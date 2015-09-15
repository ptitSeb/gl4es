#ifdef ANDROID
#include "../gl/gl.h"
#include "glx.h"
#else
#include "glx.h"
#endif



#define MAP(func_name, func) \
    if (strcmp(name, func_name) == 0) return (void *)func;

#define MAP_EGL(func_name, egl_func) \
    MAP(#func_name, egl_eglGetProcAddress(#egl_func))

#define EX(func_name) MAP(#func_name, func_name)

#define ARB(func_name) MAP(#func_name "ARB", func_name)

#define EXT(func_name) MAP(#func_name "EXT", func_name)

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
    ARB(glBindBuffer);
    ARB(glBufferData);
    ARB(glBufferSubData);
    ARB(glDeleteBuffers);
    ARB(glGenBuffers);
    ARB(glIsBuffer);
    EX(glGetBufferPointerv);
    ARB(glGetBufferPointerv);
    EX(glMapBuffer);
    EX(glUnmapBuffer);
    ARB(glMapBuffer);
    ARB(glUnmapBuffer);
    ARB(glGetBufferParameteriv);
    EX(glGetBufferSubData);
    ARB(glGetBufferSubData);
    
    // GL_ARB_frameBuffer_ext
    EX(glFramebufferTexture1D);
    EX(glFramebufferTexture3D);
    EX(glFramebufferTextureLayer);
    EX(glRenderbufferStorageMultisample);
    EX(glBlitFramebuffer);
    EXT(glGenFramebuffers);
    EXT(glDeleteFramebuffers);
    EXT(glIsFramebuffer);
    EXT(glCheckFramebufferStatus);
    EXT(glBindFramebuffer);
    EXT(glFramebufferTexture2D);
    EXT(glFramebufferTexture1D);
    EXT(glFramebufferTexture3D);
    EXT(glGenRenderbuffers);
    EXT(glFramebufferRenderbuffer);
    EXT(glDeleteRenderbuffers);
    EXT(glRenderbufferStorage);
    EXT(glRenderbufferStorageMultisample);
    EXT(glBindRenderbuffer);
    EXT(glIsRenderbuffer);
    EXT(glGenerateMipmap);
    EXT(glGetFramebufferAttachmentParameteriv);
    EXT(glGetRenderbufferParameteriv);
    EXT(glFramebufferTextureLayer);
    EXT(glBlitFramebuffer);
    ARB(glGenFramebuffers);
    ARB(glDeleteFramebuffers);
    ARB(glIsFramebuffer);
    ARB(glCheckFramebufferStatus);
    ARB(glBindFramebuffer);
    ARB(glFramebufferTexture2D);
    ARB(glFramebufferTexture1D);
    ARB(glFramebufferTexture3D);
    ARB(glGenRenderbuffers);
    ARB(glFramebufferRenderbuffer);
    ARB(glDeleteRenderbuffers);
    ARB(glRenderbufferStorage);
    ARB(glRenderbufferStorageMultisample);
    ARB(glBindRenderbuffer);
    ARB(glIsRenderbuffer);
    ARB(glGenerateMipmap);
    ARB(glGetFramebufferAttachmentParameteriv);
    ARB(glGetRenderbufferParameteriv);
    ARB(glFramebufferTextureLayer);
    ARB(glBlitFramebuffer);
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
    EXT(glArrayElement);
    EXT(glDrawArrays);
    EXT(glVertexPointer);
    EXT(glNormalPointer);
    EXT(glColorPointer);
    //EXT(glIndexPointer);	//TODO
    EXT(glTexCoordPointer);
    //EXT(glEdgeFlagPointer);	//TODO
    //EXT(glGetPointerv);	//TODO


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
    EX(glColor3##suffix##v);          \
    EX(glColor3##suffix);             \
    EX(glColor4##suffix##v);          \
    EX(glColor4##suffix);             \
    EX(glSecondaryColor3##suffix##v); \
    EX(glSecondaryColor3##suffix);    \
    EXT(glSecondaryColor3##suffix##v); \
    EXT(glSecondaryColor3##suffix);    \
    EX(glIndex##suffix##v);           \
    EX(glIndex##suffix);              \
    EX(glNormal3##suffix##v);         \
    EX(glNormal3##suffix);            \
    EX(glRasterPos2##suffix##v);      \
    EX(glRasterPos2##suffix);         \
    EX(glRasterPos3##suffix##v);      \
    EX(glRasterPos3##suffix);         \
    EX(glRasterPos4##suffix##v);      \
    EX(glRasterPos4##suffix);         \
    EX(glWindowPos2##suffix##v);      \
    EX(glWindowPos2##suffix);         \
    EX(glWindowPos3##suffix##v);      \
    EX(glWindowPos3##suffix);         \
    EX(glVertex2##suffix##v);         \
    EX(glVertex2##suffix);            \
    EX(glVertex3##suffix##v);         \
    EX(glVertex3##suffix);            \
    EX(glVertex4##suffix##v);         \
    EX(glVertex4##suffix);            \
    EX(glTexCoord1##suffix##v);       \
    EX(glTexCoord1##suffix);          \
    EX(glTexCoord2##suffix##v);       \
    EX(glTexCoord2##suffix);          \
    EX(glTexCoord3##suffix##v);       \
    EX(glTexCoord3##suffix);          \
    EX(glTexCoord4##suffix##v);       \
    EX(glTexCoord4##suffix);          \
    EX(glMultiTexCoord1##suffix##v);  \
    EX(glMultiTexCoord1##suffix);     \
    EX(glMultiTexCoord2##suffix##v);  \
    EX(glMultiTexCoord2##suffix);     \
    EX(glMultiTexCoord3##suffix##v);  \
    EX(glMultiTexCoord3##suffix);     \
    EX(glMultiTexCoord4##suffix##v);  \
    EX(glMultiTexCoord4##suffix);     \
    EXT(glMultiTexCoord1##suffix##v); \
    EXT(glMultiTexCoord1##suffix);    \
    EXT(glMultiTexCoord2##suffix##v); \
    EXT(glMultiTexCoord2##suffix);    \
    EXT(glMultiTexCoord3##suffix##v); \
    EXT(glMultiTexCoord3##suffix);    \
    EXT(glMultiTexCoord4##suffix##v); \
    EXT(glMultiTexCoord4##suffix);    \
    ARB(glMultiTexCoord1##suffix##v); \
    ARB(glMultiTexCoord1##suffix);    \
    ARB(glMultiTexCoord2##suffix##v); \
    ARB(glMultiTexCoord2##suffix);    \
    ARB(glMultiTexCoord3##suffix##v); \
    ARB(glMultiTexCoord3##suffix);    \
    ARB(glMultiTexCoord4##suffix##v); \
    ARB(glMultiTexCoord4##suffix);

    THUNK(b, GLbyte);
    THUNK(d, GLdouble);
    THUNK(i, GLint);
    THUNK(s, GLshort);
    THUNK(ub, GLubyte);
    THUNK(ui, GLuint);
    THUNK(us, GLushort);
    THUNK(f, GLfloat);
    #undef THUNK
    
    EX(glPointParameterf);
    EX(glPointParameterfv);
    ARB(glPointParameterf);
    ARB(glPointParameterfv);
    EXT(glPointParameterf);
    EXT(glPointParameterfv);

#ifdef USE_ES2
    EX(glCompileShaderARB);
    EX(glCreateShaderObjectARB);
    EX(glGetObjectParameterivARB);
    EX(glShaderSourceARB);
#endif

    // functions we actually define
    EXT(glActiveTexture);
    ARB(glActiveTexture);
    EX(glArrayElement);
    EX(glBegin);
    EX(glBitmap);
    /*EXT(glBlendColor);
    ARB(glBlendColor);*/
    EXT(glBlendEquation);
    ARB(glBlendEquation);
    EXT(glBlendFunc);
    ARB(glBlendFunc);
#ifndef ODROID
    EXT(glBlendEquationSeparate);
    ARB(glBlendEquationSeparate);
    EX(glBlendEquationSeparatei);
    EXT(glBlendEquationSeparatei);
    ARB(glBlendEquationSeparatei);
    EXT(glBlendFuncSeparate);
    ARB(glBlendFuncSeparate);
    EX(glBlendFuncSeparatei);
    EXT(glBlendFuncSeparatei);
    ARB(glBlendFuncSeparatei);
#endif
    EX(glCallList);
    EX(glCallLists);
    EX(glClearDepth);
    EXT(glClientActiveTexture);
    ARB(glClientActiveTexture);
    EX(glClipPlane);
    EX(glCopyPixels);
    EX(glDeleteLists);
    EX(glDepthRange);
    EX(glDrawBuffer);
    EX(glDrawPixels);
    EX(glDrawRangeElements);
    EX(glDrawRangeElementsEXT);
    EX(glEdgeFlag);
    EX(glEnd);
    EX(glEndList);
    EX(glEvalCoord1d);
    EX(glEvalCoord1f);
    EX(glEvalCoord2d);
    EX(glEvalCoord2f);
    EX(glEvalMesh1);
    EX(glEvalMesh2);
    EX(glEvalPoint1);
    EX(glEvalPoint2);
    EX(glFogCoordd);
    EX(glFogCoorddv);
    EX(glFogCoordf);
    EX(glFogCoordfv);
    EX(glFogi);
    EX(glFogiv);
    EX(glFrustum);
    EX(glGenLists);
    EX(glGetDoublev);
    EX(glGetIntegerv);
    EX(glGetMapdv);
    EX(glGetMapfv);
    EX(glGetMapiv);
    EX(glGetTexImage);
    EX(glGetTexLevelParameterfv);
    EX(glGetTexLevelParameteriv);
    EX(glInitNames);
    EX(glInterleavedArrays);
    EX(glIsList);
#ifndef USE_ES2
    EX(glLighti);
    EX(glLightiv);
    EX(glLightModeli);
    EX(glLightModeliv);
#endif
    EX(glLineStipple);
    EX(glListBase);
    EX(glLoadMatrixd);
    EX(glLoadName);
    EX(glLockArraysEXT);
    EX(glMap1d);
    EX(glMap1f);
    EX(glMap2d);
    EX(glMap2f);
    EX(glMapGrid1d);
    EX(glMapGrid1f);
    EX(glMapGrid2d);
    EX(glMapGrid2f);
    EX(glMateriali);
    EX(glMultMatrixd);
    EX(glNewList);
    EX(glOrtho);
    EX(glPixelTransferf);
    EX(glPixelTransferi);
    EX(glPixelZoom);
    EX(glPolygonMode);
    EX(glPolygonStipple);
    EX(glPopAttrib);
    EX(glPopClientAttrib);
    EX(glPopName);
    EX(glPushAttrib);
    EX(glPushClientAttrib);
    EX(glPushName);
    EX(glRasterPos2i);
    EX(glReadBuffer);
    EX(glRectd);
    EX(glRectf);
    EX(glRecti);
    EX(glRects);
    EX(glRectdv);
    EX(glRectfv);
    EX(glRectiv);
    EX(glRectsv);
    EX(glRenderMode);
    EX(glRotated);
    EX(glScaled);
    EX(glSecondaryColorPointer);
    EXT(glSecondaryColorPointer);
    EX(glTexEnvf);
    EX(glTexEnviv);
    EX(glTexGend);
    EX(glTexGendv);
    EX(glTexGenf);
    EX(glTexGenfv);
    EX(glTexGeni);
    EX(glTexGeniv);
    EX(glTexImage1D);
    EX(glTexImage3D);
    EX(glTexSubImage1D);
    EX(glTexSubImage3D);
    EX(glCompressedTexImage1D);
    EX(glCompressedTexSubImage1D);
    EX(glCompressedTexImage3D);
    EX(glCompressedTexSubImage3D);
    EX(glGetCompressedTexImage);
    EXT(glCompressedTexImage2D);
    EXT(glCompressedTexSubImage2D);
    EXT(glCompressedTexImage1D);
    EXT(glCompressedTexSubImage1D);
    EXT(glCompressedTexImage3D);
    EXT(glCompressedTexSubImage3D);
    EXT(glGetCompressedTexImage);
    ARB(glCompressedTexImage2D);
    ARB(glCompressedTexSubImage2D);
    ARB(glCompressedTexImage1D);
    ARB(glCompressedTexSubImage1D);
    ARB(glCompressedTexImage3D);
    ARB(glCompressedTexSubImage3D);
    ARB(glGetCompressedTexImage);
    EX(glCopyTexImage1D);
    EX(glCopyTexSubImage1D);
    EX(glTranslated);
    EX(glUnlockArraysEXT);
	EX(glGetTexGenfv);
	EX(glLoadTransposeMatrixf);
	EX(glLoadTransposeMatrixd);
	EX(glMultTransposeMatrixd);
	EX(glMultTransposeMatrixf);
    // stubs for unimplemented functions
    STUB(glAccum);
    STUB(glAreTexturesResident);
    STUB(glClearAccum);
    STUB(glColorMaterial);
    STUB(glCopyTexImage3D);
    STUB(glCopyTexSubImage3D);
    STUB(glEdgeFlagPointer);
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
    STUB(glGetTexGeniv);
    STUB(glMaterialiv);
    STUB(glPassThrough);
    STUB(glPixelMapfv);
    STUB(glPixelMapuiv);
    STUB(glPixelMapusv);
    EX(glPixelStoref);
    STUB(glPrioritizeTextures);
    STUB(glSelectBuffer);
    
    STUB(glFogCoordPointer);
    STUB(glEdgeFlagPointerEXT);
    STUB(glIndexPointerEXT);
    STUB(glIndexPointer);

    printf("glXGetProcAddress: %s not found.\n", name);
    return NULL;
}

void *glXGetProcAddress(const char *name) {
    return glXGetProcAddressARB(name);
}
