#include "directstate.h"

#include <stdio.h>

#include "wrap/gl4es.h"
#include "gles.h"
#include "stack.h"
#include "texgen.h"
#include "debug.h"

//#define DEBUG
#ifdef DEBUG
#define DBG(a) a
#else
#define DBG(a)
#endif

// Client State
void gl4es_glClientAttribDefault(GLbitfield mask) {
    if (mask & GL_CLIENT_PIXEL_STORE_BIT) {
        gl4es_glPixelStorei(GL_PACK_ALIGNMENT, 0);
        gl4es_glPixelStorei(GL_UNPACK_ALIGNMENT, 0);
        gl4es_glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
        gl4es_glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
        gl4es_glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
        gl4es_glPixelStorei(GL_PACK_ROW_LENGTH, 0);
        gl4es_glPixelStorei(GL_PACK_SKIP_PIXELS, 0);
        gl4es_glPixelStorei(GL_PACK_SKIP_ROWS, 0);
    }
#define enable_disable(pname, enabled)             \
    if (enabled) gl4es_glEnableClientState(pname);       \
    else gl4es_glDisableClientState(pname)

    if (mask & GL_CLIENT_VERTEX_ARRAY_BIT) {
        int client = glstate->texture.client;
        
        enable_disable(GL_VERTEX_ARRAY, false);
        enable_disable(GL_NORMAL_ARRAY, false);
        enable_disable(GL_COLOR_ARRAY, false);
        enable_disable(GL_SECONDARY_COLOR_ARRAY, false);
        for (int a=0; a<MAX_TEX; a++) {
           gl4es_glClientActiveTexture(GL_TEXTURE0+a);
           enable_disable(GL_TEXTURE_COORD_ARRAY, false);
        }
#undef enable_disable
        if (glstate->texture.client != client) gl4es_glClientActiveTexture(GL_TEXTURE0+client);
    }
}
void gl4es_glPushClientAttribDefault(GLbitfield mask) {
    gl4es_glPushClientAttrib(mask);
    gl4es_glClientAttribDefault(mask);
}

// Matrix
#define mat(f) \
  GLenum old_mat; \
  gl4es_glGetIntegerv(GL_MATRIX_MODE, &old_mat); \
  gl4es_glMatrixMode(matrixMode); \
  gl4es_##f; \
  gl4es_glMatrixMode(old_mat)
  
void gl4es_glMatrixLoadf(GLenum matrixMode, const GLfloat *m) {
    mat(glLoadMatrixf(m));
}
void gl4es_glMatrixLoadd(GLenum matrixMode, const GLdouble *m) {
    mat(glLoadMatrixd(m));
}
void gl4es_glMatrixMultf(GLenum matrixMode, const GLfloat *m) {
    mat(glMultMatrixf(m));
}
void gl4es_glMatrixMultd(GLenum matrixMode, const GLdouble *m) {
        mat(glMultMatrixd(m));
}
void gl4es_glMatrixLoadIdentity(GLenum matrixMode) {
        mat(glLoadIdentity());
}
void gl4es_glMatrixRotatef(GLenum matrixMode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
    mat(glRotatef(angle, x, y, z));
}
void gl4es_glMatrixRotated(GLenum matrixMode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
    mat(glRotated(angle, x, y, z));
}
void gl4es_glMatrixScalef(GLenum matrixMode, GLfloat x, GLfloat y, GLfloat z) {
    mat(glScalef(x, y, z));
}
void gl4es_glMatrixScaled(GLenum matrixMode, GLdouble x, GLdouble y, GLdouble z) {
    mat(glScaled(x, y, z));
}
void gl4es_glMatrixTranslatef(GLenum matrixMode, GLfloat x, GLfloat y, GLfloat z) {
    mat(glTranslatef(x, y, z));
}
void gl4es_glMatrixTranslated(GLenum matrixMode, GLdouble x, GLdouble y, GLdouble z) {
    mat(glTranslated(x, y, z));
}
void gl4es_glMatrixOrtho(GLenum matrixMode, GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f) {
    mat(glOrtho(l, r, b ,t, n, f));
}
void gl4es_glMatrixFrustum(GLenum matrixMode, GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f) {
    mat(glFrustum(l, r, b, t, n, f));
}
void gl4es_glMatrixPush(GLenum matrixMode) {
    mat(glPushMatrix());
}
void gl4es_glMatrixPop(GLenum matrixMode) {
    mat(glPopMatrix());
}
void gl4es_glMatrixLoadTransposef(GLenum matrixMode, const GLfloat *m) {
    mat(glLoadTransposeMatrixf(m));
}
void gl4es_glMatrixLoadTransposed(GLenum matrixMode, const GLdouble *m) {
    mat(glLoadTransposeMatrixd(m));
}
void gl4es_glMatrixMultTransposef(GLenum matrixMode, const GLfloat *m) {
    mat(glMultTransposeMatrixf(m));
}
void gl4es_glMatrixMultTransposed(GLenum matrixMode, const GLdouble *m) {
    mat(glMultTransposeMatrixd(m));
}
#undef mat

