#include "gleswrap.h"

void glPackedCall(const void *packed) {
    int format = *(int *)packed;
    switch (format) {
        case FORMAT_void_GLenum: {
            PACKED_void_GLenum *unpacked = (PACKED_void_GLenum *) packed;
            ARGS_void_GLenum args = unpacked->args;
            unpacked->func(args.a0);
        }
        case FORMAT_void_GLenum_GLclampf: {
            PACKED_void_GLenum_GLclampf *unpacked = (PACKED_void_GLenum_GLclampf *) packed;
            ARGS_void_GLenum_GLclampf args = unpacked->args;
            unpacked->func(args.a0, args.a1);
        }
        case FORMAT_void_GLenum_GLclampx: {
            PACKED_void_GLenum_GLclampx *unpacked = (PACKED_void_GLenum_GLclampx *) packed;
            ARGS_void_GLenum_GLclampx args = unpacked->args;
            unpacked->func(args.a0, args.a1);
        }
        case FORMAT_void_GLenum_GLuint: {
            PACKED_void_GLenum_GLuint *unpacked = (PACKED_void_GLenum_GLuint *) packed;
            ARGS_void_GLenum_GLuint args = unpacked->args;
            unpacked->func(args.a0, args.a1);
        }
        case FORMAT_void_GLenum_GLenum: {
            PACKED_void_GLenum_GLenum *unpacked = (PACKED_void_GLenum_GLenum *) packed;
            ARGS_void_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a0, args.a1);
        }
        case FORMAT_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum: {
            PACKED_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum *unpacked = (PACKED_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum *) packed;
            ARGS_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2, args.a3);
        }
        case FORMAT_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__ *) packed;
            ARGS_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2, args.a3);
        }
        case FORMAT_void_GLbitfield: {
            PACKED_void_GLbitfield *unpacked = (PACKED_void_GLbitfield *) packed;
            ARGS_void_GLbitfield args = unpacked->args;
            unpacked->func(args.a0);
        }
        case FORMAT_void_GLclampf_GLclampf_GLclampf_GLclampf: {
            PACKED_void_GLclampf_GLclampf_GLclampf_GLclampf *unpacked = (PACKED_void_GLclampf_GLclampf_GLclampf_GLclampf *) packed;
            ARGS_void_GLclampf_GLclampf_GLclampf_GLclampf args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2, args.a3);
        }
        case FORMAT_void_GLclampx_GLclampx_GLclampx_GLclampx: {
            PACKED_void_GLclampx_GLclampx_GLclampx_GLclampx *unpacked = (PACKED_void_GLclampx_GLclampx_GLclampx_GLclampx *) packed;
            ARGS_void_GLclampx_GLclampx_GLclampx_GLclampx args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2, args.a3);
        }
        case FORMAT_void_GLclampf: {
            PACKED_void_GLclampf *unpacked = (PACKED_void_GLclampf *) packed;
            ARGS_void_GLclampf args = unpacked->args;
            unpacked->func(args.a0);
        }
        case FORMAT_void_GLclampx: {
            PACKED_void_GLclampx *unpacked = (PACKED_void_GLclampx *) packed;
            ARGS_void_GLclampx args = unpacked->args;
            unpacked->func(args.a0);
        }
        case FORMAT_void_GLint: {
            PACKED_void_GLint *unpacked = (PACKED_void_GLint *) packed;
            ARGS_void_GLint args = unpacked->args;
            unpacked->func(args.a0);
        }
        case FORMAT_void_GLenum_const_GLfloat___GENPT__: {
            PACKED_void_GLenum_const_GLfloat___GENPT__ *unpacked = (PACKED_void_GLenum_const_GLfloat___GENPT__ *) packed;
            ARGS_void_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a0, args.a1);
        }
        case FORMAT_void_GLenum_const_GLfixed___GENPT__: {
            PACKED_void_GLenum_const_GLfixed___GENPT__ *unpacked = (PACKED_void_GLenum_const_GLfixed___GENPT__ *) packed;
            ARGS_void_GLenum_const_GLfixed___GENPT__ args = unpacked->args;
            unpacked->func(args.a0, args.a1);
        }
        case FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat *) packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2, args.a3);
        }
        case FORMAT_void_GLubyte_GLubyte_GLubyte_GLubyte: {
            PACKED_void_GLubyte_GLubyte_GLubyte_GLubyte *unpacked = (PACKED_void_GLubyte_GLubyte_GLubyte_GLubyte *) packed;
            ARGS_void_GLubyte_GLubyte_GLubyte_GLubyte args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2, args.a3);
        }
        case FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed: {
            PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed *unpacked = (PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed *) packed;
            ARGS_void_GLfixed_GLfixed_GLfixed_GLfixed args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2, args.a3);
        }
        case FORMAT_void_GLboolean_GLboolean_GLboolean_GLboolean: {
            PACKED_void_GLboolean_GLboolean_GLboolean_GLboolean *unpacked = (PACKED_void_GLboolean_GLboolean_GLboolean_GLboolean *) packed;
            ARGS_void_GLboolean_GLboolean_GLboolean_GLboolean args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2, args.a3);
        }
        case FORMAT_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__: {
            PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *) packed;
            ARGS_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2, args.a3);
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *) packed;
            ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *) packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
        }
        case FORMAT_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint: {
            PACKED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint *unpacked = (PACKED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint *) packed;
            ARGS_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei: {
            PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *unpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *) packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
        }
        case FORMAT_void_GLsizei_const_GLuint___GENPT__: {
            PACKED_void_GLsizei_const_GLuint___GENPT__ *unpacked = (PACKED_void_GLsizei_const_GLuint___GENPT__ *) packed;
            ARGS_void_GLsizei_const_GLuint___GENPT__ args = unpacked->args;
            unpacked->func(args.a0, args.a1);
        }
        case FORMAT_void_GLboolean: {
            PACKED_void_GLboolean *unpacked = (PACKED_void_GLboolean *) packed;
            ARGS_void_GLboolean args = unpacked->args;
            unpacked->func(args.a0);
        }
        case FORMAT_void_GLclampf_GLclampf: {
            PACKED_void_GLclampf_GLclampf *unpacked = (PACKED_void_GLclampf_GLclampf *) packed;
            ARGS_void_GLclampf_GLclampf args = unpacked->args;
            unpacked->func(args.a0, args.a1);
        }
        case FORMAT_void_GLclampx_GLclampx: {
            PACKED_void_GLclampx_GLclampx *unpacked = (PACKED_void_GLclampx_GLclampx *) packed;
            ARGS_void_GLclampx_GLclampx args = unpacked->args;
            unpacked->func(args.a0, args.a1);
        }
        case FORMAT_void_GLenum_GLint_GLsizei: {
            PACKED_void_GLenum_GLint_GLsizei *unpacked = (PACKED_void_GLenum_GLint_GLsizei *) packed;
            ARGS_void_GLenum_GLint_GLsizei args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2);
        }
        case FORMAT_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ *) packed;
            ARGS_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2, args.a3);
        }
        case FORMAT_void: {
            PACKED_void *unpacked = (PACKED_void *) packed;
            ARGS_void args = unpacked->args;
            unpacked->func();
        }
        case FORMAT_void_GLenum_GLfloat: {
            PACKED_void_GLenum_GLfloat *unpacked = (PACKED_void_GLenum_GLfloat *) packed;
            ARGS_void_GLenum_GLfloat args = unpacked->args;
            unpacked->func(args.a0, args.a1);
        }
        case FORMAT_void_GLenum_GLfixed: {
            PACKED_void_GLenum_GLfixed *unpacked = (PACKED_void_GLenum_GLfixed *) packed;
            ARGS_void_GLenum_GLfixed args = unpacked->args;
            unpacked->func(args.a0, args.a1);
        }
        case FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *) packed;
            ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2, args.a3, args.a4, args.a5);
        }
        case FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed: {
            PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed *unpacked = (PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed *) packed;
            ARGS_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2, args.a3, args.a4, args.a5);
        }
        case FORMAT_void_GLsizei_GLuint___GENPT__: {
            PACKED_void_GLsizei_GLuint___GENPT__ *unpacked = (PACKED_void_GLsizei_GLuint___GENPT__ *) packed;
            ARGS_void_GLsizei_GLuint___GENPT__ args = unpacked->args;
            unpacked->func(args.a0, args.a1);
        }
        case FORMAT_void_GLenum_GLboolean___GENPT__: {
            PACKED_void_GLenum_GLboolean___GENPT__ *unpacked = (PACKED_void_GLenum_GLboolean___GENPT__ *) packed;
            ARGS_void_GLenum_GLboolean___GENPT__ args = unpacked->args;
            unpacked->func(args.a0, args.a1);
        }
        case FORMAT_void_GLenum_GLenum_GLint___GENPT__: {
            PACKED_void_GLenum_GLenum_GLint___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLint___GENPT__ *) packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2);
        }
        case FORMAT_void_GLenum_GLfloat___GENPT__: {
            PACKED_void_GLenum_GLfloat___GENPT__ *unpacked = (PACKED_void_GLenum_GLfloat___GENPT__ *) packed;
            ARGS_void_GLenum_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a0, args.a1);
        }
        case FORMAT_void_GLenum_GLfixed___GENPT__: {
            PACKED_void_GLenum_GLfixed___GENPT__ *unpacked = (PACKED_void_GLenum_GLfixed___GENPT__ *) packed;
            ARGS_void_GLenum_GLfixed___GENPT__ args = unpacked->args;
            unpacked->func(args.a0, args.a1);
        }
        case FORMAT_GLenum: {
            PACKED_GLenum *unpacked = (PACKED_GLenum *) packed;
            ARGS_GLenum args = unpacked->args;
            unpacked->func();
        }
        case FORMAT_void_GLenum_GLint___GENPT__: {
            PACKED_void_GLenum_GLint___GENPT__ *unpacked = (PACKED_void_GLenum_GLint___GENPT__ *) packed;
            ARGS_void_GLenum_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a0, args.a1);
        }
        case FORMAT_void_GLenum_GLenum_GLfloat___GENPT__: {
            PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *) packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2);
        }
        case FORMAT_void_GLenum_GLenum_GLfixed___GENPT__: {
            PACKED_void_GLenum_GLenum_GLfixed___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLfixed___GENPT__ *) packed;
            ARGS_void_GLenum_GLenum_GLfixed___GENPT__ args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2);
        }
        case FORMAT_void_GLenum_GLvoid___GENPT____GENPT__: {
            PACKED_void_GLenum_GLvoid___GENPT____GENPT__ *unpacked = (PACKED_void_GLenum_GLvoid___GENPT____GENPT__ *) packed;
            ARGS_void_GLenum_GLvoid___GENPT____GENPT__ args = unpacked->args;
            unpacked->func(args.a0, args.a1);
        }
        case FORMAT_const_GLubyte___GENPT___GLenum: {
            PACKED_const_GLubyte___GENPT___GLenum *unpacked = (PACKED_const_GLubyte___GENPT___GLenum *) packed;
            ARGS_const_GLubyte___GENPT___GLenum args = unpacked->args;
            unpacked->func(args.a0);
        }
        case FORMAT_GLboolean_GLuint: {
            PACKED_GLboolean_GLuint *unpacked = (PACKED_GLboolean_GLuint *) packed;
            ARGS_GLboolean_GLuint args = unpacked->args;
            unpacked->func(args.a0);
        }
        case FORMAT_GLboolean_GLenum: {
            PACKED_GLboolean_GLenum *unpacked = (PACKED_GLboolean_GLenum *) packed;
            ARGS_GLboolean_GLenum args = unpacked->args;
            unpacked->func(args.a0);
        }
        case FORMAT_void_GLenum_GLenum_GLfloat: {
            PACKED_void_GLenum_GLenum_GLfloat *unpacked = (PACKED_void_GLenum_GLenum_GLfloat *) packed;
            ARGS_void_GLenum_GLenum_GLfloat args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2);
        }
        case FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__: {
            PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__ *) packed;
            ARGS_void_GLenum_GLenum_const_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2);
        }
        case FORMAT_void_GLenum_GLenum_GLfixed: {
            PACKED_void_GLenum_GLenum_GLfixed *unpacked = (PACKED_void_GLenum_GLenum_GLfixed *) packed;
            ARGS_void_GLenum_GLenum_GLfixed args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2);
        }
        case FORMAT_void_GLenum_GLenum_const_GLfixed___GENPT__: {
            PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__ *) packed;
            ARGS_void_GLenum_GLenum_const_GLfixed___GENPT__ args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2);
        }
        case FORMAT_void_GLfloat: {
            PACKED_void_GLfloat *unpacked = (PACKED_void_GLfloat *) packed;
            ARGS_void_GLfloat args = unpacked->args;
            unpacked->func(args.a0);
        }
        case FORMAT_void_GLfixed: {
            PACKED_void_GLfixed *unpacked = (PACKED_void_GLfixed *) packed;
            ARGS_void_GLfixed args = unpacked->args;
            unpacked->func(args.a0);
        }
        case FORMAT_void_const_GLfloat___GENPT__: {
            PACKED_void_const_GLfloat___GENPT__ *unpacked = (PACKED_void_const_GLfloat___GENPT__ *) packed;
            ARGS_void_const_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a0);
        }
        case FORMAT_void_const_GLfixed___GENPT__: {
            PACKED_void_const_GLfixed___GENPT__ *unpacked = (PACKED_void_const_GLfixed___GENPT__ *) packed;
            ARGS_void_const_GLfixed___GENPT__ args = unpacked->args;
            unpacked->func(args.a0);
        }
        case FORMAT_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat *) packed;
            ARGS_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2, args.a3, args.a4);
        }
        case FORMAT_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed: {
            PACKED_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed *unpacked = (PACKED_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed *) packed;
            ARGS_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2, args.a3, args.a4);
        }
        case FORMAT_void_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat_GLfloat *) packed;
            ARGS_void_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2);
        }
        case FORMAT_void_GLfixed_GLfixed_GLfixed: {
            PACKED_void_GLfixed_GLfixed_GLfixed *unpacked = (PACKED_void_GLfixed_GLfixed_GLfixed *) packed;
            ARGS_void_GLfixed_GLfixed_GLfixed args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2);
        }
        case FORMAT_void_GLenum_GLsizei_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *) packed;
            ARGS_void_GLenum_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2);
        }
        case FORMAT_void_GLenum_GLint: {
            PACKED_void_GLenum_GLint *unpacked = (PACKED_void_GLenum_GLint *) packed;
            ARGS_void_GLenum_GLint args = unpacked->args;
            unpacked->func(args.a0, args.a1);
        }
        case FORMAT_void_GLfloat_GLfloat: {
            PACKED_void_GLfloat_GLfloat *unpacked = (PACKED_void_GLfloat_GLfloat *) packed;
            ARGS_void_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a0, args.a1);
        }
        case FORMAT_void_GLfixed_GLfixed: {
            PACKED_void_GLfixed_GLfixed *unpacked = (PACKED_void_GLfixed_GLfixed *) packed;
            ARGS_void_GLfixed_GLfixed args = unpacked->args;
            unpacked->func(args.a0, args.a1);
        }
        case FORMAT_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__: {
            PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ *unpacked = (PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ *) packed;
            ARGS_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
        }
        case FORMAT_void_GLclampf_GLboolean: {
            PACKED_void_GLclampf_GLboolean *unpacked = (PACKED_void_GLclampf_GLboolean *) packed;
            ARGS_void_GLclampf_GLboolean args = unpacked->args;
            unpacked->func(args.a0, args.a1);
        }
        case FORMAT_void_GLclampx_GLboolean: {
            PACKED_void_GLclampx_GLboolean *unpacked = (PACKED_void_GLclampx_GLboolean *) packed;
            ARGS_void_GLclampx_GLboolean args = unpacked->args;
            unpacked->func(args.a0, args.a1);
        }
        case FORMAT_void_GLint_GLint_GLsizei_GLsizei: {
            PACKED_void_GLint_GLint_GLsizei_GLsizei *unpacked = (PACKED_void_GLint_GLint_GLsizei_GLsizei *) packed;
            ARGS_void_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2, args.a3);
        }
        case FORMAT_void_GLenum_GLint_GLuint: {
            PACKED_void_GLenum_GLint_GLuint *unpacked = (PACKED_void_GLenum_GLint_GLuint *) packed;
            ARGS_void_GLenum_GLint_GLuint args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2);
        }
        case FORMAT_void_GLuint: {
            PACKED_void_GLuint *unpacked = (PACKED_void_GLuint *) packed;
            ARGS_void_GLuint args = unpacked->args;
            unpacked->func(args.a0);
        }
        case FORMAT_void_GLenum_GLenum_GLenum: {
            PACKED_void_GLenum_GLenum_GLenum *unpacked = (PACKED_void_GLenum_GLenum_GLenum *) packed;
            ARGS_void_GLenum_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2);
        }
        case FORMAT_void_GLenum_GLenum_GLint: {
            PACKED_void_GLenum_GLenum_GLint *unpacked = (PACKED_void_GLenum_GLenum_GLint *) packed;
            ARGS_void_GLenum_GLenum_GLint args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2);
        }
        case FORMAT_void_GLenum_GLenum_const_GLint___GENPT__: {
            PACKED_void_GLenum_GLenum_const_GLint___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_const_GLint___GENPT__ *) packed;
            ARGS_void_GLenum_GLenum_const_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2);
        }
        case FORMAT_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *) packed;
            ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
        }
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *) packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a0, args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8);
        }
    }
}

