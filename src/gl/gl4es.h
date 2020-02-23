#ifndef _GL4ES_GL4ES_H_
#define _GL4ES_GL4ES_H_

#include "khash.h"

#ifdef __ARM_NEON__
#include <arm_neon.h>
#endif // __ARM_NEON__

#include "wrap/gles.h"
#include "gles.h"
#include "glstate.h"

packed_call_t* glCopyPackedCall(const packed_call_t *packed);

#define checkError(code)                          \
    {int error; while ((error = glGetError())) {} \
    code                                          \
    if ((error = glGetError()))                   \
        printf(#code " -> %i\n", error);}

#define printError(file, line)              \
    {int error; if ((error = glGetError())) \
        printf(file ":%i -> %i\n", line, error);}

#define FLUSH_BEGINEND if(glstate->list.pending) gl4es_flush()

#define ERROR_IN_BEGIN if(glstate->list.begin) {errorShim(GL_INVALID_OPERATION); return;}

const GLubyte *gl4es_glGetString(GLenum name);
void gl4es_glGetIntegerv(GLenum pname, GLint *params);
void gl4es_glGetFloatv(GLenum pname, GLfloat *params);
void gl4es_glEnable(GLenum cap);
void gl4es_glDisable(GLenum cap);
void gl4es_glEnableClientState(GLenum cap);
void gl4es_glDisableClientState(GLenum cap);
GLboolean gl4es_glIsEnabled(GLenum cap);
void gl4es_glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
void gl4es_glDrawArrays(GLenum mode, GLint first, GLsizei count);
void gl4es_glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid *pointer);
void gl4es_glBegin(GLenum mode);
void gl4es_glEnd();
void gl4es_glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz);
void gl4es_glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void gl4es_glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void gl4es_glSecondaryColor3f(GLfloat r, GLfloat g, GLfloat b);
void gl4es_glMaterialfv(GLenum face, GLenum pname, const GLfloat *params);
void gl4es_glMaterialf(GLenum face, GLenum pname, const GLfloat param);
void gl4es_glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void gl4es_glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void gl4es_glArrayElement(GLint i);
void gl4es_glLockArrays(GLint first, GLsizei count);
void gl4es_glUnlockArrays();
GLuint gl4es_glGenLists(GLsizei range);
void gl4es_glNewList(GLuint list, GLenum mode);
void gl4es_glEndList();
void gl4es_glCallList(GLuint list);
void gl4es_glCallLists(GLsizei n, GLenum type, const GLvoid *lists);
void gl4es_glDeleteLists(GLuint list, GLsizei range);
void gl4es_glListBase(GLuint base);
GLboolean gl4es_glIsList(GLuint list);
void gl4es_glPolygonMode(GLenum face, GLenum mode);
GLenum gl4es_glGetError();

void gl4es_glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void gl4es_glIndexPointer(GLenum type, GLsizei stride, const GLvoid * pointer);
void gl4es_glEdgeFlagPointer(GLsizei stride, const GLvoid * pointer);
void gl4es_glGetPointerv(GLenum pname, GLvoid* *params);
void gl4es_glFlush();
void gl4es_glFinish();
void gl4es_glFogfv(GLenum pname, const GLfloat* params);

void gl4es_glStencilMaskSeparate(GLenum face, GLuint mask);

void gl4es_glMultiDrawArrays(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
void gl4es_glMultiDrawElements( GLenum mode, GLsizei *count, GLenum type, const void * const *indices, GLsizei primcount);
void gl4es_glMultiDrawElementsBaseVertex( GLenum mode, GLsizei *count, GLenum type, const void * const *indices, GLsizei primcount, const GLint * basevertex);

void gl4es_glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
void gl4es_glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);

void gl4es_glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
void gl4es_glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount);
void gl4es_glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount, GLint basevertex);

const GLubyte *gl4es_glGetStringi(GLenum name, GLuint index);

void gl4es_glClampColor(GLenum target, GLenum clamp);

void gl4es_flush(void);

int adjust_vertices(GLenum mode, int nb);

extern glstate_t *glstate;

void fpe_Init(glstate_t *glstate);       // defined in fpe.c
void fpe_Dispose(glstate_t *glstate);    // defined in fpe.c

static inline void errorGL() {	// next glGetError will be from GL 
	glstate->shim_error = 0;
}
static inline void errorShim(GLenum error) {	// next glGetError will be "error" from gl4es
	glstate->shim_error = 1;
	glstate->last_error = error;
}
static inline void noerrorShim() {
	errorShim(GL_NO_ERROR);
}

static inline void noerrorShimNoPurge() {
	glstate->shim_error = 2;
	glstate->last_error = GL_NO_ERROR;
}

void gl4es_scratch(int alloc);
void gl4es_scratch_vertex(int alloc);
void gl4es_scratch_indices(int alloc);
void gl4es_use_scratch_vertex(int use);
void gl4es_use_scratch_indices(int use);

void ToBuffer(int first, int count);
void UnBuffer();

GLboolean glIsList(GLuint list);
GLuint glGenLists(GLsizei range);
void glActiveTextureARB(GLenum texture);
void glArrayElement(GLint i);
void glBegin(GLenum mode);
void glCallList(GLuint list);
void glCallLists(GLsizei n, GLenum type, const GLvoid *lists);
void glClearDepth(GLdouble depth);
void glDeleteList(GLuint list);
void glDeleteLists(GLuint list, GLsizei range);
void glDrawArrays(GLenum mode, GLint first, GLsizei count);
void glEnd();
void glEndList();
void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far);
void glGetDoublev(GLenum pname, GLdouble *params);
void glIndexf(GLfloat i);
void glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid *pointer);
void glListBase(GLuint base);
void glLockArraysEXT(GLint first, GLsizei count);
void glNewList(GLuint list, GLenum mode);
void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far);
void glSecondaryColor3f(GLfloat r, GLfloat g, GLfloat b);
void glTexCoord2f(GLfloat s, GLfloat t);
void glUnlockArraysEXT();
void glVertex2f(GLfloat x, GLfloat y);
void glVertex2i(GLint x, GLint y);
void glVertex3f(GLfloat x, GLfloat y, GLfloat z);
GLenum glGetError();

// custom functions
void glPushCall(void *call);

#endif // _GL4ES_GL4ES_H_
