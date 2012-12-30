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

#undef STUB
