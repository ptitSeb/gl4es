#include <gl.h>

void glTexImage2D(GLenum target, GLint level, GLint internalFormat,
                  GLsizei width, GLsizei height, GLint border,
                  GLenum format, GLenum type, const GLvoid *data);

void glTexImage1D(GLenum target, GLint level, GLint internalFormat,
                  GLsizei width, GLint border,
                  GLenum format, GLenum type, const GLvoid *data);

int npot(int n);

extern GLuint tUnpackRowLength;
extern GLuint tUnpackSkipPixels;
extern GLuint tUnpackSkipRows;
