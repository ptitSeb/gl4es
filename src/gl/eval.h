#include "gl.h"

#ifndef GL_MAP_H
#define GL_MAP_H

void glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
void glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
void glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
void glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);

void glEvalCoord1d(GLdouble u);
void glEvalCoord1f(GLfloat u);
void glEvalCoord2d(GLdouble u, GLdouble v);
void glEvalCoord2f(GLfloat u, GLfloat v);

GLvoid glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
void glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
void glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);

typedef struct {
    GLenum type;
} MapState;

typedef struct {
    GLdouble _1, _2, n, d;
    GLint stride, order;
} MapCoordD;

typedef struct {
    GLdouble _1, _2, n, d;
    GLint stride, order;
} MapCoordF;

typedef struct {
    GLenum type;
    GLint dims, width;
    MapCoordD u, v;
    const GLdouble *points;
} MapStateD;

typedef struct {
    GLenum type;
    GLint dims, width;
    MapCoordF u, v;
    const GLfloat *points;
} MapStateF;

#endif
