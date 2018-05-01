#include "gl.h"

#ifndef __DEPTH_H__
#define __DEPTH_H__

void gl4es_glDepthFunc(GLenum func);
void gl4es_glDepthMask(GLboolean flag);
void gl4es_glDepthRangef(GLclampf nearVal, GLclampf farVal);
void gl4es_glClearDepthf(GLclampf depth);

#endif //__DEPTH_H__