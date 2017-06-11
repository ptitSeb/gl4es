#ifndef _BLIT_H_
#define _BLIT_H_

#include "gl.h"

#define BLIT_ALPHA      0
#define BLIT_OPAQUE     1
#define BLIT_COLOR      2

void gl4es_blitTexture(GLuint texture, 
    float width, float height, 
    float nwidth, float nheight, 
    float zoomx, float zoomy, 
    float vpwidth, float vpheight, 
    float x, float y, int mode);

#endif