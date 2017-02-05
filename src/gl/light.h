#include "gl.h"

#ifndef __LIGHT_H_
#define __LIGHT_H_

typedef struct {
    GLfloat         ambient[4];
    GLfloat         diffuse[4];
    GLfloat         specular[4];
    GLfloat         constantAttenuation, linearAttenuation, quadraticAttenuation;
    GLfloat         position[4];
    GLfloat         spotDirection[4];  // It's only 3 in fact, because it's a direction
    GLfloat         spotExponent;
    GLfloat         spotCutoff;
} light_t;

typedef struct {
    light_t     lights[MAX_LIGHT];
    GLfloat     ambient[4];
    GLboolean   two_side;
} light_state_t;

typedef struct {
    GLfloat         ambient[4];
    GLfloat         diffuse[4];
    GLfloat         specular[4];
    GLfloat         emission[4];
    GLfloat         shininess;
    int             indexes[3];
    GLenum          colormat;
} material_t;

typedef struct {
    material_t      front;
    material_t      back;
} material_state_t;

void gl4es_glLightModelf(GLenum pname, GLfloat param);
void gl4es_glLightModelfv(GLenum pname, const GLfloat* params);
void gl4es_glLightfv(GLenum light, GLenum pname, const GLfloat* params);
void gl4es_glLightf(GLenum light, GLenum pname, const GLfloat params);

void gl4es_glGetLightfv(GLenum light, GLenum pname, GLfloat * params);
void gl4es_glGetLightiv(GLenum light, GLenum pname, GLint * params);

void gl4es_glMaterialfv(GLenum face, GLenum pname, const GLfloat *params) ;
void gl4es_glMaterialf(GLenum face, GLenum pname, const GLfloat param);
void gl4es_glColorMaterial(GLenum face, GLenum mode);

#endif //__LIGHT_H_