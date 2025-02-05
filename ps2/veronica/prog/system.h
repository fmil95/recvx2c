#include "common.h"

struct _anon0 {
    unsigned short* scd0;
    unsigned short* scd1;
    unsigned short* evd;
};

struct _anon3 {
    unsigned short on;
    unsigned short old;
    unsigned short push;
    unsigned short release;
    short send;
    unsigned short ad_flag;
    unsigned char buff[2];
    unsigned short onon;
    unsigned short repeat;
    char time1[16];
    char time2[16];
    unsigned char rh;
    unsigned char rv;
    unsigned char lh;
    unsigned char lv;
    unsigned char au;
    unsigned char ad;
    unsigned char al;
    unsigned char ar;
    unsigned char abu;
    unsigned char abd;
    unsigned char abl;
    unsigned char abr;
    unsigned char al1;
    unsigned char al2;
    unsigned char ar1;
    unsigned char ar2;
};

struct _anon6 {
    unsigned short flg;
    short frame;
    float px;
    float py;
    float pz;
    short ax;
    short ay;
    short az;
    short pers;
    unsigned int hidobj[8];
    unsigned int hidlgt[4];
    unsigned int fog_col;
    float fog_nr;
    float fog_fr;
    short lkflg;
    short lkno;
    short lkono;
    short nxt_no;
    float lx;
    float ly;
    float lz;
    float prm_0;
    float prm_1;
    float prm_2;
    float prm_3;
    float prm_4;
    unsigned char* recp;
};

struct _anon7 {
    float dist;
    float w;
    float h;
    float cx;
    float cy;
};

struct _anon14 {
    float px;
    float py;
    float pz;
    int ay;
};

struct _anon16 {
    _anon3 pad1;
    _anon3 pad2;
};

struct _anon18 {
    unsigned short flg;
    unsigned short type;
    short nxt_no;
    short keyf_n;
    _anon6 keyf[16];
};

struct _anon20 {
    unsigned char be_flag;
    unsigned char level;
    unsigned char start;
    unsigned char end;
    unsigned short delay;
    unsigned short time;
    unsigned short add;
    short f_level;
    short f_add;
    char data[2];
};

struct _anon22 {
    _anon23* cutp;
    Unknown10* lgtp;
    _anon27* enep;
    _anon27* objp;
    _anon27* itmp;
    _anon32* effp;
    Unknown15* walp;
    Unknown15* etcp;
    Unknown15* flrp;
    _anon14* posp;
    Unknown15* rutp;
    unsigned char* ruttp;
    _anon0* evtp;
    _anon18* evcp;
    unsigned int* mesp;
    Unknown10* evlp;
    unsigned char* dmp00;
    unsigned char* dmp01;
    unsigned char* dmp02;
    unsigned char* dmp03;
    unsigned char* dmp04;
    unsigned char* dmp05;
    unsigned char* dmp06;
    unsigned char* dmp07;
    unsigned char* dmp08;
    unsigned char* dmp09;
    unsigned char* dmp10;
    unsigned char* dmp11;
    unsigned char* dmp12;
    unsigned char* dmp13;
    unsigned char* dmp14;
    unsigned char* dmp15;
    int cut_n;
    int lgt_n;
    int ene_n;
    int obj_n;
    int itm_n;
    int eff_n;
    int wal_n;
    int etc_n;
    int flr_n;
    int pos_n;
    int rut_n;
    int evc_n;
    int mes_n;
    int evl_n;
    int dmy00;
    int dmy01;
    int dmy02;
    int dmy03;
    int dmy04;
    int dmy05;
    int dmy06;
    int dmy07;
    int dmy08;
    int dmy09;
    int dmy10;
    int dmy11;
    int dmy12;
    int dmy13;
    int dmy14;
    int dmy15;
    int dmy16;
    int dmy17;
    unsigned int flg;
    unsigned int bak_col;
    unsigned int fog_col;
    float fog_nr;
    float fog_fr;
    float w;
    float h;
    float d;
    float grand[32];
    Unknown4 mdl;
    float fog[128];
    char amb_rom;
    char amb_chr;
    char amb_obj;
    char amb_itm;
    float amb_r[4];
    float amb_g[4];
    float amb_b[4];
};

struct _anon23 {
    unsigned char flg;
    unsigned char type;
    char flr_no;
    unsigned char ctab_n;
    _anon26* cuttp;
    float cx;
    float cy;
    float cz;
    float cw;
    float ch;
    float cd;
    _anon34 cam[2];
    unsigned char exd[256];
};

