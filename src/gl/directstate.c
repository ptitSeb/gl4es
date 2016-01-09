#include "directstate.h"
#include "gl.h"
#include "stack.h"

// Client State
void glshim_glClientAttribDefault(GLbitfield mask) {
    if (mask & GL_CLIENT_PIXEL_STORE_BIT) {
        glshim_glPixelStorei(GL_PACK_ALIGNMENT, 0);
        glshim_glPixelStorei(GL_UNPACK_ALIGNMENT, 0);
        glshim_glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
        glshim_glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
        glshim_glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
        glshim_glPixelStorei(GL_PACK_ROW_LENGTH, 0);
        glshim_glPixelStorei(GL_PACK_SKIP_PIXELS, 0);
        glshim_glPixelStorei(GL_PACK_SKIP_ROWS, 0);
    }
#define enable_disable(pname, enabled)             \
    if (enabled) glshim_glEnableClientState(pname);       \
    else glshim_glDisableClientState(pname)

    if (mask & GL_CLIENT_VERTEX_ARRAY_BIT) {
        int client = glstate.texture.client;
        
		enable_disable(GL_VERTEX_ARRAY, false);
		enable_disable(GL_NORMAL_ARRAY, false);
		enable_disable(GL_COLOR_ARRAY, false);
		enable_disable(GL_SECONDARY_COLOR_ARRAY, false);
        for (int a=0; a<MAX_TEX; a++) {
           glshim_glClientActiveTexture(GL_TEXTURE0+a);
           enable_disable(GL_TEXTURE_COORD_ARRAY, false);
        }
#undef enable_disable
		if (glstate.texture.client != client) glshim_glClientActiveTexture(GL_TEXTURE0+client);
    }
}
void glshim_glPushClientAttribDefault(GLbitfield mask) {
    glshim_glPushClientAttrib(mask);
    glshim_glClientAttribDefault(mask);
}

// Matrix
#define mat(f) \
  GLenum old_mat; \
  glshim_glGetIntegerv(GL_MATRIX_MODE, &old_mat); \
  glshim_glMatrixMode(matrixMode); \
  glshim_##f; \
  glshim_glMatrixMode(old_mat)
  
void glshim_glMatrixLoadf(GLenum matrixMode, const GLfloat *m) {
    mat(glLoadMatrixf(m));
}
void glshim_glMatrixLoadd(GLenum matrixMode, const GLdouble *m) {
    mat(glLoadMatrixd(m));
}
void glshim_glMatrixMultf(GLenum matrixMode, const GLfloat *m) {
    mat(glMultMatrixf(m));
}
void glshim_glMatrixMultd(GLenum matrixMode, const GLdouble *m) {
        mat(glMultMatrixd(m));
}
void glshim_glMatrixLoadIdentity(GLenum matrixMode) {
        mat(glLoadIdentity());
}
void glshim_glMatrixRotatef(GLenum matrixMode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
    mat(glRotatef(angle, x, y, z));
}
void glshim_glMatrixRotated(GLenum matrixMode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
    mat(glRotated(angle, x, y, z));
}
void glshim_glMatrixScalef(GLenum matrixMode, GLfloat x, GLfloat y, GLfloat z) {
    mat(glScalef(x, y, z));
}
void glshim_glMatrixScaled(GLenum matrixMode, GLdouble x, GLdouble y, GLdouble z) {
    mat(glScaled(x, y, z));
}
void glshim_glMatrixTranslatef(GLenum matrixMode, GLfloat x, GLfloat y, GLfloat z) {
    mat(glTranslatef(x, y, z));
}
void glshim_glMatrixTranslated(GLenum matrixMode, GLdouble x, GLdouble y, GLdouble z) {
    mat(glTranslated(x, y, z));
}
void glshim_glMatrixOrtho(GLenum matrixMode, GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f) {
    mat(glOrtho(l, r, b ,t, n, f));
}
void glshim_glMatrixFrustum(GLenum matrixMode, GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f) {
    mat(glFrustum(l, r, b, t, n, f));
}
void glshim_glMatrixPush(GLenum matrixMode) {
    mat(glPushMatrix());
}
void glshim_glMatrixPop(GLenum matrixMode) {
    mat(glPopMatrix());
}
void glshim_glMatrixLoadTransposef(GLenum matrixMode, const GLfloat *m) {
    mat(glLoadTransposeMatrixf(m));
}
void glshim_glMatrixLoadTransposed(GLenum matrixMode, const GLdouble *m) {
    mat(glLoadTransposeMatrixd(m));
}
void glshim_glMatrixMultTransposef(GLenum matrixMode, const GLfloat *m) {
    mat(glMultTransposeMatrixf(m));
}
void glshim_glMatrixMultTransposed(GLenum matrixMode, const GLdouble *m) {
    mat(glMultTransposeMatrixd(m));
}
#undef mat

