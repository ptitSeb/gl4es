#ifndef UTILS_H
#define UTILS_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <string.h>

#include "../gl/gl.h"

void
fill_bitmap(Display * dpy, Window win, GC gc,
            unsigned int width, unsigned int height,
            int x0, int y0, unsigned int c, GLubyte * bitmap);

XCharStruct *
isvalid(XFontStruct * fs, int which);

#endif