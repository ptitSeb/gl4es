#include <GL/gl.h>
#include <GL/glx.h>

#ifndef GL_H
#define GL_H

typedef struct {
    int format;
    void *func;
    void *args;
} UnknownCall;

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
    FORMAT_void_uint32_t_uint32_t_uint32_t,
    FORMAT_void_uint32_t_uint32_t_uint32_t_uint32_t,
    FORMAT_void_uint32_t_uint32_t_uint32_t_uint32_t_uint32_t_uint32_t,
    FORMAT_int_Display___GENPT___int_int_int_const_void___GENPT__,
    FORMAT_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__,
    FORMAT_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__,
    FORMAT_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__,
    FORMAT_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__,
    FORMAT_void_uint32_t___GENPT___uint32_t___GENPT__,
    FORMAT_GLXFBConfig___GENPT___Display___GENPT___int_const_int___GENPT___int___GENPT__,
    FORMAT_GLXContext_Display___GENPT___GLXFBConfig_int_GLXContext_Bool,
    FORMAT_GLXPbuffer_Display___GENPT___GLXFBConfig_const_int___GENPT__,
    FORMAT_GLXPixmap_Display___GENPT___GLXFBConfig_Pixmap_const_int___GENPT__,
    FORMAT_GLXWindow_Display___GENPT___GLXFBConfig_Window_const_int___GENPT__,
    FORMAT_void_Display___GENPT___GLXPbuffer,
    FORMAT_void_Display___GENPT___GLXPixmap,
    FORMAT_void_Display___GENPT___GLXWindow,
    FORMAT_Display___GENPT__,
    FORMAT_GLXDrawable,
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
typedef void (*FUNC_void_GLenum)(GLenum texture);
typedef struct {
    GLenum a1;
} ARGS_void_GLenum;
typedef struct {
    int format;
    FUNC_void_GLenum func;
    ARGS_void_GLenum args;
} PACKED_void_GLenum;
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
typedef void (*FUNC_void_GLint)(GLint i);
typedef struct {
    GLint a1;
} ARGS_void_GLint;
typedef struct {
    int format;
    FUNC_void_GLint func;
    ARGS_void_GLint args;
} PACKED_void_GLint;
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
typedef void (*FUNC_void_GLuint)(GLuint list);
typedef struct {
    GLuint a1;
} ARGS_void_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint func;
    ARGS_void_GLuint args;
} PACKED_void_GLuint;
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
typedef void (*FUNC_void_GLbitfield)(GLbitfield mask);
typedef struct {
    GLbitfield a1;
} ARGS_void_GLbitfield;
typedef struct {
    int format;
    FUNC_void_GLbitfield func;
    ARGS_void_GLbitfield args;
} PACKED_void_GLbitfield;
typedef void (*FUNC_void_GLdouble)(GLdouble depth);
typedef struct {
    GLdouble a1;
} ARGS_void_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLdouble func;
    ARGS_void_GLdouble args;
} PACKED_void_GLdouble;
typedef void (*FUNC_void_GLfloat)(GLfloat c);
typedef struct {
    GLfloat a1;
} ARGS_void_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLfloat func;
    ARGS_void_GLfloat args;
} PACKED_void_GLfloat;
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
typedef void (*FUNC_void_const_GLbyte___GENPT__)(const GLbyte * v);
typedef struct {
    const GLbyte * a1;
} ARGS_void_const_GLbyte___GENPT__;
typedef struct {
    int format;
    FUNC_void_const_GLbyte___GENPT__ func;
    ARGS_void_const_GLbyte___GENPT__ args;
} PACKED_void_const_GLbyte___GENPT__;
typedef void (*FUNC_void_GLdouble_GLdouble_GLdouble)(GLdouble red, GLdouble green, GLdouble blue);
typedef struct {
    GLdouble a1;
    GLdouble a2;
    GLdouble a3;
} ARGS_void_GLdouble_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLdouble_GLdouble_GLdouble func;
    ARGS_void_GLdouble_GLdouble_GLdouble args;
} PACKED_void_GLdouble_GLdouble_GLdouble;
typedef void (*FUNC_void_const_GLdouble___GENPT__)(const GLdouble * v);
typedef struct {
    const GLdouble * a1;
} ARGS_void_const_GLdouble___GENPT__;
typedef struct {
    int format;
    FUNC_void_const_GLdouble___GENPT__ func;
    ARGS_void_const_GLdouble___GENPT__ args;
} PACKED_void_const_GLdouble___GENPT__;
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
typedef void (*FUNC_void_const_GLfloat___GENPT__)(const GLfloat * v);
typedef struct {
    const GLfloat * a1;
} ARGS_void_const_GLfloat___GENPT__;
typedef struct {
    int format;
    FUNC_void_const_GLfloat___GENPT__ func;
    ARGS_void_const_GLfloat___GENPT__ args;
} PACKED_void_const_GLfloat___GENPT__;
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
typedef void (*FUNC_void_const_GLint___GENPT__)(const GLint * v);
typedef struct {
    const GLint * a1;
} ARGS_void_const_GLint___GENPT__;
typedef struct {
    int format;
    FUNC_void_const_GLint___GENPT__ func;
    ARGS_void_const_GLint___GENPT__ args;
} PACKED_void_const_GLint___GENPT__;
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
typedef void (*FUNC_void_const_GLshort___GENPT__)(const GLshort * v);
typedef struct {
    const GLshort * a1;
} ARGS_void_const_GLshort___GENPT__;
typedef struct {
    int format;
    FUNC_void_const_GLshort___GENPT__ func;
    ARGS_void_const_GLshort___GENPT__ args;
} PACKED_void_const_GLshort___GENPT__;
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
typedef void (*FUNC_void_const_GLubyte___GENPT__)(const GLubyte * v);
typedef struct {
    const GLubyte * a1;
} ARGS_void_const_GLubyte___GENPT__;
typedef struct {
    int format;
    FUNC_void_const_GLubyte___GENPT__ func;
    ARGS_void_const_GLubyte___GENPT__ args;
} PACKED_void_const_GLubyte___GENPT__;
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
typedef void (*FUNC_void_const_GLuint___GENPT__)(const GLuint * v);
typedef struct {
    const GLuint * a1;
} ARGS_void_const_GLuint___GENPT__;
typedef struct {
    int format;
    FUNC_void_const_GLuint___GENPT__ func;
    ARGS_void_const_GLuint___GENPT__ args;
} PACKED_void_const_GLuint___GENPT__;
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
typedef void (*FUNC_void_const_GLushort___GENPT__)(const GLushort * v);
typedef struct {
    const GLushort * a1;
} ARGS_void_const_GLushort___GENPT__;
typedef struct {
    int format;
    FUNC_void_const_GLushort___GENPT__ func;
    ARGS_void_const_GLushort___GENPT__ args;
} PACKED_void_const_GLushort___GENPT__;
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
typedef void (*FUNC_void_GLdouble_GLdouble_GLdouble_GLdouble)(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
typedef struct {
    GLdouble a1;
    GLdouble a2;
    GLdouble a3;
    GLdouble a4;
} ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLdouble_GLdouble_GLdouble_GLdouble func;
    ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble args;
} PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble;
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
typedef void (*FUNC_void_GLboolean)(GLboolean flag);
typedef struct {
    GLboolean a1;
} ARGS_void_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLboolean func;
    ARGS_void_GLboolean args;
} PACKED_void_GLboolean;
typedef void (*FUNC_void_GLdouble_GLdouble)(GLdouble near, GLdouble far);
typedef struct {
    GLdouble a1;
    GLdouble a2;
} ARGS_void_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLdouble_GLdouble func;
    ARGS_void_GLdouble_GLdouble args;
} PACKED_void_GLdouble_GLdouble;
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
typedef void (*FUNC_void_const_GLboolean___GENPT__)(const GLboolean * flag);
typedef struct {
    const GLboolean * a1;
} ARGS_void_const_GLboolean___GENPT__;
typedef struct {
    int format;
    FUNC_void_const_GLboolean___GENPT__ func;
    ARGS_void_const_GLboolean___GENPT__ args;
} PACKED_void_const_GLboolean___GENPT__;
typedef void (*FUNC_void)();
typedef struct {
} ARGS_void;
typedef struct {
    int format;
    FUNC_void func;
    ARGS_void args;
} PACKED_void;
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
typedef void (*FUNC_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef struct {
    GLdouble a1;
    GLdouble a2;
    GLdouble a3;
    GLdouble a4;
    GLdouble a5;
    GLdouble a6;
} ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble func;
    ARGS_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble args;
} PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble;
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
typedef GLuint (*FUNC_GLuint_GLsizei)(GLsizei range);
typedef struct {
    GLsizei a1;
} ARGS_GLuint_GLsizei;
typedef struct {
    int format;
    FUNC_GLuint_GLsizei func;
    ARGS_GLuint_GLsizei args;
} PACKED_GLuint_GLsizei;
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
typedef void (*FUNC_void_GLubyte___GENPT__)(GLubyte * mask);
typedef struct {
    GLubyte * a1;
} ARGS_void_GLubyte___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLubyte___GENPT__ func;
    ARGS_void_GLubyte___GENPT__ args;
} PACKED_void_GLubyte___GENPT__;
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
typedef const GLubyte * (*FUNC_const_GLubyte___GENPT___GLenum)(GLenum name);
typedef struct {
    GLenum a1;
} ARGS_const_GLubyte___GENPT___GLenum;
typedef struct {
    int format;
    FUNC_const_GLubyte___GENPT___GLenum func;
    ARGS_const_GLubyte___GENPT___GLenum args;
} PACKED_const_GLubyte___GENPT___GLenum;
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
typedef void (*FUNC_void_GLshort)(GLshort c);
typedef struct {
    GLshort a1;
} ARGS_void_GLshort;
typedef struct {
    int format;
    FUNC_void_GLshort func;
    ARGS_void_GLshort args;
} PACKED_void_GLshort;
typedef void (*FUNC_void_GLubyte)(GLubyte c);
typedef struct {
    GLubyte a1;
} ARGS_void_GLubyte;
typedef struct {
    int format;
    FUNC_void_GLubyte func;
    ARGS_void_GLubyte args;
} PACKED_void_GLubyte;
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
typedef void (*FUNC_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__)(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble * points);
typedef struct {
    GLenum a1;
    GLdouble a2;
    GLdouble a3;
    GLint a4;
    GLint a5;
    const GLdouble * a6;
} ARGS_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ func;
    ARGS_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ args;
} PACKED_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__;
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
typedef void (*FUNC_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble * points);
typedef struct {
    GLenum a1;
    GLdouble a2;
    GLdouble a3;
    GLint a4;
    GLint a5;
    GLdouble a6;
    GLdouble a7;
    GLint a8;
    GLint a9;
    const GLdouble * a10;
} ARGS_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ func;
    ARGS_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ args;
} PACKED_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__;
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
typedef void (*FUNC_void_GLint_GLdouble_GLdouble)(GLint un, GLdouble u1, GLdouble u2);
typedef struct {
    GLint a1;
    GLdouble a2;
    GLdouble a3;
} ARGS_void_GLint_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLint_GLdouble_GLdouble func;
    ARGS_void_GLint_GLdouble_GLdouble args;
} PACKED_void_GLint_GLdouble_GLdouble;
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
typedef void (*FUNC_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble)(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
typedef struct {
    GLint a1;
    GLdouble a2;
    GLdouble a3;
    GLint a4;
    GLdouble a5;
    GLdouble a6;
} ARGS_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble func;
    ARGS_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble args;
} PACKED_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble;
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
typedef void (*FUNC_void_GLenum_GLdouble)(GLenum target, GLdouble s);
typedef struct {
    GLenum a1;
    GLdouble a2;
} ARGS_void_GLenum_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLenum_GLdouble func;
    ARGS_void_GLenum_GLdouble args;
} PACKED_void_GLenum_GLdouble;
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
typedef void (*FUNC_void_GLenum_GLdouble_GLdouble)(GLenum target, GLdouble s, GLdouble t);
typedef struct {
    GLenum a1;
    GLdouble a2;
    GLdouble a3;
} ARGS_void_GLenum_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLenum_GLdouble_GLdouble func;
    ARGS_void_GLenum_GLdouble_GLdouble args;
} PACKED_void_GLenum_GLdouble_GLdouble;
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
typedef void (*FUNC_void_GLenum_GLdouble_GLdouble_GLdouble)(GLenum target, GLdouble s, GLdouble t, GLdouble r);
typedef struct {
    GLenum a1;
    GLdouble a2;
    GLdouble a3;
    GLdouble a4;
} ARGS_void_GLenum_GLdouble_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLenum_GLdouble_GLdouble_GLdouble func;
    ARGS_void_GLenum_GLdouble_GLdouble_GLdouble args;
} PACKED_void_GLenum_GLdouble_GLdouble_GLdouble;
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
typedef void (*FUNC_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
typedef struct {
    GLenum a1;
    GLdouble a2;
    GLdouble a3;
    GLdouble a4;
    GLdouble a5;
} ARGS_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble func;
    ARGS_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble args;
} PACKED_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble;
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
typedef GLint (*FUNC_GLint_GLenum)(GLenum mode);
typedef struct {
    GLenum a1;
} ARGS_GLint_GLenum;
typedef struct {
    int format;
    FUNC_GLint_GLenum func;
    ARGS_GLint_GLenum args;
} PACKED_GLint_GLenum;
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
typedef void (*FUNC_void_GLenum_GLenum_GLdouble)(GLenum coord, GLenum pname, GLdouble param);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLdouble a3;
} ARGS_void_GLenum_GLenum_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLdouble func;
    ARGS_void_GLenum_GLenum_GLdouble args;
} PACKED_void_GLenum_GLenum_GLdouble;
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
typedef void (*FUNC_void_uint32_t)(uint32_t drawable);
typedef struct {
    uint32_t a1;
} ARGS_void_uint32_t;
typedef struct {
    int format;
    FUNC_void_uint32_t func;
    ARGS_void_uint32_t args;
} PACKED_void_uint32_t;
typedef void (*FUNC_void_uint32_t_uint32_t_uint32_t)(uint32_t source, uint32_t dest, uint32_t mask);
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
typedef void (*FUNC_void_uint32_t_uint32_t_uint32_t_uint32_t)(uint32_t gc_id, uint32_t screen, uint32_t visual, uint32_t share_list);
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
typedef void (*FUNC_void_uint32_t_uint32_t_uint32_t_uint32_t_uint32_t_uint32_t)(uint32_t dpy, uint32_t screen, uint32_t server, uint32_t path, uint32_t class, uint32_t node);
typedef struct {
    uint32_t a1;
    uint32_t a2;
    uint32_t a3;
    uint32_t a4;
    uint32_t a5;
    uint32_t a6;
} ARGS_void_uint32_t_uint32_t_uint32_t_uint32_t_uint32_t_uint32_t;
typedef struct {
    int format;
    FUNC_void_uint32_t_uint32_t_uint32_t_uint32_t_uint32_t_uint32_t func;
    ARGS_void_uint32_t_uint32_t_uint32_t_uint32_t_uint32_t_uint32_t args;
} PACKED_void_uint32_t_uint32_t_uint32_t_uint32_t_uint32_t_uint32_t;
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
typedef void (*FUNC_void_uint32_t___GENPT___uint32_t___GENPT__)(uint32_t * major, uint32_t * minor);
typedef struct {
    uint32_t * a1;
    uint32_t * a2;
} ARGS_void_uint32_t___GENPT___uint32_t___GENPT__;
typedef struct {
    int format;
    FUNC_void_uint32_t___GENPT___uint32_t___GENPT__ func;
    ARGS_void_uint32_t___GENPT___uint32_t___GENPT__ args;
} PACKED_void_uint32_t___GENPT___uint32_t___GENPT__;
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
typedef Display * (*FUNC_Display___GENPT__)();
typedef struct {
} ARGS_Display___GENPT__;
typedef struct {
    int format;
    FUNC_Display___GENPT__ func;
    ARGS_Display___GENPT__ args;
} PACKED_Display___GENPT__;
typedef GLXDrawable (*FUNC_GLXDrawable)();
typedef struct {
} ARGS_GLXDrawable;
typedef struct {
    int format;
    FUNC_GLXDrawable func;
    ARGS_GLXDrawable args;
} PACKED_GLXDrawable;
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
typedef __GLXextFuncPtr (*FUNC___GLXextFuncPtr_const_GLubyte___GENPT__)(const GLubyte * procName);
typedef struct {
    const GLubyte * a1;
} ARGS___GLXextFuncPtr_const_GLubyte___GENPT__;
typedef struct {
    int format;
    FUNC___GLXextFuncPtr_const_GLubyte___GENPT__ func;
    ARGS___GLXextFuncPtr_const_GLubyte___GENPT__ args;
} PACKED___GLXextFuncPtr_const_GLubyte___GENPT__;
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

