#ifndef ANDROID
#include <execinfo.h>
#endif
#include <fcntl.h>
#if defined(PANDORA) || defined(ODROID)
#define USE_FBIO 1
#endif

#ifdef USE_FBIO
#include <linux/fb.h>
#endif
#ifdef PANDORA
#include <sys/socket.h>
#include <sys/un.h>
#endif
#include <signal.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <unistd.h>

#include "glx.h"
#include "utils.h"
//#include <GLES/gl.h>
#include "../gl/gl.h"
#include "../glx/streaming.h"
#include "khash.h"
#include "hardext.h"

#define EXPORT __attribute__((visibility("default")))

#ifndef EGL_GL_COLORSPACE_KHR
#define EGL_GL_COLORSPACE_KHR                   0x309D
#define EGL_GL_COLORSPACE_SRGB_KHR              0x3089
#define EGL_GL_COLORSPACE_LINEAR_KHR            0x308A
#endif

static bool eglInitialized = false;
static EGLDisplay eglDisplay;
static EGLSurface eglSurface;
static EGLConfig eglConfigs[1];
static int glx_default_depth=0;
#ifdef PANDORA
static struct sockaddr_un sun;
static int sock = -2;
#endif

#ifndef ANDROID
static int shm_tested = 0;
static int shm_shm = 0;
typedef struct {
    int Width; 
    int Height; 
    EGLContext Context; 
    EGLSurface Surface; 
    int Depth; 
    Display *dpy; 
    int Type; GC gc; 
    XImage* frame; 
    GLXContext glxcontext;
} glx_buffSize;

//PBuffer should work under ANDROID
static GLXPbuffer *pbufferlist = NULL;
static glx_buffSize *pbuffersize = NULL;
static int pbufferlist_cap = 0;
static int pbufferlist_size = 0;
static int isPBuffer(GLXDrawable drawable) {
    for (int i=0; i<pbufferlist_size; i++)
        if(pbufferlist[i]==(GLXPbuffer)drawable)
            return i+1;
    return 0;
}
void BlitEmulatedPixmap();
int createPBuffer(Display * dpy, const EGLint * egl_attribs, EGLSurface* Surface, EGLContext* Context, int redBits, int greenBits, int blueBits, int alphaBits, int samplebuffers, int samples);
GLXPbuffer addPixBuffer(Display *dpy, EGLSurface surface, int Width, int Height, EGLContext Context, Pixmap pixmap, int depth, int emulated);
#endif

static EGLint egl_context_attrib[] = {
#ifdef USE_ES2
    EGL_CONTEXT_CLIENT_VERSION, 2,
#endif
    EGL_NONE
};



extern void* egl;
// GLState management
void* NewGLState(void* shared_glstate);
void DeleteGLState(void* oldstate);
void ActivateGLState(void* new_glstate);

typedef struct {
    int drawable;
    EGLSurface surface;
    int PBuffer;
} map_drawable_t;
KHASH_MAP_INIT_INT(mapdrawable, map_drawable_t*)
khash_t(mapdrawable) *MapDrawable = NULL;

int8_t CheckEGLErrors() {
    EGLenum error;
    char *errortext;
    
    LOAD_EGL(eglGetError);

    error = egl_eglGetError();

    if (error != EGL_SUCCESS && error != 0) {
        switch (error) {
            case EGL_NOT_INITIALIZED:     errortext = "EGL_NOT_INITIALIZED"; break;
            case EGL_BAD_ACCESS:          errortext = "EGL_BAD_ACCESS"; break;
            case EGL_BAD_ALLOC:           errortext = "EGL_BAD_ALLOC"; break;
            case EGL_BAD_ATTRIBUTE:       errortext = "EGL_BAD_ATTRIBUTE"; break;
            case EGL_BAD_CONTEXT:         errortext = "EGL_BAD_CONTEXT"; break;
            case EGL_BAD_CONFIG:          errortext = "EGL_BAD_CONFIG"; break;
            case EGL_BAD_CURRENT_SURFACE: errortext = "EGL_BAD_CURRENT_SURFACE"; break;
            case EGL_BAD_DISPLAY:         errortext = "EGL_BAD_DISPLAY"; break;
            case EGL_BAD_SURFACE:         errortext = "EGL_BAD_SURFACE"; break;
            case EGL_BAD_MATCH:           errortext = "EGL_BAD_MATCH"; break;
            case EGL_BAD_PARAMETER:       errortext = "EGL_BAD_PARAMETER"; break;
            case EGL_BAD_NATIVE_PIXMAP:   errortext = "EGL_BAD_NATIVE_PIXMAP"; break;
            case EGL_BAD_NATIVE_WINDOW:   errortext = "EGL_BAD_NATIVE_WINDOW"; break;
            default:                      errortext = "unknown"; break;
        }

        LOGE("LIBGL: ERROR: EGL Error detected: %s (0x%X)\n", errortext, error);
        return 1;
    }

    return 0;
}
#ifndef ANDROID
static int get_config_default(Display *display, int attribute, int *value) {
    switch (attribute) {
        case GLX_USE_GL:
        case GLX_RGBA:
        case GLX_DOUBLEBUFFER:
            *value = 1;
            break;
        case GLX_LEVEL:
        case GLX_STEREO:
            *value = 0;
            break;
        case GLX_AUX_BUFFERS:
            *value = 0;
            break;
        case GLX_RED_SIZE:
            *value = 5;
            break;
        case GLX_GREEN_SIZE:
            *value = 6;
            break;
        case GLX_BLUE_SIZE:
            *value = 5;
            break;
        case GLX_ALPHA_SIZE:
            *value = 8;
            break;
        case GLX_DEPTH_SIZE:
            *value = 16;
            break;
        case GLX_STENCIL_SIZE:
            *value = 8;
            break;
        case GLX_ACCUM_RED_SIZE:
        case GLX_ACCUM_GREEN_SIZE:
        case GLX_ACCUM_BLUE_SIZE:
        case GLX_ACCUM_ALPHA_SIZE:
            *value = 0;
            break;
        case GLX_TRANSPARENT_TYPE:
            *value = GLX_NONE;
            break;
        case GLX_RENDER_TYPE:
            *value = GLX_RGBA_TYPE;
            break;
        case GLX_VISUAL_ID:
            *value = glXChooseVisual(display, 0, NULL)->visualid;
            //*value = 1;
            break;
        case GLX_FBCONFIG_ID:
            *value = 1;
            break;
        case GLX_DRAWABLE_TYPE:
            *value = GLX_WINDOW_BIT;
            break;
        case GLX_BUFFER_SIZE:
             *value = 0;
            break;
        case GLX_X_VISUAL_TYPE:
        case GLX_CONFIG_CAVEAT:
        case GLX_SAMPLE_BUFFERS:
        case GLX_SAMPLES:
            *value = 0;
            break;
        case GLX_FRAMEBUFFER_SRGB_CAPABLE_ARB:
            *value = hardext.srgb;
            break;
        default:
            LOGD("LIBGL: unknown attrib %i\n", attribute);
            *value = 0;
            return 1;
    }
    return 0;
}

static Display *g_display = NULL;
static GLXContext glxContext = NULL;
static GLXContext fbContext = NULL;
static bool g_usepbuffer = false;
#endif //ANDROID

// hmm...
static EGLContext eglContext;

static int fbcontext_count = 0;
static int glx_surface_srgb = 0;

#ifdef USE_FBIO
#ifndef FBIO_WAITFORVSYNC
#define FBIO_WAITFORVSYNC _IOW('F', 0x20, __u32)
#endif
#ifdef PANDORA
static float pandora_gamma = 0.0f;
#endif
static int fbdev = -1;
static bool g_vsync = false;
#endif
static bool g_showfps = false;
static bool g_usefb = false;
static bool g_usefbo = false;
static bool g_xrefresh = false;
static bool g_stacktrace = false;
extern int automipmap;
extern int texcopydata;
extern int tested_env;
extern int texshrink;
extern int texdump;
extern int alphahack;
extern int texstream;
extern int copytex;
extern int nolumalpha;
extern int blendhack;
extern int export_blendcolor;
extern int glshim_noerror;
extern char glshim_version[50];
extern int glshim_nobanner;
extern int glshim_npot;
int export_silentstub = 0;
int glshim_queries = 1;

bool g_recyclefbo = false;
static int  g_width=0, g_height=0;
// RPI stuffs
static bool g_bcmhost = false;
static bool g_bcm_active = false;
void (*bcm_host_init)();
void (*bcm_host_deinit)();

#define SHUT(a) if(!glshim_nobanner) a

static int swap_interval = 1;
#ifndef ANDROID
static void init_display(Display *display) {
    LOAD_EGL(eglGetDisplay);
    
    if (! g_display) {
        g_display = display;//XOpenDisplay(NULL);
    }
    if (g_usefb) {
        eglDisplay = egl_eglGetDisplay(EGL_DEFAULT_DISPLAY);
    } else {
		eglDisplay = egl_eglGetDisplay(display);
    }
}
#endif //ANDROID
static void init_vsync() {
#ifdef USE_FBIO
    fbdev = open("/dev/fb0", O_RDONLY);
    if (fbdev < 0) {
        LOGE("LIBGL: Could not open /dev/fb0 for vsync.\n");
    }
#endif
}

static void xrefresh() {
    int dummy = system("xrefresh");
}

#ifdef PANDORA
static void pandora_reset_gamma() {
    if(pandora_gamma>0.0f)
        system("sudo /usr/pandora/scripts/op_gamma.sh 0");
}
static void pandora_set_gamma() {
    if(pandora_gamma>0.0f) {
        char buf[50];
        sprintf(buf, "sudo /usr/pandora/scripts/op_gamma.sh %.2f", pandora_gamma);
        int dummy = system(buf);
    }
}
#endif

