#include "../gl.h"

//GLint glRenderMode(GLenum mode);
//void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha);
void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
//void glBlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
void glColorMaterial(GLenum face, GLenum mode);
void glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
void glDrawBuffer(GLenum mode);
void glEdgeFlag(GLboolean flag);
void glFogCoordd(GLdouble coord);
void glFogCoorddv(const GLdouble *coord);
void glFogCoordf(GLfloat coord);
void glFogCoordfv(const GLfloat *coord);
//void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid * img);
//void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params);
//void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params);
void glIndexf(GLfloat c);
//void glInitNames();
void glLightModeli(GLenum pname, GLint param);
//void glLoadName(GLuint name);
//void glPixelTransferf(GLenum pname, GLfloat param);
//void glPixelTransferi(GLenum pname, GLint param);
//void glPixelZoom(GLfloat xfactor, GLfloat yfactor);
//void glPolygonMode(GLenum face, GLenum mode);
void glPolygonStipple(const GLubyte *mask);
//void glPopName();
//void glPushName();
void glReadBuffer(GLenum mode);
void glSecondaryColor3f(GLfloat r, GLfloat g, GLfloat b);
// glSelectBuffer: http://www.lighthouse3d.com/opengl/picking/index.php?color1
//void glSelectBuffer(GLsizei size, GLuint *buffer);
void glColorTable (GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid *table);

void glAccum(GLenum op, GLfloat value);
void glPrioritizeTextures(GLsizei n, const GLuint *textures, const GLclampf *priorities);
void glPixelMapfv(GLenum map, GLsizei mapsize, const GLfloat *values);
void glPixelMapuiv(GLenum map,GLsizei mapsize, const GLuint *values);
void glPixelMapusv(GLenum map,GLsizei mapsize, const GLushort *values);
void glPassThrough(GLfloat token);
void glIndexMask(GLuint mask);
void glGetPixelMapfv(GLenum map, GLfloat *data);
void glGetPixelMapuiv(GLenum map, GLuint *data);
void glGetPixelMapusv(GLenum map, GLushort *data);
void glClearIndex(GLfloat c);
void glGetPolygonStipple(GLubyte *pattern);
void glFeedbackBuffer(GLsizei size, GLenum type, GLfloat *buffer);
void glEdgeFlagv(GLboolean *flag);
