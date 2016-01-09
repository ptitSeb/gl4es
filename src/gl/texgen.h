#include "gl.h"
#include <math.h>

void glshim_glTexGenfv(GLenum coord, GLenum pname, const GLfloat *params);
void glshim_glTexGeni(GLenum coord, GLenum pname, GLint param);
void gen_tex_coords(GLfloat *verts, GLfloat *norm, GLfloat **coords, GLint count, GLint *needclean, int texture, GLushort* indices, GLuint ilen);
void gen_tex_clean(GLint cleancode, int texture);
void glshim_glGetTexGenfv(GLenum coord,GLenum pname,GLfloat *params);

GLfloat dot(const GLfloat *a, const GLfloat *b);
void matrix_vector(const GLfloat *a, const GLfloat *b, GLfloat *c);
void vector_matrix(const GLfloat *a, const GLfloat *b, GLfloat *c);
void vector_normalize(GLfloat *a);
void matrix_column_row(const GLfloat *a, GLfloat *b);
void matrix_row_column(const GLfloat *a, GLfloat *b);
void matrix_inverse(const GLfloat *m, GLfloat *r);
void matrix_mul(const GLfloat *a, const GLfloat *b, GLfloat *c);

void glshim_glLoadTransposeMatrixf(const GLfloat *m);
void glshim_glLoadTransposeMatrixd(const GLdouble *m);
void glshim_glMultTransposeMatrixd(const GLdouble *m);
void glshim_glMultTransposeMatrixf(const GLfloat *m);
