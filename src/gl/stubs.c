#include "gl4es.h"

#define GLAPI __attribute__((visibility("default")))
#define APIENTRY
#define STUB errorShim(GL_INVALID_VALUE);

GLAPI void APIENTRY glClampColorARB (GLenum target, GLenum clamp){STUB}