#ifndef skip_glActiveTexture
WRAP_GLES(void, glActiveTexture, GLenum texture)
#ifndef direct_glActiveTexture
    if (listCompiling) {
        PACKED_void_GLenum *data = malloc(sizeof(PACKED_void_GLenum));
        data->format = FORMAT_void_GLenum;
        data->func = glActiveTexture;
        data->args.a0 = texture;
        glPushCall((void *)data);
    } else {
#endif
    gles_glActiveTexture(texture);
#ifndef direct_glActiveTexture
    }
#endif
END_WRAP
#endif

#ifndef skip_glAlphaFunc
WRAP_GLES(void, glAlphaFunc, GLenum func, GLclampf ref)
#ifndef direct_glAlphaFunc
    if (listCompiling) {
        PACKED_void_GLenum_GLclampf *data = malloc(sizeof(PACKED_void_GLenum_GLclampf));
        data->format = FORMAT_void_GLenum_GLclampf;
        data->func = glAlphaFunc;
        data->args.a0 = func;
        data->args.a1 = ref;
        glPushCall((void *)data);
    } else {
#endif
    gles_glAlphaFunc(func, ref);
#ifndef direct_glAlphaFunc
    }
#endif
END_WRAP
#endif

#ifndef skip_glAlphaFuncx
WRAP_GLES(void, glAlphaFuncx, GLenum func, GLclampx ref)
#ifndef direct_glAlphaFuncx
    if (listCompiling) {
        PACKED_void_GLenum_GLclampx *data = malloc(sizeof(PACKED_void_GLenum_GLclampx));
        data->format = FORMAT_void_GLenum_GLclampx;
        data->func = glAlphaFuncx;
        data->args.a0 = func;
        data->args.a1 = ref;
        glPushCall((void *)data);
    } else {
#endif
    gles_glAlphaFuncx(func, ref);
#ifndef direct_glAlphaFuncx
    }
#endif
END_WRAP
#endif

#ifndef skip_glBindBuffer
WRAP_GLES(void, glBindBuffer, GLenum target, GLuint buffer)
#ifndef direct_glBindBuffer
    if (listCompiling) {
        PACKED_void_GLenum_GLuint *data = malloc(sizeof(PACKED_void_GLenum_GLuint));
        data->format = FORMAT_void_GLenum_GLuint;
        data->func = glBindBuffer;
        data->args.a0 = target;
        data->args.a1 = buffer;
        glPushCall((void *)data);
    } else {
#endif
    gles_glBindBuffer(target, buffer);
#ifndef direct_glBindBuffer
    }
#endif
END_WRAP
#endif

#ifndef skip_glBindTexture
WRAP_GLES(void, glBindTexture, GLenum target, GLuint texture)
#ifndef direct_glBindTexture
    if (listCompiling) {
        PACKED_void_GLenum_GLuint *data = malloc(sizeof(PACKED_void_GLenum_GLuint));
        data->format = FORMAT_void_GLenum_GLuint;
        data->func = glBindTexture;
        data->args.a0 = target;
        data->args.a1 = texture;
        glPushCall((void *)data);
    } else {
#endif
    gles_glBindTexture(target, texture);
#ifndef direct_glBindTexture
    }
#endif
END_WRAP
#endif

#ifndef skip_glBlendFunc
WRAP_GLES(void, glBlendFunc, GLenum sfactor, GLenum dfactor)
#ifndef direct_glBlendFunc
    if (listCompiling) {
        PACKED_void_GLenum_GLenum *data = malloc(sizeof(PACKED_void_GLenum_GLenum));
        data->format = FORMAT_void_GLenum_GLenum;
        data->func = glBlendFunc;
        data->args.a0 = sfactor;
        data->args.a1 = dfactor;
        glPushCall((void *)data);
    } else {
#endif
    gles_glBlendFunc(sfactor, dfactor);
#ifndef direct_glBlendFunc
    }
#endif
END_WRAP
#endif

#ifndef skip_glBufferData
WRAP_GLES(void, glBufferData, GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage)
#ifndef direct_glBufferData
    if (listCompiling) {
        PACKED_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum *data = malloc(sizeof(PACKED_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum));
        data->format = FORMAT_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum;
        data->func = glBufferData;
        data->args.a0 = target;
        data->args.a1 = size;
        data->args.a2 = data;
        data->args.a3 = usage;
        glPushCall((void *)data);
    } else {
#endif
    gles_glBufferData(target, size, data, usage);
#ifndef direct_glBufferData
    }
#endif
END_WRAP
#endif

#ifndef skip_glBufferSubData
WRAP_GLES(void, glBufferSubData, GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data)
#ifndef direct_glBufferSubData
    if (listCompiling) {
        PACKED_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__));
        data->format = FORMAT_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__;
        data->func = glBufferSubData;
        data->args.a0 = target;
        data->args.a1 = offset;
        data->args.a2 = size;
        data->args.a3 = data;
        glPushCall((void *)data);
    } else {
#endif
    gles_glBufferSubData(target, offset, size, data);
#ifndef direct_glBufferSubData
    }
#endif
END_WRAP
#endif

#ifndef skip_glClear
WRAP_GLES(void, glClear, GLbitfield mask)
#ifndef direct_glClear
    if (listCompiling) {
        PACKED_void_GLbitfield *data = malloc(sizeof(PACKED_void_GLbitfield));
        data->format = FORMAT_void_GLbitfield;
        data->func = glClear;
        data->args.a0 = mask;
        glPushCall((void *)data);
    } else {
#endif
    gles_glClear(mask);
#ifndef direct_glClear
    }
#endif
END_WRAP
#endif

#ifndef skip_glClearColor
WRAP_GLES(void, glClearColor, GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
#ifndef direct_glClearColor
    if (listCompiling) {
        PACKED_void_GLclampf_GLclampf_GLclampf_GLclampf *data = malloc(sizeof(PACKED_void_GLclampf_GLclampf_GLclampf_GLclampf));
        data->format = FORMAT_void_GLclampf_GLclampf_GLclampf_GLclampf;
        data->func = glClearColor;
        data->args.a0 = red;
        data->args.a1 = green;
        data->args.a2 = blue;
        data->args.a3 = alpha;
        glPushCall((void *)data);
    } else {
#endif
    gles_glClearColor(red, green, blue, alpha);
#ifndef direct_glClearColor
    }
#endif
END_WRAP
#endif

#ifndef skip_glClearColorx
WRAP_GLES(void, glClearColorx, GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha)
#ifndef direct_glClearColorx
    if (listCompiling) {
        PACKED_void_GLclampx_GLclampx_GLclampx_GLclampx *data = malloc(sizeof(PACKED_void_GLclampx_GLclampx_GLclampx_GLclampx));
        data->format = FORMAT_void_GLclampx_GLclampx_GLclampx_GLclampx;
        data->func = glClearColorx;
        data->args.a0 = red;
        data->args.a1 = green;
        data->args.a2 = blue;
        data->args.a3 = alpha;
        glPushCall((void *)data);
    } else {
#endif
    gles_glClearColorx(red, green, blue, alpha);
#ifndef direct_glClearColorx
    }
#endif
END_WRAP
#endif

#ifndef skip_glClearDepthf
WRAP_GLES(void, glClearDepthf, GLclampf depth)
#ifndef direct_glClearDepthf
    if (listCompiling) {
        PACKED_void_GLclampf *data = malloc(sizeof(PACKED_void_GLclampf));
        data->format = FORMAT_void_GLclampf;
        data->func = glClearDepthf;
        data->args.a0 = depth;
        glPushCall((void *)data);
    } else {
#endif
    gles_glClearDepthf(depth);
#ifndef direct_glClearDepthf
    }
#endif
END_WRAP
#endif

#ifndef skip_glClearDepthx
WRAP_GLES(void, glClearDepthx, GLclampx depth)
#ifndef direct_glClearDepthx
    if (listCompiling) {
        PACKED_void_GLclampx *data = malloc(sizeof(PACKED_void_GLclampx));
        data->format = FORMAT_void_GLclampx;
        data->func = glClearDepthx;
        data->args.a0 = depth;
        glPushCall((void *)data);
    } else {
#endif
    gles_glClearDepthx(depth);
#ifndef direct_glClearDepthx
    }
#endif
END_WRAP
#endif

#ifndef skip_glClearStencil
WRAP_GLES(void, glClearStencil, GLint s)
#ifndef direct_glClearStencil
    if (listCompiling) {
        PACKED_void_GLint *data = malloc(sizeof(PACKED_void_GLint));
        data->format = FORMAT_void_GLint;
        data->func = glClearStencil;
        data->args.a0 = s;
        glPushCall((void *)data);
    } else {
#endif
    gles_glClearStencil(s);
#ifndef direct_glClearStencil
    }
#endif
END_WRAP
#endif

#ifndef skip_glClientActiveTexture
WRAP_GLES(void, glClientActiveTexture, GLenum texture)
#ifndef direct_glClientActiveTexture
    if (listCompiling) {
        PACKED_void_GLenum *data = malloc(sizeof(PACKED_void_GLenum));
        data->format = FORMAT_void_GLenum;
        data->func = glClientActiveTexture;
        data->args.a0 = texture;
        glPushCall((void *)data);
    } else {
#endif
    gles_glClientActiveTexture(texture);
#ifndef direct_glClientActiveTexture
    }
#endif
END_WRAP
#endif

#ifndef skip_glClipPlanef
WRAP_GLES(void, glClipPlanef, GLenum plane, const GLfloat * equation)
#ifndef direct_glClipPlanef
    if (listCompiling) {
        PACKED_void_GLenum_const_GLfloat___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_const_GLfloat___GENPT__));
        data->format = FORMAT_void_GLenum_const_GLfloat___GENPT__;
        data->func = glClipPlanef;
        data->args.a0 = plane;
        data->args.a1 = equation;
        glPushCall((void *)data);
    } else {
#endif
    gles_glClipPlanef(plane, equation);
#ifndef direct_glClipPlanef
    }
