#include "directstate.h"
#include "gl.h"
#include "stack.h"

// Client State
void glClientAttribDefaultEXT(GLbitfield mask) {
    if (mask & GL_CLIENT_PIXEL_STORE_BIT) {
        glPixelStorei(GL_PACK_ALIGNMENT, 0);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 0);
        glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
        glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
        glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
        glPixelStorei(GL_PACK_ROW_LENGTH, 0);
        glPixelStorei(GL_PACK_SKIP_PIXELS, 0);
        glPixelStorei(GL_PACK_SKIP_ROWS, 0);
    }
#define enable_disable(pname, enabled)             \
    if (enabled) glEnableClientState(pname);       \
    else glDisableClientState(pname)

    if (mask & GL_CLIENT_VERTEX_ARRAY_BIT) {
        int client = state.texture.client;
        
		enable_disable(GL_VERTEX_ARRAY, false);
		enable_disable(GL_NORMAL_ARRAY, false);
		enable_disable(GL_COLOR_ARRAY, false);
		enable_disable(GL_SECONDARY_COLOR_ARRAY, false);
        for (int a=0; a<MAX_TEX; a++) {
           glClientActiveTexture(GL_TEXTURE0+a);
           enable_disable(GL_TEXTURE_COORD_ARRAY, false);
        }
#undef enable_disable
		if (state.texture.client != client) glClientActiveTexture(GL_TEXTURE0+client);
    }
}
void glPushClientAttribDefaultEXT(GLbitfield mask) {
    glPushClientAttrib(mask);
    glClientAttribDefaultEXT(mask);
}

// Matrix
#define mat(f) \
  GLenum old_mat; \
  glGetIntegerv(GL_MATRIX_MODE, &old_mat); \
  glMatrixMode(matrixMode); \
  f; \
  glMatrixMode(old_mat)
  
void glMatrixLoadfEXT(GLenum matrixMode, const GLfloat *m) {
    mat(glLoadMatrixf(m));
}
void glMatrixLoaddEXT(GLenum matrixMode, const GLdouble *m) {
    mat(glLoadMatrixd(m));
}
void glMatrixMultfEXT(GLenum matrixMode, const GLfloat *m) {
    mat(glMultMatrixf(m));
}
void glMatrixMultdEXT(GLenum matrixMode, const GLdouble *m) {
        mat(glMultMatrixd(m));
}
void glMatrixLoadIdentityEXT(GLenum matrixMode) {
        mat(glLoadIdentity());
}
void glMatrixRotatefEXT(GLenum matrixMode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
    mat(glRotatef(angle, x, y, z));
}
void glMatrixRotatedEXT(GLenum matrixMode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
    mat(glRotated(angle, x, y, z));
}
void glMatrixScalefEXT(GLenum matrixMode, GLfloat x, GLfloat y, GLfloat z) {
    mat(glScalef(x, y, z));
}
void glMatrixScaledEXT(GLenum matrixMode, GLdouble x, GLdouble y, GLdouble z) {
    mat(glScaled(x, y, z));
}
void glMatrixTranslatefEXT(GLenum matrixMode, GLfloat x, GLfloat y, GLfloat z) {
    mat(glTranslatef(x, y, z));
}
void glMatrixTranslatedEXT(GLenum matrixMode, GLdouble x, GLdouble y, GLdouble z) {
    mat(glTranslated(x, y, z));
}
void glMatrixOrthoEXT(GLenum matrixMode, GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f) {
    mat(glOrtho(l, r, b ,t, n, f));
}
void glMatrixFrustumEXT(GLenum matrixMode, GLdouble l, GLdouble r, GLdouble b, GLdouble t, GLdouble n, GLdouble f) {
    mat(glFrustum(l, r, b, t, n, f));
}
void glMatrixPushEXT(GLenum matrixMode) {
    mat(glPushMatrix());
}
void glMatrixPopEXT(GLenum matrixMode) {
    mat(glPopMatrix());
}
void glMatrixLoadTransposefEXT(GLenum matrixMode, const GLfloat *m) {
    mat(glLoadTransposeMatrixf(m));
}
void glMatrixLoadTransposedEXT(GLenum matrixMode, const GLdouble *m) {
    mat(glLoadTransposeMatrixd(m));
}
void glMatrixMultTransposefEXT(GLenum matrixMode, const GLfloat *m) {
    mat(glMultTransposeMatrixf(m));
}
void glMatrixMultTransposedEXT(GLenum matrixMode, const GLdouble *m) {
    mat(glMultTransposeMatrixd(m));
}
#undef mat

// Textures
#define text(f) \
  glBindTexture(target, texture); \
  f

void glTextureParameteriEXT(GLuint texture, GLenum target, GLenum pname, GLint param) {
    text(glTexParameteri(target, pname, param));
}
void glTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, const GLint *param) {
    text(glTexParameteriv(target, pname, param));
}
void glTextureParameterfEXT(GLuint texture, GLenum target, GLenum pname, GLfloat param) {
    text(glTexParameterf(target, pname, param));
}
void glTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, const GLfloat *param) {
    text(glTexParameterfv(target, pname, param));
}
void glTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexImage1D(target, level, internalformat, width, border, format, type, pixels));
}
void glTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels));
}
void glTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexSubImage1D(target, level, xoffset, width, format, type, pixels));
}
void glTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels));
}
void glCopyTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
    text(glCopyTexImage1D(target, level, internalformat, x, y, width, border));
}
void glCopyTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    text(glCopyTexImage2D(target, level, internalformat, x, y, width, height, border));
}
void glCopyTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    text(glCopyTexSubImage1D(target, level, xoffset, x, y, width));
}
void glCopyTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    text(glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height));
}
void glGetTextureImageEXT(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels) {
    text(glGetTexImage(target, level, format, type, pixels));
}
void glGetTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat *params) {
    text(glGetTexParameterfv(target, pname, params));
}
void glGetTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint *params) {
    text(glGetTexParameteriv(target, pname, params));
}
void glGetTextureLevelParameterfvEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat *params) {
    text(glGetTexLevelParameterfv(target, level, pname, params));
}
void glGetTextureLevelParameterivEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLint *params) {
    text(glGetTexLevelParameteriv(target, level, pname, params));
}

