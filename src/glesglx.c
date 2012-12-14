#include <glesglx.h>

#define maxConfigs 20

bool eglInitialized = false;
EGLDisplay eglDisplay;
EGLSurface eglSurface;
EGLConfig eglConfig;

GLXContext glXCreateContext(Display *display,
                            XVisualInfo *visual,
                            GLXContext shareList,
                            Bool isDirect) {
    printf("glXCreateContext\n");
    GLXContext fake = {0, 0, NULL, 0, 0};
    display = XOpenDisplay(NULL);

    // make an egl context here...
    EGLBoolean result;
    if (!eglDisplay) {
        eglDisplay = eglGetDisplay(display);
        if (eglDisplay == EGL_NO_DISPLAY) {
            printf("Unable to create EGL display.\n");
            return fake;
        }
    }

    // first time?
    if (eglInitialized == false) {
        eglInitialized = true;
        result = eglInitialize(eglDisplay, NULL, NULL);
        if (result != EGL_TRUE) {
            printf("Unable to initialize EGL display.\n");
            return fake;
        }
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
    if (result != EGL_TRUE || configsFound == 0) {
        printf("No EGL configs found.\n");
        return fake;
    }
    eglConfig = configs[0];
    EGLContext egl = eglCreateContext(display, eglConfig, NULL, eglAttrs);

    // need to return a glx context pointing at it
    return (GLXContext){display, true, &egl, 0, 0};;
}

void glXDestroyContext(Display *display, GLXContext ctx) {
    printf("glXDestroyContext\n");
    display = XOpenDisplay(NULL);
    if (ctx.egl != NULL) {
        EGLBoolean result = eglDestroyContext(display, *ctx.egl);
        if (eglSurface != NULL) {
            eglDestroySurface(eglDisplay, eglSurface);
        }

        if (result != EGL_TRUE) {
            printf("Failed to destroy EGL context.\n");
        }
    }
    return;
}

void *glXGetProcAddressARB(const char *name) {
    printf("glXGetProcAddressARB\n");
    return NULL;
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

Bool glXMakeCurrent(Display *display,
                    int drawable,
                    GLXContext context) {
    printf("glXMakeCurrent\n");
    EGLContext *ctx = context.egl;
    eglSurface = eglCreateWindowSurface(eglDisplay, eglConfig, drawable, NULL);
    printf("here\n");
    EGLBoolean result = eglMakeCurrent(eglDisplay, eglSurface, eglSurface, *ctx);
    if (result) {
        printf("seems to have worked.\n");
        return true;
    }
    CheckEGLErrors();
    return false;
}

void glXSwapBuffers(Display *display,
                    int drawable) {
    printf("glXSwapBuffers\n");
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