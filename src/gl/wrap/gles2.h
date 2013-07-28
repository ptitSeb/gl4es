#ifdef USE_ES2
#include "../gl.h"

#ifndef GLES2WRAP_H
#define GLES2WRAP_H

typedef struct {
    int format;
    void *func;
    void *args;
} UnknownCall;

enum FORMAT {
    FORMAT_void_GLenum,
    FORMAT_void_GLuint_GLuint,
    FORMAT_void_GLuint_GLuint_const_GLchar___GENPT__,
    FORMAT_void_GLenum_GLuint,
    FORMAT_void_GLclampf_GLclampf_GLclampf_GLclampf,
    FORMAT_void_GLenum_GLenum,
    FORMAT_void_GLenum_GLenum_GLenum_GLenum,
    FORMAT_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum,
    FORMAT_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__,
    FORMAT_GLenum_GLenum,
    FORMAT_void_GLbitfield,
    FORMAT_void_GLclampf,
    FORMAT_void_GLint,
    FORMAT_void_GLboolean_GLboolean_GLboolean_GLboolean,
    FORMAT_void_GLuint,
    FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint,
    FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei,
    FORMAT_GLuint,
    FORMAT_GLuint_GLenum,
    FORMAT_void_GLsizei_const_GLuint___GENPT__,
    FORMAT_void_GLboolean,
    FORMAT_void_GLclampf_GLclampf,
    FORMAT_void_GLenum_GLint_GLsizei,
    FORMAT_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__,
    FORMAT_void,
    FORMAT_void_GLenum_GLenum_GLenum_GLuint,
    FORMAT_void_GLenum_GLenum_GLenum_GLuint_GLint,
    FORMAT_void_GLsizei_GLuint___GENPT__,
    FORMAT_void_GLuint_GLuint_GLsizei_GLsizei___GENPT___GLint___GENPT___GLenum___GENPT___GLchar___GENPT__,
    FORMAT_void_GLuint_GLsizei_GLsizei___GENPT___GLuint___GENPT__,
    FORMAT_GLint_GLuint_const_GLchar___GENPT__,
    FORMAT_void_GLenum_GLboolean___GENPT__,
    FORMAT_void_GLenum_GLenum_GLint___GENPT__,
    FORMAT_GLenum,
    FORMAT_void_GLenum_GLfloat___GENPT__,
    FORMAT_void_GLenum_GLenum_GLenum_GLint___GENPT__,
    FORMAT_void_GLenum_GLint___GENPT__,
    FORMAT_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__,
    FORMAT_void_GLuint_GLenum_GLint___GENPT__,
    FORMAT_void_GLenum_GLenum_GLint___GENPT___GLint___GENPT__,
    FORMAT_const_GLubyte___GENPT___GLenum,
    FORMAT_void_GLenum_GLenum_GLfloat___GENPT__,
    FORMAT_void_GLuint_GLint_GLfloat___GENPT__,
    FORMAT_void_GLuint_GLint_GLint___GENPT__,
    FORMAT_void_GLuint_GLenum_GLvoid___GENPT____GENPT__,
    FORMAT_void_GLuint_GLenum_GLfloat___GENPT__,
    FORMAT_GLboolean_GLuint,
    FORMAT_GLboolean_GLenum,
    FORMAT_void_GLfloat,
    FORMAT_void_GLenum_GLint,
    FORMAT_void_GLfloat_GLfloat,
    FORMAT_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLenum_GLsizei_GLsizei,
    FORMAT_void_GLclampf_GLboolean,
    FORMAT_void_GLint_GLint_GLsizei_GLsizei,
    FORMAT_void_GLsizei_const_GLuint___GENPT___GLenum_const_GLvoid___GENPT___GLsizei,
    FORMAT_void_GLuint_GLsizei_const_GLchar___GENPT___const___GENPT___const_GLint___GENPT__,
    FORMAT_void_GLenum_GLint_GLuint,
    FORMAT_void_GLenum_GLenum_GLint_GLuint,
    FORMAT_void_GLenum_GLenum_GLenum,
    FORMAT_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLenum_GLfloat,
    FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__,
    FORMAT_void_GLenum_GLenum_GLint,
    FORMAT_void_GLenum_GLenum_const_GLint___GENPT__,
    FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__,
    FORMAT_void_GLint_GLfloat,
    FORMAT_void_GLint_GLsizei_const_GLfloat___GENPT__,
    FORMAT_void_GLint_GLint,
    FORMAT_void_GLint_GLsizei_const_GLint___GENPT__,
    FORMAT_void_GLint_GLfloat_GLfloat,
    FORMAT_void_GLint_GLint_GLint,
    FORMAT_void_GLint_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLint_GLint_GLint_GLint,
    FORMAT_void_GLint_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLint_GLint_GLint_GLint_GLint,
    FORMAT_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__,
    FORMAT_void_GLuint_GLfloat,
    FORMAT_void_GLuint_const_GLfloat___GENPT__,
    FORMAT_void_GLuint_GLfloat_GLfloat,
    FORMAT_void_GLuint_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLuint_GLint_GLenum_GLboolean_GLsizei_const_GLvoid___GENPT__,
};

