#ifndef USE_ES2
#include "../gl.h"

#ifndef GLESWRAP_H
#define GLESWRAP_H

typedef struct {
    int format;
    void *func;
    void *args;
} packed_call_t;

typedef struct {
    int func;
    void *args;
} indexed_call_t;

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
    FORMAT_void_GLenum_GLenum_GLenum_GLenum,
    FORMAT_GLenum_GLenum,
    FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLint_GLint_GLint_GLint_GLint,
    FORMAT_void_GLenum_GLenum_GLenum_GLuint,
    FORMAT_void_GLenum_GLenum_GLenum_GLuint_GLint,
    FORMAT_void_GLenum_GLenum_GLenum_GLint___GENPT__,
    FORMAT_void_GLenum_GLenum_GLsizei_GLsizei,
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
typedef struct {
    int func;
    ARGS_void_GLenum args;
} INDEXED_void_GLenum;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLclampf args;
} INDEXED_void_GLenum_GLclampf;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLclampx args;
} INDEXED_void_GLenum_GLclampx;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLuint args;
} INDEXED_void_GLenum_GLuint;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum args;
} INDEXED_void_GLenum_GLenum;
typedef void (*FUNC_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum)(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage);
typedef struct {
    GLenum a1;
    GLsizeiptr a2;
    GLvoid * a3;
    GLenum a4;
} ARGS_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum func;
    ARGS_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum args;
} PACKED_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum;
typedef struct {
    int func;
    ARGS_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum args;
} INDEXED_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum;
typedef void (*FUNC_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__)(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data);
typedef struct {
    GLenum a1;
    GLintptr a2;
    GLsizeiptr a3;
    GLvoid * a4;
} ARGS_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__;
typedef void (*FUNC_void_GLbitfield)(GLbitfield mask);
typedef struct {
    GLbitfield a1;
} ARGS_void_GLbitfield;
typedef struct {
    int format;
    FUNC_void_GLbitfield func;
    ARGS_void_GLbitfield args;
} PACKED_void_GLbitfield;
typedef struct {
    int func;
    ARGS_void_GLbitfield args;
} INDEXED_void_GLbitfield;
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
typedef struct {
    int func;
    ARGS_void_GLclampf_GLclampf_GLclampf_GLclampf args;
} INDEXED_void_GLclampf_GLclampf_GLclampf_GLclampf;
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
typedef struct {
    int func;
    ARGS_void_GLclampx_GLclampx_GLclampx_GLclampx args;
} INDEXED_void_GLclampx_GLclampx_GLclampx_GLclampx;
typedef void (*FUNC_void_GLclampf)(GLclampf depth);
typedef struct {
    GLclampf a1;
} ARGS_void_GLclampf;
typedef struct {
    int format;
    FUNC_void_GLclampf func;
    ARGS_void_GLclampf args;
} PACKED_void_GLclampf;
typedef struct {
    int func;
    ARGS_void_GLclampf args;
} INDEXED_void_GLclampf;
typedef void (*FUNC_void_GLclampx)(GLclampx depth);
typedef struct {
    GLclampx a1;
} ARGS_void_GLclampx;
typedef struct {
    int format;
    FUNC_void_GLclampx func;
    ARGS_void_GLclampx args;
} PACKED_void_GLclampx;
typedef struct {
    int func;
    ARGS_void_GLclampx args;
} INDEXED_void_GLclampx;
typedef void (*FUNC_void_GLint)(GLint s);
typedef struct {
    GLint a1;
} ARGS_void_GLint;
typedef struct {
    int format;
    FUNC_void_GLint func;
    ARGS_void_GLint args;
} PACKED_void_GLint;
typedef struct {
    int func;
    ARGS_void_GLint args;
} INDEXED_void_GLint;
typedef void (*FUNC_void_GLenum_const_GLfloat___GENPT__)(GLenum plane, const GLfloat * equation);
typedef struct {
    GLenum a1;
    GLfloat * a2;
} ARGS_void_GLenum_const_GLfloat___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_const_GLfloat___GENPT__ func;
    ARGS_void_GLenum_const_GLfloat___GENPT__ args;
} PACKED_void_GLenum_const_GLfloat___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_const_GLfloat___GENPT__ args;
} INDEXED_void_GLenum_const_GLfloat___GENPT__;
typedef void (*FUNC_void_GLenum_const_GLfixed___GENPT__)(GLenum plane, const GLfixed * equation);
typedef struct {
    GLenum a1;
    GLfixed * a2;
} ARGS_void_GLenum_const_GLfixed___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_const_GLfixed___GENPT__ func;
    ARGS_void_GLenum_const_GLfixed___GENPT__ args;
} PACKED_void_GLenum_const_GLfixed___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_const_GLfixed___GENPT__ args;
} INDEXED_void_GLenum_const_GLfixed___GENPT__;
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
typedef struct {
    int func;
    ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat args;
} INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat;
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
typedef struct {
    int func;
    ARGS_void_GLubyte_GLubyte_GLubyte_GLubyte args;
} INDEXED_void_GLubyte_GLubyte_GLubyte_GLubyte;
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
typedef struct {
    int func;
    ARGS_void_GLfixed_GLfixed_GLfixed_GLfixed args;
} INDEXED_void_GLfixed_GLfixed_GLfixed_GLfixed;
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
typedef struct {
    int func;
    ARGS_void_GLboolean_GLboolean_GLboolean_GLboolean args;
} INDEXED_void_GLboolean_GLboolean_GLboolean_GLboolean;
typedef void (*FUNC_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__)(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
typedef struct {
    GLint a1;
    GLenum a2;
    GLsizei a3;
    GLvoid * a4;
} ARGS_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ func;
    ARGS_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ args;
} PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ args;
} INDEXED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__;
typedef void (*FUNC_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data);
typedef struct {
    GLenum a1;
    GLint a2;
    GLenum a3;
    GLsizei a4;
    GLsizei a5;
    GLint a6;
    GLsizei a7;
    GLvoid * a8;
} ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__;
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
    GLvoid * a9;
} ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint args;
} INDEXED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei args;
} INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei;
typedef void (*FUNC_void_GLsizei_const_GLuint___GENPT__)(GLsizei n, const GLuint * buffers);
typedef struct {
    GLsizei a1;
    GLuint * a2;
} ARGS_void_GLsizei_const_GLuint___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLsizei_const_GLuint___GENPT__ func;
    ARGS_void_GLsizei_const_GLuint___GENPT__ args;
} PACKED_void_GLsizei_const_GLuint___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLsizei_const_GLuint___GENPT__ args;
} INDEXED_void_GLsizei_const_GLuint___GENPT__;
typedef void (*FUNC_void_GLboolean)(GLboolean flag);
typedef struct {
    GLboolean a1;
} ARGS_void_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLboolean func;
    ARGS_void_GLboolean args;
} PACKED_void_GLboolean;
typedef struct {
    int func;
    ARGS_void_GLboolean args;
} INDEXED_void_GLboolean;
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
typedef struct {
    int func;
    ARGS_void_GLclampf_GLclampf args;
} INDEXED_void_GLclampf_GLclampf;
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
typedef struct {
    int func;
    ARGS_void_GLclampx_GLclampx args;
} INDEXED_void_GLclampx_GLclampx;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLsizei args;
} INDEXED_void_GLenum_GLint_GLsizei;
typedef void (*FUNC_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__)(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLenum a3;
    GLvoid * a4;
} ARGS_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__;
typedef void (*FUNC_void)();
typedef struct {
    int format;
    FUNC_void func;
} PACKED_void;
typedef struct {
    int func;
} INDEXED_void;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLfloat args;
} INDEXED_void_GLenum_GLfloat;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLfixed args;
} INDEXED_void_GLenum_GLfixed;
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
typedef struct {
    int func;
    ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args;
} INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
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
typedef struct {
    int func;
    ARGS_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed args;
} INDEXED_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed;
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
typedef struct {
    int func;
    ARGS_void_GLsizei_GLuint___GENPT__ args;
} INDEXED_void_GLsizei_GLuint___GENPT__;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLboolean___GENPT__ args;
} INDEXED_void_GLenum_GLboolean___GENPT__;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_GLint___GENPT__ args;
} INDEXED_void_GLenum_GLenum_GLint___GENPT__;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLfloat___GENPT__ args;
} INDEXED_void_GLenum_GLfloat___GENPT__;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLfixed___GENPT__ args;
} INDEXED_void_GLenum_GLfixed___GENPT__;
typedef GLenum (*FUNC_GLenum)();
typedef struct {
    int format;
    FUNC_GLenum func;
} PACKED_GLenum;
typedef struct {
    int func;
} INDEXED_GLenum;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLint___GENPT__ args;
} INDEXED_void_GLenum_GLint___GENPT__;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args;
} INDEXED_void_GLenum_GLenum_GLfloat___GENPT__;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_GLfixed___GENPT__ args;
} INDEXED_void_GLenum_GLenum_GLfixed___GENPT__;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLvoid___GENPT____GENPT__ args;
} INDEXED_void_GLenum_GLvoid___GENPT____GENPT__;
typedef const GLubyte * (*FUNC_const_GLubyte___GENPT___GLenum)(GLenum name);
typedef struct {
    GLenum a1;
} ARGS_const_GLubyte___GENPT___GLenum;
typedef struct {
    int format;
    FUNC_const_GLubyte___GENPT___GLenum func;
    ARGS_const_GLubyte___GENPT___GLenum args;
} PACKED_const_GLubyte___GENPT___GLenum;
typedef struct {
    int func;
    ARGS_const_GLubyte___GENPT___GLenum args;
} INDEXED_const_GLubyte___GENPT___GLenum;
typedef GLboolean (*FUNC_GLboolean_GLuint)(GLuint buffer);
typedef struct {
    GLuint a1;
} ARGS_GLboolean_GLuint;
typedef struct {
    int format;
    FUNC_GLboolean_GLuint func;
    ARGS_GLboolean_GLuint args;
} PACKED_GLboolean_GLuint;
typedef struct {
    int func;
    ARGS_GLboolean_GLuint args;
} INDEXED_GLboolean_GLuint;
typedef GLboolean (*FUNC_GLboolean_GLenum)(GLenum cap);
typedef struct {
    GLenum a1;
} ARGS_GLboolean_GLenum;
typedef struct {
    int format;
    FUNC_GLboolean_GLenum func;
    ARGS_GLboolean_GLenum args;
} PACKED_GLboolean_GLenum;
typedef struct {
    int func;
    ARGS_GLboolean_GLenum args;
} INDEXED_GLboolean_GLenum;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_GLfloat args;
} INDEXED_void_GLenum_GLenum_GLfloat;
typedef void (*FUNC_void_GLenum_GLenum_const_GLfloat___GENPT__)(GLenum light, GLenum pname, const GLfloat * params);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLfloat * a3;
} ARGS_void_GLenum_GLenum_const_GLfloat___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_const_GLfloat___GENPT__ func;
    ARGS_void_GLenum_GLenum_const_GLfloat___GENPT__ args;
} PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_const_GLfloat___GENPT__ args;
} INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_GLfixed args;
} INDEXED_void_GLenum_GLenum_GLfixed;
typedef void (*FUNC_void_GLenum_GLenum_const_GLfixed___GENPT__)(GLenum light, GLenum pname, const GLfixed * params);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLfixed * a3;
} ARGS_void_GLenum_GLenum_const_GLfixed___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_const_GLfixed___GENPT__ func;
    ARGS_void_GLenum_GLenum_const_GLfixed___GENPT__ args;
} PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_const_GLfixed___GENPT__ args;
} INDEXED_void_GLenum_GLenum_const_GLfixed___GENPT__;
typedef void (*FUNC_void_GLfloat)(GLfloat width);
typedef struct {
    GLfloat a1;
} ARGS_void_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLfloat func;
    ARGS_void_GLfloat args;
} PACKED_void_GLfloat;
typedef struct {
    int func;
    ARGS_void_GLfloat args;
} INDEXED_void_GLfloat;
typedef void (*FUNC_void_GLfixed)(GLfixed width);
typedef struct {
    GLfixed a1;
} ARGS_void_GLfixed;
typedef struct {
    int format;
    FUNC_void_GLfixed func;
    ARGS_void_GLfixed args;
} PACKED_void_GLfixed;
typedef struct {
    int func;
    ARGS_void_GLfixed args;
} INDEXED_void_GLfixed;
typedef void (*FUNC_void_const_GLfloat___GENPT__)(const GLfloat * m);
typedef struct {
    GLfloat * a1;
} ARGS_void_const_GLfloat___GENPT__;
typedef struct {
    int format;
    FUNC_void_const_GLfloat___GENPT__ func;
    ARGS_void_const_GLfloat___GENPT__ args;
} PACKED_void_const_GLfloat___GENPT__;
typedef struct {
    int func;
    ARGS_void_const_GLfloat___GENPT__ args;
} INDEXED_void_const_GLfloat___GENPT__;
typedef void (*FUNC_void_const_GLfixed___GENPT__)(const GLfixed * m);
typedef struct {
    GLfixed * a1;
} ARGS_void_const_GLfixed___GENPT__;
typedef struct {
    int format;
    FUNC_void_const_GLfixed___GENPT__ func;
    ARGS_void_const_GLfixed___GENPT__ args;
} PACKED_void_const_GLfixed___GENPT__;
typedef struct {
    int func;
    ARGS_void_const_GLfixed___GENPT__ args;
} INDEXED_void_const_GLfixed___GENPT__;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat args;
} INDEXED_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed args;
} INDEXED_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed;
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
typedef struct {
    int func;
    ARGS_void_GLfloat_GLfloat_GLfloat args;
} INDEXED_void_GLfloat_GLfloat_GLfloat;
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
typedef struct {
    int func;
    ARGS_void_GLfixed_GLfixed_GLfixed args;
} INDEXED_void_GLfixed_GLfixed_GLfixed;
typedef void (*FUNC_void_GLenum_GLsizei_const_GLvoid___GENPT__)(GLenum type, GLsizei stride, const GLvoid * pointer);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLvoid * a3;
} ARGS_void_GLenum_GLsizei_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLsizei_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLsizei_const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLsizei_const_GLvoid___GENPT__;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLint args;
} INDEXED_void_GLenum_GLint;
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
typedef struct {
    int func;
    ARGS_void_GLfloat_GLfloat args;
} INDEXED_void_GLfloat_GLfloat;
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
typedef struct {
    int func;
    ARGS_void_GLfixed_GLfixed args;
} INDEXED_void_GLfixed_GLfixed;
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
typedef struct {
    int func;
    ARGS_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__ args;
} INDEXED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__;
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
typedef struct {
    int func;
    ARGS_void_GLclampf_GLboolean args;
} INDEXED_void_GLclampf_GLboolean;
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
typedef struct {
    int func;
    ARGS_void_GLclampx_GLboolean args;
} INDEXED_void_GLclampx_GLboolean;
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
typedef struct {
    int func;
    ARGS_void_GLint_GLint_GLsizei_GLsizei args;
} INDEXED_void_GLint_GLint_GLsizei_GLsizei;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLuint args;
} INDEXED_void_GLenum_GLint_GLuint;
typedef void (*FUNC_void_GLuint)(GLuint mask);
typedef struct {
    GLuint a1;
} ARGS_void_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint func;
    ARGS_void_GLuint args;
} PACKED_void_GLuint;
typedef struct {
    int func;
    ARGS_void_GLuint args;
} INDEXED_void_GLuint;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_GLenum args;
} INDEXED_void_GLenum_GLenum_GLenum;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_GLint args;
} INDEXED_void_GLenum_GLenum_GLint;
typedef void (*FUNC_void_GLenum_GLenum_const_GLint___GENPT__)(GLenum target, GLenum pname, const GLint * params);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint * a3;
} ARGS_void_GLenum_GLenum_const_GLint___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_const_GLint___GENPT__ func;
    ARGS_void_GLenum_GLenum_const_GLint___GENPT__ args;
} PACKED_void_GLenum_GLenum_const_GLint___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_const_GLint___GENPT__ args;
} INDEXED_void_GLenum_GLenum_const_GLint___GENPT__;
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
    GLvoid * a9;
} ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__;
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
    GLvoid * a9;
} ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_GLenum_GLenum args;
} INDEXED_void_GLenum_GLenum_GLenum_GLenum;
typedef GLenum (*FUNC_GLenum_GLenum)(GLenum target);
typedef struct {
    GLenum a1;
} ARGS_GLenum_GLenum;
typedef struct {
    int format;
    FUNC_GLenum_GLenum func;
    ARGS_GLenum_GLenum args;
} PACKED_GLenum_GLenum;
typedef struct {
    int func;
    ARGS_GLenum_GLenum args;
} INDEXED_GLenum_GLenum;
typedef void (*FUNC_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat)(GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height);
typedef struct {
    GLfloat a1;
    GLfloat a2;
    GLfloat a3;
    GLfloat a4;
    GLfloat a5;
} ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef struct {
    int func;
    ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args;
} INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLint_GLint_GLint_GLint_GLint)(GLint x, GLint y, GLint z, GLint width, GLint height);
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
typedef struct {
    int func;
    ARGS_void_GLint_GLint_GLint_GLint_GLint args;
} INDEXED_void_GLint_GLint_GLint_GLint_GLint;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_GLenum_GLuint args;
} INDEXED_void_GLenum_GLenum_GLenum_GLuint;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_GLenum_GLuint_GLint args;
} INDEXED_void_GLenum_GLenum_GLenum_GLuint_GLint;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_GLenum_GLint___GENPT__ args;
} INDEXED_void_GLenum_GLenum_GLenum_GLint___GENPT__;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_GLsizei_GLsizei args;
} INDEXED_void_GLenum_GLenum_GLsizei_GLsizei;

extern void glPushCall(void *data);
void glPackedCall(const packed_call_t *packed);
void glIndexedCall(const indexed_call_t *packed, void *ret_v);

