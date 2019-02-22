#ifndef _GL4ES_MATVEC_H_
#define _GL4ES_MATVEC_H_

#include <math.h>
#include "attributes.h"
#include "gles.h"

GLfloat dot(const GLfloat *a, const GLfloat *b) FASTMATH;
GLfloat dot4(const GLfloat *a, const GLfloat *b) FASTMATH;
GLfloat cross3(const GLfloat *a, const GLfloat *b, GLfloat* c) FASTMATH;
void matrix_vector(const GLfloat *a, const GLfloat *b, GLfloat *c);
void vector_matrix(const GLfloat *a, const GLfloat *b, GLfloat *c);
void vector3_matrix(const GLfloat *a, const GLfloat *b, GLfloat *c);
void vector3_matrix3(const GLfloat *a, const GLfloat *b, GLfloat *c);
void vector3_matrix4(const GLfloat *a, const GLfloat *b, GLfloat *c);
void vector_normalize(GLfloat *a);
void vector4_normalize(GLfloat *a);
void vector4_mult(const GLfloat *a, const GLfloat *b, GLfloat *c);
void vector4_add(const GLfloat *a, const GLfloat *b, GLfloat *c);
void matrix_transpose(const GLfloat *a, GLfloat *b);
void matrix_inverse(const GLfloat *m, GLfloat *r);
void matrix_inverse3_transpose(const GLfloat *m, GLfloat *r); // upper3x3 of matrix4 -> inverse -> transposed mat3
void matrix_mul(const GLfloat *a, const GLfloat *b, GLfloat *c);
void set_identity(GLfloat* mat);
GLint is_identity(const GLfloat* mat);

#endif // _GL4ES_MATVEC_H_
