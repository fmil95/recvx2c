#include <shinobi.h>





/* 100% match - Hardwires the CBL type to NTSC */
SYE_CBL syCblCheck() { // Line 8, Address: 0x2ddef0
    return SYE_CBL_NTSC;
}
