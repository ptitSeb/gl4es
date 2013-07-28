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

extern void glPushCall(void *data);
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

#ifndef direct_glActiveTexture
static inline void push_glActiveTexture(GLenum texture) {
    PACKED_void_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum));
    packed_data->format = FORMAT_void_GLenum;
    packed_data->func = glActiveTexture;
    packed_data->args.a1 = texture;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glAlphaFunc
static inline void push_glAlphaFunc(GLenum func, GLclampf ref) {
    PACKED_void_GLenum_GLclampf *packed_data = malloc(sizeof(PACKED_void_GLenum_GLclampf));
    packed_data->format = FORMAT_void_GLenum_GLclampf;
    packed_data->func = glAlphaFunc;
    packed_data->args.a1 = func;
    packed_data->args.a2 = ref;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glAlphaFuncx
static inline void push_glAlphaFuncx(GLenum func, GLclampx ref) {
    PACKED_void_GLenum_GLclampx *packed_data = malloc(sizeof(PACKED_void_GLenum_GLclampx));
    packed_data->format = FORMAT_void_GLenum_GLclampx;
    packed_data->func = glAlphaFuncx;
    packed_data->args.a1 = func;
    packed_data->args.a2 = ref;
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
#ifndef direct_glClearColorx
static inline void push_glClearColorx(GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha) {
    PACKED_void_GLclampx_GLclampx_GLclampx_GLclampx *packed_data = malloc(sizeof(PACKED_void_GLclampx_GLclampx_GLclampx_GLclampx));
    packed_data->format = FORMAT_void_GLclampx_GLclampx_GLclampx_GLclampx;
    packed_data->func = glClearColorx;
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
#ifndef direct_glClearDepthx
static inline void push_glClearDepthx(GLclampx depth) {
    PACKED_void_GLclampx *packed_data = malloc(sizeof(PACKED_void_GLclampx));
    packed_data->format = FORMAT_void_GLclampx;
    packed_data->func = glClearDepthx;
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
#ifndef direct_glClientActiveTexture
static inline void push_glClientActiveTexture(GLenum texture) {
    PACKED_void_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum));
    packed_data->format = FORMAT_void_GLenum;
    packed_data->func = glClientActiveTexture;
    packed_data->args.a1 = texture;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glClipPlanef
static inline void push_glClipPlanef(GLenum plane, const GLfloat * equation) {
    PACKED_void_GLenum_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLfloat___GENPT__;
    packed_data->func = glClipPlanef;
    packed_data->args.a1 = plane;
    packed_data->args.a2 = equation;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glClipPlanex
static inline void push_glClipPlanex(GLenum plane, const GLfixed * equation) {
    PACKED_void_GLenum_const_GLfixed___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLfixed___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLfixed___GENPT__;
    packed_data->func = glClipPlanex;
    packed_data->args.a1 = plane;
    packed_data->args.a2 = equation;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor4f
static inline void push_glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat;
    packed_data->func = glColor4f;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor4ub
static inline void push_glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {
    PACKED_void_GLubyte_GLubyte_GLubyte_GLubyte *packed_data = malloc(sizeof(PACKED_void_GLubyte_GLubyte_GLubyte_GLubyte));
    packed_data->format = FORMAT_void_GLubyte_GLubyte_GLubyte_GLubyte;
    packed_data->func = glColor4ub;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor4x
static inline void push_glColor4x(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha) {
    PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed *packed_data = malloc(sizeof(PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed));
    packed_data->format = FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed;
    packed_data->func = glColor4x;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
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
#ifndef direct_glColorPointer
static inline void push_glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__;
    packed_data->func = glColorPointer;
    packed_data->args.a1 = size;
    packed_data->args.a2 = type;
    packed_data->args.a3 = stride;
    packed_data->args.a4 = pointer;
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
static inline void push_glDeleteBuffers(GLsizei n, const GLuint * buffers) {
    PACKED_void_GLsizei_const_GLuint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLsizei_const_GLuint___GENPT__));
    packed_data->format = FORMAT_void_GLsizei_const_GLuint___GENPT__;
    packed_data->func = glDeleteBuffers;
    packed_data->args.a1 = n;
    packed_data->args.a2 = buffers;
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
static inline void push_glDepthRangef(GLclampf near, GLclampf far) {
    PACKED_void_GLclampf_GLclampf *packed_data = malloc(sizeof(PACKED_void_GLclampf_GLclampf));
    packed_data->format = FORMAT_void_GLclampf_GLclampf;
    packed_data->func = glDepthRangef;
    packed_data->args.a1 = near;
    packed_data->args.a2 = far;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glDepthRangex
static inline void push_glDepthRangex(GLclampx near, GLclampx far) {
    PACKED_void_GLclampx_GLclampx *packed_data = malloc(sizeof(PACKED_void_GLclampx_GLclampx));
    packed_data->format = FORMAT_void_GLclampx_GLclampx;
    packed_data->func = glDepthRangex;
    packed_data->args.a1 = near;
    packed_data->args.a2 = far;
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
#ifndef direct_glDisableClientState
static inline void push_glDisableClientState(GLenum array) {
    PACKED_void_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum));
    packed_data->format = FORMAT_void_GLenum;
    packed_data->func = glDisableClientState;
    packed_data->args.a1 = array;
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
#ifndef direct_glEnableClientState
static inline void push_glEnableClientState(GLenum array) {
    PACKED_void_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum));
    packed_data->format = FORMAT_void_GLenum;
    packed_data->func = glEnableClientState;
    packed_data->args.a1 = array;
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
#ifndef direct_glFogf
static inline void push_glFogf(GLenum pname, GLfloat param) {
    PACKED_void_GLenum_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLenum_GLfloat));
    packed_data->format = FORMAT_void_GLenum_GLfloat;
    packed_data->func = glFogf;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glFogfv
static inline void push_glFogfv(GLenum pname, const GLfloat * params) {
    PACKED_void_GLenum_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLfloat___GENPT__;
    packed_data->func = glFogfv;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glFogx
static inline void push_glFogx(GLenum pname, GLfixed param) {
    PACKED_void_GLenum_GLfixed *packed_data = malloc(sizeof(PACKED_void_GLenum_GLfixed));
    packed_data->format = FORMAT_void_GLenum_GLfixed;
    packed_data->func = glFogx;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glFogxv
static inline void push_glFogxv(GLenum pname, const GLfixed * params) {
    PACKED_void_GLenum_const_GLfixed___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLfixed___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLfixed___GENPT__;
    packed_data->func = glFogxv;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
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
#ifndef direct_glFrustumf
static inline void push_glFrustumf(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far) {
    PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
    packed_data->func = glFrustumf;
    packed_data->args.a1 = left;
    packed_data->args.a2 = right;
    packed_data->args.a3 = bottom;
    packed_data->args.a4 = top;
    packed_data->args.a5 = near;
    packed_data->args.a6 = far;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glFrustumx
static inline void push_glFrustumx(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far) {
    PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed *packed_data = malloc(sizeof(PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed));
    packed_data->format = FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed;
    packed_data->func = glFrustumx;
    packed_data->args.a1 = left;
    packed_data->args.a2 = right;
    packed_data->args.a3 = bottom;
    packed_data->args.a4 = top;
    packed_data->args.a5 = near;
    packed_data->args.a6 = far;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGenBuffers
static inline void push_glGenBuffers(GLsizei n, GLuint * buffers) {
    PACKED_void_GLsizei_GLuint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLsizei_GLuint___GENPT__));
    packed_data->format = FORMAT_void_GLsizei_GLuint___GENPT__;
    packed_data->func = glGenBuffers;
    packed_data->args.a1 = n;
    packed_data->args.a2 = buffers;
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
#ifndef direct_glGetClipPlanef
static inline void push_glGetClipPlanef(GLenum plane, GLfloat * equation) {
    PACKED_void_GLenum_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLfloat___GENPT__;
    packed_data->func = glGetClipPlanef;
    packed_data->args.a1 = plane;
    packed_data->args.a2 = equation;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetClipPlanex
static inline void push_glGetClipPlanex(GLenum plane, GLfixed * equation) {
    PACKED_void_GLenum_GLfixed___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLfixed___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLfixed___GENPT__;
    packed_data->func = glGetClipPlanex;
    packed_data->args.a1 = plane;
    packed_data->args.a2 = equation;
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
#ifndef direct_glGetFixedv
static inline void push_glGetFixedv(GLenum pname, GLfixed * params) {
    PACKED_void_GLenum_GLfixed___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLfixed___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLfixed___GENPT__;
    packed_data->func = glGetFixedv;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
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
#ifndef direct_glGetLightfv
static inline void push_glGetLightfv(GLenum light, GLenum pname, GLfloat * params) {
    PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLfloat___GENPT__;
    packed_data->func = glGetLightfv;
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetLightxv
static inline void push_glGetLightxv(GLenum light, GLenum pname, GLfixed * params) {
    PACKED_void_GLenum_GLenum_GLfixed___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfixed___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLfixed___GENPT__;
    packed_data->func = glGetLightxv;
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetMaterialfv
static inline void push_glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params) {
    PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLfloat___GENPT__;
    packed_data->func = glGetMaterialfv;
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetMaterialxv
static inline void push_glGetMaterialxv(GLenum face, GLenum pname, GLfixed * params) {
    PACKED_void_GLenum_GLenum_GLfixed___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfixed___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLfixed___GENPT__;
    packed_data->func = glGetMaterialxv;
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetPointerv
static inline void push_glGetPointerv(GLenum pname, GLvoid ** params) {
    PACKED_void_GLenum_GLvoid___GENPT____GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLvoid___GENPT____GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLvoid___GENPT____GENPT__;
    packed_data->func = glGetPointerv;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
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
#ifndef direct_glGetTexEnvfv
static inline void push_glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params) {
    PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLfloat___GENPT__;
    packed_data->func = glGetTexEnvfv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetTexEnviv
static inline void push_glGetTexEnviv(GLenum target, GLenum pname, GLint * params) {
    PACKED_void_GLenum_GLenum_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLint___GENPT__;
    packed_data->func = glGetTexEnviv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetTexEnvxv
static inline void push_glGetTexEnvxv(GLenum target, GLenum pname, GLfixed * params) {
    PACKED_void_GLenum_GLenum_GLfixed___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfixed___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLfixed___GENPT__;
    packed_data->func = glGetTexEnvxv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
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
#ifndef direct_glGetTexParameterxv
static inline void push_glGetTexParameterxv(GLenum target, GLenum pname, GLfixed * params) {
    PACKED_void_GLenum_GLenum_GLfixed___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfixed___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLfixed___GENPT__;
    packed_data->func = glGetTexParameterxv;
    packed_data->args.a1 = target;
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
#ifndef direct_glIsTexture
static inline void push_glIsTexture(GLuint texture) {
    PACKED_GLboolean_GLuint *packed_data = malloc(sizeof(PACKED_GLboolean_GLuint));
    packed_data->format = FORMAT_GLboolean_GLuint;
    packed_data->func = glIsTexture;
    packed_data->args.a1 = texture;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glLightModelf
static inline void push_glLightModelf(GLenum pname, GLfloat param) {
    PACKED_void_GLenum_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLenum_GLfloat));
    packed_data->format = FORMAT_void_GLenum_GLfloat;
    packed_data->func = glLightModelf;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glLightModelfv
static inline void push_glLightModelfv(GLenum pname, const GLfloat * params) {
    PACKED_void_GLenum_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLfloat___GENPT__;
    packed_data->func = glLightModelfv;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glLightModelx
static inline void push_glLightModelx(GLenum pname, GLfixed param) {
    PACKED_void_GLenum_GLfixed *packed_data = malloc(sizeof(PACKED_void_GLenum_GLfixed));
    packed_data->format = FORMAT_void_GLenum_GLfixed;
    packed_data->func = glLightModelx;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glLightModelxv
static inline void push_glLightModelxv(GLenum pname, const GLfixed * params) {
    PACKED_void_GLenum_const_GLfixed___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLfixed___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLfixed___GENPT__;
    packed_data->func = glLightModelxv;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glLightf
static inline void push_glLightf(GLenum light, GLenum pname, GLfloat param) {
    PACKED_void_GLenum_GLenum_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfloat));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLfloat;
    packed_data->func = glLightf;
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glLightfv
static inline void push_glLightfv(GLenum light, GLenum pname, const GLfloat * params) {
    PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__;
    packed_data->func = glLightfv;
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glLightx
static inline void push_glLightx(GLenum light, GLenum pname, GLfixed param) {
    PACKED_void_GLenum_GLenum_GLfixed *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfixed));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLfixed;
    packed_data->func = glLightx;
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glLightxv
static inline void push_glLightxv(GLenum light, GLenum pname, const GLfixed * params) {
    PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_const_GLfixed___GENPT__;
    packed_data->func = glLightxv;
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
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
#ifndef direct_glLineWidthx
static inline void push_glLineWidthx(GLfixed width) {
    PACKED_void_GLfixed *packed_data = malloc(sizeof(PACKED_void_GLfixed));
    packed_data->format = FORMAT_void_GLfixed;
    packed_data->func = glLineWidthx;
    packed_data->args.a1 = width;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glLoadIdentity
static inline void push_glLoadIdentity() {
    PACKED_void *packed_data = malloc(sizeof(PACKED_void));
    packed_data->format = FORMAT_void;
    packed_data->func = glLoadIdentity;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glLoadMatrixf
static inline void push_glLoadMatrixf(const GLfloat * m) {
    PACKED_void_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_const_GLfloat___GENPT__;
    packed_data->func = glLoadMatrixf;
    packed_data->args.a1 = m;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glLoadMatrixx
static inline void push_glLoadMatrixx(const GLfixed * m) {
    PACKED_void_const_GLfixed___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfixed___GENPT__));
    packed_data->format = FORMAT_void_const_GLfixed___GENPT__;
    packed_data->func = glLoadMatrixx;
    packed_data->args.a1 = m;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glLogicOp
static inline void push_glLogicOp(GLenum opcode) {
    PACKED_void_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum));
    packed_data->format = FORMAT_void_GLenum;
    packed_data->func = glLogicOp;
    packed_data->args.a1 = opcode;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMaterialf
static inline void push_glMaterialf(GLenum face, GLenum pname, GLfloat param) {
    PACKED_void_GLenum_GLenum_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfloat));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLfloat;
    packed_data->func = glMaterialf;
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMaterialfv
static inline void push_glMaterialfv(GLenum face, GLenum pname, const GLfloat * params) {
    PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__;
    packed_data->func = glMaterialfv;
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMaterialx
static inline void push_glMaterialx(GLenum face, GLenum pname, GLfixed param) {
    PACKED_void_GLenum_GLenum_GLfixed *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfixed));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLfixed;
    packed_data->func = glMaterialx;
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMaterialxv
static inline void push_glMaterialxv(GLenum face, GLenum pname, const GLfixed * params) {
    PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_const_GLfixed___GENPT__;
    packed_data->func = glMaterialxv;
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMatrixMode
static inline void push_glMatrixMode(GLenum mode) {
    PACKED_void_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum));
    packed_data->format = FORMAT_void_GLenum;
    packed_data->func = glMatrixMode;
    packed_data->args.a1 = mode;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultMatrixf
static inline void push_glMultMatrixf(const GLfloat * m) {
    PACKED_void_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_const_GLfloat___GENPT__;
    packed_data->func = glMultMatrixf;
    packed_data->args.a1 = m;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultMatrixx
static inline void push_glMultMatrixx(const GLfixed * m) {
    PACKED_void_const_GLfixed___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfixed___GENPT__));
    packed_data->format = FORMAT_void_const_GLfixed___GENPT__;
    packed_data->func = glMultMatrixx;
    packed_data->args.a1 = m;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord4f
static inline void push_glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    PACKED_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat;
    packed_data->func = glMultiTexCoord4f;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    packed_data->args.a5 = q;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord4x
static inline void push_glMultiTexCoord4x(GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q) {
    PACKED_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed *packed_data = malloc(sizeof(PACKED_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed));
    packed_data->format = FORMAT_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed;
    packed_data->func = glMultiTexCoord4x;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    packed_data->args.a5 = q;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glNormal3f
static inline void push_glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {
    PACKED_void_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat_GLfloat;
    packed_data->func = glNormal3f;
    packed_data->args.a1 = nx;
    packed_data->args.a2 = ny;
    packed_data->args.a3 = nz;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glNormal3x
static inline void push_glNormal3x(GLfixed nx, GLfixed ny, GLfixed nz) {
    PACKED_void_GLfixed_GLfixed_GLfixed *packed_data = malloc(sizeof(PACKED_void_GLfixed_GLfixed_GLfixed));
    packed_data->format = FORMAT_void_GLfixed_GLfixed_GLfixed;
    packed_data->func = glNormal3x;
    packed_data->args.a1 = nx;
    packed_data->args.a2 = ny;
    packed_data->args.a3 = nz;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glNormalPointer
static inline void push_glNormalPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLsizei_const_GLvoid___GENPT__;
    packed_data->func = glNormalPointer;
    packed_data->args.a1 = type;
    packed_data->args.a2 = stride;
    packed_data->args.a3 = pointer;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glOrthof
static inline void push_glOrthof(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far) {
    PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
    packed_data->func = glOrthof;
    packed_data->args.a1 = left;
    packed_data->args.a2 = right;
    packed_data->args.a3 = bottom;
    packed_data->args.a4 = top;
    packed_data->args.a5 = near;
    packed_data->args.a6 = far;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glOrthox
static inline void push_glOrthox(GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far) {
    PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed *packed_data = malloc(sizeof(PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed));
    packed_data->format = FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed;
    packed_data->func = glOrthox;
    packed_data->args.a1 = left;
    packed_data->args.a2 = right;
    packed_data->args.a3 = bottom;
    packed_data->args.a4 = top;
    packed_data->args.a5 = near;
    packed_data->args.a6 = far;
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
#ifndef direct_glPointParameterf
static inline void push_glPointParameterf(GLenum pname, GLfloat param) {
    PACKED_void_GLenum_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLenum_GLfloat));
    packed_data->format = FORMAT_void_GLenum_GLfloat;
    packed_data->func = glPointParameterf;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glPointParameterfv
static inline void push_glPointParameterfv(GLenum pname, const GLfloat * params) {
    PACKED_void_GLenum_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLfloat___GENPT__;
    packed_data->func = glPointParameterfv;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glPointParameterx
static inline void push_glPointParameterx(GLenum pname, GLfixed param) {
    PACKED_void_GLenum_GLfixed *packed_data = malloc(sizeof(PACKED_void_GLenum_GLfixed));
    packed_data->format = FORMAT_void_GLenum_GLfixed;
    packed_data->func = glPointParameterx;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glPointParameterxv
static inline void push_glPointParameterxv(GLenum pname, const GLfixed * params) {
    PACKED_void_GLenum_const_GLfixed___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLfixed___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLfixed___GENPT__;
    packed_data->func = glPointParameterxv;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glPointSize
static inline void push_glPointSize(GLfloat size) {
    PACKED_void_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat));
    packed_data->format = FORMAT_void_GLfloat;
    packed_data->func = glPointSize;
    packed_data->args.a1 = size;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glPointSizePointerOES
static inline void push_glPointSizePointerOES(GLenum type, GLsizei stride, const GLvoid * pointer) {
    PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLsizei_const_GLvoid___GENPT__;
    packed_data->func = glPointSizePointerOES;
    packed_data->args.a1 = type;
    packed_data->args.a2 = stride;
    packed_data->args.a3 = pointer;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glPointSizex
static inline void push_glPointSizex(GLfixed size) {
    PACKED_void_GLfixed *packed_data = malloc(sizeof(PACKED_void_GLfixed));
    packed_data->format = FORMAT_void_GLfixed;
    packed_data->func = glPointSizex;
    packed_data->args.a1 = size;
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
#ifndef direct_glPolygonOffsetx
static inline void push_glPolygonOffsetx(GLfixed factor, GLfixed units) {
    PACKED_void_GLfixed_GLfixed *packed_data = malloc(sizeof(PACKED_void_GLfixed_GLfixed));
    packed_data->format = FORMAT_void_GLfixed_GLfixed;
    packed_data->func = glPolygonOffsetx;
    packed_data->args.a1 = factor;
    packed_data->args.a2 = units;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glPopMatrix
static inline void push_glPopMatrix() {
    PACKED_void *packed_data = malloc(sizeof(PACKED_void));
    packed_data->format = FORMAT_void;
    packed_data->func = glPopMatrix;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glPushMatrix
static inline void push_glPushMatrix() {
    PACKED_void *packed_data = malloc(sizeof(PACKED_void));
    packed_data->format = FORMAT_void;
    packed_data->func = glPushMatrix;
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
#ifndef direct_glRotatef
static inline void push_glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
    PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat;
    packed_data->func = glRotatef;
    packed_data->args.a1 = angle;
    packed_data->args.a2 = x;
    packed_data->args.a3 = y;
    packed_data->args.a4 = z;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRotatex
static inline void push_glRotatex(GLfixed angle, GLfixed x, GLfixed y, GLfixed z) {
    PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed *packed_data = malloc(sizeof(PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed));
    packed_data->format = FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed;
    packed_data->func = glRotatex;
    packed_data->args.a1 = angle;
    packed_data->args.a2 = x;
    packed_data->args.a3 = y;
    packed_data->args.a4 = z;
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
#ifndef direct_glSampleCoveragex
static inline void push_glSampleCoveragex(GLclampx value, GLboolean invert) {
    PACKED_void_GLclampx_GLboolean *packed_data = malloc(sizeof(PACKED_void_GLclampx_GLboolean));
    packed_data->format = FORMAT_void_GLclampx_GLboolean;
    packed_data->func = glSampleCoveragex;
    packed_data->args.a1 = value;
    packed_data->args.a2 = invert;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glScalef
static inline void push_glScalef(GLfloat x, GLfloat y, GLfloat z) {
    PACKED_void_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat_GLfloat;
    packed_data->func = glScalef;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glScalex
static inline void push_glScalex(GLfixed x, GLfixed y, GLfixed z) {
    PACKED_void_GLfixed_GLfixed_GLfixed *packed_data = malloc(sizeof(PACKED_void_GLfixed_GLfixed_GLfixed));
    packed_data->format = FORMAT_void_GLfixed_GLfixed_GLfixed;
    packed_data->func = glScalex;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
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
#ifndef direct_glShadeModel
static inline void push_glShadeModel(GLenum mode) {
    PACKED_void_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum));
    packed_data->format = FORMAT_void_GLenum;
    packed_data->func = glShadeModel;
    packed_data->args.a1 = mode;
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
#ifndef direct_glStencilMask
static inline void push_glStencilMask(GLuint mask) {
    PACKED_void_GLuint *packed_data = malloc(sizeof(PACKED_void_GLuint));
    packed_data->format = FORMAT_void_GLuint;
    packed_data->func = glStencilMask;
    packed_data->args.a1 = mask;
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
#ifndef direct_glTexCoordPointer
static inline void push_glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__;
    packed_data->func = glTexCoordPointer;
    packed_data->args.a1 = size;
    packed_data->args.a2 = type;
    packed_data->args.a3 = stride;
    packed_data->args.a4 = pointer;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexEnvf
static inline void push_glTexEnvf(GLenum target, GLenum pname, GLfloat param) {
    PACKED_void_GLenum_GLenum_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfloat));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLfloat;
    packed_data->func = glTexEnvf;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexEnvfv
static inline void push_glTexEnvfv(GLenum target, GLenum pname, const GLfloat * params) {
    PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__;
    packed_data->func = glTexEnvfv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexEnvi
static inline void push_glTexEnvi(GLenum target, GLenum pname, GLint param) {
    PACKED_void_GLenum_GLenum_GLint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLint;
    packed_data->func = glTexEnvi;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexEnviv
static inline void push_glTexEnviv(GLenum target, GLenum pname, const GLint * params) {
    PACKED_void_GLenum_GLenum_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_const_GLint___GENPT__;
    packed_data->func = glTexEnviv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexEnvx
static inline void push_glTexEnvx(GLenum target, GLenum pname, GLfixed param) {
    PACKED_void_GLenum_GLenum_GLfixed *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfixed));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLfixed;
    packed_data->func = glTexEnvx;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexEnvxv
static inline void push_glTexEnvxv(GLenum target, GLenum pname, const GLfixed * params) {
    PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_const_GLfixed___GENPT__;
    packed_data->func = glTexEnvxv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
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
#ifndef direct_glTexParameterx
static inline void push_glTexParameterx(GLenum target, GLenum pname, GLfixed param) {
    PACKED_void_GLenum_GLenum_GLfixed *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfixed));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLfixed;
    packed_data->func = glTexParameterx;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexParameterxv
static inline void push_glTexParameterxv(GLenum target, GLenum pname, const GLfixed * params) {
    PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_const_GLfixed___GENPT__;
    packed_data->func = glTexParameterxv;
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
#ifndef direct_glTranslatef
static inline void push_glTranslatef(GLfloat x, GLfloat y, GLfloat z) {
    PACKED_void_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat_GLfloat;
    packed_data->func = glTranslatef;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTranslatex
static inline void push_glTranslatex(GLfixed x, GLfixed y, GLfixed z) {
    PACKED_void_GLfixed_GLfixed_GLfixed *packed_data = malloc(sizeof(PACKED_void_GLfixed_GLfixed_GLfixed));
    packed_data->format = FORMAT_void_GLfixed_GLfixed_GLfixed;
    packed_data->func = glTranslatex;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertexPointer
static inline void push_glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__;
    packed_data->func = glVertexPointer;
    packed_data->args.a1 = size;
    packed_data->args.a2 = type;
    packed_data->args.a3 = stride;
    packed_data->args.a4 = pointer;
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
