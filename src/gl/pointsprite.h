#include "gl.h"

#ifndef __POINTSPRITE_H_
#define __POINTSPRITE_H_

typedef struct {
    GLfloat size;
    GLfloat sizeMin;
    GLfloat sizeMax;
    GLfloat fadeThresholdSize;
    GLfloat distance[3];
    GLenum  coordOrigin;
} pointsprite_t;

void gl4es_glPointParameteri(GLenum pname, GLint param);
void gl4es_glPointParameteriv(GLenum pname, const GLint * params);
void gl4es_glPointParameterf(GLenum pname, GLfloat param);
void gl4es_glPointParameterfv(GLenum pname, const GLfloat * params);

void gl4es_glPointSize(GLfloat size);

#endif //__POINTSPRITE_H_