#ifndef USE_ES2
#include "gles.h"

void glPackedCall(const UnknownCall *packed) {
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
#ifndef skip_glActiveTexture
void glActiveTexture(GLenum texture) {
    LOAD_GLES(void, glActiveTexture, GLenum texture);
#ifndef direct_glActiveTexture
    if (state.list.compiling) {
        push_glActiveTexture(texture);
    } else {
#endif
        gles_glActiveTexture(texture);

#ifndef direct_glActiveTexture
    }
#endif
}
#endif
#ifndef skip_glAlphaFunc
void glAlphaFunc(GLenum func, GLclampf ref) {
    LOAD_GLES(void, glAlphaFunc, GLenum func, GLclampf ref);
#ifndef direct_glAlphaFunc
    if (state.list.compiling) {
        push_glAlphaFunc(func, ref);
    } else {
#endif
        gles_glAlphaFunc(func, ref);

#ifndef direct_glAlphaFunc
    }
#endif
}
#endif
#ifndef skip_glAlphaFuncx
void glAlphaFuncx(GLenum func, GLclampx ref) {
    LOAD_GLES(void, glAlphaFuncx, GLenum func, GLclampx ref);
#ifndef direct_glAlphaFuncx
    if (state.list.compiling) {
        push_glAlphaFuncx(func, ref);
    } else {
#endif
        gles_glAlphaFuncx(func, ref);

#ifndef direct_glAlphaFuncx
    }
#endif
}
#endif
#ifndef skip_glBindBuffer
void glBindBuffer(GLenum target, GLuint buffer) {
    LOAD_GLES(void, glBindBuffer, GLenum target, GLuint buffer);
#ifndef direct_glBindBuffer
    if (state.list.compiling) {
        push_glBindBuffer(target, buffer);
    } else {
#endif
        gles_glBindBuffer(target, buffer);

#ifndef direct_glBindBuffer
    }
#endif
}
#endif
#ifndef skip_glBindTexture
void glBindTexture(GLenum target, GLuint texture) {
    LOAD_GLES(void, glBindTexture, GLenum target, GLuint texture);
#ifndef direct_glBindTexture
    if (state.list.compiling) {
        push_glBindTexture(target, texture);
    } else {
#endif
        gles_glBindTexture(target, texture);

#ifndef direct_glBindTexture
    }
#endif
}
#endif
#ifndef skip_glBlendFunc
void glBlendFunc(GLenum sfactor, GLenum dfactor) {
    LOAD_GLES(void, glBlendFunc, GLenum sfactor, GLenum dfactor);
#ifndef direct_glBlendFunc
    if (state.list.compiling) {
        push_glBlendFunc(sfactor, dfactor);
    } else {
#endif
        gles_glBlendFunc(sfactor, dfactor);

#ifndef direct_glBlendFunc
    }
#endif
}
#endif
#ifndef skip_glBufferData
void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage) {
    LOAD_GLES(void, glBufferData, GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage);
#ifndef direct_glBufferData
    if (state.list.compiling) {
        push_glBufferData(target, size, data, usage);
    } else {
#endif
        gles_glBufferData(target, size, data, usage);

#ifndef direct_glBufferData
    }
#endif
}
#endif
#ifndef skip_glBufferSubData
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data) {
    LOAD_GLES(void, glBufferSubData, GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data);
#ifndef direct_glBufferSubData
    if (state.list.compiling) {
        push_glBufferSubData(target, offset, size, data);
    } else {
#endif
        gles_glBufferSubData(target, offset, size, data);

#ifndef direct_glBufferSubData
    }
#endif
}
#endif
#ifndef skip_glClear
void glClear(GLbitfield mask) {
    LOAD_GLES(void, glClear, GLbitfield mask);
#ifndef direct_glClear
    if (state.list.compiling) {
        push_glClear(mask);
    } else {
#endif
        gles_glClear(mask);

#ifndef direct_glClear
    }
#endif
}
#endif
#ifndef skip_glClearColor
void glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
    LOAD_GLES(void, glClearColor, GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
#ifndef direct_glClearColor
    if (state.list.compiling) {
        push_glClearColor(red, green, blue, alpha);
    } else {
#endif
        gles_glClearColor(red, green, blue, alpha);

#ifndef direct_glClearColor
    }
#endif
}
#endif
#ifndef skip_glClearColorx
void glClearColorx(GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha) {
    LOAD_GLES(void, glClearColorx, GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha);
#ifndef direct_glClearColorx
    if (state.list.compiling) {
        push_glClearColorx(red, green, blue, alpha);
    } else {
#endif
        gles_glClearColorx(red, green, blue, alpha);

#ifndef direct_glClearColorx
    }
#endif
}
#endif
#ifndef skip_glClearDepthf
void glClearDepthf(GLclampf depth) {
    LOAD_GLES(void, glClearDepthf, GLclampf depth);
#ifndef direct_glClearDepthf
    if (state.list.compiling) {
        push_glClearDepthf(depth);
    } else {
#endif
        gles_glClearDepthf(depth);

#ifndef direct_glClearDepthf
    }
#endif
}
#endif
#ifndef skip_glClearDepthx
void glClearDepthx(GLclampx depth) {
    LOAD_GLES(void, glClearDepthx, GLclampx depth);
#ifndef direct_glClearDepthx
    if (state.list.compiling) {
        push_glClearDepthx(depth);
    } else {
#endif
        gles_glClearDepthx(depth);

#ifndef direct_glClearDepthx
    }
#endif
}
#endif
#ifndef skip_glClearStencil
void glClearStencil(GLint s) {
    LOAD_GLES(void, glClearStencil, GLint s);
#ifndef direct_glClearStencil
    if (state.list.compiling) {
        push_glClearStencil(s);
    } else {
#endif
        gles_glClearStencil(s);

#ifndef direct_glClearStencil
    }
#endif
}
#endif
#ifndef skip_glClientActiveTexture
void glClientActiveTexture(GLenum texture) {
    LOAD_GLES(void, glClientActiveTexture, GLenum texture);
#ifndef direct_glClientActiveTexture
    if (state.list.compiling) {
        push_glClientActiveTexture(texture);
    } else {
#endif
        gles_glClientActiveTexture(texture);

#ifndef direct_glClientActiveTexture
    }
#endif
}
#endif
#ifndef skip_glClipPlanef
void glClipPlanef(GLenum plane, const GLfloat * equation) {
    LOAD_GLES(void, glClipPlanef, GLenum plane, const GLfloat * equation);
#ifndef direct_glClipPlanef
    if (state.list.compiling) {
        push_glClipPlanef(plane, equation);
    } else {
#endif
        gles_glClipPlanef(plane, equation);

#ifndef direct_glClipPlanef
    }
#endif
}
#endif
#ifndef skip_glClipPlanex
void glClipPlanex(GLenum plane, const GLfixed * equation) {
    LOAD_GLES(void, glClipPlanex, GLenum plane, const GLfixed * equation);
#ifndef direct_glClipPlanex
    if (state.list.compiling) {
        push_glClipPlanex(plane, equation);
    } else {
#endif
        gles_glClipPlanex(plane, equation);

#ifndef direct_glClipPlanex
    }
#endif
}
#endif
#ifndef skip_glColor4f
void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    LOAD_GLES(void, glColor4f, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#ifndef direct_glColor4f
    if (state.list.compiling) {
        push_glColor4f(red, green, blue, alpha);
    } else {
#endif
        gles_glColor4f(red, green, blue, alpha);

#ifndef direct_glColor4f
    }
#endif
}
#endif
#ifndef skip_glColor4ub
void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {
    LOAD_GLES(void, glColor4ub, GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
#ifndef direct_glColor4ub
    if (state.list.compiling) {
        push_glColor4ub(red, green, blue, alpha);
    } else {
#endif
        gles_glColor4ub(red, green, blue, alpha);

#ifndef direct_glColor4ub
    }
#endif
}
#endif
#ifndef skip_glColor4x
void glColor4x(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
    LOAD_GLES(void, glColor4x, GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
#ifndef direct_glColor4x
    if (state.list.compiling) {
        push_glColor4x(red, green, blue, alpha);
    } else {
#endif
        gles_glColor4x(red, green, blue, alpha);

#ifndef direct_glColor4x
    }
#endif
}
#endif
#ifndef skip_glColorMask
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
    LOAD_GLES(void, glColorMask, GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
#ifndef direct_glColorMask
    if (state.list.compiling) {
        push_glColorMask(red, green, blue, alpha);
    } else {
#endif
        gles_glColorMask(red, green, blue, alpha);

#ifndef direct_glColorMask
    }
#endif
}
#endif
#ifndef skip_glColorPointer
void glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    LOAD_GLES(void, glColorPointer, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
#ifndef direct_glColorPointer
    if (state.list.compiling) {
        push_glColorPointer(size, type, stride, pointer);
    } else {
#endif
        gles_glColorPointer(size, type, stride, pointer);

#ifndef direct_glColorPointer
    }
#endif
}
#endif
#ifndef skip_glCompressedTexImage2D
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data) {
    LOAD_GLES(void, glCompressedTexImage2D, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data);
#ifndef direct_glCompressedTexImage2D
    if (state.list.compiling) {
        push_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
    } else {
#endif
        gles_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);

#ifndef direct_glCompressedTexImage2D
    }
#endif
}
#endif
#ifndef skip_glCompressedTexSubImage2D
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data) {
    LOAD_GLES(void, glCompressedTexSubImage2D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data);
#ifndef direct_glCompressedTexSubImage2D
    if (state.list.compiling) {
        push_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
    } else {
#endif
        gles_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);

#ifndef direct_glCompressedTexSubImage2D
    }
