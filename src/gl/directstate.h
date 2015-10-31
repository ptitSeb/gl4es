#ifndef __DIRECTSTATE_H_
#define __DIRECTSTATE_H_

#include "gl.h"

void glClientAttribDefaultEXT(GLbitfield mask);
void glPushClientAttribDefaultEXT(GLbitfield mask);

void glMatrixLoadfEXT(GLenum matrixMode, const GLfloat *m);
void glMatrixLoaddEXT(GLenum matrixMode, const GLdouble *m);
void glMatrixMultfEXT(GLenum matrixMode, const GLfloat *m);
void glMatrixMultdEXT(GLenum matrixMode, const GLdouble *m);
void glMatrixLoadIdentityEXT(GLenum matrixMode);
void glMatrixRotatefEXT(GLenum matrixMode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
void glMatrixRotatedEXT(GLenum matrixMode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
void glMatrixScalefEXT(GLenum matrixMode, GLfloat x, GLfloat y, GLfloat z);
void glMatrixScaledEXT(GLenum matrixMode, GLdouble x, GLdouble y, GLdouble z);
void glMatrixTranslatefEXT(GLenum matrixMode, GLfloat x, GLfloat y, GLfloat z);
void glMatrixTranslatedEXT(GLenum matrixMode, GLdouble x, GLdouble y, GLdouble z);
void glMatrixOrthoEXT(GLenum matrixMode, GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f);
void glMatrixFrustumEXT(GLenum matrixMode, GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f);
void glMatrixPushEXT(GLenum matrixMode);
void glMatrixPopEXT(GLenum matrixMode);

void glTextureParameteriEXT(GLuint texture, GLenum target, GLenum pname, GLint param);
void glTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, const GLint *param);
void glTextureParameterfEXT(GLuint texture, GLenum target, GLenum pname, GLfloat param);
void glTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, const GLfloat *param);
void glTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
void glTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
void glTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
void glTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
void glCopyTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
void glCopyTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void glCopyTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void glCopyTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glGetTextureImageEXT(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
void glGetTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat *params);
void glGetTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint *params);
void glGetTextureLevelParameterfvEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat *params);
void glGetTextureLevelParameterivEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLint *params);

void glTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
void glTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
void glCopyTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);

void glBindMultiTextureEXT(GLenum texunit, GLenum target, GLuint texture);
void glMultiTexCoordPointerEXT(GLenum texunit, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void glMultiTexEnvfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
void glMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
void glMultiTexEnviEXT(GLenum texunit, GLenum target, GLenum pname, GLint param);
void glMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint *params);
void glMultiTexGendEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
void glMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLdouble *params);
void glMultiTexGenfEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
void glMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLfloat *params);
void glMultiTexGeniEXT(GLenum texunit, GLenum coord, GLenum pname, GLint param);
void glMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, const GLint *params);
void glGetMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
void glGetMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint *params);
void glGetMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble *params);
void glGetMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat *params);
void glGetMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint *params);
void glMultiTexParameteriEXT(GLenum texunit, GLenum target, GLenum pname, GLint param);
void glMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint *param);
void glMultiTexParameterfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
void glMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat *param);
void glMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
void glMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
void glMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
void glMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
void glCopyMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
void glCopyMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void glCopyMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void glCopyMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glGetMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
void glGetMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
void glGetMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint *params);
void glGetMultiTexLevelParameterfvEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat *params);
void glGetMultiTexLevelParameterivEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint *params);
void glMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
void glMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels);
void glCopyMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);

void glCompressedTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data);
void glCompressedTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
void glCompressedTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data);
void glCompressedTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data);
void glCompressedTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
void glCompressedTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data);
void glGetCompressedTextureImageEXT(GLuint texture, GLenum target, GLint level, GLvoid *img);

void glCompressedMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data);
void glCompressedMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data);
void glCompressedMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data);
void glCompressedMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data);
void glCompressedMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data);
void glCompressedMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data);
void glGetCompressedMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLvoid *img);

void glMatrixLoadTransposefEXT(GLenum matrixMode, const GLfloat *m);
void glMatrixLoadTransposedEXT(GLenum matrixMode, const GLdouble *m);
void glMatrixMultTransposefEXT(GLenum matrixMode, const GLfloat *m);
void glMatrixMultTransposedEXT(GLenum matrixMode, const GLdouble *m);

#endif
