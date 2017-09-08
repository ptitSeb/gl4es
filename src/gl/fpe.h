#include "gl.h"

#ifndef __FPE_H_
#define __FPE_H_
/*
  This is the FPE : Fixed Pipeline Emulator

  It task is to create a shader that emulate the fixed pipeline.

  So based on the current GL State, it will either take a shader from the cache or create a new one
  For conveniance, the relevant GL states element are condenced in a bitfield packed fpe_state_t structure

*/

#define FPE_FOG_OFF 0
#define FPE_FOG_LINEAR 1
#define FPE_FOG_EXP 2
#define FPE_FOG_EXP2 3

#define FPE_TEX_OFF  0
#define FPE_TEX_2D   1
#define FPE_TEX_CUBE 2
#define FPE_TEX_STRM 3

typedef struct {
    int plane:6;                //  0: 5  the 6 planes packed
    int light:8;                //  5:13  the 8 lights packed
    int light_2sided:8;         // 14:21  the 8 two sided bits packed (equation is simpler when not 2-sided)
    int fogmode:4;              // 22:25  fog mode
    int colorsum:1;             // 26:26  secondary color enabled
    int texture:32;             // 27:58  8 texture stored on 4 bits

    int dummy:5;                // 59:63  to be sure it's int32 aligned
}__attribute__((packed)) fpe_state_t;


void fpe_glEnableClientState(GLenum cap);
void fpe_glDisableClientState(GLenum cap);
void fpe_glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void fpe_glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void fpe_glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void fpe_glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void fpe_glNormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer);
void fpe_glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void fpe_glEnable(GLenum cap);
void fpe_glDisable(GLenum cap);
//void fpe_glDrawArrays(GLenum mode, GLint first, GLsizei count);
//void fpe_glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
void fpe_glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void fpe_glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz);

#endif