// Textures
#define text(f) \
  glshim_glBindTexture(target, texture); \
  glshim_##f

void glshim_glTextureParameteri(GLuint texture, GLenum target, GLenum pname, GLint param) {
    text(glTexParameteri(target, pname, param));
}
void glshim_glTextureParameteriv(GLuint texture, GLenum target, GLenum pname, const GLint *param) {
    text(glTexParameteriv(target, pname, param));
}
void glshim_glTextureParameterf(GLuint texture, GLenum target, GLenum pname, GLfloat param) {
    text(glTexParameterf(target, pname, param));
}
void glshim_glTextureParameterfv(GLuint texture, GLenum target, GLenum pname, const GLfloat *param) {
    text(glTexParameterfv(target, pname, param));
}
void glshim_glTextureImage1D(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexImage1D(target, level, internalformat, width, border, format, type, pixels));
}
void glshim_glTextureImage2D(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels));
}
void glshim_glTextureSubImage1D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexSubImage1D(target, level, xoffset, width, format, type, pixels));
}
void glshim_glTextureSubImage2D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels));
}
void glshim_glCopyTextureImage1D(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
    text(glCopyTexImage1D(target, level, internalformat, x, y, width, border));
}
void glshim_glCopyTextureImage2D(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    text(glCopyTexImage2D(target, level, internalformat, x, y, width, height, border));
}
void glshim_glCopyTextureSubImage1D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    text(glCopyTexSubImage1D(target, level, xoffset, x, y, width));
}
void glshim_glCopyTextureSubImage2D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    text(glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height));
}
void glshim_glGetTextureImage(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels) {
    text(glGetTexImage(target, level, format, type, pixels));
}
void glshim_glGetTextureParameterfv(GLuint texture, GLenum target, GLenum pname, GLfloat *params) {
    text(glGetTexParameterfv(target, pname, params));
}
void glshim_glGetTextureParameteriv(GLuint texture, GLenum target, GLenum pname, GLint *params) {
    text(glGetTexParameteriv(target, pname, params));
}
void glshim_glGetTextureLevelParameterfv(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat *params) {
    text(glGetTexLevelParameterfv(target, level, pname, params));
}
void glshim_glGetTextureLevelParameteriv(GLuint texture, GLenum target, GLint level, GLenum pname, GLint *params) {
    text(glGetTexLevelParameteriv(target, level, pname, params));
}

// Texture 3D
void glshim_glTextureImage3D(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels));
}
void glshim_glTextureSubImage3D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels));
}
void glshim_glCopyTextureSubImage3D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    text(glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height));
}
// Compressed texture
void glshim_glCompressedTextureImage3D(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data));
}
void glshim_glCompressedTextureImage2D(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data));
}
void glshim_glCompressedTextureImage1D(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data));
}
void glshim_glCompressedTextureSubImage3D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data));
}
void glshim_glCompressedTextureSubImage2D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data));
}
void glshim_glCompressedTextureSubImage1D(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data));
}
void glshim_glGetCompressedTextureImage(GLuint texture, GLenum target, GLint level, GLvoid *img) {
    text(glGetCompressedTexImage(target, level, img));
}

