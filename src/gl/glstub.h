#include "gl.h"

void glColorMaterial(GLenum face, GLenum mode);
void glPopAttrib();
void glPushAttrib(GLbitfield mask);
void glPopClientAttrib();
void glPushClientAttrib(GLbitfield mask);
void glSecondaryColor3f(GLfloat r, GLfloat g, GLfloat b);
void glIndexf(GLfloat c);

void glFogCoordd(GLdouble coord);
void glFogCoordf(GLfloat coord);
void glFogCoorddv(const GLdouble *coord);
void glFogCoordfv(const GLfloat *coord);

void glArrayElement(GLint i);
void glEdgeFlag(GLboolean flag);
