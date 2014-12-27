#include "gl.h"

#ifndef PIXEL_H
#define PIXEL_H

typedef struct {
    GLenum type;
    GLint red, green, blue, alpha;
} colorlayout_t;

typedef struct {
    GLfloat r, g, b, a;
} pixel_t;

bool pixel_convert(const GLvoid *src, GLvoid **dst,
                   GLuint width, GLuint height,
                   GLenum src_format, GLenum src_type,
                   GLenum dst_format, GLenum dst_type, GLuint stride);

bool pixel_transform(const GLvoid *src, GLvoid **dst,
                   GLuint width, GLuint height,
                   GLenum src_format, GLenum src_type,
                   const GLfloat *scale, const GLfloat *bias);

bool pixel_scale(const GLvoid *src, GLvoid **dst,
                  GLuint width, GLuint height,
                  GLfloat ratio,
                  GLenum format, GLenum type);

bool pixel_halfscale(const GLvoid *src, GLvoid **dst,
                  GLuint width, GLuint height,
                  GLenum format, GLenum type);

bool pixel_thirdscale(const GLvoid *src, GLvoid **dst,
                  GLuint width, GLuint height,
                  GLenum format, GLenum type);

bool pixel_quarterscale(const GLvoid *src, GLvoid **dst,
                  GLuint width, GLuint height,
                  GLenum format, GLenum type);

bool pixel_to_ppm(const GLvoid *pixels,
                  GLuint width, GLuint height,
                  GLenum format, GLenum type, GLuint name);

#endif