static void signal_handler(int sig) {
    if (g_xrefresh)
        xrefresh();
#ifdef PANDORA
    pandora_reset_gamma();
#endif

#ifdef BCMHOST
    if (g_bcm_active) {
        g_bcm_active = false;
        bcm_host_deinit();
    }
#endif
#ifndef ANDROID
    if (g_stacktrace) {
        switch (sig) {
            case SIGBUS:
            case SIGFPE:
            case SIGILL:
            case SIGSEGV: {
                void *array[10];
                size_t size = backtrace(array, 10);
                if (! size) {
                    LOGD("LIBGL: No stacktrace. Compile with -funwind-tables.\n");
                } else {
                    LOGD("LIBGL: Stacktrace: %zd\n", size);
                    backtrace_symbols_fd(array, size, 2);
                }
                break;
            }
        }
    }
#endif
    signal(sig, SIG_DFL);
    raise(sig);
}
#ifdef PANDORA
static void init_liveinfo() {
    static const char socket_name[] = "\0liveinfo";
    sock = socket(PF_UNIX, SOCK_DGRAM, 0);
    if (sock == -1) {
        // no socket, so LiveInfo probably not active
        return;
    }

    memset(&sun, 0, sizeof(sun));
    sun.sun_family = AF_UNIX;
    memcpy(sun.sun_path, socket_name, sizeof(socket_name));
    // send a test string
    const char test_string[] = "gl: fpsinfo";
    if (sendto(sock, test_string, strlen(test_string), 0,(struct sockaddr *)&sun, sizeof(sun))<0) {
        // error, so probably not present
        close(sock);
        sock=-1;
    } else
        fcntl(sock, F_SETFL, O_NONBLOCK);
}

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
extern void initialize_glshim();
extern int initialized;
void scan_env() {
    static bool first = true;
    if (! first)
        return;
    first = false;
    if (! initialized)
    {
	initialize_glshim();
    }
    /* Check for some corruption inside state.... */
    /*
    if ((glstate->texture.active < 0) || (glstate->texture.active > MAX_TEX) || 
        (glstate->vao->pointers.vertex.buffer!= 0) || (glstate->vao->vertex != 0) || (glstate->list.active!=0)) {
        SHUT(LOGD("LIBGL: Warning, memory corruption detected at init, trying to compensate\n"));
        initialize_glshim();
    }
    */
    // initialise MapDrawable too
    {
        int ret;
        MapDrawable = kh_init(mapdrawable);
        kh_put(mapdrawable, MapDrawable, 1, &ret);
        kh_del(mapdrawable, MapDrawable, 1);
    }
    SHUT(LOGD("LIBGL: built on %s %s\n", __DATE__, __TIME__));
    #define env(name, global, message)                    \
        char *env_##name = getenv(#name);                 \
        if (env_##name && strcmp(env_##name, "1") == 0) { \
            SHUT(LOGD("LIBGL: " message "\n"));         \
            global = true;                                \
        }

    env(LIBGL_XREFRESH, g_xrefresh, "xrefresh will be called on cleanup");
    env(LIBGL_STACKTRACE, g_stacktrace, "stacktrace will be printed on crash");
    // if ok, grab the init/deinit functions
    if (bcm_host) {
        bcm_host_init = dlsym(bcm_host, "bcm_host_init");
        bcm_host_deinit = dlsym(bcm_host, "bcm_host_deinit");
        if (bcm_host_init && bcm_host_deinit)
            g_bcmhost = true;
    }
    if (g_xrefresh || g_stacktrace || g_bcmhost) {
        // TODO: a bit gross. Maybe look at this: http://stackoverflow.com/a/13290134/293352
        signal(SIGBUS, signal_handler);
        signal(SIGFPE, signal_handler);
        signal(SIGILL, signal_handler);
        signal(SIGSEGV, signal_handler);
        if (g_xrefresh || g_bcmhost) {
            signal(SIGINT, signal_handler);
            signal(SIGQUIT, signal_handler);
            signal(SIGTERM, signal_handler);
        }
        if (g_xrefresh)
            atexit(xrefresh);
#ifndef ANDROID	
#ifdef BCMHOST
            atexit(bcm_host_deinit);
#endif
#endif //ANDROID
    }
    char *env_fb = getenv("LIBGL_FB");
    if (env_fb && strcmp(env_fb, "1") == 0) {
            SHUT(LOGD("LIBGL: framebuffer output enabled\n"));
            g_usefb = true;
    }
    if (env_fb && strcmp(env_fb, "2") == 0) {
            SHUT(LOGD("LIBGL: using framebuffer + fbo\n"));
            g_usefb = true;
            g_usefbo = true;
    }
#ifndef ANDROID
    if (env_fb && strcmp(env_fb, "3") == 0) {
            SHUT(LOGD("LIBGL: using pbuffer\n"));
            g_usefb = true;
            g_usepbuffer = true;
    }
#endif
    env(LIBGL_FPS, g_showfps, "fps counter enabled");
#ifdef USE_FBIO
    env(LIBGL_VSYNC, g_vsync, "vsync enabled");
    if (g_vsync) {
        init_vsync();
    }
#endif
#ifdef PANDORA
    init_liveinfo();
    if (sock>-1) {
        SHUT(LOGD("LIBGL: LiveInfo detected, fps will be shown\n"));
    }
#endif
    int glshim_notest = 0;
    char *env_notest = getenv("LIBGL_NOTEST");
    if (env_notest && strcmp(env_notest, "1") == 0) {
		glshim_notest = 1;
    }
    GetHardwareExtensions(glshim_notest);

    env(LIBGL_RECYCLEFBO, g_recyclefbo, "Recycling of FBO enabled");
    // Texture hacks
    char *env_mipmap = getenv("LIBGL_MIPMAP");
    if (env_mipmap && strcmp(env_mipmap, "1") == 0) {
        automipmap = 1;
        SHUT(LOGD("LIBGL: AutoMipMap forced\n"));
    }
    if (env_mipmap && strcmp(env_mipmap, "2") == 0) {
        automipmap = 2;
        SHUT(LOGD("LIBGL: guess AutoMipMap\n"));
    }
    if (env_mipmap && strcmp(env_mipmap, "3") == 0) {
        automipmap = 3;
        SHUT(LOGD("LIBGL: ignore MipMap\n"));
    }
    if (env_mipmap && strcmp(env_mipmap, "4") == 0) {
        automipmap = 4;
        SHUT(LOGD("LIBGL: ignore AutoMipMap on non-squared textures\n"));
    }
    char *env_texcopy = getenv("LIBGL_TEXCOPY");
    if (env_texcopy && strcmp(env_texcopy, "1") == 0) {
        texcopydata = 1;
        SHUT(LOGD("LIBGL: Texture copy enabled\n"));
    }
    char *env_shrink = getenv("LIBGL_SHRINK");
    if (env_shrink && strcmp(env_shrink, "1") == 0) {
        texshrink = 1;
        SHUT(LOGD("LIBGL: Texture shink, mode 1 selected (everything / 2)\n"));
    }
    if (env_shrink && strcmp(env_shrink, "2") == 0) {
        texshrink = 2;
        SHUT(LOGD("LIBGL: Texture shink, mode 2 selected (only > 512 /2 )\n"));
    }
    if (env_shrink && strcmp(env_shrink, "3") == 0) {
        texshrink = 3;
        SHUT(LOGD("LIBGL: Texture shink, mode 3 selected (only > 256 /2 )\n"));
    }
    if (env_shrink && strcmp(env_shrink, "4") == 0) {
        texshrink = 4;
        SHUT(LOGD("LIBGL: Texture shink, mode 4 selected (only > 256 /2, >=1024 /4 )\n"));
    }
    if (env_shrink && strcmp(env_shrink, "5") == 0) {
        texshrink = 5;
        SHUT(LOGD("LIBGL: Texture shink, mode 5 selected (every > 256 is downscaled to 256 ), but not for empty texture\n"));
    }
    if (env_shrink && strcmp(env_shrink, "6") == 0) {
        texshrink = 6;
        SHUT(LOGD("LIBGL: Texture shink, mode 6 selected (only > 128 /2, >=512 is downscaled to 256 ), but not for empty texture\n"));
    }
    if (env_shrink && strcmp(env_shrink, "7") == 0) {
        texshrink = 7;
        SHUT(LOGD("LIBGL: Texture shink, mode 7 selected (only > 512 /2 ), but not for empty texture\n"));
    }
    if (env_shrink && strcmp(env_shrink, "8") == 0) {
        texshrink = 8;
        SHUT(LOGD("LIBGL: Texture shink, mode 8 selected (advertise 8192 max texture size, but >2048 are shrinked to 2048)\n"));
    }
    if (env_shrink && strcmp(env_shrink, "9") == 0) {
        texshrink = 9;
        SHUT(LOGD("LIBGL: Texture shink, mode 9 selected (advertise 8192 max texture size, but >4096 are quadshrinked and > 512 are shrinked), but not for empty texture\n"));
    }
    if (env_shrink && strcmp(env_shrink, "10") == 0) {
        texshrink = 10;
        SHUT(LOGD("LIBGL: Texture shink, mode 10 selected (advertise 8192 max texture size, but >2048 are quadshrinked and > 512 are shrinked), but not for empty texture\n"));
    }
    char *env_dump = getenv("LIBGL_TEXDUMP");
    if (env_dump && strcmp(env_dump, "1") == 0) {
        texdump = 1;
        SHUT(LOGD("LIBGL: Texture dump enabled\n"));
    }
    char *env_alpha = getenv("LIBGL_ALPHAHACK");
    if (env_alpha && strcmp(env_alpha, "1") == 0) {
        alphahack = 1;
        SHUT(LOGD("LIBGL: Alpha Hack enabled\n"));
    }
#ifdef TEXSTREAM
    char *env_stream = getenv("LIBGL_STREAM");
    if (env_stream && strcmp(env_stream, "1") == 0) {
        texstream = InitStreamingCache();
        SHUT(LOGD("LIBGL: Streaming texture %s\n",(texstream)?"enabled":"not available"));
        //FreeStreamed(AddStreamed(1024, 512, 0));
    }
    if (env_stream && strcmp(env_stream, "2") == 0) {
        texstream = InitStreamingCache()?2:0;
        SHUT(LOGD("LIBGL: Streaming texture %s\n",(texstream)?"forced":"not available"));
        //FreeStreamed(AddStreamed(1024, 512, 0));
    }
#endif
    char *env_copy = getenv("LIBGL_COPY");
    if (env_copy && strcmp(env_copy, "1") == 0) {
        SHUT(LOGD("LIBGL: No glCopyTexImage2D / glCopyTexSubImage2D hack\n"));
        copytex = 1;
    }
    char *env_lumalpha = getenv("LIBGL_NOLUMALPHA");
    if (env_lumalpha && strcmp(env_lumalpha, "1") == 0) {
        nolumalpha = 1;
        SHUT(LOGD("LIBGL: GL_LUMINANCE_ALPHA hardware support disabled\n"));
    }

    env(LIBGL_BLENDHACK, blendhack, "Change Blend GL_SRC_ALPHA, GL_ONE to GL_ONE, GL_ONE");
    env(LIBGL_BLENDCOLOR, export_blendcolor, "Export a (faked) glBlendColor");
    env(LIBGL_NOERROR, glshim_noerror, "glGetError() always return GL_NOERROR");
    env(LIBGL_SILENTSTUB, export_silentstub, "Stub/non present functions are not printed");
    
    char *env_version = getenv("LIBGL_VERSION");
    if (env_version) {
        SHUT(LOGD("LIBGL: Overide version string with \"%s\" (should be in the form of \"1.x\")\n", env_version));
    }
    snprintf(glshim_version, 49, "%s glshim wrapper", (env_version)?env_version:"1.5");
#ifdef PANDORA
    char *env_gamma = getenv("LIBGL_GAMMA");
    if (env_gamma) {
        pandora_gamma=atof(env_gamma);
        SHUT(LOGD("LIBGL: Set gamma to %.2f\n", pandora_gamma));
        atexit(pandora_reset_gamma);
    }
#endif
    char *env_srgb = getenv("LIBGL_SRGB");
    if (env_srgb && strcmp(env_srgb, "1") == 0 && hardext.srgb) {
        glx_surface_srgb = 2;
        SHUT(LOGD("LIBGL: enabling sRGB support\n"));
    }
    char *env_fastmath = getenv("LIBGL_FASTMATH");
    if (env_fastmath && strcmp(env_fastmath, "1") == 0) {
#ifdef PANDORA
        SHUT(LOGD("LIBGL: Enable FastMath for cortex-a8\n"));
        fast_math();
#else
        SHUT(LOGD("LIBGL: No FastMath on this platform\n"));
#endif
    }
    char *env_npot = getenv("LIBGL_NPOT");
    glshim_npot = hardext.npot;
    if (env_npot && strcmp(env_npot, "1") == 0 && glshim_npot<1) {
		glshim_npot = 1;
		SHUT(LOGD("LIBGL: Expose limited NPOT extension\n"));
	}
    if (env_npot && strcmp(env_npot, "2") == 0 && glshim_npot<2) {
		glshim_npot = 2;
		SHUT(LOGD("LIBGL: Expose GL_ARB_texture_non_power_of_two extension\n"));
	}
   char *env_queries = getenv("LIBGL_GLQUERIES");
    if (env_queries && strcmp(env_queries, "0") == 0) {
        glshim_queries = 0;
        SHUT(LOGD("LIBGL: Dont't expose fake glQueries functions\n"));
    }
     
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd))!= NULL)
        SHUT(LOGD("LIBGL: Current folder is:%s\n", cwd));
}

