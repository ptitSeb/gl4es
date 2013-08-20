#include "../proxy.h"

#ifndef HOST_C
#define HOST_C
void glIndexedCall(const indexed_call_t *packed, void *ret_v) {
    switch (packed->func) {
        #ifndef skip_index_glAccum
        case glAccum_INDEX: {
            INDEXED_void_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat args = unpacked->args;
            glAccum(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glActiveTexture
        case glActiveTexture_INDEX: {
            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            glActiveTexture(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glAlphaFunc
        case glAlphaFunc_INDEX: {
            INDEXED_void_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat args = unpacked->args;
            glAlphaFunc(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glAreTexturesResident
        case glAreTexturesResident_INDEX: {
            INDEXED_GLboolean_GLsizei_const_GLuint___GENPT___GLboolean___GENPT__ *unpacked = (INDEXED_GLboolean_GLsizei_const_GLuint___GENPT___GLboolean___GENPT__ *)packed;
            ARGS_GLboolean_GLsizei_const_GLuint___GENPT___GLboolean___GENPT__ args = unpacked->args;
            GLboolean *ret = (GLboolean *)ret_v;
            *ret =
            glAreTexturesResident(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glArrayElement
        case glArrayElement_INDEX: {
            INDEXED_void_GLint *unpacked = (INDEXED_void_GLint *)packed;
            ARGS_void_GLint args = unpacked->args;
            glArrayElement(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glBegin
        case glBegin_INDEX: {
            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            glBegin(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glBeginQuery
        case glBeginQuery_INDEX: {
            INDEXED_void_GLenum_GLuint *unpacked = (INDEXED_void_GLenum_GLuint *)packed;
            ARGS_void_GLenum_GLuint args = unpacked->args;
            glBeginQuery(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glBindBuffer
        case glBindBuffer_INDEX: {
            INDEXED_void_GLenum_GLuint *unpacked = (INDEXED_void_GLenum_GLuint *)packed;
            ARGS_void_GLenum_GLuint args = unpacked->args;
            glBindBuffer(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glBindTexture
        case glBindTexture_INDEX: {
            INDEXED_void_GLenum_GLuint *unpacked = (INDEXED_void_GLenum_GLuint *)packed;
            ARGS_void_GLenum_GLuint args = unpacked->args;
            glBindTexture(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glBitmap
        case glBitmap_INDEX: {
            INDEXED_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_const_GLubyte___GENPT__ *unpacked = (INDEXED_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_const_GLubyte___GENPT__ *)packed;
            ARGS_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_const_GLubyte___GENPT__ args = unpacked->args;
            glBitmap(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        #endif
        #ifndef skip_index_glBlendColor
        case glBlendColor_INDEX: {
            INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            glBlendColor(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glBlendEquation
        case glBlendEquation_INDEX: {
            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            glBlendEquation(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glBlendFunc
        case glBlendFunc_INDEX: {
            INDEXED_void_GLenum_GLenum *unpacked = (INDEXED_void_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLenum args = unpacked->args;
            glBlendFunc(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glBlendFuncSeparate
        case glBlendFuncSeparate_INDEX: {
            INDEXED_void_GLenum_GLenum_GLenum_GLenum *unpacked = (INDEXED_void_GLenum_GLenum_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLenum args = unpacked->args;
            glBlendFuncSeparate(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glBufferData
        case glBufferData_INDEX: {
            INDEXED_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum *unpacked = (INDEXED_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum *)packed;
            ARGS_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum args = unpacked->args;
            glBufferData(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glBufferSubData
        case glBufferSubData_INDEX: {
            INDEXED_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__ args = unpacked->args;
            glBufferSubData(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glCallList
        case glCallList_INDEX: {
            INDEXED_void_GLuint *unpacked = (INDEXED_void_GLuint *)packed;
            ARGS_void_GLuint args = unpacked->args;
            glCallList(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glCallLists
        case glCallLists_INDEX: {
            INDEXED_void_GLsizei_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLsizei_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLsizei_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            glCallLists(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glClear
        case glClear_INDEX: {
            INDEXED_void_GLbitfield *unpacked = (INDEXED_void_GLbitfield *)packed;
            ARGS_void_GLbitfield args = unpacked->args;
            glClear(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glClearAccum
        case glClearAccum_INDEX: {
            INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            glClearAccum(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glClearColor
        case glClearColor_INDEX: {
            INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            glClearColor(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glClearDepth
        case glClearDepth_INDEX: {
            INDEXED_void_GLdouble *unpacked = (INDEXED_void_GLdouble *)packed;
            ARGS_void_GLdouble args = unpacked->args;
            glClearDepth(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glClearIndex
        case glClearIndex_INDEX: {
            INDEXED_void_GLfloat *unpacked = (INDEXED_void_GLfloat *)packed;
            ARGS_void_GLfloat args = unpacked->args;
            glClearIndex(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glClearStencil
        case glClearStencil_INDEX: {
            INDEXED_void_GLint *unpacked = (INDEXED_void_GLint *)packed;
            ARGS_void_GLint args = unpacked->args;
            glClearStencil(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glClientActiveTexture
        case glClientActiveTexture_INDEX: {
            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            glClientActiveTexture(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glClipPlane
        case glClipPlane_INDEX: {
            INDEXED_void_GLenum_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLdouble___GENPT__ args = unpacked->args;
            glClipPlane(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glColor3b
        case glColor3b_INDEX: {
            INDEXED_void_GLbyte_GLbyte_GLbyte *unpacked = (INDEXED_void_GLbyte_GLbyte_GLbyte *)packed;
            ARGS_void_GLbyte_GLbyte_GLbyte args = unpacked->args;
            glColor3b(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glColor3bv
        case glColor3bv_INDEX: {
            INDEXED_void_const_GLbyte___GENPT__ *unpacked = (INDEXED_void_const_GLbyte___GENPT__ *)packed;
            ARGS_void_const_GLbyte___GENPT__ args = unpacked->args;
            glColor3bv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor3d
        case glColor3d_INDEX: {
            INDEXED_void_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble args = unpacked->args;
            glColor3d(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glColor3dv
        case glColor3dv_INDEX: {
            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            glColor3dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor3f
        case glColor3f_INDEX: {
            INDEXED_void_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat args = unpacked->args;
            glColor3f(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glColor3fv
        case glColor3fv_INDEX: {
            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            glColor3fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor3i
        case glColor3i_INDEX: {
            INDEXED_void_GLint_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint args = unpacked->args;
            glColor3i(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glColor3iv
        case glColor3iv_INDEX: {
            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            glColor3iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor3s
        case glColor3s_INDEX: {
            INDEXED_void_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort args = unpacked->args;
            glColor3s(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glColor3sv
        case glColor3sv_INDEX: {
            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            glColor3sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor3ub
        case glColor3ub_INDEX: {
            INDEXED_void_GLubyte_GLubyte_GLubyte *unpacked = (INDEXED_void_GLubyte_GLubyte_GLubyte *)packed;
            ARGS_void_GLubyte_GLubyte_GLubyte args = unpacked->args;
            glColor3ub(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glColor3ubv
        case glColor3ubv_INDEX: {
            INDEXED_void_const_GLubyte___GENPT__ *unpacked = (INDEXED_void_const_GLubyte___GENPT__ *)packed;
            ARGS_void_const_GLubyte___GENPT__ args = unpacked->args;
            glColor3ubv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor3ui
        case glColor3ui_INDEX: {
            INDEXED_void_GLuint_GLuint_GLuint *unpacked = (INDEXED_void_GLuint_GLuint_GLuint *)packed;
            ARGS_void_GLuint_GLuint_GLuint args = unpacked->args;
            glColor3ui(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glColor3uiv
        case glColor3uiv_INDEX: {
            INDEXED_void_const_GLuint___GENPT__ *unpacked = (INDEXED_void_const_GLuint___GENPT__ *)packed;
            ARGS_void_const_GLuint___GENPT__ args = unpacked->args;
            glColor3uiv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor3us
        case glColor3us_INDEX: {
            INDEXED_void_GLushort_GLushort_GLushort *unpacked = (INDEXED_void_GLushort_GLushort_GLushort *)packed;
            ARGS_void_GLushort_GLushort_GLushort args = unpacked->args;
            glColor3us(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glColor3usv
        case glColor3usv_INDEX: {
            INDEXED_void_const_GLushort___GENPT__ *unpacked = (INDEXED_void_const_GLushort___GENPT__ *)packed;
            ARGS_void_const_GLushort___GENPT__ args = unpacked->args;
            glColor3usv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor4b
        case glColor4b_INDEX: {
            INDEXED_void_GLbyte_GLbyte_GLbyte_GLbyte *unpacked = (INDEXED_void_GLbyte_GLbyte_GLbyte_GLbyte *)packed;
            ARGS_void_GLbyte_GLbyte_GLbyte_GLbyte args = unpacked->args;
            glColor4b(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glColor4bv
        case glColor4bv_INDEX: {
            INDEXED_void_const_GLbyte___GENPT__ *unpacked = (INDEXED_void_const_GLbyte___GENPT__ *)packed;
            ARGS_void_const_GLbyte___GENPT__ args = unpacked->args;
            glColor4bv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor4d
        case glColor4d_INDEX: {
            INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            glColor4d(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glColor4dv
        case glColor4dv_INDEX: {
            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            glColor4dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor4f
        case glColor4f_INDEX: {
            INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            glColor4f(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glColor4fv
        case glColor4fv_INDEX: {
            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            glColor4fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor4i
        case glColor4i_INDEX: {
            INDEXED_void_GLint_GLint_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint_GLint args = unpacked->args;
            glColor4i(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glColor4iv
        case glColor4iv_INDEX: {
            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            glColor4iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor4s
        case glColor4s_INDEX: {
            INDEXED_void_GLshort_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort_GLshort args = unpacked->args;
            glColor4s(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glColor4sv
        case glColor4sv_INDEX: {
            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            glColor4sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor4ub
        case glColor4ub_INDEX: {
            INDEXED_void_GLubyte_GLubyte_GLubyte_GLubyte *unpacked = (INDEXED_void_GLubyte_GLubyte_GLubyte_GLubyte *)packed;
            ARGS_void_GLubyte_GLubyte_GLubyte_GLubyte args = unpacked->args;
            glColor4ub(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glColor4ubv
        case glColor4ubv_INDEX: {
            INDEXED_void_const_GLubyte___GENPT__ *unpacked = (INDEXED_void_const_GLubyte___GENPT__ *)packed;
            ARGS_void_const_GLubyte___GENPT__ args = unpacked->args;
            glColor4ubv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor4ui
        case glColor4ui_INDEX: {
            INDEXED_void_GLuint_GLuint_GLuint_GLuint *unpacked = (INDEXED_void_GLuint_GLuint_GLuint_GLuint *)packed;
            ARGS_void_GLuint_GLuint_GLuint_GLuint args = unpacked->args;
            glColor4ui(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glColor4uiv
        case glColor4uiv_INDEX: {
            INDEXED_void_const_GLuint___GENPT__ *unpacked = (INDEXED_void_const_GLuint___GENPT__ *)packed;
            ARGS_void_const_GLuint___GENPT__ args = unpacked->args;
            glColor4uiv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColor4us
        case glColor4us_INDEX: {
            INDEXED_void_GLushort_GLushort_GLushort_GLushort *unpacked = (INDEXED_void_GLushort_GLushort_GLushort_GLushort *)packed;
            ARGS_void_GLushort_GLushort_GLushort_GLushort args = unpacked->args;
            glColor4us(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glColor4usv
        case glColor4usv_INDEX: {
            INDEXED_void_const_GLushort___GENPT__ *unpacked = (INDEXED_void_const_GLushort___GENPT__ *)packed;
            ARGS_void_const_GLushort___GENPT__ args = unpacked->args;
            glColor4usv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glColorMask
        case glColorMask_INDEX: {
            INDEXED_void_GLboolean_GLboolean_GLboolean_GLboolean *unpacked = (INDEXED_void_GLboolean_GLboolean_GLboolean_GLboolean *)packed;
            ARGS_void_GLboolean_GLboolean_GLboolean_GLboolean args = unpacked->args;
            glColorMask(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glColorMaterial
        case glColorMaterial_INDEX: {
            INDEXED_void_GLenum_GLenum *unpacked = (INDEXED_void_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLenum args = unpacked->args;
            glColorMaterial(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glColorPointer
        case glColorPointer_INDEX: {
            INDEXED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            glColorPointer(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glColorSubTable
        case glColorSubTable_INDEX: {
            INDEXED_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            glColorSubTable(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glColorTable
        case glColorTable_INDEX: {
            INDEXED_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            glColorTable(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glColorTableParameterfv
        case glColorTableParameterfv_INDEX: {
            INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            glColorTableParameterfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glColorTableParameteriv
        case glColorTableParameteriv_INDEX: {
            INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLint___GENPT__ args = unpacked->args;
            glColorTableParameteriv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glCompressedTexImage1D
        case glCompressedTexImage1D_INDEX: {
            INDEXED_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            glCompressedTexImage1D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        #endif
        #ifndef skip_index_glCompressedTexImage2D
        case glCompressedTexImage2D_INDEX: {
            INDEXED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            glCompressedTexImage2D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        #endif
        #ifndef skip_index_glCompressedTexImage3D
        case glCompressedTexImage3D_INDEX: {
            INDEXED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            glCompressedTexImage3D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        #endif
        #ifndef skip_index_glCompressedTexSubImage1D
        case glCompressedTexSubImage1D_INDEX: {
            INDEXED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            glCompressedTexSubImage1D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        #endif
        #ifndef skip_index_glCompressedTexSubImage2D
        case glCompressedTexSubImage2D_INDEX: {
            INDEXED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            glCompressedTexSubImage2D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        #endif
        #ifndef skip_index_glCompressedTexSubImage3D
        case glCompressedTexSubImage3D_INDEX: {
            INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            glCompressedTexSubImage3D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11);
            break;
        }
        #endif
        #ifndef skip_index_glConvolutionFilter1D
        case glConvolutionFilter1D_INDEX: {
            INDEXED_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            glConvolutionFilter1D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glConvolutionFilter2D
        case glConvolutionFilter2D_INDEX: {
            INDEXED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            glConvolutionFilter2D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        #endif
        #ifndef skip_index_glConvolutionParameterf
        case glConvolutionParameterf_INDEX: {
            INDEXED_void_GLenum_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLenum_GLfloat args = unpacked->args;
            glConvolutionParameterf(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glConvolutionParameterfv
        case glConvolutionParameterfv_INDEX: {
            INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            glConvolutionParameterfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glConvolutionParameteri
        case glConvolutionParameteri_INDEX: {
            INDEXED_void_GLenum_GLenum_GLint *unpacked = (INDEXED_void_GLenum_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLint args = unpacked->args;
            glConvolutionParameteri(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glConvolutionParameteriv
        case glConvolutionParameteriv_INDEX: {
            INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLint___GENPT__ args = unpacked->args;
            glConvolutionParameteriv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glCopyColorSubTable
        case glCopyColorSubTable_INDEX: {
            INDEXED_void_GLenum_GLsizei_GLint_GLint_GLsizei *unpacked = (INDEXED_void_GLenum_GLsizei_GLint_GLint_GLsizei *)packed;
            ARGS_void_GLenum_GLsizei_GLint_GLint_GLsizei args = unpacked->args;
            glCopyColorSubTable(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glCopyColorTable
        case glCopyColorTable_INDEX: {
            INDEXED_void_GLenum_GLenum_GLint_GLint_GLsizei *unpacked = (INDEXED_void_GLenum_GLenum_GLint_GLint_GLsizei *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLint_GLsizei args = unpacked->args;
            glCopyColorTable(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glCopyConvolutionFilter1D
        case glCopyConvolutionFilter1D_INDEX: {
            INDEXED_void_GLenum_GLenum_GLint_GLint_GLsizei *unpacked = (INDEXED_void_GLenum_GLenum_GLint_GLint_GLsizei *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLint_GLsizei args = unpacked->args;
            glCopyConvolutionFilter1D(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glCopyConvolutionFilter2D
        case glCopyConvolutionFilter2D_INDEX: {
            INDEXED_void_GLenum_GLenum_GLint_GLint_GLsizei_GLsizei *unpacked = (INDEXED_void_GLenum_GLenum_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            glCopyConvolutionFilter2D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glCopyPixels
        case glCopyPixels_INDEX: {
            INDEXED_void_GLint_GLint_GLsizei_GLsizei_GLenum *unpacked = (INDEXED_void_GLint_GLint_GLsizei_GLsizei_GLenum *)packed;
            ARGS_void_GLint_GLint_GLsizei_GLsizei_GLenum args = unpacked->args;
            glCopyPixels(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glCopyTexImage1D
        case glCopyTexImage1D_INDEX: {
            INDEXED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint *unpacked = (INDEXED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint args = unpacked->args;
            glCopyTexImage1D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        #endif
        #ifndef skip_index_glCopyTexImage2D
        case glCopyTexImage2D_INDEX: {
            INDEXED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint *unpacked = (INDEXED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint args = unpacked->args;
            glCopyTexImage2D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        #endif
        #ifndef skip_index_glCopyTexSubImage1D
        case glCopyTexSubImage1D_INDEX: {
            INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLsizei args = unpacked->args;
            glCopyTexSubImage1D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glCopyTexSubImage2D
        case glCopyTexSubImage2D_INDEX: {
            INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            glCopyTexSubImage2D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        #endif
        #ifndef skip_index_glCopyTexSubImage3D
        case glCopyTexSubImage3D_INDEX: {
            INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            glCopyTexSubImage3D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        #endif
        #ifndef skip_index_glCullFace
        case glCullFace_INDEX: {
            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            glCullFace(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glDeleteBuffers
        case glDeleteBuffers_INDEX: {
            INDEXED_void_GLsizei_const_GLuint___GENPT__ *unpacked = (INDEXED_void_GLsizei_const_GLuint___GENPT__ *)packed;
            ARGS_void_GLsizei_const_GLuint___GENPT__ args = unpacked->args;
            glDeleteBuffers(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glDeleteLists
        case glDeleteLists_INDEX: {
            INDEXED_void_GLuint_GLsizei *unpacked = (INDEXED_void_GLuint_GLsizei *)packed;
            ARGS_void_GLuint_GLsizei args = unpacked->args;
            glDeleteLists(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glDeleteQueries
        case glDeleteQueries_INDEX: {
            INDEXED_void_GLsizei_const_GLuint___GENPT__ *unpacked = (INDEXED_void_GLsizei_const_GLuint___GENPT__ *)packed;
            ARGS_void_GLsizei_const_GLuint___GENPT__ args = unpacked->args;
            glDeleteQueries(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glDeleteTextures
        case glDeleteTextures_INDEX: {
            INDEXED_void_GLsizei_const_GLuint___GENPT__ *unpacked = (INDEXED_void_GLsizei_const_GLuint___GENPT__ *)packed;
            ARGS_void_GLsizei_const_GLuint___GENPT__ args = unpacked->args;
            glDeleteTextures(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glDepthFunc
        case glDepthFunc_INDEX: {
            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            glDepthFunc(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glDepthMask
        case glDepthMask_INDEX: {
            INDEXED_void_GLboolean *unpacked = (INDEXED_void_GLboolean *)packed;
            ARGS_void_GLboolean args = unpacked->args;
            glDepthMask(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glDepthRange
        case glDepthRange_INDEX: {
            INDEXED_void_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble args = unpacked->args;
            glDepthRange(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glDisable
        case glDisable_INDEX: {
            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            glDisable(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glDisableClientState
        case glDisableClientState_INDEX: {
            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            glDisableClientState(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glDrawArrays
        case glDrawArrays_INDEX: {
            INDEXED_void_GLenum_GLint_GLsizei *unpacked = (INDEXED_void_GLenum_GLint_GLsizei *)packed;
            ARGS_void_GLenum_GLint_GLsizei args = unpacked->args;
            glDrawArrays(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glDrawBuffer
        case glDrawBuffer_INDEX: {
            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            glDrawBuffer(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glDrawElements
        case glDrawElements_INDEX: {
            INDEXED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            glDrawElements(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glDrawPixels
        case glDrawPixels_INDEX: {
            INDEXED_void_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            glDrawPixels(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glDrawRangeElements
        case glDrawRangeElements_INDEX: {
            INDEXED_void_GLenum_GLuint_GLuint_GLsizei_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLuint_GLuint_GLsizei_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLuint_GLuint_GLsizei_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            glDrawRangeElements(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glEdgeFlag
        case glEdgeFlag_INDEX: {
            INDEXED_void_GLboolean *unpacked = (INDEXED_void_GLboolean *)packed;
            ARGS_void_GLboolean args = unpacked->args;
            glEdgeFlag(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glEdgeFlagPointer
        case glEdgeFlagPointer_INDEX: {
            INDEXED_void_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            glEdgeFlagPointer(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glEdgeFlagv
        case glEdgeFlagv_INDEX: {
            INDEXED_void_const_GLboolean___GENPT__ *unpacked = (INDEXED_void_const_GLboolean___GENPT__ *)packed;
            ARGS_void_const_GLboolean___GENPT__ args = unpacked->args;
            glEdgeFlagv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glEnable
        case glEnable_INDEX: {
            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            glEnable(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glEnableClientState
        case glEnableClientState_INDEX: {
            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            glEnableClientState(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glEnd
        case glEnd_INDEX: {
            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            glEnd();
            break;
        }
        #endif
        #ifndef skip_index_glEndList
        case glEndList_INDEX: {
            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            glEndList();
            break;
        }
        #endif
        #ifndef skip_index_glEndQuery
        case glEndQuery_INDEX: {
            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            glEndQuery(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glEvalCoord1d
        case glEvalCoord1d_INDEX: {
            INDEXED_void_GLdouble *unpacked = (INDEXED_void_GLdouble *)packed;
            ARGS_void_GLdouble args = unpacked->args;
            glEvalCoord1d(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glEvalCoord1dv
        case glEvalCoord1dv_INDEX: {
            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            glEvalCoord1dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glEvalCoord1f
        case glEvalCoord1f_INDEX: {
            INDEXED_void_GLfloat *unpacked = (INDEXED_void_GLfloat *)packed;
            ARGS_void_GLfloat args = unpacked->args;
            glEvalCoord1f(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glEvalCoord1fv
        case glEvalCoord1fv_INDEX: {
            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            glEvalCoord1fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glEvalCoord2d
        case glEvalCoord2d_INDEX: {
            INDEXED_void_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble args = unpacked->args;
            glEvalCoord2d(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glEvalCoord2dv
        case glEvalCoord2dv_INDEX: {
            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            glEvalCoord2dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glEvalCoord2f
        case glEvalCoord2f_INDEX: {
            INDEXED_void_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat args = unpacked->args;
            glEvalCoord2f(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glEvalCoord2fv
        case glEvalCoord2fv_INDEX: {
            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            glEvalCoord2fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glEvalMesh1
        case glEvalMesh1_INDEX: {
            INDEXED_void_GLenum_GLint_GLint *unpacked = (INDEXED_void_GLenum_GLint_GLint *)packed;
            ARGS_void_GLenum_GLint_GLint args = unpacked->args;
            glEvalMesh1(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glEvalMesh2
        case glEvalMesh2_INDEX: {
            INDEXED_void_GLenum_GLint_GLint_GLint_GLint *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint args = unpacked->args;
            glEvalMesh2(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glEvalPoint1
        case glEvalPoint1_INDEX: {
            INDEXED_void_GLint *unpacked = (INDEXED_void_GLint *)packed;
            ARGS_void_GLint args = unpacked->args;
            glEvalPoint1(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glEvalPoint2
        case glEvalPoint2_INDEX: {
            INDEXED_void_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint *)packed;
            ARGS_void_GLint_GLint args = unpacked->args;
            glEvalPoint2(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glFeedbackBuffer
        case glFeedbackBuffer_INDEX: {
            INDEXED_void_GLsizei_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLsizei_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLsizei_GLenum_GLfloat___GENPT__ args = unpacked->args;
            glFeedbackBuffer(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glFinish
        case glFinish_INDEX: {
            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            glFinish();
            break;
        }
        #endif
        #ifndef skip_index_glFlush
        case glFlush_INDEX: {
            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            glFlush();
            break;
        }
        #endif
        #ifndef skip_index_glFogCoordPointer
        case glFogCoordPointer_INDEX: {
            INDEXED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            glFogCoordPointer(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glFogCoordd
        case glFogCoordd_INDEX: {
            INDEXED_void_GLdouble *unpacked = (INDEXED_void_GLdouble *)packed;
            ARGS_void_GLdouble args = unpacked->args;
            glFogCoordd(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glFogCoorddv
        case glFogCoorddv_INDEX: {
            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            glFogCoorddv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glFogCoordf
        case glFogCoordf_INDEX: {
            INDEXED_void_GLfloat *unpacked = (INDEXED_void_GLfloat *)packed;
            ARGS_void_GLfloat args = unpacked->args;
            glFogCoordf(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glFogCoordfv
        case glFogCoordfv_INDEX: {
            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            glFogCoordfv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glFogf
        case glFogf_INDEX: {
            INDEXED_void_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat args = unpacked->args;
            glFogf(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glFogfv
        case glFogfv_INDEX: {
            INDEXED_void_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            glFogfv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glFogi
        case glFogi_INDEX: {
            INDEXED_void_GLenum_GLint *unpacked = (INDEXED_void_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLint args = unpacked->args;
            glFogi(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glFogiv
        case glFogiv_INDEX: {
            INDEXED_void_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLint___GENPT__ args = unpacked->args;
            glFogiv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glFrontFace
        case glFrontFace_INDEX: {
            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            glFrontFace(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glFrustum
        case glFrustum_INDEX: {
            INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            glFrustum(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glGenBuffers
        case glGenBuffers_INDEX: {
            INDEXED_void_GLsizei_GLuint___GENPT__ *unpacked = (INDEXED_void_GLsizei_GLuint___GENPT__ *)packed;
            ARGS_void_GLsizei_GLuint___GENPT__ args = unpacked->args;
            glGenBuffers(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glGenLists
        case glGenLists_INDEX: {
            INDEXED_GLuint_GLsizei *unpacked = (INDEXED_GLuint_GLsizei *)packed;
            ARGS_GLuint_GLsizei args = unpacked->args;
            GLuint *ret = (GLuint *)ret_v;
            *ret =
            glGenLists(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glGenQueries
        case glGenQueries_INDEX: {
            INDEXED_void_GLsizei_GLuint___GENPT__ *unpacked = (INDEXED_void_GLsizei_GLuint___GENPT__ *)packed;
            ARGS_void_GLsizei_GLuint___GENPT__ args = unpacked->args;
            glGenQueries(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glGenTextures
        case glGenTextures_INDEX: {
            INDEXED_void_GLsizei_GLuint___GENPT__ *unpacked = (INDEXED_void_GLsizei_GLuint___GENPT__ *)packed;
            ARGS_void_GLsizei_GLuint___GENPT__ args = unpacked->args;
            glGenTextures(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glGetBooleanv
        case glGetBooleanv_INDEX: {
            INDEXED_void_GLenum_GLboolean___GENPT__ *unpacked = (INDEXED_void_GLenum_GLboolean___GENPT__ *)packed;
            ARGS_void_GLenum_GLboolean___GENPT__ args = unpacked->args;
            glGetBooleanv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glGetBufferParameteriv
        case glGetBufferParameteriv_INDEX: {
            INDEXED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            glGetBufferParameteriv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetBufferPointerv
        case glGetBufferPointerv_INDEX: {
            INDEXED_void_GLenum_GLenum_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLvoid___GENPT__ args = unpacked->args;
            glGetBufferPointerv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetBufferSubData
        case glGetBufferSubData_INDEX: {
            INDEXED_void_GLenum_GLintptr_GLsizeiptr_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLintptr_GLsizeiptr_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLintptr_GLsizeiptr_GLvoid___GENPT__ args = unpacked->args;
            glGetBufferSubData(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glGetClipPlane
        case glGetClipPlane_INDEX: {
            INDEXED_void_GLenum_GLdouble___GENPT__ *unpacked = (INDEXED_void_GLenum_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_GLdouble___GENPT__ args = unpacked->args;
            glGetClipPlane(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glGetColorTable
        case glGetColorTable_INDEX: {
            INDEXED_void_GLenum_GLenum_GLenum_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLvoid___GENPT__ args = unpacked->args;
            glGetColorTable(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glGetColorTableParameterfv
        case glGetColorTableParameterfv_INDEX: {
            INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            glGetColorTableParameterfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetColorTableParameteriv
        case glGetColorTableParameteriv_INDEX: {
            INDEXED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            glGetColorTableParameteriv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetCompressedTexImage
        case glGetCompressedTexImage_INDEX: {
            INDEXED_void_GLenum_GLint_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLvoid___GENPT__ args = unpacked->args;
            glGetCompressedTexImage(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetConvolutionFilter
        case glGetConvolutionFilter_INDEX: {
            INDEXED_void_GLenum_GLenum_GLenum_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLvoid___GENPT__ args = unpacked->args;
            glGetConvolutionFilter(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glGetConvolutionParameterfv
        case glGetConvolutionParameterfv_INDEX: {
            INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            glGetConvolutionParameterfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetConvolutionParameteriv
        case glGetConvolutionParameteriv_INDEX: {
            INDEXED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            glGetConvolutionParameteriv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetDoublev
        case glGetDoublev_INDEX: {
            INDEXED_void_GLenum_GLdouble___GENPT__ *unpacked = (INDEXED_void_GLenum_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_GLdouble___GENPT__ args = unpacked->args;
            glGetDoublev(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glGetError
        case glGetError_INDEX: {
            INDEXED_GLenum *unpacked = (INDEXED_GLenum *)packed;
            ARGS_GLenum args = unpacked->args;
            GLenum *ret = (GLenum *)ret_v;
            *ret =
            glGetError();
            break;
        }
        #endif
        #ifndef skip_index_glGetFloatv
        case glGetFloatv_INDEX: {
            INDEXED_void_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLfloat___GENPT__ args = unpacked->args;
            glGetFloatv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glGetHistogram
        case glGetHistogram_INDEX: {
            INDEXED_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__ args = unpacked->args;
            glGetHistogram(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glGetHistogramParameterfv
        case glGetHistogramParameterfv_INDEX: {
            INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            glGetHistogramParameterfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetHistogramParameteriv
        case glGetHistogramParameteriv_INDEX: {
            INDEXED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            glGetHistogramParameteriv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetIntegerv
        case glGetIntegerv_INDEX: {
            INDEXED_void_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLint___GENPT__ args = unpacked->args;
            glGetIntegerv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glGetLightfv
        case glGetLightfv_INDEX: {
            INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            glGetLightfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetLightiv
        case glGetLightiv_INDEX: {
            INDEXED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            glGetLightiv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetMapdv
        case glGetMapdv_INDEX: {
            INDEXED_void_GLenum_GLenum_GLdouble___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLdouble___GENPT__ args = unpacked->args;
            glGetMapdv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetMapfv
        case glGetMapfv_INDEX: {
            INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            glGetMapfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetMapiv
        case glGetMapiv_INDEX: {
            INDEXED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            glGetMapiv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetMaterialfv
        case glGetMaterialfv_INDEX: {
            INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            glGetMaterialfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetMaterialiv
        case glGetMaterialiv_INDEX: {
            INDEXED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            glGetMaterialiv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetMinmax
        case glGetMinmax_INDEX: {
            INDEXED_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__ args = unpacked->args;
            glGetMinmax(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glGetMinmaxParameterfv
        case glGetMinmaxParameterfv_INDEX: {
            INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            glGetMinmaxParameterfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetMinmaxParameteriv
        case glGetMinmaxParameteriv_INDEX: {
            INDEXED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            glGetMinmaxParameteriv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetPixelMapfv
        case glGetPixelMapfv_INDEX: {
            INDEXED_void_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLfloat___GENPT__ args = unpacked->args;
            glGetPixelMapfv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glGetPixelMapuiv
        case glGetPixelMapuiv_INDEX: {
            INDEXED_void_GLenum_GLuint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLuint___GENPT__ *)packed;
            ARGS_void_GLenum_GLuint___GENPT__ args = unpacked->args;
            glGetPixelMapuiv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glGetPixelMapusv
        case glGetPixelMapusv_INDEX: {
            INDEXED_void_GLenum_GLushort___GENPT__ *unpacked = (INDEXED_void_GLenum_GLushort___GENPT__ *)packed;
            ARGS_void_GLenum_GLushort___GENPT__ args = unpacked->args;
            glGetPixelMapusv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glGetPointerv
        case glGetPointerv_INDEX: {
            INDEXED_void_GLenum_GLvoid___GENPT____GENPT__ *unpacked = (INDEXED_void_GLenum_GLvoid___GENPT____GENPT__ *)packed;
            ARGS_void_GLenum_GLvoid___GENPT____GENPT__ args = unpacked->args;
            glGetPointerv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glGetPolygonStipple
        case glGetPolygonStipple_INDEX: {
            INDEXED_void_GLubyte___GENPT__ *unpacked = (INDEXED_void_GLubyte___GENPT__ *)packed;
            ARGS_void_GLubyte___GENPT__ args = unpacked->args;
            glGetPolygonStipple(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glGetQueryObjectiv
        case glGetQueryObjectiv_INDEX: {
            INDEXED_void_GLuint_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLuint_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLuint_GLenum_GLint___GENPT__ args = unpacked->args;
            glGetQueryObjectiv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetQueryObjectuiv
        case glGetQueryObjectuiv_INDEX: {
            INDEXED_void_GLuint_GLenum_GLuint___GENPT__ *unpacked = (INDEXED_void_GLuint_GLenum_GLuint___GENPT__ *)packed;
            ARGS_void_GLuint_GLenum_GLuint___GENPT__ args = unpacked->args;
            glGetQueryObjectuiv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetQueryiv
        case glGetQueryiv_INDEX: {
            INDEXED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            glGetQueryiv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetSeparableFilter
        case glGetSeparableFilter_INDEX: {
            INDEXED_void_GLenum_GLenum_GLenum_GLvoid___GENPT___GLvoid___GENPT___GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLenum_GLvoid___GENPT___GLvoid___GENPT___GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLvoid___GENPT___GLvoid___GENPT___GLvoid___GENPT__ args = unpacked->args;
            glGetSeparableFilter(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glGetString
        case glGetString_INDEX: {
            INDEXED_const_GLubyte___GENPT___GLenum *unpacked = (INDEXED_const_GLubyte___GENPT___GLenum *)packed;
            ARGS_const_GLubyte___GENPT___GLenum args = unpacked->args;
            const GLubyte * *ret = (const GLubyte * *)ret_v;
            *ret =
            glGetString(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glGetTexEnvfv
        case glGetTexEnvfv_INDEX: {
            INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            glGetTexEnvfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetTexEnviv
        case glGetTexEnviv_INDEX: {
            INDEXED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            glGetTexEnviv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetTexGendv
        case glGetTexGendv_INDEX: {
            INDEXED_void_GLenum_GLenum_GLdouble___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLdouble___GENPT__ args = unpacked->args;
            glGetTexGendv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetTexGenfv
        case glGetTexGenfv_INDEX: {
            INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            glGetTexGenfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetTexGeniv
        case glGetTexGeniv_INDEX: {
            INDEXED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            glGetTexGeniv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetTexImage
        case glGetTexImage_INDEX: {
            INDEXED_void_GLenum_GLint_GLenum_GLenum_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLenum_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLenum_GLvoid___GENPT__ args = unpacked->args;
            glGetTexImage(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glGetTexLevelParameterfv
        case glGetTexLevelParameterfv_INDEX: {
            INDEXED_void_GLenum_GLint_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLfloat___GENPT__ args = unpacked->args;
            glGetTexLevelParameterfv(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glGetTexLevelParameteriv
        case glGetTexLevelParameteriv_INDEX: {
            INDEXED_void_GLenum_GLint_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLint___GENPT__ args = unpacked->args;
            glGetTexLevelParameteriv(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glGetTexParameterfv
        case glGetTexParameterfv_INDEX: {
            INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            glGetTexParameterfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glGetTexParameteriv
        case glGetTexParameteriv_INDEX: {
            INDEXED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            glGetTexParameteriv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glHint
        case glHint_INDEX: {
            INDEXED_void_GLenum_GLenum *unpacked = (INDEXED_void_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLenum args = unpacked->args;
            glHint(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glHistogram
        case glHistogram_INDEX: {
            INDEXED_void_GLenum_GLsizei_GLenum_GLboolean *unpacked = (INDEXED_void_GLenum_GLsizei_GLenum_GLboolean *)packed;
            ARGS_void_GLenum_GLsizei_GLenum_GLboolean args = unpacked->args;
            glHistogram(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glIndexMask
        case glIndexMask_INDEX: {
            INDEXED_void_GLuint *unpacked = (INDEXED_void_GLuint *)packed;
            ARGS_void_GLuint args = unpacked->args;
            glIndexMask(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIndexPointer
        case glIndexPointer_INDEX: {
            INDEXED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            glIndexPointer(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glIndexd
        case glIndexd_INDEX: {
            INDEXED_void_GLdouble *unpacked = (INDEXED_void_GLdouble *)packed;
            ARGS_void_GLdouble args = unpacked->args;
            glIndexd(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIndexdv
        case glIndexdv_INDEX: {
            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            glIndexdv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIndexf
        case glIndexf_INDEX: {
            INDEXED_void_GLfloat *unpacked = (INDEXED_void_GLfloat *)packed;
            ARGS_void_GLfloat args = unpacked->args;
            glIndexf(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIndexfv
        case glIndexfv_INDEX: {
            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            glIndexfv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIndexi
        case glIndexi_INDEX: {
            INDEXED_void_GLint *unpacked = (INDEXED_void_GLint *)packed;
            ARGS_void_GLint args = unpacked->args;
            glIndexi(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIndexiv
        case glIndexiv_INDEX: {
            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            glIndexiv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIndexs
        case glIndexs_INDEX: {
            INDEXED_void_GLshort *unpacked = (INDEXED_void_GLshort *)packed;
            ARGS_void_GLshort args = unpacked->args;
            glIndexs(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIndexsv
        case glIndexsv_INDEX: {
            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            glIndexsv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIndexub
        case glIndexub_INDEX: {
            INDEXED_void_GLubyte *unpacked = (INDEXED_void_GLubyte *)packed;
            ARGS_void_GLubyte args = unpacked->args;
            glIndexub(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIndexubv
        case glIndexubv_INDEX: {
            INDEXED_void_const_GLubyte___GENPT__ *unpacked = (INDEXED_void_const_GLubyte___GENPT__ *)packed;
            ARGS_void_const_GLubyte___GENPT__ args = unpacked->args;
            glIndexubv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glInitNames
        case glInitNames_INDEX: {
            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            glInitNames();
            break;
        }
        #endif
        #ifndef skip_index_glInterleavedArrays
        case glInterleavedArrays_INDEX: {
            INDEXED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            glInterleavedArrays(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glIsBuffer
        case glIsBuffer_INDEX: {
            INDEXED_GLboolean_GLuint *unpacked = (INDEXED_GLboolean_GLuint *)packed;
            ARGS_GLboolean_GLuint args = unpacked->args;
            GLboolean *ret = (GLboolean *)ret_v;
            *ret =
            glIsBuffer(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIsEnabled
        case glIsEnabled_INDEX: {
            INDEXED_GLboolean_GLenum *unpacked = (INDEXED_GLboolean_GLenum *)packed;
            ARGS_GLboolean_GLenum args = unpacked->args;
            GLboolean *ret = (GLboolean *)ret_v;
            *ret =
            glIsEnabled(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIsList
        case glIsList_INDEX: {
            INDEXED_GLboolean_GLuint *unpacked = (INDEXED_GLboolean_GLuint *)packed;
            ARGS_GLboolean_GLuint args = unpacked->args;
            GLboolean *ret = (GLboolean *)ret_v;
            *ret =
            glIsList(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIsQuery
        case glIsQuery_INDEX: {
            INDEXED_GLboolean_GLuint *unpacked = (INDEXED_GLboolean_GLuint *)packed;
            ARGS_GLboolean_GLuint args = unpacked->args;
            GLboolean *ret = (GLboolean *)ret_v;
            *ret =
            glIsQuery(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glIsTexture
        case glIsTexture_INDEX: {
            INDEXED_GLboolean_GLuint *unpacked = (INDEXED_GLboolean_GLuint *)packed;
            ARGS_GLboolean_GLuint args = unpacked->args;
            GLboolean *ret = (GLboolean *)ret_v;
            *ret =
            glIsTexture(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glLightModelf
        case glLightModelf_INDEX: {
            INDEXED_void_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat args = unpacked->args;
            glLightModelf(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glLightModelfv
        case glLightModelfv_INDEX: {
            INDEXED_void_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            glLightModelfv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glLightModeli
        case glLightModeli_INDEX: {
            INDEXED_void_GLenum_GLint *unpacked = (INDEXED_void_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLint args = unpacked->args;
            glLightModeli(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glLightModeliv
        case glLightModeliv_INDEX: {
            INDEXED_void_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLint___GENPT__ args = unpacked->args;
            glLightModeliv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glLightf
        case glLightf_INDEX: {
            INDEXED_void_GLenum_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLenum_GLfloat args = unpacked->args;
            glLightf(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glLightfv
        case glLightfv_INDEX: {
            INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            glLightfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glLighti
        case glLighti_INDEX: {
            INDEXED_void_GLenum_GLenum_GLint *unpacked = (INDEXED_void_GLenum_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLint args = unpacked->args;
            glLighti(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glLightiv
        case glLightiv_INDEX: {
            INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLint___GENPT__ args = unpacked->args;
            glLightiv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glLineStipple
        case glLineStipple_INDEX: {
            INDEXED_void_GLint_GLushort *unpacked = (INDEXED_void_GLint_GLushort *)packed;
            ARGS_void_GLint_GLushort args = unpacked->args;
            glLineStipple(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glLineWidth
        case glLineWidth_INDEX: {
            INDEXED_void_GLfloat *unpacked = (INDEXED_void_GLfloat *)packed;
            ARGS_void_GLfloat args = unpacked->args;
            glLineWidth(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glListBase
        case glListBase_INDEX: {
            INDEXED_void_GLuint *unpacked = (INDEXED_void_GLuint *)packed;
            ARGS_void_GLuint args = unpacked->args;
            glListBase(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glLoadIdentity
        case glLoadIdentity_INDEX: {
            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            glLoadIdentity();
            break;
        }
        #endif
        #ifndef skip_index_glLoadMatrixd
        case glLoadMatrixd_INDEX: {
            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            glLoadMatrixd(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glLoadMatrixf
        case glLoadMatrixf_INDEX: {
            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            glLoadMatrixf(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glLoadName
        case glLoadName_INDEX: {
            INDEXED_void_GLuint *unpacked = (INDEXED_void_GLuint *)packed;
            ARGS_void_GLuint args = unpacked->args;
            glLoadName(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glLoadTransposeMatrixd
        case glLoadTransposeMatrixd_INDEX: {
            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            glLoadTransposeMatrixd(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glLoadTransposeMatrixf
        case glLoadTransposeMatrixf_INDEX: {
            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            glLoadTransposeMatrixf(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glLogicOp
        case glLogicOp_INDEX: {
            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            glLogicOp(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glMap1d
        case glMap1d_INDEX: {
            INDEXED_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ args = unpacked->args;
            glMap1d(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glMap1f
        case glMap1f_INDEX: {
            INDEXED_void_GLenum_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ args = unpacked->args;
            glMap1f(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glMap2d
        case glMap2d_INDEX: {
            INDEXED_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ args = unpacked->args;
            glMap2d(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        #endif
        #ifndef skip_index_glMap2f
        case glMap2f_INDEX: {
            INDEXED_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ args = unpacked->args;
            glMap2f(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        #endif
        #ifndef skip_index_glMapBuffer
        case glMapBuffer_INDEX: {
            INDEXED_GLvoid___GENPT___GLenum_GLenum *unpacked = (INDEXED_GLvoid___GENPT___GLenum_GLenum *)packed;
            ARGS_GLvoid___GENPT___GLenum_GLenum args = unpacked->args;
            GLvoid * *ret = (GLvoid * *)ret_v;
            *ret =
            glMapBuffer(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMapGrid1d
        case glMapGrid1d_INDEX: {
            INDEXED_void_GLint_GLdouble_GLdouble *unpacked = (INDEXED_void_GLint_GLdouble_GLdouble *)packed;
            ARGS_void_GLint_GLdouble_GLdouble args = unpacked->args;
            glMapGrid1d(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glMapGrid1f
        case glMapGrid1f_INDEX: {
            INDEXED_void_GLint_GLfloat_GLfloat *unpacked = (INDEXED_void_GLint_GLfloat_GLfloat *)packed;
            ARGS_void_GLint_GLfloat_GLfloat args = unpacked->args;
            glMapGrid1f(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glMapGrid2d
        case glMapGrid2d_INDEX: {
            INDEXED_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble *unpacked = (INDEXED_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble *)packed;
            ARGS_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble args = unpacked->args;
            glMapGrid2d(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glMapGrid2f
        case glMapGrid2f_INDEX: {
            INDEXED_void_GLint_GLfloat_GLfloat_GLint_GLfloat_GLfloat *unpacked = (INDEXED_void_GLint_GLfloat_GLfloat_GLint_GLfloat_GLfloat *)packed;
            ARGS_void_GLint_GLfloat_GLfloat_GLint_GLfloat_GLfloat args = unpacked->args;
            glMapGrid2f(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glMaterialf
        case glMaterialf_INDEX: {
            INDEXED_void_GLenum_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLenum_GLfloat args = unpacked->args;
            glMaterialf(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glMaterialfv
        case glMaterialfv_INDEX: {
            INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            glMaterialfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glMateriali
        case glMateriali_INDEX: {
            INDEXED_void_GLenum_GLenum_GLint *unpacked = (INDEXED_void_GLenum_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLint args = unpacked->args;
            glMateriali(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glMaterialiv
        case glMaterialiv_INDEX: {
            INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLint___GENPT__ args = unpacked->args;
            glMaterialiv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glMatrixMode
        case glMatrixMode_INDEX: {
            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            glMatrixMode(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glMinmax
        case glMinmax_INDEX: {
            INDEXED_void_GLenum_GLenum_GLboolean *unpacked = (INDEXED_void_GLenum_GLenum_GLboolean *)packed;
            ARGS_void_GLenum_GLenum_GLboolean args = unpacked->args;
            glMinmax(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glMultMatrixd
        case glMultMatrixd_INDEX: {
            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            glMultMatrixd(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glMultMatrixf
        case glMultMatrixf_INDEX: {
            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            glMultMatrixf(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glMultTransposeMatrixd
        case glMultTransposeMatrixd_INDEX: {
            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            glMultTransposeMatrixd(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glMultTransposeMatrixf
        case glMultTransposeMatrixf_INDEX: {
            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            glMultTransposeMatrixf(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glMultiDrawArrays
        case glMultiDrawArrays_INDEX: {
            INDEXED_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei *unpacked = (INDEXED_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei *)packed;
            ARGS_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei args = unpacked->args;
            glMultiDrawArrays(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glMultiDrawElements
        case glMultiDrawElements_INDEX: {
            INDEXED_void_GLenum_const_GLsizei___GENPT___GLenum_GLvoid__GENPT__const___GENPT___GLsizei *unpacked = (INDEXED_void_GLenum_const_GLsizei___GENPT___GLenum_GLvoid__GENPT__const___GENPT___GLsizei *)packed;
            ARGS_void_GLenum_const_GLsizei___GENPT___GLenum_GLvoid__GENPT__const___GENPT___GLsizei args = unpacked->args;
            glMultiDrawElements(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord1d
        case glMultiTexCoord1d_INDEX: {
            INDEXED_void_GLenum_GLdouble *unpacked = (INDEXED_void_GLenum_GLdouble *)packed;
            ARGS_void_GLenum_GLdouble args = unpacked->args;
            glMultiTexCoord1d(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord1dv
        case glMultiTexCoord1dv_INDEX: {
            INDEXED_void_GLenum_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLdouble___GENPT__ args = unpacked->args;
            glMultiTexCoord1dv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord1f
        case glMultiTexCoord1f_INDEX: {
            INDEXED_void_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat args = unpacked->args;
            glMultiTexCoord1f(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord1fv
        case glMultiTexCoord1fv_INDEX: {
            INDEXED_void_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            glMultiTexCoord1fv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord1i
        case glMultiTexCoord1i_INDEX: {
            INDEXED_void_GLenum_GLint *unpacked = (INDEXED_void_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLint args = unpacked->args;
            glMultiTexCoord1i(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord1iv
        case glMultiTexCoord1iv_INDEX: {
            INDEXED_void_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLint___GENPT__ args = unpacked->args;
            glMultiTexCoord1iv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord1s
        case glMultiTexCoord1s_INDEX: {
            INDEXED_void_GLenum_GLshort *unpacked = (INDEXED_void_GLenum_GLshort *)packed;
            ARGS_void_GLenum_GLshort args = unpacked->args;
            glMultiTexCoord1s(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord1sv
        case glMultiTexCoord1sv_INDEX: {
            INDEXED_void_GLenum_const_GLshort___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLshort___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLshort___GENPT__ args = unpacked->args;
            glMultiTexCoord1sv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord2d
        case glMultiTexCoord2d_INDEX: {
            INDEXED_void_GLenum_GLdouble_GLdouble *unpacked = (INDEXED_void_GLenum_GLdouble_GLdouble *)packed;
            ARGS_void_GLenum_GLdouble_GLdouble args = unpacked->args;
            glMultiTexCoord2d(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord2dv
        case glMultiTexCoord2dv_INDEX: {
            INDEXED_void_GLenum_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLdouble___GENPT__ args = unpacked->args;
            glMultiTexCoord2dv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord2f
        case glMultiTexCoord2f_INDEX: {
            INDEXED_void_GLenum_GLfloat_GLfloat *unpacked = (INDEXED_void_GLenum_GLfloat_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat_GLfloat args = unpacked->args;
            glMultiTexCoord2f(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord2fv
        case glMultiTexCoord2fv_INDEX: {
            INDEXED_void_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            glMultiTexCoord2fv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord2i
        case glMultiTexCoord2i_INDEX: {
            INDEXED_void_GLenum_GLint_GLint *unpacked = (INDEXED_void_GLenum_GLint_GLint *)packed;
            ARGS_void_GLenum_GLint_GLint args = unpacked->args;
            glMultiTexCoord2i(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord2iv
        case glMultiTexCoord2iv_INDEX: {
            INDEXED_void_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLint___GENPT__ args = unpacked->args;
            glMultiTexCoord2iv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord2s
        case glMultiTexCoord2s_INDEX: {
            INDEXED_void_GLenum_GLshort_GLshort *unpacked = (INDEXED_void_GLenum_GLshort_GLshort *)packed;
            ARGS_void_GLenum_GLshort_GLshort args = unpacked->args;
            glMultiTexCoord2s(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord2sv
        case glMultiTexCoord2sv_INDEX: {
            INDEXED_void_GLenum_const_GLshort___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLshort___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLshort___GENPT__ args = unpacked->args;
            glMultiTexCoord2sv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord3d
        case glMultiTexCoord3d_INDEX: {
            INDEXED_void_GLenum_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLenum_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLenum_GLdouble_GLdouble_GLdouble args = unpacked->args;
            glMultiTexCoord3d(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord3dv
        case glMultiTexCoord3dv_INDEX: {
            INDEXED_void_GLenum_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLdouble___GENPT__ args = unpacked->args;
            glMultiTexCoord3dv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord3f
        case glMultiTexCoord3f_INDEX: {
            INDEXED_void_GLenum_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLenum_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat_GLfloat_GLfloat args = unpacked->args;
            glMultiTexCoord3f(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord3fv
        case glMultiTexCoord3fv_INDEX: {
            INDEXED_void_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            glMultiTexCoord3fv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord3i
        case glMultiTexCoord3i_INDEX: {
            INDEXED_void_GLenum_GLint_GLint_GLint *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLint *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint args = unpacked->args;
            glMultiTexCoord3i(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord3iv
        case glMultiTexCoord3iv_INDEX: {
            INDEXED_void_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLint___GENPT__ args = unpacked->args;
            glMultiTexCoord3iv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord3s
        case glMultiTexCoord3s_INDEX: {
            INDEXED_void_GLenum_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLenum_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLenum_GLshort_GLshort_GLshort args = unpacked->args;
            glMultiTexCoord3s(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord3sv
        case glMultiTexCoord3sv_INDEX: {
            INDEXED_void_GLenum_const_GLshort___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLshort___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLshort___GENPT__ args = unpacked->args;
            glMultiTexCoord3sv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord4d
        case glMultiTexCoord4d_INDEX: {
            INDEXED_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            glMultiTexCoord4d(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord4dv
        case glMultiTexCoord4dv_INDEX: {
            INDEXED_void_GLenum_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLdouble___GENPT__ args = unpacked->args;
            glMultiTexCoord4dv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord4f
        case glMultiTexCoord4f_INDEX: {
            INDEXED_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            glMultiTexCoord4f(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord4fv
        case glMultiTexCoord4fv_INDEX: {
            INDEXED_void_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            glMultiTexCoord4fv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord4i
        case glMultiTexCoord4i_INDEX: {
            INDEXED_void_GLenum_GLint_GLint_GLint_GLint *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint args = unpacked->args;
            glMultiTexCoord4i(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord4iv
        case glMultiTexCoord4iv_INDEX: {
            INDEXED_void_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLint___GENPT__ args = unpacked->args;
            glMultiTexCoord4iv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord4s
        case glMultiTexCoord4s_INDEX: {
            INDEXED_void_GLenum_GLshort_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLenum_GLshort_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLenum_GLshort_GLshort_GLshort_GLshort args = unpacked->args;
            glMultiTexCoord4s(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glMultiTexCoord4sv
        case glMultiTexCoord4sv_INDEX: {
            INDEXED_void_GLenum_const_GLshort___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLshort___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLshort___GENPT__ args = unpacked->args;
            glMultiTexCoord4sv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glNewList
        case glNewList_INDEX: {
            INDEXED_void_GLuint_GLenum *unpacked = (INDEXED_void_GLuint_GLenum *)packed;
            ARGS_void_GLuint_GLenum args = unpacked->args;
            glNewList(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glNormal3b
        case glNormal3b_INDEX: {
            INDEXED_void_GLbyte_GLbyte_GLbyte *unpacked = (INDEXED_void_GLbyte_GLbyte_GLbyte *)packed;
            ARGS_void_GLbyte_GLbyte_GLbyte args = unpacked->args;
            glNormal3b(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glNormal3bv
        case glNormal3bv_INDEX: {
            INDEXED_void_const_GLbyte___GENPT__ *unpacked = (INDEXED_void_const_GLbyte___GENPT__ *)packed;
            ARGS_void_const_GLbyte___GENPT__ args = unpacked->args;
            glNormal3bv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glNormal3d
        case glNormal3d_INDEX: {
            INDEXED_void_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble args = unpacked->args;
            glNormal3d(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glNormal3dv
        case glNormal3dv_INDEX: {
            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            glNormal3dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glNormal3f
        case glNormal3f_INDEX: {
            INDEXED_void_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat args = unpacked->args;
            glNormal3f(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glNormal3fv
        case glNormal3fv_INDEX: {
            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            glNormal3fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glNormal3i
        case glNormal3i_INDEX: {
            INDEXED_void_GLint_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint args = unpacked->args;
            glNormal3i(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glNormal3iv
        case glNormal3iv_INDEX: {
            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            glNormal3iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glNormal3s
        case glNormal3s_INDEX: {
            INDEXED_void_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort args = unpacked->args;
            glNormal3s(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glNormal3sv
        case glNormal3sv_INDEX: {
            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            glNormal3sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glNormalPointer
        case glNormalPointer_INDEX: {
            INDEXED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            glNormalPointer(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glOrtho
        case glOrtho_INDEX: {
            INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            glOrtho(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glPassThrough
        case glPassThrough_INDEX: {
            INDEXED_void_GLfloat *unpacked = (INDEXED_void_GLfloat *)packed;
            ARGS_void_GLfloat args = unpacked->args;
            glPassThrough(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glPixelMapfv
        case glPixelMapfv_INDEX: {
            INDEXED_void_GLenum_GLsizei_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLsizei_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_const_GLfloat___GENPT__ args = unpacked->args;
            glPixelMapfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glPixelMapuiv
        case glPixelMapuiv_INDEX: {
            INDEXED_void_GLenum_GLsizei_const_GLuint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLsizei_const_GLuint___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_const_GLuint___GENPT__ args = unpacked->args;
            glPixelMapuiv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glPixelMapusv
        case glPixelMapusv_INDEX: {
            INDEXED_void_GLenum_GLsizei_const_GLushort___GENPT__ *unpacked = (INDEXED_void_GLenum_GLsizei_const_GLushort___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_const_GLushort___GENPT__ args = unpacked->args;
            glPixelMapusv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glPixelStoref
        case glPixelStoref_INDEX: {
            INDEXED_void_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat args = unpacked->args;
            glPixelStoref(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glPixelStorei
        case glPixelStorei_INDEX: {
            INDEXED_void_GLenum_GLint *unpacked = (INDEXED_void_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLint args = unpacked->args;
            glPixelStorei(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glPixelTransferf
        case glPixelTransferf_INDEX: {
            INDEXED_void_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat args = unpacked->args;
            glPixelTransferf(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glPixelTransferi
        case glPixelTransferi_INDEX: {
            INDEXED_void_GLenum_GLint *unpacked = (INDEXED_void_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLint args = unpacked->args;
            glPixelTransferi(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glPixelZoom
        case glPixelZoom_INDEX: {
            INDEXED_void_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat args = unpacked->args;
            glPixelZoom(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glPointParameterf
        case glPointParameterf_INDEX: {
            INDEXED_void_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat args = unpacked->args;
            glPointParameterf(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glPointParameterfv
        case glPointParameterfv_INDEX: {
            INDEXED_void_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            glPointParameterfv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glPointParameteri
        case glPointParameteri_INDEX: {
            INDEXED_void_GLenum_GLint *unpacked = (INDEXED_void_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLint args = unpacked->args;
            glPointParameteri(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glPointParameteriv
        case glPointParameteriv_INDEX: {
            INDEXED_void_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLint___GENPT__ args = unpacked->args;
            glPointParameteriv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glPointSize
        case glPointSize_INDEX: {
            INDEXED_void_GLfloat *unpacked = (INDEXED_void_GLfloat *)packed;
            ARGS_void_GLfloat args = unpacked->args;
            glPointSize(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glPolygonMode
        case glPolygonMode_INDEX: {
            INDEXED_void_GLenum_GLenum *unpacked = (INDEXED_void_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLenum args = unpacked->args;
            glPolygonMode(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glPolygonOffset
        case glPolygonOffset_INDEX: {
            INDEXED_void_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat args = unpacked->args;
            glPolygonOffset(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glPolygonStipple
        case glPolygonStipple_INDEX: {
            INDEXED_void_const_GLubyte___GENPT__ *unpacked = (INDEXED_void_const_GLubyte___GENPT__ *)packed;
            ARGS_void_const_GLubyte___GENPT__ args = unpacked->args;
            glPolygonStipple(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glPopAttrib
        case glPopAttrib_INDEX: {
            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            glPopAttrib();
            break;
        }
        #endif
        #ifndef skip_index_glPopClientAttrib
        case glPopClientAttrib_INDEX: {
            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            glPopClientAttrib();
            break;
        }
        #endif
        #ifndef skip_index_glPopMatrix
        case glPopMatrix_INDEX: {
            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            glPopMatrix();
            break;
        }
        #endif
        #ifndef skip_index_glPopName
        case glPopName_INDEX: {
            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            glPopName();
            break;
        }
        #endif
        #ifndef skip_index_glPrioritizeTextures
        case glPrioritizeTextures_INDEX: {
            INDEXED_void_GLsizei_const_GLuint___GENPT___const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLsizei_const_GLuint___GENPT___const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLsizei_const_GLuint___GENPT___const_GLfloat___GENPT__ args = unpacked->args;
            glPrioritizeTextures(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glPushAttrib
        case glPushAttrib_INDEX: {
            INDEXED_void_GLbitfield *unpacked = (INDEXED_void_GLbitfield *)packed;
            ARGS_void_GLbitfield args = unpacked->args;
            glPushAttrib(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glPushClientAttrib
        case glPushClientAttrib_INDEX: {
            INDEXED_void_GLbitfield *unpacked = (INDEXED_void_GLbitfield *)packed;
            ARGS_void_GLbitfield args = unpacked->args;
            glPushClientAttrib(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glPushMatrix
        case glPushMatrix_INDEX: {
            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            glPushMatrix();
            break;
        }
        #endif
        #ifndef skip_index_glPushName
        case glPushName_INDEX: {
            INDEXED_void_GLuint *unpacked = (INDEXED_void_GLuint *)packed;
            ARGS_void_GLuint args = unpacked->args;
            glPushName(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos2d
        case glRasterPos2d_INDEX: {
            INDEXED_void_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble args = unpacked->args;
            glRasterPos2d(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos2dv
        case glRasterPos2dv_INDEX: {
            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            glRasterPos2dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos2f
        case glRasterPos2f_INDEX: {
            INDEXED_void_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat args = unpacked->args;
            glRasterPos2f(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos2fv
        case glRasterPos2fv_INDEX: {
            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            glRasterPos2fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos2i
        case glRasterPos2i_INDEX: {
            INDEXED_void_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint *)packed;
            ARGS_void_GLint_GLint args = unpacked->args;
            glRasterPos2i(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos2iv
        case glRasterPos2iv_INDEX: {
            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            glRasterPos2iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos2s
        case glRasterPos2s_INDEX: {
            INDEXED_void_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort args = unpacked->args;
            glRasterPos2s(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos2sv
        case glRasterPos2sv_INDEX: {
            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            glRasterPos2sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos3d
        case glRasterPos3d_INDEX: {
            INDEXED_void_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble args = unpacked->args;
            glRasterPos3d(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos3dv
        case glRasterPos3dv_INDEX: {
            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            glRasterPos3dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos3f
        case glRasterPos3f_INDEX: {
            INDEXED_void_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat args = unpacked->args;
            glRasterPos3f(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos3fv
        case glRasterPos3fv_INDEX: {
            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            glRasterPos3fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos3i
        case glRasterPos3i_INDEX: {
            INDEXED_void_GLint_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint args = unpacked->args;
            glRasterPos3i(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos3iv
        case glRasterPos3iv_INDEX: {
            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            glRasterPos3iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos3s
        case glRasterPos3s_INDEX: {
            INDEXED_void_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort args = unpacked->args;
            glRasterPos3s(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos3sv
        case glRasterPos3sv_INDEX: {
            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            glRasterPos3sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos4d
        case glRasterPos4d_INDEX: {
            INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            glRasterPos4d(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos4dv
        case glRasterPos4dv_INDEX: {
            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            glRasterPos4dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos4f
        case glRasterPos4f_INDEX: {
            INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            glRasterPos4f(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos4fv
        case glRasterPos4fv_INDEX: {
            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            glRasterPos4fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos4i
        case glRasterPos4i_INDEX: {
            INDEXED_void_GLint_GLint_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint_GLint args = unpacked->args;
            glRasterPos4i(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos4iv
        case glRasterPos4iv_INDEX: {
            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            glRasterPos4iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos4s
        case glRasterPos4s_INDEX: {
            INDEXED_void_GLshort_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort_GLshort args = unpacked->args;
            glRasterPos4s(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glRasterPos4sv
        case glRasterPos4sv_INDEX: {
            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            glRasterPos4sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glReadBuffer
        case glReadBuffer_INDEX: {
            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            glReadBuffer(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glReadPixels
        case glReadPixels_INDEX: {
            INDEXED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ args = unpacked->args;
            glReadPixels(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        #endif
        #ifndef skip_index_glRectd
        case glRectd_INDEX: {
            INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            glRectd(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glRectdv
        case glRectdv_INDEX: {
            INDEXED_void_const_GLdouble___GENPT___const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT___const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT___const_GLdouble___GENPT__ args = unpacked->args;
            glRectdv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glRectf
        case glRectf_INDEX: {
            INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            glRectf(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glRectfv
        case glRectfv_INDEX: {
            INDEXED_void_const_GLfloat___GENPT___const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT___const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT___const_GLfloat___GENPT__ args = unpacked->args;
            glRectfv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glRecti
        case glRecti_INDEX: {
            INDEXED_void_GLint_GLint_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint_GLint args = unpacked->args;
            glRecti(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glRectiv
        case glRectiv_INDEX: {
            INDEXED_void_const_GLint___GENPT___const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT___const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT___const_GLint___GENPT__ args = unpacked->args;
            glRectiv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glRects
        case glRects_INDEX: {
            INDEXED_void_GLshort_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort_GLshort args = unpacked->args;
            glRects(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glRectsv
        case glRectsv_INDEX: {
            INDEXED_void_const_GLshort___GENPT___const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT___const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT___const_GLshort___GENPT__ args = unpacked->args;
            glRectsv(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glRenderMode
        case glRenderMode_INDEX: {
            INDEXED_GLint_GLenum *unpacked = (INDEXED_GLint_GLenum *)packed;
            ARGS_GLint_GLenum args = unpacked->args;
            GLint *ret = (GLint *)ret_v;
            *ret =
            glRenderMode(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glResetHistogram
        case glResetHistogram_INDEX: {
            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            glResetHistogram(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glResetMinmax
        case glResetMinmax_INDEX: {
            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            glResetMinmax(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glRotated
        case glRotated_INDEX: {
            INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            glRotated(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glRotatef
        case glRotatef_INDEX: {
            INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            glRotatef(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glSampleCoverage
        case glSampleCoverage_INDEX: {
            INDEXED_void_GLfloat_GLboolean *unpacked = (INDEXED_void_GLfloat_GLboolean *)packed;
            ARGS_void_GLfloat_GLboolean args = unpacked->args;
            glSampleCoverage(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glScaled
        case glScaled_INDEX: {
            INDEXED_void_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble args = unpacked->args;
            glScaled(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glScalef
        case glScalef_INDEX: {
            INDEXED_void_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat args = unpacked->args;
            glScalef(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glScissor
        case glScissor_INDEX: {
            INDEXED_void_GLint_GLint_GLsizei_GLsizei *unpacked = (INDEXED_void_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            glScissor(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3b
        case glSecondaryColor3b_INDEX: {
            INDEXED_void_GLbyte_GLbyte_GLbyte *unpacked = (INDEXED_void_GLbyte_GLbyte_GLbyte *)packed;
            ARGS_void_GLbyte_GLbyte_GLbyte args = unpacked->args;
            glSecondaryColor3b(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3bv
        case glSecondaryColor3bv_INDEX: {
            INDEXED_void_const_GLbyte___GENPT__ *unpacked = (INDEXED_void_const_GLbyte___GENPT__ *)packed;
            ARGS_void_const_GLbyte___GENPT__ args = unpacked->args;
            glSecondaryColor3bv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3d
        case glSecondaryColor3d_INDEX: {
            INDEXED_void_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble args = unpacked->args;
            glSecondaryColor3d(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3dv
        case glSecondaryColor3dv_INDEX: {
            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            glSecondaryColor3dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3f
        case glSecondaryColor3f_INDEX: {
            INDEXED_void_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat args = unpacked->args;
            glSecondaryColor3f(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3fv
        case glSecondaryColor3fv_INDEX: {
            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            glSecondaryColor3fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3i
        case glSecondaryColor3i_INDEX: {
            INDEXED_void_GLint_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint args = unpacked->args;
            glSecondaryColor3i(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3iv
        case glSecondaryColor3iv_INDEX: {
            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            glSecondaryColor3iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3s
        case glSecondaryColor3s_INDEX: {
            INDEXED_void_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort args = unpacked->args;
            glSecondaryColor3s(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3sv
        case glSecondaryColor3sv_INDEX: {
            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            glSecondaryColor3sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3ub
        case glSecondaryColor3ub_INDEX: {
            INDEXED_void_GLubyte_GLubyte_GLubyte *unpacked = (INDEXED_void_GLubyte_GLubyte_GLubyte *)packed;
            ARGS_void_GLubyte_GLubyte_GLubyte args = unpacked->args;
            glSecondaryColor3ub(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3ubv
        case glSecondaryColor3ubv_INDEX: {
            INDEXED_void_const_GLubyte___GENPT__ *unpacked = (INDEXED_void_const_GLubyte___GENPT__ *)packed;
            ARGS_void_const_GLubyte___GENPT__ args = unpacked->args;
            glSecondaryColor3ubv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3ui
        case glSecondaryColor3ui_INDEX: {
            INDEXED_void_GLuint_GLuint_GLuint *unpacked = (INDEXED_void_GLuint_GLuint_GLuint *)packed;
            ARGS_void_GLuint_GLuint_GLuint args = unpacked->args;
            glSecondaryColor3ui(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3uiv
        case glSecondaryColor3uiv_INDEX: {
            INDEXED_void_const_GLuint___GENPT__ *unpacked = (INDEXED_void_const_GLuint___GENPT__ *)packed;
            ARGS_void_const_GLuint___GENPT__ args = unpacked->args;
            glSecondaryColor3uiv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3us
        case glSecondaryColor3us_INDEX: {
            INDEXED_void_GLushort_GLushort_GLushort *unpacked = (INDEXED_void_GLushort_GLushort_GLushort *)packed;
            ARGS_void_GLushort_GLushort_GLushort args = unpacked->args;
            glSecondaryColor3us(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColor3usv
        case glSecondaryColor3usv_INDEX: {
            INDEXED_void_const_GLushort___GENPT__ *unpacked = (INDEXED_void_const_GLushort___GENPT__ *)packed;
            ARGS_void_const_GLushort___GENPT__ args = unpacked->args;
            glSecondaryColor3usv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glSecondaryColorPointer
        case glSecondaryColorPointer_INDEX: {
            INDEXED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            glSecondaryColorPointer(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glSelectBuffer
        case glSelectBuffer_INDEX: {
            INDEXED_void_GLsizei_GLuint___GENPT__ *unpacked = (INDEXED_void_GLsizei_GLuint___GENPT__ *)packed;
            ARGS_void_GLsizei_GLuint___GENPT__ args = unpacked->args;
            glSelectBuffer(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glSeparableFilter2D
        case glSeparableFilter2D_INDEX: {
            INDEXED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT___const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT___const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT___const_GLvoid___GENPT__ args = unpacked->args;
            glSeparableFilter2D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        #endif
        #ifndef skip_index_glShadeModel
        case glShadeModel_INDEX: {
            INDEXED_void_GLenum *unpacked = (INDEXED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            glShadeModel(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glStencilFunc
        case glStencilFunc_INDEX: {
            INDEXED_void_GLenum_GLint_GLuint *unpacked = (INDEXED_void_GLenum_GLint_GLuint *)packed;
            ARGS_void_GLenum_GLint_GLuint args = unpacked->args;
            glStencilFunc(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glStencilMask
        case glStencilMask_INDEX: {
            INDEXED_void_GLuint *unpacked = (INDEXED_void_GLuint *)packed;
            ARGS_void_GLuint args = unpacked->args;
            glStencilMask(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glStencilOp
        case glStencilOp_INDEX: {
            INDEXED_void_GLenum_GLenum_GLenum *unpacked = (INDEXED_void_GLenum_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLenum_GLenum args = unpacked->args;
            glStencilOp(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord1d
        case glTexCoord1d_INDEX: {
            INDEXED_void_GLdouble *unpacked = (INDEXED_void_GLdouble *)packed;
            ARGS_void_GLdouble args = unpacked->args;
            glTexCoord1d(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord1dv
        case glTexCoord1dv_INDEX: {
            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            glTexCoord1dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord1f
        case glTexCoord1f_INDEX: {
            INDEXED_void_GLfloat *unpacked = (INDEXED_void_GLfloat *)packed;
            ARGS_void_GLfloat args = unpacked->args;
            glTexCoord1f(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord1fv
        case glTexCoord1fv_INDEX: {
            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            glTexCoord1fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord1i
        case glTexCoord1i_INDEX: {
            INDEXED_void_GLint *unpacked = (INDEXED_void_GLint *)packed;
            ARGS_void_GLint args = unpacked->args;
            glTexCoord1i(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord1iv
        case glTexCoord1iv_INDEX: {
            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            glTexCoord1iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord1s
        case glTexCoord1s_INDEX: {
            INDEXED_void_GLshort *unpacked = (INDEXED_void_GLshort *)packed;
            ARGS_void_GLshort args = unpacked->args;
            glTexCoord1s(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord1sv
        case glTexCoord1sv_INDEX: {
            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            glTexCoord1sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord2d
        case glTexCoord2d_INDEX: {
            INDEXED_void_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble args = unpacked->args;
            glTexCoord2d(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord2dv
        case glTexCoord2dv_INDEX: {
            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            glTexCoord2dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord2f
        case glTexCoord2f_INDEX: {
            INDEXED_void_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat args = unpacked->args;
            glTexCoord2f(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord2fv
        case glTexCoord2fv_INDEX: {
            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            glTexCoord2fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord2i
        case glTexCoord2i_INDEX: {
            INDEXED_void_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint *)packed;
            ARGS_void_GLint_GLint args = unpacked->args;
            glTexCoord2i(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord2iv
        case glTexCoord2iv_INDEX: {
            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            glTexCoord2iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord2s
        case glTexCoord2s_INDEX: {
            INDEXED_void_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort args = unpacked->args;
            glTexCoord2s(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord2sv
        case glTexCoord2sv_INDEX: {
            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            glTexCoord2sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord3d
        case glTexCoord3d_INDEX: {
            INDEXED_void_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble args = unpacked->args;
            glTexCoord3d(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord3dv
        case glTexCoord3dv_INDEX: {
            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            glTexCoord3dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord3f
        case glTexCoord3f_INDEX: {
            INDEXED_void_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat args = unpacked->args;
            glTexCoord3f(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord3fv
        case glTexCoord3fv_INDEX: {
            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            glTexCoord3fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord3i
        case glTexCoord3i_INDEX: {
            INDEXED_void_GLint_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint args = unpacked->args;
            glTexCoord3i(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord3iv
        case glTexCoord3iv_INDEX: {
            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            glTexCoord3iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord3s
        case glTexCoord3s_INDEX: {
            INDEXED_void_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort args = unpacked->args;
            glTexCoord3s(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord3sv
        case glTexCoord3sv_INDEX: {
            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            glTexCoord3sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord4d
        case glTexCoord4d_INDEX: {
            INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            glTexCoord4d(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord4dv
        case glTexCoord4dv_INDEX: {
            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            glTexCoord4dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord4f
        case glTexCoord4f_INDEX: {
            INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            glTexCoord4f(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord4fv
        case glTexCoord4fv_INDEX: {
            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            glTexCoord4fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord4i
        case glTexCoord4i_INDEX: {
            INDEXED_void_GLint_GLint_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint_GLint args = unpacked->args;
            glTexCoord4i(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord4iv
        case glTexCoord4iv_INDEX: {
            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            glTexCoord4iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord4s
        case glTexCoord4s_INDEX: {
            INDEXED_void_GLshort_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort_GLshort args = unpacked->args;
            glTexCoord4s(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoord4sv
        case glTexCoord4sv_INDEX: {
            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            glTexCoord4sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glTexCoordPointer
        case glTexCoordPointer_INDEX: {
            INDEXED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            glTexCoordPointer(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glTexEnvf
        case glTexEnvf_INDEX: {
            INDEXED_void_GLenum_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLenum_GLfloat args = unpacked->args;
            glTexEnvf(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexEnvfv
        case glTexEnvfv_INDEX: {
            INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            glTexEnvfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexEnvi
        case glTexEnvi_INDEX: {
            INDEXED_void_GLenum_GLenum_GLint *unpacked = (INDEXED_void_GLenum_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLint args = unpacked->args;
            glTexEnvi(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexEnviv
        case glTexEnviv_INDEX: {
            INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLint___GENPT__ args = unpacked->args;
            glTexEnviv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexGend
        case glTexGend_INDEX: {
            INDEXED_void_GLenum_GLenum_GLdouble *unpacked = (INDEXED_void_GLenum_GLenum_GLdouble *)packed;
            ARGS_void_GLenum_GLenum_GLdouble args = unpacked->args;
            glTexGend(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexGendv
        case glTexGendv_INDEX: {
            INDEXED_void_GLenum_GLenum_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLdouble___GENPT__ args = unpacked->args;
            glTexGendv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexGenf
        case glTexGenf_INDEX: {
            INDEXED_void_GLenum_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLenum_GLfloat args = unpacked->args;
            glTexGenf(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexGenfv
        case glTexGenfv_INDEX: {
            INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            glTexGenfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexGeni
        case glTexGeni_INDEX: {
            INDEXED_void_GLenum_GLenum_GLint *unpacked = (INDEXED_void_GLenum_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLint args = unpacked->args;
            glTexGeni(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexGeniv
        case glTexGeniv_INDEX: {
            INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLint___GENPT__ args = unpacked->args;
            glTexGeniv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexImage1D
        case glTexImage1D_INDEX: {
            INDEXED_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            glTexImage1D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        #endif
        #ifndef skip_index_glTexImage2D
        case glTexImage2D_INDEX: {
            INDEXED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            glTexImage2D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        #endif
        #ifndef skip_index_glTexImage3D
        case glTexImage3D_INDEX: {
            INDEXED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            glTexImage3D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        #endif
        #ifndef skip_index_glTexParameterf
        case glTexParameterf_INDEX: {
            INDEXED_void_GLenum_GLenum_GLfloat *unpacked = (INDEXED_void_GLenum_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLenum_GLfloat args = unpacked->args;
            glTexParameterf(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexParameterfv
        case glTexParameterfv_INDEX: {
            INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            glTexParameterfv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexParameteri
        case glTexParameteri_INDEX: {
            INDEXED_void_GLenum_GLenum_GLint *unpacked = (INDEXED_void_GLenum_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLint args = unpacked->args;
            glTexParameteri(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexParameteriv
        case glTexParameteriv_INDEX: {
            INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *unpacked = (INDEXED_void_GLenum_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLint___GENPT__ args = unpacked->args;
            glTexParameteriv(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTexSubImage1D
        case glTexSubImage1D_INDEX: {
            INDEXED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            glTexSubImage1D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        #endif
        #ifndef skip_index_glTexSubImage2D
        case glTexSubImage2D_INDEX: {
            INDEXED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            glTexSubImage2D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        #endif
        #ifndef skip_index_glTexSubImage3D
        case glTexSubImage3D_INDEX: {
            INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            glTexSubImage3D(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11);
            break;
        }
        #endif
        #ifndef skip_index_glTranslated
        case glTranslated_INDEX: {
            INDEXED_void_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble args = unpacked->args;
            glTranslated(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glTranslatef
        case glTranslatef_INDEX: {
            INDEXED_void_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat args = unpacked->args;
            glTranslatef(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glUnmapBuffer
        case glUnmapBuffer_INDEX: {
            INDEXED_GLboolean_GLenum *unpacked = (INDEXED_GLboolean_GLenum *)packed;
            ARGS_GLboolean_GLenum args = unpacked->args;
            GLboolean *ret = (GLboolean *)ret_v;
            *ret =
            glUnmapBuffer(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertex2d
        case glVertex2d_INDEX: {
            INDEXED_void_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble args = unpacked->args;
            glVertex2d(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glVertex2dv
        case glVertex2dv_INDEX: {
            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            glVertex2dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertex2f
        case glVertex2f_INDEX: {
            INDEXED_void_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat args = unpacked->args;
            glVertex2f(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glVertex2fv
        case glVertex2fv_INDEX: {
            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            glVertex2fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertex2i
        case glVertex2i_INDEX: {
            INDEXED_void_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint *)packed;
            ARGS_void_GLint_GLint args = unpacked->args;
            glVertex2i(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glVertex2iv
        case glVertex2iv_INDEX: {
            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            glVertex2iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertex2s
        case glVertex2s_INDEX: {
            INDEXED_void_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort args = unpacked->args;
            glVertex2s(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glVertex2sv
        case glVertex2sv_INDEX: {
            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            glVertex2sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertex3d
        case glVertex3d_INDEX: {
            INDEXED_void_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble args = unpacked->args;
            glVertex3d(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glVertex3dv
        case glVertex3dv_INDEX: {
            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            glVertex3dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertex3f
        case glVertex3f_INDEX: {
            INDEXED_void_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat args = unpacked->args;
            glVertex3f(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glVertex3fv
        case glVertex3fv_INDEX: {
            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            glVertex3fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertex3i
        case glVertex3i_INDEX: {
            INDEXED_void_GLint_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint args = unpacked->args;
            glVertex3i(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glVertex3iv
        case glVertex3iv_INDEX: {
            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            glVertex3iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertex3s
        case glVertex3s_INDEX: {
            INDEXED_void_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort args = unpacked->args;
            glVertex3s(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glVertex3sv
        case glVertex3sv_INDEX: {
            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            glVertex3sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertex4d
        case glVertex4d_INDEX: {
            INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            glVertex4d(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glVertex4dv
        case glVertex4dv_INDEX: {
            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            glVertex4dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertex4f
        case glVertex4f_INDEX: {
            INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            glVertex4f(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glVertex4fv
        case glVertex4fv_INDEX: {
            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            glVertex4fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertex4i
        case glVertex4i_INDEX: {
            INDEXED_void_GLint_GLint_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint_GLint args = unpacked->args;
            glVertex4i(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glVertex4iv
        case glVertex4iv_INDEX: {
            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            glVertex4iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertex4s
        case glVertex4s_INDEX: {
            INDEXED_void_GLshort_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort_GLshort args = unpacked->args;
            glVertex4s(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glVertex4sv
        case glVertex4sv_INDEX: {
            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            glVertex4sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glVertexPointer
        case glVertexPointer_INDEX: {
            INDEXED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (INDEXED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            glVertexPointer(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glViewport
        case glViewport_INDEX: {
            INDEXED_void_GLint_GLint_GLsizei_GLsizei *unpacked = (INDEXED_void_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            glViewport(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos2d
        case glWindowPos2d_INDEX: {
            INDEXED_void_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble args = unpacked->args;
            glWindowPos2d(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos2dv
        case glWindowPos2dv_INDEX: {
            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            glWindowPos2dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos2f
        case glWindowPos2f_INDEX: {
            INDEXED_void_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat args = unpacked->args;
            glWindowPos2f(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos2fv
        case glWindowPos2fv_INDEX: {
            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            glWindowPos2fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos2i
        case glWindowPos2i_INDEX: {
            INDEXED_void_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint *)packed;
            ARGS_void_GLint_GLint args = unpacked->args;
            glWindowPos2i(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos2iv
        case glWindowPos2iv_INDEX: {
            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            glWindowPos2iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos2s
        case glWindowPos2s_INDEX: {
            INDEXED_void_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort args = unpacked->args;
            glWindowPos2s(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos2sv
        case glWindowPos2sv_INDEX: {
            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            glWindowPos2sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos3d
        case glWindowPos3d_INDEX: {
            INDEXED_void_GLdouble_GLdouble_GLdouble *unpacked = (INDEXED_void_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble args = unpacked->args;
            glWindowPos3d(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos3dv
        case glWindowPos3dv_INDEX: {
            INDEXED_void_const_GLdouble___GENPT__ *unpacked = (INDEXED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            glWindowPos3dv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos3f
        case glWindowPos3f_INDEX: {
            INDEXED_void_GLfloat_GLfloat_GLfloat *unpacked = (INDEXED_void_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat args = unpacked->args;
            glWindowPos3f(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos3fv
        case glWindowPos3fv_INDEX: {
            INDEXED_void_const_GLfloat___GENPT__ *unpacked = (INDEXED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            glWindowPos3fv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos3i
        case glWindowPos3i_INDEX: {
            INDEXED_void_GLint_GLint_GLint *unpacked = (INDEXED_void_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint args = unpacked->args;
            glWindowPos3i(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos3iv
        case glWindowPos3iv_INDEX: {
            INDEXED_void_const_GLint___GENPT__ *unpacked = (INDEXED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            glWindowPos3iv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos3s
        case glWindowPos3s_INDEX: {
            INDEXED_void_GLshort_GLshort_GLshort *unpacked = (INDEXED_void_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort args = unpacked->args;
            glWindowPos3s(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glWindowPos3sv
        case glWindowPos3sv_INDEX: {
            INDEXED_void_const_GLshort___GENPT__ *unpacked = (INDEXED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            glWindowPos3sv(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glXBindHyperpipeSGIX
        case glXBindHyperpipeSGIX_INDEX: {
            INDEXED_int_Display___GENPT___int *unpacked = (INDEXED_int_Display___GENPT___int *)packed;
            ARGS_int_Display___GENPT___int args = unpacked->args;
            int *ret = (int *)ret_v;
            *ret =
            glXBindHyperpipeSGIX(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXBindSwapBarrierSGIX
        case glXBindSwapBarrierSGIX_INDEX: {
            INDEXED_void_uint32_t_uint32_t *unpacked = (INDEXED_void_uint32_t_uint32_t *)packed;
            ARGS_void_uint32_t_uint32_t args = unpacked->args;
            glXBindSwapBarrierSGIX(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXChangeDrawableAttributes
        case glXChangeDrawableAttributes_INDEX: {
            INDEXED_void_uint32_t *unpacked = (INDEXED_void_uint32_t *)packed;
            ARGS_void_uint32_t args = unpacked->args;
            glXChangeDrawableAttributes(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glXChangeDrawableAttributesSGIX
        case glXChangeDrawableAttributesSGIX_INDEX: {
            INDEXED_void_uint32_t *unpacked = (INDEXED_void_uint32_t *)packed;
            ARGS_void_uint32_t args = unpacked->args;
            glXChangeDrawableAttributesSGIX(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glXChooseFBConfig
        case glXChooseFBConfig_INDEX: {
            INDEXED_GLXFBConfig___GENPT___Display___GENPT___int_const_int___GENPT___int___GENPT__ *unpacked = (INDEXED_GLXFBConfig___GENPT___Display___GENPT___int_const_int___GENPT___int___GENPT__ *)packed;
            ARGS_GLXFBConfig___GENPT___Display___GENPT___int_const_int___GENPT___int___GENPT__ args = unpacked->args;
            GLXFBConfig * *ret = (GLXFBConfig * *)ret_v;
            *ret =
            glXChooseFBConfig(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glXChooseVisual
        case glXChooseVisual_INDEX: {
            INDEXED_XVisualInfo___GENPT___Display___GENPT___int_int___GENPT__ *unpacked = (INDEXED_XVisualInfo___GENPT___Display___GENPT___int_int___GENPT__ *)packed;
            ARGS_XVisualInfo___GENPT___Display___GENPT___int_int___GENPT__ args = unpacked->args;
            XVisualInfo * *ret = (XVisualInfo * *)ret_v;
            *ret =
            glXChooseVisual(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXClientInfo
        case glXClientInfo_INDEX: {
            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            glXClientInfo();
            break;
        }
        #endif
        #ifndef skip_index_glXCopyContext
        case glXCopyContext_INDEX: {
            INDEXED_void_Display___GENPT___GLXContext_GLXContext_unsigned_long *unpacked = (INDEXED_void_Display___GENPT___GLXContext_GLXContext_unsigned_long *)packed;
            ARGS_void_Display___GENPT___GLXContext_GLXContext_unsigned_long args = unpacked->args;
            glXCopyContext(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glXCreateContext
        case glXCreateContext_INDEX: {
            INDEXED_GLXContext_Display___GENPT___XVisualInfo___GENPT___GLXContext_Bool *unpacked = (INDEXED_GLXContext_Display___GENPT___XVisualInfo___GENPT___GLXContext_Bool *)packed;
            ARGS_GLXContext_Display___GENPT___XVisualInfo___GENPT___GLXContext_Bool args = unpacked->args;
            GLXContext *ret = (GLXContext *)ret_v;
            *ret =
            glXCreateContext(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glXCreateContextWithConfigSGIX
        case glXCreateContextWithConfigSGIX_INDEX: {
            INDEXED_void_uint32_t_uint32_t_uint32_t_uint32_t *unpacked = (INDEXED_void_uint32_t_uint32_t_uint32_t_uint32_t *)packed;
            ARGS_void_uint32_t_uint32_t_uint32_t_uint32_t args = unpacked->args;
            glXCreateContextWithConfigSGIX(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glXCreateGLXPbufferSGIX
        case glXCreateGLXPbufferSGIX_INDEX: {
            INDEXED_void_uint32_t_uint32_t *unpacked = (INDEXED_void_uint32_t_uint32_t *)packed;
            ARGS_void_uint32_t_uint32_t args = unpacked->args;
            glXCreateGLXPbufferSGIX(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXCreateGLXPixmap
        case glXCreateGLXPixmap_INDEX: {
            INDEXED_GLXPixmap_Display___GENPT___XVisualInfo___GENPT___Pixmap *unpacked = (INDEXED_GLXPixmap_Display___GENPT___XVisualInfo___GENPT___Pixmap *)packed;
            ARGS_GLXPixmap_Display___GENPT___XVisualInfo___GENPT___Pixmap args = unpacked->args;
            GLXPixmap *ret = (GLXPixmap *)ret_v;
            *ret =
            glXCreateGLXPixmap(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXCreateGLXPixmapWithConfigSGIX
        case glXCreateGLXPixmapWithConfigSGIX_INDEX: {
            INDEXED_void_uint32_t_uint32_t_uint32_t *unpacked = (INDEXED_void_uint32_t_uint32_t_uint32_t *)packed;
            ARGS_void_uint32_t_uint32_t_uint32_t args = unpacked->args;
            glXCreateGLXPixmapWithConfigSGIX(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXCreateGLXVideoSourceSGIX
        case glXCreateGLXVideoSourceSGIX_INDEX: {
            INDEXED_void_Display___GENPT___uint32_t_uint32_t_uint32_t_uint32_t_uint32_t *unpacked = (INDEXED_void_Display___GENPT___uint32_t_uint32_t_uint32_t_uint32_t_uint32_t *)packed;
            ARGS_void_Display___GENPT___uint32_t_uint32_t_uint32_t_uint32_t_uint32_t args = unpacked->args;
            glXCreateGLXVideoSourceSGIX(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glXCreateNewContext
        case glXCreateNewContext_INDEX: {
            INDEXED_GLXContext_Display___GENPT___GLXFBConfig_int_GLXContext_Bool *unpacked = (INDEXED_GLXContext_Display___GENPT___GLXFBConfig_int_GLXContext_Bool *)packed;
            ARGS_GLXContext_Display___GENPT___GLXFBConfig_int_GLXContext_Bool args = unpacked->args;
            GLXContext *ret = (GLXContext *)ret_v;
            *ret =
            glXCreateNewContext(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glXCreatePbuffer
        case glXCreatePbuffer_INDEX: {
            INDEXED_GLXPbuffer_Display___GENPT___GLXFBConfig_const_int___GENPT__ *unpacked = (INDEXED_GLXPbuffer_Display___GENPT___GLXFBConfig_const_int___GENPT__ *)packed;
            ARGS_GLXPbuffer_Display___GENPT___GLXFBConfig_const_int___GENPT__ args = unpacked->args;
            GLXPbuffer *ret = (GLXPbuffer *)ret_v;
            *ret =
            glXCreatePbuffer(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXCreatePixmap
        case glXCreatePixmap_INDEX: {
            INDEXED_GLXPixmap_Display___GENPT___GLXFBConfig_Pixmap_const_int___GENPT__ *unpacked = (INDEXED_GLXPixmap_Display___GENPT___GLXFBConfig_Pixmap_const_int___GENPT__ *)packed;
            ARGS_GLXPixmap_Display___GENPT___GLXFBConfig_Pixmap_const_int___GENPT__ args = unpacked->args;
            GLXPixmap *ret = (GLXPixmap *)ret_v;
            *ret =
            glXCreatePixmap(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glXCreateWindow
        case glXCreateWindow_INDEX: {
            INDEXED_GLXWindow_Display___GENPT___GLXFBConfig_Window_const_int___GENPT__ *unpacked = (INDEXED_GLXWindow_Display___GENPT___GLXFBConfig_Window_const_int___GENPT__ *)packed;
            ARGS_GLXWindow_Display___GENPT___GLXFBConfig_Window_const_int___GENPT__ args = unpacked->args;
            GLXWindow *ret = (GLXWindow *)ret_v;
            *ret =
            glXCreateWindow(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glXDestroyContext
        case glXDestroyContext_INDEX: {
            INDEXED_void_Display___GENPT___GLXContext *unpacked = (INDEXED_void_Display___GENPT___GLXContext *)packed;
            ARGS_void_Display___GENPT___GLXContext args = unpacked->args;
            glXDestroyContext(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXDestroyGLXPbufferSGIX
        case glXDestroyGLXPbufferSGIX_INDEX: {
            INDEXED_void_uint32_t *unpacked = (INDEXED_void_uint32_t *)packed;
            ARGS_void_uint32_t args = unpacked->args;
            glXDestroyGLXPbufferSGIX(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glXDestroyGLXPixmap
        case glXDestroyGLXPixmap_INDEX: {
            INDEXED_void_Display___GENPT___GLXPixmap *unpacked = (INDEXED_void_Display___GENPT___GLXPixmap *)packed;
            ARGS_void_Display___GENPT___GLXPixmap args = unpacked->args;
            glXDestroyGLXPixmap(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXDestroyGLXVideoSourceSGIX
        case glXDestroyGLXVideoSourceSGIX_INDEX: {
            INDEXED_void_Display___GENPT___uint32_t *unpacked = (INDEXED_void_Display___GENPT___uint32_t *)packed;
            ARGS_void_Display___GENPT___uint32_t args = unpacked->args;
            glXDestroyGLXVideoSourceSGIX(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXDestroyHyperpipeConfigSGIX
        case glXDestroyHyperpipeConfigSGIX_INDEX: {
            INDEXED_int_Display___GENPT___int *unpacked = (INDEXED_int_Display___GENPT___int *)packed;
            ARGS_int_Display___GENPT___int args = unpacked->args;
            int *ret = (int *)ret_v;
            *ret =
            glXDestroyHyperpipeConfigSGIX(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXDestroyPbuffer
        case glXDestroyPbuffer_INDEX: {
            INDEXED_void_Display___GENPT___GLXPbuffer *unpacked = (INDEXED_void_Display___GENPT___GLXPbuffer *)packed;
            ARGS_void_Display___GENPT___GLXPbuffer args = unpacked->args;
            glXDestroyPbuffer(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXDestroyPixmap
        case glXDestroyPixmap_INDEX: {
            INDEXED_void_Display___GENPT___GLXPixmap *unpacked = (INDEXED_void_Display___GENPT___GLXPixmap *)packed;
            ARGS_void_Display___GENPT___GLXPixmap args = unpacked->args;
            glXDestroyPixmap(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXDestroyWindow
        case glXDestroyWindow_INDEX: {
            INDEXED_void_Display___GENPT___GLXWindow *unpacked = (INDEXED_void_Display___GENPT___GLXWindow *)packed;
            ARGS_void_Display___GENPT___GLXWindow args = unpacked->args;
            glXDestroyWindow(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXGetClientString
        case glXGetClientString_INDEX: {
            INDEXED_const_char___GENPT___Display___GENPT___int *unpacked = (INDEXED_const_char___GENPT___Display___GENPT___int *)packed;
            ARGS_const_char___GENPT___Display___GENPT___int args = unpacked->args;
            const char * *ret = (const char * *)ret_v;
            *ret =
            glXGetClientString(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXGetConfig
        case glXGetConfig_INDEX: {
            INDEXED_int_Display___GENPT___XVisualInfo___GENPT___int_int___GENPT__ *unpacked = (INDEXED_int_Display___GENPT___XVisualInfo___GENPT___int_int___GENPT__ *)packed;
            ARGS_int_Display___GENPT___XVisualInfo___GENPT___int_int___GENPT__ args = unpacked->args;
            int *ret = (int *)ret_v;
            *ret =
            glXGetConfig(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glXGetCurrentContext
        case glXGetCurrentContext_INDEX: {
            INDEXED_GLXContext *unpacked = (INDEXED_GLXContext *)packed;
            ARGS_GLXContext args = unpacked->args;
            GLXContext *ret = (GLXContext *)ret_v;
            *ret =
            glXGetCurrentContext();
            break;
        }
        #endif
        #ifndef skip_index_glXGetCurrentDisplay
        case glXGetCurrentDisplay_INDEX: {
            INDEXED_Display___GENPT__ *unpacked = (INDEXED_Display___GENPT__ *)packed;
            ARGS_Display___GENPT__ args = unpacked->args;
            Display * *ret = (Display * *)ret_v;
            *ret =
            glXGetCurrentDisplay();
            break;
        }
        #endif
        #ifndef skip_index_glXGetCurrentDrawable
        case glXGetCurrentDrawable_INDEX: {
            INDEXED_GLXDrawable *unpacked = (INDEXED_GLXDrawable *)packed;
            ARGS_GLXDrawable args = unpacked->args;
            GLXDrawable *ret = (GLXDrawable *)ret_v;
            *ret =
            glXGetCurrentDrawable();
            break;
        }
        #endif
        #ifndef skip_index_glXGetCurrentReadDrawable
        case glXGetCurrentReadDrawable_INDEX: {
            INDEXED_GLXDrawable *unpacked = (INDEXED_GLXDrawable *)packed;
            ARGS_GLXDrawable args = unpacked->args;
            GLXDrawable *ret = (GLXDrawable *)ret_v;
            *ret =
            glXGetCurrentReadDrawable();
            break;
        }
        #endif
        #ifndef skip_index_glXGetDrawableAttributes
        case glXGetDrawableAttributes_INDEX: {
            INDEXED_void_uint32_t *unpacked = (INDEXED_void_uint32_t *)packed;
            ARGS_void_uint32_t args = unpacked->args;
            glXGetDrawableAttributes(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glXGetDrawableAttributesSGIX
        case glXGetDrawableAttributesSGIX_INDEX: {
            INDEXED_void_uint32_t *unpacked = (INDEXED_void_uint32_t *)packed;
            ARGS_void_uint32_t args = unpacked->args;
            glXGetDrawableAttributesSGIX(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glXGetFBConfigAttrib
        case glXGetFBConfigAttrib_INDEX: {
            INDEXED_int_Display___GENPT___GLXFBConfig_int_int___GENPT__ *unpacked = (INDEXED_int_Display___GENPT___GLXFBConfig_int_int___GENPT__ *)packed;
            ARGS_int_Display___GENPT___GLXFBConfig_int_int___GENPT__ args = unpacked->args;
            int *ret = (int *)ret_v;
            *ret =
            glXGetFBConfigAttrib(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glXGetFBConfigs
        case glXGetFBConfigs_INDEX: {
            INDEXED_GLXFBConfig___GENPT___Display___GENPT___int_int___GENPT__ *unpacked = (INDEXED_GLXFBConfig___GENPT___Display___GENPT___int_int___GENPT__ *)packed;
            ARGS_GLXFBConfig___GENPT___Display___GENPT___int_int___GENPT__ args = unpacked->args;
            GLXFBConfig * *ret = (GLXFBConfig * *)ret_v;
            *ret =
            glXGetFBConfigs(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXGetFBConfigsSGIX
        case glXGetFBConfigsSGIX_INDEX: {
            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            glXGetFBConfigsSGIX();
            break;
        }
        #endif
        #ifndef skip_index_glXGetProcAddress
        case glXGetProcAddress_INDEX: {
            INDEXED___GLXextFuncPtr_const_GLubyte___GENPT__ *unpacked = (INDEXED___GLXextFuncPtr_const_GLubyte___GENPT__ *)packed;
            ARGS___GLXextFuncPtr_const_GLubyte___GENPT__ args = unpacked->args;
            __GLXextFuncPtr *ret = (__GLXextFuncPtr *)ret_v;
            *ret =
            glXGetProcAddress(args.a1);
            break;
        }
        #endif
        #ifndef skip_index_glXGetSelectedEvent
        case glXGetSelectedEvent_INDEX: {
            INDEXED_void_Display___GENPT___GLXDrawable_unsigned_long___GENPT__ *unpacked = (INDEXED_void_Display___GENPT___GLXDrawable_unsigned_long___GENPT__ *)packed;
            ARGS_void_Display___GENPT___GLXDrawable_unsigned_long___GENPT__ args = unpacked->args;
            glXGetSelectedEvent(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXGetVisualConfigs
        case glXGetVisualConfigs_INDEX: {
            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            glXGetVisualConfigs();
            break;
        }
        #endif
        #ifndef skip_index_glXGetVisualFromFBConfig
        case glXGetVisualFromFBConfig_INDEX: {
            INDEXED_XVisualInfo___GENPT___Display___GENPT___GLXFBConfig *unpacked = (INDEXED_XVisualInfo___GENPT___Display___GENPT___GLXFBConfig *)packed;
            ARGS_XVisualInfo___GENPT___Display___GENPT___GLXFBConfig args = unpacked->args;
            XVisualInfo * *ret = (XVisualInfo * *)ret_v;
            *ret =
            glXGetVisualFromFBConfig(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXHyperpipeAttribSGIX
        case glXHyperpipeAttribSGIX_INDEX: {
            INDEXED_int_Display___GENPT___int_int_int_const_void___GENPT__ *unpacked = (INDEXED_int_Display___GENPT___int_int_int_const_void___GENPT__ *)packed;
            ARGS_int_Display___GENPT___int_int_int_const_void___GENPT__ args = unpacked->args;
            int *ret = (int *)ret_v;
            *ret =
            glXHyperpipeAttribSGIX(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glXHyperpipeConfigSGIX
        case glXHyperpipeConfigSGIX_INDEX: {
            INDEXED_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__ *unpacked = (INDEXED_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__ *)packed;
            ARGS_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__ args = unpacked->args;
            int *ret = (int *)ret_v;
            *ret =
            glXHyperpipeConfigSGIX(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glXIsDirect
        case glXIsDirect_INDEX: {
            INDEXED_Bool_Display___GENPT___GLXContext *unpacked = (INDEXED_Bool_Display___GENPT___GLXContext *)packed;
            ARGS_Bool_Display___GENPT___GLXContext args = unpacked->args;
            Bool *ret = (Bool *)ret_v;
            *ret =
            glXIsDirect(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXJoinSwapGroupSGIX
        case glXJoinSwapGroupSGIX_INDEX: {
            INDEXED_void_uint32_t_uint32_t *unpacked = (INDEXED_void_uint32_t_uint32_t *)packed;
            ARGS_void_uint32_t_uint32_t args = unpacked->args;
            glXJoinSwapGroupSGIX(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXMakeContextCurrent
        case glXMakeContextCurrent_INDEX: {
            INDEXED_Bool_Display___GENPT___GLXDrawable_GLXDrawable_GLXContext *unpacked = (INDEXED_Bool_Display___GENPT___GLXDrawable_GLXDrawable_GLXContext *)packed;
            ARGS_Bool_Display___GENPT___GLXDrawable_GLXDrawable_GLXContext args = unpacked->args;
            Bool *ret = (Bool *)ret_v;
            *ret =
            glXMakeContextCurrent(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glXMakeCurrent
        case glXMakeCurrent_INDEX: {
            INDEXED_Bool_Display___GENPT___GLXDrawable_GLXContext *unpacked = (INDEXED_Bool_Display___GENPT___GLXDrawable_GLXContext *)packed;
            ARGS_Bool_Display___GENPT___GLXDrawable_GLXContext args = unpacked->args;
            Bool *ret = (Bool *)ret_v;
            *ret =
            glXMakeCurrent(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXMakeCurrentReadSGI
        case glXMakeCurrentReadSGI_INDEX: {
            INDEXED_void_uint32_t_uint32_t_uint32_t *unpacked = (INDEXED_void_uint32_t_uint32_t_uint32_t *)packed;
            ARGS_void_uint32_t_uint32_t_uint32_t args = unpacked->args;
            glXMakeCurrentReadSGI(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXQueryContext
        case glXQueryContext_INDEX: {
            INDEXED_int_Display___GENPT___GLXContext_int_int___GENPT__ *unpacked = (INDEXED_int_Display___GENPT___GLXContext_int_int___GENPT__ *)packed;
            ARGS_int_Display___GENPT___GLXContext_int_int___GENPT__ args = unpacked->args;
            int *ret = (int *)ret_v;
            *ret =
            glXQueryContext(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glXQueryContextInfoEXT
        case glXQueryContextInfoEXT_INDEX: {
            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            glXQueryContextInfoEXT();
            break;
        }
        #endif
        #ifndef skip_index_glXQueryDrawable
        case glXQueryDrawable_INDEX: {
            INDEXED_void_Display___GENPT___GLXDrawable_int_unsigned_int___GENPT__ *unpacked = (INDEXED_void_Display___GENPT___GLXDrawable_int_unsigned_int___GENPT__ *)packed;
            ARGS_void_Display___GENPT___GLXDrawable_int_unsigned_int___GENPT__ args = unpacked->args;
            glXQueryDrawable(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glXQueryExtension
        case glXQueryExtension_INDEX: {
            INDEXED_Bool_Display___GENPT___int___GENPT___int___GENPT__ *unpacked = (INDEXED_Bool_Display___GENPT___int___GENPT___int___GENPT__ *)packed;
            ARGS_Bool_Display___GENPT___int___GENPT___int___GENPT__ args = unpacked->args;
            Bool *ret = (Bool *)ret_v;
            *ret =
            glXQueryExtension(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXQueryExtensionsString
        case glXQueryExtensionsString_INDEX: {
            INDEXED_const_char___GENPT___Display___GENPT___int *unpacked = (INDEXED_const_char___GENPT___Display___GENPT___int *)packed;
            ARGS_const_char___GENPT___Display___GENPT___int args = unpacked->args;
            const char * *ret = (const char * *)ret_v;
            *ret =
            glXQueryExtensionsString(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXQueryHyperpipeAttribSGIX
        case glXQueryHyperpipeAttribSGIX_INDEX: {
            INDEXED_int_Display___GENPT___int_int_int_const_void___GENPT__ *unpacked = (INDEXED_int_Display___GENPT___int_int_int_const_void___GENPT__ *)packed;
            ARGS_int_Display___GENPT___int_int_int_const_void___GENPT__ args = unpacked->args;
            int *ret = (int *)ret_v;
            *ret =
            glXQueryHyperpipeAttribSGIX(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        #endif
        #ifndef skip_index_glXQueryHyperpipeBestAttribSGIX
        case glXQueryHyperpipeBestAttribSGIX_INDEX: {
            INDEXED_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__ *unpacked = (INDEXED_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__ *)packed;
            ARGS_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__ args = unpacked->args;
            int *ret = (int *)ret_v;
            *ret =
            glXQueryHyperpipeBestAttribSGIX(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        #endif
        #ifndef skip_index_glXQueryHyperpipeConfigSGIX
        case glXQueryHyperpipeConfigSGIX_INDEX: {
            INDEXED_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__ *unpacked = (INDEXED_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__ *)packed;
            ARGS_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__ args = unpacked->args;
            GLXHyperpipeConfigSGIX * *ret = (GLXHyperpipeConfigSGIX * *)ret_v;
            *ret =
            glXQueryHyperpipeConfigSGIX(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXQueryHyperpipeNetworkSGIX
        case glXQueryHyperpipeNetworkSGIX_INDEX: {
            INDEXED_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__ *unpacked = (INDEXED_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__ *)packed;
            ARGS_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__ args = unpacked->args;
            GLXHyperpipeNetworkSGIX * *ret = (GLXHyperpipeNetworkSGIX * *)ret_v;
            *ret =
            glXQueryHyperpipeNetworkSGIX(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXQueryMaxSwapBarriersSGIX
        case glXQueryMaxSwapBarriersSGIX_INDEX: {
            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            glXQueryMaxSwapBarriersSGIX();
            break;
        }
        #endif
        #ifndef skip_index_glXQueryServerString
        case glXQueryServerString_INDEX: {
            INDEXED_const_char___GENPT___Display___GENPT___int_int *unpacked = (INDEXED_const_char___GENPT___Display___GENPT___int_int *)packed;
            ARGS_const_char___GENPT___Display___GENPT___int_int args = unpacked->args;
            const char * *ret = (const char * *)ret_v;
            *ret =
            glXQueryServerString(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXQueryVersion
        case glXQueryVersion_INDEX: {
            INDEXED_Bool_Display___GENPT___int___GENPT___int___GENPT__ *unpacked = (INDEXED_Bool_Display___GENPT___int___GENPT___int___GENPT__ *)packed;
            ARGS_Bool_Display___GENPT___int___GENPT___int___GENPT__ args = unpacked->args;
            Bool *ret = (Bool *)ret_v;
            *ret =
            glXQueryVersion(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXRender
        case glXRender_INDEX: {
            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            glXRender();
            break;
        }
        #endif
        #ifndef skip_index_glXRenderLarge
        case glXRenderLarge_INDEX: {
            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            glXRenderLarge();
            break;
        }
        #endif
        #ifndef skip_index_glXSelectEvent
        case glXSelectEvent_INDEX: {
            INDEXED_void_Display___GENPT___GLXDrawable_unsigned_long *unpacked = (INDEXED_void_Display___GENPT___GLXDrawable_unsigned_long *)packed;
            ARGS_void_Display___GENPT___GLXDrawable_unsigned_long args = unpacked->args;
            glXSelectEvent(args.a1, args.a2, args.a3);
            break;
        }
        #endif
        #ifndef skip_index_glXSwapBuffers
        case glXSwapBuffers_INDEX: {
            INDEXED_void_Display___GENPT___GLXDrawable *unpacked = (INDEXED_void_Display___GENPT___GLXDrawable *)packed;
            ARGS_void_Display___GENPT___GLXDrawable args = unpacked->args;
            glXSwapBuffers(args.a1, args.a2);
            break;
        }
        #endif
        #ifndef skip_index_glXSwapIntervalSGI
        case glXSwapIntervalSGI_INDEX: {
            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            glXSwapIntervalSGI();
            break;
        }
        #endif
        #ifndef skip_index_glXUseXFont
        case glXUseXFont_INDEX: {
            INDEXED_void_Font_int_int_int *unpacked = (INDEXED_void_Font_int_int_int *)packed;
            ARGS_void_Font_int_int_int args = unpacked->args;
            glXUseXFont(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        #endif
        #ifndef skip_index_glXVendorPrivate
        case glXVendorPrivate_INDEX: {
            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            glXVendorPrivate();
            break;
        }
        #endif
        #ifndef skip_index_glXVendorPrivateWithReply
        case glXVendorPrivateWithReply_INDEX: {
            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            glXVendorPrivateWithReply();
            break;
        }
        #endif
        #ifndef skip_index_glXWaitGL
        case glXWaitGL_INDEX: {
            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            glXWaitGL();
            break;
        }
        #endif
        #ifndef skip_index_glXWaitX
        case glXWaitX_INDEX: {
            INDEXED_void *unpacked = (INDEXED_void *)packed;
            ARGS_void args = unpacked->args;
            glXWaitX();
            break;
        }
        #endif
    }
}
#endif
