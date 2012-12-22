#include <gl.h>

#define STUB(def)\
def {\
    printf("stub: %s;\n", #def);\
}

STUB(void glColorMaterial(GLenum face, GLenum mode));
STUB(void glLineStipple(GLuint factor, GLushort pattern));
STUB(void glPopAttrib());
STUB(void glPushAttrib(GLbitfield mask));
STUB(void glTexGenfv(GLenum coord, GLenum pname, GLfloat *param));
STUB(void glTexGeni(GLenum coord, GLenum pname, GLint param));

#undef STUB
