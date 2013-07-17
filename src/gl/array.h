#include "gl.h"

#ifndef GL_ARRAY_H
#define GL_ARRAY_H

#include "state.h"

GLvoid *copy_gl_array(const GLvoid *src,
                      GLenum from, GLsizei width, GLsizei stride,
                      GLenum to, GLsizei to_width, GLsizei count);

GLvoid *copy_gl_pointer(PointerState *ptr, GLsizei width, GLsizei count);
GLfloat *gl_pointer_index(PointerState *ptr, GLint index);
GLfloat *copy_eval_double(GLenum target, GLint ustride, GLint uorder, GLint vstride, GLint vorder, const GLdouble *points);
#endif
