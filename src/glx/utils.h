#ifndef UTILS_H
#define UTILS_H

#ifndef ANDROID
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#endif //ANDROID
#include <stdio.h>
#include <string.h>

#include "../gl/gl.h"
#ifndef ANDROID
void
fill_bitmap(Display * dpy, Window win, GC gc,
            unsigned int width, unsigned int height,
            int x0, int y0, unsigned int c, GLubyte * bitmap);

XCharStruct *
isvalid(XFontStruct * fs, int which);
#endif //ANDROID
#endif