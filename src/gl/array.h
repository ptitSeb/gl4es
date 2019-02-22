#ifndef _GL4ES_ARRAY_H_
#define _GL4ES_ARRAY_H_

#include "buffers.h"
#include "gles.h"

GLvoid *copy_gl_array(const GLvoid *src,
                      GLenum from, GLsizei width, GLsizei stride,
                      GLenum to, GLsizei to_width, GLsizei skip, GLsizei count);

GLvoid *copy_gl_array_convert(const GLvoid *src,
					  GLenum from, GLsizei width, GLsizei stride,
					  GLenum to, GLsizei to_width, GLsizei skip, GLsizei count, GLvoid* filler);
	
GLvoid *copy_gl_pointer(pointer_state_t *ptr, GLsizei width, GLsizei skip, GLsizei count);
GLvoid *copy_gl_pointer_color(pointer_state_t *ptr, GLsizei width, GLsizei skip, GLsizei count);
GLvoid *copy_gl_pointer_color_bgra(const void *ptr, GLint stride, GLsizei width, GLsizei skip, GLsizei count);
GLvoid *copy_gl_pointer_bytecolor(pointer_state_t *ptr, GLsizei width, GLsizei skip, GLsizei count);
GLvoid *copy_gl_pointer_raw(pointer_state_t *ptr, GLsizei width, GLsizei skip, GLsizei count);
GLvoid *copy_gl_pointer_tex(pointer_state_t *ptr, GLsizei width, GLsizei skip, GLsizei count);
void copy_gl_pointer_tex_noalloc(void* dest, pointer_state_t *ptr, GLsizei width, GLsizei skip, GLsizei count);
GLfloat *gl_pointer_index(pointer_state_t *ptr, GLint index);
void normalize_indices_us(GLushort *indices, GLsizei *max, GLsizei *min, GLsizei count);
void getminmax_indices_us(const GLushort *indices, GLsizei *max, GLsizei *min, GLsizei count);
void normalize_indices_ui(GLuint *indices, GLsizei *max, GLsizei *min, GLsizei count);
void getminmax_indices_ui(const GLuint *indices, GLsizei *max, GLsizei *min, GLsizei count);

GLfloat *copy_eval_double1(GLenum target, GLint ustride, GLint uorder, const GLdouble *points);
GLfloat *copy_eval_float1(GLenum target, GLint ustride, GLint uorder, const GLfloat *points);
GLfloat *copy_eval_double2(GLenum target, GLint ustride, GLint uorder, GLint vstride, GLint vorder, const GLdouble *points);
GLfloat *copy_eval_float2(GLenum target, GLint ustride, GLint uorder, GLint vstride, GLint vorder, const GLfloat *points);

#endif // _GL4ES_ARRAY_H_
