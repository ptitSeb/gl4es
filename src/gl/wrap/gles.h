#ifndef USE_ES2
#include "../gl.h"

#ifndef GLESWRAP_H
#define GLESWRAP_H

typedef struct {
    int format;
    void *func;
    void *args;
} UnknownCall;

enum FORMAT {
    FORMAT_void_GLenum,
    FORMAT_void_GLenum_GLclampf,
    FORMAT_void_GLenum_GLclampx,
    FORMAT_void_GLenum_GLuint,
    FORMAT_void_GLenum_GLenum,
    FORMAT_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum,
    FORMAT_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__,
    FORMAT_void_GLbitfield,
    FORMAT_void_GLclampf_GLclampf_GLclampf_GLclampf,
    FORMAT_void_GLclampx_GLclampx_GLclampx_GLclampx,
    FORMAT_void_GLclampf,
    FORMAT_void_GLclampx,
    FORMAT_void_GLint,
    FORMAT_void_GLenum_const_GLfloat___GENPT__,
    FORMAT_void_GLenum_const_GLfixed___GENPT__,
    FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLubyte_GLubyte_GLubyte_GLubyte,
    FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed,
    FORMAT_void_GLboolean_GLboolean_GLboolean_GLboolean,
    FORMAT_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint,
    FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei,
    FORMAT_void_GLsizei_const_GLuint___GENPT__,
    FORMAT_void_GLboolean,
    FORMAT_void_GLclampf_GLclampf,
    FORMAT_void_GLclampx_GLclampx,
    FORMAT_void_GLenum_GLint_GLsizei,
    FORMAT_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__,
    FORMAT_void,
    FORMAT_void_GLenum_GLfloat,
    FORMAT_void_GLenum_GLfixed,
    FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed,
    FORMAT_void_GLsizei_GLuint___GENPT__,
    FORMAT_void_GLenum_GLboolean___GENPT__,
    FORMAT_void_GLenum_GLenum_GLint___GENPT__,
    FORMAT_void_GLenum_GLfloat___GENPT__,
    FORMAT_void_GLenum_GLfixed___GENPT__,
    FORMAT_GLenum,
    FORMAT_void_GLenum_GLint___GENPT__,
    FORMAT_void_GLenum_GLenum_GLfloat___GENPT__,
    FORMAT_void_GLenum_GLenum_GLfixed___GENPT__,
    FORMAT_void_GLenum_GLvoid___GENPT____GENPT__,
    FORMAT_const_GLubyte___GENPT___GLenum,
    FORMAT_GLboolean_GLuint,
    FORMAT_GLboolean_GLenum,
    FORMAT_void_GLenum_GLenum_GLfloat,
    FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__,
    FORMAT_void_GLenum_GLenum_GLfixed,
    FORMAT_void_GLenum_GLenum_const_GLfixed___GENPT__,
    FORMAT_void_GLfloat,
    FORMAT_void_GLfixed,
    FORMAT_void_const_GLfloat___GENPT__,
    FORMAT_void_const_GLfixed___GENPT__,
    FORMAT_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed,
    FORMAT_void_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLfixed_GLfixed_GLfixed,
    FORMAT_void_GLenum_GLsizei_const_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLint,
    FORMAT_void_GLfloat_GLfloat,
    FORMAT_void_GLfixed_GLfixed,
    FORMAT_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__,
    FORMAT_void_GLclampf_GLboolean,
    FORMAT_void_GLclampx_GLboolean,
    FORMAT_void_GLint_GLint_GLsizei_GLsizei,
    FORMAT_void_GLenum_GLint_GLuint,
    FORMAT_void_GLuint,
    FORMAT_void_GLenum_GLenum_GLenum,
    FORMAT_void_GLenum_GLenum_GLint,
    FORMAT_void_GLenum_GLenum_const_GLint___GENPT__,
    FORMAT_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__,
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
typedef void (*FUNC_void_GLenum_GLclampf)(GLenum func, GLclampf ref);
typedef struct {
    GLenum a1;
    GLclampf a2;
} ARGS_void_GLenum_GLclampf;
typedef struct {
    int format;
    FUNC_void_GLenum_GLclampf func;
    ARGS_void_GLenum_GLclampf args;
} PACKED_void_GLenum_GLclampf;
typedef void (*FUNC_void_GLenum_GLclampx)(GLenum func, GLclampx ref);
typedef struct {
    GLenum a1;
    GLclampx a2;
} ARGS_void_GLenum_GLclampx;
typedef struct {
    int format;
    FUNC_void_GLenum_GLclampx func;
    ARGS_void_GLenum_GLclampx args;
} PACKED_void_GLenum_GLclampx;
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
typedef void (*FUNC_void_GLenum_GLenum)(GLenum sfactor, GLenum dfactor);
typedef struct {
    GLenum a1;
    GLenum a2;
} ARGS_void_GLenum_GLenum;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum func;
    ARGS_void_GLenum_GLenum args;
} PACKED_void_GLenum_GLenum;
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
typedef void (*FUNC_void_GLbitfield)(GLbitfield mask);
typedef struct {
    GLbitfield a1;
} ARGS_void_GLbitfield;
typedef struct {
    int format;
    FUNC_void_GLbitfield func;
    ARGS_void_GLbitfield args;
} PACKED_void_GLbitfield;
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
typedef void (*FUNC_void_GLclampx_GLclampx_GLclampx_GLclampx)(GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha);
typedef struct {
    GLclampx a1;
    GLclampx a2;
    GLclampx a3;
    GLclampx a4;
} ARGS_void_GLclampx_GLclampx_GLclampx_GLclampx;
typedef struct {
    int format;
    FUNC_void_GLclampx_GLclampx_GLclampx_GLclampx func;
    ARGS_void_GLclampx_GLclampx_GLclampx_GLclampx args;
} PACKED_void_GLclampx_GLclampx_GLclampx_GLclampx;
typedef void (*FUNC_void_GLclampf)(GLclampf depth);
typedef struct {
    GLclampf a1;
} ARGS_void_GLclampf;
typedef struct {
    int format;
    FUNC_void_GLclampf func;
    ARGS_void_GLclampf args;
} PACKED_void_GLclampf;
typedef void (*FUNC_void_GLclampx)(GLclampx depth);
typedef struct {
    GLclampx a1;
} ARGS_void_GLclampx;
typedef struct {
    int format;
    FUNC_void_GLclampx func;
    ARGS_void_GLclampx args;
} PACKED_void_GLclampx;
typedef void (*FUNC_void_GLint)(GLint s);
typedef struct {
    GLint a1;
} ARGS_void_GLint;
typedef struct {
    int format;
    FUNC_void_GLint func;
    ARGS_void_GLint args;
} PACKED_void_GLint;
typedef void (*FUNC_void_GLenum_const_GLfloat___GENPT__)(GLenum plane, const GLfloat * equation);
typedef struct {
    GLenum a1;
    const GLfloat * a2;
} ARGS_void_GLenum_const_GLfloat___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_const_GLfloat___GENPT__ func;
    ARGS_void_GLenum_const_GLfloat___GENPT__ args;
} PACKED_void_GLenum_const_GLfloat___GENPT__;
typedef void (*FUNC_void_GLenum_const_GLfixed___GENPT__)(GLenum plane, const GLfixed * equation);
typedef struct {
    GLenum a1;
    const GLfixed * a2;
} ARGS_void_GLenum_const_GLfixed___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_const_GLfixed___GENPT__ func;
    ARGS_void_GLenum_const_GLfixed___GENPT__ args;
} PACKED_void_GLenum_const_GLfixed___GENPT__;
typedef void (*FUNC_void_GLfloat_GLfloat_GLfloat_GLfloat)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef struct {
    GLfloat a1;
    GLfloat a2;
    GLfloat a3;
    GLfloat a4;
} ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLfloat_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLubyte_GLubyte_GLubyte_GLubyte)(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
typedef struct {
    GLubyte a1;
    GLubyte a2;
    GLubyte a3;
    GLubyte a4;
} ARGS_void_GLubyte_GLubyte_GLubyte_GLubyte;
typedef struct {
    int format;
    FUNC_void_GLubyte_GLubyte_GLubyte_GLubyte func;
    ARGS_void_GLubyte_GLubyte_GLubyte_GLubyte args;
} PACKED_void_GLubyte_GLubyte_GLubyte_GLubyte;
typedef void (*FUNC_void_GLfixed_GLfixed_GLfixed_GLfixed)(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
typedef struct {
    GLfixed a1;
    GLfixed a2;
    GLfixed a3;
    GLfixed a4;
} ARGS_void_GLfixed_GLfixed_GLfixed_GLfixed;
typedef struct {
    int format;
    FUNC_void_GLfixed_GLfixed_GLfixed_GLfixed func;
    ARGS_void_GLfixed_GLfixed_GLfixed_GLfixed args;
} PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed;
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
typedef void (*FUNC_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__)(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
typedef struct {
    GLint a1;
    GLenum a2;
    GLsizei a3;
    const GLvoid * a4;
} ARGS_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ func;
    ARGS_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ args;
} PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__;
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
typedef void (*FUNC_void_GLsizei_const_GLuint___GENPT__)(GLsizei n, const GLuint * buffers);
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
typedef void (*FUNC_void_GLclampf_GLclampf)(GLclampf near, GLclampf far);
typedef struct {
    GLclampf a1;
    GLclampf a2;
} ARGS_void_GLclampf_GLclampf;
typedef struct {
    int format;
    FUNC_void_GLclampf_GLclampf func;
    ARGS_void_GLclampf_GLclampf args;
} PACKED_void_GLclampf_GLclampf;
typedef void (*FUNC_void_GLclampx_GLclampx)(GLclampx near, GLclampx far);
typedef struct {
    GLclampx a1;
    GLclampx a2;
} ARGS_void_GLclampx_GLclampx;
typedef struct {
    int format;
    FUNC_void_GLclampx_GLclampx func;
    ARGS_void_GLclampx_GLclampx args;
} PACKED_void_GLclampx_GLclampx;
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
typedef void (*FUNC_void_GLenum_GLfloat)(GLenum pname, GLfloat param);
typedef struct {
    GLenum a1;
    GLfloat a2;
} ARGS_void_GLenum_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLenum_GLfloat func;
    ARGS_void_GLenum_GLfloat args;
} PACKED_void_GLenum_GLfloat;
typedef void (*FUNC_void_GLenum_GLfixed)(GLenum pname, GLfixed param);
typedef struct {
    GLenum a1;
    GLfixed a2;
} ARGS_void_GLenum_GLfixed;
typedef struct {
    int format;
    FUNC_void_GLenum_GLfixed func;
    ARGS_void_GLenum_GLfixed args;
} PACKED_void_GLenum_GLfixed;
typedef void (*FUNC_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat)(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far);
typedef struct {
    GLfloat a1;
    GLfloat a2;
    GLfloat a3;
    GLfloat a4;
    GLfloat a5;
    GLfloat a6;
} ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed)(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far);
typedef struct {
    GLfixed a1;
    GLfixed a2;
    GLfixed a3;
    GLfixed a4;
    GLfixed a5;
    GLfixed a6;
} ARGS_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed;
typedef struct {
    int format;
    FUNC_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed func;
    ARGS_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed args;
} PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed;
typedef void (*FUNC_void_GLsizei_GLuint___GENPT__)(GLsizei n, GLuint * buffers);
typedef struct {
    GLsizei a1;
    GLuint * a2;
} ARGS_void_GLsizei_GLuint___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLuint___GENPT__ func;
    ARGS_void_GLsizei_GLuint___GENPT__ args;
} PACKED_void_GLsizei_GLuint___GENPT__;
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
typedef void (*FUNC_void_GLenum_GLfloat___GENPT__)(GLenum plane, GLfloat * equation);
typedef struct {
    GLenum a1;
    GLfloat * a2;
} ARGS_void_GLenum_GLfloat___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLfloat___GENPT__ func;
    ARGS_void_GLenum_GLfloat___GENPT__ args;
} PACKED_void_GLenum_GLfloat___GENPT__;
typedef void (*FUNC_void_GLenum_GLfixed___GENPT__)(GLenum plane, GLfixed * equation);
typedef struct {
    GLenum a1;
    GLfixed * a2;
} ARGS_void_GLenum_GLfixed___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLfixed___GENPT__ func;
    ARGS_void_GLenum_GLfixed___GENPT__ args;
} PACKED_void_GLenum_GLfixed___GENPT__;
typedef GLenum (*FUNC_GLenum)();
typedef struct {
} ARGS_GLenum;
typedef struct {
    int format;
    FUNC_GLenum func;
    ARGS_GLenum args;
} PACKED_GLenum;
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
typedef void (*FUNC_void_GLenum_GLenum_GLfloat___GENPT__)(GLenum light, GLenum pname, GLfloat * params);
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
typedef void (*FUNC_void_GLenum_GLenum_GLfixed___GENPT__)(GLenum light, GLenum pname, GLfixed * params);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLfixed * a3;
} ARGS_void_GLenum_GLenum_GLfixed___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLfixed___GENPT__ func;
    ARGS_void_GLenum_GLenum_GLfixed___GENPT__ args;
} PACKED_void_GLenum_GLenum_GLfixed___GENPT__;
typedef void (*FUNC_void_GLenum_GLvoid___GENPT____GENPT__)(GLenum pname, GLvoid ** params);
typedef struct {
    GLenum a1;
    GLvoid ** a2;
} ARGS_void_GLenum_GLvoid___GENPT____GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLvoid___GENPT____GENPT__ func;
    ARGS_void_GLenum_GLvoid___GENPT____GENPT__ args;
} PACKED_void_GLenum_GLvoid___GENPT____GENPT__;
typedef const GLubyte * (*FUNC_const_GLubyte___GENPT___GLenum)(GLenum name);
typedef struct {
    GLenum a1;
} ARGS_const_GLubyte___GENPT___GLenum;
typedef struct {
    int format;
    FUNC_const_GLubyte___GENPT___GLenum func;
    ARGS_const_GLubyte___GENPT___GLenum args;
} PACKED_const_GLubyte___GENPT___GLenum;
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
typedef void (*FUNC_void_GLenum_GLenum_GLfloat)(GLenum light, GLenum pname, GLfloat param);
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
typedef void (*FUNC_void_GLenum_GLenum_const_GLfloat___GENPT__)(GLenum light, GLenum pname, const GLfloat * params);
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
typedef void (*FUNC_void_GLenum_GLenum_GLfixed)(GLenum light, GLenum pname, GLfixed param);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLfixed a3;
} ARGS_void_GLenum_GLenum_GLfixed;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLfixed func;
    ARGS_void_GLenum_GLenum_GLfixed args;
} PACKED_void_GLenum_GLenum_GLfixed;
typedef void (*FUNC_void_GLenum_GLenum_const_GLfixed___GENPT__)(GLenum light, GLenum pname, const GLfixed * params);
typedef struct {
    GLenum a1;
    GLenum a2;
    const GLfixed * a3;
} ARGS_void_GLenum_GLenum_const_GLfixed___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_const_GLfixed___GENPT__ func;
    ARGS_void_GLenum_GLenum_const_GLfixed___GENPT__ args;
} PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__;
typedef void (*FUNC_void_GLfloat)(GLfloat width);
typedef struct {
    GLfloat a1;
} ARGS_void_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLfloat func;
    ARGS_void_GLfloat args;
} PACKED_void_GLfloat;
typedef void (*FUNC_void_GLfixed)(GLfixed width);
typedef struct {
    GLfixed a1;
} ARGS_void_GLfixed;
typedef struct {
    int format;
    FUNC_void_GLfixed func;
    ARGS_void_GLfixed args;
} PACKED_void_GLfixed;
typedef void (*FUNC_void_const_GLfloat___GENPT__)(const GLfloat * m);
typedef struct {
    const GLfloat * a1;
} ARGS_void_const_GLfloat___GENPT__;
typedef struct {
    int format;
    FUNC_void_const_GLfloat___GENPT__ func;
    ARGS_void_const_GLfloat___GENPT__ args;
} PACKED_void_const_GLfloat___GENPT__;
typedef void (*FUNC_void_const_GLfixed___GENPT__)(const GLfixed * m);
typedef struct {
    const GLfixed * a1;
} ARGS_void_const_GLfixed___GENPT__;
typedef struct {
    int format;
    FUNC_void_const_GLfixed___GENPT__ func;
    ARGS_void_const_GLfixed___GENPT__ args;
} PACKED_void_const_GLfixed___GENPT__;
typedef void (*FUNC_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
typedef struct {
    GLenum a1;
    GLfloat a2;
    GLfloat a3;
    GLfloat a4;
    GLfloat a5;
} ARGS_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed)(GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q);
typedef struct {
    GLenum a1;
    GLfixed a2;
    GLfixed a3;
    GLfixed a4;
    GLfixed a5;
} ARGS_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed;
typedef struct {
    int format;
    FUNC_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed func;
    ARGS_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed args;
} PACKED_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed;
typedef void (*FUNC_void_GLfloat_GLfloat_GLfloat)(GLfloat nx, GLfloat ny, GLfloat nz);
typedef struct {
    GLfloat a1;
    GLfloat a2;
    GLfloat a3;
} ARGS_void_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLfixed_GLfixed_GLfixed)(GLfixed nx, GLfixed ny, GLfixed nz);
typedef struct {
    GLfixed a1;
    GLfixed a2;
    GLfixed a3;
} ARGS_void_GLfixed_GLfixed_GLfixed;
typedef struct {
    int format;
    FUNC_void_GLfixed_GLfixed_GLfixed func;
    ARGS_void_GLfixed_GLfixed_GLfixed args;
} PACKED_void_GLfixed_GLfixed_GLfixed;
typedef void (*FUNC_void_GLenum_GLsizei_const_GLvoid___GENPT__)(GLenum type, GLsizei stride, const GLvoid * pointer);
typedef struct {
    GLenum a1;
    GLsizei a2;
    const GLvoid * a3;
} ARGS_void_GLenum_GLsizei_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLsizei_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__;
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
typedef void (*FUNC_void_GLfixed_GLfixed)(GLfixed factor, GLfixed units);
typedef struct {
    GLfixed a1;
    GLfixed a2;
} ARGS_void_GLfixed_GLfixed;
typedef struct {
    int format;
    FUNC_void_GLfixed_GLfixed func;
    ARGS_void_GLfixed_GLfixed args;
} PACKED_void_GLfixed_GLfixed;
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
typedef void (*FUNC_void_GLclampx_GLboolean)(GLclampx value, GLboolean invert);
typedef struct {
    GLclampx a1;
    GLboolean a2;
} ARGS_void_GLclampx_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLclampx_GLboolean func;
    ARGS_void_GLclampx_GLboolean args;
} PACKED_void_GLclampx_GLboolean;
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
typedef void (*FUNC_void_GLuint)(GLuint mask);
typedef struct {
    GLuint a1;
} ARGS_void_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint func;
    ARGS_void_GLuint args;
} PACKED_void_GLuint;
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

