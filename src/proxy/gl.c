#include <stdio.h>
#include "gl.h"

void glPackedCall(const packed_call_t *packed) {
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
        case FORMAT_int_Display___GENPT___int: {
            PACKED_int_Display___GENPT___int *unpacked = (PACKED_int_Display___GENPT___int *)packed;
            ARGS_int_Display___GENPT___int args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_uint32_t_uint32_t: {
            PACKED_void_uint32_t_uint32_t *unpacked = (PACKED_void_uint32_t_uint32_t *)packed;
            ARGS_void_uint32_t_uint32_t args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_uint32_t: {
            PACKED_void_uint32_t *unpacked = (PACKED_void_uint32_t *)packed;
            ARGS_void_uint32_t args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_XVisualInfo___GENPT___Display___GENPT___int_int___GENPT__: {
            PACKED_XVisualInfo___GENPT___Display___GENPT___int_int___GENPT__ *unpacked = (PACKED_XVisualInfo___GENPT___Display___GENPT___int_int___GENPT__ *)packed;
            ARGS_XVisualInfo___GENPT___Display___GENPT___int_int___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_Display___GENPT___GLXContext_GLXContext_unsigned_long: {
            PACKED_void_Display___GENPT___GLXContext_GLXContext_unsigned_long *unpacked = (PACKED_void_Display___GENPT___GLXContext_GLXContext_unsigned_long *)packed;
            ARGS_void_Display___GENPT___GLXContext_GLXContext_unsigned_long args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_GLXContext_Display___GENPT___XVisualInfo___GENPT___GLXContext_Bool: {
            PACKED_GLXContext_Display___GENPT___XVisualInfo___GENPT___GLXContext_Bool *unpacked = (PACKED_GLXContext_Display___GENPT___XVisualInfo___GENPT___GLXContext_Bool *)packed;
            ARGS_GLXContext_Display___GENPT___XVisualInfo___GENPT___GLXContext_Bool args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_uint32_t_uint32_t_uint32_t_uint32_t: {
            PACKED_void_uint32_t_uint32_t_uint32_t_uint32_t *unpacked = (PACKED_void_uint32_t_uint32_t_uint32_t_uint32_t *)packed;
            ARGS_void_uint32_t_uint32_t_uint32_t_uint32_t args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_GLXPixmap_Display___GENPT___XVisualInfo___GENPT___Pixmap: {
            PACKED_GLXPixmap_Display___GENPT___XVisualInfo___GENPT___Pixmap *unpacked = (PACKED_GLXPixmap_Display___GENPT___XVisualInfo___GENPT___Pixmap *)packed;
            ARGS_GLXPixmap_Display___GENPT___XVisualInfo___GENPT___Pixmap args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_uint32_t_uint32_t_uint32_t: {
            PACKED_void_uint32_t_uint32_t_uint32_t *unpacked = (PACKED_void_uint32_t_uint32_t_uint32_t *)packed;
            ARGS_void_uint32_t_uint32_t_uint32_t args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_Display___GENPT___uint32_t_uint32_t_uint32_t_uint32_t_uint32_t: {
            PACKED_void_Display___GENPT___uint32_t_uint32_t_uint32_t_uint32_t_uint32_t *unpacked = (PACKED_void_Display___GENPT___uint32_t_uint32_t_uint32_t_uint32_t_uint32_t *)packed;
            ARGS_void_Display___GENPT___uint32_t_uint32_t_uint32_t_uint32_t_uint32_t args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_Display___GENPT___GLXContext: {
            PACKED_void_Display___GENPT___GLXContext *unpacked = (PACKED_void_Display___GENPT___GLXContext *)packed;
            ARGS_void_Display___GENPT___GLXContext args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_Display___GENPT___GLXPixmap: {
            PACKED_void_Display___GENPT___GLXPixmap *unpacked = (PACKED_void_Display___GENPT___GLXPixmap *)packed;
            ARGS_void_Display___GENPT___GLXPixmap args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_Display___GENPT___uint32_t: {
            PACKED_void_Display___GENPT___uint32_t *unpacked = (PACKED_void_Display___GENPT___uint32_t *)packed;
            ARGS_void_Display___GENPT___uint32_t args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_int_Display___GENPT___int_int_int_const_void___GENPT__: {
            PACKED_int_Display___GENPT___int_int_int_const_void___GENPT__ *unpacked = (PACKED_int_Display___GENPT___int_int_int_const_void___GENPT__ *)packed;
            ARGS_int_Display___GENPT___int_int_int_const_void___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__: {
            PACKED_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__ *unpacked = (PACKED_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__ *)packed;
            ARGS_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_Bool_Display___GENPT___GLXContext: {
            PACKED_Bool_Display___GENPT___GLXContext *unpacked = (PACKED_Bool_Display___GENPT___GLXContext *)packed;
            ARGS_Bool_Display___GENPT___GLXContext args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_Bool_Display___GENPT___GLXDrawable_GLXContext: {
            PACKED_Bool_Display___GENPT___GLXDrawable_GLXContext *unpacked = (PACKED_Bool_Display___GENPT___GLXDrawable_GLXContext *)packed;
            ARGS_Bool_Display___GENPT___GLXDrawable_GLXContext args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_const_char___GENPT___Display___GENPT___int: {
            PACKED_const_char___GENPT___Display___GENPT___int *unpacked = (PACKED_const_char___GENPT___Display___GENPT___int *)packed;
            ARGS_const_char___GENPT___Display___GENPT___int args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__: {
            PACKED_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__ *unpacked = (PACKED_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__ *)packed;
            ARGS_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__: {
            PACKED_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__ *unpacked = (PACKED_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__ *)packed;
            ARGS_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__: {
            PACKED_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__ *unpacked = (PACKED_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__ *)packed;
            ARGS_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_const_char___GENPT___Display___GENPT___int_int: {
            PACKED_const_char___GENPT___Display___GENPT___int_int *unpacked = (PACKED_const_char___GENPT___Display___GENPT___int_int *)packed;
            ARGS_const_char___GENPT___Display___GENPT___int_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_Bool_Display___GENPT___int___GENPT___int___GENPT__: {
            PACKED_Bool_Display___GENPT___int___GENPT___int___GENPT__ *unpacked = (PACKED_Bool_Display___GENPT___int___GENPT___int___GENPT__ *)packed;
            ARGS_Bool_Display___GENPT___int___GENPT___int___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_Display___GENPT___GLXDrawable: {
            PACKED_void_Display___GENPT___GLXDrawable *unpacked = (PACKED_void_Display___GENPT___GLXDrawable *)packed;
            ARGS_void_Display___GENPT___GLXDrawable args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_Font_int_int_int: {
            PACKED_void_Font_int_int_int *unpacked = (PACKED_void_Font_int_int_int *)packed;
            ARGS_void_Font_int_int_int args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_GLXFBConfig___GENPT___Display___GENPT___int_const_int___GENPT___int___GENPT__: {
            PACKED_GLXFBConfig___GENPT___Display___GENPT___int_const_int___GENPT___int___GENPT__ *unpacked = (PACKED_GLXFBConfig___GENPT___Display___GENPT___int_const_int___GENPT___int___GENPT__ *)packed;
            ARGS_GLXFBConfig___GENPT___Display___GENPT___int_const_int___GENPT___int___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_GLXContext_Display___GENPT___GLXFBConfig_int_GLXContext_Bool: {
            PACKED_GLXContext_Display___GENPT___GLXFBConfig_int_GLXContext_Bool *unpacked = (PACKED_GLXContext_Display___GENPT___GLXFBConfig_int_GLXContext_Bool *)packed;
            ARGS_GLXContext_Display___GENPT___GLXFBConfig_int_GLXContext_Bool args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_GLXPbuffer_Display___GENPT___GLXFBConfig_const_int___GENPT__: {
            PACKED_GLXPbuffer_Display___GENPT___GLXFBConfig_const_int___GENPT__ *unpacked = (PACKED_GLXPbuffer_Display___GENPT___GLXFBConfig_const_int___GENPT__ *)packed;
            ARGS_GLXPbuffer_Display___GENPT___GLXFBConfig_const_int___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_GLXPixmap_Display___GENPT___GLXFBConfig_Pixmap_const_int___GENPT__: {
            PACKED_GLXPixmap_Display___GENPT___GLXFBConfig_Pixmap_const_int___GENPT__ *unpacked = (PACKED_GLXPixmap_Display___GENPT___GLXFBConfig_Pixmap_const_int___GENPT__ *)packed;
            ARGS_GLXPixmap_Display___GENPT___GLXFBConfig_Pixmap_const_int___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_GLXWindow_Display___GENPT___GLXFBConfig_Window_const_int___GENPT__: {
            PACKED_GLXWindow_Display___GENPT___GLXFBConfig_Window_const_int___GENPT__ *unpacked = (PACKED_GLXWindow_Display___GENPT___GLXFBConfig_Window_const_int___GENPT__ *)packed;
            ARGS_GLXWindow_Display___GENPT___GLXFBConfig_Window_const_int___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_Display___GENPT___GLXPbuffer: {
            PACKED_void_Display___GENPT___GLXPbuffer *unpacked = (PACKED_void_Display___GENPT___GLXPbuffer *)packed;
            ARGS_void_Display___GENPT___GLXPbuffer args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_Display___GENPT___GLXWindow: {
            PACKED_void_Display___GENPT___GLXWindow *unpacked = (PACKED_void_Display___GENPT___GLXWindow *)packed;
            ARGS_void_Display___GENPT___GLXWindow args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_Display___GENPT__: {
            PACKED_Display___GENPT__ *unpacked = (PACKED_Display___GENPT__ *)packed;
            ARGS_Display___GENPT__ args = unpacked->args;
            unpacked->func();
            break;
        }
        case FORMAT_GLXDrawable: {
            PACKED_GLXDrawable *unpacked = (PACKED_GLXDrawable *)packed;
            ARGS_GLXDrawable args = unpacked->args;
            unpacked->func();
            break;
        }
        case FORMAT_int_Display___GENPT___GLXFBConfig_int_int___GENPT__: {
            PACKED_int_Display___GENPT___GLXFBConfig_int_int___GENPT__ *unpacked = (PACKED_int_Display___GENPT___GLXFBConfig_int_int___GENPT__ *)packed;
            ARGS_int_Display___GENPT___GLXFBConfig_int_int___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_GLXFBConfig___GENPT___Display___GENPT___int_int___GENPT__: {
            PACKED_GLXFBConfig___GENPT___Display___GENPT___int_int___GENPT__ *unpacked = (PACKED_GLXFBConfig___GENPT___Display___GENPT___int_int___GENPT__ *)packed;
            ARGS_GLXFBConfig___GENPT___Display___GENPT___int_int___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT___GLXextFuncPtr_const_GLubyte___GENPT__: {
            PACKED___GLXextFuncPtr_const_GLubyte___GENPT__ *unpacked = (PACKED___GLXextFuncPtr_const_GLubyte___GENPT__ *)packed;
            ARGS___GLXextFuncPtr_const_GLubyte___GENPT__ args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_Display___GENPT___GLXDrawable_unsigned_long___GENPT__: {
            PACKED_void_Display___GENPT___GLXDrawable_unsigned_long___GENPT__ *unpacked = (PACKED_void_Display___GENPT___GLXDrawable_unsigned_long___GENPT__ *)packed;
            ARGS_void_Display___GENPT___GLXDrawable_unsigned_long___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_XVisualInfo___GENPT___Display___GENPT___GLXFBConfig: {
            PACKED_XVisualInfo___GENPT___Display___GENPT___GLXFBConfig *unpacked = (PACKED_XVisualInfo___GENPT___Display___GENPT___GLXFBConfig *)packed;
            ARGS_XVisualInfo___GENPT___Display___GENPT___GLXFBConfig args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_Bool_Display___GENPT___GLXDrawable_GLXDrawable_GLXContext: {
            PACKED_Bool_Display___GENPT___GLXDrawable_GLXDrawable_GLXContext *unpacked = (PACKED_Bool_Display___GENPT___GLXDrawable_GLXDrawable_GLXContext *)packed;
            ARGS_Bool_Display___GENPT___GLXDrawable_GLXDrawable_GLXContext args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_int_Display___GENPT___GLXContext_int_int___GENPT__: {
            PACKED_int_Display___GENPT___GLXContext_int_int___GENPT__ *unpacked = (PACKED_int_Display___GENPT___GLXContext_int_int___GENPT__ *)packed;
            ARGS_int_Display___GENPT___GLXContext_int_int___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_Display___GENPT___GLXDrawable_int_unsigned_int___GENPT__: {
            PACKED_void_Display___GENPT___GLXDrawable_int_unsigned_int___GENPT__ *unpacked = (PACKED_void_Display___GENPT___GLXDrawable_int_unsigned_int___GENPT__ *)packed;
            ARGS_void_Display___GENPT___GLXDrawable_int_unsigned_int___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_Display___GENPT___GLXDrawable_unsigned_long: {
            PACKED_void_Display___GENPT___GLXDrawable_unsigned_long *unpacked = (PACKED_void_Display___GENPT___GLXDrawable_unsigned_long *)packed;
            ARGS_void_Display___GENPT___GLXDrawable_unsigned_long args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
    }
}
#ifndef skip_glAccum
void glAccum(GLenum op, GLfloat value) {
    printf("glAccum(%u, %0.2f);\n", op, value);
}
#endif
#ifndef skip_glActiveTexture
void glActiveTexture(GLenum texture) {
    printf("glActiveTexture(%u);\n", texture);
}
#endif
#ifndef skip_glAlphaFunc
void glAlphaFunc(GLenum func, GLfloat ref) {
    printf("glAlphaFunc(%u, %0.2f);\n", func, ref);
}
#endif
#ifndef skip_glAreTexturesResident
GLboolean glAreTexturesResident(GLsizei n, const GLuint * textures, GLboolean * residences) {
    printf("glAreTexturesResident(%d, %p, %p);\n", n, textures, residences);
    return 0;
}
#endif
#ifndef skip_glArrayElement
void glArrayElement(GLint i) {
    printf("glArrayElement(%d);\n", i);
}
#endif
#ifndef skip_glBegin
void glBegin(GLenum mode) {
    printf("glBegin(%u);\n", mode);
}
#endif
#ifndef skip_glBeginQuery
void glBeginQuery(GLenum target, GLuint id) {
    printf("glBeginQuery(%u, %u);\n", target, id);
}
#endif
#ifndef skip_glBindBuffer
void glBindBuffer(GLenum target, GLuint buffer) {
    printf("glBindBuffer(%u, %u);\n", target, buffer);
}
#endif
#ifndef skip_glBindTexture
void glBindTexture(GLenum target, GLuint texture) {
    printf("glBindTexture(%u, %u);\n", target, texture);
}
#endif
#ifndef skip_glBitmap
void glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte * bitmap) {
    printf("glBitmap(%d, %d, %0.2f, %0.2f, %0.2f, %0.2f, %p);\n", width, height, xorig, yorig, xmove, ymove, bitmap);
}
#endif
#ifndef skip_glBlendColor
void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    printf("glBlendColor(%0.2f, %0.2f, %0.2f, %0.2f);\n", red, green, blue, alpha);
}
#endif
#ifndef skip_glBlendEquation
void glBlendEquation(GLenum mode) {
    printf("glBlendEquation(%u);\n", mode);
}
#endif
#ifndef skip_glBlendFunc
void glBlendFunc(GLenum sfactor, GLenum dfactor) {
    printf("glBlendFunc(%u, %u);\n", sfactor, dfactor);
}
#endif
#ifndef skip_glBlendFuncSeparate
void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
    printf("glBlendFuncSeparate(%u, %u, %u, %u);\n", sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
#endif
#ifndef skip_glBufferData
void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage) {
    printf("glBufferData(%u, %d, %p, %u);\n", target, size, data, usage);
}
#endif
#ifndef skip_glBufferSubData
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data) {
    printf("glBufferSubData(%u, %d, %d, %p);\n", target, offset, size, data);
}
#endif
#ifndef skip_glCallList
void glCallList(GLuint list) {
    printf("glCallList(%u);\n", list);
}
#endif
#ifndef skip_glCallLists
void glCallLists(GLsizei n, GLenum type, const GLvoid * lists) {
    printf("glCallLists(%d, %u, %p);\n", n, type, lists);
}
#endif
#ifndef skip_glClear
void glClear(GLbitfield mask) {
    printf("glClear(%d);\n", mask);
}
#endif
#ifndef skip_glClearAccum
void glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    printf("glClearAccum(%0.2f, %0.2f, %0.2f, %0.2f);\n", red, green, blue, alpha);
}
#endif
#ifndef skip_glClearColor
void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    printf("glClearColor(%0.2f, %0.2f, %0.2f, %0.2f);\n", red, green, blue, alpha);
}
#endif
#ifndef skip_glClearDepth
void glClearDepth(GLdouble depth) {
    printf("glClearDepth(%0.2f);\n", depth);
}
#endif
#ifndef skip_glClearIndex
void glClearIndex(GLfloat c) {
    printf("glClearIndex(%0.2f);\n", c);
}
#endif
#ifndef skip_glClearStencil
void glClearStencil(GLint s) {
    printf("glClearStencil(%d);\n", s);
}
#endif
#ifndef skip_glClientActiveTexture
void glClientActiveTexture(GLenum texture) {
    printf("glClientActiveTexture(%u);\n", texture);
}
#endif
#ifndef skip_glClipPlane
void glClipPlane(GLenum plane, const GLdouble * equation) {
    printf("glClipPlane(%u, %p);\n", plane, equation);
}
#endif
#ifndef skip_glColor3b
void glColor3b(GLbyte red, GLbyte green, GLbyte blue) {
    printf("glColor3b(%c, %c, %c);\n", red, green, blue);
}
#endif
#ifndef skip_glColor3bv
void glColor3bv(const GLbyte * v) {
    printf("glColor3bv(%p);\n", v);
}
#endif
#ifndef skip_glColor3d
void glColor3d(GLdouble red, GLdouble green, GLdouble blue) {
    printf("glColor3d(%0.2f, %0.2f, %0.2f);\n", red, green, blue);
}
#endif
#ifndef skip_glColor3dv
void glColor3dv(const GLdouble * v) {
    printf("glColor3dv(%p);\n", v);
}
#endif
#ifndef skip_glColor3f
void glColor3f(GLfloat red, GLfloat green, GLfloat blue) {
    printf("glColor3f(%0.2f, %0.2f, %0.2f);\n", red, green, blue);
}
#endif
#ifndef skip_glColor3fv
void glColor3fv(const GLfloat * v) {
    printf("glColor3fv(%p);\n", v);
}
#endif
#ifndef skip_glColor3i
void glColor3i(GLint red, GLint green, GLint blue) {
    printf("glColor3i(%d, %d, %d);\n", red, green, blue);
}
#endif
#ifndef skip_glColor3iv
void glColor3iv(const GLint * v) {
    printf("glColor3iv(%p);\n", v);
}
#endif
#ifndef skip_glColor3s
void glColor3s(GLshort red, GLshort green, GLshort blue) {
    printf("glColor3s(%d, %d, %d);\n", red, green, blue);
}
#endif
#ifndef skip_glColor3sv
void glColor3sv(const GLshort * v) {
    printf("glColor3sv(%p);\n", v);
}
#endif
#ifndef skip_glColor3ub
void glColor3ub(GLubyte red, GLubyte green, GLubyte blue) {
    printf("glColor3ub(%c, %c, %c);\n", red, green, blue);
}
#endif
#ifndef skip_glColor3ubv
void glColor3ubv(const GLubyte * v) {
    printf("glColor3ubv(%p);\n", v);
}
#endif
#ifndef skip_glColor3ui
void glColor3ui(GLuint red, GLuint green, GLuint blue) {
    printf("glColor3ui(%u, %u, %u);\n", red, green, blue);
}
#endif
#ifndef skip_glColor3uiv
void glColor3uiv(const GLuint * v) {
    printf("glColor3uiv(%p);\n", v);
}
#endif
#ifndef skip_glColor3us
void glColor3us(GLushort red, GLushort green, GLushort blue) {
    printf("glColor3us(%u, %u, %u);\n", red, green, blue);
}
#endif
#ifndef skip_glColor3usv
void glColor3usv(const GLushort * v) {
    printf("glColor3usv(%p);\n", v);
}
#endif
#ifndef skip_glColor4b
void glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha) {
    printf("glColor4b(%c, %c, %c, %c);\n", red, green, blue, alpha);
}
#endif
#ifndef skip_glColor4bv
void glColor4bv(const GLbyte * v) {
    printf("glColor4bv(%p);\n", v);
}
#endif
#ifndef skip_glColor4d
void glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha) {
    printf("glColor4d(%0.2f, %0.2f, %0.2f, %0.2f);\n", red, green, blue, alpha);
}
#endif
#ifndef skip_glColor4dv
void glColor4dv(const GLdouble * v) {
    printf("glColor4dv(%p);\n", v);
}
#endif
#ifndef skip_glColor4f
void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    printf("glColor4f(%0.2f, %0.2f, %0.2f, %0.2f);\n", red, green, blue, alpha);
}
#endif
#ifndef skip_glColor4fv
void glColor4fv(const GLfloat * v) {
    printf("glColor4fv(%p);\n", v);
}
#endif
#ifndef skip_glColor4i
void glColor4i(GLint red, GLint green, GLint blue, GLint alpha) {
    printf("glColor4i(%d, %d, %d, %d);\n", red, green, blue, alpha);
}
#endif
#ifndef skip_glColor4iv
void glColor4iv(const GLint * v) {
    printf("glColor4iv(%p);\n", v);
}
#endif
#ifndef skip_glColor4s
void glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha) {
    printf("glColor4s(%d, %d, %d, %d);\n", red, green, blue, alpha);
}
#endif
#ifndef skip_glColor4sv
void glColor4sv(const GLshort * v) {
    printf("glColor4sv(%p);\n", v);
}
#endif
#ifndef skip_glColor4ub
void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {
    printf("glColor4ub(%c, %c, %c, %c);\n", red, green, blue, alpha);
}
#endif
#ifndef skip_glColor4ubv
void glColor4ubv(const GLubyte * v) {
    printf("glColor4ubv(%p);\n", v);
}
#endif
#ifndef skip_glColor4ui
void glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha) {
    printf("glColor4ui(%u, %u, %u, %u);\n", red, green, blue, alpha);
}
#endif
#ifndef skip_glColor4uiv
void glColor4uiv(const GLuint * v) {
    printf("glColor4uiv(%p);\n", v);
}
#endif
#ifndef skip_glColor4us
void glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha) {
    printf("glColor4us(%u, %u, %u, %u);\n", red, green, blue, alpha);
}
#endif
#ifndef skip_glColor4usv
void glColor4usv(const GLushort * v) {
    printf("glColor4usv(%p);\n", v);
}
#endif
#ifndef skip_glColorMask
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
    printf("glColorMask(%d, %d, %d, %d);\n", red, green, blue, alpha);
}
#endif
#ifndef skip_glColorMaterial
void glColorMaterial(GLenum face, GLenum mode) {
    printf("glColorMaterial(%u, %u);\n", face, mode);
}
#endif
#ifndef skip_glColorPointer
void glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    printf("glColorPointer(%d, %u, %d, %p);\n", size, type, stride, pointer);
}
#endif
#ifndef skip_glColorSubTable
void glColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid * data) {
    printf("glColorSubTable(%u, %d, %d, %u, %u, %p);\n", target, start, count, format, type, data);
}
#endif
#ifndef skip_glColorTable
void glColorTable(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * table) {
    printf("glColorTable(%u, %u, %d, %u, %u, %p);\n", target, internalformat, width, format, type, table);
}
#endif
#ifndef skip_glColorTableParameterfv
void glColorTableParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    printf("glColorTableParameterfv(%u, %u, %p);\n", target, pname, params);
}
#endif
#ifndef skip_glColorTableParameteriv
void glColorTableParameteriv(GLenum target, GLenum pname, const GLint * params) {
    printf("glColorTableParameteriv(%u, %u, %p);\n", target, pname, params);
}
#endif
#ifndef skip_glCompressedTexImage1D
void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid * data) {
    printf("glCompressedTexImage1D(%u, %d, %u, %d, %d, %d, %p);\n", target, level, internalformat, width, border, imageSize, data);
}
#endif
#ifndef skip_glCompressedTexImage2D
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data) {
    printf("glCompressedTexImage2D(%u, %d, %u, %d, %d, %d, %d, %p);\n", target, level, internalformat, width, height, border, imageSize, data);
}
#endif
#ifndef skip_glCompressedTexImage3D
void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid * data) {
    printf("glCompressedTexImage3D(%u, %d, %u, %d, %d, %d, %d, %d, %p);\n", target, level, internalformat, width, height, depth, border, imageSize, data);
}
#endif
#ifndef skip_glCompressedTexSubImage1D
void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid * data) {
    printf("glCompressedTexSubImage1D(%u, %d, %d, %d, %u, %d, %p);\n", target, level, xoffset, width, format, imageSize, data);
}
#endif
#ifndef skip_glCompressedTexSubImage2D
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data) {
    printf("glCompressedTexSubImage2D(%u, %d, %d, %d, %d, %d, %u, %d, %p);\n", target, level, xoffset, yoffset, width, height, format, imageSize, data);
}
#endif
#ifndef skip_glCompressedTexSubImage3D
void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid * data) {
    printf("glCompressedTexSubImage3D(%u, %d, %d, %d, %d, %d, %d, %d, %u, %d, %p);\n", target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}
#endif
#ifndef skip_glConvolutionFilter1D
void glConvolutionFilter1D(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * image) {
    printf("glConvolutionFilter1D(%u, %u, %d, %u, %u, %p);\n", target, internalformat, width, format, type, image);
}
#endif
#ifndef skip_glConvolutionFilter2D
void glConvolutionFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * image) {
    printf("glConvolutionFilter2D(%u, %u, %d, %d, %u, %u, %p);\n", target, internalformat, width, height, format, type, image);
}
#endif
#ifndef skip_glConvolutionParameterf
void glConvolutionParameterf(GLenum target, GLenum pname, GLfloat params) {
    printf("glConvolutionParameterf(%u, %u, %0.2f);\n", target, pname, params);
}
#endif
#ifndef skip_glConvolutionParameterfv
void glConvolutionParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    printf("glConvolutionParameterfv(%u, %u, %p);\n", target, pname, params);
}
#endif
#ifndef skip_glConvolutionParameteri
void glConvolutionParameteri(GLenum target, GLenum pname, GLint params) {
    printf("glConvolutionParameteri(%u, %u, %d);\n", target, pname, params);
}
#endif
#ifndef skip_glConvolutionParameteriv
void glConvolutionParameteriv(GLenum target, GLenum pname, const GLint * params) {
    printf("glConvolutionParameteriv(%u, %u, %p);\n", target, pname, params);
}
#endif
#ifndef skip_glCopyColorSubTable
void glCopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width) {
    printf("glCopyColorSubTable(%u, %d, %d, %d, %d);\n", target, start, x, y, width);
}
#endif
#ifndef skip_glCopyColorTable
void glCopyColorTable(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
    printf("glCopyColorTable(%u, %u, %d, %d, %d);\n", target, internalformat, x, y, width);
}
#endif
#ifndef skip_glCopyConvolutionFilter1D
void glCopyConvolutionFilter1D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
    printf("glCopyConvolutionFilter1D(%u, %u, %d, %d, %d);\n", target, internalformat, x, y, width);
}
#endif
#ifndef skip_glCopyConvolutionFilter2D
void glCopyConvolutionFilter2D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height) {
    printf("glCopyConvolutionFilter2D(%u, %u, %d, %d, %d, %d);\n", target, internalformat, x, y, width, height);
}
#endif
#ifndef skip_glCopyPixels
void glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type) {
    printf("glCopyPixels(%d, %d, %d, %d, %u);\n", x, y, width, height, type);
}
#endif
#ifndef skip_glCopyTexImage1D
void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
    printf("glCopyTexImage1D(%u, %d, %u, %d, %d, %d, %d);\n", target, level, internalformat, x, y, width, border);
}
#endif
#ifndef skip_glCopyTexImage2D
void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    printf("glCopyTexImage2D(%u, %d, %u, %d, %d, %d, %d, %d);\n", target, level, internalformat, x, y, width, height, border);
}
#endif
#ifndef skip_glCopyTexSubImage1D
void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    printf("glCopyTexSubImage1D(%u, %d, %d, %d, %d, %d);\n", target, level, xoffset, x, y, width);
}
#endif
#ifndef skip_glCopyTexSubImage2D
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    printf("glCopyTexSubImage2D(%u, %d, %d, %d, %d, %d, %d, %d);\n", target, level, xoffset, yoffset, x, y, width, height);
}
#endif
#ifndef skip_glCopyTexSubImage3D
void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    printf("glCopyTexSubImage3D(%u, %d, %d, %d, %d, %d, %d, %d, %d);\n", target, level, xoffset, yoffset, zoffset, x, y, width, height);
}
#endif
#ifndef skip_glCullFace
void glCullFace(GLenum mode) {
    printf("glCullFace(%u);\n", mode);
}
#endif
#ifndef skip_glDeleteBuffers
void glDeleteBuffers(GLsizei n, const GLuint * buffers) {
    printf("glDeleteBuffers(%d, %p);\n", n, buffers);
}
#endif
#ifndef skip_glDeleteLists
void glDeleteLists(GLuint list, GLsizei range) {
    printf("glDeleteLists(%u, %d);\n", list, range);
}
#endif
#ifndef skip_glDeleteQueries
void glDeleteQueries(GLsizei n, const GLuint * ids) {
    printf("glDeleteQueries(%d, %p);\n", n, ids);
}
#endif
#ifndef skip_glDeleteTextures
void glDeleteTextures(GLsizei n, const GLuint * textures) {
    printf("glDeleteTextures(%d, %p);\n", n, textures);
}
#endif
#ifndef skip_glDepthFunc
void glDepthFunc(GLenum func) {
    printf("glDepthFunc(%u);\n", func);
}
#endif
#ifndef skip_glDepthMask
void glDepthMask(GLboolean flag) {
    printf("glDepthMask(%d);\n", flag);
}
#endif
#ifndef skip_glDepthRange
void glDepthRange(GLdouble near, GLdouble far) {
    printf("glDepthRange(%0.2f, %0.2f);\n", near, far);
}
#endif
#ifndef skip_glDisable
void glDisable(GLenum cap) {
    printf("glDisable(%u);\n", cap);
}
#endif
#ifndef skip_glDisableClientState
void glDisableClientState(GLenum array) {
    printf("glDisableClientState(%u);\n", array);
}
#endif
#ifndef skip_glDrawArrays
void glDrawArrays(GLenum mode, GLint first, GLsizei count) {
    printf("glDrawArrays(%u, %d, %d);\n", mode, first, count);
}
#endif
#ifndef skip_glDrawBuffer
void glDrawBuffer(GLenum mode) {
    printf("glDrawBuffer(%u);\n", mode);
}
#endif
#ifndef skip_glDrawElements
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices) {
    printf("glDrawElements(%u, %d, %u, %p);\n", mode, count, type, indices);
}
#endif
#ifndef skip_glDrawPixels
void glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels) {
    printf("glDrawPixels(%d, %d, %u, %u, %p);\n", width, height, format, type, pixels);
}
#endif
#ifndef skip_glDrawRangeElements
void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid * indices) {
    printf("glDrawRangeElements(%u, %u, %u, %d, %u, %p);\n", mode, start, end, count, type, indices);
}
#endif
#ifndef skip_glEdgeFlag
void glEdgeFlag(GLboolean flag) {
    printf("glEdgeFlag(%d);\n", flag);
}
#endif
#ifndef skip_glEdgeFlagPointer
void glEdgeFlagPointer(GLsizei stride, const GLvoid * pointer) {
    printf("glEdgeFlagPointer(%d, %p);\n", stride, pointer);
}
#endif
#ifndef skip_glEdgeFlagv
void glEdgeFlagv(const GLboolean * flag) {
    printf("glEdgeFlagv(%p);\n", flag);
}
#endif
#ifndef skip_glEnable
void glEnable(GLenum cap) {
    printf("glEnable(%u);\n", cap);
}
#endif
#ifndef skip_glEnableClientState
void glEnableClientState(GLenum array) {
    printf("glEnableClientState(%u);\n", array);
}
#endif
#ifndef skip_glEnd
void glEnd() {
    printf("glEnd();\n");
}
#endif
#ifndef skip_glEndList
void glEndList() {
    printf("glEndList();\n");
}
#endif
#ifndef skip_glEndQuery
void glEndQuery(GLenum target) {
    printf("glEndQuery(%u);\n", target);
}
#endif
#ifndef skip_glEvalCoord1d
void glEvalCoord1d(GLdouble u) {
    printf("glEvalCoord1d(%0.2f);\n", u);
}
#endif
#ifndef skip_glEvalCoord1dv
void glEvalCoord1dv(const GLdouble * u) {
    printf("glEvalCoord1dv(%p);\n", u);
}
#endif
#ifndef skip_glEvalCoord1f
void glEvalCoord1f(GLfloat u) {
    printf("glEvalCoord1f(%0.2f);\n", u);
}
#endif
#ifndef skip_glEvalCoord1fv
void glEvalCoord1fv(const GLfloat * u) {
    printf("glEvalCoord1fv(%p);\n", u);
}
#endif
#ifndef skip_glEvalCoord2d
void glEvalCoord2d(GLdouble u, GLdouble v) {
    printf("glEvalCoord2d(%0.2f, %0.2f);\n", u, v);
}
#endif
#ifndef skip_glEvalCoord2dv
void glEvalCoord2dv(const GLdouble * u) {
    printf("glEvalCoord2dv(%p);\n", u);
}
#endif
#ifndef skip_glEvalCoord2f
void glEvalCoord2f(GLfloat u, GLfloat v) {
    printf("glEvalCoord2f(%0.2f, %0.2f);\n", u, v);
}
#endif
#ifndef skip_glEvalCoord2fv
void glEvalCoord2fv(const GLfloat * u) {
    printf("glEvalCoord2fv(%p);\n", u);
}
#endif
#ifndef skip_glEvalMesh1
void glEvalMesh1(GLenum mode, GLint i1, GLint i2) {
    printf("glEvalMesh1(%u, %d, %d);\n", mode, i1, i2);
}
#endif
#ifndef skip_glEvalMesh2
void glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2) {
    printf("glEvalMesh2(%u, %d, %d, %d, %d);\n", mode, i1, i2, j1, j2);
}
#endif
#ifndef skip_glEvalPoint1
void glEvalPoint1(GLint i) {
    printf("glEvalPoint1(%d);\n", i);
}
#endif
#ifndef skip_glEvalPoint2
void glEvalPoint2(GLint i, GLint j) {
    printf("glEvalPoint2(%d, %d);\n", i, j);
}
#endif
#ifndef skip_glFeedbackBuffer
void glFeedbackBuffer(GLsizei size, GLenum type, GLfloat * buffer) {
    printf("glFeedbackBuffer(%d, %u, %p);\n", size, type, buffer);
}
#endif
#ifndef skip_glFinish
void glFinish() {
    printf("glFinish();\n");
}
#endif
#ifndef skip_glFlush
void glFlush() {
    printf("glFlush();\n");
}
#endif
#ifndef skip_glFogCoordPointer
void glFogCoordPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    printf("glFogCoordPointer(%u, %d, %p);\n", type, stride, pointer);
}
#endif
#ifndef skip_glFogCoordd
void glFogCoordd(GLdouble coord) {
    printf("glFogCoordd(%0.2f);\n", coord);
}
#endif
#ifndef skip_glFogCoorddv
void glFogCoorddv(const GLdouble * coord) {
    printf("glFogCoorddv(%p);\n", coord);
}
#endif
#ifndef skip_glFogCoordf
void glFogCoordf(GLfloat coord) {
    printf("glFogCoordf(%0.2f);\n", coord);
}
#endif
#ifndef skip_glFogCoordfv
void glFogCoordfv(const GLfloat * coord) {
    printf("glFogCoordfv(%p);\n", coord);
}
#endif
#ifndef skip_glFogf
void glFogf(GLenum pname, GLfloat param) {
    printf("glFogf(%u, %0.2f);\n", pname, param);
}
#endif
#ifndef skip_glFogfv
void glFogfv(GLenum pname, const GLfloat * params) {
    printf("glFogfv(%u, %p);\n", pname, params);
}
#endif
#ifndef skip_glFogi
void glFogi(GLenum pname, GLint param) {
    printf("glFogi(%u, %d);\n", pname, param);
}
#endif
#ifndef skip_glFogiv
void glFogiv(GLenum pname, const GLint * params) {
    printf("glFogiv(%u, %p);\n", pname, params);
}
#endif
#ifndef skip_glFrontFace
void glFrontFace(GLenum mode) {
    printf("glFrontFace(%u);\n", mode);
}
#endif
#ifndef skip_glFrustum
void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
    printf("glFrustum(%0.2f, %0.2f, %0.2f, %0.2f, %0.2f, %0.2f);\n", left, right, bottom, top, zNear, zFar);
}
#endif
#ifndef skip_glGenBuffers
void glGenBuffers(GLsizei n, GLuint * buffers) {
    printf("glGenBuffers(%d, %p);\n", n, buffers);
}
#endif
#ifndef skip_glGenLists
GLuint glGenLists(GLsizei range) {
    printf("glGenLists(%d);\n", range);
    return 0;
}
#endif
#ifndef skip_glGenQueries
void glGenQueries(GLsizei n, GLuint * ids) {
    printf("glGenQueries(%d, %p);\n", n, ids);
}
#endif
#ifndef skip_glGenTextures
void glGenTextures(GLsizei n, GLuint * textures) {
    printf("glGenTextures(%d, %p);\n", n, textures);
}
#endif
#ifndef skip_glGetBooleanv
void glGetBooleanv(GLenum pname, GLboolean * params) {
    printf("glGetBooleanv(%u, %p);\n", pname, params);
}
#endif
#ifndef skip_glGetBufferParameteriv
void glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    printf("glGetBufferParameteriv(%u, %u, %p);\n", target, pname, params);
}
#endif
#ifndef skip_glGetBufferPointerv
void glGetBufferPointerv(GLenum target, GLenum pname, GLvoid * params) {
    printf("glGetBufferPointerv(%u, %u, %p);\n", target, pname, params);
}
#endif
#ifndef skip_glGetBufferSubData
void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data) {
    printf("glGetBufferSubData(%u, %d, %d, %p);\n", target, offset, size, data);
}
#endif
#ifndef skip_glGetClipPlane
void glGetClipPlane(GLenum plane, GLdouble * equation) {
    printf("glGetClipPlane(%u, %p);\n", plane, equation);
}
#endif
#ifndef skip_glGetColorTable
void glGetColorTable(GLenum target, GLenum format, GLenum type, GLvoid * table) {
    printf("glGetColorTable(%u, %u, %u, %p);\n", target, format, type, table);
}
#endif
#ifndef skip_glGetColorTableParameterfv
void glGetColorTableParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    printf("glGetColorTableParameterfv(%u, %u, %p);\n", target, pname, params);
}
#endif
#ifndef skip_glGetColorTableParameteriv
void glGetColorTableParameteriv(GLenum target, GLenum pname, GLint * params) {
    printf("glGetColorTableParameteriv(%u, %u, %p);\n", target, pname, params);
}
#endif
#ifndef skip_glGetCompressedTexImage
void glGetCompressedTexImage(GLenum target, GLint level, GLvoid * img) {
    printf("glGetCompressedTexImage(%u, %d, %p);\n", target, level, img);
}
#endif
#ifndef skip_glGetConvolutionFilter
void glGetConvolutionFilter(GLenum target, GLenum format, GLenum type, GLvoid * image) {
    printf("glGetConvolutionFilter(%u, %u, %u, %p);\n", target, format, type, image);
}
#endif
#ifndef skip_glGetConvolutionParameterfv
void glGetConvolutionParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    printf("glGetConvolutionParameterfv(%u, %u, %p);\n", target, pname, params);
}
#endif
#ifndef skip_glGetConvolutionParameteriv
void glGetConvolutionParameteriv(GLenum target, GLenum pname, GLint * params) {
    printf("glGetConvolutionParameteriv(%u, %u, %p);\n", target, pname, params);
}
#endif
#ifndef skip_glGetDoublev
void glGetDoublev(GLenum pname, GLdouble * params) {
    printf("glGetDoublev(%u, %p);\n", pname, params);
}
#endif
#ifndef skip_glGetError
GLenum glGetError() {
    printf("glGetError();\n");
    return 0;
}
#endif
#ifndef skip_glGetFloatv
void glGetFloatv(GLenum pname, GLfloat * params) {
    printf("glGetFloatv(%u, %p);\n", pname, params);
}
#endif
#ifndef skip_glGetHistogram
void glGetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values) {
    printf("glGetHistogram(%u, %d, %u, %u, %p);\n", target, reset, format, type, values);
}
#endif
#ifndef skip_glGetHistogramParameterfv
void glGetHistogramParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    printf("glGetHistogramParameterfv(%u, %u, %p);\n", target, pname, params);
}
#endif
#ifndef skip_glGetHistogramParameteriv
void glGetHistogramParameteriv(GLenum target, GLenum pname, GLint * params) {
    printf("glGetHistogramParameteriv(%u, %u, %p);\n", target, pname, params);
}
#endif
#ifndef skip_glGetIntegerv
void glGetIntegerv(GLenum pname, GLint * params) {
    printf("glGetIntegerv(%u, %p);\n", pname, params);
}
#endif
#ifndef skip_glGetLightfv
void glGetLightfv(GLenum light, GLenum pname, GLfloat * params) {
    printf("glGetLightfv(%u, %u, %p);\n", light, pname, params);
}
#endif
#ifndef skip_glGetLightiv
void glGetLightiv(GLenum light, GLenum pname, GLint * params) {
    printf("glGetLightiv(%u, %u, %p);\n", light, pname, params);
}
#endif
#ifndef skip_glGetMapdv
void glGetMapdv(GLenum target, GLenum query, GLdouble * v) {
    printf("glGetMapdv(%u, %u, %p);\n", target, query, v);
}
#endif
#ifndef skip_glGetMapfv
void glGetMapfv(GLenum target, GLenum query, GLfloat * v) {
    printf("glGetMapfv(%u, %u, %p);\n", target, query, v);
}
#endif
#ifndef skip_glGetMapiv
void glGetMapiv(GLenum target, GLenum query, GLint * v) {
    printf("glGetMapiv(%u, %u, %p);\n", target, query, v);
}
#endif
#ifndef skip_glGetMaterialfv
void glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params) {
    printf("glGetMaterialfv(%u, %u, %p);\n", face, pname, params);
}
#endif
#ifndef skip_glGetMaterialiv
void glGetMaterialiv(GLenum face, GLenum pname, GLint * params) {
    printf("glGetMaterialiv(%u, %u, %p);\n", face, pname, params);
}
#endif
#ifndef skip_glGetMinmax
void glGetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values) {
    printf("glGetMinmax(%u, %d, %u, %u, %p);\n", target, reset, format, type, values);
}
#endif
#ifndef skip_glGetMinmaxParameterfv
void glGetMinmaxParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    printf("glGetMinmaxParameterfv(%u, %u, %p);\n", target, pname, params);
}
#endif
#ifndef skip_glGetMinmaxParameteriv
void glGetMinmaxParameteriv(GLenum target, GLenum pname, GLint * params) {
    printf("glGetMinmaxParameteriv(%u, %u, %p);\n", target, pname, params);
}
#endif
#ifndef skip_glGetPixelMapfv
void glGetPixelMapfv(GLenum map, GLfloat * values) {
    printf("glGetPixelMapfv(%u, %p);\n", map, values);
}
#endif
#ifndef skip_glGetPixelMapuiv
void glGetPixelMapuiv(GLenum map, GLuint * values) {
    printf("glGetPixelMapuiv(%u, %p);\n", map, values);
}
#endif
#ifndef skip_glGetPixelMapusv
void glGetPixelMapusv(GLenum map, GLushort * values) {
    printf("glGetPixelMapusv(%u, %p);\n", map, values);
}
#endif
#ifndef skip_glGetPointerv
void glGetPointerv(GLenum pname, GLvoid ** params) {
    printf("glGetPointerv(%u, %p);\n", pname, params);
}
#endif
#ifndef skip_glGetPolygonStipple
void glGetPolygonStipple(GLubyte * mask) {
    printf("glGetPolygonStipple(%p);\n", mask);
}
#endif
#ifndef skip_glGetQueryObjectiv
void glGetQueryObjectiv(GLuint id, GLenum pname, GLint * params) {
    printf("glGetQueryObjectiv(%u, %u, %p);\n", id, pname, params);
}
#endif
#ifndef skip_glGetQueryObjectuiv
void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint * params) {
    printf("glGetQueryObjectuiv(%u, %u, %p);\n", id, pname, params);
}
#endif
#ifndef skip_glGetQueryiv
void glGetQueryiv(GLenum target, GLenum pname, GLint * params) {
    printf("glGetQueryiv(%u, %u, %p);\n", target, pname, params);
}
#endif
#ifndef skip_glGetSeparableFilter
void glGetSeparableFilter(GLenum target, GLenum format, GLenum type, GLvoid * row, GLvoid * column, GLvoid * span) {
    printf("glGetSeparableFilter(%u, %u, %u, %p, %p, %p);\n", target, format, type, row, column, span);
}
#endif
#ifndef skip_glGetString
const GLubyte * glGetString(GLenum name) {
    printf("glGetString(%u);\n", name);
    return 0;
}
#endif
#ifndef skip_glGetTexEnvfv
void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params) {
    printf("glGetTexEnvfv(%u, %u, %p);\n", target, pname, params);
}
#endif
#ifndef skip_glGetTexEnviv
void glGetTexEnviv(GLenum target, GLenum pname, GLint * params) {
    printf("glGetTexEnviv(%u, %u, %p);\n", target, pname, params);
}
#endif
#ifndef skip_glGetTexGendv
void glGetTexGendv(GLenum coord, GLenum pname, GLdouble * params) {
    printf("glGetTexGendv(%u, %u, %p);\n", coord, pname, params);
}
#endif
#ifndef skip_glGetTexGenfv
void glGetTexGenfv(GLenum coord, GLenum pname, GLfloat * params) {
    printf("glGetTexGenfv(%u, %u, %p);\n", coord, pname, params);
}
#endif
#ifndef skip_glGetTexGeniv
void glGetTexGeniv(GLenum coord, GLenum pname, GLint * params) {
    printf("glGetTexGeniv(%u, %u, %p);\n", coord, pname, params);
}
#endif
#ifndef skip_glGetTexImage
void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid * pixels) {
    printf("glGetTexImage(%u, %d, %u, %u, %p);\n", target, level, format, type, pixels);
}
#endif
#ifndef skip_glGetTexLevelParameterfv
void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat * params) {
    printf("glGetTexLevelParameterfv(%u, %d, %u, %p);\n", target, level, pname, params);
}
#endif
#ifndef skip_glGetTexLevelParameteriv
void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint * params) {
    printf("glGetTexLevelParameteriv(%u, %d, %u, %p);\n", target, level, pname, params);
}
#endif
#ifndef skip_glGetTexParameterfv
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    printf("glGetTexParameterfv(%u, %u, %p);\n", target, pname, params);
}
#endif
#ifndef skip_glGetTexParameteriv
void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params) {
    printf("glGetTexParameteriv(%u, %u, %p);\n", target, pname, params);
}
#endif
#ifndef skip_glHint
void glHint(GLenum target, GLenum mode) {
    printf("glHint(%u, %u);\n", target, mode);
}
#endif
#ifndef skip_glHistogram
void glHistogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink) {
    printf("glHistogram(%u, %d, %u, %d);\n", target, width, internalformat, sink);
}
#endif
#ifndef skip_glIndexMask
void glIndexMask(GLuint mask) {
    printf("glIndexMask(%u);\n", mask);
}
#endif
#ifndef skip_glIndexPointer
void glIndexPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    printf("glIndexPointer(%u, %d, %p);\n", type, stride, pointer);
}
#endif
#ifndef skip_glIndexd
void glIndexd(GLdouble c) {
    printf("glIndexd(%0.2f);\n", c);
}
#endif
#ifndef skip_glIndexdv
void glIndexdv(const GLdouble * c) {
    printf("glIndexdv(%p);\n", c);
}
#endif
#ifndef skip_glIndexf
void glIndexf(GLfloat c) {
    printf("glIndexf(%0.2f);\n", c);
}
#endif
#ifndef skip_glIndexfv
void glIndexfv(const GLfloat * c) {
    printf("glIndexfv(%p);\n", c);
}
#endif
#ifndef skip_glIndexi
void glIndexi(GLint c) {
    printf("glIndexi(%d);\n", c);
}
#endif
#ifndef skip_glIndexiv
void glIndexiv(const GLint * c) {
    printf("glIndexiv(%p);\n", c);
}
#endif
#ifndef skip_glIndexs
void glIndexs(GLshort c) {
    printf("glIndexs(%d);\n", c);
}
#endif
#ifndef skip_glIndexsv
void glIndexsv(const GLshort * c) {
    printf("glIndexsv(%p);\n", c);
}
#endif
#ifndef skip_glIndexub
void glIndexub(GLubyte c) {
    printf("glIndexub(%c);\n", c);
}
#endif
#ifndef skip_glIndexubv
void glIndexubv(const GLubyte * c) {
    printf("glIndexubv(%p);\n", c);
}
#endif
#ifndef skip_glInitNames
void glInitNames() {
    printf("glInitNames();\n");
}
#endif
#ifndef skip_glInterleavedArrays
void glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid * pointer) {
    printf("glInterleavedArrays(%u, %d, %p);\n", format, stride, pointer);
}
#endif
#ifndef skip_glIsBuffer
GLboolean glIsBuffer(GLuint buffer) {
    printf("glIsBuffer(%u);\n", buffer);
    return 0;
}
#endif
#ifndef skip_glIsEnabled
GLboolean glIsEnabled(GLenum cap) {
    printf("glIsEnabled(%u);\n", cap);
    return 0;
}
#endif
#ifndef skip_glIsList
GLboolean glIsList(GLuint list) {
    printf("glIsList(%u);\n", list);
    return 0;
}
#endif
#ifndef skip_glIsQuery
GLboolean glIsQuery(GLuint id) {
    printf("glIsQuery(%u);\n", id);
    return 0;
}
#endif
#ifndef skip_glIsTexture
GLboolean glIsTexture(GLuint texture) {
    printf("glIsTexture(%u);\n", texture);
    return 0;
}
#endif
#ifndef skip_glLightModelf
void glLightModelf(GLenum pname, GLfloat param) {
    printf("glLightModelf(%u, %0.2f);\n", pname, param);
}
#endif
#ifndef skip_glLightModelfv
void glLightModelfv(GLenum pname, const GLfloat * params) {
    printf("glLightModelfv(%u, %p);\n", pname, params);
}
#endif
#ifndef skip_glLightModeli
void glLightModeli(GLenum pname, GLint param) {
    printf("glLightModeli(%u, %d);\n", pname, param);
}
#endif
#ifndef skip_glLightModeliv
void glLightModeliv(GLenum pname, const GLint * params) {
    printf("glLightModeliv(%u, %p);\n", pname, params);
}
#endif
#ifndef skip_glLightf
void glLightf(GLenum light, GLenum pname, GLfloat param) {
    printf("glLightf(%u, %u, %0.2f);\n", light, pname, param);
}
#endif
#ifndef skip_glLightfv
void glLightfv(GLenum light, GLenum pname, const GLfloat * params) {
    printf("glLightfv(%u, %u, %p);\n", light, pname, params);
}
#endif
#ifndef skip_glLighti
void glLighti(GLenum light, GLenum pname, GLint param) {
    printf("glLighti(%u, %u, %d);\n", light, pname, param);
}
#endif
#ifndef skip_glLightiv
void glLightiv(GLenum light, GLenum pname, const GLint * params) {
    printf("glLightiv(%u, %u, %p);\n", light, pname, params);
}
#endif
#ifndef skip_glLineStipple
void glLineStipple(GLint factor, GLushort pattern) {
    printf("glLineStipple(%d, %u);\n", factor, pattern);
}
#endif
#ifndef skip_glLineWidth
void glLineWidth(GLfloat width) {
    printf("glLineWidth(%0.2f);\n", width);
}
#endif
#ifndef skip_glListBase
void glListBase(GLuint base) {
    printf("glListBase(%u);\n", base);
}
#endif
#ifndef skip_glLoadIdentity
void glLoadIdentity() {
    printf("glLoadIdentity();\n");
}
#endif
#ifndef skip_glLoadMatrixd
void glLoadMatrixd(const GLdouble * m) {
    printf("glLoadMatrixd(%p);\n", m);
}
#endif
#ifndef skip_glLoadMatrixf
void glLoadMatrixf(const GLfloat * m) {
    printf("glLoadMatrixf(%p);\n", m);
}
#endif
#ifndef skip_glLoadName
void glLoadName(GLuint name) {
    printf("glLoadName(%u);\n", name);
}
#endif
#ifndef skip_glLoadTransposeMatrixd
void glLoadTransposeMatrixd(const GLdouble * m) {
    printf("glLoadTransposeMatrixd(%p);\n", m);
}
#endif
#ifndef skip_glLoadTransposeMatrixf
void glLoadTransposeMatrixf(const GLfloat * m) {
    printf("glLoadTransposeMatrixf(%p);\n", m);
}
#endif
#ifndef skip_glLogicOp
void glLogicOp(GLenum opcode) {
    printf("glLogicOp(%u);\n", opcode);
}
#endif
#ifndef skip_glMap1d
void glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble * points) {
    printf("glMap1d(%u, %0.2f, %0.2f, %d, %d, %p);\n", target, u1, u2, stride, order, points);
}
#endif
#ifndef skip_glMap1f
void glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat * points) {
    printf("glMap1f(%u, %0.2f, %0.2f, %d, %d, %p);\n", target, u1, u2, stride, order, points);
}
#endif
#ifndef skip_glMap2d
void glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble * points) {
    printf("glMap2d(%u, %0.2f, %0.2f, %d, %d, %0.2f, %0.2f, %d, %d, %p);\n", target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}
#endif
#ifndef skip_glMap2f
void glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat * points) {
    printf("glMap2f(%u, %0.2f, %0.2f, %d, %d, %0.2f, %0.2f, %d, %d, %p);\n", target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}
#endif
#ifndef skip_glMapBuffer
GLvoid * glMapBuffer(GLenum target, GLenum access) {
    printf("glMapBuffer(%u, %u);\n", target, access);
    return 0;
}
#endif
#ifndef skip_glMapGrid1d
void glMapGrid1d(GLint un, GLdouble u1, GLdouble u2) {
    printf("glMapGrid1d(%d, %0.2f, %0.2f);\n", un, u1, u2);
}
#endif
#ifndef skip_glMapGrid1f
void glMapGrid1f(GLint un, GLfloat u1, GLfloat u2) {
    printf("glMapGrid1f(%d, %0.2f, %0.2f);\n", un, u1, u2);
}
#endif
#ifndef skip_glMapGrid2d
void glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2) {
    printf("glMapGrid2d(%d, %0.2f, %0.2f, %d, %0.2f, %0.2f);\n", un, u1, u2, vn, v1, v2);
}
#endif
#ifndef skip_glMapGrid2f
void glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2) {
    printf("glMapGrid2f(%d, %0.2f, %0.2f, %d, %0.2f, %0.2f);\n", un, u1, u2, vn, v1, v2);
}
#endif
#ifndef skip_glMaterialf
void glMaterialf(GLenum face, GLenum pname, GLfloat param) {
    printf("glMaterialf(%u, %u, %0.2f);\n", face, pname, param);
}
#endif
#ifndef skip_glMaterialfv
void glMaterialfv(GLenum face, GLenum pname, const GLfloat * params) {
    printf("glMaterialfv(%u, %u, %p);\n", face, pname, params);
}
#endif
#ifndef skip_glMateriali
void glMateriali(GLenum face, GLenum pname, GLint param) {
    printf("glMateriali(%u, %u, %d);\n", face, pname, param);
}
#endif
#ifndef skip_glMaterialiv
void glMaterialiv(GLenum face, GLenum pname, const GLint * params) {
    printf("glMaterialiv(%u, %u, %p);\n", face, pname, params);
}
#endif
#ifndef skip_glMatrixMode
void glMatrixMode(GLenum mode) {
    printf("glMatrixMode(%u);\n", mode);
}
#endif
#ifndef skip_glMinmax
void glMinmax(GLenum target, GLenum internalformat, GLboolean sink) {
    printf("glMinmax(%u, %u, %d);\n", target, internalformat, sink);
}
#endif
#ifndef skip_glMultMatrixd
void glMultMatrixd(const GLdouble * m) {
    printf("glMultMatrixd(%p);\n", m);
}
#endif
#ifndef skip_glMultMatrixf
void glMultMatrixf(const GLfloat * m) {
    printf("glMultMatrixf(%p);\n", m);
}
#endif
#ifndef skip_glMultTransposeMatrixd
void glMultTransposeMatrixd(const GLdouble * m) {
    printf("glMultTransposeMatrixd(%p);\n", m);
}
#endif
#ifndef skip_glMultTransposeMatrixf
void glMultTransposeMatrixf(const GLfloat * m) {
    printf("glMultTransposeMatrixf(%p);\n", m);
}
#endif
#ifndef skip_glMultiDrawArrays
void glMultiDrawArrays(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount) {
    printf("glMultiDrawArrays(%u, %p, %p, %d);\n", mode, first, count, drawcount);
}
#endif
#ifndef skip_glMultiDrawElements
void glMultiDrawElements(GLenum mode, const GLsizei * count, GLenum type, GLvoid*const * indices, GLsizei drawcount) {
    printf("glMultiDrawElements(%u, %p, %u, %p, %d);\n", mode, count, type, indices, drawcount);
}
#endif
#ifndef skip_glMultiTexCoord1d
void glMultiTexCoord1d(GLenum target, GLdouble s) {
    printf("glMultiTexCoord1d(%u, %0.2f);\n", target, s);
}
#endif
#ifndef skip_glMultiTexCoord1dv
void glMultiTexCoord1dv(GLenum target, const GLdouble * v) {
    printf("glMultiTexCoord1dv(%u, %p);\n", target, v);
}
#endif
#ifndef skip_glMultiTexCoord1f
void glMultiTexCoord1f(GLenum target, GLfloat s) {
    printf("glMultiTexCoord1f(%u, %0.2f);\n", target, s);
}
#endif
#ifndef skip_glMultiTexCoord1fv
void glMultiTexCoord1fv(GLenum target, const GLfloat * v) {
    printf("glMultiTexCoord1fv(%u, %p);\n", target, v);
}
#endif
#ifndef skip_glMultiTexCoord1i
void glMultiTexCoord1i(GLenum target, GLint s) {
    printf("glMultiTexCoord1i(%u, %d);\n", target, s);
}
#endif
#ifndef skip_glMultiTexCoord1iv
void glMultiTexCoord1iv(GLenum target, const GLint * v) {
    printf("glMultiTexCoord1iv(%u, %p);\n", target, v);
}
#endif
#ifndef skip_glMultiTexCoord1s
void glMultiTexCoord1s(GLenum target, GLshort s) {
    printf("glMultiTexCoord1s(%u, %d);\n", target, s);
}
#endif
#ifndef skip_glMultiTexCoord1sv
void glMultiTexCoord1sv(GLenum target, const GLshort * v) {
    printf("glMultiTexCoord1sv(%u, %p);\n", target, v);
}
#endif
#ifndef skip_glMultiTexCoord2d
void glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t) {
    printf("glMultiTexCoord2d(%u, %0.2f, %0.2f);\n", target, s, t);
}
#endif
#ifndef skip_glMultiTexCoord2dv
void glMultiTexCoord2dv(GLenum target, const GLdouble * v) {
    printf("glMultiTexCoord2dv(%u, %p);\n", target, v);
}
#endif
#ifndef skip_glMultiTexCoord2f
void glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) {
    printf("glMultiTexCoord2f(%u, %0.2f, %0.2f);\n", target, s, t);
}
#endif
#ifndef skip_glMultiTexCoord2fv
void glMultiTexCoord2fv(GLenum target, const GLfloat * v) {
    printf("glMultiTexCoord2fv(%u, %p);\n", target, v);
}
#endif
#ifndef skip_glMultiTexCoord2i
void glMultiTexCoord2i(GLenum target, GLint s, GLint t) {
    printf("glMultiTexCoord2i(%u, %d, %d);\n", target, s, t);
}
#endif
#ifndef skip_glMultiTexCoord2iv
void glMultiTexCoord2iv(GLenum target, const GLint * v) {
    printf("glMultiTexCoord2iv(%u, %p);\n", target, v);
}
#endif
#ifndef skip_glMultiTexCoord2s
void glMultiTexCoord2s(GLenum target, GLshort s, GLshort t) {
    printf("glMultiTexCoord2s(%u, %d, %d);\n", target, s, t);
}
#endif
#ifndef skip_glMultiTexCoord2sv
void glMultiTexCoord2sv(GLenum target, const GLshort * v) {
    printf("glMultiTexCoord2sv(%u, %p);\n", target, v);
}
#endif
#ifndef skip_glMultiTexCoord3d
void glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r) {
    printf("glMultiTexCoord3d(%u, %0.2f, %0.2f, %0.2f);\n", target, s, t, r);
}
#endif
#ifndef skip_glMultiTexCoord3dv
void glMultiTexCoord3dv(GLenum target, const GLdouble * v) {
    printf("glMultiTexCoord3dv(%u, %p);\n", target, v);
}
#endif
#ifndef skip_glMultiTexCoord3f
void glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r) {
    printf("glMultiTexCoord3f(%u, %0.2f, %0.2f, %0.2f);\n", target, s, t, r);
}
#endif
#ifndef skip_glMultiTexCoord3fv
void glMultiTexCoord3fv(GLenum target, const GLfloat * v) {
    printf("glMultiTexCoord3fv(%u, %p);\n", target, v);
}
#endif
#ifndef skip_glMultiTexCoord3i
void glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r) {
    printf("glMultiTexCoord3i(%u, %d, %d, %d);\n", target, s, t, r);
}
#endif
#ifndef skip_glMultiTexCoord3iv
void glMultiTexCoord3iv(GLenum target, const GLint * v) {
    printf("glMultiTexCoord3iv(%u, %p);\n", target, v);
}
#endif
#ifndef skip_glMultiTexCoord3s
void glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r) {
    printf("glMultiTexCoord3s(%u, %d, %d, %d);\n", target, s, t, r);
}
#endif
#ifndef skip_glMultiTexCoord3sv
void glMultiTexCoord3sv(GLenum target, const GLshort * v) {
    printf("glMultiTexCoord3sv(%u, %p);\n", target, v);
}
#endif
#ifndef skip_glMultiTexCoord4d
void glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
    printf("glMultiTexCoord4d(%u, %0.2f, %0.2f, %0.2f, %0.2f);\n", target, s, t, r, q);
}
#endif
#ifndef skip_glMultiTexCoord4dv
void glMultiTexCoord4dv(GLenum target, const GLdouble * v) {
    printf("glMultiTexCoord4dv(%u, %p);\n", target, v);
}
#endif
#ifndef skip_glMultiTexCoord4f
void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    printf("glMultiTexCoord4f(%u, %0.2f, %0.2f, %0.2f, %0.2f);\n", target, s, t, r, q);
}
#endif
#ifndef skip_glMultiTexCoord4fv
void glMultiTexCoord4fv(GLenum target, const GLfloat * v) {
    printf("glMultiTexCoord4fv(%u, %p);\n", target, v);
}
#endif
#ifndef skip_glMultiTexCoord4i
void glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q) {
    printf("glMultiTexCoord4i(%u, %d, %d, %d, %d);\n", target, s, t, r, q);
}
#endif
#ifndef skip_glMultiTexCoord4iv
void glMultiTexCoord4iv(GLenum target, const GLint * v) {
    printf("glMultiTexCoord4iv(%u, %p);\n", target, v);
}
#endif
#ifndef skip_glMultiTexCoord4s
void glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) {
    printf("glMultiTexCoord4s(%u, %d, %d, %d, %d);\n", target, s, t, r, q);
}
#endif
#ifndef skip_glMultiTexCoord4sv
void glMultiTexCoord4sv(GLenum target, const GLshort * v) {
    printf("glMultiTexCoord4sv(%u, %p);\n", target, v);
}
#endif
#ifndef skip_glNewList
void glNewList(GLuint list, GLenum mode) {
    printf("glNewList(%u, %u);\n", list, mode);
}
#endif
#ifndef skip_glNormal3b
void glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz) {
    printf("glNormal3b(%c, %c, %c);\n", nx, ny, nz);
}
#endif
#ifndef skip_glNormal3bv
void glNormal3bv(const GLbyte * v) {
    printf("glNormal3bv(%p);\n", v);
}
#endif
#ifndef skip_glNormal3d
void glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz) {
    printf("glNormal3d(%0.2f, %0.2f, %0.2f);\n", nx, ny, nz);
}
#endif
#ifndef skip_glNormal3dv
void glNormal3dv(const GLdouble * v) {
    printf("glNormal3dv(%p);\n", v);
}
#endif
#ifndef skip_glNormal3f
void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {
    printf("glNormal3f(%0.2f, %0.2f, %0.2f);\n", nx, ny, nz);
}
#endif
#ifndef skip_glNormal3fv
void glNormal3fv(const GLfloat * v) {
    printf("glNormal3fv(%p);\n", v);
}
#endif
#ifndef skip_glNormal3i
void glNormal3i(GLint nx, GLint ny, GLint nz) {
    printf("glNormal3i(%d, %d, %d);\n", nx, ny, nz);
}
#endif
#ifndef skip_glNormal3iv
void glNormal3iv(const GLint * v) {
    printf("glNormal3iv(%p);\n", v);
}
#endif
#ifndef skip_glNormal3s
void glNormal3s(GLshort nx, GLshort ny, GLshort nz) {
    printf("glNormal3s(%d, %d, %d);\n", nx, ny, nz);
}
#endif
#ifndef skip_glNormal3sv
void glNormal3sv(const GLshort * v) {
    printf("glNormal3sv(%p);\n", v);
}
#endif
#ifndef skip_glNormalPointer
void glNormalPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    printf("glNormalPointer(%u, %d, %p);\n", type, stride, pointer);
}
#endif
#ifndef skip_glOrtho
void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
    printf("glOrtho(%0.2f, %0.2f, %0.2f, %0.2f, %0.2f, %0.2f);\n", left, right, bottom, top, zNear, zFar);
}
#endif
#ifndef skip_glPassThrough
void glPassThrough(GLfloat token) {
    printf("glPassThrough(%0.2f);\n", token);
}
#endif
#ifndef skip_glPixelMapfv
void glPixelMapfv(GLenum map, GLsizei mapsize, const GLfloat * values) {
    printf("glPixelMapfv(%u, %d, %p);\n", map, mapsize, values);
}
#endif
#ifndef skip_glPixelMapuiv
void glPixelMapuiv(GLenum map, GLsizei mapsize, const GLuint * values) {
    printf("glPixelMapuiv(%u, %d, %p);\n", map, mapsize, values);
}
#endif
#ifndef skip_glPixelMapusv
void glPixelMapusv(GLenum map, GLsizei mapsize, const GLushort * values) {
    printf("glPixelMapusv(%u, %d, %p);\n", map, mapsize, values);
}
#endif
#ifndef skip_glPixelStoref
void glPixelStoref(GLenum pname, GLfloat param) {
    printf("glPixelStoref(%u, %0.2f);\n", pname, param);
}
#endif
#ifndef skip_glPixelStorei
void glPixelStorei(GLenum pname, GLint param) {
    printf("glPixelStorei(%u, %d);\n", pname, param);
}
#endif
#ifndef skip_glPixelTransferf
void glPixelTransferf(GLenum pname, GLfloat param) {
    printf("glPixelTransferf(%u, %0.2f);\n", pname, param);
}
#endif
#ifndef skip_glPixelTransferi
void glPixelTransferi(GLenum pname, GLint param) {
    printf("glPixelTransferi(%u, %d);\n", pname, param);
}
#endif
#ifndef skip_glPixelZoom
void glPixelZoom(GLfloat xfactor, GLfloat yfactor) {
    printf("glPixelZoom(%0.2f, %0.2f);\n", xfactor, yfactor);
}
#endif
#ifndef skip_glPointParameterf
void glPointParameterf(GLenum pname, GLfloat param) {
    printf("glPointParameterf(%u, %0.2f);\n", pname, param);
}
#endif
#ifndef skip_glPointParameterfv
void glPointParameterfv(GLenum pname, const GLfloat * params) {
    printf("glPointParameterfv(%u, %p);\n", pname, params);
}
#endif
#ifndef skip_glPointParameteri
void glPointParameteri(GLenum pname, GLint param) {
    printf("glPointParameteri(%u, %d);\n", pname, param);
}
#endif
#ifndef skip_glPointParameteriv
void glPointParameteriv(GLenum pname, const GLint * params) {
    printf("glPointParameteriv(%u, %p);\n", pname, params);
}
#endif
#ifndef skip_glPointSize
void glPointSize(GLfloat size) {
    printf("glPointSize(%0.2f);\n", size);
}
#endif
#ifndef skip_glPolygonMode
void glPolygonMode(GLenum face, GLenum mode) {
    printf("glPolygonMode(%u, %u);\n", face, mode);
}
#endif
#ifndef skip_glPolygonOffset
void glPolygonOffset(GLfloat factor, GLfloat units) {
    printf("glPolygonOffset(%0.2f, %0.2f);\n", factor, units);
}
#endif
#ifndef skip_glPolygonStipple
void glPolygonStipple(const GLubyte * mask) {
    printf("glPolygonStipple(%p);\n", mask);
}
#endif
#ifndef skip_glPopAttrib
void glPopAttrib() {
    printf("glPopAttrib();\n");
}
#endif
#ifndef skip_glPopClientAttrib
void glPopClientAttrib() {
    printf("glPopClientAttrib();\n");
}
#endif
#ifndef skip_glPopMatrix
void glPopMatrix() {
    printf("glPopMatrix();\n");
}
#endif
#ifndef skip_glPopName
void glPopName() {
    printf("glPopName();\n");
}
#endif
#ifndef skip_glPrioritizeTextures
void glPrioritizeTextures(GLsizei n, const GLuint * textures, const GLfloat * priorities) {
    printf("glPrioritizeTextures(%d, %p, %p);\n", n, textures, priorities);
}
#endif
#ifndef skip_glPushAttrib
void glPushAttrib(GLbitfield mask) {
    printf("glPushAttrib(%d);\n", mask);
}
#endif
#ifndef skip_glPushClientAttrib
void glPushClientAttrib(GLbitfield mask) {
    printf("glPushClientAttrib(%d);\n", mask);
}
#endif
#ifndef skip_glPushMatrix
void glPushMatrix() {
    printf("glPushMatrix();\n");
}
#endif
#ifndef skip_glPushName
void glPushName(GLuint name) {
    printf("glPushName(%u);\n", name);
}
#endif
#ifndef skip_glRasterPos2d
void glRasterPos2d(GLdouble x, GLdouble y) {
    printf("glRasterPos2d(%0.2f, %0.2f);\n", x, y);
}
#endif
#ifndef skip_glRasterPos2dv
void glRasterPos2dv(const GLdouble * v) {
    printf("glRasterPos2dv(%p);\n", v);
}
#endif
#ifndef skip_glRasterPos2f
void glRasterPos2f(GLfloat x, GLfloat y) {
    printf("glRasterPos2f(%0.2f, %0.2f);\n", x, y);
}
#endif
#ifndef skip_glRasterPos2fv
void glRasterPos2fv(const GLfloat * v) {
    printf("glRasterPos2fv(%p);\n", v);
}
#endif
#ifndef skip_glRasterPos2i
void glRasterPos2i(GLint x, GLint y) {
    printf("glRasterPos2i(%d, %d);\n", x, y);
}
#endif
#ifndef skip_glRasterPos2iv
void glRasterPos2iv(const GLint * v) {
    printf("glRasterPos2iv(%p);\n", v);
}
#endif
#ifndef skip_glRasterPos2s
void glRasterPos2s(GLshort x, GLshort y) {
    printf("glRasterPos2s(%d, %d);\n", x, y);
}
#endif
#ifndef skip_glRasterPos2sv
void glRasterPos2sv(const GLshort * v) {
    printf("glRasterPos2sv(%p);\n", v);
}
#endif
#ifndef skip_glRasterPos3d
void glRasterPos3d(GLdouble x, GLdouble y, GLdouble z) {
    printf("glRasterPos3d(%0.2f, %0.2f, %0.2f);\n", x, y, z);
}
#endif
#ifndef skip_glRasterPos3dv
void glRasterPos3dv(const GLdouble * v) {
    printf("glRasterPos3dv(%p);\n", v);
}
#endif
#ifndef skip_glRasterPos3f
void glRasterPos3f(GLfloat x, GLfloat y, GLfloat z) {
    printf("glRasterPos3f(%0.2f, %0.2f, %0.2f);\n", x, y, z);
}
#endif
#ifndef skip_glRasterPos3fv
void glRasterPos3fv(const GLfloat * v) {
    printf("glRasterPos3fv(%p);\n", v);
}
#endif
#ifndef skip_glRasterPos3i
void glRasterPos3i(GLint x, GLint y, GLint z) {
    printf("glRasterPos3i(%d, %d, %d);\n", x, y, z);
}
#endif
#ifndef skip_glRasterPos3iv
void glRasterPos3iv(const GLint * v) {
    printf("glRasterPos3iv(%p);\n", v);
}
#endif
#ifndef skip_glRasterPos3s
void glRasterPos3s(GLshort x, GLshort y, GLshort z) {
    printf("glRasterPos3s(%d, %d, %d);\n", x, y, z);
}
#endif
#ifndef skip_glRasterPos3sv
void glRasterPos3sv(const GLshort * v) {
    printf("glRasterPos3sv(%p);\n", v);
}
#endif
#ifndef skip_glRasterPos4d
void glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    printf("glRasterPos4d(%0.2f, %0.2f, %0.2f, %0.2f);\n", x, y, z, w);
}
#endif
#ifndef skip_glRasterPos4dv
void glRasterPos4dv(const GLdouble * v) {
    printf("glRasterPos4dv(%p);\n", v);
}
#endif
#ifndef skip_glRasterPos4f
void glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    printf("glRasterPos4f(%0.2f, %0.2f, %0.2f, %0.2f);\n", x, y, z, w);
}
#endif
#ifndef skip_glRasterPos4fv
void glRasterPos4fv(const GLfloat * v) {
    printf("glRasterPos4fv(%p);\n", v);
}
#endif
#ifndef skip_glRasterPos4i
void glRasterPos4i(GLint x, GLint y, GLint z, GLint w) {
    printf("glRasterPos4i(%d, %d, %d, %d);\n", x, y, z, w);
}
#endif
#ifndef skip_glRasterPos4iv
void glRasterPos4iv(const GLint * v) {
    printf("glRasterPos4iv(%p);\n", v);
}
#endif
#ifndef skip_glRasterPos4s
void glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w) {
    printf("glRasterPos4s(%d, %d, %d, %d);\n", x, y, z, w);
}
#endif
#ifndef skip_glRasterPos4sv
void glRasterPos4sv(const GLshort * v) {
    printf("glRasterPos4sv(%p);\n", v);
}
#endif
#ifndef skip_glReadBuffer
void glReadBuffer(GLenum mode) {
    printf("glReadBuffer(%u);\n", mode);
}
#endif
#ifndef skip_glReadPixels
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels) {
    printf("glReadPixels(%d, %d, %d, %d, %u, %u, %p);\n", x, y, width, height, format, type, pixels);
}
#endif
#ifndef skip_glRectd
void glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) {
    printf("glRectd(%0.2f, %0.2f, %0.2f, %0.2f);\n", x1, y1, x2, y2);
}
#endif
#ifndef skip_glRectdv
void glRectdv(const GLdouble * v1, const GLdouble * v2) {
    printf("glRectdv(%p, %p);\n", v1, v2);
}
#endif
#ifndef skip_glRectf
void glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
    printf("glRectf(%0.2f, %0.2f, %0.2f, %0.2f);\n", x1, y1, x2, y2);
}
#endif
#ifndef skip_glRectfv
void glRectfv(const GLfloat * v1, const GLfloat * v2) {
    printf("glRectfv(%p, %p);\n", v1, v2);
}
#endif
#ifndef skip_glRecti
void glRecti(GLint x1, GLint y1, GLint x2, GLint y2) {
    printf("glRecti(%d, %d, %d, %d);\n", x1, y1, x2, y2);
}
#endif
#ifndef skip_glRectiv
void glRectiv(const GLint * v1, const GLint * v2) {
    printf("glRectiv(%p, %p);\n", v1, v2);
}
#endif
#ifndef skip_glRects
void glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2) {
    printf("glRects(%d, %d, %d, %d);\n", x1, y1, x2, y2);
}
#endif
#ifndef skip_glRectsv
void glRectsv(const GLshort * v1, const GLshort * v2) {
    printf("glRectsv(%p, %p);\n", v1, v2);
}
#endif
#ifndef skip_glRenderMode
GLint glRenderMode(GLenum mode) {
    printf("glRenderMode(%u);\n", mode);
    return 0;
}
#endif
#ifndef skip_glResetHistogram
void glResetHistogram(GLenum target) {
    printf("glResetHistogram(%u);\n", target);
}
#endif
#ifndef skip_glResetMinmax
void glResetMinmax(GLenum target) {
    printf("glResetMinmax(%u);\n", target);
}
#endif
#ifndef skip_glRotated
void glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
    printf("glRotated(%0.2f, %0.2f, %0.2f, %0.2f);\n", angle, x, y, z);
}
#endif
#ifndef skip_glRotatef
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
    printf("glRotatef(%0.2f, %0.2f, %0.2f, %0.2f);\n", angle, x, y, z);
}
#endif
#ifndef skip_glSampleCoverage
void glSampleCoverage(GLfloat value, GLboolean invert) {
    printf("glSampleCoverage(%0.2f, %d);\n", value, invert);
}
#endif
#ifndef skip_glScaled
void glScaled(GLdouble x, GLdouble y, GLdouble z) {
    printf("glScaled(%0.2f, %0.2f, %0.2f);\n", x, y, z);
}
#endif
#ifndef skip_glScalef
void glScalef(GLfloat x, GLfloat y, GLfloat z) {
    printf("glScalef(%0.2f, %0.2f, %0.2f);\n", x, y, z);
}
#endif
#ifndef skip_glScissor
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {
    printf("glScissor(%d, %d, %d, %d);\n", x, y, width, height);
}
#endif
#ifndef skip_glSecondaryColor3b
void glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue) {
    printf("glSecondaryColor3b(%c, %c, %c);\n", red, green, blue);
}
#endif
#ifndef skip_glSecondaryColor3bv
void glSecondaryColor3bv(const GLbyte * v) {
    printf("glSecondaryColor3bv(%p);\n", v);
}
#endif
#ifndef skip_glSecondaryColor3d
void glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue) {
    printf("glSecondaryColor3d(%0.2f, %0.2f, %0.2f);\n", red, green, blue);
}
#endif
#ifndef skip_glSecondaryColor3dv
void glSecondaryColor3dv(const GLdouble * v) {
    printf("glSecondaryColor3dv(%p);\n", v);
}
#endif
#ifndef skip_glSecondaryColor3f
void glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue) {
    printf("glSecondaryColor3f(%0.2f, %0.2f, %0.2f);\n", red, green, blue);
}
#endif
#ifndef skip_glSecondaryColor3fv
void glSecondaryColor3fv(const GLfloat * v) {
    printf("glSecondaryColor3fv(%p);\n", v);
}
#endif
#ifndef skip_glSecondaryColor3i
void glSecondaryColor3i(GLint red, GLint green, GLint blue) {
    printf("glSecondaryColor3i(%d, %d, %d);\n", red, green, blue);
}
#endif
#ifndef skip_glSecondaryColor3iv
void glSecondaryColor3iv(const GLint * v) {
    printf("glSecondaryColor3iv(%p);\n", v);
}
#endif
#ifndef skip_glSecondaryColor3s
void glSecondaryColor3s(GLshort red, GLshort green, GLshort blue) {
    printf("glSecondaryColor3s(%d, %d, %d);\n", red, green, blue);
}
#endif
#ifndef skip_glSecondaryColor3sv
void glSecondaryColor3sv(const GLshort * v) {
    printf("glSecondaryColor3sv(%p);\n", v);
}
#endif
#ifndef skip_glSecondaryColor3ub
void glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue) {
    printf("glSecondaryColor3ub(%c, %c, %c);\n", red, green, blue);
}
#endif
#ifndef skip_glSecondaryColor3ubv
void glSecondaryColor3ubv(const GLubyte * v) {
    printf("glSecondaryColor3ubv(%p);\n", v);
}
#endif
#ifndef skip_glSecondaryColor3ui
void glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue) {
    printf("glSecondaryColor3ui(%u, %u, %u);\n", red, green, blue);
}
#endif
#ifndef skip_glSecondaryColor3uiv
void glSecondaryColor3uiv(const GLuint * v) {
    printf("glSecondaryColor3uiv(%p);\n", v);
}
#endif
#ifndef skip_glSecondaryColor3us
void glSecondaryColor3us(GLushort red, GLushort green, GLushort blue) {
    printf("glSecondaryColor3us(%u, %u, %u);\n", red, green, blue);
}
#endif
#ifndef skip_glSecondaryColor3usv
void glSecondaryColor3usv(const GLushort * v) {
    printf("glSecondaryColor3usv(%p);\n", v);
}
#endif
#ifndef skip_glSecondaryColorPointer
void glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    printf("glSecondaryColorPointer(%d, %u, %d, %p);\n", size, type, stride, pointer);
}
#endif
#ifndef skip_glSelectBuffer
void glSelectBuffer(GLsizei size, GLuint * buffer) {
    printf("glSelectBuffer(%d, %p);\n", size, buffer);
}
#endif
#ifndef skip_glSeparableFilter2D
void glSeparableFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * row, const GLvoid * column) {
    printf("glSeparableFilter2D(%u, %u, %d, %d, %u, %u, %p, %p);\n", target, internalformat, width, height, format, type, row, column);
}
#endif
#ifndef skip_glShadeModel
void glShadeModel(GLenum mode) {
    printf("glShadeModel(%u);\n", mode);
}
#endif
#ifndef skip_glStencilFunc
void glStencilFunc(GLenum func, GLint ref, GLuint mask) {
    printf("glStencilFunc(%u, %d, %u);\n", func, ref, mask);
}
#endif
#ifndef skip_glStencilMask
void glStencilMask(GLuint mask) {
    printf("glStencilMask(%u);\n", mask);
}
#endif
#ifndef skip_glStencilOp
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
    printf("glStencilOp(%u, %u, %u);\n", fail, zfail, zpass);
}
#endif
#ifndef skip_glTexCoord1d
void glTexCoord1d(GLdouble s) {
    printf("glTexCoord1d(%0.2f);\n", s);
}
#endif
#ifndef skip_glTexCoord1dv
void glTexCoord1dv(const GLdouble * v) {
    printf("glTexCoord1dv(%p);\n", v);
}
#endif
#ifndef skip_glTexCoord1f
void glTexCoord1f(GLfloat s) {
    printf("glTexCoord1f(%0.2f);\n", s);
}
#endif
#ifndef skip_glTexCoord1fv
void glTexCoord1fv(const GLfloat * v) {
    printf("glTexCoord1fv(%p);\n", v);
}
#endif
#ifndef skip_glTexCoord1i
void glTexCoord1i(GLint s) {
    printf("glTexCoord1i(%d);\n", s);
}
#endif
#ifndef skip_glTexCoord1iv
void glTexCoord1iv(const GLint * v) {
    printf("glTexCoord1iv(%p);\n", v);
}
#endif
#ifndef skip_glTexCoord1s
void glTexCoord1s(GLshort s) {
    printf("glTexCoord1s(%d);\n", s);
}
#endif
#ifndef skip_glTexCoord1sv
void glTexCoord1sv(const GLshort * v) {
    printf("glTexCoord1sv(%p);\n", v);
}
#endif
#ifndef skip_glTexCoord2d
void glTexCoord2d(GLdouble s, GLdouble t) {
    printf("glTexCoord2d(%0.2f, %0.2f);\n", s, t);
}
#endif
#ifndef skip_glTexCoord2dv
void glTexCoord2dv(const GLdouble * v) {
    printf("glTexCoord2dv(%p);\n", v);
}
#endif
#ifndef skip_glTexCoord2f
void glTexCoord2f(GLfloat s, GLfloat t) {
    printf("glTexCoord2f(%0.2f, %0.2f);\n", s, t);
}
#endif
#ifndef skip_glTexCoord2fv
void glTexCoord2fv(const GLfloat * v) {
    printf("glTexCoord2fv(%p);\n", v);
}
#endif
#ifndef skip_glTexCoord2i
void glTexCoord2i(GLint s, GLint t) {
    printf("glTexCoord2i(%d, %d);\n", s, t);
}
#endif
#ifndef skip_glTexCoord2iv
void glTexCoord2iv(const GLint * v) {
    printf("glTexCoord2iv(%p);\n", v);
}
#endif
#ifndef skip_glTexCoord2s
void glTexCoord2s(GLshort s, GLshort t) {
    printf("glTexCoord2s(%d, %d);\n", s, t);
}
#endif
#ifndef skip_glTexCoord2sv
void glTexCoord2sv(const GLshort * v) {
    printf("glTexCoord2sv(%p);\n", v);
}
#endif
#ifndef skip_glTexCoord3d
void glTexCoord3d(GLdouble s, GLdouble t, GLdouble r) {
    printf("glTexCoord3d(%0.2f, %0.2f, %0.2f);\n", s, t, r);
}
#endif
#ifndef skip_glTexCoord3dv
void glTexCoord3dv(const GLdouble * v) {
    printf("glTexCoord3dv(%p);\n", v);
}
#endif
#ifndef skip_glTexCoord3f
void glTexCoord3f(GLfloat s, GLfloat t, GLfloat r) {
    printf("glTexCoord3f(%0.2f, %0.2f, %0.2f);\n", s, t, r);
}
#endif
#ifndef skip_glTexCoord3fv
void glTexCoord3fv(const GLfloat * v) {
    printf("glTexCoord3fv(%p);\n", v);
}
#endif
#ifndef skip_glTexCoord3i
void glTexCoord3i(GLint s, GLint t, GLint r) {
    printf("glTexCoord3i(%d, %d, %d);\n", s, t, r);
}
#endif
#ifndef skip_glTexCoord3iv
void glTexCoord3iv(const GLint * v) {
    printf("glTexCoord3iv(%p);\n", v);
}
#endif
#ifndef skip_glTexCoord3s
void glTexCoord3s(GLshort s, GLshort t, GLshort r) {
    printf("glTexCoord3s(%d, %d, %d);\n", s, t, r);
}
#endif
#ifndef skip_glTexCoord3sv
void glTexCoord3sv(const GLshort * v) {
    printf("glTexCoord3sv(%p);\n", v);
}
#endif
#ifndef skip_glTexCoord4d
void glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
    printf("glTexCoord4d(%0.2f, %0.2f, %0.2f, %0.2f);\n", s, t, r, q);
}
#endif
#ifndef skip_glTexCoord4dv
void glTexCoord4dv(const GLdouble * v) {
    printf("glTexCoord4dv(%p);\n", v);
}
#endif
#ifndef skip_glTexCoord4f
void glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    printf("glTexCoord4f(%0.2f, %0.2f, %0.2f, %0.2f);\n", s, t, r, q);
}
#endif
#ifndef skip_glTexCoord4fv
void glTexCoord4fv(const GLfloat * v) {
    printf("glTexCoord4fv(%p);\n", v);
}
#endif
#ifndef skip_glTexCoord4i
void glTexCoord4i(GLint s, GLint t, GLint r, GLint q) {
    printf("glTexCoord4i(%d, %d, %d, %d);\n", s, t, r, q);
}
#endif
#ifndef skip_glTexCoord4iv
void glTexCoord4iv(const GLint * v) {
    printf("glTexCoord4iv(%p);\n", v);
}
#endif
#ifndef skip_glTexCoord4s
void glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q) {
    printf("glTexCoord4s(%d, %d, %d, %d);\n", s, t, r, q);
}
#endif
#ifndef skip_glTexCoord4sv
void glTexCoord4sv(const GLshort * v) {
    printf("glTexCoord4sv(%p);\n", v);
}
#endif
#ifndef skip_glTexCoordPointer
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    printf("glTexCoordPointer(%d, %u, %d, %p);\n", size, type, stride, pointer);
}
#endif
#ifndef skip_glTexEnvf
void glTexEnvf(GLenum target, GLenum pname, GLfloat param) {
    printf("glTexEnvf(%u, %u, %0.2f);\n", target, pname, param);
}
#endif
#ifndef skip_glTexEnvfv
void glTexEnvfv(GLenum target, GLenum pname, const GLfloat * params) {
    printf("glTexEnvfv(%u, %u, %p);\n", target, pname, params);
}
#endif
#ifndef skip_glTexEnvi
void glTexEnvi(GLenum target, GLenum pname, GLint param) {
    printf("glTexEnvi(%u, %u, %d);\n", target, pname, param);
}
#endif
#ifndef skip_glTexEnviv
void glTexEnviv(GLenum target, GLenum pname, const GLint * params) {
    printf("glTexEnviv(%u, %u, %p);\n", target, pname, params);
}
#endif
#ifndef skip_glTexGend
void glTexGend(GLenum coord, GLenum pname, GLdouble param) {
    printf("glTexGend(%u, %u, %0.2f);\n", coord, pname, param);
}
#endif
#ifndef skip_glTexGendv
void glTexGendv(GLenum coord, GLenum pname, const GLdouble * params) {
    printf("glTexGendv(%u, %u, %p);\n", coord, pname, params);
}
#endif
#ifndef skip_glTexGenf
void glTexGenf(GLenum coord, GLenum pname, GLfloat param) {
    printf("glTexGenf(%u, %u, %0.2f);\n", coord, pname, param);
}
#endif
#ifndef skip_glTexGenfv
void glTexGenfv(GLenum coord, GLenum pname, const GLfloat * params) {
    printf("glTexGenfv(%u, %u, %p);\n", coord, pname, params);
}
#endif
#ifndef skip_glTexGeni
void glTexGeni(GLenum coord, GLenum pname, GLint param) {
    printf("glTexGeni(%u, %u, %d);\n", coord, pname, param);
}
#endif
#ifndef skip_glTexGeniv
void glTexGeniv(GLenum coord, GLenum pname, const GLint * params) {
    printf("glTexGeniv(%u, %u, %p);\n", coord, pname, params);
}
#endif
#ifndef skip_glTexImage1D
void glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid * pixels) {
    printf("glTexImage1D(%u, %d, %d, %d, %d, %u, %u, %p);\n", target, level, internalformat, width, border, format, type, pixels);
}
#endif
#ifndef skip_glTexImage2D
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels) {
    printf("glTexImage2D(%u, %d, %d, %d, %d, %d, %u, %u, %p);\n", target, level, internalformat, width, height, border, format, type, pixels);
}
#endif
#ifndef skip_glTexImage3D
void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid * pixels) {
    printf("glTexImage3D(%u, %d, %d, %d, %d, %d, %d, %u, %u, %p);\n", target, level, internalformat, width, height, depth, border, format, type, pixels);
}
#endif
#ifndef skip_glTexParameterf
void glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
    printf("glTexParameterf(%u, %u, %0.2f);\n", target, pname, param);
}
#endif
#ifndef skip_glTexParameterfv
void glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    printf("glTexParameterfv(%u, %u, %p);\n", target, pname, params);
}
#endif
#ifndef skip_glTexParameteri
void glTexParameteri(GLenum target, GLenum pname, GLint param) {
    printf("glTexParameteri(%u, %u, %d);\n", target, pname, param);
}
#endif
#ifndef skip_glTexParameteriv
void glTexParameteriv(GLenum target, GLenum pname, const GLint * params) {
    printf("glTexParameteriv(%u, %u, %p);\n", target, pname, params);
}
#endif
#ifndef skip_glTexSubImage1D
void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid * pixels) {
    printf("glTexSubImage1D(%u, %d, %d, %d, %u, %u, %p);\n", target, level, xoffset, width, format, type, pixels);
}
#endif
#ifndef skip_glTexSubImage2D
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels) {
    printf("glTexSubImage2D(%u, %d, %d, %d, %d, %d, %u, %u, %p);\n", target, level, xoffset, yoffset, width, height, format, type, pixels);
}
#endif
#ifndef skip_glTexSubImage3D
void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * pixels) {
    printf("glTexSubImage3D(%u, %d, %d, %d, %d, %d, %d, %d, %u, %u, %p);\n", target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}
#endif
#ifndef skip_glTranslated
void glTranslated(GLdouble x, GLdouble y, GLdouble z) {
    printf("glTranslated(%0.2f, %0.2f, %0.2f);\n", x, y, z);
}
#endif
#ifndef skip_glTranslatef
void glTranslatef(GLfloat x, GLfloat y, GLfloat z) {
    printf("glTranslatef(%0.2f, %0.2f, %0.2f);\n", x, y, z);
}
#endif
#ifndef skip_glUnmapBuffer
GLboolean glUnmapBuffer(GLenum target) {
    printf("glUnmapBuffer(%u);\n", target);
    return 0;
}
#endif
#ifndef skip_glVertex2d
void glVertex2d(GLdouble x, GLdouble y) {
    printf("glVertex2d(%0.2f, %0.2f);\n", x, y);
}
#endif
#ifndef skip_glVertex2dv
void glVertex2dv(const GLdouble * v) {
    printf("glVertex2dv(%p);\n", v);
}
#endif
#ifndef skip_glVertex2f
void glVertex2f(GLfloat x, GLfloat y) {
    printf("glVertex2f(%0.2f, %0.2f);\n", x, y);
}
#endif
#ifndef skip_glVertex2fv
void glVertex2fv(const GLfloat * v) {
    printf("glVertex2fv(%p);\n", v);
}
#endif
#ifndef skip_glVertex2i
void glVertex2i(GLint x, GLint y) {
    printf("glVertex2i(%d, %d);\n", x, y);
}
#endif
#ifndef skip_glVertex2iv
void glVertex2iv(const GLint * v) {
    printf("glVertex2iv(%p);\n", v);
}
#endif
#ifndef skip_glVertex2s
void glVertex2s(GLshort x, GLshort y) {
    printf("glVertex2s(%d, %d);\n", x, y);
}
#endif
#ifndef skip_glVertex2sv
void glVertex2sv(const GLshort * v) {
    printf("glVertex2sv(%p);\n", v);
}
#endif
#ifndef skip_glVertex3d
void glVertex3d(GLdouble x, GLdouble y, GLdouble z) {
    printf("glVertex3d(%0.2f, %0.2f, %0.2f);\n", x, y, z);
}
#endif
#ifndef skip_glVertex3dv
void glVertex3dv(const GLdouble * v) {
    printf("glVertex3dv(%p);\n", v);
}
#endif
#ifndef skip_glVertex3f
void glVertex3f(GLfloat x, GLfloat y, GLfloat z) {
    printf("glVertex3f(%0.2f, %0.2f, %0.2f);\n", x, y, z);
}
#endif
#ifndef skip_glVertex3fv
void glVertex3fv(const GLfloat * v) {
    printf("glVertex3fv(%p);\n", v);
}
#endif
#ifndef skip_glVertex3i
void glVertex3i(GLint x, GLint y, GLint z) {
    printf("glVertex3i(%d, %d, %d);\n", x, y, z);
}
#endif
#ifndef skip_glVertex3iv
void glVertex3iv(const GLint * v) {
    printf("glVertex3iv(%p);\n", v);
}
#endif
#ifndef skip_glVertex3s
void glVertex3s(GLshort x, GLshort y, GLshort z) {
    printf("glVertex3s(%d, %d, %d);\n", x, y, z);
}
#endif
#ifndef skip_glVertex3sv
void glVertex3sv(const GLshort * v) {
    printf("glVertex3sv(%p);\n", v);
}
#endif
#ifndef skip_glVertex4d
void glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    printf("glVertex4d(%0.2f, %0.2f, %0.2f, %0.2f);\n", x, y, z, w);
}
#endif
#ifndef skip_glVertex4dv
void glVertex4dv(const GLdouble * v) {
    printf("glVertex4dv(%p);\n", v);
}
#endif
#ifndef skip_glVertex4f
void glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    printf("glVertex4f(%0.2f, %0.2f, %0.2f, %0.2f);\n", x, y, z, w);
}
#endif
#ifndef skip_glVertex4fv
void glVertex4fv(const GLfloat * v) {
    printf("glVertex4fv(%p);\n", v);
}
#endif
#ifndef skip_glVertex4i
void glVertex4i(GLint x, GLint y, GLint z, GLint w) {
    printf("glVertex4i(%d, %d, %d, %d);\n", x, y, z, w);
}
#endif
#ifndef skip_glVertex4iv
void glVertex4iv(const GLint * v) {
    printf("glVertex4iv(%p);\n", v);
}
#endif
#ifndef skip_glVertex4s
void glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w) {
    printf("glVertex4s(%d, %d, %d, %d);\n", x, y, z, w);
}
#endif
#ifndef skip_glVertex4sv
void glVertex4sv(const GLshort * v) {
    printf("glVertex4sv(%p);\n", v);
}
#endif
#ifndef skip_glVertexPointer
void glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    printf("glVertexPointer(%d, %u, %d, %p);\n", size, type, stride, pointer);
}
#endif
#ifndef skip_glViewport
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
    printf("glViewport(%d, %d, %d, %d);\n", x, y, width, height);
}
#endif
#ifndef skip_glWindowPos2d
void glWindowPos2d(GLdouble x, GLdouble y) {
    printf("glWindowPos2d(%0.2f, %0.2f);\n", x, y);
}
#endif
#ifndef skip_glWindowPos2dv
void glWindowPos2dv(const GLdouble * v) {
    printf("glWindowPos2dv(%p);\n", v);
}
#endif
#ifndef skip_glWindowPos2f
void glWindowPos2f(GLfloat x, GLfloat y) {
    printf("glWindowPos2f(%0.2f, %0.2f);\n", x, y);
}
#endif
#ifndef skip_glWindowPos2fv
void glWindowPos2fv(const GLfloat * v) {
    printf("glWindowPos2fv(%p);\n", v);
}
#endif
#ifndef skip_glWindowPos2i
void glWindowPos2i(GLint x, GLint y) {
    printf("glWindowPos2i(%d, %d);\n", x, y);
}
#endif
#ifndef skip_glWindowPos2iv
void glWindowPos2iv(const GLint * v) {
    printf("glWindowPos2iv(%p);\n", v);
}
#endif
#ifndef skip_glWindowPos2s
void glWindowPos2s(GLshort x, GLshort y) {
    printf("glWindowPos2s(%d, %d);\n", x, y);
}
#endif
#ifndef skip_glWindowPos2sv
void glWindowPos2sv(const GLshort * v) {
    printf("glWindowPos2sv(%p);\n", v);
}
#endif
#ifndef skip_glWindowPos3d
void glWindowPos3d(GLdouble x, GLdouble y, GLdouble z) {
    printf("glWindowPos3d(%0.2f, %0.2f, %0.2f);\n", x, y, z);
}
#endif
#ifndef skip_glWindowPos3dv
void glWindowPos3dv(const GLdouble * v) {
    printf("glWindowPos3dv(%p);\n", v);
}
#endif
#ifndef skip_glWindowPos3f
void glWindowPos3f(GLfloat x, GLfloat y, GLfloat z) {
    printf("glWindowPos3f(%0.2f, %0.2f, %0.2f);\n", x, y, z);
}
#endif
#ifndef skip_glWindowPos3fv
void glWindowPos3fv(const GLfloat * v) {
    printf("glWindowPos3fv(%p);\n", v);
}
#endif
#ifndef skip_glWindowPos3i
void glWindowPos3i(GLint x, GLint y, GLint z) {
    printf("glWindowPos3i(%d, %d, %d);\n", x, y, z);
}
#endif
#ifndef skip_glWindowPos3iv
void glWindowPos3iv(const GLint * v) {
    printf("glWindowPos3iv(%p);\n", v);
}
#endif
#ifndef skip_glWindowPos3s
void glWindowPos3s(GLshort x, GLshort y, GLshort z) {
    printf("glWindowPos3s(%d, %d, %d);\n", x, y, z);
}
#endif
#ifndef skip_glWindowPos3sv
void glWindowPos3sv(const GLshort * v) {
    printf("glWindowPos3sv(%p);\n", v);
}
#endif
#ifndef skip_glXBindHyperpipeSGIX
int glXBindHyperpipeSGIX(Display * dpy, int hpId) {
    printf("glXBindHyperpipeSGIX(%p, %p);\n", dpy, hpId);
    return 0;
}
#endif
#ifndef skip_glXBindSwapBarrierSGIX
void glXBindSwapBarrierSGIX(uint32_t window, uint32_t barrier) {
    printf("glXBindSwapBarrierSGIX(%p, %p);\n", window, barrier);
}
#endif
#ifndef skip_glXChangeDrawableAttributes
void glXChangeDrawableAttributes(uint32_t drawable) {
    printf("glXChangeDrawableAttributes(%p);\n", drawable);
}
#endif
#ifndef skip_glXChangeDrawableAttributesSGIX
void glXChangeDrawableAttributesSGIX(uint32_t drawable) {
    printf("glXChangeDrawableAttributesSGIX(%p);\n", drawable);
}
#endif
#ifndef skip_glXChooseFBConfig
GLXFBConfig * glXChooseFBConfig(Display * dpy, int screen, const int * attrib_list, int * nelements) {
    printf("glXChooseFBConfig(%p, %p, %p, %p);\n", dpy, screen, attrib_list, nelements);
    return 0;
}
#endif
#ifndef skip_glXChooseVisual
XVisualInfo * glXChooseVisual(Display * dpy, int screen, int * attribList) {
    printf("glXChooseVisual(%p, %p, %p);\n", dpy, screen, attribList);
    return 0;
}
#endif
#ifndef skip_glXClientInfo
void glXClientInfo() {
    printf("glXClientInfo();\n");
}
#endif
#ifndef skip_glXCopyContext
void glXCopyContext(Display * dpy, GLXContext src, GLXContext dst, unsigned long mask) {
    printf("glXCopyContext(%p, %p, %p, %p);\n", dpy, src, dst, mask);
}
#endif
#ifndef skip_glXCreateContext
GLXContext glXCreateContext(Display * dpy, XVisualInfo * vis, GLXContext shareList, Bool direct) {
    printf("glXCreateContext(%p, %p, %p, %p);\n", dpy, vis, shareList, direct);
    return 0;
}
#endif
#ifndef skip_glXCreateContextWithConfigSGIX
void glXCreateContextWithConfigSGIX(uint32_t gc_id, uint32_t screen, uint32_t config, uint32_t share_list) {
    printf("glXCreateContextWithConfigSGIX(%p, %p, %p, %p);\n", gc_id, screen, config, share_list);
}
#endif
#ifndef skip_glXCreateGLXPbufferSGIX
void glXCreateGLXPbufferSGIX(uint32_t config, uint32_t pbuffer) {
    printf("glXCreateGLXPbufferSGIX(%p, %p);\n", config, pbuffer);
}
#endif
#ifndef skip_glXCreateGLXPixmap
GLXPixmap glXCreateGLXPixmap(Display * dpy, XVisualInfo * visual, Pixmap pixmap) {
    printf("glXCreateGLXPixmap(%p, %p, %p);\n", dpy, visual, pixmap);
    return 0;
}
#endif
#ifndef skip_glXCreateGLXPixmapWithConfigSGIX
void glXCreateGLXPixmapWithConfigSGIX(uint32_t config, uint32_t pixmap, uint32_t glxpixmap) {
    printf("glXCreateGLXPixmapWithConfigSGIX(%p, %p, %p);\n", config, pixmap, glxpixmap);
}
#endif
#ifndef skip_glXCreateGLXVideoSourceSGIX
void glXCreateGLXVideoSourceSGIX(Display * dpy, uint32_t screen, uint32_t server, uint32_t path, uint32_t class, uint32_t node) {
    printf("glXCreateGLXVideoSourceSGIX(%p, %p, %p, %p, %p, %p);\n", dpy, screen, server, path, class, node);
}
#endif
#ifndef skip_glXCreateNewContext
GLXContext glXCreateNewContext(Display * dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct) {
    printf("glXCreateNewContext(%p, %p, %p, %p, %p);\n", dpy, config, render_type, share_list, direct);
    return 0;
}
#endif
#ifndef skip_glXCreatePbuffer
GLXPbuffer glXCreatePbuffer(Display * dpy, GLXFBConfig config, const int * attrib_list) {
    printf("glXCreatePbuffer(%p, %p, %p);\n", dpy, config, attrib_list);
    return 0;
}
#endif
#ifndef skip_glXCreatePixmap
GLXPixmap glXCreatePixmap(Display * dpy, GLXFBConfig config, Pixmap pixmap, const int * attrib_list) {
    printf("glXCreatePixmap(%p, %p, %p, %p);\n", dpy, config, pixmap, attrib_list);
    return 0;
}
#endif
#ifndef skip_glXCreateWindow
GLXWindow glXCreateWindow(Display * dpy, GLXFBConfig config, Window win, const int * attrib_list) {
    printf("glXCreateWindow(%p, %p, %p, %p);\n", dpy, config, win, attrib_list);
    return 0;
}
#endif
#ifndef skip_glXDestroyContext
void glXDestroyContext(Display * dpy, GLXContext ctx) {
    printf("glXDestroyContext(%p, %p);\n", dpy, ctx);
}
#endif
#ifndef skip_glXDestroyGLXPbufferSGIX
void glXDestroyGLXPbufferSGIX(uint32_t pbuffer) {
    printf("glXDestroyGLXPbufferSGIX(%p);\n", pbuffer);
}
#endif
#ifndef skip_glXDestroyGLXPixmap
void glXDestroyGLXPixmap(Display * dpy, GLXPixmap pixmap) {
    printf("glXDestroyGLXPixmap(%p, %p);\n", dpy, pixmap);
}
#endif
#ifndef skip_glXDestroyGLXVideoSourceSGIX
void glXDestroyGLXVideoSourceSGIX(Display * dpy, uint32_t glxvideosource) {
    printf("glXDestroyGLXVideoSourceSGIX(%p, %p);\n", dpy, glxvideosource);
}
#endif
#ifndef skip_glXDestroyHyperpipeConfigSGIX
int glXDestroyHyperpipeConfigSGIX(Display * dpy, int hpId) {
    printf("glXDestroyHyperpipeConfigSGIX(%p, %p);\n", dpy, hpId);
    return 0;
}
#endif
#ifndef skip_glXDestroyPbuffer
void glXDestroyPbuffer(Display * dpy, GLXPbuffer pbuf) {
    printf("glXDestroyPbuffer(%p, %p);\n", dpy, pbuf);
}
#endif
#ifndef skip_glXDestroyPixmap
void glXDestroyPixmap(Display * dpy, GLXPixmap pixmap) {
    printf("glXDestroyPixmap(%p, %p);\n", dpy, pixmap);
}
#endif
#ifndef skip_glXDestroyWindow
void glXDestroyWindow(Display * dpy, GLXWindow win) {
    printf("glXDestroyWindow(%p, %p);\n", dpy, win);
}
#endif
#ifndef skip_glXGetCurrentDisplay
Display * glXGetCurrentDisplay() {
    printf("glXGetCurrentDisplay();\n");
    return 0;
}
#endif
#ifndef skip_glXGetCurrentReadDrawable
GLXDrawable glXGetCurrentReadDrawable() {
    printf("glXGetCurrentReadDrawable();\n");
    return 0;
}
#endif
#ifndef skip_glXGetDrawableAttributes
void glXGetDrawableAttributes(uint32_t drawable) {
    printf("glXGetDrawableAttributes(%p);\n", drawable);
}
#endif
#ifndef skip_glXGetDrawableAttributesSGIX
void glXGetDrawableAttributesSGIX(uint32_t drawable) {
    printf("glXGetDrawableAttributesSGIX(%p);\n", drawable);
}
#endif
#ifndef skip_glXGetFBConfigAttrib
int glXGetFBConfigAttrib(Display * dpy, GLXFBConfig config, int attribute, int * value) {
    printf("glXGetFBConfigAttrib(%p, %p, %p, %p);\n", dpy, config, attribute, value);
    return 0;
}
#endif
#ifndef skip_glXGetFBConfigs
GLXFBConfig * glXGetFBConfigs(Display * dpy, int screen, int * nelements) {
    printf("glXGetFBConfigs(%p, %p, %p);\n", dpy, screen, nelements);
    return 0;
}
#endif
#ifndef skip_glXGetFBConfigsSGIX
void glXGetFBConfigsSGIX() {
    printf("glXGetFBConfigsSGIX();\n");
}
#endif
#ifndef skip_glXGetProcAddress
__GLXextFuncPtr glXGetProcAddress(const GLubyte * procName) {
    printf("glXGetProcAddress(%p);\n", procName);
    return 0;
}
#endif
#ifndef skip_glXGetSelectedEvent
void glXGetSelectedEvent(Display * dpy, GLXDrawable draw, unsigned long * event_mask) {
    printf("glXGetSelectedEvent(%p, %p, %p);\n", dpy, draw, event_mask);
}
#endif
#ifndef skip_glXGetVisualConfigs
void glXGetVisualConfigs() {
    printf("glXGetVisualConfigs();\n");
}
#endif
#ifndef skip_glXGetVisualFromFBConfig
XVisualInfo * glXGetVisualFromFBConfig(Display * dpy, GLXFBConfig config) {
    printf("glXGetVisualFromFBConfig(%p, %p);\n", dpy, config);
    return 0;
}
#endif
#ifndef skip_glXHyperpipeAttribSGIX
int glXHyperpipeAttribSGIX(Display * dpy, int timeSlice, int attrib, int size, const void * attribList) {
    printf("glXHyperpipeAttribSGIX(%p, %p, %p, %p, %p);\n", dpy, timeSlice, attrib, size, attribList);
    return 0;
}
#endif
#ifndef skip_glXHyperpipeConfigSGIX
int glXHyperpipeConfigSGIX(Display * dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX cfg, int * hpId) {
    printf("glXHyperpipeConfigSGIX(%p, %p, %p, %p, %p);\n", dpy, networkId, npipes, cfg, hpId);
    return 0;
}
#endif
#ifndef skip_glXIsDirect
Bool glXIsDirect(Display * dpy, GLXContext ctx) {
    printf("glXIsDirect(%p, %p);\n", dpy, ctx);
    return 0;
}
#endif
#ifndef skip_glXJoinSwapGroupSGIX
void glXJoinSwapGroupSGIX(uint32_t window, uint32_t group) {
    printf("glXJoinSwapGroupSGIX(%p, %p);\n", window, group);
}
#endif
#ifndef skip_glXMakeContextCurrent
Bool glXMakeContextCurrent(Display * dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx) {
    printf("glXMakeContextCurrent(%p, %p, %p, %p);\n", dpy, draw, read, ctx);
    return 0;
}
#endif
#ifndef skip_glXMakeCurrent
Bool glXMakeCurrent(Display * dpy, GLXDrawable drawable, GLXContext ctx) {
    printf("glXMakeCurrent(%p, %p, %p);\n", dpy, drawable, ctx);
    return 0;
}
#endif
#ifndef skip_glXMakeCurrentReadSGI
void glXMakeCurrentReadSGI(uint32_t drawable, uint32_t readdrawable, uint32_t context) {
    printf("glXMakeCurrentReadSGI(%p, %p, %p);\n", drawable, readdrawable, context);
}
#endif
#ifndef skip_glXQueryContext
int glXQueryContext(Display * dpy, GLXContext ctx, int attribute, int * value) {
    printf("glXQueryContext(%p, %p, %p, %p);\n", dpy, ctx, attribute, value);
    return 0;
}
#endif
#ifndef skip_glXQueryContextInfoEXT
void glXQueryContextInfoEXT() {
    printf("glXQueryContextInfoEXT();\n");
}
#endif
#ifndef skip_glXQueryDrawable
void glXQueryDrawable(Display * dpy, GLXDrawable draw, int attribute, unsigned int * value) {
    printf("glXQueryDrawable(%p, %p, %p, %p);\n", dpy, draw, attribute, value);
}
#endif
#ifndef skip_glXQueryExtensionsString
const char * glXQueryExtensionsString(Display * dpy, int screen) {
    printf("glXQueryExtensionsString(%p, %p);\n", dpy, screen);
    return 0;
}
#endif
#ifndef skip_glXQueryHyperpipeAttribSGIX
int glXQueryHyperpipeAttribSGIX(Display * dpy, int timeSlice, int attrib, int size, const void * returnAttribList) {
    printf("glXQueryHyperpipeAttribSGIX(%p, %p, %p, %p, %p);\n", dpy, timeSlice, attrib, size, returnAttribList);
    return 0;
}
#endif
#ifndef skip_glXQueryHyperpipeBestAttribSGIX
int glXQueryHyperpipeBestAttribSGIX(Display * dpy, int timeSlice, int attrib, int size, const void * attribList, void * returnAttribList) {
    printf("glXQueryHyperpipeBestAttribSGIX(%p, %p, %p, %p, %p, %p);\n", dpy, timeSlice, attrib, size, attribList, returnAttribList);
    return 0;
}
#endif
#ifndef skip_glXQueryHyperpipeConfigSGIX
GLXHyperpipeConfigSGIX * glXQueryHyperpipeConfigSGIX(Display * dpy, int hpId, int * npipes) {
    printf("glXQueryHyperpipeConfigSGIX(%p, %p, %p);\n", dpy, hpId, npipes);
    return 0;
}
#endif
#ifndef skip_glXQueryHyperpipeNetworkSGIX
GLXHyperpipeNetworkSGIX * glXQueryHyperpipeNetworkSGIX(Display * dpy, int * npipes) {
    printf("glXQueryHyperpipeNetworkSGIX(%p, %p);\n", dpy, npipes);
    return 0;
}
#endif
#ifndef skip_glXQueryMaxSwapBarriersSGIX
void glXQueryMaxSwapBarriersSGIX() {
    printf("glXQueryMaxSwapBarriersSGIX();\n");
}
#endif
#ifndef skip_glXQueryServerString
const char * glXQueryServerString(Display * dpy, int screen, int name) {
    printf("glXQueryServerString(%p, %p, %p);\n", dpy, screen, name);
    return 0;
}
#endif
#ifndef skip_glXQueryVersion
Bool glXQueryVersion(Display * dpy, int * maj, int * min) {
    printf("glXQueryVersion(%p, %p, %p);\n", dpy, maj, min);
    return 0;
}
#endif
#ifndef skip_glXRender
void glXRender() {
    printf("glXRender();\n");
}
#endif
#ifndef skip_glXRenderLarge
void glXRenderLarge() {
    printf("glXRenderLarge();\n");
}
#endif
#ifndef skip_glXSelectEvent
void glXSelectEvent(Display * dpy, GLXDrawable draw, unsigned long event_mask) {
    printf("glXSelectEvent(%p, %p, %p);\n", dpy, draw, event_mask);
}
#endif
#ifndef skip_glXSwapBuffers
void glXSwapBuffers(Display * dpy, GLXDrawable drawable) {
    printf("glXSwapBuffers(%p, %p);\n", dpy, drawable);
}
#endif
#ifndef skip_glXSwapIntervalSGI
void glXSwapIntervalSGI() {
    printf("glXSwapIntervalSGI();\n");
}
#endif
#ifndef skip_glXUseXFont
void glXUseXFont(Font font, int first, int count, int list) {
    printf("glXUseXFont(%p, %p, %p, %p);\n", font, first, count, list);
}
#endif
#ifndef skip_glXVendorPrivate
void glXVendorPrivate() {
    printf("glXVendorPrivate();\n");
}
#endif
#ifndef skip_glXVendorPrivateWithReply
void glXVendorPrivateWithReply() {
    printf("glXVendorPrivateWithReply();\n");
}
#endif
#ifndef skip_glXWaitGL
void glXWaitGL() {
    printf("glXWaitGL();\n");
}
#endif
#ifndef skip_glXWaitX
void glXWaitX() {
    printf("glXWaitX();\n");
}
#endif