#endif
END_WRAP
#endif

#ifndef skip_glClipPlanex
WRAP_GLES(void, glClipPlanex, GLenum plane, const GLfixed * equation)
#ifndef direct_glClipPlanex
    if (listCompiling) {
        PACKED_void_GLenum_const_GLfixed___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_const_GLfixed___GENPT__));
        data->format = FORMAT_void_GLenum_const_GLfixed___GENPT__;
        data->func = glClipPlanex;
        data->args.a0 = plane;
        data->args.a1 = equation;
        glPushCall((void *)data);
    } else {
#endif
    gles_glClipPlanex(plane, equation);
#ifndef direct_glClipPlanex
    }
#endif
END_WRAP
#endif

#ifndef skip_glColor4f
WRAP_GLES(void, glColor4f, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
#ifndef direct_glColor4f
    if (listCompiling) {
        PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat *data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat));
        data->format = FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat;
        data->func = glColor4f;
        data->args.a0 = red;
        data->args.a1 = green;
        data->args.a2 = blue;
        data->args.a3 = alpha;
        glPushCall((void *)data);
    } else {
#endif
    gles_glColor4f(red, green, blue, alpha);
#ifndef direct_glColor4f
    }
#endif
END_WRAP
#endif

#ifndef skip_glColor4ub
WRAP_GLES(void, glColor4ub, GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha)
#ifndef direct_glColor4ub
    if (listCompiling) {
        PACKED_void_GLubyte_GLubyte_GLubyte_GLubyte *data = malloc(sizeof(PACKED_void_GLubyte_GLubyte_GLubyte_GLubyte));
        data->format = FORMAT_void_GLubyte_GLubyte_GLubyte_GLubyte;
        data->func = glColor4ub;
        data->args.a0 = red;
        data->args.a1 = green;
        data->args.a2 = blue;
        data->args.a3 = alpha;
        glPushCall((void *)data);
    } else {
#endif
    gles_glColor4ub(red, green, blue, alpha);
#ifndef direct_glColor4ub
    }
#endif
END_WRAP
#endif

#ifndef skip_glColor4x
WRAP_GLES(void, glColor4x, GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha)
#ifndef direct_glColor4x
    if (listCompiling) {
        PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed *data = malloc(sizeof(PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed));
        data->format = FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed;
        data->func = glColor4x;
        data->args.a0 = red;
        data->args.a1 = green;
        data->args.a2 = blue;
        data->args.a3 = alpha;
        glPushCall((void *)data);
    } else {
#endif
    gles_glColor4x(red, green, blue, alpha);
#ifndef direct_glColor4x
    }
#endif
END_WRAP
#endif

#ifndef skip_glColorMask
WRAP_GLES(void, glColorMask, GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
#ifndef direct_glColorMask
    if (listCompiling) {
        PACKED_void_GLboolean_GLboolean_GLboolean_GLboolean *data = malloc(sizeof(PACKED_void_GLboolean_GLboolean_GLboolean_GLboolean));
        data->format = FORMAT_void_GLboolean_GLboolean_GLboolean_GLboolean;
        data->func = glColorMask;
        data->args.a0 = red;
        data->args.a1 = green;
        data->args.a2 = blue;
        data->args.a3 = alpha;
        glPushCall((void *)data);
    } else {
#endif
    gles_glColorMask(red, green, blue, alpha);
#ifndef direct_glColorMask
    }
#endif
END_WRAP
#endif

#ifndef skip_glColorPointer
WRAP_GLES(void, glColorPointer, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer)
#ifndef direct_glColorPointer
    if (listCompiling) {
        PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *data = malloc(sizeof(PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__));
        data->format = FORMAT_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__;
        data->func = glColorPointer;
        data->args.a0 = size;
        data->args.a1 = type;
        data->args.a2 = stride;
        data->args.a3 = pointer;
        glPushCall((void *)data);
    } else {
#endif
    gles_glColorPointer(size, type, stride, pointer);
#ifndef direct_glColorPointer
    }
#endif
END_WRAP
#endif

#ifndef skip_glCompressedTexImage2D
WRAP_GLES(void, glCompressedTexImage2D, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data)
#ifndef direct_glCompressedTexImage2D
    if (listCompiling) {
        PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__));
        data->format = FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__;
        data->func = glCompressedTexImage2D;
        data->args.a0 = target;
        data->args.a1 = level;
        data->args.a2 = internalformat;
        data->args.a3 = width;
        data->args.a4 = height;
        data->args.a5 = border;
        data->args.a6 = imageSize;
        data->args.a7 = data;
        glPushCall((void *)data);
    } else {
#endif
    gles_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
#ifndef direct_glCompressedTexImage2D
    }
#endif
END_WRAP
#endif

#ifndef skip_glCompressedTexSubImage2D
WRAP_GLES(void, glCompressedTexSubImage2D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data)
#ifndef direct_glCompressedTexSubImage2D
    if (listCompiling) {
        PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__));
        data->format = FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__;
        data->func = glCompressedTexSubImage2D;
        data->args.a0 = target;
        data->args.a1 = level;
        data->args.a2 = xoffset;
        data->args.a3 = yoffset;
        data->args.a4 = width;
        data->args.a5 = height;
        data->args.a6 = format;
        data->args.a7 = imageSize;
        data->args.a8 = data;
        glPushCall((void *)data);
    } else {
#endif
    gles_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
#ifndef direct_glCompressedTexSubImage2D
    }
#endif
END_WRAP
#endif

#ifndef skip_glCopyTexImage2D
WRAP_GLES(void, glCopyTexImage2D, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
#ifndef direct_glCopyTexImage2D
    if (listCompiling) {
        PACKED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint *data = malloc(sizeof(PACKED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint));
        data->format = FORMAT_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint;
        data->func = glCopyTexImage2D;
        data->args.a0 = target;
        data->args.a1 = level;
        data->args.a2 = internalformat;
        data->args.a3 = x;
        data->args.a4 = y;
        data->args.a5 = width;
        data->args.a6 = height;
        data->args.a7 = border;
        glPushCall((void *)data);
    } else {
#endif
    gles_glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
#ifndef direct_glCopyTexImage2D
    }
#endif
END_WRAP
#endif

#ifndef skip_glCopyTexSubImage2D
WRAP_GLES(void, glCopyTexSubImage2D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
#ifndef direct_glCopyTexSubImage2D
    if (listCompiling) {
        PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *data = malloc(sizeof(PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei));
        data->format = FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei;
        data->func = glCopyTexSubImage2D;
        data->args.a0 = target;
        data->args.a1 = level;
        data->args.a2 = xoffset;
        data->args.a3 = yoffset;
        data->args.a4 = x;
        data->args.a5 = y;
        data->args.a6 = width;
        data->args.a7 = height;
        glPushCall((void *)data);
    } else {
#endif
    gles_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
#ifndef direct_glCopyTexSubImage2D
    }
#endif
END_WRAP
#endif

#ifndef skip_glCullFace
WRAP_GLES(void, glCullFace, GLenum mode)
#ifndef direct_glCullFace
    if (listCompiling) {
        PACKED_void_GLenum *data = malloc(sizeof(PACKED_void_GLenum));
        data->format = FORMAT_void_GLenum;
        data->func = glCullFace;
        data->args.a0 = mode;
        glPushCall((void *)data);
    } else {
#endif
    gles_glCullFace(mode);
#ifndef direct_glCullFace
    }
#endif
END_WRAP
#endif

#ifndef skip_glDeleteBuffers
WRAP_GLES(void, glDeleteBuffers, GLsizei n, const GLuint * buffers)
#ifndef direct_glDeleteBuffers
    if (listCompiling) {
        PACKED_void_GLsizei_const_GLuint___GENPT__ *data = malloc(sizeof(PACKED_void_GLsizei_const_GLuint___GENPT__));
        data->format = FORMAT_void_GLsizei_const_GLuint___GENPT__;
        data->func = glDeleteBuffers;
        data->args.a0 = n;
        data->args.a1 = buffers;
        glPushCall((void *)data);
    } else {
#endif
    gles_glDeleteBuffers(n, buffers);
#ifndef direct_glDeleteBuffers
    }
#endif
END_WRAP
#endif

#ifndef skip_glDeleteTextures
WRAP_GLES(void, glDeleteTextures, GLsizei n, const GLuint * textures)
#ifndef direct_glDeleteTextures
    if (listCompiling) {
        PACKED_void_GLsizei_const_GLuint___GENPT__ *data = malloc(sizeof(PACKED_void_GLsizei_const_GLuint___GENPT__));
        data->format = FORMAT_void_GLsizei_const_GLuint___GENPT__;
        data->func = glDeleteTextures;
        data->args.a0 = n;
        data->args.a1 = textures;
        glPushCall((void *)data);
    } else {
#endif
    gles_glDeleteTextures(n, textures);
#ifndef direct_glDeleteTextures
    }
#endif
END_WRAP
#endif

#ifndef skip_glDepthFunc
WRAP_GLES(void, glDepthFunc, GLenum func)
#ifndef direct_glDepthFunc
    if (listCompiling) {
        PACKED_void_GLenum *data = malloc(sizeof(PACKED_void_GLenum));
        data->format = FORMAT_void_GLenum;
        data->func = glDepthFunc;
        data->args.a0 = func;
        glPushCall((void *)data);
    } else {
#endif
    gles_glDepthFunc(func);
#ifndef direct_glDepthFunc
    }
#endif
END_WRAP
#endif

#ifndef skip_glDepthMask
WRAP_GLES(void, glDepthMask, GLboolean flag)
#ifndef direct_glDepthMask
    if (listCompiling) {
        PACKED_void_GLboolean *data = malloc(sizeof(PACKED_void_GLboolean));
        data->format = FORMAT_void_GLboolean;
        data->func = glDepthMask;
        data->args.a0 = flag;
        glPushCall((void *)data);
    } else {
#endif
    gles_glDepthMask(flag);
#ifndef direct_glDepthMask
    }
#endif
END_WRAP
#endif

#ifndef skip_glDepthRangef
WRAP_GLES(void, glDepthRangef, GLclampf near, GLclampf far)
#ifndef direct_glDepthRangef
    if (listCompiling) {
        PACKED_void_GLclampf_GLclampf *data = malloc(sizeof(PACKED_void_GLclampf_GLclampf));
        data->format = FORMAT_void_GLclampf_GLclampf;
        data->func = glDepthRangef;
        data->args.a0 = near;
        data->args.a1 = far;
        glPushCall((void *)data);
    } else {
#endif
    gles_glDepthRangef(near, far);
#ifndef direct_glDepthRangef
    }
#endif
END_WRAP
#endif

#ifndef skip_glDepthRangex
WRAP_GLES(void, glDepthRangex, GLclampx near, GLclampx far)
#ifndef direct_glDepthRangex
    if (listCompiling) {
        PACKED_void_GLclampx_GLclampx *data = malloc(sizeof(PACKED_void_GLclampx_GLclampx));
        data->format = FORMAT_void_GLclampx_GLclampx;
        data->func = glDepthRangex;
        data->args.a0 = near;
        data->args.a1 = far;
        glPushCall((void *)data);
    } else {
#endif
    gles_glDepthRangex(near, far);
#ifndef direct_glDepthRangex
    }
#endif
END_WRAP
#endif

#ifndef skip_glDisable
WRAP_GLES(void, glDisable, GLenum cap)
#ifndef direct_glDisable
    if (listCompiling) {
        PACKED_void_GLenum *data = malloc(sizeof(PACKED_void_GLenum));
        data->format = FORMAT_void_GLenum;
        data->func = glDisable;
        data->args.a0 = cap;
        glPushCall((void *)data);
    } else {
#endif
    gles_glDisable(cap);
#ifndef direct_glDisable
    }
#endif
END_WRAP
#endif

#ifndef skip_glDisableClientState
WRAP_GLES(void, glDisableClientState, GLenum array)
#ifndef direct_glDisableClientState
    if (listCompiling) {
        PACKED_void_GLenum *data = malloc(sizeof(PACKED_void_GLenum));
        data->format = FORMAT_void_GLenum;
        data->func = glDisableClientState;
        data->args.a0 = array;
        glPushCall((void *)data);
    } else {
#endif
    gles_glDisableClientState(array);
#ifndef direct_glDisableClientState
    }
#endif
END_WRAP
#endif

#ifndef skip_glDrawArrays
WRAP_GLES(void, glDrawArrays, GLenum mode, GLint first, GLsizei count)
#ifndef direct_glDrawArrays
    if (listCompiling) {
        PACKED_void_GLenum_GLint_GLsizei *data = malloc(sizeof(PACKED_void_GLenum_GLint_GLsizei));
        data->format = FORMAT_void_GLenum_GLint_GLsizei;
        data->func = glDrawArrays;
        data->args.a0 = mode;
        data->args.a1 = first;
        data->args.a2 = count;
        glPushCall((void *)data);
    } else {
#endif
    gles_glDrawArrays(mode, first, count);
#ifndef direct_glDrawArrays
    }
#endif
END_WRAP
#endif

#ifndef skip_glDrawElements
WRAP_GLES(void, glDrawElements, GLenum mode, GLsizei count, GLenum type, const GLvoid * indices)
#ifndef direct_glDrawElements
    if (listCompiling) {
        PACKED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__));
        data->format = FORMAT_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__;
        data->func = glDrawElements;
        data->args.a0 = mode;
        data->args.a1 = count;
        data->args.a2 = type;
        data->args.a3 = indices;
        glPushCall((void *)data);
    } else {
#endif
    gles_glDrawElements(mode, count, type, indices);
#ifndef direct_glDrawElements
    }
