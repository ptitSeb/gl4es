#include "gl.h"

#ifndef RASTER_H
#define RASTER_H

typedef struct {
    GLfloat x;
    GLfloat y;
    GLfloat z;
} rasterPosT;

typedef struct {
    GLint x;
    GLint y;
    GLsizei width;
    GLsizei height;
} viewportT;

void glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig,
              GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
void glRasterPos3f(GLfloat x, GLfloat y, GLfloat z);
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height);
void renderRaster();

#endif
