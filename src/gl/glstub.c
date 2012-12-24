#include <gl.h>

#define STUB(def)\
def {\
    printf("stub: %s;\n", #def);\
}

STUB(void glColorMaterial(GLenum face, GLenum mode));
STUB(void glPopAttrib());
STUB(void glPushAttrib(GLbitfield mask));

#undef STUB