#endif
END_WRAP
#endif

#ifndef skip_glEnable
WRAP_GLES(void, glEnable, GLenum cap)
#ifndef direct_glEnable
    if (listCompiling) {
        PACKED_void_GLenum *data = malloc(sizeof(PACKED_void_GLenum));
        data->format = FORMAT_void_GLenum;
        data->func = glEnable;
        data->args.a0 = cap;
        glPushCall((void *)data);
    } else {
#endif
    gles_glEnable(cap);
#ifndef direct_glEnable
    }
#endif
END_WRAP
#endif

#ifndef skip_glEnableClientState
WRAP_GLES(void, glEnableClientState, GLenum array)
#ifndef direct_glEnableClientState
    if (listCompiling) {
        PACKED_void_GLenum *data = malloc(sizeof(PACKED_void_GLenum));
        data->format = FORMAT_void_GLenum;
        data->func = glEnableClientState;
        data->args.a0 = array;
        glPushCall((void *)data);
    } else {
#endif
    gles_glEnableClientState(array);
#ifndef direct_glEnableClientState
    }
#endif
END_WRAP
#endif

#ifndef skip_glFinish
WRAP_GLES(void, glFinish)
#ifndef direct_glFinish
    if (listCompiling) {
        PACKED_void *data = malloc(sizeof(PACKED_void));
        data->format = FORMAT_void;
        data->func = glFinish;
        glPushCall((void *)data);
    } else {
#endif
    gles_glFinish();
#ifndef direct_glFinish
    }
#endif
END_WRAP
#endif

#ifndef skip_glFlush
WRAP_GLES(void, glFlush)
#ifndef direct_glFlush
    if (listCompiling) {
        PACKED_void *data = malloc(sizeof(PACKED_void));
        data->format = FORMAT_void;
        data->func = glFlush;
        glPushCall((void *)data);
    } else {
#endif
    gles_glFlush();
#ifndef direct_glFlush
    }
#endif
END_WRAP
#endif

#ifndef skip_glFogf
WRAP_GLES(void, glFogf, GLenum pname, GLfloat param)
#ifndef direct_glFogf
    if (listCompiling) {
        PACKED_void_GLenum_GLfloat *data = malloc(sizeof(PACKED_void_GLenum_GLfloat));
        data->format = FORMAT_void_GLenum_GLfloat;
        data->func = glFogf;
        data->args.a0 = pname;
        data->args.a1 = param;
        glPushCall((void *)data);
    } else {
#endif
    gles_glFogf(pname, param);
#ifndef direct_glFogf
    }
#endif
END_WRAP
#endif

#ifndef skip_glFogfv
WRAP_GLES(void, glFogfv, GLenum pname, const GLfloat * params)
#ifndef direct_glFogfv
    if (listCompiling) {
        PACKED_void_GLenum_const_GLfloat___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_const_GLfloat___GENPT__));
        data->format = FORMAT_void_GLenum_const_GLfloat___GENPT__;
        data->func = glFogfv;
        data->args.a0 = pname;
        data->args.a1 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glFogfv(pname, params);
#ifndef direct_glFogfv
    }
#endif
END_WRAP
#endif

#ifndef skip_glFogx
WRAP_GLES(void, glFogx, GLenum pname, GLfixed param)
#ifndef direct_glFogx
    if (listCompiling) {
        PACKED_void_GLenum_GLfixed *data = malloc(sizeof(PACKED_void_GLenum_GLfixed));
        data->format = FORMAT_void_GLenum_GLfixed;
        data->func = glFogx;
        data->args.a0 = pname;
        data->args.a1 = param;
        glPushCall((void *)data);
    } else {
#endif
    gles_glFogx(pname, param);
#ifndef direct_glFogx
    }
#endif
END_WRAP
#endif

#ifndef skip_glFogxv
WRAP_GLES(void, glFogxv, GLenum pname, const GLfixed * params)
#ifndef direct_glFogxv
    if (listCompiling) {
        PACKED_void_GLenum_const_GLfixed___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_const_GLfixed___GENPT__));
        data->format = FORMAT_void_GLenum_const_GLfixed___GENPT__;
        data->func = glFogxv;
        data->args.a0 = pname;
        data->args.a1 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glFogxv(pname, params);
#ifndef direct_glFogxv
    }
#endif
END_WRAP
#endif

#ifndef skip_glFrontFace
WRAP_GLES(void, glFrontFace, GLenum mode)
#ifndef direct_glFrontFace
    if (listCompiling) {
        PACKED_void_GLenum *data = malloc(sizeof(PACKED_void_GLenum));
        data->format = FORMAT_void_GLenum;
        data->func = glFrontFace;
        data->args.a0 = mode;
        glPushCall((void *)data);
    } else {
#endif
    gles_glFrontFace(mode);
#ifndef direct_glFrontFace
    }
#endif
END_WRAP
#endif

#ifndef skip_glFrustumf
WRAP_GLES(void, glFrustumf, GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far)
#ifndef direct_glFrustumf
    if (listCompiling) {
        PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat));
        data->format = FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
        data->func = glFrustumf;
        data->args.a0 = left;
        data->args.a1 = right;
        data->args.a2 = bottom;
        data->args.a3 = top;
        data->args.a4 = near;
        data->args.a5 = far;
        glPushCall((void *)data);
    } else {
#endif
    gles_glFrustumf(left, right, bottom, top, near, far);
#ifndef direct_glFrustumf
    }
#endif
END_WRAP
#endif

#ifndef skip_glFrustumx
WRAP_GLES(void, glFrustumx, GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far)
#ifndef direct_glFrustumx
    if (listCompiling) {
        PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed *data = malloc(sizeof(PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed));
        data->format = FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed;
        data->func = glFrustumx;
        data->args.a0 = left;
        data->args.a1 = right;
        data->args.a2 = bottom;
        data->args.a3 = top;
        data->args.a4 = near;
        data->args.a5 = far;
        glPushCall((void *)data);
    } else {
#endif
    gles_glFrustumx(left, right, bottom, top, near, far);
#ifndef direct_glFrustumx
    }
#endif
END_WRAP
#endif

#ifndef skip_glGenBuffers
WRAP_GLES(void, glGenBuffers, GLsizei n, GLuint * buffers)
#ifndef direct_glGenBuffers
    if (listCompiling) {
        PACKED_void_GLsizei_GLuint___GENPT__ *data = malloc(sizeof(PACKED_void_GLsizei_GLuint___GENPT__));
        data->format = FORMAT_void_GLsizei_GLuint___GENPT__;
        data->func = glGenBuffers;
        data->args.a0 = n;
        data->args.a1 = buffers;
        glPushCall((void *)data);
    } else {
#endif
    gles_glGenBuffers(n, buffers);
#ifndef direct_glGenBuffers
    }
#endif
END_WRAP
#endif

#ifndef skip_glGenTextures
WRAP_GLES(void, glGenTextures, GLsizei n, GLuint * textures)
#ifndef direct_glGenTextures
    if (listCompiling) {
        PACKED_void_GLsizei_GLuint___GENPT__ *data = malloc(sizeof(PACKED_void_GLsizei_GLuint___GENPT__));
        data->format = FORMAT_void_GLsizei_GLuint___GENPT__;
        data->func = glGenTextures;
        data->args.a0 = n;
        data->args.a1 = textures;
        glPushCall((void *)data);
    } else {
#endif
    gles_glGenTextures(n, textures);
#ifndef direct_glGenTextures
    }
#endif
END_WRAP
#endif

#ifndef skip_glGetBooleanv
WRAP_GLES(void, glGetBooleanv, GLenum pname, GLboolean * params)
#ifndef direct_glGetBooleanv
    if (listCompiling) {
        PACKED_void_GLenum_GLboolean___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLboolean___GENPT__));
        data->format = FORMAT_void_GLenum_GLboolean___GENPT__;
        data->func = glGetBooleanv;
        data->args.a0 = pname;
        data->args.a1 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glGetBooleanv(pname, params);
#ifndef direct_glGetBooleanv
    }
#endif
END_WRAP
#endif

#ifndef skip_glGetBufferParameteriv
WRAP_GLES(void, glGetBufferParameteriv, GLenum target, GLenum pname, GLint * params)
#ifndef direct_glGetBufferParameteriv
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_GLint___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint___GENPT__));
        data->format = FORMAT_void_GLenum_GLenum_GLint___GENPT__;
        data->func = glGetBufferParameteriv;
        data->args.a0 = target;
        data->args.a1 = pname;
        data->args.a2 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glGetBufferParameteriv(target, pname, params);
#ifndef direct_glGetBufferParameteriv
    }
#endif
END_WRAP
#endif

#ifndef skip_glGetClipPlanef
WRAP_GLES(void, glGetClipPlanef, GLenum plane, GLfloat * equation)
#ifndef direct_glGetClipPlanef
    if (listCompiling) {
        PACKED_void_GLenum_GLfloat___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLfloat___GENPT__));
        data->format = FORMAT_void_GLenum_GLfloat___GENPT__;
        data->func = glGetClipPlanef;
        data->args.a0 = plane;
        data->args.a1 = equation;
        glPushCall((void *)data);
    } else {
#endif
    gles_glGetClipPlanef(plane, equation);
#ifndef direct_glGetClipPlanef
    }
#endif
END_WRAP
#endif

#ifndef skip_glGetClipPlanex
WRAP_GLES(void, glGetClipPlanex, GLenum plane, GLfixed * equation)
#ifndef direct_glGetClipPlanex
    if (listCompiling) {
        PACKED_void_GLenum_GLfixed___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLfixed___GENPT__));
        data->format = FORMAT_void_GLenum_GLfixed___GENPT__;
        data->func = glGetClipPlanex;
        data->args.a0 = plane;
        data->args.a1 = equation;
        glPushCall((void *)data);
    } else {
#endif
    gles_glGetClipPlanex(plane, equation);
#ifndef direct_glGetClipPlanex
    }
#endif
END_WRAP
#endif

#ifndef skip_glGetError
WRAP_GLES(GLenum, glGetError)
#ifndef direct_glGetError
    if (listCompiling) {
        PACKED_GLenum *data = malloc(sizeof(PACKED_GLenum));
        data->format = FORMAT_GLenum;
        data->func = glGetError;
        glPushCall((void *)data);
        return 0;
    } else {
#endif
    return gles_glGetError();
#ifndef direct_glGetError
    }
#endif
END_WRAP
#endif

#ifndef skip_glGetFixedv
WRAP_GLES(void, glGetFixedv, GLenum pname, GLfixed * params)
#ifndef direct_glGetFixedv
    if (listCompiling) {
        PACKED_void_GLenum_GLfixed___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLfixed___GENPT__));
        data->format = FORMAT_void_GLenum_GLfixed___GENPT__;
        data->func = glGetFixedv;
        data->args.a0 = pname;
        data->args.a1 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glGetFixedv(pname, params);
#ifndef direct_glGetFixedv
    }
#endif
END_WRAP
#endif

#ifndef skip_glGetFloatv
WRAP_GLES(void, glGetFloatv, GLenum pname, GLfloat * params)
#ifndef direct_glGetFloatv
    if (listCompiling) {
        PACKED_void_GLenum_GLfloat___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLfloat___GENPT__));
        data->format = FORMAT_void_GLenum_GLfloat___GENPT__;
        data->func = glGetFloatv;
        data->args.a0 = pname;
        data->args.a1 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glGetFloatv(pname, params);
#ifndef direct_glGetFloatv
    }
#endif
END_WRAP
#endif

