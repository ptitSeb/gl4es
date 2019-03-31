#include "../gl/wrap/gl4es.h"
#include "../gl/wrap/stub.h"
#include "../gl/directstate.h"
#include "../gl/framebuffers.h"
#include "../gl/init.h"
#include "../gl/line.h"
#include "../gl/loader.h"
#include "../gl/render.h"
#include "../gl/texgen.h"
#include "../gl/vertexattrib.h"
#include "glx.h"
#include "hardext.h"

#define EXPORT __attribute__((visibility("default")))

//#define DEBUG_ADDRESS

#ifdef DEBUG_ADDRESS
#define MAP(func_name, func) \
    if (strcmp(name, func_name) == 0) return (void *)func;
#else
#define MAP(func_name, func) \
    if (strcmp(name, func_name) == 0) return (void *)func;
#endif

#ifdef NOEGL
 #define MAP_EGL(func_name, egl_func)
#else
 #define MAP_EGL(func_name, egl_func) \
    MAP(#func_name, egl_eglGetProcAddress(#egl_func))
#endif

#define EX(func_name) MAP(#func_name, func_name)

#define ARB(func_name) MAP(#func_name "ARB", func_name)

#define EXT(func_name) MAP(#func_name "EXT", func_name)

#define _EX(func_name) MAP(#func_name, gl4es_ ## func_name)

#define _ARB(func_name) MAP(#func_name "ARB", gl4es_ ## func_name)

#define _EXT(func_name) MAP(#func_name "EXT", gl4es_ ## func_name)

#define STUB(func_name)                       \
    if (strcmp(name, #func_name) == 0) {      \
        if(!globals4es.silentstub) LOGD("glX stub: %s\n", #func_name); \
        return (void *)glXStub;               \
    }

void glXStub(void *x, ...) {
    return;
}

void *gl4es_glXGetProcAddress(const char *name) {
#ifndef NOEGL
    LOAD_EGL(eglGetProcAddress);
#endif
#ifdef DEBUG_ADDRESS
    static int cnt = 0;
    cnt++;
#endif
    // generated gles wrappers
    #include "glesfuncs.inc"

#ifndef NOX11
    // glX calls
    _EX(glXChooseVisual);
    _EX(glXCopyContext);
    _EX(glXCreateContext);
    _EX(glXCreateNewContext);
    _EX(glXCreateContextAttribsARB);
    _EX(glXDestroyContext);
    _EX(glXGetConfig);
    _EX(glXGetCurrentDisplay);
    _EX(glXGetCurrentDrawable);
    _EX(glXIsDirect);
    _EX(glXMakeCurrent);
    _EX(glXMakeContextCurrent);
    _EX(glXQueryExtensionsString);
    _EX(glXQueryServerString);
    _EX(glXSwapBuffers);
    _EX(glXSwapIntervalEXT);
#endif //NOX11
    MAP("glXSwapIntervalMESA", gl4es_glXSwapInterval);
    MAP("glXSwapIntervalSGI", gl4es_glXSwapInterval);
#ifndef NOX11
    _EX(glXUseXFont);
    _EX(glXWaitGL);
    _EX(glXWaitX);
    _EX(glXGetCurrentContext);
    _EX(glXQueryExtension);
    _EX(glXQueryDrawable);
    _EX(glXQueryVersion);
    _EX(glXGetClientString);
    _EX(glXGetFBConfigs);
    _EX(glXChooseFBConfig);
    MAP("glXChooseFBConfigSGIX", gl4es_glXChooseFBConfig);
    _EX(glXGetFBConfigAttrib);
    _EX(glXQueryContext);
    _EX(glXGetVisualFromFBConfig);
    _EX(glXCreateWindow);
    _EX(glXDestroyWindow);
    
    _EX(glXCreatePbuffer);
    _EX(glXDestroyPbuffer);
    _EX(glXCreatePixmap);
    _EX(glXDestroyPixmap);
    _EX(glXCreateGLXPixmap);
    _EX(glXDestroyGLXPixmap);
    STUB(glXGetCurrentReadDrawable);
    STUB(glXGetSelectedEvent);
    STUB(glXSelectEvent);

    _EX(glXCreateContextAttribs);
    _ARB(glXCreateContextAttribs);
#endif //NOX11
    _EX(glXGetProcAddress);
    _ARB(glXGetProcAddress);
    // GL_EXT_texture_object (yeah, super old!)
    _EXT(glGenTextures);
    _EXT(glBindTexture);
    _EXT(glDeleteTextures);
    _EXT(glIsTexture);
    _EXT(glAreTexturesResident);
    _EXT(glPrioritizeTextures);

    // GL_EXT_polygonoffset
    _EXT(glPolygonOffset);

    // GL_ARB_vertex_buffer_object
    _ARB(glBindBuffer);
    _ARB(glBufferData);
    _ARB(glBufferSubData);
    _ARB(glDeleteBuffers);
    _ARB(glGenBuffers);
    _ARB(glIsBuffer);
    _EX(glGetBufferPointerv);
    _ARB(glGetBufferPointerv);
    _EX(glMapBuffer);
    _EX(glUnmapBuffer);
    _ARB(glMapBuffer);
    _ARB(glUnmapBuffer);
    _ARB(glGetBufferParameteriv);
    _EX(glGetBufferSubData);
    _ARB(glGetBufferSubData);

    _EX(glMapBufferRange);
    _EX(glFlushMappedBufferRange);
    // Named Buffer
    _EX(glNamedBufferData);
    _EX(glNamedBufferSubData);
    _EX(glGetNamedBufferParameteriv);
    _EX(glMapNamedBuffer);
    _EX(glUnmapNamedBuffer);
    _EX(glGetNamedBufferSubData);
    _EX(glGetNamedBufferPointerv);
    _EXT(glNamedBufferData);
    _EXT(glNamedBufferSubData);
    _EXT(glGetNamedBufferParameteriv);
    _EXT(glMapNamedBuffer);
    _EXT(glUnmapNamedBuffer);
    _EXT(glGetNamedBufferSubData);
    _EXT(glGetNamedBufferPointerv);
    // GL_ARB_vertex_array_object
    _EX(glGenVertexArrays);
    _EX(glBindVertexArray);
    _EX(glDeleteVertexArrays);
    _EX(glIsVertexArray);
    _ARB(glGenVertexArrays);
    _ARB(glBindVertexArray);
    _ARB(glDeleteVertexArrays);
    _ARB(glIsVertexArray);
    _EXT(glGenVertexArrays);
    _EXT(glBindVertexArray);
    _EXT(glDeleteVertexArrays);
    _EXT(glIsVertexArray);
    
    // GL_ARB_frameBuffer_ext
    if(hardext.fbo) {
        _EX(glFramebufferTexture1D);
        _EX(glFramebufferTexture3D);
        _EX(glFramebufferTextureLayer);
        _EX(glRenderbufferStorageMultisample);
        _EX(glBlitFramebuffer);
        _EXT(glGenFramebuffers);
        _EXT(glDeleteFramebuffers);
        _EXT(glIsFramebuffer);
        _EXT(glCheckFramebufferStatus);
        _EXT(glBindFramebuffer);
        _EXT(glFramebufferTexture2D);
        _EXT(glFramebufferTexture1D);
        _EXT(glFramebufferTexture3D);
        _EXT(glGenRenderbuffers);
        _EXT(glFramebufferRenderbuffer);
        _EXT(glDeleteRenderbuffers);
        _EXT(glRenderbufferStorage);
        _EXT(glRenderbufferStorageMultisample);
        _EXT(glBindRenderbuffer);
        _EXT(glIsRenderbuffer);
        _EXT(glGenerateMipmap);
        _EXT(glGetFramebufferAttachmentParameteriv);
        _EXT(glGetRenderbufferParameteriv);
        _EXT(glFramebufferTextureLayer);
        _EXT(glBlitFramebuffer);
        _ARB(glGenFramebuffers);
        _ARB(glDeleteFramebuffers);
        _ARB(glIsFramebuffer);
        _ARB(glCheckFramebufferStatus);
        _ARB(glBindFramebuffer);
        _ARB(glFramebufferTexture2D);
        _ARB(glFramebufferTexture1D);
        _ARB(glFramebufferTexture3D);
        _ARB(glGenRenderbuffers);
        _ARB(glFramebufferRenderbuffer);
        _ARB(glDeleteRenderbuffers);
        _ARB(glRenderbufferStorage);
        _ARB(glRenderbufferStorageMultisample);
        _ARB(glBindRenderbuffer);
        _ARB(glIsRenderbuffer);
        _ARB(glGenerateMipmap);
        _ARB(glGetFramebufferAttachmentParameteriv);
        _ARB(glGetRenderbufferParameteriv);
        _ARB(glFramebufferTextureLayer);
        _ARB(glBlitFramebuffer);
        _EX(glDrawBuffers);
        _ARB(glDrawBuffers);
        _EX(glClearBufferiv);
        _EX(glClearBufferuiv);
        _EX(glClearBufferfv);
        _EX(glClearBufferfi);
        _EX(glClearNamedFramebufferiv)
        _EX(glClearNamedFramebufferuiv)
        _EX(glClearNamedFramebufferfv)
        _EX(glClearNamedFramebufferfi)
        _EXT(glClearNamedFramebufferiv)
        _EXT(glClearNamedFramebufferuiv)
        _EXT(glClearNamedFramebufferfv)
        _EXT(glClearNamedFramebufferfi)
    }
    
    // GL_EXT_vertex_array
    _EXT(glArrayElement);
    _EXT(glDrawArrays);
    _EXT(glVertexPointer);
    _EXT(glNormalPointer);
    _EXT(glColorPointer);
    _EX(glIndexPointer);    //TODO, stub for now
    _EXT(glIndexPointer);
    _EXT(glTexCoordPointer);
    _EX(glEdgeFlagPointer); //TODO, stub for now
    _EXT(glEdgeFlagPointer);
    _EX(glGetPointerv);
    _EXT(glGetPointerv);


    // OES wrapper
    EX(glClearDepthfOES);
    EX(glClipPlanefOES);
    EX(glDepthRangefOES);
    EX(glFrustumfOES);
    EX(glGetClipPlanefOES);
    EX(glOrthofOES);

    // passthrough
    // batch thunking!
    #define THUNK(suffix, type)       \
    _EX(glColor3##suffix##v);          \
    _EX(glColor3##suffix);             \
    _EX(glColor4##suffix##v);          \
    _EX(glColor4##suffix);             \
    _EX(glSecondaryColor3##suffix##v); \
    _EX(glSecondaryColor3##suffix);    \
    _EXT(glSecondaryColor3##suffix##v); \
    _EXT(glSecondaryColor3##suffix);    \
    _EX(glIndex##suffix##v);           \
    _EX(glIndex##suffix);              \
    _EX(glNormal3##suffix##v);         \
    _EX(glNormal3##suffix);            \
    _EX(glRasterPos2##suffix##v);      \
    _EX(glRasterPos2##suffix);         \
    _EX(glRasterPos3##suffix##v);      \
    _EX(glRasterPos3##suffix);         \
    _EX(glRasterPos4##suffix##v);      \
    _EX(glRasterPos4##suffix);         \
    _EX(glWindowPos2##suffix##v);      \
    _EX(glWindowPos2##suffix);         \
    _EX(glWindowPos3##suffix##v);      \
    _EX(glWindowPos3##suffix);         \
    _EX(glVertex2##suffix##v);         \
    _EX(glVertex2##suffix);            \
    _EX(glVertex3##suffix##v);         \
    _EX(glVertex3##suffix);            \
    _EX(glVertex4##suffix##v);         \
    _EX(glVertex4##suffix);            \
    _EX(glTexCoord1##suffix##v);       \
    _EX(glTexCoord1##suffix);          \
    _EX(glTexCoord2##suffix##v);       \
    _EX(glTexCoord2##suffix);          \
    _EX(glTexCoord3##suffix##v);       \
    _EX(glTexCoord3##suffix);          \
    _EX(glTexCoord4##suffix##v);       \
    _EX(glTexCoord4##suffix);          \
    _EX(glMultiTexCoord1##suffix##v);  \
    _EX(glMultiTexCoord1##suffix);     \
    _EX(glMultiTexCoord2##suffix##v);  \
    _EX(glMultiTexCoord2##suffix);     \
    _EX(glMultiTexCoord3##suffix##v);  \
    _EX(glMultiTexCoord3##suffix);     \
    _EX(glMultiTexCoord4##suffix##v);  \
    _EX(glMultiTexCoord4##suffix);     \
    _EXT(glMultiTexCoord1##suffix##v); \
    _EXT(glMultiTexCoord1##suffix);    \
    _EXT(glMultiTexCoord2##suffix##v); \
    _EXT(glMultiTexCoord2##suffix);    \
    _EXT(glMultiTexCoord3##suffix##v); \
    _EXT(glMultiTexCoord3##suffix);    \
    _EXT(glMultiTexCoord4##suffix##v); \
    _EXT(glMultiTexCoord4##suffix);    \
    _ARB(glMultiTexCoord1##suffix##v); \
    _ARB(glMultiTexCoord1##suffix);    \
    _ARB(glMultiTexCoord2##suffix##v); \
    _ARB(glMultiTexCoord2##suffix);    \
    _ARB(glMultiTexCoord3##suffix##v); \
    _ARB(glMultiTexCoord3##suffix);    \
    _ARB(glMultiTexCoord4##suffix##v); \
    _ARB(glMultiTexCoord4##suffix);

    THUNK(b, GLbyte);
    THUNK(d, GLdouble);
    THUNK(i, GLint);
    THUNK(s, GLshort);
    THUNK(ub, GLubyte);
    THUNK(ui, GLuint);
    THUNK(us, GLushort);
    THUNK(f, GLfloat);
    #undef THUNK
    
    _EX(glPointParameterf);
    _EX(glPointParameterfv);
    _ARB(glPointParameterf);
    _ARB(glPointParameterfv);
    _EXT(glPointParameterf);
    _EXT(glPointParameterfv);

    // functions we actually define
    _EXT(glActiveTexture);
    _ARB(glActiveTexture);
    _EX(glArrayElement);
    _EX(glBegin);
    _EX(glBitmap);
    if(globals4es.blendcolor || hardext.blendcolor) {
        _EX(glBlendColor);
        _EXT(glBlendColor);
        _ARB(glBlendColor);
    }
    _EXT(glBlendEquation);
    _ARB(glBlendEquation);
    _EXT(glBlendFunc);
    _ARB(glBlendFunc);

    if(hardext.blendeq) {
        _EXT(glBlendEquationSeparate);
        _ARB(glBlendEquationSeparate);
        _EX(glBlendEquationSeparatei);
        _EXT(glBlendEquationSeparatei);
        _ARB(glBlendEquationSeparatei);
    }
    if(hardext.blendfunc) {
        _EXT(glBlendFuncSeparate);
        _ARB(glBlendFuncSeparate);
        _EX(glBlendFuncSeparatei);
        _EXT(glBlendFuncSeparatei);
        _ARB(glBlendFuncSeparatei);
    }
    _EX(glStencilMaskSeparate);
    _EXT(glStencilMaskSeparate);
    _EX(glCallList);
    _EX(glCallLists);
    _EX(glClearDepth);
    _EXT(glClientActiveTexture);
    _ARB(glClientActiveTexture);
    _EX(glClipPlane);
    _EX(glCopyPixels);
    _EX(glDeleteLists);
    _EX(glDepthRange);
    _EX(glDrawBuffer);
    _EX(glDrawPixels);
    _EX(glDrawRangeElements);
    _EXT(glDrawRangeElements);
    _EX(glEdgeFlag);
    _EX(glEnd);
    _EX(glEndList);
    _EX(glEvalCoord1d);
    _EX(glEvalCoord1f);
    _EX(glEvalCoord2d);
    _EX(glEvalCoord2f);
    _EX(glEvalCoord1dv);
    _EX(glEvalCoord1fv);
    _EX(glEvalCoord2dv);
    _EX(glEvalCoord2fv);
    _EX(glEvalMesh1);
    _EX(glEvalMesh2);
    _EX(glEvalPoint1);
    _EX(glEvalPoint2);
    _EX(glFogCoordd);
    _EX(glFogCoorddv);
    _EX(glFogCoordf);
    _EX(glFogCoordfv);
    _EX(glFogi);
    _EX(glFogiv);
    _EX(glFrustum);
    _EX(glGenLists);
    _EX(glGetDoublev);
    _EX(glGetIntegerv);
    _EX(glGetMapdv);
    _EX(glGetMapfv);
    _EX(glGetMapiv);
    _EX(glGetTexImage);
    _EX(glGetTexLevelParameterfv);
    _EX(glGetTexLevelParameteriv);
    _EX(glInitNames);
    _EX(glInterleavedArrays);
    _EX(glIsList);
    _EX(glLighti);
    _EX(glLightiv);
    _EX(glLightModeli);
    _EX(glLightModeliv);
    _EX(glLineStipple);
    _EX(glListBase);
    _EX(glLoadMatrixd);
    _EX(glLoadName);
    _EXT(glLockArrays);
    _EX(glMap1d);
    _EX(glMap1f);
    _EX(glMap2d);
    _EX(glMap2f);
    _EX(glMapGrid1d);
    _EX(glMapGrid1f);
    _EX(glMapGrid2d);
    _EX(glMapGrid2f);
    _EX(glMateriali);
    _EX(glMaterialiv);
    _EX(glMultMatrixd);
    _EX(glNewList);
    _EX(glOrtho);
    _EX(glPixelTransferf);
    _EX(glPixelTransferi);
    _EX(glPixelZoom);
    _EX(glPolygonMode);
    _EX(glPolygonStipple);
    _EX(glPopAttrib);
    _EX(glPopClientAttrib);
    _EX(glPopName);
    _EX(glPushAttrib);
    _EX(glPushClientAttrib);
    _EX(glPushName);
    _EX(glRasterPos2i);
    _EX(glReadBuffer);
    _EX(glRectd);
    _EX(glRectf);
    _EX(glRecti);
    _EX(glRects);
    _EX(glRectdv);
    _EX(glRectfv);
    _EX(glRectiv);
    _EX(glRectsv);
    _EX(glRenderMode);
    _EX(glRotated);
    _EX(glScaled);
    _EX(glSecondaryColorPointer);
    _EXT(glSecondaryColorPointer);
    _EX(glTexEnvf);
    _EX(glTexEnviv);
    _EX(glTexGend);
    _EX(glTexGendv);
    _EX(glTexGenf);
    _EX(glTexGenfv);
    _EX(glTexGeni);
    _EX(glTexGeniv);
    _EX(glTexImage1D);
    _EX(glTexImage3D);
    _EX(glTexSubImage1D);
    _EX(glTexSubImage3D);
    _EXT(glTexImage3D);
    _EXT(glTexSubImage3D);
    _EX(glCompressedTexImage1D);
    _EX(glCompressedTexSubImage1D);
    _EX(glCompressedTexImage3D);
    _EX(glCompressedTexSubImage3D);
    _EX(glGetCompressedTexImage);
    _EXT(glCompressedTexImage2D);
    _EXT(glCompressedTexSubImage2D);
    _EXT(glCompressedTexImage1D);
    _EXT(glCompressedTexSubImage1D);
    _EXT(glCompressedTexImage3D);
    _EXT(glCompressedTexSubImage3D);
    _EXT(glGetCompressedTexImage);
    _ARB(glCompressedTexImage2D);
    _ARB(glCompressedTexSubImage2D);
    _ARB(glCompressedTexImage1D);
    _ARB(glCompressedTexSubImage1D);
    _ARB(glCompressedTexImage3D);
    _ARB(glCompressedTexSubImage3D);
    _ARB(glGetCompressedTexImage);
    _EX(glCopyTexImage1D);
    _EX(glCopyTexSubImage1D);
    _EX(glTranslated);
    _EXT(glUnlockArrays);
    _EX(glGetTexGenfv);
    _EX(glGetTexGendv);
    _EX(glGetTexGeniv);
    _EX(glLoadTransposeMatrixf);
    _EX(glLoadTransposeMatrixd);
    _EX(glMultTransposeMatrixd);
    _EX(glMultTransposeMatrixf);
    // stubs for unimplemented functions
    STUB(glAccum);
    STUB(glAreTexturesResident);
    STUB(glClearAccum);
    _EX(glColorMaterial);
    _EX(glCopyTexSubImage3D);   // It's a stub, calling the 2D one
    STUB(glFeedbackBuffer);
    _EX(glGetClipPlane);
    _EX(glGetLightiv);
    _EX(glGetMaterialiv);
    _EX(glGetPixelMapfv);
    _EX(glGetPixelMapuiv);
    _EX(glGetPixelMapusv);
    STUB(glGetPolygonStipple);
    _EX(glGetStringi);
    STUB(glPassThrough);
    _EX(glPixelMapfv);
    _EX(glPixelMapuiv);
    _EX(glPixelMapusv);
    _EX(glPixelStoref);
    STUB(glPrioritizeTextures);
    STUB(glSelectBuffer);   //TODO

    _EX(glMultiDrawArrays);
    _EXT(glMultiDrawArrays);
    _EX(glMultiDrawElements);
    _EXT(glMultiDrawElements);

    _EX(glPointParameteri);
    _EX(glPointParameteriv);
    
    _EX(glFogCoordPointer);
    if(hardext.esversion>1) {
        // EXT_fog_coord supported
        _EXT(glFogCoordd);
        _EXT(glFogCoorddv);
        _EXT(glFogCoordf);
        _EXT(glFogCoordfv);
        _EXT(glFogCoordPointer);
    }
    /*STUB(glEdgeFlagPointerEXT);
    STUB(glIndexPointerEXT);*/
    
    //EXT_direct_state_access
    _EX(glClientAttribDefault);
    _EX(glPushClientAttribDefault);
    _EX(glMatrixLoadf);
    _EX(glMatrixLoadd);
    _EX(glMatrixMultf);
    _EX(glMatrixMultd);
    _EX(glMatrixLoadIdentity);
    _EX(glMatrixRotatef);
    _EX(glMatrixRotated);
    _EX(glMatrixScalef);
    _EX(glMatrixScaled);
    _EX(glMatrixTranslatef);
    _EX(glMatrixTranslated);
    _EX(glMatrixOrtho);
    _EX(glMatrixFrustum);
    _EX(glMatrixPush);
    _EX(glMatrixPop);
    _EX(glTextureParameteri);
    _EX(glTextureParameteriv);
    _EX(glTextureParameterf);
    _EX(glTextureParameterfv);
    _EX(glTextureImage1D);
    _EX(glTextureImage2D);
    _EX(glTextureSubImage1D);
    _EX(glTextureSubImage2D);
    _EX(glCopyTextureImage1D);
    _EX(glCopyTextureImage2D);
    _EX(glCopyTextureSubImage1D);
    _EX(glCopyTextureSubImage2D);
    _EX(glGetTextureImage);
    _EX(glGetTextureParameterfv);
    _EX(glGetTextureParameteriv);
    _EX(glGetTextureLevelParameterfv);
    _EX(glGetTextureLevelParameteriv);
    _EX(glTextureImage3D);
    _EX(glTextureSubImage3D);
    _EX(glCopyTextureSubImage3D);
    _EX(glBindMultiTexture);
    _EX(glMultiTexCoordPointer);
    _EX(glMultiTexEnvf);
    _EX(glMultiTexEnvfv);
    _EX(glMultiTexEnvi);
    _EX(glMultiTexEnviv);
    _EX(glMultiTexGend);
    _EX(glMultiTexGendv);
    _EX(glMultiTexGenf);
    _EX(glMultiTexGenfv);
    _EX(glMultiTexGeni);
    _EX(glMultiTexGeniv);
    _EX(glGetMultiTexEnvfv);
    _EX(glGetMultiTexEnviv);
    _EX(glGetMultiTexGendv);
    _EX(glGetMultiTexGenfv);
    _EX(glGetMultiTexGeniv);
    _EX(glMultiTexParameteri);
    _EX(glMultiTexParameteriv);
    _EX(glMultiTexParameterf);
    _EX(glMultiTexParameterfv);
    _EX(glMultiTexImage1D);
    _EX(glMultiTexImage2D);
    _EX(glMultiTexSubImage1D);
    _EX(glMultiTexSubImage2D);
    _EX(glCopyMultiTexImage1D);
    _EX(glCopyMultiTexImage2D);
    _EX(glCopyMultiTexSubImage1D);
    _EX(glCopyMultiTexSubImage2D);
    _EX(glGetMultiTexImage);
    _EX(glGetMultiTexParameterfv);
    _EX(glGetMultiTexParameteriv);
    _EX(glGetMultiTexLevelParameterfv);
    _EX(glGetMultiTexLevelParameteriv);
    _EX(glMultiTexImage3D);
    _EX(glMultiTexSubImage3D);
    _EX(glCopyMultiTexSubImage3D);
    _EX(glEnableClientStateIndexedEXT);
    _EX(glDisableClientStateIndexedEXT);
    _EX(glGetFloatIndexedvEXT);
    _EX(glGetDoubleIndexedvEXT);
    _EX(glGetIntegerIndexedvEXT);
    _EX(glGetBooleanIndexedvEXT);
    _EX(glGetPointerIndexedvEXT);
    _EX(glEnableIndexedEXT);
    _EX(glDisableIndexedEXT);
    _EX(glIsEnabledIndexedEXT);
    _EX(glCompressedTextureImage3D);
    _EX(glCompressedTextureImage2D);
    _EX(glCompressedTextureImage1D);
    _EX(glCompressedTextureSubImage3D);
    _EX(glCompressedTextureSubImage2D);
    _EX(glCompressedTextureSubImage1D);
    _EX(glGetCompressedTextureImage);
    _EX(glCompressedMultiTexImage3D);
    _EX(glCompressedMultiTexImage2D);
    _EX(glCompressedMultiTexImage1D);
    _EX(glCompressedMultiTexSubImage3D);
    _EX(glCompressedMultiTexSubImage2D);
    _EX(glCompressedMultiTexSubImage1D);
    _EX(glGetCompressedMultiTexImage);
    _EX(glMatrixLoadTransposef);
    _EX(glMatrixLoadTransposed);
    _EX(glMatrixMultTransposef);
    _EX(glMatrixMultTransposed);

    if(globals4es.queries) {
        _EX(glGenQueries);
        _EX(glIsQuery);
        _EX(glDeleteQueries);
        _EX(glBeginQuery);
        _EX(glEndQuery);
        _EX(glGetQueryiv);
        _EX(glGetQueryObjectiv);
        _EX(glGetQueryObjectuiv);
        
        _ARB(glGenQueries);
        _ARB(glIsQuery);
        _ARB(glDeleteQueries);
        _ARB(glBeginQuery);
        _ARB(glEndQuery);
        _ARB(glGetQueryiv);
        _ARB(glGetQueryObjectiv);
        _ARB(glGetQueryObjectuiv);
    }

    // GL_ARB_multisample
    _ARB(glSampleCoverage);

    // extra shaders stuff
    #define THUNK(suffix) \
    _EX(glVertexAttrib1##suffix); \
    _EX(glVertexAttrib2##suffix); \
    _EX(glVertexAttrib3##suffix); \
    _EX(glVertexAttrib4##suffix); \
    _EXT(glVertexAttrib1##suffix); \
    _EXT(glVertexAttrib2##suffix); \
    _EXT(glVertexAttrib3##suffix); \
    _EXT(glVertexAttrib4##suffix);
    THUNK(s);
    THUNK(d);
    THUNK(sv);
    THUNK(dv);
    #undef THUNK
    #define THUNK(suffix) \
    _EX(glVertexAttrib4##suffix##v); \
    _EX(glVertexAttrib4u##suffix##v); \
    _EX(glVertexAttrib4N##suffix##v); \
    _EX(glVertexAttrib4Nu##suffix##v);\
    _EXT(glVertexAttrib4##suffix##v); \
    _EXT(glVertexAttrib4u##suffix##v); \
    _EXT(glVertexAttrib4N##suffix##v); \
    _EXT(glVertexAttrib4Nu##suffix##v);
    THUNK(b);
    THUNK(s);
    THUNK(i);
    #undef THUNK
    _EX(glGetVertexAttribdv);
    _EXT(glGetVertexAttribdv);
    _ARB(glGetVertexAttribdv);
    _EX(glVertexAttrib4Nub);
    _EXT(glVertexAttrib4Nub);
    _ARB(glVertexAttrib4Nub);
    // arb version of shader stuffs
    //  GL_ARB_vertex_shader
    _ARB(glVertexAttrib1f);
    _ARB(glVertexAttrib1s);
    _ARB(glVertexAttrib1d);
    _ARB(glVertexAttrib2f);
    _ARB(glVertexAttrib2s);
    _ARB(glVertexAttrib2d);
    _ARB(glVertexAttrib3f);
    _ARB(glVertexAttrib3s);
    _ARB(glVertexAttrib3d);
    _ARB(glVertexAttrib4f);
    _ARB(glVertexAttrib4s);
    _ARB(glVertexAttrib4d);
    _ARB(glVertexAttrib4Nub);
    _ARB(glVertexAttrib1fv);
    _ARB(glVertexAttrib1sv);
    _ARB(glVertexAttrib1dv);
    _ARB(glVertexAttrib2fv);
    _ARB(glVertexAttrib2sv);
    _ARB(glVertexAttrib2dv);
    _ARB(glVertexAttrib3fv);
    _ARB(glVertexAttrib3sv);
    _ARB(glVertexAttrib3dv);
    _ARB(glVertexAttrib4fv);
    _ARB(glVertexAttrib4sv);
    _ARB(glVertexAttrib4dv);
    _ARB(glVertexAttrib4iv);
    _ARB(glVertexAttrib4bv);
    _ARB(glVertexAttrib4ubv);
    _ARB(glVertexAttrib4usv);
    _ARB(glVertexAttrib4uiv);
    _ARB(glVertexAttrib4Nbv);
    _ARB(glVertexAttrib4Nsv);
    _ARB(glVertexAttrib4Niv);
    _ARB(glVertexAttrib4Nubv);
    _ARB(glVertexAttrib4Nusv);
    _ARB(glVertexAttrib4Nuiv);
    _ARB(glVertexAttribPointer);
    _ARB(glEnableVertexAttribArray);
    _ARB(glDisableVertexAttribArray);
    _ARB(glBindAttribLocation);
    _ARB(glGetActiveAttrib);
    _ARB(glGetAttribLocation);
    _ARB(glGetVertexAttribdv);
    _ARB(glGetVertexAttribfv);
    _ARB(glGetVertexAttribiv);
    _ARB(glGetVertexAttribPointerv);
    // GL_ARB_fragment_shader (nothing)
    // GL_ARGB_shader_objects
    _ARB(glDeleteObject);
    _ARB(glGetHandle);
    _ARB(glDetachObject);
    _ARB(glCreateShaderObject);
    _ARB(glShaderSource);
    _ARB(glCompileShader);
    _ARB(glCreateProgramObject);
    _ARB(glAttachObject);
    _ARB(glLinkProgram);
    _ARB(glUseProgramObject);
    _ARB(glValidateProgram);
    _ARB(glUniform1f);
    _ARB(glUniform2f);
    _ARB(glUniform3f);
    _ARB(glUniform4f);
    _ARB(glUniform1i);
    _ARB(glUniform2i);
    _ARB(glUniform3i);
    _ARB(glUniform4i);
    _ARB(glUniform1fv);
    _ARB(glUniform2fv);
    _ARB(glUniform3fv);
    _ARB(glUniform4fv);
    _ARB(glUniform1iv);
    _ARB(glUniform2iv);
    _ARB(glUniform3iv);
    _ARB(glUniform4iv);
    _ARB(glUniformMatrix2fv);
    _ARB(glUniformMatrix3fv);
    _ARB(glUniformMatrix4fv);
    _ARB(glGetObjectParameterfv);
    _ARB(glGetObjectParameteriv);
    _ARB(glGetInfoLog);
    _ARB(glGetAttachedObjects);
    _ARB(glGetUniformLocation);
    _ARB(glGetActiveUniform);
    _ARB(glGetUniformfv);
    _ARB(glGetUniformiv);
    _ARB(glGetShaderSource);
    _EX(glProgramUniform1f);
    _EX(glProgramUniform2f);
    _EX(glProgramUniform3f);
    _EX(glProgramUniform4f);
    _EX(glProgramUniform1i);
    _EX(glProgramUniform2i);
    _EX(glProgramUniform3i);
    _EX(glProgramUniform4i);
    _EX(glProgramUniform1fv);
    _EX(glProgramUniform2fv);
    _EX(glProgramUniform3fv);
    _EX(glProgramUniform4fv);
    _EX(glProgramUniform1iv);
    _EX(glProgramUniform2iv);
    _EX(glProgramUniform3iv);
    _EX(glProgramUniform4iv);
    _EX(glProgramUniformMatrix2fv);
    _EX(glProgramUniformMatrix3fv);
    _EX(glProgramUniformMatrix4fv);
    // EXT version of Shaders functions
    _EXT(glAttachShader);
    _EXT(glBindAttribLocation);
    _EXT(glCompileShader);
    _EXT(glCreateProgram);
    _EXT(glCreateShader);
    _EXT(glDeleteProgram);
    _EXT(glDeleteShader);
    _EXT(glDetachShader);
    _EXT(glGetActiveAttrib);
    _EXT(glGetActiveUniform);
    _EXT(glGetAttachedShaders);
    _EXT(glGetAttribLocation);
    _EXT(glGetProgramInfoLog);
    _EXT(glGetProgramiv);
    _EXT(glGetShaderInfoLog);
    _EXT(glGetShaderPrecisionFormat);
    _EXT(glGetShaderSource);
    _EXT(glGetShaderiv);
    _EXT(glGetUniformLocation);
    _EXT(glGetUniformfv);
    _EXT(glGetUniformiv);
    _EXT(glGetVertexAttribPointerv);
    _EXT(glGetVertexAttribfv);
    _EXT(glGetVertexAttribiv);
    _EXT(glIsProgram);
    _EXT(glIsShader);
    _EXT(glReleaseShaderCompiler);
    _EXT(glShaderBinary);
    _EXT(glShaderSource);
    _EXT(glUniform1f);
    _EXT(glUniform1fv);
    _EXT(glUniform1i);
    _EXT(glUniform1iv);
    _EXT(glUniform2f);
    _EXT(glUniform2fv);
    _EXT(glUniform2i);
    _EXT(glUniform2iv);
    _EXT(glUniform3f);
    _EXT(glUniform3fv);
    _EXT(glUniform3i);
    _EXT(glUniform3iv);
    _EXT(glUniform4f);
    _EXT(glUniform4fv);
    _EXT(glUniform4i);
    _EXT(glUniform4iv);
    _EXT(glUniformMatrix2fv);
    _EXT(glUniformMatrix3fv);
    _EXT(glUniformMatrix4fv);
    _EXT(glUseProgram);
    _EXT(glValidateProgram);
    _EXT(glVertexAttrib1f);
    _EXT(glVertexAttrib1fv);
    _EXT(glVertexAttrib2f);
    _EXT(glVertexAttrib2fv);
    _EXT(glVertexAttrib3f);
    _EXT(glVertexAttrib3fv);
    _EXT(glVertexAttrib4f);
    _EXT(glVertexAttrib4fv);
    _EXT(glVertexAttribPointer);
    _EXT(glVertexPointer);
    _EXT(glProgramUniform1f);
    _EXT(glProgramUniform2f);
    _EXT(glProgramUniform3f);
    _EXT(glProgramUniform4f);
    _EXT(glProgramUniform1i);
    _EXT(glProgramUniform2i);
    _EXT(glProgramUniform3i);
    _EXT(glProgramUniform4i);
    _EXT(glProgramUniform1fv);
    _EXT(glProgramUniform2fv);
    _EXT(glProgramUniform3fv);
    _EXT(glProgramUniform4fv);
    _EXT(glProgramUniform1iv);
    _EXT(glProgramUniform2iv);
    _EXT(glProgramUniform3iv);
    _EXT(glProgramUniform4iv);
    _EXT(glProgramUniformMatrix2fv);
    _EXT(glProgramUniformMatrix3fv);
    _EXT(glProgramUniformMatrix4fv);

    //ARB_draw_elements_base_vertex / EXT_draw_elements_base_vertex
    _EX(glDrawElementsBaseVertex);
    _EXT(glDrawElementsBaseVertex);
    _ARB(glDrawElementsBaseVertex);
    _EX(glDrawRangeElementsBaseVertex);
    _EXT(glDrawRangeElementsBaseVertex);
    _ARB(glDrawRangeElementsBaseVertex);
    _EX(glMultiDrawElementsBaseVertex);
    _EXT(glMultiDrawElementsBaseVertex);
    _ARB(glMultiDrawElementsBaseVertex);

    //GL_ARB_draw_instanced
    _EX(glDrawArraysInstanced);
    _EXT(glDrawArraysInstanced); // not sure _EXT is needed...
    _ARB(glDrawArraysInstanced);
    _EX(glDrawElementsInstanced);
    _EXT(glDrawElementsInstanced);
    _ARB(glDrawElementsInstanced);
    _EX(glDrawElementsInstancedBaseVertex);
    _EXT(glDrawElementsInstancedBaseVertex);
    _ARB(glDrawElementsInstancedBaseVertex);

    //GL_ARB_instanced_arrays
    _EX(glVertexAttribDivisor);
    _EXT(glVertexAttribDivisor);
    _ARB(glVertexAttribDivisor);

    // stub non-squared matrix access
    STUB(glUniformMatrix2x3fv);
    STUB(glUniformMatrix3x2fv);
    STUB(glUniformMatrix2x4fv);
    STUB(glUniformMatrix4x2fv);
    STUB(glUniformMatrix3x4fv);
    STUB(glUniformMatrix4x3fv);
            

    if (!globals4es.silentstub) LOGD("glXGetProcAddress: %s not found.\n", name);
    return NULL;
}
#ifdef AMIGAOS4
void* aglGetProcAddress(const char* name) AliasExport("gl4es_glXGetProcAddress");
#else
void* glXGetProcAddress(const char* name) AliasExport("gl4es_glXGetProcAddress");
void* glXGetProcAddressARB(const char* name) AliasExport("gl4es_glXGetProcAddress");
#endif