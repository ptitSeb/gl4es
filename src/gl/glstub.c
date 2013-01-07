#include <gl.h>

#define STUB(def)\
def {\
    printf("stub: %s;\n", #def);\
}

STUB(void glPopAttrib());
STUB(void glPushAttrib(GLbitfield mask));
STUB(void glPopClientAttrib());
STUB(void glPushClientAttrib(GLbitfield mask));
STUB(void glSecondaryColor3f(GLfloat r, GLfloat g, GLfloat b));
STUB(void glIndexf(GLfloat c));

STUB(void glFogCoordd(GLdouble coord));
STUB(void glFogCoordf(GLfloat coord));
STUB(void glFogCoorddv(const GLdouble *coord));
STUB(void glFogCoordfv(const GLfloat *coord));

// STUB(void glMultiTexCoord());
// STUB(void glVertexAttrib());
// STUB(void glEvalCoord());
// STUB(void glEvalPoint());
STUB(void glArrayElement(GLint i));
STUB(void glClipPlane(GLenum plane, const GLdouble *equation));
STUB(void glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *data));
STUB(void glEdgeFlag(GLboolean flag));
STUB(void glLightModeli(GLenum pname, GLint param));
STUB(void glLoadName(GLuint name));
STUB(void glPixelTransferf(GLenum pname, GLfloat param));
STUB(void glPixelTransferi(GLenum pname, GLint param));
STUB(void glPolygonMode(GLenum face, GLenum mode));
STUB(void glPolygonStipple(const GLubyte *mask));
STUB(void glRasterPos2f(GLfloat x, GLfloat y));
STUB(void glReadBuffer(GLenum mode));
// glSelectBuffer: http://www.lighthouse3d.com/opengl/picking/index.php?color1
STUB(void glSelectBuffer(GLsizei size, GLuint *buffer));
STUB(GLint glRenderMode(GLenum mode));
STUB(void glInitNames());
STUB(void glPushName());
STUB(void glPopName());
STUB(void glPixelZoom(GLfloat xfactor, GLfloat yfactor));

#undef STUB