#endif
}
#endif
#ifndef skip_glCopyTexImage2D
void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    LOAD_GLES(void, glCopyTexImage2D, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
#ifndef direct_glCopyTexImage2D
    if (state.list.compiling) {
        push_glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
    } else {
#endif
        gles_glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);

#ifndef direct_glCopyTexImage2D
    }
#endif
}
#endif
#ifndef skip_glCopyTexSubImage2D
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    LOAD_GLES(void, glCopyTexSubImage2D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
#ifndef direct_glCopyTexSubImage2D
    if (state.list.compiling) {
        push_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
    } else {
#endif
        gles_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);

#ifndef direct_glCopyTexSubImage2D
    }
#endif
}
#endif
#ifndef skip_glCullFace
void glCullFace(GLenum mode) {
    LOAD_GLES(void, glCullFace, GLenum mode);
#ifndef direct_glCullFace
    if (state.list.compiling) {
        push_glCullFace(mode);
    } else {
#endif
        gles_glCullFace(mode);

#ifndef direct_glCullFace
    }
#endif
}
#endif
#ifndef skip_glDeleteBuffers
void glDeleteBuffers(GLsizei n, const GLuint * buffers) {
    LOAD_GLES(void, glDeleteBuffers, GLsizei n, const GLuint * buffers);
#ifndef direct_glDeleteBuffers
    if (state.list.compiling) {
        push_glDeleteBuffers(n, buffers);
    } else {
#endif
        gles_glDeleteBuffers(n, buffers);

#ifndef direct_glDeleteBuffers
    }
#endif
}
#endif
#ifndef skip_glDeleteTextures
void glDeleteTextures(GLsizei n, const GLuint * textures) {
    LOAD_GLES(void, glDeleteTextures, GLsizei n, const GLuint * textures);
#ifndef direct_glDeleteTextures
    if (state.list.compiling) {
        push_glDeleteTextures(n, textures);
    } else {
#endif
        gles_glDeleteTextures(n, textures);

#ifndef direct_glDeleteTextures
    }
#endif
}
#endif
#ifndef skip_glDepthFunc
void glDepthFunc(GLenum func) {
    LOAD_GLES(void, glDepthFunc, GLenum func);
#ifndef direct_glDepthFunc
    if (state.list.compiling) {
        push_glDepthFunc(func);
    } else {
#endif
        gles_glDepthFunc(func);

#ifndef direct_glDepthFunc
    }
#endif
}
#endif
#ifndef skip_glDepthMask
void glDepthMask(GLboolean flag) {
    LOAD_GLES(void, glDepthMask, GLboolean flag);
#ifndef direct_glDepthMask
    if (state.list.compiling) {
        push_glDepthMask(flag);
    } else {
#endif
        gles_glDepthMask(flag);

#ifndef direct_glDepthMask
    }
#endif
}
#endif
#ifndef skip_glDepthRangef
void glDepthRangef(GLclampf near, GLclampf far) {
    LOAD_GLES(void, glDepthRangef, GLclampf near, GLclampf far);
#ifndef direct_glDepthRangef
    if (state.list.compiling) {
        push_glDepthRangef(near, far);
    } else {
#endif
        gles_glDepthRangef(near, far);

#ifndef direct_glDepthRangef
    }
#endif
}
#endif
#ifndef skip_glDepthRangex
void glDepthRangex(GLclampx near, GLclampx far) {
    LOAD_GLES(void, glDepthRangex, GLclampx near, GLclampx far);
#ifndef direct_glDepthRangex
    if (state.list.compiling) {
        push_glDepthRangex(near, far);
    } else {
#endif
        gles_glDepthRangex(near, far);

#ifndef direct_glDepthRangex
    }
#endif
}
#endif
#ifndef skip_glDisable
void glDisable(GLenum cap) {
    LOAD_GLES(void, glDisable, GLenum cap);
#ifndef direct_glDisable
    if (state.list.compiling) {
        push_glDisable(cap);
    } else {
#endif
        gles_glDisable(cap);

#ifndef direct_glDisable
    }
#endif
}
#endif
#ifndef skip_glDisableClientState
void glDisableClientState(GLenum array) {
    LOAD_GLES(void, glDisableClientState, GLenum array);
#ifndef direct_glDisableClientState
    if (state.list.compiling) {
        push_glDisableClientState(array);
    } else {
#endif
        gles_glDisableClientState(array);

#ifndef direct_glDisableClientState
    }
#endif
}
#endif
#ifndef skip_glDrawArrays
void glDrawArrays(GLenum mode, GLint first, GLsizei count) {
    LOAD_GLES(void, glDrawArrays, GLenum mode, GLint first, GLsizei count);
#ifndef direct_glDrawArrays
    if (state.list.compiling) {
        push_glDrawArrays(mode, first, count);
    } else {
#endif
        gles_glDrawArrays(mode, first, count);

#ifndef direct_glDrawArrays
    }
#endif
}
#endif
#ifndef skip_glDrawElements
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices) {
    LOAD_GLES(void, glDrawElements, GLenum mode, GLsizei count, GLenum type, const GLvoid * indices);
#ifndef direct_glDrawElements
    if (state.list.compiling) {
        push_glDrawElements(mode, count, type, indices);
    } else {
#endif
        gles_glDrawElements(mode, count, type, indices);

#ifndef direct_glDrawElements
    }
#endif
}
#endif
#ifndef skip_glEnable
void glEnable(GLenum cap) {
    LOAD_GLES(void, glEnable, GLenum cap);
#ifndef direct_glEnable
    if (state.list.compiling) {
        push_glEnable(cap);
    } else {
#endif
        gles_glEnable(cap);

#ifndef direct_glEnable
    }
#endif
}
#endif
#ifndef skip_glEnableClientState
void glEnableClientState(GLenum array) {
    LOAD_GLES(void, glEnableClientState, GLenum array);
#ifndef direct_glEnableClientState
    if (state.list.compiling) {
        push_glEnableClientState(array);
    } else {
#endif
        gles_glEnableClientState(array);

#ifndef direct_glEnableClientState
    }
#endif
}
#endif
#ifndef skip_glFinish
void glFinish() {
    LOAD_GLES(void, glFinish);
#ifndef direct_glFinish
    if (state.list.compiling) {
        push_glFinish();
    } else {
#endif
        gles_glFinish();

#ifndef direct_glFinish
    }
#endif
}
#endif
#ifndef skip_glFlush
void glFlush() {
    LOAD_GLES(void, glFlush);
#ifndef direct_glFlush
    if (state.list.compiling) {
        push_glFlush();
    } else {
#endif
        gles_glFlush();

#ifndef direct_glFlush
    }
#endif
}
#endif
#ifndef skip_glFogf
void glFogf(GLenum pname, GLfloat param) {
    LOAD_GLES(void, glFogf, GLenum pname, GLfloat param);
#ifndef direct_glFogf
    if (state.list.compiling) {
        push_glFogf(pname, param);
    } else {
#endif
        gles_glFogf(pname, param);

#ifndef direct_glFogf
    }
#endif
}
#endif
#ifndef skip_glFogfv
void glFogfv(GLenum pname, const GLfloat * params) {
    LOAD_GLES(void, glFogfv, GLenum pname, const GLfloat * params);
#ifndef direct_glFogfv
    if (state.list.compiling) {
        push_glFogfv(pname, params);
    } else {
#endif
        gles_glFogfv(pname, params);

#ifndef direct_glFogfv
    }
#endif
}
#endif
#ifndef skip_glFogx
void glFogx(GLenum pname, GLfixed param) {
    LOAD_GLES(void, glFogx, GLenum pname, GLfixed param);
#ifndef direct_glFogx
    if (state.list.compiling) {
        push_glFogx(pname, param);
    } else {
#endif
        gles_glFogx(pname, param);

#ifndef direct_glFogx
    }
#endif
}
#endif
#ifndef skip_glFogxv
void glFogxv(GLenum pname, const GLfixed * params) {
    LOAD_GLES(void, glFogxv, GLenum pname, const GLfixed * params);
#ifndef direct_glFogxv
    if (state.list.compiling) {
        push_glFogxv(pname, params);
    } else {
#endif
        gles_glFogxv(pname, params);

#ifndef direct_glFogxv
    }
#endif
}
#endif
#ifndef skip_glFrontFace
void glFrontFace(GLenum mode) {
    LOAD_GLES(void, glFrontFace, GLenum mode);
#ifndef direct_glFrontFace
    if (state.list.compiling) {
        push_glFrontFace(mode);
    } else {
#endif
        gles_glFrontFace(mode);

#ifndef direct_glFrontFace
    }
#endif
}
#endif
#ifndef skip_glFrustumf
void glFrustumf(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far) {
    LOAD_GLES(void, glFrustumf, GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far);
#ifndef direct_glFrustumf
    if (state.list.compiling) {
        push_glFrustumf(left, right, bottom, top, near, far);
    } else {
#endif
        gles_glFrustumf(left, right, bottom, top, near, far);

#ifndef direct_glFrustumf
    }
#endif
}
#endif
#ifndef skip_glFrustumx
void glFrustumx(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far) {
    LOAD_GLES(void, glFrustumx, GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far);
#ifndef direct_glFrustumx
    if (state.list.compiling) {
        push_glFrustumx(left, right, bottom, top, near, far);
    } else {
#endif
        gles_glFrustumx(left, right, bottom, top, near, far);

#ifndef direct_glFrustumx
    }
#endif
}
#endif
#ifndef skip_glGenBuffers
void glGenBuffers(GLsizei n, GLuint * buffers) {
    LOAD_GLES(void, glGenBuffers, GLsizei n, GLuint * buffers);
#ifndef direct_glGenBuffers
    if (state.list.compiling) {
        push_glGenBuffers(n, buffers);
    } else {
#endif
        gles_glGenBuffers(n, buffers);

#ifndef direct_glGenBuffers
    }
#endif
}
#endif
#ifndef skip_glGenTextures
void glGenTextures(GLsizei n, GLuint * textures) {
    LOAD_GLES(void, glGenTextures, GLsizei n, GLuint * textures);
#ifndef direct_glGenTextures
    if (state.list.compiling) {
        push_glGenTextures(n, textures);
    } else {
#endif
        gles_glGenTextures(n, textures);

#ifndef direct_glGenTextures
    }
#endif
}
#endif
#ifndef skip_glGetBooleanv
void glGetBooleanv(GLenum pname, GLboolean * params) {
    LOAD_GLES(void, glGetBooleanv, GLenum pname, GLboolean * params);
#ifndef direct_glGetBooleanv
    if (state.list.compiling) {
        push_glGetBooleanv(pname, params);
    } else {
#endif
        gles_glGetBooleanv(pname, params);

#ifndef direct_glGetBooleanv
    }
#endif
}
#endif
#ifndef skip_glGetBufferParameteriv
void glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    LOAD_GLES(void, glGetBufferParameteriv, GLenum target, GLenum pname, GLint * params);
#ifndef direct_glGetBufferParameteriv
    if (state.list.compiling) {
        push_glGetBufferParameteriv(target, pname, params);
    } else {
#endif
        gles_glGetBufferParameteriv(target, pname, params);

#ifndef direct_glGetBufferParameteriv
    }