// Textures
#define text(f) \
  gl4es_glBindTexture(target, texture); \
  gl4es_##f

void gl4es_glTextureParameteri(GLuint texture, GLenum target, GLenum pname, GLint param) {
    text(glTexParameteri(target, pname, param));
}
void gl4es_glTextureParameteriv(GLuint texture, GLenum target, GLenum pname, const GLint *param) {
    text(glTexParameteriv(target, pname, param));
}
void gl4es_glTextureParameterf(GLuint texture, GLenum target, GLenum pname, GLfloat param) {
    text(glTexParameterf(target, pname, param));
}
void gl4es_glTextureParameterfv(GLuint texture, GLenum target, GLenum pname, const GLfloat *param) {
    text(glTexParameterfv(target, pname, param));
}
void gl4es_glTextureImage1D(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexImage1D(target, level, internalformat, width, border, format, type, pixels));
}
void gl4es_glTextureImage2D(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels));
}
void gl4es_glTextureSubImage1D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexSubImage1D(target, level, xoffset, width, format, type, pixels));
}
void gl4es_glTextureSubImage2D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels));
}
void gl4es_glCopyTextureImage1D(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
    text(glCopyTexImage1D(target, level, internalformat, x, y, width, border));
}
void gl4es_glCopyTextureImage2D(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    text(glCopyTexImage2D(target, level, internalformat, x, y, width, height, border));
}
void gl4es_glCopyTextureSubImage1D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    text(glCopyTexSubImage1D(target, level, xoffset, x, y, width));
}
void gl4es_glCopyTextureSubImage2D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    text(glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height));
}
void gl4es_glGetTextureImage(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels) {
    text(glGetTexImage(target, level, format, type, pixels));
}
void gl4es_glGetTextureParameterfv(GLuint texture, GLenum target, GLenum pname, GLfloat *params) {
    text(glGetTexParameterfv(target, pname, params));
}
void gl4es_glGetTextureParameteriv(GLuint texture, GLenum target, GLenum pname, GLint *params) {
    text(glGetTexParameteriv(target, pname, params));
}
void gl4es_glGetTextureLevelParameterfv(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat *params) {
    text(glGetTexLevelParameterfv(target, level, pname, params));
}
void gl4es_glGetTextureLevelParameteriv(GLuint texture, GLenum target, GLint level, GLenum pname, GLint *params) {
    text(glGetTexLevelParameteriv(target, level, pname, params));
}

// Texture 3D
void gl4es_glTextureImage3D(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels));
}
void gl4es_glTextureSubImage3D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels));
}
void gl4es_glCopyTextureSubImage3D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    text(glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height));
}
// Compressed texture
void gl4es_glCompressedTextureImage3D(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data));
}
void gl4es_glCompressedTextureImage2D(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data));
}
void gl4es_glCompressedTextureImage1D(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data));
}
void gl4es_glCompressedTextureSubImage3D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data));
}
void gl4es_glCompressedTextureSubImage2D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data));
}
void gl4es_glCompressedTextureSubImage1D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data));
}
void gl4es_glGetCompressedTextureImage(GLuint texture, GLenum target, GLint level, GLvoid *img) {
    text(glGetCompressedTexImage(target, level, img));
}

#undef text
#define text(f) \
  GLenum old_tex = glstate->texture.active; \
  if(texunit != old_tex) gl4es_glActiveTexture(texunit); \
  gl4es_##f; \
  if(texunit != old_tex) gl4es_glActiveTexture(old_tex)
#define texc(f) \
  GLenum old_tex = glstate->texture.client; \
  if(texunit != old_tex) gl4es_glClientActiveTexture(texunit); \
  gl4es_##f; \
  if(texunit != old_tex) gl4es_glClientActiveTexture(old_tex)