#ifndef skip_glGetIntegerv
WRAP_GLES(void, glGetIntegerv, GLenum pname, GLint * params)
#ifndef direct_glGetIntegerv
    if (listCompiling) {
        PACKED_void_GLenum_GLint___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLint___GENPT__));
        data->format = FORMAT_void_GLenum_GLint___GENPT__;
        data->func = glGetIntegerv;
        data->args.a0 = pname;
        data->args.a1 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glGetIntegerv(pname, params);
#ifndef direct_glGetIntegerv
    }
#endif
END_WRAP
#endif

#ifndef skip_glGetLightfv
WRAP_GLES(void, glGetLightfv, GLenum light, GLenum pname, GLfloat * params)
#ifndef direct_glGetLightfv
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfloat___GENPT__));
        data->format = FORMAT_void_GLenum_GLenum_GLfloat___GENPT__;
        data->func = glGetLightfv;
        data->args.a0 = light;
        data->args.a1 = pname;
        data->args.a2 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glGetLightfv(light, pname, params);
#ifndef direct_glGetLightfv
    }
#endif
END_WRAP
#endif

#ifndef skip_glGetLightxv
WRAP_GLES(void, glGetLightxv, GLenum light, GLenum pname, GLfixed * params)
#ifndef direct_glGetLightxv
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_GLfixed___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfixed___GENPT__));
        data->format = FORMAT_void_GLenum_GLenum_GLfixed___GENPT__;
        data->func = glGetLightxv;
        data->args.a0 = light;
        data->args.a1 = pname;
        data->args.a2 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glGetLightxv(light, pname, params);
#ifndef direct_glGetLightxv
    }
#endif
END_WRAP
#endif

#ifndef skip_glGetMaterialfv
WRAP_GLES(void, glGetMaterialfv, GLenum face, GLenum pname, GLfloat * params)
#ifndef direct_glGetMaterialfv
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfloat___GENPT__));
        data->format = FORMAT_void_GLenum_GLenum_GLfloat___GENPT__;
        data->func = glGetMaterialfv;
        data->args.a0 = face;
        data->args.a1 = pname;
        data->args.a2 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glGetMaterialfv(face, pname, params);
#ifndef direct_glGetMaterialfv
    }
#endif
END_WRAP
#endif

#ifndef skip_glGetMaterialxv
WRAP_GLES(void, glGetMaterialxv, GLenum face, GLenum pname, GLfixed * params)
#ifndef direct_glGetMaterialxv
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_GLfixed___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfixed___GENPT__));
        data->format = FORMAT_void_GLenum_GLenum_GLfixed___GENPT__;
        data->func = glGetMaterialxv;
        data->args.a0 = face;
        data->args.a1 = pname;
        data->args.a2 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glGetMaterialxv(face, pname, params);
#ifndef direct_glGetMaterialxv
    }
#endif
END_WRAP
#endif

#ifndef skip_glGetPointerv
WRAP_GLES(void, glGetPointerv, GLenum pname, GLvoid ** params)
#ifndef direct_glGetPointerv
    if (listCompiling) {
        PACKED_void_GLenum_GLvoid___GENPT____GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLvoid___GENPT____GENPT__));
        data->format = FORMAT_void_GLenum_GLvoid___GENPT____GENPT__;
        data->func = glGetPointerv;
        data->args.a0 = pname;
        data->args.a1 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glGetPointerv(pname, params);
#ifndef direct_glGetPointerv
    }
#endif
END_WRAP
#endif

#ifndef skip_glGetString
WRAP_GLES(const GLubyte *, glGetString, GLenum name)
#ifndef direct_glGetString
    if (listCompiling) {
        PACKED_const_GLubyte___GENPT___GLenum *data = malloc(sizeof(PACKED_const_GLubyte___GENPT___GLenum));
        data->format = FORMAT_const_GLubyte___GENPT___GLenum;
        data->func = glGetString;
        data->args.a0 = name;
        glPushCall((void *)data);
        return 0;
    } else {
#endif
    return gles_glGetString(name);
#ifndef direct_glGetString
    }
#endif
END_WRAP
#endif

#ifndef skip_glGetTexEnvfv
WRAP_GLES(void, glGetTexEnvfv, GLenum target, GLenum pname, GLfloat * params)
#ifndef direct_glGetTexEnvfv
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfloat___GENPT__));
        data->format = FORMAT_void_GLenum_GLenum_GLfloat___GENPT__;
        data->func = glGetTexEnvfv;
        data->args.a0 = target;
        data->args.a1 = pname;
        data->args.a2 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glGetTexEnvfv(target, pname, params);
#ifndef direct_glGetTexEnvfv
    }
#endif
END_WRAP
#endif

#ifndef skip_glGetTexEnviv
WRAP_GLES(void, glGetTexEnviv, GLenum target, GLenum pname, GLint * params)
#ifndef direct_glGetTexEnviv
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_GLint___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint___GENPT__));
        data->format = FORMAT_void_GLenum_GLenum_GLint___GENPT__;
        data->func = glGetTexEnviv;
        data->args.a0 = target;
        data->args.a1 = pname;
        data->args.a2 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glGetTexEnviv(target, pname, params);
#ifndef direct_glGetTexEnviv
    }
#endif
END_WRAP
#endif

#ifndef skip_glGetTexEnvxv
WRAP_GLES(void, glGetTexEnvxv, GLenum target, GLenum pname, GLfixed * params)
#ifndef direct_glGetTexEnvxv
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_GLfixed___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfixed___GENPT__));
        data->format = FORMAT_void_GLenum_GLenum_GLfixed___GENPT__;
        data->func = glGetTexEnvxv;
        data->args.a0 = target;
        data->args.a1 = pname;
        data->args.a2 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glGetTexEnvxv(target, pname, params);
#ifndef direct_glGetTexEnvxv
    }
#endif
END_WRAP
#endif

#ifndef skip_glGetTexParameterfv
WRAP_GLES(void, glGetTexParameterfv, GLenum target, GLenum pname, GLfloat * params)
#ifndef direct_glGetTexParameterfv
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfloat___GENPT__));
        data->format = FORMAT_void_GLenum_GLenum_GLfloat___GENPT__;
        data->func = glGetTexParameterfv;
        data->args.a0 = target;
        data->args.a1 = pname;
        data->args.a2 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glGetTexParameterfv(target, pname, params);
#ifndef direct_glGetTexParameterfv
    }
#endif
END_WRAP
#endif

#ifndef skip_glGetTexParameteriv
WRAP_GLES(void, glGetTexParameteriv, GLenum target, GLenum pname, GLint * params)
#ifndef direct_glGetTexParameteriv
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_GLint___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint___GENPT__));
        data->format = FORMAT_void_GLenum_GLenum_GLint___GENPT__;
        data->func = glGetTexParameteriv;
        data->args.a0 = target;
        data->args.a1 = pname;
        data->args.a2 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glGetTexParameteriv(target, pname, params);
#ifndef direct_glGetTexParameteriv
    }
#endif
END_WRAP
#endif

#ifndef skip_glGetTexParameterxv
WRAP_GLES(void, glGetTexParameterxv, GLenum target, GLenum pname, GLfixed * params)
#ifndef direct_glGetTexParameterxv
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_GLfixed___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfixed___GENPT__));
        data->format = FORMAT_void_GLenum_GLenum_GLfixed___GENPT__;
        data->func = glGetTexParameterxv;
        data->args.a0 = target;
        data->args.a1 = pname;
        data->args.a2 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glGetTexParameterxv(target, pname, params);
#ifndef direct_glGetTexParameterxv
    }
#endif
END_WRAP
#endif

#ifndef skip_glHint
WRAP_GLES(void, glHint, GLenum target, GLenum mode)
#ifndef direct_glHint
    if (listCompiling) {
        PACKED_void_GLenum_GLenum *data = malloc(sizeof(PACKED_void_GLenum_GLenum));
        data->format = FORMAT_void_GLenum_GLenum;
        data->func = glHint;
        data->args.a0 = target;
        data->args.a1 = mode;
        glPushCall((void *)data);
    } else {
#endif
    gles_glHint(target, mode);
#ifndef direct_glHint
    }
#endif
END_WRAP
#endif

#ifndef skip_glIsBuffer
WRAP_GLES(GLboolean, glIsBuffer, GLuint buffer)
#ifndef direct_glIsBuffer
    if (listCompiling) {
        PACKED_GLboolean_GLuint *data = malloc(sizeof(PACKED_GLboolean_GLuint));
        data->format = FORMAT_GLboolean_GLuint;
        data->func = glIsBuffer;
        data->args.a0 = buffer;
        glPushCall((void *)data);
        return 0;
    } else {
#endif
    return gles_glIsBuffer(buffer);
#ifndef direct_glIsBuffer
    }
#endif
END_WRAP
#endif

#ifndef skip_glIsEnabled
WRAP_GLES(GLboolean, glIsEnabled, GLenum cap)
#ifndef direct_glIsEnabled
    if (listCompiling) {
        PACKED_GLboolean_GLenum *data = malloc(sizeof(PACKED_GLboolean_GLenum));
        data->format = FORMAT_GLboolean_GLenum;
        data->func = glIsEnabled;
        data->args.a0 = cap;
        glPushCall((void *)data);
        return 0;
    } else {
#endif
    return gles_glIsEnabled(cap);
#ifndef direct_glIsEnabled
    }
#endif
END_WRAP
#endif

#ifndef skip_glIsTexture
WRAP_GLES(GLboolean, glIsTexture, GLuint texture)
#ifndef direct_glIsTexture
    if (listCompiling) {
        PACKED_GLboolean_GLuint *data = malloc(sizeof(PACKED_GLboolean_GLuint));
        data->format = FORMAT_GLboolean_GLuint;
        data->func = glIsTexture;
        data->args.a0 = texture;
        glPushCall((void *)data);
        return 0;
    } else {
#endif
    return gles_glIsTexture(texture);
#ifndef direct_glIsTexture
    }
#endif
END_WRAP
#endif

#ifndef skip_glLightModelf
WRAP_GLES(void, glLightModelf, GLenum pname, GLfloat param)
#ifndef direct_glLightModelf
    if (listCompiling) {
        PACKED_void_GLenum_GLfloat *data = malloc(sizeof(PACKED_void_GLenum_GLfloat));
        data->format = FORMAT_void_GLenum_GLfloat;
        data->func = glLightModelf;
        data->args.a0 = pname;
        data->args.a1 = param;
        glPushCall((void *)data);
    } else {
#endif
    gles_glLightModelf(pname, param);
#ifndef direct_glLightModelf
    }
#endif
END_WRAP
#endif

#ifndef skip_glLightModelfv
WRAP_GLES(void, glLightModelfv, GLenum pname, const GLfloat * params)
#ifndef direct_glLightModelfv
    if (listCompiling) {
        PACKED_void_GLenum_const_GLfloat___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_const_GLfloat___GENPT__));
        data->format = FORMAT_void_GLenum_const_GLfloat___GENPT__;
        data->func = glLightModelfv;
        data->args.a0 = pname;
        data->args.a1 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glLightModelfv(pname, params);
#ifndef direct_glLightModelfv
    }
#endif
END_WRAP
#endif

#ifndef skip_glLightModelx
WRAP_GLES(void, glLightModelx, GLenum pname, GLfixed param)
#ifndef direct_glLightModelx
    if (listCompiling) {
        PACKED_void_GLenum_GLfixed *data = malloc(sizeof(PACKED_void_GLenum_GLfixed));
        data->format = FORMAT_void_GLenum_GLfixed;
        data->func = glLightModelx;
        data->args.a0 = pname;
        data->args.a1 = param;
        glPushCall((void *)data);
    } else {
#endif
    gles_glLightModelx(pname, param);
#ifndef direct_glLightModelx
    }
#endif
END_WRAP
#endif

#ifndef skip_glLightModelxv
WRAP_GLES(void, glLightModelxv, GLenum pname, const GLfixed * params)
#ifndef direct_glLightModelxv
    if (listCompiling) {
        PACKED_void_GLenum_const_GLfixed___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_const_GLfixed___GENPT__));
        data->format = FORMAT_void_GLenum_const_GLfixed___GENPT__;
        data->func = glLightModelxv;
        data->args.a0 = pname;
        data->args.a1 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glLightModelxv(pname, params);
#ifndef direct_glLightModelxv
    }
#endif
END_WRAP
#endif

#ifndef skip_glLightf
WRAP_GLES(void, glLightf, GLenum light, GLenum pname, GLfloat param)
#ifndef direct_glLightf
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_GLfloat *data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfloat));
        data->format = FORMAT_void_GLenum_GLenum_GLfloat;
        data->func = glLightf;
        data->args.a0 = light;
        data->args.a1 = pname;
        data->args.a2 = param;
        glPushCall((void *)data);
    } else {
#endif
    gles_glLightf(light, pname, param);
#ifndef direct_glLightf
    }
#endif
END_WRAP
#endif

#ifndef skip_glLightfv
WRAP_GLES(void, glLightfv, GLenum light, GLenum pname, const GLfloat * params)
#ifndef direct_glLightfv
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__));
        data->format = FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__;
        data->func = glLightfv;
        data->args.a0 = light;
        data->args.a1 = pname;
        data->args.a2 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glLightfv(light, pname, params);
#ifndef direct_glLightfv
    }
