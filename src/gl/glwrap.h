#include <gl.h>

#ifndef GL_WRAP_H
#define GL_WRAP_H

// misc naive wrappers
void glActiveTextureARB(GLenum texture);
void glClearDepth(GLdouble depth);
void glClipPlane(GLenum plane, const GLdouble *equation);
void glDepthRange(GLdouble nearVal, GLdouble farVal);
void glFogi(GLenum pname, GLint param);
void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far);
void glGetDoublev(GLenum pname, GLdouble *params);
void glMateriali(GLenum face, GLenum pname, GLint param);
void glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat r, GLfloat q, GLfloat t);
void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far);

// color
void glColor3f(GLfloat r, GLfloat g, GLfloat b);
void glColor3fv(GLfloat *c);
void glColor4fv(GLfloat *c);
void glIndexfv(const GLfloat *c);
void glSecondaryColor3fv(const GLfloat *v);

// raster
void glRasterPos2fv(const GLfloat *v);
void glRasterPos2f(GLfloat x, GLfloat y);
void glRasterPos3fv(GLfloat x, GLfloat y, GLfloat z);

// matrix
void glLoadMatrixd(const GLdouble *m);
void glMultMatrixd(const GLdouble *m);

// normal
void glNormal3fv(GLfloat *v);

// textures
void glTexCoord1f(GLfloat s);
void glTexCoord1fv(GLfloat *t);
void glTexCoord2fv(GLfloat *t);
void glTexCoord3f(GLfloat s, GLfloat t, GLfloat r);
void glTexCoord3fv(GLfloat *t);
void glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void glTexCoord4fv(GLfloat *t);

// transforms
void glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
void glScaled(GLdouble x, GLdouble y, GLdouble z);
void glTranslated(GLdouble x, GLdouble y, GLdouble z);

// vertex
void glVertex2f(GLfloat x, GLfloat y);
void glVertex2fv(GLfloat *v);
void glVertex3fv(GLfloat *v);
void glVertex4f(GLfloat r, GLfloat g, GLfloat b, GLfloat w);
void glVertex4fv(GLfloat *v);

// OES wrappers

void glClearDepthfOES(GLfloat depth);
void glClipPlanefOES(GLenum plane, const GLfloat *equation);
void glDepthRangefOES(GLclampf near, GLclampf far);
void glFrustumfOES(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far);
void glGetClipPlanefOES(GLenum plane, GLfloat equation[4]);
void glOrthofOES(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far);

// basic thunking

#define THUNK(suffix, type)\
void glColor3##suffix##v(const type *v);\
void glColor3##suffix(type r, type g, type b);\
void glColor4##suffix##v(const type *v);\
void glColor4##suffix(type r, type g, type b, type a);\
void glSecondaryColor3##suffix##v(const type *v);\
void glSecondaryColor3##suffix(type r, type g, type b);\
void glIndex##suffix##v(const type *c);\
void glIndex##suffix(type c);\
void glNormal3##suffix##v(const type *v);\
void glNormal3##suffix(type x, type y, type z);\
void glRasterPos2##suffix##v(type *v);\
void glRasterPos2##suffix(type x, type y);\
void glRasterPos3##suffix##v(type *v);\
void glRasterPos3##suffix(type x, type y, type z);\
void glVertex2##suffix##v(type *v);\
void glVertex2##suffix(type x, type y);\
void glVertex3##suffix##v(type *v);\
void glVertex3##suffix(type x, type y, type z);\
void glVertex4##suffix(type x, type y, type z, type w);\
void glVertex4##suffix##v(type *v);\
void glTexCoord1##suffix##v(type *t);\
void glTexCoord1##suffix(type s, type t);\
void glTexCoord2##suffix##v(type *t);\
void glTexCoord2##suffix(type s, type t);\
void glTexCoord3##suffix##v(type *t);\
void glTexCoord3##suffix(type s, type t, type r);\
void glTexCoord4##suffix(type s, type t, type r, type q);\
void glTexCoord4##suffix##v(type *t);

THUNK(b, GLbyte);
THUNK(d, GLdouble);
THUNK(i, GLint);
THUNK(s, GLshort);
THUNK(ub, GLubyte);
THUNK(ui, GLuint);
THUNK(us, GLushort);
#undef THUNK

#define THUNK(suffix, type)\
extern void glGet##suffix##v(GLenum pname, type *params);

THUNK(Double, GLdouble);
THUNK(Integer, GLint);
#undef THUNK

#endif