#define glActiveTexture_INDEX 1
#define glActiveTexture_RETURN void
#define glActiveTexture_ARG_NAMES texture
#define glActiveTexture_ARG_EXPAND GLenum texture
#define glActiveTexture_PACKED PACKED_void_GLenum
#define glActiveTexture_INDEXED INDEXED_void_GLenum
#define glActiveTexture_FORMAT FORMAT_void_GLenum
#define glAlphaFunc_INDEX 2
#define glAlphaFunc_RETURN void
#define glAlphaFunc_ARG_NAMES func, ref
#define glAlphaFunc_ARG_EXPAND GLenum func, GLclampf ref
#define glAlphaFunc_PACKED PACKED_void_GLenum_GLclampf
#define glAlphaFunc_INDEXED INDEXED_void_GLenum_GLclampf
#define glAlphaFunc_FORMAT FORMAT_void_GLenum_GLclampf
#define glAlphaFuncx_INDEX 3
#define glAlphaFuncx_RETURN void
#define glAlphaFuncx_ARG_NAMES func, ref
#define glAlphaFuncx_ARG_EXPAND GLenum func, GLclampx ref
#define glAlphaFuncx_PACKED PACKED_void_GLenum_GLclampx
#define glAlphaFuncx_INDEXED INDEXED_void_GLenum_GLclampx
#define glAlphaFuncx_FORMAT FORMAT_void_GLenum_GLclampx
#define glBindBuffer_INDEX 4
#define glBindBuffer_RETURN void
#define glBindBuffer_ARG_NAMES target, buffer
#define glBindBuffer_ARG_EXPAND GLenum target, GLuint buffer
#define glBindBuffer_PACKED PACKED_void_GLenum_GLuint
#define glBindBuffer_INDEXED INDEXED_void_GLenum_GLuint
#define glBindBuffer_FORMAT FORMAT_void_GLenum_GLuint
#define glBindFramebuffer_INDEX 5
#define glBindFramebuffer_RETURN void
#define glBindFramebuffer_ARG_NAMES target, framebuffer
#define glBindFramebuffer_ARG_EXPAND GLenum target, GLuint framebuffer
#define glBindFramebuffer_PACKED PACKED_void_GLenum_GLuint
#define glBindFramebuffer_INDEXED INDEXED_void_GLenum_GLuint
#define glBindFramebuffer_FORMAT FORMAT_void_GLenum_GLuint
#define glBindRenderbuffer_INDEX 6
#define glBindRenderbuffer_RETURN void
#define glBindRenderbuffer_ARG_NAMES target, renderbuffer
#define glBindRenderbuffer_ARG_EXPAND GLenum target, GLuint renderbuffer
#define glBindRenderbuffer_PACKED PACKED_void_GLenum_GLuint
#define glBindRenderbuffer_INDEXED INDEXED_void_GLenum_GLuint
#define glBindRenderbuffer_FORMAT FORMAT_void_GLenum_GLuint
#define glBindTexture_INDEX 7
#define glBindTexture_RETURN void
#define glBindTexture_ARG_NAMES target, texture
#define glBindTexture_ARG_EXPAND GLenum target, GLuint texture
#define glBindTexture_PACKED PACKED_void_GLenum_GLuint
#define glBindTexture_INDEXED INDEXED_void_GLenum_GLuint
#define glBindTexture_FORMAT FORMAT_void_GLenum_GLuint
#define glBlendColor_INDEX 8
#define glBlendColor_RETURN void
#define glBlendColor_ARG_NAMES red, green, blue, alpha
#define glBlendColor_ARG_EXPAND GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha
#define glBlendColor_PACKED PACKED_void_GLclampf_GLclampf_GLclampf_GLclampf
#define glBlendColor_INDEXED INDEXED_void_GLclampf_GLclampf_GLclampf_GLclampf
#define glBlendColor_FORMAT FORMAT_void_GLclampf_GLclampf_GLclampf_GLclampf
#define glBlendEquation_INDEX 9
#define glBlendEquation_RETURN void
#define glBlendEquation_ARG_NAMES mode
#define glBlendEquation_ARG_EXPAND GLenum mode
#define glBlendEquation_PACKED PACKED_void_GLenum
#define glBlendEquation_INDEXED INDEXED_void_GLenum
#define glBlendEquation_FORMAT FORMAT_void_GLenum
#define glBlendEquationSeparate_INDEX 10
#define glBlendEquationSeparate_RETURN void
#define glBlendEquationSeparate_ARG_NAMES modeRGB, modeA
#define glBlendEquationSeparate_ARG_EXPAND GLenum modeRGB, GLenum modeA
#define glBlendEquationSeparate_PACKED PACKED_void_GLenum_GLenum
#define glBlendEquationSeparate_INDEXED INDEXED_void_GLenum_GLenum
#define glBlendEquationSeparate_FORMAT FORMAT_void_GLenum_GLenum
#define glBlendFunc_INDEX 11
#define glBlendFunc_RETURN void
#define glBlendFunc_ARG_NAMES sfactor, dfactor
#define glBlendFunc_ARG_EXPAND GLenum sfactor, GLenum dfactor
#define glBlendFunc_PACKED PACKED_void_GLenum_GLenum
#define glBlendFunc_INDEXED INDEXED_void_GLenum_GLenum
#define glBlendFunc_FORMAT FORMAT_void_GLenum_GLenum
#define glBlendFuncSeparate_INDEX 12
#define glBlendFuncSeparate_RETURN void
#define glBlendFuncSeparate_ARG_NAMES sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha
#define glBlendFuncSeparate_ARG_EXPAND GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha
#define glBlendFuncSeparate_PACKED PACKED_void_GLenum_GLenum_GLenum_GLenum
#define glBlendFuncSeparate_INDEXED INDEXED_void_GLenum_GLenum_GLenum_GLenum
#define glBlendFuncSeparate_FORMAT FORMAT_void_GLenum_GLenum_GLenum_GLenum
#define glBufferData_INDEX 13
#define glBufferData_RETURN void
#define glBufferData_ARG_NAMES target, size, data, usage
#define glBufferData_ARG_EXPAND GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage
#define glBufferData_PACKED PACKED_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum
#define glBufferData_INDEXED INDEXED_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum
#define glBufferData_FORMAT FORMAT_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum
#define glBufferSubData_INDEX 14
#define glBufferSubData_RETURN void
#define glBufferSubData_ARG_NAMES target, offset, size, data
#define glBufferSubData_ARG_EXPAND GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data
#define glBufferSubData_PACKED PACKED_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__
#define glBufferSubData_INDEXED INDEXED_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__
#define glBufferSubData_FORMAT FORMAT_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__
#define glCheckFramebufferStatus_INDEX 15
#define glCheckFramebufferStatus_RETURN GLenum
#define glCheckFramebufferStatus_ARG_NAMES target
#define glCheckFramebufferStatus_ARG_EXPAND GLenum target
#define glCheckFramebufferStatus_PACKED PACKED_GLenum_GLenum
#define glCheckFramebufferStatus_INDEXED INDEXED_GLenum_GLenum
#define glCheckFramebufferStatus_FORMAT FORMAT_GLenum_GLenum
#define glClear_INDEX 16
#define glClear_RETURN void
#define glClear_ARG_NAMES mask
#define glClear_ARG_EXPAND GLbitfield mask
#define glClear_PACKED PACKED_void_GLbitfield
#define glClear_INDEXED INDEXED_void_GLbitfield
#define glClear_FORMAT FORMAT_void_GLbitfield
#define glClearColor_INDEX 17
#define glClearColor_RETURN void
#define glClearColor_ARG_NAMES red, green, blue, alpha
#define glClearColor_ARG_EXPAND GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha
#define glClearColor_PACKED PACKED_void_GLclampf_GLclampf_GLclampf_GLclampf
#define glClearColor_INDEXED INDEXED_void_GLclampf_GLclampf_GLclampf_GLclampf
#define glClearColor_FORMAT FORMAT_void_GLclampf_GLclampf_GLclampf_GLclampf
#define glClearColorx_INDEX 18
#define glClearColorx_RETURN void
#define glClearColorx_ARG_NAMES red, green, blue, alpha
#define glClearColorx_ARG_EXPAND GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha
#define glClearColorx_PACKED PACKED_void_GLclampx_GLclampx_GLclampx_GLclampx
#define glClearColorx_INDEXED INDEXED_void_GLclampx_GLclampx_GLclampx_GLclampx
#define glClearColorx_FORMAT FORMAT_void_GLclampx_GLclampx_GLclampx_GLclampx
#define glClearDepthf_INDEX 19
#define glClearDepthf_RETURN void
#define glClearDepthf_ARG_NAMES depth
#define glClearDepthf_ARG_EXPAND GLclampf depth
#define glClearDepthf_PACKED PACKED_void_GLclampf
#define glClearDepthf_INDEXED INDEXED_void_GLclampf
#define glClearDepthf_FORMAT FORMAT_void_GLclampf
#define glClearDepthx_INDEX 20
#define glClearDepthx_RETURN void
#define glClearDepthx_ARG_NAMES depth
#define glClearDepthx_ARG_EXPAND GLclampx depth
#define glClearDepthx_PACKED PACKED_void_GLclampx
#define glClearDepthx_INDEXED INDEXED_void_GLclampx
#define glClearDepthx_FORMAT FORMAT_void_GLclampx
#define glClearStencil_INDEX 21
#define glClearStencil_RETURN void
#define glClearStencil_ARG_NAMES s
#define glClearStencil_ARG_EXPAND GLint s
#define glClearStencil_PACKED PACKED_void_GLint
#define glClearStencil_INDEXED INDEXED_void_GLint
#define glClearStencil_FORMAT FORMAT_void_GLint
#define glClientActiveTexture_INDEX 22
#define glClientActiveTexture_RETURN void
#define glClientActiveTexture_ARG_NAMES texture
#define glClientActiveTexture_ARG_EXPAND GLenum texture
#define glClientActiveTexture_PACKED PACKED_void_GLenum
#define glClientActiveTexture_INDEXED INDEXED_void_GLenum
#define glClientActiveTexture_FORMAT FORMAT_void_GLenum
#define glClipPlanef_INDEX 23
#define glClipPlanef_RETURN void
#define glClipPlanef_ARG_NAMES plane, equation
#define glClipPlanef_ARG_EXPAND GLenum plane, const GLfloat * equation
#define glClipPlanef_PACKED PACKED_void_GLenum_const_GLfloat___GENPT__
#define glClipPlanef_INDEXED INDEXED_void_GLenum_const_GLfloat___GENPT__
#define glClipPlanef_FORMAT FORMAT_void_GLenum_const_GLfloat___GENPT__
#define glClipPlanex_INDEX 24
#define glClipPlanex_RETURN void
#define glClipPlanex_ARG_NAMES plane, equation
#define glClipPlanex_ARG_EXPAND GLenum plane, const GLfixed * equation
#define glClipPlanex_PACKED PACKED_void_GLenum_const_GLfixed___GENPT__
#define glClipPlanex_INDEXED INDEXED_void_GLenum_const_GLfixed___GENPT__
#define glClipPlanex_FORMAT FORMAT_void_GLenum_const_GLfixed___GENPT__
#define glColor4f_INDEX 25
#define glColor4f_RETURN void
#define glColor4f_ARG_NAMES red, green, blue, alpha
#define glColor4f_ARG_EXPAND GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha
#define glColor4f_PACKED PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glColor4f_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glColor4f_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glColor4ub_INDEX 26
#define glColor4ub_RETURN void
#define glColor4ub_ARG_NAMES red, green, blue, alpha
#define glColor4ub_ARG_EXPAND GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha
#define glColor4ub_PACKED PACKED_void_GLubyte_GLubyte_GLubyte_GLubyte
#define glColor4ub_INDEXED INDEXED_void_GLubyte_GLubyte_GLubyte_GLubyte
#define glColor4ub_FORMAT FORMAT_void_GLubyte_GLubyte_GLubyte_GLubyte
#define glColor4x_INDEX 27
#define glColor4x_RETURN void
#define glColor4x_ARG_NAMES red, green, blue, alpha
#define glColor4x_ARG_EXPAND GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha
#define glColor4x_PACKED PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed
#define glColor4x_INDEXED INDEXED_void_GLfixed_GLfixed_GLfixed_GLfixed
#define glColor4x_FORMAT FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed
#define glColorMask_INDEX 28
#define glColorMask_RETURN void
#define glColorMask_ARG_NAMES red, green, blue, alpha
#define glColorMask_ARG_EXPAND GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha
#define glColorMask_PACKED PACKED_void_GLboolean_GLboolean_GLboolean_GLboolean
#define glColorMask_INDEXED INDEXED_void_GLboolean_GLboolean_GLboolean_GLboolean
#define glColorMask_FORMAT FORMAT_void_GLboolean_GLboolean_GLboolean_GLboolean
#define glColorPointer_INDEX 29
#define glColorPointer_RETURN void
#define glColorPointer_ARG_NAMES size, type, stride, pointer
#define glColorPointer_ARG_EXPAND GLint size, GLenum type, GLsizei stride, const GLvoid * pointer
#define glColorPointer_PACKED PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__
#define glColorPointer_INDEXED INDEXED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__
#define glColorPointer_FORMAT FORMAT_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__
#define glCompressedTexImage2D_INDEX 30
#define glCompressedTexImage2D_RETURN void
#define glCompressedTexImage2D_ARG_NAMES target, level, internalformat, width, height, border, imageSize, data
#define glCompressedTexImage2D_ARG_EXPAND GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data
#define glCompressedTexImage2D_PACKED PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__
#define glCompressedTexImage2D_INDEXED INDEXED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__
#define glCompressedTexImage2D_FORMAT FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__
#define glCompressedTexSubImage2D_INDEX 31
#define glCompressedTexSubImage2D_RETURN void
#define glCompressedTexSubImage2D_ARG_NAMES target, level, xoffset, yoffset, width, height, format, imageSize, data
#define glCompressedTexSubImage2D_ARG_EXPAND GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data
#define glCompressedTexSubImage2D_PACKED PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__
#define glCompressedTexSubImage2D_INDEXED INDEXED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__
#define glCompressedTexSubImage2D_FORMAT FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__
#define glCopyTexImage2D_INDEX 32
#define glCopyTexImage2D_RETURN void
#define glCopyTexImage2D_ARG_NAMES target, level, internalformat, x, y, width, height, border
#define glCopyTexImage2D_ARG_EXPAND GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border
#define glCopyTexImage2D_PACKED PACKED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint
#define glCopyTexImage2D_INDEXED INDEXED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint
#define glCopyTexImage2D_FORMAT FORMAT_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint
#define glCopyTexSubImage2D_INDEX 33
#define glCopyTexSubImage2D_RETURN void
#define glCopyTexSubImage2D_ARG_NAMES target, level, xoffset, yoffset, x, y, width, height
#define glCopyTexSubImage2D_ARG_EXPAND GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height
#define glCopyTexSubImage2D_PACKED PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei
#define glCopyTexSubImage2D_INDEXED INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei
#define glCopyTexSubImage2D_FORMAT FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei
#define glCullFace_INDEX 34
#define glCullFace_RETURN void
#define glCullFace_ARG_NAMES mode
#define glCullFace_ARG_EXPAND GLenum mode
#define glCullFace_PACKED PACKED_void_GLenum
#define glCullFace_INDEXED INDEXED_void_GLenum
#define glCullFace_FORMAT FORMAT_void_GLenum
#define glDeleteBuffers_INDEX 35
#define glDeleteBuffers_RETURN void
#define glDeleteBuffers_ARG_NAMES n, buffers
#define glDeleteBuffers_ARG_EXPAND GLsizei n, const GLuint * buffers
#define glDeleteBuffers_PACKED PACKED_void_GLsizei_const_GLuint___GENPT__
#define glDeleteBuffers_INDEXED INDEXED_void_GLsizei_const_GLuint___GENPT__
#define glDeleteBuffers_FORMAT FORMAT_void_GLsizei_const_GLuint___GENPT__
#define glDeleteFramebuffers_INDEX 36
#define glDeleteFramebuffers_RETURN void
#define glDeleteFramebuffers_ARG_NAMES n, framebuffers
#define glDeleteFramebuffers_ARG_EXPAND GLsizei n, GLuint * framebuffers
#define glDeleteFramebuffers_PACKED PACKED_void_GLsizei_GLuint___GENPT__
#define glDeleteFramebuffers_INDEXED INDEXED_void_GLsizei_GLuint___GENPT__
#define glDeleteFramebuffers_FORMAT FORMAT_void_GLsizei_GLuint___GENPT__
#define glDeleteRenderbuffers_INDEX 37
#define glDeleteRenderbuffers_RETURN void
#define glDeleteRenderbuffers_ARG_NAMES n, renderbuffers
#define glDeleteRenderbuffers_ARG_EXPAND GLsizei n, GLuint * renderbuffers
#define glDeleteRenderbuffers_PACKED PACKED_void_GLsizei_GLuint___GENPT__
#define glDeleteRenderbuffers_INDEXED INDEXED_void_GLsizei_GLuint___GENPT__
#define glDeleteRenderbuffers_FORMAT FORMAT_void_GLsizei_GLuint___GENPT__
#define glDeleteTextures_INDEX 38
#define glDeleteTextures_RETURN void
#define glDeleteTextures_ARG_NAMES n, textures
#define glDeleteTextures_ARG_EXPAND GLsizei n, const GLuint * textures
#define glDeleteTextures_PACKED PACKED_void_GLsizei_const_GLuint___GENPT__
#define glDeleteTextures_INDEXED INDEXED_void_GLsizei_const_GLuint___GENPT__
#define glDeleteTextures_FORMAT FORMAT_void_GLsizei_const_GLuint___GENPT__
#define glDepthFunc_INDEX 39
#define glDepthFunc_RETURN void
#define glDepthFunc_ARG_NAMES func
#define glDepthFunc_ARG_EXPAND GLenum func
#define glDepthFunc_PACKED PACKED_void_GLenum
#define glDepthFunc_INDEXED INDEXED_void_GLenum
#define glDepthFunc_FORMAT FORMAT_void_GLenum
#define glDepthMask_INDEX 40
#define glDepthMask_RETURN void
#define glDepthMask_ARG_NAMES flag
#define glDepthMask_ARG_EXPAND GLboolean flag
#define glDepthMask_PACKED PACKED_void_GLboolean
#define glDepthMask_INDEXED INDEXED_void_GLboolean
#define glDepthMask_FORMAT FORMAT_void_GLboolean
#define glDepthRangef_INDEX 41
#define glDepthRangef_RETURN void
#define glDepthRangef_ARG_NAMES near, far
#define glDepthRangef_ARG_EXPAND GLclampf near, GLclampf far
#define glDepthRangef_PACKED PACKED_void_GLclampf_GLclampf
#define glDepthRangef_INDEXED INDEXED_void_GLclampf_GLclampf
#define glDepthRangef_FORMAT FORMAT_void_GLclampf_GLclampf
#define glDepthRangex_INDEX 42
#define glDepthRangex_RETURN void
#define glDepthRangex_ARG_NAMES near, far
#define glDepthRangex_ARG_EXPAND GLclampx near, GLclampx far
#define glDepthRangex_PACKED PACKED_void_GLclampx_GLclampx
#define glDepthRangex_INDEXED INDEXED_void_GLclampx_GLclampx
#define glDepthRangex_FORMAT FORMAT_void_GLclampx_GLclampx
#define glDisable_INDEX 43
#define glDisable_RETURN void
#define glDisable_ARG_NAMES cap
#define glDisable_ARG_EXPAND GLenum cap
#define glDisable_PACKED PACKED_void_GLenum
#define glDisable_INDEXED INDEXED_void_GLenum
#define glDisable_FORMAT FORMAT_void_GLenum
#define glDisableClientState_INDEX 44
#define glDisableClientState_RETURN void
#define glDisableClientState_ARG_NAMES array
#define glDisableClientState_ARG_EXPAND GLenum array
#define glDisableClientState_PACKED PACKED_void_GLenum
#define glDisableClientState_INDEXED INDEXED_void_GLenum
#define glDisableClientState_FORMAT FORMAT_void_GLenum
#define glDrawArrays_INDEX 45
#define glDrawArrays_RETURN void
#define glDrawArrays_ARG_NAMES mode, first, count
#define glDrawArrays_ARG_EXPAND GLenum mode, GLint first, GLsizei count
#define glDrawArrays_PACKED PACKED_void_GLenum_GLint_GLsizei
#define glDrawArrays_INDEXED INDEXED_void_GLenum_GLint_GLsizei
#define glDrawArrays_FORMAT FORMAT_void_GLenum_GLint_GLsizei
#define glDrawElements_INDEX 46
#define glDrawElements_RETURN void
#define glDrawElements_ARG_NAMES mode, count, type, indices
#define glDrawElements_ARG_EXPAND GLenum mode, GLsizei count, GLenum type, const GLvoid * indices
#define glDrawElements_PACKED PACKED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__
#define glDrawElements_INDEXED INDEXED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__
#define glDrawElements_FORMAT FORMAT_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__
#define glDrawTexf_INDEX 47
#define glDrawTexf_RETURN void
#define glDrawTexf_ARG_NAMES x, y, z, width, height
#define glDrawTexf_ARG_EXPAND GLfloat x, GLfloat y, GLfloat z, GLfloat width, GLfloat height
#define glDrawTexf_PACKED PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat
#define glDrawTexf_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat
#define glDrawTexf_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat
#define glDrawTexi_INDEX 48
#define glDrawTexi_RETURN void
#define glDrawTexi_ARG_NAMES x, y, z, width, height
#define glDrawTexi_ARG_EXPAND GLint x, GLint y, GLint z, GLint width, GLint height
#define glDrawTexi_PACKED PACKED_void_GLint_GLint_GLint_GLint_GLint
#define glDrawTexi_INDEXED INDEXED_void_GLint_GLint_GLint_GLint_GLint
#define glDrawTexi_FORMAT FORMAT_void_GLint_GLint_GLint_GLint_GLint
#define glEnable_INDEX 49
#define glEnable_RETURN void
#define glEnable_ARG_NAMES cap
#define glEnable_ARG_EXPAND GLenum cap
#define glEnable_PACKED PACKED_void_GLenum
#define glEnable_INDEXED INDEXED_void_GLenum
#define glEnable_FORMAT FORMAT_void_GLenum
#define glEnableClientState_INDEX 50
#define glEnableClientState_RETURN void
#define glEnableClientState_ARG_NAMES array
#define glEnableClientState_ARG_EXPAND GLenum array
#define glEnableClientState_PACKED PACKED_void_GLenum
#define glEnableClientState_INDEXED INDEXED_void_GLenum
#define glEnableClientState_FORMAT FORMAT_void_GLenum
#define glFinish_INDEX 51
#define glFinish_RETURN void
#define glFinish_ARG_NAMES 
#define glFinish_ARG_EXPAND 
#define glFinish_PACKED PACKED_void
#define glFinish_INDEXED INDEXED_void
#define glFinish_FORMAT FORMAT_void
#define glFlush_INDEX 52
#define glFlush_RETURN void
#define glFlush_ARG_NAMES 
#define glFlush_ARG_EXPAND 
#define glFlush_PACKED PACKED_void
#define glFlush_INDEXED INDEXED_void
#define glFlush_FORMAT FORMAT_void
#define glFogf_INDEX 53
#define glFogf_RETURN void
#define glFogf_ARG_NAMES pname, param
#define glFogf_ARG_EXPAND GLenum pname, GLfloat param
#define glFogf_PACKED PACKED_void_GLenum_GLfloat
#define glFogf_INDEXED INDEXED_void_GLenum_GLfloat
#define glFogf_FORMAT FORMAT_void_GLenum_GLfloat
#define glFogfv_INDEX 54
#define glFogfv_RETURN void
#define glFogfv_ARG_NAMES pname, params
#define glFogfv_ARG_EXPAND GLenum pname, const GLfloat * params
#define glFogfv_PACKED PACKED_void_GLenum_const_GLfloat___GENPT__
#define glFogfv_INDEXED INDEXED_void_GLenum_const_GLfloat___GENPT__
#define glFogfv_FORMAT FORMAT_void_GLenum_const_GLfloat___GENPT__
#define glFogx_INDEX 55
#define glFogx_RETURN void
#define glFogx_ARG_NAMES pname, param
#define glFogx_ARG_EXPAND GLenum pname, GLfixed param
#define glFogx_PACKED PACKED_void_GLenum_GLfixed
#define glFogx_INDEXED INDEXED_void_GLenum_GLfixed
#define glFogx_FORMAT FORMAT_void_GLenum_GLfixed
#define glFogxv_INDEX 56
#define glFogxv_RETURN void
#define glFogxv_ARG_NAMES pname, params
#define glFogxv_ARG_EXPAND GLenum pname, const GLfixed * params
#define glFogxv_PACKED PACKED_void_GLenum_const_GLfixed___GENPT__
#define glFogxv_INDEXED INDEXED_void_GLenum_const_GLfixed___GENPT__
#define glFogxv_FORMAT FORMAT_void_GLenum_const_GLfixed___GENPT__
#define glFramebufferRenderbuffer_INDEX 57
#define glFramebufferRenderbuffer_RETURN void
#define glFramebufferRenderbuffer_ARG_NAMES target, attachment, renderbuffertarget, renderbuffer
#define glFramebufferRenderbuffer_ARG_EXPAND GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer
#define glFramebufferRenderbuffer_PACKED PACKED_void_GLenum_GLenum_GLenum_GLuint
#define glFramebufferRenderbuffer_INDEXED INDEXED_void_GLenum_GLenum_GLenum_GLuint
#define glFramebufferRenderbuffer_FORMAT FORMAT_void_GLenum_GLenum_GLenum_GLuint
#define glFramebufferTexture2D_INDEX 58
#define glFramebufferTexture2D_RETURN void
#define glFramebufferTexture2D_ARG_NAMES target, attachment, textarget, texture, level
#define glFramebufferTexture2D_ARG_EXPAND GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level
#define glFramebufferTexture2D_PACKED PACKED_void_GLenum_GLenum_GLenum_GLuint_GLint
#define glFramebufferTexture2D_INDEXED INDEXED_void_GLenum_GLenum_GLenum_GLuint_GLint
#define glFramebufferTexture2D_FORMAT FORMAT_void_GLenum_GLenum_GLenum_GLuint_GLint
#define glFrontFace_INDEX 59
#define glFrontFace_RETURN void
#define glFrontFace_ARG_NAMES mode
#define glFrontFace_ARG_EXPAND GLenum mode
#define glFrontFace_PACKED PACKED_void_GLenum
#define glFrontFace_INDEXED INDEXED_void_GLenum
#define glFrontFace_FORMAT FORMAT_void_GLenum
#define glFrustumf_INDEX 60
#define glFrustumf_RETURN void
#define glFrustumf_ARG_NAMES left, right, bottom, top, near, far
#define glFrustumf_ARG_EXPAND GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far
#define glFrustumf_PACKED PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat
#define glFrustumf_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat
#define glFrustumf_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat
#define glFrustumx_INDEX 61
#define glFrustumx_RETURN void
#define glFrustumx_ARG_NAMES left, right, bottom, top, near, far
#define glFrustumx_ARG_EXPAND GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far
#define glFrustumx_PACKED PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed
#define glFrustumx_INDEXED INDEXED_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed
#define glFrustumx_FORMAT FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed
#define glGenBuffers_INDEX 62
#define glGenBuffers_RETURN void
#define glGenBuffers_ARG_NAMES n, buffers
#define glGenBuffers_ARG_EXPAND GLsizei n, GLuint * buffers
#define glGenBuffers_PACKED PACKED_void_GLsizei_GLuint___GENPT__
#define glGenBuffers_INDEXED INDEXED_void_GLsizei_GLuint___GENPT__
#define glGenBuffers_FORMAT FORMAT_void_GLsizei_GLuint___GENPT__
#define glGenFramebuffers_INDEX 63
#define glGenFramebuffers_RETURN void
#define glGenFramebuffers_ARG_NAMES n, ids
#define glGenFramebuffers_ARG_EXPAND GLsizei n, GLuint * ids
#define glGenFramebuffers_PACKED PACKED_void_GLsizei_GLuint___GENPT__
#define glGenFramebuffers_INDEXED INDEXED_void_GLsizei_GLuint___GENPT__
#define glGenFramebuffers_FORMAT FORMAT_void_GLsizei_GLuint___GENPT__
#define glGenRenderbuffers_INDEX 64
#define glGenRenderbuffers_RETURN void
#define glGenRenderbuffers_ARG_NAMES n, renderbuffers
#define glGenRenderbuffers_ARG_EXPAND GLsizei n, GLuint * renderbuffers
#define glGenRenderbuffers_PACKED PACKED_void_GLsizei_GLuint___GENPT__
#define glGenRenderbuffers_INDEXED INDEXED_void_GLsizei_GLuint___GENPT__
#define glGenRenderbuffers_FORMAT FORMAT_void_GLsizei_GLuint___GENPT__
#define glGenTextures_INDEX 65
#define glGenTextures_RETURN void
#define glGenTextures_ARG_NAMES n, textures
#define glGenTextures_ARG_EXPAND GLsizei n, GLuint * textures
#define glGenTextures_PACKED PACKED_void_GLsizei_GLuint___GENPT__
#define glGenTextures_INDEXED INDEXED_void_GLsizei_GLuint___GENPT__
#define glGenTextures_FORMAT FORMAT_void_GLsizei_GLuint___GENPT__
#define glGenerateMipmap_INDEX 66
#define glGenerateMipmap_RETURN void
#define glGenerateMipmap_ARG_NAMES target
#define glGenerateMipmap_ARG_EXPAND GLenum target
#define glGenerateMipmap_PACKED PACKED_void_GLenum
#define glGenerateMipmap_INDEXED INDEXED_void_GLenum
#define glGenerateMipmap_FORMAT FORMAT_void_GLenum
#define glGetBooleanv_INDEX 67
#define glGetBooleanv_RETURN void
#define glGetBooleanv_ARG_NAMES pname, params
#define glGetBooleanv_ARG_EXPAND GLenum pname, GLboolean * params
#define glGetBooleanv_PACKED PACKED_void_GLenum_GLboolean___GENPT__
#define glGetBooleanv_INDEXED INDEXED_void_GLenum_GLboolean___GENPT__
#define glGetBooleanv_FORMAT FORMAT_void_GLenum_GLboolean___GENPT__
#define glGetBufferParameteriv_INDEX 68
#define glGetBufferParameteriv_RETURN void
#define glGetBufferParameteriv_ARG_NAMES target, pname, params
#define glGetBufferParameteriv_ARG_EXPAND GLenum target, GLenum pname, GLint * params
#define glGetBufferParameteriv_PACKED PACKED_void_GLenum_GLenum_GLint___GENPT__
#define glGetBufferParameteriv_INDEXED INDEXED_void_GLenum_GLenum_GLint___GENPT__
#define glGetBufferParameteriv_FORMAT FORMAT_void_GLenum_GLenum_GLint___GENPT__
#define glGetClipPlanef_INDEX 69
#define glGetClipPlanef_RETURN void
#define glGetClipPlanef_ARG_NAMES plane, equation
#define glGetClipPlanef_ARG_EXPAND GLenum plane, GLfloat * equation
#define glGetClipPlanef_PACKED PACKED_void_GLenum_GLfloat___GENPT__
#define glGetClipPlanef_INDEXED INDEXED_void_GLenum_GLfloat___GENPT__
#define glGetClipPlanef_FORMAT FORMAT_void_GLenum_GLfloat___GENPT__
#define glGetClipPlanex_INDEX 70
#define glGetClipPlanex_RETURN void
#define glGetClipPlanex_ARG_NAMES plane, equation
#define glGetClipPlanex_ARG_EXPAND GLenum plane, GLfixed * equation
#define glGetClipPlanex_PACKED PACKED_void_GLenum_GLfixed___GENPT__
#define glGetClipPlanex_INDEXED INDEXED_void_GLenum_GLfixed___GENPT__
#define glGetClipPlanex_FORMAT FORMAT_void_GLenum_GLfixed___GENPT__
#define glGetError_INDEX 71
#define glGetError_RETURN GLenum
#define glGetError_ARG_NAMES 
#define glGetError_ARG_EXPAND 
#define glGetError_PACKED PACKED_GLenum
#define glGetError_INDEXED INDEXED_GLenum
#define glGetError_FORMAT FORMAT_GLenum
#define glGetFixedv_INDEX 72
#define glGetFixedv_RETURN void
#define glGetFixedv_ARG_NAMES pname, params
#define glGetFixedv_ARG_EXPAND GLenum pname, GLfixed * params
#define glGetFixedv_PACKED PACKED_void_GLenum_GLfixed___GENPT__
#define glGetFixedv_INDEXED INDEXED_void_GLenum_GLfixed___GENPT__
#define glGetFixedv_FORMAT FORMAT_void_GLenum_GLfixed___GENPT__
#define glGetFloatv_INDEX 73
#define glGetFloatv_RETURN void
#define glGetFloatv_ARG_NAMES pname, params
#define glGetFloatv_ARG_EXPAND GLenum pname, GLfloat * params
#define glGetFloatv_PACKED PACKED_void_GLenum_GLfloat___GENPT__
#define glGetFloatv_INDEXED INDEXED_void_GLenum_GLfloat___GENPT__
#define glGetFloatv_FORMAT FORMAT_void_GLenum_GLfloat___GENPT__
#define glGetFramebufferAttachmentParameteriv_INDEX 74
#define glGetFramebufferAttachmentParameteriv_RETURN void
#define glGetFramebufferAttachmentParameteriv_ARG_NAMES target, attachment, pname, params
#define glGetFramebufferAttachmentParameteriv_ARG_EXPAND GLenum target, GLenum attachment, GLenum pname, GLint * params
#define glGetFramebufferAttachmentParameteriv_PACKED PACKED_void_GLenum_GLenum_GLenum_GLint___GENPT__
#define glGetFramebufferAttachmentParameteriv_INDEXED INDEXED_void_GLenum_GLenum_GLenum_GLint___GENPT__
#define glGetFramebufferAttachmentParameteriv_FORMAT FORMAT_void_GLenum_GLenum_GLenum_GLint___GENPT__
#define glGetIntegerv_INDEX 75
#define glGetIntegerv_RETURN void
#define glGetIntegerv_ARG_NAMES pname, params
#define glGetIntegerv_ARG_EXPAND GLenum pname, GLint * params
#define glGetIntegerv_PACKED PACKED_void_GLenum_GLint___GENPT__
#define glGetIntegerv_INDEXED INDEXED_void_GLenum_GLint___GENPT__
#define glGetIntegerv_FORMAT FORMAT_void_GLenum_GLint___GENPT__
#define glGetLightfv_INDEX 76
#define glGetLightfv_RETURN void
#define glGetLightfv_ARG_NAMES light, pname, params
#define glGetLightfv_ARG_EXPAND GLenum light, GLenum pname, GLfloat * params
#define glGetLightfv_PACKED PACKED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetLightfv_INDEXED INDEXED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetLightfv_FORMAT FORMAT_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetLightxv_INDEX 77
#define glGetLightxv_RETURN void
#define glGetLightxv_ARG_NAMES light, pname, params
#define glGetLightxv_ARG_EXPAND GLenum light, GLenum pname, GLfixed * params
#define glGetLightxv_PACKED PACKED_void_GLenum_GLenum_GLfixed___GENPT__
#define glGetLightxv_INDEXED INDEXED_void_GLenum_GLenum_GLfixed___GENPT__
#define glGetLightxv_FORMAT FORMAT_void_GLenum_GLenum_GLfixed___GENPT__
#define glGetMaterialfv_INDEX 78
#define glGetMaterialfv_RETURN void
#define glGetMaterialfv_ARG_NAMES face, pname, params
#define glGetMaterialfv_ARG_EXPAND GLenum face, GLenum pname, GLfloat * params
#define glGetMaterialfv_PACKED PACKED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetMaterialfv_INDEXED INDEXED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetMaterialfv_FORMAT FORMAT_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetMaterialxv_INDEX 79
#define glGetMaterialxv_RETURN void
#define glGetMaterialxv_ARG_NAMES face, pname, params
#define glGetMaterialxv_ARG_EXPAND GLenum face, GLenum pname, GLfixed * params
#define glGetMaterialxv_PACKED PACKED_void_GLenum_GLenum_GLfixed___GENPT__
#define glGetMaterialxv_INDEXED INDEXED_void_GLenum_GLenum_GLfixed___GENPT__
#define glGetMaterialxv_FORMAT FORMAT_void_GLenum_GLenum_GLfixed___GENPT__
#define glGetPointerv_INDEX 80
#define glGetPointerv_RETURN void
#define glGetPointerv_ARG_NAMES pname, params
#define glGetPointerv_ARG_EXPAND GLenum pname, GLvoid ** params
#define glGetPointerv_PACKED PACKED_void_GLenum_GLvoid___GENPT____GENPT__
#define glGetPointerv_INDEXED INDEXED_void_GLenum_GLvoid___GENPT____GENPT__
#define glGetPointerv_FORMAT FORMAT_void_GLenum_GLvoid___GENPT____GENPT__
#define glGetRenderbufferParameteriv_INDEX 81
#define glGetRenderbufferParameteriv_RETURN void
#define glGetRenderbufferParameteriv_ARG_NAMES target, pname, params
#define glGetRenderbufferParameteriv_ARG_EXPAND GLenum target, GLenum pname, GLint * params
#define glGetRenderbufferParameteriv_PACKED PACKED_void_GLenum_GLenum_GLint___GENPT__
#define glGetRenderbufferParameteriv_INDEXED INDEXED_void_GLenum_GLenum_GLint___GENPT__
#define glGetRenderbufferParameteriv_FORMAT FORMAT_void_GLenum_GLenum_GLint___GENPT__
#define glGetString_INDEX 82
#define glGetString_RETURN const GLubyte *
#define glGetString_ARG_NAMES name
#define glGetString_ARG_EXPAND GLenum name
#define glGetString_PACKED PACKED_const_GLubyte___GENPT___GLenum
#define glGetString_INDEXED INDEXED_const_GLubyte___GENPT___GLenum
#define glGetString_FORMAT FORMAT_const_GLubyte___GENPT___GLenum
#define glGetTexEnvfv_INDEX 83
#define glGetTexEnvfv_RETURN void
#define glGetTexEnvfv_ARG_NAMES target, pname, params
#define glGetTexEnvfv_ARG_EXPAND GLenum target, GLenum pname, GLfloat * params
#define glGetTexEnvfv_PACKED PACKED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetTexEnvfv_INDEXED INDEXED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetTexEnvfv_FORMAT FORMAT_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetTexEnviv_INDEX 84
#define glGetTexEnviv_RETURN void
#define glGetTexEnviv_ARG_NAMES target, pname, params
#define glGetTexEnviv_ARG_EXPAND GLenum target, GLenum pname, GLint * params
#define glGetTexEnviv_PACKED PACKED_void_GLenum_GLenum_GLint___GENPT__
#define glGetTexEnviv_INDEXED INDEXED_void_GLenum_GLenum_GLint___GENPT__
#define glGetTexEnviv_FORMAT FORMAT_void_GLenum_GLenum_GLint___GENPT__
#define glGetTexEnvxv_INDEX 85
#define glGetTexEnvxv_RETURN void
#define glGetTexEnvxv_ARG_NAMES target, pname, params
#define glGetTexEnvxv_ARG_EXPAND GLenum target, GLenum pname, GLfixed * params
#define glGetTexEnvxv_PACKED PACKED_void_GLenum_GLenum_GLfixed___GENPT__
#define glGetTexEnvxv_INDEXED INDEXED_void_GLenum_GLenum_GLfixed___GENPT__
#define glGetTexEnvxv_FORMAT FORMAT_void_GLenum_GLenum_GLfixed___GENPT__
#define glGetTexParameterfv_INDEX 86
#define glGetTexParameterfv_RETURN void
#define glGetTexParameterfv_ARG_NAMES target, pname, params
#define glGetTexParameterfv_ARG_EXPAND GLenum target, GLenum pname, GLfloat * params
#define glGetTexParameterfv_PACKED PACKED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetTexParameterfv_INDEXED INDEXED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetTexParameterfv_FORMAT FORMAT_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetTexParameteriv_INDEX 87
#define glGetTexParameteriv_RETURN void
#define glGetTexParameteriv_ARG_NAMES target, pname, params
#define glGetTexParameteriv_ARG_EXPAND GLenum target, GLenum pname, GLint * params
#define glGetTexParameteriv_PACKED PACKED_void_GLenum_GLenum_GLint___GENPT__
#define glGetTexParameteriv_INDEXED INDEXED_void_GLenum_GLenum_GLint___GENPT__
#define glGetTexParameteriv_FORMAT FORMAT_void_GLenum_GLenum_GLint___GENPT__
#define glGetTexParameterxv_INDEX 88
#define glGetTexParameterxv_RETURN void
#define glGetTexParameterxv_ARG_NAMES target, pname, params
#define glGetTexParameterxv_ARG_EXPAND GLenum target, GLenum pname, GLfixed * params
#define glGetTexParameterxv_PACKED PACKED_void_GLenum_GLenum_GLfixed___GENPT__
#define glGetTexParameterxv_INDEXED INDEXED_void_GLenum_GLenum_GLfixed___GENPT__
#define glGetTexParameterxv_FORMAT FORMAT_void_GLenum_GLenum_GLfixed___GENPT__
#define glHint_INDEX 89
#define glHint_RETURN void
#define glHint_ARG_NAMES target, mode
#define glHint_ARG_EXPAND GLenum target, GLenum mode
#define glHint_PACKED PACKED_void_GLenum_GLenum
#define glHint_INDEXED INDEXED_void_GLenum_GLenum
#define glHint_FORMAT FORMAT_void_GLenum_GLenum
#define glIsBuffer_INDEX 90
#define glIsBuffer_RETURN GLboolean
#define glIsBuffer_ARG_NAMES buffer
#define glIsBuffer_ARG_EXPAND GLuint buffer
#define glIsBuffer_PACKED PACKED_GLboolean_GLuint
#define glIsBuffer_INDEXED INDEXED_GLboolean_GLuint
#define glIsBuffer_FORMAT FORMAT_GLboolean_GLuint
#define glIsEnabled_INDEX 91
#define glIsEnabled_RETURN GLboolean
#define glIsEnabled_ARG_NAMES cap
#define glIsEnabled_ARG_EXPAND GLenum cap
#define glIsEnabled_PACKED PACKED_GLboolean_GLenum
#define glIsEnabled_INDEXED INDEXED_GLboolean_GLenum
#define glIsEnabled_FORMAT FORMAT_GLboolean_GLenum
#define glIsFramebuffer_INDEX 92
#define glIsFramebuffer_RETURN GLboolean
#define glIsFramebuffer_ARG_NAMES framebuffer
#define glIsFramebuffer_ARG_EXPAND GLuint framebuffer
#define glIsFramebuffer_PACKED PACKED_GLboolean_GLuint
#define glIsFramebuffer_INDEXED INDEXED_GLboolean_GLuint
#define glIsFramebuffer_FORMAT FORMAT_GLboolean_GLuint
#define glIsRenderbuffer_INDEX 93
#define glIsRenderbuffer_RETURN GLboolean
#define glIsRenderbuffer_ARG_NAMES renderbuffer
#define glIsRenderbuffer_ARG_EXPAND GLuint renderbuffer
#define glIsRenderbuffer_PACKED PACKED_GLboolean_GLuint
#define glIsRenderbuffer_INDEXED INDEXED_GLboolean_GLuint
#define glIsRenderbuffer_FORMAT FORMAT_GLboolean_GLuint
#define glIsTexture_INDEX 94
#define glIsTexture_RETURN GLboolean
#define glIsTexture_ARG_NAMES texture
#define glIsTexture_ARG_EXPAND GLuint texture
#define glIsTexture_PACKED PACKED_GLboolean_GLuint
#define glIsTexture_INDEXED INDEXED_GLboolean_GLuint
#define glIsTexture_FORMAT FORMAT_GLboolean_GLuint
#define glLightModelf_INDEX 95
#define glLightModelf_RETURN void
#define glLightModelf_ARG_NAMES pname, param
#define glLightModelf_ARG_EXPAND GLenum pname, GLfloat param
#define glLightModelf_PACKED PACKED_void_GLenum_GLfloat
#define glLightModelf_INDEXED INDEXED_void_GLenum_GLfloat
#define glLightModelf_FORMAT FORMAT_void_GLenum_GLfloat
#define glLightModelfv_INDEX 96
#define glLightModelfv_RETURN void
#define glLightModelfv_ARG_NAMES pname, params
#define glLightModelfv_ARG_EXPAND GLenum pname, const GLfloat * params
#define glLightModelfv_PACKED PACKED_void_GLenum_const_GLfloat___GENPT__
#define glLightModelfv_INDEXED INDEXED_void_GLenum_const_GLfloat___GENPT__
#define glLightModelfv_FORMAT FORMAT_void_GLenum_const_GLfloat___GENPT__
#define glLightModelx_INDEX 97
#define glLightModelx_RETURN void
#define glLightModelx_ARG_NAMES pname, param
#define glLightModelx_ARG_EXPAND GLenum pname, GLfixed param
#define glLightModelx_PACKED PACKED_void_GLenum_GLfixed
#define glLightModelx_INDEXED INDEXED_void_GLenum_GLfixed
#define glLightModelx_FORMAT FORMAT_void_GLenum_GLfixed
#define glLightModelxv_INDEX 98
#define glLightModelxv_RETURN void
#define glLightModelxv_ARG_NAMES pname, params
#define glLightModelxv_ARG_EXPAND GLenum pname, const GLfixed * params
#define glLightModelxv_PACKED PACKED_void_GLenum_const_GLfixed___GENPT__
#define glLightModelxv_INDEXED INDEXED_void_GLenum_const_GLfixed___GENPT__
#define glLightModelxv_FORMAT FORMAT_void_GLenum_const_GLfixed___GENPT__
#define glLightf_INDEX 99
#define glLightf_RETURN void
#define glLightf_ARG_NAMES light, pname, param
#define glLightf_ARG_EXPAND GLenum light, GLenum pname, GLfloat param
#define glLightf_PACKED PACKED_void_GLenum_GLenum_GLfloat
#define glLightf_INDEXED INDEXED_void_GLenum_GLenum_GLfloat
#define glLightf_FORMAT FORMAT_void_GLenum_GLenum_GLfloat
#define glLightfv_INDEX 100
#define glLightfv_RETURN void
#define glLightfv_ARG_NAMES light, pname, params
#define glLightfv_ARG_EXPAND GLenum light, GLenum pname, const GLfloat * params
#define glLightfv_PACKED PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glLightfv_INDEXED INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glLightfv_FORMAT FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glLightx_INDEX 101
#define glLightx_RETURN void
#define glLightx_ARG_NAMES light, pname, param
#define glLightx_ARG_EXPAND GLenum light, GLenum pname, GLfixed param
#define glLightx_PACKED PACKED_void_GLenum_GLenum_GLfixed
#define glLightx_INDEXED INDEXED_void_GLenum_GLenum_GLfixed
#define glLightx_FORMAT FORMAT_void_GLenum_GLenum_GLfixed
#define glLightxv_INDEX 102
#define glLightxv_RETURN void
#define glLightxv_ARG_NAMES light, pname, params
#define glLightxv_ARG_EXPAND GLenum light, GLenum pname, const GLfixed * params
#define glLightxv_PACKED PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__
#define glLightxv_INDEXED INDEXED_void_GLenum_GLenum_const_GLfixed___GENPT__
#define glLightxv_FORMAT FORMAT_void_GLenum_GLenum_const_GLfixed___GENPT__
#define glLineWidth_INDEX 103
#define glLineWidth_RETURN void
#define glLineWidth_ARG_NAMES width
#define glLineWidth_ARG_EXPAND GLfloat width
#define glLineWidth_PACKED PACKED_void_GLfloat
#define glLineWidth_INDEXED INDEXED_void_GLfloat
#define glLineWidth_FORMAT FORMAT_void_GLfloat
#define glLineWidthx_INDEX 104
#define glLineWidthx_RETURN void
#define glLineWidthx_ARG_NAMES width
#define glLineWidthx_ARG_EXPAND GLfixed width
#define glLineWidthx_PACKED PACKED_void_GLfixed
#define glLineWidthx_INDEXED INDEXED_void_GLfixed
#define glLineWidthx_FORMAT FORMAT_void_GLfixed
#define glLoadIdentity_INDEX 105
#define glLoadIdentity_RETURN void
#define glLoadIdentity_ARG_NAMES 
#define glLoadIdentity_ARG_EXPAND 
#define glLoadIdentity_PACKED PACKED_void
#define glLoadIdentity_INDEXED INDEXED_void
#define glLoadIdentity_FORMAT FORMAT_void
#define glLoadMatrixf_INDEX 106
#define glLoadMatrixf_RETURN void
#define glLoadMatrixf_ARG_NAMES m
#define glLoadMatrixf_ARG_EXPAND const GLfloat * m
#define glLoadMatrixf_PACKED PACKED_void_const_GLfloat___GENPT__
#define glLoadMatrixf_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glLoadMatrixf_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glLoadMatrixx_INDEX 107
#define glLoadMatrixx_RETURN void
#define glLoadMatrixx_ARG_NAMES m
#define glLoadMatrixx_ARG_EXPAND const GLfixed * m
#define glLoadMatrixx_PACKED PACKED_void_const_GLfixed___GENPT__
#define glLoadMatrixx_INDEXED INDEXED_void_const_GLfixed___GENPT__
#define glLoadMatrixx_FORMAT FORMAT_void_const_GLfixed___GENPT__
#define glLogicOp_INDEX 108
#define glLogicOp_RETURN void
#define glLogicOp_ARG_NAMES opcode
#define glLogicOp_ARG_EXPAND GLenum opcode
#define glLogicOp_PACKED PACKED_void_GLenum
#define glLogicOp_INDEXED INDEXED_void_GLenum
#define glLogicOp_FORMAT FORMAT_void_GLenum
#define glMaterialf_INDEX 109
#define glMaterialf_RETURN void
#define glMaterialf_ARG_NAMES face, pname, param
#define glMaterialf_ARG_EXPAND GLenum face, GLenum pname, GLfloat param
#define glMaterialf_PACKED PACKED_void_GLenum_GLenum_GLfloat
#define glMaterialf_INDEXED INDEXED_void_GLenum_GLenum_GLfloat
#define glMaterialf_FORMAT FORMAT_void_GLenum_GLenum_GLfloat
#define glMaterialfv_INDEX 110
#define glMaterialfv_RETURN void
#define glMaterialfv_ARG_NAMES face, pname, params
#define glMaterialfv_ARG_EXPAND GLenum face, GLenum pname, const GLfloat * params
#define glMaterialfv_PACKED PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glMaterialfv_INDEXED INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glMaterialfv_FORMAT FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glMaterialx_INDEX 111
#define glMaterialx_RETURN void
#define glMaterialx_ARG_NAMES face, pname, param
#define glMaterialx_ARG_EXPAND GLenum face, GLenum pname, GLfixed param
#define glMaterialx_PACKED PACKED_void_GLenum_GLenum_GLfixed
#define glMaterialx_INDEXED INDEXED_void_GLenum_GLenum_GLfixed
#define glMaterialx_FORMAT FORMAT_void_GLenum_GLenum_GLfixed
#define glMaterialxv_INDEX 112
#define glMaterialxv_RETURN void
#define glMaterialxv_ARG_NAMES face, pname, params
#define glMaterialxv_ARG_EXPAND GLenum face, GLenum pname, const GLfixed * params
#define glMaterialxv_PACKED PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__
#define glMaterialxv_INDEXED INDEXED_void_GLenum_GLenum_const_GLfixed___GENPT__
#define glMaterialxv_FORMAT FORMAT_void_GLenum_GLenum_const_GLfixed___GENPT__
#define glMatrixMode_INDEX 113
#define glMatrixMode_RETURN void
#define glMatrixMode_ARG_NAMES mode
#define glMatrixMode_ARG_EXPAND GLenum mode
#define glMatrixMode_PACKED PACKED_void_GLenum
#define glMatrixMode_INDEXED INDEXED_void_GLenum
#define glMatrixMode_FORMAT FORMAT_void_GLenum
#define glMultMatrixf_INDEX 114
#define glMultMatrixf_RETURN void
#define glMultMatrixf_ARG_NAMES m
#define glMultMatrixf_ARG_EXPAND const GLfloat * m
#define glMultMatrixf_PACKED PACKED_void_const_GLfloat___GENPT__
#define glMultMatrixf_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glMultMatrixf_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glMultMatrixx_INDEX 115
#define glMultMatrixx_RETURN void
#define glMultMatrixx_ARG_NAMES m
#define glMultMatrixx_ARG_EXPAND const GLfixed * m
#define glMultMatrixx_PACKED PACKED_void_const_GLfixed___GENPT__
#define glMultMatrixx_INDEXED INDEXED_void_const_GLfixed___GENPT__
#define glMultMatrixx_FORMAT FORMAT_void_const_GLfixed___GENPT__
#define glMultiTexCoord4f_INDEX 116
#define glMultiTexCoord4f_RETURN void
#define glMultiTexCoord4f_ARG_NAMES target, s, t, r, q
#define glMultiTexCoord4f_ARG_EXPAND GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q
#define glMultiTexCoord4f_PACKED PACKED_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat
#define glMultiTexCoord4f_INDEXED INDEXED_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat
#define glMultiTexCoord4f_FORMAT FORMAT_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat
#define glMultiTexCoord4x_INDEX 117
#define glMultiTexCoord4x_RETURN void
#define glMultiTexCoord4x_ARG_NAMES target, s, t, r, q
#define glMultiTexCoord4x_ARG_EXPAND GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q
#define glMultiTexCoord4x_PACKED PACKED_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed
#define glMultiTexCoord4x_INDEXED INDEXED_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed
#define glMultiTexCoord4x_FORMAT FORMAT_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed
#define glNormal3f_INDEX 118
#define glNormal3f_RETURN void
#define glNormal3f_ARG_NAMES nx, ny, nz
#define glNormal3f_ARG_EXPAND GLfloat nx, GLfloat ny, GLfloat nz
#define glNormal3f_PACKED PACKED_void_GLfloat_GLfloat_GLfloat
#define glNormal3f_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat
#define glNormal3f_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat
#define glNormal3x_INDEX 119
#define glNormal3x_RETURN void
#define glNormal3x_ARG_NAMES nx, ny, nz
#define glNormal3x_ARG_EXPAND GLfixed nx, GLfixed ny, GLfixed nz
#define glNormal3x_PACKED PACKED_void_GLfixed_GLfixed_GLfixed
#define glNormal3x_INDEXED INDEXED_void_GLfixed_GLfixed_GLfixed
#define glNormal3x_FORMAT FORMAT_void_GLfixed_GLfixed_GLfixed
#define glNormalPointer_INDEX 120
#define glNormalPointer_RETURN void
#define glNormalPointer_ARG_NAMES type, stride, pointer
#define glNormalPointer_ARG_EXPAND GLenum type, GLsizei stride, const GLvoid * pointer
#define glNormalPointer_PACKED PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__
#define glNormalPointer_INDEXED INDEXED_void_GLenum_GLsizei_const_GLvoid___GENPT__
#define glNormalPointer_FORMAT FORMAT_void_GLenum_GLsizei_const_GLvoid___GENPT__
#define glOrthof_INDEX 121
#define glOrthof_RETURN void
#define glOrthof_ARG_NAMES left, right, bottom, top, near, far
#define glOrthof_ARG_EXPAND GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far
#define glOrthof_PACKED PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat
#define glOrthof_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat
#define glOrthof_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat
#define glOrthox_INDEX 122
#define glOrthox_RETURN void
#define glOrthox_ARG_NAMES left, right, bottom, top, near, far
#define glOrthox_ARG_EXPAND GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far
#define glOrthox_PACKED PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed
#define glOrthox_INDEXED INDEXED_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed
#define glOrthox_FORMAT FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed
#define glPixelStorei_INDEX 123
#define glPixelStorei_RETURN void
#define glPixelStorei_ARG_NAMES pname, param
#define glPixelStorei_ARG_EXPAND GLenum pname, GLint param
#define glPixelStorei_PACKED PACKED_void_GLenum_GLint
#define glPixelStorei_INDEXED INDEXED_void_GLenum_GLint
#define glPixelStorei_FORMAT FORMAT_void_GLenum_GLint
#define glPointParameterf_INDEX 124
#define glPointParameterf_RETURN void
#define glPointParameterf_ARG_NAMES pname, param
#define glPointParameterf_ARG_EXPAND GLenum pname, GLfloat param
#define glPointParameterf_PACKED PACKED_void_GLenum_GLfloat
#define glPointParameterf_INDEXED INDEXED_void_GLenum_GLfloat
#define glPointParameterf_FORMAT FORMAT_void_GLenum_GLfloat
#define glPointParameterfv_INDEX 125
#define glPointParameterfv_RETURN void
#define glPointParameterfv_ARG_NAMES pname, params
#define glPointParameterfv_ARG_EXPAND GLenum pname, const GLfloat * params
#define glPointParameterfv_PACKED PACKED_void_GLenum_const_GLfloat___GENPT__
#define glPointParameterfv_INDEXED INDEXED_void_GLenum_const_GLfloat___GENPT__
#define glPointParameterfv_FORMAT FORMAT_void_GLenum_const_GLfloat___GENPT__
#define glPointParameterx_INDEX 126
#define glPointParameterx_RETURN void
#define glPointParameterx_ARG_NAMES pname, param
#define glPointParameterx_ARG_EXPAND GLenum pname, GLfixed param
#define glPointParameterx_PACKED PACKED_void_GLenum_GLfixed
#define glPointParameterx_INDEXED INDEXED_void_GLenum_GLfixed
#define glPointParameterx_FORMAT FORMAT_void_GLenum_GLfixed
#define glPointParameterxv_INDEX 127
#define glPointParameterxv_RETURN void
#define glPointParameterxv_ARG_NAMES pname, params
#define glPointParameterxv_ARG_EXPAND GLenum pname, const GLfixed * params
#define glPointParameterxv_PACKED PACKED_void_GLenum_const_GLfixed___GENPT__
#define glPointParameterxv_INDEXED INDEXED_void_GLenum_const_GLfixed___GENPT__
#define glPointParameterxv_FORMAT FORMAT_void_GLenum_const_GLfixed___GENPT__
#define glPointSize_INDEX 128
#define glPointSize_RETURN void
#define glPointSize_ARG_NAMES size
#define glPointSize_ARG_EXPAND GLfloat size
#define glPointSize_PACKED PACKED_void_GLfloat
#define glPointSize_INDEXED INDEXED_void_GLfloat
#define glPointSize_FORMAT FORMAT_void_GLfloat
#define glPointSizePointerOES_INDEX 129
#define glPointSizePointerOES_RETURN void
#define glPointSizePointerOES_ARG_NAMES type, stride, pointer
#define glPointSizePointerOES_ARG_EXPAND GLenum type, GLsizei stride, const GLvoid * pointer
#define glPointSizePointerOES_PACKED PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__
#define glPointSizePointerOES_INDEXED INDEXED_void_GLenum_GLsizei_const_GLvoid___GENPT__
#define glPointSizePointerOES_FORMAT FORMAT_void_GLenum_GLsizei_const_GLvoid___GENPT__
#define glPointSizex_INDEX 130
#define glPointSizex_RETURN void
#define glPointSizex_ARG_NAMES size
#define glPointSizex_ARG_EXPAND GLfixed size
#define glPointSizex_PACKED PACKED_void_GLfixed
#define glPointSizex_INDEXED INDEXED_void_GLfixed
#define glPointSizex_FORMAT FORMAT_void_GLfixed
#define glPolygonOffset_INDEX 131
#define glPolygonOffset_RETURN void
#define glPolygonOffset_ARG_NAMES factor, units
#define glPolygonOffset_ARG_EXPAND GLfloat factor, GLfloat units
#define glPolygonOffset_PACKED PACKED_void_GLfloat_GLfloat
#define glPolygonOffset_INDEXED INDEXED_void_GLfloat_GLfloat
#define glPolygonOffset_FORMAT FORMAT_void_GLfloat_GLfloat
#define glPolygonOffsetx_INDEX 132
#define glPolygonOffsetx_RETURN void
#define glPolygonOffsetx_ARG_NAMES factor, units
#define glPolygonOffsetx_ARG_EXPAND GLfixed factor, GLfixed units
#define glPolygonOffsetx_PACKED PACKED_void_GLfixed_GLfixed
#define glPolygonOffsetx_INDEXED INDEXED_void_GLfixed_GLfixed
#define glPolygonOffsetx_FORMAT FORMAT_void_GLfixed_GLfixed
#define glPopMatrix_INDEX 133
#define glPopMatrix_RETURN void
#define glPopMatrix_ARG_NAMES 
#define glPopMatrix_ARG_EXPAND 
#define glPopMatrix_PACKED PACKED_void
#define glPopMatrix_INDEXED INDEXED_void
#define glPopMatrix_FORMAT FORMAT_void
#define glPushMatrix_INDEX 134
#define glPushMatrix_RETURN void
#define glPushMatrix_ARG_NAMES 
#define glPushMatrix_ARG_EXPAND 
#define glPushMatrix_PACKED PACKED_void
#define glPushMatrix_INDEXED INDEXED_void
#define glPushMatrix_FORMAT FORMAT_void
#define glReadPixels_INDEX 135
#define glReadPixels_RETURN void
#define glReadPixels_ARG_NAMES x, y, width, height, format, type, pixels
#define glReadPixels_ARG_EXPAND GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels
#define glReadPixels_PACKED PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__
#define glReadPixels_INDEXED INDEXED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__
#define glReadPixels_FORMAT FORMAT_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__
#define glRenderbufferStorage_INDEX 136
#define glRenderbufferStorage_RETURN void
#define glRenderbufferStorage_ARG_NAMES target, internalformat, width, height
#define glRenderbufferStorage_ARG_EXPAND GLenum target, GLenum internalformat, GLsizei width, GLsizei height
#define glRenderbufferStorage_PACKED PACKED_void_GLenum_GLenum_GLsizei_GLsizei
#define glRenderbufferStorage_INDEXED INDEXED_void_GLenum_GLenum_GLsizei_GLsizei
#define glRenderbufferStorage_FORMAT FORMAT_void_GLenum_GLenum_GLsizei_GLsizei
#define glRotatef_INDEX 137
#define glRotatef_RETURN void
#define glRotatef_ARG_NAMES angle, x, y, z
#define glRotatef_ARG_EXPAND GLfloat angle, GLfloat x, GLfloat y, GLfloat z
#define glRotatef_PACKED PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glRotatef_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glRotatef_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glRotatex_INDEX 138
#define glRotatex_RETURN void
#define glRotatex_ARG_NAMES angle, x, y, z
#define glRotatex_ARG_EXPAND GLfixed angle, GLfixed x, GLfixed y, GLfixed z
#define glRotatex_PACKED PACKED_void_GLfixed_GLfixed_GLfixed_GLfixed
#define glRotatex_INDEXED INDEXED_void_GLfixed_GLfixed_GLfixed_GLfixed
#define glRotatex_FORMAT FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed
#define glSampleCoverage_INDEX 139
#define glSampleCoverage_RETURN void
#define glSampleCoverage_ARG_NAMES value, invert
#define glSampleCoverage_ARG_EXPAND GLclampf value, GLboolean invert
#define glSampleCoverage_PACKED PACKED_void_GLclampf_GLboolean
#define glSampleCoverage_INDEXED INDEXED_void_GLclampf_GLboolean
#define glSampleCoverage_FORMAT FORMAT_void_GLclampf_GLboolean
#define glSampleCoveragex_INDEX 140
#define glSampleCoveragex_RETURN void
#define glSampleCoveragex_ARG_NAMES value, invert
#define glSampleCoveragex_ARG_EXPAND GLclampx value, GLboolean invert
#define glSampleCoveragex_PACKED PACKED_void_GLclampx_GLboolean
#define glSampleCoveragex_INDEXED INDEXED_void_GLclampx_GLboolean
#define glSampleCoveragex_FORMAT FORMAT_void_GLclampx_GLboolean
#define glScalef_INDEX 141
#define glScalef_RETURN void
#define glScalef_ARG_NAMES x, y, z
#define glScalef_ARG_EXPAND GLfloat x, GLfloat y, GLfloat z
#define glScalef_PACKED PACKED_void_GLfloat_GLfloat_GLfloat
#define glScalef_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat
#define glScalef_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat
#define glScalex_INDEX 142
#define glScalex_RETURN void
#define glScalex_ARG_NAMES x, y, z
#define glScalex_ARG_EXPAND GLfixed x, GLfixed y, GLfixed z
#define glScalex_PACKED PACKED_void_GLfixed_GLfixed_GLfixed
#define glScalex_INDEXED INDEXED_void_GLfixed_GLfixed_GLfixed
#define glScalex_FORMAT FORMAT_void_GLfixed_GLfixed_GLfixed
#define glScissor_INDEX 143
#define glScissor_RETURN void
#define glScissor_ARG_NAMES x, y, width, height
#define glScissor_ARG_EXPAND GLint x, GLint y, GLsizei width, GLsizei height
#define glScissor_PACKED PACKED_void_GLint_GLint_GLsizei_GLsizei
#define glScissor_INDEXED INDEXED_void_GLint_GLint_GLsizei_GLsizei
#define glScissor_FORMAT FORMAT_void_GLint_GLint_GLsizei_GLsizei
#define glShadeModel_INDEX 144
#define glShadeModel_RETURN void
#define glShadeModel_ARG_NAMES mode
#define glShadeModel_ARG_EXPAND GLenum mode
#define glShadeModel_PACKED PACKED_void_GLenum
#define glShadeModel_INDEXED INDEXED_void_GLenum
#define glShadeModel_FORMAT FORMAT_void_GLenum
#define glStencilFunc_INDEX 145
#define glStencilFunc_RETURN void
#define glStencilFunc_ARG_NAMES func, ref, mask
#define glStencilFunc_ARG_EXPAND GLenum func, GLint ref, GLuint mask
#define glStencilFunc_PACKED PACKED_void_GLenum_GLint_GLuint
#define glStencilFunc_INDEXED INDEXED_void_GLenum_GLint_GLuint
#define glStencilFunc_FORMAT FORMAT_void_GLenum_GLint_GLuint
#define glStencilMask_INDEX 146
#define glStencilMask_RETURN void
#define glStencilMask_ARG_NAMES mask
#define glStencilMask_ARG_EXPAND GLuint mask
#define glStencilMask_PACKED PACKED_void_GLuint
#define glStencilMask_INDEXED INDEXED_void_GLuint
#define glStencilMask_FORMAT FORMAT_void_GLuint
#define glStencilOp_INDEX 147
#define glStencilOp_RETURN void
#define glStencilOp_ARG_NAMES fail, zfail, zpass
#define glStencilOp_ARG_EXPAND GLenum fail, GLenum zfail, GLenum zpass
#define glStencilOp_PACKED PACKED_void_GLenum_GLenum_GLenum
#define glStencilOp_INDEXED INDEXED_void_GLenum_GLenum_GLenum
#define glStencilOp_FORMAT FORMAT_void_GLenum_GLenum_GLenum
#define glTexCoordPointer_INDEX 148
#define glTexCoordPointer_RETURN void
#define glTexCoordPointer_ARG_NAMES size, type, stride, pointer
#define glTexCoordPointer_ARG_EXPAND GLint size, GLenum type, GLsizei stride, const GLvoid * pointer
#define glTexCoordPointer_PACKED PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__
#define glTexCoordPointer_INDEXED INDEXED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__
#define glTexCoordPointer_FORMAT FORMAT_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__
#define glTexEnvf_INDEX 149
#define glTexEnvf_RETURN void
#define glTexEnvf_ARG_NAMES target, pname, param
#define glTexEnvf_ARG_EXPAND GLenum target, GLenum pname, GLfloat param
#define glTexEnvf_PACKED PACKED_void_GLenum_GLenum_GLfloat
#define glTexEnvf_INDEXED INDEXED_void_GLenum_GLenum_GLfloat
#define glTexEnvf_FORMAT FORMAT_void_GLenum_GLenum_GLfloat
#define glTexEnvfv_INDEX 150
#define glTexEnvfv_RETURN void
#define glTexEnvfv_ARG_NAMES target, pname, params
#define glTexEnvfv_ARG_EXPAND GLenum target, GLenum pname, const GLfloat * params
#define glTexEnvfv_PACKED PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glTexEnvfv_INDEXED INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glTexEnvfv_FORMAT FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glTexEnvi_INDEX 151
#define glTexEnvi_RETURN void
#define glTexEnvi_ARG_NAMES target, pname, param
#define glTexEnvi_ARG_EXPAND GLenum target, GLenum pname, GLint param
#define glTexEnvi_PACKED PACKED_void_GLenum_GLenum_GLint
#define glTexEnvi_INDEXED INDEXED_void_GLenum_GLenum_GLint
#define glTexEnvi_FORMAT FORMAT_void_GLenum_GLenum_GLint
#define glTexEnviv_INDEX 152
#define glTexEnviv_RETURN void
#define glTexEnviv_ARG_NAMES target, pname, params
#define glTexEnviv_ARG_EXPAND GLenum target, GLenum pname, const GLint * params
#define glTexEnviv_PACKED PACKED_void_GLenum_GLenum_const_GLint___GENPT__
#define glTexEnviv_INDEXED INDEXED_void_GLenum_GLenum_const_GLint___GENPT__
#define glTexEnviv_FORMAT FORMAT_void_GLenum_GLenum_const_GLint___GENPT__
#define glTexEnvx_INDEX 153
#define glTexEnvx_RETURN void
#define glTexEnvx_ARG_NAMES target, pname, param
#define glTexEnvx_ARG_EXPAND GLenum target, GLenum pname, GLfixed param
#define glTexEnvx_PACKED PACKED_void_GLenum_GLenum_GLfixed
#define glTexEnvx_INDEXED INDEXED_void_GLenum_GLenum_GLfixed
#define glTexEnvx_FORMAT FORMAT_void_GLenum_GLenum_GLfixed
#define glTexEnvxv_INDEX 154
#define glTexEnvxv_RETURN void
#define glTexEnvxv_ARG_NAMES target, pname, params
#define glTexEnvxv_ARG_EXPAND GLenum target, GLenum pname, const GLfixed * params
#define glTexEnvxv_PACKED PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__
#define glTexEnvxv_INDEXED INDEXED_void_GLenum_GLenum_const_GLfixed___GENPT__
#define glTexEnvxv_FORMAT FORMAT_void_GLenum_GLenum_const_GLfixed___GENPT__
#define glTexGenfv_INDEX 155
#define glTexGenfv_RETURN void
#define glTexGenfv_ARG_NAMES coord, pname, params
#define glTexGenfv_ARG_EXPAND GLenum coord, GLenum pname, const GLfloat * params
#define glTexGenfv_PACKED PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glTexGenfv_INDEXED INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glTexGenfv_FORMAT FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glTexGeni_INDEX 156
#define glTexGeni_RETURN void
#define glTexGeni_ARG_NAMES coord, pname, param
#define glTexGeni_ARG_EXPAND GLenum coord, GLenum pname, GLint param
#define glTexGeni_PACKED PACKED_void_GLenum_GLenum_GLint
#define glTexGeni_INDEXED INDEXED_void_GLenum_GLenum_GLint
#define glTexGeni_FORMAT FORMAT_void_GLenum_GLenum_GLint
#define glTexImage2D_INDEX 157
#define glTexImage2D_RETURN void
#define glTexImage2D_ARG_NAMES target, level, internalformat, width, height, border, format, type, pixels
#define glTexImage2D_ARG_EXPAND GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels
#define glTexImage2D_PACKED PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__
#define glTexImage2D_INDEXED INDEXED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__
#define glTexImage2D_FORMAT FORMAT_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__
#define glTexParameterf_INDEX 158
#define glTexParameterf_RETURN void
#define glTexParameterf_ARG_NAMES target, pname, param
#define glTexParameterf_ARG_EXPAND GLenum target, GLenum pname, GLfloat param
#define glTexParameterf_PACKED PACKED_void_GLenum_GLenum_GLfloat
#define glTexParameterf_INDEXED INDEXED_void_GLenum_GLenum_GLfloat
#define glTexParameterf_FORMAT FORMAT_void_GLenum_GLenum_GLfloat
#define glTexParameterfv_INDEX 159
#define glTexParameterfv_RETURN void
#define glTexParameterfv_ARG_NAMES target, pname, params
#define glTexParameterfv_ARG_EXPAND GLenum target, GLenum pname, const GLfloat * params
#define glTexParameterfv_PACKED PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glTexParameterfv_INDEXED INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glTexParameterfv_FORMAT FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glTexParameteri_INDEX 160
#define glTexParameteri_RETURN void
#define glTexParameteri_ARG_NAMES target, pname, param
#define glTexParameteri_ARG_EXPAND GLenum target, GLenum pname, GLint param
#define glTexParameteri_PACKED PACKED_void_GLenum_GLenum_GLint
#define glTexParameteri_INDEXED INDEXED_void_GLenum_GLenum_GLint
#define glTexParameteri_FORMAT FORMAT_void_GLenum_GLenum_GLint
#define glTexParameteriv_INDEX 161
#define glTexParameteriv_RETURN void
#define glTexParameteriv_ARG_NAMES target, pname, params
#define glTexParameteriv_ARG_EXPAND GLenum target, GLenum pname, const GLint * params
#define glTexParameteriv_PACKED PACKED_void_GLenum_GLenum_const_GLint___GENPT__
#define glTexParameteriv_INDEXED INDEXED_void_GLenum_GLenum_const_GLint___GENPT__
#define glTexParameteriv_FORMAT FORMAT_void_GLenum_GLenum_const_GLint___GENPT__
#define glTexParameterx_INDEX 162
#define glTexParameterx_RETURN void
#define glTexParameterx_ARG_NAMES target, pname, param
#define glTexParameterx_ARG_EXPAND GLenum target, GLenum pname, GLfixed param
#define glTexParameterx_PACKED PACKED_void_GLenum_GLenum_GLfixed
#define glTexParameterx_INDEXED INDEXED_void_GLenum_GLenum_GLfixed
#define glTexParameterx_FORMAT FORMAT_void_GLenum_GLenum_GLfixed
#define glTexParameterxv_INDEX 163
#define glTexParameterxv_RETURN void
#define glTexParameterxv_ARG_NAMES target, pname, params
#define glTexParameterxv_ARG_EXPAND GLenum target, GLenum pname, const GLfixed * params
#define glTexParameterxv_PACKED PACKED_void_GLenum_GLenum_const_GLfixed___GENPT__
#define glTexParameterxv_INDEXED INDEXED_void_GLenum_GLenum_const_GLfixed___GENPT__
#define glTexParameterxv_FORMAT FORMAT_void_GLenum_GLenum_const_GLfixed___GENPT__
#define glTexSubImage2D_INDEX 164
#define glTexSubImage2D_RETURN void
#define glTexSubImage2D_ARG_NAMES target, level, xoffset, yoffset, width, height, format, type, pixels
#define glTexSubImage2D_ARG_EXPAND GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels
#define glTexSubImage2D_PACKED PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glTexSubImage2D_INDEXED INDEXED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glTexSubImage2D_FORMAT FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glTranslatef_INDEX 165
#define glTranslatef_RETURN void
#define glTranslatef_ARG_NAMES x, y, z
#define glTranslatef_ARG_EXPAND GLfloat x, GLfloat y, GLfloat z
#define glTranslatef_PACKED PACKED_void_GLfloat_GLfloat_GLfloat
#define glTranslatef_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat
#define glTranslatef_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat
#define glTranslatex_INDEX 166
#define glTranslatex_RETURN void
#define glTranslatex_ARG_NAMES x, y, z
#define glTranslatex_ARG_EXPAND GLfixed x, GLfixed y, GLfixed z
#define glTranslatex_PACKED PACKED_void_GLfixed_GLfixed_GLfixed
#define glTranslatex_INDEXED INDEXED_void_GLfixed_GLfixed_GLfixed
#define glTranslatex_FORMAT FORMAT_void_GLfixed_GLfixed_GLfixed
#define glVertexPointer_INDEX 167
#define glVertexPointer_RETURN void
#define glVertexPointer_ARG_NAMES size, type, stride, pointer
#define glVertexPointer_ARG_EXPAND GLint size, GLenum type, GLsizei stride, const GLvoid * pointer
#define glVertexPointer_PACKED PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__
#define glVertexPointer_INDEXED INDEXED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__
#define glVertexPointer_FORMAT FORMAT_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__
#define glViewport_INDEX 168
#define glViewport_RETURN void
#define glViewport_ARG_NAMES x, y, width, height
#define glViewport_ARG_EXPAND GLint x, GLint y, GLsizei width, GLsizei height
#define glViewport_PACKED PACKED_void_GLint_GLint_GLsizei_GLsizei
#define glViewport_INDEXED INDEXED_void_GLint_GLint_GLsizei_GLsizei
#define glViewport_FORMAT FORMAT_void_GLint_GLint_GLsizei_GLsizei

