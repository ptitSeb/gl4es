#ifndef UTILS_H
#define UTILS_H

#ifndef NOX11
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#endif //NOX11
#include <stdio.h>
#include <string.h>

#include "../gl/gl.h"
#ifndef NOX11
void
fill_bitmap(Display * dpy, Window win, GC gc,
            unsigned int width, unsigned int height,
            int x0, int y0, unsigned int c, GLubyte * bitmap);

XCharStruct *
isvalid(XFontStruct * fs, int which);
#endif //NOX11
#endif