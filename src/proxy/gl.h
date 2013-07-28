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
    FORMAT_int_Display___GENPT___int_int_int_const_void___GENPT__,
    FORMAT_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__,
    FORMAT_Bool_Display___GENPT___GLXContext,
    FORMAT_Bool_Display___GENPT___GLXDrawable_GLXContext,
    FORMAT_const_char___GENPT___Display___GENPT___int,
    FORMAT_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__,
    FORMAT_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__,
    FORMAT_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__,
    FORMAT_const_char___GENPT___Display___GENPT___int_int,
    FORMAT_Bool_Display___GENPT___int___GENPT___int___GENPT__,
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
typedef const char * (*FUNC_const_char___GENPT___Display___GENPT___int)(Display * dpy, int screen);
typedef struct {
    Display * a1;
    int a2;
} ARGS_const_char___GENPT___Display___GENPT___int;
typedef struct {
    int format;
    FUNC_const_char___GENPT___Display___GENPT___int func;
    ARGS_const_char___GENPT___Display___GENPT___int args;
} PACKED_const_char___GENPT___Display___GENPT___int;
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
typedef Bool (*FUNC_Bool_Display___GENPT___int___GENPT___int___GENPT__)(Display * dpy, int * maj, int * min);
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

extern void glPushCall(void *data);
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
XVisualInfo * glXChooseVisual(Display * dpy, int screen, int * attribList);
void glXClientInfo();
void glXCopyContext(Display * dpy, GLXContext src, GLXContext dst, unsigned long mask);
GLXContext glXCreateContext(Display * dpy, XVisualInfo * vis, GLXContext shareList, Bool direct);
void glXCreateContextWithConfigSGIX(uint32_t gc_id, uint32_t screen, uint32_t config, uint32_t share_list);
void glXCreateGLXPbufferSGIX(uint32_t config, uint32_t pbuffer);
GLXPixmap glXCreateGLXPixmap(Display * dpy, XVisualInfo * visual, Pixmap pixmap);
void glXCreateGLXPixmapWithConfigSGIX(uint32_t config, uint32_t pixmap, uint32_t glxpixmap);
void glXCreateGLXVideoSourceSGIX(Display * dpy, uint32_t screen, uint32_t server, uint32_t path, uint32_t class, uint32_t node);
GLXContext glXCreateNewContext(Display * dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct);
GLXPbuffer glXCreatePbuffer(Display * dpy, GLXFBConfig config, const int * attrib_list);
GLXPixmap glXCreatePixmap(Display * dpy, GLXFBConfig config, Pixmap pixmap, const int * attrib_list);
GLXWindow glXCreateWindow(Display * dpy, GLXFBConfig config, Window win, const int * attrib_list);
void glXDestroyContext(Display * dpy, GLXContext ctx);
void glXDestroyGLXPbufferSGIX(uint32_t pbuffer);
void glXDestroyGLXPixmap(Display * dpy, GLXPixmap pixmap);
void glXDestroyGLXVideoSourceSGIX(Display * dpy, uint32_t glxvideosource);
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
Bool glXIsDirect(Display * dpy, GLXContext ctx);
void glXJoinSwapGroupSGIX(uint32_t window, uint32_t group);
Bool glXMakeContextCurrent(Display * dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
Bool glXMakeCurrent(Display * dpy, GLXDrawable drawable, GLXContext ctx);
void glXMakeCurrentReadSGI(uint32_t drawable, uint32_t readdrawable, uint32_t context);
int glXQueryContext(Display * dpy, GLXContext ctx, int attribute, int * value);
void glXQueryContextInfoEXT();
void glXQueryDrawable(Display * dpy, GLXDrawable draw, int attribute, unsigned int * value);
const char * glXQueryExtensionsString(Display * dpy, int screen);
int glXQueryHyperpipeAttribSGIX(Display * dpy, int timeSlice, int attrib, int size, const void * returnAttribList);
int glXQueryHyperpipeBestAttribSGIX(Display * dpy, int timeSlice, int attrib, int size, const void * attribList, void * returnAttribList);
GLXHyperpipeConfigSGIX * glXQueryHyperpipeConfigSGIX(Display * dpy, int hpId, int * npipes);
GLXHyperpipeNetworkSGIX * glXQueryHyperpipeNetworkSGIX(Display * dpy, int * npipes);
void glXQueryMaxSwapBarriersSGIX();
const char * glXQueryServerString(Display * dpy, int screen, int name);
Bool glXQueryVersion(Display * dpy, int * maj, int * min);
void glXRender();
void glXRenderLarge();
void glXSelectEvent(Display * dpy, GLXDrawable draw, unsigned long event_mask);
void glXSwapBuffers(Display * dpy, GLXDrawable drawable);
void glXSwapIntervalSGI();
void glXUseXFont(Font font, int first, int count, int list);
void glXVendorPrivate();
void glXVendorPrivateWithReply();
void glXWaitGL();
void glXWaitX();

#ifndef direct_glAccum
static inline void push_glAccum(GLenum op, GLfloat value) {
    PACKED_void_GLenum_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLenum_GLfloat));
    packed_data->format = FORMAT_void_GLenum_GLfloat;
    packed_data->func = glAccum;
    packed_data->args.a1 = op;
    packed_data->args.a2 = value;
    glPushCall((void *)packed_data);
};
#endif
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
static inline void push_glAlphaFunc(GLenum func, GLfloat ref) {
    PACKED_void_GLenum_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLenum_GLfloat));
    packed_data->format = FORMAT_void_GLenum_GLfloat;
    packed_data->func = glAlphaFunc;
    packed_data->args.a1 = func;
    packed_data->args.a2 = ref;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glAreTexturesResident
static inline void push_glAreTexturesResident(GLsizei n, const GLuint * textures, GLboolean * residences) {
    PACKED_GLboolean_GLsizei_const_GLuint___GENPT___GLboolean___GENPT__ *packed_data = malloc(sizeof(PACKED_GLboolean_GLsizei_const_GLuint___GENPT___GLboolean___GENPT__));
    packed_data->format = FORMAT_GLboolean_GLsizei_const_GLuint___GENPT___GLboolean___GENPT__;
    packed_data->func = glAreTexturesResident;
    packed_data->args.a1 = n;
    packed_data->args.a2 = textures;
    packed_data->args.a3 = residences;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glArrayElement
static inline void push_glArrayElement(GLint i) {
    PACKED_void_GLint *packed_data = malloc(sizeof(PACKED_void_GLint));
    packed_data->format = FORMAT_void_GLint;
    packed_data->func = glArrayElement;
    packed_data->args.a1 = i;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glBegin
static inline void push_glBegin(GLenum mode) {
    PACKED_void_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum));
    packed_data->format = FORMAT_void_GLenum;
    packed_data->func = glBegin;
    packed_data->args.a1 = mode;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glBeginQuery
static inline void push_glBeginQuery(GLenum target, GLuint id) {
    PACKED_void_GLenum_GLuint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLuint));
    packed_data->format = FORMAT_void_GLenum_GLuint;
    packed_data->func = glBeginQuery;
    packed_data->args.a1 = target;
    packed_data->args.a2 = id;
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
#ifndef direct_glBitmap
static inline void push_glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte * bitmap) {
    PACKED_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_const_GLubyte___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_const_GLubyte___GENPT__));
    packed_data->format = FORMAT_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_const_GLubyte___GENPT__;
    packed_data->func = glBitmap;
    packed_data->args.a1 = width;
    packed_data->args.a2 = height;
    packed_data->args.a3 = xorig;
    packed_data->args.a4 = yorig;
    packed_data->args.a5 = xmove;
    packed_data->args.a6 = ymove;
    packed_data->args.a7 = bitmap;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glBlendColor
static inline void push_glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat;
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
#ifndef direct_glCallList
static inline void push_glCallList(GLuint list) {
    PACKED_void_GLuint *packed_data = malloc(sizeof(PACKED_void_GLuint));
    packed_data->format = FORMAT_void_GLuint;
    packed_data->func = glCallList;
    packed_data->args.a1 = list;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glCallLists
static inline void push_glCallLists(GLsizei n, GLenum type, const GLvoid * lists) {
    PACKED_void_GLsizei_GLenum_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLsizei_GLenum_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLsizei_GLenum_const_GLvoid___GENPT__;
    packed_data->func = glCallLists;
    packed_data->args.a1 = n;
    packed_data->args.a2 = type;
    packed_data->args.a3 = lists;
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
#ifndef direct_glClearAccum
static inline void push_glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat;
    packed_data->func = glClearAccum;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glClearColor
static inline void push_glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat;
    packed_data->func = glClearColor;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glClearDepth
static inline void push_glClearDepth(GLdouble depth) {
    PACKED_void_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble));
    packed_data->format = FORMAT_void_GLdouble;
    packed_data->func = glClearDepth;
    packed_data->args.a1 = depth;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glClearIndex
static inline void push_glClearIndex(GLfloat c) {
    PACKED_void_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat));
    packed_data->format = FORMAT_void_GLfloat;
    packed_data->func = glClearIndex;
    packed_data->args.a1 = c;
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
#ifndef direct_glClipPlane
static inline void push_glClipPlane(GLenum plane, const GLdouble * equation) {
    PACKED_void_GLenum_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLdouble___GENPT__;
    packed_data->func = glClipPlane;
    packed_data->args.a1 = plane;
    packed_data->args.a2 = equation;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor3b
static inline void push_glColor3b(GLbyte red, GLbyte green, GLbyte blue) {
    PACKED_void_GLbyte_GLbyte_GLbyte *packed_data = malloc(sizeof(PACKED_void_GLbyte_GLbyte_GLbyte));
    packed_data->format = FORMAT_void_GLbyte_GLbyte_GLbyte;
    packed_data->func = glColor3b;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor3bv
static inline void push_glColor3bv(const GLbyte * v) {
    PACKED_void_const_GLbyte___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLbyte___GENPT__));
    packed_data->format = FORMAT_void_const_GLbyte___GENPT__;
    packed_data->func = glColor3bv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor3d
static inline void push_glColor3d(GLdouble red, GLdouble green, GLdouble blue) {
    PACKED_void_GLdouble_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLdouble_GLdouble_GLdouble;
    packed_data->func = glColor3d;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor3dv
static inline void push_glColor3dv(const GLdouble * v) {
    PACKED_void_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_const_GLdouble___GENPT__;
    packed_data->func = glColor3dv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor3f
static inline void push_glColor3f(GLfloat red, GLfloat green, GLfloat blue) {
    PACKED_void_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat_GLfloat;
    packed_data->func = glColor3f;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor3fv
static inline void push_glColor3fv(const GLfloat * v) {
    PACKED_void_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_const_GLfloat___GENPT__;
    packed_data->func = glColor3fv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor3i
static inline void push_glColor3i(GLint red, GLint green, GLint blue) {
    PACKED_void_GLint_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLint_GLint_GLint));
    packed_data->format = FORMAT_void_GLint_GLint_GLint;
    packed_data->func = glColor3i;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor3iv
static inline void push_glColor3iv(const GLint * v) {
    PACKED_void_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_const_GLint___GENPT__;
    packed_data->func = glColor3iv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor3s
static inline void push_glColor3s(GLshort red, GLshort green, GLshort blue) {
    PACKED_void_GLshort_GLshort_GLshort *packed_data = malloc(sizeof(PACKED_void_GLshort_GLshort_GLshort));
    packed_data->format = FORMAT_void_GLshort_GLshort_GLshort;
    packed_data->func = glColor3s;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor3sv
static inline void push_glColor3sv(const GLshort * v) {
    PACKED_void_const_GLshort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLshort___GENPT__));
    packed_data->format = FORMAT_void_const_GLshort___GENPT__;
    packed_data->func = glColor3sv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor3ub
static inline void push_glColor3ub(GLubyte red, GLubyte green, GLubyte blue) {
    PACKED_void_GLubyte_GLubyte_GLubyte *packed_data = malloc(sizeof(PACKED_void_GLubyte_GLubyte_GLubyte));
    packed_data->format = FORMAT_void_GLubyte_GLubyte_GLubyte;
    packed_data->func = glColor3ub;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor3ubv
static inline void push_glColor3ubv(const GLubyte * v) {
    PACKED_void_const_GLubyte___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLubyte___GENPT__));
    packed_data->format = FORMAT_void_const_GLubyte___GENPT__;
    packed_data->func = glColor3ubv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor3ui
static inline void push_glColor3ui(GLuint red, GLuint green, GLuint blue) {
    PACKED_void_GLuint_GLuint_GLuint *packed_data = malloc(sizeof(PACKED_void_GLuint_GLuint_GLuint));
    packed_data->format = FORMAT_void_GLuint_GLuint_GLuint;
    packed_data->func = glColor3ui;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor3uiv
static inline void push_glColor3uiv(const GLuint * v) {
    PACKED_void_const_GLuint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLuint___GENPT__));
    packed_data->format = FORMAT_void_const_GLuint___GENPT__;
    packed_data->func = glColor3uiv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor3us
static inline void push_glColor3us(GLushort red, GLushort green, GLushort blue) {
    PACKED_void_GLushort_GLushort_GLushort *packed_data = malloc(sizeof(PACKED_void_GLushort_GLushort_GLushort));
    packed_data->format = FORMAT_void_GLushort_GLushort_GLushort;
    packed_data->func = glColor3us;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor3usv
static inline void push_glColor3usv(const GLushort * v) {
    PACKED_void_const_GLushort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLushort___GENPT__));
    packed_data->format = FORMAT_void_const_GLushort___GENPT__;
    packed_data->func = glColor3usv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor4b
static inline void push_glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha) {
    PACKED_void_GLbyte_GLbyte_GLbyte_GLbyte *packed_data = malloc(sizeof(PACKED_void_GLbyte_GLbyte_GLbyte_GLbyte));
    packed_data->format = FORMAT_void_GLbyte_GLbyte_GLbyte_GLbyte;
    packed_data->func = glColor4b;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor4bv
static inline void push_glColor4bv(const GLbyte * v) {
    PACKED_void_const_GLbyte___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLbyte___GENPT__));
    packed_data->format = FORMAT_void_const_GLbyte___GENPT__;
    packed_data->func = glColor4bv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor4d
static inline void push_glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha) {
    PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLdouble_GLdouble_GLdouble_GLdouble;
    packed_data->func = glColor4d;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor4dv
static inline void push_glColor4dv(const GLdouble * v) {
    PACKED_void_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_const_GLdouble___GENPT__;
    packed_data->func = glColor4dv;
    packed_data->args.a1 = v;
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
#ifndef direct_glColor4fv
static inline void push_glColor4fv(const GLfloat * v) {
    PACKED_void_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_const_GLfloat___GENPT__;
    packed_data->func = glColor4fv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor4i
static inline void push_glColor4i(GLint red, GLint green, GLint blue, GLint alpha) {
    PACKED_void_GLint_GLint_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLint_GLint_GLint_GLint));
    packed_data->format = FORMAT_void_GLint_GLint_GLint_GLint;
    packed_data->func = glColor4i;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor4iv
static inline void push_glColor4iv(const GLint * v) {
    PACKED_void_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_const_GLint___GENPT__;
    packed_data->func = glColor4iv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor4s
static inline void push_glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha) {
    PACKED_void_GLshort_GLshort_GLshort_GLshort *packed_data = malloc(sizeof(PACKED_void_GLshort_GLshort_GLshort_GLshort));
    packed_data->format = FORMAT_void_GLshort_GLshort_GLshort_GLshort;
    packed_data->func = glColor4s;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor4sv
static inline void push_glColor4sv(const GLshort * v) {
    PACKED_void_const_GLshort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLshort___GENPT__));
    packed_data->format = FORMAT_void_const_GLshort___GENPT__;
    packed_data->func = glColor4sv;
    packed_data->args.a1 = v;
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
#ifndef direct_glColor4ubv
static inline void push_glColor4ubv(const GLubyte * v) {
    PACKED_void_const_GLubyte___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLubyte___GENPT__));
    packed_data->format = FORMAT_void_const_GLubyte___GENPT__;
    packed_data->func = glColor4ubv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor4ui
static inline void push_glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha) {
    PACKED_void_GLuint_GLuint_GLuint_GLuint *packed_data = malloc(sizeof(PACKED_void_GLuint_GLuint_GLuint_GLuint));
    packed_data->format = FORMAT_void_GLuint_GLuint_GLuint_GLuint;
    packed_data->func = glColor4ui;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor4uiv
static inline void push_glColor4uiv(const GLuint * v) {
    PACKED_void_const_GLuint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLuint___GENPT__));
    packed_data->format = FORMAT_void_const_GLuint___GENPT__;
    packed_data->func = glColor4uiv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor4us
static inline void push_glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha) {
    PACKED_void_GLushort_GLushort_GLushort_GLushort *packed_data = malloc(sizeof(PACKED_void_GLushort_GLushort_GLushort_GLushort));
    packed_data->format = FORMAT_void_GLushort_GLushort_GLushort_GLushort;
    packed_data->func = glColor4us;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    packed_data->args.a4 = alpha;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColor4usv
static inline void push_glColor4usv(const GLushort * v) {
    PACKED_void_const_GLushort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLushort___GENPT__));
    packed_data->format = FORMAT_void_const_GLushort___GENPT__;
    packed_data->func = glColor4usv;
    packed_data->args.a1 = v;
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
#ifndef direct_glColorMaterial
static inline void push_glColorMaterial(GLenum face, GLenum mode) {
    PACKED_void_GLenum_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum));
    packed_data->format = FORMAT_void_GLenum_GLenum;
    packed_data->func = glColorMaterial;
    packed_data->args.a1 = face;
    packed_data->args.a2 = mode;
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
#ifndef direct_glColorSubTable
static inline void push_glColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const GLvoid * data) {
    PACKED_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
    packed_data->func = glColorSubTable;
    packed_data->args.a1 = target;
    packed_data->args.a2 = start;
    packed_data->args.a3 = count;
    packed_data->args.a4 = format;
    packed_data->args.a5 = type;
    packed_data->args.a6 = data;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColorTable
static inline void push_glColorTable(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * table) {
    PACKED_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
    packed_data->func = glColorTable;
    packed_data->args.a1 = target;
    packed_data->args.a2 = internalformat;
    packed_data->args.a3 = width;
    packed_data->args.a4 = format;
    packed_data->args.a5 = type;
    packed_data->args.a6 = table;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColorTableParameterfv
static inline void push_glColorTableParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__;
    packed_data->func = glColorTableParameterfv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glColorTableParameteriv
static inline void push_glColorTableParameteriv(GLenum target, GLenum pname, const GLint * params) {
    PACKED_void_GLenum_GLenum_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_const_GLint___GENPT__;
    packed_data->func = glColorTableParameteriv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glCompressedTexImage1D
static inline void push_glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid * data) {
    PACKED_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__;
    packed_data->func = glCompressedTexImage1D;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = internalformat;
    packed_data->args.a4 = width;
    packed_data->args.a5 = border;
    packed_data->args.a6 = imageSize;
    packed_data->args.a7 = data;
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
#ifndef direct_glCompressedTexImage3D
static inline void push_glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid * data) {
    PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_const_GLvoid___GENPT__;
    packed_data->func = glCompressedTexImage3D;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = internalformat;
    packed_data->args.a4 = width;
    packed_data->args.a5 = height;
    packed_data->args.a6 = depth;
    packed_data->args.a7 = border;
    packed_data->args.a8 = imageSize;
    packed_data->args.a9 = data;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glCompressedTexSubImage1D
static inline void push_glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid * data) {
    PACKED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__;
    packed_data->func = glCompressedTexSubImage1D;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = xoffset;
    packed_data->args.a4 = width;
    packed_data->args.a5 = format;
    packed_data->args.a6 = imageSize;
    packed_data->args.a7 = data;
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
#ifndef direct_glCompressedTexSubImage3D
static inline void push_glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid * data) {
    PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_const_GLvoid___GENPT__;
    packed_data->func = glCompressedTexSubImage3D;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = xoffset;
    packed_data->args.a4 = yoffset;
    packed_data->args.a5 = zoffset;
    packed_data->args.a6 = width;
    packed_data->args.a7 = height;
    packed_data->args.a8 = depth;
    packed_data->args.a9 = format;
    packed_data->args.a10 = imageSize;
    packed_data->args.a11 = data;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glConvolutionFilter1D
static inline void push_glConvolutionFilter1D(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const GLvoid * image) {
    PACKED_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
    packed_data->func = glConvolutionFilter1D;
    packed_data->args.a1 = target;
    packed_data->args.a2 = internalformat;
    packed_data->args.a3 = width;
    packed_data->args.a4 = format;
    packed_data->args.a5 = type;
    packed_data->args.a6 = image;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glConvolutionFilter2D
static inline void push_glConvolutionFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * image) {
    PACKED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
    packed_data->func = glConvolutionFilter2D;
    packed_data->args.a1 = target;
    packed_data->args.a2 = internalformat;
    packed_data->args.a3 = width;
    packed_data->args.a4 = height;
    packed_data->args.a5 = format;
    packed_data->args.a6 = type;
    packed_data->args.a7 = image;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glConvolutionParameterf
static inline void push_glConvolutionParameterf(GLenum target, GLenum pname, GLfloat params) {
    PACKED_void_GLenum_GLenum_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfloat));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLfloat;
    packed_data->func = glConvolutionParameterf;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glConvolutionParameterfv
static inline void push_glConvolutionParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__;
    packed_data->func = glConvolutionParameterfv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glConvolutionParameteri
static inline void push_glConvolutionParameteri(GLenum target, GLenum pname, GLint params) {
    PACKED_void_GLenum_GLenum_GLint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLint;
    packed_data->func = glConvolutionParameteri;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glConvolutionParameteriv
static inline void push_glConvolutionParameteriv(GLenum target, GLenum pname, const GLint * params) {
    PACKED_void_GLenum_GLenum_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_const_GLint___GENPT__;
    packed_data->func = glConvolutionParameteriv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glCopyColorSubTable
static inline void push_glCopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width) {
    PACKED_void_GLenum_GLsizei_GLint_GLint_GLsizei *packed_data = malloc(sizeof(PACKED_void_GLenum_GLsizei_GLint_GLint_GLsizei));
    packed_data->format = FORMAT_void_GLenum_GLsizei_GLint_GLint_GLsizei;
    packed_data->func = glCopyColorSubTable;
    packed_data->args.a1 = target;
    packed_data->args.a2 = start;
    packed_data->args.a3 = x;
    packed_data->args.a4 = y;
    packed_data->args.a5 = width;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glCopyColorTable
static inline void push_glCopyColorTable(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
    PACKED_void_GLenum_GLenum_GLint_GLint_GLsizei *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint_GLint_GLsizei));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLint_GLint_GLsizei;
    packed_data->func = glCopyColorTable;
    packed_data->args.a1 = target;
    packed_data->args.a2 = internalformat;
    packed_data->args.a3 = x;
    packed_data->args.a4 = y;
    packed_data->args.a5 = width;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glCopyConvolutionFilter1D
static inline void push_glCopyConvolutionFilter1D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width) {
    PACKED_void_GLenum_GLenum_GLint_GLint_GLsizei *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint_GLint_GLsizei));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLint_GLint_GLsizei;
    packed_data->func = glCopyConvolutionFilter1D;
    packed_data->args.a1 = target;
    packed_data->args.a2 = internalformat;
    packed_data->args.a3 = x;
    packed_data->args.a4 = y;
    packed_data->args.a5 = width;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glCopyConvolutionFilter2D
static inline void push_glCopyConvolutionFilter2D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height) {
    PACKED_void_GLenum_GLenum_GLint_GLint_GLsizei_GLsizei *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint_GLint_GLsizei_GLsizei));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLint_GLint_GLsizei_GLsizei;
    packed_data->func = glCopyConvolutionFilter2D;
    packed_data->args.a1 = target;
    packed_data->args.a2 = internalformat;
    packed_data->args.a3 = x;
    packed_data->args.a4 = y;
    packed_data->args.a5 = width;
    packed_data->args.a6 = height;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glCopyPixels
