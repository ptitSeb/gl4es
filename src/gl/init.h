#ifndef _GL4ES_INIT_H_
#define _GL4ES_INIT_H_

#if defined(PANDORA) || defined(ODROID)
#define USE_FBIO 1
#endif

typedef struct _globals4es {
 int nobanner;
 int mergelist;
 int xrefresh;
 int stacktrace;
 int usefb;
 int usefbo;
 int recyclefbo;
 int usepbuffer;
 int showfps;
 int vsync;
 int automipmap;
 int texcopydata;
 int tested_env;
 int texshrink;
 int texdump;
 int alphahack;
 int texstream;
 int copytex;
 int nolumalpha;
 int blendhack;
 int blendcolor;
 int noerror;
 int npot;
 int queries;
 int silentstub;
 int glx_surface_srgb;
 int nodownsampling;
 int vabgra;
 int nobgra;
 int potframebuffer;
#ifdef PANDORA
 float gamma;
#endif
 int texmat;
 int novaocache;
 int beginend;
 int avoid16bits;
 int avoid24bits;
 int nohighp;
 int es;
 int gl;
 int usevbo;
 int comments;
 int forcenpot;
 int fbomakecurrent;    // hack to bind/unbind FBO when doing glXMakeCurrent
 char version[50];
} globals4es_t;

extern globals4es_t globals4es;

#endif