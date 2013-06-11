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


#ifndef skip_Accum
void Accum(GLenum op, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_AccumxOES
void AccumxOES(GLenum op, GLfixed value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ActiveProgramEXT
void ActiveProgramEXT(GLuint program) {
    
printf(gl.c);
}
#endif

#ifndef skip_ActiveShaderProgram
void ActiveShaderProgram(GLuint pipeline, GLuint program) {
    
printf(gl.c);
}
#endif

#ifndef skip_ActiveStencilFaceEXT
void ActiveStencilFaceEXT(GLenum face) {
    
printf(gl.c);
}
#endif

#ifndef skip_ActiveTexture
void ActiveTexture(GLenum texture) {
    
printf(gl.c);
}
#endif

#ifndef skip_ActiveTextureARB
void ActiveTextureARB(GLenum texture) {
    
printf(gl.c);
}
#endif

#ifndef skip_ActiveVaryingNV
void ActiveVaryingNV(GLuint program, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_AlphaFragmentOp1ATI
void AlphaFragmentOp1ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod) {
    
printf(gl.c);
}
#endif

#ifndef skip_AlphaFragmentOp2ATI
void AlphaFragmentOp2ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod) {
    
printf(gl.c);
}
#endif

#ifndef skip_AlphaFragmentOp3ATI
void AlphaFragmentOp3ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod) {
    
printf(gl.c);
}
#endif

#ifndef skip_AlphaFunc
void AlphaFunc(GLenum func, GLfloat ref) {
    
printf(gl.c);
}
#endif

#ifndef skip_AlphaFuncxOES
void AlphaFuncxOES(GLenum func, GLfixed ref) {
    
printf(gl.c);
}
#endif