#endif
}
#endif
#ifndef skip_glGetClipPlanef
void glGetClipPlanef(GLenum plane, GLfloat * equation) {
    LOAD_GLES(void, glGetClipPlanef, GLenum plane, GLfloat * equation);
#ifndef direct_glGetClipPlanef
    if (state.list.compiling) {
        push_glGetClipPlanef(plane, equation);
    } else {
#endif
        gles_glGetClipPlanef(plane, equation);

#ifndef direct_glGetClipPlanef
    }
#endif
}
#endif
#ifndef skip_glGetClipPlanex
void glGetClipPlanex(GLenum plane, GLfixed * equation) {
    LOAD_GLES(void, glGetClipPlanex, GLenum plane, GLfixed * equation);
#ifndef direct_glGetClipPlanex
    if (state.list.compiling) {
        push_glGetClipPlanex(plane, equation);
    } else {
#endif
        gles_glGetClipPlanex(plane, equation);

#ifndef direct_glGetClipPlanex
    }
#endif
}
#endif
#ifndef skip_glGetError
GLenum glGetError() {
    LOAD_GLES(GLenum, glGetError);
#ifndef direct_glGetError
    if (state.list.compiling) {
        push_glGetError();
        return 0;
    } else {
#endif
        return gles_glGetError();

#ifndef direct_glGetError
    }
#endif
}
#endif
#ifndef skip_glGetFixedv
void glGetFixedv(GLenum pname, GLfixed * params) {
    LOAD_GLES(void, glGetFixedv, GLenum pname, GLfixed * params);
#ifndef direct_glGetFixedv
    if (state.list.compiling) {
        push_glGetFixedv(pname, params);
    } else {
#endif
        gles_glGetFixedv(pname, params);

#ifndef direct_glGetFixedv
    }
#endif
}
#endif
#ifndef skip_glGetFloatv
void glGetFloatv(GLenum pname, GLfloat * params) {
    LOAD_GLES(void, glGetFloatv, GLenum pname, GLfloat * params);
#ifndef direct_glGetFloatv
    if (state.list.compiling) {
        push_glGetFloatv(pname, params);
    } else {
#endif
        gles_glGetFloatv(pname, params);

#ifndef direct_glGetFloatv
    }
#endif
}
#endif
#ifndef skip_glGetIntegerv
void glGetIntegerv(GLenum pname, GLint * params) {
    LOAD_GLES(void, glGetIntegerv, GLenum pname, GLint * params);
#ifndef direct_glGetIntegerv
    if (state.list.compiling) {
        push_glGetIntegerv(pname, params);
    } else {
#endif
        gles_glGetIntegerv(pname, params);

#ifndef direct_glGetIntegerv
    }
#endif
}
#endif
#ifndef skip_glGetLightfv
void glGetLightfv(GLenum light, GLenum pname, GLfloat * params) {
    LOAD_GLES(void, glGetLightfv, GLenum light, GLenum pname, GLfloat * params);
#ifndef direct_glGetLightfv
    if (state.list.compiling) {
        push_glGetLightfv(light, pname, params);
    } else {
#endif
        gles_glGetLightfv(light, pname, params);

#ifndef direct_glGetLightfv
    }
#endif
}
#endif
#ifndef skip_glGetLightxv
void glGetLightxv(GLenum light, GLenum pname, GLfixed * params) {
    LOAD_GLES(void, glGetLightxv, GLenum light, GLenum pname, GLfixed * params);
#ifndef direct_glGetLightxv
    if (state.list.compiling) {
        push_glGetLightxv(light, pname, params);
    } else {
#endif
        gles_glGetLightxv(light, pname, params);

#ifndef direct_glGetLightxv
    }
#endif
}
#endif
#ifndef skip_glGetMaterialfv
void glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params) {
    LOAD_GLES(void, glGetMaterialfv, GLenum face, GLenum pname, GLfloat * params);
#ifndef direct_glGetMaterialfv
    if (state.list.compiling) {
        push_glGetMaterialfv(face, pname, params);
    } else {
#endif
        gles_glGetMaterialfv(face, pname, params);

#ifndef direct_glGetMaterialfv
    }
#endif
}
#endif
#ifndef skip_glGetMaterialxv
void glGetMaterialxv(GLenum face, GLenum pname, GLfixed * params) {
    LOAD_GLES(void, glGetMaterialxv, GLenum face, GLenum pname, GLfixed * params);
#ifndef direct_glGetMaterialxv
    if (state.list.compiling) {
        push_glGetMaterialxv(face, pname, params);
    } else {
#endif
        gles_glGetMaterialxv(face, pname, params);

#ifndef direct_glGetMaterialxv
    }
#endif
}
#endif
#ifndef skip_glGetPointerv
void glGetPointerv(GLenum pname, GLvoid ** params) {
    LOAD_GLES(void, glGetPointerv, GLenum pname, GLvoid ** params);
#ifndef direct_glGetPointerv
    if (state.list.compiling) {
        push_glGetPointerv(pname, params);
    } else {
#endif
        gles_glGetPointerv(pname, params);

#ifndef direct_glGetPointerv
    }
#endif
}
#endif
#ifndef skip_glGetString
const GLubyte * glGetString(GLenum name) {
    LOAD_GLES(const GLubyte *, glGetString, GLenum name);
#ifndef direct_glGetString
    if (state.list.compiling) {
        push_glGetString(name);
        return 0;
    } else {
#endif
        return gles_glGetString(name);

#ifndef direct_glGetString
    }
#endif
}
#endif
#ifndef skip_glGetTexEnvfv
void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params) {
    LOAD_GLES(void, glGetTexEnvfv, GLenum target, GLenum pname, GLfloat * params);
#ifndef direct_glGetTexEnvfv
    if (state.list.compiling) {
        push_glGetTexEnvfv(target, pname, params);
    } else {
#endif
        gles_glGetTexEnvfv(target, pname, params);

#ifndef direct_glGetTexEnvfv
    }
#endif
}
#endif
#ifndef skip_glGetTexEnviv
void glGetTexEnviv(GLenum target, GLenum pname, GLint * params) {
    LOAD_GLES(void, glGetTexEnviv, GLenum target, GLenum pname, GLint * params);
#ifndef direct_glGetTexEnviv
    if (state.list.compiling) {
        push_glGetTexEnviv(target, pname, params);
    } else {
#endif
        gles_glGetTexEnviv(target, pname, params);

#ifndef direct_glGetTexEnviv
    }
#endif
}
#endif
#ifndef skip_glGetTexEnvxv
void glGetTexEnvxv(GLenum target, GLenum pname, GLfixed * params) {
    LOAD_GLES(void, glGetTexEnvxv, GLenum target, GLenum pname, GLfixed * params);
#ifndef direct_glGetTexEnvxv
    if (state.list.compiling) {
        push_glGetTexEnvxv(target, pname, params);
    } else {
#endif
        gles_glGetTexEnvxv(target, pname, params);

#ifndef direct_glGetTexEnvxv
    }
#endif
}
#endif
#ifndef skip_glGetTexParameterfv
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    LOAD_GLES(void, glGetTexParameterfv, GLenum target, GLenum pname, GLfloat * params);
#ifndef direct_glGetTexParameterfv
    if (state.list.compiling) {
        push_glGetTexParameterfv(target, pname, params);
    } else {
#endif
        gles_glGetTexParameterfv(target, pname, params);

#ifndef direct_glGetTexParameterfv
    }