void gl4es_glBindMultiTexture(GLenum texunit, GLenum target, GLuint texture) {
    text(glBindTexture(target, texture));
}
void gl4es_glMultiTexCoordPointer(GLenum texunit, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) {
    texc(glTexCoordPointer(size, type, stride, pointer));
}
void gl4es_glMultiTexEnvf(GLenum texunit, GLenum target, GLenum pname, GLfloat param) {
    text(glTexEnvf(target, pname, param));
}
void gl4es_glMultiTexEnvfv(GLenum texunit, GLenum target, GLenum pname, const GLfloat *params) {
    text(glTexEnvfv(target, pname, params));
}
void gl4es_glMultiTexEnvi(GLenum texunit, GLenum target, GLenum pname, GLint param) {
    text(glTexEnvi(target, pname, param));
}
void gl4es_glMultiTexEnviv(GLenum texunit, GLenum target, GLenum pname, const GLint *params) {
    text(glTexEnviv(target, pname, params));
}
void gl4es_glMultiTexGend(GLenum texunit, GLenum coord, GLenum pname, GLdouble param) {
    text(glTexGend(coord, pname, param));
}
void gl4es_glMultiTexGendv(GLenum texunit, GLenum coord, GLenum pname, const GLdouble *params) {
    text(glTexGendv(coord, pname, params));
}
void gl4es_glMultiTexGenf(GLenum texunit, GLenum coord, GLenum pname, GLfloat param) {
    text(glTexGenf(coord, pname, param));
}
void gl4es_glMultiTexGenfv(GLenum texunit, GLenum coord, GLenum pname, const GLfloat *params) {
    text(glTexGenfv(coord, pname, params));
}
void gl4es_glMultiTexGeni(GLenum texunit, GLenum coord, GLenum pname, GLint param) {
    text(glTexGeni(coord, pname, param));
}
void gl4es_glMultiTexGeniv(GLenum texunit, GLenum coord, GLenum pname, const GLint *params) {
    text(glTexGeniv(coord, pname, params));
}
void gl4es_glGetMultiTexEnvfv(GLenum texunit, GLenum target, GLenum pname, GLfloat *params) {
    text(glGetTexEnvfv(target, pname, params));
}
void gl4es_glGetMultiTexEnviv(GLenum texunit, GLenum target, GLenum pname, GLint *params) {
    text(glGetTexEnviv(target, pname, params));
}
void gl4es_glGetMultiTexGendv(GLenum texunit, GLenum coord, GLenum pname, GLdouble *params) {
    text(glGetTexGendv(coord, pname, params));
}
void gl4es_glGetMultiTexGenfv(GLenum texunit, GLenum coord, GLenum pname, GLfloat *params) {
    text(glGetTexGenfv(coord, pname, params));
}
void gl4es_glGetMultiTexGeniv(GLenum texunit, GLenum coord, GLenum pname, GLint *params) {
    text(glGetTexGeniv(coord, pname, params));
}
void gl4es_glMultiTexParameteri(GLenum texunit, GLenum target, GLenum pname, GLint param) {
    text(glTexParameteri(target, pname, param));
}
void gl4es_glMultiTexParameteriv(GLenum texunit, GLenum target, GLenum pname, const GLint *param) {
    text(glTexParameteriv(target, pname, param));
}
void gl4es_glMultiTexParameterf(GLenum texunit, GLenum target, GLenum pname, GLfloat param) {
    text(glTexParameterf(target, pname, param));
}
void gl4es_glMultiTexParameterfv(GLenum texunit, GLenum target, GLenum pname, const GLfloat *param) {
    text(glTexParameterfv(target, pname, param));
}
void gl4es_glMultiTexImage1D(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexImage1D(target, level, internalformat, width, border, format, type, pixels));
}
void gl4es_glMultiTexImage2D(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels));
}
void gl4es_glMultiTexSubImage1D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexSubImage1D(target, level, xoffset, width, format, type, pixels));
}
void gl4es_glMultiTexSubImage2D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels));
}
void gl4es_glCopyMultiTexImage1D(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
    text(glCopyTexImage1D(target, level, internalformat, x, y, width, border));
}
void gl4es_glCopyMultiTexImage2D(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    text(glCopyTexImage2D(target, level, internalformat, x, y, width, height, border));
}
void gl4es_glCopyMultiTexSubImage1D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    text(glCopyTexSubImage1D(target, level, xoffset, x, y, width));
}
void gl4es_glCopyMultiTexSubImage2D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    text(glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height));
}
void gl4es_glGetMultiTexImage(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels) {
    text(glGetTexImage(target, level, format, type, pixels));
}
void gl4es_glGetMultiTexParameterfv(GLenum texunit, GLenum target, GLenum pname, GLfloat *params) {
    text(glGetTexParameterfv(target, pname, params));
}
void gl4es_glGetMultiTexParameteriv(GLenum texunit, GLenum target, GLenum pname, GLint *params) {
    text(glGetTexParameteriv(target, pname, params));
}
void gl4es_glGetMultiTexLevelParameterfv(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat *params) {
    text(glGetTexLevelParameterfv(target, level, pname, params));
}
void gl4es_glGetMultiTexLevelParameteriv(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint *params) {
    text(glGetTexLevelParameteriv(target, level, pname, params));
}
void gl4es_glMultiTexImage3D(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels));
}
void gl4es_glMultiTexSubImage3D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels));
}
void gl4es_glCopyMultiTexSubImage3D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    text(glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height));
}
// Compressed texture
void gl4es_glCompressedMultiTexImage3D(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data));
}
void gl4es_glCompressedMultiTexImage2D(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data));
}
void gl4es_glCompressedMultiTexImage1D(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data));
}
void gl4es_glCompressedMultiTexSubImage3D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data));
}
void gl4es_glCompressedMultiTexSubImage2D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data));
}
void gl4es_glCompressedMultiTexSubImage1D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data));
}
void gl4es_glGetCompressedMultiTexImage(GLenum texunit, GLenum target, GLint level, GLvoid *img) {
    text(glGetCompressedTexImage(target, level, img));
}

