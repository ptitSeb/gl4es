#include "gl.h"

#ifndef GL_MAP_H
#define GL_MAP_H

void glshim_glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
void glshim_glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
void glshim_glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
void glshim_glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);

void glshim_glEvalCoord1d(GLdouble u);
void glshim_glEvalCoord1f(GLfloat u);
void glshim_glEvalCoord2d(GLdouble u, GLdouble v);
void glshim_glEvalCoord2f(GLfloat u, GLfloat v);

void glshim_glEvalMesh1(GLenum mode, GLint i1, GLint i2);
void glshim_glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
void glshim_glEvalPoint1(GLint i);
void glshim_glEvalPoint2(GLint i, GLint j);
void glshim_glMapGrid1d(GLint un, GLdouble u1, GLdouble u2);
void glshim_glMapGrid1f(GLint un, GLfloat u1, GLfloat u2);
void glshim_glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
void glshim_glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
void glshim_glGetMapdv(GLenum target, GLenum query, GLdouble *v);
void glshim_glGetMapfv(GLenum target, GLenum query, GLfloat *v);
void glshim_glGetMapiv(GLenum target, GLenum query, GLint *v);

typedef struct {
    GLenum type;
} map_state_t;

typedef struct {
    GLdouble _1, _2, n, d;
    GLint stride, order;
} mapcoordd_t;

typedef struct {
    GLdouble _1, _2, n, d;
    GLint stride, order;
} mapcoordf_t;

typedef struct {
    GLenum type;
    GLint dims, width;
    mapcoordd_t u, v;
    GLboolean free;
    const GLdouble *points;
} map_stated_t;

typedef struct {
    GLenum type;
    GLint dims, width;
    mapcoordf_t u, v;
    GLboolean free;
    const GLfloat *points;
} map_statef_t;

static const GLsizei get_map_width(GLenum target) {
    switch (target) {
        case GL_MAP1_COLOR_4:         return 4;
        case GL_MAP1_INDEX:           return 3;
        case GL_MAP1_NORMAL:          return 3;
        case GL_MAP1_TEXTURE_COORD_1: return 1;
        case GL_MAP1_TEXTURE_COORD_2: return 2;
        case GL_MAP1_TEXTURE_COORD_3: return 3;
        case GL_MAP1_TEXTURE_COORD_4: return 4;
        case GL_MAP1_VERTEX_3:        return 3;
        case GL_MAP1_VERTEX_4:        return 4;
        case GL_MAP2_COLOR_4:         return 4;
        case GL_MAP2_INDEX:           return 3;
        case GL_MAP2_NORMAL:          return 3;
        case GL_MAP2_TEXTURE_COORD_1: return 1;
        case GL_MAP2_TEXTURE_COORD_2: return 2;
        case GL_MAP2_TEXTURE_COORD_3: return 3;
        case GL_MAP2_TEXTURE_COORD_4: return 4;
        case GL_MAP2_VERTEX_3:        return 3;
        case GL_MAP2_VERTEX_4:        return 4;
    }
    return 0;
}

#endif
