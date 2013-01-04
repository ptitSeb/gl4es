#include "gl.h"

void glFlush();

void glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);

void glHint(GLenum target, GLenum mode);

void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);

const GLubyte * glGetString(GLenum name);

void glLightx(GLenum light, GLenum pname, GLfixed param);

void glGetTexParameterxv(GLenum target, GLenum pname, GLfixed * params);

void glScalef(GLfloat x, GLfloat y, GLfloat z);

void glClearColorx(GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha);

void glLineWidth(GLfloat width);

void glScalex(GLfixed x, GLfixed y, GLfixed z);

void glLightf(GLenum light, GLenum pname, GLfloat param);

void glDeleteTextures(GLsizei n, const GLuint * textures);

void glClearDepthx(GLclampx depth);

void glDepthRangef(GLclampf near, GLclampf far);

void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params);

void glClearStencil(GLint s);

void glSampleCoverage(GLclampf value, GLboolean invert);

void glGenTextures(GLsizei n, GLuint * textures);

void glDepthFunc(GLenum func);

void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data);

void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);

void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params);

GLboolean glIsBuffer(GLuint buffer);

GLboolean glIsTexture(GLuint texture);

void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);

void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data);

void glPointSizePointerOES(GLenum type, GLsizei stride, const GLvoid * pointer);

void glDisable(GLenum cap);

void glLogicOp(GLenum opcode);

void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);

void glBindTexture(GLenum target, GLuint texture);

void glMultiTexCoord4x(GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q);

void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params);

void glLineWidthx(GLfixed width);

void glCullFace(GLenum mode);

void glGetLightfv(GLenum light, GLenum pname, GLfloat * params);

void glColor4x(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);

void glPointSize(GLfloat size);

void glDrawArrays(GLenum mode, GLint first, GLsizei count);

void glViewport(GLint x, GLint y, GLsizei width, GLsizei height);

void glLoadIdentity();

void glTexEnvf(GLenum target, GLenum pname, GLfloat param);

void glGetFixedv(GLenum pname, GLfixed * params);

void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);

void glEnableClientState(GLenum array);

void glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params);

void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices);

void glTexEnvi(GLenum target, GLenum pname, GLint param);

void glClientActiveTexture(GLenum texture);

void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data);

void glMatrixMode(GLenum mode);

void glSampleCoveragex(GLclampx value, GLboolean invert);

void glGetLightxv(GLenum light, GLenum pname, GLfixed * params);

void glNormalPointer(GLenum type, GLsizei stride, const GLvoid * pointer);

void glGetMaterialxv(GLenum face, GLenum pname, GLfixed * params);

void glPopMatrix();

void glFogx(GLenum pname, GLfixed param);

void glPointSizex(GLfixed size);

void glClipPlanef(GLenum plane, const GLfloat * equation);

void glPointParameterf(GLenum pname, GLfloat param);

void glPointParameterx(GLenum pname, GLfixed param);

void glMaterialf(GLenum face, GLenum pname, GLfloat param);

void glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);

void glFogf(GLenum pname, GLfloat param);

void glLightModelf(GLenum pname, GLfloat param);

void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels);

void glRotatex(GLfixed angle, GLfixed x, GLfixed y, GLfixed z);

void glClear(GLbitfield mask);

void glActiveTexture(GLenum texture);

void glTexEnvx(GLenum target, GLenum pname, GLfixed param);

void glBindBuffer(GLenum target, GLuint buffer);

void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);

void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass);

void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels);

void glLightModelx(GLenum pname, GLfixed param);

void glGetTexEnvxv(GLenum target, GLenum pname, GLfixed * params);

void glTranslatef(GLfloat x, GLfloat y, GLfloat z);

void glLoadMatrixx(const GLfixed * m);

void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage);

GLboolean glIsEnabled(GLenum cap);

void glDisableClientState(GLenum array);

GLenum glGetError();

void glGetTexEnviv(GLenum target, GLenum pname, GLint * params);

void glGetFloatv(GLenum pname, GLfloat * params);

void glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params);

void glAlphaFunc(GLenum func, GLclampf ref);

void glTranslatex(GLfixed x, GLfixed y, GLfixed z);

void glGetClipPlanex(GLenum plane, GLfixed * equation);

void glMaterialx(GLenum face, GLenum pname, GLfixed param);

void glStencilFunc(GLenum func, GLint ref, GLuint mask);

void glGetIntegerv(GLenum pname, GLint * params);

void glGetClipPlanef(GLenum plane, GLfloat * equation);

void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);

void glFrontFace(GLenum mode);

void glLoadMatrixf(const GLfloat * m);

void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels);

void glFrustumx(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far);

void glStencilMask(GLuint mask);

void glOrthox(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far);

void glMultMatrixf(const GLfloat * m);

void glMultMatrixx(const GLfixed * m);

void glClipPlanex(GLenum plane, const GLfixed * equation);

void glShadeModel(GLenum mode);

void glOrthof(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far);

void glFrustumf(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far);

void glEnable(GLenum cap);

void glNormal3x(GLfixed nx, GLfixed ny, GLfixed nz);

void glGenBuffers(GLsizei n, GLuint * buffers);

void glFinish();

void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz);

void glBlendFunc(GLenum sfactor, GLenum dfactor);

void glAlphaFuncx(GLenum func, GLclampx ref);

void glDepthRangex(GLclampx near, GLclampx far);

void glGetPointerv(GLenum pname, GLvoid ** params);

void glDepthMask(GLboolean flag);

void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);

void glPolygonOffsetx(GLfixed factor, GLfixed units);

void glTexParameterf(GLenum target, GLenum pname, GLfloat param);

void glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);

void glTexParameteri(GLenum target, GLenum pname, GLint param);

void glPushMatrix();

void glClearDepthf(GLclampf depth);

void glDeleteBuffers(GLsizei n, const GLuint * buffers);

void glScissor(GLint x, GLint y, GLsizei width, GLsizei height);

void glGetBooleanv(GLenum pname, GLboolean * params);

void glPixelStorei(GLenum pname, GLint param);

void glTexParameterx(GLenum target, GLenum pname, GLfixed param);

void glPolygonOffset(GLfloat factor, GLfloat units);


