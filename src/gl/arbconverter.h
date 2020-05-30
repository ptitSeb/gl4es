#ifndef _GL4ES_ARBCONVERTER_H_
#define _GL4ES_ARBCONVERTER_H_

#include <stdint.h>

typedef struct glsl_s glsl_t;
char* gl4es_convertARB(const char* const code, int vertex, glsl_t *glsl);

#endif // _GL4ES_ARBCONVERTER_H_
