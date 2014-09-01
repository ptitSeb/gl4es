#include "glx.h"

#define MAP(func_name, func) \
    if (strcmp(name, func_name) == 0) return (void *)func;

#define MAP_EGL(func_name, egl_func) \
    MAP(#func_name, eglGetProcAddress(#egl_func))

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
    // generated gles wrappers
#ifdef USE_ES2
    #include "gles2funcs.inc"
#else
    #include "glesfuncs.inc"
#endif

    // glX calls
    EX(glXChooseVisual);
    EX(glXCopyContext);
    EX(glXCreateContext);
	EX(glXCreateContextAttribsARB);
    EX(glXCreateGLXPixmap);
    EX(glXDestroyContext);
    EX(glXDestroyGLXPixmap);
    EX(glXGetConfig);
    EX(glXGetCurrentDisplay);
    EX(glXGetCurrentDrawable);
    EX(glXIsDirect);
    EX(glXMakeCurrent);
    EX(glXQueryExtensionsString);
    EX(glXQueryServerString);
    EX(glXSwapBuffers);
    EX(glXSwapIntervalEXT);
    EX(glXSwapIntervalMESA);
    EX(glXSwapIntervalSGI);
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
    EX(glXGetFBConfigAttrib);
    EX(glXGetVisualFromFBConfig);
    EX(glXCreateWindow);
    EX(glXDestroyWindow);

    // GL_ARB_vertex_buffer_object
    EX(glBindBuffer);
    EX(glBufferData);
    EX(glBufferSubData);
    EX(glDeleteBuffers);
    EX(glGenBuffers);
    EX(glIsBuffer);
    EX(glGetBufferPointerv);
    EX(glMapBuffer);
    EX(glUnmapBuffer);
    EX(glGetBufferParameteriv);
    EX(glGetBufferSubData);
    ARB(glBindBuffer);
    ARB(glBufferData);
    ARB(glBufferSubData);
    ARB(glDeleteBuffers);
    ARB(glGenBuffers);
    ARB(glIsBuffer);
    ARB(glGetBufferPointerv);
    ARB(glMapBuffer);
    ARB(glUnmapBuffer);
    ARB(glGetBufferParameteriv);
    ARB(glGetBufferSubData);
    
    // GL_ARB_frameBuffer_ext
    EX(glGenFramebuffers);
    EX(glDeleteFramebuffers);
    EX(glIsFramebuffer);
    EX(glCheckFramebufferStatus);
    EX(glBindFramebuffer);
    EX(glFramebufferTexture2D);
    EX(glFramebufferTexture1D);
    EX(glFramebufferTexture3D);
    EX(glGenRenderbuffers);
    EX(glFramebufferRenderbuffer);
    EX(glDeleteRenderbuffers);
    EX(glRenderbufferStorage);
    EX(glRenderbufferStorageMultisample);
    EX(glBindRenderbuffer);
    EX(glIsRenderbuffer);
    EX(glGenerateMipmap);
    EX(glGetFramebufferAttachmentParameteriv);
    EX(glGetRenderbufferParameteriv);
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
/*    ARB(glGenFramebuffers);
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
    ARB(glGetRenderbufferParameteriv);*/
    
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

#ifdef USE_ES2
    EX(glCompileShaderARB);
    EX(glCreateShaderObjectARB);
    EX(glGetObjectParameterivARB);
    EX(glShaderSourceARB);
#endif

    // functions we actually define
    EX(glActiveTexture);
    EXT(glActiveTexture);
    ARB(glActiveTexture);
    EX(glArrayElement);
    EXT(glArrayElement);
    EX(glBegin);
    EX(glBitmap);
    EX(glBlendColor);
    EXT(glBlendColor);
    ARB(glBlendColor);
    EX(glBlendEquationSeparate);
    EXT(glBlendEquationSeparate);
    ARB(glBlendEquationSeparate);
    EX(glBlendEquationSeparatei);
    EXT(glBlendEquationSeparatei);
    ARB(glBlendEquationSeparatei);
    EX(glBlendFunc);
    EXT(glBlendFunc);
    ARB(glBlendFunc);
    EX(glBlendFuncSeparate);
    EXT(glBlendFuncSeparate);
    ARB(glBlendFuncSeparate);
    EX(glBlendFuncSeparatei);
    EXT(glBlendFuncSeparatei);
    ARB(glBlendFuncSeparatei);
    EX(glCallList);
    EX(glCallLists);
    EX(glClearDepth);
    EX(glClientActiveTexture);
    EXT(glClientActiveTexture);
    ARB(glClientActiveTexture);
    EX(glClipPlane);
    EX(glCopyPixels);
    EX(glDeleteLists);
    EX(glDepthRange);
    EX(glDisable);
    EX(glDrawBuffer);
    EX(glDrawPixels);
    EX(glDrawRangeElements);
    EXT(glDrawRangeElements);
    EX(glEdgeFlag);
    EX(glEnable);
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
    EX(glTexEnvi);
    EX(glTexEnvfv);
    EX(glTexEnviv);
    EX(glTexGend);
    EX(glTexGendv);
    EX(glTexGenf);
    EX(glTexGenfv);
    EX(glTexGeni);
    EX(glTexGeniv);
    EX(glTexImage1D);
    EX(glTexImage2D);
    EX(glTexImage3D);
    EX(glTexSubImage1D);
    EX(glTexSubImage2D);
    EX(glTexSubImage3D);
    EX(glCompressedTexImage2D);
    EX(glCompressedTexSubImage2D);
    EX(glCopyTexImage1D);
    EX(glCopyTexImage2D);
    EX(glCopyTexSubImage1D);
    EX(glCopyTexSubImage2D);
    EX(glTranslated);
    EX(glUnlockArraysEXT);
	EX(glGetTexGenfv);
	EX(glLoadTransposeMatrixf);
	EX(glLoadTransposeMatrixd);
	EX(glMultTransposeMatrixd);
	EX(glMultTransposeMatrixf);
    EX(glGetCompressedTexImage);
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
    STUB(glPixelStoref);
    STUB(glPrioritizeTextures);
    STUB(glSelectBuffer);
    STUB( glIndexPointer);
    //STUB(glTexSubImage1D);

    printf("glXGetProcAddress: %s not found.\n", name);
    return NULL;
}

void *glXGetProcAddress(const char *name) {
    return glXGetProcAddressARB(name);
}