#endif
}
#endif
#ifndef skip_glGetTexParameteriv
void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params) {
    LOAD_GLES(void, glGetTexParameteriv, GLenum target, GLenum pname, GLint * params);
#ifndef direct_glGetTexParameteriv
    if (state.list.compiling) {
        push_glGetTexParameteriv(target, pname, params);
    } else {
#endif
        gles_glGetTexParameteriv(target, pname, params);

#ifndef direct_glGetTexParameteriv
    }
#endif
}
#endif
#ifndef skip_glGetTexParameterxv
void glGetTexParameterxv(GLenum target, GLenum pname, GLfixed * params) {
    LOAD_GLES(void, glGetTexParameterxv, GLenum target, GLenum pname, GLfixed * params);
#ifndef direct_glGetTexParameterxv
    if (state.list.compiling) {
        push_glGetTexParameterxv(target, pname, params);
    } else {
#endif
        gles_glGetTexParameterxv(target, pname, params);

#ifndef direct_glGetTexParameterxv
    }
#endif
}
#endif
#ifndef skip_glHint
void glHint(GLenum target, GLenum mode) {
    LOAD_GLES(void, glHint, GLenum target, GLenum mode);
#ifndef direct_glHint
    if (state.list.compiling) {
        push_glHint(target, mode);
    } else {
#endif
        gles_glHint(target, mode);

#ifndef direct_glHint
    }
#endif
}
#endif
#ifndef skip_glIsBuffer
GLboolean glIsBuffer(GLuint buffer) {
    LOAD_GLES(GLboolean, glIsBuffer, GLuint buffer);
#ifndef direct_glIsBuffer
    if (state.list.compiling) {
        push_glIsBuffer(buffer);
        return 0;
    } else {
#endif
        return gles_glIsBuffer(buffer);

#ifndef direct_glIsBuffer
    }
#endif
}
#endif
#ifndef skip_glIsEnabled
GLboolean glIsEnabled(GLenum cap) {
    LOAD_GLES(GLboolean, glIsEnabled, GLenum cap);
#ifndef direct_glIsEnabled
    if (state.list.compiling) {
        push_glIsEnabled(cap);
        return 0;
    } else {
#endif
        return gles_glIsEnabled(cap);

#ifndef direct_glIsEnabled
    }
#endif
}
#endif
#ifndef skip_glIsTexture
GLboolean glIsTexture(GLuint texture) {
    LOAD_GLES(GLboolean, glIsTexture, GLuint texture);
#ifndef direct_glIsTexture
    if (state.list.compiling) {
        push_glIsTexture(texture);
        return 0;
    } else {
#endif
        return gles_glIsTexture(texture);

#ifndef direct_glIsTexture
    }
#endif
}
#endif
#ifndef skip_glLightModelf
void glLightModelf(GLenum pname, GLfloat param) {
    LOAD_GLES(void, glLightModelf, GLenum pname, GLfloat param);
#ifndef direct_glLightModelf
    if (state.list.compiling) {
        push_glLightModelf(pname, param);
    } else {
#endif
        gles_glLightModelf(pname, param);

#ifndef direct_glLightModelf
    }
#endif
}
#endif
#ifndef skip_glLightModelfv
void glLightModelfv(GLenum pname, const GLfloat * params) {
    LOAD_GLES(void, glLightModelfv, GLenum pname, const GLfloat * params);
#ifndef direct_glLightModelfv
    if (state.list.compiling) {
        push_glLightModelfv(pname, params);
    } else {
#endif
        gles_glLightModelfv(pname, params);

#ifndef direct_glLightModelfv
    }
#endif
}
#endif
#ifndef skip_glLightModelx
void glLightModelx(GLenum pname, GLfixed param) {
    LOAD_GLES(void, glLightModelx, GLenum pname, GLfixed param);
#ifndef direct_glLightModelx
    if (state.list.compiling) {
        push_glLightModelx(pname, param);
    } else {
#endif
        gles_glLightModelx(pname, param);

#ifndef direct_glLightModelx
    }
#endif
}
#endif
#ifndef skip_glLightModelxv
void glLightModelxv(GLenum pname, const GLfixed * params) {
    LOAD_GLES(void, glLightModelxv, GLenum pname, const GLfixed * params);
#ifndef direct_glLightModelxv
    if (state.list.compiling) {
        push_glLightModelxv(pname, params);
    } else {
#endif
        gles_glLightModelxv(pname, params);

#ifndef direct_glLightModelxv
    }
#endif
}
#endif
#ifndef skip_glLightf
void glLightf(GLenum light, GLenum pname, GLfloat param) {
    LOAD_GLES(void, glLightf, GLenum light, GLenum pname, GLfloat param);
#ifndef direct_glLightf
    if (state.list.compiling) {
        push_glLightf(light, pname, param);
    } else {
#endif
        gles_glLightf(light, pname, param);

#ifndef direct_glLightf
    }
#endif
}
#endif
#ifndef skip_glLightfv
void glLightfv(GLenum light, GLenum pname, const GLfloat * params) {
    LOAD_GLES(void, glLightfv, GLenum light, GLenum pname, const GLfloat * params);
#ifndef direct_glLightfv
    if (state.list.compiling) {
        push_glLightfv(light, pname, params);
    } else {
#endif
        gles_glLightfv(light, pname, params);

#ifndef direct_glLightfv
    }
#endif
}
#endif
#ifndef skip_glLightx
void glLightx(GLenum light, GLenum pname, GLfixed param) {
    LOAD_GLES(void, glLightx, GLenum light, GLenum pname, GLfixed param);
#ifndef direct_glLightx
    if (state.list.compiling) {
        push_glLightx(light, pname, param);
    } else {
#endif
        gles_glLightx(light, pname, param);

#ifndef direct_glLightx
    }
#endif
}
#endif
#ifndef skip_glLightxv
void glLightxv(GLenum light, GLenum pname, const GLfixed * params) {
    LOAD_GLES(void, glLightxv, GLenum light, GLenum pname, const GLfixed * params);
#ifndef direct_glLightxv
    if (state.list.compiling) {
        push_glLightxv(light, pname, params);
    } else {
#endif
        gles_glLightxv(light, pname, params);

#ifndef direct_glLightxv
    }
#endif
}
#endif
#ifndef skip_glLineWidth
void glLineWidth(GLfloat width) {
    LOAD_GLES(void, glLineWidth, GLfloat width);
#ifndef direct_glLineWidth
    if (state.list.compiling) {
        push_glLineWidth(width);
    } else {
#endif
        gles_glLineWidth(width);

#ifndef direct_glLineWidth
    }
#endif
}
#endif
#ifndef skip_glLineWidthx
void glLineWidthx(GLfixed width) {
    LOAD_GLES(void, glLineWidthx, GLfixed width);
#ifndef direct_glLineWidthx
    if (state.list.compiling) {
        push_glLineWidthx(width);
    } else {
#endif
        gles_glLineWidthx(width);

#ifndef direct_glLineWidthx
    }
#endif
}
#endif
#ifndef skip_glLoadIdentity
void glLoadIdentity() {
    LOAD_GLES(void, glLoadIdentity);
#ifndef direct_glLoadIdentity
    if (state.list.compiling) {
        push_glLoadIdentity();
    } else {
#endif
        gles_glLoadIdentity();

#ifndef direct_glLoadIdentity
    }
#endif
}
#endif
#ifndef skip_glLoadMatrixf
void glLoadMatrixf(const GLfloat * m) {
    LOAD_GLES(void, glLoadMatrixf, const GLfloat * m);
#ifndef direct_glLoadMatrixf
    if (state.list.compiling) {
        push_glLoadMatrixf(m);
    } else {
#endif
        gles_glLoadMatrixf(m);

#ifndef direct_glLoadMatrixf
    }
#endif
}
#endif
#ifndef skip_glLoadMatrixx
void glLoadMatrixx(const GLfixed * m) {
    LOAD_GLES(void, glLoadMatrixx, const GLfixed * m);
#ifndef direct_glLoadMatrixx
    if (state.list.compiling) {
        push_glLoadMatrixx(m);
    } else {
#endif
        gles_glLoadMatrixx(m);

#ifndef direct_glLoadMatrixx
    }
#endif
}
#endif
#ifndef skip_glLogicOp
void glLogicOp(GLenum opcode) {
    LOAD_GLES(void, glLogicOp, GLenum opcode);
#ifndef direct_glLogicOp
    if (state.list.compiling) {
        push_glLogicOp(opcode);
    } else {
#endif
        gles_glLogicOp(opcode);

#ifndef direct_glLogicOp
    }
#endif
}
#endif
#ifndef skip_glMaterialf
void glMaterialf(GLenum face, GLenum pname, GLfloat param) {
    LOAD_GLES(void, glMaterialf, GLenum face, GLenum pname, GLfloat param);
#ifndef direct_glMaterialf
    if (state.list.compiling) {
        push_glMaterialf(face, pname, param);
    } else {
#endif
        gles_glMaterialf(face, pname, param);

#ifndef direct_glMaterialf
    }
#endif
}
#endif
#ifndef skip_glMaterialfv
void glMaterialfv(GLenum face, GLenum pname, const GLfloat * params) {
    LOAD_GLES(void, glMaterialfv, GLenum face, GLenum pname, const GLfloat * params);
#ifndef direct_glMaterialfv
    if (state.list.compiling) {
        push_glMaterialfv(face, pname, params);
    } else {
#endif
        gles_glMaterialfv(face, pname, params);

#ifndef direct_glMaterialfv
    }
#endif
}
#endif
#ifndef skip_glMaterialx
void glMaterialx(GLenum face, GLenum pname, GLfixed param) {
    LOAD_GLES(void, glMaterialx, GLenum face, GLenum pname, GLfixed param);
#ifndef direct_glMaterialx
    if (state.list.compiling) {
        push_glMaterialx(face, pname, param);
    } else {
#endif
        gles_glMaterialx(face, pname, param);

#ifndef direct_glMaterialx
    }
#endif
}
#endif
#ifndef skip_glMaterialxv
void glMaterialxv(GLenum face, GLenum pname, const GLfixed * params) {
    LOAD_GLES(void, glMaterialxv, GLenum face, GLenum pname, const GLfixed * params);
#ifndef direct_glMaterialxv
    if (state.list.compiling) {
        push_glMaterialxv(face, pname, params);
    } else {
#endif
        gles_glMaterialxv(face, pname, params);

#ifndef direct_glMaterialxv
    }
#endif
}
#endif
#ifndef skip_glMatrixMode
void glMatrixMode(GLenum mode) {
    LOAD_GLES(void, glMatrixMode, GLenum mode);
#ifndef direct_glMatrixMode
    if (state.list.compiling) {
        push_glMatrixMode(mode);
    } else {
#endif
        gles_glMatrixMode(mode);

#ifndef direct_glMatrixMode
    }
#endif
}
#endif
#ifndef skip_glMultMatrixf
void glMultMatrixf(const GLfloat * m) {
    LOAD_GLES(void, glMultMatrixf, const GLfloat * m);
#ifndef direct_glMultMatrixf
    if (state.list.compiling) {
        push_glMultMatrixf(m);
    } else {
#endif
        gles_glMultMatrixf(m);

#ifndef direct_glMultMatrixf
    }
#endif
}
#endif
#ifndef skip_glMultMatrixx
void glMultMatrixx(const GLfixed * m) {
    LOAD_GLES(void, glMultMatrixx, const GLfixed * m);
#ifndef direct_glMultMatrixx
    if (state.list.compiling) {
        push_glMultMatrixx(m);
    } else {
#endif
        gles_glMultMatrixx(m);

#ifndef direct_glMultMatrixx
    }
#endif
}
#endif
#ifndef skip_glMultiTexCoord4f
void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    LOAD_GLES(void, glMultiTexCoord4f, GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
#ifndef direct_glMultiTexCoord4f
    if (state.list.compiling) {
        push_glMultiTexCoord4f(target, s, t, r, q);
    } else {
#endif
        gles_glMultiTexCoord4f(target, s, t, r, q);

#ifndef direct_glMultiTexCoord4f
    }
#endif
}
#endif
#ifndef skip_glMultiTexCoord4x
void glMultiTexCoord4x(GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q) {
    LOAD_GLES(void, glMultiTexCoord4x, GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q);
#ifndef direct_glMultiTexCoord4x
    if (state.list.compiling) {
        push_glMultiTexCoord4x(target, s, t, r, q);
    } else {
#endif
        gles_glMultiTexCoord4x(target, s, t, r, q);

#ifndef direct_glMultiTexCoord4x
    }
#endif
}
#endif
#ifndef skip_glNormal3f
void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {
    LOAD_GLES(void, glNormal3f, GLfloat nx, GLfloat ny, GLfloat nz);
#ifndef direct_glNormal3f
    if (state.list.compiling) {
        push_glNormal3f(nx, ny, nz);
    } else {
#endif
        gles_glNormal3f(nx, ny, nz);

#ifndef direct_glNormal3f
    }
#endif
}
#endif
#ifndef skip_glNormal3x
void glNormal3x(GLfixed nx, GLfixed ny, GLfixed nz) {
    LOAD_GLES(void, glNormal3x, GLfixed nx, GLfixed ny, GLfixed nz);
#ifndef direct_glNormal3x
    if (state.list.compiling) {
        push_glNormal3x(nx, ny, nz);
    } else {
#endif
        gles_glNormal3x(nx, ny, nz);

#ifndef direct_glNormal3x
    }
#endif
}
#endif
#ifndef skip_glNormalPointer
void glNormalPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    LOAD_GLES(void, glNormalPointer, GLenum type, GLsizei stride, const GLvoid * pointer);
#ifndef direct_glNormalPointer
    if (state.list.compiling) {
        push_glNormalPointer(type, stride, pointer);
    } else {
#endif
        gles_glNormalPointer(type, stride, pointer);

#ifndef direct_glNormalPointer
    }
