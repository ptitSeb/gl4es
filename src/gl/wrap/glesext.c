#ifndef USE_ES2
#include "gles.h"
#ifndef skip_glBlendEquationSeparate
void glBlendEquationSeparate(GLenum modeRGB, GLenum modeA) {
    LOAD_GLES_OES(glBlendEquationSeparate);
#ifndef direct_glBlendEquationSeparate
    PUSH_IF_COMPILING(glBlendEquationSeparate)
#endif
    gles_glBlendEquationSeparate(modeRGB, modeA);
}
#endif
#endif
