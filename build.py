import os
import subprocess
import json
import argparse
import sys

# ANSI escape codes for colored text
class Colors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

def colored_output(message, color=Colors.ENDC, brackets=True, bold=False):
    """Wrapper function to print colored text with optional brackets and bold style."""
    if brackets:
        message = f"[{message}]"
    if bold:
        message = f"{Colors.BOLD}{message}{Colors.ENDC}"
    print(f"{color}{message}{Colors.ENDC}")

def load_json(filename):
    """Load JSON data from a file."""
    colored_output(f"Loading JSON data from: {filename}", color=Colors.OKCYAN)
    with open(filename, 'r') as f:
        return json.load(f)


def write_json(filename, data):
    """Write JSON data to a file."""
    colored_output(f"Writing JSON data to: {filename}", color=Colors.OKCYAN)
    with open(filename, 'w') as f:
        json.dump(data, f, indent=4)


def run_command(command, env_vars, log_file='build.log'):
    """Run a shell command with specified environment variables and log output."""
    colored_output(f"Running: {' '.join(command)}", color=Colors.OKBLUE)

    env = os.environ.copy()
    env.update(env_vars)

    result = subprocess.run(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    # Log the result to file
    with open(log_file, 'a') as f:
        f.write(result.stdout.decode('utf-8'))
        f.write(result.stderr.decode('utf-8'))

    if result.returncode != 0:
        colored_output("Error:", color=Colors.FAIL, bold=True)
        colored_output(result.stderr.decode('utf-8'), color=Colors.FAIL, brackets=False)
        return False  # Return False on failure
    else:
        colored_output("Success:", color=Colors.OKGREEN, bold=True)
        colored_output(result.stdout.decode('utf-8'), color=Colors.OKGREEN, brackets=False)
        return True  # Return True on success
    

def create_compile_command_entry(compiler, source, object_file, include_dirs, defines):
    """Create a compile command entry for compile_commands.json."""
    valid_include_dirs = [os.path.abspath(inc) for inc in include_dirs if os.path.isdir(inc)]
    invalid_include_dirs = [inc for inc in include_dirs if not os.path.isdir(inc)]
    if invalid_include_dirs:
        colored_output(f"Warning: Invalid include directories: {invalid_include_dirs}", color=Colors.WARNING)

    return {
        "directory": os.getcwd(),
        "command": ' '.join([compiler, '-c', source, '-o', object_file] +
                            [f'-D{d}' for d in defines] +
                            [f'-I{inc}' for inc in valid_include_dirs]),
        "file": source
    }


def compile_source_files(compiler, sources, compiler_flags, include_dirs, defines, env_vars):
    """Compile all source files and return object file list and compile commands."""
    objects = []
    compile_commands = []
    build_failed = False  # Track if any compilation fails

    for source in sources:
        object_file = source.replace(".c", ".o")
        objects.append(object_file)

        compile_command = [compiler] + compiler_flags + ['-c', source, '-o', object_file] + \
                          [f'-I{inc}' for inc in include_dirs] + [f'-D{d}' for d in defines]

        # Continue compiling even if one source fails
        if not run_command(compile_command, env_vars):
            build_failed = True  # Mark the build as failed if any command fails

        compile_commands.append(create_compile_command_entry(compiler, source, object_file, include_dirs, defines))

    return objects, compile_commands, build_failed


def link_objects(linker, objects, linker_flags, libraries, library_dirs, env_vars):
    """Link object files into the final executable."""
    output_elf = "main.elf"
    link_command = [linker] + linker_flags + objects + ['-o', output_elf] + \
                   [f'-L{lib}' for lib in library_dirs] + libraries

    if not run_command(link_command, env_vars):
        return None  # Return None if linking fails
    return output_elf


def main(args):
    """Main entry point for the build process."""
    # Load environment variables from JSON
    env_vars = load_json(args.env_file)

    compiler = env_vars["compiler"]
    linker = env_vars["linker"]
    include_dirs = env_vars["includes"]
    library_dirs = env_vars["libraries"]
    compiler_flags = env_vars["compiler_flags"]
    linker_flags = env_vars["linker_flags"]
    libraries = env_vars["libs"]
    sources = env_vars["source_files"]
    defines = env_vars.get("defines", [])
    actions = env_vars.get("actions", {"compile": True, "link": True})

    # Compile source files
    compiler_env = {
        "MWLibraries": ";".join(library_dirs),
        "MWLibraryFiles": ""
    }

    if not actions["compile"]:
        colored_output("Skipping compilation.", color=Colors.WARNING, bold=True)
        return
    else: 
        objects, compile_commands, build_failed = compile_source_files(compiler, sources, compiler_flags, include_dirs, defines, compiler_env)
        colored_output(f"Objects: {objects}", color=Colors.OKCYAN)
    
    # Even if the compilation fails, we want to generate the compile_commands.json for IDEs
    write_json('compile_commands.json', compile_commands)

    # If the compilation succeeded, attempt to link the objects
    if not build_failed:
        if not actions["link"]:
            colored_output("Skipping linking.", color=Colors.WARNING, bold=True)

        else: 
            linker_env = {
                "MWLibraries": ";".join(library_dirs),
                "MWLibraryFiles": ""
            }
            output_elf = link_objects(linker, objects, linker_flags, libraries, library_dirs, linker_env)

            if output_elf:
                colored_output(f"Build completed successfully: {output_elf}", color=Colors.OKGREEN, bold=True)
            else:
                colored_output("Build failed during linking.", color=Colors.FAIL, bold=True)
    else:
        colored_output("Build failed during compilation.", color=Colors.FAIL, bold=True)

if __name__ == "__main__":
    # Argument parser setup
    parser = argparse.ArgumentParser(description="Build automation script.")
    parser.add_argument('--env-file', type=str, default='.env.json', help="Path to the JSON file containing environment variables.")
    args = parser.parse_args()

    main(args)