void glshim_glActiveTexture(glActiveTexture_ARG_EXPAND);
typedef void (*glActiveTexture_PTR)(glActiveTexture_ARG_EXPAND);
void glshim_glAlphaFunc(glAlphaFunc_ARG_EXPAND);
typedef void (*glAlphaFunc_PTR)(glAlphaFunc_ARG_EXPAND);
void glshim_glAlphaFuncx(glAlphaFuncx_ARG_EXPAND);
typedef void (*glAlphaFuncx_PTR)(glAlphaFuncx_ARG_EXPAND);
void glshim_glBindBuffer(glBindBuffer_ARG_EXPAND);
typedef void (*glBindBuffer_PTR)(glBindBuffer_ARG_EXPAND);
void glshim_glBindFramebuffer(glBindFramebuffer_ARG_EXPAND);
typedef void (*glBindFramebuffer_PTR)(glBindFramebuffer_ARG_EXPAND);
void glshim_glBindRenderbuffer(glBindRenderbuffer_ARG_EXPAND);
typedef void (*glBindRenderbuffer_PTR)(glBindRenderbuffer_ARG_EXPAND);
void glshim_glBindTexture(glBindTexture_ARG_EXPAND);
typedef void (*glBindTexture_PTR)(glBindTexture_ARG_EXPAND);
void glshim_glBlendColor(glBlendColor_ARG_EXPAND);
typedef void (*glBlendColor_PTR)(glBlendColor_ARG_EXPAND);
void glshim_glBlendEquation(glBlendEquation_ARG_EXPAND);
typedef void (*glBlendEquation_PTR)(glBlendEquation_ARG_EXPAND);
void glshim_glBlendEquationSeparate(glBlendEquationSeparate_ARG_EXPAND);
typedef void (*glBlendEquationSeparate_PTR)(glBlendEquationSeparate_ARG_EXPAND);
void glshim_glBlendFunc(glBlendFunc_ARG_EXPAND);
typedef void (*glBlendFunc_PTR)(glBlendFunc_ARG_EXPAND);
void glshim_glBlendFuncSeparate(glBlendFuncSeparate_ARG_EXPAND);
typedef void (*glBlendFuncSeparate_PTR)(glBlendFuncSeparate_ARG_EXPAND);
void glshim_glBufferData(glBufferData_ARG_EXPAND);
typedef void (*glBufferData_PTR)(glBufferData_ARG_EXPAND);
void glshim_glBufferSubData(glBufferSubData_ARG_EXPAND);
typedef void (*glBufferSubData_PTR)(glBufferSubData_ARG_EXPAND);
GLenum glshim_glCheckFramebufferStatus(glCheckFramebufferStatus_ARG_EXPAND);
typedef GLenum (*glCheckFramebufferStatus_PTR)(glCheckFramebufferStatus_ARG_EXPAND);
void glshim_glClear(glClear_ARG_EXPAND);
typedef void (*glClear_PTR)(glClear_ARG_EXPAND);
void glshim_glClearColor(glClearColor_ARG_EXPAND);
typedef void (*glClearColor_PTR)(glClearColor_ARG_EXPAND);
void glshim_glClearColorx(glClearColorx_ARG_EXPAND);
typedef void (*glClearColorx_PTR)(glClearColorx_ARG_EXPAND);
void glshim_glClearDepthf(glClearDepthf_ARG_EXPAND);
typedef void (*glClearDepthf_PTR)(glClearDepthf_ARG_EXPAND);
void glshim_glClearDepthx(glClearDepthx_ARG_EXPAND);
typedef void (*glClearDepthx_PTR)(glClearDepthx_ARG_EXPAND);
void glshim_glClearStencil(glClearStencil_ARG_EXPAND);
typedef void (*glClearStencil_PTR)(glClearStencil_ARG_EXPAND);
void glshim_glClientActiveTexture(glClientActiveTexture_ARG_EXPAND);
typedef void (*glClientActiveTexture_PTR)(glClientActiveTexture_ARG_EXPAND);
void glshim_glClipPlanef(glClipPlanef_ARG_EXPAND);
typedef void (*glClipPlanef_PTR)(glClipPlanef_ARG_EXPAND);
void glshim_glClipPlanex(glClipPlanex_ARG_EXPAND);
typedef void (*glClipPlanex_PTR)(glClipPlanex_ARG_EXPAND);
void glshim_glColor4f(glColor4f_ARG_EXPAND);
typedef void (*glColor4f_PTR)(glColor4f_ARG_EXPAND);
void glshim_glColor4ub(glColor4ub_ARG_EXPAND);
typedef void (*glColor4ub_PTR)(glColor4ub_ARG_EXPAND);
void glshim_glColor4x(glColor4x_ARG_EXPAND);
typedef void (*glColor4x_PTR)(glColor4x_ARG_EXPAND);
void glshim_glColorMask(glColorMask_ARG_EXPAND);
typedef void (*glColorMask_PTR)(glColorMask_ARG_EXPAND);
void glshim_glColorPointer(glColorPointer_ARG_EXPAND);
typedef void (*glColorPointer_PTR)(glColorPointer_ARG_EXPAND);
void glshim_glCompressedTexImage2D(glCompressedTexImage2D_ARG_EXPAND);
typedef void (*glCompressedTexImage2D_PTR)(glCompressedTexImage2D_ARG_EXPAND);
void glshim_glCompressedTexSubImage2D(glCompressedTexSubImage2D_ARG_EXPAND);
typedef void (*glCompressedTexSubImage2D_PTR)(glCompressedTexSubImage2D_ARG_EXPAND);
void glshim_glCopyTexImage2D(glCopyTexImage2D_ARG_EXPAND);
typedef void (*glCopyTexImage2D_PTR)(glCopyTexImage2D_ARG_EXPAND);
void glshim_glCopyTexSubImage2D(glCopyTexSubImage2D_ARG_EXPAND);
typedef void (*glCopyTexSubImage2D_PTR)(glCopyTexSubImage2D_ARG_EXPAND);
void glshim_glCullFace(glCullFace_ARG_EXPAND);
typedef void (*glCullFace_PTR)(glCullFace_ARG_EXPAND);
void glshim_glDeleteBuffers(glDeleteBuffers_ARG_EXPAND);
typedef void (*glDeleteBuffers_PTR)(glDeleteBuffers_ARG_EXPAND);
void glshim_glDeleteFramebuffers(glDeleteFramebuffers_ARG_EXPAND);
typedef void (*glDeleteFramebuffers_PTR)(glDeleteFramebuffers_ARG_EXPAND);
void glshim_glDeleteRenderbuffers(glDeleteRenderbuffers_ARG_EXPAND);
typedef void (*glDeleteRenderbuffers_PTR)(glDeleteRenderbuffers_ARG_EXPAND);
void glshim_glDeleteTextures(glDeleteTextures_ARG_EXPAND);
typedef void (*glDeleteTextures_PTR)(glDeleteTextures_ARG_EXPAND);
void glshim_glDepthFunc(glDepthFunc_ARG_EXPAND);
typedef void (*glDepthFunc_PTR)(glDepthFunc_ARG_EXPAND);
void glshim_glDepthMask(glDepthMask_ARG_EXPAND);
typedef void (*glDepthMask_PTR)(glDepthMask_ARG_EXPAND);
void glshim_glDepthRangef(glDepthRangef_ARG_EXPAND);
typedef void (*glDepthRangef_PTR)(glDepthRangef_ARG_EXPAND);
void glshim_glDepthRangex(glDepthRangex_ARG_EXPAND);
typedef void (*glDepthRangex_PTR)(glDepthRangex_ARG_EXPAND);
void glshim_glDisable(glDisable_ARG_EXPAND);
typedef void (*glDisable_PTR)(glDisable_ARG_EXPAND);
void glshim_glDisableClientState(glDisableClientState_ARG_EXPAND);
typedef void (*glDisableClientState_PTR)(glDisableClientState_ARG_EXPAND);
void glshim_glDrawArrays(glDrawArrays_ARG_EXPAND);
typedef void (*glDrawArrays_PTR)(glDrawArrays_ARG_EXPAND);
void glshim_glDrawElements(glDrawElements_ARG_EXPAND);
typedef void (*glDrawElements_PTR)(glDrawElements_ARG_EXPAND);
void glshim_glDrawTexf(glDrawTexf_ARG_EXPAND);
typedef void (*glDrawTexf_PTR)(glDrawTexf_ARG_EXPAND);
void glshim_glDrawTexi(glDrawTexi_ARG_EXPAND);
typedef void (*glDrawTexi_PTR)(glDrawTexi_ARG_EXPAND);
void glshim_glEnable(glEnable_ARG_EXPAND);
typedef void (*glEnable_PTR)(glEnable_ARG_EXPAND);
void glshim_glEnableClientState(glEnableClientState_ARG_EXPAND);
typedef void (*glEnableClientState_PTR)(glEnableClientState_ARG_EXPAND);
void glshim_glFinish(glFinish_ARG_EXPAND);
typedef void (*glFinish_PTR)(glFinish_ARG_EXPAND);
void glshim_glFlush(glFlush_ARG_EXPAND);
typedef void (*glFlush_PTR)(glFlush_ARG_EXPAND);
void glshim_glFogf(glFogf_ARG_EXPAND);
typedef void (*glFogf_PTR)(glFogf_ARG_EXPAND);
void glshim_glFogfv(glFogfv_ARG_EXPAND);
typedef void (*glFogfv_PTR)(glFogfv_ARG_EXPAND);
void glshim_glFogx(glFogx_ARG_EXPAND);
typedef void (*glFogx_PTR)(glFogx_ARG_EXPAND);
void glshim_glFogxv(glFogxv_ARG_EXPAND);
typedef void (*glFogxv_PTR)(glFogxv_ARG_EXPAND);
void glshim_glFramebufferRenderbuffer(glFramebufferRenderbuffer_ARG_EXPAND);
typedef void (*glFramebufferRenderbuffer_PTR)(glFramebufferRenderbuffer_ARG_EXPAND);
void glshim_glFramebufferTexture2D(glFramebufferTexture2D_ARG_EXPAND);
typedef void (*glFramebufferTexture2D_PTR)(glFramebufferTexture2D_ARG_EXPAND);
void glshim_glFrontFace(glFrontFace_ARG_EXPAND);
typedef void (*glFrontFace_PTR)(glFrontFace_ARG_EXPAND);
void glshim_glFrustumf(glFrustumf_ARG_EXPAND);
typedef void (*glFrustumf_PTR)(glFrustumf_ARG_EXPAND);
void glshim_glFrustumx(glFrustumx_ARG_EXPAND);
typedef void (*glFrustumx_PTR)(glFrustumx_ARG_EXPAND);
void glshim_glGenBuffers(glGenBuffers_ARG_EXPAND);
typedef void (*glGenBuffers_PTR)(glGenBuffers_ARG_EXPAND);
void glshim_glGenFramebuffers(glGenFramebuffers_ARG_EXPAND);
typedef void (*glGenFramebuffers_PTR)(glGenFramebuffers_ARG_EXPAND);
void glshim_glGenRenderbuffers(glGenRenderbuffers_ARG_EXPAND);
typedef void (*glGenRenderbuffers_PTR)(glGenRenderbuffers_ARG_EXPAND);
void glshim_glGenTextures(glGenTextures_ARG_EXPAND);
typedef void (*glGenTextures_PTR)(glGenTextures_ARG_EXPAND);
void glshim_glGenerateMipmap(glGenerateMipmap_ARG_EXPAND);
typedef void (*glGenerateMipmap_PTR)(glGenerateMipmap_ARG_EXPAND);
void glshim_glGetBooleanv(glGetBooleanv_ARG_EXPAND);
typedef void (*glGetBooleanv_PTR)(glGetBooleanv_ARG_EXPAND);
void glshim_glGetBufferParameteriv(glGetBufferParameteriv_ARG_EXPAND);
typedef void (*glGetBufferParameteriv_PTR)(glGetBufferParameteriv_ARG_EXPAND);
void glshim_glGetClipPlanef(glGetClipPlanef_ARG_EXPAND);
typedef void (*glGetClipPlanef_PTR)(glGetClipPlanef_ARG_EXPAND);
void glshim_glGetClipPlanex(glGetClipPlanex_ARG_EXPAND);
typedef void (*glGetClipPlanex_PTR)(glGetClipPlanex_ARG_EXPAND);
GLenum glshim_glGetError(glGetError_ARG_EXPAND);
typedef GLenum (*glGetError_PTR)(glGetError_ARG_EXPAND);
void glshim_glGetFixedv(glGetFixedv_ARG_EXPAND);
typedef void (*glGetFixedv_PTR)(glGetFixedv_ARG_EXPAND);
void glshim_glGetFloatv(glGetFloatv_ARG_EXPAND);
typedef void (*glGetFloatv_PTR)(glGetFloatv_ARG_EXPAND);
void glshim_glGetFramebufferAttachmentParameteriv(glGetFramebufferAttachmentParameteriv_ARG_EXPAND);
typedef void (*glGetFramebufferAttachmentParameteriv_PTR)(glGetFramebufferAttachmentParameteriv_ARG_EXPAND);
void glshim_glGetIntegerv(glGetIntegerv_ARG_EXPAND);
typedef void (*glGetIntegerv_PTR)(glGetIntegerv_ARG_EXPAND);
void glshim_glGetLightfv(glGetLightfv_ARG_EXPAND);
typedef void (*glGetLightfv_PTR)(glGetLightfv_ARG_EXPAND);
void glshim_glGetLightxv(glGetLightxv_ARG_EXPAND);
typedef void (*glGetLightxv_PTR)(glGetLightxv_ARG_EXPAND);
void glshim_glGetMaterialfv(glGetMaterialfv_ARG_EXPAND);
typedef void (*glGetMaterialfv_PTR)(glGetMaterialfv_ARG_EXPAND);
void glshim_glGetMaterialxv(glGetMaterialxv_ARG_EXPAND);
typedef void (*glGetMaterialxv_PTR)(glGetMaterialxv_ARG_EXPAND);
void glshim_glGetPointerv(glGetPointerv_ARG_EXPAND);
typedef void (*glGetPointerv_PTR)(glGetPointerv_ARG_EXPAND);
void glshim_glGetRenderbufferParameteriv(glGetRenderbufferParameteriv_ARG_EXPAND);
typedef void (*glGetRenderbufferParameteriv_PTR)(glGetRenderbufferParameteriv_ARG_EXPAND);
const GLubyte * glshim_glGetString(glGetString_ARG_EXPAND);
typedef const GLubyte * (*glGetString_PTR)(glGetString_ARG_EXPAND);
void glshim_glGetTexEnvfv(glGetTexEnvfv_ARG_EXPAND);
typedef void (*glGetTexEnvfv_PTR)(glGetTexEnvfv_ARG_EXPAND);
void glshim_glGetTexEnviv(glGetTexEnviv_ARG_EXPAND);
typedef void (*glGetTexEnviv_PTR)(glGetTexEnviv_ARG_EXPAND);
void glshim_glGetTexEnvxv(glGetTexEnvxv_ARG_EXPAND);
typedef void (*glGetTexEnvxv_PTR)(glGetTexEnvxv_ARG_EXPAND);
void glshim_glGetTexParameterfv(glGetTexParameterfv_ARG_EXPAND);
typedef void (*glGetTexParameterfv_PTR)(glGetTexParameterfv_ARG_EXPAND);
void glshim_glGetTexParameteriv(glGetTexParameteriv_ARG_EXPAND);
typedef void (*glGetTexParameteriv_PTR)(glGetTexParameteriv_ARG_EXPAND);
void glshim_glGetTexParameterxv(glGetTexParameterxv_ARG_EXPAND);
typedef void (*glGetTexParameterxv_PTR)(glGetTexParameterxv_ARG_EXPAND);
void glshim_glHint(glHint_ARG_EXPAND);
typedef void (*glHint_PTR)(glHint_ARG_EXPAND);
GLboolean glshim_glIsBuffer(glIsBuffer_ARG_EXPAND);
typedef GLboolean (*glIsBuffer_PTR)(glIsBuffer_ARG_EXPAND);
GLboolean glshim_glIsEnabled(glIsEnabled_ARG_EXPAND);
typedef GLboolean (*glIsEnabled_PTR)(glIsEnabled_ARG_EXPAND);
GLboolean glshim_glIsFramebuffer(glIsFramebuffer_ARG_EXPAND);
typedef GLboolean (*glIsFramebuffer_PTR)(glIsFramebuffer_ARG_EXPAND);
GLboolean glshim_glIsRenderbuffer(glIsRenderbuffer_ARG_EXPAND);
typedef GLboolean (*glIsRenderbuffer_PTR)(glIsRenderbuffer_ARG_EXPAND);
GLboolean glshim_glIsTexture(glIsTexture_ARG_EXPAND);
typedef GLboolean (*glIsTexture_PTR)(glIsTexture_ARG_EXPAND);
void glshim_glLightModelf(glLightModelf_ARG_EXPAND);
typedef void (*glLightModelf_PTR)(glLightModelf_ARG_EXPAND);
void glshim_glLightModelfv(glLightModelfv_ARG_EXPAND);
typedef void (*glLightModelfv_PTR)(glLightModelfv_ARG_EXPAND);
void glshim_glLightModelx(glLightModelx_ARG_EXPAND);
typedef void (*glLightModelx_PTR)(glLightModelx_ARG_EXPAND);
void glshim_glLightModelxv(glLightModelxv_ARG_EXPAND);
typedef void (*glLightModelxv_PTR)(glLightModelxv_ARG_EXPAND);
void glshim_glLightf(glLightf_ARG_EXPAND);
typedef void (*glLightf_PTR)(glLightf_ARG_EXPAND);
void glshim_glLightfv(glLightfv_ARG_EXPAND);
typedef void (*glLightfv_PTR)(glLightfv_ARG_EXPAND);
void glshim_glLightx(glLightx_ARG_EXPAND);
typedef void (*glLightx_PTR)(glLightx_ARG_EXPAND);
void glshim_glLightxv(glLightxv_ARG_EXPAND);
typedef void (*glLightxv_PTR)(glLightxv_ARG_EXPAND);
void glshim_glLineWidth(glLineWidth_ARG_EXPAND);
typedef void (*glLineWidth_PTR)(glLineWidth_ARG_EXPAND);
void glshim_glLineWidthx(glLineWidthx_ARG_EXPAND);
typedef void (*glLineWidthx_PTR)(glLineWidthx_ARG_EXPAND);
void glshim_glLoadIdentity(glLoadIdentity_ARG_EXPAND);
typedef void (*glLoadIdentity_PTR)(glLoadIdentity_ARG_EXPAND);
void glshim_glLoadMatrixf(glLoadMatrixf_ARG_EXPAND);
typedef void (*glLoadMatrixf_PTR)(glLoadMatrixf_ARG_EXPAND);
void glshim_glLoadMatrixx(glLoadMatrixx_ARG_EXPAND);
typedef void (*glLoadMatrixx_PTR)(glLoadMatrixx_ARG_EXPAND);
void glshim_glLogicOp(glLogicOp_ARG_EXPAND);
typedef void (*glLogicOp_PTR)(glLogicOp_ARG_EXPAND);
void glshim_glMaterialf(glMaterialf_ARG_EXPAND);
typedef void (*glMaterialf_PTR)(glMaterialf_ARG_EXPAND);
void glshim_glMaterialfv(glMaterialfv_ARG_EXPAND);
typedef void (*glMaterialfv_PTR)(glMaterialfv_ARG_EXPAND);
void glshim_glMaterialx(glMaterialx_ARG_EXPAND);
typedef void (*glMaterialx_PTR)(glMaterialx_ARG_EXPAND);
void glshim_glMaterialxv(glMaterialxv_ARG_EXPAND);
typedef void (*glMaterialxv_PTR)(glMaterialxv_ARG_EXPAND);
void glshim_glMatrixMode(glMatrixMode_ARG_EXPAND);
typedef void (*glMatrixMode_PTR)(glMatrixMode_ARG_EXPAND);
void glshim_glMultMatrixf(glMultMatrixf_ARG_EXPAND);
typedef void (*glMultMatrixf_PTR)(glMultMatrixf_ARG_EXPAND);
void glshim_glMultMatrixx(glMultMatrixx_ARG_EXPAND);
typedef void (*glMultMatrixx_PTR)(glMultMatrixx_ARG_EXPAND);
void glshim_glMultiTexCoord4f(glMultiTexCoord4f_ARG_EXPAND);
typedef void (*glMultiTexCoord4f_PTR)(glMultiTexCoord4f_ARG_EXPAND);
void glshim_glMultiTexCoord4x(glMultiTexCoord4x_ARG_EXPAND);
typedef void (*glMultiTexCoord4x_PTR)(glMultiTexCoord4x_ARG_EXPAND);
void glshim_glNormal3f(glNormal3f_ARG_EXPAND);
typedef void (*glNormal3f_PTR)(glNormal3f_ARG_EXPAND);
void glshim_glNormal3x(glNormal3x_ARG_EXPAND);
typedef void (*glNormal3x_PTR)(glNormal3x_ARG_EXPAND);
void glshim_glNormalPointer(glNormalPointer_ARG_EXPAND);
typedef void (*glNormalPointer_PTR)(glNormalPointer_ARG_EXPAND);
void glshim_glOrthof(glOrthof_ARG_EXPAND);
typedef void (*glOrthof_PTR)(glOrthof_ARG_EXPAND);
void glshim_glOrthox(glOrthox_ARG_EXPAND);
typedef void (*glOrthox_PTR)(glOrthox_ARG_EXPAND);
void glshim_glPixelStorei(glPixelStorei_ARG_EXPAND);
typedef void (*glPixelStorei_PTR)(glPixelStorei_ARG_EXPAND);
void glshim_glPointParameterf(glPointParameterf_ARG_EXPAND);
typedef void (*glPointParameterf_PTR)(glPointParameterf_ARG_EXPAND);
void glshim_glPointParameterfv(glPointParameterfv_ARG_EXPAND);
typedef void (*glPointParameterfv_PTR)(glPointParameterfv_ARG_EXPAND);
void glshim_glPointParameterx(glPointParameterx_ARG_EXPAND);
typedef void (*glPointParameterx_PTR)(glPointParameterx_ARG_EXPAND);
void glshim_glPointParameterxv(glPointParameterxv_ARG_EXPAND);
typedef void (*glPointParameterxv_PTR)(glPointParameterxv_ARG_EXPAND);
void glshim_glPointSize(glPointSize_ARG_EXPAND);
typedef void (*glPointSize_PTR)(glPointSize_ARG_EXPAND);
void glshim_glPointSizePointerOES(glPointSizePointerOES_ARG_EXPAND);
typedef void (*glPointSizePointerOES_PTR)(glPointSizePointerOES_ARG_EXPAND);
void glshim_glPointSizex(glPointSizex_ARG_EXPAND);
typedef void (*glPointSizex_PTR)(glPointSizex_ARG_EXPAND);
void glshim_glPolygonOffset(glPolygonOffset_ARG_EXPAND);
typedef void (*glPolygonOffset_PTR)(glPolygonOffset_ARG_EXPAND);
void glshim_glPolygonOffsetx(glPolygonOffsetx_ARG_EXPAND);
typedef void (*glPolygonOffsetx_PTR)(glPolygonOffsetx_ARG_EXPAND);
void glshim_glPopMatrix(glPopMatrix_ARG_EXPAND);
typedef void (*glPopMatrix_PTR)(glPopMatrix_ARG_EXPAND);
void glshim_glPushMatrix(glPushMatrix_ARG_EXPAND);
typedef void (*glPushMatrix_PTR)(glPushMatrix_ARG_EXPAND);
void glshim_glReadPixels(glReadPixels_ARG_EXPAND);
typedef void (*glReadPixels_PTR)(glReadPixels_ARG_EXPAND);
void glshim_glRenderbufferStorage(glRenderbufferStorage_ARG_EXPAND);
typedef void (*glRenderbufferStorage_PTR)(glRenderbufferStorage_ARG_EXPAND);
void glshim_glRotatef(glRotatef_ARG_EXPAND);
typedef void (*glRotatef_PTR)(glRotatef_ARG_EXPAND);
void glshim_glRotatex(glRotatex_ARG_EXPAND);
typedef void (*glRotatex_PTR)(glRotatex_ARG_EXPAND);
void glshim_glSampleCoverage(glSampleCoverage_ARG_EXPAND);
typedef void (*glSampleCoverage_PTR)(glSampleCoverage_ARG_EXPAND);
void glshim_glSampleCoveragex(glSampleCoveragex_ARG_EXPAND);
typedef void (*glSampleCoveragex_PTR)(glSampleCoveragex_ARG_EXPAND);
void glshim_glScalef(glScalef_ARG_EXPAND);
typedef void (*glScalef_PTR)(glScalef_ARG_EXPAND);
void glshim_glScalex(glScalex_ARG_EXPAND);
typedef void (*glScalex_PTR)(glScalex_ARG_EXPAND);
void glshim_glScissor(glScissor_ARG_EXPAND);
typedef void (*glScissor_PTR)(glScissor_ARG_EXPAND);
void glshim_glShadeModel(glShadeModel_ARG_EXPAND);
typedef void (*glShadeModel_PTR)(glShadeModel_ARG_EXPAND);
void glshim_glStencilFunc(glStencilFunc_ARG_EXPAND);
typedef void (*glStencilFunc_PTR)(glStencilFunc_ARG_EXPAND);
void glshim_glStencilMask(glStencilMask_ARG_EXPAND);
typedef void (*glStencilMask_PTR)(glStencilMask_ARG_EXPAND);
void glshim_glStencilOp(glStencilOp_ARG_EXPAND);
typedef void (*glStencilOp_PTR)(glStencilOp_ARG_EXPAND);
void glshim_glTexCoordPointer(glTexCoordPointer_ARG_EXPAND);
typedef void (*glTexCoordPointer_PTR)(glTexCoordPointer_ARG_EXPAND);
void glshim_glTexEnvf(glTexEnvf_ARG_EXPAND);
typedef void (*glTexEnvf_PTR)(glTexEnvf_ARG_EXPAND);
void glshim_glTexEnvfv(glTexEnvfv_ARG_EXPAND);
typedef void (*glTexEnvfv_PTR)(glTexEnvfv_ARG_EXPAND);
void glshim_glTexEnvi(glTexEnvi_ARG_EXPAND);
typedef void (*glTexEnvi_PTR)(glTexEnvi_ARG_EXPAND);
void glshim_glTexEnviv(glTexEnviv_ARG_EXPAND);
typedef void (*glTexEnviv_PTR)(glTexEnviv_ARG_EXPAND);
void glshim_glTexEnvx(glTexEnvx_ARG_EXPAND);
typedef void (*glTexEnvx_PTR)(glTexEnvx_ARG_EXPAND);
void glshim_glTexEnvxv(glTexEnvxv_ARG_EXPAND);
typedef void (*glTexEnvxv_PTR)(glTexEnvxv_ARG_EXPAND);
void glshim_glTexGenfv(glTexGenfv_ARG_EXPAND);
typedef void (*glTexGenfv_PTR)(glTexGenfv_ARG_EXPAND);
void glshim_glTexGeni(glTexGeni_ARG_EXPAND);
typedef void (*glTexGeni_PTR)(glTexGeni_ARG_EXPAND);
void glshim_glTexImage2D(glTexImage2D_ARG_EXPAND);
typedef void (*glTexImage2D_PTR)(glTexImage2D_ARG_EXPAND);
void glshim_glTexParameterf(glTexParameterf_ARG_EXPAND);
typedef void (*glTexParameterf_PTR)(glTexParameterf_ARG_EXPAND);
void glshim_glTexParameterfv(glTexParameterfv_ARG_EXPAND);
typedef void (*glTexParameterfv_PTR)(glTexParameterfv_ARG_EXPAND);
void glshim_glTexParameteri(glTexParameteri_ARG_EXPAND);
typedef void (*glTexParameteri_PTR)(glTexParameteri_ARG_EXPAND);
void glshim_glTexParameteriv(glTexParameteriv_ARG_EXPAND);
typedef void (*glTexParameteriv_PTR)(glTexParameteriv_ARG_EXPAND);
void glshim_glTexParameterx(glTexParameterx_ARG_EXPAND);
typedef void (*glTexParameterx_PTR)(glTexParameterx_ARG_EXPAND);
void glshim_glTexParameterxv(glTexParameterxv_ARG_EXPAND);
typedef void (*glTexParameterxv_PTR)(glTexParameterxv_ARG_EXPAND);
void glshim_glTexSubImage2D(glTexSubImage2D_ARG_EXPAND);
typedef void (*glTexSubImage2D_PTR)(glTexSubImage2D_ARG_EXPAND);
void glshim_glTranslatef(glTranslatef_ARG_EXPAND);
typedef void (*glTranslatef_PTR)(glTranslatef_ARG_EXPAND);
void glshim_glTranslatex(glTranslatex_ARG_EXPAND);
typedef void (*glTranslatex_PTR)(glTranslatex_ARG_EXPAND);
void glshim_glVertexPointer(glVertexPointer_ARG_EXPAND);
typedef void (*glVertexPointer_PTR)(glVertexPointer_ARG_EXPAND);
void glshim_glViewport(glViewport_ARG_EXPAND);
typedef void (*glViewport_PTR)(glViewport_ARG_EXPAND);