void gl4es_glEnableClientStateIndexed(GLenum array, GLuint index) {
    DBG(printf("glEnableClientStateIndexed(%s, %d)\n", PrintEnum(array), index);)
    if (array == GL_TEXTURE_COORD_ARRAY) {
        int old = glstate->texture.client;
        if(old!=index) gl4es_glClientActiveTexture(GL_TEXTURE0+index);
        gl4es_glEnableClientState(array);
        if(old!=index) gl4es_glClientActiveTexture(GL_TEXTURE0+old);
        errorGL();
    } else {
        errorShim(GL_INVALID_ENUM);
    }
}
void gl4es_glEnableClientStatei(GLenum array, GLuint index) __attribute__((alias("gl4es_glEnableClientStateIndexed")));
void gl4es_glDisableClientStateIndexed(GLenum array, GLuint index) {
    DBG(printf("glDisableClientStateIndexed(%s, %d)\n", PrintEnum(array), index);)
    if (array == GL_TEXTURE_COORD_ARRAY) {
        int old = glstate->texture.client;
        if(old!=index) gl4es_glClientActiveTexture(GL_TEXTURE0+index);
        gl4es_glDisableClientState(array);
        if(old!=index) gl4es_glClientActiveTexture(GL_TEXTURE0+old);
        errorGL();
    } else {
        errorShim(GL_INVALID_ENUM);
    }
}
void gl4es_glDisableClientStatei(GLenum array, GLuint index) __attribute__((alias("gl4es_glDisableClientStateIndexed")));

void gl4es_glEnableVertexArray(GLuint vaobj, GLenum array) {
    DBG(printf("glEnableVertexArray(%d, %s)\n", vaobj, PrintEnum(array));)
    GLuint old = glstate->vao->array;
    gl4es_glBindVertexArray(vaobj);
    gl4es_glEnableClientState(array);
    gl4es_glBindVertexArray(old);
}
void gl4es_glDisableVertexArray(GLuint vaobj, GLenum array) {
    DBG(printf("glDisableVertexArray(%d, %s)\n", vaobj, PrintEnum(array));)
    GLuint old = glstate->vao->array;
    gl4es_glBindVertexArray(vaobj);
    gl4es_glDisableClientState(array);
    gl4es_glBindVertexArray(old);
}
void gl4es_glEnableVertexArrayAttrib(GLuint vaobj, GLuint index) {
    DBG(printf("glEnableVertexArrayAttrib(%d, %d)\n", vaobj, index);)
    GLuint old = glstate->vao->array;
    gl4es_glBindVertexArray(vaobj);
    gl4es_glEnableVertexAttribArray(index);
    gl4es_glBindVertexArray(old);
}
void gl4es_glDisableVertexArrayAttrib(GLuint vaobj, GLuint index) {
    DBG(printf("glDisableVertexArrayAttrib(%d, %d)\n", vaobj, index);)
    GLuint old = glstate->vao->array;
    gl4es_glBindVertexArray(vaobj);
    gl4es_glDisableVertexAttribArray(index);
    gl4es_glBindVertexArray(old);
}