#undef text
#define text(f) \
  GLenum old_tex = glstate.texture.active; \
  if(texunit != old_tex) glshim_glActiveTexture(texunit); \
  glshim_##f; \
  if(texunit != old_tex) glshim_glActiveTexture(old_tex)
#define texc(f) \
  GLenum old_tex = glstate.texture.client; \
  if(texunit != old_tex) glshim_glClientActiveTexture(texunit); \
  glshim_##f; \
  if(texunit != old_tex) glshim_glClientActiveTexture(old_tex)

void glshim_glBindMultiTexture(GLenum texunit, GLenum target, GLuint texture) {
    text(glBindTexture(target, texture));
}
void glshim_glMultiTexCoordPointer(GLenum texunit, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) {
    texc(glTexCoordPointer(size, type, stride, pointer));
}
void glshim_glMultiTexEnvf(GLenum texunit, GLenum target, GLenum pname, GLfloat param) {
    text(glTexEnvf(target, pname, param));
}
void glshim_glMultiTexEnvfv(GLenum texunit, GLenum target, GLenum pname, const GLfloat *params) {
    text(glTexEnvfv(target, pname, params));
}
void glshim_glMultiTexEnvi(GLenum texunit, GLenum target, GLenum pname, GLint param) {
    text(glTexEnvi(target, pname, param));
}
void glshim_glMultiTexEnviv(GLenum texunit, GLenum target, GLenum pname, const GLint *params) {
    text(glTexEnviv(target, pname, params));
}
void glshim_glMultiTexGend(GLenum texunit, GLenum coord, GLenum pname, GLdouble param) {
    text(glTexGend(coord, pname, param));
}
void glshim_glMultiTexGendv(GLenum texunit, GLenum coord, GLenum pname, const GLdouble *params) {
    text(glTexGendv(coord, pname, params));
}
void glshim_glMultiTexGenf(GLenum texunit, GLenum coord, GLenum pname, GLfloat param) {
    text(glTexGenf(coord, pname, param));
}
void glshim_glMultiTexGenfv(GLenum texunit, GLenum coord, GLenum pname, const GLfloat *params) {
    text(glTexGenfv(coord, pname, params));
}
void glshim_glMultiTexGeni(GLenum texunit, GLenum coord, GLenum pname, GLint param) {
    text(glTexGeni(coord, pname, param));
}
void glshim_glMultiTexGeniv(GLenum texunit, GLenum coord, GLenum pname, const GLint *params) {
    text(glTexGeniv(coord, pname, params));
}
void glshim_glGetMultiTexEnvfv(GLenum texunit, GLenum target, GLenum pname, GLfloat *params) {
    text(glGetTexEnvfv(target, pname, params));
}
void glshim_glGetMultiTexEnviv(GLenum texunit, GLenum target, GLenum pname, GLint *params) {
    text(glGetTexEnviv(target, pname, params));
}
void glshim_glGetMultiTexGendv(GLenum texunit, GLenum coord, GLenum pname, GLdouble *params) {
    text(glGetTexGendv(coord, pname, params));
}
void glshim_glGetMultiTexGenfv(GLenum texunit, GLenum coord, GLenum pname, GLfloat *params) {
    text(glGetTexGenfv(coord, pname, params));
}
void glshim_glGetMultiTexGeniv(GLenum texunit, GLenum coord, GLenum pname, GLint *params) {
    text(glGetTexGeniv(coord, pname, params));
}
void glshim_glMultiTexParameteri(GLenum texunit, GLenum target, GLenum pname, GLint param) {
    text(glTexParameteri(target, pname, param));
}
void glshim_glMultiTexParameteriv(GLenum texunit, GLenum target, GLenum pname, const GLint *param) {
    text(glTexParameteriv(target, pname, param));
}
void glshim_glMultiTexParameterf(GLenum texunit, GLenum target, GLenum pname, GLfloat param) {
    text(glTexParameterf(target, pname, param));
}
void glshim_glMultiTexParameterfv(GLenum texunit, GLenum target, GLenum pname, const GLfloat *param) {
    text(glTexParameterfv(target, pname, param));
}
void glshim_glMultiTexImage1D(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexImage1D(target, level, internalformat, width, border, format, type, pixels));
}
void glshim_glMultiTexImage2D(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels));
}
void glshim_glMultiTexSubImage1D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexSubImage1D(target, level, xoffset, width, format, type, pixels));
}
void glshim_glMultiTexSubImage2D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels));
}
void glshim_glCopyMultiTexImage1D(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
    text(glCopyTexImage1D(target, level, internalformat, x, y, width, border));
}
void glshim_glCopyMultiTexImage2D(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    text(glCopyTexImage2D(target, level, internalformat, x, y, width, height, border));
}
void glshim_glCopyMultiTexSubImage1D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    text(glCopyTexSubImage1D(target, level, xoffset, x, y, width));
}
void glshim_glCopyMultiTexSubImage2D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    text(glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height));
}
void glshim_glGetMultiTexImage(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels) {
    text(glGetTexImage(target, level, format, type, pixels));
}
void glshim_glGetMultiTexParameterfv(GLenum texunit, GLenum target, GLenum pname, GLfloat *params) {
    text(glGetTexParameterfv(target, pname, params));
}
void glshim_glGetMultiTexParameteriv(GLenum texunit, GLenum target, GLenum pname, GLint *params) {
    text(glGetTexParameteriv(target, pname, params));
}
void glshim_glGetMultiTexLevelParameterfv(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat *params) {
    text(glGetTexLevelParameterfv(target, level, pname, params));
}
void glshim_glGetMultiTexLevelParameteriv(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint *params) {
    text(glGetTexLevelParameteriv(target, level, pname, params));
}
void glshim_glMultiTexImage3D(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels));
}
void glshim_glMultiTexSubImage3D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels));
}
void glshim_glCopyMultiTexSubImage3D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    text(glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height));
}
// Compressed texture
void glshim_glCompressedMultiTexImage3D(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data));
}
void glshim_glCompressedMultiTexImage2D(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data));
}
void glshim_glCompressedMultiTexImage1D(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data));
}
void glshim_glCompressedMultiTexSubImage3D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data));
}
void glshim_glCompressedMultiTexSubImage2D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data));
}
void glshim_glCompressedMultiTexSubImage1D(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data));
}
void glshim_glGetCompressedMultiTexImage(GLenum texunit, GLenum target, GLint level, GLvoid *img) {
    text(glGetCompressedTexImage(target, level, img));
}

