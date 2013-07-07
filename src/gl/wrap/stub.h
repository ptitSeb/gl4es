#include "../gl.h"

GLint glRenderMode(GLenum mode);
void glArrayElement(GLint i);
void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha);
void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
void glBlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
void glColorMaterial(GLenum face, GLenum mode);
void glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
void glDrawBuffer(GLenum mode);
void glEdgeFlag(GLboolean flag);
void glFogCoordd(GLdouble coord);
void glFogCoorddv(const GLdouble *coord);
void glFogCoordf(GLfloat coord);
void glFogCoordfv(const GLfloat *coord);
void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid * img);
void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params);
void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params);
void glIndexf(GLfloat c);
void glInitNames();
void glLightModeli(GLenum pname, GLint param);
void glLoadName(GLuint name);
void glPixelTransferf(GLenum pname, GLfloat param);
void glPixelTransferi(GLenum pname, GLint param);
void glPixelZoom(GLfloat xfactor, GLfloat yfactor);
void glPolygonMode(GLenum face, GLenum mode);
void glPolygonStipple(const GLubyte *mask);
void glPopName();
void glPushName();
void glReadBuffer(GLenum mode);
void glSecondaryColor3f(GLfloat r, GLfloat g, GLfloat b);
void glTexImage3D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *data);
// glSelectBuffer: http://www.lighthouse3d.com/opengl/picking/index.php?color1
void glSelectBuffer(GLsizei size, GLuint *buffer);

// mesh functions
void glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
void glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
void glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