#endif
}
#endif
#ifndef skip_glOrthof
void glOrthof(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far) {
    LOAD_GLES(void, glOrthof, GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far);
#ifndef direct_glOrthof
    if (state.list.compiling) {
        push_glOrthof(left, right, bottom, top, near, far);
    } else {
#endif
        gles_glOrthof(left, right, bottom, top, near, far);

#ifndef direct_glOrthof
    }
#endif
}
#endif
#ifndef skip_glOrthox
void glOrthox(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far) {
    LOAD_GLES(void, glOrthox, GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far);
#ifndef direct_glOrthox
    if (state.list.compiling) {
        push_glOrthox(left, right, bottom, top, near, far);
    } else {
#endif
        gles_glOrthox(left, right, bottom, top, near, far);

#ifndef direct_glOrthox
    }
#endif
}
#endif
#ifndef skip_glPixelStorei
void glPixelStorei(GLenum pname, GLint param) {
    LOAD_GLES(void, glPixelStorei, GLenum pname, GLint param);
#ifndef direct_glPixelStorei
    if (state.list.compiling) {
        push_glPixelStorei(pname, param);
    } else {
#endif
        gles_glPixelStorei(pname, param);

#ifndef direct_glPixelStorei
    }
#endif
}
#endif
#ifndef skip_glPointParameterf
void glPointParameterf(GLenum pname, GLfloat param) {
    LOAD_GLES(void, glPointParameterf, GLenum pname, GLfloat param);
#ifndef direct_glPointParameterf
    if (state.list.compiling) {
        push_glPointParameterf(pname, param);
    } else {
#endif
        gles_glPointParameterf(pname, param);

#ifndef direct_glPointParameterf
    }
#endif
}
#endif
#ifndef skip_glPointParameterfv
void glPointParameterfv(GLenum pname, const GLfloat * params) {
    LOAD_GLES(void, glPointParameterfv, GLenum pname, const GLfloat * params);
#ifndef direct_glPointParameterfv
    if (state.list.compiling) {
        push_glPointParameterfv(pname, params);
    } else {
#endif
        gles_glPointParameterfv(pname, params);

#ifndef direct_glPointParameterfv
    }
#endif
}
#endif
#ifndef skip_glPointParameterx
void glPointParameterx(GLenum pname, GLfixed param) {
    LOAD_GLES(void, glPointParameterx, GLenum pname, GLfixed param);
#ifndef direct_glPointParameterx
    if (state.list.compiling) {
        push_glPointParameterx(pname, param);
    } else {
#endif
        gles_glPointParameterx(pname, param);

#ifndef direct_glPointParameterx
    }
#endif
}
#endif
#ifndef skip_glPointParameterxv
void glPointParameterxv(GLenum pname, const GLfixed * params) {
    LOAD_GLES(void, glPointParameterxv, GLenum pname, const GLfixed * params);
#ifndef direct_glPointParameterxv
    if (state.list.compiling) {
        push_glPointParameterxv(pname, params);
    } else {
#endif
        gles_glPointParameterxv(pname, params);

#ifndef direct_glPointParameterxv
    }
#endif
}
#endif
#ifndef skip_glPointSize
void glPointSize(GLfloat size) {
    LOAD_GLES(void, glPointSize, GLfloat size);
#ifndef direct_glPointSize
    if (state.list.compiling) {
        push_glPointSize(size);
    } else {
#endif
        gles_glPointSize(size);

#ifndef direct_glPointSize
    }
#endif
}
#endif
#ifndef skip_glPointSizePointerOES
void glPointSizePointerOES(GLenum type, GLsizei stride, const GLvoid * pointer) {
    LOAD_GLES(void, glPointSizePointerOES, GLenum type, GLsizei stride, const GLvoid * pointer);
#ifndef direct_glPointSizePointerOES
    if (state.list.compiling) {
        push_glPointSizePointerOES(type, stride, pointer);
    } else {
#endif
        gles_glPointSizePointerOES(type, stride, pointer);

#ifndef direct_glPointSizePointerOES
    }
#endif
}
#endif
#ifndef skip_glPointSizex
void glPointSizex(GLfixed size) {
    LOAD_GLES(void, glPointSizex, GLfixed size);
#ifndef direct_glPointSizex
    if (state.list.compiling) {
        push_glPointSizex(size);
    } else {
#endif
        gles_glPointSizex(size);

#ifndef direct_glPointSizex
    }
#endif
}
#endif
#ifndef skip_glPolygonOffset
void glPolygonOffset(GLfloat factor, GLfloat units) {
    LOAD_GLES(void, glPolygonOffset, GLfloat factor, GLfloat units);
#ifndef direct_glPolygonOffset
    if (state.list.compiling) {
        push_glPolygonOffset(factor, units);
    } else {
#endif
        gles_glPolygonOffset(factor, units);

#ifndef direct_glPolygonOffset
    }
#endif
}
#endif
#ifndef skip_glPolygonOffsetx
void glPolygonOffsetx(GLfixed factor, GLfixed units) {
    LOAD_GLES(void, glPolygonOffsetx, GLfixed factor, GLfixed units);
#ifndef direct_glPolygonOffsetx
    if (state.list.compiling) {
        push_glPolygonOffsetx(factor, units);
    } else {
#endif
        gles_glPolygonOffsetx(factor, units);

#ifndef direct_glPolygonOffsetx
    }
#endif
}
#endif
#ifndef skip_glPopMatrix
void glPopMatrix() {
    LOAD_GLES(void, glPopMatrix);
#ifndef direct_glPopMatrix
    if (state.list.compiling) {
        push_glPopMatrix();
    } else {
#endif
        gles_glPopMatrix();

#ifndef direct_glPopMatrix
    }
#endif
}
#endif
#ifndef skip_glPushMatrix
void glPushMatrix() {
    LOAD_GLES(void, glPushMatrix);
#ifndef direct_glPushMatrix
    if (state.list.compiling) {
        push_glPushMatrix();
    } else {
#endif
        gles_glPushMatrix();

#ifndef direct_glPushMatrix
    }
#endif
}
#endif
#ifndef skip_glReadPixels
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels) {
    LOAD_GLES(void, glReadPixels, GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels);
#ifndef direct_glReadPixels
    if (state.list.compiling) {
        push_glReadPixels(x, y, width, height, format, type, pixels);
    } else {
#endif
        gles_glReadPixels(x, y, width, height, format, type, pixels);

#ifndef direct_glReadPixels
    }
#endif
}
#endif
#ifndef skip_glRotatef
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
    LOAD_GLES(void, glRotatef, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
#ifndef direct_glRotatef
    if (state.list.compiling) {
        push_glRotatef(angle, x, y, z);
    } else {
#endif
        gles_glRotatef(angle, x, y, z);

#ifndef direct_glRotatef
    }
#endif
}
#endif
#ifndef skip_glRotatex
void glRotatex(GLfixed angle, GLfixed x, GLfixed y, GLfixed z) {
    LOAD_GLES(void, glRotatex, GLfixed angle, GLfixed x, GLfixed y, GLfixed z);
#ifndef direct_glRotatex
    if (state.list.compiling) {
        push_glRotatex(angle, x, y, z);
    } else {
#endif
        gles_glRotatex(angle, x, y, z);

#ifndef direct_glRotatex
    }
#endif
}
#endif
#ifndef skip_glSampleCoverage
void glSampleCoverage(GLclampf value, GLboolean invert) {
    LOAD_GLES(void, glSampleCoverage, GLclampf value, GLboolean invert);
#ifndef direct_glSampleCoverage
    if (state.list.compiling) {
        push_glSampleCoverage(value, invert);
    } else {
#endif
        gles_glSampleCoverage(value, invert);

#ifndef direct_glSampleCoverage
    }
#endif
}
#endif
#ifndef skip_glSampleCoveragex
void glSampleCoveragex(GLclampx value, GLboolean invert) {
    LOAD_GLES(void, glSampleCoveragex, GLclampx value, GLboolean invert);
#ifndef direct_glSampleCoveragex
    if (state.list.compiling) {
        push_glSampleCoveragex(value, invert);
    } else {
#endif
        gles_glSampleCoveragex(value, invert);

#ifndef direct_glSampleCoveragex
    }
#endif
}
#endif
#ifndef skip_glScalef
void glScalef(GLfloat x, GLfloat y, GLfloat z) {
    LOAD_GLES(void, glScalef, GLfloat x, GLfloat y, GLfloat z);
#ifndef direct_glScalef
    if (state.list.compiling) {
        push_glScalef(x, y, z);
    } else {
#endif
        gles_glScalef(x, y, z);

#ifndef direct_glScalef
    }
#endif
}
#endif
#ifndef skip_glScalex
void glScalex(GLfixed x, GLfixed y, GLfixed z) {
    LOAD_GLES(void, glScalex, GLfixed x, GLfixed y, GLfixed z);
#ifndef direct_glScalex
    if (state.list.compiling) {
        push_glScalex(x, y, z);
    } else {
#endif
        gles_glScalex(x, y, z);

#ifndef direct_glScalex
    }
#endif
}
#endif
#ifndef skip_glScissor
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {
    LOAD_GLES(void, glScissor, GLint x, GLint y, GLsizei width, GLsizei height);
#ifndef direct_glScissor
    if (state.list.compiling) {
        push_glScissor(x, y, width, height);
    } else {
#endif
        gles_glScissor(x, y, width, height);

#ifndef direct_glScissor
    }
#endif
}
#endif
#ifndef skip_glShadeModel
void glShadeModel(GLenum mode) {
    LOAD_GLES(void, glShadeModel, GLenum mode);
#ifndef direct_glShadeModel
    if (state.list.compiling) {
        push_glShadeModel(mode);
    } else {
#endif
        gles_glShadeModel(mode);

#ifndef direct_glShadeModel
    }
#endif
}
#endif
#ifndef skip_glStencilFunc
void glStencilFunc(GLenum func, GLint ref, GLuint mask) {
    LOAD_GLES(void, glStencilFunc, GLenum func, GLint ref, GLuint mask);
#ifndef direct_glStencilFunc
    if (state.list.compiling) {
        push_glStencilFunc(func, ref, mask);
    } else {
#endif
        gles_glStencilFunc(func, ref, mask);

#ifndef direct_glStencilFunc
    }
#endif
}
#endif
#ifndef skip_glStencilMask
void glStencilMask(GLuint mask) {
    LOAD_GLES(void, glStencilMask, GLuint mask);
#ifndef direct_glStencilMask
    if (state.list.compiling) {
        push_glStencilMask(mask);
    } else {
#endif
        gles_glStencilMask(mask);

#ifndef direct_glStencilMask
    }
#endif
}
#endif
#ifndef skip_glStencilOp
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
    LOAD_GLES(void, glStencilOp, GLenum fail, GLenum zfail, GLenum zpass);