struct _anon25 {
    unsigned int globalIndex;
    unsigned int bank;
    unsigned int tspparambuffer;
    unsigned int texparambuffer;
    unsigned int texaddr;
    TextureInfo texinfo;
    unsigned short count;
    unsigned short dummy;
};

struct _anon26 {
    unsigned int attr;
    char flr_no;
    char reserve0;
    char reserve1;
    char atr_tp;
    float h;
    float dmy;
    float minx;
    float minz;
    float maxx;
    float maxz;
};

struct _anon27 {
    unsigned int flg;
    unsigned short id;
    unsigned short type;
    char flr_no;
    unsigned char mdlver;
    unsigned char wrk_no;
    char prm1;
    float px;
    float py;
    float pz;
    short ax;
    short az;
    short ay;
    short aspd;
    char hide[4];
};

struct _anon30 {
    unsigned int flg;
    unsigned int atack_ct;
    unsigned int fend_ct;
    unsigned int at_cct;
    short ef_yct;
    short act_ct0;
    short act_ct1;
    short act_ct2;
    float r;
    float l;
    float rn;
    float rmax;
    Vector3 wp_fps1;
    Vector3 wp_fps2;
    Vector3 wp_cps;
    unsigned char ltp;
    unsigned char lr;
    unsigned char lg;
    unsigned char lb;
    unsigned short lnr;
    unsigned short lfr;
    float hrate;
    float ef_scale;
    short snd_wpno;
    short hiteff;
    unsigned short seno0;
    unsigned short seno1;
    char vib_tp;
    char vib_ct;
    char reserve1;
    char reserve2;
};

struct _anon32 {
    unsigned int flg;
    unsigned short id;
    unsigned short type;
    short flr_no;
    unsigned short mdlver;
    float px;
    float py;
    float pz;
    float sx;
    float sy;
    float sz;
    short ay;
    short ax;
    int lkflg;
    int lkno;
    int lkono;
    float lx;
    float ly;
    float lz;
    int param;
};

struct _anon34 {
    unsigned short flg;
    unsigned char lgtclip;
    char spd;
    float px;
    float py;
    float pz;
    float ln;
    float w;
    float h;
    float d;
    float y0;
    float y1;
    float y2;
    float y3;
    float am_spd;
    int ax;
    int ay;
    int az;
    int lax;
    int lay;
    short laz0;
    short laz1;
    short laz2;
    short laz3;
    char aa_spd;
    char fil_no;
    char fil_rt;
    char reserve;
    int pers;
    unsigned int hidobj[16];
    unsigned int hidlgt[8];
    unsigned int fog_col;
    float fog_nr;
    float fog_fr;
};

struct _anon47 {
    float ver;
    unsigned int flg;
    unsigned int dat0;
    unsigned int dat1;
    unsigned int hed00;
    unsigned int hed01;
    unsigned int hed02;
    unsigned int hed03;
    unsigned int hed04;
    unsigned int hed05;
    unsigned int hed06;
    unsigned int hed07;
    unsigned int hed08;
    unsigned int hed09;
    unsigned int hed10;
    unsigned int hed11;
    unsigned int hed12;
    unsigned int hed13;
    unsigned int hed14;
    unsigned int hed15;
    unsigned int hed16;
    unsigned int hed17;
    unsigned int hed18;
    unsigned int hed19;
    char usrname[32];
};

int bhCalcVtxBuffer();
void bhChangeHWSetting();
void bhInitSystem();
void bhInitRoomChangeSystem();
void bhSysCallInit();
void bhSysCallDiscChange();
void bhSysCallSoundMuseum();
void bhSysCallWarning();
void bhSysCallIpl();
void bhSysCallFirstmovie();
void bhSysCallTitle();
void bhSysCallOpening();
void bhFirstGameStart();
void bhSysCallPad();
void bhSysCallGame();
void bhCheckSubTask();
void bhSysCallEvent();
void bhSysCallMap();
void bhSysCallItemselect();
void bhSysCallDoordemo();
void bhSysCallMovie();
void bhSysCallEnding();
void bhSysCallGameover();
void bhSysCallTypewriter();
void bhSysCallOption();
void bhSysCallCompEvent();
void bhSysCallMonitor();
void bhSysCallSndMonitor();
void bhSysCallScreenSaver();
void bhReturnTitle();
void bhExitGame();
void bhSetEventTimer(int mode);
void EasyDispMessage(float PosY, unsigned int MessageNo);