typedef void (*FUNC_void_GLenum)(GLenum texture);
typedef struct {
    GLenum a1;
} ARGS_void_GLenum;
typedef struct {
    int format;
    FUNC_void_GLenum func;
    ARGS_void_GLenum args;
} PACKED_void_GLenum;
typedef void (*FUNC_void_GLuint_GLuint)(GLuint program, GLuint shader);
typedef struct {
    GLuint a1;
    GLuint a2;
} ARGS_void_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint func;
    ARGS_void_GLuint_GLuint args;
} PACKED_void_GLuint_GLuint;
typedef void (*FUNC_void_GLuint_GLuint_const_GLchar___GENPT__)(GLuint program, GLuint index, const GLchar * name);
typedef struct {
    GLuint a1;
    GLuint a2;
    const GLchar * a3;
} ARGS_void_GLuint_GLuint_const_GLchar___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_const_GLchar___GENPT__ func;
    ARGS_void_GLuint_GLuint_const_GLchar___GENPT__ args;
} PACKED_void_GLuint_GLuint_const_GLchar___GENPT__;
typedef void (*FUNC_void_GLenum_GLuint)(GLenum target, GLuint buffer);
typedef struct {
    GLenum a1;
    GLuint a2;
} ARGS_void_GLenum_GLuint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint func;
    ARGS_void_GLenum_GLuint args;
} PACKED_void_GLenum_GLuint;
typedef void (*FUNC_void_GLclampf_GLclampf_GLclampf_GLclampf)(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
typedef struct {
    GLclampf a1;
    GLclampf a2;
    GLclampf a3;
    GLclampf a4;
} ARGS_void_GLclampf_GLclampf_GLclampf_GLclampf;
typedef struct {
    int format;
    FUNC_void_GLclampf_GLclampf_GLclampf_GLclampf func;
    ARGS_void_GLclampf_GLclampf_GLclampf_GLclampf args;
} PACKED_void_GLclampf_GLclampf_GLclampf_GLclampf;
typedef void (*FUNC_void_GLenum_GLenum)(GLenum modeRGB, GLenum modeA);
typedef struct {
    GLenum a1;
    GLenum a2;
} ARGS_void_GLenum_GLenum;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum func;
    ARGS_void_GLenum_GLenum args;
} PACKED_void_GLenum_GLenum;
typedef void (*FUNC_void_GLenum_GLenum_GLenum_GLenum)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLenum a3;
    GLenum a4;
} ARGS_void_GLenum_GLenum_GLenum_GLenum;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLenum_GLenum func;
    ARGS_void_GLenum_GLenum_GLenum_GLenum args;
} PACKED_void_GLenum_GLenum_GLenum_GLenum;
typedef void (*FUNC_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum)(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage);
typedef struct {
    GLenum a1;
    GLsizeiptr a2;
    const GLvoid * a3;
    GLenum a4;
} ARGS_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum func;
    ARGS_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum args;
} PACKED_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum;
typedef void (*FUNC_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__)(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data);
typedef struct {
    GLenum a1;
    GLintptr a2;
    GLsizeiptr a3;
    const GLvoid * a4;
} ARGS_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__;
typedef GLenum (*FUNC_GLenum_GLenum)(GLenum target);
typedef struct {
    GLenum a1;
} ARGS_GLenum_GLenum;
typedef struct {
    int format;
    FUNC_GLenum_GLenum func;
    ARGS_GLenum_GLenum args;
} PACKED_GLenum_GLenum;
typedef void (*FUNC_void_GLbitfield)(GLbitfield mask);
typedef struct {
    GLbitfield a1;
} ARGS_void_GLbitfield;
typedef struct {
    int format;
    FUNC_void_GLbitfield func;
    ARGS_void_GLbitfield args;
} PACKED_void_GLbitfield;
typedef void (*FUNC_void_GLclampf)(GLclampf depth);
typedef struct {
    GLclampf a1;
} ARGS_void_GLclampf;
typedef struct {
    int format;
    FUNC_void_GLclampf func;
    ARGS_void_GLclampf args;
} PACKED_void_GLclampf;
typedef void (*FUNC_void_GLint)(GLint s);
typedef struct {
    GLint a1;
} ARGS_void_GLint;
typedef struct {
    int format;
    FUNC_void_GLint func;
    ARGS_void_GLint args;
} PACKED_void_GLint;
typedef void (*FUNC_void_GLboolean_GLboolean_GLboolean_GLboolean)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
typedef struct {
    GLboolean a1;
    GLboolean a2;
    GLboolean a3;
    GLboolean a4;
} ARGS_void_GLboolean_GLboolean_GLboolean_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLboolean_GLboolean_GLboolean_GLboolean func;
    ARGS_void_GLboolean_GLboolean_GLboolean_GLboolean args;
} PACKED_void_GLboolean_GLboolean_GLboolean_GLboolean;
typedef void (*FUNC_void_GLuint)(GLuint shader);
typedef struct {
    GLuint a1;
} ARGS_void_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint func;
    ARGS_void_GLuint args;
} PACKED_void_GLuint;
typedef void (*FUNC_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data);
typedef struct {
    GLenum a1;
    GLint a2;
    GLenum a3;
    GLsizei a4;
    GLsizei a5;
    GLint a6;
    GLsizei a7;
    const GLvoid * a8;
} ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__;
typedef void (*FUNC_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data);
typedef struct {
    GLenum a1;
    GLint a2;
    GLint a3;
    GLint a4;
    GLsizei a5;
    GLsizei a6;
    GLenum a7;
    GLsizei a8;
    const GLvoid * a9;
} ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__;
typedef void (*FUNC_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef struct {
    GLenum a1;
    GLint a2;
    GLenum a3;
    GLint a4;
    GLint a5;
    GLsizei a6;
    GLsizei a7;
    GLint a8;
} ARGS_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint func;
    ARGS_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint args;
} PACKED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint;
typedef void (*FUNC_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef struct {
    GLenum a1;
    GLint a2;
    GLint a3;
    GLint a4;
    GLint a5;
    GLint a6;
    GLsizei a7;
    GLsizei a8;
} ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei func;
    ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei args;
} PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei;
typedef GLuint (*FUNC_GLuint)();
typedef struct {
} ARGS_GLuint;
typedef struct {
    int format;
    FUNC_GLuint func;
    ARGS_GLuint args;
} PACKED_GLuint;
typedef GLuint (*FUNC_GLuint_GLenum)(GLenum type);
typedef struct {
    GLenum a1;
} ARGS_GLuint_GLenum;
typedef struct {
    int format;
    FUNC_GLuint_GLenum func;
    ARGS_GLuint_GLenum args;
} PACKED_GLuint_GLenum;
typedef void (*FUNC_void_GLsizei_const_GLuint___GENPT__)(GLsizei n, const GLuint * buffer);
typedef struct {
    GLsizei a1;
    const GLuint * a2;
} ARGS_void_GLsizei_const_GLuint___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLsizei_const_GLuint___GENPT__ func;
    ARGS_void_GLsizei_const_GLuint___GENPT__ args;
} PACKED_void_GLsizei_const_GLuint___GENPT__;
typedef void (*FUNC_void_GLboolean)(GLboolean flag);
typedef struct {
    GLboolean a1;
} ARGS_void_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLboolean func;
    ARGS_void_GLboolean args;
} PACKED_void_GLboolean;
typedef void (*FUNC_void_GLclampf_GLclampf)(GLclampf zNear, GLclampf zFar);
typedef struct {
    GLclampf a1;
    GLclampf a2;
} ARGS_void_GLclampf_GLclampf;
typedef struct {
    int format;
    FUNC_void_GLclampf_GLclampf func;
    ARGS_void_GLclampf_GLclampf args;
} PACKED_void_GLclampf_GLclampf;
typedef void (*FUNC_void_GLenum_GLint_GLsizei)(GLenum mode, GLint first, GLsizei count);
typedef struct {
    GLenum a1;
    GLint a2;
    GLsizei a3;
} ARGS_void_GLenum_GLint_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLsizei func;
    ARGS_void_GLenum_GLint_GLsizei args;
} PACKED_void_GLenum_GLint_GLsizei;
typedef void (*FUNC_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__)(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLenum a3;
    const GLvoid * a4;
} ARGS_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__;
typedef void (*FUNC_void)();
typedef struct {
} ARGS_void;
typedef struct {
    int format;
    FUNC_void func;
    ARGS_void args;
} PACKED_void;
typedef void (*FUNC_void_GLenum_GLenum_GLenum_GLuint)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLenum a3;
    GLuint a4;
} ARGS_void_GLenum_GLenum_GLenum_GLuint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLenum_GLuint func;
    ARGS_void_GLenum_GLenum_GLenum_GLuint args;
} PACKED_void_GLenum_GLenum_GLenum_GLuint;
typedef void (*FUNC_void_GLenum_GLenum_GLenum_GLuint_GLint)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLenum a3;
    GLuint a4;
    GLint a5;
} ARGS_void_GLenum_GLenum_GLenum_GLuint_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLenum_GLuint_GLint func;
    ARGS_void_GLenum_GLenum_GLenum_GLuint_GLint args;
} PACKED_void_GLenum_GLenum_GLenum_GLuint_GLint;
typedef void (*FUNC_void_GLsizei_GLuint___GENPT__)(GLsizei n, GLuint * buffer);
typedef struct {
    GLsizei a1;
    GLuint * a2;
} ARGS_void_GLsizei_GLuint___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLuint___GENPT__ func;
    ARGS_void_GLsizei_GLuint___GENPT__ args;
} PACKED_void_GLsizei_GLuint___GENPT__;
typedef void (*FUNC_void_GLuint_GLuint_GLsizei_GLsizei___GENPT___GLint___GENPT___GLenum___GENPT___GLchar___GENPT__)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLsizei a3;
    GLsizei * a4;
    GLint * a5;
    GLenum * a6;
    GLchar * a7;
} ARGS_void_GLuint_GLuint_GLsizei_GLsizei___GENPT___GLint___GENPT___GLenum___GENPT___GLchar___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLsizei_GLsizei___GENPT___GLint___GENPT___GLenum___GENPT___GLchar___GENPT__ func;
    ARGS_void_GLuint_GLuint_GLsizei_GLsizei___GENPT___GLint___GENPT___GLenum___GENPT___GLchar___GENPT__ args;
} PACKED_void_GLuint_GLuint_GLsizei_GLsizei___GENPT___GLint___GENPT___GLenum___GENPT___GLchar___GENPT__;
typedef void (*FUNC_void_GLuint_GLsizei_GLsizei___GENPT___GLuint___GENPT__)(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * obj);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLsizei * a3;
    GLuint * a4;
} ARGS_void_GLuint_GLsizei_GLsizei___GENPT___GLuint___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLsizei___GENPT___GLuint___GENPT__ func;
    ARGS_void_GLuint_GLsizei_GLsizei___GENPT___GLuint___GENPT__ args;
} PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLuint___GENPT__;
typedef GLint (*FUNC_GLint_GLuint_const_GLchar___GENPT__)(GLuint program, const GLchar * name);
typedef struct {
    GLuint a1;
    const GLchar * a2;
} ARGS_GLint_GLuint_const_GLchar___GENPT__;
typedef struct {
    int format;
    FUNC_GLint_GLuint_const_GLchar___GENPT__ func;
    ARGS_GLint_GLuint_const_GLchar___GENPT__ args;
} PACKED_GLint_GLuint_const_GLchar___GENPT__;
typedef void (*FUNC_void_GLenum_GLboolean___GENPT__)(GLenum pname, GLboolean * params);
typedef struct {
    GLenum a1;
    GLboolean * a2;
} ARGS_void_GLenum_GLboolean___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLboolean___GENPT__ func;
    ARGS_void_GLenum_GLboolean___GENPT__ args;
} PACKED_void_GLenum_GLboolean___GENPT__;
typedef void (*FUNC_void_GLenum_GLenum_GLint___GENPT__)(GLenum target, GLenum pname, GLint * params);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint * a3;
} ARGS_void_GLenum_GLenum_GLint___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint___GENPT__ func;
    ARGS_void_GLenum_GLenum_GLint___GENPT__ args;
} PACKED_void_GLenum_GLenum_GLint___GENPT__;
typedef GLenum (*FUNC_GLenum)();
typedef struct {
} ARGS_GLenum;
typedef struct {
    int format;
    FUNC_GLenum func;
    ARGS_GLenum args;
} PACKED_GLenum;
typedef void (*FUNC_void_GLenum_GLfloat___GENPT__)(GLenum pname, GLfloat * params);
typedef struct {
    GLenum a1;
    GLfloat * a2;
} ARGS_void_GLenum_GLfloat___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLfloat___GENPT__ func;
    ARGS_void_GLenum_GLfloat___GENPT__ args;
} PACKED_void_GLenum_GLfloat___GENPT__;
typedef void (*FUNC_void_GLenum_GLenum_GLenum_GLint___GENPT__)(GLenum target, GLenum attachment, GLenum pname, GLint * params);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLenum a3;
    GLint * a4;
} ARGS_void_GLenum_GLenum_GLenum_GLint___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLenum_GLint___GENPT__ func;
    ARGS_void_GLenum_GLenum_GLenum_GLint___GENPT__ args;
} PACKED_void_GLenum_GLenum_GLenum_GLint___GENPT__;
typedef void (*FUNC_void_GLenum_GLint___GENPT__)(GLenum pname, GLint * params);
typedef struct {
    GLenum a1;
    GLint * a2;
} ARGS_void_GLenum_GLint___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint___GENPT__ func;
    ARGS_void_GLenum_GLint___GENPT__ args;
} PACKED_void_GLenum_GLint___GENPT__;
typedef void (*FUNC_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__)(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLsizei * a3;
    GLchar * a4;
} ARGS_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__ func;
    ARGS_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__ args;
} PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__;
typedef void (*FUNC_void_GLuint_GLenum_GLint___GENPT__)(GLuint program, GLenum pname, GLint * params);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint * a3;
} ARGS_void_GLuint_GLenum_GLint___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint___GENPT__ func;
    ARGS_void_GLuint_GLenum_GLint___GENPT__ args;
} PACKED_void_GLuint_GLenum_GLint___GENPT__;
typedef void (*FUNC_void_GLenum_GLenum_GLint___GENPT___GLint___GENPT__)(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint * a3;
    GLint * a4;
} ARGS_void_GLenum_GLenum_GLint___GENPT___GLint___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint___GENPT___GLint___GENPT__ func;
    ARGS_void_GLenum_GLenum_GLint___GENPT___GLint___GENPT__ args;
} PACKED_void_GLenum_GLenum_GLint___GENPT___GLint___GENPT__;
typedef const GLubyte * (*FUNC_const_GLubyte___GENPT___GLenum)(GLenum name);
typedef struct {
    GLenum a1;
} ARGS_const_GLubyte___GENPT___GLenum;
typedef struct {
    int format;
    FUNC_const_GLubyte___GENPT___GLenum func;
    ARGS_const_GLubyte___GENPT___GLenum args;
} PACKED_const_GLubyte___GENPT___GLenum;
typedef void (*FUNC_void_GLenum_GLenum_GLfloat___GENPT__)(GLenum target, GLenum pname, GLfloat * params);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLfloat * a3;
} ARGS_void_GLenum_GLenum_GLfloat___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLfloat___GENPT__ func;
    ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args;
} PACKED_void_GLenum_GLenum_GLfloat___GENPT__;
typedef void (*FUNC_void_GLuint_GLint_GLfloat___GENPT__)(GLuint program, GLint location, GLfloat * params);
typedef struct {
    GLuint a1;
    GLint a2;
    GLfloat * a3;
} ARGS_void_GLuint_GLint_GLfloat___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLfloat___GENPT__ func;
    ARGS_void_GLuint_GLint_GLfloat___GENPT__ args;
} PACKED_void_GLuint_GLint_GLfloat___GENPT__;
typedef void (*FUNC_void_GLuint_GLint_GLint___GENPT__)(GLuint program, GLint location, GLint * params);
typedef struct {
    GLuint a1;
    GLint a2;
    GLint * a3;
} ARGS_void_GLuint_GLint_GLint___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLint___GENPT__ func;
    ARGS_void_GLuint_GLint_GLint___GENPT__ args;
} PACKED_void_GLuint_GLint_GLint___GENPT__;
typedef void (*FUNC_void_GLuint_GLenum_GLvoid___GENPT____GENPT__)(GLuint index, GLenum pname, GLvoid ** pointer);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLvoid ** a3;
} ARGS_void_GLuint_GLenum_GLvoid___GENPT____GENPT__;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLvoid___GENPT____GENPT__ func;
    ARGS_void_GLuint_GLenum_GLvoid___GENPT____GENPT__ args;
} PACKED_void_GLuint_GLenum_GLvoid___GENPT____GENPT__;
typedef void (*FUNC_void_GLuint_GLenum_GLfloat___GENPT__)(GLuint index, GLenum pname, GLfloat * params);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLfloat * a3;
} ARGS_void_GLuint_GLenum_GLfloat___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLfloat___GENPT__ func;
    ARGS_void_GLuint_GLenum_GLfloat___GENPT__ args;
} PACKED_void_GLuint_GLenum_GLfloat___GENPT__;
typedef GLboolean (*FUNC_GLboolean_GLuint)(GLuint buffer);
typedef struct {
    GLuint a1;
} ARGS_GLboolean_GLuint;
typedef struct {
    int format;
    FUNC_GLboolean_GLuint func;
    ARGS_GLboolean_GLuint args;
} PACKED_GLboolean_GLuint;
typedef GLboolean (*FUNC_GLboolean_GLenum)(GLenum cap);
typedef struct {
    GLenum a1;
} ARGS_GLboolean_GLenum;
typedef struct {
    int format;
    FUNC_GLboolean_GLenum func;
    ARGS_GLboolean_GLenum args;
} PACKED_GLboolean_GLenum;
typedef void (*FUNC_void_GLfloat)(GLfloat width);
typedef struct {
    GLfloat a1;
} ARGS_void_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLfloat func;
    ARGS_void_GLfloat args;
} PACKED_void_GLfloat;
typedef void (*FUNC_void_GLenum_GLint)(GLenum pname, GLint param);
typedef struct {
    GLenum a1;
    GLint a2;
} ARGS_void_GLenum_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint func;
    ARGS_void_GLenum_GLint args;
} PACKED_void_GLenum_GLint;
typedef void (*FUNC_void_GLfloat_GLfloat)(GLfloat factor, GLfloat units);
typedef struct {
    GLfloat a1;
    GLfloat a2;
} ARGS_void_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLfloat_GLfloat func;
    ARGS_void_GLfloat_GLfloat args;
} PACKED_void_GLfloat_GLfloat;
typedef void (*FUNC_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels);
typedef struct {
    GLint a1;
    GLint a2;
    GLsizei a3;
    GLsizei a4;
    GLenum a5;
    GLenum a6;
    GLvoid * a7;
} ARGS_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ func;
    ARGS_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ args;
} PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__;
typedef void (*FUNC_void_GLenum_GLenum_GLsizei_GLsizei)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLsizei a3;
    GLsizei a4;
} ARGS_void_GLenum_GLenum_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLsizei_GLsizei func;
    ARGS_void_GLenum_GLenum_GLsizei_GLsizei args;
} PACKED_void_GLenum_GLenum_GLsizei_GLsizei;
typedef void (*FUNC_void_GLclampf_GLboolean)(GLclampf value, GLboolean invert);
typedef struct {
    GLclampf a1;
    GLboolean a2;
} ARGS_void_GLclampf_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLclampf_GLboolean func;
    ARGS_void_GLclampf_GLboolean args;
} PACKED_void_GLclampf_GLboolean;
typedef void (*FUNC_void_GLint_GLint_GLsizei_GLsizei)(GLint x, GLint y, GLsizei width, GLsizei height);
typedef struct {
    GLint a1;
    GLint a2;
    GLsizei a3;
    GLsizei a4;
} ARGS_void_GLint_GLint_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLint_GLint_GLsizei_GLsizei func;
    ARGS_void_GLint_GLint_GLsizei_GLsizei args;
} PACKED_void_GLint_GLint_GLsizei_GLsizei;
typedef void (*FUNC_void_GLsizei_const_GLuint___GENPT___GLenum_const_GLvoid___GENPT___GLsizei)(GLsizei n, const GLuint * shaders, GLenum binaryformat, const GLvoid * binary, GLsizei length);
typedef struct {
    GLsizei a1;
    const GLuint * a2;
    GLenum a3;
    const GLvoid * a4;
    GLsizei a5;
} ARGS_void_GLsizei_const_GLuint___GENPT___GLenum_const_GLvoid___GENPT___GLsizei;
typedef struct {
    int format;
    FUNC_void_GLsizei_const_GLuint___GENPT___GLenum_const_GLvoid___GENPT___GLsizei func;
    ARGS_void_GLsizei_const_GLuint___GENPT___GLenum_const_GLvoid___GENPT___GLsizei args;
} PACKED_void_GLsizei_const_GLuint___GENPT___GLenum_const_GLvoid___GENPT___GLsizei;
typedef void (*FUNC_void_GLuint_GLsizei_const_GLchar___GENPT___const___GENPT___const_GLint___GENPT__)(GLuint shader, GLsizei count, const GLchar * const * string, const GLint * length);
typedef struct {
    GLuint a1;
    GLsizei a2;
    const GLchar * const * a3;
    const GLint * a4;
} ARGS_void_GLuint_GLsizei_const_GLchar___GENPT___const___GENPT___const_GLint___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_const_GLchar___GENPT___const___GENPT___const_GLint___GENPT__ func;
    ARGS_void_GLuint_GLsizei_const_GLchar___GENPT___const___GENPT___const_GLint___GENPT__ args;
} PACKED_void_GLuint_GLsizei_const_GLchar___GENPT___const___GENPT___const_GLint___GENPT__;
typedef void (*FUNC_void_GLenum_GLint_GLuint)(GLenum func, GLint ref, GLuint mask);
typedef struct {
    GLenum a1;
    GLint a2;
    GLuint a3;
} ARGS_void_GLenum_GLint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLuint func;
    ARGS_void_GLenum_GLint_GLuint args;
} PACKED_void_GLenum_GLint_GLuint;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLuint)(GLenum face, GLenum func, GLint ref, GLuint mask);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLuint a4;
} ARGS_void_GLenum_GLenum_GLint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLuint func;
    ARGS_void_GLenum_GLenum_GLint_GLuint args;
} PACKED_void_GLenum_GLenum_GLint_GLuint;
typedef void (*FUNC_void_GLenum_GLenum_GLenum)(GLenum fail, GLenum zfail, GLenum zpass);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLenum a3;
} ARGS_void_GLenum_GLenum_GLenum;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLenum func;
    ARGS_void_GLenum_GLenum_GLenum args;
} PACKED_void_GLenum_GLenum_GLenum;
typedef void (*FUNC_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels);
typedef struct {
    GLenum a1;
    GLint a2;
    GLint a3;
    GLsizei a4;
    GLsizei a5;
    GLint a6;
    GLenum a7;
    GLenum a8;
    const GLvoid * a9;
} ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__;
typedef void (*FUNC_void_GLenum_GLenum_GLfloat)(GLenum target, GLenum pname, GLfloat param);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLfloat a3;
} ARGS_void_GLenum_GLenum_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLfloat func;
    ARGS_void_GLenum_GLenum_GLfloat args;
} PACKED_void_GLenum_GLenum_GLfloat;
typedef void (*FUNC_void_GLenum_GLenum_const_GLfloat___GENPT__)(GLenum target, GLenum pname, const GLfloat * params);
typedef struct {
    GLenum a1;
    GLenum a2;
    const GLfloat * a3;
} ARGS_void_GLenum_GLenum_const_GLfloat___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_const_GLfloat___GENPT__ func;
    ARGS_void_GLenum_GLenum_const_GLfloat___GENPT__ args;
} PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__;
typedef void (*FUNC_void_GLenum_GLenum_GLint)(GLenum target, GLenum pname, GLint param);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
} ARGS_void_GLenum_GLenum_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint func;
    ARGS_void_GLenum_GLenum_GLint args;
} PACKED_void_GLenum_GLenum_GLint;
typedef void (*FUNC_void_GLenum_GLenum_const_GLint___GENPT__)(GLenum target, GLenum pname, const GLint * params);
typedef struct {
    GLenum a1;
    GLenum a2;
    const GLint * a3;
} ARGS_void_GLenum_GLenum_const_GLint___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_const_GLint___GENPT__ func;
    ARGS_void_GLenum_GLenum_const_GLint___GENPT__ args;
} PACKED_void_GLenum_GLenum_const_GLint___GENPT__;
typedef void (*FUNC_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels);
typedef struct {
    GLenum a1;
    GLint a2;
    GLint a3;
    GLint a4;
    GLsizei a5;
    GLsizei a6;
    GLenum a7;
    GLenum a8;
    const GLvoid * a9;
} ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
typedef void (*FUNC_void_GLint_GLfloat)(GLint location, GLfloat v0);
typedef struct {
    GLint a1;
    GLfloat a2;
} ARGS_void_GLint_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLint_GLfloat func;
    ARGS_void_GLint_GLfloat args;
} PACKED_void_GLint_GLfloat;
typedef void (*FUNC_void_GLint_GLsizei_const_GLfloat___GENPT__)(GLint location, GLsizei count, const GLfloat * value);
typedef struct {
    GLint a1;
    GLsizei a2;
    const GLfloat * a3;
} ARGS_void_GLint_GLsizei_const_GLfloat___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLint_GLsizei_const_GLfloat___GENPT__ func;
    ARGS_void_GLint_GLsizei_const_GLfloat___GENPT__ args;
} PACKED_void_GLint_GLsizei_const_GLfloat___GENPT__;
typedef void (*FUNC_void_GLint_GLint)(GLint location, GLint v0);
typedef struct {
    GLint a1;
    GLint a2;
} ARGS_void_GLint_GLint;
typedef struct {
    int format;
    FUNC_void_GLint_GLint func;
    ARGS_void_GLint_GLint args;
} PACKED_void_GLint_GLint;
typedef void (*FUNC_void_GLint_GLsizei_const_GLint___GENPT__)(GLint location, GLsizei count, const GLint * value);
typedef struct {
    GLint a1;
    GLsizei a2;
    const GLint * a3;
} ARGS_void_GLint_GLsizei_const_GLint___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLint_GLsizei_const_GLint___GENPT__ func;
    ARGS_void_GLint_GLsizei_const_GLint___GENPT__ args;
} PACKED_void_GLint_GLsizei_const_GLint___GENPT__;
typedef void (*FUNC_void_GLint_GLfloat_GLfloat)(GLint location, GLfloat v0, GLfloat v1);
typedef struct {
    GLint a1;
    GLfloat a2;
    GLfloat a3;
} ARGS_void_GLint_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLint_GLfloat_GLfloat func;
    ARGS_void_GLint_GLfloat_GLfloat args;
} PACKED_void_GLint_GLfloat_GLfloat;
typedef void (*FUNC_void_GLint_GLint_GLint)(GLint location, GLint v0, GLint v1);
typedef struct {
    GLint a1;
    GLint a2;
    GLint a3;
} ARGS_void_GLint_GLint_GLint;
typedef struct {
    int format;
    FUNC_void_GLint_GLint_GLint func;
    ARGS_void_GLint_GLint_GLint args;
} PACKED_void_GLint_GLint_GLint;
typedef void (*FUNC_void_GLint_GLfloat_GLfloat_GLfloat)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef struct {
    GLint a1;
    GLfloat a2;
    GLfloat a3;
    GLfloat a4;
} ARGS_void_GLint_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLint_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLint_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLint_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLint_GLint_GLint_GLint)(GLint location, GLint v0, GLint v1, GLint v2);
typedef struct {
    GLint a1;
    GLint a2;
    GLint a3;
    GLint a4;
} ARGS_void_GLint_GLint_GLint_GLint;
typedef struct {
    int format;
    FUNC_void_GLint_GLint_GLint_GLint func;
    ARGS_void_GLint_GLint_GLint_GLint args;
} PACKED_void_GLint_GLint_GLint_GLint;
typedef void (*FUNC_void_GLint_GLfloat_GLfloat_GLfloat_GLfloat)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef struct {
    GLint a1;
    GLfloat a2;
    GLfloat a3;
    GLfloat a4;
    GLfloat a5;
} ARGS_void_GLint_GLfloat_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLint_GLfloat_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLint_GLfloat_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLint_GLfloat_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLint_GLint_GLint_GLint_GLint)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef struct {
    GLint a1;
    GLint a2;
    GLint a3;
    GLint a4;
    GLint a5;
} ARGS_void_GLint_GLint_GLint_GLint_GLint;
typedef struct {
    int format;
    FUNC_void_GLint_GLint_GLint_GLint_GLint func;
    ARGS_void_GLint_GLint_GLint_GLint_GLint args;
} PACKED_void_GLint_GLint_GLint_GLint_GLint;
typedef void (*FUNC_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
typedef struct {
    GLint a1;
    GLsizei a2;
    GLboolean a3;
    const GLfloat * a4;
} ARGS_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__ func;
    ARGS_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__ args;
} PACKED_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__;
typedef void (*FUNC_void_GLuint_GLfloat)(GLuint index, GLfloat x);
typedef struct {
    GLuint a1;
    GLfloat a2;
} ARGS_void_GLuint_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLfloat func;
    ARGS_void_GLuint_GLfloat args;
} PACKED_void_GLuint_GLfloat;
typedef void (*FUNC_void_GLuint_const_GLfloat___GENPT__)(GLuint index, const GLfloat * v);
typedef struct {
    GLuint a1;
    const GLfloat * a2;
} ARGS_void_GLuint_const_GLfloat___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLuint_const_GLfloat___GENPT__ func;
    ARGS_void_GLuint_const_GLfloat___GENPT__ args;
} PACKED_void_GLuint_const_GLfloat___GENPT__;
typedef void (*FUNC_void_GLuint_GLfloat_GLfloat)(GLuint index, GLfloat x, GLfloat y);
typedef struct {
    GLuint a1;
    GLfloat a2;
    GLfloat a3;
} ARGS_void_GLuint_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLfloat_GLfloat func;
    ARGS_void_GLuint_GLfloat_GLfloat args;
} PACKED_void_GLuint_GLfloat_GLfloat;
typedef void (*FUNC_void_GLuint_GLfloat_GLfloat_GLfloat)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef struct {
    GLuint a1;
    GLfloat a2;
    GLfloat a3;
    GLfloat a4;
} ARGS_void_GLuint_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLuint_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLuint_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef struct {
    GLuint a1;
    GLfloat a2;
    GLfloat a3;
    GLfloat a4;
    GLfloat a5;
} ARGS_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLuint_GLint_GLenum_GLboolean_GLsizei_const_GLvoid___GENPT__)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer);
typedef struct {
    GLuint a1;
    GLint a2;
    GLenum a3;
    GLboolean a4;
    GLsizei a5;
    const GLvoid * a6;
} ARGS_void_GLuint_GLint_GLenum_GLboolean_GLsizei_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLenum_GLboolean_GLsizei_const_GLvoid___GENPT__ func;
    ARGS_void_GLuint_GLint_GLenum_GLboolean_GLsizei_const_GLvoid___GENPT__ args;
} PACKED_void_GLuint_GLint_GLenum_GLboolean_GLsizei_const_GLvoid___GENPT__;