#ifndef ANDROID	
EXPORT GLXContext glXCreateContext(Display *display,
                            XVisualInfo *visual,
                            GLXContext shareList,
                            Bool isDirect) {
    //printf("glXCreateContext(%p, %p, %p, %i)\n", display, visual, shareList, isDirect);
    EGLint configAttribs[] = {
#ifdef PANDORA
        EGL_RED_SIZE, 5,
        EGL_GREEN_SIZE, 6,
        EGL_BLUE_SIZE, 5,
#endif
        EGL_DEPTH_SIZE, 16,
#ifdef USE_ES2
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
#else
        EGL_BUFFER_SIZE, 16,
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT | EGL_PBUFFER_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES_BIT,
#endif
        EGL_NONE
    };

    scan_env();
    
    if (g_usefb && fbcontext_count>0) {
        // don't create a new context, one FB is enough...
        fbcontext_count++;
        return fbContext;
    }

#ifdef BCMHOST
    if (! g_bcm_active) {
        g_bcm_active = true;
        bcm_host_init();
    }
#endif

    LOAD_EGL(eglMakeCurrent);
    LOAD_EGL(eglDestroyContext);
    LOAD_EGL(eglDestroySurface);
    LOAD_EGL(eglBindAPI);
    LOAD_EGL(eglInitialize);
    LOAD_EGL(eglCreateContext);
    LOAD_EGL(eglChooseConfig);
    LOAD_EGL(eglQueryString);
    
    GLXContext fake = malloc(sizeof(struct __GLXContextRec));
	memset(fake, 0, sizeof(struct __GLXContextRec));

    if(g_usefb)
        fbContext = fake;
    // make an egl context here...
    EGLBoolean result;
    if (eglDisplay == NULL || eglDisplay == EGL_NO_DISPLAY) {
        init_display(display);
        if (eglDisplay == EGL_NO_DISPLAY) {
            LOGE("LIBGL: Unable to create EGL display.\n");
            free(fake);
            return 0;
        }
    }

    // first time?
    if (eglInitialized == false) {
        egl_eglBindAPI(EGL_OPENGL_ES_API);
        result = egl_eglInitialize(eglDisplay, NULL, NULL);
        if (result != EGL_TRUE) {
            LOGE("LIBGL: Unable to initialize EGL display.\n");
            free(fake);
            return 0;
        }
        eglInitialized = true;
    }

    int configsFound;
	result = egl_eglChooseConfig(eglDisplay, configAttribs, fake->eglConfigs, 1, &configsFound);
    if(g_usefb)
		eglConfigs[0] = fake->eglConfigs[0];

    CheckEGLErrors();
    if (result != EGL_TRUE || configsFound == 0) {
        LOGE("LIBGL: No EGL configs found.\n");
        free(fake);
        return 0;
    }
    EGLContext shared = (shareList)?shareList->eglContext:EGL_NO_CONTEXT;
	fake->eglContext = egl_eglCreateContext(eglDisplay, fake->eglConfigs[0], shared, egl_context_attrib);
    if(g_usefb)
        eglContext = fake->eglContext;

    CheckEGLErrors();

    // need to return a glx context pointing at it
    fake->display = (g_usefb)?g_display:display;
    fake->direct = true;
    fake->xid = 1;  //TODO: Proper handling of that id...
    fake->contextType = 0;  //Window
#ifdef PANDORA
    fake->rbits = 5; fake->gbits=6; fake->bbits=5; fake->abits=0;
#else
    fake->rbits = 8; fake->gbits=8; fake->bbits=8; fake->abits=8;
#endif
    fake->samples = 0; fake->samplebuffers = 0;

    fake->glstate = NewGLState((shareList)?shareList->glstate:NULL);
    /*
    // why unassign the context, it's not assigned yet
   	if (!g_usefb) {
		// unassign the context, it's not supposed to be active at the creation
		egl_eglMakeCurrent(eglDisplay, NULL, NULL, EGL_NO_CONTEXT);
	}
    */

    return fake;
}

GLXContext createPBufferContext(Display *display, GLXContext shareList, GLXFBConfig config) {

    EGLint configAttribs[] = {
        EGL_RED_SIZE, (config)?config->redBits:0,
        EGL_GREEN_SIZE, (config)?config->greenBits:0,
        EGL_BLUE_SIZE, (config)?config->blueBits:0,
        EGL_ALPHA_SIZE, (config)?config->alphaBits:0,
        EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES_BIT,
        EGL_SAMPLE_BUFFERS, (config)?config->nMultiSampleBuffers:0,
        EGL_SAMPLES, (config)?config->multiSampleSize:0,
        EGL_NONE
    };

    LOAD_EGL(eglBindAPI);
    LOAD_EGL(eglInitialize);
    LOAD_EGL(eglChooseConfig);
    LOAD_EGL(eglCreateContext);
    LOAD_EGL(eglGetConfigAttrib);

    // Check that the config is for PBuffer
    if(config->drawableType&GLX_PBUFFER_BIT!=GLX_PBUFFER_BIT)
        return 0;

    // Init what need to be done
    EGLBoolean result;
    if (eglDisplay == NULL || eglDisplay == EGL_NO_DISPLAY) {
        init_display((g_usefb)?g_display:display);
        if (eglDisplay == EGL_NO_DISPLAY) {
            LOGE("LIBGL: Unable to create EGL display.\n");
            return 0;
        }
    }

    // first time?
    if (eglInitialized == false) {
        egl_eglBindAPI(EGL_OPENGL_ES_API);
        result = egl_eglInitialize(eglDisplay, NULL, NULL);
        if (result != EGL_TRUE) {
            LOGE("LIBGL: Unable to initialize EGL display.\n");
            return 0;
        }
        eglInitialized = true;
    }

	// select a configuration
    int configsFound;
    static EGLConfig pbufConfigs[1];
    result = egl_eglChooseConfig(eglDisplay, configAttribs, pbufConfigs, 1, &configsFound);

    CheckEGLErrors();
    if (result != EGL_TRUE || configsFound == 0) {
        LOGE("LIBGL: No EGL configs found.\n");
        return 0;
    }

    EGLContext shared = (shareList)?shareList->eglContext:EGL_NO_CONTEXT;
    
    GLXContext fake = malloc(sizeof(struct __GLXContextRec));
	memset(fake, 0, sizeof(struct __GLXContextRec));
    fake->glstate = NewGLState((shareList)?shareList->glstate:NULL);

	fake->eglContext = egl_eglCreateContext(eglDisplay, fake->eglConfigs[0], shared, egl_context_attrib);

    CheckEGLErrors();

    // need to return a glx context pointing at it
    fake->display = (g_usefb)?g_display:display;
    fake->direct = true;
    fake->xid = 1;  //TODO: Proper handling of that id...
    fake->contextType = 1;  //PBuffer
    egl_eglGetConfigAttrib(eglDisplay, fake->eglConfigs[0], EGL_RED_SIZE, &fake->rbits);
    egl_eglGetConfigAttrib(eglDisplay, fake->eglConfigs[0], EGL_GREEN_SIZE, &fake->gbits);
    egl_eglGetConfigAttrib(eglDisplay, fake->eglConfigs[0], EGL_BLUE_SIZE, &fake->bbits);
    egl_eglGetConfigAttrib(eglDisplay, fake->eglConfigs[0], EGL_ALPHA_SIZE, &fake->abits);
    egl_eglGetConfigAttrib(eglDisplay, fake->eglConfigs[0], EGL_DEPTH_SIZE, &fake->depth);
    egl_eglGetConfigAttrib(eglDisplay, fake->eglConfigs[0], EGL_STENCIL_SIZE, &fake->stencil);
    egl_eglGetConfigAttrib(eglDisplay, fake->eglConfigs[0], EGL_SAMPLES, &fake->samples);
    egl_eglGetConfigAttrib(eglDisplay, fake->eglConfigs[0], EGL_SAMPLE_BUFFERS, &fake->samplebuffers);
        
    return fake;
}

