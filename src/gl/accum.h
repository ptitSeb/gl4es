#ifndef _GL4ES_ACCUM_H_
#define _GL4ES_ACCUM_H_

#include "gles.h"

// Accumulation-buffer emulation over an internal FBO (see accum.c).
void APIENTRY_GL4ES gl4es_glAccum(GLenum op, GLfloat value);
void APIENTRY_GL4ES gl4es_glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);

// glClear(GL_ACCUM_BUFFER_BIT) hook, called from gl4es_glClear
void gl4es_accum_clear(void);
// GL_ACCUM_*_BITS for the getter: 16 (half-float target), 8 (RGBA8 fallback), 0 (unavailable)
int gl4es_accum_get_bits(void);
void gl4es_accum_get_clear(GLfloat *params);
// Delete GL objects and free the accum state (DeleteGLState).
// Takes the glesaccum_t pointer; void* avoids a state.h cycle.
void gl4es_accum_dispose(void *accum);

#endif // _GL4ES_ACCUM_H_
