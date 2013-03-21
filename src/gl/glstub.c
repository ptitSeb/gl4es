#include <gl.h>

#define STUB(def)\
def {\
    /*printf("stub: %s;\n", #def);*/\
}

STUB(void glFogCoordd(GLdouble coord))
STUB(void glFogCoordf(GLfloat coord))
STUB(void glFogCoorddv(const GLdouble *coord))
STUB(void glFogCoordfv(const GLfloat *coord))

// STUB(void glMultiTexCoord());
// STUB(void glVertexAttrib());
// STUB(void glEvalCoord());
// STUB(void glEvalPoint());
STUB(GLint glRenderMode(GLenum mode))
STUB(void glArrayElement(GLint i))
STUB(void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha))
STUB(void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha))
STUB(void glBlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha))
STUB(void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha))
STUB(void glColorMaterial(GLenum face, GLenum mode))
STUB(void glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type))
STUB(void glDrawBuffer(GLenum mode))
STUB(void glEdgeFlag(GLboolean flag))
STUB(void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid * img))
STUB(void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params))
STUB(void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params))
STUB(void glIndexf(GLfloat c))
STUB(void glInitNames())
STUB(void glLoadName(GLuint name))
STUB(void glPixelTransferf(GLenum pname, GLfloat param))
STUB(void glPixelTransferi(GLenum pname, GLint param))
STUB(void glPixelZoom(GLfloat xfactor, GLfloat yfactor))
STUB(void glPolygonMode(GLenum face, GLenum mode))
STUB(void glPolygonStipple(const GLubyte *mask))
STUB(void glPopName())
STUB(void glPushName())
STUB(void glReadBuffer(GLenum mode))
STUB(void glSecondaryColor3f(GLfloat r, GLfloat g, GLfloat b))
STUB(void glTexImage3D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *data))

// glSelectBuffer: http://www.lighthouse3d.com/opengl/picking/index.php?color1
STUB(void glSelectBuffer(GLsizei size, GLuint *buffer))

#undef STUB
