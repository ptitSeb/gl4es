#include <GLES/gl.h>
#include "glx.h"

#define maxConfigs 20

bool eglInitialized = false;
EGLDisplay eglDisplay;
EGLSurface eglSurface;
EGLConfig eglConfig;

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

// hmm...
EGLContext eglContext;
Display *xDisplay;

GLXContext glXCreateContext(Display *display,
                            XVisualInfo *visual,
                            GLXContext shareList,
                            Bool isDirect) {

    GLXContext fake = {NULL, 0, 0, 0, 0};
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
        eglDisplay = eglGetDisplay(xDisplay);
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
    if (eglConfig) free(eglConfig);
    eglConfig = malloc(sizeof(EGLConfig));
    memcpy(&eglConfig, configs, sizeof(EGLConfig));
    free(configs);

    eglContext = eglCreateContext(eglDisplay, eglConfig, NULL, NULL);
    CheckEGLErrors();

    // need to return a glx context pointing at it
    return (GLXContext){xDisplay, true, 0, 0, 1};
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

    if (!drawable) {
        return false;
    }

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
    eglSwapBuffers(eglDisplay, eglSurface);
    CheckEGLErrors();
}

int glXGetConfig(Display *display,
                 XVisualInfo *visual,
                 int attribute,
                 int *value) {
    printf("glXGetConfig()\n");
    return 0;
}

const char *glXQueryExtensionsString(Display *display, int screen) {
    return "";
}

Bool glXQueryExtension(Display *display, int *errorBase, int *eventBase) {
    // TODO: figure out which extensions we support?
    return false;
}

Bool glXQueryVersion(Display *display, int *major, int *minor) {
    // TODO: figure out which version we want to pretend to implement
    *major = 1;
    *minor = 2;
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

void glXSwapIntervalSGI() {}
void glXSwapIntervalMESA() {}
// glXCreatePixmap()?
