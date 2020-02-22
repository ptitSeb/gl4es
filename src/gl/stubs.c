#include "gl4es.h"
#include "attributes.h"

#define GLAPI EXPORT
#define APIENTRY
#define STUB errorShim(GL_INVALID_VALUE);

GLAPI void APIENTRY glClampColorARB (GLenum target, GLenum clamp){STUB}
