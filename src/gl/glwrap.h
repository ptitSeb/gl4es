#include <gl.h>

#ifndef GL_WRAP_H
#define GL_WRAP_H

void glActiveTextureARB(GLenum texture);
void glClearDepth(GLdouble depth);
void glFogi(GLenum pname, GLint param);
void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far);
void glGetDoublev(GLenum pname, GLdouble *params);
void glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz);
void glNormal3dv(const GLdouble *n);
void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far);
void glTexCoord2d(GLdouble s, GLdouble t);
void glTranslated(GLdouble x, GLdouble y, GLdouble z);

// basic thunking

#define THUNK(suffix, type)\
void glColor3##suffix(type r, type g, type b);\
void glColor4##suffix(type r, type g, type b, type a);\
void glColor3##suffix##v(const type *v);\
void glColor4##suffix##v(const type *v);\
void glIndex##suffix(type c);\
void glIndex##suffix##v(const type *c);\
void glSecondaryColor3##suffix(type r, type g, type b);\
void glSecondaryColor3##suffix##v(const type *v);\
void glVertex2##suffix(type x, type y);\
void glVertex3##suffix(type x, type y, type z);

// TODO: we don't handle glVertex4f anywhere
// TODO: glVertex3fv?

THUNK(b, GLbyte);
THUNK(d, GLdouble);
THUNK(i, GLint);
THUNK(s, GLshort);
THUNK(ub, GLubyte);
THUNK(ui, GLuint);
THUNK(us, GLushort);
#undef THUNK

void glVertex2f(GLfloat x, GLfloat y);
void glColor3f(GLfloat r, GLfloat g, GLfloat b);

#define THUNK(suffix, type)\
extern void glGet##suffix##v(GLenum pname, type *params);

THUNK(Double, GLdouble);
THUNK(Integer, GLint);
#undef THUNK

#endif
