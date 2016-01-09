#ifndef GL_WRAP_H
#define GL_WRAP_H

#include "../gl.h"
//#include <GLES/glext.h>


// misc naive wrappers
#ifdef USE_ES2
void glshim_glCompileShaderARB(GLuint shader);
GLuint glshim_glCreateShaderObjectARB(GLenum shaderType);
void glshim_glGetObjectParameterivARB(GLuint shader, GLenum pname, GLint *params);
void glshim_glShaderSourceARB(GLuint shader, GLsizei count, const GLchar **string, const GLint *length);
#endif

void glshim_glClearDepth(GLdouble depth);
void glshim_glClipPlane(GLenum plane, const GLdouble *equation);
void glshim_glDepthRange(GLdouble nearVal, GLdouble farVal);
void glshim_glFogi(GLenum pname, GLint param);
void glshim_glFogiv(GLenum pname, GLint *params);
void glshim_glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far);
void glshim_glGetDoublev(GLenum pname, GLdouble *params);
void glshim_glLighti(GLenum light, GLenum pname, GLint param);
void glshim_glLightiv(GLenum light, GLenum pname, GLint *iparams);
void glshim_glLightModeli(GLenum pname, GLint param);
void glshim_glLightModeliv(GLenum pname, GLint *iparams);
void glshim_glMateriali(GLenum face, GLenum pname, GLint param);
void glshim_glMaterialiv(GLenum face, GLenum pname, GLint *param);
void glshim_glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t);
void glshim_glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far);
void glshim_glGetMaterialiv(GLenum face, GLenum pname, GLint * params);
void glshim_glGetLightiv(GLenum light, GLenum pname, GLint * params);
void glshim_glGetClipPlane(GLenum plane, GLdouble *equation);

void glshim_glDrawRangeElements(GLenum mode,GLuint start,GLuint end,GLsizei count,GLenum type,const void *indices);	
// color
void glshim_glColor3f(GLfloat r, GLfloat g, GLfloat b);
void glshim_glColor3fv(GLfloat *c);
void glshim_glColor4fv(GLfloat *c);
void glshim_glIndexfv(const GLfloat *c);
void glshim_glSecondaryColor3fv(const GLfloat *v);

// raster
void glshim_glRasterPos2f(GLfloat x, GLfloat y);
void glshim_glRasterPos2fv(const GLfloat *v);
void glshim_glRasterPos3f(GLfloat x, GLfloat y, GLfloat z);
void glshim_glRasterPos3fv(const GLfloat *v);
void glshim_glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glshim_glRasterPos4fv(const GLfloat *v);
void glshim_glWindowPos2f(GLfloat x, GLfloat y);
void glshim_glWindowPos2fv(const GLfloat *v);
void glshim_glWindowPos3f(GLfloat x, GLfloat y, GLfloat z);
void glshim_glWindowPos3fv(const GLfloat *v);

void glshim_glPixelStoref(GLenum pname, GLfloat param);
void glshim_glGetTexGendv(GLenum coord,GLenum pname,GLdouble *params);
void glshim_glGetTexGeniv(GLenum coord,GLenum pname,GLint *params);
void glshim_glPixelTransferi(GLenum pname, GLint param);
void glshim_glPixelTransferf(GLenum pname, GLfloat param);	

// eval
void glshim_glEvalCoord1d(GLdouble u);
void glshim_glEvalCoord1dv(GLdouble *v);
void glshim_glEvalCoord1fv(GLfloat *v);
void glshim_glEvalCoord2d(GLdouble u, GLdouble v);
void glshim_glEvalCoord2dv(GLdouble *v);
void glshim_glEvalCoord2fv(GLfloat *v);
void glshim_glMapGrid1d(GLint un, GLdouble u1, GLdouble u2);
void glshim_glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);

// matrix
void glshim_glLoadMatrixd(const GLdouble *m);
void glshim_glMultMatrixd(const GLdouble *m);

// normal
void glshim_glNormal3fv(GLfloat *v);

// rect
#define GL_RECT(suffix, type)                                \
    void glshim_glRect##suffix(type x1, type y1, type x2, type y2); \
    void glshim_glRect##suffix##v(const type *v);

GL_RECT(d, GLdouble)
GL_RECT(f, GLfloat)
GL_RECT(i, GLint)
GL_RECT(s, GLshort)
#undef GL_RECT

// textures

void glshim_glTexCoord1f(GLfloat s);
void glshim_glTexCoord1fv(GLfloat *t);
void glshim_glTexCoord2f(GLfloat s, GLfloat t);
void glshim_glTexCoord2fv(GLfloat *t);
void glshim_glTexCoord3f(GLfloat s, GLfloat t, GLfloat r);
void glshim_glTexCoord3fv(GLfloat *t);
void glshim_glTexCoord4fv(GLfloat *t);

void glshim_glMultiTexCoord1f(GLenum target, GLfloat s);
void glshim_glMultiTexCoord1fv(GLenum target, GLfloat *t);
void glshim_glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t);
void glshim_glMultiTexCoord2fv(GLenum target, GLfloat *t);
void glshim_glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r);
void glshim_glMultiTexCoord3fv(GLenum target, GLfloat *t);
void glshim_glMultiTexCoord4fv(GLenum target, GLfloat *t);

void glshim_glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params);

void glshim_glPolygonMode(GLenum face, GLenum mode);