#ifndef direct_glStencilOp
    if (state.list.compiling) {
        push_glStencilOp(fail, zfail, zpass);
    } else {
#endif
        gles_glStencilOp(fail, zfail, zpass);

#ifndef direct_glStencilOp
    }
#endif
}
#endif
#ifndef skip_glTexCoordPointer
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    LOAD_GLES(void, glTexCoordPointer, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
#ifndef direct_glTexCoordPointer
    if (state.list.compiling) {
        push_glTexCoordPointer(size, type, stride, pointer);
    } else {
#endif
        gles_glTexCoordPointer(size, type, stride, pointer);

#ifndef direct_glTexCoordPointer
    }
#endif
}
#endif
#ifndef skip_glTexEnvf
void glTexEnvf(GLenum target, GLenum pname, GLfloat param) {
    LOAD_GLES(void, glTexEnvf, GLenum target, GLenum pname, GLfloat param);
#ifndef direct_glTexEnvf
    if (state.list.compiling) {
        push_glTexEnvf(target, pname, param);
    } else {
#endif
        gles_glTexEnvf(target, pname, param);

#ifndef direct_glTexEnvf
    }
#endif
}
#endif
#ifndef skip_glTexEnvfv
void glTexEnvfv(GLenum target, GLenum pname, const GLfloat * params) {
    LOAD_GLES(void, glTexEnvfv, GLenum target, GLenum pname, const GLfloat * params);
#ifndef direct_glTexEnvfv
    if (state.list.compiling) {
        push_glTexEnvfv(target, pname, params);
    } else {
#endif
        gles_glTexEnvfv(target, pname, params);

#ifndef direct_glTexEnvfv
    }
#endif
}
#endif
#ifndef skip_glTexEnvi
void glTexEnvi(GLenum target, GLenum pname, GLint param) {
    LOAD_GLES(void, glTexEnvi, GLenum target, GLenum pname, GLint param);
#ifndef direct_glTexEnvi
    if (state.list.compiling) {
        push_glTexEnvi(target, pname, param);
    } else {
#endif
        gles_glTexEnvi(target, pname, param);

#ifndef direct_glTexEnvi
    }
#endif
}
#endif
#ifndef skip_glTexEnviv
void glTexEnviv(GLenum target, GLenum pname, const GLint * params) {
    LOAD_GLES(void, glTexEnviv, GLenum target, GLenum pname, const GLint * params);
#ifndef direct_glTexEnviv
    if (state.list.compiling) {
        push_glTexEnviv(target, pname, params);
    } else {
#endif
        gles_glTexEnviv(target, pname, params);

#ifndef direct_glTexEnviv
    }
#endif
}
#endif
#ifndef skip_glTexEnvx
void glTexEnvx(GLenum target, GLenum pname, GLfixed param) {
    LOAD_GLES(void, glTexEnvx, GLenum target, GLenum pname, GLfixed param);
#ifndef direct_glTexEnvx
    if (state.list.compiling) {
        push_glTexEnvx(target, pname, param);
    } else {
#endif
        gles_glTexEnvx(target, pname, param);

#ifndef direct_glTexEnvx
    }
#endif
}
#endif
#ifndef skip_glTexEnvxv
void glTexEnvxv(GLenum target, GLenum pname, const GLfixed * params) {
    LOAD_GLES(void, glTexEnvxv, GLenum target, GLenum pname, const GLfixed * params);
#ifndef direct_glTexEnvxv
    if (state.list.compiling) {
        push_glTexEnvxv(target, pname, params);
    } else {
#endif
        gles_glTexEnvxv(target, pname, params);

#ifndef direct_glTexEnvxv
    }
#endif
}
#endif
#ifndef skip_glTexImage2D
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels) {
    LOAD_GLES(void, glTexImage2D, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels);
#ifndef direct_glTexImage2D
    if (state.list.compiling) {
        push_glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
    } else {
#endif
        gles_glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);

#ifndef direct_glTexImage2D
    }