extern void glPushCall(void *data);
void glPackedCall(const UnknownCall *packed);
void glActiveTexture(GLenum texture);
void glAttachShader(GLuint program, GLuint shader);
void glBindAttribLocation(GLuint program, GLuint index, const GLchar * name);
void glBindBuffer(GLenum target, GLuint buffer);
void glBindFramebuffer(GLenum target, GLuint framebuffer);
void glBindRenderbuffer(GLenum target, GLuint renderbuffer);
void glBindTexture(GLenum target, GLuint texture);
void glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
void glBlendEquation(GLenum mode);
void glBlendEquationSeparate(GLenum modeRGB, GLenum modeA);
void glBlendFunc(GLenum sfactor, GLenum dfactor);
void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage);
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data);
GLenum glCheckFramebufferStatus(GLenum target);
void glClear(GLbitfield mask);
void glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
void glClearDepthf(GLclampf depth);
void glClearStencil(GLint s);
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
void glCompileShader(GLuint shader);
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data);
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data);
void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLuint glCreateProgram();
GLuint glCreateShader(GLenum type);
void glCullFace(GLenum mode);
void glDeleteBuffers(GLsizei n, const GLuint * buffer);
void glDeleteFramebuffers(GLsizei n, const GLuint * framebuffers);
void glDeleteProgram(GLuint program);
void glDeleteRenderbuffers(GLsizei n, const GLuint * renderbuffers);
void glDeleteShader(GLuint program);
void glDeleteTextures(GLsizei n, const GLuint * textures);
void glDepthFunc(GLenum func);
void glDepthMask(GLboolean flag);
void glDepthRangef(GLclampf zNear, GLclampf zFar);
void glDetachShader(GLuint program, GLuint shader);
void glDisable(GLenum cap);
void glDisableVertexAttribArray(GLuint index);
void glDrawArrays(GLenum mode, GLint first, GLsizei count);
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices);
void glEnable(GLenum cap);
void glEnableVertexAttribArray(GLuint index);
void glFinish();
void glFlush();
void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void glFrontFace(GLenum mode);
void glGenBuffers(GLsizei n, GLuint * buffer);
void glGenFramebuffers(GLsizei n, GLuint * framebuffers);
void glGenRenderbuffers(GLsizei n, GLuint * renderbuffers);
void glGenTextures(GLsizei n, GLuint * textures);
void glGenerateMipmap(GLenum target);
void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name);
void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * obj);
GLint glGetAttribLocation(GLuint program, const GLchar * name);
void glGetBooleanv(GLenum pname, GLboolean * params);
void glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params);
GLenum glGetError();
void glGetFloatv(GLenum pname, GLfloat * params);
void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint * params);
void glGetIntegerv(GLenum pname, GLint * params);
void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
void glGetProgramiv(GLuint program, GLenum pname, GLint * params);
void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params);
void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog);
void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision);
void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source);
void glGetShaderiv(GLuint shader, GLenum pname, GLint * params);
const GLubyte * glGetString(GLenum name);
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params);
void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params);
GLint glGetUniformLocation(GLuint program, const GLchar * name);
void glGetUniformfv(GLuint program, GLint location, GLfloat * params);
void glGetUniformiv(GLuint program, GLint location, GLint * params);
void glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid ** pointer);
void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat * params);
void glGetVertexAttribiv(GLuint index, GLenum pname, GLint * params);
void glHint(GLenum target, GLenum mode);
GLboolean glIsBuffer(GLuint buffer);
GLboolean glIsEnabled(GLenum cap);
GLboolean glIsFramebuffer(GLuint framebuffer);
GLboolean glIsProgram(GLuint program);
GLboolean glIsRenderbuffer(GLuint renderbuffer);
GLboolean glIsShader(GLuint shader);
GLboolean glIsTexture(GLuint texture);
void glLineWidth(GLfloat width);
void glLinkProgram(GLuint program);
void glPixelStorei(GLenum pname, GLint param);
void glPolygonOffset(GLfloat factor, GLfloat units);
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels);
void glReleaseShaderCompiler();
void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
void glSampleCoverage(GLclampf value, GLboolean invert);
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
void glShaderBinary(GLsizei n, const GLuint * shaders, GLenum binaryformat, const GLvoid * binary, GLsizei length);
void glShaderSource(GLuint shader, GLsizei count, const GLchar * const * string, const GLint * length);
void glStencilFunc(GLenum func, GLint ref, GLuint mask);
void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask);
void glStencilMask(GLuint mask);
void glStencilMaskSeparate(GLenum face, GLuint mask);
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass);
void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum zfail, GLenum zpass);
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels);
void glTexParameterf(GLenum target, GLenum pname, GLfloat param);
void glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params);
void glTexParameteri(GLenum target, GLenum pname, GLint param);
void glTexParameteriv(GLenum target, GLenum pname, const GLint * params);
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels);
void glUniform1f(GLint location, GLfloat v0);
void glUniform1fv(GLint location, GLsizei count, const GLfloat * value);
void glUniform1i(GLint location, GLint v0);
void glUniform1iv(GLint location, GLsizei count, const GLint * value);
void glUniform2f(GLint location, GLfloat v0, GLfloat v1);
void glUniform2fv(GLint location, GLsizei count, const GLfloat * value);
void glUniform2i(GLint location, GLint v0, GLint v1);
void glUniform2iv(GLint location, GLsizei count, const GLint * value);
void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void glUniform3fv(GLint location, GLsizei count, const GLfloat * value);
void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2);
void glUniform3iv(GLint location, GLsizei count, const GLint * value);
void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void glUniform4fv(GLint location, GLsizei count, const GLfloat * value);
void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void glUniform4iv(GLint location, GLsizei count, const GLint * value);
void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value);
void glUseProgram(GLuint program);
void glValidateProgram(GLuint program);
void glVertexAttrib1f(GLuint index, GLfloat x);
void glVertexAttrib1fv(GLuint index, const GLfloat * v);
void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y);
void glVertexAttrib2fv(GLuint index, const GLfloat * v);
void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z);
void glVertexAttrib3fv(GLuint index, const GLfloat * v);
void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glVertexAttrib4fv(GLuint index, const GLfloat * v);
void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer);
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height);

