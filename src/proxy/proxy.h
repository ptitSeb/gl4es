#include <GL/gl.h>
#include <GL/glx.h>
#include <stdlib.h>
#include "../gl/defines.h"
#include "../config.h"
#include "config.h"

#ifndef PROXY_H
#define PROXY_H

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
    FORMAT_void_GLenum_GLfloat,
    FORMAT_void_GLenum,
    FORMAT_GLboolean_GLsizei_const_GLuint___GENPT___GLboolean___GENPT__,
    FORMAT_void_GLint,
    FORMAT_void_GLenum_GLuint,
    FORMAT_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_const_GLubyte___GENPT__,
    FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLenum_GLenum,
    FORMAT_void_GLenum_GLenum_GLenum_GLenum,
    FORMAT_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum,
    FORMAT_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__,
    FORMAT_void_GLuint,
    FORMAT_void_GLsizei_GLenum_const_GLvoid___GENPT__,
    FORMAT_void_GLbitfield,
    FORMAT_void_GLdouble,
    FORMAT_void_GLfloat,
    FORMAT_void_GLenum_const_GLdouble___GENPT__,
    FORMAT_void_GLbyte_GLbyte_GLbyte,
    FORMAT_void_const_GLbyte___GENPT__,
    FORMAT_void_GLdouble_GLdouble_GLdouble,
    FORMAT_void_const_GLdouble___GENPT__,
    FORMAT_void_GLfloat_GLfloat_GLfloat,
    FORMAT_void_const_GLfloat___GENPT__,
    FORMAT_void_GLint_GLint_GLint,
    FORMAT_void_const_GLint___GENPT__,
    FORMAT_void_GLshort_GLshort_GLshort,
    FORMAT_void_const_GLshort___GENPT__,
    FORMAT_void_GLubyte_GLubyte_GLubyte,
    FORMAT_void_const_GLubyte___GENPT__,
    FORMAT_void_GLuint_GLuint_GLuint,
    FORMAT_void_const_GLuint___GENPT__,
    FORMAT_void_GLushort_GLushort_GLushort,
    FORMAT_void_const_GLushort___GENPT__,
    FORMAT_void_GLbyte_GLbyte_GLbyte_GLbyte,
    FORMAT_void_GLdouble_GLdouble_GLdouble_GLdouble,
    FORMAT_void_GLint_GLint_GLint_GLint,
    FORMAT_void_GLshort_GLshort_GLshort_GLshort,
    FORMAT_void_GLubyte_GLubyte_GLubyte_GLubyte,
    FORMAT_void_GLuint_GLuint_GLuint_GLuint,
    FORMAT_void_GLushort_GLushort_GLushort_GLushort,
    FORMAT_void_GLboolean_GLboolean_GLboolean_GLboolean,
    FORMAT_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__,
    FORMAT_void_GLenum_GLenum_const_GLint___GENPT__,
    FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLenum_GLfloat,
    FORMAT_void_GLenum_GLenum_GLint,
    FORMAT_void_GLenum_GLsizei_GLint_GLint_GLsizei,
    FORMAT_void_GLenum_GLenum_GLint_GLint_GLsizei,
    FORMAT_void_GLenum_GLenum_GLint_GLint_GLsizei_GLsizei,
    FORMAT_void_GLint_GLint_GLsizei_GLsizei_GLenum,
    FORMAT_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint,
    FORMAT_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint,
    FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLsizei,
    FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei,
    FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei,
    FORMAT_void_GLsizei_const_GLuint___GENPT__,
    FORMAT_void_GLuint_GLsizei,
    FORMAT_void_GLboolean,
    FORMAT_void_GLdouble_GLdouble,
    FORMAT_void_GLenum_GLint_GLsizei,
    FORMAT_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__,
    FORMAT_void_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLuint_GLuint_GLsizei_GLenum_const_GLvoid___GENPT__,
    FORMAT_void_GLsizei_const_GLvoid___GENPT__,
    FORMAT_void_const_GLboolean___GENPT__,
    FORMAT_void,
    FORMAT_void_GLfloat_GLfloat,
    FORMAT_void_GLenum_GLint_GLint,
    FORMAT_void_GLenum_GLint_GLint_GLint_GLint,
    FORMAT_void_GLint_GLint,
    FORMAT_void_GLsizei_GLenum_GLfloat___GENPT__,
    FORMAT_void_GLenum_GLsizei_const_GLvoid___GENPT__,
    FORMAT_void_GLenum_const_GLfloat___GENPT__,
    FORMAT_void_GLenum_GLint,
    FORMAT_void_GLenum_const_GLint___GENPT__,
    FORMAT_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble,
    FORMAT_void_GLsizei_GLuint___GENPT__,
    FORMAT_GLuint_GLsizei,
    FORMAT_void_GLenum_GLboolean___GENPT__,
    FORMAT_void_GLenum_GLenum_GLint___GENPT__,
    FORMAT_void_GLenum_GLenum_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLintptr_GLsizeiptr_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLdouble___GENPT__,
    FORMAT_void_GLenum_GLenum_GLenum_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLenum_GLfloat___GENPT__,
    FORMAT_void_GLenum_GLint_GLvoid___GENPT__,
    FORMAT_GLenum,
    FORMAT_void_GLenum_GLfloat___GENPT__,
    FORMAT_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLint___GENPT__,
    FORMAT_void_GLenum_GLenum_GLdouble___GENPT__,
    FORMAT_void_GLenum_GLuint___GENPT__,
    FORMAT_void_GLenum_GLushort___GENPT__,
    FORMAT_void_GLenum_GLvoid___GENPT____GENPT__,
    FORMAT_void_GLubyte___GENPT__,
    FORMAT_void_GLuint_GLenum_GLint___GENPT__,
    FORMAT_void_GLuint_GLenum_GLuint___GENPT__,
    FORMAT_void_GLenum_GLenum_GLenum_GLvoid___GENPT___GLvoid___GENPT___GLvoid___GENPT__,
    FORMAT_const_GLubyte___GENPT___GLenum,
    FORMAT_void_GLenum_GLint_GLenum_GLenum_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLint_GLenum_GLfloat___GENPT__,
    FORMAT_void_GLenum_GLint_GLenum_GLint___GENPT__,
    FORMAT_void_GLenum_GLsizei_GLenum_GLboolean,
    FORMAT_void_GLshort,
    FORMAT_void_GLubyte,
    FORMAT_GLboolean_GLuint,
    FORMAT_GLboolean_GLenum,
    FORMAT_void_GLint_GLushort,
    FORMAT_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__,
    FORMAT_void_GLenum_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__,
    FORMAT_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__,
    FORMAT_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__,
    FORMAT_GLvoid___GENPT___GLenum_GLenum,
    FORMAT_void_GLint_GLdouble_GLdouble,
    FORMAT_void_GLint_GLfloat_GLfloat,
    FORMAT_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble,
    FORMAT_void_GLint_GLfloat_GLfloat_GLint_GLfloat_GLfloat,
    FORMAT_void_GLenum_GLenum_GLboolean,
    FORMAT_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei,
    FORMAT_void_GLenum_const_GLsizei___GENPT___GLenum_GLvoid__GENPT__const___GENPT___GLsizei,
    FORMAT_void_GLenum_GLdouble,
    FORMAT_void_GLenum_GLshort,
    FORMAT_void_GLenum_const_GLshort___GENPT__,
    FORMAT_void_GLenum_GLdouble_GLdouble,
    FORMAT_void_GLenum_GLfloat_GLfloat,
    FORMAT_void_GLenum_GLshort_GLshort,
    FORMAT_void_GLenum_GLdouble_GLdouble_GLdouble,
    FORMAT_void_GLenum_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLenum_GLint_GLint_GLint,
    FORMAT_void_GLenum_GLshort_GLshort_GLshort,
    FORMAT_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble,
    FORMAT_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLenum_GLshort_GLshort_GLshort_GLshort,
    FORMAT_void_GLuint_GLenum,
    FORMAT_void_GLenum_GLsizei_const_GLfloat___GENPT__,
    FORMAT_void_GLenum_GLsizei_const_GLuint___GENPT__,
    FORMAT_void_GLenum_GLsizei_const_GLushort___GENPT__,
    FORMAT_void_GLsizei_const_GLuint___GENPT___const_GLfloat___GENPT__,
    FORMAT_void_GLshort_GLshort,
    FORMAT_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__,
    FORMAT_void_const_GLdouble___GENPT___const_GLdouble___GENPT__,
    FORMAT_void_const_GLfloat___GENPT___const_GLfloat___GENPT__,
    FORMAT_void_const_GLint___GENPT___const_GLint___GENPT__,
    FORMAT_void_const_GLshort___GENPT___const_GLshort___GENPT__,
    FORMAT_GLint_GLenum,
    FORMAT_void_GLfloat_GLboolean,
    FORMAT_void_GLint_GLint_GLsizei_GLsizei,
    FORMAT_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT___const_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLint_GLuint,
    FORMAT_void_GLenum_GLenum_GLenum,
    FORMAT_void_GLenum_GLenum_GLdouble,
    FORMAT_void_GLenum_GLenum_const_GLdouble___GENPT__,
    FORMAT_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__,
    FORMAT_int_Display___GENPT___int,
    FORMAT_void_uint32_t_uint32_t,
    FORMAT_void_uint32_t,
    FORMAT_XVisualInfo___GENPT___Display___GENPT___int_int___GENPT__,
    FORMAT_void_Display___GENPT___GLXContext_GLXContext_unsigned_long,
    FORMAT_GLXContext_Display___GENPT___XVisualInfo___GENPT___GLXContext_Bool,
    FORMAT_void_uint32_t_uint32_t_uint32_t_uint32_t,
    FORMAT_GLXPixmap_Display___GENPT___XVisualInfo___GENPT___Pixmap,
    FORMAT_void_uint32_t_uint32_t_uint32_t,
    FORMAT_void_Display___GENPT___uint32_t_uint32_t_uint32_t_uint32_t_uint32_t,
    FORMAT_void_Display___GENPT___GLXContext,
    FORMAT_void_Display___GENPT___GLXPixmap,
    FORMAT_void_Display___GENPT___uint32_t,
    FORMAT_const_char___GENPT___Display___GENPT___int,
    FORMAT_int_Display___GENPT___XVisualInfo___GENPT___int_int___GENPT__,
    FORMAT_GLXContext,
    FORMAT_GLXDrawable,
    FORMAT_int_Display___GENPT___int_int_int_const_void___GENPT__,
    FORMAT_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__,
    FORMAT_Bool_Display___GENPT___GLXContext,
    FORMAT_Bool_Display___GENPT___GLXDrawable_GLXContext,
    FORMAT_Bool_Display___GENPT___int___GENPT___int___GENPT__,
    FORMAT_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__,
    FORMAT_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__,
    FORMAT_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__,
    FORMAT_const_char___GENPT___Display___GENPT___int_int,
    FORMAT_void_Display___GENPT___GLXDrawable,
    FORMAT_void_Font_int_int_int,
    FORMAT_GLXFBConfig___GENPT___Display___GENPT___int_const_int___GENPT___int___GENPT__,
    FORMAT_GLXContext_Display___GENPT___GLXFBConfig_int_GLXContext_Bool,
    FORMAT_GLXPbuffer_Display___GENPT___GLXFBConfig_const_int___GENPT__,
    FORMAT_GLXPixmap_Display___GENPT___GLXFBConfig_Pixmap_const_int___GENPT__,
    FORMAT_GLXWindow_Display___GENPT___GLXFBConfig_Window_const_int___GENPT__,
    FORMAT_void_Display___GENPT___GLXPbuffer,
    FORMAT_void_Display___GENPT___GLXWindow,
    FORMAT_Display___GENPT__,
    FORMAT_int_Display___GENPT___GLXFBConfig_int_int___GENPT__,
    FORMAT_GLXFBConfig___GENPT___Display___GENPT___int_int___GENPT__,
    FORMAT___GLXextFuncPtr_const_GLubyte___GENPT__,
    FORMAT_void_Display___GENPT___GLXDrawable_unsigned_long___GENPT__,
    FORMAT_XVisualInfo___GENPT___Display___GENPT___GLXFBConfig,
    FORMAT_Bool_Display___GENPT___GLXDrawable_GLXDrawable_GLXContext,
    FORMAT_int_Display___GENPT___GLXContext_int_int___GENPT__,
    FORMAT_void_Display___GENPT___GLXDrawable_int_unsigned_int___GENPT__,
    FORMAT_void_Display___GENPT___GLXDrawable_unsigned_long,
};

typedef void (*FUNC_void_GLenum_GLfloat)(GLenum op, GLfloat value);
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
typedef GLboolean (*FUNC_GLboolean_GLsizei_const_GLuint___GENPT___GLboolean___GENPT__)(GLsizei n, const GLuint * textures, GLboolean * residences);
typedef struct {
    GLsizei a1;
    const GLuint * a2;
    GLboolean * a3;
} ARGS_GLboolean_GLsizei_const_GLuint___GENPT___GLboolean___GENPT__;
typedef struct {
    int format;
    FUNC_GLboolean_GLsizei_const_GLuint___GENPT___GLboolean___GENPT__ func;
    ARGS_GLboolean_GLsizei_const_GLuint___GENPT___GLboolean___GENPT__ args;
} PACKED_GLboolean_GLsizei_const_GLuint___GENPT___GLboolean___GENPT__;
typedef struct {
    int func;
    ARGS_GLboolean_GLsizei_const_GLuint___GENPT___GLboolean___GENPT__ args;
} INDEXED_GLboolean_GLsizei_const_GLuint___GENPT___GLboolean___GENPT__;
typedef void (*FUNC_void_GLint)(GLint i);
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
typedef void (*FUNC_void_GLenum_GLuint)(GLenum target, GLuint id);
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
typedef void (*FUNC_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_const_GLubyte___GENPT__)(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte * bitmap);
typedef struct {
    GLsizei a1;
    GLsizei a2;
    GLfloat a3;
    GLfloat a4;
    GLfloat a5;
    GLfloat a6;
    const GLubyte * a7;
} ARGS_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_const_GLubyte___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_const_GLubyte___GENPT__ func;
    ARGS_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_const_GLubyte___GENPT__ args;
} PACKED_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_const_GLubyte___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_const_GLubyte___GENPT__ args;
} INDEXED_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_const_GLubyte___GENPT__;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum args;
} INDEXED_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__;
typedef void (*FUNC_void_GLuint)(GLuint list);
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
typedef void (*FUNC_void_GLsizei_GLenum_const_GLvoid___GENPT__)(GLsizei n, GLenum type, const GLvoid * lists);
typedef struct {
    GLsizei a1;
    GLenum a2;
    const GLvoid * a3;
} ARGS_void_GLsizei_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLenum_const_GLvoid___GENPT__ func;
    ARGS_void_GLsizei_GLenum_const_GLvoid___GENPT__ args;
} PACKED_void_GLsizei_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLsizei_GLenum_const_GLvoid___GENPT__ args;
} INDEXED_void_GLsizei_GLenum_const_GLvoid___GENPT__;
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
typedef void (*FUNC_void_GLdouble)(GLdouble depth);
typedef struct {
    GLdouble a1 __attribute__ ((aligned(8)));
} ARGS_void_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLdouble func;
    ARGS_void_GLdouble args;
} PACKED_void_GLdouble;
typedef struct {
    int func;
    ARGS_void_GLdouble args;
} INDEXED_void_GLdouble;
typedef void (*FUNC_void_GLfloat)(GLfloat c);
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
typedef void (*FUNC_void_GLenum_const_GLdouble___GENPT__)(GLenum plane, const GLdouble * equation);
typedef struct {
    GLenum a1;
    const GLdouble * a2;
} ARGS_void_GLenum_const_GLdouble___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_const_GLdouble___GENPT__ func;
    ARGS_void_GLenum_const_GLdouble___GENPT__ args;
} PACKED_void_GLenum_const_GLdouble___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_const_GLdouble___GENPT__ args;
} INDEXED_void_GLenum_const_GLdouble___GENPT__;
typedef void (*FUNC_void_GLbyte_GLbyte_GLbyte)(GLbyte red, GLbyte green, GLbyte blue);
typedef struct {
    GLbyte a1;
    GLbyte a2;
    GLbyte a3;
} ARGS_void_GLbyte_GLbyte_GLbyte;
typedef struct {
    int format;
    FUNC_void_GLbyte_GLbyte_GLbyte func;
    ARGS_void_GLbyte_GLbyte_GLbyte args;
} PACKED_void_GLbyte_GLbyte_GLbyte;
typedef struct {
    int func;
    ARGS_void_GLbyte_GLbyte_GLbyte args;
} INDEXED_void_GLbyte_GLbyte_GLbyte;
typedef void (*FUNC_void_const_GLbyte___GENPT__)(const GLbyte * v);
typedef struct {
    const GLbyte * a1;
} ARGS_void_const_GLbyte___GENPT__;
typedef struct {
    int format;
    FUNC_void_const_GLbyte___GENPT__ func;
    ARGS_void_const_GLbyte___GENPT__ args;
} PACKED_void_const_GLbyte___GENPT__;
typedef struct {
    int func;
    ARGS_void_const_GLbyte___GENPT__ args;
} INDEXED_void_const_GLbyte___GENPT__;
typedef void (*FUNC_void_GLdouble_GLdouble_GLdouble)(GLdouble red, GLdouble green, GLdouble blue);
typedef struct {
    GLdouble a1 __attribute__ ((aligned(8)));
    GLdouble a2 __attribute__ ((aligned(8)));
    GLdouble a3 __attribute__ ((aligned(8)));
} ARGS_void_GLdouble_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLdouble_GLdouble_GLdouble func;
    ARGS_void_GLdouble_GLdouble_GLdouble args;
} PACKED_void_GLdouble_GLdouble_GLdouble;
typedef struct {
    int func;
    ARGS_void_GLdouble_GLdouble_GLdouble args;
} INDEXED_void_GLdouble_GLdouble_GLdouble;
typedef void (*FUNC_void_const_GLdouble___GENPT__)(const GLdouble * v);
typedef struct {
    const GLdouble * a1;
} ARGS_void_const_GLdouble___GENPT__;
typedef struct {
    int format;
    FUNC_void_const_GLdouble___GENPT__ func;
    ARGS_void_const_GLdouble___GENPT__ args;
} PACKED_void_const_GLdouble___GENPT__;
typedef struct {
    int func;
    ARGS_void_const_GLdouble___GENPT__ args;
} INDEXED_void_const_GLdouble___GENPT__;
typedef void (*FUNC_void_GLfloat_GLfloat_GLfloat)(GLfloat red, GLfloat green, GLfloat blue);
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
typedef void (*FUNC_void_const_GLfloat___GENPT__)(const GLfloat * v);
typedef struct {
    const GLfloat * a1;
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
typedef void (*FUNC_void_GLint_GLint_GLint)(GLint red, GLint green, GLint blue);
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
typedef struct {
    int func;
    ARGS_void_GLint_GLint_GLint args;
} INDEXED_void_GLint_GLint_GLint;
typedef void (*FUNC_void_const_GLint___GENPT__)(const GLint * v);
typedef struct {
    const GLint * a1;
} ARGS_void_const_GLint___GENPT__;
typedef struct {
    int format;
    FUNC_void_const_GLint___GENPT__ func;
    ARGS_void_const_GLint___GENPT__ args;
} PACKED_void_const_GLint___GENPT__;
typedef struct {
    int func;
    ARGS_void_const_GLint___GENPT__ args;
} INDEXED_void_const_GLint___GENPT__;
typedef void (*FUNC_void_GLshort_GLshort_GLshort)(GLshort red, GLshort green, GLshort blue);
typedef struct {
    GLshort a1;
    GLshort a2;
    GLshort a3;
} ARGS_void_GLshort_GLshort_GLshort;
typedef struct {
    int format;
    FUNC_void_GLshort_GLshort_GLshort func;
    ARGS_void_GLshort_GLshort_GLshort args;
} PACKED_void_GLshort_GLshort_GLshort;
typedef struct {
    int func;
    ARGS_void_GLshort_GLshort_GLshort args;
} INDEXED_void_GLshort_GLshort_GLshort;
typedef void (*FUNC_void_const_GLshort___GENPT__)(const GLshort * v);
typedef struct {
    const GLshort * a1;
} ARGS_void_const_GLshort___GENPT__;
typedef struct {
    int format;
    FUNC_void_const_GLshort___GENPT__ func;
    ARGS_void_const_GLshort___GENPT__ args;
} PACKED_void_const_GLshort___GENPT__;
typedef struct {
    int func;
    ARGS_void_const_GLshort___GENPT__ args;
} INDEXED_void_const_GLshort___GENPT__;
typedef void (*FUNC_void_GLubyte_GLubyte_GLubyte)(GLubyte red, GLubyte green, GLubyte blue);
typedef struct {
    GLubyte a1;
    GLubyte a2;
    GLubyte a3;
} ARGS_void_GLubyte_GLubyte_GLubyte;
typedef struct {
    int format;
    FUNC_void_GLubyte_GLubyte_GLubyte func;
    ARGS_void_GLubyte_GLubyte_GLubyte args;
} PACKED_void_GLubyte_GLubyte_GLubyte;
typedef struct {
    int func;
    ARGS_void_GLubyte_GLubyte_GLubyte args;
} INDEXED_void_GLubyte_GLubyte_GLubyte;
typedef void (*FUNC_void_const_GLubyte___GENPT__)(const GLubyte * v);
typedef struct {
    const GLubyte * a1;
} ARGS_void_const_GLubyte___GENPT__;
typedef struct {
    int format;
    FUNC_void_const_GLubyte___GENPT__ func;
    ARGS_void_const_GLubyte___GENPT__ args;
} PACKED_void_const_GLubyte___GENPT__;
typedef struct {
    int func;
    ARGS_void_const_GLubyte___GENPT__ args;
} INDEXED_void_const_GLubyte___GENPT__;
typedef void (*FUNC_void_GLuint_GLuint_GLuint)(GLuint red, GLuint green, GLuint blue);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLuint a3;
} ARGS_void_GLuint_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLuint func;
    ARGS_void_GLuint_GLuint_GLuint args;
} PACKED_void_GLuint_GLuint_GLuint;
typedef struct {
    int func;
    ARGS_void_GLuint_GLuint_GLuint args;
} INDEXED_void_GLuint_GLuint_GLuint;
typedef void (*FUNC_void_const_GLuint___GENPT__)(const GLuint * v);
typedef struct {
    const GLuint * a1;
} ARGS_void_const_GLuint___GENPT__;
typedef struct {
    int format;
    FUNC_void_const_GLuint___GENPT__ func;
    ARGS_void_const_GLuint___GENPT__ args;
} PACKED_void_const_GLuint___GENPT__;
typedef struct {
    int func;
    ARGS_void_const_GLuint___GENPT__ args;
} INDEXED_void_const_GLuint___GENPT__;
typedef void (*FUNC_void_GLushort_GLushort_GLushort)(GLushort red, GLushort green, GLushort blue);
typedef struct {
    GLushort a1;
    GLushort a2;
    GLushort a3;
} ARGS_void_GLushort_GLushort_GLushort;
typedef struct {
    int format;
    FUNC_void_GLushort_GLushort_GLushort func;
    ARGS_void_GLushort_GLushort_GLushort args;
} PACKED_void_GLushort_GLushort_GLushort;
typedef struct {
    int func;
    ARGS_void_GLushort_GLushort_GLushort args;
} INDEXED_void_GLushort_GLushort_GLushort;
typedef void (*FUNC_void_const_GLushort___GENPT__)(const GLushort * v);
typedef struct {
    const GLushort * a1;
} ARGS_void_const_GLushort___GENPT__;
typedef struct {
    int format;
    FUNC_void_const_GLushort___GENPT__ func;
    ARGS_void_const_GLushort___GENPT__ args;
} PACKED_void_const_GLushort___GENPT__;
typedef struct {
    int func;
    ARGS_void_const_GLushort___GENPT__ args;
} INDEXED_void_const_GLushort___GENPT__;
typedef void (*FUNC_void_GLbyte_GLbyte_GLbyte_GLbyte)(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
typedef struct {
    GLbyte a1;
    GLbyte a2;
    GLbyte a3;
    GLbyte a4;
} ARGS_void_GLbyte_GLbyte_GLbyte_GLbyte;
typedef struct {
    int format;
    FUNC_void_GLbyte_GLbyte_GLbyte_GLbyte func;
    ARGS_void_GLbyte_GLbyte_GLbyte_GLbyte args;
} PACKED_void_GLbyte_GLbyte_GLbyte_GLbyte;
typedef struct {
    int func;
    ARGS_void_GLbyte_GLbyte_GLbyte_GLbyte args;
} INDEXED_void_GLbyte_GLbyte_GLbyte_GLbyte;
typedef void (*FUNC_void_GLdouble_GLdouble_GLdouble_GLdouble)(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
typedef struct {
    GLdouble a1 __attribute__ ((aligned(8)));
    GLdouble a2 __attribute__ ((aligned(8)));
    GLdouble a3 __attribute__ ((aligned(8)));
    GLdouble a4 __attribute__ ((aligned(8)));
} ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLdouble_GLdouble_GLdouble_GLdouble func;
    ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble args;
} PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble;
typedef struct {
    int func;
    ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble args;
} INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble;
typedef void (*FUNC_void_GLint_GLint_GLint_GLint)(GLint red, GLint green, GLint blue, GLint alpha);
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
typedef struct {
    int func;
    ARGS_void_GLint_GLint_GLint_GLint args;
} INDEXED_void_GLint_GLint_GLint_GLint;
typedef void (*FUNC_void_GLshort_GLshort_GLshort_GLshort)(GLshort red, GLshort green, GLshort blue, GLshort alpha);
typedef struct {
    GLshort a1;
    GLshort a2;
    GLshort a3;
    GLshort a4;
} ARGS_void_GLshort_GLshort_GLshort_GLshort;
typedef struct {
    int format;
    FUNC_void_GLshort_GLshort_GLshort_GLshort func;
    ARGS_void_GLshort_GLshort_GLshort_GLshort args;
} PACKED_void_GLshort_GLshort_GLshort_GLshort;
typedef struct {
    int func;
    ARGS_void_GLshort_GLshort_GLshort_GLshort args;
} INDEXED_void_GLshort_GLshort_GLshort_GLshort;
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
typedef void (*FUNC_void_GLuint_GLuint_GLuint_GLuint)(GLuint red, GLuint green, GLuint blue, GLuint alpha);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLuint a3;
    GLuint a4;
} ARGS_void_GLuint_GLuint_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLuint_GLuint func;
    ARGS_void_GLuint_GLuint_GLuint_GLuint args;
} PACKED_void_GLuint_GLuint_GLuint_GLuint;
typedef struct {
    int func;
    ARGS_void_GLuint_GLuint_GLuint_GLuint args;
} INDEXED_void_GLuint_GLuint_GLuint_GLuint;
typedef void (*FUNC_void_GLushort_GLushort_GLushort_GLushort)(GLushort red, GLushort green, GLushort blue, GLushort alpha);
typedef struct {
    GLushort a1;
    GLushort a2;
    GLushort a3;
    GLushort a4;
} ARGS_void_GLushort_GLushort_GLushort_GLushort;
typedef struct {
    int format;
    FUNC_void_GLushort_GLushort_GLushort_GLushort func;
    ARGS_void_GLushort_GLushort_GLushort_GLushort args;
} PACKED_void_GLushort_GLushort_GLushort_GLushort;
typedef struct {
    int func;
    ARGS_void_GLushort_GLushort_GLushort_GLushort args;
} INDEXED_void_GLushort_GLushort_GLushort_GLushort;
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
    const GLvoid * a4;
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
typedef void (*FUNC_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__)(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid * data);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLsizei a3;
    GLenum a4;
    GLenum a5;
    const GLvoid * a6;
} ARGS_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
typedef void (*FUNC_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * table);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLsizei a3;
    GLenum a4;
    GLenum a5;
    const GLvoid * a6;
} ARGS_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_const_GLfloat___GENPT__ args;
} INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_const_GLint___GENPT__ args;
} INDEXED_void_GLenum_GLenum_const_GLint___GENPT__;
typedef void (*FUNC_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid * data);
typedef struct {
    GLenum a1;
    GLint a2;
    GLenum a3;
    GLsizei a4;
    GLint a5;
    GLsizei a6;
    const GLvoid * a7;
} ARGS_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__;
typedef void (*FUNC_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid * data);
typedef struct {
    GLenum a1;
    GLint a2;
    GLenum a3;
    GLsizei a4;
    GLsizei a5;
    GLsizei a6;
    GLint a7;
    GLsizei a8;
    const GLvoid * a9;
} ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__;
typedef void (*FUNC_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid * data);
typedef struct {
    GLenum a1;
    GLint a2;
    GLint a3;
    GLsizei a4;
    GLenum a5;
    GLsizei a6;
    const GLvoid * a7;
} ARGS_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__;
typedef void (*FUNC_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid * data);
typedef struct {
    GLenum a1;
    GLint a2;
    GLint a3;
    GLint a4;
    GLint a5;
    GLsizei a6;
    GLsizei a7;
    GLsizei a8;
    GLenum a9;
    GLsizei a10;
    const GLvoid * a11;
} ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__;
typedef void (*FUNC_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * image);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLsizei a3;
    GLsizei a4;
    GLenum a5;
    GLenum a6;
    const GLvoid * a7;
} ARGS_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
typedef void (*FUNC_void_GLenum_GLenum_GLfloat)(GLenum target, GLenum pname, GLfloat params);
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
typedef void (*FUNC_void_GLenum_GLenum_GLint)(GLenum target, GLenum pname, GLint params);
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
typedef void (*FUNC_void_GLenum_GLsizei_GLint_GLint_GLsizei)(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLint a3;
    GLint a4;
    GLsizei a5;
} ARGS_void_GLenum_GLsizei_GLint_GLint_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLint_GLint_GLsizei func;
    ARGS_void_GLenum_GLsizei_GLint_GLint_GLsizei args;
} PACKED_void_GLenum_GLsizei_GLint_GLint_GLsizei;
typedef struct {
    int func;
    ARGS_void_GLenum_GLsizei_GLint_GLint_GLsizei args;
} INDEXED_void_GLenum_GLsizei_GLint_GLint_GLsizei;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLint_GLsizei)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLint a4;
    GLsizei a5;
} ARGS_void_GLenum_GLenum_GLint_GLint_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLint_GLsizei func;
    ARGS_void_GLenum_GLenum_GLint_GLint_GLsizei args;
} PACKED_void_GLenum_GLenum_GLint_GLint_GLsizei;
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_GLint_GLint_GLsizei args;
} INDEXED_void_GLenum_GLenum_GLint_GLint_GLsizei;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLint_GLsizei_GLsizei)(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLint a4;
    GLsizei a5;
    GLsizei a6;
} ARGS_void_GLenum_GLenum_GLint_GLint_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLint_GLsizei_GLsizei func;
    ARGS_void_GLenum_GLenum_GLint_GLint_GLsizei_GLsizei args;
} PACKED_void_GLenum_GLenum_GLint_GLint_GLsizei_GLsizei;
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_GLint_GLint_GLsizei_GLsizei args;
} INDEXED_void_GLenum_GLenum_GLint_GLint_GLsizei_GLsizei;
typedef void (*FUNC_void_GLint_GLint_GLsizei_GLsizei_GLenum)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
typedef struct {
    GLint a1;
    GLint a2;
    GLsizei a3;
    GLsizei a4;
    GLenum a5;
} ARGS_void_GLint_GLint_GLsizei_GLsizei_GLenum;
typedef struct {
    int format;
    FUNC_void_GLint_GLint_GLsizei_GLsizei_GLenum func;
    ARGS_void_GLint_GLint_GLsizei_GLsizei_GLenum args;
} PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum;
typedef struct {
    int func;
    ARGS_void_GLint_GLint_GLsizei_GLsizei_GLenum args;
} INDEXED_void_GLint_GLint_GLsizei_GLsizei_GLenum;
typedef void (*FUNC_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef struct {
    GLenum a1;
    GLint a2;
    GLenum a3;
    GLint a4;
    GLint a5;
    GLsizei a6;
    GLint a7;
} ARGS_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint func;
    ARGS_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint args;
} PACKED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint;
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint args;
} INDEXED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint;
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
typedef void (*FUNC_void_GLenum_GLint_GLint_GLint_GLint_GLsizei)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef struct {
    GLenum a1;
    GLint a2;
    GLint a3;
    GLint a4;
    GLint a5;
    GLsizei a6;
} ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLint_GLint_GLsizei func;
    ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLsizei args;
} PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei;
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLsizei args;
} INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei;
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
typedef void (*FUNC_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef struct {
    GLenum a1;
    GLint a2;
    GLint a3;
    GLint a4;
    GLint a5;
    GLint a6;
    GLint a7;
    GLsizei a8;
    GLsizei a9;
} ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei func;
    ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei args;
} PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei;
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei args;
} INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei;
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
typedef struct {
    int func;
    ARGS_void_GLsizei_const_GLuint___GENPT__ args;
} INDEXED_void_GLsizei_const_GLuint___GENPT__;
typedef void (*FUNC_void_GLuint_GLsizei)(GLuint list, GLsizei range);
typedef struct {
    GLuint a1;
    GLsizei a2;
} ARGS_void_GLuint_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei func;
    ARGS_void_GLuint_GLsizei args;
} PACKED_void_GLuint_GLsizei;
typedef struct {
    int func;
    ARGS_void_GLuint_GLsizei args;
} INDEXED_void_GLuint_GLsizei;
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
typedef void (*FUNC_void_GLdouble_GLdouble)(GLdouble near, GLdouble far);
typedef struct {
    GLdouble a1 __attribute__ ((aligned(8)));
    GLdouble a2 __attribute__ ((aligned(8)));
} ARGS_void_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLdouble_GLdouble func;
    ARGS_void_GLdouble_GLdouble args;
} PACKED_void_GLdouble_GLdouble;
typedef struct {
    int func;
    ARGS_void_GLdouble_GLdouble args;
} INDEXED_void_GLdouble_GLdouble;
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
    const GLvoid * a4;
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
typedef void (*FUNC_void_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__)(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels);
typedef struct {
    GLsizei a1;
    GLsizei a2;
    GLenum a3;
    GLenum a4;
    const GLvoid * a5;
} ARGS_void_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ func;
    ARGS_void_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args;
} PACKED_void_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args;
} INDEXED_void_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
typedef void (*FUNC_void_GLenum_GLuint_GLuint_GLsizei_GLenum_const_GLvoid___GENPT__)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid * indices);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLuint a3;
    GLsizei a4;
    GLenum a5;
    const GLvoid * a6;
} ARGS_void_GLenum_GLuint_GLuint_GLsizei_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLuint_GLsizei_GLenum_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLuint_GLuint_GLsizei_GLenum_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLuint_GLuint_GLsizei_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLuint_GLuint_GLsizei_GLenum_const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLuint_GLuint_GLsizei_GLenum_const_GLvoid___GENPT__;
typedef void (*FUNC_void_GLsizei_const_GLvoid___GENPT__)(GLsizei stride, const GLvoid * pointer);
typedef struct {
    GLsizei a1;
    const GLvoid * a2;
} ARGS_void_GLsizei_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLsizei_const_GLvoid___GENPT__ func;
    ARGS_void_GLsizei_const_GLvoid___GENPT__ args;
} PACKED_void_GLsizei_const_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLsizei_const_GLvoid___GENPT__ args;
} INDEXED_void_GLsizei_const_GLvoid___GENPT__;
typedef void (*FUNC_void_const_GLboolean___GENPT__)(const GLboolean * flag);
typedef struct {
    const GLboolean * a1;
} ARGS_void_const_GLboolean___GENPT__;
typedef struct {
    int format;
    FUNC_void_const_GLboolean___GENPT__ func;
    ARGS_void_const_GLboolean___GENPT__ args;
} PACKED_void_const_GLboolean___GENPT__;
typedef struct {
    int func;
    ARGS_void_const_GLboolean___GENPT__ args;
} INDEXED_void_const_GLboolean___GENPT__;
typedef void (*FUNC_void)();
typedef struct {
} ARGS_void;
typedef struct {
    int format;
    FUNC_void func;
    ARGS_void args;
} PACKED_void;
typedef struct {
    int func;
    ARGS_void args;
} INDEXED_void;
typedef void (*FUNC_void_GLfloat_GLfloat)(GLfloat u, GLfloat v);
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
typedef void (*FUNC_void_GLenum_GLint_GLint)(GLenum mode, GLint i1, GLint i2);
typedef struct {
    GLenum a1;
    GLint a2;
    GLint a3;
} ARGS_void_GLenum_GLint_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint func;
    ARGS_void_GLenum_GLint_GLint args;
} PACKED_void_GLenum_GLint_GLint;
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLint args;
} INDEXED_void_GLenum_GLint_GLint;
typedef void (*FUNC_void_GLenum_GLint_GLint_GLint_GLint)(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
typedef struct {
    GLenum a1;
    GLint a2;
    GLint a3;
    GLint a4;
    GLint a5;
} ARGS_void_GLenum_GLint_GLint_GLint_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLint_GLint func;
    ARGS_void_GLenum_GLint_GLint_GLint_GLint args;
} PACKED_void_GLenum_GLint_GLint_GLint_GLint;
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLint_GLint_GLint args;
} INDEXED_void_GLenum_GLint_GLint_GLint_GLint;
typedef void (*FUNC_void_GLint_GLint)(GLint i, GLint j);
typedef struct {
    GLint a1;
    GLint a2;
} ARGS_void_GLint_GLint;
typedef struct {
    int format;
    FUNC_void_GLint_GLint func;
    ARGS_void_GLint_GLint args;
} PACKED_void_GLint_GLint;
typedef struct {
    int func;
    ARGS_void_GLint_GLint args;
} INDEXED_void_GLint_GLint;
typedef void (*FUNC_void_GLsizei_GLenum_GLfloat___GENPT__)(GLsizei size, GLenum type, GLfloat * buffer);
typedef struct {
    GLsizei a1;
    GLenum a2;
    GLfloat * a3;
} ARGS_void_GLsizei_GLenum_GLfloat___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLenum_GLfloat___GENPT__ func;
    ARGS_void_GLsizei_GLenum_GLfloat___GENPT__ args;
} PACKED_void_GLsizei_GLenum_GLfloat___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLsizei_GLenum_GLfloat___GENPT__ args;
} INDEXED_void_GLsizei_GLenum_GLfloat___GENPT__;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLsizei_const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLsizei_const_GLvoid___GENPT__;
typedef void (*FUNC_void_GLenum_const_GLfloat___GENPT__)(GLenum pname, const GLfloat * params);
typedef struct {
    GLenum a1;
    const GLfloat * a2;
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
typedef void (*FUNC_void_GLenum_const_GLint___GENPT__)(GLenum pname, const GLint * params);
typedef struct {
    GLenum a1;
    const GLint * a2;
} ARGS_void_GLenum_const_GLint___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_const_GLint___GENPT__ func;
    ARGS_void_GLenum_const_GLint___GENPT__ args;
} PACKED_void_GLenum_const_GLint___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_const_GLint___GENPT__ args;
} INDEXED_void_GLenum_const_GLint___GENPT__;
typedef void (*FUNC_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef struct {
    GLdouble a1 __attribute__ ((aligned(8)));
    GLdouble a2 __attribute__ ((aligned(8)));
    GLdouble a3 __attribute__ ((aligned(8)));
    GLdouble a4 __attribute__ ((aligned(8)));
    GLdouble a5 __attribute__ ((aligned(8)));
    GLdouble a6 __attribute__ ((aligned(8)));
} ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble func;
    ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble args;
} PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble;
typedef struct {
    int func;
    ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble args;
} INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble;
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
typedef GLuint (*FUNC_GLuint_GLsizei)(GLsizei range);
typedef struct {
    GLsizei a1;
} ARGS_GLuint_GLsizei;
typedef struct {
    int format;
    FUNC_GLuint_GLsizei func;
    ARGS_GLuint_GLsizei args;
} PACKED_GLuint_GLsizei;
typedef struct {
    int func;
    ARGS_GLuint_GLsizei args;
} INDEXED_GLuint_GLsizei;
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
typedef void (*FUNC_void_GLenum_GLenum_GLvoid___GENPT__)(GLenum target, GLenum pname, GLvoid * params);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLvoid * a3;
} ARGS_void_GLenum_GLenum_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLenum_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLenum_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLenum_GLvoid___GENPT__;
typedef void (*FUNC_void_GLenum_GLintptr_GLsizeiptr_GLvoid___GENPT__)(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data);
typedef struct {
    GLenum a1;
    GLintptr a2;
    GLsizeiptr a3;
    GLvoid * a4;
} ARGS_void_GLenum_GLintptr_GLsizeiptr_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLintptr_GLsizeiptr_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLintptr_GLsizeiptr_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLintptr_GLsizeiptr_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLintptr_GLsizeiptr_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLintptr_GLsizeiptr_GLvoid___GENPT__;
typedef void (*FUNC_void_GLenum_GLdouble___GENPT__)(GLenum plane, GLdouble * equation);
typedef struct {
    GLenum a1;
    GLdouble * a2;
} ARGS_void_GLenum_GLdouble___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLdouble___GENPT__ func;
    ARGS_void_GLenum_GLdouble___GENPT__ args;
} PACKED_void_GLenum_GLdouble___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLdouble___GENPT__ args;
} INDEXED_void_GLenum_GLdouble___GENPT__;
typedef void (*FUNC_void_GLenum_GLenum_GLenum_GLvoid___GENPT__)(GLenum target, GLenum format, GLenum type, GLvoid * table);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLenum a3;
    GLvoid * a4;
} ARGS_void_GLenum_GLenum_GLenum_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLenum_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLenum_GLenum_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLenum_GLenum_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_GLenum_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLenum_GLenum_GLvoid___GENPT__;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_GLfloat___GENPT__ args;
} INDEXED_void_GLenum_GLenum_GLfloat___GENPT__;
typedef void (*FUNC_void_GLenum_GLint_GLvoid___GENPT__)(GLenum target, GLint level, GLvoid * img);
typedef struct {
    GLenum a1;
    GLint a2;
    GLvoid * a3;
} ARGS_void_GLenum_GLint_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLint_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLint_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLint_GLvoid___GENPT__;
typedef GLenum (*FUNC_GLenum)();
typedef struct {
} ARGS_GLenum;
typedef struct {
    int format;
    FUNC_GLenum func;
    ARGS_GLenum args;
} PACKED_GLenum;
typedef struct {
    int func;
    ARGS_GLenum args;
} INDEXED_GLenum;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLfloat___GENPT__ args;
} INDEXED_void_GLenum_GLfloat___GENPT__;
typedef void (*FUNC_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values);
typedef struct {
    GLenum a1;
    GLboolean a2;
    GLenum a3;
    GLenum a4;
    GLvoid * a5;
} ARGS_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__;
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
typedef void (*FUNC_void_GLenum_GLenum_GLdouble___GENPT__)(GLenum target, GLenum query, GLdouble * v);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLdouble * a3;
} ARGS_void_GLenum_GLenum_GLdouble___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLdouble___GENPT__ func;
    ARGS_void_GLenum_GLenum_GLdouble___GENPT__ args;
} PACKED_void_GLenum_GLenum_GLdouble___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_GLdouble___GENPT__ args;
} INDEXED_void_GLenum_GLenum_GLdouble___GENPT__;
typedef void (*FUNC_void_GLenum_GLuint___GENPT__)(GLenum map, GLuint * values);
typedef struct {
    GLenum a1;
    GLuint * a2;
} ARGS_void_GLenum_GLuint___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint___GENPT__ func;
    ARGS_void_GLenum_GLuint___GENPT__ args;
} PACKED_void_GLenum_GLuint___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLuint___GENPT__ args;
} INDEXED_void_GLenum_GLuint___GENPT__;
typedef void (*FUNC_void_GLenum_GLushort___GENPT__)(GLenum map, GLushort * values);
typedef struct {
    GLenum a1;
    GLushort * a2;
} ARGS_void_GLenum_GLushort___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLushort___GENPT__ func;
    ARGS_void_GLenum_GLushort___GENPT__ args;
} PACKED_void_GLenum_GLushort___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLushort___GENPT__ args;
} INDEXED_void_GLenum_GLushort___GENPT__;
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
typedef void (*FUNC_void_GLubyte___GENPT__)(GLubyte * mask);
typedef struct {
    GLubyte * a1;
} ARGS_void_GLubyte___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLubyte___GENPT__ func;
    ARGS_void_GLubyte___GENPT__ args;
} PACKED_void_GLubyte___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLubyte___GENPT__ args;
} INDEXED_void_GLubyte___GENPT__;
typedef void (*FUNC_void_GLuint_GLenum_GLint___GENPT__)(GLuint id, GLenum pname, GLint * params);
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
typedef struct {
    int func;
    ARGS_void_GLuint_GLenum_GLint___GENPT__ args;
} INDEXED_void_GLuint_GLenum_GLint___GENPT__;
typedef void (*FUNC_void_GLuint_GLenum_GLuint___GENPT__)(GLuint id, GLenum pname, GLuint * params);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLuint * a3;
} ARGS_void_GLuint_GLenum_GLuint___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLuint___GENPT__ func;
    ARGS_void_GLuint_GLenum_GLuint___GENPT__ args;
} PACKED_void_GLuint_GLenum_GLuint___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLuint_GLenum_GLuint___GENPT__ args;
} INDEXED_void_GLuint_GLenum_GLuint___GENPT__;
typedef void (*FUNC_void_GLenum_GLenum_GLenum_GLvoid___GENPT___GLvoid___GENPT___GLvoid___GENPT__)(GLenum target, GLenum format, GLenum type, GLvoid * row, GLvoid * column, GLvoid * span);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLenum a3;
    GLvoid * a4;
    GLvoid * a5;
    GLvoid * a6;
} ARGS_void_GLenum_GLenum_GLenum_GLvoid___GENPT___GLvoid___GENPT___GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLenum_GLvoid___GENPT___GLvoid___GENPT___GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLenum_GLenum_GLvoid___GENPT___GLvoid___GENPT___GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLenum_GLenum_GLvoid___GENPT___GLvoid___GENPT___GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_GLenum_GLvoid___GENPT___GLvoid___GENPT___GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLenum_GLenum_GLvoid___GENPT___GLvoid___GENPT___GLvoid___GENPT__;
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
typedef void (*FUNC_void_GLenum_GLint_GLenum_GLenum_GLvoid___GENPT__)(GLenum target, GLint level, GLenum format, GLenum type, GLvoid * pixels);
typedef struct {
    GLenum a1;
    GLint a2;
    GLenum a3;
    GLenum a4;
    GLvoid * a5;
} ARGS_void_GLenum_GLint_GLenum_GLenum_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLenum_GLenum_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLint_GLenum_GLenum_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLint_GLenum_GLenum_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLenum_GLenum_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLint_GLenum_GLenum_GLvoid___GENPT__;
typedef void (*FUNC_void_GLenum_GLint_GLenum_GLfloat___GENPT__)(GLenum target, GLint level, GLenum pname, GLfloat * params);
typedef struct {
    GLenum a1;
    GLint a2;
    GLenum a3;
    GLfloat * a4;
} ARGS_void_GLenum_GLint_GLenum_GLfloat___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLenum_GLfloat___GENPT__ func;
    ARGS_void_GLenum_GLint_GLenum_GLfloat___GENPT__ args;
} PACKED_void_GLenum_GLint_GLenum_GLfloat___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLenum_GLfloat___GENPT__ args;
} INDEXED_void_GLenum_GLint_GLenum_GLfloat___GENPT__;
typedef void (*FUNC_void_GLenum_GLint_GLenum_GLint___GENPT__)(GLenum target, GLint level, GLenum pname, GLint * params);
typedef struct {
    GLenum a1;
    GLint a2;
    GLenum a3;
    GLint * a4;
} ARGS_void_GLenum_GLint_GLenum_GLint___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLenum_GLint___GENPT__ func;
    ARGS_void_GLenum_GLint_GLenum_GLint___GENPT__ args;
} PACKED_void_GLenum_GLint_GLenum_GLint___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLenum_GLint___GENPT__ args;
} INDEXED_void_GLenum_GLint_GLenum_GLint___GENPT__;
typedef void (*FUNC_void_GLenum_GLsizei_GLenum_GLboolean)(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLenum a3;
    GLboolean a4;
} ARGS_void_GLenum_GLsizei_GLenum_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLenum_GLboolean func;
    ARGS_void_GLenum_GLsizei_GLenum_GLboolean args;
} PACKED_void_GLenum_GLsizei_GLenum_GLboolean;
typedef struct {
    int func;
    ARGS_void_GLenum_GLsizei_GLenum_GLboolean args;
} INDEXED_void_GLenum_GLsizei_GLenum_GLboolean;
typedef void (*FUNC_void_GLshort)(GLshort c);
typedef struct {
    GLshort a1;
} ARGS_void_GLshort;
typedef struct {
    int format;
    FUNC_void_GLshort func;
    ARGS_void_GLshort args;
} PACKED_void_GLshort;
typedef struct {
    int func;
    ARGS_void_GLshort args;
} INDEXED_void_GLshort;
typedef void (*FUNC_void_GLubyte)(GLubyte c);
typedef struct {
    GLubyte a1;
} ARGS_void_GLubyte;
typedef struct {
    int format;
    FUNC_void_GLubyte func;
    ARGS_void_GLubyte args;
} PACKED_void_GLubyte;
typedef struct {
    int func;
    ARGS_void_GLubyte args;
} INDEXED_void_GLubyte;
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
typedef void (*FUNC_void_GLint_GLushort)(GLint factor, GLushort pattern);
typedef struct {
    GLint a1;
    GLushort a2;
} ARGS_void_GLint_GLushort;
typedef struct {
    int format;
    FUNC_void_GLint_GLushort func;
    ARGS_void_GLint_GLushort args;
} PACKED_void_GLint_GLushort;
typedef struct {
    int func;
    ARGS_void_GLint_GLushort args;
} INDEXED_void_GLint_GLushort;
typedef void (*FUNC_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__)(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble * points);
typedef struct {
    GLenum a1;
    GLdouble a2 __attribute__ ((aligned(8)));
    GLdouble a3 __attribute__ ((aligned(8)));
    GLint a4;
    GLint a5;
    const GLdouble * a6;
} ARGS_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ func;
    ARGS_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ args;
} PACKED_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ args;
} INDEXED_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__;
typedef void (*FUNC_void_GLenum_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__)(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat * points);
typedef struct {
    GLenum a1;
    GLfloat a2;
    GLfloat a3;
    GLint a4;
    GLint a5;
    const GLfloat * a6;
} ARGS_void_GLenum_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ func;
    ARGS_void_GLenum_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ args;
} PACKED_void_GLenum_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ args;
} INDEXED_void_GLenum_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__;
typedef void (*FUNC_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble * points);
typedef struct {
    GLenum a1;
    GLdouble a2 __attribute__ ((aligned(8)));
    GLdouble a3 __attribute__ ((aligned(8)));
    GLint a4;
    GLint a5;
    GLdouble a6 __attribute__ ((aligned(8)));
    GLdouble a7 __attribute__ ((aligned(8)));
    GLint a8;
    GLint a9;
    const GLdouble * a10;
} ARGS_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ func;
    ARGS_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ args;
} PACKED_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ args;
} INDEXED_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__;
typedef void (*FUNC_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat * points);
typedef struct {
    GLenum a1;
    GLfloat a2;
    GLfloat a3;
    GLint a4;
    GLint a5;
    GLfloat a6;
    GLfloat a7;
    GLint a8;
    GLint a9;
    const GLfloat * a10;
} ARGS_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ func;
    ARGS_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ args;
} PACKED_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ args;
} INDEXED_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__;
typedef GLvoid * (*FUNC_GLvoid___GENPT___GLenum_GLenum)(GLenum target, GLenum access);
typedef struct {
    GLenum a1;
    GLenum a2;
} ARGS_GLvoid___GENPT___GLenum_GLenum;
typedef struct {
    int format;
    FUNC_GLvoid___GENPT___GLenum_GLenum func;
    ARGS_GLvoid___GENPT___GLenum_GLenum args;
} PACKED_GLvoid___GENPT___GLenum_GLenum;
typedef struct {
    int func;
    ARGS_GLvoid___GENPT___GLenum_GLenum args;
} INDEXED_GLvoid___GENPT___GLenum_GLenum;
typedef void (*FUNC_void_GLint_GLdouble_GLdouble)(GLint un, GLdouble u1, GLdouble u2);
typedef struct {
    GLint a1;
    GLdouble a2 __attribute__ ((aligned(8)));
    GLdouble a3 __attribute__ ((aligned(8)));
} ARGS_void_GLint_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLint_GLdouble_GLdouble func;
    ARGS_void_GLint_GLdouble_GLdouble args;
} PACKED_void_GLint_GLdouble_GLdouble;
typedef struct {
    int func;
    ARGS_void_GLint_GLdouble_GLdouble args;
} INDEXED_void_GLint_GLdouble_GLdouble;
typedef void (*FUNC_void_GLint_GLfloat_GLfloat)(GLint un, GLfloat u1, GLfloat u2);
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
typedef struct {
    int func;
    ARGS_void_GLint_GLfloat_GLfloat args;
} INDEXED_void_GLint_GLfloat_GLfloat;
typedef void (*FUNC_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble)(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
typedef struct {
    GLint a1;
    GLdouble a2 __attribute__ ((aligned(8)));
    GLdouble a3 __attribute__ ((aligned(8)));
    GLint a4;
    GLdouble a5 __attribute__ ((aligned(8)));
    GLdouble a6 __attribute__ ((aligned(8)));
} ARGS_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble func;
    ARGS_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble args;
} PACKED_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble;
typedef struct {
    int func;
    ARGS_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble args;
} INDEXED_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble;
typedef void (*FUNC_void_GLint_GLfloat_GLfloat_GLint_GLfloat_GLfloat)(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
typedef struct {
    GLint a1;
    GLfloat a2;
    GLfloat a3;
    GLint a4;
    GLfloat a5;
    GLfloat a6;
} ARGS_void_GLint_GLfloat_GLfloat_GLint_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLint_GLfloat_GLfloat_GLint_GLfloat_GLfloat func;
    ARGS_void_GLint_GLfloat_GLfloat_GLint_GLfloat_GLfloat args;
} PACKED_void_GLint_GLfloat_GLfloat_GLint_GLfloat_GLfloat;
typedef struct {
    int func;
    ARGS_void_GLint_GLfloat_GLfloat_GLint_GLfloat_GLfloat args;
} INDEXED_void_GLint_GLfloat_GLfloat_GLint_GLfloat_GLfloat;
typedef void (*FUNC_void_GLenum_GLenum_GLboolean)(GLenum target, GLenum internalformat, GLboolean sink);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLboolean a3;
} ARGS_void_GLenum_GLenum_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLboolean func;
    ARGS_void_GLenum_GLenum_GLboolean args;
} PACKED_void_GLenum_GLenum_GLboolean;
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_GLboolean args;
} INDEXED_void_GLenum_GLenum_GLboolean;
typedef void (*FUNC_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei)(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount);
typedef struct {
    GLenum a1;
    const GLint * a2;
    const GLsizei * a3;
    GLsizei a4;
} ARGS_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei func;
    ARGS_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei args;
} PACKED_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei;
typedef struct {
    int func;
    ARGS_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei args;
} INDEXED_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei;
typedef void (*FUNC_void_GLenum_const_GLsizei___GENPT___GLenum_GLvoid__GENPT__const___GENPT___GLsizei)(GLenum mode, const GLsizei * count, GLenum type, GLvoid*const * indices, GLsizei drawcount);
typedef struct {
    GLenum a1;
    const GLsizei * a2;
    GLenum a3;
    GLvoid*const * a4;
    GLsizei a5;
} ARGS_void_GLenum_const_GLsizei___GENPT___GLenum_GLvoid__GENPT__const___GENPT___GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_const_GLsizei___GENPT___GLenum_GLvoid__GENPT__const___GENPT___GLsizei func;
    ARGS_void_GLenum_const_GLsizei___GENPT___GLenum_GLvoid__GENPT__const___GENPT___GLsizei args;
} PACKED_void_GLenum_const_GLsizei___GENPT___GLenum_GLvoid__GENPT__const___GENPT___GLsizei;
typedef struct {
    int func;
    ARGS_void_GLenum_const_GLsizei___GENPT___GLenum_GLvoid__GENPT__const___GENPT___GLsizei args;
} INDEXED_void_GLenum_const_GLsizei___GENPT___GLenum_GLvoid__GENPT__const___GENPT___GLsizei;
typedef void (*FUNC_void_GLenum_GLdouble)(GLenum target, GLdouble s);
typedef struct {
    GLenum a1;
    GLdouble a2 __attribute__ ((aligned(8)));
} ARGS_void_GLenum_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLenum_GLdouble func;
    ARGS_void_GLenum_GLdouble args;
} PACKED_void_GLenum_GLdouble;
typedef struct {
    int func;
    ARGS_void_GLenum_GLdouble args;
} INDEXED_void_GLenum_GLdouble;
typedef void (*FUNC_void_GLenum_GLshort)(GLenum target, GLshort s);
typedef struct {
    GLenum a1;
    GLshort a2;
} ARGS_void_GLenum_GLshort;
typedef struct {
    int format;
    FUNC_void_GLenum_GLshort func;
    ARGS_void_GLenum_GLshort args;
} PACKED_void_GLenum_GLshort;
typedef struct {
    int func;
    ARGS_void_GLenum_GLshort args;
} INDEXED_void_GLenum_GLshort;
typedef void (*FUNC_void_GLenum_const_GLshort___GENPT__)(GLenum target, const GLshort * v);
typedef struct {
    GLenum a1;
    const GLshort * a2;
} ARGS_void_GLenum_const_GLshort___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_const_GLshort___GENPT__ func;
    ARGS_void_GLenum_const_GLshort___GENPT__ args;
} PACKED_void_GLenum_const_GLshort___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_const_GLshort___GENPT__ args;
} INDEXED_void_GLenum_const_GLshort___GENPT__;
typedef void (*FUNC_void_GLenum_GLdouble_GLdouble)(GLenum target, GLdouble s, GLdouble t);
typedef struct {
    GLenum a1;
    GLdouble a2 __attribute__ ((aligned(8)));
    GLdouble a3 __attribute__ ((aligned(8)));
} ARGS_void_GLenum_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLenum_GLdouble_GLdouble func;
    ARGS_void_GLenum_GLdouble_GLdouble args;
} PACKED_void_GLenum_GLdouble_GLdouble;
typedef struct {
    int func;
    ARGS_void_GLenum_GLdouble_GLdouble args;
} INDEXED_void_GLenum_GLdouble_GLdouble;
typedef void (*FUNC_void_GLenum_GLfloat_GLfloat)(GLenum target, GLfloat s, GLfloat t);
typedef struct {
    GLenum a1;
    GLfloat a2;
    GLfloat a3;
} ARGS_void_GLenum_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLenum_GLfloat_GLfloat func;
    ARGS_void_GLenum_GLfloat_GLfloat args;
} PACKED_void_GLenum_GLfloat_GLfloat;
typedef struct {
    int func;
    ARGS_void_GLenum_GLfloat_GLfloat args;
} INDEXED_void_GLenum_GLfloat_GLfloat;
typedef void (*FUNC_void_GLenum_GLshort_GLshort)(GLenum target, GLshort s, GLshort t);
typedef struct {
    GLenum a1;
    GLshort a2;
    GLshort a3;
} ARGS_void_GLenum_GLshort_GLshort;
typedef struct {
    int format;
    FUNC_void_GLenum_GLshort_GLshort func;
    ARGS_void_GLenum_GLshort_GLshort args;
} PACKED_void_GLenum_GLshort_GLshort;
typedef struct {
    int func;
    ARGS_void_GLenum_GLshort_GLshort args;
} INDEXED_void_GLenum_GLshort_GLshort;
typedef void (*FUNC_void_GLenum_GLdouble_GLdouble_GLdouble)(GLenum target, GLdouble s, GLdouble t, GLdouble r);
typedef struct {
    GLenum a1;
    GLdouble a2 __attribute__ ((aligned(8)));
    GLdouble a3 __attribute__ ((aligned(8)));
    GLdouble a4 __attribute__ ((aligned(8)));
} ARGS_void_GLenum_GLdouble_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLenum_GLdouble_GLdouble_GLdouble func;
    ARGS_void_GLenum_GLdouble_GLdouble_GLdouble args;
} PACKED_void_GLenum_GLdouble_GLdouble_GLdouble;
typedef struct {
    int func;
    ARGS_void_GLenum_GLdouble_GLdouble_GLdouble args;
} INDEXED_void_GLenum_GLdouble_GLdouble_GLdouble;
typedef void (*FUNC_void_GLenum_GLfloat_GLfloat_GLfloat)(GLenum target, GLfloat s, GLfloat t, GLfloat r);
typedef struct {
    GLenum a1;
    GLfloat a2;
    GLfloat a3;
    GLfloat a4;
} ARGS_void_GLenum_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLenum_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLenum_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLenum_GLfloat_GLfloat_GLfloat;
typedef struct {
    int func;
    ARGS_void_GLenum_GLfloat_GLfloat_GLfloat args;
} INDEXED_void_GLenum_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLenum_GLint_GLint_GLint)(GLenum target, GLint s, GLint t, GLint r);
typedef struct {
    GLenum a1;
    GLint a2;
    GLint a3;
    GLint a4;
} ARGS_void_GLenum_GLint_GLint_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLint func;
    ARGS_void_GLenum_GLint_GLint_GLint args;
} PACKED_void_GLenum_GLint_GLint_GLint;
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLint_GLint args;
} INDEXED_void_GLenum_GLint_GLint_GLint;
typedef void (*FUNC_void_GLenum_GLshort_GLshort_GLshort)(GLenum target, GLshort s, GLshort t, GLshort r);
typedef struct {
    GLenum a1;
    GLshort a2;
    GLshort a3;
    GLshort a4;
} ARGS_void_GLenum_GLshort_GLshort_GLshort;
typedef struct {
    int format;
    FUNC_void_GLenum_GLshort_GLshort_GLshort func;
    ARGS_void_GLenum_GLshort_GLshort_GLshort args;
} PACKED_void_GLenum_GLshort_GLshort_GLshort;
typedef struct {
    int func;
    ARGS_void_GLenum_GLshort_GLshort_GLshort args;
} INDEXED_void_GLenum_GLshort_GLshort_GLshort;
typedef void (*FUNC_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef struct {
    GLenum a1;
    GLdouble a2 __attribute__ ((aligned(8)));
    GLdouble a3 __attribute__ ((aligned(8)));
    GLdouble a4 __attribute__ ((aligned(8)));
    GLdouble a5 __attribute__ ((aligned(8)));
} ARGS_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble func;
    ARGS_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble args;
} PACKED_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble;
typedef struct {
    int func;
    ARGS_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble args;
} INDEXED_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble;
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
typedef void (*FUNC_void_GLenum_GLshort_GLshort_GLshort_GLshort)(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
typedef struct {
    GLenum a1;
    GLshort a2;
    GLshort a3;
    GLshort a4;
    GLshort a5;
} ARGS_void_GLenum_GLshort_GLshort_GLshort_GLshort;
typedef struct {
    int format;
    FUNC_void_GLenum_GLshort_GLshort_GLshort_GLshort func;
    ARGS_void_GLenum_GLshort_GLshort_GLshort_GLshort args;
} PACKED_void_GLenum_GLshort_GLshort_GLshort_GLshort;
typedef struct {
    int func;
    ARGS_void_GLenum_GLshort_GLshort_GLshort_GLshort args;
} INDEXED_void_GLenum_GLshort_GLshort_GLshort_GLshort;
typedef void (*FUNC_void_GLuint_GLenum)(GLuint list, GLenum mode);
typedef struct {
    GLuint a1;
    GLenum a2;
} ARGS_void_GLuint_GLenum;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum func;
    ARGS_void_GLuint_GLenum args;
} PACKED_void_GLuint_GLenum;
typedef struct {
    int func;
    ARGS_void_GLuint_GLenum args;
} INDEXED_void_GLuint_GLenum;
typedef void (*FUNC_void_GLenum_GLsizei_const_GLfloat___GENPT__)(GLenum map, GLsizei mapsize, const GLfloat * values);
typedef struct {
    GLenum a1;
    GLsizei a2;
    const GLfloat * a3;
} ARGS_void_GLenum_GLsizei_const_GLfloat___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_const_GLfloat___GENPT__ func;
    ARGS_void_GLenum_GLsizei_const_GLfloat___GENPT__ args;
} PACKED_void_GLenum_GLsizei_const_GLfloat___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLsizei_const_GLfloat___GENPT__ args;
} INDEXED_void_GLenum_GLsizei_const_GLfloat___GENPT__;
typedef void (*FUNC_void_GLenum_GLsizei_const_GLuint___GENPT__)(GLenum map, GLsizei mapsize, const GLuint * values);
typedef struct {
    GLenum a1;
    GLsizei a2;
    const GLuint * a3;
} ARGS_void_GLenum_GLsizei_const_GLuint___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_const_GLuint___GENPT__ func;
    ARGS_void_GLenum_GLsizei_const_GLuint___GENPT__ args;
} PACKED_void_GLenum_GLsizei_const_GLuint___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLsizei_const_GLuint___GENPT__ args;
} INDEXED_void_GLenum_GLsizei_const_GLuint___GENPT__;
typedef void (*FUNC_void_GLenum_GLsizei_const_GLushort___GENPT__)(GLenum map, GLsizei mapsize, const GLushort * values);
typedef struct {
    GLenum a1;
    GLsizei a2;
    const GLushort * a3;
} ARGS_void_GLenum_GLsizei_const_GLushort___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_const_GLushort___GENPT__ func;
    ARGS_void_GLenum_GLsizei_const_GLushort___GENPT__ args;
} PACKED_void_GLenum_GLsizei_const_GLushort___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLsizei_const_GLushort___GENPT__ args;
} INDEXED_void_GLenum_GLsizei_const_GLushort___GENPT__;
typedef void (*FUNC_void_GLsizei_const_GLuint___GENPT___const_GLfloat___GENPT__)(GLsizei n, const GLuint * textures, const GLfloat * priorities);
typedef struct {
    GLsizei a1;
    const GLuint * a2;
    const GLfloat * a3;
} ARGS_void_GLsizei_const_GLuint___GENPT___const_GLfloat___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLsizei_const_GLuint___GENPT___const_GLfloat___GENPT__ func;
    ARGS_void_GLsizei_const_GLuint___GENPT___const_GLfloat___GENPT__ args;
} PACKED_void_GLsizei_const_GLuint___GENPT___const_GLfloat___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLsizei_const_GLuint___GENPT___const_GLfloat___GENPT__ args;
} INDEXED_void_GLsizei_const_GLuint___GENPT___const_GLfloat___GENPT__;
typedef void (*FUNC_void_GLshort_GLshort)(GLshort x, GLshort y);
typedef struct {
    GLshort a1;
    GLshort a2;
} ARGS_void_GLshort_GLshort;
typedef struct {
    int format;
    FUNC_void_GLshort_GLshort func;
    ARGS_void_GLshort_GLshort args;
} PACKED_void_GLshort_GLshort;
typedef struct {
    int func;
    ARGS_void_GLshort_GLshort args;
} INDEXED_void_GLshort_GLshort;
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
typedef void (*FUNC_void_const_GLdouble___GENPT___const_GLdouble___GENPT__)(const GLdouble * v1, const GLdouble * v2);
typedef struct {
    const GLdouble * a1;
    const GLdouble * a2;
} ARGS_void_const_GLdouble___GENPT___const_GLdouble___GENPT__;
typedef struct {
    int format;
    FUNC_void_const_GLdouble___GENPT___const_GLdouble___GENPT__ func;
    ARGS_void_const_GLdouble___GENPT___const_GLdouble___GENPT__ args;
} PACKED_void_const_GLdouble___GENPT___const_GLdouble___GENPT__;
typedef struct {
    int func;
    ARGS_void_const_GLdouble___GENPT___const_GLdouble___GENPT__ args;
} INDEXED_void_const_GLdouble___GENPT___const_GLdouble___GENPT__;
typedef void (*FUNC_void_const_GLfloat___GENPT___const_GLfloat___GENPT__)(const GLfloat * v1, const GLfloat * v2);
typedef struct {
    const GLfloat * a1;
    const GLfloat * a2;
} ARGS_void_const_GLfloat___GENPT___const_GLfloat___GENPT__;
typedef struct {
    int format;
    FUNC_void_const_GLfloat___GENPT___const_GLfloat___GENPT__ func;
    ARGS_void_const_GLfloat___GENPT___const_GLfloat___GENPT__ args;
} PACKED_void_const_GLfloat___GENPT___const_GLfloat___GENPT__;
typedef struct {
    int func;
    ARGS_void_const_GLfloat___GENPT___const_GLfloat___GENPT__ args;
} INDEXED_void_const_GLfloat___GENPT___const_GLfloat___GENPT__;
typedef void (*FUNC_void_const_GLint___GENPT___const_GLint___GENPT__)(const GLint * v1, const GLint * v2);
typedef struct {
    const GLint * a1;
    const GLint * a2;
} ARGS_void_const_GLint___GENPT___const_GLint___GENPT__;
typedef struct {
    int format;
    FUNC_void_const_GLint___GENPT___const_GLint___GENPT__ func;
    ARGS_void_const_GLint___GENPT___const_GLint___GENPT__ args;
} PACKED_void_const_GLint___GENPT___const_GLint___GENPT__;
typedef struct {
    int func;
    ARGS_void_const_GLint___GENPT___const_GLint___GENPT__ args;
} INDEXED_void_const_GLint___GENPT___const_GLint___GENPT__;
typedef void (*FUNC_void_const_GLshort___GENPT___const_GLshort___GENPT__)(const GLshort * v1, const GLshort * v2);
typedef struct {
    const GLshort * a1;
    const GLshort * a2;
} ARGS_void_const_GLshort___GENPT___const_GLshort___GENPT__;
typedef struct {
    int format;
    FUNC_void_const_GLshort___GENPT___const_GLshort___GENPT__ func;
    ARGS_void_const_GLshort___GENPT___const_GLshort___GENPT__ args;
} PACKED_void_const_GLshort___GENPT___const_GLshort___GENPT__;
typedef struct {
    int func;
    ARGS_void_const_GLshort___GENPT___const_GLshort___GENPT__ args;
} INDEXED_void_const_GLshort___GENPT___const_GLshort___GENPT__;
typedef GLint (*FUNC_GLint_GLenum)(GLenum mode);
typedef struct {
    GLenum a1;
} ARGS_GLint_GLenum;
typedef struct {
    int format;
    FUNC_GLint_GLenum func;
    ARGS_GLint_GLenum args;
} PACKED_GLint_GLenum;
typedef struct {
    int func;
    ARGS_GLint_GLenum args;
} INDEXED_GLint_GLenum;
typedef void (*FUNC_void_GLfloat_GLboolean)(GLfloat value, GLboolean invert);
typedef struct {
    GLfloat a1;
    GLboolean a2;
} ARGS_void_GLfloat_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLfloat_GLboolean func;
    ARGS_void_GLfloat_GLboolean args;
} PACKED_void_GLfloat_GLboolean;
typedef struct {
    int func;
    ARGS_void_GLfloat_GLboolean args;
} INDEXED_void_GLfloat_GLboolean;
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
typedef void (*FUNC_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT___const_GLvoid___GENPT__)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * row, const GLvoid * column);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLsizei a3;
    GLsizei a4;
    GLenum a5;
    GLenum a6;
    const GLvoid * a7;
    const GLvoid * a8;
} ARGS_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT___const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT___const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT___const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT___const_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT___const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT___const_GLvoid___GENPT__;
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
typedef void (*FUNC_void_GLenum_GLenum_GLdouble)(GLenum coord, GLenum pname, GLdouble param);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLdouble a3 __attribute__ ((aligned(8)));
} ARGS_void_GLenum_GLenum_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLdouble func;
    ARGS_void_GLenum_GLenum_GLdouble args;
} PACKED_void_GLenum_GLenum_GLdouble;
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_GLdouble args;
} INDEXED_void_GLenum_GLenum_GLdouble;
typedef void (*FUNC_void_GLenum_GLenum_const_GLdouble___GENPT__)(GLenum coord, GLenum pname, const GLdouble * params);
typedef struct {
    GLenum a1;
    GLenum a2;
    const GLdouble * a3;
} ARGS_void_GLenum_GLenum_const_GLdouble___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_const_GLdouble___GENPT__ func;
    ARGS_void_GLenum_GLenum_const_GLdouble___GENPT__ args;
} PACKED_void_GLenum_GLenum_const_GLdouble___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLenum_const_GLdouble___GENPT__ args;
} INDEXED_void_GLenum_GLenum_const_GLdouble___GENPT__;
typedef void (*FUNC_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid * pixels);
typedef struct {
    GLenum a1;
    GLint a2;
    GLint a3;
    GLsizei a4;
    GLint a5;
    GLenum a6;
    GLenum a7;
    const GLvoid * a8;
} ARGS_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__;
typedef void (*FUNC_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid * pixels);
typedef struct {
    GLenum a1;
    GLint a2;
    GLint a3;
    GLsizei a4;
    GLsizei a5;
    GLsizei a6;
    GLint a7;
    GLenum a8;
    GLenum a9;
    const GLvoid * a10;
} ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__;
typedef void (*FUNC_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid * pixels);
typedef struct {
    GLenum a1;
    GLint a2;
    GLint a3;
    GLsizei a4;
    GLenum a5;
    GLenum a6;
    const GLvoid * a7;
} ARGS_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
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
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
typedef void (*FUNC_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * pixels);
typedef struct {
    GLenum a1;
    GLint a2;
    GLint a3;
    GLint a4;
    GLint a5;
    GLsizei a6;
    GLsizei a7;
    GLsizei a8;
    GLenum a9;
    GLenum a10;
    const GLvoid * a11;
} ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
typedef struct {
    int func;
    ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ args;
} INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
typedef int (*FUNC_int_Display___GENPT___int)(Display * dpy, int hpId);
typedef struct {
    Display * a1;
    int a2;
} ARGS_int_Display___GENPT___int;
typedef struct {
    int format;
    FUNC_int_Display___GENPT___int func;
    ARGS_int_Display___GENPT___int args;
} PACKED_int_Display___GENPT___int;
typedef struct {
    int func;
    ARGS_int_Display___GENPT___int args;
} INDEXED_int_Display___GENPT___int;
typedef void (*FUNC_void_uint32_t_uint32_t)(uint32_t window, uint32_t barrier);
typedef struct {
    uint32_t a1;
    uint32_t a2;
} ARGS_void_uint32_t_uint32_t;
typedef struct {
    int format;
    FUNC_void_uint32_t_uint32_t func;
    ARGS_void_uint32_t_uint32_t args;
} PACKED_void_uint32_t_uint32_t;
typedef struct {
    int func;
    ARGS_void_uint32_t_uint32_t args;
} INDEXED_void_uint32_t_uint32_t;
typedef void (*FUNC_void_uint32_t)(uint32_t drawable);
typedef struct {
    uint32_t a1;
} ARGS_void_uint32_t;
typedef struct {
    int format;
    FUNC_void_uint32_t func;
    ARGS_void_uint32_t args;
} PACKED_void_uint32_t;
typedef struct {
    int func;
    ARGS_void_uint32_t args;
} INDEXED_void_uint32_t;
typedef XVisualInfo * (*FUNC_XVisualInfo___GENPT___Display___GENPT___int_int___GENPT__)(Display * dpy, int screen, int * attribList);
typedef struct {
    Display * a1;
    int a2;
    int * a3;
} ARGS_XVisualInfo___GENPT___Display___GENPT___int_int___GENPT__;
typedef struct {
    int format;
    FUNC_XVisualInfo___GENPT___Display___GENPT___int_int___GENPT__ func;
    ARGS_XVisualInfo___GENPT___Display___GENPT___int_int___GENPT__ args;
} PACKED_XVisualInfo___GENPT___Display___GENPT___int_int___GENPT__;
typedef struct {
    int func;
    ARGS_XVisualInfo___GENPT___Display___GENPT___int_int___GENPT__ args;
} INDEXED_XVisualInfo___GENPT___Display___GENPT___int_int___GENPT__;
typedef void (*FUNC_void_Display___GENPT___GLXContext_GLXContext_unsigned_long)(Display * dpy, GLXContext src, GLXContext dst, unsigned long mask);
typedef struct {
    Display * a1;
    GLXContext a2;
    GLXContext a3;
    unsigned long a4;
} ARGS_void_Display___GENPT___GLXContext_GLXContext_unsigned_long;
typedef struct {
    int format;
    FUNC_void_Display___GENPT___GLXContext_GLXContext_unsigned_long func;
    ARGS_void_Display___GENPT___GLXContext_GLXContext_unsigned_long args;
} PACKED_void_Display___GENPT___GLXContext_GLXContext_unsigned_long;
typedef struct {
    int func;
    ARGS_void_Display___GENPT___GLXContext_GLXContext_unsigned_long args;
} INDEXED_void_Display___GENPT___GLXContext_GLXContext_unsigned_long;
typedef GLXContext (*FUNC_GLXContext_Display___GENPT___XVisualInfo___GENPT___GLXContext_Bool)(Display * dpy, XVisualInfo * vis, GLXContext shareList, Bool direct);
typedef struct {
    Display * a1;
    XVisualInfo * a2;
    GLXContext a3;
    Bool a4;
} ARGS_GLXContext_Display___GENPT___XVisualInfo___GENPT___GLXContext_Bool;
typedef struct {
    int format;
    FUNC_GLXContext_Display___GENPT___XVisualInfo___GENPT___GLXContext_Bool func;
    ARGS_GLXContext_Display___GENPT___XVisualInfo___GENPT___GLXContext_Bool args;
} PACKED_GLXContext_Display___GENPT___XVisualInfo___GENPT___GLXContext_Bool;
typedef struct {
    int func;
    ARGS_GLXContext_Display___GENPT___XVisualInfo___GENPT___GLXContext_Bool args;
} INDEXED_GLXContext_Display___GENPT___XVisualInfo___GENPT___GLXContext_Bool;
typedef void (*FUNC_void_uint32_t_uint32_t_uint32_t_uint32_t)(uint32_t gc_id, uint32_t screen, uint32_t config, uint32_t share_list);
typedef struct {
    uint32_t a1;
    uint32_t a2;
    uint32_t a3;
    uint32_t a4;
} ARGS_void_uint32_t_uint32_t_uint32_t_uint32_t;
typedef struct {
    int format;
    FUNC_void_uint32_t_uint32_t_uint32_t_uint32_t func;
    ARGS_void_uint32_t_uint32_t_uint32_t_uint32_t args;
} PACKED_void_uint32_t_uint32_t_uint32_t_uint32_t;
typedef struct {
    int func;
    ARGS_void_uint32_t_uint32_t_uint32_t_uint32_t args;
} INDEXED_void_uint32_t_uint32_t_uint32_t_uint32_t;
typedef GLXPixmap (*FUNC_GLXPixmap_Display___GENPT___XVisualInfo___GENPT___Pixmap)(Display * dpy, XVisualInfo * visual, Pixmap pixmap);
typedef struct {
    Display * a1;
    XVisualInfo * a2;
    Pixmap a3;
} ARGS_GLXPixmap_Display___GENPT___XVisualInfo___GENPT___Pixmap;
typedef struct {
    int format;
    FUNC_GLXPixmap_Display___GENPT___XVisualInfo___GENPT___Pixmap func;
    ARGS_GLXPixmap_Display___GENPT___XVisualInfo___GENPT___Pixmap args;
} PACKED_GLXPixmap_Display___GENPT___XVisualInfo___GENPT___Pixmap;
typedef struct {
    int func;
    ARGS_GLXPixmap_Display___GENPT___XVisualInfo___GENPT___Pixmap args;
} INDEXED_GLXPixmap_Display___GENPT___XVisualInfo___GENPT___Pixmap;
typedef void (*FUNC_void_uint32_t_uint32_t_uint32_t)(uint32_t config, uint32_t pixmap, uint32_t glxpixmap);
typedef struct {
    uint32_t a1;
    uint32_t a2;
    uint32_t a3;
} ARGS_void_uint32_t_uint32_t_uint32_t;
typedef struct {
    int format;
    FUNC_void_uint32_t_uint32_t_uint32_t func;
    ARGS_void_uint32_t_uint32_t_uint32_t args;
} PACKED_void_uint32_t_uint32_t_uint32_t;
typedef struct {
    int func;
    ARGS_void_uint32_t_uint32_t_uint32_t args;
} INDEXED_void_uint32_t_uint32_t_uint32_t;
typedef void (*FUNC_void_Display___GENPT___uint32_t_uint32_t_uint32_t_uint32_t_uint32_t)(Display * dpy, uint32_t screen, uint32_t server, uint32_t path, uint32_t class, uint32_t node);
typedef struct {
    Display * a1;
    uint32_t a2;
    uint32_t a3;
    uint32_t a4;
    uint32_t a5;
    uint32_t a6;
} ARGS_void_Display___GENPT___uint32_t_uint32_t_uint32_t_uint32_t_uint32_t;
typedef struct {
    int format;
    FUNC_void_Display___GENPT___uint32_t_uint32_t_uint32_t_uint32_t_uint32_t func;
    ARGS_void_Display___GENPT___uint32_t_uint32_t_uint32_t_uint32_t_uint32_t args;
} PACKED_void_Display___GENPT___uint32_t_uint32_t_uint32_t_uint32_t_uint32_t;
typedef struct {
    int func;
    ARGS_void_Display___GENPT___uint32_t_uint32_t_uint32_t_uint32_t_uint32_t args;
} INDEXED_void_Display___GENPT___uint32_t_uint32_t_uint32_t_uint32_t_uint32_t;
typedef void (*FUNC_void_Display___GENPT___GLXContext)(Display * dpy, GLXContext ctx);
typedef struct {
    Display * a1;
    GLXContext a2;
} ARGS_void_Display___GENPT___GLXContext;
typedef struct {
    int format;
    FUNC_void_Display___GENPT___GLXContext func;
    ARGS_void_Display___GENPT___GLXContext args;
} PACKED_void_Display___GENPT___GLXContext;
typedef struct {
    int func;
    ARGS_void_Display___GENPT___GLXContext args;
} INDEXED_void_Display___GENPT___GLXContext;
typedef void (*FUNC_void_Display___GENPT___GLXPixmap)(Display * dpy, GLXPixmap pixmap);
typedef struct {
    Display * a1;
    GLXPixmap a2;
} ARGS_void_Display___GENPT___GLXPixmap;
typedef struct {
    int format;
    FUNC_void_Display___GENPT___GLXPixmap func;
    ARGS_void_Display___GENPT___GLXPixmap args;
} PACKED_void_Display___GENPT___GLXPixmap;
typedef struct {
    int func;
    ARGS_void_Display___GENPT___GLXPixmap args;
} INDEXED_void_Display___GENPT___GLXPixmap;
typedef void (*FUNC_void_Display___GENPT___uint32_t)(Display * dpy, uint32_t glxvideosource);
typedef struct {
    Display * a1;
    uint32_t a2;
} ARGS_void_Display___GENPT___uint32_t;
typedef struct {
    int format;
    FUNC_void_Display___GENPT___uint32_t func;
    ARGS_void_Display___GENPT___uint32_t args;
} PACKED_void_Display___GENPT___uint32_t;
typedef struct {
    int func;
    ARGS_void_Display___GENPT___uint32_t args;
} INDEXED_void_Display___GENPT___uint32_t;
typedef const char * (*FUNC_const_char___GENPT___Display___GENPT___int)(Display * display, int name);
typedef struct {
    Display * a1;
    int a2;
} ARGS_const_char___GENPT___Display___GENPT___int;
typedef struct {
    int format;
    FUNC_const_char___GENPT___Display___GENPT___int func;
    ARGS_const_char___GENPT___Display___GENPT___int args;
} PACKED_const_char___GENPT___Display___GENPT___int;
typedef struct {
    int func;
    ARGS_const_char___GENPT___Display___GENPT___int args;
} INDEXED_const_char___GENPT___Display___GENPT___int;
typedef int (*FUNC_int_Display___GENPT___XVisualInfo___GENPT___int_int___GENPT__)(Display * display, XVisualInfo * visual, int attribute, int * value);
typedef struct {
    Display * a1;
    XVisualInfo * a2;
    int a3;
    int * a4;
} ARGS_int_Display___GENPT___XVisualInfo___GENPT___int_int___GENPT__;
typedef struct {
    int format;
    FUNC_int_Display___GENPT___XVisualInfo___GENPT___int_int___GENPT__ func;
    ARGS_int_Display___GENPT___XVisualInfo___GENPT___int_int___GENPT__ args;
} PACKED_int_Display___GENPT___XVisualInfo___GENPT___int_int___GENPT__;
typedef struct {
    int func;
    ARGS_int_Display___GENPT___XVisualInfo___GENPT___int_int___GENPT__ args;
} INDEXED_int_Display___GENPT___XVisualInfo___GENPT___int_int___GENPT__;
typedef GLXContext (*FUNC_GLXContext)();
typedef struct {
} ARGS_GLXContext;
typedef struct {
    int format;
    FUNC_GLXContext func;
    ARGS_GLXContext args;
} PACKED_GLXContext;
typedef struct {
    int func;
    ARGS_GLXContext args;
} INDEXED_GLXContext;
typedef GLXDrawable (*FUNC_GLXDrawable)();
typedef struct {
} ARGS_GLXDrawable;
typedef struct {
    int format;
    FUNC_GLXDrawable func;
    ARGS_GLXDrawable args;
} PACKED_GLXDrawable;
typedef struct {
    int func;
    ARGS_GLXDrawable args;
} INDEXED_GLXDrawable;
typedef int (*FUNC_int_Display___GENPT___int_int_int_const_void___GENPT__)(Display * dpy, int timeSlice, int attrib, int size, const void * attribList);
typedef struct {
    Display * a1;
    int a2;
    int a3;
    int a4;
    const void * a5;
} ARGS_int_Display___GENPT___int_int_int_const_void___GENPT__;
typedef struct {
    int format;
    FUNC_int_Display___GENPT___int_int_int_const_void___GENPT__ func;
    ARGS_int_Display___GENPT___int_int_int_const_void___GENPT__ args;
} PACKED_int_Display___GENPT___int_int_int_const_void___GENPT__;
typedef struct {
    int func;
    ARGS_int_Display___GENPT___int_int_int_const_void___GENPT__ args;
} INDEXED_int_Display___GENPT___int_int_int_const_void___GENPT__;
typedef int (*FUNC_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__)(Display * dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX cfg, int * hpId);
typedef struct {
    Display * a1;
    int a2;
    int a3;
    GLXHyperpipeConfigSGIX a4;
    int * a5;
} ARGS_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__;
typedef struct {
    int format;
    FUNC_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__ func;
    ARGS_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__ args;
} PACKED_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__;
typedef struct {
    int func;
    ARGS_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__ args;
} INDEXED_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__;
typedef Bool (*FUNC_Bool_Display___GENPT___GLXContext)(Display * dpy, GLXContext ctx);
typedef struct {
    Display * a1;
    GLXContext a2;
} ARGS_Bool_Display___GENPT___GLXContext;
typedef struct {
    int format;
    FUNC_Bool_Display___GENPT___GLXContext func;
    ARGS_Bool_Display___GENPT___GLXContext args;
} PACKED_Bool_Display___GENPT___GLXContext;
typedef struct {
    int func;
    ARGS_Bool_Display___GENPT___GLXContext args;
} INDEXED_Bool_Display___GENPT___GLXContext;
typedef Bool (*FUNC_Bool_Display___GENPT___GLXDrawable_GLXContext)(Display * dpy, GLXDrawable drawable, GLXContext ctx);
typedef struct {
    Display * a1;
    GLXDrawable a2;
    GLXContext a3;
} ARGS_Bool_Display___GENPT___GLXDrawable_GLXContext;
typedef struct {
    int format;
    FUNC_Bool_Display___GENPT___GLXDrawable_GLXContext func;
    ARGS_Bool_Display___GENPT___GLXDrawable_GLXContext args;
} PACKED_Bool_Display___GENPT___GLXDrawable_GLXContext;
typedef struct {
    int func;
    ARGS_Bool_Display___GENPT___GLXDrawable_GLXContext args;
} INDEXED_Bool_Display___GENPT___GLXDrawable_GLXContext;
typedef Bool (*FUNC_Bool_Display___GENPT___int___GENPT___int___GENPT__)(Display * display, int * errorBase, int * eventBase);
typedef struct {
    Display * a1;
    int * a2;
    int * a3;
} ARGS_Bool_Display___GENPT___int___GENPT___int___GENPT__;
typedef struct {
    int format;
    FUNC_Bool_Display___GENPT___int___GENPT___int___GENPT__ func;
    ARGS_Bool_Display___GENPT___int___GENPT___int___GENPT__ args;
} PACKED_Bool_Display___GENPT___int___GENPT___int___GENPT__;
typedef struct {
    int func;
    ARGS_Bool_Display___GENPT___int___GENPT___int___GENPT__ args;
} INDEXED_Bool_Display___GENPT___int___GENPT___int___GENPT__;
typedef int (*FUNC_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__)(Display * dpy, int timeSlice, int attrib, int size, const void * attribList, void * returnAttribList);
typedef struct {
    Display * a1;
    int a2;
    int a3;
    int a4;
    const void * a5;
    void * a6;
} ARGS_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__;
typedef struct {
    int format;
    FUNC_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__ func;
    ARGS_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__ args;
} PACKED_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__;
typedef struct {
    int func;
    ARGS_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__ args;
} INDEXED_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__;
typedef GLXHyperpipeConfigSGIX * (*FUNC_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__)(Display * dpy, int hpId, int * npipes);
typedef struct {
    Display * a1;
    int a2;
    int * a3;
} ARGS_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__;
typedef struct {
    int format;
    FUNC_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__ func;
    ARGS_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__ args;
} PACKED_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__;
typedef struct {
    int func;
    ARGS_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__ args;
} INDEXED_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__;
typedef GLXHyperpipeNetworkSGIX * (*FUNC_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__)(Display * dpy, int * npipes);
typedef struct {
    Display * a1;
    int * a2;
} ARGS_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__;
typedef struct {
    int format;
    FUNC_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__ func;
    ARGS_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__ args;
} PACKED_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__;
typedef struct {
    int func;
    ARGS_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__ args;
} INDEXED_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__;
typedef const char * (*FUNC_const_char___GENPT___Display___GENPT___int_int)(Display * dpy, int screen, int name);
typedef struct {
    Display * a1;
    int a2;
    int a3;
} ARGS_const_char___GENPT___Display___GENPT___int_int;
typedef struct {
    int format;
    FUNC_const_char___GENPT___Display___GENPT___int_int func;
    ARGS_const_char___GENPT___Display___GENPT___int_int args;
} PACKED_const_char___GENPT___Display___GENPT___int_int;
typedef struct {
    int func;
    ARGS_const_char___GENPT___Display___GENPT___int_int args;
} INDEXED_const_char___GENPT___Display___GENPT___int_int;
typedef void (*FUNC_void_Display___GENPT___GLXDrawable)(Display * dpy, GLXDrawable drawable);
typedef struct {
    Display * a1;
    GLXDrawable a2;
} ARGS_void_Display___GENPT___GLXDrawable;
typedef struct {
    int format;
    FUNC_void_Display___GENPT___GLXDrawable func;
    ARGS_void_Display___GENPT___GLXDrawable args;
} PACKED_void_Display___GENPT___GLXDrawable;
typedef struct {
    int func;
    ARGS_void_Display___GENPT___GLXDrawable args;
} INDEXED_void_Display___GENPT___GLXDrawable;
typedef void (*FUNC_void_Font_int_int_int)(Font font, int first, int count, int list);
typedef struct {
    Font a1;
    int a2;
    int a3;
    int a4;
} ARGS_void_Font_int_int_int;
typedef struct {
    int format;
    FUNC_void_Font_int_int_int func;
    ARGS_void_Font_int_int_int args;
} PACKED_void_Font_int_int_int;
typedef struct {
    int func;
    ARGS_void_Font_int_int_int args;
} INDEXED_void_Font_int_int_int;
typedef GLXFBConfig * (*FUNC_GLXFBConfig___GENPT___Display___GENPT___int_const_int___GENPT___int___GENPT__)(Display * dpy, int screen, const int * attrib_list, int * nelements);
typedef struct {
    Display * a1;
    int a2;
    const int * a3;
    int * a4;
} ARGS_GLXFBConfig___GENPT___Display___GENPT___int_const_int___GENPT___int___GENPT__;
typedef struct {
    int format;
    FUNC_GLXFBConfig___GENPT___Display___GENPT___int_const_int___GENPT___int___GENPT__ func;
    ARGS_GLXFBConfig___GENPT___Display___GENPT___int_const_int___GENPT___int___GENPT__ args;
} PACKED_GLXFBConfig___GENPT___Display___GENPT___int_const_int___GENPT___int___GENPT__;
typedef struct {
    int func;
    ARGS_GLXFBConfig___GENPT___Display___GENPT___int_const_int___GENPT___int___GENPT__ args;
} INDEXED_GLXFBConfig___GENPT___Display___GENPT___int_const_int___GENPT___int___GENPT__;
typedef GLXContext (*FUNC_GLXContext_Display___GENPT___GLXFBConfig_int_GLXContext_Bool)(Display * dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct);
typedef struct {
    Display * a1;
    GLXFBConfig a2;
    int a3;
    GLXContext a4;
    Bool a5;
} ARGS_GLXContext_Display___GENPT___GLXFBConfig_int_GLXContext_Bool;
typedef struct {
    int format;
    FUNC_GLXContext_Display___GENPT___GLXFBConfig_int_GLXContext_Bool func;
    ARGS_GLXContext_Display___GENPT___GLXFBConfig_int_GLXContext_Bool args;
} PACKED_GLXContext_Display___GENPT___GLXFBConfig_int_GLXContext_Bool;
typedef struct {
    int func;
    ARGS_GLXContext_Display___GENPT___GLXFBConfig_int_GLXContext_Bool args;
} INDEXED_GLXContext_Display___GENPT___GLXFBConfig_int_GLXContext_Bool;
typedef GLXPbuffer (*FUNC_GLXPbuffer_Display___GENPT___GLXFBConfig_const_int___GENPT__)(Display * dpy, GLXFBConfig config, const int * attrib_list);
typedef struct {
    Display * a1;
    GLXFBConfig a2;
    const int * a3;
} ARGS_GLXPbuffer_Display___GENPT___GLXFBConfig_const_int___GENPT__;
typedef struct {
    int format;
    FUNC_GLXPbuffer_Display___GENPT___GLXFBConfig_const_int___GENPT__ func;
    ARGS_GLXPbuffer_Display___GENPT___GLXFBConfig_const_int___GENPT__ args;
} PACKED_GLXPbuffer_Display___GENPT___GLXFBConfig_const_int___GENPT__;
typedef struct {
    int func;
    ARGS_GLXPbuffer_Display___GENPT___GLXFBConfig_const_int___GENPT__ args;
} INDEXED_GLXPbuffer_Display___GENPT___GLXFBConfig_const_int___GENPT__;
typedef GLXPixmap (*FUNC_GLXPixmap_Display___GENPT___GLXFBConfig_Pixmap_const_int___GENPT__)(Display * dpy, GLXFBConfig config, Pixmap pixmap, const int * attrib_list);
typedef struct {
    Display * a1;
    GLXFBConfig a2;
    Pixmap a3;
    const int * a4;
} ARGS_GLXPixmap_Display___GENPT___GLXFBConfig_Pixmap_const_int___GENPT__;
typedef struct {
    int format;
    FUNC_GLXPixmap_Display___GENPT___GLXFBConfig_Pixmap_const_int___GENPT__ func;
    ARGS_GLXPixmap_Display___GENPT___GLXFBConfig_Pixmap_const_int___GENPT__ args;
} PACKED_GLXPixmap_Display___GENPT___GLXFBConfig_Pixmap_const_int___GENPT__;
typedef struct {
    int func;
    ARGS_GLXPixmap_Display___GENPT___GLXFBConfig_Pixmap_const_int___GENPT__ args;
} INDEXED_GLXPixmap_Display___GENPT___GLXFBConfig_Pixmap_const_int___GENPT__;
typedef GLXWindow (*FUNC_GLXWindow_Display___GENPT___GLXFBConfig_Window_const_int___GENPT__)(Display * dpy, GLXFBConfig config, Window win, const int * attrib_list);
typedef struct {
    Display * a1;
    GLXFBConfig a2;
    Window a3;
    const int * a4;
} ARGS_GLXWindow_Display___GENPT___GLXFBConfig_Window_const_int___GENPT__;
typedef struct {
    int format;
    FUNC_GLXWindow_Display___GENPT___GLXFBConfig_Window_const_int___GENPT__ func;
    ARGS_GLXWindow_Display___GENPT___GLXFBConfig_Window_const_int___GENPT__ args;
} PACKED_GLXWindow_Display___GENPT___GLXFBConfig_Window_const_int___GENPT__;
typedef struct {
    int func;
    ARGS_GLXWindow_Display___GENPT___GLXFBConfig_Window_const_int___GENPT__ args;
} INDEXED_GLXWindow_Display___GENPT___GLXFBConfig_Window_const_int___GENPT__;
typedef void (*FUNC_void_Display___GENPT___GLXPbuffer)(Display * dpy, GLXPbuffer pbuf);
typedef struct {
    Display * a1;
    GLXPbuffer a2;
} ARGS_void_Display___GENPT___GLXPbuffer;
typedef struct {
    int format;
    FUNC_void_Display___GENPT___GLXPbuffer func;
    ARGS_void_Display___GENPT___GLXPbuffer args;
} PACKED_void_Display___GENPT___GLXPbuffer;
typedef struct {
    int func;
    ARGS_void_Display___GENPT___GLXPbuffer args;
} INDEXED_void_Display___GENPT___GLXPbuffer;
typedef void (*FUNC_void_Display___GENPT___GLXWindow)(Display * dpy, GLXWindow win);
typedef struct {
    Display * a1;
    GLXWindow a2;
} ARGS_void_Display___GENPT___GLXWindow;
typedef struct {
    int format;
    FUNC_void_Display___GENPT___GLXWindow func;
    ARGS_void_Display___GENPT___GLXWindow args;
} PACKED_void_Display___GENPT___GLXWindow;
typedef struct {
    int func;
    ARGS_void_Display___GENPT___GLXWindow args;
} INDEXED_void_Display___GENPT___GLXWindow;
typedef Display * (*FUNC_Display___GENPT__)();
typedef struct {
} ARGS_Display___GENPT__;
typedef struct {
    int format;
    FUNC_Display___GENPT__ func;
    ARGS_Display___GENPT__ args;
} PACKED_Display___GENPT__;
typedef struct {
    int func;
    ARGS_Display___GENPT__ args;
} INDEXED_Display___GENPT__;
typedef int (*FUNC_int_Display___GENPT___GLXFBConfig_int_int___GENPT__)(Display * dpy, GLXFBConfig config, int attribute, int * value);
typedef struct {
    Display * a1;
    GLXFBConfig a2;
    int a3;
    int * a4;
} ARGS_int_Display___GENPT___GLXFBConfig_int_int___GENPT__;
typedef struct {
    int format;
    FUNC_int_Display___GENPT___GLXFBConfig_int_int___GENPT__ func;
    ARGS_int_Display___GENPT___GLXFBConfig_int_int___GENPT__ args;
} PACKED_int_Display___GENPT___GLXFBConfig_int_int___GENPT__;
typedef struct {
    int func;
    ARGS_int_Display___GENPT___GLXFBConfig_int_int___GENPT__ args;
} INDEXED_int_Display___GENPT___GLXFBConfig_int_int___GENPT__;
typedef GLXFBConfig * (*FUNC_GLXFBConfig___GENPT___Display___GENPT___int_int___GENPT__)(Display * dpy, int screen, int * nelements);
typedef struct {
    Display * a1;
    int a2;
    int * a3;
} ARGS_GLXFBConfig___GENPT___Display___GENPT___int_int___GENPT__;
typedef struct {
    int format;
    FUNC_GLXFBConfig___GENPT___Display___GENPT___int_int___GENPT__ func;
    ARGS_GLXFBConfig___GENPT___Display___GENPT___int_int___GENPT__ args;
} PACKED_GLXFBConfig___GENPT___Display___GENPT___int_int___GENPT__;
typedef struct {
    int func;
    ARGS_GLXFBConfig___GENPT___Display___GENPT___int_int___GENPT__ args;
} INDEXED_GLXFBConfig___GENPT___Display___GENPT___int_int___GENPT__;
typedef __GLXextFuncPtr (*FUNC___GLXextFuncPtr_const_GLubyte___GENPT__)(const GLubyte * procName);
typedef struct {
    const GLubyte * a1;
} ARGS___GLXextFuncPtr_const_GLubyte___GENPT__;
typedef struct {
    int format;
    FUNC___GLXextFuncPtr_const_GLubyte___GENPT__ func;
    ARGS___GLXextFuncPtr_const_GLubyte___GENPT__ args;
} PACKED___GLXextFuncPtr_const_GLubyte___GENPT__;
typedef struct {
    int func;
    ARGS___GLXextFuncPtr_const_GLubyte___GENPT__ args;
} INDEXED___GLXextFuncPtr_const_GLubyte___GENPT__;
typedef void (*FUNC_void_Display___GENPT___GLXDrawable_unsigned_long___GENPT__)(Display * dpy, GLXDrawable draw, unsigned long * event_mask);
typedef struct {
    Display * a1;
    GLXDrawable a2;
    unsigned long * a3;
} ARGS_void_Display___GENPT___GLXDrawable_unsigned_long___GENPT__;
typedef struct {
    int format;
    FUNC_void_Display___GENPT___GLXDrawable_unsigned_long___GENPT__ func;
    ARGS_void_Display___GENPT___GLXDrawable_unsigned_long___GENPT__ args;
} PACKED_void_Display___GENPT___GLXDrawable_unsigned_long___GENPT__;
typedef struct {
    int func;
    ARGS_void_Display___GENPT___GLXDrawable_unsigned_long___GENPT__ args;
} INDEXED_void_Display___GENPT___GLXDrawable_unsigned_long___GENPT__;
typedef XVisualInfo * (*FUNC_XVisualInfo___GENPT___Display___GENPT___GLXFBConfig)(Display * dpy, GLXFBConfig config);
typedef struct {
    Display * a1;
    GLXFBConfig a2;
} ARGS_XVisualInfo___GENPT___Display___GENPT___GLXFBConfig;
typedef struct {
    int format;
    FUNC_XVisualInfo___GENPT___Display___GENPT___GLXFBConfig func;
    ARGS_XVisualInfo___GENPT___Display___GENPT___GLXFBConfig args;
} PACKED_XVisualInfo___GENPT___Display___GENPT___GLXFBConfig;
typedef struct {
    int func;
    ARGS_XVisualInfo___GENPT___Display___GENPT___GLXFBConfig args;
} INDEXED_XVisualInfo___GENPT___Display___GENPT___GLXFBConfig;
typedef Bool (*FUNC_Bool_Display___GENPT___GLXDrawable_GLXDrawable_GLXContext)(Display * dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
typedef struct {
    Display * a1;
    GLXDrawable a2;
    GLXDrawable a3;
    GLXContext a4;
} ARGS_Bool_Display___GENPT___GLXDrawable_GLXDrawable_GLXContext;
typedef struct {
    int format;
    FUNC_Bool_Display___GENPT___GLXDrawable_GLXDrawable_GLXContext func;
    ARGS_Bool_Display___GENPT___GLXDrawable_GLXDrawable_GLXContext args;
} PACKED_Bool_Display___GENPT___GLXDrawable_GLXDrawable_GLXContext;
typedef struct {
    int func;
    ARGS_Bool_Display___GENPT___GLXDrawable_GLXDrawable_GLXContext args;
} INDEXED_Bool_Display___GENPT___GLXDrawable_GLXDrawable_GLXContext;
typedef int (*FUNC_int_Display___GENPT___GLXContext_int_int___GENPT__)(Display * dpy, GLXContext ctx, int attribute, int * value);
typedef struct {
    Display * a1;
    GLXContext a2;
    int a3;
    int * a4;
} ARGS_int_Display___GENPT___GLXContext_int_int___GENPT__;
typedef struct {
    int format;
    FUNC_int_Display___GENPT___GLXContext_int_int___GENPT__ func;
    ARGS_int_Display___GENPT___GLXContext_int_int___GENPT__ args;
} PACKED_int_Display___GENPT___GLXContext_int_int___GENPT__;
typedef struct {
    int func;
    ARGS_int_Display___GENPT___GLXContext_int_int___GENPT__ args;
} INDEXED_int_Display___GENPT___GLXContext_int_int___GENPT__;
typedef void (*FUNC_void_Display___GENPT___GLXDrawable_int_unsigned_int___GENPT__)(Display * dpy, GLXDrawable draw, int attribute, unsigned int * value);
typedef struct {
    Display * a1;
    GLXDrawable a2;
    int a3;
    unsigned int * a4;
} ARGS_void_Display___GENPT___GLXDrawable_int_unsigned_int___GENPT__;
typedef struct {
    int format;
    FUNC_void_Display___GENPT___GLXDrawable_int_unsigned_int___GENPT__ func;
    ARGS_void_Display___GENPT___GLXDrawable_int_unsigned_int___GENPT__ args;
} PACKED_void_Display___GENPT___GLXDrawable_int_unsigned_int___GENPT__;
typedef struct {
    int func;
    ARGS_void_Display___GENPT___GLXDrawable_int_unsigned_int___GENPT__ args;
} INDEXED_void_Display___GENPT___GLXDrawable_int_unsigned_int___GENPT__;
typedef void (*FUNC_void_Display___GENPT___GLXDrawable_unsigned_long)(Display * dpy, GLXDrawable draw, unsigned long event_mask);
typedef struct {
    Display * a1;
    GLXDrawable a2;
    unsigned long a3;
} ARGS_void_Display___GENPT___GLXDrawable_unsigned_long;
typedef struct {
    int format;
    FUNC_void_Display___GENPT___GLXDrawable_unsigned_long func;
    ARGS_void_Display___GENPT___GLXDrawable_unsigned_long args;
} PACKED_void_Display___GENPT___GLXDrawable_unsigned_long;
typedef struct {
    int func;
    ARGS_void_Display___GENPT___GLXDrawable_unsigned_long args;
} INDEXED_void_Display___GENPT___GLXDrawable_unsigned_long;

extern void glPushCall(void *data);
void glPackedCall(const packed_call_t *packed);
void glIndexedCall(const indexed_call_t *packed, void *ret_v);

#define glAccum_INDEX 1
#define glAccum_RETURN void
#define glAccum_ARG_NAMES op, value
#define glAccum_ARG_EXPAND GLenum op, GLfloat value
#define glAccum_PACKED PACKED_void_GLenum_GLfloat
#define glAccum_INDEXED INDEXED_void_GLenum_GLfloat
#define glAccum_FORMAT FORMAT_void_GLenum_GLfloat
#define glActiveTexture_INDEX 2
#define glActiveTexture_RETURN void
#define glActiveTexture_ARG_NAMES texture
#define glActiveTexture_ARG_EXPAND GLenum texture
#define glActiveTexture_PACKED PACKED_void_GLenum
#define glActiveTexture_INDEXED INDEXED_void_GLenum
#define glActiveTexture_FORMAT FORMAT_void_GLenum
#define glAlphaFunc_INDEX 3
#define glAlphaFunc_RETURN void
#define glAlphaFunc_ARG_NAMES func, ref
#define glAlphaFunc_ARG_EXPAND GLenum func, GLfloat ref
#define glAlphaFunc_PACKED PACKED_void_GLenum_GLfloat
#define glAlphaFunc_INDEXED INDEXED_void_GLenum_GLfloat
#define glAlphaFunc_FORMAT FORMAT_void_GLenum_GLfloat
#define glAreTexturesResident_INDEX 4
#define glAreTexturesResident_RETURN GLboolean
#define glAreTexturesResident_ARG_NAMES n, textures, residences
#define glAreTexturesResident_ARG_EXPAND GLsizei n, const GLuint * textures, GLboolean * residences
#define glAreTexturesResident_PACKED PACKED_GLboolean_GLsizei_const_GLuint___GENPT___GLboolean___GENPT__
#define glAreTexturesResident_INDEXED INDEXED_GLboolean_GLsizei_const_GLuint___GENPT___GLboolean___GENPT__
#define glAreTexturesResident_FORMAT FORMAT_GLboolean_GLsizei_const_GLuint___GENPT___GLboolean___GENPT__
#define glArrayElement_INDEX 5
#define glArrayElement_RETURN void
#define glArrayElement_ARG_NAMES i
#define glArrayElement_ARG_EXPAND GLint i
#define glArrayElement_PACKED PACKED_void_GLint
#define glArrayElement_INDEXED INDEXED_void_GLint
#define glArrayElement_FORMAT FORMAT_void_GLint
#define glBegin_INDEX 6
#define glBegin_RETURN void
#define glBegin_ARG_NAMES mode
#define glBegin_ARG_EXPAND GLenum mode
#define glBegin_PACKED PACKED_void_GLenum
#define glBegin_INDEXED INDEXED_void_GLenum
#define glBegin_FORMAT FORMAT_void_GLenum
#define glBeginQuery_INDEX 7
#define glBeginQuery_RETURN void
#define glBeginQuery_ARG_NAMES target, id
#define glBeginQuery_ARG_EXPAND GLenum target, GLuint id
#define glBeginQuery_PACKED PACKED_void_GLenum_GLuint
#define glBeginQuery_INDEXED INDEXED_void_GLenum_GLuint
#define glBeginQuery_FORMAT FORMAT_void_GLenum_GLuint
#define glBindBuffer_INDEX 8
#define glBindBuffer_RETURN void
#define glBindBuffer_ARG_NAMES target, buffer
#define glBindBuffer_ARG_EXPAND GLenum target, GLuint buffer
#define glBindBuffer_PACKED PACKED_void_GLenum_GLuint
#define glBindBuffer_INDEXED INDEXED_void_GLenum_GLuint
#define glBindBuffer_FORMAT FORMAT_void_GLenum_GLuint
#define glBindTexture_INDEX 9
#define glBindTexture_RETURN void
#define glBindTexture_ARG_NAMES target, texture
#define glBindTexture_ARG_EXPAND GLenum target, GLuint texture
#define glBindTexture_PACKED PACKED_void_GLenum_GLuint
#define glBindTexture_INDEXED INDEXED_void_GLenum_GLuint
#define glBindTexture_FORMAT FORMAT_void_GLenum_GLuint
#define glBitmap_INDEX 10
#define glBitmap_RETURN void
#define glBitmap_ARG_NAMES width, height, xorig, yorig, xmove, ymove, bitmap
#define glBitmap_ARG_EXPAND GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte * bitmap
#define glBitmap_PACKED PACKED_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_const_GLubyte___GENPT__
#define glBitmap_INDEXED INDEXED_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_const_GLubyte___GENPT__
#define glBitmap_FORMAT FORMAT_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_const_GLubyte___GENPT__
#define glBlendColor_INDEX 11
#define glBlendColor_RETURN void
#define glBlendColor_ARG_NAMES red, green, blue, alpha
#define glBlendColor_ARG_EXPAND GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha
#define glBlendColor_PACKED PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glBlendColor_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glBlendColor_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glBlendEquation_INDEX 12
#define glBlendEquation_RETURN void
#define glBlendEquation_ARG_NAMES mode
#define glBlendEquation_ARG_EXPAND GLenum mode
#define glBlendEquation_PACKED PACKED_void_GLenum
#define glBlendEquation_INDEXED INDEXED_void_GLenum
#define glBlendEquation_FORMAT FORMAT_void_GLenum
#define glBlendFunc_INDEX 13
#define glBlendFunc_RETURN void
#define glBlendFunc_ARG_NAMES sfactor, dfactor
#define glBlendFunc_ARG_EXPAND GLenum sfactor, GLenum dfactor
#define glBlendFunc_PACKED PACKED_void_GLenum_GLenum
#define glBlendFunc_INDEXED INDEXED_void_GLenum_GLenum
#define glBlendFunc_FORMAT FORMAT_void_GLenum_GLenum
#define glBlendFuncSeparate_INDEX 14
#define glBlendFuncSeparate_RETURN void
#define glBlendFuncSeparate_ARG_NAMES sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha
#define glBlendFuncSeparate_ARG_EXPAND GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha
#define glBlendFuncSeparate_PACKED PACKED_void_GLenum_GLenum_GLenum_GLenum
#define glBlendFuncSeparate_INDEXED INDEXED_void_GLenum_GLenum_GLenum_GLenum
#define glBlendFuncSeparate_FORMAT FORMAT_void_GLenum_GLenum_GLenum_GLenum
#define glBufferData_INDEX 15
#define glBufferData_RETURN void
#define glBufferData_ARG_NAMES target, size, data, usage
#define glBufferData_ARG_EXPAND GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage
#define glBufferData_PACKED PACKED_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum
#define glBufferData_INDEXED INDEXED_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum
#define glBufferData_FORMAT FORMAT_void_GLenum_GLsizeiptr_const_GLvoid___GENPT___GLenum
#define glBufferSubData_INDEX 16
#define glBufferSubData_RETURN void
#define glBufferSubData_ARG_NAMES target, offset, size, data
#define glBufferSubData_ARG_EXPAND GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data
#define glBufferSubData_PACKED PACKED_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__
#define glBufferSubData_INDEXED INDEXED_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__
#define glBufferSubData_FORMAT FORMAT_void_GLenum_GLintptr_GLsizeiptr_const_GLvoid___GENPT__
#define glCallList_INDEX 17
#define glCallList_RETURN void
#define glCallList_ARG_NAMES list
#define glCallList_ARG_EXPAND GLuint list
#define glCallList_PACKED PACKED_void_GLuint
#define glCallList_INDEXED INDEXED_void_GLuint
#define glCallList_FORMAT FORMAT_void_GLuint
#define glCallLists_INDEX 18
#define glCallLists_RETURN void
#define glCallLists_ARG_NAMES n, type, lists
#define glCallLists_ARG_EXPAND GLsizei n, GLenum type, const GLvoid * lists
#define glCallLists_PACKED PACKED_void_GLsizei_GLenum_const_GLvoid___GENPT__
#define glCallLists_INDEXED INDEXED_void_GLsizei_GLenum_const_GLvoid___GENPT__
#define glCallLists_FORMAT FORMAT_void_GLsizei_GLenum_const_GLvoid___GENPT__
#define glClear_INDEX 19
#define glClear_RETURN void
#define glClear_ARG_NAMES mask
#define glClear_ARG_EXPAND GLbitfield mask
#define glClear_PACKED PACKED_void_GLbitfield
#define glClear_INDEXED INDEXED_void_GLbitfield
#define glClear_FORMAT FORMAT_void_GLbitfield
#define glClearAccum_INDEX 20
#define glClearAccum_RETURN void
#define glClearAccum_ARG_NAMES red, green, blue, alpha
#define glClearAccum_ARG_EXPAND GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha
#define glClearAccum_PACKED PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glClearAccum_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glClearAccum_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glClearColor_INDEX 21
#define glClearColor_RETURN void
#define glClearColor_ARG_NAMES red, green, blue, alpha
#define glClearColor_ARG_EXPAND GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha
#define glClearColor_PACKED PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glClearColor_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glClearColor_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glClearDepth_INDEX 22
#define glClearDepth_RETURN void
#define glClearDepth_ARG_NAMES depth
#define glClearDepth_ARG_EXPAND GLdouble depth
#define glClearDepth_PACKED PACKED_void_GLdouble
#define glClearDepth_INDEXED INDEXED_void_GLdouble
#define glClearDepth_FORMAT FORMAT_void_GLdouble
#define glClearIndex_INDEX 23
#define glClearIndex_RETURN void
#define glClearIndex_ARG_NAMES c
#define glClearIndex_ARG_EXPAND GLfloat c
#define glClearIndex_PACKED PACKED_void_GLfloat
#define glClearIndex_INDEXED INDEXED_void_GLfloat
#define glClearIndex_FORMAT FORMAT_void_GLfloat
#define glClearStencil_INDEX 24
#define glClearStencil_RETURN void
#define glClearStencil_ARG_NAMES s
#define glClearStencil_ARG_EXPAND GLint s
#define glClearStencil_PACKED PACKED_void_GLint
#define glClearStencil_INDEXED INDEXED_void_GLint
#define glClearStencil_FORMAT FORMAT_void_GLint
#define glClientActiveTexture_INDEX 25
#define glClientActiveTexture_RETURN void
#define glClientActiveTexture_ARG_NAMES texture
#define glClientActiveTexture_ARG_EXPAND GLenum texture
#define glClientActiveTexture_PACKED PACKED_void_GLenum
#define glClientActiveTexture_INDEXED INDEXED_void_GLenum
#define glClientActiveTexture_FORMAT FORMAT_void_GLenum
#define glClipPlane_INDEX 26
#define glClipPlane_RETURN void
#define glClipPlane_ARG_NAMES plane, equation
#define glClipPlane_ARG_EXPAND GLenum plane, const GLdouble * equation
#define glClipPlane_PACKED PACKED_void_GLenum_const_GLdouble___GENPT__
#define glClipPlane_INDEXED INDEXED_void_GLenum_const_GLdouble___GENPT__
#define glClipPlane_FORMAT FORMAT_void_GLenum_const_GLdouble___GENPT__
#define glColor3b_INDEX 27
#define glColor3b_RETURN void
#define glColor3b_ARG_NAMES red, green, blue
#define glColor3b_ARG_EXPAND GLbyte red, GLbyte green, GLbyte blue
#define glColor3b_PACKED PACKED_void_GLbyte_GLbyte_GLbyte
#define glColor3b_INDEXED INDEXED_void_GLbyte_GLbyte_GLbyte
#define glColor3b_FORMAT FORMAT_void_GLbyte_GLbyte_GLbyte
#define glColor3bv_INDEX 28
#define glColor3bv_RETURN void
#define glColor3bv_ARG_NAMES v
#define glColor3bv_ARG_EXPAND const GLbyte * v
#define glColor3bv_PACKED PACKED_void_const_GLbyte___GENPT__
#define glColor3bv_INDEXED INDEXED_void_const_GLbyte___GENPT__
#define glColor3bv_FORMAT FORMAT_void_const_GLbyte___GENPT__
#define glColor3d_INDEX 29
#define glColor3d_RETURN void
#define glColor3d_ARG_NAMES red, green, blue
#define glColor3d_ARG_EXPAND GLdouble red, GLdouble green, GLdouble blue
#define glColor3d_PACKED PACKED_void_GLdouble_GLdouble_GLdouble
#define glColor3d_INDEXED INDEXED_void_GLdouble_GLdouble_GLdouble
#define glColor3d_FORMAT FORMAT_void_GLdouble_GLdouble_GLdouble
#define glColor3dv_INDEX 30
#define glColor3dv_RETURN void
#define glColor3dv_ARG_NAMES v
#define glColor3dv_ARG_EXPAND const GLdouble * v
#define glColor3dv_PACKED PACKED_void_const_GLdouble___GENPT__
#define glColor3dv_INDEXED INDEXED_void_const_GLdouble___GENPT__
#define glColor3dv_FORMAT FORMAT_void_const_GLdouble___GENPT__
#define glColor3f_INDEX 31
#define glColor3f_RETURN void
#define glColor3f_ARG_NAMES red, green, blue
#define glColor3f_ARG_EXPAND GLfloat red, GLfloat green, GLfloat blue
#define glColor3f_PACKED PACKED_void_GLfloat_GLfloat_GLfloat
#define glColor3f_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat
#define glColor3f_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat
#define glColor3fv_INDEX 32
#define glColor3fv_RETURN void
#define glColor3fv_ARG_NAMES v
#define glColor3fv_ARG_EXPAND const GLfloat * v
#define glColor3fv_PACKED PACKED_void_const_GLfloat___GENPT__
#define glColor3fv_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glColor3fv_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glColor3i_INDEX 33
#define glColor3i_RETURN void
#define glColor3i_ARG_NAMES red, green, blue
#define glColor3i_ARG_EXPAND GLint red, GLint green, GLint blue
#define glColor3i_PACKED PACKED_void_GLint_GLint_GLint
#define glColor3i_INDEXED INDEXED_void_GLint_GLint_GLint
#define glColor3i_FORMAT FORMAT_void_GLint_GLint_GLint
#define glColor3iv_INDEX 34
#define glColor3iv_RETURN void
#define glColor3iv_ARG_NAMES v
#define glColor3iv_ARG_EXPAND const GLint * v
#define glColor3iv_PACKED PACKED_void_const_GLint___GENPT__
#define glColor3iv_INDEXED INDEXED_void_const_GLint___GENPT__
#define glColor3iv_FORMAT FORMAT_void_const_GLint___GENPT__
#define glColor3s_INDEX 35
#define glColor3s_RETURN void
#define glColor3s_ARG_NAMES red, green, blue
#define glColor3s_ARG_EXPAND GLshort red, GLshort green, GLshort blue
#define glColor3s_PACKED PACKED_void_GLshort_GLshort_GLshort
#define glColor3s_INDEXED INDEXED_void_GLshort_GLshort_GLshort
#define glColor3s_FORMAT FORMAT_void_GLshort_GLshort_GLshort
#define glColor3sv_INDEX 36
#define glColor3sv_RETURN void
#define glColor3sv_ARG_NAMES v
#define glColor3sv_ARG_EXPAND const GLshort * v
#define glColor3sv_PACKED PACKED_void_const_GLshort___GENPT__
#define glColor3sv_INDEXED INDEXED_void_const_GLshort___GENPT__
#define glColor3sv_FORMAT FORMAT_void_const_GLshort___GENPT__
#define glColor3ub_INDEX 37
#define glColor3ub_RETURN void
#define glColor3ub_ARG_NAMES red, green, blue
#define glColor3ub_ARG_EXPAND GLubyte red, GLubyte green, GLubyte blue
#define glColor3ub_PACKED PACKED_void_GLubyte_GLubyte_GLubyte
#define glColor3ub_INDEXED INDEXED_void_GLubyte_GLubyte_GLubyte
#define glColor3ub_FORMAT FORMAT_void_GLubyte_GLubyte_GLubyte
#define glColor3ubv_INDEX 38
#define glColor3ubv_RETURN void
#define glColor3ubv_ARG_NAMES v
#define glColor3ubv_ARG_EXPAND const GLubyte * v
#define glColor3ubv_PACKED PACKED_void_const_GLubyte___GENPT__
#define glColor3ubv_INDEXED INDEXED_void_const_GLubyte___GENPT__
#define glColor3ubv_FORMAT FORMAT_void_const_GLubyte___GENPT__
#define glColor3ui_INDEX 39
#define glColor3ui_RETURN void
#define glColor3ui_ARG_NAMES red, green, blue
#define glColor3ui_ARG_EXPAND GLuint red, GLuint green, GLuint blue
#define glColor3ui_PACKED PACKED_void_GLuint_GLuint_GLuint
#define glColor3ui_INDEXED INDEXED_void_GLuint_GLuint_GLuint
#define glColor3ui_FORMAT FORMAT_void_GLuint_GLuint_GLuint
#define glColor3uiv_INDEX 40
#define glColor3uiv_RETURN void
#define glColor3uiv_ARG_NAMES v
#define glColor3uiv_ARG_EXPAND const GLuint * v
#define glColor3uiv_PACKED PACKED_void_const_GLuint___GENPT__
#define glColor3uiv_INDEXED INDEXED_void_const_GLuint___GENPT__
#define glColor3uiv_FORMAT FORMAT_void_const_GLuint___GENPT__
#define glColor3us_INDEX 41
#define glColor3us_RETURN void
#define glColor3us_ARG_NAMES red, green, blue
#define glColor3us_ARG_EXPAND GLushort red, GLushort green, GLushort blue
#define glColor3us_PACKED PACKED_void_GLushort_GLushort_GLushort
#define glColor3us_INDEXED INDEXED_void_GLushort_GLushort_GLushort
#define glColor3us_FORMAT FORMAT_void_GLushort_GLushort_GLushort
#define glColor3usv_INDEX 42
#define glColor3usv_RETURN void
#define glColor3usv_ARG_NAMES v
#define glColor3usv_ARG_EXPAND const GLushort * v
#define glColor3usv_PACKED PACKED_void_const_GLushort___GENPT__
#define glColor3usv_INDEXED INDEXED_void_const_GLushort___GENPT__
#define glColor3usv_FORMAT FORMAT_void_const_GLushort___GENPT__
#define glColor4b_INDEX 43
#define glColor4b_RETURN void
#define glColor4b_ARG_NAMES red, green, blue, alpha
#define glColor4b_ARG_EXPAND GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha
#define glColor4b_PACKED PACKED_void_GLbyte_GLbyte_GLbyte_GLbyte
#define glColor4b_INDEXED INDEXED_void_GLbyte_GLbyte_GLbyte_GLbyte
#define glColor4b_FORMAT FORMAT_void_GLbyte_GLbyte_GLbyte_GLbyte
#define glColor4bv_INDEX 44
#define glColor4bv_RETURN void
#define glColor4bv_ARG_NAMES v
#define glColor4bv_ARG_EXPAND const GLbyte * v
#define glColor4bv_PACKED PACKED_void_const_GLbyte___GENPT__
#define glColor4bv_INDEXED INDEXED_void_const_GLbyte___GENPT__
#define glColor4bv_FORMAT FORMAT_void_const_GLbyte___GENPT__
#define glColor4d_INDEX 45
#define glColor4d_RETURN void
#define glColor4d_ARG_NAMES red, green, blue, alpha
#define glColor4d_ARG_EXPAND GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha
#define glColor4d_PACKED PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble
#define glColor4d_INDEXED INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble
#define glColor4d_FORMAT FORMAT_void_GLdouble_GLdouble_GLdouble_GLdouble
#define glColor4dv_INDEX 46
#define glColor4dv_RETURN void
#define glColor4dv_ARG_NAMES v
#define glColor4dv_ARG_EXPAND const GLdouble * v
#define glColor4dv_PACKED PACKED_void_const_GLdouble___GENPT__
#define glColor4dv_INDEXED INDEXED_void_const_GLdouble___GENPT__
#define glColor4dv_FORMAT FORMAT_void_const_GLdouble___GENPT__
#define glColor4f_INDEX 47
#define glColor4f_RETURN void
#define glColor4f_ARG_NAMES red, green, blue, alpha
#define glColor4f_ARG_EXPAND GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha
#define glColor4f_PACKED PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glColor4f_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glColor4f_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glColor4fv_INDEX 48
#define glColor4fv_RETURN void
#define glColor4fv_ARG_NAMES v
#define glColor4fv_ARG_EXPAND const GLfloat * v
#define glColor4fv_PACKED PACKED_void_const_GLfloat___GENPT__
#define glColor4fv_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glColor4fv_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glColor4i_INDEX 49
#define glColor4i_RETURN void
#define glColor4i_ARG_NAMES red, green, blue, alpha
#define glColor4i_ARG_EXPAND GLint red, GLint green, GLint blue, GLint alpha
#define glColor4i_PACKED PACKED_void_GLint_GLint_GLint_GLint
#define glColor4i_INDEXED INDEXED_void_GLint_GLint_GLint_GLint
#define glColor4i_FORMAT FORMAT_void_GLint_GLint_GLint_GLint
#define glColor4iv_INDEX 50
#define glColor4iv_RETURN void
#define glColor4iv_ARG_NAMES v
#define glColor4iv_ARG_EXPAND const GLint * v
#define glColor4iv_PACKED PACKED_void_const_GLint___GENPT__
#define glColor4iv_INDEXED INDEXED_void_const_GLint___GENPT__
#define glColor4iv_FORMAT FORMAT_void_const_GLint___GENPT__
#define glColor4s_INDEX 51
#define glColor4s_RETURN void
#define glColor4s_ARG_NAMES red, green, blue, alpha
#define glColor4s_ARG_EXPAND GLshort red, GLshort green, GLshort blue, GLshort alpha
#define glColor4s_PACKED PACKED_void_GLshort_GLshort_GLshort_GLshort
#define glColor4s_INDEXED INDEXED_void_GLshort_GLshort_GLshort_GLshort
#define glColor4s_FORMAT FORMAT_void_GLshort_GLshort_GLshort_GLshort
#define glColor4sv_INDEX 52
#define glColor4sv_RETURN void
#define glColor4sv_ARG_NAMES v
#define glColor4sv_ARG_EXPAND const GLshort * v
#define glColor4sv_PACKED PACKED_void_const_GLshort___GENPT__
#define glColor4sv_INDEXED INDEXED_void_const_GLshort___GENPT__
#define glColor4sv_FORMAT FORMAT_void_const_GLshort___GENPT__
#define glColor4ub_INDEX 53
#define glColor4ub_RETURN void
#define glColor4ub_ARG_NAMES red, green, blue, alpha
#define glColor4ub_ARG_EXPAND GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha
#define glColor4ub_PACKED PACKED_void_GLubyte_GLubyte_GLubyte_GLubyte
#define glColor4ub_INDEXED INDEXED_void_GLubyte_GLubyte_GLubyte_GLubyte
#define glColor4ub_FORMAT FORMAT_void_GLubyte_GLubyte_GLubyte_GLubyte
#define glColor4ubv_INDEX 54
#define glColor4ubv_RETURN void
#define glColor4ubv_ARG_NAMES v
#define glColor4ubv_ARG_EXPAND const GLubyte * v
#define glColor4ubv_PACKED PACKED_void_const_GLubyte___GENPT__
#define glColor4ubv_INDEXED INDEXED_void_const_GLubyte___GENPT__
#define glColor4ubv_FORMAT FORMAT_void_const_GLubyte___GENPT__
#define glColor4ui_INDEX 55
#define glColor4ui_RETURN void
#define glColor4ui_ARG_NAMES red, green, blue, alpha
#define glColor4ui_ARG_EXPAND GLuint red, GLuint green, GLuint blue, GLuint alpha
#define glColor4ui_PACKED PACKED_void_GLuint_GLuint_GLuint_GLuint
#define glColor4ui_INDEXED INDEXED_void_GLuint_GLuint_GLuint_GLuint
#define glColor4ui_FORMAT FORMAT_void_GLuint_GLuint_GLuint_GLuint
#define glColor4uiv_INDEX 56
#define glColor4uiv_RETURN void
#define glColor4uiv_ARG_NAMES v
#define glColor4uiv_ARG_EXPAND const GLuint * v
#define glColor4uiv_PACKED PACKED_void_const_GLuint___GENPT__
#define glColor4uiv_INDEXED INDEXED_void_const_GLuint___GENPT__
#define glColor4uiv_FORMAT FORMAT_void_const_GLuint___GENPT__
#define glColor4us_INDEX 57
#define glColor4us_RETURN void
#define glColor4us_ARG_NAMES red, green, blue, alpha
#define glColor4us_ARG_EXPAND GLushort red, GLushort green, GLushort blue, GLushort alpha
#define glColor4us_PACKED PACKED_void_GLushort_GLushort_GLushort_GLushort
#define glColor4us_INDEXED INDEXED_void_GLushort_GLushort_GLushort_GLushort
#define glColor4us_FORMAT FORMAT_void_GLushort_GLushort_GLushort_GLushort
#define glColor4usv_INDEX 58
#define glColor4usv_RETURN void
#define glColor4usv_ARG_NAMES v
#define glColor4usv_ARG_EXPAND const GLushort * v
#define glColor4usv_PACKED PACKED_void_const_GLushort___GENPT__
#define glColor4usv_INDEXED INDEXED_void_const_GLushort___GENPT__
#define glColor4usv_FORMAT FORMAT_void_const_GLushort___GENPT__
#define glColorMask_INDEX 59
#define glColorMask_RETURN void
#define glColorMask_ARG_NAMES red, green, blue, alpha
#define glColorMask_ARG_EXPAND GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha
#define glColorMask_PACKED PACKED_void_GLboolean_GLboolean_GLboolean_GLboolean
#define glColorMask_INDEXED INDEXED_void_GLboolean_GLboolean_GLboolean_GLboolean
#define glColorMask_FORMAT FORMAT_void_GLboolean_GLboolean_GLboolean_GLboolean
#define glColorMaterial_INDEX 60
#define glColorMaterial_RETURN void
#define glColorMaterial_ARG_NAMES face, mode
#define glColorMaterial_ARG_EXPAND GLenum face, GLenum mode
#define glColorMaterial_PACKED PACKED_void_GLenum_GLenum
#define glColorMaterial_INDEXED INDEXED_void_GLenum_GLenum
#define glColorMaterial_FORMAT FORMAT_void_GLenum_GLenum
#define glColorPointer_INDEX 61
#define glColorPointer_RETURN void
#define glColorPointer_ARG_NAMES size, type, stride, pointer
#define glColorPointer_ARG_EXPAND GLint size, GLenum type, GLsizei stride, const GLvoid * pointer
#define glColorPointer_PACKED PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__
#define glColorPointer_INDEXED INDEXED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__
#define glColorPointer_FORMAT FORMAT_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__
#define glColorSubTable_INDEX 62
#define glColorSubTable_RETURN void
#define glColorSubTable_ARG_NAMES target, start, count, format, type, data
#define glColorSubTable_ARG_EXPAND GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid * data
#define glColorSubTable_PACKED PACKED_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glColorSubTable_INDEXED INDEXED_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glColorSubTable_FORMAT FORMAT_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glColorTable_INDEX 63
#define glColorTable_RETURN void
#define glColorTable_ARG_NAMES target, internalformat, width, format, type, table
#define glColorTable_ARG_EXPAND GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * table
#define glColorTable_PACKED PACKED_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glColorTable_INDEXED INDEXED_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glColorTable_FORMAT FORMAT_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glColorTableParameterfv_INDEX 64
#define glColorTableParameterfv_RETURN void
#define glColorTableParameterfv_ARG_NAMES target, pname, params
#define glColorTableParameterfv_ARG_EXPAND GLenum target, GLenum pname, const GLfloat * params
#define glColorTableParameterfv_PACKED PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glColorTableParameterfv_INDEXED INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glColorTableParameterfv_FORMAT FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glColorTableParameteriv_INDEX 65
#define glColorTableParameteriv_RETURN void
#define glColorTableParameteriv_ARG_NAMES target, pname, params
#define glColorTableParameteriv_ARG_EXPAND GLenum target, GLenum pname, const GLint * params
#define glColorTableParameteriv_PACKED PACKED_void_GLenum_GLenum_const_GLint___GENPT__
#define glColorTableParameteriv_INDEXED INDEXED_void_GLenum_GLenum_const_GLint___GENPT__
#define glColorTableParameteriv_FORMAT FORMAT_void_GLenum_GLenum_const_GLint___GENPT__
#define glCompressedTexImage1D_INDEX 66
#define glCompressedTexImage1D_RETURN void
#define glCompressedTexImage1D_ARG_NAMES target, level, internalformat, width, border, imageSize, data
#define glCompressedTexImage1D_ARG_EXPAND GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid * data
#define glCompressedTexImage1D_PACKED PACKED_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__
#define glCompressedTexImage1D_INDEXED INDEXED_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__
#define glCompressedTexImage1D_FORMAT FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__
#define glCompressedTexImage2D_INDEX 67
#define glCompressedTexImage2D_RETURN void
#define glCompressedTexImage2D_ARG_NAMES target, level, internalformat, width, height, border, imageSize, data
#define glCompressedTexImage2D_ARG_EXPAND GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data
#define glCompressedTexImage2D_PACKED PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__
#define glCompressedTexImage2D_INDEXED INDEXED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__
#define glCompressedTexImage2D_FORMAT FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__
#define glCompressedTexImage3D_INDEX 68
#define glCompressedTexImage3D_RETURN void
#define glCompressedTexImage3D_ARG_NAMES target, level, internalformat, width, height, depth, border, imageSize, data
#define glCompressedTexImage3D_ARG_EXPAND GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid * data
#define glCompressedTexImage3D_PACKED PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__
#define glCompressedTexImage3D_INDEXED INDEXED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__
#define glCompressedTexImage3D_FORMAT FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__
#define glCompressedTexSubImage1D_INDEX 69
#define glCompressedTexSubImage1D_RETURN void
#define glCompressedTexSubImage1D_ARG_NAMES target, level, xoffset, width, format, imageSize, data
#define glCompressedTexSubImage1D_ARG_EXPAND GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid * data
#define glCompressedTexSubImage1D_PACKED PACKED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__
#define glCompressedTexSubImage1D_INDEXED INDEXED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__
#define glCompressedTexSubImage1D_FORMAT FORMAT_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__
#define glCompressedTexSubImage2D_INDEX 70
#define glCompressedTexSubImage2D_RETURN void
#define glCompressedTexSubImage2D_ARG_NAMES target, level, xoffset, yoffset, width, height, format, imageSize, data
#define glCompressedTexSubImage2D_ARG_EXPAND GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data
#define glCompressedTexSubImage2D_PACKED PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__
#define glCompressedTexSubImage2D_INDEXED INDEXED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__
#define glCompressedTexSubImage2D_FORMAT FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__
#define glCompressedTexSubImage3D_INDEX 71
#define glCompressedTexSubImage3D_RETURN void
#define glCompressedTexSubImage3D_ARG_NAMES target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data
#define glCompressedTexSubImage3D_ARG_EXPAND GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid * data
#define glCompressedTexSubImage3D_PACKED PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__
#define glCompressedTexSubImage3D_INDEXED INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__
#define glCompressedTexSubImage3D_FORMAT FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__
#define glConvolutionFilter1D_INDEX 72
#define glConvolutionFilter1D_RETURN void
#define glConvolutionFilter1D_ARG_NAMES target, internalformat, width, format, type, image
#define glConvolutionFilter1D_ARG_EXPAND GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * image
#define glConvolutionFilter1D_PACKED PACKED_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glConvolutionFilter1D_INDEXED INDEXED_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glConvolutionFilter1D_FORMAT FORMAT_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glConvolutionFilter2D_INDEX 73
#define glConvolutionFilter2D_RETURN void
#define glConvolutionFilter2D_ARG_NAMES target, internalformat, width, height, format, type, image
#define glConvolutionFilter2D_ARG_EXPAND GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * image
#define glConvolutionFilter2D_PACKED PACKED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glConvolutionFilter2D_INDEXED INDEXED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glConvolutionFilter2D_FORMAT FORMAT_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glConvolutionParameterf_INDEX 74
#define glConvolutionParameterf_RETURN void
#define glConvolutionParameterf_ARG_NAMES target, pname, params
#define glConvolutionParameterf_ARG_EXPAND GLenum target, GLenum pname, GLfloat params
#define glConvolutionParameterf_PACKED PACKED_void_GLenum_GLenum_GLfloat
#define glConvolutionParameterf_INDEXED INDEXED_void_GLenum_GLenum_GLfloat
#define glConvolutionParameterf_FORMAT FORMAT_void_GLenum_GLenum_GLfloat
#define glConvolutionParameterfv_INDEX 75
#define glConvolutionParameterfv_RETURN void
#define glConvolutionParameterfv_ARG_NAMES target, pname, params
#define glConvolutionParameterfv_ARG_EXPAND GLenum target, GLenum pname, const GLfloat * params
#define glConvolutionParameterfv_PACKED PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glConvolutionParameterfv_INDEXED INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glConvolutionParameterfv_FORMAT FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glConvolutionParameteri_INDEX 76
#define glConvolutionParameteri_RETURN void
#define glConvolutionParameteri_ARG_NAMES target, pname, params
#define glConvolutionParameteri_ARG_EXPAND GLenum target, GLenum pname, GLint params
#define glConvolutionParameteri_PACKED PACKED_void_GLenum_GLenum_GLint
#define glConvolutionParameteri_INDEXED INDEXED_void_GLenum_GLenum_GLint
#define glConvolutionParameteri_FORMAT FORMAT_void_GLenum_GLenum_GLint
#define glConvolutionParameteriv_INDEX 77
#define glConvolutionParameteriv_RETURN void
#define glConvolutionParameteriv_ARG_NAMES target, pname, params
#define glConvolutionParameteriv_ARG_EXPAND GLenum target, GLenum pname, const GLint * params
#define glConvolutionParameteriv_PACKED PACKED_void_GLenum_GLenum_const_GLint___GENPT__
#define glConvolutionParameteriv_INDEXED INDEXED_void_GLenum_GLenum_const_GLint___GENPT__
#define glConvolutionParameteriv_FORMAT FORMAT_void_GLenum_GLenum_const_GLint___GENPT__
#define glCopyColorSubTable_INDEX 78
#define glCopyColorSubTable_RETURN void
#define glCopyColorSubTable_ARG_NAMES target, start, x, y, width
#define glCopyColorSubTable_ARG_EXPAND GLenum target, GLsizei start, GLint x, GLint y, GLsizei width
#define glCopyColorSubTable_PACKED PACKED_void_GLenum_GLsizei_GLint_GLint_GLsizei
#define glCopyColorSubTable_INDEXED INDEXED_void_GLenum_GLsizei_GLint_GLint_GLsizei
#define glCopyColorSubTable_FORMAT FORMAT_void_GLenum_GLsizei_GLint_GLint_GLsizei
#define glCopyColorTable_INDEX 79
#define glCopyColorTable_RETURN void
#define glCopyColorTable_ARG_NAMES target, internalformat, x, y, width
#define glCopyColorTable_ARG_EXPAND GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width
#define glCopyColorTable_PACKED PACKED_void_GLenum_GLenum_GLint_GLint_GLsizei
#define glCopyColorTable_INDEXED INDEXED_void_GLenum_GLenum_GLint_GLint_GLsizei
#define glCopyColorTable_FORMAT FORMAT_void_GLenum_GLenum_GLint_GLint_GLsizei
#define glCopyConvolutionFilter1D_INDEX 80
#define glCopyConvolutionFilter1D_RETURN void
#define glCopyConvolutionFilter1D_ARG_NAMES target, internalformat, x, y, width
#define glCopyConvolutionFilter1D_ARG_EXPAND GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width
#define glCopyConvolutionFilter1D_PACKED PACKED_void_GLenum_GLenum_GLint_GLint_GLsizei
#define glCopyConvolutionFilter1D_INDEXED INDEXED_void_GLenum_GLenum_GLint_GLint_GLsizei
#define glCopyConvolutionFilter1D_FORMAT FORMAT_void_GLenum_GLenum_GLint_GLint_GLsizei
#define glCopyConvolutionFilter2D_INDEX 81
#define glCopyConvolutionFilter2D_RETURN void
#define glCopyConvolutionFilter2D_ARG_NAMES target, internalformat, x, y, width, height
#define glCopyConvolutionFilter2D_ARG_EXPAND GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height
#define glCopyConvolutionFilter2D_PACKED PACKED_void_GLenum_GLenum_GLint_GLint_GLsizei_GLsizei
#define glCopyConvolutionFilter2D_INDEXED INDEXED_void_GLenum_GLenum_GLint_GLint_GLsizei_GLsizei
#define glCopyConvolutionFilter2D_FORMAT FORMAT_void_GLenum_GLenum_GLint_GLint_GLsizei_GLsizei
#define glCopyPixels_INDEX 82
#define glCopyPixels_RETURN void
#define glCopyPixels_ARG_NAMES x, y, width, height, type
#define glCopyPixels_ARG_EXPAND GLint x, GLint y, GLsizei width, GLsizei height, GLenum type
#define glCopyPixels_PACKED PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum
#define glCopyPixels_INDEXED INDEXED_void_GLint_GLint_GLsizei_GLsizei_GLenum
#define glCopyPixels_FORMAT FORMAT_void_GLint_GLint_GLsizei_GLsizei_GLenum
#define glCopyTexImage1D_INDEX 83
#define glCopyTexImage1D_RETURN void
#define glCopyTexImage1D_ARG_NAMES target, level, internalformat, x, y, width, border
#define glCopyTexImage1D_ARG_EXPAND GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border
#define glCopyTexImage1D_PACKED PACKED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint
#define glCopyTexImage1D_INDEXED INDEXED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint
#define glCopyTexImage1D_FORMAT FORMAT_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint
#define glCopyTexImage2D_INDEX 84
#define glCopyTexImage2D_RETURN void
#define glCopyTexImage2D_ARG_NAMES target, level, internalformat, x, y, width, height, border
#define glCopyTexImage2D_ARG_EXPAND GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border
#define glCopyTexImage2D_PACKED PACKED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint
#define glCopyTexImage2D_INDEXED INDEXED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint
#define glCopyTexImage2D_FORMAT FORMAT_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint
#define glCopyTexSubImage1D_INDEX 85
#define glCopyTexSubImage1D_RETURN void
#define glCopyTexSubImage1D_ARG_NAMES target, level, xoffset, x, y, width
#define glCopyTexSubImage1D_ARG_EXPAND GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width
#define glCopyTexSubImage1D_PACKED PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei
#define glCopyTexSubImage1D_INDEXED INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei
#define glCopyTexSubImage1D_FORMAT FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLsizei
#define glCopyTexSubImage2D_INDEX 86
#define glCopyTexSubImage2D_RETURN void
#define glCopyTexSubImage2D_ARG_NAMES target, level, xoffset, yoffset, x, y, width, height
#define glCopyTexSubImage2D_ARG_EXPAND GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height
#define glCopyTexSubImage2D_PACKED PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei
#define glCopyTexSubImage2D_INDEXED INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei
#define glCopyTexSubImage2D_FORMAT FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei
#define glCopyTexSubImage3D_INDEX 87
#define glCopyTexSubImage3D_RETURN void
#define glCopyTexSubImage3D_ARG_NAMES target, level, xoffset, yoffset, zoffset, x, y, width, height
#define glCopyTexSubImage3D_ARG_EXPAND GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height
#define glCopyTexSubImage3D_PACKED PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei
#define glCopyTexSubImage3D_INDEXED INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei
#define glCopyTexSubImage3D_FORMAT FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei
#define glCullFace_INDEX 88
#define glCullFace_RETURN void
#define glCullFace_ARG_NAMES mode
#define glCullFace_ARG_EXPAND GLenum mode
#define glCullFace_PACKED PACKED_void_GLenum
#define glCullFace_INDEXED INDEXED_void_GLenum
#define glCullFace_FORMAT FORMAT_void_GLenum
#define glDeleteBuffers_INDEX 89
#define glDeleteBuffers_RETURN void
#define glDeleteBuffers_ARG_NAMES n, buffers
#define glDeleteBuffers_ARG_EXPAND GLsizei n, const GLuint * buffers
#define glDeleteBuffers_PACKED PACKED_void_GLsizei_const_GLuint___GENPT__
#define glDeleteBuffers_INDEXED INDEXED_void_GLsizei_const_GLuint___GENPT__
#define glDeleteBuffers_FORMAT FORMAT_void_GLsizei_const_GLuint___GENPT__
#define glDeleteLists_INDEX 90
#define glDeleteLists_RETURN void
#define glDeleteLists_ARG_NAMES list, range
#define glDeleteLists_ARG_EXPAND GLuint list, GLsizei range
#define glDeleteLists_PACKED PACKED_void_GLuint_GLsizei
#define glDeleteLists_INDEXED INDEXED_void_GLuint_GLsizei
#define glDeleteLists_FORMAT FORMAT_void_GLuint_GLsizei
#define glDeleteQueries_INDEX 91
#define glDeleteQueries_RETURN void
#define glDeleteQueries_ARG_NAMES n, ids
#define glDeleteQueries_ARG_EXPAND GLsizei n, const GLuint * ids
#define glDeleteQueries_PACKED PACKED_void_GLsizei_const_GLuint___GENPT__
#define glDeleteQueries_INDEXED INDEXED_void_GLsizei_const_GLuint___GENPT__
#define glDeleteQueries_FORMAT FORMAT_void_GLsizei_const_GLuint___GENPT__
#define glDeleteTextures_INDEX 92
#define glDeleteTextures_RETURN void
#define glDeleteTextures_ARG_NAMES n, textures
#define glDeleteTextures_ARG_EXPAND GLsizei n, const GLuint * textures
#define glDeleteTextures_PACKED PACKED_void_GLsizei_const_GLuint___GENPT__
#define glDeleteTextures_INDEXED INDEXED_void_GLsizei_const_GLuint___GENPT__
#define glDeleteTextures_FORMAT FORMAT_void_GLsizei_const_GLuint___GENPT__
#define glDepthFunc_INDEX 93
#define glDepthFunc_RETURN void
#define glDepthFunc_ARG_NAMES func
#define glDepthFunc_ARG_EXPAND GLenum func
#define glDepthFunc_PACKED PACKED_void_GLenum
#define glDepthFunc_INDEXED INDEXED_void_GLenum
#define glDepthFunc_FORMAT FORMAT_void_GLenum
#define glDepthMask_INDEX 94
#define glDepthMask_RETURN void
#define glDepthMask_ARG_NAMES flag
#define glDepthMask_ARG_EXPAND GLboolean flag
#define glDepthMask_PACKED PACKED_void_GLboolean
#define glDepthMask_INDEXED INDEXED_void_GLboolean
#define glDepthMask_FORMAT FORMAT_void_GLboolean
#define glDepthRange_INDEX 95
#define glDepthRange_RETURN void
#define glDepthRange_ARG_NAMES near, far
#define glDepthRange_ARG_EXPAND GLdouble near, GLdouble far
#define glDepthRange_PACKED PACKED_void_GLdouble_GLdouble
#define glDepthRange_INDEXED INDEXED_void_GLdouble_GLdouble
#define glDepthRange_FORMAT FORMAT_void_GLdouble_GLdouble
#define glDisable_INDEX 96
#define glDisable_RETURN void
#define glDisable_ARG_NAMES cap
#define glDisable_ARG_EXPAND GLenum cap
#define glDisable_PACKED PACKED_void_GLenum
#define glDisable_INDEXED INDEXED_void_GLenum
#define glDisable_FORMAT FORMAT_void_GLenum
#define glDisableClientState_INDEX 97
#define glDisableClientState_RETURN void
#define glDisableClientState_ARG_NAMES array
#define glDisableClientState_ARG_EXPAND GLenum array
#define glDisableClientState_PACKED PACKED_void_GLenum
#define glDisableClientState_INDEXED INDEXED_void_GLenum
#define glDisableClientState_FORMAT FORMAT_void_GLenum
#define glDrawArrays_INDEX 98
#define glDrawArrays_RETURN void
#define glDrawArrays_ARG_NAMES mode, first, count
#define glDrawArrays_ARG_EXPAND GLenum mode, GLint first, GLsizei count
#define glDrawArrays_PACKED PACKED_void_GLenum_GLint_GLsizei
#define glDrawArrays_INDEXED INDEXED_void_GLenum_GLint_GLsizei
#define glDrawArrays_FORMAT FORMAT_void_GLenum_GLint_GLsizei
#define glDrawBuffer_INDEX 99
#define glDrawBuffer_RETURN void
#define glDrawBuffer_ARG_NAMES mode
#define glDrawBuffer_ARG_EXPAND GLenum mode
#define glDrawBuffer_PACKED PACKED_void_GLenum
#define glDrawBuffer_INDEXED INDEXED_void_GLenum
#define glDrawBuffer_FORMAT FORMAT_void_GLenum
#define glDrawElements_INDEX 100
#define glDrawElements_RETURN void
#define glDrawElements_ARG_NAMES mode, count, type, indices
#define glDrawElements_ARG_EXPAND GLenum mode, GLsizei count, GLenum type, const GLvoid * indices
#define glDrawElements_PACKED PACKED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__
#define glDrawElements_INDEXED INDEXED_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__
#define glDrawElements_FORMAT FORMAT_void_GLenum_GLsizei_GLenum_const_GLvoid___GENPT__
#define glDrawPixels_INDEX 101
#define glDrawPixels_RETURN void
#define glDrawPixels_ARG_NAMES width, height, format, type, pixels
#define glDrawPixels_ARG_EXPAND GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels
#define glDrawPixels_PACKED PACKED_void_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glDrawPixels_INDEXED INDEXED_void_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glDrawPixels_FORMAT FORMAT_void_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glDrawRangeElements_INDEX 102
#define glDrawRangeElements_RETURN void
#define glDrawRangeElements_ARG_NAMES mode, start, end, count, type, indices
#define glDrawRangeElements_ARG_EXPAND GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid * indices
#define glDrawRangeElements_PACKED PACKED_void_GLenum_GLuint_GLuint_GLsizei_GLenum_const_GLvoid___GENPT__
#define glDrawRangeElements_INDEXED INDEXED_void_GLenum_GLuint_GLuint_GLsizei_GLenum_const_GLvoid___GENPT__
#define glDrawRangeElements_FORMAT FORMAT_void_GLenum_GLuint_GLuint_GLsizei_GLenum_const_GLvoid___GENPT__
#define glEdgeFlag_INDEX 103
#define glEdgeFlag_RETURN void
#define glEdgeFlag_ARG_NAMES flag
#define glEdgeFlag_ARG_EXPAND GLboolean flag
#define glEdgeFlag_PACKED PACKED_void_GLboolean
#define glEdgeFlag_INDEXED INDEXED_void_GLboolean
#define glEdgeFlag_FORMAT FORMAT_void_GLboolean
#define glEdgeFlagPointer_INDEX 104
#define glEdgeFlagPointer_RETURN void
#define glEdgeFlagPointer_ARG_NAMES stride, pointer
#define glEdgeFlagPointer_ARG_EXPAND GLsizei stride, const GLvoid * pointer
#define glEdgeFlagPointer_PACKED PACKED_void_GLsizei_const_GLvoid___GENPT__
#define glEdgeFlagPointer_INDEXED INDEXED_void_GLsizei_const_GLvoid___GENPT__
#define glEdgeFlagPointer_FORMAT FORMAT_void_GLsizei_const_GLvoid___GENPT__
#define glEdgeFlagv_INDEX 105
#define glEdgeFlagv_RETURN void
#define glEdgeFlagv_ARG_NAMES flag
#define glEdgeFlagv_ARG_EXPAND const GLboolean * flag
#define glEdgeFlagv_PACKED PACKED_void_const_GLboolean___GENPT__
#define glEdgeFlagv_INDEXED INDEXED_void_const_GLboolean___GENPT__
#define glEdgeFlagv_FORMAT FORMAT_void_const_GLboolean___GENPT__
#define glEnable_INDEX 106
#define glEnable_RETURN void
#define glEnable_ARG_NAMES cap
#define glEnable_ARG_EXPAND GLenum cap
#define glEnable_PACKED PACKED_void_GLenum
#define glEnable_INDEXED INDEXED_void_GLenum
#define glEnable_FORMAT FORMAT_void_GLenum
#define glEnableClientState_INDEX 107
#define glEnableClientState_RETURN void
#define glEnableClientState_ARG_NAMES array
#define glEnableClientState_ARG_EXPAND GLenum array
#define glEnableClientState_PACKED PACKED_void_GLenum
#define glEnableClientState_INDEXED INDEXED_void_GLenum
#define glEnableClientState_FORMAT FORMAT_void_GLenum
#define glEnd_INDEX 108
#define glEnd_RETURN void
#define glEnd_ARG_NAMES 
#define glEnd_ARG_EXPAND 
#define glEnd_PACKED PACKED_void
#define glEnd_INDEXED INDEXED_void
#define glEnd_FORMAT FORMAT_void
#define glEndList_INDEX 109
#define glEndList_RETURN void
#define glEndList_ARG_NAMES 
#define glEndList_ARG_EXPAND 
#define glEndList_PACKED PACKED_void
#define glEndList_INDEXED INDEXED_void
#define glEndList_FORMAT FORMAT_void
#define glEndQuery_INDEX 110
#define glEndQuery_RETURN void
#define glEndQuery_ARG_NAMES target
#define glEndQuery_ARG_EXPAND GLenum target
#define glEndQuery_PACKED PACKED_void_GLenum
#define glEndQuery_INDEXED INDEXED_void_GLenum
#define glEndQuery_FORMAT FORMAT_void_GLenum
#define glEvalCoord1d_INDEX 111
#define glEvalCoord1d_RETURN void
#define glEvalCoord1d_ARG_NAMES u
#define glEvalCoord1d_ARG_EXPAND GLdouble u
#define glEvalCoord1d_PACKED PACKED_void_GLdouble
#define glEvalCoord1d_INDEXED INDEXED_void_GLdouble
#define glEvalCoord1d_FORMAT FORMAT_void_GLdouble
#define glEvalCoord1dv_INDEX 112
#define glEvalCoord1dv_RETURN void
#define glEvalCoord1dv_ARG_NAMES u
#define glEvalCoord1dv_ARG_EXPAND const GLdouble * u
#define glEvalCoord1dv_PACKED PACKED_void_const_GLdouble___GENPT__
#define glEvalCoord1dv_INDEXED INDEXED_void_const_GLdouble___GENPT__
#define glEvalCoord1dv_FORMAT FORMAT_void_const_GLdouble___GENPT__
#define glEvalCoord1f_INDEX 113
#define glEvalCoord1f_RETURN void
#define glEvalCoord1f_ARG_NAMES u
#define glEvalCoord1f_ARG_EXPAND GLfloat u
#define glEvalCoord1f_PACKED PACKED_void_GLfloat
#define glEvalCoord1f_INDEXED INDEXED_void_GLfloat
#define glEvalCoord1f_FORMAT FORMAT_void_GLfloat
#define glEvalCoord1fv_INDEX 114
#define glEvalCoord1fv_RETURN void
#define glEvalCoord1fv_ARG_NAMES u
#define glEvalCoord1fv_ARG_EXPAND const GLfloat * u
#define glEvalCoord1fv_PACKED PACKED_void_const_GLfloat___GENPT__
#define glEvalCoord1fv_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glEvalCoord1fv_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glEvalCoord2d_INDEX 115
#define glEvalCoord2d_RETURN void
#define glEvalCoord2d_ARG_NAMES u, v
#define glEvalCoord2d_ARG_EXPAND GLdouble u, GLdouble v
#define glEvalCoord2d_PACKED PACKED_void_GLdouble_GLdouble
#define glEvalCoord2d_INDEXED INDEXED_void_GLdouble_GLdouble
#define glEvalCoord2d_FORMAT FORMAT_void_GLdouble_GLdouble
#define glEvalCoord2dv_INDEX 116
#define glEvalCoord2dv_RETURN void
#define glEvalCoord2dv_ARG_NAMES u
#define glEvalCoord2dv_ARG_EXPAND const GLdouble * u
#define glEvalCoord2dv_PACKED PACKED_void_const_GLdouble___GENPT__
#define glEvalCoord2dv_INDEXED INDEXED_void_const_GLdouble___GENPT__
#define glEvalCoord2dv_FORMAT FORMAT_void_const_GLdouble___GENPT__
#define glEvalCoord2f_INDEX 117
#define glEvalCoord2f_RETURN void
#define glEvalCoord2f_ARG_NAMES u, v
#define glEvalCoord2f_ARG_EXPAND GLfloat u, GLfloat v
#define glEvalCoord2f_PACKED PACKED_void_GLfloat_GLfloat
#define glEvalCoord2f_INDEXED INDEXED_void_GLfloat_GLfloat
#define glEvalCoord2f_FORMAT FORMAT_void_GLfloat_GLfloat
#define glEvalCoord2fv_INDEX 118
#define glEvalCoord2fv_RETURN void
#define glEvalCoord2fv_ARG_NAMES u
#define glEvalCoord2fv_ARG_EXPAND const GLfloat * u
#define glEvalCoord2fv_PACKED PACKED_void_const_GLfloat___GENPT__
#define glEvalCoord2fv_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glEvalCoord2fv_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glEvalMesh1_INDEX 119
#define glEvalMesh1_RETURN void
#define glEvalMesh1_ARG_NAMES mode, i1, i2
#define glEvalMesh1_ARG_EXPAND GLenum mode, GLint i1, GLint i2
#define glEvalMesh1_PACKED PACKED_void_GLenum_GLint_GLint
#define glEvalMesh1_INDEXED INDEXED_void_GLenum_GLint_GLint
#define glEvalMesh1_FORMAT FORMAT_void_GLenum_GLint_GLint
#define glEvalMesh2_INDEX 120
#define glEvalMesh2_RETURN void
#define glEvalMesh2_ARG_NAMES mode, i1, i2, j1, j2
#define glEvalMesh2_ARG_EXPAND GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2
#define glEvalMesh2_PACKED PACKED_void_GLenum_GLint_GLint_GLint_GLint
#define glEvalMesh2_INDEXED INDEXED_void_GLenum_GLint_GLint_GLint_GLint
#define glEvalMesh2_FORMAT FORMAT_void_GLenum_GLint_GLint_GLint_GLint
#define glEvalPoint1_INDEX 121
#define glEvalPoint1_RETURN void
#define glEvalPoint1_ARG_NAMES i
#define glEvalPoint1_ARG_EXPAND GLint i
#define glEvalPoint1_PACKED PACKED_void_GLint
#define glEvalPoint1_INDEXED INDEXED_void_GLint
#define glEvalPoint1_FORMAT FORMAT_void_GLint
#define glEvalPoint2_INDEX 122
#define glEvalPoint2_RETURN void
#define glEvalPoint2_ARG_NAMES i, j
#define glEvalPoint2_ARG_EXPAND GLint i, GLint j
#define glEvalPoint2_PACKED PACKED_void_GLint_GLint
#define glEvalPoint2_INDEXED INDEXED_void_GLint_GLint
#define glEvalPoint2_FORMAT FORMAT_void_GLint_GLint
#define glFeedbackBuffer_INDEX 123
#define glFeedbackBuffer_RETURN void
#define glFeedbackBuffer_ARG_NAMES size, type, buffer
#define glFeedbackBuffer_ARG_EXPAND GLsizei size, GLenum type, GLfloat * buffer
#define glFeedbackBuffer_PACKED PACKED_void_GLsizei_GLenum_GLfloat___GENPT__
#define glFeedbackBuffer_INDEXED INDEXED_void_GLsizei_GLenum_GLfloat___GENPT__
#define glFeedbackBuffer_FORMAT FORMAT_void_GLsizei_GLenum_GLfloat___GENPT__
#define glFinish_INDEX 124
#define glFinish_RETURN void
#define glFinish_ARG_NAMES 
#define glFinish_ARG_EXPAND 
#define glFinish_PACKED PACKED_void
#define glFinish_INDEXED INDEXED_void
#define glFinish_FORMAT FORMAT_void
#define glFlush_INDEX 125
#define glFlush_RETURN void
#define glFlush_ARG_NAMES 
#define glFlush_ARG_EXPAND 
#define glFlush_PACKED PACKED_void
#define glFlush_INDEXED INDEXED_void
#define glFlush_FORMAT FORMAT_void
#define glFogCoordPointer_INDEX 126
#define glFogCoordPointer_RETURN void
#define glFogCoordPointer_ARG_NAMES type, stride, pointer
#define glFogCoordPointer_ARG_EXPAND GLenum type, GLsizei stride, const GLvoid * pointer
#define glFogCoordPointer_PACKED PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__
#define glFogCoordPointer_INDEXED INDEXED_void_GLenum_GLsizei_const_GLvoid___GENPT__
#define glFogCoordPointer_FORMAT FORMAT_void_GLenum_GLsizei_const_GLvoid___GENPT__
#define glFogCoordd_INDEX 127
#define glFogCoordd_RETURN void
#define glFogCoordd_ARG_NAMES coord
#define glFogCoordd_ARG_EXPAND GLdouble coord
#define glFogCoordd_PACKED PACKED_void_GLdouble
#define glFogCoordd_INDEXED INDEXED_void_GLdouble
#define glFogCoordd_FORMAT FORMAT_void_GLdouble
#define glFogCoorddv_INDEX 128
#define glFogCoorddv_RETURN void
#define glFogCoorddv_ARG_NAMES coord
#define glFogCoorddv_ARG_EXPAND const GLdouble * coord
#define glFogCoorddv_PACKED PACKED_void_const_GLdouble___GENPT__
#define glFogCoorddv_INDEXED INDEXED_void_const_GLdouble___GENPT__
#define glFogCoorddv_FORMAT FORMAT_void_const_GLdouble___GENPT__
#define glFogCoordf_INDEX 129
#define glFogCoordf_RETURN void
#define glFogCoordf_ARG_NAMES coord
#define glFogCoordf_ARG_EXPAND GLfloat coord
#define glFogCoordf_PACKED PACKED_void_GLfloat
#define glFogCoordf_INDEXED INDEXED_void_GLfloat
#define glFogCoordf_FORMAT FORMAT_void_GLfloat
#define glFogCoordfv_INDEX 130
#define glFogCoordfv_RETURN void
#define glFogCoordfv_ARG_NAMES coord
#define glFogCoordfv_ARG_EXPAND const GLfloat * coord
#define glFogCoordfv_PACKED PACKED_void_const_GLfloat___GENPT__
#define glFogCoordfv_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glFogCoordfv_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glFogf_INDEX 131
#define glFogf_RETURN void
#define glFogf_ARG_NAMES pname, param
#define glFogf_ARG_EXPAND GLenum pname, GLfloat param
#define glFogf_PACKED PACKED_void_GLenum_GLfloat
#define glFogf_INDEXED INDEXED_void_GLenum_GLfloat
#define glFogf_FORMAT FORMAT_void_GLenum_GLfloat
#define glFogfv_INDEX 132
#define glFogfv_RETURN void
#define glFogfv_ARG_NAMES pname, params
#define glFogfv_ARG_EXPAND GLenum pname, const GLfloat * params
#define glFogfv_PACKED PACKED_void_GLenum_const_GLfloat___GENPT__
#define glFogfv_INDEXED INDEXED_void_GLenum_const_GLfloat___GENPT__
#define glFogfv_FORMAT FORMAT_void_GLenum_const_GLfloat___GENPT__
#define glFogi_INDEX 133
#define glFogi_RETURN void
#define glFogi_ARG_NAMES pname, param
#define glFogi_ARG_EXPAND GLenum pname, GLint param
#define glFogi_PACKED PACKED_void_GLenum_GLint
#define glFogi_INDEXED INDEXED_void_GLenum_GLint
#define glFogi_FORMAT FORMAT_void_GLenum_GLint
#define glFogiv_INDEX 134
#define glFogiv_RETURN void
#define glFogiv_ARG_NAMES pname, params
#define glFogiv_ARG_EXPAND GLenum pname, const GLint * params
#define glFogiv_PACKED PACKED_void_GLenum_const_GLint___GENPT__
#define glFogiv_INDEXED INDEXED_void_GLenum_const_GLint___GENPT__
#define glFogiv_FORMAT FORMAT_void_GLenum_const_GLint___GENPT__
#define glFrontFace_INDEX 135
#define glFrontFace_RETURN void
#define glFrontFace_ARG_NAMES mode
#define glFrontFace_ARG_EXPAND GLenum mode
#define glFrontFace_PACKED PACKED_void_GLenum
#define glFrontFace_INDEXED INDEXED_void_GLenum
#define glFrontFace_FORMAT FORMAT_void_GLenum
#define glFrustum_INDEX 136
#define glFrustum_RETURN void
#define glFrustum_ARG_NAMES left, right, bottom, top, zNear, zFar
#define glFrustum_ARG_EXPAND GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar
#define glFrustum_PACKED PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble
#define glFrustum_INDEXED INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble
#define glFrustum_FORMAT FORMAT_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble
#define glGenBuffers_INDEX 137
#define glGenBuffers_RETURN void
#define glGenBuffers_ARG_NAMES n, buffers
#define glGenBuffers_ARG_EXPAND GLsizei n, GLuint * buffers
#define glGenBuffers_PACKED PACKED_void_GLsizei_GLuint___GENPT__
#define glGenBuffers_INDEXED INDEXED_void_GLsizei_GLuint___GENPT__
#define glGenBuffers_FORMAT FORMAT_void_GLsizei_GLuint___GENPT__
#define glGenLists_INDEX 138
#define glGenLists_RETURN GLuint
#define glGenLists_ARG_NAMES range
#define glGenLists_ARG_EXPAND GLsizei range
#define glGenLists_PACKED PACKED_GLuint_GLsizei
#define glGenLists_INDEXED INDEXED_GLuint_GLsizei
#define glGenLists_FORMAT FORMAT_GLuint_GLsizei
#define glGenQueries_INDEX 139
#define glGenQueries_RETURN void
#define glGenQueries_ARG_NAMES n, ids
#define glGenQueries_ARG_EXPAND GLsizei n, GLuint * ids
#define glGenQueries_PACKED PACKED_void_GLsizei_GLuint___GENPT__
#define glGenQueries_INDEXED INDEXED_void_GLsizei_GLuint___GENPT__
#define glGenQueries_FORMAT FORMAT_void_GLsizei_GLuint___GENPT__
#define glGenTextures_INDEX 140
#define glGenTextures_RETURN void
#define glGenTextures_ARG_NAMES n, textures
#define glGenTextures_ARG_EXPAND GLsizei n, GLuint * textures
#define glGenTextures_PACKED PACKED_void_GLsizei_GLuint___GENPT__
#define glGenTextures_INDEXED INDEXED_void_GLsizei_GLuint___GENPT__
#define glGenTextures_FORMAT FORMAT_void_GLsizei_GLuint___GENPT__
#define glGetBooleanv_INDEX 141
#define glGetBooleanv_RETURN void
#define glGetBooleanv_ARG_NAMES pname, params
#define glGetBooleanv_ARG_EXPAND GLenum pname, GLboolean * params
#define glGetBooleanv_PACKED PACKED_void_GLenum_GLboolean___GENPT__
#define glGetBooleanv_INDEXED INDEXED_void_GLenum_GLboolean___GENPT__
#define glGetBooleanv_FORMAT FORMAT_void_GLenum_GLboolean___GENPT__
#define glGetBufferParameteriv_INDEX 142
#define glGetBufferParameteriv_RETURN void
#define glGetBufferParameteriv_ARG_NAMES target, pname, params
#define glGetBufferParameteriv_ARG_EXPAND GLenum target, GLenum pname, GLint * params
#define glGetBufferParameteriv_PACKED PACKED_void_GLenum_GLenum_GLint___GENPT__
#define glGetBufferParameteriv_INDEXED INDEXED_void_GLenum_GLenum_GLint___GENPT__
#define glGetBufferParameteriv_FORMAT FORMAT_void_GLenum_GLenum_GLint___GENPT__
#define glGetBufferPointerv_INDEX 143
#define glGetBufferPointerv_RETURN void
#define glGetBufferPointerv_ARG_NAMES target, pname, params
#define glGetBufferPointerv_ARG_EXPAND GLenum target, GLenum pname, GLvoid * params
#define glGetBufferPointerv_PACKED PACKED_void_GLenum_GLenum_GLvoid___GENPT__
#define glGetBufferPointerv_INDEXED INDEXED_void_GLenum_GLenum_GLvoid___GENPT__
#define glGetBufferPointerv_FORMAT FORMAT_void_GLenum_GLenum_GLvoid___GENPT__
#define glGetBufferSubData_INDEX 144
#define glGetBufferSubData_RETURN void
#define glGetBufferSubData_ARG_NAMES target, offset, size, data
#define glGetBufferSubData_ARG_EXPAND GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data
#define glGetBufferSubData_PACKED PACKED_void_GLenum_GLintptr_GLsizeiptr_GLvoid___GENPT__
#define glGetBufferSubData_INDEXED INDEXED_void_GLenum_GLintptr_GLsizeiptr_GLvoid___GENPT__
#define glGetBufferSubData_FORMAT FORMAT_void_GLenum_GLintptr_GLsizeiptr_GLvoid___GENPT__
#define glGetClipPlane_INDEX 145
#define glGetClipPlane_RETURN void
#define glGetClipPlane_ARG_NAMES plane, equation
#define glGetClipPlane_ARG_EXPAND GLenum plane, GLdouble * equation
#define glGetClipPlane_PACKED PACKED_void_GLenum_GLdouble___GENPT__
#define glGetClipPlane_INDEXED INDEXED_void_GLenum_GLdouble___GENPT__
#define glGetClipPlane_FORMAT FORMAT_void_GLenum_GLdouble___GENPT__
#define glGetColorTable_INDEX 146
#define glGetColorTable_RETURN void
#define glGetColorTable_ARG_NAMES target, format, type, table
#define glGetColorTable_ARG_EXPAND GLenum target, GLenum format, GLenum type, GLvoid * table
#define glGetColorTable_PACKED PACKED_void_GLenum_GLenum_GLenum_GLvoid___GENPT__
#define glGetColorTable_INDEXED INDEXED_void_GLenum_GLenum_GLenum_GLvoid___GENPT__
#define glGetColorTable_FORMAT FORMAT_void_GLenum_GLenum_GLenum_GLvoid___GENPT__
#define glGetColorTableParameterfv_INDEX 147
#define glGetColorTableParameterfv_RETURN void
#define glGetColorTableParameterfv_ARG_NAMES target, pname, params
#define glGetColorTableParameterfv_ARG_EXPAND GLenum target, GLenum pname, GLfloat * params
#define glGetColorTableParameterfv_PACKED PACKED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetColorTableParameterfv_INDEXED INDEXED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetColorTableParameterfv_FORMAT FORMAT_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetColorTableParameteriv_INDEX 148
#define glGetColorTableParameteriv_RETURN void
#define glGetColorTableParameteriv_ARG_NAMES target, pname, params
#define glGetColorTableParameteriv_ARG_EXPAND GLenum target, GLenum pname, GLint * params
#define glGetColorTableParameteriv_PACKED PACKED_void_GLenum_GLenum_GLint___GENPT__
#define glGetColorTableParameteriv_INDEXED INDEXED_void_GLenum_GLenum_GLint___GENPT__
#define glGetColorTableParameteriv_FORMAT FORMAT_void_GLenum_GLenum_GLint___GENPT__
#define glGetCompressedTexImage_INDEX 149
#define glGetCompressedTexImage_RETURN void
#define glGetCompressedTexImage_ARG_NAMES target, level, img
#define glGetCompressedTexImage_ARG_EXPAND GLenum target, GLint level, GLvoid * img
#define glGetCompressedTexImage_PACKED PACKED_void_GLenum_GLint_GLvoid___GENPT__
#define glGetCompressedTexImage_INDEXED INDEXED_void_GLenum_GLint_GLvoid___GENPT__
#define glGetCompressedTexImage_FORMAT FORMAT_void_GLenum_GLint_GLvoid___GENPT__
#define glGetConvolutionFilter_INDEX 150
#define glGetConvolutionFilter_RETURN void
#define glGetConvolutionFilter_ARG_NAMES target, format, type, image
#define glGetConvolutionFilter_ARG_EXPAND GLenum target, GLenum format, GLenum type, GLvoid * image
#define glGetConvolutionFilter_PACKED PACKED_void_GLenum_GLenum_GLenum_GLvoid___GENPT__
#define glGetConvolutionFilter_INDEXED INDEXED_void_GLenum_GLenum_GLenum_GLvoid___GENPT__
#define glGetConvolutionFilter_FORMAT FORMAT_void_GLenum_GLenum_GLenum_GLvoid___GENPT__
#define glGetConvolutionParameterfv_INDEX 151
#define glGetConvolutionParameterfv_RETURN void
#define glGetConvolutionParameterfv_ARG_NAMES target, pname, params
#define glGetConvolutionParameterfv_ARG_EXPAND GLenum target, GLenum pname, GLfloat * params
#define glGetConvolutionParameterfv_PACKED PACKED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetConvolutionParameterfv_INDEXED INDEXED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetConvolutionParameterfv_FORMAT FORMAT_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetConvolutionParameteriv_INDEX 152
#define glGetConvolutionParameteriv_RETURN void
#define glGetConvolutionParameteriv_ARG_NAMES target, pname, params
#define glGetConvolutionParameteriv_ARG_EXPAND GLenum target, GLenum pname, GLint * params
#define glGetConvolutionParameteriv_PACKED PACKED_void_GLenum_GLenum_GLint___GENPT__
#define glGetConvolutionParameteriv_INDEXED INDEXED_void_GLenum_GLenum_GLint___GENPT__
#define glGetConvolutionParameteriv_FORMAT FORMAT_void_GLenum_GLenum_GLint___GENPT__
#define glGetDoublev_INDEX 153
#define glGetDoublev_RETURN void
#define glGetDoublev_ARG_NAMES pname, params
#define glGetDoublev_ARG_EXPAND GLenum pname, GLdouble * params
#define glGetDoublev_PACKED PACKED_void_GLenum_GLdouble___GENPT__
#define glGetDoublev_INDEXED INDEXED_void_GLenum_GLdouble___GENPT__
#define glGetDoublev_FORMAT FORMAT_void_GLenum_GLdouble___GENPT__
#define glGetError_INDEX 154
#define glGetError_RETURN GLenum
#define glGetError_ARG_NAMES 
#define glGetError_ARG_EXPAND 
#define glGetError_PACKED PACKED_GLenum
#define glGetError_INDEXED INDEXED_GLenum
#define glGetError_FORMAT FORMAT_GLenum
#define glGetFloatv_INDEX 155
#define glGetFloatv_RETURN void
#define glGetFloatv_ARG_NAMES pname, params
#define glGetFloatv_ARG_EXPAND GLenum pname, GLfloat * params
#define glGetFloatv_PACKED PACKED_void_GLenum_GLfloat___GENPT__
#define glGetFloatv_INDEXED INDEXED_void_GLenum_GLfloat___GENPT__
#define glGetFloatv_FORMAT FORMAT_void_GLenum_GLfloat___GENPT__
#define glGetHistogram_INDEX 156
#define glGetHistogram_RETURN void
#define glGetHistogram_ARG_NAMES target, reset, format, type, values
#define glGetHistogram_ARG_EXPAND GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values
#define glGetHistogram_PACKED PACKED_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__
#define glGetHistogram_INDEXED INDEXED_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__
#define glGetHistogram_FORMAT FORMAT_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__
#define glGetHistogramParameterfv_INDEX 157
#define glGetHistogramParameterfv_RETURN void
#define glGetHistogramParameterfv_ARG_NAMES target, pname, params
#define glGetHistogramParameterfv_ARG_EXPAND GLenum target, GLenum pname, GLfloat * params
#define glGetHistogramParameterfv_PACKED PACKED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetHistogramParameterfv_INDEXED INDEXED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetHistogramParameterfv_FORMAT FORMAT_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetHistogramParameteriv_INDEX 158
#define glGetHistogramParameteriv_RETURN void
#define glGetHistogramParameteriv_ARG_NAMES target, pname, params
#define glGetHistogramParameteriv_ARG_EXPAND GLenum target, GLenum pname, GLint * params
#define glGetHistogramParameteriv_PACKED PACKED_void_GLenum_GLenum_GLint___GENPT__
#define glGetHistogramParameteriv_INDEXED INDEXED_void_GLenum_GLenum_GLint___GENPT__
#define glGetHistogramParameteriv_FORMAT FORMAT_void_GLenum_GLenum_GLint___GENPT__
#define glGetIntegerv_INDEX 159
#define glGetIntegerv_RETURN void
#define glGetIntegerv_ARG_NAMES pname, params
#define glGetIntegerv_ARG_EXPAND GLenum pname, GLint * params
#define glGetIntegerv_PACKED PACKED_void_GLenum_GLint___GENPT__
#define glGetIntegerv_INDEXED INDEXED_void_GLenum_GLint___GENPT__
#define glGetIntegerv_FORMAT FORMAT_void_GLenum_GLint___GENPT__
#define glGetLightfv_INDEX 160
#define glGetLightfv_RETURN void
#define glGetLightfv_ARG_NAMES light, pname, params
#define glGetLightfv_ARG_EXPAND GLenum light, GLenum pname, GLfloat * params
#define glGetLightfv_PACKED PACKED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetLightfv_INDEXED INDEXED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetLightfv_FORMAT FORMAT_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetLightiv_INDEX 161
#define glGetLightiv_RETURN void
#define glGetLightiv_ARG_NAMES light, pname, params
#define glGetLightiv_ARG_EXPAND GLenum light, GLenum pname, GLint * params
#define glGetLightiv_PACKED PACKED_void_GLenum_GLenum_GLint___GENPT__
#define glGetLightiv_INDEXED INDEXED_void_GLenum_GLenum_GLint___GENPT__
#define glGetLightiv_FORMAT FORMAT_void_GLenum_GLenum_GLint___GENPT__
#define glGetMapdv_INDEX 162
#define glGetMapdv_RETURN void
#define glGetMapdv_ARG_NAMES target, query, v
#define glGetMapdv_ARG_EXPAND GLenum target, GLenum query, GLdouble * v
#define glGetMapdv_PACKED PACKED_void_GLenum_GLenum_GLdouble___GENPT__
#define glGetMapdv_INDEXED INDEXED_void_GLenum_GLenum_GLdouble___GENPT__
#define glGetMapdv_FORMAT FORMAT_void_GLenum_GLenum_GLdouble___GENPT__
#define glGetMapfv_INDEX 163
#define glGetMapfv_RETURN void
#define glGetMapfv_ARG_NAMES target, query, v
#define glGetMapfv_ARG_EXPAND GLenum target, GLenum query, GLfloat * v
#define glGetMapfv_PACKED PACKED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetMapfv_INDEXED INDEXED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetMapfv_FORMAT FORMAT_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetMapiv_INDEX 164
#define glGetMapiv_RETURN void
#define glGetMapiv_ARG_NAMES target, query, v
#define glGetMapiv_ARG_EXPAND GLenum target, GLenum query, GLint * v
#define glGetMapiv_PACKED PACKED_void_GLenum_GLenum_GLint___GENPT__
#define glGetMapiv_INDEXED INDEXED_void_GLenum_GLenum_GLint___GENPT__
#define glGetMapiv_FORMAT FORMAT_void_GLenum_GLenum_GLint___GENPT__
#define glGetMaterialfv_INDEX 165
#define glGetMaterialfv_RETURN void
#define glGetMaterialfv_ARG_NAMES face, pname, params
#define glGetMaterialfv_ARG_EXPAND GLenum face, GLenum pname, GLfloat * params
#define glGetMaterialfv_PACKED PACKED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetMaterialfv_INDEXED INDEXED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetMaterialfv_FORMAT FORMAT_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetMaterialiv_INDEX 166
#define glGetMaterialiv_RETURN void
#define glGetMaterialiv_ARG_NAMES face, pname, params
#define glGetMaterialiv_ARG_EXPAND GLenum face, GLenum pname, GLint * params
#define glGetMaterialiv_PACKED PACKED_void_GLenum_GLenum_GLint___GENPT__
#define glGetMaterialiv_INDEXED INDEXED_void_GLenum_GLenum_GLint___GENPT__
#define glGetMaterialiv_FORMAT FORMAT_void_GLenum_GLenum_GLint___GENPT__
#define glGetMinmax_INDEX 167
#define glGetMinmax_RETURN void
#define glGetMinmax_ARG_NAMES target, reset, format, type, values
#define glGetMinmax_ARG_EXPAND GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values
#define glGetMinmax_PACKED PACKED_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__
#define glGetMinmax_INDEXED INDEXED_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__
#define glGetMinmax_FORMAT FORMAT_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__
#define glGetMinmaxParameterfv_INDEX 168
#define glGetMinmaxParameterfv_RETURN void
#define glGetMinmaxParameterfv_ARG_NAMES target, pname, params
#define glGetMinmaxParameterfv_ARG_EXPAND GLenum target, GLenum pname, GLfloat * params
#define glGetMinmaxParameterfv_PACKED PACKED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetMinmaxParameterfv_INDEXED INDEXED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetMinmaxParameterfv_FORMAT FORMAT_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetMinmaxParameteriv_INDEX 169
#define glGetMinmaxParameteriv_RETURN void
#define glGetMinmaxParameteriv_ARG_NAMES target, pname, params
#define glGetMinmaxParameteriv_ARG_EXPAND GLenum target, GLenum pname, GLint * params
#define glGetMinmaxParameteriv_PACKED PACKED_void_GLenum_GLenum_GLint___GENPT__
#define glGetMinmaxParameteriv_INDEXED INDEXED_void_GLenum_GLenum_GLint___GENPT__
#define glGetMinmaxParameteriv_FORMAT FORMAT_void_GLenum_GLenum_GLint___GENPT__
#define glGetPixelMapfv_INDEX 170
#define glGetPixelMapfv_RETURN void
#define glGetPixelMapfv_ARG_NAMES map, values
#define glGetPixelMapfv_ARG_EXPAND GLenum map, GLfloat * values
#define glGetPixelMapfv_PACKED PACKED_void_GLenum_GLfloat___GENPT__
#define glGetPixelMapfv_INDEXED INDEXED_void_GLenum_GLfloat___GENPT__
#define glGetPixelMapfv_FORMAT FORMAT_void_GLenum_GLfloat___GENPT__
#define glGetPixelMapuiv_INDEX 171
#define glGetPixelMapuiv_RETURN void
#define glGetPixelMapuiv_ARG_NAMES map, values
#define glGetPixelMapuiv_ARG_EXPAND GLenum map, GLuint * values
#define glGetPixelMapuiv_PACKED PACKED_void_GLenum_GLuint___GENPT__
#define glGetPixelMapuiv_INDEXED INDEXED_void_GLenum_GLuint___GENPT__
#define glGetPixelMapuiv_FORMAT FORMAT_void_GLenum_GLuint___GENPT__
#define glGetPixelMapusv_INDEX 172
#define glGetPixelMapusv_RETURN void
#define glGetPixelMapusv_ARG_NAMES map, values
#define glGetPixelMapusv_ARG_EXPAND GLenum map, GLushort * values
#define glGetPixelMapusv_PACKED PACKED_void_GLenum_GLushort___GENPT__
#define glGetPixelMapusv_INDEXED INDEXED_void_GLenum_GLushort___GENPT__
#define glGetPixelMapusv_FORMAT FORMAT_void_GLenum_GLushort___GENPT__
#define glGetPointerv_INDEX 173
#define glGetPointerv_RETURN void
#define glGetPointerv_ARG_NAMES pname, params
#define glGetPointerv_ARG_EXPAND GLenum pname, GLvoid ** params
#define glGetPointerv_PACKED PACKED_void_GLenum_GLvoid___GENPT____GENPT__
#define glGetPointerv_INDEXED INDEXED_void_GLenum_GLvoid___GENPT____GENPT__
#define glGetPointerv_FORMAT FORMAT_void_GLenum_GLvoid___GENPT____GENPT__
#define glGetPolygonStipple_INDEX 174
#define glGetPolygonStipple_RETURN void
#define glGetPolygonStipple_ARG_NAMES mask
#define glGetPolygonStipple_ARG_EXPAND GLubyte * mask
#define glGetPolygonStipple_PACKED PACKED_void_GLubyte___GENPT__
#define glGetPolygonStipple_INDEXED INDEXED_void_GLubyte___GENPT__
#define glGetPolygonStipple_FORMAT FORMAT_void_GLubyte___GENPT__
#define glGetQueryObjectiv_INDEX 175
#define glGetQueryObjectiv_RETURN void
#define glGetQueryObjectiv_ARG_NAMES id, pname, params
#define glGetQueryObjectiv_ARG_EXPAND GLuint id, GLenum pname, GLint * params
#define glGetQueryObjectiv_PACKED PACKED_void_GLuint_GLenum_GLint___GENPT__
#define glGetQueryObjectiv_INDEXED INDEXED_void_GLuint_GLenum_GLint___GENPT__
#define glGetQueryObjectiv_FORMAT FORMAT_void_GLuint_GLenum_GLint___GENPT__
#define glGetQueryObjectuiv_INDEX 176
#define glGetQueryObjectuiv_RETURN void
#define glGetQueryObjectuiv_ARG_NAMES id, pname, params
#define glGetQueryObjectuiv_ARG_EXPAND GLuint id, GLenum pname, GLuint * params
#define glGetQueryObjectuiv_PACKED PACKED_void_GLuint_GLenum_GLuint___GENPT__
#define glGetQueryObjectuiv_INDEXED INDEXED_void_GLuint_GLenum_GLuint___GENPT__
#define glGetQueryObjectuiv_FORMAT FORMAT_void_GLuint_GLenum_GLuint___GENPT__
#define glGetQueryiv_INDEX 177
#define glGetQueryiv_RETURN void
#define glGetQueryiv_ARG_NAMES target, pname, params
#define glGetQueryiv_ARG_EXPAND GLenum target, GLenum pname, GLint * params
#define glGetQueryiv_PACKED PACKED_void_GLenum_GLenum_GLint___GENPT__
#define glGetQueryiv_INDEXED INDEXED_void_GLenum_GLenum_GLint___GENPT__
#define glGetQueryiv_FORMAT FORMAT_void_GLenum_GLenum_GLint___GENPT__
#define glGetSeparableFilter_INDEX 178
#define glGetSeparableFilter_RETURN void
#define glGetSeparableFilter_ARG_NAMES target, format, type, row, column, span
#define glGetSeparableFilter_ARG_EXPAND GLenum target, GLenum format, GLenum type, GLvoid * row, GLvoid * column, GLvoid * span
#define glGetSeparableFilter_PACKED PACKED_void_GLenum_GLenum_GLenum_GLvoid___GENPT___GLvoid___GENPT___GLvoid___GENPT__
#define glGetSeparableFilter_INDEXED INDEXED_void_GLenum_GLenum_GLenum_GLvoid___GENPT___GLvoid___GENPT___GLvoid___GENPT__
#define glGetSeparableFilter_FORMAT FORMAT_void_GLenum_GLenum_GLenum_GLvoid___GENPT___GLvoid___GENPT___GLvoid___GENPT__
#define glGetString_INDEX 179
#define glGetString_RETURN const GLubyte *
#define glGetString_ARG_NAMES name
#define glGetString_ARG_EXPAND GLenum name
#define glGetString_PACKED PACKED_const_GLubyte___GENPT___GLenum
#define glGetString_INDEXED INDEXED_const_GLubyte___GENPT___GLenum
#define glGetString_FORMAT FORMAT_const_GLubyte___GENPT___GLenum
#define glGetTexEnvfv_INDEX 180
#define glGetTexEnvfv_RETURN void
#define glGetTexEnvfv_ARG_NAMES target, pname, params
#define glGetTexEnvfv_ARG_EXPAND GLenum target, GLenum pname, GLfloat * params
#define glGetTexEnvfv_PACKED PACKED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetTexEnvfv_INDEXED INDEXED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetTexEnvfv_FORMAT FORMAT_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetTexEnviv_INDEX 181
#define glGetTexEnviv_RETURN void
#define glGetTexEnviv_ARG_NAMES target, pname, params
#define glGetTexEnviv_ARG_EXPAND GLenum target, GLenum pname, GLint * params
#define glGetTexEnviv_PACKED PACKED_void_GLenum_GLenum_GLint___GENPT__
#define glGetTexEnviv_INDEXED INDEXED_void_GLenum_GLenum_GLint___GENPT__
#define glGetTexEnviv_FORMAT FORMAT_void_GLenum_GLenum_GLint___GENPT__
#define glGetTexGendv_INDEX 182
#define glGetTexGendv_RETURN void
#define glGetTexGendv_ARG_NAMES coord, pname, params
#define glGetTexGendv_ARG_EXPAND GLenum coord, GLenum pname, GLdouble * params
#define glGetTexGendv_PACKED PACKED_void_GLenum_GLenum_GLdouble___GENPT__
#define glGetTexGendv_INDEXED INDEXED_void_GLenum_GLenum_GLdouble___GENPT__
#define glGetTexGendv_FORMAT FORMAT_void_GLenum_GLenum_GLdouble___GENPT__
#define glGetTexGenfv_INDEX 183
#define glGetTexGenfv_RETURN void
#define glGetTexGenfv_ARG_NAMES coord, pname, params
#define glGetTexGenfv_ARG_EXPAND GLenum coord, GLenum pname, GLfloat * params
#define glGetTexGenfv_PACKED PACKED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetTexGenfv_INDEXED INDEXED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetTexGenfv_FORMAT FORMAT_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetTexGeniv_INDEX 184
#define glGetTexGeniv_RETURN void
#define glGetTexGeniv_ARG_NAMES coord, pname, params
#define glGetTexGeniv_ARG_EXPAND GLenum coord, GLenum pname, GLint * params
#define glGetTexGeniv_PACKED PACKED_void_GLenum_GLenum_GLint___GENPT__
#define glGetTexGeniv_INDEXED INDEXED_void_GLenum_GLenum_GLint___GENPT__
#define glGetTexGeniv_FORMAT FORMAT_void_GLenum_GLenum_GLint___GENPT__
#define glGetTexImage_INDEX 185
#define glGetTexImage_RETURN void
#define glGetTexImage_ARG_NAMES target, level, format, type, pixels
#define glGetTexImage_ARG_EXPAND GLenum target, GLint level, GLenum format, GLenum type, GLvoid * pixels
#define glGetTexImage_PACKED PACKED_void_GLenum_GLint_GLenum_GLenum_GLvoid___GENPT__
#define glGetTexImage_INDEXED INDEXED_void_GLenum_GLint_GLenum_GLenum_GLvoid___GENPT__
#define glGetTexImage_FORMAT FORMAT_void_GLenum_GLint_GLenum_GLenum_GLvoid___GENPT__
#define glGetTexLevelParameterfv_INDEX 186
#define glGetTexLevelParameterfv_RETURN void
#define glGetTexLevelParameterfv_ARG_NAMES target, level, pname, params
#define glGetTexLevelParameterfv_ARG_EXPAND GLenum target, GLint level, GLenum pname, GLfloat * params
#define glGetTexLevelParameterfv_PACKED PACKED_void_GLenum_GLint_GLenum_GLfloat___GENPT__
#define glGetTexLevelParameterfv_INDEXED INDEXED_void_GLenum_GLint_GLenum_GLfloat___GENPT__
#define glGetTexLevelParameterfv_FORMAT FORMAT_void_GLenum_GLint_GLenum_GLfloat___GENPT__
#define glGetTexLevelParameteriv_INDEX 187
#define glGetTexLevelParameteriv_RETURN void
#define glGetTexLevelParameteriv_ARG_NAMES target, level, pname, params
#define glGetTexLevelParameteriv_ARG_EXPAND GLenum target, GLint level, GLenum pname, GLint * params
#define glGetTexLevelParameteriv_PACKED PACKED_void_GLenum_GLint_GLenum_GLint___GENPT__
#define glGetTexLevelParameteriv_INDEXED INDEXED_void_GLenum_GLint_GLenum_GLint___GENPT__
#define glGetTexLevelParameteriv_FORMAT FORMAT_void_GLenum_GLint_GLenum_GLint___GENPT__
#define glGetTexParameterfv_INDEX 188
#define glGetTexParameterfv_RETURN void
#define glGetTexParameterfv_ARG_NAMES target, pname, params
#define glGetTexParameterfv_ARG_EXPAND GLenum target, GLenum pname, GLfloat * params
#define glGetTexParameterfv_PACKED PACKED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetTexParameterfv_INDEXED INDEXED_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetTexParameterfv_FORMAT FORMAT_void_GLenum_GLenum_GLfloat___GENPT__
#define glGetTexParameteriv_INDEX 189
#define glGetTexParameteriv_RETURN void
#define glGetTexParameteriv_ARG_NAMES target, pname, params
#define glGetTexParameteriv_ARG_EXPAND GLenum target, GLenum pname, GLint * params
#define glGetTexParameteriv_PACKED PACKED_void_GLenum_GLenum_GLint___GENPT__
#define glGetTexParameteriv_INDEXED INDEXED_void_GLenum_GLenum_GLint___GENPT__
#define glGetTexParameteriv_FORMAT FORMAT_void_GLenum_GLenum_GLint___GENPT__
#define glHint_INDEX 190
#define glHint_RETURN void
#define glHint_ARG_NAMES target, mode
#define glHint_ARG_EXPAND GLenum target, GLenum mode
#define glHint_PACKED PACKED_void_GLenum_GLenum
#define glHint_INDEXED INDEXED_void_GLenum_GLenum
#define glHint_FORMAT FORMAT_void_GLenum_GLenum
#define glHistogram_INDEX 191
#define glHistogram_RETURN void
#define glHistogram_ARG_NAMES target, width, internalformat, sink
#define glHistogram_ARG_EXPAND GLenum target, GLsizei width, GLenum internalformat, GLboolean sink
#define glHistogram_PACKED PACKED_void_GLenum_GLsizei_GLenum_GLboolean
#define glHistogram_INDEXED INDEXED_void_GLenum_GLsizei_GLenum_GLboolean
#define glHistogram_FORMAT FORMAT_void_GLenum_GLsizei_GLenum_GLboolean
#define glIndexMask_INDEX 192
#define glIndexMask_RETURN void
#define glIndexMask_ARG_NAMES mask
#define glIndexMask_ARG_EXPAND GLuint mask
#define glIndexMask_PACKED PACKED_void_GLuint
#define glIndexMask_INDEXED INDEXED_void_GLuint
#define glIndexMask_FORMAT FORMAT_void_GLuint
#define glIndexPointer_INDEX 193
#define glIndexPointer_RETURN void
#define glIndexPointer_ARG_NAMES type, stride, pointer
#define glIndexPointer_ARG_EXPAND GLenum type, GLsizei stride, const GLvoid * pointer
#define glIndexPointer_PACKED PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__
#define glIndexPointer_INDEXED INDEXED_void_GLenum_GLsizei_const_GLvoid___GENPT__
#define glIndexPointer_FORMAT FORMAT_void_GLenum_GLsizei_const_GLvoid___GENPT__
#define glIndexd_INDEX 194
#define glIndexd_RETURN void
#define glIndexd_ARG_NAMES c
#define glIndexd_ARG_EXPAND GLdouble c
#define glIndexd_PACKED PACKED_void_GLdouble
#define glIndexd_INDEXED INDEXED_void_GLdouble
#define glIndexd_FORMAT FORMAT_void_GLdouble
#define glIndexdv_INDEX 195
#define glIndexdv_RETURN void
#define glIndexdv_ARG_NAMES c
#define glIndexdv_ARG_EXPAND const GLdouble * c
#define glIndexdv_PACKED PACKED_void_const_GLdouble___GENPT__
#define glIndexdv_INDEXED INDEXED_void_const_GLdouble___GENPT__
#define glIndexdv_FORMAT FORMAT_void_const_GLdouble___GENPT__
#define glIndexf_INDEX 196
#define glIndexf_RETURN void
#define glIndexf_ARG_NAMES c
#define glIndexf_ARG_EXPAND GLfloat c
#define glIndexf_PACKED PACKED_void_GLfloat
#define glIndexf_INDEXED INDEXED_void_GLfloat
#define glIndexf_FORMAT FORMAT_void_GLfloat
#define glIndexfv_INDEX 197
#define glIndexfv_RETURN void
#define glIndexfv_ARG_NAMES c
#define glIndexfv_ARG_EXPAND const GLfloat * c
#define glIndexfv_PACKED PACKED_void_const_GLfloat___GENPT__
#define glIndexfv_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glIndexfv_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glIndexi_INDEX 198
#define glIndexi_RETURN void
#define glIndexi_ARG_NAMES c
#define glIndexi_ARG_EXPAND GLint c
#define glIndexi_PACKED PACKED_void_GLint
#define glIndexi_INDEXED INDEXED_void_GLint
#define glIndexi_FORMAT FORMAT_void_GLint
#define glIndexiv_INDEX 199
#define glIndexiv_RETURN void
#define glIndexiv_ARG_NAMES c
#define glIndexiv_ARG_EXPAND const GLint * c
#define glIndexiv_PACKED PACKED_void_const_GLint___GENPT__
#define glIndexiv_INDEXED INDEXED_void_const_GLint___GENPT__
#define glIndexiv_FORMAT FORMAT_void_const_GLint___GENPT__
#define glIndexs_INDEX 200
#define glIndexs_RETURN void
#define glIndexs_ARG_NAMES c
#define glIndexs_ARG_EXPAND GLshort c
#define glIndexs_PACKED PACKED_void_GLshort
#define glIndexs_INDEXED INDEXED_void_GLshort
#define glIndexs_FORMAT FORMAT_void_GLshort
#define glIndexsv_INDEX 201
#define glIndexsv_RETURN void
#define glIndexsv_ARG_NAMES c
#define glIndexsv_ARG_EXPAND const GLshort * c
#define glIndexsv_PACKED PACKED_void_const_GLshort___GENPT__
#define glIndexsv_INDEXED INDEXED_void_const_GLshort___GENPT__
#define glIndexsv_FORMAT FORMAT_void_const_GLshort___GENPT__
#define glIndexub_INDEX 202
#define glIndexub_RETURN void
#define glIndexub_ARG_NAMES c
#define glIndexub_ARG_EXPAND GLubyte c
#define glIndexub_PACKED PACKED_void_GLubyte
#define glIndexub_INDEXED INDEXED_void_GLubyte
#define glIndexub_FORMAT FORMAT_void_GLubyte
#define glIndexubv_INDEX 203
#define glIndexubv_RETURN void
#define glIndexubv_ARG_NAMES c
#define glIndexubv_ARG_EXPAND const GLubyte * c
#define glIndexubv_PACKED PACKED_void_const_GLubyte___GENPT__
#define glIndexubv_INDEXED INDEXED_void_const_GLubyte___GENPT__
#define glIndexubv_FORMAT FORMAT_void_const_GLubyte___GENPT__
#define glInitNames_INDEX 204
#define glInitNames_RETURN void
#define glInitNames_ARG_NAMES 
#define glInitNames_ARG_EXPAND 
#define glInitNames_PACKED PACKED_void
#define glInitNames_INDEXED INDEXED_void
#define glInitNames_FORMAT FORMAT_void
#define glInterleavedArrays_INDEX 205
#define glInterleavedArrays_RETURN void
#define glInterleavedArrays_ARG_NAMES format, stride, pointer
#define glInterleavedArrays_ARG_EXPAND GLenum format, GLsizei stride, const GLvoid * pointer
#define glInterleavedArrays_PACKED PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__
#define glInterleavedArrays_INDEXED INDEXED_void_GLenum_GLsizei_const_GLvoid___GENPT__
#define glInterleavedArrays_FORMAT FORMAT_void_GLenum_GLsizei_const_GLvoid___GENPT__
#define glIsBuffer_INDEX 206
#define glIsBuffer_RETURN GLboolean
#define glIsBuffer_ARG_NAMES buffer
#define glIsBuffer_ARG_EXPAND GLuint buffer
#define glIsBuffer_PACKED PACKED_GLboolean_GLuint
#define glIsBuffer_INDEXED INDEXED_GLboolean_GLuint
#define glIsBuffer_FORMAT FORMAT_GLboolean_GLuint
#define glIsEnabled_INDEX 207
#define glIsEnabled_RETURN GLboolean
#define glIsEnabled_ARG_NAMES cap
#define glIsEnabled_ARG_EXPAND GLenum cap
#define glIsEnabled_PACKED PACKED_GLboolean_GLenum
#define glIsEnabled_INDEXED INDEXED_GLboolean_GLenum
#define glIsEnabled_FORMAT FORMAT_GLboolean_GLenum
#define glIsList_INDEX 208
#define glIsList_RETURN GLboolean
#define glIsList_ARG_NAMES list
#define glIsList_ARG_EXPAND GLuint list
#define glIsList_PACKED PACKED_GLboolean_GLuint
#define glIsList_INDEXED INDEXED_GLboolean_GLuint
#define glIsList_FORMAT FORMAT_GLboolean_GLuint
#define glIsQuery_INDEX 209
#define glIsQuery_RETURN GLboolean
#define glIsQuery_ARG_NAMES id
#define glIsQuery_ARG_EXPAND GLuint id
#define glIsQuery_PACKED PACKED_GLboolean_GLuint
#define glIsQuery_INDEXED INDEXED_GLboolean_GLuint
#define glIsQuery_FORMAT FORMAT_GLboolean_GLuint
#define glIsTexture_INDEX 210
#define glIsTexture_RETURN GLboolean
#define glIsTexture_ARG_NAMES texture
#define glIsTexture_ARG_EXPAND GLuint texture
#define glIsTexture_PACKED PACKED_GLboolean_GLuint
#define glIsTexture_INDEXED INDEXED_GLboolean_GLuint
#define glIsTexture_FORMAT FORMAT_GLboolean_GLuint
#define glLightModelf_INDEX 211
#define glLightModelf_RETURN void
#define glLightModelf_ARG_NAMES pname, param
#define glLightModelf_ARG_EXPAND GLenum pname, GLfloat param
#define glLightModelf_PACKED PACKED_void_GLenum_GLfloat
#define glLightModelf_INDEXED INDEXED_void_GLenum_GLfloat
#define glLightModelf_FORMAT FORMAT_void_GLenum_GLfloat
#define glLightModelfv_INDEX 212
#define glLightModelfv_RETURN void
#define glLightModelfv_ARG_NAMES pname, params
#define glLightModelfv_ARG_EXPAND GLenum pname, const GLfloat * params
#define glLightModelfv_PACKED PACKED_void_GLenum_const_GLfloat___GENPT__
#define glLightModelfv_INDEXED INDEXED_void_GLenum_const_GLfloat___GENPT__
#define glLightModelfv_FORMAT FORMAT_void_GLenum_const_GLfloat___GENPT__
#define glLightModeli_INDEX 213
#define glLightModeli_RETURN void
#define glLightModeli_ARG_NAMES pname, param
#define glLightModeli_ARG_EXPAND GLenum pname, GLint param
#define glLightModeli_PACKED PACKED_void_GLenum_GLint
#define glLightModeli_INDEXED INDEXED_void_GLenum_GLint
#define glLightModeli_FORMAT FORMAT_void_GLenum_GLint
#define glLightModeliv_INDEX 214
#define glLightModeliv_RETURN void
#define glLightModeliv_ARG_NAMES pname, params
#define glLightModeliv_ARG_EXPAND GLenum pname, const GLint * params
#define glLightModeliv_PACKED PACKED_void_GLenum_const_GLint___GENPT__
#define glLightModeliv_INDEXED INDEXED_void_GLenum_const_GLint___GENPT__
#define glLightModeliv_FORMAT FORMAT_void_GLenum_const_GLint___GENPT__
#define glLightf_INDEX 215
#define glLightf_RETURN void
#define glLightf_ARG_NAMES light, pname, param
#define glLightf_ARG_EXPAND GLenum light, GLenum pname, GLfloat param
#define glLightf_PACKED PACKED_void_GLenum_GLenum_GLfloat
#define glLightf_INDEXED INDEXED_void_GLenum_GLenum_GLfloat
#define glLightf_FORMAT FORMAT_void_GLenum_GLenum_GLfloat
#define glLightfv_INDEX 216
#define glLightfv_RETURN void
#define glLightfv_ARG_NAMES light, pname, params
#define glLightfv_ARG_EXPAND GLenum light, GLenum pname, const GLfloat * params
#define glLightfv_PACKED PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glLightfv_INDEXED INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glLightfv_FORMAT FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glLighti_INDEX 217
#define glLighti_RETURN void
#define glLighti_ARG_NAMES light, pname, param
#define glLighti_ARG_EXPAND GLenum light, GLenum pname, GLint param
#define glLighti_PACKED PACKED_void_GLenum_GLenum_GLint
#define glLighti_INDEXED INDEXED_void_GLenum_GLenum_GLint
#define glLighti_FORMAT FORMAT_void_GLenum_GLenum_GLint
#define glLightiv_INDEX 218
#define glLightiv_RETURN void
#define glLightiv_ARG_NAMES light, pname, params
#define glLightiv_ARG_EXPAND GLenum light, GLenum pname, const GLint * params
#define glLightiv_PACKED PACKED_void_GLenum_GLenum_const_GLint___GENPT__
#define glLightiv_INDEXED INDEXED_void_GLenum_GLenum_const_GLint___GENPT__
#define glLightiv_FORMAT FORMAT_void_GLenum_GLenum_const_GLint___GENPT__
#define glLineStipple_INDEX 219
#define glLineStipple_RETURN void
#define glLineStipple_ARG_NAMES factor, pattern
#define glLineStipple_ARG_EXPAND GLint factor, GLushort pattern
#define glLineStipple_PACKED PACKED_void_GLint_GLushort
#define glLineStipple_INDEXED INDEXED_void_GLint_GLushort
#define glLineStipple_FORMAT FORMAT_void_GLint_GLushort
#define glLineWidth_INDEX 220
#define glLineWidth_RETURN void
#define glLineWidth_ARG_NAMES width
#define glLineWidth_ARG_EXPAND GLfloat width
#define glLineWidth_PACKED PACKED_void_GLfloat
#define glLineWidth_INDEXED INDEXED_void_GLfloat
#define glLineWidth_FORMAT FORMAT_void_GLfloat
#define glListBase_INDEX 221
#define glListBase_RETURN void
#define glListBase_ARG_NAMES base
#define glListBase_ARG_EXPAND GLuint base
#define glListBase_PACKED PACKED_void_GLuint
#define glListBase_INDEXED INDEXED_void_GLuint
#define glListBase_FORMAT FORMAT_void_GLuint
#define glLoadIdentity_INDEX 222
#define glLoadIdentity_RETURN void
#define glLoadIdentity_ARG_NAMES 
#define glLoadIdentity_ARG_EXPAND 
#define glLoadIdentity_PACKED PACKED_void
#define glLoadIdentity_INDEXED INDEXED_void
#define glLoadIdentity_FORMAT FORMAT_void
#define glLoadMatrixd_INDEX 223
#define glLoadMatrixd_RETURN void
#define glLoadMatrixd_ARG_NAMES m
#define glLoadMatrixd_ARG_EXPAND const GLdouble * m
#define glLoadMatrixd_PACKED PACKED_void_const_GLdouble___GENPT__
#define glLoadMatrixd_INDEXED INDEXED_void_const_GLdouble___GENPT__
#define glLoadMatrixd_FORMAT FORMAT_void_const_GLdouble___GENPT__
#define glLoadMatrixf_INDEX 224
#define glLoadMatrixf_RETURN void
#define glLoadMatrixf_ARG_NAMES m
#define glLoadMatrixf_ARG_EXPAND const GLfloat * m
#define glLoadMatrixf_PACKED PACKED_void_const_GLfloat___GENPT__
#define glLoadMatrixf_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glLoadMatrixf_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glLoadName_INDEX 225
#define glLoadName_RETURN void
#define glLoadName_ARG_NAMES name
#define glLoadName_ARG_EXPAND GLuint name
#define glLoadName_PACKED PACKED_void_GLuint
#define glLoadName_INDEXED INDEXED_void_GLuint
#define glLoadName_FORMAT FORMAT_void_GLuint
#define glLoadTransposeMatrixd_INDEX 226
#define glLoadTransposeMatrixd_RETURN void
#define glLoadTransposeMatrixd_ARG_NAMES m
#define glLoadTransposeMatrixd_ARG_EXPAND const GLdouble * m
#define glLoadTransposeMatrixd_PACKED PACKED_void_const_GLdouble___GENPT__
#define glLoadTransposeMatrixd_INDEXED INDEXED_void_const_GLdouble___GENPT__
#define glLoadTransposeMatrixd_FORMAT FORMAT_void_const_GLdouble___GENPT__
#define glLoadTransposeMatrixf_INDEX 227
#define glLoadTransposeMatrixf_RETURN void
#define glLoadTransposeMatrixf_ARG_NAMES m
#define glLoadTransposeMatrixf_ARG_EXPAND const GLfloat * m
#define glLoadTransposeMatrixf_PACKED PACKED_void_const_GLfloat___GENPT__
#define glLoadTransposeMatrixf_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glLoadTransposeMatrixf_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glLogicOp_INDEX 228
#define glLogicOp_RETURN void
#define glLogicOp_ARG_NAMES opcode
#define glLogicOp_ARG_EXPAND GLenum opcode
#define glLogicOp_PACKED PACKED_void_GLenum
#define glLogicOp_INDEXED INDEXED_void_GLenum
#define glLogicOp_FORMAT FORMAT_void_GLenum
#define glMap1d_INDEX 229
#define glMap1d_RETURN void
#define glMap1d_ARG_NAMES target, u1, u2, stride, order, points
#define glMap1d_ARG_EXPAND GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble * points
#define glMap1d_PACKED PACKED_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__
#define glMap1d_INDEXED INDEXED_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__
#define glMap1d_FORMAT FORMAT_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__
#define glMap1f_INDEX 230
#define glMap1f_RETURN void
#define glMap1f_ARG_NAMES target, u1, u2, stride, order, points
#define glMap1f_ARG_EXPAND GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat * points
#define glMap1f_PACKED PACKED_void_GLenum_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__
#define glMap1f_INDEXED INDEXED_void_GLenum_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__
#define glMap1f_FORMAT FORMAT_void_GLenum_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__
#define glMap2d_INDEX 231
#define glMap2d_RETURN void
#define glMap2d_ARG_NAMES target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points
#define glMap2d_ARG_EXPAND GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble * points
#define glMap2d_PACKED PACKED_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__
#define glMap2d_INDEXED INDEXED_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__
#define glMap2d_FORMAT FORMAT_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__
#define glMap2f_INDEX 232
#define glMap2f_RETURN void
#define glMap2f_ARG_NAMES target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points
#define glMap2f_ARG_EXPAND GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat * points
#define glMap2f_PACKED PACKED_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__
#define glMap2f_INDEXED INDEXED_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__
#define glMap2f_FORMAT FORMAT_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__
#define glMapBuffer_INDEX 233
#define glMapBuffer_RETURN GLvoid *
#define glMapBuffer_ARG_NAMES target, access
#define glMapBuffer_ARG_EXPAND GLenum target, GLenum access
#define glMapBuffer_PACKED PACKED_GLvoid___GENPT___GLenum_GLenum
#define glMapBuffer_INDEXED INDEXED_GLvoid___GENPT___GLenum_GLenum
#define glMapBuffer_FORMAT FORMAT_GLvoid___GENPT___GLenum_GLenum
#define glMapGrid1d_INDEX 234
#define glMapGrid1d_RETURN void
#define glMapGrid1d_ARG_NAMES un, u1, u2
#define glMapGrid1d_ARG_EXPAND GLint un, GLdouble u1, GLdouble u2
#define glMapGrid1d_PACKED PACKED_void_GLint_GLdouble_GLdouble
#define glMapGrid1d_INDEXED INDEXED_void_GLint_GLdouble_GLdouble
#define glMapGrid1d_FORMAT FORMAT_void_GLint_GLdouble_GLdouble
#define glMapGrid1f_INDEX 235
#define glMapGrid1f_RETURN void
#define glMapGrid1f_ARG_NAMES un, u1, u2
#define glMapGrid1f_ARG_EXPAND GLint un, GLfloat u1, GLfloat u2
#define glMapGrid1f_PACKED PACKED_void_GLint_GLfloat_GLfloat
#define glMapGrid1f_INDEXED INDEXED_void_GLint_GLfloat_GLfloat
#define glMapGrid1f_FORMAT FORMAT_void_GLint_GLfloat_GLfloat
#define glMapGrid2d_INDEX 236
#define glMapGrid2d_RETURN void
#define glMapGrid2d_ARG_NAMES un, u1, u2, vn, v1, v2
#define glMapGrid2d_ARG_EXPAND GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2
#define glMapGrid2d_PACKED PACKED_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble
#define glMapGrid2d_INDEXED INDEXED_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble
#define glMapGrid2d_FORMAT FORMAT_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble
#define glMapGrid2f_INDEX 237
#define glMapGrid2f_RETURN void
#define glMapGrid2f_ARG_NAMES un, u1, u2, vn, v1, v2
#define glMapGrid2f_ARG_EXPAND GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2
#define glMapGrid2f_PACKED PACKED_void_GLint_GLfloat_GLfloat_GLint_GLfloat_GLfloat
#define glMapGrid2f_INDEXED INDEXED_void_GLint_GLfloat_GLfloat_GLint_GLfloat_GLfloat
#define glMapGrid2f_FORMAT FORMAT_void_GLint_GLfloat_GLfloat_GLint_GLfloat_GLfloat
#define glMaterialf_INDEX 238
#define glMaterialf_RETURN void
#define glMaterialf_ARG_NAMES face, pname, param
#define glMaterialf_ARG_EXPAND GLenum face, GLenum pname, GLfloat param
#define glMaterialf_PACKED PACKED_void_GLenum_GLenum_GLfloat
#define glMaterialf_INDEXED INDEXED_void_GLenum_GLenum_GLfloat
#define glMaterialf_FORMAT FORMAT_void_GLenum_GLenum_GLfloat
#define glMaterialfv_INDEX 239
#define glMaterialfv_RETURN void
#define glMaterialfv_ARG_NAMES face, pname, params
#define glMaterialfv_ARG_EXPAND GLenum face, GLenum pname, const GLfloat * params
#define glMaterialfv_PACKED PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glMaterialfv_INDEXED INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glMaterialfv_FORMAT FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glMateriali_INDEX 240
#define glMateriali_RETURN void
#define glMateriali_ARG_NAMES face, pname, param
#define glMateriali_ARG_EXPAND GLenum face, GLenum pname, GLint param
#define glMateriali_PACKED PACKED_void_GLenum_GLenum_GLint
#define glMateriali_INDEXED INDEXED_void_GLenum_GLenum_GLint
#define glMateriali_FORMAT FORMAT_void_GLenum_GLenum_GLint
#define glMaterialiv_INDEX 241
#define glMaterialiv_RETURN void
#define glMaterialiv_ARG_NAMES face, pname, params
#define glMaterialiv_ARG_EXPAND GLenum face, GLenum pname, const GLint * params
#define glMaterialiv_PACKED PACKED_void_GLenum_GLenum_const_GLint___GENPT__
#define glMaterialiv_INDEXED INDEXED_void_GLenum_GLenum_const_GLint___GENPT__
#define glMaterialiv_FORMAT FORMAT_void_GLenum_GLenum_const_GLint___GENPT__
#define glMatrixMode_INDEX 242
#define glMatrixMode_RETURN void
#define glMatrixMode_ARG_NAMES mode
#define glMatrixMode_ARG_EXPAND GLenum mode
#define glMatrixMode_PACKED PACKED_void_GLenum
#define glMatrixMode_INDEXED INDEXED_void_GLenum
#define glMatrixMode_FORMAT FORMAT_void_GLenum
#define glMinmax_INDEX 243
#define glMinmax_RETURN void
#define glMinmax_ARG_NAMES target, internalformat, sink
#define glMinmax_ARG_EXPAND GLenum target, GLenum internalformat, GLboolean sink
#define glMinmax_PACKED PACKED_void_GLenum_GLenum_GLboolean
#define glMinmax_INDEXED INDEXED_void_GLenum_GLenum_GLboolean
#define glMinmax_FORMAT FORMAT_void_GLenum_GLenum_GLboolean
#define glMultMatrixd_INDEX 244
#define glMultMatrixd_RETURN void
#define glMultMatrixd_ARG_NAMES m
#define glMultMatrixd_ARG_EXPAND const GLdouble * m
#define glMultMatrixd_PACKED PACKED_void_const_GLdouble___GENPT__
#define glMultMatrixd_INDEXED INDEXED_void_const_GLdouble___GENPT__
#define glMultMatrixd_FORMAT FORMAT_void_const_GLdouble___GENPT__
#define glMultMatrixf_INDEX 245
#define glMultMatrixf_RETURN void
#define glMultMatrixf_ARG_NAMES m
#define glMultMatrixf_ARG_EXPAND const GLfloat * m
#define glMultMatrixf_PACKED PACKED_void_const_GLfloat___GENPT__
#define glMultMatrixf_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glMultMatrixf_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glMultTransposeMatrixd_INDEX 246
#define glMultTransposeMatrixd_RETURN void
#define glMultTransposeMatrixd_ARG_NAMES m
#define glMultTransposeMatrixd_ARG_EXPAND const GLdouble * m
#define glMultTransposeMatrixd_PACKED PACKED_void_const_GLdouble___GENPT__
#define glMultTransposeMatrixd_INDEXED INDEXED_void_const_GLdouble___GENPT__
#define glMultTransposeMatrixd_FORMAT FORMAT_void_const_GLdouble___GENPT__
#define glMultTransposeMatrixf_INDEX 247
#define glMultTransposeMatrixf_RETURN void
#define glMultTransposeMatrixf_ARG_NAMES m
#define glMultTransposeMatrixf_ARG_EXPAND const GLfloat * m
#define glMultTransposeMatrixf_PACKED PACKED_void_const_GLfloat___GENPT__
#define glMultTransposeMatrixf_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glMultTransposeMatrixf_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glMultiDrawArrays_INDEX 248
#define glMultiDrawArrays_RETURN void
#define glMultiDrawArrays_ARG_NAMES mode, first, count, drawcount
#define glMultiDrawArrays_ARG_EXPAND GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount
#define glMultiDrawArrays_PACKED PACKED_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei
#define glMultiDrawArrays_INDEXED INDEXED_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei
#define glMultiDrawArrays_FORMAT FORMAT_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei
#define glMultiDrawElements_INDEX 249
#define glMultiDrawElements_RETURN void
#define glMultiDrawElements_ARG_NAMES mode, count, type, indices, drawcount
#define glMultiDrawElements_ARG_EXPAND GLenum mode, const GLsizei * count, GLenum type, GLvoid*const * indices, GLsizei drawcount
#define glMultiDrawElements_PACKED PACKED_void_GLenum_const_GLsizei___GENPT___GLenum_GLvoid__GENPT__const___GENPT___GLsizei
#define glMultiDrawElements_INDEXED INDEXED_void_GLenum_const_GLsizei___GENPT___GLenum_GLvoid__GENPT__const___GENPT___GLsizei
#define glMultiDrawElements_FORMAT FORMAT_void_GLenum_const_GLsizei___GENPT___GLenum_GLvoid__GENPT__const___GENPT___GLsizei
#define glMultiTexCoord1d_INDEX 250
#define glMultiTexCoord1d_RETURN void
#define glMultiTexCoord1d_ARG_NAMES target, s
#define glMultiTexCoord1d_ARG_EXPAND GLenum target, GLdouble s
#define glMultiTexCoord1d_PACKED PACKED_void_GLenum_GLdouble
#define glMultiTexCoord1d_INDEXED INDEXED_void_GLenum_GLdouble
#define glMultiTexCoord1d_FORMAT FORMAT_void_GLenum_GLdouble
#define glMultiTexCoord1dv_INDEX 251
#define glMultiTexCoord1dv_RETURN void
#define glMultiTexCoord1dv_ARG_NAMES target, v
#define glMultiTexCoord1dv_ARG_EXPAND GLenum target, const GLdouble * v
#define glMultiTexCoord1dv_PACKED PACKED_void_GLenum_const_GLdouble___GENPT__
#define glMultiTexCoord1dv_INDEXED INDEXED_void_GLenum_const_GLdouble___GENPT__
#define glMultiTexCoord1dv_FORMAT FORMAT_void_GLenum_const_GLdouble___GENPT__
#define glMultiTexCoord1f_INDEX 252
#define glMultiTexCoord1f_RETURN void
#define glMultiTexCoord1f_ARG_NAMES target, s
#define glMultiTexCoord1f_ARG_EXPAND GLenum target, GLfloat s
#define glMultiTexCoord1f_PACKED PACKED_void_GLenum_GLfloat
#define glMultiTexCoord1f_INDEXED INDEXED_void_GLenum_GLfloat
#define glMultiTexCoord1f_FORMAT FORMAT_void_GLenum_GLfloat
#define glMultiTexCoord1fv_INDEX 253
#define glMultiTexCoord1fv_RETURN void
#define glMultiTexCoord1fv_ARG_NAMES target, v
#define glMultiTexCoord1fv_ARG_EXPAND GLenum target, const GLfloat * v
#define glMultiTexCoord1fv_PACKED PACKED_void_GLenum_const_GLfloat___GENPT__
#define glMultiTexCoord1fv_INDEXED INDEXED_void_GLenum_const_GLfloat___GENPT__
#define glMultiTexCoord1fv_FORMAT FORMAT_void_GLenum_const_GLfloat___GENPT__
#define glMultiTexCoord1i_INDEX 254
#define glMultiTexCoord1i_RETURN void
#define glMultiTexCoord1i_ARG_NAMES target, s
#define glMultiTexCoord1i_ARG_EXPAND GLenum target, GLint s
#define glMultiTexCoord1i_PACKED PACKED_void_GLenum_GLint
#define glMultiTexCoord1i_INDEXED INDEXED_void_GLenum_GLint
#define glMultiTexCoord1i_FORMAT FORMAT_void_GLenum_GLint
#define glMultiTexCoord1iv_INDEX 255
#define glMultiTexCoord1iv_RETURN void
#define glMultiTexCoord1iv_ARG_NAMES target, v
#define glMultiTexCoord1iv_ARG_EXPAND GLenum target, const GLint * v
#define glMultiTexCoord1iv_PACKED PACKED_void_GLenum_const_GLint___GENPT__
#define glMultiTexCoord1iv_INDEXED INDEXED_void_GLenum_const_GLint___GENPT__
#define glMultiTexCoord1iv_FORMAT FORMAT_void_GLenum_const_GLint___GENPT__
#define glMultiTexCoord1s_INDEX 256
#define glMultiTexCoord1s_RETURN void
#define glMultiTexCoord1s_ARG_NAMES target, s
#define glMultiTexCoord1s_ARG_EXPAND GLenum target, GLshort s
#define glMultiTexCoord1s_PACKED PACKED_void_GLenum_GLshort
#define glMultiTexCoord1s_INDEXED INDEXED_void_GLenum_GLshort
#define glMultiTexCoord1s_FORMAT FORMAT_void_GLenum_GLshort
#define glMultiTexCoord1sv_INDEX 257
#define glMultiTexCoord1sv_RETURN void
#define glMultiTexCoord1sv_ARG_NAMES target, v
#define glMultiTexCoord1sv_ARG_EXPAND GLenum target, const GLshort * v
#define glMultiTexCoord1sv_PACKED PACKED_void_GLenum_const_GLshort___GENPT__
#define glMultiTexCoord1sv_INDEXED INDEXED_void_GLenum_const_GLshort___GENPT__
#define glMultiTexCoord1sv_FORMAT FORMAT_void_GLenum_const_GLshort___GENPT__
#define glMultiTexCoord2d_INDEX 258
#define glMultiTexCoord2d_RETURN void
#define glMultiTexCoord2d_ARG_NAMES target, s, t
#define glMultiTexCoord2d_ARG_EXPAND GLenum target, GLdouble s, GLdouble t
#define glMultiTexCoord2d_PACKED PACKED_void_GLenum_GLdouble_GLdouble
#define glMultiTexCoord2d_INDEXED INDEXED_void_GLenum_GLdouble_GLdouble
#define glMultiTexCoord2d_FORMAT FORMAT_void_GLenum_GLdouble_GLdouble
#define glMultiTexCoord2dv_INDEX 259
#define glMultiTexCoord2dv_RETURN void
#define glMultiTexCoord2dv_ARG_NAMES target, v
#define glMultiTexCoord2dv_ARG_EXPAND GLenum target, const GLdouble * v
#define glMultiTexCoord2dv_PACKED PACKED_void_GLenum_const_GLdouble___GENPT__
#define glMultiTexCoord2dv_INDEXED INDEXED_void_GLenum_const_GLdouble___GENPT__
#define glMultiTexCoord2dv_FORMAT FORMAT_void_GLenum_const_GLdouble___GENPT__
#define glMultiTexCoord2f_INDEX 260
#define glMultiTexCoord2f_RETURN void
#define glMultiTexCoord2f_ARG_NAMES target, s, t
#define glMultiTexCoord2f_ARG_EXPAND GLenum target, GLfloat s, GLfloat t
#define glMultiTexCoord2f_PACKED PACKED_void_GLenum_GLfloat_GLfloat
#define glMultiTexCoord2f_INDEXED INDEXED_void_GLenum_GLfloat_GLfloat
#define glMultiTexCoord2f_FORMAT FORMAT_void_GLenum_GLfloat_GLfloat
#define glMultiTexCoord2fv_INDEX 261
#define glMultiTexCoord2fv_RETURN void
#define glMultiTexCoord2fv_ARG_NAMES target, v
#define glMultiTexCoord2fv_ARG_EXPAND GLenum target, const GLfloat * v
#define glMultiTexCoord2fv_PACKED PACKED_void_GLenum_const_GLfloat___GENPT__
#define glMultiTexCoord2fv_INDEXED INDEXED_void_GLenum_const_GLfloat___GENPT__
#define glMultiTexCoord2fv_FORMAT FORMAT_void_GLenum_const_GLfloat___GENPT__
#define glMultiTexCoord2i_INDEX 262
#define glMultiTexCoord2i_RETURN void
#define glMultiTexCoord2i_ARG_NAMES target, s, t
#define glMultiTexCoord2i_ARG_EXPAND GLenum target, GLint s, GLint t
#define glMultiTexCoord2i_PACKED PACKED_void_GLenum_GLint_GLint
#define glMultiTexCoord2i_INDEXED INDEXED_void_GLenum_GLint_GLint
#define glMultiTexCoord2i_FORMAT FORMAT_void_GLenum_GLint_GLint
#define glMultiTexCoord2iv_INDEX 263
#define glMultiTexCoord2iv_RETURN void
#define glMultiTexCoord2iv_ARG_NAMES target, v
#define glMultiTexCoord2iv_ARG_EXPAND GLenum target, const GLint * v
#define glMultiTexCoord2iv_PACKED PACKED_void_GLenum_const_GLint___GENPT__
#define glMultiTexCoord2iv_INDEXED INDEXED_void_GLenum_const_GLint___GENPT__
#define glMultiTexCoord2iv_FORMAT FORMAT_void_GLenum_const_GLint___GENPT__
#define glMultiTexCoord2s_INDEX 264
#define glMultiTexCoord2s_RETURN void
#define glMultiTexCoord2s_ARG_NAMES target, s, t
#define glMultiTexCoord2s_ARG_EXPAND GLenum target, GLshort s, GLshort t
#define glMultiTexCoord2s_PACKED PACKED_void_GLenum_GLshort_GLshort
#define glMultiTexCoord2s_INDEXED INDEXED_void_GLenum_GLshort_GLshort
#define glMultiTexCoord2s_FORMAT FORMAT_void_GLenum_GLshort_GLshort
#define glMultiTexCoord2sv_INDEX 265
#define glMultiTexCoord2sv_RETURN void
#define glMultiTexCoord2sv_ARG_NAMES target, v
#define glMultiTexCoord2sv_ARG_EXPAND GLenum target, const GLshort * v
#define glMultiTexCoord2sv_PACKED PACKED_void_GLenum_const_GLshort___GENPT__
#define glMultiTexCoord2sv_INDEXED INDEXED_void_GLenum_const_GLshort___GENPT__
#define glMultiTexCoord2sv_FORMAT FORMAT_void_GLenum_const_GLshort___GENPT__
#define glMultiTexCoord3d_INDEX 266
#define glMultiTexCoord3d_RETURN void
#define glMultiTexCoord3d_ARG_NAMES target, s, t, r
#define glMultiTexCoord3d_ARG_EXPAND GLenum target, GLdouble s, GLdouble t, GLdouble r
#define glMultiTexCoord3d_PACKED PACKED_void_GLenum_GLdouble_GLdouble_GLdouble
#define glMultiTexCoord3d_INDEXED INDEXED_void_GLenum_GLdouble_GLdouble_GLdouble
#define glMultiTexCoord3d_FORMAT FORMAT_void_GLenum_GLdouble_GLdouble_GLdouble
#define glMultiTexCoord3dv_INDEX 267
#define glMultiTexCoord3dv_RETURN void
#define glMultiTexCoord3dv_ARG_NAMES target, v
#define glMultiTexCoord3dv_ARG_EXPAND GLenum target, const GLdouble * v
#define glMultiTexCoord3dv_PACKED PACKED_void_GLenum_const_GLdouble___GENPT__
#define glMultiTexCoord3dv_INDEXED INDEXED_void_GLenum_const_GLdouble___GENPT__
#define glMultiTexCoord3dv_FORMAT FORMAT_void_GLenum_const_GLdouble___GENPT__
#define glMultiTexCoord3f_INDEX 268
#define glMultiTexCoord3f_RETURN void
#define glMultiTexCoord3f_ARG_NAMES target, s, t, r
#define glMultiTexCoord3f_ARG_EXPAND GLenum target, GLfloat s, GLfloat t, GLfloat r
#define glMultiTexCoord3f_PACKED PACKED_void_GLenum_GLfloat_GLfloat_GLfloat
#define glMultiTexCoord3f_INDEXED INDEXED_void_GLenum_GLfloat_GLfloat_GLfloat
#define glMultiTexCoord3f_FORMAT FORMAT_void_GLenum_GLfloat_GLfloat_GLfloat
#define glMultiTexCoord3fv_INDEX 269
#define glMultiTexCoord3fv_RETURN void
#define glMultiTexCoord3fv_ARG_NAMES target, v
#define glMultiTexCoord3fv_ARG_EXPAND GLenum target, const GLfloat * v
#define glMultiTexCoord3fv_PACKED PACKED_void_GLenum_const_GLfloat___GENPT__
#define glMultiTexCoord3fv_INDEXED INDEXED_void_GLenum_const_GLfloat___GENPT__
#define glMultiTexCoord3fv_FORMAT FORMAT_void_GLenum_const_GLfloat___GENPT__
#define glMultiTexCoord3i_INDEX 270
#define glMultiTexCoord3i_RETURN void
#define glMultiTexCoord3i_ARG_NAMES target, s, t, r
#define glMultiTexCoord3i_ARG_EXPAND GLenum target, GLint s, GLint t, GLint r
#define glMultiTexCoord3i_PACKED PACKED_void_GLenum_GLint_GLint_GLint
#define glMultiTexCoord3i_INDEXED INDEXED_void_GLenum_GLint_GLint_GLint
#define glMultiTexCoord3i_FORMAT FORMAT_void_GLenum_GLint_GLint_GLint
#define glMultiTexCoord3iv_INDEX 271
#define glMultiTexCoord3iv_RETURN void
#define glMultiTexCoord3iv_ARG_NAMES target, v
#define glMultiTexCoord3iv_ARG_EXPAND GLenum target, const GLint * v
#define glMultiTexCoord3iv_PACKED PACKED_void_GLenum_const_GLint___GENPT__
#define glMultiTexCoord3iv_INDEXED INDEXED_void_GLenum_const_GLint___GENPT__
#define glMultiTexCoord3iv_FORMAT FORMAT_void_GLenum_const_GLint___GENPT__
#define glMultiTexCoord3s_INDEX 272
#define glMultiTexCoord3s_RETURN void
#define glMultiTexCoord3s_ARG_NAMES target, s, t, r
#define glMultiTexCoord3s_ARG_EXPAND GLenum target, GLshort s, GLshort t, GLshort r
#define glMultiTexCoord3s_PACKED PACKED_void_GLenum_GLshort_GLshort_GLshort
#define glMultiTexCoord3s_INDEXED INDEXED_void_GLenum_GLshort_GLshort_GLshort
#define glMultiTexCoord3s_FORMAT FORMAT_void_GLenum_GLshort_GLshort_GLshort
#define glMultiTexCoord3sv_INDEX 273
#define glMultiTexCoord3sv_RETURN void
#define glMultiTexCoord3sv_ARG_NAMES target, v
#define glMultiTexCoord3sv_ARG_EXPAND GLenum target, const GLshort * v
#define glMultiTexCoord3sv_PACKED PACKED_void_GLenum_const_GLshort___GENPT__
#define glMultiTexCoord3sv_INDEXED INDEXED_void_GLenum_const_GLshort___GENPT__
#define glMultiTexCoord3sv_FORMAT FORMAT_void_GLenum_const_GLshort___GENPT__
#define glMultiTexCoord4d_INDEX 274
#define glMultiTexCoord4d_RETURN void
#define glMultiTexCoord4d_ARG_NAMES target, s, t, r, q
#define glMultiTexCoord4d_ARG_EXPAND GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q
#define glMultiTexCoord4d_PACKED PACKED_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble
#define glMultiTexCoord4d_INDEXED INDEXED_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble
#define glMultiTexCoord4d_FORMAT FORMAT_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble
#define glMultiTexCoord4dv_INDEX 275
#define glMultiTexCoord4dv_RETURN void
#define glMultiTexCoord4dv_ARG_NAMES target, v
#define glMultiTexCoord4dv_ARG_EXPAND GLenum target, const GLdouble * v
#define glMultiTexCoord4dv_PACKED PACKED_void_GLenum_const_GLdouble___GENPT__
#define glMultiTexCoord4dv_INDEXED INDEXED_void_GLenum_const_GLdouble___GENPT__
#define glMultiTexCoord4dv_FORMAT FORMAT_void_GLenum_const_GLdouble___GENPT__
#define glMultiTexCoord4f_INDEX 276
#define glMultiTexCoord4f_RETURN void
#define glMultiTexCoord4f_ARG_NAMES target, s, t, r, q
#define glMultiTexCoord4f_ARG_EXPAND GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q
#define glMultiTexCoord4f_PACKED PACKED_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat
#define glMultiTexCoord4f_INDEXED INDEXED_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat
#define glMultiTexCoord4f_FORMAT FORMAT_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat
#define glMultiTexCoord4fv_INDEX 277
#define glMultiTexCoord4fv_RETURN void
#define glMultiTexCoord4fv_ARG_NAMES target, v
#define glMultiTexCoord4fv_ARG_EXPAND GLenum target, const GLfloat * v
#define glMultiTexCoord4fv_PACKED PACKED_void_GLenum_const_GLfloat___GENPT__
#define glMultiTexCoord4fv_INDEXED INDEXED_void_GLenum_const_GLfloat___GENPT__
#define glMultiTexCoord4fv_FORMAT FORMAT_void_GLenum_const_GLfloat___GENPT__
#define glMultiTexCoord4i_INDEX 278
#define glMultiTexCoord4i_RETURN void
#define glMultiTexCoord4i_ARG_NAMES target, s, t, r, q
#define glMultiTexCoord4i_ARG_EXPAND GLenum target, GLint s, GLint t, GLint r, GLint q
#define glMultiTexCoord4i_PACKED PACKED_void_GLenum_GLint_GLint_GLint_GLint
#define glMultiTexCoord4i_INDEXED INDEXED_void_GLenum_GLint_GLint_GLint_GLint
#define glMultiTexCoord4i_FORMAT FORMAT_void_GLenum_GLint_GLint_GLint_GLint
#define glMultiTexCoord4iv_INDEX 279
#define glMultiTexCoord4iv_RETURN void
#define glMultiTexCoord4iv_ARG_NAMES target, v
#define glMultiTexCoord4iv_ARG_EXPAND GLenum target, const GLint * v
#define glMultiTexCoord4iv_PACKED PACKED_void_GLenum_const_GLint___GENPT__
#define glMultiTexCoord4iv_INDEXED INDEXED_void_GLenum_const_GLint___GENPT__
#define glMultiTexCoord4iv_FORMAT FORMAT_void_GLenum_const_GLint___GENPT__
#define glMultiTexCoord4s_INDEX 280
#define glMultiTexCoord4s_RETURN void
#define glMultiTexCoord4s_ARG_NAMES target, s, t, r, q
#define glMultiTexCoord4s_ARG_EXPAND GLenum target, GLshort s, GLshort t, GLshort r, GLshort q
#define glMultiTexCoord4s_PACKED PACKED_void_GLenum_GLshort_GLshort_GLshort_GLshort
#define glMultiTexCoord4s_INDEXED INDEXED_void_GLenum_GLshort_GLshort_GLshort_GLshort
#define glMultiTexCoord4s_FORMAT FORMAT_void_GLenum_GLshort_GLshort_GLshort_GLshort
#define glMultiTexCoord4sv_INDEX 281
#define glMultiTexCoord4sv_RETURN void
#define glMultiTexCoord4sv_ARG_NAMES target, v
#define glMultiTexCoord4sv_ARG_EXPAND GLenum target, const GLshort * v
#define glMultiTexCoord4sv_PACKED PACKED_void_GLenum_const_GLshort___GENPT__
#define glMultiTexCoord4sv_INDEXED INDEXED_void_GLenum_const_GLshort___GENPT__
#define glMultiTexCoord4sv_FORMAT FORMAT_void_GLenum_const_GLshort___GENPT__
#define glNewList_INDEX 282
#define glNewList_RETURN void
#define glNewList_ARG_NAMES list, mode
#define glNewList_ARG_EXPAND GLuint list, GLenum mode
#define glNewList_PACKED PACKED_void_GLuint_GLenum
#define glNewList_INDEXED INDEXED_void_GLuint_GLenum
#define glNewList_FORMAT FORMAT_void_GLuint_GLenum
#define glNormal3b_INDEX 283
#define glNormal3b_RETURN void
#define glNormal3b_ARG_NAMES nx, ny, nz
#define glNormal3b_ARG_EXPAND GLbyte nx, GLbyte ny, GLbyte nz
#define glNormal3b_PACKED PACKED_void_GLbyte_GLbyte_GLbyte
#define glNormal3b_INDEXED INDEXED_void_GLbyte_GLbyte_GLbyte
#define glNormal3b_FORMAT FORMAT_void_GLbyte_GLbyte_GLbyte
#define glNormal3bv_INDEX 284
#define glNormal3bv_RETURN void
#define glNormal3bv_ARG_NAMES v
#define glNormal3bv_ARG_EXPAND const GLbyte * v
#define glNormal3bv_PACKED PACKED_void_const_GLbyte___GENPT__
#define glNormal3bv_INDEXED INDEXED_void_const_GLbyte___GENPT__
#define glNormal3bv_FORMAT FORMAT_void_const_GLbyte___GENPT__
#define glNormal3d_INDEX 285
#define glNormal3d_RETURN void
#define glNormal3d_ARG_NAMES nx, ny, nz
#define glNormal3d_ARG_EXPAND GLdouble nx, GLdouble ny, GLdouble nz
#define glNormal3d_PACKED PACKED_void_GLdouble_GLdouble_GLdouble
#define glNormal3d_INDEXED INDEXED_void_GLdouble_GLdouble_GLdouble
#define glNormal3d_FORMAT FORMAT_void_GLdouble_GLdouble_GLdouble
#define glNormal3dv_INDEX 286
#define glNormal3dv_RETURN void
#define glNormal3dv_ARG_NAMES v
#define glNormal3dv_ARG_EXPAND const GLdouble * v
#define glNormal3dv_PACKED PACKED_void_const_GLdouble___GENPT__
#define glNormal3dv_INDEXED INDEXED_void_const_GLdouble___GENPT__
#define glNormal3dv_FORMAT FORMAT_void_const_GLdouble___GENPT__
#define glNormal3f_INDEX 287
#define glNormal3f_RETURN void
#define glNormal3f_ARG_NAMES nx, ny, nz
#define glNormal3f_ARG_EXPAND GLfloat nx, GLfloat ny, GLfloat nz
#define glNormal3f_PACKED PACKED_void_GLfloat_GLfloat_GLfloat
#define glNormal3f_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat
#define glNormal3f_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat
#define glNormal3fv_INDEX 288
#define glNormal3fv_RETURN void
#define glNormal3fv_ARG_NAMES v
#define glNormal3fv_ARG_EXPAND const GLfloat * v
#define glNormal3fv_PACKED PACKED_void_const_GLfloat___GENPT__
#define glNormal3fv_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glNormal3fv_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glNormal3i_INDEX 289
#define glNormal3i_RETURN void
#define glNormal3i_ARG_NAMES nx, ny, nz
#define glNormal3i_ARG_EXPAND GLint nx, GLint ny, GLint nz
#define glNormal3i_PACKED PACKED_void_GLint_GLint_GLint
#define glNormal3i_INDEXED INDEXED_void_GLint_GLint_GLint
#define glNormal3i_FORMAT FORMAT_void_GLint_GLint_GLint
#define glNormal3iv_INDEX 290
#define glNormal3iv_RETURN void
#define glNormal3iv_ARG_NAMES v
#define glNormal3iv_ARG_EXPAND const GLint * v
#define glNormal3iv_PACKED PACKED_void_const_GLint___GENPT__
#define glNormal3iv_INDEXED INDEXED_void_const_GLint___GENPT__
#define glNormal3iv_FORMAT FORMAT_void_const_GLint___GENPT__
#define glNormal3s_INDEX 291
#define glNormal3s_RETURN void
#define glNormal3s_ARG_NAMES nx, ny, nz
#define glNormal3s_ARG_EXPAND GLshort nx, GLshort ny, GLshort nz
#define glNormal3s_PACKED PACKED_void_GLshort_GLshort_GLshort
#define glNormal3s_INDEXED INDEXED_void_GLshort_GLshort_GLshort
#define glNormal3s_FORMAT FORMAT_void_GLshort_GLshort_GLshort
#define glNormal3sv_INDEX 292
#define glNormal3sv_RETURN void
#define glNormal3sv_ARG_NAMES v
#define glNormal3sv_ARG_EXPAND const GLshort * v
#define glNormal3sv_PACKED PACKED_void_const_GLshort___GENPT__
#define glNormal3sv_INDEXED INDEXED_void_const_GLshort___GENPT__
#define glNormal3sv_FORMAT FORMAT_void_const_GLshort___GENPT__
#define glNormalPointer_INDEX 293
#define glNormalPointer_RETURN void
#define glNormalPointer_ARG_NAMES type, stride, pointer
#define glNormalPointer_ARG_EXPAND GLenum type, GLsizei stride, const GLvoid * pointer
#define glNormalPointer_PACKED PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__
#define glNormalPointer_INDEXED INDEXED_void_GLenum_GLsizei_const_GLvoid___GENPT__
#define glNormalPointer_FORMAT FORMAT_void_GLenum_GLsizei_const_GLvoid___GENPT__
#define glOrtho_INDEX 294
#define glOrtho_RETURN void
#define glOrtho_ARG_NAMES left, right, bottom, top, zNear, zFar
#define glOrtho_ARG_EXPAND GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar
#define glOrtho_PACKED PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble
#define glOrtho_INDEXED INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble
#define glOrtho_FORMAT FORMAT_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble
#define glPassThrough_INDEX 295
#define glPassThrough_RETURN void
#define glPassThrough_ARG_NAMES token
#define glPassThrough_ARG_EXPAND GLfloat token
#define glPassThrough_PACKED PACKED_void_GLfloat
#define glPassThrough_INDEXED INDEXED_void_GLfloat
#define glPassThrough_FORMAT FORMAT_void_GLfloat
#define glPixelMapfv_INDEX 296
#define glPixelMapfv_RETURN void
#define glPixelMapfv_ARG_NAMES map, mapsize, values
#define glPixelMapfv_ARG_EXPAND GLenum map, GLsizei mapsize, const GLfloat * values
#define glPixelMapfv_PACKED PACKED_void_GLenum_GLsizei_const_GLfloat___GENPT__
#define glPixelMapfv_INDEXED INDEXED_void_GLenum_GLsizei_const_GLfloat___GENPT__
#define glPixelMapfv_FORMAT FORMAT_void_GLenum_GLsizei_const_GLfloat___GENPT__
#define glPixelMapuiv_INDEX 297
#define glPixelMapuiv_RETURN void
#define glPixelMapuiv_ARG_NAMES map, mapsize, values
#define glPixelMapuiv_ARG_EXPAND GLenum map, GLsizei mapsize, const GLuint * values
#define glPixelMapuiv_PACKED PACKED_void_GLenum_GLsizei_const_GLuint___GENPT__
#define glPixelMapuiv_INDEXED INDEXED_void_GLenum_GLsizei_const_GLuint___GENPT__
#define glPixelMapuiv_FORMAT FORMAT_void_GLenum_GLsizei_const_GLuint___GENPT__
#define glPixelMapusv_INDEX 298
#define glPixelMapusv_RETURN void
#define glPixelMapusv_ARG_NAMES map, mapsize, values
#define glPixelMapusv_ARG_EXPAND GLenum map, GLsizei mapsize, const GLushort * values
#define glPixelMapusv_PACKED PACKED_void_GLenum_GLsizei_const_GLushort___GENPT__
#define glPixelMapusv_INDEXED INDEXED_void_GLenum_GLsizei_const_GLushort___GENPT__
#define glPixelMapusv_FORMAT FORMAT_void_GLenum_GLsizei_const_GLushort___GENPT__
#define glPixelStoref_INDEX 299
#define glPixelStoref_RETURN void
#define glPixelStoref_ARG_NAMES pname, param
#define glPixelStoref_ARG_EXPAND GLenum pname, GLfloat param
#define glPixelStoref_PACKED PACKED_void_GLenum_GLfloat
#define glPixelStoref_INDEXED INDEXED_void_GLenum_GLfloat
#define glPixelStoref_FORMAT FORMAT_void_GLenum_GLfloat
#define glPixelStorei_INDEX 300
#define glPixelStorei_RETURN void
#define glPixelStorei_ARG_NAMES pname, param
#define glPixelStorei_ARG_EXPAND GLenum pname, GLint param
#define glPixelStorei_PACKED PACKED_void_GLenum_GLint
#define glPixelStorei_INDEXED INDEXED_void_GLenum_GLint
#define glPixelStorei_FORMAT FORMAT_void_GLenum_GLint
#define glPixelTransferf_INDEX 301
#define glPixelTransferf_RETURN void
#define glPixelTransferf_ARG_NAMES pname, param
#define glPixelTransferf_ARG_EXPAND GLenum pname, GLfloat param
#define glPixelTransferf_PACKED PACKED_void_GLenum_GLfloat
#define glPixelTransferf_INDEXED INDEXED_void_GLenum_GLfloat
#define glPixelTransferf_FORMAT FORMAT_void_GLenum_GLfloat
#define glPixelTransferi_INDEX 302
#define glPixelTransferi_RETURN void
#define glPixelTransferi_ARG_NAMES pname, param
#define glPixelTransferi_ARG_EXPAND GLenum pname, GLint param
#define glPixelTransferi_PACKED PACKED_void_GLenum_GLint
#define glPixelTransferi_INDEXED INDEXED_void_GLenum_GLint
#define glPixelTransferi_FORMAT FORMAT_void_GLenum_GLint
#define glPixelZoom_INDEX 303
#define glPixelZoom_RETURN void
#define glPixelZoom_ARG_NAMES xfactor, yfactor
#define glPixelZoom_ARG_EXPAND GLfloat xfactor, GLfloat yfactor
#define glPixelZoom_PACKED PACKED_void_GLfloat_GLfloat
#define glPixelZoom_INDEXED INDEXED_void_GLfloat_GLfloat
#define glPixelZoom_FORMAT FORMAT_void_GLfloat_GLfloat
#define glPointParameterf_INDEX 304
#define glPointParameterf_RETURN void
#define glPointParameterf_ARG_NAMES pname, param
#define glPointParameterf_ARG_EXPAND GLenum pname, GLfloat param
#define glPointParameterf_PACKED PACKED_void_GLenum_GLfloat
#define glPointParameterf_INDEXED INDEXED_void_GLenum_GLfloat
#define glPointParameterf_FORMAT FORMAT_void_GLenum_GLfloat
#define glPointParameterfv_INDEX 305
#define glPointParameterfv_RETURN void
#define glPointParameterfv_ARG_NAMES pname, params
#define glPointParameterfv_ARG_EXPAND GLenum pname, const GLfloat * params
#define glPointParameterfv_PACKED PACKED_void_GLenum_const_GLfloat___GENPT__
#define glPointParameterfv_INDEXED INDEXED_void_GLenum_const_GLfloat___GENPT__
#define glPointParameterfv_FORMAT FORMAT_void_GLenum_const_GLfloat___GENPT__
#define glPointParameteri_INDEX 306
#define glPointParameteri_RETURN void
#define glPointParameteri_ARG_NAMES pname, param
#define glPointParameteri_ARG_EXPAND GLenum pname, GLint param
#define glPointParameteri_PACKED PACKED_void_GLenum_GLint
#define glPointParameteri_INDEXED INDEXED_void_GLenum_GLint
#define glPointParameteri_FORMAT FORMAT_void_GLenum_GLint
#define glPointParameteriv_INDEX 307
#define glPointParameteriv_RETURN void
#define glPointParameteriv_ARG_NAMES pname, params
#define glPointParameteriv_ARG_EXPAND GLenum pname, const GLint * params
#define glPointParameteriv_PACKED PACKED_void_GLenum_const_GLint___GENPT__
#define glPointParameteriv_INDEXED INDEXED_void_GLenum_const_GLint___GENPT__
#define glPointParameteriv_FORMAT FORMAT_void_GLenum_const_GLint___GENPT__
#define glPointSize_INDEX 308
#define glPointSize_RETURN void
#define glPointSize_ARG_NAMES size
#define glPointSize_ARG_EXPAND GLfloat size
#define glPointSize_PACKED PACKED_void_GLfloat
#define glPointSize_INDEXED INDEXED_void_GLfloat
#define glPointSize_FORMAT FORMAT_void_GLfloat
#define glPolygonMode_INDEX 309
#define glPolygonMode_RETURN void
#define glPolygonMode_ARG_NAMES face, mode
#define glPolygonMode_ARG_EXPAND GLenum face, GLenum mode
#define glPolygonMode_PACKED PACKED_void_GLenum_GLenum
#define glPolygonMode_INDEXED INDEXED_void_GLenum_GLenum
#define glPolygonMode_FORMAT FORMAT_void_GLenum_GLenum
#define glPolygonOffset_INDEX 310
#define glPolygonOffset_RETURN void
#define glPolygonOffset_ARG_NAMES factor, units
#define glPolygonOffset_ARG_EXPAND GLfloat factor, GLfloat units
#define glPolygonOffset_PACKED PACKED_void_GLfloat_GLfloat
#define glPolygonOffset_INDEXED INDEXED_void_GLfloat_GLfloat
#define glPolygonOffset_FORMAT FORMAT_void_GLfloat_GLfloat
#define glPolygonStipple_INDEX 311
#define glPolygonStipple_RETURN void
#define glPolygonStipple_ARG_NAMES mask
#define glPolygonStipple_ARG_EXPAND const GLubyte * mask
#define glPolygonStipple_PACKED PACKED_void_const_GLubyte___GENPT__
#define glPolygonStipple_INDEXED INDEXED_void_const_GLubyte___GENPT__
#define glPolygonStipple_FORMAT FORMAT_void_const_GLubyte___GENPT__
#define glPopAttrib_INDEX 312
#define glPopAttrib_RETURN void
#define glPopAttrib_ARG_NAMES 
#define glPopAttrib_ARG_EXPAND 
#define glPopAttrib_PACKED PACKED_void
#define glPopAttrib_INDEXED INDEXED_void
#define glPopAttrib_FORMAT FORMAT_void
#define glPopClientAttrib_INDEX 313
#define glPopClientAttrib_RETURN void
#define glPopClientAttrib_ARG_NAMES 
#define glPopClientAttrib_ARG_EXPAND 
#define glPopClientAttrib_PACKED PACKED_void
#define glPopClientAttrib_INDEXED INDEXED_void
#define glPopClientAttrib_FORMAT FORMAT_void
#define glPopMatrix_INDEX 314
#define glPopMatrix_RETURN void
#define glPopMatrix_ARG_NAMES 
#define glPopMatrix_ARG_EXPAND 
#define glPopMatrix_PACKED PACKED_void
#define glPopMatrix_INDEXED INDEXED_void
#define glPopMatrix_FORMAT FORMAT_void
#define glPopName_INDEX 315
#define glPopName_RETURN void
#define glPopName_ARG_NAMES 
#define glPopName_ARG_EXPAND 
#define glPopName_PACKED PACKED_void
#define glPopName_INDEXED INDEXED_void
#define glPopName_FORMAT FORMAT_void
#define glPrioritizeTextures_INDEX 316
#define glPrioritizeTextures_RETURN void
#define glPrioritizeTextures_ARG_NAMES n, textures, priorities
#define glPrioritizeTextures_ARG_EXPAND GLsizei n, const GLuint * textures, const GLfloat * priorities
#define glPrioritizeTextures_PACKED PACKED_void_GLsizei_const_GLuint___GENPT___const_GLfloat___GENPT__
#define glPrioritizeTextures_INDEXED INDEXED_void_GLsizei_const_GLuint___GENPT___const_GLfloat___GENPT__
#define glPrioritizeTextures_FORMAT FORMAT_void_GLsizei_const_GLuint___GENPT___const_GLfloat___GENPT__
#define glPushAttrib_INDEX 317
#define glPushAttrib_RETURN void
#define glPushAttrib_ARG_NAMES mask
#define glPushAttrib_ARG_EXPAND GLbitfield mask
#define glPushAttrib_PACKED PACKED_void_GLbitfield
#define glPushAttrib_INDEXED INDEXED_void_GLbitfield
#define glPushAttrib_FORMAT FORMAT_void_GLbitfield
#define glPushClientAttrib_INDEX 318
#define glPushClientAttrib_RETURN void
#define glPushClientAttrib_ARG_NAMES mask
#define glPushClientAttrib_ARG_EXPAND GLbitfield mask
#define glPushClientAttrib_PACKED PACKED_void_GLbitfield
#define glPushClientAttrib_INDEXED INDEXED_void_GLbitfield
#define glPushClientAttrib_FORMAT FORMAT_void_GLbitfield
#define glPushMatrix_INDEX 319
#define glPushMatrix_RETURN void
#define glPushMatrix_ARG_NAMES 
#define glPushMatrix_ARG_EXPAND 
#define glPushMatrix_PACKED PACKED_void
#define glPushMatrix_INDEXED INDEXED_void
#define glPushMatrix_FORMAT FORMAT_void
#define glPushName_INDEX 320
#define glPushName_RETURN void
#define glPushName_ARG_NAMES name
#define glPushName_ARG_EXPAND GLuint name
#define glPushName_PACKED PACKED_void_GLuint
#define glPushName_INDEXED INDEXED_void_GLuint
#define glPushName_FORMAT FORMAT_void_GLuint
#define glRasterPos2d_INDEX 321
#define glRasterPos2d_RETURN void
#define glRasterPos2d_ARG_NAMES x, y
#define glRasterPos2d_ARG_EXPAND GLdouble x, GLdouble y
#define glRasterPos2d_PACKED PACKED_void_GLdouble_GLdouble
#define glRasterPos2d_INDEXED INDEXED_void_GLdouble_GLdouble
#define glRasterPos2d_FORMAT FORMAT_void_GLdouble_GLdouble
#define glRasterPos2dv_INDEX 322
#define glRasterPos2dv_RETURN void
#define glRasterPos2dv_ARG_NAMES v
#define glRasterPos2dv_ARG_EXPAND const GLdouble * v
#define glRasterPos2dv_PACKED PACKED_void_const_GLdouble___GENPT__
#define glRasterPos2dv_INDEXED INDEXED_void_const_GLdouble___GENPT__
#define glRasterPos2dv_FORMAT FORMAT_void_const_GLdouble___GENPT__
#define glRasterPos2f_INDEX 323
#define glRasterPos2f_RETURN void
#define glRasterPos2f_ARG_NAMES x, y
#define glRasterPos2f_ARG_EXPAND GLfloat x, GLfloat y
#define glRasterPos2f_PACKED PACKED_void_GLfloat_GLfloat
#define glRasterPos2f_INDEXED INDEXED_void_GLfloat_GLfloat
#define glRasterPos2f_FORMAT FORMAT_void_GLfloat_GLfloat
#define glRasterPos2fv_INDEX 324
#define glRasterPos2fv_RETURN void
#define glRasterPos2fv_ARG_NAMES v
#define glRasterPos2fv_ARG_EXPAND const GLfloat * v
#define glRasterPos2fv_PACKED PACKED_void_const_GLfloat___GENPT__
#define glRasterPos2fv_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glRasterPos2fv_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glRasterPos2i_INDEX 325
#define glRasterPos2i_RETURN void
#define glRasterPos2i_ARG_NAMES x, y
#define glRasterPos2i_ARG_EXPAND GLint x, GLint y
#define glRasterPos2i_PACKED PACKED_void_GLint_GLint
#define glRasterPos2i_INDEXED INDEXED_void_GLint_GLint
#define glRasterPos2i_FORMAT FORMAT_void_GLint_GLint
#define glRasterPos2iv_INDEX 326
#define glRasterPos2iv_RETURN void
#define glRasterPos2iv_ARG_NAMES v
#define glRasterPos2iv_ARG_EXPAND const GLint * v
#define glRasterPos2iv_PACKED PACKED_void_const_GLint___GENPT__
#define glRasterPos2iv_INDEXED INDEXED_void_const_GLint___GENPT__
#define glRasterPos2iv_FORMAT FORMAT_void_const_GLint___GENPT__
#define glRasterPos2s_INDEX 327
#define glRasterPos2s_RETURN void
#define glRasterPos2s_ARG_NAMES x, y
#define glRasterPos2s_ARG_EXPAND GLshort x, GLshort y
#define glRasterPos2s_PACKED PACKED_void_GLshort_GLshort
#define glRasterPos2s_INDEXED INDEXED_void_GLshort_GLshort
#define glRasterPos2s_FORMAT FORMAT_void_GLshort_GLshort
#define glRasterPos2sv_INDEX 328
#define glRasterPos2sv_RETURN void
#define glRasterPos2sv_ARG_NAMES v
#define glRasterPos2sv_ARG_EXPAND const GLshort * v
#define glRasterPos2sv_PACKED PACKED_void_const_GLshort___GENPT__
#define glRasterPos2sv_INDEXED INDEXED_void_const_GLshort___GENPT__
#define glRasterPos2sv_FORMAT FORMAT_void_const_GLshort___GENPT__
#define glRasterPos3d_INDEX 329
#define glRasterPos3d_RETURN void
#define glRasterPos3d_ARG_NAMES x, y, z
#define glRasterPos3d_ARG_EXPAND GLdouble x, GLdouble y, GLdouble z
#define glRasterPos3d_PACKED PACKED_void_GLdouble_GLdouble_GLdouble
#define glRasterPos3d_INDEXED INDEXED_void_GLdouble_GLdouble_GLdouble
#define glRasterPos3d_FORMAT FORMAT_void_GLdouble_GLdouble_GLdouble
#define glRasterPos3dv_INDEX 330
#define glRasterPos3dv_RETURN void
#define glRasterPos3dv_ARG_NAMES v
#define glRasterPos3dv_ARG_EXPAND const GLdouble * v
#define glRasterPos3dv_PACKED PACKED_void_const_GLdouble___GENPT__
#define glRasterPos3dv_INDEXED INDEXED_void_const_GLdouble___GENPT__
#define glRasterPos3dv_FORMAT FORMAT_void_const_GLdouble___GENPT__
#define glRasterPos3f_INDEX 331
#define glRasterPos3f_RETURN void
#define glRasterPos3f_ARG_NAMES x, y, z
#define glRasterPos3f_ARG_EXPAND GLfloat x, GLfloat y, GLfloat z
#define glRasterPos3f_PACKED PACKED_void_GLfloat_GLfloat_GLfloat
#define glRasterPos3f_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat
#define glRasterPos3f_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat
#define glRasterPos3fv_INDEX 332
#define glRasterPos3fv_RETURN void
#define glRasterPos3fv_ARG_NAMES v
#define glRasterPos3fv_ARG_EXPAND const GLfloat * v
#define glRasterPos3fv_PACKED PACKED_void_const_GLfloat___GENPT__
#define glRasterPos3fv_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glRasterPos3fv_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glRasterPos3i_INDEX 333
#define glRasterPos3i_RETURN void
#define glRasterPos3i_ARG_NAMES x, y, z
#define glRasterPos3i_ARG_EXPAND GLint x, GLint y, GLint z
#define glRasterPos3i_PACKED PACKED_void_GLint_GLint_GLint
#define glRasterPos3i_INDEXED INDEXED_void_GLint_GLint_GLint
#define glRasterPos3i_FORMAT FORMAT_void_GLint_GLint_GLint
#define glRasterPos3iv_INDEX 334
#define glRasterPos3iv_RETURN void
#define glRasterPos3iv_ARG_NAMES v
#define glRasterPos3iv_ARG_EXPAND const GLint * v
#define glRasterPos3iv_PACKED PACKED_void_const_GLint___GENPT__
#define glRasterPos3iv_INDEXED INDEXED_void_const_GLint___GENPT__
#define glRasterPos3iv_FORMAT FORMAT_void_const_GLint___GENPT__
#define glRasterPos3s_INDEX 335
#define glRasterPos3s_RETURN void
#define glRasterPos3s_ARG_NAMES x, y, z
#define glRasterPos3s_ARG_EXPAND GLshort x, GLshort y, GLshort z
#define glRasterPos3s_PACKED PACKED_void_GLshort_GLshort_GLshort
#define glRasterPos3s_INDEXED INDEXED_void_GLshort_GLshort_GLshort
#define glRasterPos3s_FORMAT FORMAT_void_GLshort_GLshort_GLshort
#define glRasterPos3sv_INDEX 336
#define glRasterPos3sv_RETURN void
#define glRasterPos3sv_ARG_NAMES v
#define glRasterPos3sv_ARG_EXPAND const GLshort * v
#define glRasterPos3sv_PACKED PACKED_void_const_GLshort___GENPT__
#define glRasterPos3sv_INDEXED INDEXED_void_const_GLshort___GENPT__
#define glRasterPos3sv_FORMAT FORMAT_void_const_GLshort___GENPT__
#define glRasterPos4d_INDEX 337
#define glRasterPos4d_RETURN void
#define glRasterPos4d_ARG_NAMES x, y, z, w
#define glRasterPos4d_ARG_EXPAND GLdouble x, GLdouble y, GLdouble z, GLdouble w
#define glRasterPos4d_PACKED PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble
#define glRasterPos4d_INDEXED INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble
#define glRasterPos4d_FORMAT FORMAT_void_GLdouble_GLdouble_GLdouble_GLdouble
#define glRasterPos4dv_INDEX 338
#define glRasterPos4dv_RETURN void
#define glRasterPos4dv_ARG_NAMES v
#define glRasterPos4dv_ARG_EXPAND const GLdouble * v
#define glRasterPos4dv_PACKED PACKED_void_const_GLdouble___GENPT__
#define glRasterPos4dv_INDEXED INDEXED_void_const_GLdouble___GENPT__
#define glRasterPos4dv_FORMAT FORMAT_void_const_GLdouble___GENPT__
#define glRasterPos4f_INDEX 339
#define glRasterPos4f_RETURN void
#define glRasterPos4f_ARG_NAMES x, y, z, w
#define glRasterPos4f_ARG_EXPAND GLfloat x, GLfloat y, GLfloat z, GLfloat w
#define glRasterPos4f_PACKED PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glRasterPos4f_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glRasterPos4f_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glRasterPos4fv_INDEX 340
#define glRasterPos4fv_RETURN void
#define glRasterPos4fv_ARG_NAMES v
#define glRasterPos4fv_ARG_EXPAND const GLfloat * v
#define glRasterPos4fv_PACKED PACKED_void_const_GLfloat___GENPT__
#define glRasterPos4fv_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glRasterPos4fv_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glRasterPos4i_INDEX 341
#define glRasterPos4i_RETURN void
#define glRasterPos4i_ARG_NAMES x, y, z, w
#define glRasterPos4i_ARG_EXPAND GLint x, GLint y, GLint z, GLint w
#define glRasterPos4i_PACKED PACKED_void_GLint_GLint_GLint_GLint
#define glRasterPos4i_INDEXED INDEXED_void_GLint_GLint_GLint_GLint
#define glRasterPos4i_FORMAT FORMAT_void_GLint_GLint_GLint_GLint
#define glRasterPos4iv_INDEX 342
#define glRasterPos4iv_RETURN void
#define glRasterPos4iv_ARG_NAMES v
#define glRasterPos4iv_ARG_EXPAND const GLint * v
#define glRasterPos4iv_PACKED PACKED_void_const_GLint___GENPT__
#define glRasterPos4iv_INDEXED INDEXED_void_const_GLint___GENPT__
#define glRasterPos4iv_FORMAT FORMAT_void_const_GLint___GENPT__
#define glRasterPos4s_INDEX 343
#define glRasterPos4s_RETURN void
#define glRasterPos4s_ARG_NAMES x, y, z, w
#define glRasterPos4s_ARG_EXPAND GLshort x, GLshort y, GLshort z, GLshort w
#define glRasterPos4s_PACKED PACKED_void_GLshort_GLshort_GLshort_GLshort
#define glRasterPos4s_INDEXED INDEXED_void_GLshort_GLshort_GLshort_GLshort
#define glRasterPos4s_FORMAT FORMAT_void_GLshort_GLshort_GLshort_GLshort
#define glRasterPos4sv_INDEX 344
#define glRasterPos4sv_RETURN void
#define glRasterPos4sv_ARG_NAMES v
#define glRasterPos4sv_ARG_EXPAND const GLshort * v
#define glRasterPos4sv_PACKED PACKED_void_const_GLshort___GENPT__
#define glRasterPos4sv_INDEXED INDEXED_void_const_GLshort___GENPT__
#define glRasterPos4sv_FORMAT FORMAT_void_const_GLshort___GENPT__
#define glReadBuffer_INDEX 345
#define glReadBuffer_RETURN void
#define glReadBuffer_ARG_NAMES mode
#define glReadBuffer_ARG_EXPAND GLenum mode
#define glReadBuffer_PACKED PACKED_void_GLenum
#define glReadBuffer_INDEXED INDEXED_void_GLenum
#define glReadBuffer_FORMAT FORMAT_void_GLenum
#define glReadPixels_INDEX 346
#define glReadPixels_RETURN void
#define glReadPixels_ARG_NAMES x, y, width, height, format, type, pixels
#define glReadPixels_ARG_EXPAND GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels
#define glReadPixels_PACKED PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__
#define glReadPixels_INDEXED INDEXED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__
#define glReadPixels_FORMAT FORMAT_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid___GENPT__
#define glRectd_INDEX 347
#define glRectd_RETURN void
#define glRectd_ARG_NAMES x1, y1, x2, y2
#define glRectd_ARG_EXPAND GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2
#define glRectd_PACKED PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble
#define glRectd_INDEXED INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble
#define glRectd_FORMAT FORMAT_void_GLdouble_GLdouble_GLdouble_GLdouble
#define glRectdv_INDEX 348
#define glRectdv_RETURN void
#define glRectdv_ARG_NAMES v1, v2
#define glRectdv_ARG_EXPAND const GLdouble * v1, const GLdouble * v2
#define glRectdv_PACKED PACKED_void_const_GLdouble___GENPT___const_GLdouble___GENPT__
#define glRectdv_INDEXED INDEXED_void_const_GLdouble___GENPT___const_GLdouble___GENPT__
#define glRectdv_FORMAT FORMAT_void_const_GLdouble___GENPT___const_GLdouble___GENPT__
#define glRectf_INDEX 349
#define glRectf_RETURN void
#define glRectf_ARG_NAMES x1, y1, x2, y2
#define glRectf_ARG_EXPAND GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2
#define glRectf_PACKED PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glRectf_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glRectf_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glRectfv_INDEX 350
#define glRectfv_RETURN void
#define glRectfv_ARG_NAMES v1, v2
#define glRectfv_ARG_EXPAND const GLfloat * v1, const GLfloat * v2
#define glRectfv_PACKED PACKED_void_const_GLfloat___GENPT___const_GLfloat___GENPT__
#define glRectfv_INDEXED INDEXED_void_const_GLfloat___GENPT___const_GLfloat___GENPT__
#define glRectfv_FORMAT FORMAT_void_const_GLfloat___GENPT___const_GLfloat___GENPT__
#define glRecti_INDEX 351
#define glRecti_RETURN void
#define glRecti_ARG_NAMES x1, y1, x2, y2
#define glRecti_ARG_EXPAND GLint x1, GLint y1, GLint x2, GLint y2
#define glRecti_PACKED PACKED_void_GLint_GLint_GLint_GLint
#define glRecti_INDEXED INDEXED_void_GLint_GLint_GLint_GLint
#define glRecti_FORMAT FORMAT_void_GLint_GLint_GLint_GLint
#define glRectiv_INDEX 352
#define glRectiv_RETURN void
#define glRectiv_ARG_NAMES v1, v2
#define glRectiv_ARG_EXPAND const GLint * v1, const GLint * v2
#define glRectiv_PACKED PACKED_void_const_GLint___GENPT___const_GLint___GENPT__
#define glRectiv_INDEXED INDEXED_void_const_GLint___GENPT___const_GLint___GENPT__
#define glRectiv_FORMAT FORMAT_void_const_GLint___GENPT___const_GLint___GENPT__
#define glRects_INDEX 353
#define glRects_RETURN void
#define glRects_ARG_NAMES x1, y1, x2, y2
#define glRects_ARG_EXPAND GLshort x1, GLshort y1, GLshort x2, GLshort y2
#define glRects_PACKED PACKED_void_GLshort_GLshort_GLshort_GLshort
#define glRects_INDEXED INDEXED_void_GLshort_GLshort_GLshort_GLshort
#define glRects_FORMAT FORMAT_void_GLshort_GLshort_GLshort_GLshort
#define glRectsv_INDEX 354
#define glRectsv_RETURN void
#define glRectsv_ARG_NAMES v1, v2
#define glRectsv_ARG_EXPAND const GLshort * v1, const GLshort * v2
#define glRectsv_PACKED PACKED_void_const_GLshort___GENPT___const_GLshort___GENPT__
#define glRectsv_INDEXED INDEXED_void_const_GLshort___GENPT___const_GLshort___GENPT__
#define glRectsv_FORMAT FORMAT_void_const_GLshort___GENPT___const_GLshort___GENPT__
#define glRenderMode_INDEX 355
#define glRenderMode_RETURN GLint
#define glRenderMode_ARG_NAMES mode
#define glRenderMode_ARG_EXPAND GLenum mode
#define glRenderMode_PACKED PACKED_GLint_GLenum
#define glRenderMode_INDEXED INDEXED_GLint_GLenum
#define glRenderMode_FORMAT FORMAT_GLint_GLenum
#define glResetHistogram_INDEX 356
#define glResetHistogram_RETURN void
#define glResetHistogram_ARG_NAMES target
#define glResetHistogram_ARG_EXPAND GLenum target
#define glResetHistogram_PACKED PACKED_void_GLenum
#define glResetHistogram_INDEXED INDEXED_void_GLenum
#define glResetHistogram_FORMAT FORMAT_void_GLenum
#define glResetMinmax_INDEX 357
#define glResetMinmax_RETURN void
#define glResetMinmax_ARG_NAMES target
#define glResetMinmax_ARG_EXPAND GLenum target
#define glResetMinmax_PACKED PACKED_void_GLenum
#define glResetMinmax_INDEXED INDEXED_void_GLenum
#define glResetMinmax_FORMAT FORMAT_void_GLenum
#define glRotated_INDEX 358
#define glRotated_RETURN void
#define glRotated_ARG_NAMES angle, x, y, z
#define glRotated_ARG_EXPAND GLdouble angle, GLdouble x, GLdouble y, GLdouble z
#define glRotated_PACKED PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble
#define glRotated_INDEXED INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble
#define glRotated_FORMAT FORMAT_void_GLdouble_GLdouble_GLdouble_GLdouble
#define glRotatef_INDEX 359
#define glRotatef_RETURN void
#define glRotatef_ARG_NAMES angle, x, y, z
#define glRotatef_ARG_EXPAND GLfloat angle, GLfloat x, GLfloat y, GLfloat z
#define glRotatef_PACKED PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glRotatef_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glRotatef_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glSampleCoverage_INDEX 360
#define glSampleCoverage_RETURN void
#define glSampleCoverage_ARG_NAMES value, invert
#define glSampleCoverage_ARG_EXPAND GLfloat value, GLboolean invert
#define glSampleCoverage_PACKED PACKED_void_GLfloat_GLboolean
#define glSampleCoverage_INDEXED INDEXED_void_GLfloat_GLboolean
#define glSampleCoverage_FORMAT FORMAT_void_GLfloat_GLboolean
#define glScaled_INDEX 361
#define glScaled_RETURN void
#define glScaled_ARG_NAMES x, y, z
#define glScaled_ARG_EXPAND GLdouble x, GLdouble y, GLdouble z
#define glScaled_PACKED PACKED_void_GLdouble_GLdouble_GLdouble
#define glScaled_INDEXED INDEXED_void_GLdouble_GLdouble_GLdouble
#define glScaled_FORMAT FORMAT_void_GLdouble_GLdouble_GLdouble
#define glScalef_INDEX 362
#define glScalef_RETURN void
#define glScalef_ARG_NAMES x, y, z
#define glScalef_ARG_EXPAND GLfloat x, GLfloat y, GLfloat z
#define glScalef_PACKED PACKED_void_GLfloat_GLfloat_GLfloat
#define glScalef_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat
#define glScalef_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat
#define glScissor_INDEX 363
#define glScissor_RETURN void
#define glScissor_ARG_NAMES x, y, width, height
#define glScissor_ARG_EXPAND GLint x, GLint y, GLsizei width, GLsizei height
#define glScissor_PACKED PACKED_void_GLint_GLint_GLsizei_GLsizei
#define glScissor_INDEXED INDEXED_void_GLint_GLint_GLsizei_GLsizei
#define glScissor_FORMAT FORMAT_void_GLint_GLint_GLsizei_GLsizei
#define glSecondaryColor3b_INDEX 364
#define glSecondaryColor3b_RETURN void
#define glSecondaryColor3b_ARG_NAMES red, green, blue
#define glSecondaryColor3b_ARG_EXPAND GLbyte red, GLbyte green, GLbyte blue
#define glSecondaryColor3b_PACKED PACKED_void_GLbyte_GLbyte_GLbyte
#define glSecondaryColor3b_INDEXED INDEXED_void_GLbyte_GLbyte_GLbyte
#define glSecondaryColor3b_FORMAT FORMAT_void_GLbyte_GLbyte_GLbyte
#define glSecondaryColor3bv_INDEX 365
#define glSecondaryColor3bv_RETURN void
#define glSecondaryColor3bv_ARG_NAMES v
#define glSecondaryColor3bv_ARG_EXPAND const GLbyte * v
#define glSecondaryColor3bv_PACKED PACKED_void_const_GLbyte___GENPT__
#define glSecondaryColor3bv_INDEXED INDEXED_void_const_GLbyte___GENPT__
#define glSecondaryColor3bv_FORMAT FORMAT_void_const_GLbyte___GENPT__
#define glSecondaryColor3d_INDEX 366
#define glSecondaryColor3d_RETURN void
#define glSecondaryColor3d_ARG_NAMES red, green, blue
#define glSecondaryColor3d_ARG_EXPAND GLdouble red, GLdouble green, GLdouble blue
#define glSecondaryColor3d_PACKED PACKED_void_GLdouble_GLdouble_GLdouble
#define glSecondaryColor3d_INDEXED INDEXED_void_GLdouble_GLdouble_GLdouble
#define glSecondaryColor3d_FORMAT FORMAT_void_GLdouble_GLdouble_GLdouble
#define glSecondaryColor3dv_INDEX 367
#define glSecondaryColor3dv_RETURN void
#define glSecondaryColor3dv_ARG_NAMES v
#define glSecondaryColor3dv_ARG_EXPAND const GLdouble * v
#define glSecondaryColor3dv_PACKED PACKED_void_const_GLdouble___GENPT__
#define glSecondaryColor3dv_INDEXED INDEXED_void_const_GLdouble___GENPT__
#define glSecondaryColor3dv_FORMAT FORMAT_void_const_GLdouble___GENPT__
#define glSecondaryColor3f_INDEX 368
#define glSecondaryColor3f_RETURN void
#define glSecondaryColor3f_ARG_NAMES red, green, blue
#define glSecondaryColor3f_ARG_EXPAND GLfloat red, GLfloat green, GLfloat blue
#define glSecondaryColor3f_PACKED PACKED_void_GLfloat_GLfloat_GLfloat
#define glSecondaryColor3f_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat
#define glSecondaryColor3f_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat
#define glSecondaryColor3fv_INDEX 369
#define glSecondaryColor3fv_RETURN void
#define glSecondaryColor3fv_ARG_NAMES v
#define glSecondaryColor3fv_ARG_EXPAND const GLfloat * v
#define glSecondaryColor3fv_PACKED PACKED_void_const_GLfloat___GENPT__
#define glSecondaryColor3fv_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glSecondaryColor3fv_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glSecondaryColor3i_INDEX 370
#define glSecondaryColor3i_RETURN void
#define glSecondaryColor3i_ARG_NAMES red, green, blue
#define glSecondaryColor3i_ARG_EXPAND GLint red, GLint green, GLint blue
#define glSecondaryColor3i_PACKED PACKED_void_GLint_GLint_GLint
#define glSecondaryColor3i_INDEXED INDEXED_void_GLint_GLint_GLint
#define glSecondaryColor3i_FORMAT FORMAT_void_GLint_GLint_GLint
#define glSecondaryColor3iv_INDEX 371
#define glSecondaryColor3iv_RETURN void
#define glSecondaryColor3iv_ARG_NAMES v
#define glSecondaryColor3iv_ARG_EXPAND const GLint * v
#define glSecondaryColor3iv_PACKED PACKED_void_const_GLint___GENPT__
#define glSecondaryColor3iv_INDEXED INDEXED_void_const_GLint___GENPT__
#define glSecondaryColor3iv_FORMAT FORMAT_void_const_GLint___GENPT__
#define glSecondaryColor3s_INDEX 372
#define glSecondaryColor3s_RETURN void
#define glSecondaryColor3s_ARG_NAMES red, green, blue
#define glSecondaryColor3s_ARG_EXPAND GLshort red, GLshort green, GLshort blue
#define glSecondaryColor3s_PACKED PACKED_void_GLshort_GLshort_GLshort
#define glSecondaryColor3s_INDEXED INDEXED_void_GLshort_GLshort_GLshort
#define glSecondaryColor3s_FORMAT FORMAT_void_GLshort_GLshort_GLshort
#define glSecondaryColor3sv_INDEX 373
#define glSecondaryColor3sv_RETURN void
#define glSecondaryColor3sv_ARG_NAMES v
#define glSecondaryColor3sv_ARG_EXPAND const GLshort * v
#define glSecondaryColor3sv_PACKED PACKED_void_const_GLshort___GENPT__
#define glSecondaryColor3sv_INDEXED INDEXED_void_const_GLshort___GENPT__
#define glSecondaryColor3sv_FORMAT FORMAT_void_const_GLshort___GENPT__
#define glSecondaryColor3ub_INDEX 374
#define glSecondaryColor3ub_RETURN void
#define glSecondaryColor3ub_ARG_NAMES red, green, blue
#define glSecondaryColor3ub_ARG_EXPAND GLubyte red, GLubyte green, GLubyte blue
#define glSecondaryColor3ub_PACKED PACKED_void_GLubyte_GLubyte_GLubyte
#define glSecondaryColor3ub_INDEXED INDEXED_void_GLubyte_GLubyte_GLubyte
#define glSecondaryColor3ub_FORMAT FORMAT_void_GLubyte_GLubyte_GLubyte
#define glSecondaryColor3ubv_INDEX 375
#define glSecondaryColor3ubv_RETURN void
#define glSecondaryColor3ubv_ARG_NAMES v
#define glSecondaryColor3ubv_ARG_EXPAND const GLubyte * v
#define glSecondaryColor3ubv_PACKED PACKED_void_const_GLubyte___GENPT__
#define glSecondaryColor3ubv_INDEXED INDEXED_void_const_GLubyte___GENPT__
#define glSecondaryColor3ubv_FORMAT FORMAT_void_const_GLubyte___GENPT__
#define glSecondaryColor3ui_INDEX 376
#define glSecondaryColor3ui_RETURN void
#define glSecondaryColor3ui_ARG_NAMES red, green, blue
#define glSecondaryColor3ui_ARG_EXPAND GLuint red, GLuint green, GLuint blue
#define glSecondaryColor3ui_PACKED PACKED_void_GLuint_GLuint_GLuint
#define glSecondaryColor3ui_INDEXED INDEXED_void_GLuint_GLuint_GLuint
#define glSecondaryColor3ui_FORMAT FORMAT_void_GLuint_GLuint_GLuint
#define glSecondaryColor3uiv_INDEX 377
#define glSecondaryColor3uiv_RETURN void
#define glSecondaryColor3uiv_ARG_NAMES v
#define glSecondaryColor3uiv_ARG_EXPAND const GLuint * v
#define glSecondaryColor3uiv_PACKED PACKED_void_const_GLuint___GENPT__
#define glSecondaryColor3uiv_INDEXED INDEXED_void_const_GLuint___GENPT__
#define glSecondaryColor3uiv_FORMAT FORMAT_void_const_GLuint___GENPT__
#define glSecondaryColor3us_INDEX 378
#define glSecondaryColor3us_RETURN void
#define glSecondaryColor3us_ARG_NAMES red, green, blue
#define glSecondaryColor3us_ARG_EXPAND GLushort red, GLushort green, GLushort blue
#define glSecondaryColor3us_PACKED PACKED_void_GLushort_GLushort_GLushort
#define glSecondaryColor3us_INDEXED INDEXED_void_GLushort_GLushort_GLushort
#define glSecondaryColor3us_FORMAT FORMAT_void_GLushort_GLushort_GLushort
#define glSecondaryColor3usv_INDEX 379
#define glSecondaryColor3usv_RETURN void
#define glSecondaryColor3usv_ARG_NAMES v
#define glSecondaryColor3usv_ARG_EXPAND const GLushort * v
#define glSecondaryColor3usv_PACKED PACKED_void_const_GLushort___GENPT__
#define glSecondaryColor3usv_INDEXED INDEXED_void_const_GLushort___GENPT__
#define glSecondaryColor3usv_FORMAT FORMAT_void_const_GLushort___GENPT__
#define glSecondaryColorPointer_INDEX 380
#define glSecondaryColorPointer_RETURN void
#define glSecondaryColorPointer_ARG_NAMES size, type, stride, pointer
#define glSecondaryColorPointer_ARG_EXPAND GLint size, GLenum type, GLsizei stride, const GLvoid * pointer
#define glSecondaryColorPointer_PACKED PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__
#define glSecondaryColorPointer_INDEXED INDEXED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__
#define glSecondaryColorPointer_FORMAT FORMAT_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__
#define glSelectBuffer_INDEX 381
#define glSelectBuffer_RETURN void
#define glSelectBuffer_ARG_NAMES size, buffer
#define glSelectBuffer_ARG_EXPAND GLsizei size, GLuint * buffer
#define glSelectBuffer_PACKED PACKED_void_GLsizei_GLuint___GENPT__
#define glSelectBuffer_INDEXED INDEXED_void_GLsizei_GLuint___GENPT__
#define glSelectBuffer_FORMAT FORMAT_void_GLsizei_GLuint___GENPT__
#define glSeparableFilter2D_INDEX 382
#define glSeparableFilter2D_RETURN void
#define glSeparableFilter2D_ARG_NAMES target, internalformat, width, height, format, type, row, column
#define glSeparableFilter2D_ARG_EXPAND GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * row, const GLvoid * column
#define glSeparableFilter2D_PACKED PACKED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT___const_GLvoid___GENPT__
#define glSeparableFilter2D_INDEXED INDEXED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT___const_GLvoid___GENPT__
#define glSeparableFilter2D_FORMAT FORMAT_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT___const_GLvoid___GENPT__
#define glShadeModel_INDEX 383
#define glShadeModel_RETURN void
#define glShadeModel_ARG_NAMES mode
#define glShadeModel_ARG_EXPAND GLenum mode
#define glShadeModel_PACKED PACKED_void_GLenum
#define glShadeModel_INDEXED INDEXED_void_GLenum
#define glShadeModel_FORMAT FORMAT_void_GLenum
#define glStencilFunc_INDEX 384
#define glStencilFunc_RETURN void
#define glStencilFunc_ARG_NAMES func, ref, mask
#define glStencilFunc_ARG_EXPAND GLenum func, GLint ref, GLuint mask
#define glStencilFunc_PACKED PACKED_void_GLenum_GLint_GLuint
#define glStencilFunc_INDEXED INDEXED_void_GLenum_GLint_GLuint
#define glStencilFunc_FORMAT FORMAT_void_GLenum_GLint_GLuint
#define glStencilMask_INDEX 385
#define glStencilMask_RETURN void
#define glStencilMask_ARG_NAMES mask
#define glStencilMask_ARG_EXPAND GLuint mask
#define glStencilMask_PACKED PACKED_void_GLuint
#define glStencilMask_INDEXED INDEXED_void_GLuint
#define glStencilMask_FORMAT FORMAT_void_GLuint
#define glStencilOp_INDEX 386
#define glStencilOp_RETURN void
#define glStencilOp_ARG_NAMES fail, zfail, zpass
#define glStencilOp_ARG_EXPAND GLenum fail, GLenum zfail, GLenum zpass
#define glStencilOp_PACKED PACKED_void_GLenum_GLenum_GLenum
#define glStencilOp_INDEXED INDEXED_void_GLenum_GLenum_GLenum
#define glStencilOp_FORMAT FORMAT_void_GLenum_GLenum_GLenum
#define glTexCoord1d_INDEX 387
#define glTexCoord1d_RETURN void
#define glTexCoord1d_ARG_NAMES s
#define glTexCoord1d_ARG_EXPAND GLdouble s
#define glTexCoord1d_PACKED PACKED_void_GLdouble
#define glTexCoord1d_INDEXED INDEXED_void_GLdouble
#define glTexCoord1d_FORMAT FORMAT_void_GLdouble
#define glTexCoord1dv_INDEX 388
#define glTexCoord1dv_RETURN void
#define glTexCoord1dv_ARG_NAMES v
#define glTexCoord1dv_ARG_EXPAND const GLdouble * v
#define glTexCoord1dv_PACKED PACKED_void_const_GLdouble___GENPT__
#define glTexCoord1dv_INDEXED INDEXED_void_const_GLdouble___GENPT__
#define glTexCoord1dv_FORMAT FORMAT_void_const_GLdouble___GENPT__
#define glTexCoord1f_INDEX 389
#define glTexCoord1f_RETURN void
#define glTexCoord1f_ARG_NAMES s
#define glTexCoord1f_ARG_EXPAND GLfloat s
#define glTexCoord1f_PACKED PACKED_void_GLfloat
#define glTexCoord1f_INDEXED INDEXED_void_GLfloat
#define glTexCoord1f_FORMAT FORMAT_void_GLfloat
#define glTexCoord1fv_INDEX 390
#define glTexCoord1fv_RETURN void
#define glTexCoord1fv_ARG_NAMES v
#define glTexCoord1fv_ARG_EXPAND const GLfloat * v
#define glTexCoord1fv_PACKED PACKED_void_const_GLfloat___GENPT__
#define glTexCoord1fv_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glTexCoord1fv_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glTexCoord1i_INDEX 391
#define glTexCoord1i_RETURN void
#define glTexCoord1i_ARG_NAMES s
#define glTexCoord1i_ARG_EXPAND GLint s
#define glTexCoord1i_PACKED PACKED_void_GLint
#define glTexCoord1i_INDEXED INDEXED_void_GLint
#define glTexCoord1i_FORMAT FORMAT_void_GLint
#define glTexCoord1iv_INDEX 392
#define glTexCoord1iv_RETURN void
#define glTexCoord1iv_ARG_NAMES v
#define glTexCoord1iv_ARG_EXPAND const GLint * v
#define glTexCoord1iv_PACKED PACKED_void_const_GLint___GENPT__
#define glTexCoord1iv_INDEXED INDEXED_void_const_GLint___GENPT__
#define glTexCoord1iv_FORMAT FORMAT_void_const_GLint___GENPT__
#define glTexCoord1s_INDEX 393
#define glTexCoord1s_RETURN void
#define glTexCoord1s_ARG_NAMES s
#define glTexCoord1s_ARG_EXPAND GLshort s
#define glTexCoord1s_PACKED PACKED_void_GLshort
#define glTexCoord1s_INDEXED INDEXED_void_GLshort
#define glTexCoord1s_FORMAT FORMAT_void_GLshort
#define glTexCoord1sv_INDEX 394
#define glTexCoord1sv_RETURN void
#define glTexCoord1sv_ARG_NAMES v
#define glTexCoord1sv_ARG_EXPAND const GLshort * v
#define glTexCoord1sv_PACKED PACKED_void_const_GLshort___GENPT__
#define glTexCoord1sv_INDEXED INDEXED_void_const_GLshort___GENPT__
#define glTexCoord1sv_FORMAT FORMAT_void_const_GLshort___GENPT__
#define glTexCoord2d_INDEX 395
#define glTexCoord2d_RETURN void
#define glTexCoord2d_ARG_NAMES s, t
#define glTexCoord2d_ARG_EXPAND GLdouble s, GLdouble t
#define glTexCoord2d_PACKED PACKED_void_GLdouble_GLdouble
#define glTexCoord2d_INDEXED INDEXED_void_GLdouble_GLdouble
#define glTexCoord2d_FORMAT FORMAT_void_GLdouble_GLdouble
#define glTexCoord2dv_INDEX 396
#define glTexCoord2dv_RETURN void
#define glTexCoord2dv_ARG_NAMES v
#define glTexCoord2dv_ARG_EXPAND const GLdouble * v
#define glTexCoord2dv_PACKED PACKED_void_const_GLdouble___GENPT__
#define glTexCoord2dv_INDEXED INDEXED_void_const_GLdouble___GENPT__
#define glTexCoord2dv_FORMAT FORMAT_void_const_GLdouble___GENPT__
#define glTexCoord2f_INDEX 397
#define glTexCoord2f_RETURN void
#define glTexCoord2f_ARG_NAMES s, t
#define glTexCoord2f_ARG_EXPAND GLfloat s, GLfloat t
#define glTexCoord2f_PACKED PACKED_void_GLfloat_GLfloat
#define glTexCoord2f_INDEXED INDEXED_void_GLfloat_GLfloat
#define glTexCoord2f_FORMAT FORMAT_void_GLfloat_GLfloat
#define glTexCoord2fv_INDEX 398
#define glTexCoord2fv_RETURN void
#define glTexCoord2fv_ARG_NAMES v
#define glTexCoord2fv_ARG_EXPAND const GLfloat * v
#define glTexCoord2fv_PACKED PACKED_void_const_GLfloat___GENPT__
#define glTexCoord2fv_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glTexCoord2fv_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glTexCoord2i_INDEX 399
#define glTexCoord2i_RETURN void
#define glTexCoord2i_ARG_NAMES s, t
#define glTexCoord2i_ARG_EXPAND GLint s, GLint t
#define glTexCoord2i_PACKED PACKED_void_GLint_GLint
#define glTexCoord2i_INDEXED INDEXED_void_GLint_GLint
#define glTexCoord2i_FORMAT FORMAT_void_GLint_GLint
#define glTexCoord2iv_INDEX 400
#define glTexCoord2iv_RETURN void
#define glTexCoord2iv_ARG_NAMES v
#define glTexCoord2iv_ARG_EXPAND const GLint * v
#define glTexCoord2iv_PACKED PACKED_void_const_GLint___GENPT__
#define glTexCoord2iv_INDEXED INDEXED_void_const_GLint___GENPT__
#define glTexCoord2iv_FORMAT FORMAT_void_const_GLint___GENPT__
#define glTexCoord2s_INDEX 401
#define glTexCoord2s_RETURN void
#define glTexCoord2s_ARG_NAMES s, t
#define glTexCoord2s_ARG_EXPAND GLshort s, GLshort t
#define glTexCoord2s_PACKED PACKED_void_GLshort_GLshort
#define glTexCoord2s_INDEXED INDEXED_void_GLshort_GLshort
#define glTexCoord2s_FORMAT FORMAT_void_GLshort_GLshort
#define glTexCoord2sv_INDEX 402
#define glTexCoord2sv_RETURN void
#define glTexCoord2sv_ARG_NAMES v
#define glTexCoord2sv_ARG_EXPAND const GLshort * v
#define glTexCoord2sv_PACKED PACKED_void_const_GLshort___GENPT__
#define glTexCoord2sv_INDEXED INDEXED_void_const_GLshort___GENPT__
#define glTexCoord2sv_FORMAT FORMAT_void_const_GLshort___GENPT__
#define glTexCoord3d_INDEX 403
#define glTexCoord3d_RETURN void
#define glTexCoord3d_ARG_NAMES s, t, r
#define glTexCoord3d_ARG_EXPAND GLdouble s, GLdouble t, GLdouble r
#define glTexCoord3d_PACKED PACKED_void_GLdouble_GLdouble_GLdouble
#define glTexCoord3d_INDEXED INDEXED_void_GLdouble_GLdouble_GLdouble
#define glTexCoord3d_FORMAT FORMAT_void_GLdouble_GLdouble_GLdouble
#define glTexCoord3dv_INDEX 404
#define glTexCoord3dv_RETURN void
#define glTexCoord3dv_ARG_NAMES v
#define glTexCoord3dv_ARG_EXPAND const GLdouble * v
#define glTexCoord3dv_PACKED PACKED_void_const_GLdouble___GENPT__
#define glTexCoord3dv_INDEXED INDEXED_void_const_GLdouble___GENPT__
#define glTexCoord3dv_FORMAT FORMAT_void_const_GLdouble___GENPT__
#define glTexCoord3f_INDEX 405
#define glTexCoord3f_RETURN void
#define glTexCoord3f_ARG_NAMES s, t, r
#define glTexCoord3f_ARG_EXPAND GLfloat s, GLfloat t, GLfloat r
#define glTexCoord3f_PACKED PACKED_void_GLfloat_GLfloat_GLfloat
#define glTexCoord3f_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat
#define glTexCoord3f_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat
#define glTexCoord3fv_INDEX 406
#define glTexCoord3fv_RETURN void
#define glTexCoord3fv_ARG_NAMES v
#define glTexCoord3fv_ARG_EXPAND const GLfloat * v
#define glTexCoord3fv_PACKED PACKED_void_const_GLfloat___GENPT__
#define glTexCoord3fv_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glTexCoord3fv_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glTexCoord3i_INDEX 407
#define glTexCoord3i_RETURN void
#define glTexCoord3i_ARG_NAMES s, t, r
#define glTexCoord3i_ARG_EXPAND GLint s, GLint t, GLint r
#define glTexCoord3i_PACKED PACKED_void_GLint_GLint_GLint
#define glTexCoord3i_INDEXED INDEXED_void_GLint_GLint_GLint
#define glTexCoord3i_FORMAT FORMAT_void_GLint_GLint_GLint
#define glTexCoord3iv_INDEX 408
#define glTexCoord3iv_RETURN void
#define glTexCoord3iv_ARG_NAMES v
#define glTexCoord3iv_ARG_EXPAND const GLint * v
#define glTexCoord3iv_PACKED PACKED_void_const_GLint___GENPT__
#define glTexCoord3iv_INDEXED INDEXED_void_const_GLint___GENPT__
#define glTexCoord3iv_FORMAT FORMAT_void_const_GLint___GENPT__
#define glTexCoord3s_INDEX 409
#define glTexCoord3s_RETURN void
#define glTexCoord3s_ARG_NAMES s, t, r
#define glTexCoord3s_ARG_EXPAND GLshort s, GLshort t, GLshort r
#define glTexCoord3s_PACKED PACKED_void_GLshort_GLshort_GLshort
#define glTexCoord3s_INDEXED INDEXED_void_GLshort_GLshort_GLshort
#define glTexCoord3s_FORMAT FORMAT_void_GLshort_GLshort_GLshort
#define glTexCoord3sv_INDEX 410
#define glTexCoord3sv_RETURN void
#define glTexCoord3sv_ARG_NAMES v
#define glTexCoord3sv_ARG_EXPAND const GLshort * v
#define glTexCoord3sv_PACKED PACKED_void_const_GLshort___GENPT__
#define glTexCoord3sv_INDEXED INDEXED_void_const_GLshort___GENPT__
#define glTexCoord3sv_FORMAT FORMAT_void_const_GLshort___GENPT__
#define glTexCoord4d_INDEX 411
#define glTexCoord4d_RETURN void
#define glTexCoord4d_ARG_NAMES s, t, r, q
#define glTexCoord4d_ARG_EXPAND GLdouble s, GLdouble t, GLdouble r, GLdouble q
#define glTexCoord4d_PACKED PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble
#define glTexCoord4d_INDEXED INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble
#define glTexCoord4d_FORMAT FORMAT_void_GLdouble_GLdouble_GLdouble_GLdouble
#define glTexCoord4dv_INDEX 412
#define glTexCoord4dv_RETURN void
#define glTexCoord4dv_ARG_NAMES v
#define glTexCoord4dv_ARG_EXPAND const GLdouble * v
#define glTexCoord4dv_PACKED PACKED_void_const_GLdouble___GENPT__
#define glTexCoord4dv_INDEXED INDEXED_void_const_GLdouble___GENPT__
#define glTexCoord4dv_FORMAT FORMAT_void_const_GLdouble___GENPT__
#define glTexCoord4f_INDEX 413
#define glTexCoord4f_RETURN void
#define glTexCoord4f_ARG_NAMES s, t, r, q
#define glTexCoord4f_ARG_EXPAND GLfloat s, GLfloat t, GLfloat r, GLfloat q
#define glTexCoord4f_PACKED PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glTexCoord4f_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glTexCoord4f_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glTexCoord4fv_INDEX 414
#define glTexCoord4fv_RETURN void
#define glTexCoord4fv_ARG_NAMES v
#define glTexCoord4fv_ARG_EXPAND const GLfloat * v
#define glTexCoord4fv_PACKED PACKED_void_const_GLfloat___GENPT__
#define glTexCoord4fv_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glTexCoord4fv_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glTexCoord4i_INDEX 415
#define glTexCoord4i_RETURN void
#define glTexCoord4i_ARG_NAMES s, t, r, q
#define glTexCoord4i_ARG_EXPAND GLint s, GLint t, GLint r, GLint q
#define glTexCoord4i_PACKED PACKED_void_GLint_GLint_GLint_GLint
#define glTexCoord4i_INDEXED INDEXED_void_GLint_GLint_GLint_GLint
#define glTexCoord4i_FORMAT FORMAT_void_GLint_GLint_GLint_GLint
#define glTexCoord4iv_INDEX 416
#define glTexCoord4iv_RETURN void
#define glTexCoord4iv_ARG_NAMES v
#define glTexCoord4iv_ARG_EXPAND const GLint * v
#define glTexCoord4iv_PACKED PACKED_void_const_GLint___GENPT__
#define glTexCoord4iv_INDEXED INDEXED_void_const_GLint___GENPT__
#define glTexCoord4iv_FORMAT FORMAT_void_const_GLint___GENPT__
#define glTexCoord4s_INDEX 417
#define glTexCoord4s_RETURN void
#define glTexCoord4s_ARG_NAMES s, t, r, q
#define glTexCoord4s_ARG_EXPAND GLshort s, GLshort t, GLshort r, GLshort q
#define glTexCoord4s_PACKED PACKED_void_GLshort_GLshort_GLshort_GLshort
#define glTexCoord4s_INDEXED INDEXED_void_GLshort_GLshort_GLshort_GLshort
#define glTexCoord4s_FORMAT FORMAT_void_GLshort_GLshort_GLshort_GLshort
#define glTexCoord4sv_INDEX 418
#define glTexCoord4sv_RETURN void
#define glTexCoord4sv_ARG_NAMES v
#define glTexCoord4sv_ARG_EXPAND const GLshort * v
#define glTexCoord4sv_PACKED PACKED_void_const_GLshort___GENPT__
#define glTexCoord4sv_INDEXED INDEXED_void_const_GLshort___GENPT__
#define glTexCoord4sv_FORMAT FORMAT_void_const_GLshort___GENPT__
#define glTexCoordPointer_INDEX 419
#define glTexCoordPointer_RETURN void
#define glTexCoordPointer_ARG_NAMES size, type, stride, pointer
#define glTexCoordPointer_ARG_EXPAND GLint size, GLenum type, GLsizei stride, const GLvoid * pointer
#define glTexCoordPointer_PACKED PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__
#define glTexCoordPointer_INDEXED INDEXED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__
#define glTexCoordPointer_FORMAT FORMAT_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__
#define glTexEnvf_INDEX 420
#define glTexEnvf_RETURN void
#define glTexEnvf_ARG_NAMES target, pname, param
#define glTexEnvf_ARG_EXPAND GLenum target, GLenum pname, GLfloat param
#define glTexEnvf_PACKED PACKED_void_GLenum_GLenum_GLfloat
#define glTexEnvf_INDEXED INDEXED_void_GLenum_GLenum_GLfloat
#define glTexEnvf_FORMAT FORMAT_void_GLenum_GLenum_GLfloat
#define glTexEnvfv_INDEX 421
#define glTexEnvfv_RETURN void
#define glTexEnvfv_ARG_NAMES target, pname, params
#define glTexEnvfv_ARG_EXPAND GLenum target, GLenum pname, const GLfloat * params
#define glTexEnvfv_PACKED PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glTexEnvfv_INDEXED INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glTexEnvfv_FORMAT FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glTexEnvi_INDEX 422
#define glTexEnvi_RETURN void
#define glTexEnvi_ARG_NAMES target, pname, param
#define glTexEnvi_ARG_EXPAND GLenum target, GLenum pname, GLint param
#define glTexEnvi_PACKED PACKED_void_GLenum_GLenum_GLint
#define glTexEnvi_INDEXED INDEXED_void_GLenum_GLenum_GLint
#define glTexEnvi_FORMAT FORMAT_void_GLenum_GLenum_GLint
#define glTexEnviv_INDEX 423
#define glTexEnviv_RETURN void
#define glTexEnviv_ARG_NAMES target, pname, params
#define glTexEnviv_ARG_EXPAND GLenum target, GLenum pname, const GLint * params
#define glTexEnviv_PACKED PACKED_void_GLenum_GLenum_const_GLint___GENPT__
#define glTexEnviv_INDEXED INDEXED_void_GLenum_GLenum_const_GLint___GENPT__
#define glTexEnviv_FORMAT FORMAT_void_GLenum_GLenum_const_GLint___GENPT__
#define glTexGend_INDEX 424
#define glTexGend_RETURN void
#define glTexGend_ARG_NAMES coord, pname, param
#define glTexGend_ARG_EXPAND GLenum coord, GLenum pname, GLdouble param
#define glTexGend_PACKED PACKED_void_GLenum_GLenum_GLdouble
#define glTexGend_INDEXED INDEXED_void_GLenum_GLenum_GLdouble
#define glTexGend_FORMAT FORMAT_void_GLenum_GLenum_GLdouble
#define glTexGendv_INDEX 425
#define glTexGendv_RETURN void
#define glTexGendv_ARG_NAMES coord, pname, params
#define glTexGendv_ARG_EXPAND GLenum coord, GLenum pname, const GLdouble * params
#define glTexGendv_PACKED PACKED_void_GLenum_GLenum_const_GLdouble___GENPT__
#define glTexGendv_INDEXED INDEXED_void_GLenum_GLenum_const_GLdouble___GENPT__
#define glTexGendv_FORMAT FORMAT_void_GLenum_GLenum_const_GLdouble___GENPT__
#define glTexGenf_INDEX 426
#define glTexGenf_RETURN void
#define glTexGenf_ARG_NAMES coord, pname, param
#define glTexGenf_ARG_EXPAND GLenum coord, GLenum pname, GLfloat param
#define glTexGenf_PACKED PACKED_void_GLenum_GLenum_GLfloat
#define glTexGenf_INDEXED INDEXED_void_GLenum_GLenum_GLfloat
#define glTexGenf_FORMAT FORMAT_void_GLenum_GLenum_GLfloat
#define glTexGenfv_INDEX 427
#define glTexGenfv_RETURN void
#define glTexGenfv_ARG_NAMES coord, pname, params
#define glTexGenfv_ARG_EXPAND GLenum coord, GLenum pname, const GLfloat * params
#define glTexGenfv_PACKED PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glTexGenfv_INDEXED INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glTexGenfv_FORMAT FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glTexGeni_INDEX 428
#define glTexGeni_RETURN void
#define glTexGeni_ARG_NAMES coord, pname, param
#define glTexGeni_ARG_EXPAND GLenum coord, GLenum pname, GLint param
#define glTexGeni_PACKED PACKED_void_GLenum_GLenum_GLint
#define glTexGeni_INDEXED INDEXED_void_GLenum_GLenum_GLint
#define glTexGeni_FORMAT FORMAT_void_GLenum_GLenum_GLint
#define glTexGeniv_INDEX 429
#define glTexGeniv_RETURN void
#define glTexGeniv_ARG_NAMES coord, pname, params
#define glTexGeniv_ARG_EXPAND GLenum coord, GLenum pname, const GLint * params
#define glTexGeniv_PACKED PACKED_void_GLenum_GLenum_const_GLint___GENPT__
#define glTexGeniv_INDEXED INDEXED_void_GLenum_GLenum_const_GLint___GENPT__
#define glTexGeniv_FORMAT FORMAT_void_GLenum_GLenum_const_GLint___GENPT__
#define glTexImage1D_INDEX 430
#define glTexImage1D_RETURN void
#define glTexImage1D_ARG_NAMES target, level, internalformat, width, border, format, type, pixels
#define glTexImage1D_ARG_EXPAND GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid * pixels
#define glTexImage1D_PACKED PACKED_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__
#define glTexImage1D_INDEXED INDEXED_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__
#define glTexImage1D_FORMAT FORMAT_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__
#define glTexImage2D_INDEX 431
#define glTexImage2D_RETURN void
#define glTexImage2D_ARG_NAMES target, level, internalformat, width, height, border, format, type, pixels
#define glTexImage2D_ARG_EXPAND GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels
#define glTexImage2D_PACKED PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__
#define glTexImage2D_INDEXED INDEXED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__
#define glTexImage2D_FORMAT FORMAT_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__
#define glTexImage3D_INDEX 432
#define glTexImage3D_RETURN void
#define glTexImage3D_ARG_NAMES target, level, internalformat, width, height, depth, border, format, type, pixels
#define glTexImage3D_ARG_EXPAND GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid * pixels
#define glTexImage3D_PACKED PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__
#define glTexImage3D_INDEXED INDEXED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__
#define glTexImage3D_FORMAT FORMAT_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__
#define glTexParameterf_INDEX 433
#define glTexParameterf_RETURN void
#define glTexParameterf_ARG_NAMES target, pname, param
#define glTexParameterf_ARG_EXPAND GLenum target, GLenum pname, GLfloat param
#define glTexParameterf_PACKED PACKED_void_GLenum_GLenum_GLfloat
#define glTexParameterf_INDEXED INDEXED_void_GLenum_GLenum_GLfloat
#define glTexParameterf_FORMAT FORMAT_void_GLenum_GLenum_GLfloat
#define glTexParameterfv_INDEX 434
#define glTexParameterfv_RETURN void
#define glTexParameterfv_ARG_NAMES target, pname, params
#define glTexParameterfv_ARG_EXPAND GLenum target, GLenum pname, const GLfloat * params
#define glTexParameterfv_PACKED PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glTexParameterfv_INDEXED INDEXED_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glTexParameterfv_FORMAT FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__
#define glTexParameteri_INDEX 435
#define glTexParameteri_RETURN void
#define glTexParameteri_ARG_NAMES target, pname, param
#define glTexParameteri_ARG_EXPAND GLenum target, GLenum pname, GLint param
#define glTexParameteri_PACKED PACKED_void_GLenum_GLenum_GLint
#define glTexParameteri_INDEXED INDEXED_void_GLenum_GLenum_GLint
#define glTexParameteri_FORMAT FORMAT_void_GLenum_GLenum_GLint
#define glTexParameteriv_INDEX 436
#define glTexParameteriv_RETURN void
#define glTexParameteriv_ARG_NAMES target, pname, params
#define glTexParameteriv_ARG_EXPAND GLenum target, GLenum pname, const GLint * params
#define glTexParameteriv_PACKED PACKED_void_GLenum_GLenum_const_GLint___GENPT__
#define glTexParameteriv_INDEXED INDEXED_void_GLenum_GLenum_const_GLint___GENPT__
#define glTexParameteriv_FORMAT FORMAT_void_GLenum_GLenum_const_GLint___GENPT__
#define glTexSubImage1D_INDEX 437
#define glTexSubImage1D_RETURN void
#define glTexSubImage1D_ARG_NAMES target, level, xoffset, width, format, type, pixels
#define glTexSubImage1D_ARG_EXPAND GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid * pixels
#define glTexSubImage1D_PACKED PACKED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glTexSubImage1D_INDEXED INDEXED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glTexSubImage1D_FORMAT FORMAT_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glTexSubImage2D_INDEX 438
#define glTexSubImage2D_RETURN void
#define glTexSubImage2D_ARG_NAMES target, level, xoffset, yoffset, width, height, format, type, pixels
#define glTexSubImage2D_ARG_EXPAND GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels
#define glTexSubImage2D_PACKED PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glTexSubImage2D_INDEXED INDEXED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glTexSubImage2D_FORMAT FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glTexSubImage3D_INDEX 439
#define glTexSubImage3D_RETURN void
#define glTexSubImage3D_ARG_NAMES target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels
#define glTexSubImage3D_ARG_EXPAND GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * pixels
#define glTexSubImage3D_PACKED PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glTexSubImage3D_INDEXED INDEXED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glTexSubImage3D_FORMAT FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__
#define glTranslated_INDEX 440
#define glTranslated_RETURN void
#define glTranslated_ARG_NAMES x, y, z
#define glTranslated_ARG_EXPAND GLdouble x, GLdouble y, GLdouble z
#define glTranslated_PACKED PACKED_void_GLdouble_GLdouble_GLdouble
#define glTranslated_INDEXED INDEXED_void_GLdouble_GLdouble_GLdouble
#define glTranslated_FORMAT FORMAT_void_GLdouble_GLdouble_GLdouble
#define glTranslatef_INDEX 441
#define glTranslatef_RETURN void
#define glTranslatef_ARG_NAMES x, y, z
#define glTranslatef_ARG_EXPAND GLfloat x, GLfloat y, GLfloat z
#define glTranslatef_PACKED PACKED_void_GLfloat_GLfloat_GLfloat
#define glTranslatef_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat
#define glTranslatef_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat
#define glUnmapBuffer_INDEX 442
#define glUnmapBuffer_RETURN GLboolean
#define glUnmapBuffer_ARG_NAMES target
#define glUnmapBuffer_ARG_EXPAND GLenum target
#define glUnmapBuffer_PACKED PACKED_GLboolean_GLenum
#define glUnmapBuffer_INDEXED INDEXED_GLboolean_GLenum
#define glUnmapBuffer_FORMAT FORMAT_GLboolean_GLenum
#define glVertex2d_INDEX 443
#define glVertex2d_RETURN void
#define glVertex2d_ARG_NAMES x, y
#define glVertex2d_ARG_EXPAND GLdouble x, GLdouble y
#define glVertex2d_PACKED PACKED_void_GLdouble_GLdouble
#define glVertex2d_INDEXED INDEXED_void_GLdouble_GLdouble
#define glVertex2d_FORMAT FORMAT_void_GLdouble_GLdouble
#define glVertex2dv_INDEX 444
#define glVertex2dv_RETURN void
#define glVertex2dv_ARG_NAMES v
#define glVertex2dv_ARG_EXPAND const GLdouble * v
#define glVertex2dv_PACKED PACKED_void_const_GLdouble___GENPT__
#define glVertex2dv_INDEXED INDEXED_void_const_GLdouble___GENPT__
#define glVertex2dv_FORMAT FORMAT_void_const_GLdouble___GENPT__
#define glVertex2f_INDEX 445
#define glVertex2f_RETURN void
#define glVertex2f_ARG_NAMES x, y
#define glVertex2f_ARG_EXPAND GLfloat x, GLfloat y
#define glVertex2f_PACKED PACKED_void_GLfloat_GLfloat
#define glVertex2f_INDEXED INDEXED_void_GLfloat_GLfloat
#define glVertex2f_FORMAT FORMAT_void_GLfloat_GLfloat
#define glVertex2fv_INDEX 446
#define glVertex2fv_RETURN void
#define glVertex2fv_ARG_NAMES v
#define glVertex2fv_ARG_EXPAND const GLfloat * v
#define glVertex2fv_PACKED PACKED_void_const_GLfloat___GENPT__
#define glVertex2fv_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glVertex2fv_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glVertex2i_INDEX 447
#define glVertex2i_RETURN void
#define glVertex2i_ARG_NAMES x, y
#define glVertex2i_ARG_EXPAND GLint x, GLint y
#define glVertex2i_PACKED PACKED_void_GLint_GLint
#define glVertex2i_INDEXED INDEXED_void_GLint_GLint
#define glVertex2i_FORMAT FORMAT_void_GLint_GLint
#define glVertex2iv_INDEX 448
#define glVertex2iv_RETURN void
#define glVertex2iv_ARG_NAMES v
#define glVertex2iv_ARG_EXPAND const GLint * v
#define glVertex2iv_PACKED PACKED_void_const_GLint___GENPT__
#define glVertex2iv_INDEXED INDEXED_void_const_GLint___GENPT__
#define glVertex2iv_FORMAT FORMAT_void_const_GLint___GENPT__
#define glVertex2s_INDEX 449
#define glVertex2s_RETURN void
#define glVertex2s_ARG_NAMES x, y
#define glVertex2s_ARG_EXPAND GLshort x, GLshort y
#define glVertex2s_PACKED PACKED_void_GLshort_GLshort
#define glVertex2s_INDEXED INDEXED_void_GLshort_GLshort
#define glVertex2s_FORMAT FORMAT_void_GLshort_GLshort
#define glVertex2sv_INDEX 450
#define glVertex2sv_RETURN void
#define glVertex2sv_ARG_NAMES v
#define glVertex2sv_ARG_EXPAND const GLshort * v
#define glVertex2sv_PACKED PACKED_void_const_GLshort___GENPT__
#define glVertex2sv_INDEXED INDEXED_void_const_GLshort___GENPT__
#define glVertex2sv_FORMAT FORMAT_void_const_GLshort___GENPT__
#define glVertex3d_INDEX 451
#define glVertex3d_RETURN void
#define glVertex3d_ARG_NAMES x, y, z
#define glVertex3d_ARG_EXPAND GLdouble x, GLdouble y, GLdouble z
#define glVertex3d_PACKED PACKED_void_GLdouble_GLdouble_GLdouble
#define glVertex3d_INDEXED INDEXED_void_GLdouble_GLdouble_GLdouble
#define glVertex3d_FORMAT FORMAT_void_GLdouble_GLdouble_GLdouble
#define glVertex3dv_INDEX 452
#define glVertex3dv_RETURN void
#define glVertex3dv_ARG_NAMES v
#define glVertex3dv_ARG_EXPAND const GLdouble * v
#define glVertex3dv_PACKED PACKED_void_const_GLdouble___GENPT__
#define glVertex3dv_INDEXED INDEXED_void_const_GLdouble___GENPT__
#define glVertex3dv_FORMAT FORMAT_void_const_GLdouble___GENPT__
#define glVertex3f_INDEX 453
#define glVertex3f_RETURN void
#define glVertex3f_ARG_NAMES x, y, z
#define glVertex3f_ARG_EXPAND GLfloat x, GLfloat y, GLfloat z
#define glVertex3f_PACKED PACKED_void_GLfloat_GLfloat_GLfloat
#define glVertex3f_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat
#define glVertex3f_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat
#define glVertex3fv_INDEX 454
#define glVertex3fv_RETURN void
#define glVertex3fv_ARG_NAMES v
#define glVertex3fv_ARG_EXPAND const GLfloat * v
#define glVertex3fv_PACKED PACKED_void_const_GLfloat___GENPT__
#define glVertex3fv_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glVertex3fv_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glVertex3i_INDEX 455
#define glVertex3i_RETURN void
#define glVertex3i_ARG_NAMES x, y, z
#define glVertex3i_ARG_EXPAND GLint x, GLint y, GLint z
#define glVertex3i_PACKED PACKED_void_GLint_GLint_GLint
#define glVertex3i_INDEXED INDEXED_void_GLint_GLint_GLint
#define glVertex3i_FORMAT FORMAT_void_GLint_GLint_GLint
#define glVertex3iv_INDEX 456
#define glVertex3iv_RETURN void
#define glVertex3iv_ARG_NAMES v
#define glVertex3iv_ARG_EXPAND const GLint * v
#define glVertex3iv_PACKED PACKED_void_const_GLint___GENPT__
#define glVertex3iv_INDEXED INDEXED_void_const_GLint___GENPT__
#define glVertex3iv_FORMAT FORMAT_void_const_GLint___GENPT__
#define glVertex3s_INDEX 457
#define glVertex3s_RETURN void
#define glVertex3s_ARG_NAMES x, y, z
#define glVertex3s_ARG_EXPAND GLshort x, GLshort y, GLshort z
#define glVertex3s_PACKED PACKED_void_GLshort_GLshort_GLshort
#define glVertex3s_INDEXED INDEXED_void_GLshort_GLshort_GLshort
#define glVertex3s_FORMAT FORMAT_void_GLshort_GLshort_GLshort
#define glVertex3sv_INDEX 458
#define glVertex3sv_RETURN void
#define glVertex3sv_ARG_NAMES v
#define glVertex3sv_ARG_EXPAND const GLshort * v
#define glVertex3sv_PACKED PACKED_void_const_GLshort___GENPT__
#define glVertex3sv_INDEXED INDEXED_void_const_GLshort___GENPT__
#define glVertex3sv_FORMAT FORMAT_void_const_GLshort___GENPT__
#define glVertex4d_INDEX 459
#define glVertex4d_RETURN void
#define glVertex4d_ARG_NAMES x, y, z, w
#define glVertex4d_ARG_EXPAND GLdouble x, GLdouble y, GLdouble z, GLdouble w
#define glVertex4d_PACKED PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble
#define glVertex4d_INDEXED INDEXED_void_GLdouble_GLdouble_GLdouble_GLdouble
#define glVertex4d_FORMAT FORMAT_void_GLdouble_GLdouble_GLdouble_GLdouble
#define glVertex4dv_INDEX 460
#define glVertex4dv_RETURN void
#define glVertex4dv_ARG_NAMES v
#define glVertex4dv_ARG_EXPAND const GLdouble * v
#define glVertex4dv_PACKED PACKED_void_const_GLdouble___GENPT__
#define glVertex4dv_INDEXED INDEXED_void_const_GLdouble___GENPT__
#define glVertex4dv_FORMAT FORMAT_void_const_GLdouble___GENPT__
#define glVertex4f_INDEX 461
#define glVertex4f_RETURN void
#define glVertex4f_ARG_NAMES x, y, z, w
#define glVertex4f_ARG_EXPAND GLfloat x, GLfloat y, GLfloat z, GLfloat w
#define glVertex4f_PACKED PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glVertex4f_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glVertex4f_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat
#define glVertex4fv_INDEX 462
#define glVertex4fv_RETURN void
#define glVertex4fv_ARG_NAMES v
#define glVertex4fv_ARG_EXPAND const GLfloat * v
#define glVertex4fv_PACKED PACKED_void_const_GLfloat___GENPT__
#define glVertex4fv_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glVertex4fv_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glVertex4i_INDEX 463
#define glVertex4i_RETURN void
#define glVertex4i_ARG_NAMES x, y, z, w
#define glVertex4i_ARG_EXPAND GLint x, GLint y, GLint z, GLint w
#define glVertex4i_PACKED PACKED_void_GLint_GLint_GLint_GLint
#define glVertex4i_INDEXED INDEXED_void_GLint_GLint_GLint_GLint
#define glVertex4i_FORMAT FORMAT_void_GLint_GLint_GLint_GLint
#define glVertex4iv_INDEX 464
#define glVertex4iv_RETURN void
#define glVertex4iv_ARG_NAMES v
#define glVertex4iv_ARG_EXPAND const GLint * v
#define glVertex4iv_PACKED PACKED_void_const_GLint___GENPT__
#define glVertex4iv_INDEXED INDEXED_void_const_GLint___GENPT__
#define glVertex4iv_FORMAT FORMAT_void_const_GLint___GENPT__
#define glVertex4s_INDEX 465
#define glVertex4s_RETURN void
#define glVertex4s_ARG_NAMES x, y, z, w
#define glVertex4s_ARG_EXPAND GLshort x, GLshort y, GLshort z, GLshort w
#define glVertex4s_PACKED PACKED_void_GLshort_GLshort_GLshort_GLshort
#define glVertex4s_INDEXED INDEXED_void_GLshort_GLshort_GLshort_GLshort
#define glVertex4s_FORMAT FORMAT_void_GLshort_GLshort_GLshort_GLshort
#define glVertex4sv_INDEX 466
#define glVertex4sv_RETURN void
#define glVertex4sv_ARG_NAMES v
#define glVertex4sv_ARG_EXPAND const GLshort * v
#define glVertex4sv_PACKED PACKED_void_const_GLshort___GENPT__
#define glVertex4sv_INDEXED INDEXED_void_const_GLshort___GENPT__
#define glVertex4sv_FORMAT FORMAT_void_const_GLshort___GENPT__
#define glVertexPointer_INDEX 467
#define glVertexPointer_RETURN void
#define glVertexPointer_ARG_NAMES size, type, stride, pointer
#define glVertexPointer_ARG_EXPAND GLint size, GLenum type, GLsizei stride, const GLvoid * pointer
#define glVertexPointer_PACKED PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__
#define glVertexPointer_INDEXED INDEXED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__
#define glVertexPointer_FORMAT FORMAT_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__
#define glViewport_INDEX 468
#define glViewport_RETURN void
#define glViewport_ARG_NAMES x, y, width, height
#define glViewport_ARG_EXPAND GLint x, GLint y, GLsizei width, GLsizei height
#define glViewport_PACKED PACKED_void_GLint_GLint_GLsizei_GLsizei
#define glViewport_INDEXED INDEXED_void_GLint_GLint_GLsizei_GLsizei
#define glViewport_FORMAT FORMAT_void_GLint_GLint_GLsizei_GLsizei
#define glWindowPos2d_INDEX 469
#define glWindowPos2d_RETURN void
#define glWindowPos2d_ARG_NAMES x, y
#define glWindowPos2d_ARG_EXPAND GLdouble x, GLdouble y
#define glWindowPos2d_PACKED PACKED_void_GLdouble_GLdouble
#define glWindowPos2d_INDEXED INDEXED_void_GLdouble_GLdouble
#define glWindowPos2d_FORMAT FORMAT_void_GLdouble_GLdouble
#define glWindowPos2dv_INDEX 470
#define glWindowPos2dv_RETURN void
#define glWindowPos2dv_ARG_NAMES v
#define glWindowPos2dv_ARG_EXPAND const GLdouble * v
#define glWindowPos2dv_PACKED PACKED_void_const_GLdouble___GENPT__
#define glWindowPos2dv_INDEXED INDEXED_void_const_GLdouble___GENPT__
#define glWindowPos2dv_FORMAT FORMAT_void_const_GLdouble___GENPT__
#define glWindowPos2f_INDEX 471
#define glWindowPos2f_RETURN void
#define glWindowPos2f_ARG_NAMES x, y
#define glWindowPos2f_ARG_EXPAND GLfloat x, GLfloat y
#define glWindowPos2f_PACKED PACKED_void_GLfloat_GLfloat
#define glWindowPos2f_INDEXED INDEXED_void_GLfloat_GLfloat
#define glWindowPos2f_FORMAT FORMAT_void_GLfloat_GLfloat
#define glWindowPos2fv_INDEX 472
#define glWindowPos2fv_RETURN void
#define glWindowPos2fv_ARG_NAMES v
#define glWindowPos2fv_ARG_EXPAND const GLfloat * v
#define glWindowPos2fv_PACKED PACKED_void_const_GLfloat___GENPT__
#define glWindowPos2fv_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glWindowPos2fv_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glWindowPos2i_INDEX 473
#define glWindowPos2i_RETURN void
#define glWindowPos2i_ARG_NAMES x, y
#define glWindowPos2i_ARG_EXPAND GLint x, GLint y
#define glWindowPos2i_PACKED PACKED_void_GLint_GLint
#define glWindowPos2i_INDEXED INDEXED_void_GLint_GLint
#define glWindowPos2i_FORMAT FORMAT_void_GLint_GLint
#define glWindowPos2iv_INDEX 474
#define glWindowPos2iv_RETURN void
#define glWindowPos2iv_ARG_NAMES v
#define glWindowPos2iv_ARG_EXPAND const GLint * v
#define glWindowPos2iv_PACKED PACKED_void_const_GLint___GENPT__
#define glWindowPos2iv_INDEXED INDEXED_void_const_GLint___GENPT__
#define glWindowPos2iv_FORMAT FORMAT_void_const_GLint___GENPT__
#define glWindowPos2s_INDEX 475
#define glWindowPos2s_RETURN void
#define glWindowPos2s_ARG_NAMES x, y
#define glWindowPos2s_ARG_EXPAND GLshort x, GLshort y
#define glWindowPos2s_PACKED PACKED_void_GLshort_GLshort
#define glWindowPos2s_INDEXED INDEXED_void_GLshort_GLshort
#define glWindowPos2s_FORMAT FORMAT_void_GLshort_GLshort
#define glWindowPos2sv_INDEX 476
#define glWindowPos2sv_RETURN void
#define glWindowPos2sv_ARG_NAMES v
#define glWindowPos2sv_ARG_EXPAND const GLshort * v
#define glWindowPos2sv_PACKED PACKED_void_const_GLshort___GENPT__
#define glWindowPos2sv_INDEXED INDEXED_void_const_GLshort___GENPT__
#define glWindowPos2sv_FORMAT FORMAT_void_const_GLshort___GENPT__
#define glWindowPos3d_INDEX 477
#define glWindowPos3d_RETURN void
#define glWindowPos3d_ARG_NAMES x, y, z
#define glWindowPos3d_ARG_EXPAND GLdouble x, GLdouble y, GLdouble z
#define glWindowPos3d_PACKED PACKED_void_GLdouble_GLdouble_GLdouble
#define glWindowPos3d_INDEXED INDEXED_void_GLdouble_GLdouble_GLdouble
#define glWindowPos3d_FORMAT FORMAT_void_GLdouble_GLdouble_GLdouble
#define glWindowPos3dv_INDEX 478
#define glWindowPos3dv_RETURN void
#define glWindowPos3dv_ARG_NAMES v
#define glWindowPos3dv_ARG_EXPAND const GLdouble * v
#define glWindowPos3dv_PACKED PACKED_void_const_GLdouble___GENPT__
#define glWindowPos3dv_INDEXED INDEXED_void_const_GLdouble___GENPT__
#define glWindowPos3dv_FORMAT FORMAT_void_const_GLdouble___GENPT__
#define glWindowPos3f_INDEX 479
#define glWindowPos3f_RETURN void
#define glWindowPos3f_ARG_NAMES x, y, z
#define glWindowPos3f_ARG_EXPAND GLfloat x, GLfloat y, GLfloat z
#define glWindowPos3f_PACKED PACKED_void_GLfloat_GLfloat_GLfloat
#define glWindowPos3f_INDEXED INDEXED_void_GLfloat_GLfloat_GLfloat
#define glWindowPos3f_FORMAT FORMAT_void_GLfloat_GLfloat_GLfloat
#define glWindowPos3fv_INDEX 480
#define glWindowPos3fv_RETURN void
#define glWindowPos3fv_ARG_NAMES v
#define glWindowPos3fv_ARG_EXPAND const GLfloat * v
#define glWindowPos3fv_PACKED PACKED_void_const_GLfloat___GENPT__
#define glWindowPos3fv_INDEXED INDEXED_void_const_GLfloat___GENPT__
#define glWindowPos3fv_FORMAT FORMAT_void_const_GLfloat___GENPT__
#define glWindowPos3i_INDEX 481
#define glWindowPos3i_RETURN void
#define glWindowPos3i_ARG_NAMES x, y, z
#define glWindowPos3i_ARG_EXPAND GLint x, GLint y, GLint z
#define glWindowPos3i_PACKED PACKED_void_GLint_GLint_GLint
#define glWindowPos3i_INDEXED INDEXED_void_GLint_GLint_GLint
#define glWindowPos3i_FORMAT FORMAT_void_GLint_GLint_GLint
#define glWindowPos3iv_INDEX 482
#define glWindowPos3iv_RETURN void
#define glWindowPos3iv_ARG_NAMES v
#define glWindowPos3iv_ARG_EXPAND const GLint * v
#define glWindowPos3iv_PACKED PACKED_void_const_GLint___GENPT__
#define glWindowPos3iv_INDEXED INDEXED_void_const_GLint___GENPT__
#define glWindowPos3iv_FORMAT FORMAT_void_const_GLint___GENPT__
#define glWindowPos3s_INDEX 483
#define glWindowPos3s_RETURN void
#define glWindowPos3s_ARG_NAMES x, y, z
#define glWindowPos3s_ARG_EXPAND GLshort x, GLshort y, GLshort z
#define glWindowPos3s_PACKED PACKED_void_GLshort_GLshort_GLshort
#define glWindowPos3s_INDEXED INDEXED_void_GLshort_GLshort_GLshort
#define glWindowPos3s_FORMAT FORMAT_void_GLshort_GLshort_GLshort
#define glWindowPos3sv_INDEX 484
#define glWindowPos3sv_RETURN void
#define glWindowPos3sv_ARG_NAMES v
#define glWindowPos3sv_ARG_EXPAND const GLshort * v
#define glWindowPos3sv_PACKED PACKED_void_const_GLshort___GENPT__
#define glWindowPos3sv_INDEXED INDEXED_void_const_GLshort___GENPT__
#define glWindowPos3sv_FORMAT FORMAT_void_const_GLshort___GENPT__
#define glXBindHyperpipeSGIX_INDEX 485
#define glXBindHyperpipeSGIX_RETURN int
#define glXBindHyperpipeSGIX_ARG_NAMES dpy, hpId
#define glXBindHyperpipeSGIX_ARG_EXPAND Display * dpy, int hpId
#define glXBindHyperpipeSGIX_PACKED PACKED_int_Display___GENPT___int
#define glXBindHyperpipeSGIX_INDEXED INDEXED_int_Display___GENPT___int
#define glXBindHyperpipeSGIX_FORMAT FORMAT_int_Display___GENPT___int
#define glXBindSwapBarrierSGIX_INDEX 486
#define glXBindSwapBarrierSGIX_RETURN void
#define glXBindSwapBarrierSGIX_ARG_NAMES window, barrier
#define glXBindSwapBarrierSGIX_ARG_EXPAND uint32_t window, uint32_t barrier
#define glXBindSwapBarrierSGIX_PACKED PACKED_void_uint32_t_uint32_t
#define glXBindSwapBarrierSGIX_INDEXED INDEXED_void_uint32_t_uint32_t
#define glXBindSwapBarrierSGIX_FORMAT FORMAT_void_uint32_t_uint32_t
#define glXChangeDrawableAttributes_INDEX 487
#define glXChangeDrawableAttributes_RETURN void
#define glXChangeDrawableAttributes_ARG_NAMES drawable
#define glXChangeDrawableAttributes_ARG_EXPAND uint32_t drawable
#define glXChangeDrawableAttributes_PACKED PACKED_void_uint32_t
#define glXChangeDrawableAttributes_INDEXED INDEXED_void_uint32_t
#define glXChangeDrawableAttributes_FORMAT FORMAT_void_uint32_t
#define glXChangeDrawableAttributesSGIX_INDEX 488
#define glXChangeDrawableAttributesSGIX_RETURN void
#define glXChangeDrawableAttributesSGIX_ARG_NAMES drawable
#define glXChangeDrawableAttributesSGIX_ARG_EXPAND uint32_t drawable
#define glXChangeDrawableAttributesSGIX_PACKED PACKED_void_uint32_t
#define glXChangeDrawableAttributesSGIX_INDEXED INDEXED_void_uint32_t
#define glXChangeDrawableAttributesSGIX_FORMAT FORMAT_void_uint32_t
#define glXChooseFBConfig_INDEX 489
#define glXChooseFBConfig_RETURN GLXFBConfig *
#define glXChooseFBConfig_ARG_NAMES dpy, screen, attrib_list, nelements
#define glXChooseFBConfig_ARG_EXPAND Display * dpy, int screen, const int * attrib_list, int * nelements
#define glXChooseFBConfig_PACKED PACKED_GLXFBConfig___GENPT___Display___GENPT___int_const_int___GENPT___int___GENPT__
#define glXChooseFBConfig_INDEXED INDEXED_GLXFBConfig___GENPT___Display___GENPT___int_const_int___GENPT___int___GENPT__
#define glXChooseFBConfig_FORMAT FORMAT_GLXFBConfig___GENPT___Display___GENPT___int_const_int___GENPT___int___GENPT__
#define glXChooseVisual_INDEX 490
#define glXChooseVisual_RETURN XVisualInfo *
#define glXChooseVisual_ARG_NAMES dpy, screen, attribList
#define glXChooseVisual_ARG_EXPAND Display * dpy, int screen, int * attribList
#define glXChooseVisual_PACKED PACKED_XVisualInfo___GENPT___Display___GENPT___int_int___GENPT__
#define glXChooseVisual_INDEXED INDEXED_XVisualInfo___GENPT___Display___GENPT___int_int___GENPT__
#define glXChooseVisual_FORMAT FORMAT_XVisualInfo___GENPT___Display___GENPT___int_int___GENPT__
#define glXClientInfo_INDEX 491
#define glXClientInfo_RETURN void
#define glXClientInfo_ARG_NAMES 
#define glXClientInfo_ARG_EXPAND 
#define glXClientInfo_PACKED PACKED_void
#define glXClientInfo_INDEXED INDEXED_void
#define glXClientInfo_FORMAT FORMAT_void
#define glXCopyContext_INDEX 492
#define glXCopyContext_RETURN void
#define glXCopyContext_ARG_NAMES dpy, src, dst, mask
#define glXCopyContext_ARG_EXPAND Display * dpy, GLXContext src, GLXContext dst, unsigned long mask
#define glXCopyContext_PACKED PACKED_void_Display___GENPT___GLXContext_GLXContext_unsigned_long
#define glXCopyContext_INDEXED INDEXED_void_Display___GENPT___GLXContext_GLXContext_unsigned_long
#define glXCopyContext_FORMAT FORMAT_void_Display___GENPT___GLXContext_GLXContext_unsigned_long
#define glXCreateContext_INDEX 493
#define glXCreateContext_RETURN GLXContext
#define glXCreateContext_ARG_NAMES dpy, vis, shareList, direct
#define glXCreateContext_ARG_EXPAND Display * dpy, XVisualInfo * vis, GLXContext shareList, Bool direct
#define glXCreateContext_PACKED PACKED_GLXContext_Display___GENPT___XVisualInfo___GENPT___GLXContext_Bool
#define glXCreateContext_INDEXED INDEXED_GLXContext_Display___GENPT___XVisualInfo___GENPT___GLXContext_Bool
#define glXCreateContext_FORMAT FORMAT_GLXContext_Display___GENPT___XVisualInfo___GENPT___GLXContext_Bool
#define glXCreateContextWithConfigSGIX_INDEX 494
#define glXCreateContextWithConfigSGIX_RETURN void
#define glXCreateContextWithConfigSGIX_ARG_NAMES gc_id, screen, config, share_list
#define glXCreateContextWithConfigSGIX_ARG_EXPAND uint32_t gc_id, uint32_t screen, uint32_t config, uint32_t share_list
#define glXCreateContextWithConfigSGIX_PACKED PACKED_void_uint32_t_uint32_t_uint32_t_uint32_t
#define glXCreateContextWithConfigSGIX_INDEXED INDEXED_void_uint32_t_uint32_t_uint32_t_uint32_t
#define glXCreateContextWithConfigSGIX_FORMAT FORMAT_void_uint32_t_uint32_t_uint32_t_uint32_t
#define glXCreateGLXPbufferSGIX_INDEX 495
#define glXCreateGLXPbufferSGIX_RETURN void
#define glXCreateGLXPbufferSGIX_ARG_NAMES config, pbuffer
#define glXCreateGLXPbufferSGIX_ARG_EXPAND uint32_t config, uint32_t pbuffer
#define glXCreateGLXPbufferSGIX_PACKED PACKED_void_uint32_t_uint32_t
#define glXCreateGLXPbufferSGIX_INDEXED INDEXED_void_uint32_t_uint32_t
#define glXCreateGLXPbufferSGIX_FORMAT FORMAT_void_uint32_t_uint32_t
#define glXCreateGLXPixmap_INDEX 496
#define glXCreateGLXPixmap_RETURN GLXPixmap
#define glXCreateGLXPixmap_ARG_NAMES dpy, visual, pixmap
#define glXCreateGLXPixmap_ARG_EXPAND Display * dpy, XVisualInfo * visual, Pixmap pixmap
#define glXCreateGLXPixmap_PACKED PACKED_GLXPixmap_Display___GENPT___XVisualInfo___GENPT___Pixmap
#define glXCreateGLXPixmap_INDEXED INDEXED_GLXPixmap_Display___GENPT___XVisualInfo___GENPT___Pixmap
#define glXCreateGLXPixmap_FORMAT FORMAT_GLXPixmap_Display___GENPT___XVisualInfo___GENPT___Pixmap
#define glXCreateGLXPixmapWithConfigSGIX_INDEX 497
#define glXCreateGLXPixmapWithConfigSGIX_RETURN void
#define glXCreateGLXPixmapWithConfigSGIX_ARG_NAMES config, pixmap, glxpixmap
#define glXCreateGLXPixmapWithConfigSGIX_ARG_EXPAND uint32_t config, uint32_t pixmap, uint32_t glxpixmap
#define glXCreateGLXPixmapWithConfigSGIX_PACKED PACKED_void_uint32_t_uint32_t_uint32_t
#define glXCreateGLXPixmapWithConfigSGIX_INDEXED INDEXED_void_uint32_t_uint32_t_uint32_t
#define glXCreateGLXPixmapWithConfigSGIX_FORMAT FORMAT_void_uint32_t_uint32_t_uint32_t
#define glXCreateGLXVideoSourceSGIX_INDEX 498
#define glXCreateGLXVideoSourceSGIX_RETURN void
#define glXCreateGLXVideoSourceSGIX_ARG_NAMES dpy, screen, server, path, class, node
#define glXCreateGLXVideoSourceSGIX_ARG_EXPAND Display * dpy, uint32_t screen, uint32_t server, uint32_t path, uint32_t class, uint32_t node
#define glXCreateGLXVideoSourceSGIX_PACKED PACKED_void_Display___GENPT___uint32_t_uint32_t_uint32_t_uint32_t_uint32_t
#define glXCreateGLXVideoSourceSGIX_INDEXED INDEXED_void_Display___GENPT___uint32_t_uint32_t_uint32_t_uint32_t_uint32_t
#define glXCreateGLXVideoSourceSGIX_FORMAT FORMAT_void_Display___GENPT___uint32_t_uint32_t_uint32_t_uint32_t_uint32_t
#define glXCreateNewContext_INDEX 499
#define glXCreateNewContext_RETURN GLXContext
#define glXCreateNewContext_ARG_NAMES dpy, config, render_type, share_list, direct
#define glXCreateNewContext_ARG_EXPAND Display * dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct
#define glXCreateNewContext_PACKED PACKED_GLXContext_Display___GENPT___GLXFBConfig_int_GLXContext_Bool
#define glXCreateNewContext_INDEXED INDEXED_GLXContext_Display___GENPT___GLXFBConfig_int_GLXContext_Bool
#define glXCreateNewContext_FORMAT FORMAT_GLXContext_Display___GENPT___GLXFBConfig_int_GLXContext_Bool
#define glXCreatePbuffer_INDEX 500
#define glXCreatePbuffer_RETURN GLXPbuffer
#define glXCreatePbuffer_ARG_NAMES dpy, config, attrib_list
#define glXCreatePbuffer_ARG_EXPAND Display * dpy, GLXFBConfig config, const int * attrib_list
#define glXCreatePbuffer_PACKED PACKED_GLXPbuffer_Display___GENPT___GLXFBConfig_const_int___GENPT__
#define glXCreatePbuffer_INDEXED INDEXED_GLXPbuffer_Display___GENPT___GLXFBConfig_const_int___GENPT__
#define glXCreatePbuffer_FORMAT FORMAT_GLXPbuffer_Display___GENPT___GLXFBConfig_const_int___GENPT__
#define glXCreatePixmap_INDEX 501
#define glXCreatePixmap_RETURN GLXPixmap
#define glXCreatePixmap_ARG_NAMES dpy, config, pixmap, attrib_list
#define glXCreatePixmap_ARG_EXPAND Display * dpy, GLXFBConfig config, Pixmap pixmap, const int * attrib_list
#define glXCreatePixmap_PACKED PACKED_GLXPixmap_Display___GENPT___GLXFBConfig_Pixmap_const_int___GENPT__
#define glXCreatePixmap_INDEXED INDEXED_GLXPixmap_Display___GENPT___GLXFBConfig_Pixmap_const_int___GENPT__
#define glXCreatePixmap_FORMAT FORMAT_GLXPixmap_Display___GENPT___GLXFBConfig_Pixmap_const_int___GENPT__
#define glXCreateWindow_INDEX 502
#define glXCreateWindow_RETURN GLXWindow
#define glXCreateWindow_ARG_NAMES dpy, config, win, attrib_list
#define glXCreateWindow_ARG_EXPAND Display * dpy, GLXFBConfig config, Window win, const int * attrib_list
#define glXCreateWindow_PACKED PACKED_GLXWindow_Display___GENPT___GLXFBConfig_Window_const_int___GENPT__
#define glXCreateWindow_INDEXED INDEXED_GLXWindow_Display___GENPT___GLXFBConfig_Window_const_int___GENPT__
#define glXCreateWindow_FORMAT FORMAT_GLXWindow_Display___GENPT___GLXFBConfig_Window_const_int___GENPT__
#define glXDestroyContext_INDEX 503
#define glXDestroyContext_RETURN void
#define glXDestroyContext_ARG_NAMES dpy, ctx
#define glXDestroyContext_ARG_EXPAND Display * dpy, GLXContext ctx
#define glXDestroyContext_PACKED PACKED_void_Display___GENPT___GLXContext
#define glXDestroyContext_INDEXED INDEXED_void_Display___GENPT___GLXContext
#define glXDestroyContext_FORMAT FORMAT_void_Display___GENPT___GLXContext
#define glXDestroyGLXPbufferSGIX_INDEX 504
#define glXDestroyGLXPbufferSGIX_RETURN void
#define glXDestroyGLXPbufferSGIX_ARG_NAMES pbuffer
#define glXDestroyGLXPbufferSGIX_ARG_EXPAND uint32_t pbuffer
#define glXDestroyGLXPbufferSGIX_PACKED PACKED_void_uint32_t
#define glXDestroyGLXPbufferSGIX_INDEXED INDEXED_void_uint32_t
#define glXDestroyGLXPbufferSGIX_FORMAT FORMAT_void_uint32_t
#define glXDestroyGLXPixmap_INDEX 505
#define glXDestroyGLXPixmap_RETURN void
#define glXDestroyGLXPixmap_ARG_NAMES dpy, pixmap
#define glXDestroyGLXPixmap_ARG_EXPAND Display * dpy, GLXPixmap pixmap
#define glXDestroyGLXPixmap_PACKED PACKED_void_Display___GENPT___GLXPixmap
#define glXDestroyGLXPixmap_INDEXED INDEXED_void_Display___GENPT___GLXPixmap
#define glXDestroyGLXPixmap_FORMAT FORMAT_void_Display___GENPT___GLXPixmap
#define glXDestroyGLXVideoSourceSGIX_INDEX 506
#define glXDestroyGLXVideoSourceSGIX_RETURN void
#define glXDestroyGLXVideoSourceSGIX_ARG_NAMES dpy, glxvideosource
#define glXDestroyGLXVideoSourceSGIX_ARG_EXPAND Display * dpy, uint32_t glxvideosource
#define glXDestroyGLXVideoSourceSGIX_PACKED PACKED_void_Display___GENPT___uint32_t
#define glXDestroyGLXVideoSourceSGIX_INDEXED INDEXED_void_Display___GENPT___uint32_t
#define glXDestroyGLXVideoSourceSGIX_FORMAT FORMAT_void_Display___GENPT___uint32_t
#define glXDestroyHyperpipeConfigSGIX_INDEX 507
#define glXDestroyHyperpipeConfigSGIX_RETURN int
#define glXDestroyHyperpipeConfigSGIX_ARG_NAMES dpy, hpId
#define glXDestroyHyperpipeConfigSGIX_ARG_EXPAND Display * dpy, int hpId
#define glXDestroyHyperpipeConfigSGIX_PACKED PACKED_int_Display___GENPT___int
#define glXDestroyHyperpipeConfigSGIX_INDEXED INDEXED_int_Display___GENPT___int
#define glXDestroyHyperpipeConfigSGIX_FORMAT FORMAT_int_Display___GENPT___int
#define glXDestroyPbuffer_INDEX 508
#define glXDestroyPbuffer_RETURN void
#define glXDestroyPbuffer_ARG_NAMES dpy, pbuf
#define glXDestroyPbuffer_ARG_EXPAND Display * dpy, GLXPbuffer pbuf
#define glXDestroyPbuffer_PACKED PACKED_void_Display___GENPT___GLXPbuffer
#define glXDestroyPbuffer_INDEXED INDEXED_void_Display___GENPT___GLXPbuffer
#define glXDestroyPbuffer_FORMAT FORMAT_void_Display___GENPT___GLXPbuffer
#define glXDestroyPixmap_INDEX 509
#define glXDestroyPixmap_RETURN void
#define glXDestroyPixmap_ARG_NAMES dpy, pixmap
#define glXDestroyPixmap_ARG_EXPAND Display * dpy, GLXPixmap pixmap
#define glXDestroyPixmap_PACKED PACKED_void_Display___GENPT___GLXPixmap
#define glXDestroyPixmap_INDEXED INDEXED_void_Display___GENPT___GLXPixmap
#define glXDestroyPixmap_FORMAT FORMAT_void_Display___GENPT___GLXPixmap
#define glXDestroyWindow_INDEX 510
#define glXDestroyWindow_RETURN void
#define glXDestroyWindow_ARG_NAMES dpy, win
#define glXDestroyWindow_ARG_EXPAND Display * dpy, GLXWindow win
#define glXDestroyWindow_PACKED PACKED_void_Display___GENPT___GLXWindow
#define glXDestroyWindow_INDEXED INDEXED_void_Display___GENPT___GLXWindow
#define glXDestroyWindow_FORMAT FORMAT_void_Display___GENPT___GLXWindow
#define glXGetClientString_INDEX 511
#define glXGetClientString_RETURN const char *
#define glXGetClientString_ARG_NAMES display, name
#define glXGetClientString_ARG_EXPAND Display * display, int name
#define glXGetClientString_PACKED PACKED_const_char___GENPT___Display___GENPT___int
#define glXGetClientString_INDEXED INDEXED_const_char___GENPT___Display___GENPT___int
#define glXGetClientString_FORMAT FORMAT_const_char___GENPT___Display___GENPT___int
#define glXGetConfig_INDEX 512
#define glXGetConfig_RETURN int
#define glXGetConfig_ARG_NAMES display, visual, attribute, value
#define glXGetConfig_ARG_EXPAND Display * display, XVisualInfo * visual, int attribute, int * value
#define glXGetConfig_PACKED PACKED_int_Display___GENPT___XVisualInfo___GENPT___int_int___GENPT__
#define glXGetConfig_INDEXED INDEXED_int_Display___GENPT___XVisualInfo___GENPT___int_int___GENPT__
#define glXGetConfig_FORMAT FORMAT_int_Display___GENPT___XVisualInfo___GENPT___int_int___GENPT__
#define glXGetCurrentContext_INDEX 513
#define glXGetCurrentContext_RETURN GLXContext
#define glXGetCurrentContext_ARG_NAMES 
#define glXGetCurrentContext_ARG_EXPAND 
#define glXGetCurrentContext_PACKED PACKED_GLXContext
#define glXGetCurrentContext_INDEXED INDEXED_GLXContext
#define glXGetCurrentContext_FORMAT FORMAT_GLXContext
#define glXGetCurrentDisplay_INDEX 514
#define glXGetCurrentDisplay_RETURN Display *
#define glXGetCurrentDisplay_ARG_NAMES 
#define glXGetCurrentDisplay_ARG_EXPAND 
#define glXGetCurrentDisplay_PACKED PACKED_Display___GENPT__
#define glXGetCurrentDisplay_INDEXED INDEXED_Display___GENPT__
#define glXGetCurrentDisplay_FORMAT FORMAT_Display___GENPT__
#define glXGetCurrentDrawable_INDEX 515
#define glXGetCurrentDrawable_RETURN GLXDrawable
#define glXGetCurrentDrawable_ARG_NAMES 
#define glXGetCurrentDrawable_ARG_EXPAND 
#define glXGetCurrentDrawable_PACKED PACKED_GLXDrawable
#define glXGetCurrentDrawable_INDEXED INDEXED_GLXDrawable
#define glXGetCurrentDrawable_FORMAT FORMAT_GLXDrawable
#define glXGetCurrentReadDrawable_INDEX 516
#define glXGetCurrentReadDrawable_RETURN GLXDrawable
#define glXGetCurrentReadDrawable_ARG_NAMES 
#define glXGetCurrentReadDrawable_ARG_EXPAND 
#define glXGetCurrentReadDrawable_PACKED PACKED_GLXDrawable
#define glXGetCurrentReadDrawable_INDEXED INDEXED_GLXDrawable
#define glXGetCurrentReadDrawable_FORMAT FORMAT_GLXDrawable
#define glXGetDrawableAttributes_INDEX 517
#define glXGetDrawableAttributes_RETURN void
#define glXGetDrawableAttributes_ARG_NAMES drawable
#define glXGetDrawableAttributes_ARG_EXPAND uint32_t drawable
#define glXGetDrawableAttributes_PACKED PACKED_void_uint32_t
#define glXGetDrawableAttributes_INDEXED INDEXED_void_uint32_t
#define glXGetDrawableAttributes_FORMAT FORMAT_void_uint32_t
#define glXGetDrawableAttributesSGIX_INDEX 518
#define glXGetDrawableAttributesSGIX_RETURN void
#define glXGetDrawableAttributesSGIX_ARG_NAMES drawable
#define glXGetDrawableAttributesSGIX_ARG_EXPAND uint32_t drawable
#define glXGetDrawableAttributesSGIX_PACKED PACKED_void_uint32_t
#define glXGetDrawableAttributesSGIX_INDEXED INDEXED_void_uint32_t
#define glXGetDrawableAttributesSGIX_FORMAT FORMAT_void_uint32_t
#define glXGetFBConfigAttrib_INDEX 519
#define glXGetFBConfigAttrib_RETURN int
#define glXGetFBConfigAttrib_ARG_NAMES dpy, config, attribute, value
#define glXGetFBConfigAttrib_ARG_EXPAND Display * dpy, GLXFBConfig config, int attribute, int * value
#define glXGetFBConfigAttrib_PACKED PACKED_int_Display___GENPT___GLXFBConfig_int_int___GENPT__
#define glXGetFBConfigAttrib_INDEXED INDEXED_int_Display___GENPT___GLXFBConfig_int_int___GENPT__
#define glXGetFBConfigAttrib_FORMAT FORMAT_int_Display___GENPT___GLXFBConfig_int_int___GENPT__
#define glXGetFBConfigs_INDEX 520
#define glXGetFBConfigs_RETURN GLXFBConfig *
#define glXGetFBConfigs_ARG_NAMES dpy, screen, nelements
#define glXGetFBConfigs_ARG_EXPAND Display * dpy, int screen, int * nelements
#define glXGetFBConfigs_PACKED PACKED_GLXFBConfig___GENPT___Display___GENPT___int_int___GENPT__
#define glXGetFBConfigs_INDEXED INDEXED_GLXFBConfig___GENPT___Display___GENPT___int_int___GENPT__
#define glXGetFBConfigs_FORMAT FORMAT_GLXFBConfig___GENPT___Display___GENPT___int_int___GENPT__
#define glXGetFBConfigsSGIX_INDEX 521
#define glXGetFBConfigsSGIX_RETURN void
#define glXGetFBConfigsSGIX_ARG_NAMES 
#define glXGetFBConfigsSGIX_ARG_EXPAND 
#define glXGetFBConfigsSGIX_PACKED PACKED_void
#define glXGetFBConfigsSGIX_INDEXED INDEXED_void
#define glXGetFBConfigsSGIX_FORMAT FORMAT_void
#define glXGetProcAddress_INDEX 522
#define glXGetProcAddress_RETURN __GLXextFuncPtr
#define glXGetProcAddress_ARG_NAMES procName
#define glXGetProcAddress_ARG_EXPAND const GLubyte * procName
#define glXGetProcAddress_PACKED PACKED___GLXextFuncPtr_const_GLubyte___GENPT__
#define glXGetProcAddress_INDEXED INDEXED___GLXextFuncPtr_const_GLubyte___GENPT__
#define glXGetProcAddress_FORMAT FORMAT___GLXextFuncPtr_const_GLubyte___GENPT__
#define glXGetSelectedEvent_INDEX 523
#define glXGetSelectedEvent_RETURN void
#define glXGetSelectedEvent_ARG_NAMES dpy, draw, event_mask
#define glXGetSelectedEvent_ARG_EXPAND Display * dpy, GLXDrawable draw, unsigned long * event_mask
#define glXGetSelectedEvent_PACKED PACKED_void_Display___GENPT___GLXDrawable_unsigned_long___GENPT__
#define glXGetSelectedEvent_INDEXED INDEXED_void_Display___GENPT___GLXDrawable_unsigned_long___GENPT__
#define glXGetSelectedEvent_FORMAT FORMAT_void_Display___GENPT___GLXDrawable_unsigned_long___GENPT__
#define glXGetVisualConfigs_INDEX 524
#define glXGetVisualConfigs_RETURN void
#define glXGetVisualConfigs_ARG_NAMES 
#define glXGetVisualConfigs_ARG_EXPAND 
#define glXGetVisualConfigs_PACKED PACKED_void
#define glXGetVisualConfigs_INDEXED INDEXED_void
#define glXGetVisualConfigs_FORMAT FORMAT_void
#define glXGetVisualFromFBConfig_INDEX 525
#define glXGetVisualFromFBConfig_RETURN XVisualInfo *
#define glXGetVisualFromFBConfig_ARG_NAMES dpy, config
#define glXGetVisualFromFBConfig_ARG_EXPAND Display * dpy, GLXFBConfig config
#define glXGetVisualFromFBConfig_PACKED PACKED_XVisualInfo___GENPT___Display___GENPT___GLXFBConfig
#define glXGetVisualFromFBConfig_INDEXED INDEXED_XVisualInfo___GENPT___Display___GENPT___GLXFBConfig
#define glXGetVisualFromFBConfig_FORMAT FORMAT_XVisualInfo___GENPT___Display___GENPT___GLXFBConfig
#define glXHyperpipeAttribSGIX_INDEX 526
#define glXHyperpipeAttribSGIX_RETURN int
#define glXHyperpipeAttribSGIX_ARG_NAMES dpy, timeSlice, attrib, size, attribList
#define glXHyperpipeAttribSGIX_ARG_EXPAND Display * dpy, int timeSlice, int attrib, int size, const void * attribList
#define glXHyperpipeAttribSGIX_PACKED PACKED_int_Display___GENPT___int_int_int_const_void___GENPT__
#define glXHyperpipeAttribSGIX_INDEXED INDEXED_int_Display___GENPT___int_int_int_const_void___GENPT__
#define glXHyperpipeAttribSGIX_FORMAT FORMAT_int_Display___GENPT___int_int_int_const_void___GENPT__
#define glXHyperpipeConfigSGIX_INDEX 527
#define glXHyperpipeConfigSGIX_RETURN int
#define glXHyperpipeConfigSGIX_ARG_NAMES dpy, networkId, npipes, cfg, hpId
#define glXHyperpipeConfigSGIX_ARG_EXPAND Display * dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX cfg, int * hpId
#define glXHyperpipeConfigSGIX_PACKED PACKED_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__
#define glXHyperpipeConfigSGIX_INDEXED INDEXED_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__
#define glXHyperpipeConfigSGIX_FORMAT FORMAT_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__
#define glXIsDirect_INDEX 528
#define glXIsDirect_RETURN Bool
#define glXIsDirect_ARG_NAMES dpy, ctx
#define glXIsDirect_ARG_EXPAND Display * dpy, GLXContext ctx
#define glXIsDirect_PACKED PACKED_Bool_Display___GENPT___GLXContext
#define glXIsDirect_INDEXED INDEXED_Bool_Display___GENPT___GLXContext
#define glXIsDirect_FORMAT FORMAT_Bool_Display___GENPT___GLXContext
#define glXJoinSwapGroupSGIX_INDEX 529
#define glXJoinSwapGroupSGIX_RETURN void
#define glXJoinSwapGroupSGIX_ARG_NAMES window, group
#define glXJoinSwapGroupSGIX_ARG_EXPAND uint32_t window, uint32_t group
#define glXJoinSwapGroupSGIX_PACKED PACKED_void_uint32_t_uint32_t
#define glXJoinSwapGroupSGIX_INDEXED INDEXED_void_uint32_t_uint32_t
#define glXJoinSwapGroupSGIX_FORMAT FORMAT_void_uint32_t_uint32_t
#define glXMakeContextCurrent_INDEX 530
#define glXMakeContextCurrent_RETURN Bool
#define glXMakeContextCurrent_ARG_NAMES dpy, draw, read, ctx
#define glXMakeContextCurrent_ARG_EXPAND Display * dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx
#define glXMakeContextCurrent_PACKED PACKED_Bool_Display___GENPT___GLXDrawable_GLXDrawable_GLXContext
#define glXMakeContextCurrent_INDEXED INDEXED_Bool_Display___GENPT___GLXDrawable_GLXDrawable_GLXContext
#define glXMakeContextCurrent_FORMAT FORMAT_Bool_Display___GENPT___GLXDrawable_GLXDrawable_GLXContext
#define glXMakeCurrent_INDEX 531
#define glXMakeCurrent_RETURN Bool
#define glXMakeCurrent_ARG_NAMES dpy, drawable, ctx
#define glXMakeCurrent_ARG_EXPAND Display * dpy, GLXDrawable drawable, GLXContext ctx
#define glXMakeCurrent_PACKED PACKED_Bool_Display___GENPT___GLXDrawable_GLXContext
#define glXMakeCurrent_INDEXED INDEXED_Bool_Display___GENPT___GLXDrawable_GLXContext
#define glXMakeCurrent_FORMAT FORMAT_Bool_Display___GENPT___GLXDrawable_GLXContext
#define glXMakeCurrentReadSGI_INDEX 532
#define glXMakeCurrentReadSGI_RETURN void
#define glXMakeCurrentReadSGI_ARG_NAMES drawable, readdrawable, context
#define glXMakeCurrentReadSGI_ARG_EXPAND uint32_t drawable, uint32_t readdrawable, uint32_t context
#define glXMakeCurrentReadSGI_PACKED PACKED_void_uint32_t_uint32_t_uint32_t
#define glXMakeCurrentReadSGI_INDEXED INDEXED_void_uint32_t_uint32_t_uint32_t
#define glXMakeCurrentReadSGI_FORMAT FORMAT_void_uint32_t_uint32_t_uint32_t
#define glXQueryContext_INDEX 533
#define glXQueryContext_RETURN int
#define glXQueryContext_ARG_NAMES dpy, ctx, attribute, value
#define glXQueryContext_ARG_EXPAND Display * dpy, GLXContext ctx, int attribute, int * value
#define glXQueryContext_PACKED PACKED_int_Display___GENPT___GLXContext_int_int___GENPT__
#define glXQueryContext_INDEXED INDEXED_int_Display___GENPT___GLXContext_int_int___GENPT__
#define glXQueryContext_FORMAT FORMAT_int_Display___GENPT___GLXContext_int_int___GENPT__
#define glXQueryContextInfoEXT_INDEX 534
#define glXQueryContextInfoEXT_RETURN void
#define glXQueryContextInfoEXT_ARG_NAMES 
#define glXQueryContextInfoEXT_ARG_EXPAND 
#define glXQueryContextInfoEXT_PACKED PACKED_void
#define glXQueryContextInfoEXT_INDEXED INDEXED_void
#define glXQueryContextInfoEXT_FORMAT FORMAT_void
#define glXQueryDrawable_INDEX 535
#define glXQueryDrawable_RETURN void
#define glXQueryDrawable_ARG_NAMES dpy, draw, attribute, value
#define glXQueryDrawable_ARG_EXPAND Display * dpy, GLXDrawable draw, int attribute, unsigned int * value
#define glXQueryDrawable_PACKED PACKED_void_Display___GENPT___GLXDrawable_int_unsigned_int___GENPT__
#define glXQueryDrawable_INDEXED INDEXED_void_Display___GENPT___GLXDrawable_int_unsigned_int___GENPT__
#define glXQueryDrawable_FORMAT FORMAT_void_Display___GENPT___GLXDrawable_int_unsigned_int___GENPT__
#define glXQueryExtension_INDEX 536
#define glXQueryExtension_RETURN Bool
#define glXQueryExtension_ARG_NAMES display, errorBase, eventBase
#define glXQueryExtension_ARG_EXPAND Display * display, int * errorBase, int * eventBase
#define glXQueryExtension_PACKED PACKED_Bool_Display___GENPT___int___GENPT___int___GENPT__
#define glXQueryExtension_INDEXED INDEXED_Bool_Display___GENPT___int___GENPT___int___GENPT__
#define glXQueryExtension_FORMAT FORMAT_Bool_Display___GENPT___int___GENPT___int___GENPT__
#define glXQueryExtensionsString_INDEX 537
#define glXQueryExtensionsString_RETURN const char *
#define glXQueryExtensionsString_ARG_NAMES dpy, screen
#define glXQueryExtensionsString_ARG_EXPAND Display * dpy, int screen
#define glXQueryExtensionsString_PACKED PACKED_const_char___GENPT___Display___GENPT___int
#define glXQueryExtensionsString_INDEXED INDEXED_const_char___GENPT___Display___GENPT___int
#define glXQueryExtensionsString_FORMAT FORMAT_const_char___GENPT___Display___GENPT___int
#define glXQueryHyperpipeAttribSGIX_INDEX 538
#define glXQueryHyperpipeAttribSGIX_RETURN int
#define glXQueryHyperpipeAttribSGIX_ARG_NAMES dpy, timeSlice, attrib, size, returnAttribList
#define glXQueryHyperpipeAttribSGIX_ARG_EXPAND Display * dpy, int timeSlice, int attrib, int size, const void * returnAttribList
#define glXQueryHyperpipeAttribSGIX_PACKED PACKED_int_Display___GENPT___int_int_int_const_void___GENPT__
#define glXQueryHyperpipeAttribSGIX_INDEXED INDEXED_int_Display___GENPT___int_int_int_const_void___GENPT__
#define glXQueryHyperpipeAttribSGIX_FORMAT FORMAT_int_Display___GENPT___int_int_int_const_void___GENPT__
#define glXQueryHyperpipeBestAttribSGIX_INDEX 539
#define glXQueryHyperpipeBestAttribSGIX_RETURN int
#define glXQueryHyperpipeBestAttribSGIX_ARG_NAMES dpy, timeSlice, attrib, size, attribList, returnAttribList
#define glXQueryHyperpipeBestAttribSGIX_ARG_EXPAND Display * dpy, int timeSlice, int attrib, int size, const void * attribList, void * returnAttribList
#define glXQueryHyperpipeBestAttribSGIX_PACKED PACKED_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__
#define glXQueryHyperpipeBestAttribSGIX_INDEXED INDEXED_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__
#define glXQueryHyperpipeBestAttribSGIX_FORMAT FORMAT_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__
#define glXQueryHyperpipeConfigSGIX_INDEX 540
#define glXQueryHyperpipeConfigSGIX_RETURN GLXHyperpipeConfigSGIX *
#define glXQueryHyperpipeConfigSGIX_ARG_NAMES dpy, hpId, npipes
#define glXQueryHyperpipeConfigSGIX_ARG_EXPAND Display * dpy, int hpId, int * npipes
#define glXQueryHyperpipeConfigSGIX_PACKED PACKED_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__
#define glXQueryHyperpipeConfigSGIX_INDEXED INDEXED_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__
#define glXQueryHyperpipeConfigSGIX_FORMAT FORMAT_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__
#define glXQueryHyperpipeNetworkSGIX_INDEX 541
#define glXQueryHyperpipeNetworkSGIX_RETURN GLXHyperpipeNetworkSGIX *
#define glXQueryHyperpipeNetworkSGIX_ARG_NAMES dpy, npipes
#define glXQueryHyperpipeNetworkSGIX_ARG_EXPAND Display * dpy, int * npipes
#define glXQueryHyperpipeNetworkSGIX_PACKED PACKED_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__
#define glXQueryHyperpipeNetworkSGIX_INDEXED INDEXED_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__
#define glXQueryHyperpipeNetworkSGIX_FORMAT FORMAT_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__
#define glXQueryMaxSwapBarriersSGIX_INDEX 542
#define glXQueryMaxSwapBarriersSGIX_RETURN void
#define glXQueryMaxSwapBarriersSGIX_ARG_NAMES 
#define glXQueryMaxSwapBarriersSGIX_ARG_EXPAND 
#define glXQueryMaxSwapBarriersSGIX_PACKED PACKED_void
#define glXQueryMaxSwapBarriersSGIX_INDEXED INDEXED_void
#define glXQueryMaxSwapBarriersSGIX_FORMAT FORMAT_void
#define glXQueryServerString_INDEX 543
#define glXQueryServerString_RETURN const char *
#define glXQueryServerString_ARG_NAMES dpy, screen, name
#define glXQueryServerString_ARG_EXPAND Display * dpy, int screen, int name
#define glXQueryServerString_PACKED PACKED_const_char___GENPT___Display___GENPT___int_int
#define glXQueryServerString_INDEXED INDEXED_const_char___GENPT___Display___GENPT___int_int
#define glXQueryServerString_FORMAT FORMAT_const_char___GENPT___Display___GENPT___int_int
#define glXQueryVersion_INDEX 544
#define glXQueryVersion_RETURN Bool
#define glXQueryVersion_ARG_NAMES dpy, maj, min
#define glXQueryVersion_ARG_EXPAND Display * dpy, int * maj, int * min
#define glXQueryVersion_PACKED PACKED_Bool_Display___GENPT___int___GENPT___int___GENPT__
#define glXQueryVersion_INDEXED INDEXED_Bool_Display___GENPT___int___GENPT___int___GENPT__
#define glXQueryVersion_FORMAT FORMAT_Bool_Display___GENPT___int___GENPT___int___GENPT__
#define glXRender_INDEX 545
#define glXRender_RETURN void
#define glXRender_ARG_NAMES 
#define glXRender_ARG_EXPAND 
#define glXRender_PACKED PACKED_void
#define glXRender_INDEXED INDEXED_void
#define glXRender_FORMAT FORMAT_void
#define glXRenderLarge_INDEX 546
#define glXRenderLarge_RETURN void
#define glXRenderLarge_ARG_NAMES 
#define glXRenderLarge_ARG_EXPAND 
#define glXRenderLarge_PACKED PACKED_void
#define glXRenderLarge_INDEXED INDEXED_void
#define glXRenderLarge_FORMAT FORMAT_void
#define glXSelectEvent_INDEX 547
#define glXSelectEvent_RETURN void
#define glXSelectEvent_ARG_NAMES dpy, draw, event_mask
#define glXSelectEvent_ARG_EXPAND Display * dpy, GLXDrawable draw, unsigned long event_mask
#define glXSelectEvent_PACKED PACKED_void_Display___GENPT___GLXDrawable_unsigned_long
#define glXSelectEvent_INDEXED INDEXED_void_Display___GENPT___GLXDrawable_unsigned_long
#define glXSelectEvent_FORMAT FORMAT_void_Display___GENPT___GLXDrawable_unsigned_long
#define glXSwapBuffers_INDEX 548
#define glXSwapBuffers_RETURN void
#define glXSwapBuffers_ARG_NAMES dpy, drawable
#define glXSwapBuffers_ARG_EXPAND Display * dpy, GLXDrawable drawable
#define glXSwapBuffers_PACKED PACKED_void_Display___GENPT___GLXDrawable
#define glXSwapBuffers_INDEXED INDEXED_void_Display___GENPT___GLXDrawable
#define glXSwapBuffers_FORMAT FORMAT_void_Display___GENPT___GLXDrawable
#define glXSwapIntervalSGI_INDEX 549
#define glXSwapIntervalSGI_RETURN void
#define glXSwapIntervalSGI_ARG_NAMES 
#define glXSwapIntervalSGI_ARG_EXPAND 
#define glXSwapIntervalSGI_PACKED PACKED_void
#define glXSwapIntervalSGI_INDEXED INDEXED_void
#define glXSwapIntervalSGI_FORMAT FORMAT_void
#define glXUseXFont_INDEX 550
#define glXUseXFont_RETURN void
#define glXUseXFont_ARG_NAMES font, first, count, list
#define glXUseXFont_ARG_EXPAND Font font, int first, int count, int list
#define glXUseXFont_PACKED PACKED_void_Font_int_int_int
#define glXUseXFont_INDEXED INDEXED_void_Font_int_int_int
#define glXUseXFont_FORMAT FORMAT_void_Font_int_int_int
#define glXVendorPrivate_INDEX 551
#define glXVendorPrivate_RETURN void
#define glXVendorPrivate_ARG_NAMES 
#define glXVendorPrivate_ARG_EXPAND 
#define glXVendorPrivate_PACKED PACKED_void
#define glXVendorPrivate_INDEXED INDEXED_void
#define glXVendorPrivate_FORMAT FORMAT_void
#define glXVendorPrivateWithReply_INDEX 552
#define glXVendorPrivateWithReply_RETURN void
#define glXVendorPrivateWithReply_ARG_NAMES 
#define glXVendorPrivateWithReply_ARG_EXPAND 
#define glXVendorPrivateWithReply_PACKED PACKED_void
#define glXVendorPrivateWithReply_INDEXED INDEXED_void
#define glXVendorPrivateWithReply_FORMAT FORMAT_void
#define glXWaitGL_INDEX 553
#define glXWaitGL_RETURN void
#define glXWaitGL_ARG_NAMES 
#define glXWaitGL_ARG_EXPAND 
#define glXWaitGL_PACKED PACKED_void
#define glXWaitGL_INDEXED INDEXED_void
#define glXWaitGL_FORMAT FORMAT_void
#define glXWaitX_INDEX 554
#define glXWaitX_RETURN void
#define glXWaitX_ARG_NAMES 
#define glXWaitX_ARG_EXPAND 
#define glXWaitX_PACKED PACKED_void
#define glXWaitX_INDEXED INDEXED_void
#define glXWaitX_FORMAT FORMAT_void

void glAccum(glAccum_ARG_EXPAND);
typedef void (*glAccum_PTR)(glAccum_ARG_EXPAND);
void glActiveTexture(glActiveTexture_ARG_EXPAND);
typedef void (*glActiveTexture_PTR)(glActiveTexture_ARG_EXPAND);
void glAlphaFunc(glAlphaFunc_ARG_EXPAND);
typedef void (*glAlphaFunc_PTR)(glAlphaFunc_ARG_EXPAND);
GLboolean glAreTexturesResident(glAreTexturesResident_ARG_EXPAND);
typedef GLboolean (*glAreTexturesResident_PTR)(glAreTexturesResident_ARG_EXPAND);
void glArrayElement(glArrayElement_ARG_EXPAND);
typedef void (*glArrayElement_PTR)(glArrayElement_ARG_EXPAND);
void glBegin(glBegin_ARG_EXPAND);
typedef void (*glBegin_PTR)(glBegin_ARG_EXPAND);
void glBeginQuery(glBeginQuery_ARG_EXPAND);
typedef void (*glBeginQuery_PTR)(glBeginQuery_ARG_EXPAND);
void glBindBuffer(glBindBuffer_ARG_EXPAND);
typedef void (*glBindBuffer_PTR)(glBindBuffer_ARG_EXPAND);
void glBindTexture(glBindTexture_ARG_EXPAND);
typedef void (*glBindTexture_PTR)(glBindTexture_ARG_EXPAND);
void glBitmap(glBitmap_ARG_EXPAND);
typedef void (*glBitmap_PTR)(glBitmap_ARG_EXPAND);
void glBlendColor(glBlendColor_ARG_EXPAND);
typedef void (*glBlendColor_PTR)(glBlendColor_ARG_EXPAND);
void glBlendEquation(glBlendEquation_ARG_EXPAND);
typedef void (*glBlendEquation_PTR)(glBlendEquation_ARG_EXPAND);
void glBlendFunc(glBlendFunc_ARG_EXPAND);
typedef void (*glBlendFunc_PTR)(glBlendFunc_ARG_EXPAND);
void glBlendFuncSeparate(glBlendFuncSeparate_ARG_EXPAND);
typedef void (*glBlendFuncSeparate_PTR)(glBlendFuncSeparate_ARG_EXPAND);
void glBufferData(glBufferData_ARG_EXPAND);
typedef void (*glBufferData_PTR)(glBufferData_ARG_EXPAND);
void glBufferSubData(glBufferSubData_ARG_EXPAND);
typedef void (*glBufferSubData_PTR)(glBufferSubData_ARG_EXPAND);
void glCallList(glCallList_ARG_EXPAND);
typedef void (*glCallList_PTR)(glCallList_ARG_EXPAND);
void glCallLists(glCallLists_ARG_EXPAND);
typedef void (*glCallLists_PTR)(glCallLists_ARG_EXPAND);
void glClear(glClear_ARG_EXPAND);
typedef void (*glClear_PTR)(glClear_ARG_EXPAND);
void glClearAccum(glClearAccum_ARG_EXPAND);
typedef void (*glClearAccum_PTR)(glClearAccum_ARG_EXPAND);
void glClearColor(glClearColor_ARG_EXPAND);
typedef void (*glClearColor_PTR)(glClearColor_ARG_EXPAND);
void glClearDepth(glClearDepth_ARG_EXPAND);
typedef void (*glClearDepth_PTR)(glClearDepth_ARG_EXPAND);
void glClearIndex(glClearIndex_ARG_EXPAND);
typedef void (*glClearIndex_PTR)(glClearIndex_ARG_EXPAND);
void glClearStencil(glClearStencil_ARG_EXPAND);
typedef void (*glClearStencil_PTR)(glClearStencil_ARG_EXPAND);
void glClientActiveTexture(glClientActiveTexture_ARG_EXPAND);
typedef void (*glClientActiveTexture_PTR)(glClientActiveTexture_ARG_EXPAND);
void glClipPlane(glClipPlane_ARG_EXPAND);
typedef void (*glClipPlane_PTR)(glClipPlane_ARG_EXPAND);
void glColor3b(glColor3b_ARG_EXPAND);
typedef void (*glColor3b_PTR)(glColor3b_ARG_EXPAND);
void glColor3bv(glColor3bv_ARG_EXPAND);
typedef void (*glColor3bv_PTR)(glColor3bv_ARG_EXPAND);
void glColor3d(glColor3d_ARG_EXPAND);
typedef void (*glColor3d_PTR)(glColor3d_ARG_EXPAND);
void glColor3dv(glColor3dv_ARG_EXPAND);
typedef void (*glColor3dv_PTR)(glColor3dv_ARG_EXPAND);
void glColor3f(glColor3f_ARG_EXPAND);
typedef void (*glColor3f_PTR)(glColor3f_ARG_EXPAND);
void glColor3fv(glColor3fv_ARG_EXPAND);
typedef void (*glColor3fv_PTR)(glColor3fv_ARG_EXPAND);
void glColor3i(glColor3i_ARG_EXPAND);
typedef void (*glColor3i_PTR)(glColor3i_ARG_EXPAND);
void glColor3iv(glColor3iv_ARG_EXPAND);
typedef void (*glColor3iv_PTR)(glColor3iv_ARG_EXPAND);
void glColor3s(glColor3s_ARG_EXPAND);
typedef void (*glColor3s_PTR)(glColor3s_ARG_EXPAND);
void glColor3sv(glColor3sv_ARG_EXPAND);
typedef void (*glColor3sv_PTR)(glColor3sv_ARG_EXPAND);
void glColor3ub(glColor3ub_ARG_EXPAND);
typedef void (*glColor3ub_PTR)(glColor3ub_ARG_EXPAND);
void glColor3ubv(glColor3ubv_ARG_EXPAND);
typedef void (*glColor3ubv_PTR)(glColor3ubv_ARG_EXPAND);
void glColor3ui(glColor3ui_ARG_EXPAND);
typedef void (*glColor3ui_PTR)(glColor3ui_ARG_EXPAND);
void glColor3uiv(glColor3uiv_ARG_EXPAND);
typedef void (*glColor3uiv_PTR)(glColor3uiv_ARG_EXPAND);
void glColor3us(glColor3us_ARG_EXPAND);
typedef void (*glColor3us_PTR)(glColor3us_ARG_EXPAND);
void glColor3usv(glColor3usv_ARG_EXPAND);
typedef void (*glColor3usv_PTR)(glColor3usv_ARG_EXPAND);
void glColor4b(glColor4b_ARG_EXPAND);
typedef void (*glColor4b_PTR)(glColor4b_ARG_EXPAND);
void glColor4bv(glColor4bv_ARG_EXPAND);
typedef void (*glColor4bv_PTR)(glColor4bv_ARG_EXPAND);
void glColor4d(glColor4d_ARG_EXPAND);
typedef void (*glColor4d_PTR)(glColor4d_ARG_EXPAND);
void glColor4dv(glColor4dv_ARG_EXPAND);
typedef void (*glColor4dv_PTR)(glColor4dv_ARG_EXPAND);
void glColor4f(glColor4f_ARG_EXPAND);
typedef void (*glColor4f_PTR)(glColor4f_ARG_EXPAND);
void glColor4fv(glColor4fv_ARG_EXPAND);
typedef void (*glColor4fv_PTR)(glColor4fv_ARG_EXPAND);
void glColor4i(glColor4i_ARG_EXPAND);
typedef void (*glColor4i_PTR)(glColor4i_ARG_EXPAND);
void glColor4iv(glColor4iv_ARG_EXPAND);
typedef void (*glColor4iv_PTR)(glColor4iv_ARG_EXPAND);
void glColor4s(glColor4s_ARG_EXPAND);
typedef void (*glColor4s_PTR)(glColor4s_ARG_EXPAND);
void glColor4sv(glColor4sv_ARG_EXPAND);
typedef void (*glColor4sv_PTR)(glColor4sv_ARG_EXPAND);
void glColor4ub(glColor4ub_ARG_EXPAND);
typedef void (*glColor4ub_PTR)(glColor4ub_ARG_EXPAND);
void glColor4ubv(glColor4ubv_ARG_EXPAND);
typedef void (*glColor4ubv_PTR)(glColor4ubv_ARG_EXPAND);
void glColor4ui(glColor4ui_ARG_EXPAND);
typedef void (*glColor4ui_PTR)(glColor4ui_ARG_EXPAND);
void glColor4uiv(glColor4uiv_ARG_EXPAND);
typedef void (*glColor4uiv_PTR)(glColor4uiv_ARG_EXPAND);
void glColor4us(glColor4us_ARG_EXPAND);
typedef void (*glColor4us_PTR)(glColor4us_ARG_EXPAND);
void glColor4usv(glColor4usv_ARG_EXPAND);
typedef void (*glColor4usv_PTR)(glColor4usv_ARG_EXPAND);
void glColorMask(glColorMask_ARG_EXPAND);
typedef void (*glColorMask_PTR)(glColorMask_ARG_EXPAND);
void glColorMaterial(glColorMaterial_ARG_EXPAND);
typedef void (*glColorMaterial_PTR)(glColorMaterial_ARG_EXPAND);
void glColorPointer(glColorPointer_ARG_EXPAND);
typedef void (*glColorPointer_PTR)(glColorPointer_ARG_EXPAND);
void glColorSubTable(glColorSubTable_ARG_EXPAND);
typedef void (*glColorSubTable_PTR)(glColorSubTable_ARG_EXPAND);
void glColorTable(glColorTable_ARG_EXPAND);
typedef void (*glColorTable_PTR)(glColorTable_ARG_EXPAND);
void glColorTableParameterfv(glColorTableParameterfv_ARG_EXPAND);
typedef void (*glColorTableParameterfv_PTR)(glColorTableParameterfv_ARG_EXPAND);
void glColorTableParameteriv(glColorTableParameteriv_ARG_EXPAND);
typedef void (*glColorTableParameteriv_PTR)(glColorTableParameteriv_ARG_EXPAND);
void glCompressedTexImage1D(glCompressedTexImage1D_ARG_EXPAND);
typedef void (*glCompressedTexImage1D_PTR)(glCompressedTexImage1D_ARG_EXPAND);
void glCompressedTexImage2D(glCompressedTexImage2D_ARG_EXPAND);
typedef void (*glCompressedTexImage2D_PTR)(glCompressedTexImage2D_ARG_EXPAND);
void glCompressedTexImage3D(glCompressedTexImage3D_ARG_EXPAND);
typedef void (*glCompressedTexImage3D_PTR)(glCompressedTexImage3D_ARG_EXPAND);
void glCompressedTexSubImage1D(glCompressedTexSubImage1D_ARG_EXPAND);
typedef void (*glCompressedTexSubImage1D_PTR)(glCompressedTexSubImage1D_ARG_EXPAND);
void glCompressedTexSubImage2D(glCompressedTexSubImage2D_ARG_EXPAND);
typedef void (*glCompressedTexSubImage2D_PTR)(glCompressedTexSubImage2D_ARG_EXPAND);
void glCompressedTexSubImage3D(glCompressedTexSubImage3D_ARG_EXPAND);
typedef void (*glCompressedTexSubImage3D_PTR)(glCompressedTexSubImage3D_ARG_EXPAND);
void glConvolutionFilter1D(glConvolutionFilter1D_ARG_EXPAND);
typedef void (*glConvolutionFilter1D_PTR)(glConvolutionFilter1D_ARG_EXPAND);
void glConvolutionFilter2D(glConvolutionFilter2D_ARG_EXPAND);
typedef void (*glConvolutionFilter2D_PTR)(glConvolutionFilter2D_ARG_EXPAND);
void glConvolutionParameterf(glConvolutionParameterf_ARG_EXPAND);
typedef void (*glConvolutionParameterf_PTR)(glConvolutionParameterf_ARG_EXPAND);
void glConvolutionParameterfv(glConvolutionParameterfv_ARG_EXPAND);
typedef void (*glConvolutionParameterfv_PTR)(glConvolutionParameterfv_ARG_EXPAND);
void glConvolutionParameteri(glConvolutionParameteri_ARG_EXPAND);
typedef void (*glConvolutionParameteri_PTR)(glConvolutionParameteri_ARG_EXPAND);
void glConvolutionParameteriv(glConvolutionParameteriv_ARG_EXPAND);
typedef void (*glConvolutionParameteriv_PTR)(glConvolutionParameteriv_ARG_EXPAND);
void glCopyColorSubTable(glCopyColorSubTable_ARG_EXPAND);
typedef void (*glCopyColorSubTable_PTR)(glCopyColorSubTable_ARG_EXPAND);
void glCopyColorTable(glCopyColorTable_ARG_EXPAND);
typedef void (*glCopyColorTable_PTR)(glCopyColorTable_ARG_EXPAND);
void glCopyConvolutionFilter1D(glCopyConvolutionFilter1D_ARG_EXPAND);
typedef void (*glCopyConvolutionFilter1D_PTR)(glCopyConvolutionFilter1D_ARG_EXPAND);
void glCopyConvolutionFilter2D(glCopyConvolutionFilter2D_ARG_EXPAND);
typedef void (*glCopyConvolutionFilter2D_PTR)(glCopyConvolutionFilter2D_ARG_EXPAND);
void glCopyPixels(glCopyPixels_ARG_EXPAND);
typedef void (*glCopyPixels_PTR)(glCopyPixels_ARG_EXPAND);
void glCopyTexImage1D(glCopyTexImage1D_ARG_EXPAND);
typedef void (*glCopyTexImage1D_PTR)(glCopyTexImage1D_ARG_EXPAND);
void glCopyTexImage2D(glCopyTexImage2D_ARG_EXPAND);
typedef void (*glCopyTexImage2D_PTR)(glCopyTexImage2D_ARG_EXPAND);
void glCopyTexSubImage1D(glCopyTexSubImage1D_ARG_EXPAND);
typedef void (*glCopyTexSubImage1D_PTR)(glCopyTexSubImage1D_ARG_EXPAND);
void glCopyTexSubImage2D(glCopyTexSubImage2D_ARG_EXPAND);
typedef void (*glCopyTexSubImage2D_PTR)(glCopyTexSubImage2D_ARG_EXPAND);
void glCopyTexSubImage3D(glCopyTexSubImage3D_ARG_EXPAND);
typedef void (*glCopyTexSubImage3D_PTR)(glCopyTexSubImage3D_ARG_EXPAND);
void glCullFace(glCullFace_ARG_EXPAND);
typedef void (*glCullFace_PTR)(glCullFace_ARG_EXPAND);
void glDeleteBuffers(glDeleteBuffers_ARG_EXPAND);
typedef void (*glDeleteBuffers_PTR)(glDeleteBuffers_ARG_EXPAND);
void glDeleteLists(glDeleteLists_ARG_EXPAND);
typedef void (*glDeleteLists_PTR)(glDeleteLists_ARG_EXPAND);
void glDeleteQueries(glDeleteQueries_ARG_EXPAND);
typedef void (*glDeleteQueries_PTR)(glDeleteQueries_ARG_EXPAND);
void glDeleteTextures(glDeleteTextures_ARG_EXPAND);
typedef void (*glDeleteTextures_PTR)(glDeleteTextures_ARG_EXPAND);
void glDepthFunc(glDepthFunc_ARG_EXPAND);
typedef void (*glDepthFunc_PTR)(glDepthFunc_ARG_EXPAND);
void glDepthMask(glDepthMask_ARG_EXPAND);
typedef void (*glDepthMask_PTR)(glDepthMask_ARG_EXPAND);
void glDepthRange(glDepthRange_ARG_EXPAND);
typedef void (*glDepthRange_PTR)(glDepthRange_ARG_EXPAND);
void glDisable(glDisable_ARG_EXPAND);
typedef void (*glDisable_PTR)(glDisable_ARG_EXPAND);
void glDisableClientState(glDisableClientState_ARG_EXPAND);
typedef void (*glDisableClientState_PTR)(glDisableClientState_ARG_EXPAND);
void glDrawArrays(glDrawArrays_ARG_EXPAND);
typedef void (*glDrawArrays_PTR)(glDrawArrays_ARG_EXPAND);
void glDrawBuffer(glDrawBuffer_ARG_EXPAND);
typedef void (*glDrawBuffer_PTR)(glDrawBuffer_ARG_EXPAND);
void glDrawElements(glDrawElements_ARG_EXPAND);
typedef void (*glDrawElements_PTR)(glDrawElements_ARG_EXPAND);
void glDrawPixels(glDrawPixels_ARG_EXPAND);
typedef void (*glDrawPixels_PTR)(glDrawPixels_ARG_EXPAND);
void glDrawRangeElements(glDrawRangeElements_ARG_EXPAND);
typedef void (*glDrawRangeElements_PTR)(glDrawRangeElements_ARG_EXPAND);
void glEdgeFlag(glEdgeFlag_ARG_EXPAND);
typedef void (*glEdgeFlag_PTR)(glEdgeFlag_ARG_EXPAND);
void glEdgeFlagPointer(glEdgeFlagPointer_ARG_EXPAND);
typedef void (*glEdgeFlagPointer_PTR)(glEdgeFlagPointer_ARG_EXPAND);
void glEdgeFlagv(glEdgeFlagv_ARG_EXPAND);
typedef void (*glEdgeFlagv_PTR)(glEdgeFlagv_ARG_EXPAND);
void glEnable(glEnable_ARG_EXPAND);
typedef void (*glEnable_PTR)(glEnable_ARG_EXPAND);
void glEnableClientState(glEnableClientState_ARG_EXPAND);
typedef void (*glEnableClientState_PTR)(glEnableClientState_ARG_EXPAND);
void glEnd(glEnd_ARG_EXPAND);
typedef void (*glEnd_PTR)(glEnd_ARG_EXPAND);
void glEndList(glEndList_ARG_EXPAND);
typedef void (*glEndList_PTR)(glEndList_ARG_EXPAND);
void glEndQuery(glEndQuery_ARG_EXPAND);
typedef void (*glEndQuery_PTR)(glEndQuery_ARG_EXPAND);
void glEvalCoord1d(glEvalCoord1d_ARG_EXPAND);
typedef void (*glEvalCoord1d_PTR)(glEvalCoord1d_ARG_EXPAND);
void glEvalCoord1dv(glEvalCoord1dv_ARG_EXPAND);
typedef void (*glEvalCoord1dv_PTR)(glEvalCoord1dv_ARG_EXPAND);
void glEvalCoord1f(glEvalCoord1f_ARG_EXPAND);
typedef void (*glEvalCoord1f_PTR)(glEvalCoord1f_ARG_EXPAND);
void glEvalCoord1fv(glEvalCoord1fv_ARG_EXPAND);
typedef void (*glEvalCoord1fv_PTR)(glEvalCoord1fv_ARG_EXPAND);
void glEvalCoord2d(glEvalCoord2d_ARG_EXPAND);
typedef void (*glEvalCoord2d_PTR)(glEvalCoord2d_ARG_EXPAND);
void glEvalCoord2dv(glEvalCoord2dv_ARG_EXPAND);
typedef void (*glEvalCoord2dv_PTR)(glEvalCoord2dv_ARG_EXPAND);
void glEvalCoord2f(glEvalCoord2f_ARG_EXPAND);
typedef void (*glEvalCoord2f_PTR)(glEvalCoord2f_ARG_EXPAND);
void glEvalCoord2fv(glEvalCoord2fv_ARG_EXPAND);
typedef void (*glEvalCoord2fv_PTR)(glEvalCoord2fv_ARG_EXPAND);
void glEvalMesh1(glEvalMesh1_ARG_EXPAND);
typedef void (*glEvalMesh1_PTR)(glEvalMesh1_ARG_EXPAND);
void glEvalMesh2(glEvalMesh2_ARG_EXPAND);
typedef void (*glEvalMesh2_PTR)(glEvalMesh2_ARG_EXPAND);
void glEvalPoint1(glEvalPoint1_ARG_EXPAND);
typedef void (*glEvalPoint1_PTR)(glEvalPoint1_ARG_EXPAND);
void glEvalPoint2(glEvalPoint2_ARG_EXPAND);
typedef void (*glEvalPoint2_PTR)(glEvalPoint2_ARG_EXPAND);
void glFeedbackBuffer(glFeedbackBuffer_ARG_EXPAND);
typedef void (*glFeedbackBuffer_PTR)(glFeedbackBuffer_ARG_EXPAND);
void glFinish(glFinish_ARG_EXPAND);
typedef void (*glFinish_PTR)(glFinish_ARG_EXPAND);
void glFlush(glFlush_ARG_EXPAND);
typedef void (*glFlush_PTR)(glFlush_ARG_EXPAND);
void glFogCoordPointer(glFogCoordPointer_ARG_EXPAND);
typedef void (*glFogCoordPointer_PTR)(glFogCoordPointer_ARG_EXPAND);
void glFogCoordd(glFogCoordd_ARG_EXPAND);
typedef void (*glFogCoordd_PTR)(glFogCoordd_ARG_EXPAND);
void glFogCoorddv(glFogCoorddv_ARG_EXPAND);
typedef void (*glFogCoorddv_PTR)(glFogCoorddv_ARG_EXPAND);
void glFogCoordf(glFogCoordf_ARG_EXPAND);
typedef void (*glFogCoordf_PTR)(glFogCoordf_ARG_EXPAND);
void glFogCoordfv(glFogCoordfv_ARG_EXPAND);
typedef void (*glFogCoordfv_PTR)(glFogCoordfv_ARG_EXPAND);
void glFogf(glFogf_ARG_EXPAND);
typedef void (*glFogf_PTR)(glFogf_ARG_EXPAND);
void glFogfv(glFogfv_ARG_EXPAND);
typedef void (*glFogfv_PTR)(glFogfv_ARG_EXPAND);
void glFogi(glFogi_ARG_EXPAND);
typedef void (*glFogi_PTR)(glFogi_ARG_EXPAND);
void glFogiv(glFogiv_ARG_EXPAND);
typedef void (*glFogiv_PTR)(glFogiv_ARG_EXPAND);
void glFrontFace(glFrontFace_ARG_EXPAND);
typedef void (*glFrontFace_PTR)(glFrontFace_ARG_EXPAND);
void glFrustum(glFrustum_ARG_EXPAND);
typedef void (*glFrustum_PTR)(glFrustum_ARG_EXPAND);
void glGenBuffers(glGenBuffers_ARG_EXPAND);
typedef void (*glGenBuffers_PTR)(glGenBuffers_ARG_EXPAND);
GLuint glGenLists(glGenLists_ARG_EXPAND);
typedef GLuint (*glGenLists_PTR)(glGenLists_ARG_EXPAND);
void glGenQueries(glGenQueries_ARG_EXPAND);
typedef void (*glGenQueries_PTR)(glGenQueries_ARG_EXPAND);
void glGenTextures(glGenTextures_ARG_EXPAND);
typedef void (*glGenTextures_PTR)(glGenTextures_ARG_EXPAND);
void glGetBooleanv(glGetBooleanv_ARG_EXPAND);
typedef void (*glGetBooleanv_PTR)(glGetBooleanv_ARG_EXPAND);
void glGetBufferParameteriv(glGetBufferParameteriv_ARG_EXPAND);
typedef void (*glGetBufferParameteriv_PTR)(glGetBufferParameteriv_ARG_EXPAND);
void glGetBufferPointerv(glGetBufferPointerv_ARG_EXPAND);
typedef void (*glGetBufferPointerv_PTR)(glGetBufferPointerv_ARG_EXPAND);
void glGetBufferSubData(glGetBufferSubData_ARG_EXPAND);
typedef void (*glGetBufferSubData_PTR)(glGetBufferSubData_ARG_EXPAND);
void glGetClipPlane(glGetClipPlane_ARG_EXPAND);
typedef void (*glGetClipPlane_PTR)(glGetClipPlane_ARG_EXPAND);
void glGetColorTable(glGetColorTable_ARG_EXPAND);
typedef void (*glGetColorTable_PTR)(glGetColorTable_ARG_EXPAND);
void glGetColorTableParameterfv(glGetColorTableParameterfv_ARG_EXPAND);
typedef void (*glGetColorTableParameterfv_PTR)(glGetColorTableParameterfv_ARG_EXPAND);
void glGetColorTableParameteriv(glGetColorTableParameteriv_ARG_EXPAND);
typedef void (*glGetColorTableParameteriv_PTR)(glGetColorTableParameteriv_ARG_EXPAND);
void glGetCompressedTexImage(glGetCompressedTexImage_ARG_EXPAND);
typedef void (*glGetCompressedTexImage_PTR)(glGetCompressedTexImage_ARG_EXPAND);
void glGetConvolutionFilter(glGetConvolutionFilter_ARG_EXPAND);
typedef void (*glGetConvolutionFilter_PTR)(glGetConvolutionFilter_ARG_EXPAND);
void glGetConvolutionParameterfv(glGetConvolutionParameterfv_ARG_EXPAND);
typedef void (*glGetConvolutionParameterfv_PTR)(glGetConvolutionParameterfv_ARG_EXPAND);
void glGetConvolutionParameteriv(glGetConvolutionParameteriv_ARG_EXPAND);
typedef void (*glGetConvolutionParameteriv_PTR)(glGetConvolutionParameteriv_ARG_EXPAND);
void glGetDoublev(glGetDoublev_ARG_EXPAND);
typedef void (*glGetDoublev_PTR)(glGetDoublev_ARG_EXPAND);
GLenum glGetError(glGetError_ARG_EXPAND);
typedef GLenum (*glGetError_PTR)(glGetError_ARG_EXPAND);
void glGetFloatv(glGetFloatv_ARG_EXPAND);
typedef void (*glGetFloatv_PTR)(glGetFloatv_ARG_EXPAND);
void glGetHistogram(glGetHistogram_ARG_EXPAND);
typedef void (*glGetHistogram_PTR)(glGetHistogram_ARG_EXPAND);
void glGetHistogramParameterfv(glGetHistogramParameterfv_ARG_EXPAND);
typedef void (*glGetHistogramParameterfv_PTR)(glGetHistogramParameterfv_ARG_EXPAND);
void glGetHistogramParameteriv(glGetHistogramParameteriv_ARG_EXPAND);
typedef void (*glGetHistogramParameteriv_PTR)(glGetHistogramParameteriv_ARG_EXPAND);
void glGetIntegerv(glGetIntegerv_ARG_EXPAND);
typedef void (*glGetIntegerv_PTR)(glGetIntegerv_ARG_EXPAND);
void glGetLightfv(glGetLightfv_ARG_EXPAND);
typedef void (*glGetLightfv_PTR)(glGetLightfv_ARG_EXPAND);
void glGetLightiv(glGetLightiv_ARG_EXPAND);
typedef void (*glGetLightiv_PTR)(glGetLightiv_ARG_EXPAND);
void glGetMapdv(glGetMapdv_ARG_EXPAND);
typedef void (*glGetMapdv_PTR)(glGetMapdv_ARG_EXPAND);
void glGetMapfv(glGetMapfv_ARG_EXPAND);
typedef void (*glGetMapfv_PTR)(glGetMapfv_ARG_EXPAND);
void glGetMapiv(glGetMapiv_ARG_EXPAND);
typedef void (*glGetMapiv_PTR)(glGetMapiv_ARG_EXPAND);
void glGetMaterialfv(glGetMaterialfv_ARG_EXPAND);
typedef void (*glGetMaterialfv_PTR)(glGetMaterialfv_ARG_EXPAND);
void glGetMaterialiv(glGetMaterialiv_ARG_EXPAND);
typedef void (*glGetMaterialiv_PTR)(glGetMaterialiv_ARG_EXPAND);
void glGetMinmax(glGetMinmax_ARG_EXPAND);
typedef void (*glGetMinmax_PTR)(glGetMinmax_ARG_EXPAND);
void glGetMinmaxParameterfv(glGetMinmaxParameterfv_ARG_EXPAND);
typedef void (*glGetMinmaxParameterfv_PTR)(glGetMinmaxParameterfv_ARG_EXPAND);
void glGetMinmaxParameteriv(glGetMinmaxParameteriv_ARG_EXPAND);
typedef void (*glGetMinmaxParameteriv_PTR)(glGetMinmaxParameteriv_ARG_EXPAND);
void glGetPixelMapfv(glGetPixelMapfv_ARG_EXPAND);
typedef void (*glGetPixelMapfv_PTR)(glGetPixelMapfv_ARG_EXPAND);
void glGetPixelMapuiv(glGetPixelMapuiv_ARG_EXPAND);
typedef void (*glGetPixelMapuiv_PTR)(glGetPixelMapuiv_ARG_EXPAND);
void glGetPixelMapusv(glGetPixelMapusv_ARG_EXPAND);
typedef void (*glGetPixelMapusv_PTR)(glGetPixelMapusv_ARG_EXPAND);
void glGetPointerv(glGetPointerv_ARG_EXPAND);
typedef void (*glGetPointerv_PTR)(glGetPointerv_ARG_EXPAND);
void glGetPolygonStipple(glGetPolygonStipple_ARG_EXPAND);
typedef void (*glGetPolygonStipple_PTR)(glGetPolygonStipple_ARG_EXPAND);
void glGetQueryObjectiv(glGetQueryObjectiv_ARG_EXPAND);
typedef void (*glGetQueryObjectiv_PTR)(glGetQueryObjectiv_ARG_EXPAND);
void glGetQueryObjectuiv(glGetQueryObjectuiv_ARG_EXPAND);
typedef void (*glGetQueryObjectuiv_PTR)(glGetQueryObjectuiv_ARG_EXPAND);
void glGetQueryiv(glGetQueryiv_ARG_EXPAND);
typedef void (*glGetQueryiv_PTR)(glGetQueryiv_ARG_EXPAND);
void glGetSeparableFilter(glGetSeparableFilter_ARG_EXPAND);
typedef void (*glGetSeparableFilter_PTR)(glGetSeparableFilter_ARG_EXPAND);
const GLubyte * glGetString(glGetString_ARG_EXPAND);
typedef const GLubyte * (*glGetString_PTR)(glGetString_ARG_EXPAND);
void glGetTexEnvfv(glGetTexEnvfv_ARG_EXPAND);
typedef void (*glGetTexEnvfv_PTR)(glGetTexEnvfv_ARG_EXPAND);
void glGetTexEnviv(glGetTexEnviv_ARG_EXPAND);
typedef void (*glGetTexEnviv_PTR)(glGetTexEnviv_ARG_EXPAND);
void glGetTexGendv(glGetTexGendv_ARG_EXPAND);
typedef void (*glGetTexGendv_PTR)(glGetTexGendv_ARG_EXPAND);
void glGetTexGenfv(glGetTexGenfv_ARG_EXPAND);
typedef void (*glGetTexGenfv_PTR)(glGetTexGenfv_ARG_EXPAND);
void glGetTexGeniv(glGetTexGeniv_ARG_EXPAND);
typedef void (*glGetTexGeniv_PTR)(glGetTexGeniv_ARG_EXPAND);
void glGetTexImage(glGetTexImage_ARG_EXPAND);
typedef void (*glGetTexImage_PTR)(glGetTexImage_ARG_EXPAND);
void glGetTexLevelParameterfv(glGetTexLevelParameterfv_ARG_EXPAND);
typedef void (*glGetTexLevelParameterfv_PTR)(glGetTexLevelParameterfv_ARG_EXPAND);
void glGetTexLevelParameteriv(glGetTexLevelParameteriv_ARG_EXPAND);
typedef void (*glGetTexLevelParameteriv_PTR)(glGetTexLevelParameteriv_ARG_EXPAND);
void glGetTexParameterfv(glGetTexParameterfv_ARG_EXPAND);
typedef void (*glGetTexParameterfv_PTR)(glGetTexParameterfv_ARG_EXPAND);
void glGetTexParameteriv(glGetTexParameteriv_ARG_EXPAND);
typedef void (*glGetTexParameteriv_PTR)(glGetTexParameteriv_ARG_EXPAND);
void glHint(glHint_ARG_EXPAND);
typedef void (*glHint_PTR)(glHint_ARG_EXPAND);
void glHistogram(glHistogram_ARG_EXPAND);
typedef void (*glHistogram_PTR)(glHistogram_ARG_EXPAND);
void glIndexMask(glIndexMask_ARG_EXPAND);
typedef void (*glIndexMask_PTR)(glIndexMask_ARG_EXPAND);
void glIndexPointer(glIndexPointer_ARG_EXPAND);
typedef void (*glIndexPointer_PTR)(glIndexPointer_ARG_EXPAND);
void glIndexd(glIndexd_ARG_EXPAND);
typedef void (*glIndexd_PTR)(glIndexd_ARG_EXPAND);
void glIndexdv(glIndexdv_ARG_EXPAND);
typedef void (*glIndexdv_PTR)(glIndexdv_ARG_EXPAND);
void glIndexf(glIndexf_ARG_EXPAND);
typedef void (*glIndexf_PTR)(glIndexf_ARG_EXPAND);
void glIndexfv(glIndexfv_ARG_EXPAND);
typedef void (*glIndexfv_PTR)(glIndexfv_ARG_EXPAND);
void glIndexi(glIndexi_ARG_EXPAND);
typedef void (*glIndexi_PTR)(glIndexi_ARG_EXPAND);
void glIndexiv(glIndexiv_ARG_EXPAND);
typedef void (*glIndexiv_PTR)(glIndexiv_ARG_EXPAND);
void glIndexs(glIndexs_ARG_EXPAND);
typedef void (*glIndexs_PTR)(glIndexs_ARG_EXPAND);
void glIndexsv(glIndexsv_ARG_EXPAND);
typedef void (*glIndexsv_PTR)(glIndexsv_ARG_EXPAND);
void glIndexub(glIndexub_ARG_EXPAND);
typedef void (*glIndexub_PTR)(glIndexub_ARG_EXPAND);
void glIndexubv(glIndexubv_ARG_EXPAND);
typedef void (*glIndexubv_PTR)(glIndexubv_ARG_EXPAND);
void glInitNames(glInitNames_ARG_EXPAND);
typedef void (*glInitNames_PTR)(glInitNames_ARG_EXPAND);
void glInterleavedArrays(glInterleavedArrays_ARG_EXPAND);
typedef void (*glInterleavedArrays_PTR)(glInterleavedArrays_ARG_EXPAND);
GLboolean glIsBuffer(glIsBuffer_ARG_EXPAND);
typedef GLboolean (*glIsBuffer_PTR)(glIsBuffer_ARG_EXPAND);
GLboolean glIsEnabled(glIsEnabled_ARG_EXPAND);
typedef GLboolean (*glIsEnabled_PTR)(glIsEnabled_ARG_EXPAND);
GLboolean glIsList(glIsList_ARG_EXPAND);
typedef GLboolean (*glIsList_PTR)(glIsList_ARG_EXPAND);
GLboolean glIsQuery(glIsQuery_ARG_EXPAND);
typedef GLboolean (*glIsQuery_PTR)(glIsQuery_ARG_EXPAND);
GLboolean glIsTexture(glIsTexture_ARG_EXPAND);
typedef GLboolean (*glIsTexture_PTR)(glIsTexture_ARG_EXPAND);
void glLightModelf(glLightModelf_ARG_EXPAND);
typedef void (*glLightModelf_PTR)(glLightModelf_ARG_EXPAND);
void glLightModelfv(glLightModelfv_ARG_EXPAND);
typedef void (*glLightModelfv_PTR)(glLightModelfv_ARG_EXPAND);
void glLightModeli(glLightModeli_ARG_EXPAND);
typedef void (*glLightModeli_PTR)(glLightModeli_ARG_EXPAND);
void glLightModeliv(glLightModeliv_ARG_EXPAND);
typedef void (*glLightModeliv_PTR)(glLightModeliv_ARG_EXPAND);
void glLightf(glLightf_ARG_EXPAND);
typedef void (*glLightf_PTR)(glLightf_ARG_EXPAND);
void glLightfv(glLightfv_ARG_EXPAND);
typedef void (*glLightfv_PTR)(glLightfv_ARG_EXPAND);
void glLighti(glLighti_ARG_EXPAND);
typedef void (*glLighti_PTR)(glLighti_ARG_EXPAND);
void glLightiv(glLightiv_ARG_EXPAND);
typedef void (*glLightiv_PTR)(glLightiv_ARG_EXPAND);
void glLineStipple(glLineStipple_ARG_EXPAND);
typedef void (*glLineStipple_PTR)(glLineStipple_ARG_EXPAND);
void glLineWidth(glLineWidth_ARG_EXPAND);
typedef void (*glLineWidth_PTR)(glLineWidth_ARG_EXPAND);
void glListBase(glListBase_ARG_EXPAND);
typedef void (*glListBase_PTR)(glListBase_ARG_EXPAND);
void glLoadIdentity(glLoadIdentity_ARG_EXPAND);
typedef void (*glLoadIdentity_PTR)(glLoadIdentity_ARG_EXPAND);
void glLoadMatrixd(glLoadMatrixd_ARG_EXPAND);
typedef void (*glLoadMatrixd_PTR)(glLoadMatrixd_ARG_EXPAND);
void glLoadMatrixf(glLoadMatrixf_ARG_EXPAND);
typedef void (*glLoadMatrixf_PTR)(glLoadMatrixf_ARG_EXPAND);
void glLoadName(glLoadName_ARG_EXPAND);
typedef void (*glLoadName_PTR)(glLoadName_ARG_EXPAND);
void glLoadTransposeMatrixd(glLoadTransposeMatrixd_ARG_EXPAND);
typedef void (*glLoadTransposeMatrixd_PTR)(glLoadTransposeMatrixd_ARG_EXPAND);
void glLoadTransposeMatrixf(glLoadTransposeMatrixf_ARG_EXPAND);
typedef void (*glLoadTransposeMatrixf_PTR)(glLoadTransposeMatrixf_ARG_EXPAND);
void glLogicOp(glLogicOp_ARG_EXPAND);
typedef void (*glLogicOp_PTR)(glLogicOp_ARG_EXPAND);
void glMap1d(glMap1d_ARG_EXPAND);
typedef void (*glMap1d_PTR)(glMap1d_ARG_EXPAND);
void glMap1f(glMap1f_ARG_EXPAND);
typedef void (*glMap1f_PTR)(glMap1f_ARG_EXPAND);
void glMap2d(glMap2d_ARG_EXPAND);
typedef void (*glMap2d_PTR)(glMap2d_ARG_EXPAND);
void glMap2f(glMap2f_ARG_EXPAND);
typedef void (*glMap2f_PTR)(glMap2f_ARG_EXPAND);
GLvoid * glMapBuffer(glMapBuffer_ARG_EXPAND);
typedef GLvoid * (*glMapBuffer_PTR)(glMapBuffer_ARG_EXPAND);
void glMapGrid1d(glMapGrid1d_ARG_EXPAND);
typedef void (*glMapGrid1d_PTR)(glMapGrid1d_ARG_EXPAND);
void glMapGrid1f(glMapGrid1f_ARG_EXPAND);
typedef void (*glMapGrid1f_PTR)(glMapGrid1f_ARG_EXPAND);
void glMapGrid2d(glMapGrid2d_ARG_EXPAND);
typedef void (*glMapGrid2d_PTR)(glMapGrid2d_ARG_EXPAND);
void glMapGrid2f(glMapGrid2f_ARG_EXPAND);
typedef void (*glMapGrid2f_PTR)(glMapGrid2f_ARG_EXPAND);
void glMaterialf(glMaterialf_ARG_EXPAND);
typedef void (*glMaterialf_PTR)(glMaterialf_ARG_EXPAND);
void glMaterialfv(glMaterialfv_ARG_EXPAND);
typedef void (*glMaterialfv_PTR)(glMaterialfv_ARG_EXPAND);
void glMateriali(glMateriali_ARG_EXPAND);
typedef void (*glMateriali_PTR)(glMateriali_ARG_EXPAND);
void glMaterialiv(glMaterialiv_ARG_EXPAND);
typedef void (*glMaterialiv_PTR)(glMaterialiv_ARG_EXPAND);
void glMatrixMode(glMatrixMode_ARG_EXPAND);
typedef void (*glMatrixMode_PTR)(glMatrixMode_ARG_EXPAND);
void glMinmax(glMinmax_ARG_EXPAND);
typedef void (*glMinmax_PTR)(glMinmax_ARG_EXPAND);
void glMultMatrixd(glMultMatrixd_ARG_EXPAND);
typedef void (*glMultMatrixd_PTR)(glMultMatrixd_ARG_EXPAND);
void glMultMatrixf(glMultMatrixf_ARG_EXPAND);
typedef void (*glMultMatrixf_PTR)(glMultMatrixf_ARG_EXPAND);
void glMultTransposeMatrixd(glMultTransposeMatrixd_ARG_EXPAND);
typedef void (*glMultTransposeMatrixd_PTR)(glMultTransposeMatrixd_ARG_EXPAND);
void glMultTransposeMatrixf(glMultTransposeMatrixf_ARG_EXPAND);
typedef void (*glMultTransposeMatrixf_PTR)(glMultTransposeMatrixf_ARG_EXPAND);
void glMultiDrawArrays(glMultiDrawArrays_ARG_EXPAND);
typedef void (*glMultiDrawArrays_PTR)(glMultiDrawArrays_ARG_EXPAND);
void glMultiDrawElements(glMultiDrawElements_ARG_EXPAND);
typedef void (*glMultiDrawElements_PTR)(glMultiDrawElements_ARG_EXPAND);
void glMultiTexCoord1d(glMultiTexCoord1d_ARG_EXPAND);
typedef void (*glMultiTexCoord1d_PTR)(glMultiTexCoord1d_ARG_EXPAND);
void glMultiTexCoord1dv(glMultiTexCoord1dv_ARG_EXPAND);
typedef void (*glMultiTexCoord1dv_PTR)(glMultiTexCoord1dv_ARG_EXPAND);
void glMultiTexCoord1f(glMultiTexCoord1f_ARG_EXPAND);
typedef void (*glMultiTexCoord1f_PTR)(glMultiTexCoord1f_ARG_EXPAND);
void glMultiTexCoord1fv(glMultiTexCoord1fv_ARG_EXPAND);
typedef void (*glMultiTexCoord1fv_PTR)(glMultiTexCoord1fv_ARG_EXPAND);
void glMultiTexCoord1i(glMultiTexCoord1i_ARG_EXPAND);
typedef void (*glMultiTexCoord1i_PTR)(glMultiTexCoord1i_ARG_EXPAND);
void glMultiTexCoord1iv(glMultiTexCoord1iv_ARG_EXPAND);
typedef void (*glMultiTexCoord1iv_PTR)(glMultiTexCoord1iv_ARG_EXPAND);
void glMultiTexCoord1s(glMultiTexCoord1s_ARG_EXPAND);
typedef void (*glMultiTexCoord1s_PTR)(glMultiTexCoord1s_ARG_EXPAND);
void glMultiTexCoord1sv(glMultiTexCoord1sv_ARG_EXPAND);
typedef void (*glMultiTexCoord1sv_PTR)(glMultiTexCoord1sv_ARG_EXPAND);
void glMultiTexCoord2d(glMultiTexCoord2d_ARG_EXPAND);
typedef void (*glMultiTexCoord2d_PTR)(glMultiTexCoord2d_ARG_EXPAND);
void glMultiTexCoord2dv(glMultiTexCoord2dv_ARG_EXPAND);
typedef void (*glMultiTexCoord2dv_PTR)(glMultiTexCoord2dv_ARG_EXPAND);
void glMultiTexCoord2f(glMultiTexCoord2f_ARG_EXPAND);
typedef void (*glMultiTexCoord2f_PTR)(glMultiTexCoord2f_ARG_EXPAND);
void glMultiTexCoord2fv(glMultiTexCoord2fv_ARG_EXPAND);
typedef void (*glMultiTexCoord2fv_PTR)(glMultiTexCoord2fv_ARG_EXPAND);
void glMultiTexCoord2i(glMultiTexCoord2i_ARG_EXPAND);
typedef void (*glMultiTexCoord2i_PTR)(glMultiTexCoord2i_ARG_EXPAND);
void glMultiTexCoord2iv(glMultiTexCoord2iv_ARG_EXPAND);
typedef void (*glMultiTexCoord2iv_PTR)(glMultiTexCoord2iv_ARG_EXPAND);
void glMultiTexCoord2s(glMultiTexCoord2s_ARG_EXPAND);
typedef void (*glMultiTexCoord2s_PTR)(glMultiTexCoord2s_ARG_EXPAND);
void glMultiTexCoord2sv(glMultiTexCoord2sv_ARG_EXPAND);
typedef void (*glMultiTexCoord2sv_PTR)(glMultiTexCoord2sv_ARG_EXPAND);
void glMultiTexCoord3d(glMultiTexCoord3d_ARG_EXPAND);
typedef void (*glMultiTexCoord3d_PTR)(glMultiTexCoord3d_ARG_EXPAND);
void glMultiTexCoord3dv(glMultiTexCoord3dv_ARG_EXPAND);
typedef void (*glMultiTexCoord3dv_PTR)(glMultiTexCoord3dv_ARG_EXPAND);
void glMultiTexCoord3f(glMultiTexCoord3f_ARG_EXPAND);
typedef void (*glMultiTexCoord3f_PTR)(glMultiTexCoord3f_ARG_EXPAND);
void glMultiTexCoord3fv(glMultiTexCoord3fv_ARG_EXPAND);
typedef void (*glMultiTexCoord3fv_PTR)(glMultiTexCoord3fv_ARG_EXPAND);
void glMultiTexCoord3i(glMultiTexCoord3i_ARG_EXPAND);
typedef void (*glMultiTexCoord3i_PTR)(glMultiTexCoord3i_ARG_EXPAND);
void glMultiTexCoord3iv(glMultiTexCoord3iv_ARG_EXPAND);
typedef void (*glMultiTexCoord3iv_PTR)(glMultiTexCoord3iv_ARG_EXPAND);
void glMultiTexCoord3s(glMultiTexCoord3s_ARG_EXPAND);
typedef void (*glMultiTexCoord3s_PTR)(glMultiTexCoord3s_ARG_EXPAND);
void glMultiTexCoord3sv(glMultiTexCoord3sv_ARG_EXPAND);
typedef void (*glMultiTexCoord3sv_PTR)(glMultiTexCoord3sv_ARG_EXPAND);
void glMultiTexCoord4d(glMultiTexCoord4d_ARG_EXPAND);
typedef void (*glMultiTexCoord4d_PTR)(glMultiTexCoord4d_ARG_EXPAND);
void glMultiTexCoord4dv(glMultiTexCoord4dv_ARG_EXPAND);
typedef void (*glMultiTexCoord4dv_PTR)(glMultiTexCoord4dv_ARG_EXPAND);
void glMultiTexCoord4f(glMultiTexCoord4f_ARG_EXPAND);
typedef void (*glMultiTexCoord4f_PTR)(glMultiTexCoord4f_ARG_EXPAND);
void glMultiTexCoord4fv(glMultiTexCoord4fv_ARG_EXPAND);
typedef void (*glMultiTexCoord4fv_PTR)(glMultiTexCoord4fv_ARG_EXPAND);
void glMultiTexCoord4i(glMultiTexCoord4i_ARG_EXPAND);
typedef void (*glMultiTexCoord4i_PTR)(glMultiTexCoord4i_ARG_EXPAND);
void glMultiTexCoord4iv(glMultiTexCoord4iv_ARG_EXPAND);
typedef void (*glMultiTexCoord4iv_PTR)(glMultiTexCoord4iv_ARG_EXPAND);
void glMultiTexCoord4s(glMultiTexCoord4s_ARG_EXPAND);
typedef void (*glMultiTexCoord4s_PTR)(glMultiTexCoord4s_ARG_EXPAND);
void glMultiTexCoord4sv(glMultiTexCoord4sv_ARG_EXPAND);
typedef void (*glMultiTexCoord4sv_PTR)(glMultiTexCoord4sv_ARG_EXPAND);
void glNewList(glNewList_ARG_EXPAND);
typedef void (*glNewList_PTR)(glNewList_ARG_EXPAND);
void glNormal3b(glNormal3b_ARG_EXPAND);
typedef void (*glNormal3b_PTR)(glNormal3b_ARG_EXPAND);
void glNormal3bv(glNormal3bv_ARG_EXPAND);
typedef void (*glNormal3bv_PTR)(glNormal3bv_ARG_EXPAND);
void glNormal3d(glNormal3d_ARG_EXPAND);
typedef void (*glNormal3d_PTR)(glNormal3d_ARG_EXPAND);
void glNormal3dv(glNormal3dv_ARG_EXPAND);
typedef void (*glNormal3dv_PTR)(glNormal3dv_ARG_EXPAND);
void glNormal3f(glNormal3f_ARG_EXPAND);
typedef void (*glNormal3f_PTR)(glNormal3f_ARG_EXPAND);
void glNormal3fv(glNormal3fv_ARG_EXPAND);
typedef void (*glNormal3fv_PTR)(glNormal3fv_ARG_EXPAND);
void glNormal3i(glNormal3i_ARG_EXPAND);
typedef void (*glNormal3i_PTR)(glNormal3i_ARG_EXPAND);
void glNormal3iv(glNormal3iv_ARG_EXPAND);
typedef void (*glNormal3iv_PTR)(glNormal3iv_ARG_EXPAND);
void glNormal3s(glNormal3s_ARG_EXPAND);
typedef void (*glNormal3s_PTR)(glNormal3s_ARG_EXPAND);
void glNormal3sv(glNormal3sv_ARG_EXPAND);
typedef void (*glNormal3sv_PTR)(glNormal3sv_ARG_EXPAND);
void glNormalPointer(glNormalPointer_ARG_EXPAND);
typedef void (*glNormalPointer_PTR)(glNormalPointer_ARG_EXPAND);
void glOrtho(glOrtho_ARG_EXPAND);
typedef void (*glOrtho_PTR)(glOrtho_ARG_EXPAND);
void glPassThrough(glPassThrough_ARG_EXPAND);
typedef void (*glPassThrough_PTR)(glPassThrough_ARG_EXPAND);
void glPixelMapfv(glPixelMapfv_ARG_EXPAND);
typedef void (*glPixelMapfv_PTR)(glPixelMapfv_ARG_EXPAND);
void glPixelMapuiv(glPixelMapuiv_ARG_EXPAND);
typedef void (*glPixelMapuiv_PTR)(glPixelMapuiv_ARG_EXPAND);
void glPixelMapusv(glPixelMapusv_ARG_EXPAND);
typedef void (*glPixelMapusv_PTR)(glPixelMapusv_ARG_EXPAND);
void glPixelStoref(glPixelStoref_ARG_EXPAND);
typedef void (*glPixelStoref_PTR)(glPixelStoref_ARG_EXPAND);
void glPixelStorei(glPixelStorei_ARG_EXPAND);
typedef void (*glPixelStorei_PTR)(glPixelStorei_ARG_EXPAND);
void glPixelTransferf(glPixelTransferf_ARG_EXPAND);
typedef void (*glPixelTransferf_PTR)(glPixelTransferf_ARG_EXPAND);
void glPixelTransferi(glPixelTransferi_ARG_EXPAND);
typedef void (*glPixelTransferi_PTR)(glPixelTransferi_ARG_EXPAND);
void glPixelZoom(glPixelZoom_ARG_EXPAND);
typedef void (*glPixelZoom_PTR)(glPixelZoom_ARG_EXPAND);
void glPointParameterf(glPointParameterf_ARG_EXPAND);
typedef void (*glPointParameterf_PTR)(glPointParameterf_ARG_EXPAND);
void glPointParameterfv(glPointParameterfv_ARG_EXPAND);
typedef void (*glPointParameterfv_PTR)(glPointParameterfv_ARG_EXPAND);
void glPointParameteri(glPointParameteri_ARG_EXPAND);
typedef void (*glPointParameteri_PTR)(glPointParameteri_ARG_EXPAND);
void glPointParameteriv(glPointParameteriv_ARG_EXPAND);
typedef void (*glPointParameteriv_PTR)(glPointParameteriv_ARG_EXPAND);
void glPointSize(glPointSize_ARG_EXPAND);
typedef void (*glPointSize_PTR)(glPointSize_ARG_EXPAND);
void glPolygonMode(glPolygonMode_ARG_EXPAND);
typedef void (*glPolygonMode_PTR)(glPolygonMode_ARG_EXPAND);
void glPolygonOffset(glPolygonOffset_ARG_EXPAND);
typedef void (*glPolygonOffset_PTR)(glPolygonOffset_ARG_EXPAND);
void glPolygonStipple(glPolygonStipple_ARG_EXPAND);
typedef void (*glPolygonStipple_PTR)(glPolygonStipple_ARG_EXPAND);
void glPopAttrib(glPopAttrib_ARG_EXPAND);
typedef void (*glPopAttrib_PTR)(glPopAttrib_ARG_EXPAND);
void glPopClientAttrib(glPopClientAttrib_ARG_EXPAND);
typedef void (*glPopClientAttrib_PTR)(glPopClientAttrib_ARG_EXPAND);
void glPopMatrix(glPopMatrix_ARG_EXPAND);
typedef void (*glPopMatrix_PTR)(glPopMatrix_ARG_EXPAND);
void glPopName(glPopName_ARG_EXPAND);
typedef void (*glPopName_PTR)(glPopName_ARG_EXPAND);
void glPrioritizeTextures(glPrioritizeTextures_ARG_EXPAND);
typedef void (*glPrioritizeTextures_PTR)(glPrioritizeTextures_ARG_EXPAND);
void glPushAttrib(glPushAttrib_ARG_EXPAND);
typedef void (*glPushAttrib_PTR)(glPushAttrib_ARG_EXPAND);
void glPushClientAttrib(glPushClientAttrib_ARG_EXPAND);
typedef void (*glPushClientAttrib_PTR)(glPushClientAttrib_ARG_EXPAND);
void glPushMatrix(glPushMatrix_ARG_EXPAND);
typedef void (*glPushMatrix_PTR)(glPushMatrix_ARG_EXPAND);
void glPushName(glPushName_ARG_EXPAND);
typedef void (*glPushName_PTR)(glPushName_ARG_EXPAND);
void glRasterPos2d(glRasterPos2d_ARG_EXPAND);
typedef void (*glRasterPos2d_PTR)(glRasterPos2d_ARG_EXPAND);
void glRasterPos2dv(glRasterPos2dv_ARG_EXPAND);
typedef void (*glRasterPos2dv_PTR)(glRasterPos2dv_ARG_EXPAND);
void glRasterPos2f(glRasterPos2f_ARG_EXPAND);
typedef void (*glRasterPos2f_PTR)(glRasterPos2f_ARG_EXPAND);
void glRasterPos2fv(glRasterPos2fv_ARG_EXPAND);
typedef void (*glRasterPos2fv_PTR)(glRasterPos2fv_ARG_EXPAND);
void glRasterPos2i(glRasterPos2i_ARG_EXPAND);
typedef void (*glRasterPos2i_PTR)(glRasterPos2i_ARG_EXPAND);
void glRasterPos2iv(glRasterPos2iv_ARG_EXPAND);
typedef void (*glRasterPos2iv_PTR)(glRasterPos2iv_ARG_EXPAND);
void glRasterPos2s(glRasterPos2s_ARG_EXPAND);
typedef void (*glRasterPos2s_PTR)(glRasterPos2s_ARG_EXPAND);
void glRasterPos2sv(glRasterPos2sv_ARG_EXPAND);
typedef void (*glRasterPos2sv_PTR)(glRasterPos2sv_ARG_EXPAND);
void glRasterPos3d(glRasterPos3d_ARG_EXPAND);
typedef void (*glRasterPos3d_PTR)(glRasterPos3d_ARG_EXPAND);
void glRasterPos3dv(glRasterPos3dv_ARG_EXPAND);
typedef void (*glRasterPos3dv_PTR)(glRasterPos3dv_ARG_EXPAND);
void glRasterPos3f(glRasterPos3f_ARG_EXPAND);
typedef void (*glRasterPos3f_PTR)(glRasterPos3f_ARG_EXPAND);
void glRasterPos3fv(glRasterPos3fv_ARG_EXPAND);
typedef void (*glRasterPos3fv_PTR)(glRasterPos3fv_ARG_EXPAND);
void glRasterPos3i(glRasterPos3i_ARG_EXPAND);
typedef void (*glRasterPos3i_PTR)(glRasterPos3i_ARG_EXPAND);
void glRasterPos3iv(glRasterPos3iv_ARG_EXPAND);
typedef void (*glRasterPos3iv_PTR)(glRasterPos3iv_ARG_EXPAND);
void glRasterPos3s(glRasterPos3s_ARG_EXPAND);
typedef void (*glRasterPos3s_PTR)(glRasterPos3s_ARG_EXPAND);
void glRasterPos3sv(glRasterPos3sv_ARG_EXPAND);
typedef void (*glRasterPos3sv_PTR)(glRasterPos3sv_ARG_EXPAND);
void glRasterPos4d(glRasterPos4d_ARG_EXPAND);
typedef void (*glRasterPos4d_PTR)(glRasterPos4d_ARG_EXPAND);
void glRasterPos4dv(glRasterPos4dv_ARG_EXPAND);
typedef void (*glRasterPos4dv_PTR)(glRasterPos4dv_ARG_EXPAND);
void glRasterPos4f(glRasterPos4f_ARG_EXPAND);
typedef void (*glRasterPos4f_PTR)(glRasterPos4f_ARG_EXPAND);
void glRasterPos4fv(glRasterPos4fv_ARG_EXPAND);
typedef void (*glRasterPos4fv_PTR)(glRasterPos4fv_ARG_EXPAND);
void glRasterPos4i(glRasterPos4i_ARG_EXPAND);
typedef void (*glRasterPos4i_PTR)(glRasterPos4i_ARG_EXPAND);
void glRasterPos4iv(glRasterPos4iv_ARG_EXPAND);
typedef void (*glRasterPos4iv_PTR)(glRasterPos4iv_ARG_EXPAND);
void glRasterPos4s(glRasterPos4s_ARG_EXPAND);
typedef void (*glRasterPos4s_PTR)(glRasterPos4s_ARG_EXPAND);
void glRasterPos4sv(glRasterPos4sv_ARG_EXPAND);
typedef void (*glRasterPos4sv_PTR)(glRasterPos4sv_ARG_EXPAND);
void glReadBuffer(glReadBuffer_ARG_EXPAND);
typedef void (*glReadBuffer_PTR)(glReadBuffer_ARG_EXPAND);
void glReadPixels(glReadPixels_ARG_EXPAND);
typedef void (*glReadPixels_PTR)(glReadPixels_ARG_EXPAND);
void glRectd(glRectd_ARG_EXPAND);
typedef void (*glRectd_PTR)(glRectd_ARG_EXPAND);
void glRectdv(glRectdv_ARG_EXPAND);
typedef void (*glRectdv_PTR)(glRectdv_ARG_EXPAND);
void glRectf(glRectf_ARG_EXPAND);
typedef void (*glRectf_PTR)(glRectf_ARG_EXPAND);
void glRectfv(glRectfv_ARG_EXPAND);
typedef void (*glRectfv_PTR)(glRectfv_ARG_EXPAND);
void glRecti(glRecti_ARG_EXPAND);
typedef void (*glRecti_PTR)(glRecti_ARG_EXPAND);
void glRectiv(glRectiv_ARG_EXPAND);
typedef void (*glRectiv_PTR)(glRectiv_ARG_EXPAND);
void glRects(glRects_ARG_EXPAND);
typedef void (*glRects_PTR)(glRects_ARG_EXPAND);
void glRectsv(glRectsv_ARG_EXPAND);
typedef void (*glRectsv_PTR)(glRectsv_ARG_EXPAND);
GLint glRenderMode(glRenderMode_ARG_EXPAND);
typedef GLint (*glRenderMode_PTR)(glRenderMode_ARG_EXPAND);
void glResetHistogram(glResetHistogram_ARG_EXPAND);
typedef void (*glResetHistogram_PTR)(glResetHistogram_ARG_EXPAND);
void glResetMinmax(glResetMinmax_ARG_EXPAND);
typedef void (*glResetMinmax_PTR)(glResetMinmax_ARG_EXPAND);
void glRotated(glRotated_ARG_EXPAND);
typedef void (*glRotated_PTR)(glRotated_ARG_EXPAND);
void glRotatef(glRotatef_ARG_EXPAND);
typedef void (*glRotatef_PTR)(glRotatef_ARG_EXPAND);
void glSampleCoverage(glSampleCoverage_ARG_EXPAND);
typedef void (*glSampleCoverage_PTR)(glSampleCoverage_ARG_EXPAND);
void glScaled(glScaled_ARG_EXPAND);
typedef void (*glScaled_PTR)(glScaled_ARG_EXPAND);
void glScalef(glScalef_ARG_EXPAND);
typedef void (*glScalef_PTR)(glScalef_ARG_EXPAND);
void glScissor(glScissor_ARG_EXPAND);
typedef void (*glScissor_PTR)(glScissor_ARG_EXPAND);
void glSecondaryColor3b(glSecondaryColor3b_ARG_EXPAND);
typedef void (*glSecondaryColor3b_PTR)(glSecondaryColor3b_ARG_EXPAND);
void glSecondaryColor3bv(glSecondaryColor3bv_ARG_EXPAND);
typedef void (*glSecondaryColor3bv_PTR)(glSecondaryColor3bv_ARG_EXPAND);
void glSecondaryColor3d(glSecondaryColor3d_ARG_EXPAND);
typedef void (*glSecondaryColor3d_PTR)(glSecondaryColor3d_ARG_EXPAND);
void glSecondaryColor3dv(glSecondaryColor3dv_ARG_EXPAND);
typedef void (*glSecondaryColor3dv_PTR)(glSecondaryColor3dv_ARG_EXPAND);
void glSecondaryColor3f(glSecondaryColor3f_ARG_EXPAND);
typedef void (*glSecondaryColor3f_PTR)(glSecondaryColor3f_ARG_EXPAND);
void glSecondaryColor3fv(glSecondaryColor3fv_ARG_EXPAND);
typedef void (*glSecondaryColor3fv_PTR)(glSecondaryColor3fv_ARG_EXPAND);
void glSecondaryColor3i(glSecondaryColor3i_ARG_EXPAND);
typedef void (*glSecondaryColor3i_PTR)(glSecondaryColor3i_ARG_EXPAND);
void glSecondaryColor3iv(glSecondaryColor3iv_ARG_EXPAND);
typedef void (*glSecondaryColor3iv_PTR)(glSecondaryColor3iv_ARG_EXPAND);
void glSecondaryColor3s(glSecondaryColor3s_ARG_EXPAND);
typedef void (*glSecondaryColor3s_PTR)(glSecondaryColor3s_ARG_EXPAND);
void glSecondaryColor3sv(glSecondaryColor3sv_ARG_EXPAND);
typedef void (*glSecondaryColor3sv_PTR)(glSecondaryColor3sv_ARG_EXPAND);
void glSecondaryColor3ub(glSecondaryColor3ub_ARG_EXPAND);
typedef void (*glSecondaryColor3ub_PTR)(glSecondaryColor3ub_ARG_EXPAND);
void glSecondaryColor3ubv(glSecondaryColor3ubv_ARG_EXPAND);
typedef void (*glSecondaryColor3ubv_PTR)(glSecondaryColor3ubv_ARG_EXPAND);
void glSecondaryColor3ui(glSecondaryColor3ui_ARG_EXPAND);
typedef void (*glSecondaryColor3ui_PTR)(glSecondaryColor3ui_ARG_EXPAND);
void glSecondaryColor3uiv(glSecondaryColor3uiv_ARG_EXPAND);
typedef void (*glSecondaryColor3uiv_PTR)(glSecondaryColor3uiv_ARG_EXPAND);
void glSecondaryColor3us(glSecondaryColor3us_ARG_EXPAND);
typedef void (*glSecondaryColor3us_PTR)(glSecondaryColor3us_ARG_EXPAND);
void glSecondaryColor3usv(glSecondaryColor3usv_ARG_EXPAND);
typedef void (*glSecondaryColor3usv_PTR)(glSecondaryColor3usv_ARG_EXPAND);
void glSecondaryColorPointer(glSecondaryColorPointer_ARG_EXPAND);
typedef void (*glSecondaryColorPointer_PTR)(glSecondaryColorPointer_ARG_EXPAND);
void glSelectBuffer(glSelectBuffer_ARG_EXPAND);
typedef void (*glSelectBuffer_PTR)(glSelectBuffer_ARG_EXPAND);
void glSeparableFilter2D(glSeparableFilter2D_ARG_EXPAND);
typedef void (*glSeparableFilter2D_PTR)(glSeparableFilter2D_ARG_EXPAND);
void glShadeModel(glShadeModel_ARG_EXPAND);
typedef void (*glShadeModel_PTR)(glShadeModel_ARG_EXPAND);
void glStencilFunc(glStencilFunc_ARG_EXPAND);
typedef void (*glStencilFunc_PTR)(glStencilFunc_ARG_EXPAND);
void glStencilMask(glStencilMask_ARG_EXPAND);
typedef void (*glStencilMask_PTR)(glStencilMask_ARG_EXPAND);
void glStencilOp(glStencilOp_ARG_EXPAND);
typedef void (*glStencilOp_PTR)(glStencilOp_ARG_EXPAND);
void glTexCoord1d(glTexCoord1d_ARG_EXPAND);
typedef void (*glTexCoord1d_PTR)(glTexCoord1d_ARG_EXPAND);
void glTexCoord1dv(glTexCoord1dv_ARG_EXPAND);
typedef void (*glTexCoord1dv_PTR)(glTexCoord1dv_ARG_EXPAND);
void glTexCoord1f(glTexCoord1f_ARG_EXPAND);
typedef void (*glTexCoord1f_PTR)(glTexCoord1f_ARG_EXPAND);
void glTexCoord1fv(glTexCoord1fv_ARG_EXPAND);
typedef void (*glTexCoord1fv_PTR)(glTexCoord1fv_ARG_EXPAND);
void glTexCoord1i(glTexCoord1i_ARG_EXPAND);
typedef void (*glTexCoord1i_PTR)(glTexCoord1i_ARG_EXPAND);
void glTexCoord1iv(glTexCoord1iv_ARG_EXPAND);
typedef void (*glTexCoord1iv_PTR)(glTexCoord1iv_ARG_EXPAND);
void glTexCoord1s(glTexCoord1s_ARG_EXPAND);
typedef void (*glTexCoord1s_PTR)(glTexCoord1s_ARG_EXPAND);
void glTexCoord1sv(glTexCoord1sv_ARG_EXPAND);
typedef void (*glTexCoord1sv_PTR)(glTexCoord1sv_ARG_EXPAND);
void glTexCoord2d(glTexCoord2d_ARG_EXPAND);
typedef void (*glTexCoord2d_PTR)(glTexCoord2d_ARG_EXPAND);
void glTexCoord2dv(glTexCoord2dv_ARG_EXPAND);
typedef void (*glTexCoord2dv_PTR)(glTexCoord2dv_ARG_EXPAND);
void glTexCoord2f(glTexCoord2f_ARG_EXPAND);
typedef void (*glTexCoord2f_PTR)(glTexCoord2f_ARG_EXPAND);
void glTexCoord2fv(glTexCoord2fv_ARG_EXPAND);
typedef void (*glTexCoord2fv_PTR)(glTexCoord2fv_ARG_EXPAND);
void glTexCoord2i(glTexCoord2i_ARG_EXPAND);
typedef void (*glTexCoord2i_PTR)(glTexCoord2i_ARG_EXPAND);
void glTexCoord2iv(glTexCoord2iv_ARG_EXPAND);
typedef void (*glTexCoord2iv_PTR)(glTexCoord2iv_ARG_EXPAND);
void glTexCoord2s(glTexCoord2s_ARG_EXPAND);
typedef void (*glTexCoord2s_PTR)(glTexCoord2s_ARG_EXPAND);
void glTexCoord2sv(glTexCoord2sv_ARG_EXPAND);
typedef void (*glTexCoord2sv_PTR)(glTexCoord2sv_ARG_EXPAND);
void glTexCoord3d(glTexCoord3d_ARG_EXPAND);
typedef void (*glTexCoord3d_PTR)(glTexCoord3d_ARG_EXPAND);
void glTexCoord3dv(glTexCoord3dv_ARG_EXPAND);
typedef void (*glTexCoord3dv_PTR)(glTexCoord3dv_ARG_EXPAND);
void glTexCoord3f(glTexCoord3f_ARG_EXPAND);
typedef void (*glTexCoord3f_PTR)(glTexCoord3f_ARG_EXPAND);
void glTexCoord3fv(glTexCoord3fv_ARG_EXPAND);
typedef void (*glTexCoord3fv_PTR)(glTexCoord3fv_ARG_EXPAND);
void glTexCoord3i(glTexCoord3i_ARG_EXPAND);
typedef void (*glTexCoord3i_PTR)(glTexCoord3i_ARG_EXPAND);
void glTexCoord3iv(glTexCoord3iv_ARG_EXPAND);
typedef void (*glTexCoord3iv_PTR)(glTexCoord3iv_ARG_EXPAND);
void glTexCoord3s(glTexCoord3s_ARG_EXPAND);
typedef void (*glTexCoord3s_PTR)(glTexCoord3s_ARG_EXPAND);
void glTexCoord3sv(glTexCoord3sv_ARG_EXPAND);
typedef void (*glTexCoord3sv_PTR)(glTexCoord3sv_ARG_EXPAND);
void glTexCoord4d(glTexCoord4d_ARG_EXPAND);
typedef void (*glTexCoord4d_PTR)(glTexCoord4d_ARG_EXPAND);
void glTexCoord4dv(glTexCoord4dv_ARG_EXPAND);
typedef void (*glTexCoord4dv_PTR)(glTexCoord4dv_ARG_EXPAND);
void glTexCoord4f(glTexCoord4f_ARG_EXPAND);
typedef void (*glTexCoord4f_PTR)(glTexCoord4f_ARG_EXPAND);
void glTexCoord4fv(glTexCoord4fv_ARG_EXPAND);
typedef void (*glTexCoord4fv_PTR)(glTexCoord4fv_ARG_EXPAND);
void glTexCoord4i(glTexCoord4i_ARG_EXPAND);
typedef void (*glTexCoord4i_PTR)(glTexCoord4i_ARG_EXPAND);
void glTexCoord4iv(glTexCoord4iv_ARG_EXPAND);
typedef void (*glTexCoord4iv_PTR)(glTexCoord4iv_ARG_EXPAND);
void glTexCoord4s(glTexCoord4s_ARG_EXPAND);
typedef void (*glTexCoord4s_PTR)(glTexCoord4s_ARG_EXPAND);
void glTexCoord4sv(glTexCoord4sv_ARG_EXPAND);
typedef void (*glTexCoord4sv_PTR)(glTexCoord4sv_ARG_EXPAND);
void glTexCoordPointer(glTexCoordPointer_ARG_EXPAND);
typedef void (*glTexCoordPointer_PTR)(glTexCoordPointer_ARG_EXPAND);
void glTexEnvf(glTexEnvf_ARG_EXPAND);
typedef void (*glTexEnvf_PTR)(glTexEnvf_ARG_EXPAND);
void glTexEnvfv(glTexEnvfv_ARG_EXPAND);
typedef void (*glTexEnvfv_PTR)(glTexEnvfv_ARG_EXPAND);
void glTexEnvi(glTexEnvi_ARG_EXPAND);
typedef void (*glTexEnvi_PTR)(glTexEnvi_ARG_EXPAND);
void glTexEnviv(glTexEnviv_ARG_EXPAND);
typedef void (*glTexEnviv_PTR)(glTexEnviv_ARG_EXPAND);
void glTexGend(glTexGend_ARG_EXPAND);
typedef void (*glTexGend_PTR)(glTexGend_ARG_EXPAND);
void glTexGendv(glTexGendv_ARG_EXPAND);
typedef void (*glTexGendv_PTR)(glTexGendv_ARG_EXPAND);
void glTexGenf(glTexGenf_ARG_EXPAND);
typedef void (*glTexGenf_PTR)(glTexGenf_ARG_EXPAND);
void glTexGenfv(glTexGenfv_ARG_EXPAND);
typedef void (*glTexGenfv_PTR)(glTexGenfv_ARG_EXPAND);
void glTexGeni(glTexGeni_ARG_EXPAND);
typedef void (*glTexGeni_PTR)(glTexGeni_ARG_EXPAND);
void glTexGeniv(glTexGeniv_ARG_EXPAND);
typedef void (*glTexGeniv_PTR)(glTexGeniv_ARG_EXPAND);
void glTexImage1D(glTexImage1D_ARG_EXPAND);
typedef void (*glTexImage1D_PTR)(glTexImage1D_ARG_EXPAND);
void glTexImage2D(glTexImage2D_ARG_EXPAND);
typedef void (*glTexImage2D_PTR)(glTexImage2D_ARG_EXPAND);
void glTexImage3D(glTexImage3D_ARG_EXPAND);
typedef void (*glTexImage3D_PTR)(glTexImage3D_ARG_EXPAND);
void glTexParameterf(glTexParameterf_ARG_EXPAND);
typedef void (*glTexParameterf_PTR)(glTexParameterf_ARG_EXPAND);
void glTexParameterfv(glTexParameterfv_ARG_EXPAND);
typedef void (*glTexParameterfv_PTR)(glTexParameterfv_ARG_EXPAND);
void glTexParameteri(glTexParameteri_ARG_EXPAND);
typedef void (*glTexParameteri_PTR)(glTexParameteri_ARG_EXPAND);
void glTexParameteriv(glTexParameteriv_ARG_EXPAND);
typedef void (*glTexParameteriv_PTR)(glTexParameteriv_ARG_EXPAND);
void glTexSubImage1D(glTexSubImage1D_ARG_EXPAND);
typedef void (*glTexSubImage1D_PTR)(glTexSubImage1D_ARG_EXPAND);
void glTexSubImage2D(glTexSubImage2D_ARG_EXPAND);
typedef void (*glTexSubImage2D_PTR)(glTexSubImage2D_ARG_EXPAND);
void glTexSubImage3D(glTexSubImage3D_ARG_EXPAND);
typedef void (*glTexSubImage3D_PTR)(glTexSubImage3D_ARG_EXPAND);
void glTranslated(glTranslated_ARG_EXPAND);
typedef void (*glTranslated_PTR)(glTranslated_ARG_EXPAND);
void glTranslatef(glTranslatef_ARG_EXPAND);
typedef void (*glTranslatef_PTR)(glTranslatef_ARG_EXPAND);
GLboolean glUnmapBuffer(glUnmapBuffer_ARG_EXPAND);
typedef GLboolean (*glUnmapBuffer_PTR)(glUnmapBuffer_ARG_EXPAND);
void glVertex2d(glVertex2d_ARG_EXPAND);
typedef void (*glVertex2d_PTR)(glVertex2d_ARG_EXPAND);
void glVertex2dv(glVertex2dv_ARG_EXPAND);
typedef void (*glVertex2dv_PTR)(glVertex2dv_ARG_EXPAND);
void glVertex2f(glVertex2f_ARG_EXPAND);
typedef void (*glVertex2f_PTR)(glVertex2f_ARG_EXPAND);
void glVertex2fv(glVertex2fv_ARG_EXPAND);
typedef void (*glVertex2fv_PTR)(glVertex2fv_ARG_EXPAND);
void glVertex2i(glVertex2i_ARG_EXPAND);
typedef void (*glVertex2i_PTR)(glVertex2i_ARG_EXPAND);
void glVertex2iv(glVertex2iv_ARG_EXPAND);
typedef void (*glVertex2iv_PTR)(glVertex2iv_ARG_EXPAND);
void glVertex2s(glVertex2s_ARG_EXPAND);
typedef void (*glVertex2s_PTR)(glVertex2s_ARG_EXPAND);
void glVertex2sv(glVertex2sv_ARG_EXPAND);
typedef void (*glVertex2sv_PTR)(glVertex2sv_ARG_EXPAND);
void glVertex3d(glVertex3d_ARG_EXPAND);
typedef void (*glVertex3d_PTR)(glVertex3d_ARG_EXPAND);
void glVertex3dv(glVertex3dv_ARG_EXPAND);
typedef void (*glVertex3dv_PTR)(glVertex3dv_ARG_EXPAND);
void glVertex3f(glVertex3f_ARG_EXPAND);
typedef void (*glVertex3f_PTR)(glVertex3f_ARG_EXPAND);
void glVertex3fv(glVertex3fv_ARG_EXPAND);
typedef void (*glVertex3fv_PTR)(glVertex3fv_ARG_EXPAND);
void glVertex3i(glVertex3i_ARG_EXPAND);
typedef void (*glVertex3i_PTR)(glVertex3i_ARG_EXPAND);
void glVertex3iv(glVertex3iv_ARG_EXPAND);
typedef void (*glVertex3iv_PTR)(glVertex3iv_ARG_EXPAND);
void glVertex3s(glVertex3s_ARG_EXPAND);
typedef void (*glVertex3s_PTR)(glVertex3s_ARG_EXPAND);
void glVertex3sv(glVertex3sv_ARG_EXPAND);
typedef void (*glVertex3sv_PTR)(glVertex3sv_ARG_EXPAND);
void glVertex4d(glVertex4d_ARG_EXPAND);
typedef void (*glVertex4d_PTR)(glVertex4d_ARG_EXPAND);
void glVertex4dv(glVertex4dv_ARG_EXPAND);
typedef void (*glVertex4dv_PTR)(glVertex4dv_ARG_EXPAND);
void glVertex4f(glVertex4f_ARG_EXPAND);
typedef void (*glVertex4f_PTR)(glVertex4f_ARG_EXPAND);
void glVertex4fv(glVertex4fv_ARG_EXPAND);
typedef void (*glVertex4fv_PTR)(glVertex4fv_ARG_EXPAND);
void glVertex4i(glVertex4i_ARG_EXPAND);
typedef void (*glVertex4i_PTR)(glVertex4i_ARG_EXPAND);
void glVertex4iv(glVertex4iv_ARG_EXPAND);
typedef void (*glVertex4iv_PTR)(glVertex4iv_ARG_EXPAND);
void glVertex4s(glVertex4s_ARG_EXPAND);
typedef void (*glVertex4s_PTR)(glVertex4s_ARG_EXPAND);
void glVertex4sv(glVertex4sv_ARG_EXPAND);
typedef void (*glVertex4sv_PTR)(glVertex4sv_ARG_EXPAND);
void glVertexPointer(glVertexPointer_ARG_EXPAND);
typedef void (*glVertexPointer_PTR)(glVertexPointer_ARG_EXPAND);
void glViewport(glViewport_ARG_EXPAND);
typedef void (*glViewport_PTR)(glViewport_ARG_EXPAND);
void glWindowPos2d(glWindowPos2d_ARG_EXPAND);
typedef void (*glWindowPos2d_PTR)(glWindowPos2d_ARG_EXPAND);
void glWindowPos2dv(glWindowPos2dv_ARG_EXPAND);
typedef void (*glWindowPos2dv_PTR)(glWindowPos2dv_ARG_EXPAND);
void glWindowPos2f(glWindowPos2f_ARG_EXPAND);
typedef void (*glWindowPos2f_PTR)(glWindowPos2f_ARG_EXPAND);
void glWindowPos2fv(glWindowPos2fv_ARG_EXPAND);
typedef void (*glWindowPos2fv_PTR)(glWindowPos2fv_ARG_EXPAND);
void glWindowPos2i(glWindowPos2i_ARG_EXPAND);
typedef void (*glWindowPos2i_PTR)(glWindowPos2i_ARG_EXPAND);
void glWindowPos2iv(glWindowPos2iv_ARG_EXPAND);
typedef void (*glWindowPos2iv_PTR)(glWindowPos2iv_ARG_EXPAND);
void glWindowPos2s(glWindowPos2s_ARG_EXPAND);
typedef void (*glWindowPos2s_PTR)(glWindowPos2s_ARG_EXPAND);
void glWindowPos2sv(glWindowPos2sv_ARG_EXPAND);
typedef void (*glWindowPos2sv_PTR)(glWindowPos2sv_ARG_EXPAND);
void glWindowPos3d(glWindowPos3d_ARG_EXPAND);
typedef void (*glWindowPos3d_PTR)(glWindowPos3d_ARG_EXPAND);
void glWindowPos3dv(glWindowPos3dv_ARG_EXPAND);
typedef void (*glWindowPos3dv_PTR)(glWindowPos3dv_ARG_EXPAND);
void glWindowPos3f(glWindowPos3f_ARG_EXPAND);
typedef void (*glWindowPos3f_PTR)(glWindowPos3f_ARG_EXPAND);
void glWindowPos3fv(glWindowPos3fv_ARG_EXPAND);
typedef void (*glWindowPos3fv_PTR)(glWindowPos3fv_ARG_EXPAND);
void glWindowPos3i(glWindowPos3i_ARG_EXPAND);
typedef void (*glWindowPos3i_PTR)(glWindowPos3i_ARG_EXPAND);
void glWindowPos3iv(glWindowPos3iv_ARG_EXPAND);
typedef void (*glWindowPos3iv_PTR)(glWindowPos3iv_ARG_EXPAND);
void glWindowPos3s(glWindowPos3s_ARG_EXPAND);
typedef void (*glWindowPos3s_PTR)(glWindowPos3s_ARG_EXPAND);
void glWindowPos3sv(glWindowPos3sv_ARG_EXPAND);
typedef void (*glWindowPos3sv_PTR)(glWindowPos3sv_ARG_EXPAND);
int glXBindHyperpipeSGIX(glXBindHyperpipeSGIX_ARG_EXPAND);
typedef int (*glXBindHyperpipeSGIX_PTR)(glXBindHyperpipeSGIX_ARG_EXPAND);
void glXBindSwapBarrierSGIX(glXBindSwapBarrierSGIX_ARG_EXPAND);
typedef void (*glXBindSwapBarrierSGIX_PTR)(glXBindSwapBarrierSGIX_ARG_EXPAND);
void glXChangeDrawableAttributes(glXChangeDrawableAttributes_ARG_EXPAND);
typedef void (*glXChangeDrawableAttributes_PTR)(glXChangeDrawableAttributes_ARG_EXPAND);
void glXChangeDrawableAttributesSGIX(glXChangeDrawableAttributesSGIX_ARG_EXPAND);
typedef void (*glXChangeDrawableAttributesSGIX_PTR)(glXChangeDrawableAttributesSGIX_ARG_EXPAND);
GLXFBConfig * glXChooseFBConfig(glXChooseFBConfig_ARG_EXPAND);
typedef GLXFBConfig * (*glXChooseFBConfig_PTR)(glXChooseFBConfig_ARG_EXPAND);
XVisualInfo * glXChooseVisual(glXChooseVisual_ARG_EXPAND);
typedef XVisualInfo * (*glXChooseVisual_PTR)(glXChooseVisual_ARG_EXPAND);
void glXClientInfo(glXClientInfo_ARG_EXPAND);
typedef void (*glXClientInfo_PTR)(glXClientInfo_ARG_EXPAND);
void glXCopyContext(glXCopyContext_ARG_EXPAND);
typedef void (*glXCopyContext_PTR)(glXCopyContext_ARG_EXPAND);
GLXContext glXCreateContext(glXCreateContext_ARG_EXPAND);
typedef GLXContext (*glXCreateContext_PTR)(glXCreateContext_ARG_EXPAND);
void glXCreateContextWithConfigSGIX(glXCreateContextWithConfigSGIX_ARG_EXPAND);
typedef void (*glXCreateContextWithConfigSGIX_PTR)(glXCreateContextWithConfigSGIX_ARG_EXPAND);
void glXCreateGLXPbufferSGIX(glXCreateGLXPbufferSGIX_ARG_EXPAND);
typedef void (*glXCreateGLXPbufferSGIX_PTR)(glXCreateGLXPbufferSGIX_ARG_EXPAND);
GLXPixmap glXCreateGLXPixmap(glXCreateGLXPixmap_ARG_EXPAND);
typedef GLXPixmap (*glXCreateGLXPixmap_PTR)(glXCreateGLXPixmap_ARG_EXPAND);
void glXCreateGLXPixmapWithConfigSGIX(glXCreateGLXPixmapWithConfigSGIX_ARG_EXPAND);
typedef void (*glXCreateGLXPixmapWithConfigSGIX_PTR)(glXCreateGLXPixmapWithConfigSGIX_ARG_EXPAND);
void glXCreateGLXVideoSourceSGIX(glXCreateGLXVideoSourceSGIX_ARG_EXPAND);
typedef void (*glXCreateGLXVideoSourceSGIX_PTR)(glXCreateGLXVideoSourceSGIX_ARG_EXPAND);
GLXContext glXCreateNewContext(glXCreateNewContext_ARG_EXPAND);
typedef GLXContext (*glXCreateNewContext_PTR)(glXCreateNewContext_ARG_EXPAND);
GLXPbuffer glXCreatePbuffer(glXCreatePbuffer_ARG_EXPAND);
typedef GLXPbuffer (*glXCreatePbuffer_PTR)(glXCreatePbuffer_ARG_EXPAND);
GLXPixmap glXCreatePixmap(glXCreatePixmap_ARG_EXPAND);
typedef GLXPixmap (*glXCreatePixmap_PTR)(glXCreatePixmap_ARG_EXPAND);
GLXWindow glXCreateWindow(glXCreateWindow_ARG_EXPAND);
typedef GLXWindow (*glXCreateWindow_PTR)(glXCreateWindow_ARG_EXPAND);
void glXDestroyContext(glXDestroyContext_ARG_EXPAND);
typedef void (*glXDestroyContext_PTR)(glXDestroyContext_ARG_EXPAND);
void glXDestroyGLXPbufferSGIX(glXDestroyGLXPbufferSGIX_ARG_EXPAND);
typedef void (*glXDestroyGLXPbufferSGIX_PTR)(glXDestroyGLXPbufferSGIX_ARG_EXPAND);
void glXDestroyGLXPixmap(glXDestroyGLXPixmap_ARG_EXPAND);
typedef void (*glXDestroyGLXPixmap_PTR)(glXDestroyGLXPixmap_ARG_EXPAND);
void glXDestroyGLXVideoSourceSGIX(glXDestroyGLXVideoSourceSGIX_ARG_EXPAND);
typedef void (*glXDestroyGLXVideoSourceSGIX_PTR)(glXDestroyGLXVideoSourceSGIX_ARG_EXPAND);
int glXDestroyHyperpipeConfigSGIX(glXDestroyHyperpipeConfigSGIX_ARG_EXPAND);
typedef int (*glXDestroyHyperpipeConfigSGIX_PTR)(glXDestroyHyperpipeConfigSGIX_ARG_EXPAND);
void glXDestroyPbuffer(glXDestroyPbuffer_ARG_EXPAND);
typedef void (*glXDestroyPbuffer_PTR)(glXDestroyPbuffer_ARG_EXPAND);
void glXDestroyPixmap(glXDestroyPixmap_ARG_EXPAND);
typedef void (*glXDestroyPixmap_PTR)(glXDestroyPixmap_ARG_EXPAND);
void glXDestroyWindow(glXDestroyWindow_ARG_EXPAND);
typedef void (*glXDestroyWindow_PTR)(glXDestroyWindow_ARG_EXPAND);
const char * glXGetClientString(glXGetClientString_ARG_EXPAND);
typedef const char * (*glXGetClientString_PTR)(glXGetClientString_ARG_EXPAND);
int glXGetConfig(glXGetConfig_ARG_EXPAND);
typedef int (*glXGetConfig_PTR)(glXGetConfig_ARG_EXPAND);
GLXContext glXGetCurrentContext(glXGetCurrentContext_ARG_EXPAND);
typedef GLXContext (*glXGetCurrentContext_PTR)(glXGetCurrentContext_ARG_EXPAND);
Display * glXGetCurrentDisplay(glXGetCurrentDisplay_ARG_EXPAND);
typedef Display * (*glXGetCurrentDisplay_PTR)(glXGetCurrentDisplay_ARG_EXPAND);
GLXDrawable glXGetCurrentDrawable(glXGetCurrentDrawable_ARG_EXPAND);
typedef GLXDrawable (*glXGetCurrentDrawable_PTR)(glXGetCurrentDrawable_ARG_EXPAND);
GLXDrawable glXGetCurrentReadDrawable(glXGetCurrentReadDrawable_ARG_EXPAND);
typedef GLXDrawable (*glXGetCurrentReadDrawable_PTR)(glXGetCurrentReadDrawable_ARG_EXPAND);
void glXGetDrawableAttributes(glXGetDrawableAttributes_ARG_EXPAND);
typedef void (*glXGetDrawableAttributes_PTR)(glXGetDrawableAttributes_ARG_EXPAND);
void glXGetDrawableAttributesSGIX(glXGetDrawableAttributesSGIX_ARG_EXPAND);
typedef void (*glXGetDrawableAttributesSGIX_PTR)(glXGetDrawableAttributesSGIX_ARG_EXPAND);
int glXGetFBConfigAttrib(glXGetFBConfigAttrib_ARG_EXPAND);
typedef int (*glXGetFBConfigAttrib_PTR)(glXGetFBConfigAttrib_ARG_EXPAND);
GLXFBConfig * glXGetFBConfigs(glXGetFBConfigs_ARG_EXPAND);
typedef GLXFBConfig * (*glXGetFBConfigs_PTR)(glXGetFBConfigs_ARG_EXPAND);
void glXGetFBConfigsSGIX(glXGetFBConfigsSGIX_ARG_EXPAND);
typedef void (*glXGetFBConfigsSGIX_PTR)(glXGetFBConfigsSGIX_ARG_EXPAND);
__GLXextFuncPtr glXGetProcAddress(glXGetProcAddress_ARG_EXPAND);
typedef __GLXextFuncPtr (*glXGetProcAddress_PTR)(glXGetProcAddress_ARG_EXPAND);
void glXGetSelectedEvent(glXGetSelectedEvent_ARG_EXPAND);
typedef void (*glXGetSelectedEvent_PTR)(glXGetSelectedEvent_ARG_EXPAND);
void glXGetVisualConfigs(glXGetVisualConfigs_ARG_EXPAND);
typedef void (*glXGetVisualConfigs_PTR)(glXGetVisualConfigs_ARG_EXPAND);
XVisualInfo * glXGetVisualFromFBConfig(glXGetVisualFromFBConfig_ARG_EXPAND);
typedef XVisualInfo * (*glXGetVisualFromFBConfig_PTR)(glXGetVisualFromFBConfig_ARG_EXPAND);
int glXHyperpipeAttribSGIX(glXHyperpipeAttribSGIX_ARG_EXPAND);
typedef int (*glXHyperpipeAttribSGIX_PTR)(glXHyperpipeAttribSGIX_ARG_EXPAND);
int glXHyperpipeConfigSGIX(glXHyperpipeConfigSGIX_ARG_EXPAND);
typedef int (*glXHyperpipeConfigSGIX_PTR)(glXHyperpipeConfigSGIX_ARG_EXPAND);
Bool glXIsDirect(glXIsDirect_ARG_EXPAND);
typedef Bool (*glXIsDirect_PTR)(glXIsDirect_ARG_EXPAND);
void glXJoinSwapGroupSGIX(glXJoinSwapGroupSGIX_ARG_EXPAND);
typedef void (*glXJoinSwapGroupSGIX_PTR)(glXJoinSwapGroupSGIX_ARG_EXPAND);
Bool glXMakeContextCurrent(glXMakeContextCurrent_ARG_EXPAND);
typedef Bool (*glXMakeContextCurrent_PTR)(glXMakeContextCurrent_ARG_EXPAND);
Bool glXMakeCurrent(glXMakeCurrent_ARG_EXPAND);
typedef Bool (*glXMakeCurrent_PTR)(glXMakeCurrent_ARG_EXPAND);
void glXMakeCurrentReadSGI(glXMakeCurrentReadSGI_ARG_EXPAND);
typedef void (*glXMakeCurrentReadSGI_PTR)(glXMakeCurrentReadSGI_ARG_EXPAND);
int glXQueryContext(glXQueryContext_ARG_EXPAND);
typedef int (*glXQueryContext_PTR)(glXQueryContext_ARG_EXPAND);
void glXQueryContextInfoEXT(glXQueryContextInfoEXT_ARG_EXPAND);
typedef void (*glXQueryContextInfoEXT_PTR)(glXQueryContextInfoEXT_ARG_EXPAND);
void glXQueryDrawable(glXQueryDrawable_ARG_EXPAND);
typedef void (*glXQueryDrawable_PTR)(glXQueryDrawable_ARG_EXPAND);
Bool glXQueryExtension(glXQueryExtension_ARG_EXPAND);
typedef Bool (*glXQueryExtension_PTR)(glXQueryExtension_ARG_EXPAND);
const char * glXQueryExtensionsString(glXQueryExtensionsString_ARG_EXPAND);
typedef const char * (*glXQueryExtensionsString_PTR)(glXQueryExtensionsString_ARG_EXPAND);
int glXQueryHyperpipeAttribSGIX(glXQueryHyperpipeAttribSGIX_ARG_EXPAND);
typedef int (*glXQueryHyperpipeAttribSGIX_PTR)(glXQueryHyperpipeAttribSGIX_ARG_EXPAND);
int glXQueryHyperpipeBestAttribSGIX(glXQueryHyperpipeBestAttribSGIX_ARG_EXPAND);
typedef int (*glXQueryHyperpipeBestAttribSGIX_PTR)(glXQueryHyperpipeBestAttribSGIX_ARG_EXPAND);
GLXHyperpipeConfigSGIX * glXQueryHyperpipeConfigSGIX(glXQueryHyperpipeConfigSGIX_ARG_EXPAND);
typedef GLXHyperpipeConfigSGIX * (*glXQueryHyperpipeConfigSGIX_PTR)(glXQueryHyperpipeConfigSGIX_ARG_EXPAND);
GLXHyperpipeNetworkSGIX * glXQueryHyperpipeNetworkSGIX(glXQueryHyperpipeNetworkSGIX_ARG_EXPAND);
typedef GLXHyperpipeNetworkSGIX * (*glXQueryHyperpipeNetworkSGIX_PTR)(glXQueryHyperpipeNetworkSGIX_ARG_EXPAND);
void glXQueryMaxSwapBarriersSGIX(glXQueryMaxSwapBarriersSGIX_ARG_EXPAND);
typedef void (*glXQueryMaxSwapBarriersSGIX_PTR)(glXQueryMaxSwapBarriersSGIX_ARG_EXPAND);
const char * glXQueryServerString(glXQueryServerString_ARG_EXPAND);
typedef const char * (*glXQueryServerString_PTR)(glXQueryServerString_ARG_EXPAND);
Bool glXQueryVersion(glXQueryVersion_ARG_EXPAND);
typedef Bool (*glXQueryVersion_PTR)(glXQueryVersion_ARG_EXPAND);
void glXRender(glXRender_ARG_EXPAND);
typedef void (*glXRender_PTR)(glXRender_ARG_EXPAND);
void glXRenderLarge(glXRenderLarge_ARG_EXPAND);
typedef void (*glXRenderLarge_PTR)(glXRenderLarge_ARG_EXPAND);
void glXSelectEvent(glXSelectEvent_ARG_EXPAND);
typedef void (*glXSelectEvent_PTR)(glXSelectEvent_ARG_EXPAND);
void glXSwapBuffers(glXSwapBuffers_ARG_EXPAND);
typedef void (*glXSwapBuffers_PTR)(glXSwapBuffers_ARG_EXPAND);
void glXSwapIntervalSGI(glXSwapIntervalSGI_ARG_EXPAND);
typedef void (*glXSwapIntervalSGI_PTR)(glXSwapIntervalSGI_ARG_EXPAND);
void glXUseXFont(glXUseXFont_ARG_EXPAND);
typedef void (*glXUseXFont_PTR)(glXUseXFont_ARG_EXPAND);
void glXVendorPrivate(glXVendorPrivate_ARG_EXPAND);
typedef void (*glXVendorPrivate_PTR)(glXVendorPrivate_ARG_EXPAND);
void glXVendorPrivateWithReply(glXVendorPrivateWithReply_ARG_EXPAND);
typedef void (*glXVendorPrivateWithReply_PTR)(glXVendorPrivateWithReply_ARG_EXPAND);
void glXWaitGL(glXWaitGL_ARG_EXPAND);
typedef void (*glXWaitGL_PTR)(glXWaitGL_ARG_EXPAND);
void glXWaitX(glXWaitX_ARG_EXPAND);
typedef void (*glXWaitX_PTR)(glXWaitX_ARG_EXPAND);

#endif