#endif
END_WRAP
#endif

#ifndef skip_glLightx
WRAP_GLES(void, glLightx, GLenum light, GLenum pname, GLfixed param)
#ifndef direct_glLightx
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_GLfixed *data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfixed));
        data->format = FORMAT_void_GLenum_GLenum_GLfixed;
        data->func = glLightx;
        data->args.a0 = light;
        data->args.a1 = pname;
        data->args.a2 = param;
        glPushCall((void *)data);
    } else {
#endif
    gles_glLightx(light, pname, param);
#ifndef direct_glLightx
    }
#endif
END_WRAP
#endif

#ifndef skip_glLightxv
WRAP_GLES(void, glLightxv, GLenum light, GLenum pname, const GLfixed * params)
#ifndef direct_glLightxv
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__));
        data->format = FORMAT_void_GLenum_GLenum_const_GLfixed___GENPT__;
        data->func = glLightxv;
        data->args.a0 = light;
        data->args.a1 = pname;
        data->args.a2 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glLightxv(light, pname, params);
#ifndef direct_glLightxv
    }
#endif
END_WRAP
#endif

#ifndef skip_glLineWidth
WRAP_GLES(void, glLineWidth, GLfloat width)
#ifndef direct_glLineWidth
    if (listCompiling) {
        PACKED_void_GLfloat *data = malloc(sizeof(PACKED_void_GLfloat));
        data->format = FORMAT_void_GLfloat;
        data->func = glLineWidth;
        data->args.a0 = width;
        glPushCall((void *)data);
    } else {
#endif
    gles_glLineWidth(width);
#ifndef direct_glLineWidth
    }
#endif
END_WRAP
#endif

#ifndef skip_glLineWidthx
WRAP_GLES(void, glLineWidthx, GLfixed width)
#ifndef direct_glLineWidthx
    if (listCompiling) {
        PACKED_void_GLfixed *data = malloc(sizeof(PACKED_void_GLfixed));
        data->format = FORMAT_void_GLfixed;
        data->func = glLineWidthx;
        data->args.a0 = width;
        glPushCall((void *)data);
    } else {
#endif
    gles_glLineWidthx(width);
#ifndef direct_glLineWidthx
    }
#endif
END_WRAP
#endif

#ifndef skip_glLoadIdentity
WRAP_GLES(void, glLoadIdentity)
#ifndef direct_glLoadIdentity
    if (listCompiling) {
        PACKED_void *data = malloc(sizeof(PACKED_void));
        data->format = FORMAT_void;
        data->func = glLoadIdentity;
        glPushCall((void *)data);
    } else {
#endif
    gles_glLoadIdentity();
#ifndef direct_glLoadIdentity
    }
#endif
END_WRAP
#endif

#ifndef skip_glLoadMatrixf
WRAP_GLES(void, glLoadMatrixf, const GLfloat * m)
#ifndef direct_glLoadMatrixf
    if (listCompiling) {
        PACKED_void_const_GLfloat___GENPT__ *data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
        data->format = FORMAT_void_const_GLfloat___GENPT__;
        data->func = glLoadMatrixf;
        data->args.a0 = m;
        glPushCall((void *)data);
    } else {
#endif
    gles_glLoadMatrixf(m);
#ifndef direct_glLoadMatrixf
    }
#endif
END_WRAP
#endif

#ifndef skip_glLoadMatrixx
WRAP_GLES(void, glLoadMatrixx, const GLfixed * m)
#ifndef direct_glLoadMatrixx
    if (listCompiling) {
        PACKED_void_const_GLfixed___GENPT__ *data = malloc(sizeof(PACKED_void_const_GLfixed___GENPT__));
        data->format = FORMAT_void_const_GLfixed___GENPT__;
        data->func = glLoadMatrixx;
        data->args.a0 = m;
        glPushCall((void *)data);
    } else {
#endif
    gles_glLoadMatrixx(m);
#ifndef direct_glLoadMatrixx
    }
#endif
END_WRAP
#endif

#ifndef skip_glLogicOp
WRAP_GLES(void, glLogicOp, GLenum opcode)
#ifndef direct_glLogicOp
    if (listCompiling) {
        PACKED_void_GLenum *data = malloc(sizeof(PACKED_void_GLenum));
        data->format = FORMAT_void_GLenum;
        data->func = glLogicOp;
        data->args.a0 = opcode;
        glPushCall((void *)data);
    } else {
#endif
    gles_glLogicOp(opcode);
#ifndef direct_glLogicOp
    }
#endif
END_WRAP
#endif

#ifndef skip_glMaterialf
WRAP_GLES(void, glMaterialf, GLenum face, GLenum pname, GLfloat param)
#ifndef direct_glMaterialf
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_GLfloat *data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfloat));
        data->format = FORMAT_void_GLenum_GLenum_GLfloat;
        data->func = glMaterialf;
        data->args.a0 = face;
        data->args.a1 = pname;
        data->args.a2 = param;
        glPushCall((void *)data);
    } else {
#endif
    gles_glMaterialf(face, pname, param);
#ifndef direct_glMaterialf
    }
#endif
END_WRAP
#endif

#ifndef skip_glMaterialfv
WRAP_GLES(void, glMaterialfv, GLenum face, GLenum pname, const GLfloat * params)
#ifndef direct_glMaterialfv
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__));
        data->format = FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__;
        data->func = glMaterialfv;
        data->args.a0 = face;
        data->args.a1 = pname;
        data->args.a2 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glMaterialfv(face, pname, params);
#ifndef direct_glMaterialfv
    }
#endif
END_WRAP
#endif

#ifndef skip_glMaterialx
WRAP_GLES(void, glMaterialx, GLenum face, GLenum pname, GLfixed param)
#ifndef direct_glMaterialx
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_GLfixed *data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfixed));
        data->format = FORMAT_void_GLenum_GLenum_GLfixed;
        data->func = glMaterialx;
        data->args.a0 = face;
        data->args.a1 = pname;
        data->args.a2 = param;
        glPushCall((void *)data);
    } else {
#endif
    gles_glMaterialx(face, pname, param);
#ifndef direct_glMaterialx
    }
#endif
END_WRAP
#endif

#ifndef skip_glMaterialxv
WRAP_GLES(void, glMaterialxv, GLenum face, GLenum pname, const GLfixed * params)
#ifndef direct_glMaterialxv
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__));
        data->format = FORMAT_void_GLenum_GLenum_const_GLfixed___GENPT__;
        data->func = glMaterialxv;
        data->args.a0 = face;
        data->args.a1 = pname;
        data->args.a2 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glMaterialxv(face, pname, params);
#ifndef direct_glMaterialxv
    }
#endif
END_WRAP
#endif

#ifndef skip_glMatrixMode
WRAP_GLES(void, glMatrixMode, GLenum mode)
#ifndef direct_glMatrixMode
    if (listCompiling) {
        PACKED_void_GLenum *data = malloc(sizeof(PACKED_void_GLenum));
        data->format = FORMAT_void_GLenum;
        data->func = glMatrixMode;
        data->args.a0 = mode;
        glPushCall((void *)data);
    } else {
#endif
    gles_glMatrixMode(mode);
#ifndef direct_glMatrixMode
    }
#endif
END_WRAP
#endif

#ifndef skip_glMultMatrixf
WRAP_GLES(void, glMultMatrixf, const GLfloat * m)
#ifndef direct_glMultMatrixf
    if (listCompiling) {
        PACKED_void_const_GLfloat___GENPT__ *data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
        data->format = FORMAT_void_const_GLfloat___GENPT__;
        data->func = glMultMatrixf;
        data->args.a0 = m;
        glPushCall((void *)data);
    } else {
#endif
    gles_glMultMatrixf(m);
#ifndef direct_glMultMatrixf
    }
#endif
END_WRAP
#endif

#ifndef skip_glMultMatrixx
WRAP_GLES(void, glMultMatrixx, const GLfixed * m)
#ifndef direct_glMultMatrixx
    if (listCompiling) {
        PACKED_void_const_GLfixed___GENPT__ *data = malloc(sizeof(PACKED_void_const_GLfixed___GENPT__));
        data->format = FORMAT_void_const_GLfixed___GENPT__;
        data->func = glMultMatrixx;
        data->args.a0 = m;
        glPushCall((void *)data);
    } else {
#endif
    gles_glMultMatrixx(m);
#ifndef direct_glMultMatrixx
    }
#endif
END_WRAP
#endif

#ifndef skip_glMultiTexCoord4f
WRAP_GLES(void, glMultiTexCoord4f, GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q)
#ifndef direct_glMultiTexCoord4f
    if (listCompiling) {
        PACKED_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat *data = malloc(sizeof(PACKED_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat));
        data->format = FORMAT_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat;
        data->func = glMultiTexCoord4f;
        data->args.a0 = target;
        data->args.a1 = s;
        data->args.a2 = t;
        data->args.a3 = r;
        data->args.a4 = q;
        glPushCall((void *)data);
    } else {
#endif
    gles_glMultiTexCoord4f(target, s, t, r, q);
#ifndef direct_glMultiTexCoord4f
    }
#endif
END_WRAP
#endif

#ifndef skip_glMultiTexCoord4x
WRAP_GLES(void, glMultiTexCoord4x, GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q)
#ifndef direct_glMultiTexCoord4x
    if (listCompiling) {
        PACKED_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed *data = malloc(sizeof(PACKED_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed));
        data->format = FORMAT_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed;
        data->func = glMultiTexCoord4x;
        data->args.a0 = target;
        data->args.a1 = s;
        data->args.a2 = t;
        data->args.a3 = r;
        data->args.a4 = q;
        glPushCall((void *)data);
    } else {
#endif
    gles_glMultiTexCoord4x(target, s, t, r, q);
#ifndef direct_glMultiTexCoord4x
    }
#endif
END_WRAP
#endif

#ifndef skip_glNormal3f
WRAP_GLES(void, glNormal3f, GLfloat nx, GLfloat ny, GLfloat nz)
#ifndef direct_glNormal3f
    if (listCompiling) {
        PACKED_void_GLfloat_GLfloat_GLfloat *data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat));
        data->format = FORMAT_void_GLfloat_GLfloat_GLfloat;
        data->func = glNormal3f;
        data->args.a0 = nx;
        data->args.a1 = ny;
        data->args.a2 = nz;
        glPushCall((void *)data);
    } else {
#endif
    gles_glNormal3f(nx, ny, nz);
#ifndef direct_glNormal3f
    }
#endif
END_WRAP
#endif

#ifndef skip_glNormal3x
WRAP_GLES(void, glNormal3x, GLfixed nx, GLfixed ny, GLfixed nz)
#ifndef direct_glNormal3x
    if (listCompiling) {
        PACKED_void_GLfixed_GLfixed_GLfixed *data = malloc(sizeof(PACKED_void_GLfixed_GLfixed_GLfixed));
        data->format = FORMAT_void_GLfixed_GLfixed_GLfixed;
        data->func = glNormal3x;
        data->args.a0 = nx;
        data->args.a1 = ny;
        data->args.a2 = nz;
        glPushCall((void *)data);
    } else {
#endif
    gles_glNormal3x(nx, ny, nz);
#ifndef direct_glNormal3x
    }
#endif
END_WRAP
#endif

#ifndef skip_glNormalPointer
WRAP_GLES(void, glNormalPointer, GLenum type, GLsizei stride, const GLvoid * pointer)
#ifndef direct_glNormalPointer
    if (listCompiling) {
        PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__));
        data->format = FORMAT_void_GLenum_GLsizei_const_GLvoid___GENPT__;
        data->func = glNormalPointer;
        data->args.a0 = type;
        data->args.a1 = stride;
        data->args.a2 = pointer;
        glPushCall((void *)data);
    } else {
#endif
    gles_glNormalPointer(type, stride, pointer);
#ifndef direct_glNormalPointer
    }
#endif
END_WRAP
#endif

#ifndef skip_glOrthof
WRAP_GLES(void, glOrthof, GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far)
#ifndef direct_glOrthof
    if (listCompiling) {
        PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat));
        data->format = FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
        data->func = glOrthof;
        data->args.a0 = left;
        data->args.a1 = right;
        data->args.a2 = bottom;
        data->args.a3 = top;
        data->args.a4 = near;
        data->args.a5 = far;
        glPushCall((void *)data);
    } else {
#endif
    gles_glOrthof(left, right, bottom, top, near, far);
#ifndef direct_glOrthof
    }
#endif
END_WRAP
#endif

#ifndef skip_glOrthox
WRAP_GLES(void, glOrthox, GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far)
#ifndef direct_glOrthox
    if (listCompiling) {
        PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed *data = malloc(sizeof(PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed));
        data->format = FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed;
        data->func = glOrthox;
        data->args.a0 = left;
        data->args.a1 = right;
        data->args.a2 = bottom;
        data->args.a3 = top;
        data->args.a4 = near;
        data->args.a5 = far;
        glPushCall((void *)data);
    } else {
#endif
    gles_glOrthox(left, right, bottom, top, near, far);
#ifndef direct_glOrthox
    }
#endif
END_WRAP
#endif

