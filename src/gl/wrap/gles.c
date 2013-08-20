#ifndef USE_ES2
#include "gles.h"

void glPackedCall(const packed_call_t *packed) {
    switch (packed->format) {
        case FORMAT_void_GLenum: {
            PACKED_void_GLenum *unpacked = (PACKED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLenum_GLclampf: {
            PACKED_void_GLenum_GLclampf *unpacked = (PACKED_void_GLenum_GLclampf *)packed;
            ARGS_void_GLenum_GLclampf args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLclampx: {
            PACKED_void_GLenum_GLclampx *unpacked = (PACKED_void_GLenum_GLclampx *)packed;
            ARGS_void_GLenum_GLclampx args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLuint: {
            PACKED_void_GLenum_GLuint *unpacked = (PACKED_void_GLenum_GLuint *)packed;
            ARGS_void_GLenum_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLenum: {
            PACKED_void_GLenum_GLenum *unpacked = (PACKED_void_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2);
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
        case FORMAT_void_GLbitfield: {
            PACKED_void_GLbitfield *unpacked = (PACKED_void_GLbitfield *)packed;
            ARGS_void_GLbitfield args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLclampf_GLclampf_GLclampf_GLclampf: {
            PACKED_void_GLclampf_GLclampf_GLclampf_GLclampf *unpacked = (PACKED_void_GLclampf_GLclampf_GLclampf_GLclampf *)packed;
            ARGS_void_GLclampf_GLclampf_GLclampf_GLclampf args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLclampx_GLclampx_GLclampx_GLclampx: {
            PACKED_void_GLclampx_GLclampx_GLclampx_GLclampx *unpacked = (PACKED_void_GLclampx_GLclampx_GLclampx_GLclampx *)packed;
            ARGS_void_GLclampx_GLclampx_GLclampx_GLclampx args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLclampf: {
            PACKED_void_GLclampf *unpacked = (PACKED_void_GLclampf *)packed;
            ARGS_void_GLclampf args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLclampx: {
            PACKED_void_GLclampx *unpacked = (PACKED_void_GLclampx *)packed;
            ARGS_void_GLclampx args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLint: {
            PACKED_void_GLint *unpacked = (PACKED_void_GLint *)packed;
            ARGS_void_GLint args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLenum_const_GLfloat___GENPT__: {
            PACKED_void_GLenum_const_GLfloat___GENPT__ *unpacked = (PACKED_void_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_const_GLfixed___GENPT__: {
            PACKED_void_GLenum_const_GLfixed___GENPT__ *unpacked = (PACKED_void_GLenum_const_GLfixed___GENPT__ *)packed;
            ARGS_void_GLenum_const_GLfixed___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLubyte_GLubyte_GLubyte_GLubyte: {
            PACKED_void_GLubyte_GLubyte_GLubyte_GLubyte *unpacked = (PACKED_void_GLubyte_GLubyte_GLubyte_GLubyte *)packed;
            ARGS_void_GLubyte_GLubyte_GLubyte_GLubyte args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed: {
            PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed *unpacked = (PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed *)packed;
            ARGS_void_GLfixed_GLfixed_GLfixed_GLfixed args = unpacked->args;
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
        case FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint: {
            PACKED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint *)packed;
            ARGS_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei: {
            PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *unpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
            break;
        }
        case FORMAT_void_GLsizei_const_GLuint___GENPT__: {
            PACKED_void_GLsizei_const_GLuint___GENPT__ *unpacked = (PACKED_void_GLsizei_const_GLuint___GENPT__ *)packed;
            ARGS_void_GLsizei_const_GLuint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLboolean: {
            PACKED_void_GLboolean *unpacked = (PACKED_void_GLboolean *)packed;
            ARGS_void_GLboolean args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLclampf_GLclampf: {
            PACKED_void_GLclampf_GLclampf *unpacked = (PACKED_void_GLclampf_GLclampf *)packed;
            ARGS_void_GLclampf_GLclampf args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLclampx_GLclampx: {
            PACKED_void_GLclampx_GLclampx *unpacked = (PACKED_void_GLclampx_GLclampx *)packed;
            ARGS_void_GLclampx_GLclampx args = unpacked->args;
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
        case FORMAT_void: {
            PACKED_void *unpacked = (PACKED_void *)packed;
            ARGS_void args = unpacked->args;
            unpacked->func();
            break;
        }
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
        case FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed: {
            PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed *unpacked = (PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed *)packed;
            ARGS_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
            break;
        }
        case FORMAT_void_GLsizei_GLuint___GENPT__: {
            PACKED_void_GLsizei_GLuint___GENPT__ *unpacked = (PACKED_void_GLsizei_GLuint___GENPT__ *)packed;
            ARGS_void_GLsizei_GLuint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
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
        case FORMAT_void_GLenum_GLfloat___GENPT__: {
            PACKED_void_GLenum_GLfloat___GENPT__ *unpacked = (PACKED_void_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLfixed___GENPT__: {
            PACKED_void_GLenum_GLfixed___GENPT__ *unpacked = (PACKED_void_GLenum_GLfixed___GENPT__ *)packed;
            ARGS_void_GLenum_GLfixed___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_GLenum: {
            PACKED_GLenum *unpacked = (PACKED_GLenum *)packed;
            ARGS_GLenum args = unpacked->args;
            unpacked->func();
            break;
        }
        case FORMAT_void_GLenum_GLint___GENPT__: {
            PACKED_void_GLenum_GLint___GENPT__ *unpacked = (PACKED_void_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLfloat___GENPT__: {
            PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLfixed___GENPT__: {
            PACKED_void_GLenum_GLenum_GLfixed___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLfixed___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfixed___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLvoid___GENPT____GENPT__: {
            PACKED_void_GLenum_GLvoid___GENPT____GENPT__ *unpacked = (PACKED_void_GLenum_GLvoid___GENPT____GENPT__ *)packed;
            ARGS_void_GLenum_GLvoid___GENPT____GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_const_GLubyte___GENPT___GLenum: {
            PACKED_const_GLubyte___GENPT___GLenum *unpacked = (PACKED_const_GLubyte___GENPT___GLenum *)packed;
            ARGS_const_GLubyte___GENPT___GLenum args = unpacked->args;
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
        case FORMAT_void_GLenum_GLenum_GLfloat: {
            PACKED_void_GLenum_GLenum_GLfloat *unpacked = (PACKED_void_GLenum_GLenum_GLfloat *)packed;
            ARGS_void_GLenum_GLenum_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__: {
            PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLfixed: {
            PACKED_void_GLenum_GLenum_GLfixed *unpacked = (PACKED_void_GLenum_GLenum_GLfixed *)packed;
            ARGS_void_GLenum_GLenum_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_const_GLfixed___GENPT__: {
            PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLfixed___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLfloat: {
            PACKED_void_GLfloat *unpacked = (PACKED_void_GLfloat *)packed;
            ARGS_void_GLfloat args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLfixed: {
            PACKED_void_GLfixed *unpacked = (PACKED_void_GLfixed *)packed;
            ARGS_void_GLfixed args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_const_GLfloat___GENPT__: {
            PACKED_void_const_GLfloat___GENPT__ *unpacked = (PACKED_void_const_GLfloat___GENPT__ *)packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_const_GLfixed___GENPT__: {
            PACKED_void_const_GLfixed___GENPT__ *unpacked = (PACKED_void_const_GLfixed___GENPT__ *)packed;
            ARGS_void_const_GLfixed___GENPT__ args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed: {
            PACKED_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed *unpacked = (PACKED_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed *)packed;
            ARGS_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLfixed_GLfixed_GLfixed: {
            PACKED_void_GLfixed_GLfixed_GLfixed *unpacked = (PACKED_void_GLfixed_GLfixed_GLfixed *)packed;
            ARGS_void_GLfixed_GLfixed_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLsizei_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLint: {
            PACKED_void_GLenum_GLint *unpacked = (PACKED_void_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat *)packed;
            ARGS_void_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLfixed_GLfixed: {
            PACKED_void_GLfixed_GLfixed *unpacked = (PACKED_void_GLfixed_GLfixed *)packed;
            ARGS_void_GLfixed_GLfixed args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__: {
            PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ *unpacked = (PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLclampf_GLboolean: {
            PACKED_void_GLclampf_GLboolean *unpacked = (PACKED_void_GLclampf_GLboolean *)packed;
            ARGS_void_GLclampf_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLclampx_GLboolean: {
            PACKED_void_GLclampx_GLboolean *unpacked = (PACKED_void_GLclampx_GLboolean *)packed;
            ARGS_void_GLclampx_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLint_GLint_GLsizei_GLsizei: {
            PACKED_void_GLint_GLint_GLsizei_GLsizei *unpacked = (PACKED_void_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLuint: {
            PACKED_void_GLenum_GLint_GLuint *unpacked = (PACKED_void_GLenum_GLint_GLuint *)packed;
            ARGS_void_GLenum_GLint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint: {
            PACKED_void_GLuint *unpacked = (PACKED_void_GLuint *)packed;
            ARGS_void_GLuint args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum: {
            PACKED_void_GLenum_GLenum_GLenum *unpacked = (PACKED_void_GLenum_GLenum_GLenum *)packed;
            ARGS_void_GLenum_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint: {
            PACKED_void_GLenum_GLenum_GLint *unpacked = (PACKED_void_GLenum_GLenum_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_const_GLint___GENPT__: {
            PACKED_void_GLenum_GLenum_const_GLint___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_const_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_const_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
    }
}
#if !defined(skip_glActiveTexture) || defined(DISABLE_SKIP)
void glActiveTexture(GLenum texture) {
    LOAD_GLES(glActiveTexture);
#ifndef direct_glActiveTexture
    PUSH_IF_COMPILING(glActiveTexture)
#endif
    gles_glActiveTexture(texture);

}
#endif
#if !defined(skip_glAlphaFunc) || defined(DISABLE_SKIP)
void glAlphaFunc(GLenum func, GLclampf ref) {
    LOAD_GLES(glAlphaFunc);
#ifndef direct_glAlphaFunc
    PUSH_IF_COMPILING(glAlphaFunc)
#endif
    gles_glAlphaFunc(func, ref);

}
#endif
#if !defined(skip_glAlphaFuncx) || defined(DISABLE_SKIP)
void glAlphaFuncx(GLenum func, GLclampx ref) {
    LOAD_GLES(glAlphaFuncx);
#ifndef direct_glAlphaFuncx
    PUSH_IF_COMPILING(glAlphaFuncx)
#endif
    gles_glAlphaFuncx(func, ref);

}
#endif
#if !defined(skip_glBindBuffer) || defined(DISABLE_SKIP)
void glBindBuffer(GLenum target, GLuint buffer) {
    LOAD_GLES(glBindBuffer);
#ifndef direct_glBindBuffer
    PUSH_IF_COMPILING(glBindBuffer)
#endif
    gles_glBindBuffer(target, buffer);

}
#endif
#if !defined(skip_glBindTexture) || defined(DISABLE_SKIP)
void glBindTexture(GLenum target, GLuint texture) {
    LOAD_GLES(glBindTexture);
#ifndef direct_glBindTexture
    PUSH_IF_COMPILING(glBindTexture)
#endif
    gles_glBindTexture(target, texture);

}
#endif
#if !defined(skip_glBlendFunc) || defined(DISABLE_SKIP)
void glBlendFunc(GLenum sfactor, GLenum dfactor) {
    LOAD_GLES(glBlendFunc);
#ifndef direct_glBlendFunc
    PUSH_IF_COMPILING(glBlendFunc)
#endif
    gles_glBlendFunc(sfactor, dfactor);

}
#endif
#if !defined(skip_glBufferData) || defined(DISABLE_SKIP)
void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage) {
    LOAD_GLES(glBufferData);
#ifndef direct_glBufferData
    PUSH_IF_COMPILING(glBufferData)
#endif
    gles_glBufferData(target, size, data, usage);

}
#endif
#if !defined(skip_glBufferSubData) || defined(DISABLE_SKIP)
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data) {
    LOAD_GLES(glBufferSubData);
#ifndef direct_glBufferSubData
    PUSH_IF_COMPILING(glBufferSubData)
#endif
    gles_glBufferSubData(target, offset, size, data);

}
#endif
#if !defined(skip_glClear) || defined(DISABLE_SKIP)
void glClear(GLbitfield mask) {
    LOAD_GLES(glClear);
#ifndef direct_glClear
    PUSH_IF_COMPILING(glClear)
#endif
    gles_glClear(mask);

}
#endif
#if !defined(skip_glClearColor) || defined(DISABLE_SKIP)
void glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
    LOAD_GLES(glClearColor);
#ifndef direct_glClearColor
    PUSH_IF_COMPILING(glClearColor)
#endif
    gles_glClearColor(red, green, blue, alpha);

}
#endif
#if !defined(skip_glClearColorx) || defined(DISABLE_SKIP)
void glClearColorx(GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha) {
    LOAD_GLES(glClearColorx);
#ifndef direct_glClearColorx
    PUSH_IF_COMPILING(glClearColorx)
#endif
    gles_glClearColorx(red, green, blue, alpha);

}
#endif
#if !defined(skip_glClearDepthf) || defined(DISABLE_SKIP)
void glClearDepthf(GLclampf depth) {
    LOAD_GLES(glClearDepthf);
#ifndef direct_glClearDepthf
    PUSH_IF_COMPILING(glClearDepthf)
#endif
    gles_glClearDepthf(depth);

}
#endif
#if !defined(skip_glClearDepthx) || defined(DISABLE_SKIP)
void glClearDepthx(GLclampx depth) {
    LOAD_GLES(glClearDepthx);
#ifndef direct_glClearDepthx
    PUSH_IF_COMPILING(glClearDepthx)
#endif
    gles_glClearDepthx(depth);

}
#endif
#if !defined(skip_glClearStencil) || defined(DISABLE_SKIP)
void glClearStencil(GLint s) {
    LOAD_GLES(glClearStencil);
#ifndef direct_glClearStencil
    PUSH_IF_COMPILING(glClearStencil)
#endif
    gles_glClearStencil(s);

}
#endif
#if !defined(skip_glClientActiveTexture) || defined(DISABLE_SKIP)
void glClientActiveTexture(GLenum texture) {
    LOAD_GLES(glClientActiveTexture);
#ifndef direct_glClientActiveTexture
    PUSH_IF_COMPILING(glClientActiveTexture)
#endif
    gles_glClientActiveTexture(texture);

}
#endif
#if !defined(skip_glClipPlanef) || defined(DISABLE_SKIP)
void glClipPlanef(GLenum plane, const GLfloat * equation) {
    LOAD_GLES(glClipPlanef);
#ifndef direct_glClipPlanef
    PUSH_IF_COMPILING(glClipPlanef)
#endif
    gles_glClipPlanef(plane, equation);

}
#endif
#if !defined(skip_glClipPlanex) || defined(DISABLE_SKIP)
void glClipPlanex(GLenum plane, const GLfixed * equation) {
    LOAD_GLES(glClipPlanex);
#ifndef direct_glClipPlanex
    PUSH_IF_COMPILING(glClipPlanex)
#endif
    gles_glClipPlanex(plane, equation);

}
#endif
#if !defined(skip_glColor4f) || defined(DISABLE_SKIP)
void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    LOAD_GLES(glColor4f);
#ifndef direct_glColor4f
    PUSH_IF_COMPILING(glColor4f)
#endif
    gles_glColor4f(red, green, blue, alpha);

}
#endif
#if !defined(skip_glColor4ub) || defined(DISABLE_SKIP)
void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {
    LOAD_GLES(glColor4ub);
#ifndef direct_glColor4ub
    PUSH_IF_COMPILING(glColor4ub)
#endif
    gles_glColor4ub(red, green, blue, alpha);

}
#endif
#if !defined(skip_glColor4x) || defined(DISABLE_SKIP)
void glColor4x(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
    LOAD_GLES(glColor4x);
#ifndef direct_glColor4x
    PUSH_IF_COMPILING(glColor4x)
#endif
    gles_glColor4x(red, green, blue, alpha);

}
#endif
#if !defined(skip_glColorMask) || defined(DISABLE_SKIP)
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
    LOAD_GLES(glColorMask);
#ifndef direct_glColorMask
    PUSH_IF_COMPILING(glColorMask)
#endif
    gles_glColorMask(red, green, blue, alpha);

}
#endif
#if !defined(skip_glColorPointer) || defined(DISABLE_SKIP)
void glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    LOAD_GLES(glColorPointer);
#ifndef direct_glColorPointer
    PUSH_IF_COMPILING(glColorPointer)
#endif
    gles_glColorPointer(size, type, stride, pointer);

}
#endif
#if !defined(skip_glCompressedTexImage2D) || defined(DISABLE_SKIP)
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data) {
    LOAD_GLES(glCompressedTexImage2D);
#ifndef direct_glCompressedTexImage2D
    PUSH_IF_COMPILING(glCompressedTexImage2D)
#endif
    gles_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);

}
#endif
#if !defined(skip_glCompressedTexSubImage2D) || defined(DISABLE_SKIP)
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data) {
    LOAD_GLES(glCompressedTexSubImage2D);
#ifndef direct_glCompressedTexSubImage2D
    PUSH_IF_COMPILING(glCompressedTexSubImage2D)
#endif
    gles_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);

}
#endif
#if !defined(skip_glCopyTexImage2D) || defined(DISABLE_SKIP)
void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    LOAD_GLES(glCopyTexImage2D);
#ifndef direct_glCopyTexImage2D
    PUSH_IF_COMPILING(glCopyTexImage2D)
#endif
    gles_glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);

}
#endif
#if !defined(skip_glCopyTexSubImage2D) || defined(DISABLE_SKIP)
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    LOAD_GLES(glCopyTexSubImage2D);
#ifndef direct_glCopyTexSubImage2D
    PUSH_IF_COMPILING(glCopyTexSubImage2D)
#endif
    gles_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);

}
#endif
#if !defined(skip_glCullFace) || defined(DISABLE_SKIP)
void glCullFace(GLenum mode) {
    LOAD_GLES(glCullFace);
#ifndef direct_glCullFace
    PUSH_IF_COMPILING(glCullFace)
#endif
    gles_glCullFace(mode);

}
#endif
#if !defined(skip_glDeleteBuffers) || defined(DISABLE_SKIP)
void glDeleteBuffers(GLsizei n, const GLuint * buffers) {
    LOAD_GLES(glDeleteBuffers);
#ifndef direct_glDeleteBuffers
    PUSH_IF_COMPILING(glDeleteBuffers)
#endif
    gles_glDeleteBuffers(n, buffers);

}
#endif
#if !defined(skip_glDeleteTextures) || defined(DISABLE_SKIP)
void glDeleteTextures(GLsizei n, const GLuint * textures) {
    LOAD_GLES(glDeleteTextures);
#ifndef direct_glDeleteTextures
    PUSH_IF_COMPILING(glDeleteTextures)
#endif
    gles_glDeleteTextures(n, textures);

}
#endif
#if !defined(skip_glDepthFunc) || defined(DISABLE_SKIP)
void glDepthFunc(GLenum func) {
    LOAD_GLES(glDepthFunc);
#ifndef direct_glDepthFunc
    PUSH_IF_COMPILING(glDepthFunc)
#endif
    gles_glDepthFunc(func);

}
#endif
#if !defined(skip_glDepthMask) || defined(DISABLE_SKIP)
void glDepthMask(GLboolean flag) {
    LOAD_GLES(glDepthMask);
#ifndef direct_glDepthMask
    PUSH_IF_COMPILING(glDepthMask)
#endif
    gles_glDepthMask(flag);

}
#endif
#if !defined(skip_glDepthRangef) || defined(DISABLE_SKIP)
void glDepthRangef(GLclampf near, GLclampf far) {
    LOAD_GLES(glDepthRangef);
#ifndef direct_glDepthRangef
    PUSH_IF_COMPILING(glDepthRangef)
#endif
    gles_glDepthRangef(near, far);

}
#endif
#if !defined(skip_glDepthRangex) || defined(DISABLE_SKIP)
void glDepthRangex(GLclampx near, GLclampx far) {
    LOAD_GLES(glDepthRangex);
#ifndef direct_glDepthRangex
    PUSH_IF_COMPILING(glDepthRangex)
#endif
    gles_glDepthRangex(near, far);

}
#endif
#if !defined(skip_glDisable) || defined(DISABLE_SKIP)
void glDisable(GLenum cap) {
    LOAD_GLES(glDisable);
#ifndef direct_glDisable
    PUSH_IF_COMPILING(glDisable)
#endif
    gles_glDisable(cap);

}
#endif
#if !defined(skip_glDisableClientState) || defined(DISABLE_SKIP)
void glDisableClientState(GLenum array) {
    LOAD_GLES(glDisableClientState);
#ifndef direct_glDisableClientState
    PUSH_IF_COMPILING(glDisableClientState)
#endif
    gles_glDisableClientState(array);

}
#endif
#if !defined(skip_glDrawArrays) || defined(DISABLE_SKIP)
void glDrawArrays(GLenum mode, GLint first, GLsizei count) {
    LOAD_GLES(glDrawArrays);
#ifndef direct_glDrawArrays
    PUSH_IF_COMPILING(glDrawArrays)
#endif
    gles_glDrawArrays(mode, first, count);

}
#endif
#if !defined(skip_glDrawElements) || defined(DISABLE_SKIP)
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices) {
    LOAD_GLES(glDrawElements);
#ifndef direct_glDrawElements
    PUSH_IF_COMPILING(glDrawElements)
#endif
    gles_glDrawElements(mode, count, type, indices);

}
#endif
#if !defined(skip_glEnable) || defined(DISABLE_SKIP)
void glEnable(GLenum cap) {
    LOAD_GLES(glEnable);
#ifndef direct_glEnable
    PUSH_IF_COMPILING(glEnable)
#endif
    gles_glEnable(cap);

}
#endif
#if !defined(skip_glEnableClientState) || defined(DISABLE_SKIP)
void glEnableClientState(GLenum array) {
    LOAD_GLES(glEnableClientState);
#ifndef direct_glEnableClientState
    PUSH_IF_COMPILING(glEnableClientState)
#endif
    gles_glEnableClientState(array);

}
#endif
#if !defined(skip_glFinish) || defined(DISABLE_SKIP)
void glFinish() {
    LOAD_GLES(glFinish);
#ifndef direct_glFinish
    PUSH_IF_COMPILING(glFinish)
#endif
    gles_glFinish();

}
#endif
#if !defined(skip_glFlush) || defined(DISABLE_SKIP)
void glFlush() {
    LOAD_GLES(glFlush);
#ifndef direct_glFlush
    PUSH_IF_COMPILING(glFlush)
#endif
    gles_glFlush();

}
#endif
#if !defined(skip_glFogf) || defined(DISABLE_SKIP)
void glFogf(GLenum pname, GLfloat param) {
    LOAD_GLES(glFogf);
#ifndef direct_glFogf
    PUSH_IF_COMPILING(glFogf)
#endif
    gles_glFogf(pname, param);

}
#endif
#if !defined(skip_glFogfv) || defined(DISABLE_SKIP)
void glFogfv(GLenum pname, const GLfloat * params) {
    LOAD_GLES(glFogfv);
#ifndef direct_glFogfv
    PUSH_IF_COMPILING(glFogfv)
#endif
    gles_glFogfv(pname, params);

}
#endif
#if !defined(skip_glFogx) || defined(DISABLE_SKIP)
void glFogx(GLenum pname, GLfixed param) {
    LOAD_GLES(glFogx);
#ifndef direct_glFogx
    PUSH_IF_COMPILING(glFogx)
#endif
    gles_glFogx(pname, param);

}
#endif
#if !defined(skip_glFogxv) || defined(DISABLE_SKIP)
void glFogxv(GLenum pname, const GLfixed * params) {
    LOAD_GLES(glFogxv);
#ifndef direct_glFogxv
    PUSH_IF_COMPILING(glFogxv)
#endif
    gles_glFogxv(pname, params);

}
#endif
#if !defined(skip_glFrontFace) || defined(DISABLE_SKIP)
void glFrontFace(GLenum mode) {
    LOAD_GLES(glFrontFace);
#ifndef direct_glFrontFace
    PUSH_IF_COMPILING(glFrontFace)
#endif
    gles_glFrontFace(mode);

}
#endif
#if !defined(skip_glFrustumf) || defined(DISABLE_SKIP)
void glFrustumf(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far) {
    LOAD_GLES(glFrustumf);
#ifndef direct_glFrustumf
    PUSH_IF_COMPILING(glFrustumf)
#endif
    gles_glFrustumf(left, right, bottom, top, near, far);

}
#endif
#if !defined(skip_glFrustumx) || defined(DISABLE_SKIP)
void glFrustumx(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far) {
    LOAD_GLES(glFrustumx);
#ifndef direct_glFrustumx
    PUSH_IF_COMPILING(glFrustumx)
#endif
    gles_glFrustumx(left, right, bottom, top, near, far);

}
#endif
#if !defined(skip_glGenBuffers) || defined(DISABLE_SKIP)
void glGenBuffers(GLsizei n, GLuint * buffers) {
    LOAD_GLES(glGenBuffers);
#ifndef direct_glGenBuffers
    PUSH_IF_COMPILING(glGenBuffers)
#endif
    gles_glGenBuffers(n, buffers);

}
#endif
#if !defined(skip_glGenTextures) || defined(DISABLE_SKIP)
void glGenTextures(GLsizei n, GLuint * textures) {
    LOAD_GLES(glGenTextures);
#ifndef direct_glGenTextures
    PUSH_IF_COMPILING(glGenTextures)
#endif
    gles_glGenTextures(n, textures);

}
#endif
#if !defined(skip_glGetBooleanv) || defined(DISABLE_SKIP)
void glGetBooleanv(GLenum pname, GLboolean * params) {
    LOAD_GLES(glGetBooleanv);
#ifndef direct_glGetBooleanv
    PUSH_IF_COMPILING(glGetBooleanv)
#endif
    gles_glGetBooleanv(pname, params);

}
#endif
#if !defined(skip_glGetBufferParameteriv) || defined(DISABLE_SKIP)
void glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    LOAD_GLES(glGetBufferParameteriv);
#ifndef direct_glGetBufferParameteriv
    PUSH_IF_COMPILING(glGetBufferParameteriv)
#endif
    gles_glGetBufferParameteriv(target, pname, params);

}
#endif
#if !defined(skip_glGetClipPlanef) || defined(DISABLE_SKIP)
void glGetClipPlanef(GLenum plane, GLfloat * equation) {
    LOAD_GLES(glGetClipPlanef);
#ifndef direct_glGetClipPlanef
    PUSH_IF_COMPILING(glGetClipPlanef)
#endif
    gles_glGetClipPlanef(plane, equation);

}
#endif
#if !defined(skip_glGetClipPlanex) || defined(DISABLE_SKIP)
void glGetClipPlanex(GLenum plane, GLfixed * equation) {
    LOAD_GLES(glGetClipPlanex);
#ifndef direct_glGetClipPlanex
    PUSH_IF_COMPILING(glGetClipPlanex)
#endif
    gles_glGetClipPlanex(plane, equation);

}
#endif
#if !defined(skip_glGetError) || defined(DISABLE_SKIP)
GLenum glGetError() {
    LOAD_GLES(glGetError);
#ifndef direct_glGetError
    PUSH_IF_COMPILING(glGetError)
#endif
    return gles_glGetError();

}
#endif
#if !defined(skip_glGetFixedv) || defined(DISABLE_SKIP)
void glGetFixedv(GLenum pname, GLfixed * params) {
    LOAD_GLES(glGetFixedv);
#ifndef direct_glGetFixedv
    PUSH_IF_COMPILING(glGetFixedv)
#endif
    gles_glGetFixedv(pname, params);

}
#endif
#if !defined(skip_glGetFloatv) || defined(DISABLE_SKIP)
void glGetFloatv(GLenum pname, GLfloat * params) {
    LOAD_GLES(glGetFloatv);
#ifndef direct_glGetFloatv
    PUSH_IF_COMPILING(glGetFloatv)
#endif
    gles_glGetFloatv(pname, params);

}
#endif
#if !defined(skip_glGetIntegerv) || defined(DISABLE_SKIP)
void glGetIntegerv(GLenum pname, GLint * params) {
    LOAD_GLES(glGetIntegerv);
#ifndef direct_glGetIntegerv
    PUSH_IF_COMPILING(glGetIntegerv)
#endif
    gles_glGetIntegerv(pname, params);

}
#endif
#if !defined(skip_glGetLightfv) || defined(DISABLE_SKIP)
void glGetLightfv(GLenum light, GLenum pname, GLfloat * params) {
    LOAD_GLES(glGetLightfv);
#ifndef direct_glGetLightfv
    PUSH_IF_COMPILING(glGetLightfv)
#endif
    gles_glGetLightfv(light, pname, params);

}
#endif
#if !defined(skip_glGetLightxv) || defined(DISABLE_SKIP)
void glGetLightxv(GLenum light, GLenum pname, GLfixed * params) {
    LOAD_GLES(glGetLightxv);
#ifndef direct_glGetLightxv
    PUSH_IF_COMPILING(glGetLightxv)
#endif
    gles_glGetLightxv(light, pname, params);

}
#endif
#if !defined(skip_glGetMaterialfv) || defined(DISABLE_SKIP)
void glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params) {
    LOAD_GLES(glGetMaterialfv);
#ifndef direct_glGetMaterialfv
    PUSH_IF_COMPILING(glGetMaterialfv)
#endif
    gles_glGetMaterialfv(face, pname, params);

}
#endif
#if !defined(skip_glGetMaterialxv) || defined(DISABLE_SKIP)
void glGetMaterialxv(GLenum face, GLenum pname, GLfixed * params) {
    LOAD_GLES(glGetMaterialxv);
#ifndef direct_glGetMaterialxv
    PUSH_IF_COMPILING(glGetMaterialxv)
#endif
    gles_glGetMaterialxv(face, pname, params);

}
#endif
#if !defined(skip_glGetPointerv) || defined(DISABLE_SKIP)
void glGetPointerv(GLenum pname, GLvoid ** params) {
    LOAD_GLES(glGetPointerv);
#ifndef direct_glGetPointerv
    PUSH_IF_COMPILING(glGetPointerv)
#endif
    gles_glGetPointerv(pname, params);

}
#endif
#if !defined(skip_glGetString) || defined(DISABLE_SKIP)
const GLubyte * glGetString(GLenum name) {
    LOAD_GLES(glGetString);
#ifndef direct_glGetString
    PUSH_IF_COMPILING(glGetString)
#endif
    return gles_glGetString(name);

}
#endif
#if !defined(skip_glGetTexEnvfv) || defined(DISABLE_SKIP)
void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params) {
    LOAD_GLES(glGetTexEnvfv);
#ifndef direct_glGetTexEnvfv
    PUSH_IF_COMPILING(glGetTexEnvfv)
#endif
    gles_glGetTexEnvfv(target, pname, params);

}
#endif
#if !defined(skip_glGetTexEnviv) || defined(DISABLE_SKIP)
void glGetTexEnviv(GLenum target, GLenum pname, GLint * params) {
    LOAD_GLES(glGetTexEnviv);
#ifndef direct_glGetTexEnviv
    PUSH_IF_COMPILING(glGetTexEnviv)
#endif
    gles_glGetTexEnviv(target, pname, params);

}
#endif
#if !defined(skip_glGetTexEnvxv) || defined(DISABLE_SKIP)
void glGetTexEnvxv(GLenum target, GLenum pname, GLfixed * params) {
    LOAD_GLES(glGetTexEnvxv);
#ifndef direct_glGetTexEnvxv
    PUSH_IF_COMPILING(glGetTexEnvxv)
#endif
    gles_glGetTexEnvxv(target, pname, params);

}
#endif
#if !defined(skip_glGetTexParameterfv) || defined(DISABLE_SKIP)
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    LOAD_GLES(glGetTexParameterfv);
#ifndef direct_glGetTexParameterfv
    PUSH_IF_COMPILING(glGetTexParameterfv)
#endif
    gles_glGetTexParameterfv(target, pname, params);

}
#endif
#if !defined(skip_glGetTexParameteriv) || defined(DISABLE_SKIP)
void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params) {
    LOAD_GLES(glGetTexParameteriv);
#ifndef direct_glGetTexParameteriv
    PUSH_IF_COMPILING(glGetTexParameteriv)
#endif
    gles_glGetTexParameteriv(target, pname, params);

}
#endif
#if !defined(skip_glGetTexParameterxv) || defined(DISABLE_SKIP)
void glGetTexParameterxv(GLenum target, GLenum pname, GLfixed * params) {
    LOAD_GLES(glGetTexParameterxv);
#ifndef direct_glGetTexParameterxv
    PUSH_IF_COMPILING(glGetTexParameterxv)
#endif
    gles_glGetTexParameterxv(target, pname, params);

}
#endif
#if !defined(skip_glHint) || defined(DISABLE_SKIP)
void glHint(GLenum target, GLenum mode) {
    LOAD_GLES(glHint);
#ifndef direct_glHint
    PUSH_IF_COMPILING(glHint)
#endif
    gles_glHint(target, mode);

}
#endif
#if !defined(skip_glIsBuffer) || defined(DISABLE_SKIP)
GLboolean glIsBuffer(GLuint buffer) {
    LOAD_GLES(glIsBuffer);
#ifndef direct_glIsBuffer
    PUSH_IF_COMPILING(glIsBuffer)
#endif
    return gles_glIsBuffer(buffer);

}
#endif
#if !defined(skip_glIsEnabled) || defined(DISABLE_SKIP)
GLboolean glIsEnabled(GLenum cap) {
    LOAD_GLES(glIsEnabled);
#ifndef direct_glIsEnabled
    PUSH_IF_COMPILING(glIsEnabled)
#endif
    return gles_glIsEnabled(cap);

}
#endif
#if !defined(skip_glIsTexture) || defined(DISABLE_SKIP)
GLboolean glIsTexture(GLuint texture) {
    LOAD_GLES(glIsTexture);
#ifndef direct_glIsTexture
    PUSH_IF_COMPILING(glIsTexture)
#endif
    return gles_glIsTexture(texture);

}
#endif
#if !defined(skip_glLightModelf) || defined(DISABLE_SKIP)
void glLightModelf(GLenum pname, GLfloat param) {
    LOAD_GLES(glLightModelf);
#ifndef direct_glLightModelf
    PUSH_IF_COMPILING(glLightModelf)
#endif
    gles_glLightModelf(pname, param);

}
#endif
#if !defined(skip_glLightModelfv) || defined(DISABLE_SKIP)
void glLightModelfv(GLenum pname, const GLfloat * params) {
    LOAD_GLES(glLightModelfv);
#ifndef direct_glLightModelfv
    PUSH_IF_COMPILING(glLightModelfv)
#endif
    gles_glLightModelfv(pname, params);

}
#endif
#if !defined(skip_glLightModelx) || defined(DISABLE_SKIP)
void glLightModelx(GLenum pname, GLfixed param) {
    LOAD_GLES(glLightModelx);
#ifndef direct_glLightModelx
    PUSH_IF_COMPILING(glLightModelx)
#endif
    gles_glLightModelx(pname, param);

}
#endif
#if !defined(skip_glLightModelxv) || defined(DISABLE_SKIP)
void glLightModelxv(GLenum pname, const GLfixed * params) {
    LOAD_GLES(glLightModelxv);
#ifndef direct_glLightModelxv
    PUSH_IF_COMPILING(glLightModelxv)
#endif
    gles_glLightModelxv(pname, params);

}
#endif
#if !defined(skip_glLightf) || defined(DISABLE_SKIP)
void glLightf(GLenum light, GLenum pname, GLfloat param) {
    LOAD_GLES(glLightf);
#ifndef direct_glLightf
    PUSH_IF_COMPILING(glLightf)
#endif
    gles_glLightf(light, pname, param);

}
#endif
#if !defined(skip_glLightfv) || defined(DISABLE_SKIP)
void glLightfv(GLenum light, GLenum pname, const GLfloat * params) {
    LOAD_GLES(glLightfv);
#ifndef direct_glLightfv
    PUSH_IF_COMPILING(glLightfv)
#endif
    gles_glLightfv(light, pname, params);

}
#endif
#if !defined(skip_glLightx) || defined(DISABLE_SKIP)
void glLightx(GLenum light, GLenum pname, GLfixed param) {
    LOAD_GLES(glLightx);
#ifndef direct_glLightx
    PUSH_IF_COMPILING(glLightx)
#endif
    gles_glLightx(light, pname, param);

}
#endif
#if !defined(skip_glLightxv) || defined(DISABLE_SKIP)
void glLightxv(GLenum light, GLenum pname, const GLfixed * params) {
    LOAD_GLES(glLightxv);
#ifndef direct_glLightxv
    PUSH_IF_COMPILING(glLightxv)
#endif
    gles_glLightxv(light, pname, params);

}
#endif
#if !defined(skip_glLineWidth) || defined(DISABLE_SKIP)
void glLineWidth(GLfloat width) {
    LOAD_GLES(glLineWidth);
#ifndef direct_glLineWidth
    PUSH_IF_COMPILING(glLineWidth)
#endif
    gles_glLineWidth(width);

}
#endif
#if !defined(skip_glLineWidthx) || defined(DISABLE_SKIP)
void glLineWidthx(GLfixed width) {
    LOAD_GLES(glLineWidthx);
#ifndef direct_glLineWidthx
    PUSH_IF_COMPILING(glLineWidthx)
#endif
    gles_glLineWidthx(width);

}
#endif
#if !defined(skip_glLoadIdentity) || defined(DISABLE_SKIP)
void glLoadIdentity() {
    LOAD_GLES(glLoadIdentity);
#ifndef direct_glLoadIdentity
    PUSH_IF_COMPILING(glLoadIdentity)
#endif
    gles_glLoadIdentity();

}
#endif
#if !defined(skip_glLoadMatrixf) || defined(DISABLE_SKIP)
void glLoadMatrixf(const GLfloat * m) {
    LOAD_GLES(glLoadMatrixf);
#ifndef direct_glLoadMatrixf
    PUSH_IF_COMPILING(glLoadMatrixf)
#endif
    gles_glLoadMatrixf(m);

}
#endif
#if !defined(skip_glLoadMatrixx) || defined(DISABLE_SKIP)
void glLoadMatrixx(const GLfixed * m) {
    LOAD_GLES(glLoadMatrixx);
#ifndef direct_glLoadMatrixx
    PUSH_IF_COMPILING(glLoadMatrixx)
#endif
    gles_glLoadMatrixx(m);

}
#endif
#if !defined(skip_glLogicOp) || defined(DISABLE_SKIP)
void glLogicOp(GLenum opcode) {
    LOAD_GLES(glLogicOp);
#ifndef direct_glLogicOp
    PUSH_IF_COMPILING(glLogicOp)
#endif
    gles_glLogicOp(opcode);

}
#endif
#if !defined(skip_glMaterialf) || defined(DISABLE_SKIP)
void glMaterialf(GLenum face, GLenum pname, GLfloat param) {
    LOAD_GLES(glMaterialf);
#ifndef direct_glMaterialf
    PUSH_IF_COMPILING(glMaterialf)
#endif
    gles_glMaterialf(face, pname, param);

}
#endif
#if !defined(skip_glMaterialfv) || defined(DISABLE_SKIP)
void glMaterialfv(GLenum face, GLenum pname, const GLfloat * params) {
    LOAD_GLES(glMaterialfv);
#ifndef direct_glMaterialfv
    PUSH_IF_COMPILING(glMaterialfv)
#endif
    gles_glMaterialfv(face, pname, params);

}
#endif
#if !defined(skip_glMaterialx) || defined(DISABLE_SKIP)
void glMaterialx(GLenum face, GLenum pname, GLfixed param) {
    LOAD_GLES(glMaterialx);
#ifndef direct_glMaterialx
    PUSH_IF_COMPILING(glMaterialx)
#endif
    gles_glMaterialx(face, pname, param);

}
#endif
#if !defined(skip_glMaterialxv) || defined(DISABLE_SKIP)
void glMaterialxv(GLenum face, GLenum pname, const GLfixed * params) {
    LOAD_GLES(glMaterialxv);
#ifndef direct_glMaterialxv
    PUSH_IF_COMPILING(glMaterialxv)
#endif
    gles_glMaterialxv(face, pname, params);

}
#endif
#if !defined(skip_glMatrixMode) || defined(DISABLE_SKIP)
void glMatrixMode(GLenum mode) {
    LOAD_GLES(glMatrixMode);
#ifndef direct_glMatrixMode
    PUSH_IF_COMPILING(glMatrixMode)
#endif
    gles_glMatrixMode(mode);

}
#endif
#if !defined(skip_glMultMatrixf) || defined(DISABLE_SKIP)
void glMultMatrixf(const GLfloat * m) {
    LOAD_GLES(glMultMatrixf);
#ifndef direct_glMultMatrixf
    PUSH_IF_COMPILING(glMultMatrixf)
#endif
    gles_glMultMatrixf(m);

}
#endif
#if !defined(skip_glMultMatrixx) || defined(DISABLE_SKIP)
void glMultMatrixx(const GLfixed * m) {
    LOAD_GLES(glMultMatrixx);
#ifndef direct_glMultMatrixx
    PUSH_IF_COMPILING(glMultMatrixx)
#endif
    gles_glMultMatrixx(m);

}
#endif
#if !defined(skip_glMultiTexCoord4f) || defined(DISABLE_SKIP)
void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    LOAD_GLES(glMultiTexCoord4f);
#ifndef direct_glMultiTexCoord4f
    PUSH_IF_COMPILING(glMultiTexCoord4f)
#endif
    gles_glMultiTexCoord4f(target, s, t, r, q);

}
#endif
#if !defined(skip_glMultiTexCoord4x) || defined(DISABLE_SKIP)
void glMultiTexCoord4x(GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q) {
    LOAD_GLES(glMultiTexCoord4x);
#ifndef direct_glMultiTexCoord4x
    PUSH_IF_COMPILING(glMultiTexCoord4x)
#endif
    gles_glMultiTexCoord4x(target, s, t, r, q);

}
#endif
#if !defined(skip_glNormal3f) || defined(DISABLE_SKIP)
void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {
    LOAD_GLES(glNormal3f);
#ifndef direct_glNormal3f
    PUSH_IF_COMPILING(glNormal3f)
#endif
    gles_glNormal3f(nx, ny, nz);

}
#endif
#if !defined(skip_glNormal3x) || defined(DISABLE_SKIP)
void glNormal3x(GLfixed nx, GLfixed ny, GLfixed nz) {
    LOAD_GLES(glNormal3x);
#ifndef direct_glNormal3x
    PUSH_IF_COMPILING(glNormal3x)
#endif
    gles_glNormal3x(nx, ny, nz);

}
#endif
#if !defined(skip_glNormalPointer) || defined(DISABLE_SKIP)
void glNormalPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    LOAD_GLES(glNormalPointer);
#ifndef direct_glNormalPointer
    PUSH_IF_COMPILING(glNormalPointer)
#endif
    gles_glNormalPointer(type, stride, pointer);

}
#endif
#if !defined(skip_glOrthof) || defined(DISABLE_SKIP)
void glOrthof(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far) {
    LOAD_GLES(glOrthof);
#ifndef direct_glOrthof
    PUSH_IF_COMPILING(glOrthof)
#endif
    gles_glOrthof(left, right, bottom, top, near, far);

}
#endif
#if !defined(skip_glOrthox) || defined(DISABLE_SKIP)
void glOrthox(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far) {
    LOAD_GLES(glOrthox);
#ifndef direct_glOrthox
    PUSH_IF_COMPILING(glOrthox)
#endif
    gles_glOrthox(left, right, bottom, top, near, far);

}
#endif
#if !defined(skip_glPixelStorei) || defined(DISABLE_SKIP)
void glPixelStorei(GLenum pname, GLint param) {
    LOAD_GLES(glPixelStorei);
#ifndef direct_glPixelStorei
    PUSH_IF_COMPILING(glPixelStorei)
#endif
    gles_glPixelStorei(pname, param);

}
#endif
#if !defined(skip_glPointParameterf) || defined(DISABLE_SKIP)
void glPointParameterf(GLenum pname, GLfloat param) {
    LOAD_GLES(glPointParameterf);
#ifndef direct_glPointParameterf
    PUSH_IF_COMPILING(glPointParameterf)
#endif
    gles_glPointParameterf(pname, param);

}
#endif
#if !defined(skip_glPointParameterfv) || defined(DISABLE_SKIP)
void glPointParameterfv(GLenum pname, const GLfloat * params) {
    LOAD_GLES(glPointParameterfv);
#ifndef direct_glPointParameterfv
    PUSH_IF_COMPILING(glPointParameterfv)
#endif
    gles_glPointParameterfv(pname, params);

}
#endif
#if !defined(skip_glPointParameterx) || defined(DISABLE_SKIP)
void glPointParameterx(GLenum pname, GLfixed param) {
    LOAD_GLES(glPointParameterx);
#ifndef direct_glPointParameterx
    PUSH_IF_COMPILING(glPointParameterx)
#endif
    gles_glPointParameterx(pname, param);

}
#endif
#if !defined(skip_glPointParameterxv) || defined(DISABLE_SKIP)
void glPointParameterxv(GLenum pname, const GLfixed * params) {
    LOAD_GLES(glPointParameterxv);
#ifndef direct_glPointParameterxv
    PUSH_IF_COMPILING(glPointParameterxv)
#endif
    gles_glPointParameterxv(pname, params);

}
#endif
#if !defined(skip_glPointSize) || defined(DISABLE_SKIP)
void glPointSize(GLfloat size) {
    LOAD_GLES(glPointSize);
#ifndef direct_glPointSize
    PUSH_IF_COMPILING(glPointSize)
#endif
    gles_glPointSize(size);

}
#endif
#if !defined(skip_glPointSizePointerOES) || defined(DISABLE_SKIP)
void glPointSizePointerOES(GLenum type, GLsizei stride, const GLvoid * pointer) {
    LOAD_GLES(glPointSizePointerOES);
#ifndef direct_glPointSizePointerOES
    PUSH_IF_COMPILING(glPointSizePointerOES)
#endif
    gles_glPointSizePointerOES(type, stride, pointer);

}
#endif
#if !defined(skip_glPointSizex) || defined(DISABLE_SKIP)
void glPointSizex(GLfixed size) {
    LOAD_GLES(glPointSizex);
#ifndef direct_glPointSizex
    PUSH_IF_COMPILING(glPointSizex)
#endif
    gles_glPointSizex(size);

}
#endif
#if !defined(skip_glPolygonOffset) || defined(DISABLE_SKIP)
void glPolygonOffset(GLfloat factor, GLfloat units) {
    LOAD_GLES(glPolygonOffset);
#ifndef direct_glPolygonOffset
    PUSH_IF_COMPILING(glPolygonOffset)
#endif
    gles_glPolygonOffset(factor, units);

}
#endif
#if !defined(skip_glPolygonOffsetx) || defined(DISABLE_SKIP)
void glPolygonOffsetx(GLfixed factor, GLfixed units) {
    LOAD_GLES(glPolygonOffsetx);
#ifndef direct_glPolygonOffsetx
    PUSH_IF_COMPILING(glPolygonOffsetx)
#endif
    gles_glPolygonOffsetx(factor, units);

}
#endif
#if !defined(skip_glPopMatrix) || defined(DISABLE_SKIP)
void glPopMatrix() {
    LOAD_GLES(glPopMatrix);
#ifndef direct_glPopMatrix
    PUSH_IF_COMPILING(glPopMatrix)
#endif
    gles_glPopMatrix();

}
#endif
#if !defined(skip_glPushMatrix) || defined(DISABLE_SKIP)
void glPushMatrix() {
    LOAD_GLES(glPushMatrix);
#ifndef direct_glPushMatrix
    PUSH_IF_COMPILING(glPushMatrix)
#endif
    gles_glPushMatrix();

}
#endif
#if !defined(skip_glReadPixels) || defined(DISABLE_SKIP)
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels) {
    LOAD_GLES(glReadPixels);
#ifndef direct_glReadPixels
    PUSH_IF_COMPILING(glReadPixels)
#endif
    gles_glReadPixels(x, y, width, height, format, type, pixels);

}
#endif
#if !defined(skip_glRotatef) || defined(DISABLE_SKIP)
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
    LOAD_GLES(glRotatef);
#ifndef direct_glRotatef
    PUSH_IF_COMPILING(glRotatef)
#endif
    gles_glRotatef(angle, x, y, z);

}
#endif
#if !defined(skip_glRotatex) || defined(DISABLE_SKIP)
void glRotatex(GLfixed angle, GLfixed x, GLfixed y, GLfixed z) {
    LOAD_GLES(glRotatex);
#ifndef direct_glRotatex
    PUSH_IF_COMPILING(glRotatex)
#endif
    gles_glRotatex(angle, x, y, z);

}
#endif
#if !defined(skip_glSampleCoverage) || defined(DISABLE_SKIP)
void glSampleCoverage(GLclampf value, GLboolean invert) {
    LOAD_GLES(glSampleCoverage);
#ifndef direct_glSampleCoverage
    PUSH_IF_COMPILING(glSampleCoverage)
#endif
    gles_glSampleCoverage(value, invert);

}
#endif
#if !defined(skip_glSampleCoveragex) || defined(DISABLE_SKIP)
void glSampleCoveragex(GLclampx value, GLboolean invert) {
    LOAD_GLES(glSampleCoveragex);
#ifndef direct_glSampleCoveragex
    PUSH_IF_COMPILING(glSampleCoveragex)
#endif
    gles_glSampleCoveragex(value, invert);

}
#endif
#if !defined(skip_glScalef) || defined(DISABLE_SKIP)
void glScalef(GLfloat x, GLfloat y, GLfloat z) {
    LOAD_GLES(glScalef);
#ifndef direct_glScalef
    PUSH_IF_COMPILING(glScalef)
#endif
    gles_glScalef(x, y, z);

}
#endif
#if !defined(skip_glScalex) || defined(DISABLE_SKIP)
void glScalex(GLfixed x, GLfixed y, GLfixed z) {
    LOAD_GLES(glScalex);
#ifndef direct_glScalex
    PUSH_IF_COMPILING(glScalex)
#endif
    gles_glScalex(x, y, z);

}
#endif
#if !defined(skip_glScissor) || defined(DISABLE_SKIP)
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {
    LOAD_GLES(glScissor);
#ifndef direct_glScissor
    PUSH_IF_COMPILING(glScissor)
#endif
    gles_glScissor(x, y, width, height);

}
#endif
#if !defined(skip_glShadeModel) || defined(DISABLE_SKIP)
void glShadeModel(GLenum mode) {
    LOAD_GLES(glShadeModel);
#ifndef direct_glShadeModel
    PUSH_IF_COMPILING(glShadeModel)
#endif
    gles_glShadeModel(mode);

}
#endif
#if !defined(skip_glStencilFunc) || defined(DISABLE_SKIP)
void glStencilFunc(GLenum func, GLint ref, GLuint mask) {
    LOAD_GLES(glStencilFunc);
#ifndef direct_glStencilFunc
    PUSH_IF_COMPILING(glStencilFunc)
#endif
    gles_glStencilFunc(func, ref, mask);

}
#endif
#if !defined(skip_glStencilMask) || defined(DISABLE_SKIP)
void glStencilMask(GLuint mask) {
    LOAD_GLES(glStencilMask);
#ifndef direct_glStencilMask
    PUSH_IF_COMPILING(glStencilMask)
#endif
    gles_glStencilMask(mask);

}
#endif
#if !defined(skip_glStencilOp) || defined(DISABLE_SKIP)
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
    LOAD_GLES(glStencilOp);
#ifndef direct_glStencilOp
    PUSH_IF_COMPILING(glStencilOp)
#endif
    gles_glStencilOp(fail, zfail, zpass);

}
#endif
#if !defined(skip_glTexCoordPointer) || defined(DISABLE_SKIP)
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    LOAD_GLES(glTexCoordPointer);
#ifndef direct_glTexCoordPointer
    PUSH_IF_COMPILING(glTexCoordPointer)
#endif
    gles_glTexCoordPointer(size, type, stride, pointer);

}
#endif
#if !defined(skip_glTexEnvf) || defined(DISABLE_SKIP)
void glTexEnvf(GLenum target, GLenum pname, GLfloat param) {
    LOAD_GLES(glTexEnvf);
#ifndef direct_glTexEnvf
    PUSH_IF_COMPILING(glTexEnvf)
#endif
    gles_glTexEnvf(target, pname, param);

}
#endif
#if !defined(skip_glTexEnvfv) || defined(DISABLE_SKIP)
void glTexEnvfv(GLenum target, GLenum pname, const GLfloat * params) {
    LOAD_GLES(glTexEnvfv);
#ifndef direct_glTexEnvfv
    PUSH_IF_COMPILING(glTexEnvfv)
#endif
    gles_glTexEnvfv(target, pname, params);

}
#endif
#if !defined(skip_glTexEnvi) || defined(DISABLE_SKIP)
void glTexEnvi(GLenum target, GLenum pname, GLint param) {
    LOAD_GLES(glTexEnvi);
#ifndef direct_glTexEnvi
    PUSH_IF_COMPILING(glTexEnvi)
#endif
    gles_glTexEnvi(target, pname, param);

}
#endif
#if !defined(skip_glTexEnviv) || defined(DISABLE_SKIP)
void glTexEnviv(GLenum target, GLenum pname, const GLint * params) {
    LOAD_GLES(glTexEnviv);
#ifndef direct_glTexEnviv
    PUSH_IF_COMPILING(glTexEnviv)
#endif
    gles_glTexEnviv(target, pname, params);

}
#endif
#if !defined(skip_glTexEnvx) || defined(DISABLE_SKIP)
void glTexEnvx(GLenum target, GLenum pname, GLfixed param) {
    LOAD_GLES(glTexEnvx);
#ifndef direct_glTexEnvx
    PUSH_IF_COMPILING(glTexEnvx)
#endif
    gles_glTexEnvx(target, pname, param);

}
#endif
#if !defined(skip_glTexEnvxv) || defined(DISABLE_SKIP)
void glTexEnvxv(GLenum target, GLenum pname, const GLfixed * params) {
    LOAD_GLES(glTexEnvxv);
#ifndef direct_glTexEnvxv
    PUSH_IF_COMPILING(glTexEnvxv)
#endif
    gles_glTexEnvxv(target, pname, params);

}
#endif
#if !defined(skip_glTexImage2D) || defined(DISABLE_SKIP)
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels) {
    LOAD_GLES(glTexImage2D);
#ifndef direct_glTexImage2D
    PUSH_IF_COMPILING(glTexImage2D)
#endif
    gles_glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);

}
#endif
#if !defined(skip_glTexParameterf) || defined(DISABLE_SKIP)
void glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
    LOAD_GLES(glTexParameterf);
#ifndef direct_glTexParameterf
    PUSH_IF_COMPILING(glTexParameterf)
#endif
    gles_glTexParameterf(target, pname, param);

}
#endif
#if !defined(skip_glTexParameterfv) || defined(DISABLE_SKIP)
void glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    LOAD_GLES(glTexParameterfv);
#ifndef direct_glTexParameterfv
    PUSH_IF_COMPILING(glTexParameterfv)
#endif
    gles_glTexParameterfv(target, pname, params);

}
#endif
#if !defined(skip_glTexParameteri) || defined(DISABLE_SKIP)
void glTexParameteri(GLenum target, GLenum pname, GLint param) {
    LOAD_GLES(glTexParameteri);
#ifndef direct_glTexParameteri
    PUSH_IF_COMPILING(glTexParameteri)
#endif
    gles_glTexParameteri(target, pname, param);

}
#endif
#if !defined(skip_glTexParameteriv) || defined(DISABLE_SKIP)
void glTexParameteriv(GLenum target, GLenum pname, const GLint * params) {
    LOAD_GLES(glTexParameteriv);
#ifndef direct_glTexParameteriv
    PUSH_IF_COMPILING(glTexParameteriv)
#endif
    gles_glTexParameteriv(target, pname, params);

}
#endif
#if !defined(skip_glTexParameterx) || defined(DISABLE_SKIP)
void glTexParameterx(GLenum target, GLenum pname, GLfixed param) {
    LOAD_GLES(glTexParameterx);
#ifndef direct_glTexParameterx
    PUSH_IF_COMPILING(glTexParameterx)
#endif
    gles_glTexParameterx(target, pname, param);

}
#endif
#if !defined(skip_glTexParameterxv) || defined(DISABLE_SKIP)
void glTexParameterxv(GLenum target, GLenum pname, const GLfixed * params) {
    LOAD_GLES(glTexParameterxv);
#ifndef direct_glTexParameterxv
    PUSH_IF_COMPILING(glTexParameterxv)
#endif
    gles_glTexParameterxv(target, pname, params);

}
#endif
#if !defined(skip_glTexSubImage2D) || defined(DISABLE_SKIP)
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels) {
    LOAD_GLES(glTexSubImage2D);
#ifndef direct_glTexSubImage2D
    PUSH_IF_COMPILING(glTexSubImage2D)
#endif
    gles_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);

}
#endif
#if !defined(skip_glTranslatef) || defined(DISABLE_SKIP)
void glTranslatef(GLfloat x, GLfloat y, GLfloat z) {
    LOAD_GLES(glTranslatef);
#ifndef direct_glTranslatef
    PUSH_IF_COMPILING(glTranslatef)
#endif
    gles_glTranslatef(x, y, z);

}
#endif
#if !defined(skip_glTranslatex) || defined(DISABLE_SKIP)
void glTranslatex(GLfixed x, GLfixed y, GLfixed z) {
    LOAD_GLES(glTranslatex);
#ifndef direct_glTranslatex
    PUSH_IF_COMPILING(glTranslatex)
#endif
    gles_glTranslatex(x, y, z);

}
#endif
#if !defined(skip_glVertexPointer) || defined(DISABLE_SKIP)
void glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    LOAD_GLES(glVertexPointer);
#ifndef direct_glVertexPointer
    PUSH_IF_COMPILING(glVertexPointer)
#endif
    gles_glVertexPointer(size, type, stride, pointer);

}
#endif
#if !defined(skip_glViewport) || defined(DISABLE_SKIP)
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
    LOAD_GLES(glViewport);
#ifndef direct_glViewport
    PUSH_IF_COMPILING(glViewport)
#endif
    gles_glViewport(x, y, width, height);

}
#endif
#endif