// texgen
void glshim_glTexGend(GLenum coord, GLenum pname, GLdouble param);
void glshim_glTexGeni(GLenum coord, GLenum pname, GLint param);
void glshim_glTexGenf(GLenum coord, GLenum pname, GLfloat param);
void glshim_glTexGendv(GLenum coord, GLenum pname, const GLdouble *params);
void glshim_glTexGenfv(GLenum coord, GLenum pname, const GLfloat *params);
void glshim_glTexGeniv(GLenum coord, GLenum pname, const GLint *params);

// transforms
void glshim_glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
void glshim_glScaled(GLdouble x, GLdouble y, GLdouble z);
void glshim_glTranslated(GLdouble x, GLdouble y, GLdouble z);

// vertex
void glshim_glVertex2f(GLfloat x, GLfloat y);
void glshim_glVertex2fv(GLfloat *v);
void glshim_glVertex3fv(GLfloat *v);
void glshim_glVertex3f(GLfloat r, GLfloat g, GLfloat b);
void glshim_glVertex4fv(GLfloat *v);

// OES wrappers

void glClearDepthfOES(GLfloat depth);
void glClipPlanefOES(GLenum plane, const GLfloat *equation);
void glDepthRangefOES(GLclampf near, GLclampf far);
void glFrustumfOES(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far);
void glGetClipPlanefOES(GLenum plane, GLfloat equation[4]);
void glOrthofOES(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far);

// basic thunking

#define THUNK(suffix, type)                                \
void glshim_glColor3##suffix##v(const type *v);                   \
void glshim_glColor3##suffix(type r, type g, type b);             \
void glshim_glColor4##suffix##v(const type *v);                   \
void glshim_glColor4##suffix(type r, type g, type b, type a);     \
void glshim_glSecondaryColor3##suffix##v(const type *v);          \
void glshim_glSecondaryColor3##suffix(type r, type g, type b);    \
void glshim_glIndex##suffix##v(const type *c);                    \
void glshim_glIndex##suffix(type c);                              \
void glshim_glNormal3##suffix##v(const type *v);                  \
void glshim_glNormal3##suffix(type x, type y, type z);            \
void glshim_glRasterPos2##suffix##v(type *v);                     \
void glshim_glRasterPos2##suffix(type x, type y);                 \
void glshim_glRasterPos3##suffix##v(type *v);                     \
void glshim_glRasterPos3##suffix(type x, type y, type z);         \
void glshim_glRasterPos4##suffix##v(type *v);                     \
void glshim_glRasterPos4##suffix(type x, type y, type z, type w); \
void glshim_glWindowPos2##suffix##v(type *v);                     \
void glshim_glWindowPos2##suffix(type x, type y);                 \
void glshim_glWindowPos3##suffix##v(type *v);                     \
void glshim_glWindowPos3##suffix(type x, type y, type z);         \
void glshim_glVertex2##suffix##v(type *v);                        \
void glshim_glVertex2##suffix(type x, type y);                    \
void glshim_glVertex3##suffix##v(type *v);                        \
void glshim_glVertex3##suffix(type x, type y, type z);            \
void glshim_glVertex4##suffix(type x, type y, type z, type w);    \
void glshim_glVertex4##suffix##v(type *v);                        \
void glshim_glTexCoord1##suffix(type s);                          \
void glshim_glTexCoord1##suffix##v(type *t);                      \
void glshim_glTexCoord2##suffix(type s, type t);                  \
void glshim_glTexCoord2##suffix##v(type *t);                      \
void glshim_glTexCoord3##suffix(type s, type t, type r);          \
void glshim_glTexCoord3##suffix##v(type *t);                      \
void glshim_glTexCoord4##suffix(type s, type t, type r, type q);  \
void glshim_glTexCoord4##suffix##v(type *t);					   \
void glshim_glMultiTexCoord1##suffix(GLenum target, type s);                          \
void glshim_glMultiTexCoord1##suffix##v(GLenum target, type *t);                      \
void glshim_glMultiTexCoord2##suffix(GLenum target, type s, type t);                  \
void glshim_glMultiTexCoord2##suffix##v(GLenum target, type *t);                      \
void glshim_glMultiTexCoord3##suffix(GLenum target, type s, type t, type r);          \
void glshim_glMultiTexCoord3##suffix##v(GLenum target, type *t);                      \
void glshim_glMultiTexCoord4##suffix(GLenum target, type s, type t, type r, type q);  \
void glshim_glMultiTexCoord4##suffix##v(GLenum target, type *t);					   \
void glshim_glMultiTexCoord1##suffix##ARB(GLenum target, type s);                          \
void glshim_glMultiTexCoord1##suffix##vARB(GLenum target, type *t);                      \
void glshim_glMultiTexCoord2##suffix##ARB(GLenum target, type s, type t);                  \
void glshim_glMultiTexCoord2##suffix##vARB(GLenum target, type *t);                      \
void glshim_glMultiTexCoord3##suffix##ARB(GLenum target, type s, type t, type r);          \
void glshim_glMultiTexCoord3##suffix##vARB(GLenum target, type *t);                      \
void glshim_glMultiTexCoord4##suffix##ARB(GLenum target, type s, type t, type r, type q);  \
void glshim_glMultiTexCoord4##suffix##vARB(GLenum target, type *t);

THUNK(b, GLbyte)
THUNK(d, GLdouble)
THUNK(i, GLint)
THUNK(s, GLshort)
THUNK(ub, GLubyte)
THUNK(ui, GLuint)
THUNK(us, GLushort)
#undef THUNK

#define THUNK(suffix, type) \
    extern void glGet##suffix##v(GLenum pname, type *params);

THUNK(Double, GLdouble)
THUNK(Integer, GLint)
THUNK(Float, GLfloat)
#undef THUNK

#endif
