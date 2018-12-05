#include "gl.h"

#ifndef __STENCIL_H_
#define __STENCIL_H_

typedef struct {
    GLenum      func[2];
    GLint       f_ref[2];
    GLuint      f_mask[2];
    GLuint      mask[2];
    GLenum      sfail[2];
    GLenum      dpfail[2];
    GLenum      dppass[2];
    GLint       clear;
} stencil_t;

#endif