#include "gl.h"
#include <math.h>

extern void glTexGenfv(GLenum coord, GLenum pname, const GLfloat *params);
extern void glTexGeni(GLenum coord, GLenum pname, GLint param);
extern void gen_tex_coords(GLfloat *verts, GLfloat *norm, GLfloat **coords, GLint count, GLint *needclean, int texture);
extern void gen_tex_clean(GLint cleancode, int texture);
extern void glGetTexGenfv(GLenum coord,GLenum pname,GLfloat *params);