#ifndef skip_glPixelStorei
WRAP_GLES(void, glPixelStorei, GLenum pname, GLint param)
#ifndef direct_glPixelStorei
    if (listCompiling) {
        PACKED_void_GLenum_GLint *data = malloc(sizeof(PACKED_void_GLenum_GLint));
        data->format = FORMAT_void_GLenum_GLint;
        data->func = glPixelStorei;
        data->args.a0 = pname;
        data->args.a1 = param;
        glPushCall((void *)data);
    } else {
#endif
    gles_glPixelStorei(pname, param);
#ifndef direct_glPixelStorei
    }
#endif
END_WRAP
#endif

#ifndef skip_glPointParameterf
WRAP_GLES(void, glPointParameterf, GLenum pname, GLfloat param)
#ifndef direct_glPointParameterf
    if (listCompiling) {
        PACKED_void_GLenum_GLfloat *data = malloc(sizeof(PACKED_void_GLenum_GLfloat));
        data->format = FORMAT_void_GLenum_GLfloat;
        data->func = glPointParameterf;
        data->args.a0 = pname;
        data->args.a1 = param;
        glPushCall((void *)data);
    } else {
#endif
    gles_glPointParameterf(pname, param);
#ifndef direct_glPointParameterf
    }
#endif
END_WRAP
#endif

#ifndef skip_glPointParameterfv
WRAP_GLES(void, glPointParameterfv, GLenum pname, const GLfloat * params)
#ifndef direct_glPointParameterfv
    if (listCompiling) {
        PACKED_void_GLenum_const_GLfloat___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_const_GLfloat___GENPT__));
        data->format = FORMAT_void_GLenum_const_GLfloat___GENPT__;
        data->func = glPointParameterfv;
        data->args.a0 = pname;
        data->args.a1 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glPointParameterfv(pname, params);
#ifndef direct_glPointParameterfv
    }
#endif
END_WRAP
#endif

#ifndef skip_glPointParameterx
WRAP_GLES(void, glPointParameterx, GLenum pname, GLfixed param)
#ifndef direct_glPointParameterx
    if (listCompiling) {
        PACKED_void_GLenum_GLfixed *data = malloc(sizeof(PACKED_void_GLenum_GLfixed));
        data->format = FORMAT_void_GLenum_GLfixed;
        data->func = glPointParameterx;
        data->args.a0 = pname;
        data->args.a1 = param;
        glPushCall((void *)data);
    } else {
#endif
    gles_glPointParameterx(pname, param);
#ifndef direct_glPointParameterx
    }
#endif
END_WRAP
#endif

#ifndef skip_glPointParameterxv
WRAP_GLES(void, glPointParameterxv, GLenum pname, const GLfixed * params)
#ifndef direct_glPointParameterxv
    if (listCompiling) {
        PACKED_void_GLenum_const_GLfixed___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_const_GLfixed___GENPT__));
        data->format = FORMAT_void_GLenum_const_GLfixed___GENPT__;
        data->func = glPointParameterxv;
        data->args.a0 = pname;
        data->args.a1 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glPointParameterxv(pname, params);
#ifndef direct_glPointParameterxv
    }
#endif
END_WRAP
#endif

#ifndef skip_glPointSize
WRAP_GLES(void, glPointSize, GLfloat size)
#ifndef direct_glPointSize
    if (listCompiling) {
        PACKED_void_GLfloat *data = malloc(sizeof(PACKED_void_GLfloat));
        data->format = FORMAT_void_GLfloat;
        data->func = glPointSize;
        data->args.a0 = size;
        glPushCall((void *)data);
    } else {
#endif
    gles_glPointSize(size);
#ifndef direct_glPointSize
    }
#endif
END_WRAP
#endif

#ifndef skip_glPointSizePointerOES
WRAP_GLES(void, glPointSizePointerOES, GLenum type, GLsizei stride, const GLvoid * pointer)
#ifndef direct_glPointSizePointerOES
    if (listCompiling) {
        PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__));
        data->format = FORMAT_void_GLenum_GLsizei_const_GLvoid___GENPT__;
        data->func = glPointSizePointerOES;
        data->args.a0 = type;
        data->args.a1 = stride;
        data->args.a2 = pointer;
        glPushCall((void *)data);
    } else {
#endif
    gles_glPointSizePointerOES(type, stride, pointer);
#ifndef direct_glPointSizePointerOES
    }
#endif
END_WRAP
#endif

#ifndef skip_glPointSizex
WRAP_GLES(void, glPointSizex, GLfixed size)
#ifndef direct_glPointSizex
    if (listCompiling) {
        PACKED_void_GLfixed *data = malloc(sizeof(PACKED_void_GLfixed));
        data->format = FORMAT_void_GLfixed;
        data->func = glPointSizex;
        data->args.a0 = size;
        glPushCall((void *)data);
    } else {
#endif
    gles_glPointSizex(size);
#ifndef direct_glPointSizex
    }
#endif
END_WRAP
#endif

#ifndef skip_glPolygonOffset
WRAP_GLES(void, glPolygonOffset, GLfloat factor, GLfloat units)
#ifndef direct_glPolygonOffset
    if (listCompiling) {
        PACKED_void_GLfloat_GLfloat *data = malloc(sizeof(PACKED_void_GLfloat_GLfloat));
        data->format = FORMAT_void_GLfloat_GLfloat;
        data->func = glPolygonOffset;
        data->args.a0 = factor;
        data->args.a1 = units;
        glPushCall((void *)data);
    } else {
#endif
    gles_glPolygonOffset(factor, units);
#ifndef direct_glPolygonOffset
    }
#endif
END_WRAP
#endif

#ifndef skip_glPolygonOffsetx
WRAP_GLES(void, glPolygonOffsetx, GLfixed factor, GLfixed units)
#ifndef direct_glPolygonOffsetx
    if (listCompiling) {
        PACKED_void_GLfixed_GLfixed *data = malloc(sizeof(PACKED_void_GLfixed_GLfixed));
        data->format = FORMAT_void_GLfixed_GLfixed;
        data->func = glPolygonOffsetx;
        data->args.a0 = factor;
        data->args.a1 = units;
        glPushCall((void *)data);
    } else {
#endif
    gles_glPolygonOffsetx(factor, units);
#ifndef direct_glPolygonOffsetx
    }
#endif
END_WRAP
#endif

#ifndef skip_glPopMatrix
WRAP_GLES(void, glPopMatrix)
#ifndef direct_glPopMatrix
    if (listCompiling) {
        PACKED_void *data = malloc(sizeof(PACKED_void));
        data->format = FORMAT_void;
        data->func = glPopMatrix;
        glPushCall((void *)data);
    } else {
#endif
    gles_glPopMatrix();
#ifndef direct_glPopMatrix
    }
#endif
END_WRAP
#endif

#ifndef skip_glPushMatrix
WRAP_GLES(void, glPushMatrix)
#ifndef direct_glPushMatrix
    if (listCompiling) {
        PACKED_void *data = malloc(sizeof(PACKED_void));
        data->format = FORMAT_void;
        data->func = glPushMatrix;
        glPushCall((void *)data);
    } else {
#endif
    gles_glPushMatrix();
#ifndef direct_glPushMatrix
    }
#endif
END_WRAP
#endif

#ifndef skip_glReadPixels
WRAP_GLES(void, glReadPixels, GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels)
#ifndef direct_glReadPixels
    if (listCompiling) {
        PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ *data = malloc(sizeof(PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__));
        data->format = FORMAT_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__;
        data->func = glReadPixels;
        data->args.a0 = x;
        data->args.a1 = y;
        data->args.a2 = width;
        data->args.a3 = height;
        data->args.a4 = format;
        data->args.a5 = type;
        data->args.a6 = pixels;
        glPushCall((void *)data);
    } else {
#endif
    gles_glReadPixels(x, y, width, height, format, type, pixels);
#ifndef direct_glReadPixels
    }
#endif
END_WRAP
#endif

#ifndef skip_glRotatef
WRAP_GLES(void, glRotatef, GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
#ifndef direct_glRotatef
    if (listCompiling) {
        PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat *data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat));
        data->format = FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat;
        data->func = glRotatef;
        data->args.a0 = angle;
        data->args.a1 = x;
        data->args.a2 = y;
        data->args.a3 = z;
        glPushCall((void *)data);
    } else {
#endif
    gles_glRotatef(angle, x, y, z);
#ifndef direct_glRotatef
    }
#endif
END_WRAP
#endif

#ifndef skip_glRotatex
WRAP_GLES(void, glRotatex, GLfixed angle, GLfixed x, GLfixed y, GLfixed z)
#ifndef direct_glRotatex
    if (listCompiling) {
        PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed *data = malloc(sizeof(PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed));
        data->format = FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed;
        data->func = glRotatex;
        data->args.a0 = angle;
        data->args.a1 = x;
        data->args.a2 = y;
        data->args.a3 = z;
        glPushCall((void *)data);
    } else {
#endif
    gles_glRotatex(angle, x, y, z);
#ifndef direct_glRotatex
    }
#endif
END_WRAP
#endif

#ifndef skip_glSampleCoverage
WRAP_GLES(void, glSampleCoverage, GLclampf value, GLboolean invert)
#ifndef direct_glSampleCoverage
    if (listCompiling) {
        PACKED_void_GLclampf_GLboolean *data = malloc(sizeof(PACKED_void_GLclampf_GLboolean));
        data->format = FORMAT_void_GLclampf_GLboolean;
        data->func = glSampleCoverage;
        data->args.a0 = value;
        data->args.a1 = invert;
        glPushCall((void *)data);
    } else {
#endif
    gles_glSampleCoverage(value, invert);
#ifndef direct_glSampleCoverage
    }
#endif
END_WRAP
#endif

#ifndef skip_glSampleCoveragex
WRAP_GLES(void, glSampleCoveragex, GLclampx value, GLboolean invert)
#ifndef direct_glSampleCoveragex
    if (listCompiling) {
        PACKED_void_GLclampx_GLboolean *data = malloc(sizeof(PACKED_void_GLclampx_GLboolean));
        data->format = FORMAT_void_GLclampx_GLboolean;
        data->func = glSampleCoveragex;
        data->args.a0 = value;
        data->args.a1 = invert;
        glPushCall((void *)data);
    } else {
#endif
    gles_glSampleCoveragex(value, invert);
#ifndef direct_glSampleCoveragex
    }
#endif
END_WRAP
#endif

#ifndef skip_glScalef
WRAP_GLES(void, glScalef, GLfloat x, GLfloat y, GLfloat z)
#ifndef direct_glScalef
    if (listCompiling) {
        PACKED_void_GLfloat_GLfloat_GLfloat *data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat));
        data->format = FORMAT_void_GLfloat_GLfloat_GLfloat;
        data->func = glScalef;
        data->args.a0 = x;
        data->args.a1 = y;
        data->args.a2 = z;
        glPushCall((void *)data);
    } else {
#endif
    gles_glScalef(x, y, z);
#ifndef direct_glScalef
    }
#endif
END_WRAP
#endif

#ifndef skip_glScalex
WRAP_GLES(void, glScalex, GLfixed x, GLfixed y, GLfixed z)
#ifndef direct_glScalex
    if (listCompiling) {
        PACKED_void_GLfixed_GLfixed_GLfixed *data = malloc(sizeof(PACKED_void_GLfixed_GLfixed_GLfixed));
        data->format = FORMAT_void_GLfixed_GLfixed_GLfixed;
        data->func = glScalex;
        data->args.a0 = x;
        data->args.a1 = y;
        data->args.a2 = z;
        glPushCall((void *)data);
    } else {
#endif
    gles_glScalex(x, y, z);
#ifndef direct_glScalex
    }
#endif
END_WRAP
#endif

#ifndef skip_glScissor
WRAP_GLES(void, glScissor, GLint x, GLint y, GLsizei width, GLsizei height)
#ifndef direct_glScissor
    if (listCompiling) {
        PACKED_void_GLint_GLint_GLsizei_GLsizei *data = malloc(sizeof(PACKED_void_GLint_GLint_GLsizei_GLsizei));
        data->format = FORMAT_void_GLint_GLint_GLsizei_GLsizei;
        data->func = glScissor;
        data->args.a0 = x;
        data->args.a1 = y;
        data->args.a2 = width;
        data->args.a3 = height;
        glPushCall((void *)data);
    } else {
#endif
    gles_glScissor(x, y, width, height);
#ifndef direct_glScissor
    }
#endif
END_WRAP
#endif

#ifndef skip_glShadeModel
WRAP_GLES(void, glShadeModel, GLenum mode)
#ifndef direct_glShadeModel
    if (listCompiling) {
        PACKED_void_GLenum *data = malloc(sizeof(PACKED_void_GLenum));
        data->format = FORMAT_void_GLenum;
        data->func = glShadeModel;
        data->args.a0 = mode;
        glPushCall((void *)data);
    } else {
#endif
    gles_glShadeModel(mode);
#ifndef direct_glShadeModel
    }
#endif
END_WRAP
#endif