// Texture 3D
void glTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels));
}
void glTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels));
}
void glCopyTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    text(glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height));
}
// Compressed texture
void glCompressedTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data));
}
void glCompressedTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data));
}
void glCompressedTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data));
}
void glCompressedTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data));
}
void glCompressedTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data));
}
void glCompressedTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data));
}
void glGetCompressedTextureImageEXT(GLuint texture, GLenum target, GLint level, GLvoid *img) {
    text(glGetCompressedTexImage(target, level, img));
}

#undef text
#define text(f) \
  GLenum old_tex = state.texture.active; \
  if(texunit != old_tex) glActiveTexture(texunit); \
  f; \
  if(texunit != old_tex) glActiveTexture(old_tex)
#define texc(f) \
  GLenum old_tex = state.texture.client; \
  if(texunit != old_tex) glClientActiveTexture(texunit); \
  f; \
  if(texunit != old_tex) glClientActiveTexture(old_tex)

void glBindMultiTextureEXT(GLenum texunit, GLenum target, GLuint texture) {
    text(glBindTexture(target, texture));
}
void glMultiTexCoordPointerEXT(GLenum texunit, GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) {
    texc(glTexCoordPointer(size, type, stride, pointer));
}
void glMultiTexEnvfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param) {
    text(glTexEnvf(target, pname, param));
}
void glMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat *params) {
    text(glTexEnvfv(target, pname, params));
}
void glMultiTexEnviEXT(GLenum texunit, GLenum target, GLenum pname, GLint param) {
    text(glTexEnvi(target, pname, param));
}
void glMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint *params) {
    text(glTexEnviv(target, pname, params));
}
void glMultiTexGendEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble param) {
    text(glTexGend(coord, pname, param));
}
void glMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLdouble *params) {
    text(glTexGendv(coord, pname, params));
}
void glMultiTexGenfEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat param) {
    text(glTexGenf(coord, pname, param));
}
void glMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, const GLfloat *params) {
    text(glTexGenfv(coord, pname, params));
}
void glMultiTexGeniEXT(GLenum texunit, GLenum coord, GLenum pname, GLint param) {
    text(glTexGeni(coord, pname, param));
}
void glMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, const GLint *params) {
    text(glTexGeniv(coord, pname, params));
}
void glGetMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat *params) {
    text(glGetTexEnvfv(target, pname, params));
}
void glGetMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint *params) {
    text(glGetTexEnviv(target, pname, params));
}
void glGetMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble *params) {
    text(glGetTexGendv(coord, pname, params));
}
void glGetMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat *params) {
    text(glGetTexGenfv(coord, pname, params));
}
void glGetMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint *params) {
    text(glGetTexGeniv(coord, pname, params));
}
void glMultiTexParameteriEXT(GLenum texunit, GLenum target, GLenum pname, GLint param) {
    text(glTexParameteri(target, pname, param));
}
void glMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, const GLint *param) {
    text(glTexParameteriv(target, pname, param));
}
void glMultiTexParameterfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param) {
    text(glTexParameterf(target, pname, param));
}
void glMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, const GLfloat *param) {
    text(glTexParameterfv(target, pname, param));
}
void glMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexImage1D(target, level, internalformat, width, border, format, type, pixels));
}
void glMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels));
}
void glMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexSubImage1D(target, level, xoffset, width, format, type, pixels));
}
void glMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels));
}
void glCopyMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
    text(glCopyTexImage1D(target, level, internalformat, x, y, width, border));
}
void glCopyMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    text(glCopyTexImage2D(target, level, internalformat, x, y, width, height, border));
}
void glCopyMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    text(glCopyTexSubImage1D(target, level, xoffset, x, y, width));
}
void glCopyMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    text(glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height));
}
void glGetMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels) {
    text(glGetTexImage(target, level, format, type, pixels));
}
void glGetMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat *params) {
    text(glGetTexParameterfv(target, pname, params));
}
void glGetMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint *params) {
    text(glGetTexParameteriv(target, pname, params));
}
void glGetMultiTexLevelParameterfvEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat *params) {
    text(glGetTexLevelParameterfv(target, level, pname, params));
}
void glGetMultiTexLevelParameterivEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint *params) {
    text(glGetTexLevelParameteriv(target, level, pname, params));
}
void glMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels));
}
void glMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *pixels) {
    text(glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels));
}
void glCopyMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    text(glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height));
}
// Compressed texture
void glCompressedMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data));
}
void glCompressedMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data));
}
void glCompressedMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data));
}
void glCompressedMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data));
}
void glCompressedMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data));
}
void glCompressedMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data) {
    text(glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data));
}
void glGetCompressedMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLvoid *img) {
    text(glGetCompressedTexImage(target, level, img));
}


#undef text
#undef texc