//EXT wrapper
void glClientAttribDefaultEXT(GLbitfield mask) __attribute__((alias("glshim_glClientAttribDefault")));
void glPushClientAttribDefaultEXT(GLbitfield mask) __attribute__((alias("glshim_glPushClientAttribDefault")));
void glMatrixLoadfEXT(GLenum matrixMode, const GLfloat *m) __attribute__((alias("glshim_glMatrixLoadf")));
void glMatrixLoaddEXT(GLenum matrixMode, const GLdouble *m) __attribute__((alias("glshim_glMatrixLoadd")));
void glMatrixMultfEXT(GLenum matrixMode, const GLfloat *m) __attribute__((alias("glshim_glMatrixMultf")));
void glMatrixMultdEXT(GLenum matrixMode, const GLdouble *m) __attribute__((alias("glshim_glMatrixMultd")));
void glMatrixLoadIdentityEXT(GLenum matrixMode) __attribute__((alias("glshim_glMatrixLoadIdentity")));
void glMatrixRotatefEXT(GLenum matrixMode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z) __attribute__((alias("glshim_glMatrixRotatef")));
void glMatrixRotatedEXT(GLenum matrixMode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z) __attribute__((alias("glshim_glMatrixRotated")));
void glMatrixScalefEXT(GLenum matrixMode, GLfloat x, GLfloat y, GLfloat z) __attribute__((alias("glshim_glMatrixScalef")));
void glMatrixScaledEXT(GLenum matrixMode, GLdouble x, GLdouble y, GLdouble z) __attribute__((alias("glshim_glMatrixScaled")));
void glMatrixTranslatefEXT(GLenum matrixMode, GLfloat x, GLfloat y, GLfloat z) __attribute__((alias("glshim_glMatrixTranslatef")));
void glMatrixTranslatedEXT(GLenum matrixMode, GLdouble x, GLdouble y, GLdouble z) __attribute__((alias("glshim_glMatrixTranslated")));
void glMatrixOrthoEXT(GLenum matrixMode, GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f) __attribute__((alias("glshim_glMatrixOrtho")));
void glMatrixFrustumEXT(GLenum matrixMode, GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f) __attribute__((alias("glshim_glMatrixFrustum")));
void glMatrixPushEXT(GLenum matrixMode) __attribute__((alias("glshim_glMatrixPush")));
void glMatrixPopEXT(GLenum matrixMode) __attribute__((alias("glshim_glMatrixPop")));
void glTextureParameteriEXT(GLuint texture, GLenum target, GLenum pname, GLint param) __attribute__((alias("glshim_glTextureParameteri")));
void glTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, const GLint *param) __attribute__((alias("glshim_glTextureParameteriv")));
void glTextureParameterfEXT(GLuint texture, GLenum target, GLenum pname, GLfloat param) __attribute__((alias("glshim_glTextureParameterf")));
void glTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, const GLfloat *param) __attribute__((alias("glshim_glTextureParameterfv")));
void glTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels) __attribute__((alias("glshim_glTextureImage1D")));
void glTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) __attribute__((alias("glshim_glTextureImage2D")));
void glTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels) __attribute__((alias("glshim_glTextureSubImage1D")));
void glTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels) __attribute__((alias("glshim_glTextureSubImage2D")));
void glCopyTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) __attribute__((alias("glshim_glCopyTextureImage1D")));
void glCopyTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) __attribute__((alias("glshim_glCopyTextureImage2D")));
void glCopyTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) __attribute__((alias("glshim_glCopyTextureSubImage1D")));
void glCopyTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) __attribute__((alias("glshim_glCopyTextureSubImage2D")));
void glGetTextureImageEXT(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels) __attribute__((alias("glshim_glGetTextureImage")));
void glGetTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat *params) __attribute__((alias("glshim_glGetTextureParameterfv")));
void glGetTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint *params) __attribute__((alias("glshim_glGetTextureParameteriv")));
void glGetTextureLevelParameterfvEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat *params) __attribute__((alias("glshim_glGetTextureLevelParameterfv")));
void glGetTextureLevelParameterivEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLint *params) __attribute__((alias("glshim_glGetTextureLevelParameteriv")));
void glTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels) __attribute__((alias("glshim_glTextureImage3D")));
void glTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels) __attribute__((alias("glshim_glTextureSubImage3D")));
void glCopyTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) __attribute__((alias("glshim_glCopyTextureSubImage3D")));
void glBindMultiTextureEXT(GLenum texunit, GLenum target, GLuint texture) __attribute__((alias("glshim_glBindMultiTexture")));
void glMultiTexCoordPointerEXT(GLenum texunit, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) __attribute__((alias("glshim_glMultiTexCoordPointer")));
void glMultiTexEnvfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param) __attribute__((alias("glshim_glMultiTexEnvf")));
void glMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat *params) __attribute__((alias("glshim_glMultiTexEnvfv")));
void glMultiTexEnviEXT(GLenum texunit, GLenum target, GLenum pname, GLint param) __attribute__((alias("glshim_glMultiTexEnvi")));
void glMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint *params) __attribute__((alias("glshim_glMultiTexEnviv")));
void glMultiTexGendEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble param) __attribute__((alias("glshim_glMultiTexGend")));
void glMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLdouble *params) __attribute__((alias("glshim_glMultiTexGendv")));
void glMultiTexGenfEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat param) __attribute__((alias("glshim_glMultiTexGenf")));
void glMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLfloat *params) __attribute__((alias("glshim_glMultiTexGenfv")));
void glMultiTexGeniEXT(GLenum texunit, GLenum coord, GLenum pname, GLint param) __attribute__((alias("glshim_glMultiTexGeni")));
void glMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, const GLint *params) __attribute__((alias("glshim_glMultiTexGeniv")));
void glGetMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat *params) __attribute__((alias("glshim_glGetMultiTexEnvfv")));
void glGetMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint *params) __attribute__((alias("glshim_glGetMultiTexEnviv")));
void glGetMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble *params) __attribute__((alias("glshim_glGetMultiTexGendv")));
void glGetMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat *params) __attribute__((alias("glshim_glGetMultiTexGenfv")));
void glGetMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint *params) __attribute__((alias("glshim_glGetMultiTexGeniv")));
void glMultiTexParameteriEXT(GLenum texunit, GLenum target, GLenum pname, GLint param) __attribute__((alias("glshim_glMultiTexParameteri")));
void glMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint *param) __attribute__((alias("glshim_glMultiTexParameteriv")));
void glMultiTexParameterfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param) __attribute__((alias("glshim_glMultiTexParameterf")));
void glMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat *param) __attribute__((alias("glshim_glMultiTexParameterfv")));
void glMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels) __attribute__((alias("glshim_glMultiTexImage1D")));
void glMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) __attribute__((alias("glshim_glMultiTexImage2D")));
void glMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels) __attribute__((alias("glshim_glMultiTexSubImage1D")));
void glMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels) __attribute__((alias("glshim_glMultiTexSubImage2D")));
void glCopyMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) __attribute__((alias("glshim_glCopyMultiTexImage1D")));
void glCopyMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) __attribute__((alias("glshim_glCopyMultiTexImage2D")));
void glCopyMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) __attribute__((alias("glshim_glCopyMultiTexSubImage1D")));
void glCopyMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) __attribute__((alias("glshim_glCopyMultiTexSubImage2D")));
void glGetMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels) __attribute__((alias("glshim_glGetMultiTexImage")));
void glGetMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat *params) __attribute__((alias("glshim_glGetMultiTexParameterfv")));
void glGetMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint *params) __attribute__((alias("glshim_glGetMultiTexParameteriv")));
void glGetMultiTexLevelParameterfvEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat *params) __attribute__((alias("glshim_glGetMultiTexLevelParameterfv")));
void glGetMultiTexLevelParameterivEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint *params) __attribute__((alias("glshim_glGetMultiTexLevelParameteriv")));
void glMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels) __attribute__((alias("glshim_glMultiTexImage3D")));
void glMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels) __attribute__((alias("glshim_glMultiTexSubImage3D")));
void glCopyMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) __attribute__((alias("glshim_glCopyMultiTexSubImage3D")));
void glCompressedTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedTextureImage3D")));
void glCompressedTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedTextureImage2D")));
void glCompressedTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedTextureImage1D")));
void glCompressedTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedTextureSubImage3D")));
void glCompressedTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedTextureSubImage2D")));
void glCompressedTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedTextureSubImage1D")));
void glGetCompressedTextureImageEXT(GLuint texture, GLenum target, GLint level, GLvoid *img) __attribute__((alias("glshim_glGetCompressedTextureImage")));
void glCompressedMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedMultiTexImage3D")));
void glCompressedMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedMultiTexImage2D")));
void glCompressedMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedMultiTexImage1D")));
void glCompressedMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedMultiTexSubImage3D")));
void glCompressedMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedMultiTexSubImage2D")));
void glCompressedMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedMultiTexSubImage1D")));
void glGetCompressedMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLvoid *img) __attribute__((alias("glshim_glGetCompressedMultiTexImage")));
void glMatrixLoadTransposefEXT(GLenum matrixMode, const GLfloat *m) __attribute__((alias("glshim_glMatrixLoadTransposef")));
void glMatrixLoadTransposedEXT(GLenum matrixMode, const GLdouble *m) __attribute__((alias("glshim_glMatrixLoadTransposed")));
void glMatrixMultTransposefEXT(GLenum matrixMode, const GLfloat *m) __attribute__((alias("glshim_glMatrixMultTransposef")));
void glMatrixMultTransposedEXT(GLenum matrixMode, const GLdouble *m) __attribute__((alias("glshim_glMatrixMultTransposed")));

#undef text
#undef texc