#endif
}
#endif
#ifndef skip_glTexParameterf
void glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
    LOAD_GLES(void, glTexParameterf, GLenum target, GLenum pname, GLfloat param);
#ifndef direct_glTexParameterf
    if (state.list.compiling) {
        push_glTexParameterf(target, pname, param);
    } else {
#endif
        gles_glTexParameterf(target, pname, param);

#ifndef direct_glTexParameterf
    }
#endif
}
#endif
#ifndef skip_glTexParameterfv
void glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    LOAD_GLES(void, glTexParameterfv, GLenum target, GLenum pname, const GLfloat * params);
#ifndef direct_glTexParameterfv
    if (state.list.compiling) {
        push_glTexParameterfv(target, pname, params);
    } else {
#endif
        gles_glTexParameterfv(target, pname, params);

#ifndef direct_glTexParameterfv
    }
#endif
}
#endif
#ifndef skip_glTexParameteri
void glTexParameteri(GLenum target, GLenum pname, GLint param) {
    LOAD_GLES(void, glTexParameteri, GLenum target, GLenum pname, GLint param);
#ifndef direct_glTexParameteri
    if (state.list.compiling) {
        push_glTexParameteri(target, pname, param);
    } else {
#endif
        gles_glTexParameteri(target, pname, param);

#ifndef direct_glTexParameteri
    }
#endif
}
#endif
#ifndef skip_glTexParameteriv
void glTexParameteriv(GLenum target, GLenum pname, const GLint * params) {
    LOAD_GLES(void, glTexParameteriv, GLenum target, GLenum pname, const GLint * params);
#ifndef direct_glTexParameteriv
    if (state.list.compiling) {
        push_glTexParameteriv(target, pname, params);
    } else {
#endif
        gles_glTexParameteriv(target, pname, params);

#ifndef direct_glTexParameteriv
    }
#endif
}
#endif
#ifndef skip_glTexParameterx
void glTexParameterx(GLenum target, GLenum pname, GLfixed param) {
    LOAD_GLES(void, glTexParameterx, GLenum target, GLenum pname, GLfixed param);
#ifndef direct_glTexParameterx
    if (state.list.compiling) {
        push_glTexParameterx(target, pname, param);
    } else {
#endif
        gles_glTexParameterx(target, pname, param);

#ifndef direct_glTexParameterx
    }
#endif
}
#endif
#ifndef skip_glTexParameterxv
void glTexParameterxv(GLenum target, GLenum pname, const GLfixed * params) {
    LOAD_GLES(void, glTexParameterxv, GLenum target, GLenum pname, const GLfixed * params);
#ifndef direct_glTexParameterxv
    if (state.list.compiling) {
        push_glTexParameterxv(target, pname, params);
    } else {
#endif
        gles_glTexParameterxv(target, pname, params);

#ifndef direct_glTexParameterxv
    }
#endif
}
#endif
#ifndef skip_glTexSubImage2D
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels) {
    LOAD_GLES(void, glTexSubImage2D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels);
#ifndef direct_glTexSubImage2D
    if (state.list.compiling) {
        push_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
    } else {
#endif
        gles_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);

#ifndef direct_glTexSubImage2D
    }
