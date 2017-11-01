#include "gl.h"

#ifndef __SHADERCONV_H_
#define __SHADERCONV_H_

#include "program.h"

char* ConvertShader(const char* pBuffer, int isVertex, shaderconv_need_t *need);

int isBuiltinAttrib(const char* name);
int isBuiltinMatrix(const char* name);

#endif