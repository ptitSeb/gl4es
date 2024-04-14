#include "wrap/gles.h"
#include "loader.h"

#define INIT_EGL(name) \
    name##_PTR name; \

#define INIT_GLES_OR_FPE(name)  \
    name##_PTR (name);          \
    name##_PTR  fpe_##name;     \

#define INIT_GLES_FPE(name) \
    name##_PTR  fpe_##name; \

#define INIT_GLES(name) \
    name##_PTR (name); \

#define INIT_GLES_OPT(name) \
    name##_PTR (name); \

#define INIT_GLES_NO_1(name) \
    name##_PTR (name); \

#define INIT_GLES_NO_FPE(name) \
    name##_PTR (name); \

#define INIT_GLES_OR_OES(name) \
    name##_PTR (name); \

#define INIT_GLES_EXT(name) \
    name##_PTR (name); \

#define INIT_GLES_OES(name) \
    name##_PTR (name); \

#define ALL_FUNCTIONS() \
INIT_EGL(eglGetProcAddress) \
INIT_GLES_NO_1(glCreateShader); \
INIT_GLES_NO_1(glShaderSource); \
INIT_GLES_NO_1(glCompileShader); \
INIT_GLES_NO_1(glGetShaderiv); \
INIT_GLES_NO_1(glDeleteShader); \
INIT_GLES(glGetError); \
INIT_GLES_NO_1(glGetShaderInfoLog); \
INIT_GLES(glGetString); \
INIT_GLES(glGetIntegerv); \
INIT_GLES_OR_OES(glBlendColor); \
INIT_GLES_NO_1(glGetShaderPrecisionFormat); \
INIT_GLES(glFinish); \
INIT_GLES(glReadPixels); \
INIT_GLES(glTexParameterf); \
INIT_GLES_OR_FPE(glEnable); \
INIT_GLES_OR_FPE(glDisable); \
INIT_GLES_OR_OES(glGenFramebuffers); \
INIT_GLES(glDepthFunc); \
INIT_GLES(glDepthMask); \
INIT_GLES(glDepthRangef); \
INIT_GLES(glClearDepthf); \
INIT_GLES_OR_FPE(glClientActiveTexture); \
INIT_GLES_OES(glDrawTexf); \
INIT_GLES(glTexParameteriv); \
INIT_GLES_OR_FPE(glVertexPointer); \
INIT_GLES_OR_FPE(glTexCoordPointer); \
INIT_GLES_OR_FPE(glDrawArrays); \
INIT_GLES_NO_1(glBindAttribLocation); \
INIT_GLES_NO_1(glAttachShader); \
INIT_GLES_NO_1(glCreateProgram); \
INIT_GLES_NO_1(glLinkProgram); \
INIT_GLES_NO_1(glGetProgramiv); \
INIT_GLES_NO_1(glGetUniformLocation); \
INIT_GLES_NO_1(glUniform1i); \
INIT_GLES_NO_1(glUseProgram); \
INIT_GLES(glBindTexture); \
INIT_GLES(glActiveTexture); \
INIT_GLES_OR_FPE(glNormal3f); \
INIT_GLES_OR_FPE(glColor4f); \
INIT_GLES(glGenBuffers); \
INIT_GLES(glBufferData); \
INIT_GLES(glBindBuffer); \
INIT_GLES(glBufferSubData); \
INIT_GLES(glFlush); \
INIT_GLES_NO_FPE(glShadeModel); \
INIT_GLES_OR_FPE(glAlphaFunc); \
INIT_GLES_NO_FPE(glLogicOp); \
INIT_GLES(glColorMask); \
INIT_GLES(glClear); \
INIT_GLES(glDeleteBuffers); \
INIT_GLES_OR_FPE(glMatrixMode); \
INIT_GLES_NO_FPE(glLoadMatrixf); \
INIT_GLES_NO_FPE(glLoadIdentity); \
INIT_GLES_NO_1(glUniform1fv); \
INIT_GLES_NO_1(glUniform2fv); \
INIT_GLES_NO_1(glUniform3fv); \
INIT_GLES_NO_1(glUniform4fv); \
INIT_GLES_NO_1(glUniform1iv); \
INIT_GLES_NO_1(glUniform2iv); \
INIT_GLES_NO_1(glUniform3iv); \
INIT_GLES_NO_1(glUniform4iv); \
INIT_GLES_NO_1(glUniformMatrix2fv); \
INIT_GLES_NO_1(glUniformMatrix3fv); \
INIT_GLES_NO_1(glUniformMatrix4fv); \
INIT_GLES(glTexImage2D); \
INIT_GLES(glTexSubImage2D); \
INIT_GLES(glTexParameteri); \
INIT_GLES(glViewport); \
INIT_GLES(glScissor); \
INIT_GLES(glGenTextures); \
INIT_GLES(glTexParameterfv); \
INIT_GLES_OR_OES(glGenerateMipmap); \
INIT_GLES(glDeleteTextures); \
INIT_GLES(glPixelStorei); \
INIT_GLES_OES(glTexGeni); \
INIT_GLES_OES(glTexGenfv); \
INIT_GLES(glCompressedTexImage2D); \
INIT_GLES(glCompressedTexSubImage2D); \
INIT_GLES_NO_1(glDeleteProgram); \
INIT_GLES_NO_1(glDetachShader); \
INIT_GLES_NO_1(glGetProgramInfoLog); \
INIT_GLES_NO_1(glGetActiveUniform); \
INIT_GLES_NO_1(glGetActiveAttrib); \
INIT_GLES_NO_1(glGetAttribLocation); \
INIT_GLES_OES(glProgramBinary); \
INIT_GLES_OES(glGetProgramBinary); \
INIT_GLES_NO_1(glValidateProgram); \
INIT_GLES(glIsEnabled); \
INIT_GLES_OR_OES(glBlendFuncSeparate); \
INIT_GLES_OR_OES(glBlendEquationSeparate); \
INIT_GLES(glBlendFunc); \
INIT_GLES_OR_OES(glBlendEquation); \
INIT_GLES_OR_FPE(glPointParameterfv); \
INIT_GLES_OR_FPE(glPointSize); \
INIT_GLES(glCullFace); \
INIT_GLES(glFrontFace); \
INIT_GLES_OR_FPE(glLightModelf); \
INIT_GLES_OR_FPE(glLightModelfv); \
INIT_GLES_OR_FPE(glLightfv); \
INIT_GLES_OR_FPE(glMaterialfv); \
INIT_GLES_OR_FPE(glMaterialf); \
INIT_GLES(glHint); \
INIT_GLES_OR_OES(glDeleteRenderbuffers); \
INIT_GLES_OR_OES(glDeleteFramebuffers); \
INIT_GLES_NO_FPE(glEnableClientState); \
INIT_GLES_NO_FPE(glDisableClientState); \
INIT_GLES(glDrawElements); \
INIT_GLES_FPE(glDrawElements); \
INIT_GLES_NO_1(glVertexAttrib4fv); \
INIT_GLES_NO_1(glEnableVertexAttribArray); \
INIT_GLES_NO_1(glDisableVertexAttribArray); \
INIT_GLES_NO_1(glVertexAttribPointer); \
INIT_GLES_OPT(glVertexAttribIPointer); \
INIT_GLES_OR_OES(glBindFramebuffer); \
INIT_GLES_OR_OES(glFramebufferTexture2D); \
INIT_GLES(glStencilMask); \
INIT_GLES_OR_OES(glStencilMaskSeparate); \
INIT_GLES(glStencilFunc); \
INIT_GLES_OR_OES(glStencilFuncSeparate); \
INIT_GLES(glStencilOp); \
INIT_GLES_OR_OES(glStencilOpSeparate); \
INIT_GLES(glClearStencil); \
INIT_GLES_NO_FPE(glTexEnvf); \
INIT_GLES_NO_FPE(glTexEnvfv); \
INIT_GLES_NO_FPE(glGetTexEnviv); \
INIT_GLES_NO_FPE(glClipPlanef); \
INIT_GLES_OR_OES(glIsFramebuffer); \
INIT_GLES_OR_OES(glCheckFramebufferStatus); \
INIT_GLES_OR_OES(glGenRenderbuffers); \
INIT_GLES_OR_OES(glFramebufferRenderbuffer); \
INIT_GLES_OR_OES(glGetFramebufferAttachmentParameteriv); \
INIT_GLES_OR_OES(glRenderbufferStorage); \
INIT_GLES_OR_OES(glBindRenderbuffer); \
INIT_GLES_OR_OES(glGetRenderbufferParameteriv); \
INIT_GLES_EXT(glDrawBuffers); \
INIT_GLES_OR_FPE(glFogfv); \
INIT_GLES_OR_FPE(glNormalPointer); \
INIT_GLES_OR_FPE(glColorPointer); \
INIT_GLES_NO_1(glShaderBinary); \
INIT_GLES_NO_1(glReleaseShaderCompiler); \
INIT_GLES(glCopyTexImage2D); \
INIT_GLES(glCopyTexSubImage2D); \
INIT_GLES(glGetFloatv); \
INIT_GLES_NO_FPE(glGetClipPlanef); \
INIT_GLES_OR_FPE(glMultiTexCoord4f); \
INIT_GLES(glSampleCoverage); \
INIT_GLES_NO_FPE(glAlphaFuncx); \
INIT_GLES(glClearColor); \
INIT_GLES_NO_FPE(glClearColorx); \
INIT_GLES_NO_FPE(glClearDepthx); \
INIT_GLES_NO_FPE(glClipPlanex); \
INIT_GLES_NO_FPE(glColor4ub); \
INIT_GLES_NO_FPE(glColor4x); \
INIT_GLES_NO_FPE(glDepthRangex); \
INIT_GLES_OES(glDrawTexi); \
INIT_GLES_OPT(glFogCoordPointer); \
INIT_GLES_OPT(glFogCoordf); \
INIT_GLES_OPT(glFogCoordfv); \
INIT_GLES_NO_FPE(glFogf); \
INIT_GLES_NO_FPE(glFogx); \
INIT_GLES_NO_FPE(glFogxv); \
INIT_GLES_NO_FPE(glFrustumf); \
INIT_GLES_NO_FPE(glFrustumx); \
INIT_GLES_NO_1(glGetAttachedShaders); \
INIT_GLES(glGetBooleanv); \
INIT_GLES(glGetBufferParameteriv); \
INIT_GLES_NO_FPE(glGetClipPlanex); \
INIT_GLES_NO_FPE(glGetFixedv); \
INIT_GLES_NO_FPE(glGetLightfv); \
INIT_GLES_NO_FPE(glGetLightxv); \
INIT_GLES_NO_FPE(glGetMaterialfv); \
INIT_GLES_NO_FPE(glGetMaterialxv); \
INIT_GLES_NO_FPE(glGetPointerv); \
INIT_GLES_NO_1(glGetShaderSource); \
INIT_GLES_NO_FPE(glGetTexEnvfv); \
INIT_GLES_NO_FPE(glGetTexEnvxv); \
INIT_GLES(glGetTexParameterfv); \
INIT_GLES(glGetTexParameteriv); \
INIT_GLES_NO_FPE(glGetTexParameterxv); \
INIT_GLES_NO_1(glGetUniformfv); \
INIT_GLES_NO_1(glGetUniformiv); \
INIT_GLES_NO_1(glGetVertexAttribPointerv); \
INIT_GLES_NO_1(glGetVertexAttribfv); \
INIT_GLES_NO_1(glGetVertexAttribiv); \
INIT_GLES(glIsBuffer); \
INIT_GLES_NO_1(glIsProgram); \
INIT_GLES_OES(glIsRenderbuffer); \
INIT_GLES_NO_1(glIsShader); \
INIT_GLES(glIsTexture); \
INIT_GLES_NO_FPE(glLightModelx); \
INIT_GLES_NO_FPE(glLightModelxv); \
INIT_GLES_NO_FPE(glLightf); \
INIT_GLES_NO_FPE(glLightx); \
INIT_GLES_NO_FPE(glLightxv); \
INIT_GLES(glLineWidth); \
INIT_GLES_NO_FPE(glLineWidthx); \
INIT_GLES_NO_FPE(glLoadMatrixx); \
INIT_GLES_NO_FPE(glMaterialx); \
INIT_GLES_NO_FPE(glMaterialxv); \
INIT_GLES_NO_FPE(glMultMatrixf); \
INIT_GLES_NO_FPE(glMultMatrixx); \
INIT_GLES_OES(glMultiDrawArrays); \
INIT_GLES_OES(glMultiDrawElements); \
INIT_GLES_NO_FPE(glMultiTexCoord4x); \
INIT_GLES_NO_FPE(glNormal3x); \
INIT_GLES_NO_FPE(glOrthof); \
INIT_GLES_NO_FPE(glOrthox); \
INIT_GLES_NO_FPE(glPointParameterf); \
INIT_GLES_NO_FPE(glPointParameterx); \
INIT_GLES_NO_FPE(glPointParameterxv); \
INIT_GLES_OES(glPointSizePointerOES); \
INIT_GLES_NO_FPE(glPointSizex); \
INIT_GLES(glPolygonOffset); \
INIT_GLES_NO_FPE(glPolygonOffsetx); \
INIT_GLES_NO_FPE(glPopMatrix); \
INIT_GLES_NO_FPE(glPushMatrix); \
INIT_GLES_NO_FPE(glRotatef); \
INIT_GLES_NO_FPE(glRotatex); \
INIT_GLES_NO_FPE(glSampleCoveragex); \
INIT_GLES_NO_FPE(glScalef); \
INIT_GLES_NO_FPE(glScalex); \
INIT_GLES_NO_FPE(glTexEnvi); \
INIT_GLES_NO_FPE(glTexEnviv); \
INIT_GLES_NO_FPE(glTexEnvx); \
INIT_GLES_NO_FPE(glTexEnvxv); \
INIT_GLES_NO_FPE(glTexParameterx); \
INIT_GLES_NO_FPE(glTexParameterxv); \
INIT_GLES_NO_FPE(glTranslatef); \
INIT_GLES_NO_FPE(glTranslatex); \
INIT_GLES_NO_1(glUniform1f); \
INIT_GLES_NO_1(glUniform2f); \
INIT_GLES_NO_1(glUniform2i); \
INIT_GLES_NO_1(glUniform3f); \
INIT_GLES_NO_1(glUniform3i); \
INIT_GLES_NO_1(glUniform4f); \
INIT_GLES_NO_1(glUniform4i); \
INIT_GLES_NO_1(glVertexAttrib1f); \
INIT_GLES_NO_1(glVertexAttrib1fv); \
INIT_GLES_NO_1(glVertexAttrib2f); \
INIT_GLES_NO_1(glVertexAttrib2fv); \
INIT_GLES_NO_1(glVertexAttrib3f); \
INIT_GLES_NO_1(glVertexAttrib3fv); \
INIT_GLES_NO_1(glVertexAttrib4f); \


typedef struct gl_functions {
    ALL_FUNCTIONS();
} gl_functions;
extern gl_functions host_functions;
void init_gl_functions();
#undef INIT_GLES_FPE
#undef INIT_GLES_OR_FPE
#undef INIT_GLES_NO_FPE
#undef INIT_GLES_NO_1
#undef INIT_GLES_OPT
#undef INIT_GLES
#undef INIT_GLES_OR_OES
#undef INIT_GLES_EXT
#undef INIT_GLES_OES
#undef INIT_EGL
