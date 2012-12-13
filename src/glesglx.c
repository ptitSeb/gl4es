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

    EGLConfig *configs = malloc(sizeof(EGLConfig) * maxConfigs);
    int configsFound;
    eglChooseConfig(display, attributes, configs, maxConfigs, &configsFound);

    XVisualInfo *visuals = (XVisualInfo *)malloc(sizeof(XVisualInfo) * configsFound);
    for (int i = 0; i < configsFound; i++) {
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