#ifndef direct_glActiveTexture
#define push_glActiveTexture(texture) { \
    glActiveTexture_PACKED *packed_data = malloc(sizeof(glActiveTexture_PACKED)); \
    packed_data->format = glActiveTexture_FORMAT; \
    packed_data->func = glshim_glActiveTexture; \
    packed_data->args.a1 = (GLenum)texture; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glAlphaFunc
#define push_glAlphaFunc(func, ref) { \
    glAlphaFunc_PACKED *packed_data = malloc(sizeof(glAlphaFunc_PACKED)); \
    packed_data->format = glAlphaFunc_FORMAT; \
    packed_data->func = glshim_glAlphaFunc; \
    packed_data->args.a1 = (GLenum)func; \
    packed_data->args.a2 = (GLclampf)ref; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glAlphaFuncx
#define push_glAlphaFuncx(func, ref) { \
    glAlphaFuncx_PACKED *packed_data = malloc(sizeof(glAlphaFuncx_PACKED)); \
    packed_data->format = glAlphaFuncx_FORMAT; \
    packed_data->func = glshim_glAlphaFuncx; \
    packed_data->args.a1 = (GLenum)func; \
    packed_data->args.a2 = (GLclampx)ref; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glBindBuffer
#define push_glBindBuffer(target, buffer) { \
    glBindBuffer_PACKED *packed_data = malloc(sizeof(glBindBuffer_PACKED)); \
    packed_data->format = glBindBuffer_FORMAT; \
    packed_data->func = glshim_glBindBuffer; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLuint)buffer; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glBindFramebuffer
