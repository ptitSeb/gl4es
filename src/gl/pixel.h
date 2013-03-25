#include "gl.h"

#ifndef PIXEL_H
#define PIXEL_H

typedef struct {
    GLenum type;
    GLubyte red, green, blue, alpha;
} ColorLayout;

typedef struct {
    GLfloat r, g, b, a;
} Pixel;

bool pixels_to_pixels(const GLvoid *src, GLvoid **dst,
                      GLuint width, GLuint height,
                      GLenum src_format, GLenum src_type,
                      GLenum dst_format, GLenum dst_type);

#endif
