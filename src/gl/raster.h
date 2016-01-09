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

void glshim_glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig,
                     GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
void glshim_glDrawPixels(GLsizei width, GLsizei height, GLenum format,
                         GLenum type, const GLvoid *data);
void glshim_glRasterPos3f(GLfloat x, GLfloat y, GLfloat z);
void glshim_glWindowPos3f(GLfloat x, GLfloat y, GLfloat z);
void glshim_glViewport(GLint x, GLint y, GLsizei width, GLsizei height);
void render_raster();

void glshim_glPixelZoom(GLfloat xfactor, GLfloat yfactor);

void glshim_glPixelTransferf(GLenum pname, GLfloat param);

void render_raster_list(rasterlist_t* raster);
	
#endif
