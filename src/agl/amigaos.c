#include "amigaos.h"

#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include <proto/exec.h>
// make sure we don't use inline version here
#undef __USE_INLINE__
#include <proto/ogles2.h>

struct Library *LOGLES2 = NULL; 
struct OGLES2IFace *IOGLES2 = NULL;

// Open OGLES2 library and interface
void os4OpenLib(void** lib)
{
    LOGLES2 = IExec->OpenLibrary("ogles2.library", 0);
    if(!LOGLES2) {
        printf("LIBGL: Warning, cannot open ogles2 Library!\n");
        return;
    }
    IOGLES2 = (struct OGLES2IFace *)IExec->GetInterface(LOGLES2, "main", 1, NULL); 
    if(!IOGLES2) {
        printf("LIBGL: Warning, cannot openogles2 Interface!\n");
        IExec->CloseLibrary(LOGLES2);
        LOGLES2 = NULL;
    }
    *lib = LOGLES2;
    // small debug message, always helpfull at beggining
    printf("LIBGL: OGLES2 Library and Interface open successfuly\n");
}

// Close OGLES2 lib and interface
void os4CloseLib()
{
    if(IOGLES2) {
        IExec->DropInterface((struct Interface*)IOGLES2);
        IOGLES2 = NULL;
    }
    if(LOGLES2) {
        IExec->CloseLibrary(LOGLES2);
        LOGLES2 = NULL;
    }
    printf("LIBGL: OGLES2 Library and Interface closed\n");
}



// Using glXXX name, return the function pointer of that function in ogles2 library
#define MAP(func_name, func) \
    if (strcmp(name, func_name) == 0) return (void *)IOGLES2->func;

#define EX(func_name) MAP(#func_name, func_name)

void* os4GetProcAddress(const char* name)
{
    if(!IOGLES2)
        return NULL;
    // All GL functions from OGLES2 drivers
    EX(glActiveTexture)
    EX(glAttachShader)
    EX(glBindAttribLocation)
    EX(glBindBuffer)
    EX(glBindFramebuffer)
    EX(glBindRenderbuffer)
    EX(glBindTexture)
    EX(glBlendColor)
    EX(glBlendEquation)
    EX(glBlendEquationSeparate)
    EX(glBlendFunc)
    EX(glBlendFuncSeparate)
    EX(glBufferData)
    EX(glBufferSubData)
    EX(glCheckFramebufferStatus)
    EX(glClear)
    EX(glClearColor)
    EX(glClearDepthf)
    EX(glClearStencil)
    EX(glColorMask)
    EX(glCompileShader)
    EX(glCompressedTexImage2D)
    EX(glCompressedTexSubImage2D)
    EX(glCopyTexImage2D)
    EX(glCopyTexSubImage2D)
    EX(glCreateProgram)
    EX(glCreateShader)
    EX(glCullFace)
    EX(glDeleteBuffers)
    EX(glDeleteFramebuffers)
    EX(glDeleteProgram)
    EX(glDeleteRenderbuffers)
    EX(glDeleteShader)
    EX(glDeleteTextures)
    EX(glDepthFunc)
    EX(glDepthMask)
    EX(glDepthRangef)
    EX(glDetachShader)
    EX(glDisable)
    EX(glDisableVertexAttribArray)
    EX(glDrawArrays)
    EX(glDrawElements)
    EX(glEnable)
    EX(glEnableVertexAttribArray)
    EX(glFinish)
    EX(glFlush)
    EX(glFramebufferRenderbuffer)
    EX(glFramebufferTexture2D)
    EX(glFrontFace)
    EX(glGenBuffers)
    EX(glGenerateMipmap)
    EX(glGenFramebuffers)
    EX(glGenRenderbuffers)
    EX(glGenTextures)
    EX(glGetActiveAttrib)
    EX(glGetActiveUniform)
    EX(glGetAttachedShaders)
    EX(glGetAttribLocation)
    EX(glGetBooleanv)
    EX(glGetBufferParameteriv)
    EX(glGetError)
    EX(glGetFloatv)
    EX(glGetFramebufferAttachmentParameteriv)
    EX(glGetIntegerv)
    EX(glGetProgramiv)
    EX(glGetProgramInfoLog)
    EX(glGetRenderbufferParameteriv)
    EX(glGetShaderiv)
    EX(glGetShaderInfoLog)
    EX(glGetShaderPrecisionFormat)
    EX(glGetShaderSource)
    EX(glGetString)
    EX(glGetTexParameterfv)
    EX(glGetTexParameteriv)
    EX(glGetUniformfv)
    EX(glGetUniformiv)
    EX(glGetUniformLocation)
    EX(glGetVertexAttribfv)
    EX(glGetVertexAttribiv)
    EX(glGetVertexAttribPointerv)
    EX(glHint)
    EX(glIsBuffer)
    EX(glIsEnabled)
    EX(glIsFramebuffer)
    EX(glIsProgram)
    EX(glIsRenderbuffer)
    EX(glIsShader)
    EX(glIsTexture)
    EX(glLineWidth)
    EX(glLinkProgram)
    EX(glPixelStorei)
    EX(glPolygonOffset)
    EX(glReadPixels)
    EX(glReleaseShaderCompiler)
    EX(glRenderbufferStorage)
    EX(glSampleCoverage)
    EX(glScissor)
    EX(glShaderBinary)
    EX(glShaderSource)
    EX(glStencilFunc)
    EX(glStencilFuncSeparate)
    EX(glStencilMask)
    EX(glStencilMaskSeparate)
    EX(glStencilOp)
    EX(glStencilOpSeparate)
    EX(glTexImage2D)
    EX(glTexParameterf)
    EX(glTexParameterfv)
    EX(glTexParameteri)
    EX(glTexParameteriv)
    EX(glTexSubImage2D)
    EX(glUniform1f)
    EX(glUniform1fv)
    EX(glUniform1i)
    EX(glUniform1iv)
    EX(glUniform2f)
    EX(glUniform2fv)
    EX(glUniform2i)
    EX(glUniform2iv)
    EX(glUniform3f)
    EX(glUniform3fv)
    EX(glUniform3i)
    EX(glUniform3iv)
    EX(glUniform4f)
    EX(glUniform4fv)
    EX(glUniform4i)
    EX(glUniform4iv)
    EX(glUniformMatrix2fv)
    EX(glUniformMatrix3fv)
    EX(glUniformMatrix4fv)
    EX(glUseProgram)
    EX(glValidateProgram)
    EX(glVertexAttrib1f)
    EX(glVertexAttrib1fv)
    EX(glVertexAttrib2f)
    EX(glVertexAttrib2fv)
    EX(glVertexAttrib3f)
    EX(glVertexAttrib3fv)
    EX(glVertexAttrib4f)
    EX(glVertexAttrib4fv)
    EX(glVertexAttribPointer)
    EX(glViewport)
    //EX(glPolygonMode) //This is a non-standard function, and gl4es will ignore it (and emulate it), even if Amiga OGLES2 driver implement it
    // Also export AGL functions
    EX(aglCreateContext)
    EX(aglCreateContextTags)
    EX(aglDestroyContext)
    EX(aglMakeCurrent)
    EX(aglSwapBuffers)
    EX(aglSetBitmap)

    return NULL;
}