EXPORT GLXContext glXCreateContextAttribsARB(Display *display, GLXFBConfig config,
                                      GLXContext share_context, Bool direct,
                                      const int *attrib_list) {
    //printf("glXCreateContextAttribsARB(%p, %p, %p, %d) ", display, config, share_context, direct);if(config)printf("config is RGBA:%d%d%d%d, depth=%d, stencil=%d, drawable=%d\n", config->redBits, config->greenBits, config->blueBits, config->alphaBits, config->depthBits, config->stencilBits, config->drawableType); else printf("\n");
    if(config && config->drawableType==GLX_PBUFFER_BIT) {
        return createPBufferContext(display, share_context, config);
    } else {
        EGLint configAttribs[] = {
#ifdef PANDORA
            EGL_RED_SIZE, (config->drawableType)==GLX_PIXMAP_BIT?config->redBits:5,
            EGL_GREEN_SIZE, (config->drawableType)==GLX_PIXMAP_BIT?config->greenBits:6,
            EGL_BLUE_SIZE, (config->drawableType)==GLX_PIXMAP_BIT?config->blueBits:5,
            EGL_ALPHA_SIZE, (config->drawableType)==GLX_PIXMAP_BIT?config->alphaBits:0,
#else
            EGL_RED_SIZE, config->redBits,
            EGL_GREEN_SIZE, config->greenBits,
            EGL_BLUE_SIZE, config->blueBits,
            EGL_ALPHA_SIZE, config->alphaBits,
#endif
            EGL_DEPTH_SIZE, config->depthBits,
            EGL_STENCIL_SIZE, config->stencilBits,
#ifdef USE_ES2
            EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
#else
            EGL_SURFACE_TYPE, (config->drawableType)==GLX_PIXMAP_BIT?EGL_PIXMAP_BIT:(EGL_WINDOW_BIT | EGL_PBUFFER_BIT),
            EGL_RENDERABLE_TYPE, EGL_OPENGL_ES_BIT,
#endif
            EGL_NONE
        };

        scan_env();

        if (g_usefb && fbcontext_count>0) {
            // don't create a new context, one FB is enough...
            fbcontext_count++;
            return fbContext;
        }

#ifdef BCMHOST
        if (! g_bcm_active) {
            g_bcm_active = true;
            bcm_host_init();
        }
#endif

        LOAD_EGL(eglMakeCurrent);
        LOAD_EGL(eglDestroyContext);
        LOAD_EGL(eglDestroySurface);
        LOAD_EGL(eglBindAPI);
        LOAD_EGL(eglInitialize);
        LOAD_EGL(eglCreateContext);
        LOAD_EGL(eglChooseConfig);
        LOAD_EGL(eglQueryString);
        LOAD_EGL(eglGetConfigAttrib);

        GLXContext fake = malloc(sizeof(struct __GLXContextRec));
        memset(fake, 0, sizeof(struct __GLXContextRec));

        fake->glstate = NewGLState((share_context)?share_context->glstate:NULL);
        if(g_usefb)
            fbContext = fake;
        // make an egl context here...
        EGLBoolean result;
        if (eglDisplay == NULL || eglDisplay == EGL_NO_DISPLAY) {
            init_display(display);
            if (eglDisplay == EGL_NO_DISPLAY) {
                LOGE("LIBGL: Unable to create EGL display.\n");
                return fake;
            }
        }

        // first time?
        if (eglInitialized == false) {
            egl_eglBindAPI(EGL_OPENGL_ES_API);
            result = egl_eglInitialize(eglDisplay, NULL, NULL);
            if (result != EGL_TRUE) {
                LOGE("LIBGL: Unable to initialize EGL display.\n");
                return fake;
            }
            eglInitialized = true;
        }

        int configsFound;
        result = egl_eglChooseConfig(eglDisplay, configAttribs, fake->eglConfigs, 1, &configsFound);
        if(g_usefb)
            eglConfigs[0] = fake->eglConfigs[0];

        CheckEGLErrors();
        if (result != EGL_TRUE || configsFound == 0) {
            LOGE("LIBGL: No EGL configs found.\n");
            return fake;
        }
        EGLContext shared = (share_context)?share_context->eglContext:EGL_NO_CONTEXT;
        fake->eglContext = egl_eglCreateContext(eglDisplay, fake->eglConfigs[0], shared, egl_context_attrib);
        if(g_usefb)
            eglContext = fake->eglContext;

        CheckEGLErrors();

        // need to return a glx context pointing at it
        fake->display = (g_usefb)?g_display:display;
        fake->direct = true;
        fake->xid = 1;  //TODO: Proper handling of that id...
        fake->contextType = 0;  //Window

        egl_eglGetConfigAttrib(eglDisplay, fake->eglConfigs[0], EGL_RED_SIZE, &fake->rbits);
        egl_eglGetConfigAttrib(eglDisplay, fake->eglConfigs[0], EGL_GREEN_SIZE, &fake->gbits);
        egl_eglGetConfigAttrib(eglDisplay, fake->eglConfigs[0], EGL_BLUE_SIZE, &fake->bbits);
        egl_eglGetConfigAttrib(eglDisplay, fake->eglConfigs[0], EGL_ALPHA_SIZE, &fake->abits);
        egl_eglGetConfigAttrib(eglDisplay, fake->eglConfigs[0], EGL_DEPTH_SIZE, &fake->depth);
        egl_eglGetConfigAttrib(eglDisplay, fake->eglConfigs[0], EGL_STENCIL_SIZE, &fake->stencil);
        egl_eglGetConfigAttrib(eglDisplay, fake->eglConfigs[0], EGL_SAMPLES, &fake->samples);
        egl_eglGetConfigAttrib(eglDisplay, fake->eglConfigs[0], EGL_SAMPLE_BUFFERS, &fake->samplebuffers);

        return fake;
    }
}

EXPORT void glXDestroyContext(Display *display, GLXContext ctx) {
    //printf("glXDestroyContext(%p, %p)\n", display, ctx);
    if (g_usefb && ctx->contextType==0) {
        if (fbcontext_count==0)
            return; // Should not happens!
        if (--fbcontext_count > 0)
            return; // Nothing to do...
    }
    if ((!g_usefb && ctx->eglContext) || (g_usefb && eglContext)) {
        if (g_usefbo && ctx->contextType==0) {
            deleteMainFBO();
        }

        DeleteGLState(ctx->glstate);
        
        LOAD_EGL(eglDestroyContext);
        LOAD_EGL(eglDestroySurface);
        
		EGLBoolean result = egl_eglDestroyContext(eglDisplay, ctx->eglContext);
        ctx->eglContext = 0;
        if (ctx->eglSurface != 0) {
            egl_eglDestroySurface(eglDisplay, ctx->eglSurface);
			ctx->eglSurface = 0;
        }
        if(g_usefb && ctx->contextType==0) {
            // clean global eglFB too
            eglSurface = 0;
            eglContext = 0;
        }

        if (result != EGL_TRUE) {
            LOGE("LIBGL: Failed to destroy EGL context.\n");
        }
        /*if (fbdev >= 0) {
            close(fbdev);
            fbdev = -1;
        }*/
    }
    if (g_usefb)
        fbContext = NULL;
        
    return;
}

EXPORT Display *glXGetCurrentDisplay() {
	if (!g_usefb)
		return XOpenDisplay(NULL);
	else
		if (g_display && eglContext) {
			return g_display;
		}
    return XOpenDisplay(NULL);
}

EXPORT XVisualInfo *glXChooseVisual(Display *display,
                             int screen,
                             int *attributes) {

    // apparently can't trust the Display I'm passed?
/*
    if (g_display == NULL) {
        g_display = XOpenDisplay(NULL);
    }
*/
    glx_default_depth = XDefaultDepth(display, screen);
    if (glx_default_depth != 16 && glx_default_depth != 24  && glx_default_depth != 32)
        LOGD("LIBGL: unusual desktop color depth %d\n", glx_default_depth);

    XVisualInfo *visual = (XVisualInfo *)malloc(sizeof(XVisualInfo));
    if (!XMatchVisualInfo(display, screen, glx_default_depth, TrueColor, visual)) {
        LOGE("LIBGL: XMatchVisualInfo failed in glXChooseVisual\n");
        return NULL;
    }

    return visual;
}

/*
EGL_BAD_MATCH is generated if draw or read are not compatible with context
or if context is set to EGL_NO_CONTEXT and draw or read are not set to
EGL_NO_SURFACE, or if draw or read are set to EGL_NO_SURFACE and context is
not set to EGL_NO_CONTEXT.
*/

EXPORT Bool glXMakeCurrent(Display *display,
                    GLXDrawable drawable,
                    GLXContext context) {
    //printf("glXMakeCurrent(%p, %p, %p) 'isPBuffer(drawable)=%d\n", display, drawable, context, isPBuffer(drawable));                        
    LOAD_EGL(eglMakeCurrent);
    LOAD_EGL(eglDestroySurface);
    LOAD_EGL(eglCreateWindowSurface);
    LOAD_EGL(eglQuerySurface);
#ifdef ANDROID
    int created = 0;
#else
    int created = (context)?isPBuffer(drawable):0;
#endif
    EGLint const sRGB[] = {EGL_GL_COLORSPACE_KHR, EGL_GL_COLORSPACE_SRGB_KHR, EGL_NONE};
    EGLContext eglContext = EGL_NO_CONTEXT;
    EGLSurface eglSurf = 0;
    EGLConfig eglConfig = 0;
    if(context) {
        eglContext = context->eglContext;
        if(context->drawable==drawable && context->eglSurface)
            // same-same, recycling...
            eglSurf = context->eglSurface;
        else {
            // new one
            if(created) {
#ifndef ANDROID
                eglSurf = context->eglSurface = pbuffersize[created-1].Surface; //(EGLSurface)drawable;
                context->eglContext = eglContext = pbuffersize[created-1].Context;    // this context is ok for the PBuffer
#endif
            } else {
#ifndef ANDROID
                if(g_usefb) {
                    if(g_usepbuffer) {
                        // Get Window size and all...
                        unsigned int width, height, border, depth;
                        Window root;
                        int x, y;
                        XGetGeometry(display, drawable, &root, &x, &y, &width, &height, &border, &depth);
                        //let's create a PBuffer attributes
                        EGLint egl_attribs[10];	// should be enough
                        int i = 0;
                        egl_attribs[i++] = EGL_WIDTH;
                        egl_attribs[i++] = width;
                        egl_attribs[i++] = EGL_HEIGHT;
                        egl_attribs[i++] = height;
                        egl_attribs[i++] = EGL_NONE;

                        if(createPBuffer(display, egl_attribs, &eglSurf, &eglContext, (depth>16)?8:5, (depth==15)?5:(depth>16)?8:6, (depth>16)?8:5, (depth==32)?8:0, context->samplebuffers, context->samples)==0) {
                            // fail too, abort
                            SHUT(LOGE("LIBGL: PBuffer creation failed too\n"));
                            return 0;
                        }
                        int Width, Height;

                        egl_eglQuerySurface(eglDisplay,eglSurf,EGL_WIDTH,&Width);
                        egl_eglQuerySurface(eglDisplay,eglSurf,EGL_HEIGHT,&Height);

                        addPixBuffer(display, eglSurf, Width, Height, eglContext, drawable, depth, 2);
                        context->eglSurface = eglSurf;
                        context->eglContext = eglContext;
                        // update, that context is a created emulated one...
                        created = isPBuffer(drawable); 
                    } else
#endif
                    
                    if(eglSurface)
                        eglSurf = context->eglSurface = eglSurface;
                    else 
                        eglSurface = eglSurf = context->eglSurface = egl_eglCreateWindowSurface(eglDisplay, context->eglConfigs[0], 0, (glx_surface_srgb)?sRGB:NULL);
                } else {
                    if(context->eglSurface)
                        egl_eglDestroySurface(eglDisplay, context->eglSurface);
                    eglSurf = context->eglSurface = egl_eglCreateWindowSurface(eglDisplay, context->eglConfigs[0], drawable, (glx_surface_srgb)?sRGB:NULL);
                }
            }
        }
        eglConfig = context->eglConfigs[0];
    }
    glxContext = context;
    EGLBoolean result = egl_eglMakeCurrent(eglDisplay, eglSurf, eglSurf, eglContext);
    CheckEGLErrors();
    {
        // update MapDrawable
        int ret;
        khint_t k = kh_get(mapdrawable, MapDrawable, drawable);
        map_drawable_t* map = NULL;
        if (k == kh_end(MapDrawable)){
            k = kh_put(mapdrawable, MapDrawable, drawable, &ret);
            map = kh_value(MapDrawable, k) = (map_drawable_t*)malloc(sizeof(map_drawable_t));
            map->drawable = drawable;
        } else {
            map = kh_value(MapDrawable, k);
        }
        map->surface = eglSurf;
        map->PBuffer = created;

        if(created) pbuffersize[created-1].glxcontext = context;
    }
    
    if (context) {
        context->drawable = drawable;

        ActivateGLState(context->glstate);
#ifdef PANDORA
        if(created) pandora_set_gamma();
#endif
        glstate->emulatedPixmap = 0;
        glstate->emulatedWin = 0;
        if(created && pbuffersize[created-1].Type >= 3) {
            glstate->emulatedPixmap = created;
            glstate->emulatedWin = pbuffersize[created-1].Type==4?1:0;
        }

        CheckEGLErrors();
        if (result) {
            if (g_usefbo && created) {
                // get size of the surface...
                egl_eglQuerySurface(eglDisplay,eglSurf,EGL_WIDTH,&g_width);
                egl_eglQuerySurface(eglDisplay,eglSurf,EGL_HEIGHT,&g_height);
                // create the main_fbo...
                LOGD("LIBGL: Create FBO of %ix%i 32bits\n", g_width, g_height);
                createMainFBO(g_width, g_height);
            }
            // finished
            return true;
        }
        return false;
    }
    return true;
}