void glPackedCall(const UnknownCall *packed);
void glActiveTexture(GLenum texture);
void glAlphaFunc(GLenum func, GLclampf ref);
void glAlphaFuncx(GLenum func, GLclampx ref);
void glBindBuffer(GLenum target, GLuint buffer);
void glBindTexture(GLenum target, GLuint texture);
void glBlendFunc(GLenum sfactor, GLenum dfactor);
void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage);
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data);
void glClear(GLbitfield mask);
void glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
void glClearColorx(GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha);
void glClearDepthf(GLclampf depth);
void glClearDepthx(GLclampx depth);
void glClearStencil(GLint s);
void glClientActiveTexture(GLenum texture);
void glClipPlanef(GLenum plane, const GLfloat * equation);
void glClipPlanex(GLenum plane, const GLfixed * equation);
void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
void glColor4x(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
void glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data);
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data);
void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glCullFace(GLenum mode);
void glDeleteBuffers(GLsizei n, const GLuint * buffers);
void glDeleteTextures(GLsizei n, const GLuint * textures);
void glDepthFunc(GLenum func);
void glDepthMask(GLboolean flag);
void glDepthRangef(GLclampf near, GLclampf far);
void glDepthRangex(GLclampx near, GLclampx far);
void glDisable(GLenum cap);
void glDisableClientState(GLenum array);
void glDrawArrays(GLenum mode, GLint first, GLsizei count);
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices);
void glEnable(GLenum cap);
void glEnableClientState(GLenum array);
void glFinish();
void glFlush();
void glFogf(GLenum pname, GLfloat param);
void glFogfv(GLenum pname, const GLfloat * params);
void glFogx(GLenum pname, GLfixed param);
void glFogxv(GLenum pname, const GLfixed * params);
void glFrontFace(GLenum mode);
void glFrustumf(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far);
void glFrustumx(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far);
void glGenBuffers(GLsizei n, GLuint * buffers);
void glGenTextures(GLsizei n, GLuint * textures);
void glGetBooleanv(GLenum pname, GLboolean * params);
void glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params);
void glGetClipPlanef(GLenum plane, GLfloat * equation);
void glGetClipPlanex(GLenum plane, GLfixed * equation);
GLenum glGetError();
void glGetFixedv(GLenum pname, GLfixed * params);
void glGetFloatv(GLenum pname, GLfloat * params);
void glGetIntegerv(GLenum pname, GLint * params);
void glGetLightfv(GLenum light, GLenum pname, GLfloat * params);
void glGetLightxv(GLenum light, GLenum pname, GLfixed * params);
void glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params);
void glGetMaterialxv(GLenum face, GLenum pname, GLfixed * params);
void glGetPointerv(GLenum pname, GLvoid ** params);
const GLubyte * glGetString(GLenum name);
void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params);
void glGetTexEnviv(GLenum target, GLenum pname, GLint * params);
void glGetTexEnvxv(GLenum target, GLenum pname, GLfixed * params);
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params);
void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params);
void glGetTexParameterxv(GLenum target, GLenum pname, GLfixed * params);
void glHint(GLenum target, GLenum mode);
GLboolean glIsBuffer(GLuint buffer);
GLboolean glIsEnabled(GLenum cap);
GLboolean glIsTexture(GLuint texture);
void glLightModelf(GLenum pname, GLfloat param);
void glLightModelfv(GLenum pname, const GLfloat * params);
void glLightModelx(GLenum pname, GLfixed param);
void glLightModelxv(GLenum pname, const GLfixed * params);
void glLightf(GLenum light, GLenum pname, GLfloat param);
void glLightfv(GLenum light, GLenum pname, const GLfloat * params);
void glLightx(GLenum light, GLenum pname, GLfixed param);
void glLightxv(GLenum light, GLenum pname, const GLfixed * params);
void glLineWidth(GLfloat width);
void glLineWidthx(GLfixed width);
void glLoadIdentity();
void glLoadMatrixf(const GLfloat * m);
void glLoadMatrixx(const GLfixed * m);
void glLogicOp(GLenum opcode);
void glMaterialf(GLenum face, GLenum pname, GLfloat param);
void glMaterialfv(GLenum face, GLenum pname, const GLfloat * params);
void glMaterialx(GLenum face, GLenum pname, GLfixed param);
void glMaterialxv(GLenum face, GLenum pname, const GLfixed * params);
void glMatrixMode(GLenum mode);
void glMultMatrixf(const GLfloat * m);
void glMultMatrixx(const GLfixed * m);
void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void glMultiTexCoord4x(GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q);
void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz);
void glNormal3x(GLfixed nx, GLfixed ny, GLfixed nz);
void glNormalPointer(GLenum type, GLsizei stride, const GLvoid * pointer);
void glOrthof(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far);
void glOrthox(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far);
void glPixelStorei(GLenum pname, GLint param);
void glPointParameterf(GLenum pname, GLfloat param);
void glPointParameterfv(GLenum pname, const GLfloat * params);
void glPointParameterx(GLenum pname, GLfixed param);
void glPointParameterxv(GLenum pname, const GLfixed * params);
void glPointSize(GLfloat size);
void glPointSizePointerOES(GLenum type, GLsizei stride, const GLvoid * pointer);
void glPointSizex(GLfixed size);
void glPolygonOffset(GLfloat factor, GLfloat units);
void glPolygonOffsetx(GLfixed factor, GLfixed units);
void glPopMatrix();
void glPushMatrix();
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels);
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
void glRotatex(GLfixed angle, GLfixed x, GLfixed y, GLfixed z);
void glSampleCoverage(GLclampf value, GLboolean invert);
void glSampleCoveragex(GLclampx value, GLboolean invert);
void glScalef(GLfloat x, GLfloat y, GLfloat z);
void glScalex(GLfixed x, GLfixed y, GLfixed z);
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
void glShadeModel(GLenum mode);
void glStencilFunc(GLenum func, GLint ref, GLuint mask);
void glStencilMask(GLuint mask);
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass);
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
void glTexEnvf(GLenum target, GLenum pname, GLfloat param);
void glTexEnvfv(GLenum target, GLenum pname, const GLfloat * params);
void glTexEnvi(GLenum target, GLenum pname, GLint param);
void glTexEnviv(GLenum target, GLenum pname, const GLint * params);
void glTexEnvx(GLenum target, GLenum pname, GLfixed param);
void glTexEnvxv(GLenum target, GLenum pname, const GLfixed * params);
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels);
void glTexParameterf(GLenum target, GLenum pname, GLfloat param);
void glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params);
void glTexParameteri(GLenum target, GLenum pname, GLint param);
void glTexParameteriv(GLenum target, GLenum pname, const GLint * params);
void glTexParameterx(GLenum target, GLenum pname, GLfixed param);
void glTexParameterxv(GLenum target, GLenum pname, const GLfixed * params);
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels);
void glTranslatef(GLfloat x, GLfloat y, GLfloat z);
void glTranslatex(GLfixed x, GLfixed y, GLfixed z);
void glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height);

#endif
#endif
