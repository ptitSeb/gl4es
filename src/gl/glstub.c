#include <gl.h>

#define STUB(def)\
def {\
    printf("stub: %s;\n", #def);\
}

STUB(void glColorMaterial(GLenum face, GLenum mode));
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
STUB(void glEdgeFlag(GLboolean flag));

#undef STUB
