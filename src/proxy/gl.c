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
        case FORMAT_void_GLenum: {
            PACKED_void_GLenum *unpacked = (PACKED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_GLboolean_GLsizei_const_GLuint___GENPT___GLboolean___GENPT__: {
            PACKED_GLboolean_GLsizei_const_GLuint___GENPT___GLboolean___GENPT__ *unpacked = (PACKED_GLboolean_GLsizei_const_GLuint___GENPT___GLboolean___GENPT__ *)packed;
            ARGS_GLboolean_GLsizei_const_GLuint___GENPT___GLboolean___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLint: {
            PACKED_void_GLint *unpacked = (PACKED_void_GLint *)packed;
            ARGS_void_GLint args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLenum_GLuint: {
            PACKED_void_GLenum_GLuint *unpacked = (PACKED_void_GLenum_GLuint *)packed;
            ARGS_void_GLenum_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_const_GLubyte___GENPT__: {
            PACKED_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_const_GLubyte___GENPT__ *unpacked = (PACKED_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_const_GLubyte___GENPT__ *)packed;
            ARGS_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_const_GLubyte___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLenum: {
            PACKED_void_GLenum_GLenum *unpacked = (PACKED_void_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLenum: {
            PACKED_void_GLenum_GLenum_GLenum_GLenum *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum: {
            PACKED_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum *unpacked = (PACKED_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum *)packed;
            ARGS_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint: {
            PACKED_void_GLuint *unpacked = (PACKED_void_GLuint *)packed;
            ARGS_void_GLuint args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLsizei_GLenum_const_GLvoid___GENPT__: {
            PACKED_void_GLsizei_GLenum_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLsizei_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLsizei_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLbitfield: {
            PACKED_void_GLbitfield *unpacked = (PACKED_void_GLbitfield *)packed;
            ARGS_void_GLbitfield args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLdouble: {
            PACKED_void_GLdouble *unpacked = (PACKED_void_GLdouble *)packed;
            ARGS_void_GLdouble args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLfloat: {
            PACKED_void_GLfloat *unpacked = (PACKED_void_GLfloat *)packed;
            ARGS_void_GLfloat args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLenum_const_GLdouble___GENPT__: {
            PACKED_void_GLenum_const_GLdouble___GENPT__ *unpacked = (PACKED_void_GLenum_const_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLdouble___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLbyte_GLbyte_GLbyte: {
            PACKED_void_GLbyte_GLbyte_GLbyte *unpacked = (PACKED_void_GLbyte_GLbyte_GLbyte *)packed;
            ARGS_void_GLbyte_GLbyte_GLbyte args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_const_GLbyte___GENPT__: {
            PACKED_void_const_GLbyte___GENPT__ *unpacked = (PACKED_void_const_GLbyte___GENPT__ *)packed;
            ARGS_void_const_GLbyte___GENPT__ args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLdouble_GLdouble_GLdouble: {
            PACKED_void_GLdouble_GLdouble_GLdouble *unpacked = (PACKED_void_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_const_GLdouble___GENPT__: {
            PACKED_void_const_GLdouble___GENPT__ *unpacked = (PACKED_void_const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT__ args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_const_GLfloat___GENPT__: {
            PACKED_void_const_GLfloat___GENPT__ *unpacked = (PACKED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLint_GLint_GLint: {
            PACKED_void_GLint_GLint_GLint *unpacked = (PACKED_void_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_const_GLint___GENPT__: {
            PACKED_void_const_GLint___GENPT__ *unpacked = (PACKED_void_const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLshort_GLshort_GLshort: {
            PACKED_void_GLshort_GLshort_GLshort *unpacked = (PACKED_void_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort_GLshort args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_const_GLshort___GENPT__: {
            PACKED_void_const_GLshort___GENPT__ *unpacked = (PACKED_void_const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT__ args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLubyte_GLubyte_GLubyte: {
            PACKED_void_GLubyte_GLubyte_GLubyte *unpacked = (PACKED_void_GLubyte_GLubyte_GLubyte *)packed;
            ARGS_void_GLubyte_GLubyte_GLubyte args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_const_GLubyte___GENPT__: {
            PACKED_void_const_GLubyte___GENPT__ *unpacked = (PACKED_void_const_GLubyte___GENPT__ *)packed;
            ARGS_void_const_GLubyte___GENPT__ args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLuint: {
            PACKED_void_GLuint_GLuint_GLuint *unpacked = (PACKED_void_GLuint_GLuint_GLuint *)packed;
            ARGS_void_GLuint_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_const_GLuint___GENPT__: {
            PACKED_void_const_GLuint___GENPT__ *unpacked = (PACKED_void_const_GLuint___GENPT__ *)packed;
            ARGS_void_const_GLuint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLushort_GLushort_GLushort: {
            PACKED_void_GLushort_GLushort_GLushort *unpacked = (PACKED_void_GLushort_GLushort_GLushort *)packed;
            ARGS_void_GLushort_GLushort_GLushort args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_const_GLushort___GENPT__: {
            PACKED_void_const_GLushort___GENPT__ *unpacked = (PACKED_void_const_GLushort___GENPT__ *)packed;
            ARGS_void_const_GLushort___GENPT__ args = unpacked->args;
            unpacked->func(args.a1);
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
        case FORMAT_void_GLint_GLint_GLint_GLint: {
            PACKED_void_GLint_GLint_GLint_GLint *unpacked = (PACKED_void_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint_GLint args = unpacked->args;
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
        case FORMAT_void_GLuint_GLuint_GLuint_GLuint: {
            PACKED_void_GLuint_GLuint_GLuint_GLuint *unpacked = (PACKED_void_GLuint_GLuint_GLuint_GLuint *)packed;
            ARGS_void_GLuint_GLuint_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLushort_GLushort_GLushort_GLushort: {
            PACKED_void_GLushort_GLushort_GLushort_GLushort *unpacked = (PACKED_void_GLushort_GLushort_GLushort_GLushort *)packed;
            ARGS_void_GLushort_GLushort_GLushort_GLushort args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLboolean_GLboolean_GLboolean_GLboolean: {
            PACKED_void_GLboolean_GLboolean_GLboolean_GLboolean *unpacked = (PACKED_void_GLboolean_GLboolean_GLboolean_GLboolean *)packed;
            ARGS_void_GLboolean_GLboolean_GLboolean_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__: {
            PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__: {
            PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_const_GLint___GENPT__: {
            PACKED_void_GLenum_GLenum_const_GLint___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLfloat: {
            PACKED_void_GLenum_GLenum_GLfloat *unpacked = (PACKED_void_GLenum_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLenum_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint: {
            PACKED_void_GLenum_GLenum_GLint *unpacked = (PACKED_void_GLenum_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
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
        case FORMAT_void_GLsizei_const_GLuint___GENPT__: {
            PACKED_void_GLsizei_const_GLuint___GENPT__ *unpacked = (PACKED_void_GLsizei_const_GLuint___GENPT__ *)packed;
            ARGS_void_GLsizei_const_GLuint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLsizei: {
            PACKED_void_GLuint_GLsizei *unpacked = (PACKED_void_GLuint_GLsizei *)packed;
            ARGS_void_GLuint_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLboolean: {
            PACKED_void_GLboolean *unpacked = (PACKED_void_GLboolean *)packed;
            ARGS_void_GLboolean args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLdouble_GLdouble: {
            PACKED_void_GLdouble_GLdouble *unpacked = (PACKED_void_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLsizei: {
            PACKED_void_GLenum_GLint_GLsizei *unpacked = (PACKED_void_GLenum_GLint_GLsizei *)packed;
            ARGS_void_GLenum_GLint_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__: {
            PACKED_void_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLuint_GLuint_GLsizei_GLenum_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLuint_GLuint_GLsizei_GLenum_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLuint_GLuint_GLsizei_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLuint_GLuint_GLsizei_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLsizei_const_GLvoid___GENPT__: {
            PACKED_void_GLsizei_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_const_GLboolean___GENPT__: {
            PACKED_void_const_GLboolean___GENPT__ *unpacked = (PACKED_void_const_GLboolean___GENPT__ *)packed;
            ARGS_void_const_GLboolean___GENPT__ args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void: {
            PACKED_void *unpacked = (PACKED_void *)packed;
            ARGS_void args = unpacked->args;
            unpacked->func();
            break;
        }
        case FORMAT_void_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint: {
            PACKED_void_GLenum_GLint_GLint *unpacked = (PACKED_void_GLenum_GLint_GLint *)packed;
            ARGS_void_GLenum_GLint_GLint args = unpacked->args;
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
        case FORMAT_void_GLsizei_GLenum_GLfloat___GENPT__: {
            PACKED_void_GLsizei_GLenum_GLfloat___GENPT__ *unpacked = (PACKED_void_GLsizei_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLsizei_GLenum_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_const_GLfloat___GENPT__: {
            PACKED_void_GLenum_const_GLfloat___GENPT__ *unpacked = (PACKED_void_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLint: {
            PACKED_void_GLenum_GLint *unpacked = (PACKED_void_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_const_GLint___GENPT__: {
            PACKED_void_GLenum_const_GLint___GENPT__ *unpacked = (PACKED_void_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble: {
            PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble *unpacked = (PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble *)packed;
            ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLsizei_GLuint___GENPT__: {
            PACKED_void_GLsizei_GLuint___GENPT__ *unpacked = (PACKED_void_GLsizei_GLuint___GENPT__ *)packed;
            ARGS_void_GLsizei_GLuint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_GLuint_GLsizei: {
            PACKED_GLuint_GLsizei *unpacked = (PACKED_GLuint_GLsizei *)packed;
            ARGS_GLuint_GLsizei args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLenum_GLboolean___GENPT__: {
            PACKED_void_GLenum_GLboolean___GENPT__ *unpacked = (PACKED_void_GLenum_GLboolean___GENPT__ *)packed;
            ARGS_void_GLenum_GLboolean___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint___GENPT__: {
            PACKED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLenum_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLintptr_GLsizeiptr_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLintptr_GLsizeiptr_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLintptr_GLsizeiptr_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLintptr_GLsizeiptr_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLdouble___GENPT__: {
            PACKED_void_GLenum_GLdouble___GENPT__ *unpacked = (PACKED_void_GLenum_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_GLdouble___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLenum_GLenum_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLfloat___GENPT__: {
            PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_GLenum: {
            PACKED_GLenum *unpacked = (PACKED_GLenum *)packed;
            ARGS_GLenum args = unpacked->args;
            unpacked->func();
            break;
        }
        case FORMAT_void_GLenum_GLfloat___GENPT__: {
            PACKED_void_GLenum_GLfloat___GENPT__ *unpacked = (PACKED_void_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLint___GENPT__: {
            PACKED_void_GLenum_GLint___GENPT__ *unpacked = (PACKED_void_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLdouble___GENPT__: {
            PACKED_void_GLenum_GLenum_GLdouble___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLdouble___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLuint___GENPT__: {
            PACKED_void_GLenum_GLuint___GENPT__ *unpacked = (PACKED_void_GLenum_GLuint___GENPT__ *)packed;
            ARGS_void_GLenum_GLuint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLushort___GENPT__: {
            PACKED_void_GLenum_GLushort___GENPT__ *unpacked = (PACKED_void_GLenum_GLushort___GENPT__ *)packed;
            ARGS_void_GLenum_GLushort___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLvoid___GENPT____GENPT__: {
            PACKED_void_GLenum_GLvoid___GENPT____GENPT__ *unpacked = (PACKED_void_GLenum_GLvoid___GENPT____GENPT__ *)packed;
            ARGS_void_GLenum_GLvoid___GENPT____GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLubyte___GENPT__: {
            PACKED_void_GLubyte___GENPT__ *unpacked = (PACKED_void_GLubyte___GENPT__ *)packed;
            ARGS_void_GLubyte___GENPT__ args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint___GENPT__: {
            PACKED_void_GLuint_GLenum_GLint___GENPT__ *unpacked = (PACKED_void_GLuint_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLuint_GLenum_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLuint___GENPT__: {
            PACKED_void_GLuint_GLenum_GLuint___GENPT__ *unpacked = (PACKED_void_GLuint_GLenum_GLuint___GENPT__ *)packed;
            ARGS_void_GLuint_GLenum_GLuint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLvoid___GENPT___GLvoid___GENPT___GLvoid___GENPT__: {
            PACKED_void_GLenum_GLenum_GLenum_GLvoid___GENPT___GLvoid___GENPT___GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLvoid___GENPT___GLvoid___GENPT___GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLvoid___GENPT___GLvoid___GENPT___GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_const_GLubyte___GENPT___GLenum: {
            PACKED_const_GLubyte___GENPT___GLenum *unpacked = (PACKED_const_GLubyte___GENPT___GLenum *)packed;
            ARGS_const_GLubyte___GENPT___GLenum args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLenum_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLenum_GLenum_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLenum_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLfloat___GENPT__: {
            PACKED_void_GLenum_GLint_GLenum_GLfloat___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLint___GENPT__: {
            PACKED_void_GLenum_GLint_GLenum_GLint___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_GLenum_GLboolean: {
            PACKED_void_GLenum_GLsizei_GLenum_GLboolean *unpacked = (PACKED_void_GLenum_GLsizei_GLenum_GLboolean *)packed;
            ARGS_void_GLenum_GLsizei_GLenum_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLshort: {
            PACKED_void_GLshort *unpacked = (PACKED_void_GLshort *)packed;
            ARGS_void_GLshort args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLubyte: {
            PACKED_void_GLubyte *unpacked = (PACKED_void_GLubyte *)packed;
            ARGS_void_GLubyte args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_GLboolean_GLuint: {
            PACKED_GLboolean_GLuint *unpacked = (PACKED_GLboolean_GLuint *)packed;
            ARGS_GLboolean_GLuint args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_GLboolean_GLenum: {
            PACKED_GLboolean_GLenum *unpacked = (PACKED_GLboolean_GLenum *)packed;
            ARGS_GLboolean_GLenum args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLint_GLushort: {
            PACKED_void_GLint_GLushort *unpacked = (PACKED_void_GLint_GLushort *)packed;
            ARGS_void_GLint_GLushort args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__: {
            PACKED_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ *unpacked = (PACKED_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__: {
            PACKED_void_GLenum_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ *unpacked = (PACKED_void_GLenum_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__: {
            PACKED_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ *unpacked = (PACKED_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        case FORMAT_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__: {
            PACKED_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ *unpacked = (PACKED_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        case FORMAT_GLvoid___GENPT___GLenum_GLenum: {
            PACKED_GLvoid___GENPT___GLenum_GLenum *unpacked = (PACKED_GLvoid___GENPT___GLenum_GLenum *)packed;
            ARGS_GLvoid___GENPT___GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2);
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
        case FORMAT_void_GLenum_GLenum_GLboolean: {
            PACKED_void_GLenum_GLenum_GLboolean *unpacked = (PACKED_void_GLenum_GLenum_GLboolean *)packed;
            ARGS_void_GLenum_GLenum_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei: {
            PACKED_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei *unpacked = (PACKED_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei *)packed;
            ARGS_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_const_GLsizei___GENPT___GLenum_GLvoid__GENPT__const___GENPT___GLsizei: {
            PACKED_void_GLenum_const_GLsizei___GENPT___GLenum_GLvoid__GENPT__const___GENPT___GLsizei *unpacked = (PACKED_void_GLenum_const_GLsizei___GENPT___GLenum_GLvoid__GENPT__const___GENPT___GLsizei *)packed;
            ARGS_void_GLenum_const_GLsizei___GENPT___GLenum_GLvoid__GENPT__const___GENPT___GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLdouble: {
            PACKED_void_GLenum_GLdouble *unpacked = (PACKED_void_GLenum_GLdouble *)packed;
            ARGS_void_GLenum_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLshort: {
            PACKED_void_GLenum_GLshort *unpacked = (PACKED_void_GLenum_GLshort *)packed;
            ARGS_void_GLenum_GLshort args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_const_GLshort___GENPT__: {
            PACKED_void_GLenum_const_GLshort___GENPT__ *unpacked = (PACKED_void_GLenum_const_GLshort___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLshort___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
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
        case FORMAT_void_GLenum_GLshort_GLshort: {
            PACKED_void_GLenum_GLshort_GLshort *unpacked = (PACKED_void_GLenum_GLshort_GLshort *)packed;
            ARGS_void_GLenum_GLshort_GLshort args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
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
        case FORMAT_void_GLenum_GLshort_GLshort_GLshort_GLshort: {
            PACKED_void_GLenum_GLshort_GLshort_GLshort_GLshort *unpacked = (PACKED_void_GLenum_GLshort_GLshort_GLshort_GLshort *)packed;
            ARGS_void_GLenum_GLshort_GLshort_GLshort_GLshort args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLenum: {
            PACKED_void_GLuint_GLenum *unpacked = (PACKED_void_GLuint_GLenum *)packed;
            ARGS_void_GLuint_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_const_GLfloat___GENPT__: {
            PACKED_void_GLenum_GLsizei_const_GLfloat___GENPT__ *unpacked = (PACKED_void_GLenum_GLsizei_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_const_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_const_GLuint___GENPT__: {
            PACKED_void_GLenum_GLsizei_const_GLuint___GENPT__ *unpacked = (PACKED_void_GLenum_GLsizei_const_GLuint___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_const_GLuint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_const_GLushort___GENPT__: {
            PACKED_void_GLenum_GLsizei_const_GLushort___GENPT__ *unpacked = (PACKED_void_GLenum_GLsizei_const_GLushort___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_const_GLushort___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLsizei_const_GLuint___GENPT___const_GLfloat___GENPT__: {
            PACKED_void_GLsizei_const_GLuint___GENPT___const_GLfloat___GENPT__ *unpacked = (PACKED_void_GLsizei_const_GLuint___GENPT___const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLsizei_const_GLuint___GENPT___const_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLshort_GLshort: {
            PACKED_void_GLshort_GLshort *unpacked = (PACKED_void_GLshort_GLshort *)packed;
            ARGS_void_GLshort_GLshort args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__: {
            PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ *unpacked = (PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_const_GLdouble___GENPT___const_GLdouble___GENPT__: {
            PACKED_void_const_GLdouble___GENPT___const_GLdouble___GENPT__ *unpacked = (PACKED_void_const_GLdouble___GENPT___const_GLdouble___GENPT__ *)packed;
            ARGS_void_const_GLdouble___GENPT___const_GLdouble___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_const_GLfloat___GENPT___const_GLfloat___GENPT__: {
            PACKED_void_const_GLfloat___GENPT___const_GLfloat___GENPT__ *unpacked = (PACKED_void_const_GLfloat___GENPT___const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT___const_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_const_GLint___GENPT___const_GLint___GENPT__: {
            PACKED_void_const_GLint___GENPT___const_GLint___GENPT__ *unpacked = (PACKED_void_const_GLint___GENPT___const_GLint___GENPT__ *)packed;
            ARGS_void_const_GLint___GENPT___const_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_const_GLshort___GENPT___const_GLshort___GENPT__: {
            PACKED_void_const_GLshort___GENPT___const_GLshort___GENPT__ *unpacked = (PACKED_void_const_GLshort___GENPT___const_GLshort___GENPT__ *)packed;
            ARGS_void_const_GLshort___GENPT___const_GLshort___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_GLint_GLenum: {
            PACKED_GLint_GLenum *unpacked = (PACKED_GLint_GLenum *)packed;
            ARGS_GLint_GLenum args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLfloat_GLboolean: {
            PACKED_void_GLfloat_GLboolean *unpacked = (PACKED_void_GLfloat_GLboolean *)packed;
            ARGS_void_GLfloat_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLint_GLint_GLsizei_GLsizei: {
            PACKED_void_GLint_GLint_GLsizei_GLsizei *unpacked = (PACKED_void_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT___const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT___const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT___const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT___const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLuint: {
            PACKED_void_GLenum_GLint_GLuint *unpacked = (PACKED_void_GLenum_GLint_GLuint *)packed;
            ARGS_void_GLenum_GLint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum: {
            PACKED_void_GLenum_GLenum_GLenum *unpacked = (PACKED_void_GLenum_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLdouble: {
            PACKED_void_GLenum_GLenum_GLdouble *unpacked = (PACKED_void_GLenum_GLenum_GLdouble *)packed;
            ARGS_void_GLenum_GLenum_GLdouble args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_const_GLdouble___GENPT__: {
            PACKED_void_GLenum_GLenum_const_GLdouble___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_const_GLdouble___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLdouble___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9, args.a10, args.a11);
            break;
        }
    }
}
#ifndef skip_glAccum
void glAccum(GLenum op, GLfloat value) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glActiveTexture
void glActiveTexture(GLenum texture) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glAlphaFunc
void glAlphaFunc(GLenum func, GLfloat ref) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glAreTexturesResident
GLboolean glAreTexturesResident(GLsizei n, const GLuint * textures, GLboolean * residences) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glArrayElement
void glArrayElement(GLint i) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glBegin
void glBegin(GLenum mode) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glBeginQuery
void glBeginQuery(GLenum target, GLuint id) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glBindBuffer
void glBindBuffer(GLenum target, GLuint buffer) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glBindTexture
void glBindTexture(GLenum target, GLuint texture) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glBitmap
void glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte * bitmap) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glBlendColor
void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glBlendEquation
void glBlendEquation(GLenum mode) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glBlendFunc
void glBlendFunc(GLenum sfactor, GLenum dfactor) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glBlendFuncSeparate
void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glBufferData
void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glBufferSubData
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glCallList
void glCallList(GLuint list) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glCallLists
void glCallLists(GLsizei n, GLenum type, const GLvoid * lists) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glClear
void glClear(GLbitfield mask) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glClearAccum
void glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glClearColor
void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glClearDepth
void glClearDepth(GLdouble depth) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glClearIndex
void glClearIndex(GLfloat c) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glClearStencil
void glClearStencil(GLint s) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glClientActiveTexture
void glClientActiveTexture(GLenum texture) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glClipPlane
void glClipPlane(GLenum plane, const GLdouble * equation) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor3b
void glColor3b(GLbyte red, GLbyte green, GLbyte blue) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor3bv
void glColor3bv(const GLbyte * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor3d
void glColor3d(GLdouble red, GLdouble green, GLdouble blue) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor3dv
void glColor3dv(const GLdouble * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor3f
void glColor3f(GLfloat red, GLfloat green, GLfloat blue) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor3fv
void glColor3fv(const GLfloat * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor3i
void glColor3i(GLint red, GLint green, GLint blue) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor3iv
void glColor3iv(const GLint * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor3s
void glColor3s(GLshort red, GLshort green, GLshort blue) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor3sv
void glColor3sv(const GLshort * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor3ub
void glColor3ub(GLubyte red, GLubyte green, GLubyte blue) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor3ubv
void glColor3ubv(const GLubyte * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor3ui
void glColor3ui(GLuint red, GLuint green, GLuint blue) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor3uiv
void glColor3uiv(const GLuint * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor3us
void glColor3us(GLushort red, GLushort green, GLushort blue) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor3usv
void glColor3usv(const GLushort * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor4b
void glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor4bv
void glColor4bv(const GLbyte * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor4d
void glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor4dv
void glColor4dv(const GLdouble * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor4f
void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor4fv
void glColor4fv(const GLfloat * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor4i
void glColor4i(GLint red, GLint green, GLint blue, GLint alpha) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor4iv
void glColor4iv(const GLint * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor4s
void glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor4sv
void glColor4sv(const GLshort * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor4ub
void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor4ubv
void glColor4ubv(const GLubyte * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor4ui
void glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor4uiv
void glColor4uiv(const GLuint * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor4us
void glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColor4usv
void glColor4usv(const GLushort * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColorMask
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColorMaterial
void glColorMaterial(GLenum face, GLenum mode) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColorPointer
void glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColorSubTable
void glColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid * data) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColorTable
void glColorTable(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * table) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColorTableParameterfv
void glColorTableParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glColorTableParameteriv
void glColorTableParameteriv(GLenum target, GLenum pname, const GLint * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glCompressedTexImage1D
void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid * data) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glCompressedTexImage2D
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glCompressedTexImage3D
void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid * data) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glCompressedTexSubImage1D
void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid * data) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glCompressedTexSubImage2D
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glCompressedTexSubImage3D
void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid * data) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glConvolutionFilter1D
void glConvolutionFilter1D(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * image) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glConvolutionFilter2D
void glConvolutionFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * image) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glConvolutionParameterf
void glConvolutionParameterf(GLenum target, GLenum pname, GLfloat params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glConvolutionParameterfv
void glConvolutionParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glConvolutionParameteri
void glConvolutionParameteri(GLenum target, GLenum pname, GLint params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glConvolutionParameteriv
void glConvolutionParameteriv(GLenum target, GLenum pname, const GLint * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glCopyColorSubTable
void glCopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glCopyColorTable
void glCopyColorTable(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glCopyConvolutionFilter1D
void glCopyConvolutionFilter1D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glCopyConvolutionFilter2D
void glCopyConvolutionFilter2D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glCopyPixels
void glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glCopyTexImage1D
void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glCopyTexImage2D
void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glCopyTexSubImage1D
void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glCopyTexSubImage2D
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glCopyTexSubImage3D
void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glCullFace
void glCullFace(GLenum mode) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glDeleteBuffers
void glDeleteBuffers(GLsizei n, const GLuint * buffers) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glDeleteLists
void glDeleteLists(GLuint list, GLsizei range) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glDeleteQueries
void glDeleteQueries(GLsizei n, const GLuint * ids) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glDeleteTextures
void glDeleteTextures(GLsizei n, const GLuint * textures) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glDepthFunc
void glDepthFunc(GLenum func) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glDepthMask
void glDepthMask(GLboolean flag) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glDepthRange
void glDepthRange(GLdouble near, GLdouble far) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glDisable
void glDisable(GLenum cap) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glDisableClientState
void glDisableClientState(GLenum array) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glDrawArrays
void glDrawArrays(GLenum mode, GLint first, GLsizei count) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glDrawBuffer
void glDrawBuffer(GLenum mode) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glDrawElements
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glDrawPixels
void glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glDrawRangeElements
void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid * indices) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glEdgeFlag
void glEdgeFlag(GLboolean flag) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glEdgeFlagPointer
void glEdgeFlagPointer(GLsizei stride, const GLvoid * pointer) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glEdgeFlagv
void glEdgeFlagv(const GLboolean * flag) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glEnable
void glEnable(GLenum cap) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glEnableClientState
void glEnableClientState(GLenum array) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glEnd
void glEnd() {
    printf("gl.c\n");
}
#endif
#ifndef skip_glEndList
void glEndList() {
    printf("gl.c\n");
}
#endif
#ifndef skip_glEndQuery
void glEndQuery(GLenum target) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glEvalCoord1d
void glEvalCoord1d(GLdouble u) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glEvalCoord1dv
void glEvalCoord1dv(const GLdouble * u) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glEvalCoord1f
void glEvalCoord1f(GLfloat u) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glEvalCoord1fv
void glEvalCoord1fv(const GLfloat * u) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glEvalCoord2d
void glEvalCoord2d(GLdouble u, GLdouble v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glEvalCoord2dv
void glEvalCoord2dv(const GLdouble * u) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glEvalCoord2f
void glEvalCoord2f(GLfloat u, GLfloat v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glEvalCoord2fv
void glEvalCoord2fv(const GLfloat * u) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glEvalMesh1
void glEvalMesh1(GLenum mode, GLint i1, GLint i2) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glEvalMesh2
void glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glEvalPoint1
void glEvalPoint1(GLint i) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glEvalPoint2
void glEvalPoint2(GLint i, GLint j) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glFeedbackBuffer
void glFeedbackBuffer(GLsizei size, GLenum type, GLfloat * buffer) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glFinish
void glFinish() {
    printf("gl.c\n");
}
#endif
#ifndef skip_glFlush
void glFlush() {
    printf("gl.c\n");
}
#endif
#ifndef skip_glFogCoordPointer
void glFogCoordPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glFogCoordd
void glFogCoordd(GLdouble coord) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glFogCoorddv
void glFogCoorddv(const GLdouble * coord) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glFogCoordf
void glFogCoordf(GLfloat coord) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glFogCoordfv
void glFogCoordfv(const GLfloat * coord) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glFogf
void glFogf(GLenum pname, GLfloat param) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glFogfv
void glFogfv(GLenum pname, const GLfloat * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glFogi
void glFogi(GLenum pname, GLint param) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glFogiv
void glFogiv(GLenum pname, const GLint * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glFrontFace
void glFrontFace(GLenum mode) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glFrustum
void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGenBuffers
void glGenBuffers(GLsizei n, GLuint * buffers) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGenLists
GLuint glGenLists(GLsizei range) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGenQueries
void glGenQueries(GLsizei n, GLuint * ids) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGenTextures
void glGenTextures(GLsizei n, GLuint * textures) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetBooleanv
void glGetBooleanv(GLenum pname, GLboolean * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetBufferParameteriv
void glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetBufferPointerv
void glGetBufferPointerv(GLenum target, GLenum pname, GLvoid * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetBufferSubData
void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetClipPlane
void glGetClipPlane(GLenum plane, GLdouble * equation) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetColorTable
void glGetColorTable(GLenum target, GLenum format, GLenum type, GLvoid * table) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetColorTableParameterfv
void glGetColorTableParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetColorTableParameteriv
void glGetColorTableParameteriv(GLenum target, GLenum pname, GLint * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetCompressedTexImage
void glGetCompressedTexImage(GLenum target, GLint level, GLvoid * img) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetConvolutionFilter
void glGetConvolutionFilter(GLenum target, GLenum format, GLenum type, GLvoid * image) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetConvolutionParameterfv
void glGetConvolutionParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetConvolutionParameteriv
void glGetConvolutionParameteriv(GLenum target, GLenum pname, GLint * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetDoublev
void glGetDoublev(GLenum pname, GLdouble * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetError
GLenum glGetError() {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetFloatv
void glGetFloatv(GLenum pname, GLfloat * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetHistogram
void glGetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetHistogramParameterfv
void glGetHistogramParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetHistogramParameteriv
void glGetHistogramParameteriv(GLenum target, GLenum pname, GLint * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetIntegerv
void glGetIntegerv(GLenum pname, GLint * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetLightfv
void glGetLightfv(GLenum light, GLenum pname, GLfloat * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetLightiv
void glGetLightiv(GLenum light, GLenum pname, GLint * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetMapdv
void glGetMapdv(GLenum target, GLenum query, GLdouble * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetMapfv
void glGetMapfv(GLenum target, GLenum query, GLfloat * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetMapiv
void glGetMapiv(GLenum target, GLenum query, GLint * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetMaterialfv
void glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetMaterialiv
void glGetMaterialiv(GLenum face, GLenum pname, GLint * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetMinmax
void glGetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetMinmaxParameterfv
void glGetMinmaxParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetMinmaxParameteriv
void glGetMinmaxParameteriv(GLenum target, GLenum pname, GLint * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetPixelMapfv
void glGetPixelMapfv(GLenum map, GLfloat * values) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetPixelMapuiv
void glGetPixelMapuiv(GLenum map, GLuint * values) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetPixelMapusv
void glGetPixelMapusv(GLenum map, GLushort * values) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetPointerv
void glGetPointerv(GLenum pname, GLvoid ** params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetPolygonStipple
void glGetPolygonStipple(GLubyte * mask) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetQueryObjectiv
void glGetQueryObjectiv(GLuint id, GLenum pname, GLint * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetQueryObjectuiv
void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetQueryiv
void glGetQueryiv(GLenum target, GLenum pname, GLint * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetSeparableFilter
void glGetSeparableFilter(GLenum target, GLenum format, GLenum type, GLvoid * row, GLvoid * column, GLvoid * span) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetString
const GLubyte * glGetString(GLenum name) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetTexEnvfv
void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetTexEnviv
void glGetTexEnviv(GLenum target, GLenum pname, GLint * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetTexGendv
void glGetTexGendv(GLenum coord, GLenum pname, GLdouble * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetTexGenfv
void glGetTexGenfv(GLenum coord, GLenum pname, GLfloat * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetTexGeniv
void glGetTexGeniv(GLenum coord, GLenum pname, GLint * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetTexImage
void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid * pixels) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetTexLevelParameterfv
void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetTexLevelParameteriv
void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetTexParameterfv
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glGetTexParameteriv
void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glHint
void glHint(GLenum target, GLenum mode) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glHistogram
void glHistogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glIndexMask
void glIndexMask(GLuint mask) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glIndexPointer
void glIndexPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glIndexd
void glIndexd(GLdouble c) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glIndexdv
void glIndexdv(const GLdouble * c) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glIndexf
void glIndexf(GLfloat c) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glIndexfv
void glIndexfv(const GLfloat * c) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glIndexi
void glIndexi(GLint c) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glIndexiv
void glIndexiv(const GLint * c) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glIndexs
void glIndexs(GLshort c) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glIndexsv
void glIndexsv(const GLshort * c) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glIndexub
void glIndexub(GLubyte c) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glIndexubv
void glIndexubv(const GLubyte * c) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glInitNames
void glInitNames() {
    printf("gl.c\n");
}
#endif
#ifndef skip_glInterleavedArrays
void glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid * pointer) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glIsBuffer
GLboolean glIsBuffer(GLuint buffer) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glIsEnabled
GLboolean glIsEnabled(GLenum cap) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glIsList
GLboolean glIsList(GLuint list) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glIsQuery
GLboolean glIsQuery(GLuint id) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glIsTexture
GLboolean glIsTexture(GLuint texture) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glLightModelf
void glLightModelf(GLenum pname, GLfloat param) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glLightModelfv
void glLightModelfv(GLenum pname, const GLfloat * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glLightModeli
void glLightModeli(GLenum pname, GLint param) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glLightModeliv
void glLightModeliv(GLenum pname, const GLint * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glLightf
void glLightf(GLenum light, GLenum pname, GLfloat param) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glLightfv
void glLightfv(GLenum light, GLenum pname, const GLfloat * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glLighti
void glLighti(GLenum light, GLenum pname, GLint param) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glLightiv
void glLightiv(GLenum light, GLenum pname, const GLint * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glLineStipple
void glLineStipple(GLint factor, GLushort pattern) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glLineWidth
void glLineWidth(GLfloat width) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glListBase
void glListBase(GLuint base) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glLoadIdentity
void glLoadIdentity() {
    printf("gl.c\n");
}
#endif
#ifndef skip_glLoadMatrixd
void glLoadMatrixd(const GLdouble * m) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glLoadMatrixf
void glLoadMatrixf(const GLfloat * m) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glLoadName
void glLoadName(GLuint name) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glLoadTransposeMatrixd
void glLoadTransposeMatrixd(const GLdouble * m) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glLoadTransposeMatrixf
void glLoadTransposeMatrixf(const GLfloat * m) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glLogicOp
void glLogicOp(GLenum opcode) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMap1d
void glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble * points) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMap1f
void glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat * points) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMap2d
void glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble * points) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMap2f
void glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat * points) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMapBuffer
GLvoid * glMapBuffer(GLenum target, GLenum access) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMapGrid1d
void glMapGrid1d(GLint un, GLdouble u1, GLdouble u2) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMapGrid1f
void glMapGrid1f(GLint un, GLfloat u1, GLfloat u2) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMapGrid2d
void glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMapGrid2f
void glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMaterialf
void glMaterialf(GLenum face, GLenum pname, GLfloat param) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMaterialfv
void glMaterialfv(GLenum face, GLenum pname, const GLfloat * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMateriali
void glMateriali(GLenum face, GLenum pname, GLint param) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMaterialiv
void glMaterialiv(GLenum face, GLenum pname, const GLint * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMatrixMode
void glMatrixMode(GLenum mode) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMinmax
void glMinmax(GLenum target, GLenum internalformat, GLboolean sink) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultMatrixd
void glMultMatrixd(const GLdouble * m) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultMatrixf
void glMultMatrixf(const GLfloat * m) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultTransposeMatrixd
void glMultTransposeMatrixd(const GLdouble * m) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultTransposeMatrixf
void glMultTransposeMatrixf(const GLfloat * m) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiDrawArrays
void glMultiDrawArrays(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiDrawElements
void glMultiDrawElements(GLenum mode, const GLsizei * count, GLenum type, GLvoid*const * indices, GLsizei drawcount) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord1d
void glMultiTexCoord1d(GLenum target, GLdouble s) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord1dv
void glMultiTexCoord1dv(GLenum target, const GLdouble * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord1f
void glMultiTexCoord1f(GLenum target, GLfloat s) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord1fv
void glMultiTexCoord1fv(GLenum target, const GLfloat * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord1i
void glMultiTexCoord1i(GLenum target, GLint s) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord1iv
void glMultiTexCoord1iv(GLenum target, const GLint * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord1s
void glMultiTexCoord1s(GLenum target, GLshort s) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord1sv
void glMultiTexCoord1sv(GLenum target, const GLshort * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord2d
void glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord2dv
void glMultiTexCoord2dv(GLenum target, const GLdouble * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord2f
void glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord2fv
void glMultiTexCoord2fv(GLenum target, const GLfloat * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord2i
void glMultiTexCoord2i(GLenum target, GLint s, GLint t) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord2iv
void glMultiTexCoord2iv(GLenum target, const GLint * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord2s
void glMultiTexCoord2s(GLenum target, GLshort s, GLshort t) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord2sv
void glMultiTexCoord2sv(GLenum target, const GLshort * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord3d
void glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord3dv
void glMultiTexCoord3dv(GLenum target, const GLdouble * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord3f
void glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord3fv
void glMultiTexCoord3fv(GLenum target, const GLfloat * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord3i
void glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord3iv
void glMultiTexCoord3iv(GLenum target, const GLint * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord3s
void glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord3sv
void glMultiTexCoord3sv(GLenum target, const GLshort * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord4d
void glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord4dv
void glMultiTexCoord4dv(GLenum target, const GLdouble * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord4f
void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord4fv
void glMultiTexCoord4fv(GLenum target, const GLfloat * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord4i
void glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord4iv
void glMultiTexCoord4iv(GLenum target, const GLint * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord4s
void glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glMultiTexCoord4sv
void glMultiTexCoord4sv(GLenum target, const GLshort * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glNewList
void glNewList(GLuint list, GLenum mode) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glNormal3b
void glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glNormal3bv
void glNormal3bv(const GLbyte * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glNormal3d
void glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glNormal3dv
void glNormal3dv(const GLdouble * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glNormal3f
void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glNormal3fv
void glNormal3fv(const GLfloat * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glNormal3i
void glNormal3i(GLint nx, GLint ny, GLint nz) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glNormal3iv
void glNormal3iv(const GLint * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glNormal3s
void glNormal3s(GLshort nx, GLshort ny, GLshort nz) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glNormal3sv
void glNormal3sv(const GLshort * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glNormalPointer
void glNormalPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glOrtho
void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPassThrough
void glPassThrough(GLfloat token) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPixelMapfv
void glPixelMapfv(GLenum map, GLsizei mapsize, const GLfloat * values) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPixelMapuiv
void glPixelMapuiv(GLenum map, GLsizei mapsize, const GLuint * values) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPixelMapusv
void glPixelMapusv(GLenum map, GLsizei mapsize, const GLushort * values) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPixelStoref
void glPixelStoref(GLenum pname, GLfloat param) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPixelStorei
void glPixelStorei(GLenum pname, GLint param) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPixelTransferf
void glPixelTransferf(GLenum pname, GLfloat param) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPixelTransferi
void glPixelTransferi(GLenum pname, GLint param) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPixelZoom
void glPixelZoom(GLfloat xfactor, GLfloat yfactor) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPointParameterf
void glPointParameterf(GLenum pname, GLfloat param) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPointParameterfv
void glPointParameterfv(GLenum pname, const GLfloat * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPointParameteri
void glPointParameteri(GLenum pname, GLint param) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPointParameteriv
void glPointParameteriv(GLenum pname, const GLint * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPointSize
void glPointSize(GLfloat size) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPolygonMode
void glPolygonMode(GLenum face, GLenum mode) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPolygonOffset
void glPolygonOffset(GLfloat factor, GLfloat units) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPolygonStipple
void glPolygonStipple(const GLubyte * mask) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPopAttrib
void glPopAttrib() {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPopClientAttrib
void glPopClientAttrib() {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPopMatrix
void glPopMatrix() {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPopName
void glPopName() {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPrioritizeTextures
void glPrioritizeTextures(GLsizei n, const GLuint * textures, const GLfloat * priorities) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPushAttrib
void glPushAttrib(GLbitfield mask) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPushClientAttrib
void glPushClientAttrib(GLbitfield mask) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPushMatrix
void glPushMatrix() {
    printf("gl.c\n");
}
#endif
#ifndef skip_glPushName
void glPushName(GLuint name) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRasterPos2d
void glRasterPos2d(GLdouble x, GLdouble y) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRasterPos2dv
void glRasterPos2dv(const GLdouble * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRasterPos2f
void glRasterPos2f(GLfloat x, GLfloat y) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRasterPos2fv
void glRasterPos2fv(const GLfloat * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRasterPos2i
void glRasterPos2i(GLint x, GLint y) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRasterPos2iv
void glRasterPos2iv(const GLint * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRasterPos2s
void glRasterPos2s(GLshort x, GLshort y) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRasterPos2sv
void glRasterPos2sv(const GLshort * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRasterPos3d
void glRasterPos3d(GLdouble x, GLdouble y, GLdouble z) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRasterPos3dv
void glRasterPos3dv(const GLdouble * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRasterPos3f
void glRasterPos3f(GLfloat x, GLfloat y, GLfloat z) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRasterPos3fv
void glRasterPos3fv(const GLfloat * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRasterPos3i
void glRasterPos3i(GLint x, GLint y, GLint z) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRasterPos3iv
void glRasterPos3iv(const GLint * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRasterPos3s
void glRasterPos3s(GLshort x, GLshort y, GLshort z) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRasterPos3sv
void glRasterPos3sv(const GLshort * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRasterPos4d
void glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRasterPos4dv
void glRasterPos4dv(const GLdouble * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRasterPos4f
void glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRasterPos4fv
void glRasterPos4fv(const GLfloat * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRasterPos4i
void glRasterPos4i(GLint x, GLint y, GLint z, GLint w) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRasterPos4iv
void glRasterPos4iv(const GLint * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRasterPos4s
void glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRasterPos4sv
void glRasterPos4sv(const GLshort * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glReadBuffer
void glReadBuffer(GLenum mode) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glReadPixels
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRectd
void glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRectdv
void glRectdv(const GLdouble * v1, const GLdouble * v2) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRectf
void glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRectfv
void glRectfv(const GLfloat * v1, const GLfloat * v2) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRecti
void glRecti(GLint x1, GLint y1, GLint x2, GLint y2) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRectiv
void glRectiv(const GLint * v1, const GLint * v2) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRects
void glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRectsv
void glRectsv(const GLshort * v1, const GLshort * v2) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRenderMode
GLint glRenderMode(GLenum mode) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glResetHistogram
void glResetHistogram(GLenum target) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glResetMinmax
void glResetMinmax(GLenum target) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRotated
void glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glRotatef
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glSampleCoverage
void glSampleCoverage(GLfloat value, GLboolean invert) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glScaled
void glScaled(GLdouble x, GLdouble y, GLdouble z) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glScalef
void glScalef(GLfloat x, GLfloat y, GLfloat z) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glScissor
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glSecondaryColor3b
void glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glSecondaryColor3bv
void glSecondaryColor3bv(const GLbyte * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glSecondaryColor3d
void glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glSecondaryColor3dv
void glSecondaryColor3dv(const GLdouble * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glSecondaryColor3f
void glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glSecondaryColor3fv
void glSecondaryColor3fv(const GLfloat * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glSecondaryColor3i
void glSecondaryColor3i(GLint red, GLint green, GLint blue) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glSecondaryColor3iv
void glSecondaryColor3iv(const GLint * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glSecondaryColor3s
void glSecondaryColor3s(GLshort red, GLshort green, GLshort blue) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glSecondaryColor3sv
void glSecondaryColor3sv(const GLshort * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glSecondaryColor3ub
void glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glSecondaryColor3ubv
void glSecondaryColor3ubv(const GLubyte * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glSecondaryColor3ui
void glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glSecondaryColor3uiv
void glSecondaryColor3uiv(const GLuint * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glSecondaryColor3us
void glSecondaryColor3us(GLushort red, GLushort green, GLushort blue) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glSecondaryColor3usv
void glSecondaryColor3usv(const GLushort * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glSecondaryColorPointer
void glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glSelectBuffer
void glSelectBuffer(GLsizei size, GLuint * buffer) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glSeparableFilter2D
void glSeparableFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * row, const GLvoid * column) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glShadeModel
void glShadeModel(GLenum mode) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glStencilFunc
void glStencilFunc(GLenum func, GLint ref, GLuint mask) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glStencilMask
void glStencilMask(GLuint mask) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glStencilOp
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord1d
void glTexCoord1d(GLdouble s) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord1dv
void glTexCoord1dv(const GLdouble * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord1f
void glTexCoord1f(GLfloat s) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord1fv
void glTexCoord1fv(const GLfloat * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord1i
void glTexCoord1i(GLint s) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord1iv
void glTexCoord1iv(const GLint * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord1s
void glTexCoord1s(GLshort s) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord1sv
void glTexCoord1sv(const GLshort * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord2d
void glTexCoord2d(GLdouble s, GLdouble t) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord2dv
void glTexCoord2dv(const GLdouble * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord2f
void glTexCoord2f(GLfloat s, GLfloat t) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord2fv
void glTexCoord2fv(const GLfloat * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord2i
void glTexCoord2i(GLint s, GLint t) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord2iv
void glTexCoord2iv(const GLint * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord2s
void glTexCoord2s(GLshort s, GLshort t) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord2sv
void glTexCoord2sv(const GLshort * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord3d
void glTexCoord3d(GLdouble s, GLdouble t, GLdouble r) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord3dv
void glTexCoord3dv(const GLdouble * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord3f
void glTexCoord3f(GLfloat s, GLfloat t, GLfloat r) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord3fv
void glTexCoord3fv(const GLfloat * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord3i
void glTexCoord3i(GLint s, GLint t, GLint r) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord3iv
void glTexCoord3iv(const GLint * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord3s
void glTexCoord3s(GLshort s, GLshort t, GLshort r) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord3sv
void glTexCoord3sv(const GLshort * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord4d
void glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord4dv
void glTexCoord4dv(const GLdouble * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord4f
void glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord4fv
void glTexCoord4fv(const GLfloat * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord4i
void glTexCoord4i(GLint s, GLint t, GLint r, GLint q) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord4iv
void glTexCoord4iv(const GLint * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord4s
void glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoord4sv
void glTexCoord4sv(const GLshort * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexCoordPointer
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexEnvf
void glTexEnvf(GLenum target, GLenum pname, GLfloat param) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexEnvfv
void glTexEnvfv(GLenum target, GLenum pname, const GLfloat * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexEnvi
void glTexEnvi(GLenum target, GLenum pname, GLint param) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexEnviv
void glTexEnviv(GLenum target, GLenum pname, const GLint * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexGend
void glTexGend(GLenum coord, GLenum pname, GLdouble param) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexGendv
void glTexGendv(GLenum coord, GLenum pname, const GLdouble * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexGenf
void glTexGenf(GLenum coord, GLenum pname, GLfloat param) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexGenfv
void glTexGenfv(GLenum coord, GLenum pname, const GLfloat * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexGeni
void glTexGeni(GLenum coord, GLenum pname, GLint param) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexGeniv
void glTexGeniv(GLenum coord, GLenum pname, const GLint * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexImage1D
void glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid * pixels) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexImage2D
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexImage3D
void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid * pixels) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexParameterf
void glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexParameterfv
void glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexParameteri
void glTexParameteri(GLenum target, GLenum pname, GLint param) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexParameteriv
void glTexParameteriv(GLenum target, GLenum pname, const GLint * params) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexSubImage1D
void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid * pixels) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexSubImage2D
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTexSubImage3D
void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * pixels) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTranslated
void glTranslated(GLdouble x, GLdouble y, GLdouble z) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glTranslatef
void glTranslatef(GLfloat x, GLfloat y, GLfloat z) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glUnmapBuffer
GLboolean glUnmapBuffer(GLenum target) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glVertex2d
void glVertex2d(GLdouble x, GLdouble y) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glVertex2dv
void glVertex2dv(const GLdouble * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glVertex2f
void glVertex2f(GLfloat x, GLfloat y) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glVertex2fv
void glVertex2fv(const GLfloat * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glVertex2i
void glVertex2i(GLint x, GLint y) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glVertex2iv
void glVertex2iv(const GLint * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glVertex2s
void glVertex2s(GLshort x, GLshort y) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glVertex2sv
void glVertex2sv(const GLshort * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glVertex3d
void glVertex3d(GLdouble x, GLdouble y, GLdouble z) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glVertex3dv
void glVertex3dv(const GLdouble * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glVertex3f
void glVertex3f(GLfloat x, GLfloat y, GLfloat z) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glVertex3fv
void glVertex3fv(const GLfloat * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glVertex3i
void glVertex3i(GLint x, GLint y, GLint z) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glVertex3iv
void glVertex3iv(const GLint * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glVertex3s
void glVertex3s(GLshort x, GLshort y, GLshort z) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glVertex3sv
void glVertex3sv(const GLshort * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glVertex4d
void glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glVertex4dv
void glVertex4dv(const GLdouble * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glVertex4f
void glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glVertex4fv
void glVertex4fv(const GLfloat * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glVertex4i
void glVertex4i(GLint x, GLint y, GLint z, GLint w) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glVertex4iv
void glVertex4iv(const GLint * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glVertex4s
void glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glVertex4sv
void glVertex4sv(const GLshort * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glVertexPointer
void glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glViewport
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glWindowPos2d
void glWindowPos2d(GLdouble x, GLdouble y) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glWindowPos2dv
void glWindowPos2dv(const GLdouble * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glWindowPos2f
void glWindowPos2f(GLfloat x, GLfloat y) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glWindowPos2fv
void glWindowPos2fv(const GLfloat * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glWindowPos2i
void glWindowPos2i(GLint x, GLint y) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glWindowPos2iv
void glWindowPos2iv(const GLint * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glWindowPos2s
void glWindowPos2s(GLshort x, GLshort y) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glWindowPos2sv
void glWindowPos2sv(const GLshort * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glWindowPos3d
void glWindowPos3d(GLdouble x, GLdouble y, GLdouble z) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glWindowPos3dv
void glWindowPos3dv(const GLdouble * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glWindowPos3f
void glWindowPos3f(GLfloat x, GLfloat y, GLfloat z) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glWindowPos3fv
void glWindowPos3fv(const GLfloat * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glWindowPos3i
void glWindowPos3i(GLint x, GLint y, GLint z) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glWindowPos3iv
void glWindowPos3iv(const GLint * v) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glWindowPos3s
void glWindowPos3s(GLshort x, GLshort y, GLshort z) {
    printf("gl.c\n");
}
#endif
#ifndef skip_glWindowPos3sv
void glWindowPos3sv(const GLshort * v) {
    printf("gl.c\n");
}
#endif