EXPORT Bool glXMakeContextCurrent(Display *display, int drawable,
                           int readable, GLXContext context) {
    //printf("glXMakeContextCurrent(%p, %X, %X, %p)\n", display, drawable, readable, context);
    return glXMakeCurrent(display, drawable, context);
}

EXPORT void glXSwapBuffers(Display *display,
                    int drawable) {
    static int frames = 0;
    
    LOAD_EGL(eglSwapBuffers);
    // TODO: what if active context is not on the drawable?
    int old_batch = glstate->gl_batch;
    if (glstate->gl_batch || glstate->list.active){
        flush();
    }
    EGLSurface surface = eglSurface;
    int PBuffer = 0;
    {
        // get MapDrawable surface
        khint_t k = kh_get(mapdrawable, MapDrawable, drawable);
        map_drawable_t* map = NULL;
        if (k != kh_end(MapDrawable)){
            map = kh_value(MapDrawable, k);
            surface = map->surface;
            PBuffer = map->PBuffer;
        }
    }
#ifdef USE_FBIO
    if (g_vsync && fbdev >= 0 && PBuffer==0) {
        // TODO: can I just return if I don't meet vsync over multiple frames?
        // this will just block otherwise.
        int arg = 0;
        for (int i = 0; i < swap_interval; i++) {
            ioctl(fbdev, FBIO_WAITFORVSYNC, &arg);
        }
    }
#endif
    if (g_usefbo && PBuffer==0) {
        glstate->gl_batch = 0;
        unbindMainFBO();
        blitMainFBO();
        // blit the main_fbo before swap
    }
    // check emulated Pixmap
    if(PBuffer && glstate->emulatedPixmap) {
        LOAD_GLES(glFlush);
        gles_glFlush();
        BlitEmulatedPixmap();
    } else
        egl_eglSwapBuffers(eglDisplay, surface);
    CheckEGLErrors();
#ifdef PANDORA
    if (g_showfps || (sock>-1)) {
        // framerate counter
        static float avg, fps = 0;
        static int frame1, last_frame, frame, now, current_frames;
        struct timeval out;
        gettimeofday(&out, NULL);
        now = out.tv_sec;
        frame++;
        current_frames++;

        if (frame == 1) {
            frame1 = now;
        } else if (frame1 < now) {
            if (last_frame < now) {
                float change = current_frames / (float)(now - last_frame);
                float weight = 0.7;
                if (! fps) {
                    fps = change;
                } else {
                    fps = (1 - weight) * fps + weight * change;
                }
                current_frames = 0;

                avg = frame / (float)(now - frame1);
                if (g_showfps) LOGD("LIBGL: fps: %.2f, avg: %.2f\n", fps, avg);
                if (sock>-1) {
                    char tmp[60];
                    snprintf(tmp, 60, "gl:  %2.2f", fps);
                    sendto(sock, tmp, strlen(tmp), 0,(struct sockaddr *)&sun, sizeof(sun));                    
                }
            }
        }
        last_frame = now;
    }
#endif
    if (g_usefbo && PBuffer==0) {
        glstate->gl_batch = old_batch;
        bindMainFBO();
    }
}

EXPORT int glXGetConfig(Display *display,
                 XVisualInfo *visual,
                 int attribute,
                 int *value) {
    return get_config_default(display, attribute, value);
}

EXPORT const char *glXQueryExtensionsString(Display *display, int screen) {
    const char *extensions = {
        "GLX_ARB_create_context "
        "GLX_ARB_create_context_profile "
        "GLX_ARB_get_proc_address "
        "GLX_ARB_multisample "
//        "GLX_EXT_create_context_es2_profile "
    };
    return extensions;
}

EXPORT const char *glXQueryServerString(Display *display, int screen, int name) {
    return "";
}

EXPORT Bool glXQueryExtension(Display *display, int *errorBase, int *eventBase) {
    if (errorBase)
        *errorBase = 0;

    if (eventBase)
        *eventBase = 0;

    return true;
}

EXPORT Bool glXQueryVersion(Display *display, int *major, int *minor) {
    // TODO: figure out which version we want to pretend to implement
    *major = 1;
    *minor = 4;
    return true;
}

EXPORT const char *glXGetClientString(Display *display, int name) {
    // TODO: return actual data here
    switch (name) {
        case GLX_VENDOR: return "ptitSeb";
        case GLX_VERSION: return "1.4 OpenPandora";
        case GLX_EXTENSIONS: break;
    }
    return "";
}

EXPORT int glXQueryContext( Display *dpy, GLXContext ctx, int attribute, int *value ){
	*value=0;
	if (ctx) switch (attribute) {
		case GLX_FBCONFIG_ID: *value=ctx->xid; break;
		case GLX_RENDER_TYPE: *value=GLX_RGBA_TYPE; break;
		case GLX_SCREEN: break;			// screen n# is always 0
	}
    return 0;
}

/*
EXPORT void glXQueryDrawable( Display *dpy, int draw, int attribute,
                       unsigned int *value ) {
	*value=0;
}
*/
// stubs for glfw (GLX 1.3)
EXPORT GLXContext glXGetCurrentContext() {
    // hack to make some games start
    if (g_usefb)
		return glxContext ? glxContext : fbContext;
	else
		return glxContext;
}

EXPORT GLXFBConfig *glXChooseFBConfig(Display *display, int screen,
                       const int *attrib_list, int *count) {
    //printf("glXChooseFBConfig(%p, %d, %p, %p)\n", display, screen, attrib_list, count);
    // this is not really good. A static table of all config should be build, and then a filter done according to attribs...
    static struct __GLXFBConfigRec currentConfig[8];
    static int idx = 0;
    *count = 1;
    GLXFBConfig *configs = (GLXFBConfig *)malloc(sizeof(GLXFBConfig));
    configs[0] = &currentConfig[idx];
    idx=(idx+1)%8;
    memset(configs[0], 0, sizeof(struct __GLXFBConfigRec));
    // fill that config with some of the attrib_list info...
    configs[0]->drawableType = GLX_WINDOW_BIT;
    configs[0]->screen = 0;
    configs[0]->maxPbufferWidth = configs[0]->maxPbufferHeight = 2048;
    configs[0]->redBits = configs[0]->greenBits = configs[0]->blueBits = configs[0]->alphaBits = 0;
    configs[0]->nMultiSampleBuffers = 0; configs[0]->multiSampleSize = 0;
    if(attrib_list) {
		int i = 0;
		while(attrib_list[i]!=0) {
			switch(attrib_list[i++]) {
				case GLX_RED_SIZE:
					configs[0]->redBits = attrib_list[i++];
					if(configs[0]->redBits==GLX_DONT_CARE) configs[0]->redBits = 0;
					break;
				case GLX_GREEN_SIZE:
					configs[0]->greenBits = attrib_list[i++];
					if(configs[0]->greenBits==GLX_DONT_CARE) configs[0]->greenBits = 0;
					break;
				case GLX_BLUE_SIZE:
					configs[0]->blueBits = attrib_list[i++];
					if(configs[0]->blueBits==GLX_DONT_CARE) configs[0]->blueBits = 0;
					break;
				case GLX_ALPHA_SIZE:
					configs[0]->alphaBits = attrib_list[i++];
					if(configs[0]->alphaBits==GLX_DONT_CARE) configs[0]->alphaBits = 0;
					break;
                case GLX_DEPTH_SIZE:
					configs[0]->depthBits = attrib_list[i++];
					if(configs[0]->depthBits==GLX_DONT_CARE) configs[0]->depthBits = 0;
					break;
                case GLX_STENCIL_SIZE:
					configs[0]->stencilBits = attrib_list[i++];
					if(configs[0]->stencilBits==GLX_DONT_CARE) configs[0]->stencilBits = 0;
					break;
                case GLX_DRAWABLE_TYPE:
                    configs[0]->drawableType = attrib_list[i++];
                    break;
                case GLX_SAMPLE_BUFFERS:
                    configs[0]->nMultiSampleBuffers = attrib_list[i++];
                    break;
                case GLX_SAMPLES:
                    configs[0]->multiSampleSize = attrib_list[i++];
                    break;
                default:
                    ++i;
				// discard other stuffs
			}
		}
	}
		
    return configs;
}
EXPORT GLXFBConfig *glXChooseFBConfigSGIX(Display *display, int screen,
                       const int *attrib_list, int *count) {
    return glXChooseFBConfig(display, screen, attrib_list, count);
}

