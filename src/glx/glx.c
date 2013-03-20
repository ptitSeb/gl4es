#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <GLES/gl.h>
#include "glx.h"
#include <sys/time.h>

#define maxConfigs 20

bool eglInitialized = false;
EGLDisplay eglDisplay;
EGLSurface eglSurface;
EGLConfig eglConfig = NULL;

int8_t CheckEGLErrors() {
    EGLenum error;
    char *errortext;

    error = eglGetError();

    if (error != EGL_SUCCESS && error != 0)
    {
        switch (error)
        {
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

        printf("ERROR: EGL Error detected: %s (0x%X)\n", errortext, error);
        return 1;
    }

    return 0;
}

static int get_config_default(int attribute, int *value) {
    switch (attribute) {
        case GLX_USE_GL:
        case GLX_RGBA:
        case GLX_DOUBLEBUFFER:
            *value = 1;
            break;
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
            *value = 5;
            break;
        case GLX_BLUE_SIZE:
            *value = 6;
            break;
        case GLX_ALPHA_SIZE:
            *value = 8;
            break;
        case GLX_DEPTH_SIZE:
            *value = 16;
            break;
        case GLX_STENCIL_SIZE:
        case GLX_ACCUM_RED_SIZE:
        case GLX_ACCUM_GREEN_SIZE:
        case GLX_ACCUM_BLUE_SIZE:
        case GLX_ACCUM_ALPHA_SIZE:
            *value = 0;
            break;
        case GLX_RENDER_TYPE:
            *value = GLX_RGBA_BIT | GLX_COLOR_INDEX_BIT;
            break;
        case GLX_VISUAL_ID:
            *value = 1;
            break;
        case GLX_FBCONFIG_ID:
            *value = 1;
            break;
        case GLX_DRAWABLE_TYPE:
            *value = GLX_WINDOW_BIT;
            break;
        default:
            printf("unknown attrib: %i\n", attribute);
            *value = 0;
            return 1;
    }
    return 0;
}

// hmm...
EGLContext eglContext;
GLXContext glxContext;
Display *xDisplay;

#ifndef FBIO_WAITFORVSYNC
#define FBIO_WAITFORVSYNC _IOW('F', 0x20, __u32)
#endif
static bool g_usefb = false;
static bool g_vsync = false;
static bool g_showfps = false;
static int fbdev = -1;

static void scan_env() {
    #define env(name, global, message)                    \
        char *env_##name = getenv(#name);                 \
        if (env_##name && strcmp(env_##name, "1") == 0) { \
            printf("libGL: " message "\n");               \
            global = true;                                \
        }

    env(LIBGL_FB, g_usefb, "framebuffer output enabled");
    env(LIBGL_VSYNC, g_vsync, "vsync enabled");
    env(LIBGL_FPS, g_showfps, "fps counter enabled");
    if (g_vsync) {
        fbdev = open("/dev/fb0", O_RDONLY);
        if (fbdev < 0) {
            fprintf(stderr, "Could not open /dev/fb0 for vsync.\n");
        }
    }
}

GLXContext glXCreateContext(Display *display,
                            XVisualInfo *visual,
                            GLXContext shareList,
                            Bool isDirect) {

    scan_env();
    GLXContext fake = malloc(sizeof(struct __GLXContextRec));
    if (eglDisplay != NULL) {
        eglMakeCurrent(eglDisplay, NULL, NULL, EGL_NO_CONTEXT);
        if (eglContext != NULL) {
            eglDestroyContext(eglDisplay, eglContext);
            eglContext = NULL;
        }
        if (eglSurface != NULL) {
            eglDestroySurface(eglDisplay, eglSurface);
            eglSurface = NULL;
        }
    }

    // make an egl context here...
    EGLBoolean result;
    if (eglDisplay == NULL || eglDisplay == EGL_NO_DISPLAY) {
        if (xDisplay == NULL) {
            xDisplay = display;
        }
        if (g_usefb) {
            eglDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
        } else {
            eglDisplay = eglGetDisplay(xDisplay);
        }
        if (eglDisplay == EGL_NO_DISPLAY) {
            printf("Unable to create EGL display.\n");
            return fake;
        }
    }

    // first time?
    if (eglInitialized == false) {
        eglBindAPI(EGL_OPENGL_ES_API);
        result = eglInitialize(eglDisplay, NULL, NULL);
        if (result != EGL_TRUE) {
            printf("Unable to initialize EGL display.\n");
            return fake;
        }
        eglInitialized = true;
    }

    EGLint configAttribs[] = {
        EGL_RED_SIZE, 5,
        EGL_GREEN_SIZE, 6,
        EGL_BLUE_SIZE, 5,
        EGL_DEPTH_SIZE, 16,
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES_BIT,
        EGL_NONE
    };

    int configsFound;
    EGLConfig *configs = malloc(sizeof(EGLConfig) * maxConfigs);
    result = eglChooseConfig(eglDisplay, configAttribs, configs, maxConfigs, &configsFound);
    CheckEGLErrors();
    if (result != EGL_TRUE || configsFound == 0) {
        printf("No EGL configs found.\n");
        return fake;
    }
    if (!eglConfig) eglConfig = malloc(sizeof(EGLConfig));
    memcpy(&eglConfig, configs, sizeof(EGLConfig));
    free(configs);

    eglContext = eglCreateContext(eglDisplay, eglConfig, NULL, NULL);
    CheckEGLErrors();

    // need to return a glx context pointing at it
    fake->display = xDisplay;
    fake->direct = true;
    fake->xid = 1;
    return fake;
}

void glXDestroyContext(Display *display, GLXContext ctx) {
    if (eglContext) {
        EGLBoolean result = eglDestroyContext(eglDisplay, eglContext);
        if (eglSurface != NULL) {
            eglDestroySurface(eglDisplay, eglSurface);
        }

        if (result != EGL_TRUE) {
            printf("Failed to destroy EGL context.\n");
        }
        if (fbdev >= 0) {
            fclose(fbdev);
            fbdev = -1;
        }
    }
    return;
}

Display *glXGetCurrentDisplay() {
    if (xDisplay && eglContext) {
        return xDisplay;
    }
    return NULL;
}

XVisualInfo *glXChooseVisual(Display *display,
                             int screen,
                             int *attributes) {

    // apparently can't trust the Display I'm passed?
    if (xDisplay == NULL) {
        xDisplay = display;
    }
    XVisualInfo *visual = (XVisualInfo *)malloc(sizeof(XVisualInfo));
    XMatchVisualInfo(display, screen, 16, TrueColor, visual);
    return visual;
}

/*
EGL_BAD_MATCH is generated if draw or read are not compatible with context
or if context is set to EGL_NO_CONTEXT and draw or read are not set to
EGL_NO_SURFACE, or if draw or read are set to EGL_NO_SURFACE and context is
not set to EGL_NO_CONTEXT.
*/

Bool glXMakeCurrent(Display *display,
                    int drawable,
                    GLXContext context) {

    if (eglDisplay != NULL) {
        eglMakeCurrent(eglDisplay, NULL, NULL, EGL_NO_CONTEXT);
        if (eglSurface != NULL) {
            eglDestroySurface(eglDisplay, eglSurface);
        }
    }

    if (g_usefb)
        drawable = 0;
    eglSurface = eglCreateWindowSurface(eglDisplay, eglConfig, drawable, 0);
    CheckEGLErrors();

    EGLBoolean result = eglMakeCurrent(eglDisplay, eglSurface, eglSurface, eglContext);
    CheckEGLErrors();
    if (result) {
        return true;
    }
    return false;
}

void glXSwapBuffers(Display *display,
                    int drawable) {
    renderRaster();
    if (fbdev >= 0) {
        int arg = 0;
        ioctl(fbdev, FBIO_WAITFORVSYNC, &arg);
    }
    eglSwapBuffers(eglDisplay, eglSurface);
    CheckEGLErrors();

    if (g_showfps) {
        // framerate counter
        static int firstFrame = 0, lastFrame = 0;
        static int frames = 0;
        struct timeval out;
        gettimeofday(&out, NULL);
        frames++;
        if (!firstFrame) {
            lastFrame = firstFrame = out.tv_sec;
        } else if (out.tv_sec > lastFrame) {
            lastFrame = out.tv_sec;
            float fps = frames / (float)(lastFrame - firstFrame);
            printf("fps: %.2f\n", fps);
        }
    }
}

int glXGetConfig(Display *display,
                 XVisualInfo *visual,
                 int attribute,
                 int *value) {
    return get_config_default(attribute, value);
}

const char *glXQueryExtensionsString(Display *display, int screen) {
    return "";
}

const char *glXQueryServerString(Display *display, int screen, int name) {
    return "";
}

Bool glXQueryExtension(Display *display, int *errorBase, int *eventBase) {
    // GLFW queries a null extension and expects true
    if (!errorBase && !eventBase) {
        return true;
    }
    // TODO: figure out which extensions we support?
    return false;
}

Bool glXQueryVersion(Display *display, int *major, int *minor) {
    // TODO: figure out which version we want to pretend to implement
    *major = 1;
    *minor = 2;
    return true;
}

const char *glXGetClientString(Display *display, int name) {
    // TODO: return actual data here
    switch (name) {
        case GLX_VENDOR: break;
        case GLX_VERSION: break;
        case GLX_EXTENSIONS: break;
    }
    return "";
}

// stubs for glfw (GLX 1.3)
GLXContext glXGetCurrentContext() {
    return glxContext;
}

GLXFBConfig *glXChooseFBConfig(Display *display, int screen,
                       const int *attrib_list, int *count) {
    *count = 1;
    GLXFBConfig *configs = malloc(sizeof(GLXFBConfig) * *count);
    return configs;
}

GLXFBConfig *glXGetFBConfigs(Display *display, int screen, int *count) {
    *count = 1;
    GLXFBConfig *configs = malloc(sizeof(GLXFBConfig) * *count);
    return configs;
}

int glXGetFBConfigAttrib(Display *display, GLXFBConfig config, int attribute, int *value) {
    return get_config_default(attribute, value);
}

XVisualInfo *glXGetVisualFromFBConfig(Display *display, GLXFBConfig config) {
    if (xDisplay == NULL) {
        xDisplay = display;
    }
    XVisualInfo *visual = (XVisualInfo *)malloc(sizeof(XVisualInfo));
    XMatchVisualInfo(display, 0, 16, TrueColor, visual); 
    return visual;
}

GLXContext glXCreateNewContext(Display *display, GLXFBConfig config,
                               int render_type, GLXContext share_list,
                               Bool is_direct) {
    return glXCreateContext(display, 0, share_list, is_direct);
}

// misc stubs
void glXCopyContext(Display *display, GLXContext src, GLXContext dst, GLuint mask) {}
void glXCreateGLXPixmap(Display *display, XVisualInfo * visual, Pixmap pixmap) {} // should return GLXPixmap
void glXDestroyGLXPixmap(Display *display, void *pixmap) {} // really wants a GLXpixmap
void glXGetCurrentDrawable() {} // this should actually return GLXDrawable. Good luck.
Bool glXIsDirect(Display * display, GLXContext ctx) {
    return true;
}
void glXUseXFont(Font font, int first, int count, int listBase) {}
void glXWaitGL() {}
void glXWaitX() {}
