#include "init.h"

#if !defined(ANDROID) && !defined(AMIGAOS4) && !defined(__EMSCRIPTEN__)
#include <execinfo.h>
#endif
#include <stdio.h>
#include <unistd.h>
#include "../../version.h"
#include "../glx/glx_gbm.h"
#include "../glx/streaming.h"
#include "build_info.h"
#include "debug.h"
#include "loader.h"
#include "logs.h"
#ifdef __EMSCRIPTEN__
#define NO_INIT_CONSTRUCTOR
#endif

void gl_init();

globals4es_t globals4es = {0};

#define SHUT(a) if(!globals4es.nobanner) a

#if defined(PANDORA) || defined(CHIP)
static void fast_math() {
  // enable Cortex A8 RunFast
   int v = 0;
   __asm__ __volatile__ (
     "vmrs %0, fpscr\n"
     "orr  %0, #((1<<25)|(1<<24))\n" // default NaN, flush-to-zero
     "vmsr fpscr, %0\n"
     //"vmrs %0, fpscr\n"
     : "=&r"(v));
}
#endif

#ifndef DEFAULT_ES
#if defined(PANDORA) || defined(ANDROID)
#define DEFAULT_ES 1
#else
#define DEFAULT_ES 2
#endif
#endif

void load_libs();
void glx_init();