EXPORT GLXFBConfig *glXGetFBConfigs(Display *display, int screen, int *count) {
    //printf("glXGetFBConfigs(%p, %d, %p)\n", display, screen, count);
    *count = 1;
    // this is to only do 1 malloc instead of 1 for the array and one for the element...
    GLXFBConfig *configs = (GLXFBConfig *)malloc(sizeof(GLXFBConfig) + sizeof(struct __GLXFBConfigRec));
    configs[0] = (GLXFBConfig)((char*)(&configs[0])+sizeof(GLXFBConfig));
    memset(configs[0], 0, sizeof(struct __GLXFBConfigRec));
    configs[0]->drawableType = GLX_WINDOW_BIT | GLX_PBUFFER_BIT;
    configs[0]->redBits = configs[0]->greenBits = configs[0]->blueBits = configs[0]->alphaBits = 8;    
    configs[0]->multiSampleSize = 0; configs[0]->nMultiSampleBuffers = 0;
    return configs;
}

EXPORT int glXGetFBConfigAttrib(Display *display, GLXFBConfig config, int attribute, int *value) {
    //printf("glXGetFBConfigAttrib(%p, %p, 0x%04X, %p)\n", display, config, attribute, value);
    if(!config)
        return get_config_default(display, attribute, value);

    switch (attribute) {
        case GLX_RGBA:
            *value = config->alphaBits>0?1:0;
        case GLX_RED_SIZE:
            *value = config->redBits;
            break;
        case GLX_GREEN_SIZE:
            *value = config->greenBits;
            break;
        case GLX_BLUE_SIZE:
            *value = config->blueBits;
            break;
        case GLX_ALPHA_SIZE:
            *value = config->alphaBits;
            break;
        case GLX_DEPTH_SIZE:
            *value = config->depthBits;
            break;
        case GLX_STENCIL_SIZE:
            *value = config->stencilBits;
            break;
        case GLX_ACCUM_RED_SIZE:
        case GLX_ACCUM_GREEN_SIZE:
        case GLX_ACCUM_BLUE_SIZE:
        case GLX_ACCUM_ALPHA_SIZE:
            *value = 0;
            break;
        case GLX_TRANSPARENT_TYPE:
            *value = GLX_NONE;
            break;
        case GLX_RENDER_TYPE:
            *value = GLX_RGBA_TYPE;
            break;
        case GLX_VISUAL_ID:
            *value = glXChooseVisual(display, 0, NULL)->visualid; //config->associatedVisualId;
            //*value = 1;
            break;
        case GLX_FBCONFIG_ID:
            *value = 1;
            break;
        case GLX_DRAWABLE_TYPE:
            *value = GLX_WINDOW_BIT; //config->drawableType;
            break;
        case GLX_X_VISUAL_TYPE:
        case GLX_CONFIG_CAVEAT:
            *value = 0;
            break;
        case GLX_SAMPLE_BUFFERS:
            *value = config->nMultiSampleBuffers;
            break;
        case GLX_SAMPLES:
            *value = config->multiSampleSize;
            break;
        case GLX_FRAMEBUFFER_SRGB_CAPABLE_ARB:
            *value = hardext.srgb;
            break;
        default:
            return get_config_default(display, attribute, value);
   }
   return Success;
}

EXPORT XVisualInfo *glXGetVisualFromFBConfig(Display *display, GLXFBConfig config) {
    //printf("glXGetVisualFromFBConfig(%p, %p)\n", display, config);
    /*if (g_display == NULL) {
        g_display = XOpenDisplay(NULL);
    }*/
    if (glx_default_depth==0)
        glx_default_depth = XDefaultDepth(display, 0);
    XVisualInfo *visual = (XVisualInfo *)malloc(sizeof(XVisualInfo));
    XMatchVisualInfo(display, 0, glx_default_depth, TrueColor, visual);
    return visual;
}

EXPORT GLXContext glXCreateNewContext(Display *display, GLXFBConfig config,
                               int render_type, GLXContext share_list,
                               Bool is_direct) {
    //printf("glXCreateNewContext(%p, %p, %d, %p, %i), drawableType=0x%02X\n", display, config, render_type, share_list, is_direct, (config)?config->drawableType:0);
    if(render_type!=GLX_RGBA_TYPE)
        return 0;
    if(config && config->drawableType==GLX_PBUFFER_BIT) {
        return createPBufferContext(display, share_list, config);
    } else
        return glXCreateContextAttribsARB(display, config, share_list, is_direct, NULL);
        //return glXCreateContext(display, 0, share_list, is_direct);
}
#endif //ANDROID
EXPORT void glXSwapIntervalMESA(int interval) {
//LOGD("glXSwapInterval(%i)\n", interval);
#ifdef USE_FBIO
    if (! g_vsync)
        LOGD("LIBGL: Enable LIBGL_VSYNC=1 if you want to use vsync.\n");
    swap_interval = interval;
#else
    LOAD_EGL(eglSwapInterval);
    egl_eglSwapInterval(eglDisplay, swap_interval);
#endif
}

EXPORT void glXSwapIntervalSGI(int interval) {
    glXSwapIntervalMESA(interval);
}

#ifndef ANDROID
EXPORT void glXSwapIntervalEXT(Display *display, int drawable, int interval) {
    glXSwapIntervalMESA(interval);
}

// misc stubs
EXPORT void glXCopyContext(Display *display, GLXContext src, GLXContext dst, GLuint mask) {
	// mask is ignored for now, but should include glPushAttrib / glPopAttrib
	memcpy(dst, src, sizeof(struct __GLXContextRec));
}
EXPORT Window glXCreateWindow(Display *display, GLXFBConfig config, Window win, int *attrib_list) {return win;} // should return GLXWindow
EXPORT void glXDestroyWindow(Display *display, void *win) {} // really wants a GLXWindow

EXPORT GLXDrawable glXGetCurrentDrawable() {
	if (glxContext) 
		return glxContext->drawable; 
	else 
		return 0;
} // this should actually return GLXDrawable.

EXPORT Bool glXIsDirect(Display * display, GLXContext ctx) {
    return true;
}

EXPORT void glXUseXFont(Font font, int first, int count, int listBase) {
	/* Mostly from MesaGL-9.0.1 
	 * 
	 */
	// First get current Display and Window
	XFontStruct *fs;
	unsigned int max_width, max_height, max_bm_width, max_bm_height;
    Pixmap pixmap;
    XGCValues values;
    GC gc;
    int i;
    unsigned long valuemask;
	GLubyte *bm;
	Display *dpy;
	Window win;
    if (g_usefb) {
        dpy = g_display;
        win = RootWindow(dpy, XDefaultScreen(dpy));
    } else {
        dpy = glxContext->display;
        win = glxContext->drawable;		//TODO, check that drawable is a window and not a pixmap ?
    }

	// Grab font params
	fs = XQueryFont(dpy, font);
    if (!fs) {
      LOGE("LIBGL: error, no font set before call to glXUseFont\n");
      return;
    }
	max_width = fs->max_bounds.rbearing - fs->min_bounds.lbearing;
    max_height = fs->max_bounds.ascent + fs->max_bounds.descent;
    max_bm_width = (max_width + 7) / 8;
    max_bm_height = max_height;

    bm = (GLubyte *)malloc((max_bm_width * max_bm_height) * sizeof(GLubyte));
    if (!bm) {
       XFreeFontInfo(NULL, fs, 1);
       return;
    }
    // Save GL texture parameters
    GLint swapbytes, lsbfirst, rowlength;
    GLint skiprows, skippixels, alignment;
    glshim_glGetIntegerv(GL_UNPACK_SWAP_BYTES, &swapbytes);
    glshim_glGetIntegerv(GL_UNPACK_LSB_FIRST, &lsbfirst);
    glshim_glGetIntegerv(GL_UNPACK_ROW_LENGTH, &rowlength);
    glshim_glGetIntegerv(GL_UNPACK_SKIP_ROWS, &skiprows);
    glshim_glGetIntegerv(GL_UNPACK_SKIP_PIXELS, &skippixels);
    glshim_glGetIntegerv(GL_UNPACK_ALIGNMENT, &alignment);
	// Set Safe Texture params
	glshim_glPixelStorei(GL_UNPACK_SWAP_BYTES, GL_FALSE);
    glshim_glPixelStorei(GL_UNPACK_LSB_FIRST, GL_FALSE);
    glshim_glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
    glshim_glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
    glshim_glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
    glshim_glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	// Create GC and Pixmap
	pixmap = XCreatePixmap(dpy, win, 10, 10, 1);
    values.foreground = BlackPixel(dpy, DefaultScreen(dpy));
    values.background = WhitePixel(dpy, DefaultScreen(dpy));
    values.font = fs->fid;
    valuemask = GCForeground | GCBackground | GCFont;
    gc = XCreateGC(dpy, pixmap, valuemask, &values);
    XFreePixmap(dpy, pixmap);
	// Loop each chars
    for (i = 0; i < count; i++) {
       unsigned int width, height, bm_width, bm_height;
       GLfloat x0, y0, dx, dy;
       XCharStruct *ch;
       int x, y;
       unsigned int c = first + i;
       int list = listBase + i;
       int valid;

       /* check on index validity and get the bounds */
       ch = isvalid(fs, c);
       if (!ch) {
          ch = &fs->max_bounds;
          valid = 0;
       }
       else {
          valid = 1;
       }
      /* glBitmap()' parameters:
          straight from the glXUseXFont(3) manpage.  */
       width = ch->rbearing - ch->lbearing;
       height = ch->ascent + ch->descent;
       x0 = -ch->lbearing;
       y0 = ch->descent - 1;
       dx = ch->width;
       dy = 0;
       /* X11's starting point.  */
       x = -ch->lbearing;
       y = ch->ascent;
       /* Round the width to a multiple of eight.  We will use this also
         for the pixmap for capturing the X11 font.  This is slightly
         inefficient, but it makes the OpenGL part real easy.  */
       bm_width = (width + 7) / 8;
       bm_height = height;
       glshim_glNewList(list, GL_COMPILE);
       if (valid && (bm_width > 0) && (bm_height > 0)) {

          memset(bm, '\0', bm_width * bm_height);
          fill_bitmap(dpy, win, gc, bm_width, bm_height, x, y, c, bm);

          glshim_glBitmap(width, height, x0, y0, dx, dy, bm);
       }
       else {
          glshim_glBitmap(0, 0, 0.0, 0.0, dx, dy, NULL);
       }
       glshim_glEndList();
    }

	// Free GC & Pixmap
    free(bm);
    XFreeFontInfo(NULL, fs, 1);
    XFreeGC(dpy, gc);

    // Restore saved packing modes.
    glshim_glPixelStorei(GL_UNPACK_SWAP_BYTES, swapbytes);
    glshim_glPixelStorei(GL_UNPACK_LSB_FIRST, lsbfirst);
    glshim_glPixelStorei(GL_UNPACK_ROW_LENGTH, rowlength);
    glshim_glPixelStorei(GL_UNPACK_SKIP_ROWS, skiprows);
    glshim_glPixelStorei(GL_UNPACK_SKIP_PIXELS, skippixels);
    glshim_glPixelStorei(GL_UNPACK_ALIGNMENT, alignment);
	// All done
}
#endif //ANDROID
EXPORT void glXWaitGL() {}
EXPORT void glXWaitX() {}
EXPORT void glXReleaseBuffersMESA() {}
#ifndef ANDROID
/* TODO proper implementation */
EXPORT int glXQueryDrawable(Display *dpy, GLXDrawable draw, int attribute,	unsigned int *value) {
    int pbuf=isPBuffer(draw);
    *value = 0;
    switch(attribute) {
        case GLX_WIDTH:
            *value = (pbuf)?pbuffersize[pbuf-1].Width:800;
            return 1;
        case GLX_HEIGHT:
            *value = (pbuf)?pbuffersize[pbuf-1].Height:480;
            return 1;
        case GLX_PRESERVED_CONTENTS:
            return 0;
        case GLX_LARGEST_PBUFFER:
            return 0;
        case GLX_FBCONFIG_ID:
            *value = 1;
            return 1;
    }
    return 0;
}

