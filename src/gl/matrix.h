#include "gl.h"

void gl4es_glMatrixMode(GLenum mode);
void gl4es_glPushMatrix();
void gl4es_glPopMatrix();
void gl4es_glLoadMatrixf(const GLfloat * m);
void gl4es_glMultMatrixf(const GLfloat * m);
void gl4es_glLoadIdentity();
void gl4es_glTranslatef(GLfloat x, GLfloat y, GLfloat z);
void gl4es_glScalef(GLfloat x, GLfloat y, GLfloat z);
void gl4es_glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
void gl4es_glOrthof(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat nearVal, GLfloat farVal);
void gl4es_glFrustumf(GLfloat left,	GLfloat right, GLfloat bottom, GLfloat top,	GLfloat nearVal, GLfloat farVal);