void glPackedCall(const UnknownCall *packed);
void glAccum(GLenum op, GLfloat value);
void glActiveTexture(GLenum texture);
void glAlphaFunc(GLenum func, GLfloat ref);
GLboolean glAreTexturesResident(GLsizei n, const GLuint * textures, GLboolean * residences);
void glArrayElement(GLint i);
void glBegin(GLenum mode);
void glBeginQuery(GLenum target, GLuint id);
void glBindBuffer(GLenum target, GLuint buffer);
void glBindTexture(GLenum target, GLuint texture);
void glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte * bitmap);
void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glBlendEquation(GLenum mode);
void glBlendFunc(GLenum sfactor, GLenum dfactor);
void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
void glBufferData(GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage);
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data);
void glCallList(GLuint list);
void glCallLists(GLsizei n, GLenum type, const GLvoid * lists);
void glClear(GLbitfield mask);
void glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glClearDepth(GLdouble depth);
void glClearIndex(GLfloat c);
void glClearStencil(GLint s);
void glClientActiveTexture(GLenum texture);
void glClipPlane(GLenum plane, const GLdouble * equation);
void glColor3b(GLbyte red, GLbyte green, GLbyte blue);
void glColor3bv(const GLbyte * v);
void glColor3d(GLdouble red, GLdouble green, GLdouble blue);
void glColor3dv(const GLdouble * v);
void glColor3f(GLfloat red, GLfloat green, GLfloat blue);
void glColor3fv(const GLfloat * v);
void glColor3i(GLint red, GLint green, GLint blue);
void glColor3iv(const GLint * v);
void glColor3s(GLshort red, GLshort green, GLshort blue);
void glColor3sv(const GLshort * v);
void glColor3ub(GLubyte red, GLubyte green, GLubyte blue);
void glColor3ubv(const GLubyte * v);
void glColor3ui(GLuint red, GLuint green, GLuint blue);
void glColor3uiv(const GLuint * v);
void glColor3us(GLushort red, GLushort green, GLushort blue);
void glColor3usv(const GLushort * v);
void glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
void glColor4bv(const GLbyte * v);
void glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
void glColor4dv(const GLdouble * v);
void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glColor4fv(const GLfloat * v);
void glColor4i(GLint red, GLint green, GLint blue, GLint alpha);
void glColor4iv(const GLint * v);
void glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha);
void glColor4sv(const GLshort * v);
void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
void glColor4ubv(const GLubyte * v);
void glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha);
void glColor4uiv(const GLuint * v);
void glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha);
void glColor4usv(const GLushort * v);
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
void glColorMaterial(GLenum face, GLenum mode);
void glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
void glColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid * data);
void glColorTable(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * table);
void glColorTableParameterfv(GLenum target, GLenum pname, const GLfloat * params);
void glColorTableParameteriv(GLenum target, GLenum pname, const GLint * params);
void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid * data);
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data);
void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid * data);
void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid * data);
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data);
void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid * data);
void glConvolutionFilter1D(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * image);
void glConvolutionFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * image);
void glConvolutionParameterf(GLenum target, GLenum pname, GLfloat params);
void glConvolutionParameterfv(GLenum target, GLenum pname, const GLfloat * params);
void glConvolutionParameteri(GLenum target, GLenum pname, GLint params);
void glConvolutionParameteriv(GLenum target, GLenum pname, const GLint * params);
void glCopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
void glCopyColorTable(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
void glCopyConvolutionFilter1D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
void glCopyConvolutionFilter2D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
void glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glCullFace(GLenum mode);
void glDeleteBuffers(GLsizei n, const GLuint * buffers);
void glDeleteLists(GLuint list, GLsizei range);
void glDeleteQueries(GLsizei n, const GLuint * ids);
void glDeleteTextures(GLsizei n, const GLuint * textures);
void glDepthFunc(GLenum func);
void glDepthMask(GLboolean flag);
void glDepthRange(GLdouble near, GLdouble far);
void glDisable(GLenum cap);
void glDisableClientState(GLenum array);
void glDrawArrays(GLenum mode, GLint first, GLsizei count);
void glDrawBuffer(GLenum mode);
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid * indices);
void glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels);
void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid * indices);
void glEdgeFlag(GLboolean flag);
void glEdgeFlagPointer(GLsizei stride, const GLvoid * pointer);
void glEdgeFlagv(const GLboolean * flag);
void glEnable(GLenum cap);
void glEnableClientState(GLenum array);
void glEnd();
void glEndList();
void glEndQuery(GLenum target);
void glEvalCoord1d(GLdouble u);
void glEvalCoord1dv(const GLdouble * u);
void glEvalCoord1f(GLfloat u);
void glEvalCoord1fv(const GLfloat * u);
void glEvalCoord2d(GLdouble u, GLdouble v);
void glEvalCoord2dv(const GLdouble * u);
void glEvalCoord2f(GLfloat u, GLfloat v);
void glEvalCoord2fv(const GLfloat * u);
void glEvalMesh1(GLenum mode, GLint i1, GLint i2);
void glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
void glEvalPoint1(GLint i);
void glEvalPoint2(GLint i, GLint j);
void glFeedbackBuffer(GLsizei size, GLenum type, GLfloat * buffer);
void glFinish();
void glFlush();
void glFogCoordPointer(GLenum type, GLsizei stride, const GLvoid * pointer);
void glFogCoordd(GLdouble coord);
void glFogCoorddv(const GLdouble * coord);
void glFogCoordf(GLfloat coord);
void glFogCoordfv(const GLfloat * coord);
void glFogf(GLenum pname, GLfloat param);
void glFogfv(GLenum pname, const GLfloat * params);
void glFogi(GLenum pname, GLint param);
void glFogiv(GLenum pname, const GLint * params);
void glFrontFace(GLenum mode);
void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
void glGenBuffers(GLsizei n, GLuint * buffers);
GLuint glGenLists(GLsizei range);
void glGenQueries(GLsizei n, GLuint * ids);
void glGenTextures(GLsizei n, GLuint * textures);
void glGetBooleanv(GLenum pname, GLboolean * params);
void glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params);
void glGetBufferPointerv(GLenum target, GLenum pname, GLvoid * params);
void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data);
void glGetClipPlane(GLenum plane, GLdouble * equation);
void glGetColorTable(GLenum target, GLenum format, GLenum type, GLvoid * table);
void glGetColorTableParameterfv(GLenum target, GLenum pname, GLfloat * params);
void glGetColorTableParameteriv(GLenum target, GLenum pname, GLint * params);
void glGetCompressedTexImage(GLenum target, GLint level, GLvoid * img);
void glGetConvolutionFilter(GLenum target, GLenum format, GLenum type, GLvoid * image);
void glGetConvolutionParameterfv(GLenum target, GLenum pname, GLfloat * params);
void glGetConvolutionParameteriv(GLenum target, GLenum pname, GLint * params);
void glGetDoublev(GLenum pname, GLdouble * params);
GLenum glGetError();
void glGetFloatv(GLenum pname, GLfloat * params);
void glGetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values);
void glGetHistogramParameterfv(GLenum target, GLenum pname, GLfloat * params);
void glGetHistogramParameteriv(GLenum target, GLenum pname, GLint * params);
void glGetIntegerv(GLenum pname, GLint * params);
void glGetLightfv(GLenum light, GLenum pname, GLfloat * params);
void glGetLightiv(GLenum light, GLenum pname, GLint * params);
void glGetMapdv(GLenum target, GLenum query, GLdouble * v);
void glGetMapfv(GLenum target, GLenum query, GLfloat * v);
void glGetMapiv(GLenum target, GLenum query, GLint * v);
void glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params);
void glGetMaterialiv(GLenum face, GLenum pname, GLint * params);
void glGetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values);
void glGetMinmaxParameterfv(GLenum target, GLenum pname, GLfloat * params);
void glGetMinmaxParameteriv(GLenum target, GLenum pname, GLint * params);
void glGetPixelMapfv(GLenum map, GLfloat * values);
void glGetPixelMapuiv(GLenum map, GLuint * values);
void glGetPixelMapusv(GLenum map, GLushort * values);
void glGetPointerv(GLenum pname, GLvoid ** params);
void glGetPolygonStipple(GLubyte * mask);
void glGetQueryObjectiv(GLuint id, GLenum pname, GLint * params);
void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint * params);
void glGetQueryiv(GLenum target, GLenum pname, GLint * params);
void glGetSeparableFilter(GLenum target, GLenum format, GLenum type, GLvoid * row, GLvoid * column, GLvoid * span);
const GLubyte * glGetString(GLenum name);
void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params);
void glGetTexEnviv(GLenum target, GLenum pname, GLint * params);
void glGetTexGendv(GLenum coord, GLenum pname, GLdouble * params);
void glGetTexGenfv(GLenum coord, GLenum pname, GLfloat * params);
void glGetTexGeniv(GLenum coord, GLenum pname, GLint * params);
void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid * pixels);
void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat * params);
void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint * params);
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params);
void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params);
void glHint(GLenum target, GLenum mode);
void glHistogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
void glIndexMask(GLuint mask);
void glIndexPointer(GLenum type, GLsizei stride, const GLvoid * pointer);
void glIndexd(GLdouble c);
void glIndexdv(const GLdouble * c);
void glIndexf(GLfloat c);
void glIndexfv(const GLfloat * c);
void glIndexi(GLint c);
void glIndexiv(const GLint * c);
void glIndexs(GLshort c);
void glIndexsv(const GLshort * c);
void glIndexub(GLubyte c);
void glIndexubv(const GLubyte * c);
void glInitNames();
void glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid * pointer);
GLboolean glIsBuffer(GLuint buffer);
GLboolean glIsEnabled(GLenum cap);
GLboolean glIsList(GLuint list);
GLboolean glIsQuery(GLuint id);
GLboolean glIsTexture(GLuint texture);
void glLightModelf(GLenum pname, GLfloat param);
void glLightModelfv(GLenum pname, const GLfloat * params);
void glLightModeli(GLenum pname, GLint param);
void glLightModeliv(GLenum pname, const GLint * params);
void glLightf(GLenum light, GLenum pname, GLfloat param);
void glLightfv(GLenum light, GLenum pname, const GLfloat * params);
void glLighti(GLenum light, GLenum pname, GLint param);
void glLightiv(GLenum light, GLenum pname, const GLint * params);
void glLineStipple(GLint factor, GLushort pattern);
void glLineWidth(GLfloat width);
void glListBase(GLuint base);
void glLoadIdentity();
void glLoadMatrixd(const GLdouble * m);
void glLoadMatrixf(const GLfloat * m);
void glLoadName(GLuint name);
void glLoadTransposeMatrixd(const GLdouble * m);
void glLoadTransposeMatrixf(const GLfloat * m);
void glLogicOp(GLenum opcode);
void glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble * points);
void glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat * points);
void glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble * points);
void glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat * points);
GLvoid * glMapBuffer(GLenum target, GLenum access);
void glMapGrid1d(GLint un, GLdouble u1, GLdouble u2);
void glMapGrid1f(GLint un, GLfloat u1, GLfloat u2);
void glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
void glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
void glMaterialf(GLenum face, GLenum pname, GLfloat param);
void glMaterialfv(GLenum face, GLenum pname, const GLfloat * params);
void glMateriali(GLenum face, GLenum pname, GLint param);
void glMaterialiv(GLenum face, GLenum pname, const GLint * params);
void glMatrixMode(GLenum mode);
void glMinmax(GLenum target, GLenum internalformat, GLboolean sink);
void glMultMatrixd(const GLdouble * m);
void glMultMatrixf(const GLfloat * m);
void glMultTransposeMatrixd(const GLdouble * m);
void glMultTransposeMatrixf(const GLfloat * m);
void glMultiDrawArrays(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount);
void glMultiDrawElements(GLenum mode, const GLsizei * count, GLenum type, GLvoid*const * indices, GLsizei drawcount);
void glMultiTexCoord1d(GLenum target, GLdouble s);
void glMultiTexCoord1dv(GLenum target, const GLdouble * v);
void glMultiTexCoord1f(GLenum target, GLfloat s);
void glMultiTexCoord1fv(GLenum target, const GLfloat * v);
void glMultiTexCoord1i(GLenum target, GLint s);
void glMultiTexCoord1iv(GLenum target, const GLint * v);
void glMultiTexCoord1s(GLenum target, GLshort s);
void glMultiTexCoord1sv(GLenum target, const GLshort * v);
void glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t);
void glMultiTexCoord2dv(GLenum target, const GLdouble * v);
void glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t);
void glMultiTexCoord2fv(GLenum target, const GLfloat * v);
void glMultiTexCoord2i(GLenum target, GLint s, GLint t);
void glMultiTexCoord2iv(GLenum target, const GLint * v);
void glMultiTexCoord2s(GLenum target, GLshort s, GLshort t);
void glMultiTexCoord2sv(GLenum target, const GLshort * v);
void glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r);
void glMultiTexCoord3dv(GLenum target, const GLdouble * v);
void glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r);
void glMultiTexCoord3fv(GLenum target, const GLfloat * v);
void glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r);
void glMultiTexCoord3iv(GLenum target, const GLint * v);
void glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r);
void glMultiTexCoord3sv(GLenum target, const GLshort * v);
void glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
void glMultiTexCoord4dv(GLenum target, const GLdouble * v);
void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void glMultiTexCoord4fv(GLenum target, const GLfloat * v);
void glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q);
void glMultiTexCoord4iv(GLenum target, const GLint * v);
void glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
void glMultiTexCoord4sv(GLenum target, const GLshort * v);
void glNewList(GLuint list, GLenum mode);
void glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz);
void glNormal3bv(const GLbyte * v);
void glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz);
void glNormal3dv(const GLdouble * v);
void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz);
void glNormal3fv(const GLfloat * v);
void glNormal3i(GLint nx, GLint ny, GLint nz);
void glNormal3iv(const GLint * v);
void glNormal3s(GLshort nx, GLshort ny, GLshort nz);
void glNormal3sv(const GLshort * v);
void glNormalPointer(GLenum type, GLsizei stride, const GLvoid * pointer);
void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
void glPassThrough(GLfloat token);
void glPixelMapfv(GLenum map, GLsizei mapsize, const GLfloat * values);
void glPixelMapuiv(GLenum map, GLsizei mapsize, const GLuint * values);
void glPixelMapusv(GLenum map, GLsizei mapsize, const GLushort * values);
void glPixelStoref(GLenum pname, GLfloat param);
void glPixelStorei(GLenum pname, GLint param);
void glPixelTransferf(GLenum pname, GLfloat param);
void glPixelTransferi(GLenum pname, GLint param);
void glPixelZoom(GLfloat xfactor, GLfloat yfactor);
void glPointParameterf(GLenum pname, GLfloat param);
void glPointParameterfv(GLenum pname, const GLfloat * params);
void glPointParameteri(GLenum pname, GLint param);
void glPointParameteriv(GLenum pname, const GLint * params);
void glPointSize(GLfloat size);
void glPolygonMode(GLenum face, GLenum mode);
void glPolygonOffset(GLfloat factor, GLfloat units);
void glPolygonStipple(const GLubyte * mask);
void glPopAttrib();
void glPopClientAttrib();
void glPopMatrix();
void glPopName();
void glPrioritizeTextures(GLsizei n, const GLuint * textures, const GLfloat * priorities);
void glPushAttrib(GLbitfield mask);
void glPushClientAttrib(GLbitfield mask);
void glPushMatrix();
void glPushName(GLuint name);
void glRasterPos2d(GLdouble x, GLdouble y);
void glRasterPos2dv(const GLdouble * v);
void glRasterPos2f(GLfloat x, GLfloat y);
void glRasterPos2fv(const GLfloat * v);
void glRasterPos2i(GLint x, GLint y);
void glRasterPos2iv(const GLint * v);
void glRasterPos2s(GLshort x, GLshort y);
void glRasterPos2sv(const GLshort * v);
void glRasterPos3d(GLdouble x, GLdouble y, GLdouble z);
void glRasterPos3dv(const GLdouble * v);
void glRasterPos3f(GLfloat x, GLfloat y, GLfloat z);
void glRasterPos3fv(const GLfloat * v);
void glRasterPos3i(GLint x, GLint y, GLint z);
void glRasterPos3iv(const GLint * v);
void glRasterPos3s(GLshort x, GLshort y, GLshort z);
void glRasterPos3sv(const GLshort * v);
void glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glRasterPos4dv(const GLdouble * v);
void glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glRasterPos4fv(const GLfloat * v);
void glRasterPos4i(GLint x, GLint y, GLint z, GLint w);
void glRasterPos4iv(const GLint * v);
void glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w);
void glRasterPos4sv(const GLshort * v);
void glReadBuffer(GLenum mode);
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels);
void glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
void glRectdv(const GLdouble * v1, const GLdouble * v2);
void glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
void glRectfv(const GLfloat * v1, const GLfloat * v2);
void glRecti(GLint x1, GLint y1, GLint x2, GLint y2);
void glRectiv(const GLint * v1, const GLint * v2);
void glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
void glRectsv(const GLshort * v1, const GLshort * v2);
GLint glRenderMode(GLenum mode);
void glResetHistogram(GLenum target);
void glResetMinmax(GLenum target);
void glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
void glSampleCoverage(GLfloat value, GLboolean invert);
void glScaled(GLdouble x, GLdouble y, GLdouble z);
void glScalef(GLfloat x, GLfloat y, GLfloat z);
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
void glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue);
void glSecondaryColor3bv(const GLbyte * v);
void glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue);
void glSecondaryColor3dv(const GLdouble * v);
void glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue);
void glSecondaryColor3fv(const GLfloat * v);
void glSecondaryColor3i(GLint red, GLint green, GLint blue);
void glSecondaryColor3iv(const GLint * v);
void glSecondaryColor3s(GLshort red, GLshort green, GLshort blue);
void glSecondaryColor3sv(const GLshort * v);
void glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue);
void glSecondaryColor3ubv(const GLubyte * v);
void glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue);
void glSecondaryColor3uiv(const GLuint * v);
void glSecondaryColor3us(GLushort red, GLushort green, GLushort blue);
void glSecondaryColor3usv(const GLushort * v);
void glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
void glSelectBuffer(GLsizei size, GLuint * buffer);
void glSeparableFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * row, const GLvoid * column);
void glShadeModel(GLenum mode);
void glStencilFunc(GLenum func, GLint ref, GLuint mask);
void glStencilMask(GLuint mask);
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass);
void glTexCoord1d(GLdouble s);
void glTexCoord1dv(const GLdouble * v);
void glTexCoord1f(GLfloat s);
void glTexCoord1fv(const GLfloat * v);
void glTexCoord1i(GLint s);
void glTexCoord1iv(const GLint * v);
void glTexCoord1s(GLshort s);
void glTexCoord1sv(const GLshort * v);
void glTexCoord2d(GLdouble s, GLdouble t);
void glTexCoord2dv(const GLdouble * v);
void glTexCoord2f(GLfloat s, GLfloat t);
void glTexCoord2fv(const GLfloat * v);
void glTexCoord2i(GLint s, GLint t);
void glTexCoord2iv(const GLint * v);
void glTexCoord2s(GLshort s, GLshort t);
void glTexCoord2sv(const GLshort * v);
void glTexCoord3d(GLdouble s, GLdouble t, GLdouble r);
void glTexCoord3dv(const GLdouble * v);
void glTexCoord3f(GLfloat s, GLfloat t, GLfloat r);
void glTexCoord3fv(const GLfloat * v);
void glTexCoord3i(GLint s, GLint t, GLint r);
void glTexCoord3iv(const GLint * v);
void glTexCoord3s(GLshort s, GLshort t, GLshort r);
void glTexCoord3sv(const GLshort * v);
void glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
void glTexCoord4dv(const GLdouble * v);
void glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void glTexCoord4fv(const GLfloat * v);
void glTexCoord4i(GLint s, GLint t, GLint r, GLint q);
void glTexCoord4iv(const GLint * v);
void glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q);
void glTexCoord4sv(const GLshort * v);
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
void glTexEnvf(GLenum target, GLenum pname, GLfloat param);
void glTexEnvfv(GLenum target, GLenum pname, const GLfloat * params);
void glTexEnvi(GLenum target, GLenum pname, GLint param);
void glTexEnviv(GLenum target, GLenum pname, const GLint * params);
void glTexGend(GLenum coord, GLenum pname, GLdouble param);
void glTexGendv(GLenum coord, GLenum pname, const GLdouble * params);
void glTexGenf(GLenum coord, GLenum pname, GLfloat param);
void glTexGenfv(GLenum coord, GLenum pname, const GLfloat * params);
void glTexGeni(GLenum coord, GLenum pname, GLint param);
void glTexGeniv(GLenum coord, GLenum pname, const GLint * params);
void glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid * pixels);
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels);
void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid * pixels);
void glTexParameterf(GLenum target, GLenum pname, GLfloat param);
void glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params);
void glTexParameteri(GLenum target, GLenum pname, GLint param);
void glTexParameteriv(GLenum target, GLenum pname, const GLint * params);
void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid * pixels);
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels);
void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * pixels);
void glTranslated(GLdouble x, GLdouble y, GLdouble z);
void glTranslatef(GLfloat x, GLfloat y, GLfloat z);
GLboolean glUnmapBuffer(GLenum target);
void glVertex2d(GLdouble x, GLdouble y);
void glVertex2dv(const GLdouble * v);
void glVertex2f(GLfloat x, GLfloat y);
void glVertex2fv(const GLfloat * v);
void glVertex2i(GLint x, GLint y);
void glVertex2iv(const GLint * v);
void glVertex2s(GLshort x, GLshort y);
void glVertex2sv(const GLshort * v);
void glVertex3d(GLdouble x, GLdouble y, GLdouble z);
void glVertex3dv(const GLdouble * v);
void glVertex3f(GLfloat x, GLfloat y, GLfloat z);
void glVertex3fv(const GLfloat * v);
void glVertex3i(GLint x, GLint y, GLint z);
void glVertex3iv(const GLint * v);
void glVertex3s(GLshort x, GLshort y, GLshort z);
void glVertex3sv(const GLshort * v);
void glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glVertex4dv(const GLdouble * v);
void glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glVertex4fv(const GLfloat * v);
void glVertex4i(GLint x, GLint y, GLint z, GLint w);
void glVertex4iv(const GLint * v);
void glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w);
void glVertex4sv(const GLshort * v);
void glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer);
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height);
void glWindowPos2d(GLdouble x, GLdouble y);
void glWindowPos2dv(const GLdouble * v);
void glWindowPos2f(GLfloat x, GLfloat y);
void glWindowPos2fv(const GLfloat * v);
void glWindowPos2i(GLint x, GLint y);
void glWindowPos2iv(const GLint * v);
void glWindowPos2s(GLshort x, GLshort y);
void glWindowPos2sv(const GLshort * v);
void glWindowPos3d(GLdouble x, GLdouble y, GLdouble z);
void glWindowPos3dv(const GLdouble * v);
void glWindowPos3f(GLfloat x, GLfloat y, GLfloat z);
void glWindowPos3fv(const GLfloat * v);
void glWindowPos3i(GLint x, GLint y, GLint z);
void glWindowPos3iv(const GLint * v);
void glWindowPos3s(GLshort x, GLshort y, GLshort z);
void glWindowPos3sv(const GLshort * v);
int glXBindHyperpipeSGIX(Display * dpy, int hpId);
void glXBindSwapBarrierSGIX(uint32_t window, uint32_t barrier);
void glXChangeDrawableAttributes(uint32_t drawable);
void glXChangeDrawableAttributesSGIX(uint32_t drawable);
GLXFBConfig * glXChooseFBConfig(Display * dpy, int screen, const int * attrib_list, int * nelements);
void glXClientInfo();
void glXCopyContext(uint32_t source, uint32_t dest, uint32_t mask);
void glXCreateContext(uint32_t gc_id, uint32_t screen, uint32_t visual, uint32_t share_list);
void glXCreateContextWithConfigSGIX(uint32_t gc_id, uint32_t screen, uint32_t config, uint32_t share_list);
void glXCreateGLXPbufferSGIX(uint32_t config, uint32_t pbuffer);
void glXCreateGLXPixmap(uint32_t visual, uint32_t pixmap, uint32_t glxpixmap);
void glXCreateGLXPixmapWithConfigSGIX(uint32_t config, uint32_t pixmap, uint32_t glxpixmap);
void glXCreateGLXVideoSourceSGIX(uint32_t dpy, uint32_t screen, uint32_t server, uint32_t path, uint32_t class, uint32_t node);
GLXContext glXCreateNewContext(Display * dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct);
GLXPbuffer glXCreatePbuffer(Display * dpy, GLXFBConfig config, const int * attrib_list);
GLXPixmap glXCreatePixmap(Display * dpy, GLXFBConfig config, Pixmap pixmap, const int * attrib_list);
GLXWindow glXCreateWindow(Display * dpy, GLXFBConfig config, Window win, const int * attrib_list);
void glXDestroyContext(uint32_t context);
void glXDestroyGLXPbufferSGIX(uint32_t pbuffer);
void glXDestroyGLXPixmap(uint32_t pixmap);
void glXDestroyGLXVideoSourceSGIX(uint32_t dpy, uint32_t glxvideosource);
int glXDestroyHyperpipeConfigSGIX(Display * dpy, int hpId);
void glXDestroyPbuffer(Display * dpy, GLXPbuffer pbuf);
void glXDestroyPixmap(Display * dpy, GLXPixmap pixmap);
void glXDestroyWindow(Display * dpy, GLXWindow win);
Display * glXGetCurrentDisplay();
GLXDrawable glXGetCurrentReadDrawable();
void glXGetDrawableAttributes(uint32_t drawable);
void glXGetDrawableAttributesSGIX(uint32_t drawable);
int glXGetFBConfigAttrib(Display * dpy, GLXFBConfig config, int attribute, int * value);
GLXFBConfig * glXGetFBConfigs(Display * dpy, int screen, int * nelements);
void glXGetFBConfigsSGIX();
__GLXextFuncPtr glXGetProcAddress(const GLubyte * procName);
void glXGetSelectedEvent(Display * dpy, GLXDrawable draw, unsigned long * event_mask);
void glXGetVisualConfigs();
XVisualInfo * glXGetVisualFromFBConfig(Display * dpy, GLXFBConfig config);
int glXHyperpipeAttribSGIX(Display * dpy, int timeSlice, int attrib, int size, const void * attribList);
int glXHyperpipeConfigSGIX(Display * dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX cfg, int * hpId);
void glXIsDirect(uint32_t dpy, uint32_t context);
void glXJoinSwapGroupSGIX(uint32_t window, uint32_t group);
Bool glXMakeContextCurrent(Display * dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
void glXMakeCurrent(uint32_t drawable, uint32_t context);
void glXMakeCurrentReadSGI(uint32_t drawable, uint32_t readdrawable, uint32_t context);
int glXQueryContext(Display * dpy, GLXContext ctx, int attribute, int * value);
void glXQueryContextInfoEXT();
void glXQueryDrawable(Display * dpy, GLXDrawable draw, int attribute, unsigned int * value);
void glXQueryExtensionsString(uint32_t screen);
int glXQueryHyperpipeAttribSGIX(Display * dpy, int timeSlice, int attrib, int size, const void * returnAttribList);
int glXQueryHyperpipeBestAttribSGIX(Display * dpy, int timeSlice, int attrib, int size, const void * attribList, void * returnAttribList);
GLXHyperpipeConfigSGIX * glXQueryHyperpipeConfigSGIX(Display * dpy, int hpId, int * npipes);
GLXHyperpipeNetworkSGIX * glXQueryHyperpipeNetworkSGIX(Display * dpy, int * npipes);
void glXQueryMaxSwapBarriersSGIX();
void glXQueryServerString(uint32_t screen, uint32_t name);
void glXQueryVersion(uint32_t * major, uint32_t * minor);
void glXRender();
void glXRenderLarge();
void glXSelectEvent(Display * dpy, GLXDrawable draw, unsigned long event_mask);
void glXSwapBuffers(uint32_t drawable);
void glXSwapIntervalSGI();
void glXUseXFont(uint32_t font, uint32_t first, uint32_t count, uint32_t list_base);
void glXVendorPrivate();
void glXVendorPrivateWithReply();
void glXWaitGL(uint32_t context);
void glXWaitX();

#endif