#endif
}
#endif
#ifndef skip_glTranslatef
void glTranslatef(GLfloat x, GLfloat y, GLfloat z) {
    LOAD_GLES(void, glTranslatef, GLfloat x, GLfloat y, GLfloat z);
#ifndef direct_glTranslatef
    if (state.list.compiling) {
        push_glTranslatef(x, y, z);
    } else {
#endif
        gles_glTranslatef(x, y, z);

#ifndef direct_glTranslatef
    }
#endif
}
#endif
#ifndef skip_glTranslatex
void glTranslatex(GLfixed x, GLfixed y, GLfixed z) {
    LOAD_GLES(void, glTranslatex, GLfixed x, GLfixed y, GLfixed z);
#ifndef direct_glTranslatex
    if (state.list.compiling) {
        push_glTranslatex(x, y, z);
    } else {
#endif
        gles_glTranslatex(x, y, z);

#ifndef direct_glTranslatex
    }
#endif
}
#endif
#ifndef skip_glVertexPointer
void glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    LOAD_GLES(void, glVertexPointer, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
#ifndef direct_glVertexPointer
    if (state.list.compiling) {
        push_glVertexPointer(size, type, stride, pointer);
    } else {
#endif
        gles_glVertexPointer(size, type, stride, pointer);

#ifndef direct_glVertexPointer
    }
#endif
}
#endif
#ifndef skip_glViewport
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
    LOAD_GLES(void, glViewport, GLint x, GLint y, GLsizei width, GLsizei height);
#ifndef direct_glViewport
    if (state.list.compiling) {
        push_glViewport(x, y, width, height);
    } else {
#endif
        gles_glViewport(x, y, width, height);

#ifndef direct_glViewport
    }
#endif
}
#endif
#endif
