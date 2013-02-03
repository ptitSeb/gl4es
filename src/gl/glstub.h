#include "gl.h"

void glFogCoordd(GLdouble coord);
void glFogCoordf(GLfloat coord);
void glFogCoorddv(const GLdouble *coord);
void glFogCoordfv(const GLfloat *coord);

GLint glRenderMode(GLenum mode);
void glArrayElement(GLint i);
void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha);
void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
void glBlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
void glDrawBuffer(GLenum mode);
void glEdgeFlag(GLboolean flag);
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
// glSelectBuffer: http://www.lighthouse3d.com/opengl/picking/index.php?color1
void glSelectBuffer(GLsizei size, GLuint *buffer);
