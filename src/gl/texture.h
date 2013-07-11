#include "gl.h"

#ifndef GL_TEXTURE_H
#define GL_TEXTURE_H

void glTexImage2D(GLenum target, GLint level, GLint internalFormat,
                  GLsizei width, GLsizei height, GLint border,
                  GLenum format, GLenum type, const GLvoid *data);

void glTexImage1D(GLenum target, GLint level, GLint internalFormat,
                  GLsizei width, GLint border,
                  GLenum format, GLenum type, const GLvoid *data);

void glBindTexture(GLenum target, GLuint texture);
void glDeleteTextures(GLsizei n, const GLuint * textures);
void glTexParameteri(GLenum target, GLenum pname, GLint param);

void texture_rect_arb_convert(GLfloat *tex, GLsizei len,
                              GLsizei width, GLsizei height);
int npot(int n);

typedef struct {
    GLuint texture;
    GLenum target;
    GLsizei width;
    GLsizei height;
    GLboolean uploaded;
} GLtexture;

KHASH_MAP_INIT_INT(tex, GLtexture *);

static inline GLenum map_tex_target(GLenum target) {
    switch (target) {
        case GL_TEXTURE_1D:
        case GL_TEXTURE_RECTANGLE_ARB:
            target = GL_TEXTURE_2D;
            break;
    }
    return target;
}

#endif
