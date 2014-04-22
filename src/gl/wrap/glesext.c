#ifndef USE_ES2
#include "gles.h"
#ifndef skip_glBlendEquation
void glBlendEquation(GLenum mode) {
    LOAD_GLES_OES(glBlendEquation);
#ifndef direct_glBlendEquation
    PUSH_IF_COMPILING(glBlendEquation)
#endif
    gles_glBlendEquation(mode);
}
#endif
#ifndef skip_glBlendEquationSeparate
void glBlendEquationSeparate(GLenum modeRGB, GLenum modeA) {
    LOAD_GLES_OES(glBlendEquationSeparate);
#ifndef direct_glBlendEquationSeparate
    PUSH_IF_COMPILING(glBlendEquationSeparate)
#endif
    gles_glBlendEquationSeparate(modeRGB, modeA);
}
#endif
#ifndef skip_glBlendFuncSeparate
void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
    LOAD_GLES_OES(glBlendFuncSeparate);
#ifndef direct_glBlendFuncSeparate
    PUSH_IF_COMPILING(glBlendFuncSeparate)
#endif
    gles_glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
#endif
#ifndef skip_glTexGenfv
void glTexGenfv(GLenum coord, GLenum pname, const GLfloat * params) {
    LOAD_GLES_OES(glTexGenfv);
#ifndef direct_glTexGenfv
    PUSH_IF_COMPILING(glTexGenfv)
#endif
    gles_glTexGenfv(coord, pname, params);
}
#endif
#ifndef skip_glTexGeni
void glTexGeni(GLenum coord, GLenum pname, GLint param) {
    LOAD_GLES_OES(glTexGeni);
#ifndef direct_glTexGeni
    PUSH_IF_COMPILING(glTexGeni)
#endif
    gles_glTexGeni(coord, pname, param);
}
#endif
#endif