#ifndef skip_glStencilFunc
WRAP_GLES(void, glStencilFunc, GLenum func, GLint ref, GLuint mask)
#ifndef direct_glStencilFunc
    if (listCompiling) {
        PACKED_void_GLenum_GLint_GLuint *data = malloc(sizeof(PACKED_void_GLenum_GLint_GLuint));
        data->format = FORMAT_void_GLenum_GLint_GLuint;
        data->func = glStencilFunc;
        data->args.a0 = func;
        data->args.a1 = ref;
        data->args.a2 = mask;
        glPushCall((void *)data);
    } else {
#endif
    gles_glStencilFunc(func, ref, mask);
#ifndef direct_glStencilFunc
    }
#endif
END_WRAP
#endif

#ifndef skip_glStencilMask
WRAP_GLES(void, glStencilMask, GLuint mask)
#ifndef direct_glStencilMask
    if (listCompiling) {
        PACKED_void_GLuint *data = malloc(sizeof(PACKED_void_GLuint));
        data->format = FORMAT_void_GLuint;
        data->func = glStencilMask;
        data->args.a0 = mask;
        glPushCall((void *)data);
    } else {
#endif
    gles_glStencilMask(mask);
#ifndef direct_glStencilMask
    }
#endif
END_WRAP
#endif

#ifndef skip_glStencilOp
WRAP_GLES(void, glStencilOp, GLenum fail, GLenum zfail, GLenum zpass)
#ifndef direct_glStencilOp
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_GLenum *data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLenum));
        data->format = FORMAT_void_GLenum_GLenum_GLenum;
        data->func = glStencilOp;
        data->args.a0 = fail;
        data->args.a1 = zfail;
        data->args.a2 = zpass;
        glPushCall((void *)data);
    } else {
#endif
    gles_glStencilOp(fail, zfail, zpass);
#ifndef direct_glStencilOp
    }
#endif
END_WRAP
#endif

#ifndef skip_glTexCoordPointer
WRAP_GLES(void, glTexCoordPointer, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer)
#ifndef direct_glTexCoordPointer
    if (listCompiling) {
        PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *data = malloc(sizeof(PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__));
        data->format = FORMAT_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__;
        data->func = glTexCoordPointer;
        data->args.a0 = size;
        data->args.a1 = type;
        data->args.a2 = stride;
        data->args.a3 = pointer;
        glPushCall((void *)data);
    } else {
#endif
    gles_glTexCoordPointer(size, type, stride, pointer);
#ifndef direct_glTexCoordPointer
    }
#endif
END_WRAP
#endif

#ifndef skip_glTexEnvf
WRAP_GLES(void, glTexEnvf, GLenum target, GLenum pname, GLfloat param)
#ifndef direct_glTexEnvf
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_GLfloat *data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfloat));
        data->format = FORMAT_void_GLenum_GLenum_GLfloat;
        data->func = glTexEnvf;
        data->args.a0 = target;
        data->args.a1 = pname;
        data->args.a2 = param;
        glPushCall((void *)data);
    } else {
#endif
    gles_glTexEnvf(target, pname, param);
#ifndef direct_glTexEnvf
    }
#endif
END_WRAP
#endif

#ifndef skip_glTexEnvfv
WRAP_GLES(void, glTexEnvfv, GLenum target, GLenum pname, const GLfloat * params)
#ifndef direct_glTexEnvfv
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__));
        data->format = FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__;
        data->func = glTexEnvfv;
        data->args.a0 = target;
        data->args.a1 = pname;
        data->args.a2 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glTexEnvfv(target, pname, params);
#ifndef direct_glTexEnvfv
    }
#endif
END_WRAP
#endif

#ifndef skip_glTexEnvi
WRAP_GLES(void, glTexEnvi, GLenum target, GLenum pname, GLint param)
#ifndef direct_glTexEnvi
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_GLint *data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint));
        data->format = FORMAT_void_GLenum_GLenum_GLint;
        data->func = glTexEnvi;
        data->args.a0 = target;
        data->args.a1 = pname;
        data->args.a2 = param;
        glPushCall((void *)data);
    } else {
#endif
    gles_glTexEnvi(target, pname, param);
#ifndef direct_glTexEnvi
    }
#endif
END_WRAP
#endif

#ifndef skip_glTexEnviv
WRAP_GLES(void, glTexEnviv, GLenum target, GLenum pname, const GLint * params)
#ifndef direct_glTexEnviv
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_const_GLint___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLint___GENPT__));
        data->format = FORMAT_void_GLenum_GLenum_const_GLint___GENPT__;
        data->func = glTexEnviv;
        data->args.a0 = target;
        data->args.a1 = pname;
        data->args.a2 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glTexEnviv(target, pname, params);
#ifndef direct_glTexEnviv
    }
#endif
END_WRAP
#endif

#ifndef skip_glTexEnvx
WRAP_GLES(void, glTexEnvx, GLenum target, GLenum pname, GLfixed param)
#ifndef direct_glTexEnvx
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_GLfixed *data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfixed));
        data->format = FORMAT_void_GLenum_GLenum_GLfixed;
        data->func = glTexEnvx;
        data->args.a0 = target;
        data->args.a1 = pname;
        data->args.a2 = param;
        glPushCall((void *)data);
    } else {
#endif
    gles_glTexEnvx(target, pname, param);
#ifndef direct_glTexEnvx
    }
#endif
END_WRAP
#endif

#ifndef skip_glTexEnvxv
WRAP_GLES(void, glTexEnvxv, GLenum target, GLenum pname, const GLfixed * params)
#ifndef direct_glTexEnvxv
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__));
        data->format = FORMAT_void_GLenum_GLenum_const_GLfixed___GENPT__;
        data->func = glTexEnvxv;
        data->args.a0 = target;
        data->args.a1 = pname;
        data->args.a2 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glTexEnvxv(target, pname, params);
#ifndef direct_glTexEnvxv
    }
#endif
END_WRAP
#endif

#ifndef skip_glTexImage2D
WRAP_GLES(void, glTexImage2D, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels)
#ifndef direct_glTexImage2D
    if (listCompiling) {
        PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__));
        data->format = FORMAT_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__;
        data->func = glTexImage2D;
        data->args.a0 = target;
        data->args.a1 = level;
        data->args.a2 = internalformat;
        data->args.a3 = width;
        data->args.a4 = height;
        data->args.a5 = border;
        data->args.a6 = format;
        data->args.a7 = type;
        data->args.a8 = pixels;
        glPushCall((void *)data);
    } else {
#endif
    gles_glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
#ifndef direct_glTexImage2D
    }
#endif
END_WRAP
#endif

#ifndef skip_glTexParameterf
WRAP_GLES(void, glTexParameterf, GLenum target, GLenum pname, GLfloat param)
#ifndef direct_glTexParameterf
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_GLfloat *data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfloat));
        data->format = FORMAT_void_GLenum_GLenum_GLfloat;
        data->func = glTexParameterf;
        data->args.a0 = target;
        data->args.a1 = pname;
        data->args.a2 = param;
        glPushCall((void *)data);
    } else {
#endif
    gles_glTexParameterf(target, pname, param);
#ifndef direct_glTexParameterf
    }
#endif
END_WRAP
#endif

#ifndef skip_glTexParameterfv
WRAP_GLES(void, glTexParameterfv, GLenum target, GLenum pname, const GLfloat * params)
#ifndef direct_glTexParameterfv
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__));
        data->format = FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__;
        data->func = glTexParameterfv;
        data->args.a0 = target;
        data->args.a1 = pname;
        data->args.a2 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glTexParameterfv(target, pname, params);
#ifndef direct_glTexParameterfv
    }
#endif
END_WRAP
#endif

#ifndef skip_glTexParameteri
WRAP_GLES(void, glTexParameteri, GLenum target, GLenum pname, GLint param)
#ifndef direct_glTexParameteri
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_GLint *data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint));
        data->format = FORMAT_void_GLenum_GLenum_GLint;
        data->func = glTexParameteri;
        data->args.a0 = target;
        data->args.a1 = pname;
        data->args.a2 = param;
        glPushCall((void *)data);
    } else {
#endif
    gles_glTexParameteri(target, pname, param);
#ifndef direct_glTexParameteri
    }
#endif
END_WRAP
#endif

#ifndef skip_glTexParameteriv
WRAP_GLES(void, glTexParameteriv, GLenum target, GLenum pname, const GLint * params)
#ifndef direct_glTexParameteriv
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_const_GLint___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLint___GENPT__));
        data->format = FORMAT_void_GLenum_GLenum_const_GLint___GENPT__;
        data->func = glTexParameteriv;
        data->args.a0 = target;
        data->args.a1 = pname;
        data->args.a2 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glTexParameteriv(target, pname, params);
#ifndef direct_glTexParameteriv
    }
#endif
END_WRAP
#endif

#ifndef skip_glTexParameterx
WRAP_GLES(void, glTexParameterx, GLenum target, GLenum pname, GLfixed param)
#ifndef direct_glTexParameterx
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_GLfixed *data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfixed));
        data->format = FORMAT_void_GLenum_GLenum_GLfixed;
        data->func = glTexParameterx;
        data->args.a0 = target;
        data->args.a1 = pname;
        data->args.a2 = param;
        glPushCall((void *)data);
    } else {
#endif
    gles_glTexParameterx(target, pname, param);
#ifndef direct_glTexParameterx
    }
#endif
END_WRAP
#endif

#ifndef skip_glTexParameterxv
WRAP_GLES(void, glTexParameterxv, GLenum target, GLenum pname, const GLfixed * params)
#ifndef direct_glTexParameterxv
    if (listCompiling) {
        PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__));
        data->format = FORMAT_void_GLenum_GLenum_const_GLfixed___GENPT__;
        data->func = glTexParameterxv;
        data->args.a0 = target;
        data->args.a1 = pname;
        data->args.a2 = params;
        glPushCall((void *)data);
    } else {
#endif
    gles_glTexParameterxv(target, pname, params);
#ifndef direct_glTexParameterxv
    }
#endif
END_WRAP
#endif

#ifndef skip_glTexSubImage2D
WRAP_GLES(void, glTexSubImage2D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels)
#ifndef direct_glTexSubImage2D
    if (listCompiling) {
        PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *data = malloc(sizeof(PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__));
        data->format = FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
        data->func = glTexSubImage2D;
        data->args.a0 = target;
        data->args.a1 = level;
        data->args.a2 = xoffset;
        data->args.a3 = yoffset;
        data->args.a4 = width;
        data->args.a5 = height;
        data->args.a6 = format;
        data->args.a7 = type;
        data->args.a8 = pixels;
        glPushCall((void *)data);
    } else {
#endif
    gles_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
#ifndef direct_glTexSubImage2D
    }
#endif
END_WRAP
#endif

#ifndef skip_glTranslatef
WRAP_GLES(void, glTranslatef, GLfloat x, GLfloat y, GLfloat z)
#ifndef direct_glTranslatef
    if (listCompiling) {
        PACKED_void_GLfloat_GLfloat_GLfloat *data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat));
        data->format = FORMAT_void_GLfloat_GLfloat_GLfloat;
        data->func = glTranslatef;
        data->args.a0 = x;
        data->args.a1 = y;
        data->args.a2 = z;
        glPushCall((void *)data);
    } else {
#endif
    gles_glTranslatef(x, y, z);
#ifndef direct_glTranslatef
    }
#endif
END_WRAP
#endif

#ifndef skip_glTranslatex
WRAP_GLES(void, glTranslatex, GLfixed x, GLfixed y, GLfixed z)
#ifndef direct_glTranslatex
    if (listCompiling) {
        PACKED_void_GLfixed_GLfixed_GLfixed *data = malloc(sizeof(PACKED_void_GLfixed_GLfixed_GLfixed));
        data->format = FORMAT_void_GLfixed_GLfixed_GLfixed;
        data->func = glTranslatex;
        data->args.a0 = x;
        data->args.a1 = y;
        data->args.a2 = z;
        glPushCall((void *)data);
    } else {
#endif
    gles_glTranslatex(x, y, z);
#ifndef direct_glTranslatex
    }
#endif
END_WRAP
#endif

#ifndef skip_glVertexPointer
WRAP_GLES(void, glVertexPointer, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer)
#ifndef direct_glVertexPointer
    if (listCompiling) {
        PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *data = malloc(sizeof(PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__));
        data->format = FORMAT_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__;
        data->func = glVertexPointer;
        data->args.a0 = size;
        data->args.a1 = type;
        data->args.a2 = stride;
        data->args.a3 = pointer;
        glPushCall((void *)data);
    } else {
#endif
    gles_glVertexPointer(size, type, stride, pointer);
#ifndef direct_glVertexPointer
    }
#endif
END_WRAP
#endif

#ifndef skip_glViewport
WRAP_GLES(void, glViewport, GLint x, GLint y, GLsizei width, GLsizei height)
#ifndef direct_glViewport
    if (listCompiling) {
        PACKED_void_GLint_GLint_GLsizei_GLsizei *data = malloc(sizeof(PACKED_void_GLint_GLint_GLsizei_GLsizei));
        data->format = FORMAT_void_GLint_GLint_GLsizei_GLsizei;
        data->func = glViewport;
        data->args.a0 = x;
        data->args.a1 = y;
        data->args.a2 = width;
        data->args.a3 = height;
        glPushCall((void *)data);
    } else {
#endif
    gles_glViewport(x, y, width, height);
#ifndef direct_glViewport
    }
#endif
END_WRAP
#endif