#define push_glBindFramebuffer(target, framebuffer) { \
    glBindFramebuffer_PACKED *packed_data = malloc(sizeof(glBindFramebuffer_PACKED)); \
    packed_data->format = glBindFramebuffer_FORMAT; \
    packed_data->func = glshim_glBindFramebuffer; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLuint)framebuffer; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glBindRenderbuffer
#define push_glBindRenderbuffer(target, renderbuffer) { \
    glBindRenderbuffer_PACKED *packed_data = malloc(sizeof(glBindRenderbuffer_PACKED)); \
    packed_data->format = glBindRenderbuffer_FORMAT; \
    packed_data->func = glshim_glBindRenderbuffer; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLuint)renderbuffer; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glBindTexture
#define push_glBindTexture(target, texture) { \
    glBindTexture_PACKED *packed_data = malloc(sizeof(glBindTexture_PACKED)); \
    packed_data->format = glBindTexture_FORMAT; \
    packed_data->func = glshim_glBindTexture; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLuint)texture; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glBlendColor
#define push_glBlendColor(red, green, blue, alpha) { \
    glBlendColor_PACKED *packed_data = malloc(sizeof(glBlendColor_PACKED)); \
    packed_data->format = glBlendColor_FORMAT; \
    packed_data->func = glshim_glBlendColor; \
    packed_data->args.a1 = (GLclampf)red; \
    packed_data->args.a2 = (GLclampf)green; \
    packed_data->args.a3 = (GLclampf)blue; \
    packed_data->args.a4 = (GLclampf)alpha; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glBlendEquation