#define GETXXX(XXX, xxx) \
void gl4es_glGet##XXX##Indexedv(GLenum target, GLuint index, GL##xxx *data) { \
    switch(target) { \
     case GL_PROGRAM_MATRIX_EXT: \
     case GL_TRANSPOSE_PROGRAM_MATRIX_EXT: \
     case GL_PROGRAM_MATRIX_STACK_DEPTH_EXT: \
        { \
            int old = glstate->matrix_mode; \
            gl4es_glMatrixMode(GL_MATRIX0_ARB+index); \
            switch(target) { \
             case GL_PROGRAM_MATRIX_EXT: \
                gl4es_glGet##XXX##v(GL_CURRENT_MATRIX_ARB, data); \
                break; \
            case GL_TRANSPOSE_PROGRAM_MATRIX_EXT: \
                gl4es_glGet##XXX##v(GL_TRANSPOSE_CURRENT_MATRIX_ARB, data); \
                break; \
            case GL_PROGRAM_MATRIX_STACK_DEPTH_EXT: \
                gl4es_glGet##XXX##v(GL_CURRENT_MATRIX_STACK_DEPTH_ARB, data); \
                break; \
            } \
            gl4es_glMatrixMode(old); \
        } \
        break; \
        case GL_CURRENT_RASTER_TEXTURE_COORDS: \
        case GL_CURRENT_TEXTURE_COORDS: \
        case GL_TEXTURE_BINDING_1D: \
        case GL_TEXTURE_BINDING_1D_ARRAY: \
        case GL_TEXTURE_BINDING_2D: \
        case GL_TEXTURE_BINDING_2D_ARRAY: \
        case GL_TEXTURE_BINDING_3D: \
        case GL_TEXTURE_BINDING_BUFFER_EXT: \
        case GL_TEXTURE_BINDING_CUBE_MAP: \
        case GL_TEXTURE_BINDING_RECTANGLE_ARB: \
        case GL_TEXTURE_BUFFER_DATA_STORE_BINDING_EXT: \
        case GL_TEXTURE_BUFFER_FORMAT_EXT: \
        case GL_TEXTURE_GEN_Q: \
        case GL_TEXTURE_GEN_R: \
        case GL_TEXTURE_GEN_S: \
        case GL_TEXTURE_GEN_T: \
        case GL_TEXTURE_MATRIX: \
        case GL_TEXTURE_STACK_DEPTH: \
        case GL_TRANSPOSE_TEXTURE_MATRIX: \
        case GL_TEXTURE_1D: \
        case GL_TEXTURE_2D: \
        case GL_TEXTURE_3D: \
        case GL_TEXTURE_CUBE_MAP: \
        case GL_TEXTURE_RECTANGLE_ARB: \
        { \
            int old = glstate->texture.active; \
            if(old!=index+GL_TEXTURE0) gl4es_glActiveTexture(index+GL_TEXTURE0); \
            gl4es_glGet##XXX##v(target, data); \
            if(old!=index+GL_TEXTURE0) gl4es_glActiveTexture(old); \
        } \
        break; \
        case GL_TEXTURE_COORD_ARRAY: \
        case GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING: \
        case GL_TEXTURE_COORD_ARRAY_COUNT: \
        case GL_TEXTURE_COORD_ARRAY_SIZE: \
        case GL_TEXTURE_COORD_ARRAY_STRIDE: \
        case GL_TEXTURE_COORD_ARRAY_TYPE: \
        { \
            int old = glstate->texture.client; \
            if(old!=index) gl4es_glClientActiveTexture(index+GL_TEXTURE0); \
            gl4es_glGet##XXX##v(target, data); \
            if(old!=index) gl4es_glClientActiveTexture(old+GL_TEXTURE0); \
        } \
        break; \
        default: \
            gl4es_glGet##XXX##v(target, data); \
    } \
}

GETXXX(Float, float);
GETXXX(Double, double);
GETXXX(Integer, int);
GETXXX(Boolean, boolean);
#undef GETXXX

void gl4es_glGetPointerIndexedv(GLenum pname, GLuint index, GLvoid **params) {
    int old = glstate->texture.client;
    if(old!=index) gl4es_glClientActiveTexture(index+GL_TEXTURE0);
    gl4es_glGetPointerv(pname, params);
    if(old!=index) gl4es_glClientActiveTexture(old+GL_TEXTURE0);
    
}

