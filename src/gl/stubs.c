#include "gl4es.h"

#define GLAPI __attribute__((visibility("default")))
#define APIENTRY
#define STUB errorShim(GL_INVALID_VALUE);

GLAPI void APIENTRY glClampColorARB (GLenum target, GLenum clamp){STUB}

GLAPI void APIENTRY glProgramStringARB (GLenum target, GLenum format, GLsizei len, const GLvoid *string){STUB}
GLAPI void APIENTRY glBindProgramARB (GLenum target, GLuint program){STUB}
GLAPI void APIENTRY glDeleteProgramsARB (GLsizei n, const GLuint *programs){STUB}
GLAPI void APIENTRY glGenProgramsARB (GLsizei n, GLuint *programs){STUB}
GLAPI void APIENTRY glProgramEnvParameter4dARB (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w){STUB}
GLAPI void APIENTRY glProgramEnvParameter4dvARB (GLenum target, GLuint index, const GLdouble *params){STUB}
GLAPI void APIENTRY glProgramEnvParameter4fARB (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w){STUB}
GLAPI void APIENTRY glProgramEnvParameter4fvARB (GLenum target, GLuint index, const GLfloat *params){STUB}
GLAPI void APIENTRY glProgramLocalParameter4dARB (GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w){STUB}
GLAPI void APIENTRY glProgramLocalParameter4dvARB (GLenum target, GLuint index, const GLdouble *params){STUB}
GLAPI void APIENTRY glProgramLocalParameter4fARB (GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w){STUB}
GLAPI void APIENTRY glProgramLocalParameter4fvARB (GLenum target, GLuint index, const GLfloat *params){STUB}
GLAPI void APIENTRY glGetProgramEnvParameterdvARB (GLenum target, GLuint index, GLdouble *params){STUB}
GLAPI void APIENTRY glGetProgramEnvParameterfvARB (GLenum target, GLuint index, GLfloat *params){STUB}
GLAPI void APIENTRY glGetProgramLocalParameterdvARB (GLenum target, GLuint index, GLdouble *params){STUB}
GLAPI void APIENTRY glGetProgramLocalParameterfvARB (GLenum target, GLuint index, GLfloat *params){STUB}
GLAPI void APIENTRY glGetProgramivARB (GLenum target, GLenum pname, GLint *params){STUB}
GLAPI void APIENTRY glGetProgramStringARB (GLenum target, GLenum pname, GLvoid *string){STUB}
GLAPI GLboolean APIENTRY glIsProgramARB (GLuint program){STUB return 0;}
