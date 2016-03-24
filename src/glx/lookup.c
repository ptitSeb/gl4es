#ifdef ANDROID
#include "../gl/gl.h"
#endif
#include "glx.h"

#include "../gl/directstate.h"
//#define DEBUG_ADDRESS

extern int export_blendcolor;

#ifdef DEBUG_ADDRESS
#define MAP(func_name, func) \
    if(cnt==1) {if ((uint32_t)((void*)func) <0x4000000) printf("glxGetProcAddress %s = %p\n", func_name, (void*)func);} if (strcmp(name, func_name) == 0) return (void *)func;
#else
#define MAP(func_name, func) \
    if (strcmp(name, func_name) == 0) return (void *)func;
#endif

#define MAP_EGL(func_name, egl_func) \
    MAP(#func_name, egl_eglGetProcAddress(#egl_func))

#define EX(func_name) MAP(#func_name, func_name)

#define ARB(func_name) MAP(#func_name "ARB", func_name)

#define EXT(func_name) MAP(#func_name "EXT", func_name)

#define _EX(func_name) MAP(#func_name, glshim_ ## func_name)

#define _ARB(func_name) MAP(#func_name "ARB", glshim_ ## func_name)

#define _EXT(func_name) MAP(#func_name "EXT", glshim_ ## func_name)

#define STUB(func_name)                       \
    if (strcmp(name, #func_name) == 0) {      \
        printf("glX stub: %s\n", #func_name); \
        return (void *)glXStub;               \
    }

void glXStub(void *x, ...) {
    return;
}

void *glXGetProcAddressARB(const char *name) {
    LOAD_EGL(eglGetProcAddress);
#ifdef DEBUG_ADDRESS
    static int cnt = 0;
    cnt++;
#endif
    // generated gles wrappers
#ifdef USE_ES2
    #include "gles2funcs.inc"
#else
    #include "glesfuncs.inc"
#endif

#ifndef ANDROID
    // glX calls
    EX(glXChooseVisual);
    EX(glXCopyContext);
    EX(glXCreateContext);
    EX(glXCreateNewContext);
	EX(glXCreateContextAttribsARB);
    EX(glXCreateGLXPixmap);
    EX(glXDestroyContext);
    EX(glXDestroyGLXPixmap);
    EX(glXGetConfig);
    EX(glXGetCurrentDisplay);
    EX(glXGetCurrentDrawable);
    EX(glXIsDirect);
    EX(glXMakeCurrent);
    EX(glXMakeContextCurrent);
    EX(glXQueryExtensionsString);
    EX(glXQueryServerString);
    EX(glXSwapBuffers);
    EX(glXSwapIntervalEXT);
#endif //ANDROID
    EX(glXSwapIntervalMESA);
    EX(glXSwapIntervalSGI);
#ifndef ANDROID
    EX(glXUseXFont);
    EX(glXWaitGL);
    EX(glXWaitX);
    EX(glXGetCurrentContext);
    EX(glXQueryExtension);
    EX(glXQueryDrawable);
    EX(glXQueryVersion);
    EX(glXGetClientString);
    EX(glXGetFBConfigs);
    EX(glXChooseFBConfig);
    EX(glXChooseFBConfigSGIX);
    EX(glXGetFBConfigAttrib);
    EX(glXQueryContext);
    EX(glXGetVisualFromFBConfig);
    EX(glXCreateWindow);
    EX(glXDestroyWindow);
    
    STUB(glXCreatePbuffer); // to do, using Renderbuffers....
    STUB(glXDestroyPbuffer);
    STUB(glXCreatePixmap);
    STUB(glXDestroyPixmap);
    STUB(glXGetCurrentReadDrawable);
    STUB(glXGetSelectedEvent);
    STUB(glXSelectEvent);
#endif //ANDROID
    
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

    // GL_ARB_vertex_array_object
    _EX(glGenVertexArrays);
    _EX(glBindVertexArray);
    _EX(glDeleteVertexArrays);
    _EX(glIsVertexArray);
    _ARB(glGenVertexArrays);
    _ARB(glBindVertexArray);
    _ARB(glDeleteVertexArrays);
    _ARB(glIsVertexArray);
    
    // GL_ARB_frameBuffer_ext
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
    STUB(glDrawBuffersARB);
    
        /*
    MAP_EGL(glGenFramebuffersARB, glGenFramebuffersOES);
    MAP_EGL(glDeleteFramebuffersARB, glDeleteFramebuffersOES);
    MAP_EGL(glBindFramebufferARB, glBindFramebufferOES);
    MAP_EGL(glFramebufferRenderbufferARB, glFramebufferRenderbufferOES);
    MAP_EGL(glFramebufferTexture2DARB, glFramebufferTexture2DOES);
    MAP_EGL(glIsFramebufferARB, glIsFramebufferOES);
    MAP_EGL(glGenRenderbuffersARB, glGenRenderbuffersOES);
    MAP_EGL(glDeleteRenderbuffersARB, glDeleteRenderbuffersOES);
    MAP_EGL(glCheckFramebufferStatusARB, glCheckFramebufferStatusOES);
    MAP_EGL(glRenderbufferStorageARB, glRenderbufferStorageOES);
    MAP_EGL(glBindRenderbufferARB, glBindRenderbufferOES);
    MAP_EGL(glIsRenderbufferARB, glIsRenderbufferOES);
    */

    // GL_EXT_vertex_array
    _EXT(glArrayElement);
    _EXT(glDrawArrays);
    _EXT(glVertexPointer);
    _EXT(glNormalPointer);
    _EXT(glColorPointer);
    _EX(glIndexPointer);	//TODO, stub for now
    _EXT(glIndexPointer);
    _EXT(glTexCoordPointer);
    _EX(glEdgeFlagPointer);	//TODO, stub for now
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

#ifdef USE_ES2
    _EX(glCompileShaderARB);
    _EX(glCreateShaderObjectARB);
    _EX(glGetObjectParameterivARB);
    _EX(glShaderSourceARB);
#endif

    // functions we actually define
    _EXT(glActiveTexture);
    _ARB(glActiveTexture);
    _EX(glArrayElement);
    _EX(glBegin);
    _EX(glBitmap);
    if(export_blendcolor) {
        _EX(glBlendColor);
        _EXT(glBlendColor);
        _ARB(glBlendColor);
    }
    _EXT(glBlendEquation);
    _ARB(glBlendEquation);
    _EXT(glBlendFunc);
    _ARB(glBlendFunc);
#ifndef ODROID
    _EXT(glBlendEquationSeparate);
    _ARB(glBlendEquationSeparate);
    _EX(glBlendEquationSeparatei);
    _EXT(glBlendEquationSeparatei);
    _ARB(glBlendEquationSeparatei);
    _EXT(glBlendFuncSeparate);
    _ARB(glBlendFuncSeparate);
    _EX(glBlendFuncSeparatei);
    _EXT(glBlendFuncSeparatei);
    _ARB(glBlendFuncSeparatei);
#endif
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
#ifndef USE_ES2
    _EX(glLighti);
    _EX(glLightiv);
    _EX(glLightModeli);
    _EX(glLightModeliv);
#endif
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
	_EX(glLoadTransposeMatrixf);
	_EX(glLoadTransposeMatrixd);
	_EX(glMultTransposeMatrixd);
	_EX(glMultTransposeMatrixf);
    // stubs for unimplemented functions
    STUB(glAccum);
    STUB(glAreTexturesResident);
    STUB(glClearAccum);
    STUB(glColorMaterial);
    STUB(glCopyTexImage3D);
    STUB(glCopyTexSubImage3D);
    STUB(glFeedbackBuffer);
    STUB(glGetClipPlane);
    STUB(glGetLightiv);
    STUB(glGetMaterialiv);
    STUB(glGetPixelMapfv);
    STUB(glGetPixelMapuiv);
    STUB(glGetPixelMapusv);
    STUB(glGetPolygonStipple);
    STUB(glGetStringi);
    STUB(glGetTexGendv);
    //STUB(glGetTexGenfv);
    STUB(glGetTexGeniv);    //TODO
    STUB(glMaterialiv);     //TODO
    STUB(glPassThrough);
    STUB(glPixelMapfv);
    STUB(glPixelMapuiv);
    STUB(glPixelMapusv);
    _EX(glPixelStoref);
    STUB(glPrioritizeTextures);
    STUB(glSelectBuffer);   //TODO
    
    STUB(glFogCoordPointer);
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
    STUB(EnableClientStateIndexedEXT);
    STUB(DisableClientStateIndexedEXT);
    STUB(GetFloatIndexedvEXT);
    STUB(GetDoubleIndexedvEXT);
    STUB(GetPointerIndexedvEXT);
    STUB(EnableIndexedEXT);
    STUB(DisableIndexedEXT);
    STUB(IsEnabledIndexedEXT);
    STUB(GetIntegerIndexedvEXT);
    STUB(GetBooleanIndexedvEXT);
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

    printf("glXGetProcAddress: %s not found.\n", name);
    return NULL;
}

void *glXGetProcAddress(const char *name) {
    return glXGetProcAddressARB(name);
}
