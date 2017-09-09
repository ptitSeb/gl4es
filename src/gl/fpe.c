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

void fpe_glDrawArrays(GLenum mode, GLint first, GLsizei count) {
    CHECKFPE
    realize_fpeenv();
    LOAD_GLES(glDrawArrays);
    gles_glDrawArrays(mode, first, count);
}

void fpe_glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices) {
    CHECKFPE
    realize_fpeenv();
    LOAD_GLES(glDrawElements);
    gles_glDrawElements(mode, count, type, indices);
}


// ********* Realize GLES Environnements *********

void realize_glenv() {
    LOAD_GLES2(glUseProgram);
    // activate program if needed
    if(glstate->gleshard.program != glstate->glsl.program) {
        glstate->gleshard.program = glstate->glsl.program;
        gles_glUseProgram(glstate->gleshard.program);
    }
    // set Attrib if needed
}
void realize_fpeenv() {

}
void realize_blitenv() {

}
