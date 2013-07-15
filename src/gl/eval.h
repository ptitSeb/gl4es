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

typedef struct {
    GLenum type;
} MapState;

typedef struct {
    GLdouble _1, _2;
    GLint stride, order;
} MapCoordD;

typedef struct {
    GLdouble _1, _2;
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
