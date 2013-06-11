#include <stdio.h>
#include "gl.h"

void glPackedCall(const UnknownCall *packed) {
    switch (packed->format) {
        case FORMAT_void_GLenum_GLfloat: {
            PACKED_void_GLenum_GLfloat *unpacked = (PACKED_void_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLfixed: {
            PACKED_void_GLenum_GLfixed *unpacked = (PACKED_void_GLenum_GLfixed *)packed;
            ARGS_void_GLenum_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint: {
            PACKED_void_GLuint *unpacked = (PACKED_void_GLuint *)packed;
            ARGS_void_GLuint args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLuint_GLuint: {
            PACKED_void_GLuint_GLuint *unpacked = (PACKED_void_GLuint_GLuint *)packed;
            ARGS_void_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum: {
            PACKED_void_GLenum *unpacked = (PACKED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLuint_GLchar: {
            PACKED_void_GLuint_GLchar *unpacked = (PACKED_void_GLuint_GLchar *)packed;
            ARGS_void_GLuint_GLchar args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint: {
            PACKED_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint *unpacked = (PACKED_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint *)packed;
            ARGS_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint: {
            PACKED_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint *unpacked = (PACKED_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint *)packed;
            ARGS_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint: {
            PACKED_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint *unpacked = (PACKED_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint *)packed;
            ARGS_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11, args.a12);
            break;
        }
        case FORMAT_Boolean_GLsizei_GLuint_GLboolean: {
            PACKED_Boolean_GLsizei_GLuint_GLboolean *unpacked = (PACKED_Boolean_GLsizei_GLuint_GLboolean *)packed;
            ARGS_Boolean_GLsizei_GLuint_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLint: {
            PACKED_void_GLint *unpacked = (PACKED_void_GLint *)packed;
            ARGS_void_GLint args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLuint_GLuint: {
            PACKED_void_GLenum_GLint_GLenum_GLsizei_GLuint_GLuint *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLsizei_GLuint_GLuint *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLsizei_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLhandleARB_GLhandleARB: {
            PACKED_void_GLhandleARB_GLhandleARB *unpacked = (PACKED_void_GLhandleARB_GLhandleARB *)packed;
            ARGS_void_GLhandleARB_GLhandleARB args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLenum: {
            PACKED_void_GLuint_GLenum *unpacked = (PACKED_void_GLuint_GLenum *)packed;
            ARGS_void_GLuint_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void: {
            PACKED_void *unpacked = (PACKED_void *)packed;
            ARGS_void args = unpacked->args;
            unpacked->func();
            break;
        }
        case FORMAT_void_GLenum_GLuint: {
            PACKED_void_GLenum_GLuint *unpacked = (PACKED_void_GLenum_GLuint *)packed;
            ARGS_void_GLenum_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLuint: {
            PACKED_void_GLenum_GLuint_GLuint *unpacked = (PACKED_void_GLenum_GLuint_GLuint *)packed;
            ARGS_void_GLenum_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLchar: {
            PACKED_void_GLuint_GLuint_GLchar *unpacked = (PACKED_void_GLuint_GLuint_GLchar *)packed;
            ARGS_void_GLuint_GLuint_GLchar args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLhandleARB_GLuint_GLcharARB: {
            PACKED_void_GLhandleARB_GLuint_GLcharARB *unpacked = (PACKED_void_GLhandleARB_GLuint_GLcharARB *)packed;
            ARGS_void_GLhandleARB_GLuint_GLcharARB args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLuint_GLintptr: {
            PACKED_void_GLenum_GLuint_GLuint_GLintptr *unpacked = (PACKED_void_GLenum_GLuint_GLuint_GLintptr *)packed;
            ARGS_void_GLenum_GLuint_GLuint_GLintptr args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLuint_GLintptr_GLsizeiptr: {
            PACKED_void_GLenum_GLuint_GLuint_GLintptr_GLsizeiptr *unpacked = (PACKED_void_GLenum_GLuint_GLuint_GLintptr_GLsizeiptr *)packed;
            ARGS_void_GLenum_GLuint_GLuint_GLintptr_GLsizeiptr args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLuint_GLchar: {
            PACKED_void_GLuint_GLuint_GLuint_GLchar *unpacked = (PACKED_void_GLuint_GLuint_GLuint_GLchar *)packed;
            ARGS_void_GLuint_GLuint_GLuint_GLchar args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLint_GLboolean_GLint_GLenum_GLenum: {
            PACKED_void_GLuint_GLuint_GLint_GLboolean_GLint_GLenum_GLenum *unpacked = (PACKED_void_GLuint_GLuint_GLint_GLboolean_GLint_GLenum_GLenum *)packed;
            ARGS_void_GLuint_GLuint_GLint_GLboolean_GLint_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLint_GLboolean_GLint_GLenum_GLint: {
            PACKED_void_GLuint_GLuint_GLint_GLboolean_GLint_GLenum_GLint *unpacked = (PACKED_void_GLuint_GLuint_GLint_GLboolean_GLint_GLenum_GLint *)packed;
            ARGS_void_GLuint_GLuint_GLint_GLboolean_GLint_GLenum_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_UInt32_GLenum_GLenum: {
            PACKED_UInt32_GLenum_GLenum *unpacked = (PACKED_UInt32_GLenum_GLenum *)packed;
            ARGS_UInt32_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLuint: {
            PACKED_void_GLenum_GLenum_GLuint *unpacked = (PACKED_void_GLenum_GLenum_GLuint *)packed;
            ARGS_void_GLenum_GLenum_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_UInt32_GLenum: {
            PACKED_UInt32_GLenum *unpacked = (PACKED_UInt32_GLenum *)packed;
            ARGS_UInt32_GLenum args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_UInt32_GLenum_GLenum_GLenum: {
            PACKED_UInt32_GLenum_GLenum_GLenum *unpacked = (PACKED_UInt32_GLenum_GLenum_GLenum *)packed;
            ARGS_UInt32_GLenum_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLintptr_GLsizei: {
            PACKED_void_GLuint_GLuint_GLintptr_GLsizei *unpacked = (PACKED_void_GLuint_GLuint_GLintptr_GLsizei *)packed;
            ARGS_void_GLuint_GLuint_GLintptr_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLenum_GLintptrARB: {
            PACKED_void_GLuint_GLuint_GLenum_GLintptrARB *unpacked = (PACKED_void_GLuint_GLuint_GLenum_GLintptrARB *)packed;
            ARGS_void_GLuint_GLuint_GLenum_GLintptrARB args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLenum_GLenum_GLuint: {
            PACKED_void_GLuint_GLuint_GLenum_GLenum_GLuint *unpacked = (PACKED_void_GLuint_GLuint_GLenum_GLenum_GLuint *)packed;
            ARGS_void_GLuint_GLuint_GLenum_GLenum_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLbyte_GLbyte_GLbyte: {
            PACKED_void_GLbyte_GLbyte_GLbyte *unpacked = (PACKED_void_GLbyte_GLbyte_GLbyte *)packed;
            ARGS_void_GLbyte_GLbyte_GLbyte args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLbyte: {
            PACKED_void_GLbyte *unpacked = (PACKED_void_GLbyte *)packed;
            ARGS_void_GLbyte args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLdouble_GLdouble_GLdouble: {
            PACKED_void_GLdouble_GLdouble_GLdouble *unpacked = (PACKED_void_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLdouble: {
            PACKED_void_GLdouble *unpacked = (PACKED_void_GLdouble *)packed;
            ARGS_void_GLdouble args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLfloat: {
            PACKED_void_GLfloat *unpacked = (PACKED_void_GLfloat *)packed;
            ARGS_void_GLfloat args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLint_GLint_GLint: {
            PACKED_void_GLint_GLint_GLint *unpacked = (PACKED_void_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLshort_GLshort_GLshort: {
            PACKED_void_GLshort_GLshort_GLshort *unpacked = (PACKED_void_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLshort: {
            PACKED_void_GLshort *unpacked = (PACKED_void_GLshort *)packed;
            ARGS_void_GLshort args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLvoid: {
            PACKED_void_GLenum_GLsizei_GLvoid *unpacked = (PACKED_void_GLenum_GLsizei_GLvoid *)packed;
            ARGS_void_GLenum_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_GLubyte: {
            PACKED_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_GLubyte *unpacked = (PACKED_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_GLubyte *)packed;
            ARGS_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_GLubyte args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLsizei_GLsizei_GLfixed_GLfixed_GLfixed_GLfixed_GLubyte: {
            PACKED_void_GLsizei_GLsizei_GLfixed_GLfixed_GLfixed_GLfixed_GLubyte *unpacked = (PACKED_void_GLsizei_GLsizei_GLfixed_GLfixed_GLfixed_GLfixed_GLubyte *)packed;
            ARGS_void_GLsizei_GLsizei_GLfixed_GLfixed_GLfixed_GLfixed_GLubyte args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed: {
            PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed *unpacked = (PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed *)packed;
            ARGS_void_GLfixed_GLfixed_GLfixed_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLenum: {
            PACKED_void_GLenum_GLenum *unpacked = (PACKED_void_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLenum: {
            PACKED_void_GLuint_GLenum_GLenum *unpacked = (PACKED_void_GLuint_GLenum_GLenum *)packed;
            ARGS_void_GLuint_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLenum: {
            PACKED_void_GLenum_GLenum_GLenum_GLenum *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLenum_GLenum_GLenum: {
            PACKED_void_GLuint_GLenum_GLenum_GLenum_GLenum *unpacked = (PACKED_void_GLuint_GLenum_GLenum_GLenum_GLenum *)packed;
            ARGS_void_GLuint_GLenum_GLenum_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLint_GLint_GLint_GLint_GLint_GLint_GLint_GLint_GLbitfield_GLenum: {
            PACKED_void_GLint_GLint_GLint_GLint_GLint_GLint_GLint_GLint_GLbitfield_GLenum *unpacked = (PACKED_void_GLint_GLint_GLint_GLint_GLint_GLint_GLint_GLint_GLbitfield_GLenum *)packed;
            ARGS_void_GLint_GLint_GLint_GLint_GLint_GLint_GLint_GLint_GLbitfield_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLuint64EXT_GLsizeiptr: {
            PACKED_void_GLenum_GLuint_GLuint64EXT_GLsizeiptr *unpacked = (PACKED_void_GLenum_GLuint_GLuint64EXT_GLsizeiptr *)packed;
            ARGS_void_GLenum_GLuint_GLuint64EXT_GLsizeiptr args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLsizeiptr_GLvoid_GLenum: {
            PACKED_void_GLenum_GLsizeiptr_GLvoid_GLenum *unpacked = (PACKED_void_GLenum_GLsizeiptr_GLvoid_GLenum *)packed;
            ARGS_void_GLenum_GLsizeiptr_GLvoid_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLsizeiptrARB_GLvoid_GLenum: {
            PACKED_void_GLenum_GLsizeiptrARB_GLvoid_GLenum *unpacked = (PACKED_void_GLenum_GLsizeiptrARB_GLvoid_GLenum *)packed;
            ARGS_void_GLenum_GLsizeiptrARB_GLvoid_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint: {
            PACKED_void_GLenum_GLenum_GLint *unpacked = (PACKED_void_GLenum_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLintptr_GLsizeiptr_GLvoid: {
            PACKED_void_GLenum_GLintptr_GLsizeiptr_GLvoid *unpacked = (PACKED_void_GLenum_GLintptr_GLsizeiptr_GLvoid *)packed;
            ARGS_void_GLenum_GLintptr_GLsizeiptr_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLintptrARB_GLsizeiptrARB_GLvoid: {
            PACKED_void_GLenum_GLintptrARB_GLsizeiptrARB_GLvoid *unpacked = (PACKED_void_GLenum_GLintptrARB_GLsizeiptrARB_GLvoid *)packed;
            ARGS_void_GLenum_GLintptrARB_GLsizeiptrARB_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLsizei_GLenum_GLvoid: {
            PACKED_void_GLsizei_GLenum_GLvoid *unpacked = (PACKED_void_GLsizei_GLenum_GLvoid *)packed;
            ARGS_void_GLsizei_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_GLenum_GLenum: {
            PACKED_GLenum_GLenum *unpacked = (PACKED_GLenum_GLenum *)packed;
            ARGS_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_FramebufferStatus_GLuint_GLenum: {
            PACKED_FramebufferStatus_GLuint_GLenum *unpacked = (PACKED_FramebufferStatus_GLuint_GLenum *)packed;
            ARGS_FramebufferStatus_GLuint_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLbitfield: {
            PACKED_void_GLbitfield *unpacked = (PACKED_void_GLbitfield *)packed;
            ARGS_void_GLbitfield args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLenum_void___GENPT__: {
            PACKED_void_GLenum_GLenum_GLenum_GLenum_void___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLenum_void___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLenum_void___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLintptr_GLsizeiptr_GLenum_GLenum_void___GENPT__: {
            PACKED_void_GLenum_GLenum_GLintptr_GLsizeiptr_GLenum_GLenum_void___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLintptr_GLsizeiptr_GLenum_GLenum_void___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLintptr_GLsizeiptr_GLenum_GLenum_void___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLfloat_GLint: {
            PACKED_void_GLenum_GLint_GLfloat_GLint *unpacked = (PACKED_void_GLenum_GLint_GLfloat_GLint *)packed;
            ARGS_void_GLenum_GLint_GLfloat_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLfloat: {
            PACKED_void_GLenum_GLint_GLfloat *unpacked = (PACKED_void_GLenum_GLint_GLfloat *)packed;
            ARGS_void_GLenum_GLint_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint: {
            PACKED_void_GLenum_GLint_GLint *unpacked = (PACKED_void_GLenum_GLint_GLint *)packed;
            ARGS_void_GLenum_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLuint: {
            PACKED_void_GLenum_GLint_GLuint *unpacked = (PACKED_void_GLenum_GLint_GLuint *)packed;
            ARGS_void_GLenum_GLint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLint_GLint_GLint_GLint: {
            PACKED_void_GLint_GLint_GLint_GLint *unpacked = (PACKED_void_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLuint_GLuint: {
            PACKED_void_GLuint_GLuint_GLuint_GLuint *unpacked = (PACKED_void_GLuint_GLuint_GLuint_GLuint *)packed;
            ARGS_void_GLuint_GLuint_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLclampf: {
            PACKED_void_GLclampf *unpacked = (PACKED_void_GLclampf *)packed;
            ARGS_void_GLclampf args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLfixed: {
            PACKED_void_GLfixed *unpacked = (PACKED_void_GLfixed *)packed;
            ARGS_void_GLfixed args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLenum_GLenum_void___GENPT__: {
            PACKED_void_GLuint_GLenum_GLenum_GLenum_void___GENPT__ *unpacked = (PACKED_void_GLuint_GLenum_GLenum_GLenum_void___GENPT__ *)packed;
            ARGS_void_GLuint_GLenum_GLenum_GLenum_void___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLenum_GLenum_GLsizeiptr_GLsizeiptr_void___GENPT__: {
            PACKED_void_GLuint_GLenum_GLenum_GLenum_GLsizeiptr_GLsizeiptr_void___GENPT__ *unpacked = (PACKED_void_GLuint_GLenum_GLenum_GLenum_GLsizeiptr_GLsizeiptr_void___GENPT__ *)packed;
            ARGS_void_GLuint_GLenum_GLenum_GLenum_GLsizeiptr_GLsizeiptr_void___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_GLenum_GLsync_GLbitfield_GLuint64: {
            PACKED_GLenum_GLsync_GLbitfield_GLuint64 *unpacked = (PACKED_GLenum_GLsync_GLbitfield_GLuint64 *)packed;
            ARGS_GLenum_GLsync_GLbitfield_GLuint64 args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLdouble: {
            PACKED_void_GLenum_GLdouble *unpacked = (PACKED_void_GLenum_GLdouble *)packed;
            ARGS_void_GLenum_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLhalfNV_GLhalfNV_GLhalfNV: {
            PACKED_void_GLhalfNV_GLhalfNV_GLhalfNV *unpacked = (PACKED_void_GLhalfNV_GLhalfNV_GLhalfNV *)packed;
            ARGS_void_GLhalfNV_GLhalfNV_GLhalfNV args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLhalfNV: {
            PACKED_void_GLhalfNV *unpacked = (PACKED_void_GLhalfNV *)packed;
            ARGS_void_GLhalfNV args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLubyte_GLubyte_GLubyte: {
            PACKED_void_GLubyte_GLubyte_GLubyte *unpacked = (PACKED_void_GLubyte_GLubyte_GLubyte *)packed;
            ARGS_void_GLubyte_GLubyte_GLubyte args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLubyte: {
            PACKED_void_GLubyte *unpacked = (PACKED_void_GLubyte *)packed;
            ARGS_void_GLubyte args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLuint: {
            PACKED_void_GLuint_GLuint_GLuint *unpacked = (PACKED_void_GLuint_GLuint_GLuint *)packed;
            ARGS_void_GLuint_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLushort_GLushort_GLushort: {
            PACKED_void_GLushort_GLushort_GLushort *unpacked = (PACKED_void_GLushort_GLushort_GLushort *)packed;
            ARGS_void_GLushort_GLushort_GLushort args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLushort: {
            PACKED_void_GLushort *unpacked = (PACKED_void_GLushort *)packed;
            ARGS_void_GLushort args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLfixed_GLfixed_GLfixed: {
            PACKED_void_GLfixed_GLfixed_GLfixed *unpacked = (PACKED_void_GLfixed_GLfixed_GLfixed *)packed;
            ARGS_void_GLfixed_GLfixed_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLbyte_GLbyte_GLbyte_GLbyte: {
            PACKED_void_GLbyte_GLbyte_GLbyte_GLbyte *unpacked = (PACKED_void_GLbyte_GLbyte_GLbyte_GLbyte *)packed;
            ARGS_void_GLbyte_GLbyte_GLbyte_GLbyte args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLdouble_GLdouble_GLdouble_GLdouble: {
            PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        case FORMAT_void_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV: {
            PACKED_void_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV *unpacked = (PACKED_void_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV *)packed;
            ARGS_void_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLshort_GLshort_GLshort_GLshort: {
            PACKED_void_GLshort_GLshort_GLshort_GLshort *unpacked = (PACKED_void_GLshort_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort_GLshort args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLubyte_GLubyte_GLubyte_GLubyte: {
            PACKED_void_GLubyte_GLubyte_GLubyte_GLubyte *unpacked = (PACKED_void_GLubyte_GLubyte_GLubyte_GLubyte *)packed;
            ARGS_void_GLubyte_GLubyte_GLubyte_GLubyte args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat: {
            PACKED_void_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat *unpacked = (PACKED_void_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat *)packed;
            ARGS_void_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLubyte_GLfloat: {
            PACKED_void_GLubyte_GLfloat *unpacked = (PACKED_void_GLubyte_GLfloat *)packed;
            ARGS_void_GLubyte_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLushort_GLushort_GLushort_GLushort: {
            PACKED_void_GLushort_GLushort_GLushort_GLushort *unpacked = (PACKED_void_GLushort_GLushort_GLushort_GLushort *)packed;
            ARGS_void_GLushort_GLushort_GLushort_GLushort args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLint_GLenum_GLsizei: {
            PACKED_void_GLint_GLenum_GLsizei *unpacked = (PACKED_void_GLint_GLenum_GLsizei *)packed;
            ARGS_void_GLint_GLenum_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint: {
            PACKED_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint *unpacked = (PACKED_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint *)packed;
            ARGS_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint: {
            PACKED_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint *unpacked = (PACKED_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint *)packed;
            ARGS_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint: {
            PACKED_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint *unpacked = (PACKED_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint *)packed;
            ARGS_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11, args.a12, args.a13);
            break;
        }
        case FORMAT_void_GLboolean_GLboolean_GLboolean_GLboolean: {
            PACKED_void_GLboolean_GLboolean_GLboolean_GLboolean *unpacked = (PACKED_void_GLboolean_GLboolean_GLboolean_GLboolean *)packed;
            ARGS_void_GLboolean_GLboolean_GLboolean_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLboolean_GLboolean_GLboolean_GLboolean: {
            PACKED_void_GLuint_GLboolean_GLboolean_GLboolean_GLboolean *unpacked = (PACKED_void_GLuint_GLboolean_GLboolean_GLboolean_GLboolean *)packed;
            ARGS_void_GLuint_GLboolean_GLboolean_GLboolean_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLint_GLenum_GLsizei_GLvoid: {
            PACKED_void_GLint_GLenum_GLsizei_GLvoid *unpacked = (PACKED_void_GLint_GLenum_GLsizei_GLvoid *)packed;
            ARGS_void_GLint_GLenum_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLint_GLenum_GLsizei_GLsizei_GLvoid: {
            PACKED_void_GLint_GLenum_GLsizei_GLsizei_GLvoid *unpacked = (PACKED_void_GLint_GLenum_GLsizei_GLsizei_GLvoid *)packed;
            ARGS_void_GLint_GLenum_GLsizei_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLint_GLenum_GLint_GLvoid___GENPT___GLint: {
            PACKED_void_GLint_GLenum_GLint_GLvoid___GENPT___GLint *unpacked = (PACKED_void_GLint_GLenum_GLint_GLvoid___GENPT___GLint *)packed;
            ARGS_void_GLint_GLenum_GLint_GLvoid___GENPT___GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLint_GLenum_GLvoid___GENPT__: {
            PACKED_void_GLint_GLenum_GLvoid___GENPT__ *unpacked = (PACKED_void_GLint_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLint_GLenum_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid: {
            PACKED_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLsizei_GLenum_GLenum_GLvoid: {
            PACKED_void_GLenum_GLenum_GLsizei_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLenum_GLsizei_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLenum_GLsizei_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLfloat: {
            PACKED_void_GLenum_GLenum_GLfloat *unpacked = (PACKED_void_GLenum_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLenum_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum: {
            PACKED_void_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum_GLboolean_GLboolean_GLboolean: {
            PACKED_void_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum_GLboolean_GLboolean_GLboolean *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum_GLboolean_GLboolean_GLboolean *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum_GLboolean_GLboolean_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        case FORMAT_void_GLenum_GLint: {
            PACKED_void_GLenum_GLint *unpacked = (PACKED_void_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLhandleARB: {
            PACKED_void_GLhandleARB *unpacked = (PACKED_void_GLhandleARB *)packed;
            ARGS_void_GLhandleARB args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLchar___GENPT___GLint: {
            PACKED_void_GLuint_GLsizei_GLchar___GENPT___GLint *unpacked = (PACKED_void_GLuint_GLsizei_GLchar___GENPT___GLint *)packed;
            ARGS_void_GLuint_GLsizei_GLchar___GENPT___GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid: {
            PACKED_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid: {
            PACKED_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid: {
            PACKED_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid: {
            PACKED_void_GLenum_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid: {
            PACKED_void_GLenum_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid: {
            PACKED_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11, args.a12);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid: {
            PACKED_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid: {
            PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid: {
            PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid: {
            PACKED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid *unpacked = (PACKED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid *)packed;
            ARGS_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid: {
            PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid *unpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid: {
            PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid *unpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid: {
            PACKED_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid *unpacked = (PACKED_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid *)packed;
            ARGS_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid: {
            PACKED_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid *unpacked = (PACKED_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid *)packed;
            ARGS_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid: {
            PACKED_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid *unpacked = (PACKED_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid *)packed;
            ARGS_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid: {
            PACKED_void_GLuint_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid *unpacked = (PACKED_void_GLuint_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid *)packed;
            ARGS_void_GLuint_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid: {
            PACKED_void_GLuint_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid *unpacked = (PACKED_void_GLuint_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid *)packed;
            ARGS_void_GLuint_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid: {
            PACKED_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid *unpacked = (PACKED_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid *)packed;
            ARGS_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11, args.a12);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid: {
            PACKED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLfixed: {
            PACKED_void_GLenum_GLenum_GLfixed *unpacked = (PACKED_void_GLenum_GLenum_GLfixed *)packed;
            ARGS_void_GLenum_GLenum_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLintptr_GLintptr_GLsizeiptr: {
            PACKED_void_GLenum_GLenum_GLintptr_GLintptr_GLsizeiptr *unpacked = (PACKED_void_GLenum_GLenum_GLintptr_GLintptr_GLsizeiptr *)packed;
            ARGS_void_GLenum_GLenum_GLintptr_GLintptr_GLsizeiptr args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLint_GLint_GLsizei: {
            PACKED_void_GLenum_GLsizei_GLint_GLint_GLsizei *unpacked = (PACKED_void_GLenum_GLsizei_GLint_GLint_GLsizei *)packed;
            ARGS_void_GLenum_GLsizei_GLint_GLint_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLint_GLsizei: {
            PACKED_void_GLenum_GLenum_GLint_GLint_GLsizei *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLint_GLsizei *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLint_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLint_GLsizei_GLsizei: {
            PACKED_void_GLenum_GLenum_GLint_GLint_GLsizei_GLsizei *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei: {
            PACKED_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei *unpacked = (PACKED_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei *)packed;
            ARGS_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11, args.a12, args.a13, args.a14, args.a15);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint: {
            PACKED_void_GLenum_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint: {
            PACKED_void_GLenum_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei: {
            PACKED_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei: {
            PACKED_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei: {
            PACKED_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        case FORMAT_void_GLint_GLint_GLsizei_GLsizei_GLenum: {
            PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum *unpacked = (PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum *)packed;
            ARGS_void_GLint_GLint_GLsizei_GLsizei_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint: {
            PACKED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint: {
            PACKED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLsizei: {
            PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei *unpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei: {
            PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *unpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei: {
            PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *unpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint: {
            PACKED_void_GLuint_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint *unpacked = (PACKED_void_GLuint_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint *)packed;
            ARGS_void_GLuint_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint: {
            PACKED_void_GLuint_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint *unpacked = (PACKED_void_GLuint_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint *)packed;
            ARGS_void_GLuint_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei: {
            PACKED_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei *unpacked = (PACKED_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei *)packed;
            ARGS_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei: {
            PACKED_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *unpacked = (PACKED_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei: {
            PACKED_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *unpacked = (PACKED_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        case FORMAT_void_GLsizei_GLenum_GLvoid_GLuint_GLenum_GLenum_GLfloat: {
            PACKED_void_GLsizei_GLenum_GLvoid_GLuint_GLenum_GLenum_GLfloat *unpacked = (PACKED_void_GLsizei_GLenum_GLvoid_GLuint_GLenum_GLenum_GLfloat *)packed;
            ARGS_void_GLsizei_GLenum_GLvoid_GLuint_GLenum_GLenum_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_UInt32: {
            PACKED_UInt32 *unpacked = (PACKED_UInt32 *)packed;
            ARGS_UInt32 args = unpacked->args;
            unpacked->func();
            break;
        }
        case FORMAT_handleARB: {
            PACKED_handleARB *unpacked = (PACKED_handleARB *)packed;
            ARGS_handleARB args = unpacked->args;
            unpacked->func();
            break;
        }
        case FORMAT_handleARB_GLenum: {
            PACKED_handleARB_GLenum *unpacked = (PACKED_handleARB_GLenum *)packed;
            ARGS_handleARB_GLenum args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_UInt32_GLenum_GLchar: {
            PACKED_UInt32_GLenum_GLchar *unpacked = (PACKED_UInt32_GLenum_GLchar *)packed;
            ARGS_UInt32_GLenum_GLchar args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_UInt32_GLenum_GLsizei_GLchar__GENPT__const: {
            PACKED_UInt32_GLenum_GLsizei_GLchar__GENPT__const *unpacked = (PACKED_UInt32_GLenum_GLsizei_GLchar__GENPT__const *)packed;
            ARGS_UInt32_GLenum_GLsizei_GLchar__GENPT__const args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_sync_struct__cl_context___GENPT___struct__cl_event___GENPT___GLbitfield: {
            PACKED_sync_struct__cl_context___GENPT___struct__cl_event___GENPT___GLbitfield *unpacked = (PACKED_sync_struct__cl_context___GENPT___struct__cl_event___GENPT___GLbitfield *)packed;
            ARGS_sync_struct__cl_context___GENPT___struct__cl_event___GENPT___GLbitfield args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLDEBUGPROC_void___GENPT__: {
            PACKED_void_GLDEBUGPROC_void___GENPT__ *unpacked = (PACKED_void_GLDEBUGPROC_void___GENPT__ *)packed;
            ARGS_void_GLDEBUGPROC_void___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLDEBUGPROCAMD_GLvoid: {
            PACKED_void_GLDEBUGPROCAMD_GLvoid *unpacked = (PACKED_void_GLDEBUGPROCAMD_GLvoid *)packed;
            ARGS_void_GLDEBUGPROCAMD_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLDEBUGPROCARB_GLvoid: {
            PACKED_void_GLDEBUGPROCARB_GLvoid *unpacked = (PACKED_void_GLDEBUGPROCARB_GLvoid *)packed;
            ARGS_void_GLDEBUGPROCARB_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLsizei_GLuint_GLboolean: {
            PACKED_void_GLenum_GLenum_GLenum_GLsizei_GLuint_GLboolean *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLsizei_GLuint_GLboolean *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLsizei_GLuint_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLsizei_GLuint_GLboolean: {
            PACKED_void_GLenum_GLenum_GLsizei_GLuint_GLboolean *unpacked = (PACKED_void_GLenum_GLenum_GLsizei_GLuint_GLboolean *)packed;
            ARGS_void_GLenum_GLenum_GLsizei_GLuint_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLuint_GLenum_GLsizei_GLchar: {
            PACKED_void_GLenum_GLenum_GLuint_GLenum_GLsizei_GLchar *unpacked = (PACKED_void_GLenum_GLenum_GLuint_GLenum_GLsizei_GLchar *)packed;
            ARGS_void_GLenum_GLenum_GLuint_GLenum_GLsizei_GLchar args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLuint_GLsizei_GLchar: {
            PACKED_void_GLenum_GLenum_GLuint_GLsizei_GLchar *unpacked = (PACKED_void_GLenum_GLenum_GLuint_GLsizei_GLchar *)packed;
            ARGS_void_GLenum_GLenum_GLuint_GLsizei_GLchar args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble: {
            PACKED_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble *unpacked = (PACKED_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble *)packed;
            ARGS_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11, args.a12, args.a13, args.a14);
            break;
        }
        case FORMAT_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat: {
            PACKED_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat *unpacked = (PACKED_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11, args.a12, args.a13, args.a14);
            break;
        }
        case FORMAT_void_GLuint_GLsizei: {
            PACKED_void_GLuint_GLsizei *unpacked = (PACKED_void_GLuint_GLsizei *)packed;
            ARGS_void_GLuint_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLsizei_GLuint: {
            PACKED_void_GLsizei_GLuint *unpacked = (PACKED_void_GLsizei_GLuint *)packed;
            ARGS_void_GLsizei_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLint_GLchar: {
            PACKED_void_GLint_GLchar *unpacked = (PACKED_void_GLint_GLchar *)packed;
            ARGS_void_GLint_GLchar args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLsync: {
            PACKED_void_GLsync *unpacked = (PACKED_void_GLsync *)packed;
            ARGS_void_GLsync args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLclampd_GLclampd: {
            PACKED_void_GLclampd_GLclampd *unpacked = (PACKED_void_GLclampd_GLclampd *)packed;
            ARGS_void_GLclampd_GLclampd args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLdouble_GLdouble: {
            PACKED_void_GLdouble_GLdouble *unpacked = (PACKED_void_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLboolean: {
            PACKED_void_GLboolean *unpacked = (PACKED_void_GLboolean *)packed;
            ARGS_void_GLboolean args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLdouble: {
            PACKED_void_GLuint_GLsizei_GLdouble *unpacked = (PACKED_void_GLuint_GLsizei_GLdouble *)packed;
            ARGS_void_GLuint_GLsizei_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLdouble_GLdouble: {
            PACKED_void_GLuint_GLdouble_GLdouble *unpacked = (PACKED_void_GLuint_GLdouble_GLdouble *)packed;
            ARGS_void_GLuint_GLdouble_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLclampf_GLclampf: {
            PACKED_void_GLclampf_GLclampf *unpacked = (PACKED_void_GLclampf_GLclampf *)packed;
            ARGS_void_GLclampf_GLclampf args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLfixed_GLfixed: {
            PACKED_void_GLfixed_GLfixed *unpacked = (PACKED_void_GLfixed_GLfixed *)packed;
            ARGS_void_GLfixed_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLfloat: {
            PACKED_void_GLenum_GLsizei_GLfloat *unpacked = (PACKED_void_GLenum_GLsizei_GLfloat *)packed;
            ARGS_void_GLenum_GLsizei_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLintptr: {
            PACKED_void_GLintptr *unpacked = (PACKED_void_GLintptr *)packed;
            ARGS_void_GLintptr args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLsizei: {
            PACKED_void_GLenum_GLint_GLsizei *unpacked = (PACKED_void_GLenum_GLint_GLsizei *)packed;
            ARGS_void_GLenum_GLint_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLvoid: {
            PACKED_void_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLsizei_GLsizei: {
            PACKED_void_GLenum_GLint_GLsizei_GLsizei *unpacked = (PACKED_void_GLenum_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_GLint_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLsizei_GLsizei_GLuint: {
            PACKED_void_GLenum_GLint_GLsizei_GLsizei_GLuint *unpacked = (PACKED_void_GLenum_GLint_GLsizei_GLsizei_GLuint *)packed;
            ARGS_void_GLenum_GLint_GLsizei_GLsizei_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLsizei_GLenum: {
            PACKED_void_GLsizei_GLenum *unpacked = (PACKED_void_GLsizei_GLenum *)packed;
            ARGS_void_GLsizei_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLsizei: {
            PACKED_void_GLenum_GLsizei *unpacked = (PACKED_void_GLenum_GLsizei *)packed;
            ARGS_void_GLenum_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLenum_GLvoid: {
            PACKED_void_GLenum_GLsizei_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLsizei_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLsizei_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLenum_GLvoid_GLint: {
            PACKED_void_GLenum_GLsizei_GLenum_GLvoid_GLint *unpacked = (PACKED_void_GLenum_GLsizei_GLenum_GLvoid_GLint *)packed;
            ARGS_void_GLenum_GLsizei_GLenum_GLvoid_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLvoid: {
            PACKED_void_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLenum_GLvoid_GLsizei: {
            PACKED_void_GLenum_GLsizei_GLenum_GLvoid_GLsizei *unpacked = (PACKED_void_GLenum_GLsizei_GLenum_GLvoid_GLsizei *)packed;
            ARGS_void_GLenum_GLsizei_GLenum_GLvoid_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLenum_void___GENPT___GLsizei_GLuint: {
            PACKED_void_GLenum_GLsizei_GLenum_void___GENPT___GLsizei_GLuint *unpacked = (PACKED_void_GLenum_GLsizei_GLenum_void___GENPT___GLsizei_GLuint *)packed;
            ARGS_void_GLenum_GLsizei_GLenum_void___GENPT___GLsizei_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLenum_GLvoid_GLsizei_GLint: {
            PACKED_void_GLenum_GLsizei_GLenum_GLvoid_GLsizei_GLint *unpacked = (PACKED_void_GLenum_GLsizei_GLenum_GLvoid_GLsizei_GLint *)packed;
            ARGS_void_GLenum_GLsizei_GLenum_GLvoid_GLsizei_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLenum_void___GENPT___GLsizei_GLint_GLuint: {
            PACKED_void_GLenum_GLsizei_GLenum_void___GENPT___GLsizei_GLint_GLuint *unpacked = (PACKED_void_GLenum_GLsizei_GLenum_void___GENPT___GLsizei_GLint_GLuint *)packed;
            ARGS_void_GLenum_GLsizei_GLenum_void___GENPT___GLsizei_GLint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLsizei_GLsizei_GLenum_GLenum_GLvoid: {
            PACKED_void_GLsizei_GLsizei_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLsizei_GLsizei_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLsizei_GLsizei_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLuint_GLint_GLsizei: {
            PACKED_void_GLenum_GLuint_GLuint_GLint_GLsizei *unpacked = (PACKED_void_GLenum_GLuint_GLuint_GLint_GLsizei *)packed;
            ARGS_void_GLenum_GLuint_GLuint_GLint_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLuint_GLsizei: {
            PACKED_void_GLenum_GLuint_GLuint_GLsizei *unpacked = (PACKED_void_GLenum_GLuint_GLuint_GLsizei *)packed;
            ARGS_void_GLenum_GLuint_GLuint_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLuint_GLsizei_GLenum_GLvoid: {
            PACKED_void_GLenum_GLuint_GLuint_GLsizei_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLuint_GLuint_GLsizei_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLuint_GLuint_GLsizei_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLuint_GLsizei_GLenum_GLvoid_GLint: {
            PACKED_void_GLenum_GLuint_GLuint_GLsizei_GLenum_GLvoid_GLint *unpacked = (PACKED_void_GLenum_GLuint_GLuint_GLsizei_GLenum_GLvoid_GLint *)packed;
            ARGS_void_GLenum_GLuint_GLuint_GLsizei_GLenum_GLvoid_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLuint_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLuint_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLuint_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLsizei: {
            PACKED_void_GLenum_GLuint_GLsizei *unpacked = (PACKED_void_GLenum_GLuint_GLsizei *)packed;
            ARGS_void_GLenum_GLuint_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLsizei: {
            PACKED_void_GLsizei *unpacked = (PACKED_void_GLsizei *)packed;
            ARGS_void_GLsizei args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLsizei_GLvoid: {
            PACKED_void_GLsizei_GLvoid *unpacked = (PACKED_void_GLsizei_GLvoid *)packed;
            ARGS_void_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLsizei_GLsizei_GLboolean: {
            PACKED_void_GLsizei_GLsizei_GLboolean *unpacked = (PACKED_void_GLsizei_GLsizei_GLboolean *)packed;
            ARGS_void_GLsizei_GLsizei_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLint_GLboolean___GENPT___GLint: {
            PACKED_void_GLint_GLboolean___GENPT___GLint *unpacked = (PACKED_void_GLint_GLboolean___GENPT___GLint *)packed;
            ARGS_void_GLint_GLboolean___GENPT___GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLint: {
            PACKED_void_GLenum_GLint_GLint_GLint_GLint *unpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLint_GLint: {
            PACKED_void_GLint_GLint *unpacked = (PACKED_void_GLint_GLint *)packed;
            ARGS_void_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLfloat: {
            PACKED_void_GLenum_GLuint_GLfloat *unpacked = (PACKED_void_GLenum_GLuint_GLfloat *)packed;
            ARGS_void_GLenum_GLuint_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLsizei_GLenum_GLfloat: {
            PACKED_void_GLsizei_GLenum_GLfloat *unpacked = (PACKED_void_GLsizei_GLenum_GLfloat *)packed;
            ARGS_void_GLsizei_GLenum_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLsizei_GLenum_GLfixed: {
            PACKED_void_GLsizei_GLenum_GLfixed *unpacked = (PACKED_void_GLsizei_GLenum_GLfixed *)packed;
            ARGS_void_GLsizei_GLenum_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_sync_GLenum_GLbitfield: {
            PACKED_sync_GLenum_GLbitfield *unpacked = (PACKED_sync_GLenum_GLbitfield *)packed;
            ARGS_sync_GLenum_GLbitfield args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_Int32_GLuint: {
            PACKED_Int32_GLuint *unpacked = (PACKED_Int32_GLuint *)packed;
            ARGS_Int32_GLuint args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLenum_GLintptr_GLsizeiptr: {
            PACKED_void_GLenum_GLintptr_GLsizeiptr *unpacked = (PACKED_void_GLenum_GLintptr_GLsizeiptr *)packed;
            ARGS_void_GLenum_GLintptr_GLsizeiptr args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLintptr_GLsizeiptr: {
            PACKED_void_GLuint_GLintptr_GLsizeiptr *unpacked = (PACKED_void_GLuint_GLintptr_GLsizeiptr *)packed;
            ARGS_void_GLuint_GLintptr_GLsizeiptr args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLvoid___GENPT___GLint: {
            PACKED_void_GLenum_GLint_GLvoid___GENPT___GLint *unpacked = (PACKED_void_GLenum_GLint_GLvoid___GENPT___GLint *)packed;
            ARGS_void_GLenum_GLint_GLvoid___GENPT___GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLsizei_GLfloat: {
            PACKED_void_GLsizei_GLfloat *unpacked = (PACKED_void_GLsizei_GLfloat *)packed;
            ARGS_void_GLsizei_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLenum: {
            PACKED_void_GLuint_GLsizei_GLenum *unpacked = (PACKED_void_GLuint_GLsizei_GLenum *)packed;
            ARGS_void_GLuint_GLsizei_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLuint: {
            PACKED_void_GLenum_GLenum_GLenum_GLuint *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLuint *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLuint_GLint: {
            PACKED_void_GLenum_GLenum_GLuint_GLint *unpacked = (PACKED_void_GLenum_GLenum_GLuint_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLuint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLuint_GLint: {
            PACKED_void_GLenum_GLenum_GLenum_GLuint_GLint *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLuint_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLuint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLuint_GLint_GLint: {
            PACKED_void_GLenum_GLenum_GLenum_GLuint_GLint_GLint *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLuint_GLint_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLuint_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLuint_GLint_GLenum: {
            PACKED_void_GLenum_GLenum_GLuint_GLint_GLenum *unpacked = (PACKED_void_GLenum_GLenum_GLuint_GLint_GLenum *)packed;
            ARGS_void_GLenum_GLenum_GLuint_GLint_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLuint_GLint_GLint: {
            PACKED_void_GLenum_GLenum_GLuint_GLint_GLint *unpacked = (PACKED_void_GLenum_GLenum_GLuint_GLint_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLuint_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble: {
            PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed: {
            PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed *unpacked = (PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed *)packed;
            ARGS_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_UInt32_GLsizei: {
            PACKED_UInt32_GLsizei *unpacked = (PACKED_UInt32_GLsizei *)packed;
            ARGS_UInt32_GLsizei args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_UInt32_GLuint: {
            PACKED_UInt32_GLuint *unpacked = (PACKED_UInt32_GLuint *)packed;
            ARGS_UInt32_GLuint args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_List_GLsizei: {
            PACKED_List_GLsizei *unpacked = (PACKED_List_GLsizei *)packed;
            ARGS_List_GLsizei args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_Path_GLsizei: {
            PACKED_Path_GLsizei *unpacked = (PACKED_Path_GLsizei *)packed;
            ARGS_Path_GLsizei args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_UInt32_GLenum_GLenum_GLenum_GLuint: {
            PACKED_UInt32_GLenum_GLenum_GLenum_GLuint *unpacked = (PACKED_UInt32_GLenum_GLenum_GLenum_GLuint *)packed;
            ARGS_UInt32_GLenum_GLenum_GLenum_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLenum_GLint: {
            PACKED_void_GLuint_GLuint_GLenum_GLint *unpacked = (PACKED_void_GLuint_GLuint_GLenum_GLint *)packed;
            ARGS_void_GLuint_GLuint_GLenum_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLsizei_GLsizei_GLint_GLenum_GLchar: {
            PACKED_void_GLuint_GLuint_GLsizei_GLsizei_GLint_GLenum_GLchar *unpacked = (PACKED_void_GLuint_GLuint_GLsizei_GLsizei_GLint_GLenum_GLchar *)packed;
            ARGS_void_GLuint_GLuint_GLsizei_GLsizei_GLint_GLenum_GLchar args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLhandleARB_GLuint_GLsizei_GLsizei_GLint_GLenum_GLcharARB: {
            PACKED_void_GLhandleARB_GLuint_GLsizei_GLsizei_GLint_GLenum_GLcharARB *unpacked = (PACKED_void_GLhandleARB_GLuint_GLsizei_GLsizei_GLint_GLenum_GLcharARB *)packed;
            ARGS_void_GLhandleARB_GLuint_GLsizei_GLsizei_GLint_GLenum_GLcharARB args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLuint_GLsizei_GLsizei_GLchar: {
            PACKED_void_GLuint_GLenum_GLuint_GLsizei_GLsizei_GLchar *unpacked = (PACKED_void_GLuint_GLenum_GLuint_GLsizei_GLsizei_GLchar *)packed;
            ARGS_void_GLuint_GLenum_GLuint_GLsizei_GLsizei_GLchar args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLuint_GLenum_GLint: {
            PACKED_void_GLuint_GLenum_GLuint_GLenum_GLint *unpacked = (PACKED_void_GLuint_GLenum_GLuint_GLenum_GLint *)packed;
            ARGS_void_GLuint_GLenum_GLuint_GLenum_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLsizei_GLsizei_GLchar: {
            PACKED_void_GLuint_GLuint_GLsizei_GLsizei_GLchar *unpacked = (PACKED_void_GLuint_GLuint_GLsizei_GLsizei_GLchar *)packed;
            ARGS_void_GLuint_GLuint_GLsizei_GLsizei_GLchar args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLuint_GLenum_GLint: {
            PACKED_void_GLuint_GLsizei_GLuint_GLenum_GLint *unpacked = (PACKED_void_GLuint_GLsizei_GLuint_GLenum_GLint *)packed;
            ARGS_void_GLuint_GLsizei_GLuint_GLenum_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLsizei_GLsizei_GLsizei_GLenum_GLchar: {
            PACKED_void_GLuint_GLuint_GLsizei_GLsizei_GLsizei_GLenum_GLchar *unpacked = (PACKED_void_GLuint_GLuint_GLsizei_GLsizei_GLsizei_GLenum_GLchar *)packed;
            ARGS_void_GLuint_GLuint_GLsizei_GLsizei_GLsizei_GLenum_GLchar args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLhandleARB_GLsizei_GLsizei_GLhandleARB: {
            PACKED_void_GLhandleARB_GLsizei_GLsizei_GLhandleARB *unpacked = (PACKED_void_GLhandleARB_GLsizei_GLsizei_GLhandleARB *)packed;
            ARGS_void_GLhandleARB_GLsizei_GLsizei_GLhandleARB args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLsizei_GLuint: {
            PACKED_void_GLuint_GLsizei_GLsizei_GLuint *unpacked = (PACKED_void_GLuint_GLsizei_GLsizei_GLuint *)packed;
            ARGS_void_GLuint_GLsizei_GLsizei_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_Int32_GLuint_GLchar: {
            PACKED_Int32_GLuint_GLchar *unpacked = (PACKED_Int32_GLuint_GLchar *)packed;
            ARGS_Int32_GLuint_GLchar args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_Int32_GLhandleARB_GLcharARB: {
            PACKED_Int32_GLhandleARB_GLcharARB *unpacked = (PACKED_Int32_GLhandleARB_GLcharARB *)packed;
            ARGS_Int32_GLhandleARB_GLcharARB args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLboolean: {
            PACKED_void_GLenum_GLuint_GLboolean *unpacked = (PACKED_void_GLenum_GLuint_GLboolean *)packed;
            ARGS_void_GLenum_GLuint_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLboolean: {
            PACKED_void_GLenum_GLboolean *unpacked = (PACKED_void_GLenum_GLboolean *)packed;
            ARGS_void_GLenum_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint64: {
            PACKED_void_GLenum_GLenum_GLint64 *unpacked = (PACKED_void_GLenum_GLenum_GLint64 *)packed;
            ARGS_void_GLenum_GLenum_GLint64 args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLuint64EXT: {
            PACKED_void_GLenum_GLenum_GLuint64EXT *unpacked = (PACKED_void_GLenum_GLenum_GLuint64EXT *)packed;
            ARGS_void_GLenum_GLenum_GLuint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLenum_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLvoid: {
            PACKED_void_GLenum_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLenum_GLfloat: {
            PACKED_void_GLenum_GLenum_GLenum_GLenum_GLfloat *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLenum_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLenum_GLint: {
            PACKED_void_GLenum_GLenum_GLenum_GLenum_GLint *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLenum_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLfloat: {
            PACKED_void_GLenum_GLenum_GLenum_GLfloat *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLint: {
            PACKED_void_GLenum_GLenum_GLenum_GLint *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLvoid: {
            PACKED_void_GLenum_GLenum_GLint_GLvoid *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLvoid *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLvoid: {
            PACKED_void_GLenum_GLint_GLvoid *unpacked = (PACKED_void_GLenum_GLint_GLvoid *)packed;
            ARGS_void_GLenum_GLint_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint_GLvoid: {
            PACKED_void_GLuint_GLenum_GLint_GLvoid *unpacked = (PACKED_void_GLuint_GLenum_GLint_GLvoid *)packed;
            ARGS_void_GLuint_GLenum_GLint_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_UInt32_GLuint_GLsizei_GLenum_GLenum_GLuint_GLenum_GLsizei_GLchar: {
            PACKED_UInt32_GLuint_GLsizei_GLenum_GLenum_GLuint_GLenum_GLsizei_GLchar *unpacked = (PACKED_UInt32_GLuint_GLsizei_GLenum_GLenum_GLuint_GLenum_GLsizei_GLchar *)packed;
            ARGS_UInt32_GLuint_GLsizei_GLenum_GLenum_GLuint_GLenum_GLsizei_GLchar args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_UInt32_GLuint_GLsizei_GLenum_GLuint_GLuint_GLsizei_GLchar: {
            PACKED_UInt32_GLuint_GLsizei_GLenum_GLuint_GLuint_GLsizei_GLchar *unpacked = (PACKED_UInt32_GLuint_GLsizei_GLenum_GLuint_GLuint_GLsizei_GLchar *)packed;
            ARGS_UInt32_GLuint_GLsizei_GLenum_GLuint_GLuint_GLsizei_GLchar args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLdouble: {
            PACKED_void_GLenum_GLuint_GLdouble *unpacked = (PACKED_void_GLenum_GLuint_GLdouble *)packed;
            ARGS_void_GLenum_GLuint_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_ErrorCode: {
            PACKED_ErrorCode *unpacked = (PACKED_ErrorCode *)packed;
            ARGS_ErrorCode args = unpacked->args;
            unpacked->func();
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint: {
            PACKED_void_GLuint_GLenum_GLint *unpacked = (PACKED_void_GLuint_GLenum_GLint *)packed;
            ARGS_void_GLuint_GLenum_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_GLenum: {
            PACKED_GLenum *unpacked = (PACKED_GLenum *)packed;
            ARGS_GLenum args = unpacked->args;
            unpacked->func();
            break;
        }
        case FORMAT_void_GLenum_GLboolean_GLenum_GLenum_GLvoid: {
            PACKED_void_GLenum_GLboolean_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLboolean_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLboolean_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_UInt64_GLuint_GLint_GLboolean_GLint_GLenum: {
            PACKED_UInt64_GLuint_GLint_GLboolean_GLint_GLenum *unpacked = (PACKED_UInt64_GLuint_GLint_GLboolean_GLint_GLenum *)packed;
            ARGS_UInt64_GLuint_GLint_GLboolean_GLint_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLhandleARB_GLsizei_GLsizei_GLcharARB: {
            PACKED_void_GLhandleARB_GLsizei_GLsizei_GLcharARB *unpacked = (PACKED_void_GLhandleARB_GLsizei_GLsizei_GLcharARB *)packed;
            ARGS_void_GLhandleARB_GLsizei_GLsizei_GLcharARB args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_Int32: {
            PACKED_Int32 *unpacked = (PACKED_Int32 *)packed;
            ARGS_Int32 args = unpacked->args;
            unpacked->func();
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLint64: {
            PACKED_void_GLenum_GLuint_GLint64 *unpacked = (PACKED_void_GLenum_GLuint_GLint64 *)packed;
            ARGS_void_GLenum_GLuint_GLint64 args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLint64: {
            PACKED_void_GLenum_GLint64 *unpacked = (PACKED_void_GLenum_GLint64 *)packed;
            ARGS_void_GLenum_GLint64 args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLint: {
            PACKED_void_GLenum_GLuint_GLint *unpacked = (PACKED_void_GLenum_GLuint_GLint *)packed;
            ARGS_void_GLenum_GLuint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLuint64EXT: {
            PACKED_void_GLenum_GLuint_GLuint64EXT *unpacked = (PACKED_void_GLenum_GLuint_GLuint64EXT *)packed;
            ARGS_void_GLenum_GLuint_GLuint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLuint64EXT: {
            PACKED_void_GLenum_GLuint64EXT *unpacked = (PACKED_void_GLenum_GLuint64EXT *)packed;
            ARGS_void_GLenum_GLuint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLsizei_GLint64: {
            PACKED_void_GLenum_GLenum_GLenum_GLsizei_GLint64 *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLsizei_GLint64 *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLsizei_GLint64 args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLsizei_GLint: {
            PACKED_void_GLenum_GLenum_GLenum_GLsizei_GLint *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLsizei_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLsizei_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLboolean: {
            PACKED_void_GLuint_GLenum_GLboolean *unpacked = (PACKED_void_GLuint_GLenum_GLboolean *)packed;
            ARGS_void_GLuint_GLenum_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLfloat: {
            PACKED_void_GLuint_GLenum_GLfloat *unpacked = (PACKED_void_GLuint_GLenum_GLfloat *)packed;
            ARGS_void_GLuint_GLenum_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLenum_GLfloat: {
            PACKED_void_GLenum_GLuint_GLenum_GLfloat *unpacked = (PACKED_void_GLenum_GLuint_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLuint_GLenum_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLenum_GLint: {
            PACKED_void_GLenum_GLuint_GLenum_GLint *unpacked = (PACKED_void_GLenum_GLuint_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLuint_GLenum_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLenum_GLsizei_GLsizei_GLboolean_GLvoid: {
            PACKED_void_GLenum_GLuint_GLenum_GLsizei_GLsizei_GLboolean_GLvoid *unpacked = (PACKED_void_GLenum_GLuint_GLenum_GLsizei_GLsizei_GLboolean_GLvoid *)packed;
            ARGS_void_GLenum_GLuint_GLenum_GLsizei_GLsizei_GLboolean_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLdouble: {
            PACKED_void_GLenum_GLenum_GLdouble *unpacked = (PACKED_void_GLenum_GLenum_GLdouble *)packed;
            ARGS_void_GLenum_GLenum_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLdouble: {
            PACKED_void_GLenum_GLenum_GLenum_GLdouble *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLdouble *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLenum_GLenum_GLvoid: {
            PACKED_void_GLenum_GLenum_GLint_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLenum_GLfloat: {
            PACKED_void_GLenum_GLenum_GLint_GLenum_GLfloat *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLenum_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLenum_GLint: {
            PACKED_void_GLenum_GLenum_GLint_GLenum_GLint *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLenum_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLuint64EXT: {
            PACKED_void_GLuint_GLenum_GLuint64EXT *unpacked = (PACKED_void_GLuint_GLenum_GLuint64EXT *)packed;
            ARGS_void_GLuint_GLenum_GLuint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLvoid___GENPT__: {
            PACKED_void_GLuint_GLenum_GLvoid___GENPT__ *unpacked = (PACKED_void_GLuint_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLuint_GLenum_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLintptr_GLsizeiptr_GLvoid: {
            PACKED_void_GLuint_GLintptr_GLsizeiptr_GLvoid *unpacked = (PACKED_void_GLuint_GLintptr_GLsizeiptr_GLvoid *)packed;
            ARGS_void_GLuint_GLintptr_GLsizeiptr_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLenum_GLint: {
            PACKED_void_GLuint_GLenum_GLenum_GLint *unpacked = (PACKED_void_GLuint_GLenum_GLenum_GLint *)packed;
            ARGS_void_GLuint_GLenum_GLenum_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLuint_GLint: {
            PACKED_void_GLuint_GLenum_GLuint_GLint *unpacked = (PACKED_void_GLuint_GLenum_GLuint_GLint *)packed;
            ARGS_void_GLuint_GLenum_GLuint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLuint_GLuint: {
            PACKED_void_GLuint_GLenum_GLuint_GLuint *unpacked = (PACKED_void_GLuint_GLenum_GLuint_GLuint *)packed;
            ARGS_void_GLuint_GLenum_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLuint_GLdouble: {
            PACKED_void_GLuint_GLenum_GLuint_GLdouble *unpacked = (PACKED_void_GLuint_GLenum_GLuint_GLdouble *)packed;
            ARGS_void_GLuint_GLenum_GLuint_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLuint_GLfloat: {
            PACKED_void_GLuint_GLenum_GLuint_GLfloat *unpacked = (PACKED_void_GLuint_GLenum_GLuint_GLfloat *)packed;
            ARGS_void_GLuint_GLenum_GLuint_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLenum_GLvoid: {
            PACKED_void_GLuint_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLuint_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLuint_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLint_GLchar_GLsizei_GLint_GLchar: {
            PACKED_void_GLint_GLchar_GLsizei_GLint_GLchar *unpacked = (PACKED_void_GLint_GLchar_GLsizei_GLint_GLchar *)packed;
            ARGS_void_GLint_GLchar_GLsizei_GLint_GLchar args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLint_GLchar_GLenum_GLint: {
            PACKED_void_GLint_GLchar_GLenum_GLint *unpacked = (PACKED_void_GLint_GLchar_GLenum_GLint *)packed;
            ARGS_void_GLint_GLchar_GLenum_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLsizei_GLsizei_GLchar: {
            PACKED_void_GLenum_GLuint_GLsizei_GLsizei_GLchar *unpacked = (PACKED_void_GLenum_GLuint_GLsizei_GLsizei_GLchar *)packed;
            ARGS_void_GLenum_GLuint_GLsizei_GLsizei_GLchar args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLhandleARB_GLenum_GLfloat: {
            PACKED_void_GLhandleARB_GLenum_GLfloat *unpacked = (PACKED_void_GLhandleARB_GLenum_GLfloat *)packed;
            ARGS_void_GLhandleARB_GLenum_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLhandleARB_GLenum_GLint: {
            PACKED_void_GLhandleARB_GLenum_GLint *unpacked = (PACKED_void_GLhandleARB_GLenum_GLint *)packed;
            ARGS_void_GLhandleARB_GLenum_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_void___GENPT___GLsizei_GLsizei_GLchar: {
            PACKED_void_void___GENPT___GLsizei_GLsizei_GLchar *unpacked = (PACKED_void_void___GENPT___GLsizei_GLsizei_GLchar *)packed;
            ARGS_void_void___GENPT___GLsizei_GLsizei_GLchar args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLuint: {
            PACKED_void_GLuint_GLenum_GLuint *unpacked = (PACKED_void_GLuint_GLenum_GLuint *)packed;
            ARGS_void_GLuint_GLenum_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLubyte: {
            PACKED_void_GLuint_GLubyte *unpacked = (PACKED_void_GLuint_GLubyte *)packed;
            ARGS_void_GLuint_GLubyte args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLfloat: {
            PACKED_void_GLuint_GLfloat *unpacked = (PACKED_void_GLuint_GLfloat *)packed;
            ARGS_void_GLuint_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_Float32_GLuint_GLsizei_GLsizei: {
            PACKED_Float32_GLuint_GLsizei_GLsizei *unpacked = (PACKED_Float32_GLuint_GLsizei_GLsizei *)packed;
            ARGS_Float32_GLuint_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLbitfield_GLuint_GLsizei_GLsizei_GLfloat: {
            PACKED_void_GLbitfield_GLuint_GLsizei_GLsizei_GLfloat *unpacked = (PACKED_void_GLbitfield_GLuint_GLsizei_GLsizei_GLfloat *)packed;
            ARGS_void_GLbitfield_GLuint_GLsizei_GLsizei_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLbitfield_GLsizei_GLenum_GLvoid_GLuint_GLsizei_GLfloat: {
            PACKED_void_GLbitfield_GLsizei_GLenum_GLvoid_GLuint_GLsizei_GLfloat *unpacked = (PACKED_void_GLbitfield_GLsizei_GLenum_GLvoid_GLuint_GLsizei_GLfloat *)packed;
            ARGS_void_GLbitfield_GLsizei_GLenum_GLvoid_GLuint_GLsizei_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLenum_GLvoid_GLuint_GLfloat_GLfloat_GLenum_GLfloat: {
            PACKED_void_GLenum_GLsizei_GLenum_GLvoid_GLuint_GLfloat_GLfloat_GLenum_GLfloat *unpacked = (PACKED_void_GLenum_GLsizei_GLenum_GLvoid_GLuint_GLfloat_GLfloat_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLsizei_GLenum_GLvoid_GLuint_GLfloat_GLfloat_GLenum_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLsizei_GLuint_GLint: {
            PACKED_void_GLuint_GLenum_GLsizei_GLuint_GLint *unpacked = (PACKED_void_GLuint_GLenum_GLsizei_GLuint_GLint *)packed;
            ARGS_void_GLuint_GLenum_GLsizei_GLuint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLenum_GLvoid: {
            PACKED_void_GLuint_GLuint_GLenum_GLvoid *unpacked = (PACKED_void_GLuint_GLuint_GLenum_GLvoid *)packed;
            ARGS_void_GLuint_GLuint_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLint_GLsizei_GLuint: {
            PACKED_void_GLuint_GLint_GLint_GLsizei_GLuint *unpacked = (PACKED_void_GLuint_GLint_GLint_GLsizei_GLuint *)packed;
            ARGS_void_GLuint_GLint_GLint_GLsizei_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLsizei_GLchar: {
            PACKED_void_GLuint_GLsizei_GLsizei_GLchar *unpacked = (PACKED_void_GLuint_GLsizei_GLsizei_GLchar *)packed;
            ARGS_void_GLuint_GLsizei_GLsizei_GLchar args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLint_GLsizei_GLuint: {
            PACKED_void_GLint_GLsizei_GLuint *unpacked = (PACKED_void_GLint_GLsizei_GLuint *)packed;
            ARGS_void_GLint_GLsizei_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLushort: {
            PACKED_void_GLenum_GLushort *unpacked = (PACKED_void_GLenum_GLushort *)packed;
            ARGS_void_GLenum_GLushort args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLfixed: {
            PACKED_void_GLenum_GLint_GLfixed *unpacked = (PACKED_void_GLenum_GLint_GLfixed *)packed;
            ARGS_void_GLenum_GLint_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLuint_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLuint_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLuint_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLsizei_GLenum_GLvoid: {
            PACKED_void_GLuint_GLsizei_GLsizei_GLenum_GLvoid *unpacked = (PACKED_void_GLuint_GLsizei_GLsizei_GLenum_GLvoid *)packed;
            ARGS_void_GLuint_GLsizei_GLsizei_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLubyte_GLdouble: {
            PACKED_void_GLuint_GLsizei_GLubyte_GLdouble *unpacked = (PACKED_void_GLuint_GLsizei_GLubyte_GLdouble *)packed;
            ARGS_void_GLuint_GLsizei_GLubyte_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLubyte_GLfloat: {
            PACKED_void_GLuint_GLsizei_GLubyte_GLfloat *unpacked = (PACKED_void_GLuint_GLsizei_GLubyte_GLfloat *)packed;
            ARGS_void_GLuint_GLsizei_GLubyte_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLenum_GLdouble: {
            PACKED_void_GLenum_GLuint_GLenum_GLdouble *unpacked = (PACKED_void_GLenum_GLuint_GLenum_GLdouble *)packed;
            ARGS_void_GLenum_GLuint_GLenum_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_UInt32_GLuint_GLenum_GLchar: {
            PACKED_UInt32_GLuint_GLenum_GLchar *unpacked = (PACKED_UInt32_GLuint_GLenum_GLchar *)packed;
            ARGS_UInt32_GLuint_GLenum_GLchar args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_Int32_GLuint_GLenum_GLchar: {
            PACKED_Int32_GLuint_GLenum_GLchar *unpacked = (PACKED_Int32_GLuint_GLenum_GLchar *)packed;
            ARGS_Int32_GLuint_GLenum_GLchar args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLuint_GLsizei_GLenum_GLsizei_GLsizei_GLint: {
            PACKED_void_GLuint_GLenum_GLuint_GLsizei_GLenum_GLsizei_GLsizei_GLint *unpacked = (PACKED_void_GLuint_GLenum_GLuint_GLsizei_GLenum_GLsizei_GLsizei_GLint *)packed;
            ARGS_void_GLuint_GLenum_GLuint_GLsizei_GLenum_GLsizei_GLsizei_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLubyte: {
            PACKED_void_GLuint_GLenum_GLubyte *unpacked = (PACKED_void_GLuint_GLenum_GLubyte *)packed;
            ARGS_void_GLuint_GLenum_GLubyte args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint64: {
            PACKED_void_GLuint_GLenum_GLint64 *unpacked = (PACKED_void_GLuint_GLenum_GLint64 *)packed;
            ARGS_void_GLuint_GLenum_GLint64 args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint64EXT: {
            PACKED_void_GLuint_GLenum_GLint64EXT *unpacked = (PACKED_void_GLuint_GLenum_GLint64EXT *)packed;
            ARGS_void_GLuint_GLenum_GLint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLuint64: {
            PACKED_void_GLuint_GLenum_GLuint64 *unpacked = (PACKED_void_GLuint_GLenum_GLuint64 *)packed;
            ARGS_void_GLuint_GLenum_GLuint64 args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLvoid_GLvoid_GLvoid: {
            PACKED_void_GLenum_GLenum_GLenum_GLvoid_GLvoid_GLvoid *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLvoid_GLvoid_GLvoid *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLvoid_GLvoid_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLint: {
            PACKED_void_GLenum_GLenum_GLint_GLint *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_String_GLenum: {
            PACKED_String_GLenum *unpacked = (PACKED_String_GLenum *)packed;
            ARGS_String_GLenum args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_String_GLenum_GLuint: {
            PACKED_String_GLenum_GLuint *unpacked = (PACKED_String_GLenum_GLuint *)packed;
            ARGS_String_GLenum_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLsync_GLenum_GLsizei_GLsizei_GLint: {
            PACKED_void_GLsync_GLenum_GLsizei_GLsizei_GLint *unpacked = (PACKED_void_GLsync_GLenum_GLsizei_GLsizei_GLint *)packed;
            ARGS_void_GLsync_GLenum_GLsizei_GLsizei_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLenum_GLvoid: {
            PACKED_void_GLenum_GLint_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLfloat: {
            PACKED_void_GLenum_GLint_GLenum_GLfloat *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLint: {
            PACKED_void_GLenum_GLint_GLenum_GLint *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLfixed: {
            PACKED_void_GLenum_GLint_GLenum_GLfixed *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLfixed *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_UInt64_GLuint: {
            PACKED_UInt64_GLuint *unpacked = (PACKED_UInt64_GLuint *)packed;
            ARGS_UInt64_GLuint args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint_GLenum_GLenum_GLvoid: {
            PACKED_void_GLuint_GLenum_GLint_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLuint_GLenum_GLint_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLuint_GLenum_GLint_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint_GLenum_GLfloat: {
            PACKED_void_GLuint_GLenum_GLint_GLenum_GLfloat *unpacked = (PACKED_void_GLuint_GLenum_GLint_GLenum_GLfloat *)packed;
            ARGS_void_GLuint_GLenum_GLint_GLenum_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint_GLenum_GLint: {
            PACKED_void_GLuint_GLenum_GLint_GLenum_GLint *unpacked = (PACKED_void_GLuint_GLenum_GLint_GLenum_GLint *)packed;
            ARGS_void_GLuint_GLenum_GLint_GLenum_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLenum_GLuint: {
            PACKED_void_GLuint_GLenum_GLenum_GLuint *unpacked = (PACKED_void_GLuint_GLenum_GLenum_GLuint *)packed;
            ARGS_void_GLuint_GLenum_GLenum_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLenum_GLfloat: {
            PACKED_void_GLuint_GLenum_GLenum_GLfloat *unpacked = (PACKED_void_GLuint_GLenum_GLenum_GLfloat *)packed;
            ARGS_void_GLuint_GLenum_GLenum_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_UInt64_GLuint_GLuint: {
            PACKED_UInt64_GLuint_GLuint *unpacked = (PACKED_UInt64_GLuint_GLuint *)packed;
            ARGS_UInt64_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLint: {
            PACKED_void_GLuint_GLuint_GLint *unpacked = (PACKED_void_GLuint_GLuint_GLint *)packed;
            ARGS_void_GLuint_GLuint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_UInt32_GLuint_GLchar: {
            PACKED_UInt32_GLuint_GLchar *unpacked = (PACKED_UInt32_GLuint_GLchar *)packed;
            ARGS_UInt32_GLuint_GLchar args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_Int32_GLuint_GLint: {
            PACKED_Int32_GLuint_GLint *unpacked = (PACKED_Int32_GLuint_GLint *)packed;
            ARGS_Int32_GLuint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLchar__GENPT__const_GLuint: {
            PACKED_void_GLuint_GLsizei_GLchar__GENPT__const_GLuint *unpacked = (PACKED_void_GLuint_GLsizei_GLchar__GENPT__const_GLuint *)packed;
            ARGS_void_GLuint_GLsizei_GLchar__GENPT__const_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_BufferOffset_GLuint_GLint: {
            PACKED_BufferOffset_GLuint_GLint *unpacked = (PACKED_BufferOffset_GLuint_GLint *)packed;
            ARGS_BufferOffset_GLuint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLdouble: {
            PACKED_void_GLuint_GLint_GLdouble *unpacked = (PACKED_void_GLuint_GLint_GLdouble *)packed;
            ARGS_void_GLuint_GLint_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLfloat: {
            PACKED_void_GLuint_GLint_GLfloat *unpacked = (PACKED_void_GLuint_GLint_GLfloat *)packed;
            ARGS_void_GLuint_GLint_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLhandleARB_GLint_GLfloat: {
            PACKED_void_GLhandleARB_GLint_GLfloat *unpacked = (PACKED_void_GLhandleARB_GLint_GLfloat *)packed;
            ARGS_void_GLhandleARB_GLint_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLint64EXT: {
            PACKED_void_GLuint_GLint_GLint64EXT *unpacked = (PACKED_void_GLuint_GLint_GLint64EXT *)packed;
            ARGS_void_GLuint_GLint_GLint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLint: {
            PACKED_void_GLuint_GLint_GLint *unpacked = (PACKED_void_GLuint_GLint_GLint *)packed;
            ARGS_void_GLuint_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLhandleARB_GLint_GLint: {
            PACKED_void_GLhandleARB_GLint_GLint *unpacked = (PACKED_void_GLhandleARB_GLint_GLint *)packed;
            ARGS_void_GLhandleARB_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLuint64EXT: {
            PACKED_void_GLuint_GLint_GLuint64EXT *unpacked = (PACKED_void_GLuint_GLint_GLuint64EXT *)packed;
            ARGS_void_GLuint_GLint_GLuint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLuint: {
            PACKED_void_GLuint_GLint_GLuint *unpacked = (PACKED_void_GLuint_GLint_GLuint *)packed;
            ARGS_void_GLuint_GLint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLenum_GLvoid___GENPT__: {
            PACKED_void_GLuint_GLuint_GLenum_GLvoid___GENPT__ *unpacked = (PACKED_void_GLuint_GLuint_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLuint_GLuint_GLenum_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLdouble: {
            PACKED_void_GLuint_GLenum_GLdouble *unpacked = (PACKED_void_GLuint_GLenum_GLdouble *)packed;
            ARGS_void_GLuint_GLenum_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLenum_GLdouble: {
            PACKED_void_GLuint_GLuint_GLenum_GLdouble *unpacked = (PACKED_void_GLuint_GLuint_GLenum_GLdouble *)packed;
            ARGS_void_GLuint_GLuint_GLenum_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLenum_GLfloat: {
            PACKED_void_GLuint_GLuint_GLenum_GLfloat *unpacked = (PACKED_void_GLuint_GLuint_GLenum_GLfloat *)packed;
            ARGS_void_GLuint_GLuint_GLenum_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLsizei_GLvoid: {
            PACKED_void_GLenum_GLenum_GLenum_GLsizei_GLvoid *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLsizei_GLvoid *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLsizei_GLvoid: {
            PACKED_void_GLenum_GLint_GLsizei_GLvoid *unpacked = (PACKED_void_GLenum_GLint_GLsizei_GLvoid *)packed;
            ARGS_void_GLenum_GLint_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLboolean_GLenum_GLenum_GLsizei_GLvoid: {
            PACKED_void_GLenum_GLboolean_GLenum_GLenum_GLsizei_GLvoid *unpacked = (PACKED_void_GLenum_GLboolean_GLenum_GLenum_GLsizei_GLvoid *)packed;
            ARGS_void_GLenum_GLboolean_GLenum_GLenum_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLsizei_GLdouble: {
            PACKED_void_GLenum_GLenum_GLsizei_GLdouble *unpacked = (PACKED_void_GLenum_GLenum_GLsizei_GLdouble *)packed;
            ARGS_void_GLenum_GLenum_GLsizei_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLsizei_GLfloat: {
            PACKED_void_GLenum_GLenum_GLsizei_GLfloat *unpacked = (PACKED_void_GLenum_GLenum_GLsizei_GLfloat *)packed;
            ARGS_void_GLenum_GLenum_GLsizei_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLsizei_GLint: {
            PACKED_void_GLenum_GLenum_GLsizei_GLint *unpacked = (PACKED_void_GLenum_GLenum_GLsizei_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLsizei_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLuint: {
            PACKED_void_GLenum_GLsizei_GLuint *unpacked = (PACKED_void_GLenum_GLsizei_GLuint *)packed;
            ARGS_void_GLenum_GLsizei_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLushort: {
            PACKED_void_GLenum_GLsizei_GLushort *unpacked = (PACKED_void_GLenum_GLsizei_GLushort *)packed;
            ARGS_void_GLenum_GLsizei_GLushort args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLsizei_GLubyte: {
            PACKED_void_GLsizei_GLubyte *unpacked = (PACKED_void_GLsizei_GLubyte *)packed;
            ARGS_void_GLsizei_GLubyte args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLsizei_GLvoid_GLsizei_GLvoid_GLvoid: {
            PACKED_void_GLenum_GLenum_GLenum_GLsizei_GLvoid_GLsizei_GLvoid_GLvoid *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLsizei_GLvoid_GLsizei_GLvoid_GLvoid *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLsizei_GLvoid_GLsizei_GLvoid_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLenum_GLsizei_GLvoid: {
            PACKED_void_GLenum_GLint_GLenum_GLenum_GLsizei_GLvoid *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLenum_GLsizei_GLvoid *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLenum_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLsizei_GLdouble: {
            PACKED_void_GLuint_GLint_GLsizei_GLdouble *unpacked = (PACKED_void_GLuint_GLint_GLsizei_GLdouble *)packed;
            ARGS_void_GLuint_GLint_GLsizei_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLsizei_GLfloat: {
            PACKED_void_GLuint_GLint_GLsizei_GLfloat *unpacked = (PACKED_void_GLuint_GLint_GLsizei_GLfloat *)packed;
            ARGS_void_GLuint_GLint_GLsizei_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLsizei_GLint: {
            PACKED_void_GLuint_GLint_GLsizei_GLint *unpacked = (PACKED_void_GLuint_GLint_GLsizei_GLint *)packed;
            ARGS_void_GLuint_GLint_GLsizei_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLsizei_GLuint: {
            PACKED_void_GLuint_GLint_GLsizei_GLuint *unpacked = (PACKED_void_GLuint_GLint_GLsizei_GLuint *)packed;
            ARGS_void_GLuint_GLint_GLsizei_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLenum_GLboolean: {
            PACKED_void_GLenum_GLsizei_GLenum_GLboolean *unpacked = (PACKED_void_GLenum_GLsizei_GLenum_GLboolean *)packed;
            ARGS_void_GLenum_GLsizei_GLenum_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_sync_GLenum_GLintptr_GLbitfield: {
            PACKED_sync_GLenum_GLintptr_GLbitfield *unpacked = (PACKED_sync_GLenum_GLintptr_GLbitfield *)packed;
            ARGS_sync_GLenum_GLintptr_GLbitfield args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLclampf: {
            PACKED_void_GLenum_GLclampf *unpacked = (PACKED_void_GLenum_GLclampf *)packed;
            ARGS_void_GLenum_GLclampf args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLsizei_GLvoid: {
            PACKED_void_GLenum_GLsizei_GLsizei_GLvoid *unpacked = (PACKED_void_GLenum_GLsizei_GLsizei_GLvoid *)packed;
            ARGS_void_GLenum_GLsizei_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLsizei_GLint: {
            PACKED_void_GLsizei_GLint *unpacked = (PACKED_void_GLsizei_GLint *)packed;
            ARGS_void_GLsizei_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLuint_GLfloat: {
            PACKED_void_GLuint_GLuint_GLuint_GLfloat *unpacked = (PACKED_void_GLuint_GLuint_GLuint_GLfloat *)packed;
            ARGS_void_GLuint_GLuint_GLuint_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLenum: {
            PACKED_void_GLenum_GLsizei_GLenum *unpacked = (PACKED_void_GLenum_GLsizei_GLenum *)packed;
            ARGS_void_GLenum_GLsizei_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLenum_GLint_GLint_GLsizei_GLsizei: {
            PACKED_void_GLenum_GLsizei_GLenum_GLint_GLint_GLsizei_GLsizei *unpacked = (PACKED_void_GLenum_GLsizei_GLenum_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_GLsizei_GLenum_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLuint_GLint: {
            PACKED_void_GLuint_GLint *unpacked = (PACKED_void_GLuint_GLint *)packed;
            ARGS_void_GLuint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei: {
            PACKED_void_GLuint_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei *unpacked = (PACKED_void_GLuint_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei *)packed;
            ARGS_void_GLuint_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_Boolean_GLuint: {
            PACKED_Boolean_GLuint *unpacked = (PACKED_Boolean_GLuint *)packed;
            ARGS_Boolean_GLuint args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_Boolean_GLenum: {
            PACKED_Boolean_GLenum *unpacked = (PACKED_Boolean_GLenum *)packed;
            ARGS_Boolean_GLenum args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_Boolean_GLenum_GLuint: {
            PACKED_Boolean_GLenum_GLuint *unpacked = (PACKED_Boolean_GLenum_GLuint *)packed;
            ARGS_Boolean_GLenum_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_Boolean_GLuint64: {
            PACKED_Boolean_GLuint64 *unpacked = (PACKED_Boolean_GLuint64 *)packed;
            ARGS_Boolean_GLuint64 args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_Boolean_GLint_GLchar: {
            PACKED_Boolean_GLint_GLchar *unpacked = (PACKED_Boolean_GLint_GLchar *)packed;
            ARGS_Boolean_GLint_GLchar args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_Boolean_GLuint_GLuint_GLfloat_GLfloat: {
            PACKED_Boolean_GLuint_GLuint_GLfloat_GLfloat *unpacked = (PACKED_Boolean_GLuint_GLuint_GLfloat_GLfloat *)packed;
            ARGS_Boolean_GLuint_GLuint_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_Boolean_GLuint_GLfloat_GLfloat: {
            PACKED_Boolean_GLuint_GLfloat_GLfloat *unpacked = (PACKED_Boolean_GLuint_GLfloat_GLfloat *)packed;
            ARGS_Boolean_GLuint_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_Boolean_GLsync: {
            PACKED_Boolean_GLsync *unpacked = (PACKED_Boolean_GLsync *)packed;
            ARGS_Boolean_GLsync args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_Boolean_GLuint_GLenum: {
            PACKED_Boolean_GLuint_GLenum *unpacked = (PACKED_Boolean_GLuint_GLenum *)packed;
            ARGS_Boolean_GLuint_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLint_GLushort: {
            PACKED_void_GLint_GLushort *unpacked = (PACKED_void_GLint_GLushort *)packed;
            ARGS_void_GLint_GLushort args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLsizei_GLubyte: {
            PACKED_void_GLenum_GLuint_GLsizei_GLubyte *unpacked = (PACKED_void_GLenum_GLuint_GLsizei_GLubyte *)packed;
            ARGS_void_GLenum_GLuint_GLsizei_GLubyte args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLint_GLsizei: {
            PACKED_void_GLint_GLsizei *unpacked = (PACKED_void_GLint_GLsizei *)packed;
            ARGS_void_GLint_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint64: {
            PACKED_void_GLuint64 *unpacked = (PACKED_void_GLuint64 *)packed;
            ARGS_void_GLuint64 args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLuint64_GLenum: {
            PACKED_void_GLuint64_GLenum *unpacked = (PACKED_void_GLuint64_GLenum *)packed;
            ARGS_void_GLuint64_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble: {
            PACKED_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble *unpacked = (PACKED_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble *)packed;
            ARGS_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat: {
            PACKED_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat *unpacked = (PACKED_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLfixed_GLfixed_GLint_GLint_GLfixed: {
            PACKED_void_GLenum_GLfixed_GLfixed_GLint_GLint_GLfixed *unpacked = (PACKED_void_GLenum_GLfixed_GLfixed_GLint_GLint_GLfixed *)packed;
            ARGS_void_GLenum_GLfixed_GLfixed_GLint_GLint_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble: {
            PACKED_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble *unpacked = (PACKED_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble *)packed;
            ARGS_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        case FORMAT_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat: {
            PACKED_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat *unpacked = (PACKED_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        case FORMAT_void_GLenum_GLfixed_GLfixed_GLint_GLint_GLfixed_GLfixed_GLint_GLint_GLfixed: {
            PACKED_void_GLenum_GLfixed_GLfixed_GLint_GLint_GLfixed_GLfixed_GLint_GLint_GLfixed *unpacked = (PACKED_void_GLenum_GLfixed_GLfixed_GLint_GLint_GLfixed_GLfixed_GLint_GLint_GLfixed *)packed;
            ARGS_void_GLenum_GLfixed_GLfixed_GLint_GLint_GLfixed_GLfixed_GLint_GLint_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        case FORMAT_VoidPointer_GLenum_GLenum: {
            PACKED_VoidPointer_GLenum_GLenum *unpacked = (PACKED_VoidPointer_GLenum_GLenum *)packed;
            ARGS_VoidPointer_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_VoidPointer_GLenum_GLintptr_GLsizeiptr_GLbitfield: {
            PACKED_VoidPointer_GLenum_GLintptr_GLsizeiptr_GLbitfield *unpacked = (PACKED_VoidPointer_GLenum_GLintptr_GLsizeiptr_GLbitfield *)packed;
            ARGS_VoidPointer_GLenum_GLintptr_GLsizeiptr_GLbitfield args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLenum_GLsizei_GLsizei_GLint_GLint_GLboolean_GLvoid: {
            PACKED_void_GLenum_GLuint_GLenum_GLsizei_GLsizei_GLint_GLint_GLboolean_GLvoid *unpacked = (PACKED_void_GLenum_GLuint_GLenum_GLsizei_GLsizei_GLint_GLint_GLboolean_GLvoid *)packed;
            ARGS_void_GLenum_GLuint_GLenum_GLsizei_GLsizei_GLint_GLint_GLboolean_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLint_GLdouble_GLdouble: {
            PACKED_void_GLint_GLdouble_GLdouble *unpacked = (PACKED_void_GLint_GLdouble_GLdouble *)packed;
            ARGS_void_GLint_GLdouble_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLint_GLfloat_GLfloat: {
            PACKED_void_GLint_GLfloat_GLfloat *unpacked = (PACKED_void_GLint_GLfloat_GLfloat *)packed;
            ARGS_void_GLint_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLint_GLfixed_GLfixed: {
            PACKED_void_GLint_GLfixed_GLfixed *unpacked = (PACKED_void_GLint_GLfixed_GLfixed *)packed;
            ARGS_void_GLint_GLfixed_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble: {
            PACKED_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble *unpacked = (PACKED_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble *)packed;
            ARGS_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLint_GLfloat_GLfloat_GLint_GLfloat_GLfloat: {
            PACKED_void_GLint_GLfloat_GLfloat_GLint_GLfloat_GLfloat *unpacked = (PACKED_void_GLint_GLfloat_GLfloat_GLint_GLfloat_GLfloat *)packed;
            ARGS_void_GLint_GLfloat_GLfloat_GLint_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLint_GLfixed_GLfixed_GLfixed_GLfixed: {
            PACKED_void_GLint_GLfixed_GLfixed_GLfixed_GLfixed *unpacked = (PACKED_void_GLint_GLfixed_GLfixed_GLfixed_GLfixed *)packed;
            ARGS_void_GLint_GLfixed_GLfixed_GLfixed_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_VoidPointer_GLuint_GLenum: {
            PACKED_VoidPointer_GLuint_GLenum *unpacked = (PACKED_VoidPointer_GLuint_GLenum *)packed;
            ARGS_VoidPointer_GLuint_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_VoidPointer_GLuint_GLintptr_GLsizeiptr_GLbitfield: {
            PACKED_VoidPointer_GLuint_GLintptr_GLsizeiptr_GLbitfield *unpacked = (PACKED_VoidPointer_GLuint_GLintptr_GLsizeiptr_GLbitfield *)packed;
            ARGS_VoidPointer_GLuint_GLintptr_GLsizeiptr_GLbitfield args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_VoidPointer_GLuint: {
            PACKED_VoidPointer_GLuint *unpacked = (PACKED_VoidPointer_GLuint *)packed;
            ARGS_VoidPointer_GLuint args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_VoidPointer_GLuint_GLint_GLbitfield_GLint_GLenum: {
            PACKED_VoidPointer_GLuint_GLint_GLbitfield_GLint_GLenum *unpacked = (PACKED_VoidPointer_GLuint_GLint_GLbitfield_GLint_GLenum *)packed;
            ARGS_VoidPointer_GLuint_GLint_GLbitfield_GLint_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLdouble_GLdouble_GLint_GLint_GLdouble: {
            PACKED_void_GLuint_GLuint_GLdouble_GLdouble_GLint_GLint_GLdouble *unpacked = (PACKED_void_GLuint_GLuint_GLdouble_GLdouble_GLint_GLint_GLdouble *)packed;
            ARGS_void_GLuint_GLuint_GLdouble_GLdouble_GLint_GLint_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLfloat_GLfloat_GLint_GLint_GLfloat: {
            PACKED_void_GLuint_GLuint_GLfloat_GLfloat_GLint_GLint_GLfloat *unpacked = (PACKED_void_GLuint_GLuint_GLfloat_GLfloat_GLint_GLint_GLfloat *)packed;
            ARGS_void_GLuint_GLuint_GLfloat_GLfloat_GLint_GLint_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble: {
            PACKED_void_GLuint_GLuint_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble *unpacked = (PACKED_void_GLuint_GLuint_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble *)packed;
            ARGS_void_GLuint_GLuint_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat: {
            PACKED_void_GLuint_GLuint_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat *unpacked = (PACKED_void_GLuint_GLuint_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat *)packed;
            ARGS_void_GLuint_GLuint_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11);
            break;
        }
        case FORMAT_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble: {
            PACKED_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (PACKED_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLint_GLubyte: {
            PACKED_void_GLint_GLubyte *unpacked = (PACKED_void_GLint_GLubyte *)packed;
            ARGS_void_GLint_GLubyte args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLint_GLuint: {
            PACKED_void_GLint_GLuint *unpacked = (PACKED_void_GLint_GLuint *)packed;
            ARGS_void_GLint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble: {
            PACKED_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (PACKED_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLdouble_GLdouble_GLdouble: {
            PACKED_void_GLenum_GLdouble_GLdouble_GLdouble *unpacked = (PACKED_void_GLenum_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLenum_GLdouble_GLdouble_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLenum_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLenum_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLboolean: {
            PACKED_void_GLenum_GLenum_GLboolean *unpacked = (PACKED_void_GLenum_GLenum_GLboolean *)packed;
            ARGS_void_GLenum_GLenum_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_void___GENPT___GLsizei_GLsizei: {
            PACKED_void_GLenum_void___GENPT___GLsizei_GLsizei *unpacked = (PACKED_void_GLenum_void___GENPT___GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_void___GENPT___GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLvoid_GLsizei_GLsizei: {
            PACKED_void_GLenum_GLvoid_GLsizei_GLsizei *unpacked = (PACKED_void_GLenum_GLvoid_GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_GLvoid_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLenum_GLvoid__GENPT__const_GLsizei: {
            PACKED_void_GLenum_GLsizei_GLenum_GLvoid__GENPT__const_GLsizei *unpacked = (PACKED_void_GLenum_GLsizei_GLenum_GLvoid__GENPT__const_GLsizei *)packed;
            ARGS_void_GLenum_GLsizei_GLenum_GLvoid__GENPT__const_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLenum_GLvoid__GENPT__const_GLsizei_GLint: {
            PACKED_void_GLenum_GLsizei_GLenum_GLvoid__GENPT__const_GLsizei_GLint *unpacked = (PACKED_void_GLenum_GLsizei_GLenum_GLvoid__GENPT__const_GLsizei_GLint *)packed;
            ARGS_void_GLenum_GLsizei_GLenum_GLvoid__GENPT__const_GLsizei_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLenum_GLvoid___GENPT___GLsizei: {
            PACKED_void_GLenum_GLsizei_GLenum_GLvoid___GENPT___GLsizei *unpacked = (PACKED_void_GLenum_GLsizei_GLenum_GLvoid___GENPT___GLsizei *)packed;
            ARGS_void_GLenum_GLsizei_GLenum_GLvoid___GENPT___GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLenum_void___GENPT___GLsizei_GLsizei: {
            PACKED_void_GLenum_GLenum_void___GENPT___GLsizei_GLsizei *unpacked = (PACKED_void_GLenum_GLenum_void___GENPT___GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_GLenum_void___GENPT___GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLvoid_GLsizei_GLsizei: {
            PACKED_void_GLenum_GLenum_GLvoid_GLsizei_GLsizei *unpacked = (PACKED_void_GLenum_GLenum_GLvoid_GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_GLenum_GLvoid_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLuint_GLint_GLsizei_GLsizei: {
            PACKED_void_GLenum_GLuint_GLuint_GLint_GLsizei_GLsizei *unpacked = (PACKED_void_GLenum_GLuint_GLuint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_GLuint_GLuint_GLint_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLsizei_GLsizei_GLint: {
            PACKED_void_GLenum_GLint_GLsizei_GLsizei_GLint *unpacked = (PACKED_void_GLenum_GLint_GLsizei_GLsizei_GLint *)packed;
            ARGS_void_GLenum_GLint_GLsizei_GLsizei_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLbyte: {
            PACKED_void_GLenum_GLbyte *unpacked = (PACKED_void_GLenum_GLbyte *)packed;
            ARGS_void_GLenum_GLbyte args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLhalfNV: {
            PACKED_void_GLenum_GLhalfNV *unpacked = (PACKED_void_GLenum_GLhalfNV *)packed;
            ARGS_void_GLenum_GLhalfNV args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLshort: {
            PACKED_void_GLenum_GLshort *unpacked = (PACKED_void_GLenum_GLshort *)packed;
            ARGS_void_GLenum_GLshort args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLbyte_GLbyte: {
            PACKED_void_GLenum_GLbyte_GLbyte *unpacked = (PACKED_void_GLenum_GLbyte_GLbyte *)packed;
            ARGS_void_GLenum_GLbyte_GLbyte args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLdouble_GLdouble: {
            PACKED_void_GLenum_GLdouble_GLdouble *unpacked = (PACKED_void_GLenum_GLdouble_GLdouble *)packed;
            ARGS_void_GLenum_GLdouble_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLfloat_GLfloat: {
            PACKED_void_GLenum_GLfloat_GLfloat *unpacked = (PACKED_void_GLenum_GLfloat_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLhalfNV_GLhalfNV: {
            PACKED_void_GLenum_GLhalfNV_GLhalfNV *unpacked = (PACKED_void_GLenum_GLhalfNV_GLhalfNV *)packed;
            ARGS_void_GLenum_GLhalfNV_GLhalfNV args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLshort_GLshort: {
            PACKED_void_GLenum_GLshort_GLshort *unpacked = (PACKED_void_GLenum_GLshort_GLshort *)packed;
            ARGS_void_GLenum_GLshort_GLshort args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLfixed_GLfixed: {
            PACKED_void_GLenum_GLfixed_GLfixed *unpacked = (PACKED_void_GLenum_GLfixed_GLfixed *)packed;
            ARGS_void_GLenum_GLfixed_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLbyte_GLbyte_GLbyte: {
            PACKED_void_GLenum_GLbyte_GLbyte_GLbyte *unpacked = (PACKED_void_GLenum_GLbyte_GLbyte_GLbyte *)packed;
            ARGS_void_GLenum_GLbyte_GLbyte_GLbyte args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLhalfNV_GLhalfNV_GLhalfNV: {
            PACKED_void_GLenum_GLhalfNV_GLhalfNV_GLhalfNV *unpacked = (PACKED_void_GLenum_GLhalfNV_GLhalfNV_GLhalfNV *)packed;
            ARGS_void_GLenum_GLhalfNV_GLhalfNV_GLhalfNV args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint: {
            PACKED_void_GLenum_GLint_GLint_GLint *unpacked = (PACKED_void_GLenum_GLint_GLint_GLint *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLshort_GLshort_GLshort: {
            PACKED_void_GLenum_GLshort_GLshort_GLshort *unpacked = (PACKED_void_GLenum_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLenum_GLshort_GLshort_GLshort args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLfixed_GLfixed_GLfixed: {
            PACKED_void_GLenum_GLfixed_GLfixed_GLfixed *unpacked = (PACKED_void_GLenum_GLfixed_GLfixed_GLfixed *)packed;
            ARGS_void_GLenum_GLfixed_GLfixed_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLbyte_GLbyte_GLbyte_GLbyte: {
            PACKED_void_GLenum_GLbyte_GLbyte_GLbyte_GLbyte *unpacked = (PACKED_void_GLenum_GLbyte_GLbyte_GLbyte_GLbyte *)packed;
            ARGS_void_GLenum_GLbyte_GLbyte_GLbyte_GLbyte args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV: {
            PACKED_void_GLenum_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV *unpacked = (PACKED_void_GLenum_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV *)packed;
            ARGS_void_GLenum_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLshort_GLshort_GLshort_GLshort: {
            PACKED_void_GLenum_GLshort_GLshort_GLshort_GLshort *unpacked = (PACKED_void_GLenum_GLshort_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLenum_GLshort_GLshort_GLshort_GLshort args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed: {
            PACKED_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed *unpacked = (PACKED_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed *)packed;
            ARGS_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLvoid: {
            PACKED_void_GLenum_GLint_GLenum_GLsizei_GLvoid *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLsizei_GLvoid *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLint_GLenum_GLenum_GLvoid: {
            PACKED_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLint_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLint_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLint_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid: {
            PACKED_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid: {
            PACKED_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid: {
            PACKED_void_GLenum_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid: {
            PACKED_void_GLenum_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid: {
            PACKED_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11, args.a12);
            break;
        }
        case FORMAT_void_GLuint_GLsizeiptr_GLvoid_GLenum: {
            PACKED_void_GLuint_GLsizeiptr_GLvoid_GLenum *unpacked = (PACKED_void_GLuint_GLsizeiptr_GLvoid_GLenum *)packed;
            ARGS_void_GLuint_GLsizeiptr_GLvoid_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLintptr_GLintptr_GLsizeiptr: {
            PACKED_void_GLuint_GLuint_GLintptr_GLintptr_GLsizeiptr *unpacked = (PACKED_void_GLuint_GLuint_GLintptr_GLintptr_GLsizeiptr *)packed;
            ARGS_void_GLuint_GLuint_GLintptr_GLintptr_GLsizeiptr args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLenum_GLuint_GLint: {
            PACKED_void_GLuint_GLenum_GLenum_GLuint_GLint *unpacked = (PACKED_void_GLuint_GLenum_GLenum_GLuint_GLint *)packed;
            ARGS_void_GLuint_GLenum_GLenum_GLuint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLenum_GLuint_GLint_GLint: {
            PACKED_void_GLuint_GLenum_GLenum_GLuint_GLint_GLint *unpacked = (PACKED_void_GLuint_GLenum_GLenum_GLuint_GLint_GLint *)packed;
            ARGS_void_GLuint_GLenum_GLenum_GLuint_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLuint_GLint_GLenum: {
            PACKED_void_GLuint_GLenum_GLuint_GLint_GLenum *unpacked = (PACKED_void_GLuint_GLenum_GLuint_GLint_GLenum *)packed;
            ARGS_void_GLuint_GLenum_GLuint_GLint_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLuint_GLint_GLint: {
            PACKED_void_GLuint_GLenum_GLuint_GLint_GLint *unpacked = (PACKED_void_GLuint_GLenum_GLuint_GLint_GLint *)packed;
            ARGS_void_GLuint_GLenum_GLuint_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLuint_GLdouble_GLdouble_GLdouble_GLdouble: {
            PACKED_void_GLuint_GLenum_GLuint_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (PACKED_void_GLuint_GLenum_GLuint_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLuint_GLenum_GLuint_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLuint_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLuint_GLenum_GLuint_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLuint_GLenum_GLuint_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLuint_GLenum_GLuint_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLuint_GLint_GLint_GLint_GLint: {
            PACKED_void_GLuint_GLenum_GLuint_GLint_GLint_GLint_GLint *unpacked = (PACKED_void_GLuint_GLenum_GLuint_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLuint_GLenum_GLuint_GLint_GLint_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint: {
            PACKED_void_GLuint_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint *unpacked = (PACKED_void_GLuint_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint *)packed;
            ARGS_void_GLuint_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLuint_GLsizei_GLfloat: {
            PACKED_void_GLuint_GLenum_GLuint_GLsizei_GLfloat *unpacked = (PACKED_void_GLuint_GLenum_GLuint_GLsizei_GLfloat *)packed;
            ARGS_void_GLuint_GLenum_GLuint_GLsizei_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLuint_GLsizei_GLint: {
            PACKED_void_GLuint_GLenum_GLuint_GLsizei_GLint *unpacked = (PACKED_void_GLuint_GLenum_GLuint_GLsizei_GLint *)packed;
            ARGS_void_GLuint_GLenum_GLuint_GLsizei_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLuint_GLsizei_GLuint: {
            PACKED_void_GLuint_GLenum_GLuint_GLsizei_GLuint *unpacked = (PACKED_void_GLuint_GLenum_GLuint_GLsizei_GLuint *)packed;
            ARGS_void_GLuint_GLenum_GLuint_GLsizei_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLenum_GLsizei_GLvoid: {
            PACKED_void_GLuint_GLenum_GLenum_GLsizei_GLvoid *unpacked = (PACKED_void_GLuint_GLenum_GLenum_GLsizei_GLvoid *)packed;
            ARGS_void_GLuint_GLenum_GLenum_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLsizei_GLsizei: {
            PACKED_void_GLuint_GLenum_GLsizei_GLsizei *unpacked = (PACKED_void_GLuint_GLenum_GLsizei_GLsizei *)packed;
            ARGS_void_GLuint_GLenum_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLsizei_GLenum_GLsizei_GLsizei: {
            PACKED_void_GLuint_GLsizei_GLsizei_GLenum_GLsizei_GLsizei *unpacked = (PACKED_void_GLuint_GLsizei_GLsizei_GLenum_GLsizei_GLsizei *)packed;
            ARGS_void_GLuint_GLsizei_GLsizei_GLenum_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLenum_GLsizei_GLsizei: {
            PACKED_void_GLuint_GLsizei_GLenum_GLsizei_GLsizei *unpacked = (PACKED_void_GLuint_GLsizei_GLenum_GLsizei_GLsizei *)packed;
            ARGS_void_GLuint_GLsizei_GLenum_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLchar_GLint_GLchar: {
            PACKED_void_GLenum_GLint_GLchar_GLint_GLchar *unpacked = (PACKED_void_GLenum_GLint_GLchar_GLint_GLchar *)packed;
            ARGS_void_GLenum_GLint_GLchar_GLint_GLchar args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_UInt32_GLsizei_GLvoid_GLenum: {
            PACKED_UInt32_GLsizei_GLvoid_GLenum *unpacked = (PACKED_UInt32_GLsizei_GLvoid_GLenum *)packed;
            ARGS_UInt32_GLsizei_GLvoid_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLsizei_GLchar: {
            PACKED_void_GLenum_GLuint_GLsizei_GLchar *unpacked = (PACKED_void_GLenum_GLuint_GLsizei_GLchar *)packed;
            ARGS_void_GLenum_GLuint_GLsizei_GLchar args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_void___GENPT___GLsizei_GLchar: {
            PACKED_void_void___GENPT___GLsizei_GLchar *unpacked = (PACKED_void_void___GENPT___GLsizei_GLchar *)packed;
            ARGS_void_void___GENPT___GLsizei_GLchar args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_GLenum_GLenum_GLuint_GLenum: {
            PACKED_GLenum_GLenum_GLuint_GLenum *unpacked = (PACKED_GLenum_GLenum_GLuint_GLenum *)packed;
            ARGS_GLenum_GLenum_GLuint_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLenum: {
            PACKED_void_GLuint_GLuint_GLenum *unpacked = (PACKED_void_GLuint_GLuint_GLenum *)packed;
            ARGS_void_GLuint_GLuint_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLubyte_GLsizei_GLenum_GLvoid: {
            PACKED_void_GLuint_GLsizei_GLubyte_GLsizei_GLenum_GLvoid *unpacked = (PACKED_void_GLuint_GLsizei_GLubyte_GLsizei_GLenum_GLvoid *)packed;
            ARGS_void_GLuint_GLsizei_GLubyte_GLsizei_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLenum_GLvoid: {
            PACKED_void_GLuint_GLsizei_GLenum_GLvoid *unpacked = (PACKED_void_GLuint_GLsizei_GLenum_GLvoid *)packed;
            ARGS_void_GLuint_GLsizei_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLfloat: {
            PACKED_void_GLuint_GLsizei_GLfloat *unpacked = (PACKED_void_GLuint_GLsizei_GLfloat *)packed;
            ARGS_void_GLuint_GLsizei_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLvoid_GLbitfield_GLuint_GLsizei_GLenum_GLuint_GLfloat: {
            PACKED_void_GLuint_GLenum_GLvoid_GLbitfield_GLuint_GLsizei_GLenum_GLuint_GLfloat *unpacked = (PACKED_void_GLuint_GLenum_GLvoid_GLbitfield_GLuint_GLsizei_GLenum_GLuint_GLfloat *)packed;
            ARGS_void_GLuint_GLenum_GLvoid_GLbitfield_GLuint_GLsizei_GLenum_GLuint_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLvoid_GLbitfield_GLsizei_GLenum_GLvoid_GLenum_GLuint_GLfloat: {
            PACKED_void_GLuint_GLenum_GLvoid_GLbitfield_GLsizei_GLenum_GLvoid_GLenum_GLuint_GLfloat *unpacked = (PACKED_void_GLuint_GLenum_GLvoid_GLbitfield_GLsizei_GLenum_GLvoid_GLenum_GLuint_GLfloat *)packed;
            ARGS_void_GLuint_GLenum_GLvoid_GLbitfield_GLsizei_GLenum_GLvoid_GLenum_GLuint_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLsizei_GLvoid: {
            PACKED_void_GLuint_GLenum_GLsizei_GLvoid *unpacked = (PACKED_void_GLuint_GLenum_GLsizei_GLvoid *)packed;
            ARGS_void_GLuint_GLenum_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLsizei_GLsizei_GLubyte_GLsizei_GLenum_GLvoid: {
            PACKED_void_GLuint_GLsizei_GLsizei_GLsizei_GLubyte_GLsizei_GLenum_GLvoid *unpacked = (PACKED_void_GLuint_GLsizei_GLsizei_GLsizei_GLubyte_GLsizei_GLenum_GLvoid *)packed;
            ARGS_void_GLuint_GLsizei_GLsizei_GLsizei_GLubyte_GLsizei_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLfloat: {
            PACKED_void_GLenum_GLenum_GLint_GLfloat *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLfloat *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_Boolean_GLuint_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_Boolean_GLuint_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_Boolean_GLuint_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_Boolean_GLuint_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_Int32_GLint: {
            PACKED_Int32_GLint *unpacked = (PACKED_Int32_GLint *)packed;
            ARGS_Int32_GLint args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLuint_GLuint64EXT_GLuint_GLuint_GLenum_GLenum_GLuint_GLenum_GLuint_GLenum_GLuint_GLenum_GLuint: {
            PACKED_void_GLuint_GLuint64EXT_GLuint_GLuint_GLenum_GLenum_GLuint_GLenum_GLuint_GLenum_GLuint_GLenum_GLuint *unpacked = (PACKED_void_GLuint_GLuint64EXT_GLuint_GLuint_GLenum_GLenum_GLuint_GLenum_GLuint_GLenum_GLuint_GLenum_GLuint *)packed;
            ARGS_void_GLuint_GLuint64EXT_GLuint_GLuint_GLenum_GLenum_GLuint_GLenum_GLuint_GLenum_GLuint_GLenum_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11, args.a12, args.a13);
            break;
        }
        case FORMAT_void_GLuint_GLuint64EXT_GLuint_GLuint_GLenum_GLenum_GLuint_GLuint_GLenum_GLuint_GLuint: {
            PACKED_void_GLuint_GLuint64EXT_GLuint_GLuint_GLenum_GLenum_GLuint_GLuint_GLenum_GLuint_GLuint *unpacked = (PACKED_void_GLuint_GLuint64EXT_GLuint_GLuint_GLenum_GLenum_GLuint_GLuint_GLenum_GLuint_GLuint *)packed;
            ARGS_void_GLuint_GLuint64EXT_GLuint_GLuint_GLenum_GLenum_GLuint_GLuint_GLenum_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11);
            break;
        }
        case FORMAT_void_GLsizei_GLuint_GLfloat: {
            PACKED_void_GLsizei_GLuint_GLfloat *unpacked = (PACKED_void_GLsizei_GLuint_GLfloat *)packed;
            ARGS_void_GLsizei_GLuint_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLsizei_GLuint_GLclampf: {
            PACKED_void_GLsizei_GLuint_GLclampf *unpacked = (PACKED_void_GLsizei_GLuint_GLclampf *)packed;
            ARGS_void_GLsizei_GLuint_GLclampf args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLsizei_GLuint_GLfixed: {
            PACKED_void_GLsizei_GLuint_GLfixed *unpacked = (PACKED_void_GLsizei_GLuint_GLfixed *)packed;
            ARGS_void_GLsizei_GLuint_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLvoid_GLsizei: {
            PACKED_void_GLuint_GLenum_GLvoid_GLsizei *unpacked = (PACKED_void_GLuint_GLenum_GLvoid_GLsizei *)packed;
            ARGS_void_GLuint_GLenum_GLvoid_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLuint_GLsizei_GLint: {
            PACKED_void_GLenum_GLuint_GLuint_GLsizei_GLint *unpacked = (PACKED_void_GLenum_GLuint_GLuint_GLsizei_GLint *)packed;
            ARGS_void_GLenum_GLuint_GLuint_GLsizei_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLuint_GLsizei_GLuint: {
            PACKED_void_GLenum_GLuint_GLuint_GLsizei_GLuint *unpacked = (PACKED_void_GLenum_GLuint_GLuint_GLsizei_GLuint *)packed;
            ARGS_void_GLenum_GLuint_GLuint_GLsizei_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLuint_GLsizei_GLfloat: {
            PACKED_void_GLenum_GLuint_GLuint_GLsizei_GLfloat *unpacked = (PACKED_void_GLenum_GLuint_GLuint_GLsizei_GLfloat *)packed;
            ARGS_void_GLenum_GLuint_GLuint_GLsizei_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLdouble_GLdouble_GLdouble_GLdouble: {
            PACKED_void_GLenum_GLuint_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (PACKED_void_GLenum_GLuint_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLenum_GLuint_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLenum_GLuint_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLenum_GLuint_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLenum_GLuint_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLint_GLint_GLint_GLint: {
            PACKED_void_GLenum_GLuint_GLint_GLint_GLint_GLint *unpacked = (PACKED_void_GLenum_GLuint_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLenum_GLuint_GLint_GLint_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLsizei_GLfloat: {
            PACKED_void_GLenum_GLuint_GLsizei_GLfloat *unpacked = (PACKED_void_GLenum_GLuint_GLsizei_GLfloat *)packed;
            ARGS_void_GLenum_GLuint_GLsizei_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLsizei_GLint: {
            PACKED_void_GLenum_GLuint_GLsizei_GLint *unpacked = (PACKED_void_GLenum_GLuint_GLsizei_GLint *)packed;
            ARGS_void_GLenum_GLuint_GLsizei_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLsizei_GLuint: {
            PACKED_void_GLenum_GLuint_GLsizei_GLuint *unpacked = (PACKED_void_GLenum_GLuint_GLsizei_GLuint *)packed;
            ARGS_void_GLenum_GLuint_GLsizei_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLubyte_GLdouble_GLdouble_GLdouble_GLdouble: {
            PACKED_void_GLuint_GLsizei_GLubyte_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (PACKED_void_GLuint_GLsizei_GLubyte_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLuint_GLsizei_GLubyte_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLubyte_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLuint_GLsizei_GLubyte_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLuint_GLsizei_GLubyte_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLuint_GLsizei_GLubyte_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLsizei_GLdouble: {
            PACKED_void_GLenum_GLuint_GLsizei_GLdouble *unpacked = (PACKED_void_GLenum_GLuint_GLsizei_GLdouble *)packed;
            ARGS_void_GLenum_GLuint_GLsizei_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLsizei_GLvoid: {
            PACKED_void_GLenum_GLenum_GLsizei_GLvoid *unpacked = (PACKED_void_GLenum_GLenum_GLsizei_GLvoid *)packed;
            ARGS_void_GLenum_GLenum_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLsizei_GLint64EXT: {
            PACKED_void_GLuint_GLint_GLsizei_GLint64EXT *unpacked = (PACKED_void_GLuint_GLint_GLsizei_GLint64EXT *)packed;
            ARGS_void_GLuint_GLint_GLsizei_GLint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLsizei_GLuint64EXT: {
            PACKED_void_GLuint_GLint_GLsizei_GLuint64EXT *unpacked = (PACKED_void_GLuint_GLint_GLsizei_GLuint64EXT *)packed;
            ARGS_void_GLuint_GLint_GLsizei_GLuint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLdouble_GLdouble: {
            PACKED_void_GLuint_GLint_GLdouble_GLdouble *unpacked = (PACKED_void_GLuint_GLint_GLdouble_GLdouble *)packed;
            ARGS_void_GLuint_GLint_GLdouble_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLfloat_GLfloat: {
            PACKED_void_GLuint_GLint_GLfloat_GLfloat *unpacked = (PACKED_void_GLuint_GLint_GLfloat_GLfloat *)packed;
            ARGS_void_GLuint_GLint_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLint_GLint: {
            PACKED_void_GLuint_GLint_GLint_GLint *unpacked = (PACKED_void_GLuint_GLint_GLint_GLint *)packed;
            ARGS_void_GLuint_GLint_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLint64EXT_GLint64EXT: {
            PACKED_void_GLuint_GLint_GLint64EXT_GLint64EXT *unpacked = (PACKED_void_GLuint_GLint_GLint64EXT_GLint64EXT *)packed;
            ARGS_void_GLuint_GLint_GLint64EXT_GLint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLuint_GLuint: {
            PACKED_void_GLuint_GLint_GLuint_GLuint *unpacked = (PACKED_void_GLuint_GLint_GLuint_GLuint *)packed;
            ARGS_void_GLuint_GLint_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLuint64EXT_GLuint64EXT: {
            PACKED_void_GLuint_GLint_GLuint64EXT_GLuint64EXT *unpacked = (PACKED_void_GLuint_GLint_GLuint64EXT_GLuint64EXT *)packed;
            ARGS_void_GLuint_GLint_GLuint64EXT_GLuint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLdouble_GLdouble_GLdouble: {
            PACKED_void_GLuint_GLint_GLdouble_GLdouble_GLdouble *unpacked = (PACKED_void_GLuint_GLint_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLuint_GLint_GLdouble_GLdouble_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLuint_GLint_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLuint_GLint_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLuint_GLint_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLint_GLint_GLint: {
            PACKED_void_GLuint_GLint_GLint_GLint_GLint *unpacked = (PACKED_void_GLuint_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLuint_GLint_GLint_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLint64EXT_GLint64EXT_GLint64EXT: {
            PACKED_void_GLuint_GLint_GLint64EXT_GLint64EXT_GLint64EXT *unpacked = (PACKED_void_GLuint_GLint_GLint64EXT_GLint64EXT_GLint64EXT *)packed;
            ARGS_void_GLuint_GLint_GLint64EXT_GLint64EXT_GLint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLuint_GLuint_GLuint: {
            PACKED_void_GLuint_GLint_GLuint_GLuint_GLuint *unpacked = (PACKED_void_GLuint_GLint_GLuint_GLuint_GLuint *)packed;
            ARGS_void_GLuint_GLint_GLuint_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT: {
            PACKED_void_GLuint_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT *unpacked = (PACKED_void_GLuint_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT *)packed;
            ARGS_void_GLuint_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLdouble_GLdouble_GLdouble_GLdouble: {
            PACKED_void_GLuint_GLint_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (PACKED_void_GLuint_GLint_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLuint_GLint_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLuint_GLint_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLuint_GLint_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLuint_GLint_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLint_GLint_GLint_GLint: {
            PACKED_void_GLuint_GLint_GLint_GLint_GLint_GLint *unpacked = (PACKED_void_GLuint_GLint_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLuint_GLint_GLint_GLint_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT: {
            PACKED_void_GLuint_GLint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT *unpacked = (PACKED_void_GLuint_GLint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT *)packed;
            ARGS_void_GLuint_GLint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLuint_GLuint_GLuint_GLuint: {
            PACKED_void_GLuint_GLint_GLuint_GLuint_GLuint_GLuint *unpacked = (PACKED_void_GLuint_GLint_GLuint_GLuint_GLuint_GLuint *)packed;
            ARGS_void_GLuint_GLint_GLuint_GLuint_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT: {
            PACKED_void_GLuint_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT *unpacked = (PACKED_void_GLuint_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT *)packed;
            ARGS_void_GLuint_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLuint64: {
            PACKED_void_GLuint_GLint_GLuint64 *unpacked = (PACKED_void_GLuint_GLint_GLuint64 *)packed;
            ARGS_void_GLuint_GLint_GLuint64 args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLsizei_GLuint64: {
            PACKED_void_GLuint_GLint_GLsizei_GLuint64 *unpacked = (PACKED_void_GLuint_GLint_GLsizei_GLuint64 *)packed;
            ARGS_void_GLuint_GLint_GLsizei_GLuint64 args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLsizei_GLboolean_GLdouble: {
            PACKED_void_GLuint_GLint_GLsizei_GLboolean_GLdouble *unpacked = (PACKED_void_GLuint_GLint_GLsizei_GLboolean_GLdouble *)packed;
            ARGS_void_GLuint_GLint_GLsizei_GLboolean_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLsizei_GLboolean_GLfloat: {
            PACKED_void_GLuint_GLint_GLsizei_GLboolean_GLfloat *unpacked = (PACKED_void_GLuint_GLint_GLsizei_GLboolean_GLfloat *)packed;
            ARGS_void_GLuint_GLint_GLsizei_GLboolean_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_GLbitfield_GLfixed_GLint: {
            PACKED_GLbitfield_GLfixed_GLint *unpacked = (PACKED_GLbitfield_GLfixed_GLint *)packed;
            ARGS_GLbitfield_GLfixed_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLshort_GLshort: {
            PACKED_void_GLshort_GLshort *unpacked = (PACKED_void_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid: {
            PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLsizei_GLvoid: {
            PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLsizei_GLvoid *unpacked = (PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLsizei_GLvoid *)packed;
            ARGS_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_Int32_GLenum: {
            PACKED_Int32_GLenum *unpacked = (PACKED_Int32_GLenum *)packed;
            ARGS_Int32_GLenum args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLsizei_GLsizei: {
            PACKED_void_GLenum_GLenum_GLsizei_GLsizei *unpacked = (PACKED_void_GLenum_GLenum_GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_GLenum_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei: {
            PACKED_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei *unpacked = (PACKED_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLsizei_GLenum_GLsizei_GLsizei: {
            PACKED_void_GLenum_GLsizei_GLsizei_GLenum_GLsizei_GLsizei *unpacked = (PACKED_void_GLenum_GLsizei_GLsizei_GLenum_GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_GLsizei_GLsizei_GLenum_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLsizei_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLsizei_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLuint_GLfloat_GLfloat: {
            PACKED_void_GLuint_GLfloat_GLfloat *unpacked = (PACKED_void_GLuint_GLfloat_GLfloat *)packed;
            ARGS_void_GLuint_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11);
            break;
        }
        case FORMAT_void_GLuint_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLuint_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLuint_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLuint_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLuint_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLuint_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLuint_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLuint_GLubyte_GLfloat: {
            PACKED_void_GLuint_GLubyte_GLfloat *unpacked = (PACKED_void_GLuint_GLubyte_GLfloat *)packed;
            ARGS_void_GLuint_GLubyte_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11, args.a12, args.a13);
            break;
        }
        case FORMAT_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLfloat_GLboolean: {
            PACKED_void_GLfloat_GLboolean *unpacked = (PACKED_void_GLfloat_GLboolean *)packed;
            ARGS_void_GLfloat_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLfixed_GLboolean: {
            PACKED_void_GLfixed_GLboolean *unpacked = (PACKED_void_GLfixed_GLboolean *)packed;
            ARGS_void_GLfixed_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLclampf_GLboolean: {
            PACKED_void_GLclampf_GLboolean *unpacked = (PACKED_void_GLclampf_GLboolean *)packed;
            ARGS_void_GLclampf_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLbitfield: {
            PACKED_void_GLuint_GLbitfield *unpacked = (PACKED_void_GLuint_GLbitfield *)packed;
            ARGS_void_GLuint_GLbitfield args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLint_GLint_GLsizei_GLsizei: {
            PACKED_void_GLint_GLint_GLsizei_GLsizei *unpacked = (PACKED_void_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLint: {
            PACKED_void_GLuint_GLsizei_GLint *unpacked = (PACKED_void_GLuint_GLsizei_GLint *)packed;
            ARGS_void_GLuint_GLsizei_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLint_GLsizei_GLsizei: {
            PACKED_void_GLuint_GLint_GLint_GLsizei_GLsizei *unpacked = (PACKED_void_GLuint_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLuint_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLboolean_GLuint_GLint_GLuint: {
            PACKED_void_GLuint_GLboolean_GLuint_GLint_GLuint *unpacked = (PACKED_void_GLuint_GLboolean_GLuint_GLint_GLuint *)packed;
            ARGS_void_GLuint_GLboolean_GLuint_GLint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid_GLvoid: {
            PACKED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid_GLvoid *unpacked = (PACKED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid_GLvoid *)packed;
            ARGS_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLvoid: {
            PACKED_void_GLuint_GLenum_GLvoid *unpacked = (PACKED_void_GLuint_GLenum_GLvoid *)packed;
            ARGS_void_GLuint_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLsizei_GLuint_GLenum_GLvoid_GLsizei: {
            PACKED_void_GLsizei_GLuint_GLenum_GLvoid_GLsizei *unpacked = (PACKED_void_GLsizei_GLuint_GLenum_GLvoid_GLsizei *)packed;
            ARGS_void_GLsizei_GLuint_GLenum_GLvoid_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLuint_GLuint: {
            PACKED_void_GLenum_GLuint_GLuint_GLuint *unpacked = (PACKED_void_GLenum_GLuint_GLuint_GLuint *)packed;
            ARGS_void_GLenum_GLuint_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLuint_GLuint_GLuint: {
            PACKED_void_GLenum_GLuint_GLuint_GLuint_GLuint *unpacked = (PACKED_void_GLenum_GLuint_GLuint_GLuint_GLuint *)packed;
            ARGS_void_GLenum_GLuint_GLuint_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLchar__GENPT__const_GLint: {
            PACKED_void_GLuint_GLsizei_GLchar__GENPT__const_GLint *unpacked = (PACKED_void_GLuint_GLsizei_GLchar__GENPT__const_GLint *)packed;
            ARGS_void_GLuint_GLsizei_GLchar__GENPT__const_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLhandleARB_GLsizei_GLcharARB___GENPT___GLint: {
            PACKED_void_GLhandleARB_GLsizei_GLcharARB___GENPT___GLint *unpacked = (PACKED_void_GLhandleARB_GLsizei_GLcharARB___GENPT___GLint *)packed;
            ARGS_void_GLhandleARB_GLsizei_GLcharARB___GENPT___GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLsizei_GLenum_GLvoid_GLuint_GLenum_GLuint_GLenum_GLfloat: {
            PACKED_void_GLsizei_GLenum_GLvoid_GLuint_GLenum_GLuint_GLenum_GLfloat *unpacked = (PACKED_void_GLsizei_GLenum_GLvoid_GLuint_GLenum_GLuint_GLenum_GLfloat *)packed;
            ARGS_void_GLsizei_GLenum_GLvoid_GLuint_GLenum_GLuint_GLenum_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint_GLuint: {
            PACKED_void_GLenum_GLenum_GLint_GLuint *unpacked = (PACKED_void_GLenum_GLenum_GLint_GLuint *)packed;
            ARGS_void_GLenum_GLenum_GLint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum: {
            PACKED_void_GLenum_GLenum_GLenum *unpacked = (PACKED_void_GLenum_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLsizei_GLenum_GLvoid_GLuint_GLint_GLuint_GLenum_GLfloat: {
            PACKED_void_GLsizei_GLenum_GLvoid_GLuint_GLint_GLuint_GLenum_GLfloat *unpacked = (PACKED_void_GLsizei_GLenum_GLvoid_GLuint_GLint_GLuint_GLenum_GLfloat *)packed;
            ARGS_void_GLsizei_GLenum_GLvoid_GLuint_GLint_GLuint_GLenum_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLenum_GLenum_GLenum_GLenum: {
            PACKED_void_GLuint_GLuint_GLenum_GLenum_GLenum_GLenum *unpacked = (PACKED_void_GLuint_GLuint_GLenum_GLenum_GLenum_GLenum *)packed;
            ARGS_void_GLuint_GLuint_GLenum_GLenum_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLuint_GLintptr_GLsizeiptr: {
            PACKED_void_GLenum_GLenum_GLuint_GLintptr_GLsizeiptr *unpacked = (PACKED_void_GLenum_GLenum_GLuint_GLintptr_GLsizeiptr *)packed;
            ARGS_void_GLenum_GLenum_GLuint_GLintptr_GLsizeiptr args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLbyte_GLbyte: {
            PACKED_void_GLbyte_GLbyte *unpacked = (PACKED_void_GLbyte_GLbyte *)packed;
            ARGS_void_GLbyte_GLbyte args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11, args.a12);
            break;
        }
        case FORMAT_void_GLfloat_GLfloat_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLfloat_GLubyte_GLfloat: {
            PACKED_void_GLfloat_GLubyte_GLfloat *unpacked = (PACKED_void_GLfloat_GLubyte_GLfloat *)packed;
            ARGS_void_GLfloat_GLubyte_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLhalfNV_GLhalfNV: {
            PACKED_void_GLhalfNV_GLhalfNV *unpacked = (PACKED_void_GLhalfNV_GLhalfNV *)packed;
            ARGS_void_GLhalfNV_GLhalfNV args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11, args.a12, args.a13, args.a14, args.a15);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_GLvoid: {
            PACKED_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid: {
            PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLboolean: {
            PACKED_void_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLboolean *unpacked = (PACKED_void_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLboolean *)packed;
            ARGS_void_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLboolean: {
            PACKED_void_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLboolean *unpacked = (PACKED_void_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLboolean *)packed;
            ARGS_void_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid: {
            PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid: {
            PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean: {
            PACKED_void_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean *unpacked = (PACKED_void_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean *)packed;
            ARGS_void_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean: {
            PACKED_void_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean *unpacked = (PACKED_void_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean *)packed;
            ARGS_void_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid: {
            PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLenum_GLsizei: {
            PACKED_void_GLenum_GLsizei_GLenum_GLsizei *unpacked = (PACKED_void_GLenum_GLsizei_GLenum_GLsizei *)packed;
            ARGS_void_GLenum_GLsizei_GLenum_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLboolean: {
            PACKED_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLboolean *unpacked = (PACKED_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLboolean *)packed;
            ARGS_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei: {
            PACKED_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei *unpacked = (PACKED_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei_GLboolean: {
            PACKED_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei_GLboolean *unpacked = (PACKED_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei_GLboolean *)packed;
            ARGS_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLbitfield: {
            PACKED_void_GLenum_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLbitfield *unpacked = (PACKED_void_GLenum_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLbitfield *)packed;
            ARGS_void_GLenum_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLbitfield args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid: {
            PACKED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid: {
            PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid: {
            PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid: {
            PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11, args.a12, args.a13);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLenum_GLuint_GLintptr_GLsizeiptr: {
            PACKED_void_GLuint_GLenum_GLenum_GLuint_GLintptr_GLsizeiptr *unpacked = (PACKED_void_GLuint_GLenum_GLenum_GLuint_GLintptr_GLsizeiptr *)packed;
            ARGS_void_GLuint_GLenum_GLenum_GLuint_GLintptr_GLsizeiptr args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLint_GLenum_GLenum_GLvoid: {
            PACKED_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLint_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLint_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLint_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid: {
            PACKED_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLboolean: {
            PACKED_void_GLuint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLboolean *unpacked = (PACKED_void_GLuint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLboolean *)packed;
            ARGS_void_GLuint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLboolean: {
            PACKED_void_GLuint_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLboolean *unpacked = (PACKED_void_GLuint_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLboolean *)packed;
            ARGS_void_GLuint_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid: {
            PACKED_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean: {
            PACKED_void_GLuint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean *unpacked = (PACKED_void_GLuint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean *)packed;
            ARGS_void_GLuint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean: {
            PACKED_void_GLuint_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean *unpacked = (PACKED_void_GLuint_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean *)packed;
            ARGS_void_GLuint_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLsizei_GLenum_GLsizei: {
            PACKED_void_GLuint_GLenum_GLsizei_GLenum_GLsizei *unpacked = (PACKED_void_GLuint_GLenum_GLsizei_GLenum_GLsizei *)packed;
            ARGS_void_GLuint_GLenum_GLsizei_GLenum_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei: {
            PACKED_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei *unpacked = (PACKED_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei *)packed;
            ARGS_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLboolean: {
            PACKED_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLboolean *unpacked = (PACKED_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLboolean *)packed;
            ARGS_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei: {
            PACKED_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei *unpacked = (PACKED_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei *)packed;
            ARGS_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei_GLboolean: {
            PACKED_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei_GLboolean *unpacked = (PACKED_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei_GLboolean *)packed;
            ARGS_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLbitfield: {
            PACKED_void_GLuint_GLenum_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLbitfield *unpacked = (PACKED_void_GLuint_GLenum_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLbitfield *)packed;
            ARGS_void_GLuint_GLenum_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLbitfield args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid: {
            PACKED_void_GLuint_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLuint_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLuint_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid: {
            PACKED_void_GLuint_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLuint_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLuint_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid: {
            PACKED_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid *unpacked = (PACKED_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid *)packed;
            ARGS_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11, args.a12);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLuint_GLenum_GLuint_GLuint_GLuint_GLuint: {
            PACKED_void_GLuint_GLenum_GLuint_GLenum_GLuint_GLuint_GLuint_GLuint *unpacked = (PACKED_void_GLuint_GLenum_GLuint_GLenum_GLuint_GLuint_GLuint_GLuint *)packed;
            ARGS_void_GLuint_GLenum_GLuint_GLenum_GLuint_GLuint_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLenum_GLenum: {
            PACKED_void_GLenum_GLuint_GLenum_GLenum *unpacked = (PACKED_void_GLenum_GLuint_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLuint_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLsizei_GLint_GLenum: {
            PACKED_void_GLsizei_GLint_GLenum *unpacked = (PACKED_void_GLsizei_GLint_GLenum *)packed;
            ARGS_void_GLsizei_GLint_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLsizei_GLint_GLsizei_GLint_GLenum: {
            PACKED_void_GLsizei_GLint_GLsizei_GLint_GLenum *unpacked = (PACKED_void_GLsizei_GLint_GLsizei_GLint_GLenum *)packed;
            ARGS_void_GLsizei_GLint_GLsizei_GLint_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLchar__GENPT__const_GLenum: {
            PACKED_void_GLuint_GLsizei_GLchar__GENPT__const_GLenum *unpacked = (PACKED_void_GLuint_GLsizei_GLchar__GENPT__const_GLenum *)packed;
            ARGS_void_GLuint_GLsizei_GLchar__GENPT__const_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLchar___GENPT___GLenum: {
            PACKED_void_GLuint_GLsizei_GLchar___GENPT___GLenum *unpacked = (PACKED_void_GLuint_GLsizei_GLchar___GENPT___GLenum *)packed;
            ARGS_void_GLuint_GLsizei_GLchar___GENPT___GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLint_GLenum: {
            PACKED_void_GLuint_GLsizei_GLint_GLenum *unpacked = (PACKED_void_GLuint_GLsizei_GLint_GLenum *)packed;
            ARGS_void_GLuint_GLsizei_GLint_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLint_GLdouble: {
            PACKED_void_GLint_GLdouble *unpacked = (PACKED_void_GLint_GLdouble *)packed;
            ARGS_void_GLint_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLint_GLsizei_GLdouble: {
            PACKED_void_GLint_GLsizei_GLdouble *unpacked = (PACKED_void_GLint_GLsizei_GLdouble *)packed;
            ARGS_void_GLint_GLsizei_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLint_GLfloat: {
            PACKED_void_GLint_GLfloat *unpacked = (PACKED_void_GLint_GLfloat *)packed;
            ARGS_void_GLint_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLint_GLsizei_GLfloat: {
            PACKED_void_GLint_GLsizei_GLfloat *unpacked = (PACKED_void_GLint_GLsizei_GLfloat *)packed;
            ARGS_void_GLint_GLsizei_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLint_GLint64EXT: {
            PACKED_void_GLint_GLint64EXT *unpacked = (PACKED_void_GLint_GLint64EXT *)packed;
            ARGS_void_GLint_GLint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLint_GLsizei_GLint64EXT: {
            PACKED_void_GLint_GLsizei_GLint64EXT *unpacked = (PACKED_void_GLint_GLsizei_GLint64EXT *)packed;
            ARGS_void_GLint_GLsizei_GLint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLint_GLsizei_GLint: {
            PACKED_void_GLint_GLsizei_GLint *unpacked = (PACKED_void_GLint_GLsizei_GLint *)packed;
            ARGS_void_GLint_GLsizei_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLint_GLuint64EXT: {
            PACKED_void_GLint_GLuint64EXT *unpacked = (PACKED_void_GLint_GLuint64EXT *)packed;
            ARGS_void_GLint_GLuint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLint_GLsizei_GLuint64EXT: {
            PACKED_void_GLint_GLsizei_GLuint64EXT *unpacked = (PACKED_void_GLint_GLsizei_GLuint64EXT *)packed;
            ARGS_void_GLint_GLsizei_GLuint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLint_GLint64EXT_GLint64EXT: {
            PACKED_void_GLint_GLint64EXT_GLint64EXT *unpacked = (PACKED_void_GLint_GLint64EXT_GLint64EXT *)packed;
            ARGS_void_GLint_GLint64EXT_GLint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLint_GLuint_GLuint: {
            PACKED_void_GLint_GLuint_GLuint *unpacked = (PACKED_void_GLint_GLuint_GLuint *)packed;
            ARGS_void_GLint_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLint_GLuint64EXT_GLuint64EXT: {
            PACKED_void_GLint_GLuint64EXT_GLuint64EXT *unpacked = (PACKED_void_GLint_GLuint64EXT_GLuint64EXT *)packed;
            ARGS_void_GLint_GLuint64EXT_GLuint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLint_GLdouble_GLdouble_GLdouble: {
            PACKED_void_GLint_GLdouble_GLdouble_GLdouble *unpacked = (PACKED_void_GLint_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLint_GLdouble_GLdouble_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLint_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLint_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLint_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLint_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLint_GLint64EXT_GLint64EXT_GLint64EXT: {
            PACKED_void_GLint_GLint64EXT_GLint64EXT_GLint64EXT *unpacked = (PACKED_void_GLint_GLint64EXT_GLint64EXT_GLint64EXT *)packed;
            ARGS_void_GLint_GLint64EXT_GLint64EXT_GLint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLint_GLuint_GLuint_GLuint: {
            PACKED_void_GLint_GLuint_GLuint_GLuint *unpacked = (PACKED_void_GLint_GLuint_GLuint_GLuint *)packed;
            ARGS_void_GLint_GLuint_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT: {
            PACKED_void_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT *unpacked = (PACKED_void_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT *)packed;
            ARGS_void_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLint_GLdouble_GLdouble_GLdouble_GLdouble: {
            PACKED_void_GLint_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (PACKED_void_GLint_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLint_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLint_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLint_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLint_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLint_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLint_GLint_GLint_GLint_GLint: {
            PACKED_void_GLint_GLint_GLint_GLint_GLint *unpacked = (PACKED_void_GLint_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT: {
            PACKED_void_GLint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT *unpacked = (PACKED_void_GLint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT *)packed;
            ARGS_void_GLint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLint_GLuint_GLuint_GLuint_GLuint: {
            PACKED_void_GLint_GLuint_GLuint_GLuint_GLuint *unpacked = (PACKED_void_GLint_GLuint_GLuint_GLuint_GLuint *)packed;
            ARGS_void_GLint_GLuint_GLuint_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT: {
            PACKED_void_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT *unpacked = (PACKED_void_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT *)packed;
            ARGS_void_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLint_GLuint64: {
            PACKED_void_GLint_GLuint64 *unpacked = (PACKED_void_GLint_GLuint64 *)packed;
            ARGS_void_GLint_GLuint64 args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLint_GLsizei_GLuint64: {
            PACKED_void_GLint_GLsizei_GLuint64 *unpacked = (PACKED_void_GLint_GLsizei_GLuint64 *)packed;
            ARGS_void_GLint_GLsizei_GLuint64 args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLint_GLsizei_GLboolean_GLdouble: {
            PACKED_void_GLint_GLsizei_GLboolean_GLdouble *unpacked = (PACKED_void_GLint_GLsizei_GLboolean_GLdouble *)packed;
            ARGS_void_GLint_GLsizei_GLboolean_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLint_GLsizei_GLboolean_GLfloat: {
            PACKED_void_GLint_GLsizei_GLboolean_GLfloat *unpacked = (PACKED_void_GLint_GLsizei_GLboolean_GLfloat *)packed;
            ARGS_void_GLint_GLsizei_GLboolean_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLsizei_GLvoid_GLenum: {
            PACKED_void_GLuint_GLuint_GLsizei_GLvoid_GLenum *unpacked = (PACKED_void_GLuint_GLuint_GLsizei_GLvoid_GLenum *)packed;
            ARGS_void_GLuint_GLuint_GLsizei_GLvoid_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLbitfield_GLuint: {
            PACKED_void_GLuint_GLbitfield_GLuint *unpacked = (PACKED_void_GLuint_GLbitfield_GLuint *)packed;
            ARGS_void_GLuint_GLbitfield_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLvdpauSurfaceNV_GLenum_GLsizei_GLsizei_GLint: {
            PACKED_void_GLvdpauSurfaceNV_GLenum_GLsizei_GLsizei_GLint *unpacked = (PACKED_void_GLvdpauSurfaceNV_GLenum_GLsizei_GLsizei_GLint *)packed;
            ARGS_void_GLvdpauSurfaceNV_GLenum_GLsizei_GLsizei_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLvoid_GLvoid: {
            PACKED_void_GLvoid_GLvoid *unpacked = (PACKED_void_GLvoid_GLvoid *)packed;
            ARGS_void_GLvoid_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLvdpauSurfaceNV: {
            PACKED_void_GLvdpauSurfaceNV *unpacked = (PACKED_void_GLvdpauSurfaceNV *)packed;
            ARGS_void_GLvdpauSurfaceNV args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLsizei_GLvdpauSurfaceNV: {
            PACKED_void_GLsizei_GLvdpauSurfaceNV *unpacked = (PACKED_void_GLsizei_GLvdpauSurfaceNV *)packed;
            ARGS_void_GLsizei_GLvdpauSurfaceNV args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_vdpauSurfaceNV_GLvoid___GENPT___GLenum_GLsizei_GLuint: {
            PACKED_vdpauSurfaceNV_GLvoid___GENPT___GLenum_GLsizei_GLuint *unpacked = (PACKED_vdpauSurfaceNV_GLvoid___GENPT___GLenum_GLsizei_GLuint *)packed;
            ARGS_vdpauSurfaceNV_GLvoid___GENPT___GLenum_GLsizei_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_vdpauSurfaceNV_GLvoid_GLenum_GLsizei_GLuint: {
            PACKED_vdpauSurfaceNV_GLvoid_GLenum_GLsizei_GLuint *unpacked = (PACKED_vdpauSurfaceNV_GLvoid_GLenum_GLsizei_GLuint *)packed;
            ARGS_vdpauSurfaceNV_GLvoid_GLenum_GLsizei_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLvdpauSurfaceNV_GLenum: {
            PACKED_void_GLvdpauSurfaceNV_GLenum *unpacked = (PACKED_void_GLvdpauSurfaceNV_GLenum *)packed;
            ARGS_void_GLvdpauSurfaceNV_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLsizei_GLuint_GLuint: {
            PACKED_void_GLuint_GLenum_GLsizei_GLuint_GLuint *unpacked = (PACKED_void_GLuint_GLenum_GLsizei_GLuint_GLuint *)packed;
            ARGS_void_GLuint_GLenum_GLsizei_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLuint_GLvoid: {
            PACKED_void_GLuint_GLenum_GLuint_GLvoid *unpacked = (PACKED_void_GLuint_GLenum_GLuint_GLvoid *)packed;
            ARGS_void_GLuint_GLenum_GLuint_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLbyte: {
            PACKED_void_GLuint_GLbyte *unpacked = (PACKED_void_GLuint_GLbyte *)packed;
            ARGS_void_GLuint_GLbyte args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLdouble: {
            PACKED_void_GLuint_GLdouble *unpacked = (PACKED_void_GLuint_GLdouble *)packed;
            ARGS_void_GLuint_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLshort: {
            PACKED_void_GLuint_GLshort *unpacked = (PACKED_void_GLuint_GLshort *)packed;
            ARGS_void_GLuint_GLshort args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLushort: {
            PACKED_void_GLuint_GLushort *unpacked = (PACKED_void_GLuint_GLushort *)packed;
            ARGS_void_GLuint_GLushort args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLuint_GLintptr_GLsizei: {
            PACKED_void_GLuint_GLuint_GLuint_GLintptr_GLsizei *unpacked = (PACKED_void_GLuint_GLuint_GLuint_GLintptr_GLsizei *)packed;
            ARGS_void_GLuint_GLuint_GLuint_GLintptr_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLint_GLenum_GLsizei_GLintptr: {
            PACKED_void_GLuint_GLuint_GLint_GLenum_GLsizei_GLintptr *unpacked = (PACKED_void_GLuint_GLuint_GLint_GLenum_GLsizei_GLintptr *)packed;
            ARGS_void_GLuint_GLuint_GLint_GLenum_GLsizei_GLintptr args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLsizei_GLintptr: {
            PACKED_void_GLuint_GLuint_GLsizei_GLintptr *unpacked = (PACKED_void_GLuint_GLuint_GLsizei_GLintptr *)packed;
            ARGS_void_GLuint_GLuint_GLsizei_GLintptr args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLenum_GLsizei_GLintptr: {
            PACKED_void_GLuint_GLuint_GLenum_GLsizei_GLintptr *unpacked = (PACKED_void_GLuint_GLuint_GLenum_GLsizei_GLintptr *)packed;
            ARGS_void_GLuint_GLuint_GLenum_GLsizei_GLintptr args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLenum_GLint_GLenum_GLsizei_GLintptr: {
            PACKED_void_GLuint_GLuint_GLenum_GLint_GLenum_GLsizei_GLintptr *unpacked = (PACKED_void_GLuint_GLuint_GLenum_GLint_GLenum_GLsizei_GLintptr *)packed;
            ARGS_void_GLuint_GLuint_GLenum_GLint_GLenum_GLsizei_GLintptr args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLint_GLenum_GLboolean_GLuint: {
            PACKED_void_GLuint_GLuint_GLint_GLenum_GLboolean_GLuint *unpacked = (PACKED_void_GLuint_GLuint_GLint_GLenum_GLboolean_GLuint *)packed;
            ARGS_void_GLuint_GLuint_GLint_GLenum_GLboolean_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLint_GLenum_GLuint: {
            PACKED_void_GLuint_GLuint_GLint_GLenum_GLuint *unpacked = (PACKED_void_GLuint_GLuint_GLint_GLenum_GLuint *)packed;
            ARGS_void_GLuint_GLuint_GLint_GLenum_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLuint_GLint_GLenum_GLsizei_GLintptr: {
            PACKED_void_GLuint_GLuint_GLuint_GLint_GLenum_GLsizei_GLintptr *unpacked = (PACKED_void_GLuint_GLuint_GLuint_GLint_GLenum_GLsizei_GLintptr *)packed;
            ARGS_void_GLuint_GLuint_GLuint_GLint_GLenum_GLsizei_GLintptr args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLuint_GLint_GLenum_GLboolean_GLsizei_GLintptr: {
            PACKED_void_GLuint_GLuint_GLuint_GLint_GLenum_GLboolean_GLsizei_GLintptr *unpacked = (PACKED_void_GLuint_GLuint_GLuint_GLint_GLenum_GLboolean_GLsizei_GLintptr *)packed;
            ARGS_void_GLuint_GLuint_GLuint_GLint_GLenum_GLboolean_GLsizei_GLintptr args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLuint_GLhalfNV: {
            PACKED_void_GLuint_GLhalfNV *unpacked = (PACKED_void_GLuint_GLhalfNV *)packed;
            ARGS_void_GLuint_GLhalfNV args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLhalfNV_GLhalfNV: {
            PACKED_void_GLuint_GLhalfNV_GLhalfNV *unpacked = (PACKED_void_GLuint_GLhalfNV_GLhalfNV *)packed;
            ARGS_void_GLuint_GLhalfNV_GLhalfNV args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLshort_GLshort: {
            PACKED_void_GLuint_GLshort_GLshort *unpacked = (PACKED_void_GLuint_GLshort_GLshort *)packed;
            ARGS_void_GLuint_GLshort_GLshort args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLdouble_GLdouble_GLdouble: {
            PACKED_void_GLuint_GLdouble_GLdouble_GLdouble *unpacked = (PACKED_void_GLuint_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLuint_GLdouble_GLdouble_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLhalfNV_GLhalfNV_GLhalfNV: {
            PACKED_void_GLuint_GLhalfNV_GLhalfNV_GLhalfNV *unpacked = (PACKED_void_GLuint_GLhalfNV_GLhalfNV_GLhalfNV *)packed;
            ARGS_void_GLuint_GLhalfNV_GLhalfNV_GLhalfNV args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLshort_GLshort_GLshort: {
            PACKED_void_GLuint_GLshort_GLshort_GLshort *unpacked = (PACKED_void_GLuint_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLuint_GLshort_GLshort_GLshort args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLubyte_GLubyte_GLubyte_GLubyte: {
            PACKED_void_GLuint_GLubyte_GLubyte_GLubyte_GLubyte *unpacked = (PACKED_void_GLuint_GLubyte_GLubyte_GLubyte_GLubyte *)packed;
            ARGS_void_GLuint_GLubyte_GLubyte_GLubyte_GLubyte args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLdouble_GLdouble_GLdouble_GLdouble: {
            PACKED_void_GLuint_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (PACKED_void_GLuint_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLuint_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV: {
            PACKED_void_GLuint_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV *unpacked = (PACKED_void_GLuint_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV *)packed;
            ARGS_void_GLuint_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLshort_GLshort_GLshort_GLshort: {
            PACKED_void_GLuint_GLshort_GLshort_GLshort_GLshort *unpacked = (PACKED_void_GLuint_GLshort_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLuint_GLshort_GLshort_GLshort_GLshort args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLenum_GLboolean_GLsizei_GLuint_GLuint: {
            PACKED_void_GLuint_GLint_GLenum_GLboolean_GLsizei_GLuint_GLuint *unpacked = (PACKED_void_GLuint_GLint_GLenum_GLboolean_GLsizei_GLuint_GLuint *)packed;
            ARGS_void_GLuint_GLint_GLenum_GLboolean_GLsizei_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLenum_GLboolean_GLuint: {
            PACKED_void_GLuint_GLint_GLenum_GLboolean_GLuint *unpacked = (PACKED_void_GLuint_GLint_GLenum_GLboolean_GLuint *)packed;
            ARGS_void_GLuint_GLint_GLenum_GLboolean_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLenum_GLboolean_GLsizei: {
            PACKED_void_GLuint_GLint_GLenum_GLboolean_GLsizei *unpacked = (PACKED_void_GLuint_GLint_GLenum_GLboolean_GLsizei *)packed;
            ARGS_void_GLuint_GLint_GLenum_GLboolean_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLuint_GLuint_GLuint: {
            PACKED_void_GLuint_GLuint_GLuint_GLuint_GLuint *unpacked = (PACKED_void_GLuint_GLuint_GLuint_GLuint_GLuint *)packed;
            ARGS_void_GLuint_GLuint_GLuint_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLenum_GLuint: {
            PACKED_void_GLuint_GLint_GLenum_GLuint *unpacked = (PACKED_void_GLuint_GLint_GLenum_GLuint *)packed;
            ARGS_void_GLuint_GLint_GLenum_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLenum_GLsizei: {
            PACKED_void_GLuint_GLint_GLenum_GLsizei *unpacked = (PACKED_void_GLuint_GLint_GLenum_GLsizei *)packed;
            ARGS_void_GLuint_GLint_GLenum_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLenum_GLsizei_GLvoid: {
            PACKED_void_GLuint_GLint_GLenum_GLsizei_GLvoid *unpacked = (PACKED_void_GLuint_GLint_GLenum_GLsizei_GLvoid *)packed;
            ARGS_void_GLuint_GLint_GLenum_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLint64EXT: {
            PACKED_void_GLuint_GLint64EXT *unpacked = (PACKED_void_GLuint_GLint64EXT *)packed;
            ARGS_void_GLuint_GLint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLuint64EXT: {
            PACKED_void_GLuint_GLuint64EXT *unpacked = (PACKED_void_GLuint_GLuint64EXT *)packed;
            ARGS_void_GLuint_GLuint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLint64EXT_GLint64EXT: {
            PACKED_void_GLuint_GLint64EXT_GLint64EXT *unpacked = (PACKED_void_GLuint_GLint64EXT_GLint64EXT *)packed;
            ARGS_void_GLuint_GLint64EXT_GLint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLuint64EXT_GLuint64EXT: {
            PACKED_void_GLuint_GLuint64EXT_GLuint64EXT *unpacked = (PACKED_void_GLuint_GLuint64EXT_GLuint64EXT *)packed;
            ARGS_void_GLuint_GLuint64EXT_GLuint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLint64EXT_GLint64EXT_GLint64EXT: {
            PACKED_void_GLuint_GLint64EXT_GLint64EXT_GLint64EXT *unpacked = (PACKED_void_GLuint_GLint64EXT_GLint64EXT_GLint64EXT *)packed;
            ARGS_void_GLuint_GLint64EXT_GLint64EXT_GLint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLuint64EXT_GLuint64EXT_GLuint64EXT: {
            PACKED_void_GLuint_GLuint64EXT_GLuint64EXT_GLuint64EXT *unpacked = (PACKED_void_GLuint_GLuint64EXT_GLuint64EXT_GLuint64EXT *)packed;
            ARGS_void_GLuint_GLuint64EXT_GLuint64EXT_GLuint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT: {
            PACKED_void_GLuint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT *unpacked = (PACKED_void_GLuint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT *)packed;
            ARGS_void_GLuint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT: {
            PACKED_void_GLuint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT *unpacked = (PACKED_void_GLuint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT *)packed;
            ARGS_void_GLuint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLboolean_GLuint: {
            PACKED_void_GLuint_GLenum_GLboolean_GLuint *unpacked = (PACKED_void_GLuint_GLenum_GLboolean_GLuint *)packed;
            ARGS_void_GLuint_GLenum_GLboolean_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLenum_GLboolean_GLsizei_GLvoid: {
            PACKED_void_GLuint_GLint_GLenum_GLboolean_GLsizei_GLvoid *unpacked = (PACKED_void_GLuint_GLint_GLenum_GLboolean_GLsizei_GLvoid *)packed;
            ARGS_void_GLuint_GLint_GLenum_GLboolean_GLsizei_GLvoid args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLhalfNV: {
            PACKED_void_GLuint_GLsizei_GLhalfNV *unpacked = (PACKED_void_GLuint_GLsizei_GLhalfNV *)packed;
            ARGS_void_GLuint_GLsizei_GLhalfNV args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLshort: {
            PACKED_void_GLuint_GLsizei_GLshort *unpacked = (PACKED_void_GLuint_GLsizei_GLshort *)packed;
            ARGS_void_GLuint_GLsizei_GLshort args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLubyte: {
            PACKED_void_GLuint_GLsizei_GLubyte *unpacked = (PACKED_void_GLuint_GLsizei_GLubyte *)packed;
            ARGS_void_GLuint_GLsizei_GLubyte args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_GLenum_GLuint_GLuint_GLuint64EXT: {
            PACKED_GLenum_GLuint_GLuint_GLuint64EXT *unpacked = (PACKED_GLenum_GLuint_GLuint_GLuint64EXT *)packed;
            ARGS_GLenum_GLuint_GLuint_GLuint64EXT args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLsync_GLbitfield_GLuint64: {
            PACKED_void_GLsync_GLbitfield_GLuint64 *unpacked = (PACKED_void_GLsync_GLbitfield_GLuint64 *)packed;
            ARGS_void_GLsync_GLbitfield_GLuint64 args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLuint_GLfloat: {
            PACKED_void_GLuint_GLsizei_GLuint_GLfloat *unpacked = (PACKED_void_GLuint_GLsizei_GLuint_GLfloat *)packed;
            ARGS_void_GLuint_GLsizei_GLuint_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLint_GLbyte: {
            PACKED_void_GLint_GLbyte *unpacked = (PACKED_void_GLint_GLbyte *)packed;
            ARGS_void_GLint_GLbyte args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLint_GLshort: {
            PACKED_void_GLint_GLshort *unpacked = (PACKED_void_GLint_GLshort *)packed;
            ARGS_void_GLint_GLshort args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_Bool_Display_GLXPbufferSGIX_DMparams_DMbuffer: {
            PACKED_Bool_Display_GLXPbufferSGIX_DMparams_DMbuffer *unpacked = (PACKED_Bool_Display_GLXPbufferSGIX_DMparams_DMbuffer *)packed;
            ARGS_Bool_Display_GLXPbufferSGIX_DMparams_DMbuffer args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_int_Display_int_int_Window: {
            PACKED_int_Display_int_int_Window *unpacked = (PACKED_int_Display_int_int_Window *)packed;
            ARGS_int_Display_int_int_Window args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_int_Display_int: {
            PACKED_int_Display_int *unpacked = (PACKED_int_Display_int *)packed;
            ARGS_int_Display_int args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_Bool_Display_GLuint_GLuint: {
            PACKED_Bool_Display_GLuint_GLuint *unpacked = (PACKED_Bool_Display_GLuint_GLuint *)packed;
            ARGS_Bool_Display_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_Display_GLXDrawable_int: {
            PACKED_void_Display_GLXDrawable_int *unpacked = (PACKED_void_Display_GLXDrawable_int *)packed;
            ARGS_void_Display_GLXDrawable_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_Display_GLXDrawable_int_int: {
            PACKED_void_Display_GLXDrawable_int_int *unpacked = (PACKED_void_Display_GLXDrawable_int_int *)packed;
            ARGS_void_Display_GLXDrawable_int_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_int_Display_unsigned_int_GLXVideoCaptureDeviceNV: {
            PACKED_int_Display_unsigned_int_GLXVideoCaptureDeviceNV *unpacked = (PACKED_int_Display_unsigned_int_GLXVideoCaptureDeviceNV *)packed;
            ARGS_int_Display_unsigned_int_GLXVideoCaptureDeviceNV args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_int_Display_unsigned_int_unsigned_int_int: {
            PACKED_int_Display_unsigned_int_unsigned_int_int *unpacked = (PACKED_int_Display_unsigned_int_unsigned_int_int *)packed;
            ARGS_int_Display_unsigned_int_unsigned_int_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_int_Display_GLXVideoDeviceNV_GLXPbuffer_int: {
            PACKED_int_Display_GLXVideoDeviceNV_GLXPbuffer_int *unpacked = (PACKED_int_Display_GLXVideoDeviceNV_GLXPbuffer_int *)packed;
            ARGS_int_Display_GLXVideoDeviceNV_GLXPbuffer_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_int_Display_int_int_int_int_int_int: {
            PACKED_int_Display_int_int_int_int_int_int *unpacked = (PACKED_int_Display_int_int_int_int_int_int *)packed;
            ARGS_int_Display_int_int_int_int_int_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_int_Display_int_int_GLenum: {
            PACKED_int_Display_int_int_GLenum *unpacked = (PACKED_int_Display_int_int_GLenum *)packed;
            ARGS_int_Display_int_int_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_GLXFBConfigPointer_Display_int_int_int: {
            PACKED_GLXFBConfigPointer_Display_int_int_int *unpacked = (PACKED_GLXFBConfigPointer_Display_int_int_int *)packed;
            ARGS_GLXFBConfigPointer_Display_int_int_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_GLXFBConfigSGIXPointer_Display_int_int_int: {
            PACKED_GLXFBConfigSGIXPointer_Display_int_int_int *unpacked = (PACKED_GLXFBConfigSGIXPointer_Display_int_int_int *)packed;
            ARGS_GLXFBConfigSGIXPointer_Display_int_int_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_Display_GLXContext_GLuint_GLenum_GLint_GLint_GLint_GLint_GLXContext_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei: {
            PACKED_void_Display_GLXContext_GLuint_GLenum_GLint_GLint_GLint_GLint_GLXContext_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei *unpacked = (PACKED_void_Display_GLXContext_GLuint_GLenum_GLint_GLint_GLint_GLint_GLXContext_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei *)packed;
            ARGS_void_Display_GLXContext_GLuint_GLenum_GLint_GLint_GLint_GLint_GLXContext_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11, args.a12, args.a13, args.a14, args.a15, args.a16, args.a17, args.a18);
            break;
        }
        case FORMAT_void_Display_GLXDrawable_int_int_int_int: {
            PACKED_void_Display_GLXDrawable_int_int_int_int *unpacked = (PACKED_void_Display_GLXDrawable_int_int_int_int *)packed;
            ARGS_void_Display_GLXDrawable_int_int_int_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_GLXContext_Display_GLXFBConfig_GLXContext_Bool_int: {
            PACKED_GLXContext_Display_GLXFBConfig_GLXContext_Bool_int *unpacked = (PACKED_GLXContext_Display_GLXFBConfig_GLXContext_Bool_int *)packed;
            ARGS_GLXContext_Display_GLXFBConfig_GLXContext_Bool_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_GLXContext_Display_GLXFBConfigSGIX_int_GLXContext_Bool: {
            PACKED_GLXContext_Display_GLXFBConfigSGIX_int_GLXContext_Bool *unpacked = (PACKED_GLXContext_Display_GLXFBConfigSGIX_int_GLXContext_Bool *)packed;
            ARGS_GLXContext_Display_GLXFBConfigSGIX_int_GLXContext_Bool args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_GLXPbufferSGIX_Display_GLXFBConfigSGIX_unsigned_int_unsigned_int_int: {
            PACKED_GLXPbufferSGIX_Display_GLXFBConfigSGIX_unsigned_int_unsigned_int_int *unpacked = (PACKED_GLXPbufferSGIX_Display_GLXFBConfigSGIX_unsigned_int_unsigned_int_int *)packed;
            ARGS_GLXPbufferSGIX_Display_GLXFBConfigSGIX_unsigned_int_unsigned_int_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_GLXPixmap_Display_XVisualInfo_Pixmap_Colormap: {
            PACKED_GLXPixmap_Display_XVisualInfo_Pixmap_Colormap *unpacked = (PACKED_GLXPixmap_Display_XVisualInfo_Pixmap_Colormap *)packed;
            ARGS_GLXPixmap_Display_XVisualInfo_Pixmap_Colormap args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_GLXPixmap_Display_GLXFBConfigSGIX_Pixmap: {
            PACKED_GLXPixmap_Display_GLXFBConfigSGIX_Pixmap *unpacked = (PACKED_GLXPixmap_Display_GLXFBConfigSGIX_Pixmap *)packed;
            ARGS_GLXPixmap_Display_GLXFBConfigSGIX_Pixmap args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_GLXVideoSourceSGIX_Display_int_VLServer_VLPath_int_VLNode: {
            PACKED_GLXVideoSourceSGIX_Display_int_VLServer_VLPath_int_VLNode *unpacked = (PACKED_GLXVideoSourceSGIX_Display_int_VLServer_VLPath_int_VLNode *)packed;
            ARGS_GLXVideoSourceSGIX_Display_int_VLServer_VLPath_int_VLNode args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_GLXContext_Display_GLXFBConfig_int_GLXContext_Bool: {
            PACKED_GLXContext_Display_GLXFBConfig_int_GLXContext_Bool *unpacked = (PACKED_GLXContext_Display_GLXFBConfig_int_GLXContext_Bool *)packed;
            ARGS_GLXContext_Display_GLXFBConfig_int_GLXContext_Bool args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_GLXPbuffer_Display_GLXFBConfig_int: {
            PACKED_GLXPbuffer_Display_GLXFBConfig_int *unpacked = (PACKED_GLXPbuffer_Display_GLXFBConfig_int *)packed;
            ARGS_GLXPbuffer_Display_GLXFBConfig_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_GLXPixmap_Display_GLXFBConfig_Pixmap_int: {
            PACKED_GLXPixmap_Display_GLXFBConfig_Pixmap_int *unpacked = (PACKED_GLXPixmap_Display_GLXFBConfig_Pixmap_int *)packed;
            ARGS_GLXPixmap_Display_GLXFBConfig_Pixmap_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_GLXWindow_Display_GLXFBConfig_Window_int: {
            PACKED_GLXWindow_Display_GLXFBConfig_Window_int *unpacked = (PACKED_GLXWindow_Display_GLXFBConfig_Window_int *)packed;
            ARGS_GLXWindow_Display_GLXFBConfig_Window_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_Display_Window_float: {
            PACKED_void_Display_Window_float *unpacked = (PACKED_void_Display_Window_float *)packed;
            ARGS_void_Display_Window_float args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_Display_GLXPbufferSGIX: {
            PACKED_void_Display_GLXPbufferSGIX *unpacked = (PACKED_void_Display_GLXPbufferSGIX *)packed;
            ARGS_void_Display_GLXPbufferSGIX args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_Display_GLXVideoSourceSGIX: {
            PACKED_void_Display_GLXVideoSourceSGIX *unpacked = (PACKED_void_Display_GLXVideoSourceSGIX *)packed;
            ARGS_void_Display_GLXVideoSourceSGIX args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_Display_GLXPbuffer: {
            PACKED_void_Display_GLXPbuffer *unpacked = (PACKED_void_Display_GLXPbuffer *)packed;
            ARGS_void_Display_GLXPbuffer args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_Display_GLXPixmap: {
            PACKED_void_Display_GLXPixmap *unpacked = (PACKED_void_Display_GLXPixmap *)packed;
            ARGS_void_Display_GLXPixmap args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_Display_GLXWindow: {
            PACKED_void_Display_GLXWindow *unpacked = (PACKED_void_Display_GLXWindow *)packed;
            ARGS_void_Display_GLXWindow args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_GLXVideoCaptureDeviceNVPointer_Display_int_int: {
            PACKED_GLXVideoCaptureDeviceNVPointer_Display_int_int *unpacked = (PACKED_GLXVideoCaptureDeviceNVPointer_Display_int_int *)packed;
            ARGS_GLXVideoCaptureDeviceNVPointer_Display_int_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_uintPointer_Display_int_int: {
            PACKED_uintPointer_Display_int_int *unpacked = (PACKED_uintPointer_Display_int_int *)packed;
            ARGS_uintPointer_Display_int_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_Display_GLXContext: {
            PACKED_void_Display_GLXContext *unpacked = (PACKED_void_Display_GLXContext *)packed;
            ARGS_void_Display_GLXContext args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_uint_void: {
            PACKED_uint_void *unpacked = (PACKED_uint_void *)packed;
            ARGS_uint_void args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_GLXContextID_const_GLXContext: {
            PACKED_GLXContextID_const_GLXContext *unpacked = (PACKED_GLXContextID_const_GLXContext *)packed;
            ARGS_GLXContextID_const_GLXContext args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_DisplayPointer: {
            PACKED_DisplayPointer *unpacked = (PACKED_DisplayPointer *)packed;
            ARGS_DisplayPointer args = unpacked->args;
            unpacked->func();
            break;
        }
        case FORMAT_GLXDrawable: {
            PACKED_GLXDrawable *unpacked = (PACKED_GLXDrawable *)packed;
            ARGS_GLXDrawable args = unpacked->args;
            unpacked->func();
            break;
        }
        case FORMAT_int_Display_GLXFBConfig_int_int: {
            PACKED_int_Display_GLXFBConfig_int_int *unpacked = (PACKED_int_Display_GLXFBConfig_int_int *)packed;
            ARGS_int_Display_GLXFBConfig_int_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_int_Display_GLXFBConfigSGIX_int_int: {
            PACKED_int_Display_GLXFBConfigSGIX_int_int *unpacked = (PACKED_int_Display_GLXFBConfigSGIX_int_int *)packed;
            ARGS_int_Display_GLXFBConfigSGIX_int_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_GLXFBConfigSGIX_Display_XVisualInfo: {
            PACKED_GLXFBConfigSGIX_Display_XVisualInfo *unpacked = (PACKED_GLXFBConfigSGIX_Display_XVisualInfo *)packed;
            ARGS_GLXFBConfigSGIX_Display_XVisualInfo args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_GLXFBConfigPointer_Display_int_int: {
            PACKED_GLXFBConfigPointer_Display_int_int *unpacked = (PACKED_GLXFBConfigPointer_Display_int_int *)packed;
            ARGS_GLXFBConfigPointer_Display_int_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_Bool_Display_GLXDrawable_int32_t_int32_t: {
            PACKED_Bool_Display_GLXDrawable_int32_t_int32_t *unpacked = (PACKED_Bool_Display_GLXDrawable_int32_t_int32_t *)packed;
            ARGS_Bool_Display_GLXDrawable_int32_t_int32_t args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_FunctionPointer_GLubyte: {
            PACKED_FunctionPointer_GLubyte *unpacked = (PACKED_FunctionPointer_GLubyte *)packed;
            ARGS_FunctionPointer_GLubyte args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_Display_GLXDrawable_unsigned_long: {
            PACKED_void_Display_GLXDrawable_unsigned_long *unpacked = (PACKED_void_Display_GLXDrawable_unsigned_long *)packed;
            ARGS_void_Display_GLXDrawable_unsigned_long args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t: {
            PACKED_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t *unpacked = (PACKED_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t *)packed;
            ARGS_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_Status_Display_Window_Window_long: {
            PACKED_Status_Display_Window_Window_long *unpacked = (PACKED_Status_Display_Window_Window_long *)packed;
            ARGS_Status_Display_Window_Window_long args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_int_Display_int_int_GLXVideoDeviceNV: {
            PACKED_int_Display_int_int_GLXVideoDeviceNV *unpacked = (PACKED_int_Display_int_int_GLXVideoDeviceNV *)packed;
            ARGS_int_Display_int_int_GLXVideoDeviceNV args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_int_Display_int_GLXVideoDeviceNV_unsigned_long_unsigned_long: {
            PACKED_int_Display_int_GLXVideoDeviceNV_unsigned_long_unsigned_long *unpacked = (PACKED_int_Display_int_GLXVideoDeviceNV_unsigned_long_unsigned_long *)packed;
            ARGS_int_Display_int_GLXVideoDeviceNV_unsigned_long_unsigned_long args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_int_unsigned_int: {
            PACKED_int_unsigned_int *unpacked = (PACKED_int_unsigned_int *)packed;
            ARGS_int_unsigned_int args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_XVisualInfoPointer_Display_GLXFBConfig: {
            PACKED_XVisualInfoPointer_Display_GLXFBConfig *unpacked = (PACKED_XVisualInfoPointer_Display_GLXFBConfig *)packed;
            ARGS_XVisualInfoPointer_Display_GLXFBConfig args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_XVisualInfoPointer_Display_GLXFBConfigSGIX: {
            PACKED_XVisualInfoPointer_Display_GLXFBConfigSGIX *unpacked = (PACKED_XVisualInfoPointer_Display_GLXFBConfigSGIX *)packed;
            ARGS_XVisualInfoPointer_Display_GLXFBConfigSGIX args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_int_Display_int_int_int_void: {
            PACKED_int_Display_int_int_int_void *unpacked = (PACKED_int_Display_int_int_int_void *)packed;
            ARGS_int_Display_int_int_int_void args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_int_Display_int_int_GLXHyperpipeConfigSGIX_int: {
            PACKED_int_Display_int_int_GLXHyperpipeConfigSGIX_int *unpacked = (PACKED_int_Display_int_int_GLXHyperpipeConfigSGIX_int *)packed;
            ARGS_int_Display_int_int_GLXHyperpipeConfigSGIX_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_GLXContext_Display_GLXContextID: {
            PACKED_GLXContext_Display_GLXContextID *unpacked = (PACKED_GLXContext_Display_GLXContextID *)packed;
            ARGS_GLXContext_Display_GLXContextID args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_Bool_Display_GLXDrawable_GLuint: {
            PACKED_Bool_Display_GLXDrawable_GLuint *unpacked = (PACKED_Bool_Display_GLXDrawable_GLuint *)packed;
            ARGS_Bool_Display_GLXDrawable_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_Display_GLXDrawable_GLXDrawable: {
            PACKED_void_Display_GLXDrawable_GLXDrawable *unpacked = (PACKED_void_Display_GLXDrawable_GLXDrawable *)packed;
            ARGS_void_Display_GLXDrawable_GLXDrawable args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_Display_GLXVideoCaptureDeviceNV: {
            PACKED_void_Display_GLXVideoCaptureDeviceNV *unpacked = (PACKED_void_Display_GLXVideoCaptureDeviceNV *)packed;
            ARGS_void_Display_GLXVideoCaptureDeviceNV args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_Bool_Display_GLXDrawable_GLXDrawable_GLXContext: {
            PACKED_Bool_Display_GLXDrawable_GLXDrawable_GLXContext *unpacked = (PACKED_Bool_Display_GLXDrawable_GLXDrawable_GLXContext *)packed;
            ARGS_Bool_Display_GLXDrawable_GLXDrawable_GLXContext args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_int_Display_GLXContext_int_int: {
            PACKED_int_Display_GLXContext_int_int *unpacked = (PACKED_int_Display_GLXContext_int_int *)packed;
            ARGS_int_Display_GLXContext_int_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_Display_GLXDrawable_int_unsigned_int: {
            PACKED_void_Display_GLXDrawable_int_unsigned_int *unpacked = (PACKED_void_Display_GLXDrawable_int_unsigned_int *)packed;
            ARGS_void_Display_GLXDrawable_int_unsigned_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_Bool_Display_int_GLuint: {
            PACKED_Bool_Display_int_GLuint *unpacked = (PACKED_Bool_Display_int_GLuint *)packed;
            ARGS_Bool_Display_int_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_int_Display_GLXPbufferSGIX_int_unsigned_int: {
            PACKED_int_Display_GLXPbufferSGIX_int_unsigned_int *unpacked = (PACKED_int_Display_GLXPbufferSGIX_int_unsigned_int *)packed;
            ARGS_int_Display_GLXPbufferSGIX_int_unsigned_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_int_Display_int_int_int_void_void: {
            PACKED_int_Display_int_int_int_void_void *unpacked = (PACKED_int_Display_int_int_int_void_void *)packed;
            ARGS_int_Display_int_int_int_void_void args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_GLXHyperpipeConfigSGIXPointer_Display_int_int: {
            PACKED_GLXHyperpipeConfigSGIXPointer_Display_int_int *unpacked = (PACKED_GLXHyperpipeConfigSGIXPointer_Display_int_int *)packed;
            ARGS_GLXHyperpipeConfigSGIXPointer_Display_int_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_GLXHyperpipeNetworkSGIXPointer_Display_int: {
            PACKED_GLXHyperpipeNetworkSGIXPointer_Display_int *unpacked = (PACKED_GLXHyperpipeNetworkSGIXPointer_Display_int *)packed;
            ARGS_GLXHyperpipeNetworkSGIXPointer_Display_int args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_Bool_Display_int_int: {
            PACKED_Bool_Display_int_int *unpacked = (PACKED_Bool_Display_int_int *)packed;
            ARGS_Bool_Display_int_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_Bool_Display_int_GLuint_GLuint: {
            PACKED_Bool_Display_int_GLuint_GLuint *unpacked = (PACKED_Bool_Display_int_GLuint_GLuint *)packed;
            ARGS_Bool_Display_int_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_Bool_Display_GLXDrawable_GLuint_GLuint: {
            PACKED_Bool_Display_GLXDrawable_GLuint_GLuint *unpacked = (PACKED_Bool_Display_GLXDrawable_GLuint_GLuint *)packed;
            ARGS_Bool_Display_GLXDrawable_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_int_Display_GLXVideoCaptureDeviceNV_int_int: {
            PACKED_int_Display_GLXVideoCaptureDeviceNV_int_int *unpacked = (PACKED_int_Display_GLXVideoCaptureDeviceNV_int_int *)packed;
            ARGS_int_Display_GLXVideoCaptureDeviceNV_int_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_Bool_Display_GLXDrawable: {
            PACKED_Bool_Display_GLXDrawable *unpacked = (PACKED_Bool_Display_GLXDrawable *)packed;
            ARGS_Bool_Display_GLXDrawable args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_int_Display_int_GLXVideoDeviceNV: {
            PACKED_int_Display_int_GLXVideoDeviceNV *unpacked = (PACKED_int_Display_int_GLXVideoDeviceNV *)packed;
            ARGS_int_Display_int_GLXVideoDeviceNV args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_int_Display_GLXPbuffer: {
            PACKED_int_Display_GLXPbuffer *unpacked = (PACKED_int_Display_GLXPbuffer *)packed;
            ARGS_int_Display_GLXPbuffer args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_Bool_Display_int: {
            PACKED_Bool_Display_int *unpacked = (PACKED_Bool_Display_int *)packed;
            ARGS_Bool_Display_int args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_int_Display_GLXPbuffer_int_unsigned_long_GLboolean: {
            PACKED_int_Display_GLXPbuffer_int_unsigned_long_GLboolean *unpacked = (PACKED_int_Display_GLXPbuffer_int_unsigned_long_GLboolean *)packed;
            ARGS_int_Display_GLXPbuffer_int_unsigned_long_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_Bool_int: {
            PACKED_Bool_int *unpacked = (PACKED_Bool_int *)packed;
            ARGS_Bool_int args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_int64_t_Display_GLXDrawable_int64_t_int64_t_int64_t: {
            PACKED_int64_t_Display_GLXDrawable_int64_t_int64_t_int64_t *unpacked = (PACKED_int64_t_Display_GLXDrawable_int64_t_int64_t_int64_t *)packed;
            ARGS_int64_t_Display_GLXDrawable_int64_t_int64_t_int64_t args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_int_int: {
            PACKED_int_int *unpacked = (PACKED_int_int *)packed;
            ARGS_int_int args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t_int64_t_int64_t_int64_t: {
            PACKED_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t_int64_t_int64_t_int64_t *unpacked = (PACKED_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t_int64_t_int64_t_int64_t *)packed;
            ARGS_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t_int64_t_int64_t_int64_t args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t_int64_t: {
            PACKED_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t_int64_t *unpacked = (PACKED_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t_int64_t *)packed;
            ARGS_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t_int64_t args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_int_int_int_unsigned_int: {
            PACKED_int_int_int_unsigned_int *unpacked = (PACKED_int_int_int_unsigned_int *)packed;
            ARGS_int_int_int_unsigned_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
    }
}
#ifndef skip_glAccum
void glAccum(GLenum op, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glAccumxOES
void glAccumxOES(GLenum op, GLfixed value) {
printf(gl.c);
}
#endif
#ifndef skip_glActiveProgramEXT
void glActiveProgramEXT(GLuint program) {
printf(gl.c);
}
#endif
#ifndef skip_glActiveShaderProgram
void glActiveShaderProgram(GLuint pipeline, GLuint program) {
printf(gl.c);
}
#endif
#ifndef skip_glActiveStencilFaceEXT
void glActiveStencilFaceEXT(GLenum face) {
printf(gl.c);
}
#endif
#ifndef skip_glActiveTexture
void glActiveTexture(GLenum texture) {
printf(gl.c);
}
#endif
#ifndef skip_glActiveTextureARB
void glActiveTextureARB(GLenum texture) {
printf(gl.c);
}
#endif
#ifndef skip_glActiveVaryingNV
void glActiveVaryingNV(GLuint program, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glAlphaFragmentOp1ATI
void glAlphaFragmentOp1ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod) {
printf(gl.c);
}
#endif
#ifndef skip_glAlphaFragmentOp2ATI
void glAlphaFragmentOp2ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod) {
printf(gl.c);
}
#endif
#ifndef skip_glAlphaFragmentOp3ATI
void glAlphaFragmentOp3ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod) {
printf(gl.c);
}
#endif
#ifndef skip_glAlphaFunc
void glAlphaFunc(GLenum func, GLfloat ref) {
printf(gl.c);
}
#endif
#ifndef skip_glAlphaFuncxOES
void glAlphaFuncxOES(GLenum func, GLfixed ref) {
printf(gl.c);
}
#endif
#ifndef skip_glApplyTextureEXT
void glApplyTextureEXT(GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glAreProgramsResidentNV
Boolean glAreProgramsResidentNV(GLsizei n, GLuint programs, GLboolean residences) {
printf(gl.c);
}
#endif
#ifndef skip_glAreTexturesResident
Boolean glAreTexturesResident(GLsizei n, GLuint textures, GLboolean residences) {
printf(gl.c);
}
#endif
#ifndef skip_glAreTexturesResidentEXT
Boolean glAreTexturesResidentEXT(GLsizei n, GLuint textures, GLboolean residences) {
printf(gl.c);
}
#endif
#ifndef skip_glArrayElement
void glArrayElement(GLint i) {
printf(gl.c);
}
#endif
#ifndef skip_glArrayElementEXT
void glArrayElementEXT(GLint i) {
printf(gl.c);
}
#endif
#ifndef skip_glArrayObjectATI
void glArrayObjectATI(GLenum array, GLint size, GLenum type, GLsizei stride, GLuint buffer, GLuint offset) {
printf(gl.c);
}
#endif
#ifndef skip_glAsyncMarkerSGIX
void glAsyncMarkerSGIX(GLuint marker) {
printf(gl.c);
}
#endif
#ifndef skip_glAttachObjectARB
void glAttachObjectARB(GLhandleARB containerObj, GLhandleARB obj) {
printf(gl.c);
}
#endif
#ifndef skip_glAttachShader
void glAttachShader(GLuint program, GLuint shader) {
printf(gl.c);
}
#endif
#ifndef skip_glBegin
void glBegin(GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glBeginConditionalRender
void glBeginConditionalRender(GLuint id, GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glBeginConditionalRenderNV
void glBeginConditionalRenderNV(GLuint id, GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glBeginConditionalRenderNVX
void glBeginConditionalRenderNVX(GLuint id) {
printf(gl.c);
}
#endif
#ifndef skip_glBeginFragmentShaderATI
void glBeginFragmentShaderATI() {
printf(gl.c);
}
#endif
#ifndef skip_glBeginOcclusionQueryNV
void glBeginOcclusionQueryNV(GLuint id) {
printf(gl.c);
}
#endif
#ifndef skip_glBeginPerfMonitorAMD
void glBeginPerfMonitorAMD(GLuint monitor) {
printf(gl.c);
}
#endif
#ifndef skip_glBeginQuery
void glBeginQuery(GLenum target, GLuint id) {
printf(gl.c);
}
#endif
#ifndef skip_glBeginQueryARB
void glBeginQueryARB(GLenum target, GLuint id) {
printf(gl.c);
}
#endif
#ifndef skip_glBeginQueryIndexed
void glBeginQueryIndexed(GLenum target, GLuint index, GLuint id) {
printf(gl.c);
}
#endif
#ifndef skip_glBeginTransformFeedback
void glBeginTransformFeedback(GLenum primitiveMode) {
printf(gl.c);
}
#endif
#ifndef skip_glBeginTransformFeedbackEXT
void glBeginTransformFeedbackEXT(GLenum primitiveMode) {
printf(gl.c);
}
#endif
#ifndef skip_glBeginTransformFeedbackNV
void glBeginTransformFeedbackNV(GLenum primitiveMode) {
printf(gl.c);
}
#endif
#ifndef skip_glBeginVertexShaderEXT
void glBeginVertexShaderEXT() {
printf(gl.c);
}
#endif
#ifndef skip_glBeginVideoCaptureNV
void glBeginVideoCaptureNV(GLuint video_capture_slot) {
printf(gl.c);
}
#endif
#ifndef skip_glBindAttribLocation
void glBindAttribLocation(GLuint program, GLuint index, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glBindAttribLocationARB
void glBindAttribLocationARB(GLhandleARB programObj, GLuint index, GLcharARB name) {
printf(gl.c);
}
#endif
#ifndef skip_glBindBuffer
void glBindBuffer(GLenum target, GLuint buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glBindBufferARB
void glBindBufferARB(GLenum target, GLuint buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glBindBufferBase
void glBindBufferBase(GLenum target, GLuint index, GLuint buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glBindBufferBaseEXT
void glBindBufferBaseEXT(GLenum target, GLuint index, GLuint buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glBindBufferBaseNV
void glBindBufferBaseNV(GLenum target, GLuint index, GLuint buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glBindBufferOffsetEXT
void glBindBufferOffsetEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset) {
printf(gl.c);
}
#endif
#ifndef skip_glBindBufferOffsetNV
void glBindBufferOffsetNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset) {
printf(gl.c);
}
#endif
#ifndef skip_glBindBufferRange
void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {
printf(gl.c);
}
#endif
#ifndef skip_glBindBufferRangeEXT
void glBindBufferRangeEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {
printf(gl.c);
}
#endif
#ifndef skip_glBindBufferRangeNV
void glBindBufferRangeNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {
printf(gl.c);
}
#endif
#ifndef skip_glBindFragDataLocation
void glBindFragDataLocation(GLuint program, GLuint color, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glBindFragDataLocationEXT
void glBindFragDataLocationEXT(GLuint program, GLuint color, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glBindFragDataLocationIndexed
void glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glBindFragmentShaderATI
void glBindFragmentShaderATI(GLuint id) {
printf(gl.c);
}
#endif
#ifndef skip_glBindFramebuffer
void glBindFramebuffer(GLenum target, GLuint framebuffer) {
printf(gl.c);
}
#endif
#ifndef skip_glBindFramebufferEXT
void glBindFramebufferEXT(GLenum target, GLuint framebuffer) {
printf(gl.c);
}
#endif
#ifndef skip_glBindImageTexture
void glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) {
printf(gl.c);
}
#endif
#ifndef skip_glBindImageTextureEXT
void glBindImageTextureEXT(GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format) {
printf(gl.c);
}
#endif
#ifndef skip_glBindLightParameterEXT
UInt32 glBindLightParameterEXT(GLenum light, GLenum value) {
printf(gl.c);
}
#endif
#ifndef skip_glBindMaterialParameterEXT
UInt32 glBindMaterialParameterEXT(GLenum face, GLenum value) {
printf(gl.c);
}
#endif
#ifndef skip_glBindMultiTextureEXT
void glBindMultiTextureEXT(GLenum texunit, GLenum target, GLuint texture) {
printf(gl.c);
}
#endif
#ifndef skip_glBindParameterEXT
UInt32 glBindParameterEXT(GLenum value) {
printf(gl.c);
}
#endif
#ifndef skip_glBindProgramARB
void glBindProgramARB(GLenum target, GLuint program) {
printf(gl.c);
}
#endif
#ifndef skip_glBindProgramNV
void glBindProgramNV(GLenum target, GLuint id) {
printf(gl.c);
}
#endif
#ifndef skip_glBindProgramPipeline
void glBindProgramPipeline(GLuint pipeline) {
printf(gl.c);
}
#endif
#ifndef skip_glBindRenderbuffer
void glBindRenderbuffer(GLenum target, GLuint renderbuffer) {
printf(gl.c);
}
#endif
#ifndef skip_glBindRenderbufferEXT
void glBindRenderbufferEXT(GLenum target, GLuint renderbuffer) {
printf(gl.c);
}
#endif
#ifndef skip_glBindSampler
void glBindSampler(GLuint unit, GLuint sampler) {
printf(gl.c);
}
#endif
#ifndef skip_glBindTexGenParameterEXT
UInt32 glBindTexGenParameterEXT(GLenum unit, GLenum coord, GLenum value) {
printf(gl.c);
}
#endif
#ifndef skip_glBindTexture
void glBindTexture(GLenum target, GLuint texture) {
printf(gl.c);
}
#endif
#ifndef skip_glBindTextureEXT
void glBindTextureEXT(GLenum target, GLuint texture) {
printf(gl.c);
}
#endif
#ifndef skip_glBindTextureUnitParameterEXT
UInt32 glBindTextureUnitParameterEXT(GLenum unit, GLenum value) {
printf(gl.c);
}
#endif
#ifndef skip_glBindTransformFeedback
void glBindTransformFeedback(GLenum target, GLuint id) {
printf(gl.c);
}
#endif
#ifndef skip_glBindTransformFeedbackNV
void glBindTransformFeedbackNV(GLenum target, GLuint id) {
printf(gl.c);
}
#endif
#ifndef skip_glBindVertexArray
void glBindVertexArray(GLuint array) {
printf(gl.c);
}
#endif
#ifndef skip_glBindVertexArrayAPPLE
void glBindVertexArrayAPPLE(GLuint array) {
printf(gl.c);
}
#endif
#ifndef skip_glBindVertexBuffer
void glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) {
printf(gl.c);
}
#endif
#ifndef skip_glBindVertexShaderEXT
void glBindVertexShaderEXT(GLuint id) {
printf(gl.c);
}
#endif
#ifndef skip_glBindVideoCaptureStreamBufferNV
void glBindVideoCaptureStreamBufferNV(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLintptrARB offset) {
printf(gl.c);
}
#endif
#ifndef skip_glBindVideoCaptureStreamTextureNV
void glBindVideoCaptureStreamTextureNV(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLenum target, GLuint texture) {
printf(gl.c);
}
#endif
#ifndef skip_glBinormal3bEXT
void glBinormal3bEXT(GLbyte bx, GLbyte by, GLbyte bz) {
printf(gl.c);
}
#endif
#ifndef skip_glBinormal3bvEXT
void glBinormal3bvEXT(GLbyte v) {
printf(gl.c);
}
#endif
#ifndef skip_glBinormal3dEXT
void glBinormal3dEXT(GLdouble bx, GLdouble by, GLdouble bz) {
printf(gl.c);
}
#endif
#ifndef skip_glBinormal3dvEXT
void glBinormal3dvEXT(GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glBinormal3fEXT
void glBinormal3fEXT(GLfloat bx, GLfloat by, GLfloat bz) {
printf(gl.c);
}
#endif
#ifndef skip_glBinormal3fvEXT
void glBinormal3fvEXT(GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glBinormal3iEXT
void glBinormal3iEXT(GLint bx, GLint by, GLint bz) {
printf(gl.c);
}
#endif
#ifndef skip_glBinormal3ivEXT
void glBinormal3ivEXT(GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glBinormal3sEXT
void glBinormal3sEXT(GLshort bx, GLshort by, GLshort bz) {
printf(gl.c);
}
#endif
#ifndef skip_glBinormal3svEXT
void glBinormal3svEXT(GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glBinormalPointerEXT
void glBinormalPointerEXT(GLenum type, GLsizei stride, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glBitmap
void glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, GLubyte bitmap) {
printf(gl.c);
}
#endif
#ifndef skip_glBitmapxOES
void glBitmapxOES(GLsizei width, GLsizei height, GLfixed xorig, GLfixed yorig, GLfixed xmove, GLfixed ymove, GLubyte bitmap) {
printf(gl.c);
}
#endif
#ifndef skip_glBlendColor
void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
printf(gl.c);
}
#endif
#ifndef skip_glBlendColorEXT
void glBlendColorEXT(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
printf(gl.c);
}
#endif
#ifndef skip_glBlendColorxOES
void glBlendColorxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
printf(gl.c);
}
#endif
#ifndef skip_glBlendEquation
void glBlendEquation(GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glBlendEquationEXT
void glBlendEquationEXT(GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glBlendEquationIndexedAMD
void glBlendEquationIndexedAMD(GLuint buf, GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glBlendEquationSeparate
void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) {
printf(gl.c);
}
#endif
#ifndef skip_glBlendEquationSeparateEXT
void glBlendEquationSeparateEXT(GLenum modeRGB, GLenum modeAlpha) {
printf(gl.c);
}
#endif
#ifndef skip_glBlendEquationSeparateIndexedAMD
void glBlendEquationSeparateIndexedAMD(GLuint buf, GLenum modeRGB, GLenum modeAlpha) {
printf(gl.c);
}
#endif
#ifndef skip_glBlendEquationSeparatei
void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) {
printf(gl.c);
}
#endif
#ifndef skip_glBlendEquationSeparateiARB
void glBlendEquationSeparateiARB(GLuint buf, GLenum modeRGB, GLenum modeAlpha) {
printf(gl.c);
}
#endif
#ifndef skip_glBlendEquationi
void glBlendEquationi(GLuint buf, GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glBlendEquationiARB
void glBlendEquationiARB(GLuint buf, GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glBlendFunc
void glBlendFunc(GLenum sfactor, GLenum dfactor) {
printf(gl.c);
}
#endif
#ifndef skip_glBlendFuncIndexedAMD
void glBlendFuncIndexedAMD(GLuint buf, GLenum src, GLenum dst) {
printf(gl.c);
}
#endif
#ifndef skip_glBlendFuncSeparate
void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
printf(gl.c);
}
#endif
#ifndef skip_glBlendFuncSeparateEXT
void glBlendFuncSeparateEXT(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
printf(gl.c);
}
#endif
#ifndef skip_glBlendFuncSeparateINGR
void glBlendFuncSeparateINGR(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
printf(gl.c);
}
#endif
#ifndef skip_glBlendFuncSeparateIndexedAMD
void glBlendFuncSeparateIndexedAMD(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
printf(gl.c);
}
#endif
#ifndef skip_glBlendFuncSeparatei
void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
printf(gl.c);
}
#endif
#ifndef skip_glBlendFuncSeparateiARB
void glBlendFuncSeparateiARB(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
printf(gl.c);
}
#endif
#ifndef skip_glBlendFunci
void glBlendFunci(GLuint buf, GLenum src, GLenum dst) {
printf(gl.c);
}
#endif
#ifndef skip_glBlendFunciARB
void glBlendFunciARB(GLuint buf, GLenum src, GLenum dst) {
printf(gl.c);
}
#endif
#ifndef skip_glBlitFramebuffer
void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
printf(gl.c);
}
#endif
#ifndef skip_glBlitFramebufferEXT
void glBlitFramebufferEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
printf(gl.c);
}
#endif
#ifndef skip_glBufferAddressRangeNV
void glBufferAddressRangeNV(GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length) {
printf(gl.c);
}
#endif
#ifndef skip_glBufferData
void glBufferData(GLenum target, GLsizeiptr size, GLvoid data, GLenum usage) {
printf(gl.c);
}
#endif
#ifndef skip_glBufferDataARB
void glBufferDataARB(GLenum target, GLsizeiptrARB size, GLvoid data, GLenum usage) {
printf(gl.c);
}
#endif
#ifndef skip_glBufferParameteriAPPLE
void glBufferParameteriAPPLE(GLenum target, GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glBufferSubData
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid data) {
printf(gl.c);
}
#endif
#ifndef skip_glBufferSubDataARB
void glBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid data) {
printf(gl.c);
}
#endif
#ifndef skip_glCallList
void glCallList(GLuint list) {
printf(gl.c);
}
#endif
#ifndef skip_glCallLists
void glCallLists(GLsizei n, GLenum type, GLvoid lists) {
printf(gl.c);
}
#endif
#ifndef skip_glCheckFramebufferStatus
GLenum glCheckFramebufferStatus(GLenum target) {
printf(gl.c);
}
#endif
#ifndef skip_glCheckFramebufferStatusEXT
GLenum glCheckFramebufferStatusEXT(GLenum target) {
printf(gl.c);
}
#endif
#ifndef skip_glCheckNamedFramebufferStatusEXT
FramebufferStatus glCheckNamedFramebufferStatusEXT(GLuint framebuffer, GLenum target) {
printf(gl.c);
}
#endif
#ifndef skip_glClampColor
void glClampColor(GLenum target, GLenum clamp) {
printf(gl.c);
}
#endif
#ifndef skip_glClampColorARB
void glClampColorARB(GLenum target, GLenum clamp) {
printf(gl.c);
}
#endif
#ifndef skip_glClear
void glClear(GLbitfield mask) {
printf(gl.c);
}
#endif
#ifndef skip_glClearAccum
void glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
printf(gl.c);
}
#endif
#ifndef skip_glClearAccumxOES
void glClearAccumxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
printf(gl.c);
}
#endif
#ifndef skip_glClearBufferData
void glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, void * data) {
printf(gl.c);
}
#endif
#ifndef skip_glClearBufferSubData
void glClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, void * data) {
printf(gl.c);
}
#endif
#ifndef skip_glClearBufferfi
void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) {
printf(gl.c);
}
#endif
#ifndef skip_glClearBufferfv
void glClearBufferfv(GLenum buffer, GLint drawbuffer, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glClearBufferiv
void glClearBufferiv(GLenum buffer, GLint drawbuffer, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glClearBufferuiv
void glClearBufferuiv(GLenum buffer, GLint drawbuffer, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glClearColor
void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
printf(gl.c);
}
#endif
#ifndef skip_glClearColorIiEXT
void glClearColorIiEXT(GLint red, GLint green, GLint blue, GLint alpha) {
printf(gl.c);
}
#endif
#ifndef skip_glClearColorIuiEXT
void glClearColorIuiEXT(GLuint red, GLuint green, GLuint blue, GLuint alpha) {
printf(gl.c);
}
#endif
#ifndef skip_glClearColorxOES
void glClearColorxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
printf(gl.c);
}
#endif
#ifndef skip_glClearDepth
void glClearDepth(GLdouble depth) {
printf(gl.c);
}
#endif
#ifndef skip_glClearDepthdNV
void glClearDepthdNV(GLdouble depth) {
printf(gl.c);
}
#endif
#ifndef skip_glClearDepthf
void glClearDepthf(GLfloat d) {
printf(gl.c);
}
#endif
#ifndef skip_glClearDepthfOES
void glClearDepthfOES(GLclampf depth) {
printf(gl.c);
}
#endif
#ifndef skip_glClearDepthxOES
void glClearDepthxOES(GLfixed depth) {
printf(gl.c);
}
#endif
#ifndef skip_glClearIndex
void glClearIndex(GLfloat c) {
printf(gl.c);
}
#endif
#ifndef skip_glClearNamedBufferDataEXT
void glClearNamedBufferDataEXT(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, void * data) {
printf(gl.c);
}
#endif
#ifndef skip_glClearNamedBufferSubDataEXT
void glClearNamedBufferSubDataEXT(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, GLsizeiptr offset, GLsizeiptr size, void * data) {
printf(gl.c);
}
#endif
#ifndef skip_glClearStencil
void glClearStencil(GLint s) {
printf(gl.c);
}
#endif
#ifndef skip_glClientActiveTexture
void glClientActiveTexture(GLenum texture) {
printf(gl.c);
}
#endif
#ifndef skip_glClientActiveTextureARB
void glClientActiveTextureARB(GLenum texture) {
printf(gl.c);
}
#endif
#ifndef skip_glClientActiveVertexStreamATI
void glClientActiveVertexStreamATI(GLenum stream) {
printf(gl.c);
}
#endif
#ifndef skip_glClientAttribDefaultEXT
void glClientAttribDefaultEXT(GLbitfield mask) {
printf(gl.c);
}
#endif
#ifndef skip_glClientWaitSync
GLenum glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) {
printf(gl.c);
}
#endif
#ifndef skip_glClipPlane
void glClipPlane(GLenum plane, GLdouble equation) {
printf(gl.c);
}
#endif
#ifndef skip_glClipPlanefOES
void glClipPlanefOES(GLenum plane, GLfloat equation) {
printf(gl.c);
}
#endif
#ifndef skip_glClipPlanexOES
void glClipPlanexOES(GLenum plane, GLfixed equation) {
printf(gl.c);
}
#endif
#ifndef skip_glColor3b
void glColor3b(GLbyte red, GLbyte green, GLbyte blue) {
printf(gl.c);
}
#endif
#ifndef skip_glColor3bv
void glColor3bv(GLbyte v) {
printf(gl.c);
}
#endif
#ifndef skip_glColor3d
void glColor3d(GLdouble red, GLdouble green, GLdouble blue) {
printf(gl.c);
}
#endif
#ifndef skip_glColor3dv
void glColor3dv(GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glColor3f
void glColor3f(GLfloat red, GLfloat green, GLfloat blue) {
printf(gl.c);
}
#endif
#ifndef skip_glColor3fVertex3fSUN
void glColor3fVertex3fSUN(GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glColor3fVertex3fvSUN
void glColor3fVertex3fvSUN(GLfloat c, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glColor3fv
void glColor3fv(GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glColor3hNV
void glColor3hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue) {
printf(gl.c);
}
#endif
#ifndef skip_glColor3hvNV
void glColor3hvNV(GLhalfNV v) {
printf(gl.c);
}
#endif
#ifndef skip_glColor3i
void glColor3i(GLint red, GLint green, GLint blue) {
printf(gl.c);
}
#endif
#ifndef skip_glColor3iv
void glColor3iv(GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glColor3s
void glColor3s(GLshort red, GLshort green, GLshort blue) {
printf(gl.c);
}
#endif
#ifndef skip_glColor3sv
void glColor3sv(GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glColor3ub
void glColor3ub(GLubyte red, GLubyte green, GLubyte blue) {
printf(gl.c);
}
#endif
#ifndef skip_glColor3ubv
void glColor3ubv(GLubyte v) {
printf(gl.c);
}
#endif
#ifndef skip_glColor3ui
void glColor3ui(GLuint red, GLuint green, GLuint blue) {
printf(gl.c);
}
#endif
#ifndef skip_glColor3uiv
void glColor3uiv(GLuint v) {
printf(gl.c);
}
#endif
#ifndef skip_glColor3us
void glColor3us(GLushort red, GLushort green, GLushort blue) {
printf(gl.c);
}
#endif
#ifndef skip_glColor3usv
void glColor3usv(GLushort v) {
printf(gl.c);
}
#endif
#ifndef skip_glColor3xOES
void glColor3xOES(GLfixed red, GLfixed green, GLfixed blue) {
printf(gl.c);
}
#endif
#ifndef skip_glColor3xvOES
void glColor3xvOES(GLfixed components) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4b
void glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4bv
void glColor4bv(GLbyte v) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4d
void glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4dv
void glColor4dv(GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4f
void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4fNormal3fVertex3fSUN
void glColor4fNormal3fVertex3fSUN(GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4fNormal3fVertex3fvSUN
void glColor4fNormal3fVertex3fvSUN(GLfloat c, GLfloat n, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4fv
void glColor4fv(GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4hNV
void glColor4hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue, GLhalfNV alpha) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4hvNV
void glColor4hvNV(GLhalfNV v) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4i
void glColor4i(GLint red, GLint green, GLint blue, GLint alpha) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4iv
void glColor4iv(GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4s
void glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4sv
void glColor4sv(GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4ub
void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4ubVertex2fSUN
void glColor4ubVertex2fSUN(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4ubVertex2fvSUN
void glColor4ubVertex2fvSUN(GLubyte c, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4ubVertex3fSUN
void glColor4ubVertex3fSUN(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4ubVertex3fvSUN
void glColor4ubVertex3fvSUN(GLubyte c, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4ubv
void glColor4ubv(GLubyte v) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4ui
void glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4uiv
void glColor4uiv(GLuint v) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4us
void glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4usv
void glColor4usv(GLushort v) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4xOES
void glColor4xOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
printf(gl.c);
}
#endif
#ifndef skip_glColor4xvOES
void glColor4xvOES(GLfixed components) {
printf(gl.c);
}
#endif
#ifndef skip_glColorFormatNV
void glColorFormatNV(GLint size, GLenum type, GLsizei stride) {
printf(gl.c);
}
#endif
#ifndef skip_glColorFragmentOp1ATI
void glColorFragmentOp1ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod) {
printf(gl.c);
}
#endif
#ifndef skip_glColorFragmentOp2ATI
void glColorFragmentOp2ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod) {
printf(gl.c);
}
#endif
#ifndef skip_glColorFragmentOp3ATI
void glColorFragmentOp3ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod) {
printf(gl.c);
}
#endif
#ifndef skip_glColorMask
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
printf(gl.c);
}
#endif
#ifndef skip_glColorMaskIndexedEXT
void glColorMaskIndexedEXT(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) {
printf(gl.c);
}
#endif
#ifndef skip_glColorMaski
void glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) {
printf(gl.c);
}
#endif
#ifndef skip_glColorMaterial
void glColorMaterial(GLenum face, GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glColorP3ui
void glColorP3ui(GLenum type, GLuint color) {
printf(gl.c);
}
#endif
#ifndef skip_glColorP3uiv
void glColorP3uiv(GLenum type, GLuint color) {
printf(gl.c);
}
#endif
#ifndef skip_glColorP4ui
void glColorP4ui(GLenum type, GLuint color) {
printf(gl.c);
}
#endif
#ifndef skip_glColorP4uiv
void glColorP4uiv(GLenum type, GLuint color) {
printf(gl.c);
}
#endif
#ifndef skip_glColorPointer
void glColorPointer(GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glColorPointerEXT
void glColorPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glColorPointerListIBM
void glColorPointerListIBM(GLint size, GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride) {
printf(gl.c);
}
#endif
#ifndef skip_glColorPointervINTEL
void glColorPointervINTEL(GLint size, GLenum type, GLvoid * pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glColorSubTable
void glColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, GLvoid data) {
printf(gl.c);
}
#endif
#ifndef skip_glColorSubTableEXT
void glColorSubTableEXT(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, GLvoid data) {
printf(gl.c);
}
#endif
#ifndef skip_glColorTable
void glColorTable(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, GLvoid table) {
printf(gl.c);
}
#endif
#ifndef skip_glColorTableEXT
void glColorTableEXT(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, GLvoid table) {
printf(gl.c);
}
#endif
#ifndef skip_glColorTableParameterfv
void glColorTableParameterfv(GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glColorTableParameterfvSGI
void glColorTableParameterfvSGI(GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glColorTableParameteriv
void glColorTableParameteriv(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glColorTableParameterivSGI
void glColorTableParameterivSGI(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glColorTableSGI
void glColorTableSGI(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, GLvoid table) {
printf(gl.c);
}
#endif
#ifndef skip_glCombinerInputNV
void glCombinerInputNV(GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage) {
printf(gl.c);
}
#endif
#ifndef skip_glCombinerOutputNV
void glCombinerOutputNV(GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum) {
printf(gl.c);
}
#endif
#ifndef skip_glCombinerParameterfNV
void glCombinerParameterfNV(GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glCombinerParameterfvNV
void glCombinerParameterfvNV(GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glCombinerParameteriNV
void glCombinerParameteriNV(GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glCombinerParameterivNV
void glCombinerParameterivNV(GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glCombinerStageParameterfvNV
void glCombinerStageParameterfvNV(GLenum stage, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glCompileShader
void glCompileShader(GLuint shader) {
printf(gl.c);
}
#endif
#ifndef skip_glCompileShaderARB
void glCompileShaderARB(GLhandleARB shaderObj) {
printf(gl.c);
}
#endif
#ifndef skip_glCompileShaderIncludeARB
void glCompileShaderIncludeARB(GLuint shader, GLsizei count, GLchar * path, GLint length) {
printf(gl.c);
}
#endif
#ifndef skip_glCompressedMultiTexImage1DEXT
void glCompressedMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid bits) {
printf(gl.c);
}
#endif
#ifndef skip_glCompressedMultiTexImage2DEXT
void glCompressedMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid bits) {
printf(gl.c);
}
#endif
#ifndef skip_glCompressedMultiTexImage3DEXT
void glCompressedMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid bits) {
printf(gl.c);
}
#endif
#ifndef skip_glCompressedMultiTexSubImage1DEXT
void glCompressedMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid bits) {
printf(gl.c);
}
#endif
#ifndef skip_glCompressedMultiTexSubImage2DEXT
void glCompressedMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid bits) {
printf(gl.c);
}
#endif
#ifndef skip_glCompressedMultiTexSubImage3DEXT
void glCompressedMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid bits) {
printf(gl.c);
}
#endif
#ifndef skip_glCompressedTexImage1D
void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid data) {
printf(gl.c);
}
#endif
#ifndef skip_glCompressedTexImage1DARB
void glCompressedTexImage1DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid data) {
printf(gl.c);
}
#endif
#ifndef skip_glCompressedTexImage2D
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid data) {
printf(gl.c);
}
#endif
#ifndef skip_glCompressedTexImage2DARB
void glCompressedTexImage2DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid data) {
printf(gl.c);
}
#endif
#ifndef skip_glCompressedTexImage3D
void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid data) {
printf(gl.c);
}
#endif
#ifndef skip_glCompressedTexImage3DARB
void glCompressedTexImage3DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid data) {
printf(gl.c);
}
#endif
#ifndef skip_glCompressedTexSubImage1D
void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid data) {
printf(gl.c);
}
#endif
#ifndef skip_glCompressedTexSubImage1DARB
void glCompressedTexSubImage1DARB(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid data) {
printf(gl.c);
}
#endif
#ifndef skip_glCompressedTexSubImage2D
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid data) {
printf(gl.c);
}
#endif
#ifndef skip_glCompressedTexSubImage2DARB
void glCompressedTexSubImage2DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid data) {
printf(gl.c);
}
#endif
#ifndef skip_glCompressedTexSubImage3D
void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid data) {
printf(gl.c);
}
#endif
#ifndef skip_glCompressedTexSubImage3DARB
void glCompressedTexSubImage3DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid data) {
printf(gl.c);
}
#endif
#ifndef skip_glCompressedTextureImage1DEXT
void glCompressedTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid bits) {
printf(gl.c);
}
#endif
#ifndef skip_glCompressedTextureImage2DEXT
void glCompressedTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid bits) {
printf(gl.c);
}
#endif
#ifndef skip_glCompressedTextureImage3DEXT
void glCompressedTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid bits) {
printf(gl.c);
}
#endif
#ifndef skip_glCompressedTextureSubImage1DEXT
void glCompressedTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid bits) {
printf(gl.c);
}
#endif
#ifndef skip_glCompressedTextureSubImage2DEXT
void glCompressedTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid bits) {
printf(gl.c);
}
#endif
#ifndef skip_glCompressedTextureSubImage3DEXT
void glCompressedTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid bits) {
printf(gl.c);
}
#endif
#ifndef skip_glConvolutionFilter1D
void glConvolutionFilter1D(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, GLvoid image) {
printf(gl.c);
}
#endif
#ifndef skip_glConvolutionFilter1DEXT
void glConvolutionFilter1DEXT(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, GLvoid image) {
printf(gl.c);
}
#endif
#ifndef skip_glConvolutionFilter2D
void glConvolutionFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid image) {
printf(gl.c);
}
#endif
#ifndef skip_glConvolutionFilter2DEXT
void glConvolutionFilter2DEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid image) {
printf(gl.c);
}
#endif
#ifndef skip_glConvolutionParameterf
void glConvolutionParameterf(GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glConvolutionParameterfEXT
void glConvolutionParameterfEXT(GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glConvolutionParameterfv
void glConvolutionParameterfv(GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glConvolutionParameterfvEXT
void glConvolutionParameterfvEXT(GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glConvolutionParameteri
void glConvolutionParameteri(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glConvolutionParameteriEXT
void glConvolutionParameteriEXT(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glConvolutionParameteriv
void glConvolutionParameteriv(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glConvolutionParameterivEXT
void glConvolutionParameterivEXT(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glConvolutionParameterxOES
void glConvolutionParameterxOES(GLenum target, GLenum pname, GLfixed param) {
printf(gl.c);
}
#endif
#ifndef skip_glConvolutionParameterxvOES
void glConvolutionParameterxvOES(GLenum target, GLenum pname, GLfixed params) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyBufferSubData
void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyColorSubTable
void glCopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyColorSubTableEXT
void glCopyColorSubTableEXT(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyColorTable
void glCopyColorTable(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyColorTableSGI
void glCopyColorTableSGI(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyConvolutionFilter1D
void glCopyConvolutionFilter1D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyConvolutionFilter1DEXT
void glCopyConvolutionFilter1DEXT(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyConvolutionFilter2D
void glCopyConvolutionFilter2D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyConvolutionFilter2DEXT
void glCopyConvolutionFilter2DEXT(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyImageSubData
void glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyImageSubDataNV
void glCopyImageSubDataNV(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyMultiTexImage1DEXT
void glCopyMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyMultiTexImage2DEXT
void glCopyMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyMultiTexSubImage1DEXT
void glCopyMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyMultiTexSubImage2DEXT
void glCopyMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyMultiTexSubImage3DEXT
void glCopyMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyPathNV
void glCopyPathNV(GLuint resultPath, GLuint srcPath) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyPixels
void glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyTexImage1D
void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyTexImage1DEXT
void glCopyTexImage1DEXT(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyTexImage2D
void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyTexImage2DEXT
void glCopyTexImage2DEXT(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyTexSubImage1D
void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyTexSubImage1DEXT
void glCopyTexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyTexSubImage2D
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyTexSubImage2DEXT
void glCopyTexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyTexSubImage3D
void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyTexSubImage3DEXT
void glCopyTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyTextureImage1DEXT
void glCopyTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyTextureImage2DEXT
void glCopyTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyTextureSubImage1DEXT
void glCopyTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyTextureSubImage2DEXT
void glCopyTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
printf(gl.c);
}
#endif
#ifndef skip_glCopyTextureSubImage3DEXT
void glCopyTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
printf(gl.c);
}
#endif
#ifndef skip_glCoverFillPathInstancedNV
void glCoverFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLenum coverMode, GLenum transformType, GLfloat transformValues) {
printf(gl.c);
}
#endif
#ifndef skip_glCoverFillPathNV
void glCoverFillPathNV(GLuint path, GLenum coverMode) {
printf(gl.c);
}
#endif
#ifndef skip_glCoverStrokePathInstancedNV
void glCoverStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLenum coverMode, GLenum transformType, GLfloat transformValues) {
printf(gl.c);
}
#endif
#ifndef skip_glCoverStrokePathNV
void glCoverStrokePathNV(GLuint path, GLenum coverMode) {
printf(gl.c);
}
#endif
#ifndef skip_glCreateProgram
UInt32 glCreateProgram() {
printf(gl.c);
}
#endif
#ifndef skip_glCreateProgramObjectARB
handleARB glCreateProgramObjectARB() {
printf(gl.c);
}
#endif
#ifndef skip_glCreateShader
UInt32 glCreateShader(GLenum type) {
printf(gl.c);
}
#endif
#ifndef skip_glCreateShaderObjectARB
handleARB glCreateShaderObjectARB(GLenum shaderType) {
printf(gl.c);
}
#endif
#ifndef skip_glCreateShaderProgramEXT
UInt32 glCreateShaderProgramEXT(GLenum type, GLchar string) {
printf(gl.c);
}
#endif
#ifndef skip_glCreateShaderProgramv
UInt32 glCreateShaderProgramv(GLenum type, GLsizei count, GLchar*const strings) {
printf(gl.c);
}
#endif
#ifndef skip_glCreateSyncFromCLeventARB
sync glCreateSyncFromCLeventARB(struct _cl_context * context, struct _cl_event * event, GLbitfield flags) {
printf(gl.c);
}
#endif
#ifndef skip_glCullFace
void glCullFace(GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glCullParameterdvEXT
void glCullParameterdvEXT(GLenum pname, GLdouble params) {
printf(gl.c);
}
#endif
#ifndef skip_glCullParameterfvEXT
void glCullParameterfvEXT(GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glCurrentPaletteMatrixARB
void glCurrentPaletteMatrixARB(GLint index) {
printf(gl.c);
}
#endif
#ifndef skip_glDebugMessageCallback
void glDebugMessageCallback(GLDEBUGPROC callback, void * userParam) {
printf(gl.c);
}
#endif
#ifndef skip_glDebugMessageCallbackAMD
void glDebugMessageCallbackAMD(GLDEBUGPROCAMD callback, GLvoid userParam) {
printf(gl.c);
}
#endif
#ifndef skip_glDebugMessageCallbackARB
void glDebugMessageCallbackARB(GLDEBUGPROCARB callback, GLvoid userParam) {
printf(gl.c);
}
#endif
#ifndef skip_glDebugMessageControl
void glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, GLuint ids, GLboolean enabled) {
printf(gl.c);
}
#endif
#ifndef skip_glDebugMessageControlARB
void glDebugMessageControlARB(GLenum source, GLenum type, GLenum severity, GLsizei count, GLuint ids, GLboolean enabled) {
printf(gl.c);
}
#endif
#ifndef skip_glDebugMessageEnableAMD
void glDebugMessageEnableAMD(GLenum category, GLenum severity, GLsizei count, GLuint ids, GLboolean enabled) {
printf(gl.c);
}
#endif
#ifndef skip_glDebugMessageInsert
void glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, GLchar buf) {
printf(gl.c);
}
#endif
#ifndef skip_glDebugMessageInsertAMD
void glDebugMessageInsertAMD(GLenum category, GLenum severity, GLuint id, GLsizei length, GLchar buf) {
printf(gl.c);
}
#endif
#ifndef skip_glDebugMessageInsertARB
void glDebugMessageInsertARB(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, GLchar buf) {
printf(gl.c);
}
#endif
#ifndef skip_glDeformSGIX
void glDeformSGIX(GLbitfield mask) {
printf(gl.c);
}
#endif
#ifndef skip_glDeformationMap3dSGIX
void glDeformationMap3dSGIX(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble w1, GLdouble w2, GLint wstride, GLint worder, GLdouble points) {
printf(gl.c);
}
#endif
#ifndef skip_glDeformationMap3fSGIX
void glDeformationMap3fSGIX(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat w1, GLfloat w2, GLint wstride, GLint worder, GLfloat points) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteAsyncMarkersSGIX
void glDeleteAsyncMarkersSGIX(GLuint marker, GLsizei range) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteBuffers
void glDeleteBuffers(GLsizei n, GLuint buffers) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteBuffersARB
void glDeleteBuffersARB(GLsizei n, GLuint buffers) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteFencesAPPLE
void glDeleteFencesAPPLE(GLsizei n, GLuint fences) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteFencesNV
void glDeleteFencesNV(GLsizei n, GLuint fences) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteFragmentShaderATI
void glDeleteFragmentShaderATI(GLuint id) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteFramebuffers
void glDeleteFramebuffers(GLsizei n, GLuint framebuffers) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteFramebuffersEXT
void glDeleteFramebuffersEXT(GLsizei n, GLuint framebuffers) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteLists
void glDeleteLists(GLuint list, GLsizei range) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteNamedStringARB
void glDeleteNamedStringARB(GLint namelen, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteNamesAMD
void glDeleteNamesAMD(GLenum identifier, GLuint num, GLuint names) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteObjectARB
void glDeleteObjectARB(GLhandleARB obj) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteOcclusionQueriesNV
void glDeleteOcclusionQueriesNV(GLsizei n, GLuint ids) {
printf(gl.c);
}
#endif
#ifndef skip_glDeletePathsNV
void glDeletePathsNV(GLuint path, GLsizei range) {
printf(gl.c);
}
#endif
#ifndef skip_glDeletePerfMonitorsAMD
void glDeletePerfMonitorsAMD(GLsizei n, GLuint monitors) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteProgram
void glDeleteProgram(GLuint program) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteProgramPipelines
void glDeleteProgramPipelines(GLsizei n, GLuint pipelines) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteProgramsARB
void glDeleteProgramsARB(GLsizei n, GLuint programs) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteProgramsNV
void glDeleteProgramsNV(GLsizei n, GLuint programs) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteQueries
void glDeleteQueries(GLsizei n, GLuint ids) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteQueriesARB
void glDeleteQueriesARB(GLsizei n, GLuint ids) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteRenderbuffers
void glDeleteRenderbuffers(GLsizei n, GLuint renderbuffers) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteRenderbuffersEXT
void glDeleteRenderbuffersEXT(GLsizei n, GLuint renderbuffers) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteSamplers
void glDeleteSamplers(GLsizei count, GLuint samplers) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteShader
void glDeleteShader(GLuint shader) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteSync
void glDeleteSync(GLsync sync) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteTextures
void glDeleteTextures(GLsizei n, GLuint textures) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteTexturesEXT
void glDeleteTexturesEXT(GLsizei n, GLuint textures) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteTransformFeedbacks
void glDeleteTransformFeedbacks(GLsizei n, GLuint ids) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteTransformFeedbacksNV
void glDeleteTransformFeedbacksNV(GLsizei n, GLuint ids) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteVertexArrays
void glDeleteVertexArrays(GLsizei n, GLuint arrays) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteVertexArraysAPPLE
void glDeleteVertexArraysAPPLE(GLsizei n, GLuint arrays) {
printf(gl.c);
}
#endif
#ifndef skip_glDeleteVertexShaderEXT
void glDeleteVertexShaderEXT(GLuint id) {
printf(gl.c);
}
#endif
#ifndef skip_glDepthBoundsEXT
void glDepthBoundsEXT(GLclampd zmin, GLclampd zmax) {
printf(gl.c);
}
#endif
#ifndef skip_glDepthBoundsdNV
void glDepthBoundsdNV(GLdouble zmin, GLdouble zmax) {
printf(gl.c);
}
#endif
#ifndef skip_glDepthFunc
void glDepthFunc(GLenum func) {
printf(gl.c);
}
#endif
#ifndef skip_glDepthMask
void glDepthMask(GLboolean flag) {
printf(gl.c);
}
#endif
#ifndef skip_glDepthRange
void glDepthRange(GLdouble near, GLdouble far) {
printf(gl.c);
}
#endif
#ifndef skip_glDepthRangeArrayv
void glDepthRangeArrayv(GLuint first, GLsizei count, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glDepthRangeIndexed
void glDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f) {
printf(gl.c);
}
#endif
#ifndef skip_glDepthRangedNV
void glDepthRangedNV(GLdouble zNear, GLdouble zFar) {
printf(gl.c);
}
#endif
#ifndef skip_glDepthRangef
void glDepthRangef(GLfloat n, GLfloat f) {
printf(gl.c);
}
#endif
#ifndef skip_glDepthRangefOES
void glDepthRangefOES(GLclampf n, GLclampf f) {
printf(gl.c);
}
#endif
#ifndef skip_glDepthRangexOES
void glDepthRangexOES(GLfixed n, GLfixed f) {
printf(gl.c);
}
#endif
#ifndef skip_glDetachObjectARB
void glDetachObjectARB(GLhandleARB containerObj, GLhandleARB attachedObj) {
printf(gl.c);
}
#endif
#ifndef skip_glDetachShader
void glDetachShader(GLuint program, GLuint shader) {
printf(gl.c);
}
#endif
#ifndef skip_glDetailTexFuncSGIS
void glDetailTexFuncSGIS(GLenum target, GLsizei n, GLfloat points) {
printf(gl.c);
}
#endif
#ifndef skip_glDisable
void glDisable(GLenum cap) {
printf(gl.c);
}
#endif
#ifndef skip_glDisableClientState
void glDisableClientState(GLenum array) {
printf(gl.c);
}
#endif
#ifndef skip_glDisableClientStateIndexedEXT
void glDisableClientStateIndexedEXT(GLenum array, GLuint index) {
printf(gl.c);
}
#endif
#ifndef skip_glDisableClientStateiEXT
void glDisableClientStateiEXT(GLenum array, GLuint index) {
printf(gl.c);
}
#endif
#ifndef skip_glDisableIndexedEXT
void glDisableIndexedEXT(GLenum target, GLuint index) {
printf(gl.c);
}
#endif
#ifndef skip_glDisableVariantClientStateEXT
void glDisableVariantClientStateEXT(GLuint id) {
printf(gl.c);
}
#endif
#ifndef skip_glDisableVertexArrayAttribEXT
void glDisableVertexArrayAttribEXT(GLuint vaobj, GLuint index) {
printf(gl.c);
}
#endif
#ifndef skip_glDisableVertexArrayEXT
void glDisableVertexArrayEXT(GLuint vaobj, GLenum array) {
printf(gl.c);
}
#endif
#ifndef skip_glDisableVertexAttribAPPLE
void glDisableVertexAttribAPPLE(GLuint index, GLenum pname) {
printf(gl.c);
}
#endif
#ifndef skip_glDisableVertexAttribArray
void glDisableVertexAttribArray(GLuint index) {
printf(gl.c);
}
#endif
#ifndef skip_glDisableVertexAttribArrayARB
void glDisableVertexAttribArrayARB(GLuint index) {
printf(gl.c);
}
#endif
#ifndef skip_glDisablei
void glDisablei(GLenum target, GLuint index) {
printf(gl.c);
}
#endif
#ifndef skip_glDispatchCompute
void glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) {
printf(gl.c);
}
#endif
#ifndef skip_glDispatchComputeIndirect
void glDispatchComputeIndirect(GLintptr indirect) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawArrays
void glDrawArrays(GLenum mode, GLint first, GLsizei count) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawArraysEXT
void glDrawArraysEXT(GLenum mode, GLint first, GLsizei count) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawArraysIndirect
void glDrawArraysIndirect(GLenum mode, GLvoid indirect) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawArraysInstanced
void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawArraysInstancedARB
void glDrawArraysInstancedARB(GLenum mode, GLint first, GLsizei count, GLsizei primcount) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawArraysInstancedBaseInstance
void glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawArraysInstancedEXT
void glDrawArraysInstancedEXT(GLenum mode, GLint start, GLsizei count, GLsizei primcount) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawBuffer
void glDrawBuffer(GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawBuffers
void glDrawBuffers(GLsizei n, GLenum bufs) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawBuffersARB
void glDrawBuffersARB(GLsizei n, GLenum bufs) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawBuffersATI
void glDrawBuffersATI(GLsizei n, GLenum bufs) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawElementArrayAPPLE
void glDrawElementArrayAPPLE(GLenum mode, GLint first, GLsizei count) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawElementArrayATI
void glDrawElementArrayATI(GLenum mode, GLsizei count) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawElements
void glDrawElements(GLenum mode, GLsizei count, GLenum type, GLvoid indices) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawElementsBaseVertex
void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid indices, GLint basevertex) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawElementsIndirect
void glDrawElementsIndirect(GLenum mode, GLenum type, GLvoid indirect) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawElementsInstanced
void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, GLvoid indices, GLsizei instancecount) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawElementsInstancedARB
void glDrawElementsInstancedARB(GLenum mode, GLsizei count, GLenum type, GLvoid indices, GLsizei primcount) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawElementsInstancedBaseInstance
void glDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, void * indices, GLsizei instancecount, GLuint baseinstance) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawElementsInstancedBaseVertex
void glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid indices, GLsizei instancecount, GLint basevertex) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawElementsInstancedBaseVertexBaseInstance
void glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawElementsInstancedEXT
void glDrawElementsInstancedEXT(GLenum mode, GLsizei count, GLenum type, GLvoid indices, GLsizei primcount) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawMeshArraysSUN
void glDrawMeshArraysSUN(GLenum mode, GLint first, GLsizei count, GLsizei width) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawPixels
void glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawRangeElementArrayAPPLE
void glDrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawRangeElementArrayATI
void glDrawRangeElementArrayATI(GLenum mode, GLuint start, GLuint end, GLsizei count) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawRangeElements
void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid indices) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawRangeElementsBaseVertex
void glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid indices, GLint basevertex) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawRangeElementsEXT
void glDrawRangeElementsEXT(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid indices) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawTextureNV
void glDrawTextureNV(GLuint texture, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawTransformFeedback
void glDrawTransformFeedback(GLenum mode, GLuint id) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawTransformFeedbackInstanced
void glDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawTransformFeedbackNV
void glDrawTransformFeedbackNV(GLenum mode, GLuint id) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawTransformFeedbackStream
void glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream) {
printf(gl.c);
}
#endif
#ifndef skip_glDrawTransformFeedbackStreamInstanced
void glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount) {
printf(gl.c);
}
#endif
#ifndef skip_glEdgeFlag
void glEdgeFlag(GLboolean flag) {
printf(gl.c);
}
#endif
#ifndef skip_glEdgeFlagFormatNV
void glEdgeFlagFormatNV(GLsizei stride) {
printf(gl.c);
}
#endif
#ifndef skip_glEdgeFlagPointer
void glEdgeFlagPointer(GLsizei stride, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glEdgeFlagPointerEXT
void glEdgeFlagPointerEXT(GLsizei stride, GLsizei count, GLboolean pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glEdgeFlagPointerListIBM
void glEdgeFlagPointerListIBM(GLint stride, GLboolean * pointer, GLint ptrstride) {
printf(gl.c);
}
#endif
#ifndef skip_glEdgeFlagv
void glEdgeFlagv(GLboolean flag) {
printf(gl.c);
}
#endif
#ifndef skip_glElementPointerAPPLE
void glElementPointerAPPLE(GLenum type, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glElementPointerATI
void glElementPointerATI(GLenum type, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glEnable
void glEnable(GLenum cap) {
printf(gl.c);
}
#endif
#ifndef skip_glEnableClientState
void glEnableClientState(GLenum array) {
printf(gl.c);
}
#endif
#ifndef skip_glEnableClientStateIndexedEXT
void glEnableClientStateIndexedEXT(GLenum array, GLuint index) {
printf(gl.c);
}
#endif
#ifndef skip_glEnableClientStateiEXT
void glEnableClientStateiEXT(GLenum array, GLuint index) {
printf(gl.c);
}
#endif
#ifndef skip_glEnableIndexedEXT
void glEnableIndexedEXT(GLenum target, GLuint index) {
printf(gl.c);
}
#endif
#ifndef skip_glEnableVariantClientStateEXT
void glEnableVariantClientStateEXT(GLuint id) {
printf(gl.c);
}
#endif
#ifndef skip_glEnableVertexArrayAttribEXT
void glEnableVertexArrayAttribEXT(GLuint vaobj, GLuint index) {
printf(gl.c);
}
#endif
#ifndef skip_glEnableVertexArrayEXT
void glEnableVertexArrayEXT(GLuint vaobj, GLenum array) {
printf(gl.c);
}
#endif
#ifndef skip_glEnableVertexAttribAPPLE
void glEnableVertexAttribAPPLE(GLuint index, GLenum pname) {
printf(gl.c);
}
#endif
#ifndef skip_glEnableVertexAttribArray
void glEnableVertexAttribArray(GLuint index) {
printf(gl.c);
}
#endif
#ifndef skip_glEnableVertexAttribArrayARB
void glEnableVertexAttribArrayARB(GLuint index) {
printf(gl.c);
}
#endif
#ifndef skip_glEnablei
void glEnablei(GLenum target, GLuint index) {
printf(gl.c);
}
#endif
#ifndef skip_glEnd
void glEnd() {
printf(gl.c);
}
#endif
#ifndef skip_glEndConditionalRender
void glEndConditionalRender() {
printf(gl.c);
}
#endif
#ifndef skip_glEndConditionalRenderNV
void glEndConditionalRenderNV() {
printf(gl.c);
}
#endif
#ifndef skip_glEndConditionalRenderNVX
void glEndConditionalRenderNVX() {
printf(gl.c);
}
#endif
#ifndef skip_glEndFragmentShaderATI
void glEndFragmentShaderATI() {
printf(gl.c);
}
#endif
#ifndef skip_glEndList
void glEndList() {
printf(gl.c);
}
#endif
#ifndef skip_glEndOcclusionQueryNV
void glEndOcclusionQueryNV() {
printf(gl.c);
}
#endif
#ifndef skip_glEndPerfMonitorAMD
void glEndPerfMonitorAMD(GLuint monitor) {
printf(gl.c);
}
#endif
#ifndef skip_glEndQuery
void glEndQuery(GLenum target) {
printf(gl.c);
}
#endif
#ifndef skip_glEndQueryARB
void glEndQueryARB(GLenum target) {
printf(gl.c);
}
#endif
#ifndef skip_glEndQueryIndexed
void glEndQueryIndexed(GLenum target, GLuint index) {
printf(gl.c);
}
#endif
#ifndef skip_glEndTransformFeedback
void glEndTransformFeedback() {
printf(gl.c);
}
#endif
#ifndef skip_glEndTransformFeedbackEXT
void glEndTransformFeedbackEXT() {
printf(gl.c);
}
#endif
#ifndef skip_glEndTransformFeedbackNV
void glEndTransformFeedbackNV() {
printf(gl.c);
}
#endif
#ifndef skip_glEndVertexShaderEXT
void glEndVertexShaderEXT() {
printf(gl.c);
}
#endif
#ifndef skip_glEndVideoCaptureNV
void glEndVideoCaptureNV(GLuint video_capture_slot) {
printf(gl.c);
}
#endif
#ifndef skip_glEvalCoord1d
void glEvalCoord1d(GLdouble u) {
printf(gl.c);
}
#endif
#ifndef skip_glEvalCoord1dv
void glEvalCoord1dv(GLdouble u) {
printf(gl.c);
}
#endif
#ifndef skip_glEvalCoord1f
void glEvalCoord1f(GLfloat u) {
printf(gl.c);
}
#endif
#ifndef skip_glEvalCoord1fv
void glEvalCoord1fv(GLfloat u) {
printf(gl.c);
}
#endif
#ifndef skip_glEvalCoord1xOES
void glEvalCoord1xOES(GLfixed u) {
printf(gl.c);
}
#endif
#ifndef skip_glEvalCoord1xvOES
void glEvalCoord1xvOES(GLfixed coords) {
printf(gl.c);
}
#endif
#ifndef skip_glEvalCoord2d
void glEvalCoord2d(GLdouble u, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glEvalCoord2dv
void glEvalCoord2dv(GLdouble u) {
printf(gl.c);
}
#endif
#ifndef skip_glEvalCoord2f
void glEvalCoord2f(GLfloat u, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glEvalCoord2fv
void glEvalCoord2fv(GLfloat u) {
printf(gl.c);
}
#endif
#ifndef skip_glEvalCoord2xOES
void glEvalCoord2xOES(GLfixed u, GLfixed v) {
printf(gl.c);
}
#endif
#ifndef skip_glEvalCoord2xvOES
void glEvalCoord2xvOES(GLfixed coords) {
printf(gl.c);
}
#endif
#ifndef skip_glEvalMapsNV
void glEvalMapsNV(GLenum target, GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glEvalMesh1
void glEvalMesh1(GLenum mode, GLint i1, GLint i2) {
printf(gl.c);
}
#endif
#ifndef skip_glEvalMesh2
void glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2) {
printf(gl.c);
}
#endif
#ifndef skip_glEvalPoint1
void glEvalPoint1(GLint i) {
printf(gl.c);
}
#endif
#ifndef skip_glEvalPoint2
void glEvalPoint2(GLint i, GLint j) {
printf(gl.c);
}
#endif
#ifndef skip_glExecuteProgramNV
void glExecuteProgramNV(GLenum target, GLuint id, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glExtractComponentEXT
void glExtractComponentEXT(GLuint res, GLuint src, GLuint num) {
printf(gl.c);
}
#endif
#ifndef skip_glFeedbackBuffer
void glFeedbackBuffer(GLsizei size, GLenum type, GLfloat buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glFeedbackBufferxOES
void glFeedbackBufferxOES(GLsizei n, GLenum type, GLfixed buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glFenceSync
sync glFenceSync(GLenum condition, GLbitfield flags) {
printf(gl.c);
}
#endif
#ifndef skip_glFinalCombinerInputNV
void glFinalCombinerInputNV(GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage) {
printf(gl.c);
}
#endif
#ifndef skip_glFinish
void glFinish() {
printf(gl.c);
}
#endif
#ifndef skip_glFinishAsyncSGIX
Int32 glFinishAsyncSGIX(GLuint markerp) {
printf(gl.c);
}
#endif
#ifndef skip_glFinishFenceAPPLE
void glFinishFenceAPPLE(GLuint fence) {
printf(gl.c);
}
#endif
#ifndef skip_glFinishFenceNV
void glFinishFenceNV(GLuint fence) {
printf(gl.c);
}
#endif
#ifndef skip_glFinishObjectAPPLE
void glFinishObjectAPPLE(GLenum object, GLint name) {
printf(gl.c);
}
#endif
#ifndef skip_glFinishTextureSUNX
void glFinishTextureSUNX() {
printf(gl.c);
}
#endif
#ifndef skip_glFlush
void glFlush() {
printf(gl.c);
}
#endif
#ifndef skip_glFlushMappedBufferRange
void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) {
printf(gl.c);
}
#endif
#ifndef skip_glFlushMappedBufferRangeAPPLE
void glFlushMappedBufferRangeAPPLE(GLenum target, GLintptr offset, GLsizeiptr size) {
printf(gl.c);
}
#endif
#ifndef skip_glFlushMappedNamedBufferRangeEXT
void glFlushMappedNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length) {
printf(gl.c);
}
#endif
#ifndef skip_glFlushPixelDataRangeNV
void glFlushPixelDataRangeNV(GLenum target) {
printf(gl.c);
}
#endif
#ifndef skip_glFlushRasterSGIX
void glFlushRasterSGIX() {
printf(gl.c);
}
#endif
#ifndef skip_glFlushStaticDataIBM
void glFlushStaticDataIBM(GLenum target) {
printf(gl.c);
}
#endif
#ifndef skip_glFlushVertexArrayRangeAPPLE
void glFlushVertexArrayRangeAPPLE(GLsizei length, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glFlushVertexArrayRangeNV
void glFlushVertexArrayRangeNV() {
printf(gl.c);
}
#endif
#ifndef skip_glFogCoordFormatNV
void glFogCoordFormatNV(GLenum type, GLsizei stride) {
printf(gl.c);
}
#endif
#ifndef skip_glFogCoordPointer
void glFogCoordPointer(GLenum type, GLsizei stride, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glFogCoordPointerEXT
void glFogCoordPointerEXT(GLenum type, GLsizei stride, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glFogCoordPointerListIBM
void glFogCoordPointerListIBM(GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride) {
printf(gl.c);
}
#endif
#ifndef skip_glFogCoordd
void glFogCoordd(GLdouble coord) {
printf(gl.c);
}
#endif
#ifndef skip_glFogCoorddEXT
void glFogCoorddEXT(GLdouble coord) {
printf(gl.c);
}
#endif
#ifndef skip_glFogCoorddv
void glFogCoorddv(GLdouble coord) {
printf(gl.c);
}
#endif
#ifndef skip_glFogCoorddvEXT
void glFogCoorddvEXT(GLdouble coord) {
printf(gl.c);
}
#endif
#ifndef skip_glFogCoordf
void glFogCoordf(GLfloat coord) {
printf(gl.c);
}
#endif
#ifndef skip_glFogCoordfEXT
void glFogCoordfEXT(GLfloat coord) {
printf(gl.c);
}
#endif
#ifndef skip_glFogCoordfv
void glFogCoordfv(GLfloat coord) {
printf(gl.c);
}
#endif
#ifndef skip_glFogCoordfvEXT
void glFogCoordfvEXT(GLfloat coord) {
printf(gl.c);
}
#endif
#ifndef skip_glFogCoordhNV
void glFogCoordhNV(GLhalfNV fog) {
printf(gl.c);
}
#endif
#ifndef skip_glFogCoordhvNV
void glFogCoordhvNV(GLhalfNV fog) {
printf(gl.c);
}
#endif
#ifndef skip_glFogFuncSGIS
void glFogFuncSGIS(GLsizei n, GLfloat points) {
printf(gl.c);
}
#endif
#ifndef skip_glFogf
void glFogf(GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glFogfv
void glFogfv(GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glFogi
void glFogi(GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glFogiv
void glFogiv(GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glFogxOES
void glFogxOES(GLenum pname, GLfixed param) {
printf(gl.c);
}
#endif
#ifndef skip_glFogxvOES
void glFogxvOES(GLenum pname, GLfixed param) {
printf(gl.c);
}
#endif
#ifndef skip_glFragmentColorMaterialSGIX
void glFragmentColorMaterialSGIX(GLenum face, GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glFragmentLightModelfSGIX
void glFragmentLightModelfSGIX(GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glFragmentLightModelfvSGIX
void glFragmentLightModelfvSGIX(GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glFragmentLightModeliSGIX
void glFragmentLightModeliSGIX(GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glFragmentLightModelivSGIX
void glFragmentLightModelivSGIX(GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glFragmentLightfSGIX
void glFragmentLightfSGIX(GLenum light, GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glFragmentLightfvSGIX
void glFragmentLightfvSGIX(GLenum light, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glFragmentLightiSGIX
void glFragmentLightiSGIX(GLenum light, GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glFragmentLightivSGIX
void glFragmentLightivSGIX(GLenum light, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glFragmentMaterialfSGIX
void glFragmentMaterialfSGIX(GLenum face, GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glFragmentMaterialfvSGIX
void glFragmentMaterialfvSGIX(GLenum face, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glFragmentMaterialiSGIX
void glFragmentMaterialiSGIX(GLenum face, GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glFragmentMaterialivSGIX
void glFragmentMaterialivSGIX(GLenum face, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glFrameTerminatorGREMEDY
void glFrameTerminatorGREMEDY() {
printf(gl.c);
}
#endif
#ifndef skip_glFrameZoomSGIX
void glFrameZoomSGIX(GLint factor) {
printf(gl.c);
}
#endif
#ifndef skip_glFramebufferDrawBufferEXT
void glFramebufferDrawBufferEXT(GLuint framebuffer, GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glFramebufferDrawBuffersEXT
void glFramebufferDrawBuffersEXT(GLuint framebuffer, GLsizei n, GLenum bufs) {
printf(gl.c);
}
#endif
#ifndef skip_glFramebufferParameteri
void glFramebufferParameteri(GLenum target, GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glFramebufferReadBufferEXT
void glFramebufferReadBufferEXT(GLuint framebuffer, GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glFramebufferRenderbuffer
void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
printf(gl.c);
}
#endif
#ifndef skip_glFramebufferRenderbufferEXT
void glFramebufferRenderbufferEXT(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
printf(gl.c);
}
#endif
#ifndef skip_glFramebufferTexture
void glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) {
printf(gl.c);
}
#endif
#ifndef skip_glFramebufferTexture1D
void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
printf(gl.c);
}
#endif
#ifndef skip_glFramebufferTexture1DEXT
void glFramebufferTexture1DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
printf(gl.c);
}
#endif
#ifndef skip_glFramebufferTexture2D
void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
printf(gl.c);
}
#endif
#ifndef skip_glFramebufferTexture2DEXT
void glFramebufferTexture2DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
printf(gl.c);
}
#endif
#ifndef skip_glFramebufferTexture3D
void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) {
printf(gl.c);
}
#endif
#ifndef skip_glFramebufferTexture3DEXT
void glFramebufferTexture3DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) {
printf(gl.c);
}
#endif
#ifndef skip_glFramebufferTextureARB
void glFramebufferTextureARB(GLenum target, GLenum attachment, GLuint texture, GLint level) {
printf(gl.c);
}
#endif
#ifndef skip_glFramebufferTextureEXT
void glFramebufferTextureEXT(GLenum target, GLenum attachment, GLuint texture, GLint level) {
printf(gl.c);
}
#endif
#ifndef skip_glFramebufferTextureFaceARB
void glFramebufferTextureFaceARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face) {
printf(gl.c);
}
#endif
#ifndef skip_glFramebufferTextureFaceEXT
void glFramebufferTextureFaceEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face) {
printf(gl.c);
}
#endif
#ifndef skip_glFramebufferTextureLayer
void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
printf(gl.c);
}
#endif
#ifndef skip_glFramebufferTextureLayerARB
void glFramebufferTextureLayerARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
printf(gl.c);
}
#endif
#ifndef skip_glFramebufferTextureLayerEXT
void glFramebufferTextureLayerEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
printf(gl.c);
}
#endif
#ifndef skip_glFreeObjectBufferATI
void glFreeObjectBufferATI(GLuint buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glFrontFace
void glFrontFace(GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glFrustum
void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
printf(gl.c);
}
#endif
#ifndef skip_glFrustumfOES
void glFrustumfOES(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f) {
printf(gl.c);
}
#endif
#ifndef skip_glFrustumxOES
void glFrustumxOES(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f) {
printf(gl.c);
}
#endif
#ifndef skip_glGenAsyncMarkersSGIX
UInt32 glGenAsyncMarkersSGIX(GLsizei range) {
printf(gl.c);
}
#endif
#ifndef skip_glGenBuffers
void glGenBuffers(GLsizei n, GLuint buffers) {
printf(gl.c);
}
#endif
#ifndef skip_glGenBuffersARB
void glGenBuffersARB(GLsizei n, GLuint buffers) {
printf(gl.c);
}
#endif
#ifndef skip_glGenFencesAPPLE
void glGenFencesAPPLE(GLsizei n, GLuint fences) {
printf(gl.c);
}
#endif
#ifndef skip_glGenFencesNV
void glGenFencesNV(GLsizei n, GLuint fences) {
printf(gl.c);
}
#endif
#ifndef skip_glGenFragmentShadersATI
UInt32 glGenFragmentShadersATI(GLuint range) {
printf(gl.c);
}
#endif
#ifndef skip_glGenFramebuffers
void glGenFramebuffers(GLsizei n, GLuint framebuffers) {
printf(gl.c);
}
#endif
#ifndef skip_glGenFramebuffersEXT
void glGenFramebuffersEXT(GLsizei n, GLuint framebuffers) {
printf(gl.c);
}
#endif
#ifndef skip_glGenLists
List glGenLists(GLsizei range) {
printf(gl.c);
}
#endif
#ifndef skip_glGenNamesAMD
void glGenNamesAMD(GLenum identifier, GLuint num, GLuint names) {
printf(gl.c);
}
#endif
#ifndef skip_glGenOcclusionQueriesNV
void glGenOcclusionQueriesNV(GLsizei n, GLuint ids) {
printf(gl.c);
}
#endif
#ifndef skip_glGenPathsNV
Path glGenPathsNV(GLsizei range) {
printf(gl.c);
}
#endif
#ifndef skip_glGenPerfMonitorsAMD
void glGenPerfMonitorsAMD(GLsizei n, GLuint monitors) {
printf(gl.c);
}
#endif
#ifndef skip_glGenProgramPipelines
void glGenProgramPipelines(GLsizei n, GLuint pipelines) {
printf(gl.c);
}
#endif
#ifndef skip_glGenProgramsARB
void glGenProgramsARB(GLsizei n, GLuint programs) {
printf(gl.c);
}
#endif
#ifndef skip_glGenProgramsNV
void glGenProgramsNV(GLsizei n, GLuint programs) {
printf(gl.c);
}
#endif
#ifndef skip_glGenQueries
void glGenQueries(GLsizei n, GLuint ids) {
printf(gl.c);
}
#endif
#ifndef skip_glGenQueriesARB
void glGenQueriesARB(GLsizei n, GLuint ids) {
printf(gl.c);
}
#endif
#ifndef skip_glGenRenderbuffers
void glGenRenderbuffers(GLsizei n, GLuint renderbuffers) {
printf(gl.c);
}
#endif
#ifndef skip_glGenRenderbuffersEXT
void glGenRenderbuffersEXT(GLsizei n, GLuint renderbuffers) {
printf(gl.c);
}
#endif
#ifndef skip_glGenSamplers
void glGenSamplers(GLsizei count, GLuint samplers) {
printf(gl.c);
}
#endif
#ifndef skip_glGenSymbolsEXT
UInt32 glGenSymbolsEXT(GLenum datatype, GLenum storagetype, GLenum range, GLuint components) {
printf(gl.c);
}
#endif
#ifndef skip_glGenTextures
void glGenTextures(GLsizei n, GLuint textures) {
printf(gl.c);
}
#endif
#ifndef skip_glGenTexturesEXT
void glGenTexturesEXT(GLsizei n, GLuint textures) {
printf(gl.c);
}
#endif
#ifndef skip_glGenTransformFeedbacks
void glGenTransformFeedbacks(GLsizei n, GLuint ids) {
printf(gl.c);
}
#endif
#ifndef skip_glGenTransformFeedbacksNV
void glGenTransformFeedbacksNV(GLsizei n, GLuint ids) {
printf(gl.c);
}
#endif
#ifndef skip_glGenVertexArrays
void glGenVertexArrays(GLsizei n, GLuint arrays) {
printf(gl.c);
}
#endif
#ifndef skip_glGenVertexArraysAPPLE
void glGenVertexArraysAPPLE(GLsizei n, GLuint arrays) {
printf(gl.c);
}
#endif
#ifndef skip_glGenVertexShadersEXT
UInt32 glGenVertexShadersEXT(GLuint range) {
printf(gl.c);
}
#endif
#ifndef skip_glGenerateMipmap
void glGenerateMipmap(GLenum target) {
printf(gl.c);
}
#endif
#ifndef skip_glGenerateMipmapEXT
void glGenerateMipmapEXT(GLenum target) {
printf(gl.c);
}
#endif
#ifndef skip_glGenerateMultiTexMipmapEXT
void glGenerateMultiTexMipmapEXT(GLenum texunit, GLenum target) {
printf(gl.c);
}
#endif
#ifndef skip_glGenerateTextureMipmapEXT
void glGenerateTextureMipmapEXT(GLuint texture, GLenum target) {
printf(gl.c);
}
#endif
#ifndef skip_glGetActiveAtomicCounterBufferiv
void glGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetActiveAttrib
void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLint size, GLenum type, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glGetActiveAttribARB
void glGetActiveAttribARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei length, GLint size, GLenum type, GLcharARB name) {
printf(gl.c);
}
#endif
#ifndef skip_glGetActiveSubroutineName
void glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei length, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glGetActiveSubroutineUniformName
void glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei length, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glGetActiveSubroutineUniformiv
void glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint values) {
printf(gl.c);
}
#endif
#ifndef skip_glGetActiveUniform
void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLint size, GLenum type, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glGetActiveUniformARB
void glGetActiveUniformARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei length, GLint size, GLenum type, GLcharARB name) {
printf(gl.c);
}
#endif
#ifndef skip_glGetActiveUniformBlockName
void glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei length, GLchar uniformBlockName) {
printf(gl.c);
}
#endif
#ifndef skip_glGetActiveUniformBlockiv
void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetActiveUniformName
void glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei length, GLchar uniformName) {
printf(gl.c);
}
#endif
#ifndef skip_glGetActiveUniformsiv
void glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, GLuint uniformIndices, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetActiveVaryingNV
void glGetActiveVaryingNV(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLsizei size, GLenum type, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glGetArrayObjectfvATI
void glGetArrayObjectfvATI(GLenum array, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetArrayObjectivATI
void glGetArrayObjectivATI(GLenum array, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetAttachedObjectsARB
void glGetAttachedObjectsARB(GLhandleARB containerObj, GLsizei maxCount, GLsizei count, GLhandleARB obj) {
printf(gl.c);
}
#endif
#ifndef skip_glGetAttachedShaders
void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei count, GLuint obj) {
printf(gl.c);
}
#endif
#ifndef skip_glGetAttribLocation
Int32 glGetAttribLocation(GLuint program, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glGetAttribLocationARB
Int32 glGetAttribLocationARB(GLhandleARB programObj, GLcharARB name) {
printf(gl.c);
}
#endif
#ifndef skip_glGetBooleanIndexedvEXT
void glGetBooleanIndexedvEXT(GLenum target, GLuint index, GLboolean data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetBooleani_v
void glGetBooleani_v(GLenum target, GLuint index, GLboolean data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetBooleanv
void glGetBooleanv(GLenum pname, GLboolean params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetBufferParameteri64v
void glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64 params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetBufferParameteriv
void glGetBufferParameteriv(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetBufferParameterivARB
void glGetBufferParameterivARB(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetBufferParameterui64vNV
void glGetBufferParameterui64vNV(GLenum target, GLenum pname, GLuint64EXT params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetBufferPointerv
void glGetBufferPointerv(GLenum target, GLenum pname, GLvoid * params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetBufferPointervARB
void glGetBufferPointervARB(GLenum target, GLenum pname, GLvoid * params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetBufferSubData
void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetBufferSubDataARB
void glGetBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetClipPlane
void glGetClipPlane(GLenum plane, GLdouble equation) {
printf(gl.c);
}
#endif
#ifndef skip_glGetClipPlanefOES
void glGetClipPlanefOES(GLenum plane, GLfloat equation) {
printf(gl.c);
}
#endif
#ifndef skip_glGetClipPlanexOES
void glGetClipPlanexOES(GLenum plane, GLfixed equation) {
printf(gl.c);
}
#endif
#ifndef skip_glGetColorTable
void glGetColorTable(GLenum target, GLenum format, GLenum type, GLvoid table) {
printf(gl.c);
}
#endif
#ifndef skip_glGetColorTableEXT
void glGetColorTableEXT(GLenum target, GLenum format, GLenum type, GLvoid data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetColorTableParameterfv
void glGetColorTableParameterfv(GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetColorTableParameterfvEXT
void glGetColorTableParameterfvEXT(GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetColorTableParameterfvSGI
void glGetColorTableParameterfvSGI(GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetColorTableParameteriv
void glGetColorTableParameteriv(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetColorTableParameterivEXT
void glGetColorTableParameterivEXT(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetColorTableParameterivSGI
void glGetColorTableParameterivSGI(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetColorTableSGI
void glGetColorTableSGI(GLenum target, GLenum format, GLenum type, GLvoid table) {
printf(gl.c);
}
#endif
#ifndef skip_glGetCombinerInputParameterfvNV
void glGetCombinerInputParameterfvNV(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetCombinerInputParameterivNV
void glGetCombinerInputParameterivNV(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetCombinerOutputParameterfvNV
void glGetCombinerOutputParameterfvNV(GLenum stage, GLenum portion, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetCombinerOutputParameterivNV
void glGetCombinerOutputParameterivNV(GLenum stage, GLenum portion, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetCombinerStageParameterfvNV
void glGetCombinerStageParameterfvNV(GLenum stage, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetCompressedMultiTexImageEXT
void glGetCompressedMultiTexImageEXT(GLenum texunit, GLenum target, GLint lod, GLvoid img) {
printf(gl.c);
}
#endif
#ifndef skip_glGetCompressedTexImage
void glGetCompressedTexImage(GLenum target, GLint level, GLvoid img) {
printf(gl.c);
}
#endif
#ifndef skip_glGetCompressedTexImageARB
void glGetCompressedTexImageARB(GLenum target, GLint level, GLvoid img) {
printf(gl.c);
}
#endif
#ifndef skip_glGetCompressedTextureImageEXT
void glGetCompressedTextureImageEXT(GLuint texture, GLenum target, GLint lod, GLvoid img) {
printf(gl.c);
}
#endif
#ifndef skip_glGetConvolutionFilter
void glGetConvolutionFilter(GLenum target, GLenum format, GLenum type, GLvoid image) {
printf(gl.c);
}
#endif
#ifndef skip_glGetConvolutionFilterEXT
void glGetConvolutionFilterEXT(GLenum target, GLenum format, GLenum type, GLvoid image) {
printf(gl.c);
}
#endif
#ifndef skip_glGetConvolutionParameterfv
void glGetConvolutionParameterfv(GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetConvolutionParameterfvEXT
void glGetConvolutionParameterfvEXT(GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetConvolutionParameteriv
void glGetConvolutionParameteriv(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetConvolutionParameterivEXT
void glGetConvolutionParameterivEXT(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetConvolutionParameterxvOES
void glGetConvolutionParameterxvOES(GLenum target, GLenum pname, GLfixed params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetDebugMessageLog
UInt32 glGetDebugMessageLog(GLuint count, GLsizei bufsize, GLenum sources, GLenum types, GLuint ids, GLenum severities, GLsizei lengths, GLchar messageLog) {
printf(gl.c);
}
#endif
#ifndef skip_glGetDebugMessageLogAMD
UInt32 glGetDebugMessageLogAMD(GLuint count, GLsizei bufsize, GLenum categories, GLuint severities, GLuint ids, GLsizei lengths, GLchar message) {
printf(gl.c);
}
#endif
#ifndef skip_glGetDebugMessageLogARB
UInt32 glGetDebugMessageLogARB(GLuint count, GLsizei bufsize, GLenum sources, GLenum types, GLuint ids, GLenum severities, GLsizei lengths, GLchar messageLog) {
printf(gl.c);
}
#endif
#ifndef skip_glGetDetailTexFuncSGIS
void glGetDetailTexFuncSGIS(GLenum target, GLfloat points) {
printf(gl.c);
}
#endif
#ifndef skip_glGetDoubleIndexedvEXT
void glGetDoubleIndexedvEXT(GLenum target, GLuint index, GLdouble data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetDoublei_v
void glGetDoublei_v(GLenum target, GLuint index, GLdouble data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetDoublei_vEXT
void glGetDoublei_vEXT(GLenum target, GLuint index, GLdouble data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetDoublev
void glGetDoublev(GLenum pname, GLdouble params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetError
ErrorCode glGetError() {
printf(gl.c);
}
#endif
#ifndef skip_glGetFenceivNV
void glGetFenceivNV(GLuint fence, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetFinalCombinerInputParameterfvNV
void glGetFinalCombinerInputParameterfvNV(GLenum variable, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetFinalCombinerInputParameterivNV
void glGetFinalCombinerInputParameterivNV(GLenum variable, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetFixedvOES
void glGetFixedvOES(GLenum pname, GLfixed params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetFloatIndexedvEXT
void glGetFloatIndexedvEXT(GLenum target, GLuint index, GLfloat data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetFloati_v
void glGetFloati_v(GLenum target, GLuint index, GLfloat data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetFloati_vEXT
void glGetFloati_vEXT(GLenum target, GLuint index, GLfloat data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetFloatv
void glGetFloatv(GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetFogFuncSGIS
void glGetFogFuncSGIS(GLfloat points) {
printf(gl.c);
}
#endif
#ifndef skip_glGetFragDataIndex
Int32 glGetFragDataIndex(GLuint program, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glGetFragDataLocation
Int32 glGetFragDataLocation(GLuint program, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glGetFragDataLocationEXT
Int32 glGetFragDataLocationEXT(GLuint program, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glGetFragmentLightfvSGIX
void glGetFragmentLightfvSGIX(GLenum light, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetFragmentLightivSGIX
void glGetFragmentLightivSGIX(GLenum light, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetFragmentMaterialfvSGIX
void glGetFragmentMaterialfvSGIX(GLenum face, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetFragmentMaterialivSGIX
void glGetFragmentMaterialivSGIX(GLenum face, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetFramebufferAttachmentParameteriv
void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetFramebufferAttachmentParameterivEXT
void glGetFramebufferAttachmentParameterivEXT(GLenum target, GLenum attachment, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetFramebufferParameteriv
void glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetFramebufferParameterivEXT
void glGetFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetGraphicsResetStatusARB
GLenum glGetGraphicsResetStatusARB() {
printf(gl.c);
}
#endif
#ifndef skip_glGetHandleARB
handleARB glGetHandleARB(GLenum pname) {
printf(gl.c);
}
#endif
#ifndef skip_glGetHistogram
void glGetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid values) {
printf(gl.c);
}
#endif
#ifndef skip_glGetHistogramEXT
void glGetHistogramEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid values) {
printf(gl.c);
}
#endif
#ifndef skip_glGetHistogramParameterfv
void glGetHistogramParameterfv(GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetHistogramParameterfvEXT
void glGetHistogramParameterfvEXT(GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetHistogramParameteriv
void glGetHistogramParameteriv(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetHistogramParameterivEXT
void glGetHistogramParameterivEXT(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetHistogramParameterxvOES
void glGetHistogramParameterxvOES(GLenum target, GLenum pname, GLfixed params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetImageHandleNV
UInt64 glGetImageHandleNV(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format) {
printf(gl.c);
}
#endif
#ifndef skip_glGetImageTransformParameterfvHP
void glGetImageTransformParameterfvHP(GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetImageTransformParameterivHP
void glGetImageTransformParameterivHP(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetInfoLogARB
void glGetInfoLogARB(GLhandleARB obj, GLsizei maxLength, GLsizei length, GLcharARB infoLog) {
printf(gl.c);
}
#endif
#ifndef skip_glGetInstrumentsSGIX
Int32 glGetInstrumentsSGIX() {
printf(gl.c);
}
#endif
#ifndef skip_glGetInteger64i_v
void glGetInteger64i_v(GLenum target, GLuint index, GLint64 data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetInteger64v
void glGetInteger64v(GLenum pname, GLint64 params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetIntegerIndexedvEXT
void glGetIntegerIndexedvEXT(GLenum target, GLuint index, GLint data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetIntegeri_v
void glGetIntegeri_v(GLenum target, GLuint index, GLint data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetIntegerui64i_vNV
void glGetIntegerui64i_vNV(GLenum value, GLuint index, GLuint64EXT result) {
printf(gl.c);
}
#endif
#ifndef skip_glGetIntegerui64vNV
void glGetIntegerui64vNV(GLenum value, GLuint64EXT result) {
printf(gl.c);
}
#endif
#ifndef skip_glGetIntegerv
void glGetIntegerv(GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetInternalformati64v
void glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetInternalformativ
void glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetInvariantBooleanvEXT
void glGetInvariantBooleanvEXT(GLuint id, GLenum value, GLboolean data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetInvariantFloatvEXT
void glGetInvariantFloatvEXT(GLuint id, GLenum value, GLfloat data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetInvariantIntegervEXT
void glGetInvariantIntegervEXT(GLuint id, GLenum value, GLint data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetLightfv
void glGetLightfv(GLenum light, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetLightiv
void glGetLightiv(GLenum light, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetLightxOES
void glGetLightxOES(GLenum light, GLenum pname, GLfixed params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetListParameterfvSGIX
void glGetListParameterfvSGIX(GLuint list, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetListParameterivSGIX
void glGetListParameterivSGIX(GLuint list, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetLocalConstantBooleanvEXT
void glGetLocalConstantBooleanvEXT(GLuint id, GLenum value, GLboolean data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetLocalConstantFloatvEXT
void glGetLocalConstantFloatvEXT(GLuint id, GLenum value, GLfloat data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetLocalConstantIntegervEXT
void glGetLocalConstantIntegervEXT(GLuint id, GLenum value, GLint data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMapAttribParameterfvNV
void glGetMapAttribParameterfvNV(GLenum target, GLuint index, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMapAttribParameterivNV
void glGetMapAttribParameterivNV(GLenum target, GLuint index, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMapControlPointsNV
void glGetMapControlPointsNV(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLboolean packed, GLvoid points) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMapParameterfvNV
void glGetMapParameterfvNV(GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMapParameterivNV
void glGetMapParameterivNV(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMapdv
void glGetMapdv(GLenum target, GLenum query, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMapfv
void glGetMapfv(GLenum target, GLenum query, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMapiv
void glGetMapiv(GLenum target, GLenum query, GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMapxvOES
void glGetMapxvOES(GLenum target, GLenum query, GLfixed v) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMaterialfv
void glGetMaterialfv(GLenum face, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMaterialiv
void glGetMaterialiv(GLenum face, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMaterialxOES
void glGetMaterialxOES(GLenum face, GLenum pname, GLfixed param) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMinmax
void glGetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid values) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMinmaxEXT
void glGetMinmaxEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid values) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMinmaxParameterfv
void glGetMinmaxParameterfv(GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMinmaxParameterfvEXT
void glGetMinmaxParameterfvEXT(GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMinmaxParameteriv
void glGetMinmaxParameteriv(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMinmaxParameterivEXT
void glGetMinmaxParameterivEXT(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMultiTexEnvfvEXT
void glGetMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMultiTexEnvivEXT
void glGetMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMultiTexGendvEXT
void glGetMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMultiTexGenfvEXT
void glGetMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMultiTexGenivEXT
void glGetMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMultiTexImageEXT
void glGetMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMultiTexLevelParameterfvEXT
void glGetMultiTexLevelParameterfvEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMultiTexLevelParameterivEXT
void glGetMultiTexLevelParameterivEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMultiTexParameterIivEXT
void glGetMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMultiTexParameterIuivEXT
void glGetMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMultiTexParameterfvEXT
void glGetMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMultiTexParameterivEXT
void glGetMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMultisamplefv
void glGetMultisamplefv(GLenum pname, GLuint index, GLfloat val) {
printf(gl.c);
}
#endif
#ifndef skip_glGetMultisamplefvNV
void glGetMultisamplefvNV(GLenum pname, GLuint index, GLfloat val) {
printf(gl.c);
}
#endif
#ifndef skip_glGetNamedBufferParameterivEXT
void glGetNamedBufferParameterivEXT(GLuint buffer, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetNamedBufferParameterui64vNV
void glGetNamedBufferParameterui64vNV(GLuint buffer, GLenum pname, GLuint64EXT params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetNamedBufferPointervEXT
void glGetNamedBufferPointervEXT(GLuint buffer, GLenum pname, GLvoid * params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetNamedBufferSubDataEXT
void glGetNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetNamedFramebufferAttachmentParameterivEXT
void glGetNamedFramebufferAttachmentParameterivEXT(GLuint framebuffer, GLenum attachment, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetNamedFramebufferParameterivEXT
void glGetNamedFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetNamedProgramLocalParameterIivEXT
void glGetNamedProgramLocalParameterIivEXT(GLuint program, GLenum target, GLuint index, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetNamedProgramLocalParameterIuivEXT
void glGetNamedProgramLocalParameterIuivEXT(GLuint program, GLenum target, GLuint index, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetNamedProgramLocalParameterdvEXT
void glGetNamedProgramLocalParameterdvEXT(GLuint program, GLenum target, GLuint index, GLdouble params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetNamedProgramLocalParameterfvEXT
void glGetNamedProgramLocalParameterfvEXT(GLuint program, GLenum target, GLuint index, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetNamedProgramStringEXT
void glGetNamedProgramStringEXT(GLuint program, GLenum target, GLenum pname, GLvoid string) {
printf(gl.c);
}
#endif
#ifndef skip_glGetNamedProgramivEXT
void glGetNamedProgramivEXT(GLuint program, GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetNamedRenderbufferParameterivEXT
void glGetNamedRenderbufferParameterivEXT(GLuint renderbuffer, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetNamedStringARB
void glGetNamedStringARB(GLint namelen, GLchar name, GLsizei bufSize, GLint stringlen, GLchar string) {
printf(gl.c);
}
#endif
#ifndef skip_glGetNamedStringivARB
void glGetNamedStringivARB(GLint namelen, GLchar name, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetObjectBufferfvATI
void glGetObjectBufferfvATI(GLuint buffer, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetObjectBufferivATI
void glGetObjectBufferivATI(GLuint buffer, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetObjectLabel
void glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei length, GLchar label) {
printf(gl.c);
}
#endif
#ifndef skip_glGetObjectParameterfvARB
void glGetObjectParameterfvARB(GLhandleARB obj, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetObjectParameterivAPPLE
void glGetObjectParameterivAPPLE(GLenum objectType, GLuint name, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetObjectParameterivARB
void glGetObjectParameterivARB(GLhandleARB obj, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetObjectPtrLabel
void glGetObjectPtrLabel(void * ptr, GLsizei bufSize, GLsizei length, GLchar label) {
printf(gl.c);
}
#endif
#ifndef skip_glGetOcclusionQueryivNV
void glGetOcclusionQueryivNV(GLuint id, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetOcclusionQueryuivNV
void glGetOcclusionQueryuivNV(GLuint id, GLenum pname, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPathColorGenfvNV
void glGetPathColorGenfvNV(GLenum color, GLenum pname, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPathColorGenivNV
void glGetPathColorGenivNV(GLenum color, GLenum pname, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPathCommandsNV
void glGetPathCommandsNV(GLuint path, GLubyte commands) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPathCoordsNV
void glGetPathCoordsNV(GLuint path, GLfloat coords) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPathDashArrayNV
void glGetPathDashArrayNV(GLuint path, GLfloat dashArray) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPathLengthNV
Float32 glGetPathLengthNV(GLuint path, GLsizei startSegment, GLsizei numSegments) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPathMetricRangeNV
void glGetPathMetricRangeNV(GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat metrics) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPathMetricsNV
void glGetPathMetricsNV(GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLsizei stride, GLfloat metrics) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPathParameterfvNV
void glGetPathParameterfvNV(GLuint path, GLenum pname, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPathParameterivNV
void glGetPathParameterivNV(GLuint path, GLenum pname, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPathSpacingNV
void glGetPathSpacingNV(GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat returnedSpacing) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPathTexGenfvNV
void glGetPathTexGenfvNV(GLenum texCoordSet, GLenum pname, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPathTexGenivNV
void glGetPathTexGenivNV(GLenum texCoordSet, GLenum pname, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPerfMonitorCounterDataAMD
void glGetPerfMonitorCounterDataAMD(GLuint monitor, GLenum pname, GLsizei dataSize, GLuint data, GLint bytesWritten) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPerfMonitorCounterInfoAMD
void glGetPerfMonitorCounterInfoAMD(GLuint group, GLuint counter, GLenum pname, GLvoid data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPerfMonitorCounterStringAMD
void glGetPerfMonitorCounterStringAMD(GLuint group, GLuint counter, GLsizei bufSize, GLsizei length, GLchar counterString) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPerfMonitorCountersAMD
void glGetPerfMonitorCountersAMD(GLuint group, GLint numCounters, GLint maxActiveCounters, GLsizei counterSize, GLuint counters) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPerfMonitorGroupStringAMD
void glGetPerfMonitorGroupStringAMD(GLuint group, GLsizei bufSize, GLsizei length, GLchar groupString) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPerfMonitorGroupsAMD
void glGetPerfMonitorGroupsAMD(GLint numGroups, GLsizei groupsSize, GLuint groups) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPixelMapfv
void glGetPixelMapfv(GLenum map, GLfloat values) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPixelMapuiv
void glGetPixelMapuiv(GLenum map, GLuint values) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPixelMapusv
void glGetPixelMapusv(GLenum map, GLushort values) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPixelMapxv
void glGetPixelMapxv(GLenum map, GLint size, GLfixed values) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPixelTexGenParameterfvSGIS
void glGetPixelTexGenParameterfvSGIS(GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPixelTexGenParameterivSGIS
void glGetPixelTexGenParameterivSGIS(GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPixelTransformParameterfvEXT
void glGetPixelTransformParameterfvEXT(GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPixelTransformParameterivEXT
void glGetPixelTransformParameterivEXT(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPointerIndexedvEXT
void glGetPointerIndexedvEXT(GLenum target, GLuint index, GLvoid * data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPointeri_vEXT
void glGetPointeri_vEXT(GLenum target, GLuint index, GLvoid * data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPointerv
void glGetPointerv(GLenum pname, GLvoid * params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPointervEXT
void glGetPointervEXT(GLenum pname, GLvoid * params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetPolygonStipple
void glGetPolygonStipple(GLubyte mask) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramBinary
void glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei length, GLenum binaryFormat, GLvoid binary) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramEnvParameterIivNV
void glGetProgramEnvParameterIivNV(GLenum target, GLuint index, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramEnvParameterIuivNV
void glGetProgramEnvParameterIuivNV(GLenum target, GLuint index, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramEnvParameterdvARB
void glGetProgramEnvParameterdvARB(GLenum target, GLuint index, GLdouble params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramEnvParameterfvARB
void glGetProgramEnvParameterfvARB(GLenum target, GLuint index, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramInfoLog
void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei length, GLchar infoLog) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramInterfaceiv
void glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramLocalParameterIivNV
void glGetProgramLocalParameterIivNV(GLenum target, GLuint index, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramLocalParameterIuivNV
void glGetProgramLocalParameterIuivNV(GLenum target, GLuint index, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramLocalParameterdvARB
void glGetProgramLocalParameterdvARB(GLenum target, GLuint index, GLdouble params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramLocalParameterfvARB
void glGetProgramLocalParameterfvARB(GLenum target, GLuint index, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramNamedParameterdvNV
void glGetProgramNamedParameterdvNV(GLuint id, GLsizei len, GLubyte name, GLdouble params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramNamedParameterfvNV
void glGetProgramNamedParameterfvNV(GLuint id, GLsizei len, GLubyte name, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramParameterdvNV
void glGetProgramParameterdvNV(GLenum target, GLuint index, GLenum pname, GLdouble params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramParameterfvNV
void glGetProgramParameterfvNV(GLenum target, GLuint index, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramPipelineInfoLog
void glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei length, GLchar infoLog) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramPipelineiv
void glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramResourceIndex
UInt32 glGetProgramResourceIndex(GLuint program, GLenum programInterface, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramResourceLocation
Int32 glGetProgramResourceLocation(GLuint program, GLenum programInterface, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramResourceLocationIndex
Int32 glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramResourceName
void glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei length, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramResourceiv
void glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, GLenum props, GLsizei bufSize, GLsizei length, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramStageiv
void glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint values) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramStringARB
void glGetProgramStringARB(GLenum target, GLenum pname, GLvoid string) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramStringNV
void glGetProgramStringNV(GLuint id, GLenum pname, GLubyte program) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramSubroutineParameteruivNV
void glGetProgramSubroutineParameteruivNV(GLenum target, GLuint index, GLuint param) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramiv
void glGetProgramiv(GLuint program, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramivARB
void glGetProgramivARB(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetProgramivNV
void glGetProgramivNV(GLuint id, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetQueryIndexediv
void glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetQueryObjecti64v
void glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64 params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetQueryObjecti64vEXT
void glGetQueryObjecti64vEXT(GLuint id, GLenum pname, GLint64EXT params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetQueryObjectiv
void glGetQueryObjectiv(GLuint id, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetQueryObjectivARB
void glGetQueryObjectivARB(GLuint id, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetQueryObjectui64v
void glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetQueryObjectui64vEXT
void glGetQueryObjectui64vEXT(GLuint id, GLenum pname, GLuint64EXT params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetQueryObjectuiv
void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetQueryObjectuivARB
void glGetQueryObjectuivARB(GLuint id, GLenum pname, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetQueryiv
void glGetQueryiv(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetQueryivARB
void glGetQueryivARB(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetRenderbufferParameteriv
void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetRenderbufferParameterivEXT
void glGetRenderbufferParameterivEXT(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetSamplerParameterIiv
void glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetSamplerParameterIuiv
void glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetSamplerParameterfv
void glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetSamplerParameteriv
void glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetSeparableFilter
void glGetSeparableFilter(GLenum target, GLenum format, GLenum type, GLvoid row, GLvoid column, GLvoid span) {
printf(gl.c);
}
#endif
#ifndef skip_glGetSeparableFilterEXT
void glGetSeparableFilterEXT(GLenum target, GLenum format, GLenum type, GLvoid row, GLvoid column, GLvoid span) {
printf(gl.c);
}
#endif
#ifndef skip_glGetShaderInfoLog
void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei length, GLchar infoLog) {
printf(gl.c);
}
#endif
#ifndef skip_glGetShaderPrecisionFormat
void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint range, GLint precision) {
printf(gl.c);
}
#endif
#ifndef skip_glGetShaderSource
void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei length, GLchar source) {
printf(gl.c);
}
#endif
#ifndef skip_glGetShaderSourceARB
void glGetShaderSourceARB(GLhandleARB obj, GLsizei maxLength, GLsizei length, GLcharARB source) {
printf(gl.c);
}
#endif
#ifndef skip_glGetShaderiv
void glGetShaderiv(GLuint shader, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetSharpenTexFuncSGIS
void glGetSharpenTexFuncSGIS(GLenum target, GLfloat points) {
printf(gl.c);
}
#endif
#ifndef skip_glGetString
String glGetString(GLenum name) {
printf(gl.c);
}
#endif
#ifndef skip_glGetStringi
String glGetStringi(GLenum name, GLuint index) {
printf(gl.c);
}
#endif
#ifndef skip_glGetSubroutineIndex
UInt32 glGetSubroutineIndex(GLuint program, GLenum shadertype, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glGetSubroutineUniformLocation
Int32 glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glGetSynciv
void glGetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei length, GLint values) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTexBumpParameterfvATI
void glGetTexBumpParameterfvATI(GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTexBumpParameterivATI
void glGetTexBumpParameterivATI(GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTexEnvfv
void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTexEnviv
void glGetTexEnviv(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTexEnvxvOES
void glGetTexEnvxvOES(GLenum target, GLenum pname, GLfixed params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTexFilterFuncSGIS
void glGetTexFilterFuncSGIS(GLenum target, GLenum filter, GLfloat weights) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTexGendv
void glGetTexGendv(GLenum coord, GLenum pname, GLdouble params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTexGenfv
void glGetTexGenfv(GLenum coord, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTexGeniv
void glGetTexGeniv(GLenum coord, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTexGenxvOES
void glGetTexGenxvOES(GLenum coord, GLenum pname, GLfixed params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTexImage
void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTexLevelParameterfv
void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTexLevelParameteriv
void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTexLevelParameterxvOES
void glGetTexLevelParameterxvOES(GLenum target, GLint level, GLenum pname, GLfixed params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTexParameterIiv
void glGetTexParameterIiv(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTexParameterIivEXT
void glGetTexParameterIivEXT(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTexParameterIuiv
void glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTexParameterIuivEXT
void glGetTexParameterIuivEXT(GLenum target, GLenum pname, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTexParameterPointervAPPLE
void glGetTexParameterPointervAPPLE(GLenum target, GLenum pname, GLvoid * params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTexParameterfv
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTexParameteriv
void glGetTexParameteriv(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTexParameterxvOES
void glGetTexParameterxvOES(GLenum target, GLenum pname, GLfixed params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTextureHandleNV
UInt64 glGetTextureHandleNV(GLuint texture) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTextureImageEXT
void glGetTextureImageEXT(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTextureLevelParameterfvEXT
void glGetTextureLevelParameterfvEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTextureLevelParameterivEXT
void glGetTextureLevelParameterivEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTextureParameterIivEXT
void glGetTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTextureParameterIuivEXT
void glGetTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTextureParameterfvEXT
void glGetTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTextureParameterivEXT
void glGetTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTextureSamplerHandleNV
UInt64 glGetTextureSamplerHandleNV(GLuint texture, GLuint sampler) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTrackMatrixivNV
void glGetTrackMatrixivNV(GLenum target, GLuint address, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTransformFeedbackVarying
void glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLsizei size, GLenum type, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTransformFeedbackVaryingEXT
void glGetTransformFeedbackVaryingEXT(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLsizei size, GLenum type, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glGetTransformFeedbackVaryingNV
void glGetTransformFeedbackVaryingNV(GLuint program, GLuint index, GLint location) {
printf(gl.c);
}
#endif
#ifndef skip_glGetUniformBlockIndex
UInt32 glGetUniformBlockIndex(GLuint program, GLchar uniformBlockName) {
printf(gl.c);
}
#endif
#ifndef skip_glGetUniformBufferSizeEXT
Int32 glGetUniformBufferSizeEXT(GLuint program, GLint location) {
printf(gl.c);
}
#endif
#ifndef skip_glGetUniformIndices
void glGetUniformIndices(GLuint program, GLsizei uniformCount, GLchar*const uniformNames, GLuint uniformIndices) {
printf(gl.c);
}
#endif
#ifndef skip_glGetUniformLocation
Int32 glGetUniformLocation(GLuint program, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glGetUniformLocationARB
Int32 glGetUniformLocationARB(GLhandleARB programObj, GLcharARB name) {
printf(gl.c);
}
#endif
#ifndef skip_glGetUniformOffsetEXT
BufferOffset glGetUniformOffsetEXT(GLuint program, GLint location) {
printf(gl.c);
}
#endif
#ifndef skip_glGetUniformSubroutineuiv
void glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetUniformdv
void glGetUniformdv(GLuint program, GLint location, GLdouble params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetUniformfv
void glGetUniformfv(GLuint program, GLint location, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetUniformfvARB
void glGetUniformfvARB(GLhandleARB programObj, GLint location, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetUniformi64vNV
void glGetUniformi64vNV(GLuint program, GLint location, GLint64EXT params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetUniformiv
void glGetUniformiv(GLuint program, GLint location, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetUniformivARB
void glGetUniformivARB(GLhandleARB programObj, GLint location, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetUniformui64vNV
void glGetUniformui64vNV(GLuint program, GLint location, GLuint64EXT params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetUniformuiv
void glGetUniformuiv(GLuint program, GLint location, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetUniformuivEXT
void glGetUniformuivEXT(GLuint program, GLint location, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVariantArrayObjectfvATI
void glGetVariantArrayObjectfvATI(GLuint id, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVariantArrayObjectivATI
void glGetVariantArrayObjectivATI(GLuint id, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVariantBooleanvEXT
void glGetVariantBooleanvEXT(GLuint id, GLenum value, GLboolean data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVariantFloatvEXT
void glGetVariantFloatvEXT(GLuint id, GLenum value, GLfloat data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVariantIntegervEXT
void glGetVariantIntegervEXT(GLuint id, GLenum value, GLint data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVariantPointervEXT
void glGetVariantPointervEXT(GLuint id, GLenum value, GLvoid * data) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVaryingLocationNV
Int32 glGetVaryingLocationNV(GLuint program, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexArrayIntegeri_vEXT
void glGetVertexArrayIntegeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexArrayIntegervEXT
void glGetVertexArrayIntegervEXT(GLuint vaobj, GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexArrayPointeri_vEXT
void glGetVertexArrayPointeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, GLvoid * param) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexArrayPointervEXT
void glGetVertexArrayPointervEXT(GLuint vaobj, GLenum pname, GLvoid * param) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexAttribArrayObjectfvATI
void glGetVertexAttribArrayObjectfvATI(GLuint index, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexAttribArrayObjectivATI
void glGetVertexAttribArrayObjectivATI(GLuint index, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexAttribIiv
void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexAttribIivEXT
void glGetVertexAttribIivEXT(GLuint index, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexAttribIuiv
void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexAttribIuivEXT
void glGetVertexAttribIuivEXT(GLuint index, GLenum pname, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexAttribLdv
void glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexAttribLdvEXT
void glGetVertexAttribLdvEXT(GLuint index, GLenum pname, GLdouble params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexAttribLi64vNV
void glGetVertexAttribLi64vNV(GLuint index, GLenum pname, GLint64EXT params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexAttribLui64vNV
void glGetVertexAttribLui64vNV(GLuint index, GLenum pname, GLuint64EXT params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexAttribPointerv
void glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid * pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexAttribPointervARB
void glGetVertexAttribPointervARB(GLuint index, GLenum pname, GLvoid * pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexAttribPointervNV
void glGetVertexAttribPointervNV(GLuint index, GLenum pname, GLvoid * pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexAttribdv
void glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexAttribdvARB
void glGetVertexAttribdvARB(GLuint index, GLenum pname, GLdouble params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexAttribdvNV
void glGetVertexAttribdvNV(GLuint index, GLenum pname, GLdouble params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexAttribfv
void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexAttribfvARB
void glGetVertexAttribfvARB(GLuint index, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexAttribfvNV
void glGetVertexAttribfvNV(GLuint index, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexAttribiv
void glGetVertexAttribiv(GLuint index, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexAttribivARB
void glGetVertexAttribivARB(GLuint index, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVertexAttribivNV
void glGetVertexAttribivNV(GLuint index, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVideoCaptureStreamdvNV
void glGetVideoCaptureStreamdvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVideoCaptureStreamfvNV
void glGetVideoCaptureStreamfvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVideoCaptureStreamivNV
void glGetVideoCaptureStreamivNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVideoCaptureivNV
void glGetVideoCaptureivNV(GLuint video_capture_slot, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVideoi64vNV
void glGetVideoi64vNV(GLuint video_slot, GLenum pname, GLint64EXT params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVideoivNV
void glGetVideoivNV(GLuint video_slot, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVideoui64vNV
void glGetVideoui64vNV(GLuint video_slot, GLenum pname, GLuint64EXT params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetVideouivNV
void glGetVideouivNV(GLuint video_slot, GLenum pname, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetnColorTableARB
void glGetnColorTableARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, GLvoid table) {
printf(gl.c);
}
#endif
#ifndef skip_glGetnCompressedTexImageARB
void glGetnCompressedTexImageARB(GLenum target, GLint lod, GLsizei bufSize, GLvoid img) {
printf(gl.c);
}
#endif
#ifndef skip_glGetnConvolutionFilterARB
void glGetnConvolutionFilterARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, GLvoid image) {
printf(gl.c);
}
#endif
#ifndef skip_glGetnHistogramARB
void glGetnHistogramARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, GLvoid values) {
printf(gl.c);
}
#endif
#ifndef skip_glGetnMapdvARB
void glGetnMapdvARB(GLenum target, GLenum query, GLsizei bufSize, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glGetnMapfvARB
void glGetnMapfvARB(GLenum target, GLenum query, GLsizei bufSize, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glGetnMapivARB
void glGetnMapivARB(GLenum target, GLenum query, GLsizei bufSize, GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glGetnMinmaxARB
void glGetnMinmaxARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, GLvoid values) {
printf(gl.c);
}
#endif
#ifndef skip_glGetnPixelMapfvARB
void glGetnPixelMapfvARB(GLenum map, GLsizei bufSize, GLfloat values) {
printf(gl.c);
}
#endif
#ifndef skip_glGetnPixelMapuivARB
void glGetnPixelMapuivARB(GLenum map, GLsizei bufSize, GLuint values) {
printf(gl.c);
}
#endif
#ifndef skip_glGetnPixelMapusvARB
void glGetnPixelMapusvARB(GLenum map, GLsizei bufSize, GLushort values) {
printf(gl.c);
}
#endif
#ifndef skip_glGetnPolygonStippleARB
void glGetnPolygonStippleARB(GLsizei bufSize, GLubyte pattern) {
printf(gl.c);
}
#endif
#ifndef skip_glGetnSeparableFilterARB
void glGetnSeparableFilterARB(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, GLvoid row, GLsizei columnBufSize, GLvoid column, GLvoid span) {
printf(gl.c);
}
#endif
#ifndef skip_glGetnTexImageARB
void glGetnTexImageARB(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid img) {
printf(gl.c);
}
#endif
#ifndef skip_glGetnUniformdvARB
void glGetnUniformdvARB(GLuint program, GLint location, GLsizei bufSize, GLdouble params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetnUniformfvARB
void glGetnUniformfvARB(GLuint program, GLint location, GLsizei bufSize, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetnUniformivARB
void glGetnUniformivARB(GLuint program, GLint location, GLsizei bufSize, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGetnUniformuivARB
void glGetnUniformuivARB(GLuint program, GLint location, GLsizei bufSize, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glGlobalAlphaFactorbSUN
void glGlobalAlphaFactorbSUN(GLbyte factor) {
printf(gl.c);
}
#endif
#ifndef skip_glGlobalAlphaFactordSUN
void glGlobalAlphaFactordSUN(GLdouble factor) {
printf(gl.c);
}
#endif
#ifndef skip_glGlobalAlphaFactorfSUN
void glGlobalAlphaFactorfSUN(GLfloat factor) {
printf(gl.c);
}
#endif
#ifndef skip_glGlobalAlphaFactoriSUN
void glGlobalAlphaFactoriSUN(GLint factor) {
printf(gl.c);
}
#endif
#ifndef skip_glGlobalAlphaFactorsSUN
void glGlobalAlphaFactorsSUN(GLshort factor) {
printf(gl.c);
}
#endif
#ifndef skip_glGlobalAlphaFactorubSUN
void glGlobalAlphaFactorubSUN(GLubyte factor) {
printf(gl.c);
}
#endif
#ifndef skip_glGlobalAlphaFactoruiSUN
void glGlobalAlphaFactoruiSUN(GLuint factor) {
printf(gl.c);
}
#endif
#ifndef skip_glGlobalAlphaFactorusSUN
void glGlobalAlphaFactorusSUN(GLushort factor) {
printf(gl.c);
}
#endif
#ifndef skip_glHint
void glHint(GLenum target, GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glHintPGI
void glHintPGI(GLenum target, GLint mode) {
printf(gl.c);
}
#endif
#ifndef skip_glHistogram
void glHistogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink) {
printf(gl.c);
}
#endif
#ifndef skip_glHistogramEXT
void glHistogramEXT(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink) {
printf(gl.c);
}
#endif
#ifndef skip_glIglooInterfaceSGIX
void glIglooInterfaceSGIX(GLenum pname, GLvoid params) {
printf(gl.c);
}
#endif
#ifndef skip_glImageTransformParameterfHP
void glImageTransformParameterfHP(GLenum target, GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glImageTransformParameterfvHP
void glImageTransformParameterfvHP(GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glImageTransformParameteriHP
void glImageTransformParameteriHP(GLenum target, GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glImageTransformParameterivHP
void glImageTransformParameterivHP(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glImportSyncEXT
sync glImportSyncEXT(GLenum external_sync_type, GLintptr external_sync, GLbitfield flags) {
printf(gl.c);
}
#endif
#ifndef skip_glIndexFormatNV
void glIndexFormatNV(GLenum type, GLsizei stride) {
printf(gl.c);
}
#endif
#ifndef skip_glIndexFuncEXT
void glIndexFuncEXT(GLenum func, GLclampf ref) {
printf(gl.c);
}
#endif
#ifndef skip_glIndexMask
void glIndexMask(GLuint mask) {
printf(gl.c);
}
#endif
#ifndef skip_glIndexMaterialEXT
void glIndexMaterialEXT(GLenum face, GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glIndexPointer
void glIndexPointer(GLenum type, GLsizei stride, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glIndexPointerEXT
void glIndexPointerEXT(GLenum type, GLsizei stride, GLsizei count, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glIndexPointerListIBM
void glIndexPointerListIBM(GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride) {
printf(gl.c);
}
#endif
#ifndef skip_glIndexd
void glIndexd(GLdouble c) {
printf(gl.c);
}
#endif
#ifndef skip_glIndexdv
void glIndexdv(GLdouble c) {
printf(gl.c);
}
#endif
#ifndef skip_glIndexf
void glIndexf(GLfloat c) {
printf(gl.c);
}
#endif
#ifndef skip_glIndexfv
void glIndexfv(GLfloat c) {
printf(gl.c);
}
#endif
#ifndef skip_glIndexi
void glIndexi(GLint c) {
printf(gl.c);
}
#endif
#ifndef skip_glIndexiv
void glIndexiv(GLint c) {
printf(gl.c);
}
#endif
#ifndef skip_glIndexs
void glIndexs(GLshort c) {
printf(gl.c);
}
#endif
#ifndef skip_glIndexsv
void glIndexsv(GLshort c) {
printf(gl.c);
}
#endif
#ifndef skip_glIndexub
void glIndexub(GLubyte c) {
printf(gl.c);
}
#endif
#ifndef skip_glIndexubv
void glIndexubv(GLubyte c) {
printf(gl.c);
}
#endif
#ifndef skip_glIndexxOES
void glIndexxOES(GLfixed component) {
printf(gl.c);
}
#endif
#ifndef skip_glIndexxvOES
void glIndexxvOES(GLfixed component) {
printf(gl.c);
}
#endif
#ifndef skip_glInitNames
void glInitNames() {
printf(gl.c);
}
#endif
#ifndef skip_glInsertComponentEXT
void glInsertComponentEXT(GLuint res, GLuint src, GLuint num) {
printf(gl.c);
}
#endif
#ifndef skip_glInstrumentsBufferSGIX
void glInstrumentsBufferSGIX(GLsizei size, GLint buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glInterleavedArrays
void glInterleavedArrays(GLenum format, GLsizei stride, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glInterpolatePathsNV
void glInterpolatePathsNV(GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight) {
printf(gl.c);
}
#endif
#ifndef skip_glInvalidateBufferData
void glInvalidateBufferData(GLuint buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glInvalidateBufferSubData
void glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length) {
printf(gl.c);
}
#endif
#ifndef skip_glInvalidateFramebuffer
void glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, GLenum attachments) {
printf(gl.c);
}
#endif
#ifndef skip_glInvalidateSubFramebuffer
void glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, GLenum attachments, GLint x, GLint y, GLsizei width, GLsizei height) {
printf(gl.c);
}
#endif
#ifndef skip_glInvalidateTexImage
void glInvalidateTexImage(GLuint texture, GLint level) {
printf(gl.c);
}
#endif
#ifndef skip_glInvalidateTexSubImage
void glInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth) {
printf(gl.c);
}
#endif
#ifndef skip_glIsAsyncMarkerSGIX
Boolean glIsAsyncMarkerSGIX(GLuint marker) {
printf(gl.c);
}
#endif
#ifndef skip_glIsBuffer
Boolean glIsBuffer(GLuint buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glIsBufferARB
Boolean glIsBufferARB(GLuint buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glIsBufferResidentNV
Boolean glIsBufferResidentNV(GLenum target) {
printf(gl.c);
}
#endif
#ifndef skip_glIsEnabled
Boolean glIsEnabled(GLenum cap) {
printf(gl.c);
}
#endif
#ifndef skip_glIsEnabledIndexedEXT
Boolean glIsEnabledIndexedEXT(GLenum target, GLuint index) {
printf(gl.c);
}
#endif
#ifndef skip_glIsEnabledi
Boolean glIsEnabledi(GLenum target, GLuint index) {
printf(gl.c);
}
#endif
#ifndef skip_glIsFenceAPPLE
Boolean glIsFenceAPPLE(GLuint fence) {
printf(gl.c);
}
#endif
#ifndef skip_glIsFenceNV
Boolean glIsFenceNV(GLuint fence) {
printf(gl.c);
}
#endif
#ifndef skip_glIsFramebuffer
Boolean glIsFramebuffer(GLuint framebuffer) {
printf(gl.c);
}
#endif
#ifndef skip_glIsFramebufferEXT
Boolean glIsFramebufferEXT(GLuint framebuffer) {
printf(gl.c);
}
#endif
#ifndef skip_glIsImageHandleResidentNV
Boolean glIsImageHandleResidentNV(GLuint64 handle) {
printf(gl.c);
}
#endif
#ifndef skip_glIsList
Boolean glIsList(GLuint list) {
printf(gl.c);
}
#endif
#ifndef skip_glIsNameAMD
Boolean glIsNameAMD(GLenum identifier, GLuint name) {
printf(gl.c);
}
#endif
#ifndef skip_glIsNamedBufferResidentNV
Boolean glIsNamedBufferResidentNV(GLuint buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glIsNamedStringARB
Boolean glIsNamedStringARB(GLint namelen, GLchar name) {
printf(gl.c);
}
#endif
#ifndef skip_glIsObjectBufferATI
Boolean glIsObjectBufferATI(GLuint buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glIsOcclusionQueryNV
Boolean glIsOcclusionQueryNV(GLuint id) {
printf(gl.c);
}
#endif
#ifndef skip_glIsPathNV
Boolean glIsPathNV(GLuint path) {
printf(gl.c);
}
#endif
#ifndef skip_glIsPointInFillPathNV
Boolean glIsPointInFillPathNV(GLuint path, GLuint mask, GLfloat x, GLfloat y) {
printf(gl.c);
}
#endif
#ifndef skip_glIsPointInStrokePathNV
Boolean glIsPointInStrokePathNV(GLuint path, GLfloat x, GLfloat y) {
printf(gl.c);
}
#endif
#ifndef skip_glIsProgram
Boolean glIsProgram(GLuint program) {
printf(gl.c);
}
#endif
#ifndef skip_glIsProgramARB
Boolean glIsProgramARB(GLuint program) {
printf(gl.c);
}
#endif
#ifndef skip_glIsProgramNV
Boolean glIsProgramNV(GLuint id) {
printf(gl.c);
}
#endif
#ifndef skip_glIsProgramPipeline
Boolean glIsProgramPipeline(GLuint pipeline) {
printf(gl.c);
}
#endif
#ifndef skip_glIsQuery
Boolean glIsQuery(GLuint id) {
printf(gl.c);
}
#endif
#ifndef skip_glIsQueryARB
Boolean glIsQueryARB(GLuint id) {
printf(gl.c);
}
#endif
#ifndef skip_glIsRenderbuffer
Boolean glIsRenderbuffer(GLuint renderbuffer) {
printf(gl.c);
}
#endif
#ifndef skip_glIsRenderbufferEXT
Boolean glIsRenderbufferEXT(GLuint renderbuffer) {
printf(gl.c);
}
#endif
#ifndef skip_glIsSampler
Boolean glIsSampler(GLuint sampler) {
printf(gl.c);
}
#endif
#ifndef skip_glIsShader
Boolean glIsShader(GLuint shader) {
printf(gl.c);
}
#endif
#ifndef skip_glIsSync
Boolean glIsSync(GLsync sync) {
printf(gl.c);
}
#endif
#ifndef skip_glIsTexture
Boolean glIsTexture(GLuint texture) {
printf(gl.c);
}
#endif
#ifndef skip_glIsTextureEXT
Boolean glIsTextureEXT(GLuint texture) {
printf(gl.c);
}
#endif
#ifndef skip_glIsTextureHandleResidentNV
Boolean glIsTextureHandleResidentNV(GLuint64 handle) {
printf(gl.c);
}
#endif
#ifndef skip_glIsTransformFeedback
Boolean glIsTransformFeedback(GLuint id) {
printf(gl.c);
}
#endif
#ifndef skip_glIsTransformFeedbackNV
Boolean glIsTransformFeedbackNV(GLuint id) {
printf(gl.c);
}
#endif
#ifndef skip_glIsVariantEnabledEXT
Boolean glIsVariantEnabledEXT(GLuint id, GLenum cap) {
printf(gl.c);
}
#endif
#ifndef skip_glIsVertexArray
Boolean glIsVertexArray(GLuint array) {
printf(gl.c);
}
#endif
#ifndef skip_glIsVertexArrayAPPLE
Boolean glIsVertexArrayAPPLE(GLuint array) {
printf(gl.c);
}
#endif
#ifndef skip_glIsVertexAttribEnabledAPPLE
Boolean glIsVertexAttribEnabledAPPLE(GLuint index, GLenum pname) {
printf(gl.c);
}
#endif
#ifndef skip_glLightEnviSGIX
void glLightEnviSGIX(GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glLightModelf
void glLightModelf(GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glLightModelfv
void glLightModelfv(GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glLightModeli
void glLightModeli(GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glLightModeliv
void glLightModeliv(GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glLightModelxOES
void glLightModelxOES(GLenum pname, GLfixed param) {
printf(gl.c);
}
#endif
#ifndef skip_glLightModelxvOES
void glLightModelxvOES(GLenum pname, GLfixed param) {
printf(gl.c);
}
#endif
#ifndef skip_glLightf
void glLightf(GLenum light, GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glLightfv
void glLightfv(GLenum light, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glLighti
void glLighti(GLenum light, GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glLightiv
void glLightiv(GLenum light, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glLightxOES
void glLightxOES(GLenum light, GLenum pname, GLfixed param) {
printf(gl.c);
}
#endif
#ifndef skip_glLightxvOES
void glLightxvOES(GLenum light, GLenum pname, GLfixed params) {
printf(gl.c);
}
#endif
#ifndef skip_glLineStipple
void glLineStipple(GLint factor, GLushort pattern) {
printf(gl.c);
}
#endif
#ifndef skip_glLineWidth
void glLineWidth(GLfloat width) {
printf(gl.c);
}
#endif
#ifndef skip_glLineWidthxOES
void glLineWidthxOES(GLfixed width) {
printf(gl.c);
}
#endif
#ifndef skip_glLinkProgram
void glLinkProgram(GLuint program) {
printf(gl.c);
}
#endif
#ifndef skip_glLinkProgramARB
void glLinkProgramARB(GLhandleARB programObj) {
printf(gl.c);
}
#endif
#ifndef skip_glListBase
void glListBase(GLuint base) {
printf(gl.c);
}
#endif
#ifndef skip_glListParameterfSGIX
void glListParameterfSGIX(GLuint list, GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glListParameterfvSGIX
void glListParameterfvSGIX(GLuint list, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glListParameteriSGIX
void glListParameteriSGIX(GLuint list, GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glListParameterivSGIX
void glListParameterivSGIX(GLuint list, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glLoadIdentity
void glLoadIdentity() {
printf(gl.c);
}
#endif
#ifndef skip_glLoadIdentityDeformationMapSGIX
void glLoadIdentityDeformationMapSGIX(GLbitfield mask) {
printf(gl.c);
}
#endif
#ifndef skip_glLoadMatrixd
void glLoadMatrixd(GLdouble m) {
printf(gl.c);
}
#endif
#ifndef skip_glLoadMatrixf
void glLoadMatrixf(GLfloat m) {
printf(gl.c);
}
#endif
#ifndef skip_glLoadMatrixxOES
void glLoadMatrixxOES(GLfixed m) {
printf(gl.c);
}
#endif
#ifndef skip_glLoadName
void glLoadName(GLuint name) {
printf(gl.c);
}
#endif
#ifndef skip_glLoadProgramNV
void glLoadProgramNV(GLenum target, GLuint id, GLsizei len, GLubyte program) {
printf(gl.c);
}
#endif
#ifndef skip_glLoadTransposeMatrixd
void glLoadTransposeMatrixd(GLdouble m) {
printf(gl.c);
}
#endif
#ifndef skip_glLoadTransposeMatrixdARB
void glLoadTransposeMatrixdARB(GLdouble m) {
printf(gl.c);
}
#endif
#ifndef skip_glLoadTransposeMatrixf
void glLoadTransposeMatrixf(GLfloat m) {
printf(gl.c);
}
#endif
#ifndef skip_glLoadTransposeMatrixfARB
void glLoadTransposeMatrixfARB(GLfloat m) {
printf(gl.c);
}
#endif
#ifndef skip_glLoadTransposeMatrixxOES
void glLoadTransposeMatrixxOES(GLfixed m) {
printf(gl.c);
}
#endif
#ifndef skip_glLockArraysEXT
void glLockArraysEXT(GLint first, GLsizei count) {
printf(gl.c);
}
#endif
#ifndef skip_glLogicOp
void glLogicOp(GLenum opcode) {
printf(gl.c);
}
#endif
#ifndef skip_glMakeBufferNonResidentNV
void glMakeBufferNonResidentNV(GLenum target) {
printf(gl.c);
}
#endif
#ifndef skip_glMakeBufferResidentNV
void glMakeBufferResidentNV(GLenum target, GLenum access) {
printf(gl.c);
}
#endif
#ifndef skip_glMakeImageHandleNonResidentNV
void glMakeImageHandleNonResidentNV(GLuint64 handle) {
printf(gl.c);
}
#endif
#ifndef skip_glMakeImageHandleResidentNV
void glMakeImageHandleResidentNV(GLuint64 handle, GLenum access) {
printf(gl.c);
}
#endif
#ifndef skip_glMakeNamedBufferNonResidentNV
void glMakeNamedBufferNonResidentNV(GLuint buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glMakeNamedBufferResidentNV
void glMakeNamedBufferResidentNV(GLuint buffer, GLenum access) {
printf(gl.c);
}
#endif
#ifndef skip_glMakeTextureHandleNonResidentNV
void glMakeTextureHandleNonResidentNV(GLuint64 handle) {
printf(gl.c);
}
#endif
#ifndef skip_glMakeTextureHandleResidentNV
void glMakeTextureHandleResidentNV(GLuint64 handle) {
printf(gl.c);
}
#endif
#ifndef skip_glMap1d
void glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, GLdouble points) {
printf(gl.c);
}
#endif
#ifndef skip_glMap1f
void glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, GLfloat points) {
printf(gl.c);
}
#endif
#ifndef skip_glMap1xOES
void glMap1xOES(GLenum target, GLfixed u1, GLfixed u2, GLint stride, GLint order, GLfixed points) {
printf(gl.c);
}
#endif
#ifndef skip_glMap2d
void glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble points) {
printf(gl.c);
}
#endif
#ifndef skip_glMap2f
void glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat points) {
printf(gl.c);
}
#endif
#ifndef skip_glMap2xOES
void glMap2xOES(GLenum target, GLfixed u1, GLfixed u2, GLint ustride, GLint uorder, GLfixed v1, GLfixed v2, GLint vstride, GLint vorder, GLfixed points) {
printf(gl.c);
}
#endif
#ifndef skip_glMapBuffer
VoidPointer glMapBuffer(GLenum target, GLenum access) {
printf(gl.c);
}
#endif
#ifndef skip_glMapBufferARB
VoidPointer glMapBufferARB(GLenum target, GLenum access) {
printf(gl.c);
}
#endif
#ifndef skip_glMapBufferRange
VoidPointer glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) {
printf(gl.c);
}
#endif
#ifndef skip_glMapControlPointsNV
void glMapControlPointsNV(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLint uorder, GLint vorder, GLboolean packed, GLvoid points) {
printf(gl.c);
}
#endif
#ifndef skip_glMapGrid1d
void glMapGrid1d(GLint un, GLdouble u1, GLdouble u2) {
printf(gl.c);
}
#endif
#ifndef skip_glMapGrid1f
void glMapGrid1f(GLint un, GLfloat u1, GLfloat u2) {
printf(gl.c);
}
#endif
#ifndef skip_glMapGrid1xOES
void glMapGrid1xOES(GLint n, GLfixed u1, GLfixed u2) {
printf(gl.c);
}
#endif
#ifndef skip_glMapGrid2d
void glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2) {
printf(gl.c);
}
#endif
#ifndef skip_glMapGrid2f
void glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2) {
printf(gl.c);
}
#endif
#ifndef skip_glMapGrid2xOES
void glMapGrid2xOES(GLint n, GLfixed u1, GLfixed u2, GLfixed v1, GLfixed v2) {
printf(gl.c);
}
#endif
#ifndef skip_glMapNamedBufferEXT
VoidPointer glMapNamedBufferEXT(GLuint buffer, GLenum access) {
printf(gl.c);
}
#endif
#ifndef skip_glMapNamedBufferRangeEXT
VoidPointer glMapNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access) {
printf(gl.c);
}
#endif
#ifndef skip_glMapObjectBufferATI
VoidPointer glMapObjectBufferATI(GLuint buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glMapParameterfvNV
void glMapParameterfvNV(GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glMapParameterivNV
void glMapParameterivNV(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glMapTexture2DINTEL
VoidPointer glMapTexture2DINTEL(GLuint texture, GLint level, GLbitfield access, GLint stride, GLenum layout) {
printf(gl.c);
}
#endif
#ifndef skip_glMapVertexAttrib1dAPPLE
void glMapVertexAttrib1dAPPLE(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint stride, GLint order, GLdouble points) {
printf(gl.c);
}
#endif
#ifndef skip_glMapVertexAttrib1fAPPLE
void glMapVertexAttrib1fAPPLE(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint stride, GLint order, GLfloat points) {
printf(gl.c);
}
#endif
#ifndef skip_glMapVertexAttrib2dAPPLE
void glMapVertexAttrib2dAPPLE(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble points) {
printf(gl.c);
}
#endif
#ifndef skip_glMapVertexAttrib2fAPPLE
void glMapVertexAttrib2fAPPLE(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat points) {
printf(gl.c);
}
#endif
#ifndef skip_glMaterialf
void glMaterialf(GLenum face, GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glMaterialfv
void glMaterialfv(GLenum face, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glMateriali
void glMateriali(GLenum face, GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glMaterialiv
void glMaterialiv(GLenum face, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glMaterialxOES
void glMaterialxOES(GLenum face, GLenum pname, GLfixed param) {
printf(gl.c);
}
#endif
#ifndef skip_glMaterialxvOES
void glMaterialxvOES(GLenum face, GLenum pname, GLfixed param) {
printf(gl.c);
}
#endif
#ifndef skip_glMatrixFrustumEXT
void glMatrixFrustumEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
printf(gl.c);
}
#endif
#ifndef skip_glMatrixIndexPointerARB
void glMatrixIndexPointerARB(GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glMatrixIndexubvARB
void glMatrixIndexubvARB(GLint size, GLubyte indices) {
printf(gl.c);
}
#endif
#ifndef skip_glMatrixIndexuivARB
void glMatrixIndexuivARB(GLint size, GLuint indices) {
printf(gl.c);
}
#endif
#ifndef skip_glMatrixIndexusvARB
void glMatrixIndexusvARB(GLint size, GLushort indices) {
printf(gl.c);
}
#endif
#ifndef skip_glMatrixLoadIdentityEXT
void glMatrixLoadIdentityEXT(GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glMatrixLoadTransposedEXT
void glMatrixLoadTransposedEXT(GLenum mode, GLdouble m) {
printf(gl.c);
}
#endif
#ifndef skip_glMatrixLoadTransposefEXT
void glMatrixLoadTransposefEXT(GLenum mode, GLfloat m) {
printf(gl.c);
}
#endif
#ifndef skip_glMatrixLoaddEXT
void glMatrixLoaddEXT(GLenum mode, GLdouble m) {
printf(gl.c);
}
#endif
#ifndef skip_glMatrixLoadfEXT
void glMatrixLoadfEXT(GLenum mode, GLfloat m) {
printf(gl.c);
}
#endif
#ifndef skip_glMatrixMode
void glMatrixMode(GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glMatrixMultTransposedEXT
void glMatrixMultTransposedEXT(GLenum mode, GLdouble m) {
printf(gl.c);
}
#endif
#ifndef skip_glMatrixMultTransposefEXT
void glMatrixMultTransposefEXT(GLenum mode, GLfloat m) {
printf(gl.c);
}
#endif
#ifndef skip_glMatrixMultdEXT
void glMatrixMultdEXT(GLenum mode, GLdouble m) {
printf(gl.c);
}
#endif
#ifndef skip_glMatrixMultfEXT
void glMatrixMultfEXT(GLenum mode, GLfloat m) {
printf(gl.c);
}
#endif
#ifndef skip_glMatrixOrthoEXT
void glMatrixOrthoEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
printf(gl.c);
}
#endif
#ifndef skip_glMatrixPopEXT
void glMatrixPopEXT(GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glMatrixPushEXT
void glMatrixPushEXT(GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glMatrixRotatedEXT
void glMatrixRotatedEXT(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
printf(gl.c);
}
#endif
#ifndef skip_glMatrixRotatefEXT
void glMatrixRotatefEXT(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glMatrixScaledEXT
void glMatrixScaledEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z) {
printf(gl.c);
}
#endif
#ifndef skip_glMatrixScalefEXT
void glMatrixScalefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glMatrixTranslatedEXT
void glMatrixTranslatedEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z) {
printf(gl.c);
}
#endif
#ifndef skip_glMatrixTranslatefEXT
void glMatrixTranslatefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glMemoryBarrier
void glMemoryBarrier(GLbitfield barriers) {
printf(gl.c);
}
#endif
#ifndef skip_glMemoryBarrierEXT
void glMemoryBarrierEXT(GLbitfield barriers) {
printf(gl.c);
}
#endif
#ifndef skip_glMinSampleShading
void glMinSampleShading(GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glMinSampleShadingARB
void glMinSampleShadingARB(GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glMinmax
void glMinmax(GLenum target, GLenum internalformat, GLboolean sink) {
printf(gl.c);
}
#endif
#ifndef skip_glMinmaxEXT
void glMinmaxEXT(GLenum target, GLenum internalformat, GLboolean sink) {
printf(gl.c);
}
#endif
#ifndef skip_glMultMatrixd
void glMultMatrixd(GLdouble m) {
printf(gl.c);
}
#endif
#ifndef skip_glMultMatrixf
void glMultMatrixf(GLfloat m) {
printf(gl.c);
}
#endif
#ifndef skip_glMultMatrixxOES
void glMultMatrixxOES(GLfixed m) {
printf(gl.c);
}
#endif
#ifndef skip_glMultTransposeMatrixd
void glMultTransposeMatrixd(GLdouble m) {
printf(gl.c);
}
#endif
#ifndef skip_glMultTransposeMatrixdARB
void glMultTransposeMatrixdARB(GLdouble m) {
printf(gl.c);
}
#endif
#ifndef skip_glMultTransposeMatrixf
void glMultTransposeMatrixf(GLfloat m) {
printf(gl.c);
}
#endif
#ifndef skip_glMultTransposeMatrixfARB
void glMultTransposeMatrixfARB(GLfloat m) {
printf(gl.c);
}
#endif
#ifndef skip_glMultTransposeMatrixxOES
void glMultTransposeMatrixxOES(GLfixed m) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiDrawArrays
void glMultiDrawArrays(GLenum mode, GLint first, GLsizei count, GLsizei drawcount) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiDrawArraysEXT
void glMultiDrawArraysEXT(GLenum mode, GLint first, GLsizei count, GLsizei primcount) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiDrawArraysIndirect
void glMultiDrawArraysIndirect(GLenum mode, void * indirect, GLsizei drawcount, GLsizei stride) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiDrawArraysIndirectAMD
void glMultiDrawArraysIndirectAMD(GLenum mode, GLvoid indirect, GLsizei primcount, GLsizei stride) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiDrawElementArrayAPPLE
void glMultiDrawElementArrayAPPLE(GLenum mode, GLint first, GLsizei count, GLsizei primcount) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiDrawElements
void glMultiDrawElements(GLenum mode, GLsizei count, GLenum type, GLvoid*const indices, GLsizei drawcount) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiDrawElementsBaseVertex
void glMultiDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid*const indices, GLsizei drawcount, GLint basevertex) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiDrawElementsEXT
void glMultiDrawElementsEXT(GLenum mode, GLsizei count, GLenum type, GLvoid * indices, GLsizei primcount) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiDrawElementsIndirect
void glMultiDrawElementsIndirect(GLenum mode, GLenum type, void * indirect, GLsizei drawcount, GLsizei stride) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiDrawElementsIndirectAMD
void glMultiDrawElementsIndirectAMD(GLenum mode, GLenum type, GLvoid indirect, GLsizei primcount, GLsizei stride) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiDrawRangeElementArrayAPPLE
void glMultiDrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count, GLsizei primcount) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiModeDrawArraysIBM
void glMultiModeDrawArraysIBM(GLenum mode, GLint first, GLsizei count, GLsizei primcount, GLint modestride) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiModeDrawElementsIBM
void glMultiModeDrawElementsIBM(GLenum mode, GLsizei count, GLenum type, GLvoid*const indices, GLsizei primcount, GLint modestride) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexBufferEXT
void glMultiTexBufferEXT(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord1bOES
void glMultiTexCoord1bOES(GLenum texture, GLbyte s) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord1bvOES
void glMultiTexCoord1bvOES(GLenum texture, GLbyte coords) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord1d
void glMultiTexCoord1d(GLenum target, GLdouble s) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord1dARB
void glMultiTexCoord1dARB(GLenum target, GLdouble s) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord1dv
void glMultiTexCoord1dv(GLenum target, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord1dvARB
void glMultiTexCoord1dvARB(GLenum target, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord1f
void glMultiTexCoord1f(GLenum target, GLfloat s) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord1fARB
void glMultiTexCoord1fARB(GLenum target, GLfloat s) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord1fv
void glMultiTexCoord1fv(GLenum target, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord1fvARB
void glMultiTexCoord1fvARB(GLenum target, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord1hNV
void glMultiTexCoord1hNV(GLenum target, GLhalfNV s) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord1hvNV
void glMultiTexCoord1hvNV(GLenum target, GLhalfNV v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord1i
void glMultiTexCoord1i(GLenum target, GLint s) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord1iARB
void glMultiTexCoord1iARB(GLenum target, GLint s) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord1iv
void glMultiTexCoord1iv(GLenum target, GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord1ivARB
void glMultiTexCoord1ivARB(GLenum target, GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord1s
void glMultiTexCoord1s(GLenum target, GLshort s) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord1sARB
void glMultiTexCoord1sARB(GLenum target, GLshort s) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord1sv
void glMultiTexCoord1sv(GLenum target, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord1svARB
void glMultiTexCoord1svARB(GLenum target, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord1xOES
void glMultiTexCoord1xOES(GLenum texture, GLfixed s) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord1xvOES
void glMultiTexCoord1xvOES(GLenum texture, GLfixed coords) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord2bOES
void glMultiTexCoord2bOES(GLenum texture, GLbyte s, GLbyte t) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord2bvOES
void glMultiTexCoord2bvOES(GLenum texture, GLbyte coords) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord2d
void glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord2dARB
void glMultiTexCoord2dARB(GLenum target, GLdouble s, GLdouble t) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord2dv
void glMultiTexCoord2dv(GLenum target, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord2dvARB
void glMultiTexCoord2dvARB(GLenum target, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord2f
void glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord2fARB
void glMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord2fv
void glMultiTexCoord2fv(GLenum target, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord2fvARB
void glMultiTexCoord2fvARB(GLenum target, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord2hNV
void glMultiTexCoord2hNV(GLenum target, GLhalfNV s, GLhalfNV t) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord2hvNV
void glMultiTexCoord2hvNV(GLenum target, GLhalfNV v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord2i
void glMultiTexCoord2i(GLenum target, GLint s, GLint t) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord2iARB
void glMultiTexCoord2iARB(GLenum target, GLint s, GLint t) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord2iv
void glMultiTexCoord2iv(GLenum target, GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord2ivARB
void glMultiTexCoord2ivARB(GLenum target, GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord2s
void glMultiTexCoord2s(GLenum target, GLshort s, GLshort t) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord2sARB
void glMultiTexCoord2sARB(GLenum target, GLshort s, GLshort t) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord2sv
void glMultiTexCoord2sv(GLenum target, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord2svARB
void glMultiTexCoord2svARB(GLenum target, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord2xOES
void glMultiTexCoord2xOES(GLenum texture, GLfixed s, GLfixed t) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord2xvOES
void glMultiTexCoord2xvOES(GLenum texture, GLfixed coords) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord3bOES
void glMultiTexCoord3bOES(GLenum texture, GLbyte s, GLbyte t, GLbyte r) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord3bvOES
void glMultiTexCoord3bvOES(GLenum texture, GLbyte coords) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord3d
void glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord3dARB
void glMultiTexCoord3dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord3dv
void glMultiTexCoord3dv(GLenum target, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord3dvARB
void glMultiTexCoord3dvARB(GLenum target, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord3f
void glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord3fARB
void glMultiTexCoord3fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord3fv
void glMultiTexCoord3fv(GLenum target, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord3fvARB
void glMultiTexCoord3fvARB(GLenum target, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord3hNV
void glMultiTexCoord3hNV(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord3hvNV
void glMultiTexCoord3hvNV(GLenum target, GLhalfNV v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord3i
void glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord3iARB
void glMultiTexCoord3iARB(GLenum target, GLint s, GLint t, GLint r) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord3iv
void glMultiTexCoord3iv(GLenum target, GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord3ivARB
void glMultiTexCoord3ivARB(GLenum target, GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord3s
void glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord3sARB
void glMultiTexCoord3sARB(GLenum target, GLshort s, GLshort t, GLshort r) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord3sv
void glMultiTexCoord3sv(GLenum target, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord3svARB
void glMultiTexCoord3svARB(GLenum target, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord3xOES
void glMultiTexCoord3xOES(GLenum texture, GLfixed s, GLfixed t, GLfixed r) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord3xvOES
void glMultiTexCoord3xvOES(GLenum texture, GLfixed coords) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord4bOES
void glMultiTexCoord4bOES(GLenum texture, GLbyte s, GLbyte t, GLbyte r, GLbyte q) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord4bvOES
void glMultiTexCoord4bvOES(GLenum texture, GLbyte coords) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord4d
void glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord4dARB
void glMultiTexCoord4dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord4dv
void glMultiTexCoord4dv(GLenum target, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord4dvARB
void glMultiTexCoord4dvARB(GLenum target, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord4f
void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord4fARB
void glMultiTexCoord4fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord4fv
void glMultiTexCoord4fv(GLenum target, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord4fvARB
void glMultiTexCoord4fvARB(GLenum target, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord4hNV
void glMultiTexCoord4hNV(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord4hvNV
void glMultiTexCoord4hvNV(GLenum target, GLhalfNV v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord4i
void glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord4iARB
void glMultiTexCoord4iARB(GLenum target, GLint s, GLint t, GLint r, GLint q) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord4iv
void glMultiTexCoord4iv(GLenum target, GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord4ivARB
void glMultiTexCoord4ivARB(GLenum target, GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord4s
void glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord4sARB
void glMultiTexCoord4sARB(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord4sv
void glMultiTexCoord4sv(GLenum target, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord4svARB
void glMultiTexCoord4svARB(GLenum target, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord4xOES
void glMultiTexCoord4xOES(GLenum texture, GLfixed s, GLfixed t, GLfixed r, GLfixed q) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoord4xvOES
void glMultiTexCoord4xvOES(GLenum texture, GLfixed coords) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoordP1ui
void glMultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoordP1uiv
void glMultiTexCoordP1uiv(GLenum texture, GLenum type, GLuint coords) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoordP2ui
void glMultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoordP2uiv
void glMultiTexCoordP2uiv(GLenum texture, GLenum type, GLuint coords) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoordP3ui
void glMultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoordP3uiv
void glMultiTexCoordP3uiv(GLenum texture, GLenum type, GLuint coords) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoordP4ui
void glMultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoordP4uiv
void glMultiTexCoordP4uiv(GLenum texture, GLenum type, GLuint coords) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexCoordPointerEXT
void glMultiTexCoordPointerEXT(GLenum texunit, GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexEnvfEXT
void glMultiTexEnvfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexEnvfvEXT
void glMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexEnviEXT
void glMultiTexEnviEXT(GLenum texunit, GLenum target, GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexEnvivEXT
void glMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexGendEXT
void glMultiTexGendEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble param) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexGendvEXT
void glMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble params) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexGenfEXT
void glMultiTexGenfEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexGenfvEXT
void glMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexGeniEXT
void glMultiTexGeniEXT(GLenum texunit, GLenum coord, GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexGenivEXT
void glMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexImage1DEXT
void glMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexImage2DEXT
void glMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexImage3DEXT
void glMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexParameterIivEXT
void glMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexParameterIuivEXT
void glMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexParameterfEXT
void glMultiTexParameterfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexParameterfvEXT
void glMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexParameteriEXT
void glMultiTexParameteriEXT(GLenum texunit, GLenum target, GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexParameterivEXT
void glMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexRenderbufferEXT
void glMultiTexRenderbufferEXT(GLenum texunit, GLenum target, GLuint renderbuffer) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexSubImage1DEXT
void glMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexSubImage2DEXT
void glMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glMultiTexSubImage3DEXT
void glMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedBufferDataEXT
void glNamedBufferDataEXT(GLuint buffer, GLsizeiptr size, GLvoid data, GLenum usage) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedBufferSubDataEXT
void glNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid data) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedCopyBufferSubDataEXT
void glNamedCopyBufferSubDataEXT(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedFramebufferParameteriEXT
void glNamedFramebufferParameteriEXT(GLuint framebuffer, GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedFramebufferRenderbufferEXT
void glNamedFramebufferRenderbufferEXT(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedFramebufferTexture1DEXT
void glNamedFramebufferTexture1DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedFramebufferTexture2DEXT
void glNamedFramebufferTexture2DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedFramebufferTexture3DEXT
void glNamedFramebufferTexture3DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedFramebufferTextureEXT
void glNamedFramebufferTextureEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedFramebufferTextureFaceEXT
void glNamedFramebufferTextureFaceEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedFramebufferTextureLayerEXT
void glNamedFramebufferTextureLayerEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedProgramLocalParameter4dEXT
void glNamedProgramLocalParameter4dEXT(GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedProgramLocalParameter4dvEXT
void glNamedProgramLocalParameter4dvEXT(GLuint program, GLenum target, GLuint index, GLdouble params) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedProgramLocalParameter4fEXT
void glNamedProgramLocalParameter4fEXT(GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedProgramLocalParameter4fvEXT
void glNamedProgramLocalParameter4fvEXT(GLuint program, GLenum target, GLuint index, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedProgramLocalParameterI4iEXT
void glNamedProgramLocalParameterI4iEXT(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedProgramLocalParameterI4ivEXT
void glNamedProgramLocalParameterI4ivEXT(GLuint program, GLenum target, GLuint index, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedProgramLocalParameterI4uiEXT
void glNamedProgramLocalParameterI4uiEXT(GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedProgramLocalParameterI4uivEXT
void glNamedProgramLocalParameterI4uivEXT(GLuint program, GLenum target, GLuint index, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedProgramLocalParameters4fvEXT
void glNamedProgramLocalParameters4fvEXT(GLuint program, GLenum target, GLuint index, GLsizei count, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedProgramLocalParametersI4ivEXT
void glNamedProgramLocalParametersI4ivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedProgramLocalParametersI4uivEXT
void glNamedProgramLocalParametersI4uivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedProgramStringEXT
void glNamedProgramStringEXT(GLuint program, GLenum target, GLenum format, GLsizei len, GLvoid string) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedRenderbufferStorageEXT
void glNamedRenderbufferStorageEXT(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedRenderbufferStorageMultisampleCoverageEXT
void glNamedRenderbufferStorageMultisampleCoverageEXT(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedRenderbufferStorageMultisampleEXT
void glNamedRenderbufferStorageMultisampleEXT(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
printf(gl.c);
}
#endif
#ifndef skip_glNamedStringARB
void glNamedStringARB(GLenum type, GLint namelen, GLchar name, GLint stringlen, GLchar string) {
printf(gl.c);
}
#endif
#ifndef skip_glNewList
void glNewList(GLuint list, GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glNewObjectBufferATI
UInt32 glNewObjectBufferATI(GLsizei size, GLvoid pointer, GLenum usage) {
printf(gl.c);
}
#endif
#ifndef skip_glNormal3b
void glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz) {
printf(gl.c);
}
#endif
#ifndef skip_glNormal3bv
void glNormal3bv(GLbyte v) {
printf(gl.c);
}
#endif
#ifndef skip_glNormal3d
void glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz) {
printf(gl.c);
}
#endif
#ifndef skip_glNormal3dv
void glNormal3dv(GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glNormal3f
void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {
printf(gl.c);
}
#endif
#ifndef skip_glNormal3fVertex3fSUN
void glNormal3fVertex3fSUN(GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glNormal3fVertex3fvSUN
void glNormal3fVertex3fvSUN(GLfloat n, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glNormal3fv
void glNormal3fv(GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glNormal3hNV
void glNormal3hNV(GLhalfNV nx, GLhalfNV ny, GLhalfNV nz) {
printf(gl.c);
}
#endif
#ifndef skip_glNormal3hvNV
void glNormal3hvNV(GLhalfNV v) {
printf(gl.c);
}
#endif
#ifndef skip_glNormal3i
void glNormal3i(GLint nx, GLint ny, GLint nz) {
printf(gl.c);
}
#endif
#ifndef skip_glNormal3iv
void glNormal3iv(GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glNormal3s
void glNormal3s(GLshort nx, GLshort ny, GLshort nz) {
printf(gl.c);
}
#endif
#ifndef skip_glNormal3sv
void glNormal3sv(GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glNormal3xOES
void glNormal3xOES(GLfixed nx, GLfixed ny, GLfixed nz) {
printf(gl.c);
}
#endif
#ifndef skip_glNormal3xvOES
void glNormal3xvOES(GLfixed coords) {
printf(gl.c);
}
#endif
#ifndef skip_glNormalFormatNV
void glNormalFormatNV(GLenum type, GLsizei stride) {
printf(gl.c);
}
#endif
#ifndef skip_glNormalP3ui
void glNormalP3ui(GLenum type, GLuint coords) {
printf(gl.c);
}
#endif
#ifndef skip_glNormalP3uiv
void glNormalP3uiv(GLenum type, GLuint coords) {
printf(gl.c);
}
#endif
#ifndef skip_glNormalPointer
void glNormalPointer(GLenum type, GLsizei stride, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glNormalPointerEXT
void glNormalPointerEXT(GLenum type, GLsizei stride, GLsizei count, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glNormalPointerListIBM
void glNormalPointerListIBM(GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride) {
printf(gl.c);
}
#endif
#ifndef skip_glNormalPointervINTEL
void glNormalPointervINTEL(GLenum type, GLvoid * pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glNormalStream3bATI
void glNormalStream3bATI(GLenum stream, GLbyte nx, GLbyte ny, GLbyte nz) {
printf(gl.c);
}
#endif
#ifndef skip_glNormalStream3bvATI
void glNormalStream3bvATI(GLenum stream, GLbyte coords) {
printf(gl.c);
}
#endif
#ifndef skip_glNormalStream3dATI
void glNormalStream3dATI(GLenum stream, GLdouble nx, GLdouble ny, GLdouble nz) {
printf(gl.c);
}
#endif
#ifndef skip_glNormalStream3dvATI
void glNormalStream3dvATI(GLenum stream, GLdouble coords) {
printf(gl.c);
}
#endif
#ifndef skip_glNormalStream3fATI
void glNormalStream3fATI(GLenum stream, GLfloat nx, GLfloat ny, GLfloat nz) {
printf(gl.c);
}
#endif
#ifndef skip_glNormalStream3fvATI
void glNormalStream3fvATI(GLenum stream, GLfloat coords) {
printf(gl.c);
}
#endif
#ifndef skip_glNormalStream3iATI
void glNormalStream3iATI(GLenum stream, GLint nx, GLint ny, GLint nz) {
printf(gl.c);
}
#endif
#ifndef skip_glNormalStream3ivATI
void glNormalStream3ivATI(GLenum stream, GLint coords) {
printf(gl.c);
}
#endif
#ifndef skip_glNormalStream3sATI
void glNormalStream3sATI(GLenum stream, GLshort nx, GLshort ny, GLshort nz) {
printf(gl.c);
}
#endif
#ifndef skip_glNormalStream3svATI
void glNormalStream3svATI(GLenum stream, GLshort coords) {
printf(gl.c);
}
#endif
#ifndef skip_glObjectLabel
void glObjectLabel(GLenum identifier, GLuint name, GLsizei length, GLchar label) {
printf(gl.c);
}
#endif
#ifndef skip_glObjectPtrLabel
void glObjectPtrLabel(void * ptr, GLsizei length, GLchar label) {
printf(gl.c);
}
#endif
#ifndef skip_glObjectPurgeableAPPLE
GLenum glObjectPurgeableAPPLE(GLenum objectType, GLuint name, GLenum option) {
printf(gl.c);
}
#endif
#ifndef skip_glObjectUnpurgeableAPPLE
GLenum glObjectUnpurgeableAPPLE(GLenum objectType, GLuint name, GLenum option) {
printf(gl.c);
}
#endif
#ifndef skip_glOrtho
void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
printf(gl.c);
}
#endif
#ifndef skip_glOrthofOES
void glOrthofOES(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f) {
printf(gl.c);
}
#endif
#ifndef skip_glOrthoxOES
void glOrthoxOES(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f) {
printf(gl.c);
}
#endif
#ifndef skip_glPNTrianglesfATI
void glPNTrianglesfATI(GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glPNTrianglesiATI
void glPNTrianglesiATI(GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glPassTexCoordATI
void glPassTexCoordATI(GLuint dst, GLuint coord, GLenum swizzle) {
printf(gl.c);
}
#endif
#ifndef skip_glPassThrough
void glPassThrough(GLfloat token) {
printf(gl.c);
}
#endif
#ifndef skip_glPassThroughxOES
void glPassThroughxOES(GLfixed token) {
printf(gl.c);
}
#endif
#ifndef skip_glPatchParameterfv
void glPatchParameterfv(GLenum pname, GLfloat values) {
printf(gl.c);
}
#endif
#ifndef skip_glPatchParameteri
void glPatchParameteri(GLenum pname, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glPathColorGenNV
void glPathColorGenNV(GLenum color, GLenum genMode, GLenum colorFormat, GLfloat coeffs) {
printf(gl.c);
}
#endif
#ifndef skip_glPathCommandsNV
void glPathCommandsNV(GLuint path, GLsizei numCommands, GLubyte commands, GLsizei numCoords, GLenum coordType, GLvoid coords) {
printf(gl.c);
}
#endif
#ifndef skip_glPathCoordsNV
void glPathCoordsNV(GLuint path, GLsizei numCoords, GLenum coordType, GLvoid coords) {
printf(gl.c);
}
#endif
#ifndef skip_glPathCoverDepthFuncNV
void glPathCoverDepthFuncNV(GLenum func) {
printf(gl.c);
}
#endif
#ifndef skip_glPathDashArrayNV
void glPathDashArrayNV(GLuint path, GLsizei dashCount, GLfloat dashArray) {
printf(gl.c);
}
#endif
#ifndef skip_glPathFogGenNV
void glPathFogGenNV(GLenum genMode) {
printf(gl.c);
}
#endif
#ifndef skip_glPathGlyphRangeNV
void glPathGlyphRangeNV(GLuint firstPathName, GLenum fontTarget, GLvoid fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale) {
printf(gl.c);
}
#endif
#ifndef skip_glPathGlyphsNV
void glPathGlyphsNV(GLuint firstPathName, GLenum fontTarget, GLvoid fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, GLvoid charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale) {
printf(gl.c);
}
#endif
#ifndef skip_glPathParameterfNV
void glPathParameterfNV(GLuint path, GLenum pname, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glPathParameterfvNV
void glPathParameterfvNV(GLuint path, GLenum pname, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glPathParameteriNV
void glPathParameteriNV(GLuint path, GLenum pname, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glPathParameterivNV
void glPathParameterivNV(GLuint path, GLenum pname, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glPathStencilDepthOffsetNV
void glPathStencilDepthOffsetNV(GLfloat factor, GLfloat units) {
printf(gl.c);
}
#endif
#ifndef skip_glPathStencilFuncNV
void glPathStencilFuncNV(GLenum func, GLint ref, GLuint mask) {
printf(gl.c);
}
#endif
#ifndef skip_glPathStringNV
void glPathStringNV(GLuint path, GLenum format, GLsizei length, GLvoid pathString) {
printf(gl.c);
}
#endif
#ifndef skip_glPathSubCommandsNV
void glPathSubCommandsNV(GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, GLubyte commands, GLsizei numCoords, GLenum coordType, GLvoid coords) {
printf(gl.c);
}
#endif
#ifndef skip_glPathSubCoordsNV
void glPathSubCoordsNV(GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, GLvoid coords) {
printf(gl.c);
}
#endif
#ifndef skip_glPathTexGenNV
void glPathTexGenNV(GLenum texCoordSet, GLenum genMode, GLint components, GLfloat coeffs) {
printf(gl.c);
}
#endif
#ifndef skip_glPauseTransformFeedback
void glPauseTransformFeedback() {
printf(gl.c);
}
#endif
#ifndef skip_glPauseTransformFeedbackNV
void glPauseTransformFeedbackNV() {
printf(gl.c);
}
#endif
#ifndef skip_glPixelDataRangeNV
void glPixelDataRangeNV(GLenum target, GLsizei length, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glPixelMapfv
void glPixelMapfv(GLenum map, GLsizei mapsize, GLfloat values) {
printf(gl.c);
}
#endif
#ifndef skip_glPixelMapuiv
void glPixelMapuiv(GLenum map, GLsizei mapsize, GLuint values) {
printf(gl.c);
}
#endif
#ifndef skip_glPixelMapusv
void glPixelMapusv(GLenum map, GLsizei mapsize, GLushort values) {
printf(gl.c);
}
#endif
#ifndef skip_glPixelMapx
void glPixelMapx(GLenum map, GLint size, GLfixed values) {
printf(gl.c);
}
#endif
#ifndef skip_glPixelStoref
void glPixelStoref(GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glPixelStorei
void glPixelStorei(GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glPixelStorex
void glPixelStorex(GLenum pname, GLfixed param) {
printf(gl.c);
}
#endif
#ifndef skip_glPixelTexGenParameterfSGIS
void glPixelTexGenParameterfSGIS(GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glPixelTexGenParameterfvSGIS
void glPixelTexGenParameterfvSGIS(GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glPixelTexGenParameteriSGIS
void glPixelTexGenParameteriSGIS(GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glPixelTexGenParameterivSGIS
void glPixelTexGenParameterivSGIS(GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glPixelTexGenSGIX
void glPixelTexGenSGIX(GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glPixelTransferf
void glPixelTransferf(GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glPixelTransferi
void glPixelTransferi(GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glPixelTransferxOES
void glPixelTransferxOES(GLenum pname, GLfixed param) {
printf(gl.c);
}
#endif
#ifndef skip_glPixelTransformParameterfEXT
void glPixelTransformParameterfEXT(GLenum target, GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glPixelTransformParameterfvEXT
void glPixelTransformParameterfvEXT(GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glPixelTransformParameteriEXT
void glPixelTransformParameteriEXT(GLenum target, GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glPixelTransformParameterivEXT
void glPixelTransformParameterivEXT(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glPixelZoom
void glPixelZoom(GLfloat xfactor, GLfloat yfactor) {
printf(gl.c);
}
#endif
#ifndef skip_glPixelZoomxOES
void glPixelZoomxOES(GLfixed xfactor, GLfixed yfactor) {
printf(gl.c);
}
#endif
#ifndef skip_glPointAlongPathNV
Boolean glPointAlongPathNV(GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat x, GLfloat y, GLfloat tangentX, GLfloat tangentY) {
printf(gl.c);
}
#endif
#ifndef skip_glPointParameterf
void glPointParameterf(GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glPointParameterfARB
void glPointParameterfARB(GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glPointParameterfEXT
void glPointParameterfEXT(GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glPointParameterfSGIS
void glPointParameterfSGIS(GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glPointParameterfv
void glPointParameterfv(GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glPointParameterfvARB
void glPointParameterfvARB(GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glPointParameterfvEXT
void glPointParameterfvEXT(GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glPointParameterfvSGIS
void glPointParameterfvSGIS(GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glPointParameteri
void glPointParameteri(GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glPointParameteriNV
void glPointParameteriNV(GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glPointParameteriv
void glPointParameteriv(GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glPointParameterivNV
void glPointParameterivNV(GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glPointParameterxvOES
void glPointParameterxvOES(GLenum pname, GLfixed params) {
printf(gl.c);
}
#endif
#ifndef skip_glPointSize
void glPointSize(GLfloat size) {
printf(gl.c);
}
#endif
#ifndef skip_glPointSizexOES
void glPointSizexOES(GLfixed size) {
printf(gl.c);
}
#endif
#ifndef skip_glPollAsyncSGIX
Int32 glPollAsyncSGIX(GLuint markerp) {
printf(gl.c);
}
#endif
#ifndef skip_glPollInstrumentsSGIX
Int32 glPollInstrumentsSGIX(GLint marker_p) {
printf(gl.c);
}
#endif
#ifndef skip_glPolygonMode
void glPolygonMode(GLenum face, GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glPolygonOffset
void glPolygonOffset(GLfloat factor, GLfloat units) {
printf(gl.c);
}
#endif
#ifndef skip_glPolygonOffsetEXT
void glPolygonOffsetEXT(GLfloat factor, GLfloat bias) {
printf(gl.c);
}
#endif
#ifndef skip_glPolygonOffsetxOES
void glPolygonOffsetxOES(GLfixed factor, GLfixed units) {
printf(gl.c);
}
#endif
#ifndef skip_glPolygonStipple
void glPolygonStipple(GLubyte mask) {
printf(gl.c);
}
#endif
#ifndef skip_glPopAttrib
void glPopAttrib() {
printf(gl.c);
}
#endif
#ifndef skip_glPopClientAttrib
void glPopClientAttrib() {
printf(gl.c);
}
#endif
#ifndef skip_glPopDebugGroup
void glPopDebugGroup() {
printf(gl.c);
}
#endif
#ifndef skip_glPopMatrix
void glPopMatrix() {
printf(gl.c);
}
#endif
#ifndef skip_glPopName
void glPopName() {
printf(gl.c);
}
#endif
#ifndef skip_glPresentFrameDualFillNV
void glPresentFrameDualFillNV(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLenum target1, GLuint fill1, GLenum target2, GLuint fill2, GLenum target3, GLuint fill3) {
printf(gl.c);
}
#endif
#ifndef skip_glPresentFrameKeyedNV
void glPresentFrameKeyedNV(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLuint key0, GLenum target1, GLuint fill1, GLuint key1) {
printf(gl.c);
}
#endif
#ifndef skip_glPrimitiveRestartIndex
void glPrimitiveRestartIndex(GLuint index) {
printf(gl.c);
}
#endif
#ifndef skip_glPrimitiveRestartIndexNV
void glPrimitiveRestartIndexNV(GLuint index) {
printf(gl.c);
}
#endif
#ifndef skip_glPrimitiveRestartNV
void glPrimitiveRestartNV() {
printf(gl.c);
}
#endif
#ifndef skip_glPrioritizeTextures
void glPrioritizeTextures(GLsizei n, GLuint textures, GLfloat priorities) {
printf(gl.c);
}
#endif
#ifndef skip_glPrioritizeTexturesEXT
void glPrioritizeTexturesEXT(GLsizei n, GLuint textures, GLclampf priorities) {
printf(gl.c);
}
#endif
#ifndef skip_glPrioritizeTexturesxOES
void glPrioritizeTexturesxOES(GLsizei n, GLuint textures, GLfixed priorities) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramBinary
void glProgramBinary(GLuint program, GLenum binaryFormat, GLvoid binary, GLsizei length) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramBufferParametersIivNV
void glProgramBufferParametersIivNV(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramBufferParametersIuivNV
void glProgramBufferParametersIuivNV(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramBufferParametersfvNV
void glProgramBufferParametersfvNV(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramEnvParameter4dARB
void glProgramEnvParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramEnvParameter4dvARB
void glProgramEnvParameter4dvARB(GLenum target, GLuint index, GLdouble params) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramEnvParameter4fARB
void glProgramEnvParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramEnvParameter4fvARB
void glProgramEnvParameter4fvARB(GLenum target, GLuint index, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramEnvParameterI4iNV
void glProgramEnvParameterI4iNV(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramEnvParameterI4ivNV
void glProgramEnvParameterI4ivNV(GLenum target, GLuint index, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramEnvParameterI4uiNV
void glProgramEnvParameterI4uiNV(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramEnvParameterI4uivNV
void glProgramEnvParameterI4uivNV(GLenum target, GLuint index, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramEnvParameters4fvEXT
void glProgramEnvParameters4fvEXT(GLenum target, GLuint index, GLsizei count, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramEnvParametersI4ivNV
void glProgramEnvParametersI4ivNV(GLenum target, GLuint index, GLsizei count, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramEnvParametersI4uivNV
void glProgramEnvParametersI4uivNV(GLenum target, GLuint index, GLsizei count, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramLocalParameter4dARB
void glProgramLocalParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramLocalParameter4dvARB
void glProgramLocalParameter4dvARB(GLenum target, GLuint index, GLdouble params) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramLocalParameter4fARB
void glProgramLocalParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramLocalParameter4fvARB
void glProgramLocalParameter4fvARB(GLenum target, GLuint index, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramLocalParameterI4iNV
void glProgramLocalParameterI4iNV(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramLocalParameterI4ivNV
void glProgramLocalParameterI4ivNV(GLenum target, GLuint index, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramLocalParameterI4uiNV
void glProgramLocalParameterI4uiNV(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramLocalParameterI4uivNV
void glProgramLocalParameterI4uivNV(GLenum target, GLuint index, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramLocalParameters4fvEXT
void glProgramLocalParameters4fvEXT(GLenum target, GLuint index, GLsizei count, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramLocalParametersI4ivNV
void glProgramLocalParametersI4ivNV(GLenum target, GLuint index, GLsizei count, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramLocalParametersI4uivNV
void glProgramLocalParametersI4uivNV(GLenum target, GLuint index, GLsizei count, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramNamedParameter4dNV
void glProgramNamedParameter4dNV(GLuint id, GLsizei len, GLubyte name, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramNamedParameter4dvNV
void glProgramNamedParameter4dvNV(GLuint id, GLsizei len, GLubyte name, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramNamedParameter4fNV
void glProgramNamedParameter4fNV(GLuint id, GLsizei len, GLubyte name, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramNamedParameter4fvNV
void glProgramNamedParameter4fvNV(GLuint id, GLsizei len, GLubyte name, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramParameter4dNV
void glProgramParameter4dNV(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramParameter4dvNV
void glProgramParameter4dvNV(GLenum target, GLuint index, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramParameter4fNV
void glProgramParameter4fNV(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramParameter4fvNV
void glProgramParameter4fvNV(GLenum target, GLuint index, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramParameteri
void glProgramParameteri(GLuint program, GLenum pname, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramParameteriARB
void glProgramParameteriARB(GLuint program, GLenum pname, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramParameteriEXT
void glProgramParameteriEXT(GLuint program, GLenum pname, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramParameters4dvNV
void glProgramParameters4dvNV(GLenum target, GLuint index, GLsizei count, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramParameters4fvNV
void glProgramParameters4fvNV(GLenum target, GLuint index, GLsizei count, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramStringARB
void glProgramStringARB(GLenum target, GLenum format, GLsizei len, GLvoid string) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramSubroutineParametersuivNV
void glProgramSubroutineParametersuivNV(GLenum target, GLsizei count, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform1d
void glProgramUniform1d(GLuint program, GLint location, GLdouble v0) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform1dEXT
void glProgramUniform1dEXT(GLuint program, GLint location, GLdouble x) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform1dv
void glProgramUniform1dv(GLuint program, GLint location, GLsizei count, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform1dvEXT
void glProgramUniform1dvEXT(GLuint program, GLint location, GLsizei count, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform1f
void glProgramUniform1f(GLuint program, GLint location, GLfloat v0) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform1fEXT
void glProgramUniform1fEXT(GLuint program, GLint location, GLfloat v0) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform1fv
void glProgramUniform1fv(GLuint program, GLint location, GLsizei count, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform1fvEXT
void glProgramUniform1fvEXT(GLuint program, GLint location, GLsizei count, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform1i
void glProgramUniform1i(GLuint program, GLint location, GLint v0) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform1i64NV
void glProgramUniform1i64NV(GLuint program, GLint location, GLint64EXT x) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform1i64vNV
void glProgramUniform1i64vNV(GLuint program, GLint location, GLsizei count, GLint64EXT value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform1iEXT
void glProgramUniform1iEXT(GLuint program, GLint location, GLint v0) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform1iv
void glProgramUniform1iv(GLuint program, GLint location, GLsizei count, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform1ivEXT
void glProgramUniform1ivEXT(GLuint program, GLint location, GLsizei count, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform1ui
void glProgramUniform1ui(GLuint program, GLint location, GLuint v0) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform1ui64NV
void glProgramUniform1ui64NV(GLuint program, GLint location, GLuint64EXT x) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform1ui64vNV
void glProgramUniform1ui64vNV(GLuint program, GLint location, GLsizei count, GLuint64EXT value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform1uiEXT
void glProgramUniform1uiEXT(GLuint program, GLint location, GLuint v0) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform1uiv
void glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform1uivEXT
void glProgramUniform1uivEXT(GLuint program, GLint location, GLsizei count, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform2d
void glProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform2dEXT
void glProgramUniform2dEXT(GLuint program, GLint location, GLdouble x, GLdouble y) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform2dv
void glProgramUniform2dv(GLuint program, GLint location, GLsizei count, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform2dvEXT
void glProgramUniform2dvEXT(GLuint program, GLint location, GLsizei count, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform2f
void glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform2fEXT
void glProgramUniform2fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform2fv
void glProgramUniform2fv(GLuint program, GLint location, GLsizei count, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform2fvEXT
void glProgramUniform2fvEXT(GLuint program, GLint location, GLsizei count, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform2i
void glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform2i64NV
void glProgramUniform2i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform2i64vNV
void glProgramUniform2i64vNV(GLuint program, GLint location, GLsizei count, GLint64EXT value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform2iEXT
void glProgramUniform2iEXT(GLuint program, GLint location, GLint v0, GLint v1) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform2iv
void glProgramUniform2iv(GLuint program, GLint location, GLsizei count, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform2ivEXT
void glProgramUniform2ivEXT(GLuint program, GLint location, GLsizei count, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform2ui
void glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform2ui64NV
void glProgramUniform2ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform2ui64vNV
void glProgramUniform2ui64vNV(GLuint program, GLint location, GLsizei count, GLuint64EXT value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform2uiEXT
void glProgramUniform2uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform2uiv
void glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform2uivEXT
void glProgramUniform2uivEXT(GLuint program, GLint location, GLsizei count, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform3d
void glProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform3dEXT
void glProgramUniform3dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform3dv
void glProgramUniform3dv(GLuint program, GLint location, GLsizei count, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform3dvEXT
void glProgramUniform3dvEXT(GLuint program, GLint location, GLsizei count, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform3f
void glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform3fEXT
void glProgramUniform3fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform3fv
void glProgramUniform3fv(GLuint program, GLint location, GLsizei count, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform3fvEXT
void glProgramUniform3fvEXT(GLuint program, GLint location, GLsizei count, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform3i
void glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform3i64NV
void glProgramUniform3i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform3i64vNV
void glProgramUniform3i64vNV(GLuint program, GLint location, GLsizei count, GLint64EXT value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform3iEXT
void glProgramUniform3iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform3iv
void glProgramUniform3iv(GLuint program, GLint location, GLsizei count, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform3ivEXT
void glProgramUniform3ivEXT(GLuint program, GLint location, GLsizei count, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform3ui
void glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform3ui64NV
void glProgramUniform3ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform3ui64vNV
void glProgramUniform3ui64vNV(GLuint program, GLint location, GLsizei count, GLuint64EXT value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform3uiEXT
void glProgramUniform3uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform3uiv
void glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform3uivEXT
void glProgramUniform3uivEXT(GLuint program, GLint location, GLsizei count, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform4d
void glProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform4dEXT
void glProgramUniform4dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform4dv
void glProgramUniform4dv(GLuint program, GLint location, GLsizei count, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform4dvEXT
void glProgramUniform4dvEXT(GLuint program, GLint location, GLsizei count, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform4f
void glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform4fEXT
void glProgramUniform4fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform4fv
void glProgramUniform4fv(GLuint program, GLint location, GLsizei count, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform4fvEXT
void glProgramUniform4fvEXT(GLuint program, GLint location, GLsizei count, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform4i
void glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform4i64NV
void glProgramUniform4i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform4i64vNV
void glProgramUniform4i64vNV(GLuint program, GLint location, GLsizei count, GLint64EXT value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform4iEXT
void glProgramUniform4iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform4iv
void glProgramUniform4iv(GLuint program, GLint location, GLsizei count, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform4ivEXT
void glProgramUniform4ivEXT(GLuint program, GLint location, GLsizei count, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform4ui
void glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform4ui64NV
void glProgramUniform4ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform4ui64vNV
void glProgramUniform4ui64vNV(GLuint program, GLint location, GLsizei count, GLuint64EXT value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform4uiEXT
void glProgramUniform4uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform4uiv
void glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniform4uivEXT
void glProgramUniform4uivEXT(GLuint program, GLint location, GLsizei count, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformHandleui64NV
void glProgramUniformHandleui64NV(GLuint program, GLint location, GLuint64 value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformHandleui64vNV
void glProgramUniformHandleui64vNV(GLuint program, GLint location, GLsizei count, GLuint64 values) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix2dv
void glProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix2dvEXT
void glProgramUniformMatrix2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix2fv
void glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix2fvEXT
void glProgramUniformMatrix2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix2x3dv
void glProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix2x3dvEXT
void glProgramUniformMatrix2x3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix2x3fv
void glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix2x3fvEXT
void glProgramUniformMatrix2x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix2x4dv
void glProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix2x4dvEXT
void glProgramUniformMatrix2x4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix2x4fv
void glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix2x4fvEXT
void glProgramUniformMatrix2x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix3dv
void glProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix3dvEXT
void glProgramUniformMatrix3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix3fv
void glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix3fvEXT
void glProgramUniformMatrix3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix3x2dv
void glProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix3x2dvEXT
void glProgramUniformMatrix3x2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix3x2fv
void glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix3x2fvEXT
void glProgramUniformMatrix3x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix3x4dv
void glProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix3x4dvEXT
void glProgramUniformMatrix3x4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix3x4fv
void glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix3x4fvEXT
void glProgramUniformMatrix3x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix4dv
void glProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix4dvEXT
void glProgramUniformMatrix4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix4fv
void glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix4fvEXT
void glProgramUniformMatrix4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix4x2dv
void glProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix4x2dvEXT
void glProgramUniformMatrix4x2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix4x2fv
void glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix4x2fvEXT
void glProgramUniformMatrix4x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix4x3dv
void glProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix4x3dvEXT
void glProgramUniformMatrix4x3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix4x3fv
void glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformMatrix4x3fvEXT
void glProgramUniformMatrix4x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformui64NV
void glProgramUniformui64NV(GLuint program, GLint location, GLuint64EXT value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramUniformui64vNV
void glProgramUniformui64vNV(GLuint program, GLint location, GLsizei count, GLuint64EXT value) {
printf(gl.c);
}
#endif
#ifndef skip_glProgramVertexLimitNV
void glProgramVertexLimitNV(GLenum target, GLint limit) {
printf(gl.c);
}
#endif
#ifndef skip_glProvokingVertex
void glProvokingVertex(GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glProvokingVertexEXT
void glProvokingVertexEXT(GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glPushAttrib
void glPushAttrib(GLbitfield mask) {
printf(gl.c);
}
#endif
#ifndef skip_glPushClientAttrib
void glPushClientAttrib(GLbitfield mask) {
printf(gl.c);
}
#endif
#ifndef skip_glPushClientAttribDefaultEXT
void glPushClientAttribDefaultEXT(GLbitfield mask) {
printf(gl.c);
}
#endif
#ifndef skip_glPushDebugGroup
void glPushDebugGroup(GLenum source, GLuint id, GLsizei length, GLchar message) {
printf(gl.c);
}
#endif
#ifndef skip_glPushMatrix
void glPushMatrix() {
printf(gl.c);
}
#endif
#ifndef skip_glPushName
void glPushName(GLuint name) {
printf(gl.c);
}
#endif
#ifndef skip_glQueryCounter
void glQueryCounter(GLuint id, GLenum target) {
printf(gl.c);
}
#endif
#ifndef skip_glQueryMatrixxOES
GLbitfield glQueryMatrixxOES(GLfixed mantissa, GLint exponent) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos2d
void glRasterPos2d(GLdouble x, GLdouble y) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos2dv
void glRasterPos2dv(GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos2f
void glRasterPos2f(GLfloat x, GLfloat y) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos2fv
void glRasterPos2fv(GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos2i
void glRasterPos2i(GLint x, GLint y) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos2iv
void glRasterPos2iv(GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos2s
void glRasterPos2s(GLshort x, GLshort y) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos2sv
void glRasterPos2sv(GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos2xOES
void glRasterPos2xOES(GLfixed x, GLfixed y) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos2xvOES
void glRasterPos2xvOES(GLfixed coords) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos3d
void glRasterPos3d(GLdouble x, GLdouble y, GLdouble z) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos3dv
void glRasterPos3dv(GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos3f
void glRasterPos3f(GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos3fv
void glRasterPos3fv(GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos3i
void glRasterPos3i(GLint x, GLint y, GLint z) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos3iv
void glRasterPos3iv(GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos3s
void glRasterPos3s(GLshort x, GLshort y, GLshort z) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos3sv
void glRasterPos3sv(GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos3xOES
void glRasterPos3xOES(GLfixed x, GLfixed y, GLfixed z) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos3xvOES
void glRasterPos3xvOES(GLfixed coords) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos4d
void glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos4dv
void glRasterPos4dv(GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos4f
void glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos4fv
void glRasterPos4fv(GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos4i
void glRasterPos4i(GLint x, GLint y, GLint z, GLint w) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos4iv
void glRasterPos4iv(GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos4s
void glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos4sv
void glRasterPos4sv(GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos4xOES
void glRasterPos4xOES(GLfixed x, GLfixed y, GLfixed z, GLfixed w) {
printf(gl.c);
}
#endif
#ifndef skip_glRasterPos4xvOES
void glRasterPos4xvOES(GLfixed coords) {
printf(gl.c);
}
#endif
#ifndef skip_glReadBuffer
void glReadBuffer(GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glReadInstrumentsSGIX
void glReadInstrumentsSGIX(GLint marker) {
printf(gl.c);
}
#endif
#ifndef skip_glReadPixels
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glReadnPixelsARB
void glReadnPixelsARB(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLvoid data) {
printf(gl.c);
}
#endif
#ifndef skip_glRectd
void glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) {
printf(gl.c);
}
#endif
#ifndef skip_glRectdv
void glRectdv(GLdouble v1, GLdouble v2) {
printf(gl.c);
}
#endif
#ifndef skip_glRectf
void glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
printf(gl.c);
}
#endif
#ifndef skip_glRectfv
void glRectfv(GLfloat v1, GLfloat v2) {
printf(gl.c);
}
#endif
#ifndef skip_glRecti
void glRecti(GLint x1, GLint y1, GLint x2, GLint y2) {
printf(gl.c);
}
#endif
#ifndef skip_glRectiv
void glRectiv(GLint v1, GLint v2) {
printf(gl.c);
}
#endif
#ifndef skip_glRects
void glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2) {
printf(gl.c);
}
#endif
#ifndef skip_glRectsv
void glRectsv(GLshort v1, GLshort v2) {
printf(gl.c);
}
#endif
#ifndef skip_glRectxOES
void glRectxOES(GLfixed x1, GLfixed y1, GLfixed x2, GLfixed y2) {
printf(gl.c);
}
#endif
#ifndef skip_glRectxvOES
void glRectxvOES(GLfixed v1, GLfixed v2) {
printf(gl.c);
}
#endif
#ifndef skip_glReferencePlaneSGIX
void glReferencePlaneSGIX(GLdouble equation) {
printf(gl.c);
}
#endif
#ifndef skip_glReleaseShaderCompiler
void glReleaseShaderCompiler() {
printf(gl.c);
}
#endif
#ifndef skip_glRenderMode
Int32 glRenderMode(GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glRenderbufferStorage
void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
printf(gl.c);
}
#endif
#ifndef skip_glRenderbufferStorageEXT
void glRenderbufferStorageEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
printf(gl.c);
}
#endif
#ifndef skip_glRenderbufferStorageMultisample
void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
printf(gl.c);
}
#endif
#ifndef skip_glRenderbufferStorageMultisampleCoverageNV
void glRenderbufferStorageMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height) {
printf(gl.c);
}
#endif
#ifndef skip_glRenderbufferStorageMultisampleEXT
void glRenderbufferStorageMultisampleEXT(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
printf(gl.c);
}
#endif
#ifndef skip_glReplacementCodePointerSUN
void glReplacementCodePointerSUN(GLenum type, GLsizei stride, GLvoid * pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glReplacementCodeubSUN
void glReplacementCodeubSUN(GLubyte code) {
printf(gl.c);
}
#endif
#ifndef skip_glReplacementCodeubvSUN
void glReplacementCodeubvSUN(GLubyte code) {
printf(gl.c);
}
#endif
#ifndef skip_glReplacementCodeuiColor3fVertex3fSUN
void glReplacementCodeuiColor3fVertex3fSUN(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glReplacementCodeuiColor3fVertex3fvSUN
void glReplacementCodeuiColor3fVertex3fvSUN(GLuint rc, GLfloat c, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glReplacementCodeuiColor4fNormal3fVertex3fSUN
void glReplacementCodeuiColor4fNormal3fVertex3fSUN(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glReplacementCodeuiColor4fNormal3fVertex3fvSUN
void glReplacementCodeuiColor4fNormal3fVertex3fvSUN(GLuint rc, GLfloat c, GLfloat n, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glReplacementCodeuiColor4ubVertex3fSUN
void glReplacementCodeuiColor4ubVertex3fSUN(GLuint rc, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glReplacementCodeuiColor4ubVertex3fvSUN
void glReplacementCodeuiColor4ubVertex3fvSUN(GLuint rc, GLubyte c, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glReplacementCodeuiNormal3fVertex3fSUN
void glReplacementCodeuiNormal3fVertex3fSUN(GLuint rc, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glReplacementCodeuiNormal3fVertex3fvSUN
void glReplacementCodeuiNormal3fVertex3fvSUN(GLuint rc, GLfloat n, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glReplacementCodeuiSUN
void glReplacementCodeuiSUN(GLuint code) {
printf(gl.c);
}
#endif
#ifndef skip_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN
void glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN
void glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN(GLuint rc, GLfloat tc, GLfloat c, GLfloat n, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN
void glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN
void glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN(GLuint rc, GLfloat tc, GLfloat n, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glReplacementCodeuiTexCoord2fVertex3fSUN
void glReplacementCodeuiTexCoord2fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glReplacementCodeuiTexCoord2fVertex3fvSUN
void glReplacementCodeuiTexCoord2fVertex3fvSUN(GLuint rc, GLfloat tc, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glReplacementCodeuiVertex3fSUN
void glReplacementCodeuiVertex3fSUN(GLuint rc, GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glReplacementCodeuiVertex3fvSUN
void glReplacementCodeuiVertex3fvSUN(GLuint rc, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glReplacementCodeuivSUN
void glReplacementCodeuivSUN(GLuint code) {
printf(gl.c);
}
#endif
#ifndef skip_glReplacementCodeusSUN
void glReplacementCodeusSUN(GLushort code) {
printf(gl.c);
}
#endif
#ifndef skip_glReplacementCodeusvSUN
void glReplacementCodeusvSUN(GLushort code) {
printf(gl.c);
}
#endif
#ifndef skip_glRequestResidentProgramsNV
void glRequestResidentProgramsNV(GLsizei n, GLuint programs) {
printf(gl.c);
}
#endif
#ifndef skip_glResetHistogram
void glResetHistogram(GLenum target) {
printf(gl.c);
}
#endif
#ifndef skip_glResetHistogramEXT
void glResetHistogramEXT(GLenum target) {
printf(gl.c);
}
#endif
#ifndef skip_glResetMinmax
void glResetMinmax(GLenum target) {
printf(gl.c);
}
#endif
#ifndef skip_glResetMinmaxEXT
void glResetMinmaxEXT(GLenum target) {
printf(gl.c);
}
#endif
#ifndef skip_glResizeBuffersMESA
void glResizeBuffersMESA() {
printf(gl.c);
}
#endif
#ifndef skip_glResumeTransformFeedback
void glResumeTransformFeedback() {
printf(gl.c);
}
#endif
#ifndef skip_glResumeTransformFeedbackNV
void glResumeTransformFeedbackNV() {
printf(gl.c);
}
#endif
#ifndef skip_glRotated
void glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
printf(gl.c);
}
#endif
#ifndef skip_glRotatef
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glRotatexOES
void glRotatexOES(GLfixed angle, GLfixed x, GLfixed y, GLfixed z) {
printf(gl.c);
}
#endif
#ifndef skip_glSampleCoverage
void glSampleCoverage(GLfloat value, GLboolean invert) {
printf(gl.c);
}
#endif
#ifndef skip_glSampleCoverageARB
void glSampleCoverageARB(GLfloat value, GLboolean invert) {
printf(gl.c);
}
#endif
#ifndef skip_glSampleCoverageOES
void glSampleCoverageOES(GLfixed value, GLboolean invert) {
printf(gl.c);
}
#endif
#ifndef skip_glSampleMapATI
void glSampleMapATI(GLuint dst, GLuint interp, GLenum swizzle) {
printf(gl.c);
}
#endif
#ifndef skip_glSampleMaskEXT
void glSampleMaskEXT(GLclampf value, GLboolean invert) {
printf(gl.c);
}
#endif
#ifndef skip_glSampleMaskIndexedNV
void glSampleMaskIndexedNV(GLuint index, GLbitfield mask) {
printf(gl.c);
}
#endif
#ifndef skip_glSampleMaskSGIS
void glSampleMaskSGIS(GLclampf value, GLboolean invert) {
printf(gl.c);
}
#endif
#ifndef skip_glSampleMaski
void glSampleMaski(GLuint index, GLbitfield mask) {
printf(gl.c);
}
#endif
#ifndef skip_glSamplePatternEXT
void glSamplePatternEXT(GLenum pattern) {
printf(gl.c);
}
#endif
#ifndef skip_glSamplePatternSGIS
void glSamplePatternSGIS(GLenum pattern) {
printf(gl.c);
}
#endif
#ifndef skip_glSamplerParameterIiv
void glSamplerParameterIiv(GLuint sampler, GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glSamplerParameterIuiv
void glSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint param) {
printf(gl.c);
}
#endif
#ifndef skip_glSamplerParameterf
void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glSamplerParameterfv
void glSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glSamplerParameteri
void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glSamplerParameteriv
void glSamplerParameteriv(GLuint sampler, GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glScaled
void glScaled(GLdouble x, GLdouble y, GLdouble z) {
printf(gl.c);
}
#endif
#ifndef skip_glScalef
void glScalef(GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glScalexOES
void glScalexOES(GLfixed x, GLfixed y, GLfixed z) {
printf(gl.c);
}
#endif
#ifndef skip_glScissor
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {
printf(gl.c);
}
#endif
#ifndef skip_glScissorArrayv
void glScissorArrayv(GLuint first, GLsizei count, GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glScissorIndexed
void glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height) {
printf(gl.c);
}
#endif
#ifndef skip_glScissorIndexedv
void glScissorIndexedv(GLuint index, GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3b
void glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3bEXT
void glSecondaryColor3bEXT(GLbyte red, GLbyte green, GLbyte blue) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3bv
void glSecondaryColor3bv(GLbyte v) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3bvEXT
void glSecondaryColor3bvEXT(GLbyte v) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3d
void glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3dEXT
void glSecondaryColor3dEXT(GLdouble red, GLdouble green, GLdouble blue) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3dv
void glSecondaryColor3dv(GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3dvEXT
void glSecondaryColor3dvEXT(GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3f
void glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3fEXT
void glSecondaryColor3fEXT(GLfloat red, GLfloat green, GLfloat blue) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3fv
void glSecondaryColor3fv(GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3fvEXT
void glSecondaryColor3fvEXT(GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3hNV
void glSecondaryColor3hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3hvNV
void glSecondaryColor3hvNV(GLhalfNV v) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3i
void glSecondaryColor3i(GLint red, GLint green, GLint blue) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3iEXT
void glSecondaryColor3iEXT(GLint red, GLint green, GLint blue) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3iv
void glSecondaryColor3iv(GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3ivEXT
void glSecondaryColor3ivEXT(GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3s
void glSecondaryColor3s(GLshort red, GLshort green, GLshort blue) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3sEXT
void glSecondaryColor3sEXT(GLshort red, GLshort green, GLshort blue) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3sv
void glSecondaryColor3sv(GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3svEXT
void glSecondaryColor3svEXT(GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3ub
void glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3ubEXT
void glSecondaryColor3ubEXT(GLubyte red, GLubyte green, GLubyte blue) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3ubv
void glSecondaryColor3ubv(GLubyte v) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3ubvEXT
void glSecondaryColor3ubvEXT(GLubyte v) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3ui
void glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3uiEXT
void glSecondaryColor3uiEXT(GLuint red, GLuint green, GLuint blue) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3uiv
void glSecondaryColor3uiv(GLuint v) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3uivEXT
void glSecondaryColor3uivEXT(GLuint v) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3us
void glSecondaryColor3us(GLushort red, GLushort green, GLushort blue) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3usEXT
void glSecondaryColor3usEXT(GLushort red, GLushort green, GLushort blue) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3usv
void glSecondaryColor3usv(GLushort v) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColor3usvEXT
void glSecondaryColor3usvEXT(GLushort v) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColorFormatNV
void glSecondaryColorFormatNV(GLint size, GLenum type, GLsizei stride) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColorP3ui
void glSecondaryColorP3ui(GLenum type, GLuint color) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColorP3uiv
void glSecondaryColorP3uiv(GLenum type, GLuint color) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColorPointer
void glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColorPointerEXT
void glSecondaryColorPointerEXT(GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glSecondaryColorPointerListIBM
void glSecondaryColorPointerListIBM(GLint size, GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride) {
printf(gl.c);
}
#endif
#ifndef skip_glSelectBuffer
void glSelectBuffer(GLsizei size, GLuint buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glSelectPerfMonitorCountersAMD
void glSelectPerfMonitorCountersAMD(GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint counterList) {
printf(gl.c);
}
#endif
#ifndef skip_glSeparableFilter2D
void glSeparableFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid row, GLvoid column) {
printf(gl.c);
}
#endif
#ifndef skip_glSeparableFilter2DEXT
void glSeparableFilter2DEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid row, GLvoid column) {
printf(gl.c);
}
#endif
#ifndef skip_glSetFenceAPPLE
void glSetFenceAPPLE(GLuint fence) {
printf(gl.c);
}
#endif
#ifndef skip_glSetFenceNV
void glSetFenceNV(GLuint fence, GLenum condition) {
printf(gl.c);
}
#endif
#ifndef skip_glSetFragmentShaderConstantATI
void glSetFragmentShaderConstantATI(GLuint dst, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glSetInvariantEXT
void glSetInvariantEXT(GLuint id, GLenum type, GLvoid addr) {
printf(gl.c);
}
#endif
#ifndef skip_glSetLocalConstantEXT
void glSetLocalConstantEXT(GLuint id, GLenum type, GLvoid addr) {
printf(gl.c);
}
#endif
#ifndef skip_glSetMultisamplefvAMD
void glSetMultisamplefvAMD(GLenum pname, GLuint index, GLfloat val) {
printf(gl.c);
}
#endif
#ifndef skip_glShadeModel
void glShadeModel(GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glShaderBinary
void glShaderBinary(GLsizei count, GLuint shaders, GLenum binaryformat, GLvoid binary, GLsizei length) {
printf(gl.c);
}
#endif
#ifndef skip_glShaderOp1EXT
void glShaderOp1EXT(GLenum op, GLuint res, GLuint arg1) {
printf(gl.c);
}
#endif
#ifndef skip_glShaderOp2EXT
void glShaderOp2EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2) {
printf(gl.c);
}
#endif
#ifndef skip_glShaderOp3EXT
void glShaderOp3EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3) {
printf(gl.c);
}
#endif
#ifndef skip_glShaderSource
void glShaderSource(GLuint shader, GLsizei count, GLchar*const string, GLint length) {
printf(gl.c);
}
#endif
#ifndef skip_glShaderSourceARB
void glShaderSourceARB(GLhandleARB shaderObj, GLsizei count, GLcharARB * string, GLint length) {
printf(gl.c);
}
#endif
#ifndef skip_glShaderStorageBlockBinding
void glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding) {
printf(gl.c);
}
#endif
#ifndef skip_glSharpenTexFuncSGIS
void glSharpenTexFuncSGIS(GLenum target, GLsizei n, GLfloat points) {
printf(gl.c);
}
#endif
#ifndef skip_glSpriteParameterfSGIX
void glSpriteParameterfSGIX(GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glSpriteParameterfvSGIX
void glSpriteParameterfvSGIX(GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glSpriteParameteriSGIX
void glSpriteParameteriSGIX(GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glSpriteParameterivSGIX
void glSpriteParameterivSGIX(GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glStartInstrumentsSGIX
void glStartInstrumentsSGIX() {
printf(gl.c);
}
#endif
#ifndef skip_glStencilClearTagEXT
void glStencilClearTagEXT(GLsizei stencilTagBits, GLuint stencilClearTag) {
printf(gl.c);
}
#endif
#ifndef skip_glStencilFillPathInstancedNV
void glStencilFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, GLfloat transformValues) {
printf(gl.c);
}
#endif
#ifndef skip_glStencilFillPathNV
void glStencilFillPathNV(GLuint path, GLenum fillMode, GLuint mask) {
printf(gl.c);
}
#endif
#ifndef skip_glStencilFunc
void glStencilFunc(GLenum func, GLint ref, GLuint mask) {
printf(gl.c);
}
#endif
#ifndef skip_glStencilFuncSeparate
void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) {
printf(gl.c);
}
#endif
#ifndef skip_glStencilFuncSeparateATI
void glStencilFuncSeparateATI(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask) {
printf(gl.c);
}
#endif
#ifndef skip_glStencilMask
void glStencilMask(GLuint mask) {
printf(gl.c);
}
#endif
#ifndef skip_glStencilMaskSeparate
void glStencilMaskSeparate(GLenum face, GLuint mask) {
printf(gl.c);
}
#endif
#ifndef skip_glStencilOp
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
printf(gl.c);
}
#endif
#ifndef skip_glStencilOpSeparate
void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) {
printf(gl.c);
}
#endif
#ifndef skip_glStencilOpSeparateATI
void glStencilOpSeparateATI(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) {
printf(gl.c);
}
#endif
#ifndef skip_glStencilOpValueAMD
void glStencilOpValueAMD(GLenum face, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glStencilStrokePathInstancedNV
void glStencilStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, GLfloat transformValues) {
printf(gl.c);
}
#endif
#ifndef skip_glStencilStrokePathNV
void glStencilStrokePathNV(GLuint path, GLint reference, GLuint mask) {
printf(gl.c);
}
#endif
#ifndef skip_glStopInstrumentsSGIX
void glStopInstrumentsSGIX(GLint marker) {
printf(gl.c);
}
#endif
#ifndef skip_glStringMarkerGREMEDY
void glStringMarkerGREMEDY(GLsizei len, GLvoid string) {
printf(gl.c);
}
#endif
#ifndef skip_glSwizzleEXT
void glSwizzleEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW) {
printf(gl.c);
}
#endif
#ifndef skip_glSyncTextureINTEL
void glSyncTextureINTEL(GLuint texture) {
printf(gl.c);
}
#endif
#ifndef skip_glTagSampleBufferSGIX
void glTagSampleBufferSGIX() {
printf(gl.c);
}
#endif
#ifndef skip_glTangent3bEXT
void glTangent3bEXT(GLbyte tx, GLbyte ty, GLbyte tz) {
printf(gl.c);
}
#endif
#ifndef skip_glTangent3bvEXT
void glTangent3bvEXT(GLbyte v) {
printf(gl.c);
}
#endif
#ifndef skip_glTangent3dEXT
void glTangent3dEXT(GLdouble tx, GLdouble ty, GLdouble tz) {
printf(gl.c);
}
#endif
#ifndef skip_glTangent3dvEXT
void glTangent3dvEXT(GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glTangent3fEXT
void glTangent3fEXT(GLfloat tx, GLfloat ty, GLfloat tz) {
printf(gl.c);
}
#endif
#ifndef skip_glTangent3fvEXT
void glTangent3fvEXT(GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glTangent3iEXT
void glTangent3iEXT(GLint tx, GLint ty, GLint tz) {
printf(gl.c);
}
#endif
#ifndef skip_glTangent3ivEXT
void glTangent3ivEXT(GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glTangent3sEXT
void glTangent3sEXT(GLshort tx, GLshort ty, GLshort tz) {
printf(gl.c);
}
#endif
#ifndef skip_glTangent3svEXT
void glTangent3svEXT(GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glTangentPointerEXT
void glTangentPointerEXT(GLenum type, GLsizei stride, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glTbufferMask3DFX
void glTbufferMask3DFX(GLuint mask) {
printf(gl.c);
}
#endif
#ifndef skip_glTessellationFactorAMD
void glTessellationFactorAMD(GLfloat factor) {
printf(gl.c);
}
#endif
#ifndef skip_glTessellationModeAMD
void glTessellationModeAMD(GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glTestFenceAPPLE
Boolean glTestFenceAPPLE(GLuint fence) {
printf(gl.c);
}
#endif
#ifndef skip_glTestFenceNV
Boolean glTestFenceNV(GLuint fence) {
printf(gl.c);
}
#endif
#ifndef skip_glTestObjectAPPLE
Boolean glTestObjectAPPLE(GLenum object, GLuint name) {
printf(gl.c);
}
#endif
#ifndef skip_glTexBuffer
void glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glTexBufferARB
void glTexBufferARB(GLenum target, GLenum internalformat, GLuint buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glTexBufferEXT
void glTexBufferEXT(GLenum target, GLenum internalformat, GLuint buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glTexBufferRange
void glTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) {
printf(gl.c);
}
#endif
#ifndef skip_glTexBumpParameterfvATI
void glTexBumpParameterfvATI(GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glTexBumpParameterivATI
void glTexBumpParameterivATI(GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord1bOES
void glTexCoord1bOES(GLbyte s) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord1bvOES
void glTexCoord1bvOES(GLbyte coords) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord1d
void glTexCoord1d(GLdouble s) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord1dv
void glTexCoord1dv(GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord1f
void glTexCoord1f(GLfloat s) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord1fv
void glTexCoord1fv(GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord1hNV
void glTexCoord1hNV(GLhalfNV s) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord1hvNV
void glTexCoord1hvNV(GLhalfNV v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord1i
void glTexCoord1i(GLint s) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord1iv
void glTexCoord1iv(GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord1s
void glTexCoord1s(GLshort s) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord1sv
void glTexCoord1sv(GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord1xOES
void glTexCoord1xOES(GLfixed s) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord1xvOES
void glTexCoord1xvOES(GLfixed coords) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord2bOES
void glTexCoord2bOES(GLbyte s, GLbyte t) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord2bvOES
void glTexCoord2bvOES(GLbyte coords) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord2d
void glTexCoord2d(GLdouble s, GLdouble t) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord2dv
void glTexCoord2dv(GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord2f
void glTexCoord2f(GLfloat s, GLfloat t) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord2fColor3fVertex3fSUN
void glTexCoord2fColor3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord2fColor3fVertex3fvSUN
void glTexCoord2fColor3fVertex3fvSUN(GLfloat tc, GLfloat c, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord2fColor4fNormal3fVertex3fSUN
void glTexCoord2fColor4fNormal3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord2fColor4fNormal3fVertex3fvSUN
void glTexCoord2fColor4fNormal3fVertex3fvSUN(GLfloat tc, GLfloat c, GLfloat n, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord2fColor4ubVertex3fSUN
void glTexCoord2fColor4ubVertex3fSUN(GLfloat s, GLfloat t, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord2fColor4ubVertex3fvSUN
void glTexCoord2fColor4ubVertex3fvSUN(GLfloat tc, GLubyte c, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord2fNormal3fVertex3fSUN
void glTexCoord2fNormal3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord2fNormal3fVertex3fvSUN
void glTexCoord2fNormal3fVertex3fvSUN(GLfloat tc, GLfloat n, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord2fVertex3fSUN
void glTexCoord2fVertex3fSUN(GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord2fVertex3fvSUN
void glTexCoord2fVertex3fvSUN(GLfloat tc, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord2fv
void glTexCoord2fv(GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord2hNV
void glTexCoord2hNV(GLhalfNV s, GLhalfNV t) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord2hvNV
void glTexCoord2hvNV(GLhalfNV v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord2i
void glTexCoord2i(GLint s, GLint t) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord2iv
void glTexCoord2iv(GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord2s
void glTexCoord2s(GLshort s, GLshort t) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord2sv
void glTexCoord2sv(GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord2xOES
void glTexCoord2xOES(GLfixed s, GLfixed t) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord2xvOES
void glTexCoord2xvOES(GLfixed coords) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord3bOES
void glTexCoord3bOES(GLbyte s, GLbyte t, GLbyte r) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord3bvOES
void glTexCoord3bvOES(GLbyte coords) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord3d
void glTexCoord3d(GLdouble s, GLdouble t, GLdouble r) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord3dv
void glTexCoord3dv(GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord3f
void glTexCoord3f(GLfloat s, GLfloat t, GLfloat r) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord3fv
void glTexCoord3fv(GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord3hNV
void glTexCoord3hNV(GLhalfNV s, GLhalfNV t, GLhalfNV r) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord3hvNV
void glTexCoord3hvNV(GLhalfNV v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord3i
void glTexCoord3i(GLint s, GLint t, GLint r) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord3iv
void glTexCoord3iv(GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord3s
void glTexCoord3s(GLshort s, GLshort t, GLshort r) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord3sv
void glTexCoord3sv(GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord3xOES
void glTexCoord3xOES(GLfixed s, GLfixed t, GLfixed r) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord3xvOES
void glTexCoord3xvOES(GLfixed coords) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord4bOES
void glTexCoord4bOES(GLbyte s, GLbyte t, GLbyte r, GLbyte q) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord4bvOES
void glTexCoord4bvOES(GLbyte coords) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord4d
void glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord4dv
void glTexCoord4dv(GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord4f
void glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord4fColor4fNormal3fVertex4fSUN
void glTexCoord4fColor4fNormal3fVertex4fSUN(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord4fColor4fNormal3fVertex4fvSUN
void glTexCoord4fColor4fNormal3fVertex4fvSUN(GLfloat tc, GLfloat c, GLfloat n, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord4fVertex4fSUN
void glTexCoord4fVertex4fSUN(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord4fVertex4fvSUN
void glTexCoord4fVertex4fvSUN(GLfloat tc, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord4fv
void glTexCoord4fv(GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord4hNV
void glTexCoord4hNV(GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord4hvNV
void glTexCoord4hvNV(GLhalfNV v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord4i
void glTexCoord4i(GLint s, GLint t, GLint r, GLint q) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord4iv
void glTexCoord4iv(GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord4s
void glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord4sv
void glTexCoord4sv(GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord4xOES
void glTexCoord4xOES(GLfixed s, GLfixed t, GLfixed r, GLfixed q) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoord4xvOES
void glTexCoord4xvOES(GLfixed coords) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoordFormatNV
void glTexCoordFormatNV(GLint size, GLenum type, GLsizei stride) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoordP1ui
void glTexCoordP1ui(GLenum type, GLuint coords) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoordP1uiv
void glTexCoordP1uiv(GLenum type, GLuint coords) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoordP2ui
void glTexCoordP2ui(GLenum type, GLuint coords) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoordP2uiv
void glTexCoordP2uiv(GLenum type, GLuint coords) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoordP3ui
void glTexCoordP3ui(GLenum type, GLuint coords) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoordP3uiv
void glTexCoordP3uiv(GLenum type, GLuint coords) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoordP4ui
void glTexCoordP4ui(GLenum type, GLuint coords) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoordP4uiv
void glTexCoordP4uiv(GLenum type, GLuint coords) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoordPointer
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoordPointerEXT
void glTexCoordPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoordPointerListIBM
void glTexCoordPointerListIBM(GLint size, GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride) {
printf(gl.c);
}
#endif
#ifndef skip_glTexCoordPointervINTEL
void glTexCoordPointervINTEL(GLint size, GLenum type, GLvoid * pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glTexEnvf
void glTexEnvf(GLenum target, GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glTexEnvfv
void glTexEnvfv(GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glTexEnvi
void glTexEnvi(GLenum target, GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glTexEnviv
void glTexEnviv(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glTexEnvxOES
void glTexEnvxOES(GLenum target, GLenum pname, GLfixed param) {
printf(gl.c);
}
#endif
#ifndef skip_glTexEnvxvOES
void glTexEnvxvOES(GLenum target, GLenum pname, GLfixed params) {
printf(gl.c);
}
#endif
#ifndef skip_glTexFilterFuncSGIS
void glTexFilterFuncSGIS(GLenum target, GLenum filter, GLsizei n, GLfloat weights) {
printf(gl.c);
}
#endif
#ifndef skip_glTexGend
void glTexGend(GLenum coord, GLenum pname, GLdouble param) {
printf(gl.c);
}
#endif
#ifndef skip_glTexGendv
void glTexGendv(GLenum coord, GLenum pname, GLdouble params) {
printf(gl.c);
}
#endif
#ifndef skip_glTexGenf
void glTexGenf(GLenum coord, GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glTexGenfv
void glTexGenfv(GLenum coord, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glTexGeni
void glTexGeni(GLenum coord, GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glTexGeniv
void glTexGeniv(GLenum coord, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glTexGenxOES
void glTexGenxOES(GLenum coord, GLenum pname, GLfixed param) {
printf(gl.c);
}
#endif
#ifndef skip_glTexGenxvOES
void glTexGenxvOES(GLenum coord, GLenum pname, GLfixed params) {
printf(gl.c);
}
#endif
#ifndef skip_glTexImage1D
void glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glTexImage2D
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glTexImage2DMultisample
void glTexImage2DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
printf(gl.c);
}
#endif
#ifndef skip_glTexImage2DMultisampleCoverageNV
void glTexImage2DMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations) {
printf(gl.c);
}
#endif
#ifndef skip_glTexImage3D
void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glTexImage3DEXT
void glTexImage3DEXT(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glTexImage3DMultisample
void glTexImage3DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
printf(gl.c);
}
#endif
#ifndef skip_glTexImage3DMultisampleCoverageNV
void glTexImage3DMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations) {
printf(gl.c);
}
#endif
#ifndef skip_glTexImage4DSGIS
void glTexImage4DSGIS(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLint border, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glTexParameterIiv
void glTexParameterIiv(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glTexParameterIivEXT
void glTexParameterIivEXT(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glTexParameterIuiv
void glTexParameterIuiv(GLenum target, GLenum pname, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glTexParameterIuivEXT
void glTexParameterIuivEXT(GLenum target, GLenum pname, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glTexParameterf
void glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glTexParameterfv
void glTexParameterfv(GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glTexParameteri
void glTexParameteri(GLenum target, GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glTexParameteriv
void glTexParameteriv(GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glTexParameterxOES
void glTexParameterxOES(GLenum target, GLenum pname, GLfixed param) {
printf(gl.c);
}
#endif
#ifndef skip_glTexParameterxvOES
void glTexParameterxvOES(GLenum target, GLenum pname, GLfixed params) {
printf(gl.c);
}
#endif
#ifndef skip_glTexRenderbufferNV
void glTexRenderbufferNV(GLenum target, GLuint renderbuffer) {
printf(gl.c);
}
#endif
#ifndef skip_glTexStorage1D
void glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) {
printf(gl.c);
}
#endif
#ifndef skip_glTexStorage2D
void glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) {
printf(gl.c);
}
#endif
#ifndef skip_glTexStorage2DMultisample
void glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
printf(gl.c);
}
#endif
#ifndef skip_glTexStorage3D
void glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) {
printf(gl.c);
}
#endif
#ifndef skip_glTexStorage3DMultisample
void glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
printf(gl.c);
}
#endif
#ifndef skip_glTexStorageSparseAMD
void glTexStorageSparseAMD(GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags) {
printf(gl.c);
}
#endif
#ifndef skip_glTexSubImage1D
void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glTexSubImage1DEXT
void glTexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glTexSubImage2D
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glTexSubImage2DEXT
void glTexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glTexSubImage3D
void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glTexSubImage3DEXT
void glTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glTexSubImage4DSGIS
void glTexSubImage4DSGIS(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint woffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureBarrierNV
void glTextureBarrierNV() {
printf(gl.c);
}
#endif
#ifndef skip_glTextureBufferEXT
void glTextureBufferEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureBufferRangeEXT
void glTextureBufferRangeEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureColorMaskSGIS
void glTextureColorMaskSGIS(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureImage1DEXT
void glTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureImage2DEXT
void glTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureImage2DMultisampleCoverageNV
void glTextureImage2DMultisampleCoverageNV(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureImage2DMultisampleNV
void glTextureImage2DMultisampleNV(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureImage3DEXT
void glTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureImage3DMultisampleCoverageNV
void glTextureImage3DMultisampleCoverageNV(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureImage3DMultisampleNV
void glTextureImage3DMultisampleNV(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureLightEXT
void glTextureLightEXT(GLenum pname) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureMaterialEXT
void glTextureMaterialEXT(GLenum face, GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureNormalEXT
void glTextureNormalEXT(GLenum mode) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureParameterIivEXT
void glTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureParameterIuivEXT
void glTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, GLuint params) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureParameterfEXT
void glTextureParameterfEXT(GLuint texture, GLenum target, GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureParameterfvEXT
void glTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureParameteriEXT
void glTextureParameteriEXT(GLuint texture, GLenum target, GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureParameterivEXT
void glTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureRangeAPPLE
void glTextureRangeAPPLE(GLenum target, GLsizei length, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureRenderbufferEXT
void glTextureRenderbufferEXT(GLuint texture, GLenum target, GLuint renderbuffer) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureStorage1DEXT
void glTextureStorage1DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureStorage2DEXT
void glTextureStorage2DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureStorage2DMultisampleEXT
void glTextureStorage2DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureStorage3DEXT
void glTextureStorage3DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureStorage3DMultisampleEXT
void glTextureStorage3DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureStorageSparseAMD
void glTextureStorageSparseAMD(GLuint texture, GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureSubImage1DEXT
void glTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureSubImage2DEXT
void glTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureSubImage3DEXT
void glTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLvoid pixels) {
printf(gl.c);
}
#endif
#ifndef skip_glTextureView
void glTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers) {
printf(gl.c);
}
#endif
#ifndef skip_glTrackMatrixNV
void glTrackMatrixNV(GLenum target, GLuint address, GLenum matrix, GLenum transform) {
printf(gl.c);
}
#endif
#ifndef skip_glTransformFeedbackAttribsNV
void glTransformFeedbackAttribsNV(GLsizei count, GLint attribs, GLenum bufferMode) {
printf(gl.c);
}
#endif
#ifndef skip_glTransformFeedbackStreamAttribsNV
void glTransformFeedbackStreamAttribsNV(GLsizei count, GLint attribs, GLsizei nbuffers, GLint bufstreams, GLenum bufferMode) {
printf(gl.c);
}
#endif
#ifndef skip_glTransformFeedbackVaryings
void glTransformFeedbackVaryings(GLuint program, GLsizei count, GLchar*const varyings, GLenum bufferMode) {
printf(gl.c);
}
#endif
#ifndef skip_glTransformFeedbackVaryingsEXT
void glTransformFeedbackVaryingsEXT(GLuint program, GLsizei count, GLchar * varyings, GLenum bufferMode) {
printf(gl.c);
}
#endif
#ifndef skip_glTransformFeedbackVaryingsNV
void glTransformFeedbackVaryingsNV(GLuint program, GLsizei count, GLint locations, GLenum bufferMode) {
printf(gl.c);
}
#endif
#ifndef skip_glTransformPathNV
void glTransformPathNV(GLuint resultPath, GLuint srcPath, GLenum transformType, GLfloat transformValues) {
printf(gl.c);
}
#endif
#ifndef skip_glTranslated
void glTranslated(GLdouble x, GLdouble y, GLdouble z) {
printf(gl.c);
}
#endif
#ifndef skip_glTranslatef
void glTranslatef(GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glTranslatexOES
void glTranslatexOES(GLfixed x, GLfixed y, GLfixed z) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform1d
void glUniform1d(GLint location, GLdouble x) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform1dv
void glUniform1dv(GLint location, GLsizei count, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform1f
void glUniform1f(GLint location, GLfloat v0) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform1fARB
void glUniform1fARB(GLint location, GLfloat v0) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform1fv
void glUniform1fv(GLint location, GLsizei count, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform1fvARB
void glUniform1fvARB(GLint location, GLsizei count, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform1i
void glUniform1i(GLint location, GLint v0) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform1i64NV
void glUniform1i64NV(GLint location, GLint64EXT x) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform1i64vNV
void glUniform1i64vNV(GLint location, GLsizei count, GLint64EXT value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform1iARB
void glUniform1iARB(GLint location, GLint v0) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform1iv
void glUniform1iv(GLint location, GLsizei count, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform1ivARB
void glUniform1ivARB(GLint location, GLsizei count, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform1ui
void glUniform1ui(GLint location, GLuint v0) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform1ui64NV
void glUniform1ui64NV(GLint location, GLuint64EXT x) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform1ui64vNV
void glUniform1ui64vNV(GLint location, GLsizei count, GLuint64EXT value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform1uiEXT
void glUniform1uiEXT(GLint location, GLuint v0) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform1uiv
void glUniform1uiv(GLint location, GLsizei count, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform1uivEXT
void glUniform1uivEXT(GLint location, GLsizei count, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform2d
void glUniform2d(GLint location, GLdouble x, GLdouble y) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform2dv
void glUniform2dv(GLint location, GLsizei count, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform2f
void glUniform2f(GLint location, GLfloat v0, GLfloat v1) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform2fARB
void glUniform2fARB(GLint location, GLfloat v0, GLfloat v1) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform2fv
void glUniform2fv(GLint location, GLsizei count, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform2fvARB
void glUniform2fvARB(GLint location, GLsizei count, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform2i
void glUniform2i(GLint location, GLint v0, GLint v1) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform2i64NV
void glUniform2i64NV(GLint location, GLint64EXT x, GLint64EXT y) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform2i64vNV
void glUniform2i64vNV(GLint location, GLsizei count, GLint64EXT value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform2iARB
void glUniform2iARB(GLint location, GLint v0, GLint v1) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform2iv
void glUniform2iv(GLint location, GLsizei count, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform2ivARB
void glUniform2ivARB(GLint location, GLsizei count, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform2ui
void glUniform2ui(GLint location, GLuint v0, GLuint v1) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform2ui64NV
void glUniform2ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform2ui64vNV
void glUniform2ui64vNV(GLint location, GLsizei count, GLuint64EXT value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform2uiEXT
void glUniform2uiEXT(GLint location, GLuint v0, GLuint v1) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform2uiv
void glUniform2uiv(GLint location, GLsizei count, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform2uivEXT
void glUniform2uivEXT(GLint location, GLsizei count, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform3d
void glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform3dv
void glUniform3dv(GLint location, GLsizei count, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform3f
void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform3fARB
void glUniform3fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform3fv
void glUniform3fv(GLint location, GLsizei count, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform3fvARB
void glUniform3fvARB(GLint location, GLsizei count, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform3i
void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform3i64NV
void glUniform3i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform3i64vNV
void glUniform3i64vNV(GLint location, GLsizei count, GLint64EXT value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform3iARB
void glUniform3iARB(GLint location, GLint v0, GLint v1, GLint v2) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform3iv
void glUniform3iv(GLint location, GLsizei count, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform3ivARB
void glUniform3ivARB(GLint location, GLsizei count, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform3ui
void glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform3ui64NV
void glUniform3ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform3ui64vNV
void glUniform3ui64vNV(GLint location, GLsizei count, GLuint64EXT value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform3uiEXT
void glUniform3uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform3uiv
void glUniform3uiv(GLint location, GLsizei count, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform3uivEXT
void glUniform3uivEXT(GLint location, GLsizei count, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform4d
void glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform4dv
void glUniform4dv(GLint location, GLsizei count, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform4f
void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform4fARB
void glUniform4fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform4fv
void glUniform4fv(GLint location, GLsizei count, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform4fvARB
void glUniform4fvARB(GLint location, GLsizei count, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform4i
void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform4i64NV
void glUniform4i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform4i64vNV
void glUniform4i64vNV(GLint location, GLsizei count, GLint64EXT value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform4iARB
void glUniform4iARB(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform4iv
void glUniform4iv(GLint location, GLsizei count, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform4ivARB
void glUniform4ivARB(GLint location, GLsizei count, GLint value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform4ui
void glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform4ui64NV
void glUniform4ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform4ui64vNV
void glUniform4ui64vNV(GLint location, GLsizei count, GLuint64EXT value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform4uiEXT
void glUniform4uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform4uiv
void glUniform4uiv(GLint location, GLsizei count, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniform4uivEXT
void glUniform4uivEXT(GLint location, GLsizei count, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformBlockBinding
void glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformBufferEXT
void glUniformBufferEXT(GLuint program, GLint location, GLuint buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformHandleui64NV
void glUniformHandleui64NV(GLint location, GLuint64 value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformHandleui64vNV
void glUniformHandleui64vNV(GLint location, GLsizei count, GLuint64 value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformMatrix2dv
void glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformMatrix2fv
void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformMatrix2fvARB
void glUniformMatrix2fvARB(GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformMatrix2x3dv
void glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformMatrix2x3fv
void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformMatrix2x4dv
void glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformMatrix2x4fv
void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformMatrix3dv
void glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformMatrix3fv
void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformMatrix3fvARB
void glUniformMatrix3fvARB(GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformMatrix3x2dv
void glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformMatrix3x2fv
void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformMatrix3x4dv
void glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformMatrix3x4fv
void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformMatrix4dv
void glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformMatrix4fv
void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformMatrix4fvARB
void glUniformMatrix4fvARB(GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformMatrix4x2dv
void glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformMatrix4x2fv
void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformMatrix4x3dv
void glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformMatrix4x3fv
void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformSubroutinesuiv
void glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, GLuint indices) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformui64NV
void glUniformui64NV(GLint location, GLuint64EXT value) {
printf(gl.c);
}
#endif
#ifndef skip_glUniformui64vNV
void glUniformui64vNV(GLint location, GLsizei count, GLuint64EXT value) {
printf(gl.c);
}
#endif
#ifndef skip_glUnlockArraysEXT
void glUnlockArraysEXT() {
printf(gl.c);
}
#endif
#ifndef skip_glUnmapBuffer
Boolean glUnmapBuffer(GLenum target) {
printf(gl.c);
}
#endif
#ifndef skip_glUnmapBufferARB
Boolean glUnmapBufferARB(GLenum target) {
printf(gl.c);
}
#endif
#ifndef skip_glUnmapNamedBufferEXT
Boolean glUnmapNamedBufferEXT(GLuint buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glUnmapObjectBufferATI
void glUnmapObjectBufferATI(GLuint buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glUnmapTexture2DINTEL
void glUnmapTexture2DINTEL(GLuint texture, GLint level) {
printf(gl.c);
}
#endif
#ifndef skip_glUpdateObjectBufferATI
void glUpdateObjectBufferATI(GLuint buffer, GLuint offset, GLsizei size, GLvoid pointer, GLenum preserve) {
printf(gl.c);
}
#endif
#ifndef skip_glUseProgram
void glUseProgram(GLuint program) {
printf(gl.c);
}
#endif
#ifndef skip_glUseProgramObjectARB
void glUseProgramObjectARB(GLhandleARB programObj) {
printf(gl.c);
}
#endif
#ifndef skip_glUseProgramStages
void glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program) {
printf(gl.c);
}
#endif
#ifndef skip_glUseShaderProgramEXT
void glUseShaderProgramEXT(GLenum type, GLuint program) {
printf(gl.c);
}
#endif
#ifndef skip_glVDPAUFiniNV
void glVDPAUFiniNV() {
printf(gl.c);
}
#endif
#ifndef skip_glVDPAUGetSurfaceivNV
void glVDPAUGetSurfaceivNV(GLvdpauSurfaceNV surface, GLenum pname, GLsizei bufSize, GLsizei length, GLint values) {
printf(gl.c);
}
#endif
#ifndef skip_glVDPAUInitNV
void glVDPAUInitNV(GLvoid vdpDevice, GLvoid getProcAddress) {
printf(gl.c);
}
#endif
#ifndef skip_glVDPAUIsSurfaceNV
void glVDPAUIsSurfaceNV(GLvdpauSurfaceNV surface) {
printf(gl.c);
}
#endif
#ifndef skip_glVDPAUMapSurfacesNV
void glVDPAUMapSurfacesNV(GLsizei numSurfaces, GLvdpauSurfaceNV surfaces) {
printf(gl.c);
}
#endif
#ifndef skip_glVDPAURegisterOutputSurfaceNV
vdpauSurfaceNV glVDPAURegisterOutputSurfaceNV(GLvoid * vdpSurface, GLenum target, GLsizei numTextureNames, GLuint textureNames) {
printf(gl.c);
}
#endif
#ifndef skip_glVDPAURegisterVideoSurfaceNV
vdpauSurfaceNV glVDPAURegisterVideoSurfaceNV(GLvoid vdpSurface, GLenum target, GLsizei numTextureNames, GLuint textureNames) {
printf(gl.c);
}
#endif
#ifndef skip_glVDPAUSurfaceAccessNV
void glVDPAUSurfaceAccessNV(GLvdpauSurfaceNV surface, GLenum access) {
printf(gl.c);
}
#endif
#ifndef skip_glVDPAUUnmapSurfacesNV
void glVDPAUUnmapSurfacesNV(GLsizei numSurface, GLvdpauSurfaceNV surfaces) {
printf(gl.c);
}
#endif
#ifndef skip_glVDPAUUnregisterSurfaceNV
void glVDPAUUnregisterSurfaceNV(GLvdpauSurfaceNV surface) {
printf(gl.c);
}
#endif
#ifndef skip_glValidateProgram
void glValidateProgram(GLuint program) {
printf(gl.c);
}
#endif
#ifndef skip_glValidateProgramARB
void glValidateProgramARB(GLhandleARB programObj) {
printf(gl.c);
}
#endif
#ifndef skip_glValidateProgramPipeline
void glValidateProgramPipeline(GLuint pipeline) {
printf(gl.c);
}
#endif
#ifndef skip_glVariantArrayObjectATI
void glVariantArrayObjectATI(GLuint id, GLenum type, GLsizei stride, GLuint buffer, GLuint offset) {
printf(gl.c);
}
#endif
#ifndef skip_glVariantPointerEXT
void glVariantPointerEXT(GLuint id, GLenum type, GLuint stride, GLvoid addr) {
printf(gl.c);
}
#endif
#ifndef skip_glVariantbvEXT
void glVariantbvEXT(GLuint id, GLbyte addr) {
printf(gl.c);
}
#endif
#ifndef skip_glVariantdvEXT
void glVariantdvEXT(GLuint id, GLdouble addr) {
printf(gl.c);
}
#endif
#ifndef skip_glVariantfvEXT
void glVariantfvEXT(GLuint id, GLfloat addr) {
printf(gl.c);
}
#endif
#ifndef skip_glVariantivEXT
void glVariantivEXT(GLuint id, GLint addr) {
printf(gl.c);
}
#endif
#ifndef skip_glVariantsvEXT
void glVariantsvEXT(GLuint id, GLshort addr) {
printf(gl.c);
}
#endif
#ifndef skip_glVariantubvEXT
void glVariantubvEXT(GLuint id, GLubyte addr) {
printf(gl.c);
}
#endif
#ifndef skip_glVariantuivEXT
void glVariantuivEXT(GLuint id, GLuint addr) {
printf(gl.c);
}
#endif
#ifndef skip_glVariantusvEXT
void glVariantusvEXT(GLuint id, GLushort addr) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex2bOES
void glVertex2bOES(GLbyte x) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex2bvOES
void glVertex2bvOES(GLbyte coords) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex2d
void glVertex2d(GLdouble x, GLdouble y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex2dv
void glVertex2dv(GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex2f
void glVertex2f(GLfloat x, GLfloat y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex2fv
void glVertex2fv(GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex2hNV
void glVertex2hNV(GLhalfNV x, GLhalfNV y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex2hvNV
void glVertex2hvNV(GLhalfNV v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex2i
void glVertex2i(GLint x, GLint y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex2iv
void glVertex2iv(GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex2s
void glVertex2s(GLshort x, GLshort y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex2sv
void glVertex2sv(GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex2xOES
void glVertex2xOES(GLfixed x) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex2xvOES
void glVertex2xvOES(GLfixed coords) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex3bOES
void glVertex3bOES(GLbyte x, GLbyte y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex3bvOES
void glVertex3bvOES(GLbyte coords) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex3d
void glVertex3d(GLdouble x, GLdouble y, GLdouble z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex3dv
void glVertex3dv(GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex3f
void glVertex3f(GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex3fv
void glVertex3fv(GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex3hNV
void glVertex3hNV(GLhalfNV x, GLhalfNV y, GLhalfNV z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex3hvNV
void glVertex3hvNV(GLhalfNV v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex3i
void glVertex3i(GLint x, GLint y, GLint z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex3iv
void glVertex3iv(GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex3s
void glVertex3s(GLshort x, GLshort y, GLshort z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex3sv
void glVertex3sv(GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex3xOES
void glVertex3xOES(GLfixed x, GLfixed y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex3xvOES
void glVertex3xvOES(GLfixed coords) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex4bOES
void glVertex4bOES(GLbyte x, GLbyte y, GLbyte z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex4bvOES
void glVertex4bvOES(GLbyte coords) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex4d
void glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex4dv
void glVertex4dv(GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex4f
void glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex4fv
void glVertex4fv(GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex4hNV
void glVertex4hNV(GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex4hvNV
void glVertex4hvNV(GLhalfNV v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex4i
void glVertex4i(GLint x, GLint y, GLint z, GLint w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex4iv
void glVertex4iv(GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex4s
void glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex4sv
void glVertex4sv(GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex4xOES
void glVertex4xOES(GLfixed x, GLfixed y, GLfixed z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertex4xvOES
void glVertex4xvOES(GLfixed coords) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexArrayBindVertexBufferEXT
void glVertexArrayBindVertexBufferEXT(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexArrayColorOffsetEXT
void glVertexArrayColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexArrayEdgeFlagOffsetEXT
void glVertexArrayEdgeFlagOffsetEXT(GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexArrayFogCoordOffsetEXT
void glVertexArrayFogCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexArrayIndexOffsetEXT
void glVertexArrayIndexOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexArrayMultiTexCoordOffsetEXT
void glVertexArrayMultiTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexArrayNormalOffsetEXT
void glVertexArrayNormalOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexArrayParameteriAPPLE
void glVertexArrayParameteriAPPLE(GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexArrayRangeAPPLE
void glVertexArrayRangeAPPLE(GLsizei length, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexArrayRangeNV
void glVertexArrayRangeNV(GLsizei length, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexArraySecondaryColorOffsetEXT
void glVertexArraySecondaryColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexArrayTexCoordOffsetEXT
void glVertexArrayTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexArrayVertexAttribBindingEXT
void glVertexArrayVertexAttribBindingEXT(GLuint vaobj, GLuint attribindex, GLuint bindingindex) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexArrayVertexAttribFormatEXT
void glVertexArrayVertexAttribFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexArrayVertexAttribIFormatEXT
void glVertexArrayVertexAttribIFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexArrayVertexAttribIOffsetEXT
void glVertexArrayVertexAttribIOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexArrayVertexAttribLFormatEXT
void glVertexArrayVertexAttribLFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexArrayVertexAttribLOffsetEXT
void glVertexArrayVertexAttribLOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexArrayVertexAttribOffsetEXT
void glVertexArrayVertexAttribOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexArrayVertexBindingDivisorEXT
void glVertexArrayVertexBindingDivisorEXT(GLuint vaobj, GLuint bindingindex, GLuint divisor) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexArrayVertexOffsetEXT
void glVertexArrayVertexOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib1d
void glVertexAttrib1d(GLuint index, GLdouble x) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib1dARB
void glVertexAttrib1dARB(GLuint index, GLdouble x) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib1dNV
void glVertexAttrib1dNV(GLuint index, GLdouble x) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib1dv
void glVertexAttrib1dv(GLuint index, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib1dvARB
void glVertexAttrib1dvARB(GLuint index, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib1dvNV
void glVertexAttrib1dvNV(GLuint index, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib1f
void glVertexAttrib1f(GLuint index, GLfloat x) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib1fARB
void glVertexAttrib1fARB(GLuint index, GLfloat x) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib1fNV
void glVertexAttrib1fNV(GLuint index, GLfloat x) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib1fv
void glVertexAttrib1fv(GLuint index, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib1fvARB
void glVertexAttrib1fvARB(GLuint index, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib1fvNV
void glVertexAttrib1fvNV(GLuint index, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib1hNV
void glVertexAttrib1hNV(GLuint index, GLhalfNV x) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib1hvNV
void glVertexAttrib1hvNV(GLuint index, GLhalfNV v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib1s
void glVertexAttrib1s(GLuint index, GLshort x) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib1sARB
void glVertexAttrib1sARB(GLuint index, GLshort x) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib1sNV
void glVertexAttrib1sNV(GLuint index, GLshort x) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib1sv
void glVertexAttrib1sv(GLuint index, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib1svARB
void glVertexAttrib1svARB(GLuint index, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib1svNV
void glVertexAttrib1svNV(GLuint index, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib2d
void glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib2dARB
void glVertexAttrib2dARB(GLuint index, GLdouble x, GLdouble y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib2dNV
void glVertexAttrib2dNV(GLuint index, GLdouble x, GLdouble y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib2dv
void glVertexAttrib2dv(GLuint index, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib2dvARB
void glVertexAttrib2dvARB(GLuint index, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib2dvNV
void glVertexAttrib2dvNV(GLuint index, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib2f
void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib2fARB
void glVertexAttrib2fARB(GLuint index, GLfloat x, GLfloat y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib2fNV
void glVertexAttrib2fNV(GLuint index, GLfloat x, GLfloat y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib2fv
void glVertexAttrib2fv(GLuint index, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib2fvARB
void glVertexAttrib2fvARB(GLuint index, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib2fvNV
void glVertexAttrib2fvNV(GLuint index, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib2hNV
void glVertexAttrib2hNV(GLuint index, GLhalfNV x, GLhalfNV y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib2hvNV
void glVertexAttrib2hvNV(GLuint index, GLhalfNV v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib2s
void glVertexAttrib2s(GLuint index, GLshort x, GLshort y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib2sARB
void glVertexAttrib2sARB(GLuint index, GLshort x, GLshort y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib2sNV
void glVertexAttrib2sNV(GLuint index, GLshort x, GLshort y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib2sv
void glVertexAttrib2sv(GLuint index, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib2svARB
void glVertexAttrib2svARB(GLuint index, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib2svNV
void glVertexAttrib2svNV(GLuint index, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib3d
void glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib3dARB
void glVertexAttrib3dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib3dNV
void glVertexAttrib3dNV(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib3dv
void glVertexAttrib3dv(GLuint index, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib3dvARB
void glVertexAttrib3dvARB(GLuint index, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib3dvNV
void glVertexAttrib3dvNV(GLuint index, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib3f
void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib3fARB
void glVertexAttrib3fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib3fNV
void glVertexAttrib3fNV(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib3fv
void glVertexAttrib3fv(GLuint index, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib3fvARB
void glVertexAttrib3fvARB(GLuint index, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib3fvNV
void glVertexAttrib3fvNV(GLuint index, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib3hNV
void glVertexAttrib3hNV(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib3hvNV
void glVertexAttrib3hvNV(GLuint index, GLhalfNV v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib3s
void glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib3sARB
void glVertexAttrib3sARB(GLuint index, GLshort x, GLshort y, GLshort z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib3sNV
void glVertexAttrib3sNV(GLuint index, GLshort x, GLshort y, GLshort z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib3sv
void glVertexAttrib3sv(GLuint index, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib3svARB
void glVertexAttrib3svARB(GLuint index, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib3svNV
void glVertexAttrib3svNV(GLuint index, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4Nbv
void glVertexAttrib4Nbv(GLuint index, GLbyte v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4NbvARB
void glVertexAttrib4NbvARB(GLuint index, GLbyte v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4Niv
void glVertexAttrib4Niv(GLuint index, GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4NivARB
void glVertexAttrib4NivARB(GLuint index, GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4Nsv
void glVertexAttrib4Nsv(GLuint index, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4NsvARB
void glVertexAttrib4NsvARB(GLuint index, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4Nub
void glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4NubARB
void glVertexAttrib4NubARB(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4Nubv
void glVertexAttrib4Nubv(GLuint index, GLubyte v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4NubvARB
void glVertexAttrib4NubvARB(GLuint index, GLubyte v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4Nuiv
void glVertexAttrib4Nuiv(GLuint index, GLuint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4NuivARB
void glVertexAttrib4NuivARB(GLuint index, GLuint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4Nusv
void glVertexAttrib4Nusv(GLuint index, GLushort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4NusvARB
void glVertexAttrib4NusvARB(GLuint index, GLushort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4bv
void glVertexAttrib4bv(GLuint index, GLbyte v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4bvARB
void glVertexAttrib4bvARB(GLuint index, GLbyte v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4d
void glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4dARB
void glVertexAttrib4dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4dNV
void glVertexAttrib4dNV(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4dv
void glVertexAttrib4dv(GLuint index, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4dvARB
void glVertexAttrib4dvARB(GLuint index, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4dvNV
void glVertexAttrib4dvNV(GLuint index, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4f
void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4fARB
void glVertexAttrib4fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4fNV
void glVertexAttrib4fNV(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4fv
void glVertexAttrib4fv(GLuint index, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4fvARB
void glVertexAttrib4fvARB(GLuint index, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4fvNV
void glVertexAttrib4fvNV(GLuint index, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4hNV
void glVertexAttrib4hNV(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4hvNV
void glVertexAttrib4hvNV(GLuint index, GLhalfNV v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4iv
void glVertexAttrib4iv(GLuint index, GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4ivARB
void glVertexAttrib4ivARB(GLuint index, GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4s
void glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4sARB
void glVertexAttrib4sARB(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4sNV
void glVertexAttrib4sNV(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4sv
void glVertexAttrib4sv(GLuint index, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4svARB
void glVertexAttrib4svARB(GLuint index, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4svNV
void glVertexAttrib4svNV(GLuint index, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4ubNV
void glVertexAttrib4ubNV(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4ubv
void glVertexAttrib4ubv(GLuint index, GLubyte v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4ubvARB
void glVertexAttrib4ubvARB(GLuint index, GLubyte v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4ubvNV
void glVertexAttrib4ubvNV(GLuint index, GLubyte v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4uiv
void glVertexAttrib4uiv(GLuint index, GLuint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4uivARB
void glVertexAttrib4uivARB(GLuint index, GLuint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4usv
void glVertexAttrib4usv(GLuint index, GLushort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttrib4usvARB
void glVertexAttrib4usvARB(GLuint index, GLushort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribArrayObjectATI
void glVertexAttribArrayObjectATI(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint buffer, GLuint offset) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribBinding
void glVertexAttribBinding(GLuint attribindex, GLuint bindingindex) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribDivisor
void glVertexAttribDivisor(GLuint index, GLuint divisor) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribDivisorARB
void glVertexAttribDivisorARB(GLuint index, GLuint divisor) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribFormat
void glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribFormatNV
void glVertexAttribFormatNV(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI1i
void glVertexAttribI1i(GLuint index, GLint x) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI1iEXT
void glVertexAttribI1iEXT(GLuint index, GLint x) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI1iv
void glVertexAttribI1iv(GLuint index, GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI1ivEXT
void glVertexAttribI1ivEXT(GLuint index, GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI1ui
void glVertexAttribI1ui(GLuint index, GLuint x) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI1uiEXT
void glVertexAttribI1uiEXT(GLuint index, GLuint x) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI1uiv
void glVertexAttribI1uiv(GLuint index, GLuint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI1uivEXT
void glVertexAttribI1uivEXT(GLuint index, GLuint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI2i
void glVertexAttribI2i(GLuint index, GLint x, GLint y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI2iEXT
void glVertexAttribI2iEXT(GLuint index, GLint x, GLint y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI2iv
void glVertexAttribI2iv(GLuint index, GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI2ivEXT
void glVertexAttribI2ivEXT(GLuint index, GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI2ui
void glVertexAttribI2ui(GLuint index, GLuint x, GLuint y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI2uiEXT
void glVertexAttribI2uiEXT(GLuint index, GLuint x, GLuint y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI2uiv
void glVertexAttribI2uiv(GLuint index, GLuint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI2uivEXT
void glVertexAttribI2uivEXT(GLuint index, GLuint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI3i
void glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI3iEXT
void glVertexAttribI3iEXT(GLuint index, GLint x, GLint y, GLint z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI3iv
void glVertexAttribI3iv(GLuint index, GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI3ivEXT
void glVertexAttribI3ivEXT(GLuint index, GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI3ui
void glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI3uiEXT
void glVertexAttribI3uiEXT(GLuint index, GLuint x, GLuint y, GLuint z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI3uiv
void glVertexAttribI3uiv(GLuint index, GLuint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI3uivEXT
void glVertexAttribI3uivEXT(GLuint index, GLuint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI4bv
void glVertexAttribI4bv(GLuint index, GLbyte v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI4bvEXT
void glVertexAttribI4bvEXT(GLuint index, GLbyte v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI4i
void glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI4iEXT
void glVertexAttribI4iEXT(GLuint index, GLint x, GLint y, GLint z, GLint w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI4iv
void glVertexAttribI4iv(GLuint index, GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI4ivEXT
void glVertexAttribI4ivEXT(GLuint index, GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI4sv
void glVertexAttribI4sv(GLuint index, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI4svEXT
void glVertexAttribI4svEXT(GLuint index, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI4ubv
void glVertexAttribI4ubv(GLuint index, GLubyte v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI4ubvEXT
void glVertexAttribI4ubvEXT(GLuint index, GLubyte v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI4ui
void glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI4uiEXT
void glVertexAttribI4uiEXT(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI4uiv
void glVertexAttribI4uiv(GLuint index, GLuint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI4uivEXT
void glVertexAttribI4uivEXT(GLuint index, GLuint v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI4usv
void glVertexAttribI4usv(GLuint index, GLushort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribI4usvEXT
void glVertexAttribI4usvEXT(GLuint index, GLushort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribIFormat
void glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribIFormatNV
void glVertexAttribIFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribIPointer
void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribIPointerEXT
void glVertexAttribIPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL1d
void glVertexAttribL1d(GLuint index, GLdouble x) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL1dEXT
void glVertexAttribL1dEXT(GLuint index, GLdouble x) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL1dv
void glVertexAttribL1dv(GLuint index, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL1dvEXT
void glVertexAttribL1dvEXT(GLuint index, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL1i64NV
void glVertexAttribL1i64NV(GLuint index, GLint64EXT x) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL1i64vNV
void glVertexAttribL1i64vNV(GLuint index, GLint64EXT v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL1ui64NV
void glVertexAttribL1ui64NV(GLuint index, GLuint64EXT x) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL1ui64vNV
void glVertexAttribL1ui64vNV(GLuint index, GLuint64EXT v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL2d
void glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL2dEXT
void glVertexAttribL2dEXT(GLuint index, GLdouble x, GLdouble y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL2dv
void glVertexAttribL2dv(GLuint index, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL2dvEXT
void glVertexAttribL2dvEXT(GLuint index, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL2i64NV
void glVertexAttribL2i64NV(GLuint index, GLint64EXT x, GLint64EXT y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL2i64vNV
void glVertexAttribL2i64vNV(GLuint index, GLint64EXT v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL2ui64NV
void glVertexAttribL2ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL2ui64vNV
void glVertexAttribL2ui64vNV(GLuint index, GLuint64EXT v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL3d
void glVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL3dEXT
void glVertexAttribL3dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL3dv
void glVertexAttribL3dv(GLuint index, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL3dvEXT
void glVertexAttribL3dvEXT(GLuint index, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL3i64NV
void glVertexAttribL3i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL3i64vNV
void glVertexAttribL3i64vNV(GLuint index, GLint64EXT v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL3ui64NV
void glVertexAttribL3ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL3ui64vNV
void glVertexAttribL3ui64vNV(GLuint index, GLuint64EXT v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL4d
void glVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL4dEXT
void glVertexAttribL4dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL4dv
void glVertexAttribL4dv(GLuint index, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL4dvEXT
void glVertexAttribL4dvEXT(GLuint index, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL4i64NV
void glVertexAttribL4i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL4i64vNV
void glVertexAttribL4i64vNV(GLuint index, GLint64EXT v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL4ui64NV
void glVertexAttribL4ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribL4ui64vNV
void glVertexAttribL4ui64vNV(GLuint index, GLuint64EXT v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribLFormat
void glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribLFormatNV
void glVertexAttribLFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribLPointer
void glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribLPointerEXT
void glVertexAttribLPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribP1ui
void glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribP1uiv
void glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribP2ui
void glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribP2uiv
void glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribP3ui
void glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribP3uiv
void glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribP4ui
void glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribP4uiv
void glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribPointer
void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribPointerARB
void glVertexAttribPointerARB(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribPointerNV
void glVertexAttribPointerNV(GLuint index, GLint fsize, GLenum type, GLsizei stride, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribs1dvNV
void glVertexAttribs1dvNV(GLuint index, GLsizei count, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribs1fvNV
void glVertexAttribs1fvNV(GLuint index, GLsizei count, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribs1hvNV
void glVertexAttribs1hvNV(GLuint index, GLsizei n, GLhalfNV v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribs1svNV
void glVertexAttribs1svNV(GLuint index, GLsizei count, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribs2dvNV
void glVertexAttribs2dvNV(GLuint index, GLsizei count, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribs2fvNV
void glVertexAttribs2fvNV(GLuint index, GLsizei count, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribs2hvNV
void glVertexAttribs2hvNV(GLuint index, GLsizei n, GLhalfNV v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribs2svNV
void glVertexAttribs2svNV(GLuint index, GLsizei count, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribs3dvNV
void glVertexAttribs3dvNV(GLuint index, GLsizei count, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribs3fvNV
void glVertexAttribs3fvNV(GLuint index, GLsizei count, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribs3hvNV
void glVertexAttribs3hvNV(GLuint index, GLsizei n, GLhalfNV v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribs3svNV
void glVertexAttribs3svNV(GLuint index, GLsizei count, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribs4dvNV
void glVertexAttribs4dvNV(GLuint index, GLsizei count, GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribs4fvNV
void glVertexAttribs4fvNV(GLuint index, GLsizei count, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribs4hvNV
void glVertexAttribs4hvNV(GLuint index, GLsizei n, GLhalfNV v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribs4svNV
void glVertexAttribs4svNV(GLuint index, GLsizei count, GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexAttribs4ubvNV
void glVertexAttribs4ubvNV(GLuint index, GLsizei count, GLubyte v) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexBindingDivisor
void glVertexBindingDivisor(GLuint bindingindex, GLuint divisor) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexBlendARB
void glVertexBlendARB(GLint count) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexBlendEnvfATI
void glVertexBlendEnvfATI(GLenum pname, GLfloat param) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexBlendEnviATI
void glVertexBlendEnviATI(GLenum pname, GLint param) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexFormatNV
void glVertexFormatNV(GLint size, GLenum type, GLsizei stride) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexP2ui
void glVertexP2ui(GLenum type, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexP2uiv
void glVertexP2uiv(GLenum type, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexP3ui
void glVertexP3ui(GLenum type, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexP3uiv
void glVertexP3uiv(GLenum type, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexP4ui
void glVertexP4ui(GLenum type, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexP4uiv
void glVertexP4uiv(GLenum type, GLuint value) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexPointer
void glVertexPointer(GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexPointerEXT
void glVertexPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexPointerListIBM
void glVertexPointerListIBM(GLint size, GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexPointervINTEL
void glVertexPointervINTEL(GLint size, GLenum type, GLvoid * pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream1dATI
void glVertexStream1dATI(GLenum stream, GLdouble x) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream1dvATI
void glVertexStream1dvATI(GLenum stream, GLdouble coords) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream1fATI
void glVertexStream1fATI(GLenum stream, GLfloat x) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream1fvATI
void glVertexStream1fvATI(GLenum stream, GLfloat coords) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream1iATI
void glVertexStream1iATI(GLenum stream, GLint x) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream1ivATI
void glVertexStream1ivATI(GLenum stream, GLint coords) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream1sATI
void glVertexStream1sATI(GLenum stream, GLshort x) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream1svATI
void glVertexStream1svATI(GLenum stream, GLshort coords) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream2dATI
void glVertexStream2dATI(GLenum stream, GLdouble x, GLdouble y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream2dvATI
void glVertexStream2dvATI(GLenum stream, GLdouble coords) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream2fATI
void glVertexStream2fATI(GLenum stream, GLfloat x, GLfloat y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream2fvATI
void glVertexStream2fvATI(GLenum stream, GLfloat coords) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream2iATI
void glVertexStream2iATI(GLenum stream, GLint x, GLint y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream2ivATI
void glVertexStream2ivATI(GLenum stream, GLint coords) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream2sATI
void glVertexStream2sATI(GLenum stream, GLshort x, GLshort y) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream2svATI
void glVertexStream2svATI(GLenum stream, GLshort coords) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream3dATI
void glVertexStream3dATI(GLenum stream, GLdouble x, GLdouble y, GLdouble z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream3dvATI
void glVertexStream3dvATI(GLenum stream, GLdouble coords) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream3fATI
void glVertexStream3fATI(GLenum stream, GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream3fvATI
void glVertexStream3fvATI(GLenum stream, GLfloat coords) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream3iATI
void glVertexStream3iATI(GLenum stream, GLint x, GLint y, GLint z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream3ivATI
void glVertexStream3ivATI(GLenum stream, GLint coords) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream3sATI
void glVertexStream3sATI(GLenum stream, GLshort x, GLshort y, GLshort z) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream3svATI
void glVertexStream3svATI(GLenum stream, GLshort coords) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream4dATI
void glVertexStream4dATI(GLenum stream, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream4dvATI
void glVertexStream4dvATI(GLenum stream, GLdouble coords) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream4fATI
void glVertexStream4fATI(GLenum stream, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream4fvATI
void glVertexStream4fvATI(GLenum stream, GLfloat coords) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream4iATI
void glVertexStream4iATI(GLenum stream, GLint x, GLint y, GLint z, GLint w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream4ivATI
void glVertexStream4ivATI(GLenum stream, GLint coords) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream4sATI
void glVertexStream4sATI(GLenum stream, GLshort x, GLshort y, GLshort z, GLshort w) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexStream4svATI
void glVertexStream4svATI(GLenum stream, GLshort coords) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexWeightPointerEXT
void glVertexWeightPointerEXT(GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexWeightfEXT
void glVertexWeightfEXT(GLfloat weight) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexWeightfvEXT
void glVertexWeightfvEXT(GLfloat weight) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexWeighthNV
void glVertexWeighthNV(GLhalfNV weight) {
printf(gl.c);
}
#endif
#ifndef skip_glVertexWeighthvNV
void glVertexWeighthvNV(GLhalfNV weight) {
printf(gl.c);
}
#endif
#ifndef skip_glVideoCaptureNV
GLenum glVideoCaptureNV(GLuint video_capture_slot, GLuint sequence_num, GLuint64EXT capture_time) {
printf(gl.c);
}
#endif
#ifndef skip_glVideoCaptureStreamParameterdvNV
void glVideoCaptureStreamParameterdvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble params) {
printf(gl.c);
}
#endif
#ifndef skip_glVideoCaptureStreamParameterfvNV
void glVideoCaptureStreamParameterfvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat params) {
printf(gl.c);
}
#endif
#ifndef skip_glVideoCaptureStreamParameterivNV
void glVideoCaptureStreamParameterivNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLint params) {
printf(gl.c);
}
#endif
#ifndef skip_glViewport
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
printf(gl.c);
}
#endif
#ifndef skip_glViewportArrayv
void glViewportArrayv(GLuint first, GLsizei count, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glViewportIndexedf
void glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h) {
printf(gl.c);
}
#endif
#ifndef skip_glViewportIndexedfv
void glViewportIndexedfv(GLuint index, GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glWaitSync
void glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) {
printf(gl.c);
}
#endif
#ifndef skip_glWeightPathsNV
void glWeightPathsNV(GLuint resultPath, GLsizei numPaths, GLuint paths, GLfloat weights) {
printf(gl.c);
}
#endif
#ifndef skip_glWeightPointerARB
void glWeightPointerARB(GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glWeightbvARB
void glWeightbvARB(GLint size, GLbyte weights) {
printf(gl.c);
}
#endif
#ifndef skip_glWeightdvARB
void glWeightdvARB(GLint size, GLdouble weights) {
printf(gl.c);
}
#endif
#ifndef skip_glWeightfvARB
void glWeightfvARB(GLint size, GLfloat weights) {
printf(gl.c);
}
#endif
#ifndef skip_glWeightivARB
void glWeightivARB(GLint size, GLint weights) {
printf(gl.c);
}
#endif
#ifndef skip_glWeightsvARB
void glWeightsvARB(GLint size, GLshort weights) {
printf(gl.c);
}
#endif
#ifndef skip_glWeightubvARB
void glWeightubvARB(GLint size, GLubyte weights) {
printf(gl.c);
}
#endif
#ifndef skip_glWeightuivARB
void glWeightuivARB(GLint size, GLuint weights) {
printf(gl.c);
}
#endif
#ifndef skip_glWeightusvARB
void glWeightusvARB(GLint size, GLushort weights) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos2d
void glWindowPos2d(GLdouble x, GLdouble y) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos2dARB
void glWindowPos2dARB(GLdouble x, GLdouble y) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos2dMESA
void glWindowPos2dMESA(GLdouble x, GLdouble y) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos2dv
void glWindowPos2dv(GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos2dvARB
void glWindowPos2dvARB(GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos2dvMESA
void glWindowPos2dvMESA(GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos2f
void glWindowPos2f(GLfloat x, GLfloat y) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos2fARB
void glWindowPos2fARB(GLfloat x, GLfloat y) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos2fMESA
void glWindowPos2fMESA(GLfloat x, GLfloat y) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos2fv
void glWindowPos2fv(GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos2fvARB
void glWindowPos2fvARB(GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos2fvMESA
void glWindowPos2fvMESA(GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos2i
void glWindowPos2i(GLint x, GLint y) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos2iARB
void glWindowPos2iARB(GLint x, GLint y) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos2iMESA
void glWindowPos2iMESA(GLint x, GLint y) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos2iv
void glWindowPos2iv(GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos2ivARB
void glWindowPos2ivARB(GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos2ivMESA
void glWindowPos2ivMESA(GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos2s
void glWindowPos2s(GLshort x, GLshort y) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos2sARB
void glWindowPos2sARB(GLshort x, GLshort y) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos2sMESA
void glWindowPos2sMESA(GLshort x, GLshort y) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos2sv
void glWindowPos2sv(GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos2svARB
void glWindowPos2svARB(GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos2svMESA
void glWindowPos2svMESA(GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos3d
void glWindowPos3d(GLdouble x, GLdouble y, GLdouble z) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos3dARB
void glWindowPos3dARB(GLdouble x, GLdouble y, GLdouble z) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos3dMESA
void glWindowPos3dMESA(GLdouble x, GLdouble y, GLdouble z) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos3dv
void glWindowPos3dv(GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos3dvARB
void glWindowPos3dvARB(GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos3dvMESA
void glWindowPos3dvMESA(GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos3f
void glWindowPos3f(GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos3fARB
void glWindowPos3fARB(GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos3fMESA
void glWindowPos3fMESA(GLfloat x, GLfloat y, GLfloat z) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos3fv
void glWindowPos3fv(GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos3fvARB
void glWindowPos3fvARB(GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos3fvMESA
void glWindowPos3fvMESA(GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos3i
void glWindowPos3i(GLint x, GLint y, GLint z) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos3iARB
void glWindowPos3iARB(GLint x, GLint y, GLint z) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos3iMESA
void glWindowPos3iMESA(GLint x, GLint y, GLint z) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos3iv
void glWindowPos3iv(GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos3ivARB
void glWindowPos3ivARB(GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos3ivMESA
void glWindowPos3ivMESA(GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos3s
void glWindowPos3s(GLshort x, GLshort y, GLshort z) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos3sARB
void glWindowPos3sARB(GLshort x, GLshort y, GLshort z) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos3sMESA
void glWindowPos3sMESA(GLshort x, GLshort y, GLshort z) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos3sv
void glWindowPos3sv(GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos3svARB
void glWindowPos3svARB(GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos3svMESA
void glWindowPos3svMESA(GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos4dMESA
void glWindowPos4dMESA(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos4dvMESA
void glWindowPos4dvMESA(GLdouble v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos4fMESA
void glWindowPos4fMESA(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos4fvMESA
void glWindowPos4fvMESA(GLfloat v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos4iMESA
void glWindowPos4iMESA(GLint x, GLint y, GLint z, GLint w) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos4ivMESA
void glWindowPos4ivMESA(GLint v) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos4sMESA
void glWindowPos4sMESA(GLshort x, GLshort y, GLshort z, GLshort w) {
printf(gl.c);
}
#endif
#ifndef skip_glWindowPos4svMESA
void glWindowPos4svMESA(GLshort v) {
printf(gl.c);
}
#endif
#ifndef skip_glWriteMaskEXT
void glWriteMaskEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW) {
printf(gl.c);
}
#endif
#ifndef skip_glxAssociateDMPbufferSGIX
Bool glxAssociateDMPbufferSGIX(Display dpy, GLXPbufferSGIX pbuffer, DMparams params, DMbuffer dmbuffer) {
printf(gl.c);
}
#endif
#ifndef skip_glxBindChannelToWindowSGIX
int glxBindChannelToWindowSGIX(Display display, int screen, int channel, Window window) {
printf(gl.c);
}
#endif
#ifndef skip_glxBindHyperpipeSGIX
int glxBindHyperpipeSGIX(Display dpy, int hpId) {
printf(gl.c);
}
#endif
#ifndef skip_glxBindSwapBarrierNV
Bool glxBindSwapBarrierNV(Display dpy, GLuint group, GLuint barrier) {
printf(gl.c);
}
#endif
#ifndef skip_glxBindSwapBarrierSGIX
void glxBindSwapBarrierSGIX(Display dpy, GLXDrawable drawable, int barrier) {
printf(gl.c);
}
#endif
#ifndef skip_glxBindTexImageEXT
void glxBindTexImageEXT(Display dpy, GLXDrawable drawable, int buffer, int attrib_list) {
printf(gl.c);
}
#endif
#ifndef skip_glxBindVideoCaptureDeviceNV
int glxBindVideoCaptureDeviceNV(Display dpy, unsigned int video_capture_slot, GLXVideoCaptureDeviceNV device) {
printf(gl.c);
}
#endif
#ifndef skip_glxBindVideoDeviceNV
int glxBindVideoDeviceNV(Display dpy, unsigned int video_slot, unsigned int video_device, int attrib_list) {
printf(gl.c);
}
#endif
#ifndef skip_glxBindVideoImageNV
int glxBindVideoImageNV(Display dpy, GLXVideoDeviceNV VideoDevice, GLXPbuffer pbuf, int iVideoBuffer) {
printf(gl.c);
}
#endif
#ifndef skip_glxChannelRectSGIX
int glxChannelRectSGIX(Display display, int screen, int channel, int x, int y, int w, int h) {
printf(gl.c);
}
#endif
#ifndef skip_glxChannelRectSyncSGIX
int glxChannelRectSyncSGIX(Display display, int screen, int channel, GLenum synctype) {
printf(gl.c);
}
#endif
#ifndef skip_glxChooseFBConfig
GLXFBConfigPointer glxChooseFBConfig(Display dpy, int screen, int attrib_list, int nelements) {
printf(gl.c);
}
#endif
#ifndef skip_glxChooseFBConfigSGIX
GLXFBConfigSGIXPointer glxChooseFBConfigSGIX(Display dpy, int screen, int attrib_list, int nelements) {
printf(gl.c);
}
#endif
#ifndef skip_glxCopyImageSubDataNV
void glxCopyImageSubDataNV(Display dpy, GLXContext srcCtx, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLXContext dstCtx, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth) {
printf(gl.c);
}
#endif
#ifndef skip_glxCopySubBufferMESA
void glxCopySubBufferMESA(Display dpy, GLXDrawable drawable, int x, int y, int width, int height) {
printf(gl.c);
}
#endif
#ifndef skip_glxCreateContextAttribsARB
GLXContext glxCreateContextAttribsARB(Display dpy, GLXFBConfig config, GLXContext share_context, Bool direct, int attrib_list) {
printf(gl.c);
}
#endif
#ifndef skip_glxCreateContextWithConfigSGIX
GLXContext glxCreateContextWithConfigSGIX(Display dpy, GLXFBConfigSGIX config, int render_type, GLXContext share_list, Bool direct) {
printf(gl.c);
}
#endif
#ifndef skip_glxCreateGLXPbufferSGIX
GLXPbufferSGIX glxCreateGLXPbufferSGIX(Display dpy, GLXFBConfigSGIX config, unsigned int width, unsigned int height, int attrib_list) {
printf(gl.c);
}
#endif
#ifndef skip_glxCreateGLXPixmapMESA
GLXPixmap glxCreateGLXPixmapMESA(Display dpy, XVisualInfo visual, Pixmap pixmap, Colormap cmap) {
printf(gl.c);
}
#endif
#ifndef skip_glxCreateGLXPixmapWithConfigSGIX
GLXPixmap glxCreateGLXPixmapWithConfigSGIX(Display dpy, GLXFBConfigSGIX config, Pixmap pixmap) {
printf(gl.c);
}
#endif
#ifndef skip_glxCreateGLXVideoSourceSGIX
GLXVideoSourceSGIX glxCreateGLXVideoSourceSGIX(Display display, int screen, VLServer server, VLPath path, int nodeClass, VLNode drainNode) {
printf(gl.c);
}
#endif
#ifndef skip_glxCreateNewContext
GLXContext glxCreateNewContext(Display dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct) {
printf(gl.c);
}
#endif
#ifndef skip_glxCreatePbuffer
GLXPbuffer glxCreatePbuffer(Display dpy, GLXFBConfig config, int attrib_list) {
printf(gl.c);
}
#endif
#ifndef skip_glxCreatePixmap
GLXPixmap glxCreatePixmap(Display dpy, GLXFBConfig config, Pixmap pixmap, int attrib_list) {
printf(gl.c);
}
#endif
#ifndef skip_glxCreateWindow
GLXWindow glxCreateWindow(Display dpy, GLXFBConfig config, Window win, int attrib_list) {
printf(gl.c);
}
#endif
#ifndef skip_glxCushionSGI
void glxCushionSGI(Display dpy, Window window, float cushion) {
printf(gl.c);
}
#endif
#ifndef skip_glxDestroyGLXPbufferSGIX
void glxDestroyGLXPbufferSGIX(Display dpy, GLXPbufferSGIX pbuf) {
printf(gl.c);
}
#endif
#ifndef skip_glxDestroyGLXVideoSourceSGIX
void glxDestroyGLXVideoSourceSGIX(Display dpy, GLXVideoSourceSGIX glxvideosource) {
printf(gl.c);
}
#endif
#ifndef skip_glxDestroyHyperpipeConfigSGIX
int glxDestroyHyperpipeConfigSGIX(Display dpy, int hpId) {
printf(gl.c);
}
#endif
#ifndef skip_glxDestroyPbuffer
void glxDestroyPbuffer(Display dpy, GLXPbuffer pbuf) {
printf(gl.c);
}
#endif
#ifndef skip_glxDestroyPixmap
void glxDestroyPixmap(Display dpy, GLXPixmap pixmap) {
printf(gl.c);
}
#endif
#ifndef skip_glxDestroyWindow
void glxDestroyWindow(Display dpy, GLXWindow win) {
printf(gl.c);
}
#endif
#ifndef skip_glxEnumerateVideoCaptureDevicesNV
GLXVideoCaptureDeviceNVPointer glxEnumerateVideoCaptureDevicesNV(Display dpy, int screen, int nelements) {
printf(gl.c);
}
#endif
#ifndef skip_glxEnumerateVideoDevicesNV
uintPointer glxEnumerateVideoDevicesNV(Display dpy, int screen, int nelements) {
printf(gl.c);
}
#endif
#ifndef skip_glxFreeContextEXT
void glxFreeContextEXT(Display dpy, GLXContext context) {
printf(gl.c);
}
#endif
#ifndef skip_glxGetAGPOffsetMESA
uint glxGetAGPOffsetMESA(void pointer) {
printf(gl.c);
}
#endif
#ifndef skip_glxGetContextIDEXT
GLXContextID glxGetContextIDEXT(const GLXContext context) {
printf(gl.c);
}
#endif
#ifndef skip_glxGetCurrentDisplay
DisplayPointer glxGetCurrentDisplay() {
printf(gl.c);
}
#endif
#ifndef skip_glxGetCurrentDisplayEXT
DisplayPointer glxGetCurrentDisplayEXT() {
printf(gl.c);
}
#endif
#ifndef skip_glxGetCurrentReadDrawable
GLXDrawable glxGetCurrentReadDrawable() {
printf(gl.c);
}
#endif
#ifndef skip_glxGetCurrentReadDrawableSGI
GLXDrawable glxGetCurrentReadDrawableSGI() {
printf(gl.c);
}
#endif
#ifndef skip_glxGetFBConfigAttrib
int glxGetFBConfigAttrib(Display dpy, GLXFBConfig config, int attribute, int value) {
printf(gl.c);
}
#endif
#ifndef skip_glxGetFBConfigAttribSGIX
int glxGetFBConfigAttribSGIX(Display dpy, GLXFBConfigSGIX config, int attribute, int value) {
printf(gl.c);
}
#endif
#ifndef skip_glxGetFBConfigFromVisualSGIX
GLXFBConfigSGIX glxGetFBConfigFromVisualSGIX(Display dpy, XVisualInfo vis) {
printf(gl.c);
}
#endif
#ifndef skip_glxGetFBConfigs
GLXFBConfigPointer glxGetFBConfigs(Display dpy, int screen, int nelements) {
printf(gl.c);
}
#endif
#ifndef skip_glxGetMscRateOML
Bool glxGetMscRateOML(Display dpy, GLXDrawable drawable, int32_t numerator, int32_t denominator) {
printf(gl.c);
}
#endif
#ifndef skip_glxGetProcAddress
FunctionPointer glxGetProcAddress(GLubyte procName) {
printf(gl.c);
}
#endif
#ifndef skip_glxGetProcAddressARB
FunctionPointer glxGetProcAddressARB(GLubyte procName) {
printf(gl.c);
}
#endif
#ifndef skip_glxGetSelectedEvent
void glxGetSelectedEvent(Display dpy, GLXDrawable draw, unsigned long event_mask) {
printf(gl.c);
}
#endif
#ifndef skip_glxGetSelectedEventSGIX
void glxGetSelectedEventSGIX(Display dpy, GLXDrawable drawable, unsigned long mask) {
printf(gl.c);
}
#endif
#ifndef skip_glxGetSyncValuesOML
Bool glxGetSyncValuesOML(Display dpy, GLXDrawable drawable, int64_t ust, int64_t msc, int64_t sbc) {
printf(gl.c);
}
#endif
#ifndef skip_glxGetTransparentIndexSUN
Status glxGetTransparentIndexSUN(Display dpy, Window overlay, Window underlay, long pTransparentIndex) {
printf(gl.c);
}
#endif
#ifndef skip_glxGetVideoDeviceNV
int glxGetVideoDeviceNV(Display dpy, int screen, int numVideoDevices, GLXVideoDeviceNV pVideoDevice) {
printf(gl.c);
}
#endif
#ifndef skip_glxGetVideoInfoNV
int glxGetVideoInfoNV(Display dpy, int screen, GLXVideoDeviceNV VideoDevice, unsigned long pulCounterOutputPbuffer, unsigned long pulCounterOutputVideo) {
printf(gl.c);
}
#endif
#ifndef skip_glxGetVideoSyncSGI
int glxGetVideoSyncSGI(unsigned int count) {
printf(gl.c);
}
#endif
#ifndef skip_glxGetVisualFromFBConfig
XVisualInfoPointer glxGetVisualFromFBConfig(Display dpy, GLXFBConfig config) {
printf(gl.c);
}
#endif
#ifndef skip_glxGetVisualFromFBConfigSGIX
XVisualInfoPointer glxGetVisualFromFBConfigSGIX(Display dpy, GLXFBConfigSGIX config) {
printf(gl.c);
}
#endif
#ifndef skip_glxHyperpipeAttribSGIX
int glxHyperpipeAttribSGIX(Display dpy, int timeSlice, int attrib, int size, void attribList) {
printf(gl.c);
}
#endif
#ifndef skip_glxHyperpipeConfigSGIX
int glxHyperpipeConfigSGIX(Display dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX cfg, int hpId) {
printf(gl.c);
}
#endif
#ifndef skip_glxImportContextEXT
GLXContext glxImportContextEXT(Display dpy, GLXContextID contextID) {
printf(gl.c);
}
#endif
#ifndef skip_glxJoinSwapGroupNV
Bool glxJoinSwapGroupNV(Display dpy, GLXDrawable drawable, GLuint group) {
printf(gl.c);
}
#endif
#ifndef skip_glxJoinSwapGroupSGIX
void glxJoinSwapGroupSGIX(Display dpy, GLXDrawable drawable, GLXDrawable member) {
printf(gl.c);
}
#endif
#ifndef skip_glxLockVideoCaptureDeviceNV
void glxLockVideoCaptureDeviceNV(Display dpy, GLXVideoCaptureDeviceNV device) {
printf(gl.c);
}
#endif
#ifndef skip_glxMakeContextCurrent
Bool glxMakeContextCurrent(Display dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx) {
printf(gl.c);
}
#endif
#ifndef skip_glxMakeCurrentReadSGI
Bool glxMakeCurrentReadSGI(Display dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx) {
printf(gl.c);
}
#endif
#ifndef skip_glxQueryChannelDeltasSGIX
int glxQueryChannelDeltasSGIX(Display display, int screen, int channel, int x, int y, int w, int h) {
printf(gl.c);
}
#endif
#ifndef skip_glxQueryChannelRectSGIX
int glxQueryChannelRectSGIX(Display display, int screen, int channel, int dx, int dy, int dw, int dh) {
printf(gl.c);
}
#endif
#ifndef skip_glxQueryContext
int glxQueryContext(Display dpy, GLXContext ctx, int attribute, int value) {
printf(gl.c);
}
#endif
#ifndef skip_glxQueryContextInfoEXT
int glxQueryContextInfoEXT(Display dpy, GLXContext context, int attribute, int value) {
printf(gl.c);
}
#endif
#ifndef skip_glxQueryDrawable
void glxQueryDrawable(Display dpy, GLXDrawable draw, int attribute, unsigned int value) {
printf(gl.c);
}
#endif
#ifndef skip_glxQueryFrameCountNV
Bool glxQueryFrameCountNV(Display dpy, int screen, GLuint count) {
printf(gl.c);
}
#endif
#ifndef skip_glxQueryGLXPbufferSGIX
int glxQueryGLXPbufferSGIX(Display dpy, GLXPbufferSGIX pbuf, int attribute, unsigned int value) {
printf(gl.c);
}
#endif
#ifndef skip_glxQueryHyperpipeAttribSGIX
int glxQueryHyperpipeAttribSGIX(Display dpy, int timeSlice, int attrib, int size, void returnAttribList) {
printf(gl.c);
}
#endif
#ifndef skip_glxQueryHyperpipeBestAttribSGIX
int glxQueryHyperpipeBestAttribSGIX(Display dpy, int timeSlice, int attrib, int size, void attribList, void returnAttribList) {
printf(gl.c);
}
#endif
#ifndef skip_glxQueryHyperpipeConfigSGIX
GLXHyperpipeConfigSGIXPointer glxQueryHyperpipeConfigSGIX(Display dpy, int hpId, int npipes) {
printf(gl.c);
}
#endif
#ifndef skip_glxQueryHyperpipeNetworkSGIX
GLXHyperpipeNetworkSGIXPointer glxQueryHyperpipeNetworkSGIX(Display dpy, int npipes) {
printf(gl.c);
}
#endif
#ifndef skip_glxQueryMaxSwapBarriersSGIX
Bool glxQueryMaxSwapBarriersSGIX(Display dpy, int screen, int max) {
printf(gl.c);
}
#endif
#ifndef skip_glxQueryMaxSwapGroupsNV
Bool glxQueryMaxSwapGroupsNV(Display dpy, int screen, GLuint maxGroups, GLuint maxBarriers) {
printf(gl.c);
}
#endif
#ifndef skip_glxQuerySwapGroupNV
Bool glxQuerySwapGroupNV(Display dpy, GLXDrawable drawable, GLuint group, GLuint barrier) {
printf(gl.c);
}
#endif
#ifndef skip_glxQueryVideoCaptureDeviceNV
int glxQueryVideoCaptureDeviceNV(Display dpy, GLXVideoCaptureDeviceNV device, int attribute, int value) {
printf(gl.c);
}
#endif
#ifndef skip_glxReleaseBuffersMESA
Bool glxReleaseBuffersMESA(Display dpy, GLXDrawable drawable) {
printf(gl.c);
}
#endif
#ifndef skip_glxReleaseTexImageEXT
void glxReleaseTexImageEXT(Display dpy, GLXDrawable drawable, int buffer) {
printf(gl.c);
}
#endif
#ifndef skip_glxReleaseVideoCaptureDeviceNV
void glxReleaseVideoCaptureDeviceNV(Display dpy, GLXVideoCaptureDeviceNV device) {
printf(gl.c);
}
#endif
#ifndef skip_glxReleaseVideoDeviceNV
int glxReleaseVideoDeviceNV(Display dpy, int screen, GLXVideoDeviceNV VideoDevice) {
printf(gl.c);
}
#endif
#ifndef skip_glxReleaseVideoImageNV
int glxReleaseVideoImageNV(Display dpy, GLXPbuffer pbuf) {
printf(gl.c);
}
#endif
#ifndef skip_glxResetFrameCountNV
Bool glxResetFrameCountNV(Display dpy, int screen) {
printf(gl.c);
}
#endif
#ifndef skip_glxSelectEvent
void glxSelectEvent(Display dpy, GLXDrawable draw, unsigned long event_mask) {
printf(gl.c);
}
#endif
#ifndef skip_glxSelectEventSGIX
void glxSelectEventSGIX(Display dpy, GLXDrawable drawable, unsigned long mask) {
printf(gl.c);
}
#endif
#ifndef skip_glxSendPbufferToVideoNV
int glxSendPbufferToVideoNV(Display dpy, GLXPbuffer pbuf, int iBufferType, unsigned long pulCounterPbuffer, GLboolean bBlock) {
printf(gl.c);
}
#endif
#ifndef skip_glxSet3DfxModeMESA
Bool glxSet3DfxModeMESA(int mode) {
printf(gl.c);
}
#endif
#ifndef skip_glxSwapBuffersMscOML
int64_t glxSwapBuffersMscOML(Display dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder) {
printf(gl.c);
}
#endif
#ifndef skip_glxSwapIntervalEXT
void glxSwapIntervalEXT(Display dpy, GLXDrawable drawable, int interval) {
printf(gl.c);
}
#endif
#ifndef skip_glxSwapIntervalSGI
int glxSwapIntervalSGI(int interval) {
printf(gl.c);
}
#endif
#ifndef skip_glxWaitForMscOML
Bool glxWaitForMscOML(Display dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder, int64_t ust, int64_t msc, int64_t sbc) {
printf(gl.c);
}
#endif
#ifndef skip_glxWaitForSbcOML
Bool glxWaitForSbcOML(Display dpy, GLXDrawable drawable, int64_t target_sbc, int64_t ust, int64_t msc, int64_t sbc) {
printf(gl.c);
}
#endif
#ifndef skip_glxWaitVideoSyncSGI
int glxWaitVideoSyncSGI(int divisor, int remainder, unsigned int count) {
printf(gl.c);
}
#endif
