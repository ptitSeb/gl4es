#ifdef USE_ES2
#include "gles2.h"

void glPackedCall(const UnknownCall *packed) {
    switch (packed->format) {
        case FORMAT_void_GLenum: {
            PACKED_void_GLenum *unpacked = (PACKED_void_GLenum *)packed;
            ARGS_void_GLenum args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLuint_GLuint: {
            PACKED_void_GLuint_GLuint *unpacked = (PACKED_void_GLuint_GLuint *)packed;
            ARGS_void_GLuint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLuint_const_GLchar___GENPT__: {
            PACKED_void_GLuint_GLuint_const_GLchar___GENPT__ *unpacked = (PACKED_void_GLuint_GLuint_const_GLchar___GENPT__ *)packed;
            ARGS_void_GLuint_GLuint_const_GLchar___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLuint: {
            PACKED_void_GLenum_GLuint *unpacked = (PACKED_void_GLenum_GLuint *)packed;
            ARGS_void_GLenum_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLclampf_GLclampf_GLclampf_GLclampf: {
            PACKED_void_GLclampf_GLclampf_GLclampf_GLclampf *unpacked = (PACKED_void_GLclampf_GLclampf_GLclampf_GLclampf *)packed;
            ARGS_void_GLclampf_GLclampf_GLclampf_GLclampf args = unpacked->args;
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
        case FORMAT_GLenum_GLenum: {
            PACKED_GLenum_GLenum *unpacked = (PACKED_GLenum_GLenum *)packed;
            ARGS_GLenum_GLenum args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLbitfield: {
            PACKED_void_GLbitfield *unpacked = (PACKED_void_GLbitfield *)packed;
            ARGS_void_GLbitfield args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLclampf: {
            PACKED_void_GLclampf *unpacked = (PACKED_void_GLclampf *)packed;
            ARGS_void_GLclampf args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLint: {
            PACKED_void_GLint *unpacked = (PACKED_void_GLint *)packed;
            ARGS_void_GLint args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLboolean_GLboolean_GLboolean_GLboolean: {
            PACKED_void_GLboolean_GLboolean_GLboolean_GLboolean *unpacked = (PACKED_void_GLboolean_GLboolean_GLboolean_GLboolean *)packed;
            ARGS_void_GLboolean_GLboolean_GLboolean_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint: {
            PACKED_void_GLuint *unpacked = (PACKED_void_GLuint *)packed;
            ARGS_void_GLuint args = unpacked->args;
            unpacked->func(args.a1);
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
        case FORMAT_GLuint: {
            PACKED_GLuint *unpacked = (PACKED_GLuint *)packed;
            ARGS_GLuint args = unpacked->args;
            unpacked->func();
            break;
        }
        case FORMAT_GLuint_GLenum: {
            PACKED_GLuint_GLenum *unpacked = (PACKED_GLuint_GLenum *)packed;
            ARGS_GLuint_GLenum args = unpacked->args;
            unpacked->func(args.a1);
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
        case FORMAT_void_GLenum_GLenum_GLenum_GLuint: {
            PACKED_void_GLenum_GLenum_GLenum_GLuint *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLuint *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLenum_GLuint_GLint: {
            PACKED_void_GLenum_GLenum_GLenum_GLuint_GLint *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLuint_GLint *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLuint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLsizei_GLuint___GENPT__: {
            PACKED_void_GLsizei_GLuint___GENPT__ *unpacked = (PACKED_void_GLsizei_GLuint___GENPT__ *)packed;
            ARGS_void_GLsizei_GLuint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLuint_GLsizei_GLsizei___GENPT___GLint___GENPT___GLenum___GENPT___GLchar___GENPT__: {
            PACKED_void_GLuint_GLuint_GLsizei_GLsizei___GENPT___GLint___GENPT___GLenum___GENPT___GLchar___GENPT__ *unpacked = (PACKED_void_GLuint_GLuint_GLsizei_GLsizei___GENPT___GLint___GENPT___GLenum___GENPT___GLchar___GENPT__ *)packed;
            ARGS_void_GLuint_GLuint_GLsizei_GLsizei___GENPT___GLint___GENPT___GLenum___GENPT___GLchar___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLsizei___GENPT___GLuint___GENPT__: {
            PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLuint___GENPT__ *unpacked = (PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLuint___GENPT__ *)packed;
            ARGS_void_GLuint_GLsizei_GLsizei___GENPT___GLuint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_GLint_GLuint_const_GLchar___GENPT__: {
            PACKED_GLint_GLuint_const_GLchar___GENPT__ *unpacked = (PACKED_GLint_GLuint_const_GLchar___GENPT__ *)packed;
            ARGS_GLint_GLuint_const_GLchar___GENPT__ args = unpacked->args;
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
        case FORMAT_void_GLenum_GLenum_GLenum_GLint___GENPT__: {
            PACKED_void_GLenum_GLenum_GLenum_GLint___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLenum_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLint___GENPT__: {
            PACKED_void_GLenum_GLint___GENPT__ *unpacked = (PACKED_void_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__: {
            PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__ *unpacked = (PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__ *)packed;
            ARGS_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLint___GENPT__: {
            PACKED_void_GLuint_GLenum_GLint___GENPT__ *unpacked = (PACKED_void_GLuint_GLenum_GLint___GENPT__ *)packed;
            ARGS_void_GLuint_GLenum_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLint___GENPT___GLint___GENPT__: {
            PACKED_void_GLenum_GLenum_GLint___GENPT___GLint___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLint___GENPT___GLint___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLint___GENPT___GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_const_GLubyte___GENPT___GLenum: {
            PACKED_const_GLubyte___GENPT___GLenum *unpacked = (PACKED_const_GLubyte___GENPT___GLenum *)packed;
            ARGS_const_GLubyte___GENPT___GLenum args = unpacked->args;
            unpacked->func(args.a1);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLfloat___GENPT__: {
            PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *unpacked = (PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLfloat___GENPT__: {
            PACKED_void_GLuint_GLint_GLfloat___GENPT__ *unpacked = (PACKED_void_GLuint_GLint_GLfloat___GENPT__ *)packed;
            ARGS_void_GLuint_GLint_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLint___GENPT__: {
            PACKED_void_GLuint_GLint_GLint___GENPT__ *unpacked = (PACKED_void_GLuint_GLint_GLint___GENPT__ *)packed;
            ARGS_void_GLuint_GLint_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLvoid___GENPT____GENPT__: {
            PACKED_void_GLuint_GLenum_GLvoid___GENPT____GENPT__ *unpacked = (PACKED_void_GLuint_GLenum_GLvoid___GENPT____GENPT__ *)packed;
            ARGS_void_GLuint_GLenum_GLvoid___GENPT____GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLenum_GLfloat___GENPT__: {
            PACKED_void_GLuint_GLenum_GLfloat___GENPT__ *unpacked = (PACKED_void_GLuint_GLenum_GLfloat___GENPT__ *)packed;
            ARGS_void_GLuint_GLenum_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
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
        case FORMAT_void_GLfloat: {
            PACKED_void_GLfloat *unpacked = (PACKED_void_GLfloat *)packed;
            ARGS_void_GLfloat args = unpacked->args;
            unpacked->func(args.a1);
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
        case FORMAT_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__: {
            PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ *unpacked = (PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ *)packed;
            ARGS_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7);
            break;
        }
        case FORMAT_void_GLenum_GLenum_GLsizei_GLsizei: {
            PACKED_void_GLenum_GLenum_GLsizei_GLsizei *unpacked = (PACKED_void_GLenum_GLenum_GLsizei_GLsizei *)packed;
            ARGS_void_GLenum_GLenum_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLclampf_GLboolean: {
            PACKED_void_GLclampf_GLboolean *unpacked = (PACKED_void_GLclampf_GLboolean *)packed;
            ARGS_void_GLclampf_GLboolean args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLint_GLint_GLsizei_GLsizei: {
            PACKED_void_GLint_GLint_GLsizei_GLsizei *unpacked = (PACKED_void_GLint_GLint_GLsizei_GLsizei *)packed;
            ARGS_void_GLint_GLint_GLsizei_GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLsizei_const_GLuint___GENPT___GLenum_const_GLvoid___GENPT___GLsizei: {
            PACKED_void_GLsizei_const_GLuint___GENPT___GLenum_const_GLvoid___GENPT___GLsizei *unpacked = (PACKED_void_GLsizei_const_GLuint___GENPT___GLenum_const_GLvoid___GENPT___GLsizei *)packed;
            ARGS_void_GLsizei_const_GLuint___GENPT___GLenum_const_GLvoid___GENPT___GLsizei args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLsizei_const_GLchar___GENPT___const___GENPT___const_GLint___GENPT__: {
            PACKED_void_GLuint_GLsizei_const_GLchar___GENPT___const___GENPT___const_GLint___GENPT__ *unpacked = (PACKED_void_GLuint_GLsizei_const_GLchar___GENPT___const___GENPT___const_GLint___GENPT__ *)packed;
            ARGS_void_GLuint_GLsizei_const_GLchar___GENPT___const___GENPT___const_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLenum_GLint_GLuint: {
            PACKED_void_GLenum_GLint_GLuint *unpacked = (PACKED_void_GLenum_GLint_GLuint *)packed;
            ARGS_void_GLenum_GLint_GLuint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
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
        case FORMAT_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
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
        case FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__: {
            PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6, args.a7, args.a8, args.a9);
            break;
        }
        case FORMAT_void_GLint_GLfloat: {
            PACKED_void_GLint_GLfloat *unpacked = (PACKED_void_GLint_GLfloat *)packed;
            ARGS_void_GLint_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLint_GLsizei_const_GLfloat___GENPT__: {
            PACKED_void_GLint_GLsizei_const_GLfloat___GENPT__ *unpacked = (PACKED_void_GLint_GLsizei_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLint_GLsizei_const_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLint_GLint: {
            PACKED_void_GLint_GLint *unpacked = (PACKED_void_GLint_GLint *)packed;
            ARGS_void_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLint_GLsizei_const_GLint___GENPT__: {
            PACKED_void_GLint_GLsizei_const_GLint___GENPT__ *unpacked = (PACKED_void_GLint_GLsizei_const_GLint___GENPT__ *)packed;
            ARGS_void_GLint_GLsizei_const_GLint___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLint_GLfloat_GLfloat: {
            PACKED_void_GLint_GLfloat_GLfloat *unpacked = (PACKED_void_GLint_GLfloat_GLfloat *)packed;
            ARGS_void_GLint_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLint_GLint_GLint: {
            PACKED_void_GLint_GLint_GLint *unpacked = (PACKED_void_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLint_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLint_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLint_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLint_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLint_GLint_GLint_GLint: {
            PACKED_void_GLint_GLint_GLint_GLint *unpacked = (PACKED_void_GLint_GLint_GLint_GLint *)packed;
            ARGS_void_GLint_GLint_GLint_GLint args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
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
        case FORMAT_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__: {
            PACKED_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__ *unpacked = (PACKED_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLfloat: {
            PACKED_void_GLuint_GLfloat *unpacked = (PACKED_void_GLuint_GLfloat *)packed;
            ARGS_void_GLuint_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_const_GLfloat___GENPT__: {
            PACKED_void_GLuint_const_GLfloat___GENPT__ *unpacked = (PACKED_void_GLuint_const_GLfloat___GENPT__ *)packed;
            ARGS_void_GLuint_const_GLfloat___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2);
            break;
        }
        case FORMAT_void_GLuint_GLfloat_GLfloat: {
            PACKED_void_GLuint_GLfloat_GLfloat *unpacked = (PACKED_void_GLuint_GLfloat_GLfloat *)packed;
            ARGS_void_GLuint_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3);
            break;
        }
        case FORMAT_void_GLuint_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLuint_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLuint_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLuint_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4);
            break;
        }
        case FORMAT_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat: {
            PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat *unpacked = (PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat *)packed;
            ARGS_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5);
            break;
        }
        case FORMAT_void_GLuint_GLint_GLenum_GLboolean_GLsizei_const_GLvoid___GENPT__: {
            PACKED_void_GLuint_GLint_GLenum_GLboolean_GLsizei_const_GLvoid___GENPT__ *unpacked = (PACKED_void_GLuint_GLint_GLenum_GLboolean_GLsizei_const_GLvoid___GENPT__ *)packed;
            ARGS_void_GLuint_GLint_GLenum_GLboolean_GLsizei_const_GLvoid___GENPT__ args = unpacked->args;
            unpacked->func(args.a1, args.a2, args.a3, args.a4, args.a5, args.a6);
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
#ifndef skip_glAttachShader
void glAttachShader(GLuint program, GLuint shader) {
    LOAD_GLES(void, glAttachShader, GLuint program, GLuint shader);
#ifndef direct_glAttachShader
    if (state.list.compiling) {
        push_glAttachShader(program, shader);
    } else {
#endif
        gles_glAttachShader(program, shader);

#ifndef direct_glAttachShader
    }
#endif
}
#endif
#ifndef skip_glBindAttribLocation
void glBindAttribLocation(GLuint program, GLuint index, const GLchar * name) {
    LOAD_GLES(void, glBindAttribLocation, GLuint program, GLuint index, const GLchar * name);
#ifndef direct_glBindAttribLocation
    if (state.list.compiling) {
        push_glBindAttribLocation(program, index, name);
    } else {
#endif
        gles_glBindAttribLocation(program, index, name);

#ifndef direct_glBindAttribLocation
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
#ifndef skip_glBindFramebuffer
void glBindFramebuffer(GLenum target, GLuint framebuffer) {
    LOAD_GLES(void, glBindFramebuffer, GLenum target, GLuint framebuffer);
#ifndef direct_glBindFramebuffer
    if (state.list.compiling) {
        push_glBindFramebuffer(target, framebuffer);
    } else {
#endif
        gles_glBindFramebuffer(target, framebuffer);

#ifndef direct_glBindFramebuffer
    }
#endif
}
#endif
#ifndef skip_glBindRenderbuffer
void glBindRenderbuffer(GLenum target, GLuint renderbuffer) {
    LOAD_GLES(void, glBindRenderbuffer, GLenum target, GLuint renderbuffer);
#ifndef direct_glBindRenderbuffer
    if (state.list.compiling) {
        push_glBindRenderbuffer(target, renderbuffer);
    } else {
#endif
        gles_glBindRenderbuffer(target, renderbuffer);

#ifndef direct_glBindRenderbuffer
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
#ifndef skip_glBlendColor
void glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
    LOAD_GLES(void, glBlendColor, GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
#ifndef direct_glBlendColor
    if (state.list.compiling) {
        push_glBlendColor(red, green, blue, alpha);
    } else {
#endif
        gles_glBlendColor(red, green, blue, alpha);

#ifndef direct_glBlendColor
    }
#endif
}
#endif
#ifndef skip_glBlendEquation
void glBlendEquation(GLenum mode) {
    LOAD_GLES(void, glBlendEquation, GLenum mode);
#ifndef direct_glBlendEquation
    if (state.list.compiling) {
        push_glBlendEquation(mode);
    } else {
#endif
        gles_glBlendEquation(mode);

#ifndef direct_glBlendEquation
    }
#endif
}
#endif
#ifndef skip_glBlendEquationSeparate
void glBlendEquationSeparate(GLenum modeRGB, GLenum modeA) {
    LOAD_GLES(void, glBlendEquationSeparate, GLenum modeRGB, GLenum modeA);
#ifndef direct_glBlendEquationSeparate
    if (state.list.compiling) {
        push_glBlendEquationSeparate(modeRGB, modeA);
    } else {
#endif
        gles_glBlendEquationSeparate(modeRGB, modeA);

#ifndef direct_glBlendEquationSeparate
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
#ifndef skip_glBlendFuncSeparate
void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
    LOAD_GLES(void, glBlendFuncSeparate, GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
#ifndef direct_glBlendFuncSeparate
    if (state.list.compiling) {
        push_glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
    } else {
#endif
        gles_glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);

#ifndef direct_glBlendFuncSeparate
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
#ifndef skip_glCheckFramebufferStatus
GLenum glCheckFramebufferStatus(GLenum target) {
    LOAD_GLES(GLenum, glCheckFramebufferStatus, GLenum target);
#ifndef direct_glCheckFramebufferStatus
    if (state.list.compiling) {
        push_glCheckFramebufferStatus(target);
        return 0;
    } else {
#endif
        return gles_glCheckFramebufferStatus(target);

#ifndef direct_glCheckFramebufferStatus
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
#ifndef skip_glCompileShader
void glCompileShader(GLuint shader) {
    LOAD_GLES(void, glCompileShader, GLuint shader);
#ifndef direct_glCompileShader
    if (state.list.compiling) {
        push_glCompileShader(shader);
    } else {
#endif
        gles_glCompileShader(shader);

#ifndef direct_glCompileShader
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
#ifndef skip_glCreateProgram
GLuint glCreateProgram() {
    LOAD_GLES(GLuint, glCreateProgram);
#ifndef direct_glCreateProgram
    if (state.list.compiling) {
        push_glCreateProgram();
        return 0;
    } else {
#endif
        return gles_glCreateProgram();

#ifndef direct_glCreateProgram
    }
#endif
}
#endif
#ifndef skip_glCreateShader
GLuint glCreateShader(GLenum type) {
    LOAD_GLES(GLuint, glCreateShader, GLenum type);
#ifndef direct_glCreateShader
    if (state.list.compiling) {
        push_glCreateShader(type);
        return 0;
    } else {
#endif
        return gles_glCreateShader(type);

#ifndef direct_glCreateShader
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
void glDeleteBuffers(GLsizei n, const GLuint * buffer) {
    LOAD_GLES(void, glDeleteBuffers, GLsizei n, const GLuint * buffer);
#ifndef direct_glDeleteBuffers
    if (state.list.compiling) {
        push_glDeleteBuffers(n, buffer);
    } else {
#endif
        gles_glDeleteBuffers(n, buffer);

#ifndef direct_glDeleteBuffers
    }
#endif
}
#endif
#ifndef skip_glDeleteFramebuffers
void glDeleteFramebuffers(GLsizei n, const GLuint * framebuffers) {
    LOAD_GLES(void, glDeleteFramebuffers, GLsizei n, const GLuint * framebuffers);
#ifndef direct_glDeleteFramebuffers
    if (state.list.compiling) {
        push_glDeleteFramebuffers(n, framebuffers);
    } else {
#endif
        gles_glDeleteFramebuffers(n, framebuffers);

#ifndef direct_glDeleteFramebuffers
    }
#endif
}
#endif
#ifndef skip_glDeleteProgram
void glDeleteProgram(GLuint program) {
    LOAD_GLES(void, glDeleteProgram, GLuint program);
#ifndef direct_glDeleteProgram
    if (state.list.compiling) {
        push_glDeleteProgram(program);
    } else {
#endif
        gles_glDeleteProgram(program);

#ifndef direct_glDeleteProgram
    }
#endif
}
#endif
#ifndef skip_glDeleteRenderbuffers
void glDeleteRenderbuffers(GLsizei n, const GLuint * renderbuffers) {
    LOAD_GLES(void, glDeleteRenderbuffers, GLsizei n, const GLuint * renderbuffers);
#ifndef direct_glDeleteRenderbuffers
    if (state.list.compiling) {
        push_glDeleteRenderbuffers(n, renderbuffers);
    } else {
#endif
        gles_glDeleteRenderbuffers(n, renderbuffers);

#ifndef direct_glDeleteRenderbuffers
    }
#endif
}
#endif
#ifndef skip_glDeleteShader
void glDeleteShader(GLuint program) {
    LOAD_GLES(void, glDeleteShader, GLuint program);
#ifndef direct_glDeleteShader
    if (state.list.compiling) {
        push_glDeleteShader(program);
    } else {
#endif
        gles_glDeleteShader(program);

#ifndef direct_glDeleteShader
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
void glDepthRangef(GLclampf zNear, GLclampf zFar) {
    LOAD_GLES(void, glDepthRangef, GLclampf zNear, GLclampf zFar);
#ifndef direct_glDepthRangef
    if (state.list.compiling) {
        push_glDepthRangef(zNear, zFar);
    } else {
#endif
        gles_glDepthRangef(zNear, zFar);

#ifndef direct_glDepthRangef
    }
#endif
}
#endif
#ifndef skip_glDetachShader
void glDetachShader(GLuint program, GLuint shader) {
    LOAD_GLES(void, glDetachShader, GLuint program, GLuint shader);
#ifndef direct_glDetachShader
    if (state.list.compiling) {
        push_glDetachShader(program, shader);
    } else {
#endif
        gles_glDetachShader(program, shader);

#ifndef direct_glDetachShader
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
#ifndef skip_glDisableVertexAttribArray
void glDisableVertexAttribArray(GLuint index) {
    LOAD_GLES(void, glDisableVertexAttribArray, GLuint index);
#ifndef direct_glDisableVertexAttribArray
    if (state.list.compiling) {
        push_glDisableVertexAttribArray(index);
    } else {
#endif
        gles_glDisableVertexAttribArray(index);

#ifndef direct_glDisableVertexAttribArray
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
#ifndef skip_glEnableVertexAttribArray
void glEnableVertexAttribArray(GLuint index) {
    LOAD_GLES(void, glEnableVertexAttribArray, GLuint index);
#ifndef direct_glEnableVertexAttribArray
    if (state.list.compiling) {
        push_glEnableVertexAttribArray(index);
    } else {
#endif
        gles_glEnableVertexAttribArray(index);

#ifndef direct_glEnableVertexAttribArray
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
#ifndef skip_glFramebufferRenderbuffer
void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
    LOAD_GLES(void, glFramebufferRenderbuffer, GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
#ifndef direct_glFramebufferRenderbuffer
    if (state.list.compiling) {
        push_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
    } else {
#endif
        gles_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);

#ifndef direct_glFramebufferRenderbuffer
    }
#endif
}
#endif
#ifndef skip_glFramebufferTexture2D
void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
    LOAD_GLES(void, glFramebufferTexture2D, GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
#ifndef direct_glFramebufferTexture2D
    if (state.list.compiling) {
        push_glFramebufferTexture2D(target, attachment, textarget, texture, level);
    } else {
#endif
        gles_glFramebufferTexture2D(target, attachment, textarget, texture, level);

#ifndef direct_glFramebufferTexture2D
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
#ifndef skip_glGenBuffers
void glGenBuffers(GLsizei n, GLuint * buffer) {
    LOAD_GLES(void, glGenBuffers, GLsizei n, GLuint * buffer);
#ifndef direct_glGenBuffers
    if (state.list.compiling) {
        push_glGenBuffers(n, buffer);
    } else {
#endif
        gles_glGenBuffers(n, buffer);

#ifndef direct_glGenBuffers
    }
#endif
}
#endif
#ifndef skip_glGenFramebuffers
void glGenFramebuffers(GLsizei n, GLuint * framebuffers) {
    LOAD_GLES(void, glGenFramebuffers, GLsizei n, GLuint * framebuffers);
#ifndef direct_glGenFramebuffers
    if (state.list.compiling) {
        push_glGenFramebuffers(n, framebuffers);
    } else {
#endif
        gles_glGenFramebuffers(n, framebuffers);

#ifndef direct_glGenFramebuffers
    }
#endif
}
#endif
#ifndef skip_glGenRenderbuffers
void glGenRenderbuffers(GLsizei n, GLuint * renderbuffers) {
    LOAD_GLES(void, glGenRenderbuffers, GLsizei n, GLuint * renderbuffers);
#ifndef direct_glGenRenderbuffers
    if (state.list.compiling) {
        push_glGenRenderbuffers(n, renderbuffers);
    } else {
#endif
        gles_glGenRenderbuffers(n, renderbuffers);

#ifndef direct_glGenRenderbuffers
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
#ifndef skip_glGenerateMipmap
void glGenerateMipmap(GLenum target) {
    LOAD_GLES(void, glGenerateMipmap, GLenum target);
#ifndef direct_glGenerateMipmap
    if (state.list.compiling) {
        push_glGenerateMipmap(target);
    } else {
#endif
        gles_glGenerateMipmap(target);

#ifndef direct_glGenerateMipmap
    }
#endif
}
#endif
#ifndef skip_glGetActiveAttrib
void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) {
    LOAD_GLES(void, glGetActiveAttrib, GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
#ifndef direct_glGetActiveAttrib
    if (state.list.compiling) {
        push_glGetActiveAttrib(program, index, bufSize, length, size, type, name);
    } else {
#endif
        gles_glGetActiveAttrib(program, index, bufSize, length, size, type, name);

#ifndef direct_glGetActiveAttrib
    }
#endif
}
#endif
#ifndef skip_glGetActiveUniform
void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) {
    LOAD_GLES(void, glGetActiveUniform, GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
#ifndef direct_glGetActiveUniform
    if (state.list.compiling) {
        push_glGetActiveUniform(program, index, bufSize, length, size, type, name);
    } else {
#endif
        gles_glGetActiveUniform(program, index, bufSize, length, size, type, name);

#ifndef direct_glGetActiveUniform
    }
#endif
}
#endif
#ifndef skip_glGetAttachedShaders
void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * obj) {
    LOAD_GLES(void, glGetAttachedShaders, GLuint program, GLsizei maxCount, GLsizei * count, GLuint * obj);
#ifndef direct_glGetAttachedShaders
    if (state.list.compiling) {
        push_glGetAttachedShaders(program, maxCount, count, obj);
    } else {
#endif
        gles_glGetAttachedShaders(program, maxCount, count, obj);

#ifndef direct_glGetAttachedShaders
    }
#endif
}
#endif
#ifndef skip_glGetAttribLocation
GLint glGetAttribLocation(GLuint program, const GLchar * name) {
    LOAD_GLES(GLint, glGetAttribLocation, GLuint program, const GLchar * name);
#ifndef direct_glGetAttribLocation
    if (state.list.compiling) {
        push_glGetAttribLocation(program, name);
        return 0;
    } else {
#endif
        return gles_glGetAttribLocation(program, name);

#ifndef direct_glGetAttribLocation
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
#ifndef skip_glGetFramebufferAttachmentParameteriv
void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint * params) {
    LOAD_GLES(void, glGetFramebufferAttachmentParameteriv, GLenum target, GLenum attachment, GLenum pname, GLint * params);
#ifndef direct_glGetFramebufferAttachmentParameteriv
    if (state.list.compiling) {
        push_glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
    } else {
#endif
        gles_glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);

#ifndef direct_glGetFramebufferAttachmentParameteriv
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
#ifndef skip_glGetProgramInfoLog
void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
    LOAD_GLES(void, glGetProgramInfoLog, GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
#ifndef direct_glGetProgramInfoLog
    if (state.list.compiling) {
        push_glGetProgramInfoLog(program, bufSize, length, infoLog);
    } else {
#endif
        gles_glGetProgramInfoLog(program, bufSize, length, infoLog);

#ifndef direct_glGetProgramInfoLog
    }
#endif
}
#endif
#ifndef skip_glGetProgramiv
void glGetProgramiv(GLuint program, GLenum pname, GLint * params) {
    LOAD_GLES(void, glGetProgramiv, GLuint program, GLenum pname, GLint * params);
#ifndef direct_glGetProgramiv
    if (state.list.compiling) {
        push_glGetProgramiv(program, pname, params);
    } else {
#endif
        gles_glGetProgramiv(program, pname, params);

#ifndef direct_glGetProgramiv
    }
#endif
}
#endif
#ifndef skip_glGetRenderbufferParameteriv
void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    LOAD_GLES(void, glGetRenderbufferParameteriv, GLenum target, GLenum pname, GLint * params);
#ifndef direct_glGetRenderbufferParameteriv
    if (state.list.compiling) {
        push_glGetRenderbufferParameteriv(target, pname, params);
    } else {
#endif
        gles_glGetRenderbufferParameteriv(target, pname, params);

#ifndef direct_glGetRenderbufferParameteriv
    }
#endif
}
#endif
#ifndef skip_glGetShaderInfoLog
void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
    LOAD_GLES(void, glGetShaderInfoLog, GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
#ifndef direct_glGetShaderInfoLog
    if (state.list.compiling) {
        push_glGetShaderInfoLog(shader, bufSize, length, infoLog);
    } else {
#endif
        gles_glGetShaderInfoLog(shader, bufSize, length, infoLog);

#ifndef direct_glGetShaderInfoLog
    }
#endif
}
#endif
#ifndef skip_glGetShaderPrecisionFormat
void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision) {
    LOAD_GLES(void, glGetShaderPrecisionFormat, GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision);
#ifndef direct_glGetShaderPrecisionFormat
    if (state.list.compiling) {
        push_glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
    } else {
#endif
        gles_glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);

#ifndef direct_glGetShaderPrecisionFormat
    }
#endif
}
#endif
#ifndef skip_glGetShaderSource
void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source) {
    LOAD_GLES(void, glGetShaderSource, GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source);
#ifndef direct_glGetShaderSource
    if (state.list.compiling) {
        push_glGetShaderSource(shader, bufSize, length, source);
    } else {
#endif
        gles_glGetShaderSource(shader, bufSize, length, source);

#ifndef direct_glGetShaderSource
    }
#endif
}
#endif
#ifndef skip_glGetShaderiv
void glGetShaderiv(GLuint shader, GLenum pname, GLint * params) {
    LOAD_GLES(void, glGetShaderiv, GLuint shader, GLenum pname, GLint * params);
#ifndef direct_glGetShaderiv
    if (state.list.compiling) {
        push_glGetShaderiv(shader, pname, params);
    } else {
#endif
        gles_glGetShaderiv(shader, pname, params);

#ifndef direct_glGetShaderiv
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
#ifndef skip_glGetUniformLocation
GLint glGetUniformLocation(GLuint program, const GLchar * name) {
    LOAD_GLES(GLint, glGetUniformLocation, GLuint program, const GLchar * name);
#ifndef direct_glGetUniformLocation
    if (state.list.compiling) {
        push_glGetUniformLocation(program, name);
        return 0;
    } else {
#endif
        return gles_glGetUniformLocation(program, name);

#ifndef direct_glGetUniformLocation
    }
#endif
}
#endif
#ifndef skip_glGetUniformfv
void glGetUniformfv(GLuint program, GLint location, GLfloat * params) {
    LOAD_GLES(void, glGetUniformfv, GLuint program, GLint location, GLfloat * params);
#ifndef direct_glGetUniformfv
    if (state.list.compiling) {
        push_glGetUniformfv(program, location, params);
    } else {
#endif
        gles_glGetUniformfv(program, location, params);

#ifndef direct_glGetUniformfv
    }
#endif
}
#endif
#ifndef skip_glGetUniformiv
void glGetUniformiv(GLuint program, GLint location, GLint * params) {
    LOAD_GLES(void, glGetUniformiv, GLuint program, GLint location, GLint * params);
#ifndef direct_glGetUniformiv
    if (state.list.compiling) {
        push_glGetUniformiv(program, location, params);
    } else {
#endif
        gles_glGetUniformiv(program, location, params);

#ifndef direct_glGetUniformiv
    }
#endif
}
#endif
#ifndef skip_glGetVertexAttribPointerv
void glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid ** pointer) {
    LOAD_GLES(void, glGetVertexAttribPointerv, GLuint index, GLenum pname, GLvoid ** pointer);
#ifndef direct_glGetVertexAttribPointerv
    if (state.list.compiling) {
        push_glGetVertexAttribPointerv(index, pname, pointer);
    } else {
#endif
        gles_glGetVertexAttribPointerv(index, pname, pointer);

#ifndef direct_glGetVertexAttribPointerv
    }
#endif
}
#endif
#ifndef skip_glGetVertexAttribfv
void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat * params) {
    LOAD_GLES(void, glGetVertexAttribfv, GLuint index, GLenum pname, GLfloat * params);
#ifndef direct_glGetVertexAttribfv
    if (state.list.compiling) {
        push_glGetVertexAttribfv(index, pname, params);
    } else {
#endif
        gles_glGetVertexAttribfv(index, pname, params);

#ifndef direct_glGetVertexAttribfv
    }
#endif
}
#endif
#ifndef skip_glGetVertexAttribiv
void glGetVertexAttribiv(GLuint index, GLenum pname, GLint * params) {
    LOAD_GLES(void, glGetVertexAttribiv, GLuint index, GLenum pname, GLint * params);
#ifndef direct_glGetVertexAttribiv
    if (state.list.compiling) {
        push_glGetVertexAttribiv(index, pname, params);
    } else {
#endif
        gles_glGetVertexAttribiv(index, pname, params);

#ifndef direct_glGetVertexAttribiv
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
#ifndef skip_glIsFramebuffer
GLboolean glIsFramebuffer(GLuint framebuffer) {
    LOAD_GLES(GLboolean, glIsFramebuffer, GLuint framebuffer);
#ifndef direct_glIsFramebuffer
    if (state.list.compiling) {
        push_glIsFramebuffer(framebuffer);
        return 0;
    } else {
#endif
        return gles_glIsFramebuffer(framebuffer);

#ifndef direct_glIsFramebuffer
    }
#endif
}
#endif
#ifndef skip_glIsProgram
GLboolean glIsProgram(GLuint program) {
    LOAD_GLES(GLboolean, glIsProgram, GLuint program);
#ifndef direct_glIsProgram
    if (state.list.compiling) {
        push_glIsProgram(program);
        return 0;
    } else {
#endif
        return gles_glIsProgram(program);

#ifndef direct_glIsProgram
    }
#endif
}
#endif
#ifndef skip_glIsRenderbuffer
GLboolean glIsRenderbuffer(GLuint renderbuffer) {
    LOAD_GLES(GLboolean, glIsRenderbuffer, GLuint renderbuffer);
#ifndef direct_glIsRenderbuffer
    if (state.list.compiling) {
        push_glIsRenderbuffer(renderbuffer);
        return 0;
    } else {
#endif
        return gles_glIsRenderbuffer(renderbuffer);

#ifndef direct_glIsRenderbuffer
    }
#endif
}
#endif
#ifndef skip_glIsShader
GLboolean glIsShader(GLuint shader) {
    LOAD_GLES(GLboolean, glIsShader, GLuint shader);
#ifndef direct_glIsShader
    if (state.list.compiling) {
        push_glIsShader(shader);
        return 0;
    } else {
#endif
        return gles_glIsShader(shader);

#ifndef direct_glIsShader
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
#ifndef skip_glLinkProgram
void glLinkProgram(GLuint program) {
    LOAD_GLES(void, glLinkProgram, GLuint program);
#ifndef direct_glLinkProgram
    if (state.list.compiling) {
        push_glLinkProgram(program);
    } else {
#endif
        gles_glLinkProgram(program);

#ifndef direct_glLinkProgram
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
#ifndef skip_glReleaseShaderCompiler
void glReleaseShaderCompiler() {
    LOAD_GLES(void, glReleaseShaderCompiler);
#ifndef direct_glReleaseShaderCompiler
    if (state.list.compiling) {
        push_glReleaseShaderCompiler();
    } else {
#endif
        gles_glReleaseShaderCompiler();

#ifndef direct_glReleaseShaderCompiler
    }
#endif
}
#endif
#ifndef skip_glRenderbufferStorage
void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
    LOAD_GLES(void, glRenderbufferStorage, GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
#ifndef direct_glRenderbufferStorage
    if (state.list.compiling) {
        push_glRenderbufferStorage(target, internalformat, width, height);
    } else {
#endif
        gles_glRenderbufferStorage(target, internalformat, width, height);

#ifndef direct_glRenderbufferStorage
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
#ifndef skip_glShaderBinary
void glShaderBinary(GLsizei n, const GLuint * shaders, GLenum binaryformat, const GLvoid * binary, GLsizei length) {
    LOAD_GLES(void, glShaderBinary, GLsizei n, const GLuint * shaders, GLenum binaryformat, const GLvoid * binary, GLsizei length);
#ifndef direct_glShaderBinary
    if (state.list.compiling) {
        push_glShaderBinary(n, shaders, binaryformat, binary, length);
    } else {
#endif
        gles_glShaderBinary(n, shaders, binaryformat, binary, length);

#ifndef direct_glShaderBinary
    }
#endif
}
#endif
#ifndef skip_glShaderSource
void glShaderSource(GLuint shader, GLsizei count, const GLchar * const * string, const GLint * length) {
    LOAD_GLES(void, glShaderSource, GLuint shader, GLsizei count, const GLchar * const * string, const GLint * length);
#ifndef direct_glShaderSource
    if (state.list.compiling) {
        push_glShaderSource(shader, count, string, length);
    } else {
#endif
        gles_glShaderSource(shader, count, string, length);

#ifndef direct_glShaderSource
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
#ifndef skip_glStencilFuncSeparate
void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) {
    LOAD_GLES(void, glStencilFuncSeparate, GLenum face, GLenum func, GLint ref, GLuint mask);
#ifndef direct_glStencilFuncSeparate
    if (state.list.compiling) {
        push_glStencilFuncSeparate(face, func, ref, mask);
    } else {
#endif
        gles_glStencilFuncSeparate(face, func, ref, mask);

#ifndef direct_glStencilFuncSeparate
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
#ifndef skip_glStencilMaskSeparate
void glStencilMaskSeparate(GLenum face, GLuint mask) {
    LOAD_GLES(void, glStencilMaskSeparate, GLenum face, GLuint mask);
#ifndef direct_glStencilMaskSeparate
    if (state.list.compiling) {
        push_glStencilMaskSeparate(face, mask);
    } else {
#endif
        gles_glStencilMaskSeparate(face, mask);

#ifndef direct_glStencilMaskSeparate
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
#ifndef skip_glStencilOpSeparate
void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum zfail, GLenum zpass) {
    LOAD_GLES(void, glStencilOpSeparate, GLenum face, GLenum sfail, GLenum zfail, GLenum zpass);
#ifndef direct_glStencilOpSeparate
    if (state.list.compiling) {
        push_glStencilOpSeparate(face, sfail, zfail, zpass);
    } else {
#endif
        gles_glStencilOpSeparate(face, sfail, zfail, zpass);

#ifndef direct_glStencilOpSeparate
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
#ifndef skip_glUniform1f
void glUniform1f(GLint location, GLfloat v0) {
    LOAD_GLES(void, glUniform1f, GLint location, GLfloat v0);
#ifndef direct_glUniform1f
    if (state.list.compiling) {
        push_glUniform1f(location, v0);
    } else {
#endif
        gles_glUniform1f(location, v0);

#ifndef direct_glUniform1f
    }
#endif
}
#endif
#ifndef skip_glUniform1fv
void glUniform1fv(GLint location, GLsizei count, const GLfloat * value) {
    LOAD_GLES(void, glUniform1fv, GLint location, GLsizei count, const GLfloat * value);
#ifndef direct_glUniform1fv
    if (state.list.compiling) {
        push_glUniform1fv(location, count, value);
    } else {
#endif
        gles_glUniform1fv(location, count, value);

#ifndef direct_glUniform1fv
    }
#endif
}
#endif
#ifndef skip_glUniform1i
void glUniform1i(GLint location, GLint v0) {
    LOAD_GLES(void, glUniform1i, GLint location, GLint v0);
#ifndef direct_glUniform1i
    if (state.list.compiling) {
        push_glUniform1i(location, v0);
    } else {
#endif
        gles_glUniform1i(location, v0);

#ifndef direct_glUniform1i
    }
#endif
}
#endif
#ifndef skip_glUniform1iv
void glUniform1iv(GLint location, GLsizei count, const GLint * value) {
    LOAD_GLES(void, glUniform1iv, GLint location, GLsizei count, const GLint * value);
#ifndef direct_glUniform1iv
    if (state.list.compiling) {
        push_glUniform1iv(location, count, value);
    } else {
#endif
        gles_glUniform1iv(location, count, value);

#ifndef direct_glUniform1iv
    }
#endif
}
#endif
#ifndef skip_glUniform2f
void glUniform2f(GLint location, GLfloat v0, GLfloat v1) {
    LOAD_GLES(void, glUniform2f, GLint location, GLfloat v0, GLfloat v1);
#ifndef direct_glUniform2f
    if (state.list.compiling) {
        push_glUniform2f(location, v0, v1);
    } else {
#endif
        gles_glUniform2f(location, v0, v1);

#ifndef direct_glUniform2f
    }
#endif
}
#endif
#ifndef skip_glUniform2fv
void glUniform2fv(GLint location, GLsizei count, const GLfloat * value) {
    LOAD_GLES(void, glUniform2fv, GLint location, GLsizei count, const GLfloat * value);
#ifndef direct_glUniform2fv
    if (state.list.compiling) {
        push_glUniform2fv(location, count, value);
    } else {
#endif
        gles_glUniform2fv(location, count, value);

#ifndef direct_glUniform2fv
    }
#endif
}
#endif
#ifndef skip_glUniform2i
void glUniform2i(GLint location, GLint v0, GLint v1) {
    LOAD_GLES(void, glUniform2i, GLint location, GLint v0, GLint v1);
#ifndef direct_glUniform2i
    if (state.list.compiling) {
        push_glUniform2i(location, v0, v1);
    } else {
#endif
        gles_glUniform2i(location, v0, v1);

#ifndef direct_glUniform2i
    }
#endif
}
#endif
#ifndef skip_glUniform2iv
void glUniform2iv(GLint location, GLsizei count, const GLint * value) {
    LOAD_GLES(void, glUniform2iv, GLint location, GLsizei count, const GLint * value);
#ifndef direct_glUniform2iv
    if (state.list.compiling) {
        push_glUniform2iv(location, count, value);
    } else {
#endif
        gles_glUniform2iv(location, count, value);

#ifndef direct_glUniform2iv
    }
#endif
}
#endif
#ifndef skip_glUniform3f
void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    LOAD_GLES(void, glUniform3f, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
#ifndef direct_glUniform3f
    if (state.list.compiling) {
        push_glUniform3f(location, v0, v1, v2);
    } else {
#endif
        gles_glUniform3f(location, v0, v1, v2);

#ifndef direct_glUniform3f
    }
#endif
}
#endif
#ifndef skip_glUniform3fv
void glUniform3fv(GLint location, GLsizei count, const GLfloat * value) {
    LOAD_GLES(void, glUniform3fv, GLint location, GLsizei count, const GLfloat * value);
#ifndef direct_glUniform3fv
    if (state.list.compiling) {
        push_glUniform3fv(location, count, value);
    } else {
#endif
        gles_glUniform3fv(location, count, value);

#ifndef direct_glUniform3fv
    }
#endif
}
#endif
#ifndef skip_glUniform3i
void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) {
    LOAD_GLES(void, glUniform3i, GLint location, GLint v0, GLint v1, GLint v2);
#ifndef direct_glUniform3i
    if (state.list.compiling) {
        push_glUniform3i(location, v0, v1, v2);
    } else {
#endif
        gles_glUniform3i(location, v0, v1, v2);

#ifndef direct_glUniform3i
    }
#endif
}
#endif
#ifndef skip_glUniform3iv
void glUniform3iv(GLint location, GLsizei count, const GLint * value) {
    LOAD_GLES(void, glUniform3iv, GLint location, GLsizei count, const GLint * value);
#ifndef direct_glUniform3iv
    if (state.list.compiling) {
        push_glUniform3iv(location, count, value);
    } else {
#endif
        gles_glUniform3iv(location, count, value);

#ifndef direct_glUniform3iv
    }
#endif
}
#endif
#ifndef skip_glUniform4f
void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    LOAD_GLES(void, glUniform4f, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
#ifndef direct_glUniform4f
    if (state.list.compiling) {
        push_glUniform4f(location, v0, v1, v2, v3);
    } else {
#endif
        gles_glUniform4f(location, v0, v1, v2, v3);

#ifndef direct_glUniform4f
    }
#endif
}
#endif
#ifndef skip_glUniform4fv
void glUniform4fv(GLint location, GLsizei count, const GLfloat * value) {
    LOAD_GLES(void, glUniform4fv, GLint location, GLsizei count, const GLfloat * value);
#ifndef direct_glUniform4fv
    if (state.list.compiling) {
        push_glUniform4fv(location, count, value);
    } else {
#endif
        gles_glUniform4fv(location, count, value);

#ifndef direct_glUniform4fv
    }
#endif
}
#endif
#ifndef skip_glUniform4i
void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
    LOAD_GLES(void, glUniform4i, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
#ifndef direct_glUniform4i
    if (state.list.compiling) {
        push_glUniform4i(location, v0, v1, v2, v3);
    } else {
#endif
        gles_glUniform4i(location, v0, v1, v2, v3);

#ifndef direct_glUniform4i
    }
#endif
}
#endif
#ifndef skip_glUniform4iv
void glUniform4iv(GLint location, GLsizei count, const GLint * value) {
    LOAD_GLES(void, glUniform4iv, GLint location, GLsizei count, const GLint * value);
#ifndef direct_glUniform4iv
    if (state.list.compiling) {
        push_glUniform4iv(location, count, value);
    } else {
#endif
        gles_glUniform4iv(location, count, value);

#ifndef direct_glUniform4iv
    }
#endif
}
#endif
#ifndef skip_glUniformMatrix2fv
void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    LOAD_GLES(void, glUniformMatrix2fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#ifndef direct_glUniformMatrix2fv
    if (state.list.compiling) {
        push_glUniformMatrix2fv(location, count, transpose, value);
    } else {
#endif
        gles_glUniformMatrix2fv(location, count, transpose, value);

#ifndef direct_glUniformMatrix2fv
    }
#endif
}
#endif
#ifndef skip_glUniformMatrix3fv
void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    LOAD_GLES(void, glUniformMatrix3fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#ifndef direct_glUniformMatrix3fv
    if (state.list.compiling) {
        push_glUniformMatrix3fv(location, count, transpose, value);
    } else {
#endif
        gles_glUniformMatrix3fv(location, count, transpose, value);

#ifndef direct_glUniformMatrix3fv
    }
#endif
}
#endif
#ifndef skip_glUniformMatrix4fv
void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    LOAD_GLES(void, glUniformMatrix4fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
#ifndef direct_glUniformMatrix4fv
    if (state.list.compiling) {
        push_glUniformMatrix4fv(location, count, transpose, value);
    } else {
#endif
        gles_glUniformMatrix4fv(location, count, transpose, value);

#ifndef direct_glUniformMatrix4fv
    }
#endif
}
#endif
#ifndef skip_glUseProgram
void glUseProgram(GLuint program) {
    LOAD_GLES(void, glUseProgram, GLuint program);
#ifndef direct_glUseProgram
    if (state.list.compiling) {
        push_glUseProgram(program);
    } else {
#endif
        gles_glUseProgram(program);

#ifndef direct_glUseProgram
    }
#endif
}
#endif
#ifndef skip_glValidateProgram
void glValidateProgram(GLuint program) {
    LOAD_GLES(void, glValidateProgram, GLuint program);
#ifndef direct_glValidateProgram
    if (state.list.compiling) {
        push_glValidateProgram(program);
    } else {
#endif
        gles_glValidateProgram(program);

#ifndef direct_glValidateProgram
    }
#endif
}
#endif
#ifndef skip_glVertexAttrib1f
void glVertexAttrib1f(GLuint index, GLfloat x) {
    LOAD_GLES(void, glVertexAttrib1f, GLuint index, GLfloat x);
#ifndef direct_glVertexAttrib1f
    if (state.list.compiling) {
        push_glVertexAttrib1f(index, x);
    } else {
#endif
        gles_glVertexAttrib1f(index, x);

#ifndef direct_glVertexAttrib1f
    }
#endif
}
#endif
#ifndef skip_glVertexAttrib1fv
void glVertexAttrib1fv(GLuint index, const GLfloat * v) {
    LOAD_GLES(void, glVertexAttrib1fv, GLuint index, const GLfloat * v);
#ifndef direct_glVertexAttrib1fv
    if (state.list.compiling) {
        push_glVertexAttrib1fv(index, v);
    } else {
#endif
        gles_glVertexAttrib1fv(index, v);

#ifndef direct_glVertexAttrib1fv
    }
#endif
}
#endif
#ifndef skip_glVertexAttrib2f
void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) {
    LOAD_GLES(void, glVertexAttrib2f, GLuint index, GLfloat x, GLfloat y);
#ifndef direct_glVertexAttrib2f
    if (state.list.compiling) {
        push_glVertexAttrib2f(index, x, y);
    } else {
#endif
        gles_glVertexAttrib2f(index, x, y);

#ifndef direct_glVertexAttrib2f
    }
#endif
}
#endif
#ifndef skip_glVertexAttrib2fv
void glVertexAttrib2fv(GLuint index, const GLfloat * v) {
    LOAD_GLES(void, glVertexAttrib2fv, GLuint index, const GLfloat * v);
#ifndef direct_glVertexAttrib2fv
    if (state.list.compiling) {
        push_glVertexAttrib2fv(index, v);
    } else {
#endif
        gles_glVertexAttrib2fv(index, v);

#ifndef direct_glVertexAttrib2fv
    }
#endif
}
#endif
#ifndef skip_glVertexAttrib3f
void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
    LOAD_GLES(void, glVertexAttrib3f, GLuint index, GLfloat x, GLfloat y, GLfloat z);
#ifndef direct_glVertexAttrib3f
    if (state.list.compiling) {
        push_glVertexAttrib3f(index, x, y, z);
    } else {
#endif
        gles_glVertexAttrib3f(index, x, y, z);

#ifndef direct_glVertexAttrib3f
    }
#endif
}
#endif
#ifndef skip_glVertexAttrib3fv
void glVertexAttrib3fv(GLuint index, const GLfloat * v) {
    LOAD_GLES(void, glVertexAttrib3fv, GLuint index, const GLfloat * v);
#ifndef direct_glVertexAttrib3fv
    if (state.list.compiling) {
        push_glVertexAttrib3fv(index, v);
    } else {
#endif
        gles_glVertexAttrib3fv(index, v);

#ifndef direct_glVertexAttrib3fv
    }
#endif
}
#endif
#ifndef skip_glVertexAttrib4f
void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    LOAD_GLES(void, glVertexAttrib4f, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#ifndef direct_glVertexAttrib4f
    if (state.list.compiling) {
        push_glVertexAttrib4f(index, x, y, z, w);
    } else {
#endif
        gles_glVertexAttrib4f(index, x, y, z, w);

#ifndef direct_glVertexAttrib4f
    }
#endif
}
#endif
#ifndef skip_glVertexAttrib4fv
void glVertexAttrib4fv(GLuint index, const GLfloat * v) {
    LOAD_GLES(void, glVertexAttrib4fv, GLuint index, const GLfloat * v);
#ifndef direct_glVertexAttrib4fv
    if (state.list.compiling) {
        push_glVertexAttrib4fv(index, v);
    } else {
#endif
        gles_glVertexAttrib4fv(index, v);

#ifndef direct_glVertexAttrib4fv
    }
#endif
}
#endif
#ifndef skip_glVertexAttribPointer
void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer) {
    LOAD_GLES(void, glVertexAttribPointer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer);
#ifndef direct_glVertexAttribPointer
    if (state.list.compiling) {
        push_glVertexAttribPointer(index, size, type, normalized, stride, pointer);
    } else {
#endif
        gles_glVertexAttribPointer(index, size, type, normalized, stride, pointer);

#ifndef direct_glVertexAttribPointer
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