#ifndef skip_ApplyTextureEXT
void ApplyTextureEXT(GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_AreProgramsResidentNV
Boolean AreProgramsResidentNV(GLsizei n, GLuint programs, GLboolean residences) {
    
printf(gl.c);
}
#endif

#ifndef skip_AreTexturesResident
Boolean AreTexturesResident(GLsizei n, GLuint textures, GLboolean residences) {
    
printf(gl.c);
}
#endif

#ifndef skip_AreTexturesResidentEXT
Boolean AreTexturesResidentEXT(GLsizei n, GLuint textures, GLboolean residences) {
    
printf(gl.c);
}
#endif

#ifndef skip_ArrayElement
void ArrayElement(GLint i) {
    
printf(gl.c);
}
#endif

#ifndef skip_ArrayElementEXT
void ArrayElementEXT(GLint i) {
    
printf(gl.c);
}
#endif

#ifndef skip_ArrayObjectATI
void ArrayObjectATI(GLenum array, GLint size, GLenum type, GLsizei stride, GLuint buffer, GLuint offset) {
    
printf(gl.c);
}
#endif

#ifndef skip_AsyncMarkerSGIX
void AsyncMarkerSGIX(GLuint marker) {
    
printf(gl.c);
}
#endif

#ifndef skip_AttachObjectARB
void AttachObjectARB(GLhandleARB containerObj, GLhandleARB obj) {
    
printf(gl.c);
}
#endif

#ifndef skip_AttachShader
void AttachShader(GLuint program, GLuint shader) {
    
printf(gl.c);
}
#endif

#ifndef skip_Begin
void Begin(GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_BeginConditionalRender
void BeginConditionalRender(GLuint id, GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_BeginConditionalRenderNV
void BeginConditionalRenderNV(GLuint id, GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_BeginConditionalRenderNVX
void BeginConditionalRenderNVX(GLuint id) {
    
printf(gl.c);
}
#endif

#ifndef skip_BeginFragmentShaderATI
void BeginFragmentShaderATI() {
    
printf(gl.c);
}
#endif

#ifndef skip_BeginOcclusionQueryNV
void BeginOcclusionQueryNV(GLuint id) {
    
printf(gl.c);
}
#endif

#ifndef skip_BeginPerfMonitorAMD
void BeginPerfMonitorAMD(GLuint monitor) {
    
printf(gl.c);
}
#endif

#ifndef skip_BeginQuery
void BeginQuery(GLenum target, GLuint id) {
    
printf(gl.c);
}
#endif

#ifndef skip_BeginQueryARB
void BeginQueryARB(GLenum target, GLuint id) {
    
printf(gl.c);
}
#endif

#ifndef skip_BeginQueryIndexed
void BeginQueryIndexed(GLenum target, GLuint index, GLuint id) {
    
printf(gl.c);
}
#endif

#ifndef skip_BeginTransformFeedback
void BeginTransformFeedback(GLenum primitiveMode) {
    
printf(gl.c);
}
#endif

#ifndef skip_BeginTransformFeedbackEXT
void BeginTransformFeedbackEXT(GLenum primitiveMode) {
    
printf(gl.c);
}
#endif

#ifndef skip_BeginTransformFeedbackNV
void BeginTransformFeedbackNV(GLenum primitiveMode) {
    
printf(gl.c);
}
#endif

#ifndef skip_BeginVertexShaderEXT
void BeginVertexShaderEXT() {
    
printf(gl.c);
}
#endif

#ifndef skip_BeginVideoCaptureNV
void BeginVideoCaptureNV(GLuint video_capture_slot) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindAttribLocation
void BindAttribLocation(GLuint program, GLuint index, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindAttribLocationARB
void BindAttribLocationARB(GLhandleARB programObj, GLuint index, GLcharARB name) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindBuffer
void BindBuffer(GLenum target, GLuint buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindBufferARB
void BindBufferARB(GLenum target, GLuint buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindBufferBase
void BindBufferBase(GLenum target, GLuint index, GLuint buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindBufferBaseEXT
void BindBufferBaseEXT(GLenum target, GLuint index, GLuint buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindBufferBaseNV
void BindBufferBaseNV(GLenum target, GLuint index, GLuint buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindBufferOffsetEXT
void BindBufferOffsetEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindBufferOffsetNV
void BindBufferOffsetNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindBufferRange
void BindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindBufferRangeEXT
void BindBufferRangeEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindBufferRangeNV
void BindBufferRangeNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindFragDataLocation
void BindFragDataLocation(GLuint program, GLuint color, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindFragDataLocationEXT
void BindFragDataLocationEXT(GLuint program, GLuint color, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindFragDataLocationIndexed
void BindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindFragmentShaderATI
void BindFragmentShaderATI(GLuint id) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindFramebuffer
void BindFramebuffer(GLenum target, GLuint framebuffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindFramebufferEXT
void BindFramebufferEXT(GLenum target, GLuint framebuffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindImageTexture
void BindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindImageTextureEXT
void BindImageTextureEXT(GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindLightParameterEXT
UInt32 BindLightParameterEXT(GLenum light, GLenum value) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindMaterialParameterEXT
UInt32 BindMaterialParameterEXT(GLenum face, GLenum value) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindMultiTextureEXT
void BindMultiTextureEXT(GLenum texunit, GLenum target, GLuint texture) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindParameterEXT
UInt32 BindParameterEXT(GLenum value) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindProgramARB
void BindProgramARB(GLenum target, GLuint program) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindProgramNV
void BindProgramNV(GLenum target, GLuint id) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindProgramPipeline
void BindProgramPipeline(GLuint pipeline) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindRenderbuffer
void BindRenderbuffer(GLenum target, GLuint renderbuffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindRenderbufferEXT
void BindRenderbufferEXT(GLenum target, GLuint renderbuffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindSampler
void BindSampler(GLuint unit, GLuint sampler) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindTexGenParameterEXT
UInt32 BindTexGenParameterEXT(GLenum unit, GLenum coord, GLenum value) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindTexture
void BindTexture(GLenum target, GLuint texture) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindTextureEXT
void BindTextureEXT(GLenum target, GLuint texture) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindTextureUnitParameterEXT
UInt32 BindTextureUnitParameterEXT(GLenum unit, GLenum value) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindTransformFeedback
void BindTransformFeedback(GLenum target, GLuint id) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindTransformFeedbackNV
void BindTransformFeedbackNV(GLenum target, GLuint id) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindVertexArray
void BindVertexArray(GLuint array) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindVertexArrayAPPLE
void BindVertexArrayAPPLE(GLuint array) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindVertexBuffer
void BindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindVertexShaderEXT
void BindVertexShaderEXT(GLuint id) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindVideoCaptureStreamBufferNV
void BindVideoCaptureStreamBufferNV(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLintptrARB offset) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindVideoCaptureStreamTextureNV
void BindVideoCaptureStreamTextureNV(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLenum target, GLuint texture) {
    
printf(gl.c);
}
#endif

#ifndef skip_Binormal3bEXT
void Binormal3bEXT(GLbyte bx, GLbyte by, GLbyte bz) {
    
printf(gl.c);
}
#endif

#ifndef skip_Binormal3bvEXT
void Binormal3bvEXT(GLbyte v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Binormal3dEXT
void Binormal3dEXT(GLdouble bx, GLdouble by, GLdouble bz) {
    
printf(gl.c);
}
#endif

#ifndef skip_Binormal3dvEXT
void Binormal3dvEXT(GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Binormal3fEXT
void Binormal3fEXT(GLfloat bx, GLfloat by, GLfloat bz) {
    
printf(gl.c);
}
#endif

#ifndef skip_Binormal3fvEXT
void Binormal3fvEXT(GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Binormal3iEXT
void Binormal3iEXT(GLint bx, GLint by, GLint bz) {
    
printf(gl.c);
}
#endif

#ifndef skip_Binormal3ivEXT
void Binormal3ivEXT(GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Binormal3sEXT
void Binormal3sEXT(GLshort bx, GLshort by, GLshort bz) {
    
printf(gl.c);
}
#endif

#ifndef skip_Binormal3svEXT
void Binormal3svEXT(GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_BinormalPointerEXT
void BinormalPointerEXT(GLenum type, GLsizei stride, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_Bitmap
void Bitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, GLubyte bitmap) {
    
printf(gl.c);
}
#endif

#ifndef skip_BitmapxOES
void BitmapxOES(GLsizei width, GLsizei height, GLfixed xorig, GLfixed yorig, GLfixed xmove, GLfixed ymove, GLubyte bitmap) {
    
printf(gl.c);
}
#endif

#ifndef skip_BlendColor
void BlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_BlendColorEXT
void BlendColorEXT(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_BlendColorxOES
void BlendColorxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_BlendEquation
void BlendEquation(GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_BlendEquationEXT
void BlendEquationEXT(GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_BlendEquationIndexedAMD
void BlendEquationIndexedAMD(GLuint buf, GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_BlendEquationSeparate
void BlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_BlendEquationSeparateEXT
void BlendEquationSeparateEXT(GLenum modeRGB, GLenum modeAlpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_BlendEquationSeparateIndexedAMD
void BlendEquationSeparateIndexedAMD(GLuint buf, GLenum modeRGB, GLenum modeAlpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_BlendEquationSeparatei
void BlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_BlendEquationSeparateiARB
void BlendEquationSeparateiARB(GLuint buf, GLenum modeRGB, GLenum modeAlpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_BlendEquationi
void BlendEquationi(GLuint buf, GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_BlendEquationiARB
void BlendEquationiARB(GLuint buf, GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_BlendFunc
void BlendFunc(GLenum sfactor, GLenum dfactor) {
    
printf(gl.c);
}
#endif

#ifndef skip_BlendFuncIndexedAMD
void BlendFuncIndexedAMD(GLuint buf, GLenum src, GLenum dst) {
    
printf(gl.c);
}
#endif

#ifndef skip_BlendFuncSeparate
void BlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_BlendFuncSeparateEXT
void BlendFuncSeparateEXT(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_BlendFuncSeparateINGR
void BlendFuncSeparateINGR(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_BlendFuncSeparateIndexedAMD
void BlendFuncSeparateIndexedAMD(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_BlendFuncSeparatei
void BlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_BlendFuncSeparateiARB
void BlendFuncSeparateiARB(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_BlendFunci
void BlendFunci(GLuint buf, GLenum src, GLenum dst) {
    
printf(gl.c);
}
#endif

#ifndef skip_BlendFunciARB
void BlendFunciARB(GLuint buf, GLenum src, GLenum dst) {
    
printf(gl.c);
}
#endif

#ifndef skip_BlitFramebuffer
void BlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
    
printf(gl.c);
}
#endif

#ifndef skip_BlitFramebufferEXT
void BlitFramebufferEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
    
printf(gl.c);
}
#endif

#ifndef skip_BufferAddressRangeNV
void BufferAddressRangeNV(GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length) {
    
printf(gl.c);
}
#endif

#ifndef skip_BufferData
void BufferData(GLenum target, GLsizeiptr size, GLvoid data, GLenum usage) {
    
printf(gl.c);
}
#endif

#ifndef skip_BufferDataARB
void BufferDataARB(GLenum target, GLsizeiptrARB size, GLvoid data, GLenum usage) {
    
printf(gl.c);
}
#endif

#ifndef skip_BufferParameteriAPPLE
void BufferParameteriAPPLE(GLenum target, GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_BufferSubData
void BufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid data) {
    
printf(gl.c);
}
#endif

#ifndef skip_BufferSubDataARB
void BufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid data) {
    
printf(gl.c);
}
#endif

#ifndef skip_CallList
void CallList(GLuint list) {
    
printf(gl.c);
}
#endif

#ifndef skip_CallLists
void CallLists(GLsizei n, GLenum type, GLvoid lists) {
    
printf(gl.c);
}
#endif

#ifndef skip_CheckFramebufferStatus
GLenum CheckFramebufferStatus(GLenum target) {
    
printf(gl.c);
}
#endif

#ifndef skip_CheckFramebufferStatusEXT
GLenum CheckFramebufferStatusEXT(GLenum target) {
    
printf(gl.c);
}
#endif

#ifndef skip_CheckNamedFramebufferStatusEXT
FramebufferStatus CheckNamedFramebufferStatusEXT(GLuint framebuffer, GLenum target) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClampColor
void ClampColor(GLenum target, GLenum clamp) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClampColorARB
void ClampColorARB(GLenum target, GLenum clamp) {
    
printf(gl.c);
}
#endif

#ifndef skip_Clear
void Clear(GLbitfield mask) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClearAccum
void ClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClearAccumxOES
void ClearAccumxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClearBufferData
void ClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, void * data) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClearBufferSubData
void ClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, void * data) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClearBufferfi
void ClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClearBufferfv
void ClearBufferfv(GLenum buffer, GLint drawbuffer, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClearBufferiv
void ClearBufferiv(GLenum buffer, GLint drawbuffer, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClearBufferuiv
void ClearBufferuiv(GLenum buffer, GLint drawbuffer, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClearColor
void ClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClearColorIiEXT
void ClearColorIiEXT(GLint red, GLint green, GLint blue, GLint alpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClearColorIuiEXT
void ClearColorIuiEXT(GLuint red, GLuint green, GLuint blue, GLuint alpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClearColorxOES
void ClearColorxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClearDepth
void ClearDepth(GLdouble depth) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClearDepthdNV
void ClearDepthdNV(GLdouble depth) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClearDepthf
void ClearDepthf(GLfloat d) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClearDepthfOES
void ClearDepthfOES(GLclampf depth) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClearDepthxOES
void ClearDepthxOES(GLfixed depth) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClearIndex
void ClearIndex(GLfloat c) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClearNamedBufferDataEXT
void ClearNamedBufferDataEXT(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, void * data) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClearNamedBufferSubDataEXT
void ClearNamedBufferSubDataEXT(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, GLsizeiptr offset, GLsizeiptr size, void * data) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClearStencil
void ClearStencil(GLint s) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClientActiveTexture
void ClientActiveTexture(GLenum texture) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClientActiveTextureARB
void ClientActiveTextureARB(GLenum texture) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClientActiveVertexStreamATI
void ClientActiveVertexStreamATI(GLenum stream) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClientAttribDefaultEXT
void ClientAttribDefaultEXT(GLbitfield mask) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClientWaitSync
GLenum ClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClipPlane
void ClipPlane(GLenum plane, GLdouble equation) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClipPlanefOES
void ClipPlanefOES(GLenum plane, GLfloat equation) {
    
printf(gl.c);
}
#endif

#ifndef skip_ClipPlanexOES
void ClipPlanexOES(GLenum plane, GLfixed equation) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color3b
void Color3b(GLbyte red, GLbyte green, GLbyte blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color3bv
void Color3bv(GLbyte v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color3d
void Color3d(GLdouble red, GLdouble green, GLdouble blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color3dv
void Color3dv(GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color3f
void Color3f(GLfloat red, GLfloat green, GLfloat blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color3fVertex3fSUN
void Color3fVertex3fSUN(GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color3fVertex3fvSUN
void Color3fVertex3fvSUN(GLfloat c, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color3fv
void Color3fv(GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color3hNV
void Color3hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color3hvNV
void Color3hvNV(GLhalfNV v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color3i
void Color3i(GLint red, GLint green, GLint blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color3iv
void Color3iv(GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color3s
void Color3s(GLshort red, GLshort green, GLshort blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color3sv
void Color3sv(GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color3ub
void Color3ub(GLubyte red, GLubyte green, GLubyte blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color3ubv
void Color3ubv(GLubyte v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color3ui
void Color3ui(GLuint red, GLuint green, GLuint blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color3uiv
void Color3uiv(GLuint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color3us
void Color3us(GLushort red, GLushort green, GLushort blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color3usv
void Color3usv(GLushort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color3xOES
void Color3xOES(GLfixed red, GLfixed green, GLfixed blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color3xvOES
void Color3xvOES(GLfixed components) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4b
void Color4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4bv
void Color4bv(GLbyte v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4d
void Color4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4dv
void Color4dv(GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4f
void Color4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4fNormal3fVertex3fSUN
void Color4fNormal3fVertex3fSUN(GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4fNormal3fVertex3fvSUN
void Color4fNormal3fVertex3fvSUN(GLfloat c, GLfloat n, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4fv
void Color4fv(GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4hNV
void Color4hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue, GLhalfNV alpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4hvNV
void Color4hvNV(GLhalfNV v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4i
void Color4i(GLint red, GLint green, GLint blue, GLint alpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4iv
void Color4iv(GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4s
void Color4s(GLshort red, GLshort green, GLshort blue, GLshort alpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4sv
void Color4sv(GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4ub
void Color4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4ubVertex2fSUN
void Color4ubVertex2fSUN(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4ubVertex2fvSUN
void Color4ubVertex2fvSUN(GLubyte c, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4ubVertex3fSUN
void Color4ubVertex3fSUN(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4ubVertex3fvSUN
void Color4ubVertex3fvSUN(GLubyte c, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4ubv
void Color4ubv(GLubyte v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4ui
void Color4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4uiv
void Color4uiv(GLuint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4us
void Color4us(GLushort red, GLushort green, GLushort blue, GLushort alpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4usv
void Color4usv(GLushort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4xOES
void Color4xOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_Color4xvOES
void Color4xvOES(GLfixed components) {
    
printf(gl.c);
}
#endif

#ifndef skip_ColorFormatNV
void ColorFormatNV(GLint size, GLenum type, GLsizei stride) {
    
printf(gl.c);
}
#endif

#ifndef skip_ColorFragmentOp1ATI
void ColorFragmentOp1ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod) {
    
printf(gl.c);
}
#endif

#ifndef skip_ColorFragmentOp2ATI
void ColorFragmentOp2ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod) {
    
printf(gl.c);
}
#endif

#ifndef skip_ColorFragmentOp3ATI
void ColorFragmentOp3ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod) {
    
printf(gl.c);
}
#endif

#ifndef skip_ColorMask
void ColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_ColorMaskIndexedEXT
void ColorMaskIndexedEXT(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) {
    
printf(gl.c);
}
#endif

#ifndef skip_ColorMaski
void ColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) {
    
printf(gl.c);
}
#endif

#ifndef skip_ColorMaterial
void ColorMaterial(GLenum face, GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_ColorP3ui
void ColorP3ui(GLenum type, GLuint color) {
    
printf(gl.c);
}
#endif

#ifndef skip_ColorP3uiv
void ColorP3uiv(GLenum type, GLuint color) {
    
printf(gl.c);
}
#endif

#ifndef skip_ColorP4ui
void ColorP4ui(GLenum type, GLuint color) {
    
printf(gl.c);
}
#endif

#ifndef skip_ColorP4uiv
void ColorP4uiv(GLenum type, GLuint color) {
    
printf(gl.c);
}
#endif

#ifndef skip_ColorPointer
void ColorPointer(GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_ColorPointerEXT
void ColorPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_ColorPointerListIBM
void ColorPointerListIBM(GLint size, GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride) {
    
printf(gl.c);
}
#endif

#ifndef skip_ColorPointervINTEL
void ColorPointervINTEL(GLint size, GLenum type, GLvoid * pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_ColorSubTable
void ColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, GLvoid data) {
    
printf(gl.c);
}
#endif

#ifndef skip_ColorSubTableEXT
void ColorSubTableEXT(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, GLvoid data) {
    
printf(gl.c);
}
#endif

#ifndef skip_ColorTable
void ColorTable(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, GLvoid table) {
    
printf(gl.c);
}
#endif

#ifndef skip_ColorTableEXT
void ColorTableEXT(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, GLvoid table) {
    
printf(gl.c);
}
#endif

#ifndef skip_ColorTableParameterfv
void ColorTableParameterfv(GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ColorTableParameterfvSGI
void ColorTableParameterfvSGI(GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ColorTableParameteriv
void ColorTableParameteriv(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ColorTableParameterivSGI
void ColorTableParameterivSGI(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ColorTableSGI
void ColorTableSGI(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, GLvoid table) {
    
printf(gl.c);
}
#endif

#ifndef skip_CombinerInputNV
void CombinerInputNV(GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage) {
    
printf(gl.c);
}
#endif

#ifndef skip_CombinerOutputNV
void CombinerOutputNV(GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum) {
    
printf(gl.c);
}
#endif

#ifndef skip_CombinerParameterfNV
void CombinerParameterfNV(GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_CombinerParameterfvNV
void CombinerParameterfvNV(GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_CombinerParameteriNV
void CombinerParameteriNV(GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_CombinerParameterivNV
void CombinerParameterivNV(GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_CombinerStageParameterfvNV
void CombinerStageParameterfvNV(GLenum stage, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompileShader
void CompileShader(GLuint shader) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompileShaderARB
void CompileShaderARB(GLhandleARB shaderObj) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompileShaderIncludeARB
void CompileShaderIncludeARB(GLuint shader, GLsizei count, GLchar * path, GLint length) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompressedMultiTexImage1DEXT
void CompressedMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid bits) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompressedMultiTexImage2DEXT
void CompressedMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid bits) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompressedMultiTexImage3DEXT
void CompressedMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid bits) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompressedMultiTexSubImage1DEXT
void CompressedMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid bits) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompressedMultiTexSubImage2DEXT
void CompressedMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid bits) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompressedMultiTexSubImage3DEXT
void CompressedMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid bits) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompressedTexImage1D
void CompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid data) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompressedTexImage1DARB
void CompressedTexImage1DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid data) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompressedTexImage2D
void CompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid data) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompressedTexImage2DARB
void CompressedTexImage2DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid data) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompressedTexImage3D
void CompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid data) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompressedTexImage3DARB
void CompressedTexImage3DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid data) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompressedTexSubImage1D
void CompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid data) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompressedTexSubImage1DARB
void CompressedTexSubImage1DARB(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid data) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompressedTexSubImage2D
void CompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid data) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompressedTexSubImage2DARB
void CompressedTexSubImage2DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid data) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompressedTexSubImage3D
void CompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid data) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompressedTexSubImage3DARB
void CompressedTexSubImage3DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid data) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompressedTextureImage1DEXT
void CompressedTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid bits) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompressedTextureImage2DEXT
void CompressedTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid bits) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompressedTextureImage3DEXT
void CompressedTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid bits) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompressedTextureSubImage1DEXT
void CompressedTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid bits) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompressedTextureSubImage2DEXT
void CompressedTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid bits) {
    
printf(gl.c);
}
#endif

#ifndef skip_CompressedTextureSubImage3DEXT
void CompressedTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid bits) {
    
printf(gl.c);
}
#endif

#ifndef skip_ConvolutionFilter1D
void ConvolutionFilter1D(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, GLvoid image) {
    
printf(gl.c);
}
#endif

#ifndef skip_ConvolutionFilter1DEXT
void ConvolutionFilter1DEXT(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, GLvoid image) {
    
printf(gl.c);
}
#endif

#ifndef skip_ConvolutionFilter2D
void ConvolutionFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid image) {
    
printf(gl.c);
}
#endif

#ifndef skip_ConvolutionFilter2DEXT
void ConvolutionFilter2DEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid image) {
    
printf(gl.c);
}
#endif

#ifndef skip_ConvolutionParameterf
void ConvolutionParameterf(GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ConvolutionParameterfEXT
void ConvolutionParameterfEXT(GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ConvolutionParameterfv
void ConvolutionParameterfv(GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ConvolutionParameterfvEXT
void ConvolutionParameterfvEXT(GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ConvolutionParameteri
void ConvolutionParameteri(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ConvolutionParameteriEXT
void ConvolutionParameteriEXT(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ConvolutionParameteriv
void ConvolutionParameteriv(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ConvolutionParameterivEXT
void ConvolutionParameterivEXT(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ConvolutionParameterxOES
void ConvolutionParameterxOES(GLenum target, GLenum pname, GLfixed param) {
    
printf(gl.c);
}
#endif

#ifndef skip_ConvolutionParameterxvOES
void ConvolutionParameterxvOES(GLenum target, GLenum pname, GLfixed params) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyBufferSubData
void CopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyColorSubTable
void CopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyColorSubTableEXT
void CopyColorSubTableEXT(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyColorTable
void CopyColorTable(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyColorTableSGI
void CopyColorTableSGI(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyConvolutionFilter1D
void CopyConvolutionFilter1D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyConvolutionFilter1DEXT
void CopyConvolutionFilter1DEXT(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyConvolutionFilter2D
void CopyConvolutionFilter2D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyConvolutionFilter2DEXT
void CopyConvolutionFilter2DEXT(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyImageSubData
void CopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyImageSubDataNV
void CopyImageSubDataNV(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyMultiTexImage1DEXT
void CopyMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyMultiTexImage2DEXT
void CopyMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyMultiTexSubImage1DEXT
void CopyMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyMultiTexSubImage2DEXT
void CopyMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyMultiTexSubImage3DEXT
void CopyMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyPathNV
void CopyPathNV(GLuint resultPath, GLuint srcPath) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyPixels
void CopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyTexImage1D
void CopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyTexImage1DEXT
void CopyTexImage1DEXT(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyTexImage2D
void CopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyTexImage2DEXT
void CopyTexImage2DEXT(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyTexSubImage1D
void CopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyTexSubImage1DEXT
void CopyTexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyTexSubImage2D
void CopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyTexSubImage2DEXT
void CopyTexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyTexSubImage3D
void CopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyTexSubImage3DEXT
void CopyTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyTextureImage1DEXT
void CopyTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyTextureImage2DEXT
void CopyTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyTextureSubImage1DEXT
void CopyTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyTextureSubImage2DEXT
void CopyTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyTextureSubImage3DEXT
void CopyTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    
printf(gl.c);
}
#endif

#ifndef skip_CoverFillPathInstancedNV
void CoverFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLenum coverMode, GLenum transformType, GLfloat transformValues) {
    
printf(gl.c);
}
#endif

#ifndef skip_CoverFillPathNV
void CoverFillPathNV(GLuint path, GLenum coverMode) {
    
printf(gl.c);
}
#endif

#ifndef skip_CoverStrokePathInstancedNV
void CoverStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLenum coverMode, GLenum transformType, GLfloat transformValues) {
    
printf(gl.c);
}
#endif

#ifndef skip_CoverStrokePathNV
void CoverStrokePathNV(GLuint path, GLenum coverMode) {
    
printf(gl.c);
}
#endif

#ifndef skip_CreateProgram
UInt32 CreateProgram() {
    
printf(gl.c);
}
#endif

#ifndef skip_CreateProgramObjectARB
handleARB CreateProgramObjectARB() {
    
printf(gl.c);
}
#endif

#ifndef skip_CreateShader
UInt32 CreateShader(GLenum type) {
    
printf(gl.c);
}
#endif

#ifndef skip_CreateShaderObjectARB
handleARB CreateShaderObjectARB(GLenum shaderType) {
    
printf(gl.c);
}
#endif

#ifndef skip_CreateShaderProgramEXT
UInt32 CreateShaderProgramEXT(GLenum type, GLchar string) {
    
printf(gl.c);
}
#endif

#ifndef skip_CreateShaderProgramv
UInt32 CreateShaderProgramv(GLenum type, GLsizei count, GLchar*const strings) {
    
printf(gl.c);
}
#endif

#ifndef skip_CreateSyncFromCLeventARB
sync CreateSyncFromCLeventARB(struct _cl_context * context, struct _cl_event * event, GLbitfield flags) {
    
printf(gl.c);
}
#endif

#ifndef skip_CullFace
void CullFace(GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_CullParameterdvEXT
void CullParameterdvEXT(GLenum pname, GLdouble params) {
    
printf(gl.c);
}
#endif

#ifndef skip_CullParameterfvEXT
void CullParameterfvEXT(GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_CurrentPaletteMatrixARB
void CurrentPaletteMatrixARB(GLint index) {
    
printf(gl.c);
}
#endif

#ifndef skip_DebugMessageCallback
void DebugMessageCallback(GLDEBUGPROC callback, void * userParam) {
    
printf(gl.c);
}
#endif

#ifndef skip_DebugMessageCallbackAMD
void DebugMessageCallbackAMD(GLDEBUGPROCAMD callback, GLvoid userParam) {
    
printf(gl.c);
}
#endif

#ifndef skip_DebugMessageCallbackARB
void DebugMessageCallbackARB(GLDEBUGPROCARB callback, GLvoid userParam) {
    
printf(gl.c);
}
#endif

#ifndef skip_DebugMessageControl
void DebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, GLuint ids, GLboolean enabled) {
    
printf(gl.c);
}
#endif

#ifndef skip_DebugMessageControlARB
void DebugMessageControlARB(GLenum source, GLenum type, GLenum severity, GLsizei count, GLuint ids, GLboolean enabled) {
    
printf(gl.c);
}
#endif

#ifndef skip_DebugMessageEnableAMD
void DebugMessageEnableAMD(GLenum category, GLenum severity, GLsizei count, GLuint ids, GLboolean enabled) {
    
printf(gl.c);
}
#endif

#ifndef skip_DebugMessageInsert
void DebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, GLchar buf) {
    
printf(gl.c);
}
#endif

#ifndef skip_DebugMessageInsertAMD
void DebugMessageInsertAMD(GLenum category, GLenum severity, GLuint id, GLsizei length, GLchar buf) {
    
printf(gl.c);
}
#endif

#ifndef skip_DebugMessageInsertARB
void DebugMessageInsertARB(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, GLchar buf) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeformSGIX
void DeformSGIX(GLbitfield mask) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeformationMap3dSGIX
void DeformationMap3dSGIX(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble w1, GLdouble w2, GLint wstride, GLint worder, GLdouble points) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeformationMap3fSGIX
void DeformationMap3fSGIX(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat w1, GLfloat w2, GLint wstride, GLint worder, GLfloat points) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteAsyncMarkersSGIX
void DeleteAsyncMarkersSGIX(GLuint marker, GLsizei range) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteBuffers
void DeleteBuffers(GLsizei n, GLuint buffers) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteBuffersARB
void DeleteBuffersARB(GLsizei n, GLuint buffers) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteFencesAPPLE
void DeleteFencesAPPLE(GLsizei n, GLuint fences) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteFencesNV
void DeleteFencesNV(GLsizei n, GLuint fences) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteFragmentShaderATI
void DeleteFragmentShaderATI(GLuint id) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteFramebuffers
void DeleteFramebuffers(GLsizei n, GLuint framebuffers) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteFramebuffersEXT
void DeleteFramebuffersEXT(GLsizei n, GLuint framebuffers) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteLists
void DeleteLists(GLuint list, GLsizei range) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteNamedStringARB
void DeleteNamedStringARB(GLint namelen, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteNamesAMD
void DeleteNamesAMD(GLenum identifier, GLuint num, GLuint names) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteObjectARB
void DeleteObjectARB(GLhandleARB obj) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteOcclusionQueriesNV
void DeleteOcclusionQueriesNV(GLsizei n, GLuint ids) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeletePathsNV
void DeletePathsNV(GLuint path, GLsizei range) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeletePerfMonitorsAMD
void DeletePerfMonitorsAMD(GLsizei n, GLuint monitors) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteProgram
void DeleteProgram(GLuint program) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteProgramPipelines
void DeleteProgramPipelines(GLsizei n, GLuint pipelines) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteProgramsARB
void DeleteProgramsARB(GLsizei n, GLuint programs) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteProgramsNV
void DeleteProgramsNV(GLsizei n, GLuint programs) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteQueries
void DeleteQueries(GLsizei n, GLuint ids) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteQueriesARB
void DeleteQueriesARB(GLsizei n, GLuint ids) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteRenderbuffers
void DeleteRenderbuffers(GLsizei n, GLuint renderbuffers) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteRenderbuffersEXT
void DeleteRenderbuffersEXT(GLsizei n, GLuint renderbuffers) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteSamplers
void DeleteSamplers(GLsizei count, GLuint samplers) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteShader
void DeleteShader(GLuint shader) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteSync
void DeleteSync(GLsync sync) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteTextures
void DeleteTextures(GLsizei n, GLuint textures) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteTexturesEXT
void DeleteTexturesEXT(GLsizei n, GLuint textures) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteTransformFeedbacks
void DeleteTransformFeedbacks(GLsizei n, GLuint ids) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteTransformFeedbacksNV
void DeleteTransformFeedbacksNV(GLsizei n, GLuint ids) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteVertexArrays
void DeleteVertexArrays(GLsizei n, GLuint arrays) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteVertexArraysAPPLE
void DeleteVertexArraysAPPLE(GLsizei n, GLuint arrays) {
    
printf(gl.c);
}
#endif

#ifndef skip_DeleteVertexShaderEXT
void DeleteVertexShaderEXT(GLuint id) {
    
printf(gl.c);
}
#endif

#ifndef skip_DepthBoundsEXT
void DepthBoundsEXT(GLclampd zmin, GLclampd zmax) {
    
printf(gl.c);
}
#endif

#ifndef skip_DepthBoundsdNV
void DepthBoundsdNV(GLdouble zmin, GLdouble zmax) {
    
printf(gl.c);
}
#endif

#ifndef skip_DepthFunc
void DepthFunc(GLenum func) {
    
printf(gl.c);
}
#endif

#ifndef skip_DepthMask
void DepthMask(GLboolean flag) {
    
printf(gl.c);
}
#endif

#ifndef skip_DepthRange
void DepthRange(GLdouble near, GLdouble far) {
    
printf(gl.c);
}
#endif

#ifndef skip_DepthRangeArrayv
void DepthRangeArrayv(GLuint first, GLsizei count, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_DepthRangeIndexed
void DepthRangeIndexed(GLuint index, GLdouble n, GLdouble f) {
    
printf(gl.c);
}
#endif

#ifndef skip_DepthRangedNV
void DepthRangedNV(GLdouble zNear, GLdouble zFar) {
    
printf(gl.c);
}
#endif

#ifndef skip_DepthRangef
void DepthRangef(GLfloat n, GLfloat f) {
    
printf(gl.c);
}
#endif

#ifndef skip_DepthRangefOES
void DepthRangefOES(GLclampf n, GLclampf f) {
    
printf(gl.c);
}
#endif

#ifndef skip_DepthRangexOES
void DepthRangexOES(GLfixed n, GLfixed f) {
    
printf(gl.c);
}
#endif

#ifndef skip_DetachObjectARB
void DetachObjectARB(GLhandleARB containerObj, GLhandleARB attachedObj) {
    
printf(gl.c);
}
#endif

#ifndef skip_DetachShader
void DetachShader(GLuint program, GLuint shader) {
    
printf(gl.c);
}
#endif

#ifndef skip_DetailTexFuncSGIS
void DetailTexFuncSGIS(GLenum target, GLsizei n, GLfloat points) {
    
printf(gl.c);
}
#endif

#ifndef skip_Disable
void Disable(GLenum cap) {
    
printf(gl.c);
}
#endif

#ifndef skip_DisableClientState
void DisableClientState(GLenum array) {
    
printf(gl.c);
}
#endif

#ifndef skip_DisableClientStateIndexedEXT
void DisableClientStateIndexedEXT(GLenum array, GLuint index) {
    
printf(gl.c);
}
#endif

#ifndef skip_DisableClientStateiEXT
void DisableClientStateiEXT(GLenum array, GLuint index) {
    
printf(gl.c);
}
#endif

#ifndef skip_DisableIndexedEXT
void DisableIndexedEXT(GLenum target, GLuint index) {
    
printf(gl.c);
}
#endif

#ifndef skip_DisableVariantClientStateEXT
void DisableVariantClientStateEXT(GLuint id) {
    
printf(gl.c);
}
#endif

#ifndef skip_DisableVertexArrayAttribEXT
void DisableVertexArrayAttribEXT(GLuint vaobj, GLuint index) {
    
printf(gl.c);
}
#endif

#ifndef skip_DisableVertexArrayEXT
void DisableVertexArrayEXT(GLuint vaobj, GLenum array) {
    
printf(gl.c);
}
#endif

#ifndef skip_DisableVertexAttribAPPLE
void DisableVertexAttribAPPLE(GLuint index, GLenum pname) {
    
printf(gl.c);
}
#endif

#ifndef skip_DisableVertexAttribArray
void DisableVertexAttribArray(GLuint index) {
    
printf(gl.c);
}
#endif

#ifndef skip_DisableVertexAttribArrayARB
void DisableVertexAttribArrayARB(GLuint index) {
    
printf(gl.c);
}
#endif

#ifndef skip_Disablei
void Disablei(GLenum target, GLuint index) {
    
printf(gl.c);
}
#endif

#ifndef skip_DispatchCompute
void DispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z) {
    
printf(gl.c);
}
#endif

#ifndef skip_DispatchComputeIndirect
void DispatchComputeIndirect(GLintptr indirect) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawArrays
void DrawArrays(GLenum mode, GLint first, GLsizei count) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawArraysEXT
void DrawArraysEXT(GLenum mode, GLint first, GLsizei count) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawArraysIndirect
void DrawArraysIndirect(GLenum mode, GLvoid indirect) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawArraysInstanced
void DrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawArraysInstancedARB
void DrawArraysInstancedARB(GLenum mode, GLint first, GLsizei count, GLsizei primcount) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawArraysInstancedBaseInstance
void DrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawArraysInstancedEXT
void DrawArraysInstancedEXT(GLenum mode, GLint start, GLsizei count, GLsizei primcount) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawBuffer
void DrawBuffer(GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawBuffers
void DrawBuffers(GLsizei n, GLenum bufs) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawBuffersARB
void DrawBuffersARB(GLsizei n, GLenum bufs) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawBuffersATI
void DrawBuffersATI(GLsizei n, GLenum bufs) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawElementArrayAPPLE
void DrawElementArrayAPPLE(GLenum mode, GLint first, GLsizei count) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawElementArrayATI
void DrawElementArrayATI(GLenum mode, GLsizei count) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawElements
void DrawElements(GLenum mode, GLsizei count, GLenum type, GLvoid indices) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawElementsBaseVertex
void DrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid indices, GLint basevertex) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawElementsIndirect
void DrawElementsIndirect(GLenum mode, GLenum type, GLvoid indirect) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawElementsInstanced
void DrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, GLvoid indices, GLsizei instancecount) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawElementsInstancedARB
void DrawElementsInstancedARB(GLenum mode, GLsizei count, GLenum type, GLvoid indices, GLsizei primcount) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawElementsInstancedBaseInstance
void DrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, void * indices, GLsizei instancecount, GLuint baseinstance) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawElementsInstancedBaseVertex
void DrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid indices, GLsizei instancecount, GLint basevertex) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawElementsInstancedBaseVertexBaseInstance
void DrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawElementsInstancedEXT
void DrawElementsInstancedEXT(GLenum mode, GLsizei count, GLenum type, GLvoid indices, GLsizei primcount) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawMeshArraysSUN
void DrawMeshArraysSUN(GLenum mode, GLint first, GLsizei count, GLsizei width) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawPixels
void DrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawRangeElementArrayAPPLE
void DrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawRangeElementArrayATI
void DrawRangeElementArrayATI(GLenum mode, GLuint start, GLuint end, GLsizei count) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawRangeElements
void DrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid indices) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawRangeElementsBaseVertex
void DrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid indices, GLint basevertex) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawRangeElementsEXT
void DrawRangeElementsEXT(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid indices) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawTextureNV
void DrawTextureNV(GLuint texture, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawTransformFeedback
void DrawTransformFeedback(GLenum mode, GLuint id) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawTransformFeedbackInstanced
void DrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawTransformFeedbackNV
void DrawTransformFeedbackNV(GLenum mode, GLuint id) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawTransformFeedbackStream
void DrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream) {
    
printf(gl.c);
}
#endif

#ifndef skip_DrawTransformFeedbackStreamInstanced
void DrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount) {
    
printf(gl.c);
}
#endif

#ifndef skip_EdgeFlag
void EdgeFlag(GLboolean flag) {
    
printf(gl.c);
}
#endif

#ifndef skip_EdgeFlagFormatNV
void EdgeFlagFormatNV(GLsizei stride) {
    
printf(gl.c);
}
#endif

#ifndef skip_EdgeFlagPointer
void EdgeFlagPointer(GLsizei stride, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_EdgeFlagPointerEXT
void EdgeFlagPointerEXT(GLsizei stride, GLsizei count, GLboolean pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_EdgeFlagPointerListIBM
void EdgeFlagPointerListIBM(GLint stride, GLboolean * pointer, GLint ptrstride) {
    
printf(gl.c);
}
#endif

#ifndef skip_EdgeFlagv
void EdgeFlagv(GLboolean flag) {
    
printf(gl.c);
}
#endif

#ifndef skip_ElementPointerAPPLE
void ElementPointerAPPLE(GLenum type, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_ElementPointerATI
void ElementPointerATI(GLenum type, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_Enable
void Enable(GLenum cap) {
    
printf(gl.c);
}
#endif

#ifndef skip_EnableClientState
void EnableClientState(GLenum array) {
    
printf(gl.c);
}
#endif

#ifndef skip_EnableClientStateIndexedEXT
void EnableClientStateIndexedEXT(GLenum array, GLuint index) {
    
printf(gl.c);
}
#endif

#ifndef skip_EnableClientStateiEXT
void EnableClientStateiEXT(GLenum array, GLuint index) {
    
printf(gl.c);
}
#endif

#ifndef skip_EnableIndexedEXT
void EnableIndexedEXT(GLenum target, GLuint index) {
    
printf(gl.c);
}
#endif

#ifndef skip_EnableVariantClientStateEXT
void EnableVariantClientStateEXT(GLuint id) {
    
printf(gl.c);
}
#endif

#ifndef skip_EnableVertexArrayAttribEXT
void EnableVertexArrayAttribEXT(GLuint vaobj, GLuint index) {
    
printf(gl.c);
}
#endif

#ifndef skip_EnableVertexArrayEXT
void EnableVertexArrayEXT(GLuint vaobj, GLenum array) {
    
printf(gl.c);
}
#endif

#ifndef skip_EnableVertexAttribAPPLE
void EnableVertexAttribAPPLE(GLuint index, GLenum pname) {
    
printf(gl.c);
}
#endif

#ifndef skip_EnableVertexAttribArray
void EnableVertexAttribArray(GLuint index) {
    
printf(gl.c);
}
#endif

#ifndef skip_EnableVertexAttribArrayARB
void EnableVertexAttribArrayARB(GLuint index) {
    
printf(gl.c);
}
#endif

#ifndef skip_Enablei
void Enablei(GLenum target, GLuint index) {
    
printf(gl.c);
}
#endif

#ifndef skip_End
void End() {
    
printf(gl.c);
}
#endif

#ifndef skip_EndConditionalRender
void EndConditionalRender() {
    
printf(gl.c);
}
#endif

#ifndef skip_EndConditionalRenderNV
void EndConditionalRenderNV() {
    
printf(gl.c);
}
#endif

#ifndef skip_EndConditionalRenderNVX
void EndConditionalRenderNVX() {
    
printf(gl.c);
}
#endif

#ifndef skip_EndFragmentShaderATI
void EndFragmentShaderATI() {
    
printf(gl.c);
}
#endif

#ifndef skip_EndList
void EndList() {
    
printf(gl.c);
}
#endif

#ifndef skip_EndOcclusionQueryNV
void EndOcclusionQueryNV() {
    
printf(gl.c);
}
#endif

#ifndef skip_EndPerfMonitorAMD
void EndPerfMonitorAMD(GLuint monitor) {
    
printf(gl.c);
}
#endif

#ifndef skip_EndQuery
void EndQuery(GLenum target) {
    
printf(gl.c);
}
#endif

#ifndef skip_EndQueryARB
void EndQueryARB(GLenum target) {
    
printf(gl.c);
}
#endif

#ifndef skip_EndQueryIndexed
void EndQueryIndexed(GLenum target, GLuint index) {
    
printf(gl.c);
}
#endif

#ifndef skip_EndTransformFeedback
void EndTransformFeedback() {
    
printf(gl.c);
}
#endif

#ifndef skip_EndTransformFeedbackEXT
void EndTransformFeedbackEXT() {
    
printf(gl.c);
}
#endif

#ifndef skip_EndTransformFeedbackNV
void EndTransformFeedbackNV() {
    
printf(gl.c);
}
#endif

#ifndef skip_EndVertexShaderEXT
void EndVertexShaderEXT() {
    
printf(gl.c);
}
#endif

#ifndef skip_EndVideoCaptureNV
void EndVideoCaptureNV(GLuint video_capture_slot) {
    
printf(gl.c);
}
#endif

#ifndef skip_EvalCoord1d
void EvalCoord1d(GLdouble u) {
    
printf(gl.c);
}
#endif

#ifndef skip_EvalCoord1dv
void EvalCoord1dv(GLdouble u) {
    
printf(gl.c);
}
#endif

#ifndef skip_EvalCoord1f
void EvalCoord1f(GLfloat u) {
    
printf(gl.c);
}
#endif

#ifndef skip_EvalCoord1fv
void EvalCoord1fv(GLfloat u) {
    
printf(gl.c);
}
#endif

#ifndef skip_EvalCoord1xOES
void EvalCoord1xOES(GLfixed u) {
    
printf(gl.c);
}
#endif

#ifndef skip_EvalCoord1xvOES
void EvalCoord1xvOES(GLfixed coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_EvalCoord2d
void EvalCoord2d(GLdouble u, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_EvalCoord2dv
void EvalCoord2dv(GLdouble u) {
    
printf(gl.c);
}
#endif

#ifndef skip_EvalCoord2f
void EvalCoord2f(GLfloat u, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_EvalCoord2fv
void EvalCoord2fv(GLfloat u) {
    
printf(gl.c);
}
#endif

#ifndef skip_EvalCoord2xOES
void EvalCoord2xOES(GLfixed u, GLfixed v) {
    
printf(gl.c);
}
#endif

#ifndef skip_EvalCoord2xvOES
void EvalCoord2xvOES(GLfixed coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_EvalMapsNV
void EvalMapsNV(GLenum target, GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_EvalMesh1
void EvalMesh1(GLenum mode, GLint i1, GLint i2) {
    
printf(gl.c);
}
#endif

#ifndef skip_EvalMesh2
void EvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2) {
    
printf(gl.c);
}
#endif

#ifndef skip_EvalPoint1
void EvalPoint1(GLint i) {
    
printf(gl.c);
}
#endif

#ifndef skip_EvalPoint2
void EvalPoint2(GLint i, GLint j) {
    
printf(gl.c);
}
#endif

#ifndef skip_ExecuteProgramNV
void ExecuteProgramNV(GLenum target, GLuint id, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ExtractComponentEXT
void ExtractComponentEXT(GLuint res, GLuint src, GLuint num) {
    
printf(gl.c);
}
#endif

#ifndef skip_FeedbackBuffer
void FeedbackBuffer(GLsizei size, GLenum type, GLfloat buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_FeedbackBufferxOES
void FeedbackBufferxOES(GLsizei n, GLenum type, GLfixed buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_FenceSync
sync FenceSync(GLenum condition, GLbitfield flags) {
    
printf(gl.c);
}
#endif

#ifndef skip_FinalCombinerInputNV
void FinalCombinerInputNV(GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage) {
    
printf(gl.c);
}
#endif

#ifndef skip_Finish
void Finish() {
    
printf(gl.c);
}
#endif

#ifndef skip_FinishAsyncSGIX
Int32 FinishAsyncSGIX(GLuint markerp) {
    
printf(gl.c);
}
#endif

#ifndef skip_FinishFenceAPPLE
void FinishFenceAPPLE(GLuint fence) {
    
printf(gl.c);
}
#endif

#ifndef skip_FinishFenceNV
void FinishFenceNV(GLuint fence) {
    
printf(gl.c);
}
#endif

#ifndef skip_FinishObjectAPPLE
void FinishObjectAPPLE(GLenum object, GLint name) {
    
printf(gl.c);
}
#endif

#ifndef skip_FinishTextureSUNX
void FinishTextureSUNX() {
    
printf(gl.c);
}
#endif

#ifndef skip_Flush
void Flush() {
    
printf(gl.c);
}
#endif

#ifndef skip_FlushMappedBufferRange
void FlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) {
    
printf(gl.c);
}
#endif

#ifndef skip_FlushMappedBufferRangeAPPLE
void FlushMappedBufferRangeAPPLE(GLenum target, GLintptr offset, GLsizeiptr size) {
    
printf(gl.c);
}
#endif

#ifndef skip_FlushMappedNamedBufferRangeEXT
void FlushMappedNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length) {
    
printf(gl.c);
}
#endif

#ifndef skip_FlushPixelDataRangeNV
void FlushPixelDataRangeNV(GLenum target) {
    
printf(gl.c);
}
#endif

#ifndef skip_FlushRasterSGIX
void FlushRasterSGIX() {
    
printf(gl.c);
}
#endif

#ifndef skip_FlushStaticDataIBM
void FlushStaticDataIBM(GLenum target) {
    
printf(gl.c);
}
#endif

#ifndef skip_FlushVertexArrayRangeAPPLE
void FlushVertexArrayRangeAPPLE(GLsizei length, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_FlushVertexArrayRangeNV
void FlushVertexArrayRangeNV() {
    
printf(gl.c);
}
#endif

#ifndef skip_FogCoordFormatNV
void FogCoordFormatNV(GLenum type, GLsizei stride) {
    
printf(gl.c);
}
#endif

#ifndef skip_FogCoordPointer
void FogCoordPointer(GLenum type, GLsizei stride, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_FogCoordPointerEXT
void FogCoordPointerEXT(GLenum type, GLsizei stride, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_FogCoordPointerListIBM
void FogCoordPointerListIBM(GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride) {
    
printf(gl.c);
}
#endif

#ifndef skip_FogCoordd
void FogCoordd(GLdouble coord) {
    
printf(gl.c);
}
#endif

#ifndef skip_FogCoorddEXT
void FogCoorddEXT(GLdouble coord) {
    
printf(gl.c);
}
#endif

#ifndef skip_FogCoorddv
void FogCoorddv(GLdouble coord) {
    
printf(gl.c);
}
#endif

#ifndef skip_FogCoorddvEXT
void FogCoorddvEXT(GLdouble coord) {
    
printf(gl.c);
}
#endif

#ifndef skip_FogCoordf
void FogCoordf(GLfloat coord) {
    
printf(gl.c);
}
#endif

#ifndef skip_FogCoordfEXT
void FogCoordfEXT(GLfloat coord) {
    
printf(gl.c);
}
#endif

#ifndef skip_FogCoordfv
void FogCoordfv(GLfloat coord) {
    
printf(gl.c);
}
#endif

#ifndef skip_FogCoordfvEXT
void FogCoordfvEXT(GLfloat coord) {
    
printf(gl.c);
}
#endif

#ifndef skip_FogCoordhNV
void FogCoordhNV(GLhalfNV fog) {
    
printf(gl.c);
}
#endif

#ifndef skip_FogCoordhvNV
void FogCoordhvNV(GLhalfNV fog) {
    
printf(gl.c);
}
#endif

#ifndef skip_FogFuncSGIS
void FogFuncSGIS(GLsizei n, GLfloat points) {
    
printf(gl.c);
}
#endif

#ifndef skip_Fogf
void Fogf(GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_Fogfv
void Fogfv(GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_Fogi
void Fogi(GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_Fogiv
void Fogiv(GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_FogxOES
void FogxOES(GLenum pname, GLfixed param) {
    
printf(gl.c);
}
#endif

#ifndef skip_FogxvOES
void FogxvOES(GLenum pname, GLfixed param) {
    
printf(gl.c);
}
#endif

#ifndef skip_FragmentColorMaterialSGIX
void FragmentColorMaterialSGIX(GLenum face, GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_FragmentLightModelfSGIX
void FragmentLightModelfSGIX(GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_FragmentLightModelfvSGIX
void FragmentLightModelfvSGIX(GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_FragmentLightModeliSGIX
void FragmentLightModeliSGIX(GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_FragmentLightModelivSGIX
void FragmentLightModelivSGIX(GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_FragmentLightfSGIX
void FragmentLightfSGIX(GLenum light, GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_FragmentLightfvSGIX
void FragmentLightfvSGIX(GLenum light, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_FragmentLightiSGIX
void FragmentLightiSGIX(GLenum light, GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_FragmentLightivSGIX
void FragmentLightivSGIX(GLenum light, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_FragmentMaterialfSGIX
void FragmentMaterialfSGIX(GLenum face, GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_FragmentMaterialfvSGIX
void FragmentMaterialfvSGIX(GLenum face, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_FragmentMaterialiSGIX
void FragmentMaterialiSGIX(GLenum face, GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_FragmentMaterialivSGIX
void FragmentMaterialivSGIX(GLenum face, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_FrameTerminatorGREMEDY
void FrameTerminatorGREMEDY() {
    
printf(gl.c);
}
#endif

#ifndef skip_FrameZoomSGIX
void FrameZoomSGIX(GLint factor) {
    
printf(gl.c);
}
#endif

#ifndef skip_FramebufferDrawBufferEXT
void FramebufferDrawBufferEXT(GLuint framebuffer, GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_FramebufferDrawBuffersEXT
void FramebufferDrawBuffersEXT(GLuint framebuffer, GLsizei n, GLenum bufs) {
    
printf(gl.c);
}
#endif

#ifndef skip_FramebufferParameteri
void FramebufferParameteri(GLenum target, GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_FramebufferReadBufferEXT
void FramebufferReadBufferEXT(GLuint framebuffer, GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_FramebufferRenderbuffer
void FramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_FramebufferRenderbufferEXT
void FramebufferRenderbufferEXT(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_FramebufferTexture
void FramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) {
    
printf(gl.c);
}
#endif

#ifndef skip_FramebufferTexture1D
void FramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
    
printf(gl.c);
}
#endif

#ifndef skip_FramebufferTexture1DEXT
void FramebufferTexture1DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
    
printf(gl.c);
}
#endif

#ifndef skip_FramebufferTexture2D
void FramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
    
printf(gl.c);
}
#endif

#ifndef skip_FramebufferTexture2DEXT
void FramebufferTexture2DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
    
printf(gl.c);
}
#endif

#ifndef skip_FramebufferTexture3D
void FramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) {
    
printf(gl.c);
}
#endif

#ifndef skip_FramebufferTexture3DEXT
void FramebufferTexture3DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) {
    
printf(gl.c);
}
#endif

#ifndef skip_FramebufferTextureARB
void FramebufferTextureARB(GLenum target, GLenum attachment, GLuint texture, GLint level) {
    
printf(gl.c);
}
#endif

#ifndef skip_FramebufferTextureEXT
void FramebufferTextureEXT(GLenum target, GLenum attachment, GLuint texture, GLint level) {
    
printf(gl.c);
}
#endif

#ifndef skip_FramebufferTextureFaceARB
void FramebufferTextureFaceARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face) {
    
printf(gl.c);
}
#endif

#ifndef skip_FramebufferTextureFaceEXT
void FramebufferTextureFaceEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face) {
    
printf(gl.c);
}
#endif

#ifndef skip_FramebufferTextureLayer
void FramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
    
printf(gl.c);
}
#endif

#ifndef skip_FramebufferTextureLayerARB
void FramebufferTextureLayerARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
    
printf(gl.c);
}
#endif

#ifndef skip_FramebufferTextureLayerEXT
void FramebufferTextureLayerEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
    
printf(gl.c);
}
#endif

#ifndef skip_FreeObjectBufferATI
void FreeObjectBufferATI(GLuint buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_FrontFace
void FrontFace(GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_Frustum
void Frustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
    
printf(gl.c);
}
#endif

#ifndef skip_FrustumfOES
void FrustumfOES(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f) {
    
printf(gl.c);
}
#endif

#ifndef skip_FrustumxOES
void FrustumxOES(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenAsyncMarkersSGIX
UInt32 GenAsyncMarkersSGIX(GLsizei range) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenBuffers
void GenBuffers(GLsizei n, GLuint buffers) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenBuffersARB
void GenBuffersARB(GLsizei n, GLuint buffers) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenFencesAPPLE
void GenFencesAPPLE(GLsizei n, GLuint fences) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenFencesNV
void GenFencesNV(GLsizei n, GLuint fences) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenFragmentShadersATI
UInt32 GenFragmentShadersATI(GLuint range) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenFramebuffers
void GenFramebuffers(GLsizei n, GLuint framebuffers) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenFramebuffersEXT
void GenFramebuffersEXT(GLsizei n, GLuint framebuffers) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenLists
List GenLists(GLsizei range) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenNamesAMD
void GenNamesAMD(GLenum identifier, GLuint num, GLuint names) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenOcclusionQueriesNV
void GenOcclusionQueriesNV(GLsizei n, GLuint ids) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenPathsNV
Path GenPathsNV(GLsizei range) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenPerfMonitorsAMD
void GenPerfMonitorsAMD(GLsizei n, GLuint monitors) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenProgramPipelines
void GenProgramPipelines(GLsizei n, GLuint pipelines) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenProgramsARB
void GenProgramsARB(GLsizei n, GLuint programs) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenProgramsNV
void GenProgramsNV(GLsizei n, GLuint programs) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenQueries
void GenQueries(GLsizei n, GLuint ids) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenQueriesARB
void GenQueriesARB(GLsizei n, GLuint ids) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenRenderbuffers
void GenRenderbuffers(GLsizei n, GLuint renderbuffers) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenRenderbuffersEXT
void GenRenderbuffersEXT(GLsizei n, GLuint renderbuffers) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenSamplers
void GenSamplers(GLsizei count, GLuint samplers) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenSymbolsEXT
UInt32 GenSymbolsEXT(GLenum datatype, GLenum storagetype, GLenum range, GLuint components) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenTextures
void GenTextures(GLsizei n, GLuint textures) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenTexturesEXT
void GenTexturesEXT(GLsizei n, GLuint textures) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenTransformFeedbacks
void GenTransformFeedbacks(GLsizei n, GLuint ids) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenTransformFeedbacksNV
void GenTransformFeedbacksNV(GLsizei n, GLuint ids) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenVertexArrays
void GenVertexArrays(GLsizei n, GLuint arrays) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenVertexArraysAPPLE
void GenVertexArraysAPPLE(GLsizei n, GLuint arrays) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenVertexShadersEXT
UInt32 GenVertexShadersEXT(GLuint range) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenerateMipmap
void GenerateMipmap(GLenum target) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenerateMipmapEXT
void GenerateMipmapEXT(GLenum target) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenerateMultiTexMipmapEXT
void GenerateMultiTexMipmapEXT(GLenum texunit, GLenum target) {
    
printf(gl.c);
}
#endif

#ifndef skip_GenerateTextureMipmapEXT
void GenerateTextureMipmapEXT(GLuint texture, GLenum target) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetActiveAtomicCounterBufferiv
void GetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetActiveAttrib
void GetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLint size, GLenum type, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetActiveAttribARB
void GetActiveAttribARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei length, GLint size, GLenum type, GLcharARB name) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetActiveSubroutineName
void GetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei length, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetActiveSubroutineUniformName
void GetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei length, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetActiveSubroutineUniformiv
void GetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint values) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetActiveUniform
void GetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLint size, GLenum type, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetActiveUniformARB
void GetActiveUniformARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei length, GLint size, GLenum type, GLcharARB name) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetActiveUniformBlockName
void GetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei length, GLchar uniformBlockName) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetActiveUniformBlockiv
void GetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetActiveUniformName
void GetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei length, GLchar uniformName) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetActiveUniformsiv
void GetActiveUniformsiv(GLuint program, GLsizei uniformCount, GLuint uniformIndices, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetActiveVaryingNV
void GetActiveVaryingNV(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLsizei size, GLenum type, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetArrayObjectfvATI
void GetArrayObjectfvATI(GLenum array, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetArrayObjectivATI
void GetArrayObjectivATI(GLenum array, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetAttachedObjectsARB
void GetAttachedObjectsARB(GLhandleARB containerObj, GLsizei maxCount, GLsizei count, GLhandleARB obj) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetAttachedShaders
void GetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei count, GLuint obj) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetAttribLocation
Int32 GetAttribLocation(GLuint program, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetAttribLocationARB
Int32 GetAttribLocationARB(GLhandleARB programObj, GLcharARB name) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetBooleanIndexedvEXT
void GetBooleanIndexedvEXT(GLenum target, GLuint index, GLboolean data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetBooleani_v
void GetBooleani_v(GLenum target, GLuint index, GLboolean data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetBooleanv
void GetBooleanv(GLenum pname, GLboolean params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetBufferParameteri64v
void GetBufferParameteri64v(GLenum target, GLenum pname, GLint64 params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetBufferParameteriv
void GetBufferParameteriv(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetBufferParameterivARB
void GetBufferParameterivARB(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetBufferParameterui64vNV
void GetBufferParameterui64vNV(GLenum target, GLenum pname, GLuint64EXT params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetBufferPointerv
void GetBufferPointerv(GLenum target, GLenum pname, GLvoid * params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetBufferPointervARB
void GetBufferPointervARB(GLenum target, GLenum pname, GLvoid * params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetBufferSubData
void GetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetBufferSubDataARB
void GetBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetClipPlane
void GetClipPlane(GLenum plane, GLdouble equation) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetClipPlanefOES
void GetClipPlanefOES(GLenum plane, GLfloat equation) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetClipPlanexOES
void GetClipPlanexOES(GLenum plane, GLfixed equation) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetColorTable
void GetColorTable(GLenum target, GLenum format, GLenum type, GLvoid table) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetColorTableEXT
void GetColorTableEXT(GLenum target, GLenum format, GLenum type, GLvoid data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetColorTableParameterfv
void GetColorTableParameterfv(GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetColorTableParameterfvEXT
void GetColorTableParameterfvEXT(GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetColorTableParameterfvSGI
void GetColorTableParameterfvSGI(GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetColorTableParameteriv
void GetColorTableParameteriv(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetColorTableParameterivEXT
void GetColorTableParameterivEXT(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetColorTableParameterivSGI
void GetColorTableParameterivSGI(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetColorTableSGI
void GetColorTableSGI(GLenum target, GLenum format, GLenum type, GLvoid table) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetCombinerInputParameterfvNV
void GetCombinerInputParameterfvNV(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetCombinerInputParameterivNV
void GetCombinerInputParameterivNV(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetCombinerOutputParameterfvNV
void GetCombinerOutputParameterfvNV(GLenum stage, GLenum portion, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetCombinerOutputParameterivNV
void GetCombinerOutputParameterivNV(GLenum stage, GLenum portion, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetCombinerStageParameterfvNV
void GetCombinerStageParameterfvNV(GLenum stage, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetCompressedMultiTexImageEXT
void GetCompressedMultiTexImageEXT(GLenum texunit, GLenum target, GLint lod, GLvoid img) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetCompressedTexImage
void GetCompressedTexImage(GLenum target, GLint level, GLvoid img) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetCompressedTexImageARB
void GetCompressedTexImageARB(GLenum target, GLint level, GLvoid img) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetCompressedTextureImageEXT
void GetCompressedTextureImageEXT(GLuint texture, GLenum target, GLint lod, GLvoid img) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetConvolutionFilter
void GetConvolutionFilter(GLenum target, GLenum format, GLenum type, GLvoid image) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetConvolutionFilterEXT
void GetConvolutionFilterEXT(GLenum target, GLenum format, GLenum type, GLvoid image) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetConvolutionParameterfv
void GetConvolutionParameterfv(GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetConvolutionParameterfvEXT
void GetConvolutionParameterfvEXT(GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetConvolutionParameteriv
void GetConvolutionParameteriv(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetConvolutionParameterivEXT
void GetConvolutionParameterivEXT(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetConvolutionParameterxvOES
void GetConvolutionParameterxvOES(GLenum target, GLenum pname, GLfixed params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetDebugMessageLog
UInt32 GetDebugMessageLog(GLuint count, GLsizei bufsize, GLenum sources, GLenum types, GLuint ids, GLenum severities, GLsizei lengths, GLchar messageLog) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetDebugMessageLogAMD
UInt32 GetDebugMessageLogAMD(GLuint count, GLsizei bufsize, GLenum categories, GLuint severities, GLuint ids, GLsizei lengths, GLchar message) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetDebugMessageLogARB
UInt32 GetDebugMessageLogARB(GLuint count, GLsizei bufsize, GLenum sources, GLenum types, GLuint ids, GLenum severities, GLsizei lengths, GLchar messageLog) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetDetailTexFuncSGIS
void GetDetailTexFuncSGIS(GLenum target, GLfloat points) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetDoubleIndexedvEXT
void GetDoubleIndexedvEXT(GLenum target, GLuint index, GLdouble data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetDoublei_v
void GetDoublei_v(GLenum target, GLuint index, GLdouble data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetDoublei_vEXT
void GetDoublei_vEXT(GLenum target, GLuint index, GLdouble data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetDoublev
void GetDoublev(GLenum pname, GLdouble params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetError
ErrorCode GetError() {
    
printf(gl.c);
}
#endif

#ifndef skip_GetFenceivNV
void GetFenceivNV(GLuint fence, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetFinalCombinerInputParameterfvNV
void GetFinalCombinerInputParameterfvNV(GLenum variable, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetFinalCombinerInputParameterivNV
void GetFinalCombinerInputParameterivNV(GLenum variable, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetFixedvOES
void GetFixedvOES(GLenum pname, GLfixed params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetFloatIndexedvEXT
void GetFloatIndexedvEXT(GLenum target, GLuint index, GLfloat data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetFloati_v
void GetFloati_v(GLenum target, GLuint index, GLfloat data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetFloati_vEXT
void GetFloati_vEXT(GLenum target, GLuint index, GLfloat data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetFloatv
void GetFloatv(GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetFogFuncSGIS
void GetFogFuncSGIS(GLfloat points) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetFragDataIndex
Int32 GetFragDataIndex(GLuint program, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetFragDataLocation
Int32 GetFragDataLocation(GLuint program, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetFragDataLocationEXT
Int32 GetFragDataLocationEXT(GLuint program, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetFragmentLightfvSGIX
void GetFragmentLightfvSGIX(GLenum light, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetFragmentLightivSGIX
void GetFragmentLightivSGIX(GLenum light, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetFragmentMaterialfvSGIX
void GetFragmentMaterialfvSGIX(GLenum face, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetFragmentMaterialivSGIX
void GetFragmentMaterialivSGIX(GLenum face, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetFramebufferAttachmentParameteriv
void GetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetFramebufferAttachmentParameterivEXT
void GetFramebufferAttachmentParameterivEXT(GLenum target, GLenum attachment, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetFramebufferParameteriv
void GetFramebufferParameteriv(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetFramebufferParameterivEXT
void GetFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetGraphicsResetStatusARB
GLenum GetGraphicsResetStatusARB() {
    
printf(gl.c);
}
#endif

#ifndef skip_GetHandleARB
handleARB GetHandleARB(GLenum pname) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetHistogram
void GetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid values) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetHistogramEXT
void GetHistogramEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid values) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetHistogramParameterfv
void GetHistogramParameterfv(GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetHistogramParameterfvEXT
void GetHistogramParameterfvEXT(GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetHistogramParameteriv
void GetHistogramParameteriv(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetHistogramParameterivEXT
void GetHistogramParameterivEXT(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetHistogramParameterxvOES
void GetHistogramParameterxvOES(GLenum target, GLenum pname, GLfixed params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetImageHandleNV
UInt64 GetImageHandleNV(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetImageTransformParameterfvHP
void GetImageTransformParameterfvHP(GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetImageTransformParameterivHP
void GetImageTransformParameterivHP(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetInfoLogARB
void GetInfoLogARB(GLhandleARB obj, GLsizei maxLength, GLsizei length, GLcharARB infoLog) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetInstrumentsSGIX
Int32 GetInstrumentsSGIX() {
    
printf(gl.c);
}
#endif

#ifndef skip_GetInteger64i_v
void GetInteger64i_v(GLenum target, GLuint index, GLint64 data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetInteger64v
void GetInteger64v(GLenum pname, GLint64 params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetIntegerIndexedvEXT
void GetIntegerIndexedvEXT(GLenum target, GLuint index, GLint data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetIntegeri_v
void GetIntegeri_v(GLenum target, GLuint index, GLint data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetIntegerui64i_vNV
void GetIntegerui64i_vNV(GLenum value, GLuint index, GLuint64EXT result) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetIntegerui64vNV
void GetIntegerui64vNV(GLenum value, GLuint64EXT result) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetIntegerv
void GetIntegerv(GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetInternalformati64v
void GetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetInternalformativ
void GetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetInvariantBooleanvEXT
void GetInvariantBooleanvEXT(GLuint id, GLenum value, GLboolean data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetInvariantFloatvEXT
void GetInvariantFloatvEXT(GLuint id, GLenum value, GLfloat data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetInvariantIntegervEXT
void GetInvariantIntegervEXT(GLuint id, GLenum value, GLint data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetLightfv
void GetLightfv(GLenum light, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetLightiv
void GetLightiv(GLenum light, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetLightxOES
void GetLightxOES(GLenum light, GLenum pname, GLfixed params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetListParameterfvSGIX
void GetListParameterfvSGIX(GLuint list, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetListParameterivSGIX
void GetListParameterivSGIX(GLuint list, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetLocalConstantBooleanvEXT
void GetLocalConstantBooleanvEXT(GLuint id, GLenum value, GLboolean data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetLocalConstantFloatvEXT
void GetLocalConstantFloatvEXT(GLuint id, GLenum value, GLfloat data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetLocalConstantIntegervEXT
void GetLocalConstantIntegervEXT(GLuint id, GLenum value, GLint data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMapAttribParameterfvNV
void GetMapAttribParameterfvNV(GLenum target, GLuint index, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMapAttribParameterivNV
void GetMapAttribParameterivNV(GLenum target, GLuint index, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMapControlPointsNV
void GetMapControlPointsNV(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLboolean packed, GLvoid points) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMapParameterfvNV
void GetMapParameterfvNV(GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMapParameterivNV
void GetMapParameterivNV(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMapdv
void GetMapdv(GLenum target, GLenum query, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMapfv
void GetMapfv(GLenum target, GLenum query, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMapiv
void GetMapiv(GLenum target, GLenum query, GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMapxvOES
void GetMapxvOES(GLenum target, GLenum query, GLfixed v) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMaterialfv
void GetMaterialfv(GLenum face, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMaterialiv
void GetMaterialiv(GLenum face, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMaterialxOES
void GetMaterialxOES(GLenum face, GLenum pname, GLfixed param) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMinmax
void GetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid values) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMinmaxEXT
void GetMinmaxEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid values) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMinmaxParameterfv
void GetMinmaxParameterfv(GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMinmaxParameterfvEXT
void GetMinmaxParameterfvEXT(GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMinmaxParameteriv
void GetMinmaxParameteriv(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMinmaxParameterivEXT
void GetMinmaxParameterivEXT(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMultiTexEnvfvEXT
void GetMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMultiTexEnvivEXT
void GetMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMultiTexGendvEXT
void GetMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMultiTexGenfvEXT
void GetMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMultiTexGenivEXT
void GetMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMultiTexImageEXT
void GetMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMultiTexLevelParameterfvEXT
void GetMultiTexLevelParameterfvEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMultiTexLevelParameterivEXT
void GetMultiTexLevelParameterivEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMultiTexParameterIivEXT
void GetMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMultiTexParameterIuivEXT
void GetMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMultiTexParameterfvEXT
void GetMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMultiTexParameterivEXT
void GetMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMultisamplefv
void GetMultisamplefv(GLenum pname, GLuint index, GLfloat val) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMultisamplefvNV
void GetMultisamplefvNV(GLenum pname, GLuint index, GLfloat val) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetNamedBufferParameterivEXT
void GetNamedBufferParameterivEXT(GLuint buffer, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetNamedBufferParameterui64vNV
void GetNamedBufferParameterui64vNV(GLuint buffer, GLenum pname, GLuint64EXT params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetNamedBufferPointervEXT
void GetNamedBufferPointervEXT(GLuint buffer, GLenum pname, GLvoid * params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetNamedBufferSubDataEXT
void GetNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetNamedFramebufferAttachmentParameterivEXT
void GetNamedFramebufferAttachmentParameterivEXT(GLuint framebuffer, GLenum attachment, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetNamedFramebufferParameterivEXT
void GetNamedFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetNamedProgramLocalParameterIivEXT
void GetNamedProgramLocalParameterIivEXT(GLuint program, GLenum target, GLuint index, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetNamedProgramLocalParameterIuivEXT
void GetNamedProgramLocalParameterIuivEXT(GLuint program, GLenum target, GLuint index, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetNamedProgramLocalParameterdvEXT
void GetNamedProgramLocalParameterdvEXT(GLuint program, GLenum target, GLuint index, GLdouble params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetNamedProgramLocalParameterfvEXT
void GetNamedProgramLocalParameterfvEXT(GLuint program, GLenum target, GLuint index, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetNamedProgramStringEXT
void GetNamedProgramStringEXT(GLuint program, GLenum target, GLenum pname, GLvoid string) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetNamedProgramivEXT
void GetNamedProgramivEXT(GLuint program, GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetNamedRenderbufferParameterivEXT
void GetNamedRenderbufferParameterivEXT(GLuint renderbuffer, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetNamedStringARB
void GetNamedStringARB(GLint namelen, GLchar name, GLsizei bufSize, GLint stringlen, GLchar string) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetNamedStringivARB
void GetNamedStringivARB(GLint namelen, GLchar name, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetObjectBufferfvATI
void GetObjectBufferfvATI(GLuint buffer, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetObjectBufferivATI
void GetObjectBufferivATI(GLuint buffer, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetObjectLabel
void GetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei length, GLchar label) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetObjectParameterfvARB
void GetObjectParameterfvARB(GLhandleARB obj, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetObjectParameterivAPPLE
void GetObjectParameterivAPPLE(GLenum objectType, GLuint name, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetObjectParameterivARB
void GetObjectParameterivARB(GLhandleARB obj, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetObjectPtrLabel
void GetObjectPtrLabel(void * ptr, GLsizei bufSize, GLsizei length, GLchar label) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetOcclusionQueryivNV
void GetOcclusionQueryivNV(GLuint id, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetOcclusionQueryuivNV
void GetOcclusionQueryuivNV(GLuint id, GLenum pname, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPathColorGenfvNV
void GetPathColorGenfvNV(GLenum color, GLenum pname, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPathColorGenivNV
void GetPathColorGenivNV(GLenum color, GLenum pname, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPathCommandsNV
void GetPathCommandsNV(GLuint path, GLubyte commands) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPathCoordsNV
void GetPathCoordsNV(GLuint path, GLfloat coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPathDashArrayNV
void GetPathDashArrayNV(GLuint path, GLfloat dashArray) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPathLengthNV
Float32 GetPathLengthNV(GLuint path, GLsizei startSegment, GLsizei numSegments) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPathMetricRangeNV
void GetPathMetricRangeNV(GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat metrics) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPathMetricsNV
void GetPathMetricsNV(GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLsizei stride, GLfloat metrics) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPathParameterfvNV
void GetPathParameterfvNV(GLuint path, GLenum pname, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPathParameterivNV
void GetPathParameterivNV(GLuint path, GLenum pname, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPathSpacingNV
void GetPathSpacingNV(GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat returnedSpacing) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPathTexGenfvNV
void GetPathTexGenfvNV(GLenum texCoordSet, GLenum pname, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPathTexGenivNV
void GetPathTexGenivNV(GLenum texCoordSet, GLenum pname, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPerfMonitorCounterDataAMD
void GetPerfMonitorCounterDataAMD(GLuint monitor, GLenum pname, GLsizei dataSize, GLuint data, GLint bytesWritten) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPerfMonitorCounterInfoAMD
void GetPerfMonitorCounterInfoAMD(GLuint group, GLuint counter, GLenum pname, GLvoid data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPerfMonitorCounterStringAMD
void GetPerfMonitorCounterStringAMD(GLuint group, GLuint counter, GLsizei bufSize, GLsizei length, GLchar counterString) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPerfMonitorCountersAMD
void GetPerfMonitorCountersAMD(GLuint group, GLint numCounters, GLint maxActiveCounters, GLsizei counterSize, GLuint counters) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPerfMonitorGroupStringAMD
void GetPerfMonitorGroupStringAMD(GLuint group, GLsizei bufSize, GLsizei length, GLchar groupString) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPerfMonitorGroupsAMD
void GetPerfMonitorGroupsAMD(GLint numGroups, GLsizei groupsSize, GLuint groups) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPixelMapfv
void GetPixelMapfv(GLenum map, GLfloat values) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPixelMapuiv
void GetPixelMapuiv(GLenum map, GLuint values) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPixelMapusv
void GetPixelMapusv(GLenum map, GLushort values) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPixelMapxv
void GetPixelMapxv(GLenum map, GLint size, GLfixed values) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPixelTexGenParameterfvSGIS
void GetPixelTexGenParameterfvSGIS(GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPixelTexGenParameterivSGIS
void GetPixelTexGenParameterivSGIS(GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPixelTransformParameterfvEXT
void GetPixelTransformParameterfvEXT(GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPixelTransformParameterivEXT
void GetPixelTransformParameterivEXT(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPointerIndexedvEXT
void GetPointerIndexedvEXT(GLenum target, GLuint index, GLvoid * data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPointeri_vEXT
void GetPointeri_vEXT(GLenum target, GLuint index, GLvoid * data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPointerv
void GetPointerv(GLenum pname, GLvoid * params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPointervEXT
void GetPointervEXT(GLenum pname, GLvoid * params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetPolygonStipple
void GetPolygonStipple(GLubyte mask) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramBinary
void GetProgramBinary(GLuint program, GLsizei bufSize, GLsizei length, GLenum binaryFormat, GLvoid binary) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramEnvParameterIivNV
void GetProgramEnvParameterIivNV(GLenum target, GLuint index, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramEnvParameterIuivNV
void GetProgramEnvParameterIuivNV(GLenum target, GLuint index, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramEnvParameterdvARB
void GetProgramEnvParameterdvARB(GLenum target, GLuint index, GLdouble params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramEnvParameterfvARB
void GetProgramEnvParameterfvARB(GLenum target, GLuint index, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramInfoLog
void GetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei length, GLchar infoLog) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramInterfaceiv
void GetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramLocalParameterIivNV
void GetProgramLocalParameterIivNV(GLenum target, GLuint index, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramLocalParameterIuivNV
void GetProgramLocalParameterIuivNV(GLenum target, GLuint index, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramLocalParameterdvARB
void GetProgramLocalParameterdvARB(GLenum target, GLuint index, GLdouble params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramLocalParameterfvARB
void GetProgramLocalParameterfvARB(GLenum target, GLuint index, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramNamedParameterdvNV
void GetProgramNamedParameterdvNV(GLuint id, GLsizei len, GLubyte name, GLdouble params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramNamedParameterfvNV
void GetProgramNamedParameterfvNV(GLuint id, GLsizei len, GLubyte name, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramParameterdvNV
void GetProgramParameterdvNV(GLenum target, GLuint index, GLenum pname, GLdouble params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramParameterfvNV
void GetProgramParameterfvNV(GLenum target, GLuint index, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramPipelineInfoLog
void GetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei length, GLchar infoLog) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramPipelineiv
void GetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramResourceIndex
UInt32 GetProgramResourceIndex(GLuint program, GLenum programInterface, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramResourceLocation
Int32 GetProgramResourceLocation(GLuint program, GLenum programInterface, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramResourceLocationIndex
Int32 GetProgramResourceLocationIndex(GLuint program, GLenum programInterface, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramResourceName
void GetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei length, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramResourceiv
void GetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, GLenum props, GLsizei bufSize, GLsizei length, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramStageiv
void GetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint values) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramStringARB
void GetProgramStringARB(GLenum target, GLenum pname, GLvoid string) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramStringNV
void GetProgramStringNV(GLuint id, GLenum pname, GLubyte program) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramSubroutineParameteruivNV
void GetProgramSubroutineParameteruivNV(GLenum target, GLuint index, GLuint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramiv
void GetProgramiv(GLuint program, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramivARB
void GetProgramivARB(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProgramivNV
void GetProgramivNV(GLuint id, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetQueryIndexediv
void GetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetQueryObjecti64v
void GetQueryObjecti64v(GLuint id, GLenum pname, GLint64 params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetQueryObjecti64vEXT
void GetQueryObjecti64vEXT(GLuint id, GLenum pname, GLint64EXT params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetQueryObjectiv
void GetQueryObjectiv(GLuint id, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetQueryObjectivARB
void GetQueryObjectivARB(GLuint id, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetQueryObjectui64v
void GetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetQueryObjectui64vEXT
void GetQueryObjectui64vEXT(GLuint id, GLenum pname, GLuint64EXT params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetQueryObjectuiv
void GetQueryObjectuiv(GLuint id, GLenum pname, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetQueryObjectuivARB
void GetQueryObjectuivARB(GLuint id, GLenum pname, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetQueryiv
void GetQueryiv(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetQueryivARB
void GetQueryivARB(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetRenderbufferParameteriv
void GetRenderbufferParameteriv(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetRenderbufferParameterivEXT
void GetRenderbufferParameterivEXT(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetSamplerParameterIiv
void GetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetSamplerParameterIuiv
void GetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetSamplerParameterfv
void GetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetSamplerParameteriv
void GetSamplerParameteriv(GLuint sampler, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetSeparableFilter
void GetSeparableFilter(GLenum target, GLenum format, GLenum type, GLvoid row, GLvoid column, GLvoid span) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetSeparableFilterEXT
void GetSeparableFilterEXT(GLenum target, GLenum format, GLenum type, GLvoid row, GLvoid column, GLvoid span) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetShaderInfoLog
void GetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei length, GLchar infoLog) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetShaderPrecisionFormat
void GetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint range, GLint precision) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetShaderSource
void GetShaderSource(GLuint shader, GLsizei bufSize, GLsizei length, GLchar source) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetShaderSourceARB
void GetShaderSourceARB(GLhandleARB obj, GLsizei maxLength, GLsizei length, GLcharARB source) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetShaderiv
void GetShaderiv(GLuint shader, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetSharpenTexFuncSGIS
void GetSharpenTexFuncSGIS(GLenum target, GLfloat points) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetString
String GetString(GLenum name) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetStringi
String GetStringi(GLenum name, GLuint index) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetSubroutineIndex
UInt32 GetSubroutineIndex(GLuint program, GLenum shadertype, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetSubroutineUniformLocation
Int32 GetSubroutineUniformLocation(GLuint program, GLenum shadertype, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetSynciv
void GetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei length, GLint values) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTexBumpParameterfvATI
void GetTexBumpParameterfvATI(GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTexBumpParameterivATI
void GetTexBumpParameterivATI(GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTexEnvfv
void GetTexEnvfv(GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTexEnviv
void GetTexEnviv(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTexEnvxvOES
void GetTexEnvxvOES(GLenum target, GLenum pname, GLfixed params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTexFilterFuncSGIS
void GetTexFilterFuncSGIS(GLenum target, GLenum filter, GLfloat weights) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTexGendv
void GetTexGendv(GLenum coord, GLenum pname, GLdouble params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTexGenfv
void GetTexGenfv(GLenum coord, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTexGeniv
void GetTexGeniv(GLenum coord, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTexGenxvOES
void GetTexGenxvOES(GLenum coord, GLenum pname, GLfixed params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTexImage
void GetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTexLevelParameterfv
void GetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTexLevelParameteriv
void GetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTexLevelParameterxvOES
void GetTexLevelParameterxvOES(GLenum target, GLint level, GLenum pname, GLfixed params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTexParameterIiv
void GetTexParameterIiv(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTexParameterIivEXT
void GetTexParameterIivEXT(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTexParameterIuiv
void GetTexParameterIuiv(GLenum target, GLenum pname, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTexParameterIuivEXT
void GetTexParameterIuivEXT(GLenum target, GLenum pname, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTexParameterPointervAPPLE
void GetTexParameterPointervAPPLE(GLenum target, GLenum pname, GLvoid * params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTexParameterfv
void GetTexParameterfv(GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTexParameteriv
void GetTexParameteriv(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTexParameterxvOES
void GetTexParameterxvOES(GLenum target, GLenum pname, GLfixed params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTextureHandleNV
UInt64 GetTextureHandleNV(GLuint texture) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTextureImageEXT
void GetTextureImageEXT(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTextureLevelParameterfvEXT
void GetTextureLevelParameterfvEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTextureLevelParameterivEXT
void GetTextureLevelParameterivEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTextureParameterIivEXT
void GetTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTextureParameterIuivEXT
void GetTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTextureParameterfvEXT
void GetTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTextureParameterivEXT
void GetTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTextureSamplerHandleNV
UInt64 GetTextureSamplerHandleNV(GLuint texture, GLuint sampler) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTrackMatrixivNV
void GetTrackMatrixivNV(GLenum target, GLuint address, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTransformFeedbackVarying
void GetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLsizei size, GLenum type, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTransformFeedbackVaryingEXT
void GetTransformFeedbackVaryingEXT(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLsizei size, GLenum type, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTransformFeedbackVaryingNV
void GetTransformFeedbackVaryingNV(GLuint program, GLuint index, GLint location) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetUniformBlockIndex
UInt32 GetUniformBlockIndex(GLuint program, GLchar uniformBlockName) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetUniformBufferSizeEXT
Int32 GetUniformBufferSizeEXT(GLuint program, GLint location) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetUniformIndices
void GetUniformIndices(GLuint program, GLsizei uniformCount, GLchar*const uniformNames, GLuint uniformIndices) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetUniformLocation
Int32 GetUniformLocation(GLuint program, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetUniformLocationARB
Int32 GetUniformLocationARB(GLhandleARB programObj, GLcharARB name) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetUniformOffsetEXT
BufferOffset GetUniformOffsetEXT(GLuint program, GLint location) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetUniformSubroutineuiv
void GetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetUniformdv
void GetUniformdv(GLuint program, GLint location, GLdouble params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetUniformfv
void GetUniformfv(GLuint program, GLint location, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetUniformfvARB
void GetUniformfvARB(GLhandleARB programObj, GLint location, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetUniformi64vNV
void GetUniformi64vNV(GLuint program, GLint location, GLint64EXT params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetUniformiv
void GetUniformiv(GLuint program, GLint location, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetUniformivARB
void GetUniformivARB(GLhandleARB programObj, GLint location, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetUniformui64vNV
void GetUniformui64vNV(GLuint program, GLint location, GLuint64EXT params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetUniformuiv
void GetUniformuiv(GLuint program, GLint location, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetUniformuivEXT
void GetUniformuivEXT(GLuint program, GLint location, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVariantArrayObjectfvATI
void GetVariantArrayObjectfvATI(GLuint id, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVariantArrayObjectivATI
void GetVariantArrayObjectivATI(GLuint id, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVariantBooleanvEXT
void GetVariantBooleanvEXT(GLuint id, GLenum value, GLboolean data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVariantFloatvEXT
void GetVariantFloatvEXT(GLuint id, GLenum value, GLfloat data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVariantIntegervEXT
void GetVariantIntegervEXT(GLuint id, GLenum value, GLint data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVariantPointervEXT
void GetVariantPointervEXT(GLuint id, GLenum value, GLvoid * data) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVaryingLocationNV
Int32 GetVaryingLocationNV(GLuint program, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexArrayIntegeri_vEXT
void GetVertexArrayIntegeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexArrayIntegervEXT
void GetVertexArrayIntegervEXT(GLuint vaobj, GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexArrayPointeri_vEXT
void GetVertexArrayPointeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, GLvoid * param) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexArrayPointervEXT
void GetVertexArrayPointervEXT(GLuint vaobj, GLenum pname, GLvoid * param) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexAttribArrayObjectfvATI
void GetVertexAttribArrayObjectfvATI(GLuint index, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexAttribArrayObjectivATI
void GetVertexAttribArrayObjectivATI(GLuint index, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexAttribIiv
void GetVertexAttribIiv(GLuint index, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexAttribIivEXT
void GetVertexAttribIivEXT(GLuint index, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexAttribIuiv
void GetVertexAttribIuiv(GLuint index, GLenum pname, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexAttribIuivEXT
void GetVertexAttribIuivEXT(GLuint index, GLenum pname, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexAttribLdv
void GetVertexAttribLdv(GLuint index, GLenum pname, GLdouble params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexAttribLdvEXT
void GetVertexAttribLdvEXT(GLuint index, GLenum pname, GLdouble params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexAttribLi64vNV
void GetVertexAttribLi64vNV(GLuint index, GLenum pname, GLint64EXT params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexAttribLui64vNV
void GetVertexAttribLui64vNV(GLuint index, GLenum pname, GLuint64EXT params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexAttribPointerv
void GetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid * pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexAttribPointervARB
void GetVertexAttribPointervARB(GLuint index, GLenum pname, GLvoid * pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexAttribPointervNV
void GetVertexAttribPointervNV(GLuint index, GLenum pname, GLvoid * pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexAttribdv
void GetVertexAttribdv(GLuint index, GLenum pname, GLdouble params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexAttribdvARB
void GetVertexAttribdvARB(GLuint index, GLenum pname, GLdouble params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexAttribdvNV
void GetVertexAttribdvNV(GLuint index, GLenum pname, GLdouble params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexAttribfv
void GetVertexAttribfv(GLuint index, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexAttribfvARB
void GetVertexAttribfvARB(GLuint index, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexAttribfvNV
void GetVertexAttribfvNV(GLuint index, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexAttribiv
void GetVertexAttribiv(GLuint index, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexAttribivARB
void GetVertexAttribivARB(GLuint index, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVertexAttribivNV
void GetVertexAttribivNV(GLuint index, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVideoCaptureStreamdvNV
void GetVideoCaptureStreamdvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVideoCaptureStreamfvNV
void GetVideoCaptureStreamfvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVideoCaptureStreamivNV
void GetVideoCaptureStreamivNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVideoCaptureivNV
void GetVideoCaptureivNV(GLuint video_capture_slot, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVideoi64vNV
void GetVideoi64vNV(GLuint video_slot, GLenum pname, GLint64EXT params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVideoivNV
void GetVideoivNV(GLuint video_slot, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVideoui64vNV
void GetVideoui64vNV(GLuint video_slot, GLenum pname, GLuint64EXT params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVideouivNV
void GetVideouivNV(GLuint video_slot, GLenum pname, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetnColorTableARB
void GetnColorTableARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, GLvoid table) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetnCompressedTexImageARB
void GetnCompressedTexImageARB(GLenum target, GLint lod, GLsizei bufSize, GLvoid img) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetnConvolutionFilterARB
void GetnConvolutionFilterARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, GLvoid image) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetnHistogramARB
void GetnHistogramARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, GLvoid values) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetnMapdvARB
void GetnMapdvARB(GLenum target, GLenum query, GLsizei bufSize, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetnMapfvARB
void GetnMapfvARB(GLenum target, GLenum query, GLsizei bufSize, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetnMapivARB
void GetnMapivARB(GLenum target, GLenum query, GLsizei bufSize, GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetnMinmaxARB
void GetnMinmaxARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, GLvoid values) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetnPixelMapfvARB
void GetnPixelMapfvARB(GLenum map, GLsizei bufSize, GLfloat values) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetnPixelMapuivARB
void GetnPixelMapuivARB(GLenum map, GLsizei bufSize, GLuint values) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetnPixelMapusvARB
void GetnPixelMapusvARB(GLenum map, GLsizei bufSize, GLushort values) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetnPolygonStippleARB
void GetnPolygonStippleARB(GLsizei bufSize, GLubyte pattern) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetnSeparableFilterARB
void GetnSeparableFilterARB(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, GLvoid row, GLsizei columnBufSize, GLvoid column, GLvoid span) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetnTexImageARB
void GetnTexImageARB(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid img) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetnUniformdvARB
void GetnUniformdvARB(GLuint program, GLint location, GLsizei bufSize, GLdouble params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetnUniformfvARB
void GetnUniformfvARB(GLuint program, GLint location, GLsizei bufSize, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetnUniformivARB
void GetnUniformivARB(GLuint program, GLint location, GLsizei bufSize, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetnUniformuivARB
void GetnUniformuivARB(GLuint program, GLint location, GLsizei bufSize, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_GlobalAlphaFactorbSUN
void GlobalAlphaFactorbSUN(GLbyte factor) {
    
printf(gl.c);
}
#endif

#ifndef skip_GlobalAlphaFactordSUN
void GlobalAlphaFactordSUN(GLdouble factor) {
    
printf(gl.c);
}
#endif

#ifndef skip_GlobalAlphaFactorfSUN
void GlobalAlphaFactorfSUN(GLfloat factor) {
    
printf(gl.c);
}
#endif

#ifndef skip_GlobalAlphaFactoriSUN
void GlobalAlphaFactoriSUN(GLint factor) {
    
printf(gl.c);
}
#endif

#ifndef skip_GlobalAlphaFactorsSUN
void GlobalAlphaFactorsSUN(GLshort factor) {
    
printf(gl.c);
}
#endif

#ifndef skip_GlobalAlphaFactorubSUN
void GlobalAlphaFactorubSUN(GLubyte factor) {
    
printf(gl.c);
}
#endif

#ifndef skip_GlobalAlphaFactoruiSUN
void GlobalAlphaFactoruiSUN(GLuint factor) {
    
printf(gl.c);
}
#endif

#ifndef skip_GlobalAlphaFactorusSUN
void GlobalAlphaFactorusSUN(GLushort factor) {
    
printf(gl.c);
}
#endif

#ifndef skip_Hint
void Hint(GLenum target, GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_HintPGI
void HintPGI(GLenum target, GLint mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_Histogram
void Histogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink) {
    
printf(gl.c);
}
#endif

#ifndef skip_HistogramEXT
void HistogramEXT(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink) {
    
printf(gl.c);
}
#endif

#ifndef skip_IglooInterfaceSGIX
void IglooInterfaceSGIX(GLenum pname, GLvoid params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ImageTransformParameterfHP
void ImageTransformParameterfHP(GLenum target, GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_ImageTransformParameterfvHP
void ImageTransformParameterfvHP(GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ImageTransformParameteriHP
void ImageTransformParameteriHP(GLenum target, GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_ImageTransformParameterivHP
void ImageTransformParameterivHP(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ImportSyncEXT
sync ImportSyncEXT(GLenum external_sync_type, GLintptr external_sync, GLbitfield flags) {
    
printf(gl.c);
}
#endif

#ifndef skip_IndexFormatNV
void IndexFormatNV(GLenum type, GLsizei stride) {
    
printf(gl.c);
}
#endif

#ifndef skip_IndexFuncEXT
void IndexFuncEXT(GLenum func, GLclampf ref) {
    
printf(gl.c);
}
#endif

#ifndef skip_IndexMask
void IndexMask(GLuint mask) {
    
printf(gl.c);
}
#endif

#ifndef skip_IndexMaterialEXT
void IndexMaterialEXT(GLenum face, GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_IndexPointer
void IndexPointer(GLenum type, GLsizei stride, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_IndexPointerEXT
void IndexPointerEXT(GLenum type, GLsizei stride, GLsizei count, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_IndexPointerListIBM
void IndexPointerListIBM(GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride) {
    
printf(gl.c);
}
#endif

#ifndef skip_Indexd
void Indexd(GLdouble c) {
    
printf(gl.c);
}
#endif

#ifndef skip_Indexdv
void Indexdv(GLdouble c) {
    
printf(gl.c);
}
#endif

#ifndef skip_Indexf
void Indexf(GLfloat c) {
    
printf(gl.c);
}
#endif

#ifndef skip_Indexfv
void Indexfv(GLfloat c) {
    
printf(gl.c);
}
#endif

#ifndef skip_Indexi
void Indexi(GLint c) {
    
printf(gl.c);
}
#endif

#ifndef skip_Indexiv
void Indexiv(GLint c) {
    
printf(gl.c);
}
#endif

#ifndef skip_Indexs
void Indexs(GLshort c) {
    
printf(gl.c);
}
#endif

#ifndef skip_Indexsv
void Indexsv(GLshort c) {
    
printf(gl.c);
}
#endif

#ifndef skip_Indexub
void Indexub(GLubyte c) {
    
printf(gl.c);
}
#endif

#ifndef skip_Indexubv
void Indexubv(GLubyte c) {
    
printf(gl.c);
}
#endif

#ifndef skip_IndexxOES
void IndexxOES(GLfixed component) {
    
printf(gl.c);
}
#endif

#ifndef skip_IndexxvOES
void IndexxvOES(GLfixed component) {
    
printf(gl.c);
}
#endif

#ifndef skip_InitNames
void InitNames() {
    
printf(gl.c);
}
#endif

#ifndef skip_InsertComponentEXT
void InsertComponentEXT(GLuint res, GLuint src, GLuint num) {
    
printf(gl.c);
}
#endif

#ifndef skip_InstrumentsBufferSGIX
void InstrumentsBufferSGIX(GLsizei size, GLint buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_InterleavedArrays
void InterleavedArrays(GLenum format, GLsizei stride, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_InterpolatePathsNV
void InterpolatePathsNV(GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight) {
    
printf(gl.c);
}
#endif

#ifndef skip_InvalidateBufferData
void InvalidateBufferData(GLuint buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_InvalidateBufferSubData
void InvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length) {
    
printf(gl.c);
}
#endif

#ifndef skip_InvalidateFramebuffer
void InvalidateFramebuffer(GLenum target, GLsizei numAttachments, GLenum attachments) {
    
printf(gl.c);
}
#endif

#ifndef skip_InvalidateSubFramebuffer
void InvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, GLenum attachments, GLint x, GLint y, GLsizei width, GLsizei height) {
    
printf(gl.c);
}
#endif

#ifndef skip_InvalidateTexImage
void InvalidateTexImage(GLuint texture, GLint level) {
    
printf(gl.c);
}
#endif

#ifndef skip_InvalidateTexSubImage
void InvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsAsyncMarkerSGIX
Boolean IsAsyncMarkerSGIX(GLuint marker) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsBuffer
Boolean IsBuffer(GLuint buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsBufferARB
Boolean IsBufferARB(GLuint buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsBufferResidentNV
Boolean IsBufferResidentNV(GLenum target) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsEnabled
Boolean IsEnabled(GLenum cap) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsEnabledIndexedEXT
Boolean IsEnabledIndexedEXT(GLenum target, GLuint index) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsEnabledi
Boolean IsEnabledi(GLenum target, GLuint index) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsFenceAPPLE
Boolean IsFenceAPPLE(GLuint fence) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsFenceNV
Boolean IsFenceNV(GLuint fence) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsFramebuffer
Boolean IsFramebuffer(GLuint framebuffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsFramebufferEXT
Boolean IsFramebufferEXT(GLuint framebuffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsImageHandleResidentNV
Boolean IsImageHandleResidentNV(GLuint64 handle) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsList
Boolean IsList(GLuint list) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsNameAMD
Boolean IsNameAMD(GLenum identifier, GLuint name) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsNamedBufferResidentNV
Boolean IsNamedBufferResidentNV(GLuint buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsNamedStringARB
Boolean IsNamedStringARB(GLint namelen, GLchar name) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsObjectBufferATI
Boolean IsObjectBufferATI(GLuint buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsOcclusionQueryNV
Boolean IsOcclusionQueryNV(GLuint id) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsPathNV
Boolean IsPathNV(GLuint path) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsPointInFillPathNV
Boolean IsPointInFillPathNV(GLuint path, GLuint mask, GLfloat x, GLfloat y) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsPointInStrokePathNV
Boolean IsPointInStrokePathNV(GLuint path, GLfloat x, GLfloat y) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsProgram
Boolean IsProgram(GLuint program) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsProgramARB
Boolean IsProgramARB(GLuint program) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsProgramNV
Boolean IsProgramNV(GLuint id) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsProgramPipeline
Boolean IsProgramPipeline(GLuint pipeline) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsQuery
Boolean IsQuery(GLuint id) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsQueryARB
Boolean IsQueryARB(GLuint id) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsRenderbuffer
Boolean IsRenderbuffer(GLuint renderbuffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsRenderbufferEXT
Boolean IsRenderbufferEXT(GLuint renderbuffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsSampler
Boolean IsSampler(GLuint sampler) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsShader
Boolean IsShader(GLuint shader) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsSync
Boolean IsSync(GLsync sync) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsTexture
Boolean IsTexture(GLuint texture) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsTextureEXT
Boolean IsTextureEXT(GLuint texture) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsTextureHandleResidentNV
Boolean IsTextureHandleResidentNV(GLuint64 handle) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsTransformFeedback
Boolean IsTransformFeedback(GLuint id) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsTransformFeedbackNV
Boolean IsTransformFeedbackNV(GLuint id) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsVariantEnabledEXT
Boolean IsVariantEnabledEXT(GLuint id, GLenum cap) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsVertexArray
Boolean IsVertexArray(GLuint array) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsVertexArrayAPPLE
Boolean IsVertexArrayAPPLE(GLuint array) {
    
printf(gl.c);
}
#endif

#ifndef skip_IsVertexAttribEnabledAPPLE
Boolean IsVertexAttribEnabledAPPLE(GLuint index, GLenum pname) {
    
printf(gl.c);
}
#endif

#ifndef skip_LightEnviSGIX
void LightEnviSGIX(GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_LightModelf
void LightModelf(GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_LightModelfv
void LightModelfv(GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_LightModeli
void LightModeli(GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_LightModeliv
void LightModeliv(GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_LightModelxOES
void LightModelxOES(GLenum pname, GLfixed param) {
    
printf(gl.c);
}
#endif

#ifndef skip_LightModelxvOES
void LightModelxvOES(GLenum pname, GLfixed param) {
    
printf(gl.c);
}
#endif

#ifndef skip_Lightf
void Lightf(GLenum light, GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_Lightfv
void Lightfv(GLenum light, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_Lighti
void Lighti(GLenum light, GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_Lightiv
void Lightiv(GLenum light, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_LightxOES
void LightxOES(GLenum light, GLenum pname, GLfixed param) {
    
printf(gl.c);
}
#endif

#ifndef skip_LightxvOES
void LightxvOES(GLenum light, GLenum pname, GLfixed params) {
    
printf(gl.c);
}
#endif

#ifndef skip_LineStipple
void LineStipple(GLint factor, GLushort pattern) {
    
printf(gl.c);
}
#endif

#ifndef skip_LineWidth
void LineWidth(GLfloat width) {
    
printf(gl.c);
}
#endif

#ifndef skip_LineWidthxOES
void LineWidthxOES(GLfixed width) {
    
printf(gl.c);
}
#endif

#ifndef skip_LinkProgram
void LinkProgram(GLuint program) {
    
printf(gl.c);
}
#endif

#ifndef skip_LinkProgramARB
void LinkProgramARB(GLhandleARB programObj) {
    
printf(gl.c);
}
#endif

#ifndef skip_ListBase
void ListBase(GLuint base) {
    
printf(gl.c);
}
#endif

#ifndef skip_ListParameterfSGIX
void ListParameterfSGIX(GLuint list, GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_ListParameterfvSGIX
void ListParameterfvSGIX(GLuint list, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ListParameteriSGIX
void ListParameteriSGIX(GLuint list, GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_ListParameterivSGIX
void ListParameterivSGIX(GLuint list, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_LoadIdentity
void LoadIdentity() {
    
printf(gl.c);
}
#endif

#ifndef skip_LoadIdentityDeformationMapSGIX
void LoadIdentityDeformationMapSGIX(GLbitfield mask) {
    
printf(gl.c);
}
#endif

#ifndef skip_LoadMatrixd
void LoadMatrixd(GLdouble m) {
    
printf(gl.c);
}
#endif

#ifndef skip_LoadMatrixf
void LoadMatrixf(GLfloat m) {
    
printf(gl.c);
}
#endif

#ifndef skip_LoadMatrixxOES
void LoadMatrixxOES(GLfixed m) {
    
printf(gl.c);
}
#endif

#ifndef skip_LoadName
void LoadName(GLuint name) {
    
printf(gl.c);
}
#endif

#ifndef skip_LoadProgramNV
void LoadProgramNV(GLenum target, GLuint id, GLsizei len, GLubyte program) {
    
printf(gl.c);
}
#endif

#ifndef skip_LoadTransposeMatrixd
void LoadTransposeMatrixd(GLdouble m) {
    
printf(gl.c);
}
#endif

#ifndef skip_LoadTransposeMatrixdARB
void LoadTransposeMatrixdARB(GLdouble m) {
    
printf(gl.c);
}
#endif

#ifndef skip_LoadTransposeMatrixf
void LoadTransposeMatrixf(GLfloat m) {
    
printf(gl.c);
}
#endif

#ifndef skip_LoadTransposeMatrixfARB
void LoadTransposeMatrixfARB(GLfloat m) {
    
printf(gl.c);
}
#endif

#ifndef skip_LoadTransposeMatrixxOES
void LoadTransposeMatrixxOES(GLfixed m) {
    
printf(gl.c);
}
#endif

#ifndef skip_LockArraysEXT
void LockArraysEXT(GLint first, GLsizei count) {
    
printf(gl.c);
}
#endif

#ifndef skip_LogicOp
void LogicOp(GLenum opcode) {
    
printf(gl.c);
}
#endif

#ifndef skip_MakeBufferNonResidentNV
void MakeBufferNonResidentNV(GLenum target) {
    
printf(gl.c);
}
#endif

#ifndef skip_MakeBufferResidentNV
void MakeBufferResidentNV(GLenum target, GLenum access) {
    
printf(gl.c);
}
#endif

#ifndef skip_MakeImageHandleNonResidentNV
void MakeImageHandleNonResidentNV(GLuint64 handle) {
    
printf(gl.c);
}
#endif

#ifndef skip_MakeImageHandleResidentNV
void MakeImageHandleResidentNV(GLuint64 handle, GLenum access) {
    
printf(gl.c);
}
#endif

#ifndef skip_MakeNamedBufferNonResidentNV
void MakeNamedBufferNonResidentNV(GLuint buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_MakeNamedBufferResidentNV
void MakeNamedBufferResidentNV(GLuint buffer, GLenum access) {
    
printf(gl.c);
}
#endif

#ifndef skip_MakeTextureHandleNonResidentNV
void MakeTextureHandleNonResidentNV(GLuint64 handle) {
    
printf(gl.c);
}
#endif

#ifndef skip_MakeTextureHandleResidentNV
void MakeTextureHandleResidentNV(GLuint64 handle) {
    
printf(gl.c);
}
#endif

#ifndef skip_Map1d
void Map1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, GLdouble points) {
    
printf(gl.c);
}
#endif

#ifndef skip_Map1f
void Map1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, GLfloat points) {
    
printf(gl.c);
}
#endif

#ifndef skip_Map1xOES
void Map1xOES(GLenum target, GLfixed u1, GLfixed u2, GLint stride, GLint order, GLfixed points) {
    
printf(gl.c);
}
#endif

#ifndef skip_Map2d
void Map2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble points) {
    
printf(gl.c);
}
#endif

#ifndef skip_Map2f
void Map2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat points) {
    
printf(gl.c);
}
#endif

#ifndef skip_Map2xOES
void Map2xOES(GLenum target, GLfixed u1, GLfixed u2, GLint ustride, GLint uorder, GLfixed v1, GLfixed v2, GLint vstride, GLint vorder, GLfixed points) {
    
printf(gl.c);
}
#endif

#ifndef skip_MapBuffer
VoidPointer MapBuffer(GLenum target, GLenum access) {
    
printf(gl.c);
}
#endif

#ifndef skip_MapBufferARB
VoidPointer MapBufferARB(GLenum target, GLenum access) {
    
printf(gl.c);
}
#endif

#ifndef skip_MapBufferRange
VoidPointer MapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) {
    
printf(gl.c);
}
#endif

#ifndef skip_MapControlPointsNV
void MapControlPointsNV(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLint uorder, GLint vorder, GLboolean packed, GLvoid points) {
    
printf(gl.c);
}
#endif

#ifndef skip_MapGrid1d
void MapGrid1d(GLint un, GLdouble u1, GLdouble u2) {
    
printf(gl.c);
}
#endif

#ifndef skip_MapGrid1f
void MapGrid1f(GLint un, GLfloat u1, GLfloat u2) {
    
printf(gl.c);
}
#endif

#ifndef skip_MapGrid1xOES
void MapGrid1xOES(GLint n, GLfixed u1, GLfixed u2) {
    
printf(gl.c);
}
#endif

#ifndef skip_MapGrid2d
void MapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2) {
    
printf(gl.c);
}
#endif

#ifndef skip_MapGrid2f
void MapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2) {
    
printf(gl.c);
}
#endif

#ifndef skip_MapGrid2xOES
void MapGrid2xOES(GLint n, GLfixed u1, GLfixed u2, GLfixed v1, GLfixed v2) {
    
printf(gl.c);
}
#endif

#ifndef skip_MapNamedBufferEXT
VoidPointer MapNamedBufferEXT(GLuint buffer, GLenum access) {
    
printf(gl.c);
}
#endif

#ifndef skip_MapNamedBufferRangeEXT
VoidPointer MapNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access) {
    
printf(gl.c);
}
#endif

#ifndef skip_MapObjectBufferATI
VoidPointer MapObjectBufferATI(GLuint buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_MapParameterfvNV
void MapParameterfvNV(GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_MapParameterivNV
void MapParameterivNV(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_MapTexture2DINTEL
VoidPointer MapTexture2DINTEL(GLuint texture, GLint level, GLbitfield access, GLint stride, GLenum layout) {
    
printf(gl.c);
}
#endif

#ifndef skip_MapVertexAttrib1dAPPLE
void MapVertexAttrib1dAPPLE(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint stride, GLint order, GLdouble points) {
    
printf(gl.c);
}
#endif

#ifndef skip_MapVertexAttrib1fAPPLE
void MapVertexAttrib1fAPPLE(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint stride, GLint order, GLfloat points) {
    
printf(gl.c);
}
#endif

#ifndef skip_MapVertexAttrib2dAPPLE
void MapVertexAttrib2dAPPLE(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble points) {
    
printf(gl.c);
}
#endif

#ifndef skip_MapVertexAttrib2fAPPLE
void MapVertexAttrib2fAPPLE(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat points) {
    
printf(gl.c);
}
#endif

#ifndef skip_Materialf
void Materialf(GLenum face, GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_Materialfv
void Materialfv(GLenum face, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_Materiali
void Materiali(GLenum face, GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_Materialiv
void Materialiv(GLenum face, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_MaterialxOES
void MaterialxOES(GLenum face, GLenum pname, GLfixed param) {
    
printf(gl.c);
}
#endif

#ifndef skip_MaterialxvOES
void MaterialxvOES(GLenum face, GLenum pname, GLfixed param) {
    
printf(gl.c);
}
#endif

#ifndef skip_MatrixFrustumEXT
void MatrixFrustumEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
    
printf(gl.c);
}
#endif

#ifndef skip_MatrixIndexPointerARB
void MatrixIndexPointerARB(GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_MatrixIndexubvARB
void MatrixIndexubvARB(GLint size, GLubyte indices) {
    
printf(gl.c);
}
#endif

#ifndef skip_MatrixIndexuivARB
void MatrixIndexuivARB(GLint size, GLuint indices) {
    
printf(gl.c);
}
#endif

#ifndef skip_MatrixIndexusvARB
void MatrixIndexusvARB(GLint size, GLushort indices) {
    
printf(gl.c);
}
#endif

#ifndef skip_MatrixLoadIdentityEXT
void MatrixLoadIdentityEXT(GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_MatrixLoadTransposedEXT
void MatrixLoadTransposedEXT(GLenum mode, GLdouble m) {
    
printf(gl.c);
}
#endif

#ifndef skip_MatrixLoadTransposefEXT
void MatrixLoadTransposefEXT(GLenum mode, GLfloat m) {
    
printf(gl.c);
}
#endif

#ifndef skip_MatrixLoaddEXT
void MatrixLoaddEXT(GLenum mode, GLdouble m) {
    
printf(gl.c);
}
#endif

#ifndef skip_MatrixLoadfEXT
void MatrixLoadfEXT(GLenum mode, GLfloat m) {
    
printf(gl.c);
}
#endif

#ifndef skip_MatrixMode
void MatrixMode(GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_MatrixMultTransposedEXT
void MatrixMultTransposedEXT(GLenum mode, GLdouble m) {
    
printf(gl.c);
}
#endif

#ifndef skip_MatrixMultTransposefEXT
void MatrixMultTransposefEXT(GLenum mode, GLfloat m) {
    
printf(gl.c);
}
#endif

#ifndef skip_MatrixMultdEXT
void MatrixMultdEXT(GLenum mode, GLdouble m) {
    
printf(gl.c);
}
#endif

#ifndef skip_MatrixMultfEXT
void MatrixMultfEXT(GLenum mode, GLfloat m) {
    
printf(gl.c);
}
#endif

#ifndef skip_MatrixOrthoEXT
void MatrixOrthoEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
    
printf(gl.c);
}
#endif

#ifndef skip_MatrixPopEXT
void MatrixPopEXT(GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_MatrixPushEXT
void MatrixPushEXT(GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_MatrixRotatedEXT
void MatrixRotatedEXT(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
    
printf(gl.c);
}
#endif

#ifndef skip_MatrixRotatefEXT
void MatrixRotatefEXT(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_MatrixScaledEXT
void MatrixScaledEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z) {
    
printf(gl.c);
}
#endif

#ifndef skip_MatrixScalefEXT
void MatrixScalefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_MatrixTranslatedEXT
void MatrixTranslatedEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z) {
    
printf(gl.c);
}
#endif

#ifndef skip_MatrixTranslatefEXT
void MatrixTranslatefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_MemoryBarrier
void MemoryBarrier(GLbitfield barriers) {
    
printf(gl.c);
}
#endif

#ifndef skip_MemoryBarrierEXT
void MemoryBarrierEXT(GLbitfield barriers) {
    
printf(gl.c);
}
#endif

#ifndef skip_MinSampleShading
void MinSampleShading(GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_MinSampleShadingARB
void MinSampleShadingARB(GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Minmax
void Minmax(GLenum target, GLenum internalformat, GLboolean sink) {
    
printf(gl.c);
}
#endif

#ifndef skip_MinmaxEXT
void MinmaxEXT(GLenum target, GLenum internalformat, GLboolean sink) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultMatrixd
void MultMatrixd(GLdouble m) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultMatrixf
void MultMatrixf(GLfloat m) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultMatrixxOES
void MultMatrixxOES(GLfixed m) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultTransposeMatrixd
void MultTransposeMatrixd(GLdouble m) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultTransposeMatrixdARB
void MultTransposeMatrixdARB(GLdouble m) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultTransposeMatrixf
void MultTransposeMatrixf(GLfloat m) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultTransposeMatrixfARB
void MultTransposeMatrixfARB(GLfloat m) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultTransposeMatrixxOES
void MultTransposeMatrixxOES(GLfixed m) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiDrawArrays
void MultiDrawArrays(GLenum mode, GLint first, GLsizei count, GLsizei drawcount) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiDrawArraysEXT
void MultiDrawArraysEXT(GLenum mode, GLint first, GLsizei count, GLsizei primcount) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiDrawArraysIndirect
void MultiDrawArraysIndirect(GLenum mode, void * indirect, GLsizei drawcount, GLsizei stride) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiDrawArraysIndirectAMD
void MultiDrawArraysIndirectAMD(GLenum mode, GLvoid indirect, GLsizei primcount, GLsizei stride) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiDrawElementArrayAPPLE
void MultiDrawElementArrayAPPLE(GLenum mode, GLint first, GLsizei count, GLsizei primcount) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiDrawElements
void MultiDrawElements(GLenum mode, GLsizei count, GLenum type, GLvoid*const indices, GLsizei drawcount) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiDrawElementsBaseVertex
void MultiDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid*const indices, GLsizei drawcount, GLint basevertex) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiDrawElementsEXT
void MultiDrawElementsEXT(GLenum mode, GLsizei count, GLenum type, GLvoid * indices, GLsizei primcount) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiDrawElementsIndirect
void MultiDrawElementsIndirect(GLenum mode, GLenum type, void * indirect, GLsizei drawcount, GLsizei stride) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiDrawElementsIndirectAMD
void MultiDrawElementsIndirectAMD(GLenum mode, GLenum type, GLvoid indirect, GLsizei primcount, GLsizei stride) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiDrawRangeElementArrayAPPLE
void MultiDrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count, GLsizei primcount) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiModeDrawArraysIBM
void MultiModeDrawArraysIBM(GLenum mode, GLint first, GLsizei count, GLsizei primcount, GLint modestride) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiModeDrawElementsIBM
void MultiModeDrawElementsIBM(GLenum mode, GLsizei count, GLenum type, GLvoid*const indices, GLsizei primcount, GLint modestride) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexBufferEXT
void MultiTexBufferEXT(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord1bOES
void MultiTexCoord1bOES(GLenum texture, GLbyte s) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord1bvOES
void MultiTexCoord1bvOES(GLenum texture, GLbyte coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord1d
void MultiTexCoord1d(GLenum target, GLdouble s) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord1dARB
void MultiTexCoord1dARB(GLenum target, GLdouble s) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord1dv
void MultiTexCoord1dv(GLenum target, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord1dvARB
void MultiTexCoord1dvARB(GLenum target, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord1f
void MultiTexCoord1f(GLenum target, GLfloat s) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord1fARB
void MultiTexCoord1fARB(GLenum target, GLfloat s) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord1fv
void MultiTexCoord1fv(GLenum target, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord1fvARB
void MultiTexCoord1fvARB(GLenum target, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord1hNV
void MultiTexCoord1hNV(GLenum target, GLhalfNV s) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord1hvNV
void MultiTexCoord1hvNV(GLenum target, GLhalfNV v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord1i
void MultiTexCoord1i(GLenum target, GLint s) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord1iARB
void MultiTexCoord1iARB(GLenum target, GLint s) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord1iv
void MultiTexCoord1iv(GLenum target, GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord1ivARB
void MultiTexCoord1ivARB(GLenum target, GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord1s
void MultiTexCoord1s(GLenum target, GLshort s) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord1sARB
void MultiTexCoord1sARB(GLenum target, GLshort s) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord1sv
void MultiTexCoord1sv(GLenum target, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord1svARB
void MultiTexCoord1svARB(GLenum target, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord1xOES
void MultiTexCoord1xOES(GLenum texture, GLfixed s) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord1xvOES
void MultiTexCoord1xvOES(GLenum texture, GLfixed coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord2bOES
void MultiTexCoord2bOES(GLenum texture, GLbyte s, GLbyte t) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord2bvOES
void MultiTexCoord2bvOES(GLenum texture, GLbyte coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord2d
void MultiTexCoord2d(GLenum target, GLdouble s, GLdouble t) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord2dARB
void MultiTexCoord2dARB(GLenum target, GLdouble s, GLdouble t) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord2dv
void MultiTexCoord2dv(GLenum target, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord2dvARB
void MultiTexCoord2dvARB(GLenum target, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord2f
void MultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord2fARB
void MultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord2fv
void MultiTexCoord2fv(GLenum target, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord2fvARB
void MultiTexCoord2fvARB(GLenum target, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord2hNV
void MultiTexCoord2hNV(GLenum target, GLhalfNV s, GLhalfNV t) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord2hvNV
void MultiTexCoord2hvNV(GLenum target, GLhalfNV v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord2i
void MultiTexCoord2i(GLenum target, GLint s, GLint t) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord2iARB
void MultiTexCoord2iARB(GLenum target, GLint s, GLint t) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord2iv
void MultiTexCoord2iv(GLenum target, GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord2ivARB
void MultiTexCoord2ivARB(GLenum target, GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord2s
void MultiTexCoord2s(GLenum target, GLshort s, GLshort t) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord2sARB
void MultiTexCoord2sARB(GLenum target, GLshort s, GLshort t) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord2sv
void MultiTexCoord2sv(GLenum target, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord2svARB
void MultiTexCoord2svARB(GLenum target, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord2xOES
void MultiTexCoord2xOES(GLenum texture, GLfixed s, GLfixed t) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord2xvOES
void MultiTexCoord2xvOES(GLenum texture, GLfixed coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord3bOES
void MultiTexCoord3bOES(GLenum texture, GLbyte s, GLbyte t, GLbyte r) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord3bvOES
void MultiTexCoord3bvOES(GLenum texture, GLbyte coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord3d
void MultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord3dARB
void MultiTexCoord3dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord3dv
void MultiTexCoord3dv(GLenum target, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord3dvARB
void MultiTexCoord3dvARB(GLenum target, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord3f
void MultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord3fARB
void MultiTexCoord3fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord3fv
void MultiTexCoord3fv(GLenum target, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord3fvARB
void MultiTexCoord3fvARB(GLenum target, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord3hNV
void MultiTexCoord3hNV(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord3hvNV
void MultiTexCoord3hvNV(GLenum target, GLhalfNV v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord3i
void MultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord3iARB
void MultiTexCoord3iARB(GLenum target, GLint s, GLint t, GLint r) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord3iv
void MultiTexCoord3iv(GLenum target, GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord3ivARB
void MultiTexCoord3ivARB(GLenum target, GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord3s
void MultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord3sARB
void MultiTexCoord3sARB(GLenum target, GLshort s, GLshort t, GLshort r) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord3sv
void MultiTexCoord3sv(GLenum target, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord3svARB
void MultiTexCoord3svARB(GLenum target, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord3xOES
void MultiTexCoord3xOES(GLenum texture, GLfixed s, GLfixed t, GLfixed r) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord3xvOES
void MultiTexCoord3xvOES(GLenum texture, GLfixed coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord4bOES
void MultiTexCoord4bOES(GLenum texture, GLbyte s, GLbyte t, GLbyte r, GLbyte q) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord4bvOES
void MultiTexCoord4bvOES(GLenum texture, GLbyte coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord4d
void MultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord4dARB
void MultiTexCoord4dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord4dv
void MultiTexCoord4dv(GLenum target, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord4dvARB
void MultiTexCoord4dvARB(GLenum target, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord4f
void MultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord4fARB
void MultiTexCoord4fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord4fv
void MultiTexCoord4fv(GLenum target, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord4fvARB
void MultiTexCoord4fvARB(GLenum target, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord4hNV
void MultiTexCoord4hNV(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord4hvNV
void MultiTexCoord4hvNV(GLenum target, GLhalfNV v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord4i
void MultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord4iARB
void MultiTexCoord4iARB(GLenum target, GLint s, GLint t, GLint r, GLint q) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord4iv
void MultiTexCoord4iv(GLenum target, GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord4ivARB
void MultiTexCoord4ivARB(GLenum target, GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord4s
void MultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord4sARB
void MultiTexCoord4sARB(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord4sv
void MultiTexCoord4sv(GLenum target, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord4svARB
void MultiTexCoord4svARB(GLenum target, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord4xOES
void MultiTexCoord4xOES(GLenum texture, GLfixed s, GLfixed t, GLfixed r, GLfixed q) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoord4xvOES
void MultiTexCoord4xvOES(GLenum texture, GLfixed coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoordP1ui
void MultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoordP1uiv
void MultiTexCoordP1uiv(GLenum texture, GLenum type, GLuint coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoordP2ui
void MultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoordP2uiv
void MultiTexCoordP2uiv(GLenum texture, GLenum type, GLuint coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoordP3ui
void MultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoordP3uiv
void MultiTexCoordP3uiv(GLenum texture, GLenum type, GLuint coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoordP4ui
void MultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoordP4uiv
void MultiTexCoordP4uiv(GLenum texture, GLenum type, GLuint coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexCoordPointerEXT
void MultiTexCoordPointerEXT(GLenum texunit, GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexEnvfEXT
void MultiTexEnvfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexEnvfvEXT
void MultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexEnviEXT
void MultiTexEnviEXT(GLenum texunit, GLenum target, GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexEnvivEXT
void MultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexGendEXT
void MultiTexGendEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble param) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexGendvEXT
void MultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble params) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexGenfEXT
void MultiTexGenfEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexGenfvEXT
void MultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexGeniEXT
void MultiTexGeniEXT(GLenum texunit, GLenum coord, GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexGenivEXT
void MultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexImage1DEXT
void MultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexImage2DEXT
void MultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexImage3DEXT
void MultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexParameterIivEXT
void MultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexParameterIuivEXT
void MultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexParameterfEXT
void MultiTexParameterfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexParameterfvEXT
void MultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexParameteriEXT
void MultiTexParameteriEXT(GLenum texunit, GLenum target, GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexParameterivEXT
void MultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexRenderbufferEXT
void MultiTexRenderbufferEXT(GLenum texunit, GLenum target, GLuint renderbuffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexSubImage1DEXT
void MultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexSubImage2DEXT
void MultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_MultiTexSubImage3DEXT
void MultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedBufferDataEXT
void NamedBufferDataEXT(GLuint buffer, GLsizeiptr size, GLvoid data, GLenum usage) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedBufferSubDataEXT
void NamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid data) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedCopyBufferSubDataEXT
void NamedCopyBufferSubDataEXT(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedFramebufferParameteriEXT
void NamedFramebufferParameteriEXT(GLuint framebuffer, GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedFramebufferRenderbufferEXT
void NamedFramebufferRenderbufferEXT(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedFramebufferTexture1DEXT
void NamedFramebufferTexture1DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedFramebufferTexture2DEXT
void NamedFramebufferTexture2DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedFramebufferTexture3DEXT
void NamedFramebufferTexture3DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedFramebufferTextureEXT
void NamedFramebufferTextureEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedFramebufferTextureFaceEXT
void NamedFramebufferTextureFaceEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedFramebufferTextureLayerEXT
void NamedFramebufferTextureLayerEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedProgramLocalParameter4dEXT
void NamedProgramLocalParameter4dEXT(GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedProgramLocalParameter4dvEXT
void NamedProgramLocalParameter4dvEXT(GLuint program, GLenum target, GLuint index, GLdouble params) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedProgramLocalParameter4fEXT
void NamedProgramLocalParameter4fEXT(GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedProgramLocalParameter4fvEXT
void NamedProgramLocalParameter4fvEXT(GLuint program, GLenum target, GLuint index, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedProgramLocalParameterI4iEXT
void NamedProgramLocalParameterI4iEXT(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedProgramLocalParameterI4ivEXT
void NamedProgramLocalParameterI4ivEXT(GLuint program, GLenum target, GLuint index, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedProgramLocalParameterI4uiEXT
void NamedProgramLocalParameterI4uiEXT(GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedProgramLocalParameterI4uivEXT
void NamedProgramLocalParameterI4uivEXT(GLuint program, GLenum target, GLuint index, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedProgramLocalParameters4fvEXT
void NamedProgramLocalParameters4fvEXT(GLuint program, GLenum target, GLuint index, GLsizei count, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedProgramLocalParametersI4ivEXT
void NamedProgramLocalParametersI4ivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedProgramLocalParametersI4uivEXT
void NamedProgramLocalParametersI4uivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedProgramStringEXT
void NamedProgramStringEXT(GLuint program, GLenum target, GLenum format, GLsizei len, GLvoid string) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedRenderbufferStorageEXT
void NamedRenderbufferStorageEXT(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedRenderbufferStorageMultisampleCoverageEXT
void NamedRenderbufferStorageMultisampleCoverageEXT(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedRenderbufferStorageMultisampleEXT
void NamedRenderbufferStorageMultisampleEXT(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
    
printf(gl.c);
}
#endif

#ifndef skip_NamedStringARB
void NamedStringARB(GLenum type, GLint namelen, GLchar name, GLint stringlen, GLchar string) {
    
printf(gl.c);
}
#endif

#ifndef skip_NewList
void NewList(GLuint list, GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_NewObjectBufferATI
UInt32 NewObjectBufferATI(GLsizei size, GLvoid pointer, GLenum usage) {
    
printf(gl.c);
}
#endif

#ifndef skip_Normal3b
void Normal3b(GLbyte nx, GLbyte ny, GLbyte nz) {
    
printf(gl.c);
}
#endif

#ifndef skip_Normal3bv
void Normal3bv(GLbyte v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Normal3d
void Normal3d(GLdouble nx, GLdouble ny, GLdouble nz) {
    
printf(gl.c);
}
#endif

#ifndef skip_Normal3dv
void Normal3dv(GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Normal3f
void Normal3f(GLfloat nx, GLfloat ny, GLfloat nz) {
    
printf(gl.c);
}
#endif

#ifndef skip_Normal3fVertex3fSUN
void Normal3fVertex3fSUN(GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_Normal3fVertex3fvSUN
void Normal3fVertex3fvSUN(GLfloat n, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Normal3fv
void Normal3fv(GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Normal3hNV
void Normal3hNV(GLhalfNV nx, GLhalfNV ny, GLhalfNV nz) {
    
printf(gl.c);
}
#endif

#ifndef skip_Normal3hvNV
void Normal3hvNV(GLhalfNV v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Normal3i
void Normal3i(GLint nx, GLint ny, GLint nz) {
    
printf(gl.c);
}
#endif

#ifndef skip_Normal3iv
void Normal3iv(GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Normal3s
void Normal3s(GLshort nx, GLshort ny, GLshort nz) {
    
printf(gl.c);
}
#endif

#ifndef skip_Normal3sv
void Normal3sv(GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Normal3xOES
void Normal3xOES(GLfixed nx, GLfixed ny, GLfixed nz) {
    
printf(gl.c);
}
#endif

#ifndef skip_Normal3xvOES
void Normal3xvOES(GLfixed coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_NormalFormatNV
void NormalFormatNV(GLenum type, GLsizei stride) {
    
printf(gl.c);
}
#endif

#ifndef skip_NormalP3ui
void NormalP3ui(GLenum type, GLuint coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_NormalP3uiv
void NormalP3uiv(GLenum type, GLuint coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_NormalPointer
void NormalPointer(GLenum type, GLsizei stride, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_NormalPointerEXT
void NormalPointerEXT(GLenum type, GLsizei stride, GLsizei count, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_NormalPointerListIBM
void NormalPointerListIBM(GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride) {
    
printf(gl.c);
}
#endif

#ifndef skip_NormalPointervINTEL
void NormalPointervINTEL(GLenum type, GLvoid * pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_NormalStream3bATI
void NormalStream3bATI(GLenum stream, GLbyte nx, GLbyte ny, GLbyte nz) {
    
printf(gl.c);
}
#endif

#ifndef skip_NormalStream3bvATI
void NormalStream3bvATI(GLenum stream, GLbyte coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_NormalStream3dATI
void NormalStream3dATI(GLenum stream, GLdouble nx, GLdouble ny, GLdouble nz) {
    
printf(gl.c);
}
#endif

#ifndef skip_NormalStream3dvATI
void NormalStream3dvATI(GLenum stream, GLdouble coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_NormalStream3fATI
void NormalStream3fATI(GLenum stream, GLfloat nx, GLfloat ny, GLfloat nz) {
    
printf(gl.c);
}
#endif

#ifndef skip_NormalStream3fvATI
void NormalStream3fvATI(GLenum stream, GLfloat coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_NormalStream3iATI
void NormalStream3iATI(GLenum stream, GLint nx, GLint ny, GLint nz) {
    
printf(gl.c);
}
#endif

#ifndef skip_NormalStream3ivATI
void NormalStream3ivATI(GLenum stream, GLint coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_NormalStream3sATI
void NormalStream3sATI(GLenum stream, GLshort nx, GLshort ny, GLshort nz) {
    
printf(gl.c);
}
#endif

#ifndef skip_NormalStream3svATI
void NormalStream3svATI(GLenum stream, GLshort coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_ObjectLabel
void ObjectLabel(GLenum identifier, GLuint name, GLsizei length, GLchar label) {
    
printf(gl.c);
}
#endif

#ifndef skip_ObjectPtrLabel
void ObjectPtrLabel(void * ptr, GLsizei length, GLchar label) {
    
printf(gl.c);
}
#endif

#ifndef skip_ObjectPurgeableAPPLE
GLenum ObjectPurgeableAPPLE(GLenum objectType, GLuint name, GLenum option) {
    
printf(gl.c);
}
#endif

#ifndef skip_ObjectUnpurgeableAPPLE
GLenum ObjectUnpurgeableAPPLE(GLenum objectType, GLuint name, GLenum option) {
    
printf(gl.c);
}
#endif

#ifndef skip_Ortho
void Ortho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
    
printf(gl.c);
}
#endif

#ifndef skip_OrthofOES
void OrthofOES(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f) {
    
printf(gl.c);
}
#endif

#ifndef skip_OrthoxOES
void OrthoxOES(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f) {
    
printf(gl.c);
}
#endif

#ifndef skip_PNTrianglesfATI
void PNTrianglesfATI(GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_PNTrianglesiATI
void PNTrianglesiATI(GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_PassTexCoordATI
void PassTexCoordATI(GLuint dst, GLuint coord, GLenum swizzle) {
    
printf(gl.c);
}
#endif

#ifndef skip_PassThrough
void PassThrough(GLfloat token) {
    
printf(gl.c);
}
#endif

#ifndef skip_PassThroughxOES
void PassThroughxOES(GLfixed token) {
    
printf(gl.c);
}
#endif

#ifndef skip_PatchParameterfv
void PatchParameterfv(GLenum pname, GLfloat values) {
    
printf(gl.c);
}
#endif

#ifndef skip_PatchParameteri
void PatchParameteri(GLenum pname, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_PathColorGenNV
void PathColorGenNV(GLenum color, GLenum genMode, GLenum colorFormat, GLfloat coeffs) {
    
printf(gl.c);
}
#endif

#ifndef skip_PathCommandsNV
void PathCommandsNV(GLuint path, GLsizei numCommands, GLubyte commands, GLsizei numCoords, GLenum coordType, GLvoid coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_PathCoordsNV
void PathCoordsNV(GLuint path, GLsizei numCoords, GLenum coordType, GLvoid coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_PathCoverDepthFuncNV
void PathCoverDepthFuncNV(GLenum func) {
    
printf(gl.c);
}
#endif

#ifndef skip_PathDashArrayNV
void PathDashArrayNV(GLuint path, GLsizei dashCount, GLfloat dashArray) {
    
printf(gl.c);
}
#endif

#ifndef skip_PathFogGenNV
void PathFogGenNV(GLenum genMode) {
    
printf(gl.c);
}
#endif

#ifndef skip_PathGlyphRangeNV
void PathGlyphRangeNV(GLuint firstPathName, GLenum fontTarget, GLvoid fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale) {
    
printf(gl.c);
}
#endif

#ifndef skip_PathGlyphsNV
void PathGlyphsNV(GLuint firstPathName, GLenum fontTarget, GLvoid fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, GLvoid charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale) {
    
printf(gl.c);
}
#endif

#ifndef skip_PathParameterfNV
void PathParameterfNV(GLuint path, GLenum pname, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_PathParameterfvNV
void PathParameterfvNV(GLuint path, GLenum pname, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_PathParameteriNV
void PathParameteriNV(GLuint path, GLenum pname, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_PathParameterivNV
void PathParameterivNV(GLuint path, GLenum pname, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_PathStencilDepthOffsetNV
void PathStencilDepthOffsetNV(GLfloat factor, GLfloat units) {
    
printf(gl.c);
}
#endif

#ifndef skip_PathStencilFuncNV
void PathStencilFuncNV(GLenum func, GLint ref, GLuint mask) {
    
printf(gl.c);
}
#endif

#ifndef skip_PathStringNV
void PathStringNV(GLuint path, GLenum format, GLsizei length, GLvoid pathString) {
    
printf(gl.c);
}
#endif

#ifndef skip_PathSubCommandsNV
void PathSubCommandsNV(GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, GLubyte commands, GLsizei numCoords, GLenum coordType, GLvoid coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_PathSubCoordsNV
void PathSubCoordsNV(GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, GLvoid coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_PathTexGenNV
void PathTexGenNV(GLenum texCoordSet, GLenum genMode, GLint components, GLfloat coeffs) {
    
printf(gl.c);
}
#endif

#ifndef skip_PauseTransformFeedback
void PauseTransformFeedback() {
    
printf(gl.c);
}
#endif

#ifndef skip_PauseTransformFeedbackNV
void PauseTransformFeedbackNV() {
    
printf(gl.c);
}
#endif

#ifndef skip_PixelDataRangeNV
void PixelDataRangeNV(GLenum target, GLsizei length, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_PixelMapfv
void PixelMapfv(GLenum map, GLsizei mapsize, GLfloat values) {
    
printf(gl.c);
}
#endif

#ifndef skip_PixelMapuiv
void PixelMapuiv(GLenum map, GLsizei mapsize, GLuint values) {
    
printf(gl.c);
}
#endif

#ifndef skip_PixelMapusv
void PixelMapusv(GLenum map, GLsizei mapsize, GLushort values) {
    
printf(gl.c);
}
#endif

#ifndef skip_PixelMapx
void PixelMapx(GLenum map, GLint size, GLfixed values) {
    
printf(gl.c);
}
#endif

#ifndef skip_PixelStoref
void PixelStoref(GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_PixelStorei
void PixelStorei(GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_PixelStorex
void PixelStorex(GLenum pname, GLfixed param) {
    
printf(gl.c);
}
#endif

#ifndef skip_PixelTexGenParameterfSGIS
void PixelTexGenParameterfSGIS(GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_PixelTexGenParameterfvSGIS
void PixelTexGenParameterfvSGIS(GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_PixelTexGenParameteriSGIS
void PixelTexGenParameteriSGIS(GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_PixelTexGenParameterivSGIS
void PixelTexGenParameterivSGIS(GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_PixelTexGenSGIX
void PixelTexGenSGIX(GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_PixelTransferf
void PixelTransferf(GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_PixelTransferi
void PixelTransferi(GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_PixelTransferxOES
void PixelTransferxOES(GLenum pname, GLfixed param) {
    
printf(gl.c);
}
#endif

#ifndef skip_PixelTransformParameterfEXT
void PixelTransformParameterfEXT(GLenum target, GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_PixelTransformParameterfvEXT
void PixelTransformParameterfvEXT(GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_PixelTransformParameteriEXT
void PixelTransformParameteriEXT(GLenum target, GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_PixelTransformParameterivEXT
void PixelTransformParameterivEXT(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_PixelZoom
void PixelZoom(GLfloat xfactor, GLfloat yfactor) {
    
printf(gl.c);
}
#endif

#ifndef skip_PixelZoomxOES
void PixelZoomxOES(GLfixed xfactor, GLfixed yfactor) {
    
printf(gl.c);
}
#endif

#ifndef skip_PointAlongPathNV
Boolean PointAlongPathNV(GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat x, GLfloat y, GLfloat tangentX, GLfloat tangentY) {
    
printf(gl.c);
}
#endif

#ifndef skip_PointParameterf
void PointParameterf(GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_PointParameterfARB
void PointParameterfARB(GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_PointParameterfEXT
void PointParameterfEXT(GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_PointParameterfSGIS
void PointParameterfSGIS(GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_PointParameterfv
void PointParameterfv(GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_PointParameterfvARB
void PointParameterfvARB(GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_PointParameterfvEXT
void PointParameterfvEXT(GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_PointParameterfvSGIS
void PointParameterfvSGIS(GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_PointParameteri
void PointParameteri(GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_PointParameteriNV
void PointParameteriNV(GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_PointParameteriv
void PointParameteriv(GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_PointParameterivNV
void PointParameterivNV(GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_PointParameterxvOES
void PointParameterxvOES(GLenum pname, GLfixed params) {
    
printf(gl.c);
}
#endif

#ifndef skip_PointSize
void PointSize(GLfloat size) {
    
printf(gl.c);
}
#endif

#ifndef skip_PointSizexOES
void PointSizexOES(GLfixed size) {
    
printf(gl.c);
}
#endif

#ifndef skip_PollAsyncSGIX
Int32 PollAsyncSGIX(GLuint markerp) {
    
printf(gl.c);
}
#endif

#ifndef skip_PollInstrumentsSGIX
Int32 PollInstrumentsSGIX(GLint marker_p) {
    
printf(gl.c);
}
#endif

#ifndef skip_PolygonMode
void PolygonMode(GLenum face, GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_PolygonOffset
void PolygonOffset(GLfloat factor, GLfloat units) {
    
printf(gl.c);
}
#endif

#ifndef skip_PolygonOffsetEXT
void PolygonOffsetEXT(GLfloat factor, GLfloat bias) {
    
printf(gl.c);
}
#endif

#ifndef skip_PolygonOffsetxOES
void PolygonOffsetxOES(GLfixed factor, GLfixed units) {
    
printf(gl.c);
}
#endif

#ifndef skip_PolygonStipple
void PolygonStipple(GLubyte mask) {
    
printf(gl.c);
}
#endif

#ifndef skip_PopAttrib
void PopAttrib() {
    
printf(gl.c);
}
#endif

#ifndef skip_PopClientAttrib
void PopClientAttrib() {
    
printf(gl.c);
}
#endif

#ifndef skip_PopDebugGroup
void PopDebugGroup() {
    
printf(gl.c);
}
#endif

#ifndef skip_PopMatrix
void PopMatrix() {
    
printf(gl.c);
}
#endif

#ifndef skip_PopName
void PopName() {
    
printf(gl.c);
}
#endif

#ifndef skip_PresentFrameDualFillNV
void PresentFrameDualFillNV(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLenum target1, GLuint fill1, GLenum target2, GLuint fill2, GLenum target3, GLuint fill3) {
    
printf(gl.c);
}
#endif

#ifndef skip_PresentFrameKeyedNV
void PresentFrameKeyedNV(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLuint key0, GLenum target1, GLuint fill1, GLuint key1) {
    
printf(gl.c);
}
#endif

#ifndef skip_PrimitiveRestartIndex
void PrimitiveRestartIndex(GLuint index) {
    
printf(gl.c);
}
#endif

#ifndef skip_PrimitiveRestartIndexNV
void PrimitiveRestartIndexNV(GLuint index) {
    
printf(gl.c);
}
#endif

#ifndef skip_PrimitiveRestartNV
void PrimitiveRestartNV() {
    
printf(gl.c);
}
#endif

#ifndef skip_PrioritizeTextures
void PrioritizeTextures(GLsizei n, GLuint textures, GLfloat priorities) {
    
printf(gl.c);
}
#endif

#ifndef skip_PrioritizeTexturesEXT
void PrioritizeTexturesEXT(GLsizei n, GLuint textures, GLclampf priorities) {
    
printf(gl.c);
}
#endif

#ifndef skip_PrioritizeTexturesxOES
void PrioritizeTexturesxOES(GLsizei n, GLuint textures, GLfixed priorities) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramBinary
void ProgramBinary(GLuint program, GLenum binaryFormat, GLvoid binary, GLsizei length) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramBufferParametersIivNV
void ProgramBufferParametersIivNV(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramBufferParametersIuivNV
void ProgramBufferParametersIuivNV(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramBufferParametersfvNV
void ProgramBufferParametersfvNV(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramEnvParameter4dARB
void ProgramEnvParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramEnvParameter4dvARB
void ProgramEnvParameter4dvARB(GLenum target, GLuint index, GLdouble params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramEnvParameter4fARB
void ProgramEnvParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramEnvParameter4fvARB
void ProgramEnvParameter4fvARB(GLenum target, GLuint index, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramEnvParameterI4iNV
void ProgramEnvParameterI4iNV(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramEnvParameterI4ivNV
void ProgramEnvParameterI4ivNV(GLenum target, GLuint index, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramEnvParameterI4uiNV
void ProgramEnvParameterI4uiNV(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramEnvParameterI4uivNV
void ProgramEnvParameterI4uivNV(GLenum target, GLuint index, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramEnvParameters4fvEXT
void ProgramEnvParameters4fvEXT(GLenum target, GLuint index, GLsizei count, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramEnvParametersI4ivNV
void ProgramEnvParametersI4ivNV(GLenum target, GLuint index, GLsizei count, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramEnvParametersI4uivNV
void ProgramEnvParametersI4uivNV(GLenum target, GLuint index, GLsizei count, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramLocalParameter4dARB
void ProgramLocalParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramLocalParameter4dvARB
void ProgramLocalParameter4dvARB(GLenum target, GLuint index, GLdouble params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramLocalParameter4fARB
void ProgramLocalParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramLocalParameter4fvARB
void ProgramLocalParameter4fvARB(GLenum target, GLuint index, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramLocalParameterI4iNV
void ProgramLocalParameterI4iNV(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramLocalParameterI4ivNV
void ProgramLocalParameterI4ivNV(GLenum target, GLuint index, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramLocalParameterI4uiNV
void ProgramLocalParameterI4uiNV(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramLocalParameterI4uivNV
void ProgramLocalParameterI4uivNV(GLenum target, GLuint index, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramLocalParameters4fvEXT
void ProgramLocalParameters4fvEXT(GLenum target, GLuint index, GLsizei count, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramLocalParametersI4ivNV
void ProgramLocalParametersI4ivNV(GLenum target, GLuint index, GLsizei count, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramLocalParametersI4uivNV
void ProgramLocalParametersI4uivNV(GLenum target, GLuint index, GLsizei count, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramNamedParameter4dNV
void ProgramNamedParameter4dNV(GLuint id, GLsizei len, GLubyte name, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramNamedParameter4dvNV
void ProgramNamedParameter4dvNV(GLuint id, GLsizei len, GLubyte name, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramNamedParameter4fNV
void ProgramNamedParameter4fNV(GLuint id, GLsizei len, GLubyte name, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramNamedParameter4fvNV
void ProgramNamedParameter4fvNV(GLuint id, GLsizei len, GLubyte name, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramParameter4dNV
void ProgramParameter4dNV(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramParameter4dvNV
void ProgramParameter4dvNV(GLenum target, GLuint index, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramParameter4fNV
void ProgramParameter4fNV(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramParameter4fvNV
void ProgramParameter4fvNV(GLenum target, GLuint index, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramParameteri
void ProgramParameteri(GLuint program, GLenum pname, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramParameteriARB
void ProgramParameteriARB(GLuint program, GLenum pname, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramParameteriEXT
void ProgramParameteriEXT(GLuint program, GLenum pname, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramParameters4dvNV
void ProgramParameters4dvNV(GLenum target, GLuint index, GLsizei count, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramParameters4fvNV
void ProgramParameters4fvNV(GLenum target, GLuint index, GLsizei count, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramStringARB
void ProgramStringARB(GLenum target, GLenum format, GLsizei len, GLvoid string) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramSubroutineParametersuivNV
void ProgramSubroutineParametersuivNV(GLenum target, GLsizei count, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform1d
void ProgramUniform1d(GLuint program, GLint location, GLdouble v0) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform1dEXT
void ProgramUniform1dEXT(GLuint program, GLint location, GLdouble x) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform1dv
void ProgramUniform1dv(GLuint program, GLint location, GLsizei count, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform1dvEXT
void ProgramUniform1dvEXT(GLuint program, GLint location, GLsizei count, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform1f
void ProgramUniform1f(GLuint program, GLint location, GLfloat v0) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform1fEXT
void ProgramUniform1fEXT(GLuint program, GLint location, GLfloat v0) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform1fv
void ProgramUniform1fv(GLuint program, GLint location, GLsizei count, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform1fvEXT
void ProgramUniform1fvEXT(GLuint program, GLint location, GLsizei count, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform1i
void ProgramUniform1i(GLuint program, GLint location, GLint v0) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform1i64NV
void ProgramUniform1i64NV(GLuint program, GLint location, GLint64EXT x) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform1i64vNV
void ProgramUniform1i64vNV(GLuint program, GLint location, GLsizei count, GLint64EXT value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform1iEXT
void ProgramUniform1iEXT(GLuint program, GLint location, GLint v0) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform1iv
void ProgramUniform1iv(GLuint program, GLint location, GLsizei count, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform1ivEXT
void ProgramUniform1ivEXT(GLuint program, GLint location, GLsizei count, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform1ui
void ProgramUniform1ui(GLuint program, GLint location, GLuint v0) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform1ui64NV
void ProgramUniform1ui64NV(GLuint program, GLint location, GLuint64EXT x) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform1ui64vNV
void ProgramUniform1ui64vNV(GLuint program, GLint location, GLsizei count, GLuint64EXT value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform1uiEXT
void ProgramUniform1uiEXT(GLuint program, GLint location, GLuint v0) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform1uiv
void ProgramUniform1uiv(GLuint program, GLint location, GLsizei count, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform1uivEXT
void ProgramUniform1uivEXT(GLuint program, GLint location, GLsizei count, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform2d
void ProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform2dEXT
void ProgramUniform2dEXT(GLuint program, GLint location, GLdouble x, GLdouble y) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform2dv
void ProgramUniform2dv(GLuint program, GLint location, GLsizei count, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform2dvEXT
void ProgramUniform2dvEXT(GLuint program, GLint location, GLsizei count, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform2f
void ProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform2fEXT
void ProgramUniform2fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform2fv
void ProgramUniform2fv(GLuint program, GLint location, GLsizei count, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform2fvEXT
void ProgramUniform2fvEXT(GLuint program, GLint location, GLsizei count, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform2i
void ProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform2i64NV
void ProgramUniform2i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform2i64vNV
void ProgramUniform2i64vNV(GLuint program, GLint location, GLsizei count, GLint64EXT value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform2iEXT
void ProgramUniform2iEXT(GLuint program, GLint location, GLint v0, GLint v1) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform2iv
void ProgramUniform2iv(GLuint program, GLint location, GLsizei count, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform2ivEXT
void ProgramUniform2ivEXT(GLuint program, GLint location, GLsizei count, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform2ui
void ProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform2ui64NV
void ProgramUniform2ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform2ui64vNV
void ProgramUniform2ui64vNV(GLuint program, GLint location, GLsizei count, GLuint64EXT value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform2uiEXT
void ProgramUniform2uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform2uiv
void ProgramUniform2uiv(GLuint program, GLint location, GLsizei count, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform2uivEXT
void ProgramUniform2uivEXT(GLuint program, GLint location, GLsizei count, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform3d
void ProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform3dEXT
void ProgramUniform3dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform3dv
void ProgramUniform3dv(GLuint program, GLint location, GLsizei count, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform3dvEXT
void ProgramUniform3dvEXT(GLuint program, GLint location, GLsizei count, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform3f
void ProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform3fEXT
void ProgramUniform3fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform3fv
void ProgramUniform3fv(GLuint program, GLint location, GLsizei count, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform3fvEXT
void ProgramUniform3fvEXT(GLuint program, GLint location, GLsizei count, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform3i
void ProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform3i64NV
void ProgramUniform3i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform3i64vNV
void ProgramUniform3i64vNV(GLuint program, GLint location, GLsizei count, GLint64EXT value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform3iEXT
void ProgramUniform3iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform3iv
void ProgramUniform3iv(GLuint program, GLint location, GLsizei count, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform3ivEXT
void ProgramUniform3ivEXT(GLuint program, GLint location, GLsizei count, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform3ui
void ProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform3ui64NV
void ProgramUniform3ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform3ui64vNV
void ProgramUniform3ui64vNV(GLuint program, GLint location, GLsizei count, GLuint64EXT value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform3uiEXT
void ProgramUniform3uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform3uiv
void ProgramUniform3uiv(GLuint program, GLint location, GLsizei count, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform3uivEXT
void ProgramUniform3uivEXT(GLuint program, GLint location, GLsizei count, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform4d
void ProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform4dEXT
void ProgramUniform4dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform4dv
void ProgramUniform4dv(GLuint program, GLint location, GLsizei count, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform4dvEXT
void ProgramUniform4dvEXT(GLuint program, GLint location, GLsizei count, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform4f
void ProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform4fEXT
void ProgramUniform4fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform4fv
void ProgramUniform4fv(GLuint program, GLint location, GLsizei count, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform4fvEXT
void ProgramUniform4fvEXT(GLuint program, GLint location, GLsizei count, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform4i
void ProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform4i64NV
void ProgramUniform4i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform4i64vNV
void ProgramUniform4i64vNV(GLuint program, GLint location, GLsizei count, GLint64EXT value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform4iEXT
void ProgramUniform4iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform4iv
void ProgramUniform4iv(GLuint program, GLint location, GLsizei count, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform4ivEXT
void ProgramUniform4ivEXT(GLuint program, GLint location, GLsizei count, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform4ui
void ProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform4ui64NV
void ProgramUniform4ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform4ui64vNV
void ProgramUniform4ui64vNV(GLuint program, GLint location, GLsizei count, GLuint64EXT value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform4uiEXT
void ProgramUniform4uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform4uiv
void ProgramUniform4uiv(GLuint program, GLint location, GLsizei count, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniform4uivEXT
void ProgramUniform4uivEXT(GLuint program, GLint location, GLsizei count, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformHandleui64NV
void ProgramUniformHandleui64NV(GLuint program, GLint location, GLuint64 value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformHandleui64vNV
void ProgramUniformHandleui64vNV(GLuint program, GLint location, GLsizei count, GLuint64 values) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix2dv
void ProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix2dvEXT
void ProgramUniformMatrix2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix2fv
void ProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix2fvEXT
void ProgramUniformMatrix2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix2x3dv
void ProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix2x3dvEXT
void ProgramUniformMatrix2x3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix2x3fv
void ProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix2x3fvEXT
void ProgramUniformMatrix2x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix2x4dv
void ProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix2x4dvEXT
void ProgramUniformMatrix2x4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix2x4fv
void ProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix2x4fvEXT
void ProgramUniformMatrix2x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix3dv
void ProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix3dvEXT
void ProgramUniformMatrix3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix3fv
void ProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix3fvEXT
void ProgramUniformMatrix3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix3x2dv
void ProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix3x2dvEXT
void ProgramUniformMatrix3x2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix3x2fv
void ProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix3x2fvEXT
void ProgramUniformMatrix3x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix3x4dv
void ProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix3x4dvEXT
void ProgramUniformMatrix3x4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix3x4fv
void ProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix3x4fvEXT
void ProgramUniformMatrix3x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix4dv
void ProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix4dvEXT
void ProgramUniformMatrix4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix4fv
void ProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix4fvEXT
void ProgramUniformMatrix4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix4x2dv
void ProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix4x2dvEXT
void ProgramUniformMatrix4x2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix4x2fv
void ProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix4x2fvEXT
void ProgramUniformMatrix4x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix4x3dv
void ProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix4x3dvEXT
void ProgramUniformMatrix4x3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix4x3fv
void ProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformMatrix4x3fvEXT
void ProgramUniformMatrix4x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformui64NV
void ProgramUniformui64NV(GLuint program, GLint location, GLuint64EXT value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramUniformui64vNV
void ProgramUniformui64vNV(GLuint program, GLint location, GLsizei count, GLuint64EXT value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProgramVertexLimitNV
void ProgramVertexLimitNV(GLenum target, GLint limit) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProvokingVertex
void ProvokingVertex(GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_ProvokingVertexEXT
void ProvokingVertexEXT(GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_PushAttrib
void PushAttrib(GLbitfield mask) {
    
printf(gl.c);
}
#endif

#ifndef skip_PushClientAttrib
void PushClientAttrib(GLbitfield mask) {
    
printf(gl.c);
}
#endif

#ifndef skip_PushClientAttribDefaultEXT
void PushClientAttribDefaultEXT(GLbitfield mask) {
    
printf(gl.c);
}
#endif

#ifndef skip_PushDebugGroup
void PushDebugGroup(GLenum source, GLuint id, GLsizei length, GLchar message) {
    
printf(gl.c);
}
#endif

#ifndef skip_PushMatrix
void PushMatrix() {
    
printf(gl.c);
}
#endif

#ifndef skip_PushName
void PushName(GLuint name) {
    
printf(gl.c);
}
#endif

#ifndef skip_QueryCounter
void QueryCounter(GLuint id, GLenum target) {
    
printf(gl.c);
}
#endif

#ifndef skip_QueryMatrixxOES
GLbitfield QueryMatrixxOES(GLfixed mantissa, GLint exponent) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos2d
void RasterPos2d(GLdouble x, GLdouble y) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos2dv
void RasterPos2dv(GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos2f
void RasterPos2f(GLfloat x, GLfloat y) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos2fv
void RasterPos2fv(GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos2i
void RasterPos2i(GLint x, GLint y) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos2iv
void RasterPos2iv(GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos2s
void RasterPos2s(GLshort x, GLshort y) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos2sv
void RasterPos2sv(GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos2xOES
void RasterPos2xOES(GLfixed x, GLfixed y) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos2xvOES
void RasterPos2xvOES(GLfixed coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos3d
void RasterPos3d(GLdouble x, GLdouble y, GLdouble z) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos3dv
void RasterPos3dv(GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos3f
void RasterPos3f(GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos3fv
void RasterPos3fv(GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos3i
void RasterPos3i(GLint x, GLint y, GLint z) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos3iv
void RasterPos3iv(GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos3s
void RasterPos3s(GLshort x, GLshort y, GLshort z) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos3sv
void RasterPos3sv(GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos3xOES
void RasterPos3xOES(GLfixed x, GLfixed y, GLfixed z) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos3xvOES
void RasterPos3xvOES(GLfixed coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos4d
void RasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos4dv
void RasterPos4dv(GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos4f
void RasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos4fv
void RasterPos4fv(GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos4i
void RasterPos4i(GLint x, GLint y, GLint z, GLint w) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos4iv
void RasterPos4iv(GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos4s
void RasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos4sv
void RasterPos4sv(GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos4xOES
void RasterPos4xOES(GLfixed x, GLfixed y, GLfixed z, GLfixed w) {
    
printf(gl.c);
}
#endif

#ifndef skip_RasterPos4xvOES
void RasterPos4xvOES(GLfixed coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReadBuffer
void ReadBuffer(GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReadInstrumentsSGIX
void ReadInstrumentsSGIX(GLint marker) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReadPixels
void ReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReadnPixelsARB
void ReadnPixelsARB(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLvoid data) {
    
printf(gl.c);
}
#endif

#ifndef skip_Rectd
void Rectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) {
    
printf(gl.c);
}
#endif

#ifndef skip_Rectdv
void Rectdv(GLdouble v1, GLdouble v2) {
    
printf(gl.c);
}
#endif

#ifndef skip_Rectf
void Rectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
    
printf(gl.c);
}
#endif

#ifndef skip_Rectfv
void Rectfv(GLfloat v1, GLfloat v2) {
    
printf(gl.c);
}
#endif

#ifndef skip_Recti
void Recti(GLint x1, GLint y1, GLint x2, GLint y2) {
    
printf(gl.c);
}
#endif

#ifndef skip_Rectiv
void Rectiv(GLint v1, GLint v2) {
    
printf(gl.c);
}
#endif

#ifndef skip_Rects
void Rects(GLshort x1, GLshort y1, GLshort x2, GLshort y2) {
    
printf(gl.c);
}
#endif

#ifndef skip_Rectsv
void Rectsv(GLshort v1, GLshort v2) {
    
printf(gl.c);
}
#endif

#ifndef skip_RectxOES
void RectxOES(GLfixed x1, GLfixed y1, GLfixed x2, GLfixed y2) {
    
printf(gl.c);
}
#endif

#ifndef skip_RectxvOES
void RectxvOES(GLfixed v1, GLfixed v2) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReferencePlaneSGIX
void ReferencePlaneSGIX(GLdouble equation) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReleaseShaderCompiler
void ReleaseShaderCompiler() {
    
printf(gl.c);
}
#endif

#ifndef skip_RenderMode
Int32 RenderMode(GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_RenderbufferStorage
void RenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
    
printf(gl.c);
}
#endif

#ifndef skip_RenderbufferStorageEXT
void RenderbufferStorageEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
    
printf(gl.c);
}
#endif

#ifndef skip_RenderbufferStorageMultisample
void RenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
    
printf(gl.c);
}
#endif

#ifndef skip_RenderbufferStorageMultisampleCoverageNV
void RenderbufferStorageMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height) {
    
printf(gl.c);
}
#endif

#ifndef skip_RenderbufferStorageMultisampleEXT
void RenderbufferStorageMultisampleEXT(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReplacementCodePointerSUN
void ReplacementCodePointerSUN(GLenum type, GLsizei stride, GLvoid * pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReplacementCodeubSUN
void ReplacementCodeubSUN(GLubyte code) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReplacementCodeubvSUN
void ReplacementCodeubvSUN(GLubyte code) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReplacementCodeuiColor3fVertex3fSUN
void ReplacementCodeuiColor3fVertex3fSUN(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReplacementCodeuiColor3fVertex3fvSUN
void ReplacementCodeuiColor3fVertex3fvSUN(GLuint rc, GLfloat c, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReplacementCodeuiColor4fNormal3fVertex3fSUN
void ReplacementCodeuiColor4fNormal3fVertex3fSUN(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReplacementCodeuiColor4fNormal3fVertex3fvSUN
void ReplacementCodeuiColor4fNormal3fVertex3fvSUN(GLuint rc, GLfloat c, GLfloat n, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReplacementCodeuiColor4ubVertex3fSUN
void ReplacementCodeuiColor4ubVertex3fSUN(GLuint rc, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReplacementCodeuiColor4ubVertex3fvSUN
void ReplacementCodeuiColor4ubVertex3fvSUN(GLuint rc, GLubyte c, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReplacementCodeuiNormal3fVertex3fSUN
void ReplacementCodeuiNormal3fVertex3fSUN(GLuint rc, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReplacementCodeuiNormal3fVertex3fvSUN
void ReplacementCodeuiNormal3fVertex3fvSUN(GLuint rc, GLfloat n, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReplacementCodeuiSUN
void ReplacementCodeuiSUN(GLuint code) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN
void ReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN
void ReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN(GLuint rc, GLfloat tc, GLfloat c, GLfloat n, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReplacementCodeuiTexCoord2fNormal3fVertex3fSUN
void ReplacementCodeuiTexCoord2fNormal3fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN
void ReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN(GLuint rc, GLfloat tc, GLfloat n, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReplacementCodeuiTexCoord2fVertex3fSUN
void ReplacementCodeuiTexCoord2fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReplacementCodeuiTexCoord2fVertex3fvSUN
void ReplacementCodeuiTexCoord2fVertex3fvSUN(GLuint rc, GLfloat tc, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReplacementCodeuiVertex3fSUN
void ReplacementCodeuiVertex3fSUN(GLuint rc, GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReplacementCodeuiVertex3fvSUN
void ReplacementCodeuiVertex3fvSUN(GLuint rc, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReplacementCodeuivSUN
void ReplacementCodeuivSUN(GLuint code) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReplacementCodeusSUN
void ReplacementCodeusSUN(GLushort code) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReplacementCodeusvSUN
void ReplacementCodeusvSUN(GLushort code) {
    
printf(gl.c);
}
#endif

#ifndef skip_RequestResidentProgramsNV
void RequestResidentProgramsNV(GLsizei n, GLuint programs) {
    
printf(gl.c);
}
#endif

#ifndef skip_ResetHistogram
void ResetHistogram(GLenum target) {
    
printf(gl.c);
}
#endif

#ifndef skip_ResetHistogramEXT
void ResetHistogramEXT(GLenum target) {
    
printf(gl.c);
}
#endif

#ifndef skip_ResetMinmax
void ResetMinmax(GLenum target) {
    
printf(gl.c);
}
#endif

#ifndef skip_ResetMinmaxEXT
void ResetMinmaxEXT(GLenum target) {
    
printf(gl.c);
}
#endif

#ifndef skip_ResizeBuffersMESA
void ResizeBuffersMESA() {
    
printf(gl.c);
}
#endif

#ifndef skip_ResumeTransformFeedback
void ResumeTransformFeedback() {
    
printf(gl.c);
}
#endif

#ifndef skip_ResumeTransformFeedbackNV
void ResumeTransformFeedbackNV() {
    
printf(gl.c);
}
#endif

#ifndef skip_Rotated
void Rotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
    
printf(gl.c);
}
#endif

#ifndef skip_Rotatef
void Rotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_RotatexOES
void RotatexOES(GLfixed angle, GLfixed x, GLfixed y, GLfixed z) {
    
printf(gl.c);
}
#endif

#ifndef skip_SampleCoverage
void SampleCoverage(GLfloat value, GLboolean invert) {
    
printf(gl.c);
}
#endif

#ifndef skip_SampleCoverageARB
void SampleCoverageARB(GLfloat value, GLboolean invert) {
    
printf(gl.c);
}
#endif

#ifndef skip_SampleCoverageOES
void SampleCoverageOES(GLfixed value, GLboolean invert) {
    
printf(gl.c);
}
#endif

#ifndef skip_SampleMapATI
void SampleMapATI(GLuint dst, GLuint interp, GLenum swizzle) {
    
printf(gl.c);
}
#endif

#ifndef skip_SampleMaskEXT
void SampleMaskEXT(GLclampf value, GLboolean invert) {
    
printf(gl.c);
}
#endif

#ifndef skip_SampleMaskIndexedNV
void SampleMaskIndexedNV(GLuint index, GLbitfield mask) {
    
printf(gl.c);
}
#endif

#ifndef skip_SampleMaskSGIS
void SampleMaskSGIS(GLclampf value, GLboolean invert) {
    
printf(gl.c);
}
#endif

#ifndef skip_SampleMaski
void SampleMaski(GLuint index, GLbitfield mask) {
    
printf(gl.c);
}
#endif

#ifndef skip_SamplePatternEXT
void SamplePatternEXT(GLenum pattern) {
    
printf(gl.c);
}
#endif

#ifndef skip_SamplePatternSGIS
void SamplePatternSGIS(GLenum pattern) {
    
printf(gl.c);
}
#endif

#ifndef skip_SamplerParameterIiv
void SamplerParameterIiv(GLuint sampler, GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_SamplerParameterIuiv
void SamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_SamplerParameterf
void SamplerParameterf(GLuint sampler, GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_SamplerParameterfv
void SamplerParameterfv(GLuint sampler, GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_SamplerParameteri
void SamplerParameteri(GLuint sampler, GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_SamplerParameteriv
void SamplerParameteriv(GLuint sampler, GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_Scaled
void Scaled(GLdouble x, GLdouble y, GLdouble z) {
    
printf(gl.c);
}
#endif

#ifndef skip_Scalef
void Scalef(GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_ScalexOES
void ScalexOES(GLfixed x, GLfixed y, GLfixed z) {
    
printf(gl.c);
}
#endif

#ifndef skip_Scissor
void Scissor(GLint x, GLint y, GLsizei width, GLsizei height) {
    
printf(gl.c);
}
#endif

#ifndef skip_ScissorArrayv
void ScissorArrayv(GLuint first, GLsizei count, GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_ScissorIndexed
void ScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height) {
    
printf(gl.c);
}
#endif

#ifndef skip_ScissorIndexedv
void ScissorIndexedv(GLuint index, GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3b
void SecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3bEXT
void SecondaryColor3bEXT(GLbyte red, GLbyte green, GLbyte blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3bv
void SecondaryColor3bv(GLbyte v) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3bvEXT
void SecondaryColor3bvEXT(GLbyte v) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3d
void SecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3dEXT
void SecondaryColor3dEXT(GLdouble red, GLdouble green, GLdouble blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3dv
void SecondaryColor3dv(GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3dvEXT
void SecondaryColor3dvEXT(GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3f
void SecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3fEXT
void SecondaryColor3fEXT(GLfloat red, GLfloat green, GLfloat blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3fv
void SecondaryColor3fv(GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3fvEXT
void SecondaryColor3fvEXT(GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3hNV
void SecondaryColor3hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3hvNV
void SecondaryColor3hvNV(GLhalfNV v) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3i
void SecondaryColor3i(GLint red, GLint green, GLint blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3iEXT
void SecondaryColor3iEXT(GLint red, GLint green, GLint blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3iv
void SecondaryColor3iv(GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3ivEXT
void SecondaryColor3ivEXT(GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3s
void SecondaryColor3s(GLshort red, GLshort green, GLshort blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3sEXT
void SecondaryColor3sEXT(GLshort red, GLshort green, GLshort blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3sv
void SecondaryColor3sv(GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3svEXT
void SecondaryColor3svEXT(GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3ub
void SecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3ubEXT
void SecondaryColor3ubEXT(GLubyte red, GLubyte green, GLubyte blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3ubv
void SecondaryColor3ubv(GLubyte v) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3ubvEXT
void SecondaryColor3ubvEXT(GLubyte v) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3ui
void SecondaryColor3ui(GLuint red, GLuint green, GLuint blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3uiEXT
void SecondaryColor3uiEXT(GLuint red, GLuint green, GLuint blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3uiv
void SecondaryColor3uiv(GLuint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3uivEXT
void SecondaryColor3uivEXT(GLuint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3us
void SecondaryColor3us(GLushort red, GLushort green, GLushort blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3usEXT
void SecondaryColor3usEXT(GLushort red, GLushort green, GLushort blue) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3usv
void SecondaryColor3usv(GLushort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColor3usvEXT
void SecondaryColor3usvEXT(GLushort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColorFormatNV
void SecondaryColorFormatNV(GLint size, GLenum type, GLsizei stride) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColorP3ui
void SecondaryColorP3ui(GLenum type, GLuint color) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColorP3uiv
void SecondaryColorP3uiv(GLenum type, GLuint color) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColorPointer
void SecondaryColorPointer(GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColorPointerEXT
void SecondaryColorPointerEXT(GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_SecondaryColorPointerListIBM
void SecondaryColorPointerListIBM(GLint size, GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride) {
    
printf(gl.c);
}
#endif

#ifndef skip_SelectBuffer
void SelectBuffer(GLsizei size, GLuint buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_SelectPerfMonitorCountersAMD
void SelectPerfMonitorCountersAMD(GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint counterList) {
    
printf(gl.c);
}
#endif

#ifndef skip_SeparableFilter2D
void SeparableFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid row, GLvoid column) {
    
printf(gl.c);
}
#endif

#ifndef skip_SeparableFilter2DEXT
void SeparableFilter2DEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid row, GLvoid column) {
    
printf(gl.c);
}
#endif

#ifndef skip_SetFenceAPPLE
void SetFenceAPPLE(GLuint fence) {
    
printf(gl.c);
}
#endif

#ifndef skip_SetFenceNV
void SetFenceNV(GLuint fence, GLenum condition) {
    
printf(gl.c);
}
#endif

#ifndef skip_SetFragmentShaderConstantATI
void SetFragmentShaderConstantATI(GLuint dst, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_SetInvariantEXT
void SetInvariantEXT(GLuint id, GLenum type, GLvoid addr) {
    
printf(gl.c);
}
#endif

#ifndef skip_SetLocalConstantEXT
void SetLocalConstantEXT(GLuint id, GLenum type, GLvoid addr) {
    
printf(gl.c);
}
#endif

#ifndef skip_SetMultisamplefvAMD
void SetMultisamplefvAMD(GLenum pname, GLuint index, GLfloat val) {
    
printf(gl.c);
}
#endif

#ifndef skip_ShadeModel
void ShadeModel(GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_ShaderBinary
void ShaderBinary(GLsizei count, GLuint shaders, GLenum binaryformat, GLvoid binary, GLsizei length) {
    
printf(gl.c);
}
#endif

#ifndef skip_ShaderOp1EXT
void ShaderOp1EXT(GLenum op, GLuint res, GLuint arg1) {
    
printf(gl.c);
}
#endif

#ifndef skip_ShaderOp2EXT
void ShaderOp2EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2) {
    
printf(gl.c);
}
#endif

#ifndef skip_ShaderOp3EXT
void ShaderOp3EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3) {
    
printf(gl.c);
}
#endif

#ifndef skip_ShaderSource
void ShaderSource(GLuint shader, GLsizei count, GLchar*const string, GLint length) {
    
printf(gl.c);
}
#endif

#ifndef skip_ShaderSourceARB
void ShaderSourceARB(GLhandleARB shaderObj, GLsizei count, GLcharARB * string, GLint length) {
    
printf(gl.c);
}
#endif

#ifndef skip_ShaderStorageBlockBinding
void ShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding) {
    
printf(gl.c);
}
#endif

#ifndef skip_SharpenTexFuncSGIS
void SharpenTexFuncSGIS(GLenum target, GLsizei n, GLfloat points) {
    
printf(gl.c);
}
#endif

#ifndef skip_SpriteParameterfSGIX
void SpriteParameterfSGIX(GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_SpriteParameterfvSGIX
void SpriteParameterfvSGIX(GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_SpriteParameteriSGIX
void SpriteParameteriSGIX(GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_SpriteParameterivSGIX
void SpriteParameterivSGIX(GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_StartInstrumentsSGIX
void StartInstrumentsSGIX() {
    
printf(gl.c);
}
#endif

#ifndef skip_StencilClearTagEXT
void StencilClearTagEXT(GLsizei stencilTagBits, GLuint stencilClearTag) {
    
printf(gl.c);
}
#endif

#ifndef skip_StencilFillPathInstancedNV
void StencilFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, GLfloat transformValues) {
    
printf(gl.c);
}
#endif

#ifndef skip_StencilFillPathNV
void StencilFillPathNV(GLuint path, GLenum fillMode, GLuint mask) {
    
printf(gl.c);
}
#endif

#ifndef skip_StencilFunc
void StencilFunc(GLenum func, GLint ref, GLuint mask) {
    
printf(gl.c);
}
#endif

#ifndef skip_StencilFuncSeparate
void StencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) {
    
printf(gl.c);
}
#endif

#ifndef skip_StencilFuncSeparateATI
void StencilFuncSeparateATI(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask) {
    
printf(gl.c);
}
#endif

#ifndef skip_StencilMask
void StencilMask(GLuint mask) {
    
printf(gl.c);
}
#endif

#ifndef skip_StencilMaskSeparate
void StencilMaskSeparate(GLenum face, GLuint mask) {
    
printf(gl.c);
}
#endif

#ifndef skip_StencilOp
void StencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
    
printf(gl.c);
}
#endif

#ifndef skip_StencilOpSeparate
void StencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) {
    
printf(gl.c);
}
#endif

#ifndef skip_StencilOpSeparateATI
void StencilOpSeparateATI(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) {
    
printf(gl.c);
}
#endif

#ifndef skip_StencilOpValueAMD
void StencilOpValueAMD(GLenum face, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_StencilStrokePathInstancedNV
void StencilStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, GLfloat transformValues) {
    
printf(gl.c);
}
#endif

#ifndef skip_StencilStrokePathNV
void StencilStrokePathNV(GLuint path, GLint reference, GLuint mask) {
    
printf(gl.c);
}
#endif

#ifndef skip_StopInstrumentsSGIX
void StopInstrumentsSGIX(GLint marker) {
    
printf(gl.c);
}
#endif

#ifndef skip_StringMarkerGREMEDY
void StringMarkerGREMEDY(GLsizei len, GLvoid string) {
    
printf(gl.c);
}
#endif

#ifndef skip_SwizzleEXT
void SwizzleEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW) {
    
printf(gl.c);
}
#endif

#ifndef skip_SyncTextureINTEL
void SyncTextureINTEL(GLuint texture) {
    
printf(gl.c);
}
#endif

#ifndef skip_TagSampleBufferSGIX
void TagSampleBufferSGIX() {
    
printf(gl.c);
}
#endif

#ifndef skip_Tangent3bEXT
void Tangent3bEXT(GLbyte tx, GLbyte ty, GLbyte tz) {
    
printf(gl.c);
}
#endif

#ifndef skip_Tangent3bvEXT
void Tangent3bvEXT(GLbyte v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Tangent3dEXT
void Tangent3dEXT(GLdouble tx, GLdouble ty, GLdouble tz) {
    
printf(gl.c);
}
#endif

#ifndef skip_Tangent3dvEXT
void Tangent3dvEXT(GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Tangent3fEXT
void Tangent3fEXT(GLfloat tx, GLfloat ty, GLfloat tz) {
    
printf(gl.c);
}
#endif

#ifndef skip_Tangent3fvEXT
void Tangent3fvEXT(GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Tangent3iEXT
void Tangent3iEXT(GLint tx, GLint ty, GLint tz) {
    
printf(gl.c);
}
#endif

#ifndef skip_Tangent3ivEXT
void Tangent3ivEXT(GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Tangent3sEXT
void Tangent3sEXT(GLshort tx, GLshort ty, GLshort tz) {
    
printf(gl.c);
}
#endif

#ifndef skip_Tangent3svEXT
void Tangent3svEXT(GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TangentPointerEXT
void TangentPointerEXT(GLenum type, GLsizei stride, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_TbufferMask3DFX
void TbufferMask3DFX(GLuint mask) {
    
printf(gl.c);
}
#endif

#ifndef skip_TessellationFactorAMD
void TessellationFactorAMD(GLfloat factor) {
    
printf(gl.c);
}
#endif

#ifndef skip_TessellationModeAMD
void TessellationModeAMD(GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_TestFenceAPPLE
Boolean TestFenceAPPLE(GLuint fence) {
    
printf(gl.c);
}
#endif

#ifndef skip_TestFenceNV
Boolean TestFenceNV(GLuint fence) {
    
printf(gl.c);
}
#endif

#ifndef skip_TestObjectAPPLE
Boolean TestObjectAPPLE(GLenum object, GLuint name) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexBuffer
void TexBuffer(GLenum target, GLenum internalformat, GLuint buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexBufferARB
void TexBufferARB(GLenum target, GLenum internalformat, GLuint buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexBufferEXT
void TexBufferEXT(GLenum target, GLenum internalformat, GLuint buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexBufferRange
void TexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexBumpParameterfvATI
void TexBumpParameterfvATI(GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexBumpParameterivATI
void TexBumpParameterivATI(GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord1bOES
void TexCoord1bOES(GLbyte s) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord1bvOES
void TexCoord1bvOES(GLbyte coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord1d
void TexCoord1d(GLdouble s) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord1dv
void TexCoord1dv(GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord1f
void TexCoord1f(GLfloat s) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord1fv
void TexCoord1fv(GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord1hNV
void TexCoord1hNV(GLhalfNV s) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord1hvNV
void TexCoord1hvNV(GLhalfNV v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord1i
void TexCoord1i(GLint s) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord1iv
void TexCoord1iv(GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord1s
void TexCoord1s(GLshort s) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord1sv
void TexCoord1sv(GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord1xOES
void TexCoord1xOES(GLfixed s) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord1xvOES
void TexCoord1xvOES(GLfixed coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord2bOES
void TexCoord2bOES(GLbyte s, GLbyte t) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord2bvOES
void TexCoord2bvOES(GLbyte coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord2d
void TexCoord2d(GLdouble s, GLdouble t) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord2dv
void TexCoord2dv(GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord2f
void TexCoord2f(GLfloat s, GLfloat t) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord2fColor3fVertex3fSUN
void TexCoord2fColor3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord2fColor3fVertex3fvSUN
void TexCoord2fColor3fVertex3fvSUN(GLfloat tc, GLfloat c, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord2fColor4fNormal3fVertex3fSUN
void TexCoord2fColor4fNormal3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord2fColor4fNormal3fVertex3fvSUN
void TexCoord2fColor4fNormal3fVertex3fvSUN(GLfloat tc, GLfloat c, GLfloat n, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord2fColor4ubVertex3fSUN
void TexCoord2fColor4ubVertex3fSUN(GLfloat s, GLfloat t, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord2fColor4ubVertex3fvSUN
void TexCoord2fColor4ubVertex3fvSUN(GLfloat tc, GLubyte c, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord2fNormal3fVertex3fSUN
void TexCoord2fNormal3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord2fNormal3fVertex3fvSUN
void TexCoord2fNormal3fVertex3fvSUN(GLfloat tc, GLfloat n, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord2fVertex3fSUN
void TexCoord2fVertex3fSUN(GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord2fVertex3fvSUN
void TexCoord2fVertex3fvSUN(GLfloat tc, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord2fv
void TexCoord2fv(GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord2hNV
void TexCoord2hNV(GLhalfNV s, GLhalfNV t) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord2hvNV
void TexCoord2hvNV(GLhalfNV v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord2i
void TexCoord2i(GLint s, GLint t) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord2iv
void TexCoord2iv(GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord2s
void TexCoord2s(GLshort s, GLshort t) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord2sv
void TexCoord2sv(GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord2xOES
void TexCoord2xOES(GLfixed s, GLfixed t) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord2xvOES
void TexCoord2xvOES(GLfixed coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord3bOES
void TexCoord3bOES(GLbyte s, GLbyte t, GLbyte r) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord3bvOES
void TexCoord3bvOES(GLbyte coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord3d
void TexCoord3d(GLdouble s, GLdouble t, GLdouble r) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord3dv
void TexCoord3dv(GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord3f
void TexCoord3f(GLfloat s, GLfloat t, GLfloat r) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord3fv
void TexCoord3fv(GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord3hNV
void TexCoord3hNV(GLhalfNV s, GLhalfNV t, GLhalfNV r) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord3hvNV
void TexCoord3hvNV(GLhalfNV v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord3i
void TexCoord3i(GLint s, GLint t, GLint r) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord3iv
void TexCoord3iv(GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord3s
void TexCoord3s(GLshort s, GLshort t, GLshort r) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord3sv
void TexCoord3sv(GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord3xOES
void TexCoord3xOES(GLfixed s, GLfixed t, GLfixed r) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord3xvOES
void TexCoord3xvOES(GLfixed coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord4bOES
void TexCoord4bOES(GLbyte s, GLbyte t, GLbyte r, GLbyte q) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord4bvOES
void TexCoord4bvOES(GLbyte coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord4d
void TexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord4dv
void TexCoord4dv(GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord4f
void TexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord4fColor4fNormal3fVertex4fSUN
void TexCoord4fColor4fNormal3fVertex4fSUN(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord4fColor4fNormal3fVertex4fvSUN
void TexCoord4fColor4fNormal3fVertex4fvSUN(GLfloat tc, GLfloat c, GLfloat n, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord4fVertex4fSUN
void TexCoord4fVertex4fSUN(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord4fVertex4fvSUN
void TexCoord4fVertex4fvSUN(GLfloat tc, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord4fv
void TexCoord4fv(GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord4hNV
void TexCoord4hNV(GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord4hvNV
void TexCoord4hvNV(GLhalfNV v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord4i
void TexCoord4i(GLint s, GLint t, GLint r, GLint q) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord4iv
void TexCoord4iv(GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord4s
void TexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord4sv
void TexCoord4sv(GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord4xOES
void TexCoord4xOES(GLfixed s, GLfixed t, GLfixed r, GLfixed q) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoord4xvOES
void TexCoord4xvOES(GLfixed coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoordFormatNV
void TexCoordFormatNV(GLint size, GLenum type, GLsizei stride) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoordP1ui
void TexCoordP1ui(GLenum type, GLuint coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoordP1uiv
void TexCoordP1uiv(GLenum type, GLuint coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoordP2ui
void TexCoordP2ui(GLenum type, GLuint coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoordP2uiv
void TexCoordP2uiv(GLenum type, GLuint coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoordP3ui
void TexCoordP3ui(GLenum type, GLuint coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoordP3uiv
void TexCoordP3uiv(GLenum type, GLuint coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoordP4ui
void TexCoordP4ui(GLenum type, GLuint coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoordP4uiv
void TexCoordP4uiv(GLenum type, GLuint coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoordPointer
void TexCoordPointer(GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoordPointerEXT
void TexCoordPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoordPointerListIBM
void TexCoordPointerListIBM(GLint size, GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexCoordPointervINTEL
void TexCoordPointervINTEL(GLint size, GLenum type, GLvoid * pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexEnvf
void TexEnvf(GLenum target, GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexEnvfv
void TexEnvfv(GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexEnvi
void TexEnvi(GLenum target, GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexEnviv
void TexEnviv(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexEnvxOES
void TexEnvxOES(GLenum target, GLenum pname, GLfixed param) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexEnvxvOES
void TexEnvxvOES(GLenum target, GLenum pname, GLfixed params) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexFilterFuncSGIS
void TexFilterFuncSGIS(GLenum target, GLenum filter, GLsizei n, GLfloat weights) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexGend
void TexGend(GLenum coord, GLenum pname, GLdouble param) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexGendv
void TexGendv(GLenum coord, GLenum pname, GLdouble params) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexGenf
void TexGenf(GLenum coord, GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexGenfv
void TexGenfv(GLenum coord, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexGeni
void TexGeni(GLenum coord, GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexGeniv
void TexGeniv(GLenum coord, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexGenxOES
void TexGenxOES(GLenum coord, GLenum pname, GLfixed param) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexGenxvOES
void TexGenxvOES(GLenum coord, GLenum pname, GLfixed params) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexImage1D
void TexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexImage2D
void TexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexImage2DMultisample
void TexImage2DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexImage2DMultisampleCoverageNV
void TexImage2DMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexImage3D
void TexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexImage3DEXT
void TexImage3DEXT(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexImage3DMultisample
void TexImage3DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexImage3DMultisampleCoverageNV
void TexImage3DMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexImage4DSGIS
void TexImage4DSGIS(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLint border, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexParameterIiv
void TexParameterIiv(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexParameterIivEXT
void TexParameterIivEXT(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexParameterIuiv
void TexParameterIuiv(GLenum target, GLenum pname, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexParameterIuivEXT
void TexParameterIuivEXT(GLenum target, GLenum pname, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexParameterf
void TexParameterf(GLenum target, GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexParameterfv
void TexParameterfv(GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexParameteri
void TexParameteri(GLenum target, GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexParameteriv
void TexParameteriv(GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexParameterxOES
void TexParameterxOES(GLenum target, GLenum pname, GLfixed param) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexParameterxvOES
void TexParameterxvOES(GLenum target, GLenum pname, GLfixed params) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexRenderbufferNV
void TexRenderbufferNV(GLenum target, GLuint renderbuffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexStorage1D
void TexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexStorage2D
void TexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexStorage2DMultisample
void TexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexStorage3D
void TexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexStorage3DMultisample
void TexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexStorageSparseAMD
void TexStorageSparseAMD(GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexSubImage1D
void TexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexSubImage1DEXT
void TexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexSubImage2D
void TexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexSubImage2DEXT
void TexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexSubImage3D
void TexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexSubImage3DEXT
void TexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_TexSubImage4DSGIS
void TexSubImage4DSGIS(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint woffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureBarrierNV
void TextureBarrierNV() {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureBufferEXT
void TextureBufferEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureBufferRangeEXT
void TextureBufferRangeEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureColorMaskSGIS
void TextureColorMaskSGIS(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureImage1DEXT
void TextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureImage2DEXT
void TextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureImage2DMultisampleCoverageNV
void TextureImage2DMultisampleCoverageNV(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureImage2DMultisampleNV
void TextureImage2DMultisampleNV(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureImage3DEXT
void TextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureImage3DMultisampleCoverageNV
void TextureImage3DMultisampleCoverageNV(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureImage3DMultisampleNV
void TextureImage3DMultisampleNV(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureLightEXT
void TextureLightEXT(GLenum pname) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureMaterialEXT
void TextureMaterialEXT(GLenum face, GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureNormalEXT
void TextureNormalEXT(GLenum mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureParameterIivEXT
void TextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureParameterIuivEXT
void TextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, GLuint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureParameterfEXT
void TextureParameterfEXT(GLuint texture, GLenum target, GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureParameterfvEXT
void TextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureParameteriEXT
void TextureParameteriEXT(GLuint texture, GLenum target, GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureParameterivEXT
void TextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureRangeAPPLE
void TextureRangeAPPLE(GLenum target, GLsizei length, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureRenderbufferEXT
void TextureRenderbufferEXT(GLuint texture, GLenum target, GLuint renderbuffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureStorage1DEXT
void TextureStorage1DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureStorage2DEXT
void TextureStorage2DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureStorage2DMultisampleEXT
void TextureStorage2DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureStorage3DEXT
void TextureStorage3DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureStorage3DMultisampleEXT
void TextureStorage3DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureStorageSparseAMD
void TextureStorageSparseAMD(GLuint texture, GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureSubImage1DEXT
void TextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureSubImage2DEXT
void TextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureSubImage3DEXT
void TextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLvoid pixels) {
    
printf(gl.c);
}
#endif

#ifndef skip_TextureView
void TextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers) {
    
printf(gl.c);
}
#endif

#ifndef skip_TrackMatrixNV
void TrackMatrixNV(GLenum target, GLuint address, GLenum matrix, GLenum transform) {
    
printf(gl.c);
}
#endif

#ifndef skip_TransformFeedbackAttribsNV
void TransformFeedbackAttribsNV(GLsizei count, GLint attribs, GLenum bufferMode) {
    
printf(gl.c);
}
#endif

#ifndef skip_TransformFeedbackStreamAttribsNV
void TransformFeedbackStreamAttribsNV(GLsizei count, GLint attribs, GLsizei nbuffers, GLint bufstreams, GLenum bufferMode) {
    
printf(gl.c);
}
#endif

#ifndef skip_TransformFeedbackVaryings
void TransformFeedbackVaryings(GLuint program, GLsizei count, GLchar*const varyings, GLenum bufferMode) {
    
printf(gl.c);
}
#endif

#ifndef skip_TransformFeedbackVaryingsEXT
void TransformFeedbackVaryingsEXT(GLuint program, GLsizei count, GLchar * varyings, GLenum bufferMode) {
    
printf(gl.c);
}
#endif

#ifndef skip_TransformFeedbackVaryingsNV
void TransformFeedbackVaryingsNV(GLuint program, GLsizei count, GLint locations, GLenum bufferMode) {
    
printf(gl.c);
}
#endif

#ifndef skip_TransformPathNV
void TransformPathNV(GLuint resultPath, GLuint srcPath, GLenum transformType, GLfloat transformValues) {
    
printf(gl.c);
}
#endif

#ifndef skip_Translated
void Translated(GLdouble x, GLdouble y, GLdouble z) {
    
printf(gl.c);
}
#endif

#ifndef skip_Translatef
void Translatef(GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_TranslatexOES
void TranslatexOES(GLfixed x, GLfixed y, GLfixed z) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform1d
void Uniform1d(GLint location, GLdouble x) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform1dv
void Uniform1dv(GLint location, GLsizei count, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform1f
void Uniform1f(GLint location, GLfloat v0) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform1fARB
void Uniform1fARB(GLint location, GLfloat v0) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform1fv
void Uniform1fv(GLint location, GLsizei count, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform1fvARB
void Uniform1fvARB(GLint location, GLsizei count, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform1i
void Uniform1i(GLint location, GLint v0) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform1i64NV
void Uniform1i64NV(GLint location, GLint64EXT x) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform1i64vNV
void Uniform1i64vNV(GLint location, GLsizei count, GLint64EXT value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform1iARB
void Uniform1iARB(GLint location, GLint v0) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform1iv
void Uniform1iv(GLint location, GLsizei count, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform1ivARB
void Uniform1ivARB(GLint location, GLsizei count, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform1ui
void Uniform1ui(GLint location, GLuint v0) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform1ui64NV
void Uniform1ui64NV(GLint location, GLuint64EXT x) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform1ui64vNV
void Uniform1ui64vNV(GLint location, GLsizei count, GLuint64EXT value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform1uiEXT
void Uniform1uiEXT(GLint location, GLuint v0) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform1uiv
void Uniform1uiv(GLint location, GLsizei count, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform1uivEXT
void Uniform1uivEXT(GLint location, GLsizei count, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform2d
void Uniform2d(GLint location, GLdouble x, GLdouble y) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform2dv
void Uniform2dv(GLint location, GLsizei count, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform2f
void Uniform2f(GLint location, GLfloat v0, GLfloat v1) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform2fARB
void Uniform2fARB(GLint location, GLfloat v0, GLfloat v1) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform2fv
void Uniform2fv(GLint location, GLsizei count, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform2fvARB
void Uniform2fvARB(GLint location, GLsizei count, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform2i
void Uniform2i(GLint location, GLint v0, GLint v1) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform2i64NV
void Uniform2i64NV(GLint location, GLint64EXT x, GLint64EXT y) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform2i64vNV
void Uniform2i64vNV(GLint location, GLsizei count, GLint64EXT value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform2iARB
void Uniform2iARB(GLint location, GLint v0, GLint v1) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform2iv
void Uniform2iv(GLint location, GLsizei count, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform2ivARB
void Uniform2ivARB(GLint location, GLsizei count, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform2ui
void Uniform2ui(GLint location, GLuint v0, GLuint v1) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform2ui64NV
void Uniform2ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform2ui64vNV
void Uniform2ui64vNV(GLint location, GLsizei count, GLuint64EXT value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform2uiEXT
void Uniform2uiEXT(GLint location, GLuint v0, GLuint v1) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform2uiv
void Uniform2uiv(GLint location, GLsizei count, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform2uivEXT
void Uniform2uivEXT(GLint location, GLsizei count, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform3d
void Uniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform3dv
void Uniform3dv(GLint location, GLsizei count, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform3f
void Uniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform3fARB
void Uniform3fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform3fv
void Uniform3fv(GLint location, GLsizei count, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform3fvARB
void Uniform3fvARB(GLint location, GLsizei count, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform3i
void Uniform3i(GLint location, GLint v0, GLint v1, GLint v2) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform3i64NV
void Uniform3i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform3i64vNV
void Uniform3i64vNV(GLint location, GLsizei count, GLint64EXT value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform3iARB
void Uniform3iARB(GLint location, GLint v0, GLint v1, GLint v2) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform3iv
void Uniform3iv(GLint location, GLsizei count, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform3ivARB
void Uniform3ivARB(GLint location, GLsizei count, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform3ui
void Uniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform3ui64NV
void Uniform3ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform3ui64vNV
void Uniform3ui64vNV(GLint location, GLsizei count, GLuint64EXT value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform3uiEXT
void Uniform3uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform3uiv
void Uniform3uiv(GLint location, GLsizei count, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform3uivEXT
void Uniform3uivEXT(GLint location, GLsizei count, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform4d
void Uniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform4dv
void Uniform4dv(GLint location, GLsizei count, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform4f
void Uniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform4fARB
void Uniform4fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform4fv
void Uniform4fv(GLint location, GLsizei count, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform4fvARB
void Uniform4fvARB(GLint location, GLsizei count, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform4i
void Uniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform4i64NV
void Uniform4i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform4i64vNV
void Uniform4i64vNV(GLint location, GLsizei count, GLint64EXT value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform4iARB
void Uniform4iARB(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform4iv
void Uniform4iv(GLint location, GLsizei count, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform4ivARB
void Uniform4ivARB(GLint location, GLsizei count, GLint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform4ui
void Uniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform4ui64NV
void Uniform4ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform4ui64vNV
void Uniform4ui64vNV(GLint location, GLsizei count, GLuint64EXT value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform4uiEXT
void Uniform4uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform4uiv
void Uniform4uiv(GLint location, GLsizei count, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniform4uivEXT
void Uniform4uivEXT(GLint location, GLsizei count, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformBlockBinding
void UniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformBufferEXT
void UniformBufferEXT(GLuint program, GLint location, GLuint buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformHandleui64NV
void UniformHandleui64NV(GLint location, GLuint64 value) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformHandleui64vNV
void UniformHandleui64vNV(GLint location, GLsizei count, GLuint64 value) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformMatrix2dv
void UniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformMatrix2fv
void UniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformMatrix2fvARB
void UniformMatrix2fvARB(GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformMatrix2x3dv
void UniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformMatrix2x3fv
void UniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformMatrix2x4dv
void UniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformMatrix2x4fv
void UniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformMatrix3dv
void UniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformMatrix3fv
void UniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformMatrix3fvARB
void UniformMatrix3fvARB(GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformMatrix3x2dv
void UniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformMatrix3x2fv
void UniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformMatrix3x4dv
void UniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformMatrix3x4fv
void UniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformMatrix4dv
void UniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformMatrix4fv
void UniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformMatrix4fvARB
void UniformMatrix4fvARB(GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformMatrix4x2dv
void UniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformMatrix4x2fv
void UniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformMatrix4x3dv
void UniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformMatrix4x3fv
void UniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value) {
    
printf(gl.c);
}
#endif

#ifndef skip_UniformSubroutinesuiv
void UniformSubroutinesuiv(GLenum shadertype, GLsizei count, GLuint indices) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniformui64NV
void Uniformui64NV(GLint location, GLuint64EXT value) {
    
printf(gl.c);
}
#endif

#ifndef skip_Uniformui64vNV
void Uniformui64vNV(GLint location, GLsizei count, GLuint64EXT value) {
    
printf(gl.c);
}
#endif

#ifndef skip_UnlockArraysEXT
void UnlockArraysEXT() {
    
printf(gl.c);
}
#endif

#ifndef skip_UnmapBuffer
Boolean UnmapBuffer(GLenum target) {
    
printf(gl.c);
}
#endif

#ifndef skip_UnmapBufferARB
Boolean UnmapBufferARB(GLenum target) {
    
printf(gl.c);
}
#endif

#ifndef skip_UnmapNamedBufferEXT
Boolean UnmapNamedBufferEXT(GLuint buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_UnmapObjectBufferATI
void UnmapObjectBufferATI(GLuint buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_UnmapTexture2DINTEL
void UnmapTexture2DINTEL(GLuint texture, GLint level) {
    
printf(gl.c);
}
#endif

#ifndef skip_UpdateObjectBufferATI
void UpdateObjectBufferATI(GLuint buffer, GLuint offset, GLsizei size, GLvoid pointer, GLenum preserve) {
    
printf(gl.c);
}
#endif

#ifndef skip_UseProgram
void UseProgram(GLuint program) {
    
printf(gl.c);
}
#endif

#ifndef skip_UseProgramObjectARB
void UseProgramObjectARB(GLhandleARB programObj) {
    
printf(gl.c);
}
#endif

#ifndef skip_UseProgramStages
void UseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program) {
    
printf(gl.c);
}
#endif

#ifndef skip_UseShaderProgramEXT
void UseShaderProgramEXT(GLenum type, GLuint program) {
    
printf(gl.c);
}
#endif

#ifndef skip_VDPAUFiniNV
void VDPAUFiniNV() {
    
printf(gl.c);
}
#endif

#ifndef skip_VDPAUGetSurfaceivNV
void VDPAUGetSurfaceivNV(GLvdpauSurfaceNV surface, GLenum pname, GLsizei bufSize, GLsizei length, GLint values) {
    
printf(gl.c);
}
#endif

#ifndef skip_VDPAUInitNV
void VDPAUInitNV(GLvoid vdpDevice, GLvoid getProcAddress) {
    
printf(gl.c);
}
#endif

#ifndef skip_VDPAUIsSurfaceNV
void VDPAUIsSurfaceNV(GLvdpauSurfaceNV surface) {
    
printf(gl.c);
}
#endif

#ifndef skip_VDPAUMapSurfacesNV
void VDPAUMapSurfacesNV(GLsizei numSurfaces, GLvdpauSurfaceNV surfaces) {
    
printf(gl.c);
}
#endif

#ifndef skip_VDPAURegisterOutputSurfaceNV
vdpauSurfaceNV VDPAURegisterOutputSurfaceNV(GLvoid * vdpSurface, GLenum target, GLsizei numTextureNames, GLuint textureNames) {
    
printf(gl.c);
}
#endif

#ifndef skip_VDPAURegisterVideoSurfaceNV
vdpauSurfaceNV VDPAURegisterVideoSurfaceNV(GLvoid vdpSurface, GLenum target, GLsizei numTextureNames, GLuint textureNames) {
    
printf(gl.c);
}
#endif

#ifndef skip_VDPAUSurfaceAccessNV
void VDPAUSurfaceAccessNV(GLvdpauSurfaceNV surface, GLenum access) {
    
printf(gl.c);
}
#endif

#ifndef skip_VDPAUUnmapSurfacesNV
void VDPAUUnmapSurfacesNV(GLsizei numSurface, GLvdpauSurfaceNV surfaces) {
    
printf(gl.c);
}
#endif

#ifndef skip_VDPAUUnregisterSurfaceNV
void VDPAUUnregisterSurfaceNV(GLvdpauSurfaceNV surface) {
    
printf(gl.c);
}
#endif

#ifndef skip_ValidateProgram
void ValidateProgram(GLuint program) {
    
printf(gl.c);
}
#endif

#ifndef skip_ValidateProgramARB
void ValidateProgramARB(GLhandleARB programObj) {
    
printf(gl.c);
}
#endif

#ifndef skip_ValidateProgramPipeline
void ValidateProgramPipeline(GLuint pipeline) {
    
printf(gl.c);
}
#endif

#ifndef skip_VariantArrayObjectATI
void VariantArrayObjectATI(GLuint id, GLenum type, GLsizei stride, GLuint buffer, GLuint offset) {
    
printf(gl.c);
}
#endif

#ifndef skip_VariantPointerEXT
void VariantPointerEXT(GLuint id, GLenum type, GLuint stride, GLvoid addr) {
    
printf(gl.c);
}
#endif

#ifndef skip_VariantbvEXT
void VariantbvEXT(GLuint id, GLbyte addr) {
    
printf(gl.c);
}
#endif

#ifndef skip_VariantdvEXT
void VariantdvEXT(GLuint id, GLdouble addr) {
    
printf(gl.c);
}
#endif

#ifndef skip_VariantfvEXT
void VariantfvEXT(GLuint id, GLfloat addr) {
    
printf(gl.c);
}
#endif

#ifndef skip_VariantivEXT
void VariantivEXT(GLuint id, GLint addr) {
    
printf(gl.c);
}
#endif

#ifndef skip_VariantsvEXT
void VariantsvEXT(GLuint id, GLshort addr) {
    
printf(gl.c);
}
#endif

#ifndef skip_VariantubvEXT
void VariantubvEXT(GLuint id, GLubyte addr) {
    
printf(gl.c);
}
#endif

#ifndef skip_VariantuivEXT
void VariantuivEXT(GLuint id, GLuint addr) {
    
printf(gl.c);
}
#endif

#ifndef skip_VariantusvEXT
void VariantusvEXT(GLuint id, GLushort addr) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex2bOES
void Vertex2bOES(GLbyte x) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex2bvOES
void Vertex2bvOES(GLbyte coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex2d
void Vertex2d(GLdouble x, GLdouble y) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex2dv
void Vertex2dv(GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex2f
void Vertex2f(GLfloat x, GLfloat y) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex2fv
void Vertex2fv(GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex2hNV
void Vertex2hNV(GLhalfNV x, GLhalfNV y) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex2hvNV
void Vertex2hvNV(GLhalfNV v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex2i
void Vertex2i(GLint x, GLint y) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex2iv
void Vertex2iv(GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex2s
void Vertex2s(GLshort x, GLshort y) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex2sv
void Vertex2sv(GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex2xOES
void Vertex2xOES(GLfixed x) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex2xvOES
void Vertex2xvOES(GLfixed coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex3bOES
void Vertex3bOES(GLbyte x, GLbyte y) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex3bvOES
void Vertex3bvOES(GLbyte coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex3d
void Vertex3d(GLdouble x, GLdouble y, GLdouble z) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex3dv
void Vertex3dv(GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex3f
void Vertex3f(GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex3fv
void Vertex3fv(GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex3hNV
void Vertex3hNV(GLhalfNV x, GLhalfNV y, GLhalfNV z) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex3hvNV
void Vertex3hvNV(GLhalfNV v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex3i
void Vertex3i(GLint x, GLint y, GLint z) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex3iv
void Vertex3iv(GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex3s
void Vertex3s(GLshort x, GLshort y, GLshort z) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex3sv
void Vertex3sv(GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex3xOES
void Vertex3xOES(GLfixed x, GLfixed y) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex3xvOES
void Vertex3xvOES(GLfixed coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex4bOES
void Vertex4bOES(GLbyte x, GLbyte y, GLbyte z) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex4bvOES
void Vertex4bvOES(GLbyte coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex4d
void Vertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex4dv
void Vertex4dv(GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex4f
void Vertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex4fv
void Vertex4fv(GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex4hNV
void Vertex4hNV(GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex4hvNV
void Vertex4hvNV(GLhalfNV v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex4i
void Vertex4i(GLint x, GLint y, GLint z, GLint w) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex4iv
void Vertex4iv(GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex4s
void Vertex4s(GLshort x, GLshort y, GLshort z, GLshort w) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex4sv
void Vertex4sv(GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex4xOES
void Vertex4xOES(GLfixed x, GLfixed y, GLfixed z) {
    
printf(gl.c);
}
#endif

#ifndef skip_Vertex4xvOES
void Vertex4xvOES(GLfixed coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexArrayBindVertexBufferEXT
void VertexArrayBindVertexBufferEXT(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexArrayColorOffsetEXT
void VertexArrayColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexArrayEdgeFlagOffsetEXT
void VertexArrayEdgeFlagOffsetEXT(GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexArrayFogCoordOffsetEXT
void VertexArrayFogCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexArrayIndexOffsetEXT
void VertexArrayIndexOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexArrayMultiTexCoordOffsetEXT
void VertexArrayMultiTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexArrayNormalOffsetEXT
void VertexArrayNormalOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexArrayParameteriAPPLE
void VertexArrayParameteriAPPLE(GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexArrayRangeAPPLE
void VertexArrayRangeAPPLE(GLsizei length, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexArrayRangeNV
void VertexArrayRangeNV(GLsizei length, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexArraySecondaryColorOffsetEXT
void VertexArraySecondaryColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexArrayTexCoordOffsetEXT
void VertexArrayTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexArrayVertexAttribBindingEXT
void VertexArrayVertexAttribBindingEXT(GLuint vaobj, GLuint attribindex, GLuint bindingindex) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexArrayVertexAttribFormatEXT
void VertexArrayVertexAttribFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexArrayVertexAttribIFormatEXT
void VertexArrayVertexAttribIFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexArrayVertexAttribIOffsetEXT
void VertexArrayVertexAttribIOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexArrayVertexAttribLFormatEXT
void VertexArrayVertexAttribLFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexArrayVertexAttribLOffsetEXT
void VertexArrayVertexAttribLOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexArrayVertexAttribOffsetEXT
void VertexArrayVertexAttribOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexArrayVertexBindingDivisorEXT
void VertexArrayVertexBindingDivisorEXT(GLuint vaobj, GLuint bindingindex, GLuint divisor) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexArrayVertexOffsetEXT
void VertexArrayVertexOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib1d
void VertexAttrib1d(GLuint index, GLdouble x) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib1dARB
void VertexAttrib1dARB(GLuint index, GLdouble x) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib1dNV
void VertexAttrib1dNV(GLuint index, GLdouble x) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib1dv
void VertexAttrib1dv(GLuint index, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib1dvARB
void VertexAttrib1dvARB(GLuint index, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib1dvNV
void VertexAttrib1dvNV(GLuint index, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib1f
void VertexAttrib1f(GLuint index, GLfloat x) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib1fARB
void VertexAttrib1fARB(GLuint index, GLfloat x) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib1fNV
void VertexAttrib1fNV(GLuint index, GLfloat x) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib1fv
void VertexAttrib1fv(GLuint index, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib1fvARB
void VertexAttrib1fvARB(GLuint index, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib1fvNV
void VertexAttrib1fvNV(GLuint index, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib1hNV
void VertexAttrib1hNV(GLuint index, GLhalfNV x) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib1hvNV
void VertexAttrib1hvNV(GLuint index, GLhalfNV v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib1s
void VertexAttrib1s(GLuint index, GLshort x) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib1sARB
void VertexAttrib1sARB(GLuint index, GLshort x) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib1sNV
void VertexAttrib1sNV(GLuint index, GLshort x) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib1sv
void VertexAttrib1sv(GLuint index, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib1svARB
void VertexAttrib1svARB(GLuint index, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib1svNV
void VertexAttrib1svNV(GLuint index, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib2d
void VertexAttrib2d(GLuint index, GLdouble x, GLdouble y) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib2dARB
void VertexAttrib2dARB(GLuint index, GLdouble x, GLdouble y) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib2dNV
void VertexAttrib2dNV(GLuint index, GLdouble x, GLdouble y) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib2dv
void VertexAttrib2dv(GLuint index, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib2dvARB
void VertexAttrib2dvARB(GLuint index, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib2dvNV
void VertexAttrib2dvNV(GLuint index, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib2f
void VertexAttrib2f(GLuint index, GLfloat x, GLfloat y) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib2fARB
void VertexAttrib2fARB(GLuint index, GLfloat x, GLfloat y) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib2fNV
void VertexAttrib2fNV(GLuint index, GLfloat x, GLfloat y) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib2fv
void VertexAttrib2fv(GLuint index, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib2fvARB
void VertexAttrib2fvARB(GLuint index, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib2fvNV
void VertexAttrib2fvNV(GLuint index, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib2hNV
void VertexAttrib2hNV(GLuint index, GLhalfNV x, GLhalfNV y) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib2hvNV
void VertexAttrib2hvNV(GLuint index, GLhalfNV v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib2s
void VertexAttrib2s(GLuint index, GLshort x, GLshort y) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib2sARB
void VertexAttrib2sARB(GLuint index, GLshort x, GLshort y) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib2sNV
void VertexAttrib2sNV(GLuint index, GLshort x, GLshort y) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib2sv
void VertexAttrib2sv(GLuint index, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib2svARB
void VertexAttrib2svARB(GLuint index, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib2svNV
void VertexAttrib2svNV(GLuint index, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib3d
void VertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib3dARB
void VertexAttrib3dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib3dNV
void VertexAttrib3dNV(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib3dv
void VertexAttrib3dv(GLuint index, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib3dvARB
void VertexAttrib3dvARB(GLuint index, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib3dvNV
void VertexAttrib3dvNV(GLuint index, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib3f
void VertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib3fARB
void VertexAttrib3fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib3fNV
void VertexAttrib3fNV(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib3fv
void VertexAttrib3fv(GLuint index, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib3fvARB
void VertexAttrib3fvARB(GLuint index, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib3fvNV
void VertexAttrib3fvNV(GLuint index, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib3hNV
void VertexAttrib3hNV(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib3hvNV
void VertexAttrib3hvNV(GLuint index, GLhalfNV v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib3s
void VertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib3sARB
void VertexAttrib3sARB(GLuint index, GLshort x, GLshort y, GLshort z) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib3sNV
void VertexAttrib3sNV(GLuint index, GLshort x, GLshort y, GLshort z) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib3sv
void VertexAttrib3sv(GLuint index, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib3svARB
void VertexAttrib3svARB(GLuint index, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib3svNV
void VertexAttrib3svNV(GLuint index, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4Nbv
void VertexAttrib4Nbv(GLuint index, GLbyte v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4NbvARB
void VertexAttrib4NbvARB(GLuint index, GLbyte v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4Niv
void VertexAttrib4Niv(GLuint index, GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4NivARB
void VertexAttrib4NivARB(GLuint index, GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4Nsv
void VertexAttrib4Nsv(GLuint index, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4NsvARB
void VertexAttrib4NsvARB(GLuint index, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4Nub
void VertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4NubARB
void VertexAttrib4NubARB(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4Nubv
void VertexAttrib4Nubv(GLuint index, GLubyte v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4NubvARB
void VertexAttrib4NubvARB(GLuint index, GLubyte v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4Nuiv
void VertexAttrib4Nuiv(GLuint index, GLuint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4NuivARB
void VertexAttrib4NuivARB(GLuint index, GLuint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4Nusv
void VertexAttrib4Nusv(GLuint index, GLushort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4NusvARB
void VertexAttrib4NusvARB(GLuint index, GLushort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4bv
void VertexAttrib4bv(GLuint index, GLbyte v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4bvARB
void VertexAttrib4bvARB(GLuint index, GLbyte v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4d
void VertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4dARB
void VertexAttrib4dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4dNV
void VertexAttrib4dNV(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4dv
void VertexAttrib4dv(GLuint index, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4dvARB
void VertexAttrib4dvARB(GLuint index, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4dvNV
void VertexAttrib4dvNV(GLuint index, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4f
void VertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4fARB
void VertexAttrib4fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4fNV
void VertexAttrib4fNV(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4fv
void VertexAttrib4fv(GLuint index, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4fvARB
void VertexAttrib4fvARB(GLuint index, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4fvNV
void VertexAttrib4fvNV(GLuint index, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4hNV
void VertexAttrib4hNV(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4hvNV
void VertexAttrib4hvNV(GLuint index, GLhalfNV v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4iv
void VertexAttrib4iv(GLuint index, GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4ivARB
void VertexAttrib4ivARB(GLuint index, GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4s
void VertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4sARB
void VertexAttrib4sARB(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4sNV
void VertexAttrib4sNV(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4sv
void VertexAttrib4sv(GLuint index, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4svARB
void VertexAttrib4svARB(GLuint index, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4svNV
void VertexAttrib4svNV(GLuint index, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4ubNV
void VertexAttrib4ubNV(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4ubv
void VertexAttrib4ubv(GLuint index, GLubyte v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4ubvARB
void VertexAttrib4ubvARB(GLuint index, GLubyte v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4ubvNV
void VertexAttrib4ubvNV(GLuint index, GLubyte v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4uiv
void VertexAttrib4uiv(GLuint index, GLuint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4uivARB
void VertexAttrib4uivARB(GLuint index, GLuint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4usv
void VertexAttrib4usv(GLuint index, GLushort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttrib4usvARB
void VertexAttrib4usvARB(GLuint index, GLushort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribArrayObjectATI
void VertexAttribArrayObjectATI(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint buffer, GLuint offset) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribBinding
void VertexAttribBinding(GLuint attribindex, GLuint bindingindex) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribDivisor
void VertexAttribDivisor(GLuint index, GLuint divisor) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribDivisorARB
void VertexAttribDivisorARB(GLuint index, GLuint divisor) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribFormat
void VertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribFormatNV
void VertexAttribFormatNV(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI1i
void VertexAttribI1i(GLuint index, GLint x) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI1iEXT
void VertexAttribI1iEXT(GLuint index, GLint x) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI1iv
void VertexAttribI1iv(GLuint index, GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI1ivEXT
void VertexAttribI1ivEXT(GLuint index, GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI1ui
void VertexAttribI1ui(GLuint index, GLuint x) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI1uiEXT
void VertexAttribI1uiEXT(GLuint index, GLuint x) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI1uiv
void VertexAttribI1uiv(GLuint index, GLuint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI1uivEXT
void VertexAttribI1uivEXT(GLuint index, GLuint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI2i
void VertexAttribI2i(GLuint index, GLint x, GLint y) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI2iEXT
void VertexAttribI2iEXT(GLuint index, GLint x, GLint y) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI2iv
void VertexAttribI2iv(GLuint index, GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI2ivEXT
void VertexAttribI2ivEXT(GLuint index, GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI2ui
void VertexAttribI2ui(GLuint index, GLuint x, GLuint y) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI2uiEXT
void VertexAttribI2uiEXT(GLuint index, GLuint x, GLuint y) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI2uiv
void VertexAttribI2uiv(GLuint index, GLuint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI2uivEXT
void VertexAttribI2uivEXT(GLuint index, GLuint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI3i
void VertexAttribI3i(GLuint index, GLint x, GLint y, GLint z) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI3iEXT
void VertexAttribI3iEXT(GLuint index, GLint x, GLint y, GLint z) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI3iv
void VertexAttribI3iv(GLuint index, GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI3ivEXT
void VertexAttribI3ivEXT(GLuint index, GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI3ui
void VertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI3uiEXT
void VertexAttribI3uiEXT(GLuint index, GLuint x, GLuint y, GLuint z) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI3uiv
void VertexAttribI3uiv(GLuint index, GLuint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI3uivEXT
void VertexAttribI3uivEXT(GLuint index, GLuint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI4bv
void VertexAttribI4bv(GLuint index, GLbyte v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI4bvEXT
void VertexAttribI4bvEXT(GLuint index, GLbyte v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI4i
void VertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI4iEXT
void VertexAttribI4iEXT(GLuint index, GLint x, GLint y, GLint z, GLint w) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI4iv
void VertexAttribI4iv(GLuint index, GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI4ivEXT
void VertexAttribI4ivEXT(GLuint index, GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI4sv
void VertexAttribI4sv(GLuint index, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI4svEXT
void VertexAttribI4svEXT(GLuint index, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI4ubv
void VertexAttribI4ubv(GLuint index, GLubyte v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI4ubvEXT
void VertexAttribI4ubvEXT(GLuint index, GLubyte v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI4ui
void VertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI4uiEXT
void VertexAttribI4uiEXT(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI4uiv
void VertexAttribI4uiv(GLuint index, GLuint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI4uivEXT
void VertexAttribI4uivEXT(GLuint index, GLuint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI4usv
void VertexAttribI4usv(GLuint index, GLushort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribI4usvEXT
void VertexAttribI4usvEXT(GLuint index, GLushort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribIFormat
void VertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribIFormatNV
void VertexAttribIFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribIPointer
void VertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribIPointerEXT
void VertexAttribIPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL1d
void VertexAttribL1d(GLuint index, GLdouble x) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL1dEXT
void VertexAttribL1dEXT(GLuint index, GLdouble x) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL1dv
void VertexAttribL1dv(GLuint index, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL1dvEXT
void VertexAttribL1dvEXT(GLuint index, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL1i64NV
void VertexAttribL1i64NV(GLuint index, GLint64EXT x) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL1i64vNV
void VertexAttribL1i64vNV(GLuint index, GLint64EXT v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL1ui64NV
void VertexAttribL1ui64NV(GLuint index, GLuint64EXT x) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL1ui64vNV
void VertexAttribL1ui64vNV(GLuint index, GLuint64EXT v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL2d
void VertexAttribL2d(GLuint index, GLdouble x, GLdouble y) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL2dEXT
void VertexAttribL2dEXT(GLuint index, GLdouble x, GLdouble y) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL2dv
void VertexAttribL2dv(GLuint index, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL2dvEXT
void VertexAttribL2dvEXT(GLuint index, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL2i64NV
void VertexAttribL2i64NV(GLuint index, GLint64EXT x, GLint64EXT y) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL2i64vNV
void VertexAttribL2i64vNV(GLuint index, GLint64EXT v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL2ui64NV
void VertexAttribL2ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL2ui64vNV
void VertexAttribL2ui64vNV(GLuint index, GLuint64EXT v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL3d
void VertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL3dEXT
void VertexAttribL3dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL3dv
void VertexAttribL3dv(GLuint index, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL3dvEXT
void VertexAttribL3dvEXT(GLuint index, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL3i64NV
void VertexAttribL3i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL3i64vNV
void VertexAttribL3i64vNV(GLuint index, GLint64EXT v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL3ui64NV
void VertexAttribL3ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL3ui64vNV
void VertexAttribL3ui64vNV(GLuint index, GLuint64EXT v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL4d
void VertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL4dEXT
void VertexAttribL4dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL4dv
void VertexAttribL4dv(GLuint index, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL4dvEXT
void VertexAttribL4dvEXT(GLuint index, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL4i64NV
void VertexAttribL4i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL4i64vNV
void VertexAttribL4i64vNV(GLuint index, GLint64EXT v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL4ui64NV
void VertexAttribL4ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribL4ui64vNV
void VertexAttribL4ui64vNV(GLuint index, GLuint64EXT v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribLFormat
void VertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribLFormatNV
void VertexAttribLFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribLPointer
void VertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribLPointerEXT
void VertexAttribLPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribP1ui
void VertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribP1uiv
void VertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribP2ui
void VertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribP2uiv
void VertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribP3ui
void VertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribP3uiv
void VertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribP4ui
void VertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribP4uiv
void VertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribPointer
void VertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribPointerARB
void VertexAttribPointerARB(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribPointerNV
void VertexAttribPointerNV(GLuint index, GLint fsize, GLenum type, GLsizei stride, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribs1dvNV
void VertexAttribs1dvNV(GLuint index, GLsizei count, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribs1fvNV
void VertexAttribs1fvNV(GLuint index, GLsizei count, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribs1hvNV
void VertexAttribs1hvNV(GLuint index, GLsizei n, GLhalfNV v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribs1svNV
void VertexAttribs1svNV(GLuint index, GLsizei count, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribs2dvNV
void VertexAttribs2dvNV(GLuint index, GLsizei count, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribs2fvNV
void VertexAttribs2fvNV(GLuint index, GLsizei count, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribs2hvNV
void VertexAttribs2hvNV(GLuint index, GLsizei n, GLhalfNV v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribs2svNV
void VertexAttribs2svNV(GLuint index, GLsizei count, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribs3dvNV
void VertexAttribs3dvNV(GLuint index, GLsizei count, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribs3fvNV
void VertexAttribs3fvNV(GLuint index, GLsizei count, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribs3hvNV
void VertexAttribs3hvNV(GLuint index, GLsizei n, GLhalfNV v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribs3svNV
void VertexAttribs3svNV(GLuint index, GLsizei count, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribs4dvNV
void VertexAttribs4dvNV(GLuint index, GLsizei count, GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribs4fvNV
void VertexAttribs4fvNV(GLuint index, GLsizei count, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribs4hvNV
void VertexAttribs4hvNV(GLuint index, GLsizei n, GLhalfNV v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribs4svNV
void VertexAttribs4svNV(GLuint index, GLsizei count, GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexAttribs4ubvNV
void VertexAttribs4ubvNV(GLuint index, GLsizei count, GLubyte v) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexBindingDivisor
void VertexBindingDivisor(GLuint bindingindex, GLuint divisor) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexBlendARB
void VertexBlendARB(GLint count) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexBlendEnvfATI
void VertexBlendEnvfATI(GLenum pname, GLfloat param) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexBlendEnviATI
void VertexBlendEnviATI(GLenum pname, GLint param) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexFormatNV
void VertexFormatNV(GLint size, GLenum type, GLsizei stride) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexP2ui
void VertexP2ui(GLenum type, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexP2uiv
void VertexP2uiv(GLenum type, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexP3ui
void VertexP3ui(GLenum type, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexP3uiv
void VertexP3uiv(GLenum type, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexP4ui
void VertexP4ui(GLenum type, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexP4uiv
void VertexP4uiv(GLenum type, GLuint value) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexPointer
void VertexPointer(GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexPointerEXT
void VertexPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexPointerListIBM
void VertexPointerListIBM(GLint size, GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexPointervINTEL
void VertexPointervINTEL(GLint size, GLenum type, GLvoid * pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream1dATI
void VertexStream1dATI(GLenum stream, GLdouble x) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream1dvATI
void VertexStream1dvATI(GLenum stream, GLdouble coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream1fATI
void VertexStream1fATI(GLenum stream, GLfloat x) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream1fvATI
void VertexStream1fvATI(GLenum stream, GLfloat coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream1iATI
void VertexStream1iATI(GLenum stream, GLint x) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream1ivATI
void VertexStream1ivATI(GLenum stream, GLint coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream1sATI
void VertexStream1sATI(GLenum stream, GLshort x) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream1svATI
void VertexStream1svATI(GLenum stream, GLshort coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream2dATI
void VertexStream2dATI(GLenum stream, GLdouble x, GLdouble y) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream2dvATI
void VertexStream2dvATI(GLenum stream, GLdouble coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream2fATI
void VertexStream2fATI(GLenum stream, GLfloat x, GLfloat y) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream2fvATI
void VertexStream2fvATI(GLenum stream, GLfloat coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream2iATI
void VertexStream2iATI(GLenum stream, GLint x, GLint y) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream2ivATI
void VertexStream2ivATI(GLenum stream, GLint coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream2sATI
void VertexStream2sATI(GLenum stream, GLshort x, GLshort y) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream2svATI
void VertexStream2svATI(GLenum stream, GLshort coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream3dATI
void VertexStream3dATI(GLenum stream, GLdouble x, GLdouble y, GLdouble z) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream3dvATI
void VertexStream3dvATI(GLenum stream, GLdouble coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream3fATI
void VertexStream3fATI(GLenum stream, GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream3fvATI
void VertexStream3fvATI(GLenum stream, GLfloat coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream3iATI
void VertexStream3iATI(GLenum stream, GLint x, GLint y, GLint z) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream3ivATI
void VertexStream3ivATI(GLenum stream, GLint coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream3sATI
void VertexStream3sATI(GLenum stream, GLshort x, GLshort y, GLshort z) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream3svATI
void VertexStream3svATI(GLenum stream, GLshort coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream4dATI
void VertexStream4dATI(GLenum stream, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream4dvATI
void VertexStream4dvATI(GLenum stream, GLdouble coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream4fATI
void VertexStream4fATI(GLenum stream, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream4fvATI
void VertexStream4fvATI(GLenum stream, GLfloat coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream4iATI
void VertexStream4iATI(GLenum stream, GLint x, GLint y, GLint z, GLint w) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream4ivATI
void VertexStream4ivATI(GLenum stream, GLint coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream4sATI
void VertexStream4sATI(GLenum stream, GLshort x, GLshort y, GLshort z, GLshort w) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexStream4svATI
void VertexStream4svATI(GLenum stream, GLshort coords) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexWeightPointerEXT
void VertexWeightPointerEXT(GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexWeightfEXT
void VertexWeightfEXT(GLfloat weight) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexWeightfvEXT
void VertexWeightfvEXT(GLfloat weight) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexWeighthNV
void VertexWeighthNV(GLhalfNV weight) {
    
printf(gl.c);
}
#endif

#ifndef skip_VertexWeighthvNV
void VertexWeighthvNV(GLhalfNV weight) {
    
printf(gl.c);
}
#endif

#ifndef skip_VideoCaptureNV
GLenum VideoCaptureNV(GLuint video_capture_slot, GLuint sequence_num, GLuint64EXT capture_time) {
    
printf(gl.c);
}
#endif

#ifndef skip_VideoCaptureStreamParameterdvNV
void VideoCaptureStreamParameterdvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble params) {
    
printf(gl.c);
}
#endif

#ifndef skip_VideoCaptureStreamParameterfvNV
void VideoCaptureStreamParameterfvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat params) {
    
printf(gl.c);
}
#endif

#ifndef skip_VideoCaptureStreamParameterivNV
void VideoCaptureStreamParameterivNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLint params) {
    
printf(gl.c);
}
#endif

#ifndef skip_Viewport
void Viewport(GLint x, GLint y, GLsizei width, GLsizei height) {
    
printf(gl.c);
}
#endif

#ifndef skip_ViewportArrayv
void ViewportArrayv(GLuint first, GLsizei count, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_ViewportIndexedf
void ViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h) {
    
printf(gl.c);
}
#endif

#ifndef skip_ViewportIndexedfv
void ViewportIndexedfv(GLuint index, GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WaitSync
void WaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) {
    
printf(gl.c);
}
#endif

#ifndef skip_WeightPathsNV
void WeightPathsNV(GLuint resultPath, GLsizei numPaths, GLuint paths, GLfloat weights) {
    
printf(gl.c);
}
#endif

#ifndef skip_WeightPointerARB
void WeightPointerARB(GLint size, GLenum type, GLsizei stride, GLvoid pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_WeightbvARB
void WeightbvARB(GLint size, GLbyte weights) {
    
printf(gl.c);
}
#endif

#ifndef skip_WeightdvARB
void WeightdvARB(GLint size, GLdouble weights) {
    
printf(gl.c);
}
#endif

#ifndef skip_WeightfvARB
void WeightfvARB(GLint size, GLfloat weights) {
    
printf(gl.c);
}
#endif

#ifndef skip_WeightivARB
void WeightivARB(GLint size, GLint weights) {
    
printf(gl.c);
}
#endif

#ifndef skip_WeightsvARB
void WeightsvARB(GLint size, GLshort weights) {
    
printf(gl.c);
}
#endif

#ifndef skip_WeightubvARB
void WeightubvARB(GLint size, GLubyte weights) {
    
printf(gl.c);
}
#endif

#ifndef skip_WeightuivARB
void WeightuivARB(GLint size, GLuint weights) {
    
printf(gl.c);
}
#endif

#ifndef skip_WeightusvARB
void WeightusvARB(GLint size, GLushort weights) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos2d
void WindowPos2d(GLdouble x, GLdouble y) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos2dARB
void WindowPos2dARB(GLdouble x, GLdouble y) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos2dMESA
void WindowPos2dMESA(GLdouble x, GLdouble y) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos2dv
void WindowPos2dv(GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos2dvARB
void WindowPos2dvARB(GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos2dvMESA
void WindowPos2dvMESA(GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos2f
void WindowPos2f(GLfloat x, GLfloat y) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos2fARB
void WindowPos2fARB(GLfloat x, GLfloat y) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos2fMESA
void WindowPos2fMESA(GLfloat x, GLfloat y) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos2fv
void WindowPos2fv(GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos2fvARB
void WindowPos2fvARB(GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos2fvMESA
void WindowPos2fvMESA(GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos2i
void WindowPos2i(GLint x, GLint y) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos2iARB
void WindowPos2iARB(GLint x, GLint y) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos2iMESA
void WindowPos2iMESA(GLint x, GLint y) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos2iv
void WindowPos2iv(GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos2ivARB
void WindowPos2ivARB(GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos2ivMESA
void WindowPos2ivMESA(GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos2s
void WindowPos2s(GLshort x, GLshort y) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos2sARB
void WindowPos2sARB(GLshort x, GLshort y) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos2sMESA
void WindowPos2sMESA(GLshort x, GLshort y) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos2sv
void WindowPos2sv(GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos2svARB
void WindowPos2svARB(GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos2svMESA
void WindowPos2svMESA(GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos3d
void WindowPos3d(GLdouble x, GLdouble y, GLdouble z) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos3dARB
void WindowPos3dARB(GLdouble x, GLdouble y, GLdouble z) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos3dMESA
void WindowPos3dMESA(GLdouble x, GLdouble y, GLdouble z) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos3dv
void WindowPos3dv(GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos3dvARB
void WindowPos3dvARB(GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos3dvMESA
void WindowPos3dvMESA(GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos3f
void WindowPos3f(GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos3fARB
void WindowPos3fARB(GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos3fMESA
void WindowPos3fMESA(GLfloat x, GLfloat y, GLfloat z) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos3fv
void WindowPos3fv(GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos3fvARB
void WindowPos3fvARB(GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos3fvMESA
void WindowPos3fvMESA(GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos3i
void WindowPos3i(GLint x, GLint y, GLint z) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos3iARB
void WindowPos3iARB(GLint x, GLint y, GLint z) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos3iMESA
void WindowPos3iMESA(GLint x, GLint y, GLint z) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos3iv
void WindowPos3iv(GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos3ivARB
void WindowPos3ivARB(GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos3ivMESA
void WindowPos3ivMESA(GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos3s
void WindowPos3s(GLshort x, GLshort y, GLshort z) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos3sARB
void WindowPos3sARB(GLshort x, GLshort y, GLshort z) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos3sMESA
void WindowPos3sMESA(GLshort x, GLshort y, GLshort z) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos3sv
void WindowPos3sv(GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos3svARB
void WindowPos3svARB(GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos3svMESA
void WindowPos3svMESA(GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos4dMESA
void WindowPos4dMESA(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos4dvMESA
void WindowPos4dvMESA(GLdouble v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos4fMESA
void WindowPos4fMESA(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos4fvMESA
void WindowPos4fvMESA(GLfloat v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos4iMESA
void WindowPos4iMESA(GLint x, GLint y, GLint z, GLint w) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos4ivMESA
void WindowPos4ivMESA(GLint v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos4sMESA
void WindowPos4sMESA(GLshort x, GLshort y, GLshort z, GLshort w) {
    
printf(gl.c);
}
#endif

#ifndef skip_WindowPos4svMESA
void WindowPos4svMESA(GLshort v) {
    
printf(gl.c);
}
#endif

#ifndef skip_WriteMaskEXT
void WriteMaskEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW) {
    
printf(gl.c);
}
#endif

#ifndef skip_AssociateDMPbufferSGIX
Bool AssociateDMPbufferSGIX(Display dpy, GLXPbufferSGIX pbuffer, DMparams params, DMbuffer dmbuffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindChannelToWindowSGIX
int BindChannelToWindowSGIX(Display display, int screen, int channel, Window window) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindHyperpipeSGIX
int BindHyperpipeSGIX(Display dpy, int hpId) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindSwapBarrierNV
Bool BindSwapBarrierNV(Display dpy, GLuint group, GLuint barrier) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindSwapBarrierSGIX
void BindSwapBarrierSGIX(Display dpy, GLXDrawable drawable, int barrier) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindTexImageEXT
void BindTexImageEXT(Display dpy, GLXDrawable drawable, int buffer, int attrib_list) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindVideoCaptureDeviceNV
int BindVideoCaptureDeviceNV(Display dpy, unsigned int video_capture_slot, GLXVideoCaptureDeviceNV device) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindVideoDeviceNV
int BindVideoDeviceNV(Display dpy, unsigned int video_slot, unsigned int video_device, int attrib_list) {
    
printf(gl.c);
}
#endif

#ifndef skip_BindVideoImageNV
int BindVideoImageNV(Display dpy, GLXVideoDeviceNV VideoDevice, GLXPbuffer pbuf, int iVideoBuffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_ChannelRectSGIX
int ChannelRectSGIX(Display display, int screen, int channel, int x, int y, int w, int h) {
    
printf(gl.c);
}
#endif

#ifndef skip_ChannelRectSyncSGIX
int ChannelRectSyncSGIX(Display display, int screen, int channel, GLenum synctype) {
    
printf(gl.c);
}
#endif

#ifndef skip_ChooseFBConfig
GLXFBConfigPointer ChooseFBConfig(Display dpy, int screen, int attrib_list, int nelements) {
    
printf(gl.c);
}
#endif

#ifndef skip_ChooseFBConfigSGIX
GLXFBConfigSGIXPointer ChooseFBConfigSGIX(Display dpy, int screen, int attrib_list, int nelements) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopyImageSubDataNV
void CopyImageSubDataNV(Display dpy, GLXContext srcCtx, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLXContext dstCtx, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth) {
    
printf(gl.c);
}
#endif

#ifndef skip_CopySubBufferMESA
void CopySubBufferMESA(Display dpy, GLXDrawable drawable, int x, int y, int width, int height) {
    
printf(gl.c);
}
#endif

#ifndef skip_CreateContextAttribsARB
GLXContext CreateContextAttribsARB(Display dpy, GLXFBConfig config, GLXContext share_context, Bool direct, int attrib_list) {
    
printf(gl.c);
}
#endif

#ifndef skip_CreateContextWithConfigSGIX
GLXContext CreateContextWithConfigSGIX(Display dpy, GLXFBConfigSGIX config, int render_type, GLXContext share_list, Bool direct) {
    
printf(gl.c);
}
#endif

#ifndef skip_CreateGLXPbufferSGIX
GLXPbufferSGIX CreateGLXPbufferSGIX(Display dpy, GLXFBConfigSGIX config, unsigned int width, unsigned int height, int attrib_list) {
    
printf(gl.c);
}
#endif

#ifndef skip_CreateGLXPixmapMESA
GLXPixmap CreateGLXPixmapMESA(Display dpy, XVisualInfo visual, Pixmap pixmap, Colormap cmap) {
    
printf(gl.c);
}
#endif

#ifndef skip_CreateGLXPixmapWithConfigSGIX
GLXPixmap CreateGLXPixmapWithConfigSGIX(Display dpy, GLXFBConfigSGIX config, Pixmap pixmap) {
    
printf(gl.c);
}
#endif

#ifndef skip_CreateGLXVideoSourceSGIX
GLXVideoSourceSGIX CreateGLXVideoSourceSGIX(Display display, int screen, VLServer server, VLPath path, int nodeClass, VLNode drainNode) {
    
printf(gl.c);
}
#endif

#ifndef skip_CreateNewContext
GLXContext CreateNewContext(Display dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct) {
    
printf(gl.c);
}
#endif

#ifndef skip_CreatePbuffer
GLXPbuffer CreatePbuffer(Display dpy, GLXFBConfig config, int attrib_list) {
    
printf(gl.c);
}
#endif

#ifndef skip_CreatePixmap
GLXPixmap CreatePixmap(Display dpy, GLXFBConfig config, Pixmap pixmap, int attrib_list) {
    
printf(gl.c);
}
#endif

#ifndef skip_CreateWindow
GLXWindow CreateWindow(Display dpy, GLXFBConfig config, Window win, int attrib_list) {
    
printf(gl.c);
}
#endif

#ifndef skip_CushionSGI
void CushionSGI(Display dpy, Window window, float cushion) {
    
printf(gl.c);
}
#endif

#ifndef skip_DestroyGLXPbufferSGIX
void DestroyGLXPbufferSGIX(Display dpy, GLXPbufferSGIX pbuf) {
    
printf(gl.c);
}
#endif

#ifndef skip_DestroyGLXVideoSourceSGIX
void DestroyGLXVideoSourceSGIX(Display dpy, GLXVideoSourceSGIX glxvideosource) {
    
printf(gl.c);
}
#endif

#ifndef skip_DestroyHyperpipeConfigSGIX
int DestroyHyperpipeConfigSGIX(Display dpy, int hpId) {
    
printf(gl.c);
}
#endif

#ifndef skip_DestroyPbuffer
void DestroyPbuffer(Display dpy, GLXPbuffer pbuf) {
    
printf(gl.c);
}
#endif

#ifndef skip_DestroyPixmap
void DestroyPixmap(Display dpy, GLXPixmap pixmap) {
    
printf(gl.c);
}
#endif

#ifndef skip_DestroyWindow
void DestroyWindow(Display dpy, GLXWindow win) {
    
printf(gl.c);
}
#endif

#ifndef skip_EnumerateVideoCaptureDevicesNV
GLXVideoCaptureDeviceNVPointer EnumerateVideoCaptureDevicesNV(Display dpy, int screen, int nelements) {
    
printf(gl.c);
}
#endif

#ifndef skip_EnumerateVideoDevicesNV
uintPointer EnumerateVideoDevicesNV(Display dpy, int screen, int nelements) {
    
printf(gl.c);
}
#endif

#ifndef skip_FreeContextEXT
void FreeContextEXT(Display dpy, GLXContext context) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetAGPOffsetMESA
uint GetAGPOffsetMESA(void pointer) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetContextIDEXT
GLXContextID GetContextIDEXT(const GLXContext context) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetCurrentDisplay
DisplayPointer GetCurrentDisplay() {
    
printf(gl.c);
}
#endif

#ifndef skip_GetCurrentDisplayEXT
DisplayPointer GetCurrentDisplayEXT() {
    
printf(gl.c);
}
#endif

#ifndef skip_GetCurrentReadDrawable
GLXDrawable GetCurrentReadDrawable() {
    
printf(gl.c);
}
#endif

#ifndef skip_GetCurrentReadDrawableSGI
GLXDrawable GetCurrentReadDrawableSGI() {
    
printf(gl.c);
}
#endif

#ifndef skip_GetFBConfigAttrib
int GetFBConfigAttrib(Display dpy, GLXFBConfig config, int attribute, int value) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetFBConfigAttribSGIX
int GetFBConfigAttribSGIX(Display dpy, GLXFBConfigSGIX config, int attribute, int value) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetFBConfigFromVisualSGIX
GLXFBConfigSGIX GetFBConfigFromVisualSGIX(Display dpy, XVisualInfo vis) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetFBConfigs
GLXFBConfigPointer GetFBConfigs(Display dpy, int screen, int nelements) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetMscRateOML
Bool GetMscRateOML(Display dpy, GLXDrawable drawable, int32_t numerator, int32_t denominator) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProcAddress
FunctionPointer GetProcAddress(GLubyte procName) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetProcAddressARB
FunctionPointer GetProcAddressARB(GLubyte procName) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetSelectedEvent
void GetSelectedEvent(Display dpy, GLXDrawable draw, unsigned long event_mask) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetSelectedEventSGIX
void GetSelectedEventSGIX(Display dpy, GLXDrawable drawable, unsigned long mask) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetSyncValuesOML
Bool GetSyncValuesOML(Display dpy, GLXDrawable drawable, int64_t ust, int64_t msc, int64_t sbc) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetTransparentIndexSUN
Status GetTransparentIndexSUN(Display dpy, Window overlay, Window underlay, long pTransparentIndex) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVideoDeviceNV
int GetVideoDeviceNV(Display dpy, int screen, int numVideoDevices, GLXVideoDeviceNV pVideoDevice) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVideoInfoNV
int GetVideoInfoNV(Display dpy, int screen, GLXVideoDeviceNV VideoDevice, unsigned long pulCounterOutputPbuffer, unsigned long pulCounterOutputVideo) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVideoSyncSGI
int GetVideoSyncSGI(unsigned int count) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVisualFromFBConfig
XVisualInfoPointer GetVisualFromFBConfig(Display dpy, GLXFBConfig config) {
    
printf(gl.c);
}
#endif

#ifndef skip_GetVisualFromFBConfigSGIX
XVisualInfoPointer GetVisualFromFBConfigSGIX(Display dpy, GLXFBConfigSGIX config) {
    
printf(gl.c);
}
#endif

#ifndef skip_HyperpipeAttribSGIX
int HyperpipeAttribSGIX(Display dpy, int timeSlice, int attrib, int size, void attribList) {
    
printf(gl.c);
}
#endif

#ifndef skip_HyperpipeConfigSGIX
int HyperpipeConfigSGIX(Display dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX cfg, int hpId) {
    
printf(gl.c);
}
#endif

#ifndef skip_ImportContextEXT
GLXContext ImportContextEXT(Display dpy, GLXContextID contextID) {
    
printf(gl.c);
}
#endif

#ifndef skip_JoinSwapGroupNV
Bool JoinSwapGroupNV(Display dpy, GLXDrawable drawable, GLuint group) {
    
printf(gl.c);
}
#endif

#ifndef skip_JoinSwapGroupSGIX
void JoinSwapGroupSGIX(Display dpy, GLXDrawable drawable, GLXDrawable member) {
    
printf(gl.c);
}
#endif

#ifndef skip_LockVideoCaptureDeviceNV
void LockVideoCaptureDeviceNV(Display dpy, GLXVideoCaptureDeviceNV device) {
    
printf(gl.c);
}
#endif

#ifndef skip_MakeContextCurrent
Bool MakeContextCurrent(Display dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx) {
    
printf(gl.c);
}
#endif

#ifndef skip_MakeCurrentReadSGI
Bool MakeCurrentReadSGI(Display dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx) {
    
printf(gl.c);
}
#endif

#ifndef skip_QueryChannelDeltasSGIX
int QueryChannelDeltasSGIX(Display display, int screen, int channel, int x, int y, int w, int h) {
    
printf(gl.c);
}
#endif

#ifndef skip_QueryChannelRectSGIX
int QueryChannelRectSGIX(Display display, int screen, int channel, int dx, int dy, int dw, int dh) {
    
printf(gl.c);
}
#endif

#ifndef skip_QueryContext
int QueryContext(Display dpy, GLXContext ctx, int attribute, int value) {
    
printf(gl.c);
}
#endif

#ifndef skip_QueryContextInfoEXT
int QueryContextInfoEXT(Display dpy, GLXContext context, int attribute, int value) {
    
printf(gl.c);
}
#endif

#ifndef skip_QueryDrawable
void QueryDrawable(Display dpy, GLXDrawable draw, int attribute, unsigned int value) {
    
printf(gl.c);
}
#endif

#ifndef skip_QueryFrameCountNV
Bool QueryFrameCountNV(Display dpy, int screen, GLuint count) {
    
printf(gl.c);
}
#endif

#ifndef skip_QueryGLXPbufferSGIX
int QueryGLXPbufferSGIX(Display dpy, GLXPbufferSGIX pbuf, int attribute, unsigned int value) {
    
printf(gl.c);
}
#endif

#ifndef skip_QueryHyperpipeAttribSGIX
int QueryHyperpipeAttribSGIX(Display dpy, int timeSlice, int attrib, int size, void returnAttribList) {
    
printf(gl.c);
}
#endif

#ifndef skip_QueryHyperpipeBestAttribSGIX
int QueryHyperpipeBestAttribSGIX(Display dpy, int timeSlice, int attrib, int size, void attribList, void returnAttribList) {
    
printf(gl.c);
}
#endif

#ifndef skip_QueryHyperpipeConfigSGIX
GLXHyperpipeConfigSGIXPointer QueryHyperpipeConfigSGIX(Display dpy, int hpId, int npipes) {
    
printf(gl.c);
}
#endif

#ifndef skip_QueryHyperpipeNetworkSGIX
GLXHyperpipeNetworkSGIXPointer QueryHyperpipeNetworkSGIX(Display dpy, int npipes) {
    
printf(gl.c);
}
#endif

#ifndef skip_QueryMaxSwapBarriersSGIX
Bool QueryMaxSwapBarriersSGIX(Display dpy, int screen, int max) {
    
printf(gl.c);
}
#endif

#ifndef skip_QueryMaxSwapGroupsNV
Bool QueryMaxSwapGroupsNV(Display dpy, int screen, GLuint maxGroups, GLuint maxBarriers) {
    
printf(gl.c);
}
#endif

#ifndef skip_QuerySwapGroupNV
Bool QuerySwapGroupNV(Display dpy, GLXDrawable drawable, GLuint group, GLuint barrier) {
    
printf(gl.c);
}
#endif

#ifndef skip_QueryVideoCaptureDeviceNV
int QueryVideoCaptureDeviceNV(Display dpy, GLXVideoCaptureDeviceNV device, int attribute, int value) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReleaseBuffersMESA
Bool ReleaseBuffersMESA(Display dpy, GLXDrawable drawable) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReleaseTexImageEXT
void ReleaseTexImageEXT(Display dpy, GLXDrawable drawable, int buffer) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReleaseVideoCaptureDeviceNV
void ReleaseVideoCaptureDeviceNV(Display dpy, GLXVideoCaptureDeviceNV device) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReleaseVideoDeviceNV
int ReleaseVideoDeviceNV(Display dpy, int screen, GLXVideoDeviceNV VideoDevice) {
    
printf(gl.c);
}
#endif

#ifndef skip_ReleaseVideoImageNV
int ReleaseVideoImageNV(Display dpy, GLXPbuffer pbuf) {
    
printf(gl.c);
}
#endif

#ifndef skip_ResetFrameCountNV
Bool ResetFrameCountNV(Display dpy, int screen) {
    
printf(gl.c);
}
#endif

#ifndef skip_SelectEvent
void SelectEvent(Display dpy, GLXDrawable draw, unsigned long event_mask) {
    
printf(gl.c);
}
#endif

#ifndef skip_SelectEventSGIX
void SelectEventSGIX(Display dpy, GLXDrawable drawable, unsigned long mask) {
    
printf(gl.c);
}
#endif

#ifndef skip_SendPbufferToVideoNV
int SendPbufferToVideoNV(Display dpy, GLXPbuffer pbuf, int iBufferType, unsigned long pulCounterPbuffer, GLboolean bBlock) {
    
printf(gl.c);
}
#endif

#ifndef skip_Set3DfxModeMESA
Bool Set3DfxModeMESA(int mode) {
    
printf(gl.c);
}
#endif

#ifndef skip_SwapBuffersMscOML
int64_t SwapBuffersMscOML(Display dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder) {
    
printf(gl.c);
}
#endif

#ifndef skip_SwapIntervalEXT
void SwapIntervalEXT(Display dpy, GLXDrawable drawable, int interval) {
    
printf(gl.c);
}
#endif

#ifndef skip_SwapIntervalSGI
int SwapIntervalSGI(int interval) {
    
printf(gl.c);
}
#endif

#ifndef skip_WaitForMscOML
Bool WaitForMscOML(Display dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder, int64_t ust, int64_t msc, int64_t sbc) {
    
printf(gl.c);
}
#endif

#ifndef skip_WaitForSbcOML
Bool WaitForSbcOML(Display dpy, GLXDrawable drawable, int64_t target_sbc, int64_t ust, int64_t msc, int64_t sbc) {
    
printf(gl.c);
}
#endif

#ifndef skip_WaitVideoSyncSGI
int WaitVideoSyncSGI(int divisor, int remainder, unsigned int count) {
    
printf(gl.c);
}
#endif