GLXPbuffer addPBuffer(EGLSurface surface, int Width, int Height, EGLContext Context)
{
    if(pbufferlist_cap<=pbufferlist_size) {
        pbufferlist_cap += 4;
        pbufferlist = (GLXPbuffer*)realloc(pbufferlist, sizeof(GLXPbuffer)*pbufferlist_cap);
        pbuffersize = (glx_buffSize*)realloc(pbuffersize, sizeof(glx_buffSize)*pbufferlist_cap);
    }
    pbufferlist[pbufferlist_size] = (GLXPbuffer)surface;
    pbuffersize[pbufferlist_size].Width = Width;
    pbuffersize[pbufferlist_size].Height = Height;
    pbuffersize[pbufferlist_size].Context = Context;
    pbuffersize[pbufferlist_size].Surface = surface;
    pbuffersize[pbufferlist_size].gc = NULL;
    pbuffersize[pbufferlist_size].Type = 1; // 1 = pbuffer
    return pbufferlist[pbufferlist_size++];
}
void delPBuffer(int j)
{
    LOAD_EGL(eglDestroyContext);
    pbufferlist[j] = 0;
    pbuffersize[j].Width = 0;
    pbuffersize[j].Height = 0;
    pbuffersize[j].gc = 0;
    egl_eglDestroyContext(eglDisplay, pbuffersize[j].Context);
    // should pack, but I think it's useless for common use 
}

EXPORT void glXDestroyPbuffer(Display * dpy, GLXPbuffer pbuf) {
//    printf("glxDestroyPBuffer(%p, %p)\n", dpy, pbuf);
    LOAD_EGL(eglDestroySurface);
    int j=0;
    while(j<pbufferlist_size || pbufferlist[j]==pbuf) j++;
    if(j==pbufferlist_size)
        return;
        // delete de Surface
    EGLSurface surface = (EGLSurface)pbufferlist[j];
    egl_eglDestroySurface(dpy, surface);

    delPBuffer(j);
}

int createPBuffer(Display * dpy, const EGLint * egl_attribs, EGLSurface* Surface, EGLContext* Context, int redBits, int greenBits, int blueBits, int alphaBits, int samplebuffers, int samples) {
    LOAD_EGL(eglChooseConfig);
    LOAD_EGL(eglCreatePbufferSurface);
    LOAD_EGL(eglInitialize);
    LOAD_EGL(eglBindAPI);
    LOAD_EGL(eglCreateContext);

    EGLint configAttribs[] = {
        EGL_RED_SIZE, redBits,
        EGL_GREEN_SIZE, greenBits,
        EGL_BLUE_SIZE, blueBits,
        EGL_ALPHA_SIZE, alphaBits,
        EGL_DEPTH_SIZE, 1,
        EGL_STENCIL_SIZE, 1,
        EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES_BIT,
        EGL_SAMPLE_BUFFERS, samplebuffers,
        EGL_SAMPLES, samples,
        EGL_NONE
    };

    // Init what need to be done
    EGLBoolean result;
    if (eglDisplay == NULL || eglDisplay == EGL_NO_DISPLAY) {
        init_display((g_usefb)?g_display:dpy);
        if (eglDisplay == EGL_NO_DISPLAY) {
            LOGD("LIBGL: Unable to create EGL display.\n");
            return 0;
        }
    }

    // first time?
    if (eglInitialized == false) {
        egl_eglBindAPI(EGL_OPENGL_ES_API);
        result = egl_eglInitialize(eglDisplay, NULL, NULL);
        if (result != EGL_TRUE) {
            LOGD("LIBGL: Unable to initialize EGL display.\n");
            return 0;
        }
        eglInitialized = true;
    }

	// select a configuration
    int configsFound;
    static EGLConfig pbufConfigs[1];
    result = egl_eglChooseConfig(eglDisplay, configAttribs, pbufConfigs, 1, &configsFound);

    CheckEGLErrors();
    if (result != EGL_TRUE || configsFound == 0) {
        LOGD("LIBGL: No EGL configs found.\n");
        return 0;
    }

	// now, create the PBufferSurface
    (*Surface) = egl_eglCreatePbufferSurface(eglDisplay, pbufConfigs[0], egl_attribs);

    if((*Surface)==EGL_NO_SURFACE) {
        LOGD("LIBGL: Error creating PBuffer\n");
        return 0;
    }

    (*Context) = egl_eglCreateContext(eglDisplay, pbufConfigs[0], EGL_NO_CONTEXT, egl_context_attrib);

    return 1;
}

EXPORT GLXPbuffer glXCreatePbuffer(Display * dpy, GLXFBConfig config, const int * attrib_list) {
    //printf("glXCreatePbuffer(%p, %p, %p)\n", dpy, config, attrib_list);
    LOAD_EGL(eglQuerySurface);

	EGLSurface Surface = 0;
    EGLContext Context = 0;
	//let's create a PBuffer attributes
	EGLint egl_attribs[128];	// should be enough
	int i = 0;
	if(attrib_list) {
		int j = 0;
		while(attrib_list[j]!=0) {
			switch(attrib_list[j++]) {
				case GLX_PBUFFER_WIDTH:
					egl_attribs[i++] = EGL_WIDTH;
					egl_attribs[i++] = attrib_list[j++];
					break;
				case GLX_PBUFFER_HEIGHT:
					egl_attribs[i++] = EGL_HEIGHT;
					egl_attribs[i++] = attrib_list[j++];
					break;
				case GLX_LARGEST_PBUFFER:
					egl_attribs[i++] = EGL_LARGEST_PBUFFER;
                    egl_attribs[i++] = (attrib_list[j++])?EGL_TRUE:EGL_FALSE;
					break;
				case GLX_PRESERVED_CONTENTS:
                    j++;
					// ignore this one
					break;
				//nothing, ignore unknown attribs
			}
		}
	}
    egl_attribs[i++] = EGL_NONE;

    // Check that the config is for PBuffer
    if(config->drawableType&GLX_PBUFFER_BIT!=GLX_PBUFFER_BIT)
        return 0;


    if(createPBuffer(dpy, egl_attribs, &Surface, &Context, config->redBits, config->greenBits, config->blueBits, config->alphaBits, config->nMultiSampleBuffers, config->multiSampleSize)==0) {
        return 0;
    }

    int Width, Height;

    egl_eglQuerySurface(eglDisplay,Surface,EGL_WIDTH,&Width);
    egl_eglQuerySurface(eglDisplay,Surface,EGL_HEIGHT,&Height);

    return addPBuffer(Surface, Width, Height, Context);
}

GLXPbuffer addPixBuffer(Display *dpy, EGLSurface surface, int Width, int Height, EGLContext Context, Pixmap pixmap, int depth, int emulated)
{
    if(pbufferlist_cap<=pbufferlist_size) {
        pbufferlist_cap += 4;
        pbufferlist = (GLXPbuffer*)realloc(pbufferlist, sizeof(GLXPbuffer)*pbufferlist_cap);
        pbuffersize = (glx_buffSize*)realloc(pbuffersize, sizeof(glx_buffSize)*pbufferlist_cap);
    }
    pbufferlist[pbufferlist_size] = (GLXPbuffer)pixmap;
    pbuffersize[pbufferlist_size].Width = Width;
    pbuffersize[pbufferlist_size].Height = Height;
    pbuffersize[pbufferlist_size].Context = Context;
    pbuffersize[pbufferlist_size].Surface = surface;
    pbuffersize[pbufferlist_size].Depth = depth;
    pbuffersize[pbufferlist_size].dpy = dpy;
    pbuffersize[pbufferlist_size].gc = (emulated)?XCreateGC(dpy, pixmap, 0, NULL):NULL;
    pbuffersize[pbufferlist_size].frame = NULL;

    pbuffersize[pbufferlist_size].Type = 2+emulated;    //2 = pixmap, 3 = emulated pixmap, 4 = emulated win
    return pbufferlist[pbufferlist_size++];
}
void delPixBuffer(int j)
{
    LOAD_EGL(eglDestroyContext);
    if(pbuffersize[j].gc)
        XFree(pbuffersize[j].gc);
    if(pbuffersize[j].frame) {
        XDestroyImage(pbuffersize[j].frame);
    }
    pbufferlist[j] = 0;
    pbuffersize[j].Width = 0;
    pbuffersize[j].Height = 0;
    pbuffersize[j].Depth = 0;
    pbuffersize[j].dpy = 0;
    pbuffersize[j].gc = 0;
    pbuffersize[j].Surface = 0;
    egl_eglDestroyContext(eglDisplay, pbuffersize[j].Context);
    // should pack, but I think it's useless for common use 
}

