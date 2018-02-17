#include "amigaos.h"

#include <stdlib.h> 
#include <stdio.h>
#include <proto/exec.h> 
#include <proto/ogles2.h>

struct Library *LOGLES2 = NULL; 
struct OGLES2IFace *IOGLES2 = NULL;

struct Interface *getInterface(char *libname) 
{ 
    struct Library *lib; 
     
    lib = IExec->OpenLibrary("ogles2.library", 0); 
    if (lib) 
        return IExec->GetInterface(lib, "main", 1, NULL); 
     
    return 0; 
} 

void dropInterface(struct Interface *iface) 
{ 
    if (iface) 
    { 
        struct Library *lib = iface->Data.LibBase; 
        IExec->DropInterface(iface); 
        IExec->CloseLibrary(lib); 
    } 
}

// Open OGLES2 library and interface
void os4OpenLib()
{
    LOGLES2 = IExec->OpenLibrary("ogles2.library", 0);
    if(!LOGLES2) {
        printf("LIBGL: Warning, cannot open ogles2 Library!\n");
        return;
    }
    IOGLES2 = (struct OGLES2IFace *)getInterface("ogles2.library"); 
    if(!IOGLES2) {
        printf("LIBGL: Warning, cannot openogles2 Interface!\n");
        IExec->CloseLibrary(LOGLES2);
        LOGLES2 = NULL;
    }
}

// Close OGLES2 lib and interface
void os4CloseLib()
{
    if(IOGLES2) {
        IExec->DropInterface(IOGLES2);
        IOGLES2 = NULL;
    }
    if(LOGLES2) {
        IExec->CloseLibrary(LOGLES2);
        LOGLES2 = NULL;
    }
}

// Using glXXX name, return the function pointer of that function in ogles2 library
#define MAP(func_name, func) \
    if (strcmp(name, func_name) == 0) return (void *)IOGLES2->func;

void* os4GetProcAddress(const char* name)
{
    if(!IOGLES2)
        return NULL;
    // All GL functions from OGLES2 drivers
    MAP(glActiveTexture)
    MAP(glAttachShader)
    MAP(glBindAttribLocation)
    MAP(glBindBuffer)
    MAP(glBindFramebuffer)
    MAP(glBindRenderbuffer)
    MAP(glBindTexture)
    MAP(glBlendColor)
    MAP(glBlendEquation)
    MAP(glBlendEquationSeparate)
    MAP(glBlendFunc)
    MAP(glBlendFuncSeparate)
    MAP(glBufferData)
    MAP(glBufferSubData)
    MAP(glCheckFramebufferStatus)
    MAP(glClear)
    MAP(glClearColor)
    MAP(glClearDepthf)
    MAP(glClearStencil)
    MAP(glColorMask)
    MAP(glCompileShader)
    MAP(glCompressedTexImage2D)
    MAP(glCompressedTexSubImage2D)
    MAP(glCopyTexImage2D)
    MAP(glCopyTexSubImage2D)
    MAP(glCreateProgram)
    MAP(glCreateShader)
    MAP(glCullFace)
    MAP(glDeleteBuffers)
    MAP(glDeleteFramebuffers)
    MAP(glDeleteProgram)
    MAP(glDeleteRenderbuffers)
    MAP(glDeleteShader)
    MAP(glDeleteTextures)
    MAP(glDepthFunc)
    MAP(glDepthMask)
    MAP(glDepthRangef)
    MAP(glDetachShader)
    MAP(glDisable)
    MAP(glDisableVertexAttribArray)
    MAP(glDrawArrays)
    MAP(glDrawElements)
    MAP(glEnable)
    MAP(glEnableVertexAttribArray)
    MAP(glFinish)
    MAP(glFlush)
    MAP(glFramebufferRenderbuffer)
    MAP(glFramebufferTexture2D)
    MAP(glFrontFace)
    MAP(glGenBuffers)
    MAP(glGenerateMipmap)
    MAP(glGenFramebuffers)
    MAP(glGenRenderbuffers)
    MAP(glGenTextures)
    MAP(glGetActiveAttrib)
    MAP(glGetActiveUniform)
    MAP(glGetAttachedShaders)
    MAP(glGetAttribLocation)
    MAP(glGetBooleanv)
    MAP(glGetBufferParameteriv)
    MAP(glGetError)
    MAP(glGetFloatv)
    MAP(glGetFramebufferAttachmentParameteriv)
    MAP(glGetIntegerv)
    MAP(glGetProgramiv)
    MAP(glGetProgramInfoLog)
    MAP(glGetRenderbufferParameteriv)
    MAP(glGetShaderiv)
    MAP(glGetShaderInfoLog)
    MAP(glGetShaderPrecisionFormat)
    MAP(glGetShaderSource)
    MAP(glGetString)
    MAP(glGetTexParameterfv)
    MAP(glGetTexParameteriv)
    MAP(glGetUniformfv)
    MAP(glGetUniformiv)
    MAP(glGetUniformLocation)
    MAP(glGetVertexAttribfv)
    MAP(glGetVertexAttribiv)
    MAP(glGetVertexAttribPointerv)
    MAP(glHint)
    MAP(glIsBuffer)
    MAP(glIsEnabled)
    MAP(glIsFramebuffer)
    MAP(glIsProgram)
    MAP(glIsRenderbuffer)
    MAP(glIsShader)
    MAP(glIsTexture)
    MAP(glLineWidth)
    MAP(glLinkProgram)
    MAP(glPixelStorei)
    MAP(glPolygonOffset)
    MAP(glReadPixels)
    MAP(glReleaseShaderCompiler)
    MAP(glRenderbufferStorage)
    MAP(glSampleCoverage)
    MAP(glScissor)
    MAP(glShaderBinary)
    MAP(glShaderSource)
    MAP(glStencilFunc)
    MAP(glStencilFuncSeparate)
    MAP(glStencilMask)
    MAP(glStencilMaskSeparate)
    MAP(glStencilOp)
    MAP(glStencilOpSeparate)
    MAP(glTexImage2D)
    MAP(glTexParameterf)
    MAP(glTexParameterfv)
    MAP(glTexParameteri)
    MAP(glTexParameteriv)
    MAP(glTexSubImage2D)
    MAP(glUniform1f)
    MAP(glUniform1fv)
    MAP(glUniform1i)
    MAP(glUniform1iv)
    MAP(glUniform2f)
    MAP(glUniform2fv)
    MAP(glUniform2i)
    MAP(glUniform2iv)
    MAP(glUniform3f)
    MAP(glUniform3fv)
    MAP(glUniform3i)
    MAP(glUniform3iv)
    MAP(glUniform4f)
    MAP(glUniform4fv)
    MAP(glUniform4i)
    MAP(glUniform4iv)
    MAP(glUniformMatrix2fv)
    MAP(glUniformMatrix3fv)
    MAP(glUniformMatrix4fv)
    MAP(glUseProgram)
    MAP(glValidateProgram)
    MAP(glVertexAttrib1f)
    MAP(glVertexAttrib1fv)
    MAP(glVertexAttrib2f)
    MAP(glVertexAttrib2fv)
    MAP(glVertexAttrib3f)
    MAP(glVertexAttrib3fv)
    MAP(glVertexAttrib4f)
    MAP(glVertexAttrib4fv)
    MAP(glVertexAttribPointer)
    MAP(glViewport)
    // Also export AGL functions
    MAP(aglCreateContext
    MAP(aglCreateContextTags
    MAP(aglDestroyContext
    MAP(aglMakeCurrent
    MAP(aglSwapBuffers
    MAP(aglSetBitmap

    return NULL;
}