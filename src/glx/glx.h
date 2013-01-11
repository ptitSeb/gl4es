#include <EGL/egl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <string.h>

#include "gl.h"

typedef struct {
    Display *currentDpy;
    unsigned char isDirect;
    int currentWritable;
    int currentReadable;
    XID xid;
} GLXContext;

#define GLX_VENDOR              1
#define GLX_VERSION             2
#define GLX_EXTENSIONS          3

GLXContext glXCreateContext(Display *dpy,
                            XVisualInfo *visual,
                            GLXContext shareList,
                            Bool direct);

Bool glXMakeCurrent(Display *display, int drawable, GLXContext context);
Bool glXQueryExtension(Display *display, int *errorBase, int *eventBase);
Bool glXQueryVersion(Display *display, int *major, int *minor);
const char *glXGetClientString(Display *display, int name);
const char *glXQueryExtensionsString(Display *display, int screen);
Display *glXGetCurrentDisplay();
int glXGetConfig(Display *display, XVisualInfo *visual, int attribute, int *value);
void glXDestroyContext(Display *display, GLXContext ctx);
void glXSwapBuffers(Display *display, int drawable);
XVisualInfo *glXChooseVisual(Display *display, int screen, int *attributes);
