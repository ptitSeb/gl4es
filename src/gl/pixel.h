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

bool pixel_convert(const GLvoid *src, GLvoid **dst,
                   GLuint width, GLuint height,
                   GLenum src_format, GLenum src_type,
                   GLenum dst_format, GLenum dst_type);

bool pixel_scale(const GLvoid *src, GLvoid **dst,
                  GLuint width, GLuint height,
                  GLfloat ratio,
                  GLenum format, GLenum type);

bool pixel_to_ppm(const GLvoid *pixels,
                  GLuint width, GLuint height,
                  GLenum format, GLenum type);

#endif
