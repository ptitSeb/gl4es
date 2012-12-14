#include <EGL/egl.h>
#include <stdbool.h>
#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    Display *currentDpy;
    unsigned char isDirect;
    EGLContext *egl;
    int currentReadable;
    XID xid;
} GLXContext;

GLXContext glXCreateContext(Display *dpy,
                            XVisualInfo *visual,
                            GLXContext shareList,
                            Bool direct);

void glXDestroyContext(Display *display, GLXContext ctx);
XVisualInfo *glXChooseVisual(Display *display, int screen, int *attributes);
Bool glXMakeCurrent(Display *display, int drawable, GLXContext context);
void glXSwapBuffers(Display *display, int drawable);
int glXGetConfig(Display *display, XVisualInfo *visual, int attribute, int *value);
const char *glXQueryExtensionsString(Display *display, int screen);

int8_t CheckEGLErrors() {
    EGLenum error;
    char *errortext;

    error = eglGetError();

    if (error != EGL_SUCCESS && error != 0)
    {
        switch (error)
        {
            case EGL_NOT_INITIALIZED:     errortext = "EGL_NOT_INITIALIZED"; break;
            case EGL_BAD_ACCESS:          errortext = "EGL_BAD_ACCESS"; break;
            case EGL_BAD_ALLOC:           errortext = "EGL_BAD_ALLOC"; break;
            case EGL_BAD_ATTRIBUTE:       errortext = "EGL_BAD_ATTRIBUTE"; break;
            case EGL_BAD_CONTEXT:         errortext = "EGL_BAD_CONTEXT"; break;
            case EGL_BAD_CONFIG:          errortext = "EGL_BAD_CONFIG"; break;
            case EGL_BAD_CURRENT_SURFACE: errortext = "EGL_BAD_CURRENT_SURFACE"; break;
            case EGL_BAD_DISPLAY:         errortext = "EGL_BAD_DISPLAY"; break;
            case EGL_BAD_SURFACE:         errortext = "EGL_BAD_SURFACE"; break;
            case EGL_BAD_MATCH:           errortext = "EGL_BAD_MATCH"; break;
            case EGL_BAD_PARAMETER:       errortext = "EGL_BAD_PARAMETER"; break;
            case EGL_BAD_NATIVE_PIXMAP:   errortext = "EGL_BAD_NATIVE_PIXMAP"; break;
            case EGL_BAD_NATIVE_WINDOW:   errortext = "EGL_BAD_NATIVE_WINDOW"; break;
            default:                      errortext = "unknown"; break;
        }

        printf("ERROR: EGL Error detected: %s (0x%X)\n", errortext, error);
        return 1;
    }

    return 0;
}