#ifndef direct_glActiveTexture
static inline void push_glActiveTexture(GLenum texture) {
    PACKED_void_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum));
    packed_data->format = FORMAT_void_GLenum;
    packed_data->func = glActiveTexture;
    packed_data->args.a1 = texture;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glAttachShader
static inline void push_glAttachShader(GLuint program, GLuint shader) {
    PACKED_void_GLuint_GLuint *packed_data = malloc(sizeof(PACKED_void_GLuint_GLuint));
    packed_data->format = FORMAT_void_GLuint_GLuint;
    packed_data->func = glAttachShader;
    packed_data->args.a1 = program;
    packed_data->args.a2 = shader;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glBindAttribLocation
static inline void push_glBindAttribLocation(GLuint program, GLuint index, const GLchar * name) {
    PACKED_void_GLuint_GLuint_const_GLchar___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLuint_GLuint_const_GLchar___GENPT__));
    packed_data->format = FORMAT_void_GLuint_GLuint_const_GLchar___GENPT__;
    packed_data->func = glBindAttribLocation;
    packed_data->args.a1 = program;
    packed_data->args.a2 = index;
    packed_data->args.a3 = name;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glBindBuffer
static inline void push_glBindBuffer(GLenum target, GLuint buffer) {
    PACKED_void_GLenum_GLuint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLuint));
    packed_data->format = FORMAT_void_GLenum_GLuint;
    packed_data->func = glBindBuffer;
    packed_data->args.a1 = target;
    packed_data->args.a2 = buffer;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glBindFramebuffer
static inline void push_glBindFramebuffer(GLenum target, GLuint framebuffer) {
    PACKED_void_GLenum_GLuint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLuint));
    packed_data->format = FORMAT_void_GLenum_GLuint;
    packed_data->func = glBindFramebuffer;
    packed_data->args.a1 = target;
    packed_data->args.a2 = framebuffer;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glBindRenderbuffer
static inline void push_glBindRenderbuffer(GLenum target, GLuint renderbuffer) {
    PACKED_void_GLenum_GLuint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLuint));
    packed_data->format = FORMAT_void_GLenum_GLuint;
    packed_data->func = glBindRenderbuffer;
    packed_data->args.a1 = target;
    packed_data->args.a2 = renderbuffer;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glBindTexture
static inline void push_glBindTexture(GLenum target, GLuint texture) {
    PACKED_void_GLenum_GLuint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLuint));
    packed_data->format = FORMAT_void_GLenum_GLuint;
    packed_data->func = glBindTexture;
    packed_data->args.a1 = target;
    packed_data->args.a2 = texture;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glBlendColor
static inline void push_glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
    PACKED_void_GLclampf_GLclampf_GLclampf_GLclampf *packed_data = malloc(sizeof(PACKED_void_GLclampf_GLclampf_GLclampf_GLclampf));
    packed_data->format = FORMAT_void_GLclampf_GLclampf_GLclampf_GLclampf;
    packed_data->func = glBlendColor;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glBlendEquation
static inline void push_glBlendEquation(GLenum mode) {
    PACKED_void_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum));
    packed_data->format = FORMAT_void_GLenum;
    packed_data->func = glBlendEquation;
    packed_data->args.a1 = mode;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glBlendEquationSeparate