#define push_glBlendEquation(mode) { \
    glBlendEquation_PACKED *packed_data = malloc(sizeof(glBlendEquation_PACKED)); \
    packed_data->format = glBlendEquation_FORMAT; \
    packed_data->func = glshim_glBlendEquation; \
    packed_data->args.a1 = (GLenum)mode; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glBlendEquationSeparate
#define push_glBlendEquationSeparate(modeRGB, modeA) { \
    glBlendEquationSeparate_PACKED *packed_data = malloc(sizeof(glBlendEquationSeparate_PACKED)); \
    packed_data->format = glBlendEquationSeparate_FORMAT; \
    packed_data->func = glshim_glBlendEquationSeparate; \
    packed_data->args.a1 = (GLenum)modeRGB; \
    packed_data->args.a2 = (GLenum)modeA; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glBlendFunc
#define push_glBlendFunc(sfactor, dfactor) { \
    glBlendFunc_PACKED *packed_data = malloc(sizeof(glBlendFunc_PACKED)); \
    packed_data->format = glBlendFunc_FORMAT; \
    packed_data->func = glshim_glBlendFunc; \
    packed_data->args.a1 = (GLenum)sfactor; \
    packed_data->args.a2 = (GLenum)dfactor; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glBlendFuncSeparate
#define push_glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha) { \
    glBlendFuncSeparate_PACKED *packed_data = malloc(sizeof(glBlendFuncSeparate_PACKED)); \
    packed_data->format = glBlendFuncSeparate_FORMAT; \
    packed_data->func = glshim_glBlendFuncSeparate; \
    packed_data->args.a1 = (GLenum)sfactorRGB; \
    packed_data->args.a2 = (GLenum)dfactorRGB; \
    packed_data->args.a3 = (GLenum)sfactorAlpha; \
    packed_data->args.a4 = (GLenum)dfactorAlpha; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glBufferData
#define push_glBufferData(target, size, data, usage) { \
    glBufferData_PACKED *packed_data = malloc(sizeof(glBufferData_PACKED)); \
    packed_data->format = glBufferData_FORMAT; \
    packed_data->func = glshim_glBufferData; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLsizeiptr)size; \
    packed_data->args.a3 = (GLvoid *)data; \
    packed_data->args.a4 = (GLenum)usage; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glBufferSubData
#define push_glBufferSubData(target, offset, size, data) { \
    glBufferSubData_PACKED *packed_data = malloc(sizeof(glBufferSubData_PACKED)); \
    packed_data->format = glBufferSubData_FORMAT; \
    packed_data->func = glshim_glBufferSubData; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLintptr)offset; \
    packed_data->args.a3 = (GLsizeiptr)size; \
    packed_data->args.a4 = (GLvoid *)data; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glCheckFramebufferStatus
#define push_glCheckFramebufferStatus(target) { \
    glCheckFramebufferStatus_PACKED *packed_data = malloc(sizeof(glCheckFramebufferStatus_PACKED)); \
    packed_data->format = glCheckFramebufferStatus_FORMAT; \
    packed_data->func = glshim_glCheckFramebufferStatus; \
    packed_data->args.a1 = (GLenum)target; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glClear
#define push_glClear(mask) { \
    glClear_PACKED *packed_data = malloc(sizeof(glClear_PACKED)); \
    packed_data->format = glClear_FORMAT; \
    packed_data->func = glshim_glClear; \
    packed_data->args.a1 = (GLbitfield)mask; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glClearColor
#define push_glClearColor(red, green, blue, alpha) { \
    glClearColor_PACKED *packed_data = malloc(sizeof(glClearColor_PACKED)); \
    packed_data->format = glClearColor_FORMAT; \
    packed_data->func = glshim_glClearColor; \
    packed_data->args.a1 = (GLclampf)red; \
    packed_data->args.a2 = (GLclampf)green; \
    packed_data->args.a3 = (GLclampf)blue; \
    packed_data->args.a4 = (GLclampf)alpha; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glClearColorx
#define push_glClearColorx(red, green, blue, alpha) { \
    glClearColorx_PACKED *packed_data = malloc(sizeof(glClearColorx_PACKED)); \
    packed_data->format = glClearColorx_FORMAT; \
    packed_data->func = glshim_glClearColorx; \
    packed_data->args.a1 = (GLclampx)red; \
    packed_data->args.a2 = (GLclampx)green; \
    packed_data->args.a3 = (GLclampx)blue; \
    packed_data->args.a4 = (GLclampx)alpha; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glClearDepthf
#define push_glClearDepthf(depth) { \
    glClearDepthf_PACKED *packed_data = malloc(sizeof(glClearDepthf_PACKED)); \
    packed_data->format = glClearDepthf_FORMAT; \
    packed_data->func = glshim_glClearDepthf; \
    packed_data->args.a1 = (GLclampf)depth; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glClearDepthx
#define push_glClearDepthx(depth) { \
    glClearDepthx_PACKED *packed_data = malloc(sizeof(glClearDepthx_PACKED)); \
    packed_data->format = glClearDepthx_FORMAT; \
    packed_data->func = glshim_glClearDepthx; \
    packed_data->args.a1 = (GLclampx)depth; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glClearStencil
#define push_glClearStencil(s) { \
    glClearStencil_PACKED *packed_data = malloc(sizeof(glClearStencil_PACKED)); \
    packed_data->format = glClearStencil_FORMAT; \
    packed_data->func = glshim_glClearStencil; \
    packed_data->args.a1 = (GLint)s; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glClientActiveTexture
#define push_glClientActiveTexture(texture) { \
    glClientActiveTexture_PACKED *packed_data = malloc(sizeof(glClientActiveTexture_PACKED)); \
    packed_data->format = glClientActiveTexture_FORMAT; \
    packed_data->func = glshim_glClientActiveTexture; \
    packed_data->args.a1 = (GLenum)texture; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glClipPlanef
#define push_glClipPlanef(plane, equation) { \
    glClipPlanef_PACKED *packed_data = malloc(sizeof(glClipPlanef_PACKED)); \
    packed_data->format = glClipPlanef_FORMAT; \
    packed_data->func = glshim_glClipPlanef; \
    packed_data->args.a1 = (GLenum)plane; \
    packed_data->args.a2 = (GLfloat *)equation; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glClipPlanex
#define push_glClipPlanex(plane, equation) { \
    glClipPlanex_PACKED *packed_data = malloc(sizeof(glClipPlanex_PACKED)); \
    packed_data->format = glClipPlanex_FORMAT; \
    packed_data->func = glshim_glClipPlanex; \
    packed_data->args.a1 = (GLenum)plane; \
    packed_data->args.a2 = (GLfixed *)equation; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glColor4f
#define push_glColor4f(red, green, blue, alpha) { \
    glColor4f_PACKED *packed_data = malloc(sizeof(glColor4f_PACKED)); \
    packed_data->format = glColor4f_FORMAT; \
    packed_data->func = glshim_glColor4f; \
    packed_data->args.a1 = (GLfloat)red; \
    packed_data->args.a2 = (GLfloat)green; \
    packed_data->args.a3 = (GLfloat)blue; \
    packed_data->args.a4 = (GLfloat)alpha; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glColor4ub
#define push_glColor4ub(red, green, blue, alpha) { \
    glColor4ub_PACKED *packed_data = malloc(sizeof(glColor4ub_PACKED)); \
    packed_data->format = glColor4ub_FORMAT; \
    packed_data->func = glshim_glColor4ub; \
    packed_data->args.a1 = (GLubyte)red; \
    packed_data->args.a2 = (GLubyte)green; \
    packed_data->args.a3 = (GLubyte)blue; \
    packed_data->args.a4 = (GLubyte)alpha; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glColor4x
#define push_glColor4x(red, green, blue, alpha) { \
    glColor4x_PACKED *packed_data = malloc(sizeof(glColor4x_PACKED)); \
    packed_data->format = glColor4x_FORMAT; \
    packed_data->func = glshim_glColor4x; \
    packed_data->args.a1 = (GLfixed)red; \
    packed_data->args.a2 = (GLfixed)green; \
    packed_data->args.a3 = (GLfixed)blue; \
    packed_data->args.a4 = (GLfixed)alpha; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glColorMask
#define push_glColorMask(red, green, blue, alpha) { \
    glColorMask_PACKED *packed_data = malloc(sizeof(glColorMask_PACKED)); \
    packed_data->format = glColorMask_FORMAT; \
    packed_data->func = glshim_glColorMask; \
    packed_data->args.a1 = (GLboolean)red; \
    packed_data->args.a2 = (GLboolean)green; \
    packed_data->args.a3 = (GLboolean)blue; \
    packed_data->args.a4 = (GLboolean)alpha; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glColorPointer
#define push_glColorPointer(size, type, stride, pointer) { \
    glColorPointer_PACKED *packed_data = malloc(sizeof(glColorPointer_PACKED)); \
    packed_data->format = glColorPointer_FORMAT; \
    packed_data->func = glshim_glColorPointer; \
    packed_data->args.a1 = (GLint)size; \
    packed_data->args.a2 = (GLenum)type; \
    packed_data->args.a3 = (GLsizei)stride; \
    packed_data->args.a4 = (GLvoid *)pointer; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glCompressedTexImage2D
#define push_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data) { \
    glCompressedTexImage2D_PACKED *packed_data = malloc(sizeof(glCompressedTexImage2D_PACKED)); \
    packed_data->format = glCompressedTexImage2D_FORMAT; \
    packed_data->func = glshim_glCompressedTexImage2D; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLint)level; \
    packed_data->args.a3 = (GLenum)internalformat; \
    packed_data->args.a4 = (GLsizei)width; \
    packed_data->args.a5 = (GLsizei)height; \
    packed_data->args.a6 = (GLint)border; \
    packed_data->args.a7 = (GLsizei)imageSize; \
    packed_data->args.a8 = (GLvoid *)data; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glCompressedTexSubImage2D
#define push_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data) { \
    glCompressedTexSubImage2D_PACKED *packed_data = malloc(sizeof(glCompressedTexSubImage2D_PACKED)); \
    packed_data->format = glCompressedTexSubImage2D_FORMAT; \
    packed_data->func = glshim_glCompressedTexSubImage2D; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLint)level; \
    packed_data->args.a3 = (GLint)xoffset; \
    packed_data->args.a4 = (GLint)yoffset; \
    packed_data->args.a5 = (GLsizei)width; \
    packed_data->args.a6 = (GLsizei)height; \
    packed_data->args.a7 = (GLenum)format; \
    packed_data->args.a8 = (GLsizei)imageSize; \
    packed_data->args.a9 = (GLvoid *)data; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glCopyTexImage2D
#define push_glCopyTexImage2D(target, level, internalformat, x, y, width, height, border) { \
    glCopyTexImage2D_PACKED *packed_data = malloc(sizeof(glCopyTexImage2D_PACKED)); \
    packed_data->format = glCopyTexImage2D_FORMAT; \
    packed_data->func = glshim_glCopyTexImage2D; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLint)level; \
    packed_data->args.a3 = (GLenum)internalformat; \
    packed_data->args.a4 = (GLint)x; \
    packed_data->args.a5 = (GLint)y; \
    packed_data->args.a6 = (GLsizei)width; \
    packed_data->args.a7 = (GLsizei)height; \
    packed_data->args.a8 = (GLint)border; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glCopyTexSubImage2D
#define push_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height) { \
    glCopyTexSubImage2D_PACKED *packed_data = malloc(sizeof(glCopyTexSubImage2D_PACKED)); \
    packed_data->format = glCopyTexSubImage2D_FORMAT; \
    packed_data->func = glshim_glCopyTexSubImage2D; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLint)level; \
    packed_data->args.a3 = (GLint)xoffset; \
    packed_data->args.a4 = (GLint)yoffset; \
    packed_data->args.a5 = (GLint)x; \
    packed_data->args.a6 = (GLint)y; \
    packed_data->args.a7 = (GLsizei)width; \
    packed_data->args.a8 = (GLsizei)height; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glCullFace
#define push_glCullFace(mode) { \
    glCullFace_PACKED *packed_data = malloc(sizeof(glCullFace_PACKED)); \
    packed_data->format = glCullFace_FORMAT; \
    packed_data->func = glshim_glCullFace; \
    packed_data->args.a1 = (GLenum)mode; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glDeleteBuffers
#define push_glDeleteBuffers(n, buffers) { \
    glDeleteBuffers_PACKED *packed_data = malloc(sizeof(glDeleteBuffers_PACKED)); \
    packed_data->format = glDeleteBuffers_FORMAT; \
    packed_data->func = glshim_glDeleteBuffers; \
    packed_data->args.a1 = (GLsizei)n; \
    packed_data->args.a2 = (GLuint *)buffers; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glDeleteFramebuffers
#define push_glDeleteFramebuffers(n, framebuffers) { \
    glDeleteFramebuffers_PACKED *packed_data = malloc(sizeof(glDeleteFramebuffers_PACKED)); \
    packed_data->format = glDeleteFramebuffers_FORMAT; \
    packed_data->func = glshim_glDeleteFramebuffers; \
    packed_data->args.a1 = (GLsizei)n; \
    packed_data->args.a2 = (GLuint *)framebuffers; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glDeleteRenderbuffers
#define push_glDeleteRenderbuffers(n, renderbuffers) { \
    glDeleteRenderbuffers_PACKED *packed_data = malloc(sizeof(glDeleteRenderbuffers_PACKED)); \
    packed_data->format = glDeleteRenderbuffers_FORMAT; \
    packed_data->func = glshim_glDeleteRenderbuffers; \
    packed_data->args.a1 = (GLsizei)n; \
    packed_data->args.a2 = (GLuint *)renderbuffers; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glDeleteTextures
#define push_glDeleteTextures(n, textures) { \
    glDeleteTextures_PACKED *packed_data = malloc(sizeof(glDeleteTextures_PACKED)); \
    packed_data->format = glDeleteTextures_FORMAT; \
    packed_data->func = glshim_glDeleteTextures; \
    packed_data->args.a1 = (GLsizei)n; \
    packed_data->args.a2 = (GLuint *)textures; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glDepthFunc
#define push_glDepthFunc(func) { \
    glDepthFunc_PACKED *packed_data = malloc(sizeof(glDepthFunc_PACKED)); \
    packed_data->format = glDepthFunc_FORMAT; \
    packed_data->func = glshim_glDepthFunc; \
    packed_data->args.a1 = (GLenum)func; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glDepthMask
#define push_glDepthMask(flag) { \
    glDepthMask_PACKED *packed_data = malloc(sizeof(glDepthMask_PACKED)); \
    packed_data->format = glDepthMask_FORMAT; \
    packed_data->func = glshim_glDepthMask; \
    packed_data->args.a1 = (GLboolean)flag; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glDepthRangef
#define push_glDepthRangef(near, far) { \
    glDepthRangef_PACKED *packed_data = malloc(sizeof(glDepthRangef_PACKED)); \
    packed_data->format = glDepthRangef_FORMAT; \
    packed_data->func = glshim_glDepthRangef; \
    packed_data->args.a1 = (GLclampf)near; \
    packed_data->args.a2 = (GLclampf)far; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glDepthRangex
#define push_glDepthRangex(near, far) { \
    glDepthRangex_PACKED *packed_data = malloc(sizeof(glDepthRangex_PACKED)); \
    packed_data->format = glDepthRangex_FORMAT; \
    packed_data->func = glshim_glDepthRangex; \
    packed_data->args.a1 = (GLclampx)near; \
    packed_data->args.a2 = (GLclampx)far; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glDisable
#define push_glDisable(cap) { \
    glDisable_PACKED *packed_data = malloc(sizeof(glDisable_PACKED)); \
    packed_data->format = glDisable_FORMAT; \
    packed_data->func = glshim_glDisable; \
    packed_data->args.a1 = (GLenum)cap; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glDisableClientState
#define push_glDisableClientState(array) { \
    glDisableClientState_PACKED *packed_data = malloc(sizeof(glDisableClientState_PACKED)); \
    packed_data->format = glDisableClientState_FORMAT; \
    packed_data->func = glshim_glDisableClientState; \
    packed_data->args.a1 = (GLenum)array; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glDrawArrays
#define push_glDrawArrays(mode, first, count) { \
    glDrawArrays_PACKED *packed_data = malloc(sizeof(glDrawArrays_PACKED)); \
    packed_data->format = glDrawArrays_FORMAT; \
    packed_data->func = glshim_glDrawArrays; \
    packed_data->args.a1 = (GLenum)mode; \
    packed_data->args.a2 = (GLint)first; \
    packed_data->args.a3 = (GLsizei)count; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glDrawElements
#define push_glDrawElements(mode, count, type, indices) { \
    glDrawElements_PACKED *packed_data = malloc(sizeof(glDrawElements_PACKED)); \
    packed_data->format = glDrawElements_FORMAT; \
    packed_data->func = glshim_glDrawElements; \
    packed_data->args.a1 = (GLenum)mode; \
    packed_data->args.a2 = (GLsizei)count; \
    packed_data->args.a3 = (GLenum)type; \
    packed_data->args.a4 = (GLvoid *)indices; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glDrawTexf
