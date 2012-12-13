#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <EGL/egl.h>

typedef struct __GLXcontextRec {
    Display *currentDpy;
    GLboolean isDirect;
    int currentDrawable;
    int currentReadable;
    XID xid;
} __GLXcontext;

GLXContext glXCreateContext(Display *dpy,
                            XVisualInfo *Visual,
                            GLXContext ShareList,
                            Bool Direct);

void glXDestroyContext(Display *display, GLXContext *context);