static inline void push_glBlendEquationSeparate(GLenum modeRGB, GLenum modeA) {
    PACKED_void_GLenum_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum));
    packed_data->format = FORMAT_void_GLenum_GLenum;
    packed_data->func = glBlendEquationSeparate;
    packed_data->args.a1 = modeRGB;
    packed_data->args.a2 = modeA;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glBlendFunc
static inline void push_glBlendFunc(GLenum sfactor, GLenum dfactor) {
    PACKED_void_GLenum_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum));
    packed_data->format = FORMAT_void_GLenum_GLenum;
    packed_data->func = glBlendFunc;
    packed_data->args.a1 = sfactor;
    packed_data->args.a2 = dfactor;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glBlendFuncSeparate
static inline void push_glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
    PACKED_void_GLenum_GLenum_GLenum_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLenum_GLenum));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLenum_GLenum;
    packed_data->func = glBlendFuncSeparate;
    packed_data->args.a1 = sfactorRGB;
    packed_data->args.a2 = dfactorRGB;
    packed_data->args.a3 = sfactorAlpha;
    packed_data->args.a4 = dfactorAlpha;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glBufferData
static inline void push_glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage) {
    PACKED_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum));
    packed_data->format = FORMAT_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum;
    packed_data->func = glBufferData;
    packed_data->args.a1 = target;
    packed_data->args.a2 = size;
    packed_data->args.a3 = data;
    packed_data->args.a4 = usage;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glBufferSubData
static inline void push_glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data) {
    PACKED_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__;
    packed_data->func = glBufferSubData;
    packed_data->args.a1 = target;
    packed_data->args.a2 = offset;
    packed_data->args.a3 = size;
    packed_data->args.a4 = data;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glCheckFramebufferStatus
static inline void push_glCheckFramebufferStatus(GLenum target) {
    PACKED_GLenum_GLenum *packed_data = malloc(sizeof(PACKED_GLenum_GLenum));
    packed_data->format = FORMAT_GLenum_GLenum;
    packed_data->func = glCheckFramebufferStatus;
    packed_data->args.a1 = target;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glClear
static inline void push_glClear(GLbitfield mask) {
    PACKED_void_GLbitfield *packed_data = malloc(sizeof(PACKED_void_GLbitfield));
    packed_data->format = FORMAT_void_GLbitfield;
    packed_data->func = glClear;
    packed_data->args.a1 = mask;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glClearColor
static inline void push_glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
    PACKED_void_GLclampf_GLclampf_GLclampf_GLclampf *packed_data = malloc(sizeof(PACKED_void_GLclampf_GLclampf_GLclampf_GLclampf));
    packed_data->format = FORMAT_void_GLclampf_GLclampf_GLclampf_GLclampf;
    packed_data->func = glClearColor;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glClearDepthf
static inline void push_glClearDepthf(GLclampf depth) {
    PACKED_void_GLclampf *packed_data = malloc(sizeof(PACKED_void_GLclampf));
    packed_data->format = FORMAT_void_GLclampf;
    packed_data->func = glClearDepthf;
    packed_data->args.a1 = depth;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glClearStencil
static inline void push_glClearStencil(GLint s) {
    PACKED_void_GLint *packed_data = malloc(sizeof(PACKED_void_GLint));
    packed_data->format = FORMAT_void_GLint;
    packed_data->func = glClearStencil;
    packed_data->args.a1 = s;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColorMask
static inline void push_glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
    PACKED_void_GLboolean_GLboolean_GLboolean_GLboolean *packed_data = malloc(sizeof(PACKED_void_GLboolean_GLboolean_GLboolean_GLboolean));
    packed_data->format = FORMAT_void_GLboolean_GLboolean_GLboolean_GLboolean;
    packed_data->func = glColorMask;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glCompileShader
static inline void push_glCompileShader(GLuint shader) {
    PACKED_void_GLuint *packed_data = malloc(sizeof(PACKED_void_GLuint));
    packed_data->format = FORMAT_void_GLuint;
    packed_data->func = glCompileShader;
    packed_data->args.a1 = shader;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glCompressedTexImage2D
static inline void push_glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data) {
    PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__;
    packed_data->func = glCompressedTexImage2D;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = internalformat;
    packed_data->args.a4 = width;
    packed_data->args.a5 = height;
    packed_data->args.a6 = border;
    packed_data->args.a7 = imageSize;
    packed_data->args.a8 = data;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glCompressedTexSubImage2D
static inline void push_glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data) {
    PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__;
    packed_data->func = glCompressedTexSubImage2D;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = xoffset;
    packed_data->args.a4 = yoffset;
    packed_data->args.a5 = width;
    packed_data->args.a6 = height;
    packed_data->args.a7 = format;
    packed_data->args.a8 = imageSize;
    packed_data->args.a9 = data;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glCopyTexImage2D
static inline void push_glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    PACKED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint));
    packed_data->format = FORMAT_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint;
    packed_data->func = glCopyTexImage2D;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = internalformat;
    packed_data->args.a4 = x;
    packed_data->args.a5 = y;
    packed_data->args.a6 = width;
    packed_data->args.a7 = height;
    packed_data->args.a8 = border;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glCopyTexSubImage2D
static inline void push_glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei));
    packed_data->format = FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei;
    packed_data->func = glCopyTexSubImage2D;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = xoffset;
    packed_data->args.a4 = yoffset;
    packed_data->args.a5 = x;
    packed_data->args.a6 = y;
    packed_data->args.a7 = width;
    packed_data->args.a8 = height;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glCreateProgram
static inline void push_glCreateProgram() {
    PACKED_GLuint *packed_data = malloc(sizeof(PACKED_GLuint));
    packed_data->format = FORMAT_GLuint;
    packed_data->func = glCreateProgram;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glCreateShader
static inline void push_glCreateShader(GLenum type) {
    PACKED_GLuint_GLenum *packed_data = malloc(sizeof(PACKED_GLuint_GLenum));
    packed_data->format = FORMAT_GLuint_GLenum;
    packed_data->func = glCreateShader;
    packed_data->args.a1 = type;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glCullFace
static inline void push_glCullFace(GLenum mode) {
    PACKED_void_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum));
    packed_data->format = FORMAT_void_GLenum;
    packed_data->func = glCullFace;
    packed_data->args.a1 = mode;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glDeleteBuffers
static inline void push_glDeleteBuffers(GLsizei n, const GLuint * buffer) {
    PACKED_void_GLsizei_const_GLuint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLsizei_const_GLuint___GENPT__));
    packed_data->format = FORMAT_void_GLsizei_const_GLuint___GENPT__;
    packed_data->func = glDeleteBuffers;
    packed_data->args.a1 = n;
    packed_data->args.a2 = buffer;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glDeleteFramebuffers
static inline void push_glDeleteFramebuffers(GLsizei n, const GLuint * framebuffers) {
    PACKED_void_GLsizei_const_GLuint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLsizei_const_GLuint___GENPT__));
    packed_data->format = FORMAT_void_GLsizei_const_GLuint___GENPT__;
    packed_data->func = glDeleteFramebuffers;
    packed_data->args.a1 = n;
    packed_data->args.a2 = framebuffers;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glDeleteProgram
static inline void push_glDeleteProgram(GLuint program) {
    PACKED_void_GLuint *packed_data = malloc(sizeof(PACKED_void_GLuint));
    packed_data->format = FORMAT_void_GLuint;
    packed_data->func = glDeleteProgram;
    packed_data->args.a1 = program;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glDeleteRenderbuffers
static inline void push_glDeleteRenderbuffers(GLsizei n, const GLuint * renderbuffers) {
    PACKED_void_GLsizei_const_GLuint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLsizei_const_GLuint___GENPT__));
    packed_data->format = FORMAT_void_GLsizei_const_GLuint___GENPT__;
    packed_data->func = glDeleteRenderbuffers;
    packed_data->args.a1 = n;
    packed_data->args.a2 = renderbuffers;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glDeleteShader
static inline void push_glDeleteShader(GLuint program) {
    PACKED_void_GLuint *packed_data = malloc(sizeof(PACKED_void_GLuint));
    packed_data->format = FORMAT_void_GLuint;
    packed_data->func = glDeleteShader;
    packed_data->args.a1 = program;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glDeleteTextures
static inline void push_glDeleteTextures(GLsizei n, const GLuint * textures) {
    PACKED_void_GLsizei_const_GLuint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLsizei_const_GLuint___GENPT__));
    packed_data->format = FORMAT_void_GLsizei_const_GLuint___GENPT__;
    packed_data->func = glDeleteTextures;
    packed_data->args.a1 = n;
    packed_data->args.a2 = textures;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glDepthFunc
static inline void push_glDepthFunc(GLenum func) {
    PACKED_void_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum));
    packed_data->format = FORMAT_void_GLenum;
    packed_data->func = glDepthFunc;
    packed_data->args.a1 = func;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glDepthMask
static inline void push_glDepthMask(GLboolean flag) {
    PACKED_void_GLboolean *packed_data = malloc(sizeof(PACKED_void_GLboolean));
    packed_data->format = FORMAT_void_GLboolean;
    packed_data->func = glDepthMask;
    packed_data->args.a1 = flag;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glDepthRangef
static inline void push_glDepthRangef(GLclampf zNear, GLclampf zFar) {
    PACKED_void_GLclampf_GLclampf *packed_data = malloc(sizeof(PACKED_void_GLclampf_GLclampf));
    packed_data->format = FORMAT_void_GLclampf_GLclampf;
    packed_data->func = glDepthRangef;
    packed_data->args.a1 = zNear;
    packed_data->args.a2 = zFar;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glDetachShader
static inline void push_glDetachShader(GLuint program, GLuint shader) {
    PACKED_void_GLuint_GLuint *packed_data = malloc(sizeof(PACKED_void_GLuint_GLuint));
    packed_data->format = FORMAT_void_GLuint_GLuint;
    packed_data->func = glDetachShader;
    packed_data->args.a1 = program;
    packed_data->args.a2 = shader;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glDisable
static inline void push_glDisable(GLenum cap) {
    PACKED_void_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum));
    packed_data->format = FORMAT_void_GLenum;
    packed_data->func = glDisable;
    packed_data->args.a1 = cap;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glDisableVertexAttribArray
static inline void push_glDisableVertexAttribArray(GLuint index) {
    PACKED_void_GLuint *packed_data = malloc(sizeof(PACKED_void_GLuint));
    packed_data->format = FORMAT_void_GLuint;
    packed_data->func = glDisableVertexAttribArray;
    packed_data->args.a1 = index;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glDrawArrays
static inline void push_glDrawArrays(GLenum mode, GLint first, GLsizei count) {
    PACKED_void_GLenum_GLint_GLsizei *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLsizei));
    packed_data->format = FORMAT_void_GLenum_GLint_GLsizei;
    packed_data->func = glDrawArrays;
    packed_data->args.a1 = mode;
    packed_data->args.a2 = first;
    packed_data->args.a3 = count;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glDrawElements
static inline void push_glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices) {
    PACKED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__;
    packed_data->func = glDrawElements;
    packed_data->args.a1 = mode;
    packed_data->args.a2 = count;
    packed_data->args.a3 = type;
    packed_data->args.a4 = indices;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glEnable
static inline void push_glEnable(GLenum cap) {
    PACKED_void_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum));
    packed_data->format = FORMAT_void_GLenum;
    packed_data->func = glEnable;
    packed_data->args.a1 = cap;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glEnableVertexAttribArray
static inline void push_glEnableVertexAttribArray(GLuint index) {
    PACKED_void_GLuint *packed_data = malloc(sizeof(PACKED_void_GLuint));
    packed_data->format = FORMAT_void_GLuint;
    packed_data->func = glEnableVertexAttribArray;
    packed_data->args.a1 = index;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glFinish
static inline void push_glFinish() {
    PACKED_void *packed_data = malloc(sizeof(PACKED_void));
    packed_data->format = FORMAT_void;
    packed_data->func = glFinish;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glFlush
static inline void push_glFlush() {
    PACKED_void *packed_data = malloc(sizeof(PACKED_void));
    packed_data->format = FORMAT_void;
    packed_data->func = glFlush;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glFramebufferRenderbuffer
static inline void push_glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
    PACKED_void_GLenum_GLenum_GLenum_GLuint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLenum_GLuint));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLenum_GLuint;
    packed_data->func = glFramebufferRenderbuffer;
    packed_data->args.a1 = target;
    packed_data->args.a2 = attachment;
    packed_data->args.a3 = renderbuffertarget;
    packed_data->args.a4 = renderbuffer;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glFramebufferTexture2D
static inline void push_glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
    PACKED_void_GLenum_GLenum_GLenum_GLuint_GLint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLenum_GLuint_GLint));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLenum_GLuint_GLint;
    packed_data->func = glFramebufferTexture2D;
    packed_data->args.a1 = target;
    packed_data->args.a2 = attachment;
    packed_data->args.a3 = textarget;
    packed_data->args.a4 = texture;
    packed_data->args.a5 = level;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glFrontFace
