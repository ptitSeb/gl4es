#include <glesglx.h>
#include <GLES/gl.h>

#define maxConfigs 20

bool eglInitialized = false;
EGLDisplay eglDisplay;
EGLSurface eglSurface;
EGLConfig eglConfig;

// hmm...
EGLContext eglContext;

GLXContext glXCreateContext(Display *display,
                            XVisualInfo *visual,
                            GLXContext shareList,
                            Bool isDirect) {
    display = XOpenDisplay(NULL);

    printf("glXCreateContext()\n");
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
        eglDisplay = eglGetDisplay(display);
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
    eglConfig = configs[0];

    eglContext = eglCreateContext(eglDisplay, eglConfig, NULL, NULL);
    CheckEGLErrors();

    // need to return a glx context pointing at it
    return (GLXContext){display, true, 0, 0, 1};;
}

void glXDestroyContext(Display *display, GLXContext ctx) {
    printf("glXDestroyContext()\n");
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

XVisualInfo *glXChooseVisual(Display *display,
                             int screen,
                             int *attributes) {
    printf("glXChooseVisual()\n");
    // apparently can't trust the Display I'm passed?
    display = XOpenDisplay(NULL);
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
    printf("glXMakeCurrent()\n");
    
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
    printf("glxSwapBuffers()\n");
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

const char *glXQueryExtensionsString(Display *display,
                                     int screen) {
    return "";
}
void glXSwapIntervalSGI() {}
void glXSwapIntervalMESA() {}
// glXCreatePixmap()?