#define push_glDrawTexf(x, y, z, width, height) { \
    glDrawTexf_PACKED *packed_data = malloc(sizeof(glDrawTexf_PACKED)); \
    packed_data->format = glDrawTexf_FORMAT; \
    packed_data->func = glshim_glDrawTexf; \
    packed_data->args.a1 = (GLfloat)x; \
    packed_data->args.a2 = (GLfloat)y; \
    packed_data->args.a3 = (GLfloat)z; \
    packed_data->args.a4 = (GLfloat)width; \
    packed_data->args.a5 = (GLfloat)height; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glDrawTexi
#define push_glDrawTexi(x, y, z, width, height) { \
    glDrawTexi_PACKED *packed_data = malloc(sizeof(glDrawTexi_PACKED)); \
    packed_data->format = glDrawTexi_FORMAT; \
    packed_data->func = glshim_glDrawTexi; \
    packed_data->args.a1 = (GLint)x; \
    packed_data->args.a2 = (GLint)y; \
    packed_data->args.a3 = (GLint)z; \
    packed_data->args.a4 = (GLint)width; \
    packed_data->args.a5 = (GLint)height; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glEnable
#define push_glEnable(cap) { \
    glEnable_PACKED *packed_data = malloc(sizeof(glEnable_PACKED)); \
    packed_data->format = glEnable_FORMAT; \
    packed_data->func = glshim_glEnable; \
    packed_data->args.a1 = (GLenum)cap; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glEnableClientState
#define push_glEnableClientState(array) { \
    glEnableClientState_PACKED *packed_data = malloc(sizeof(glEnableClientState_PACKED)); \
    packed_data->format = glEnableClientState_FORMAT; \
    packed_data->func = glshim_glEnableClientState; \
    packed_data->args.a1 = (GLenum)array; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glFinish
#define push_glFinish() { \
    glFinish_PACKED *packed_data = malloc(sizeof(glFinish_PACKED)); \
    packed_data->format = glFinish_FORMAT; \
    packed_data->func = glshim_glFinish; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glFlush
#define push_glFlush() { \
    glFlush_PACKED *packed_data = malloc(sizeof(glFlush_PACKED)); \
    packed_data->format = glFlush_FORMAT; \
    packed_data->func = glshim_glFlush; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glFogf
#define push_glFogf(pname, param) { \
    glFogf_PACKED *packed_data = malloc(sizeof(glFogf_PACKED)); \
    packed_data->format = glFogf_FORMAT; \
    packed_data->func = glshim_glFogf; \
    packed_data->args.a1 = (GLenum)pname; \
    packed_data->args.a2 = (GLfloat)param; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glFogfv
#define push_glFogfv(pname, params) { \
    glFogfv_PACKED *packed_data = malloc(sizeof(glFogfv_PACKED)); \
    packed_data->format = glFogfv_FORMAT; \
    packed_data->func = glshim_glFogfv; \
    packed_data->args.a1 = (GLenum)pname; \
    packed_data->args.a2 = (GLfloat *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glFogx
#define push_glFogx(pname, param) { \
    glFogx_PACKED *packed_data = malloc(sizeof(glFogx_PACKED)); \
    packed_data->format = glFogx_FORMAT; \
    packed_data->func = glshim_glFogx; \
    packed_data->args.a1 = (GLenum)pname; \
    packed_data->args.a2 = (GLfixed)param; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glFogxv
#define push_glFogxv(pname, params) { \
    glFogxv_PACKED *packed_data = malloc(sizeof(glFogxv_PACKED)); \
    packed_data->format = glFogxv_FORMAT; \
    packed_data->func = glshim_glFogxv; \
    packed_data->args.a1 = (GLenum)pname; \
    packed_data->args.a2 = (GLfixed *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glFramebufferRenderbuffer
#define push_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer) { \
    glFramebufferRenderbuffer_PACKED *packed_data = malloc(sizeof(glFramebufferRenderbuffer_PACKED)); \
    packed_data->format = glFramebufferRenderbuffer_FORMAT; \
    packed_data->func = glshim_glFramebufferRenderbuffer; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLenum)attachment; \
    packed_data->args.a3 = (GLenum)renderbuffertarget; \
    packed_data->args.a4 = (GLuint)renderbuffer; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glFramebufferTexture2D
#define push_glFramebufferTexture2D(target, attachment, textarget, texture, level) { \
    glFramebufferTexture2D_PACKED *packed_data = malloc(sizeof(glFramebufferTexture2D_PACKED)); \
    packed_data->format = glFramebufferTexture2D_FORMAT; \
    packed_data->func = glshim_glFramebufferTexture2D; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLenum)attachment; \
    packed_data->args.a3 = (GLenum)textarget; \
    packed_data->args.a4 = (GLuint)texture; \
    packed_data->args.a5 = (GLint)level; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glFrontFace
#define push_glFrontFace(mode) { \
    glFrontFace_PACKED *packed_data = malloc(sizeof(glFrontFace_PACKED)); \
    packed_data->format = glFrontFace_FORMAT; \
    packed_data->func = glshim_glFrontFace; \
    packed_data->args.a1 = (GLenum)mode; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glFrustumf
#define push_glFrustumf(left, right, bottom, top, near, far) { \
    glFrustumf_PACKED *packed_data = malloc(sizeof(glFrustumf_PACKED)); \
    packed_data->format = glFrustumf_FORMAT; \
    packed_data->func = glshim_glFrustumf; \
    packed_data->args.a1 = (GLfloat)left; \
    packed_data->args.a2 = (GLfloat)right; \
    packed_data->args.a3 = (GLfloat)bottom; \
    packed_data->args.a4 = (GLfloat)top; \
    packed_data->args.a5 = (GLfloat)near; \
    packed_data->args.a6 = (GLfloat)far; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glFrustumx
#define push_glFrustumx(left, right, bottom, top, near, far) { \
    glFrustumx_PACKED *packed_data = malloc(sizeof(glFrustumx_PACKED)); \
    packed_data->format = glFrustumx_FORMAT; \
    packed_data->func = glshim_glFrustumx; \
    packed_data->args.a1 = (GLfixed)left; \
    packed_data->args.a2 = (GLfixed)right; \
    packed_data->args.a3 = (GLfixed)bottom; \
    packed_data->args.a4 = (GLfixed)top; \
    packed_data->args.a5 = (GLfixed)near; \
    packed_data->args.a6 = (GLfixed)far; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGenBuffers
#define push_glGenBuffers(n, buffers) { \
    glGenBuffers_PACKED *packed_data = malloc(sizeof(glGenBuffers_PACKED)); \
    packed_data->format = glGenBuffers_FORMAT; \
    packed_data->func = glshim_glGenBuffers; \
    packed_data->args.a1 = (GLsizei)n; \
    packed_data->args.a2 = (GLuint *)buffers; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGenFramebuffers
#define push_glGenFramebuffers(n, ids) { \
    glGenFramebuffers_PACKED *packed_data = malloc(sizeof(glGenFramebuffers_PACKED)); \
    packed_data->format = glGenFramebuffers_FORMAT; \
    packed_data->func = glshim_glGenFramebuffers; \
    packed_data->args.a1 = (GLsizei)n; \
    packed_data->args.a2 = (GLuint *)ids; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGenRenderbuffers
#define push_glGenRenderbuffers(n, renderbuffers) { \
    glGenRenderbuffers_PACKED *packed_data = malloc(sizeof(glGenRenderbuffers_PACKED)); \
    packed_data->format = glGenRenderbuffers_FORMAT; \
    packed_data->func = glshim_glGenRenderbuffers; \
    packed_data->args.a1 = (GLsizei)n; \
    packed_data->args.a2 = (GLuint *)renderbuffers; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGenTextures
#define push_glGenTextures(n, textures) { \
    glGenTextures_PACKED *packed_data = malloc(sizeof(glGenTextures_PACKED)); \
    packed_data->format = glGenTextures_FORMAT; \
    packed_data->func = glshim_glGenTextures; \
    packed_data->args.a1 = (GLsizei)n; \
    packed_data->args.a2 = (GLuint *)textures; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGenerateMipmap
#define push_glGenerateMipmap(target) { \
    glGenerateMipmap_PACKED *packed_data = malloc(sizeof(glGenerateMipmap_PACKED)); \
    packed_data->format = glGenerateMipmap_FORMAT; \
    packed_data->func = glshim_glGenerateMipmap; \
    packed_data->args.a1 = (GLenum)target; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGetBooleanv
#define push_glGetBooleanv(pname, params) { \
    glGetBooleanv_PACKED *packed_data = malloc(sizeof(glGetBooleanv_PACKED)); \
    packed_data->format = glGetBooleanv_FORMAT; \
    packed_data->func = glshim_glGetBooleanv; \
    packed_data->args.a1 = (GLenum)pname; \
    packed_data->args.a2 = (GLboolean *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGetBufferParameteriv
#define push_glGetBufferParameteriv(target, pname, params) { \
    glGetBufferParameteriv_PACKED *packed_data = malloc(sizeof(glGetBufferParameteriv_PACKED)); \
    packed_data->format = glGetBufferParameteriv_FORMAT; \
    packed_data->func = glshim_glGetBufferParameteriv; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLint *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGetClipPlanef
#define push_glGetClipPlanef(plane, equation) { \
    glGetClipPlanef_PACKED *packed_data = malloc(sizeof(glGetClipPlanef_PACKED)); \
    packed_data->format = glGetClipPlanef_FORMAT; \
    packed_data->func = glshim_glGetClipPlanef; \
    packed_data->args.a1 = (GLenum)plane; \
    packed_data->args.a2 = (GLfloat *)equation; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGetClipPlanex
#define push_glGetClipPlanex(plane, equation) { \
    glGetClipPlanex_PACKED *packed_data = malloc(sizeof(glGetClipPlanex_PACKED)); \
    packed_data->format = glGetClipPlanex_FORMAT; \
    packed_data->func = glshim_glGetClipPlanex; \
    packed_data->args.a1 = (GLenum)plane; \
    packed_data->args.a2 = (GLfixed *)equation; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGetError
#define push_glGetError() { \
    glGetError_PACKED *packed_data = malloc(sizeof(glGetError_PACKED)); \
    packed_data->format = glGetError_FORMAT; \
    packed_data->func = glshim_glGetError; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGetFixedv
#define push_glGetFixedv(pname, params) { \
    glGetFixedv_PACKED *packed_data = malloc(sizeof(glGetFixedv_PACKED)); \
    packed_data->format = glGetFixedv_FORMAT; \
    packed_data->func = glshim_glGetFixedv; \
    packed_data->args.a1 = (GLenum)pname; \
    packed_data->args.a2 = (GLfixed *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGetFloatv
#define push_glGetFloatv(pname, params) { \
    glGetFloatv_PACKED *packed_data = malloc(sizeof(glGetFloatv_PACKED)); \
    packed_data->format = glGetFloatv_FORMAT; \
    packed_data->func = glshim_glGetFloatv; \
    packed_data->args.a1 = (GLenum)pname; \
    packed_data->args.a2 = (GLfloat *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGetFramebufferAttachmentParameteriv
#define push_glGetFramebufferAttachmentParameteriv(target, attachment, pname, params) { \
    glGetFramebufferAttachmentParameteriv_PACKED *packed_data = malloc(sizeof(glGetFramebufferAttachmentParameteriv_PACKED)); \
    packed_data->format = glGetFramebufferAttachmentParameteriv_FORMAT; \
    packed_data->func = glshim_glGetFramebufferAttachmentParameteriv; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLenum)attachment; \
    packed_data->args.a3 = (GLenum)pname; \
    packed_data->args.a4 = (GLint *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGetIntegerv
#define push_glGetIntegerv(pname, params) { \
    glGetIntegerv_PACKED *packed_data = malloc(sizeof(glGetIntegerv_PACKED)); \
    packed_data->format = glGetIntegerv_FORMAT; \
    packed_data->func = glshim_glGetIntegerv; \
    packed_data->args.a1 = (GLenum)pname; \
    packed_data->args.a2 = (GLint *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGetLightfv
#define push_glGetLightfv(light, pname, params) { \
    glGetLightfv_PACKED *packed_data = malloc(sizeof(glGetLightfv_PACKED)); \
    packed_data->format = glGetLightfv_FORMAT; \
    packed_data->func = glshim_glGetLightfv; \
    packed_data->args.a1 = (GLenum)light; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLfloat *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGetLightxv
#define push_glGetLightxv(light, pname, params) { \
    glGetLightxv_PACKED *packed_data = malloc(sizeof(glGetLightxv_PACKED)); \
    packed_data->format = glGetLightxv_FORMAT; \
    packed_data->func = glshim_glGetLightxv; \
    packed_data->args.a1 = (GLenum)light; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLfixed *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGetMaterialfv
#define push_glGetMaterialfv(face, pname, params) { \
    glGetMaterialfv_PACKED *packed_data = malloc(sizeof(glGetMaterialfv_PACKED)); \
    packed_data->format = glGetMaterialfv_FORMAT; \
    packed_data->func = glshim_glGetMaterialfv; \
    packed_data->args.a1 = (GLenum)face; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLfloat *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGetMaterialxv
#define push_glGetMaterialxv(face, pname, params) { \
    glGetMaterialxv_PACKED *packed_data = malloc(sizeof(glGetMaterialxv_PACKED)); \
    packed_data->format = glGetMaterialxv_FORMAT; \
    packed_data->func = glshim_glGetMaterialxv; \
    packed_data->args.a1 = (GLenum)face; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLfixed *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGetPointerv
#define push_glGetPointerv(pname, params) { \
    glGetPointerv_PACKED *packed_data = malloc(sizeof(glGetPointerv_PACKED)); \
    packed_data->format = glGetPointerv_FORMAT; \
    packed_data->func = glshim_glGetPointerv; \
    packed_data->args.a1 = (GLenum)pname; \
    packed_data->args.a2 = (GLvoid **)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGetRenderbufferParameteriv
#define push_glGetRenderbufferParameteriv(target, pname, params) { \
    glGetRenderbufferParameteriv_PACKED *packed_data = malloc(sizeof(glGetRenderbufferParameteriv_PACKED)); \
    packed_data->format = glGetRenderbufferParameteriv_FORMAT; \
    packed_data->func = glshim_glGetRenderbufferParameteriv; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLint *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGetString
#define push_glGetString(name) { \
    glGetString_PACKED *packed_data = malloc(sizeof(glGetString_PACKED)); \
    packed_data->format = glGetString_FORMAT; \
    packed_data->func = glshim_glGetString; \
    packed_data->args.a1 = (GLenum)name; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGetTexEnvfv
#define push_glGetTexEnvfv(target, pname, params) { \
    glGetTexEnvfv_PACKED *packed_data = malloc(sizeof(glGetTexEnvfv_PACKED)); \
    packed_data->format = glGetTexEnvfv_FORMAT; \
    packed_data->func = glshim_glGetTexEnvfv; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLfloat *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGetTexEnviv
#define push_glGetTexEnviv(target, pname, params) { \
    glGetTexEnviv_PACKED *packed_data = malloc(sizeof(glGetTexEnviv_PACKED)); \
    packed_data->format = glGetTexEnviv_FORMAT; \
    packed_data->func = glshim_glGetTexEnviv; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLint *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGetTexEnvxv
#define push_glGetTexEnvxv(target, pname, params) { \
    glGetTexEnvxv_PACKED *packed_data = malloc(sizeof(glGetTexEnvxv_PACKED)); \
    packed_data->format = glGetTexEnvxv_FORMAT; \
    packed_data->func = glshim_glGetTexEnvxv; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLfixed *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGetTexParameterfv
#define push_glGetTexParameterfv(target, pname, params) { \
    glGetTexParameterfv_PACKED *packed_data = malloc(sizeof(glGetTexParameterfv_PACKED)); \
    packed_data->format = glGetTexParameterfv_FORMAT; \
    packed_data->func = glshim_glGetTexParameterfv; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLfloat *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGetTexParameteriv
#define push_glGetTexParameteriv(target, pname, params) { \
    glGetTexParameteriv_PACKED *packed_data = malloc(sizeof(glGetTexParameteriv_PACKED)); \
    packed_data->format = glGetTexParameteriv_FORMAT; \
    packed_data->func = glshim_glGetTexParameteriv; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLint *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glGetTexParameterxv
#define push_glGetTexParameterxv(target, pname, params) { \
    glGetTexParameterxv_PACKED *packed_data = malloc(sizeof(glGetTexParameterxv_PACKED)); \
    packed_data->format = glGetTexParameterxv_FORMAT; \
    packed_data->func = glshim_glGetTexParameterxv; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLfixed *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glHint
#define push_glHint(target, mode) { \
    glHint_PACKED *packed_data = malloc(sizeof(glHint_PACKED)); \
    packed_data->format = glHint_FORMAT; \
    packed_data->func = glshim_glHint; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLenum)mode; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glIsBuffer
#define push_glIsBuffer(buffer) { \
    glIsBuffer_PACKED *packed_data = malloc(sizeof(glIsBuffer_PACKED)); \
    packed_data->format = glIsBuffer_FORMAT; \
    packed_data->func = glshim_glIsBuffer; \
    packed_data->args.a1 = (GLuint)buffer; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glIsEnabled
#define push_glIsEnabled(cap) { \
    glIsEnabled_PACKED *packed_data = malloc(sizeof(glIsEnabled_PACKED)); \
    packed_data->format = glIsEnabled_FORMAT; \
    packed_data->func = glshim_glIsEnabled; \
    packed_data->args.a1 = (GLenum)cap; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glIsFramebuffer
#define push_glIsFramebuffer(framebuffer) { \
    glIsFramebuffer_PACKED *packed_data = malloc(sizeof(glIsFramebuffer_PACKED)); \
    packed_data->format = glIsFramebuffer_FORMAT; \
    packed_data->func = glshim_glIsFramebuffer; \
    packed_data->args.a1 = (GLuint)framebuffer; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glIsRenderbuffer
#define push_glIsRenderbuffer(renderbuffer) { \
    glIsRenderbuffer_PACKED *packed_data = malloc(sizeof(glIsRenderbuffer_PACKED)); \
    packed_data->format = glIsRenderbuffer_FORMAT; \
    packed_data->func = glshim_glIsRenderbuffer; \
    packed_data->args.a1 = (GLuint)renderbuffer; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glIsTexture
#define push_glIsTexture(texture) { \
    glIsTexture_PACKED *packed_data = malloc(sizeof(glIsTexture_PACKED)); \
    packed_data->format = glIsTexture_FORMAT; \
    packed_data->func = glshim_glIsTexture; \
    packed_data->args.a1 = (GLuint)texture; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glLightModelf
#define push_glLightModelf(pname, param) { \
    glLightModelf_PACKED *packed_data = malloc(sizeof(glLightModelf_PACKED)); \
    packed_data->format = glLightModelf_FORMAT; \
    packed_data->func = glshim_glLightModelf; \
    packed_data->args.a1 = (GLenum)pname; \
    packed_data->args.a2 = (GLfloat)param; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glLightModelfv
#define push_glLightModelfv(pname, params) { \
    glLightModelfv_PACKED *packed_data = malloc(sizeof(glLightModelfv_PACKED)); \
    packed_data->format = glLightModelfv_FORMAT; \
    packed_data->func = glshim_glLightModelfv; \
    packed_data->args.a1 = (GLenum)pname; \
    packed_data->args.a2 = (GLfloat *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glLightModelx
#define push_glLightModelx(pname, param) { \
    glLightModelx_PACKED *packed_data = malloc(sizeof(glLightModelx_PACKED)); \
    packed_data->format = glLightModelx_FORMAT; \
    packed_data->func = glshim_glLightModelx; \
    packed_data->args.a1 = (GLenum)pname; \
    packed_data->args.a2 = (GLfixed)param; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glLightModelxv
#define push_glLightModelxv(pname, params) { \
    glLightModelxv_PACKED *packed_data = malloc(sizeof(glLightModelxv_PACKED)); \
    packed_data->format = glLightModelxv_FORMAT; \
    packed_data->func = glshim_glLightModelxv; \
    packed_data->args.a1 = (GLenum)pname; \
    packed_data->args.a2 = (GLfixed *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glLightf
#define push_glLightf(light, pname, param) { \
    glLightf_PACKED *packed_data = malloc(sizeof(glLightf_PACKED)); \
    packed_data->format = glLightf_FORMAT; \
    packed_data->func = glshim_glLightf; \
    packed_data->args.a1 = (GLenum)light; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLfloat)param; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glLightfv
#define push_glLightfv(light, pname, params) { \
    glLightfv_PACKED *packed_data = malloc(sizeof(glLightfv_PACKED)); \
    packed_data->format = glLightfv_FORMAT; \
    packed_data->func = glshim_glLightfv; \
    packed_data->args.a1 = (GLenum)light; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLfloat *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glLightx
#define push_glLightx(light, pname, param) { \
    glLightx_PACKED *packed_data = malloc(sizeof(glLightx_PACKED)); \
    packed_data->format = glLightx_FORMAT; \
    packed_data->func = glshim_glLightx; \
    packed_data->args.a1 = (GLenum)light; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLfixed)param; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glLightxv
#define push_glLightxv(light, pname, params) { \
    glLightxv_PACKED *packed_data = malloc(sizeof(glLightxv_PACKED)); \
    packed_data->format = glLightxv_FORMAT; \
    packed_data->func = glshim_glLightxv; \
    packed_data->args.a1 = (GLenum)light; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLfixed *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glLineWidth
#define push_glLineWidth(width) { \
    glLineWidth_PACKED *packed_data = malloc(sizeof(glLineWidth_PACKED)); \
    packed_data->format = glLineWidth_FORMAT; \
    packed_data->func = glshim_glLineWidth; \
    packed_data->args.a1 = (GLfloat)width; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glLineWidthx
#define push_glLineWidthx(width) { \
    glLineWidthx_PACKED *packed_data = malloc(sizeof(glLineWidthx_PACKED)); \
    packed_data->format = glLineWidthx_FORMAT; \
    packed_data->func = glshim_glLineWidthx; \
    packed_data->args.a1 = (GLfixed)width; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glLoadIdentity
#define push_glLoadIdentity() { \
    glLoadIdentity_PACKED *packed_data = malloc(sizeof(glLoadIdentity_PACKED)); \
    packed_data->format = glLoadIdentity_FORMAT; \
    packed_data->func = glshim_glLoadIdentity; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glLoadMatrixf
#define push_glLoadMatrixf(m) { \
    glLoadMatrixf_PACKED *packed_data = malloc(sizeof(glLoadMatrixf_PACKED)); \
    packed_data->format = glLoadMatrixf_FORMAT; \
    packed_data->func = glshim_glLoadMatrixf; \
    packed_data->args.a1 = (GLfloat *)m; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glLoadMatrixx
#define push_glLoadMatrixx(m) { \
    glLoadMatrixx_PACKED *packed_data = malloc(sizeof(glLoadMatrixx_PACKED)); \
    packed_data->format = glLoadMatrixx_FORMAT; \
    packed_data->func = glshim_glLoadMatrixx; \
    packed_data->args.a1 = (GLfixed *)m; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glLogicOp
#define push_glLogicOp(opcode) { \
    glLogicOp_PACKED *packed_data = malloc(sizeof(glLogicOp_PACKED)); \
    packed_data->format = glLogicOp_FORMAT; \
    packed_data->func = glshim_glLogicOp; \
    packed_data->args.a1 = (GLenum)opcode; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glMaterialf
#define push_glMaterialf(face, pname, param) { \
    glMaterialf_PACKED *packed_data = malloc(sizeof(glMaterialf_PACKED)); \
    packed_data->format = glMaterialf_FORMAT; \
    packed_data->func = glshim_glMaterialf; \
    packed_data->args.a1 = (GLenum)face; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLfloat)param; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glMaterialfv
#define push_glMaterialfv(face, pname, params) { \
    glMaterialfv_PACKED *packed_data = malloc(sizeof(glMaterialfv_PACKED)); \
    packed_data->format = glMaterialfv_FORMAT; \
    packed_data->func = glshim_glMaterialfv; \
    packed_data->args.a1 = (GLenum)face; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLfloat *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glMaterialx
#define push_glMaterialx(face, pname, param) { \
    glMaterialx_PACKED *packed_data = malloc(sizeof(glMaterialx_PACKED)); \
    packed_data->format = glMaterialx_FORMAT; \
    packed_data->func = glshim_glMaterialx; \
    packed_data->args.a1 = (GLenum)face; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLfixed)param; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glMaterialxv
#define push_glMaterialxv(face, pname, params) { \
    glMaterialxv_PACKED *packed_data = malloc(sizeof(glMaterialxv_PACKED)); \
    packed_data->format = glMaterialxv_FORMAT; \
    packed_data->func = glshim_glMaterialxv; \
    packed_data->args.a1 = (GLenum)face; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLfixed *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glMatrixMode
#define push_glMatrixMode(mode) { \
    glMatrixMode_PACKED *packed_data = malloc(sizeof(glMatrixMode_PACKED)); \
    packed_data->format = glMatrixMode_FORMAT; \
    packed_data->func = glshim_glMatrixMode; \
    packed_data->args.a1 = (GLenum)mode; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glMultMatrixf
#define push_glMultMatrixf(m) { \
    glMultMatrixf_PACKED *packed_data = malloc(sizeof(glMultMatrixf_PACKED)); \
    packed_data->format = glMultMatrixf_FORMAT; \
    packed_data->func = glshim_glMultMatrixf; \
    packed_data->args.a1 = (GLfloat *)m; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glMultMatrixx
#define push_glMultMatrixx(m) { \
    glMultMatrixx_PACKED *packed_data = malloc(sizeof(glMultMatrixx_PACKED)); \
    packed_data->format = glMultMatrixx_FORMAT; \
    packed_data->func = glshim_glMultMatrixx; \
    packed_data->args.a1 = (GLfixed *)m; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glMultiTexCoord4f
#define push_glMultiTexCoord4f(target, s, t, r, q) { \
    glMultiTexCoord4f_PACKED *packed_data = malloc(sizeof(glMultiTexCoord4f_PACKED)); \
    packed_data->format = glMultiTexCoord4f_FORMAT; \
    packed_data->func = glshim_glMultiTexCoord4f; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLfloat)s; \
    packed_data->args.a3 = (GLfloat)t; \
    packed_data->args.a4 = (GLfloat)r; \
    packed_data->args.a5 = (GLfloat)q; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glMultiTexCoord4x
