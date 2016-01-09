#ifndef __DIRECTSTATE_H_
#define __DIRECTSTATE_H_

#include "gl.h"

void glshim_glClientAttribDefault(GLbitfield mask);
void glshim_glPushClientAttribDefault(GLbitfield mask);

void glshim_glMatrixLoadf(GLenum matrixMode, const GLfloat *m);
void glshim_glMatrixLoadd(GLenum matrixMode, const GLdouble *m);
void glshim_glMatrixMultf(GLenum matrixMode, const GLfloat *m);
void glshim_glMatrixMultd(GLenum matrixMode, const GLdouble *m);
void glshim_glMatrixLoadIdentity(GLenum matrixMode);
void glshim_glMatrixRotatef(GLenum matrixMode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
void glshim_glMatrixRotated(GLenum matrixMode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
void glshim_glMatrixScalef(GLenum matrixMode, GLfloat x, GLfloat y, GLfloat z);
void glshim_glMatrixScaled(GLenum matrixMode, GLdouble x, GLdouble y, GLdouble z);
void glshim_glMatrixTranslatef(GLenum matrixMode, GLfloat x, GLfloat y, GLfloat z);
void glshim_glMatrixTranslated(GLenum matrixMode, GLdouble x, GLdouble y, GLdouble z);
void glshim_glMatrixOrtho(GLenum matrixMode, GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f);
void glshim_glMatrixFrustum(GLenum matrixMode, GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f);
void glshim_glMatrixPush(GLenum matrixMode);
void glshim_glMatrixPop(GLenum matrixMode);

void glshim_glTextureParameteri(GLuint texture, GLenum target, GLenum pname, GLint param);
void glshim_glTextureParameteriv(GLuint texture, GLenum target, GLenum pname, const GLint *param);
void glshim_glTextureParameterf(GLuint texture, GLenum target, GLenum pname, GLfloat param);
void glshim_glTextureParameterfv(GLuint texture, GLenum target, GLenum pname, const GLfloat *param);
void glshim_glTextureImage1D(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
void glshim_glTextureImage2D(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
void glshim_glTextureSubImage1D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
void glshim_glTextureSubImage2D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
void glshim_glCopyTextureImage1D(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
void glshim_glCopyTextureImage2D(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void glshim_glCopyTextureSubImage1D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void glshim_glCopyTextureSubImage2D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glshim_glGetTextureImage(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
void glshim_glGetTextureParameterfv(GLuint texture, GLenum target, GLenum pname, GLfloat *params);
void glshim_glGetTextureParameteriv(GLuint texture, GLenum target, GLenum pname, GLint *params);
void glshim_glGetTextureLevelParameterfv(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat *params);
void glshim_glGetTextureLevelParameteriv(GLuint texture, GLenum target, GLint level, GLenum pname, GLint *params);

void glshim_glTextureImage3D(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
void glshim_glTextureSubImage3D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
void glshim_glCopyTextureSubImage3D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);

void glshim_glBindMultiTexture(GLenum texunit, GLenum target, GLuint texture);
void glshim_glMultiTexCoordPointer(GLenum texunit, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void glshim_glMultiTexEnvf(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
void glshim_glMultiTexEnvfv(GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
void glshim_glMultiTexEnvi(GLenum texunit, GLenum target, GLenum pname, GLint param);
void glshim_glMultiTexEnviv(GLenum texunit, GLenum target, GLenum pname, const GLint *params);
void glshim_glMultiTexGend(GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
void glshim_glMultiTexGendv(GLenum texunit, GLenum coord, GLenum pname, const GLdouble *params);
void glshim_glMultiTexGenf(GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
void glshim_glMultiTexGenfv(GLenum texunit, GLenum coord, GLenum pname, const GLfloat *params);
void glshim_glMultiTexGeni(GLenum texunit, GLenum coord, GLenum pname, GLint param);
void glshim_glMultiTexGeniv(GLenum texunit, GLenum coord, GLenum pname, const GLint *params);
void glshim_glGetMultiTexEnvfv(GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
void glshim_glGetMultiTexEnviv(GLenum texunit, GLenum target, GLenum pname, GLint *params);
void glshim_glGetMultiTexGendv(GLenum texunit, GLenum coord, GLenum pname, GLdouble *params);
void glshim_glGetMultiTexGenfv(GLenum texunit, GLenum coord, GLenum pname, GLfloat *params);
void glshim_glGetMultiTexGeniv(GLenum texunit, GLenum coord, GLenum pname, GLint *params);
void glshim_glMultiTexParameteri(GLenum texunit, GLenum target, GLenum pname, GLint param);
void glshim_glMultiTexParameteriv(GLenum texunit, GLenum target, GLenum pname, const GLint *param);
void glshim_glMultiTexParameterf(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
void glshim_glMultiTexParameterfv(GLenum texunit, GLenum target, GLenum pname, const GLfloat *param);
void glshim_glMultiTexImage1D(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
void glshim_glMultiTexImage2D(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
void glshim_glMultiTexSubImage1D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
void glshim_glMultiTexSubImage2D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
void glshim_glCopyMultiTexImage1D(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
void glshim_glCopyMultiTexImage2D(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void glshim_glCopyMultiTexSubImage1D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void glshim_glCopyMultiTexSubImage2D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glshim_glGetMultiTexImage(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
void glshim_glGetMultiTexParameterfv(GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
void glshim_glGetMultiTexParameteriv(GLenum texunit, GLenum target, GLenum pname, GLint *params);
void glshim_glGetMultiTexLevelParameterfv(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat *params);
void glshim_glGetMultiTexLevelParameteriv(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint *params);
void glshim_glMultiTexImage3D(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
void glshim_glMultiTexSubImage3D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
void glshim_glCopyMultiTexSubImage3D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);

void glshim_glCompressedTextureImage3D(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data);
void glshim_glCompressedTextureImage2D(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
void glshim_glCompressedTextureImage1D(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data);
void glshim_glCompressedTextureSubImage3D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data);
void glshim_glCompressedTextureSubImage2D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
void glshim_glCompressedTextureSubImage1D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data);
void glshim_glGetCompressedTextureImage(GLuint texture, GLenum target, GLint level, GLvoid *img);

void glshim_glCompressedMultiTexImage3D(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data);
void glshim_glCompressedMultiTexImage2D(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
void glshim_glCompressedMultiTexImage1D(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data);
void glshim_glCompressedMultiTexSubImage3D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data);
void glshim_glCompressedMultiTexSubImage2D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
void glshim_glCompressedMultiTexSubImage1D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data);
void glshim_glGetCompressedMultiTexImage(GLenum texunit, GLenum target, GLint level, GLvoid *img);

void glshim_glMatrixLoadTransposef(GLenum matrixMode, const GLfloat *m);
void glshim_glMatrixLoadTransposed(GLenum matrixMode, const GLdouble *m);
void glshim_glMatrixMultTransposef(GLenum matrixMode, const GLfloat *m);
void glshim_glMatrixMultTransposed(GLenum matrixMode, const GLdouble *m);

#endif
