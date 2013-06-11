
#ifndef GL_H
#define GL_H

typedef struct {
    int format;
    void *func;
    void *args;
} UnknownCall;

enum FORMAT {
    FORMAT_void_GLenum_GLfloat,
    FORMAT_void_GLenum_GLfixed,
    FORMAT_void_GLuint,
    FORMAT_void_GLuint_GLuint,
    FORMAT_void_GLenum,
    FORMAT_void_GLuint_GLchar,
    FORMAT_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint,
    FORMAT_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint,
    FORMAT_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint,
    FORMAT_Boolean_GLsizei_GLuint_GLboolean,
    FORMAT_void_GLint,
    FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLuint_GLuint,
    FORMAT_void_GLhandleARB_GLhandleARB,
    FORMAT_void_GLuint_GLenum,
    FORMAT_void,
    FORMAT_void_GLenum_GLuint,
    FORMAT_void_GLenum_GLuint_GLuint,
    FORMAT_void_GLuint_GLuint_GLchar,
    FORMAT_void_GLhandleARB_GLuint_GLcharARB,
    FORMAT_void_GLenum_GLuint_GLuint_GLintptr,
    FORMAT_void_GLenum_GLuint_GLuint_GLintptr_GLsizeiptr,
    FORMAT_void_GLuint_GLuint_GLuint_GLchar,
    FORMAT_void_GLuint_GLuint_GLint_GLboolean_GLint_GLenum_GLenum,
    FORMAT_void_GLuint_GLuint_GLint_GLboolean_GLint_GLenum_GLint,
    FORMAT_UInt32_GLenum_GLenum,
    FORMAT_void_GLenum_GLenum_GLuint,
    FORMAT_UInt32_GLenum,
    FORMAT_UInt32_GLenum_GLenum_GLenum,
    FORMAT_void_GLuint_GLuint_GLintptr_GLsizei,
    FORMAT_void_GLuint_GLuint_GLenum_GLintptrARB,
    FORMAT_void_GLuint_GLuint_GLenum_GLenum_GLuint,
    FORMAT_void_GLbyte_GLbyte_GLbyte,
    FORMAT_void_GLbyte,
    FORMAT_void_GLdouble_GLdouble_GLdouble,
    FORMAT_void_GLdouble,
    FORMAT_void_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLfloat,
    FORMAT_void_GLint_GLint_GLint,
    FORMAT_void_GLshort_GLshort_GLshort,
    FORMAT_void_GLshort,
    FORMAT_void_GLenum_GLsizei_GLvoid,
    FORMAT_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_GLubyte,
    FORMAT_void_GLsizei_GLsizei_GLfixed_GLfixed_GLfixed_GLfixed_GLubyte,
    FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed,
    FORMAT_void_GLenum_GLenum,
    FORMAT_void_GLuint_GLenum_GLenum,
    FORMAT_void_GLenum_GLenum_GLenum_GLenum,
    FORMAT_void_GLuint_GLenum_GLenum_GLenum_GLenum,
    FORMAT_void_GLint_GLint_GLint_GLint_GLint_GLint_GLint_GLint_GLbitfield_GLenum,
    FORMAT_void_GLenum_GLuint_GLuint64EXT_GLsizeiptr,
    FORMAT_void_GLenum_GLsizeiptr_GLvoid_GLenum,
    FORMAT_void_GLenum_GLsizeiptrARB_GLvoid_GLenum,
    FORMAT_void_GLenum_GLenum_GLint,
    FORMAT_void_GLenum_GLintptr_GLsizeiptr_GLvoid,
    FORMAT_void_GLenum_GLintptrARB_GLsizeiptrARB_GLvoid,
    FORMAT_void_GLsizei_GLenum_GLvoid,
    FORMAT_GLenum_GLenum,
    FORMAT_FramebufferStatus_GLuint_GLenum,
    FORMAT_void_GLbitfield,
    FORMAT_void_GLenum_GLenum_GLenum_GLenum_void___GENPT__,
    FORMAT_void_GLenum_GLenum_GLintptr_GLsizeiptr_GLenum_GLenum_void___GENPT__,
    FORMAT_void_GLenum_GLint_GLfloat_GLint,
    FORMAT_void_GLenum_GLint_GLfloat,
    FORMAT_void_GLenum_GLint_GLint,
    FORMAT_void_GLenum_GLint_GLuint,
    FORMAT_void_GLint_GLint_GLint_GLint,
    FORMAT_void_GLuint_GLuint_GLuint_GLuint,
    FORMAT_void_GLclampf,
    FORMAT_void_GLfixed,
    FORMAT_void_GLuint_GLenum_GLenum_GLenum_void___GENPT__,
    FORMAT_void_GLuint_GLenum_GLenum_GLenum_GLsizeiptr_GLsizeiptr_void___GENPT__,
    FORMAT_GLenum_GLsync_GLbitfield_GLuint64,
    FORMAT_void_GLenum_GLdouble,
    FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLfloat_GLfloat,
    FORMAT_void_GLhalfNV_GLhalfNV_GLhalfNV,
    FORMAT_void_GLhalfNV,
    FORMAT_void_GLubyte_GLubyte_GLubyte,
    FORMAT_void_GLubyte,
    FORMAT_void_GLuint_GLuint_GLuint,
    FORMAT_void_GLushort_GLushort_GLushort,
    FORMAT_void_GLushort,
    FORMAT_void_GLfixed_GLfixed_GLfixed,
    FORMAT_void_GLbyte_GLbyte_GLbyte_GLbyte,
    FORMAT_void_GLdouble_GLdouble_GLdouble_GLdouble,
    FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV,
    FORMAT_void_GLshort_GLshort_GLshort_GLshort,
    FORMAT_void_GLubyte_GLubyte_GLubyte_GLubyte,
    FORMAT_void_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat,
    FORMAT_void_GLubyte_GLfloat,
    FORMAT_void_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLushort_GLushort_GLushort_GLushort,
    FORMAT_void_GLint_GLenum_GLsizei,
    FORMAT_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint,
    FORMAT_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint,
    FORMAT_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint,
    FORMAT_void_GLboolean_GLboolean_GLboolean_GLboolean,
    FORMAT_void_GLuint_GLboolean_GLboolean_GLboolean_GLboolean,
    FORMAT_void_GLint_GLenum_GLsizei_GLvoid,
    FORMAT_void_GLint_GLenum_GLsizei_GLsizei_GLvoid,
    FORMAT_void_GLint_GLenum_GLint_GLvoid___GENPT___GLint,
    FORMAT_void_GLint_GLenum_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid,
    FORMAT_void_GLenum_GLenum_GLsizei_GLenum_GLenum_GLvoid,
    FORMAT_void_GLenum_GLenum_GLfloat,
    FORMAT_void_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum,
    FORMAT_void_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum_GLboolean_GLboolean_GLboolean,
    FORMAT_void_GLenum_GLint,
    FORMAT_void_GLhandleARB,
    FORMAT_void_GLuint_GLsizei_GLchar___GENPT___GLint,
    FORMAT_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid,
    FORMAT_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid,
    FORMAT_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid,
    FORMAT_void_GLenum_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid,
    FORMAT_void_GLenum_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid,
    FORMAT_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid,
    FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid,
    FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid,
    FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid,
    FORMAT_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid,
    FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid,
    FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid,
    FORMAT_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid,
    FORMAT_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid,
    FORMAT_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid,
    FORMAT_void_GLuint_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid,
    FORMAT_void_GLuint_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid,
    FORMAT_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid,
    FORMAT_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid,
    FORMAT_void_GLenum_GLenum_GLfixed,
    FORMAT_void_GLenum_GLenum_GLintptr_GLintptr_GLsizeiptr,
    FORMAT_void_GLenum_GLsizei_GLint_GLint_GLsizei,
    FORMAT_void_GLenum_GLenum_GLint_GLint_GLsizei,
    FORMAT_void_GLenum_GLenum_GLint_GLint_GLsizei_GLsizei,
    FORMAT_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei,
    FORMAT_void_GLenum_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint,
    FORMAT_void_GLenum_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint,
    FORMAT_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei,
    FORMAT_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei,
    FORMAT_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei,
    FORMAT_void_GLint_GLint_GLsizei_GLsizei_GLenum,
    FORMAT_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint,
    FORMAT_void_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint,
    FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLsizei,
    FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei,
    FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei,
    FORMAT_void_GLuint_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint,
    FORMAT_void_GLuint_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint,
    FORMAT_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei,
    FORMAT_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei,
    FORMAT_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei,
    FORMAT_void_GLsizei_GLenum_GLvoid_GLuint_GLenum_GLenum_GLfloat,
    FORMAT_UInt32,
    FORMAT_handleARB,
    FORMAT_handleARB_GLenum,
    FORMAT_UInt32_GLenum_GLchar,
    FORMAT_UInt32_GLenum_GLsizei_GLchar__GENPT__const,
    FORMAT_sync_struct__cl_context___GENPT___struct__cl_event___GENPT___GLbitfield,
    FORMAT_void_GLDEBUGPROC_void___GENPT__,
    FORMAT_void_GLDEBUGPROCAMD_GLvoid,
    FORMAT_void_GLDEBUGPROCARB_GLvoid,
    FORMAT_void_GLenum_GLenum_GLenum_GLsizei_GLuint_GLboolean,
    FORMAT_void_GLenum_GLenum_GLsizei_GLuint_GLboolean,
    FORMAT_void_GLenum_GLenum_GLuint_GLenum_GLsizei_GLchar,
    FORMAT_void_GLenum_GLenum_GLuint_GLsizei_GLchar,
    FORMAT_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble,
    FORMAT_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat,
    FORMAT_void_GLuint_GLsizei,
    FORMAT_void_GLsizei_GLuint,
    FORMAT_void_GLint_GLchar,
    FORMAT_void_GLsync,
    FORMAT_void_GLclampd_GLclampd,
    FORMAT_void_GLdouble_GLdouble,
    FORMAT_void_GLboolean,
    FORMAT_void_GLuint_GLsizei_GLdouble,
    FORMAT_void_GLuint_GLdouble_GLdouble,
    FORMAT_void_GLclampf_GLclampf,
    FORMAT_void_GLfixed_GLfixed,
    FORMAT_void_GLenum_GLsizei_GLfloat,
    FORMAT_void_GLintptr,
    FORMAT_void_GLenum_GLint_GLsizei,
    FORMAT_void_GLenum_GLvoid,
    FORMAT_void_GLenum_GLint_GLsizei_GLsizei,
    FORMAT_void_GLenum_GLint_GLsizei_GLsizei_GLuint,
    FORMAT_void_GLsizei_GLenum,
    FORMAT_void_GLenum_GLsizei,
    FORMAT_void_GLenum_GLsizei_GLenum_GLvoid,
    FORMAT_void_GLenum_GLsizei_GLenum_GLvoid_GLint,
    FORMAT_void_GLenum_GLenum_GLvoid,
    FORMAT_void_GLenum_GLsizei_GLenum_GLvoid_GLsizei,
    FORMAT_void_GLenum_GLsizei_GLenum_void___GENPT___GLsizei_GLuint,
    FORMAT_void_GLenum_GLsizei_GLenum_GLvoid_GLsizei_GLint,
    FORMAT_void_GLenum_GLsizei_GLenum_void___GENPT___GLsizei_GLint_GLuint,
    FORMAT_void_GLsizei_GLsizei_GLenum_GLenum_GLvoid,
    FORMAT_void_GLenum_GLuint_GLuint_GLint_GLsizei,
    FORMAT_void_GLenum_GLuint_GLuint_GLsizei,
    FORMAT_void_GLenum_GLuint_GLuint_GLsizei_GLenum_GLvoid,
    FORMAT_void_GLenum_GLuint_GLuint_GLsizei_GLenum_GLvoid_GLint,
    FORMAT_void_GLuint_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLenum_GLuint_GLsizei,
    FORMAT_void_GLsizei,
    FORMAT_void_GLsizei_GLvoid,
    FORMAT_void_GLsizei_GLsizei_GLboolean,
    FORMAT_void_GLint_GLboolean___GENPT___GLint,
    FORMAT_void_GLenum_GLint_GLint_GLint_GLint,
    FORMAT_void_GLint_GLint,
    FORMAT_void_GLenum_GLuint_GLfloat,
    FORMAT_void_GLsizei_GLenum_GLfloat,
    FORMAT_void_GLsizei_GLenum_GLfixed,
    FORMAT_sync_GLenum_GLbitfield,
    FORMAT_Int32_GLuint,
    FORMAT_void_GLenum_GLintptr_GLsizeiptr,
    FORMAT_void_GLuint_GLintptr_GLsizeiptr,
    FORMAT_void_GLenum_GLint_GLvoid___GENPT___GLint,
    FORMAT_void_GLsizei_GLfloat,
    FORMAT_void_GLuint_GLsizei_GLenum,
    FORMAT_void_GLenum_GLenum_GLenum_GLuint,
    FORMAT_void_GLenum_GLenum_GLuint_GLint,
    FORMAT_void_GLenum_GLenum_GLenum_GLuint_GLint,
    FORMAT_void_GLenum_GLenum_GLenum_GLuint_GLint_GLint,
    FORMAT_void_GLenum_GLenum_GLuint_GLint_GLenum,
    FORMAT_void_GLenum_GLenum_GLuint_GLint_GLint,
    FORMAT_void_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble,
    FORMAT_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed,
    FORMAT_UInt32_GLsizei,
    FORMAT_UInt32_GLuint,
    FORMAT_List_GLsizei,
    FORMAT_Path_GLsizei,
    FORMAT_UInt32_GLenum_GLenum_GLenum_GLuint,
    FORMAT_void_GLuint_GLuint_GLenum_GLint,
    FORMAT_void_GLuint_GLuint_GLsizei_GLsizei_GLint_GLenum_GLchar,
    FORMAT_void_GLhandleARB_GLuint_GLsizei_GLsizei_GLint_GLenum_GLcharARB,
    FORMAT_void_GLuint_GLenum_GLuint_GLsizei_GLsizei_GLchar,
    FORMAT_void_GLuint_GLenum_GLuint_GLenum_GLint,
    FORMAT_void_GLuint_GLuint_GLsizei_GLsizei_GLchar,
    FORMAT_void_GLuint_GLsizei_GLuint_GLenum_GLint,
    FORMAT_void_GLuint_GLuint_GLsizei_GLsizei_GLsizei_GLenum_GLchar,
    FORMAT_void_GLhandleARB_GLsizei_GLsizei_GLhandleARB,
    FORMAT_void_GLuint_GLsizei_GLsizei_GLuint,
    FORMAT_Int32_GLuint_GLchar,
    FORMAT_Int32_GLhandleARB_GLcharARB,
    FORMAT_void_GLenum_GLuint_GLboolean,
    FORMAT_void_GLenum_GLboolean,
    FORMAT_void_GLenum_GLenum_GLint64,
    FORMAT_void_GLenum_GLenum_GLuint64EXT,
    FORMAT_void_GLenum_GLenum_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLenum_GLenum_GLvoid,
    FORMAT_void_GLenum_GLenum_GLenum_GLenum_GLfloat,
    FORMAT_void_GLenum_GLenum_GLenum_GLenum_GLint,
    FORMAT_void_GLenum_GLenum_GLenum_GLfloat,
    FORMAT_void_GLenum_GLenum_GLenum_GLint,
    FORMAT_void_GLenum_GLenum_GLint_GLvoid,
    FORMAT_void_GLenum_GLint_GLvoid,
    FORMAT_void_GLuint_GLenum_GLint_GLvoid,
    FORMAT_UInt32_GLuint_GLsizei_GLenum_GLenum_GLuint_GLenum_GLsizei_GLchar,
    FORMAT_UInt32_GLuint_GLsizei_GLenum_GLuint_GLuint_GLsizei_GLchar,
    FORMAT_void_GLenum_GLuint_GLdouble,
    FORMAT_ErrorCode,
    FORMAT_void_GLuint_GLenum_GLint,
    FORMAT_GLenum,
    FORMAT_void_GLenum_GLboolean_GLenum_GLenum_GLvoid,
    FORMAT_UInt64_GLuint_GLint_GLboolean_GLint_GLenum,
    FORMAT_void_GLhandleARB_GLsizei_GLsizei_GLcharARB,
    FORMAT_Int32,
    FORMAT_void_GLenum_GLuint_GLint64,
    FORMAT_void_GLenum_GLint64,
    FORMAT_void_GLenum_GLuint_GLint,
    FORMAT_void_GLenum_GLuint_GLuint64EXT,
    FORMAT_void_GLenum_GLuint64EXT,
    FORMAT_void_GLenum_GLenum_GLenum_GLsizei_GLint64,
    FORMAT_void_GLenum_GLenum_GLenum_GLsizei_GLint,
    FORMAT_void_GLuint_GLenum_GLboolean,
    FORMAT_void_GLuint_GLenum_GLfloat,
    FORMAT_void_GLenum_GLuint_GLenum_GLfloat,
    FORMAT_void_GLenum_GLuint_GLenum_GLint,
    FORMAT_void_GLenum_GLuint_GLenum_GLsizei_GLsizei_GLboolean_GLvoid,
    FORMAT_void_GLenum_GLenum_GLdouble,
    FORMAT_void_GLenum_GLenum_GLenum_GLdouble,
    FORMAT_void_GLenum_GLenum_GLint_GLenum_GLenum_GLvoid,
    FORMAT_void_GLenum_GLenum_GLint_GLenum_GLfloat,
    FORMAT_void_GLenum_GLenum_GLint_GLenum_GLint,
    FORMAT_void_GLuint_GLenum_GLuint64EXT,
    FORMAT_void_GLuint_GLenum_GLvoid___GENPT__,
    FORMAT_void_GLuint_GLintptr_GLsizeiptr_GLvoid,
    FORMAT_void_GLuint_GLenum_GLenum_GLint,
    FORMAT_void_GLuint_GLenum_GLuint_GLint,
    FORMAT_void_GLuint_GLenum_GLuint_GLuint,
    FORMAT_void_GLuint_GLenum_GLuint_GLdouble,
    FORMAT_void_GLuint_GLenum_GLuint_GLfloat,
    FORMAT_void_GLuint_GLenum_GLenum_GLvoid,
    FORMAT_void_GLint_GLchar_GLsizei_GLint_GLchar,
    FORMAT_void_GLint_GLchar_GLenum_GLint,
    FORMAT_void_GLenum_GLuint_GLsizei_GLsizei_GLchar,
    FORMAT_void_GLhandleARB_GLenum_GLfloat,
    FORMAT_void_GLhandleARB_GLenum_GLint,
    FORMAT_void_void___GENPT___GLsizei_GLsizei_GLchar,
    FORMAT_void_GLuint_GLenum_GLuint,
    FORMAT_void_GLuint_GLubyte,
    FORMAT_void_GLuint_GLfloat,
    FORMAT_Float32_GLuint_GLsizei_GLsizei,
    FORMAT_void_GLbitfield_GLuint_GLsizei_GLsizei_GLfloat,
    FORMAT_void_GLbitfield_GLsizei_GLenum_GLvoid_GLuint_GLsizei_GLfloat,
    FORMAT_void_GLenum_GLsizei_GLenum_GLvoid_GLuint_GLfloat_GLfloat_GLenum_GLfloat,
    FORMAT_void_GLuint_GLenum_GLsizei_GLuint_GLint,
    FORMAT_void_GLuint_GLuint_GLenum_GLvoid,
    FORMAT_void_GLuint_GLint_GLint_GLsizei_GLuint,
    FORMAT_void_GLuint_GLsizei_GLsizei_GLchar,
    FORMAT_void_GLint_GLsizei_GLuint,
    FORMAT_void_GLenum_GLushort,
    FORMAT_void_GLenum_GLint_GLfixed,
    FORMAT_void_GLenum_GLuint_GLvoid___GENPT__,
    FORMAT_void_GLenum_GLvoid___GENPT__,
    FORMAT_void_GLuint_GLsizei_GLsizei_GLenum_GLvoid,
    FORMAT_void_GLuint_GLsizei_GLubyte_GLdouble,
    FORMAT_void_GLuint_GLsizei_GLubyte_GLfloat,
    FORMAT_void_GLenum_GLuint_GLenum_GLdouble,
    FORMAT_UInt32_GLuint_GLenum_GLchar,
    FORMAT_Int32_GLuint_GLenum_GLchar,
    FORMAT_void_GLuint_GLenum_GLuint_GLsizei_GLenum_GLsizei_GLsizei_GLint,
    FORMAT_void_GLuint_GLenum_GLubyte,
    FORMAT_void_GLuint_GLenum_GLint64,
    FORMAT_void_GLuint_GLenum_GLint64EXT,
    FORMAT_void_GLuint_GLenum_GLuint64,
    FORMAT_void_GLenum_GLenum_GLenum_GLvoid_GLvoid_GLvoid,
    FORMAT_void_GLenum_GLenum_GLint_GLint,
    FORMAT_String_GLenum,
    FORMAT_String_GLenum_GLuint,
    FORMAT_void_GLsync_GLenum_GLsizei_GLsizei_GLint,
    FORMAT_void_GLenum_GLint_GLenum_GLenum_GLvoid,
    FORMAT_void_GLenum_GLint_GLenum_GLfloat,
    FORMAT_void_GLenum_GLint_GLenum_GLint,
    FORMAT_void_GLenum_GLint_GLenum_GLfixed,
    FORMAT_UInt64_GLuint,
    FORMAT_void_GLuint_GLenum_GLint_GLenum_GLenum_GLvoid,
    FORMAT_void_GLuint_GLenum_GLint_GLenum_GLfloat,
    FORMAT_void_GLuint_GLenum_GLint_GLenum_GLint,
    FORMAT_void_GLuint_GLenum_GLenum_GLuint,
    FORMAT_void_GLuint_GLenum_GLenum_GLfloat,
    FORMAT_UInt64_GLuint_GLuint,
    FORMAT_void_GLuint_GLuint_GLint,
    FORMAT_UInt32_GLuint_GLchar,
    FORMAT_Int32_GLuint_GLint,
    FORMAT_void_GLuint_GLsizei_GLchar__GENPT__const_GLuint,
    FORMAT_BufferOffset_GLuint_GLint,
    FORMAT_void_GLuint_GLint_GLdouble,
    FORMAT_void_GLuint_GLint_GLfloat,
    FORMAT_void_GLhandleARB_GLint_GLfloat,
    FORMAT_void_GLuint_GLint_GLint64EXT,
    FORMAT_void_GLuint_GLint_GLint,
    FORMAT_void_GLhandleARB_GLint_GLint,
    FORMAT_void_GLuint_GLint_GLuint64EXT,
    FORMAT_void_GLuint_GLint_GLuint,
    FORMAT_void_GLuint_GLuint_GLenum_GLvoid___GENPT__,
    FORMAT_void_GLuint_GLenum_GLdouble,
    FORMAT_void_GLuint_GLuint_GLenum_GLdouble,
    FORMAT_void_GLuint_GLuint_GLenum_GLfloat,
    FORMAT_void_GLenum_GLenum_GLenum_GLsizei_GLvoid,
    FORMAT_void_GLenum_GLint_GLsizei_GLvoid,
    FORMAT_void_GLenum_GLboolean_GLenum_GLenum_GLsizei_GLvoid,
    FORMAT_void_GLenum_GLenum_GLsizei_GLdouble,
    FORMAT_void_GLenum_GLenum_GLsizei_GLfloat,
    FORMAT_void_GLenum_GLenum_GLsizei_GLint,
    FORMAT_void_GLenum_GLsizei_GLuint,
    FORMAT_void_GLenum_GLsizei_GLushort,
    FORMAT_void_GLsizei_GLubyte,
    FORMAT_void_GLenum_GLenum_GLenum_GLsizei_GLvoid_GLsizei_GLvoid_GLvoid,
    FORMAT_void_GLenum_GLint_GLenum_GLenum_GLsizei_GLvoid,
    FORMAT_void_GLuint_GLint_GLsizei_GLdouble,
    FORMAT_void_GLuint_GLint_GLsizei_GLfloat,
    FORMAT_void_GLuint_GLint_GLsizei_GLint,
    FORMAT_void_GLuint_GLint_GLsizei_GLuint,
    FORMAT_void_GLenum_GLsizei_GLenum_GLboolean,
    FORMAT_sync_GLenum_GLintptr_GLbitfield,
    FORMAT_void_GLenum_GLclampf,
    FORMAT_void_GLenum_GLsizei_GLsizei_GLvoid,
    FORMAT_void_GLsizei_GLint,
    FORMAT_void_GLuint_GLuint_GLuint_GLfloat,
    FORMAT_void_GLenum_GLsizei_GLenum,
    FORMAT_void_GLenum_GLsizei_GLenum_GLint_GLint_GLsizei_GLsizei,
    FORMAT_void_GLuint_GLint,
    FORMAT_void_GLuint_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei,
    FORMAT_Boolean_GLuint,
    FORMAT_Boolean_GLenum,
    FORMAT_Boolean_GLenum_GLuint,
    FORMAT_Boolean_GLuint64,
    FORMAT_Boolean_GLint_GLchar,
    FORMAT_Boolean_GLuint_GLuint_GLfloat_GLfloat,
    FORMAT_Boolean_GLuint_GLfloat_GLfloat,
    FORMAT_Boolean_GLsync,
    FORMAT_Boolean_GLuint_GLenum,
    FORMAT_void_GLint_GLushort,
    FORMAT_void_GLenum_GLuint_GLsizei_GLubyte,
    FORMAT_void_GLint_GLsizei,
    FORMAT_void_GLuint64,
    FORMAT_void_GLuint64_GLenum,
    FORMAT_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble,
    FORMAT_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat,
    FORMAT_void_GLenum_GLfixed_GLfixed_GLint_GLint_GLfixed,
    FORMAT_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble,
    FORMAT_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat,
    FORMAT_void_GLenum_GLfixed_GLfixed_GLint_GLint_GLfixed_GLfixed_GLint_GLint_GLfixed,
    FORMAT_VoidPointer_GLenum_GLenum,
    FORMAT_VoidPointer_GLenum_GLintptr_GLsizeiptr_GLbitfield,
    FORMAT_void_GLenum_GLuint_GLenum_GLsizei_GLsizei_GLint_GLint_GLboolean_GLvoid,
    FORMAT_void_GLint_GLdouble_GLdouble,
    FORMAT_void_GLint_GLfloat_GLfloat,
    FORMAT_void_GLint_GLfixed_GLfixed,
    FORMAT_void_GLint_GLdouble_GLdouble_GLint_GLdouble_GLdouble,
    FORMAT_void_GLint_GLfloat_GLfloat_GLint_GLfloat_GLfloat,
    FORMAT_void_GLint_GLfixed_GLfixed_GLfixed_GLfixed,
    FORMAT_VoidPointer_GLuint_GLenum,
    FORMAT_VoidPointer_GLuint_GLintptr_GLsizeiptr_GLbitfield,
    FORMAT_VoidPointer_GLuint,
    FORMAT_VoidPointer_GLuint_GLint_GLbitfield_GLint_GLenum,
    FORMAT_void_GLuint_GLuint_GLdouble_GLdouble_GLint_GLint_GLdouble,
    FORMAT_void_GLuint_GLuint_GLfloat_GLfloat_GLint_GLint_GLfloat,
    FORMAT_void_GLuint_GLuint_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble,
    FORMAT_void_GLuint_GLuint_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat,
    FORMAT_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble,
    FORMAT_void_GLint_GLubyte,
    FORMAT_void_GLint_GLuint,
    FORMAT_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble,
    FORMAT_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLenum_GLdouble_GLdouble_GLdouble,
    FORMAT_void_GLenum_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLenum_GLenum_GLboolean,
    FORMAT_void_GLenum_void___GENPT___GLsizei_GLsizei,
    FORMAT_void_GLenum_GLvoid_GLsizei_GLsizei,
    FORMAT_void_GLenum_GLsizei_GLenum_GLvoid__GENPT__const_GLsizei,
    FORMAT_void_GLenum_GLsizei_GLenum_GLvoid__GENPT__const_GLsizei_GLint,
    FORMAT_void_GLenum_GLsizei_GLenum_GLvoid___GENPT___GLsizei,
    FORMAT_void_GLenum_GLenum_void___GENPT___GLsizei_GLsizei,
    FORMAT_void_GLenum_GLenum_GLvoid_GLsizei_GLsizei,
    FORMAT_void_GLenum_GLuint_GLuint_GLint_GLsizei_GLsizei,
    FORMAT_void_GLenum_GLint_GLsizei_GLsizei_GLint,
    FORMAT_void_GLenum_GLbyte,
    FORMAT_void_GLenum_GLhalfNV,
    FORMAT_void_GLenum_GLshort,
    FORMAT_void_GLenum_GLbyte_GLbyte,
    FORMAT_void_GLenum_GLdouble_GLdouble,
    FORMAT_void_GLenum_GLfloat_GLfloat,
    FORMAT_void_GLenum_GLhalfNV_GLhalfNV,
    FORMAT_void_GLenum_GLshort_GLshort,
    FORMAT_void_GLenum_GLfixed_GLfixed,
    FORMAT_void_GLenum_GLbyte_GLbyte_GLbyte,
    FORMAT_void_GLenum_GLhalfNV_GLhalfNV_GLhalfNV,
    FORMAT_void_GLenum_GLint_GLint_GLint,
    FORMAT_void_GLenum_GLshort_GLshort_GLshort,
    FORMAT_void_GLenum_GLfixed_GLfixed_GLfixed,
    FORMAT_void_GLenum_GLbyte_GLbyte_GLbyte_GLbyte,
    FORMAT_void_GLenum_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV,
    FORMAT_void_GLenum_GLshort_GLshort_GLshort_GLshort,
    FORMAT_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed,
    FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLvoid,
    FORMAT_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLint_GLenum_GLenum_GLvoid,
    FORMAT_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid,
    FORMAT_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid,
    FORMAT_void_GLenum_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid,
    FORMAT_void_GLenum_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid,
    FORMAT_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid,
    FORMAT_void_GLuint_GLsizeiptr_GLvoid_GLenum,
    FORMAT_void_GLuint_GLuint_GLintptr_GLintptr_GLsizeiptr,
    FORMAT_void_GLuint_GLenum_GLenum_GLuint_GLint,
    FORMAT_void_GLuint_GLenum_GLenum_GLuint_GLint_GLint,
    FORMAT_void_GLuint_GLenum_GLuint_GLint_GLenum,
    FORMAT_void_GLuint_GLenum_GLuint_GLint_GLint,
    FORMAT_void_GLuint_GLenum_GLuint_GLdouble_GLdouble_GLdouble_GLdouble,
    FORMAT_void_GLuint_GLenum_GLuint_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLuint_GLenum_GLuint_GLint_GLint_GLint_GLint,
    FORMAT_void_GLuint_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint,
    FORMAT_void_GLuint_GLenum_GLuint_GLsizei_GLfloat,
    FORMAT_void_GLuint_GLenum_GLuint_GLsizei_GLint,
    FORMAT_void_GLuint_GLenum_GLuint_GLsizei_GLuint,
    FORMAT_void_GLuint_GLenum_GLenum_GLsizei_GLvoid,
    FORMAT_void_GLuint_GLenum_GLsizei_GLsizei,
    FORMAT_void_GLuint_GLsizei_GLsizei_GLenum_GLsizei_GLsizei,
    FORMAT_void_GLuint_GLsizei_GLenum_GLsizei_GLsizei,
    FORMAT_void_GLenum_GLint_GLchar_GLint_GLchar,
    FORMAT_UInt32_GLsizei_GLvoid_GLenum,
    FORMAT_void_GLenum_GLuint_GLsizei_GLchar,
    FORMAT_void_void___GENPT___GLsizei_GLchar,
    FORMAT_GLenum_GLenum_GLuint_GLenum,
    FORMAT_void_GLuint_GLuint_GLenum,
    FORMAT_void_GLuint_GLsizei_GLubyte_GLsizei_GLenum_GLvoid,
    FORMAT_void_GLuint_GLsizei_GLenum_GLvoid,
    FORMAT_void_GLuint_GLsizei_GLfloat,
    FORMAT_void_GLuint_GLenum_GLvoid_GLbitfield_GLuint_GLsizei_GLenum_GLuint_GLfloat,
    FORMAT_void_GLuint_GLenum_GLvoid_GLbitfield_GLsizei_GLenum_GLvoid_GLenum_GLuint_GLfloat,
    FORMAT_void_GLuint_GLenum_GLsizei_GLvoid,
    FORMAT_void_GLuint_GLsizei_GLsizei_GLsizei_GLubyte_GLsizei_GLenum_GLvoid,
    FORMAT_void_GLenum_GLenum_GLint_GLfloat,
    FORMAT_Boolean_GLuint_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_Int32_GLint,
    FORMAT_void_GLuint_GLuint64EXT_GLuint_GLuint_GLenum_GLenum_GLuint_GLenum_GLuint_GLenum_GLuint_GLenum_GLuint,
    FORMAT_void_GLuint_GLuint64EXT_GLuint_GLuint_GLenum_GLenum_GLuint_GLuint_GLenum_GLuint_GLuint,
    FORMAT_void_GLsizei_GLuint_GLfloat,
    FORMAT_void_GLsizei_GLuint_GLclampf,
    FORMAT_void_GLsizei_GLuint_GLfixed,
    FORMAT_void_GLuint_GLenum_GLvoid_GLsizei,
    FORMAT_void_GLenum_GLuint_GLuint_GLsizei_GLint,
    FORMAT_void_GLenum_GLuint_GLuint_GLsizei_GLuint,
    FORMAT_void_GLenum_GLuint_GLuint_GLsizei_GLfloat,
    FORMAT_void_GLenum_GLuint_GLdouble_GLdouble_GLdouble_GLdouble,
    FORMAT_void_GLenum_GLuint_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLenum_GLuint_GLint_GLint_GLint_GLint,
    FORMAT_void_GLenum_GLuint_GLsizei_GLfloat,
    FORMAT_void_GLenum_GLuint_GLsizei_GLint,
    FORMAT_void_GLenum_GLuint_GLsizei_GLuint,
    FORMAT_void_GLuint_GLsizei_GLubyte_GLdouble_GLdouble_GLdouble_GLdouble,
    FORMAT_void_GLuint_GLsizei_GLubyte_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLenum_GLuint_GLsizei_GLdouble,
    FORMAT_void_GLenum_GLenum_GLsizei_GLvoid,
    FORMAT_void_GLuint_GLint_GLsizei_GLint64EXT,
    FORMAT_void_GLuint_GLint_GLsizei_GLuint64EXT,
    FORMAT_void_GLuint_GLint_GLdouble_GLdouble,
    FORMAT_void_GLuint_GLint_GLfloat_GLfloat,
    FORMAT_void_GLuint_GLint_GLint_GLint,
    FORMAT_void_GLuint_GLint_GLint64EXT_GLint64EXT,
    FORMAT_void_GLuint_GLint_GLuint_GLuint,
    FORMAT_void_GLuint_GLint_GLuint64EXT_GLuint64EXT,
    FORMAT_void_GLuint_GLint_GLdouble_GLdouble_GLdouble,
    FORMAT_void_GLuint_GLint_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLuint_GLint_GLint_GLint_GLint,
    FORMAT_void_GLuint_GLint_GLint64EXT_GLint64EXT_GLint64EXT,
    FORMAT_void_GLuint_GLint_GLuint_GLuint_GLuint,
    FORMAT_void_GLuint_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT,
    FORMAT_void_GLuint_GLint_GLdouble_GLdouble_GLdouble_GLdouble,
    FORMAT_void_GLuint_GLint_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLuint_GLint_GLint_GLint_GLint_GLint,
    FORMAT_void_GLuint_GLint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT,
    FORMAT_void_GLuint_GLint_GLuint_GLuint_GLuint_GLuint,
    FORMAT_void_GLuint_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT,
    FORMAT_void_GLuint_GLint_GLuint64,
    FORMAT_void_GLuint_GLint_GLsizei_GLuint64,
    FORMAT_void_GLuint_GLint_GLsizei_GLboolean_GLdouble,
    FORMAT_void_GLuint_GLint_GLsizei_GLboolean_GLfloat,
    FORMAT_GLbitfield_GLfixed_GLint,
    FORMAT_void_GLshort_GLshort,
    FORMAT_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid,
    FORMAT_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLsizei_GLvoid,
    FORMAT_Int32_GLenum,
    FORMAT_void_GLenum_GLenum_GLsizei_GLsizei,
    FORMAT_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei,
    FORMAT_void_GLenum_GLsizei_GLsizei_GLenum_GLsizei_GLsizei,
    FORMAT_void_GLenum_GLsizei_GLvoid___GENPT__,
    FORMAT_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLuint_GLfloat_GLfloat,
    FORMAT_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLuint_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLuint_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLuint_GLubyte_GLfloat,
    FORMAT_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLfloat_GLboolean,
    FORMAT_void_GLfixed_GLboolean,
    FORMAT_void_GLclampf_GLboolean,
    FORMAT_void_GLuint_GLbitfield,
    FORMAT_void_GLint_GLint_GLsizei_GLsizei,
    FORMAT_void_GLuint_GLsizei_GLint,
    FORMAT_void_GLuint_GLint_GLint_GLsizei_GLsizei,
    FORMAT_void_GLuint_GLboolean_GLuint_GLint_GLuint,
    FORMAT_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid_GLvoid,
    FORMAT_void_GLuint_GLenum_GLvoid,
    FORMAT_void_GLsizei_GLuint_GLenum_GLvoid_GLsizei,
    FORMAT_void_GLenum_GLuint_GLuint_GLuint,
    FORMAT_void_GLenum_GLuint_GLuint_GLuint_GLuint,
    FORMAT_void_GLuint_GLsizei_GLchar__GENPT__const_GLint,
    FORMAT_void_GLhandleARB_GLsizei_GLcharARB___GENPT___GLint,
    FORMAT_void_GLsizei_GLenum_GLvoid_GLuint_GLenum_GLuint_GLenum_GLfloat,
    FORMAT_void_GLenum_GLenum_GLint_GLuint,
    FORMAT_void_GLenum_GLenum_GLenum,
    FORMAT_void_GLsizei_GLenum_GLvoid_GLuint_GLint_GLuint_GLenum_GLfloat,
    FORMAT_void_GLuint_GLuint_GLenum_GLenum_GLenum_GLenum,
    FORMAT_void_GLenum_GLenum_GLuint_GLintptr_GLsizeiptr,
    FORMAT_void_GLbyte_GLbyte,
    FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLfloat_GLfloat_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLfloat_GLubyte_GLfloat,
    FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLhalfNV_GLhalfNV,
    FORMAT_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_GLvoid,
    FORMAT_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid,
    FORMAT_void_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLboolean,
    FORMAT_void_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLboolean,
    FORMAT_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid,
    FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid,
    FORMAT_void_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean,
    FORMAT_void_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean,
    FORMAT_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid,
    FORMAT_void_GLenum_GLsizei_GLenum_GLsizei,
    FORMAT_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLboolean,
    FORMAT_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei,
    FORMAT_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei_GLboolean,
    FORMAT_void_GLenum_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLbitfield,
    FORMAT_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid,
    FORMAT_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid,
    FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid,
    FORMAT_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid,
    FORMAT_void_GLuint_GLenum_GLenum_GLuint_GLintptr_GLsizeiptr,
    FORMAT_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLint_GLenum_GLenum_GLvoid,
    FORMAT_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid,
    FORMAT_void_GLuint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLboolean,
    FORMAT_void_GLuint_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLboolean,
    FORMAT_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid,
    FORMAT_void_GLuint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean,
    FORMAT_void_GLuint_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean,
    FORMAT_void_GLuint_GLenum_GLsizei_GLenum_GLsizei,
    FORMAT_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei,
    FORMAT_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLboolean,
    FORMAT_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei,
    FORMAT_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei_GLboolean,
    FORMAT_void_GLuint_GLenum_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLbitfield,
    FORMAT_void_GLuint_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid,
    FORMAT_void_GLuint_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid,
    FORMAT_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid,
    FORMAT_void_GLuint_GLenum_GLuint_GLenum_GLuint_GLuint_GLuint_GLuint,
    FORMAT_void_GLenum_GLuint_GLenum_GLenum,
    FORMAT_void_GLsizei_GLint_GLenum,
    FORMAT_void_GLsizei_GLint_GLsizei_GLint_GLenum,
    FORMAT_void_GLuint_GLsizei_GLchar__GENPT__const_GLenum,
    FORMAT_void_GLuint_GLsizei_GLchar___GENPT___GLenum,
    FORMAT_void_GLuint_GLsizei_GLint_GLenum,
    FORMAT_void_GLint_GLdouble,
    FORMAT_void_GLint_GLsizei_GLdouble,
    FORMAT_void_GLint_GLfloat,
    FORMAT_void_GLint_GLsizei_GLfloat,
    FORMAT_void_GLint_GLint64EXT,
    FORMAT_void_GLint_GLsizei_GLint64EXT,
    FORMAT_void_GLint_GLsizei_GLint,
    FORMAT_void_GLint_GLuint64EXT,
    FORMAT_void_GLint_GLsizei_GLuint64EXT,
    FORMAT_void_GLint_GLint64EXT_GLint64EXT,
    FORMAT_void_GLint_GLuint_GLuint,
    FORMAT_void_GLint_GLuint64EXT_GLuint64EXT,
    FORMAT_void_GLint_GLdouble_GLdouble_GLdouble,
    FORMAT_void_GLint_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLint_GLint64EXT_GLint64EXT_GLint64EXT,
    FORMAT_void_GLint_GLuint_GLuint_GLuint,
    FORMAT_void_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT,
    FORMAT_void_GLint_GLdouble_GLdouble_GLdouble_GLdouble,
    FORMAT_void_GLint_GLfloat_GLfloat_GLfloat_GLfloat,
    FORMAT_void_GLint_GLint_GLint_GLint_GLint,
    FORMAT_void_GLint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT,
    FORMAT_void_GLint_GLuint_GLuint_GLuint_GLuint,
    FORMAT_void_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT,
    FORMAT_void_GLint_GLuint64,
    FORMAT_void_GLint_GLsizei_GLuint64,
    FORMAT_void_GLint_GLsizei_GLboolean_GLdouble,
    FORMAT_void_GLint_GLsizei_GLboolean_GLfloat,
    FORMAT_void_GLuint_GLuint_GLsizei_GLvoid_GLenum,
    FORMAT_void_GLuint_GLbitfield_GLuint,
    FORMAT_void_GLvdpauSurfaceNV_GLenum_GLsizei_GLsizei_GLint,
    FORMAT_void_GLvoid_GLvoid,
    FORMAT_void_GLvdpauSurfaceNV,
    FORMAT_void_GLsizei_GLvdpauSurfaceNV,
    FORMAT_vdpauSurfaceNV_GLvoid___GENPT___GLenum_GLsizei_GLuint,
    FORMAT_vdpauSurfaceNV_GLvoid_GLenum_GLsizei_GLuint,
    FORMAT_void_GLvdpauSurfaceNV_GLenum,
    FORMAT_void_GLuint_GLenum_GLsizei_GLuint_GLuint,
    FORMAT_void_GLuint_GLenum_GLuint_GLvoid,
    FORMAT_void_GLuint_GLbyte,
    FORMAT_void_GLuint_GLdouble,
    FORMAT_void_GLuint_GLshort,
    FORMAT_void_GLuint_GLushort,
    FORMAT_void_GLuint_GLuint_GLuint_GLintptr_GLsizei,
    FORMAT_void_GLuint_GLuint_GLint_GLenum_GLsizei_GLintptr,
    FORMAT_void_GLuint_GLuint_GLsizei_GLintptr,
    FORMAT_void_GLuint_GLuint_GLenum_GLsizei_GLintptr,
    FORMAT_void_GLuint_GLuint_GLenum_GLint_GLenum_GLsizei_GLintptr,
    FORMAT_void_GLuint_GLuint_GLint_GLenum_GLboolean_GLuint,
    FORMAT_void_GLuint_GLuint_GLint_GLenum_GLuint,
    FORMAT_void_GLuint_GLuint_GLuint_GLint_GLenum_GLsizei_GLintptr,
    FORMAT_void_GLuint_GLuint_GLuint_GLint_GLenum_GLboolean_GLsizei_GLintptr,
    FORMAT_void_GLuint_GLhalfNV,
    FORMAT_void_GLuint_GLhalfNV_GLhalfNV,
    FORMAT_void_GLuint_GLshort_GLshort,
    FORMAT_void_GLuint_GLdouble_GLdouble_GLdouble,
    FORMAT_void_GLuint_GLhalfNV_GLhalfNV_GLhalfNV,
    FORMAT_void_GLuint_GLshort_GLshort_GLshort,
    FORMAT_void_GLuint_GLubyte_GLubyte_GLubyte_GLubyte,
    FORMAT_void_GLuint_GLdouble_GLdouble_GLdouble_GLdouble,
    FORMAT_void_GLuint_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV,
    FORMAT_void_GLuint_GLshort_GLshort_GLshort_GLshort,
    FORMAT_void_GLuint_GLint_GLenum_GLboolean_GLsizei_GLuint_GLuint,
    FORMAT_void_GLuint_GLint_GLenum_GLboolean_GLuint,
    FORMAT_void_GLuint_GLint_GLenum_GLboolean_GLsizei,
    FORMAT_void_GLuint_GLuint_GLuint_GLuint_GLuint,
    FORMAT_void_GLuint_GLint_GLenum_GLuint,
    FORMAT_void_GLuint_GLint_GLenum_GLsizei,
    FORMAT_void_GLuint_GLint_GLenum_GLsizei_GLvoid,
    FORMAT_void_GLuint_GLint64EXT,
    FORMAT_void_GLuint_GLuint64EXT,
    FORMAT_void_GLuint_GLint64EXT_GLint64EXT,
    FORMAT_void_GLuint_GLuint64EXT_GLuint64EXT,
    FORMAT_void_GLuint_GLint64EXT_GLint64EXT_GLint64EXT,
    FORMAT_void_GLuint_GLuint64EXT_GLuint64EXT_GLuint64EXT,
    FORMAT_void_GLuint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT,
    FORMAT_void_GLuint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT,
    FORMAT_void_GLuint_GLenum_GLboolean_GLuint,
    FORMAT_void_GLuint_GLint_GLenum_GLboolean_GLsizei_GLvoid,
    FORMAT_void_GLuint_GLsizei_GLhalfNV,
    FORMAT_void_GLuint_GLsizei_GLshort,
    FORMAT_void_GLuint_GLsizei_GLubyte,
    FORMAT_GLenum_GLuint_GLuint_GLuint64EXT,
    FORMAT_void_GLsync_GLbitfield_GLuint64,
    FORMAT_void_GLuint_GLsizei_GLuint_GLfloat,
    FORMAT_void_GLint_GLbyte,
    FORMAT_void_GLint_GLshort,
    FORMAT_Bool_Display_GLXPbufferSGIX_DMparams_DMbuffer,
    FORMAT_int_Display_int_int_Window,
    FORMAT_int_Display_int,
    FORMAT_Bool_Display_GLuint_GLuint,
    FORMAT_void_Display_GLXDrawable_int,
    FORMAT_void_Display_GLXDrawable_int_int,
    FORMAT_int_Display_unsigned_int_GLXVideoCaptureDeviceNV,
    FORMAT_int_Display_unsigned_int_unsigned_int_int,
    FORMAT_int_Display_GLXVideoDeviceNV_GLXPbuffer_int,
    FORMAT_int_Display_int_int_int_int_int_int,
    FORMAT_int_Display_int_int_GLenum,
    FORMAT_GLXFBConfigPointer_Display_int_int_int,
    FORMAT_GLXFBConfigSGIXPointer_Display_int_int_int,
    FORMAT_void_Display_GLXContext_GLuint_GLenum_GLint_GLint_GLint_GLint_GLXContext_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei,
    FORMAT_void_Display_GLXDrawable_int_int_int_int,
    FORMAT_GLXContext_Display_GLXFBConfig_GLXContext_Bool_int,
    FORMAT_GLXContext_Display_GLXFBConfigSGIX_int_GLXContext_Bool,
    FORMAT_GLXPbufferSGIX_Display_GLXFBConfigSGIX_unsigned_int_unsigned_int_int,
    FORMAT_GLXPixmap_Display_XVisualInfo_Pixmap_Colormap,
    FORMAT_GLXPixmap_Display_GLXFBConfigSGIX_Pixmap,
    FORMAT_GLXVideoSourceSGIX_Display_int_VLServer_VLPath_int_VLNode,
    FORMAT_GLXContext_Display_GLXFBConfig_int_GLXContext_Bool,
    FORMAT_GLXPbuffer_Display_GLXFBConfig_int,
    FORMAT_GLXPixmap_Display_GLXFBConfig_Pixmap_int,
    FORMAT_GLXWindow_Display_GLXFBConfig_Window_int,
    FORMAT_void_Display_Window_float,
    FORMAT_void_Display_GLXPbufferSGIX,
    FORMAT_void_Display_GLXVideoSourceSGIX,
    FORMAT_void_Display_GLXPbuffer,
    FORMAT_void_Display_GLXPixmap,
    FORMAT_void_Display_GLXWindow,
    FORMAT_GLXVideoCaptureDeviceNVPointer_Display_int_int,
    FORMAT_uintPointer_Display_int_int,
    FORMAT_void_Display_GLXContext,
    FORMAT_uint_void,
    FORMAT_GLXContextID_const_GLXContext,
    FORMAT_DisplayPointer,
    FORMAT_GLXDrawable,
    FORMAT_int_Display_GLXFBConfig_int_int,
    FORMAT_int_Display_GLXFBConfigSGIX_int_int,
    FORMAT_GLXFBConfigSGIX_Display_XVisualInfo,
    FORMAT_GLXFBConfigPointer_Display_int_int,
    FORMAT_Bool_Display_GLXDrawable_int32_t_int32_t,
    FORMAT_FunctionPointer_GLubyte,
    FORMAT_void_Display_GLXDrawable_unsigned_long,
    FORMAT_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t,
    FORMAT_Status_Display_Window_Window_long,
    FORMAT_int_Display_int_int_GLXVideoDeviceNV,
    FORMAT_int_Display_int_GLXVideoDeviceNV_unsigned_long_unsigned_long,
    FORMAT_int_unsigned_int,
    FORMAT_XVisualInfoPointer_Display_GLXFBConfig,
    FORMAT_XVisualInfoPointer_Display_GLXFBConfigSGIX,
    FORMAT_int_Display_int_int_int_void,
    FORMAT_int_Display_int_int_GLXHyperpipeConfigSGIX_int,
    FORMAT_GLXContext_Display_GLXContextID,
    FORMAT_Bool_Display_GLXDrawable_GLuint,
    FORMAT_void_Display_GLXDrawable_GLXDrawable,
    FORMAT_void_Display_GLXVideoCaptureDeviceNV,
    FORMAT_Bool_Display_GLXDrawable_GLXDrawable_GLXContext,
    FORMAT_int_Display_GLXContext_int_int,
    FORMAT_void_Display_GLXDrawable_int_unsigned_int,
    FORMAT_Bool_Display_int_GLuint,
    FORMAT_int_Display_GLXPbufferSGIX_int_unsigned_int,
    FORMAT_int_Display_int_int_int_void_void,
    FORMAT_GLXHyperpipeConfigSGIXPointer_Display_int_int,
    FORMAT_GLXHyperpipeNetworkSGIXPointer_Display_int,
    FORMAT_Bool_Display_int_int,
    FORMAT_Bool_Display_int_GLuint_GLuint,
    FORMAT_Bool_Display_GLXDrawable_GLuint_GLuint,
    FORMAT_int_Display_GLXVideoCaptureDeviceNV_int_int,
    FORMAT_Bool_Display_GLXDrawable,
    FORMAT_int_Display_int_GLXVideoDeviceNV,
    FORMAT_int_Display_GLXPbuffer,
    FORMAT_Bool_Display_int,
    FORMAT_int_Display_GLXPbuffer_int_unsigned_long_GLboolean,
    FORMAT_Bool_int,
    FORMAT_int64_t_Display_GLXDrawable_int64_t_int64_t_int64_t,
    FORMAT_int_int,
    FORMAT_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t_int64_t_int64_t_int64_t,
    FORMAT_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t_int64_t,
    FORMAT_int_int_int_unsigned_int,
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
typedef void (*FUNC_void_GLenum_GLfixed)(GLenum op, GLfixed value);
typedef struct {
    GLenum a1;
    GLfixed a2;
} ARGS_void_GLenum_GLfixed;
typedef struct {
    int format;
    FUNC_void_GLenum_GLfixed func;
    ARGS_void_GLenum_GLfixed args;
} PACKED_void_GLenum_GLfixed;
typedef void (*FUNC_void_GLuint)(GLuint program);
typedef struct {
    GLuint a1;
} ARGS_void_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint func;
    ARGS_void_GLuint args;
} PACKED_void_GLuint;
typedef void (*FUNC_void_GLuint_GLuint)(GLuint pipeline, GLuint program);
typedef struct {
    GLuint a1;
    GLuint a2;
} ARGS_void_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint func;
    ARGS_void_GLuint_GLuint args;
} PACKED_void_GLuint_GLuint;
typedef void (*FUNC_void_GLenum)(GLenum face);
typedef struct {
    GLenum a1;
} ARGS_void_GLenum;
typedef struct {
    int format;
    FUNC_void_GLenum func;
    ARGS_void_GLenum args;
} PACKED_void_GLenum;
typedef void (*FUNC_void_GLuint_GLchar)(GLuint program, GLchar name);
typedef struct {
    GLuint a1;
    GLchar a2;
} ARGS_void_GLuint_GLchar;
typedef struct {
    int format;
    FUNC_void_GLuint_GLchar func;
    ARGS_void_GLuint_GLchar args;
} PACKED_void_GLuint_GLchar;
typedef void (*FUNC_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint)(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLuint a3;
    GLuint a4;
    GLuint a5;
    GLuint a6;
} ARGS_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint func;
    ARGS_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint args;
} PACKED_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint;
typedef void (*FUNC_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint)(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLuint a3;
    GLuint a4;
    GLuint a5;
    GLuint a6;
    GLuint a7;
    GLuint a8;
    GLuint a9;
} ARGS_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint func;
    ARGS_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint args;
} PACKED_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint;
typedef void (*FUNC_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint)(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLuint a3;
    GLuint a4;
    GLuint a5;
    GLuint a6;
    GLuint a7;
    GLuint a8;
    GLuint a9;
    GLuint a10;
    GLuint a11;
    GLuint a12;
} ARGS_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint func;
    ARGS_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint args;
} PACKED_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint;
typedef Boolean (*FUNC_Boolean_GLsizei_GLuint_GLboolean)(GLsizei n, GLuint programs, GLboolean residences);
typedef struct {
    GLsizei a1;
    GLuint a2;
    GLboolean a3;
} ARGS_Boolean_GLsizei_GLuint_GLboolean;
typedef struct {
    int format;
    FUNC_Boolean_GLsizei_GLuint_GLboolean func;
    ARGS_Boolean_GLsizei_GLuint_GLboolean args;
} PACKED_Boolean_GLsizei_GLuint_GLboolean;
typedef void (*FUNC_void_GLint)(GLint i);
typedef struct {
    GLint a1;
} ARGS_void_GLint;
typedef struct {
    int format;
    FUNC_void_GLint func;
    ARGS_void_GLint args;
} PACKED_void_GLint;
typedef void (*FUNC_void_GLenum_GLint_GLenum_GLsizei_GLuint_GLuint)(GLenum array, GLint size, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
typedef struct {
    GLenum a1;
    GLint a2;
    GLenum a3;
    GLsizei a4;
    GLuint a5;
    GLuint a6;
} ARGS_void_GLenum_GLint_GLenum_GLsizei_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLenum_GLsizei_GLuint_GLuint func;
    ARGS_void_GLenum_GLint_GLenum_GLsizei_GLuint_GLuint args;
} PACKED_void_GLenum_GLint_GLenum_GLsizei_GLuint_GLuint;
typedef void (*FUNC_void_GLhandleARB_GLhandleARB)(GLhandleARB containerObj, GLhandleARB obj);
typedef struct {
    GLhandleARB a1;
    GLhandleARB a2;
} ARGS_void_GLhandleARB_GLhandleARB;
typedef struct {
    int format;
    FUNC_void_GLhandleARB_GLhandleARB func;
    ARGS_void_GLhandleARB_GLhandleARB args;
} PACKED_void_GLhandleARB_GLhandleARB;
typedef void (*FUNC_void_GLuint_GLenum)(GLuint id, GLenum mode);
typedef struct {
    GLuint a1;
    GLenum a2;
} ARGS_void_GLuint_GLenum;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum func;
    ARGS_void_GLuint_GLenum args;
} PACKED_void_GLuint_GLenum;
typedef void (*FUNC_void)();
typedef struct {
} ARGS_void;
typedef struct {
    int format;
    FUNC_void func;
    ARGS_void args;
} PACKED_void;
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
typedef void (*FUNC_void_GLenum_GLuint_GLuint)(GLenum target, GLuint index, GLuint id);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLuint a3;
} ARGS_void_GLenum_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLuint func;
    ARGS_void_GLenum_GLuint_GLuint args;
} PACKED_void_GLenum_GLuint_GLuint;
typedef void (*FUNC_void_GLuint_GLuint_GLchar)(GLuint program, GLuint index, GLchar name);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLchar a3;
} ARGS_void_GLuint_GLuint_GLchar;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLchar func;
    ARGS_void_GLuint_GLuint_GLchar args;
} PACKED_void_GLuint_GLuint_GLchar;
typedef void (*FUNC_void_GLhandleARB_GLuint_GLcharARB)(GLhandleARB programObj, GLuint index, GLcharARB name);
typedef struct {
    GLhandleARB a1;
    GLuint a2;
    GLcharARB a3;
} ARGS_void_GLhandleARB_GLuint_GLcharARB;
typedef struct {
    int format;
    FUNC_void_GLhandleARB_GLuint_GLcharARB func;
    ARGS_void_GLhandleARB_GLuint_GLcharARB args;
} PACKED_void_GLhandleARB_GLuint_GLcharARB;
typedef void (*FUNC_void_GLenum_GLuint_GLuint_GLintptr)(GLenum target, GLuint index, GLuint buffer, GLintptr offset);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLuint a3;
    GLintptr a4;
} ARGS_void_GLenum_GLuint_GLuint_GLintptr;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLuint_GLintptr func;
    ARGS_void_GLenum_GLuint_GLuint_GLintptr args;
} PACKED_void_GLenum_GLuint_GLuint_GLintptr;
typedef void (*FUNC_void_GLenum_GLuint_GLuint_GLintptr_GLsizeiptr)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLuint a3;
    GLintptr a4;
    GLsizeiptr a5;
} ARGS_void_GLenum_GLuint_GLuint_GLintptr_GLsizeiptr;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLuint_GLintptr_GLsizeiptr func;
    ARGS_void_GLenum_GLuint_GLuint_GLintptr_GLsizeiptr args;
} PACKED_void_GLenum_GLuint_GLuint_GLintptr_GLsizeiptr;
typedef void (*FUNC_void_GLuint_GLuint_GLuint_GLchar)(GLuint program, GLuint colorNumber, GLuint index, GLchar name);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLuint a3;
    GLchar a4;
} ARGS_void_GLuint_GLuint_GLuint_GLchar;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLuint_GLchar func;
    ARGS_void_GLuint_GLuint_GLuint_GLchar args;
} PACKED_void_GLuint_GLuint_GLuint_GLchar;
typedef void (*FUNC_void_GLuint_GLuint_GLint_GLboolean_GLint_GLenum_GLenum)(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLint a3;
    GLboolean a4;
    GLint a5;
    GLenum a6;
    GLenum a7;
} ARGS_void_GLuint_GLuint_GLint_GLboolean_GLint_GLenum_GLenum;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLint_GLboolean_GLint_GLenum_GLenum func;
    ARGS_void_GLuint_GLuint_GLint_GLboolean_GLint_GLenum_GLenum args;
} PACKED_void_GLuint_GLuint_GLint_GLboolean_GLint_GLenum_GLenum;
typedef void (*FUNC_void_GLuint_GLuint_GLint_GLboolean_GLint_GLenum_GLint)(GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLint a3;
    GLboolean a4;
    GLint a5;
    GLenum a6;
    GLint a7;
} ARGS_void_GLuint_GLuint_GLint_GLboolean_GLint_GLenum_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLint_GLboolean_GLint_GLenum_GLint func;
    ARGS_void_GLuint_GLuint_GLint_GLboolean_GLint_GLenum_GLint args;
} PACKED_void_GLuint_GLuint_GLint_GLboolean_GLint_GLenum_GLint;
typedef UInt32 (*FUNC_UInt32_GLenum_GLenum)(GLenum light, GLenum value);
typedef struct {
    GLenum a1;
    GLenum a2;
} ARGS_UInt32_GLenum_GLenum;
typedef struct {
    int format;
    FUNC_UInt32_GLenum_GLenum func;
    ARGS_UInt32_GLenum_GLenum args;
} PACKED_UInt32_GLenum_GLenum;
typedef void (*FUNC_void_GLenum_GLenum_GLuint)(GLenum texunit, GLenum target, GLuint texture);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLuint a3;
} ARGS_void_GLenum_GLenum_GLuint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLuint func;
    ARGS_void_GLenum_GLenum_GLuint args;
} PACKED_void_GLenum_GLenum_GLuint;
typedef UInt32 (*FUNC_UInt32_GLenum)(GLenum value);
typedef struct {
    GLenum a1;
} ARGS_UInt32_GLenum;
typedef struct {
    int format;
    FUNC_UInt32_GLenum func;
    ARGS_UInt32_GLenum args;
} PACKED_UInt32_GLenum;
typedef UInt32 (*FUNC_UInt32_GLenum_GLenum_GLenum)(GLenum unit, GLenum coord, GLenum value);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLenum a3;
} ARGS_UInt32_GLenum_GLenum_GLenum;
typedef struct {
    int format;
    FUNC_UInt32_GLenum_GLenum_GLenum func;
    ARGS_UInt32_GLenum_GLenum_GLenum args;
} PACKED_UInt32_GLenum_GLenum_GLenum;
typedef void (*FUNC_void_GLuint_GLuint_GLintptr_GLsizei)(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLintptr a3;
    GLsizei a4;
} ARGS_void_GLuint_GLuint_GLintptr_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLintptr_GLsizei func;
    ARGS_void_GLuint_GLuint_GLintptr_GLsizei args;
} PACKED_void_GLuint_GLuint_GLintptr_GLsizei;
typedef void (*FUNC_void_GLuint_GLuint_GLenum_GLintptrARB)(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLintptrARB offset);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLenum a3;
    GLintptrARB a4;
} ARGS_void_GLuint_GLuint_GLenum_GLintptrARB;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLenum_GLintptrARB func;
    ARGS_void_GLuint_GLuint_GLenum_GLintptrARB args;
} PACKED_void_GLuint_GLuint_GLenum_GLintptrARB;
typedef void (*FUNC_void_GLuint_GLuint_GLenum_GLenum_GLuint)(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLenum target, GLuint texture);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLenum a3;
    GLenum a4;
    GLuint a5;
} ARGS_void_GLuint_GLuint_GLenum_GLenum_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLenum_GLenum_GLuint func;
    ARGS_void_GLuint_GLuint_GLenum_GLenum_GLuint args;
} PACKED_void_GLuint_GLuint_GLenum_GLenum_GLuint;
typedef void (*FUNC_void_GLbyte_GLbyte_GLbyte)(GLbyte bx, GLbyte by, GLbyte bz);
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
typedef void (*FUNC_void_GLbyte)(GLbyte v);
typedef struct {
    GLbyte a1;
} ARGS_void_GLbyte;
typedef struct {
    int format;
    FUNC_void_GLbyte func;
    ARGS_void_GLbyte args;
} PACKED_void_GLbyte;
typedef void (*FUNC_void_GLdouble_GLdouble_GLdouble)(GLdouble bx, GLdouble by, GLdouble bz);
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
typedef void (*FUNC_void_GLdouble)(GLdouble v);
typedef struct {
    GLdouble a1;
} ARGS_void_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLdouble func;
    ARGS_void_GLdouble args;
} PACKED_void_GLdouble;
typedef void (*FUNC_void_GLfloat_GLfloat_GLfloat)(GLfloat bx, GLfloat by, GLfloat bz);
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
typedef void (*FUNC_void_GLfloat)(GLfloat v);
typedef struct {
    GLfloat a1;
} ARGS_void_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLfloat func;
    ARGS_void_GLfloat args;
} PACKED_void_GLfloat;
typedef void (*FUNC_void_GLint_GLint_GLint)(GLint bx, GLint by, GLint bz);
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
typedef void (*FUNC_void_GLshort_GLshort_GLshort)(GLshort bx, GLshort by, GLshort bz);
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
typedef void (*FUNC_void_GLshort)(GLshort v);
typedef struct {
    GLshort a1;
} ARGS_void_GLshort;
typedef struct {
    int format;
    FUNC_void_GLshort func;
    ARGS_void_GLshort args;
} PACKED_void_GLshort;
typedef void (*FUNC_void_GLenum_GLsizei_GLvoid)(GLenum type, GLsizei stride, GLvoid pointer);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLvoid a3;
} ARGS_void_GLenum_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLvoid func;
    ARGS_void_GLenum_GLsizei_GLvoid args;
} PACKED_void_GLenum_GLsizei_GLvoid;
typedef void (*FUNC_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_GLubyte)(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, GLubyte bitmap);
typedef struct {
    GLsizei a1;
    GLsizei a2;
    GLfloat a3;
    GLfloat a4;
    GLfloat a5;
    GLfloat a6;
    GLubyte a7;
} ARGS_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_GLubyte;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_GLubyte func;
    ARGS_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_GLubyte args;
} PACKED_void_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_GLubyte;
typedef void (*FUNC_void_GLsizei_GLsizei_GLfixed_GLfixed_GLfixed_GLfixed_GLubyte)(GLsizei width, GLsizei height, GLfixed xorig, GLfixed yorig, GLfixed xmove, GLfixed ymove, GLubyte bitmap);
typedef struct {
    GLsizei a1;
    GLsizei a2;
    GLfixed a3;
    GLfixed a4;
    GLfixed a5;
    GLfixed a6;
    GLubyte a7;
} ARGS_void_GLsizei_GLsizei_GLfixed_GLfixed_GLfixed_GLfixed_GLubyte;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLsizei_GLfixed_GLfixed_GLfixed_GLfixed_GLubyte func;
    ARGS_void_GLsizei_GLsizei_GLfixed_GLfixed_GLfixed_GLfixed_GLubyte args;
} PACKED_void_GLsizei_GLsizei_GLfixed_GLfixed_GLfixed_GLfixed_GLubyte;
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
typedef void (*FUNC_void_GLenum_GLenum)(GLenum modeRGB, GLenum modeAlpha);
typedef struct {
    GLenum a1;
    GLenum a2;
} ARGS_void_GLenum_GLenum;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum func;
    ARGS_void_GLenum_GLenum args;
} PACKED_void_GLenum_GLenum;
typedef void (*FUNC_void_GLuint_GLenum_GLenum)(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLenum a3;
} ARGS_void_GLuint_GLenum_GLenum;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLenum func;
    ARGS_void_GLuint_GLenum_GLenum args;
} PACKED_void_GLuint_GLenum_GLenum;
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
typedef void (*FUNC_void_GLuint_GLenum_GLenum_GLenum_GLenum)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLenum a3;
    GLenum a4;
    GLenum a5;
} ARGS_void_GLuint_GLenum_GLenum_GLenum_GLenum;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLenum_GLenum_GLenum func;
    ARGS_void_GLuint_GLenum_GLenum_GLenum_GLenum args;
} PACKED_void_GLuint_GLenum_GLenum_GLenum_GLenum;
typedef void (*FUNC_void_GLint_GLint_GLint_GLint_GLint_GLint_GLint_GLint_GLbitfield_GLenum)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
typedef struct {
    GLint a1;
    GLint a2;
    GLint a3;
    GLint a4;
    GLint a5;
    GLint a6;
    GLint a7;
    GLint a8;
    GLbitfield a9;
    GLenum a10;
} ARGS_void_GLint_GLint_GLint_GLint_GLint_GLint_GLint_GLint_GLbitfield_GLenum;
typedef struct {
    int format;
    FUNC_void_GLint_GLint_GLint_GLint_GLint_GLint_GLint_GLint_GLbitfield_GLenum func;
    ARGS_void_GLint_GLint_GLint_GLint_GLint_GLint_GLint_GLint_GLbitfield_GLenum args;
} PACKED_void_GLint_GLint_GLint_GLint_GLint_GLint_GLint_GLint_GLbitfield_GLenum;
typedef void (*FUNC_void_GLenum_GLuint_GLuint64EXT_GLsizeiptr)(GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLuint64EXT a3;
    GLsizeiptr a4;
} ARGS_void_GLenum_GLuint_GLuint64EXT_GLsizeiptr;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLuint64EXT_GLsizeiptr func;
    ARGS_void_GLenum_GLuint_GLuint64EXT_GLsizeiptr args;
} PACKED_void_GLenum_GLuint_GLuint64EXT_GLsizeiptr;
typedef void (*FUNC_void_GLenum_GLsizeiptr_GLvoid_GLenum)(GLenum target, GLsizeiptr size, GLvoid data, GLenum usage);
typedef struct {
    GLenum a1;
    GLsizeiptr a2;
    GLvoid a3;
    GLenum a4;
} ARGS_void_GLenum_GLsizeiptr_GLvoid_GLenum;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizeiptr_GLvoid_GLenum func;
    ARGS_void_GLenum_GLsizeiptr_GLvoid_GLenum args;
} PACKED_void_GLenum_GLsizeiptr_GLvoid_GLenum;
typedef void (*FUNC_void_GLenum_GLsizeiptrARB_GLvoid_GLenum)(GLenum target, GLsizeiptrARB size, GLvoid data, GLenum usage);
typedef struct {
    GLenum a1;
    GLsizeiptrARB a2;
    GLvoid a3;
    GLenum a4;
} ARGS_void_GLenum_GLsizeiptrARB_GLvoid_GLenum;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizeiptrARB_GLvoid_GLenum func;
    ARGS_void_GLenum_GLsizeiptrARB_GLvoid_GLenum args;
} PACKED_void_GLenum_GLsizeiptrARB_GLvoid_GLenum;
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
typedef void (*FUNC_void_GLenum_GLintptr_GLsizeiptr_GLvoid)(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid data);
typedef struct {
    GLenum a1;
    GLintptr a2;
    GLsizeiptr a3;
    GLvoid a4;
} ARGS_void_GLenum_GLintptr_GLsizeiptr_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLintptr_GLsizeiptr_GLvoid func;
    ARGS_void_GLenum_GLintptr_GLsizeiptr_GLvoid args;
} PACKED_void_GLenum_GLintptr_GLsizeiptr_GLvoid;
typedef void (*FUNC_void_GLenum_GLintptrARB_GLsizeiptrARB_GLvoid)(GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid data);
typedef struct {
    GLenum a1;
    GLintptrARB a2;
    GLsizeiptrARB a3;
    GLvoid a4;
} ARGS_void_GLenum_GLintptrARB_GLsizeiptrARB_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLintptrARB_GLsizeiptrARB_GLvoid func;
    ARGS_void_GLenum_GLintptrARB_GLsizeiptrARB_GLvoid args;
} PACKED_void_GLenum_GLintptrARB_GLsizeiptrARB_GLvoid;
typedef void (*FUNC_void_GLsizei_GLenum_GLvoid)(GLsizei n, GLenum type, GLvoid lists);
typedef struct {
    GLsizei a1;
    GLenum a2;
    GLvoid a3;
} ARGS_void_GLsizei_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLenum_GLvoid func;
    ARGS_void_GLsizei_GLenum_GLvoid args;
} PACKED_void_GLsizei_GLenum_GLvoid;
typedef GLenum (*FUNC_GLenum_GLenum)(GLenum target);
typedef struct {
    GLenum a1;
} ARGS_GLenum_GLenum;
typedef struct {
    int format;
    FUNC_GLenum_GLenum func;
    ARGS_GLenum_GLenum args;
} PACKED_GLenum_GLenum;
typedef FramebufferStatus (*FUNC_FramebufferStatus_GLuint_GLenum)(GLuint framebuffer, GLenum target);
typedef struct {
    GLuint a1;
    GLenum a2;
} ARGS_FramebufferStatus_GLuint_GLenum;
typedef struct {
    int format;
    FUNC_FramebufferStatus_GLuint_GLenum func;
    ARGS_FramebufferStatus_GLuint_GLenum args;
} PACKED_FramebufferStatus_GLuint_GLenum;
typedef void (*FUNC_void_GLbitfield)(GLbitfield mask);
typedef struct {
    GLbitfield a1;
} ARGS_void_GLbitfield;
typedef struct {
    int format;
    FUNC_void_GLbitfield func;
    ARGS_void_GLbitfield args;
} PACKED_void_GLbitfield;
typedef void (*FUNC_void_GLenum_GLenum_GLenum_GLenum_void___GENPT__)(GLenum target, GLenum internalformat, GLenum format, GLenum type, void * data);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLenum a3;
    GLenum a4;
    void * a5;
} ARGS_void_GLenum_GLenum_GLenum_GLenum_void___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLenum_GLenum_void___GENPT__ func;
    ARGS_void_GLenum_GLenum_GLenum_GLenum_void___GENPT__ args;
} PACKED_void_GLenum_GLenum_GLenum_GLenum_void___GENPT__;
typedef void (*FUNC_void_GLenum_GLenum_GLintptr_GLsizeiptr_GLenum_GLenum_void___GENPT__)(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, void * data);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLintptr a3;
    GLsizeiptr a4;
    GLenum a5;
    GLenum a6;
    void * a7;
} ARGS_void_GLenum_GLenum_GLintptr_GLsizeiptr_GLenum_GLenum_void___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLintptr_GLsizeiptr_GLenum_GLenum_void___GENPT__ func;
    ARGS_void_GLenum_GLenum_GLintptr_GLsizeiptr_GLenum_GLenum_void___GENPT__ args;
} PACKED_void_GLenum_GLenum_GLintptr_GLsizeiptr_GLenum_GLenum_void___GENPT__;
typedef void (*FUNC_void_GLenum_GLint_GLfloat_GLint)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
typedef struct {
    GLenum a1;
    GLint a2;
    GLfloat a3;
    GLint a4;
} ARGS_void_GLenum_GLint_GLfloat_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLfloat_GLint func;
    ARGS_void_GLenum_GLint_GLfloat_GLint args;
} PACKED_void_GLenum_GLint_GLfloat_GLint;
typedef void (*FUNC_void_GLenum_GLint_GLfloat)(GLenum buffer, GLint drawbuffer, GLfloat value);
typedef struct {
    GLenum a1;
    GLint a2;
    GLfloat a3;
} ARGS_void_GLenum_GLint_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLfloat func;
    ARGS_void_GLenum_GLint_GLfloat args;
} PACKED_void_GLenum_GLint_GLfloat;
typedef void (*FUNC_void_GLenum_GLint_GLint)(GLenum buffer, GLint drawbuffer, GLint value);
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
typedef void (*FUNC_void_GLenum_GLint_GLuint)(GLenum buffer, GLint drawbuffer, GLuint value);
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
typedef void (*FUNC_void_GLclampf)(GLclampf depth);
typedef struct {
    GLclampf a1;
} ARGS_void_GLclampf;
typedef struct {
    int format;
    FUNC_void_GLclampf func;
    ARGS_void_GLclampf args;
} PACKED_void_GLclampf;
typedef void (*FUNC_void_GLfixed)(GLfixed depth);
typedef struct {
    GLfixed a1;
} ARGS_void_GLfixed;
typedef struct {
    int format;
    FUNC_void_GLfixed func;
    ARGS_void_GLfixed args;
} PACKED_void_GLfixed;
typedef void (*FUNC_void_GLuint_GLenum_GLenum_GLenum_void___GENPT__)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, void * data);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLenum a3;
    GLenum a4;
    void * a5;
} ARGS_void_GLuint_GLenum_GLenum_GLenum_void___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLenum_GLenum_void___GENPT__ func;
    ARGS_void_GLuint_GLenum_GLenum_GLenum_void___GENPT__ args;
} PACKED_void_GLuint_GLenum_GLenum_GLenum_void___GENPT__;
typedef void (*FUNC_void_GLuint_GLenum_GLenum_GLenum_GLsizeiptr_GLsizeiptr_void___GENPT__)(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, GLsizeiptr offset, GLsizeiptr size, void * data);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLenum a3;
    GLenum a4;
    GLsizeiptr a5;
    GLsizeiptr a6;
    void * a7;
} ARGS_void_GLuint_GLenum_GLenum_GLenum_GLsizeiptr_GLsizeiptr_void___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLenum_GLenum_GLsizeiptr_GLsizeiptr_void___GENPT__ func;
    ARGS_void_GLuint_GLenum_GLenum_GLenum_GLsizeiptr_GLsizeiptr_void___GENPT__ args;
} PACKED_void_GLuint_GLenum_GLenum_GLenum_GLsizeiptr_GLsizeiptr_void___GENPT__;
typedef GLenum (*FUNC_GLenum_GLsync_GLbitfield_GLuint64)(GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef struct {
    GLsync a1;
    GLbitfield a2;
    GLuint64 a3;
} ARGS_GLenum_GLsync_GLbitfield_GLuint64;
typedef struct {
    int format;
    FUNC_GLenum_GLsync_GLbitfield_GLuint64 func;
    ARGS_GLenum_GLsync_GLbitfield_GLuint64 args;
} PACKED_GLenum_GLsync_GLbitfield_GLuint64;
typedef void (*FUNC_void_GLenum_GLdouble)(GLenum plane, GLdouble equation);
typedef struct {
    GLenum a1;
    GLdouble a2;
} ARGS_void_GLenum_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLenum_GLdouble func;
    ARGS_void_GLenum_GLdouble args;
} PACKED_void_GLenum_GLdouble;
typedef void (*FUNC_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat)(GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
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
typedef void (*FUNC_void_GLfloat_GLfloat)(GLfloat c, GLfloat v);
typedef struct {
    GLfloat a1;
    GLfloat a2;
} ARGS_void_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLfloat_GLfloat func;
    ARGS_void_GLfloat_GLfloat args;
} PACKED_void_GLfloat_GLfloat;
typedef void (*FUNC_void_GLhalfNV_GLhalfNV_GLhalfNV)(GLhalfNV red, GLhalfNV green, GLhalfNV blue);
typedef struct {
    GLhalfNV a1;
    GLhalfNV a2;
    GLhalfNV a3;
} ARGS_void_GLhalfNV_GLhalfNV_GLhalfNV;
typedef struct {
    int format;
    FUNC_void_GLhalfNV_GLhalfNV_GLhalfNV func;
    ARGS_void_GLhalfNV_GLhalfNV_GLhalfNV args;
} PACKED_void_GLhalfNV_GLhalfNV_GLhalfNV;
typedef void (*FUNC_void_GLhalfNV)(GLhalfNV v);
typedef struct {
    GLhalfNV a1;
} ARGS_void_GLhalfNV;
typedef struct {
    int format;
    FUNC_void_GLhalfNV func;
    ARGS_void_GLhalfNV args;
} PACKED_void_GLhalfNV;
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
typedef void (*FUNC_void_GLubyte)(GLubyte v);
typedef struct {
    GLubyte a1;
} ARGS_void_GLubyte;
typedef struct {
    int format;
    FUNC_void_GLubyte func;
    ARGS_void_GLubyte args;
} PACKED_void_GLubyte;
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
typedef void (*FUNC_void_GLushort)(GLushort v);
typedef struct {
    GLushort a1;
} ARGS_void_GLushort;
typedef struct {
    int format;
    FUNC_void_GLushort func;
    ARGS_void_GLushort args;
} PACKED_void_GLushort;
typedef void (*FUNC_void_GLfixed_GLfixed_GLfixed)(GLfixed red, GLfixed green, GLfixed blue);
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
typedef void (*FUNC_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat)(GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
typedef struct {
    GLfloat a1;
    GLfloat a2;
    GLfloat a3;
    GLfloat a4;
    GLfloat a5;
    GLfloat a6;
    GLfloat a7;
    GLfloat a8;
    GLfloat a9;
    GLfloat a10;
} ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV)(GLhalfNV red, GLhalfNV green, GLhalfNV blue, GLhalfNV alpha);
typedef struct {
    GLhalfNV a1;
    GLhalfNV a2;
    GLhalfNV a3;
    GLhalfNV a4;
} ARGS_void_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV;
typedef struct {
    int format;
    FUNC_void_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV func;
    ARGS_void_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV args;
} PACKED_void_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV;
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
typedef void (*FUNC_void_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat)(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y);
typedef struct {
    GLubyte a1;
    GLubyte a2;
    GLubyte a3;
    GLubyte a4;
    GLfloat a5;
    GLfloat a6;
} ARGS_void_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat func;
    ARGS_void_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat args;
} PACKED_void_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat;
typedef void (*FUNC_void_GLubyte_GLfloat)(GLubyte c, GLfloat v);
typedef struct {
    GLubyte a1;
    GLfloat a2;
} ARGS_void_GLubyte_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLubyte_GLfloat func;
    ARGS_void_GLubyte_GLfloat args;
} PACKED_void_GLubyte_GLfloat;
typedef void (*FUNC_void_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat)(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
typedef struct {
    GLubyte a1;
    GLubyte a2;
    GLubyte a3;
    GLubyte a4;
    GLfloat a5;
    GLfloat a6;
    GLfloat a7;
} ARGS_void_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat;
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
typedef void (*FUNC_void_GLint_GLenum_GLsizei)(GLint size, GLenum type, GLsizei stride);
typedef struct {
    GLint a1;
    GLenum a2;
    GLsizei a3;
} ARGS_void_GLint_GLenum_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLint_GLenum_GLsizei func;
    ARGS_void_GLint_GLenum_GLsizei args;
} PACKED_void_GLint_GLenum_GLsizei;
typedef void (*FUNC_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint)(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLuint a3;
    GLuint a4;
    GLuint a5;
    GLuint a6;
    GLuint a7;
} ARGS_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint func;
    ARGS_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint args;
} PACKED_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint;
typedef void (*FUNC_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint)(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLuint a3;
    GLuint a4;
    GLuint a5;
    GLuint a6;
    GLuint a7;
    GLuint a8;
    GLuint a9;
    GLuint a10;
} ARGS_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint func;
    ARGS_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint args;
} PACKED_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint;
typedef void (*FUNC_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint)(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLuint a3;
    GLuint a4;
    GLuint a5;
    GLuint a6;
    GLuint a7;
    GLuint a8;
    GLuint a9;
    GLuint a10;
    GLuint a11;
    GLuint a12;
    GLuint a13;
} ARGS_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint func;
    ARGS_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint args;
} PACKED_void_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint_GLuint;
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
typedef void (*FUNC_void_GLuint_GLboolean_GLboolean_GLboolean_GLboolean)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
typedef struct {
    GLuint a1;
    GLboolean a2;
    GLboolean a3;
    GLboolean a4;
    GLboolean a5;
} ARGS_void_GLuint_GLboolean_GLboolean_GLboolean_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLuint_GLboolean_GLboolean_GLboolean_GLboolean func;
    ARGS_void_GLuint_GLboolean_GLboolean_GLboolean_GLboolean args;
} PACKED_void_GLuint_GLboolean_GLboolean_GLboolean_GLboolean;
typedef void (*FUNC_void_GLint_GLenum_GLsizei_GLvoid)(GLint size, GLenum type, GLsizei stride, GLvoid pointer);
typedef struct {
    GLint a1;
    GLenum a2;
    GLsizei a3;
    GLvoid a4;
} ARGS_void_GLint_GLenum_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLint_GLenum_GLsizei_GLvoid func;
    ARGS_void_GLint_GLenum_GLsizei_GLvoid args;
} PACKED_void_GLint_GLenum_GLsizei_GLvoid;
typedef void (*FUNC_void_GLint_GLenum_GLsizei_GLsizei_GLvoid)(GLint size, GLenum type, GLsizei stride, GLsizei count, GLvoid pointer);
typedef struct {
    GLint a1;
    GLenum a2;
    GLsizei a3;
    GLsizei a4;
    GLvoid a5;
} ARGS_void_GLint_GLenum_GLsizei_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLint_GLenum_GLsizei_GLsizei_GLvoid func;
    ARGS_void_GLint_GLenum_GLsizei_GLsizei_GLvoid args;
} PACKED_void_GLint_GLenum_GLsizei_GLsizei_GLvoid;
typedef void (*FUNC_void_GLint_GLenum_GLint_GLvoid___GENPT___GLint)(GLint size, GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride);
typedef struct {
    GLint a1;
    GLenum a2;
    GLint a3;
    GLvoid * a4;
    GLint a5;
} ARGS_void_GLint_GLenum_GLint_GLvoid___GENPT___GLint;
typedef struct {
    int format;
    FUNC_void_GLint_GLenum_GLint_GLvoid___GENPT___GLint func;
    ARGS_void_GLint_GLenum_GLint_GLvoid___GENPT___GLint args;
} PACKED_void_GLint_GLenum_GLint_GLvoid___GENPT___GLint;
typedef void (*FUNC_void_GLint_GLenum_GLvoid___GENPT__)(GLint size, GLenum type, GLvoid * pointer);
typedef struct {
    GLint a1;
    GLenum a2;
    GLvoid * a3;
} ARGS_void_GLint_GLenum_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLint_GLenum_GLvoid___GENPT__ func;
    ARGS_void_GLint_GLenum_GLvoid___GENPT__ args;
} PACKED_void_GLint_GLenum_GLvoid___GENPT__;
typedef void (*FUNC_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid)(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, GLvoid data);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLsizei a3;
    GLenum a4;
    GLenum a5;
    GLvoid a6;
} ARGS_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid func;
    ARGS_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid args;
} PACKED_void_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLenum_GLenum_GLsizei_GLenum_GLenum_GLvoid)(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, GLvoid table);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLsizei a3;
    GLenum a4;
    GLenum a5;
    GLvoid a6;
} ARGS_void_GLenum_GLenum_GLsizei_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLsizei_GLenum_GLenum_GLvoid func;
    ARGS_void_GLenum_GLenum_GLsizei_GLenum_GLenum_GLvoid args;
} PACKED_void_GLenum_GLenum_GLsizei_GLenum_GLenum_GLvoid;
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
typedef void (*FUNC_void_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum)(GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLenum a3;
    GLenum a4;
    GLenum a5;
    GLenum a6;
} ARGS_void_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum func;
    ARGS_void_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum args;
} PACKED_void_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum;
typedef void (*FUNC_void_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum_GLboolean_GLboolean_GLboolean)(GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLenum a3;
    GLenum a4;
    GLenum a5;
    GLenum a6;
    GLenum a7;
    GLboolean a8;
    GLboolean a9;
    GLboolean a10;
} ARGS_void_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum_GLboolean_GLboolean_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum_GLboolean_GLboolean_GLboolean func;
    ARGS_void_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum_GLboolean_GLboolean_GLboolean args;
} PACKED_void_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum_GLenum_GLboolean_GLboolean_GLboolean;
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
typedef void (*FUNC_void_GLhandleARB)(GLhandleARB shaderObj);
typedef struct {
    GLhandleARB a1;
} ARGS_void_GLhandleARB;
typedef struct {
    int format;
    FUNC_void_GLhandleARB func;
    ARGS_void_GLhandleARB args;
} PACKED_void_GLhandleARB;
typedef void (*FUNC_void_GLuint_GLsizei_GLchar___GENPT___GLint)(GLuint shader, GLsizei count, GLchar * path, GLint length);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLchar * a3;
    GLint a4;
} ARGS_void_GLuint_GLsizei_GLchar___GENPT___GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLchar___GENPT___GLint func;
    ARGS_void_GLuint_GLsizei_GLchar___GENPT___GLint args;
} PACKED_void_GLuint_GLsizei_GLchar___GENPT___GLint;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid bits);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLenum a4;
    GLsizei a5;
    GLint a6;
    GLsizei a7;
    GLvoid a8;
} ARGS_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid func;
    ARGS_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid args;
} PACKED_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid bits);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLenum a4;
    GLsizei a5;
    GLsizei a6;
    GLint a7;
    GLsizei a8;
    GLvoid a9;
} ARGS_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid func;
    ARGS_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid args;
} PACKED_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid bits);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLenum a4;
    GLsizei a5;
    GLsizei a6;
    GLsizei a7;
    GLint a8;
    GLsizei a9;
    GLvoid a10;
} ARGS_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid func;
    ARGS_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid args;
} PACKED_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid bits);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLint a4;
    GLsizei a5;
    GLenum a6;
    GLsizei a7;
    GLvoid a8;
} ARGS_void_GLenum_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid func;
    ARGS_void_GLenum_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid args;
} PACKED_void_GLenum_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid bits);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLint a4;
    GLint a5;
    GLsizei a6;
    GLsizei a7;
    GLenum a8;
    GLsizei a9;
    GLvoid a10;
} ARGS_void_GLenum_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid func;
    ARGS_void_GLenum_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid args;
} PACKED_void_GLenum_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid bits);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLint a4;
    GLint a5;
    GLint a6;
    GLsizei a7;
    GLsizei a8;
    GLsizei a9;
    GLenum a10;
    GLsizei a11;
    GLvoid a12;
} ARGS_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid func;
    ARGS_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid args;
} PACKED_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid;
typedef void (*FUNC_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid data);
typedef struct {
    GLenum a1;
    GLint a2;
    GLenum a3;
    GLsizei a4;
    GLint a5;
    GLsizei a6;
    GLvoid a7;
} ARGS_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid func;
    ARGS_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid args;
} PACKED_void_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid;
typedef void (*FUNC_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid data);
typedef struct {
    GLenum a1;
    GLint a2;
    GLenum a3;
    GLsizei a4;
    GLsizei a5;
    GLint a6;
    GLsizei a7;
    GLvoid a8;
} ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid func;
    ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid args;
} PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid;
typedef void (*FUNC_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid data);
typedef struct {
    GLenum a1;
    GLint a2;
    GLenum a3;
    GLsizei a4;
    GLsizei a5;
    GLsizei a6;
    GLint a7;
    GLsizei a8;
    GLvoid a9;
} ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid func;
    ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid args;
} PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid;
typedef void (*FUNC_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid data);
typedef struct {
    GLenum a1;
    GLint a2;
    GLint a3;
    GLsizei a4;
    GLenum a5;
    GLsizei a6;
    GLvoid a7;
} ARGS_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid func;
    ARGS_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid args;
} PACKED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid;
typedef void (*FUNC_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid data);
typedef struct {
    GLenum a1;
    GLint a2;
    GLint a3;
    GLint a4;
    GLsizei a5;
    GLsizei a6;
    GLenum a7;
    GLsizei a8;
    GLvoid a9;
} ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid func;
    ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid args;
} PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid;
typedef void (*FUNC_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid data);
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
    GLvoid a11;
} ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid func;
    ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid args;
} PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid;
typedef void (*FUNC_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid bits);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint a3;
    GLenum a4;
    GLsizei a5;
    GLint a6;
    GLsizei a7;
    GLvoid a8;
} ARGS_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid func;
    ARGS_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid args;
} PACKED_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLint_GLsizei_GLvoid;
typedef void (*FUNC_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid bits);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint a3;
    GLenum a4;
    GLsizei a5;
    GLsizei a6;
    GLint a7;
    GLsizei a8;
    GLvoid a9;
} ARGS_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid func;
    ARGS_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid args;
} PACKED_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLvoid;
typedef void (*FUNC_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid bits);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint a3;
    GLenum a4;
    GLsizei a5;
    GLsizei a6;
    GLsizei a7;
    GLint a8;
    GLsizei a9;
    GLvoid a10;
} ARGS_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid func;
    ARGS_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid args;
} PACKED_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLsizei_GLvoid;
typedef void (*FUNC_void_GLuint_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid bits);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint a3;
    GLint a4;
    GLsizei a5;
    GLenum a6;
    GLsizei a7;
    GLvoid a8;
} ARGS_void_GLuint_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid func;
    ARGS_void_GLuint_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid args;
} PACKED_void_GLuint_GLenum_GLint_GLint_GLsizei_GLenum_GLsizei_GLvoid;
typedef void (*FUNC_void_GLuint_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid bits);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint a3;
    GLint a4;
    GLint a5;
    GLsizei a6;
    GLsizei a7;
    GLenum a8;
    GLsizei a9;
    GLvoid a10;
} ARGS_void_GLuint_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid func;
    ARGS_void_GLuint_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid args;
} PACKED_void_GLuint_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLsizei_GLvoid;
typedef void (*FUNC_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid bits);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint a3;
    GLint a4;
    GLint a5;
    GLint a6;
    GLsizei a7;
    GLsizei a8;
    GLsizei a9;
    GLenum a10;
    GLsizei a11;
    GLvoid a12;
} ARGS_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid func;
    ARGS_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid args;
} PACKED_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLsizei_GLvoid;
typedef void (*FUNC_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid image);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLsizei a3;
    GLsizei a4;
    GLenum a5;
    GLenum a6;
    GLvoid a7;
} ARGS_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid func;
    ARGS_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid args;
} PACKED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLenum_GLenum_GLfixed)(GLenum target, GLenum pname, GLfixed param);
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
typedef void (*FUNC_void_GLenum_GLenum_GLintptr_GLintptr_GLsizeiptr)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLintptr a3;
    GLintptr a4;
    GLsizeiptr a5;
} ARGS_void_GLenum_GLenum_GLintptr_GLintptr_GLsizeiptr;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLintptr_GLintptr_GLsizeiptr func;
    ARGS_void_GLenum_GLenum_GLintptr_GLintptr_GLsizeiptr args;
} PACKED_void_GLenum_GLenum_GLintptr_GLintptr_GLsizeiptr;
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
typedef void (*FUNC_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei)(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint a3;
    GLint a4;
    GLint a5;
    GLint a6;
    GLuint a7;
    GLenum a8;
    GLint a9;
    GLint a10;
    GLint a11;
    GLint a12;
    GLsizei a13;
    GLsizei a14;
    GLsizei a15;
} ARGS_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei func;
    ARGS_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei args;
} PACKED_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLenum a4;
    GLint a5;
    GLint a6;
    GLsizei a7;
    GLint a8;
} ARGS_void_GLenum_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint func;
    ARGS_void_GLenum_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint args;
} PACKED_void_GLenum_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLenum a4;
    GLint a5;
    GLint a6;
    GLsizei a7;
    GLsizei a8;
    GLint a9;
} ARGS_void_GLenum_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint func;
    ARGS_void_GLenum_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint args;
} PACKED_void_GLenum_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLint a4;
    GLint a5;
    GLint a6;
    GLsizei a7;
} ARGS_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei func;
    ARGS_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei args;
} PACKED_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLint a4;
    GLint a5;
    GLint a6;
    GLint a7;
    GLsizei a8;
    GLsizei a9;
} ARGS_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei func;
    ARGS_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei args;
} PACKED_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLint a4;
    GLint a5;
    GLint a6;
    GLint a7;
    GLint a8;
    GLsizei a9;
    GLsizei a10;
} ARGS_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei func;
    ARGS_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei args;
} PACKED_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei;
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
typedef void (*FUNC_void_GLuint_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint a3;
    GLenum a4;
    GLint a5;
    GLint a6;
    GLsizei a7;
    GLint a8;
} ARGS_void_GLuint_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint func;
    ARGS_void_GLuint_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint args;
} PACKED_void_GLuint_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLint;
typedef void (*FUNC_void_GLuint_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint a3;
    GLenum a4;
    GLint a5;
    GLint a6;
    GLsizei a7;
    GLsizei a8;
    GLint a9;
} ARGS_void_GLuint_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint func;
    ARGS_void_GLuint_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint args;
} PACKED_void_GLuint_GLenum_GLint_GLenum_GLint_GLint_GLsizei_GLsizei_GLint;
typedef void (*FUNC_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint a3;
    GLint a4;
    GLint a5;
    GLint a6;
    GLsizei a7;
} ARGS_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei func;
    ARGS_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei args;
} PACKED_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei;
typedef void (*FUNC_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint a3;
    GLint a4;
    GLint a5;
    GLint a6;
    GLint a7;
    GLsizei a8;
    GLsizei a9;
} ARGS_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei func;
    ARGS_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei args;
} PACKED_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei;
typedef void (*FUNC_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint a3;
    GLint a4;
    GLint a5;
    GLint a6;
    GLint a7;
    GLint a8;
    GLsizei a9;
    GLsizei a10;
} ARGS_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei func;
    ARGS_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei args;
} PACKED_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei;
typedef void (*FUNC_void_GLsizei_GLenum_GLvoid_GLuint_GLenum_GLenum_GLfloat)(GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLenum coverMode, GLenum transformType, GLfloat transformValues);
typedef struct {
    GLsizei a1;
    GLenum a2;
    GLvoid a3;
    GLuint a4;
    GLenum a5;
    GLenum a6;
    GLfloat a7;
} ARGS_void_GLsizei_GLenum_GLvoid_GLuint_GLenum_GLenum_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLenum_GLvoid_GLuint_GLenum_GLenum_GLfloat func;
    ARGS_void_GLsizei_GLenum_GLvoid_GLuint_GLenum_GLenum_GLfloat args;
} PACKED_void_GLsizei_GLenum_GLvoid_GLuint_GLenum_GLenum_GLfloat;
typedef UInt32 (*FUNC_UInt32)();
typedef struct {
} ARGS_UInt32;
typedef struct {
    int format;
    FUNC_UInt32 func;
    ARGS_UInt32 args;
} PACKED_UInt32;
typedef handleARB (*FUNC_handleARB)();
typedef struct {
} ARGS_handleARB;
typedef struct {
    int format;
    FUNC_handleARB func;
    ARGS_handleARB args;
} PACKED_handleARB;
typedef handleARB (*FUNC_handleARB_GLenum)(GLenum shaderType);
typedef struct {
    GLenum a1;
} ARGS_handleARB_GLenum;
typedef struct {
    int format;
    FUNC_handleARB_GLenum func;
    ARGS_handleARB_GLenum args;
} PACKED_handleARB_GLenum;
typedef UInt32 (*FUNC_UInt32_GLenum_GLchar)(GLenum type, GLchar string);
typedef struct {
    GLenum a1;
    GLchar a2;
} ARGS_UInt32_GLenum_GLchar;
typedef struct {
    int format;
    FUNC_UInt32_GLenum_GLchar func;
    ARGS_UInt32_GLenum_GLchar args;
} PACKED_UInt32_GLenum_GLchar;
typedef UInt32 (*FUNC_UInt32_GLenum_GLsizei_GLchar__GENPT__const)(GLenum type, GLsizei count, GLchar*const strings);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLchar*const a3;
} ARGS_UInt32_GLenum_GLsizei_GLchar__GENPT__const;
typedef struct {
    int format;
    FUNC_UInt32_GLenum_GLsizei_GLchar__GENPT__const func;
    ARGS_UInt32_GLenum_GLsizei_GLchar__GENPT__const args;
} PACKED_UInt32_GLenum_GLsizei_GLchar__GENPT__const;
typedef sync (*FUNC_sync_struct__cl_context___GENPT___struct__cl_event___GENPT___GLbitfield)(struct _cl_context * context, struct _cl_event * event, GLbitfield flags);
typedef struct {
    struct _cl_context * a1;
    struct _cl_event * a2;
    GLbitfield a3;
} ARGS_sync_struct__cl_context___GENPT___struct__cl_event___GENPT___GLbitfield;
typedef struct {
    int format;
    FUNC_sync_struct__cl_context___GENPT___struct__cl_event___GENPT___GLbitfield func;
    ARGS_sync_struct__cl_context___GENPT___struct__cl_event___GENPT___GLbitfield args;
} PACKED_sync_struct__cl_context___GENPT___struct__cl_event___GENPT___GLbitfield;
typedef void (*FUNC_void_GLDEBUGPROC_void___GENPT__)(GLDEBUGPROC callback, void * userParam);
typedef struct {
    GLDEBUGPROC a1;
    void * a2;
} ARGS_void_GLDEBUGPROC_void___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLDEBUGPROC_void___GENPT__ func;
    ARGS_void_GLDEBUGPROC_void___GENPT__ args;
} PACKED_void_GLDEBUGPROC_void___GENPT__;
typedef void (*FUNC_void_GLDEBUGPROCAMD_GLvoid)(GLDEBUGPROCAMD callback, GLvoid userParam);
typedef struct {
    GLDEBUGPROCAMD a1;
    GLvoid a2;
} ARGS_void_GLDEBUGPROCAMD_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLDEBUGPROCAMD_GLvoid func;
    ARGS_void_GLDEBUGPROCAMD_GLvoid args;
} PACKED_void_GLDEBUGPROCAMD_GLvoid;
typedef void (*FUNC_void_GLDEBUGPROCARB_GLvoid)(GLDEBUGPROCARB callback, GLvoid userParam);
typedef struct {
    GLDEBUGPROCARB a1;
    GLvoid a2;
} ARGS_void_GLDEBUGPROCARB_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLDEBUGPROCARB_GLvoid func;
    ARGS_void_GLDEBUGPROCARB_GLvoid args;
} PACKED_void_GLDEBUGPROCARB_GLvoid;
typedef void (*FUNC_void_GLenum_GLenum_GLenum_GLsizei_GLuint_GLboolean)(GLenum source, GLenum type, GLenum severity, GLsizei count, GLuint ids, GLboolean enabled);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLenum a3;
    GLsizei a4;
    GLuint a5;
    GLboolean a6;
} ARGS_void_GLenum_GLenum_GLenum_GLsizei_GLuint_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLenum_GLsizei_GLuint_GLboolean func;
    ARGS_void_GLenum_GLenum_GLenum_GLsizei_GLuint_GLboolean args;
} PACKED_void_GLenum_GLenum_GLenum_GLsizei_GLuint_GLboolean;
typedef void (*FUNC_void_GLenum_GLenum_GLsizei_GLuint_GLboolean)(GLenum category, GLenum severity, GLsizei count, GLuint ids, GLboolean enabled);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLsizei a3;
    GLuint a4;
    GLboolean a5;
} ARGS_void_GLenum_GLenum_GLsizei_GLuint_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLsizei_GLuint_GLboolean func;
    ARGS_void_GLenum_GLenum_GLsizei_GLuint_GLboolean args;
} PACKED_void_GLenum_GLenum_GLsizei_GLuint_GLboolean;
typedef void (*FUNC_void_GLenum_GLenum_GLuint_GLenum_GLsizei_GLchar)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, GLchar buf);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLuint a3;
    GLenum a4;
    GLsizei a5;
    GLchar a6;
} ARGS_void_GLenum_GLenum_GLuint_GLenum_GLsizei_GLchar;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLuint_GLenum_GLsizei_GLchar func;
    ARGS_void_GLenum_GLenum_GLuint_GLenum_GLsizei_GLchar args;
} PACKED_void_GLenum_GLenum_GLuint_GLenum_GLsizei_GLchar;
typedef void (*FUNC_void_GLenum_GLenum_GLuint_GLsizei_GLchar)(GLenum category, GLenum severity, GLuint id, GLsizei length, GLchar buf);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLuint a3;
    GLsizei a4;
    GLchar a5;
} ARGS_void_GLenum_GLenum_GLuint_GLsizei_GLchar;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLuint_GLsizei_GLchar func;
    ARGS_void_GLenum_GLenum_GLuint_GLsizei_GLchar args;
} PACKED_void_GLenum_GLenum_GLuint_GLsizei_GLchar;
typedef void (*FUNC_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble w1, GLdouble w2, GLint wstride, GLint worder, GLdouble points);
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
    GLdouble a10;
    GLdouble a11;
    GLint a12;
    GLint a13;
    GLdouble a14;
} ARGS_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble func;
    ARGS_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble args;
} PACKED_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble;
typedef void (*FUNC_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat w1, GLfloat w2, GLint wstride, GLint worder, GLfloat points);
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
    GLfloat a10;
    GLfloat a11;
    GLint a12;
    GLint a13;
    GLfloat a14;
} ARGS_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat func;
    ARGS_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat args;
} PACKED_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat;
typedef void (*FUNC_void_GLuint_GLsizei)(GLuint marker, GLsizei range);
typedef struct {
    GLuint a1;
    GLsizei a2;
} ARGS_void_GLuint_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei func;
    ARGS_void_GLuint_GLsizei args;
} PACKED_void_GLuint_GLsizei;
typedef void (*FUNC_void_GLsizei_GLuint)(GLsizei n, GLuint buffers);
typedef struct {
    GLsizei a1;
    GLuint a2;
} ARGS_void_GLsizei_GLuint;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLuint func;
    ARGS_void_GLsizei_GLuint args;
} PACKED_void_GLsizei_GLuint;
typedef void (*FUNC_void_GLint_GLchar)(GLint namelen, GLchar name);
typedef struct {
    GLint a1;
    GLchar a2;
} ARGS_void_GLint_GLchar;
typedef struct {
    int format;
    FUNC_void_GLint_GLchar func;
    ARGS_void_GLint_GLchar args;
} PACKED_void_GLint_GLchar;
typedef void (*FUNC_void_GLsync)(GLsync sync);
typedef struct {
    GLsync a1;
} ARGS_void_GLsync;
typedef struct {
    int format;
    FUNC_void_GLsync func;
    ARGS_void_GLsync args;
} PACKED_void_GLsync;
typedef void (*FUNC_void_GLclampd_GLclampd)(GLclampd zmin, GLclampd zmax);
typedef struct {
    GLclampd a1;
    GLclampd a2;
} ARGS_void_GLclampd_GLclampd;
typedef struct {
    int format;
    FUNC_void_GLclampd_GLclampd func;
    ARGS_void_GLclampd_GLclampd args;
} PACKED_void_GLclampd_GLclampd;
typedef void (*FUNC_void_GLdouble_GLdouble)(GLdouble zmin, GLdouble zmax);
typedef struct {
    GLdouble a1;
    GLdouble a2;
} ARGS_void_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLdouble_GLdouble func;
    ARGS_void_GLdouble_GLdouble args;
} PACKED_void_GLdouble_GLdouble;
typedef void (*FUNC_void_GLboolean)(GLboolean flag);
typedef struct {
    GLboolean a1;
} ARGS_void_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLboolean func;
    ARGS_void_GLboolean args;
} PACKED_void_GLboolean;
typedef void (*FUNC_void_GLuint_GLsizei_GLdouble)(GLuint first, GLsizei count, GLdouble v);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLdouble a3;
} ARGS_void_GLuint_GLsizei_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLdouble func;
    ARGS_void_GLuint_GLsizei_GLdouble args;
} PACKED_void_GLuint_GLsizei_GLdouble;
typedef void (*FUNC_void_GLuint_GLdouble_GLdouble)(GLuint index, GLdouble n, GLdouble f);
typedef struct {
    GLuint a1;
    GLdouble a2;
    GLdouble a3;
} ARGS_void_GLuint_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLuint_GLdouble_GLdouble func;
    ARGS_void_GLuint_GLdouble_GLdouble args;
} PACKED_void_GLuint_GLdouble_GLdouble;
typedef void (*FUNC_void_GLclampf_GLclampf)(GLclampf n, GLclampf f);
typedef struct {
    GLclampf a1;
    GLclampf a2;
} ARGS_void_GLclampf_GLclampf;
typedef struct {
    int format;
    FUNC_void_GLclampf_GLclampf func;
    ARGS_void_GLclampf_GLclampf args;
} PACKED_void_GLclampf_GLclampf;
typedef void (*FUNC_void_GLfixed_GLfixed)(GLfixed n, GLfixed f);
typedef struct {
    GLfixed a1;
    GLfixed a2;
} ARGS_void_GLfixed_GLfixed;
typedef struct {
    int format;
    FUNC_void_GLfixed_GLfixed func;
    ARGS_void_GLfixed_GLfixed args;
} PACKED_void_GLfixed_GLfixed;
typedef void (*FUNC_void_GLenum_GLsizei_GLfloat)(GLenum target, GLsizei n, GLfloat points);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLfloat a3;
} ARGS_void_GLenum_GLsizei_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLfloat func;
    ARGS_void_GLenum_GLsizei_GLfloat args;
} PACKED_void_GLenum_GLsizei_GLfloat;
typedef void (*FUNC_void_GLintptr)(GLintptr indirect);
typedef struct {
    GLintptr a1;
} ARGS_void_GLintptr;
typedef struct {
    int format;
    FUNC_void_GLintptr func;
    ARGS_void_GLintptr args;
} PACKED_void_GLintptr;
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
typedef void (*FUNC_void_GLenum_GLvoid)(GLenum mode, GLvoid indirect);
typedef struct {
    GLenum a1;
    GLvoid a2;
} ARGS_void_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLvoid func;
    ARGS_void_GLenum_GLvoid args;
} PACKED_void_GLenum_GLvoid;
typedef void (*FUNC_void_GLenum_GLint_GLsizei_GLsizei)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
typedef struct {
    GLenum a1;
    GLint a2;
    GLsizei a3;
    GLsizei a4;
} ARGS_void_GLenum_GLint_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLsizei_GLsizei func;
    ARGS_void_GLenum_GLint_GLsizei_GLsizei args;
} PACKED_void_GLenum_GLint_GLsizei_GLsizei;
typedef void (*FUNC_void_GLenum_GLint_GLsizei_GLsizei_GLuint)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
typedef struct {
    GLenum a1;
    GLint a2;
    GLsizei a3;
    GLsizei a4;
    GLuint a5;
} ARGS_void_GLenum_GLint_GLsizei_GLsizei_GLuint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLsizei_GLsizei_GLuint func;
    ARGS_void_GLenum_GLint_GLsizei_GLsizei_GLuint args;
} PACKED_void_GLenum_GLint_GLsizei_GLsizei_GLuint;
typedef void (*FUNC_void_GLsizei_GLenum)(GLsizei n, GLenum bufs);
typedef struct {
    GLsizei a1;
    GLenum a2;
} ARGS_void_GLsizei_GLenum;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLenum func;
    ARGS_void_GLsizei_GLenum args;
} PACKED_void_GLsizei_GLenum;
typedef void (*FUNC_void_GLenum_GLsizei)(GLenum mode, GLsizei count);
typedef struct {
    GLenum a1;
    GLsizei a2;
} ARGS_void_GLenum_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei func;
    ARGS_void_GLenum_GLsizei args;
} PACKED_void_GLenum_GLsizei;
typedef void (*FUNC_void_GLenum_GLsizei_GLenum_GLvoid)(GLenum mode, GLsizei count, GLenum type, GLvoid indices);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLenum a3;
    GLvoid a4;
} ARGS_void_GLenum_GLsizei_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLenum_GLvoid func;
    ARGS_void_GLenum_GLsizei_GLenum_GLvoid args;
} PACKED_void_GLenum_GLsizei_GLenum_GLvoid;
typedef void (*FUNC_void_GLenum_GLsizei_GLenum_GLvoid_GLint)(GLenum mode, GLsizei count, GLenum type, GLvoid indices, GLint basevertex);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLenum a3;
    GLvoid a4;
    GLint a5;
} ARGS_void_GLenum_GLsizei_GLenum_GLvoid_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLenum_GLvoid_GLint func;
    ARGS_void_GLenum_GLsizei_GLenum_GLvoid_GLint args;
} PACKED_void_GLenum_GLsizei_GLenum_GLvoid_GLint;
typedef void (*FUNC_void_GLenum_GLenum_GLvoid)(GLenum mode, GLenum type, GLvoid indirect);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLvoid a3;
} ARGS_void_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLvoid func;
    ARGS_void_GLenum_GLenum_GLvoid args;
} PACKED_void_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLenum_GLsizei_GLenum_GLvoid_GLsizei)(GLenum mode, GLsizei count, GLenum type, GLvoid indices, GLsizei instancecount);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLenum a3;
    GLvoid a4;
    GLsizei a5;
} ARGS_void_GLenum_GLsizei_GLenum_GLvoid_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLenum_GLvoid_GLsizei func;
    ARGS_void_GLenum_GLsizei_GLenum_GLvoid_GLsizei args;
} PACKED_void_GLenum_GLsizei_GLenum_GLvoid_GLsizei;
typedef void (*FUNC_void_GLenum_GLsizei_GLenum_void___GENPT___GLsizei_GLuint)(GLenum mode, GLsizei count, GLenum type, void * indices, GLsizei instancecount, GLuint baseinstance);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLenum a3;
    void * a4;
    GLsizei a5;
    GLuint a6;
} ARGS_void_GLenum_GLsizei_GLenum_void___GENPT___GLsizei_GLuint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLenum_void___GENPT___GLsizei_GLuint func;
    ARGS_void_GLenum_GLsizei_GLenum_void___GENPT___GLsizei_GLuint args;
} PACKED_void_GLenum_GLsizei_GLenum_void___GENPT___GLsizei_GLuint;
typedef void (*FUNC_void_GLenum_GLsizei_GLenum_GLvoid_GLsizei_GLint)(GLenum mode, GLsizei count, GLenum type, GLvoid indices, GLsizei instancecount, GLint basevertex);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLenum a3;
    GLvoid a4;
    GLsizei a5;
    GLint a6;
} ARGS_void_GLenum_GLsizei_GLenum_GLvoid_GLsizei_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLenum_GLvoid_GLsizei_GLint func;
    ARGS_void_GLenum_GLsizei_GLenum_GLvoid_GLsizei_GLint args;
} PACKED_void_GLenum_GLsizei_GLenum_GLvoid_GLsizei_GLint;
typedef void (*FUNC_void_GLenum_GLsizei_GLenum_void___GENPT___GLsizei_GLint_GLuint)(GLenum mode, GLsizei count, GLenum type, void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLenum a3;
    void * a4;
    GLsizei a5;
    GLint a6;
    GLuint a7;
} ARGS_void_GLenum_GLsizei_GLenum_void___GENPT___GLsizei_GLint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLenum_void___GENPT___GLsizei_GLint_GLuint func;
    ARGS_void_GLenum_GLsizei_GLenum_void___GENPT___GLsizei_GLint_GLuint args;
} PACKED_void_GLenum_GLsizei_GLenum_void___GENPT___GLsizei_GLint_GLuint;
typedef void (*FUNC_void_GLsizei_GLsizei_GLenum_GLenum_GLvoid)(GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels);
typedef struct {
    GLsizei a1;
    GLsizei a2;
    GLenum a3;
    GLenum a4;
    GLvoid a5;
} ARGS_void_GLsizei_GLsizei_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLsizei_GLenum_GLenum_GLvoid func;
    ARGS_void_GLsizei_GLsizei_GLenum_GLenum_GLvoid args;
} PACKED_void_GLsizei_GLsizei_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLenum_GLuint_GLuint_GLint_GLsizei)(GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLuint a3;
    GLint a4;
    GLsizei a5;
} ARGS_void_GLenum_GLuint_GLuint_GLint_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLuint_GLint_GLsizei func;
    ARGS_void_GLenum_GLuint_GLuint_GLint_GLsizei args;
} PACKED_void_GLenum_GLuint_GLuint_GLint_GLsizei;
typedef void (*FUNC_void_GLenum_GLuint_GLuint_GLsizei)(GLenum mode, GLuint start, GLuint end, GLsizei count);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLuint a3;
    GLsizei a4;
} ARGS_void_GLenum_GLuint_GLuint_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLuint_GLsizei func;
    ARGS_void_GLenum_GLuint_GLuint_GLsizei args;
} PACKED_void_GLenum_GLuint_GLuint_GLsizei;
typedef void (*FUNC_void_GLenum_GLuint_GLuint_GLsizei_GLenum_GLvoid)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid indices);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLuint a3;
    GLsizei a4;
    GLenum a5;
    GLvoid a6;
} ARGS_void_GLenum_GLuint_GLuint_GLsizei_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLuint_GLsizei_GLenum_GLvoid func;
    ARGS_void_GLenum_GLuint_GLuint_GLsizei_GLenum_GLvoid args;
} PACKED_void_GLenum_GLuint_GLuint_GLsizei_GLenum_GLvoid;
typedef void (*FUNC_void_GLenum_GLuint_GLuint_GLsizei_GLenum_GLvoid_GLint)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid indices, GLint basevertex);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLuint a3;
    GLsizei a4;
    GLenum a5;
    GLvoid a6;
    GLint a7;
} ARGS_void_GLenum_GLuint_GLuint_GLsizei_GLenum_GLvoid_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLuint_GLsizei_GLenum_GLvoid_GLint func;
    ARGS_void_GLenum_GLuint_GLuint_GLsizei_GLenum_GLvoid_GLint args;
} PACKED_void_GLenum_GLuint_GLuint_GLsizei_GLenum_GLvoid_GLint;
typedef void (*FUNC_void_GLuint_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat)(GLuint texture, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLfloat a3;
    GLfloat a4;
    GLfloat a5;
    GLfloat a6;
    GLfloat a7;
    GLfloat a8;
    GLfloat a9;
    GLfloat a10;
    GLfloat a11;
} ARGS_void_GLuint_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLuint_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLuint_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLenum_GLuint_GLsizei)(GLenum mode, GLuint id, GLsizei instancecount);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLsizei a3;
} ARGS_void_GLenum_GLuint_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLsizei func;
    ARGS_void_GLenum_GLuint_GLsizei args;
} PACKED_void_GLenum_GLuint_GLsizei;
typedef void (*FUNC_void_GLsizei)(GLsizei stride);
typedef struct {
    GLsizei a1;
} ARGS_void_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLsizei func;
    ARGS_void_GLsizei args;
} PACKED_void_GLsizei;
typedef void (*FUNC_void_GLsizei_GLvoid)(GLsizei stride, GLvoid pointer);
typedef struct {
    GLsizei a1;
    GLvoid a2;
} ARGS_void_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLvoid func;
    ARGS_void_GLsizei_GLvoid args;
} PACKED_void_GLsizei_GLvoid;
typedef void (*FUNC_void_GLsizei_GLsizei_GLboolean)(GLsizei stride, GLsizei count, GLboolean pointer);
typedef struct {
    GLsizei a1;
    GLsizei a2;
    GLboolean a3;
} ARGS_void_GLsizei_GLsizei_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLsizei_GLboolean func;
    ARGS_void_GLsizei_GLsizei_GLboolean args;
} PACKED_void_GLsizei_GLsizei_GLboolean;
typedef void (*FUNC_void_GLint_GLboolean___GENPT___GLint)(GLint stride, GLboolean * pointer, GLint ptrstride);
typedef struct {
    GLint a1;
    GLboolean * a2;
    GLint a3;
} ARGS_void_GLint_GLboolean___GENPT___GLint;
typedef struct {
    int format;
    FUNC_void_GLint_GLboolean___GENPT___GLint func;
    ARGS_void_GLint_GLboolean___GENPT___GLint args;
} PACKED_void_GLint_GLboolean___GENPT___GLint;
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
typedef void (*FUNC_void_GLenum_GLuint_GLfloat)(GLenum target, GLuint id, GLfloat params);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLfloat a3;
} ARGS_void_GLenum_GLuint_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLfloat func;
    ARGS_void_GLenum_GLuint_GLfloat args;
} PACKED_void_GLenum_GLuint_GLfloat;
typedef void (*FUNC_void_GLsizei_GLenum_GLfloat)(GLsizei size, GLenum type, GLfloat buffer);
typedef struct {
    GLsizei a1;
    GLenum a2;
    GLfloat a3;
} ARGS_void_GLsizei_GLenum_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLenum_GLfloat func;
    ARGS_void_GLsizei_GLenum_GLfloat args;
} PACKED_void_GLsizei_GLenum_GLfloat;
typedef void (*FUNC_void_GLsizei_GLenum_GLfixed)(GLsizei n, GLenum type, GLfixed buffer);
typedef struct {
    GLsizei a1;
    GLenum a2;
    GLfixed a3;
} ARGS_void_GLsizei_GLenum_GLfixed;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLenum_GLfixed func;
    ARGS_void_GLsizei_GLenum_GLfixed args;
} PACKED_void_GLsizei_GLenum_GLfixed;
typedef sync (*FUNC_sync_GLenum_GLbitfield)(GLenum condition, GLbitfield flags);
typedef struct {
    GLenum a1;
    GLbitfield a2;
} ARGS_sync_GLenum_GLbitfield;
typedef struct {
    int format;
    FUNC_sync_GLenum_GLbitfield func;
    ARGS_sync_GLenum_GLbitfield args;
} PACKED_sync_GLenum_GLbitfield;
typedef Int32 (*FUNC_Int32_GLuint)(GLuint markerp);
typedef struct {
    GLuint a1;
} ARGS_Int32_GLuint;
typedef struct {
    int format;
    FUNC_Int32_GLuint func;
    ARGS_Int32_GLuint args;
} PACKED_Int32_GLuint;
typedef void (*FUNC_void_GLenum_GLintptr_GLsizeiptr)(GLenum target, GLintptr offset, GLsizeiptr length);
typedef struct {
    GLenum a1;
    GLintptr a2;
    GLsizeiptr a3;
} ARGS_void_GLenum_GLintptr_GLsizeiptr;
typedef struct {
    int format;
    FUNC_void_GLenum_GLintptr_GLsizeiptr func;
    ARGS_void_GLenum_GLintptr_GLsizeiptr args;
} PACKED_void_GLenum_GLintptr_GLsizeiptr;
typedef void (*FUNC_void_GLuint_GLintptr_GLsizeiptr)(GLuint buffer, GLintptr offset, GLsizeiptr length);
typedef struct {
    GLuint a1;
    GLintptr a2;
    GLsizeiptr a3;
} ARGS_void_GLuint_GLintptr_GLsizeiptr;
typedef struct {
    int format;
    FUNC_void_GLuint_GLintptr_GLsizeiptr func;
    ARGS_void_GLuint_GLintptr_GLsizeiptr args;
} PACKED_void_GLuint_GLintptr_GLsizeiptr;
typedef void (*FUNC_void_GLenum_GLint_GLvoid___GENPT___GLint)(GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride);
typedef struct {
    GLenum a1;
    GLint a2;
    GLvoid * a3;
    GLint a4;
} ARGS_void_GLenum_GLint_GLvoid___GENPT___GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLvoid___GENPT___GLint func;
    ARGS_void_GLenum_GLint_GLvoid___GENPT___GLint args;
} PACKED_void_GLenum_GLint_GLvoid___GENPT___GLint;
typedef void (*FUNC_void_GLsizei_GLfloat)(GLsizei n, GLfloat points);
typedef struct {
    GLsizei a1;
    GLfloat a2;
} ARGS_void_GLsizei_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLfloat func;
    ARGS_void_GLsizei_GLfloat args;
} PACKED_void_GLsizei_GLfloat;
typedef void (*FUNC_void_GLuint_GLsizei_GLenum)(GLuint framebuffer, GLsizei n, GLenum bufs);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLenum a3;
} ARGS_void_GLuint_GLsizei_GLenum;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLenum func;
    ARGS_void_GLuint_GLsizei_GLenum args;
} PACKED_void_GLuint_GLsizei_GLenum;
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
typedef void (*FUNC_void_GLenum_GLenum_GLuint_GLint)(GLenum target, GLenum attachment, GLuint texture, GLint level);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLuint a3;
    GLint a4;
} ARGS_void_GLenum_GLenum_GLuint_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLuint_GLint func;
    ARGS_void_GLenum_GLenum_GLuint_GLint args;
} PACKED_void_GLenum_GLenum_GLuint_GLint;
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
typedef void (*FUNC_void_GLenum_GLenum_GLenum_GLuint_GLint_GLint)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLenum a3;
    GLuint a4;
    GLint a5;
    GLint a6;
} ARGS_void_GLenum_GLenum_GLenum_GLuint_GLint_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLenum_GLuint_GLint_GLint func;
    ARGS_void_GLenum_GLenum_GLenum_GLuint_GLint_GLint args;
} PACKED_void_GLenum_GLenum_GLenum_GLuint_GLint_GLint;
typedef void (*FUNC_void_GLenum_GLenum_GLuint_GLint_GLenum)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLuint a3;
    GLint a4;
    GLenum a5;
} ARGS_void_GLenum_GLenum_GLuint_GLint_GLenum;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLuint_GLint_GLenum func;
    ARGS_void_GLenum_GLenum_GLuint_GLint_GLenum args;
} PACKED_void_GLenum_GLenum_GLuint_GLint_GLenum;
typedef void (*FUNC_void_GLenum_GLenum_GLuint_GLint_GLint)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLuint a3;
    GLint a4;
    GLint a5;
} ARGS_void_GLenum_GLenum_GLuint_GLint_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLuint_GLint_GLint func;
    ARGS_void_GLenum_GLenum_GLuint_GLint_GLint args;
} PACKED_void_GLenum_GLenum_GLuint_GLint_GLint;
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
typedef void (*FUNC_void_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed_GLfixed)(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f);
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
typedef UInt32 (*FUNC_UInt32_GLsizei)(GLsizei range);
typedef struct {
    GLsizei a1;
} ARGS_UInt32_GLsizei;
typedef struct {
    int format;
    FUNC_UInt32_GLsizei func;
    ARGS_UInt32_GLsizei args;
} PACKED_UInt32_GLsizei;
typedef UInt32 (*FUNC_UInt32_GLuint)(GLuint range);
typedef struct {
    GLuint a1;
} ARGS_UInt32_GLuint;
typedef struct {
    int format;
    FUNC_UInt32_GLuint func;
    ARGS_UInt32_GLuint args;
} PACKED_UInt32_GLuint;
typedef List (*FUNC_List_GLsizei)(GLsizei range);
typedef struct {
    GLsizei a1;
} ARGS_List_GLsizei;
typedef struct {
    int format;
    FUNC_List_GLsizei func;
    ARGS_List_GLsizei args;
} PACKED_List_GLsizei;
typedef Path (*FUNC_Path_GLsizei)(GLsizei range);
typedef struct {
    GLsizei a1;
} ARGS_Path_GLsizei;
typedef struct {
    int format;
    FUNC_Path_GLsizei func;
    ARGS_Path_GLsizei args;
} PACKED_Path_GLsizei;
typedef UInt32 (*FUNC_UInt32_GLenum_GLenum_GLenum_GLuint)(GLenum datatype, GLenum storagetype, GLenum range, GLuint components);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLenum a3;
    GLuint a4;
} ARGS_UInt32_GLenum_GLenum_GLenum_GLuint;
typedef struct {
    int format;
    FUNC_UInt32_GLenum_GLenum_GLenum_GLuint func;
    ARGS_UInt32_GLenum_GLenum_GLenum_GLuint args;
} PACKED_UInt32_GLenum_GLenum_GLenum_GLuint;
typedef void (*FUNC_void_GLuint_GLuint_GLenum_GLint)(GLuint program, GLuint bufferIndex, GLenum pname, GLint params);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLenum a3;
    GLint a4;
} ARGS_void_GLuint_GLuint_GLenum_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLenum_GLint func;
    ARGS_void_GLuint_GLuint_GLenum_GLint args;
} PACKED_void_GLuint_GLuint_GLenum_GLint;
typedef void (*FUNC_void_GLuint_GLuint_GLsizei_GLsizei_GLint_GLenum_GLchar)(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLint size, GLenum type, GLchar name);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLsizei a3;
    GLsizei a4;
    GLint a5;
    GLenum a6;
    GLchar a7;
} ARGS_void_GLuint_GLuint_GLsizei_GLsizei_GLint_GLenum_GLchar;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLsizei_GLsizei_GLint_GLenum_GLchar func;
    ARGS_void_GLuint_GLuint_GLsizei_GLsizei_GLint_GLenum_GLchar args;
} PACKED_void_GLuint_GLuint_GLsizei_GLsizei_GLint_GLenum_GLchar;
typedef void (*FUNC_void_GLhandleARB_GLuint_GLsizei_GLsizei_GLint_GLenum_GLcharARB)(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei length, GLint size, GLenum type, GLcharARB name);
typedef struct {
    GLhandleARB a1;
    GLuint a2;
    GLsizei a3;
    GLsizei a4;
    GLint a5;
    GLenum a6;
    GLcharARB a7;
} ARGS_void_GLhandleARB_GLuint_GLsizei_GLsizei_GLint_GLenum_GLcharARB;
typedef struct {
    int format;
    FUNC_void_GLhandleARB_GLuint_GLsizei_GLsizei_GLint_GLenum_GLcharARB func;
    ARGS_void_GLhandleARB_GLuint_GLsizei_GLsizei_GLint_GLenum_GLcharARB args;
} PACKED_void_GLhandleARB_GLuint_GLsizei_GLsizei_GLint_GLenum_GLcharARB;
typedef void (*FUNC_void_GLuint_GLenum_GLuint_GLsizei_GLsizei_GLchar)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei length, GLchar name);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLuint a3;
    GLsizei a4;
    GLsizei a5;
    GLchar a6;
} ARGS_void_GLuint_GLenum_GLuint_GLsizei_GLsizei_GLchar;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLuint_GLsizei_GLsizei_GLchar func;
    ARGS_void_GLuint_GLenum_GLuint_GLsizei_GLsizei_GLchar args;
} PACKED_void_GLuint_GLenum_GLuint_GLsizei_GLsizei_GLchar;
typedef void (*FUNC_void_GLuint_GLenum_GLuint_GLenum_GLint)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint values);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLuint a3;
    GLenum a4;
    GLint a5;
} ARGS_void_GLuint_GLenum_GLuint_GLenum_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLuint_GLenum_GLint func;
    ARGS_void_GLuint_GLenum_GLuint_GLenum_GLint args;
} PACKED_void_GLuint_GLenum_GLuint_GLenum_GLint;
typedef void (*FUNC_void_GLuint_GLuint_GLsizei_GLsizei_GLchar)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei length, GLchar uniformBlockName);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLsizei a3;
    GLsizei a4;
    GLchar a5;
} ARGS_void_GLuint_GLuint_GLsizei_GLsizei_GLchar;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLsizei_GLsizei_GLchar func;
    ARGS_void_GLuint_GLuint_GLsizei_GLsizei_GLchar args;
} PACKED_void_GLuint_GLuint_GLsizei_GLsizei_GLchar;
typedef void (*FUNC_void_GLuint_GLsizei_GLuint_GLenum_GLint)(GLuint program, GLsizei uniformCount, GLuint uniformIndices, GLenum pname, GLint params);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLuint a3;
    GLenum a4;
    GLint a5;
} ARGS_void_GLuint_GLsizei_GLuint_GLenum_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLuint_GLenum_GLint func;
    ARGS_void_GLuint_GLsizei_GLuint_GLenum_GLint args;
} PACKED_void_GLuint_GLsizei_GLuint_GLenum_GLint;
typedef void (*FUNC_void_GLuint_GLuint_GLsizei_GLsizei_GLsizei_GLenum_GLchar)(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLsizei size, GLenum type, GLchar name);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLsizei a3;
    GLsizei a4;
    GLsizei a5;
    GLenum a6;
    GLchar a7;
} ARGS_void_GLuint_GLuint_GLsizei_GLsizei_GLsizei_GLenum_GLchar;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLsizei_GLsizei_GLsizei_GLenum_GLchar func;
    ARGS_void_GLuint_GLuint_GLsizei_GLsizei_GLsizei_GLenum_GLchar args;
} PACKED_void_GLuint_GLuint_GLsizei_GLsizei_GLsizei_GLenum_GLchar;
typedef void (*FUNC_void_GLhandleARB_GLsizei_GLsizei_GLhandleARB)(GLhandleARB containerObj, GLsizei maxCount, GLsizei count, GLhandleARB obj);
typedef struct {
    GLhandleARB a1;
    GLsizei a2;
    GLsizei a3;
    GLhandleARB a4;
} ARGS_void_GLhandleARB_GLsizei_GLsizei_GLhandleARB;
typedef struct {
    int format;
    FUNC_void_GLhandleARB_GLsizei_GLsizei_GLhandleARB func;
    ARGS_void_GLhandleARB_GLsizei_GLsizei_GLhandleARB args;
} PACKED_void_GLhandleARB_GLsizei_GLsizei_GLhandleARB;
typedef void (*FUNC_void_GLuint_GLsizei_GLsizei_GLuint)(GLuint program, GLsizei maxCount, GLsizei count, GLuint obj);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLsizei a3;
    GLuint a4;
} ARGS_void_GLuint_GLsizei_GLsizei_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLsizei_GLuint func;
    ARGS_void_GLuint_GLsizei_GLsizei_GLuint args;
} PACKED_void_GLuint_GLsizei_GLsizei_GLuint;
typedef Int32 (*FUNC_Int32_GLuint_GLchar)(GLuint program, GLchar name);
typedef struct {
    GLuint a1;
    GLchar a2;
} ARGS_Int32_GLuint_GLchar;
typedef struct {
    int format;
    FUNC_Int32_GLuint_GLchar func;
    ARGS_Int32_GLuint_GLchar args;
} PACKED_Int32_GLuint_GLchar;
typedef Int32 (*FUNC_Int32_GLhandleARB_GLcharARB)(GLhandleARB programObj, GLcharARB name);
typedef struct {
    GLhandleARB a1;
    GLcharARB a2;
} ARGS_Int32_GLhandleARB_GLcharARB;
typedef struct {
    int format;
    FUNC_Int32_GLhandleARB_GLcharARB func;
    ARGS_Int32_GLhandleARB_GLcharARB args;
} PACKED_Int32_GLhandleARB_GLcharARB;
typedef void (*FUNC_void_GLenum_GLuint_GLboolean)(GLenum target, GLuint index, GLboolean data);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLboolean a3;
} ARGS_void_GLenum_GLuint_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLboolean func;
    ARGS_void_GLenum_GLuint_GLboolean args;
} PACKED_void_GLenum_GLuint_GLboolean;
typedef void (*FUNC_void_GLenum_GLboolean)(GLenum pname, GLboolean params);
typedef struct {
    GLenum a1;
    GLboolean a2;
} ARGS_void_GLenum_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLenum_GLboolean func;
    ARGS_void_GLenum_GLboolean args;
} PACKED_void_GLenum_GLboolean;
typedef void (*FUNC_void_GLenum_GLenum_GLint64)(GLenum target, GLenum pname, GLint64 params);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint64 a3;
} ARGS_void_GLenum_GLenum_GLint64;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint64 func;
    ARGS_void_GLenum_GLenum_GLint64 args;
} PACKED_void_GLenum_GLenum_GLint64;
typedef void (*FUNC_void_GLenum_GLenum_GLuint64EXT)(GLenum target, GLenum pname, GLuint64EXT params);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLuint64EXT a3;
} ARGS_void_GLenum_GLenum_GLuint64EXT;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLuint64EXT func;
    ARGS_void_GLenum_GLenum_GLuint64EXT args;
} PACKED_void_GLenum_GLenum_GLuint64EXT;
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
typedef void (*FUNC_void_GLenum_GLenum_GLenum_GLvoid)(GLenum target, GLenum format, GLenum type, GLvoid table);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLenum a3;
    GLvoid a4;
} ARGS_void_GLenum_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLenum_GLvoid func;
    ARGS_void_GLenum_GLenum_GLenum_GLvoid args;
} PACKED_void_GLenum_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLenum_GLenum_GLenum_GLenum_GLfloat)(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat params);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLenum a3;
    GLenum a4;
    GLfloat a5;
} ARGS_void_GLenum_GLenum_GLenum_GLenum_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLenum_GLenum_GLfloat func;
    ARGS_void_GLenum_GLenum_GLenum_GLenum_GLfloat args;
} PACKED_void_GLenum_GLenum_GLenum_GLenum_GLfloat;
typedef void (*FUNC_void_GLenum_GLenum_GLenum_GLenum_GLint)(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint params);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLenum a3;
    GLenum a4;
    GLint a5;
} ARGS_void_GLenum_GLenum_GLenum_GLenum_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLenum_GLenum_GLint func;
    ARGS_void_GLenum_GLenum_GLenum_GLenum_GLint args;
} PACKED_void_GLenum_GLenum_GLenum_GLenum_GLint;
typedef void (*FUNC_void_GLenum_GLenum_GLenum_GLfloat)(GLenum stage, GLenum portion, GLenum pname, GLfloat params);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLenum a3;
    GLfloat a4;
} ARGS_void_GLenum_GLenum_GLenum_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLenum_GLfloat func;
    ARGS_void_GLenum_GLenum_GLenum_GLfloat args;
} PACKED_void_GLenum_GLenum_GLenum_GLfloat;
typedef void (*FUNC_void_GLenum_GLenum_GLenum_GLint)(GLenum stage, GLenum portion, GLenum pname, GLint params);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLenum a3;
    GLint a4;
} ARGS_void_GLenum_GLenum_GLenum_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLenum_GLint func;
    ARGS_void_GLenum_GLenum_GLenum_GLint args;
} PACKED_void_GLenum_GLenum_GLenum_GLint;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLvoid)(GLenum texunit, GLenum target, GLint lod, GLvoid img);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLvoid a4;
} ARGS_void_GLenum_GLenum_GLint_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLvoid func;
    ARGS_void_GLenum_GLenum_GLint_GLvoid args;
} PACKED_void_GLenum_GLenum_GLint_GLvoid;
typedef void (*FUNC_void_GLenum_GLint_GLvoid)(GLenum target, GLint level, GLvoid img);
typedef struct {
    GLenum a1;
    GLint a2;
    GLvoid a3;
} ARGS_void_GLenum_GLint_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLvoid func;
    ARGS_void_GLenum_GLint_GLvoid args;
} PACKED_void_GLenum_GLint_GLvoid;
typedef void (*FUNC_void_GLuint_GLenum_GLint_GLvoid)(GLuint texture, GLenum target, GLint lod, GLvoid img);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint a3;
    GLvoid a4;
} ARGS_void_GLuint_GLenum_GLint_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint_GLvoid func;
    ARGS_void_GLuint_GLenum_GLint_GLvoid args;
} PACKED_void_GLuint_GLenum_GLint_GLvoid;
typedef UInt32 (*FUNC_UInt32_GLuint_GLsizei_GLenum_GLenum_GLuint_GLenum_GLsizei_GLchar)(GLuint count, GLsizei bufsize, GLenum sources, GLenum types, GLuint ids, GLenum severities, GLsizei lengths, GLchar messageLog);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLenum a3;
    GLenum a4;
    GLuint a5;
    GLenum a6;
    GLsizei a7;
    GLchar a8;
} ARGS_UInt32_GLuint_GLsizei_GLenum_GLenum_GLuint_GLenum_GLsizei_GLchar;
typedef struct {
    int format;
    FUNC_UInt32_GLuint_GLsizei_GLenum_GLenum_GLuint_GLenum_GLsizei_GLchar func;
    ARGS_UInt32_GLuint_GLsizei_GLenum_GLenum_GLuint_GLenum_GLsizei_GLchar args;
} PACKED_UInt32_GLuint_GLsizei_GLenum_GLenum_GLuint_GLenum_GLsizei_GLchar;
typedef UInt32 (*FUNC_UInt32_GLuint_GLsizei_GLenum_GLuint_GLuint_GLsizei_GLchar)(GLuint count, GLsizei bufsize, GLenum categories, GLuint severities, GLuint ids, GLsizei lengths, GLchar message);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLenum a3;
    GLuint a4;
    GLuint a5;
    GLsizei a6;
    GLchar a7;
} ARGS_UInt32_GLuint_GLsizei_GLenum_GLuint_GLuint_GLsizei_GLchar;
typedef struct {
    int format;
    FUNC_UInt32_GLuint_GLsizei_GLenum_GLuint_GLuint_GLsizei_GLchar func;
    ARGS_UInt32_GLuint_GLsizei_GLenum_GLuint_GLuint_GLsizei_GLchar args;
} PACKED_UInt32_GLuint_GLsizei_GLenum_GLuint_GLuint_GLsizei_GLchar;
typedef void (*FUNC_void_GLenum_GLuint_GLdouble)(GLenum target, GLuint index, GLdouble data);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLdouble a3;
} ARGS_void_GLenum_GLuint_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLdouble func;
    ARGS_void_GLenum_GLuint_GLdouble args;
} PACKED_void_GLenum_GLuint_GLdouble;
typedef ErrorCode (*FUNC_ErrorCode)();
typedef struct {
} ARGS_ErrorCode;
typedef struct {
    int format;
    FUNC_ErrorCode func;
    ARGS_ErrorCode args;
} PACKED_ErrorCode;
typedef void (*FUNC_void_GLuint_GLenum_GLint)(GLuint fence, GLenum pname, GLint params);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint a3;
} ARGS_void_GLuint_GLenum_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint func;
    ARGS_void_GLuint_GLenum_GLint args;
} PACKED_void_GLuint_GLenum_GLint;
typedef GLenum (*FUNC_GLenum)();
typedef struct {
} ARGS_GLenum;
typedef struct {
    int format;
    FUNC_GLenum func;
    ARGS_GLenum args;
} PACKED_GLenum;
typedef void (*FUNC_void_GLenum_GLboolean_GLenum_GLenum_GLvoid)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid values);
typedef struct {
    GLenum a1;
    GLboolean a2;
    GLenum a3;
    GLenum a4;
    GLvoid a5;
} ARGS_void_GLenum_GLboolean_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLboolean_GLenum_GLenum_GLvoid func;
    ARGS_void_GLenum_GLboolean_GLenum_GLenum_GLvoid args;
} PACKED_void_GLenum_GLboolean_GLenum_GLenum_GLvoid;
typedef UInt64 (*FUNC_UInt64_GLuint_GLint_GLboolean_GLint_GLenum)(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
typedef struct {
    GLuint a1;
    GLint a2;
    GLboolean a3;
    GLint a4;
    GLenum a5;
} ARGS_UInt64_GLuint_GLint_GLboolean_GLint_GLenum;
typedef struct {
    int format;
    FUNC_UInt64_GLuint_GLint_GLboolean_GLint_GLenum func;
    ARGS_UInt64_GLuint_GLint_GLboolean_GLint_GLenum args;
} PACKED_UInt64_GLuint_GLint_GLboolean_GLint_GLenum;
typedef void (*FUNC_void_GLhandleARB_GLsizei_GLsizei_GLcharARB)(GLhandleARB obj, GLsizei maxLength, GLsizei length, GLcharARB infoLog);
typedef struct {
    GLhandleARB a1;
    GLsizei a2;
    GLsizei a3;
    GLcharARB a4;
} ARGS_void_GLhandleARB_GLsizei_GLsizei_GLcharARB;
typedef struct {
    int format;
    FUNC_void_GLhandleARB_GLsizei_GLsizei_GLcharARB func;
    ARGS_void_GLhandleARB_GLsizei_GLsizei_GLcharARB args;
} PACKED_void_GLhandleARB_GLsizei_GLsizei_GLcharARB;
typedef Int32 (*FUNC_Int32)();
typedef struct {
} ARGS_Int32;
typedef struct {
    int format;
    FUNC_Int32 func;
    ARGS_Int32 args;
} PACKED_Int32;
typedef void (*FUNC_void_GLenum_GLuint_GLint64)(GLenum target, GLuint index, GLint64 data);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLint64 a3;
} ARGS_void_GLenum_GLuint_GLint64;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLint64 func;
    ARGS_void_GLenum_GLuint_GLint64 args;
} PACKED_void_GLenum_GLuint_GLint64;
typedef void (*FUNC_void_GLenum_GLint64)(GLenum pname, GLint64 params);
typedef struct {
    GLenum a1;
    GLint64 a2;
} ARGS_void_GLenum_GLint64;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint64 func;
    ARGS_void_GLenum_GLint64 args;
} PACKED_void_GLenum_GLint64;
typedef void (*FUNC_void_GLenum_GLuint_GLint)(GLenum target, GLuint index, GLint data);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLint a3;
} ARGS_void_GLenum_GLuint_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLint func;
    ARGS_void_GLenum_GLuint_GLint args;
} PACKED_void_GLenum_GLuint_GLint;
typedef void (*FUNC_void_GLenum_GLuint_GLuint64EXT)(GLenum value, GLuint index, GLuint64EXT result);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLuint64EXT a3;
} ARGS_void_GLenum_GLuint_GLuint64EXT;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLuint64EXT func;
    ARGS_void_GLenum_GLuint_GLuint64EXT args;
} PACKED_void_GLenum_GLuint_GLuint64EXT;
typedef void (*FUNC_void_GLenum_GLuint64EXT)(GLenum value, GLuint64EXT result);
typedef struct {
    GLenum a1;
    GLuint64EXT a2;
} ARGS_void_GLenum_GLuint64EXT;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint64EXT func;
    ARGS_void_GLenum_GLuint64EXT args;
} PACKED_void_GLenum_GLuint64EXT;
typedef void (*FUNC_void_GLenum_GLenum_GLenum_GLsizei_GLint64)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 params);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLenum a3;
    GLsizei a4;
    GLint64 a5;
} ARGS_void_GLenum_GLenum_GLenum_GLsizei_GLint64;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLenum_GLsizei_GLint64 func;
    ARGS_void_GLenum_GLenum_GLenum_GLsizei_GLint64 args;
} PACKED_void_GLenum_GLenum_GLenum_GLsizei_GLint64;
typedef void (*FUNC_void_GLenum_GLenum_GLenum_GLsizei_GLint)(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint params);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLenum a3;
    GLsizei a4;
    GLint a5;
} ARGS_void_GLenum_GLenum_GLenum_GLsizei_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLenum_GLsizei_GLint func;
    ARGS_void_GLenum_GLenum_GLenum_GLsizei_GLint args;
} PACKED_void_GLenum_GLenum_GLenum_GLsizei_GLint;
typedef void (*FUNC_void_GLuint_GLenum_GLboolean)(GLuint id, GLenum value, GLboolean data);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLboolean a3;
} ARGS_void_GLuint_GLenum_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLboolean func;
    ARGS_void_GLuint_GLenum_GLboolean args;
} PACKED_void_GLuint_GLenum_GLboolean;
typedef void (*FUNC_void_GLuint_GLenum_GLfloat)(GLuint id, GLenum value, GLfloat data);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLfloat a3;
} ARGS_void_GLuint_GLenum_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLfloat func;
    ARGS_void_GLuint_GLenum_GLfloat args;
} PACKED_void_GLuint_GLenum_GLfloat;
typedef void (*FUNC_void_GLenum_GLuint_GLenum_GLfloat)(GLenum target, GLuint index, GLenum pname, GLfloat params);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLenum a3;
    GLfloat a4;
} ARGS_void_GLenum_GLuint_GLenum_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLenum_GLfloat func;
    ARGS_void_GLenum_GLuint_GLenum_GLfloat args;
} PACKED_void_GLenum_GLuint_GLenum_GLfloat;
typedef void (*FUNC_void_GLenum_GLuint_GLenum_GLint)(GLenum target, GLuint index, GLenum pname, GLint params);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLenum a3;
    GLint a4;
} ARGS_void_GLenum_GLuint_GLenum_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLenum_GLint func;
    ARGS_void_GLenum_GLuint_GLenum_GLint args;
} PACKED_void_GLenum_GLuint_GLenum_GLint;
typedef void (*FUNC_void_GLenum_GLuint_GLenum_GLsizei_GLsizei_GLboolean_GLvoid)(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLboolean packed, GLvoid points);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLenum a3;
    GLsizei a4;
    GLsizei a5;
    GLboolean a6;
    GLvoid a7;
} ARGS_void_GLenum_GLuint_GLenum_GLsizei_GLsizei_GLboolean_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLenum_GLsizei_GLsizei_GLboolean_GLvoid func;
    ARGS_void_GLenum_GLuint_GLenum_GLsizei_GLsizei_GLboolean_GLvoid args;
} PACKED_void_GLenum_GLuint_GLenum_GLsizei_GLsizei_GLboolean_GLvoid;
typedef void (*FUNC_void_GLenum_GLenum_GLdouble)(GLenum target, GLenum query, GLdouble v);
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
typedef void (*FUNC_void_GLenum_GLenum_GLenum_GLdouble)(GLenum texunit, GLenum coord, GLenum pname, GLdouble params);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLenum a3;
    GLdouble a4;
} ARGS_void_GLenum_GLenum_GLenum_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLenum_GLdouble func;
    ARGS_void_GLenum_GLenum_GLenum_GLdouble args;
} PACKED_void_GLenum_GLenum_GLenum_GLdouble;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLenum_GLenum_GLvoid)(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, GLvoid pixels);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLenum a4;
    GLenum a5;
    GLvoid a6;
} ARGS_void_GLenum_GLenum_GLint_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLenum_GLenum_GLvoid func;
    ARGS_void_GLenum_GLenum_GLint_GLenum_GLenum_GLvoid args;
} PACKED_void_GLenum_GLenum_GLint_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLenum_GLfloat)(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat params);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLenum a4;
    GLfloat a5;
} ARGS_void_GLenum_GLenum_GLint_GLenum_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLenum_GLfloat func;
    ARGS_void_GLenum_GLenum_GLint_GLenum_GLfloat args;
} PACKED_void_GLenum_GLenum_GLint_GLenum_GLfloat;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLenum_GLint)(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint params);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLenum a4;
    GLint a5;
} ARGS_void_GLenum_GLenum_GLint_GLenum_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLenum_GLint func;
    ARGS_void_GLenum_GLenum_GLint_GLenum_GLint args;
} PACKED_void_GLenum_GLenum_GLint_GLenum_GLint;
typedef void (*FUNC_void_GLuint_GLenum_GLuint64EXT)(GLuint buffer, GLenum pname, GLuint64EXT params);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLuint64EXT a3;
} ARGS_void_GLuint_GLenum_GLuint64EXT;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLuint64EXT func;
    ARGS_void_GLuint_GLenum_GLuint64EXT args;
} PACKED_void_GLuint_GLenum_GLuint64EXT;
typedef void (*FUNC_void_GLuint_GLenum_GLvoid___GENPT__)(GLuint buffer, GLenum pname, GLvoid * params);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLvoid * a3;
} ARGS_void_GLuint_GLenum_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLvoid___GENPT__ func;
    ARGS_void_GLuint_GLenum_GLvoid___GENPT__ args;
} PACKED_void_GLuint_GLenum_GLvoid___GENPT__;
typedef void (*FUNC_void_GLuint_GLintptr_GLsizeiptr_GLvoid)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid data);
typedef struct {
    GLuint a1;
    GLintptr a2;
    GLsizeiptr a3;
    GLvoid a4;
} ARGS_void_GLuint_GLintptr_GLsizeiptr_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLintptr_GLsizeiptr_GLvoid func;
    ARGS_void_GLuint_GLintptr_GLsizeiptr_GLvoid args;
} PACKED_void_GLuint_GLintptr_GLsizeiptr_GLvoid;
typedef void (*FUNC_void_GLuint_GLenum_GLenum_GLint)(GLuint framebuffer, GLenum attachment, GLenum pname, GLint params);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLenum a3;
    GLint a4;
} ARGS_void_GLuint_GLenum_GLenum_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLenum_GLint func;
    ARGS_void_GLuint_GLenum_GLenum_GLint args;
} PACKED_void_GLuint_GLenum_GLenum_GLint;
typedef void (*FUNC_void_GLuint_GLenum_GLuint_GLint)(GLuint program, GLenum target, GLuint index, GLint params);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLuint a3;
    GLint a4;
} ARGS_void_GLuint_GLenum_GLuint_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLuint_GLint func;
    ARGS_void_GLuint_GLenum_GLuint_GLint args;
} PACKED_void_GLuint_GLenum_GLuint_GLint;
typedef void (*FUNC_void_GLuint_GLenum_GLuint_GLuint)(GLuint program, GLenum target, GLuint index, GLuint params);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLuint a3;
    GLuint a4;
} ARGS_void_GLuint_GLenum_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLuint_GLuint func;
    ARGS_void_GLuint_GLenum_GLuint_GLuint args;
} PACKED_void_GLuint_GLenum_GLuint_GLuint;
typedef void (*FUNC_void_GLuint_GLenum_GLuint_GLdouble)(GLuint program, GLenum target, GLuint index, GLdouble params);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLuint a3;
    GLdouble a4;
} ARGS_void_GLuint_GLenum_GLuint_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLuint_GLdouble func;
    ARGS_void_GLuint_GLenum_GLuint_GLdouble args;
} PACKED_void_GLuint_GLenum_GLuint_GLdouble;
typedef void (*FUNC_void_GLuint_GLenum_GLuint_GLfloat)(GLuint program, GLenum target, GLuint index, GLfloat params);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLuint a3;
    GLfloat a4;
} ARGS_void_GLuint_GLenum_GLuint_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLuint_GLfloat func;
    ARGS_void_GLuint_GLenum_GLuint_GLfloat args;
} PACKED_void_GLuint_GLenum_GLuint_GLfloat;
typedef void (*FUNC_void_GLuint_GLenum_GLenum_GLvoid)(GLuint program, GLenum target, GLenum pname, GLvoid string);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLenum a3;
    GLvoid a4;
} ARGS_void_GLuint_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLenum_GLvoid func;
    ARGS_void_GLuint_GLenum_GLenum_GLvoid args;
} PACKED_void_GLuint_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLint_GLchar_GLsizei_GLint_GLchar)(GLint namelen, GLchar name, GLsizei bufSize, GLint stringlen, GLchar string);
typedef struct {
    GLint a1;
    GLchar a2;
    GLsizei a3;
    GLint a4;
    GLchar a5;
} ARGS_void_GLint_GLchar_GLsizei_GLint_GLchar;
typedef struct {
    int format;
    FUNC_void_GLint_GLchar_GLsizei_GLint_GLchar func;
    ARGS_void_GLint_GLchar_GLsizei_GLint_GLchar args;
} PACKED_void_GLint_GLchar_GLsizei_GLint_GLchar;
typedef void (*FUNC_void_GLint_GLchar_GLenum_GLint)(GLint namelen, GLchar name, GLenum pname, GLint params);
typedef struct {
    GLint a1;
    GLchar a2;
    GLenum a3;
    GLint a4;
} ARGS_void_GLint_GLchar_GLenum_GLint;
typedef struct {
    int format;
    FUNC_void_GLint_GLchar_GLenum_GLint func;
    ARGS_void_GLint_GLchar_GLenum_GLint args;
} PACKED_void_GLint_GLchar_GLenum_GLint;
typedef void (*FUNC_void_GLenum_GLuint_GLsizei_GLsizei_GLchar)(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei length, GLchar label);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLsizei a3;
    GLsizei a4;
    GLchar a5;
} ARGS_void_GLenum_GLuint_GLsizei_GLsizei_GLchar;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLsizei_GLsizei_GLchar func;
    ARGS_void_GLenum_GLuint_GLsizei_GLsizei_GLchar args;
} PACKED_void_GLenum_GLuint_GLsizei_GLsizei_GLchar;
typedef void (*FUNC_void_GLhandleARB_GLenum_GLfloat)(GLhandleARB obj, GLenum pname, GLfloat params);
typedef struct {
    GLhandleARB a1;
    GLenum a2;
    GLfloat a3;
} ARGS_void_GLhandleARB_GLenum_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLhandleARB_GLenum_GLfloat func;
    ARGS_void_GLhandleARB_GLenum_GLfloat args;
} PACKED_void_GLhandleARB_GLenum_GLfloat;
typedef void (*FUNC_void_GLhandleARB_GLenum_GLint)(GLhandleARB obj, GLenum pname, GLint params);
typedef struct {
    GLhandleARB a1;
    GLenum a2;
    GLint a3;
} ARGS_void_GLhandleARB_GLenum_GLint;
typedef struct {
    int format;
    FUNC_void_GLhandleARB_GLenum_GLint func;
    ARGS_void_GLhandleARB_GLenum_GLint args;
} PACKED_void_GLhandleARB_GLenum_GLint;
typedef void (*FUNC_void_void___GENPT___GLsizei_GLsizei_GLchar)(void * ptr, GLsizei bufSize, GLsizei length, GLchar label);
typedef struct {
    void * a1;
    GLsizei a2;
    GLsizei a3;
    GLchar a4;
} ARGS_void_void___GENPT___GLsizei_GLsizei_GLchar;
typedef struct {
    int format;
    FUNC_void_void___GENPT___GLsizei_GLsizei_GLchar func;
    ARGS_void_void___GENPT___GLsizei_GLsizei_GLchar args;
} PACKED_void_void___GENPT___GLsizei_GLsizei_GLchar;
typedef void (*FUNC_void_GLuint_GLenum_GLuint)(GLuint id, GLenum pname, GLuint params);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLuint a3;
} ARGS_void_GLuint_GLenum_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLuint func;
    ARGS_void_GLuint_GLenum_GLuint args;
} PACKED_void_GLuint_GLenum_GLuint;
typedef void (*FUNC_void_GLuint_GLubyte)(GLuint path, GLubyte commands);
typedef struct {
    GLuint a1;
    GLubyte a2;
} ARGS_void_GLuint_GLubyte;
typedef struct {
    int format;
    FUNC_void_GLuint_GLubyte func;
    ARGS_void_GLuint_GLubyte args;
} PACKED_void_GLuint_GLubyte;
typedef void (*FUNC_void_GLuint_GLfloat)(GLuint path, GLfloat coords);
typedef struct {
    GLuint a1;
    GLfloat a2;
} ARGS_void_GLuint_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLfloat func;
    ARGS_void_GLuint_GLfloat args;
} PACKED_void_GLuint_GLfloat;
typedef Float32 (*FUNC_Float32_GLuint_GLsizei_GLsizei)(GLuint path, GLsizei startSegment, GLsizei numSegments);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLsizei a3;
} ARGS_Float32_GLuint_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_Float32_GLuint_GLsizei_GLsizei func;
    ARGS_Float32_GLuint_GLsizei_GLsizei args;
} PACKED_Float32_GLuint_GLsizei_GLsizei;
typedef void (*FUNC_void_GLbitfield_GLuint_GLsizei_GLsizei_GLfloat)(GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat metrics);
typedef struct {
    GLbitfield a1;
    GLuint a2;
    GLsizei a3;
    GLsizei a4;
    GLfloat a5;
} ARGS_void_GLbitfield_GLuint_GLsizei_GLsizei_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLbitfield_GLuint_GLsizei_GLsizei_GLfloat func;
    ARGS_void_GLbitfield_GLuint_GLsizei_GLsizei_GLfloat args;
} PACKED_void_GLbitfield_GLuint_GLsizei_GLsizei_GLfloat;
typedef void (*FUNC_void_GLbitfield_GLsizei_GLenum_GLvoid_GLuint_GLsizei_GLfloat)(GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLsizei stride, GLfloat metrics);
typedef struct {
    GLbitfield a1;
    GLsizei a2;
    GLenum a3;
    GLvoid a4;
    GLuint a5;
    GLsizei a6;
    GLfloat a7;
} ARGS_void_GLbitfield_GLsizei_GLenum_GLvoid_GLuint_GLsizei_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLbitfield_GLsizei_GLenum_GLvoid_GLuint_GLsizei_GLfloat func;
    ARGS_void_GLbitfield_GLsizei_GLenum_GLvoid_GLuint_GLsizei_GLfloat args;
} PACKED_void_GLbitfield_GLsizei_GLenum_GLvoid_GLuint_GLsizei_GLfloat;
typedef void (*FUNC_void_GLenum_GLsizei_GLenum_GLvoid_GLuint_GLfloat_GLfloat_GLenum_GLfloat)(GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat returnedSpacing);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLenum a3;
    GLvoid a4;
    GLuint a5;
    GLfloat a6;
    GLfloat a7;
    GLenum a8;
    GLfloat a9;
} ARGS_void_GLenum_GLsizei_GLenum_GLvoid_GLuint_GLfloat_GLfloat_GLenum_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLenum_GLvoid_GLuint_GLfloat_GLfloat_GLenum_GLfloat func;
    ARGS_void_GLenum_GLsizei_GLenum_GLvoid_GLuint_GLfloat_GLfloat_GLenum_GLfloat args;
} PACKED_void_GLenum_GLsizei_GLenum_GLvoid_GLuint_GLfloat_GLfloat_GLenum_GLfloat;
typedef void (*FUNC_void_GLuint_GLenum_GLsizei_GLuint_GLint)(GLuint monitor, GLenum pname, GLsizei dataSize, GLuint data, GLint bytesWritten);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLsizei a3;
    GLuint a4;
    GLint a5;
} ARGS_void_GLuint_GLenum_GLsizei_GLuint_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLsizei_GLuint_GLint func;
    ARGS_void_GLuint_GLenum_GLsizei_GLuint_GLint args;
} PACKED_void_GLuint_GLenum_GLsizei_GLuint_GLint;
typedef void (*FUNC_void_GLuint_GLuint_GLenum_GLvoid)(GLuint group, GLuint counter, GLenum pname, GLvoid data);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLenum a3;
    GLvoid a4;
} ARGS_void_GLuint_GLuint_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLenum_GLvoid func;
    ARGS_void_GLuint_GLuint_GLenum_GLvoid args;
} PACKED_void_GLuint_GLuint_GLenum_GLvoid;
typedef void (*FUNC_void_GLuint_GLint_GLint_GLsizei_GLuint)(GLuint group, GLint numCounters, GLint maxActiveCounters, GLsizei counterSize, GLuint counters);
typedef struct {
    GLuint a1;
    GLint a2;
    GLint a3;
    GLsizei a4;
    GLuint a5;
} ARGS_void_GLuint_GLint_GLint_GLsizei_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLint_GLsizei_GLuint func;
    ARGS_void_GLuint_GLint_GLint_GLsizei_GLuint args;
} PACKED_void_GLuint_GLint_GLint_GLsizei_GLuint;
typedef void (*FUNC_void_GLuint_GLsizei_GLsizei_GLchar)(GLuint group, GLsizei bufSize, GLsizei length, GLchar groupString);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLsizei a3;
    GLchar a4;
} ARGS_void_GLuint_GLsizei_GLsizei_GLchar;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLsizei_GLchar func;
    ARGS_void_GLuint_GLsizei_GLsizei_GLchar args;
} PACKED_void_GLuint_GLsizei_GLsizei_GLchar;
typedef void (*FUNC_void_GLint_GLsizei_GLuint)(GLint numGroups, GLsizei groupsSize, GLuint groups);
typedef struct {
    GLint a1;
    GLsizei a2;
    GLuint a3;
} ARGS_void_GLint_GLsizei_GLuint;
typedef struct {
    int format;
    FUNC_void_GLint_GLsizei_GLuint func;
    ARGS_void_GLint_GLsizei_GLuint args;
} PACKED_void_GLint_GLsizei_GLuint;
typedef void (*FUNC_void_GLenum_GLushort)(GLenum map, GLushort values);
typedef struct {
    GLenum a1;
    GLushort a2;
} ARGS_void_GLenum_GLushort;
typedef struct {
    int format;
    FUNC_void_GLenum_GLushort func;
    ARGS_void_GLenum_GLushort args;
} PACKED_void_GLenum_GLushort;
typedef void (*FUNC_void_GLenum_GLint_GLfixed)(GLenum map, GLint size, GLfixed values);
typedef struct {
    GLenum a1;
    GLint a2;
    GLfixed a3;
} ARGS_void_GLenum_GLint_GLfixed;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLfixed func;
    ARGS_void_GLenum_GLint_GLfixed args;
} PACKED_void_GLenum_GLint_GLfixed;
typedef void (*FUNC_void_GLenum_GLuint_GLvoid___GENPT__)(GLenum target, GLuint index, GLvoid * data);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLvoid * a3;
} ARGS_void_GLenum_GLuint_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLuint_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLuint_GLvoid___GENPT__;
typedef void (*FUNC_void_GLenum_GLvoid___GENPT__)(GLenum pname, GLvoid * params);
typedef struct {
    GLenum a1;
    GLvoid * a2;
} ARGS_void_GLenum_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLvoid___GENPT__;
typedef void (*FUNC_void_GLuint_GLsizei_GLsizei_GLenum_GLvoid)(GLuint program, GLsizei bufSize, GLsizei length, GLenum binaryFormat, GLvoid binary);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLsizei a3;
    GLenum a4;
    GLvoid a5;
} ARGS_void_GLuint_GLsizei_GLsizei_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLsizei_GLenum_GLvoid func;
    ARGS_void_GLuint_GLsizei_GLsizei_GLenum_GLvoid args;
} PACKED_void_GLuint_GLsizei_GLsizei_GLenum_GLvoid;
typedef void (*FUNC_void_GLuint_GLsizei_GLubyte_GLdouble)(GLuint id, GLsizei len, GLubyte name, GLdouble params);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLubyte a3;
    GLdouble a4;
} ARGS_void_GLuint_GLsizei_GLubyte_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLubyte_GLdouble func;
    ARGS_void_GLuint_GLsizei_GLubyte_GLdouble args;
} PACKED_void_GLuint_GLsizei_GLubyte_GLdouble;
typedef void (*FUNC_void_GLuint_GLsizei_GLubyte_GLfloat)(GLuint id, GLsizei len, GLubyte name, GLfloat params);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLubyte a3;
    GLfloat a4;
} ARGS_void_GLuint_GLsizei_GLubyte_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLubyte_GLfloat func;
    ARGS_void_GLuint_GLsizei_GLubyte_GLfloat args;
} PACKED_void_GLuint_GLsizei_GLubyte_GLfloat;
typedef void (*FUNC_void_GLenum_GLuint_GLenum_GLdouble)(GLenum target, GLuint index, GLenum pname, GLdouble params);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLenum a3;
    GLdouble a4;
} ARGS_void_GLenum_GLuint_GLenum_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLenum_GLdouble func;
    ARGS_void_GLenum_GLuint_GLenum_GLdouble args;
} PACKED_void_GLenum_GLuint_GLenum_GLdouble;
typedef UInt32 (*FUNC_UInt32_GLuint_GLenum_GLchar)(GLuint program, GLenum programInterface, GLchar name);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLchar a3;
} ARGS_UInt32_GLuint_GLenum_GLchar;
typedef struct {
    int format;
    FUNC_UInt32_GLuint_GLenum_GLchar func;
    ARGS_UInt32_GLuint_GLenum_GLchar args;
} PACKED_UInt32_GLuint_GLenum_GLchar;
typedef Int32 (*FUNC_Int32_GLuint_GLenum_GLchar)(GLuint program, GLenum programInterface, GLchar name);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLchar a3;
} ARGS_Int32_GLuint_GLenum_GLchar;
typedef struct {
    int format;
    FUNC_Int32_GLuint_GLenum_GLchar func;
    ARGS_Int32_GLuint_GLenum_GLchar args;
} PACKED_Int32_GLuint_GLenum_GLchar;
typedef void (*FUNC_void_GLuint_GLenum_GLuint_GLsizei_GLenum_GLsizei_GLsizei_GLint)(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, GLenum props, GLsizei bufSize, GLsizei length, GLint params);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLuint a3;
    GLsizei a4;
    GLenum a5;
    GLsizei a6;
    GLsizei a7;
    GLint a8;
} ARGS_void_GLuint_GLenum_GLuint_GLsizei_GLenum_GLsizei_GLsizei_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLuint_GLsizei_GLenum_GLsizei_GLsizei_GLint func;
    ARGS_void_GLuint_GLenum_GLuint_GLsizei_GLenum_GLsizei_GLsizei_GLint args;
} PACKED_void_GLuint_GLenum_GLuint_GLsizei_GLenum_GLsizei_GLsizei_GLint;
typedef void (*FUNC_void_GLuint_GLenum_GLubyte)(GLuint id, GLenum pname, GLubyte program);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLubyte a3;
} ARGS_void_GLuint_GLenum_GLubyte;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLubyte func;
    ARGS_void_GLuint_GLenum_GLubyte args;
} PACKED_void_GLuint_GLenum_GLubyte;
typedef void (*FUNC_void_GLuint_GLenum_GLint64)(GLuint id, GLenum pname, GLint64 params);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint64 a3;
} ARGS_void_GLuint_GLenum_GLint64;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint64 func;
    ARGS_void_GLuint_GLenum_GLint64 args;
} PACKED_void_GLuint_GLenum_GLint64;
typedef void (*FUNC_void_GLuint_GLenum_GLint64EXT)(GLuint id, GLenum pname, GLint64EXT params);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint64EXT a3;
} ARGS_void_GLuint_GLenum_GLint64EXT;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint64EXT func;
    ARGS_void_GLuint_GLenum_GLint64EXT args;
} PACKED_void_GLuint_GLenum_GLint64EXT;
typedef void (*FUNC_void_GLuint_GLenum_GLuint64)(GLuint id, GLenum pname, GLuint64 params);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLuint64 a3;
} ARGS_void_GLuint_GLenum_GLuint64;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLuint64 func;
    ARGS_void_GLuint_GLenum_GLuint64 args;
} PACKED_void_GLuint_GLenum_GLuint64;
typedef void (*FUNC_void_GLenum_GLenum_GLenum_GLvoid_GLvoid_GLvoid)(GLenum target, GLenum format, GLenum type, GLvoid row, GLvoid column, GLvoid span);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLenum a3;
    GLvoid a4;
    GLvoid a5;
    GLvoid a6;
} ARGS_void_GLenum_GLenum_GLenum_GLvoid_GLvoid_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLenum_GLvoid_GLvoid_GLvoid func;
    ARGS_void_GLenum_GLenum_GLenum_GLvoid_GLvoid_GLvoid args;
} PACKED_void_GLenum_GLenum_GLenum_GLvoid_GLvoid_GLvoid;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLint)(GLenum shadertype, GLenum precisiontype, GLint range, GLint precision);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLint a4;
} ARGS_void_GLenum_GLenum_GLint_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLint func;
    ARGS_void_GLenum_GLenum_GLint_GLint args;
} PACKED_void_GLenum_GLenum_GLint_GLint;
typedef String (*FUNC_String_GLenum)(GLenum name);
typedef struct {
    GLenum a1;
} ARGS_String_GLenum;
typedef struct {
    int format;
    FUNC_String_GLenum func;
    ARGS_String_GLenum args;
} PACKED_String_GLenum;
typedef String (*FUNC_String_GLenum_GLuint)(GLenum name, GLuint index);
typedef struct {
    GLenum a1;
    GLuint a2;
} ARGS_String_GLenum_GLuint;
typedef struct {
    int format;
    FUNC_String_GLenum_GLuint func;
    ARGS_String_GLenum_GLuint args;
} PACKED_String_GLenum_GLuint;
typedef void (*FUNC_void_GLsync_GLenum_GLsizei_GLsizei_GLint)(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei length, GLint values);
typedef struct {
    GLsync a1;
    GLenum a2;
    GLsizei a3;
    GLsizei a4;
    GLint a5;
} ARGS_void_GLsync_GLenum_GLsizei_GLsizei_GLint;
typedef struct {
    int format;
    FUNC_void_GLsync_GLenum_GLsizei_GLsizei_GLint func;
    ARGS_void_GLsync_GLenum_GLsizei_GLsizei_GLint args;
} PACKED_void_GLsync_GLenum_GLsizei_GLsizei_GLint;
typedef void (*FUNC_void_GLenum_GLint_GLenum_GLenum_GLvoid)(GLenum target, GLint level, GLenum format, GLenum type, GLvoid pixels);
typedef struct {
    GLenum a1;
    GLint a2;
    GLenum a3;
    GLenum a4;
    GLvoid a5;
} ARGS_void_GLenum_GLint_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLenum_GLenum_GLvoid func;
    ARGS_void_GLenum_GLint_GLenum_GLenum_GLvoid args;
} PACKED_void_GLenum_GLint_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLenum_GLint_GLenum_GLfloat)(GLenum target, GLint level, GLenum pname, GLfloat params);
typedef struct {
    GLenum a1;
    GLint a2;
    GLenum a3;
    GLfloat a4;
} ARGS_void_GLenum_GLint_GLenum_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLenum_GLfloat func;
    ARGS_void_GLenum_GLint_GLenum_GLfloat args;
} PACKED_void_GLenum_GLint_GLenum_GLfloat;
typedef void (*FUNC_void_GLenum_GLint_GLenum_GLint)(GLenum target, GLint level, GLenum pname, GLint params);
typedef struct {
    GLenum a1;
    GLint a2;
    GLenum a3;
    GLint a4;
} ARGS_void_GLenum_GLint_GLenum_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLenum_GLint func;
    ARGS_void_GLenum_GLint_GLenum_GLint args;
} PACKED_void_GLenum_GLint_GLenum_GLint;
typedef void (*FUNC_void_GLenum_GLint_GLenum_GLfixed)(GLenum target, GLint level, GLenum pname, GLfixed params);
typedef struct {
    GLenum a1;
    GLint a2;
    GLenum a3;
    GLfixed a4;
} ARGS_void_GLenum_GLint_GLenum_GLfixed;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLenum_GLfixed func;
    ARGS_void_GLenum_GLint_GLenum_GLfixed args;
} PACKED_void_GLenum_GLint_GLenum_GLfixed;
typedef UInt64 (*FUNC_UInt64_GLuint)(GLuint texture);
typedef struct {
    GLuint a1;
} ARGS_UInt64_GLuint;
typedef struct {
    int format;
    FUNC_UInt64_GLuint func;
    ARGS_UInt64_GLuint args;
} PACKED_UInt64_GLuint;
typedef void (*FUNC_void_GLuint_GLenum_GLint_GLenum_GLenum_GLvoid)(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, GLvoid pixels);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint a3;
    GLenum a4;
    GLenum a5;
    GLvoid a6;
} ARGS_void_GLuint_GLenum_GLint_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint_GLenum_GLenum_GLvoid func;
    ARGS_void_GLuint_GLenum_GLint_GLenum_GLenum_GLvoid args;
} PACKED_void_GLuint_GLenum_GLint_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLuint_GLenum_GLint_GLenum_GLfloat)(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat params);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint a3;
    GLenum a4;
    GLfloat a5;
} ARGS_void_GLuint_GLenum_GLint_GLenum_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint_GLenum_GLfloat func;
    ARGS_void_GLuint_GLenum_GLint_GLenum_GLfloat args;
} PACKED_void_GLuint_GLenum_GLint_GLenum_GLfloat;
typedef void (*FUNC_void_GLuint_GLenum_GLint_GLenum_GLint)(GLuint texture, GLenum target, GLint level, GLenum pname, GLint params);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint a3;
    GLenum a4;
    GLint a5;
} ARGS_void_GLuint_GLenum_GLint_GLenum_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint_GLenum_GLint func;
    ARGS_void_GLuint_GLenum_GLint_GLenum_GLint args;
} PACKED_void_GLuint_GLenum_GLint_GLenum_GLint;
typedef void (*FUNC_void_GLuint_GLenum_GLenum_GLuint)(GLuint texture, GLenum target, GLenum pname, GLuint params);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLenum a3;
    GLuint a4;
} ARGS_void_GLuint_GLenum_GLenum_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLenum_GLuint func;
    ARGS_void_GLuint_GLenum_GLenum_GLuint args;
} PACKED_void_GLuint_GLenum_GLenum_GLuint;
typedef void (*FUNC_void_GLuint_GLenum_GLenum_GLfloat)(GLuint texture, GLenum target, GLenum pname, GLfloat params);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLenum a3;
    GLfloat a4;
} ARGS_void_GLuint_GLenum_GLenum_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLenum_GLfloat func;
    ARGS_void_GLuint_GLenum_GLenum_GLfloat args;
} PACKED_void_GLuint_GLenum_GLenum_GLfloat;
typedef UInt64 (*FUNC_UInt64_GLuint_GLuint)(GLuint texture, GLuint sampler);
typedef struct {
    GLuint a1;
    GLuint a2;
} ARGS_UInt64_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_UInt64_GLuint_GLuint func;
    ARGS_UInt64_GLuint_GLuint args;
} PACKED_UInt64_GLuint_GLuint;
typedef void (*FUNC_void_GLuint_GLuint_GLint)(GLuint program, GLuint index, GLint location);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLint a3;
} ARGS_void_GLuint_GLuint_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLint func;
    ARGS_void_GLuint_GLuint_GLint args;
} PACKED_void_GLuint_GLuint_GLint;
typedef UInt32 (*FUNC_UInt32_GLuint_GLchar)(GLuint program, GLchar uniformBlockName);
typedef struct {
    GLuint a1;
    GLchar a2;
} ARGS_UInt32_GLuint_GLchar;
typedef struct {
    int format;
    FUNC_UInt32_GLuint_GLchar func;
    ARGS_UInt32_GLuint_GLchar args;
} PACKED_UInt32_GLuint_GLchar;
typedef Int32 (*FUNC_Int32_GLuint_GLint)(GLuint program, GLint location);
typedef struct {
    GLuint a1;
    GLint a2;
} ARGS_Int32_GLuint_GLint;
typedef struct {
    int format;
    FUNC_Int32_GLuint_GLint func;
    ARGS_Int32_GLuint_GLint args;
} PACKED_Int32_GLuint_GLint;
typedef void (*FUNC_void_GLuint_GLsizei_GLchar__GENPT__const_GLuint)(GLuint program, GLsizei uniformCount, GLchar*const uniformNames, GLuint uniformIndices);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLchar*const a3;
    GLuint a4;
} ARGS_void_GLuint_GLsizei_GLchar__GENPT__const_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLchar__GENPT__const_GLuint func;
    ARGS_void_GLuint_GLsizei_GLchar__GENPT__const_GLuint args;
} PACKED_void_GLuint_GLsizei_GLchar__GENPT__const_GLuint;
typedef BufferOffset (*FUNC_BufferOffset_GLuint_GLint)(GLuint program, GLint location);
typedef struct {
    GLuint a1;
    GLint a2;
} ARGS_BufferOffset_GLuint_GLint;
typedef struct {
    int format;
    FUNC_BufferOffset_GLuint_GLint func;
    ARGS_BufferOffset_GLuint_GLint args;
} PACKED_BufferOffset_GLuint_GLint;
typedef void (*FUNC_void_GLuint_GLint_GLdouble)(GLuint program, GLint location, GLdouble params);
typedef struct {
    GLuint a1;
    GLint a2;
    GLdouble a3;
} ARGS_void_GLuint_GLint_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLdouble func;
    ARGS_void_GLuint_GLint_GLdouble args;
} PACKED_void_GLuint_GLint_GLdouble;
typedef void (*FUNC_void_GLuint_GLint_GLfloat)(GLuint program, GLint location, GLfloat params);
typedef struct {
    GLuint a1;
    GLint a2;
    GLfloat a3;
} ARGS_void_GLuint_GLint_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLfloat func;
    ARGS_void_GLuint_GLint_GLfloat args;
} PACKED_void_GLuint_GLint_GLfloat;
typedef void (*FUNC_void_GLhandleARB_GLint_GLfloat)(GLhandleARB programObj, GLint location, GLfloat params);
typedef struct {
    GLhandleARB a1;
    GLint a2;
    GLfloat a3;
} ARGS_void_GLhandleARB_GLint_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLhandleARB_GLint_GLfloat func;
    ARGS_void_GLhandleARB_GLint_GLfloat args;
} PACKED_void_GLhandleARB_GLint_GLfloat;
typedef void (*FUNC_void_GLuint_GLint_GLint64EXT)(GLuint program, GLint location, GLint64EXT params);
typedef struct {
    GLuint a1;
    GLint a2;
    GLint64EXT a3;
} ARGS_void_GLuint_GLint_GLint64EXT;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLint64EXT func;
    ARGS_void_GLuint_GLint_GLint64EXT args;
} PACKED_void_GLuint_GLint_GLint64EXT;
typedef void (*FUNC_void_GLuint_GLint_GLint)(GLuint program, GLint location, GLint params);
typedef struct {
    GLuint a1;
    GLint a2;
    GLint a3;
} ARGS_void_GLuint_GLint_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLint func;
    ARGS_void_GLuint_GLint_GLint args;
} PACKED_void_GLuint_GLint_GLint;
typedef void (*FUNC_void_GLhandleARB_GLint_GLint)(GLhandleARB programObj, GLint location, GLint params);
typedef struct {
    GLhandleARB a1;
    GLint a2;
    GLint a3;
} ARGS_void_GLhandleARB_GLint_GLint;
typedef struct {
    int format;
    FUNC_void_GLhandleARB_GLint_GLint func;
    ARGS_void_GLhandleARB_GLint_GLint args;
} PACKED_void_GLhandleARB_GLint_GLint;
typedef void (*FUNC_void_GLuint_GLint_GLuint64EXT)(GLuint program, GLint location, GLuint64EXT params);
typedef struct {
    GLuint a1;
    GLint a2;
    GLuint64EXT a3;
} ARGS_void_GLuint_GLint_GLuint64EXT;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLuint64EXT func;
    ARGS_void_GLuint_GLint_GLuint64EXT args;
} PACKED_void_GLuint_GLint_GLuint64EXT;
typedef void (*FUNC_void_GLuint_GLint_GLuint)(GLuint program, GLint location, GLuint params);
typedef struct {
    GLuint a1;
    GLint a2;
    GLuint a3;
} ARGS_void_GLuint_GLint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLuint func;
    ARGS_void_GLuint_GLint_GLuint args;
} PACKED_void_GLuint_GLint_GLuint;
typedef void (*FUNC_void_GLuint_GLuint_GLenum_GLvoid___GENPT__)(GLuint vaobj, GLuint index, GLenum pname, GLvoid * param);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLenum a3;
    GLvoid * a4;
} ARGS_void_GLuint_GLuint_GLenum_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLenum_GLvoid___GENPT__ func;
    ARGS_void_GLuint_GLuint_GLenum_GLvoid___GENPT__ args;
} PACKED_void_GLuint_GLuint_GLenum_GLvoid___GENPT__;
typedef void (*FUNC_void_GLuint_GLenum_GLdouble)(GLuint index, GLenum pname, GLdouble params);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLdouble a3;
} ARGS_void_GLuint_GLenum_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLdouble func;
    ARGS_void_GLuint_GLenum_GLdouble args;
} PACKED_void_GLuint_GLenum_GLdouble;
typedef void (*FUNC_void_GLuint_GLuint_GLenum_GLdouble)(GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble params);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLenum a3;
    GLdouble a4;
} ARGS_void_GLuint_GLuint_GLenum_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLenum_GLdouble func;
    ARGS_void_GLuint_GLuint_GLenum_GLdouble args;
} PACKED_void_GLuint_GLuint_GLenum_GLdouble;
typedef void (*FUNC_void_GLuint_GLuint_GLenum_GLfloat)(GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat params);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLenum a3;
    GLfloat a4;
} ARGS_void_GLuint_GLuint_GLenum_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLenum_GLfloat func;
    ARGS_void_GLuint_GLuint_GLenum_GLfloat args;
} PACKED_void_GLuint_GLuint_GLenum_GLfloat;
typedef void (*FUNC_void_GLenum_GLenum_GLenum_GLsizei_GLvoid)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, GLvoid table);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLenum a3;
    GLsizei a4;
    GLvoid a5;
} ARGS_void_GLenum_GLenum_GLenum_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLenum_GLsizei_GLvoid func;
    ARGS_void_GLenum_GLenum_GLenum_GLsizei_GLvoid args;
} PACKED_void_GLenum_GLenum_GLenum_GLsizei_GLvoid;
typedef void (*FUNC_void_GLenum_GLint_GLsizei_GLvoid)(GLenum target, GLint lod, GLsizei bufSize, GLvoid img);
typedef struct {
    GLenum a1;
    GLint a2;
    GLsizei a3;
    GLvoid a4;
} ARGS_void_GLenum_GLint_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLsizei_GLvoid func;
    ARGS_void_GLenum_GLint_GLsizei_GLvoid args;
} PACKED_void_GLenum_GLint_GLsizei_GLvoid;
typedef void (*FUNC_void_GLenum_GLboolean_GLenum_GLenum_GLsizei_GLvoid)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, GLvoid values);
typedef struct {
    GLenum a1;
    GLboolean a2;
    GLenum a3;
    GLenum a4;
    GLsizei a5;
    GLvoid a6;
} ARGS_void_GLenum_GLboolean_GLenum_GLenum_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLboolean_GLenum_GLenum_GLsizei_GLvoid func;
    ARGS_void_GLenum_GLboolean_GLenum_GLenum_GLsizei_GLvoid args;
} PACKED_void_GLenum_GLboolean_GLenum_GLenum_GLsizei_GLvoid;
typedef void (*FUNC_void_GLenum_GLenum_GLsizei_GLdouble)(GLenum target, GLenum query, GLsizei bufSize, GLdouble v);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLsizei a3;
    GLdouble a4;
} ARGS_void_GLenum_GLenum_GLsizei_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLsizei_GLdouble func;
    ARGS_void_GLenum_GLenum_GLsizei_GLdouble args;
} PACKED_void_GLenum_GLenum_GLsizei_GLdouble;
typedef void (*FUNC_void_GLenum_GLenum_GLsizei_GLfloat)(GLenum target, GLenum query, GLsizei bufSize, GLfloat v);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLsizei a3;
    GLfloat a4;
} ARGS_void_GLenum_GLenum_GLsizei_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLsizei_GLfloat func;
    ARGS_void_GLenum_GLenum_GLsizei_GLfloat args;
} PACKED_void_GLenum_GLenum_GLsizei_GLfloat;
typedef void (*FUNC_void_GLenum_GLenum_GLsizei_GLint)(GLenum target, GLenum query, GLsizei bufSize, GLint v);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLsizei a3;
    GLint a4;
} ARGS_void_GLenum_GLenum_GLsizei_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLsizei_GLint func;
    ARGS_void_GLenum_GLenum_GLsizei_GLint args;
} PACKED_void_GLenum_GLenum_GLsizei_GLint;
typedef void (*FUNC_void_GLenum_GLsizei_GLuint)(GLenum map, GLsizei bufSize, GLuint values);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLuint a3;
} ARGS_void_GLenum_GLsizei_GLuint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLuint func;
    ARGS_void_GLenum_GLsizei_GLuint args;
} PACKED_void_GLenum_GLsizei_GLuint;
typedef void (*FUNC_void_GLenum_GLsizei_GLushort)(GLenum map, GLsizei bufSize, GLushort values);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLushort a3;
} ARGS_void_GLenum_GLsizei_GLushort;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLushort func;
    ARGS_void_GLenum_GLsizei_GLushort args;
} PACKED_void_GLenum_GLsizei_GLushort;
typedef void (*FUNC_void_GLsizei_GLubyte)(GLsizei bufSize, GLubyte pattern);
typedef struct {
    GLsizei a1;
    GLubyte a2;
} ARGS_void_GLsizei_GLubyte;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLubyte func;
    ARGS_void_GLsizei_GLubyte args;
} PACKED_void_GLsizei_GLubyte;
typedef void (*FUNC_void_GLenum_GLenum_GLenum_GLsizei_GLvoid_GLsizei_GLvoid_GLvoid)(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, GLvoid row, GLsizei columnBufSize, GLvoid column, GLvoid span);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLenum a3;
    GLsizei a4;
    GLvoid a5;
    GLsizei a6;
    GLvoid a7;
    GLvoid a8;
} ARGS_void_GLenum_GLenum_GLenum_GLsizei_GLvoid_GLsizei_GLvoid_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLenum_GLsizei_GLvoid_GLsizei_GLvoid_GLvoid func;
    ARGS_void_GLenum_GLenum_GLenum_GLsizei_GLvoid_GLsizei_GLvoid_GLvoid args;
} PACKED_void_GLenum_GLenum_GLenum_GLsizei_GLvoid_GLsizei_GLvoid_GLvoid;
typedef void (*FUNC_void_GLenum_GLint_GLenum_GLenum_GLsizei_GLvoid)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid img);
typedef struct {
    GLenum a1;
    GLint a2;
    GLenum a3;
    GLenum a4;
    GLsizei a5;
    GLvoid a6;
} ARGS_void_GLenum_GLint_GLenum_GLenum_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLenum_GLenum_GLsizei_GLvoid func;
    ARGS_void_GLenum_GLint_GLenum_GLenum_GLsizei_GLvoid args;
} PACKED_void_GLenum_GLint_GLenum_GLenum_GLsizei_GLvoid;
typedef void (*FUNC_void_GLuint_GLint_GLsizei_GLdouble)(GLuint program, GLint location, GLsizei bufSize, GLdouble params);
typedef struct {
    GLuint a1;
    GLint a2;
    GLsizei a3;
    GLdouble a4;
} ARGS_void_GLuint_GLint_GLsizei_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLsizei_GLdouble func;
    ARGS_void_GLuint_GLint_GLsizei_GLdouble args;
} PACKED_void_GLuint_GLint_GLsizei_GLdouble;
typedef void (*FUNC_void_GLuint_GLint_GLsizei_GLfloat)(GLuint program, GLint location, GLsizei bufSize, GLfloat params);
typedef struct {
    GLuint a1;
    GLint a2;
    GLsizei a3;
    GLfloat a4;
} ARGS_void_GLuint_GLint_GLsizei_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLsizei_GLfloat func;
    ARGS_void_GLuint_GLint_GLsizei_GLfloat args;
} PACKED_void_GLuint_GLint_GLsizei_GLfloat;
typedef void (*FUNC_void_GLuint_GLint_GLsizei_GLint)(GLuint program, GLint location, GLsizei bufSize, GLint params);
typedef struct {
    GLuint a1;
    GLint a2;
    GLsizei a3;
    GLint a4;
} ARGS_void_GLuint_GLint_GLsizei_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLsizei_GLint func;
    ARGS_void_GLuint_GLint_GLsizei_GLint args;
} PACKED_void_GLuint_GLint_GLsizei_GLint;
typedef void (*FUNC_void_GLuint_GLint_GLsizei_GLuint)(GLuint program, GLint location, GLsizei bufSize, GLuint params);
typedef struct {
    GLuint a1;
    GLint a2;
    GLsizei a3;
    GLuint a4;
} ARGS_void_GLuint_GLint_GLsizei_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLsizei_GLuint func;
    ARGS_void_GLuint_GLint_GLsizei_GLuint args;
} PACKED_void_GLuint_GLint_GLsizei_GLuint;
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
typedef sync (*FUNC_sync_GLenum_GLintptr_GLbitfield)(GLenum external_sync_type, GLintptr external_sync, GLbitfield flags);
typedef struct {
    GLenum a1;
    GLintptr a2;
    GLbitfield a3;
} ARGS_sync_GLenum_GLintptr_GLbitfield;
typedef struct {
    int format;
    FUNC_sync_GLenum_GLintptr_GLbitfield func;
    ARGS_sync_GLenum_GLintptr_GLbitfield args;
} PACKED_sync_GLenum_GLintptr_GLbitfield;
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
typedef void (*FUNC_void_GLenum_GLsizei_GLsizei_GLvoid)(GLenum type, GLsizei stride, GLsizei count, GLvoid pointer);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLsizei a3;
    GLvoid a4;
} ARGS_void_GLenum_GLsizei_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLsizei_GLvoid func;
    ARGS_void_GLenum_GLsizei_GLsizei_GLvoid args;
} PACKED_void_GLenum_GLsizei_GLsizei_GLvoid;
typedef void (*FUNC_void_GLsizei_GLint)(GLsizei size, GLint buffer);
typedef struct {
    GLsizei a1;
    GLint a2;
} ARGS_void_GLsizei_GLint;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLint func;
    ARGS_void_GLsizei_GLint args;
} PACKED_void_GLsizei_GLint;
typedef void (*FUNC_void_GLuint_GLuint_GLuint_GLfloat)(GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLuint a3;
    GLfloat a4;
} ARGS_void_GLuint_GLuint_GLuint_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLuint_GLfloat func;
    ARGS_void_GLuint_GLuint_GLuint_GLfloat args;
} PACKED_void_GLuint_GLuint_GLuint_GLfloat;
typedef void (*FUNC_void_GLenum_GLsizei_GLenum)(GLenum target, GLsizei numAttachments, GLenum attachments);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLenum a3;
} ARGS_void_GLenum_GLsizei_GLenum;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLenum func;
    ARGS_void_GLenum_GLsizei_GLenum args;
} PACKED_void_GLenum_GLsizei_GLenum;
typedef void (*FUNC_void_GLenum_GLsizei_GLenum_GLint_GLint_GLsizei_GLsizei)(GLenum target, GLsizei numAttachments, GLenum attachments, GLint x, GLint y, GLsizei width, GLsizei height);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLenum a3;
    GLint a4;
    GLint a5;
    GLsizei a6;
    GLsizei a7;
} ARGS_void_GLenum_GLsizei_GLenum_GLint_GLint_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLenum_GLint_GLint_GLsizei_GLsizei func;
    ARGS_void_GLenum_GLsizei_GLenum_GLint_GLint_GLsizei_GLsizei args;
} PACKED_void_GLenum_GLsizei_GLenum_GLint_GLint_GLsizei_GLsizei;
typedef void (*FUNC_void_GLuint_GLint)(GLuint texture, GLint level);
typedef struct {
    GLuint a1;
    GLint a2;
} ARGS_void_GLuint_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint func;
    ARGS_void_GLuint_GLint args;
} PACKED_void_GLuint_GLint;
typedef void (*FUNC_void_GLuint_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei)(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
typedef struct {
    GLuint a1;
    GLint a2;
    GLint a3;
    GLint a4;
    GLint a5;
    GLsizei a6;
    GLsizei a7;
    GLsizei a8;
} ARGS_void_GLuint_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei func;
    ARGS_void_GLuint_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei args;
} PACKED_void_GLuint_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei;
typedef Boolean (*FUNC_Boolean_GLuint)(GLuint marker);
typedef struct {
    GLuint a1;
} ARGS_Boolean_GLuint;
typedef struct {
    int format;
    FUNC_Boolean_GLuint func;
    ARGS_Boolean_GLuint args;
} PACKED_Boolean_GLuint;
typedef Boolean (*FUNC_Boolean_GLenum)(GLenum target);
typedef struct {
    GLenum a1;
} ARGS_Boolean_GLenum;
typedef struct {
    int format;
    FUNC_Boolean_GLenum func;
    ARGS_Boolean_GLenum args;
} PACKED_Boolean_GLenum;
typedef Boolean (*FUNC_Boolean_GLenum_GLuint)(GLenum target, GLuint index);
typedef struct {
    GLenum a1;
    GLuint a2;
} ARGS_Boolean_GLenum_GLuint;
typedef struct {
    int format;
    FUNC_Boolean_GLenum_GLuint func;
    ARGS_Boolean_GLenum_GLuint args;
} PACKED_Boolean_GLenum_GLuint;
typedef Boolean (*FUNC_Boolean_GLuint64)(GLuint64 handle);
typedef struct {
    GLuint64 a1;
} ARGS_Boolean_GLuint64;
typedef struct {
    int format;
    FUNC_Boolean_GLuint64 func;
    ARGS_Boolean_GLuint64 args;
} PACKED_Boolean_GLuint64;
typedef Boolean (*FUNC_Boolean_GLint_GLchar)(GLint namelen, GLchar name);
typedef struct {
    GLint a1;
    GLchar a2;
} ARGS_Boolean_GLint_GLchar;
typedef struct {
    int format;
    FUNC_Boolean_GLint_GLchar func;
    ARGS_Boolean_GLint_GLchar args;
} PACKED_Boolean_GLint_GLchar;
typedef Boolean (*FUNC_Boolean_GLuint_GLuint_GLfloat_GLfloat)(GLuint path, GLuint mask, GLfloat x, GLfloat y);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLfloat a3;
    GLfloat a4;
} ARGS_Boolean_GLuint_GLuint_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_Boolean_GLuint_GLuint_GLfloat_GLfloat func;
    ARGS_Boolean_GLuint_GLuint_GLfloat_GLfloat args;
} PACKED_Boolean_GLuint_GLuint_GLfloat_GLfloat;
typedef Boolean (*FUNC_Boolean_GLuint_GLfloat_GLfloat)(GLuint path, GLfloat x, GLfloat y);
typedef struct {
    GLuint a1;
    GLfloat a2;
    GLfloat a3;
} ARGS_Boolean_GLuint_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_Boolean_GLuint_GLfloat_GLfloat func;
    ARGS_Boolean_GLuint_GLfloat_GLfloat args;
} PACKED_Boolean_GLuint_GLfloat_GLfloat;
typedef Boolean (*FUNC_Boolean_GLsync)(GLsync sync);
typedef struct {
    GLsync a1;
} ARGS_Boolean_GLsync;
typedef struct {
    int format;
    FUNC_Boolean_GLsync func;
    ARGS_Boolean_GLsync args;
} PACKED_Boolean_GLsync;
typedef Boolean (*FUNC_Boolean_GLuint_GLenum)(GLuint id, GLenum cap);
typedef struct {
    GLuint a1;
    GLenum a2;
} ARGS_Boolean_GLuint_GLenum;
typedef struct {
    int format;
    FUNC_Boolean_GLuint_GLenum func;
    ARGS_Boolean_GLuint_GLenum args;
} PACKED_Boolean_GLuint_GLenum;
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
typedef void (*FUNC_void_GLenum_GLuint_GLsizei_GLubyte)(GLenum target, GLuint id, GLsizei len, GLubyte program);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLsizei a3;
    GLubyte a4;
} ARGS_void_GLenum_GLuint_GLsizei_GLubyte;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLsizei_GLubyte func;
    ARGS_void_GLenum_GLuint_GLsizei_GLubyte args;
} PACKED_void_GLenum_GLuint_GLsizei_GLubyte;
typedef void (*FUNC_void_GLint_GLsizei)(GLint first, GLsizei count);
typedef struct {
    GLint a1;
    GLsizei a2;
} ARGS_void_GLint_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLint_GLsizei func;
    ARGS_void_GLint_GLsizei args;
} PACKED_void_GLint_GLsizei;
typedef void (*FUNC_void_GLuint64)(GLuint64 handle);
typedef struct {
    GLuint64 a1;
} ARGS_void_GLuint64;
typedef struct {
    int format;
    FUNC_void_GLuint64 func;
    ARGS_void_GLuint64 args;
} PACKED_void_GLuint64;
typedef void (*FUNC_void_GLuint64_GLenum)(GLuint64 handle, GLenum access);
typedef struct {
    GLuint64 a1;
    GLenum a2;
} ARGS_void_GLuint64_GLenum;
typedef struct {
    int format;
    FUNC_void_GLuint64_GLenum func;
    ARGS_void_GLuint64_GLenum args;
} PACKED_void_GLuint64_GLenum;
typedef void (*FUNC_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble)(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, GLdouble points);
typedef struct {
    GLenum a1;
    GLdouble a2;
    GLdouble a3;
    GLint a4;
    GLint a5;
    GLdouble a6;
} ARGS_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble func;
    ARGS_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble args;
} PACKED_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble;
typedef void (*FUNC_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat)(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, GLfloat points);
typedef struct {
    GLenum a1;
    GLfloat a2;
    GLfloat a3;
    GLint a4;
    GLint a5;
    GLfloat a6;
} ARGS_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat func;
    ARGS_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat args;
} PACKED_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat;
typedef void (*FUNC_void_GLenum_GLfixed_GLfixed_GLint_GLint_GLfixed)(GLenum target, GLfixed u1, GLfixed u2, GLint stride, GLint order, GLfixed points);
typedef struct {
    GLenum a1;
    GLfixed a2;
    GLfixed a3;
    GLint a4;
    GLint a5;
    GLfixed a6;
} ARGS_void_GLenum_GLfixed_GLfixed_GLint_GLint_GLfixed;
typedef struct {
    int format;
    FUNC_void_GLenum_GLfixed_GLfixed_GLint_GLint_GLfixed func;
    ARGS_void_GLenum_GLfixed_GLfixed_GLint_GLint_GLfixed args;
} PACKED_void_GLenum_GLfixed_GLfixed_GLint_GLint_GLfixed;
typedef void (*FUNC_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble points);
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
    GLdouble a10;
} ARGS_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble func;
    ARGS_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble args;
} PACKED_void_GLenum_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble;
typedef void (*FUNC_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat points);
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
    GLfloat a10;
} ARGS_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat func;
    ARGS_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat args;
} PACKED_void_GLenum_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat;
typedef void (*FUNC_void_GLenum_GLfixed_GLfixed_GLint_GLint_GLfixed_GLfixed_GLint_GLint_GLfixed)(GLenum target, GLfixed u1, GLfixed u2, GLint ustride, GLint uorder, GLfixed v1, GLfixed v2, GLint vstride, GLint vorder, GLfixed points);
typedef struct {
    GLenum a1;
    GLfixed a2;
    GLfixed a3;
    GLint a4;
    GLint a5;
    GLfixed a6;
    GLfixed a7;
    GLint a8;
    GLint a9;
    GLfixed a10;
} ARGS_void_GLenum_GLfixed_GLfixed_GLint_GLint_GLfixed_GLfixed_GLint_GLint_GLfixed;
typedef struct {
    int format;
    FUNC_void_GLenum_GLfixed_GLfixed_GLint_GLint_GLfixed_GLfixed_GLint_GLint_GLfixed func;
    ARGS_void_GLenum_GLfixed_GLfixed_GLint_GLint_GLfixed_GLfixed_GLint_GLint_GLfixed args;
} PACKED_void_GLenum_GLfixed_GLfixed_GLint_GLint_GLfixed_GLfixed_GLint_GLint_GLfixed;
typedef VoidPointer (*FUNC_VoidPointer_GLenum_GLenum)(GLenum target, GLenum access);
typedef struct {
    GLenum a1;
    GLenum a2;
} ARGS_VoidPointer_GLenum_GLenum;
typedef struct {
    int format;
    FUNC_VoidPointer_GLenum_GLenum func;
    ARGS_VoidPointer_GLenum_GLenum args;
} PACKED_VoidPointer_GLenum_GLenum;
typedef VoidPointer (*FUNC_VoidPointer_GLenum_GLintptr_GLsizeiptr_GLbitfield)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef struct {
    GLenum a1;
    GLintptr a2;
    GLsizeiptr a3;
    GLbitfield a4;
} ARGS_VoidPointer_GLenum_GLintptr_GLsizeiptr_GLbitfield;
typedef struct {
    int format;
    FUNC_VoidPointer_GLenum_GLintptr_GLsizeiptr_GLbitfield func;
    ARGS_VoidPointer_GLenum_GLintptr_GLsizeiptr_GLbitfield args;
} PACKED_VoidPointer_GLenum_GLintptr_GLsizeiptr_GLbitfield;
typedef void (*FUNC_void_GLenum_GLuint_GLenum_GLsizei_GLsizei_GLint_GLint_GLboolean_GLvoid)(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLint uorder, GLint vorder, GLboolean packed, GLvoid points);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLenum a3;
    GLsizei a4;
    GLsizei a5;
    GLint a6;
    GLint a7;
    GLboolean a8;
    GLvoid a9;
} ARGS_void_GLenum_GLuint_GLenum_GLsizei_GLsizei_GLint_GLint_GLboolean_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLenum_GLsizei_GLsizei_GLint_GLint_GLboolean_GLvoid func;
    ARGS_void_GLenum_GLuint_GLenum_GLsizei_GLsizei_GLint_GLint_GLboolean_GLvoid args;
} PACKED_void_GLenum_GLuint_GLenum_GLsizei_GLsizei_GLint_GLint_GLboolean_GLvoid;
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
typedef void (*FUNC_void_GLint_GLfixed_GLfixed)(GLint n, GLfixed u1, GLfixed u2);
typedef struct {
    GLint a1;
    GLfixed a2;
    GLfixed a3;
} ARGS_void_GLint_GLfixed_GLfixed;
typedef struct {
    int format;
    FUNC_void_GLint_GLfixed_GLfixed func;
    ARGS_void_GLint_GLfixed_GLfixed args;
} PACKED_void_GLint_GLfixed_GLfixed;
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
typedef void (*FUNC_void_GLint_GLfixed_GLfixed_GLfixed_GLfixed)(GLint n, GLfixed u1, GLfixed u2, GLfixed v1, GLfixed v2);
typedef struct {
    GLint a1;
    GLfixed a2;
    GLfixed a3;
    GLfixed a4;
    GLfixed a5;
} ARGS_void_GLint_GLfixed_GLfixed_GLfixed_GLfixed;
typedef struct {
    int format;
    FUNC_void_GLint_GLfixed_GLfixed_GLfixed_GLfixed func;
    ARGS_void_GLint_GLfixed_GLfixed_GLfixed_GLfixed args;
} PACKED_void_GLint_GLfixed_GLfixed_GLfixed_GLfixed;
typedef VoidPointer (*FUNC_VoidPointer_GLuint_GLenum)(GLuint buffer, GLenum access);
typedef struct {
    GLuint a1;
    GLenum a2;
} ARGS_VoidPointer_GLuint_GLenum;
typedef struct {
    int format;
    FUNC_VoidPointer_GLuint_GLenum func;
    ARGS_VoidPointer_GLuint_GLenum args;
} PACKED_VoidPointer_GLuint_GLenum;
typedef VoidPointer (*FUNC_VoidPointer_GLuint_GLintptr_GLsizeiptr_GLbitfield)(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
typedef struct {
    GLuint a1;
    GLintptr a2;
    GLsizeiptr a3;
    GLbitfield a4;
} ARGS_VoidPointer_GLuint_GLintptr_GLsizeiptr_GLbitfield;
typedef struct {
    int format;
    FUNC_VoidPointer_GLuint_GLintptr_GLsizeiptr_GLbitfield func;
    ARGS_VoidPointer_GLuint_GLintptr_GLsizeiptr_GLbitfield args;
} PACKED_VoidPointer_GLuint_GLintptr_GLsizeiptr_GLbitfield;
typedef VoidPointer (*FUNC_VoidPointer_GLuint)(GLuint buffer);
typedef struct {
    GLuint a1;
} ARGS_VoidPointer_GLuint;
typedef struct {
    int format;
    FUNC_VoidPointer_GLuint func;
    ARGS_VoidPointer_GLuint args;
} PACKED_VoidPointer_GLuint;
typedef VoidPointer (*FUNC_VoidPointer_GLuint_GLint_GLbitfield_GLint_GLenum)(GLuint texture, GLint level, GLbitfield access, GLint stride, GLenum layout);
typedef struct {
    GLuint a1;
    GLint a2;
    GLbitfield a3;
    GLint a4;
    GLenum a5;
} ARGS_VoidPointer_GLuint_GLint_GLbitfield_GLint_GLenum;
typedef struct {
    int format;
    FUNC_VoidPointer_GLuint_GLint_GLbitfield_GLint_GLenum func;
    ARGS_VoidPointer_GLuint_GLint_GLbitfield_GLint_GLenum args;
} PACKED_VoidPointer_GLuint_GLint_GLbitfield_GLint_GLenum;
typedef void (*FUNC_void_GLuint_GLuint_GLdouble_GLdouble_GLint_GLint_GLdouble)(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint stride, GLint order, GLdouble points);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLdouble a3;
    GLdouble a4;
    GLint a5;
    GLint a6;
    GLdouble a7;
} ARGS_void_GLuint_GLuint_GLdouble_GLdouble_GLint_GLint_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLdouble_GLdouble_GLint_GLint_GLdouble func;
    ARGS_void_GLuint_GLuint_GLdouble_GLdouble_GLint_GLint_GLdouble args;
} PACKED_void_GLuint_GLuint_GLdouble_GLdouble_GLint_GLint_GLdouble;
typedef void (*FUNC_void_GLuint_GLuint_GLfloat_GLfloat_GLint_GLint_GLfloat)(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint stride, GLint order, GLfloat points);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLfloat a3;
    GLfloat a4;
    GLint a5;
    GLint a6;
    GLfloat a7;
} ARGS_void_GLuint_GLuint_GLfloat_GLfloat_GLint_GLint_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLfloat_GLfloat_GLint_GLint_GLfloat func;
    ARGS_void_GLuint_GLuint_GLfloat_GLfloat_GLint_GLint_GLfloat args;
} PACKED_void_GLuint_GLuint_GLfloat_GLfloat_GLint_GLint_GLfloat;
typedef void (*FUNC_void_GLuint_GLuint_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble)(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble points);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLdouble a3;
    GLdouble a4;
    GLint a5;
    GLint a6;
    GLdouble a7;
    GLdouble a8;
    GLint a9;
    GLint a10;
    GLdouble a11;
} ARGS_void_GLuint_GLuint_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble func;
    ARGS_void_GLuint_GLuint_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble args;
} PACKED_void_GLuint_GLuint_GLdouble_GLdouble_GLint_GLint_GLdouble_GLdouble_GLint_GLint_GLdouble;
typedef void (*FUNC_void_GLuint_GLuint_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat)(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat points);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLfloat a3;
    GLfloat a4;
    GLint a5;
    GLint a6;
    GLfloat a7;
    GLfloat a8;
    GLint a9;
    GLint a10;
    GLfloat a11;
} ARGS_void_GLuint_GLuint_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat func;
    ARGS_void_GLuint_GLuint_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat args;
} PACKED_void_GLuint_GLuint_GLfloat_GLfloat_GLint_GLint_GLfloat_GLfloat_GLint_GLint_GLfloat;
typedef void (*FUNC_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble)(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
typedef struct {
    GLenum a1;
    GLdouble a2;
    GLdouble a3;
    GLdouble a4;
    GLdouble a5;
    GLdouble a6;
    GLdouble a7;
} ARGS_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble func;
    ARGS_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble args;
} PACKED_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble_GLdouble;
typedef void (*FUNC_void_GLint_GLubyte)(GLint size, GLubyte indices);
typedef struct {
    GLint a1;
    GLubyte a2;
} ARGS_void_GLint_GLubyte;
typedef struct {
    int format;
    FUNC_void_GLint_GLubyte func;
    ARGS_void_GLint_GLubyte args;
} PACKED_void_GLint_GLubyte;
typedef void (*FUNC_void_GLint_GLuint)(GLint size, GLuint indices);
typedef struct {
    GLint a1;
    GLuint a2;
} ARGS_void_GLint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLint_GLuint func;
    ARGS_void_GLint_GLuint args;
} PACKED_void_GLint_GLuint;
typedef void (*FUNC_void_GLenum_GLdouble_GLdouble_GLdouble_GLdouble)(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
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
typedef void (*FUNC_void_GLenum_GLfloat_GLfloat_GLfloat_GLfloat)(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
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
typedef void (*FUNC_void_GLenum_GLdouble_GLdouble_GLdouble)(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
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
typedef void (*FUNC_void_GLenum_GLfloat_GLfloat_GLfloat)(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
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
typedef void (*FUNC_void_GLenum_void___GENPT___GLsizei_GLsizei)(GLenum mode, void * indirect, GLsizei drawcount, GLsizei stride);
typedef struct {
    GLenum a1;
    void * a2;
    GLsizei a3;
    GLsizei a4;
} ARGS_void_GLenum_void___GENPT___GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_void___GENPT___GLsizei_GLsizei func;
    ARGS_void_GLenum_void___GENPT___GLsizei_GLsizei args;
} PACKED_void_GLenum_void___GENPT___GLsizei_GLsizei;
typedef void (*FUNC_void_GLenum_GLvoid_GLsizei_GLsizei)(GLenum mode, GLvoid indirect, GLsizei primcount, GLsizei stride);
typedef struct {
    GLenum a1;
    GLvoid a2;
    GLsizei a3;
    GLsizei a4;
} ARGS_void_GLenum_GLvoid_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLvoid_GLsizei_GLsizei func;
    ARGS_void_GLenum_GLvoid_GLsizei_GLsizei args;
} PACKED_void_GLenum_GLvoid_GLsizei_GLsizei;
typedef void (*FUNC_void_GLenum_GLsizei_GLenum_GLvoid__GENPT__const_GLsizei)(GLenum mode, GLsizei count, GLenum type, GLvoid*const indices, GLsizei drawcount);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLenum a3;
    GLvoid*const a4;
    GLsizei a5;
} ARGS_void_GLenum_GLsizei_GLenum_GLvoid__GENPT__const_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLenum_GLvoid__GENPT__const_GLsizei func;
    ARGS_void_GLenum_GLsizei_GLenum_GLvoid__GENPT__const_GLsizei args;
} PACKED_void_GLenum_GLsizei_GLenum_GLvoid__GENPT__const_GLsizei;
typedef void (*FUNC_void_GLenum_GLsizei_GLenum_GLvoid__GENPT__const_GLsizei_GLint)(GLenum mode, GLsizei count, GLenum type, GLvoid*const indices, GLsizei drawcount, GLint basevertex);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLenum a3;
    GLvoid*const a4;
    GLsizei a5;
    GLint a6;
} ARGS_void_GLenum_GLsizei_GLenum_GLvoid__GENPT__const_GLsizei_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLenum_GLvoid__GENPT__const_GLsizei_GLint func;
    ARGS_void_GLenum_GLsizei_GLenum_GLvoid__GENPT__const_GLsizei_GLint args;
} PACKED_void_GLenum_GLsizei_GLenum_GLvoid__GENPT__const_GLsizei_GLint;
typedef void (*FUNC_void_GLenum_GLsizei_GLenum_GLvoid___GENPT___GLsizei)(GLenum mode, GLsizei count, GLenum type, GLvoid * indices, GLsizei primcount);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLenum a3;
    GLvoid * a4;
    GLsizei a5;
} ARGS_void_GLenum_GLsizei_GLenum_GLvoid___GENPT___GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLenum_GLvoid___GENPT___GLsizei func;
    ARGS_void_GLenum_GLsizei_GLenum_GLvoid___GENPT___GLsizei args;
} PACKED_void_GLenum_GLsizei_GLenum_GLvoid___GENPT___GLsizei;
typedef void (*FUNC_void_GLenum_GLenum_void___GENPT___GLsizei_GLsizei)(GLenum mode, GLenum type, void * indirect, GLsizei drawcount, GLsizei stride);
typedef struct {
    GLenum a1;
    GLenum a2;
    void * a3;
    GLsizei a4;
    GLsizei a5;
} ARGS_void_GLenum_GLenum_void___GENPT___GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_void___GENPT___GLsizei_GLsizei func;
    ARGS_void_GLenum_GLenum_void___GENPT___GLsizei_GLsizei args;
} PACKED_void_GLenum_GLenum_void___GENPT___GLsizei_GLsizei;
typedef void (*FUNC_void_GLenum_GLenum_GLvoid_GLsizei_GLsizei)(GLenum mode, GLenum type, GLvoid indirect, GLsizei primcount, GLsizei stride);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLvoid a3;
    GLsizei a4;
    GLsizei a5;
} ARGS_void_GLenum_GLenum_GLvoid_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLvoid_GLsizei_GLsizei func;
    ARGS_void_GLenum_GLenum_GLvoid_GLsizei_GLsizei args;
} PACKED_void_GLenum_GLenum_GLvoid_GLsizei_GLsizei;
typedef void (*FUNC_void_GLenum_GLuint_GLuint_GLint_GLsizei_GLsizei)(GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count, GLsizei primcount);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLuint a3;
    GLint a4;
    GLsizei a5;
    GLsizei a6;
} ARGS_void_GLenum_GLuint_GLuint_GLint_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLuint_GLint_GLsizei_GLsizei func;
    ARGS_void_GLenum_GLuint_GLuint_GLint_GLsizei_GLsizei args;
} PACKED_void_GLenum_GLuint_GLuint_GLint_GLsizei_GLsizei;
typedef void (*FUNC_void_GLenum_GLint_GLsizei_GLsizei_GLint)(GLenum mode, GLint first, GLsizei count, GLsizei primcount, GLint modestride);
typedef struct {
    GLenum a1;
    GLint a2;
    GLsizei a3;
    GLsizei a4;
    GLint a5;
} ARGS_void_GLenum_GLint_GLsizei_GLsizei_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLsizei_GLsizei_GLint func;
    ARGS_void_GLenum_GLint_GLsizei_GLsizei_GLint args;
} PACKED_void_GLenum_GLint_GLsizei_GLsizei_GLint;
typedef void (*FUNC_void_GLenum_GLbyte)(GLenum texture, GLbyte s);
typedef struct {
    GLenum a1;
    GLbyte a2;
} ARGS_void_GLenum_GLbyte;
typedef struct {
    int format;
    FUNC_void_GLenum_GLbyte func;
    ARGS_void_GLenum_GLbyte args;
} PACKED_void_GLenum_GLbyte;
typedef void (*FUNC_void_GLenum_GLhalfNV)(GLenum target, GLhalfNV s);
typedef struct {
    GLenum a1;
    GLhalfNV a2;
} ARGS_void_GLenum_GLhalfNV;
typedef struct {
    int format;
    FUNC_void_GLenum_GLhalfNV func;
    ARGS_void_GLenum_GLhalfNV args;
} PACKED_void_GLenum_GLhalfNV;
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
typedef void (*FUNC_void_GLenum_GLbyte_GLbyte)(GLenum texture, GLbyte s, GLbyte t);
typedef struct {
    GLenum a1;
    GLbyte a2;
    GLbyte a3;
} ARGS_void_GLenum_GLbyte_GLbyte;
typedef struct {
    int format;
    FUNC_void_GLenum_GLbyte_GLbyte func;
    ARGS_void_GLenum_GLbyte_GLbyte args;
} PACKED_void_GLenum_GLbyte_GLbyte;
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
typedef void (*FUNC_void_GLenum_GLhalfNV_GLhalfNV)(GLenum target, GLhalfNV s, GLhalfNV t);
typedef struct {
    GLenum a1;
    GLhalfNV a2;
    GLhalfNV a3;
} ARGS_void_GLenum_GLhalfNV_GLhalfNV;
typedef struct {
    int format;
    FUNC_void_GLenum_GLhalfNV_GLhalfNV func;
    ARGS_void_GLenum_GLhalfNV_GLhalfNV args;
} PACKED_void_GLenum_GLhalfNV_GLhalfNV;
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
typedef void (*FUNC_void_GLenum_GLfixed_GLfixed)(GLenum texture, GLfixed s, GLfixed t);
typedef struct {
    GLenum a1;
    GLfixed a2;
    GLfixed a3;
} ARGS_void_GLenum_GLfixed_GLfixed;
typedef struct {
    int format;
    FUNC_void_GLenum_GLfixed_GLfixed func;
    ARGS_void_GLenum_GLfixed_GLfixed args;
} PACKED_void_GLenum_GLfixed_GLfixed;
typedef void (*FUNC_void_GLenum_GLbyte_GLbyte_GLbyte)(GLenum texture, GLbyte s, GLbyte t, GLbyte r);
typedef struct {
    GLenum a1;
    GLbyte a2;
    GLbyte a3;
    GLbyte a4;
} ARGS_void_GLenum_GLbyte_GLbyte_GLbyte;
typedef struct {
    int format;
    FUNC_void_GLenum_GLbyte_GLbyte_GLbyte func;
    ARGS_void_GLenum_GLbyte_GLbyte_GLbyte args;
} PACKED_void_GLenum_GLbyte_GLbyte_GLbyte;
typedef void (*FUNC_void_GLenum_GLhalfNV_GLhalfNV_GLhalfNV)(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r);
typedef struct {
    GLenum a1;
    GLhalfNV a2;
    GLhalfNV a3;
    GLhalfNV a4;
} ARGS_void_GLenum_GLhalfNV_GLhalfNV_GLhalfNV;
typedef struct {
    int format;
    FUNC_void_GLenum_GLhalfNV_GLhalfNV_GLhalfNV func;
    ARGS_void_GLenum_GLhalfNV_GLhalfNV_GLhalfNV args;
} PACKED_void_GLenum_GLhalfNV_GLhalfNV_GLhalfNV;
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
typedef void (*FUNC_void_GLenum_GLfixed_GLfixed_GLfixed)(GLenum texture, GLfixed s, GLfixed t, GLfixed r);
typedef struct {
    GLenum a1;
    GLfixed a2;
    GLfixed a3;
    GLfixed a4;
} ARGS_void_GLenum_GLfixed_GLfixed_GLfixed;
typedef struct {
    int format;
    FUNC_void_GLenum_GLfixed_GLfixed_GLfixed func;
    ARGS_void_GLenum_GLfixed_GLfixed_GLfixed args;
} PACKED_void_GLenum_GLfixed_GLfixed_GLfixed;
typedef void (*FUNC_void_GLenum_GLbyte_GLbyte_GLbyte_GLbyte)(GLenum texture, GLbyte s, GLbyte t, GLbyte r, GLbyte q);
typedef struct {
    GLenum a1;
    GLbyte a2;
    GLbyte a3;
    GLbyte a4;
    GLbyte a5;
} ARGS_void_GLenum_GLbyte_GLbyte_GLbyte_GLbyte;
typedef struct {
    int format;
    FUNC_void_GLenum_GLbyte_GLbyte_GLbyte_GLbyte func;
    ARGS_void_GLenum_GLbyte_GLbyte_GLbyte_GLbyte args;
} PACKED_void_GLenum_GLbyte_GLbyte_GLbyte_GLbyte;
typedef void (*FUNC_void_GLenum_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV)(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
typedef struct {
    GLenum a1;
    GLhalfNV a2;
    GLhalfNV a3;
    GLhalfNV a4;
    GLhalfNV a5;
} ARGS_void_GLenum_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV;
typedef struct {
    int format;
    FUNC_void_GLenum_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV func;
    ARGS_void_GLenum_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV args;
} PACKED_void_GLenum_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV;
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
typedef void (*FUNC_void_GLenum_GLfixed_GLfixed_GLfixed_GLfixed)(GLenum texture, GLfixed s, GLfixed t, GLfixed r, GLfixed q);
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
typedef void (*FUNC_void_GLenum_GLint_GLenum_GLsizei_GLvoid)(GLenum texunit, GLint size, GLenum type, GLsizei stride, GLvoid pointer);
typedef struct {
    GLenum a1;
    GLint a2;
    GLenum a3;
    GLsizei a4;
    GLvoid a5;
} ARGS_void_GLenum_GLint_GLenum_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLenum_GLsizei_GLvoid func;
    ARGS_void_GLenum_GLint_GLenum_GLsizei_GLvoid args;
} PACKED_void_GLenum_GLint_GLenum_GLsizei_GLvoid;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLint_GLenum_GLenum_GLvoid)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLenum format, GLenum type, GLvoid pixels);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLenum a4;
    GLsizei a5;
    GLint a6;
    GLenum a7;
    GLenum a8;
    GLvoid a9;
} ARGS_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLint_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLint_GLenum_GLenum_GLvoid func;
    ARGS_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLint_GLenum_GLenum_GLvoid args;
} PACKED_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLint_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, GLvoid pixels);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLenum a4;
    GLsizei a5;
    GLsizei a6;
    GLint a7;
    GLenum a8;
    GLenum a9;
    GLvoid a10;
} ARGS_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid func;
    ARGS_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid args;
} PACKED_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid)(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid pixels);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLenum a4;
    GLsizei a5;
    GLsizei a6;
    GLsizei a7;
    GLint a8;
    GLenum a9;
    GLenum a10;
    GLvoid a11;
} ARGS_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid func;
    ARGS_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid args;
} PACKED_void_GLenum_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid pixels);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLint a4;
    GLsizei a5;
    GLenum a6;
    GLenum a7;
    GLvoid a8;
} ARGS_void_GLenum_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid func;
    ARGS_void_GLenum_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid args;
} PACKED_void_GLenum_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLint a4;
    GLint a5;
    GLsizei a6;
    GLsizei a7;
    GLenum a8;
    GLenum a9;
    GLvoid a10;
} ARGS_void_GLenum_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid func;
    ARGS_void_GLenum_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid args;
} PACKED_void_GLenum_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid)(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLvoid pixels);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLint a4;
    GLint a5;
    GLint a6;
    GLsizei a7;
    GLsizei a8;
    GLsizei a9;
    GLenum a10;
    GLenum a11;
    GLvoid a12;
} ARGS_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid func;
    ARGS_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid args;
} PACKED_void_GLenum_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLuint_GLsizeiptr_GLvoid_GLenum)(GLuint buffer, GLsizeiptr size, GLvoid data, GLenum usage);
typedef struct {
    GLuint a1;
    GLsizeiptr a2;
    GLvoid a3;
    GLenum a4;
} ARGS_void_GLuint_GLsizeiptr_GLvoid_GLenum;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizeiptr_GLvoid_GLenum func;
    ARGS_void_GLuint_GLsizeiptr_GLvoid_GLenum args;
} PACKED_void_GLuint_GLsizeiptr_GLvoid_GLenum;
typedef void (*FUNC_void_GLuint_GLuint_GLintptr_GLintptr_GLsizeiptr)(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLintptr a3;
    GLintptr a4;
    GLsizeiptr a5;
} ARGS_void_GLuint_GLuint_GLintptr_GLintptr_GLsizeiptr;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLintptr_GLintptr_GLsizeiptr func;
    ARGS_void_GLuint_GLuint_GLintptr_GLintptr_GLsizeiptr args;
} PACKED_void_GLuint_GLuint_GLintptr_GLintptr_GLsizeiptr;
typedef void (*FUNC_void_GLuint_GLenum_GLenum_GLuint_GLint)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLenum a3;
    GLuint a4;
    GLint a5;
} ARGS_void_GLuint_GLenum_GLenum_GLuint_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLenum_GLuint_GLint func;
    ARGS_void_GLuint_GLenum_GLenum_GLuint_GLint args;
} PACKED_void_GLuint_GLenum_GLenum_GLuint_GLint;
typedef void (*FUNC_void_GLuint_GLenum_GLenum_GLuint_GLint_GLint)(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLenum a3;
    GLuint a4;
    GLint a5;
    GLint a6;
} ARGS_void_GLuint_GLenum_GLenum_GLuint_GLint_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLenum_GLuint_GLint_GLint func;
    ARGS_void_GLuint_GLenum_GLenum_GLuint_GLint_GLint args;
} PACKED_void_GLuint_GLenum_GLenum_GLuint_GLint_GLint;
typedef void (*FUNC_void_GLuint_GLenum_GLuint_GLint_GLenum)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLuint a3;
    GLint a4;
    GLenum a5;
} ARGS_void_GLuint_GLenum_GLuint_GLint_GLenum;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLuint_GLint_GLenum func;
    ARGS_void_GLuint_GLenum_GLuint_GLint_GLenum args;
} PACKED_void_GLuint_GLenum_GLuint_GLint_GLenum;
typedef void (*FUNC_void_GLuint_GLenum_GLuint_GLint_GLint)(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLuint a3;
    GLint a4;
    GLint a5;
} ARGS_void_GLuint_GLenum_GLuint_GLint_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLuint_GLint_GLint func;
    ARGS_void_GLuint_GLenum_GLuint_GLint_GLint args;
} PACKED_void_GLuint_GLenum_GLuint_GLint_GLint;
typedef void (*FUNC_void_GLuint_GLenum_GLuint_GLdouble_GLdouble_GLdouble_GLdouble)(GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLuint a3;
    GLdouble a4;
    GLdouble a5;
    GLdouble a6;
    GLdouble a7;
} ARGS_void_GLuint_GLenum_GLuint_GLdouble_GLdouble_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLuint_GLdouble_GLdouble_GLdouble_GLdouble func;
    ARGS_void_GLuint_GLenum_GLuint_GLdouble_GLdouble_GLdouble_GLdouble args;
} PACKED_void_GLuint_GLenum_GLuint_GLdouble_GLdouble_GLdouble_GLdouble;
typedef void (*FUNC_void_GLuint_GLenum_GLuint_GLfloat_GLfloat_GLfloat_GLfloat)(GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLuint a3;
    GLfloat a4;
    GLfloat a5;
    GLfloat a6;
    GLfloat a7;
} ARGS_void_GLuint_GLenum_GLuint_GLfloat_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLuint_GLfloat_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLuint_GLenum_GLuint_GLfloat_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLuint_GLenum_GLuint_GLfloat_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLuint_GLenum_GLuint_GLint_GLint_GLint_GLint)(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLuint a3;
    GLint a4;
    GLint a5;
    GLint a6;
    GLint a7;
} ARGS_void_GLuint_GLenum_GLuint_GLint_GLint_GLint_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLuint_GLint_GLint_GLint_GLint func;
    ARGS_void_GLuint_GLenum_GLuint_GLint_GLint_GLint_GLint args;
} PACKED_void_GLuint_GLenum_GLuint_GLint_GLint_GLint_GLint;
typedef void (*FUNC_void_GLuint_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint)(GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLuint a3;
    GLuint a4;
    GLuint a5;
    GLuint a6;
    GLuint a7;
} ARGS_void_GLuint_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint func;
    ARGS_void_GLuint_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint args;
} PACKED_void_GLuint_GLenum_GLuint_GLuint_GLuint_GLuint_GLuint;
typedef void (*FUNC_void_GLuint_GLenum_GLuint_GLsizei_GLfloat)(GLuint program, GLenum target, GLuint index, GLsizei count, GLfloat params);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLuint a3;
    GLsizei a4;
    GLfloat a5;
} ARGS_void_GLuint_GLenum_GLuint_GLsizei_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLuint_GLsizei_GLfloat func;
    ARGS_void_GLuint_GLenum_GLuint_GLsizei_GLfloat args;
} PACKED_void_GLuint_GLenum_GLuint_GLsizei_GLfloat;
typedef void (*FUNC_void_GLuint_GLenum_GLuint_GLsizei_GLint)(GLuint program, GLenum target, GLuint index, GLsizei count, GLint params);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLuint a3;
    GLsizei a4;
    GLint a5;
} ARGS_void_GLuint_GLenum_GLuint_GLsizei_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLuint_GLsizei_GLint func;
    ARGS_void_GLuint_GLenum_GLuint_GLsizei_GLint args;
} PACKED_void_GLuint_GLenum_GLuint_GLsizei_GLint;
typedef void (*FUNC_void_GLuint_GLenum_GLuint_GLsizei_GLuint)(GLuint program, GLenum target, GLuint index, GLsizei count, GLuint params);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLuint a3;
    GLsizei a4;
    GLuint a5;
} ARGS_void_GLuint_GLenum_GLuint_GLsizei_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLuint_GLsizei_GLuint func;
    ARGS_void_GLuint_GLenum_GLuint_GLsizei_GLuint args;
} PACKED_void_GLuint_GLenum_GLuint_GLsizei_GLuint;
typedef void (*FUNC_void_GLuint_GLenum_GLenum_GLsizei_GLvoid)(GLuint program, GLenum target, GLenum format, GLsizei len, GLvoid string);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLenum a3;
    GLsizei a4;
    GLvoid a5;
} ARGS_void_GLuint_GLenum_GLenum_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLenum_GLsizei_GLvoid func;
    ARGS_void_GLuint_GLenum_GLenum_GLsizei_GLvoid args;
} PACKED_void_GLuint_GLenum_GLenum_GLsizei_GLvoid;
typedef void (*FUNC_void_GLuint_GLenum_GLsizei_GLsizei)(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLsizei a3;
    GLsizei a4;
} ARGS_void_GLuint_GLenum_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLsizei_GLsizei func;
    ARGS_void_GLuint_GLenum_GLsizei_GLsizei args;
} PACKED_void_GLuint_GLenum_GLsizei_GLsizei;
typedef void (*FUNC_void_GLuint_GLsizei_GLsizei_GLenum_GLsizei_GLsizei)(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLsizei a3;
    GLenum a4;
    GLsizei a5;
    GLsizei a6;
} ARGS_void_GLuint_GLsizei_GLsizei_GLenum_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLsizei_GLenum_GLsizei_GLsizei func;
    ARGS_void_GLuint_GLsizei_GLsizei_GLenum_GLsizei_GLsizei args;
} PACKED_void_GLuint_GLsizei_GLsizei_GLenum_GLsizei_GLsizei;
typedef void (*FUNC_void_GLuint_GLsizei_GLenum_GLsizei_GLsizei)(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLenum a3;
    GLsizei a4;
    GLsizei a5;
} ARGS_void_GLuint_GLsizei_GLenum_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLenum_GLsizei_GLsizei func;
    ARGS_void_GLuint_GLsizei_GLenum_GLsizei_GLsizei args;
} PACKED_void_GLuint_GLsizei_GLenum_GLsizei_GLsizei;
typedef void (*FUNC_void_GLenum_GLint_GLchar_GLint_GLchar)(GLenum type, GLint namelen, GLchar name, GLint stringlen, GLchar string);
typedef struct {
    GLenum a1;
    GLint a2;
    GLchar a3;
    GLint a4;
    GLchar a5;
} ARGS_void_GLenum_GLint_GLchar_GLint_GLchar;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLchar_GLint_GLchar func;
    ARGS_void_GLenum_GLint_GLchar_GLint_GLchar args;
} PACKED_void_GLenum_GLint_GLchar_GLint_GLchar;
typedef UInt32 (*FUNC_UInt32_GLsizei_GLvoid_GLenum)(GLsizei size, GLvoid pointer, GLenum usage);
typedef struct {
    GLsizei a1;
    GLvoid a2;
    GLenum a3;
} ARGS_UInt32_GLsizei_GLvoid_GLenum;
typedef struct {
    int format;
    FUNC_UInt32_GLsizei_GLvoid_GLenum func;
    ARGS_UInt32_GLsizei_GLvoid_GLenum args;
} PACKED_UInt32_GLsizei_GLvoid_GLenum;
typedef void (*FUNC_void_GLenum_GLuint_GLsizei_GLchar)(GLenum identifier, GLuint name, GLsizei length, GLchar label);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLsizei a3;
    GLchar a4;
} ARGS_void_GLenum_GLuint_GLsizei_GLchar;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLsizei_GLchar func;
    ARGS_void_GLenum_GLuint_GLsizei_GLchar args;
} PACKED_void_GLenum_GLuint_GLsizei_GLchar;
typedef void (*FUNC_void_void___GENPT___GLsizei_GLchar)(void * ptr, GLsizei length, GLchar label);
typedef struct {
    void * a1;
    GLsizei a2;
    GLchar a3;
} ARGS_void_void___GENPT___GLsizei_GLchar;
typedef struct {
    int format;
    FUNC_void_void___GENPT___GLsizei_GLchar func;
    ARGS_void_void___GENPT___GLsizei_GLchar args;
} PACKED_void_void___GENPT___GLsizei_GLchar;
typedef GLenum (*FUNC_GLenum_GLenum_GLuint_GLenum)(GLenum objectType, GLuint name, GLenum option);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLenum a3;
} ARGS_GLenum_GLenum_GLuint_GLenum;
typedef struct {
    int format;
    FUNC_GLenum_GLenum_GLuint_GLenum func;
    ARGS_GLenum_GLenum_GLuint_GLenum args;
} PACKED_GLenum_GLenum_GLuint_GLenum;
typedef void (*FUNC_void_GLuint_GLuint_GLenum)(GLuint dst, GLuint coord, GLenum swizzle);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLenum a3;
} ARGS_void_GLuint_GLuint_GLenum;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLenum func;
    ARGS_void_GLuint_GLuint_GLenum args;
} PACKED_void_GLuint_GLuint_GLenum;
typedef void (*FUNC_void_GLuint_GLsizei_GLubyte_GLsizei_GLenum_GLvoid)(GLuint path, GLsizei numCommands, GLubyte commands, GLsizei numCoords, GLenum coordType, GLvoid coords);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLubyte a3;
    GLsizei a4;
    GLenum a5;
    GLvoid a6;
} ARGS_void_GLuint_GLsizei_GLubyte_GLsizei_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLubyte_GLsizei_GLenum_GLvoid func;
    ARGS_void_GLuint_GLsizei_GLubyte_GLsizei_GLenum_GLvoid args;
} PACKED_void_GLuint_GLsizei_GLubyte_GLsizei_GLenum_GLvoid;
typedef void (*FUNC_void_GLuint_GLsizei_GLenum_GLvoid)(GLuint path, GLsizei numCoords, GLenum coordType, GLvoid coords);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLenum a3;
    GLvoid a4;
} ARGS_void_GLuint_GLsizei_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLenum_GLvoid func;
    ARGS_void_GLuint_GLsizei_GLenum_GLvoid args;
} PACKED_void_GLuint_GLsizei_GLenum_GLvoid;
typedef void (*FUNC_void_GLuint_GLsizei_GLfloat)(GLuint path, GLsizei dashCount, GLfloat dashArray);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLfloat a3;
} ARGS_void_GLuint_GLsizei_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLfloat func;
    ARGS_void_GLuint_GLsizei_GLfloat args;
} PACKED_void_GLuint_GLsizei_GLfloat;
typedef void (*FUNC_void_GLuint_GLenum_GLvoid_GLbitfield_GLuint_GLsizei_GLenum_GLuint_GLfloat)(GLuint firstPathName, GLenum fontTarget, GLvoid fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLvoid a3;
    GLbitfield a4;
    GLuint a5;
    GLsizei a6;
    GLenum a7;
    GLuint a8;
    GLfloat a9;
} ARGS_void_GLuint_GLenum_GLvoid_GLbitfield_GLuint_GLsizei_GLenum_GLuint_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLvoid_GLbitfield_GLuint_GLsizei_GLenum_GLuint_GLfloat func;
    ARGS_void_GLuint_GLenum_GLvoid_GLbitfield_GLuint_GLsizei_GLenum_GLuint_GLfloat args;
} PACKED_void_GLuint_GLenum_GLvoid_GLbitfield_GLuint_GLsizei_GLenum_GLuint_GLfloat;
typedef void (*FUNC_void_GLuint_GLenum_GLvoid_GLbitfield_GLsizei_GLenum_GLvoid_GLenum_GLuint_GLfloat)(GLuint firstPathName, GLenum fontTarget, GLvoid fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, GLvoid charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLvoid a3;
    GLbitfield a4;
    GLsizei a5;
    GLenum a6;
    GLvoid a7;
    GLenum a8;
    GLuint a9;
    GLfloat a10;
} ARGS_void_GLuint_GLenum_GLvoid_GLbitfield_GLsizei_GLenum_GLvoid_GLenum_GLuint_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLvoid_GLbitfield_GLsizei_GLenum_GLvoid_GLenum_GLuint_GLfloat func;
    ARGS_void_GLuint_GLenum_GLvoid_GLbitfield_GLsizei_GLenum_GLvoid_GLenum_GLuint_GLfloat args;
} PACKED_void_GLuint_GLenum_GLvoid_GLbitfield_GLsizei_GLenum_GLvoid_GLenum_GLuint_GLfloat;
typedef void (*FUNC_void_GLuint_GLenum_GLsizei_GLvoid)(GLuint path, GLenum format, GLsizei length, GLvoid pathString);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLsizei a3;
    GLvoid a4;
} ARGS_void_GLuint_GLenum_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLsizei_GLvoid func;
    ARGS_void_GLuint_GLenum_GLsizei_GLvoid args;
} PACKED_void_GLuint_GLenum_GLsizei_GLvoid;
typedef void (*FUNC_void_GLuint_GLsizei_GLsizei_GLsizei_GLubyte_GLsizei_GLenum_GLvoid)(GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, GLubyte commands, GLsizei numCoords, GLenum coordType, GLvoid coords);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLsizei a3;
    GLsizei a4;
    GLubyte a5;
    GLsizei a6;
    GLenum a7;
    GLvoid a8;
} ARGS_void_GLuint_GLsizei_GLsizei_GLsizei_GLubyte_GLsizei_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLsizei_GLsizei_GLubyte_GLsizei_GLenum_GLvoid func;
    ARGS_void_GLuint_GLsizei_GLsizei_GLsizei_GLubyte_GLsizei_GLenum_GLvoid args;
} PACKED_void_GLuint_GLsizei_GLsizei_GLsizei_GLubyte_GLsizei_GLenum_GLvoid;
typedef void (*FUNC_void_GLenum_GLenum_GLint_GLfloat)(GLenum texCoordSet, GLenum genMode, GLint components, GLfloat coeffs);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLint a3;
    GLfloat a4;
} ARGS_void_GLenum_GLenum_GLint_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLint_GLfloat func;
    ARGS_void_GLenum_GLenum_GLint_GLfloat args;
} PACKED_void_GLenum_GLenum_GLint_GLfloat;
typedef Boolean (*FUNC_Boolean_GLuint_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat)(GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat x, GLfloat y, GLfloat tangentX, GLfloat tangentY);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLsizei a3;
    GLfloat a4;
    GLfloat a5;
    GLfloat a6;
    GLfloat a7;
    GLfloat a8;
} ARGS_Boolean_GLuint_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_Boolean_GLuint_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat func;
    ARGS_Boolean_GLuint_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args;
} PACKED_Boolean_GLuint_GLsizei_GLsizei_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef Int32 (*FUNC_Int32_GLint)(GLint marker_p);
typedef struct {
    GLint a1;
} ARGS_Int32_GLint;
typedef struct {
    int format;
    FUNC_Int32_GLint func;
    ARGS_Int32_GLint args;
} PACKED_Int32_GLint;
typedef void (*FUNC_void_GLuint_GLuint64EXT_GLuint_GLuint_GLenum_GLenum_GLuint_GLenum_GLuint_GLenum_GLuint_GLenum_GLuint)(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLenum target1, GLuint fill1, GLenum target2, GLuint fill2, GLenum target3, GLuint fill3);
typedef struct {
    GLuint a1;
    GLuint64EXT a2;
    GLuint a3;
    GLuint a4;
    GLenum a5;
    GLenum a6;
    GLuint a7;
    GLenum a8;
    GLuint a9;
    GLenum a10;
    GLuint a11;
    GLenum a12;
    GLuint a13;
} ARGS_void_GLuint_GLuint64EXT_GLuint_GLuint_GLenum_GLenum_GLuint_GLenum_GLuint_GLenum_GLuint_GLenum_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint64EXT_GLuint_GLuint_GLenum_GLenum_GLuint_GLenum_GLuint_GLenum_GLuint_GLenum_GLuint func;
    ARGS_void_GLuint_GLuint64EXT_GLuint_GLuint_GLenum_GLenum_GLuint_GLenum_GLuint_GLenum_GLuint_GLenum_GLuint args;
} PACKED_void_GLuint_GLuint64EXT_GLuint_GLuint_GLenum_GLenum_GLuint_GLenum_GLuint_GLenum_GLuint_GLenum_GLuint;
typedef void (*FUNC_void_GLuint_GLuint64EXT_GLuint_GLuint_GLenum_GLenum_GLuint_GLuint_GLenum_GLuint_GLuint)(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLuint key0, GLenum target1, GLuint fill1, GLuint key1);
typedef struct {
    GLuint a1;
    GLuint64EXT a2;
    GLuint a3;
    GLuint a4;
    GLenum a5;
    GLenum a6;
    GLuint a7;
    GLuint a8;
    GLenum a9;
    GLuint a10;
    GLuint a11;
} ARGS_void_GLuint_GLuint64EXT_GLuint_GLuint_GLenum_GLenum_GLuint_GLuint_GLenum_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint64EXT_GLuint_GLuint_GLenum_GLenum_GLuint_GLuint_GLenum_GLuint_GLuint func;
    ARGS_void_GLuint_GLuint64EXT_GLuint_GLuint_GLenum_GLenum_GLuint_GLuint_GLenum_GLuint_GLuint args;
} PACKED_void_GLuint_GLuint64EXT_GLuint_GLuint_GLenum_GLenum_GLuint_GLuint_GLenum_GLuint_GLuint;
typedef void (*FUNC_void_GLsizei_GLuint_GLfloat)(GLsizei n, GLuint textures, GLfloat priorities);
typedef struct {
    GLsizei a1;
    GLuint a2;
    GLfloat a3;
} ARGS_void_GLsizei_GLuint_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLuint_GLfloat func;
    ARGS_void_GLsizei_GLuint_GLfloat args;
} PACKED_void_GLsizei_GLuint_GLfloat;
typedef void (*FUNC_void_GLsizei_GLuint_GLclampf)(GLsizei n, GLuint textures, GLclampf priorities);
typedef struct {
    GLsizei a1;
    GLuint a2;
    GLclampf a3;
} ARGS_void_GLsizei_GLuint_GLclampf;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLuint_GLclampf func;
    ARGS_void_GLsizei_GLuint_GLclampf args;
} PACKED_void_GLsizei_GLuint_GLclampf;
typedef void (*FUNC_void_GLsizei_GLuint_GLfixed)(GLsizei n, GLuint textures, GLfixed priorities);
typedef struct {
    GLsizei a1;
    GLuint a2;
    GLfixed a3;
} ARGS_void_GLsizei_GLuint_GLfixed;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLuint_GLfixed func;
    ARGS_void_GLsizei_GLuint_GLfixed args;
} PACKED_void_GLsizei_GLuint_GLfixed;
typedef void (*FUNC_void_GLuint_GLenum_GLvoid_GLsizei)(GLuint program, GLenum binaryFormat, GLvoid binary, GLsizei length);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLvoid a3;
    GLsizei a4;
} ARGS_void_GLuint_GLenum_GLvoid_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLvoid_GLsizei func;
    ARGS_void_GLuint_GLenum_GLvoid_GLsizei args;
} PACKED_void_GLuint_GLenum_GLvoid_GLsizei;
typedef void (*FUNC_void_GLenum_GLuint_GLuint_GLsizei_GLint)(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, GLint params);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLuint a3;
    GLsizei a4;
    GLint a5;
} ARGS_void_GLenum_GLuint_GLuint_GLsizei_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLuint_GLsizei_GLint func;
    ARGS_void_GLenum_GLuint_GLuint_GLsizei_GLint args;
} PACKED_void_GLenum_GLuint_GLuint_GLsizei_GLint;
typedef void (*FUNC_void_GLenum_GLuint_GLuint_GLsizei_GLuint)(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, GLuint params);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLuint a3;
    GLsizei a4;
    GLuint a5;
} ARGS_void_GLenum_GLuint_GLuint_GLsizei_GLuint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLuint_GLsizei_GLuint func;
    ARGS_void_GLenum_GLuint_GLuint_GLsizei_GLuint args;
} PACKED_void_GLenum_GLuint_GLuint_GLsizei_GLuint;
typedef void (*FUNC_void_GLenum_GLuint_GLuint_GLsizei_GLfloat)(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, GLfloat params);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLuint a3;
    GLsizei a4;
    GLfloat a5;
} ARGS_void_GLenum_GLuint_GLuint_GLsizei_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLuint_GLsizei_GLfloat func;
    ARGS_void_GLenum_GLuint_GLuint_GLsizei_GLfloat args;
} PACKED_void_GLenum_GLuint_GLuint_GLsizei_GLfloat;
typedef void (*FUNC_void_GLenum_GLuint_GLdouble_GLdouble_GLdouble_GLdouble)(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLdouble a3;
    GLdouble a4;
    GLdouble a5;
    GLdouble a6;
} ARGS_void_GLenum_GLuint_GLdouble_GLdouble_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLdouble_GLdouble_GLdouble_GLdouble func;
    ARGS_void_GLenum_GLuint_GLdouble_GLdouble_GLdouble_GLdouble args;
} PACKED_void_GLenum_GLuint_GLdouble_GLdouble_GLdouble_GLdouble;
typedef void (*FUNC_void_GLenum_GLuint_GLfloat_GLfloat_GLfloat_GLfloat)(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLfloat a3;
    GLfloat a4;
    GLfloat a5;
    GLfloat a6;
} ARGS_void_GLenum_GLuint_GLfloat_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLfloat_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLenum_GLuint_GLfloat_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLenum_GLuint_GLfloat_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLenum_GLuint_GLint_GLint_GLint_GLint)(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLint a3;
    GLint a4;
    GLint a5;
    GLint a6;
} ARGS_void_GLenum_GLuint_GLint_GLint_GLint_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLint_GLint_GLint_GLint func;
    ARGS_void_GLenum_GLuint_GLint_GLint_GLint_GLint args;
} PACKED_void_GLenum_GLuint_GLint_GLint_GLint_GLint;
typedef void (*FUNC_void_GLenum_GLuint_GLsizei_GLfloat)(GLenum target, GLuint index, GLsizei count, GLfloat params);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLsizei a3;
    GLfloat a4;
} ARGS_void_GLenum_GLuint_GLsizei_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLsizei_GLfloat func;
    ARGS_void_GLenum_GLuint_GLsizei_GLfloat args;
} PACKED_void_GLenum_GLuint_GLsizei_GLfloat;
typedef void (*FUNC_void_GLenum_GLuint_GLsizei_GLint)(GLenum target, GLuint index, GLsizei count, GLint params);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLsizei a3;
    GLint a4;
} ARGS_void_GLenum_GLuint_GLsizei_GLint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLsizei_GLint func;
    ARGS_void_GLenum_GLuint_GLsizei_GLint args;
} PACKED_void_GLenum_GLuint_GLsizei_GLint;
typedef void (*FUNC_void_GLenum_GLuint_GLsizei_GLuint)(GLenum target, GLuint index, GLsizei count, GLuint params);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLsizei a3;
    GLuint a4;
} ARGS_void_GLenum_GLuint_GLsizei_GLuint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLsizei_GLuint func;
    ARGS_void_GLenum_GLuint_GLsizei_GLuint args;
} PACKED_void_GLenum_GLuint_GLsizei_GLuint;
typedef void (*FUNC_void_GLuint_GLsizei_GLubyte_GLdouble_GLdouble_GLdouble_GLdouble)(GLuint id, GLsizei len, GLubyte name, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLubyte a3;
    GLdouble a4;
    GLdouble a5;
    GLdouble a6;
    GLdouble a7;
} ARGS_void_GLuint_GLsizei_GLubyte_GLdouble_GLdouble_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLubyte_GLdouble_GLdouble_GLdouble_GLdouble func;
    ARGS_void_GLuint_GLsizei_GLubyte_GLdouble_GLdouble_GLdouble_GLdouble args;
} PACKED_void_GLuint_GLsizei_GLubyte_GLdouble_GLdouble_GLdouble_GLdouble;
typedef void (*FUNC_void_GLuint_GLsizei_GLubyte_GLfloat_GLfloat_GLfloat_GLfloat)(GLuint id, GLsizei len, GLubyte name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLubyte a3;
    GLfloat a4;
    GLfloat a5;
    GLfloat a6;
    GLfloat a7;
} ARGS_void_GLuint_GLsizei_GLubyte_GLfloat_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLubyte_GLfloat_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLuint_GLsizei_GLubyte_GLfloat_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLuint_GLsizei_GLubyte_GLfloat_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLenum_GLuint_GLsizei_GLdouble)(GLenum target, GLuint index, GLsizei count, GLdouble v);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLsizei a3;
    GLdouble a4;
} ARGS_void_GLenum_GLuint_GLsizei_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLsizei_GLdouble func;
    ARGS_void_GLenum_GLuint_GLsizei_GLdouble args;
} PACKED_void_GLenum_GLuint_GLsizei_GLdouble;
typedef void (*FUNC_void_GLenum_GLenum_GLsizei_GLvoid)(GLenum target, GLenum format, GLsizei len, GLvoid string);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLsizei a3;
    GLvoid a4;
} ARGS_void_GLenum_GLenum_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLsizei_GLvoid func;
    ARGS_void_GLenum_GLenum_GLsizei_GLvoid args;
} PACKED_void_GLenum_GLenum_GLsizei_GLvoid;
typedef void (*FUNC_void_GLuint_GLint_GLsizei_GLint64EXT)(GLuint program, GLint location, GLsizei count, GLint64EXT value);
typedef struct {
    GLuint a1;
    GLint a2;
    GLsizei a3;
    GLint64EXT a4;
} ARGS_void_GLuint_GLint_GLsizei_GLint64EXT;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLsizei_GLint64EXT func;
    ARGS_void_GLuint_GLint_GLsizei_GLint64EXT args;
} PACKED_void_GLuint_GLint_GLsizei_GLint64EXT;
typedef void (*FUNC_void_GLuint_GLint_GLsizei_GLuint64EXT)(GLuint program, GLint location, GLsizei count, GLuint64EXT value);
typedef struct {
    GLuint a1;
    GLint a2;
    GLsizei a3;
    GLuint64EXT a4;
} ARGS_void_GLuint_GLint_GLsizei_GLuint64EXT;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLsizei_GLuint64EXT func;
    ARGS_void_GLuint_GLint_GLsizei_GLuint64EXT args;
} PACKED_void_GLuint_GLint_GLsizei_GLuint64EXT;
typedef void (*FUNC_void_GLuint_GLint_GLdouble_GLdouble)(GLuint program, GLint location, GLdouble v0, GLdouble v1);
typedef struct {
    GLuint a1;
    GLint a2;
    GLdouble a3;
    GLdouble a4;
} ARGS_void_GLuint_GLint_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLdouble_GLdouble func;
    ARGS_void_GLuint_GLint_GLdouble_GLdouble args;
} PACKED_void_GLuint_GLint_GLdouble_GLdouble;
typedef void (*FUNC_void_GLuint_GLint_GLfloat_GLfloat)(GLuint program, GLint location, GLfloat v0, GLfloat v1);
typedef struct {
    GLuint a1;
    GLint a2;
    GLfloat a3;
    GLfloat a4;
} ARGS_void_GLuint_GLint_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLfloat_GLfloat func;
    ARGS_void_GLuint_GLint_GLfloat_GLfloat args;
} PACKED_void_GLuint_GLint_GLfloat_GLfloat;
typedef void (*FUNC_void_GLuint_GLint_GLint_GLint)(GLuint program, GLint location, GLint v0, GLint v1);
typedef struct {
    GLuint a1;
    GLint a2;
    GLint a3;
    GLint a4;
} ARGS_void_GLuint_GLint_GLint_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLint_GLint func;
    ARGS_void_GLuint_GLint_GLint_GLint args;
} PACKED_void_GLuint_GLint_GLint_GLint;
typedef void (*FUNC_void_GLuint_GLint_GLint64EXT_GLint64EXT)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y);
typedef struct {
    GLuint a1;
    GLint a2;
    GLint64EXT a3;
    GLint64EXT a4;
} ARGS_void_GLuint_GLint_GLint64EXT_GLint64EXT;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLint64EXT_GLint64EXT func;
    ARGS_void_GLuint_GLint_GLint64EXT_GLint64EXT args;
} PACKED_void_GLuint_GLint_GLint64EXT_GLint64EXT;
typedef void (*FUNC_void_GLuint_GLint_GLuint_GLuint)(GLuint program, GLint location, GLuint v0, GLuint v1);
typedef struct {
    GLuint a1;
    GLint a2;
    GLuint a3;
    GLuint a4;
} ARGS_void_GLuint_GLint_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLuint_GLuint func;
    ARGS_void_GLuint_GLint_GLuint_GLuint args;
} PACKED_void_GLuint_GLint_GLuint_GLuint;
typedef void (*FUNC_void_GLuint_GLint_GLuint64EXT_GLuint64EXT)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y);
typedef struct {
    GLuint a1;
    GLint a2;
    GLuint64EXT a3;
    GLuint64EXT a4;
} ARGS_void_GLuint_GLint_GLuint64EXT_GLuint64EXT;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLuint64EXT_GLuint64EXT func;
    ARGS_void_GLuint_GLint_GLuint64EXT_GLuint64EXT args;
} PACKED_void_GLuint_GLint_GLuint64EXT_GLuint64EXT;
typedef void (*FUNC_void_GLuint_GLint_GLdouble_GLdouble_GLdouble)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
typedef struct {
    GLuint a1;
    GLint a2;
    GLdouble a3;
    GLdouble a4;
    GLdouble a5;
} ARGS_void_GLuint_GLint_GLdouble_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLdouble_GLdouble_GLdouble func;
    ARGS_void_GLuint_GLint_GLdouble_GLdouble_GLdouble args;
} PACKED_void_GLuint_GLint_GLdouble_GLdouble_GLdouble;
typedef void (*FUNC_void_GLuint_GLint_GLfloat_GLfloat_GLfloat)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef struct {
    GLuint a1;
    GLint a2;
    GLfloat a3;
    GLfloat a4;
    GLfloat a5;
} ARGS_void_GLuint_GLint_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLuint_GLint_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLuint_GLint_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLuint_GLint_GLint_GLint_GLint)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
typedef struct {
    GLuint a1;
    GLint a2;
    GLint a3;
    GLint a4;
    GLint a5;
} ARGS_void_GLuint_GLint_GLint_GLint_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLint_GLint_GLint func;
    ARGS_void_GLuint_GLint_GLint_GLint_GLint args;
} PACKED_void_GLuint_GLint_GLint_GLint_GLint;
typedef void (*FUNC_void_GLuint_GLint_GLint64EXT_GLint64EXT_GLint64EXT)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
typedef struct {
    GLuint a1;
    GLint a2;
    GLint64EXT a3;
    GLint64EXT a4;
    GLint64EXT a5;
} ARGS_void_GLuint_GLint_GLint64EXT_GLint64EXT_GLint64EXT;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLint64EXT_GLint64EXT_GLint64EXT func;
    ARGS_void_GLuint_GLint_GLint64EXT_GLint64EXT_GLint64EXT args;
} PACKED_void_GLuint_GLint_GLint64EXT_GLint64EXT_GLint64EXT;
typedef void (*FUNC_void_GLuint_GLint_GLuint_GLuint_GLuint)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef struct {
    GLuint a1;
    GLint a2;
    GLuint a3;
    GLuint a4;
    GLuint a5;
} ARGS_void_GLuint_GLint_GLuint_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLuint_GLuint_GLuint func;
    ARGS_void_GLuint_GLint_GLuint_GLuint_GLuint args;
} PACKED_void_GLuint_GLint_GLuint_GLuint_GLuint;
typedef void (*FUNC_void_GLuint_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
typedef struct {
    GLuint a1;
    GLint a2;
    GLuint64EXT a3;
    GLuint64EXT a4;
    GLuint64EXT a5;
} ARGS_void_GLuint_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT func;
    ARGS_void_GLuint_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT args;
} PACKED_void_GLuint_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT;
typedef void (*FUNC_void_GLuint_GLint_GLdouble_GLdouble_GLdouble_GLdouble)(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
typedef struct {
    GLuint a1;
    GLint a2;
    GLdouble a3;
    GLdouble a4;
    GLdouble a5;
    GLdouble a6;
} ARGS_void_GLuint_GLint_GLdouble_GLdouble_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLdouble_GLdouble_GLdouble_GLdouble func;
    ARGS_void_GLuint_GLint_GLdouble_GLdouble_GLdouble_GLdouble args;
} PACKED_void_GLuint_GLint_GLdouble_GLdouble_GLdouble_GLdouble;
typedef void (*FUNC_void_GLuint_GLint_GLfloat_GLfloat_GLfloat_GLfloat)(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef struct {
    GLuint a1;
    GLint a2;
    GLfloat a3;
    GLfloat a4;
    GLfloat a5;
    GLfloat a6;
} ARGS_void_GLuint_GLint_GLfloat_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLfloat_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLuint_GLint_GLfloat_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLuint_GLint_GLfloat_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLuint_GLint_GLint_GLint_GLint_GLint)(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef struct {
    GLuint a1;
    GLint a2;
    GLint a3;
    GLint a4;
    GLint a5;
    GLint a6;
} ARGS_void_GLuint_GLint_GLint_GLint_GLint_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLint_GLint_GLint_GLint func;
    ARGS_void_GLuint_GLint_GLint_GLint_GLint_GLint args;
} PACKED_void_GLuint_GLint_GLint_GLint_GLint_GLint;
typedef void (*FUNC_void_GLuint_GLint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT)(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
typedef struct {
    GLuint a1;
    GLint a2;
    GLint64EXT a3;
    GLint64EXT a4;
    GLint64EXT a5;
    GLint64EXT a6;
} ARGS_void_GLuint_GLint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT func;
    ARGS_void_GLuint_GLint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT args;
} PACKED_void_GLuint_GLint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT;
typedef void (*FUNC_void_GLuint_GLint_GLuint_GLuint_GLuint_GLuint)(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef struct {
    GLuint a1;
    GLint a2;
    GLuint a3;
    GLuint a4;
    GLuint a5;
    GLuint a6;
} ARGS_void_GLuint_GLint_GLuint_GLuint_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLuint_GLuint_GLuint_GLuint func;
    ARGS_void_GLuint_GLint_GLuint_GLuint_GLuint_GLuint args;
} PACKED_void_GLuint_GLint_GLuint_GLuint_GLuint_GLuint;
typedef void (*FUNC_void_GLuint_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT)(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
typedef struct {
    GLuint a1;
    GLint a2;
    GLuint64EXT a3;
    GLuint64EXT a4;
    GLuint64EXT a5;
    GLuint64EXT a6;
} ARGS_void_GLuint_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT func;
    ARGS_void_GLuint_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT args;
} PACKED_void_GLuint_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT;
typedef void (*FUNC_void_GLuint_GLint_GLuint64)(GLuint program, GLint location, GLuint64 value);
typedef struct {
    GLuint a1;
    GLint a2;
    GLuint64 a3;
} ARGS_void_GLuint_GLint_GLuint64;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLuint64 func;
    ARGS_void_GLuint_GLint_GLuint64 args;
} PACKED_void_GLuint_GLint_GLuint64;
typedef void (*FUNC_void_GLuint_GLint_GLsizei_GLuint64)(GLuint program, GLint location, GLsizei count, GLuint64 values);
typedef struct {
    GLuint a1;
    GLint a2;
    GLsizei a3;
    GLuint64 a4;
} ARGS_void_GLuint_GLint_GLsizei_GLuint64;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLsizei_GLuint64 func;
    ARGS_void_GLuint_GLint_GLsizei_GLuint64 args;
} PACKED_void_GLuint_GLint_GLsizei_GLuint64;
typedef void (*FUNC_void_GLuint_GLint_GLsizei_GLboolean_GLdouble)(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
typedef struct {
    GLuint a1;
    GLint a2;
    GLsizei a3;
    GLboolean a4;
    GLdouble a5;
} ARGS_void_GLuint_GLint_GLsizei_GLboolean_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLsizei_GLboolean_GLdouble func;
    ARGS_void_GLuint_GLint_GLsizei_GLboolean_GLdouble args;
} PACKED_void_GLuint_GLint_GLsizei_GLboolean_GLdouble;
typedef void (*FUNC_void_GLuint_GLint_GLsizei_GLboolean_GLfloat)(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
typedef struct {
    GLuint a1;
    GLint a2;
    GLsizei a3;
    GLboolean a4;
    GLfloat a5;
} ARGS_void_GLuint_GLint_GLsizei_GLboolean_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLsizei_GLboolean_GLfloat func;
    ARGS_void_GLuint_GLint_GLsizei_GLboolean_GLfloat args;
} PACKED_void_GLuint_GLint_GLsizei_GLboolean_GLfloat;
typedef GLbitfield (*FUNC_GLbitfield_GLfixed_GLint)(GLfixed mantissa, GLint exponent);
typedef struct {
    GLfixed a1;
    GLint a2;
} ARGS_GLbitfield_GLfixed_GLint;
typedef struct {
    int format;
    FUNC_GLbitfield_GLfixed_GLint func;
    ARGS_GLbitfield_GLfixed_GLint args;
} PACKED_GLbitfield_GLfixed_GLint;
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
typedef void (*FUNC_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels);
typedef struct {
    GLint a1;
    GLint a2;
    GLsizei a3;
    GLsizei a4;
    GLenum a5;
    GLenum a6;
    GLvoid a7;
} ARGS_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid func;
    ARGS_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid args;
} PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLsizei_GLvoid)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLvoid data);
typedef struct {
    GLint a1;
    GLint a2;
    GLsizei a3;
    GLsizei a4;
    GLenum a5;
    GLenum a6;
    GLsizei a7;
    GLvoid a8;
} ARGS_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLsizei_GLvoid func;
    ARGS_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLsizei_GLvoid args;
} PACKED_void_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLsizei_GLvoid;
typedef Int32 (*FUNC_Int32_GLenum)(GLenum mode);
typedef struct {
    GLenum a1;
} ARGS_Int32_GLenum;
typedef struct {
    int format;
    FUNC_Int32_GLenum func;
    ARGS_Int32_GLenum args;
} PACKED_Int32_GLenum;
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
typedef void (*FUNC_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLenum a3;
    GLsizei a4;
    GLsizei a5;
} ARGS_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei func;
    ARGS_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei args;
} PACKED_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei;
typedef void (*FUNC_void_GLenum_GLsizei_GLsizei_GLenum_GLsizei_GLsizei)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLsizei a3;
    GLenum a4;
    GLsizei a5;
    GLsizei a6;
} ARGS_void_GLenum_GLsizei_GLsizei_GLenum_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLsizei_GLenum_GLsizei_GLsizei func;
    ARGS_void_GLenum_GLsizei_GLsizei_GLenum_GLsizei_GLsizei args;
} PACKED_void_GLenum_GLsizei_GLsizei_GLenum_GLsizei_GLsizei;
typedef void (*FUNC_void_GLenum_GLsizei_GLvoid___GENPT__)(GLenum type, GLsizei stride, GLvoid * pointer);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLvoid * a3;
} ARGS_void_GLenum_GLsizei_GLvoid___GENPT__;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLvoid___GENPT__ func;
    ARGS_void_GLenum_GLsizei_GLvoid___GENPT__ args;
} PACKED_void_GLenum_GLsizei_GLvoid___GENPT__;
typedef void (*FUNC_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat)(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
typedef struct {
    GLuint a1;
    GLfloat a2;
    GLfloat a3;
    GLfloat a4;
    GLfloat a5;
    GLfloat a6;
    GLfloat a7;
} ARGS_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLuint_GLfloat_GLfloat)(GLuint rc, GLfloat c, GLfloat v);
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
typedef void (*FUNC_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat)(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
typedef struct {
    GLuint a1;
    GLfloat a2;
    GLfloat a3;
    GLfloat a4;
    GLfloat a5;
    GLfloat a6;
    GLfloat a7;
    GLfloat a8;
    GLfloat a9;
    GLfloat a10;
    GLfloat a11;
} ARGS_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLuint_GLfloat_GLfloat_GLfloat)(GLuint rc, GLfloat c, GLfloat n, GLfloat v);
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
typedef void (*FUNC_void_GLuint_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat)(GLuint rc, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
typedef struct {
    GLuint a1;
    GLubyte a2;
    GLubyte a3;
    GLubyte a4;
    GLubyte a5;
    GLfloat a6;
    GLfloat a7;
    GLfloat a8;
} ARGS_void_GLuint_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLuint_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLuint_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLuint_GLubyte_GLfloat)(GLuint rc, GLubyte c, GLfloat v);
typedef struct {
    GLuint a1;
    GLubyte a2;
    GLfloat a3;
} ARGS_void_GLuint_GLubyte_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLubyte_GLfloat func;
    ARGS_void_GLuint_GLubyte_GLfloat args;
} PACKED_void_GLuint_GLubyte_GLfloat;
typedef void (*FUNC_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat)(GLuint rc, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
typedef struct {
    GLuint a1;
    GLfloat a2;
    GLfloat a3;
    GLfloat a4;
    GLfloat a5;
    GLfloat a6;
    GLfloat a7;
    GLfloat a8;
    GLfloat a9;
    GLfloat a10;
    GLfloat a11;
    GLfloat a12;
    GLfloat a13;
} ARGS_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat)(GLuint rc, GLfloat tc, GLfloat c, GLfloat n, GLfloat v);
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
typedef void (*FUNC_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat)(GLuint rc, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
typedef struct {
    GLuint a1;
    GLfloat a2;
    GLfloat a3;
    GLfloat a4;
    GLfloat a5;
    GLfloat a6;
    GLfloat a7;
    GLfloat a8;
    GLfloat a9;
} ARGS_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat)(GLuint rc, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
typedef struct {
    GLuint a1;
    GLfloat a2;
    GLfloat a3;
    GLfloat a4;
    GLfloat a5;
    GLfloat a6;
} ARGS_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLuint_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
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
typedef void (*FUNC_void_GLfixed_GLboolean)(GLfixed value, GLboolean invert);
typedef struct {
    GLfixed a1;
    GLboolean a2;
} ARGS_void_GLfixed_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLfixed_GLboolean func;
    ARGS_void_GLfixed_GLboolean args;
} PACKED_void_GLfixed_GLboolean;
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
typedef void (*FUNC_void_GLuint_GLbitfield)(GLuint index, GLbitfield mask);
typedef struct {
    GLuint a1;
    GLbitfield a2;
} ARGS_void_GLuint_GLbitfield;
typedef struct {
    int format;
    FUNC_void_GLuint_GLbitfield func;
    ARGS_void_GLuint_GLbitfield args;
} PACKED_void_GLuint_GLbitfield;
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
typedef void (*FUNC_void_GLuint_GLsizei_GLint)(GLuint first, GLsizei count, GLint v);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLint a3;
} ARGS_void_GLuint_GLsizei_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLint func;
    ARGS_void_GLuint_GLsizei_GLint args;
} PACKED_void_GLuint_GLsizei_GLint;
typedef void (*FUNC_void_GLuint_GLint_GLint_GLsizei_GLsizei)(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
typedef struct {
    GLuint a1;
    GLint a2;
    GLint a3;
    GLsizei a4;
    GLsizei a5;
} ARGS_void_GLuint_GLint_GLint_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLint_GLsizei_GLsizei func;
    ARGS_void_GLuint_GLint_GLint_GLsizei_GLsizei args;
} PACKED_void_GLuint_GLint_GLint_GLsizei_GLsizei;
typedef void (*FUNC_void_GLuint_GLboolean_GLuint_GLint_GLuint)(GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint counterList);
typedef struct {
    GLuint a1;
    GLboolean a2;
    GLuint a3;
    GLint a4;
    GLuint a5;
} ARGS_void_GLuint_GLboolean_GLuint_GLint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLboolean_GLuint_GLint_GLuint func;
    ARGS_void_GLuint_GLboolean_GLuint_GLint_GLuint args;
} PACKED_void_GLuint_GLboolean_GLuint_GLint_GLuint;
typedef void (*FUNC_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid_GLvoid)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid row, GLvoid column);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLsizei a3;
    GLsizei a4;
    GLenum a5;
    GLenum a6;
    GLvoid a7;
    GLvoid a8;
} ARGS_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid_GLvoid func;
    ARGS_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid_GLvoid args;
} PACKED_void_GLenum_GLenum_GLsizei_GLsizei_GLenum_GLenum_GLvoid_GLvoid;
typedef void (*FUNC_void_GLuint_GLenum_GLvoid)(GLuint id, GLenum type, GLvoid addr);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLvoid a3;
} ARGS_void_GLuint_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLvoid func;
    ARGS_void_GLuint_GLenum_GLvoid args;
} PACKED_void_GLuint_GLenum_GLvoid;
typedef void (*FUNC_void_GLsizei_GLuint_GLenum_GLvoid_GLsizei)(GLsizei count, GLuint shaders, GLenum binaryformat, GLvoid binary, GLsizei length);
typedef struct {
    GLsizei a1;
    GLuint a2;
    GLenum a3;
    GLvoid a4;
    GLsizei a5;
} ARGS_void_GLsizei_GLuint_GLenum_GLvoid_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLuint_GLenum_GLvoid_GLsizei func;
    ARGS_void_GLsizei_GLuint_GLenum_GLvoid_GLsizei args;
} PACKED_void_GLsizei_GLuint_GLenum_GLvoid_GLsizei;
typedef void (*FUNC_void_GLenum_GLuint_GLuint_GLuint)(GLenum op, GLuint res, GLuint arg1, GLuint arg2);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLuint a3;
    GLuint a4;
} ARGS_void_GLenum_GLuint_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLuint_GLuint func;
    ARGS_void_GLenum_GLuint_GLuint_GLuint args;
} PACKED_void_GLenum_GLuint_GLuint_GLuint;
typedef void (*FUNC_void_GLenum_GLuint_GLuint_GLuint_GLuint)(GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLuint a3;
    GLuint a4;
    GLuint a5;
} ARGS_void_GLenum_GLuint_GLuint_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLuint_GLuint_GLuint func;
    ARGS_void_GLenum_GLuint_GLuint_GLuint_GLuint args;
} PACKED_void_GLenum_GLuint_GLuint_GLuint_GLuint;
typedef void (*FUNC_void_GLuint_GLsizei_GLchar__GENPT__const_GLint)(GLuint shader, GLsizei count, GLchar*const string, GLint length);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLchar*const a3;
    GLint a4;
} ARGS_void_GLuint_GLsizei_GLchar__GENPT__const_GLint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLchar__GENPT__const_GLint func;
    ARGS_void_GLuint_GLsizei_GLchar__GENPT__const_GLint args;
} PACKED_void_GLuint_GLsizei_GLchar__GENPT__const_GLint;
typedef void (*FUNC_void_GLhandleARB_GLsizei_GLcharARB___GENPT___GLint)(GLhandleARB shaderObj, GLsizei count, GLcharARB * string, GLint length);
typedef struct {
    GLhandleARB a1;
    GLsizei a2;
    GLcharARB * a3;
    GLint a4;
} ARGS_void_GLhandleARB_GLsizei_GLcharARB___GENPT___GLint;
typedef struct {
    int format;
    FUNC_void_GLhandleARB_GLsizei_GLcharARB___GENPT___GLint func;
    ARGS_void_GLhandleARB_GLsizei_GLcharARB___GENPT___GLint args;
} PACKED_void_GLhandleARB_GLsizei_GLcharARB___GENPT___GLint;
typedef void (*FUNC_void_GLsizei_GLenum_GLvoid_GLuint_GLenum_GLuint_GLenum_GLfloat)(GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, GLfloat transformValues);
typedef struct {
    GLsizei a1;
    GLenum a2;
    GLvoid a3;
    GLuint a4;
    GLenum a5;
    GLuint a6;
    GLenum a7;
    GLfloat a8;
} ARGS_void_GLsizei_GLenum_GLvoid_GLuint_GLenum_GLuint_GLenum_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLenum_GLvoid_GLuint_GLenum_GLuint_GLenum_GLfloat func;
    ARGS_void_GLsizei_GLenum_GLvoid_GLuint_GLenum_GLuint_GLenum_GLfloat args;
} PACKED_void_GLsizei_GLenum_GLvoid_GLuint_GLenum_GLuint_GLenum_GLfloat;
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
typedef void (*FUNC_void_GLsizei_GLenum_GLvoid_GLuint_GLint_GLuint_GLenum_GLfloat)(GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, GLfloat transformValues);
typedef struct {
    GLsizei a1;
    GLenum a2;
    GLvoid a3;
    GLuint a4;
    GLint a5;
    GLuint a6;
    GLenum a7;
    GLfloat a8;
} ARGS_void_GLsizei_GLenum_GLvoid_GLuint_GLint_GLuint_GLenum_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLenum_GLvoid_GLuint_GLint_GLuint_GLenum_GLfloat func;
    ARGS_void_GLsizei_GLenum_GLvoid_GLuint_GLint_GLuint_GLenum_GLfloat args;
} PACKED_void_GLsizei_GLenum_GLvoid_GLuint_GLint_GLuint_GLenum_GLfloat;
typedef void (*FUNC_void_GLuint_GLuint_GLenum_GLenum_GLenum_GLenum)(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLenum a3;
    GLenum a4;
    GLenum a5;
    GLenum a6;
} ARGS_void_GLuint_GLuint_GLenum_GLenum_GLenum_GLenum;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLenum_GLenum_GLenum_GLenum func;
    ARGS_void_GLuint_GLuint_GLenum_GLenum_GLenum_GLenum args;
} PACKED_void_GLuint_GLuint_GLenum_GLenum_GLenum_GLenum;
typedef void (*FUNC_void_GLenum_GLenum_GLuint_GLintptr_GLsizeiptr)(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLuint a3;
    GLintptr a4;
    GLsizeiptr a5;
} ARGS_void_GLenum_GLenum_GLuint_GLintptr_GLsizeiptr;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLuint_GLintptr_GLsizeiptr func;
    ARGS_void_GLenum_GLenum_GLuint_GLintptr_GLsizeiptr args;
} PACKED_void_GLenum_GLenum_GLuint_GLintptr_GLsizeiptr;
typedef void (*FUNC_void_GLbyte_GLbyte)(GLbyte s, GLbyte t);
typedef struct {
    GLbyte a1;
    GLbyte a2;
} ARGS_void_GLbyte_GLbyte;
typedef struct {
    int format;
    FUNC_void_GLbyte_GLbyte func;
    ARGS_void_GLbyte_GLbyte args;
} PACKED_void_GLbyte_GLbyte;
typedef void (*FUNC_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat)(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
typedef struct {
    GLfloat a1;
    GLfloat a2;
    GLfloat a3;
    GLfloat a4;
    GLfloat a5;
    GLfloat a6;
    GLfloat a7;
    GLfloat a8;
} ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat)(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
typedef struct {
    GLfloat a1;
    GLfloat a2;
    GLfloat a3;
    GLfloat a4;
    GLfloat a5;
    GLfloat a6;
    GLfloat a7;
    GLfloat a8;
    GLfloat a9;
    GLfloat a10;
    GLfloat a11;
    GLfloat a12;
} ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLfloat_GLfloat_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat)(GLfloat s, GLfloat t, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
typedef struct {
    GLfloat a1;
    GLfloat a2;
    GLubyte a3;
    GLubyte a4;
    GLubyte a5;
    GLubyte a6;
    GLfloat a7;
    GLfloat a8;
    GLfloat a9;
} ARGS_void_GLfloat_GLfloat_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLfloat_GLfloat_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLfloat_GLfloat_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLfloat_GLfloat_GLubyte_GLubyte_GLubyte_GLubyte_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLfloat_GLubyte_GLfloat)(GLfloat tc, GLubyte c, GLfloat v);
typedef struct {
    GLfloat a1;
    GLubyte a2;
    GLfloat a3;
} ARGS_void_GLfloat_GLubyte_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLfloat_GLubyte_GLfloat func;
    ARGS_void_GLfloat_GLubyte_GLfloat args;
} PACKED_void_GLfloat_GLubyte_GLfloat;
typedef void (*FUNC_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat)(GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
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
typedef void (*FUNC_void_GLhalfNV_GLhalfNV)(GLhalfNV s, GLhalfNV t);
typedef struct {
    GLhalfNV a1;
    GLhalfNV a2;
} ARGS_void_GLhalfNV_GLhalfNV;
typedef struct {
    int format;
    FUNC_void_GLhalfNV_GLhalfNV func;
    ARGS_void_GLhalfNV_GLhalfNV args;
} PACKED_void_GLhalfNV_GLhalfNV;
typedef void (*FUNC_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat)(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef struct {
    GLfloat a1;
    GLfloat a2;
    GLfloat a3;
    GLfloat a4;
    GLfloat a5;
    GLfloat a6;
    GLfloat a7;
    GLfloat a8;
    GLfloat a9;
    GLfloat a10;
    GLfloat a11;
    GLfloat a12;
    GLfloat a13;
    GLfloat a14;
    GLfloat a15;
} ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat func;
    ARGS_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat args;
} PACKED_void_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat_GLfloat;
typedef void (*FUNC_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_GLvoid)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, GLvoid pixels);
typedef struct {
    GLenum a1;
    GLint a2;
    GLint a3;
    GLsizei a4;
    GLint a5;
    GLenum a6;
    GLenum a7;
    GLvoid a8;
} ARGS_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_GLvoid func;
    ARGS_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_GLvoid args;
} PACKED_void_GLenum_GLint_GLint_GLsizei_GLint_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, GLvoid pixels);
typedef struct {
    GLenum a1;
    GLint a2;
    GLint a3;
    GLsizei a4;
    GLsizei a5;
    GLint a6;
    GLenum a7;
    GLenum a8;
    GLvoid a9;
} ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid func;
    ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid args;
} PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLboolean)(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLint a3;
    GLsizei a4;
    GLsizei a5;
    GLboolean a6;
} ARGS_void_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLboolean func;
    ARGS_void_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLboolean args;
} PACKED_void_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLboolean;
typedef void (*FUNC_void_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLboolean)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLsizei a3;
    GLint a4;
    GLsizei a5;
    GLsizei a6;
    GLboolean a7;
} ARGS_void_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLboolean func;
    ARGS_void_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLboolean args;
} PACKED_void_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLboolean;
typedef void (*FUNC_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid pixels);
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
    GLvoid a10;
} ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid func;
    ARGS_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid args;
} PACKED_void_GLenum_GLint_GLint_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid pixels);
typedef struct {
    GLenum a1;
    GLint a2;
    GLenum a3;
    GLsizei a4;
    GLsizei a5;
    GLsizei a6;
    GLint a7;
    GLenum a8;
    GLenum a9;
    GLvoid a10;
} ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid func;
    ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid args;
} PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean)(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLint a3;
    GLsizei a4;
    GLsizei a5;
    GLsizei a6;
    GLboolean a7;
} ARGS_void_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean func;
    ARGS_void_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean args;
} PACKED_void_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean;
typedef void (*FUNC_void_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean)(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLsizei a3;
    GLint a4;
    GLsizei a5;
    GLsizei a6;
    GLsizei a7;
    GLboolean a8;
} ARGS_void_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean func;
    ARGS_void_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean args;
} PACKED_void_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean;
typedef void (*FUNC_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLint border, GLenum format, GLenum type, GLvoid pixels);
typedef struct {
    GLenum a1;
    GLint a2;
    GLenum a3;
    GLsizei a4;
    GLsizei a5;
    GLsizei a6;
    GLsizei a7;
    GLint a8;
    GLenum a9;
    GLenum a10;
    GLvoid a11;
} ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid func;
    ARGS_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid args;
} PACKED_void_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLenum_GLsizei_GLenum_GLsizei)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLenum a3;
    GLsizei a4;
} ARGS_void_GLenum_GLsizei_GLenum_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLenum_GLsizei func;
    ARGS_void_GLenum_GLsizei_GLenum_GLsizei args;
} PACKED_void_GLenum_GLsizei_GLenum_GLsizei;
typedef void (*FUNC_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLboolean)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLenum a3;
    GLsizei a4;
    GLsizei a5;
    GLboolean a6;
} ARGS_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLboolean func;
    ARGS_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLboolean args;
} PACKED_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLboolean;
typedef void (*FUNC_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei)(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLenum a3;
    GLsizei a4;
    GLsizei a5;
    GLsizei a6;
} ARGS_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei func;
    ARGS_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei args;
} PACKED_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei;
typedef void (*FUNC_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei_GLboolean)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef struct {
    GLenum a1;
    GLsizei a2;
    GLenum a3;
    GLsizei a4;
    GLsizei a5;
    GLsizei a6;
    GLboolean a7;
} ARGS_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei_GLboolean func;
    ARGS_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei_GLboolean args;
} PACKED_void_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei_GLboolean;
typedef void (*FUNC_void_GLenum_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLbitfield)(GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags);
typedef struct {
    GLenum a1;
    GLenum a2;
    GLsizei a3;
    GLsizei a4;
    GLsizei a5;
    GLsizei a6;
    GLbitfield a7;
} ARGS_void_GLenum_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLbitfield;
typedef struct {
    int format;
    FUNC_void_GLenum_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLbitfield func;
    ARGS_void_GLenum_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLbitfield args;
} PACKED_void_GLenum_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLbitfield;
typedef void (*FUNC_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid pixels);
typedef struct {
    GLenum a1;
    GLint a2;
    GLint a3;
    GLsizei a4;
    GLenum a5;
    GLenum a6;
    GLvoid a7;
} ARGS_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid func;
    ARGS_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid args;
} PACKED_void_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels);
typedef struct {
    GLenum a1;
    GLint a2;
    GLint a3;
    GLint a4;
    GLsizei a5;
    GLsizei a6;
    GLenum a7;
    GLenum a8;
    GLvoid a9;
} ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid func;
    ARGS_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid args;
} PACKED_void_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLvoid pixels);
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
    GLvoid a11;
} ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid func;
    ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid args;
} PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint woffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLenum format, GLenum type, GLvoid pixels);
typedef struct {
    GLenum a1;
    GLint a2;
    GLint a3;
    GLint a4;
    GLint a5;
    GLint a6;
    GLsizei a7;
    GLsizei a8;
    GLsizei a9;
    GLsizei a10;
    GLenum a11;
    GLenum a12;
    GLvoid a13;
} ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid func;
    ARGS_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid args;
} PACKED_void_GLenum_GLint_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLuint_GLenum_GLenum_GLuint_GLintptr_GLsizeiptr)(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLenum a3;
    GLuint a4;
    GLintptr a5;
    GLsizeiptr a6;
} ARGS_void_GLuint_GLenum_GLenum_GLuint_GLintptr_GLsizeiptr;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLenum_GLuint_GLintptr_GLsizeiptr func;
    ARGS_void_GLuint_GLenum_GLenum_GLuint_GLintptr_GLsizeiptr args;
} PACKED_void_GLuint_GLenum_GLenum_GLuint_GLintptr_GLsizeiptr;
typedef void (*FUNC_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLint_GLenum_GLenum_GLvoid)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLenum format, GLenum type, GLvoid pixels);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint a3;
    GLenum a4;
    GLsizei a5;
    GLint a6;
    GLenum a7;
    GLenum a8;
    GLvoid a9;
} ARGS_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLint_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLint_GLenum_GLenum_GLvoid func;
    ARGS_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLint_GLenum_GLenum_GLvoid args;
} PACKED_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLint_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, GLvoid pixels);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint a3;
    GLenum a4;
    GLsizei a5;
    GLsizei a6;
    GLint a7;
    GLenum a8;
    GLenum a9;
    GLvoid a10;
} ARGS_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid func;
    ARGS_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid args;
} PACKED_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLuint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLboolean)(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLsizei a3;
    GLsizei a4;
    GLint a5;
    GLsizei a6;
    GLsizei a7;
    GLboolean a8;
} ARGS_void_GLuint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLboolean func;
    ARGS_void_GLuint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLboolean args;
} PACKED_void_GLuint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLboolean;
typedef void (*FUNC_void_GLuint_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLboolean)(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLsizei a3;
    GLint a4;
    GLsizei a5;
    GLsizei a6;
    GLboolean a7;
} ARGS_void_GLuint_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLboolean func;
    ARGS_void_GLuint_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLboolean args;
} PACKED_void_GLuint_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLboolean;
typedef void (*FUNC_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid)(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid pixels);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint a3;
    GLenum a4;
    GLsizei a5;
    GLsizei a6;
    GLsizei a7;
    GLint a8;
    GLenum a9;
    GLenum a10;
    GLvoid a11;
} ARGS_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid func;
    ARGS_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid args;
} PACKED_void_GLuint_GLenum_GLint_GLenum_GLsizei_GLsizei_GLsizei_GLint_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLuint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean)(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLsizei a3;
    GLsizei a4;
    GLint a5;
    GLsizei a6;
    GLsizei a7;
    GLsizei a8;
    GLboolean a9;
} ARGS_void_GLuint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean func;
    ARGS_void_GLuint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean args;
} PACKED_void_GLuint_GLenum_GLsizei_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean;
typedef void (*FUNC_void_GLuint_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean)(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLsizei a3;
    GLint a4;
    GLsizei a5;
    GLsizei a6;
    GLsizei a7;
    GLboolean a8;
} ARGS_void_GLuint_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean func;
    ARGS_void_GLuint_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean args;
} PACKED_void_GLuint_GLenum_GLsizei_GLint_GLsizei_GLsizei_GLsizei_GLboolean;
typedef void (*FUNC_void_GLuint_GLenum_GLsizei_GLenum_GLsizei)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLsizei a3;
    GLenum a4;
    GLsizei a5;
} ARGS_void_GLuint_GLenum_GLsizei_GLenum_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLsizei_GLenum_GLsizei func;
    ARGS_void_GLuint_GLenum_GLsizei_GLenum_GLsizei args;
} PACKED_void_GLuint_GLenum_GLsizei_GLenum_GLsizei;
typedef void (*FUNC_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLsizei a3;
    GLenum a4;
    GLsizei a5;
    GLsizei a6;
} ARGS_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei func;
    ARGS_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei args;
} PACKED_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei;
typedef void (*FUNC_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLboolean)(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLsizei a3;
    GLenum a4;
    GLsizei a5;
    GLsizei a6;
    GLboolean a7;
} ARGS_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLboolean func;
    ARGS_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLboolean args;
} PACKED_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLboolean;
typedef void (*FUNC_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei)(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLsizei a3;
    GLenum a4;
    GLsizei a5;
    GLsizei a6;
    GLsizei a7;
} ARGS_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei func;
    ARGS_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei args;
} PACKED_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei;
typedef void (*FUNC_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei_GLboolean)(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLsizei a3;
    GLenum a4;
    GLsizei a5;
    GLsizei a6;
    GLsizei a7;
    GLboolean a8;
} ARGS_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei_GLboolean;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei_GLboolean func;
    ARGS_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei_GLboolean args;
} PACKED_void_GLuint_GLenum_GLsizei_GLenum_GLsizei_GLsizei_GLsizei_GLboolean;
typedef void (*FUNC_void_GLuint_GLenum_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLbitfield)(GLuint texture, GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLenum a3;
    GLsizei a4;
    GLsizei a5;
    GLsizei a6;
    GLsizei a7;
    GLbitfield a8;
} ARGS_void_GLuint_GLenum_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLbitfield;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLbitfield func;
    ARGS_void_GLuint_GLenum_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLbitfield args;
} PACKED_void_GLuint_GLenum_GLenum_GLsizei_GLsizei_GLsizei_GLsizei_GLbitfield;
typedef void (*FUNC_void_GLuint_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid pixels);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint a3;
    GLint a4;
    GLsizei a5;
    GLenum a6;
    GLenum a7;
    GLvoid a8;
} ARGS_void_GLuint_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid func;
    ARGS_void_GLuint_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid args;
} PACKED_void_GLuint_GLenum_GLint_GLint_GLsizei_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLuint_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint a3;
    GLint a4;
    GLint a5;
    GLsizei a6;
    GLsizei a7;
    GLenum a8;
    GLenum a9;
    GLvoid a10;
} ARGS_void_GLuint_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid func;
    ARGS_void_GLuint_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid args;
} PACKED_void_GLuint_GLenum_GLint_GLint_GLint_GLsizei_GLsizei_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid)(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLvoid pixels);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLint a3;
    GLint a4;
    GLint a5;
    GLint a6;
    GLsizei a7;
    GLsizei a8;
    GLsizei a9;
    GLenum a10;
    GLenum a11;
    GLvoid a12;
} ARGS_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid func;
    ARGS_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid args;
} PACKED_void_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei_GLenum_GLenum_GLvoid;
typedef void (*FUNC_void_GLuint_GLenum_GLuint_GLenum_GLuint_GLuint_GLuint_GLuint)(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLuint a3;
    GLenum a4;
    GLuint a5;
    GLuint a6;
    GLuint a7;
    GLuint a8;
} ARGS_void_GLuint_GLenum_GLuint_GLenum_GLuint_GLuint_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLuint_GLenum_GLuint_GLuint_GLuint_GLuint func;
    ARGS_void_GLuint_GLenum_GLuint_GLenum_GLuint_GLuint_GLuint_GLuint args;
} PACKED_void_GLuint_GLenum_GLuint_GLenum_GLuint_GLuint_GLuint_GLuint;
typedef void (*FUNC_void_GLenum_GLuint_GLenum_GLenum)(GLenum target, GLuint address, GLenum matrix, GLenum transform);
typedef struct {
    GLenum a1;
    GLuint a2;
    GLenum a3;
    GLenum a4;
} ARGS_void_GLenum_GLuint_GLenum_GLenum;
typedef struct {
    int format;
    FUNC_void_GLenum_GLuint_GLenum_GLenum func;
    ARGS_void_GLenum_GLuint_GLenum_GLenum args;
} PACKED_void_GLenum_GLuint_GLenum_GLenum;
typedef void (*FUNC_void_GLsizei_GLint_GLenum)(GLsizei count, GLint attribs, GLenum bufferMode);
typedef struct {
    GLsizei a1;
    GLint a2;
    GLenum a3;
} ARGS_void_GLsizei_GLint_GLenum;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLint_GLenum func;
    ARGS_void_GLsizei_GLint_GLenum args;
} PACKED_void_GLsizei_GLint_GLenum;
typedef void (*FUNC_void_GLsizei_GLint_GLsizei_GLint_GLenum)(GLsizei count, GLint attribs, GLsizei nbuffers, GLint bufstreams, GLenum bufferMode);
typedef struct {
    GLsizei a1;
    GLint a2;
    GLsizei a3;
    GLint a4;
    GLenum a5;
} ARGS_void_GLsizei_GLint_GLsizei_GLint_GLenum;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLint_GLsizei_GLint_GLenum func;
    ARGS_void_GLsizei_GLint_GLsizei_GLint_GLenum args;
} PACKED_void_GLsizei_GLint_GLsizei_GLint_GLenum;
typedef void (*FUNC_void_GLuint_GLsizei_GLchar__GENPT__const_GLenum)(GLuint program, GLsizei count, GLchar*const varyings, GLenum bufferMode);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLchar*const a3;
    GLenum a4;
} ARGS_void_GLuint_GLsizei_GLchar__GENPT__const_GLenum;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLchar__GENPT__const_GLenum func;
    ARGS_void_GLuint_GLsizei_GLchar__GENPT__const_GLenum args;
} PACKED_void_GLuint_GLsizei_GLchar__GENPT__const_GLenum;
typedef void (*FUNC_void_GLuint_GLsizei_GLchar___GENPT___GLenum)(GLuint program, GLsizei count, GLchar * varyings, GLenum bufferMode);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLchar * a3;
    GLenum a4;
} ARGS_void_GLuint_GLsizei_GLchar___GENPT___GLenum;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLchar___GENPT___GLenum func;
    ARGS_void_GLuint_GLsizei_GLchar___GENPT___GLenum args;
} PACKED_void_GLuint_GLsizei_GLchar___GENPT___GLenum;
typedef void (*FUNC_void_GLuint_GLsizei_GLint_GLenum)(GLuint program, GLsizei count, GLint locations, GLenum bufferMode);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLint a3;
    GLenum a4;
} ARGS_void_GLuint_GLsizei_GLint_GLenum;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLint_GLenum func;
    ARGS_void_GLuint_GLsizei_GLint_GLenum args;
} PACKED_void_GLuint_GLsizei_GLint_GLenum;
typedef void (*FUNC_void_GLint_GLdouble)(GLint location, GLdouble x);
typedef struct {
    GLint a1;
    GLdouble a2;
} ARGS_void_GLint_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLint_GLdouble func;
    ARGS_void_GLint_GLdouble args;
} PACKED_void_GLint_GLdouble;
typedef void (*FUNC_void_GLint_GLsizei_GLdouble)(GLint location, GLsizei count, GLdouble value);
typedef struct {
    GLint a1;
    GLsizei a2;
    GLdouble a3;
} ARGS_void_GLint_GLsizei_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLint_GLsizei_GLdouble func;
    ARGS_void_GLint_GLsizei_GLdouble args;
} PACKED_void_GLint_GLsizei_GLdouble;
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
typedef void (*FUNC_void_GLint_GLsizei_GLfloat)(GLint location, GLsizei count, GLfloat value);
typedef struct {
    GLint a1;
    GLsizei a2;
    GLfloat a3;
} ARGS_void_GLint_GLsizei_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLint_GLsizei_GLfloat func;
    ARGS_void_GLint_GLsizei_GLfloat args;
} PACKED_void_GLint_GLsizei_GLfloat;
typedef void (*FUNC_void_GLint_GLint64EXT)(GLint location, GLint64EXT x);
typedef struct {
    GLint a1;
    GLint64EXT a2;
} ARGS_void_GLint_GLint64EXT;
typedef struct {
    int format;
    FUNC_void_GLint_GLint64EXT func;
    ARGS_void_GLint_GLint64EXT args;
} PACKED_void_GLint_GLint64EXT;
typedef void (*FUNC_void_GLint_GLsizei_GLint64EXT)(GLint location, GLsizei count, GLint64EXT value);
typedef struct {
    GLint a1;
    GLsizei a2;
    GLint64EXT a3;
} ARGS_void_GLint_GLsizei_GLint64EXT;
typedef struct {
    int format;
    FUNC_void_GLint_GLsizei_GLint64EXT func;
    ARGS_void_GLint_GLsizei_GLint64EXT args;
} PACKED_void_GLint_GLsizei_GLint64EXT;
typedef void (*FUNC_void_GLint_GLsizei_GLint)(GLint location, GLsizei count, GLint value);
typedef struct {
    GLint a1;
    GLsizei a2;
    GLint a3;
} ARGS_void_GLint_GLsizei_GLint;
typedef struct {
    int format;
    FUNC_void_GLint_GLsizei_GLint func;
    ARGS_void_GLint_GLsizei_GLint args;
} PACKED_void_GLint_GLsizei_GLint;
typedef void (*FUNC_void_GLint_GLuint64EXT)(GLint location, GLuint64EXT x);
typedef struct {
    GLint a1;
    GLuint64EXT a2;
} ARGS_void_GLint_GLuint64EXT;
typedef struct {
    int format;
    FUNC_void_GLint_GLuint64EXT func;
    ARGS_void_GLint_GLuint64EXT args;
} PACKED_void_GLint_GLuint64EXT;
typedef void (*FUNC_void_GLint_GLsizei_GLuint64EXT)(GLint location, GLsizei count, GLuint64EXT value);
typedef struct {
    GLint a1;
    GLsizei a2;
    GLuint64EXT a3;
} ARGS_void_GLint_GLsizei_GLuint64EXT;
typedef struct {
    int format;
    FUNC_void_GLint_GLsizei_GLuint64EXT func;
    ARGS_void_GLint_GLsizei_GLuint64EXT args;
} PACKED_void_GLint_GLsizei_GLuint64EXT;
typedef void (*FUNC_void_GLint_GLint64EXT_GLint64EXT)(GLint location, GLint64EXT x, GLint64EXT y);
typedef struct {
    GLint a1;
    GLint64EXT a2;
    GLint64EXT a3;
} ARGS_void_GLint_GLint64EXT_GLint64EXT;
typedef struct {
    int format;
    FUNC_void_GLint_GLint64EXT_GLint64EXT func;
    ARGS_void_GLint_GLint64EXT_GLint64EXT args;
} PACKED_void_GLint_GLint64EXT_GLint64EXT;
typedef void (*FUNC_void_GLint_GLuint_GLuint)(GLint location, GLuint v0, GLuint v1);
typedef struct {
    GLint a1;
    GLuint a2;
    GLuint a3;
} ARGS_void_GLint_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLint_GLuint_GLuint func;
    ARGS_void_GLint_GLuint_GLuint args;
} PACKED_void_GLint_GLuint_GLuint;
typedef void (*FUNC_void_GLint_GLuint64EXT_GLuint64EXT)(GLint location, GLuint64EXT x, GLuint64EXT y);
typedef struct {
    GLint a1;
    GLuint64EXT a2;
    GLuint64EXT a3;
} ARGS_void_GLint_GLuint64EXT_GLuint64EXT;
typedef struct {
    int format;
    FUNC_void_GLint_GLuint64EXT_GLuint64EXT func;
    ARGS_void_GLint_GLuint64EXT_GLuint64EXT args;
} PACKED_void_GLint_GLuint64EXT_GLuint64EXT;
typedef void (*FUNC_void_GLint_GLdouble_GLdouble_GLdouble)(GLint location, GLdouble x, GLdouble y, GLdouble z);
typedef struct {
    GLint a1;
    GLdouble a2;
    GLdouble a3;
    GLdouble a4;
} ARGS_void_GLint_GLdouble_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLint_GLdouble_GLdouble_GLdouble func;
    ARGS_void_GLint_GLdouble_GLdouble_GLdouble args;
} PACKED_void_GLint_GLdouble_GLdouble_GLdouble;
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
typedef void (*FUNC_void_GLint_GLint64EXT_GLint64EXT_GLint64EXT)(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
typedef struct {
    GLint a1;
    GLint64EXT a2;
    GLint64EXT a3;
    GLint64EXT a4;
} ARGS_void_GLint_GLint64EXT_GLint64EXT_GLint64EXT;
typedef struct {
    int format;
    FUNC_void_GLint_GLint64EXT_GLint64EXT_GLint64EXT func;
    ARGS_void_GLint_GLint64EXT_GLint64EXT_GLint64EXT args;
} PACKED_void_GLint_GLint64EXT_GLint64EXT_GLint64EXT;
typedef void (*FUNC_void_GLint_GLuint_GLuint_GLuint)(GLint location, GLuint v0, GLuint v1, GLuint v2);
typedef struct {
    GLint a1;
    GLuint a2;
    GLuint a3;
    GLuint a4;
} ARGS_void_GLint_GLuint_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLint_GLuint_GLuint_GLuint func;
    ARGS_void_GLint_GLuint_GLuint_GLuint args;
} PACKED_void_GLint_GLuint_GLuint_GLuint;
typedef void (*FUNC_void_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT)(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
typedef struct {
    GLint a1;
    GLuint64EXT a2;
    GLuint64EXT a3;
    GLuint64EXT a4;
} ARGS_void_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT;
typedef struct {
    int format;
    FUNC_void_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT func;
    ARGS_void_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT args;
} PACKED_void_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT;
typedef void (*FUNC_void_GLint_GLdouble_GLdouble_GLdouble_GLdouble)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef struct {
    GLint a1;
    GLdouble a2;
    GLdouble a3;
    GLdouble a4;
    GLdouble a5;
} ARGS_void_GLint_GLdouble_GLdouble_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLint_GLdouble_GLdouble_GLdouble_GLdouble func;
    ARGS_void_GLint_GLdouble_GLdouble_GLdouble_GLdouble args;
} PACKED_void_GLint_GLdouble_GLdouble_GLdouble_GLdouble;
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
typedef void (*FUNC_void_GLint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT)(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
typedef struct {
    GLint a1;
    GLint64EXT a2;
    GLint64EXT a3;
    GLint64EXT a4;
    GLint64EXT a5;
} ARGS_void_GLint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT;
typedef struct {
    int format;
    FUNC_void_GLint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT func;
    ARGS_void_GLint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT args;
} PACKED_void_GLint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT;
typedef void (*FUNC_void_GLint_GLuint_GLuint_GLuint_GLuint)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
typedef struct {
    GLint a1;
    GLuint a2;
    GLuint a3;
    GLuint a4;
    GLuint a5;
} ARGS_void_GLint_GLuint_GLuint_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLint_GLuint_GLuint_GLuint_GLuint func;
    ARGS_void_GLint_GLuint_GLuint_GLuint_GLuint args;
} PACKED_void_GLint_GLuint_GLuint_GLuint_GLuint;
typedef void (*FUNC_void_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT)(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
typedef struct {
    GLint a1;
    GLuint64EXT a2;
    GLuint64EXT a3;
    GLuint64EXT a4;
    GLuint64EXT a5;
} ARGS_void_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT;
typedef struct {
    int format;
    FUNC_void_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT func;
    ARGS_void_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT args;
} PACKED_void_GLint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT;
typedef void (*FUNC_void_GLint_GLuint64)(GLint location, GLuint64 value);
typedef struct {
    GLint a1;
    GLuint64 a2;
} ARGS_void_GLint_GLuint64;
typedef struct {
    int format;
    FUNC_void_GLint_GLuint64 func;
    ARGS_void_GLint_GLuint64 args;
} PACKED_void_GLint_GLuint64;
typedef void (*FUNC_void_GLint_GLsizei_GLuint64)(GLint location, GLsizei count, GLuint64 value);
typedef struct {
    GLint a1;
    GLsizei a2;
    GLuint64 a3;
} ARGS_void_GLint_GLsizei_GLuint64;
typedef struct {
    int format;
    FUNC_void_GLint_GLsizei_GLuint64 func;
    ARGS_void_GLint_GLsizei_GLuint64 args;
} PACKED_void_GLint_GLsizei_GLuint64;
typedef void (*FUNC_void_GLint_GLsizei_GLboolean_GLdouble)(GLint location, GLsizei count, GLboolean transpose, GLdouble value);
typedef struct {
    GLint a1;
    GLsizei a2;
    GLboolean a3;
    GLdouble a4;
} ARGS_void_GLint_GLsizei_GLboolean_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLint_GLsizei_GLboolean_GLdouble func;
    ARGS_void_GLint_GLsizei_GLboolean_GLdouble args;
} PACKED_void_GLint_GLsizei_GLboolean_GLdouble;
typedef void (*FUNC_void_GLint_GLsizei_GLboolean_GLfloat)(GLint location, GLsizei count, GLboolean transpose, GLfloat value);
typedef struct {
    GLint a1;
    GLsizei a2;
    GLboolean a3;
    GLfloat a4;
} ARGS_void_GLint_GLsizei_GLboolean_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLint_GLsizei_GLboolean_GLfloat func;
    ARGS_void_GLint_GLsizei_GLboolean_GLfloat args;
} PACKED_void_GLint_GLsizei_GLboolean_GLfloat;
typedef void (*FUNC_void_GLuint_GLuint_GLsizei_GLvoid_GLenum)(GLuint buffer, GLuint offset, GLsizei size, GLvoid pointer, GLenum preserve);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLsizei a3;
    GLvoid a4;
    GLenum a5;
} ARGS_void_GLuint_GLuint_GLsizei_GLvoid_GLenum;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLsizei_GLvoid_GLenum func;
    ARGS_void_GLuint_GLuint_GLsizei_GLvoid_GLenum args;
} PACKED_void_GLuint_GLuint_GLsizei_GLvoid_GLenum;
typedef void (*FUNC_void_GLuint_GLbitfield_GLuint)(GLuint pipeline, GLbitfield stages, GLuint program);
typedef struct {
    GLuint a1;
    GLbitfield a2;
    GLuint a3;
} ARGS_void_GLuint_GLbitfield_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLbitfield_GLuint func;
    ARGS_void_GLuint_GLbitfield_GLuint args;
} PACKED_void_GLuint_GLbitfield_GLuint;
typedef void (*FUNC_void_GLvdpauSurfaceNV_GLenum_GLsizei_GLsizei_GLint)(GLvdpauSurfaceNV surface, GLenum pname, GLsizei bufSize, GLsizei length, GLint values);
typedef struct {
    GLvdpauSurfaceNV a1;
    GLenum a2;
    GLsizei a3;
    GLsizei a4;
    GLint a5;
} ARGS_void_GLvdpauSurfaceNV_GLenum_GLsizei_GLsizei_GLint;
typedef struct {
    int format;
    FUNC_void_GLvdpauSurfaceNV_GLenum_GLsizei_GLsizei_GLint func;
    ARGS_void_GLvdpauSurfaceNV_GLenum_GLsizei_GLsizei_GLint args;
} PACKED_void_GLvdpauSurfaceNV_GLenum_GLsizei_GLsizei_GLint;
typedef void (*FUNC_void_GLvoid_GLvoid)(GLvoid vdpDevice, GLvoid getProcAddress);
typedef struct {
    GLvoid a1;
    GLvoid a2;
} ARGS_void_GLvoid_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLvoid_GLvoid func;
    ARGS_void_GLvoid_GLvoid args;
} PACKED_void_GLvoid_GLvoid;
typedef void (*FUNC_void_GLvdpauSurfaceNV)(GLvdpauSurfaceNV surface);
typedef struct {
    GLvdpauSurfaceNV a1;
} ARGS_void_GLvdpauSurfaceNV;
typedef struct {
    int format;
    FUNC_void_GLvdpauSurfaceNV func;
    ARGS_void_GLvdpauSurfaceNV args;
} PACKED_void_GLvdpauSurfaceNV;
typedef void (*FUNC_void_GLsizei_GLvdpauSurfaceNV)(GLsizei numSurfaces, GLvdpauSurfaceNV surfaces);
typedef struct {
    GLsizei a1;
    GLvdpauSurfaceNV a2;
} ARGS_void_GLsizei_GLvdpauSurfaceNV;
typedef struct {
    int format;
    FUNC_void_GLsizei_GLvdpauSurfaceNV func;
    ARGS_void_GLsizei_GLvdpauSurfaceNV args;
} PACKED_void_GLsizei_GLvdpauSurfaceNV;
typedef vdpauSurfaceNV (*FUNC_vdpauSurfaceNV_GLvoid___GENPT___GLenum_GLsizei_GLuint)(GLvoid * vdpSurface, GLenum target, GLsizei numTextureNames, GLuint textureNames);
typedef struct {
    GLvoid * a1;
    GLenum a2;
    GLsizei a3;
    GLuint a4;
} ARGS_vdpauSurfaceNV_GLvoid___GENPT___GLenum_GLsizei_GLuint;
typedef struct {
    int format;
    FUNC_vdpauSurfaceNV_GLvoid___GENPT___GLenum_GLsizei_GLuint func;
    ARGS_vdpauSurfaceNV_GLvoid___GENPT___GLenum_GLsizei_GLuint args;
} PACKED_vdpauSurfaceNV_GLvoid___GENPT___GLenum_GLsizei_GLuint;
typedef vdpauSurfaceNV (*FUNC_vdpauSurfaceNV_GLvoid_GLenum_GLsizei_GLuint)(GLvoid vdpSurface, GLenum target, GLsizei numTextureNames, GLuint textureNames);
typedef struct {
    GLvoid a1;
    GLenum a2;
    GLsizei a3;
    GLuint a4;
} ARGS_vdpauSurfaceNV_GLvoid_GLenum_GLsizei_GLuint;
typedef struct {
    int format;
    FUNC_vdpauSurfaceNV_GLvoid_GLenum_GLsizei_GLuint func;
    ARGS_vdpauSurfaceNV_GLvoid_GLenum_GLsizei_GLuint args;
} PACKED_vdpauSurfaceNV_GLvoid_GLenum_GLsizei_GLuint;
typedef void (*FUNC_void_GLvdpauSurfaceNV_GLenum)(GLvdpauSurfaceNV surface, GLenum access);
typedef struct {
    GLvdpauSurfaceNV a1;
    GLenum a2;
} ARGS_void_GLvdpauSurfaceNV_GLenum;
typedef struct {
    int format;
    FUNC_void_GLvdpauSurfaceNV_GLenum func;
    ARGS_void_GLvdpauSurfaceNV_GLenum args;
} PACKED_void_GLvdpauSurfaceNV_GLenum;
typedef void (*FUNC_void_GLuint_GLenum_GLsizei_GLuint_GLuint)(GLuint id, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLsizei a3;
    GLuint a4;
    GLuint a5;
} ARGS_void_GLuint_GLenum_GLsizei_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLsizei_GLuint_GLuint func;
    ARGS_void_GLuint_GLenum_GLsizei_GLuint_GLuint args;
} PACKED_void_GLuint_GLenum_GLsizei_GLuint_GLuint;
typedef void (*FUNC_void_GLuint_GLenum_GLuint_GLvoid)(GLuint id, GLenum type, GLuint stride, GLvoid addr);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLuint a3;
    GLvoid a4;
} ARGS_void_GLuint_GLenum_GLuint_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLuint_GLvoid func;
    ARGS_void_GLuint_GLenum_GLuint_GLvoid args;
} PACKED_void_GLuint_GLenum_GLuint_GLvoid;
typedef void (*FUNC_void_GLuint_GLbyte)(GLuint id, GLbyte addr);
typedef struct {
    GLuint a1;
    GLbyte a2;
} ARGS_void_GLuint_GLbyte;
typedef struct {
    int format;
    FUNC_void_GLuint_GLbyte func;
    ARGS_void_GLuint_GLbyte args;
} PACKED_void_GLuint_GLbyte;
typedef void (*FUNC_void_GLuint_GLdouble)(GLuint id, GLdouble addr);
typedef struct {
    GLuint a1;
    GLdouble a2;
} ARGS_void_GLuint_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLuint_GLdouble func;
    ARGS_void_GLuint_GLdouble args;
} PACKED_void_GLuint_GLdouble;
typedef void (*FUNC_void_GLuint_GLshort)(GLuint id, GLshort addr);
typedef struct {
    GLuint a1;
    GLshort a2;
} ARGS_void_GLuint_GLshort;
typedef struct {
    int format;
    FUNC_void_GLuint_GLshort func;
    ARGS_void_GLuint_GLshort args;
} PACKED_void_GLuint_GLshort;
typedef void (*FUNC_void_GLuint_GLushort)(GLuint id, GLushort addr);
typedef struct {
    GLuint a1;
    GLushort a2;
} ARGS_void_GLuint_GLushort;
typedef struct {
    int format;
    FUNC_void_GLuint_GLushort func;
    ARGS_void_GLuint_GLushort args;
} PACKED_void_GLuint_GLushort;
typedef void (*FUNC_void_GLuint_GLuint_GLuint_GLintptr_GLsizei)(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLuint a3;
    GLintptr a4;
    GLsizei a5;
} ARGS_void_GLuint_GLuint_GLuint_GLintptr_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLuint_GLintptr_GLsizei func;
    ARGS_void_GLuint_GLuint_GLuint_GLintptr_GLsizei args;
} PACKED_void_GLuint_GLuint_GLuint_GLintptr_GLsizei;
typedef void (*FUNC_void_GLuint_GLuint_GLint_GLenum_GLsizei_GLintptr)(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLint a3;
    GLenum a4;
    GLsizei a5;
    GLintptr a6;
} ARGS_void_GLuint_GLuint_GLint_GLenum_GLsizei_GLintptr;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLint_GLenum_GLsizei_GLintptr func;
    ARGS_void_GLuint_GLuint_GLint_GLenum_GLsizei_GLintptr args;
} PACKED_void_GLuint_GLuint_GLint_GLenum_GLsizei_GLintptr;
typedef void (*FUNC_void_GLuint_GLuint_GLsizei_GLintptr)(GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLsizei a3;
    GLintptr a4;
} ARGS_void_GLuint_GLuint_GLsizei_GLintptr;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLsizei_GLintptr func;
    ARGS_void_GLuint_GLuint_GLsizei_GLintptr args;
} PACKED_void_GLuint_GLuint_GLsizei_GLintptr;
typedef void (*FUNC_void_GLuint_GLuint_GLenum_GLsizei_GLintptr)(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLenum a3;
    GLsizei a4;
    GLintptr a5;
} ARGS_void_GLuint_GLuint_GLenum_GLsizei_GLintptr;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLenum_GLsizei_GLintptr func;
    ARGS_void_GLuint_GLuint_GLenum_GLsizei_GLintptr args;
} PACKED_void_GLuint_GLuint_GLenum_GLsizei_GLintptr;
typedef void (*FUNC_void_GLuint_GLuint_GLenum_GLint_GLenum_GLsizei_GLintptr)(GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLenum a3;
    GLint a4;
    GLenum a5;
    GLsizei a6;
    GLintptr a7;
} ARGS_void_GLuint_GLuint_GLenum_GLint_GLenum_GLsizei_GLintptr;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLenum_GLint_GLenum_GLsizei_GLintptr func;
    ARGS_void_GLuint_GLuint_GLenum_GLint_GLenum_GLsizei_GLintptr args;
} PACKED_void_GLuint_GLuint_GLenum_GLint_GLenum_GLsizei_GLintptr;
typedef void (*FUNC_void_GLuint_GLuint_GLint_GLenum_GLboolean_GLuint)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLint a3;
    GLenum a4;
    GLboolean a5;
    GLuint a6;
} ARGS_void_GLuint_GLuint_GLint_GLenum_GLboolean_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLint_GLenum_GLboolean_GLuint func;
    ARGS_void_GLuint_GLuint_GLint_GLenum_GLboolean_GLuint args;
} PACKED_void_GLuint_GLuint_GLint_GLenum_GLboolean_GLuint;
typedef void (*FUNC_void_GLuint_GLuint_GLint_GLenum_GLuint)(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLint a3;
    GLenum a4;
    GLuint a5;
} ARGS_void_GLuint_GLuint_GLint_GLenum_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLint_GLenum_GLuint func;
    ARGS_void_GLuint_GLuint_GLint_GLenum_GLuint args;
} PACKED_void_GLuint_GLuint_GLint_GLenum_GLuint;
typedef void (*FUNC_void_GLuint_GLuint_GLuint_GLint_GLenum_GLsizei_GLintptr)(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLuint a3;
    GLint a4;
    GLenum a5;
    GLsizei a6;
    GLintptr a7;
} ARGS_void_GLuint_GLuint_GLuint_GLint_GLenum_GLsizei_GLintptr;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLuint_GLint_GLenum_GLsizei_GLintptr func;
    ARGS_void_GLuint_GLuint_GLuint_GLint_GLenum_GLsizei_GLintptr args;
} PACKED_void_GLuint_GLuint_GLuint_GLint_GLenum_GLsizei_GLintptr;
typedef void (*FUNC_void_GLuint_GLuint_GLuint_GLint_GLenum_GLboolean_GLsizei_GLintptr)(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLuint a3;
    GLint a4;
    GLenum a5;
    GLboolean a6;
    GLsizei a7;
    GLintptr a8;
} ARGS_void_GLuint_GLuint_GLuint_GLint_GLenum_GLboolean_GLsizei_GLintptr;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLuint_GLint_GLenum_GLboolean_GLsizei_GLintptr func;
    ARGS_void_GLuint_GLuint_GLuint_GLint_GLenum_GLboolean_GLsizei_GLintptr args;
} PACKED_void_GLuint_GLuint_GLuint_GLint_GLenum_GLboolean_GLsizei_GLintptr;
typedef void (*FUNC_void_GLuint_GLhalfNV)(GLuint index, GLhalfNV x);
typedef struct {
    GLuint a1;
    GLhalfNV a2;
} ARGS_void_GLuint_GLhalfNV;
typedef struct {
    int format;
    FUNC_void_GLuint_GLhalfNV func;
    ARGS_void_GLuint_GLhalfNV args;
} PACKED_void_GLuint_GLhalfNV;
typedef void (*FUNC_void_GLuint_GLhalfNV_GLhalfNV)(GLuint index, GLhalfNV x, GLhalfNV y);
typedef struct {
    GLuint a1;
    GLhalfNV a2;
    GLhalfNV a3;
} ARGS_void_GLuint_GLhalfNV_GLhalfNV;
typedef struct {
    int format;
    FUNC_void_GLuint_GLhalfNV_GLhalfNV func;
    ARGS_void_GLuint_GLhalfNV_GLhalfNV args;
} PACKED_void_GLuint_GLhalfNV_GLhalfNV;
typedef void (*FUNC_void_GLuint_GLshort_GLshort)(GLuint index, GLshort x, GLshort y);
typedef struct {
    GLuint a1;
    GLshort a2;
    GLshort a3;
} ARGS_void_GLuint_GLshort_GLshort;
typedef struct {
    int format;
    FUNC_void_GLuint_GLshort_GLshort func;
    ARGS_void_GLuint_GLshort_GLshort args;
} PACKED_void_GLuint_GLshort_GLshort;
typedef void (*FUNC_void_GLuint_GLdouble_GLdouble_GLdouble)(GLuint index, GLdouble x, GLdouble y, GLdouble z);
typedef struct {
    GLuint a1;
    GLdouble a2;
    GLdouble a3;
    GLdouble a4;
} ARGS_void_GLuint_GLdouble_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLuint_GLdouble_GLdouble_GLdouble func;
    ARGS_void_GLuint_GLdouble_GLdouble_GLdouble args;
} PACKED_void_GLuint_GLdouble_GLdouble_GLdouble;
typedef void (*FUNC_void_GLuint_GLhalfNV_GLhalfNV_GLhalfNV)(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z);
typedef struct {
    GLuint a1;
    GLhalfNV a2;
    GLhalfNV a3;
    GLhalfNV a4;
} ARGS_void_GLuint_GLhalfNV_GLhalfNV_GLhalfNV;
typedef struct {
    int format;
    FUNC_void_GLuint_GLhalfNV_GLhalfNV_GLhalfNV func;
    ARGS_void_GLuint_GLhalfNV_GLhalfNV_GLhalfNV args;
} PACKED_void_GLuint_GLhalfNV_GLhalfNV_GLhalfNV;
typedef void (*FUNC_void_GLuint_GLshort_GLshort_GLshort)(GLuint index, GLshort x, GLshort y, GLshort z);
typedef struct {
    GLuint a1;
    GLshort a2;
    GLshort a3;
    GLshort a4;
} ARGS_void_GLuint_GLshort_GLshort_GLshort;
typedef struct {
    int format;
    FUNC_void_GLuint_GLshort_GLshort_GLshort func;
    ARGS_void_GLuint_GLshort_GLshort_GLshort args;
} PACKED_void_GLuint_GLshort_GLshort_GLshort;
typedef void (*FUNC_void_GLuint_GLubyte_GLubyte_GLubyte_GLubyte)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
typedef struct {
    GLuint a1;
    GLubyte a2;
    GLubyte a3;
    GLubyte a4;
    GLubyte a5;
} ARGS_void_GLuint_GLubyte_GLubyte_GLubyte_GLubyte;
typedef struct {
    int format;
    FUNC_void_GLuint_GLubyte_GLubyte_GLubyte_GLubyte func;
    ARGS_void_GLuint_GLubyte_GLubyte_GLubyte_GLubyte args;
} PACKED_void_GLuint_GLubyte_GLubyte_GLubyte_GLubyte;
typedef void (*FUNC_void_GLuint_GLdouble_GLdouble_GLdouble_GLdouble)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
typedef struct {
    GLuint a1;
    GLdouble a2;
    GLdouble a3;
    GLdouble a4;
    GLdouble a5;
} ARGS_void_GLuint_GLdouble_GLdouble_GLdouble_GLdouble;
typedef struct {
    int format;
    FUNC_void_GLuint_GLdouble_GLdouble_GLdouble_GLdouble func;
    ARGS_void_GLuint_GLdouble_GLdouble_GLdouble_GLdouble args;
} PACKED_void_GLuint_GLdouble_GLdouble_GLdouble_GLdouble;
typedef void (*FUNC_void_GLuint_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV)(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
typedef struct {
    GLuint a1;
    GLhalfNV a2;
    GLhalfNV a3;
    GLhalfNV a4;
    GLhalfNV a5;
} ARGS_void_GLuint_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV;
typedef struct {
    int format;
    FUNC_void_GLuint_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV func;
    ARGS_void_GLuint_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV args;
} PACKED_void_GLuint_GLhalfNV_GLhalfNV_GLhalfNV_GLhalfNV;
typedef void (*FUNC_void_GLuint_GLshort_GLshort_GLshort_GLshort)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
typedef struct {
    GLuint a1;
    GLshort a2;
    GLshort a3;
    GLshort a4;
    GLshort a5;
} ARGS_void_GLuint_GLshort_GLshort_GLshort_GLshort;
typedef struct {
    int format;
    FUNC_void_GLuint_GLshort_GLshort_GLshort_GLshort func;
    ARGS_void_GLuint_GLshort_GLshort_GLshort_GLshort args;
} PACKED_void_GLuint_GLshort_GLshort_GLshort_GLshort;
typedef void (*FUNC_void_GLuint_GLint_GLenum_GLboolean_GLsizei_GLuint_GLuint)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint buffer, GLuint offset);
typedef struct {
    GLuint a1;
    GLint a2;
    GLenum a3;
    GLboolean a4;
    GLsizei a5;
    GLuint a6;
    GLuint a7;
} ARGS_void_GLuint_GLint_GLenum_GLboolean_GLsizei_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLenum_GLboolean_GLsizei_GLuint_GLuint func;
    ARGS_void_GLuint_GLint_GLenum_GLboolean_GLsizei_GLuint_GLuint args;
} PACKED_void_GLuint_GLint_GLenum_GLboolean_GLsizei_GLuint_GLuint;
typedef void (*FUNC_void_GLuint_GLint_GLenum_GLboolean_GLuint)(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
typedef struct {
    GLuint a1;
    GLint a2;
    GLenum a3;
    GLboolean a4;
    GLuint a5;
} ARGS_void_GLuint_GLint_GLenum_GLboolean_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLenum_GLboolean_GLuint func;
    ARGS_void_GLuint_GLint_GLenum_GLboolean_GLuint args;
} PACKED_void_GLuint_GLint_GLenum_GLboolean_GLuint;
typedef void (*FUNC_void_GLuint_GLint_GLenum_GLboolean_GLsizei)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
typedef struct {
    GLuint a1;
    GLint a2;
    GLenum a3;
    GLboolean a4;
    GLsizei a5;
} ARGS_void_GLuint_GLint_GLenum_GLboolean_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLenum_GLboolean_GLsizei func;
    ARGS_void_GLuint_GLint_GLenum_GLboolean_GLsizei args;
} PACKED_void_GLuint_GLint_GLenum_GLboolean_GLsizei;
typedef void (*FUNC_void_GLuint_GLuint_GLuint_GLuint_GLuint)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLuint a3;
    GLuint a4;
    GLuint a5;
} ARGS_void_GLuint_GLuint_GLuint_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint_GLuint_GLuint_GLuint func;
    ARGS_void_GLuint_GLuint_GLuint_GLuint_GLuint args;
} PACKED_void_GLuint_GLuint_GLuint_GLuint_GLuint;
typedef void (*FUNC_void_GLuint_GLint_GLenum_GLuint)(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
typedef struct {
    GLuint a1;
    GLint a2;
    GLenum a3;
    GLuint a4;
} ARGS_void_GLuint_GLint_GLenum_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLenum_GLuint func;
    ARGS_void_GLuint_GLint_GLenum_GLuint args;
} PACKED_void_GLuint_GLint_GLenum_GLuint;
typedef void (*FUNC_void_GLuint_GLint_GLenum_GLsizei)(GLuint index, GLint size, GLenum type, GLsizei stride);
typedef struct {
    GLuint a1;
    GLint a2;
    GLenum a3;
    GLsizei a4;
} ARGS_void_GLuint_GLint_GLenum_GLsizei;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLenum_GLsizei func;
    ARGS_void_GLuint_GLint_GLenum_GLsizei args;
} PACKED_void_GLuint_GLint_GLenum_GLsizei;
typedef void (*FUNC_void_GLuint_GLint_GLenum_GLsizei_GLvoid)(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid pointer);
typedef struct {
    GLuint a1;
    GLint a2;
    GLenum a3;
    GLsizei a4;
    GLvoid a5;
} ARGS_void_GLuint_GLint_GLenum_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLenum_GLsizei_GLvoid func;
    ARGS_void_GLuint_GLint_GLenum_GLsizei_GLvoid args;
} PACKED_void_GLuint_GLint_GLenum_GLsizei_GLvoid;
typedef void (*FUNC_void_GLuint_GLint64EXT)(GLuint index, GLint64EXT x);
typedef struct {
    GLuint a1;
    GLint64EXT a2;
} ARGS_void_GLuint_GLint64EXT;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint64EXT func;
    ARGS_void_GLuint_GLint64EXT args;
} PACKED_void_GLuint_GLint64EXT;
typedef void (*FUNC_void_GLuint_GLuint64EXT)(GLuint index, GLuint64EXT x);
typedef struct {
    GLuint a1;
    GLuint64EXT a2;
} ARGS_void_GLuint_GLuint64EXT;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint64EXT func;
    ARGS_void_GLuint_GLuint64EXT args;
} PACKED_void_GLuint_GLuint64EXT;
typedef void (*FUNC_void_GLuint_GLint64EXT_GLint64EXT)(GLuint index, GLint64EXT x, GLint64EXT y);
typedef struct {
    GLuint a1;
    GLint64EXT a2;
    GLint64EXT a3;
} ARGS_void_GLuint_GLint64EXT_GLint64EXT;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint64EXT_GLint64EXT func;
    ARGS_void_GLuint_GLint64EXT_GLint64EXT args;
} PACKED_void_GLuint_GLint64EXT_GLint64EXT;
typedef void (*FUNC_void_GLuint_GLuint64EXT_GLuint64EXT)(GLuint index, GLuint64EXT x, GLuint64EXT y);
typedef struct {
    GLuint a1;
    GLuint64EXT a2;
    GLuint64EXT a3;
} ARGS_void_GLuint_GLuint64EXT_GLuint64EXT;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint64EXT_GLuint64EXT func;
    ARGS_void_GLuint_GLuint64EXT_GLuint64EXT args;
} PACKED_void_GLuint_GLuint64EXT_GLuint64EXT;
typedef void (*FUNC_void_GLuint_GLint64EXT_GLint64EXT_GLint64EXT)(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z);
typedef struct {
    GLuint a1;
    GLint64EXT a2;
    GLint64EXT a3;
    GLint64EXT a4;
} ARGS_void_GLuint_GLint64EXT_GLint64EXT_GLint64EXT;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint64EXT_GLint64EXT_GLint64EXT func;
    ARGS_void_GLuint_GLint64EXT_GLint64EXT_GLint64EXT args;
} PACKED_void_GLuint_GLint64EXT_GLint64EXT_GLint64EXT;
typedef void (*FUNC_void_GLuint_GLuint64EXT_GLuint64EXT_GLuint64EXT)(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
typedef struct {
    GLuint a1;
    GLuint64EXT a2;
    GLuint64EXT a3;
    GLuint64EXT a4;
} ARGS_void_GLuint_GLuint64EXT_GLuint64EXT_GLuint64EXT;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint64EXT_GLuint64EXT_GLuint64EXT func;
    ARGS_void_GLuint_GLuint64EXT_GLuint64EXT_GLuint64EXT args;
} PACKED_void_GLuint_GLuint64EXT_GLuint64EXT_GLuint64EXT;
typedef void (*FUNC_void_GLuint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT)(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
typedef struct {
    GLuint a1;
    GLint64EXT a2;
    GLint64EXT a3;
    GLint64EXT a4;
    GLint64EXT a5;
} ARGS_void_GLuint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT func;
    ARGS_void_GLuint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT args;
} PACKED_void_GLuint_GLint64EXT_GLint64EXT_GLint64EXT_GLint64EXT;
typedef void (*FUNC_void_GLuint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT)(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
typedef struct {
    GLuint a1;
    GLuint64EXT a2;
    GLuint64EXT a3;
    GLuint64EXT a4;
    GLuint64EXT a5;
} ARGS_void_GLuint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT;
typedef struct {
    int format;
    FUNC_void_GLuint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT func;
    ARGS_void_GLuint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT args;
} PACKED_void_GLuint_GLuint64EXT_GLuint64EXT_GLuint64EXT_GLuint64EXT;
typedef void (*FUNC_void_GLuint_GLenum_GLboolean_GLuint)(GLuint index, GLenum type, GLboolean normalized, GLuint value);
typedef struct {
    GLuint a1;
    GLenum a2;
    GLboolean a3;
    GLuint a4;
} ARGS_void_GLuint_GLenum_GLboolean_GLuint;
typedef struct {
    int format;
    FUNC_void_GLuint_GLenum_GLboolean_GLuint func;
    ARGS_void_GLuint_GLenum_GLboolean_GLuint args;
} PACKED_void_GLuint_GLenum_GLboolean_GLuint;
typedef void (*FUNC_void_GLuint_GLint_GLenum_GLboolean_GLsizei_GLvoid)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid pointer);
typedef struct {
    GLuint a1;
    GLint a2;
    GLenum a3;
    GLboolean a4;
    GLsizei a5;
    GLvoid a6;
} ARGS_void_GLuint_GLint_GLenum_GLboolean_GLsizei_GLvoid;
typedef struct {
    int format;
    FUNC_void_GLuint_GLint_GLenum_GLboolean_GLsizei_GLvoid func;
    ARGS_void_GLuint_GLint_GLenum_GLboolean_GLsizei_GLvoid args;
} PACKED_void_GLuint_GLint_GLenum_GLboolean_GLsizei_GLvoid;
typedef void (*FUNC_void_GLuint_GLsizei_GLhalfNV)(GLuint index, GLsizei n, GLhalfNV v);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLhalfNV a3;
} ARGS_void_GLuint_GLsizei_GLhalfNV;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLhalfNV func;
    ARGS_void_GLuint_GLsizei_GLhalfNV args;
} PACKED_void_GLuint_GLsizei_GLhalfNV;
typedef void (*FUNC_void_GLuint_GLsizei_GLshort)(GLuint index, GLsizei count, GLshort v);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLshort a3;
} ARGS_void_GLuint_GLsizei_GLshort;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLshort func;
    ARGS_void_GLuint_GLsizei_GLshort args;
} PACKED_void_GLuint_GLsizei_GLshort;
typedef void (*FUNC_void_GLuint_GLsizei_GLubyte)(GLuint index, GLsizei count, GLubyte v);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLubyte a3;
} ARGS_void_GLuint_GLsizei_GLubyte;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLubyte func;
    ARGS_void_GLuint_GLsizei_GLubyte args;
} PACKED_void_GLuint_GLsizei_GLubyte;
typedef GLenum (*FUNC_GLenum_GLuint_GLuint_GLuint64EXT)(GLuint video_capture_slot, GLuint sequence_num, GLuint64EXT capture_time);
typedef struct {
    GLuint a1;
    GLuint a2;
    GLuint64EXT a3;
} ARGS_GLenum_GLuint_GLuint_GLuint64EXT;
typedef struct {
    int format;
    FUNC_GLenum_GLuint_GLuint_GLuint64EXT func;
    ARGS_GLenum_GLuint_GLuint_GLuint64EXT args;
} PACKED_GLenum_GLuint_GLuint_GLuint64EXT;
typedef void (*FUNC_void_GLsync_GLbitfield_GLuint64)(GLsync sync, GLbitfield flags, GLuint64 timeout);
typedef struct {
    GLsync a1;
    GLbitfield a2;
    GLuint64 a3;
} ARGS_void_GLsync_GLbitfield_GLuint64;
typedef struct {
    int format;
    FUNC_void_GLsync_GLbitfield_GLuint64 func;
    ARGS_void_GLsync_GLbitfield_GLuint64 args;
} PACKED_void_GLsync_GLbitfield_GLuint64;
typedef void (*FUNC_void_GLuint_GLsizei_GLuint_GLfloat)(GLuint resultPath, GLsizei numPaths, GLuint paths, GLfloat weights);
typedef struct {
    GLuint a1;
    GLsizei a2;
    GLuint a3;
    GLfloat a4;
} ARGS_void_GLuint_GLsizei_GLuint_GLfloat;
typedef struct {
    int format;
    FUNC_void_GLuint_GLsizei_GLuint_GLfloat func;
    ARGS_void_GLuint_GLsizei_GLuint_GLfloat args;
} PACKED_void_GLuint_GLsizei_GLuint_GLfloat;
typedef void (*FUNC_void_GLint_GLbyte)(GLint size, GLbyte weights);
typedef struct {
    GLint a1;
    GLbyte a2;
} ARGS_void_GLint_GLbyte;
typedef struct {
    int format;
    FUNC_void_GLint_GLbyte func;
    ARGS_void_GLint_GLbyte args;
} PACKED_void_GLint_GLbyte;
typedef void (*FUNC_void_GLint_GLshort)(GLint size, GLshort weights);
typedef struct {
    GLint a1;
    GLshort a2;
} ARGS_void_GLint_GLshort;
typedef struct {
    int format;
    FUNC_void_GLint_GLshort func;
    ARGS_void_GLint_GLshort args;
} PACKED_void_GLint_GLshort;
typedef Bool (*FUNC_Bool_Display_GLXPbufferSGIX_DMparams_DMbuffer)(Display dpy, GLXPbufferSGIX pbuffer, DMparams params, DMbuffer dmbuffer);
typedef struct {
    Display a1;
    GLXPbufferSGIX a2;
    DMparams a3;
    DMbuffer a4;
} ARGS_Bool_Display_GLXPbufferSGIX_DMparams_DMbuffer;
typedef struct {
    int format;
    FUNC_Bool_Display_GLXPbufferSGIX_DMparams_DMbuffer func;
    ARGS_Bool_Display_GLXPbufferSGIX_DMparams_DMbuffer args;
} PACKED_Bool_Display_GLXPbufferSGIX_DMparams_DMbuffer;
typedef int (*FUNC_int_Display_int_int_Window)(Display display, int screen, int channel, Window window);
typedef struct {
    Display a1;
    int a2;
    int a3;
    Window a4;
} ARGS_int_Display_int_int_Window;
typedef struct {
    int format;
    FUNC_int_Display_int_int_Window func;
    ARGS_int_Display_int_int_Window args;
} PACKED_int_Display_int_int_Window;
typedef int (*FUNC_int_Display_int)(Display dpy, int hpId);
typedef struct {
    Display a1;
    int a2;
} ARGS_int_Display_int;
typedef struct {
    int format;
    FUNC_int_Display_int func;
    ARGS_int_Display_int args;
} PACKED_int_Display_int;
typedef Bool (*FUNC_Bool_Display_GLuint_GLuint)(Display dpy, GLuint group, GLuint barrier);
typedef struct {
    Display a1;
    GLuint a2;
    GLuint a3;
} ARGS_Bool_Display_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_Bool_Display_GLuint_GLuint func;
    ARGS_Bool_Display_GLuint_GLuint args;
} PACKED_Bool_Display_GLuint_GLuint;
typedef void (*FUNC_void_Display_GLXDrawable_int)(Display dpy, GLXDrawable drawable, int barrier);
typedef struct {
    Display a1;
    GLXDrawable a2;
    int a3;
} ARGS_void_Display_GLXDrawable_int;
typedef struct {
    int format;
    FUNC_void_Display_GLXDrawable_int func;
    ARGS_void_Display_GLXDrawable_int args;
} PACKED_void_Display_GLXDrawable_int;
typedef void (*FUNC_void_Display_GLXDrawable_int_int)(Display dpy, GLXDrawable drawable, int buffer, int attrib_list);
typedef struct {
    Display a1;
    GLXDrawable a2;
    int a3;
    int a4;
} ARGS_void_Display_GLXDrawable_int_int;
typedef struct {
    int format;
    FUNC_void_Display_GLXDrawable_int_int func;
    ARGS_void_Display_GLXDrawable_int_int args;
} PACKED_void_Display_GLXDrawable_int_int;
typedef int (*FUNC_int_Display_unsigned_int_GLXVideoCaptureDeviceNV)(Display dpy, unsigned int video_capture_slot, GLXVideoCaptureDeviceNV device);
typedef struct {
    Display a1;
    unsigned int a2;
    GLXVideoCaptureDeviceNV a3;
} ARGS_int_Display_unsigned_int_GLXVideoCaptureDeviceNV;
typedef struct {
    int format;
    FUNC_int_Display_unsigned_int_GLXVideoCaptureDeviceNV func;
    ARGS_int_Display_unsigned_int_GLXVideoCaptureDeviceNV args;
} PACKED_int_Display_unsigned_int_GLXVideoCaptureDeviceNV;
typedef int (*FUNC_int_Display_unsigned_int_unsigned_int_int)(Display dpy, unsigned int video_slot, unsigned int video_device, int attrib_list);
typedef struct {
    Display a1;
    unsigned int a2;
    unsigned int a3;
    int a4;
} ARGS_int_Display_unsigned_int_unsigned_int_int;
typedef struct {
    int format;
    FUNC_int_Display_unsigned_int_unsigned_int_int func;
    ARGS_int_Display_unsigned_int_unsigned_int_int args;
} PACKED_int_Display_unsigned_int_unsigned_int_int;
typedef int (*FUNC_int_Display_GLXVideoDeviceNV_GLXPbuffer_int)(Display dpy, GLXVideoDeviceNV VideoDevice, GLXPbuffer pbuf, int iVideoBuffer);
typedef struct {
    Display a1;
    GLXVideoDeviceNV a2;
    GLXPbuffer a3;
    int a4;
} ARGS_int_Display_GLXVideoDeviceNV_GLXPbuffer_int;
typedef struct {
    int format;
    FUNC_int_Display_GLXVideoDeviceNV_GLXPbuffer_int func;
    ARGS_int_Display_GLXVideoDeviceNV_GLXPbuffer_int args;
} PACKED_int_Display_GLXVideoDeviceNV_GLXPbuffer_int;
typedef int (*FUNC_int_Display_int_int_int_int_int_int)(Display display, int screen, int channel, int x, int y, int w, int h);
typedef struct {
    Display a1;
    int a2;
    int a3;
    int a4;
    int a5;
    int a6;
    int a7;
} ARGS_int_Display_int_int_int_int_int_int;
typedef struct {
    int format;
    FUNC_int_Display_int_int_int_int_int_int func;
    ARGS_int_Display_int_int_int_int_int_int args;
} PACKED_int_Display_int_int_int_int_int_int;
typedef int (*FUNC_int_Display_int_int_GLenum)(Display display, int screen, int channel, GLenum synctype);
typedef struct {
    Display a1;
    int a2;
    int a3;
    GLenum a4;
} ARGS_int_Display_int_int_GLenum;
typedef struct {
    int format;
    FUNC_int_Display_int_int_GLenum func;
    ARGS_int_Display_int_int_GLenum args;
} PACKED_int_Display_int_int_GLenum;
typedef GLXFBConfigPointer (*FUNC_GLXFBConfigPointer_Display_int_int_int)(Display dpy, int screen, int attrib_list, int nelements);
typedef struct {
    Display a1;
    int a2;
    int a3;
    int a4;
} ARGS_GLXFBConfigPointer_Display_int_int_int;
typedef struct {
    int format;
    FUNC_GLXFBConfigPointer_Display_int_int_int func;
    ARGS_GLXFBConfigPointer_Display_int_int_int args;
} PACKED_GLXFBConfigPointer_Display_int_int_int;
typedef GLXFBConfigSGIXPointer (*FUNC_GLXFBConfigSGIXPointer_Display_int_int_int)(Display dpy, int screen, int attrib_list, int nelements);
typedef struct {
    Display a1;
    int a2;
    int a3;
    int a4;
} ARGS_GLXFBConfigSGIXPointer_Display_int_int_int;
typedef struct {
    int format;
    FUNC_GLXFBConfigSGIXPointer_Display_int_int_int func;
    ARGS_GLXFBConfigSGIXPointer_Display_int_int_int args;
} PACKED_GLXFBConfigSGIXPointer_Display_int_int_int;
typedef void (*FUNC_void_Display_GLXContext_GLuint_GLenum_GLint_GLint_GLint_GLint_GLXContext_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei)(Display dpy, GLXContext srcCtx, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLXContext dstCtx, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
typedef struct {
    Display a1;
    GLXContext a2;
    GLuint a3;
    GLenum a4;
    GLint a5;
    GLint a6;
    GLint a7;
    GLint a8;
    GLXContext a9;
    GLuint a10;
    GLenum a11;
    GLint a12;
    GLint a13;
    GLint a14;
    GLint a15;
    GLsizei a16;
    GLsizei a17;
    GLsizei a18;
} ARGS_void_Display_GLXContext_GLuint_GLenum_GLint_GLint_GLint_GLint_GLXContext_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei;
typedef struct {
    int format;
    FUNC_void_Display_GLXContext_GLuint_GLenum_GLint_GLint_GLint_GLint_GLXContext_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei func;
    ARGS_void_Display_GLXContext_GLuint_GLenum_GLint_GLint_GLint_GLint_GLXContext_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei args;
} PACKED_void_Display_GLXContext_GLuint_GLenum_GLint_GLint_GLint_GLint_GLXContext_GLuint_GLenum_GLint_GLint_GLint_GLint_GLsizei_GLsizei_GLsizei;
typedef void (*FUNC_void_Display_GLXDrawable_int_int_int_int)(Display dpy, GLXDrawable drawable, int x, int y, int width, int height);
typedef struct {
    Display a1;
    GLXDrawable a2;
    int a3;
    int a4;
    int a5;
    int a6;
} ARGS_void_Display_GLXDrawable_int_int_int_int;
typedef struct {
    int format;
    FUNC_void_Display_GLXDrawable_int_int_int_int func;
    ARGS_void_Display_GLXDrawable_int_int_int_int args;
} PACKED_void_Display_GLXDrawable_int_int_int_int;
typedef GLXContext (*FUNC_GLXContext_Display_GLXFBConfig_GLXContext_Bool_int)(Display dpy, GLXFBConfig config, GLXContext share_context, Bool direct, int attrib_list);
typedef struct {
    Display a1;
    GLXFBConfig a2;
    GLXContext a3;
    Bool a4;
    int a5;
} ARGS_GLXContext_Display_GLXFBConfig_GLXContext_Bool_int;
typedef struct {
    int format;
    FUNC_GLXContext_Display_GLXFBConfig_GLXContext_Bool_int func;
    ARGS_GLXContext_Display_GLXFBConfig_GLXContext_Bool_int args;
} PACKED_GLXContext_Display_GLXFBConfig_GLXContext_Bool_int;
typedef GLXContext (*FUNC_GLXContext_Display_GLXFBConfigSGIX_int_GLXContext_Bool)(Display dpy, GLXFBConfigSGIX config, int render_type, GLXContext share_list, Bool direct);
typedef struct {
    Display a1;
    GLXFBConfigSGIX a2;
    int a3;
    GLXContext a4;
    Bool a5;
} ARGS_GLXContext_Display_GLXFBConfigSGIX_int_GLXContext_Bool;
typedef struct {
    int format;
    FUNC_GLXContext_Display_GLXFBConfigSGIX_int_GLXContext_Bool func;
    ARGS_GLXContext_Display_GLXFBConfigSGIX_int_GLXContext_Bool args;
} PACKED_GLXContext_Display_GLXFBConfigSGIX_int_GLXContext_Bool;
typedef GLXPbufferSGIX (*FUNC_GLXPbufferSGIX_Display_GLXFBConfigSGIX_unsigned_int_unsigned_int_int)(Display dpy, GLXFBConfigSGIX config, unsigned int width, unsigned int height, int attrib_list);
typedef struct {
    Display a1;
    GLXFBConfigSGIX a2;
    unsigned int a3;
    unsigned int a4;
    int a5;
} ARGS_GLXPbufferSGIX_Display_GLXFBConfigSGIX_unsigned_int_unsigned_int_int;
typedef struct {
    int format;
    FUNC_GLXPbufferSGIX_Display_GLXFBConfigSGIX_unsigned_int_unsigned_int_int func;
    ARGS_GLXPbufferSGIX_Display_GLXFBConfigSGIX_unsigned_int_unsigned_int_int args;
} PACKED_GLXPbufferSGIX_Display_GLXFBConfigSGIX_unsigned_int_unsigned_int_int;
typedef GLXPixmap (*FUNC_GLXPixmap_Display_XVisualInfo_Pixmap_Colormap)(Display dpy, XVisualInfo visual, Pixmap pixmap, Colormap cmap);
typedef struct {
    Display a1;
    XVisualInfo a2;
    Pixmap a3;
    Colormap a4;
} ARGS_GLXPixmap_Display_XVisualInfo_Pixmap_Colormap;
typedef struct {
    int format;
    FUNC_GLXPixmap_Display_XVisualInfo_Pixmap_Colormap func;
    ARGS_GLXPixmap_Display_XVisualInfo_Pixmap_Colormap args;
} PACKED_GLXPixmap_Display_XVisualInfo_Pixmap_Colormap;
typedef GLXPixmap (*FUNC_GLXPixmap_Display_GLXFBConfigSGIX_Pixmap)(Display dpy, GLXFBConfigSGIX config, Pixmap pixmap);
typedef struct {
    Display a1;
    GLXFBConfigSGIX a2;
    Pixmap a3;
} ARGS_GLXPixmap_Display_GLXFBConfigSGIX_Pixmap;
typedef struct {
    int format;
    FUNC_GLXPixmap_Display_GLXFBConfigSGIX_Pixmap func;
    ARGS_GLXPixmap_Display_GLXFBConfigSGIX_Pixmap args;
} PACKED_GLXPixmap_Display_GLXFBConfigSGIX_Pixmap;
typedef GLXVideoSourceSGIX (*FUNC_GLXVideoSourceSGIX_Display_int_VLServer_VLPath_int_VLNode)(Display display, int screen, VLServer server, VLPath path, int nodeClass, VLNode drainNode);
typedef struct {
    Display a1;
    int a2;
    VLServer a3;
    VLPath a4;
    int a5;
    VLNode a6;
} ARGS_GLXVideoSourceSGIX_Display_int_VLServer_VLPath_int_VLNode;
typedef struct {
    int format;
    FUNC_GLXVideoSourceSGIX_Display_int_VLServer_VLPath_int_VLNode func;
    ARGS_GLXVideoSourceSGIX_Display_int_VLServer_VLPath_int_VLNode args;
} PACKED_GLXVideoSourceSGIX_Display_int_VLServer_VLPath_int_VLNode;
typedef GLXContext (*FUNC_GLXContext_Display_GLXFBConfig_int_GLXContext_Bool)(Display dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct);
typedef struct {
    Display a1;
    GLXFBConfig a2;
    int a3;
    GLXContext a4;
    Bool a5;
} ARGS_GLXContext_Display_GLXFBConfig_int_GLXContext_Bool;
typedef struct {
    int format;
    FUNC_GLXContext_Display_GLXFBConfig_int_GLXContext_Bool func;
    ARGS_GLXContext_Display_GLXFBConfig_int_GLXContext_Bool args;
} PACKED_GLXContext_Display_GLXFBConfig_int_GLXContext_Bool;
typedef GLXPbuffer (*FUNC_GLXPbuffer_Display_GLXFBConfig_int)(Display dpy, GLXFBConfig config, int attrib_list);
typedef struct {
    Display a1;
    GLXFBConfig a2;
    int a3;
} ARGS_GLXPbuffer_Display_GLXFBConfig_int;
typedef struct {
    int format;
    FUNC_GLXPbuffer_Display_GLXFBConfig_int func;
    ARGS_GLXPbuffer_Display_GLXFBConfig_int args;
} PACKED_GLXPbuffer_Display_GLXFBConfig_int;
typedef GLXPixmap (*FUNC_GLXPixmap_Display_GLXFBConfig_Pixmap_int)(Display dpy, GLXFBConfig config, Pixmap pixmap, int attrib_list);
typedef struct {
    Display a1;
    GLXFBConfig a2;
    Pixmap a3;
    int a4;
} ARGS_GLXPixmap_Display_GLXFBConfig_Pixmap_int;
typedef struct {
    int format;
    FUNC_GLXPixmap_Display_GLXFBConfig_Pixmap_int func;
    ARGS_GLXPixmap_Display_GLXFBConfig_Pixmap_int args;
} PACKED_GLXPixmap_Display_GLXFBConfig_Pixmap_int;
typedef GLXWindow (*FUNC_GLXWindow_Display_GLXFBConfig_Window_int)(Display dpy, GLXFBConfig config, Window win, int attrib_list);
typedef struct {
    Display a1;
    GLXFBConfig a2;
    Window a3;
    int a4;
} ARGS_GLXWindow_Display_GLXFBConfig_Window_int;
typedef struct {
    int format;
    FUNC_GLXWindow_Display_GLXFBConfig_Window_int func;
    ARGS_GLXWindow_Display_GLXFBConfig_Window_int args;
} PACKED_GLXWindow_Display_GLXFBConfig_Window_int;
typedef void (*FUNC_void_Display_Window_float)(Display dpy, Window window, float cushion);
typedef struct {
    Display a1;
    Window a2;
    float a3;
} ARGS_void_Display_Window_float;
typedef struct {
    int format;
    FUNC_void_Display_Window_float func;
    ARGS_void_Display_Window_float args;
} PACKED_void_Display_Window_float;
typedef void (*FUNC_void_Display_GLXPbufferSGIX)(Display dpy, GLXPbufferSGIX pbuf);
typedef struct {
    Display a1;
    GLXPbufferSGIX a2;
} ARGS_void_Display_GLXPbufferSGIX;
typedef struct {
    int format;
    FUNC_void_Display_GLXPbufferSGIX func;
    ARGS_void_Display_GLXPbufferSGIX args;
} PACKED_void_Display_GLXPbufferSGIX;
typedef void (*FUNC_void_Display_GLXVideoSourceSGIX)(Display dpy, GLXVideoSourceSGIX glxvideosource);
typedef struct {
    Display a1;
    GLXVideoSourceSGIX a2;
} ARGS_void_Display_GLXVideoSourceSGIX;
typedef struct {
    int format;
    FUNC_void_Display_GLXVideoSourceSGIX func;
    ARGS_void_Display_GLXVideoSourceSGIX args;
} PACKED_void_Display_GLXVideoSourceSGIX;
typedef void (*FUNC_void_Display_GLXPbuffer)(Display dpy, GLXPbuffer pbuf);
typedef struct {
    Display a1;
    GLXPbuffer a2;
} ARGS_void_Display_GLXPbuffer;
typedef struct {
    int format;
    FUNC_void_Display_GLXPbuffer func;
    ARGS_void_Display_GLXPbuffer args;
} PACKED_void_Display_GLXPbuffer;
typedef void (*FUNC_void_Display_GLXPixmap)(Display dpy, GLXPixmap pixmap);
typedef struct {
    Display a1;
    GLXPixmap a2;
} ARGS_void_Display_GLXPixmap;
typedef struct {
    int format;
    FUNC_void_Display_GLXPixmap func;
    ARGS_void_Display_GLXPixmap args;
} PACKED_void_Display_GLXPixmap;
typedef void (*FUNC_void_Display_GLXWindow)(Display dpy, GLXWindow win);
typedef struct {
    Display a1;
    GLXWindow a2;
} ARGS_void_Display_GLXWindow;
typedef struct {
    int format;
    FUNC_void_Display_GLXWindow func;
    ARGS_void_Display_GLXWindow args;
} PACKED_void_Display_GLXWindow;
typedef GLXVideoCaptureDeviceNVPointer (*FUNC_GLXVideoCaptureDeviceNVPointer_Display_int_int)(Display dpy, int screen, int nelements);
typedef struct {
    Display a1;
    int a2;
    int a3;
} ARGS_GLXVideoCaptureDeviceNVPointer_Display_int_int;
typedef struct {
    int format;
    FUNC_GLXVideoCaptureDeviceNVPointer_Display_int_int func;
    ARGS_GLXVideoCaptureDeviceNVPointer_Display_int_int args;
} PACKED_GLXVideoCaptureDeviceNVPointer_Display_int_int;
typedef uintPointer (*FUNC_uintPointer_Display_int_int)(Display dpy, int screen, int nelements);
typedef struct {
    Display a1;
    int a2;
    int a3;
} ARGS_uintPointer_Display_int_int;
typedef struct {
    int format;
    FUNC_uintPointer_Display_int_int func;
    ARGS_uintPointer_Display_int_int args;
} PACKED_uintPointer_Display_int_int;
typedef void (*FUNC_void_Display_GLXContext)(Display dpy, GLXContext context);
typedef struct {
    Display a1;
    GLXContext a2;
} ARGS_void_Display_GLXContext;
typedef struct {
    int format;
    FUNC_void_Display_GLXContext func;
    ARGS_void_Display_GLXContext args;
} PACKED_void_Display_GLXContext;
typedef uint (*FUNC_uint_void)(void pointer);
typedef struct {
    void a1;
} ARGS_uint_void;
typedef struct {
    int format;
    FUNC_uint_void func;
    ARGS_uint_void args;
} PACKED_uint_void;
typedef GLXContextID (*FUNC_GLXContextID_const_GLXContext)(const GLXContext context);
typedef struct {
    const GLXContext a1;
} ARGS_GLXContextID_const_GLXContext;
typedef struct {
    int format;
    FUNC_GLXContextID_const_GLXContext func;
    ARGS_GLXContextID_const_GLXContext args;
} PACKED_GLXContextID_const_GLXContext;
typedef DisplayPointer (*FUNC_DisplayPointer)();
typedef struct {
} ARGS_DisplayPointer;
typedef struct {
    int format;
    FUNC_DisplayPointer func;
    ARGS_DisplayPointer args;
} PACKED_DisplayPointer;
typedef GLXDrawable (*FUNC_GLXDrawable)();
typedef struct {
} ARGS_GLXDrawable;
typedef struct {
    int format;
    FUNC_GLXDrawable func;
    ARGS_GLXDrawable args;
} PACKED_GLXDrawable;
typedef int (*FUNC_int_Display_GLXFBConfig_int_int)(Display dpy, GLXFBConfig config, int attribute, int value);
typedef struct {
    Display a1;
    GLXFBConfig a2;
    int a3;
    int a4;
} ARGS_int_Display_GLXFBConfig_int_int;
typedef struct {
    int format;
    FUNC_int_Display_GLXFBConfig_int_int func;
    ARGS_int_Display_GLXFBConfig_int_int args;
} PACKED_int_Display_GLXFBConfig_int_int;
typedef int (*FUNC_int_Display_GLXFBConfigSGIX_int_int)(Display dpy, GLXFBConfigSGIX config, int attribute, int value);
typedef struct {
    Display a1;
    GLXFBConfigSGIX a2;
    int a3;
    int a4;
} ARGS_int_Display_GLXFBConfigSGIX_int_int;
typedef struct {
    int format;
    FUNC_int_Display_GLXFBConfigSGIX_int_int func;
    ARGS_int_Display_GLXFBConfigSGIX_int_int args;
} PACKED_int_Display_GLXFBConfigSGIX_int_int;
typedef GLXFBConfigSGIX (*FUNC_GLXFBConfigSGIX_Display_XVisualInfo)(Display dpy, XVisualInfo vis);
typedef struct {
    Display a1;
    XVisualInfo a2;
} ARGS_GLXFBConfigSGIX_Display_XVisualInfo;
typedef struct {
    int format;
    FUNC_GLXFBConfigSGIX_Display_XVisualInfo func;
    ARGS_GLXFBConfigSGIX_Display_XVisualInfo args;
} PACKED_GLXFBConfigSGIX_Display_XVisualInfo;
typedef GLXFBConfigPointer (*FUNC_GLXFBConfigPointer_Display_int_int)(Display dpy, int screen, int nelements);
typedef struct {
    Display a1;
    int a2;
    int a3;
} ARGS_GLXFBConfigPointer_Display_int_int;
typedef struct {
    int format;
    FUNC_GLXFBConfigPointer_Display_int_int func;
    ARGS_GLXFBConfigPointer_Display_int_int args;
} PACKED_GLXFBConfigPointer_Display_int_int;
typedef Bool (*FUNC_Bool_Display_GLXDrawable_int32_t_int32_t)(Display dpy, GLXDrawable drawable, int32_t numerator, int32_t denominator);
typedef struct {
    Display a1;
    GLXDrawable a2;
    int32_t a3;
    int32_t a4;
} ARGS_Bool_Display_GLXDrawable_int32_t_int32_t;
typedef struct {
    int format;
    FUNC_Bool_Display_GLXDrawable_int32_t_int32_t func;
    ARGS_Bool_Display_GLXDrawable_int32_t_int32_t args;
} PACKED_Bool_Display_GLXDrawable_int32_t_int32_t;
typedef FunctionPointer (*FUNC_FunctionPointer_GLubyte)(GLubyte procName);
typedef struct {
    GLubyte a1;
} ARGS_FunctionPointer_GLubyte;
typedef struct {
    int format;
    FUNC_FunctionPointer_GLubyte func;
    ARGS_FunctionPointer_GLubyte args;
} PACKED_FunctionPointer_GLubyte;
typedef void (*FUNC_void_Display_GLXDrawable_unsigned_long)(Display dpy, GLXDrawable draw, unsigned long event_mask);
typedef struct {
    Display a1;
    GLXDrawable a2;
    unsigned long a3;
} ARGS_void_Display_GLXDrawable_unsigned_long;
typedef struct {
    int format;
    FUNC_void_Display_GLXDrawable_unsigned_long func;
    ARGS_void_Display_GLXDrawable_unsigned_long args;
} PACKED_void_Display_GLXDrawable_unsigned_long;
typedef Bool (*FUNC_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t)(Display dpy, GLXDrawable drawable, int64_t ust, int64_t msc, int64_t sbc);
typedef struct {
    Display a1;
    GLXDrawable a2;
    int64_t a3;
    int64_t a4;
    int64_t a5;
} ARGS_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t;
typedef struct {
    int format;
    FUNC_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t func;
    ARGS_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t args;
} PACKED_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t;
typedef Status (*FUNC_Status_Display_Window_Window_long)(Display dpy, Window overlay, Window underlay, long pTransparentIndex);
typedef struct {
    Display a1;
    Window a2;
    Window a3;
    long a4;
} ARGS_Status_Display_Window_Window_long;
typedef struct {
    int format;
    FUNC_Status_Display_Window_Window_long func;
    ARGS_Status_Display_Window_Window_long args;
} PACKED_Status_Display_Window_Window_long;
typedef int (*FUNC_int_Display_int_int_GLXVideoDeviceNV)(Display dpy, int screen, int numVideoDevices, GLXVideoDeviceNV pVideoDevice);
typedef struct {
    Display a1;
    int a2;
    int a3;
    GLXVideoDeviceNV a4;
} ARGS_int_Display_int_int_GLXVideoDeviceNV;
typedef struct {
    int format;
    FUNC_int_Display_int_int_GLXVideoDeviceNV func;
    ARGS_int_Display_int_int_GLXVideoDeviceNV args;
} PACKED_int_Display_int_int_GLXVideoDeviceNV;
typedef int (*FUNC_int_Display_int_GLXVideoDeviceNV_unsigned_long_unsigned_long)(Display dpy, int screen, GLXVideoDeviceNV VideoDevice, unsigned long pulCounterOutputPbuffer, unsigned long pulCounterOutputVideo);
typedef struct {
    Display a1;
    int a2;
    GLXVideoDeviceNV a3;
    unsigned long a4;
    unsigned long a5;
} ARGS_int_Display_int_GLXVideoDeviceNV_unsigned_long_unsigned_long;
typedef struct {
    int format;
    FUNC_int_Display_int_GLXVideoDeviceNV_unsigned_long_unsigned_long func;
    ARGS_int_Display_int_GLXVideoDeviceNV_unsigned_long_unsigned_long args;
} PACKED_int_Display_int_GLXVideoDeviceNV_unsigned_long_unsigned_long;
typedef int (*FUNC_int_unsigned_int)(unsigned int count);
typedef struct {
    unsigned int a1;
} ARGS_int_unsigned_int;
typedef struct {
    int format;
    FUNC_int_unsigned_int func;
    ARGS_int_unsigned_int args;
} PACKED_int_unsigned_int;
typedef XVisualInfoPointer (*FUNC_XVisualInfoPointer_Display_GLXFBConfig)(Display dpy, GLXFBConfig config);
typedef struct {
    Display a1;
    GLXFBConfig a2;
} ARGS_XVisualInfoPointer_Display_GLXFBConfig;
typedef struct {
    int format;
    FUNC_XVisualInfoPointer_Display_GLXFBConfig func;
    ARGS_XVisualInfoPointer_Display_GLXFBConfig args;
} PACKED_XVisualInfoPointer_Display_GLXFBConfig;
typedef XVisualInfoPointer (*FUNC_XVisualInfoPointer_Display_GLXFBConfigSGIX)(Display dpy, GLXFBConfigSGIX config);
typedef struct {
    Display a1;
    GLXFBConfigSGIX a2;
} ARGS_XVisualInfoPointer_Display_GLXFBConfigSGIX;
typedef struct {
    int format;
    FUNC_XVisualInfoPointer_Display_GLXFBConfigSGIX func;
    ARGS_XVisualInfoPointer_Display_GLXFBConfigSGIX args;
} PACKED_XVisualInfoPointer_Display_GLXFBConfigSGIX;
typedef int (*FUNC_int_Display_int_int_int_void)(Display dpy, int timeSlice, int attrib, int size, void attribList);
typedef struct {
    Display a1;
    int a2;
    int a3;
    int a4;
    void a5;
} ARGS_int_Display_int_int_int_void;
typedef struct {
    int format;
    FUNC_int_Display_int_int_int_void func;
    ARGS_int_Display_int_int_int_void args;
} PACKED_int_Display_int_int_int_void;
typedef int (*FUNC_int_Display_int_int_GLXHyperpipeConfigSGIX_int)(Display dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX cfg, int hpId);
typedef struct {
    Display a1;
    int a2;
    int a3;
    GLXHyperpipeConfigSGIX a4;
    int a5;
} ARGS_int_Display_int_int_GLXHyperpipeConfigSGIX_int;
typedef struct {
    int format;
    FUNC_int_Display_int_int_GLXHyperpipeConfigSGIX_int func;
    ARGS_int_Display_int_int_GLXHyperpipeConfigSGIX_int args;
} PACKED_int_Display_int_int_GLXHyperpipeConfigSGIX_int;
typedef GLXContext (*FUNC_GLXContext_Display_GLXContextID)(Display dpy, GLXContextID contextID);
typedef struct {
    Display a1;
    GLXContextID a2;
} ARGS_GLXContext_Display_GLXContextID;
typedef struct {
    int format;
    FUNC_GLXContext_Display_GLXContextID func;
    ARGS_GLXContext_Display_GLXContextID args;
} PACKED_GLXContext_Display_GLXContextID;
typedef Bool (*FUNC_Bool_Display_GLXDrawable_GLuint)(Display dpy, GLXDrawable drawable, GLuint group);
typedef struct {
    Display a1;
    GLXDrawable a2;
    GLuint a3;
} ARGS_Bool_Display_GLXDrawable_GLuint;
typedef struct {
    int format;
    FUNC_Bool_Display_GLXDrawable_GLuint func;
    ARGS_Bool_Display_GLXDrawable_GLuint args;
} PACKED_Bool_Display_GLXDrawable_GLuint;
typedef void (*FUNC_void_Display_GLXDrawable_GLXDrawable)(Display dpy, GLXDrawable drawable, GLXDrawable member);
typedef struct {
    Display a1;
    GLXDrawable a2;
    GLXDrawable a3;
} ARGS_void_Display_GLXDrawable_GLXDrawable;
typedef struct {
    int format;
    FUNC_void_Display_GLXDrawable_GLXDrawable func;
    ARGS_void_Display_GLXDrawable_GLXDrawable args;
} PACKED_void_Display_GLXDrawable_GLXDrawable;
typedef void (*FUNC_void_Display_GLXVideoCaptureDeviceNV)(Display dpy, GLXVideoCaptureDeviceNV device);
typedef struct {
    Display a1;
    GLXVideoCaptureDeviceNV a2;
} ARGS_void_Display_GLXVideoCaptureDeviceNV;
typedef struct {
    int format;
    FUNC_void_Display_GLXVideoCaptureDeviceNV func;
    ARGS_void_Display_GLXVideoCaptureDeviceNV args;
} PACKED_void_Display_GLXVideoCaptureDeviceNV;
typedef Bool (*FUNC_Bool_Display_GLXDrawable_GLXDrawable_GLXContext)(Display dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
typedef struct {
    Display a1;
    GLXDrawable a2;
    GLXDrawable a3;
    GLXContext a4;
} ARGS_Bool_Display_GLXDrawable_GLXDrawable_GLXContext;
typedef struct {
    int format;
    FUNC_Bool_Display_GLXDrawable_GLXDrawable_GLXContext func;
    ARGS_Bool_Display_GLXDrawable_GLXDrawable_GLXContext args;
} PACKED_Bool_Display_GLXDrawable_GLXDrawable_GLXContext;
typedef int (*FUNC_int_Display_GLXContext_int_int)(Display dpy, GLXContext ctx, int attribute, int value);
typedef struct {
    Display a1;
    GLXContext a2;
    int a3;
    int a4;
} ARGS_int_Display_GLXContext_int_int;
typedef struct {
    int format;
    FUNC_int_Display_GLXContext_int_int func;
    ARGS_int_Display_GLXContext_int_int args;
} PACKED_int_Display_GLXContext_int_int;
typedef void (*FUNC_void_Display_GLXDrawable_int_unsigned_int)(Display dpy, GLXDrawable draw, int attribute, unsigned int value);
typedef struct {
    Display a1;
    GLXDrawable a2;
    int a3;
    unsigned int a4;
} ARGS_void_Display_GLXDrawable_int_unsigned_int;
typedef struct {
    int format;
    FUNC_void_Display_GLXDrawable_int_unsigned_int func;
    ARGS_void_Display_GLXDrawable_int_unsigned_int args;
} PACKED_void_Display_GLXDrawable_int_unsigned_int;
typedef Bool (*FUNC_Bool_Display_int_GLuint)(Display dpy, int screen, GLuint count);
typedef struct {
    Display a1;
    int a2;
    GLuint a3;
} ARGS_Bool_Display_int_GLuint;
typedef struct {
    int format;
    FUNC_Bool_Display_int_GLuint func;
    ARGS_Bool_Display_int_GLuint args;
} PACKED_Bool_Display_int_GLuint;
typedef int (*FUNC_int_Display_GLXPbufferSGIX_int_unsigned_int)(Display dpy, GLXPbufferSGIX pbuf, int attribute, unsigned int value);
typedef struct {
    Display a1;
    GLXPbufferSGIX a2;
    int a3;
    unsigned int a4;
} ARGS_int_Display_GLXPbufferSGIX_int_unsigned_int;
typedef struct {
    int format;
    FUNC_int_Display_GLXPbufferSGIX_int_unsigned_int func;
    ARGS_int_Display_GLXPbufferSGIX_int_unsigned_int args;
} PACKED_int_Display_GLXPbufferSGIX_int_unsigned_int;
typedef int (*FUNC_int_Display_int_int_int_void_void)(Display dpy, int timeSlice, int attrib, int size, void attribList, void returnAttribList);
typedef struct {
    Display a1;
    int a2;
    int a3;
    int a4;
    void a5;
    void a6;
} ARGS_int_Display_int_int_int_void_void;
typedef struct {
    int format;
    FUNC_int_Display_int_int_int_void_void func;
    ARGS_int_Display_int_int_int_void_void args;
} PACKED_int_Display_int_int_int_void_void;
typedef GLXHyperpipeConfigSGIXPointer (*FUNC_GLXHyperpipeConfigSGIXPointer_Display_int_int)(Display dpy, int hpId, int npipes);
typedef struct {
    Display a1;
    int a2;
    int a3;
} ARGS_GLXHyperpipeConfigSGIXPointer_Display_int_int;
typedef struct {
    int format;
    FUNC_GLXHyperpipeConfigSGIXPointer_Display_int_int func;
    ARGS_GLXHyperpipeConfigSGIXPointer_Display_int_int args;
} PACKED_GLXHyperpipeConfigSGIXPointer_Display_int_int;
typedef GLXHyperpipeNetworkSGIXPointer (*FUNC_GLXHyperpipeNetworkSGIXPointer_Display_int)(Display dpy, int npipes);
typedef struct {
    Display a1;
    int a2;
} ARGS_GLXHyperpipeNetworkSGIXPointer_Display_int;
typedef struct {
    int format;
    FUNC_GLXHyperpipeNetworkSGIXPointer_Display_int func;
    ARGS_GLXHyperpipeNetworkSGIXPointer_Display_int args;
} PACKED_GLXHyperpipeNetworkSGIXPointer_Display_int;
typedef Bool (*FUNC_Bool_Display_int_int)(Display dpy, int screen, int max);
typedef struct {
    Display a1;
    int a2;
    int a3;
} ARGS_Bool_Display_int_int;
typedef struct {
    int format;
    FUNC_Bool_Display_int_int func;
    ARGS_Bool_Display_int_int args;
} PACKED_Bool_Display_int_int;
typedef Bool (*FUNC_Bool_Display_int_GLuint_GLuint)(Display dpy, int screen, GLuint maxGroups, GLuint maxBarriers);
typedef struct {
    Display a1;
    int a2;
    GLuint a3;
    GLuint a4;
} ARGS_Bool_Display_int_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_Bool_Display_int_GLuint_GLuint func;
    ARGS_Bool_Display_int_GLuint_GLuint args;
} PACKED_Bool_Display_int_GLuint_GLuint;
typedef Bool (*FUNC_Bool_Display_GLXDrawable_GLuint_GLuint)(Display dpy, GLXDrawable drawable, GLuint group, GLuint barrier);
typedef struct {
    Display a1;
    GLXDrawable a2;
    GLuint a3;
    GLuint a4;
} ARGS_Bool_Display_GLXDrawable_GLuint_GLuint;
typedef struct {
    int format;
    FUNC_Bool_Display_GLXDrawable_GLuint_GLuint func;
    ARGS_Bool_Display_GLXDrawable_GLuint_GLuint args;
} PACKED_Bool_Display_GLXDrawable_GLuint_GLuint;
typedef int (*FUNC_int_Display_GLXVideoCaptureDeviceNV_int_int)(Display dpy, GLXVideoCaptureDeviceNV device, int attribute, int value);
typedef struct {
    Display a1;
    GLXVideoCaptureDeviceNV a2;
    int a3;
    int a4;
} ARGS_int_Display_GLXVideoCaptureDeviceNV_int_int;
typedef struct {
    int format;
    FUNC_int_Display_GLXVideoCaptureDeviceNV_int_int func;
    ARGS_int_Display_GLXVideoCaptureDeviceNV_int_int args;
} PACKED_int_Display_GLXVideoCaptureDeviceNV_int_int;
typedef Bool (*FUNC_Bool_Display_GLXDrawable)(Display dpy, GLXDrawable drawable);
typedef struct {
    Display a1;
    GLXDrawable a2;
} ARGS_Bool_Display_GLXDrawable;
typedef struct {
    int format;
    FUNC_Bool_Display_GLXDrawable func;
    ARGS_Bool_Display_GLXDrawable args;
} PACKED_Bool_Display_GLXDrawable;
typedef int (*FUNC_int_Display_int_GLXVideoDeviceNV)(Display dpy, int screen, GLXVideoDeviceNV VideoDevice);
typedef struct {
    Display a1;
    int a2;
    GLXVideoDeviceNV a3;
} ARGS_int_Display_int_GLXVideoDeviceNV;
typedef struct {
    int format;
    FUNC_int_Display_int_GLXVideoDeviceNV func;
    ARGS_int_Display_int_GLXVideoDeviceNV args;
} PACKED_int_Display_int_GLXVideoDeviceNV;
typedef int (*FUNC_int_Display_GLXPbuffer)(Display dpy, GLXPbuffer pbuf);
typedef struct {
    Display a1;
    GLXPbuffer a2;
} ARGS_int_Display_GLXPbuffer;
typedef struct {
    int format;
    FUNC_int_Display_GLXPbuffer func;
    ARGS_int_Display_GLXPbuffer args;
} PACKED_int_Display_GLXPbuffer;
typedef Bool (*FUNC_Bool_Display_int)(Display dpy, int screen);
typedef struct {
    Display a1;
    int a2;
} ARGS_Bool_Display_int;
typedef struct {
    int format;
    FUNC_Bool_Display_int func;
    ARGS_Bool_Display_int args;
} PACKED_Bool_Display_int;
typedef int (*FUNC_int_Display_GLXPbuffer_int_unsigned_long_GLboolean)(Display dpy, GLXPbuffer pbuf, int iBufferType, unsigned long pulCounterPbuffer, GLboolean bBlock);
typedef struct {
    Display a1;
    GLXPbuffer a2;
    int a3;
    unsigned long a4;
    GLboolean a5;
} ARGS_int_Display_GLXPbuffer_int_unsigned_long_GLboolean;
typedef struct {
    int format;
    FUNC_int_Display_GLXPbuffer_int_unsigned_long_GLboolean func;
    ARGS_int_Display_GLXPbuffer_int_unsigned_long_GLboolean args;
} PACKED_int_Display_GLXPbuffer_int_unsigned_long_GLboolean;
typedef Bool (*FUNC_Bool_int)(int mode);
typedef struct {
    int a1;
} ARGS_Bool_int;
typedef struct {
    int format;
    FUNC_Bool_int func;
    ARGS_Bool_int args;
} PACKED_Bool_int;
typedef int64_t (*FUNC_int64_t_Display_GLXDrawable_int64_t_int64_t_int64_t)(Display dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder);
typedef struct {
    Display a1;
    GLXDrawable a2;
    int64_t a3;
    int64_t a4;
    int64_t a5;
} ARGS_int64_t_Display_GLXDrawable_int64_t_int64_t_int64_t;
typedef struct {
    int format;
    FUNC_int64_t_Display_GLXDrawable_int64_t_int64_t_int64_t func;
    ARGS_int64_t_Display_GLXDrawable_int64_t_int64_t_int64_t args;
} PACKED_int64_t_Display_GLXDrawable_int64_t_int64_t_int64_t;
typedef int (*FUNC_int_int)(int interval);
typedef struct {
    int a1;
} ARGS_int_int;
typedef struct {
    int format;
    FUNC_int_int func;
    ARGS_int_int args;
} PACKED_int_int;
typedef Bool (*FUNC_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t_int64_t_int64_t_int64_t)(Display dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder, int64_t ust, int64_t msc, int64_t sbc);
typedef struct {
    Display a1;
    GLXDrawable a2;
    int64_t a3;
    int64_t a4;
    int64_t a5;
    int64_t a6;
    int64_t a7;
    int64_t a8;
} ARGS_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t_int64_t_int64_t_int64_t;
typedef struct {
    int format;
    FUNC_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t_int64_t_int64_t_int64_t func;
    ARGS_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t_int64_t_int64_t_int64_t args;
} PACKED_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t_int64_t_int64_t_int64_t;
typedef Bool (*FUNC_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t_int64_t)(Display dpy, GLXDrawable drawable, int64_t target_sbc, int64_t ust, int64_t msc, int64_t sbc);
typedef struct {
    Display a1;
    GLXDrawable a2;
    int64_t a3;
    int64_t a4;
    int64_t a5;
    int64_t a6;
} ARGS_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t_int64_t;
typedef struct {
    int format;
    FUNC_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t_int64_t func;
    ARGS_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t_int64_t args;
} PACKED_Bool_Display_GLXDrawable_int64_t_int64_t_int64_t_int64_t;
typedef int (*FUNC_int_int_int_unsigned_int)(int divisor, int remainder, unsigned int count);
typedef struct {
    int a1;
    int a2;
    unsigned int a3;
} ARGS_int_int_int_unsigned_int;
typedef struct {
    int format;
    FUNC_int_int_int_unsigned_int func;
    ARGS_int_int_int_unsigned_int args;
} PACKED_int_int_int_unsigned_int;

void glPackedCall(const UnknownCall *packed);
void glAccum(GLenum op, GLfloat value);
void glAccumxOES(GLenum op, GLfixed value);
void glActiveProgramEXT(GLuint program);
void glActiveShaderProgram(GLuint pipeline, GLuint program);
void glActiveStencilFaceEXT(GLenum face);
void glActiveTexture(GLenum texture);
void glActiveTextureARB(GLenum texture);
void glActiveVaryingNV(GLuint program, GLchar name);
void glAlphaFragmentOp1ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
void glAlphaFragmentOp2ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
void glAlphaFragmentOp3ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
void glAlphaFunc(GLenum func, GLfloat ref);
void glAlphaFuncxOES(GLenum func, GLfixed ref);
void glApplyTextureEXT(GLenum mode);
Boolean glAreProgramsResidentNV(GLsizei n, GLuint programs, GLboolean residences);
Boolean glAreTexturesResident(GLsizei n, GLuint textures, GLboolean residences);
Boolean glAreTexturesResidentEXT(GLsizei n, GLuint textures, GLboolean residences);
void glArrayElement(GLint i);
void glArrayElementEXT(GLint i);
void glArrayObjectATI(GLenum array, GLint size, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
void glAsyncMarkerSGIX(GLuint marker);
void glAttachObjectARB(GLhandleARB containerObj, GLhandleARB obj);
void glAttachShader(GLuint program, GLuint shader);
void glBegin(GLenum mode);
void glBeginConditionalRender(GLuint id, GLenum mode);
void glBeginConditionalRenderNV(GLuint id, GLenum mode);
void glBeginConditionalRenderNVX(GLuint id);
void glBeginFragmentShaderATI();
void glBeginOcclusionQueryNV(GLuint id);
void glBeginPerfMonitorAMD(GLuint monitor);
void glBeginQuery(GLenum target, GLuint id);
void glBeginQueryARB(GLenum target, GLuint id);
void glBeginQueryIndexed(GLenum target, GLuint index, GLuint id);
void glBeginTransformFeedback(GLenum primitiveMode);
void glBeginTransformFeedbackEXT(GLenum primitiveMode);
void glBeginTransformFeedbackNV(GLenum primitiveMode);
void glBeginVertexShaderEXT();
void glBeginVideoCaptureNV(GLuint video_capture_slot);
void glBindAttribLocation(GLuint program, GLuint index, GLchar name);
void glBindAttribLocationARB(GLhandleARB programObj, GLuint index, GLcharARB name);
void glBindBuffer(GLenum target, GLuint buffer);
void glBindBufferARB(GLenum target, GLuint buffer);
void glBindBufferBase(GLenum target, GLuint index, GLuint buffer);
void glBindBufferBaseEXT(GLenum target, GLuint index, GLuint buffer);
void glBindBufferBaseNV(GLenum target, GLuint index, GLuint buffer);
void glBindBufferOffsetEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset);
void glBindBufferOffsetNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset);
void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
void glBindBufferRangeEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
void glBindBufferRangeNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
void glBindFragDataLocation(GLuint program, GLuint color, GLchar name);
void glBindFragDataLocationEXT(GLuint program, GLuint color, GLchar name);
void glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, GLchar name);
void glBindFragmentShaderATI(GLuint id);
void glBindFramebuffer(GLenum target, GLuint framebuffer);
void glBindFramebufferEXT(GLenum target, GLuint framebuffer);
void glBindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
void glBindImageTextureEXT(GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format);
UInt32 glBindLightParameterEXT(GLenum light, GLenum value);
UInt32 glBindMaterialParameterEXT(GLenum face, GLenum value);
void glBindMultiTextureEXT(GLenum texunit, GLenum target, GLuint texture);
UInt32 glBindParameterEXT(GLenum value);
void glBindProgramARB(GLenum target, GLuint program);
void glBindProgramNV(GLenum target, GLuint id);
void glBindProgramPipeline(GLuint pipeline);
void glBindRenderbuffer(GLenum target, GLuint renderbuffer);
void glBindRenderbufferEXT(GLenum target, GLuint renderbuffer);
void glBindSampler(GLuint unit, GLuint sampler);
UInt32 glBindTexGenParameterEXT(GLenum unit, GLenum coord, GLenum value);
void glBindTexture(GLenum target, GLuint texture);
void glBindTextureEXT(GLenum target, GLuint texture);
UInt32 glBindTextureUnitParameterEXT(GLenum unit, GLenum value);
void glBindTransformFeedback(GLenum target, GLuint id);
void glBindTransformFeedbackNV(GLenum target, GLuint id);
void glBindVertexArray(GLuint array);
void glBindVertexArrayAPPLE(GLuint array);
void glBindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
void glBindVertexShaderEXT(GLuint id);
void glBindVideoCaptureStreamBufferNV(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLintptrARB offset);
void glBindVideoCaptureStreamTextureNV(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLenum target, GLuint texture);
void glBinormal3bEXT(GLbyte bx, GLbyte by, GLbyte bz);
void glBinormal3bvEXT(GLbyte v);
void glBinormal3dEXT(GLdouble bx, GLdouble by, GLdouble bz);
void glBinormal3dvEXT(GLdouble v);
void glBinormal3fEXT(GLfloat bx, GLfloat by, GLfloat bz);
void glBinormal3fvEXT(GLfloat v);
void glBinormal3iEXT(GLint bx, GLint by, GLint bz);
void glBinormal3ivEXT(GLint v);
void glBinormal3sEXT(GLshort bx, GLshort by, GLshort bz);
void glBinormal3svEXT(GLshort v);
void glBinormalPointerEXT(GLenum type, GLsizei stride, GLvoid pointer);
void glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, GLubyte bitmap);
void glBitmapxOES(GLsizei width, GLsizei height, GLfixed xorig, GLfixed yorig, GLfixed xmove, GLfixed ymove, GLubyte bitmap);
void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glBlendColorEXT(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glBlendColorxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
void glBlendEquation(GLenum mode);
void glBlendEquationEXT(GLenum mode);
void glBlendEquationIndexedAMD(GLuint buf, GLenum mode);
void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha);
void glBlendEquationSeparateEXT(GLenum modeRGB, GLenum modeAlpha);
void glBlendEquationSeparateIndexedAMD(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
void glBlendEquationSeparateiARB(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
void glBlendEquationi(GLuint buf, GLenum mode);
void glBlendEquationiARB(GLuint buf, GLenum mode);
void glBlendFunc(GLenum sfactor, GLenum dfactor);
void glBlendFuncIndexedAMD(GLuint buf, GLenum src, GLenum dst);
void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
void glBlendFuncSeparateEXT(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
void glBlendFuncSeparateINGR(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
void glBlendFuncSeparateIndexedAMD(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
void glBlendFuncSeparateiARB(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
void glBlendFunci(GLuint buf, GLenum src, GLenum dst);
void glBlendFunciARB(GLuint buf, GLenum src, GLenum dst);
void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
void glBlitFramebufferEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
void glBufferAddressRangeNV(GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length);
void glBufferData(GLenum target, GLsizeiptr size, GLvoid data, GLenum usage);
void glBufferDataARB(GLenum target, GLsizeiptrARB size, GLvoid data, GLenum usage);
void glBufferParameteriAPPLE(GLenum target, GLenum pname, GLint param);
void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid data);
void glBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid data);
void glCallList(GLuint list);
void glCallLists(GLsizei n, GLenum type, GLvoid lists);
GLenum glCheckFramebufferStatus(GLenum target);
GLenum glCheckFramebufferStatusEXT(GLenum target);
FramebufferStatus glCheckNamedFramebufferStatusEXT(GLuint framebuffer, GLenum target);
void glClampColor(GLenum target, GLenum clamp);
void glClampColorARB(GLenum target, GLenum clamp);
void glClear(GLbitfield mask);
void glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glClearAccumxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
void glClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, void * data);
void glClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, void * data);
void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
void glClearBufferfv(GLenum buffer, GLint drawbuffer, GLfloat value);
void glClearBufferiv(GLenum buffer, GLint drawbuffer, GLint value);
void glClearBufferuiv(GLenum buffer, GLint drawbuffer, GLuint value);
void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glClearColorIiEXT(GLint red, GLint green, GLint blue, GLint alpha);
void glClearColorIuiEXT(GLuint red, GLuint green, GLuint blue, GLuint alpha);
void glClearColorxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
void glClearDepth(GLdouble depth);
void glClearDepthdNV(GLdouble depth);
void glClearDepthf(GLfloat d);
void glClearDepthfOES(GLclampf depth);
void glClearDepthxOES(GLfixed depth);
void glClearIndex(GLfloat c);
void glClearNamedBufferDataEXT(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, void * data);
void glClearNamedBufferSubDataEXT(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, GLsizeiptr offset, GLsizeiptr size, void * data);
void glClearStencil(GLint s);
void glClientActiveTexture(GLenum texture);
void glClientActiveTextureARB(GLenum texture);
void glClientActiveVertexStreamATI(GLenum stream);
void glClientAttribDefaultEXT(GLbitfield mask);
GLenum glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
void glClipPlane(GLenum plane, GLdouble equation);
void glClipPlanefOES(GLenum plane, GLfloat equation);
void glClipPlanexOES(GLenum plane, GLfixed equation);
void glColor3b(GLbyte red, GLbyte green, GLbyte blue);
void glColor3bv(GLbyte v);
void glColor3d(GLdouble red, GLdouble green, GLdouble blue);
void glColor3dv(GLdouble v);
void glColor3f(GLfloat red, GLfloat green, GLfloat blue);
void glColor3fVertex3fSUN(GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
void glColor3fVertex3fvSUN(GLfloat c, GLfloat v);
void glColor3fv(GLfloat v);
void glColor3hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue);
void glColor3hvNV(GLhalfNV v);
void glColor3i(GLint red, GLint green, GLint blue);
void glColor3iv(GLint v);
void glColor3s(GLshort red, GLshort green, GLshort blue);
void glColor3sv(GLshort v);
void glColor3ub(GLubyte red, GLubyte green, GLubyte blue);
void glColor3ubv(GLubyte v);
void glColor3ui(GLuint red, GLuint green, GLuint blue);
void glColor3uiv(GLuint v);
void glColor3us(GLushort red, GLushort green, GLushort blue);
void glColor3usv(GLushort v);
void glColor3xOES(GLfixed red, GLfixed green, GLfixed blue);
void glColor3xvOES(GLfixed components);
void glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
void glColor4bv(GLbyte v);
void glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
void glColor4dv(GLdouble v);
void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glColor4fNormal3fVertex3fSUN(GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
void glColor4fNormal3fVertex3fvSUN(GLfloat c, GLfloat n, GLfloat v);
void glColor4fv(GLfloat v);
void glColor4hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue, GLhalfNV alpha);
void glColor4hvNV(GLhalfNV v);
void glColor4i(GLint red, GLint green, GLint blue, GLint alpha);
void glColor4iv(GLint v);
void glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha);
void glColor4sv(GLshort v);
void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
void glColor4ubVertex2fSUN(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y);
void glColor4ubVertex2fvSUN(GLubyte c, GLfloat v);
void glColor4ubVertex3fSUN(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
void glColor4ubVertex3fvSUN(GLubyte c, GLfloat v);
void glColor4ubv(GLubyte v);
void glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha);
void glColor4uiv(GLuint v);
void glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha);
void glColor4usv(GLushort v);
void glColor4xOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
void glColor4xvOES(GLfixed components);
void glColorFormatNV(GLint size, GLenum type, GLsizei stride);
void glColorFragmentOp1ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
void glColorFragmentOp2ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
void glColorFragmentOp3ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
void glColorMaskIndexedEXT(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
void glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
void glColorMaterial(GLenum face, GLenum mode);
void glColorP3ui(GLenum type, GLuint color);
void glColorP3uiv(GLenum type, GLuint color);
void glColorP4ui(GLenum type, GLuint color);
void glColorP4uiv(GLenum type, GLuint color);
void glColorPointer(GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void glColorPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, GLvoid pointer);
void glColorPointerListIBM(GLint size, GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride);
void glColorPointervINTEL(GLint size, GLenum type, GLvoid * pointer);
void glColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, GLvoid data);
void glColorSubTableEXT(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, GLvoid data);
void glColorTable(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, GLvoid table);
void glColorTableEXT(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, GLvoid table);
void glColorTableParameterfv(GLenum target, GLenum pname, GLfloat params);
void glColorTableParameterfvSGI(GLenum target, GLenum pname, GLfloat params);
void glColorTableParameteriv(GLenum target, GLenum pname, GLint params);
void glColorTableParameterivSGI(GLenum target, GLenum pname, GLint params);
void glColorTableSGI(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, GLvoid table);
void glCombinerInputNV(GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
void glCombinerOutputNV(GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum);
void glCombinerParameterfNV(GLenum pname, GLfloat param);
void glCombinerParameterfvNV(GLenum pname, GLfloat params);
void glCombinerParameteriNV(GLenum pname, GLint param);
void glCombinerParameterivNV(GLenum pname, GLint params);
void glCombinerStageParameterfvNV(GLenum stage, GLenum pname, GLfloat params);
void glCompileShader(GLuint shader);
void glCompileShaderARB(GLhandleARB shaderObj);
void glCompileShaderIncludeARB(GLuint shader, GLsizei count, GLchar * path, GLint length);
void glCompressedMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid bits);
void glCompressedMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid bits);
void glCompressedMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid bits);
void glCompressedMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid bits);
void glCompressedMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid bits);
void glCompressedMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid bits);
void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid data);
void glCompressedTexImage1DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid data);
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid data);
void glCompressedTexImage2DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid data);
void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid data);
void glCompressedTexImage3DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid data);
void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid data);
void glCompressedTexSubImage1DARB(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid data);
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid data);
void glCompressedTexSubImage2DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid data);
void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid data);
void glCompressedTexSubImage3DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid data);
void glCompressedTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid bits);
void glCompressedTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid bits);
void glCompressedTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid bits);
void glCompressedTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid bits);
void glCompressedTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid bits);
void glCompressedTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid bits);
void glConvolutionFilter1D(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, GLvoid image);
void glConvolutionFilter1DEXT(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, GLvoid image);
void glConvolutionFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid image);
void glConvolutionFilter2DEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid image);
void glConvolutionParameterf(GLenum target, GLenum pname, GLfloat params);
void glConvolutionParameterfEXT(GLenum target, GLenum pname, GLfloat params);
void glConvolutionParameterfv(GLenum target, GLenum pname, GLfloat params);
void glConvolutionParameterfvEXT(GLenum target, GLenum pname, GLfloat params);
void glConvolutionParameteri(GLenum target, GLenum pname, GLint params);
void glConvolutionParameteriEXT(GLenum target, GLenum pname, GLint params);
void glConvolutionParameteriv(GLenum target, GLenum pname, GLint params);
void glConvolutionParameterivEXT(GLenum target, GLenum pname, GLint params);
void glConvolutionParameterxOES(GLenum target, GLenum pname, GLfixed param);
void glConvolutionParameterxvOES(GLenum target, GLenum pname, GLfixed params);
void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
void glCopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
void glCopyColorSubTableEXT(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
void glCopyColorTable(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
void glCopyColorTableSGI(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
void glCopyConvolutionFilter1D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
void glCopyConvolutionFilter1DEXT(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
void glCopyConvolutionFilter2D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
void glCopyConvolutionFilter2DEXT(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
void glCopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
void glCopyImageSubDataNV(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
void glCopyMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
void glCopyMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void glCopyMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void glCopyMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glCopyMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glCopyPathNV(GLuint resultPath, GLuint srcPath);
void glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
void glCopyTexImage1DEXT(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void glCopyTexImage2DEXT(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void glCopyTexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glCopyTexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glCopyTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glCopyTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
void glCopyTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void glCopyTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void glCopyTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glCopyTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glCoverFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLenum coverMode, GLenum transformType, GLfloat transformValues);
void glCoverFillPathNV(GLuint path, GLenum coverMode);
void glCoverStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLenum coverMode, GLenum transformType, GLfloat transformValues);
void glCoverStrokePathNV(GLuint path, GLenum coverMode);
UInt32 glCreateProgram();
handleARB glCreateProgramObjectARB();
UInt32 glCreateShader(GLenum type);
handleARB glCreateShaderObjectARB(GLenum shaderType);
UInt32 glCreateShaderProgramEXT(GLenum type, GLchar string);
UInt32 glCreateShaderProgramv(GLenum type, GLsizei count, GLchar*const strings);
sync glCreateSyncFromCLeventARB(struct _cl_context * context, struct _cl_event * event, GLbitfield flags);
void glCullFace(GLenum mode);
void glCullParameterdvEXT(GLenum pname, GLdouble params);
void glCullParameterfvEXT(GLenum pname, GLfloat params);
void glCurrentPaletteMatrixARB(GLint index);
void glDebugMessageCallback(GLDEBUGPROC callback, void * userParam);
void glDebugMessageCallbackAMD(GLDEBUGPROCAMD callback, GLvoid userParam);
void glDebugMessageCallbackARB(GLDEBUGPROCARB callback, GLvoid userParam);
void glDebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, GLuint ids, GLboolean enabled);
void glDebugMessageControlARB(GLenum source, GLenum type, GLenum severity, GLsizei count, GLuint ids, GLboolean enabled);
void glDebugMessageEnableAMD(GLenum category, GLenum severity, GLsizei count, GLuint ids, GLboolean enabled);
void glDebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, GLchar buf);
void glDebugMessageInsertAMD(GLenum category, GLenum severity, GLuint id, GLsizei length, GLchar buf);
void glDebugMessageInsertARB(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, GLchar buf);
void glDeformSGIX(GLbitfield mask);
void glDeformationMap3dSGIX(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble w1, GLdouble w2, GLint wstride, GLint worder, GLdouble points);
void glDeformationMap3fSGIX(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat w1, GLfloat w2, GLint wstride, GLint worder, GLfloat points);
void glDeleteAsyncMarkersSGIX(GLuint marker, GLsizei range);
void glDeleteBuffers(GLsizei n, GLuint buffers);
void glDeleteBuffersARB(GLsizei n, GLuint buffers);
void glDeleteFencesAPPLE(GLsizei n, GLuint fences);
void glDeleteFencesNV(GLsizei n, GLuint fences);
void glDeleteFragmentShaderATI(GLuint id);
void glDeleteFramebuffers(GLsizei n, GLuint framebuffers);
void glDeleteFramebuffersEXT(GLsizei n, GLuint framebuffers);
void glDeleteLists(GLuint list, GLsizei range);
void glDeleteNamedStringARB(GLint namelen, GLchar name);
void glDeleteNamesAMD(GLenum identifier, GLuint num, GLuint names);
void glDeleteObjectARB(GLhandleARB obj);
void glDeleteOcclusionQueriesNV(GLsizei n, GLuint ids);
void glDeletePathsNV(GLuint path, GLsizei range);
void glDeletePerfMonitorsAMD(GLsizei n, GLuint monitors);
void glDeleteProgram(GLuint program);
void glDeleteProgramPipelines(GLsizei n, GLuint pipelines);
void glDeleteProgramsARB(GLsizei n, GLuint programs);
void glDeleteProgramsNV(GLsizei n, GLuint programs);
void glDeleteQueries(GLsizei n, GLuint ids);
void glDeleteQueriesARB(GLsizei n, GLuint ids);
void glDeleteRenderbuffers(GLsizei n, GLuint renderbuffers);
void glDeleteRenderbuffersEXT(GLsizei n, GLuint renderbuffers);
void glDeleteSamplers(GLsizei count, GLuint samplers);
void glDeleteShader(GLuint shader);
void glDeleteSync(GLsync sync);
void glDeleteTextures(GLsizei n, GLuint textures);
void glDeleteTexturesEXT(GLsizei n, GLuint textures);
void glDeleteTransformFeedbacks(GLsizei n, GLuint ids);
void glDeleteTransformFeedbacksNV(GLsizei n, GLuint ids);
void glDeleteVertexArrays(GLsizei n, GLuint arrays);
void glDeleteVertexArraysAPPLE(GLsizei n, GLuint arrays);
void glDeleteVertexShaderEXT(GLuint id);
void glDepthBoundsEXT(GLclampd zmin, GLclampd zmax);
void glDepthBoundsdNV(GLdouble zmin, GLdouble zmax);
void glDepthFunc(GLenum func);
void glDepthMask(GLboolean flag);
void glDepthRange(GLdouble near, GLdouble far);
void glDepthRangeArrayv(GLuint first, GLsizei count, GLdouble v);
void glDepthRangeIndexed(GLuint index, GLdouble n, GLdouble f);
void glDepthRangedNV(GLdouble zNear, GLdouble zFar);
void glDepthRangef(GLfloat n, GLfloat f);
void glDepthRangefOES(GLclampf n, GLclampf f);
void glDepthRangexOES(GLfixed n, GLfixed f);
void glDetachObjectARB(GLhandleARB containerObj, GLhandleARB attachedObj);
void glDetachShader(GLuint program, GLuint shader);
void glDetailTexFuncSGIS(GLenum target, GLsizei n, GLfloat points);
void glDisable(GLenum cap);
void glDisableClientState(GLenum array);
void glDisableClientStateIndexedEXT(GLenum array, GLuint index);
void glDisableClientStateiEXT(GLenum array, GLuint index);
void glDisableIndexedEXT(GLenum target, GLuint index);
void glDisableVariantClientStateEXT(GLuint id);
void glDisableVertexArrayAttribEXT(GLuint vaobj, GLuint index);
void glDisableVertexArrayEXT(GLuint vaobj, GLenum array);
void glDisableVertexAttribAPPLE(GLuint index, GLenum pname);
void glDisableVertexAttribArray(GLuint index);
void glDisableVertexAttribArrayARB(GLuint index);
void glDisablei(GLenum target, GLuint index);
void glDispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
void glDispatchComputeIndirect(GLintptr indirect);
void glDrawArrays(GLenum mode, GLint first, GLsizei count);
void glDrawArraysEXT(GLenum mode, GLint first, GLsizei count);
void glDrawArraysIndirect(GLenum mode, GLvoid indirect);
void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
void glDrawArraysInstancedARB(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
void glDrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
void glDrawArraysInstancedEXT(GLenum mode, GLint start, GLsizei count, GLsizei primcount);
void glDrawBuffer(GLenum mode);
void glDrawBuffers(GLsizei n, GLenum bufs);
void glDrawBuffersARB(GLsizei n, GLenum bufs);
void glDrawBuffersATI(GLsizei n, GLenum bufs);
void glDrawElementArrayAPPLE(GLenum mode, GLint first, GLsizei count);
void glDrawElementArrayATI(GLenum mode, GLsizei count);
void glDrawElements(GLenum mode, GLsizei count, GLenum type, GLvoid indices);
void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid indices, GLint basevertex);
void glDrawElementsIndirect(GLenum mode, GLenum type, GLvoid indirect);
void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, GLvoid indices, GLsizei instancecount);
void glDrawElementsInstancedARB(GLenum mode, GLsizei count, GLenum type, GLvoid indices, GLsizei primcount);
void glDrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, void * indices, GLsizei instancecount, GLuint baseinstance);
void glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid indices, GLsizei instancecount, GLint basevertex);
void glDrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
void glDrawElementsInstancedEXT(GLenum mode, GLsizei count, GLenum type, GLvoid indices, GLsizei primcount);
void glDrawMeshArraysSUN(GLenum mode, GLint first, GLsizei count, GLsizei width);
void glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels);
void glDrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count);
void glDrawRangeElementArrayATI(GLenum mode, GLuint start, GLuint end, GLsizei count);
void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid indices);
void glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid indices, GLint basevertex);
void glDrawRangeElementsEXT(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid indices);
void glDrawTextureNV(GLuint texture, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1);
void glDrawTransformFeedback(GLenum mode, GLuint id);
void glDrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount);
void glDrawTransformFeedbackNV(GLenum mode, GLuint id);
void glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream);
void glDrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
void glEdgeFlag(GLboolean flag);
void glEdgeFlagFormatNV(GLsizei stride);
void glEdgeFlagPointer(GLsizei stride, GLvoid pointer);
void glEdgeFlagPointerEXT(GLsizei stride, GLsizei count, GLboolean pointer);
void glEdgeFlagPointerListIBM(GLint stride, GLboolean * pointer, GLint ptrstride);
void glEdgeFlagv(GLboolean flag);
void glElementPointerAPPLE(GLenum type, GLvoid pointer);
void glElementPointerATI(GLenum type, GLvoid pointer);
void glEnable(GLenum cap);
void glEnableClientState(GLenum array);
void glEnableClientStateIndexedEXT(GLenum array, GLuint index);
void glEnableClientStateiEXT(GLenum array, GLuint index);
void glEnableIndexedEXT(GLenum target, GLuint index);
void glEnableVariantClientStateEXT(GLuint id);
void glEnableVertexArrayAttribEXT(GLuint vaobj, GLuint index);
void glEnableVertexArrayEXT(GLuint vaobj, GLenum array);
void glEnableVertexAttribAPPLE(GLuint index, GLenum pname);
void glEnableVertexAttribArray(GLuint index);
void glEnableVertexAttribArrayARB(GLuint index);
void glEnablei(GLenum target, GLuint index);
void glEnd();
void glEndConditionalRender();
void glEndConditionalRenderNV();
void glEndConditionalRenderNVX();
void glEndFragmentShaderATI();
void glEndList();
void glEndOcclusionQueryNV();
void glEndPerfMonitorAMD(GLuint monitor);
void glEndQuery(GLenum target);
void glEndQueryARB(GLenum target);
void glEndQueryIndexed(GLenum target, GLuint index);
void glEndTransformFeedback();
void glEndTransformFeedbackEXT();
void glEndTransformFeedbackNV();
void glEndVertexShaderEXT();
void glEndVideoCaptureNV(GLuint video_capture_slot);
void glEvalCoord1d(GLdouble u);
void glEvalCoord1dv(GLdouble u);
void glEvalCoord1f(GLfloat u);
void glEvalCoord1fv(GLfloat u);
void glEvalCoord1xOES(GLfixed u);
void glEvalCoord1xvOES(GLfixed coords);
void glEvalCoord2d(GLdouble u, GLdouble v);
void glEvalCoord2dv(GLdouble u);
void glEvalCoord2f(GLfloat u, GLfloat v);
void glEvalCoord2fv(GLfloat u);
void glEvalCoord2xOES(GLfixed u, GLfixed v);
void glEvalCoord2xvOES(GLfixed coords);
void glEvalMapsNV(GLenum target, GLenum mode);
void glEvalMesh1(GLenum mode, GLint i1, GLint i2);
void glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
void glEvalPoint1(GLint i);
void glEvalPoint2(GLint i, GLint j);
void glExecuteProgramNV(GLenum target, GLuint id, GLfloat params);
void glExtractComponentEXT(GLuint res, GLuint src, GLuint num);
void glFeedbackBuffer(GLsizei size, GLenum type, GLfloat buffer);
void glFeedbackBufferxOES(GLsizei n, GLenum type, GLfixed buffer);
sync glFenceSync(GLenum condition, GLbitfield flags);
void glFinalCombinerInputNV(GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
void glFinish();
Int32 glFinishAsyncSGIX(GLuint markerp);
void glFinishFenceAPPLE(GLuint fence);
void glFinishFenceNV(GLuint fence);
void glFinishObjectAPPLE(GLenum object, GLint name);
void glFinishTextureSUNX();
void glFlush();
void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length);
void glFlushMappedBufferRangeAPPLE(GLenum target, GLintptr offset, GLsizeiptr size);
void glFlushMappedNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length);
void glFlushPixelDataRangeNV(GLenum target);
void glFlushRasterSGIX();
void glFlushStaticDataIBM(GLenum target);
void glFlushVertexArrayRangeAPPLE(GLsizei length, GLvoid pointer);
void glFlushVertexArrayRangeNV();
void glFogCoordFormatNV(GLenum type, GLsizei stride);
void glFogCoordPointer(GLenum type, GLsizei stride, GLvoid pointer);
void glFogCoordPointerEXT(GLenum type, GLsizei stride, GLvoid pointer);
void glFogCoordPointerListIBM(GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride);
void glFogCoordd(GLdouble coord);
void glFogCoorddEXT(GLdouble coord);
void glFogCoorddv(GLdouble coord);
void glFogCoorddvEXT(GLdouble coord);
void glFogCoordf(GLfloat coord);
void glFogCoordfEXT(GLfloat coord);
void glFogCoordfv(GLfloat coord);
void glFogCoordfvEXT(GLfloat coord);
void glFogCoordhNV(GLhalfNV fog);
void glFogCoordhvNV(GLhalfNV fog);
void glFogFuncSGIS(GLsizei n, GLfloat points);
void glFogf(GLenum pname, GLfloat param);
void glFogfv(GLenum pname, GLfloat params);
void glFogi(GLenum pname, GLint param);
void glFogiv(GLenum pname, GLint params);
void glFogxOES(GLenum pname, GLfixed param);
void glFogxvOES(GLenum pname, GLfixed param);
void glFragmentColorMaterialSGIX(GLenum face, GLenum mode);
void glFragmentLightModelfSGIX(GLenum pname, GLfloat param);
void glFragmentLightModelfvSGIX(GLenum pname, GLfloat params);
void glFragmentLightModeliSGIX(GLenum pname, GLint param);
void glFragmentLightModelivSGIX(GLenum pname, GLint params);
void glFragmentLightfSGIX(GLenum light, GLenum pname, GLfloat param);
void glFragmentLightfvSGIX(GLenum light, GLenum pname, GLfloat params);
void glFragmentLightiSGIX(GLenum light, GLenum pname, GLint param);
void glFragmentLightivSGIX(GLenum light, GLenum pname, GLint params);
void glFragmentMaterialfSGIX(GLenum face, GLenum pname, GLfloat param);
void glFragmentMaterialfvSGIX(GLenum face, GLenum pname, GLfloat params);
void glFragmentMaterialiSGIX(GLenum face, GLenum pname, GLint param);
void glFragmentMaterialivSGIX(GLenum face, GLenum pname, GLint params);
void glFrameTerminatorGREMEDY();
void glFrameZoomSGIX(GLint factor);
void glFramebufferDrawBufferEXT(GLuint framebuffer, GLenum mode);
void glFramebufferDrawBuffersEXT(GLuint framebuffer, GLsizei n, GLenum bufs);
void glFramebufferParameteri(GLenum target, GLenum pname, GLint param);
void glFramebufferReadBufferEXT(GLuint framebuffer, GLenum mode);
void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
void glFramebufferRenderbufferEXT(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
void glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level);
void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void glFramebufferTexture1DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void glFramebufferTexture2DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
void glFramebufferTexture3DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
void glFramebufferTextureARB(GLenum target, GLenum attachment, GLuint texture, GLint level);
void glFramebufferTextureEXT(GLenum target, GLenum attachment, GLuint texture, GLint level);
void glFramebufferTextureFaceARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
void glFramebufferTextureFaceEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
void glFramebufferTextureLayerARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
void glFramebufferTextureLayerEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
void glFreeObjectBufferATI(GLuint buffer);
void glFrontFace(GLenum mode);
void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
void glFrustumfOES(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
void glFrustumxOES(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f);
UInt32 glGenAsyncMarkersSGIX(GLsizei range);
void glGenBuffers(GLsizei n, GLuint buffers);
void glGenBuffersARB(GLsizei n, GLuint buffers);
void glGenFencesAPPLE(GLsizei n, GLuint fences);
void glGenFencesNV(GLsizei n, GLuint fences);
UInt32 glGenFragmentShadersATI(GLuint range);
void glGenFramebuffers(GLsizei n, GLuint framebuffers);
void glGenFramebuffersEXT(GLsizei n, GLuint framebuffers);
List glGenLists(GLsizei range);
void glGenNamesAMD(GLenum identifier, GLuint num, GLuint names);
void glGenOcclusionQueriesNV(GLsizei n, GLuint ids);
Path glGenPathsNV(GLsizei range);
void glGenPerfMonitorsAMD(GLsizei n, GLuint monitors);
void glGenProgramPipelines(GLsizei n, GLuint pipelines);
void glGenProgramsARB(GLsizei n, GLuint programs);
void glGenProgramsNV(GLsizei n, GLuint programs);
void glGenQueries(GLsizei n, GLuint ids);
void glGenQueriesARB(GLsizei n, GLuint ids);
void glGenRenderbuffers(GLsizei n, GLuint renderbuffers);
void glGenRenderbuffersEXT(GLsizei n, GLuint renderbuffers);
void glGenSamplers(GLsizei count, GLuint samplers);
UInt32 glGenSymbolsEXT(GLenum datatype, GLenum storagetype, GLenum range, GLuint components);
void glGenTextures(GLsizei n, GLuint textures);
void glGenTexturesEXT(GLsizei n, GLuint textures);
void glGenTransformFeedbacks(GLsizei n, GLuint ids);
void glGenTransformFeedbacksNV(GLsizei n, GLuint ids);
void glGenVertexArrays(GLsizei n, GLuint arrays);
void glGenVertexArraysAPPLE(GLsizei n, GLuint arrays);
UInt32 glGenVertexShadersEXT(GLuint range);
void glGenerateMipmap(GLenum target);
void glGenerateMipmapEXT(GLenum target);
void glGenerateMultiTexMipmapEXT(GLenum texunit, GLenum target);
void glGenerateTextureMipmapEXT(GLuint texture, GLenum target);
void glGetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint params);
void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLint size, GLenum type, GLchar name);
void glGetActiveAttribARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei length, GLint size, GLenum type, GLcharARB name);
void glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei length, GLchar name);
void glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei length, GLchar name);
void glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint values);
void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLint size, GLenum type, GLchar name);
void glGetActiveUniformARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei length, GLint size, GLenum type, GLcharARB name);
void glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei length, GLchar uniformBlockName);
void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint params);
void glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei length, GLchar uniformName);
void glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, GLuint uniformIndices, GLenum pname, GLint params);
void glGetActiveVaryingNV(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLsizei size, GLenum type, GLchar name);
void glGetArrayObjectfvATI(GLenum array, GLenum pname, GLfloat params);
void glGetArrayObjectivATI(GLenum array, GLenum pname, GLint params);
void glGetAttachedObjectsARB(GLhandleARB containerObj, GLsizei maxCount, GLsizei count, GLhandleARB obj);
void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei count, GLuint obj);
Int32 glGetAttribLocation(GLuint program, GLchar name);
Int32 glGetAttribLocationARB(GLhandleARB programObj, GLcharARB name);
void glGetBooleanIndexedvEXT(GLenum target, GLuint index, GLboolean data);
void glGetBooleani_v(GLenum target, GLuint index, GLboolean data);
void glGetBooleanv(GLenum pname, GLboolean params);
void glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64 params);
void glGetBufferParameteriv(GLenum target, GLenum pname, GLint params);
void glGetBufferParameterivARB(GLenum target, GLenum pname, GLint params);
void glGetBufferParameterui64vNV(GLenum target, GLenum pname, GLuint64EXT params);
void glGetBufferPointerv(GLenum target, GLenum pname, GLvoid * params);
void glGetBufferPointervARB(GLenum target, GLenum pname, GLvoid * params);
void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid data);
void glGetBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid data);
void glGetClipPlane(GLenum plane, GLdouble equation);
void glGetClipPlanefOES(GLenum plane, GLfloat equation);
void glGetClipPlanexOES(GLenum plane, GLfixed equation);
void glGetColorTable(GLenum target, GLenum format, GLenum type, GLvoid table);
void glGetColorTableEXT(GLenum target, GLenum format, GLenum type, GLvoid data);
void glGetColorTableParameterfv(GLenum target, GLenum pname, GLfloat params);
void glGetColorTableParameterfvEXT(GLenum target, GLenum pname, GLfloat params);
void glGetColorTableParameterfvSGI(GLenum target, GLenum pname, GLfloat params);
void glGetColorTableParameteriv(GLenum target, GLenum pname, GLint params);
void glGetColorTableParameterivEXT(GLenum target, GLenum pname, GLint params);
void glGetColorTableParameterivSGI(GLenum target, GLenum pname, GLint params);
void glGetColorTableSGI(GLenum target, GLenum format, GLenum type, GLvoid table);
void glGetCombinerInputParameterfvNV(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat params);
void glGetCombinerInputParameterivNV(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint params);
void glGetCombinerOutputParameterfvNV(GLenum stage, GLenum portion, GLenum pname, GLfloat params);
void glGetCombinerOutputParameterivNV(GLenum stage, GLenum portion, GLenum pname, GLint params);
void glGetCombinerStageParameterfvNV(GLenum stage, GLenum pname, GLfloat params);
void glGetCompressedMultiTexImageEXT(GLenum texunit, GLenum target, GLint lod, GLvoid img);
void glGetCompressedTexImage(GLenum target, GLint level, GLvoid img);
void glGetCompressedTexImageARB(GLenum target, GLint level, GLvoid img);
void glGetCompressedTextureImageEXT(GLuint texture, GLenum target, GLint lod, GLvoid img);
void glGetConvolutionFilter(GLenum target, GLenum format, GLenum type, GLvoid image);
void glGetConvolutionFilterEXT(GLenum target, GLenum format, GLenum type, GLvoid image);
void glGetConvolutionParameterfv(GLenum target, GLenum pname, GLfloat params);
void glGetConvolutionParameterfvEXT(GLenum target, GLenum pname, GLfloat params);
void glGetConvolutionParameteriv(GLenum target, GLenum pname, GLint params);
void glGetConvolutionParameterivEXT(GLenum target, GLenum pname, GLint params);
void glGetConvolutionParameterxvOES(GLenum target, GLenum pname, GLfixed params);
UInt32 glGetDebugMessageLog(GLuint count, GLsizei bufsize, GLenum sources, GLenum types, GLuint ids, GLenum severities, GLsizei lengths, GLchar messageLog);
UInt32 glGetDebugMessageLogAMD(GLuint count, GLsizei bufsize, GLenum categories, GLuint severities, GLuint ids, GLsizei lengths, GLchar message);
UInt32 glGetDebugMessageLogARB(GLuint count, GLsizei bufsize, GLenum sources, GLenum types, GLuint ids, GLenum severities, GLsizei lengths, GLchar messageLog);
void glGetDetailTexFuncSGIS(GLenum target, GLfloat points);
void glGetDoubleIndexedvEXT(GLenum target, GLuint index, GLdouble data);
void glGetDoublei_v(GLenum target, GLuint index, GLdouble data);
void glGetDoublei_vEXT(GLenum target, GLuint index, GLdouble data);
void glGetDoublev(GLenum pname, GLdouble params);
ErrorCode glGetError();
void glGetFenceivNV(GLuint fence, GLenum pname, GLint params);
void glGetFinalCombinerInputParameterfvNV(GLenum variable, GLenum pname, GLfloat params);
void glGetFinalCombinerInputParameterivNV(GLenum variable, GLenum pname, GLint params);
void glGetFixedvOES(GLenum pname, GLfixed params);
void glGetFloatIndexedvEXT(GLenum target, GLuint index, GLfloat data);
void glGetFloati_v(GLenum target, GLuint index, GLfloat data);
void glGetFloati_vEXT(GLenum target, GLuint index, GLfloat data);
void glGetFloatv(GLenum pname, GLfloat params);
void glGetFogFuncSGIS(GLfloat points);
Int32 glGetFragDataIndex(GLuint program, GLchar name);
Int32 glGetFragDataLocation(GLuint program, GLchar name);
Int32 glGetFragDataLocationEXT(GLuint program, GLchar name);
void glGetFragmentLightfvSGIX(GLenum light, GLenum pname, GLfloat params);
void glGetFragmentLightivSGIX(GLenum light, GLenum pname, GLint params);
void glGetFragmentMaterialfvSGIX(GLenum face, GLenum pname, GLfloat params);
void glGetFragmentMaterialivSGIX(GLenum face, GLenum pname, GLint params);
void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint params);
void glGetFramebufferAttachmentParameterivEXT(GLenum target, GLenum attachment, GLenum pname, GLint params);
void glGetFramebufferParameteriv(GLenum target, GLenum pname, GLint params);
void glGetFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint params);
GLenum glGetGraphicsResetStatusARB();
handleARB glGetHandleARB(GLenum pname);
void glGetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid values);
void glGetHistogramEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid values);
void glGetHistogramParameterfv(GLenum target, GLenum pname, GLfloat params);
void glGetHistogramParameterfvEXT(GLenum target, GLenum pname, GLfloat params);
void glGetHistogramParameteriv(GLenum target, GLenum pname, GLint params);
void glGetHistogramParameterivEXT(GLenum target, GLenum pname, GLint params);
void glGetHistogramParameterxvOES(GLenum target, GLenum pname, GLfixed params);
UInt64 glGetImageHandleNV(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
void glGetImageTransformParameterfvHP(GLenum target, GLenum pname, GLfloat params);
void glGetImageTransformParameterivHP(GLenum target, GLenum pname, GLint params);
void glGetInfoLogARB(GLhandleARB obj, GLsizei maxLength, GLsizei length, GLcharARB infoLog);
Int32 glGetInstrumentsSGIX();
void glGetInteger64i_v(GLenum target, GLuint index, GLint64 data);
void glGetInteger64v(GLenum pname, GLint64 params);
void glGetIntegerIndexedvEXT(GLenum target, GLuint index, GLint data);
void glGetIntegeri_v(GLenum target, GLuint index, GLint data);
void glGetIntegerui64i_vNV(GLenum value, GLuint index, GLuint64EXT result);
void glGetIntegerui64vNV(GLenum value, GLuint64EXT result);
void glGetIntegerv(GLenum pname, GLint params);
void glGetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 params);
void glGetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint params);
void glGetInvariantBooleanvEXT(GLuint id, GLenum value, GLboolean data);
void glGetInvariantFloatvEXT(GLuint id, GLenum value, GLfloat data);
void glGetInvariantIntegervEXT(GLuint id, GLenum value, GLint data);
void glGetLightfv(GLenum light, GLenum pname, GLfloat params);
void glGetLightiv(GLenum light, GLenum pname, GLint params);
void glGetLightxOES(GLenum light, GLenum pname, GLfixed params);
void glGetListParameterfvSGIX(GLuint list, GLenum pname, GLfloat params);
void glGetListParameterivSGIX(GLuint list, GLenum pname, GLint params);
void glGetLocalConstantBooleanvEXT(GLuint id, GLenum value, GLboolean data);
void glGetLocalConstantFloatvEXT(GLuint id, GLenum value, GLfloat data);
void glGetLocalConstantIntegervEXT(GLuint id, GLenum value, GLint data);
void glGetMapAttribParameterfvNV(GLenum target, GLuint index, GLenum pname, GLfloat params);
void glGetMapAttribParameterivNV(GLenum target, GLuint index, GLenum pname, GLint params);
void glGetMapControlPointsNV(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLboolean packed, GLvoid points);
void glGetMapParameterfvNV(GLenum target, GLenum pname, GLfloat params);
void glGetMapParameterivNV(GLenum target, GLenum pname, GLint params);
void glGetMapdv(GLenum target, GLenum query, GLdouble v);
void glGetMapfv(GLenum target, GLenum query, GLfloat v);
void glGetMapiv(GLenum target, GLenum query, GLint v);
void glGetMapxvOES(GLenum target, GLenum query, GLfixed v);
void glGetMaterialfv(GLenum face, GLenum pname, GLfloat params);
void glGetMaterialiv(GLenum face, GLenum pname, GLint params);
void glGetMaterialxOES(GLenum face, GLenum pname, GLfixed param);
void glGetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid values);
void glGetMinmaxEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid values);
void glGetMinmaxParameterfv(GLenum target, GLenum pname, GLfloat params);
void glGetMinmaxParameterfvEXT(GLenum target, GLenum pname, GLfloat params);
void glGetMinmaxParameteriv(GLenum target, GLenum pname, GLint params);
void glGetMinmaxParameterivEXT(GLenum target, GLenum pname, GLint params);
void glGetMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat params);
void glGetMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint params);
void glGetMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble params);
void glGetMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat params);
void glGetMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint params);
void glGetMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, GLvoid pixels);
void glGetMultiTexLevelParameterfvEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat params);
void glGetMultiTexLevelParameterivEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint params);
void glGetMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, GLint params);
void glGetMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, GLuint params);
void glGetMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat params);
void glGetMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint params);
void glGetMultisamplefv(GLenum pname, GLuint index, GLfloat val);
void glGetMultisamplefvNV(GLenum pname, GLuint index, GLfloat val);
void glGetNamedBufferParameterivEXT(GLuint buffer, GLenum pname, GLint params);
void glGetNamedBufferParameterui64vNV(GLuint buffer, GLenum pname, GLuint64EXT params);
void glGetNamedBufferPointervEXT(GLuint buffer, GLenum pname, GLvoid * params);
void glGetNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid data);
void glGetNamedFramebufferAttachmentParameterivEXT(GLuint framebuffer, GLenum attachment, GLenum pname, GLint params);
void glGetNamedFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint params);
void glGetNamedProgramLocalParameterIivEXT(GLuint program, GLenum target, GLuint index, GLint params);
void glGetNamedProgramLocalParameterIuivEXT(GLuint program, GLenum target, GLuint index, GLuint params);
void glGetNamedProgramLocalParameterdvEXT(GLuint program, GLenum target, GLuint index, GLdouble params);
void glGetNamedProgramLocalParameterfvEXT(GLuint program, GLenum target, GLuint index, GLfloat params);
void glGetNamedProgramStringEXT(GLuint program, GLenum target, GLenum pname, GLvoid string);
void glGetNamedProgramivEXT(GLuint program, GLenum target, GLenum pname, GLint params);
void glGetNamedRenderbufferParameterivEXT(GLuint renderbuffer, GLenum pname, GLint params);
void glGetNamedStringARB(GLint namelen, GLchar name, GLsizei bufSize, GLint stringlen, GLchar string);
void glGetNamedStringivARB(GLint namelen, GLchar name, GLenum pname, GLint params);
void glGetObjectBufferfvATI(GLuint buffer, GLenum pname, GLfloat params);
void glGetObjectBufferivATI(GLuint buffer, GLenum pname, GLint params);
void glGetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei length, GLchar label);
void glGetObjectParameterfvARB(GLhandleARB obj, GLenum pname, GLfloat params);
void glGetObjectParameterivAPPLE(GLenum objectType, GLuint name, GLenum pname, GLint params);
void glGetObjectParameterivARB(GLhandleARB obj, GLenum pname, GLint params);
void glGetObjectPtrLabel(void * ptr, GLsizei bufSize, GLsizei length, GLchar label);
void glGetOcclusionQueryivNV(GLuint id, GLenum pname, GLint params);
void glGetOcclusionQueryuivNV(GLuint id, GLenum pname, GLuint params);
void glGetPathColorGenfvNV(GLenum color, GLenum pname, GLfloat value);
void glGetPathColorGenivNV(GLenum color, GLenum pname, GLint value);
void glGetPathCommandsNV(GLuint path, GLubyte commands);
void glGetPathCoordsNV(GLuint path, GLfloat coords);
void glGetPathDashArrayNV(GLuint path, GLfloat dashArray);
Float32 glGetPathLengthNV(GLuint path, GLsizei startSegment, GLsizei numSegments);
void glGetPathMetricRangeNV(GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat metrics);
void glGetPathMetricsNV(GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLsizei stride, GLfloat metrics);
void glGetPathParameterfvNV(GLuint path, GLenum pname, GLfloat value);
void glGetPathParameterivNV(GLuint path, GLenum pname, GLint value);
void glGetPathSpacingNV(GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat returnedSpacing);
void glGetPathTexGenfvNV(GLenum texCoordSet, GLenum pname, GLfloat value);
void glGetPathTexGenivNV(GLenum texCoordSet, GLenum pname, GLint value);
void glGetPerfMonitorCounterDataAMD(GLuint monitor, GLenum pname, GLsizei dataSize, GLuint data, GLint bytesWritten);
void glGetPerfMonitorCounterInfoAMD(GLuint group, GLuint counter, GLenum pname, GLvoid data);
void glGetPerfMonitorCounterStringAMD(GLuint group, GLuint counter, GLsizei bufSize, GLsizei length, GLchar counterString);
void glGetPerfMonitorCountersAMD(GLuint group, GLint numCounters, GLint maxActiveCounters, GLsizei counterSize, GLuint counters);
void glGetPerfMonitorGroupStringAMD(GLuint group, GLsizei bufSize, GLsizei length, GLchar groupString);
void glGetPerfMonitorGroupsAMD(GLint numGroups, GLsizei groupsSize, GLuint groups);
void glGetPixelMapfv(GLenum map, GLfloat values);
void glGetPixelMapuiv(GLenum map, GLuint values);
void glGetPixelMapusv(GLenum map, GLushort values);
void glGetPixelMapxv(GLenum map, GLint size, GLfixed values);
void glGetPixelTexGenParameterfvSGIS(GLenum pname, GLfloat params);
void glGetPixelTexGenParameterivSGIS(GLenum pname, GLint params);
void glGetPixelTransformParameterfvEXT(GLenum target, GLenum pname, GLfloat params);
void glGetPixelTransformParameterivEXT(GLenum target, GLenum pname, GLint params);
void glGetPointerIndexedvEXT(GLenum target, GLuint index, GLvoid * data);
void glGetPointeri_vEXT(GLenum target, GLuint index, GLvoid * data);
void glGetPointerv(GLenum pname, GLvoid * params);
void glGetPointervEXT(GLenum pname, GLvoid * params);
void glGetPolygonStipple(GLubyte mask);
void glGetProgramBinary(GLuint program, GLsizei bufSize, GLsizei length, GLenum binaryFormat, GLvoid binary);
void glGetProgramEnvParameterIivNV(GLenum target, GLuint index, GLint params);
void glGetProgramEnvParameterIuivNV(GLenum target, GLuint index, GLuint params);
void glGetProgramEnvParameterdvARB(GLenum target, GLuint index, GLdouble params);
void glGetProgramEnvParameterfvARB(GLenum target, GLuint index, GLfloat params);
void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei length, GLchar infoLog);
void glGetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint params);
void glGetProgramLocalParameterIivNV(GLenum target, GLuint index, GLint params);
void glGetProgramLocalParameterIuivNV(GLenum target, GLuint index, GLuint params);
void glGetProgramLocalParameterdvARB(GLenum target, GLuint index, GLdouble params);
void glGetProgramLocalParameterfvARB(GLenum target, GLuint index, GLfloat params);
void glGetProgramNamedParameterdvNV(GLuint id, GLsizei len, GLubyte name, GLdouble params);
void glGetProgramNamedParameterfvNV(GLuint id, GLsizei len, GLubyte name, GLfloat params);
void glGetProgramParameterdvNV(GLenum target, GLuint index, GLenum pname, GLdouble params);
void glGetProgramParameterfvNV(GLenum target, GLuint index, GLenum pname, GLfloat params);
void glGetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei length, GLchar infoLog);
void glGetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint params);
UInt32 glGetProgramResourceIndex(GLuint program, GLenum programInterface, GLchar name);
Int32 glGetProgramResourceLocation(GLuint program, GLenum programInterface, GLchar name);
Int32 glGetProgramResourceLocationIndex(GLuint program, GLenum programInterface, GLchar name);
void glGetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei length, GLchar name);
void glGetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, GLenum props, GLsizei bufSize, GLsizei length, GLint params);
void glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint values);
void glGetProgramStringARB(GLenum target, GLenum pname, GLvoid string);
void glGetProgramStringNV(GLuint id, GLenum pname, GLubyte program);
void glGetProgramSubroutineParameteruivNV(GLenum target, GLuint index, GLuint param);
void glGetProgramiv(GLuint program, GLenum pname, GLint params);
void glGetProgramivARB(GLenum target, GLenum pname, GLint params);
void glGetProgramivNV(GLuint id, GLenum pname, GLint params);
void glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint params);
void glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64 params);
void glGetQueryObjecti64vEXT(GLuint id, GLenum pname, GLint64EXT params);
void glGetQueryObjectiv(GLuint id, GLenum pname, GLint params);
void glGetQueryObjectivARB(GLuint id, GLenum pname, GLint params);
void glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 params);
void glGetQueryObjectui64vEXT(GLuint id, GLenum pname, GLuint64EXT params);
void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint params);
void glGetQueryObjectuivARB(GLuint id, GLenum pname, GLuint params);
void glGetQueryiv(GLenum target, GLenum pname, GLint params);
void glGetQueryivARB(GLenum target, GLenum pname, GLint params);
void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint params);
void glGetRenderbufferParameterivEXT(GLenum target, GLenum pname, GLint params);
void glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint params);
void glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint params);
void glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat params);
void glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint params);
void glGetSeparableFilter(GLenum target, GLenum format, GLenum type, GLvoid row, GLvoid column, GLvoid span);
void glGetSeparableFilterEXT(GLenum target, GLenum format, GLenum type, GLvoid row, GLvoid column, GLvoid span);
void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei length, GLchar infoLog);
void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint range, GLint precision);
void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei length, GLchar source);
void glGetShaderSourceARB(GLhandleARB obj, GLsizei maxLength, GLsizei length, GLcharARB source);
void glGetShaderiv(GLuint shader, GLenum pname, GLint params);
void glGetSharpenTexFuncSGIS(GLenum target, GLfloat points);
String glGetString(GLenum name);
String glGetStringi(GLenum name, GLuint index);
UInt32 glGetSubroutineIndex(GLuint program, GLenum shadertype, GLchar name);
Int32 glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, GLchar name);
void glGetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei length, GLint values);
void glGetTexBumpParameterfvATI(GLenum pname, GLfloat param);
void glGetTexBumpParameterivATI(GLenum pname, GLint param);
void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat params);
void glGetTexEnviv(GLenum target, GLenum pname, GLint params);
void glGetTexEnvxvOES(GLenum target, GLenum pname, GLfixed params);
void glGetTexFilterFuncSGIS(GLenum target, GLenum filter, GLfloat weights);
void glGetTexGendv(GLenum coord, GLenum pname, GLdouble params);
void glGetTexGenfv(GLenum coord, GLenum pname, GLfloat params);
void glGetTexGeniv(GLenum coord, GLenum pname, GLint params);
void glGetTexGenxvOES(GLenum coord, GLenum pname, GLfixed params);
void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid pixels);
void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat params);
void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint params);
void glGetTexLevelParameterxvOES(GLenum target, GLint level, GLenum pname, GLfixed params);
void glGetTexParameterIiv(GLenum target, GLenum pname, GLint params);
void glGetTexParameterIivEXT(GLenum target, GLenum pname, GLint params);
void glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint params);
void glGetTexParameterIuivEXT(GLenum target, GLenum pname, GLuint params);
void glGetTexParameterPointervAPPLE(GLenum target, GLenum pname, GLvoid * params);
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat params);
void glGetTexParameteriv(GLenum target, GLenum pname, GLint params);
void glGetTexParameterxvOES(GLenum target, GLenum pname, GLfixed params);
UInt64 glGetTextureHandleNV(GLuint texture);
void glGetTextureImageEXT(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, GLvoid pixels);
void glGetTextureLevelParameterfvEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat params);
void glGetTextureLevelParameterivEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLint params);
void glGetTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, GLint params);
void glGetTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, GLuint params);
void glGetTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat params);
void glGetTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint params);
UInt64 glGetTextureSamplerHandleNV(GLuint texture, GLuint sampler);
void glGetTrackMatrixivNV(GLenum target, GLuint address, GLenum pname, GLint params);
void glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLsizei size, GLenum type, GLchar name);
void glGetTransformFeedbackVaryingEXT(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLsizei size, GLenum type, GLchar name);
void glGetTransformFeedbackVaryingNV(GLuint program, GLuint index, GLint location);
UInt32 glGetUniformBlockIndex(GLuint program, GLchar uniformBlockName);
Int32 glGetUniformBufferSizeEXT(GLuint program, GLint location);
void glGetUniformIndices(GLuint program, GLsizei uniformCount, GLchar*const uniformNames, GLuint uniformIndices);
Int32 glGetUniformLocation(GLuint program, GLchar name);
Int32 glGetUniformLocationARB(GLhandleARB programObj, GLcharARB name);
BufferOffset glGetUniformOffsetEXT(GLuint program, GLint location);
void glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint params);
void glGetUniformdv(GLuint program, GLint location, GLdouble params);
void glGetUniformfv(GLuint program, GLint location, GLfloat params);
void glGetUniformfvARB(GLhandleARB programObj, GLint location, GLfloat params);
void glGetUniformi64vNV(GLuint program, GLint location, GLint64EXT params);
void glGetUniformiv(GLuint program, GLint location, GLint params);
void glGetUniformivARB(GLhandleARB programObj, GLint location, GLint params);
void glGetUniformui64vNV(GLuint program, GLint location, GLuint64EXT params);
void glGetUniformuiv(GLuint program, GLint location, GLuint params);
void glGetUniformuivEXT(GLuint program, GLint location, GLuint params);
void glGetVariantArrayObjectfvATI(GLuint id, GLenum pname, GLfloat params);
void glGetVariantArrayObjectivATI(GLuint id, GLenum pname, GLint params);
void glGetVariantBooleanvEXT(GLuint id, GLenum value, GLboolean data);
void glGetVariantFloatvEXT(GLuint id, GLenum value, GLfloat data);
void glGetVariantIntegervEXT(GLuint id, GLenum value, GLint data);
void glGetVariantPointervEXT(GLuint id, GLenum value, GLvoid * data);
Int32 glGetVaryingLocationNV(GLuint program, GLchar name);
void glGetVertexArrayIntegeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, GLint param);
void glGetVertexArrayIntegervEXT(GLuint vaobj, GLenum pname, GLint param);
void glGetVertexArrayPointeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, GLvoid * param);
void glGetVertexArrayPointervEXT(GLuint vaobj, GLenum pname, GLvoid * param);
void glGetVertexAttribArrayObjectfvATI(GLuint index, GLenum pname, GLfloat params);
void glGetVertexAttribArrayObjectivATI(GLuint index, GLenum pname, GLint params);
void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint params);
void glGetVertexAttribIivEXT(GLuint index, GLenum pname, GLint params);
void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint params);
void glGetVertexAttribIuivEXT(GLuint index, GLenum pname, GLuint params);
void glGetVertexAttribLdv(GLuint index, GLenum pname, GLdouble params);
void glGetVertexAttribLdvEXT(GLuint index, GLenum pname, GLdouble params);
void glGetVertexAttribLi64vNV(GLuint index, GLenum pname, GLint64EXT params);
void glGetVertexAttribLui64vNV(GLuint index, GLenum pname, GLuint64EXT params);
void glGetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid * pointer);
void glGetVertexAttribPointervARB(GLuint index, GLenum pname, GLvoid * pointer);
void glGetVertexAttribPointervNV(GLuint index, GLenum pname, GLvoid * pointer);
void glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble params);
void glGetVertexAttribdvARB(GLuint index, GLenum pname, GLdouble params);
void glGetVertexAttribdvNV(GLuint index, GLenum pname, GLdouble params);
void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat params);
void glGetVertexAttribfvARB(GLuint index, GLenum pname, GLfloat params);
void glGetVertexAttribfvNV(GLuint index, GLenum pname, GLfloat params);
void glGetVertexAttribiv(GLuint index, GLenum pname, GLint params);
void glGetVertexAttribivARB(GLuint index, GLenum pname, GLint params);
void glGetVertexAttribivNV(GLuint index, GLenum pname, GLint params);
void glGetVideoCaptureStreamdvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble params);
void glGetVideoCaptureStreamfvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat params);
void glGetVideoCaptureStreamivNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLint params);
void glGetVideoCaptureivNV(GLuint video_capture_slot, GLenum pname, GLint params);
void glGetVideoi64vNV(GLuint video_slot, GLenum pname, GLint64EXT params);
void glGetVideoivNV(GLuint video_slot, GLenum pname, GLint params);
void glGetVideoui64vNV(GLuint video_slot, GLenum pname, GLuint64EXT params);
void glGetVideouivNV(GLuint video_slot, GLenum pname, GLuint params);
void glGetnColorTableARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, GLvoid table);
void glGetnCompressedTexImageARB(GLenum target, GLint lod, GLsizei bufSize, GLvoid img);
void glGetnConvolutionFilterARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, GLvoid image);
void glGetnHistogramARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, GLvoid values);
void glGetnMapdvARB(GLenum target, GLenum query, GLsizei bufSize, GLdouble v);
void glGetnMapfvARB(GLenum target, GLenum query, GLsizei bufSize, GLfloat v);
void glGetnMapivARB(GLenum target, GLenum query, GLsizei bufSize, GLint v);
void glGetnMinmaxARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, GLvoid values);
void glGetnPixelMapfvARB(GLenum map, GLsizei bufSize, GLfloat values);
void glGetnPixelMapuivARB(GLenum map, GLsizei bufSize, GLuint values);
void glGetnPixelMapusvARB(GLenum map, GLsizei bufSize, GLushort values);
void glGetnPolygonStippleARB(GLsizei bufSize, GLubyte pattern);
void glGetnSeparableFilterARB(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, GLvoid row, GLsizei columnBufSize, GLvoid column, GLvoid span);
void glGetnTexImageARB(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid img);
void glGetnUniformdvARB(GLuint program, GLint location, GLsizei bufSize, GLdouble params);
void glGetnUniformfvARB(GLuint program, GLint location, GLsizei bufSize, GLfloat params);
void glGetnUniformivARB(GLuint program, GLint location, GLsizei bufSize, GLint params);
void glGetnUniformuivARB(GLuint program, GLint location, GLsizei bufSize, GLuint params);
void glGlobalAlphaFactorbSUN(GLbyte factor);
void glGlobalAlphaFactordSUN(GLdouble factor);
void glGlobalAlphaFactorfSUN(GLfloat factor);
void glGlobalAlphaFactoriSUN(GLint factor);
void glGlobalAlphaFactorsSUN(GLshort factor);
void glGlobalAlphaFactorubSUN(GLubyte factor);
void glGlobalAlphaFactoruiSUN(GLuint factor);
void glGlobalAlphaFactorusSUN(GLushort factor);
void glHint(GLenum target, GLenum mode);
void glHintPGI(GLenum target, GLint mode);
void glHistogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
void glHistogramEXT(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
void glIglooInterfaceSGIX(GLenum pname, GLvoid params);
void glImageTransformParameterfHP(GLenum target, GLenum pname, GLfloat param);
void glImageTransformParameterfvHP(GLenum target, GLenum pname, GLfloat params);
void glImageTransformParameteriHP(GLenum target, GLenum pname, GLint param);
void glImageTransformParameterivHP(GLenum target, GLenum pname, GLint params);
sync glImportSyncEXT(GLenum external_sync_type, GLintptr external_sync, GLbitfield flags);
void glIndexFormatNV(GLenum type, GLsizei stride);
void glIndexFuncEXT(GLenum func, GLclampf ref);
void glIndexMask(GLuint mask);
void glIndexMaterialEXT(GLenum face, GLenum mode);
void glIndexPointer(GLenum type, GLsizei stride, GLvoid pointer);
void glIndexPointerEXT(GLenum type, GLsizei stride, GLsizei count, GLvoid pointer);
void glIndexPointerListIBM(GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride);
void glIndexd(GLdouble c);
void glIndexdv(GLdouble c);
void glIndexf(GLfloat c);
void glIndexfv(GLfloat c);
void glIndexi(GLint c);
void glIndexiv(GLint c);
void glIndexs(GLshort c);
void glIndexsv(GLshort c);
void glIndexub(GLubyte c);
void glIndexubv(GLubyte c);
void glIndexxOES(GLfixed component);
void glIndexxvOES(GLfixed component);
void glInitNames();
void glInsertComponentEXT(GLuint res, GLuint src, GLuint num);
void glInstrumentsBufferSGIX(GLsizei size, GLint buffer);
void glInterleavedArrays(GLenum format, GLsizei stride, GLvoid pointer);
void glInterpolatePathsNV(GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight);
void glInvalidateBufferData(GLuint buffer);
void glInvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length);
void glInvalidateFramebuffer(GLenum target, GLsizei numAttachments, GLenum attachments);
void glInvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, GLenum attachments, GLint x, GLint y, GLsizei width, GLsizei height);
void glInvalidateTexImage(GLuint texture, GLint level);
void glInvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
Boolean glIsAsyncMarkerSGIX(GLuint marker);
Boolean glIsBuffer(GLuint buffer);
Boolean glIsBufferARB(GLuint buffer);
Boolean glIsBufferResidentNV(GLenum target);
Boolean glIsEnabled(GLenum cap);
Boolean glIsEnabledIndexedEXT(GLenum target, GLuint index);
Boolean glIsEnabledi(GLenum target, GLuint index);
Boolean glIsFenceAPPLE(GLuint fence);
Boolean glIsFenceNV(GLuint fence);
Boolean glIsFramebuffer(GLuint framebuffer);
Boolean glIsFramebufferEXT(GLuint framebuffer);
Boolean glIsImageHandleResidentNV(GLuint64 handle);
Boolean glIsList(GLuint list);
Boolean glIsNameAMD(GLenum identifier, GLuint name);
Boolean glIsNamedBufferResidentNV(GLuint buffer);
Boolean glIsNamedStringARB(GLint namelen, GLchar name);
Boolean glIsObjectBufferATI(GLuint buffer);
Boolean glIsOcclusionQueryNV(GLuint id);
Boolean glIsPathNV(GLuint path);
Boolean glIsPointInFillPathNV(GLuint path, GLuint mask, GLfloat x, GLfloat y);
Boolean glIsPointInStrokePathNV(GLuint path, GLfloat x, GLfloat y);
Boolean glIsProgram(GLuint program);
Boolean glIsProgramARB(GLuint program);
Boolean glIsProgramNV(GLuint id);
Boolean glIsProgramPipeline(GLuint pipeline);
Boolean glIsQuery(GLuint id);
Boolean glIsQueryARB(GLuint id);
Boolean glIsRenderbuffer(GLuint renderbuffer);
Boolean glIsRenderbufferEXT(GLuint renderbuffer);
Boolean glIsSampler(GLuint sampler);
Boolean glIsShader(GLuint shader);
Boolean glIsSync(GLsync sync);
Boolean glIsTexture(GLuint texture);
Boolean glIsTextureEXT(GLuint texture);
Boolean glIsTextureHandleResidentNV(GLuint64 handle);
Boolean glIsTransformFeedback(GLuint id);
Boolean glIsTransformFeedbackNV(GLuint id);
Boolean glIsVariantEnabledEXT(GLuint id, GLenum cap);
Boolean glIsVertexArray(GLuint array);
Boolean glIsVertexArrayAPPLE(GLuint array);
Boolean glIsVertexAttribEnabledAPPLE(GLuint index, GLenum pname);
void glLightEnviSGIX(GLenum pname, GLint param);
void glLightModelf(GLenum pname, GLfloat param);
void glLightModelfv(GLenum pname, GLfloat params);
void glLightModeli(GLenum pname, GLint param);
void glLightModeliv(GLenum pname, GLint params);
void glLightModelxOES(GLenum pname, GLfixed param);
void glLightModelxvOES(GLenum pname, GLfixed param);
void glLightf(GLenum light, GLenum pname, GLfloat param);
void glLightfv(GLenum light, GLenum pname, GLfloat params);
void glLighti(GLenum light, GLenum pname, GLint param);
void glLightiv(GLenum light, GLenum pname, GLint params);
void glLightxOES(GLenum light, GLenum pname, GLfixed param);
void glLightxvOES(GLenum light, GLenum pname, GLfixed params);
void glLineStipple(GLint factor, GLushort pattern);
void glLineWidth(GLfloat width);
void glLineWidthxOES(GLfixed width);
void glLinkProgram(GLuint program);
void glLinkProgramARB(GLhandleARB programObj);
void glListBase(GLuint base);
void glListParameterfSGIX(GLuint list, GLenum pname, GLfloat param);
void glListParameterfvSGIX(GLuint list, GLenum pname, GLfloat params);
void glListParameteriSGIX(GLuint list, GLenum pname, GLint param);
void glListParameterivSGIX(GLuint list, GLenum pname, GLint params);
void glLoadIdentity();
void glLoadIdentityDeformationMapSGIX(GLbitfield mask);
void glLoadMatrixd(GLdouble m);
void glLoadMatrixf(GLfloat m);
void glLoadMatrixxOES(GLfixed m);
void glLoadName(GLuint name);
void glLoadProgramNV(GLenum target, GLuint id, GLsizei len, GLubyte program);
void glLoadTransposeMatrixd(GLdouble m);
void glLoadTransposeMatrixdARB(GLdouble m);
void glLoadTransposeMatrixf(GLfloat m);
void glLoadTransposeMatrixfARB(GLfloat m);
void glLoadTransposeMatrixxOES(GLfixed m);
void glLockArraysEXT(GLint first, GLsizei count);
void glLogicOp(GLenum opcode);
void glMakeBufferNonResidentNV(GLenum target);
void glMakeBufferResidentNV(GLenum target, GLenum access);
void glMakeImageHandleNonResidentNV(GLuint64 handle);
void glMakeImageHandleResidentNV(GLuint64 handle, GLenum access);
void glMakeNamedBufferNonResidentNV(GLuint buffer);
void glMakeNamedBufferResidentNV(GLuint buffer, GLenum access);
void glMakeTextureHandleNonResidentNV(GLuint64 handle);
void glMakeTextureHandleResidentNV(GLuint64 handle);
void glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, GLdouble points);
void glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, GLfloat points);
void glMap1xOES(GLenum target, GLfixed u1, GLfixed u2, GLint stride, GLint order, GLfixed points);
void glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble points);
void glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat points);
void glMap2xOES(GLenum target, GLfixed u1, GLfixed u2, GLint ustride, GLint uorder, GLfixed v1, GLfixed v2, GLint vstride, GLint vorder, GLfixed points);
VoidPointer glMapBuffer(GLenum target, GLenum access);
VoidPointer glMapBufferARB(GLenum target, GLenum access);
VoidPointer glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
void glMapControlPointsNV(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLint uorder, GLint vorder, GLboolean packed, GLvoid points);
void glMapGrid1d(GLint un, GLdouble u1, GLdouble u2);
void glMapGrid1f(GLint un, GLfloat u1, GLfloat u2);
void glMapGrid1xOES(GLint n, GLfixed u1, GLfixed u2);
void glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
void glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
void glMapGrid2xOES(GLint n, GLfixed u1, GLfixed u2, GLfixed v1, GLfixed v2);
VoidPointer glMapNamedBufferEXT(GLuint buffer, GLenum access);
VoidPointer glMapNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
VoidPointer glMapObjectBufferATI(GLuint buffer);
void glMapParameterfvNV(GLenum target, GLenum pname, GLfloat params);
void glMapParameterivNV(GLenum target, GLenum pname, GLint params);
VoidPointer glMapTexture2DINTEL(GLuint texture, GLint level, GLbitfield access, GLint stride, GLenum layout);
void glMapVertexAttrib1dAPPLE(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint stride, GLint order, GLdouble points);
void glMapVertexAttrib1fAPPLE(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint stride, GLint order, GLfloat points);
void glMapVertexAttrib2dAPPLE(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble points);
void glMapVertexAttrib2fAPPLE(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat points);
void glMaterialf(GLenum face, GLenum pname, GLfloat param);
void glMaterialfv(GLenum face, GLenum pname, GLfloat params);
void glMateriali(GLenum face, GLenum pname, GLint param);
void glMaterialiv(GLenum face, GLenum pname, GLint params);
void glMaterialxOES(GLenum face, GLenum pname, GLfixed param);
void glMaterialxvOES(GLenum face, GLenum pname, GLfixed param);
void glMatrixFrustumEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
void glMatrixIndexPointerARB(GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void glMatrixIndexubvARB(GLint size, GLubyte indices);
void glMatrixIndexuivARB(GLint size, GLuint indices);
void glMatrixIndexusvARB(GLint size, GLushort indices);
void glMatrixLoadIdentityEXT(GLenum mode);
void glMatrixLoadTransposedEXT(GLenum mode, GLdouble m);
void glMatrixLoadTransposefEXT(GLenum mode, GLfloat m);
void glMatrixLoaddEXT(GLenum mode, GLdouble m);
void glMatrixLoadfEXT(GLenum mode, GLfloat m);
void glMatrixMode(GLenum mode);
void glMatrixMultTransposedEXT(GLenum mode, GLdouble m);
void glMatrixMultTransposefEXT(GLenum mode, GLfloat m);
void glMatrixMultdEXT(GLenum mode, GLdouble m);
void glMatrixMultfEXT(GLenum mode, GLfloat m);
void glMatrixOrthoEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
void glMatrixPopEXT(GLenum mode);
void glMatrixPushEXT(GLenum mode);
void glMatrixRotatedEXT(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
void glMatrixRotatefEXT(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
void glMatrixScaledEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
void glMatrixScalefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
void glMatrixTranslatedEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
void glMatrixTranslatefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
void glMemoryBarrier(GLbitfield barriers);
void glMemoryBarrierEXT(GLbitfield barriers);
void glMinSampleShading(GLfloat value);
void glMinSampleShadingARB(GLfloat value);
void glMinmax(GLenum target, GLenum internalformat, GLboolean sink);
void glMinmaxEXT(GLenum target, GLenum internalformat, GLboolean sink);
void glMultMatrixd(GLdouble m);
void glMultMatrixf(GLfloat m);
void glMultMatrixxOES(GLfixed m);
void glMultTransposeMatrixd(GLdouble m);
void glMultTransposeMatrixdARB(GLdouble m);
void glMultTransposeMatrixf(GLfloat m);
void glMultTransposeMatrixfARB(GLfloat m);
void glMultTransposeMatrixxOES(GLfixed m);
void glMultiDrawArrays(GLenum mode, GLint first, GLsizei count, GLsizei drawcount);
void glMultiDrawArraysEXT(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
void glMultiDrawArraysIndirect(GLenum mode, void * indirect, GLsizei drawcount, GLsizei stride);
void glMultiDrawArraysIndirectAMD(GLenum mode, GLvoid indirect, GLsizei primcount, GLsizei stride);
void glMultiDrawElementArrayAPPLE(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
void glMultiDrawElements(GLenum mode, GLsizei count, GLenum type, GLvoid*const indices, GLsizei drawcount);
void glMultiDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid*const indices, GLsizei drawcount, GLint basevertex);
void glMultiDrawElementsEXT(GLenum mode, GLsizei count, GLenum type, GLvoid * indices, GLsizei primcount);
void glMultiDrawElementsIndirect(GLenum mode, GLenum type, void * indirect, GLsizei drawcount, GLsizei stride);
void glMultiDrawElementsIndirectAMD(GLenum mode, GLenum type, GLvoid indirect, GLsizei primcount, GLsizei stride);
void glMultiDrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count, GLsizei primcount);
void glMultiModeDrawArraysIBM(GLenum mode, GLint first, GLsizei count, GLsizei primcount, GLint modestride);
void glMultiModeDrawElementsIBM(GLenum mode, GLsizei count, GLenum type, GLvoid*const indices, GLsizei primcount, GLint modestride);
void glMultiTexBufferEXT(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
void glMultiTexCoord1bOES(GLenum texture, GLbyte s);
void glMultiTexCoord1bvOES(GLenum texture, GLbyte coords);
void glMultiTexCoord1d(GLenum target, GLdouble s);
void glMultiTexCoord1dARB(GLenum target, GLdouble s);
void glMultiTexCoord1dv(GLenum target, GLdouble v);
void glMultiTexCoord1dvARB(GLenum target, GLdouble v);
void glMultiTexCoord1f(GLenum target, GLfloat s);
void glMultiTexCoord1fARB(GLenum target, GLfloat s);
void glMultiTexCoord1fv(GLenum target, GLfloat v);
void glMultiTexCoord1fvARB(GLenum target, GLfloat v);
void glMultiTexCoord1hNV(GLenum target, GLhalfNV s);
void glMultiTexCoord1hvNV(GLenum target, GLhalfNV v);
void glMultiTexCoord1i(GLenum target, GLint s);
void glMultiTexCoord1iARB(GLenum target, GLint s);
void glMultiTexCoord1iv(GLenum target, GLint v);
void glMultiTexCoord1ivARB(GLenum target, GLint v);
void glMultiTexCoord1s(GLenum target, GLshort s);
void glMultiTexCoord1sARB(GLenum target, GLshort s);
void glMultiTexCoord1sv(GLenum target, GLshort v);
void glMultiTexCoord1svARB(GLenum target, GLshort v);
void glMultiTexCoord1xOES(GLenum texture, GLfixed s);
void glMultiTexCoord1xvOES(GLenum texture, GLfixed coords);
void glMultiTexCoord2bOES(GLenum texture, GLbyte s, GLbyte t);
void glMultiTexCoord2bvOES(GLenum texture, GLbyte coords);
void glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t);
void glMultiTexCoord2dARB(GLenum target, GLdouble s, GLdouble t);
void glMultiTexCoord2dv(GLenum target, GLdouble v);
void glMultiTexCoord2dvARB(GLenum target, GLdouble v);
void glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t);
void glMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t);
void glMultiTexCoord2fv(GLenum target, GLfloat v);
void glMultiTexCoord2fvARB(GLenum target, GLfloat v);
void glMultiTexCoord2hNV(GLenum target, GLhalfNV s, GLhalfNV t);
void glMultiTexCoord2hvNV(GLenum target, GLhalfNV v);
void glMultiTexCoord2i(GLenum target, GLint s, GLint t);
void glMultiTexCoord2iARB(GLenum target, GLint s, GLint t);
void glMultiTexCoord2iv(GLenum target, GLint v);
void glMultiTexCoord2ivARB(GLenum target, GLint v);
void glMultiTexCoord2s(GLenum target, GLshort s, GLshort t);
void glMultiTexCoord2sARB(GLenum target, GLshort s, GLshort t);
void glMultiTexCoord2sv(GLenum target, GLshort v);
void glMultiTexCoord2svARB(GLenum target, GLshort v);
void glMultiTexCoord2xOES(GLenum texture, GLfixed s, GLfixed t);
void glMultiTexCoord2xvOES(GLenum texture, GLfixed coords);
void glMultiTexCoord3bOES(GLenum texture, GLbyte s, GLbyte t, GLbyte r);
void glMultiTexCoord3bvOES(GLenum texture, GLbyte coords);
void glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r);
void glMultiTexCoord3dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r);
void glMultiTexCoord3dv(GLenum target, GLdouble v);
void glMultiTexCoord3dvARB(GLenum target, GLdouble v);
void glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r);
void glMultiTexCoord3fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r);
void glMultiTexCoord3fv(GLenum target, GLfloat v);
void glMultiTexCoord3fvARB(GLenum target, GLfloat v);
void glMultiTexCoord3hNV(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r);
void glMultiTexCoord3hvNV(GLenum target, GLhalfNV v);
void glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r);
void glMultiTexCoord3iARB(GLenum target, GLint s, GLint t, GLint r);
void glMultiTexCoord3iv(GLenum target, GLint v);
void glMultiTexCoord3ivARB(GLenum target, GLint v);
void glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r);
void glMultiTexCoord3sARB(GLenum target, GLshort s, GLshort t, GLshort r);
void glMultiTexCoord3sv(GLenum target, GLshort v);
void glMultiTexCoord3svARB(GLenum target, GLshort v);
void glMultiTexCoord3xOES(GLenum texture, GLfixed s, GLfixed t, GLfixed r);
void glMultiTexCoord3xvOES(GLenum texture, GLfixed coords);
void glMultiTexCoord4bOES(GLenum texture, GLbyte s, GLbyte t, GLbyte r, GLbyte q);
void glMultiTexCoord4bvOES(GLenum texture, GLbyte coords);
void glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
void glMultiTexCoord4dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
void glMultiTexCoord4dv(GLenum target, GLdouble v);
void glMultiTexCoord4dvARB(GLenum target, GLdouble v);
void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void glMultiTexCoord4fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void glMultiTexCoord4fv(GLenum target, GLfloat v);
void glMultiTexCoord4fvARB(GLenum target, GLfloat v);
void glMultiTexCoord4hNV(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
void glMultiTexCoord4hvNV(GLenum target, GLhalfNV v);
void glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q);
void glMultiTexCoord4iARB(GLenum target, GLint s, GLint t, GLint r, GLint q);
void glMultiTexCoord4iv(GLenum target, GLint v);
void glMultiTexCoord4ivARB(GLenum target, GLint v);
void glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
void glMultiTexCoord4sARB(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
void glMultiTexCoord4sv(GLenum target, GLshort v);
void glMultiTexCoord4svARB(GLenum target, GLshort v);
void glMultiTexCoord4xOES(GLenum texture, GLfixed s, GLfixed t, GLfixed r, GLfixed q);
void glMultiTexCoord4xvOES(GLenum texture, GLfixed coords);
void glMultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords);
void glMultiTexCoordP1uiv(GLenum texture, GLenum type, GLuint coords);
void glMultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords);
void glMultiTexCoordP2uiv(GLenum texture, GLenum type, GLuint coords);
void glMultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords);
void glMultiTexCoordP3uiv(GLenum texture, GLenum type, GLuint coords);
void glMultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords);
void glMultiTexCoordP4uiv(GLenum texture, GLenum type, GLuint coords);
void glMultiTexCoordPointerEXT(GLenum texunit, GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void glMultiTexEnvfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
void glMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat params);
void glMultiTexEnviEXT(GLenum texunit, GLenum target, GLenum pname, GLint param);
void glMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint params);
void glMultiTexGendEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
void glMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble params);
void glMultiTexGenfEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
void glMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat params);
void glMultiTexGeniEXT(GLenum texunit, GLenum coord, GLenum pname, GLint param);
void glMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint params);
void glMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLenum format, GLenum type, GLvoid pixels);
void glMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, GLvoid pixels);
void glMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid pixels);
void glMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, GLint params);
void glMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, GLuint params);
void glMultiTexParameterfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
void glMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat params);
void glMultiTexParameteriEXT(GLenum texunit, GLenum target, GLenum pname, GLint param);
void glMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint params);
void glMultiTexRenderbufferEXT(GLenum texunit, GLenum target, GLuint renderbuffer);
void glMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid pixels);
void glMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels);
void glMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLvoid pixels);
void glNamedBufferDataEXT(GLuint buffer, GLsizeiptr size, GLvoid data, GLenum usage);
void glNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid data);
void glNamedCopyBufferSubDataEXT(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
void glNamedFramebufferParameteriEXT(GLuint framebuffer, GLenum pname, GLint param);
void glNamedFramebufferRenderbufferEXT(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
void glNamedFramebufferTexture1DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void glNamedFramebufferTexture2DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void glNamedFramebufferTexture3DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
void glNamedFramebufferTextureEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
void glNamedFramebufferTextureFaceEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
void glNamedFramebufferTextureLayerEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
void glNamedProgramLocalParameter4dEXT(GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glNamedProgramLocalParameter4dvEXT(GLuint program, GLenum target, GLuint index, GLdouble params);
void glNamedProgramLocalParameter4fEXT(GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glNamedProgramLocalParameter4fvEXT(GLuint program, GLenum target, GLuint index, GLfloat params);
void glNamedProgramLocalParameterI4iEXT(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
void glNamedProgramLocalParameterI4ivEXT(GLuint program, GLenum target, GLuint index, GLint params);
void glNamedProgramLocalParameterI4uiEXT(GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
void glNamedProgramLocalParameterI4uivEXT(GLuint program, GLenum target, GLuint index, GLuint params);
void glNamedProgramLocalParameters4fvEXT(GLuint program, GLenum target, GLuint index, GLsizei count, GLfloat params);
void glNamedProgramLocalParametersI4ivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, GLint params);
void glNamedProgramLocalParametersI4uivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, GLuint params);
void glNamedProgramStringEXT(GLuint program, GLenum target, GLenum format, GLsizei len, GLvoid string);
void glNamedRenderbufferStorageEXT(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
void glNamedRenderbufferStorageMultisampleCoverageEXT(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
void glNamedRenderbufferStorageMultisampleEXT(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
void glNamedStringARB(GLenum type, GLint namelen, GLchar name, GLint stringlen, GLchar string);
void glNewList(GLuint list, GLenum mode);
UInt32 glNewObjectBufferATI(GLsizei size, GLvoid pointer, GLenum usage);
void glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz);
void glNormal3bv(GLbyte v);
void glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz);
void glNormal3dv(GLdouble v);
void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz);
void glNormal3fVertex3fSUN(GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
void glNormal3fVertex3fvSUN(GLfloat n, GLfloat v);
void glNormal3fv(GLfloat v);
void glNormal3hNV(GLhalfNV nx, GLhalfNV ny, GLhalfNV nz);
void glNormal3hvNV(GLhalfNV v);
void glNormal3i(GLint nx, GLint ny, GLint nz);
void glNormal3iv(GLint v);
void glNormal3s(GLshort nx, GLshort ny, GLshort nz);
void glNormal3sv(GLshort v);
void glNormal3xOES(GLfixed nx, GLfixed ny, GLfixed nz);
void glNormal3xvOES(GLfixed coords);
void glNormalFormatNV(GLenum type, GLsizei stride);
void glNormalP3ui(GLenum type, GLuint coords);
void glNormalP3uiv(GLenum type, GLuint coords);
void glNormalPointer(GLenum type, GLsizei stride, GLvoid pointer);
void glNormalPointerEXT(GLenum type, GLsizei stride, GLsizei count, GLvoid pointer);
void glNormalPointerListIBM(GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride);
void glNormalPointervINTEL(GLenum type, GLvoid * pointer);
void glNormalStream3bATI(GLenum stream, GLbyte nx, GLbyte ny, GLbyte nz);
void glNormalStream3bvATI(GLenum stream, GLbyte coords);
void glNormalStream3dATI(GLenum stream, GLdouble nx, GLdouble ny, GLdouble nz);
void glNormalStream3dvATI(GLenum stream, GLdouble coords);
void glNormalStream3fATI(GLenum stream, GLfloat nx, GLfloat ny, GLfloat nz);
void glNormalStream3fvATI(GLenum stream, GLfloat coords);
void glNormalStream3iATI(GLenum stream, GLint nx, GLint ny, GLint nz);
void glNormalStream3ivATI(GLenum stream, GLint coords);
void glNormalStream3sATI(GLenum stream, GLshort nx, GLshort ny, GLshort nz);
void glNormalStream3svATI(GLenum stream, GLshort coords);
void glObjectLabel(GLenum identifier, GLuint name, GLsizei length, GLchar label);
void glObjectPtrLabel(void * ptr, GLsizei length, GLchar label);
GLenum glObjectPurgeableAPPLE(GLenum objectType, GLuint name, GLenum option);
GLenum glObjectUnpurgeableAPPLE(GLenum objectType, GLuint name, GLenum option);
void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
void glOrthofOES(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
void glOrthoxOES(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f);
void glPNTrianglesfATI(GLenum pname, GLfloat param);
void glPNTrianglesiATI(GLenum pname, GLint param);
void glPassTexCoordATI(GLuint dst, GLuint coord, GLenum swizzle);
void glPassThrough(GLfloat token);
void glPassThroughxOES(GLfixed token);
void glPatchParameterfv(GLenum pname, GLfloat values);
void glPatchParameteri(GLenum pname, GLint value);
void glPathColorGenNV(GLenum color, GLenum genMode, GLenum colorFormat, GLfloat coeffs);
void glPathCommandsNV(GLuint path, GLsizei numCommands, GLubyte commands, GLsizei numCoords, GLenum coordType, GLvoid coords);
void glPathCoordsNV(GLuint path, GLsizei numCoords, GLenum coordType, GLvoid coords);
void glPathCoverDepthFuncNV(GLenum func);
void glPathDashArrayNV(GLuint path, GLsizei dashCount, GLfloat dashArray);
void glPathFogGenNV(GLenum genMode);
void glPathGlyphRangeNV(GLuint firstPathName, GLenum fontTarget, GLvoid fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
void glPathGlyphsNV(GLuint firstPathName, GLenum fontTarget, GLvoid fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, GLvoid charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
void glPathParameterfNV(GLuint path, GLenum pname, GLfloat value);
void glPathParameterfvNV(GLuint path, GLenum pname, GLfloat value);
void glPathParameteriNV(GLuint path, GLenum pname, GLint value);
void glPathParameterivNV(GLuint path, GLenum pname, GLint value);
void glPathStencilDepthOffsetNV(GLfloat factor, GLfloat units);
void glPathStencilFuncNV(GLenum func, GLint ref, GLuint mask);
void glPathStringNV(GLuint path, GLenum format, GLsizei length, GLvoid pathString);
void glPathSubCommandsNV(GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, GLubyte commands, GLsizei numCoords, GLenum coordType, GLvoid coords);
void glPathSubCoordsNV(GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, GLvoid coords);
void glPathTexGenNV(GLenum texCoordSet, GLenum genMode, GLint components, GLfloat coeffs);
void glPauseTransformFeedback();
void glPauseTransformFeedbackNV();
void glPixelDataRangeNV(GLenum target, GLsizei length, GLvoid pointer);
void glPixelMapfv(GLenum map, GLsizei mapsize, GLfloat values);
void glPixelMapuiv(GLenum map, GLsizei mapsize, GLuint values);
void glPixelMapusv(GLenum map, GLsizei mapsize, GLushort values);
void glPixelMapx(GLenum map, GLint size, GLfixed values);
void glPixelStoref(GLenum pname, GLfloat param);
void glPixelStorei(GLenum pname, GLint param);
void glPixelStorex(GLenum pname, GLfixed param);
void glPixelTexGenParameterfSGIS(GLenum pname, GLfloat param);
void glPixelTexGenParameterfvSGIS(GLenum pname, GLfloat params);
void glPixelTexGenParameteriSGIS(GLenum pname, GLint param);
void glPixelTexGenParameterivSGIS(GLenum pname, GLint params);
void glPixelTexGenSGIX(GLenum mode);
void glPixelTransferf(GLenum pname, GLfloat param);
void glPixelTransferi(GLenum pname, GLint param);
void glPixelTransferxOES(GLenum pname, GLfixed param);
void glPixelTransformParameterfEXT(GLenum target, GLenum pname, GLfloat param);
void glPixelTransformParameterfvEXT(GLenum target, GLenum pname, GLfloat params);
void glPixelTransformParameteriEXT(GLenum target, GLenum pname, GLint param);
void glPixelTransformParameterivEXT(GLenum target, GLenum pname, GLint params);
void glPixelZoom(GLfloat xfactor, GLfloat yfactor);
void glPixelZoomxOES(GLfixed xfactor, GLfixed yfactor);
Boolean glPointAlongPathNV(GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat x, GLfloat y, GLfloat tangentX, GLfloat tangentY);
void glPointParameterf(GLenum pname, GLfloat param);
void glPointParameterfARB(GLenum pname, GLfloat param);
void glPointParameterfEXT(GLenum pname, GLfloat param);
void glPointParameterfSGIS(GLenum pname, GLfloat param);
void glPointParameterfv(GLenum pname, GLfloat params);
void glPointParameterfvARB(GLenum pname, GLfloat params);
void glPointParameterfvEXT(GLenum pname, GLfloat params);
void glPointParameterfvSGIS(GLenum pname, GLfloat params);
void glPointParameteri(GLenum pname, GLint param);
void glPointParameteriNV(GLenum pname, GLint param);
void glPointParameteriv(GLenum pname, GLint params);
void glPointParameterivNV(GLenum pname, GLint params);
void glPointParameterxvOES(GLenum pname, GLfixed params);
void glPointSize(GLfloat size);
void glPointSizexOES(GLfixed size);
Int32 glPollAsyncSGIX(GLuint markerp);
Int32 glPollInstrumentsSGIX(GLint marker_p);
void glPolygonMode(GLenum face, GLenum mode);
void glPolygonOffset(GLfloat factor, GLfloat units);
void glPolygonOffsetEXT(GLfloat factor, GLfloat bias);
void glPolygonOffsetxOES(GLfixed factor, GLfixed units);
void glPolygonStipple(GLubyte mask);
void glPopAttrib();
void glPopClientAttrib();
void glPopDebugGroup();
void glPopMatrix();
void glPopName();
void glPresentFrameDualFillNV(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLenum target1, GLuint fill1, GLenum target2, GLuint fill2, GLenum target3, GLuint fill3);
void glPresentFrameKeyedNV(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLuint key0, GLenum target1, GLuint fill1, GLuint key1);
void glPrimitiveRestartIndex(GLuint index);
void glPrimitiveRestartIndexNV(GLuint index);
void glPrimitiveRestartNV();
void glPrioritizeTextures(GLsizei n, GLuint textures, GLfloat priorities);
void glPrioritizeTexturesEXT(GLsizei n, GLuint textures, GLclampf priorities);
void glPrioritizeTexturesxOES(GLsizei n, GLuint textures, GLfixed priorities);
void glProgramBinary(GLuint program, GLenum binaryFormat, GLvoid binary, GLsizei length);
void glProgramBufferParametersIivNV(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, GLint params);
void glProgramBufferParametersIuivNV(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, GLuint params);
void glProgramBufferParametersfvNV(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, GLfloat params);
void glProgramEnvParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glProgramEnvParameter4dvARB(GLenum target, GLuint index, GLdouble params);
void glProgramEnvParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glProgramEnvParameter4fvARB(GLenum target, GLuint index, GLfloat params);
void glProgramEnvParameterI4iNV(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
void glProgramEnvParameterI4ivNV(GLenum target, GLuint index, GLint params);
void glProgramEnvParameterI4uiNV(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
void glProgramEnvParameterI4uivNV(GLenum target, GLuint index, GLuint params);
void glProgramEnvParameters4fvEXT(GLenum target, GLuint index, GLsizei count, GLfloat params);
void glProgramEnvParametersI4ivNV(GLenum target, GLuint index, GLsizei count, GLint params);
void glProgramEnvParametersI4uivNV(GLenum target, GLuint index, GLsizei count, GLuint params);
void glProgramLocalParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glProgramLocalParameter4dvARB(GLenum target, GLuint index, GLdouble params);
void glProgramLocalParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glProgramLocalParameter4fvARB(GLenum target, GLuint index, GLfloat params);
void glProgramLocalParameterI4iNV(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
void glProgramLocalParameterI4ivNV(GLenum target, GLuint index, GLint params);
void glProgramLocalParameterI4uiNV(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
void glProgramLocalParameterI4uivNV(GLenum target, GLuint index, GLuint params);
void glProgramLocalParameters4fvEXT(GLenum target, GLuint index, GLsizei count, GLfloat params);
void glProgramLocalParametersI4ivNV(GLenum target, GLuint index, GLsizei count, GLint params);
void glProgramLocalParametersI4uivNV(GLenum target, GLuint index, GLsizei count, GLuint params);
void glProgramNamedParameter4dNV(GLuint id, GLsizei len, GLubyte name, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glProgramNamedParameter4dvNV(GLuint id, GLsizei len, GLubyte name, GLdouble v);
void glProgramNamedParameter4fNV(GLuint id, GLsizei len, GLubyte name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glProgramNamedParameter4fvNV(GLuint id, GLsizei len, GLubyte name, GLfloat v);
void glProgramParameter4dNV(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glProgramParameter4dvNV(GLenum target, GLuint index, GLdouble v);
void glProgramParameter4fNV(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glProgramParameter4fvNV(GLenum target, GLuint index, GLfloat v);
void glProgramParameteri(GLuint program, GLenum pname, GLint value);
void glProgramParameteriARB(GLuint program, GLenum pname, GLint value);
void glProgramParameteriEXT(GLuint program, GLenum pname, GLint value);
void glProgramParameters4dvNV(GLenum target, GLuint index, GLsizei count, GLdouble v);
void glProgramParameters4fvNV(GLenum target, GLuint index, GLsizei count, GLfloat v);
void glProgramStringARB(GLenum target, GLenum format, GLsizei len, GLvoid string);
void glProgramSubroutineParametersuivNV(GLenum target, GLsizei count, GLuint params);
void glProgramUniform1d(GLuint program, GLint location, GLdouble v0);
void glProgramUniform1dEXT(GLuint program, GLint location, GLdouble x);
void glProgramUniform1dv(GLuint program, GLint location, GLsizei count, GLdouble value);
void glProgramUniform1dvEXT(GLuint program, GLint location, GLsizei count, GLdouble value);
void glProgramUniform1f(GLuint program, GLint location, GLfloat v0);
void glProgramUniform1fEXT(GLuint program, GLint location, GLfloat v0);
void glProgramUniform1fv(GLuint program, GLint location, GLsizei count, GLfloat value);
void glProgramUniform1fvEXT(GLuint program, GLint location, GLsizei count, GLfloat value);
void glProgramUniform1i(GLuint program, GLint location, GLint v0);
void glProgramUniform1i64NV(GLuint program, GLint location, GLint64EXT x);
void glProgramUniform1i64vNV(GLuint program, GLint location, GLsizei count, GLint64EXT value);
void glProgramUniform1iEXT(GLuint program, GLint location, GLint v0);
void glProgramUniform1iv(GLuint program, GLint location, GLsizei count, GLint value);
void glProgramUniform1ivEXT(GLuint program, GLint location, GLsizei count, GLint value);
void glProgramUniform1ui(GLuint program, GLint location, GLuint v0);
void glProgramUniform1ui64NV(GLuint program, GLint location, GLuint64EXT x);
void glProgramUniform1ui64vNV(GLuint program, GLint location, GLsizei count, GLuint64EXT value);
void glProgramUniform1uiEXT(GLuint program, GLint location, GLuint v0);
void glProgramUniform1uiv(GLuint program, GLint location, GLsizei count, GLuint value);
void glProgramUniform1uivEXT(GLuint program, GLint location, GLsizei count, GLuint value);
void glProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1);
void glProgramUniform2dEXT(GLuint program, GLint location, GLdouble x, GLdouble y);
void glProgramUniform2dv(GLuint program, GLint location, GLsizei count, GLdouble value);
void glProgramUniform2dvEXT(GLuint program, GLint location, GLsizei count, GLdouble value);
void glProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1);
void glProgramUniform2fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1);
void glProgramUniform2fv(GLuint program, GLint location, GLsizei count, GLfloat value);
void glProgramUniform2fvEXT(GLuint program, GLint location, GLsizei count, GLfloat value);
void glProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1);
void glProgramUniform2i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y);
void glProgramUniform2i64vNV(GLuint program, GLint location, GLsizei count, GLint64EXT value);
void glProgramUniform2iEXT(GLuint program, GLint location, GLint v0, GLint v1);
void glProgramUniform2iv(GLuint program, GLint location, GLsizei count, GLint value);
void glProgramUniform2ivEXT(GLuint program, GLint location, GLsizei count, GLint value);
void glProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1);
void glProgramUniform2ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y);
void glProgramUniform2ui64vNV(GLuint program, GLint location, GLsizei count, GLuint64EXT value);
void glProgramUniform2uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1);
void glProgramUniform2uiv(GLuint program, GLint location, GLsizei count, GLuint value);
void glProgramUniform2uivEXT(GLuint program, GLint location, GLsizei count, GLuint value);
void glProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
void glProgramUniform3dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
void glProgramUniform3dv(GLuint program, GLint location, GLsizei count, GLdouble value);
void glProgramUniform3dvEXT(GLuint program, GLint location, GLsizei count, GLdouble value);
void glProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void glProgramUniform3fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void glProgramUniform3fv(GLuint program, GLint location, GLsizei count, GLfloat value);
void glProgramUniform3fvEXT(GLuint program, GLint location, GLsizei count, GLfloat value);
void glProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
void glProgramUniform3i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
void glProgramUniform3i64vNV(GLuint program, GLint location, GLsizei count, GLint64EXT value);
void glProgramUniform3iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
void glProgramUniform3iv(GLuint program, GLint location, GLsizei count, GLint value);
void glProgramUniform3ivEXT(GLuint program, GLint location, GLsizei count, GLint value);
void glProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
void glProgramUniform3ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
void glProgramUniform3ui64vNV(GLuint program, GLint location, GLsizei count, GLuint64EXT value);
void glProgramUniform3uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
void glProgramUniform3uiv(GLuint program, GLint location, GLsizei count, GLuint value);
void glProgramUniform3uivEXT(GLuint program, GLint location, GLsizei count, GLuint value);
void glProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
void glProgramUniform4dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glProgramUniform4dv(GLuint program, GLint location, GLsizei count, GLdouble value);
void glProgramUniform4dvEXT(GLuint program, GLint location, GLsizei count, GLdouble value);
void glProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void glProgramUniform4fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void glProgramUniform4fv(GLuint program, GLint location, GLsizei count, GLfloat value);
void glProgramUniform4fvEXT(GLuint program, GLint location, GLsizei count, GLfloat value);
void glProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void glProgramUniform4i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
void glProgramUniform4i64vNV(GLuint program, GLint location, GLsizei count, GLint64EXT value);
void glProgramUniform4iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void glProgramUniform4iv(GLuint program, GLint location, GLsizei count, GLint value);
void glProgramUniform4ivEXT(GLuint program, GLint location, GLsizei count, GLint value);
void glProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
void glProgramUniform4ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
void glProgramUniform4ui64vNV(GLuint program, GLint location, GLsizei count, GLuint64EXT value);
void glProgramUniform4uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
void glProgramUniform4uiv(GLuint program, GLint location, GLsizei count, GLuint value);
void glProgramUniform4uivEXT(GLuint program, GLint location, GLsizei count, GLuint value);
void glProgramUniformHandleui64NV(GLuint program, GLint location, GLuint64 value);
void glProgramUniformHandleui64vNV(GLuint program, GLint location, GLsizei count, GLuint64 values);
void glProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glProgramUniformMatrix2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glProgramUniformMatrix2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glProgramUniformMatrix2x3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glProgramUniformMatrix2x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glProgramUniformMatrix2x4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glProgramUniformMatrix2x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glProgramUniformMatrix3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glProgramUniformMatrix3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glProgramUniformMatrix3x2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glProgramUniformMatrix3x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glProgramUniformMatrix3x4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glProgramUniformMatrix3x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glProgramUniformMatrix4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glProgramUniformMatrix4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glProgramUniformMatrix4x2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glProgramUniformMatrix4x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glProgramUniformMatrix4x3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glProgramUniformMatrix4x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glProgramUniformui64NV(GLuint program, GLint location, GLuint64EXT value);
void glProgramUniformui64vNV(GLuint program, GLint location, GLsizei count, GLuint64EXT value);
void glProgramVertexLimitNV(GLenum target, GLint limit);
void glProvokingVertex(GLenum mode);
void glProvokingVertexEXT(GLenum mode);
void glPushAttrib(GLbitfield mask);
void glPushClientAttrib(GLbitfield mask);
void glPushClientAttribDefaultEXT(GLbitfield mask);
void glPushDebugGroup(GLenum source, GLuint id, GLsizei length, GLchar message);
void glPushMatrix();
void glPushName(GLuint name);
void glQueryCounter(GLuint id, GLenum target);
GLbitfield glQueryMatrixxOES(GLfixed mantissa, GLint exponent);
void glRasterPos2d(GLdouble x, GLdouble y);
void glRasterPos2dv(GLdouble v);
void glRasterPos2f(GLfloat x, GLfloat y);
void glRasterPos2fv(GLfloat v);
void glRasterPos2i(GLint x, GLint y);
void glRasterPos2iv(GLint v);
void glRasterPos2s(GLshort x, GLshort y);
void glRasterPos2sv(GLshort v);
void glRasterPos2xOES(GLfixed x, GLfixed y);
void glRasterPos2xvOES(GLfixed coords);
void glRasterPos3d(GLdouble x, GLdouble y, GLdouble z);
void glRasterPos3dv(GLdouble v);
void glRasterPos3f(GLfloat x, GLfloat y, GLfloat z);
void glRasterPos3fv(GLfloat v);
void glRasterPos3i(GLint x, GLint y, GLint z);
void glRasterPos3iv(GLint v);
void glRasterPos3s(GLshort x, GLshort y, GLshort z);
void glRasterPos3sv(GLshort v);
void glRasterPos3xOES(GLfixed x, GLfixed y, GLfixed z);
void glRasterPos3xvOES(GLfixed coords);
void glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glRasterPos4dv(GLdouble v);
void glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glRasterPos4fv(GLfloat v);
void glRasterPos4i(GLint x, GLint y, GLint z, GLint w);
void glRasterPos4iv(GLint v);
void glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w);
void glRasterPos4sv(GLshort v);
void glRasterPos4xOES(GLfixed x, GLfixed y, GLfixed z, GLfixed w);
void glRasterPos4xvOES(GLfixed coords);
void glReadBuffer(GLenum mode);
void glReadInstrumentsSGIX(GLint marker);
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels);
void glReadnPixelsARB(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLvoid data);
void glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
void glRectdv(GLdouble v1, GLdouble v2);
void glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
void glRectfv(GLfloat v1, GLfloat v2);
void glRecti(GLint x1, GLint y1, GLint x2, GLint y2);
void glRectiv(GLint v1, GLint v2);
void glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
void glRectsv(GLshort v1, GLshort v2);
void glRectxOES(GLfixed x1, GLfixed y1, GLfixed x2, GLfixed y2);
void glRectxvOES(GLfixed v1, GLfixed v2);
void glReferencePlaneSGIX(GLdouble equation);
void glReleaseShaderCompiler();
Int32 glRenderMode(GLenum mode);
void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
void glRenderbufferStorageEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
void glRenderbufferStorageMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
void glRenderbufferStorageMultisampleEXT(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
void glReplacementCodePointerSUN(GLenum type, GLsizei stride, GLvoid * pointer);
void glReplacementCodeubSUN(GLubyte code);
void glReplacementCodeubvSUN(GLubyte code);
void glReplacementCodeuiColor3fVertex3fSUN(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
void glReplacementCodeuiColor3fVertex3fvSUN(GLuint rc, GLfloat c, GLfloat v);
void glReplacementCodeuiColor4fNormal3fVertex3fSUN(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
void glReplacementCodeuiColor4fNormal3fVertex3fvSUN(GLuint rc, GLfloat c, GLfloat n, GLfloat v);
void glReplacementCodeuiColor4ubVertex3fSUN(GLuint rc, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
void glReplacementCodeuiColor4ubVertex3fvSUN(GLuint rc, GLubyte c, GLfloat v);
void glReplacementCodeuiNormal3fVertex3fSUN(GLuint rc, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
void glReplacementCodeuiNormal3fVertex3fvSUN(GLuint rc, GLfloat n, GLfloat v);
void glReplacementCodeuiSUN(GLuint code);
void glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
void glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN(GLuint rc, GLfloat tc, GLfloat c, GLfloat n, GLfloat v);
void glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
void glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN(GLuint rc, GLfloat tc, GLfloat n, GLfloat v);
void glReplacementCodeuiTexCoord2fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
void glReplacementCodeuiTexCoord2fVertex3fvSUN(GLuint rc, GLfloat tc, GLfloat v);
void glReplacementCodeuiVertex3fSUN(GLuint rc, GLfloat x, GLfloat y, GLfloat z);
void glReplacementCodeuiVertex3fvSUN(GLuint rc, GLfloat v);
void glReplacementCodeuivSUN(GLuint code);
void glReplacementCodeusSUN(GLushort code);
void glReplacementCodeusvSUN(GLushort code);
void glRequestResidentProgramsNV(GLsizei n, GLuint programs);
void glResetHistogram(GLenum target);
void glResetHistogramEXT(GLenum target);
void glResetMinmax(GLenum target);
void glResetMinmaxEXT(GLenum target);
void glResizeBuffersMESA();
void glResumeTransformFeedback();
void glResumeTransformFeedbackNV();
void glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
void glRotatexOES(GLfixed angle, GLfixed x, GLfixed y, GLfixed z);
void glSampleCoverage(GLfloat value, GLboolean invert);
void glSampleCoverageARB(GLfloat value, GLboolean invert);
void glSampleCoverageOES(GLfixed value, GLboolean invert);
void glSampleMapATI(GLuint dst, GLuint interp, GLenum swizzle);
void glSampleMaskEXT(GLclampf value, GLboolean invert);
void glSampleMaskIndexedNV(GLuint index, GLbitfield mask);
void glSampleMaskSGIS(GLclampf value, GLboolean invert);
void glSampleMaski(GLuint index, GLbitfield mask);
void glSamplePatternEXT(GLenum pattern);
void glSamplePatternSGIS(GLenum pattern);
void glSamplerParameterIiv(GLuint sampler, GLenum pname, GLint param);
void glSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint param);
void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param);
void glSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat param);
void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param);
void glSamplerParameteriv(GLuint sampler, GLenum pname, GLint param);
void glScaled(GLdouble x, GLdouble y, GLdouble z);
void glScalef(GLfloat x, GLfloat y, GLfloat z);
void glScalexOES(GLfixed x, GLfixed y, GLfixed z);
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
void glScissorArrayv(GLuint first, GLsizei count, GLint v);
void glScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
void glScissorIndexedv(GLuint index, GLint v);
void glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue);
void glSecondaryColor3bEXT(GLbyte red, GLbyte green, GLbyte blue);
void glSecondaryColor3bv(GLbyte v);
void glSecondaryColor3bvEXT(GLbyte v);
void glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue);
void glSecondaryColor3dEXT(GLdouble red, GLdouble green, GLdouble blue);
void glSecondaryColor3dv(GLdouble v);
void glSecondaryColor3dvEXT(GLdouble v);
void glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue);
void glSecondaryColor3fEXT(GLfloat red, GLfloat green, GLfloat blue);
void glSecondaryColor3fv(GLfloat v);
void glSecondaryColor3fvEXT(GLfloat v);
void glSecondaryColor3hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue);
void glSecondaryColor3hvNV(GLhalfNV v);
void glSecondaryColor3i(GLint red, GLint green, GLint blue);
void glSecondaryColor3iEXT(GLint red, GLint green, GLint blue);
void glSecondaryColor3iv(GLint v);
void glSecondaryColor3ivEXT(GLint v);
void glSecondaryColor3s(GLshort red, GLshort green, GLshort blue);
void glSecondaryColor3sEXT(GLshort red, GLshort green, GLshort blue);
void glSecondaryColor3sv(GLshort v);
void glSecondaryColor3svEXT(GLshort v);
void glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue);
void glSecondaryColor3ubEXT(GLubyte red, GLubyte green, GLubyte blue);
void glSecondaryColor3ubv(GLubyte v);
void glSecondaryColor3ubvEXT(GLubyte v);
void glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue);
void glSecondaryColor3uiEXT(GLuint red, GLuint green, GLuint blue);
void glSecondaryColor3uiv(GLuint v);
void glSecondaryColor3uivEXT(GLuint v);
void glSecondaryColor3us(GLushort red, GLushort green, GLushort blue);
void glSecondaryColor3usEXT(GLushort red, GLushort green, GLushort blue);
void glSecondaryColor3usv(GLushort v);
void glSecondaryColor3usvEXT(GLushort v);
void glSecondaryColorFormatNV(GLint size, GLenum type, GLsizei stride);
void glSecondaryColorP3ui(GLenum type, GLuint color);
void glSecondaryColorP3uiv(GLenum type, GLuint color);
void glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void glSecondaryColorPointerEXT(GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void glSecondaryColorPointerListIBM(GLint size, GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride);
void glSelectBuffer(GLsizei size, GLuint buffer);
void glSelectPerfMonitorCountersAMD(GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint counterList);
void glSeparableFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid row, GLvoid column);
void glSeparableFilter2DEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid row, GLvoid column);
void glSetFenceAPPLE(GLuint fence);
void glSetFenceNV(GLuint fence, GLenum condition);
void glSetFragmentShaderConstantATI(GLuint dst, GLfloat value);
void glSetInvariantEXT(GLuint id, GLenum type, GLvoid addr);
void glSetLocalConstantEXT(GLuint id, GLenum type, GLvoid addr);
void glSetMultisamplefvAMD(GLenum pname, GLuint index, GLfloat val);
void glShadeModel(GLenum mode);
void glShaderBinary(GLsizei count, GLuint shaders, GLenum binaryformat, GLvoid binary, GLsizei length);
void glShaderOp1EXT(GLenum op, GLuint res, GLuint arg1);
void glShaderOp2EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2);
void glShaderOp3EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3);
void glShaderSource(GLuint shader, GLsizei count, GLchar*const string, GLint length);
void glShaderSourceARB(GLhandleARB shaderObj, GLsizei count, GLcharARB * string, GLint length);
void glShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
void glSharpenTexFuncSGIS(GLenum target, GLsizei n, GLfloat points);
void glSpriteParameterfSGIX(GLenum pname, GLfloat param);
void glSpriteParameterfvSGIX(GLenum pname, GLfloat params);
void glSpriteParameteriSGIX(GLenum pname, GLint param);
void glSpriteParameterivSGIX(GLenum pname, GLint params);
void glStartInstrumentsSGIX();
void glStencilClearTagEXT(GLsizei stencilTagBits, GLuint stencilClearTag);
void glStencilFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, GLfloat transformValues);
void glStencilFillPathNV(GLuint path, GLenum fillMode, GLuint mask);
void glStencilFunc(GLenum func, GLint ref, GLuint mask);
void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask);
void glStencilFuncSeparateATI(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);
void glStencilMask(GLuint mask);
void glStencilMaskSeparate(GLenum face, GLuint mask);
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass);
void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
void glStencilOpSeparateATI(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
void glStencilOpValueAMD(GLenum face, GLuint value);
void glStencilStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, GLfloat transformValues);
void glStencilStrokePathNV(GLuint path, GLint reference, GLuint mask);
void glStopInstrumentsSGIX(GLint marker);
void glStringMarkerGREMEDY(GLsizei len, GLvoid string);
void glSwizzleEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
void glSyncTextureINTEL(GLuint texture);
void glTagSampleBufferSGIX();
void glTangent3bEXT(GLbyte tx, GLbyte ty, GLbyte tz);
void glTangent3bvEXT(GLbyte v);
void glTangent3dEXT(GLdouble tx, GLdouble ty, GLdouble tz);
void glTangent3dvEXT(GLdouble v);
void glTangent3fEXT(GLfloat tx, GLfloat ty, GLfloat tz);
void glTangent3fvEXT(GLfloat v);
void glTangent3iEXT(GLint tx, GLint ty, GLint tz);
void glTangent3ivEXT(GLint v);
void glTangent3sEXT(GLshort tx, GLshort ty, GLshort tz);
void glTangent3svEXT(GLshort v);
void glTangentPointerEXT(GLenum type, GLsizei stride, GLvoid pointer);
void glTbufferMask3DFX(GLuint mask);
void glTessellationFactorAMD(GLfloat factor);
void glTessellationModeAMD(GLenum mode);
Boolean glTestFenceAPPLE(GLuint fence);
Boolean glTestFenceNV(GLuint fence);
Boolean glTestObjectAPPLE(GLenum object, GLuint name);
void glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer);
void glTexBufferARB(GLenum target, GLenum internalformat, GLuint buffer);
void glTexBufferEXT(GLenum target, GLenum internalformat, GLuint buffer);
void glTexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
void glTexBumpParameterfvATI(GLenum pname, GLfloat param);
void glTexBumpParameterivATI(GLenum pname, GLint param);
void glTexCoord1bOES(GLbyte s);
void glTexCoord1bvOES(GLbyte coords);
void glTexCoord1d(GLdouble s);
void glTexCoord1dv(GLdouble v);
void glTexCoord1f(GLfloat s);
void glTexCoord1fv(GLfloat v);
void glTexCoord1hNV(GLhalfNV s);
void glTexCoord1hvNV(GLhalfNV v);
void glTexCoord1i(GLint s);
void glTexCoord1iv(GLint v);
void glTexCoord1s(GLshort s);
void glTexCoord1sv(GLshort v);
void glTexCoord1xOES(GLfixed s);
void glTexCoord1xvOES(GLfixed coords);
void glTexCoord2bOES(GLbyte s, GLbyte t);
void glTexCoord2bvOES(GLbyte coords);
void glTexCoord2d(GLdouble s, GLdouble t);
void glTexCoord2dv(GLdouble v);
void glTexCoord2f(GLfloat s, GLfloat t);
void glTexCoord2fColor3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
void glTexCoord2fColor3fVertex3fvSUN(GLfloat tc, GLfloat c, GLfloat v);
void glTexCoord2fColor4fNormal3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
void glTexCoord2fColor4fNormal3fVertex3fvSUN(GLfloat tc, GLfloat c, GLfloat n, GLfloat v);
void glTexCoord2fColor4ubVertex3fSUN(GLfloat s, GLfloat t, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
void glTexCoord2fColor4ubVertex3fvSUN(GLfloat tc, GLubyte c, GLfloat v);
void glTexCoord2fNormal3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
void glTexCoord2fNormal3fVertex3fvSUN(GLfloat tc, GLfloat n, GLfloat v);
void glTexCoord2fVertex3fSUN(GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
void glTexCoord2fVertex3fvSUN(GLfloat tc, GLfloat v);
void glTexCoord2fv(GLfloat v);
void glTexCoord2hNV(GLhalfNV s, GLhalfNV t);
void glTexCoord2hvNV(GLhalfNV v);
void glTexCoord2i(GLint s, GLint t);
void glTexCoord2iv(GLint v);
void glTexCoord2s(GLshort s, GLshort t);
void glTexCoord2sv(GLshort v);
void glTexCoord2xOES(GLfixed s, GLfixed t);
void glTexCoord2xvOES(GLfixed coords);
void glTexCoord3bOES(GLbyte s, GLbyte t, GLbyte r);
void glTexCoord3bvOES(GLbyte coords);
void glTexCoord3d(GLdouble s, GLdouble t, GLdouble r);
void glTexCoord3dv(GLdouble v);
void glTexCoord3f(GLfloat s, GLfloat t, GLfloat r);
void glTexCoord3fv(GLfloat v);
void glTexCoord3hNV(GLhalfNV s, GLhalfNV t, GLhalfNV r);
void glTexCoord3hvNV(GLhalfNV v);
void glTexCoord3i(GLint s, GLint t, GLint r);
void glTexCoord3iv(GLint v);
void glTexCoord3s(GLshort s, GLshort t, GLshort r);
void glTexCoord3sv(GLshort v);
void glTexCoord3xOES(GLfixed s, GLfixed t, GLfixed r);
void glTexCoord3xvOES(GLfixed coords);
void glTexCoord4bOES(GLbyte s, GLbyte t, GLbyte r, GLbyte q);
void glTexCoord4bvOES(GLbyte coords);
void glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
void glTexCoord4dv(GLdouble v);
void glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void glTexCoord4fColor4fNormal3fVertex4fSUN(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glTexCoord4fColor4fNormal3fVertex4fvSUN(GLfloat tc, GLfloat c, GLfloat n, GLfloat v);
void glTexCoord4fVertex4fSUN(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glTexCoord4fVertex4fvSUN(GLfloat tc, GLfloat v);
void glTexCoord4fv(GLfloat v);
void glTexCoord4hNV(GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
void glTexCoord4hvNV(GLhalfNV v);
void glTexCoord4i(GLint s, GLint t, GLint r, GLint q);
void glTexCoord4iv(GLint v);
void glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q);
void glTexCoord4sv(GLshort v);
void glTexCoord4xOES(GLfixed s, GLfixed t, GLfixed r, GLfixed q);
void glTexCoord4xvOES(GLfixed coords);
void glTexCoordFormatNV(GLint size, GLenum type, GLsizei stride);
void glTexCoordP1ui(GLenum type, GLuint coords);
void glTexCoordP1uiv(GLenum type, GLuint coords);
void glTexCoordP2ui(GLenum type, GLuint coords);
void glTexCoordP2uiv(GLenum type, GLuint coords);
void glTexCoordP3ui(GLenum type, GLuint coords);
void glTexCoordP3uiv(GLenum type, GLuint coords);
void glTexCoordP4ui(GLenum type, GLuint coords);
void glTexCoordP4uiv(GLenum type, GLuint coords);
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void glTexCoordPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, GLvoid pointer);
void glTexCoordPointerListIBM(GLint size, GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride);
void glTexCoordPointervINTEL(GLint size, GLenum type, GLvoid * pointer);
void glTexEnvf(GLenum target, GLenum pname, GLfloat param);
void glTexEnvfv(GLenum target, GLenum pname, GLfloat params);
void glTexEnvi(GLenum target, GLenum pname, GLint param);
void glTexEnviv(GLenum target, GLenum pname, GLint params);
void glTexEnvxOES(GLenum target, GLenum pname, GLfixed param);
void glTexEnvxvOES(GLenum target, GLenum pname, GLfixed params);
void glTexFilterFuncSGIS(GLenum target, GLenum filter, GLsizei n, GLfloat weights);
void glTexGend(GLenum coord, GLenum pname, GLdouble param);
void glTexGendv(GLenum coord, GLenum pname, GLdouble params);
void glTexGenf(GLenum coord, GLenum pname, GLfloat param);
void glTexGenfv(GLenum coord, GLenum pname, GLfloat params);
void glTexGeni(GLenum coord, GLenum pname, GLint param);
void glTexGeniv(GLenum coord, GLenum pname, GLint params);
void glTexGenxOES(GLenum coord, GLenum pname, GLfixed param);
void glTexGenxvOES(GLenum coord, GLenum pname, GLfixed params);
void glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, GLvoid pixels);
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, GLvoid pixels);
void glTexImage2DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
void glTexImage2DMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid pixels);
void glTexImage3DEXT(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid pixels);
void glTexImage3DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
void glTexImage3DMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
void glTexImage4DSGIS(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLint border, GLenum format, GLenum type, GLvoid pixels);
void glTexParameterIiv(GLenum target, GLenum pname, GLint params);
void glTexParameterIivEXT(GLenum target, GLenum pname, GLint params);
void glTexParameterIuiv(GLenum target, GLenum pname, GLuint params);
void glTexParameterIuivEXT(GLenum target, GLenum pname, GLuint params);
void glTexParameterf(GLenum target, GLenum pname, GLfloat param);
void glTexParameterfv(GLenum target, GLenum pname, GLfloat params);
void glTexParameteri(GLenum target, GLenum pname, GLint param);
void glTexParameteriv(GLenum target, GLenum pname, GLint params);
void glTexParameterxOES(GLenum target, GLenum pname, GLfixed param);
void glTexParameterxvOES(GLenum target, GLenum pname, GLfixed params);
void glTexRenderbufferNV(GLenum target, GLuint renderbuffer);
void glTexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
void glTexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
void glTexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
void glTexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
void glTexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
void glTexStorageSparseAMD(GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags);
void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid pixels);
void glTexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid pixels);
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels);
void glTexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels);
void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLvoid pixels);
void glTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLvoid pixels);
void glTexSubImage4DSGIS(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint woffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLenum format, GLenum type, GLvoid pixels);
void glTextureBarrierNV();
void glTextureBufferEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
void glTextureBufferRangeEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
void glTextureColorMaskSGIS(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
void glTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLenum format, GLenum type, GLvoid pixels);
void glTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, GLvoid pixels);
void glTextureImage2DMultisampleCoverageNV(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
void glTextureImage2DMultisampleNV(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
void glTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid pixels);
void glTextureImage3DMultisampleCoverageNV(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
void glTextureImage3DMultisampleNV(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
void glTextureLightEXT(GLenum pname);
void glTextureMaterialEXT(GLenum face, GLenum mode);
void glTextureNormalEXT(GLenum mode);
void glTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, GLint params);
void glTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, GLuint params);
void glTextureParameterfEXT(GLuint texture, GLenum target, GLenum pname, GLfloat param);
void glTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat params);
void glTextureParameteriEXT(GLuint texture, GLenum target, GLenum pname, GLint param);
void glTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint params);
void glTextureRangeAPPLE(GLenum target, GLsizei length, GLvoid pointer);
void glTextureRenderbufferEXT(GLuint texture, GLenum target, GLuint renderbuffer);
void glTextureStorage1DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
void glTextureStorage2DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
void glTextureStorage2DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
void glTextureStorage3DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
void glTextureStorage3DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
void glTextureStorageSparseAMD(GLuint texture, GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags);
void glTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid pixels);
void glTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels);
void glTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLvoid pixels);
void glTextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
void glTrackMatrixNV(GLenum target, GLuint address, GLenum matrix, GLenum transform);
void glTransformFeedbackAttribsNV(GLsizei count, GLint attribs, GLenum bufferMode);
void glTransformFeedbackStreamAttribsNV(GLsizei count, GLint attribs, GLsizei nbuffers, GLint bufstreams, GLenum bufferMode);
void glTransformFeedbackVaryings(GLuint program, GLsizei count, GLchar*const varyings, GLenum bufferMode);
void glTransformFeedbackVaryingsEXT(GLuint program, GLsizei count, GLchar * varyings, GLenum bufferMode);
void glTransformFeedbackVaryingsNV(GLuint program, GLsizei count, GLint locations, GLenum bufferMode);
void glTransformPathNV(GLuint resultPath, GLuint srcPath, GLenum transformType, GLfloat transformValues);
void glTranslated(GLdouble x, GLdouble y, GLdouble z);
void glTranslatef(GLfloat x, GLfloat y, GLfloat z);
void glTranslatexOES(GLfixed x, GLfixed y, GLfixed z);
void glUniform1d(GLint location, GLdouble x);
void glUniform1dv(GLint location, GLsizei count, GLdouble value);
void glUniform1f(GLint location, GLfloat v0);
void glUniform1fARB(GLint location, GLfloat v0);
void glUniform1fv(GLint location, GLsizei count, GLfloat value);
void glUniform1fvARB(GLint location, GLsizei count, GLfloat value);
void glUniform1i(GLint location, GLint v0);
void glUniform1i64NV(GLint location, GLint64EXT x);
void glUniform1i64vNV(GLint location, GLsizei count, GLint64EXT value);
void glUniform1iARB(GLint location, GLint v0);
void glUniform1iv(GLint location, GLsizei count, GLint value);
void glUniform1ivARB(GLint location, GLsizei count, GLint value);
void glUniform1ui(GLint location, GLuint v0);
void glUniform1ui64NV(GLint location, GLuint64EXT x);
void glUniform1ui64vNV(GLint location, GLsizei count, GLuint64EXT value);
void glUniform1uiEXT(GLint location, GLuint v0);
void glUniform1uiv(GLint location, GLsizei count, GLuint value);
void glUniform1uivEXT(GLint location, GLsizei count, GLuint value);
void glUniform2d(GLint location, GLdouble x, GLdouble y);
void glUniform2dv(GLint location, GLsizei count, GLdouble value);
void glUniform2f(GLint location, GLfloat v0, GLfloat v1);
void glUniform2fARB(GLint location, GLfloat v0, GLfloat v1);
void glUniform2fv(GLint location, GLsizei count, GLfloat value);
void glUniform2fvARB(GLint location, GLsizei count, GLfloat value);
void glUniform2i(GLint location, GLint v0, GLint v1);
void glUniform2i64NV(GLint location, GLint64EXT x, GLint64EXT y);
void glUniform2i64vNV(GLint location, GLsizei count, GLint64EXT value);
void glUniform2iARB(GLint location, GLint v0, GLint v1);
void glUniform2iv(GLint location, GLsizei count, GLint value);
void glUniform2ivARB(GLint location, GLsizei count, GLint value);
void glUniform2ui(GLint location, GLuint v0, GLuint v1);
void glUniform2ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y);
void glUniform2ui64vNV(GLint location, GLsizei count, GLuint64EXT value);
void glUniform2uiEXT(GLint location, GLuint v0, GLuint v1);
void glUniform2uiv(GLint location, GLsizei count, GLuint value);
void glUniform2uivEXT(GLint location, GLsizei count, GLuint value);
void glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z);
void glUniform3dv(GLint location, GLsizei count, GLdouble value);
void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void glUniform3fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void glUniform3fv(GLint location, GLsizei count, GLfloat value);
void glUniform3fvARB(GLint location, GLsizei count, GLfloat value);
void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2);
void glUniform3i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
void glUniform3i64vNV(GLint location, GLsizei count, GLint64EXT value);
void glUniform3iARB(GLint location, GLint v0, GLint v1, GLint v2);
void glUniform3iv(GLint location, GLsizei count, GLint value);
void glUniform3ivARB(GLint location, GLsizei count, GLint value);
void glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2);
void glUniform3ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
void glUniform3ui64vNV(GLint location, GLsizei count, GLuint64EXT value);
void glUniform3uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2);
void glUniform3uiv(GLint location, GLsizei count, GLuint value);
void glUniform3uivEXT(GLint location, GLsizei count, GLuint value);
void glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glUniform4dv(GLint location, GLsizei count, GLdouble value);
void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void glUniform4fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void glUniform4fv(GLint location, GLsizei count, GLfloat value);
void glUniform4fvARB(GLint location, GLsizei count, GLfloat value);
void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void glUniform4i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
void glUniform4i64vNV(GLint location, GLsizei count, GLint64EXT value);
void glUniform4iARB(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void glUniform4iv(GLint location, GLsizei count, GLint value);
void glUniform4ivARB(GLint location, GLsizei count, GLint value);
void glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
void glUniform4ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
void glUniform4ui64vNV(GLint location, GLsizei count, GLuint64EXT value);
void glUniform4uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
void glUniform4uiv(GLint location, GLsizei count, GLuint value);
void glUniform4uivEXT(GLint location, GLsizei count, GLuint value);
void glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
void glUniformBufferEXT(GLuint program, GLint location, GLuint buffer);
void glUniformHandleui64NV(GLint location, GLuint64 value);
void glUniformHandleui64vNV(GLint location, GLsizei count, GLuint64 value);
void glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glUniformMatrix2fvARB(GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glUniformMatrix3fvARB(GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glUniformMatrix4fvARB(GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, GLuint indices);
void glUniformui64NV(GLint location, GLuint64EXT value);
void glUniformui64vNV(GLint location, GLsizei count, GLuint64EXT value);
void glUnlockArraysEXT();
Boolean glUnmapBuffer(GLenum target);
Boolean glUnmapBufferARB(GLenum target);
Boolean glUnmapNamedBufferEXT(GLuint buffer);
void glUnmapObjectBufferATI(GLuint buffer);
void glUnmapTexture2DINTEL(GLuint texture, GLint level);
void glUpdateObjectBufferATI(GLuint buffer, GLuint offset, GLsizei size, GLvoid pointer, GLenum preserve);
void glUseProgram(GLuint program);
void glUseProgramObjectARB(GLhandleARB programObj);
void glUseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program);
void glUseShaderProgramEXT(GLenum type, GLuint program);
void glVDPAUFiniNV();
void glVDPAUGetSurfaceivNV(GLvdpauSurfaceNV surface, GLenum pname, GLsizei bufSize, GLsizei length, GLint values);
void glVDPAUInitNV(GLvoid vdpDevice, GLvoid getProcAddress);
void glVDPAUIsSurfaceNV(GLvdpauSurfaceNV surface);
void glVDPAUMapSurfacesNV(GLsizei numSurfaces, GLvdpauSurfaceNV surfaces);
vdpauSurfaceNV glVDPAURegisterOutputSurfaceNV(GLvoid * vdpSurface, GLenum target, GLsizei numTextureNames, GLuint textureNames);
vdpauSurfaceNV glVDPAURegisterVideoSurfaceNV(GLvoid vdpSurface, GLenum target, GLsizei numTextureNames, GLuint textureNames);
void glVDPAUSurfaceAccessNV(GLvdpauSurfaceNV surface, GLenum access);
void glVDPAUUnmapSurfacesNV(GLsizei numSurface, GLvdpauSurfaceNV surfaces);
void glVDPAUUnregisterSurfaceNV(GLvdpauSurfaceNV surface);
void glValidateProgram(GLuint program);
void glValidateProgramARB(GLhandleARB programObj);
void glValidateProgramPipeline(GLuint pipeline);
void glVariantArrayObjectATI(GLuint id, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
void glVariantPointerEXT(GLuint id, GLenum type, GLuint stride, GLvoid addr);
void glVariantbvEXT(GLuint id, GLbyte addr);
void glVariantdvEXT(GLuint id, GLdouble addr);
void glVariantfvEXT(GLuint id, GLfloat addr);
void glVariantivEXT(GLuint id, GLint addr);
void glVariantsvEXT(GLuint id, GLshort addr);
void glVariantubvEXT(GLuint id, GLubyte addr);
void glVariantuivEXT(GLuint id, GLuint addr);
void glVariantusvEXT(GLuint id, GLushort addr);
void glVertex2bOES(GLbyte x);
void glVertex2bvOES(GLbyte coords);
void glVertex2d(GLdouble x, GLdouble y);
void glVertex2dv(GLdouble v);
void glVertex2f(GLfloat x, GLfloat y);
void glVertex2fv(GLfloat v);
void glVertex2hNV(GLhalfNV x, GLhalfNV y);
void glVertex2hvNV(GLhalfNV v);
void glVertex2i(GLint x, GLint y);
void glVertex2iv(GLint v);
void glVertex2s(GLshort x, GLshort y);
void glVertex2sv(GLshort v);
void glVertex2xOES(GLfixed x);
void glVertex2xvOES(GLfixed coords);
void glVertex3bOES(GLbyte x, GLbyte y);
void glVertex3bvOES(GLbyte coords);
void glVertex3d(GLdouble x, GLdouble y, GLdouble z);
void glVertex3dv(GLdouble v);
void glVertex3f(GLfloat x, GLfloat y, GLfloat z);
void glVertex3fv(GLfloat v);
void glVertex3hNV(GLhalfNV x, GLhalfNV y, GLhalfNV z);
void glVertex3hvNV(GLhalfNV v);
void glVertex3i(GLint x, GLint y, GLint z);
void glVertex3iv(GLint v);
void glVertex3s(GLshort x, GLshort y, GLshort z);
void glVertex3sv(GLshort v);
void glVertex3xOES(GLfixed x, GLfixed y);
void glVertex3xvOES(GLfixed coords);
void glVertex4bOES(GLbyte x, GLbyte y, GLbyte z);
void glVertex4bvOES(GLbyte coords);
void glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glVertex4dv(GLdouble v);
void glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glVertex4fv(GLfloat v);
void glVertex4hNV(GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
void glVertex4hvNV(GLhalfNV v);
void glVertex4i(GLint x, GLint y, GLint z, GLint w);
void glVertex4iv(GLint v);
void glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w);
void glVertex4sv(GLshort v);
void glVertex4xOES(GLfixed x, GLfixed y, GLfixed z);
void glVertex4xvOES(GLfixed coords);
void glVertexArrayBindVertexBufferEXT(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
void glVertexArrayColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
void glVertexArrayEdgeFlagOffsetEXT(GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset);
void glVertexArrayFogCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
void glVertexArrayIndexOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
void glVertexArrayMultiTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset);
void glVertexArrayNormalOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
void glVertexArrayParameteriAPPLE(GLenum pname, GLint param);
void glVertexArrayRangeAPPLE(GLsizei length, GLvoid pointer);
void glVertexArrayRangeNV(GLsizei length, GLvoid pointer);
void glVertexArraySecondaryColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
void glVertexArrayTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
void glVertexArrayVertexAttribBindingEXT(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
void glVertexArrayVertexAttribFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
void glVertexArrayVertexAttribIFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
void glVertexArrayVertexAttribIOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
void glVertexArrayVertexAttribLFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
void glVertexArrayVertexAttribLOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
void glVertexArrayVertexAttribOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset);
void glVertexArrayVertexBindingDivisorEXT(GLuint vaobj, GLuint bindingindex, GLuint divisor);
void glVertexArrayVertexOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
void glVertexAttrib1d(GLuint index, GLdouble x);
void glVertexAttrib1dARB(GLuint index, GLdouble x);
void glVertexAttrib1dNV(GLuint index, GLdouble x);
void glVertexAttrib1dv(GLuint index, GLdouble v);
void glVertexAttrib1dvARB(GLuint index, GLdouble v);
void glVertexAttrib1dvNV(GLuint index, GLdouble v);
void glVertexAttrib1f(GLuint index, GLfloat x);
void glVertexAttrib1fARB(GLuint index, GLfloat x);
void glVertexAttrib1fNV(GLuint index, GLfloat x);
void glVertexAttrib1fv(GLuint index, GLfloat v);
void glVertexAttrib1fvARB(GLuint index, GLfloat v);
void glVertexAttrib1fvNV(GLuint index, GLfloat v);
void glVertexAttrib1hNV(GLuint index, GLhalfNV x);
void glVertexAttrib1hvNV(GLuint index, GLhalfNV v);
void glVertexAttrib1s(GLuint index, GLshort x);
void glVertexAttrib1sARB(GLuint index, GLshort x);
void glVertexAttrib1sNV(GLuint index, GLshort x);
void glVertexAttrib1sv(GLuint index, GLshort v);
void glVertexAttrib1svARB(GLuint index, GLshort v);
void glVertexAttrib1svNV(GLuint index, GLshort v);
void glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y);
void glVertexAttrib2dARB(GLuint index, GLdouble x, GLdouble y);
void glVertexAttrib2dNV(GLuint index, GLdouble x, GLdouble y);
void glVertexAttrib2dv(GLuint index, GLdouble v);
void glVertexAttrib2dvARB(GLuint index, GLdouble v);
void glVertexAttrib2dvNV(GLuint index, GLdouble v);
void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y);
void glVertexAttrib2fARB(GLuint index, GLfloat x, GLfloat y);
void glVertexAttrib2fNV(GLuint index, GLfloat x, GLfloat y);
void glVertexAttrib2fv(GLuint index, GLfloat v);
void glVertexAttrib2fvARB(GLuint index, GLfloat v);
void glVertexAttrib2fvNV(GLuint index, GLfloat v);
void glVertexAttrib2hNV(GLuint index, GLhalfNV x, GLhalfNV y);
void glVertexAttrib2hvNV(GLuint index, GLhalfNV v);
void glVertexAttrib2s(GLuint index, GLshort x, GLshort y);
void glVertexAttrib2sARB(GLuint index, GLshort x, GLshort y);
void glVertexAttrib2sNV(GLuint index, GLshort x, GLshort y);
void glVertexAttrib2sv(GLuint index, GLshort v);
void glVertexAttrib2svARB(GLuint index, GLshort v);
void glVertexAttrib2svNV(GLuint index, GLshort v);
void glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z);
void glVertexAttrib3dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z);
void glVertexAttrib3dNV(GLuint index, GLdouble x, GLdouble y, GLdouble z);
void glVertexAttrib3dv(GLuint index, GLdouble v);
void glVertexAttrib3dvARB(GLuint index, GLdouble v);
void glVertexAttrib3dvNV(GLuint index, GLdouble v);
void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z);
void glVertexAttrib3fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z);
void glVertexAttrib3fNV(GLuint index, GLfloat x, GLfloat y, GLfloat z);
void glVertexAttrib3fv(GLuint index, GLfloat v);
void glVertexAttrib3fvARB(GLuint index, GLfloat v);
void glVertexAttrib3fvNV(GLuint index, GLfloat v);
void glVertexAttrib3hNV(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z);
void glVertexAttrib3hvNV(GLuint index, GLhalfNV v);
void glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z);
void glVertexAttrib3sARB(GLuint index, GLshort x, GLshort y, GLshort z);
void glVertexAttrib3sNV(GLuint index, GLshort x, GLshort y, GLshort z);
void glVertexAttrib3sv(GLuint index, GLshort v);
void glVertexAttrib3svARB(GLuint index, GLshort v);
void glVertexAttrib3svNV(GLuint index, GLshort v);
void glVertexAttrib4Nbv(GLuint index, GLbyte v);
void glVertexAttrib4NbvARB(GLuint index, GLbyte v);
void glVertexAttrib4Niv(GLuint index, GLint v);
void glVertexAttrib4NivARB(GLuint index, GLint v);
void glVertexAttrib4Nsv(GLuint index, GLshort v);
void glVertexAttrib4NsvARB(GLuint index, GLshort v);
void glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
void glVertexAttrib4NubARB(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
void glVertexAttrib4Nubv(GLuint index, GLubyte v);
void glVertexAttrib4NubvARB(GLuint index, GLubyte v);
void glVertexAttrib4Nuiv(GLuint index, GLuint v);
void glVertexAttrib4NuivARB(GLuint index, GLuint v);
void glVertexAttrib4Nusv(GLuint index, GLushort v);
void glVertexAttrib4NusvARB(GLuint index, GLushort v);
void glVertexAttrib4bv(GLuint index, GLbyte v);
void glVertexAttrib4bvARB(GLuint index, GLbyte v);
void glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glVertexAttrib4dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glVertexAttrib4dNV(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glVertexAttrib4dv(GLuint index, GLdouble v);
void glVertexAttrib4dvARB(GLuint index, GLdouble v);
void glVertexAttrib4dvNV(GLuint index, GLdouble v);
void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glVertexAttrib4fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glVertexAttrib4fNV(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glVertexAttrib4fv(GLuint index, GLfloat v);
void glVertexAttrib4fvARB(GLuint index, GLfloat v);
void glVertexAttrib4fvNV(GLuint index, GLfloat v);
void glVertexAttrib4hNV(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
void glVertexAttrib4hvNV(GLuint index, GLhalfNV v);
void glVertexAttrib4iv(GLuint index, GLint v);
void glVertexAttrib4ivARB(GLuint index, GLint v);
void glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
void glVertexAttrib4sARB(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
void glVertexAttrib4sNV(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
void glVertexAttrib4sv(GLuint index, GLshort v);
void glVertexAttrib4svARB(GLuint index, GLshort v);
void glVertexAttrib4svNV(GLuint index, GLshort v);
void glVertexAttrib4ubNV(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
void glVertexAttrib4ubv(GLuint index, GLubyte v);
void glVertexAttrib4ubvARB(GLuint index, GLubyte v);
void glVertexAttrib4ubvNV(GLuint index, GLubyte v);
void glVertexAttrib4uiv(GLuint index, GLuint v);
void glVertexAttrib4uivARB(GLuint index, GLuint v);
void glVertexAttrib4usv(GLuint index, GLushort v);
void glVertexAttrib4usvARB(GLuint index, GLushort v);
void glVertexAttribArrayObjectATI(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint buffer, GLuint offset);
void glVertexAttribBinding(GLuint attribindex, GLuint bindingindex);
void glVertexAttribDivisor(GLuint index, GLuint divisor);
void glVertexAttribDivisorARB(GLuint index, GLuint divisor);
void glVertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
void glVertexAttribFormatNV(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
void glVertexAttribI1i(GLuint index, GLint x);
void glVertexAttribI1iEXT(GLuint index, GLint x);
void glVertexAttribI1iv(GLuint index, GLint v);
void glVertexAttribI1ivEXT(GLuint index, GLint v);
void glVertexAttribI1ui(GLuint index, GLuint x);
void glVertexAttribI1uiEXT(GLuint index, GLuint x);
void glVertexAttribI1uiv(GLuint index, GLuint v);
void glVertexAttribI1uivEXT(GLuint index, GLuint v);
void glVertexAttribI2i(GLuint index, GLint x, GLint y);
void glVertexAttribI2iEXT(GLuint index, GLint x, GLint y);
void glVertexAttribI2iv(GLuint index, GLint v);
void glVertexAttribI2ivEXT(GLuint index, GLint v);
void glVertexAttribI2ui(GLuint index, GLuint x, GLuint y);
void glVertexAttribI2uiEXT(GLuint index, GLuint x, GLuint y);
void glVertexAttribI2uiv(GLuint index, GLuint v);
void glVertexAttribI2uivEXT(GLuint index, GLuint v);
void glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z);
void glVertexAttribI3iEXT(GLuint index, GLint x, GLint y, GLint z);
void glVertexAttribI3iv(GLuint index, GLint v);
void glVertexAttribI3ivEXT(GLuint index, GLint v);
void glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z);
void glVertexAttribI3uiEXT(GLuint index, GLuint x, GLuint y, GLuint z);
void glVertexAttribI3uiv(GLuint index, GLuint v);
void glVertexAttribI3uivEXT(GLuint index, GLuint v);
void glVertexAttribI4bv(GLuint index, GLbyte v);
void glVertexAttribI4bvEXT(GLuint index, GLbyte v);
void glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w);
void glVertexAttribI4iEXT(GLuint index, GLint x, GLint y, GLint z, GLint w);
void glVertexAttribI4iv(GLuint index, GLint v);
void glVertexAttribI4ivEXT(GLuint index, GLint v);
void glVertexAttribI4sv(GLuint index, GLshort v);
void glVertexAttribI4svEXT(GLuint index, GLshort v);
void glVertexAttribI4ubv(GLuint index, GLubyte v);
void glVertexAttribI4ubvEXT(GLuint index, GLubyte v);
void glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
void glVertexAttribI4uiEXT(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
void glVertexAttribI4uiv(GLuint index, GLuint v);
void glVertexAttribI4uivEXT(GLuint index, GLuint v);
void glVertexAttribI4usv(GLuint index, GLushort v);
void glVertexAttribI4usvEXT(GLuint index, GLushort v);
void glVertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
void glVertexAttribIFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride);
void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void glVertexAttribIPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void glVertexAttribL1d(GLuint index, GLdouble x);
void glVertexAttribL1dEXT(GLuint index, GLdouble x);
void glVertexAttribL1dv(GLuint index, GLdouble v);
void glVertexAttribL1dvEXT(GLuint index, GLdouble v);
void glVertexAttribL1i64NV(GLuint index, GLint64EXT x);
void glVertexAttribL1i64vNV(GLuint index, GLint64EXT v);
void glVertexAttribL1ui64NV(GLuint index, GLuint64EXT x);
void glVertexAttribL1ui64vNV(GLuint index, GLuint64EXT v);
void glVertexAttribL2d(GLuint index, GLdouble x, GLdouble y);
void glVertexAttribL2dEXT(GLuint index, GLdouble x, GLdouble y);
void glVertexAttribL2dv(GLuint index, GLdouble v);
void glVertexAttribL2dvEXT(GLuint index, GLdouble v);
void glVertexAttribL2i64NV(GLuint index, GLint64EXT x, GLint64EXT y);
void glVertexAttribL2i64vNV(GLuint index, GLint64EXT v);
void glVertexAttribL2ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y);
void glVertexAttribL2ui64vNV(GLuint index, GLuint64EXT v);
void glVertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z);
void glVertexAttribL3dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z);
void glVertexAttribL3dv(GLuint index, GLdouble v);
void glVertexAttribL3dvEXT(GLuint index, GLdouble v);
void glVertexAttribL3i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z);
void glVertexAttribL3i64vNV(GLuint index, GLint64EXT v);
void glVertexAttribL3ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
void glVertexAttribL3ui64vNV(GLuint index, GLuint64EXT v);
void glVertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glVertexAttribL4dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glVertexAttribL4dv(GLuint index, GLdouble v);
void glVertexAttribL4dvEXT(GLuint index, GLdouble v);
void glVertexAttribL4i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
void glVertexAttribL4i64vNV(GLuint index, GLint64EXT v);
void glVertexAttribL4ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
void glVertexAttribL4ui64vNV(GLuint index, GLuint64EXT v);
void glVertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
void glVertexAttribLFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride);
void glVertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void glVertexAttribLPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid pointer);
void glVertexAttribPointerARB(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid pointer);
void glVertexAttribPointerNV(GLuint index, GLint fsize, GLenum type, GLsizei stride, GLvoid pointer);
void glVertexAttribs1dvNV(GLuint index, GLsizei count, GLdouble v);
void glVertexAttribs1fvNV(GLuint index, GLsizei count, GLfloat v);
void glVertexAttribs1hvNV(GLuint index, GLsizei n, GLhalfNV v);
void glVertexAttribs1svNV(GLuint index, GLsizei count, GLshort v);
void glVertexAttribs2dvNV(GLuint index, GLsizei count, GLdouble v);
void glVertexAttribs2fvNV(GLuint index, GLsizei count, GLfloat v);
void glVertexAttribs2hvNV(GLuint index, GLsizei n, GLhalfNV v);
void glVertexAttribs2svNV(GLuint index, GLsizei count, GLshort v);
void glVertexAttribs3dvNV(GLuint index, GLsizei count, GLdouble v);
void glVertexAttribs3fvNV(GLuint index, GLsizei count, GLfloat v);
void glVertexAttribs3hvNV(GLuint index, GLsizei n, GLhalfNV v);
void glVertexAttribs3svNV(GLuint index, GLsizei count, GLshort v);
void glVertexAttribs4dvNV(GLuint index, GLsizei count, GLdouble v);
void glVertexAttribs4fvNV(GLuint index, GLsizei count, GLfloat v);
void glVertexAttribs4hvNV(GLuint index, GLsizei n, GLhalfNV v);
void glVertexAttribs4svNV(GLuint index, GLsizei count, GLshort v);
void glVertexAttribs4ubvNV(GLuint index, GLsizei count, GLubyte v);
void glVertexBindingDivisor(GLuint bindingindex, GLuint divisor);
void glVertexBlendARB(GLint count);
void glVertexBlendEnvfATI(GLenum pname, GLfloat param);
void glVertexBlendEnviATI(GLenum pname, GLint param);
void glVertexFormatNV(GLint size, GLenum type, GLsizei stride);
void glVertexP2ui(GLenum type, GLuint value);
void glVertexP2uiv(GLenum type, GLuint value);
void glVertexP3ui(GLenum type, GLuint value);
void glVertexP3uiv(GLenum type, GLuint value);
void glVertexP4ui(GLenum type, GLuint value);
void glVertexP4uiv(GLenum type, GLuint value);
void glVertexPointer(GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void glVertexPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, GLvoid pointer);
void glVertexPointerListIBM(GLint size, GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride);
void glVertexPointervINTEL(GLint size, GLenum type, GLvoid * pointer);
void glVertexStream1dATI(GLenum stream, GLdouble x);
void glVertexStream1dvATI(GLenum stream, GLdouble coords);
void glVertexStream1fATI(GLenum stream, GLfloat x);
void glVertexStream1fvATI(GLenum stream, GLfloat coords);
void glVertexStream1iATI(GLenum stream, GLint x);
void glVertexStream1ivATI(GLenum stream, GLint coords);
void glVertexStream1sATI(GLenum stream, GLshort x);
void glVertexStream1svATI(GLenum stream, GLshort coords);
void glVertexStream2dATI(GLenum stream, GLdouble x, GLdouble y);
void glVertexStream2dvATI(GLenum stream, GLdouble coords);
void glVertexStream2fATI(GLenum stream, GLfloat x, GLfloat y);
void glVertexStream2fvATI(GLenum stream, GLfloat coords);
void glVertexStream2iATI(GLenum stream, GLint x, GLint y);
void glVertexStream2ivATI(GLenum stream, GLint coords);
void glVertexStream2sATI(GLenum stream, GLshort x, GLshort y);
void glVertexStream2svATI(GLenum stream, GLshort coords);
void glVertexStream3dATI(GLenum stream, GLdouble x, GLdouble y, GLdouble z);
void glVertexStream3dvATI(GLenum stream, GLdouble coords);
void glVertexStream3fATI(GLenum stream, GLfloat x, GLfloat y, GLfloat z);
void glVertexStream3fvATI(GLenum stream, GLfloat coords);
void glVertexStream3iATI(GLenum stream, GLint x, GLint y, GLint z);
void glVertexStream3ivATI(GLenum stream, GLint coords);
void glVertexStream3sATI(GLenum stream, GLshort x, GLshort y, GLshort z);
void glVertexStream3svATI(GLenum stream, GLshort coords);
void glVertexStream4dATI(GLenum stream, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glVertexStream4dvATI(GLenum stream, GLdouble coords);
void glVertexStream4fATI(GLenum stream, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glVertexStream4fvATI(GLenum stream, GLfloat coords);
void glVertexStream4iATI(GLenum stream, GLint x, GLint y, GLint z, GLint w);
void glVertexStream4ivATI(GLenum stream, GLint coords);
void glVertexStream4sATI(GLenum stream, GLshort x, GLshort y, GLshort z, GLshort w);
void glVertexStream4svATI(GLenum stream, GLshort coords);
void glVertexWeightPointerEXT(GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void glVertexWeightfEXT(GLfloat weight);
void glVertexWeightfvEXT(GLfloat weight);
void glVertexWeighthNV(GLhalfNV weight);
void glVertexWeighthvNV(GLhalfNV weight);
GLenum glVideoCaptureNV(GLuint video_capture_slot, GLuint sequence_num, GLuint64EXT capture_time);
void glVideoCaptureStreamParameterdvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble params);
void glVideoCaptureStreamParameterfvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat params);
void glVideoCaptureStreamParameterivNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLint params);
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height);
void glViewportArrayv(GLuint first, GLsizei count, GLfloat v);
void glViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
void glViewportIndexedfv(GLuint index, GLfloat v);
void glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
void glWeightPathsNV(GLuint resultPath, GLsizei numPaths, GLuint paths, GLfloat weights);
void glWeightPointerARB(GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void glWeightbvARB(GLint size, GLbyte weights);
void glWeightdvARB(GLint size, GLdouble weights);
void glWeightfvARB(GLint size, GLfloat weights);
void glWeightivARB(GLint size, GLint weights);
void glWeightsvARB(GLint size, GLshort weights);
void glWeightubvARB(GLint size, GLubyte weights);
void glWeightuivARB(GLint size, GLuint weights);
void glWeightusvARB(GLint size, GLushort weights);
void glWindowPos2d(GLdouble x, GLdouble y);
void glWindowPos2dARB(GLdouble x, GLdouble y);
void glWindowPos2dMESA(GLdouble x, GLdouble y);
void glWindowPos2dv(GLdouble v);
void glWindowPos2dvARB(GLdouble v);
void glWindowPos2dvMESA(GLdouble v);
void glWindowPos2f(GLfloat x, GLfloat y);
void glWindowPos2fARB(GLfloat x, GLfloat y);
void glWindowPos2fMESA(GLfloat x, GLfloat y);
void glWindowPos2fv(GLfloat v);
void glWindowPos2fvARB(GLfloat v);
void glWindowPos2fvMESA(GLfloat v);
void glWindowPos2i(GLint x, GLint y);
void glWindowPos2iARB(GLint x, GLint y);
void glWindowPos2iMESA(GLint x, GLint y);
void glWindowPos2iv(GLint v);
void glWindowPos2ivARB(GLint v);
void glWindowPos2ivMESA(GLint v);
void glWindowPos2s(GLshort x, GLshort y);
void glWindowPos2sARB(GLshort x, GLshort y);
void glWindowPos2sMESA(GLshort x, GLshort y);
void glWindowPos2sv(GLshort v);
void glWindowPos2svARB(GLshort v);
void glWindowPos2svMESA(GLshort v);
void glWindowPos3d(GLdouble x, GLdouble y, GLdouble z);
void glWindowPos3dARB(GLdouble x, GLdouble y, GLdouble z);
void glWindowPos3dMESA(GLdouble x, GLdouble y, GLdouble z);
void glWindowPos3dv(GLdouble v);
void glWindowPos3dvARB(GLdouble v);
void glWindowPos3dvMESA(GLdouble v);
void glWindowPos3f(GLfloat x, GLfloat y, GLfloat z);
void glWindowPos3fARB(GLfloat x, GLfloat y, GLfloat z);
void glWindowPos3fMESA(GLfloat x, GLfloat y, GLfloat z);
void glWindowPos3fv(GLfloat v);
void glWindowPos3fvARB(GLfloat v);
void glWindowPos3fvMESA(GLfloat v);
void glWindowPos3i(GLint x, GLint y, GLint z);
void glWindowPos3iARB(GLint x, GLint y, GLint z);
void glWindowPos3iMESA(GLint x, GLint y, GLint z);
void glWindowPos3iv(GLint v);
void glWindowPos3ivARB(GLint v);
void glWindowPos3ivMESA(GLint v);
void glWindowPos3s(GLshort x, GLshort y, GLshort z);
void glWindowPos3sARB(GLshort x, GLshort y, GLshort z);
void glWindowPos3sMESA(GLshort x, GLshort y, GLshort z);
void glWindowPos3sv(GLshort v);
void glWindowPos3svARB(GLshort v);
void glWindowPos3svMESA(GLshort v);
void glWindowPos4dMESA(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void glWindowPos4dvMESA(GLdouble v);
void glWindowPos4fMESA(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glWindowPos4fvMESA(GLfloat v);
void glWindowPos4iMESA(GLint x, GLint y, GLint z, GLint w);
void glWindowPos4ivMESA(GLint v);
void glWindowPos4sMESA(GLshort x, GLshort y, GLshort z, GLshort w);
void glWindowPos4svMESA(GLshort v);
void glWriteMaskEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
Bool glxAssociateDMPbufferSGIX(Display dpy, GLXPbufferSGIX pbuffer, DMparams params, DMbuffer dmbuffer);
int glxBindChannelToWindowSGIX(Display display, int screen, int channel, Window window);
int glxBindHyperpipeSGIX(Display dpy, int hpId);
Bool glxBindSwapBarrierNV(Display dpy, GLuint group, GLuint barrier);
void glxBindSwapBarrierSGIX(Display dpy, GLXDrawable drawable, int barrier);
void glxBindTexImageEXT(Display dpy, GLXDrawable drawable, int buffer, int attrib_list);
int glxBindVideoCaptureDeviceNV(Display dpy, unsigned int video_capture_slot, GLXVideoCaptureDeviceNV device);
int glxBindVideoDeviceNV(Display dpy, unsigned int video_slot, unsigned int video_device, int attrib_list);
int glxBindVideoImageNV(Display dpy, GLXVideoDeviceNV VideoDevice, GLXPbuffer pbuf, int iVideoBuffer);
int glxChannelRectSGIX(Display display, int screen, int channel, int x, int y, int w, int h);
int glxChannelRectSyncSGIX(Display display, int screen, int channel, GLenum synctype);
GLXFBConfigPointer glxChooseFBConfig(Display dpy, int screen, int attrib_list, int nelements);
GLXFBConfigSGIXPointer glxChooseFBConfigSGIX(Display dpy, int screen, int attrib_list, int nelements);
void glxCopyImageSubDataNV(Display dpy, GLXContext srcCtx, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLXContext dstCtx, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
void glxCopySubBufferMESA(Display dpy, GLXDrawable drawable, int x, int y, int width, int height);
GLXContext glxCreateContextAttribsARB(Display dpy, GLXFBConfig config, GLXContext share_context, Bool direct, int attrib_list);
GLXContext glxCreateContextWithConfigSGIX(Display dpy, GLXFBConfigSGIX config, int render_type, GLXContext share_list, Bool direct);
GLXPbufferSGIX glxCreateGLXPbufferSGIX(Display dpy, GLXFBConfigSGIX config, unsigned int width, unsigned int height, int attrib_list);
GLXPixmap glxCreateGLXPixmapMESA(Display dpy, XVisualInfo visual, Pixmap pixmap, Colormap cmap);
GLXPixmap glxCreateGLXPixmapWithConfigSGIX(Display dpy, GLXFBConfigSGIX config, Pixmap pixmap);
GLXVideoSourceSGIX glxCreateGLXVideoSourceSGIX(Display display, int screen, VLServer server, VLPath path, int nodeClass, VLNode drainNode);
GLXContext glxCreateNewContext(Display dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct);
GLXPbuffer glxCreatePbuffer(Display dpy, GLXFBConfig config, int attrib_list);
GLXPixmap glxCreatePixmap(Display dpy, GLXFBConfig config, Pixmap pixmap, int attrib_list);
GLXWindow glxCreateWindow(Display dpy, GLXFBConfig config, Window win, int attrib_list);
void glxCushionSGI(Display dpy, Window window, float cushion);
void glxDestroyGLXPbufferSGIX(Display dpy, GLXPbufferSGIX pbuf);
void glxDestroyGLXVideoSourceSGIX(Display dpy, GLXVideoSourceSGIX glxvideosource);
int glxDestroyHyperpipeConfigSGIX(Display dpy, int hpId);
void glxDestroyPbuffer(Display dpy, GLXPbuffer pbuf);
void glxDestroyPixmap(Display dpy, GLXPixmap pixmap);
void glxDestroyWindow(Display dpy, GLXWindow win);
GLXVideoCaptureDeviceNVPointer glxEnumerateVideoCaptureDevicesNV(Display dpy, int screen, int nelements);
uintPointer glxEnumerateVideoDevicesNV(Display dpy, int screen, int nelements);
void glxFreeContextEXT(Display dpy, GLXContext context);
uint glxGetAGPOffsetMESA(void pointer);
GLXContextID glxGetContextIDEXT(const GLXContext context);
DisplayPointer glxGetCurrentDisplay();
DisplayPointer glxGetCurrentDisplayEXT();
GLXDrawable glxGetCurrentReadDrawable();
GLXDrawable glxGetCurrentReadDrawableSGI();
int glxGetFBConfigAttrib(Display dpy, GLXFBConfig config, int attribute, int value);
int glxGetFBConfigAttribSGIX(Display dpy, GLXFBConfigSGIX config, int attribute, int value);
GLXFBConfigSGIX glxGetFBConfigFromVisualSGIX(Display dpy, XVisualInfo vis);
GLXFBConfigPointer glxGetFBConfigs(Display dpy, int screen, int nelements);
Bool glxGetMscRateOML(Display dpy, GLXDrawable drawable, int32_t numerator, int32_t denominator);
FunctionPointer glxGetProcAddress(GLubyte procName);
FunctionPointer glxGetProcAddressARB(GLubyte procName);
void glxGetSelectedEvent(Display dpy, GLXDrawable draw, unsigned long event_mask);
void glxGetSelectedEventSGIX(Display dpy, GLXDrawable drawable, unsigned long mask);
Bool glxGetSyncValuesOML(Display dpy, GLXDrawable drawable, int64_t ust, int64_t msc, int64_t sbc);
Status glxGetTransparentIndexSUN(Display dpy, Window overlay, Window underlay, long pTransparentIndex);
int glxGetVideoDeviceNV(Display dpy, int screen, int numVideoDevices, GLXVideoDeviceNV pVideoDevice);
int glxGetVideoInfoNV(Display dpy, int screen, GLXVideoDeviceNV VideoDevice, unsigned long pulCounterOutputPbuffer, unsigned long pulCounterOutputVideo);
int glxGetVideoSyncSGI(unsigned int count);
XVisualInfoPointer glxGetVisualFromFBConfig(Display dpy, GLXFBConfig config);
XVisualInfoPointer glxGetVisualFromFBConfigSGIX(Display dpy, GLXFBConfigSGIX config);
int glxHyperpipeAttribSGIX(Display dpy, int timeSlice, int attrib, int size, void attribList);
int glxHyperpipeConfigSGIX(Display dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX cfg, int hpId);
GLXContext glxImportContextEXT(Display dpy, GLXContextID contextID);
Bool glxJoinSwapGroupNV(Display dpy, GLXDrawable drawable, GLuint group);
void glxJoinSwapGroupSGIX(Display dpy, GLXDrawable drawable, GLXDrawable member);
void glxLockVideoCaptureDeviceNV(Display dpy, GLXVideoCaptureDeviceNV device);
Bool glxMakeContextCurrent(Display dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
Bool glxMakeCurrentReadSGI(Display dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
int glxQueryChannelDeltasSGIX(Display display, int screen, int channel, int x, int y, int w, int h);
int glxQueryChannelRectSGIX(Display display, int screen, int channel, int dx, int dy, int dw, int dh);
int glxQueryContext(Display dpy, GLXContext ctx, int attribute, int value);
int glxQueryContextInfoEXT(Display dpy, GLXContext context, int attribute, int value);
void glxQueryDrawable(Display dpy, GLXDrawable draw, int attribute, unsigned int value);
Bool glxQueryFrameCountNV(Display dpy, int screen, GLuint count);
int glxQueryGLXPbufferSGIX(Display dpy, GLXPbufferSGIX pbuf, int attribute, unsigned int value);
int glxQueryHyperpipeAttribSGIX(Display dpy, int timeSlice, int attrib, int size, void returnAttribList);
int glxQueryHyperpipeBestAttribSGIX(Display dpy, int timeSlice, int attrib, int size, void attribList, void returnAttribList);
GLXHyperpipeConfigSGIXPointer glxQueryHyperpipeConfigSGIX(Display dpy, int hpId, int npipes);
GLXHyperpipeNetworkSGIXPointer glxQueryHyperpipeNetworkSGIX(Display dpy, int npipes);
Bool glxQueryMaxSwapBarriersSGIX(Display dpy, int screen, int max);
Bool glxQueryMaxSwapGroupsNV(Display dpy, int screen, GLuint maxGroups, GLuint maxBarriers);
Bool glxQuerySwapGroupNV(Display dpy, GLXDrawable drawable, GLuint group, GLuint barrier);
int glxQueryVideoCaptureDeviceNV(Display dpy, GLXVideoCaptureDeviceNV device, int attribute, int value);
Bool glxReleaseBuffersMESA(Display dpy, GLXDrawable drawable);
void glxReleaseTexImageEXT(Display dpy, GLXDrawable drawable, int buffer);
void glxReleaseVideoCaptureDeviceNV(Display dpy, GLXVideoCaptureDeviceNV device);
int glxReleaseVideoDeviceNV(Display dpy, int screen, GLXVideoDeviceNV VideoDevice);
int glxReleaseVideoImageNV(Display dpy, GLXPbuffer pbuf);
Bool glxResetFrameCountNV(Display dpy, int screen);
void glxSelectEvent(Display dpy, GLXDrawable draw, unsigned long event_mask);
void glxSelectEventSGIX(Display dpy, GLXDrawable drawable, unsigned long mask);
int glxSendPbufferToVideoNV(Display dpy, GLXPbuffer pbuf, int iBufferType, unsigned long pulCounterPbuffer, GLboolean bBlock);
Bool glxSet3DfxModeMESA(int mode);
int64_t glxSwapBuffersMscOML(Display dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder);
void glxSwapIntervalEXT(Display dpy, GLXDrawable drawable, int interval);
int glxSwapIntervalSGI(int interval);
Bool glxWaitForMscOML(Display dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder, int64_t ust, int64_t msc, int64_t sbc);
Bool glxWaitForSbcOML(Display dpy, GLXDrawable drawable, int64_t target_sbc, int64_t ust, int64_t msc, int64_t sbc);
int glxWaitVideoSyncSGI(int divisor, int remainder, unsigned int count);

#endif
