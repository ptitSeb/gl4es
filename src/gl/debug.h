#ifndef __DEBUG_H_
#define __DEBUG_H_

#include "gles.h"

const char* PrintEnum(GLenum what);

const char* PrintEGLError(int onlyerror);

void CheckGLError(int fwd);
#endif
