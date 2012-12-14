#include <glesglx.h>

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
    printf("glXCreateContext\n");
    GLXContext fake = {0, 0, NULL, 0, 0};
    display = XOpenDisplay(NULL);

    // make an egl context here...
    EGLBoolean result;
    if (!eglDisplay || eglDisplay == EGL_NO_DISPLAY) {
        eglDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
        if (eglDisplay == EGL_NO_DISPLAY) {
            printf("Unable to create EGL display.\n");
            return fake;
        }
    }

    // first time?
    if (eglInitialized == false) {
        result = eglInitialize(eglDisplay, NULL, NULL);
        if (result != EGL_TRUE) {
            printf("Unable to initialize EGL display.\n");
            return fake;
        }
        eglInitialized = true;
    }

    EGLint eglAttrs[] = {
        EGL_RED_SIZE, 5,
        EGL_GREEN_SIZE, 6,
        EGL_BLUE_SIZE, 5,
        EGL_DEPTH_SIZE, 16,
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES_BIT,
        EGL_NONE,
    };

    int configsFound;
    EGLConfig *configs = malloc(sizeof(EGLConfig) * maxConfigs);
    result = eglChooseConfig(eglDisplay, eglAttrs, configs, maxConfigs, &configsFound);
    printf("eglChooseConfig\n");
    CheckEGLErrors();
    if (result != EGL_TRUE || configsFound == 0) {
        printf("No EGL configs found.\n");
        return fake;
    }
    eglConfig = configs[0];
    eglContext = eglCreateContext(display, eglConfig, NULL, eglAttrs);
    CheckEGLErrors();

    // need to return a glx context pointing at it
    return (GLXContext){display, true, 0, 0, 0};;
}

void glXDestroyContext(Display *display, GLXContext ctx) {
    printf("glXDestroyContext\n");
    display = XOpenDisplay(NULL);
    if (eglContext) {
        EGLBoolean result = eglDestroyContext(display, eglContext);
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
    printf("glXChooseVisual\n");
    XVisualInfo *visual = (XVisualInfo *)malloc(sizeof(XVisualInfo));
    // apparently can't trust the Display I'm passed?
    display = XOpenDisplay(NULL);
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
    printf("glXMakeCurrent\n");
    eglSurface = eglCreateWindowSurface(eglDisplay, eglConfig, drawable, NULL);
    CheckEGLErrors();

    if (eglContext == EGL_NO_CONTEXT) {
        printf("no context\n");
    }
    EGLBoolean result = eglMakeCurrent(eglDisplay, eglSurface, eglSurface, eglContext);
    CheckEGLErrors();
    if (result) {
        printf("seems to have worked.\n");
        return true;
    }
    return false;
}

void glXSwapBuffers(Display *display,
                    int drawable) {
    eglSwapBuffers(eglDisplay, eglSurface);
}

int glXGetConfig(Display *display,
                 XVisualInfo *visual,
                 int attribute,
                 int *value) {
    printf("glXGetConfig\n");
    return 0;
}

const char *glXQueryExtensionsString(Display *display,
                                     int screen) {
    printf("glXQueryExtensionsString\n");
    return 0;
}
void glXSwapIntervalSGI() {}
void glXSwapIntervalMESA() {}
// glXCreatePixmap()?