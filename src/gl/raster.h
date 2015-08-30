#include "gl.h"
#ifndef GL_STENCIL_INDEX
#define GL_STENCIL_INDEX			0x1901
#endif
#ifndef GL_DEPTH_COMPONENT
#define GL_DEPTH_COMPONENT			0x1902
#endif

#ifndef RASTER_H
#define RASTER_H

typedef struct {
    GLfloat x;
    GLfloat y;
    GLfloat z;
} rasterpos_t;

typedef struct {
    GLint x;
    GLint y;
    GLsizei width;
    GLsizei height;
} viewport_t;

extern viewport_t viewport;

extern GLfloat raster_scale[4];
extern GLfloat raster_bias[4];

int raster_need_transform();

extern void glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig,
                     GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
extern void glDrawPixels(GLsizei width, GLsizei height, GLenum format,
                         GLenum type, const GLvoid *data);
extern void glRasterPos3f(GLfloat x, GLfloat y, GLfloat z);
extern void glWindowPos3f(GLfloat x, GLfloat y, GLfloat z);
extern void glViewport(GLint x, GLint y, GLsizei width, GLsizei height);
extern void render_raster();

extern void glPixelZoom(GLfloat xfactor, GLfloat yfactor);

extern void glPixelTransferf(GLenum pname, GLfloat param);

void render_raster_list(rasterlist_t* raster);
	
#endif
