#include "fpe.h"
#include "gl.h"
#include "../glx/hardext.h"

// ********* Cache handling *********

// ********* Shader stuffs handling *********
void fpe_program() {

}

// ********* Fixed Pipeling function wrapper *********
#define CHECKFPE      \
    if(!glstate->fpe) \
        fpe_program();

void fpe_glEnableClientState(GLenum cap) {
    CHECKFPE
}

void fpe_glDisableClientState(GLenum cap) {
    CHECKFPE
}

void fpe_glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    CHECKFPE
}

void fpe_glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) {
    CHECKFPE
}

void fpe_glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) {
    CHECKFPE
}

void fpe_glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) {
    CHECKFPE
}

void fpe_glNormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer) {
    CHECKFPE
}

void fpe_glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) {
    CHECKFPE
}

void fpe_glEnable(GLenum cap) {
    gl4es_glEnable(cap);    // may reset fpe curent program
}
void fpe_glDisable(GLenum cap) {
    gl4es_glDisable(cap);   // may reset fpe curent program
}

void fpe_glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    noerrorShim();
}

void fpe_glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {
    noerrorShim();
}