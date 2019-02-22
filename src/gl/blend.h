#ifndef _GL4ES_BLEND_H_
#define _GL4ES_BLEND_H_

#include "gles.h"

void gl4es_glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
void gl4es_glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
void gl4es_glBlendEquationSeparate(GLenum modeRGB, GLenum modeA);
void gl4es_glBlendFunc(GLenum sfactor, GLenum dfactor);
void gl4es_glBlendEquation(GLenum mode);

#endif //_GL4ES_BLEND_H_