int createPixBuffer(Display * dpy, int bpp, const EGLint * egl_attribs, NativePixmapType nativepixmap, EGLSurface* Surface, EGLContext* Context) {
    LOAD_EGL(eglChooseConfig);
    LOAD_EGL(eglCreatePixmapSurface);
    LOAD_EGL(eglInitialize);
    LOAD_EGL(eglBindAPI);
    LOAD_EGL(eglCreateContext);

    EGLint configAttribs[] = {
        EGL_RED_SIZE, (bpp>16)?8:5,
        EGL_GREEN_SIZE, (bpp==15)?5:(bpp>16)?8:6,
        EGL_BLUE_SIZE, (bpp>16)?8:5,
        EGL_ALPHA_SIZE, (bpp==32)?8:0,
        EGL_DEPTH_SIZE, 1,      // some depth
        EGL_STENCIL_SIZE, 1,    // some stencil too
        EGL_SURFACE_TYPE, EGL_PIXMAP_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES_BIT,
        EGL_NONE
    };

    // Init what need to be done
    EGLBoolean result;
    if (eglDisplay == NULL || eglDisplay == EGL_NO_DISPLAY) {
        init_display((g_usefb)?g_display:dpy);
        if (eglDisplay == EGL_NO_DISPLAY) {
            LOGE("LIBGL: Unable to create EGL display.\n");
            return 0;
        }
    }

    // first time?
    if (eglInitialized == false) {
        egl_eglBindAPI(EGL_OPENGL_ES_API);
        result = egl_eglInitialize(eglDisplay, NULL, NULL);
        if (result != EGL_TRUE) {
            LOGE("LIBGL: Unable to initialize EGL display.\n");
            return 0;
        }
        eglInitialized = true;
    }

	// select a configuration
    int configsFound;
    static EGLConfig pixbufConfigs[1];
    result = egl_eglChooseConfig(eglDisplay, configAttribs, pixbufConfigs, 1, &configsFound);

    CheckEGLErrors();
    if (result != EGL_TRUE || configsFound == 0) {
        LOGE("LIBGL: No EGL configs found.\n");
        return 0;
    }

	// now, create the PBufferSurface
    (*Surface) = egl_eglCreatePixmapSurface(eglDisplay, pixbufConfigs[0], nativepixmap,egl_attribs);

    if((*Surface)==EGL_NO_SURFACE) {
        LOGE("LIBGL: Error creating PBuffer\n");
        return 0;
    }

    (*Context) = egl_eglCreateContext(eglDisplay, pixbufConfigs[0], EGL_NO_CONTEXT, egl_context_attrib);

    return 1;
}

EXPORT GLXPixmap glXCreateGLXPixmap(Display *display, XVisualInfo * visual, Pixmap pixmap) {
    //LOGD("glXCreateGLXPixmap(%p, %p, %p)\n", display, visual, pixmap);
    LOAD_EGL(eglQuerySurface);

	EGLSurface Surface = 0;
    EGLContext Context = 0;
    //first, analyse PixMap to get it's dimensions and color depth...
    unsigned int width, height, border, depth;
    Window root;
    int x, y;
    int emulated = 0;
    XGetGeometry(display, pixmap, &root, &x, &y, &width, &height, &border, &depth);
    // let's try to create a PixmapSurface directly
    if(g_usefb || createPixBuffer(display, depth, NULL, (NativePixmapType)pixmap, &Surface, &Context)==0) {
        // fail, so emulate with a PBuffer
        SHUT(LOGE("LIBGL: Pixmap creation failed, trying PBuffer instead\n"));
        //let's create a PixBuffer attributes
        EGLint egl_attribs[10];	// should be enough
        int i = 0;
        egl_attribs[i++] = EGL_WIDTH;
        egl_attribs[i++] = width;
        egl_attribs[i++] = EGL_HEIGHT;
        egl_attribs[i++] = height;
        egl_attribs[i++] = EGL_NONE;

        if(createPBuffer(display, egl_attribs, &Surface, &Context, (depth>16)?8:5, (depth==15)?5:(depth>16)?8:6, (depth>16)?8:5, (depth==32)?8:0, 0, 0)==0) {
            // fail too, abort
            SHUT(LOGE("LIBGL: PBuffer creation failed too\n"));
            return 0;
        }
        emulated = 1;

    }
    int Width, Height;

    egl_eglQuerySurface(eglDisplay,Surface,EGL_WIDTH,&Width);
    egl_eglQuerySurface(eglDisplay,Surface,EGL_HEIGHT,&Height);

    return addPixBuffer(display, Surface, Width, Height, Context, pixmap, depth, emulated);
}

GLXPixmap glXCreatePixmap(Display * dpy, GLXFBConfig config, Pixmap pixmap, const int * attrib_list) {
//    LOGD("glXCreatePixmap(%p, %p, %p, %p)\n", dpy, config, pixmap, attrib_list);
    // Check that the config is for PBuffer
    if(config->drawableType&GLX_PIXMAP_BIT!=GLX_PIXMAP_BIT)
        return 0;
    
    return glXCreateGLXPixmap(dpy, NULL, pixmap);
}


EXPORT void glXDestroyGLXPixmap(Display *display, void *pixmap) {
//LOGD("glXDestroyGLXPixmap(%p, %p)\n", display, pixmap);
    LOAD_EGL(eglDestroySurface);
    int j=0;
    while(j<pbufferlist_size || pbufferlist[j]==(GLXPbuffer)pixmap) j++;
    if(j==pbufferlist_size)
        return;
        // delete de Surface
    EGLSurface surface = pbuffersize[j].Surface;// (EGLSurface)pbufferlist[j];
    egl_eglDestroySurface(display, surface);

    delPixBuffer(j);
}

EXPORT void glXDestroyPixmap(Display *display, void *pixmap) {
    glXDestroyGLXPixmap(display, pixmap);
}


void BlitEmulatedPixmap() {
    if(!glstate->emulatedPixmap)
        return;

    Pixmap drawable = (Pixmap)pbufferlist[glstate->emulatedPixmap-1];

    glx_buffSize *buff = &pbuffersize[glstate->emulatedPixmap-1]; 

    int Width = buff->Width;
    int Height = buff->Height;
    int Depth = buff->Depth;
    Display *dpy = buff->dpy;
    GC gc = buff->gc;
    // the reverse stuff can probably be better!
    int reverse = buff->Type==4?1:0;
    int sbuf = Width * Height * (Depth==16?2:4);

    // create things if needed
    if(!buff->frame) {
        buff->frame = XCreateImage(dpy, NULL /*visual*/, Depth, ZPixmap, 0, malloc(Width*(Height+reverse)*(Depth==16?2:4)), Width, Height, (Depth==16)?16:32, 0);
    }

    XImage* frame = buff->frame;
    if (!frame) {
        return;
    }
    uintptr_t pix=(uintptr_t)frame->data;

    // grab framebuffer
#ifdef PANDORA
    LOAD_GLES(glReadPixels);
    if(Depth==16) {
        void* tmp = malloc(Width*Height*4);
        gles_glReadPixels(0, 0, Width, Height, GL_BGRA, GL_UNSIGNED_BYTE, tmp);
        if(reverse) {
            int stride = Width * 2;
            uintptr_t src_pos = (uintptr_t)tmp;
            uintptr_t dst_pos = (uintptr_t)pix+sbuf-stride;
            for (int i = 0; i < Height; i++) {
                for (int j = 0; j < Width; j++) {
                    *(GLushort*)dst_pos = ((GLushort)(((char*)src_pos)[0]&0xf8)>>(3)) | ((GLushort)(((char*)src_pos)[1]&0xfc)<<(5-2)) | ((GLushort)(((char*)src_pos)[2]&0xf8)<<(11-3));
                    src_pos += 4;
                    dst_pos += 2;
                }
                dst_pos -= 2*stride;
            }
        } else
            pixel_convert(tmp, (void**)&pix, Width, Height, GL_BGRA, GL_UNSIGNED_BYTE, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, 0);
        free(tmp);
    } else {
        gles_glReadPixels(0, 0, Width, Height, GL_BGRA, GL_UNSIGNED_BYTE, (void*)pix);
        if(reverse) {
            int stride = Width * 4;
            uintptr_t end=pix+sbuf-stride;
            uintptr_t beg=pix;
            void* const tmp = (void*)(pix+sbuf);
            for (; beg < end; beg+=stride, end-=stride) {
                memcpy(tmp, (void*)end, stride);
                memcpy((void*)end, (void*)beg, stride);
                memcpy((void*)beg, tmp, stride);
            }
        }
    }
#else
    glshim_glReadPixels(0, 0, Width, Height, (Depth==16)?GL_RGB:GL_BGRA, (Depth==16)?GL_UNSIGNED_SHORT_5_6_5:GL_UNSIGNED_BYTE, (void*)pix);
    if(reverse) {
        int stride = Width * (Depth==16?2:4);
        uintptr_t end=pix+sbuf-stride;
        uintptr_t beg=pix;
        void* const tmp = (void*)(pix+sbuf);
        for (; beg < end; beg+=stride, end-=stride) {
            memcpy(tmp, (void*)end, stride);
            memcpy((void*)end, (void*)beg, stride);
            memcpy((void*)beg, tmp, stride);
        }
    }
#endif
    // blit
    XPutImage(dpy, drawable, gc, frame, 0, 0, 0, 0, Width, Height);

    // grab the size of the drawable if it has changed
    if(reverse) {
        // Get Window size and all...
        unsigned int width, height, border, depth;
        Window root;
        int x, y;
        XGetGeometry(dpy, drawable, &root, &x, &y, &width, &height, &border, &depth);
        if(width!=Width || height!=Height || depth!=Depth) {
            LOAD_EGL(eglCreatePbufferSurface);
            LOAD_EGL(eglDestroySurface);
            LOAD_EGL(eglMakeCurrent);
            LOAD_EGL(eglChooseConfig);
            // destroy old stuff
            XSync(dpy, False);  // synch seems needed before the DestroyImage...
            XDestroyImage(frame);
            buff->frame = 0;
            

            //let's create a PBuffer attributes
            EGLint egl_attribs[10];	// should be enough
            int i = 0;
            egl_attribs[i++] = EGL_WIDTH;
            egl_attribs[i++] = width;
            egl_attribs[i++] = EGL_HEIGHT;
            egl_attribs[i++] = height;
            egl_attribs[i++] = EGL_NONE;

            EGLint configAttribs[] = {
                EGL_RED_SIZE, (Depth>16)?8:5,
                EGL_GREEN_SIZE, (Depth==15)?5:(Depth>16)?8:6,
                EGL_BLUE_SIZE, (depth>16)?8:5,
                EGL_ALPHA_SIZE, (depth==32)?8:0,
                EGL_DEPTH_SIZE, 1,
                EGL_STENCIL_SIZE, 1,
                EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
                EGL_RENDERABLE_TYPE, EGL_OPENGL_ES_BIT,
                EGL_NONE
            };

            int configsFound;
            static EGLConfig pbufConfigs[1];
            egl_eglChooseConfig(eglDisplay, configAttribs, pbufConfigs, 1, &configsFound);

            EGLSurface Surface = egl_eglCreatePbufferSurface(eglDisplay, pbufConfigs[0], egl_attribs);

            buff->glxcontext->eglSurface = Surface;

            egl_eglMakeCurrent(eglDisplay, Surface, Surface, eglContext);

            egl_eglDestroySurface(eglDisplay, buff->Surface);
            buff->Surface = Surface;
            buff->Width = width;
            buff->Height = height;
            buff->Depth = depth;
        }
    }
}

#endif //ANDROID
