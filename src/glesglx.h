#include <EGL/egl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

typedef struct {
    Display *currentDpy;
    unsigned char isDirect;
    int currentDrawable;
    int currentReadable;
    XID xid;
} GLXContext;

GLXContext glXCreateContext(Display *dpy,
                            XVisualInfo *visual,
                            GLXContext shareList,
                            Bool direct);

void glXDestroyContext(Display *display, GLXContext ctx);