static inline void push_glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type) {
    PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum *packed_data = malloc(sizeof(PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum));
    packed_data->format = FORMAT_void_GLint_GLint_GLsizei_GLsizei_GLenum;
    packed_data->func = glCopyPixels;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = width;
    packed_data->args.a4 = height;
    packed_data->args.a5 = type;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glCopyTexImage1D
static inline void push_glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
    PACKED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint));
    packed_data->format = FORMAT_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint;
    packed_data->func = glCopyTexImage1D;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = internalformat;
    packed_data->args.a4 = x;
    packed_data->args.a5 = y;
    packed_data->args.a6 = width;
    packed_data->args.a7 = border;
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
#ifndef direct_glCopyTexSubImage1D
static inline void push_glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei));
    packed_data->format = FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLsizei;
    packed_data->func = glCopyTexSubImage1D;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = xoffset;
    packed_data->args.a4 = x;
    packed_data->args.a5 = y;
    packed_data->args.a6 = width;
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
#ifndef direct_glCopyTexSubImage3D
static inline void push_glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei));
    packed_data->format = FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei;
    packed_data->func = glCopyTexSubImage3D;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = xoffset;
    packed_data->args.a4 = yoffset;
    packed_data->args.a5 = zoffset;
    packed_data->args.a6 = x;
    packed_data->args.a7 = y;
    packed_data->args.a8 = width;
    packed_data->args.a9 = height;
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
#ifndef direct_glDeleteLists
static inline void push_glDeleteLists(GLuint list, GLsizei range) {
    PACKED_void_GLuint_GLsizei *packed_data = malloc(sizeof(PACKED_void_GLuint_GLsizei));
    packed_data->format = FORMAT_void_GLuint_GLsizei;
    packed_data->func = glDeleteLists;
    packed_data->args.a1 = list;
    packed_data->args.a2 = range;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glDeleteQueries
static inline void push_glDeleteQueries(GLsizei n, const GLuint * ids) {
    PACKED_void_GLsizei_const_GLuint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLsizei_const_GLuint___GENPT__));
    packed_data->format = FORMAT_void_GLsizei_const_GLuint___GENPT__;
    packed_data->func = glDeleteQueries;
    packed_data->args.a1 = n;
    packed_data->args.a2 = ids;
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
#ifndef direct_glDepthRange
static inline void push_glDepthRange(GLdouble near, GLdouble far) {
    PACKED_void_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLdouble_GLdouble;
    packed_data->func = glDepthRange;
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
#ifndef direct_glDrawBuffer
static inline void push_glDrawBuffer(GLenum mode) {
    PACKED_void_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum));
    packed_data->format = FORMAT_void_GLenum;
    packed_data->func = glDrawBuffer;
    packed_data->args.a1 = mode;
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
#ifndef direct_glDrawPixels
static inline void push_glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels) {
    PACKED_void_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
    packed_data->func = glDrawPixels;
    packed_data->args.a1 = width;
    packed_data->args.a2 = height;
    packed_data->args.a3 = format;
    packed_data->args.a4 = type;
    packed_data->args.a5 = pixels;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glDrawRangeElements
static inline void push_glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const GLvoid * indices) {
    PACKED_void_GLenum_GLuint_GLuint_GLsizei_GLenum_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLuint_GLuint_GLsizei_GLenum_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLuint_GLuint_GLsizei_GLenum_const_GLvoid___GENPT__;
    packed_data->func = glDrawRangeElements;
    packed_data->args.a1 = mode;
    packed_data->args.a2 = start;
    packed_data->args.a3 = end;
    packed_data->args.a4 = count;
    packed_data->args.a5 = type;
    packed_data->args.a6 = indices;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glEdgeFlag
static inline void push_glEdgeFlag(GLboolean flag) {
    PACKED_void_GLboolean *packed_data = malloc(sizeof(PACKED_void_GLboolean));
    packed_data->format = FORMAT_void_GLboolean;
    packed_data->func = glEdgeFlag;
    packed_data->args.a1 = flag;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glEdgeFlagPointer
static inline void push_glEdgeFlagPointer(GLsizei stride, const GLvoid * pointer) {
    PACKED_void_GLsizei_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLsizei_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLsizei_const_GLvoid___GENPT__;
    packed_data->func = glEdgeFlagPointer;
    packed_data->args.a1 = stride;
    packed_data->args.a2 = pointer;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glEdgeFlagv
static inline void push_glEdgeFlagv(const GLboolean * flag) {
    PACKED_void_const_GLboolean___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLboolean___GENPT__));
    packed_data->format = FORMAT_void_const_GLboolean___GENPT__;
    packed_data->func = glEdgeFlagv;
    packed_data->args.a1 = flag;
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
#ifndef direct_glEnd
static inline void push_glEnd() {
    PACKED_void *packed_data = malloc(sizeof(PACKED_void));
    packed_data->format = FORMAT_void;
    packed_data->func = glEnd;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glEndList
static inline void push_glEndList() {
    PACKED_void *packed_data = malloc(sizeof(PACKED_void));
    packed_data->format = FORMAT_void;
    packed_data->func = glEndList;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glEndQuery
static inline void push_glEndQuery(GLenum target) {
    PACKED_void_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum));
    packed_data->format = FORMAT_void_GLenum;
    packed_data->func = glEndQuery;
    packed_data->args.a1 = target;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glEvalCoord1d
static inline void push_glEvalCoord1d(GLdouble u) {
    PACKED_void_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble));
    packed_data->format = FORMAT_void_GLdouble;
    packed_data->func = glEvalCoord1d;
    packed_data->args.a1 = u;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glEvalCoord1dv
static inline void push_glEvalCoord1dv(const GLdouble * u) {
    PACKED_void_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_const_GLdouble___GENPT__;
    packed_data->func = glEvalCoord1dv;
    packed_data->args.a1 = u;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glEvalCoord1f
static inline void push_glEvalCoord1f(GLfloat u) {
    PACKED_void_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat));
    packed_data->format = FORMAT_void_GLfloat;
    packed_data->func = glEvalCoord1f;
    packed_data->args.a1 = u;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glEvalCoord1fv
static inline void push_glEvalCoord1fv(const GLfloat * u) {
    PACKED_void_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_const_GLfloat___GENPT__;
    packed_data->func = glEvalCoord1fv;
    packed_data->args.a1 = u;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glEvalCoord2d
static inline void push_glEvalCoord2d(GLdouble u, GLdouble v) {
    PACKED_void_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLdouble_GLdouble;
    packed_data->func = glEvalCoord2d;
    packed_data->args.a1 = u;
    packed_data->args.a2 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glEvalCoord2dv
static inline void push_glEvalCoord2dv(const GLdouble * u) {
    PACKED_void_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_const_GLdouble___GENPT__;
    packed_data->func = glEvalCoord2dv;
    packed_data->args.a1 = u;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glEvalCoord2f
static inline void push_glEvalCoord2f(GLfloat u, GLfloat v) {
    PACKED_void_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat;
    packed_data->func = glEvalCoord2f;
    packed_data->args.a1 = u;
    packed_data->args.a2 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glEvalCoord2fv
static inline void push_glEvalCoord2fv(const GLfloat * u) {
    PACKED_void_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_const_GLfloat___GENPT__;
    packed_data->func = glEvalCoord2fv;
    packed_data->args.a1 = u;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glEvalMesh1
static inline void push_glEvalMesh1(GLenum mode, GLint i1, GLint i2) {
    PACKED_void_GLenum_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLint));
    packed_data->format = FORMAT_void_GLenum_GLint_GLint;
    packed_data->func = glEvalMesh1;
    packed_data->args.a1 = mode;
    packed_data->args.a2 = i1;
    packed_data->args.a3 = i2;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glEvalMesh2
static inline void push_glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2) {
    PACKED_void_GLenum_GLint_GLint_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLint_GLint_GLint));
    packed_data->format = FORMAT_void_GLenum_GLint_GLint_GLint_GLint;
    packed_data->func = glEvalMesh2;
    packed_data->args.a1 = mode;
    packed_data->args.a2 = i1;
    packed_data->args.a3 = i2;
    packed_data->args.a4 = j1;
    packed_data->args.a5 = j2;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glEvalPoint1
static inline void push_glEvalPoint1(GLint i) {
    PACKED_void_GLint *packed_data = malloc(sizeof(PACKED_void_GLint));
    packed_data->format = FORMAT_void_GLint;
    packed_data->func = glEvalPoint1;
    packed_data->args.a1 = i;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glEvalPoint2
static inline void push_glEvalPoint2(GLint i, GLint j) {
    PACKED_void_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLint_GLint));
    packed_data->format = FORMAT_void_GLint_GLint;
    packed_data->func = glEvalPoint2;
    packed_data->args.a1 = i;
    packed_data->args.a2 = j;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glFeedbackBuffer
static inline void push_glFeedbackBuffer(GLsizei size, GLenum type, GLfloat * buffer) {
    PACKED_void_GLsizei_GLenum_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLsizei_GLenum_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLsizei_GLenum_GLfloat___GENPT__;
    packed_data->func = glFeedbackBuffer;
    packed_data->args.a1 = size;
    packed_data->args.a2 = type;
    packed_data->args.a3 = buffer;
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
#ifndef direct_glFogCoordPointer
static inline void push_glFogCoordPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLsizei_const_GLvoid___GENPT__;
    packed_data->func = glFogCoordPointer;
    packed_data->args.a1 = type;
    packed_data->args.a2 = stride;
    packed_data->args.a3 = pointer;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glFogCoordd
static inline void push_glFogCoordd(GLdouble coord) {
    PACKED_void_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble));
    packed_data->format = FORMAT_void_GLdouble;
    packed_data->func = glFogCoordd;
    packed_data->args.a1 = coord;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glFogCoorddv
static inline void push_glFogCoorddv(const GLdouble * coord) {
    PACKED_void_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_const_GLdouble___GENPT__;
    packed_data->func = glFogCoorddv;
    packed_data->args.a1 = coord;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glFogCoordf
static inline void push_glFogCoordf(GLfloat coord) {
    PACKED_void_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat));
    packed_data->format = FORMAT_void_GLfloat;
    packed_data->func = glFogCoordf;
    packed_data->args.a1 = coord;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glFogCoordfv
static inline void push_glFogCoordfv(const GLfloat * coord) {
    PACKED_void_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_const_GLfloat___GENPT__;
    packed_data->func = glFogCoordfv;
    packed_data->args.a1 = coord;
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
#ifndef direct_glFogi
static inline void push_glFogi(GLenum pname, GLint param) {
    PACKED_void_GLenum_GLint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint));
    packed_data->format = FORMAT_void_GLenum_GLint;
    packed_data->func = glFogi;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glFogiv
static inline void push_glFogiv(GLenum pname, const GLint * params) {
    PACKED_void_GLenum_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLint___GENPT__;
    packed_data->func = glFogiv;
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
#ifndef direct_glFrustum
static inline void push_glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
    PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble;
    packed_data->func = glFrustum;
    packed_data->args.a1 = left;
    packed_data->args.a2 = right;
    packed_data->args.a3 = bottom;
    packed_data->args.a4 = top;
    packed_data->args.a5 = zNear;
    packed_data->args.a6 = zFar;
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
#ifndef direct_glGenLists
static inline void push_glGenLists(GLsizei range) {
    PACKED_GLuint_GLsizei *packed_data = malloc(sizeof(PACKED_GLuint_GLsizei));
    packed_data->format = FORMAT_GLuint_GLsizei;
    packed_data->func = glGenLists;
    packed_data->args.a1 = range;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGenQueries
static inline void push_glGenQueries(GLsizei n, GLuint * ids) {
    PACKED_void_GLsizei_GLuint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLsizei_GLuint___GENPT__));
    packed_data->format = FORMAT_void_GLsizei_GLuint___GENPT__;
    packed_data->func = glGenQueries;
    packed_data->args.a1 = n;
    packed_data->args.a2 = ids;
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
#ifndef direct_glGetBufferPointerv
static inline void push_glGetBufferPointerv(GLenum target, GLenum pname, GLvoid * params) {
    PACKED_void_GLenum_GLenum_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLvoid___GENPT__;
    packed_data->func = glGetBufferPointerv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetBufferSubData
static inline void push_glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid * data) {
    PACKED_void_GLenum_GLintptr_GLsizeiptr_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLintptr_GLsizeiptr_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLintptr_GLsizeiptr_GLvoid___GENPT__;
    packed_data->func = glGetBufferSubData;
    packed_data->args.a1 = target;
    packed_data->args.a2 = offset;
    packed_data->args.a3 = size;
    packed_data->args.a4 = data;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetClipPlane
static inline void push_glGetClipPlane(GLenum plane, GLdouble * equation) {
    PACKED_void_GLenum_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLdouble___GENPT__;
    packed_data->func = glGetClipPlane;
    packed_data->args.a1 = plane;
    packed_data->args.a2 = equation;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetColorTable
static inline void push_glGetColorTable(GLenum target, GLenum format, GLenum type, GLvoid * table) {
    PACKED_void_GLenum_GLenum_GLenum_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLenum_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLenum_GLvoid___GENPT__;
    packed_data->func = glGetColorTable;
    packed_data->args.a1 = target;
    packed_data->args.a2 = format;
    packed_data->args.a3 = type;
    packed_data->args.a4 = table;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetColorTableParameterfv
static inline void push_glGetColorTableParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLfloat___GENPT__;
    packed_data->func = glGetColorTableParameterfv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetColorTableParameteriv
static inline void push_glGetColorTableParameteriv(GLenum target, GLenum pname, GLint * params) {
    PACKED_void_GLenum_GLenum_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLint___GENPT__;
    packed_data->func = glGetColorTableParameteriv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetCompressedTexImage
static inline void push_glGetCompressedTexImage(GLenum target, GLint level, GLvoid * img) {
    PACKED_void_GLenum_GLint_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLint_GLvoid___GENPT__;
    packed_data->func = glGetCompressedTexImage;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = img;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetConvolutionFilter
static inline void push_glGetConvolutionFilter(GLenum target, GLenum format, GLenum type, GLvoid * image) {
    PACKED_void_GLenum_GLenum_GLenum_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLenum_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLenum_GLvoid___GENPT__;
    packed_data->func = glGetConvolutionFilter;
    packed_data->args.a1 = target;
    packed_data->args.a2 = format;
    packed_data->args.a3 = type;
    packed_data->args.a4 = image;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetConvolutionParameterfv
static inline void push_glGetConvolutionParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLfloat___GENPT__;
    packed_data->func = glGetConvolutionParameterfv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetConvolutionParameteriv
static inline void push_glGetConvolutionParameteriv(GLenum target, GLenum pname, GLint * params) {
    PACKED_void_GLenum_GLenum_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLint___GENPT__;
    packed_data->func = glGetConvolutionParameteriv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetDoublev
static inline void push_glGetDoublev(GLenum pname, GLdouble * params) {
    PACKED_void_GLenum_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLdouble___GENPT__;
    packed_data->func = glGetDoublev;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = params;
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
#ifndef direct_glGetHistogram
static inline void push_glGetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values) {
    PACKED_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__;
    packed_data->func = glGetHistogram;
    packed_data->args.a1 = target;
    packed_data->args.a2 = reset;
    packed_data->args.a3 = format;
    packed_data->args.a4 = type;
    packed_data->args.a5 = values;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetHistogramParameterfv
static inline void push_glGetHistogramParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLfloat___GENPT__;
    packed_data->func = glGetHistogramParameterfv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetHistogramParameteriv
static inline void push_glGetHistogramParameteriv(GLenum target, GLenum pname, GLint * params) {
    PACKED_void_GLenum_GLenum_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLint___GENPT__;
    packed_data->func = glGetHistogramParameteriv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
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
#ifndef direct_glGetLightiv
static inline void push_glGetLightiv(GLenum light, GLenum pname, GLint * params) {
    PACKED_void_GLenum_GLenum_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLint___GENPT__;
    packed_data->func = glGetLightiv;
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetMapdv
static inline void push_glGetMapdv(GLenum target, GLenum query, GLdouble * v) {
    PACKED_void_GLenum_GLenum_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLdouble___GENPT__;
    packed_data->func = glGetMapdv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = query;
    packed_data->args.a3 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetMapfv
static inline void push_glGetMapfv(GLenum target, GLenum query, GLfloat * v) {
    PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLfloat___GENPT__;
    packed_data->func = glGetMapfv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = query;
    packed_data->args.a3 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetMapiv
static inline void push_glGetMapiv(GLenum target, GLenum query, GLint * v) {
    PACKED_void_GLenum_GLenum_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLint___GENPT__;
    packed_data->func = glGetMapiv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = query;
    packed_data->args.a3 = v;
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
#ifndef direct_glGetMaterialiv
static inline void push_glGetMaterialiv(GLenum face, GLenum pname, GLint * params) {
    PACKED_void_GLenum_GLenum_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLint___GENPT__;
    packed_data->func = glGetMaterialiv;
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetMinmax
static inline void push_glGetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid * values) {
    PACKED_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLboolean_GLenum_GLenum_GLvoid___GENPT__;
    packed_data->func = glGetMinmax;
    packed_data->args.a1 = target;
    packed_data->args.a2 = reset;
    packed_data->args.a3 = format;
    packed_data->args.a4 = type;
    packed_data->args.a5 = values;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetMinmaxParameterfv
static inline void push_glGetMinmaxParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLfloat___GENPT__;
    packed_data->func = glGetMinmaxParameterfv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetMinmaxParameteriv
static inline void push_glGetMinmaxParameteriv(GLenum target, GLenum pname, GLint * params) {
    PACKED_void_GLenum_GLenum_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLint___GENPT__;
    packed_data->func = glGetMinmaxParameteriv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetPixelMapfv
static inline void push_glGetPixelMapfv(GLenum map, GLfloat * values) {
    PACKED_void_GLenum_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLfloat___GENPT__;
    packed_data->func = glGetPixelMapfv;
    packed_data->args.a1 = map;
    packed_data->args.a2 = values;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetPixelMapuiv
static inline void push_glGetPixelMapuiv(GLenum map, GLuint * values) {
    PACKED_void_GLenum_GLuint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLuint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLuint___GENPT__;
    packed_data->func = glGetPixelMapuiv;
    packed_data->args.a1 = map;
    packed_data->args.a2 = values;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetPixelMapusv
static inline void push_glGetPixelMapusv(GLenum map, GLushort * values) {
    PACKED_void_GLenum_GLushort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLushort___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLushort___GENPT__;
    packed_data->func = glGetPixelMapusv;
    packed_data->args.a1 = map;
    packed_data->args.a2 = values;
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
#ifndef direct_glGetPolygonStipple
static inline void push_glGetPolygonStipple(GLubyte * mask) {
    PACKED_void_GLubyte___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLubyte___GENPT__));
    packed_data->format = FORMAT_void_GLubyte___GENPT__;
    packed_data->func = glGetPolygonStipple;
    packed_data->args.a1 = mask;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetQueryObjectiv
static inline void push_glGetQueryObjectiv(GLuint id, GLenum pname, GLint * params) {
    PACKED_void_GLuint_GLenum_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLuint_GLenum_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLuint_GLenum_GLint___GENPT__;
    packed_data->func = glGetQueryObjectiv;
    packed_data->args.a1 = id;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetQueryObjectuiv
static inline void push_glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint * params) {
    PACKED_void_GLuint_GLenum_GLuint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLuint_GLenum_GLuint___GENPT__));
    packed_data->format = FORMAT_void_GLuint_GLenum_GLuint___GENPT__;
    packed_data->func = glGetQueryObjectuiv;
    packed_data->args.a1 = id;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetQueryiv
static inline void push_glGetQueryiv(GLenum target, GLenum pname, GLint * params) {
    PACKED_void_GLenum_GLenum_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLint___GENPT__;
    packed_data->func = glGetQueryiv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetSeparableFilter
static inline void push_glGetSeparableFilter(GLenum target, GLenum format, GLenum type, GLvoid * row, GLvoid * column, GLvoid * span) {
    PACKED_void_GLenum_GLenum_GLenum_GLvoid___GENPT___GLvoid___GENPT___GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLenum_GLvoid___GENPT___GLvoid___GENPT___GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLenum_GLvoid___GENPT___GLvoid___GENPT___GLvoid___GENPT__;
    packed_data->func = glGetSeparableFilter;
    packed_data->args.a1 = target;
    packed_data->args.a2 = format;
    packed_data->args.a3 = type;
    packed_data->args.a4 = row;
    packed_data->args.a5 = column;
    packed_data->args.a6 = span;
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
#ifndef direct_glGetTexGendv
static inline void push_glGetTexGendv(GLenum coord, GLenum pname, GLdouble * params) {
    PACKED_void_GLenum_GLenum_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLdouble___GENPT__;
    packed_data->func = glGetTexGendv;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetTexGenfv
static inline void push_glGetTexGenfv(GLenum coord, GLenum pname, GLfloat * params) {
    PACKED_void_GLenum_GLenum_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLfloat___GENPT__;
    packed_data->func = glGetTexGenfv;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetTexGeniv
static inline void push_glGetTexGeniv(GLenum coord, GLenum pname, GLint * params) {
    PACKED_void_GLenum_GLenum_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLint___GENPT__;
    packed_data->func = glGetTexGeniv;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetTexImage
static inline void push_glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid * pixels) {
    PACKED_void_GLenum_GLint_GLenum_GLenum_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLenum_GLenum_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLint_GLenum_GLenum_GLvoid___GENPT__;
    packed_data->func = glGetTexImage;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = format;
    packed_data->args.a4 = type;
    packed_data->args.a5 = pixels;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetTexLevelParameterfv
static inline void push_glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat * params) {
    PACKED_void_GLenum_GLint_GLenum_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLenum_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLint_GLenum_GLfloat___GENPT__;
    packed_data->func = glGetTexLevelParameterfv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = pname;
    packed_data->args.a4 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glGetTexLevelParameteriv
static inline void push_glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint * params) {
    PACKED_void_GLenum_GLint_GLenum_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLenum_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLint_GLenum_GLint___GENPT__;
    packed_data->func = glGetTexLevelParameteriv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = pname;
    packed_data->args.a4 = params;
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
#ifndef direct_glHistogram
static inline void push_glHistogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink) {
    PACKED_void_GLenum_GLsizei_GLenum_GLboolean *packed_data = malloc(sizeof(PACKED_void_GLenum_GLsizei_GLenum_GLboolean));
    packed_data->format = FORMAT_void_GLenum_GLsizei_GLenum_GLboolean;
    packed_data->func = glHistogram;
    packed_data->args.a1 = target;
    packed_data->args.a2 = width;
    packed_data->args.a3 = internalformat;
    packed_data->args.a4 = sink;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glIndexMask
static inline void push_glIndexMask(GLuint mask) {
    PACKED_void_GLuint *packed_data = malloc(sizeof(PACKED_void_GLuint));
    packed_data->format = FORMAT_void_GLuint;
    packed_data->func = glIndexMask;
    packed_data->args.a1 = mask;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glIndexPointer
static inline void push_glIndexPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLsizei_const_GLvoid___GENPT__;
    packed_data->func = glIndexPointer;
    packed_data->args.a1 = type;
    packed_data->args.a2 = stride;
    packed_data->args.a3 = pointer;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glIndexd
static inline void push_glIndexd(GLdouble c) {
    PACKED_void_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble));
    packed_data->format = FORMAT_void_GLdouble;
    packed_data->func = glIndexd;
    packed_data->args.a1 = c;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glIndexdv
static inline void push_glIndexdv(const GLdouble * c) {
    PACKED_void_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_const_GLdouble___GENPT__;
    packed_data->func = glIndexdv;
    packed_data->args.a1 = c;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glIndexf
static inline void push_glIndexf(GLfloat c) {
    PACKED_void_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat));
    packed_data->format = FORMAT_void_GLfloat;
    packed_data->func = glIndexf;
    packed_data->args.a1 = c;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glIndexfv
static inline void push_glIndexfv(const GLfloat * c) {
    PACKED_void_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_const_GLfloat___GENPT__;
    packed_data->func = glIndexfv;
    packed_data->args.a1 = c;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glIndexi
static inline void push_glIndexi(GLint c) {
    PACKED_void_GLint *packed_data = malloc(sizeof(PACKED_void_GLint));
    packed_data->format = FORMAT_void_GLint;
    packed_data->func = glIndexi;
    packed_data->args.a1 = c;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glIndexiv
static inline void push_glIndexiv(const GLint * c) {
    PACKED_void_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_const_GLint___GENPT__;
    packed_data->func = glIndexiv;
    packed_data->args.a1 = c;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glIndexs
static inline void push_glIndexs(GLshort c) {
    PACKED_void_GLshort *packed_data = malloc(sizeof(PACKED_void_GLshort));
    packed_data->format = FORMAT_void_GLshort;
    packed_data->func = glIndexs;
    packed_data->args.a1 = c;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glIndexsv
static inline void push_glIndexsv(const GLshort * c) {
    PACKED_void_const_GLshort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLshort___GENPT__));
    packed_data->format = FORMAT_void_const_GLshort___GENPT__;
    packed_data->func = glIndexsv;
    packed_data->args.a1 = c;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glIndexub
static inline void push_glIndexub(GLubyte c) {
    PACKED_void_GLubyte *packed_data = malloc(sizeof(PACKED_void_GLubyte));
    packed_data->format = FORMAT_void_GLubyte;
    packed_data->func = glIndexub;
    packed_data->args.a1 = c;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glIndexubv
static inline void push_glIndexubv(const GLubyte * c) {
    PACKED_void_const_GLubyte___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLubyte___GENPT__));
    packed_data->format = FORMAT_void_const_GLubyte___GENPT__;
    packed_data->func = glIndexubv;
    packed_data->args.a1 = c;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glInitNames
static inline void push_glInitNames() {
    PACKED_void *packed_data = malloc(sizeof(PACKED_void));
    packed_data->format = FORMAT_void;
    packed_data->func = glInitNames;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glInterleavedArrays
static inline void push_glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid * pointer) {
    PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLsizei_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLsizei_const_GLvoid___GENPT__;
    packed_data->func = glInterleavedArrays;
    packed_data->args.a1 = format;
    packed_data->args.a2 = stride;
    packed_data->args.a3 = pointer;
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
#ifndef direct_glIsList
static inline void push_glIsList(GLuint list) {
    PACKED_GLboolean_GLuint *packed_data = malloc(sizeof(PACKED_GLboolean_GLuint));
    packed_data->format = FORMAT_GLboolean_GLuint;
    packed_data->func = glIsList;
    packed_data->args.a1 = list;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glIsQuery
static inline void push_glIsQuery(GLuint id) {
    PACKED_GLboolean_GLuint *packed_data = malloc(sizeof(PACKED_GLboolean_GLuint));
    packed_data->format = FORMAT_GLboolean_GLuint;
    packed_data->func = glIsQuery;
    packed_data->args.a1 = id;
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
#ifndef direct_glLightModeli
static inline void push_glLightModeli(GLenum pname, GLint param) {
    PACKED_void_GLenum_GLint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint));
    packed_data->format = FORMAT_void_GLenum_GLint;
    packed_data->func = glLightModeli;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glLightModeliv
static inline void push_glLightModeliv(GLenum pname, const GLint * params) {
    PACKED_void_GLenum_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLint___GENPT__;
    packed_data->func = glLightModeliv;
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
#ifndef direct_glLighti
static inline void push_glLighti(GLenum light, GLenum pname, GLint param) {
    PACKED_void_GLenum_GLenum_GLint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLint;
    packed_data->func = glLighti;
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glLightiv
static inline void push_glLightiv(GLenum light, GLenum pname, const GLint * params) {
    PACKED_void_GLenum_GLenum_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_const_GLint___GENPT__;
    packed_data->func = glLightiv;
    packed_data->args.a1 = light;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glLineStipple
static inline void push_glLineStipple(GLint factor, GLushort pattern) {
    PACKED_void_GLint_GLushort *packed_data = malloc(sizeof(PACKED_void_GLint_GLushort));
    packed_data->format = FORMAT_void_GLint_GLushort;
    packed_data->func = glLineStipple;
    packed_data->args.a1 = factor;
    packed_data->args.a2 = pattern;
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
#ifndef direct_glListBase
static inline void push_glListBase(GLuint base) {
    PACKED_void_GLuint *packed_data = malloc(sizeof(PACKED_void_GLuint));
    packed_data->format = FORMAT_void_GLuint;
    packed_data->func = glListBase;
    packed_data->args.a1 = base;
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
#ifndef direct_glLoadMatrixd
static inline void push_glLoadMatrixd(const GLdouble * m) {
    PACKED_void_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_const_GLdouble___GENPT__;
    packed_data->func = glLoadMatrixd;
    packed_data->args.a1 = m;
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
#ifndef direct_glLoadName
static inline void push_glLoadName(GLuint name) {
    PACKED_void_GLuint *packed_data = malloc(sizeof(PACKED_void_GLuint));
    packed_data->format = FORMAT_void_GLuint;
    packed_data->func = glLoadName;
    packed_data->args.a1 = name;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glLoadTransposeMatrixd
static inline void push_glLoadTransposeMatrixd(const GLdouble * m) {
    PACKED_void_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_const_GLdouble___GENPT__;
    packed_data->func = glLoadTransposeMatrixd;
    packed_data->args.a1 = m;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glLoadTransposeMatrixf
static inline void push_glLoadTransposeMatrixf(const GLfloat * m) {
    PACKED_void_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_const_GLfloat___GENPT__;
    packed_data->func = glLoadTransposeMatrixf;
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
#ifndef direct_glMap1d
static inline void push_glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble * points) {
    PACKED_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__;
    packed_data->func = glMap1d;
    packed_data->args.a1 = target;
    packed_data->args.a2 = u1;
    packed_data->args.a3 = u2;
    packed_data->args.a4 = stride;
    packed_data->args.a5 = order;
    packed_data->args.a6 = points;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMap1f
static inline void push_glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat * points) {
    PACKED_void_GLenum_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__;
    packed_data->func = glMap1f;
    packed_data->args.a1 = target;
    packed_data->args.a2 = u1;
    packed_data->args.a3 = u2;
    packed_data->args.a4 = stride;
    packed_data->args.a5 = order;
    packed_data->args.a6 = points;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMap2d
static inline void push_glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble * points) {
    PACKED_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_const_GLdouble___GENPT__;
    packed_data->func = glMap2d;
    packed_data->args.a1 = target;
    packed_data->args.a2 = u1;
    packed_data->args.a3 = u2;
    packed_data->args.a4 = ustride;
    packed_data->args.a5 = uorder;
    packed_data->args.a6 = v1;
    packed_data->args.a7 = v2;
    packed_data->args.a8 = vstride;
    packed_data->args.a9 = vorder;
    packed_data->args.a10 = points;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMap2f
static inline void push_glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat * points) {
    PACKED_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_const_GLfloat___GENPT__;
    packed_data->func = glMap2f;
    packed_data->args.a1 = target;
    packed_data->args.a2 = u1;
    packed_data->args.a3 = u2;
    packed_data->args.a4 = ustride;
    packed_data->args.a5 = uorder;
    packed_data->args.a6 = v1;
    packed_data->args.a7 = v2;
    packed_data->args.a8 = vstride;
    packed_data->args.a9 = vorder;
    packed_data->args.a10 = points;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMapBuffer
static inline void push_glMapBuffer(GLenum target, GLenum access) {
    PACKED_GLvoid___GENPT___GLenum_GLenum *packed_data = malloc(sizeof(PACKED_GLvoid___GENPT___GLenum_GLenum));
    packed_data->format = FORMAT_GLvoid___GENPT___GLenum_GLenum;
    packed_data->func = glMapBuffer;
    packed_data->args.a1 = target;
    packed_data->args.a2 = access;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMapGrid1d
static inline void push_glMapGrid1d(GLint un, GLdouble u1, GLdouble u2) {
    PACKED_void_GLint_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLint_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLint_GLdouble_GLdouble;
    packed_data->func = glMapGrid1d;
    packed_data->args.a1 = un;
    packed_data->args.a2 = u1;
    packed_data->args.a3 = u2;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMapGrid1f
static inline void push_glMapGrid1f(GLint un, GLfloat u1, GLfloat u2) {
    PACKED_void_GLint_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLint_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLint_GLfloat_GLfloat;
    packed_data->func = glMapGrid1f;
    packed_data->args.a1 = un;
    packed_data->args.a2 = u1;
    packed_data->args.a3 = u2;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMapGrid2d
static inline void push_glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2) {
    PACKED_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble;
    packed_data->func = glMapGrid2d;
    packed_data->args.a1 = un;
    packed_data->args.a2 = u1;
    packed_data->args.a3 = u2;
    packed_data->args.a4 = vn;
    packed_data->args.a5 = v1;
    packed_data->args.a6 = v2;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMapGrid2f
static inline void push_glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2) {
    PACKED_void_GLint_GLfloat_GLfloat_GLint_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLint_GLfloat_GLfloat_GLint_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLint_GLfloat_GLfloat_GLint_GLfloat_GLfloat;
    packed_data->func = glMapGrid2f;
    packed_data->args.a1 = un;
    packed_data->args.a2 = u1;
    packed_data->args.a3 = u2;
    packed_data->args.a4 = vn;
    packed_data->args.a5 = v1;
    packed_data->args.a6 = v2;
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
#ifndef direct_glMateriali
static inline void push_glMateriali(GLenum face, GLenum pname, GLint param) {
    PACKED_void_GLenum_GLenum_GLint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLint;
    packed_data->func = glMateriali;
    packed_data->args.a1 = face;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMaterialiv
static inline void push_glMaterialiv(GLenum face, GLenum pname, const GLint * params) {
    PACKED_void_GLenum_GLenum_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_const_GLint___GENPT__;
    packed_data->func = glMaterialiv;
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
#ifndef direct_glMinmax
static inline void push_glMinmax(GLenum target, GLenum internalformat, GLboolean sink) {
    PACKED_void_GLenum_GLenum_GLboolean *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLboolean));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLboolean;
    packed_data->func = glMinmax;
    packed_data->args.a1 = target;
    packed_data->args.a2 = internalformat;
    packed_data->args.a3 = sink;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultMatrixd
static inline void push_glMultMatrixd(const GLdouble * m) {
    PACKED_void_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_const_GLdouble___GENPT__;
    packed_data->func = glMultMatrixd;
    packed_data->args.a1 = m;
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
#ifndef direct_glMultTransposeMatrixd
static inline void push_glMultTransposeMatrixd(const GLdouble * m) {
    PACKED_void_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_const_GLdouble___GENPT__;
    packed_data->func = glMultTransposeMatrixd;
    packed_data->args.a1 = m;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultTransposeMatrixf
static inline void push_glMultTransposeMatrixf(const GLfloat * m) {
    PACKED_void_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_const_GLfloat___GENPT__;
    packed_data->func = glMultTransposeMatrixf;
    packed_data->args.a1 = m;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiDrawArrays
static inline void push_glMultiDrawArrays(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount) {
    PACKED_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei));
    packed_data->format = FORMAT_void_GLenum_const_GLint___GENPT___const_GLsizei___GENPT___GLsizei;
    packed_data->func = glMultiDrawArrays;
    packed_data->args.a1 = mode;
    packed_data->args.a2 = first;
    packed_data->args.a3 = count;
    packed_data->args.a4 = drawcount;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiDrawElements
static inline void push_glMultiDrawElements(GLenum mode, const GLsizei * count, GLenum type, GLvoid*const * indices, GLsizei drawcount) {
    PACKED_void_GLenum_const_GLsizei___GENPT___GLenum_GLvoid__GENPT__const___GENPT___GLsizei *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLsizei___GENPT___GLenum_GLvoid__GENPT__const___GENPT___GLsizei));
    packed_data->format = FORMAT_void_GLenum_const_GLsizei___GENPT___GLenum_GLvoid__GENPT__const___GENPT___GLsizei;
    packed_data->func = glMultiDrawElements;
    packed_data->args.a1 = mode;
    packed_data->args.a2 = count;
    packed_data->args.a3 = type;
    packed_data->args.a4 = indices;
    packed_data->args.a5 = drawcount;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord1d
static inline void push_glMultiTexCoord1d(GLenum target, GLdouble s) {
    PACKED_void_GLenum_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLenum_GLdouble));
    packed_data->format = FORMAT_void_GLenum_GLdouble;
    packed_data->func = glMultiTexCoord1d;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord1dv
static inline void push_glMultiTexCoord1dv(GLenum target, const GLdouble * v) {
    PACKED_void_GLenum_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLdouble___GENPT__;
    packed_data->func = glMultiTexCoord1dv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord1f
static inline void push_glMultiTexCoord1f(GLenum target, GLfloat s) {
    PACKED_void_GLenum_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLenum_GLfloat));
    packed_data->format = FORMAT_void_GLenum_GLfloat;
    packed_data->func = glMultiTexCoord1f;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord1fv
static inline void push_glMultiTexCoord1fv(GLenum target, const GLfloat * v) {
    PACKED_void_GLenum_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLfloat___GENPT__;
    packed_data->func = glMultiTexCoord1fv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord1i
static inline void push_glMultiTexCoord1i(GLenum target, GLint s) {
    PACKED_void_GLenum_GLint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint));
    packed_data->format = FORMAT_void_GLenum_GLint;
    packed_data->func = glMultiTexCoord1i;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord1iv
static inline void push_glMultiTexCoord1iv(GLenum target, const GLint * v) {
    PACKED_void_GLenum_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLint___GENPT__;
    packed_data->func = glMultiTexCoord1iv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord1s
static inline void push_glMultiTexCoord1s(GLenum target, GLshort s) {
    PACKED_void_GLenum_GLshort *packed_data = malloc(sizeof(PACKED_void_GLenum_GLshort));
    packed_data->format = FORMAT_void_GLenum_GLshort;
    packed_data->func = glMultiTexCoord1s;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord1sv
static inline void push_glMultiTexCoord1sv(GLenum target, const GLshort * v) {
    PACKED_void_GLenum_const_GLshort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLshort___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLshort___GENPT__;
    packed_data->func = glMultiTexCoord1sv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord2d
static inline void push_glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t) {
    PACKED_void_GLenum_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLenum_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLenum_GLdouble_GLdouble;
    packed_data->func = glMultiTexCoord2d;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord2dv
static inline void push_glMultiTexCoord2dv(GLenum target, const GLdouble * v) {
    PACKED_void_GLenum_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLdouble___GENPT__;
    packed_data->func = glMultiTexCoord2dv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord2f
static inline void push_glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) {
    PACKED_void_GLenum_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLenum_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLenum_GLfloat_GLfloat;
    packed_data->func = glMultiTexCoord2f;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord2fv
static inline void push_glMultiTexCoord2fv(GLenum target, const GLfloat * v) {
    PACKED_void_GLenum_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLfloat___GENPT__;
    packed_data->func = glMultiTexCoord2fv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord2i
static inline void push_glMultiTexCoord2i(GLenum target, GLint s, GLint t) {
    PACKED_void_GLenum_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLint));
    packed_data->format = FORMAT_void_GLenum_GLint_GLint;
    packed_data->func = glMultiTexCoord2i;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord2iv
static inline void push_glMultiTexCoord2iv(GLenum target, const GLint * v) {
    PACKED_void_GLenum_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLint___GENPT__;
    packed_data->func = glMultiTexCoord2iv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord2s
static inline void push_glMultiTexCoord2s(GLenum target, GLshort s, GLshort t) {
    PACKED_void_GLenum_GLshort_GLshort *packed_data = malloc(sizeof(PACKED_void_GLenum_GLshort_GLshort));
    packed_data->format = FORMAT_void_GLenum_GLshort_GLshort;
    packed_data->func = glMultiTexCoord2s;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord2sv
static inline void push_glMultiTexCoord2sv(GLenum target, const GLshort * v) {
    PACKED_void_GLenum_const_GLshort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLshort___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLshort___GENPT__;
    packed_data->func = glMultiTexCoord2sv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord3d
static inline void push_glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r) {
    PACKED_void_GLenum_GLdouble_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLenum_GLdouble_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLenum_GLdouble_GLdouble_GLdouble;
    packed_data->func = glMultiTexCoord3d;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord3dv
static inline void push_glMultiTexCoord3dv(GLenum target, const GLdouble * v) {
    PACKED_void_GLenum_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLdouble___GENPT__;
    packed_data->func = glMultiTexCoord3dv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord3f
static inline void push_glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r) {
    PACKED_void_GLenum_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLenum_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLenum_GLfloat_GLfloat_GLfloat;
    packed_data->func = glMultiTexCoord3f;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord3fv
static inline void push_glMultiTexCoord3fv(GLenum target, const GLfloat * v) {
    PACKED_void_GLenum_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLfloat___GENPT__;
    packed_data->func = glMultiTexCoord3fv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord3i
static inline void push_glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r) {
    PACKED_void_GLenum_GLint_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLint_GLint));
    packed_data->format = FORMAT_void_GLenum_GLint_GLint_GLint;
    packed_data->func = glMultiTexCoord3i;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord3iv
static inline void push_glMultiTexCoord3iv(GLenum target, const GLint * v) {
    PACKED_void_GLenum_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLint___GENPT__;
    packed_data->func = glMultiTexCoord3iv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord3s
static inline void push_glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r) {
    PACKED_void_GLenum_GLshort_GLshort_GLshort *packed_data = malloc(sizeof(PACKED_void_GLenum_GLshort_GLshort_GLshort));
    packed_data->format = FORMAT_void_GLenum_GLshort_GLshort_GLshort;
    packed_data->func = glMultiTexCoord3s;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord3sv
static inline void push_glMultiTexCoord3sv(GLenum target, const GLshort * v) {
    PACKED_void_GLenum_const_GLshort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLshort___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLshort___GENPT__;
    packed_data->func = glMultiTexCoord3sv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord4d
static inline void push_glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
    PACKED_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble;
    packed_data->func = glMultiTexCoord4d;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    packed_data->args.a5 = q;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord4dv
static inline void push_glMultiTexCoord4dv(GLenum target, const GLdouble * v) {
    PACKED_void_GLenum_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLdouble___GENPT__;
    packed_data->func = glMultiTexCoord4dv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
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
#ifndef direct_glMultiTexCoord4fv
static inline void push_glMultiTexCoord4fv(GLenum target, const GLfloat * v) {
    PACKED_void_GLenum_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLfloat___GENPT__;
    packed_data->func = glMultiTexCoord4fv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord4i
static inline void push_glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q) {
    PACKED_void_GLenum_GLint_GLint_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLint_GLint_GLint));
    packed_data->format = FORMAT_void_GLenum_GLint_GLint_GLint_GLint;
    packed_data->func = glMultiTexCoord4i;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    packed_data->args.a5 = q;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord4iv
static inline void push_glMultiTexCoord4iv(GLenum target, const GLint * v) {
    PACKED_void_GLenum_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLint___GENPT__;
    packed_data->func = glMultiTexCoord4iv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord4s
static inline void push_glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) {
    PACKED_void_GLenum_GLshort_GLshort_GLshort_GLshort *packed_data = malloc(sizeof(PACKED_void_GLenum_GLshort_GLshort_GLshort_GLshort));
    packed_data->format = FORMAT_void_GLenum_GLshort_GLshort_GLshort_GLshort;
    packed_data->func = glMultiTexCoord4s;
    packed_data->args.a1 = target;
    packed_data->args.a2 = s;
    packed_data->args.a3 = t;
    packed_data->args.a4 = r;
    packed_data->args.a5 = q;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glMultiTexCoord4sv
static inline void push_glMultiTexCoord4sv(GLenum target, const GLshort * v) {
    PACKED_void_GLenum_const_GLshort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLshort___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLshort___GENPT__;
    packed_data->func = glMultiTexCoord4sv;
    packed_data->args.a1 = target;
    packed_data->args.a2 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glNewList
static inline void push_glNewList(GLuint list, GLenum mode) {
    PACKED_void_GLuint_GLenum *packed_data = malloc(sizeof(PACKED_void_GLuint_GLenum));
    packed_data->format = FORMAT_void_GLuint_GLenum;
    packed_data->func = glNewList;
    packed_data->args.a1 = list;
    packed_data->args.a2 = mode;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glNormal3b
static inline void push_glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz) {
    PACKED_void_GLbyte_GLbyte_GLbyte *packed_data = malloc(sizeof(PACKED_void_GLbyte_GLbyte_GLbyte));
    packed_data->format = FORMAT_void_GLbyte_GLbyte_GLbyte;
    packed_data->func = glNormal3b;
    packed_data->args.a1 = nx;
    packed_data->args.a2 = ny;
    packed_data->args.a3 = nz;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glNormal3bv
static inline void push_glNormal3bv(const GLbyte * v) {
    PACKED_void_const_GLbyte___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLbyte___GENPT__));
    packed_data->format = FORMAT_void_const_GLbyte___GENPT__;
    packed_data->func = glNormal3bv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glNormal3d
static inline void push_glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz) {
    PACKED_void_GLdouble_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLdouble_GLdouble_GLdouble;
    packed_data->func = glNormal3d;
    packed_data->args.a1 = nx;
    packed_data->args.a2 = ny;
    packed_data->args.a3 = nz;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glNormal3dv
static inline void push_glNormal3dv(const GLdouble * v) {
    PACKED_void_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_const_GLdouble___GENPT__;
    packed_data->func = glNormal3dv;
    packed_data->args.a1 = v;
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
#ifndef direct_glNormal3fv
static inline void push_glNormal3fv(const GLfloat * v) {
    PACKED_void_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_const_GLfloat___GENPT__;
    packed_data->func = glNormal3fv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glNormal3i
static inline void push_glNormal3i(GLint nx, GLint ny, GLint nz) {
    PACKED_void_GLint_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLint_GLint_GLint));
    packed_data->format = FORMAT_void_GLint_GLint_GLint;
    packed_data->func = glNormal3i;
    packed_data->args.a1 = nx;
    packed_data->args.a2 = ny;
    packed_data->args.a3 = nz;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glNormal3iv
static inline void push_glNormal3iv(const GLint * v) {
    PACKED_void_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_const_GLint___GENPT__;
    packed_data->func = glNormal3iv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glNormal3s
static inline void push_glNormal3s(GLshort nx, GLshort ny, GLshort nz) {
    PACKED_void_GLshort_GLshort_GLshort *packed_data = malloc(sizeof(PACKED_void_GLshort_GLshort_GLshort));
    packed_data->format = FORMAT_void_GLshort_GLshort_GLshort;
    packed_data->func = glNormal3s;
    packed_data->args.a1 = nx;
    packed_data->args.a2 = ny;
    packed_data->args.a3 = nz;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glNormal3sv
static inline void push_glNormal3sv(const GLshort * v) {
    PACKED_void_const_GLshort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLshort___GENPT__));
    packed_data->format = FORMAT_void_const_GLshort___GENPT__;
    packed_data->func = glNormal3sv;
    packed_data->args.a1 = v;
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
#ifndef direct_glOrtho
static inline void push_glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
    PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble;
    packed_data->func = glOrtho;
    packed_data->args.a1 = left;
    packed_data->args.a2 = right;
    packed_data->args.a3 = bottom;
    packed_data->args.a4 = top;
    packed_data->args.a5 = zNear;
    packed_data->args.a6 = zFar;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glPassThrough
static inline void push_glPassThrough(GLfloat token) {
    PACKED_void_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat));
    packed_data->format = FORMAT_void_GLfloat;
    packed_data->func = glPassThrough;
    packed_data->args.a1 = token;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glPixelMapfv
static inline void push_glPixelMapfv(GLenum map, GLsizei mapsize, const GLfloat * values) {
    PACKED_void_GLenum_GLsizei_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLsizei_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLsizei_const_GLfloat___GENPT__;
    packed_data->func = glPixelMapfv;
    packed_data->args.a1 = map;
    packed_data->args.a2 = mapsize;
    packed_data->args.a3 = values;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glPixelMapuiv
static inline void push_glPixelMapuiv(GLenum map, GLsizei mapsize, const GLuint * values) {
    PACKED_void_GLenum_GLsizei_const_GLuint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLsizei_const_GLuint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLsizei_const_GLuint___GENPT__;
    packed_data->func = glPixelMapuiv;
    packed_data->args.a1 = map;
    packed_data->args.a2 = mapsize;
    packed_data->args.a3 = values;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glPixelMapusv
static inline void push_glPixelMapusv(GLenum map, GLsizei mapsize, const GLushort * values) {
    PACKED_void_GLenum_GLsizei_const_GLushort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLsizei_const_GLushort___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLsizei_const_GLushort___GENPT__;
    packed_data->func = glPixelMapusv;
    packed_data->args.a1 = map;
    packed_data->args.a2 = mapsize;
    packed_data->args.a3 = values;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glPixelStoref
static inline void push_glPixelStoref(GLenum pname, GLfloat param) {
    PACKED_void_GLenum_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLenum_GLfloat));
    packed_data->format = FORMAT_void_GLenum_GLfloat;
    packed_data->func = glPixelStoref;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
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
#ifndef direct_glPixelTransferf
static inline void push_glPixelTransferf(GLenum pname, GLfloat param) {
    PACKED_void_GLenum_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLenum_GLfloat));
    packed_data->format = FORMAT_void_GLenum_GLfloat;
    packed_data->func = glPixelTransferf;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glPixelTransferi
static inline void push_glPixelTransferi(GLenum pname, GLint param) {
    PACKED_void_GLenum_GLint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint));
    packed_data->format = FORMAT_void_GLenum_GLint;
    packed_data->func = glPixelTransferi;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glPixelZoom
static inline void push_glPixelZoom(GLfloat xfactor, GLfloat yfactor) {
    PACKED_void_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat;
    packed_data->func = glPixelZoom;
    packed_data->args.a1 = xfactor;
    packed_data->args.a2 = yfactor;
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
#ifndef direct_glPointParameteri
static inline void push_glPointParameteri(GLenum pname, GLint param) {
    PACKED_void_GLenum_GLint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint));
    packed_data->format = FORMAT_void_GLenum_GLint;
    packed_data->func = glPointParameteri;
    packed_data->args.a1 = pname;
    packed_data->args.a2 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glPointParameteriv
static inline void push_glPointParameteriv(GLenum pname, const GLint * params) {
    PACKED_void_GLenum_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_const_GLint___GENPT__;
    packed_data->func = glPointParameteriv;
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
#ifndef direct_glPolygonMode
static inline void push_glPolygonMode(GLenum face, GLenum mode) {
    PACKED_void_GLenum_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum));
    packed_data->format = FORMAT_void_GLenum_GLenum;
    packed_data->func = glPolygonMode;
    packed_data->args.a1 = face;
    packed_data->args.a2 = mode;
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
#ifndef direct_glPolygonStipple
static inline void push_glPolygonStipple(const GLubyte * mask) {
    PACKED_void_const_GLubyte___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLubyte___GENPT__));
    packed_data->format = FORMAT_void_const_GLubyte___GENPT__;
    packed_data->func = glPolygonStipple;
    packed_data->args.a1 = mask;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glPopAttrib
static inline void push_glPopAttrib() {
    PACKED_void *packed_data = malloc(sizeof(PACKED_void));
    packed_data->format = FORMAT_void;
    packed_data->func = glPopAttrib;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glPopClientAttrib
static inline void push_glPopClientAttrib() {
    PACKED_void *packed_data = malloc(sizeof(PACKED_void));
    packed_data->format = FORMAT_void;
    packed_data->func = glPopClientAttrib;
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
#ifndef direct_glPopName
static inline void push_glPopName() {
    PACKED_void *packed_data = malloc(sizeof(PACKED_void));
    packed_data->format = FORMAT_void;
    packed_data->func = glPopName;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glPrioritizeTextures
static inline void push_glPrioritizeTextures(GLsizei n, const GLuint * textures, const GLfloat * priorities) {
    PACKED_void_GLsizei_const_GLuint___GENPT___const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLsizei_const_GLuint___GENPT___const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLsizei_const_GLuint___GENPT___const_GLfloat___GENPT__;
    packed_data->func = glPrioritizeTextures;
    packed_data->args.a1 = n;
    packed_data->args.a2 = textures;
    packed_data->args.a3 = priorities;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glPushAttrib
static inline void push_glPushAttrib(GLbitfield mask) {
    PACKED_void_GLbitfield *packed_data = malloc(sizeof(PACKED_void_GLbitfield));
    packed_data->format = FORMAT_void_GLbitfield;
    packed_data->func = glPushAttrib;
    packed_data->args.a1 = mask;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glPushClientAttrib
static inline void push_glPushClientAttrib(GLbitfield mask) {
    PACKED_void_GLbitfield *packed_data = malloc(sizeof(PACKED_void_GLbitfield));
    packed_data->format = FORMAT_void_GLbitfield;
    packed_data->func = glPushClientAttrib;
    packed_data->args.a1 = mask;
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
#ifndef direct_glPushName
static inline void push_glPushName(GLuint name) {
    PACKED_void_GLuint *packed_data = malloc(sizeof(PACKED_void_GLuint));
    packed_data->format = FORMAT_void_GLuint;
    packed_data->func = glPushName;
    packed_data->args.a1 = name;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRasterPos2d
static inline void push_glRasterPos2d(GLdouble x, GLdouble y) {
    PACKED_void_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLdouble_GLdouble;
    packed_data->func = glRasterPos2d;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRasterPos2dv
static inline void push_glRasterPos2dv(const GLdouble * v) {
    PACKED_void_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_const_GLdouble___GENPT__;
    packed_data->func = glRasterPos2dv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRasterPos2f
static inline void push_glRasterPos2f(GLfloat x, GLfloat y) {
    PACKED_void_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat;
    packed_data->func = glRasterPos2f;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRasterPos2fv
static inline void push_glRasterPos2fv(const GLfloat * v) {
    PACKED_void_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_const_GLfloat___GENPT__;
    packed_data->func = glRasterPos2fv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRasterPos2i
static inline void push_glRasterPos2i(GLint x, GLint y) {
    PACKED_void_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLint_GLint));
    packed_data->format = FORMAT_void_GLint_GLint;
    packed_data->func = glRasterPos2i;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRasterPos2iv
static inline void push_glRasterPos2iv(const GLint * v) {
    PACKED_void_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_const_GLint___GENPT__;
    packed_data->func = glRasterPos2iv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRasterPos2s
static inline void push_glRasterPos2s(GLshort x, GLshort y) {
    PACKED_void_GLshort_GLshort *packed_data = malloc(sizeof(PACKED_void_GLshort_GLshort));
    packed_data->format = FORMAT_void_GLshort_GLshort;
    packed_data->func = glRasterPos2s;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRasterPos2sv
static inline void push_glRasterPos2sv(const GLshort * v) {
    PACKED_void_const_GLshort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLshort___GENPT__));
    packed_data->format = FORMAT_void_const_GLshort___GENPT__;
    packed_data->func = glRasterPos2sv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRasterPos3d
static inline void push_glRasterPos3d(GLdouble x, GLdouble y, GLdouble z) {
    PACKED_void_GLdouble_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLdouble_GLdouble_GLdouble;
    packed_data->func = glRasterPos3d;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRasterPos3dv
static inline void push_glRasterPos3dv(const GLdouble * v) {
    PACKED_void_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_const_GLdouble___GENPT__;
    packed_data->func = glRasterPos3dv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRasterPos3f
static inline void push_glRasterPos3f(GLfloat x, GLfloat y, GLfloat z) {
    PACKED_void_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat_GLfloat;
    packed_data->func = glRasterPos3f;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRasterPos3fv
static inline void push_glRasterPos3fv(const GLfloat * v) {
    PACKED_void_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_const_GLfloat___GENPT__;
    packed_data->func = glRasterPos3fv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRasterPos3i
static inline void push_glRasterPos3i(GLint x, GLint y, GLint z) {
    PACKED_void_GLint_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLint_GLint_GLint));
    packed_data->format = FORMAT_void_GLint_GLint_GLint;
    packed_data->func = glRasterPos3i;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRasterPos3iv
static inline void push_glRasterPos3iv(const GLint * v) {
    PACKED_void_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_const_GLint___GENPT__;
    packed_data->func = glRasterPos3iv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRasterPos3s
static inline void push_glRasterPos3s(GLshort x, GLshort y, GLshort z) {
    PACKED_void_GLshort_GLshort_GLshort *packed_data = malloc(sizeof(PACKED_void_GLshort_GLshort_GLshort));
    packed_data->format = FORMAT_void_GLshort_GLshort_GLshort;
    packed_data->func = glRasterPos3s;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRasterPos3sv
static inline void push_glRasterPos3sv(const GLshort * v) {
    PACKED_void_const_GLshort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLshort___GENPT__));
    packed_data->format = FORMAT_void_const_GLshort___GENPT__;
    packed_data->func = glRasterPos3sv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRasterPos4d
static inline void push_glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLdouble_GLdouble_GLdouble_GLdouble;
    packed_data->func = glRasterPos4d;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRasterPos4dv
static inline void push_glRasterPos4dv(const GLdouble * v) {
    PACKED_void_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_const_GLdouble___GENPT__;
    packed_data->func = glRasterPos4dv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRasterPos4f
static inline void push_glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat;
    packed_data->func = glRasterPos4f;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRasterPos4fv
static inline void push_glRasterPos4fv(const GLfloat * v) {
    PACKED_void_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_const_GLfloat___GENPT__;
    packed_data->func = glRasterPos4fv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRasterPos4i
static inline void push_glRasterPos4i(GLint x, GLint y, GLint z, GLint w) {
    PACKED_void_GLint_GLint_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLint_GLint_GLint_GLint));
    packed_data->format = FORMAT_void_GLint_GLint_GLint_GLint;
    packed_data->func = glRasterPos4i;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRasterPos4iv
static inline void push_glRasterPos4iv(const GLint * v) {
    PACKED_void_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_const_GLint___GENPT__;
    packed_data->func = glRasterPos4iv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRasterPos4s
static inline void push_glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w) {
    PACKED_void_GLshort_GLshort_GLshort_GLshort *packed_data = malloc(sizeof(PACKED_void_GLshort_GLshort_GLshort_GLshort));
    packed_data->format = FORMAT_void_GLshort_GLshort_GLshort_GLshort;
    packed_data->func = glRasterPos4s;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRasterPos4sv
static inline void push_glRasterPos4sv(const GLshort * v) {
    PACKED_void_const_GLshort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLshort___GENPT__));
    packed_data->format = FORMAT_void_const_GLshort___GENPT__;
    packed_data->func = glRasterPos4sv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glReadBuffer
static inline void push_glReadBuffer(GLenum mode) {
    PACKED_void_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum));
    packed_data->format = FORMAT_void_GLenum;
    packed_data->func = glReadBuffer;
    packed_data->args.a1 = mode;
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
#ifndef direct_glRectd
static inline void push_glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) {
    PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLdouble_GLdouble_GLdouble_GLdouble;
    packed_data->func = glRectd;
    packed_data->args.a1 = x1;
    packed_data->args.a2 = y1;
    packed_data->args.a3 = x2;
    packed_data->args.a4 = y2;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRectdv
static inline void push_glRectdv(const GLdouble * v1, const GLdouble * v2) {
    PACKED_void_const_GLdouble___GENPT___const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLdouble___GENPT___const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_const_GLdouble___GENPT___const_GLdouble___GENPT__;
    packed_data->func = glRectdv;
    packed_data->args.a1 = v1;
    packed_data->args.a2 = v2;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRectf
static inline void push_glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
    PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat;
    packed_data->func = glRectf;
    packed_data->args.a1 = x1;
    packed_data->args.a2 = y1;
    packed_data->args.a3 = x2;
    packed_data->args.a4 = y2;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRectfv
static inline void push_glRectfv(const GLfloat * v1, const GLfloat * v2) {
    PACKED_void_const_GLfloat___GENPT___const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT___const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_const_GLfloat___GENPT___const_GLfloat___GENPT__;
    packed_data->func = glRectfv;
    packed_data->args.a1 = v1;
    packed_data->args.a2 = v2;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRecti
static inline void push_glRecti(GLint x1, GLint y1, GLint x2, GLint y2) {
    PACKED_void_GLint_GLint_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLint_GLint_GLint_GLint));
    packed_data->format = FORMAT_void_GLint_GLint_GLint_GLint;
    packed_data->func = glRecti;
    packed_data->args.a1 = x1;
    packed_data->args.a2 = y1;
    packed_data->args.a3 = x2;
    packed_data->args.a4 = y2;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRectiv
static inline void push_glRectiv(const GLint * v1, const GLint * v2) {
    PACKED_void_const_GLint___GENPT___const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLint___GENPT___const_GLint___GENPT__));
    packed_data->format = FORMAT_void_const_GLint___GENPT___const_GLint___GENPT__;
    packed_data->func = glRectiv;
    packed_data->args.a1 = v1;
    packed_data->args.a2 = v2;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRects
static inline void push_glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2) {
    PACKED_void_GLshort_GLshort_GLshort_GLshort *packed_data = malloc(sizeof(PACKED_void_GLshort_GLshort_GLshort_GLshort));
    packed_data->format = FORMAT_void_GLshort_GLshort_GLshort_GLshort;
    packed_data->func = glRects;
    packed_data->args.a1 = x1;
    packed_data->args.a2 = y1;
    packed_data->args.a3 = x2;
    packed_data->args.a4 = y2;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRectsv
static inline void push_glRectsv(const GLshort * v1, const GLshort * v2) {
    PACKED_void_const_GLshort___GENPT___const_GLshort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLshort___GENPT___const_GLshort___GENPT__));
    packed_data->format = FORMAT_void_const_GLshort___GENPT___const_GLshort___GENPT__;
    packed_data->func = glRectsv;
    packed_data->args.a1 = v1;
    packed_data->args.a2 = v2;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRenderMode
static inline void push_glRenderMode(GLenum mode) {
    PACKED_GLint_GLenum *packed_data = malloc(sizeof(PACKED_GLint_GLenum));
    packed_data->format = FORMAT_GLint_GLenum;
    packed_data->func = glRenderMode;
    packed_data->args.a1 = mode;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glResetHistogram
static inline void push_glResetHistogram(GLenum target) {
    PACKED_void_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum));
    packed_data->format = FORMAT_void_GLenum;
    packed_data->func = glResetHistogram;
    packed_data->args.a1 = target;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glResetMinmax
static inline void push_glResetMinmax(GLenum target) {
    PACKED_void_GLenum *packed_data = malloc(sizeof(PACKED_void_GLenum));
    packed_data->format = FORMAT_void_GLenum;
    packed_data->func = glResetMinmax;
    packed_data->args.a1 = target;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glRotated
static inline void push_glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
    PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLdouble_GLdouble_GLdouble_GLdouble;
    packed_data->func = glRotated;
    packed_data->args.a1 = angle;
    packed_data->args.a2 = x;
    packed_data->args.a3 = y;
    packed_data->args.a4 = z;
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
#ifndef direct_glSampleCoverage
static inline void push_glSampleCoverage(GLfloat value, GLboolean invert) {
    PACKED_void_GLfloat_GLboolean *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLboolean));
    packed_data->format = FORMAT_void_GLfloat_GLboolean;
    packed_data->func = glSampleCoverage;
    packed_data->args.a1 = value;
    packed_data->args.a2 = invert;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glScaled
static inline void push_glScaled(GLdouble x, GLdouble y, GLdouble z) {
    PACKED_void_GLdouble_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLdouble_GLdouble_GLdouble;
    packed_data->func = glScaled;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
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
#ifndef direct_glSecondaryColor3b
static inline void push_glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue) {
    PACKED_void_GLbyte_GLbyte_GLbyte *packed_data = malloc(sizeof(PACKED_void_GLbyte_GLbyte_GLbyte));
    packed_data->format = FORMAT_void_GLbyte_GLbyte_GLbyte;
    packed_data->func = glSecondaryColor3b;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glSecondaryColor3bv
static inline void push_glSecondaryColor3bv(const GLbyte * v) {
    PACKED_void_const_GLbyte___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLbyte___GENPT__));
    packed_data->format = FORMAT_void_const_GLbyte___GENPT__;
    packed_data->func = glSecondaryColor3bv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glSecondaryColor3d
static inline void push_glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue) {
    PACKED_void_GLdouble_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLdouble_GLdouble_GLdouble;
    packed_data->func = glSecondaryColor3d;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glSecondaryColor3dv
static inline void push_glSecondaryColor3dv(const GLdouble * v) {
    PACKED_void_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_const_GLdouble___GENPT__;
    packed_data->func = glSecondaryColor3dv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glSecondaryColor3f
static inline void push_glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue) {
    PACKED_void_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat_GLfloat;
    packed_data->func = glSecondaryColor3f;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glSecondaryColor3fv
static inline void push_glSecondaryColor3fv(const GLfloat * v) {
    PACKED_void_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_const_GLfloat___GENPT__;
    packed_data->func = glSecondaryColor3fv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glSecondaryColor3i
static inline void push_glSecondaryColor3i(GLint red, GLint green, GLint blue) {
    PACKED_void_GLint_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLint_GLint_GLint));
    packed_data->format = FORMAT_void_GLint_GLint_GLint;
    packed_data->func = glSecondaryColor3i;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glSecondaryColor3iv
static inline void push_glSecondaryColor3iv(const GLint * v) {
    PACKED_void_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_const_GLint___GENPT__;
    packed_data->func = glSecondaryColor3iv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glSecondaryColor3s
static inline void push_glSecondaryColor3s(GLshort red, GLshort green, GLshort blue) {
    PACKED_void_GLshort_GLshort_GLshort *packed_data = malloc(sizeof(PACKED_void_GLshort_GLshort_GLshort));
    packed_data->format = FORMAT_void_GLshort_GLshort_GLshort;
    packed_data->func = glSecondaryColor3s;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glSecondaryColor3sv
static inline void push_glSecondaryColor3sv(const GLshort * v) {
    PACKED_void_const_GLshort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLshort___GENPT__));
    packed_data->format = FORMAT_void_const_GLshort___GENPT__;
    packed_data->func = glSecondaryColor3sv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glSecondaryColor3ub
static inline void push_glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue) {
    PACKED_void_GLubyte_GLubyte_GLubyte *packed_data = malloc(sizeof(PACKED_void_GLubyte_GLubyte_GLubyte));
    packed_data->format = FORMAT_void_GLubyte_GLubyte_GLubyte;
    packed_data->func = glSecondaryColor3ub;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glSecondaryColor3ubv
static inline void push_glSecondaryColor3ubv(const GLubyte * v) {
    PACKED_void_const_GLubyte___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLubyte___GENPT__));
    packed_data->format = FORMAT_void_const_GLubyte___GENPT__;
    packed_data->func = glSecondaryColor3ubv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glSecondaryColor3ui
static inline void push_glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue) {
    PACKED_void_GLuint_GLuint_GLuint *packed_data = malloc(sizeof(PACKED_void_GLuint_GLuint_GLuint));
    packed_data->format = FORMAT_void_GLuint_GLuint_GLuint;
    packed_data->func = glSecondaryColor3ui;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glSecondaryColor3uiv
static inline void push_glSecondaryColor3uiv(const GLuint * v) {
    PACKED_void_const_GLuint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLuint___GENPT__));
    packed_data->format = FORMAT_void_const_GLuint___GENPT__;
    packed_data->func = glSecondaryColor3uiv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glSecondaryColor3us
static inline void push_glSecondaryColor3us(GLushort red, GLushort green, GLushort blue) {
    PACKED_void_GLushort_GLushort_GLushort *packed_data = malloc(sizeof(PACKED_void_GLushort_GLushort_GLushort));
    packed_data->format = FORMAT_void_GLushort_GLushort_GLushort;
    packed_data->func = glSecondaryColor3us;
    packed_data->args.a1 = red;
    packed_data->args.a2 = green;
    packed_data->args.a3 = blue;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glSecondaryColor3usv
static inline void push_glSecondaryColor3usv(const GLushort * v) {
    PACKED_void_const_GLushort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLushort___GENPT__));
    packed_data->format = FORMAT_void_const_GLushort___GENPT__;
    packed_data->func = glSecondaryColor3usv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glSecondaryColorPointer
static inline void push_glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid * pointer) {
    PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLint_GLenum_GLsizei_const_GLvoid___GENPT__;
    packed_data->func = glSecondaryColorPointer;
    packed_data->args.a1 = size;
    packed_data->args.a2 = type;
    packed_data->args.a3 = stride;
    packed_data->args.a4 = pointer;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glSelectBuffer
static inline void push_glSelectBuffer(GLsizei size, GLuint * buffer) {
    PACKED_void_GLsizei_GLuint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLsizei_GLuint___GENPT__));
    packed_data->format = FORMAT_void_GLsizei_GLuint___GENPT__;
    packed_data->func = glSelectBuffer;
    packed_data->args.a1 = size;
    packed_data->args.a2 = buffer;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glSeparableFilter2D
static inline void push_glSeparableFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * row, const GLvoid * column) {
    PACKED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT___const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT___const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT___const_GLvoid___GENPT__;
    packed_data->func = glSeparableFilter2D;
    packed_data->args.a1 = target;
    packed_data->args.a2 = internalformat;
    packed_data->args.a3 = width;
    packed_data->args.a4 = height;
    packed_data->args.a5 = format;
    packed_data->args.a6 = type;
    packed_data->args.a7 = row;
    packed_data->args.a8 = column;
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
#ifndef direct_glTexCoord1d
static inline void push_glTexCoord1d(GLdouble s) {
    PACKED_void_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble));
    packed_data->format = FORMAT_void_GLdouble;
    packed_data->func = glTexCoord1d;
    packed_data->args.a1 = s;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord1dv
static inline void push_glTexCoord1dv(const GLdouble * v) {
    PACKED_void_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_const_GLdouble___GENPT__;
    packed_data->func = glTexCoord1dv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord1f
static inline void push_glTexCoord1f(GLfloat s) {
    PACKED_void_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat));
    packed_data->format = FORMAT_void_GLfloat;
    packed_data->func = glTexCoord1f;
    packed_data->args.a1 = s;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord1fv
static inline void push_glTexCoord1fv(const GLfloat * v) {
    PACKED_void_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_const_GLfloat___GENPT__;
    packed_data->func = glTexCoord1fv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord1i
static inline void push_glTexCoord1i(GLint s) {
    PACKED_void_GLint *packed_data = malloc(sizeof(PACKED_void_GLint));
    packed_data->format = FORMAT_void_GLint;
    packed_data->func = glTexCoord1i;
    packed_data->args.a1 = s;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord1iv
static inline void push_glTexCoord1iv(const GLint * v) {
    PACKED_void_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_const_GLint___GENPT__;
    packed_data->func = glTexCoord1iv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord1s
static inline void push_glTexCoord1s(GLshort s) {
    PACKED_void_GLshort *packed_data = malloc(sizeof(PACKED_void_GLshort));
    packed_data->format = FORMAT_void_GLshort;
    packed_data->func = glTexCoord1s;
    packed_data->args.a1 = s;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord1sv
static inline void push_glTexCoord1sv(const GLshort * v) {
    PACKED_void_const_GLshort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLshort___GENPT__));
    packed_data->format = FORMAT_void_const_GLshort___GENPT__;
    packed_data->func = glTexCoord1sv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord2d
static inline void push_glTexCoord2d(GLdouble s, GLdouble t) {
    PACKED_void_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLdouble_GLdouble;
    packed_data->func = glTexCoord2d;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord2dv
static inline void push_glTexCoord2dv(const GLdouble * v) {
    PACKED_void_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_const_GLdouble___GENPT__;
    packed_data->func = glTexCoord2dv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord2f
static inline void push_glTexCoord2f(GLfloat s, GLfloat t) {
    PACKED_void_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat;
    packed_data->func = glTexCoord2f;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord2fv
static inline void push_glTexCoord2fv(const GLfloat * v) {
    PACKED_void_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_const_GLfloat___GENPT__;
    packed_data->func = glTexCoord2fv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord2i
static inline void push_glTexCoord2i(GLint s, GLint t) {
    PACKED_void_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLint_GLint));
    packed_data->format = FORMAT_void_GLint_GLint;
    packed_data->func = glTexCoord2i;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord2iv
static inline void push_glTexCoord2iv(const GLint * v) {
    PACKED_void_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_const_GLint___GENPT__;
    packed_data->func = glTexCoord2iv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord2s
static inline void push_glTexCoord2s(GLshort s, GLshort t) {
    PACKED_void_GLshort_GLshort *packed_data = malloc(sizeof(PACKED_void_GLshort_GLshort));
    packed_data->format = FORMAT_void_GLshort_GLshort;
    packed_data->func = glTexCoord2s;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord2sv
static inline void push_glTexCoord2sv(const GLshort * v) {
    PACKED_void_const_GLshort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLshort___GENPT__));
    packed_data->format = FORMAT_void_const_GLshort___GENPT__;
    packed_data->func = glTexCoord2sv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord3d
static inline void push_glTexCoord3d(GLdouble s, GLdouble t, GLdouble r) {
    PACKED_void_GLdouble_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLdouble_GLdouble_GLdouble;
    packed_data->func = glTexCoord3d;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord3dv
static inline void push_glTexCoord3dv(const GLdouble * v) {
    PACKED_void_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_const_GLdouble___GENPT__;
    packed_data->func = glTexCoord3dv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord3f
static inline void push_glTexCoord3f(GLfloat s, GLfloat t, GLfloat r) {
    PACKED_void_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat_GLfloat;
    packed_data->func = glTexCoord3f;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord3fv
static inline void push_glTexCoord3fv(const GLfloat * v) {
    PACKED_void_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_const_GLfloat___GENPT__;
    packed_data->func = glTexCoord3fv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord3i
static inline void push_glTexCoord3i(GLint s, GLint t, GLint r) {
    PACKED_void_GLint_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLint_GLint_GLint));
    packed_data->format = FORMAT_void_GLint_GLint_GLint;
    packed_data->func = glTexCoord3i;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord3iv
static inline void push_glTexCoord3iv(const GLint * v) {
    PACKED_void_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_const_GLint___GENPT__;
    packed_data->func = glTexCoord3iv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord3s
static inline void push_glTexCoord3s(GLshort s, GLshort t, GLshort r) {
    PACKED_void_GLshort_GLshort_GLshort *packed_data = malloc(sizeof(PACKED_void_GLshort_GLshort_GLshort));
    packed_data->format = FORMAT_void_GLshort_GLshort_GLshort;
    packed_data->func = glTexCoord3s;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord3sv
static inline void push_glTexCoord3sv(const GLshort * v) {
    PACKED_void_const_GLshort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLshort___GENPT__));
    packed_data->format = FORMAT_void_const_GLshort___GENPT__;
    packed_data->func = glTexCoord3sv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord4d
static inline void push_glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
    PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLdouble_GLdouble_GLdouble_GLdouble;
    packed_data->func = glTexCoord4d;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    packed_data->args.a4 = q;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord4dv
static inline void push_glTexCoord4dv(const GLdouble * v) {
    PACKED_void_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_const_GLdouble___GENPT__;
    packed_data->func = glTexCoord4dv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord4f
static inline void push_glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat;
    packed_data->func = glTexCoord4f;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    packed_data->args.a4 = q;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord4fv
static inline void push_glTexCoord4fv(const GLfloat * v) {
    PACKED_void_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_const_GLfloat___GENPT__;
    packed_data->func = glTexCoord4fv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord4i
static inline void push_glTexCoord4i(GLint s, GLint t, GLint r, GLint q) {
    PACKED_void_GLint_GLint_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLint_GLint_GLint_GLint));
    packed_data->format = FORMAT_void_GLint_GLint_GLint_GLint;
    packed_data->func = glTexCoord4i;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    packed_data->args.a4 = q;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord4iv
static inline void push_glTexCoord4iv(const GLint * v) {
    PACKED_void_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_const_GLint___GENPT__;
    packed_data->func = glTexCoord4iv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord4s
static inline void push_glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q) {
    PACKED_void_GLshort_GLshort_GLshort_GLshort *packed_data = malloc(sizeof(PACKED_void_GLshort_GLshort_GLshort_GLshort));
    packed_data->format = FORMAT_void_GLshort_GLshort_GLshort_GLshort;
    packed_data->func = glTexCoord4s;
    packed_data->args.a1 = s;
    packed_data->args.a2 = t;
    packed_data->args.a3 = r;
    packed_data->args.a4 = q;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexCoord4sv
static inline void push_glTexCoord4sv(const GLshort * v) {
    PACKED_void_const_GLshort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLshort___GENPT__));
    packed_data->format = FORMAT_void_const_GLshort___GENPT__;
    packed_data->func = glTexCoord4sv;
    packed_data->args.a1 = v;
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
#ifndef direct_glTexGend
static inline void push_glTexGend(GLenum coord, GLenum pname, GLdouble param) {
    PACKED_void_GLenum_GLenum_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLdouble));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLdouble;
    packed_data->func = glTexGend;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexGendv
static inline void push_glTexGendv(GLenum coord, GLenum pname, const GLdouble * params) {
    PACKED_void_GLenum_GLenum_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_const_GLdouble___GENPT__;
    packed_data->func = glTexGendv;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexGenf
static inline void push_glTexGenf(GLenum coord, GLenum pname, GLfloat param) {
    PACKED_void_GLenum_GLenum_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLfloat));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLfloat;
    packed_data->func = glTexGenf;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexGenfv
static inline void push_glTexGenfv(GLenum coord, GLenum pname, const GLfloat * params) {
    PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_const_GLfloat___GENPT__;
    packed_data->func = glTexGenfv;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexGeni
static inline void push_glTexGeni(GLenum coord, GLenum pname, GLint param) {
    PACKED_void_GLenum_GLenum_GLint *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_GLint));
    packed_data->format = FORMAT_void_GLenum_GLenum_GLint;
    packed_data->func = glTexGeni;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = param;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexGeniv
static inline void push_glTexGeniv(GLenum coord, GLenum pname, const GLint * params) {
    PACKED_void_GLenum_GLenum_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLenum_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLenum_const_GLint___GENPT__;
    packed_data->func = glTexGeniv;
    packed_data->args.a1 = coord;
    packed_data->args.a2 = pname;
    packed_data->args.a3 = params;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTexImage1D
static inline void push_glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid * pixels) {
    PACKED_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__;
    packed_data->func = glTexImage1D;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = internalformat;
    packed_data->args.a4 = width;
    packed_data->args.a5 = border;
    packed_data->args.a6 = format;
    packed_data->args.a7 = type;
    packed_data->args.a8 = pixels;
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
#ifndef direct_glTexImage3D
static inline void push_glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid * pixels) {
    PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_const_GLvoid___GENPT__;
    packed_data->func = glTexImage3D;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = internalformat;
    packed_data->args.a4 = width;
    packed_data->args.a5 = height;
    packed_data->args.a6 = depth;
    packed_data->args.a7 = border;
    packed_data->args.a8 = format;
    packed_data->args.a9 = type;
    packed_data->args.a10 = pixels;
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
#ifndef direct_glTexSubImage1D
static inline void push_glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid * pixels) {
    PACKED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
    packed_data->func = glTexSubImage1D;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = xoffset;
    packed_data->args.a4 = width;
    packed_data->args.a5 = format;
    packed_data->args.a6 = type;
    packed_data->args.a7 = pixels;
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
#ifndef direct_glTexSubImage3D
static inline void push_glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid * pixels) {
    PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__ *packed_data = malloc(sizeof(PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__));
    packed_data->format = FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_const_GLvoid___GENPT__;
    packed_data->func = glTexSubImage3D;
    packed_data->args.a1 = target;
    packed_data->args.a2 = level;
    packed_data->args.a3 = xoffset;
    packed_data->args.a4 = yoffset;
    packed_data->args.a5 = zoffset;
    packed_data->args.a6 = width;
    packed_data->args.a7 = height;
    packed_data->args.a8 = depth;
    packed_data->args.a9 = format;
    packed_data->args.a10 = type;
    packed_data->args.a11 = pixels;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glTranslated
static inline void push_glTranslated(GLdouble x, GLdouble y, GLdouble z) {
    PACKED_void_GLdouble_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLdouble_GLdouble_GLdouble;
    packed_data->func = glTranslated;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
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
#ifndef direct_glUnmapBuffer
static inline void push_glUnmapBuffer(GLenum target) {
    PACKED_GLboolean_GLenum *packed_data = malloc(sizeof(PACKED_GLboolean_GLenum));
    packed_data->format = FORMAT_GLboolean_GLenum;
    packed_data->func = glUnmapBuffer;
    packed_data->args.a1 = target;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertex2d
static inline void push_glVertex2d(GLdouble x, GLdouble y) {
    PACKED_void_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLdouble_GLdouble;
    packed_data->func = glVertex2d;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertex2dv
static inline void push_glVertex2dv(const GLdouble * v) {
    PACKED_void_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_const_GLdouble___GENPT__;
    packed_data->func = glVertex2dv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertex2f
static inline void push_glVertex2f(GLfloat x, GLfloat y) {
    PACKED_void_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat;
    packed_data->func = glVertex2f;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertex2fv
static inline void push_glVertex2fv(const GLfloat * v) {
    PACKED_void_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_const_GLfloat___GENPT__;
    packed_data->func = glVertex2fv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertex2i
static inline void push_glVertex2i(GLint x, GLint y) {
    PACKED_void_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLint_GLint));
    packed_data->format = FORMAT_void_GLint_GLint;
    packed_data->func = glVertex2i;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertex2iv
static inline void push_glVertex2iv(const GLint * v) {
    PACKED_void_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_const_GLint___GENPT__;
    packed_data->func = glVertex2iv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertex2s
static inline void push_glVertex2s(GLshort x, GLshort y) {
    PACKED_void_GLshort_GLshort *packed_data = malloc(sizeof(PACKED_void_GLshort_GLshort));
    packed_data->format = FORMAT_void_GLshort_GLshort;
    packed_data->func = glVertex2s;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertex2sv
static inline void push_glVertex2sv(const GLshort * v) {
    PACKED_void_const_GLshort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLshort___GENPT__));
    packed_data->format = FORMAT_void_const_GLshort___GENPT__;
    packed_data->func = glVertex2sv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertex3d
static inline void push_glVertex3d(GLdouble x, GLdouble y, GLdouble z) {
    PACKED_void_GLdouble_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLdouble_GLdouble_GLdouble;
    packed_data->func = glVertex3d;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertex3dv
static inline void push_glVertex3dv(const GLdouble * v) {
    PACKED_void_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_const_GLdouble___GENPT__;
    packed_data->func = glVertex3dv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertex3f
static inline void push_glVertex3f(GLfloat x, GLfloat y, GLfloat z) {
    PACKED_void_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat_GLfloat;
    packed_data->func = glVertex3f;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertex3fv
static inline void push_glVertex3fv(const GLfloat * v) {
    PACKED_void_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_const_GLfloat___GENPT__;
    packed_data->func = glVertex3fv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertex3i
static inline void push_glVertex3i(GLint x, GLint y, GLint z) {
    PACKED_void_GLint_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLint_GLint_GLint));
    packed_data->format = FORMAT_void_GLint_GLint_GLint;
    packed_data->func = glVertex3i;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertex3iv
static inline void push_glVertex3iv(const GLint * v) {
    PACKED_void_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_const_GLint___GENPT__;
    packed_data->func = glVertex3iv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertex3s
static inline void push_glVertex3s(GLshort x, GLshort y, GLshort z) {
    PACKED_void_GLshort_GLshort_GLshort *packed_data = malloc(sizeof(PACKED_void_GLshort_GLshort_GLshort));
    packed_data->format = FORMAT_void_GLshort_GLshort_GLshort;
    packed_data->func = glVertex3s;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertex3sv
static inline void push_glVertex3sv(const GLshort * v) {
    PACKED_void_const_GLshort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLshort___GENPT__));
    packed_data->format = FORMAT_void_const_GLshort___GENPT__;
    packed_data->func = glVertex3sv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertex4d
static inline void push_glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble_GLdouble_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLdouble_GLdouble_GLdouble_GLdouble;
    packed_data->func = glVertex4d;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertex4dv
static inline void push_glVertex4dv(const GLdouble * v) {
    PACKED_void_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_const_GLdouble___GENPT__;
    packed_data->func = glVertex4dv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertex4f
static inline void push_glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat;
    packed_data->func = glVertex4f;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertex4fv
static inline void push_glVertex4fv(const GLfloat * v) {
    PACKED_void_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_const_GLfloat___GENPT__;
    packed_data->func = glVertex4fv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertex4i
static inline void push_glVertex4i(GLint x, GLint y, GLint z, GLint w) {
    PACKED_void_GLint_GLint_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLint_GLint_GLint_GLint));
    packed_data->format = FORMAT_void_GLint_GLint_GLint_GLint;
    packed_data->func = glVertex4i;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertex4iv
static inline void push_glVertex4iv(const GLint * v) {
    PACKED_void_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_const_GLint___GENPT__;
    packed_data->func = glVertex4iv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertex4s
static inline void push_glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w) {
    PACKED_void_GLshort_GLshort_GLshort_GLshort *packed_data = malloc(sizeof(PACKED_void_GLshort_GLshort_GLshort_GLshort));
    packed_data->format = FORMAT_void_GLshort_GLshort_GLshort_GLshort;
    packed_data->func = glVertex4s;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    packed_data->args.a4 = w;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glVertex4sv
static inline void push_glVertex4sv(const GLshort * v) {
    PACKED_void_const_GLshort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLshort___GENPT__));
    packed_data->format = FORMAT_void_const_GLshort___GENPT__;
    packed_data->func = glVertex4sv;
    packed_data->args.a1 = v;
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
#ifndef direct_glWindowPos2d
static inline void push_glWindowPos2d(GLdouble x, GLdouble y) {
    PACKED_void_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLdouble_GLdouble;
    packed_data->func = glWindowPos2d;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glWindowPos2dv
static inline void push_glWindowPos2dv(const GLdouble * v) {
    PACKED_void_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_const_GLdouble___GENPT__;
    packed_data->func = glWindowPos2dv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glWindowPos2f
static inline void push_glWindowPos2f(GLfloat x, GLfloat y) {
    PACKED_void_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat;
    packed_data->func = glWindowPos2f;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glWindowPos2fv
static inline void push_glWindowPos2fv(const GLfloat * v) {
    PACKED_void_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_const_GLfloat___GENPT__;
    packed_data->func = glWindowPos2fv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glWindowPos2i
static inline void push_glWindowPos2i(GLint x, GLint y) {
    PACKED_void_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLint_GLint));
    packed_data->format = FORMAT_void_GLint_GLint;
    packed_data->func = glWindowPos2i;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glWindowPos2iv
static inline void push_glWindowPos2iv(const GLint * v) {
    PACKED_void_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_const_GLint___GENPT__;
    packed_data->func = glWindowPos2iv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glWindowPos2s
static inline void push_glWindowPos2s(GLshort x, GLshort y) {
    PACKED_void_GLshort_GLshort *packed_data = malloc(sizeof(PACKED_void_GLshort_GLshort));
    packed_data->format = FORMAT_void_GLshort_GLshort;
    packed_data->func = glWindowPos2s;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glWindowPos2sv
static inline void push_glWindowPos2sv(const GLshort * v) {
    PACKED_void_const_GLshort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLshort___GENPT__));
    packed_data->format = FORMAT_void_const_GLshort___GENPT__;
    packed_data->func = glWindowPos2sv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glWindowPos3d
static inline void push_glWindowPos3d(GLdouble x, GLdouble y, GLdouble z) {
    PACKED_void_GLdouble_GLdouble_GLdouble *packed_data = malloc(sizeof(PACKED_void_GLdouble_GLdouble_GLdouble));
    packed_data->format = FORMAT_void_GLdouble_GLdouble_GLdouble;
    packed_data->func = glWindowPos3d;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glWindowPos3dv
static inline void push_glWindowPos3dv(const GLdouble * v) {
    PACKED_void_const_GLdouble___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLdouble___GENPT__));
    packed_data->format = FORMAT_void_const_GLdouble___GENPT__;
    packed_data->func = glWindowPos3dv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glWindowPos3f
static inline void push_glWindowPos3f(GLfloat x, GLfloat y, GLfloat z) {
    PACKED_void_GLfloat_GLfloat_GLfloat *packed_data = malloc(sizeof(PACKED_void_GLfloat_GLfloat_GLfloat));
    packed_data->format = FORMAT_void_GLfloat_GLfloat_GLfloat;
    packed_data->func = glWindowPos3f;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glWindowPos3fv
static inline void push_glWindowPos3fv(const GLfloat * v) {
    PACKED_void_const_GLfloat___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLfloat___GENPT__));
    packed_data->format = FORMAT_void_const_GLfloat___GENPT__;
    packed_data->func = glWindowPos3fv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glWindowPos3i
static inline void push_glWindowPos3i(GLint x, GLint y, GLint z) {
    PACKED_void_GLint_GLint_GLint *packed_data = malloc(sizeof(PACKED_void_GLint_GLint_GLint));
    packed_data->format = FORMAT_void_GLint_GLint_GLint;
    packed_data->func = glWindowPos3i;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glWindowPos3iv
static inline void push_glWindowPos3iv(const GLint * v) {
    PACKED_void_const_GLint___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLint___GENPT__));
    packed_data->format = FORMAT_void_const_GLint___GENPT__;
    packed_data->func = glWindowPos3iv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glWindowPos3s
static inline void push_glWindowPos3s(GLshort x, GLshort y, GLshort z) {
    PACKED_void_GLshort_GLshort_GLshort *packed_data = malloc(sizeof(PACKED_void_GLshort_GLshort_GLshort));
    packed_data->format = FORMAT_void_GLshort_GLshort_GLshort;
    packed_data->func = glWindowPos3s;
    packed_data->args.a1 = x;
    packed_data->args.a2 = y;
    packed_data->args.a3 = z;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glWindowPos3sv
static inline void push_glWindowPos3sv(const GLshort * v) {
    PACKED_void_const_GLshort___GENPT__ *packed_data = malloc(sizeof(PACKED_void_const_GLshort___GENPT__));
    packed_data->format = FORMAT_void_const_GLshort___GENPT__;
    packed_data->func = glWindowPos3sv;
    packed_data->args.a1 = v;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXBindHyperpipeSGIX
static inline void push_glXBindHyperpipeSGIX(Display * dpy, int hpId) {
    PACKED_int_Display___GENPT___int *packed_data = malloc(sizeof(PACKED_int_Display___GENPT___int));
    packed_data->format = FORMAT_int_Display___GENPT___int;
    packed_data->func = glXBindHyperpipeSGIX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = hpId;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXBindSwapBarrierSGIX
static inline void push_glXBindSwapBarrierSGIX(uint32_t window, uint32_t barrier) {
    PACKED_void_uint32_t_uint32_t *packed_data = malloc(sizeof(PACKED_void_uint32_t_uint32_t));
    packed_data->format = FORMAT_void_uint32_t_uint32_t;
    packed_data->func = glXBindSwapBarrierSGIX;
    packed_data->args.a1 = window;
    packed_data->args.a2 = barrier;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXChangeDrawableAttributes
static inline void push_glXChangeDrawableAttributes(uint32_t drawable) {
    PACKED_void_uint32_t *packed_data = malloc(sizeof(PACKED_void_uint32_t));
    packed_data->format = FORMAT_void_uint32_t;
    packed_data->func = glXChangeDrawableAttributes;
    packed_data->args.a1 = drawable;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXChangeDrawableAttributesSGIX
static inline void push_glXChangeDrawableAttributesSGIX(uint32_t drawable) {
    PACKED_void_uint32_t *packed_data = malloc(sizeof(PACKED_void_uint32_t));
    packed_data->format = FORMAT_void_uint32_t;
    packed_data->func = glXChangeDrawableAttributesSGIX;
    packed_data->args.a1 = drawable;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXChooseFBConfig
static inline void push_glXChooseFBConfig(Display * dpy, int screen, const int * attrib_list, int * nelements) {
    PACKED_GLXFBConfig___GENPT___Display___GENPT___int_const_int___GENPT___int___GENPT__ *packed_data = malloc(sizeof(PACKED_GLXFBConfig___GENPT___Display___GENPT___int_const_int___GENPT___int___GENPT__));
    packed_data->format = FORMAT_GLXFBConfig___GENPT___Display___GENPT___int_const_int___GENPT___int___GENPT__;
    packed_data->func = glXChooseFBConfig;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = screen;
    packed_data->args.a3 = attrib_list;
    packed_data->args.a4 = nelements;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXChooseVisual
static inline void push_glXChooseVisual(Display * dpy, int screen, int * attribList) {
    PACKED_XVisualInfo___GENPT___Display___GENPT___int_int___GENPT__ *packed_data = malloc(sizeof(PACKED_XVisualInfo___GENPT___Display___GENPT___int_int___GENPT__));
    packed_data->format = FORMAT_XVisualInfo___GENPT___Display___GENPT___int_int___GENPT__;
    packed_data->func = glXChooseVisual;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = screen;
    packed_data->args.a3 = attribList;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXClientInfo
static inline void push_glXClientInfo() {
    PACKED_void *packed_data = malloc(sizeof(PACKED_void));
    packed_data->format = FORMAT_void;
    packed_data->func = glXClientInfo;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXCopyContext
static inline void push_glXCopyContext(Display * dpy, GLXContext src, GLXContext dst, unsigned long mask) {
    PACKED_void_Display___GENPT___GLXContext_GLXContext_unsigned_long *packed_data = malloc(sizeof(PACKED_void_Display___GENPT___GLXContext_GLXContext_unsigned_long));
    packed_data->format = FORMAT_void_Display___GENPT___GLXContext_GLXContext_unsigned_long;
    packed_data->func = glXCopyContext;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = src;
    packed_data->args.a3 = dst;
    packed_data->args.a4 = mask;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXCreateContext
static inline void push_glXCreateContext(Display * dpy, XVisualInfo * vis, GLXContext shareList, Bool direct) {
    PACKED_GLXContext_Display___GENPT___XVisualInfo___GENPT___GLXContext_Bool *packed_data = malloc(sizeof(PACKED_GLXContext_Display___GENPT___XVisualInfo___GENPT___GLXContext_Bool));
    packed_data->format = FORMAT_GLXContext_Display___GENPT___XVisualInfo___GENPT___GLXContext_Bool;
    packed_data->func = glXCreateContext;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = vis;
    packed_data->args.a3 = shareList;
    packed_data->args.a4 = direct;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXCreateContextWithConfigSGIX
static inline void push_glXCreateContextWithConfigSGIX(uint32_t gc_id, uint32_t screen, uint32_t config, uint32_t share_list) {
    PACKED_void_uint32_t_uint32_t_uint32_t_uint32_t *packed_data = malloc(sizeof(PACKED_void_uint32_t_uint32_t_uint32_t_uint32_t));
    packed_data->format = FORMAT_void_uint32_t_uint32_t_uint32_t_uint32_t;
    packed_data->func = glXCreateContextWithConfigSGIX;
    packed_data->args.a1 = gc_id;
    packed_data->args.a2 = screen;
    packed_data->args.a3 = config;
    packed_data->args.a4 = share_list;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXCreateGLXPbufferSGIX
static inline void push_glXCreateGLXPbufferSGIX(uint32_t config, uint32_t pbuffer) {
    PACKED_void_uint32_t_uint32_t *packed_data = malloc(sizeof(PACKED_void_uint32_t_uint32_t));
    packed_data->format = FORMAT_void_uint32_t_uint32_t;
    packed_data->func = glXCreateGLXPbufferSGIX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = pbuffer;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXCreateGLXPixmap
static inline void push_glXCreateGLXPixmap(Display * dpy, XVisualInfo * visual, Pixmap pixmap) {
    PACKED_GLXPixmap_Display___GENPT___XVisualInfo___GENPT___Pixmap *packed_data = malloc(sizeof(PACKED_GLXPixmap_Display___GENPT___XVisualInfo___GENPT___Pixmap));
    packed_data->format = FORMAT_GLXPixmap_Display___GENPT___XVisualInfo___GENPT___Pixmap;
    packed_data->func = glXCreateGLXPixmap;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = visual;
    packed_data->args.a3 = pixmap;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXCreateGLXPixmapWithConfigSGIX
static inline void push_glXCreateGLXPixmapWithConfigSGIX(uint32_t config, uint32_t pixmap, uint32_t glxpixmap) {
    PACKED_void_uint32_t_uint32_t_uint32_t *packed_data = malloc(sizeof(PACKED_void_uint32_t_uint32_t_uint32_t));
    packed_data->format = FORMAT_void_uint32_t_uint32_t_uint32_t;
    packed_data->func = glXCreateGLXPixmapWithConfigSGIX;
    packed_data->args.a1 = config;
    packed_data->args.a2 = pixmap;
    packed_data->args.a3 = glxpixmap;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXCreateGLXVideoSourceSGIX
static inline void push_glXCreateGLXVideoSourceSGIX(Display * dpy, uint32_t screen, uint32_t server, uint32_t path, uint32_t class, uint32_t node) {
    PACKED_void_Display___GENPT___uint32_t_uint32_t_uint32_t_uint32_t_uint32_t *packed_data = malloc(sizeof(PACKED_void_Display___GENPT___uint32_t_uint32_t_uint32_t_uint32_t_uint32_t));
    packed_data->format = FORMAT_void_Display___GENPT___uint32_t_uint32_t_uint32_t_uint32_t_uint32_t;
    packed_data->func = glXCreateGLXVideoSourceSGIX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = screen;
    packed_data->args.a3 = server;
    packed_data->args.a4 = path;
    packed_data->args.a5 = class;
    packed_data->args.a6 = node;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXCreateNewContext
static inline void push_glXCreateNewContext(Display * dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct) {
    PACKED_GLXContext_Display___GENPT___GLXFBConfig_int_GLXContext_Bool *packed_data = malloc(sizeof(PACKED_GLXContext_Display___GENPT___GLXFBConfig_int_GLXContext_Bool));
    packed_data->format = FORMAT_GLXContext_Display___GENPT___GLXFBConfig_int_GLXContext_Bool;
    packed_data->func = glXCreateNewContext;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = config;
    packed_data->args.a3 = render_type;
    packed_data->args.a4 = share_list;
    packed_data->args.a5 = direct;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXCreatePbuffer
static inline void push_glXCreatePbuffer(Display * dpy, GLXFBConfig config, const int * attrib_list) {
    PACKED_GLXPbuffer_Display___GENPT___GLXFBConfig_const_int___GENPT__ *packed_data = malloc(sizeof(PACKED_GLXPbuffer_Display___GENPT___GLXFBConfig_const_int___GENPT__));
    packed_data->format = FORMAT_GLXPbuffer_Display___GENPT___GLXFBConfig_const_int___GENPT__;
    packed_data->func = glXCreatePbuffer;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = config;
    packed_data->args.a3 = attrib_list;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXCreatePixmap
static inline void push_glXCreatePixmap(Display * dpy, GLXFBConfig config, Pixmap pixmap, const int * attrib_list) {
    PACKED_GLXPixmap_Display___GENPT___GLXFBConfig_Pixmap_const_int___GENPT__ *packed_data = malloc(sizeof(PACKED_GLXPixmap_Display___GENPT___GLXFBConfig_Pixmap_const_int___GENPT__));
    packed_data->format = FORMAT_GLXPixmap_Display___GENPT___GLXFBConfig_Pixmap_const_int___GENPT__;
    packed_data->func = glXCreatePixmap;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = config;
    packed_data->args.a3 = pixmap;
    packed_data->args.a4 = attrib_list;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXCreateWindow
static inline void push_glXCreateWindow(Display * dpy, GLXFBConfig config, Window win, const int * attrib_list) {
    PACKED_GLXWindow_Display___GENPT___GLXFBConfig_Window_const_int___GENPT__ *packed_data = malloc(sizeof(PACKED_GLXWindow_Display___GENPT___GLXFBConfig_Window_const_int___GENPT__));
    packed_data->format = FORMAT_GLXWindow_Display___GENPT___GLXFBConfig_Window_const_int___GENPT__;
    packed_data->func = glXCreateWindow;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = config;
    packed_data->args.a3 = win;
    packed_data->args.a4 = attrib_list;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXDestroyContext
static inline void push_glXDestroyContext(Display * dpy, GLXContext ctx) {
    PACKED_void_Display___GENPT___GLXContext *packed_data = malloc(sizeof(PACKED_void_Display___GENPT___GLXContext));
    packed_data->format = FORMAT_void_Display___GENPT___GLXContext;
    packed_data->func = glXDestroyContext;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = ctx;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXDestroyGLXPbufferSGIX
static inline void push_glXDestroyGLXPbufferSGIX(uint32_t pbuffer) {
    PACKED_void_uint32_t *packed_data = malloc(sizeof(PACKED_void_uint32_t));
    packed_data->format = FORMAT_void_uint32_t;
    packed_data->func = glXDestroyGLXPbufferSGIX;
    packed_data->args.a1 = pbuffer;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXDestroyGLXPixmap
static inline void push_glXDestroyGLXPixmap(Display * dpy, GLXPixmap pixmap) {
    PACKED_void_Display___GENPT___GLXPixmap *packed_data = malloc(sizeof(PACKED_void_Display___GENPT___GLXPixmap));
    packed_data->format = FORMAT_void_Display___GENPT___GLXPixmap;
    packed_data->func = glXDestroyGLXPixmap;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = pixmap;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXDestroyGLXVideoSourceSGIX
static inline void push_glXDestroyGLXVideoSourceSGIX(Display * dpy, uint32_t glxvideosource) {
    PACKED_void_Display___GENPT___uint32_t *packed_data = malloc(sizeof(PACKED_void_Display___GENPT___uint32_t));
    packed_data->format = FORMAT_void_Display___GENPT___uint32_t;
    packed_data->func = glXDestroyGLXVideoSourceSGIX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = glxvideosource;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXDestroyHyperpipeConfigSGIX
static inline void push_glXDestroyHyperpipeConfigSGIX(Display * dpy, int hpId) {
    PACKED_int_Display___GENPT___int *packed_data = malloc(sizeof(PACKED_int_Display___GENPT___int));
    packed_data->format = FORMAT_int_Display___GENPT___int;
    packed_data->func = glXDestroyHyperpipeConfigSGIX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = hpId;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXDestroyPbuffer
static inline void push_glXDestroyPbuffer(Display * dpy, GLXPbuffer pbuf) {
    PACKED_void_Display___GENPT___GLXPbuffer *packed_data = malloc(sizeof(PACKED_void_Display___GENPT___GLXPbuffer));
    packed_data->format = FORMAT_void_Display___GENPT___GLXPbuffer;
    packed_data->func = glXDestroyPbuffer;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = pbuf;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXDestroyPixmap
static inline void push_glXDestroyPixmap(Display * dpy, GLXPixmap pixmap) {
    PACKED_void_Display___GENPT___GLXPixmap *packed_data = malloc(sizeof(PACKED_void_Display___GENPT___GLXPixmap));
    packed_data->format = FORMAT_void_Display___GENPT___GLXPixmap;
    packed_data->func = glXDestroyPixmap;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = pixmap;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXDestroyWindow
static inline void push_glXDestroyWindow(Display * dpy, GLXWindow win) {
    PACKED_void_Display___GENPT___GLXWindow *packed_data = malloc(sizeof(PACKED_void_Display___GENPT___GLXWindow));
    packed_data->format = FORMAT_void_Display___GENPT___GLXWindow;
    packed_data->func = glXDestroyWindow;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = win;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXGetCurrentDisplay
static inline void push_glXGetCurrentDisplay() {
    PACKED_Display___GENPT__ *packed_data = malloc(sizeof(PACKED_Display___GENPT__));
    packed_data->format = FORMAT_Display___GENPT__;
    packed_data->func = glXGetCurrentDisplay;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXGetCurrentReadDrawable
static inline void push_glXGetCurrentReadDrawable() {
    PACKED_GLXDrawable *packed_data = malloc(sizeof(PACKED_GLXDrawable));
    packed_data->format = FORMAT_GLXDrawable;
    packed_data->func = glXGetCurrentReadDrawable;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXGetDrawableAttributes
static inline void push_glXGetDrawableAttributes(uint32_t drawable) {
    PACKED_void_uint32_t *packed_data = malloc(sizeof(PACKED_void_uint32_t));
    packed_data->format = FORMAT_void_uint32_t;
    packed_data->func = glXGetDrawableAttributes;
    packed_data->args.a1 = drawable;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXGetDrawableAttributesSGIX
static inline void push_glXGetDrawableAttributesSGIX(uint32_t drawable) {
    PACKED_void_uint32_t *packed_data = malloc(sizeof(PACKED_void_uint32_t));
    packed_data->format = FORMAT_void_uint32_t;
    packed_data->func = glXGetDrawableAttributesSGIX;
    packed_data->args.a1 = drawable;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXGetFBConfigAttrib
static inline void push_glXGetFBConfigAttrib(Display * dpy, GLXFBConfig config, int attribute, int * value) {
    PACKED_int_Display___GENPT___GLXFBConfig_int_int___GENPT__ *packed_data = malloc(sizeof(PACKED_int_Display___GENPT___GLXFBConfig_int_int___GENPT__));
    packed_data->format = FORMAT_int_Display___GENPT___GLXFBConfig_int_int___GENPT__;
    packed_data->func = glXGetFBConfigAttrib;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = config;
    packed_data->args.a3 = attribute;
    packed_data->args.a4 = value;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXGetFBConfigs
static inline void push_glXGetFBConfigs(Display * dpy, int screen, int * nelements) {
    PACKED_GLXFBConfig___GENPT___Display___GENPT___int_int___GENPT__ *packed_data = malloc(sizeof(PACKED_GLXFBConfig___GENPT___Display___GENPT___int_int___GENPT__));
    packed_data->format = FORMAT_GLXFBConfig___GENPT___Display___GENPT___int_int___GENPT__;
    packed_data->func = glXGetFBConfigs;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = screen;
    packed_data->args.a3 = nelements;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXGetFBConfigsSGIX
static inline void push_glXGetFBConfigsSGIX() {
    PACKED_void *packed_data = malloc(sizeof(PACKED_void));
    packed_data->format = FORMAT_void;
    packed_data->func = glXGetFBConfigsSGIX;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXGetProcAddress
static inline void push_glXGetProcAddress(const GLubyte * procName) {
    PACKED___GLXextFuncPtr_const_GLubyte___GENPT__ *packed_data = malloc(sizeof(PACKED___GLXextFuncPtr_const_GLubyte___GENPT__));
    packed_data->format = FORMAT___GLXextFuncPtr_const_GLubyte___GENPT__;
    packed_data->func = glXGetProcAddress;
    packed_data->args.a1 = procName;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXGetSelectedEvent
static inline void push_glXGetSelectedEvent(Display * dpy, GLXDrawable draw, unsigned long * event_mask) {
    PACKED_void_Display___GENPT___GLXDrawable_unsigned_long___GENPT__ *packed_data = malloc(sizeof(PACKED_void_Display___GENPT___GLXDrawable_unsigned_long___GENPT__));
    packed_data->format = FORMAT_void_Display___GENPT___GLXDrawable_unsigned_long___GENPT__;
    packed_data->func = glXGetSelectedEvent;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = draw;
    packed_data->args.a3 = event_mask;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXGetVisualConfigs
static inline void push_glXGetVisualConfigs() {
    PACKED_void *packed_data = malloc(sizeof(PACKED_void));
    packed_data->format = FORMAT_void;
    packed_data->func = glXGetVisualConfigs;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXGetVisualFromFBConfig
static inline void push_glXGetVisualFromFBConfig(Display * dpy, GLXFBConfig config) {
    PACKED_XVisualInfo___GENPT___Display___GENPT___GLXFBConfig *packed_data = malloc(sizeof(PACKED_XVisualInfo___GENPT___Display___GENPT___GLXFBConfig));
    packed_data->format = FORMAT_XVisualInfo___GENPT___Display___GENPT___GLXFBConfig;
    packed_data->func = glXGetVisualFromFBConfig;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = config;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXHyperpipeAttribSGIX
static inline void push_glXHyperpipeAttribSGIX(Display * dpy, int timeSlice, int attrib, int size, const void * attribList) {
    PACKED_int_Display___GENPT___int_int_int_const_void___GENPT__ *packed_data = malloc(sizeof(PACKED_int_Display___GENPT___int_int_int_const_void___GENPT__));
    packed_data->format = FORMAT_int_Display___GENPT___int_int_int_const_void___GENPT__;
    packed_data->func = glXHyperpipeAttribSGIX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = timeSlice;
    packed_data->args.a3 = attrib;
    packed_data->args.a4 = size;
    packed_data->args.a5 = attribList;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXHyperpipeConfigSGIX
static inline void push_glXHyperpipeConfigSGIX(Display * dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX cfg, int * hpId) {
    PACKED_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__ *packed_data = malloc(sizeof(PACKED_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__));
    packed_data->format = FORMAT_int_Display___GENPT___int_int_GLXHyperpipeConfigSGIX_int___GENPT__;
    packed_data->func = glXHyperpipeConfigSGIX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = networkId;
    packed_data->args.a3 = npipes;
    packed_data->args.a4 = cfg;
    packed_data->args.a5 = hpId;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXIsDirect
static inline void push_glXIsDirect(Display * dpy, GLXContext ctx) {
    PACKED_Bool_Display___GENPT___GLXContext *packed_data = malloc(sizeof(PACKED_Bool_Display___GENPT___GLXContext));
    packed_data->format = FORMAT_Bool_Display___GENPT___GLXContext;
    packed_data->func = glXIsDirect;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = ctx;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXJoinSwapGroupSGIX
static inline void push_glXJoinSwapGroupSGIX(uint32_t window, uint32_t group) {
    PACKED_void_uint32_t_uint32_t *packed_data = malloc(sizeof(PACKED_void_uint32_t_uint32_t));
    packed_data->format = FORMAT_void_uint32_t_uint32_t;
    packed_data->func = glXJoinSwapGroupSGIX;
    packed_data->args.a1 = window;
    packed_data->args.a2 = group;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXMakeContextCurrent
static inline void push_glXMakeContextCurrent(Display * dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx) {
    PACKED_Bool_Display___GENPT___GLXDrawable_GLXDrawable_GLXContext *packed_data = malloc(sizeof(PACKED_Bool_Display___GENPT___GLXDrawable_GLXDrawable_GLXContext));
    packed_data->format = FORMAT_Bool_Display___GENPT___GLXDrawable_GLXDrawable_GLXContext;
    packed_data->func = glXMakeContextCurrent;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = draw;
    packed_data->args.a3 = read;
    packed_data->args.a4 = ctx;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXMakeCurrent
static inline void push_glXMakeCurrent(Display * dpy, GLXDrawable drawable, GLXContext ctx) {
    PACKED_Bool_Display___GENPT___GLXDrawable_GLXContext *packed_data = malloc(sizeof(PACKED_Bool_Display___GENPT___GLXDrawable_GLXContext));
    packed_data->format = FORMAT_Bool_Display___GENPT___GLXDrawable_GLXContext;
    packed_data->func = glXMakeCurrent;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = drawable;
    packed_data->args.a3 = ctx;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXMakeCurrentReadSGI
static inline void push_glXMakeCurrentReadSGI(uint32_t drawable, uint32_t readdrawable, uint32_t context) {
    PACKED_void_uint32_t_uint32_t_uint32_t *packed_data = malloc(sizeof(PACKED_void_uint32_t_uint32_t_uint32_t));
    packed_data->format = FORMAT_void_uint32_t_uint32_t_uint32_t;
    packed_data->func = glXMakeCurrentReadSGI;
    packed_data->args.a1 = drawable;
    packed_data->args.a2 = readdrawable;
    packed_data->args.a3 = context;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXQueryContext
static inline void push_glXQueryContext(Display * dpy, GLXContext ctx, int attribute, int * value) {
    PACKED_int_Display___GENPT___GLXContext_int_int___GENPT__ *packed_data = malloc(sizeof(PACKED_int_Display___GENPT___GLXContext_int_int___GENPT__));
    packed_data->format = FORMAT_int_Display___GENPT___GLXContext_int_int___GENPT__;
    packed_data->func = glXQueryContext;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = ctx;
    packed_data->args.a3 = attribute;
    packed_data->args.a4 = value;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXQueryContextInfoEXT
static inline void push_glXQueryContextInfoEXT() {
    PACKED_void *packed_data = malloc(sizeof(PACKED_void));
    packed_data->format = FORMAT_void;
    packed_data->func = glXQueryContextInfoEXT;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXQueryDrawable
static inline void push_glXQueryDrawable(Display * dpy, GLXDrawable draw, int attribute, unsigned int * value) {
    PACKED_void_Display___GENPT___GLXDrawable_int_unsigned_int___GENPT__ *packed_data = malloc(sizeof(PACKED_void_Display___GENPT___GLXDrawable_int_unsigned_int___GENPT__));
    packed_data->format = FORMAT_void_Display___GENPT___GLXDrawable_int_unsigned_int___GENPT__;
    packed_data->func = glXQueryDrawable;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = draw;
    packed_data->args.a3 = attribute;
    packed_data->args.a4 = value;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXQueryExtensionsString
static inline void push_glXQueryExtensionsString(Display * dpy, int screen) {
    PACKED_const_char___GENPT___Display___GENPT___int *packed_data = malloc(sizeof(PACKED_const_char___GENPT___Display___GENPT___int));
    packed_data->format = FORMAT_const_char___GENPT___Display___GENPT___int;
    packed_data->func = glXQueryExtensionsString;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = screen;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXQueryHyperpipeAttribSGIX
static inline void push_glXQueryHyperpipeAttribSGIX(Display * dpy, int timeSlice, int attrib, int size, const void * returnAttribList) {
    PACKED_int_Display___GENPT___int_int_int_const_void___GENPT__ *packed_data = malloc(sizeof(PACKED_int_Display___GENPT___int_int_int_const_void___GENPT__));
    packed_data->format = FORMAT_int_Display___GENPT___int_int_int_const_void___GENPT__;
    packed_data->func = glXQueryHyperpipeAttribSGIX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = timeSlice;
    packed_data->args.a3 = attrib;
    packed_data->args.a4 = size;
    packed_data->args.a5 = returnAttribList;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXQueryHyperpipeBestAttribSGIX
static inline void push_glXQueryHyperpipeBestAttribSGIX(Display * dpy, int timeSlice, int attrib, int size, const void * attribList, void * returnAttribList) {
    PACKED_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__ *packed_data = malloc(sizeof(PACKED_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__));
    packed_data->format = FORMAT_int_Display___GENPT___int_int_int_const_void___GENPT___void___GENPT__;
    packed_data->func = glXQueryHyperpipeBestAttribSGIX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = timeSlice;
    packed_data->args.a3 = attrib;
    packed_data->args.a4 = size;
    packed_data->args.a5 = attribList;
    packed_data->args.a6 = returnAttribList;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXQueryHyperpipeConfigSGIX
static inline void push_glXQueryHyperpipeConfigSGIX(Display * dpy, int hpId, int * npipes) {
    PACKED_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__ *packed_data = malloc(sizeof(PACKED_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__));
    packed_data->format = FORMAT_GLXHyperpipeConfigSGIX___GENPT___Display___GENPT___int_int___GENPT__;
    packed_data->func = glXQueryHyperpipeConfigSGIX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = hpId;
    packed_data->args.a3 = npipes;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXQueryHyperpipeNetworkSGIX
static inline void push_glXQueryHyperpipeNetworkSGIX(Display * dpy, int * npipes) {
    PACKED_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__ *packed_data = malloc(sizeof(PACKED_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__));
    packed_data->format = FORMAT_GLXHyperpipeNetworkSGIX___GENPT___Display___GENPT___int___GENPT__;
    packed_data->func = glXQueryHyperpipeNetworkSGIX;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = npipes;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXQueryMaxSwapBarriersSGIX
static inline void push_glXQueryMaxSwapBarriersSGIX() {
    PACKED_void *packed_data = malloc(sizeof(PACKED_void));
    packed_data->format = FORMAT_void;
    packed_data->func = glXQueryMaxSwapBarriersSGIX;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXQueryServerString
static inline void push_glXQueryServerString(Display * dpy, int screen, int name) {
    PACKED_const_char___GENPT___Display___GENPT___int_int *packed_data = malloc(sizeof(PACKED_const_char___GENPT___Display___GENPT___int_int));
    packed_data->format = FORMAT_const_char___GENPT___Display___GENPT___int_int;
    packed_data->func = glXQueryServerString;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = screen;
    packed_data->args.a3 = name;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXQueryVersion
static inline void push_glXQueryVersion(Display * dpy, int * maj, int * min) {
    PACKED_Bool_Display___GENPT___int___GENPT___int___GENPT__ *packed_data = malloc(sizeof(PACKED_Bool_Display___GENPT___int___GENPT___int___GENPT__));
    packed_data->format = FORMAT_Bool_Display___GENPT___int___GENPT___int___GENPT__;
    packed_data->func = glXQueryVersion;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = maj;
    packed_data->args.a3 = min;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXRender
static inline void push_glXRender() {
    PACKED_void *packed_data = malloc(sizeof(PACKED_void));
    packed_data->format = FORMAT_void;
    packed_data->func = glXRender;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXRenderLarge
static inline void push_glXRenderLarge() {
    PACKED_void *packed_data = malloc(sizeof(PACKED_void));
    packed_data->format = FORMAT_void;
    packed_data->func = glXRenderLarge;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXSelectEvent
static inline void push_glXSelectEvent(Display * dpy, GLXDrawable draw, unsigned long event_mask) {
    PACKED_void_Display___GENPT___GLXDrawable_unsigned_long *packed_data = malloc(sizeof(PACKED_void_Display___GENPT___GLXDrawable_unsigned_long));
    packed_data->format = FORMAT_void_Display___GENPT___GLXDrawable_unsigned_long;
    packed_data->func = glXSelectEvent;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = draw;
    packed_data->args.a3 = event_mask;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXSwapBuffers
static inline void push_glXSwapBuffers(Display * dpy, GLXDrawable drawable) {
    PACKED_void_Display___GENPT___GLXDrawable *packed_data = malloc(sizeof(PACKED_void_Display___GENPT___GLXDrawable));
    packed_data->format = FORMAT_void_Display___GENPT___GLXDrawable;
    packed_data->func = glXSwapBuffers;
    packed_data->args.a1 = dpy;
    packed_data->args.a2 = drawable;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXSwapIntervalSGI
static inline void push_glXSwapIntervalSGI() {
    PACKED_void *packed_data = malloc(sizeof(PACKED_void));
    packed_data->format = FORMAT_void;
    packed_data->func = glXSwapIntervalSGI;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXUseXFont
static inline void push_glXUseXFont(Font font, int first, int count, int list) {
    PACKED_void_Font_int_int_int *packed_data = malloc(sizeof(PACKED_void_Font_int_int_int));
    packed_data->format = FORMAT_void_Font_int_int_int;
    packed_data->func = glXUseXFont;
    packed_data->args.a1 = font;
    packed_data->args.a2 = first;
    packed_data->args.a3 = count;
    packed_data->args.a4 = list;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXVendorPrivate
static inline void push_glXVendorPrivate() {
    PACKED_void *packed_data = malloc(sizeof(PACKED_void));
    packed_data->format = FORMAT_void;
    packed_data->func = glXVendorPrivate;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXVendorPrivateWithReply
static inline void push_glXVendorPrivateWithReply() {
    PACKED_void *packed_data = malloc(sizeof(PACKED_void));
    packed_data->format = FORMAT_void;
    packed_data->func = glXVendorPrivateWithReply;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXWaitGL
static inline void push_glXWaitGL() {
    PACKED_void *packed_data = malloc(sizeof(PACKED_void));
    packed_data->format = FORMAT_void;
    packed_data->func = glXWaitGL;
    glPushCall((void *)packed_data);
};
#endif
#ifndef direct_glXWaitX
static inline void push_glXWaitX() {
    PACKED_void *packed_data = malloc(sizeof(PACKED_void));
    packed_data->format = FORMAT_void;
    packed_data->func = glXWaitX;
    glPushCall((void *)packed_data);
};
#endif

#endif
