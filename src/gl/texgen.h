#include "gl.h"
#include <math.h>

extern void glTexGenfv(GLenum coord, GLenum pname, const GLfloat *params);
extern void glTexGeni(GLenum coord, GLenum pname, GLint param);
extern void gen_tex_coords(GLfloat *verts, GLfloat *norm, GLfloat **coords, GLint count, GLint *needclean, int texture, GLushort* indices, GLuint ilen);
extern void gen_tex_clean(GLint cleancode, int texture);
extern void glGetTexGenfv(GLenum coord,GLenum pname,GLfloat *params);

extern GLfloat dot(const GLfloat *a, const GLfloat *b);
extern void matrix_vector(const GLfloat *a, const GLfloat *b, GLfloat *c);
extern void vector_matrix(const GLfloat *a, const GLfloat *b, GLfloat *c);
extern void vector_normalize(GLfloat *a);
extern void matrix_column_row(const GLfloat *a, GLfloat *b);
extern void matrix_row_column(const GLfloat *a, GLfloat *b);
extern void matrix_inverse(const GLfloat *m, GLfloat *r);

extern void glLoadTransposeMatrixf(const GLfloat *m);
extern void glLoadTransposeMatrixd(const GLdouble *m);
extern void glMultTransposeMatrixd(const GLdouble *m);
extern void glMultTransposeMatrixf(const GLfloat *m);