void gl4es_glEnableIndexed(GLenum cap, GLuint index) {
    DBG(printf("glEnableIndexed(%s, %d)\n", PrintEnum(cap), index);)
    int old = glstate->texture.active;
    if(old!=index) gl4es_glActiveTexture(index+GL_TEXTURE0);
    gl4es_glEnable(cap);
    if(old!=index) gl4es_glActiveTexture(old);
}

void gl4es_glDisableIndexed(GLenum cap, GLuint index) {
    DBG(printf("glDisableIndexed(%s, %d)\n", PrintEnum(cap), index);)
    int old = glstate->texture.active;
    if(old!=index) gl4es_glActiveTexture(index+GL_TEXTURE0);
    gl4es_glDisable(cap);
    if(old!=index) gl4es_glActiveTexture(old);
}

GLboolean gl4es_glIsEnabledIndexed(GLenum cap, GLuint index) {
    DBG(printf("glIsEnabledIndexed(%s, %d)\n", PrintEnum(cap), index);)
    int old;
    GLboolean rv;
    switch(cap) {
        case GL_TEXTURE_1D:
        case GL_TEXTURE_2D:
        case GL_TEXTURE_3D:
        case GL_TEXTURE_CUBE_MAP:
        case GL_TEXTURE_RECTANGLE_ARB:
        case GL_TEXTURE_GEN_S:
        case GL_TEXTURE_GEN_T:
        case GL_TEXTURE_GEN_R:
        case GL_TEXTURE_GEN_Q:
            old = glstate->texture.active;
            if(old!=index) gl4es_glActiveTexture(index+GL_TEXTURE0);
            rv = gl4es_glIsEnabled(cap);
            if(old!=index) gl4es_glActiveTexture(old);
            return rv;
        case GL_TEXTURE_COORD_ARRAY:
            old = glstate->texture.client;
            if(old!=index) gl4es_glClientActiveTexture(index+GL_TEXTURE0);
            rv = gl4es_glIsEnabled(cap);
            if(old!=index) gl4es_glClientActiveTexture(old+GL_TEXTURE0);
            return rv;
    }
    return gl4es_glIsEnabled(cap);
}

