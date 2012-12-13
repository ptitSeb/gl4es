#include <glesglx.h>
#include <stdio.h>

#define maxConfigs 20

GLXContext glXCreateContext(Display *display,
                            XVisualInfo *visual,
                            GLXContext shareList,
                            Bool isDirect) {
    printf("glXCreateContext\n");
    // make an egl context here... need to return a glx context kinda pointing at it
    // EGLContext egl = eglCreateContext(display, config, shareList)
    return;
}

void glXDestroyContext(Display *display, GLXContext ctx) {
    printf("glXDestroyContext\n");
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
    int configsFound = 0;
    EGLBoolean result;

    EGLConfig *configs = malloc(sizeof(EGLConfig) * maxConfigs);
    result = eglChooseConfig(display, attributes, configs, maxConfigs, &configsFound);
    if (result != EGL_TRUE || configsFound == 0) {
        printf("No EGL configs found.\n");
        return NULL;
    }
    printf("%i configs found\n", configsFound);

    XVisualInfo *visuals = (XVisualInfo *)malloc(sizeof(XVisualInfo) * configsFound);
    for (int i = 0; i < configsFound; i++) {
        printf("config %i\n", i);
        XVisualInfo *visual = (visuals+i);
        EGLConfig *config = (configs+i);

        // maybe bad if this is ever called more than once and cached
        visual->visualid = i;
        visual->screen = screen;

        // http://tronche.com/gui/x/xlib/window/visual-types.html
        // hope this is good enough :)
        eglGetConfigAttrib(display, config, EGL_DEPTH_SIZE, &visual->depth);
        visual->class = TrueColor;
    }

    printf("exiting function\n");
    return visuals;
}

Bool glXMakeCurrent(Display *display,
                    int  drawable,
                    GLXContext context) {
    printf("glXMakeCurrent\n");
    return false;
}

void glXSwapBuffers(Display *display,
                    int drawable) {
    printf("glXSwapBuffers\n");
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
