#include "gl.h"

#ifndef GL_ARRAY_H
#define GL_ARRAY_H

#include "state.h"

GLvoid *copy_gl_array(const GLvoid *src,
                      GLenum from, GLsizei width, GLsizei stride,
                      GLenum to, GLsizei to_width, GLsizei skip, GLsizei count);

GLvoid *copy_gl_array_convert(const GLvoid *src,
					  GLenum from, GLsizei width, GLsizei stride,
					  GLenum to, GLsizei to_width, GLsizei skip, GLsizei count, GLvoid* filler);
	
GLvoid *copy_gl_pointer(pointer_state_t *ptr, GLsizei width, GLsizei skip, GLsizei count, glbuffer_t *buff);
GLvoid *copy_gl_pointer_color(pointer_state_t *ptr, GLsizei width, GLsizei skip, GLsizei count, glbuffer_t *buff);
GLvoid *copy_gl_pointer_bytecolor(pointer_state_t *ptr, GLsizei width, GLsizei skip, GLsizei count, glbuffer_t *buff);
GLvoid *copy_gl_pointer_raw(pointer_state_t *ptr, GLsizei width, GLsizei skip, GLsizei count, glbuffer_t *buff);
GLvoid *copy_gl_pointer_tex(pointer_state_t *ptr, GLsizei width, GLsizei skip, GLsizei count, glbuffer_t *buff);
GLfloat *gl_pointer_index(pointer_state_t *ptr, GLint index);
GLfloat *copy_eval_double(GLenum target, GLint ustride, GLint uorder, GLint vstride, GLint vorder, const GLdouble *points);
void normalize_indices(GLushort *indices, GLsizei *max, GLsizei *min, GLsizei count);
void getminmax_indices(GLushort *indices, GLsizei *max, GLsizei *min, GLsizei count);
#endif