//EXT wrapper
void glClientAttribDefaultEXT(GLbitfield mask) AliasExport("gl4es_glClientAttribDefault");
void glPushClientAttribDefaultEXT(GLbitfield mask) AliasExport("gl4es_glPushClientAttribDefault");
void glMatrixLoadfEXT(GLenum matrixMode, const GLfloat *m) AliasExport("gl4es_glMatrixLoadf");
void glMatrixLoaddEXT(GLenum matrixMode, const GLdouble *m) AliasExport("gl4es_glMatrixLoadd");
void glMatrixMultfEXT(GLenum matrixMode, const GLfloat *m) AliasExport("gl4es_glMatrixMultf");
void glMatrixMultdEXT(GLenum matrixMode, const GLdouble *m) AliasExport("gl4es_glMatrixMultd");
void glMatrixLoadIdentityEXT(GLenum matrixMode) AliasExport("gl4es_glMatrixLoadIdentity");
void glMatrixRotatefEXT(GLenum matrixMode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z) AliasExport("gl4es_glMatrixRotatef");
void glMatrixRotatedEXT(GLenum matrixMode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z) AliasExport("gl4es_glMatrixRotated");
void glMatrixScalefEXT(GLenum matrixMode, GLfloat x, GLfloat y, GLfloat z) AliasExport("gl4es_glMatrixScalef");
void glMatrixScaledEXT(GLenum matrixMode, GLdouble x, GLdouble y, GLdouble z) AliasExport("gl4es_glMatrixScaled");
void glMatrixTranslatefEXT(GLenum matrixMode, GLfloat x, GLfloat y, GLfloat z) AliasExport("gl4es_glMatrixTranslatef");
void glMatrixTranslatedEXT(GLenum matrixMode, GLdouble x, GLdouble y, GLdouble z) AliasExport("gl4es_glMatrixTranslated");
void glMatrixOrthoEXT(GLenum matrixMode, GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f) AliasExport("gl4es_glMatrixOrtho");
void glMatrixFrustumEXT(GLenum matrixMode, GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f) AliasExport("gl4es_glMatrixFrustum");
void glMatrixPushEXT(GLenum matrixMode) AliasExport("gl4es_glMatrixPush");
void glMatrixPopEXT(GLenum matrixMode) AliasExport("gl4es_glMatrixPop");
void glTextureParameteriEXT(GLuint texture, GLenum target, GLenum pname, GLint param) AliasExport("gl4es_glTextureParameteri");
void glTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, const GLint *param) AliasExport("gl4es_glTextureParameteriv");
void glTextureParameterfEXT(GLuint texture, GLenum target, GLenum pname, GLfloat param) AliasExport("gl4es_glTextureParameterf");
void glTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, const GLfloat *param) AliasExport("gl4es_glTextureParameterfv");
void glTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels) AliasExport("gl4es_glTextureImage1D");
void glTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) AliasExport("gl4es_glTextureImage2D");
void glTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels) AliasExport("gl4es_glTextureSubImage1D");
void glTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels) AliasExport("gl4es_glTextureSubImage2D");
void glCopyTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) AliasExport("gl4es_glCopyTextureImage1D");
void glCopyTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) AliasExport("gl4es_glCopyTextureImage2D");
void glCopyTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) AliasExport("gl4es_glCopyTextureSubImage1D");
void glCopyTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) AliasExport("gl4es_glCopyTextureSubImage2D");
void glGetTextureImageEXT(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels) AliasExport("gl4es_glGetTextureImage");
void glGetTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat *params) AliasExport("gl4es_glGetTextureParameterfv");
void glGetTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint *params) AliasExport("gl4es_glGetTextureParameteriv");
void glGetTextureLevelParameterfvEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat *params) AliasExport("gl4es_glGetTextureLevelParameterfv");
void glGetTextureLevelParameterivEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLint *params) AliasExport("gl4es_glGetTextureLevelParameteriv");
void glTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels) AliasExport("gl4es_glTextureImage3D");
void glTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels) AliasExport("gl4es_glTextureSubImage3D");
void glCopyTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) AliasExport("gl4es_glCopyTextureSubImage3D");
void glBindMultiTextureEXT(GLenum texunit, GLenum target, GLuint texture) AliasExport("gl4es_glBindMultiTexture");
void glMultiTexCoordPointerEXT(GLenum texunit, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) AliasExport("gl4es_glMultiTexCoordPointer");
void glMultiTexEnvfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param) AliasExport("gl4es_glMultiTexEnvf");
void glMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat *params) AliasExport("gl4es_glMultiTexEnvfv");
void glMultiTexEnviEXT(GLenum texunit, GLenum target, GLenum pname, GLint param) AliasExport("gl4es_glMultiTexEnvi");
void glMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint *params) AliasExport("gl4es_glMultiTexEnviv");
void glMultiTexGendEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble param) AliasExport("gl4es_glMultiTexGend");
void glMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLdouble *params) AliasExport("gl4es_glMultiTexGendv");
void glMultiTexGenfEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat param) AliasExport("gl4es_glMultiTexGenf");
void glMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLfloat *params) AliasExport("gl4es_glMultiTexGenfv");
void glMultiTexGeniEXT(GLenum texunit, GLenum coord, GLenum pname, GLint param) AliasExport("gl4es_glMultiTexGeni");
void glMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, const GLint *params) AliasExport("gl4es_glMultiTexGeniv");
void glGetMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat *params) AliasExport("gl4es_glGetMultiTexEnvfv");
void glGetMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint *params) AliasExport("gl4es_glGetMultiTexEnviv");
void glGetMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble *params) AliasExport("gl4es_glGetMultiTexGendv");
void glGetMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat *params) AliasExport("gl4es_glGetMultiTexGenfv");
void glGetMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint *params) AliasExport("gl4es_glGetMultiTexGeniv");
void glMultiTexParameteriEXT(GLenum texunit, GLenum target, GLenum pname, GLint param) AliasExport("gl4es_glMultiTexParameteri");
void glMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint *param) AliasExport("gl4es_glMultiTexParameteriv");
void glMultiTexParameterfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param) AliasExport("gl4es_glMultiTexParameterf");
void glMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat *param) AliasExport("gl4es_glMultiTexParameterfv");
void glMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels) AliasExport("gl4es_glMultiTexImage1D");
void glMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) AliasExport("gl4es_glMultiTexImage2D");
void glMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels) AliasExport("gl4es_glMultiTexSubImage1D");
void glMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels) AliasExport("gl4es_glMultiTexSubImage2D");
void glCopyMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) AliasExport("gl4es_glCopyMultiTexImage1D");
void glCopyMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) AliasExport("gl4es_glCopyMultiTexImage2D");
void glCopyMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) AliasExport("gl4es_glCopyMultiTexSubImage1D");
void glCopyMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) AliasExport("gl4es_glCopyMultiTexSubImage2D");
void glGetMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels) AliasExport("gl4es_glGetMultiTexImage");
void glGetMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat *params) AliasExport("gl4es_glGetMultiTexParameterfv");
void glGetMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint *params) AliasExport("gl4es_glGetMultiTexParameteriv");
void glGetMultiTexLevelParameterfvEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat *params) AliasExport("gl4es_glGetMultiTexLevelParameterfv");
void glGetMultiTexLevelParameterivEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint *params) AliasExport("gl4es_glGetMultiTexLevelParameteriv");
void glMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels) AliasExport("gl4es_glMultiTexImage3D");
void glMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels) AliasExport("gl4es_glMultiTexSubImage3D");
void glCopyMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) AliasExport("gl4es_glCopyMultiTexSubImage3D");
void glCompressedTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTextureImage3D");
void glCompressedTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTextureImage2D");
void glCompressedTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTextureImage1D");
void glCompressedTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTextureSubImage3D");
void glCompressedTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTextureSubImage2D");
void glCompressedTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTextureSubImage1D");
void glGetCompressedTextureImageEXT(GLuint texture, GLenum target, GLint level, GLvoid *img) AliasExport("gl4es_glGetCompressedTextureImage");
void glCompressedMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedMultiTexImage3D");
void glCompressedMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedMultiTexImage2D");
void glCompressedMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedMultiTexImage1D");
void glCompressedMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedMultiTexSubImage3D");
void glCompressedMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedMultiTexSubImage2D");
void glCompressedMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedMultiTexSubImage1D");
void glGetCompressedMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLvoid *img) AliasExport("gl4es_glGetCompressedMultiTexImage");
void glMatrixLoadTransposefEXT(GLenum matrixMode, const GLfloat *m) AliasExport("gl4es_glMatrixLoadTransposef");
void glMatrixLoadTransposedEXT(GLenum matrixMode, const GLdouble *m) AliasExport("gl4es_glMatrixLoadTransposed");
void glMatrixMultTransposefEXT(GLenum matrixMode, const GLfloat *m) AliasExport("gl4es_glMatrixMultTransposef");
void glMatrixMultTransposedEXT(GLenum matrixMode, const GLdouble *m) AliasExport("gl4es_glMatrixMultTransposed");
void glEnableClientStateIndexedEXT(GLenum array, GLuint index) AliasExport("gl4es_glEnableClientStateIndexed");
void glDisableClientStateIndexedEXT(GLenum array, GLuint index) AliasExport("gl4es_glDisableClientStateIndexed");
void glEnableClientStateiEXT(GLenum array, GLuint index) AliasExport("gl4es_glEnableClientStateIndexed");
void glDisableClientStateiEXT(GLenum array, GLuint index) AliasExport("gl4es_glDisableClientStateIndexed");
void glEnableVertexArrayEXT(GLuint vaobj, GLenum array) AliasExport("gl4es_glEnableVertexArray");
void glDisableVertexArrayEXT(GLuint vaobj, GLenum array) AliasExport("gl4es_glDisableVertexArray");
void glEnableVertexArrayAttribEXT(GLuint vaobj, GLuint index) AliasExport("gl4es_glEnableVertexArrayAttrib");
void glDisableVertexArrayAttribEXT(GLuint vaobj, GLuint index) AliasExport("gl4es_glDisableVertexArrayAttrib");
void glGetPointerIndexedvEXT(GLenum pname, GLuint index, GLvoid **params) AliasExport("gl4es_glGetPointerIndexedv");
void glGetFloatIndexedvEXT(GLenum target, GLuint index, GLfloat *data) AliasExport("gl4es_glGetFloatIndexedv");
void glGetDoubleIndexedvEXT(GLenum target, GLuint index, GLdouble *data) AliasExport("gl4es_glGetDoubleIndexedv");
void glGetIntegerIndexedvEXT(GLenum target, GLuint index, GLint *data) AliasExport("gl4es_glGetIntegerIndexedv");
void glGetBooleanIndexedvEXT(GLenum target, GLuint index, GLboolean *data) AliasExport("gl4es_glGetBooleanIndexedv");
void glEnableIndexedEXT(GLenum cap, GLuint index) AliasExport("gl4es_glEnableIndexed");
void glDisableIndexedEXT(GLenum cap, GLuint index) AliasExport("gl4es_glDisableIndexed");
GLboolean glIsEnabledIndexedEXT(GLenum cap, GLuint index) AliasExport("gl4es_glIsEnabledIndexed");
#undef text
#undef texc
