#include <glesglx.h>

GLXContext glXCreateContext(Display *display,
                            XVisualInfo *visual,
                            GLXContext shareList,
                            Bool isDirect) {
    // make an egl context here
    return NULL;
}

void glXDestroyContext(Display *display, GLXContext ctx) {
    return;
}