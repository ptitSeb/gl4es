#include <glesglx.h>

GLXContext glXCreateContext(Display *display,
                            XVisualInfo *visual,
                            GLXContext shareList,
                            Bool isDirect) {
    // make an egl context here... need to return a glx context kinda pointing at it
    // EGLContext egl = eglCreateContext(display, config, shareList)
    return;
}

void glXDestroyContext(Display *display, GLXContext ctx) {
    return;
}

void glXGetProcAddressARB() {}
void glXChooseVisual() {}
void glXMakeCurrent() {}
void glXSwapBuffers() {}
void glXGetConfig() {}
void glXQueryExtensionsString() {}
void glXSwapIntervalSGI() {}
void glXSwapIntervalMESA() {}