#ifdef NO_INIT_CONSTRUCTOR
__attribute__((visibility("default")))
#else
__attribute__((constructor))
#endif
void initialize_gl4es() {
    // only init 1 time
    static int inited = 0;
    if(inited) return;
    inited = 1;
    // default init of globals
    memset(&globals4es, 0, sizeof(globals4es));
    globals4es.mergelist = 1;
    globals4es.queries = 1;
    globals4es.beginend = 1;
    // overides by env. variables
    char *env_nobanner = getenv("LIBGL_NOBANNER");
    if (env_nobanner && strcmp(env_nobanner, "1") == 0)
        globals4es.nobanner = 1;

	SHUT(LOGD("LIBGL: Initialising gl4es\n"));
	
    SHUT(print_build_infos());
    #define env(name, global, message)                    \
        char *env_##name = getenv(#name);                 \
        if (env_##name && strcmp(env_##name, "1") == 0) { \
            SHUT(LOGD("LIBGL: " message "\n"));         \
            global = true;                                \
        }

    env(LIBGL_XREFRESH, globals4es.xrefresh, "xrefresh will be called on cleanup");
    env(LIBGL_STACKTRACE, globals4es.stacktrace, "stacktrace will be printed on crash");

    char *env_fb = getenv("LIBGL_FB");
    if (env_fb && strcmp(env_fb, "1") == 0) {
            SHUT(LOGD("LIBGL: framebuffer output enabled\n"));
            globals4es.usefb = 1;
    }
    if (env_fb && strcmp(env_fb, "2") == 0) {
            SHUT(LOGD("LIBGL: using framebuffer + fbo\n"));
            globals4es.usefb = 1;
            globals4es.usefbo = 1;
    }
#ifndef NOX11
    if (env_fb && strcmp(env_fb, "3") == 0) {
            SHUT(LOGD("LIBGL: using pbuffer\n"));
            globals4es.usefb = 0;
            globals4es.usepbuffer = 1;
    }
#endif
    if (env_fb && strcmp(env_fb, "4") == 0) {
#ifdef NO_GBM
        SHUT(LOGD("LIBGL: GBM Support not builded, cannot use it\n"));
#else
        SHUT(LOGD("LIBGL: using GBM\n"));
        globals4es.usefb = 0;
        globals4es.usegbm = 1;
#endif
    }

    env(LIBGL_FPS, globals4es.showfps, "fps counter enabled");
#ifdef USE_FBIO
    env(LIBGL_VSYNC, globals4es.vsync, "vsync enabled");
#endif
#ifdef PANDORA
    char *env_gamma = getenv("LIBGL_GAMMA");
    if (env_gamma) {
        globals4es.gamma=atof(env_gamma);
        SHUT(LOGD("LIBGL: Set gamma to %.2f\n", globals4es.gamma));
    }
#endif
    env(LIBGL_NOBGRA, globals4es.nobgra, "Ignore BGRA texture capability");
    env(LIBGL_ARBPROGRAM, globals4es.arb_program, "Export (Fake!) ARB Program extensions");
    char *env_es = getenv("LIBGL_ES");
    if (env_es && strcmp(env_es, "1") == 0) {
            globals4es.es = 1;
    }
    if (env_es && strcmp(env_es, "2") == 0) {
            globals4es.es = 2;
    }
    // automatic ES backend selection
    if(globals4es.es==0)
        globals4es.es = DEFAULT_ES;

    char *env_gl = getenv("LIBGL_GL");
    if (env_gl && strcmp(env_gl, "15") == 0) {
            globals4es.gl = 15;
    }
    if (env_gl && strcmp(env_gl, "20") == 0) {
            globals4es.gl = 20;
    }
    if (env_gl && strcmp(env_gl, "21") == 0) {
            globals4es.gl = 21;
    }
    // automatic GL version selection
    if(globals4es.gl==0)
        globals4es.gl = (globals4es.es==1)?15:20;  // forcing GL 1.5 for es1.1 and GL 2.0 for es2.0

    SHUT(LOGD("LIBGL: Using GLES %s backend\n", (globals4es.es==1)?"1.1":"2.0"));

    env(LIBGL_NODEPTHTEX, globals4es.nodepthtex, "Disable usage of Depth Textures");
    char* env_drmcard = getenv("LIBGL_DRMCARD");
    if(env_drmcard) {
#ifdef NO_GBM
        SHUT(LOGD("LIBGL: Warning, GBM not compiled in, cannot use LIBGL_DRMCARD\n"));
#else
        strncpy(globals4es.drmcard, env_drmcard, 50);
    } else {
        strcpy(globals4es.drmcard, "/dev/dri/card0");
#endif
    }

#ifndef __EMSCRIPTEN__
    load_libs();
    if(globals4es.usegbm)
        LoadGBMFunctions();
    if(globals4es.usegbm && !gbm) {
        SHUT(LOGD("LIBGL: cannot use GBM, disabling\n"));
        globals4es.usegbm = 0;  // should do some smarter fallback?
    }
    glx_init();
#else
    globals4es.usegbm = 0;
#endif

#if (defined(NOEGL) && !defined(ANDROID)) || defined(__EMSCRIPTEN__)
    int gl4es_notest = 1;
#else
    int gl4es_notest = 0;
    char *env_notest = getenv("LIBGL_NOTEST");
    if (env_notest && strcmp(env_notest, "1") == 0) {
		gl4es_notest = 1;
    }
#endif
    env(LIBGL_NOHIGHP, globals4es.nohighp, "Do not use HIGHP in fragment shader even if detected");

    globals4es.floattex = 1;
    char *env_float = getenv("LIBGL_FLOAT");
    if (env_float && strcmp(env_float, "0") == 0) {
        globals4es.floattex = 0;
        SHUT(LOGD("LIBGL: Float and Half-Float texture support disabled\n"));
    }
    if (env_float && strcmp(env_float, "2") == 0) {
        globals4es.floattex = 2;
        SHUT(LOGD("LIBGL: Float and Half-float texture support forced\n"));
    }
    GetHardwareExtensions(gl4es_notest);
    gl_init();

    env(LIBGL_RECYCLEFBO, globals4es.recyclefbo, "Recycling of FBO enabled");
    // Texture hacks
    char *env_mipmap = getenv("LIBGL_MIPMAP");
    if (env_mipmap && strcmp(env_mipmap, "1") == 0) {
        globals4es.automipmap = 1;
        SHUT(LOGD("LIBGL: AutoMipMap forced\n"));
    }
    if (env_mipmap && strcmp(env_mipmap, "2") == 0) {
        globals4es.automipmap = 2;
        SHUT(LOGD("LIBGL: guess AutoMipMap\n"));
    }
    if (env_mipmap && strcmp(env_mipmap, "3") == 0) {
        globals4es.automipmap = 3;
        SHUT(LOGD("LIBGL: ignore MipMap\n"));
    }
    if (env_mipmap && strcmp(env_mipmap, "4") == 0) {
        globals4es.automipmap = 4;
        SHUT(LOGD("LIBGL: ignore AutoMipMap on non-squared textures\n"));
    }
    if (env_mipmap && strcmp(env_mipmap, "5") == 0) {
        globals4es.automipmap = 5;
        SHUT(LOGD("LIBGL: Calculate sub-mipmap incase some are missing\n"));
    }
    char *env_texcopy = getenv("LIBGL_TEXCOPY");
    if (env_texcopy && strcmp(env_texcopy, "1") == 0) {
        globals4es.texcopydata = 1;
        SHUT(LOGD("LIBGL: Texture copy enabled\n"));
    }
    char *env_shrink = getenv("LIBGL_SHRINK");
    if(env_shrink) {
        if (env_shrink && strcmp(env_shrink, "10") == 0) {
            globals4es.texshrink = 10;
            SHUT(LOGD("LIBGL: Texture shink, mode 10 selected (advertise 8192 max texture size, but >2048 are quadshrinked and > 512 are shrinked), but not for empty texture\n"));
        }
        else if (env_shrink && strcmp(env_shrink, "11") == 0) {
            globals4es.texshrink = 11;
            SHUT(LOGD("LIBGL: Texture shink, mode 11 selected (advertise a max texture size *2, but every texture with one dimension > max texture size will get shrinked to max texture size), but not for empty texture\n"));
        }
        else if (env_shrink && strcmp(env_shrink, "1") == 0) {
            globals4es.texshrink = 1;
            SHUT(LOGD("LIBGL: Texture shink, mode 1 selected (everything / 2)\n"));
        }
        else if (env_shrink && strcmp(env_shrink, "2") == 0) {
            globals4es.texshrink = 2;
            SHUT(LOGD("LIBGL: Texture shink, mode 2 selected (only > 512 /2 )\n"));
        }
        else if (env_shrink && strcmp(env_shrink, "3") == 0) {
            globals4es.texshrink = 3;
            SHUT(LOGD("LIBGL: Texture shink, mode 3 selected (only > 256 /2 )\n"));
        }
        else if (env_shrink && strcmp(env_shrink, "4") == 0) {
            globals4es.texshrink = 4;
            SHUT(LOGD("LIBGL: Texture shink, mode 4 selected (only > 256 /2, >=1024 /4 )\n"));
        }
        else if (env_shrink && strcmp(env_shrink, "5") == 0) {
            globals4es.texshrink = 5;
            SHUT(LOGD("LIBGL: Texture shink, mode 5 selected (every > 256 is downscaled to 256 ), but not for empty texture\n"));
        }
        else if (env_shrink && strcmp(env_shrink, "6") == 0) {
            globals4es.texshrink = 6;
            SHUT(LOGD("LIBGL: Texture shink, mode 6 selected (only > 128 /2, >=512 is downscaled to 256 ), but not for empty texture\n"));
        }
        else if (env_shrink && strcmp(env_shrink, "7") == 0) {
            globals4es.texshrink = 7;
            SHUT(LOGD("LIBGL: Texture shink, mode 7 selected (only > 512 /2 ), but not for empty texture\n"));
        }
        else if (env_shrink && strcmp(env_shrink, "8") == 0) {
            globals4es.texshrink = 8;
            SHUT(LOGD("LIBGL: Texture shink, mode 8 selected (advertise 8192 max texture size, but >2048 are shrinked to 2048)\n"));
        }
        else if (env_shrink && strcmp(env_shrink, "9") == 0) {
            globals4es.texshrink = 9;
            SHUT(LOGD("LIBGL: Texture shink, mode 9 selected (advertise 8192 max texture size, but >4096 are quadshrinked and > 512 are shrinked), but not for empty texture\n"));
        }
    }

    char *env_dump = getenv("LIBGL_TEXDUMP");
    if (env_dump && strcmp(env_dump, "1") == 0) {
        globals4es.texdump = 1;
        SHUT(LOGD("LIBGL: Texture dump enabled\n"));
    }
    char *env_alpha = getenv("LIBGL_ALPHAHACK");
    if (env_alpha && strcmp(env_alpha, "1") == 0) {
        globals4es.alphahack = 1;
        SHUT(LOGD("LIBGL: Alpha Hack enabled\n"));
    }
#ifdef TEXSTREAM
    char *env_stream = getenv("LIBGL_STREAM");
    if (env_stream && strcmp(env_stream, "1") == 0) {
        globals4es.texstream = InitStreamingCache();
        SHUT(LOGD("LIBGL: Streaming texture %s\n",(globals4es.texstream)?"enabled":"not available"));
        //FreeStreamed(AddStreamed(1024, 512, 0));
    }
    if (env_stream && strcmp(env_stream, "2") == 0) {
        globals4es.texstream = InitStreamingCache()?2:0;
        SHUT(LOGD("LIBGL: Streaming texture %s\n",(globals4es.texstream)?"forced":"not available"));
        //FreeStreamed(AddStreamed(1024, 512, 0));
    }
#endif
    char *env_lumalpha = getenv("LIBGL_NOLUMALPHA");
    if (env_lumalpha && strcmp(env_lumalpha, "1") == 0) {
        globals4es.nolumalpha = 1;
        SHUT(LOGD("LIBGL: GL_LUMINANCE_ALPHA hardware support disabled\n"));
    }

    env(LIBGL_BLENDHACK, globals4es.blendhack, "Change Blend GL_SRC_ALPHA, GL_ONE to GL_ONE, GL_ONE");
    env(LIBGL_BLENDCOLOR, globals4es.blendcolor, "Export a (faked) glBlendColor");
    env(LIBGL_NOERROR, globals4es.noerror, "glGetError() always return GL_NOERROR");
    globals4es.silentstub = 1;
    char *env_silentstub = getenv("LIBGL_SILENTSTUB");
    if (env_silentstub && strcmp(env_silentstub, "0") == 0) {
        globals4es.silentstub = 0;
        SHUT(LOGD("LIBGL: Stub/non present functions are printed"));
    }
    env(LIBGL_VABGRA, globals4es.vabgra, "Export GL_ARB_vertex_array_bgra extension");

    char *env_version = getenv("LIBGL_VERSION");
    if (env_version) {
        SHUT(LOGD("LIBGL: Overide version string with \"%s\" (should be in the form of \"1.x\")\n", env_version));
    }
    if(env_version) {
        snprintf(globals4es.version, 49, "%s gl4es wrapper %d.%d.%d", env_version, MAJOR, MINOR, REVISION);
        SHUT(LOGD("LIBGL: Targeting OpenGL %s\n", env_version));
    } else {
        snprintf(globals4es.version, 49, "%d.%d gl4es wrapper %d.%d.%d", globals4es.gl/10, globals4es.gl%10, MAJOR, MINOR, REVISION);
        SHUT(LOGD("LIBGL: Targeting OpenGL %d.%d\n", globals4es.gl/10, globals4es.gl%10));
    }

    char *env_srgb = getenv("LIBGL_SRGB");
    if (env_srgb && strcmp(env_srgb, "1") == 0 && hardext.srgb) {
        globals4es.glx_surface_srgb = 2;
        SHUT(LOGD("LIBGL: enabling sRGB support\n"));
    }
    char *env_fastmath = getenv("LIBGL_FASTMATH");
    if (env_fastmath && strcmp(env_fastmath, "1") == 0) {
#if defined(PANDORA) || defined(CHIP)
        SHUT(LOGD("LIBGL: Enable FastMath for cortex-a8\n"));
        fast_math();
#else
        SHUT(LOGD("LIBGL: No FastMath on this platform\n"));
#endif
    }
    char *env_npot = getenv("LIBGL_NPOT");
    switch(hardext.npot) {
        case 0: globals4es.npot = 0; break;
        case 1:
        case 2: globals4es.npot = 1; break;
        case 3: globals4es.npot = 2; break;
    }
    if (env_npot && strcmp(env_npot, "1") == 0 && globals4es.npot<1) {
		globals4es.npot = 1;
		SHUT(LOGD("LIBGL: Expose limited NPOT extension\n"));
	}
    if (env_npot && strcmp(env_npot, "2") == 0 && globals4es.npot<3) {
		globals4es.npot = 2;
		SHUT(LOGD("LIBGL: Expose GL_ARB_texture_non_power_of_two extension\n"));
	}
   char *env_queries = getenv("LIBGL_GLQUERIES");
    if (env_queries && strcmp(env_queries, "0") == 0) {
        globals4es.queries = 0;
        SHUT(LOGD("LIBGL: Dont't expose fake glQueries functions\n"));
    }
    char *env_nodownsampling = getenv("LIBGL_NODOWNSAMPLING");
    if (env_nodownsampling && strcmp(env_nodownsampling, "1") == 0) {
        globals4es.nodownsampling = 1;
        SHUT(LOGD("LIBGL: No downsampling of DXTc textures\n"));
    }

    env(LIBGL_NOTEXMAT, globals4es.texmat, "Don't handle Texture Matrice internaly");
    env(LIBGL_NOVAOCACHE, globals4es.novaocache, "Don't use VAO cache");
    
    char *env_beginend = getenv("LIBGL_BEGINEND");
    if(env_beginend) {
        if (strcmp(env_beginend, "0") == 0) {
                globals4es.beginend = 0;
                globals4es.mergelist = 0;
                SHUT(LOGD("LIBGL: Don't try to merge subsequent glBegin/glEnd blocks\n"));
        } 
        if (strcmp(env_beginend, "1") == 0 || strcmp(env_beginend, "2") == 0) {
                globals4es.beginend = 1;
                SHUT(LOGD("LIBGL: Try to merge subsequent glBegin/glEnd blocks, even if there is a glColor / glNormal in between\n"));
        } 
    }
    env(LIBGL_AVOID16BITS, globals4es.avoid16bits, "Avoid 16bits textures");

    globals4es.avoid24bits = 0;
    char *env_avoid24bits = getenv("LIBGL_AVOID24BITS");
    if(env_avoid24bits) {
        if (strcmp(env_avoid24bits, "0") == 0) {
            globals4es.avoid24bits = 0;
            SHUT(LOGD("LIBGL: Don't try to avoid 24bits textures\n"));
        } 
        if (strcmp(env_avoid24bits, "1") == 0) {
            globals4es.avoid24bits = 2;
            SHUT(LOGD("LIBGL: Avoid 24bits textures\n"));
        } 
    }

    env(LIBGL_FORCE16BITS, globals4es.force16bits, "Force 16bits textures");

    env(LIBGL_POTFRAMEBUFFER, globals4es.potframebuffer, "Force framebuffers to be on POT size");

    char *env_forcenpot = getenv("LIBGL_FORCENPOT");
    if ((env_forcenpot && strcmp(env_forcenpot,"0") == 0) && (hardext.esversion==2 && (hardext.npot==1 || hardext.npot==2))) {
        SHUT(LOGD("LIBGL: Not forcing NPOT support\n"));
    } else
    if ((env_forcenpot && strcmp(env_forcenpot,"1") == 0) || (hardext.esversion==2 && (hardext.npot==1 || hardext.npot==2))) {
        if(hardext.npot==3) {
            SHUT(LOGD("LIBGL: NPOT texture handled in hardware\n"));
        } else if(hardext.npot==1) {
            globals4es.forcenpot = 1;
            SHUT(LOGD("LIBGL: Forcing NPOT support by disabling MIPMAP support for NPOT textures \n"));
        } else {
            SHUT(LOGD("LIBGL: WARNING, No Limited or Full NPOT support in hardware, Forcing NPOT have no effect!\n"));
        }
    }
    globals4es.batch = 0;
    char *env_batch = getenv("LIBGL_BATCH");
    int tmp = 0;
    if(env_batch && sscanf(env_batch, "%d", &tmp)==1) {
        globals4es.batch = tmp;
        if(tmp==0) {
            SHUT(LOGD("LIBGL: Not trying to batch small subsequent glDrawXXXX\n"));
        } else {
            SHUT(LOGD("LIBGL: Trying to batch subsequent glDrawXXXX of size < %d vertices\n", tmp*10));
        }
    }

    globals4es.usevbo = 0;
    char *env_usevbo = getenv("LIBGL_USEVBO");
    /*if(env_usevbo && strcmp(env_usevbo,"0") == 0) {
        SHUT(LOGD("LIBGL: Use of VBO disabled\n"));
        globals4es.usevbo = 0;
    } else*/ if(env_usevbo && strcmp(env_usevbo,"1") == 0) {
        globals4es.usevbo = 1;
    }
    if(globals4es.usevbo) {
        SHUT(LOGD("LIBGL: VBO used (in a few cases)\n"));
    }

    globals4es.fbomakecurrent = 0;
    if((hardext.vendor & VEND_ARM) || (globals4es.usefb))
        globals4es.fbomakecurrent = 1;
    char *env_fbomakecurrent = getenv("LIBGL_FBOMAKECURRENT");
    if(globals4es.fbomakecurrent && env_fbomakecurrent && !strcmp(env_fbomakecurrent, "0")) {
        globals4es.fbomakecurrent = 0;
        SHUT(LOGD("LIBGL: glXMakeCurrent FBO workaround disabled\n"));
    }
    if(env_fbomakecurrent && !strcmp(env_fbomakecurrent, "1"))
        globals4es.fbomakecurrent = 1;
    if(globals4es.fbomakecurrent) {
        SHUT(LOGD("LIBGL: glXMakeCurrent FBO workaround enabled\n"));
    }

    globals4es.fbounbind = 0;
    if((hardext.vendor & VEND_ARM) || (hardext.vendor & VEND_IMGTEC))
        globals4es.fbounbind = 1;
    char *env_fbounbind = getenv("LIBGL_FBOUNBIND");
    if(globals4es.fbounbind && env_fbounbind && !strcmp(env_fbounbind, "0")) {
        globals4es.fbounbind = 0;
        SHUT(LOGD("LIBGL: FBO workaround for using binded texture disabled\n"));
    }
    if(env_fbounbind && !strcmp(env_fbounbind, "1"))
        globals4es.fbounbind = 1;
    if(globals4es.fbounbind) {
        SHUT(LOGD("LIBGL: FBO workaround for using binded texture enabled\n"));
    }

    env(LIBGL_FBOFORCETEX, globals4es.fboforcetex, "Force texture for Attachment color0 on FBO");

    env(LIBGL_COMMENTS, globals4es.comments, "Keep comments in converted Shaders");

    if(hardext.npot==3)
        globals4es.defaultwrap=0; 
    else
        globals4es.defaultwrap=1; 
    char *env_defaultwrap = getenv("LIBGL_DEFAULTWRAP");
    if(env_defaultwrap && !strcmp(env_defaultwrap, "0")) {
        globals4es.defaultwrap = 0;
        SHUT(LOGD("LIBGL: Default wrap mode is GL_REPEAT\n"));
    } else if(env_defaultwrap && !strcmp(env_defaultwrap, "1")) {
        globals4es.defaultwrap = 1;
        SHUT(LOGD("LIBGL: Default wrap mode is GL_CLAMP_TO_EDGE\n"));
    } else if(env_defaultwrap && !strcmp(env_defaultwrap, "2")) {
        globals4es.defaultwrap = 2;
        SHUT(LOGD("LIBGL: Default wrap mode is GL_CLAMP_TO_EDGE, enforced\n"));
    }

    globals4es.notexarray = 0;
    char *env_notexarray = getenv("LIBGL_NOTEXARRAY");
    if(env_notexarray && !strcmp(env_notexarray, "0"))
        globals4es.notexarray = 0;
    else if(env_notexarray && !strcmp(env_notexarray, "1"))
        globals4es.notexarray = 1;
    if(globals4es.notexarray) {
        SHUT(LOGD("LIBGL: No Texture Array in Shaders\n"));
    }

    env(LIBGL_LOGSHADERERROR, globals4es.logshader, "Log to the console Error compiling shaders");
    env(LIBGL_SHADERNOGLES, globals4es.shadernogles, "Remove GLES part in shader");
    char *env_dbgshaderconv = getenv("LIBGL_DBGSHADERCONV");
    if(env_dbgshaderconv) {
        if(sscanf(env_dbgshaderconv, "%d", &globals4es.dbgshaderconv)!=1)
            globals4es.dbgshaderconv = 0;
        if(globals4es.dbgshaderconv) {
            if(globals4es.dbgshaderconv==1)
                globals4es.dbgshaderconv=15;
            if(!(globals4es.dbgshaderconv&3))   // neither vertex or fragment
                globals4es.dbgshaderconv|=3;    // select both
            if(!(globals4es.dbgshaderconv&12))  // neither before or after
                globals4es.dbgshaderconv|=12;   // select both
            SHUT(LOGD("Log to the console all shaders before and after conversion: "));
            if(globals4es.dbgshaderconv&4)
                SHUT(LOGD("Before  "));
            if(globals4es.dbgshaderconv&8)
                SHUT(LOGD("After  "));
            if(globals4es.dbgshaderconv&1)
                SHUT(LOGD("Vertex  "));
            if(globals4es.dbgshaderconv&2)
                SHUT(LOGD("Fragment  "));
            SHUT(LOGD("\n"));
        }
    }
    env(LIBGL_NOCLEAN, globals4es.noclean, "Don't clean Context when destroy");


    globals4es.glxrecycle = 1;
#ifndef NOEGL
    if((globals4es.usepbuffer) || (globals4es.usefb))
        globals4es.glxrecycle = 0;
    char *env_glxrecycle = getenv("LIBGL_GLXRECYCLE");
    if(globals4es.glxrecycle && env_glxrecycle && !strcmp(env_glxrecycle, "0") && !((globals4es.usepbuffer) || (globals4es.usefb))) {
        globals4es.glxrecycle = 0;
        SHUT(LOGD("LIBGL: glX Will NOT try to recycle EGL Surface\n"));
    }
    if(env_glxrecycle && !strcmp(env_glxrecycle, "1"))
        globals4es.glxrecycle = 1;
    if(globals4es.glxrecycle) {
        SHUT(LOGD("LIBGL: glX Will try to recycle EGL Surface\n"));
    }
#endif
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd))!= NULL)
        SHUT(LOGD("LIBGL: Current folder is:%s\n", cwd));
}