static inline void push_glFrontFace(GLenum mode) {
    PACKED_void_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum));
    packed_data->format = FORMAT_void_GLenum;
    packed_data->func = glFrontFace;
    packed_data->args.a1 = mode;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGenBuffers
static inline void push_glGenBuffers(GLsizei n, GLuint * buffer) {
    PACKED_void_GLsizei_GLuint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLsizei_GLuint___GENPT__));
    packed_data->format = FORMAT_void_GLsizei_GLuint___GENPT__;
    packed_data->func = glGenBuffers;
    packed_data->args.a1 = n;
    packed_data->args.a2 = buffer;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGenFramebuffers
static inline void push_glGenFramebuffers(GLsizei n, GLuint * framebuffers) {
    PACKED_void_GLsizei_GLuint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLsizei_GLuint___GENPT__));
    packed_data->format = FORMAT_void_GLsizei_GLuint___GENPT__;
    packed_data->func = glGenFramebuffers;
    packed_data->args.a1 = n;
    packed_data->args.a2 = framebuffers;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGenRenderbuffers
static inline void push_glGenRenderbuffers(GLsizei n, GLuint * renderbuffers) {
    PACKED_void_GLsizei_GLuint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLsizei_GLuint___GENPT__));
    packed_data->format = FORMAT_void_GLsizei_GLuint___GENPT__;
    packed_data->func = glGenRenderbuffers;
    packed_data->args.a1 = n;
    packed_data->args.a2 = renderbuffers;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGenTextures
static inline void push_glGenTextures(GLsizei n, GLuint * textures) {
    PACKED_void_GLsizei_GLuint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLsizei_GLuint___GENPT__));
    packed_data->format = FORMAT_void_GLsizei_GLuint___GENPT__;
    packed_data->func = glGenTextures;
    packed_data->args.a1 = n;
    packed_data->args.a2 = textures;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGenerateMipmap
static inline void push_glGenerateMipmap(GLenum target) {
    PACKED_void_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum));
    packed_data->format = FORMAT_void_GLenum;
    packed_data->func = glGenerateMipmap;
    packed_data->args.a1 = target;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetActiveAttrib
static inline void push_glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) {
    PACKED_void_GLuint_GLuint_GLsizei_GLsizei___GENPT___GLint___GENPT___GLenum___GENPT___GLchar___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLuint_GLuint_GLsizei_GLsizei___GENPT___GLint___GENPT___GLenum___GENPT___GLchar___GENPT__));
    packed_data->format = FORMAT_void_GLuint_GLuint_GLsizei_GLsizei___GENPT___GLint___GENPT___GLenum___GENPT___GLchar___GENPT__;
    packed_data->func = glGetActiveAttrib;
    packed_data->args.a1 = program;
    packed_data->args.a2 = index;
    packed_data->args.a3 = bufSize;
    packed_data->args.a4 = length;
    packed_data->args.a5 = size;
    packed_data->args.a6 = type;
    packed_data->args.a7 = name;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetActiveUniform
static inline void push_glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) {
    PACKED_void_GLuint_GLuint_GLsizei_GLsizei___GENPT___GLint___GENPT___GLenum___GENPT___GLchar___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLuint_GLuint_GLsizei_GLsizei___GENPT___GLint___GENPT___GLenum___GENPT___GLchar___GENPT__));
    packed_data->format = FORMAT_void_GLuint_GLuint_GLsizei_GLsizei___GENPT___GLint___GENPT___GLenum___GENPT___GLchar___GENPT__;
    packed_data->func = glGetActiveUniform;
    packed_data->args.a1 = program;
    packed_data->args.a2 = index;
    packed_data->args.a3 = bufSize;
    packed_data->args.a4 = length;
    packed_data->args.a5 = size;
    packed_data->args.a6 = type;
    packed_data->args.a7 = name;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetAttachedShaders
static inline void push_glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * obj) {
    PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLuint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLuint___GENPT__));
    packed_data->format = FORMAT_void_GLuint_GLsizei_GLsizei___GENPT___GLuint___GENPT__;
    packed_data->func = glGetAttachedShaders;
    packed_data->args.a1 = program;
    packed_data->args.a2 = maxCount;
    packed_data->args.a3 = count;
    packed_data->args.a4 = obj;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetAttribLocation
static inline void push_glGetAttribLocation(GLuint program, const GLchar * name) {
    PACKED_GLint_GLuint_const_GLchar___GENPT__ *packed_data = malloc(sizeof(PACKED_GLint_GLuint_const_GLchar___GENPT__));
    packed_data->format = FORMAT_GLint_GLuint_const_GLchar___GENPT__;
    packed_data->func = glGetAttribLocation;
    packed_data->args.a1 = program;
    packed_data->args.a2 = name;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetBooleanv
static inline void push_glGetBooleanv(GLenum pname, GLboolean * params) {
    PACKED_void_GLenum_GLboolean___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLboolean___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLboolean___GENPT__;
    packed_data->func = glGetBooleanv;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetBufferParameteriv
static inline void push_glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    PACKED_void_GLenum_GLenum_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLint___GENPT__;
    packed_data->func = glGetBufferParameteriv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetError
static inline void push_glGetError() {
    PACKED_GLenum *packed_data = malloc(sizeof(PACKED_GLenum));
    packed_data->format = FORMAT_GLenum;
    packed_data->func = glGetError;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetFloatv
static inline void push_glGetFloatv(GLenum pname, GLfloat * params) {
    PACKED_void_GLenum_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLfloat___GENPT__;
    packed_data->func = glGetFloatv;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetFramebufferAttachmentParameteriv
static inline void push_glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint * params) {
    PACKED_void_GLenum_GLenum_GLenum_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLenum_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLenum_GLint___GENPT__;
    packed_data->func = glGetFramebufferAttachmentParameteriv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = attachment;
    packed_data->args.a3 = pname;
    packed_data->args.a4 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetIntegerv
static inline void push_glGetIntegerv(GLenum pname, GLint * params) {
    PACKED_void_GLenum_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLint___GENPT__;
    packed_data->func = glGetIntegerv;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetProgramInfoLog
static inline void push_glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
    PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__));
    packed_data->format = FORMAT_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__;
    packed_data->func = glGetProgramInfoLog;
    packed_data->args.a1 = program;
    packed_data->args.a2 = bufSize;
    packed_data->args.a3 = length;
    packed_data->args.a4 = infoLog;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetProgramiv
static inline void push_glGetProgramiv(GLuint program, GLenum pname, GLint * params) {
    PACKED_void_GLuint_GLenum_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLuint_GLenum_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLuint_GLenum_GLint___GENPT__;
    packed_data->func = glGetProgramiv;
    packed_data->args.a1 = program;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetRenderbufferParameteriv
static inline void push_glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    PACKED_void_GLenum_GLenum_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLint___GENPT__;
    packed_data->func = glGetRenderbufferParameteriv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetShaderInfoLog
static inline void push_glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
    PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__));
    packed_data->format = FORMAT_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__;
    packed_data->func = glGetShaderInfoLog;
    packed_data->args.a1 = shader;
    packed_data->args.a2 = bufSize;
    packed_data->args.a3 = length;
    packed_data->args.a4 = infoLog;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetShaderPrecisionFormat
static inline void push_glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint * range, GLint * precision) {
    PACKED_void_GLenum_GLenum_GLint___GENPT___GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint___GENPT___GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLint___GENPT___GLint___GENPT__;
    packed_data->func = glGetShaderPrecisionFormat;
    packed_data->args.a1 = shadertype;
    packed_data->args.a2 = precisiontype;
    packed_data->args.a3 = range;
    packed_data->args.a4 = precision;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetShaderSource
static inline void push_glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source) {
    PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__));
    packed_data->format = FORMAT_void_GLuint_GLsizei_GLsizei___GENPT___GLchar___GENPT__;
    packed_data->func = glGetShaderSource;
    packed_data->args.a1 = shader;
    packed_data->args.a2 = bufSize;
    packed_data->args.a3 = length;
    packed_data->args.a4 = source;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetShaderiv
static inline void push_glGetShaderiv(GLuint shader, GLenum pname, GLint * params) {
    PACKED_void_GLuint_GLenum_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLuint_GLenum_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLuint_GLenum_GLint___GENPT__;
    packed_data->func = glGetShaderiv;
    packed_data->args.a1 = shader;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetString
static inline void push_glGetString(GLenum name) {
    PACKED_const_GLubyte___GENPT___GLenum *packed_data = malloc(sizeof(PACKED_const_GLubyte___GENPT___GLenum));
    packed_data->format = FORMAT_const_GLubyte___GENPT___GLenum;
    packed_data->func = glGetString;
    packed_data->args.a1 = name;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetTexParameterfv
static inline void push_glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLfloat___GENPT__;
    packed_data->func = glGetTexParameterfv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetTexParameteriv
static inline void push_glGetTexParameteriv(GLenum target, GLenum pname, GLint * params) {
    PACKED_void_GLenum_GLenum_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLint___GENPT__;
    packed_data->func = glGetTexParameteriv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetUniformLocation
static inline void push_glGetUniformLocation(GLuint program, const GLchar * name) {
    PACKED_GLint_GLuint_const_GLchar___GENPT__ *packed_data = malloc(sizeof(PACKED_GLint_GLuint_const_GLchar___GENPT__));
    packed_data->format = FORMAT_GLint_GLuint_const_GLchar___GENPT__;
    packed_data->func = glGetUniformLocation;
    packed_data->args.a1 = program;
    packed_data->args.a2 = name;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetUniformfv
static inline void push_glGetUniformfv(GLuint program, GLint location, GLfloat * params) {
    PACKED_void_GLuint_GLint_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLuint_GLint_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLuint_GLint_GLfloat___GENPT__;
    packed_data->func = glGetUniformfv;
    packed_data->args.a1 = program;
    packed_data->args.a2 = location;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetUniformiv
static inline void push_glGetUniformiv(GLuint program, GLint location, GLint * params) {
    PACKED_void_GLuint_GLint_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLuint_GLint_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLuint_GLint_GLint___GENPT__;
    packed_data->func = glGetUniformiv;
    packed_data->args.a1 = program;
    packed_data->args.a2 = location;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetVertexAttribPointerv
static inline void push_glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid ** pointer) {
    PACKED_void_GLuint_GLenum_GLvoid___GENPT____GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLuint_GLenum_GLvoid___GENPT____GENPT__));
    packed_data->format = FORMAT_void_GLuint_GLenum_GLvoid___GENPT____GENPT__;
    packed_data->func = glGetVertexAttribPointerv;
    packed_data->args.a1 = index;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = pointer;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetVertexAttribfv
static inline void push_glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat * params) {
    PACKED_void_GLuint_GLenum_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLuint_GLenum_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLuint_GLenum_GLfloat___GENPT__;
    packed_data->func = glGetVertexAttribfv;
    packed_data->args.a1 = index;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetVertexAttribiv
static inline void push_glGetVertexAttribiv(GLuint index, GLenum pname, GLint * params) {
    PACKED_void_GLuint_GLenum_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLuint_GLenum_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLuint_GLenum_GLint___GENPT__;
    packed_data->func = glGetVertexAttribiv;
    packed_data->args.a1 = index;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glHint
static inline void push_glHint(GLenum target, GLenum mode) {
    PACKED_void_GLenum_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum));
    packed_data->format = FORMAT_void_GLenum_GLenum;
    packed_data->func = glHint;
    packed_data->args.a1 = target;
    packed_data->args.a2 = mode;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glIsBuffer
static inline void push_glIsBuffer(GLuint buffer) {
    PACKED_GLboolean_GLuint *packed_data = malloc(sizeof(PACKED_GLboolean_GLuint));
    packed_data->format = FORMAT_GLboolean_GLuint;
    packed_data->func = glIsBuffer;
    packed_data->args.a1 = buffer;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glIsEnabled
static inline void push_glIsEnabled(GLenum cap) {
    PACKED_GLboolean_GLenum *packed_data = malloc(sizeof(PACKED_GLboolean_GLenum));
    packed_data->format = FORMAT_GLboolean_GLenum;
    packed_data->func = glIsEnabled;
    packed_data->args.a1 = cap;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glIsFramebuffer
static inline void push_glIsFramebuffer(GLuint framebuffer) {
    PACKED_GLboolean_GLuint *packed_data = malloc(sizeof(PACKED_GLboolean_GLuint));
    packed_data->format = FORMAT_GLboolean_GLuint;
    packed_data->func = glIsFramebuffer;
    packed_data->args.a1 = framebuffer;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glIsProgram
static inline void push_glIsProgram(GLuint program) {
    PACKED_GLboolean_GLuint *packed_data = malloc(sizeof(PACKED_GLboolean_GLuint));
    packed_data->format = FORMAT_GLboolean_GLuint;
    packed_data->func = glIsProgram;
    packed_data->args.a1 = program;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glIsRenderbuffer
static inline void push_glIsRenderbuffer(GLuint renderbuffer) {
    PACKED_GLboolean_GLuint *packed_data = malloc(sizeof(PACKED_GLboolean_GLuint));
    packed_data->format = FORMAT_GLboolean_GLuint;
    packed_data->func = glIsRenderbuffer;
    packed_data->args.a1 = renderbuffer;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glIsShader
static inline void push_glIsShader(GLuint shader) {
    PACKED_GLboolean_GLuint *packed_data = malloc(sizeof(PACKED_GLboolean_GLuint));
    packed_data->format = FORMAT_GLboolean_GLuint;
    packed_data->func = glIsShader;
    packed_data->args.a1 = shader;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glIsTexture
static inline void push_glIsTexture(GLuint texture) {
    PACKED_GLboolean_GLuint *packed_data = malloc(sizeof(PACKED_GLboolean_GLuint));
    packed_data->format = FORMAT_GLboolean_GLuint;
    packed_data->func = glIsTexture;
    packed_data->args.a1 = texture;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glLineWidth
static inline void push_glLineWidth(GLfloat width) {
    PACKED_void_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat));
    packed_data->format = FORMAT_void_GLfloat;
    packed_data->func = glLineWidth;
    packed_data->args.a1 = width;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glLinkProgram
static inline void push_glLinkProgram(GLuint program) {
    PACKED_void_GLuint *packed_data = malloc(sizeof(PACKED_void_GLuint));
    packed_data->format = FORMAT_void_GLuint;
    packed_data->func = glLinkProgram;
    packed_data->args.a1 = program;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glPixelStorei
static inline void push_glPixelStorei(GLenum pname, GLint param) {
    PACKED_void_GLenum_GLint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint));
    packed_data->format = FORMAT_void_GLenum_GLint;
    packed_data->func = glPixelStorei;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glPolygonOffset
static inline void push_glPolygonOffset(GLfloat factor, GLfloat units) {
    PACKED_void_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat;
    packed_data->func = glPolygonOffset;
    packed_data->args.a1 = factor;
    packed_data->args.a2 = units;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glReadPixels
static inline void push_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels) {
    PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__;
    packed_data->func = glReadPixels;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = width;
    packed_data->args.a4 = height;
    packed_data->args.a5 = format;
    packed_data->args.a6 = type;
    packed_data->args.a7 = pixels;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glReleaseShaderCompiler
static inline void push_glReleaseShaderCompiler() {
    PACKED_void *packed_data = malloc(sizeof(PACKED_void));
    packed_data->format = FORMAT_void;
    packed_data->func = glReleaseShaderCompiler;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRenderbufferStorage
static inline void push_glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
    PACKED_void_GLenum_GLenum_GLsizei_GLsizei *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLsizei_GLsizei));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLsizei_GLsizei;
    packed_data->func = glRenderbufferStorage;
    packed_data->args.a1 = target;
    packed_data->args.a2 = internalformat;
    packed_data->args.a3 = width;
    packed_data->args.a4 = height;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glSampleCoverage
static inline void push_glSampleCoverage(GLclampf value, GLboolean invert) {
    PACKED_void_GLclampf_GLboolean *packed_data = malloc(sizeof(PACKED_void_GLclampf_GLboolean));
    packed_data->format = FORMAT_void_GLclampf_GLboolean;
    packed_data->func = glSampleCoverage;
    packed_data->args.a1 = value;
    packed_data->args.a2 = invert;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glScissor
static inline void push_glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {
    PACKED_void_GLint_GLint_GLsizei_GLsizei *packed_data = malloc(sizeof(PACKED_void_GLint_GLint_GLsizei_GLsizei));
    packed_data->format = FORMAT_void_GLint_GLint_GLsizei_GLsizei;
    packed_data->func = glScissor;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = width;
    packed_data->args.a4 = height;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glShaderBinary
static inline void push_glShaderBinary(GLsizei n, const GLuint * shaders, GLenum binaryformat, const GLvoid * binary, GLsizei length) {
    PACKED_void_GLsizei_const_GLuint___GENPT___GLenum_const_GLvoid___GENPT___GLsizei *packed_data = malloc(sizeof(PACKED_void_GLsizei_const_GLuint___GENPT___GLenum_const_GLvoid___GENPT___GLsizei));
    packed_data->format = FORMAT_void_GLsizei_const_GLuint___GENPT___GLenum_const_GLvoid___GENPT___GLsizei;
    packed_data->func = glShaderBinary;
    packed_data->args.a1 = n;
    packed_data->args.a2 = shaders;
    packed_data->args.a3 = binaryformat;
    packed_data->args.a4 = binary;
    packed_data->args.a5 = length;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glShaderSource
static inline void push_glShaderSource(GLuint shader, GLsizei count, const GLchar * const * string, const GLint * length) {
    PACKED_void_GLuint_GLsizei_const_GLchar___GENPT___const___GENPT___const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLuint_GLsizei_const_GLchar___GENPT___const___GENPT___const_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLuint_GLsizei_const_GLchar___GENPT___const___GENPT___const_GLint___GENPT__;
    packed_data->func = glShaderSource;
    packed_data->args.a1 = shader;
    packed_data->args.a2 = count;
    packed_data->args.a3 = string;
    packed_data->args.a4 = length;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glStencilFunc
static inline void push_glStencilFunc(GLenum func, GLint ref, GLuint mask) {
    PACKED_void_GLenum_GLint_GLuint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLuint));
    packed_data->format = FORMAT_void_GLenum_GLint_GLuint;
    packed_data->func = glStencilFunc;
    packed_data->args.a1 = func;
    packed_data->args.a2 = ref;
    packed_data->args.a3 = mask;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glStencilFuncSeparate
static inline void push_glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) {
    PACKED_void_GLenum_GLenum_GLint_GLuint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint_GLuint));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLint_GLuint;
    packed_data->func = glStencilFuncSeparate;
    packed_data->args.a1 = face;
    packed_data->args.a2 = func;
    packed_data->args.a3 = ref;
    packed_data->args.a4 = mask;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glStencilMask
static inline void push_glStencilMask(GLuint mask) {
    PACKED_void_GLuint *packed_data = malloc(sizeof(PACKED_void_GLuint));
    packed_data->format = FORMAT_void_GLuint;
    packed_data->func = glStencilMask;
    packed_data->args.a1 = mask;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glStencilMaskSeparate
static inline void push_glStencilMaskSeparate(GLenum face, GLuint mask) {
    PACKED_void_GLenum_GLuint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLuint));
    packed_data->format = FORMAT_void_GLenum_GLuint;
    packed_data->func = glStencilMaskSeparate;
    packed_data->args.a1 = face;
    packed_data->args.a2 = mask;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glStencilOp
static inline void push_glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
    PACKED_void_GLenum_GLenum_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLenum));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLenum;
    packed_data->func = glStencilOp;
    packed_data->args.a1 = fail;
    packed_data->args.a2 = zfail;
    packed_data->args.a3 = zpass;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glStencilOpSeparate
static inline void push_glStencilOpSeparate(GLenum face, GLenum sfail, GLenum zfail, GLenum zpass) {
    PACKED_void_GLenum_GLenum_GLenum_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLenum_GLenum));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLenum_GLenum;
    packed_data->func = glStencilOpSeparate;
    packed_data->args.a1 = face;
    packed_data->args.a2 = sfail;
    packed_data->args.a3 = zfail;
    packed_data->args.a4 = zpass;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexImage2D
static inline void push_glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels) {
    PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__;
    packed_data->func = glTexImage2D;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = internalformat;
    packed_data->args.a4 = width;
    packed_data->args.a5 = height;
    packed_data->args.a6 = border;
    packed_data->args.a7 = format;
    packed_data->args.a8 = type;
    packed_data->args.a9 = pixels;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexParameterf
static inline void push_glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
    PACKED_void_GLenum_GLenum_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfloat));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLfloat;
    packed_data->func = glTexParameterf;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexParameterfv
static inline void push_glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__;
    packed_data->func = glTexParameterfv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexParameteri
static inline void push_glTexParameteri(GLenum target, GLenum pname, GLint param) {
    PACKED_void_GLenum_GLenum_GLint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLint;
    packed_data->func = glTexParameteri;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexParameteriv
static inline void push_glTexParameteriv(GLenum target, GLenum pname, const GLint * params) {
    PACKED_void_GLenum_GLenum_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_const_GLint___GENPT__;
    packed_data->func = glTexParameteriv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexSubImage2D
static inline void push_glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels) {
    PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
    packed_data->func = glTexSubImage2D;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = xoffset;
    packed_data->args.a4 = yoffset;
    packed_data->args.a5 = width;
    packed_data->args.a6 = height;
    packed_data->args.a7 = format;
    packed_data->args.a8 = type;
    packed_data->args.a9 = pixels;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glUniform1f
static inline void push_glUniform1f(GLint location, GLfloat v0) {
    PACKED_void_GLint_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLint_GLfloat));
    packed_data->format = FORMAT_void_GLint_GLfloat;
    packed_data->func = glUniform1f;
    packed_data->args.a1 = location;
    packed_data->args.a2 = v0;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glUniform1fv
static inline void push_glUniform1fv(GLint location, GLsizei count, const GLfloat * value) {
    PACKED_void_GLint_GLsizei_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLint_GLsizei_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLint_GLsizei_const_GLfloat___GENPT__;
    packed_data->func = glUniform1fv;
    packed_data->args.a1 = location;
    packed_data->args.a2 = count;
    packed_data->args.a3 = value;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glUniform1i
static inline void push_glUniform1i(GLint location, GLint v0) {
    PACKED_void_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLint_GLint));
    packed_data->format = FORMAT_void_GLint_GLint;
    packed_data->func = glUniform1i;
    packed_data->args.a1 = location;
    packed_data->args.a2 = v0;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glUniform1iv
static inline void push_glUniform1iv(GLint location, GLsizei count, const GLint * value) {
    PACKED_void_GLint_GLsizei_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLint_GLsizei_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLint_GLsizei_const_GLint___GENPT__;
    packed_data->func = glUniform1iv;
    packed_data->args.a1 = location;
    packed_data->args.a2 = count;
    packed_data->args.a3 = value;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glUniform2f
static inline void push_glUniform2f(GLint location, GLfloat v0, GLfloat v1) {
    PACKED_void_GLint_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLint_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLint_GLfloat_GLfloat;
    packed_data->func = glUniform2f;
    packed_data->args.a1 = location;
    packed_data->args.a2 = v0;
    packed_data->args.a3 = v1;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glUniform2fv
static inline void push_glUniform2fv(GLint location, GLsizei count, const GLfloat * value) {
    PACKED_void_GLint_GLsizei_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLint_GLsizei_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLint_GLsizei_const_GLfloat___GENPT__;
    packed_data->func = glUniform2fv;
    packed_data->args.a1 = location;
    packed_data->args.a2 = count;
    packed_data->args.a3 = value;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glUniform2i
static inline void push_glUniform2i(GLint location, GLint v0, GLint v1) {
    PACKED_void_GLint_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLint_GLint_GLint));
    packed_data->format = FORMAT_void_GLint_GLint_GLint;
    packed_data->func = glUniform2i;
    packed_data->args.a1 = location;
    packed_data->args.a2 = v0;
    packed_data->args.a3 = v1;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glUniform2iv
static inline void push_glUniform2iv(GLint location, GLsizei count, const GLint * value) {
    PACKED_void_GLint_GLsizei_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLint_GLsizei_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLint_GLsizei_const_GLint___GENPT__;
    packed_data->func = glUniform2iv;
    packed_data->args.a1 = location;
    packed_data->args.a2 = count;
    packed_data->args.a3 = value;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glUniform3f
static inline void push_glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    PACKED_void_GLint_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLint_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLint_GLfloat_GLfloat_GLfloat;
    packed_data->func = glUniform3f;
    packed_data->args.a1 = location;
    packed_data->args.a2 = v0;
    packed_data->args.a3 = v1;
    packed_data->args.a4 = v2;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glUniform3fv
static inline void push_glUniform3fv(GLint location, GLsizei count, const GLfloat * value) {
    PACKED_void_GLint_GLsizei_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLint_GLsizei_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLint_GLsizei_const_GLfloat___GENPT__;
    packed_data->func = glUniform3fv;
    packed_data->args.a1 = location;
    packed_data->args.a2 = count;
    packed_data->args.a3 = value;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glUniform3i
static inline void push_glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) {
    PACKED_void_GLint_GLint_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLint_GLint_GLint_GLint));
    packed_data->format = FORMAT_void_GLint_GLint_GLint_GLint;
    packed_data->func = glUniform3i;
    packed_data->args.a1 = location;
    packed_data->args.a2 = v0;
    packed_data->args.a3 = v1;
    packed_data->args.a4 = v2;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glUniform3iv
static inline void push_glUniform3iv(GLint location, GLsizei count, const GLint * value) {
    PACKED_void_GLint_GLsizei_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLint_GLsizei_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLint_GLsizei_const_GLint___GENPT__;
    packed_data->func = glUniform3iv;
    packed_data->args.a1 = location;
    packed_data->args.a2 = count;
    packed_data->args.a3 = value;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glUniform4f
static inline void push_glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    PACKED_void_GLint_GLfloat_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLint_GLfloat_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLint_GLfloat_GLfloat_GLfloat_GLfloat;
    packed_data->func = glUniform4f;
    packed_data->args.a1 = location;
    packed_data->args.a2 = v0;
    packed_data->args.a3 = v1;
    packed_data->args.a4 = v2;
    packed_data->args.a5 = v3;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glUniform4fv
static inline void push_glUniform4fv(GLint location, GLsizei count, const GLfloat * value) {
    PACKED_void_GLint_GLsizei_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLint_GLsizei_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLint_GLsizei_const_GLfloat___GENPT__;
    packed_data->func = glUniform4fv;
    packed_data->args.a1 = location;
    packed_data->args.a2 = count;
    packed_data->args.a3 = value;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glUniform4i
static inline void push_glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
    PACKED_void_GLint_GLint_GLint_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLint_GLint_GLint_GLint_GLint));
    packed_data->format = FORMAT_void_GLint_GLint_GLint_GLint_GLint;
    packed_data->func = glUniform4i;
    packed_data->args.a1 = location;
    packed_data->args.a2 = v0;
    packed_data->args.a3 = v1;
    packed_data->args.a4 = v2;
    packed_data->args.a5 = v3;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glUniform4iv
static inline void push_glUniform4iv(GLint location, GLsizei count, const GLint * value) {
    PACKED_void_GLint_GLsizei_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLint_GLsizei_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLint_GLsizei_const_GLint___GENPT__;
    packed_data->func = glUniform4iv;
    packed_data->args.a1 = location;
    packed_data->args.a2 = count;
    packed_data->args.a3 = value;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glUniformMatrix2fv
static inline void push_glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    PACKED_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__;
    packed_data->func = glUniformMatrix2fv;
    packed_data->args.a1 = location;
    packed_data->args.a2 = count;
    packed_data->args.a3 = transpose;
    packed_data->args.a4 = value;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glUniformMatrix3fv
static inline void push_glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    PACKED_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__;
    packed_data->func = glUniformMatrix3fv;
    packed_data->args.a1 = location;
    packed_data->args.a2 = count;
    packed_data->args.a3 = transpose;
    packed_data->args.a4 = value;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glUniformMatrix4fv
static inline void push_glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    PACKED_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLint_GLsizei_GLboolean_const_GLfloat___GENPT__;
    packed_data->func = glUniformMatrix4fv;
    packed_data->args.a1 = location;
    packed_data->args.a2 = count;
    packed_data->args.a3 = transpose;
    packed_data->args.a4 = value;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glUseProgram
static inline void push_glUseProgram(GLuint program) {
    PACKED_void_GLuint *packed_data = malloc(sizeof(PACKED_void_GLuint));
    packed_data->format = FORMAT_void_GLuint;
    packed_data->func = glUseProgram;
    packed_data->args.a1 = program;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glValidateProgram
static inline void push_glValidateProgram(GLuint program) {
    PACKED_void_GLuint *packed_data = malloc(sizeof(PACKED_void_GLuint));
    packed_data->format = FORMAT_void_GLuint;
    packed_data->func = glValidateProgram;
    packed_data->args.a1 = program;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertexAttrib1f
static inline void push_glVertexAttrib1f(GLuint index, GLfloat x) {
    PACKED_void_GLuint_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLuint_GLfloat));
    packed_data->format = FORMAT_void_GLuint_GLfloat;
    packed_data->func = glVertexAttrib1f;
    packed_data->args.a1 = index;
    packed_data->args.a2 = x;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertexAttrib1fv
static inline void push_glVertexAttrib1fv(GLuint index, const GLfloat * v) {
    PACKED_void_GLuint_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLuint_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLuint_const_GLfloat___GENPT__;
    packed_data->func = glVertexAttrib1fv;
    packed_data->args.a1 = index;
    packed_data->args.a2 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertexAttrib2f
static inline void push_glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) {
    PACKED_void_GLuint_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLuint_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLuint_GLfloat_GLfloat;
    packed_data->func = glVertexAttrib2f;
    packed_data->args.a1 = index;
    packed_data->args.a2 = x;
    packed_data->args.a3 = y;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertexAttrib2fv
static inline void push_glVertexAttrib2fv(GLuint index, const GLfloat * v) {
    PACKED_void_GLuint_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLuint_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLuint_const_GLfloat___GENPT__;
    packed_data->func = glVertexAttrib2fv;
    packed_data->args.a1 = index;
    packed_data->args.a2 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertexAttrib3f
static inline void push_glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
    PACKED_void_GLuint_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLuint_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLuint_GLfloat_GLfloat_GLfloat;
    packed_data->func = glVertexAttrib3f;
    packed_data->args.a1 = index;
    packed_data->args.a2 = x;
    packed_data->args.a3 = y;
    packed_data->args.a4 = z;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertexAttrib3fv
static inline void push_glVertexAttrib3fv(GLuint index, const GLfloat * v) {
    PACKED_void_GLuint_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLuint_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLuint_const_GLfloat___GENPT__;
    packed_data->func = glVertexAttrib3fv;
    packed_data->args.a1 = index;
    packed_data->args.a2 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertexAttrib4f
static inline void push_glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat;
    packed_data->func = glVertexAttrib4f;
    packed_data->args.a1 = index;
    packed_data->args.a2 = x;
    packed_data->args.a3 = y;
    packed_data->args.a4 = z;
    packed_data->args.a5 = w;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertexAttrib4fv
static inline void push_glVertexAttrib4fv(GLuint index, const GLfloat * v) {
    PACKED_void_GLuint_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLuint_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLuint_const_GLfloat___GENPT__;
    packed_data->func = glVertexAttrib4fv;
    packed_data->args.a1 = index;
    packed_data->args.a2 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertexAttribPointer
static inline void push_glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid * pointer) {
    PACKED_void_GLuint_GLint_GLenum_GLboolean_GLsizei_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLuint_GLint_GLenum_GLboolean_GLsizei_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLuint_GLint_GLenum_GLboolean_GLsizei_const_GLvoid___GENPT__;
    packed_data->func = glVertexAttribPointer;
    packed_data->args.a1 = index;
    packed_data->args.a2 = size;
    packed_data->args.a3 = type;
    packed_data->args.a4 = normalized;
    packed_data->args.a5 = stride;
    packed_data->args.a6 = pointer;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glViewport
static inline void push_glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
    PACKED_void_GLint_GLint_GLsizei_GLsizei *packed_data = malloc(sizeof(PACKED_void_GLint_GLint_GLsizei_GLsizei));
    packed_data->format = FORMAT_void_GLint_GLint_GLsizei_GLsizei;
    packed_data->func = glViewport;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = width;
    packed_data->args.a4 = height;
    glPushCall((void *)packed_data);
};
#endif

#endif
#endif