#define push_glMultiTexCoord4x(target, s, t, r, q) { \
    glMultiTexCoord4x_PACKED *packed_data = malloc(sizeof(glMultiTexCoord4x_PACKED)); \
    packed_data->format = glMultiTexCoord4x_FORMAT; \
    packed_data->func = glshim_glMultiTexCoord4x; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLfixed)s; \
    packed_data->args.a3 = (GLfixed)t; \
    packed_data->args.a4 = (GLfixed)r; \
    packed_data->args.a5 = (GLfixed)q; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glNormal3f
#define push_glNormal3f(nx, ny, nz) { \
    glNormal3f_PACKED *packed_data = malloc(sizeof(glNormal3f_PACKED)); \
    packed_data->format = glNormal3f_FORMAT; \
    packed_data->func = glshim_glNormal3f; \
    packed_data->args.a1 = (GLfloat)nx; \
    packed_data->args.a2 = (GLfloat)ny; \
    packed_data->args.a3 = (GLfloat)nz; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glNormal3x
#define push_glNormal3x(nx, ny, nz) { \
    glNormal3x_PACKED *packed_data = malloc(sizeof(glNormal3x_PACKED)); \
    packed_data->format = glNormal3x_FORMAT; \
    packed_data->func = glshim_glNormal3x; \
    packed_data->args.a1 = (GLfixed)nx; \
    packed_data->args.a2 = (GLfixed)ny; \
    packed_data->args.a3 = (GLfixed)nz; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glNormalPointer
#define push_glNormalPointer(type, stride, pointer) { \
    glNormalPointer_PACKED *packed_data = malloc(sizeof(glNormalPointer_PACKED)); \
    packed_data->format = glNormalPointer_FORMAT; \
    packed_data->func = glshim_glNormalPointer; \
    packed_data->args.a1 = (GLenum)type; \
    packed_data->args.a2 = (GLsizei)stride; \
    packed_data->args.a3 = (GLvoid *)pointer; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glOrthof
#define push_glOrthof(left, right, bottom, top, near, far) { \
    glOrthof_PACKED *packed_data = malloc(sizeof(glOrthof_PACKED)); \
    packed_data->format = glOrthof_FORMAT; \
    packed_data->func = glshim_glOrthof; \
    packed_data->args.a1 = (GLfloat)left; \
    packed_data->args.a2 = (GLfloat)right; \
    packed_data->args.a3 = (GLfloat)bottom; \
    packed_data->args.a4 = (GLfloat)top; \
    packed_data->args.a5 = (GLfloat)near; \
    packed_data->args.a6 = (GLfloat)far; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glOrthox
#define push_glOrthox(left, right, bottom, top, near, far) { \
    glOrthox_PACKED *packed_data = malloc(sizeof(glOrthox_PACKED)); \
    packed_data->format = glOrthox_FORMAT; \
    packed_data->func = glshim_glOrthox; \
    packed_data->args.a1 = (GLfixed)left; \
    packed_data->args.a2 = (GLfixed)right; \
    packed_data->args.a3 = (GLfixed)bottom; \
    packed_data->args.a4 = (GLfixed)top; \
    packed_data->args.a5 = (GLfixed)near; \
    packed_data->args.a6 = (GLfixed)far; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glPixelStorei
#define push_glPixelStorei(pname, param) { \
    glPixelStorei_PACKED *packed_data = malloc(sizeof(glPixelStorei_PACKED)); \
    packed_data->format = glPixelStorei_FORMAT; \
    packed_data->func = glshim_glPixelStorei; \
    packed_data->args.a1 = (GLenum)pname; \
    packed_data->args.a2 = (GLint)param; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glPointParameterf
#define push_glPointParameterf(pname, param) { \
    glPointParameterf_PACKED *packed_data = malloc(sizeof(glPointParameterf_PACKED)); \
    packed_data->format = glPointParameterf_FORMAT; \
    packed_data->func = glshim_glPointParameterf; \
    packed_data->args.a1 = (GLenum)pname; \
    packed_data->args.a2 = (GLfloat)param; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glPointParameterfv
#define push_glPointParameterfv(pname, params) { \
    glPointParameterfv_PACKED *packed_data = malloc(sizeof(glPointParameterfv_PACKED)); \
    packed_data->format = glPointParameterfv_FORMAT; \
    packed_data->func = glshim_glPointParameterfv; \
    packed_data->args.a1 = (GLenum)pname; \
    packed_data->args.a2 = (GLfloat *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glPointParameterx
#define push_glPointParameterx(pname, param) { \
    glPointParameterx_PACKED *packed_data = malloc(sizeof(glPointParameterx_PACKED)); \
    packed_data->format = glPointParameterx_FORMAT; \
    packed_data->func = glshim_glPointParameterx; \
    packed_data->args.a1 = (GLenum)pname; \
    packed_data->args.a2 = (GLfixed)param; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glPointParameterxv
#define push_glPointParameterxv(pname, params) { \
    glPointParameterxv_PACKED *packed_data = malloc(sizeof(glPointParameterxv_PACKED)); \
    packed_data->format = glPointParameterxv_FORMAT; \
    packed_data->func = glshim_glPointParameterxv; \
    packed_data->args.a1 = (GLenum)pname; \
    packed_data->args.a2 = (GLfixed *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glPointSize
#define push_glPointSize(size) { \
    glPointSize_PACKED *packed_data = malloc(sizeof(glPointSize_PACKED)); \
    packed_data->format = glPointSize_FORMAT; \
    packed_data->func = glshim_glPointSize; \
    packed_data->args.a1 = (GLfloat)size; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glPointSizePointerOES
#define push_glPointSizePointerOES(type, stride, pointer) { \
    glPointSizePointerOES_PACKED *packed_data = malloc(sizeof(glPointSizePointerOES_PACKED)); \
    packed_data->format = glPointSizePointerOES_FORMAT; \
    packed_data->func = glshim_glPointSizePointerOES; \
    packed_data->args.a1 = (GLenum)type; \
    packed_data->args.a2 = (GLsizei)stride; \
    packed_data->args.a3 = (GLvoid *)pointer; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glPointSizex
#define push_glPointSizex(size) { \
    glPointSizex_PACKED *packed_data = malloc(sizeof(glPointSizex_PACKED)); \
    packed_data->format = glPointSizex_FORMAT; \
    packed_data->func = glshim_glPointSizex; \
    packed_data->args.a1 = (GLfixed)size; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glPolygonOffset
#define push_glPolygonOffset(factor, units) { \
    glPolygonOffset_PACKED *packed_data = malloc(sizeof(glPolygonOffset_PACKED)); \
    packed_data->format = glPolygonOffset_FORMAT; \
    packed_data->func = glshim_glPolygonOffset; \
    packed_data->args.a1 = (GLfloat)factor; \
    packed_data->args.a2 = (GLfloat)units; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glPolygonOffsetx
#define push_glPolygonOffsetx(factor, units) { \
    glPolygonOffsetx_PACKED *packed_data = malloc(sizeof(glPolygonOffsetx_PACKED)); \
    packed_data->format = glPolygonOffsetx_FORMAT; \
    packed_data->func = glshim_glPolygonOffsetx; \
    packed_data->args.a1 = (GLfixed)factor; \
    packed_data->args.a2 = (GLfixed)units; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glPopMatrix
#define push_glPopMatrix() { \
    glPopMatrix_PACKED *packed_data = malloc(sizeof(glPopMatrix_PACKED)); \
    packed_data->format = glPopMatrix_FORMAT; \
    packed_data->func = glshim_glPopMatrix; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glPushMatrix
#define push_glPushMatrix() { \
    glPushMatrix_PACKED *packed_data = malloc(sizeof(glPushMatrix_PACKED)); \
    packed_data->format = glPushMatrix_FORMAT; \
    packed_data->func = glshim_glPushMatrix; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glReadPixels
#define push_glReadPixels(x, y, width, height, format, type, pixels) { \
    glReadPixels_PACKED *packed_data = malloc(sizeof(glReadPixels_PACKED)); \
    packed_data->format = glReadPixels_FORMAT; \
    packed_data->func = glshim_glReadPixels; \
    packed_data->args.a1 = (GLint)x; \
    packed_data->args.a2 = (GLint)y; \
    packed_data->args.a3 = (GLsizei)width; \
    packed_data->args.a4 = (GLsizei)height; \
    packed_data->args.a5 = (GLenum)format; \
    packed_data->args.a6 = (GLenum)type; \
    packed_data->args.a7 = (GLvoid *)pixels; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glRenderbufferStorage
#define push_glRenderbufferStorage(target, internalformat, width, height) { \
    glRenderbufferStorage_PACKED *packed_data = malloc(sizeof(glRenderbufferStorage_PACKED)); \
    packed_data->format = glRenderbufferStorage_FORMAT; \
    packed_data->func = glshim_glRenderbufferStorage; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLenum)internalformat; \
    packed_data->args.a3 = (GLsizei)width; \
    packed_data->args.a4 = (GLsizei)height; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glRotatef
#define push_glRotatef(angle, x, y, z) { \
    glRotatef_PACKED *packed_data = malloc(sizeof(glRotatef_PACKED)); \
    packed_data->format = glRotatef_FORMAT; \
    packed_data->func = glshim_glRotatef; \
    packed_data->args.a1 = (GLfloat)angle; \
    packed_data->args.a2 = (GLfloat)x; \
    packed_data->args.a3 = (GLfloat)y; \
    packed_data->args.a4 = (GLfloat)z; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glRotatex
#define push_glRotatex(angle, x, y, z) { \
    glRotatex_PACKED *packed_data = malloc(sizeof(glRotatex_PACKED)); \
    packed_data->format = glRotatex_FORMAT; \
    packed_data->func = glshim_glRotatex; \
    packed_data->args.a1 = (GLfixed)angle; \
    packed_data->args.a2 = (GLfixed)x; \
    packed_data->args.a3 = (GLfixed)y; \
    packed_data->args.a4 = (GLfixed)z; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glSampleCoverage
#define push_glSampleCoverage(value, invert) { \
    glSampleCoverage_PACKED *packed_data = malloc(sizeof(glSampleCoverage_PACKED)); \
    packed_data->format = glSampleCoverage_FORMAT; \
    packed_data->func = glshim_glSampleCoverage; \
    packed_data->args.a1 = (GLclampf)value; \
    packed_data->args.a2 = (GLboolean)invert; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glSampleCoveragex
#define push_glSampleCoveragex(value, invert) { \
    glSampleCoveragex_PACKED *packed_data = malloc(sizeof(glSampleCoveragex_PACKED)); \
    packed_data->format = glSampleCoveragex_FORMAT; \
    packed_data->func = glshim_glSampleCoveragex; \
    packed_data->args.a1 = (GLclampx)value; \
    packed_data->args.a2 = (GLboolean)invert; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glScalef
#define push_glScalef(x, y, z) { \
    glScalef_PACKED *packed_data = malloc(sizeof(glScalef_PACKED)); \
    packed_data->format = glScalef_FORMAT; \
    packed_data->func = glshim_glScalef; \
    packed_data->args.a1 = (GLfloat)x; \
    packed_data->args.a2 = (GLfloat)y; \
    packed_data->args.a3 = (GLfloat)z; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glScalex
#define push_glScalex(x, y, z) { \
    glScalex_PACKED *packed_data = malloc(sizeof(glScalex_PACKED)); \
    packed_data->format = glScalex_FORMAT; \
    packed_data->func = glshim_glScalex; \
    packed_data->args.a1 = (GLfixed)x; \
    packed_data->args.a2 = (GLfixed)y; \
    packed_data->args.a3 = (GLfixed)z; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glScissor
#define push_glScissor(x, y, width, height) { \
    glScissor_PACKED *packed_data = malloc(sizeof(glScissor_PACKED)); \
    packed_data->format = glScissor_FORMAT; \
    packed_data->func = glshim_glScissor; \
    packed_data->args.a1 = (GLint)x; \
    packed_data->args.a2 = (GLint)y; \
    packed_data->args.a3 = (GLsizei)width; \
    packed_data->args.a4 = (GLsizei)height; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glShadeModel
#define push_glShadeModel(mode) { \
    glShadeModel_PACKED *packed_data = malloc(sizeof(glShadeModel_PACKED)); \
    packed_data->format = glShadeModel_FORMAT; \
    packed_data->func = glshim_glShadeModel; \
    packed_data->args.a1 = (GLenum)mode; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glStencilFunc
#define push_glStencilFunc(func, ref, mask) { \
    glStencilFunc_PACKED *packed_data = malloc(sizeof(glStencilFunc_PACKED)); \
    packed_data->format = glStencilFunc_FORMAT; \
    packed_data->func = glshim_glStencilFunc; \
    packed_data->args.a1 = (GLenum)func; \
    packed_data->args.a2 = (GLint)ref; \
    packed_data->args.a3 = (GLuint)mask; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glStencilMask
#define push_glStencilMask(mask) { \
    glStencilMask_PACKED *packed_data = malloc(sizeof(glStencilMask_PACKED)); \
    packed_data->format = glStencilMask_FORMAT; \
    packed_data->func = glshim_glStencilMask; \
    packed_data->args.a1 = (GLuint)mask; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glStencilOp
#define push_glStencilOp(fail, zfail, zpass) { \
    glStencilOp_PACKED *packed_data = malloc(sizeof(glStencilOp_PACKED)); \
    packed_data->format = glStencilOp_FORMAT; \
    packed_data->func = glshim_glStencilOp; \
    packed_data->args.a1 = (GLenum)fail; \
    packed_data->args.a2 = (GLenum)zfail; \
    packed_data->args.a3 = (GLenum)zpass; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glTexCoordPointer
#define push_glTexCoordPointer(size, type, stride, pointer) { \
    glTexCoordPointer_PACKED *packed_data = malloc(sizeof(glTexCoordPointer_PACKED)); \
    packed_data->format = glTexCoordPointer_FORMAT; \
    packed_data->func = glshim_glTexCoordPointer; \
    packed_data->args.a1 = (GLint)size; \
    packed_data->args.a2 = (GLenum)type; \
    packed_data->args.a3 = (GLsizei)stride; \
    packed_data->args.a4 = (GLvoid *)pointer; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glTexEnvf
#define push_glTexEnvf(target, pname, param) { \
    glTexEnvf_PACKED *packed_data = malloc(sizeof(glTexEnvf_PACKED)); \
    packed_data->format = glTexEnvf_FORMAT; \
    packed_data->func = glshim_glTexEnvf; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLfloat)param; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glTexEnvfv
#define push_glTexEnvfv(target, pname, params) { \
    glTexEnvfv_PACKED *packed_data = malloc(sizeof(glTexEnvfv_PACKED)); \
    packed_data->format = glTexEnvfv_FORMAT; \
    packed_data->func = glshim_glTexEnvfv; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLfloat *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glTexEnvi
#define push_glTexEnvi(target, pname, param) { \
    glTexEnvi_PACKED *packed_data = malloc(sizeof(glTexEnvi_PACKED)); \
    packed_data->format = glTexEnvi_FORMAT; \
    packed_data->func = glshim_glTexEnvi; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLint)param; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glTexEnviv
#define push_glTexEnviv(target, pname, params) { \
    glTexEnviv_PACKED *packed_data = malloc(sizeof(glTexEnviv_PACKED)); \
    packed_data->format = glTexEnviv_FORMAT; \
    packed_data->func = glshim_glTexEnviv; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLint *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glTexEnvx
#define push_glTexEnvx(target, pname, param) { \
    glTexEnvx_PACKED *packed_data = malloc(sizeof(glTexEnvx_PACKED)); \
    packed_data->format = glTexEnvx_FORMAT; \
    packed_data->func = glshim_glTexEnvx; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLfixed)param; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glTexEnvxv
#define push_glTexEnvxv(target, pname, params) { \
    glTexEnvxv_PACKED *packed_data = malloc(sizeof(glTexEnvxv_PACKED)); \
    packed_data->format = glTexEnvxv_FORMAT; \
    packed_data->func = glshim_glTexEnvxv; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLfixed *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glTexGenfv
#define push_glTexGenfv(coord, pname, params) { \
    glTexGenfv_PACKED *packed_data = malloc(sizeof(glTexGenfv_PACKED)); \
    packed_data->format = glTexGenfv_FORMAT; \
    packed_data->func = glshim_glTexGenfv; \
    packed_data->args.a1 = (GLenum)coord; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLfloat *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glTexGeni
#define push_glTexGeni(coord, pname, param) { \
    glTexGeni_PACKED *packed_data = malloc(sizeof(glTexGeni_PACKED)); \
    packed_data->format = glTexGeni_FORMAT; \
    packed_data->func = glshim_glTexGeni; \
    packed_data->args.a1 = (GLenum)coord; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLint)param; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glTexImage2D
#define push_glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels) { \
    glTexImage2D_PACKED *packed_data = malloc(sizeof(glTexImage2D_PACKED)); \
    packed_data->format = glTexImage2D_FORMAT; \
    packed_data->func = glshim_glTexImage2D; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLint)level; \
    packed_data->args.a3 = (GLint)internalformat; \
    packed_data->args.a4 = (GLsizei)width; \
    packed_data->args.a5 = (GLsizei)height; \
    packed_data->args.a6 = (GLint)border; \
    packed_data->args.a7 = (GLenum)format; \
    packed_data->args.a8 = (GLenum)type; \
    packed_data->args.a9 = (GLvoid *)pixels; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glTexParameterf
#define push_glTexParameterf(target, pname, param) { \
    glTexParameterf_PACKED *packed_data = malloc(sizeof(glTexParameterf_PACKED)); \
    packed_data->format = glTexParameterf_FORMAT; \
    packed_data->func = glshim_glTexParameterf; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLfloat)param; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glTexParameterfv
#define push_glTexParameterfv(target, pname, params) { \
    glTexParameterfv_PACKED *packed_data = malloc(sizeof(glTexParameterfv_PACKED)); \
    packed_data->format = glTexParameterfv_FORMAT; \
    packed_data->func = glshim_glTexParameterfv; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLfloat *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glTexParameteri
#define push_glTexParameteri(target, pname, param) { \
    glTexParameteri_PACKED *packed_data = malloc(sizeof(glTexParameteri_PACKED)); \
    packed_data->format = glTexParameteri_FORMAT; \
    packed_data->func = glshim_glTexParameteri; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLint)param; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glTexParameteriv
#define push_glTexParameteriv(target, pname, params) { \
    glTexParameteriv_PACKED *packed_data = malloc(sizeof(glTexParameteriv_PACKED)); \
    packed_data->format = glTexParameteriv_FORMAT; \
    packed_data->func = glshim_glTexParameteriv; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLint *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glTexParameterx
#define push_glTexParameterx(target, pname, param) { \
    glTexParameterx_PACKED *packed_data = malloc(sizeof(glTexParameterx_PACKED)); \
    packed_data->format = glTexParameterx_FORMAT; \
    packed_data->func = glshim_glTexParameterx; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLfixed)param; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glTexParameterxv
#define push_glTexParameterxv(target, pname, params) { \
    glTexParameterxv_PACKED *packed_data = malloc(sizeof(glTexParameterxv_PACKED)); \
    packed_data->format = glTexParameterxv_FORMAT; \
    packed_data->func = glshim_glTexParameterxv; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLenum)pname; \
    packed_data->args.a3 = (GLfixed *)params; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glTexSubImage2D
#define push_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels) { \
    glTexSubImage2D_PACKED *packed_data = malloc(sizeof(glTexSubImage2D_PACKED)); \
    packed_data->format = glTexSubImage2D_FORMAT; \
    packed_data->func = glshim_glTexSubImage2D; \
    packed_data->args.a1 = (GLenum)target; \
    packed_data->args.a2 = (GLint)level; \
    packed_data->args.a3 = (GLint)xoffset; \
    packed_data->args.a4 = (GLint)yoffset; \
    packed_data->args.a5 = (GLsizei)width; \
    packed_data->args.a6 = (GLsizei)height; \
    packed_data->args.a7 = (GLenum)format; \
    packed_data->args.a8 = (GLenum)type; \
    packed_data->args.a9 = (GLvoid *)pixels; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glTranslatef
#define push_glTranslatef(x, y, z) { \
    glTranslatef_PACKED *packed_data = malloc(sizeof(glTranslatef_PACKED)); \
    packed_data->format = glTranslatef_FORMAT; \
    packed_data->func = glshim_glTranslatef; \
    packed_data->args.a1 = (GLfloat)x; \
    packed_data->args.a2 = (GLfloat)y; \
    packed_data->args.a3 = (GLfloat)z; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glTranslatex
#define push_glTranslatex(x, y, z) { \
    glTranslatex_PACKED *packed_data = malloc(sizeof(glTranslatex_PACKED)); \
    packed_data->format = glTranslatex_FORMAT; \
    packed_data->func = glshim_glTranslatex; \
    packed_data->args.a1 = (GLfixed)x; \
    packed_data->args.a2 = (GLfixed)y; \
    packed_data->args.a3 = (GLfixed)z; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glVertexPointer
#define push_glVertexPointer(size, type, stride, pointer) { \
    glVertexPointer_PACKED *packed_data = malloc(sizeof(glVertexPointer_PACKED)); \
    packed_data->format = glVertexPointer_FORMAT; \
    packed_data->func = glshim_glVertexPointer; \
    packed_data->args.a1 = (GLint)size; \
    packed_data->args.a2 = (GLenum)type; \
    packed_data->args.a3 = (GLsizei)stride; \
    packed_data->args.a4 = (GLvoid *)pointer; \
    glPushCall((void *)packed_data); \
}
#endif
#ifndef direct_glViewport
#define push_glViewport(x, y, width, height) { \
    glViewport_PACKED *packed_data = malloc(sizeof(glViewport_PACKED)); \
    packed_data->format = glViewport_FORMAT; \
    packed_data->func = glshim_glViewport; \
    packed_data->args.a1 = (GLint)x; \
    packed_data->args.a2 = (GLint)y; \
    packed_data->args.a3 = (GLsizei)width; \
    packed_data->args.a4 = (GLsizei)height; \
    glPushCall((void *)packed_data); \
}
#endif
#endif

#endif
