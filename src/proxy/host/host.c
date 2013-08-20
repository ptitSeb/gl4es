#include "../proxy.h"

#ifndef HOST_C
#define HOST_C
#include <dlfcn.h>
#include <stdio.h>
static void *g_libgl = NULL;

void glIndexedCall(const indexed_call_t *packed, void *ret_v) {
    if (! g_libgl) {
        g_libgl = dlopen("libGL.so.1", RTLD_LOCAL | RTLD_LAZY);
        if (! g_libgl) {
            printf("Warning: Unable to open libGL.so.1\n");
            return;
        }
    }

    switch (packed->func) {
        #ifndef skip_index_glAccum
        case glAccum_INDEX: {
            static glAccum_PTR local_glAccum;
            if (local_glAccum == NULL) {
                local_glAccum = (glAccum_PTR)dlsym(g_libgl, "glAccum");
                if (! local_glAccum) {
                    printf("Warning: Unable to dlsym 'glAccum'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat args = unpacked->args;
            local_glAccum(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glActiveTexture
        case glActiveTexture_INDEX: {
            static glActiveTexture_PTR local_glActiveTexture;
            if (local_glActiveTexture == NULL) {
                local_glActiveTexture = (glActiveTexture_PTR)dlsym(g_libgl, "glActiveTexture");
                if (! local_glActiveTexture) {
                    printf("Warning: Unable to dlsym 'glActiveTexture'\n");
                    return;
                }
            }

            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            local_glActiveTexture(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glAlphaFunc
        case glAlphaFunc_INDEX: {
            static glAlphaFunc_PTR local_glAlphaFunc;
            if (local_glAlphaFunc == NULL) {
                local_glAlphaFunc = (glAlphaFunc_PTR)dlsym(g_libgl, "glAlphaFunc");
                if (! local_glAlphaFunc) {
                    printf("Warning: Unable to dlsym 'glAlphaFunc'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat args = unpacked->args;
            local_glAlphaFunc(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glAreTexturesResident
        case glAreTexturesResident_INDEX: {
            static glAreTexturesResident_PTR local_glAreTexturesResident;
            if (local_glAreTexturesResident == NULL) {
                local_glAreTexturesResident = (glAreTexturesResident_PTR)dlsym(g_libgl, "glAreTexturesResident");
                if (! local_glAreTexturesResident) {
                    printf("Warning: Unable to dlsym 'glAreTexturesResident'\n");
                    return;
                }
            }

            INDEXED_GLboolean_GLsizei_const_GLuint___GENPT___GLboolean___GENPT__ *unpacked = (INDEXED_GLboolean_GLsizei_const_GLuint___GENPT___GLboolean___GENPT__ *)packed;
            ARGS_GLboolean_GLsizei_const_GLuint___GENPT___GLboolean___GENPT__ args = unpacked->args;
            GLboolean *ret = (GLboolean *)ret_v;
            *ret =
            local_glAreTexturesResident(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glArrayElement
        case glArrayElement_INDEX: {
            static glArrayElement_PTR local_glArrayElement;
            if (local_glArrayElement == NULL) {
                local_glArrayElement = (glArrayElement_PTR)dlsym(g_libgl, "glArrayElement");
                if (! local_glArrayElement) {
                    printf("Warning: Unable to dlsym 'glArrayElement'\n");
                    return;
                }
            }

            INDEXED_void_GLint *unpacked = (INDEXED_void_GLint *)packed;
            ARGS_void_GLint args = unpacked->args;
            local_glArrayElement(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glBegin
        case glBegin_INDEX: {
            static glBegin_PTR local_glBegin;
            if (local_glBegin == NULL) {
                local_glBegin = (glBegin_PTR)dlsym(g_libgl, "glBegin");
                if (! local_glBegin) {
                    printf("Warning: Unable to dlsym 'glBegin'\n");
                    return;
                }
            }

            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            local_glBegin(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glBeginQuery
        case glBeginQuery_INDEX: {
            static glBeginQuery_PTR local_glBeginQuery;
            if (local_glBeginQuery == NULL) {
                local_glBeginQuery = (glBeginQuery_PTR)dlsym(g_libgl, "glBeginQuery");
                if (! local_glBeginQuery) {
                    printf("Warning: Unable to dlsym 'glBeginQuery'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLuint *unpacked = (INDEXED_void_GLenum_GLuint *)packed;
            ARGS_void_GLenum_GLuint args = unpacked->args;
            local_glBeginQuery(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glBindBuffer
        case glBindBuffer_INDEX: {
            static glBindBuffer_PTR local_glBindBuffer;
            if (local_glBindBuffer == NULL) {
                local_glBindBuffer = (glBindBuffer_PTR)dlsym(g_libgl, "glBindBuffer");
                if (! local_glBindBuffer) {
                    printf("Warning: Unable to dlsym 'glBindBuffer'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLuint *unpacked = (INDEXED_void_GLenum_GLuint *)packed;
            ARGS_void_GLenum_GLuint args = unpacked->args;
            local_glBindBuffer(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glBindTexture
        case glBindTexture_INDEX: {
            static glBindTexture_PTR local_glBindTexture;
            if (local_glBindTexture == NULL) {
                local_glBindTexture = (glBindTexture_PTR)dlsym(g_libgl, "glBindTexture");
                if (! local_glBindTexture) {
                    printf("Warning: Unable to dlsym 'glBindTexture'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLuint *unpacked = (INDEXED_void_GLenum_GLuint *)packed;
            ARGS_void_GLenum_GLuint args = unpacked->args;
            local_glBindTexture(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glBitmap
        case glBitmap_INDEX: {
            static glBitmap_PTR local_glBitmap;
            if (local_glBitmap == NULL) {
                local_glBitmap = (glBitmap_PTR)dlsym(g_libgl, "glBitmap");
                if (! local_glBitmap) {
                    printf("Warning: Unable to dlsym 'glBitmap'\n");
                    return;
                }
            }

            INDEXED_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_const_GLubyte___GENPT__ *unpacked = (INDEXED_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_const_GLubyte___GENPT__ *)packed;
            ARGS_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_const_GLubyte___GENPT__ args = unpacked->args;
            local_glBitmap(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        #endif
        #ifndef skip_index_glBlendColor
        case glBlendColor_INDEX: {
            static glBlendColor_PTR local_glBlendColor;
            if (local_glBlendColor == NULL) {
                local_glBlendColor = (glBlendColor_PTR)dlsym(g_libgl, "glBlendColor");
                if (! local_glBlendColor) {
                    printf("Warning: Unable to dlsym 'glBlendColor'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            local_glBlendColor(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glBlendEquation
        case glBlendEquation_INDEX: {
            static glBlendEquation_PTR local_glBlendEquation;
            if (local_glBlendEquation == NULL) {
                local_glBlendEquation = (glBlendEquation_PTR)dlsym(g_libgl, "glBlendEquation");
                if (! local_glBlendEquation) {
                    printf("Warning: Unable to dlsym 'glBlendEquation'\n");
                    return;
                }
            }

            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            local_glBlendEquation(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glBlendFunc
        case glBlendFunc_INDEX: {
            static glBlendFunc_PTR local_glBlendFunc;
            if (local_glBlendFunc == NULL) {
                local_glBlendFunc = (glBlendFunc_PTR)dlsym(g_libgl, "glBlendFunc");
                if (! local_glBlendFunc) {
                    printf("Warning: Unable to dlsym 'glBlendFunc'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum *unpacked = (INDEXED_void_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLenum args = unpacked->args;
            local_glBlendFunc(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glBlendFuncSeparate
        case glBlendFuncSeparate_INDEX: {
            static glBlendFuncSeparate_PTR local_glBlendFuncSeparate;
            if (local_glBlendFuncSeparate == NULL) {
                local_glBlendFuncSeparate = (glBlendFuncSeparate_PTR)dlsym(g_libgl, "glBlendFuncSeparate");
                if (! local_glBlendFuncSeparate) {
                    printf("Warning: Unable to dlsym 'glBlendFuncSeparate'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLenum_GLenum *unpacked = (INDEXED_void_GLenum_GLenum_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLenum args = unpacked->args;
            local_glBlendFuncSeparate(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glBufferData
        case glBufferData_INDEX: {
            static glBufferData_PTR local_glBufferData;
            if (local_glBufferData == NULL) {
                local_glBufferData = (glBufferData_PTR)dlsym(g_libgl, "glBufferData");
                if (! local_glBufferData) {
                    printf("Warning: Unable to dlsym 'glBufferData'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum *unpacked = (INDEXED_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum *)packed;
            ARGS_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum args = unpacked->args;
            local_glBufferData(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glBufferSubData
        case glBufferSubData_INDEX: {
            static glBufferSubData_PTR local_glBufferSubData;
            if (local_glBufferSubData == NULL) {
                local_glBufferSubData = (glBufferSubData_PTR)dlsym(g_libgl, "glBufferSubData");
                if (! local_glBufferSubData) {
                    printf("Warning: Unable to dlsym 'glBufferSubData'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__ args = unpacked->args;
            local_glBufferSubData(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glCallList
        case glCallList_INDEX: {
            static glCallList_PTR local_glCallList;
            if (local_glCallList == NULL) {
                local_glCallList = (glCallList_PTR)dlsym(g_libgl, "glCallList");
                if (! local_glCallList) {
                    printf("Warning: Unable to dlsym 'glCallList'\n");
                    return;
                }
            }

            INDEXED_void_GLuint *unpacked = (INDEXED_void_GLuint *)packed;
            ARGS_void_GLuint args = unpacked->args;
            local_glCallList(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glCallLists
        case glCallLists_INDEX: {
            static glCallLists_PTR local_glCallLists;
            if (local_glCallLists == NULL) {
                local_glCallLists = (glCallLists_PTR)dlsym(g_libgl, "glCallLists");
                if (! local_glCallLists) {
                    printf("Warning: Unable to dlsym 'glCallLists'\n");
                    return;
                }
            }

            INDEXED_void_GLsizei_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLsizei_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLsizei_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            local_glCallLists(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glClear
        case glClear_INDEX: {
            static glClear_PTR local_glClear;
            if (local_glClear == NULL) {
                local_glClear = (glClear_PTR)dlsym(g_libgl, "glClear");
                if (! local_glClear) {
                    printf("Warning: Unable to dlsym 'glClear'\n");
                    return;
                }
            }

            INDEXED_void_GLbitfield *unpacked = (INDEXED_void_GLbitfield *)packed;
            ARGS_void_GLbitfield args = unpacked->args;
            local_glClear(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glClearAccum
        case glClearAccum_INDEX: {
            static glClearAccum_PTR local_glClearAccum;
            if (local_glClearAccum == NULL) {
                local_glClearAccum = (glClearAccum_PTR)dlsym(g_libgl, "glClearAccum");
                if (! local_glClearAccum) {
                    printf("Warning: Unable to dlsym 'glClearAccum'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            local_glClearAccum(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glClearColor
        case glClearColor_INDEX: {
            static glClearColor_PTR local_glClearColor;
            if (local_glClearColor == NULL) {
                local_glClearColor = (glClearColor_PTR)dlsym(g_libgl, "glClearColor");
                if (! local_glClearColor) {
                    printf("Warning: Unable to dlsym 'glClearColor'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            local_glClearColor(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glClearDepth
        case glClearDepth_INDEX: {
            static glClearDepth_PTR local_glClearDepth;
            if (local_glClearDepth == NULL) {
                local_glClearDepth = (glClearDepth_PTR)dlsym(g_libgl, "glClearDepth");
                if (! local_glClearDepth) {
                    printf("Warning: Unable to dlsym 'glClearDepth'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble *unpacked = (INDEXED_void_GLdouble *)packed;
            ARGS_void_GLdouble args = unpacked->args;
            local_glClearDepth(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glClearIndex
        case glClearIndex_INDEX: {
            static glClearIndex_PTR local_glClearIndex;
            if (local_glClearIndex == NULL) {
                local_glClearIndex = (glClearIndex_PTR)dlsym(g_libgl, "glClearIndex");
                if (! local_glClearIndex) {
                    printf("Warning: Unable to dlsym 'glClearIndex'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat *unpacked = (INDEXED_void_GLfloat *)packed;
            ARGS_void_GLfloat args = unpacked->args;
            local_glClearIndex(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glClearStencil
        case glClearStencil_INDEX: {
            static glClearStencil_PTR local_glClearStencil;
            if (local_glClearStencil == NULL) {
                local_glClearStencil = (glClearStencil_PTR)dlsym(g_libgl, "glClearStencil");
                if (! local_glClearStencil) {
                    printf("Warning: Unable to dlsym 'glClearStencil'\n");
                    return;
                }
            }

            INDEXED_void_GLint *unpacked = (INDEXED_void_GLint *)packed;
            ARGS_void_GLint args = unpacked->args;
            local_glClearStencil(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glClientActiveTexture
        case glClientActiveTexture_INDEX: {
            static glClientActiveTexture_PTR local_glClientActiveTexture;
            if (local_glClientActiveTexture == NULL) {
                local_glClientActiveTexture = (glClientActiveTexture_PTR)dlsym(g_libgl, "glClientActiveTexture");
                if (! local_glClientActiveTexture) {
                    printf("Warning: Unable to dlsym 'glClientActiveTexture'\n");
                    return;
                }
            }

            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            local_glClientActiveTexture(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glClipPlane
        case glClipPlane_INDEX: {
            static glClipPlane_PTR local_glClipPlane;
            if (local_glClipPlane == NULL) {
                local_glClipPlane = (glClipPlane_PTR)dlsym(g_libgl, "glClipPlane");
                if (! local_glClipPlane) {
                    printf("Warning: Unable to dlsym 'glClipPlane'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLdouble___GENPT__ args = unpacked->args;
            local_glClipPlane(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glColor3b
        case glColor3b_INDEX: {
            static glColor3b_PTR local_glColor3b;
            if (local_glColor3b == NULL) {
                local_glColor3b = (glColor3b_PTR)dlsym(g_libgl, "glColor3b");
                if (! local_glColor3b) {
                    printf("Warning: Unable to dlsym 'glColor3b'\n");
                    return;
                }
            }

            INDEXED_void_GLbyte_GLbyte_GLbyte *unpacked = (INDEXED_void_GLbyte_GLbyte_GLbyte *)packed;
            ARGS_void_GLbyte_GLbyte_GLbyte args = unpacked->args;
            local_glColor3b(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glColor3bv
        case glColor3bv_INDEX: {
            static glColor3bv_PTR local_glColor3bv;
            if (local_glColor3bv == NULL) {
                local_glColor3bv = (glColor3bv_PTR)dlsym(g_libgl, "glColor3bv");
                if (! local_glColor3bv) {
                    printf("Warning: Unable to dlsym 'glColor3bv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLbyte___GENPT__ *unpacked = (INDEXED_void_const_GLbyte___GENPT__ *)packed;
            ARGS_void_const_GLbyte___GENPT__ args = unpacked->args;
            local_glColor3bv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor3d
        case glColor3d_INDEX: {
            static glColor3d_PTR local_glColor3d;
            if (local_glColor3d == NULL) {
                local_glColor3d = (glColor3d_PTR)dlsym(g_libgl, "glColor3d");
                if (! local_glColor3d) {
                    printf("Warning: Unable to dlsym 'glColor3d'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble args = unpacked->args;
            local_glColor3d(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glColor3dv
        case glColor3dv_INDEX: {
            static glColor3dv_PTR local_glColor3dv;
            if (local_glColor3dv == NULL) {
                local_glColor3dv = (glColor3dv_PTR)dlsym(g_libgl, "glColor3dv");
                if (! local_glColor3dv) {
                    printf("Warning: Unable to dlsym 'glColor3dv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            local_glColor3dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor3f
        case glColor3f_INDEX: {
            static glColor3f_PTR local_glColor3f;
            if (local_glColor3f == NULL) {
                local_glColor3f = (glColor3f_PTR)dlsym(g_libgl, "glColor3f");
                if (! local_glColor3f) {
                    printf("Warning: Unable to dlsym 'glColor3f'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat args = unpacked->args;
            local_glColor3f(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glColor3fv
        case glColor3fv_INDEX: {
            static glColor3fv_PTR local_glColor3fv;
            if (local_glColor3fv == NULL) {
                local_glColor3fv = (glColor3fv_PTR)dlsym(g_libgl, "glColor3fv");
                if (! local_glColor3fv) {
                    printf("Warning: Unable to dlsym 'glColor3fv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            local_glColor3fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor3i
        case glColor3i_INDEX: {
            static glColor3i_PTR local_glColor3i;
            if (local_glColor3i == NULL) {
                local_glColor3i = (glColor3i_PTR)dlsym(g_libgl, "glColor3i");
                if (! local_glColor3i) {
                    printf("Warning: Unable to dlsym 'glColor3i'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint args = unpacked->args;
            local_glColor3i(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glColor3iv
        case glColor3iv_INDEX: {
            static glColor3iv_PTR local_glColor3iv;
            if (local_glColor3iv == NULL) {
                local_glColor3iv = (glColor3iv_PTR)dlsym(g_libgl, "glColor3iv");
                if (! local_glColor3iv) {
                    printf("Warning: Unable to dlsym 'glColor3iv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            local_glColor3iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor3s
        case glColor3s_INDEX: {
            static glColor3s_PTR local_glColor3s;
            if (local_glColor3s == NULL) {
                local_glColor3s = (glColor3s_PTR)dlsym(g_libgl, "glColor3s");
                if (! local_glColor3s) {
                    printf("Warning: Unable to dlsym 'glColor3s'\n");
                    return;
                }
            }

            INDEXED_void_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort args = unpacked->args;
            local_glColor3s(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glColor3sv
        case glColor3sv_INDEX: {
            static glColor3sv_PTR local_glColor3sv;
            if (local_glColor3sv == NULL) {
                local_glColor3sv = (glColor3sv_PTR)dlsym(g_libgl, "glColor3sv");
                if (! local_glColor3sv) {
                    printf("Warning: Unable to dlsym 'glColor3sv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            local_glColor3sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor3ub
        case glColor3ub_INDEX: {
            static glColor3ub_PTR local_glColor3ub;
            if (local_glColor3ub == NULL) {
                local_glColor3ub = (glColor3ub_PTR)dlsym(g_libgl, "glColor3ub");
                if (! local_glColor3ub) {
                    printf("Warning: Unable to dlsym 'glColor3ub'\n");
                    return;
                }
            }

            INDEXED_void_GLubyte_GLubyte_GLubyte *unpacked = (INDEXED_void_GLubyte_GLubyte_GLubyte *)packed;
            ARGS_void_GLubyte_GLubyte_GLubyte args = unpacked->args;
            local_glColor3ub(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glColor3ubv
        case glColor3ubv_INDEX: {
            static glColor3ubv_PTR local_glColor3ubv;
            if (local_glColor3ubv == NULL) {
                local_glColor3ubv = (glColor3ubv_PTR)dlsym(g_libgl, "glColor3ubv");
                if (! local_glColor3ubv) {
                    printf("Warning: Unable to dlsym 'glColor3ubv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLubyte___GENPT__ *unpacked = (INDEXED_void_const_GLubyte___GENPT__ *)packed;
            ARGS_void_const_GLubyte___GENPT__ args = unpacked->args;
            local_glColor3ubv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor3ui
        case glColor3ui_INDEX: {
            static glColor3ui_PTR local_glColor3ui;
            if (local_glColor3ui == NULL) {
                local_glColor3ui = (glColor3ui_PTR)dlsym(g_libgl, "glColor3ui");
                if (! local_glColor3ui) {
                    printf("Warning: Unable to dlsym 'glColor3ui'\n");
                    return;
                }
            }

            INDEXED_void_GLuint_GLuint_GLuint *unpacked = (INDEXED_void_GLuint_GLuint_GLuint *)packed;
            ARGS_void_GLuint_GLuint_GLuint args = unpacked->args;
            local_glColor3ui(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glColor3uiv
        case glColor3uiv_INDEX: {
            static glColor3uiv_PTR local_glColor3uiv;
            if (local_glColor3uiv == NULL) {
                local_glColor3uiv = (glColor3uiv_PTR)dlsym(g_libgl, "glColor3uiv");
                if (! local_glColor3uiv) {
                    printf("Warning: Unable to dlsym 'glColor3uiv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLuint___GENPT__ *unpacked = (INDEXED_void_const_GLuint___GENPT__ *)packed;
            ARGS_void_const_GLuint___GENPT__ args = unpacked->args;
            local_glColor3uiv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor3us
        case glColor3us_INDEX: {
            static glColor3us_PTR local_glColor3us;
            if (local_glColor3us == NULL) {
                local_glColor3us = (glColor3us_PTR)dlsym(g_libgl, "glColor3us");
                if (! local_glColor3us) {
                    printf("Warning: Unable to dlsym 'glColor3us'\n");
                    return;
                }
            }

            INDEXED_void_GLushort_GLushort_GLushort *unpacked = (INDEXED_void_GLushort_GLushort_GLushort *)packed;
            ARGS_void_GLushort_GLushort_GLushort args = unpacked->args;
            local_glColor3us(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glColor3usv
        case glColor3usv_INDEX: {
            static glColor3usv_PTR local_glColor3usv;
            if (local_glColor3usv == NULL) {
                local_glColor3usv = (glColor3usv_PTR)dlsym(g_libgl, "glColor3usv");
                if (! local_glColor3usv) {
                    printf("Warning: Unable to dlsym 'glColor3usv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLushort___GENPT__ *unpacked = (INDEXED_void_const_GLushort___GENPT__ *)packed;
            ARGS_void_const_GLushort___GENPT__ args = unpacked->args;
            local_glColor3usv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor4b
        case glColor4b_INDEX: {
            static glColor4b_PTR local_glColor4b;
            if (local_glColor4b == NULL) {
                local_glColor4b = (glColor4b_PTR)dlsym(g_libgl, "glColor4b");
                if (! local_glColor4b) {
                    printf("Warning: Unable to dlsym 'glColor4b'\n");
                    return;
                }
            }

            INDEXED_void_GLbyte_GLbyte_GLbyte_GLbyte *unpacked = (INDEXED_void_GLbyte_GLbyte_GLbyte_GLbyte *)packed;
            ARGS_void_GLbyte_GLbyte_GLbyte_GLbyte args = unpacked->args;
            local_glColor4b(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glColor4bv
        case glColor4bv_INDEX: {
            static glColor4bv_PTR local_glColor4bv;
            if (local_glColor4bv == NULL) {
                local_glColor4bv = (glColor4bv_PTR)dlsym(g_libgl, "glColor4bv");
                if (! local_glColor4bv) {
                    printf("Warning: Unable to dlsym 'glColor4bv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLbyte___GENPT__ *unpacked = (INDEXED_void_const_GLbyte___GENPT__ *)packed;
            ARGS_void_const_GLbyte___GENPT__ args = unpacked->args;
            local_glColor4bv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor4d
        case glColor4d_INDEX: {
            static glColor4d_PTR local_glColor4d;
            if (local_glColor4d == NULL) {
                local_glColor4d = (glColor4d_PTR)dlsym(g_libgl, "glColor4d");
                if (! local_glColor4d) {
                    printf("Warning: Unable to dlsym 'glColor4d'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            local_glColor4d(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glColor4dv
        case glColor4dv_INDEX: {
            static glColor4dv_PTR local_glColor4dv;
            if (local_glColor4dv == NULL) {
                local_glColor4dv = (glColor4dv_PTR)dlsym(g_libgl, "glColor4dv");
                if (! local_glColor4dv) {
                    printf("Warning: Unable to dlsym 'glColor4dv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            local_glColor4dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor4f
        case glColor4f_INDEX: {
            static glColor4f_PTR local_glColor4f;
            if (local_glColor4f == NULL) {
                local_glColor4f = (glColor4f_PTR)dlsym(g_libgl, "glColor4f");
                if (! local_glColor4f) {
                    printf("Warning: Unable to dlsym 'glColor4f'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            local_glColor4f(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glColor4fv
        case glColor4fv_INDEX: {
            static glColor4fv_PTR local_glColor4fv;
            if (local_glColor4fv == NULL) {
                local_glColor4fv = (glColor4fv_PTR)dlsym(g_libgl, "glColor4fv");
                if (! local_glColor4fv) {
                    printf("Warning: Unable to dlsym 'glColor4fv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            local_glColor4fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor4i
        case glColor4i_INDEX: {
            static glColor4i_PTR local_glColor4i;
            if (local_glColor4i == NULL) {
                local_glColor4i = (glColor4i_PTR)dlsym(g_libgl, "glColor4i");
                if (! local_glColor4i) {
                    printf("Warning: Unable to dlsym 'glColor4i'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLint_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint_GLint args = unpacked->args;
            local_glColor4i(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glColor4iv
        case glColor4iv_INDEX: {
            static glColor4iv_PTR local_glColor4iv;
            if (local_glColor4iv == NULL) {
                local_glColor4iv = (glColor4iv_PTR)dlsym(g_libgl, "glColor4iv");
                if (! local_glColor4iv) {
                    printf("Warning: Unable to dlsym 'glColor4iv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            local_glColor4iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor4s
        case glColor4s_INDEX: {
            static glColor4s_PTR local_glColor4s;
            if (local_glColor4s == NULL) {
                local_glColor4s = (glColor4s_PTR)dlsym(g_libgl, "glColor4s");
                if (! local_glColor4s) {
                    printf("Warning: Unable to dlsym 'glColor4s'\n");
                    return;
                }
            }

            INDEXED_void_GLshort_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort_GLshort args = unpacked->args;
            local_glColor4s(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glColor4sv
        case glColor4sv_INDEX: {
            static glColor4sv_PTR local_glColor4sv;
            if (local_glColor4sv == NULL) {
                local_glColor4sv = (glColor4sv_PTR)dlsym(g_libgl, "glColor4sv");
                if (! local_glColor4sv) {
                    printf("Warning: Unable to dlsym 'glColor4sv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            local_glColor4sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor4ub
        case glColor4ub_INDEX: {
            static glColor4ub_PTR local_glColor4ub;
            if (local_glColor4ub == NULL) {
                local_glColor4ub = (glColor4ub_PTR)dlsym(g_libgl, "glColor4ub");
                if (! local_glColor4ub) {
                    printf("Warning: Unable to dlsym 'glColor4ub'\n");
                    return;
                }
            }

            INDEXED_void_GLubyte_GLubyte_GLubyte_GLubyte *unpacked = (INDEXED_void_GLubyte_GLubyte_GLubyte_GLubyte *)packed;
            ARGS_void_GLubyte_GLubyte_GLubyte_GLubyte args = unpacked->args;
            local_glColor4ub(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glColor4ubv
        case glColor4ubv_INDEX: {
            static glColor4ubv_PTR local_glColor4ubv;
            if (local_glColor4ubv == NULL) {
                local_glColor4ubv = (glColor4ubv_PTR)dlsym(g_libgl, "glColor4ubv");
                if (! local_glColor4ubv) {
                    printf("Warning: Unable to dlsym 'glColor4ubv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLubyte___GENPT__ *unpacked = (INDEXED_void_const_GLubyte___GENPT__ *)packed;
            ARGS_void_const_GLubyte___GENPT__ args = unpacked->args;
            local_glColor4ubv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor4ui
        case glColor4ui_INDEX: {
            static glColor4ui_PTR local_glColor4ui;
            if (local_glColor4ui == NULL) {
                local_glColor4ui = (glColor4ui_PTR)dlsym(g_libgl, "glColor4ui");
                if (! local_glColor4ui) {
                    printf("Warning: Unable to dlsym 'glColor4ui'\n");
                    return;
                }
            }

            INDEXED_void_GLuint_GLuint_GLuint_GLuint *unpacked = (INDEXED_void_GLuint_GLuint_GLuint_GLuint *)packed;
            ARGS_void_GLuint_GLuint_GLuint_GLuint args = unpacked->args;
            local_glColor4ui(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glColor4uiv
        case glColor4uiv_INDEX: {
            static glColor4uiv_PTR local_glColor4uiv;
            if (local_glColor4uiv == NULL) {
                local_glColor4uiv = (glColor4uiv_PTR)dlsym(g_libgl, "glColor4uiv");
                if (! local_glColor4uiv) {
                    printf("Warning: Unable to dlsym 'glColor4uiv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLuint___GENPT__ *unpacked = (INDEXED_void_const_GLuint___GENPT__ *)packed;
            ARGS_void_const_GLuint___GENPT__ args = unpacked->args;
            local_glColor4uiv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor4us
        case glColor4us_INDEX: {
            static glColor4us_PTR local_glColor4us;
            if (local_glColor4us == NULL) {
                local_glColor4us = (glColor4us_PTR)dlsym(g_libgl, "glColor4us");
                if (! local_glColor4us) {
                    printf("Warning: Unable to dlsym 'glColor4us'\n");
                    return;
                }
            }

            INDEXED_void_GLushort_GLushort_GLushort_GLushort *unpacked = (INDEXED_void_GLushort_GLushort_GLushort_GLushort *)packed;
            ARGS_void_GLushort_GLushort_GLushort_GLushort args = unpacked->args;
            local_glColor4us(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glColor4usv
        case glColor4usv_INDEX: {
            static glColor4usv_PTR local_glColor4usv;
            if (local_glColor4usv == NULL) {
                local_glColor4usv = (glColor4usv_PTR)dlsym(g_libgl, "glColor4usv");
                if (! local_glColor4usv) {
                    printf("Warning: Unable to dlsym 'glColor4usv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLushort___GENPT__ *unpacked = (INDEXED_void_const_GLushort___GENPT__ *)packed;
            ARGS_void_const_GLushort___GENPT__ args = unpacked->args;
            local_glColor4usv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColorMask
        case glColorMask_INDEX: {
            static glColorMask_PTR local_glColorMask;
            if (local_glColorMask == NULL) {
                local_glColorMask = (glColorMask_PTR)dlsym(g_libgl, "glColorMask");
                if (! local_glColorMask) {
                    printf("Warning: Unable to dlsym 'glColorMask'\n");
                    return;
                }
            }

            INDEXED_void_GLboolean_GLboolean_GLboolean_GLboolean *unpacked = (INDEXED_void_GLboolean_GLboolean_GLboolean_GLboolean *)packed;
            ARGS_void_GLboolean_GLboolean_GLboolean_GLboolean args = unpacked->args;
            local_glColorMask(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glColorMaterial
        case glColorMaterial_INDEX: {
            static glColorMaterial_PTR local_glColorMaterial;
            if (local_glColorMaterial == NULL) {
                local_glColorMaterial = (glColorMaterial_PTR)dlsym(g_libgl, "glColorMaterial");
                if (! local_glColorMaterial) {
                    printf("Warning: Unable to dlsym 'glColorMaterial'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum *unpacked = (INDEXED_void_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLenum args = unpacked->args;
            local_glColorMaterial(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glColorPointer
        case glColorPointer_INDEX: {
            static glColorPointer_PTR local_glColorPointer;
            if (local_glColorPointer == NULL) {
                local_glColorPointer = (glColorPointer_PTR)dlsym(g_libgl, "glColorPointer");
                if (! local_glColorPointer) {
                    printf("Warning: Unable to dlsym 'glColorPointer'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            local_glColorPointer(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glColorSubTable
        case glColorSubTable_INDEX: {
            static glColorSubTable_PTR local_glColorSubTable;
            if (local_glColorSubTable == NULL) {
                local_glColorSubTable = (glColorSubTable_PTR)dlsym(g_libgl, "glColorSubTable");
                if (! local_glColorSubTable) {
                    printf("Warning: Unable to dlsym 'glColorSubTable'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            local_glColorSubTable(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glColorTable
        case glColorTable_INDEX: {
            static glColorTable_PTR local_glColorTable;
            if (local_glColorTable == NULL) {
                local_glColorTable = (glColorTable_PTR)dlsym(g_libgl, "glColorTable");
                if (! local_glColorTable) {
                    printf("Warning: Unable to dlsym 'glColorTable'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            local_glColorTable(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glColorTableParameterfv
        case glColorTableParameterfv_INDEX: {
            static glColorTableParameterfv_PTR local_glColorTableParameterfv;
            if (local_glColorTableParameterfv == NULL) {
                local_glColorTableParameterfv = (glColorTableParameterfv_PTR)dlsym(g_libgl, "glColorTableParameterfv");
                if (! local_glColorTableParameterfv) {
                    printf("Warning: Unable to dlsym 'glColorTableParameterfv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            local_glColorTableParameterfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glColorTableParameteriv
        case glColorTableParameteriv_INDEX: {
            static glColorTableParameteriv_PTR local_glColorTableParameteriv;
            if (local_glColorTableParameteriv == NULL) {
                local_glColorTableParameteriv = (glColorTableParameteriv_PTR)dlsym(g_libgl, "glColorTableParameteriv");
                if (! local_glColorTableParameteriv) {
                    printf("Warning: Unable to dlsym 'glColorTableParameteriv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLint___GENPT__ args = unpacked->args;
            local_glColorTableParameteriv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glCompressedTexImage1D
        case glCompressedTexImage1D_INDEX: {
            static glCompressedTexImage1D_PTR local_glCompressedTexImage1D;
            if (local_glCompressedTexImage1D == NULL) {
                local_glCompressedTexImage1D = (glCompressedTexImage1D_PTR)dlsym(g_libgl, "glCompressedTexImage1D");
                if (! local_glCompressedTexImage1D) {
                    printf("Warning: Unable to dlsym 'glCompressedTexImage1D'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            local_glCompressedTexImage1D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        #endif
        #ifndef skip_index_glCompressedTexImage2D
        case glCompressedTexImage2D_INDEX: {
            static glCompressedTexImage2D_PTR local_glCompressedTexImage2D;
            if (local_glCompressedTexImage2D == NULL) {
                local_glCompressedTexImage2D = (glCompressedTexImage2D_PTR)dlsym(g_libgl, "glCompressedTexImage2D");
                if (! local_glCompressedTexImage2D) {
                    printf("Warning: Unable to dlsym 'glCompressedTexImage2D'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            local_glCompressedTexImage2D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        #endif
        #ifndef skip_index_glCompressedTexImage3D
        case glCompressedTexImage3D_INDEX: {
            static glCompressedTexImage3D_PTR local_glCompressedTexImage3D;
            if (local_glCompressedTexImage3D == NULL) {
                local_glCompressedTexImage3D = (glCompressedTexImage3D_PTR)dlsym(g_libgl, "glCompressedTexImage3D");
                if (! local_glCompressedTexImage3D) {
                    printf("Warning: Unable to dlsym 'glCompressedTexImage3D'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            local_glCompressedTexImage3D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        #endif
        #ifndef skip_index_glCompressedTexSubImage1D
        case glCompressedTexSubImage1D_INDEX: {
            static glCompressedTexSubImage1D_PTR local_glCompressedTexSubImage1D;
            if (local_glCompressedTexSubImage1D == NULL) {
                local_glCompressedTexSubImage1D = (glCompressedTexSubImage1D_PTR)dlsym(g_libgl, "glCompressedTexSubImage1D");
                if (! local_glCompressedTexSubImage1D) {
                    printf("Warning: Unable to dlsym 'glCompressedTexSubImage1D'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            local_glCompressedTexSubImage1D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        #endif
        #ifndef skip_index_glCompressedTexSubImage2D
        case glCompressedTexSubImage2D_INDEX: {
            static glCompressedTexSubImage2D_PTR local_glCompressedTexSubImage2D;
            if (local_glCompressedTexSubImage2D == NULL) {
                local_glCompressedTexSubImage2D = (glCompressedTexSubImage2D_PTR)dlsym(g_libgl, "glCompressedTexSubImage2D");
                if (! local_glCompressedTexSubImage2D) {
                    printf("Warning: Unable to dlsym 'glCompressedTexSubImage2D'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            local_glCompressedTexSubImage2D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        #endif
        #ifndef skip_index_glCompressedTexSubImage3D
        case glCompressedTexSubImage3D_INDEX: {
            static glCompressedTexSubImage3D_PTR local_glCompressedTexSubImage3D;
            if (local_glCompressedTexSubImage3D == NULL) {
                local_glCompressedTexSubImage3D = (glCompressedTexSubImage3D_PTR)dlsym(g_libgl, "glCompressedTexSubImage3D");
                if (! local_glCompressedTexSubImage3D) {
                    printf("Warning: Unable to dlsym 'glCompressedTexSubImage3D'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            local_glCompressedTexSubImage3D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11);
            break;
        }
        #endif
        #ifndef skip_index_glConvolutionFilter1D
        case glConvolutionFilter1D_INDEX: {
            static glConvolutionFilter1D_PTR local_glConvolutionFilter1D;
            if (local_glConvolutionFilter1D == NULL) {
                local_glConvolutionFilter1D = (glConvolutionFilter1D_PTR)dlsym(g_libgl, "glConvolutionFilter1D");
                if (! local_glConvolutionFilter1D) {
                    printf("Warning: Unable to dlsym 'glConvolutionFilter1D'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            local_glConvolutionFilter1D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glConvolutionFilter2D
        case glConvolutionFilter2D_INDEX: {
            static glConvolutionFilter2D_PTR local_glConvolutionFilter2D;
            if (local_glConvolutionFilter2D == NULL) {
                local_glConvolutionFilter2D = (glConvolutionFilter2D_PTR)dlsym(g_libgl, "glConvolutionFilter2D");
                if (! local_glConvolutionFilter2D) {
                    printf("Warning: Unable to dlsym 'glConvolutionFilter2D'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            local_glConvolutionFilter2D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        #endif
        #ifndef skip_index_glConvolutionParameterf
        case glConvolutionParameterf_INDEX: {
            static glConvolutionParameterf_PTR local_glConvolutionParameterf;
            if (local_glConvolutionParameterf == NULL) {
                local_glConvolutionParameterf = (glConvolutionParameterf_PTR)dlsym(g_libgl, "glConvolutionParameterf");
                if (! local_glConvolutionParameterf) {
                    printf("Warning: Unable to dlsym 'glConvolutionParameterf'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLenum_GLfloat args = unpacked->args;
            local_glConvolutionParameterf(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glConvolutionParameterfv
        case glConvolutionParameterfv_INDEX: {
            static glConvolutionParameterfv_PTR local_glConvolutionParameterfv;
            if (local_glConvolutionParameterfv == NULL) {
                local_glConvolutionParameterfv = (glConvolutionParameterfv_PTR)dlsym(g_libgl, "glConvolutionParameterfv");
                if (! local_glConvolutionParameterfv) {
                    printf("Warning: Unable to dlsym 'glConvolutionParameterfv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            local_glConvolutionParameterfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glConvolutionParameteri
        case glConvolutionParameteri_INDEX: {
            static glConvolutionParameteri_PTR local_glConvolutionParameteri;
            if (local_glConvolutionParameteri == NULL) {
                local_glConvolutionParameteri = (glConvolutionParameteri_PTR)dlsym(g_libgl, "glConvolutionParameteri");
                if (! local_glConvolutionParameteri) {
                    printf("Warning: Unable to dlsym 'glConvolutionParameteri'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLint *unpacked = (INDEXED_void_GLenum_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLint args = unpacked->args;
            local_glConvolutionParameteri(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glConvolutionParameteriv
        case glConvolutionParameteriv_INDEX: {
            static glConvolutionParameteriv_PTR local_glConvolutionParameteriv;
            if (local_glConvolutionParameteriv == NULL) {
                local_glConvolutionParameteriv = (glConvolutionParameteriv_PTR)dlsym(g_libgl, "glConvolutionParameteriv");
                if (! local_glConvolutionParameteriv) {
                    printf("Warning: Unable to dlsym 'glConvolutionParameteriv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLint___GENPT__ args = unpacked->args;
            local_glConvolutionParameteriv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glCopyColorSubTable
        case glCopyColorSubTable_INDEX: {
            static glCopyColorSubTable_PTR local_glCopyColorSubTable;
            if (local_glCopyColorSubTable == NULL) {
                local_glCopyColorSubTable = (glCopyColorSubTable_PTR)dlsym(g_libgl, "glCopyColorSubTable");
                if (! local_glCopyColorSubTable) {
                    printf("Warning: Unable to dlsym 'glCopyColorSubTable'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLsizei_GLint_GLint_GLsizei *unpacked = (INDEXED_void_GLenum_GLsizei_GLint_GLint_GLsizei *)packed;
            ARGS_void_GLenum_GLsizei_GLint_GLint_GLsizei args = unpacked->args;
            local_glCopyColorSubTable(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glCopyColorTable
        case glCopyColorTable_INDEX: {
            static glCopyColorTable_PTR local_glCopyColorTable;
            if (local_glCopyColorTable == NULL) {
                local_glCopyColorTable = (glCopyColorTable_PTR)dlsym(g_libgl, "glCopyColorTable");
                if (! local_glCopyColorTable) {
                    printf("Warning: Unable to dlsym 'glCopyColorTable'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLint_GLint_GLsizei *unpacked = (INDEXED_void_GLenum_GLenum_GLint_GLint_GLsizei *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLint_GLsizei args = unpacked->args;
            local_glCopyColorTable(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glCopyConvolutionFilter1D
        case glCopyConvolutionFilter1D_INDEX: {
            static glCopyConvolutionFilter1D_PTR local_glCopyConvolutionFilter1D;
            if (local_glCopyConvolutionFilter1D == NULL) {
                local_glCopyConvolutionFilter1D = (glCopyConvolutionFilter1D_PTR)dlsym(g_libgl, "glCopyConvolutionFilter1D");
                if (! local_glCopyConvolutionFilter1D) {
                    printf("Warning: Unable to dlsym 'glCopyConvolutionFilter1D'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLint_GLint_GLsizei *unpacked = (INDEXED_void_GLenum_GLenum_GLint_GLint_GLsizei *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLint_GLsizei args = unpacked->args;
            local_glCopyConvolutionFilter1D(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glCopyConvolutionFilter2D
        case glCopyConvolutionFilter2D_INDEX: {
            static glCopyConvolutionFilter2D_PTR local_glCopyConvolutionFilter2D;
            if (local_glCopyConvolutionFilter2D == NULL) {
                local_glCopyConvolutionFilter2D = (glCopyConvolutionFilter2D_PTR)dlsym(g_libgl, "glCopyConvolutionFilter2D");
                if (! local_glCopyConvolutionFilter2D) {
                    printf("Warning: Unable to dlsym 'glCopyConvolutionFilter2D'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLint_GLint_GLsizei_GLsizei *unpacked = (INDEXED_void_GLenum_GLenum_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            local_glCopyConvolutionFilter2D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glCopyPixels
        case glCopyPixels_INDEX: {
            static glCopyPixels_PTR local_glCopyPixels;
            if (local_glCopyPixels == NULL) {
                local_glCopyPixels = (glCopyPixels_PTR)dlsym(g_libgl, "glCopyPixels");
                if (! local_glCopyPixels) {
                    printf("Warning: Unable to dlsym 'glCopyPixels'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLint_GLsizei_GLsizei_GLenum *unpacked = (INDEXED_void_GLint_GLint_GLsizei_GLsizei_GLenum *)packed;
            ARGS_void_GLint_GLint_GLsizei_GLsizei_GLenum args = unpacked->args;
            local_glCopyPixels(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glCopyTexImage1D
        case glCopyTexImage1D_INDEX: {
            static glCopyTexImage1D_PTR local_glCopyTexImage1D;
            if (local_glCopyTexImage1D == NULL) {
                local_glCopyTexImage1D = (glCopyTexImage1D_PTR)dlsym(g_libgl, "glCopyTexImage1D");
                if (! local_glCopyTexImage1D) {
                    printf("Warning: Unable to dlsym 'glCopyTexImage1D'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint *unpacked = (INDEXED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint args = unpacked->args;
            local_glCopyTexImage1D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        #endif
        #ifndef skip_index_glCopyTexImage2D
        case glCopyTexImage2D_INDEX: {
            static glCopyTexImage2D_PTR local_glCopyTexImage2D;
            if (local_glCopyTexImage2D == NULL) {
                local_glCopyTexImage2D = (glCopyTexImage2D_PTR)dlsym(g_libgl, "glCopyTexImage2D");
                if (! local_glCopyTexImage2D) {
                    printf("Warning: Unable to dlsym 'glCopyTexImage2D'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint *unpacked = (INDEXED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint args = unpacked->args;
            local_glCopyTexImage2D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        #endif
        #ifndef skip_index_glCopyTexSubImage1D
        case glCopyTexSubImage1D_INDEX: {
            static glCopyTexSubImage1D_PTR local_glCopyTexSubImage1D;
            if (local_glCopyTexSubImage1D == NULL) {
                local_glCopyTexSubImage1D = (glCopyTexSubImage1D_PTR)dlsym(g_libgl, "glCopyTexSubImage1D");
                if (! local_glCopyTexSubImage1D) {
                    printf("Warning: Unable to dlsym 'glCopyTexSubImage1D'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLsizei args = unpacked->args;
            local_glCopyTexSubImage1D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glCopyTexSubImage2D
        case glCopyTexSubImage2D_INDEX: {
            static glCopyTexSubImage2D_PTR local_glCopyTexSubImage2D;
            if (local_glCopyTexSubImage2D == NULL) {
                local_glCopyTexSubImage2D = (glCopyTexSubImage2D_PTR)dlsym(g_libgl, "glCopyTexSubImage2D");
                if (! local_glCopyTexSubImage2D) {
                    printf("Warning: Unable to dlsym 'glCopyTexSubImage2D'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            local_glCopyTexSubImage2D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        #endif
        #ifndef skip_index_glCopyTexSubImage3D
        case glCopyTexSubImage3D_INDEX: {
            static glCopyTexSubImage3D_PTR local_glCopyTexSubImage3D;
            if (local_glCopyTexSubImage3D == NULL) {
                local_glCopyTexSubImage3D = (glCopyTexSubImage3D_PTR)dlsym(g_libgl, "glCopyTexSubImage3D");
                if (! local_glCopyTexSubImage3D) {
                    printf("Warning: Unable to dlsym 'glCopyTexSubImage3D'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            local_glCopyTexSubImage3D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        #endif
        #ifndef skip_index_glCullFace
        case glCullFace_INDEX: {
            static glCullFace_PTR local_glCullFace;
            if (local_glCullFace == NULL) {
                local_glCullFace = (glCullFace_PTR)dlsym(g_libgl, "glCullFace");
                if (! local_glCullFace) {
                    printf("Warning: Unable to dlsym 'glCullFace'\n");
                    return;
                }
            }

            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            local_glCullFace(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glDeleteBuffers
        case glDeleteBuffers_INDEX: {
            static glDeleteBuffers_PTR local_glDeleteBuffers;
            if (local_glDeleteBuffers == NULL) {
                local_glDeleteBuffers = (glDeleteBuffers_PTR)dlsym(g_libgl, "glDeleteBuffers");
                if (! local_glDeleteBuffers) {
                    printf("Warning: Unable to dlsym 'glDeleteBuffers'\n");
                    return;
                }
            }

            INDEXED_void_GLsizei_const_GLuint___GENPT__ *unpacked = (INDEXED_void_GLsizei_const_GLuint___GENPT__ *)packed;
            ARGS_void_GLsizei_const_GLuint___GENPT__ args = unpacked->args;
            local_glDeleteBuffers(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glDeleteLists
        case glDeleteLists_INDEX: {
            static glDeleteLists_PTR local_glDeleteLists;
            if (local_glDeleteLists == NULL) {
                local_glDeleteLists = (glDeleteLists_PTR)dlsym(g_libgl, "glDeleteLists");
                if (! local_glDeleteLists) {
                    printf("Warning: Unable to dlsym 'glDeleteLists'\n");
                    return;
                }
            }

            INDEXED_void_GLuint_GLsizei *unpacked = (INDEXED_void_GLuint_GLsizei *)packed;
            ARGS_void_GLuint_GLsizei args = unpacked->args;
            local_glDeleteLists(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glDeleteQueries
        case glDeleteQueries_INDEX: {
            static glDeleteQueries_PTR local_glDeleteQueries;
            if (local_glDeleteQueries == NULL) {
                local_glDeleteQueries = (glDeleteQueries_PTR)dlsym(g_libgl, "glDeleteQueries");
                if (! local_glDeleteQueries) {
                    printf("Warning: Unable to dlsym 'glDeleteQueries'\n");
                    return;
                }
            }

            INDEXED_void_GLsizei_const_GLuint___GENPT__ *unpacked = (INDEXED_void_GLsizei_const_GLuint___GENPT__ *)packed;
            ARGS_void_GLsizei_const_GLuint___GENPT__ args = unpacked->args;
            local_glDeleteQueries(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glDeleteTextures
        case glDeleteTextures_INDEX: {
            static glDeleteTextures_PTR local_glDeleteTextures;
            if (local_glDeleteTextures == NULL) {
                local_glDeleteTextures = (glDeleteTextures_PTR)dlsym(g_libgl, "glDeleteTextures");
                if (! local_glDeleteTextures) {
                    printf("Warning: Unable to dlsym 'glDeleteTextures'\n");
                    return;
                }
            }

            INDEXED_void_GLsizei_const_GLuint___GENPT__ *unpacked = (INDEXED_void_GLsizei_const_GLuint___GENPT__ *)packed;
            ARGS_void_GLsizei_const_GLuint___GENPT__ args = unpacked->args;
            local_glDeleteTextures(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glDepthFunc
        case glDepthFunc_INDEX: {
            static glDepthFunc_PTR local_glDepthFunc;
            if (local_glDepthFunc == NULL) {
                local_glDepthFunc = (glDepthFunc_PTR)dlsym(g_libgl, "glDepthFunc");
                if (! local_glDepthFunc) {
                    printf("Warning: Unable to dlsym 'glDepthFunc'\n");
                    return;
                }
            }

            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            local_glDepthFunc(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glDepthMask
        case glDepthMask_INDEX: {
            static glDepthMask_PTR local_glDepthMask;
            if (local_glDepthMask == NULL) {
                local_glDepthMask = (glDepthMask_PTR)dlsym(g_libgl, "glDepthMask");
                if (! local_glDepthMask) {
                    printf("Warning: Unable to dlsym 'glDepthMask'\n");
                    return;
                }
            }

            INDEXED_void_GLboolean *unpacked = (INDEXED_void_GLboolean *)packed;
            ARGS_void_GLboolean args = unpacked->args;
            local_glDepthMask(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glDepthRange
        case glDepthRange_INDEX: {
            static glDepthRange_PTR local_glDepthRange;
            if (local_glDepthRange == NULL) {
                local_glDepthRange = (glDepthRange_PTR)dlsym(g_libgl, "glDepthRange");
                if (! local_glDepthRange) {
                    printf("Warning: Unable to dlsym 'glDepthRange'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble args = unpacked->args;
            local_glDepthRange(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glDisable
        case glDisable_INDEX: {
            static glDisable_PTR local_glDisable;
            if (local_glDisable == NULL) {
                local_glDisable = (glDisable_PTR)dlsym(g_libgl, "glDisable");
                if (! local_glDisable) {
                    printf("Warning: Unable to dlsym 'glDisable'\n");
                    return;
                }
            }

            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            local_glDisable(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glDisableClientState
        case glDisableClientState_INDEX: {
            static glDisableClientState_PTR local_glDisableClientState;
            if (local_glDisableClientState == NULL) {
                local_glDisableClientState = (glDisableClientState_PTR)dlsym(g_libgl, "glDisableClientState");
                if (! local_glDisableClientState) {
                    printf("Warning: Unable to dlsym 'glDisableClientState'\n");
                    return;
                }
            }

            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            local_glDisableClientState(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glDrawArrays
        case glDrawArrays_INDEX: {
            static glDrawArrays_PTR local_glDrawArrays;
            if (local_glDrawArrays == NULL) {
                local_glDrawArrays = (glDrawArrays_PTR)dlsym(g_libgl, "glDrawArrays");
                if (! local_glDrawArrays) {
                    printf("Warning: Unable to dlsym 'glDrawArrays'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLsizei *unpacked = (INDEXED_void_GLenum_GLint_GLsizei *)packed;
            ARGS_void_GLenum_GLint_GLsizei args = unpacked->args;
            local_glDrawArrays(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glDrawBuffer
        case glDrawBuffer_INDEX: {
            static glDrawBuffer_PTR local_glDrawBuffer;
            if (local_glDrawBuffer == NULL) {
                local_glDrawBuffer = (glDrawBuffer_PTR)dlsym(g_libgl, "glDrawBuffer");
                if (! local_glDrawBuffer) {
                    printf("Warning: Unable to dlsym 'glDrawBuffer'\n");
                    return;
                }
            }

            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            local_glDrawBuffer(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glDrawElements
        case glDrawElements_INDEX: {
            static glDrawElements_PTR local_glDrawElements;
            if (local_glDrawElements == NULL) {
                local_glDrawElements = (glDrawElements_PTR)dlsym(g_libgl, "glDrawElements");
                if (! local_glDrawElements) {
                    printf("Warning: Unable to dlsym 'glDrawElements'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            local_glDrawElements(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glDrawPixels
        case glDrawPixels_INDEX: {
            static glDrawPixels_PTR local_glDrawPixels;
            if (local_glDrawPixels == NULL) {
                local_glDrawPixels = (glDrawPixels_PTR)dlsym(g_libgl, "glDrawPixels");
                if (! local_glDrawPixels) {
                    printf("Warning: Unable to dlsym 'glDrawPixels'\n");
                    return;
                }
            }

            INDEXED_void_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            local_glDrawPixels(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glDrawRangeElements
        case glDrawRangeElements_INDEX: {
            static glDrawRangeElements_PTR local_glDrawRangeElements;
            if (local_glDrawRangeElements == NULL) {
                local_glDrawRangeElements = (glDrawRangeElements_PTR)dlsym(g_libgl, "glDrawRangeElements");
                if (! local_glDrawRangeElements) {
                    printf("Warning: Unable to dlsym 'glDrawRangeElements'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLuint_GLuint_GLsizei_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLuint_GLuint_GLsizei_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLuint_GLuint_GLsizei_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            local_glDrawRangeElements(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glEdgeFlag
        case glEdgeFlag_INDEX: {
            static glEdgeFlag_PTR local_glEdgeFlag;
            if (local_glEdgeFlag == NULL) {
                local_glEdgeFlag = (glEdgeFlag_PTR)dlsym(g_libgl, "glEdgeFlag");
                if (! local_glEdgeFlag) {
                    printf("Warning: Unable to dlsym 'glEdgeFlag'\n");
                    return;
                }
            }

            INDEXED_void_GLboolean *unpacked = (INDEXED_void_GLboolean *)packed;
            ARGS_void_GLboolean args = unpacked->args;
            local_glEdgeFlag(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glEdgeFlagPointer
        case glEdgeFlagPointer_INDEX: {
            static glEdgeFlagPointer_PTR local_glEdgeFlagPointer;
            if (local_glEdgeFlagPointer == NULL) {
                local_glEdgeFlagPointer = (glEdgeFlagPointer_PTR)dlsym(g_libgl, "glEdgeFlagPointer");
                if (! local_glEdgeFlagPointer) {
                    printf("Warning: Unable to dlsym 'glEdgeFlagPointer'\n");
                    return;
                }
            }

            INDEXED_void_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            local_glEdgeFlagPointer(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glEdgeFlagv
        case glEdgeFlagv_INDEX: {
            static glEdgeFlagv_PTR local_glEdgeFlagv;
            if (local_glEdgeFlagv == NULL) {
                local_glEdgeFlagv = (glEdgeFlagv_PTR)dlsym(g_libgl, "glEdgeFlagv");
                if (! local_glEdgeFlagv) {
                    printf("Warning: Unable to dlsym 'glEdgeFlagv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLboolean___GENPT__ *unpacked = (INDEXED_void_const_GLboolean___GENPT__ *)packed;
            ARGS_void_const_GLboolean___GENPT__ args = unpacked->args;
            local_glEdgeFlagv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glEnable
        case glEnable_INDEX: {
            static glEnable_PTR local_glEnable;
            if (local_glEnable == NULL) {
                local_glEnable = (glEnable_PTR)dlsym(g_libgl, "glEnable");
                if (! local_glEnable) {
                    printf("Warning: Unable to dlsym 'glEnable'\n");
                    return;
                }
            }

            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            local_glEnable(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glEnableClientState
        case glEnableClientState_INDEX: {
            static glEnableClientState_PTR local_glEnableClientState;
            if (local_glEnableClientState == NULL) {
                local_glEnableClientState = (glEnableClientState_PTR)dlsym(g_libgl, "glEnableClientState");
                if (! local_glEnableClientState) {
                    printf("Warning: Unable to dlsym 'glEnableClientState'\n");
                    return;
                }
            }

            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            local_glEnableClientState(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glEnd
        case glEnd_INDEX: {
            static glEnd_PTR local_glEnd;
            if (local_glEnd == NULL) {
                local_glEnd = (glEnd_PTR)dlsym(g_libgl, "glEnd");
                if (! local_glEnd) {
                    printf("Warning: Unable to dlsym 'glEnd'\n");
                    return;
                }
            }

            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            local_glEnd();
            break;
        }
        #endif
        #ifndef skip_index_glEndList
        case glEndList_INDEX: {
            static glEndList_PTR local_glEndList;
            if (local_glEndList == NULL) {
                local_glEndList = (glEndList_PTR)dlsym(g_libgl, "glEndList");
                if (! local_glEndList) {
                    printf("Warning: Unable to dlsym 'glEndList'\n");
                    return;
                }
            }

            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            local_glEndList();
            break;
        }
        #endif
        #ifndef skip_index_glEndQuery
        case glEndQuery_INDEX: {
            static glEndQuery_PTR local_glEndQuery;
            if (local_glEndQuery == NULL) {
                local_glEndQuery = (glEndQuery_PTR)dlsym(g_libgl, "glEndQuery");
                if (! local_glEndQuery) {
                    printf("Warning: Unable to dlsym 'glEndQuery'\n");
                    return;
                }
            }

            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            local_glEndQuery(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glEvalCoord1d
        case glEvalCoord1d_INDEX: {
            static glEvalCoord1d_PTR local_glEvalCoord1d;
            if (local_glEvalCoord1d == NULL) {
                local_glEvalCoord1d = (glEvalCoord1d_PTR)dlsym(g_libgl, "glEvalCoord1d");
                if (! local_glEvalCoord1d) {
                    printf("Warning: Unable to dlsym 'glEvalCoord1d'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble *unpacked = (INDEXED_void_GLdouble *)packed;
            ARGS_void_GLdouble args = unpacked->args;
            local_glEvalCoord1d(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glEvalCoord1dv
        case glEvalCoord1dv_INDEX: {
            static glEvalCoord1dv_PTR local_glEvalCoord1dv;
            if (local_glEvalCoord1dv == NULL) {
                local_glEvalCoord1dv = (glEvalCoord1dv_PTR)dlsym(g_libgl, "glEvalCoord1dv");
                if (! local_glEvalCoord1dv) {
                    printf("Warning: Unable to dlsym 'glEvalCoord1dv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            local_glEvalCoord1dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glEvalCoord1f
        case glEvalCoord1f_INDEX: {
            static glEvalCoord1f_PTR local_glEvalCoord1f;
            if (local_glEvalCoord1f == NULL) {
                local_glEvalCoord1f = (glEvalCoord1f_PTR)dlsym(g_libgl, "glEvalCoord1f");
                if (! local_glEvalCoord1f) {
                    printf("Warning: Unable to dlsym 'glEvalCoord1f'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat *unpacked = (INDEXED_void_GLfloat *)packed;
            ARGS_void_GLfloat args = unpacked->args;
            local_glEvalCoord1f(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glEvalCoord1fv
        case glEvalCoord1fv_INDEX: {
            static glEvalCoord1fv_PTR local_glEvalCoord1fv;
            if (local_glEvalCoord1fv == NULL) {
                local_glEvalCoord1fv = (glEvalCoord1fv_PTR)dlsym(g_libgl, "glEvalCoord1fv");
                if (! local_glEvalCoord1fv) {
                    printf("Warning: Unable to dlsym 'glEvalCoord1fv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            local_glEvalCoord1fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glEvalCoord2d
        case glEvalCoord2d_INDEX: {
            static glEvalCoord2d_PTR local_glEvalCoord2d;
            if (local_glEvalCoord2d == NULL) {
                local_glEvalCoord2d = (glEvalCoord2d_PTR)dlsym(g_libgl, "glEvalCoord2d");
                if (! local_glEvalCoord2d) {
                    printf("Warning: Unable to dlsym 'glEvalCoord2d'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble args = unpacked->args;
            local_glEvalCoord2d(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glEvalCoord2dv
        case glEvalCoord2dv_INDEX: {
            static glEvalCoord2dv_PTR local_glEvalCoord2dv;
            if (local_glEvalCoord2dv == NULL) {
                local_glEvalCoord2dv = (glEvalCoord2dv_PTR)dlsym(g_libgl, "glEvalCoord2dv");
                if (! local_glEvalCoord2dv) {
                    printf("Warning: Unable to dlsym 'glEvalCoord2dv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            local_glEvalCoord2dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glEvalCoord2f
        case glEvalCoord2f_INDEX: {
            static glEvalCoord2f_PTR local_glEvalCoord2f;
            if (local_glEvalCoord2f == NULL) {
                local_glEvalCoord2f = (glEvalCoord2f_PTR)dlsym(g_libgl, "glEvalCoord2f");
                if (! local_glEvalCoord2f) {
                    printf("Warning: Unable to dlsym 'glEvalCoord2f'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat args = unpacked->args;
            local_glEvalCoord2f(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glEvalCoord2fv
        case glEvalCoord2fv_INDEX: {
            static glEvalCoord2fv_PTR local_glEvalCoord2fv;
            if (local_glEvalCoord2fv == NULL) {
                local_glEvalCoord2fv = (glEvalCoord2fv_PTR)dlsym(g_libgl, "glEvalCoord2fv");
                if (! local_glEvalCoord2fv) {
                    printf("Warning: Unable to dlsym 'glEvalCoord2fv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            local_glEvalCoord2fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glEvalMesh1
        case glEvalMesh1_INDEX: {
            static glEvalMesh1_PTR local_glEvalMesh1;
            if (local_glEvalMesh1 == NULL) {
                local_glEvalMesh1 = (glEvalMesh1_PTR)dlsym(g_libgl, "glEvalMesh1");
                if (! local_glEvalMesh1) {
                    printf("Warning: Unable to dlsym 'glEvalMesh1'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLint *unpacked = (INDEXED_void_GLenum_GLint_GLint *)packed;
            ARGS_void_GLenum_GLint_GLint args = unpacked->args;
            local_glEvalMesh1(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glEvalMesh2
        case glEvalMesh2_INDEX: {
            static glEvalMesh2_PTR local_glEvalMesh2;
            if (local_glEvalMesh2 == NULL) {
                local_glEvalMesh2 = (glEvalMesh2_PTR)dlsym(g_libgl, "glEvalMesh2");
                if (! local_glEvalMesh2) {
                    printf("Warning: Unable to dlsym 'glEvalMesh2'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLint_GLint_GLint *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint args = unpacked->args;
            local_glEvalMesh2(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glEvalPoint1
        case glEvalPoint1_INDEX: {
            static glEvalPoint1_PTR local_glEvalPoint1;
            if (local_glEvalPoint1 == NULL) {
                local_glEvalPoint1 = (glEvalPoint1_PTR)dlsym(g_libgl, "glEvalPoint1");
                if (! local_glEvalPoint1) {
                    printf("Warning: Unable to dlsym 'glEvalPoint1'\n");
                    return;
                }
            }

            INDEXED_void_GLint *unpacked = (INDEXED_void_GLint *)packed;
            ARGS_void_GLint args = unpacked->args;
            local_glEvalPoint1(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glEvalPoint2
        case glEvalPoint2_INDEX: {
            static glEvalPoint2_PTR local_glEvalPoint2;
            if (local_glEvalPoint2 == NULL) {
                local_glEvalPoint2 = (glEvalPoint2_PTR)dlsym(g_libgl, "glEvalPoint2");
                if (! local_glEvalPoint2) {
                    printf("Warning: Unable to dlsym 'glEvalPoint2'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint *)packed;
            ARGS_void_GLint_GLint args = unpacked->args;
            local_glEvalPoint2(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glFeedbackBuffer
        case glFeedbackBuffer_INDEX: {
            static glFeedbackBuffer_PTR local_glFeedbackBuffer;
            if (local_glFeedbackBuffer == NULL) {
                local_glFeedbackBuffer = (glFeedbackBuffer_PTR)dlsym(g_libgl, "glFeedbackBuffer");
                if (! local_glFeedbackBuffer) {
                    printf("Warning: Unable to dlsym 'glFeedbackBuffer'\n");
                    return;
                }
            }

            INDEXED_void_GLsizei_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLsizei_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLsizei_GLenum_GLfloat___GENPT__ args = unpacked->args;
            local_glFeedbackBuffer(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glFinish
        case glFinish_INDEX: {
            static glFinish_PTR local_glFinish;
            if (local_glFinish == NULL) {
                local_glFinish = (glFinish_PTR)dlsym(g_libgl, "glFinish");
                if (! local_glFinish) {
                    printf("Warning: Unable to dlsym 'glFinish'\n");
                    return;
                }
            }

            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            local_glFinish();
            break;
        }
        #endif
        #ifndef skip_index_glFlush
        case glFlush_INDEX: {
            static glFlush_PTR local_glFlush;
            if (local_glFlush == NULL) {
                local_glFlush = (glFlush_PTR)dlsym(g_libgl, "glFlush");
                if (! local_glFlush) {
                    printf("Warning: Unable to dlsym 'glFlush'\n");
                    return;
                }
            }

            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            local_glFlush();
            break;
        }
        #endif
        #ifndef skip_index_glFogCoordPointer
        case glFogCoordPointer_INDEX: {
            static glFogCoordPointer_PTR local_glFogCoordPointer;
            if (local_glFogCoordPointer == NULL) {
                local_glFogCoordPointer = (glFogCoordPointer_PTR)dlsym(g_libgl, "glFogCoordPointer");
                if (! local_glFogCoordPointer) {
                    printf("Warning: Unable to dlsym 'glFogCoordPointer'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            local_glFogCoordPointer(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glFogCoordd
        case glFogCoordd_INDEX: {
            static glFogCoordd_PTR local_glFogCoordd;
            if (local_glFogCoordd == NULL) {
                local_glFogCoordd = (glFogCoordd_PTR)dlsym(g_libgl, "glFogCoordd");
                if (! local_glFogCoordd) {
                    printf("Warning: Unable to dlsym 'glFogCoordd'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble *unpacked = (INDEXED_void_GLdouble *)packed;
            ARGS_void_GLdouble args = unpacked->args;
            local_glFogCoordd(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glFogCoorddv
        case glFogCoorddv_INDEX: {
            static glFogCoorddv_PTR local_glFogCoorddv;
            if (local_glFogCoorddv == NULL) {
                local_glFogCoorddv = (glFogCoorddv_PTR)dlsym(g_libgl, "glFogCoorddv");
                if (! local_glFogCoorddv) {
                    printf("Warning: Unable to dlsym 'glFogCoorddv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            local_glFogCoorddv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glFogCoordf
        case glFogCoordf_INDEX: {
            static glFogCoordf_PTR local_glFogCoordf;
            if (local_glFogCoordf == NULL) {
                local_glFogCoordf = (glFogCoordf_PTR)dlsym(g_libgl, "glFogCoordf");
                if (! local_glFogCoordf) {
                    printf("Warning: Unable to dlsym 'glFogCoordf'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat *unpacked = (INDEXED_void_GLfloat *)packed;
            ARGS_void_GLfloat args = unpacked->args;
            local_glFogCoordf(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glFogCoordfv
        case glFogCoordfv_INDEX: {
            static glFogCoordfv_PTR local_glFogCoordfv;
            if (local_glFogCoordfv == NULL) {
                local_glFogCoordfv = (glFogCoordfv_PTR)dlsym(g_libgl, "glFogCoordfv");
                if (! local_glFogCoordfv) {
                    printf("Warning: Unable to dlsym 'glFogCoordfv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            local_glFogCoordfv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glFogf
        case glFogf_INDEX: {
            static glFogf_PTR local_glFogf;
            if (local_glFogf == NULL) {
                local_glFogf = (glFogf_PTR)dlsym(g_libgl, "glFogf");
                if (! local_glFogf) {
                    printf("Warning: Unable to dlsym 'glFogf'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat args = unpacked->args;
            local_glFogf(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glFogfv
        case glFogfv_INDEX: {
            static glFogfv_PTR local_glFogfv;
            if (local_glFogfv == NULL) {
                local_glFogfv = (glFogfv_PTR)dlsym(g_libgl, "glFogfv");
                if (! local_glFogfv) {
                    printf("Warning: Unable to dlsym 'glFogfv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            local_glFogfv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glFogi
        case glFogi_INDEX: {
            static glFogi_PTR local_glFogi;
            if (local_glFogi == NULL) {
                local_glFogi = (glFogi_PTR)dlsym(g_libgl, "glFogi");
                if (! local_glFogi) {
                    printf("Warning: Unable to dlsym 'glFogi'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint *unpacked = (INDEXED_void_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLint args = unpacked->args;
            local_glFogi(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glFogiv
        case glFogiv_INDEX: {
            static glFogiv_PTR local_glFogiv;
            if (local_glFogiv == NULL) {
                local_glFogiv = (glFogiv_PTR)dlsym(g_libgl, "glFogiv");
                if (! local_glFogiv) {
                    printf("Warning: Unable to dlsym 'glFogiv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLint___GENPT__ args = unpacked->args;
            local_glFogiv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glFrontFace
        case glFrontFace_INDEX: {
            static glFrontFace_PTR local_glFrontFace;
            if (local_glFrontFace == NULL) {
                local_glFrontFace = (glFrontFace_PTR)dlsym(g_libgl, "glFrontFace");
                if (! local_glFrontFace) {
                    printf("Warning: Unable to dlsym 'glFrontFace'\n");
                    return;
                }
            }

            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            local_glFrontFace(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glFrustum
        case glFrustum_INDEX: {
            static glFrustum_PTR local_glFrustum;
            if (local_glFrustum == NULL) {
                local_glFrustum = (glFrustum_PTR)dlsym(g_libgl, "glFrustum");
                if (! local_glFrustum) {
                    printf("Warning: Unable to dlsym 'glFrustum'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            local_glFrustum(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glGenBuffers
        case glGenBuffers_INDEX: {
            static glGenBuffers_PTR local_glGenBuffers;
            if (local_glGenBuffers == NULL) {
                local_glGenBuffers = (glGenBuffers_PTR)dlsym(g_libgl, "glGenBuffers");
                if (! local_glGenBuffers) {
                    printf("Warning: Unable to dlsym 'glGenBuffers'\n");
                    return;
                }
            }

            INDEXED_void_GLsizei_GLuint___GENPT__ *unpacked = (INDEXED_void_GLsizei_GLuint___GENPT__ *)packed;
            ARGS_void_GLsizei_GLuint___GENPT__ args = unpacked->args;
            local_glGenBuffers(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glGenLists
        case glGenLists_INDEX: {
            static glGenLists_PTR local_glGenLists;
            if (local_glGenLists == NULL) {
                local_glGenLists = (glGenLists_PTR)dlsym(g_libgl, "glGenLists");
                if (! local_glGenLists) {
                    printf("Warning: Unable to dlsym 'glGenLists'\n");
                    return;
                }
            }

            INDEXED_GLuint_GLsizei *unpacked = (INDEXED_GLuint_GLsizei *)packed;
            ARGS_GLuint_GLsizei args = unpacked->args;
            GLuint *ret = (GLuint *)ret_v;
            *ret =
            local_glGenLists(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glGenQueries
        case glGenQueries_INDEX: {
            static glGenQueries_PTR local_glGenQueries;
            if (local_glGenQueries == NULL) {
                local_glGenQueries = (glGenQueries_PTR)dlsym(g_libgl, "glGenQueries");
                if (! local_glGenQueries) {
                    printf("Warning: Unable to dlsym 'glGenQueries'\n");
                    return;
                }
            }

            INDEXED_void_GLsizei_GLuint___GENPT__ *unpacked = (INDEXED_void_GLsizei_GLuint___GENPT__ *)packed;
            ARGS_void_GLsizei_GLuint___GENPT__ args = unpacked->args;
            local_glGenQueries(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glGenTextures
        case glGenTextures_INDEX: {
            static glGenTextures_PTR local_glGenTextures;
            if (local_glGenTextures == NULL) {
                local_glGenTextures = (glGenTextures_PTR)dlsym(g_libgl, "glGenTextures");
                if (! local_glGenTextures) {
                    printf("Warning: Unable to dlsym 'glGenTextures'\n");
                    return;
                }
            }

            INDEXED_void_GLsizei_GLuint___GENPT__ *unpacked = (INDEXED_void_GLsizei_GLuint___GENPT__ *)packed;
            ARGS_void_GLsizei_GLuint___GENPT__ args = unpacked->args;
            local_glGenTextures(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glGetBooleanv
        case glGetBooleanv_INDEX: {
            static glGetBooleanv_PTR local_glGetBooleanv;
            if (local_glGetBooleanv == NULL) {
                local_glGetBooleanv = (glGetBooleanv_PTR)dlsym(g_libgl, "glGetBooleanv");
                if (! local_glGetBooleanv) {
                    printf("Warning: Unable to dlsym 'glGetBooleanv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLboolean___GENPT__ *unpacked = (INDEXED_void_GLenum_GLboolean___GENPT__ *)packed;
            ARGS_void_GLenum_GLboolean___GENPT__ args = unpacked->args;
            local_glGetBooleanv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glGetBufferParameteriv
        case glGetBufferParameteriv_INDEX: {
            static glGetBufferParameteriv_PTR local_glGetBufferParameteriv;
            if (local_glGetBufferParameteriv == NULL) {
                local_glGetBufferParameteriv = (glGetBufferParameteriv_PTR)dlsym(g_libgl, "glGetBufferParameteriv");
                if (! local_glGetBufferParameteriv) {
                    printf("Warning: Unable to dlsym 'glGetBufferParameteriv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            local_glGetBufferParameteriv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetBufferPointerv
        case glGetBufferPointerv_INDEX: {
            static glGetBufferPointerv_PTR local_glGetBufferPointerv;
            if (local_glGetBufferPointerv == NULL) {
                local_glGetBufferPointerv = (glGetBufferPointerv_PTR)dlsym(g_libgl, "glGetBufferPointerv");
                if (! local_glGetBufferPointerv) {
                    printf("Warning: Unable to dlsym 'glGetBufferPointerv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLvoid___GENPT__ args = unpacked->args;
            local_glGetBufferPointerv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetBufferSubData
        case glGetBufferSubData_INDEX: {
            static glGetBufferSubData_PTR local_glGetBufferSubData;
            if (local_glGetBufferSubData == NULL) {
                local_glGetBufferSubData = (glGetBufferSubData_PTR)dlsym(g_libgl, "glGetBufferSubData");
                if (! local_glGetBufferSubData) {
                    printf("Warning: Unable to dlsym 'glGetBufferSubData'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLintptr_GLsizeiptr_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLintptr_GLsizeiptr_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLintptr_GLsizeiptr_GLvoid___GENPT__ args = unpacked->args;
            local_glGetBufferSubData(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glGetClipPlane
        case glGetClipPlane_INDEX: {
            static glGetClipPlane_PTR local_glGetClipPlane;
            if (local_glGetClipPlane == NULL) {
                local_glGetClipPlane = (glGetClipPlane_PTR)dlsym(g_libgl, "glGetClipPlane");
                if (! local_glGetClipPlane) {
                    printf("Warning: Unable to dlsym 'glGetClipPlane'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLdouble___GENPT__ *unpacked = (INDEXED_void_GLenum_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_GLdouble___GENPT__ args = unpacked->args;
            local_glGetClipPlane(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glGetColorTable
        case glGetColorTable_INDEX: {
            static glGetColorTable_PTR local_glGetColorTable;
            if (local_glGetColorTable == NULL) {
                local_glGetColorTable = (glGetColorTable_PTR)dlsym(g_libgl, "glGetColorTable");
                if (! local_glGetColorTable) {
                    printf("Warning: Unable to dlsym 'glGetColorTable'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLenum_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLvoid___GENPT__ args = unpacked->args;
            local_glGetColorTable(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glGetColorTableParameterfv
        case glGetColorTableParameterfv_INDEX: {
            static glGetColorTableParameterfv_PTR local_glGetColorTableParameterfv;
            if (local_glGetColorTableParameterfv == NULL) {
                local_glGetColorTableParameterfv = (glGetColorTableParameterfv_PTR)dlsym(g_libgl, "glGetColorTableParameterfv");
                if (! local_glGetColorTableParameterfv) {
                    printf("Warning: Unable to dlsym 'glGetColorTableParameterfv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            local_glGetColorTableParameterfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetColorTableParameteriv
        case glGetColorTableParameteriv_INDEX: {
            static glGetColorTableParameteriv_PTR local_glGetColorTableParameteriv;
            if (local_glGetColorTableParameteriv == NULL) {
                local_glGetColorTableParameteriv = (glGetColorTableParameteriv_PTR)dlsym(g_libgl, "glGetColorTableParameteriv");
                if (! local_glGetColorTableParameteriv) {
                    printf("Warning: Unable to dlsym 'glGetColorTableParameteriv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            local_glGetColorTableParameteriv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetCompressedTexImage
        case glGetCompressedTexImage_INDEX: {
            static glGetCompressedTexImage_PTR local_glGetCompressedTexImage;
            if (local_glGetCompressedTexImage == NULL) {
                local_glGetCompressedTexImage = (glGetCompressedTexImage_PTR)dlsym(g_libgl, "glGetCompressedTexImage");
                if (! local_glGetCompressedTexImage) {
                    printf("Warning: Unable to dlsym 'glGetCompressedTexImage'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLvoid___GENPT__ args = unpacked->args;
            local_glGetCompressedTexImage(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetConvolutionFilter
        case glGetConvolutionFilter_INDEX: {
            static glGetConvolutionFilter_PTR local_glGetConvolutionFilter;
            if (local_glGetConvolutionFilter == NULL) {
                local_glGetConvolutionFilter = (glGetConvolutionFilter_PTR)dlsym(g_libgl, "glGetConvolutionFilter");
                if (! local_glGetConvolutionFilter) {
                    printf("Warning: Unable to dlsym 'glGetConvolutionFilter'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLenum_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLvoid___GENPT__ args = unpacked->args;
            local_glGetConvolutionFilter(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glGetConvolutionParameterfv
        case glGetConvolutionParameterfv_INDEX: {
            static glGetConvolutionParameterfv_PTR local_glGetConvolutionParameterfv;
            if (local_glGetConvolutionParameterfv == NULL) {
                local_glGetConvolutionParameterfv = (glGetConvolutionParameterfv_PTR)dlsym(g_libgl, "glGetConvolutionParameterfv");
                if (! local_glGetConvolutionParameterfv) {
                    printf("Warning: Unable to dlsym 'glGetConvolutionParameterfv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            local_glGetConvolutionParameterfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetConvolutionParameteriv
        case glGetConvolutionParameteriv_INDEX: {
            static glGetConvolutionParameteriv_PTR local_glGetConvolutionParameteriv;
            if (local_glGetConvolutionParameteriv == NULL) {
                local_glGetConvolutionParameteriv = (glGetConvolutionParameteriv_PTR)dlsym(g_libgl, "glGetConvolutionParameteriv");
                if (! local_glGetConvolutionParameteriv) {
                    printf("Warning: Unable to dlsym 'glGetConvolutionParameteriv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            local_glGetConvolutionParameteriv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetDoublev
        case glGetDoublev_INDEX: {
            static glGetDoublev_PTR local_glGetDoublev;
            if (local_glGetDoublev == NULL) {
                local_glGetDoublev = (glGetDoublev_PTR)dlsym(g_libgl, "glGetDoublev");
                if (! local_glGetDoublev) {
                    printf("Warning: Unable to dlsym 'glGetDoublev'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLdouble___GENPT__ *unpacked = (INDEXED_void_GLenum_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_GLdouble___GENPT__ args = unpacked->args;
            local_glGetDoublev(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glGetError
        case glGetError_INDEX: {
            static glGetError_PTR local_glGetError;
            if (local_glGetError == NULL) {
                local_glGetError = (glGetError_PTR)dlsym(g_libgl, "glGetError");
                if (! local_glGetError) {
                    printf("Warning: Unable to dlsym 'glGetError'\n");
                    return;
                }
            }

            INDEXED_GLenum *unpacked = (INDEXED_GLenum *)packed;
            ARGS_GLenum args = unpacked->args;
            GLenum *ret = (GLenum *)ret_v;
            *ret =
            local_glGetError();
            break;
        }
        #endif
        #ifndef skip_index_glGetFloatv
        case glGetFloatv_INDEX: {
            static glGetFloatv_PTR local_glGetFloatv;
            if (local_glGetFloatv == NULL) {
                local_glGetFloatv = (glGetFloatv_PTR)dlsym(g_libgl, "glGetFloatv");
                if (! local_glGetFloatv) {
                    printf("Warning: Unable to dlsym 'glGetFloatv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLfloat___GENPT__ args = unpacked->args;
            local_glGetFloatv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glGetHistogram
        case glGetHistogram_INDEX: {
            static glGetHistogram_PTR local_glGetHistogram;
            if (local_glGetHistogram == NULL) {
                local_glGetHistogram = (glGetHistogram_PTR)dlsym(g_libgl, "glGetHistogram");
                if (! local_glGetHistogram) {
                    printf("Warning: Unable to dlsym 'glGetHistogram'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__ args = unpacked->args;
            local_glGetHistogram(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glGetHistogramParameterfv
        case glGetHistogramParameterfv_INDEX: {
            static glGetHistogramParameterfv_PTR local_glGetHistogramParameterfv;
            if (local_glGetHistogramParameterfv == NULL) {
                local_glGetHistogramParameterfv = (glGetHistogramParameterfv_PTR)dlsym(g_libgl, "glGetHistogramParameterfv");
                if (! local_glGetHistogramParameterfv) {
                    printf("Warning: Unable to dlsym 'glGetHistogramParameterfv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            local_glGetHistogramParameterfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetHistogramParameteriv
        case glGetHistogramParameteriv_INDEX: {
            static glGetHistogramParameteriv_PTR local_glGetHistogramParameteriv;
            if (local_glGetHistogramParameteriv == NULL) {
                local_glGetHistogramParameteriv = (glGetHistogramParameteriv_PTR)dlsym(g_libgl, "glGetHistogramParameteriv");
                if (! local_glGetHistogramParameteriv) {
                    printf("Warning: Unable to dlsym 'glGetHistogramParameteriv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            local_glGetHistogramParameteriv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetIntegerv
        case glGetIntegerv_INDEX: {
            static glGetIntegerv_PTR local_glGetIntegerv;
            if (local_glGetIntegerv == NULL) {
                local_glGetIntegerv = (glGetIntegerv_PTR)dlsym(g_libgl, "glGetIntegerv");
                if (! local_glGetIntegerv) {
                    printf("Warning: Unable to dlsym 'glGetIntegerv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLint___GENPT__ args = unpacked->args;
            local_glGetIntegerv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glGetLightfv
        case glGetLightfv_INDEX: {
            static glGetLightfv_PTR local_glGetLightfv;
            if (local_glGetLightfv == NULL) {
                local_glGetLightfv = (glGetLightfv_PTR)dlsym(g_libgl, "glGetLightfv");
                if (! local_glGetLightfv) {
                    printf("Warning: Unable to dlsym 'glGetLightfv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            local_glGetLightfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetLightiv
        case glGetLightiv_INDEX: {
            static glGetLightiv_PTR local_glGetLightiv;
            if (local_glGetLightiv == NULL) {
                local_glGetLightiv = (glGetLightiv_PTR)dlsym(g_libgl, "glGetLightiv");
                if (! local_glGetLightiv) {
                    printf("Warning: Unable to dlsym 'glGetLightiv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            local_glGetLightiv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetMapdv
        case glGetMapdv_INDEX: {
            static glGetMapdv_PTR local_glGetMapdv;
            if (local_glGetMapdv == NULL) {
                local_glGetMapdv = (glGetMapdv_PTR)dlsym(g_libgl, "glGetMapdv");
                if (! local_glGetMapdv) {
                    printf("Warning: Unable to dlsym 'glGetMapdv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLdouble___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLdouble___GENPT__ args = unpacked->args;
            local_glGetMapdv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetMapfv
        case glGetMapfv_INDEX: {
            static glGetMapfv_PTR local_glGetMapfv;
            if (local_glGetMapfv == NULL) {
                local_glGetMapfv = (glGetMapfv_PTR)dlsym(g_libgl, "glGetMapfv");
                if (! local_glGetMapfv) {
                    printf("Warning: Unable to dlsym 'glGetMapfv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            local_glGetMapfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetMapiv
        case glGetMapiv_INDEX: {
            static glGetMapiv_PTR local_glGetMapiv;
            if (local_glGetMapiv == NULL) {
                local_glGetMapiv = (glGetMapiv_PTR)dlsym(g_libgl, "glGetMapiv");
                if (! local_glGetMapiv) {
                    printf("Warning: Unable to dlsym 'glGetMapiv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            local_glGetMapiv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetMaterialfv
        case glGetMaterialfv_INDEX: {
            static glGetMaterialfv_PTR local_glGetMaterialfv;
            if (local_glGetMaterialfv == NULL) {
                local_glGetMaterialfv = (glGetMaterialfv_PTR)dlsym(g_libgl, "glGetMaterialfv");
                if (! local_glGetMaterialfv) {
                    printf("Warning: Unable to dlsym 'glGetMaterialfv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            local_glGetMaterialfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetMaterialiv
        case glGetMaterialiv_INDEX: {
            static glGetMaterialiv_PTR local_glGetMaterialiv;
            if (local_glGetMaterialiv == NULL) {
                local_glGetMaterialiv = (glGetMaterialiv_PTR)dlsym(g_libgl, "glGetMaterialiv");
                if (! local_glGetMaterialiv) {
                    printf("Warning: Unable to dlsym 'glGetMaterialiv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            local_glGetMaterialiv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetMinmax
        case glGetMinmax_INDEX: {
            static glGetMinmax_PTR local_glGetMinmax;
            if (local_glGetMinmax == NULL) {
                local_glGetMinmax = (glGetMinmax_PTR)dlsym(g_libgl, "glGetMinmax");
                if (! local_glGetMinmax) {
                    printf("Warning: Unable to dlsym 'glGetMinmax'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__ args = unpacked->args;
            local_glGetMinmax(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glGetMinmaxParameterfv
        case glGetMinmaxParameterfv_INDEX: {
            static glGetMinmaxParameterfv_PTR local_glGetMinmaxParameterfv;
            if (local_glGetMinmaxParameterfv == NULL) {
                local_glGetMinmaxParameterfv = (glGetMinmaxParameterfv_PTR)dlsym(g_libgl, "glGetMinmaxParameterfv");
                if (! local_glGetMinmaxParameterfv) {
                    printf("Warning: Unable to dlsym 'glGetMinmaxParameterfv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            local_glGetMinmaxParameterfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetMinmaxParameteriv
        case glGetMinmaxParameteriv_INDEX: {
            static glGetMinmaxParameteriv_PTR local_glGetMinmaxParameteriv;
            if (local_glGetMinmaxParameteriv == NULL) {
                local_glGetMinmaxParameteriv = (glGetMinmaxParameteriv_PTR)dlsym(g_libgl, "glGetMinmaxParameteriv");
                if (! local_glGetMinmaxParameteriv) {
                    printf("Warning: Unable to dlsym 'glGetMinmaxParameteriv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            local_glGetMinmaxParameteriv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetPixelMapfv
        case glGetPixelMapfv_INDEX: {
            static glGetPixelMapfv_PTR local_glGetPixelMapfv;
            if (local_glGetPixelMapfv == NULL) {
                local_glGetPixelMapfv = (glGetPixelMapfv_PTR)dlsym(g_libgl, "glGetPixelMapfv");
                if (! local_glGetPixelMapfv) {
                    printf("Warning: Unable to dlsym 'glGetPixelMapfv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLfloat___GENPT__ args = unpacked->args;
            local_glGetPixelMapfv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glGetPixelMapuiv
        case glGetPixelMapuiv_INDEX: {
            static glGetPixelMapuiv_PTR local_glGetPixelMapuiv;
            if (local_glGetPixelMapuiv == NULL) {
                local_glGetPixelMapuiv = (glGetPixelMapuiv_PTR)dlsym(g_libgl, "glGetPixelMapuiv");
                if (! local_glGetPixelMapuiv) {
                    printf("Warning: Unable to dlsym 'glGetPixelMapuiv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLuint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLuint___GENPT__ *)packed;
            ARGS_void_GLenum_GLuint___GENPT__ args = unpacked->args;
            local_glGetPixelMapuiv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glGetPixelMapusv
        case glGetPixelMapusv_INDEX: {
            static glGetPixelMapusv_PTR local_glGetPixelMapusv;
            if (local_glGetPixelMapusv == NULL) {
                local_glGetPixelMapusv = (glGetPixelMapusv_PTR)dlsym(g_libgl, "glGetPixelMapusv");
                if (! local_glGetPixelMapusv) {
                    printf("Warning: Unable to dlsym 'glGetPixelMapusv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLushort___GENPT__ *unpacked = (INDEXED_void_GLenum_GLushort___GENPT__ *)packed;
            ARGS_void_GLenum_GLushort___GENPT__ args = unpacked->args;
            local_glGetPixelMapusv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glGetPointerv
        case glGetPointerv_INDEX: {
            static glGetPointerv_PTR local_glGetPointerv;
            if (local_glGetPointerv == NULL) {
                local_glGetPointerv = (glGetPointerv_PTR)dlsym(g_libgl, "glGetPointerv");
                if (! local_glGetPointerv) {
                    printf("Warning: Unable to dlsym 'glGetPointerv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLvoid___GENPT____GENPT__ *unpacked = (INDEXED_void_GLenum_GLvoid___GENPT____GENPT__ *)packed;
            ARGS_void_GLenum_GLvoid___GENPT____GENPT__ args = unpacked->args;
            local_glGetPointerv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glGetPolygonStipple
        case glGetPolygonStipple_INDEX: {
            static glGetPolygonStipple_PTR local_glGetPolygonStipple;
            if (local_glGetPolygonStipple == NULL) {
                local_glGetPolygonStipple = (glGetPolygonStipple_PTR)dlsym(g_libgl, "glGetPolygonStipple");
                if (! local_glGetPolygonStipple) {
                    printf("Warning: Unable to dlsym 'glGetPolygonStipple'\n");
                    return;
                }
            }

            INDEXED_void_GLubyte___GENPT__ *unpacked = (INDEXED_void_GLubyte___GENPT__ *)packed;
            ARGS_void_GLubyte___GENPT__ args = unpacked->args;
            local_glGetPolygonStipple(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glGetQueryObjectiv
        case glGetQueryObjectiv_INDEX: {
            static glGetQueryObjectiv_PTR local_glGetQueryObjectiv;
            if (local_glGetQueryObjectiv == NULL) {
                local_glGetQueryObjectiv = (glGetQueryObjectiv_PTR)dlsym(g_libgl, "glGetQueryObjectiv");
                if (! local_glGetQueryObjectiv) {
                    printf("Warning: Unable to dlsym 'glGetQueryObjectiv'\n");
                    return;
                }
            }

            INDEXED_void_GLuint_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLuint_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLuint_GLenum_GLint___GENPT__ args = unpacked->args;
            local_glGetQueryObjectiv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetQueryObjectuiv
        case glGetQueryObjectuiv_INDEX: {
            static glGetQueryObjectuiv_PTR local_glGetQueryObjectuiv;
            if (local_glGetQueryObjectuiv == NULL) {
                local_glGetQueryObjectuiv = (glGetQueryObjectuiv_PTR)dlsym(g_libgl, "glGetQueryObjectuiv");
                if (! local_glGetQueryObjectuiv) {
                    printf("Warning: Unable to dlsym 'glGetQueryObjectuiv'\n");
                    return;
                }
            }

            INDEXED_void_GLuint_GLenum_GLuint___GENPT__ *unpacked = (INDEXED_void_GLuint_GLenum_GLuint___GENPT__ *)packed;
            ARGS_void_GLuint_GLenum_GLuint___GENPT__ args = unpacked->args;
            local_glGetQueryObjectuiv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetQueryiv
        case glGetQueryiv_INDEX: {
            static glGetQueryiv_PTR local_glGetQueryiv;
            if (local_glGetQueryiv == NULL) {
                local_glGetQueryiv = (glGetQueryiv_PTR)dlsym(g_libgl, "glGetQueryiv");
                if (! local_glGetQueryiv) {
                    printf("Warning: Unable to dlsym 'glGetQueryiv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            local_glGetQueryiv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetSeparableFilter
        case glGetSeparableFilter_INDEX: {
            static glGetSeparableFilter_PTR local_glGetSeparableFilter;
            if (local_glGetSeparableFilter == NULL) {
                local_glGetSeparableFilter = (glGetSeparableFilter_PTR)dlsym(g_libgl, "glGetSeparableFilter");
                if (! local_glGetSeparableFilter) {
                    printf("Warning: Unable to dlsym 'glGetSeparableFilter'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLenum_GLvoid___GENPT___GLvoid___GENPT___GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLenum_GLvoid___GENPT___GLvoid___GENPT___GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLvoid___GENPT___GLvoid___GENPT___GLvoid___GENPT__ args = unpacked->args;
            local_glGetSeparableFilter(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glGetString
        case glGetString_INDEX: {
            static glGetString_PTR local_glGetString;
            if (local_glGetString == NULL) {
                local_glGetString = (glGetString_PTR)dlsym(g_libgl, "glGetString");
                if (! local_glGetString) {
                    printf("Warning: Unable to dlsym 'glGetString'\n");
                    return;
                }
            }

            INDEXED_const_GLubyte___GENPT___GLenum *unpacked = (INDEXED_const_GLubyte___GENPT___GLenum *)packed;
            ARGS_const_GLubyte___GENPT___GLenum args = unpacked->args;
            const GLubyte * *ret = (const GLubyte * *)ret_v;
            *ret =
            local_glGetString(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glGetTexEnvfv
        case glGetTexEnvfv_INDEX: {
            static glGetTexEnvfv_PTR local_glGetTexEnvfv;
            if (local_glGetTexEnvfv == NULL) {
                local_glGetTexEnvfv = (glGetTexEnvfv_PTR)dlsym(g_libgl, "glGetTexEnvfv");
                if (! local_glGetTexEnvfv) {
                    printf("Warning: Unable to dlsym 'glGetTexEnvfv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            local_glGetTexEnvfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetTexEnviv
        case glGetTexEnviv_INDEX: {
            static glGetTexEnviv_PTR local_glGetTexEnviv;
            if (local_glGetTexEnviv == NULL) {
                local_glGetTexEnviv = (glGetTexEnviv_PTR)dlsym(g_libgl, "glGetTexEnviv");
                if (! local_glGetTexEnviv) {
                    printf("Warning: Unable to dlsym 'glGetTexEnviv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            local_glGetTexEnviv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetTexGendv
        case glGetTexGendv_INDEX: {
            static glGetTexGendv_PTR local_glGetTexGendv;
            if (local_glGetTexGendv == NULL) {
                local_glGetTexGendv = (glGetTexGendv_PTR)dlsym(g_libgl, "glGetTexGendv");
                if (! local_glGetTexGendv) {
                    printf("Warning: Unable to dlsym 'glGetTexGendv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLdouble___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLdouble___GENPT__ args = unpacked->args;
            local_glGetTexGendv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetTexGenfv
        case glGetTexGenfv_INDEX: {
            static glGetTexGenfv_PTR local_glGetTexGenfv;
            if (local_glGetTexGenfv == NULL) {
                local_glGetTexGenfv = (glGetTexGenfv_PTR)dlsym(g_libgl, "glGetTexGenfv");
                if (! local_glGetTexGenfv) {
                    printf("Warning: Unable to dlsym 'glGetTexGenfv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            local_glGetTexGenfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetTexGeniv
        case glGetTexGeniv_INDEX: {
            static glGetTexGeniv_PTR local_glGetTexGeniv;
            if (local_glGetTexGeniv == NULL) {
                local_glGetTexGeniv = (glGetTexGeniv_PTR)dlsym(g_libgl, "glGetTexGeniv");
                if (! local_glGetTexGeniv) {
                    printf("Warning: Unable to dlsym 'glGetTexGeniv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            local_glGetTexGeniv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetTexImage
        case glGetTexImage_INDEX: {
            static glGetTexImage_PTR local_glGetTexImage;
            if (local_glGetTexImage == NULL) {
                local_glGetTexImage = (glGetTexImage_PTR)dlsym(g_libgl, "glGetTexImage");
                if (! local_glGetTexImage) {
                    printf("Warning: Unable to dlsym 'glGetTexImage'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLenum_GLenum_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLenum_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLenum_GLvoid___GENPT__ args = unpacked->args;
            local_glGetTexImage(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glGetTexLevelParameterfv
        case glGetTexLevelParameterfv_INDEX: {
            static glGetTexLevelParameterfv_PTR local_glGetTexLevelParameterfv;
            if (local_glGetTexLevelParameterfv == NULL) {
                local_glGetTexLevelParameterfv = (glGetTexLevelParameterfv_PTR)dlsym(g_libgl, "glGetTexLevelParameterfv");
                if (! local_glGetTexLevelParameterfv) {
                    printf("Warning: Unable to dlsym 'glGetTexLevelParameterfv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLfloat___GENPT__ args = unpacked->args;
            local_glGetTexLevelParameterfv(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glGetTexLevelParameteriv
        case glGetTexLevelParameteriv_INDEX: {
            static glGetTexLevelParameteriv_PTR local_glGetTexLevelParameteriv;
            if (local_glGetTexLevelParameteriv == NULL) {
                local_glGetTexLevelParameteriv = (glGetTexLevelParameteriv_PTR)dlsym(g_libgl, "glGetTexLevelParameteriv");
                if (! local_glGetTexLevelParameteriv) {
                    printf("Warning: Unable to dlsym 'glGetTexLevelParameteriv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLint___GENPT__ args = unpacked->args;
            local_glGetTexLevelParameteriv(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glGetTexParameterfv
        case glGetTexParameterfv_INDEX: {
            static glGetTexParameterfv_PTR local_glGetTexParameterfv;
            if (local_glGetTexParameterfv == NULL) {
                local_glGetTexParameterfv = (glGetTexParameterfv_PTR)dlsym(g_libgl, "glGetTexParameterfv");
                if (! local_glGetTexParameterfv) {
                    printf("Warning: Unable to dlsym 'glGetTexParameterfv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            local_glGetTexParameterfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetTexParameteriv
        case glGetTexParameteriv_INDEX: {
            static glGetTexParameteriv_PTR local_glGetTexParameteriv;
            if (local_glGetTexParameteriv == NULL) {
                local_glGetTexParameteriv = (glGetTexParameteriv_PTR)dlsym(g_libgl, "glGetTexParameteriv");
                if (! local_glGetTexParameteriv) {
                    printf("Warning: Unable to dlsym 'glGetTexParameteriv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            local_glGetTexParameteriv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glHint
        case glHint_INDEX: {
            static glHint_PTR local_glHint;
            if (local_glHint == NULL) {
                local_glHint = (glHint_PTR)dlsym(g_libgl, "glHint");
                if (! local_glHint) {
                    printf("Warning: Unable to dlsym 'glHint'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum *unpacked = (INDEXED_void_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLenum args = unpacked->args;
            local_glHint(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glHistogram
        case glHistogram_INDEX: {
            static glHistogram_PTR local_glHistogram;
            if (local_glHistogram == NULL) {
                local_glHistogram = (glHistogram_PTR)dlsym(g_libgl, "glHistogram");
                if (! local_glHistogram) {
                    printf("Warning: Unable to dlsym 'glHistogram'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLsizei_GLenum_GLboolean *unpacked = (INDEXED_void_GLenum_GLsizei_GLenum_GLboolean *)packed;
            ARGS_void_GLenum_GLsizei_GLenum_GLboolean args = unpacked->args;
            local_glHistogram(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glIndexMask
        case glIndexMask_INDEX: {
            static glIndexMask_PTR local_glIndexMask;
            if (local_glIndexMask == NULL) {
                local_glIndexMask = (glIndexMask_PTR)dlsym(g_libgl, "glIndexMask");
                if (! local_glIndexMask) {
                    printf("Warning: Unable to dlsym 'glIndexMask'\n");
                    return;
                }
            }

            INDEXED_void_GLuint *unpacked = (INDEXED_void_GLuint *)packed;
            ARGS_void_GLuint args = unpacked->args;
            local_glIndexMask(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIndexPointer
        case glIndexPointer_INDEX: {
            static glIndexPointer_PTR local_glIndexPointer;
            if (local_glIndexPointer == NULL) {
                local_glIndexPointer = (glIndexPointer_PTR)dlsym(g_libgl, "glIndexPointer");
                if (! local_glIndexPointer) {
                    printf("Warning: Unable to dlsym 'glIndexPointer'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            local_glIndexPointer(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glIndexd
        case glIndexd_INDEX: {
            static glIndexd_PTR local_glIndexd;
            if (local_glIndexd == NULL) {
                local_glIndexd = (glIndexd_PTR)dlsym(g_libgl, "glIndexd");
                if (! local_glIndexd) {
                    printf("Warning: Unable to dlsym 'glIndexd'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble *unpacked = (INDEXED_void_GLdouble *)packed;
            ARGS_void_GLdouble args = unpacked->args;
            local_glIndexd(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIndexdv
        case glIndexdv_INDEX: {
            static glIndexdv_PTR local_glIndexdv;
            if (local_glIndexdv == NULL) {
                local_glIndexdv = (glIndexdv_PTR)dlsym(g_libgl, "glIndexdv");
                if (! local_glIndexdv) {
                    printf("Warning: Unable to dlsym 'glIndexdv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            local_glIndexdv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIndexf
        case glIndexf_INDEX: {
            static glIndexf_PTR local_glIndexf;
            if (local_glIndexf == NULL) {
                local_glIndexf = (glIndexf_PTR)dlsym(g_libgl, "glIndexf");
                if (! local_glIndexf) {
                    printf("Warning: Unable to dlsym 'glIndexf'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat *unpacked = (INDEXED_void_GLfloat *)packed;
            ARGS_void_GLfloat args = unpacked->args;
            local_glIndexf(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIndexfv
        case glIndexfv_INDEX: {
            static glIndexfv_PTR local_glIndexfv;
            if (local_glIndexfv == NULL) {
                local_glIndexfv = (glIndexfv_PTR)dlsym(g_libgl, "glIndexfv");
                if (! local_glIndexfv) {
                    printf("Warning: Unable to dlsym 'glIndexfv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            local_glIndexfv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIndexi
        case glIndexi_INDEX: {
            static glIndexi_PTR local_glIndexi;
            if (local_glIndexi == NULL) {
                local_glIndexi = (glIndexi_PTR)dlsym(g_libgl, "glIndexi");
                if (! local_glIndexi) {
                    printf("Warning: Unable to dlsym 'glIndexi'\n");
                    return;
                }
            }

            INDEXED_void_GLint *unpacked = (INDEXED_void_GLint *)packed;
            ARGS_void_GLint args = unpacked->args;
            local_glIndexi(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIndexiv
        case glIndexiv_INDEX: {
            static glIndexiv_PTR local_glIndexiv;
            if (local_glIndexiv == NULL) {
                local_glIndexiv = (glIndexiv_PTR)dlsym(g_libgl, "glIndexiv");
                if (! local_glIndexiv) {
                    printf("Warning: Unable to dlsym 'glIndexiv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            local_glIndexiv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIndexs
        case glIndexs_INDEX: {
            static glIndexs_PTR local_glIndexs;
            if (local_glIndexs == NULL) {
                local_glIndexs = (glIndexs_PTR)dlsym(g_libgl, "glIndexs");
                if (! local_glIndexs) {
                    printf("Warning: Unable to dlsym 'glIndexs'\n");
                    return;
                }
            }

            INDEXED_void_GLshort *unpacked = (INDEXED_void_GLshort *)packed;
            ARGS_void_GLshort args = unpacked->args;
            local_glIndexs(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIndexsv
        case glIndexsv_INDEX: {
            static glIndexsv_PTR local_glIndexsv;
            if (local_glIndexsv == NULL) {
                local_glIndexsv = (glIndexsv_PTR)dlsym(g_libgl, "glIndexsv");
                if (! local_glIndexsv) {
                    printf("Warning: Unable to dlsym 'glIndexsv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            local_glIndexsv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIndexub
        case glIndexub_INDEX: {
            static glIndexub_PTR local_glIndexub;
            if (local_glIndexub == NULL) {
                local_glIndexub = (glIndexub_PTR)dlsym(g_libgl, "glIndexub");
                if (! local_glIndexub) {
                    printf("Warning: Unable to dlsym 'glIndexub'\n");
                    return;
                }
            }

            INDEXED_void_GLubyte *unpacked = (INDEXED_void_GLubyte *)packed;
            ARGS_void_GLubyte args = unpacked->args;
            local_glIndexub(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIndexubv
        case glIndexubv_INDEX: {
            static glIndexubv_PTR local_glIndexubv;
            if (local_glIndexubv == NULL) {
                local_glIndexubv = (glIndexubv_PTR)dlsym(g_libgl, "glIndexubv");
                if (! local_glIndexubv) {
                    printf("Warning: Unable to dlsym 'glIndexubv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLubyte___GENPT__ *unpacked = (INDEXED_void_const_GLubyte___GENPT__ *)packed;
            ARGS_void_const_GLubyte___GENPT__ args = unpacked->args;
            local_glIndexubv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glInitNames
        case glInitNames_INDEX: {
            static glInitNames_PTR local_glInitNames;
            if (local_glInitNames == NULL) {
                local_glInitNames = (glInitNames_PTR)dlsym(g_libgl, "glInitNames");
                if (! local_glInitNames) {
                    printf("Warning: Unable to dlsym 'glInitNames'\n");
                    return;
                }
            }

            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            local_glInitNames();
            break;
        }
        #endif
        #ifndef skip_index_glInterleavedArrays
        case glInterleavedArrays_INDEX: {
            static glInterleavedArrays_PTR local_glInterleavedArrays;
            if (local_glInterleavedArrays == NULL) {
                local_glInterleavedArrays = (glInterleavedArrays_PTR)dlsym(g_libgl, "glInterleavedArrays");
                if (! local_glInterleavedArrays) {
                    printf("Warning: Unable to dlsym 'glInterleavedArrays'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            local_glInterleavedArrays(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glIsBuffer
        case glIsBuffer_INDEX: {
            static glIsBuffer_PTR local_glIsBuffer;
            if (local_glIsBuffer == NULL) {
                local_glIsBuffer = (glIsBuffer_PTR)dlsym(g_libgl, "glIsBuffer");
                if (! local_glIsBuffer) {
                    printf("Warning: Unable to dlsym 'glIsBuffer'\n");
                    return;
                }
            }

            INDEXED_GLboolean_GLuint *unpacked = (INDEXED_GLboolean_GLuint *)packed;
            ARGS_GLboolean_GLuint args = unpacked->args;
            GLboolean *ret = (GLboolean *)ret_v;
            *ret =
            local_glIsBuffer(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIsEnabled
        case glIsEnabled_INDEX: {
            static glIsEnabled_PTR local_glIsEnabled;
            if (local_glIsEnabled == NULL) {
                local_glIsEnabled = (glIsEnabled_PTR)dlsym(g_libgl, "glIsEnabled");
                if (! local_glIsEnabled) {
                    printf("Warning: Unable to dlsym 'glIsEnabled'\n");
                    return;
                }
            }

            INDEXED_GLboolean_GLenum *unpacked = (INDEXED_GLboolean_GLenum *)packed;
            ARGS_GLboolean_GLenum args = unpacked->args;
            GLboolean *ret = (GLboolean *)ret_v;
            *ret =
            local_glIsEnabled(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIsList
        case glIsList_INDEX: {
            static glIsList_PTR local_glIsList;
            if (local_glIsList == NULL) {
                local_glIsList = (glIsList_PTR)dlsym(g_libgl, "glIsList");
                if (! local_glIsList) {
                    printf("Warning: Unable to dlsym 'glIsList'\n");
                    return;
                }
            }

            INDEXED_GLboolean_GLuint *unpacked = (INDEXED_GLboolean_GLuint *)packed;
            ARGS_GLboolean_GLuint args = unpacked->args;
            GLboolean *ret = (GLboolean *)ret_v;
            *ret =
            local_glIsList(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIsQuery
        case glIsQuery_INDEX: {
            static glIsQuery_PTR local_glIsQuery;
            if (local_glIsQuery == NULL) {
                local_glIsQuery = (glIsQuery_PTR)dlsym(g_libgl, "glIsQuery");
                if (! local_glIsQuery) {
                    printf("Warning: Unable to dlsym 'glIsQuery'\n");
                    return;
                }
            }

            INDEXED_GLboolean_GLuint *unpacked = (INDEXED_GLboolean_GLuint *)packed;
            ARGS_GLboolean_GLuint args = unpacked->args;
            GLboolean *ret = (GLboolean *)ret_v;
            *ret =
            local_glIsQuery(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIsTexture
        case glIsTexture_INDEX: {
            static glIsTexture_PTR local_glIsTexture;
            if (local_glIsTexture == NULL) {
                local_glIsTexture = (glIsTexture_PTR)dlsym(g_libgl, "glIsTexture");
                if (! local_glIsTexture) {
                    printf("Warning: Unable to dlsym 'glIsTexture'\n");
                    return;
                }
            }

            INDEXED_GLboolean_GLuint *unpacked = (INDEXED_GLboolean_GLuint *)packed;
            ARGS_GLboolean_GLuint args = unpacked->args;
            GLboolean *ret = (GLboolean *)ret_v;
            *ret =
            local_glIsTexture(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glLightModelf
        case glLightModelf_INDEX: {
            static glLightModelf_PTR local_glLightModelf;
            if (local_glLightModelf == NULL) {
                local_glLightModelf = (glLightModelf_PTR)dlsym(g_libgl, "glLightModelf");
                if (! local_glLightModelf) {
                    printf("Warning: Unable to dlsym 'glLightModelf'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat args = unpacked->args;
            local_glLightModelf(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glLightModelfv
        case glLightModelfv_INDEX: {
            static glLightModelfv_PTR local_glLightModelfv;
            if (local_glLightModelfv == NULL) {
                local_glLightModelfv = (glLightModelfv_PTR)dlsym(g_libgl, "glLightModelfv");
                if (! local_glLightModelfv) {
                    printf("Warning: Unable to dlsym 'glLightModelfv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            local_glLightModelfv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glLightModeli
        case glLightModeli_INDEX: {
            static glLightModeli_PTR local_glLightModeli;
            if (local_glLightModeli == NULL) {
                local_glLightModeli = (glLightModeli_PTR)dlsym(g_libgl, "glLightModeli");
                if (! local_glLightModeli) {
                    printf("Warning: Unable to dlsym 'glLightModeli'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint *unpacked = (INDEXED_void_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLint args = unpacked->args;
            local_glLightModeli(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glLightModeliv
        case glLightModeliv_INDEX: {
            static glLightModeliv_PTR local_glLightModeliv;
            if (local_glLightModeliv == NULL) {
                local_glLightModeliv = (glLightModeliv_PTR)dlsym(g_libgl, "glLightModeliv");
                if (! local_glLightModeliv) {
                    printf("Warning: Unable to dlsym 'glLightModeliv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLint___GENPT__ args = unpacked->args;
            local_glLightModeliv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glLightf
        case glLightf_INDEX: {
            static glLightf_PTR local_glLightf;
            if (local_glLightf == NULL) {
                local_glLightf = (glLightf_PTR)dlsym(g_libgl, "glLightf");
                if (! local_glLightf) {
                    printf("Warning: Unable to dlsym 'glLightf'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLenum_GLfloat args = unpacked->args;
            local_glLightf(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glLightfv
        case glLightfv_INDEX: {
            static glLightfv_PTR local_glLightfv;
            if (local_glLightfv == NULL) {
                local_glLightfv = (glLightfv_PTR)dlsym(g_libgl, "glLightfv");
                if (! local_glLightfv) {
                    printf("Warning: Unable to dlsym 'glLightfv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            local_glLightfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glLighti
        case glLighti_INDEX: {
            static glLighti_PTR local_glLighti;
            if (local_glLighti == NULL) {
                local_glLighti = (glLighti_PTR)dlsym(g_libgl, "glLighti");
                if (! local_glLighti) {
                    printf("Warning: Unable to dlsym 'glLighti'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLint *unpacked = (INDEXED_void_GLenum_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLint args = unpacked->args;
            local_glLighti(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glLightiv
        case glLightiv_INDEX: {
            static glLightiv_PTR local_glLightiv;
            if (local_glLightiv == NULL) {
                local_glLightiv = (glLightiv_PTR)dlsym(g_libgl, "glLightiv");
                if (! local_glLightiv) {
                    printf("Warning: Unable to dlsym 'glLightiv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLint___GENPT__ args = unpacked->args;
            local_glLightiv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glLineStipple
        case glLineStipple_INDEX: {
            static glLineStipple_PTR local_glLineStipple;
            if (local_glLineStipple == NULL) {
                local_glLineStipple = (glLineStipple_PTR)dlsym(g_libgl, "glLineStipple");
                if (! local_glLineStipple) {
                    printf("Warning: Unable to dlsym 'glLineStipple'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLushort *unpacked = (INDEXED_void_GLint_GLushort *)packed;
            ARGS_void_GLint_GLushort args = unpacked->args;
            local_glLineStipple(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glLineWidth
        case glLineWidth_INDEX: {
            static glLineWidth_PTR local_glLineWidth;
            if (local_glLineWidth == NULL) {
                local_glLineWidth = (glLineWidth_PTR)dlsym(g_libgl, "glLineWidth");
                if (! local_glLineWidth) {
                    printf("Warning: Unable to dlsym 'glLineWidth'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat *unpacked = (INDEXED_void_GLfloat *)packed;
            ARGS_void_GLfloat args = unpacked->args;
            local_glLineWidth(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glListBase
        case glListBase_INDEX: {
            static glListBase_PTR local_glListBase;
            if (local_glListBase == NULL) {
                local_glListBase = (glListBase_PTR)dlsym(g_libgl, "glListBase");
                if (! local_glListBase) {
                    printf("Warning: Unable to dlsym 'glListBase'\n");
                    return;
                }
            }

            INDEXED_void_GLuint *unpacked = (INDEXED_void_GLuint *)packed;
            ARGS_void_GLuint args = unpacked->args;
            local_glListBase(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glLoadIdentity
        case glLoadIdentity_INDEX: {
            static glLoadIdentity_PTR local_glLoadIdentity;
            if (local_glLoadIdentity == NULL) {
                local_glLoadIdentity = (glLoadIdentity_PTR)dlsym(g_libgl, "glLoadIdentity");
                if (! local_glLoadIdentity) {
                    printf("Warning: Unable to dlsym 'glLoadIdentity'\n");
                    return;
                }
            }

            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            local_glLoadIdentity();
            break;
        }
        #endif
        #ifndef skip_index_glLoadMatrixd
        case glLoadMatrixd_INDEX: {
            static glLoadMatrixd_PTR local_glLoadMatrixd;
            if (local_glLoadMatrixd == NULL) {
                local_glLoadMatrixd = (glLoadMatrixd_PTR)dlsym(g_libgl, "glLoadMatrixd");
                if (! local_glLoadMatrixd) {
                    printf("Warning: Unable to dlsym 'glLoadMatrixd'\n");
                    return;
                }
            }

            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            local_glLoadMatrixd(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glLoadMatrixf
        case glLoadMatrixf_INDEX: {
            static glLoadMatrixf_PTR local_glLoadMatrixf;
            if (local_glLoadMatrixf == NULL) {
                local_glLoadMatrixf = (glLoadMatrixf_PTR)dlsym(g_libgl, "glLoadMatrixf");
                if (! local_glLoadMatrixf) {
                    printf("Warning: Unable to dlsym 'glLoadMatrixf'\n");
                    return;
                }
            }

            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            local_glLoadMatrixf(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glLoadName
        case glLoadName_INDEX: {
            static glLoadName_PTR local_glLoadName;
            if (local_glLoadName == NULL) {
                local_glLoadName = (glLoadName_PTR)dlsym(g_libgl, "glLoadName");
                if (! local_glLoadName) {
                    printf("Warning: Unable to dlsym 'glLoadName'\n");
                    return;
                }
            }

            INDEXED_void_GLuint *unpacked = (INDEXED_void_GLuint *)packed;
            ARGS_void_GLuint args = unpacked->args;
            local_glLoadName(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glLoadTransposeMatrixd
        case glLoadTransposeMatrixd_INDEX: {
            static glLoadTransposeMatrixd_PTR local_glLoadTransposeMatrixd;
            if (local_glLoadTransposeMatrixd == NULL) {
                local_glLoadTransposeMatrixd = (glLoadTransposeMatrixd_PTR)dlsym(g_libgl, "glLoadTransposeMatrixd");
                if (! local_glLoadTransposeMatrixd) {
                    printf("Warning: Unable to dlsym 'glLoadTransposeMatrixd'\n");
                    return;
                }
            }

            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            local_glLoadTransposeMatrixd(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glLoadTransposeMatrixf
        case glLoadTransposeMatrixf_INDEX: {
            static glLoadTransposeMatrixf_PTR local_glLoadTransposeMatrixf;
            if (local_glLoadTransposeMatrixf == NULL) {
                local_glLoadTransposeMatrixf = (glLoadTransposeMatrixf_PTR)dlsym(g_libgl, "glLoadTransposeMatrixf");
                if (! local_glLoadTransposeMatrixf) {
                    printf("Warning: Unable to dlsym 'glLoadTransposeMatrixf'\n");
                    return;
                }
            }

            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            local_glLoadTransposeMatrixf(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glLogicOp
        case glLogicOp_INDEX: {
            static glLogicOp_PTR local_glLogicOp;
            if (local_glLogicOp == NULL) {
                local_glLogicOp = (glLogicOp_PTR)dlsym(g_libgl, "glLogicOp");
                if (! local_glLogicOp) {
                    printf("Warning: Unable to dlsym 'glLogicOp'\n");
                    return;
                }
            }

            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            local_glLogicOp(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glMap1d
        case glMap1d_INDEX: {
            static glMap1d_PTR local_glMap1d;
            if (local_glMap1d == NULL) {
                local_glMap1d = (glMap1d_PTR)dlsym(g_libgl, "glMap1d");
                if (! local_glMap1d) {
                    printf("Warning: Unable to dlsym 'glMap1d'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ args = unpacked->args;
            local_glMap1d(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glMap1f
        case glMap1f_INDEX: {
            static glMap1f_PTR local_glMap1f;
            if (local_glMap1f == NULL) {
                local_glMap1f = (glMap1f_PTR)dlsym(g_libgl, "glMap1f");
                if (! local_glMap1f) {
                    printf("Warning: Unable to dlsym 'glMap1f'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ args = unpacked->args;
            local_glMap1f(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glMap2d
        case glMap2d_INDEX: {
            static glMap2d_PTR local_glMap2d;
            if (local_glMap2d == NULL) {
                local_glMap2d = (glMap2d_PTR)dlsym(g_libgl, "glMap2d");
                if (! local_glMap2d) {
                    printf("Warning: Unable to dlsym 'glMap2d'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ args = unpacked->args;
            local_glMap2d(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        #endif
        #ifndef skip_index_glMap2f
        case glMap2f_INDEX: {
            static glMap2f_PTR local_glMap2f;
            if (local_glMap2f == NULL) {
                local_glMap2f = (glMap2f_PTR)dlsym(g_libgl, "glMap2f");
                if (! local_glMap2f) {
                    printf("Warning: Unable to dlsym 'glMap2f'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ args = unpacked->args;
            local_glMap2f(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        #endif
        #ifndef skip_index_glMapBuffer
        case glMapBuffer_INDEX: {
            static glMapBuffer_PTR local_glMapBuffer;
            if (local_glMapBuffer == NULL) {
                local_glMapBuffer = (glMapBuffer_PTR)dlsym(g_libgl, "glMapBuffer");
                if (! local_glMapBuffer) {
                    printf("Warning: Unable to dlsym 'glMapBuffer'\n");
                    return;
                }
            }

            INDEXED_GLvoid___GENPT___GLenum_GLenum *unpacked = (INDEXED_GLvoid___GENPT___GLenum_GLenum *)packed;
            ARGS_GLvoid___GENPT___GLenum_GLenum args = unpacked->args;
            GLvoid * *ret = (GLvoid * *)ret_v;
            *ret =
            local_glMapBuffer(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMapGrid1d
        case glMapGrid1d_INDEX: {
            static glMapGrid1d_PTR local_glMapGrid1d;
            if (local_glMapGrid1d == NULL) {
                local_glMapGrid1d = (glMapGrid1d_PTR)dlsym(g_libgl, "glMapGrid1d");
                if (! local_glMapGrid1d) {
                    printf("Warning: Unable to dlsym 'glMapGrid1d'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLdouble_GLdouble *unpacked = (INDEXED_void_GLint_GLdouble_GLdouble *)packed;
            ARGS_void_GLint_GLdouble_GLdouble args = unpacked->args;
            local_glMapGrid1d(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glMapGrid1f
        case glMapGrid1f_INDEX: {
            static glMapGrid1f_PTR local_glMapGrid1f;
            if (local_glMapGrid1f == NULL) {
                local_glMapGrid1f = (glMapGrid1f_PTR)dlsym(g_libgl, "glMapGrid1f");
                if (! local_glMapGrid1f) {
                    printf("Warning: Unable to dlsym 'glMapGrid1f'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLfloat_GLfloat *unpacked = (INDEXED_void_GLint_GLfloat_GLfloat *)packed;
            ARGS_void_GLint_GLfloat_GLfloat args = unpacked->args;
            local_glMapGrid1f(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glMapGrid2d
        case glMapGrid2d_INDEX: {
            static glMapGrid2d_PTR local_glMapGrid2d;
            if (local_glMapGrid2d == NULL) {
                local_glMapGrid2d = (glMapGrid2d_PTR)dlsym(g_libgl, "glMapGrid2d");
                if (! local_glMapGrid2d) {
                    printf("Warning: Unable to dlsym 'glMapGrid2d'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble *unpacked = (INDEXED_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble *)packed;
            ARGS_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble args = unpacked->args;
            local_glMapGrid2d(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glMapGrid2f
        case glMapGrid2f_INDEX: {
            static glMapGrid2f_PTR local_glMapGrid2f;
            if (local_glMapGrid2f == NULL) {
                local_glMapGrid2f = (glMapGrid2f_PTR)dlsym(g_libgl, "glMapGrid2f");
                if (! local_glMapGrid2f) {
                    printf("Warning: Unable to dlsym 'glMapGrid2f'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLfloat_GLfloat_GLint_GLfloat_GLfloat *unpacked = (INDEXED_void_GLint_GLfloat_GLfloat_GLint_GLfloat_GLfloat *)packed;
            ARGS_void_GLint_GLfloat_GLfloat_GLint_GLfloat_GLfloat args = unpacked->args;
            local_glMapGrid2f(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glMaterialf
        case glMaterialf_INDEX: {
            static glMaterialf_PTR local_glMaterialf;
            if (local_glMaterialf == NULL) {
                local_glMaterialf = (glMaterialf_PTR)dlsym(g_libgl, "glMaterialf");
                if (! local_glMaterialf) {
                    printf("Warning: Unable to dlsym 'glMaterialf'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLenum_GLfloat args = unpacked->args;
            local_glMaterialf(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glMaterialfv
        case glMaterialfv_INDEX: {
            static glMaterialfv_PTR local_glMaterialfv;
            if (local_glMaterialfv == NULL) {
                local_glMaterialfv = (glMaterialfv_PTR)dlsym(g_libgl, "glMaterialfv");
                if (! local_glMaterialfv) {
                    printf("Warning: Unable to dlsym 'glMaterialfv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            local_glMaterialfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glMateriali
        case glMateriali_INDEX: {
            static glMateriali_PTR local_glMateriali;
            if (local_glMateriali == NULL) {
                local_glMateriali = (glMateriali_PTR)dlsym(g_libgl, "glMateriali");
                if (! local_glMateriali) {
                    printf("Warning: Unable to dlsym 'glMateriali'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLint *unpacked = (INDEXED_void_GLenum_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLint args = unpacked->args;
            local_glMateriali(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glMaterialiv
        case glMaterialiv_INDEX: {
            static glMaterialiv_PTR local_glMaterialiv;
            if (local_glMaterialiv == NULL) {
                local_glMaterialiv = (glMaterialiv_PTR)dlsym(g_libgl, "glMaterialiv");
                if (! local_glMaterialiv) {
                    printf("Warning: Unable to dlsym 'glMaterialiv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLint___GENPT__ args = unpacked->args;
            local_glMaterialiv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glMatrixMode
        case glMatrixMode_INDEX: {
            static glMatrixMode_PTR local_glMatrixMode;
            if (local_glMatrixMode == NULL) {
                local_glMatrixMode = (glMatrixMode_PTR)dlsym(g_libgl, "glMatrixMode");
                if (! local_glMatrixMode) {
                    printf("Warning: Unable to dlsym 'glMatrixMode'\n");
                    return;
                }
            }

            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            local_glMatrixMode(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glMinmax
        case glMinmax_INDEX: {
            static glMinmax_PTR local_glMinmax;
            if (local_glMinmax == NULL) {
                local_glMinmax = (glMinmax_PTR)dlsym(g_libgl, "glMinmax");
                if (! local_glMinmax) {
                    printf("Warning: Unable to dlsym 'glMinmax'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLboolean *unpacked = (INDEXED_void_GLenum_GLenum_GLboolean *)packed;
            ARGS_void_GLenum_GLenum_GLboolean args = unpacked->args;
            local_glMinmax(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glMultMatrixd
        case glMultMatrixd_INDEX: {
            static glMultMatrixd_PTR local_glMultMatrixd;
            if (local_glMultMatrixd == NULL) {
                local_glMultMatrixd = (glMultMatrixd_PTR)dlsym(g_libgl, "glMultMatrixd");
                if (! local_glMultMatrixd) {
                    printf("Warning: Unable to dlsym 'glMultMatrixd'\n");
                    return;
                }
            }

            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            local_glMultMatrixd(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glMultMatrixf
        case glMultMatrixf_INDEX: {
            static glMultMatrixf_PTR local_glMultMatrixf;
            if (local_glMultMatrixf == NULL) {
                local_glMultMatrixf = (glMultMatrixf_PTR)dlsym(g_libgl, "glMultMatrixf");
                if (! local_glMultMatrixf) {
                    printf("Warning: Unable to dlsym 'glMultMatrixf'\n");
                    return;
                }
            }

            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            local_glMultMatrixf(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glMultTransposeMatrixd
        case glMultTransposeMatrixd_INDEX: {
            static glMultTransposeMatrixd_PTR local_glMultTransposeMatrixd;
            if (local_glMultTransposeMatrixd == NULL) {
                local_glMultTransposeMatrixd = (glMultTransposeMatrixd_PTR)dlsym(g_libgl, "glMultTransposeMatrixd");
                if (! local_glMultTransposeMatrixd) {
                    printf("Warning: Unable to dlsym 'glMultTransposeMatrixd'\n");
                    return;
                }
            }

            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            local_glMultTransposeMatrixd(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glMultTransposeMatrixf
        case glMultTransposeMatrixf_INDEX: {
            static glMultTransposeMatrixf_PTR local_glMultTransposeMatrixf;
            if (local_glMultTransposeMatrixf == NULL) {
                local_glMultTransposeMatrixf = (glMultTransposeMatrixf_PTR)dlsym(g_libgl, "glMultTransposeMatrixf");
                if (! local_glMultTransposeMatrixf) {
                    printf("Warning: Unable to dlsym 'glMultTransposeMatrixf'\n");
                    return;
                }
            }

            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            local_glMultTransposeMatrixf(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glMultiDrawArrays
        case glMultiDrawArrays_INDEX: {
            static glMultiDrawArrays_PTR local_glMultiDrawArrays;
            if (local_glMultiDrawArrays == NULL) {
                local_glMultiDrawArrays = (glMultiDrawArrays_PTR)dlsym(g_libgl, "glMultiDrawArrays");
                if (! local_glMultiDrawArrays) {
                    printf("Warning: Unable to dlsym 'glMultiDrawArrays'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei *unpacked = (INDEXED_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei *)packed;
            ARGS_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei args = unpacked->args;
            local_glMultiDrawArrays(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glMultiDrawElements
        case glMultiDrawElements_INDEX: {
            static glMultiDrawElements_PTR local_glMultiDrawElements;
            if (local_glMultiDrawElements == NULL) {
                local_glMultiDrawElements = (glMultiDrawElements_PTR)dlsym(g_libgl, "glMultiDrawElements");
                if (! local_glMultiDrawElements) {
                    printf("Warning: Unable to dlsym 'glMultiDrawElements'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_const_GLsizei___GENPT___GLenum_GLvoid__GENPT__const___GENPT___GLsizei *unpacked = (INDEXED_void_GLenum_const_GLsizei___GENPT___GLenum_GLvoid__GENPT__const___GENPT___GLsizei *)packed;
            ARGS_void_GLenum_const_GLsizei___GENPT___GLenum_GLvoid__GENPT__const___GENPT___GLsizei args = unpacked->args;
            local_glMultiDrawElements(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord1d
        case glMultiTexCoord1d_INDEX: {
            static glMultiTexCoord1d_PTR local_glMultiTexCoord1d;
            if (local_glMultiTexCoord1d == NULL) {
                local_glMultiTexCoord1d = (glMultiTexCoord1d_PTR)dlsym(g_libgl, "glMultiTexCoord1d");
                if (! local_glMultiTexCoord1d) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord1d'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLdouble *unpacked = (INDEXED_void_GLenum_GLdouble *)packed;
            ARGS_void_GLenum_GLdouble args = unpacked->args;
            local_glMultiTexCoord1d(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord1dv
        case glMultiTexCoord1dv_INDEX: {
            static glMultiTexCoord1dv_PTR local_glMultiTexCoord1dv;
            if (local_glMultiTexCoord1dv == NULL) {
                local_glMultiTexCoord1dv = (glMultiTexCoord1dv_PTR)dlsym(g_libgl, "glMultiTexCoord1dv");
                if (! local_glMultiTexCoord1dv) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord1dv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLdouble___GENPT__ args = unpacked->args;
            local_glMultiTexCoord1dv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord1f
        case glMultiTexCoord1f_INDEX: {
            static glMultiTexCoord1f_PTR local_glMultiTexCoord1f;
            if (local_glMultiTexCoord1f == NULL) {
                local_glMultiTexCoord1f = (glMultiTexCoord1f_PTR)dlsym(g_libgl, "glMultiTexCoord1f");
                if (! local_glMultiTexCoord1f) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord1f'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat args = unpacked->args;
            local_glMultiTexCoord1f(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord1fv
        case glMultiTexCoord1fv_INDEX: {
            static glMultiTexCoord1fv_PTR local_glMultiTexCoord1fv;
            if (local_glMultiTexCoord1fv == NULL) {
                local_glMultiTexCoord1fv = (glMultiTexCoord1fv_PTR)dlsym(g_libgl, "glMultiTexCoord1fv");
                if (! local_glMultiTexCoord1fv) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord1fv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            local_glMultiTexCoord1fv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord1i
        case glMultiTexCoord1i_INDEX: {
            static glMultiTexCoord1i_PTR local_glMultiTexCoord1i;
            if (local_glMultiTexCoord1i == NULL) {
                local_glMultiTexCoord1i = (glMultiTexCoord1i_PTR)dlsym(g_libgl, "glMultiTexCoord1i");
                if (! local_glMultiTexCoord1i) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord1i'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint *unpacked = (INDEXED_void_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLint args = unpacked->args;
            local_glMultiTexCoord1i(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord1iv
        case glMultiTexCoord1iv_INDEX: {
            static glMultiTexCoord1iv_PTR local_glMultiTexCoord1iv;
            if (local_glMultiTexCoord1iv == NULL) {
                local_glMultiTexCoord1iv = (glMultiTexCoord1iv_PTR)dlsym(g_libgl, "glMultiTexCoord1iv");
                if (! local_glMultiTexCoord1iv) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord1iv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLint___GENPT__ args = unpacked->args;
            local_glMultiTexCoord1iv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord1s
        case glMultiTexCoord1s_INDEX: {
            static glMultiTexCoord1s_PTR local_glMultiTexCoord1s;
            if (local_glMultiTexCoord1s == NULL) {
                local_glMultiTexCoord1s = (glMultiTexCoord1s_PTR)dlsym(g_libgl, "glMultiTexCoord1s");
                if (! local_glMultiTexCoord1s) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord1s'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLshort *unpacked = (INDEXED_void_GLenum_GLshort *)packed;
            ARGS_void_GLenum_GLshort args = unpacked->args;
            local_glMultiTexCoord1s(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord1sv
        case glMultiTexCoord1sv_INDEX: {
            static glMultiTexCoord1sv_PTR local_glMultiTexCoord1sv;
            if (local_glMultiTexCoord1sv == NULL) {
                local_glMultiTexCoord1sv = (glMultiTexCoord1sv_PTR)dlsym(g_libgl, "glMultiTexCoord1sv");
                if (! local_glMultiTexCoord1sv) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord1sv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_const_GLshort___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLshort___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLshort___GENPT__ args = unpacked->args;
            local_glMultiTexCoord1sv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord2d
        case glMultiTexCoord2d_INDEX: {
            static glMultiTexCoord2d_PTR local_glMultiTexCoord2d;
            if (local_glMultiTexCoord2d == NULL) {
                local_glMultiTexCoord2d = (glMultiTexCoord2d_PTR)dlsym(g_libgl, "glMultiTexCoord2d");
                if (! local_glMultiTexCoord2d) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord2d'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLdouble_GLdouble *unpacked = (INDEXED_void_GLenum_GLdouble_GLdouble *)packed;
            ARGS_void_GLenum_GLdouble_GLdouble args = unpacked->args;
            local_glMultiTexCoord2d(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord2dv
        case glMultiTexCoord2dv_INDEX: {
            static glMultiTexCoord2dv_PTR local_glMultiTexCoord2dv;
            if (local_glMultiTexCoord2dv == NULL) {
                local_glMultiTexCoord2dv = (glMultiTexCoord2dv_PTR)dlsym(g_libgl, "glMultiTexCoord2dv");
                if (! local_glMultiTexCoord2dv) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord2dv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLdouble___GENPT__ args = unpacked->args;
            local_glMultiTexCoord2dv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord2f
        case glMultiTexCoord2f_INDEX: {
            static glMultiTexCoord2f_PTR local_glMultiTexCoord2f;
            if (local_glMultiTexCoord2f == NULL) {
                local_glMultiTexCoord2f = (glMultiTexCoord2f_PTR)dlsym(g_libgl, "glMultiTexCoord2f");
                if (! local_glMultiTexCoord2f) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord2f'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLfloat_GLfloat *unpacked = (INDEXED_void_GLenum_GLfloat_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat_GLfloat args = unpacked->args;
            local_glMultiTexCoord2f(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord2fv
        case glMultiTexCoord2fv_INDEX: {
            static glMultiTexCoord2fv_PTR local_glMultiTexCoord2fv;
            if (local_glMultiTexCoord2fv == NULL) {
                local_glMultiTexCoord2fv = (glMultiTexCoord2fv_PTR)dlsym(g_libgl, "glMultiTexCoord2fv");
                if (! local_glMultiTexCoord2fv) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord2fv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            local_glMultiTexCoord2fv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord2i
        case glMultiTexCoord2i_INDEX: {
            static glMultiTexCoord2i_PTR local_glMultiTexCoord2i;
            if (local_glMultiTexCoord2i == NULL) {
                local_glMultiTexCoord2i = (glMultiTexCoord2i_PTR)dlsym(g_libgl, "glMultiTexCoord2i");
                if (! local_glMultiTexCoord2i) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord2i'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLint *unpacked = (INDEXED_void_GLenum_GLint_GLint *)packed;
            ARGS_void_GLenum_GLint_GLint args = unpacked->args;
            local_glMultiTexCoord2i(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord2iv
        case glMultiTexCoord2iv_INDEX: {
            static glMultiTexCoord2iv_PTR local_glMultiTexCoord2iv;
            if (local_glMultiTexCoord2iv == NULL) {
                local_glMultiTexCoord2iv = (glMultiTexCoord2iv_PTR)dlsym(g_libgl, "glMultiTexCoord2iv");
                if (! local_glMultiTexCoord2iv) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord2iv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLint___GENPT__ args = unpacked->args;
            local_glMultiTexCoord2iv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord2s
        case glMultiTexCoord2s_INDEX: {
            static glMultiTexCoord2s_PTR local_glMultiTexCoord2s;
            if (local_glMultiTexCoord2s == NULL) {
                local_glMultiTexCoord2s = (glMultiTexCoord2s_PTR)dlsym(g_libgl, "glMultiTexCoord2s");
                if (! local_glMultiTexCoord2s) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord2s'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLshort_GLshort *unpacked = (INDEXED_void_GLenum_GLshort_GLshort *)packed;
            ARGS_void_GLenum_GLshort_GLshort args = unpacked->args;
            local_glMultiTexCoord2s(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord2sv
        case glMultiTexCoord2sv_INDEX: {
            static glMultiTexCoord2sv_PTR local_glMultiTexCoord2sv;
            if (local_glMultiTexCoord2sv == NULL) {
                local_glMultiTexCoord2sv = (glMultiTexCoord2sv_PTR)dlsym(g_libgl, "glMultiTexCoord2sv");
                if (! local_glMultiTexCoord2sv) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord2sv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_const_GLshort___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLshort___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLshort___GENPT__ args = unpacked->args;
            local_glMultiTexCoord2sv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord3d
        case glMultiTexCoord3d_INDEX: {
            static glMultiTexCoord3d_PTR local_glMultiTexCoord3d;
            if (local_glMultiTexCoord3d == NULL) {
                local_glMultiTexCoord3d = (glMultiTexCoord3d_PTR)dlsym(g_libgl, "glMultiTexCoord3d");
                if (! local_glMultiTexCoord3d) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord3d'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLenum_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLenum_GLdouble_GLdouble_GLdouble args = unpacked->args;
            local_glMultiTexCoord3d(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord3dv
        case glMultiTexCoord3dv_INDEX: {
            static glMultiTexCoord3dv_PTR local_glMultiTexCoord3dv;
            if (local_glMultiTexCoord3dv == NULL) {
                local_glMultiTexCoord3dv = (glMultiTexCoord3dv_PTR)dlsym(g_libgl, "glMultiTexCoord3dv");
                if (! local_glMultiTexCoord3dv) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord3dv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLdouble___GENPT__ args = unpacked->args;
            local_glMultiTexCoord3dv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord3f
        case glMultiTexCoord3f_INDEX: {
            static glMultiTexCoord3f_PTR local_glMultiTexCoord3f;
            if (local_glMultiTexCoord3f == NULL) {
                local_glMultiTexCoord3f = (glMultiTexCoord3f_PTR)dlsym(g_libgl, "glMultiTexCoord3f");
                if (! local_glMultiTexCoord3f) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord3f'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLenum_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat_GLfloat_GLfloat args = unpacked->args;
            local_glMultiTexCoord3f(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord3fv
        case glMultiTexCoord3fv_INDEX: {
            static glMultiTexCoord3fv_PTR local_glMultiTexCoord3fv;
            if (local_glMultiTexCoord3fv == NULL) {
                local_glMultiTexCoord3fv = (glMultiTexCoord3fv_PTR)dlsym(g_libgl, "glMultiTexCoord3fv");
                if (! local_glMultiTexCoord3fv) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord3fv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            local_glMultiTexCoord3fv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord3i
        case glMultiTexCoord3i_INDEX: {
            static glMultiTexCoord3i_PTR local_glMultiTexCoord3i;
            if (local_glMultiTexCoord3i == NULL) {
                local_glMultiTexCoord3i = (glMultiTexCoord3i_PTR)dlsym(g_libgl, "glMultiTexCoord3i");
                if (! local_glMultiTexCoord3i) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord3i'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLint_GLint *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLint *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint args = unpacked->args;
            local_glMultiTexCoord3i(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord3iv
        case glMultiTexCoord3iv_INDEX: {
            static glMultiTexCoord3iv_PTR local_glMultiTexCoord3iv;
            if (local_glMultiTexCoord3iv == NULL) {
                local_glMultiTexCoord3iv = (glMultiTexCoord3iv_PTR)dlsym(g_libgl, "glMultiTexCoord3iv");
                if (! local_glMultiTexCoord3iv) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord3iv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLint___GENPT__ args = unpacked->args;
            local_glMultiTexCoord3iv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord3s
        case glMultiTexCoord3s_INDEX: {
            static glMultiTexCoord3s_PTR local_glMultiTexCoord3s;
            if (local_glMultiTexCoord3s == NULL) {
                local_glMultiTexCoord3s = (glMultiTexCoord3s_PTR)dlsym(g_libgl, "glMultiTexCoord3s");
                if (! local_glMultiTexCoord3s) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord3s'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLenum_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLenum_GLshort_GLshort_GLshort args = unpacked->args;
            local_glMultiTexCoord3s(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord3sv
        case glMultiTexCoord3sv_INDEX: {
            static glMultiTexCoord3sv_PTR local_glMultiTexCoord3sv;
            if (local_glMultiTexCoord3sv == NULL) {
                local_glMultiTexCoord3sv = (glMultiTexCoord3sv_PTR)dlsym(g_libgl, "glMultiTexCoord3sv");
                if (! local_glMultiTexCoord3sv) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord3sv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_const_GLshort___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLshort___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLshort___GENPT__ args = unpacked->args;
            local_glMultiTexCoord3sv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord4d
        case glMultiTexCoord4d_INDEX: {
            static glMultiTexCoord4d_PTR local_glMultiTexCoord4d;
            if (local_glMultiTexCoord4d == NULL) {
                local_glMultiTexCoord4d = (glMultiTexCoord4d_PTR)dlsym(g_libgl, "glMultiTexCoord4d");
                if (! local_glMultiTexCoord4d) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord4d'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            local_glMultiTexCoord4d(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord4dv
        case glMultiTexCoord4dv_INDEX: {
            static glMultiTexCoord4dv_PTR local_glMultiTexCoord4dv;
            if (local_glMultiTexCoord4dv == NULL) {
                local_glMultiTexCoord4dv = (glMultiTexCoord4dv_PTR)dlsym(g_libgl, "glMultiTexCoord4dv");
                if (! local_glMultiTexCoord4dv) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord4dv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLdouble___GENPT__ args = unpacked->args;
            local_glMultiTexCoord4dv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord4f
        case glMultiTexCoord4f_INDEX: {
            static glMultiTexCoord4f_PTR local_glMultiTexCoord4f;
            if (local_glMultiTexCoord4f == NULL) {
                local_glMultiTexCoord4f = (glMultiTexCoord4f_PTR)dlsym(g_libgl, "glMultiTexCoord4f");
                if (! local_glMultiTexCoord4f) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord4f'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            local_glMultiTexCoord4f(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord4fv
        case glMultiTexCoord4fv_INDEX: {
            static glMultiTexCoord4fv_PTR local_glMultiTexCoord4fv;
            if (local_glMultiTexCoord4fv == NULL) {
                local_glMultiTexCoord4fv = (glMultiTexCoord4fv_PTR)dlsym(g_libgl, "glMultiTexCoord4fv");
                if (! local_glMultiTexCoord4fv) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord4fv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            local_glMultiTexCoord4fv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord4i
        case glMultiTexCoord4i_INDEX: {
            static glMultiTexCoord4i_PTR local_glMultiTexCoord4i;
            if (local_glMultiTexCoord4i == NULL) {
                local_glMultiTexCoord4i = (glMultiTexCoord4i_PTR)dlsym(g_libgl, "glMultiTexCoord4i");
                if (! local_glMultiTexCoord4i) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord4i'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLint_GLint_GLint *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint args = unpacked->args;
            local_glMultiTexCoord4i(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord4iv
        case glMultiTexCoord4iv_INDEX: {
            static glMultiTexCoord4iv_PTR local_glMultiTexCoord4iv;
            if (local_glMultiTexCoord4iv == NULL) {
                local_glMultiTexCoord4iv = (glMultiTexCoord4iv_PTR)dlsym(g_libgl, "glMultiTexCoord4iv");
                if (! local_glMultiTexCoord4iv) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord4iv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLint___GENPT__ args = unpacked->args;
            local_glMultiTexCoord4iv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord4s
        case glMultiTexCoord4s_INDEX: {
            static glMultiTexCoord4s_PTR local_glMultiTexCoord4s;
            if (local_glMultiTexCoord4s == NULL) {
                local_glMultiTexCoord4s = (glMultiTexCoord4s_PTR)dlsym(g_libgl, "glMultiTexCoord4s");
                if (! local_glMultiTexCoord4s) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord4s'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLshort_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLenum_GLshort_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLenum_GLshort_GLshort_GLshort_GLshort args = unpacked->args;
            local_glMultiTexCoord4s(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord4sv
        case glMultiTexCoord4sv_INDEX: {
            static glMultiTexCoord4sv_PTR local_glMultiTexCoord4sv;
            if (local_glMultiTexCoord4sv == NULL) {
                local_glMultiTexCoord4sv = (glMultiTexCoord4sv_PTR)dlsym(g_libgl, "glMultiTexCoord4sv");
                if (! local_glMultiTexCoord4sv) {
                    printf("Warning: Unable to dlsym 'glMultiTexCoord4sv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_const_GLshort___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLshort___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLshort___GENPT__ args = unpacked->args;
            local_glMultiTexCoord4sv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glNewList
        case glNewList_INDEX: {
            static glNewList_PTR local_glNewList;
            if (local_glNewList == NULL) {
                local_glNewList = (glNewList_PTR)dlsym(g_libgl, "glNewList");
                if (! local_glNewList) {
                    printf("Warning: Unable to dlsym 'glNewList'\n");
                    return;
                }
            }

            INDEXED_void_GLuint_GLenum *unpacked = (INDEXED_void_GLuint_GLenum *)packed;
            ARGS_void_GLuint_GLenum args = unpacked->args;
            local_glNewList(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glNormal3b
        case glNormal3b_INDEX: {
            static glNormal3b_PTR local_glNormal3b;
            if (local_glNormal3b == NULL) {
                local_glNormal3b = (glNormal3b_PTR)dlsym(g_libgl, "glNormal3b");
                if (! local_glNormal3b) {
                    printf("Warning: Unable to dlsym 'glNormal3b'\n");
                    return;
                }
            }

            INDEXED_void_GLbyte_GLbyte_GLbyte *unpacked = (INDEXED_void_GLbyte_GLbyte_GLbyte *)packed;
            ARGS_void_GLbyte_GLbyte_GLbyte args = unpacked->args;
            local_glNormal3b(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glNormal3bv
        case glNormal3bv_INDEX: {
            static glNormal3bv_PTR local_glNormal3bv;
            if (local_glNormal3bv == NULL) {
                local_glNormal3bv = (glNormal3bv_PTR)dlsym(g_libgl, "glNormal3bv");
                if (! local_glNormal3bv) {
                    printf("Warning: Unable to dlsym 'glNormal3bv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLbyte___GENPT__ *unpacked = (INDEXED_void_const_GLbyte___GENPT__ *)packed;
            ARGS_void_const_GLbyte___GENPT__ args = unpacked->args;
            local_glNormal3bv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glNormal3d
        case glNormal3d_INDEX: {
            static glNormal3d_PTR local_glNormal3d;
            if (local_glNormal3d == NULL) {
                local_glNormal3d = (glNormal3d_PTR)dlsym(g_libgl, "glNormal3d");
                if (! local_glNormal3d) {
                    printf("Warning: Unable to dlsym 'glNormal3d'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble args = unpacked->args;
            local_glNormal3d(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glNormal3dv
        case glNormal3dv_INDEX: {
            static glNormal3dv_PTR local_glNormal3dv;
            if (local_glNormal3dv == NULL) {
                local_glNormal3dv = (glNormal3dv_PTR)dlsym(g_libgl, "glNormal3dv");
                if (! local_glNormal3dv) {
                    printf("Warning: Unable to dlsym 'glNormal3dv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            local_glNormal3dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glNormal3f
        case glNormal3f_INDEX: {
            static glNormal3f_PTR local_glNormal3f;
            if (local_glNormal3f == NULL) {
                local_glNormal3f = (glNormal3f_PTR)dlsym(g_libgl, "glNormal3f");
                if (! local_glNormal3f) {
                    printf("Warning: Unable to dlsym 'glNormal3f'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat args = unpacked->args;
            local_glNormal3f(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glNormal3fv
        case glNormal3fv_INDEX: {
            static glNormal3fv_PTR local_glNormal3fv;
            if (local_glNormal3fv == NULL) {
                local_glNormal3fv = (glNormal3fv_PTR)dlsym(g_libgl, "glNormal3fv");
                if (! local_glNormal3fv) {
                    printf("Warning: Unable to dlsym 'glNormal3fv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            local_glNormal3fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glNormal3i
        case glNormal3i_INDEX: {
            static glNormal3i_PTR local_glNormal3i;
            if (local_glNormal3i == NULL) {
                local_glNormal3i = (glNormal3i_PTR)dlsym(g_libgl, "glNormal3i");
                if (! local_glNormal3i) {
                    printf("Warning: Unable to dlsym 'glNormal3i'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint args = unpacked->args;
            local_glNormal3i(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glNormal3iv
        case glNormal3iv_INDEX: {
            static glNormal3iv_PTR local_glNormal3iv;
            if (local_glNormal3iv == NULL) {
                local_glNormal3iv = (glNormal3iv_PTR)dlsym(g_libgl, "glNormal3iv");
                if (! local_glNormal3iv) {
                    printf("Warning: Unable to dlsym 'glNormal3iv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            local_glNormal3iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glNormal3s
        case glNormal3s_INDEX: {
            static glNormal3s_PTR local_glNormal3s;
            if (local_glNormal3s == NULL) {
                local_glNormal3s = (glNormal3s_PTR)dlsym(g_libgl, "glNormal3s");
                if (! local_glNormal3s) {
                    printf("Warning: Unable to dlsym 'glNormal3s'\n");
                    return;
                }
            }

            INDEXED_void_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort args = unpacked->args;
            local_glNormal3s(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glNormal3sv
        case glNormal3sv_INDEX: {
            static glNormal3sv_PTR local_glNormal3sv;
            if (local_glNormal3sv == NULL) {
                local_glNormal3sv = (glNormal3sv_PTR)dlsym(g_libgl, "glNormal3sv");
                if (! local_glNormal3sv) {
                    printf("Warning: Unable to dlsym 'glNormal3sv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            local_glNormal3sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glNormalPointer
        case glNormalPointer_INDEX: {
            static glNormalPointer_PTR local_glNormalPointer;
            if (local_glNormalPointer == NULL) {
                local_glNormalPointer = (glNormalPointer_PTR)dlsym(g_libgl, "glNormalPointer");
                if (! local_glNormalPointer) {
                    printf("Warning: Unable to dlsym 'glNormalPointer'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            local_glNormalPointer(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glOrtho
        case glOrtho_INDEX: {
            static glOrtho_PTR local_glOrtho;
            if (local_glOrtho == NULL) {
                local_glOrtho = (glOrtho_PTR)dlsym(g_libgl, "glOrtho");
                if (! local_glOrtho) {
                    printf("Warning: Unable to dlsym 'glOrtho'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            local_glOrtho(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glPassThrough
        case glPassThrough_INDEX: {
            static glPassThrough_PTR local_glPassThrough;
            if (local_glPassThrough == NULL) {
                local_glPassThrough = (glPassThrough_PTR)dlsym(g_libgl, "glPassThrough");
                if (! local_glPassThrough) {
                    printf("Warning: Unable to dlsym 'glPassThrough'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat *unpacked = (INDEXED_void_GLfloat *)packed;
            ARGS_void_GLfloat args = unpacked->args;
            local_glPassThrough(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glPixelMapfv
        case glPixelMapfv_INDEX: {
            static glPixelMapfv_PTR local_glPixelMapfv;
            if (local_glPixelMapfv == NULL) {
                local_glPixelMapfv = (glPixelMapfv_PTR)dlsym(g_libgl, "glPixelMapfv");
                if (! local_glPixelMapfv) {
                    printf("Warning: Unable to dlsym 'glPixelMapfv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLsizei_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLsizei_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_const_GLfloat___GENPT__ args = unpacked->args;
            local_glPixelMapfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glPixelMapuiv
        case glPixelMapuiv_INDEX: {
            static glPixelMapuiv_PTR local_glPixelMapuiv;
            if (local_glPixelMapuiv == NULL) {
                local_glPixelMapuiv = (glPixelMapuiv_PTR)dlsym(g_libgl, "glPixelMapuiv");
                if (! local_glPixelMapuiv) {
                    printf("Warning: Unable to dlsym 'glPixelMapuiv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLsizei_const_GLuint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLsizei_const_GLuint___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_const_GLuint___GENPT__ args = unpacked->args;
            local_glPixelMapuiv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glPixelMapusv
        case glPixelMapusv_INDEX: {
            static glPixelMapusv_PTR local_glPixelMapusv;
            if (local_glPixelMapusv == NULL) {
                local_glPixelMapusv = (glPixelMapusv_PTR)dlsym(g_libgl, "glPixelMapusv");
                if (! local_glPixelMapusv) {
                    printf("Warning: Unable to dlsym 'glPixelMapusv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLsizei_const_GLushort___GENPT__ *unpacked = (INDEXED_void_GLenum_GLsizei_const_GLushort___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_const_GLushort___GENPT__ args = unpacked->args;
            local_glPixelMapusv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glPixelStoref
        case glPixelStoref_INDEX: {
            static glPixelStoref_PTR local_glPixelStoref;
            if (local_glPixelStoref == NULL) {
                local_glPixelStoref = (glPixelStoref_PTR)dlsym(g_libgl, "glPixelStoref");
                if (! local_glPixelStoref) {
                    printf("Warning: Unable to dlsym 'glPixelStoref'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat args = unpacked->args;
            local_glPixelStoref(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glPixelStorei
        case glPixelStorei_INDEX: {
            static glPixelStorei_PTR local_glPixelStorei;
            if (local_glPixelStorei == NULL) {
                local_glPixelStorei = (glPixelStorei_PTR)dlsym(g_libgl, "glPixelStorei");
                if (! local_glPixelStorei) {
                    printf("Warning: Unable to dlsym 'glPixelStorei'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint *unpacked = (INDEXED_void_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLint args = unpacked->args;
            local_glPixelStorei(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glPixelTransferf
        case glPixelTransferf_INDEX: {
            static glPixelTransferf_PTR local_glPixelTransferf;
            if (local_glPixelTransferf == NULL) {
                local_glPixelTransferf = (glPixelTransferf_PTR)dlsym(g_libgl, "glPixelTransferf");
                if (! local_glPixelTransferf) {
                    printf("Warning: Unable to dlsym 'glPixelTransferf'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat args = unpacked->args;
            local_glPixelTransferf(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glPixelTransferi
        case glPixelTransferi_INDEX: {
            static glPixelTransferi_PTR local_glPixelTransferi;
            if (local_glPixelTransferi == NULL) {
                local_glPixelTransferi = (glPixelTransferi_PTR)dlsym(g_libgl, "glPixelTransferi");
                if (! local_glPixelTransferi) {
                    printf("Warning: Unable to dlsym 'glPixelTransferi'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint *unpacked = (INDEXED_void_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLint args = unpacked->args;
            local_glPixelTransferi(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glPixelZoom
        case glPixelZoom_INDEX: {
            static glPixelZoom_PTR local_glPixelZoom;
            if (local_glPixelZoom == NULL) {
                local_glPixelZoom = (glPixelZoom_PTR)dlsym(g_libgl, "glPixelZoom");
                if (! local_glPixelZoom) {
                    printf("Warning: Unable to dlsym 'glPixelZoom'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat args = unpacked->args;
            local_glPixelZoom(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glPointParameterf
        case glPointParameterf_INDEX: {
            static glPointParameterf_PTR local_glPointParameterf;
            if (local_glPointParameterf == NULL) {
                local_glPointParameterf = (glPointParameterf_PTR)dlsym(g_libgl, "glPointParameterf");
                if (! local_glPointParameterf) {
                    printf("Warning: Unable to dlsym 'glPointParameterf'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat args = unpacked->args;
            local_glPointParameterf(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glPointParameterfv
        case glPointParameterfv_INDEX: {
            static glPointParameterfv_PTR local_glPointParameterfv;
            if (local_glPointParameterfv == NULL) {
                local_glPointParameterfv = (glPointParameterfv_PTR)dlsym(g_libgl, "glPointParameterfv");
                if (! local_glPointParameterfv) {
                    printf("Warning: Unable to dlsym 'glPointParameterfv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            local_glPointParameterfv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glPointParameteri
        case glPointParameteri_INDEX: {
            static glPointParameteri_PTR local_glPointParameteri;
            if (local_glPointParameteri == NULL) {
                local_glPointParameteri = (glPointParameteri_PTR)dlsym(g_libgl, "glPointParameteri");
                if (! local_glPointParameteri) {
                    printf("Warning: Unable to dlsym 'glPointParameteri'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint *unpacked = (INDEXED_void_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLint args = unpacked->args;
            local_glPointParameteri(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glPointParameteriv
        case glPointParameteriv_INDEX: {
            static glPointParameteriv_PTR local_glPointParameteriv;
            if (local_glPointParameteriv == NULL) {
                local_glPointParameteriv = (glPointParameteriv_PTR)dlsym(g_libgl, "glPointParameteriv");
                if (! local_glPointParameteriv) {
                    printf("Warning: Unable to dlsym 'glPointParameteriv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLint___GENPT__ args = unpacked->args;
            local_glPointParameteriv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glPointSize
        case glPointSize_INDEX: {
            static glPointSize_PTR local_glPointSize;
            if (local_glPointSize == NULL) {
                local_glPointSize = (glPointSize_PTR)dlsym(g_libgl, "glPointSize");
                if (! local_glPointSize) {
                    printf("Warning: Unable to dlsym 'glPointSize'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat *unpacked = (INDEXED_void_GLfloat *)packed;
            ARGS_void_GLfloat args = unpacked->args;
            local_glPointSize(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glPolygonMode
        case glPolygonMode_INDEX: {
            static glPolygonMode_PTR local_glPolygonMode;
            if (local_glPolygonMode == NULL) {
                local_glPolygonMode = (glPolygonMode_PTR)dlsym(g_libgl, "glPolygonMode");
                if (! local_glPolygonMode) {
                    printf("Warning: Unable to dlsym 'glPolygonMode'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum *unpacked = (INDEXED_void_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLenum args = unpacked->args;
            local_glPolygonMode(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glPolygonOffset
        case glPolygonOffset_INDEX: {
            static glPolygonOffset_PTR local_glPolygonOffset;
            if (local_glPolygonOffset == NULL) {
                local_glPolygonOffset = (glPolygonOffset_PTR)dlsym(g_libgl, "glPolygonOffset");
                if (! local_glPolygonOffset) {
                    printf("Warning: Unable to dlsym 'glPolygonOffset'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat args = unpacked->args;
            local_glPolygonOffset(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glPolygonStipple
        case glPolygonStipple_INDEX: {
            static glPolygonStipple_PTR local_glPolygonStipple;
            if (local_glPolygonStipple == NULL) {
                local_glPolygonStipple = (glPolygonStipple_PTR)dlsym(g_libgl, "glPolygonStipple");
                if (! local_glPolygonStipple) {
                    printf("Warning: Unable to dlsym 'glPolygonStipple'\n");
                    return;
                }
            }

            INDEXED_void_const_GLubyte___GENPT__ *unpacked = (INDEXED_void_const_GLubyte___GENPT__ *)packed;
            ARGS_void_const_GLubyte___GENPT__ args = unpacked->args;
            local_glPolygonStipple(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glPopAttrib
        case glPopAttrib_INDEX: {
            static glPopAttrib_PTR local_glPopAttrib;
            if (local_glPopAttrib == NULL) {
                local_glPopAttrib = (glPopAttrib_PTR)dlsym(g_libgl, "glPopAttrib");
                if (! local_glPopAttrib) {
                    printf("Warning: Unable to dlsym 'glPopAttrib'\n");
                    return;
                }
            }

            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            local_glPopAttrib();
            break;
        }
        #endif
        #ifndef skip_index_glPopClientAttrib
        case glPopClientAttrib_INDEX: {
            static glPopClientAttrib_PTR local_glPopClientAttrib;
            if (local_glPopClientAttrib == NULL) {
                local_glPopClientAttrib = (glPopClientAttrib_PTR)dlsym(g_libgl, "glPopClientAttrib");
                if (! local_glPopClientAttrib) {
                    printf("Warning: Unable to dlsym 'glPopClientAttrib'\n");
                    return;
                }
            }

            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            local_glPopClientAttrib();
            break;
        }
        #endif
        #ifndef skip_index_glPopMatrix
        case glPopMatrix_INDEX: {
            static glPopMatrix_PTR local_glPopMatrix;
            if (local_glPopMatrix == NULL) {
                local_glPopMatrix = (glPopMatrix_PTR)dlsym(g_libgl, "glPopMatrix");
                if (! local_glPopMatrix) {
                    printf("Warning: Unable to dlsym 'glPopMatrix'\n");
                    return;
                }
            }

            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            local_glPopMatrix();
            break;
        }
        #endif
        #ifndef skip_index_glPopName
        case glPopName_INDEX: {
            static glPopName_PTR local_glPopName;
            if (local_glPopName == NULL) {
                local_glPopName = (glPopName_PTR)dlsym(g_libgl, "glPopName");
                if (! local_glPopName) {
                    printf("Warning: Unable to dlsym 'glPopName'\n");
                    return;
                }
            }

            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            local_glPopName();
            break;
        }
        #endif
        #ifndef skip_index_glPrioritizeTextures
        case glPrioritizeTextures_INDEX: {
            static glPrioritizeTextures_PTR local_glPrioritizeTextures;
            if (local_glPrioritizeTextures == NULL) {
                local_glPrioritizeTextures = (glPrioritizeTextures_PTR)dlsym(g_libgl, "glPrioritizeTextures");
                if (! local_glPrioritizeTextures) {
                    printf("Warning: Unable to dlsym 'glPrioritizeTextures'\n");
                    return;
                }
            }

            INDEXED_void_GLsizei_const_GLuint___GENPT___const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLsizei_const_GLuint___GENPT___const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLsizei_const_GLuint___GENPT___const_GLfloat___GENPT__ args = unpacked->args;
            local_glPrioritizeTextures(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glPushAttrib
        case glPushAttrib_INDEX: {
            static glPushAttrib_PTR local_glPushAttrib;
            if (local_glPushAttrib == NULL) {
                local_glPushAttrib = (glPushAttrib_PTR)dlsym(g_libgl, "glPushAttrib");
                if (! local_glPushAttrib) {
                    printf("Warning: Unable to dlsym 'glPushAttrib'\n");
                    return;
                }
            }

            INDEXED_void_GLbitfield *unpacked = (INDEXED_void_GLbitfield *)packed;
            ARGS_void_GLbitfield args = unpacked->args;
            local_glPushAttrib(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glPushClientAttrib
        case glPushClientAttrib_INDEX: {
            static glPushClientAttrib_PTR local_glPushClientAttrib;
            if (local_glPushClientAttrib == NULL) {
                local_glPushClientAttrib = (glPushClientAttrib_PTR)dlsym(g_libgl, "glPushClientAttrib");
                if (! local_glPushClientAttrib) {
                    printf("Warning: Unable to dlsym 'glPushClientAttrib'\n");
                    return;
                }
            }

            INDEXED_void_GLbitfield *unpacked = (INDEXED_void_GLbitfield *)packed;
            ARGS_void_GLbitfield args = unpacked->args;
            local_glPushClientAttrib(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glPushMatrix
        case glPushMatrix_INDEX: {
            static glPushMatrix_PTR local_glPushMatrix;
            if (local_glPushMatrix == NULL) {
                local_glPushMatrix = (glPushMatrix_PTR)dlsym(g_libgl, "glPushMatrix");
                if (! local_glPushMatrix) {
                    printf("Warning: Unable to dlsym 'glPushMatrix'\n");
                    return;
                }
            }

            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            local_glPushMatrix();
            break;
        }
        #endif
        #ifndef skip_index_glPushName
        case glPushName_INDEX: {
            static glPushName_PTR local_glPushName;
            if (local_glPushName == NULL) {
                local_glPushName = (glPushName_PTR)dlsym(g_libgl, "glPushName");
                if (! local_glPushName) {
                    printf("Warning: Unable to dlsym 'glPushName'\n");
                    return;
                }
            }

            INDEXED_void_GLuint *unpacked = (INDEXED_void_GLuint *)packed;
            ARGS_void_GLuint args = unpacked->args;
            local_glPushName(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos2d
        case glRasterPos2d_INDEX: {
            static glRasterPos2d_PTR local_glRasterPos2d;
            if (local_glRasterPos2d == NULL) {
                local_glRasterPos2d = (glRasterPos2d_PTR)dlsym(g_libgl, "glRasterPos2d");
                if (! local_glRasterPos2d) {
                    printf("Warning: Unable to dlsym 'glRasterPos2d'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble args = unpacked->args;
            local_glRasterPos2d(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos2dv
        case glRasterPos2dv_INDEX: {
            static glRasterPos2dv_PTR local_glRasterPos2dv;
            if (local_glRasterPos2dv == NULL) {
                local_glRasterPos2dv = (glRasterPos2dv_PTR)dlsym(g_libgl, "glRasterPos2dv");
                if (! local_glRasterPos2dv) {
                    printf("Warning: Unable to dlsym 'glRasterPos2dv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            local_glRasterPos2dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos2f
        case glRasterPos2f_INDEX: {
            static glRasterPos2f_PTR local_glRasterPos2f;
            if (local_glRasterPos2f == NULL) {
                local_glRasterPos2f = (glRasterPos2f_PTR)dlsym(g_libgl, "glRasterPos2f");
                if (! local_glRasterPos2f) {
                    printf("Warning: Unable to dlsym 'glRasterPos2f'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat args = unpacked->args;
            local_glRasterPos2f(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos2fv
        case glRasterPos2fv_INDEX: {
            static glRasterPos2fv_PTR local_glRasterPos2fv;
            if (local_glRasterPos2fv == NULL) {
                local_glRasterPos2fv = (glRasterPos2fv_PTR)dlsym(g_libgl, "glRasterPos2fv");
                if (! local_glRasterPos2fv) {
                    printf("Warning: Unable to dlsym 'glRasterPos2fv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            local_glRasterPos2fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos2i
        case glRasterPos2i_INDEX: {
            static glRasterPos2i_PTR local_glRasterPos2i;
            if (local_glRasterPos2i == NULL) {
                local_glRasterPos2i = (glRasterPos2i_PTR)dlsym(g_libgl, "glRasterPos2i");
                if (! local_glRasterPos2i) {
                    printf("Warning: Unable to dlsym 'glRasterPos2i'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint *)packed;
            ARGS_void_GLint_GLint args = unpacked->args;
            local_glRasterPos2i(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos2iv
        case glRasterPos2iv_INDEX: {
            static glRasterPos2iv_PTR local_glRasterPos2iv;
            if (local_glRasterPos2iv == NULL) {
                local_glRasterPos2iv = (glRasterPos2iv_PTR)dlsym(g_libgl, "glRasterPos2iv");
                if (! local_glRasterPos2iv) {
                    printf("Warning: Unable to dlsym 'glRasterPos2iv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            local_glRasterPos2iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos2s
        case glRasterPos2s_INDEX: {
            static glRasterPos2s_PTR local_glRasterPos2s;
            if (local_glRasterPos2s == NULL) {
                local_glRasterPos2s = (glRasterPos2s_PTR)dlsym(g_libgl, "glRasterPos2s");
                if (! local_glRasterPos2s) {
                    printf("Warning: Unable to dlsym 'glRasterPos2s'\n");
                    return;
                }
            }

            INDEXED_void_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort args = unpacked->args;
            local_glRasterPos2s(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos2sv
        case glRasterPos2sv_INDEX: {
            static glRasterPos2sv_PTR local_glRasterPos2sv;
            if (local_glRasterPos2sv == NULL) {
                local_glRasterPos2sv = (glRasterPos2sv_PTR)dlsym(g_libgl, "glRasterPos2sv");
                if (! local_glRasterPos2sv) {
                    printf("Warning: Unable to dlsym 'glRasterPos2sv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            local_glRasterPos2sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos3d
        case glRasterPos3d_INDEX: {
            static glRasterPos3d_PTR local_glRasterPos3d;
            if (local_glRasterPos3d == NULL) {
                local_glRasterPos3d = (glRasterPos3d_PTR)dlsym(g_libgl, "glRasterPos3d");
                if (! local_glRasterPos3d) {
                    printf("Warning: Unable to dlsym 'glRasterPos3d'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble args = unpacked->args;
            local_glRasterPos3d(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos3dv
        case glRasterPos3dv_INDEX: {
            static glRasterPos3dv_PTR local_glRasterPos3dv;
            if (local_glRasterPos3dv == NULL) {
                local_glRasterPos3dv = (glRasterPos3dv_PTR)dlsym(g_libgl, "glRasterPos3dv");
                if (! local_glRasterPos3dv) {
                    printf("Warning: Unable to dlsym 'glRasterPos3dv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            local_glRasterPos3dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos3f
        case glRasterPos3f_INDEX: {
            static glRasterPos3f_PTR local_glRasterPos3f;
            if (local_glRasterPos3f == NULL) {
                local_glRasterPos3f = (glRasterPos3f_PTR)dlsym(g_libgl, "glRasterPos3f");
                if (! local_glRasterPos3f) {
                    printf("Warning: Unable to dlsym 'glRasterPos3f'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat args = unpacked->args;
            local_glRasterPos3f(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos3fv
        case glRasterPos3fv_INDEX: {
            static glRasterPos3fv_PTR local_glRasterPos3fv;
            if (local_glRasterPos3fv == NULL) {
                local_glRasterPos3fv = (glRasterPos3fv_PTR)dlsym(g_libgl, "glRasterPos3fv");
                if (! local_glRasterPos3fv) {
                    printf("Warning: Unable to dlsym 'glRasterPos3fv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            local_glRasterPos3fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos3i
        case glRasterPos3i_INDEX: {
            static glRasterPos3i_PTR local_glRasterPos3i;
            if (local_glRasterPos3i == NULL) {
                local_glRasterPos3i = (glRasterPos3i_PTR)dlsym(g_libgl, "glRasterPos3i");
                if (! local_glRasterPos3i) {
                    printf("Warning: Unable to dlsym 'glRasterPos3i'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint args = unpacked->args;
            local_glRasterPos3i(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos3iv
        case glRasterPos3iv_INDEX: {
            static glRasterPos3iv_PTR local_glRasterPos3iv;
            if (local_glRasterPos3iv == NULL) {
                local_glRasterPos3iv = (glRasterPos3iv_PTR)dlsym(g_libgl, "glRasterPos3iv");
                if (! local_glRasterPos3iv) {
                    printf("Warning: Unable to dlsym 'glRasterPos3iv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            local_glRasterPos3iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos3s
        case glRasterPos3s_INDEX: {
            static glRasterPos3s_PTR local_glRasterPos3s;
            if (local_glRasterPos3s == NULL) {
                local_glRasterPos3s = (glRasterPos3s_PTR)dlsym(g_libgl, "glRasterPos3s");
                if (! local_glRasterPos3s) {
                    printf("Warning: Unable to dlsym 'glRasterPos3s'\n");
                    return;
                }
            }

            INDEXED_void_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort args = unpacked->args;
            local_glRasterPos3s(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos3sv
        case glRasterPos3sv_INDEX: {
            static glRasterPos3sv_PTR local_glRasterPos3sv;
            if (local_glRasterPos3sv == NULL) {
                local_glRasterPos3sv = (glRasterPos3sv_PTR)dlsym(g_libgl, "glRasterPos3sv");
                if (! local_glRasterPos3sv) {
                    printf("Warning: Unable to dlsym 'glRasterPos3sv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            local_glRasterPos3sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos4d
        case glRasterPos4d_INDEX: {
            static glRasterPos4d_PTR local_glRasterPos4d;
            if (local_glRasterPos4d == NULL) {
                local_glRasterPos4d = (glRasterPos4d_PTR)dlsym(g_libgl, "glRasterPos4d");
                if (! local_glRasterPos4d) {
                    printf("Warning: Unable to dlsym 'glRasterPos4d'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            local_glRasterPos4d(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos4dv
        case glRasterPos4dv_INDEX: {
            static glRasterPos4dv_PTR local_glRasterPos4dv;
            if (local_glRasterPos4dv == NULL) {
                local_glRasterPos4dv = (glRasterPos4dv_PTR)dlsym(g_libgl, "glRasterPos4dv");
                if (! local_glRasterPos4dv) {
                    printf("Warning: Unable to dlsym 'glRasterPos4dv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            local_glRasterPos4dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos4f
        case glRasterPos4f_INDEX: {
            static glRasterPos4f_PTR local_glRasterPos4f;
            if (local_glRasterPos4f == NULL) {
                local_glRasterPos4f = (glRasterPos4f_PTR)dlsym(g_libgl, "glRasterPos4f");
                if (! local_glRasterPos4f) {
                    printf("Warning: Unable to dlsym 'glRasterPos4f'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            local_glRasterPos4f(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos4fv
        case glRasterPos4fv_INDEX: {
            static glRasterPos4fv_PTR local_glRasterPos4fv;
            if (local_glRasterPos4fv == NULL) {
                local_glRasterPos4fv = (glRasterPos4fv_PTR)dlsym(g_libgl, "glRasterPos4fv");
                if (! local_glRasterPos4fv) {
                    printf("Warning: Unable to dlsym 'glRasterPos4fv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            local_glRasterPos4fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos4i
        case glRasterPos4i_INDEX: {
            static glRasterPos4i_PTR local_glRasterPos4i;
            if (local_glRasterPos4i == NULL) {
                local_glRasterPos4i = (glRasterPos4i_PTR)dlsym(g_libgl, "glRasterPos4i");
                if (! local_glRasterPos4i) {
                    printf("Warning: Unable to dlsym 'glRasterPos4i'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLint_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint_GLint args = unpacked->args;
            local_glRasterPos4i(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos4iv
        case glRasterPos4iv_INDEX: {
            static glRasterPos4iv_PTR local_glRasterPos4iv;
            if (local_glRasterPos4iv == NULL) {
                local_glRasterPos4iv = (glRasterPos4iv_PTR)dlsym(g_libgl, "glRasterPos4iv");
                if (! local_glRasterPos4iv) {
                    printf("Warning: Unable to dlsym 'glRasterPos4iv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            local_glRasterPos4iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos4s
        case glRasterPos4s_INDEX: {
            static glRasterPos4s_PTR local_glRasterPos4s;
            if (local_glRasterPos4s == NULL) {
                local_glRasterPos4s = (glRasterPos4s_PTR)dlsym(g_libgl, "glRasterPos4s");
                if (! local_glRasterPos4s) {
                    printf("Warning: Unable to dlsym 'glRasterPos4s'\n");
                    return;
                }
            }

            INDEXED_void_GLshort_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort_GLshort args = unpacked->args;
            local_glRasterPos4s(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos4sv
        case glRasterPos4sv_INDEX: {
            static glRasterPos4sv_PTR local_glRasterPos4sv;
            if (local_glRasterPos4sv == NULL) {
                local_glRasterPos4sv = (glRasterPos4sv_PTR)dlsym(g_libgl, "glRasterPos4sv");
                if (! local_glRasterPos4sv) {
                    printf("Warning: Unable to dlsym 'glRasterPos4sv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            local_glRasterPos4sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glReadBuffer
        case glReadBuffer_INDEX: {
            static glReadBuffer_PTR local_glReadBuffer;
            if (local_glReadBuffer == NULL) {
                local_glReadBuffer = (glReadBuffer_PTR)dlsym(g_libgl, "glReadBuffer");
                if (! local_glReadBuffer) {
                    printf("Warning: Unable to dlsym 'glReadBuffer'\n");
                    return;
                }
            }

            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            local_glReadBuffer(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glReadPixels
        case glReadPixels_INDEX: {
            static glReadPixels_PTR local_glReadPixels;
            if (local_glReadPixels == NULL) {
                local_glReadPixels = (glReadPixels_PTR)dlsym(g_libgl, "glReadPixels");
                if (! local_glReadPixels) {
                    printf("Warning: Unable to dlsym 'glReadPixels'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ args = unpacked->args;
            local_glReadPixels(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        #endif
        #ifndef skip_index_glRectd
        case glRectd_INDEX: {
            static glRectd_PTR local_glRectd;
            if (local_glRectd == NULL) {
                local_glRectd = (glRectd_PTR)dlsym(g_libgl, "glRectd");
                if (! local_glRectd) {
                    printf("Warning: Unable to dlsym 'glRectd'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            local_glRectd(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glRectdv
        case glRectdv_INDEX: {
            static glRectdv_PTR local_glRectdv;
            if (local_glRectdv == NULL) {
                local_glRectdv = (glRectdv_PTR)dlsym(g_libgl, "glRectdv");
                if (! local_glRectdv) {
                    printf("Warning: Unable to dlsym 'glRectdv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLdouble___GENPT___const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT___const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT___const_GLdouble___GENPT__ args = unpacked->args;
            local_glRectdv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glRectf
        case glRectf_INDEX: {
            static glRectf_PTR local_glRectf;
            if (local_glRectf == NULL) {
                local_glRectf = (glRectf_PTR)dlsym(g_libgl, "glRectf");
                if (! local_glRectf) {
                    printf("Warning: Unable to dlsym 'glRectf'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            local_glRectf(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glRectfv
        case glRectfv_INDEX: {
            static glRectfv_PTR local_glRectfv;
            if (local_glRectfv == NULL) {
                local_glRectfv = (glRectfv_PTR)dlsym(g_libgl, "glRectfv");
                if (! local_glRectfv) {
                    printf("Warning: Unable to dlsym 'glRectfv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLfloat___GENPT___const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT___const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT___const_GLfloat___GENPT__ args = unpacked->args;
            local_glRectfv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glRecti
        case glRecti_INDEX: {
            static glRecti_PTR local_glRecti;
            if (local_glRecti == NULL) {
                local_glRecti = (glRecti_PTR)dlsym(g_libgl, "glRecti");
                if (! local_glRecti) {
                    printf("Warning: Unable to dlsym 'glRecti'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLint_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint_GLint args = unpacked->args;
            local_glRecti(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glRectiv
        case glRectiv_INDEX: {
            static glRectiv_PTR local_glRectiv;
            if (local_glRectiv == NULL) {
                local_glRectiv = (glRectiv_PTR)dlsym(g_libgl, "glRectiv");
                if (! local_glRectiv) {
                    printf("Warning: Unable to dlsym 'glRectiv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLint___GENPT___const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT___const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT___const_GLint___GENPT__ args = unpacked->args;
            local_glRectiv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glRects
        case glRects_INDEX: {
            static glRects_PTR local_glRects;
            if (local_glRects == NULL) {
                local_glRects = (glRects_PTR)dlsym(g_libgl, "glRects");
                if (! local_glRects) {
                    printf("Warning: Unable to dlsym 'glRects'\n");
                    return;
                }
            }

            INDEXED_void_GLshort_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort_GLshort args = unpacked->args;
            local_glRects(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glRectsv
        case glRectsv_INDEX: {
            static glRectsv_PTR local_glRectsv;
            if (local_glRectsv == NULL) {
                local_glRectsv = (glRectsv_PTR)dlsym(g_libgl, "glRectsv");
                if (! local_glRectsv) {
                    printf("Warning: Unable to dlsym 'glRectsv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLshort___GENPT___const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT___const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT___const_GLshort___GENPT__ args = unpacked->args;
            local_glRectsv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glRenderMode
        case glRenderMode_INDEX: {
            static glRenderMode_PTR local_glRenderMode;
            if (local_glRenderMode == NULL) {
                local_glRenderMode = (glRenderMode_PTR)dlsym(g_libgl, "glRenderMode");
                if (! local_glRenderMode) {
                    printf("Warning: Unable to dlsym 'glRenderMode'\n");
                    return;
                }
            }

            INDEXED_GLint_GLenum *unpacked = (INDEXED_GLint_GLenum *)packed;
            ARGS_GLint_GLenum args = unpacked->args;
            GLint *ret = (GLint *)ret_v;
            *ret =
            local_glRenderMode(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glResetHistogram
        case glResetHistogram_INDEX: {
            static glResetHistogram_PTR local_glResetHistogram;
            if (local_glResetHistogram == NULL) {
                local_glResetHistogram = (glResetHistogram_PTR)dlsym(g_libgl, "glResetHistogram");
                if (! local_glResetHistogram) {
                    printf("Warning: Unable to dlsym 'glResetHistogram'\n");
                    return;
                }
            }

            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            local_glResetHistogram(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glResetMinmax
        case glResetMinmax_INDEX: {
            static glResetMinmax_PTR local_glResetMinmax;
            if (local_glResetMinmax == NULL) {
                local_glResetMinmax = (glResetMinmax_PTR)dlsym(g_libgl, "glResetMinmax");
                if (! local_glResetMinmax) {
                    printf("Warning: Unable to dlsym 'glResetMinmax'\n");
                    return;
                }
            }

            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            local_glResetMinmax(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRotated
        case glRotated_INDEX: {
            static glRotated_PTR local_glRotated;
            if (local_glRotated == NULL) {
                local_glRotated = (glRotated_PTR)dlsym(g_libgl, "glRotated");
                if (! local_glRotated) {
                    printf("Warning: Unable to dlsym 'glRotated'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            local_glRotated(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glRotatef
        case glRotatef_INDEX: {
            static glRotatef_PTR local_glRotatef;
            if (local_glRotatef == NULL) {
                local_glRotatef = (glRotatef_PTR)dlsym(g_libgl, "glRotatef");
                if (! local_glRotatef) {
                    printf("Warning: Unable to dlsym 'glRotatef'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            local_glRotatef(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glSampleCoverage
        case glSampleCoverage_INDEX: {
            static glSampleCoverage_PTR local_glSampleCoverage;
            if (local_glSampleCoverage == NULL) {
                local_glSampleCoverage = (glSampleCoverage_PTR)dlsym(g_libgl, "glSampleCoverage");
                if (! local_glSampleCoverage) {
                    printf("Warning: Unable to dlsym 'glSampleCoverage'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLboolean *unpacked = (INDEXED_void_GLfloat_GLboolean *)packed;
            ARGS_void_GLfloat_GLboolean args = unpacked->args;
            local_glSampleCoverage(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glScaled
        case glScaled_INDEX: {
            static glScaled_PTR local_glScaled;
            if (local_glScaled == NULL) {
                local_glScaled = (glScaled_PTR)dlsym(g_libgl, "glScaled");
                if (! local_glScaled) {
                    printf("Warning: Unable to dlsym 'glScaled'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble args = unpacked->args;
            local_glScaled(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glScalef
        case glScalef_INDEX: {
            static glScalef_PTR local_glScalef;
            if (local_glScalef == NULL) {
                local_glScalef = (glScalef_PTR)dlsym(g_libgl, "glScalef");
                if (! local_glScalef) {
                    printf("Warning: Unable to dlsym 'glScalef'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat args = unpacked->args;
            local_glScalef(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glScissor
        case glScissor_INDEX: {
            static glScissor_PTR local_glScissor;
            if (local_glScissor == NULL) {
                local_glScissor = (glScissor_PTR)dlsym(g_libgl, "glScissor");
                if (! local_glScissor) {
                    printf("Warning: Unable to dlsym 'glScissor'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLint_GLsizei_GLsizei *unpacked = (INDEXED_void_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            local_glScissor(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3b
        case glSecondaryColor3b_INDEX: {
            static glSecondaryColor3b_PTR local_glSecondaryColor3b;
            if (local_glSecondaryColor3b == NULL) {
                local_glSecondaryColor3b = (glSecondaryColor3b_PTR)dlsym(g_libgl, "glSecondaryColor3b");
                if (! local_glSecondaryColor3b) {
                    printf("Warning: Unable to dlsym 'glSecondaryColor3b'\n");
                    return;
                }
            }

            INDEXED_void_GLbyte_GLbyte_GLbyte *unpacked = (INDEXED_void_GLbyte_GLbyte_GLbyte *)packed;
            ARGS_void_GLbyte_GLbyte_GLbyte args = unpacked->args;
            local_glSecondaryColor3b(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3bv
        case glSecondaryColor3bv_INDEX: {
            static glSecondaryColor3bv_PTR local_glSecondaryColor3bv;
            if (local_glSecondaryColor3bv == NULL) {
                local_glSecondaryColor3bv = (glSecondaryColor3bv_PTR)dlsym(g_libgl, "glSecondaryColor3bv");
                if (! local_glSecondaryColor3bv) {
                    printf("Warning: Unable to dlsym 'glSecondaryColor3bv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLbyte___GENPT__ *unpacked = (INDEXED_void_const_GLbyte___GENPT__ *)packed;
            ARGS_void_const_GLbyte___GENPT__ args = unpacked->args;
            local_glSecondaryColor3bv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3d
        case glSecondaryColor3d_INDEX: {
            static glSecondaryColor3d_PTR local_glSecondaryColor3d;
            if (local_glSecondaryColor3d == NULL) {
                local_glSecondaryColor3d = (glSecondaryColor3d_PTR)dlsym(g_libgl, "glSecondaryColor3d");
                if (! local_glSecondaryColor3d) {
                    printf("Warning: Unable to dlsym 'glSecondaryColor3d'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble args = unpacked->args;
            local_glSecondaryColor3d(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3dv
        case glSecondaryColor3dv_INDEX: {
            static glSecondaryColor3dv_PTR local_glSecondaryColor3dv;
            if (local_glSecondaryColor3dv == NULL) {
                local_glSecondaryColor3dv = (glSecondaryColor3dv_PTR)dlsym(g_libgl, "glSecondaryColor3dv");
                if (! local_glSecondaryColor3dv) {
                    printf("Warning: Unable to dlsym 'glSecondaryColor3dv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            local_glSecondaryColor3dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3f
        case glSecondaryColor3f_INDEX: {
            static glSecondaryColor3f_PTR local_glSecondaryColor3f;
            if (local_glSecondaryColor3f == NULL) {
                local_glSecondaryColor3f = (glSecondaryColor3f_PTR)dlsym(g_libgl, "glSecondaryColor3f");
                if (! local_glSecondaryColor3f) {
                    printf("Warning: Unable to dlsym 'glSecondaryColor3f'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat args = unpacked->args;
            local_glSecondaryColor3f(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3fv
        case glSecondaryColor3fv_INDEX: {
            static glSecondaryColor3fv_PTR local_glSecondaryColor3fv;
            if (local_glSecondaryColor3fv == NULL) {
                local_glSecondaryColor3fv = (glSecondaryColor3fv_PTR)dlsym(g_libgl, "glSecondaryColor3fv");
                if (! local_glSecondaryColor3fv) {
                    printf("Warning: Unable to dlsym 'glSecondaryColor3fv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            local_glSecondaryColor3fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3i
        case glSecondaryColor3i_INDEX: {
            static glSecondaryColor3i_PTR local_glSecondaryColor3i;
            if (local_glSecondaryColor3i == NULL) {
                local_glSecondaryColor3i = (glSecondaryColor3i_PTR)dlsym(g_libgl, "glSecondaryColor3i");
                if (! local_glSecondaryColor3i) {
                    printf("Warning: Unable to dlsym 'glSecondaryColor3i'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint args = unpacked->args;
            local_glSecondaryColor3i(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3iv
        case glSecondaryColor3iv_INDEX: {
            static glSecondaryColor3iv_PTR local_glSecondaryColor3iv;
            if (local_glSecondaryColor3iv == NULL) {
                local_glSecondaryColor3iv = (glSecondaryColor3iv_PTR)dlsym(g_libgl, "glSecondaryColor3iv");
                if (! local_glSecondaryColor3iv) {
                    printf("Warning: Unable to dlsym 'glSecondaryColor3iv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            local_glSecondaryColor3iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3s
        case glSecondaryColor3s_INDEX: {
            static glSecondaryColor3s_PTR local_glSecondaryColor3s;
            if (local_glSecondaryColor3s == NULL) {
                local_glSecondaryColor3s = (glSecondaryColor3s_PTR)dlsym(g_libgl, "glSecondaryColor3s");
                if (! local_glSecondaryColor3s) {
                    printf("Warning: Unable to dlsym 'glSecondaryColor3s'\n");
                    return;
                }
            }

            INDEXED_void_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort args = unpacked->args;
            local_glSecondaryColor3s(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3sv
        case glSecondaryColor3sv_INDEX: {
            static glSecondaryColor3sv_PTR local_glSecondaryColor3sv;
            if (local_glSecondaryColor3sv == NULL) {
                local_glSecondaryColor3sv = (glSecondaryColor3sv_PTR)dlsym(g_libgl, "glSecondaryColor3sv");
                if (! local_glSecondaryColor3sv) {
                    printf("Warning: Unable to dlsym 'glSecondaryColor3sv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            local_glSecondaryColor3sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3ub
        case glSecondaryColor3ub_INDEX: {
            static glSecondaryColor3ub_PTR local_glSecondaryColor3ub;
            if (local_glSecondaryColor3ub == NULL) {
                local_glSecondaryColor3ub = (glSecondaryColor3ub_PTR)dlsym(g_libgl, "glSecondaryColor3ub");
                if (! local_glSecondaryColor3ub) {
                    printf("Warning: Unable to dlsym 'glSecondaryColor3ub'\n");
                    return;
                }
            }

            INDEXED_void_GLubyte_GLubyte_GLubyte *unpacked = (INDEXED_void_GLubyte_GLubyte_GLubyte *)packed;
            ARGS_void_GLubyte_GLubyte_GLubyte args = unpacked->args;
            local_glSecondaryColor3ub(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3ubv
        case glSecondaryColor3ubv_INDEX: {
            static glSecondaryColor3ubv_PTR local_glSecondaryColor3ubv;
            if (local_glSecondaryColor3ubv == NULL) {
                local_glSecondaryColor3ubv = (glSecondaryColor3ubv_PTR)dlsym(g_libgl, "glSecondaryColor3ubv");
                if (! local_glSecondaryColor3ubv) {
                    printf("Warning: Unable to dlsym 'glSecondaryColor3ubv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLubyte___GENPT__ *unpacked = (INDEXED_void_const_GLubyte___GENPT__ *)packed;
            ARGS_void_const_GLubyte___GENPT__ args = unpacked->args;
            local_glSecondaryColor3ubv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3ui
        case glSecondaryColor3ui_INDEX: {
            static glSecondaryColor3ui_PTR local_glSecondaryColor3ui;
            if (local_glSecondaryColor3ui == NULL) {
                local_glSecondaryColor3ui = (glSecondaryColor3ui_PTR)dlsym(g_libgl, "glSecondaryColor3ui");
                if (! local_glSecondaryColor3ui) {
                    printf("Warning: Unable to dlsym 'glSecondaryColor3ui'\n");
                    return;
                }
            }

            INDEXED_void_GLuint_GLuint_GLuint *unpacked = (INDEXED_void_GLuint_GLuint_GLuint *)packed;
            ARGS_void_GLuint_GLuint_GLuint args = unpacked->args;
            local_glSecondaryColor3ui(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3uiv
        case glSecondaryColor3uiv_INDEX: {
            static glSecondaryColor3uiv_PTR local_glSecondaryColor3uiv;
            if (local_glSecondaryColor3uiv == NULL) {
                local_glSecondaryColor3uiv = (glSecondaryColor3uiv_PTR)dlsym(g_libgl, "glSecondaryColor3uiv");
                if (! local_glSecondaryColor3uiv) {
                    printf("Warning: Unable to dlsym 'glSecondaryColor3uiv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLuint___GENPT__ *unpacked = (INDEXED_void_const_GLuint___GENPT__ *)packed;
            ARGS_void_const_GLuint___GENPT__ args = unpacked->args;
            local_glSecondaryColor3uiv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3us
        case glSecondaryColor3us_INDEX: {
            static glSecondaryColor3us_PTR local_glSecondaryColor3us;
            if (local_glSecondaryColor3us == NULL) {
                local_glSecondaryColor3us = (glSecondaryColor3us_PTR)dlsym(g_libgl, "glSecondaryColor3us");
                if (! local_glSecondaryColor3us) {
                    printf("Warning: Unable to dlsym 'glSecondaryColor3us'\n");
                    return;
                }
            }

            INDEXED_void_GLushort_GLushort_GLushort *unpacked = (INDEXED_void_GLushort_GLushort_GLushort *)packed;
            ARGS_void_GLushort_GLushort_GLushort args = unpacked->args;
            local_glSecondaryColor3us(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3usv
        case glSecondaryColor3usv_INDEX: {
            static glSecondaryColor3usv_PTR local_glSecondaryColor3usv;
            if (local_glSecondaryColor3usv == NULL) {
                local_glSecondaryColor3usv = (glSecondaryColor3usv_PTR)dlsym(g_libgl, "glSecondaryColor3usv");
                if (! local_glSecondaryColor3usv) {
                    printf("Warning: Unable to dlsym 'glSecondaryColor3usv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLushort___GENPT__ *unpacked = (INDEXED_void_const_GLushort___GENPT__ *)packed;
            ARGS_void_const_GLushort___GENPT__ args = unpacked->args;
            local_glSecondaryColor3usv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColorPointer
        case glSecondaryColorPointer_INDEX: {
            static glSecondaryColorPointer_PTR local_glSecondaryColorPointer;
            if (local_glSecondaryColorPointer == NULL) {
                local_glSecondaryColorPointer = (glSecondaryColorPointer_PTR)dlsym(g_libgl, "glSecondaryColorPointer");
                if (! local_glSecondaryColorPointer) {
                    printf("Warning: Unable to dlsym 'glSecondaryColorPointer'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            local_glSecondaryColorPointer(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glSelectBuffer
        case glSelectBuffer_INDEX: {
            static glSelectBuffer_PTR local_glSelectBuffer;
            if (local_glSelectBuffer == NULL) {
                local_glSelectBuffer = (glSelectBuffer_PTR)dlsym(g_libgl, "glSelectBuffer");
                if (! local_glSelectBuffer) {
                    printf("Warning: Unable to dlsym 'glSelectBuffer'\n");
                    return;
                }
            }

            INDEXED_void_GLsizei_GLuint___GENPT__ *unpacked = (INDEXED_void_GLsizei_GLuint___GENPT__ *)packed;
            ARGS_void_GLsizei_GLuint___GENPT__ args = unpacked->args;
            local_glSelectBuffer(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glSeparableFilter2D
        case glSeparableFilter2D_INDEX: {
            static glSeparableFilter2D_PTR local_glSeparableFilter2D;
            if (local_glSeparableFilter2D == NULL) {
                local_glSeparableFilter2D = (glSeparableFilter2D_PTR)dlsym(g_libgl, "glSeparableFilter2D");
                if (! local_glSeparableFilter2D) {
                    printf("Warning: Unable to dlsym 'glSeparableFilter2D'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT___const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT___const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT___const_GLvoid___GENPT__ args = unpacked->args;
            local_glSeparableFilter2D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        #endif
        #ifndef skip_index_glShadeModel
        case glShadeModel_INDEX: {
            static glShadeModel_PTR local_glShadeModel;
            if (local_glShadeModel == NULL) {
                local_glShadeModel = (glShadeModel_PTR)dlsym(g_libgl, "glShadeModel");
                if (! local_glShadeModel) {
                    printf("Warning: Unable to dlsym 'glShadeModel'\n");
                    return;
                }
            }

            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            local_glShadeModel(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glStencilFunc
        case glStencilFunc_INDEX: {
            static glStencilFunc_PTR local_glStencilFunc;
            if (local_glStencilFunc == NULL) {
                local_glStencilFunc = (glStencilFunc_PTR)dlsym(g_libgl, "glStencilFunc");
                if (! local_glStencilFunc) {
                    printf("Warning: Unable to dlsym 'glStencilFunc'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLuint *unpacked = (INDEXED_void_GLenum_GLint_GLuint *)packed;
            ARGS_void_GLenum_GLint_GLuint args = unpacked->args;
            local_glStencilFunc(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glStencilMask
        case glStencilMask_INDEX: {
            static glStencilMask_PTR local_glStencilMask;
            if (local_glStencilMask == NULL) {
                local_glStencilMask = (glStencilMask_PTR)dlsym(g_libgl, "glStencilMask");
                if (! local_glStencilMask) {
                    printf("Warning: Unable to dlsym 'glStencilMask'\n");
                    return;
                }
            }

            INDEXED_void_GLuint *unpacked = (INDEXED_void_GLuint *)packed;
            ARGS_void_GLuint args = unpacked->args;
            local_glStencilMask(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glStencilOp
        case glStencilOp_INDEX: {
            static glStencilOp_PTR local_glStencilOp;
            if (local_glStencilOp == NULL) {
                local_glStencilOp = (glStencilOp_PTR)dlsym(g_libgl, "glStencilOp");
                if (! local_glStencilOp) {
                    printf("Warning: Unable to dlsym 'glStencilOp'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLenum *unpacked = (INDEXED_void_GLenum_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLenum_GLenum args = unpacked->args;
            local_glStencilOp(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord1d
        case glTexCoord1d_INDEX: {
            static glTexCoord1d_PTR local_glTexCoord1d;
            if (local_glTexCoord1d == NULL) {
                local_glTexCoord1d = (glTexCoord1d_PTR)dlsym(g_libgl, "glTexCoord1d");
                if (! local_glTexCoord1d) {
                    printf("Warning: Unable to dlsym 'glTexCoord1d'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble *unpacked = (INDEXED_void_GLdouble *)packed;
            ARGS_void_GLdouble args = unpacked->args;
            local_glTexCoord1d(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord1dv
        case glTexCoord1dv_INDEX: {
            static glTexCoord1dv_PTR local_glTexCoord1dv;
            if (local_glTexCoord1dv == NULL) {
                local_glTexCoord1dv = (glTexCoord1dv_PTR)dlsym(g_libgl, "glTexCoord1dv");
                if (! local_glTexCoord1dv) {
                    printf("Warning: Unable to dlsym 'glTexCoord1dv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            local_glTexCoord1dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord1f
        case glTexCoord1f_INDEX: {
            static glTexCoord1f_PTR local_glTexCoord1f;
            if (local_glTexCoord1f == NULL) {
                local_glTexCoord1f = (glTexCoord1f_PTR)dlsym(g_libgl, "glTexCoord1f");
                if (! local_glTexCoord1f) {
                    printf("Warning: Unable to dlsym 'glTexCoord1f'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat *unpacked = (INDEXED_void_GLfloat *)packed;
            ARGS_void_GLfloat args = unpacked->args;
            local_glTexCoord1f(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord1fv
        case glTexCoord1fv_INDEX: {
            static glTexCoord1fv_PTR local_glTexCoord1fv;
            if (local_glTexCoord1fv == NULL) {
                local_glTexCoord1fv = (glTexCoord1fv_PTR)dlsym(g_libgl, "glTexCoord1fv");
                if (! local_glTexCoord1fv) {
                    printf("Warning: Unable to dlsym 'glTexCoord1fv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            local_glTexCoord1fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord1i
        case glTexCoord1i_INDEX: {
            static glTexCoord1i_PTR local_glTexCoord1i;
            if (local_glTexCoord1i == NULL) {
                local_glTexCoord1i = (glTexCoord1i_PTR)dlsym(g_libgl, "glTexCoord1i");
                if (! local_glTexCoord1i) {
                    printf("Warning: Unable to dlsym 'glTexCoord1i'\n");
                    return;
                }
            }

            INDEXED_void_GLint *unpacked = (INDEXED_void_GLint *)packed;
            ARGS_void_GLint args = unpacked->args;
            local_glTexCoord1i(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord1iv
        case glTexCoord1iv_INDEX: {
            static glTexCoord1iv_PTR local_glTexCoord1iv;
            if (local_glTexCoord1iv == NULL) {
                local_glTexCoord1iv = (glTexCoord1iv_PTR)dlsym(g_libgl, "glTexCoord1iv");
                if (! local_glTexCoord1iv) {
                    printf("Warning: Unable to dlsym 'glTexCoord1iv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            local_glTexCoord1iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord1s
        case glTexCoord1s_INDEX: {
            static glTexCoord1s_PTR local_glTexCoord1s;
            if (local_glTexCoord1s == NULL) {
                local_glTexCoord1s = (glTexCoord1s_PTR)dlsym(g_libgl, "glTexCoord1s");
                if (! local_glTexCoord1s) {
                    printf("Warning: Unable to dlsym 'glTexCoord1s'\n");
                    return;
                }
            }

            INDEXED_void_GLshort *unpacked = (INDEXED_void_GLshort *)packed;
            ARGS_void_GLshort args = unpacked->args;
            local_glTexCoord1s(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord1sv
        case glTexCoord1sv_INDEX: {
            static glTexCoord1sv_PTR local_glTexCoord1sv;
            if (local_glTexCoord1sv == NULL) {
                local_glTexCoord1sv = (glTexCoord1sv_PTR)dlsym(g_libgl, "glTexCoord1sv");
                if (! local_glTexCoord1sv) {
                    printf("Warning: Unable to dlsym 'glTexCoord1sv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            local_glTexCoord1sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord2d
        case glTexCoord2d_INDEX: {
            static glTexCoord2d_PTR local_glTexCoord2d;
            if (local_glTexCoord2d == NULL) {
                local_glTexCoord2d = (glTexCoord2d_PTR)dlsym(g_libgl, "glTexCoord2d");
                if (! local_glTexCoord2d) {
                    printf("Warning: Unable to dlsym 'glTexCoord2d'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble args = unpacked->args;
            local_glTexCoord2d(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord2dv
        case glTexCoord2dv_INDEX: {
            static glTexCoord2dv_PTR local_glTexCoord2dv;
            if (local_glTexCoord2dv == NULL) {
                local_glTexCoord2dv = (glTexCoord2dv_PTR)dlsym(g_libgl, "glTexCoord2dv");
                if (! local_glTexCoord2dv) {
                    printf("Warning: Unable to dlsym 'glTexCoord2dv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            local_glTexCoord2dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord2f
        case glTexCoord2f_INDEX: {
            static glTexCoord2f_PTR local_glTexCoord2f;
            if (local_glTexCoord2f == NULL) {
                local_glTexCoord2f = (glTexCoord2f_PTR)dlsym(g_libgl, "glTexCoord2f");
                if (! local_glTexCoord2f) {
                    printf("Warning: Unable to dlsym 'glTexCoord2f'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat args = unpacked->args;
            local_glTexCoord2f(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord2fv
        case glTexCoord2fv_INDEX: {
            static glTexCoord2fv_PTR local_glTexCoord2fv;
            if (local_glTexCoord2fv == NULL) {
                local_glTexCoord2fv = (glTexCoord2fv_PTR)dlsym(g_libgl, "glTexCoord2fv");
                if (! local_glTexCoord2fv) {
                    printf("Warning: Unable to dlsym 'glTexCoord2fv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            local_glTexCoord2fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord2i
        case glTexCoord2i_INDEX: {
            static glTexCoord2i_PTR local_glTexCoord2i;
            if (local_glTexCoord2i == NULL) {
                local_glTexCoord2i = (glTexCoord2i_PTR)dlsym(g_libgl, "glTexCoord2i");
                if (! local_glTexCoord2i) {
                    printf("Warning: Unable to dlsym 'glTexCoord2i'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint *)packed;
            ARGS_void_GLint_GLint args = unpacked->args;
            local_glTexCoord2i(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord2iv
        case glTexCoord2iv_INDEX: {
            static glTexCoord2iv_PTR local_glTexCoord2iv;
            if (local_glTexCoord2iv == NULL) {
                local_glTexCoord2iv = (glTexCoord2iv_PTR)dlsym(g_libgl, "glTexCoord2iv");
                if (! local_glTexCoord2iv) {
                    printf("Warning: Unable to dlsym 'glTexCoord2iv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            local_glTexCoord2iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord2s
        case glTexCoord2s_INDEX: {
            static glTexCoord2s_PTR local_glTexCoord2s;
            if (local_glTexCoord2s == NULL) {
                local_glTexCoord2s = (glTexCoord2s_PTR)dlsym(g_libgl, "glTexCoord2s");
                if (! local_glTexCoord2s) {
                    printf("Warning: Unable to dlsym 'glTexCoord2s'\n");
                    return;
                }
            }

            INDEXED_void_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort args = unpacked->args;
            local_glTexCoord2s(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord2sv
        case glTexCoord2sv_INDEX: {
            static glTexCoord2sv_PTR local_glTexCoord2sv;
            if (local_glTexCoord2sv == NULL) {
                local_glTexCoord2sv = (glTexCoord2sv_PTR)dlsym(g_libgl, "glTexCoord2sv");
                if (! local_glTexCoord2sv) {
                    printf("Warning: Unable to dlsym 'glTexCoord2sv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            local_glTexCoord2sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord3d
        case glTexCoord3d_INDEX: {
            static glTexCoord3d_PTR local_glTexCoord3d;
            if (local_glTexCoord3d == NULL) {
                local_glTexCoord3d = (glTexCoord3d_PTR)dlsym(g_libgl, "glTexCoord3d");
                if (! local_glTexCoord3d) {
                    printf("Warning: Unable to dlsym 'glTexCoord3d'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble args = unpacked->args;
            local_glTexCoord3d(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord3dv
        case glTexCoord3dv_INDEX: {
            static glTexCoord3dv_PTR local_glTexCoord3dv;
            if (local_glTexCoord3dv == NULL) {
                local_glTexCoord3dv = (glTexCoord3dv_PTR)dlsym(g_libgl, "glTexCoord3dv");
                if (! local_glTexCoord3dv) {
                    printf("Warning: Unable to dlsym 'glTexCoord3dv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            local_glTexCoord3dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord3f
        case glTexCoord3f_INDEX: {
            static glTexCoord3f_PTR local_glTexCoord3f;
            if (local_glTexCoord3f == NULL) {
                local_glTexCoord3f = (glTexCoord3f_PTR)dlsym(g_libgl, "glTexCoord3f");
                if (! local_glTexCoord3f) {
                    printf("Warning: Unable to dlsym 'glTexCoord3f'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat args = unpacked->args;
            local_glTexCoord3f(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord3fv
        case glTexCoord3fv_INDEX: {
            static glTexCoord3fv_PTR local_glTexCoord3fv;
            if (local_glTexCoord3fv == NULL) {
                local_glTexCoord3fv = (glTexCoord3fv_PTR)dlsym(g_libgl, "glTexCoord3fv");
                if (! local_glTexCoord3fv) {
                    printf("Warning: Unable to dlsym 'glTexCoord3fv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            local_glTexCoord3fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord3i
        case glTexCoord3i_INDEX: {
            static glTexCoord3i_PTR local_glTexCoord3i;
            if (local_glTexCoord3i == NULL) {
                local_glTexCoord3i = (glTexCoord3i_PTR)dlsym(g_libgl, "glTexCoord3i");
                if (! local_glTexCoord3i) {
                    printf("Warning: Unable to dlsym 'glTexCoord3i'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint args = unpacked->args;
            local_glTexCoord3i(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord3iv
        case glTexCoord3iv_INDEX: {
            static glTexCoord3iv_PTR local_glTexCoord3iv;
            if (local_glTexCoord3iv == NULL) {
                local_glTexCoord3iv = (glTexCoord3iv_PTR)dlsym(g_libgl, "glTexCoord3iv");
                if (! local_glTexCoord3iv) {
                    printf("Warning: Unable to dlsym 'glTexCoord3iv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            local_glTexCoord3iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord3s
        case glTexCoord3s_INDEX: {
            static glTexCoord3s_PTR local_glTexCoord3s;
            if (local_glTexCoord3s == NULL) {
                local_glTexCoord3s = (glTexCoord3s_PTR)dlsym(g_libgl, "glTexCoord3s");
                if (! local_glTexCoord3s) {
                    printf("Warning: Unable to dlsym 'glTexCoord3s'\n");
                    return;
                }
            }

            INDEXED_void_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort args = unpacked->args;
            local_glTexCoord3s(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord3sv
        case glTexCoord3sv_INDEX: {
            static glTexCoord3sv_PTR local_glTexCoord3sv;
            if (local_glTexCoord3sv == NULL) {
                local_glTexCoord3sv = (glTexCoord3sv_PTR)dlsym(g_libgl, "glTexCoord3sv");
                if (! local_glTexCoord3sv) {
                    printf("Warning: Unable to dlsym 'glTexCoord3sv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            local_glTexCoord3sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord4d
        case glTexCoord4d_INDEX: {
            static glTexCoord4d_PTR local_glTexCoord4d;
            if (local_glTexCoord4d == NULL) {
                local_glTexCoord4d = (glTexCoord4d_PTR)dlsym(g_libgl, "glTexCoord4d");
                if (! local_glTexCoord4d) {
                    printf("Warning: Unable to dlsym 'glTexCoord4d'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            local_glTexCoord4d(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord4dv
        case glTexCoord4dv_INDEX: {
            static glTexCoord4dv_PTR local_glTexCoord4dv;
            if (local_glTexCoord4dv == NULL) {
                local_glTexCoord4dv = (glTexCoord4dv_PTR)dlsym(g_libgl, "glTexCoord4dv");
                if (! local_glTexCoord4dv) {
                    printf("Warning: Unable to dlsym 'glTexCoord4dv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            local_glTexCoord4dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord4f
        case glTexCoord4f_INDEX: {
            static glTexCoord4f_PTR local_glTexCoord4f;
            if (local_glTexCoord4f == NULL) {
                local_glTexCoord4f = (glTexCoord4f_PTR)dlsym(g_libgl, "glTexCoord4f");
                if (! local_glTexCoord4f) {
                    printf("Warning: Unable to dlsym 'glTexCoord4f'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            local_glTexCoord4f(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord4fv
        case glTexCoord4fv_INDEX: {
            static glTexCoord4fv_PTR local_glTexCoord4fv;
            if (local_glTexCoord4fv == NULL) {
                local_glTexCoord4fv = (glTexCoord4fv_PTR)dlsym(g_libgl, "glTexCoord4fv");
                if (! local_glTexCoord4fv) {
                    printf("Warning: Unable to dlsym 'glTexCoord4fv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            local_glTexCoord4fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord4i
        case glTexCoord4i_INDEX: {
            static glTexCoord4i_PTR local_glTexCoord4i;
            if (local_glTexCoord4i == NULL) {
                local_glTexCoord4i = (glTexCoord4i_PTR)dlsym(g_libgl, "glTexCoord4i");
                if (! local_glTexCoord4i) {
                    printf("Warning: Unable to dlsym 'glTexCoord4i'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLint_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint_GLint args = unpacked->args;
            local_glTexCoord4i(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord4iv
        case glTexCoord4iv_INDEX: {
            static glTexCoord4iv_PTR local_glTexCoord4iv;
            if (local_glTexCoord4iv == NULL) {
                local_glTexCoord4iv = (glTexCoord4iv_PTR)dlsym(g_libgl, "glTexCoord4iv");
                if (! local_glTexCoord4iv) {
                    printf("Warning: Unable to dlsym 'glTexCoord4iv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            local_glTexCoord4iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord4s
        case glTexCoord4s_INDEX: {
            static glTexCoord4s_PTR local_glTexCoord4s;
            if (local_glTexCoord4s == NULL) {
                local_glTexCoord4s = (glTexCoord4s_PTR)dlsym(g_libgl, "glTexCoord4s");
                if (! local_glTexCoord4s) {
                    printf("Warning: Unable to dlsym 'glTexCoord4s'\n");
                    return;
                }
            }

            INDEXED_void_GLshort_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort_GLshort args = unpacked->args;
            local_glTexCoord4s(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord4sv
        case glTexCoord4sv_INDEX: {
            static glTexCoord4sv_PTR local_glTexCoord4sv;
            if (local_glTexCoord4sv == NULL) {
                local_glTexCoord4sv = (glTexCoord4sv_PTR)dlsym(g_libgl, "glTexCoord4sv");
                if (! local_glTexCoord4sv) {
                    printf("Warning: Unable to dlsym 'glTexCoord4sv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            local_glTexCoord4sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoordPointer
        case glTexCoordPointer_INDEX: {
            static glTexCoordPointer_PTR local_glTexCoordPointer;
            if (local_glTexCoordPointer == NULL) {
                local_glTexCoordPointer = (glTexCoordPointer_PTR)dlsym(g_libgl, "glTexCoordPointer");
                if (! local_glTexCoordPointer) {
                    printf("Warning: Unable to dlsym 'glTexCoordPointer'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            local_glTexCoordPointer(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glTexEnvf
        case glTexEnvf_INDEX: {
            static glTexEnvf_PTR local_glTexEnvf;
            if (local_glTexEnvf == NULL) {
                local_glTexEnvf = (glTexEnvf_PTR)dlsym(g_libgl, "glTexEnvf");
                if (! local_glTexEnvf) {
                    printf("Warning: Unable to dlsym 'glTexEnvf'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLenum_GLfloat args = unpacked->args;
            local_glTexEnvf(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexEnvfv
        case glTexEnvfv_INDEX: {
            static glTexEnvfv_PTR local_glTexEnvfv;
            if (local_glTexEnvfv == NULL) {
                local_glTexEnvfv = (glTexEnvfv_PTR)dlsym(g_libgl, "glTexEnvfv");
                if (! local_glTexEnvfv) {
                    printf("Warning: Unable to dlsym 'glTexEnvfv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            local_glTexEnvfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexEnvi
        case glTexEnvi_INDEX: {
            static glTexEnvi_PTR local_glTexEnvi;
            if (local_glTexEnvi == NULL) {
                local_glTexEnvi = (glTexEnvi_PTR)dlsym(g_libgl, "glTexEnvi");
                if (! local_glTexEnvi) {
                    printf("Warning: Unable to dlsym 'glTexEnvi'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLint *unpacked = (INDEXED_void_GLenum_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLint args = unpacked->args;
            local_glTexEnvi(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexEnviv
        case glTexEnviv_INDEX: {
            static glTexEnviv_PTR local_glTexEnviv;
            if (local_glTexEnviv == NULL) {
                local_glTexEnviv = (glTexEnviv_PTR)dlsym(g_libgl, "glTexEnviv");
                if (! local_glTexEnviv) {
                    printf("Warning: Unable to dlsym 'glTexEnviv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLint___GENPT__ args = unpacked->args;
            local_glTexEnviv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexGend
        case glTexGend_INDEX: {
            static glTexGend_PTR local_glTexGend;
            if (local_glTexGend == NULL) {
                local_glTexGend = (glTexGend_PTR)dlsym(g_libgl, "glTexGend");
                if (! local_glTexGend) {
                    printf("Warning: Unable to dlsym 'glTexGend'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLdouble *unpacked = (INDEXED_void_GLenum_GLenum_GLdouble *)packed;
            ARGS_void_GLenum_GLenum_GLdouble args = unpacked->args;
            local_glTexGend(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexGendv
        case glTexGendv_INDEX: {
            static glTexGendv_PTR local_glTexGendv;
            if (local_glTexGendv == NULL) {
                local_glTexGendv = (glTexGendv_PTR)dlsym(g_libgl, "glTexGendv");
                if (! local_glTexGendv) {
                    printf("Warning: Unable to dlsym 'glTexGendv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLdouble___GENPT__ args = unpacked->args;
            local_glTexGendv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexGenf
        case glTexGenf_INDEX: {
            static glTexGenf_PTR local_glTexGenf;
            if (local_glTexGenf == NULL) {
                local_glTexGenf = (glTexGenf_PTR)dlsym(g_libgl, "glTexGenf");
                if (! local_glTexGenf) {
                    printf("Warning: Unable to dlsym 'glTexGenf'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLenum_GLfloat args = unpacked->args;
            local_glTexGenf(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexGenfv
        case glTexGenfv_INDEX: {
            static glTexGenfv_PTR local_glTexGenfv;
            if (local_glTexGenfv == NULL) {
                local_glTexGenfv = (glTexGenfv_PTR)dlsym(g_libgl, "glTexGenfv");
                if (! local_glTexGenfv) {
                    printf("Warning: Unable to dlsym 'glTexGenfv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            local_glTexGenfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexGeni
        case glTexGeni_INDEX: {
            static glTexGeni_PTR local_glTexGeni;
            if (local_glTexGeni == NULL) {
                local_glTexGeni = (glTexGeni_PTR)dlsym(g_libgl, "glTexGeni");
                if (! local_glTexGeni) {
                    printf("Warning: Unable to dlsym 'glTexGeni'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLint *unpacked = (INDEXED_void_GLenum_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLint args = unpacked->args;
            local_glTexGeni(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexGeniv
        case glTexGeniv_INDEX: {
            static glTexGeniv_PTR local_glTexGeniv;
            if (local_glTexGeniv == NULL) {
                local_glTexGeniv = (glTexGeniv_PTR)dlsym(g_libgl, "glTexGeniv");
                if (! local_glTexGeniv) {
                    printf("Warning: Unable to dlsym 'glTexGeniv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLint___GENPT__ args = unpacked->args;
            local_glTexGeniv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexImage1D
        case glTexImage1D_INDEX: {
            static glTexImage1D_PTR local_glTexImage1D;
            if (local_glTexImage1D == NULL) {
                local_glTexImage1D = (glTexImage1D_PTR)dlsym(g_libgl, "glTexImage1D");
                if (! local_glTexImage1D) {
                    printf("Warning: Unable to dlsym 'glTexImage1D'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            local_glTexImage1D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        #endif
        #ifndef skip_index_glTexImage2D
        case glTexImage2D_INDEX: {
            static glTexImage2D_PTR local_glTexImage2D;
            if (local_glTexImage2D == NULL) {
                local_glTexImage2D = (glTexImage2D_PTR)dlsym(g_libgl, "glTexImage2D");
                if (! local_glTexImage2D) {
                    printf("Warning: Unable to dlsym 'glTexImage2D'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            local_glTexImage2D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        #endif
        #ifndef skip_index_glTexImage3D
        case glTexImage3D_INDEX: {
            static glTexImage3D_PTR local_glTexImage3D;
            if (local_glTexImage3D == NULL) {
                local_glTexImage3D = (glTexImage3D_PTR)dlsym(g_libgl, "glTexImage3D");
                if (! local_glTexImage3D) {
                    printf("Warning: Unable to dlsym 'glTexImage3D'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            local_glTexImage3D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        #endif
        #ifndef skip_index_glTexParameterf
        case glTexParameterf_INDEX: {
            static glTexParameterf_PTR local_glTexParameterf;
            if (local_glTexParameterf == NULL) {
                local_glTexParameterf = (glTexParameterf_PTR)dlsym(g_libgl, "glTexParameterf");
                if (! local_glTexParameterf) {
                    printf("Warning: Unable to dlsym 'glTexParameterf'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLenum_GLfloat args = unpacked->args;
            local_glTexParameterf(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexParameterfv
        case glTexParameterfv_INDEX: {
            static glTexParameterfv_PTR local_glTexParameterfv;
            if (local_glTexParameterfv == NULL) {
                local_glTexParameterfv = (glTexParameterfv_PTR)dlsym(g_libgl, "glTexParameterfv");
                if (! local_glTexParameterfv) {
                    printf("Warning: Unable to dlsym 'glTexParameterfv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            local_glTexParameterfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexParameteri
        case glTexParameteri_INDEX: {
            static glTexParameteri_PTR local_glTexParameteri;
            if (local_glTexParameteri == NULL) {
                local_glTexParameteri = (glTexParameteri_PTR)dlsym(g_libgl, "glTexParameteri");
                if (! local_glTexParameteri) {
                    printf("Warning: Unable to dlsym 'glTexParameteri'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_GLint *unpacked = (INDEXED_void_GLenum_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLint args = unpacked->args;
            local_glTexParameteri(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexParameteriv
        case glTexParameteriv_INDEX: {
            static glTexParameteriv_PTR local_glTexParameteriv;
            if (local_glTexParameteriv == NULL) {
                local_glTexParameteriv = (glTexParameteriv_PTR)dlsym(g_libgl, "glTexParameteriv");
                if (! local_glTexParameteriv) {
                    printf("Warning: Unable to dlsym 'glTexParameteriv'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLint___GENPT__ args = unpacked->args;
            local_glTexParameteriv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexSubImage1D
        case glTexSubImage1D_INDEX: {
            static glTexSubImage1D_PTR local_glTexSubImage1D;
            if (local_glTexSubImage1D == NULL) {
                local_glTexSubImage1D = (glTexSubImage1D_PTR)dlsym(g_libgl, "glTexSubImage1D");
                if (! local_glTexSubImage1D) {
                    printf("Warning: Unable to dlsym 'glTexSubImage1D'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            local_glTexSubImage1D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        #endif
        #ifndef skip_index_glTexSubImage2D
        case glTexSubImage2D_INDEX: {
            static glTexSubImage2D_PTR local_glTexSubImage2D;
            if (local_glTexSubImage2D == NULL) {
                local_glTexSubImage2D = (glTexSubImage2D_PTR)dlsym(g_libgl, "glTexSubImage2D");
                if (! local_glTexSubImage2D) {
                    printf("Warning: Unable to dlsym 'glTexSubImage2D'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            local_glTexSubImage2D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        #endif
        #ifndef skip_index_glTexSubImage3D
        case glTexSubImage3D_INDEX: {
            static glTexSubImage3D_PTR local_glTexSubImage3D;
            if (local_glTexSubImage3D == NULL) {
                local_glTexSubImage3D = (glTexSubImage3D_PTR)dlsym(g_libgl, "glTexSubImage3D");
                if (! local_glTexSubImage3D) {
                    printf("Warning: Unable to dlsym 'glTexSubImage3D'\n");
                    return;
                }
            }

            INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            local_glTexSubImage3D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11);
            break;
        }
        #endif
        #ifndef skip_index_glTranslated
        case glTranslated_INDEX: {
            static glTranslated_PTR local_glTranslated;
            if (local_glTranslated == NULL) {
                local_glTranslated = (glTranslated_PTR)dlsym(g_libgl, "glTranslated");
                if (! local_glTranslated) {
                    printf("Warning: Unable to dlsym 'glTranslated'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble args = unpacked->args;
            local_glTranslated(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTranslatef
        case glTranslatef_INDEX: {
            static glTranslatef_PTR local_glTranslatef;
            if (local_glTranslatef == NULL) {
                local_glTranslatef = (glTranslatef_PTR)dlsym(g_libgl, "glTranslatef");
                if (! local_glTranslatef) {
                    printf("Warning: Unable to dlsym 'glTranslatef'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat args = unpacked->args;
            local_glTranslatef(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glUnmapBuffer
        case glUnmapBuffer_INDEX: {
            static glUnmapBuffer_PTR local_glUnmapBuffer;
            if (local_glUnmapBuffer == NULL) {
                local_glUnmapBuffer = (glUnmapBuffer_PTR)dlsym(g_libgl, "glUnmapBuffer");
                if (! local_glUnmapBuffer) {
                    printf("Warning: Unable to dlsym 'glUnmapBuffer'\n");
                    return;
                }
            }

            INDEXED_GLboolean_GLenum *unpacked = (INDEXED_GLboolean_GLenum *)packed;
            ARGS_GLboolean_GLenum args = unpacked->args;
            GLboolean *ret = (GLboolean *)ret_v;
            *ret =
            local_glUnmapBuffer(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertex2d
        case glVertex2d_INDEX: {
            static glVertex2d_PTR local_glVertex2d;
            if (local_glVertex2d == NULL) {
                local_glVertex2d = (glVertex2d_PTR)dlsym(g_libgl, "glVertex2d");
                if (! local_glVertex2d) {
                    printf("Warning: Unable to dlsym 'glVertex2d'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble args = unpacked->args;
            local_glVertex2d(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glVertex2dv
        case glVertex2dv_INDEX: {
            static glVertex2dv_PTR local_glVertex2dv;
            if (local_glVertex2dv == NULL) {
                local_glVertex2dv = (glVertex2dv_PTR)dlsym(g_libgl, "glVertex2dv");
                if (! local_glVertex2dv) {
                    printf("Warning: Unable to dlsym 'glVertex2dv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            local_glVertex2dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertex2f
        case glVertex2f_INDEX: {
            static glVertex2f_PTR local_glVertex2f;
            if (local_glVertex2f == NULL) {
                local_glVertex2f = (glVertex2f_PTR)dlsym(g_libgl, "glVertex2f");
                if (! local_glVertex2f) {
                    printf("Warning: Unable to dlsym 'glVertex2f'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat args = unpacked->args;
            local_glVertex2f(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glVertex2fv
        case glVertex2fv_INDEX: {
            static glVertex2fv_PTR local_glVertex2fv;
            if (local_glVertex2fv == NULL) {
                local_glVertex2fv = (glVertex2fv_PTR)dlsym(g_libgl, "glVertex2fv");
                if (! local_glVertex2fv) {
                    printf("Warning: Unable to dlsym 'glVertex2fv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            local_glVertex2fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertex2i
        case glVertex2i_INDEX: {
            static glVertex2i_PTR local_glVertex2i;
            if (local_glVertex2i == NULL) {
                local_glVertex2i = (glVertex2i_PTR)dlsym(g_libgl, "glVertex2i");
                if (! local_glVertex2i) {
                    printf("Warning: Unable to dlsym 'glVertex2i'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint *)packed;
            ARGS_void_GLint_GLint args = unpacked->args;
            local_glVertex2i(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glVertex2iv
        case glVertex2iv_INDEX: {
            static glVertex2iv_PTR local_glVertex2iv;
            if (local_glVertex2iv == NULL) {
                local_glVertex2iv = (glVertex2iv_PTR)dlsym(g_libgl, "glVertex2iv");
                if (! local_glVertex2iv) {
                    printf("Warning: Unable to dlsym 'glVertex2iv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            local_glVertex2iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertex2s
        case glVertex2s_INDEX: {
            static glVertex2s_PTR local_glVertex2s;
            if (local_glVertex2s == NULL) {
                local_glVertex2s = (glVertex2s_PTR)dlsym(g_libgl, "glVertex2s");
                if (! local_glVertex2s) {
                    printf("Warning: Unable to dlsym 'glVertex2s'\n");
                    return;
                }
            }

            INDEXED_void_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort args = unpacked->args;
            local_glVertex2s(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glVertex2sv
        case glVertex2sv_INDEX: {
            static glVertex2sv_PTR local_glVertex2sv;
            if (local_glVertex2sv == NULL) {
                local_glVertex2sv = (glVertex2sv_PTR)dlsym(g_libgl, "glVertex2sv");
                if (! local_glVertex2sv) {
                    printf("Warning: Unable to dlsym 'glVertex2sv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            local_glVertex2sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertex3d
        case glVertex3d_INDEX: {
            static glVertex3d_PTR local_glVertex3d;
            if (local_glVertex3d == NULL) {
                local_glVertex3d = (glVertex3d_PTR)dlsym(g_libgl, "glVertex3d");
                if (! local_glVertex3d) {
                    printf("Warning: Unable to dlsym 'glVertex3d'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble args = unpacked->args;
            local_glVertex3d(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glVertex3dv
        case glVertex3dv_INDEX: {
            static glVertex3dv_PTR local_glVertex3dv;
            if (local_glVertex3dv == NULL) {
                local_glVertex3dv = (glVertex3dv_PTR)dlsym(g_libgl, "glVertex3dv");
                if (! local_glVertex3dv) {
                    printf("Warning: Unable to dlsym 'glVertex3dv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            local_glVertex3dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertex3f
        case glVertex3f_INDEX: {
            static glVertex3f_PTR local_glVertex3f;
            if (local_glVertex3f == NULL) {
                local_glVertex3f = (glVertex3f_PTR)dlsym(g_libgl, "glVertex3f");
                if (! local_glVertex3f) {
                    printf("Warning: Unable to dlsym 'glVertex3f'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat args = unpacked->args;
            local_glVertex3f(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glVertex3fv
        case glVertex3fv_INDEX: {
            static glVertex3fv_PTR local_glVertex3fv;
            if (local_glVertex3fv == NULL) {
                local_glVertex3fv = (glVertex3fv_PTR)dlsym(g_libgl, "glVertex3fv");
                if (! local_glVertex3fv) {
                    printf("Warning: Unable to dlsym 'glVertex3fv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            local_glVertex3fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertex3i
        case glVertex3i_INDEX: {
            static glVertex3i_PTR local_glVertex3i;
            if (local_glVertex3i == NULL) {
                local_glVertex3i = (glVertex3i_PTR)dlsym(g_libgl, "glVertex3i");
                if (! local_glVertex3i) {
                    printf("Warning: Unable to dlsym 'glVertex3i'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint args = unpacked->args;
            local_glVertex3i(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glVertex3iv
        case glVertex3iv_INDEX: {
            static glVertex3iv_PTR local_glVertex3iv;
            if (local_glVertex3iv == NULL) {
                local_glVertex3iv = (glVertex3iv_PTR)dlsym(g_libgl, "glVertex3iv");
                if (! local_glVertex3iv) {
                    printf("Warning: Unable to dlsym 'glVertex3iv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            local_glVertex3iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertex3s
        case glVertex3s_INDEX: {
            static glVertex3s_PTR local_glVertex3s;
            if (local_glVertex3s == NULL) {
                local_glVertex3s = (glVertex3s_PTR)dlsym(g_libgl, "glVertex3s");
                if (! local_glVertex3s) {
                    printf("Warning: Unable to dlsym 'glVertex3s'\n");
                    return;
                }
            }

            INDEXED_void_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort args = unpacked->args;
            local_glVertex3s(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glVertex3sv
        case glVertex3sv_INDEX: {
            static glVertex3sv_PTR local_glVertex3sv;
            if (local_glVertex3sv == NULL) {
                local_glVertex3sv = (glVertex3sv_PTR)dlsym(g_libgl, "glVertex3sv");
                if (! local_glVertex3sv) {
                    printf("Warning: Unable to dlsym 'glVertex3sv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            local_glVertex3sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertex4d
        case glVertex4d_INDEX: {
            static glVertex4d_PTR local_glVertex4d;
            if (local_glVertex4d == NULL) {
                local_glVertex4d = (glVertex4d_PTR)dlsym(g_libgl, "glVertex4d");
                if (! local_glVertex4d) {
                    printf("Warning: Unable to dlsym 'glVertex4d'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            local_glVertex4d(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glVertex4dv
        case glVertex4dv_INDEX: {
            static glVertex4dv_PTR local_glVertex4dv;
            if (local_glVertex4dv == NULL) {
                local_glVertex4dv = (glVertex4dv_PTR)dlsym(g_libgl, "glVertex4dv");
                if (! local_glVertex4dv) {
                    printf("Warning: Unable to dlsym 'glVertex4dv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            local_glVertex4dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertex4f
        case glVertex4f_INDEX: {
            static glVertex4f_PTR local_glVertex4f;
            if (local_glVertex4f == NULL) {
                local_glVertex4f = (glVertex4f_PTR)dlsym(g_libgl, "glVertex4f");
                if (! local_glVertex4f) {
                    printf("Warning: Unable to dlsym 'glVertex4f'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            local_glVertex4f(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glVertex4fv
        case glVertex4fv_INDEX: {
            static glVertex4fv_PTR local_glVertex4fv;
            if (local_glVertex4fv == NULL) {
                local_glVertex4fv = (glVertex4fv_PTR)dlsym(g_libgl, "glVertex4fv");
                if (! local_glVertex4fv) {
                    printf("Warning: Unable to dlsym 'glVertex4fv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            local_glVertex4fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertex4i
        case glVertex4i_INDEX: {
            static glVertex4i_PTR local_glVertex4i;
            if (local_glVertex4i == NULL) {
                local_glVertex4i = (glVertex4i_PTR)dlsym(g_libgl, "glVertex4i");
                if (! local_glVertex4i) {
                    printf("Warning: Unable to dlsym 'glVertex4i'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLint_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint_GLint args = unpacked->args;
            local_glVertex4i(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glVertex4iv
        case glVertex4iv_INDEX: {
            static glVertex4iv_PTR local_glVertex4iv;
            if (local_glVertex4iv == NULL) {
                local_glVertex4iv = (glVertex4iv_PTR)dlsym(g_libgl, "glVertex4iv");
                if (! local_glVertex4iv) {
                    printf("Warning: Unable to dlsym 'glVertex4iv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            local_glVertex4iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertex4s
        case glVertex4s_INDEX: {
            static glVertex4s_PTR local_glVertex4s;
            if (local_glVertex4s == NULL) {
                local_glVertex4s = (glVertex4s_PTR)dlsym(g_libgl, "glVertex4s");
                if (! local_glVertex4s) {
                    printf("Warning: Unable to dlsym 'glVertex4s'\n");
                    return;
                }
            }

            INDEXED_void_GLshort_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort_GLshort args = unpacked->args;
            local_glVertex4s(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glVertex4sv
        case glVertex4sv_INDEX: {
            static glVertex4sv_PTR local_glVertex4sv;
            if (local_glVertex4sv == NULL) {
                local_glVertex4sv = (glVertex4sv_PTR)dlsym(g_libgl, "glVertex4sv");
                if (! local_glVertex4sv) {
                    printf("Warning: Unable to dlsym 'glVertex4sv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            local_glVertex4sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertexPointer
        case glVertexPointer_INDEX: {
            static glVertexPointer_PTR local_glVertexPointer;
            if (local_glVertexPointer == NULL) {
                local_glVertexPointer = (glVertexPointer_PTR)dlsym(g_libgl, "glVertexPointer");
                if (! local_glVertexPointer) {
                    printf("Warning: Unable to dlsym 'glVertexPointer'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            local_glVertexPointer(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glViewport
        case glViewport_INDEX: {
            static glViewport_PTR local_glViewport;
            if (local_glViewport == NULL) {
                local_glViewport = (glViewport_PTR)dlsym(g_libgl, "glViewport");
                if (! local_glViewport) {
                    printf("Warning: Unable to dlsym 'glViewport'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLint_GLsizei_GLsizei *unpacked = (INDEXED_void_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            local_glViewport(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos2d
        case glWindowPos2d_INDEX: {
            static glWindowPos2d_PTR local_glWindowPos2d;
            if (local_glWindowPos2d == NULL) {
                local_glWindowPos2d = (glWindowPos2d_PTR)dlsym(g_libgl, "glWindowPos2d");
                if (! local_glWindowPos2d) {
                    printf("Warning: Unable to dlsym 'glWindowPos2d'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble args = unpacked->args;
            local_glWindowPos2d(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos2dv
        case glWindowPos2dv_INDEX: {
            static glWindowPos2dv_PTR local_glWindowPos2dv;
            if (local_glWindowPos2dv == NULL) {
                local_glWindowPos2dv = (glWindowPos2dv_PTR)dlsym(g_libgl, "glWindowPos2dv");
                if (! local_glWindowPos2dv) {
                    printf("Warning: Unable to dlsym 'glWindowPos2dv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            local_glWindowPos2dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos2f
        case glWindowPos2f_INDEX: {
            static glWindowPos2f_PTR local_glWindowPos2f;
            if (local_glWindowPos2f == NULL) {
                local_glWindowPos2f = (glWindowPos2f_PTR)dlsym(g_libgl, "glWindowPos2f");
                if (! local_glWindowPos2f) {
                    printf("Warning: Unable to dlsym 'glWindowPos2f'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat args = unpacked->args;
            local_glWindowPos2f(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos2fv
        case glWindowPos2fv_INDEX: {
            static glWindowPos2fv_PTR local_glWindowPos2fv;
            if (local_glWindowPos2fv == NULL) {
                local_glWindowPos2fv = (glWindowPos2fv_PTR)dlsym(g_libgl, "glWindowPos2fv");
                if (! local_glWindowPos2fv) {
                    printf("Warning: Unable to dlsym 'glWindowPos2fv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            local_glWindowPos2fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos2i
        case glWindowPos2i_INDEX: {
            static glWindowPos2i_PTR local_glWindowPos2i;
            if (local_glWindowPos2i == NULL) {
                local_glWindowPos2i = (glWindowPos2i_PTR)dlsym(g_libgl, "glWindowPos2i");
                if (! local_glWindowPos2i) {
                    printf("Warning: Unable to dlsym 'glWindowPos2i'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint *)packed;
            ARGS_void_GLint_GLint args = unpacked->args;
            local_glWindowPos2i(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos2iv
        case glWindowPos2iv_INDEX: {
            static glWindowPos2iv_PTR local_glWindowPos2iv;
            if (local_glWindowPos2iv == NULL) {
                local_glWindowPos2iv = (glWindowPos2iv_PTR)dlsym(g_libgl, "glWindowPos2iv");
                if (! local_glWindowPos2iv) {
                    printf("Warning: Unable to dlsym 'glWindowPos2iv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            local_glWindowPos2iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos2s
        case glWindowPos2s_INDEX: {
            static glWindowPos2s_PTR local_glWindowPos2s;
            if (local_glWindowPos2s == NULL) {
                local_glWindowPos2s = (glWindowPos2s_PTR)dlsym(g_libgl, "glWindowPos2s");
                if (! local_glWindowPos2s) {
                    printf("Warning: Unable to dlsym 'glWindowPos2s'\n");
                    return;
                }
            }

            INDEXED_void_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort args = unpacked->args;
            local_glWindowPos2s(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos2sv
        case glWindowPos2sv_INDEX: {
            static glWindowPos2sv_PTR local_glWindowPos2sv;
            if (local_glWindowPos2sv == NULL) {
                local_glWindowPos2sv = (glWindowPos2sv_PTR)dlsym(g_libgl, "glWindowPos2sv");
                if (! local_glWindowPos2sv) {
                    printf("Warning: Unable to dlsym 'glWindowPos2sv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            local_glWindowPos2sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos3d
        case glWindowPos3d_INDEX: {
            static glWindowPos3d_PTR local_glWindowPos3d;
            if (local_glWindowPos3d == NULL) {
                local_glWindowPos3d = (glWindowPos3d_PTR)dlsym(g_libgl, "glWindowPos3d");
                if (! local_glWindowPos3d) {
                    printf("Warning: Unable to dlsym 'glWindowPos3d'\n");
                    return;
                }
            }

            INDEXED_void_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble args = unpacked->args;
            local_glWindowPos3d(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos3dv
        case glWindowPos3dv_INDEX: {
            static glWindowPos3dv_PTR local_glWindowPos3dv;
            if (local_glWindowPos3dv == NULL) {
                local_glWindowPos3dv = (glWindowPos3dv_PTR)dlsym(g_libgl, "glWindowPos3dv");
                if (! local_glWindowPos3dv) {
                    printf("Warning: Unable to dlsym 'glWindowPos3dv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            local_glWindowPos3dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos3f
        case glWindowPos3f_INDEX: {
            static glWindowPos3f_PTR local_glWindowPos3f;
            if (local_glWindowPos3f == NULL) {
                local_glWindowPos3f = (glWindowPos3f_PTR)dlsym(g_libgl, "glWindowPos3f");
                if (! local_glWindowPos3f) {
                    printf("Warning: Unable to dlsym 'glWindowPos3f'\n");
                    return;
                }
            }

            INDEXED_void_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat args = unpacked->args;
            local_glWindowPos3f(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos3fv
        case glWindowPos3fv_INDEX: {
            static glWindowPos3fv_PTR local_glWindowPos3fv;
            if (local_glWindowPos3fv == NULL) {
                local_glWindowPos3fv = (glWindowPos3fv_PTR)dlsym(g_libgl, "glWindowPos3fv");
                if (! local_glWindowPos3fv) {
                    printf("Warning: Unable to dlsym 'glWindowPos3fv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            local_glWindowPos3fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos3i
        case glWindowPos3i_INDEX: {
            static glWindowPos3i_PTR local_glWindowPos3i;
            if (local_glWindowPos3i == NULL) {
                local_glWindowPos3i = (glWindowPos3i_PTR)dlsym(g_libgl, "glWindowPos3i");
                if (! local_glWindowPos3i) {
                    printf("Warning: Unable to dlsym 'glWindowPos3i'\n");
                    return;
                }
            }

            INDEXED_void_GLint_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint args = unpacked->args;
            local_glWindowPos3i(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos3iv
        case glWindowPos3iv_INDEX: {
            static glWindowPos3iv_PTR local_glWindowPos3iv;
            if (local_glWindowPos3iv == NULL) {
                local_glWindowPos3iv = (glWindowPos3iv_PTR)dlsym(g_libgl, "glWindowPos3iv");
                if (! local_glWindowPos3iv) {
                    printf("Warning: Unable to dlsym 'glWindowPos3iv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            local_glWindowPos3iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos3s
        case glWindowPos3s_INDEX: {
            static glWindowPos3s_PTR local_glWindowPos3s;
            if (local_glWindowPos3s == NULL) {
                local_glWindowPos3s = (glWindowPos3s_PTR)dlsym(g_libgl, "glWindowPos3s");
                if (! local_glWindowPos3s) {
                    printf("Warning: Unable to dlsym 'glWindowPos3s'\n");
                    return;
                }
            }

            INDEXED_void_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort args = unpacked->args;
            local_glWindowPos3s(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos3sv
        case glWindowPos3sv_INDEX: {
            static glWindowPos3sv_PTR local_glWindowPos3sv;
            if (local_glWindowPos3sv == NULL) {
                local_glWindowPos3sv = (glWindowPos3sv_PTR)dlsym(g_libgl, "glWindowPos3sv");
                if (! local_glWindowPos3sv) {
                    printf("Warning: Unable to dlsym 'glWindowPos3sv'\n");
                    return;
                }
            }

            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            local_glWindowPos3sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glXBindHyperpipeSGIX
        case glXBindHyperpipeSGIX_INDEX: {
            static glXBindHyperpipeSGIX_PTR local_glXBindHyperpipeSGIX;
            if (local_glXBindHyperpipeSGIX == NULL) {
                local_glXBindHyperpipeSGIX = (glXBindHyperpipeSGIX_PTR)dlsym(g_libgl, "glXBindHyperpipeSGIX");
                if (! local_glXBindHyperpipeSGIX) {
                    printf("Warning: Unable to dlsym 'glXBindHyperpipeSGIX'\n");
                    return;
                }
            }

            INDEXED_int_Display___GENPT___int *unpacked = (INDEXED_int_Display___GENPT___int *)packed;
            ARGS_int_Display___GENPT___int args = unpacked->args;
            int *ret = (int *)ret_v;
            *ret =
            local_glXBindHyperpipeSGIX(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXBindSwapBarrierSGIX
        case glXBindSwapBarrierSGIX_INDEX: {
            static glXBindSwapBarrierSGIX_PTR local_glXBindSwapBarrierSGIX;
            if (local_glXBindSwapBarrierSGIX == NULL) {
                local_glXBindSwapBarrierSGIX = (glXBindSwapBarrierSGIX_PTR)dlsym(g_libgl, "glXBindSwapBarrierSGIX");
                if (! local_glXBindSwapBarrierSGIX) {
                    printf("Warning: Unable to dlsym 'glXBindSwapBarrierSGIX'\n");
                    return;
                }
            }

            INDEXED_void_uint32_t_uint32_t *unpacked = (INDEXED_void_uint32_t_uint32_t *)packed;
            ARGS_void_uint32_t_uint32_t args = unpacked->args;
            local_glXBindSwapBarrierSGIX(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXChangeDrawableAttributes
        case glXChangeDrawableAttributes_INDEX: {
            static glXChangeDrawableAttributes_PTR local_glXChangeDrawableAttributes;
            if (local_glXChangeDrawableAttributes == NULL) {
                local_glXChangeDrawableAttributes = (glXChangeDrawableAttributes_PTR)dlsym(g_libgl, "glXChangeDrawableAttributes");
                if (! local_glXChangeDrawableAttributes) {
                    printf("Warning: Unable to dlsym 'glXChangeDrawableAttributes'\n");
                    return;
                }
            }

            INDEXED_void_uint32_t *unpacked = (INDEXED_void_uint32_t *)packed;
            ARGS_void_uint32_t args = unpacked->args;
            local_glXChangeDrawableAttributes(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glXChangeDrawableAttributesSGIX
        case glXChangeDrawableAttributesSGIX_INDEX: {
            static glXChangeDrawableAttributesSGIX_PTR local_glXChangeDrawableAttributesSGIX;
            if (local_glXChangeDrawableAttributesSGIX == NULL) {
                local_glXChangeDrawableAttributesSGIX = (glXChangeDrawableAttributesSGIX_PTR)dlsym(g_libgl, "glXChangeDrawableAttributesSGIX");
                if (! local_glXChangeDrawableAttributesSGIX) {
                    printf("Warning: Unable to dlsym 'glXChangeDrawableAttributesSGIX'\n");
                    return;
                }
            }

            INDEXED_void_uint32_t *unpacked = (INDEXED_void_uint32_t *)packed;
            ARGS_void_uint32_t args = unpacked->args;
            local_glXChangeDrawableAttributesSGIX(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glXChooseFBConfig
        case glXChooseFBConfig_INDEX: {
            static glXChooseFBConfig_PTR local_glXChooseFBConfig;
            if (local_glXChooseFBConfig == NULL) {
                local_glXChooseFBConfig = (glXChooseFBConfig_PTR)dlsym(g_libgl, "glXChooseFBConfig");
                if (! local_glXChooseFBConfig) {
                    printf("Warning: Unable to dlsym 'glXChooseFBConfig'\n");
                    return;
                }
            }

            INDEXED_GLXFBConfig___GENPT___Display___GENPT___int_const_int___GENPT___int___GENPT__ *unpacked = (INDEXED_GLXFBConfig___GENPT___Display___GENPT___int_const_int___GENPT___int___GENPT__ *)packed;
            ARGS_GLXFBConfig___GENPT___Display___GENPT___int_const_int___GENPT___int___GENPT__ args = unpacked->args;
            GLXFBConfig * *ret = (GLXFBConfig * *)ret_v;
            *ret =
            local_glXChooseFBConfig(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glXChooseVisual
        case glXChooseVisual_INDEX: {
            static glXChooseVisual_PTR local_glXChooseVisual;
            if (local_glXChooseVisual == NULL) {
                local_glXChooseVisual = (glXChooseVisual_PTR)dlsym(g_libgl, "glXChooseVisual");
                if (! local_glXChooseVisual) {
                    printf("Warning: Unable to dlsym 'glXChooseVisual'\n");
                    return;
                }
            }

            INDEXED_XVisualInfo___GENPT___Display___GENPT___int_int___GENPT__ *unpacked = (INDEXED_XVisualInfo___GENPT___Display___GENPT___int_int___GENPT__ *)packed;
            ARGS_XVisualInfo___GENPT___Display___GENPT___int_int___GENPT__ args = unpacked->args;
            XVisualInfo * *ret = (XVisualInfo * *)ret_v;
            *ret =
            local_glXChooseVisual(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXClientInfo
        case glXClientInfo_INDEX: {
            static glXClientInfo_PTR local_glXClientInfo;
            if (local_glXClientInfo == NULL) {
                local_glXClientInfo = (glXClientInfo_PTR)dlsym(g_libgl, "glXClientInfo");
                if (! local_glXClientInfo) {
                    printf("Warning: Unable to dlsym 'glXClientInfo'\n");
                    return;
                }
            }

            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            local_glXClientInfo();
            break;
        }
        #endif
        #ifndef skip_index_glXCopyContext
        case glXCopyContext_INDEX: {
            static glXCopyContext_PTR local_glXCopyContext;
            if (local_glXCopyContext == NULL) {
                local_glXCopyContext = (glXCopyContext_PTR)dlsym(g_libgl, "glXCopyContext");
                if (! local_glXCopyContext) {
                    printf("Warning: Unable to dlsym 'glXCopyContext'\n");
                    return;
                }
            }

            INDEXED_void_Display___GENPT___GLXContext_GLXContext_unsigned_long *unpacked = (INDEXED_void_Display___GENPT___GLXContext_GLXContext_unsigned_long *)packed;
            ARGS_void_Display___GENPT___GLXContext_GLXContext_unsigned_long args = unpacked->args;
            local_glXCopyContext(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glXCreateContext
        case glXCreateContext_INDEX: {
            static glXCreateContext_PTR local_glXCreateContext;
            if (local_glXCreateContext == NULL) {
                local_glXCreateContext = (glXCreateContext_PTR)dlsym(g_libgl, "glXCreateContext");
                if (! local_glXCreateContext) {
                    printf("Warning: Unable to dlsym 'glXCreateContext'\n");
                    return;
                }
            }

            INDEXED_GLXContext_Display___GENPT___XVisualInfo___GENPT___GLXContext_Bool *unpacked = (INDEXED_GLXContext_Display___GENPT___XVisualInfo___GENPT___GLXContext_Bool *)packed;
            ARGS_GLXContext_Display___GENPT___XVisualInfo___GENPT___GLXContext_Bool args = unpacked->args;
            GLXContext *ret = (GLXContext *)ret_v;
            *ret =
            local_glXCreateContext(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glXCreateContextWithConfigSGIX
        case glXCreateContextWithConfigSGIX_INDEX: {
            static glXCreateContextWithConfigSGIX_PTR local_glXCreateContextWithConfigSGIX;
            if (local_glXCreateContextWithConfigSGIX == NULL) {
                local_glXCreateContextWithConfigSGIX = (glXCreateContextWithConfigSGIX_PTR)dlsym(g_libgl, "glXCreateContextWithConfigSGIX");
                if (! local_glXCreateContextWithConfigSGIX) {
                    printf("Warning: Unable to dlsym 'glXCreateContextWithConfigSGIX'\n");
                    return;
                }
            }

            INDEXED_void_uint32_t_uint32_t_uint32_t_uint32_t *unpacked = (INDEXED_void_uint32_t_uint32_t_uint32_t_uint32_t *)packed;
            ARGS_void_uint32_t_uint32_t_uint32_t_uint32_t args = unpacked->args;
            local_glXCreateContextWithConfigSGIX(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glXCreateGLXPbufferSGIX
        case glXCreateGLXPbufferSGIX_INDEX: {
            static glXCreateGLXPbufferSGIX_PTR local_glXCreateGLXPbufferSGIX;
            if (local_glXCreateGLXPbufferSGIX == NULL) {
                local_glXCreateGLXPbufferSGIX = (glXCreateGLXPbufferSGIX_PTR)dlsym(g_libgl, "glXCreateGLXPbufferSGIX");
                if (! local_glXCreateGLXPbufferSGIX) {
                    printf("Warning: Unable to dlsym 'glXCreateGLXPbufferSGIX'\n");
                    return;
                }
            }

            INDEXED_void_uint32_t_uint32_t *unpacked = (INDEXED_void_uint32_t_uint32_t *)packed;
            ARGS_void_uint32_t_uint32_t args = unpacked->args;
            local_glXCreateGLXPbufferSGIX(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXCreateGLXPixmap
        case glXCreateGLXPixmap_INDEX: {
            static glXCreateGLXPixmap_PTR local_glXCreateGLXPixmap;
            if (local_glXCreateGLXPixmap == NULL) {
                local_glXCreateGLXPixmap = (glXCreateGLXPixmap_PTR)dlsym(g_libgl, "glXCreateGLXPixmap");
                if (! local_glXCreateGLXPixmap) {
                    printf("Warning: Unable to dlsym 'glXCreateGLXPixmap'\n");
                    return;
                }
            }

            INDEXED_GLXPixmap_Display___GENPT___XVisualInfo___GENPT___Pixmap *unpacked = (INDEXED_GLXPixmap_Display___GENPT___XVisualInfo___GENPT___Pixmap *)packed;
            ARGS_GLXPixmap_Display___GENPT___XVisualInfo___GENPT___Pixmap args = unpacked->args;
            GLXPixmap *ret = (GLXPixmap *)ret_v;
            *ret =
            local_glXCreateGLXPixmap(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXCreateGLXPixmapWithConfigSGIX
        case glXCreateGLXPixmapWithConfigSGIX_INDEX: {
            static glXCreateGLXPixmapWithConfigSGIX_PTR local_glXCreateGLXPixmapWithConfigSGIX;
            if (local_glXCreateGLXPixmapWithConfigSGIX == NULL) {
                local_glXCreateGLXPixmapWithConfigSGIX = (glXCreateGLXPixmapWithConfigSGIX_PTR)dlsym(g_libgl, "glXCreateGLXPixmapWithConfigSGIX");
                if (! local_glXCreateGLXPixmapWithConfigSGIX) {
                    printf("Warning: Unable to dlsym 'glXCreateGLXPixmapWithConfigSGIX'\n");
                    return;
                }
            }

            INDEXED_void_uint32_t_uint32_t_uint32_t *unpacked = (INDEXED_void_uint32_t_uint32_t_uint32_t *)packed;
            ARGS_void_uint32_t_uint32_t_uint32_t args = unpacked->args;
            local_glXCreateGLXPixmapWithConfigSGIX(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXCreateGLXVideoSourceSGIX
        case glXCreateGLXVideoSourceSGIX_INDEX: {
            static glXCreateGLXVideoSourceSGIX_PTR local_glXCreateGLXVideoSourceSGIX;
            if (local_glXCreateGLXVideoSourceSGIX == NULL) {
                local_glXCreateGLXVideoSourceSGIX = (glXCreateGLXVideoSourceSGIX_PTR)dlsym(g_libgl, "glXCreateGLXVideoSourceSGIX");
                if (! local_glXCreateGLXVideoSourceSGIX) {
                    printf("Warning: Unable to dlsym 'glXCreateGLXVideoSourceSGIX'\n");
                    return;
                }
            }

            INDEXED_void_Display___GENPT___uint32_t_uint32_t_uint32_t_uint32_t_uint32_t *unpacked = (INDEXED_void_Display___GENPT___uint32_t_uint32_t_uint32_t_uint32_t_uint32_t *)packed;
            ARGS_void_Display___GENPT___uint32_t_uint32_t_uint32_t_uint32_t_uint32_t args = unpacked->args;
            local_glXCreateGLXVideoSourceSGIX(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glXCreateNewContext
        case glXCreateNewContext_INDEX: {
            static glXCreateNewContext_PTR local_glXCreateNewContext;
            if (local_glXCreateNewContext == NULL) {
                local_glXCreateNewContext = (glXCreateNewContext_PTR)dlsym(g_libgl, "glXCreateNewContext");
                if (! local_glXCreateNewContext) {
                    printf("Warning: Unable to dlsym 'glXCreateNewContext'\n");
                    return;
                }
            }

            INDEXED_GLXContext_Display___GENPT___GLXFBConfig_int_GLXContext_Bool *unpacked = (INDEXED_GLXContext_Display___GENPT___GLXFBConfig_int_GLXContext_Bool *)packed;
            ARGS_GLXContext_Display___GENPT___GLXFBConfig_int_GLXContext_Bool args = unpacked->args;
            GLXContext *ret = (GLXContext *)ret_v;
            *ret =
            local_glXCreateNewContext(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glXCreatePbuffer
        case glXCreatePbuffer_INDEX: {
            static glXCreatePbuffer_PTR local_glXCreatePbuffer;
            if (local_glXCreatePbuffer == NULL) {
                local_glXCreatePbuffer = (glXCreatePbuffer_PTR)dlsym(g_libgl, "glXCreatePbuffer");
                if (! local_glXCreatePbuffer) {
                    printf("Warning: Unable to dlsym 'glXCreatePbuffer'\n");
                    return;
                }
            }

            INDEXED_GLXPbuffer_Display___GENPT___GLXFBConfig_const_int___GENPT__ *unpacked = (INDEXED_GLXPbuffer_Display___GENPT___GLXFBConfig_const_int___GENPT__ *)packed;
            ARGS_GLXPbuffer_Display___GENPT___GLXFBConfig_const_int___GENPT__ args = unpacked->args;
            GLXPbuffer *ret = (GLXPbuffer *)ret_v;
            *ret =
            local_glXCreatePbuffer(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXCreatePixmap
        case glXCreatePixmap_INDEX: {
            static glXCreatePixmap_PTR local_glXCreatePixmap;
            if (local_glXCreatePixmap == NULL) {
                local_glXCreatePixmap = (glXCreatePixmap_PTR)dlsym(g_libgl, "glXCreatePixmap");
                if (! local_glXCreatePixmap) {
                    printf("Warning: Unable to dlsym 'glXCreatePixmap'\n");
                    return;
                }
            }

            INDEXED_GLXPixmap_Display___GENPT___GLXFBConfig_Pixmap_const_int___GENPT__ *unpacked = (INDEXED_GLXPixmap_Display___GENPT___GLXFBConfig_Pixmap_const_int___GENPT__ *)packed;
            ARGS_GLXPixmap_Display___GENPT___GLXFBConfig_Pixmap_const_int___GENPT__ args = unpacked->args;
            GLXPixmap *ret = (GLXPixmap *)ret_v;
            *ret =
            local_glXCreatePixmap(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glXCreateWindow
        case glXCreateWindow_INDEX: {
            static glXCreateWindow_PTR local_glXCreateWindow;
            if (local_glXCreateWindow == NULL) {
                local_glXCreateWindow = (glXCreateWindow_PTR)dlsym(g_libgl, "glXCreateWindow");
                if (! local_glXCreateWindow) {
                    printf("Warning: Unable to dlsym 'glXCreateWindow'\n");
                    return;
                }
            }

            INDEXED_GLXWindow_Display___GENPT___GLXFBConfig_Window_const_int___GENPT__ *unpacked = (INDEXED_GLXWindow_Display___GENPT___GLXFBConfig_Window_const_int___GENPT__ *)packed;
            ARGS_GLXWindow_Display___GENPT___GLXFBConfig_Window_const_int___GENPT__ args = unpacked->args;
            GLXWindow *ret = (GLXWindow *)ret_v;
            *ret =
            local_glXCreateWindow(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glXDestroyContext
        case glXDestroyContext_INDEX: {
            static glXDestroyContext_PTR local_glXDestroyContext;
            if (local_glXDestroyContext == NULL) {
                local_glXDestroyContext = (glXDestroyContext_PTR)dlsym(g_libgl, "glXDestroyContext");
                if (! local_glXDestroyContext) {
                    printf("Warning: Unable to dlsym 'glXDestroyContext'\n");
                    return;
                }
            }

            INDEXED_void_Display___GENPT___GLXContext *unpacked = (INDEXED_void_Display___GENPT___GLXContext *)packed;
            ARGS_void_Display___GENPT___GLXContext args = unpacked->args;
            local_glXDestroyContext(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXDestroyGLXPbufferSGIX
        case glXDestroyGLXPbufferSGIX_INDEX: {
            static glXDestroyGLXPbufferSGIX_PTR local_glXDestroyGLXPbufferSGIX;
            if (local_glXDestroyGLXPbufferSGIX == NULL) {
                local_glXDestroyGLXPbufferSGIX = (glXDestroyGLXPbufferSGIX_PTR)dlsym(g_libgl, "glXDestroyGLXPbufferSGIX");
                if (! local_glXDestroyGLXPbufferSGIX) {
                    printf("Warning: Unable to dlsym 'glXDestroyGLXPbufferSGIX'\n");
                    return;
                }
            }

            INDEXED_void_uint32_t *unpacked = (INDEXED_void_uint32_t *)packed;
            ARGS_void_uint32_t args = unpacked->args;
            local_glXDestroyGLXPbufferSGIX(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glXDestroyGLXPixmap
        case glXDestroyGLXPixmap_INDEX: {
            static glXDestroyGLXPixmap_PTR local_glXDestroyGLXPixmap;
            if (local_glXDestroyGLXPixmap == NULL) {
                local_glXDestroyGLXPixmap = (glXDestroyGLXPixmap_PTR)dlsym(g_libgl, "glXDestroyGLXPixmap");
                if (! local_glXDestroyGLXPixmap) {
                    printf("Warning: Unable to dlsym 'glXDestroyGLXPixmap'\n");
                    return;
                }
            }

            INDEXED_void_Display___GENPT___GLXPixmap *unpacked = (INDEXED_void_Display___GENPT___GLXPixmap *)packed;
            ARGS_void_Display___GENPT___GLXPixmap args = unpacked->args;
            local_glXDestroyGLXPixmap(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXDestroyGLXVideoSourceSGIX
        case glXDestroyGLXVideoSourceSGIX_INDEX: {
            static glXDestroyGLXVideoSourceSGIX_PTR local_glXDestroyGLXVideoSourceSGIX;
            if (local_glXDestroyGLXVideoSourceSGIX == NULL) {
                local_glXDestroyGLXVideoSourceSGIX = (glXDestroyGLXVideoSourceSGIX_PTR)dlsym(g_libgl, "glXDestroyGLXVideoSourceSGIX");
                if (! local_glXDestroyGLXVideoSourceSGIX) {
                    printf("Warning: Unable to dlsym 'glXDestroyGLXVideoSourceSGIX'\n");
                    return;
                }
            }

            INDEXED_void_Display___GENPT___uint32_t *unpacked = (INDEXED_void_Display___GENPT___uint32_t *)packed;
            ARGS_void_Display___GENPT___uint32_t args = unpacked->args;
            local_glXDestroyGLXVideoSourceSGIX(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXDestroyHyperpipeConfigSGIX
        case glXDestroyHyperpipeConfigSGIX_INDEX: {
            static glXDestroyHyperpipeConfigSGIX_PTR local_glXDestroyHyperpipeConfigSGIX;
            if (local_glXDestroyHyperpipeConfigSGIX == NULL) {
                local_glXDestroyHyperpipeConfigSGIX = (glXDestroyHyperpipeConfigSGIX_PTR)dlsym(g_libgl, "glXDestroyHyperpipeConfigSGIX");
                if (! local_glXDestroyHyperpipeConfigSGIX) {
                    printf("Warning: Unable to dlsym 'glXDestroyHyperpipeConfigSGIX'\n");
                    return;
                }
            }

            INDEXED_int_Display___GENPT___int *unpacked = (INDEXED_int_Display___GENPT___int *)packed;
            ARGS_int_Display___GENPT___int args = unpacked->args;
            int *ret = (int *)ret_v;
            *ret =
            local_glXDestroyHyperpipeConfigSGIX(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXDestroyPbuffer
        case glXDestroyPbuffer_INDEX: {
            static glXDestroyPbuffer_PTR local_glXDestroyPbuffer;
            if (local_glXDestroyPbuffer == NULL) {
                local_glXDestroyPbuffer = (glXDestroyPbuffer_PTR)dlsym(g_libgl, "glXDestroyPbuffer");
                if (! local_glXDestroyPbuffer) {
                    printf("Warning: Unable to dlsym 'glXDestroyPbuffer'\n");
                    return;
                }
            }

            INDEXED_void_Display___GENPT___GLXPbuffer *unpacked = (INDEXED_void_Display___GENPT___GLXPbuffer *)packed;
            ARGS_void_Display___GENPT___GLXPbuffer args = unpacked->args;
            local_glXDestroyPbuffer(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXDestroyPixmap
        case glXDestroyPixmap_INDEX: {
            static glXDestroyPixmap_PTR local_glXDestroyPixmap;
            if (local_glXDestroyPixmap == NULL) {
                local_glXDestroyPixmap = (glXDestroyPixmap_PTR)dlsym(g_libgl, "glXDestroyPixmap");
                if (! local_glXDestroyPixmap) {
                    printf("Warning: Unable to dlsym 'glXDestroyPixmap'\n");
                    return;
                }
            }

            INDEXED_void_Display___GENPT___GLXPixmap *unpacked = (INDEXED_void_Display___GENPT___GLXPixmap *)packed;
            ARGS_void_Display___GENPT___GLXPixmap args = unpacked->args;
            local_glXDestroyPixmap(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXDestroyWindow
        case glXDestroyWindow_INDEX: {
            static glXDestroyWindow_PTR local_glXDestroyWindow;
            if (local_glXDestroyWindow == NULL) {
                local_glXDestroyWindow = (glXDestroyWindow_PTR)dlsym(g_libgl, "glXDestroyWindow");
                if (! local_glXDestroyWindow) {
                    printf("Warning: Unable to dlsym 'glXDestroyWindow'\n");
                    return;
                }
            }

            INDEXED_void_Display___GENPT___GLXWindow *unpacked = (INDEXED_void_Display___GENPT___GLXWindow *)packed;
            ARGS_void_Display___GENPT___GLXWindow args = unpacked->args;
            local_glXDestroyWindow(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXGetClientString
        case glXGetClientString_INDEX: {
            static glXGetClientString_PTR local_glXGetClientString;
            if (local_glXGetClientString == NULL) {
                local_glXGetClientString = (glXGetClientString_PTR)dlsym(g_libgl, "glXGetClientString");
                if (! local_glXGetClientString) {
                    printf("Warning: Unable to dlsym 'glXGetClientString'\n");
                    return;
                }
            }

            INDEXED_const_char___GENPT___Display___GENPT___int *unpacked = (INDEXED_const_char___GENPT___Display___GENPT___int *)packed;
            ARGS_const_char___GENPT___Display___GENPT___int args = unpacked->args;
            const char * *ret = (const char * *)ret_v;
            *ret =
            local_glXGetClientString(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXGetConfig
        case glXGetConfig_INDEX: {
            static glXGetConfig_PTR local_glXGetConfig;
            if (local_glXGetConfig == NULL) {
                local_glXGetConfig = (glXGetConfig_PTR)dlsym(g_libgl, "glXGetConfig");
                if (! local_glXGetConfig) {
                    printf("Warning: Unable to dlsym 'glXGetConfig'\n");
                    return;
                }
            }

            INDEXED_int_Display___GENPT___XVisualInfo___GENPT___int_int___GENPT__ *unpacked = (INDEXED_int_Display___GENPT___XVisualInfo___GENPT___int_int___GENPT__ *)packed;
            ARGS_int_Display___GENPT___XVisualInfo___GENPT___int_int___GENPT__ args = unpacked->args;
            int *ret = (int *)ret_v;
            *ret =
            local_glXGetConfig(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glXGetCurrentContext
        case glXGetCurrentContext_INDEX: {
            static glXGetCurrentContext_PTR local_glXGetCurrentContext;
            if (local_glXGetCurrentContext == NULL) {
                local_glXGetCurrentContext = (glXGetCurrentContext_PTR)dlsym(g_libgl, "glXGetCurrentContext");
                if (! local_glXGetCurrentContext) {
                    printf("Warning: Unable to dlsym 'glXGetCurrentContext'\n");
                    return;
                }
            }

            INDEXED_GLXContext *unpacked = (INDEXED_GLXContext *)packed;
            ARGS_GLXContext args = unpacked->args;
            GLXContext *ret = (GLXContext *)ret_v;
            *ret =
            local_glXGetCurrentContext();
            break;
        }
        #endif
        #ifndef skip_index_glXGetCurrentDisplay
        case glXGetCurrentDisplay_INDEX: {
            static glXGetCurrentDisplay_PTR local_glXGetCurrentDisplay;
            if (local_glXGetCurrentDisplay == NULL) {
                local_glXGetCurrentDisplay = (glXGetCurrentDisplay_PTR)dlsym(g_libgl, "glXGetCurrentDisplay");
                if (! local_glXGetCurrentDisplay) {
                    printf("Warning: Unable to dlsym 'glXGetCurrentDisplay'\n");
                    return;
                }
            }

            INDEXED_Display___GENPT__ *unpacked = (INDEXED_Display___GENPT__ *)packed;
            ARGS_Display___GENPT__ args = unpacked->args;
            Display * *ret = (Display * *)ret_v;
            *ret =
            local_glXGetCurrentDisplay();
            break;
        }
        #endif
        #ifndef skip_index_glXGetCurrentDrawable
        case glXGetCurrentDrawable_INDEX: {
            static glXGetCurrentDrawable_PTR local_glXGetCurrentDrawable;
            if (local_glXGetCurrentDrawable == NULL) {
                local_glXGetCurrentDrawable = (glXGetCurrentDrawable_PTR)dlsym(g_libgl, "glXGetCurrentDrawable");
                if (! local_glXGetCurrentDrawable) {
                    printf("Warning: Unable to dlsym 'glXGetCurrentDrawable'\n");
                    return;
                }
            }

            INDEXED_GLXDrawable *unpacked = (INDEXED_GLXDrawable *)packed;
            ARGS_GLXDrawable args = unpacked->args;
            GLXDrawable *ret = (GLXDrawable *)ret_v;
            *ret =
            local_glXGetCurrentDrawable();
            break;
        }
        #endif
        #ifndef skip_index_glXGetCurrentReadDrawable
        case glXGetCurrentReadDrawable_INDEX: {
            static glXGetCurrentReadDrawable_PTR local_glXGetCurrentReadDrawable;
            if (local_glXGetCurrentReadDrawable == NULL) {
                local_glXGetCurrentReadDrawable = (glXGetCurrentReadDrawable_PTR)dlsym(g_libgl, "glXGetCurrentReadDrawable");
                if (! local_glXGetCurrentReadDrawable) {
                    printf("Warning: Unable to dlsym 'glXGetCurrentReadDrawable'\n");
                    return;
                }
            }

            INDEXED_GLXDrawable *unpacked = (INDEXED_GLXDrawable *)packed;
            ARGS_GLXDrawable args = unpacked->args;
            GLXDrawable *ret = (GLXDrawable *)ret_v;
            *ret =
            local_glXGetCurrentReadDrawable();
            break;
        }
        #endif
        #ifndef skip_index_glXGetDrawableAttributes
        case glXGetDrawableAttributes_INDEX: {
            static glXGetDrawableAttributes_PTR local_glXGetDrawableAttributes;
            if (local_glXGetDrawableAttributes == NULL) {
                local_glXGetDrawableAttributes = (glXGetDrawableAttributes_PTR)dlsym(g_libgl, "glXGetDrawableAttributes");
                if (! local_glXGetDrawableAttributes) {
                    printf("Warning: Unable to dlsym 'glXGetDrawableAttributes'\n");
                    return;
                }
            }

            INDEXED_void_uint32_t *unpacked = (INDEXED_void_uint32_t *)packed;
            ARGS_void_uint32_t args = unpacked->args;
            local_glXGetDrawableAttributes(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glXGetDrawableAttributesSGIX
        case glXGetDrawableAttributesSGIX_INDEX: {
            static glXGetDrawableAttributesSGIX_PTR local_glXGetDrawableAttributesSGIX;
            if (local_glXGetDrawableAttributesSGIX == NULL) {
                local_glXGetDrawableAttributesSGIX = (glXGetDrawableAttributesSGIX_PTR)dlsym(g_libgl, "glXGetDrawableAttributesSGIX");
                if (! local_glXGetDrawableAttributesSGIX) {
                    printf("Warning: Unable to dlsym 'glXGetDrawableAttributesSGIX'\n");
                    return;
                }
            }

            INDEXED_void_uint32_t *unpacked = (INDEXED_void_uint32_t *)packed;
            ARGS_void_uint32_t args = unpacked->args;
            local_glXGetDrawableAttributesSGIX(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glXGetFBConfigAttrib
        case glXGetFBConfigAttrib_INDEX: {
            static glXGetFBConfigAttrib_PTR local_glXGetFBConfigAttrib;
            if (local_glXGetFBConfigAttrib == NULL) {
                local_glXGetFBConfigAttrib = (glXGetFBConfigAttrib_PTR)dlsym(g_libgl, "glXGetFBConfigAttrib");
                if (! local_glXGetFBConfigAttrib) {
                    printf("Warning: Unable to dlsym 'glXGetFBConfigAttrib'\n");
                    return;
                }
            }

            INDEXED_int_Display___GENPT___GLXFBConfig_int_int___GENPT__ *unpacked = (INDEXED_int_Display___GENPT___GLXFBConfig_int_int___GENPT__ *)packed;
            ARGS_int_Display___GENPT___GLXFBConfig_int_int___GENPT__ args = unpacked->args;
            int *ret = (int *)ret_v;
            *ret =
            local_glXGetFBConfigAttrib(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glXGetFBConfigs
        case glXGetFBConfigs_INDEX: {
            static glXGetFBConfigs_PTR local_glXGetFBConfigs;
            if (local_glXGetFBConfigs == NULL) {
                local_glXGetFBConfigs = (glXGetFBConfigs_PTR)dlsym(g_libgl, "glXGetFBConfigs");
                if (! local_glXGetFBConfigs) {
                    printf("Warning: Unable to dlsym 'glXGetFBConfigs'\n");
                    return;
                }
            }

            INDEXED_GLXFBConfig___GENPT___Display___GENPT___int_int___GENPT__ *unpacked = (INDEXED_GLXFBConfig___GENPT___Display___GENPT___int_int___GENPT__ *)packed;
            ARGS_GLXFBConfig___GENPT___Display___GENPT___int_int___GENPT__ args = unpacked->args;
            GLXFBConfig * *ret = (GLXFBConfig * *)ret_v;
            *ret =
            local_glXGetFBConfigs(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXGetFBConfigsSGIX
        case glXGetFBConfigsSGIX_INDEX: {
            static glXGetFBConfigsSGIX_PTR local_glXGetFBConfigsSGIX;
            if (local_glXGetFBConfigsSGIX == NULL) {
                local_glXGetFBConfigsSGIX = (glXGetFBConfigsSGIX_PTR)dlsym(g_libgl, "glXGetFBConfigsSGIX");
                if (! local_glXGetFBConfigsSGIX) {
                    printf("Warning: Unable to dlsym 'glXGetFBConfigsSGIX'\n");
                    return;
                }
            }

            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            local_glXGetFBConfigsSGIX();
            break;
        }
        #endif
        #ifndef skip_index_glXGetProcAddress
        case glXGetProcAddress_INDEX: {
            static glXGetProcAddress_PTR local_glXGetProcAddress;
            if (local_glXGetProcAddress == NULL) {
                local_glXGetProcAddress = (glXGetProcAddress_PTR)dlsym(g_libgl, "glXGetProcAddress");
                if (! local_glXGetProcAddress) {
                    printf("Warning: Unable to dlsym 'glXGetProcAddress'\n");
                    return;
                }
            }

            INDEXED___GLXextFuncPtr_const_GLubyte___GENPT__ *unpacked = (INDEXED___GLXextFuncPtr_const_GLubyte___GENPT__ *)packed;
            ARGS___GLXextFuncPtr_const_GLubyte___GENPT__ args = unpacked->args;
            __GLXextFuncPtr *ret = (__GLXextFuncPtr *)ret_v;
            *ret =
            local_glXGetProcAddress(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glXGetSelectedEvent
        case glXGetSelectedEvent_INDEX: {
            static glXGetSelectedEvent_PTR local_glXGetSelectedEvent;
            if (local_glXGetSelectedEvent == NULL) {
                local_glXGetSelectedEvent = (glXGetSelectedEvent_PTR)dlsym(g_libgl, "glXGetSelectedEvent");
                if (! local_glXGetSelectedEvent) {
                    printf("Warning: Unable to dlsym 'glXGetSelectedEvent'\n");
                    return;
                }
            }

            INDEXED_void_Display___GENPT___GLXDrawable_unsigned_long___GENPT__ *unpacked = (INDEXED_void_Display___GENPT___GLXDrawable_unsigned_long___GENPT__ *)packed;
            ARGS_void_Display___GENPT___GLXDrawable_unsigned_long___GENPT__ args = unpacked->args;
            local_glXGetSelectedEvent(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXGetVisualConfigs
        case glXGetVisualConfigs_INDEX: {
            static glXGetVisualConfigs_PTR local_glXGetVisualConfigs;
            if (local_glXGetVisualConfigs == NULL) {
                local_glXGetVisualConfigs = (glXGetVisualConfigs_PTR)dlsym(g_libgl, "glXGetVisualConfigs");
                if (! local_glXGetVisualConfigs) {
                    printf("Warning: Unable to dlsym 'glXGetVisualConfigs'\n");
                    return;
                }
            }

            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            local_glXGetVisualConfigs();
            break;
        }
        #endif
        #ifndef skip_index_glXGetVisualFromFBConfig
        case glXGetVisualFromFBConfig_INDEX: {
            static glXGetVisualFromFBConfig_PTR local_glXGetVisualFromFBConfig;
            if (local_glXGetVisualFromFBConfig == NULL) {
                local_glXGetVisualFromFBConfig = (glXGetVisualFromFBConfig_PTR)dlsym(g_libgl, "glXGetVisualFromFBConfig");
                if (! local_glXGetVisualFromFBConfig) {
                    printf("Warning: Unable to dlsym 'glXGetVisualFromFBConfig'\n");
                    return;
                }
            }

            INDEXED_XVisualInfo___GENPT___Display___GENPT___GLXFBConfig *unpacked = (INDEXED_XVisualInfo___GENPT___Display___GENPT___GLXFBConfig *)packed;
            ARGS_XVisualInfo___GENPT___Display___GENPT___GLXFBConfig args = unpacked->args;
            XVisualInfo * *ret = (XVisualInfo * *)ret_v;
            *ret =
            local_glXGetVisualFromFBConfig(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXHyperpipeAttribSGIX
        case glXHyperpipeAttribSGIX_INDEX: {
            static glXHyperpipeAttribSGIX_PTR local_glXHyperpipeAttribSGIX;
            if (local_glXHyperpipeAttribSGIX == NULL) {
                local_glXHyperpipeAttribSGIX = (glXHyperpipeAttribSGIX_PTR)dlsym(g_libgl, "glXHyperpipeAttribSGIX");
                if (! local_glXHyperpipeAttribSGIX) {
                    printf("Warning: Unable to dlsym 'glXHyperpipeAttribSGIX'\n");
                    return;
                }
            }

            INDEXED_int_Display___GENPT___int_int_int_const_void___GENPT__ *unpacked = (INDEXED_int_Display___GENPT___int_int_int_const_void___GENPT__ *)packed;
            ARGS_int_Display___GENPT___int_int_int_const_void___GENPT__ args = unpacked->args;
            int *ret = (int *)ret_v;
            *ret =
            local_glXHyperpipeAttribSGIX(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glXHyperpipeConfigSGIX
        case glXHyperpipeConfigSGIX_INDEX: {
            static glXHyperpipeConfigSGIX_PTR local_glXHyperpipeConfigSGIX;
            if (local_glXHyperpipeConfigSGIX == NULL) {
                local_glXHyperpipeConfigSGIX = (glXHyperpipeConfigSGIX_PTR)dlsym(g_libgl, "glXHyperpipeConfigSGIX");
                if (! local_glXHyperpipeConfigSGIX) {
                    printf("Warning: Unable to dlsym 'glXHyperpipeConfigSGIX'\n");
                    return;
                }
            }

            INDEXED_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__ *unpacked = (INDEXED_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__ *)packed;
            ARGS_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__ args = unpacked->args;
            int *ret = (int *)ret_v;
            *ret =
            local_glXHyperpipeConfigSGIX(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glXIsDirect
        case glXIsDirect_INDEX: {
            static glXIsDirect_PTR local_glXIsDirect;
            if (local_glXIsDirect == NULL) {
                local_glXIsDirect = (glXIsDirect_PTR)dlsym(g_libgl, "glXIsDirect");
                if (! local_glXIsDirect) {
                    printf("Warning: Unable to dlsym 'glXIsDirect'\n");
                    return;
                }
            }

            INDEXED_Bool_Display___GENPT___GLXContext *unpacked = (INDEXED_Bool_Display___GENPT___GLXContext *)packed;
            ARGS_Bool_Display___GENPT___GLXContext args = unpacked->args;
            Bool *ret = (Bool *)ret_v;
            *ret =
            local_glXIsDirect(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXJoinSwapGroupSGIX
        case glXJoinSwapGroupSGIX_INDEX: {
            static glXJoinSwapGroupSGIX_PTR local_glXJoinSwapGroupSGIX;
            if (local_glXJoinSwapGroupSGIX == NULL) {
                local_glXJoinSwapGroupSGIX = (glXJoinSwapGroupSGIX_PTR)dlsym(g_libgl, "glXJoinSwapGroupSGIX");
                if (! local_glXJoinSwapGroupSGIX) {
                    printf("Warning: Unable to dlsym 'glXJoinSwapGroupSGIX'\n");
                    return;
                }
            }

            INDEXED_void_uint32_t_uint32_t *unpacked = (INDEXED_void_uint32_t_uint32_t *)packed;
            ARGS_void_uint32_t_uint32_t args = unpacked->args;
            local_glXJoinSwapGroupSGIX(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXMakeContextCurrent
        case glXMakeContextCurrent_INDEX: {
            static glXMakeContextCurrent_PTR local_glXMakeContextCurrent;
            if (local_glXMakeContextCurrent == NULL) {
                local_glXMakeContextCurrent = (glXMakeContextCurrent_PTR)dlsym(g_libgl, "glXMakeContextCurrent");
                if (! local_glXMakeContextCurrent) {
                    printf("Warning: Unable to dlsym 'glXMakeContextCurrent'\n");
                    return;
                }
            }

            INDEXED_Bool_Display___GENPT___GLXDrawable_GLXDrawable_GLXContext *unpacked = (INDEXED_Bool_Display___GENPT___GLXDrawable_GLXDrawable_GLXContext *)packed;
            ARGS_Bool_Display___GENPT___GLXDrawable_GLXDrawable_GLXContext args = unpacked->args;
            Bool *ret = (Bool *)ret_v;
            *ret =
            local_glXMakeContextCurrent(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glXMakeCurrent
        case glXMakeCurrent_INDEX: {
            static glXMakeCurrent_PTR local_glXMakeCurrent;
            if (local_glXMakeCurrent == NULL) {
                local_glXMakeCurrent = (glXMakeCurrent_PTR)dlsym(g_libgl, "glXMakeCurrent");
                if (! local_glXMakeCurrent) {
                    printf("Warning: Unable to dlsym 'glXMakeCurrent'\n");
                    return;
                }
            }

            INDEXED_Bool_Display___GENPT___GLXDrawable_GLXContext *unpacked = (INDEXED_Bool_Display___GENPT___GLXDrawable_GLXContext *)packed;
            ARGS_Bool_Display___GENPT___GLXDrawable_GLXContext args = unpacked->args;
            Bool *ret = (Bool *)ret_v;
            *ret =
            local_glXMakeCurrent(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXMakeCurrentReadSGI
        case glXMakeCurrentReadSGI_INDEX: {
            static glXMakeCurrentReadSGI_PTR local_glXMakeCurrentReadSGI;
            if (local_glXMakeCurrentReadSGI == NULL) {
                local_glXMakeCurrentReadSGI = (glXMakeCurrentReadSGI_PTR)dlsym(g_libgl, "glXMakeCurrentReadSGI");
                if (! local_glXMakeCurrentReadSGI) {
                    printf("Warning: Unable to dlsym 'glXMakeCurrentReadSGI'\n");
                    return;
                }
            }

            INDEXED_void_uint32_t_uint32_t_uint32_t *unpacked = (INDEXED_void_uint32_t_uint32_t_uint32_t *)packed;
            ARGS_void_uint32_t_uint32_t_uint32_t args = unpacked->args;
            local_glXMakeCurrentReadSGI(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXQueryContext
        case glXQueryContext_INDEX: {
            static glXQueryContext_PTR local_glXQueryContext;
            if (local_glXQueryContext == NULL) {
                local_glXQueryContext = (glXQueryContext_PTR)dlsym(g_libgl, "glXQueryContext");
                if (! local_glXQueryContext) {
                    printf("Warning: Unable to dlsym 'glXQueryContext'\n");
                    return;
                }
            }

            INDEXED_int_Display___GENPT___GLXContext_int_int___GENPT__ *unpacked = (INDEXED_int_Display___GENPT___GLXContext_int_int___GENPT__ *)packed;
            ARGS_int_Display___GENPT___GLXContext_int_int___GENPT__ args = unpacked->args;
            int *ret = (int *)ret_v;
            *ret =
            local_glXQueryContext(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glXQueryContextInfoEXT
        case glXQueryContextInfoEXT_INDEX: {
            static glXQueryContextInfoEXT_PTR local_glXQueryContextInfoEXT;
            if (local_glXQueryContextInfoEXT == NULL) {
                local_glXQueryContextInfoEXT = (glXQueryContextInfoEXT_PTR)dlsym(g_libgl, "glXQueryContextInfoEXT");
                if (! local_glXQueryContextInfoEXT) {
                    printf("Warning: Unable to dlsym 'glXQueryContextInfoEXT'\n");
                    return;
                }
            }

            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            local_glXQueryContextInfoEXT();
            break;
        }
        #endif
        #ifndef skip_index_glXQueryDrawable
        case glXQueryDrawable_INDEX: {
            static glXQueryDrawable_PTR local_glXQueryDrawable;
            if (local_glXQueryDrawable == NULL) {
                local_glXQueryDrawable = (glXQueryDrawable_PTR)dlsym(g_libgl, "glXQueryDrawable");
                if (! local_glXQueryDrawable) {
                    printf("Warning: Unable to dlsym 'glXQueryDrawable'\n");
                    return;
                }
            }

            INDEXED_void_Display___GENPT___GLXDrawable_int_unsigned_int___GENPT__ *unpacked = (INDEXED_void_Display___GENPT___GLXDrawable_int_unsigned_int___GENPT__ *)packed;
            ARGS_void_Display___GENPT___GLXDrawable_int_unsigned_int___GENPT__ args = unpacked->args;
            local_glXQueryDrawable(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glXQueryExtension
        case glXQueryExtension_INDEX: {
            static glXQueryExtension_PTR local_glXQueryExtension;
            if (local_glXQueryExtension == NULL) {
                local_glXQueryExtension = (glXQueryExtension_PTR)dlsym(g_libgl, "glXQueryExtension");
                if (! local_glXQueryExtension) {
                    printf("Warning: Unable to dlsym 'glXQueryExtension'\n");
                    return;
                }
            }

            INDEXED_Bool_Display___GENPT___int___GENPT___int___GENPT__ *unpacked = (INDEXED_Bool_Display___GENPT___int___GENPT___int___GENPT__ *)packed;
            ARGS_Bool_Display___GENPT___int___GENPT___int___GENPT__ args = unpacked->args;
            Bool *ret = (Bool *)ret_v;
            *ret =
            local_glXQueryExtension(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXQueryExtensionsString
        case glXQueryExtensionsString_INDEX: {
            static glXQueryExtensionsString_PTR local_glXQueryExtensionsString;
            if (local_glXQueryExtensionsString == NULL) {
                local_glXQueryExtensionsString = (glXQueryExtensionsString_PTR)dlsym(g_libgl, "glXQueryExtensionsString");
                if (! local_glXQueryExtensionsString) {
                    printf("Warning: Unable to dlsym 'glXQueryExtensionsString'\n");
                    return;
                }
            }

            INDEXED_const_char___GENPT___Display___GENPT___int *unpacked = (INDEXED_const_char___GENPT___Display___GENPT___int *)packed;
            ARGS_const_char___GENPT___Display___GENPT___int args = unpacked->args;
            const char * *ret = (const char * *)ret_v;
            *ret =
            local_glXQueryExtensionsString(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXQueryHyperpipeAttribSGIX
        case glXQueryHyperpipeAttribSGIX_INDEX: {
            static glXQueryHyperpipeAttribSGIX_PTR local_glXQueryHyperpipeAttribSGIX;
            if (local_glXQueryHyperpipeAttribSGIX == NULL) {
                local_glXQueryHyperpipeAttribSGIX = (glXQueryHyperpipeAttribSGIX_PTR)dlsym(g_libgl, "glXQueryHyperpipeAttribSGIX");
                if (! local_glXQueryHyperpipeAttribSGIX) {
                    printf("Warning: Unable to dlsym 'glXQueryHyperpipeAttribSGIX'\n");
                    return;
                }
            }

            INDEXED_int_Display___GENPT___int_int_int_const_void___GENPT__ *unpacked = (INDEXED_int_Display___GENPT___int_int_int_const_void___GENPT__ *)packed;
            ARGS_int_Display___GENPT___int_int_int_const_void___GENPT__ args = unpacked->args;
            int *ret = (int *)ret_v;
            *ret =
            local_glXQueryHyperpipeAttribSGIX(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glXQueryHyperpipeBestAttribSGIX
        case glXQueryHyperpipeBestAttribSGIX_INDEX: {
            static glXQueryHyperpipeBestAttribSGIX_PTR local_glXQueryHyperpipeBestAttribSGIX;
            if (local_glXQueryHyperpipeBestAttribSGIX == NULL) {
                local_glXQueryHyperpipeBestAttribSGIX = (glXQueryHyperpipeBestAttribSGIX_PTR)dlsym(g_libgl, "glXQueryHyperpipeBestAttribSGIX");
                if (! local_glXQueryHyperpipeBestAttribSGIX) {
                    printf("Warning: Unable to dlsym 'glXQueryHyperpipeBestAttribSGIX'\n");
                    return;
                }
            }

            INDEXED_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__ *unpacked = (INDEXED_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__ *)packed;
            ARGS_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__ args = unpacked->args;
            int *ret = (int *)ret_v;
            *ret =
            local_glXQueryHyperpipeBestAttribSGIX(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glXQueryHyperpipeConfigSGIX
        case glXQueryHyperpipeConfigSGIX_INDEX: {
            static glXQueryHyperpipeConfigSGIX_PTR local_glXQueryHyperpipeConfigSGIX;
            if (local_glXQueryHyperpipeConfigSGIX == NULL) {
                local_glXQueryHyperpipeConfigSGIX = (glXQueryHyperpipeConfigSGIX_PTR)dlsym(g_libgl, "glXQueryHyperpipeConfigSGIX");
                if (! local_glXQueryHyperpipeConfigSGIX) {
                    printf("Warning: Unable to dlsym 'glXQueryHyperpipeConfigSGIX'\n");
                    return;
                }
            }

            INDEXED_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__ *unpacked = (INDEXED_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__ *)packed;
            ARGS_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__ args = unpacked->args;
            GLXHyperpipeConfigSGIX * *ret = (GLXHyperpipeConfigSGIX * *)ret_v;
            *ret =
            local_glXQueryHyperpipeConfigSGIX(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXQueryHyperpipeNetworkSGIX
        case glXQueryHyperpipeNetworkSGIX_INDEX: {
            static glXQueryHyperpipeNetworkSGIX_PTR local_glXQueryHyperpipeNetworkSGIX;
            if (local_glXQueryHyperpipeNetworkSGIX == NULL) {
                local_glXQueryHyperpipeNetworkSGIX = (glXQueryHyperpipeNetworkSGIX_PTR)dlsym(g_libgl, "glXQueryHyperpipeNetworkSGIX");
                if (! local_glXQueryHyperpipeNetworkSGIX) {
                    printf("Warning: Unable to dlsym 'glXQueryHyperpipeNetworkSGIX'\n");
                    return;
                }
            }

            INDEXED_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__ *unpacked = (INDEXED_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__ *)packed;
            ARGS_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__ args = unpacked->args;
            GLXHyperpipeNetworkSGIX * *ret = (GLXHyperpipeNetworkSGIX * *)ret_v;
            *ret =
            local_glXQueryHyperpipeNetworkSGIX(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXQueryMaxSwapBarriersSGIX
        case glXQueryMaxSwapBarriersSGIX_INDEX: {
            static glXQueryMaxSwapBarriersSGIX_PTR local_glXQueryMaxSwapBarriersSGIX;
            if (local_glXQueryMaxSwapBarriersSGIX == NULL) {
                local_glXQueryMaxSwapBarriersSGIX = (glXQueryMaxSwapBarriersSGIX_PTR)dlsym(g_libgl, "glXQueryMaxSwapBarriersSGIX");
                if (! local_glXQueryMaxSwapBarriersSGIX) {
                    printf("Warning: Unable to dlsym 'glXQueryMaxSwapBarriersSGIX'\n");
                    return;
                }
            }

            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            local_glXQueryMaxSwapBarriersSGIX();
            break;
        }
        #endif
        #ifndef skip_index_glXQueryServerString
        case glXQueryServerString_INDEX: {
            static glXQueryServerString_PTR local_glXQueryServerString;
            if (local_glXQueryServerString == NULL) {
                local_glXQueryServerString = (glXQueryServerString_PTR)dlsym(g_libgl, "glXQueryServerString");
                if (! local_glXQueryServerString) {
                    printf("Warning: Unable to dlsym 'glXQueryServerString'\n");
                    return;
                }
            }

            INDEXED_const_char___GENPT___Display___GENPT___int_int *unpacked = (INDEXED_const_char___GENPT___Display___GENPT___int_int *)packed;
            ARGS_const_char___GENPT___Display___GENPT___int_int args = unpacked->args;
            const char * *ret = (const char * *)ret_v;
            *ret =
            local_glXQueryServerString(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXQueryVersion
        case glXQueryVersion_INDEX: {
            static glXQueryVersion_PTR local_glXQueryVersion;
            if (local_glXQueryVersion == NULL) {
                local_glXQueryVersion = (glXQueryVersion_PTR)dlsym(g_libgl, "glXQueryVersion");
                if (! local_glXQueryVersion) {
                    printf("Warning: Unable to dlsym 'glXQueryVersion'\n");
                    return;
                }
            }

            INDEXED_Bool_Display___GENPT___int___GENPT___int___GENPT__ *unpacked = (INDEXED_Bool_Display___GENPT___int___GENPT___int___GENPT__ *)packed;
            ARGS_Bool_Display___GENPT___int___GENPT___int___GENPT__ args = unpacked->args;
            Bool *ret = (Bool *)ret_v;
            *ret =
            local_glXQueryVersion(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXRender
        case glXRender_INDEX: {
            static glXRender_PTR local_glXRender;
            if (local_glXRender == NULL) {
                local_glXRender = (glXRender_PTR)dlsym(g_libgl, "glXRender");
                if (! local_glXRender) {
                    printf("Warning: Unable to dlsym 'glXRender'\n");
                    return;
                }
            }

            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            local_glXRender();
            break;
        }
        #endif
        #ifndef skip_index_glXRenderLarge
        case glXRenderLarge_INDEX: {
            static glXRenderLarge_PTR local_glXRenderLarge;
            if (local_glXRenderLarge == NULL) {
                local_glXRenderLarge = (glXRenderLarge_PTR)dlsym(g_libgl, "glXRenderLarge");
                if (! local_glXRenderLarge) {
                    printf("Warning: Unable to dlsym 'glXRenderLarge'\n");
                    return;
                }
            }

            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            local_glXRenderLarge();
            break;
        }
        #endif
        #ifndef skip_index_glXSelectEvent
        case glXSelectEvent_INDEX: {
            static glXSelectEvent_PTR local_glXSelectEvent;
            if (local_glXSelectEvent == NULL) {
                local_glXSelectEvent = (glXSelectEvent_PTR)dlsym(g_libgl, "glXSelectEvent");
                if (! local_glXSelectEvent) {
                    printf("Warning: Unable to dlsym 'glXSelectEvent'\n");
                    return;
                }
            }

            INDEXED_void_Display___GENPT___GLXDrawable_unsigned_long *unpacked = (INDEXED_void_Display___GENPT___GLXDrawable_unsigned_long *)packed;
            ARGS_void_Display___GENPT___GLXDrawable_unsigned_long args = unpacked->args;
            local_glXSelectEvent(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXSwapBuffers
        case glXSwapBuffers_INDEX: {
            static glXSwapBuffers_PTR local_glXSwapBuffers;
            if (local_glXSwapBuffers == NULL) {
                local_glXSwapBuffers = (glXSwapBuffers_PTR)dlsym(g_libgl, "glXSwapBuffers");
                if (! local_glXSwapBuffers) {
                    printf("Warning: Unable to dlsym 'glXSwapBuffers'\n");
                    return;
                }
            }

            INDEXED_void_Display___GENPT___GLXDrawable *unpacked = (INDEXED_void_Display___GENPT___GLXDrawable *)packed;
            ARGS_void_Display___GENPT___GLXDrawable args = unpacked->args;
            local_glXSwapBuffers(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXSwapIntervalSGI
        case glXSwapIntervalSGI_INDEX: {
            static glXSwapIntervalSGI_PTR local_glXSwapIntervalSGI;
            if (local_glXSwapIntervalSGI == NULL) {
                local_glXSwapIntervalSGI = (glXSwapIntervalSGI_PTR)dlsym(g_libgl, "glXSwapIntervalSGI");
                if (! local_glXSwapIntervalSGI) {
                    printf("Warning: Unable to dlsym 'glXSwapIntervalSGI'\n");
                    return;
                }
            }

            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            local_glXSwapIntervalSGI();
            break;
        }
        #endif
        #ifndef skip_index_glXUseXFont
        case glXUseXFont_INDEX: {
            static glXUseXFont_PTR local_glXUseXFont;
            if (local_glXUseXFont == NULL) {
                local_glXUseXFont = (glXUseXFont_PTR)dlsym(g_libgl, "glXUseXFont");
                if (! local_glXUseXFont) {
                    printf("Warning: Unable to dlsym 'glXUseXFont'\n");
                    return;
                }
            }

            INDEXED_void_Font_int_int_int *unpacked = (INDEXED_void_Font_int_int_int *)packed;
            ARGS_void_Font_int_int_int args = unpacked->args;
            local_glXUseXFont(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glXVendorPrivate
        case glXVendorPrivate_INDEX: {
            static glXVendorPrivate_PTR local_glXVendorPrivate;
            if (local_glXVendorPrivate == NULL) {
                local_glXVendorPrivate = (glXVendorPrivate_PTR)dlsym(g_libgl, "glXVendorPrivate");
                if (! local_glXVendorPrivate) {
                    printf("Warning: Unable to dlsym 'glXVendorPrivate'\n");
                    return;
                }
            }

            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            local_glXVendorPrivate();
            break;
        }
        #endif
        #ifndef skip_index_glXVendorPrivateWithReply
        case glXVendorPrivateWithReply_INDEX: {
            static glXVendorPrivateWithReply_PTR local_glXVendorPrivateWithReply;
            if (local_glXVendorPrivateWithReply == NULL) {
                local_glXVendorPrivateWithReply = (glXVendorPrivateWithReply_PTR)dlsym(g_libgl, "glXVendorPrivateWithReply");
                if (! local_glXVendorPrivateWithReply) {
                    printf("Warning: Unable to dlsym 'glXVendorPrivateWithReply'\n");
                    return;
                }
            }

            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            local_glXVendorPrivateWithReply();
            break;
        }
        #endif
        #ifndef skip_index_glXWaitGL
        case glXWaitGL_INDEX: {
            static glXWaitGL_PTR local_glXWaitGL;
            if (local_glXWaitGL == NULL) {
                local_glXWaitGL = (glXWaitGL_PTR)dlsym(g_libgl, "glXWaitGL");
                if (! local_glXWaitGL) {
                    printf("Warning: Unable to dlsym 'glXWaitGL'\n");
                    return;
                }
            }

            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            local_glXWaitGL();
            break;
        }
        #endif
        #ifndef skip_index_glXWaitX
        case glXWaitX_INDEX: {
            static glXWaitX_PTR local_glXWaitX;
            if (local_glXWaitX == NULL) {
                local_glXWaitX = (glXWaitX_PTR)dlsym(g_libgl, "glXWaitX");
                if (! local_glXWaitX) {
                    printf("Warning: Unable to dlsym 'glXWaitX'\n");
                    return;
                }
            }

            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            local_glXWaitX();
            break;
        }
        #endif
    }
}
#endif
