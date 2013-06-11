

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
void Accum(GLenum op, GLfloat value);
void AccumxOES(GLenum op, GLfixed value);
void ActiveProgramEXT(GLuint program);
void ActiveShaderProgram(GLuint pipeline, GLuint program);
void ActiveStencilFaceEXT(GLenum face);
void ActiveTexture(GLenum texture);
void ActiveTextureARB(GLenum texture);
void ActiveVaryingNV(GLuint program, GLchar name);
void AlphaFragmentOp1ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
void AlphaFragmentOp2ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
void AlphaFragmentOp3ATI(GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
void AlphaFunc(GLenum func, GLfloat ref);
void AlphaFuncxOES(GLenum func, GLfixed ref);
void ApplyTextureEXT(GLenum mode);
Boolean AreProgramsResidentNV(GLsizei n, GLuint programs, GLboolean residences);
Boolean AreTexturesResident(GLsizei n, GLuint textures, GLboolean residences);
Boolean AreTexturesResidentEXT(GLsizei n, GLuint textures, GLboolean residences);
void ArrayElement(GLint i);
void ArrayElementEXT(GLint i);
void ArrayObjectATI(GLenum array, GLint size, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
void AsyncMarkerSGIX(GLuint marker);
void AttachObjectARB(GLhandleARB containerObj, GLhandleARB obj);
void AttachShader(GLuint program, GLuint shader);
void Begin(GLenum mode);
void BeginConditionalRender(GLuint id, GLenum mode);
void BeginConditionalRenderNV(GLuint id, GLenum mode);
void BeginConditionalRenderNVX(GLuint id);
void BeginFragmentShaderATI();
void BeginOcclusionQueryNV(GLuint id);
void BeginPerfMonitorAMD(GLuint monitor);
void BeginQuery(GLenum target, GLuint id);
void BeginQueryARB(GLenum target, GLuint id);
void BeginQueryIndexed(GLenum target, GLuint index, GLuint id);
void BeginTransformFeedback(GLenum primitiveMode);
void BeginTransformFeedbackEXT(GLenum primitiveMode);
void BeginTransformFeedbackNV(GLenum primitiveMode);
void BeginVertexShaderEXT();
void BeginVideoCaptureNV(GLuint video_capture_slot);
void BindAttribLocation(GLuint program, GLuint index, GLchar name);
void BindAttribLocationARB(GLhandleARB programObj, GLuint index, GLcharARB name);
void BindBuffer(GLenum target, GLuint buffer);
void BindBufferARB(GLenum target, GLuint buffer);
void BindBufferBase(GLenum target, GLuint index, GLuint buffer);
void BindBufferBaseEXT(GLenum target, GLuint index, GLuint buffer);
void BindBufferBaseNV(GLenum target, GLuint index, GLuint buffer);
void BindBufferOffsetEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset);
void BindBufferOffsetNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset);
void BindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
void BindBufferRangeEXT(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
void BindBufferRangeNV(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
void BindFragDataLocation(GLuint program, GLuint color, GLchar name);
void BindFragDataLocationEXT(GLuint program, GLuint color, GLchar name);
void BindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, GLchar name);
void BindFragmentShaderATI(GLuint id);
void BindFramebuffer(GLenum target, GLuint framebuffer);
void BindFramebufferEXT(GLenum target, GLuint framebuffer);
void BindImageTexture(GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
void BindImageTextureEXT(GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format);
UInt32 BindLightParameterEXT(GLenum light, GLenum value);
UInt32 BindMaterialParameterEXT(GLenum face, GLenum value);
void BindMultiTextureEXT(GLenum texunit, GLenum target, GLuint texture);
UInt32 BindParameterEXT(GLenum value);
void BindProgramARB(GLenum target, GLuint program);
void BindProgramNV(GLenum target, GLuint id);
void BindProgramPipeline(GLuint pipeline);
void BindRenderbuffer(GLenum target, GLuint renderbuffer);
void BindRenderbufferEXT(GLenum target, GLuint renderbuffer);
void BindSampler(GLuint unit, GLuint sampler);
UInt32 BindTexGenParameterEXT(GLenum unit, GLenum coord, GLenum value);
void BindTexture(GLenum target, GLuint texture);
void BindTextureEXT(GLenum target, GLuint texture);
UInt32 BindTextureUnitParameterEXT(GLenum unit, GLenum value);
void BindTransformFeedback(GLenum target, GLuint id);
void BindTransformFeedbackNV(GLenum target, GLuint id);
void BindVertexArray(GLuint array);
void BindVertexArrayAPPLE(GLuint array);
void BindVertexBuffer(GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
void BindVertexShaderEXT(GLuint id);
void BindVideoCaptureStreamBufferNV(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLintptrARB offset);
void BindVideoCaptureStreamTextureNV(GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLenum target, GLuint texture);
void Binormal3bEXT(GLbyte bx, GLbyte by, GLbyte bz);
void Binormal3bvEXT(GLbyte v);
void Binormal3dEXT(GLdouble bx, GLdouble by, GLdouble bz);
void Binormal3dvEXT(GLdouble v);
void Binormal3fEXT(GLfloat bx, GLfloat by, GLfloat bz);
void Binormal3fvEXT(GLfloat v);
void Binormal3iEXT(GLint bx, GLint by, GLint bz);
void Binormal3ivEXT(GLint v);
void Binormal3sEXT(GLshort bx, GLshort by, GLshort bz);
void Binormal3svEXT(GLshort v);
void BinormalPointerEXT(GLenum type, GLsizei stride, GLvoid pointer);
void Bitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, GLubyte bitmap);
void BitmapxOES(GLsizei width, GLsizei height, GLfixed xorig, GLfixed yorig, GLfixed xmove, GLfixed ymove, GLubyte bitmap);
void BlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void BlendColorEXT(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void BlendColorxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
void BlendEquation(GLenum mode);
void BlendEquationEXT(GLenum mode);
void BlendEquationIndexedAMD(GLuint buf, GLenum mode);
void BlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha);
void BlendEquationSeparateEXT(GLenum modeRGB, GLenum modeAlpha);
void BlendEquationSeparateIndexedAMD(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
void BlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
void BlendEquationSeparateiARB(GLuint buf, GLenum modeRGB, GLenum modeAlpha);
void BlendEquationi(GLuint buf, GLenum mode);
void BlendEquationiARB(GLuint buf, GLenum mode);
void BlendFunc(GLenum sfactor, GLenum dfactor);
void BlendFuncIndexedAMD(GLuint buf, GLenum src, GLenum dst);
void BlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
void BlendFuncSeparateEXT(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
void BlendFuncSeparateINGR(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
void BlendFuncSeparateIndexedAMD(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
void BlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
void BlendFuncSeparateiARB(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
void BlendFunci(GLuint buf, GLenum src, GLenum dst);
void BlendFunciARB(GLuint buf, GLenum src, GLenum dst);
void BlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
void BlitFramebufferEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
void BufferAddressRangeNV(GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length);
void BufferData(GLenum target, GLsizeiptr size, GLvoid data, GLenum usage);
void BufferDataARB(GLenum target, GLsizeiptrARB size, GLvoid data, GLenum usage);
void BufferParameteriAPPLE(GLenum target, GLenum pname, GLint param);
void BufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid data);
void BufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid data);
void CallList(GLuint list);
void CallLists(GLsizei n, GLenum type, GLvoid lists);
GLenum CheckFramebufferStatus(GLenum target);
GLenum CheckFramebufferStatusEXT(GLenum target);
FramebufferStatus CheckNamedFramebufferStatusEXT(GLuint framebuffer, GLenum target);
void ClampColor(GLenum target, GLenum clamp);
void ClampColorARB(GLenum target, GLenum clamp);
void Clear(GLbitfield mask);
void ClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void ClearAccumxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
void ClearBufferData(GLenum target, GLenum internalformat, GLenum format, GLenum type, void * data);
void ClearBufferSubData(GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, void * data);
void ClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
void ClearBufferfv(GLenum buffer, GLint drawbuffer, GLfloat value);
void ClearBufferiv(GLenum buffer, GLint drawbuffer, GLint value);
void ClearBufferuiv(GLenum buffer, GLint drawbuffer, GLuint value);
void ClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void ClearColorIiEXT(GLint red, GLint green, GLint blue, GLint alpha);
void ClearColorIuiEXT(GLuint red, GLuint green, GLuint blue, GLuint alpha);
void ClearColorxOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
void ClearDepth(GLdouble depth);
void ClearDepthdNV(GLdouble depth);
void ClearDepthf(GLfloat d);
void ClearDepthfOES(GLclampf depth);
void ClearDepthxOES(GLfixed depth);
void ClearIndex(GLfloat c);
void ClearNamedBufferDataEXT(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, void * data);
void ClearNamedBufferSubDataEXT(GLuint buffer, GLenum internalformat, GLenum format, GLenum type, GLsizeiptr offset, GLsizeiptr size, void * data);
void ClearStencil(GLint s);
void ClientActiveTexture(GLenum texture);
void ClientActiveTextureARB(GLenum texture);
void ClientActiveVertexStreamATI(GLenum stream);
void ClientAttribDefaultEXT(GLbitfield mask);
GLenum ClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
void ClipPlane(GLenum plane, GLdouble equation);
void ClipPlanefOES(GLenum plane, GLfloat equation);
void ClipPlanexOES(GLenum plane, GLfixed equation);
void Color3b(GLbyte red, GLbyte green, GLbyte blue);
void Color3bv(GLbyte v);
void Color3d(GLdouble red, GLdouble green, GLdouble blue);
void Color3dv(GLdouble v);
void Color3f(GLfloat red, GLfloat green, GLfloat blue);
void Color3fVertex3fSUN(GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
void Color3fVertex3fvSUN(GLfloat c, GLfloat v);
void Color3fv(GLfloat v);
void Color3hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue);
void Color3hvNV(GLhalfNV v);
void Color3i(GLint red, GLint green, GLint blue);
void Color3iv(GLint v);
void Color3s(GLshort red, GLshort green, GLshort blue);
void Color3sv(GLshort v);
void Color3ub(GLubyte red, GLubyte green, GLubyte blue);
void Color3ubv(GLubyte v);
void Color3ui(GLuint red, GLuint green, GLuint blue);
void Color3uiv(GLuint v);
void Color3us(GLushort red, GLushort green, GLushort blue);
void Color3usv(GLushort v);
void Color3xOES(GLfixed red, GLfixed green, GLfixed blue);
void Color3xvOES(GLfixed components);
void Color4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
void Color4bv(GLbyte v);
void Color4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
void Color4dv(GLdouble v);
void Color4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void Color4fNormal3fVertex3fSUN(GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
void Color4fNormal3fVertex3fvSUN(GLfloat c, GLfloat n, GLfloat v);
void Color4fv(GLfloat v);
void Color4hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue, GLhalfNV alpha);
void Color4hvNV(GLhalfNV v);
void Color4i(GLint red, GLint green, GLint blue, GLint alpha);
void Color4iv(GLint v);
void Color4s(GLshort red, GLshort green, GLshort blue, GLshort alpha);
void Color4sv(GLshort v);
void Color4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
void Color4ubVertex2fSUN(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y);
void Color4ubVertex2fvSUN(GLubyte c, GLfloat v);
void Color4ubVertex3fSUN(GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
void Color4ubVertex3fvSUN(GLubyte c, GLfloat v);
void Color4ubv(GLubyte v);
void Color4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha);
void Color4uiv(GLuint v);
void Color4us(GLushort red, GLushort green, GLushort blue, GLushort alpha);
void Color4usv(GLushort v);
void Color4xOES(GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
void Color4xvOES(GLfixed components);
void ColorFormatNV(GLint size, GLenum type, GLsizei stride);
void ColorFragmentOp1ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
void ColorFragmentOp2ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
void ColorFragmentOp3ATI(GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
void ColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
void ColorMaskIndexedEXT(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
void ColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
void ColorMaterial(GLenum face, GLenum mode);
void ColorP3ui(GLenum type, GLuint color);
void ColorP3uiv(GLenum type, GLuint color);
void ColorP4ui(GLenum type, GLuint color);
void ColorP4uiv(GLenum type, GLuint color);
void ColorPointer(GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void ColorPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, GLvoid pointer);
void ColorPointerListIBM(GLint size, GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride);
void ColorPointervINTEL(GLint size, GLenum type, GLvoid * pointer);
void ColorSubTable(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, GLvoid data);
void ColorSubTableEXT(GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, GLvoid data);
void ColorTable(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, GLvoid table);
void ColorTableEXT(GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, GLvoid table);
void ColorTableParameterfv(GLenum target, GLenum pname, GLfloat params);
void ColorTableParameterfvSGI(GLenum target, GLenum pname, GLfloat params);
void ColorTableParameteriv(GLenum target, GLenum pname, GLint params);
void ColorTableParameterivSGI(GLenum target, GLenum pname, GLint params);
void ColorTableSGI(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, GLvoid table);
void CombinerInputNV(GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
void CombinerOutputNV(GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum);
void CombinerParameterfNV(GLenum pname, GLfloat param);
void CombinerParameterfvNV(GLenum pname, GLfloat params);
void CombinerParameteriNV(GLenum pname, GLint param);
void CombinerParameterivNV(GLenum pname, GLint params);
void CombinerStageParameterfvNV(GLenum stage, GLenum pname, GLfloat params);
void CompileShader(GLuint shader);
void CompileShaderARB(GLhandleARB shaderObj);
void CompileShaderIncludeARB(GLuint shader, GLsizei count, GLchar * path, GLint length);
void CompressedMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid bits);
void CompressedMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid bits);
void CompressedMultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid bits);
void CompressedMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid bits);
void CompressedMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid bits);
void CompressedMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid bits);
void CompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid data);
void CompressedTexImage1DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid data);
void CompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid data);
void CompressedTexImage2DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid data);
void CompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid data);
void CompressedTexImage3DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid data);
void CompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid data);
void CompressedTexSubImage1DARB(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid data);
void CompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid data);
void CompressedTexSubImage2DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid data);
void CompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid data);
void CompressedTexSubImage3DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid data);
void CompressedTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, GLvoid bits);
void CompressedTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, GLvoid bits);
void CompressedTextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, GLvoid bits);
void CompressedTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, GLvoid bits);
void CompressedTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, GLvoid bits);
void CompressedTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, GLvoid bits);
void ConvolutionFilter1D(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, GLvoid image);
void ConvolutionFilter1DEXT(GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, GLvoid image);
void ConvolutionFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid image);
void ConvolutionFilter2DEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid image);
void ConvolutionParameterf(GLenum target, GLenum pname, GLfloat params);
void ConvolutionParameterfEXT(GLenum target, GLenum pname, GLfloat params);
void ConvolutionParameterfv(GLenum target, GLenum pname, GLfloat params);
void ConvolutionParameterfvEXT(GLenum target, GLenum pname, GLfloat params);
void ConvolutionParameteri(GLenum target, GLenum pname, GLint params);
void ConvolutionParameteriEXT(GLenum target, GLenum pname, GLint params);
void ConvolutionParameteriv(GLenum target, GLenum pname, GLint params);
void ConvolutionParameterivEXT(GLenum target, GLenum pname, GLint params);
void ConvolutionParameterxOES(GLenum target, GLenum pname, GLfixed param);
void ConvolutionParameterxvOES(GLenum target, GLenum pname, GLfixed params);
void CopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
void CopyColorSubTable(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
void CopyColorSubTableEXT(GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
void CopyColorTable(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
void CopyColorTableSGI(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
void CopyConvolutionFilter1D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
void CopyConvolutionFilter1DEXT(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
void CopyConvolutionFilter2D(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
void CopyConvolutionFilter2DEXT(GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
void CopyImageSubData(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
void CopyImageSubDataNV(GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
void CopyMultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
void CopyMultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void CopyMultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void CopyMultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void CopyMultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void CopyPathNV(GLuint resultPath, GLuint srcPath);
void CopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
void CopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
void CopyTexImage1DEXT(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
void CopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void CopyTexImage2DEXT(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void CopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void CopyTexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void CopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void CopyTexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void CopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void CopyTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void CopyTextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
void CopyTextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void CopyTextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void CopyTextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void CopyTextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void CoverFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLenum coverMode, GLenum transformType, GLfloat transformValues);
void CoverFillPathNV(GLuint path, GLenum coverMode);
void CoverStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLenum coverMode, GLenum transformType, GLfloat transformValues);
void CoverStrokePathNV(GLuint path, GLenum coverMode);
UInt32 CreateProgram();
handleARB CreateProgramObjectARB();
UInt32 CreateShader(GLenum type);
handleARB CreateShaderObjectARB(GLenum shaderType);
UInt32 CreateShaderProgramEXT(GLenum type, GLchar string);
UInt32 CreateShaderProgramv(GLenum type, GLsizei count, GLchar*const strings);
sync CreateSyncFromCLeventARB(struct _cl_context * context, struct _cl_event * event, GLbitfield flags);
void CullFace(GLenum mode);
void CullParameterdvEXT(GLenum pname, GLdouble params);
void CullParameterfvEXT(GLenum pname, GLfloat params);
void CurrentPaletteMatrixARB(GLint index);
void DebugMessageCallback(GLDEBUGPROC callback, void * userParam);
void DebugMessageCallbackAMD(GLDEBUGPROCAMD callback, GLvoid userParam);
void DebugMessageCallbackARB(GLDEBUGPROCARB callback, GLvoid userParam);
void DebugMessageControl(GLenum source, GLenum type, GLenum severity, GLsizei count, GLuint ids, GLboolean enabled);
void DebugMessageControlARB(GLenum source, GLenum type, GLenum severity, GLsizei count, GLuint ids, GLboolean enabled);
void DebugMessageEnableAMD(GLenum category, GLenum severity, GLsizei count, GLuint ids, GLboolean enabled);
void DebugMessageInsert(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, GLchar buf);
void DebugMessageInsertAMD(GLenum category, GLenum severity, GLuint id, GLsizei length, GLchar buf);
void DebugMessageInsertARB(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, GLchar buf);
void DeformSGIX(GLbitfield mask);
void DeformationMap3dSGIX(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble w1, GLdouble w2, GLint wstride, GLint worder, GLdouble points);
void DeformationMap3fSGIX(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat w1, GLfloat w2, GLint wstride, GLint worder, GLfloat points);
void DeleteAsyncMarkersSGIX(GLuint marker, GLsizei range);
void DeleteBuffers(GLsizei n, GLuint buffers);
void DeleteBuffersARB(GLsizei n, GLuint buffers);
void DeleteFencesAPPLE(GLsizei n, GLuint fences);
void DeleteFencesNV(GLsizei n, GLuint fences);
void DeleteFragmentShaderATI(GLuint id);
void DeleteFramebuffers(GLsizei n, GLuint framebuffers);
void DeleteFramebuffersEXT(GLsizei n, GLuint framebuffers);
void DeleteLists(GLuint list, GLsizei range);
void DeleteNamedStringARB(GLint namelen, GLchar name);
void DeleteNamesAMD(GLenum identifier, GLuint num, GLuint names);
void DeleteObjectARB(GLhandleARB obj);
void DeleteOcclusionQueriesNV(GLsizei n, GLuint ids);
void DeletePathsNV(GLuint path, GLsizei range);
void DeletePerfMonitorsAMD(GLsizei n, GLuint monitors);
void DeleteProgram(GLuint program);
void DeleteProgramPipelines(GLsizei n, GLuint pipelines);
void DeleteProgramsARB(GLsizei n, GLuint programs);
void DeleteProgramsNV(GLsizei n, GLuint programs);
void DeleteQueries(GLsizei n, GLuint ids);
void DeleteQueriesARB(GLsizei n, GLuint ids);
void DeleteRenderbuffers(GLsizei n, GLuint renderbuffers);
void DeleteRenderbuffersEXT(GLsizei n, GLuint renderbuffers);
void DeleteSamplers(GLsizei count, GLuint samplers);
void DeleteShader(GLuint shader);
void DeleteSync(GLsync sync);
void DeleteTextures(GLsizei n, GLuint textures);
void DeleteTexturesEXT(GLsizei n, GLuint textures);
void DeleteTransformFeedbacks(GLsizei n, GLuint ids);
void DeleteTransformFeedbacksNV(GLsizei n, GLuint ids);
void DeleteVertexArrays(GLsizei n, GLuint arrays);
void DeleteVertexArraysAPPLE(GLsizei n, GLuint arrays);
void DeleteVertexShaderEXT(GLuint id);
void DepthBoundsEXT(GLclampd zmin, GLclampd zmax);
void DepthBoundsdNV(GLdouble zmin, GLdouble zmax);
void DepthFunc(GLenum func);
void DepthMask(GLboolean flag);
void DepthRange(GLdouble near, GLdouble far);
void DepthRangeArrayv(GLuint first, GLsizei count, GLdouble v);
void DepthRangeIndexed(GLuint index, GLdouble n, GLdouble f);
void DepthRangedNV(GLdouble zNear, GLdouble zFar);
void DepthRangef(GLfloat n, GLfloat f);
void DepthRangefOES(GLclampf n, GLclampf f);
void DepthRangexOES(GLfixed n, GLfixed f);
void DetachObjectARB(GLhandleARB containerObj, GLhandleARB attachedObj);
void DetachShader(GLuint program, GLuint shader);
void DetailTexFuncSGIS(GLenum target, GLsizei n, GLfloat points);
void Disable(GLenum cap);
void DisableClientState(GLenum array);
void DisableClientStateIndexedEXT(GLenum array, GLuint index);
void DisableClientStateiEXT(GLenum array, GLuint index);
void DisableIndexedEXT(GLenum target, GLuint index);
void DisableVariantClientStateEXT(GLuint id);
void DisableVertexArrayAttribEXT(GLuint vaobj, GLuint index);
void DisableVertexArrayEXT(GLuint vaobj, GLenum array);
void DisableVertexAttribAPPLE(GLuint index, GLenum pname);
void DisableVertexAttribArray(GLuint index);
void DisableVertexAttribArrayARB(GLuint index);
void Disablei(GLenum target, GLuint index);
void DispatchCompute(GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
void DispatchComputeIndirect(GLintptr indirect);
void DrawArrays(GLenum mode, GLint first, GLsizei count);
void DrawArraysEXT(GLenum mode, GLint first, GLsizei count);
void DrawArraysIndirect(GLenum mode, GLvoid indirect);
void DrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
void DrawArraysInstancedARB(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
void DrawArraysInstancedBaseInstance(GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
void DrawArraysInstancedEXT(GLenum mode, GLint start, GLsizei count, GLsizei primcount);
void DrawBuffer(GLenum mode);
void DrawBuffers(GLsizei n, GLenum bufs);
void DrawBuffersARB(GLsizei n, GLenum bufs);
void DrawBuffersATI(GLsizei n, GLenum bufs);
void DrawElementArrayAPPLE(GLenum mode, GLint first, GLsizei count);
void DrawElementArrayATI(GLenum mode, GLsizei count);
void DrawElements(GLenum mode, GLsizei count, GLenum type, GLvoid indices);
void DrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid indices, GLint basevertex);
void DrawElementsIndirect(GLenum mode, GLenum type, GLvoid indirect);
void DrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, GLvoid indices, GLsizei instancecount);
void DrawElementsInstancedARB(GLenum mode, GLsizei count, GLenum type, GLvoid indices, GLsizei primcount);
void DrawElementsInstancedBaseInstance(GLenum mode, GLsizei count, GLenum type, void * indices, GLsizei instancecount, GLuint baseinstance);
void DrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid indices, GLsizei instancecount, GLint basevertex);
void DrawElementsInstancedBaseVertexBaseInstance(GLenum mode, GLsizei count, GLenum type, void * indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
void DrawElementsInstancedEXT(GLenum mode, GLsizei count, GLenum type, GLvoid indices, GLsizei primcount);
void DrawMeshArraysSUN(GLenum mode, GLint first, GLsizei count, GLsizei width);
void DrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels);
void DrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count);
void DrawRangeElementArrayATI(GLenum mode, GLuint start, GLuint end, GLsizei count);
void DrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid indices);
void DrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid indices, GLint basevertex);
void DrawRangeElementsEXT(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, GLvoid indices);
void DrawTextureNV(GLuint texture, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1);
void DrawTransformFeedback(GLenum mode, GLuint id);
void DrawTransformFeedbackInstanced(GLenum mode, GLuint id, GLsizei instancecount);
void DrawTransformFeedbackNV(GLenum mode, GLuint id);
void DrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream);
void DrawTransformFeedbackStreamInstanced(GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);
void EdgeFlag(GLboolean flag);
void EdgeFlagFormatNV(GLsizei stride);
void EdgeFlagPointer(GLsizei stride, GLvoid pointer);
void EdgeFlagPointerEXT(GLsizei stride, GLsizei count, GLboolean pointer);
void EdgeFlagPointerListIBM(GLint stride, GLboolean * pointer, GLint ptrstride);
void EdgeFlagv(GLboolean flag);
void ElementPointerAPPLE(GLenum type, GLvoid pointer);
void ElementPointerATI(GLenum type, GLvoid pointer);
void Enable(GLenum cap);
void EnableClientState(GLenum array);
void EnableClientStateIndexedEXT(GLenum array, GLuint index);
void EnableClientStateiEXT(GLenum array, GLuint index);
void EnableIndexedEXT(GLenum target, GLuint index);
void EnableVariantClientStateEXT(GLuint id);
void EnableVertexArrayAttribEXT(GLuint vaobj, GLuint index);
void EnableVertexArrayEXT(GLuint vaobj, GLenum array);
void EnableVertexAttribAPPLE(GLuint index, GLenum pname);
void EnableVertexAttribArray(GLuint index);
void EnableVertexAttribArrayARB(GLuint index);
void Enablei(GLenum target, GLuint index);
void End();
void EndConditionalRender();
void EndConditionalRenderNV();
void EndConditionalRenderNVX();
void EndFragmentShaderATI();
void EndList();
void EndOcclusionQueryNV();
void EndPerfMonitorAMD(GLuint monitor);
void EndQuery(GLenum target);
void EndQueryARB(GLenum target);
void EndQueryIndexed(GLenum target, GLuint index);
void EndTransformFeedback();
void EndTransformFeedbackEXT();
void EndTransformFeedbackNV();
void EndVertexShaderEXT();
void EndVideoCaptureNV(GLuint video_capture_slot);
void EvalCoord1d(GLdouble u);
void EvalCoord1dv(GLdouble u);
void EvalCoord1f(GLfloat u);
void EvalCoord1fv(GLfloat u);
void EvalCoord1xOES(GLfixed u);
void EvalCoord1xvOES(GLfixed coords);
void EvalCoord2d(GLdouble u, GLdouble v);
void EvalCoord2dv(GLdouble u);
void EvalCoord2f(GLfloat u, GLfloat v);
void EvalCoord2fv(GLfloat u);
void EvalCoord2xOES(GLfixed u, GLfixed v);
void EvalCoord2xvOES(GLfixed coords);
void EvalMapsNV(GLenum target, GLenum mode);
void EvalMesh1(GLenum mode, GLint i1, GLint i2);
void EvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
void EvalPoint1(GLint i);
void EvalPoint2(GLint i, GLint j);
void ExecuteProgramNV(GLenum target, GLuint id, GLfloat params);
void ExtractComponentEXT(GLuint res, GLuint src, GLuint num);
void FeedbackBuffer(GLsizei size, GLenum type, GLfloat buffer);
void FeedbackBufferxOES(GLsizei n, GLenum type, GLfixed buffer);
sync FenceSync(GLenum condition, GLbitfield flags);
void FinalCombinerInputNV(GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
void Finish();
Int32 FinishAsyncSGIX(GLuint markerp);
void FinishFenceAPPLE(GLuint fence);
void FinishFenceNV(GLuint fence);
void FinishObjectAPPLE(GLenum object, GLint name);
void FinishTextureSUNX();
void Flush();
void FlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length);
void FlushMappedBufferRangeAPPLE(GLenum target, GLintptr offset, GLsizeiptr size);
void FlushMappedNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length);
void FlushPixelDataRangeNV(GLenum target);
void FlushRasterSGIX();
void FlushStaticDataIBM(GLenum target);
void FlushVertexArrayRangeAPPLE(GLsizei length, GLvoid pointer);
void FlushVertexArrayRangeNV();
void FogCoordFormatNV(GLenum type, GLsizei stride);
void FogCoordPointer(GLenum type, GLsizei stride, GLvoid pointer);
void FogCoordPointerEXT(GLenum type, GLsizei stride, GLvoid pointer);
void FogCoordPointerListIBM(GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride);
void FogCoordd(GLdouble coord);
void FogCoorddEXT(GLdouble coord);
void FogCoorddv(GLdouble coord);
void FogCoorddvEXT(GLdouble coord);
void FogCoordf(GLfloat coord);
void FogCoordfEXT(GLfloat coord);
void FogCoordfv(GLfloat coord);
void FogCoordfvEXT(GLfloat coord);
void FogCoordhNV(GLhalfNV fog);
void FogCoordhvNV(GLhalfNV fog);
void FogFuncSGIS(GLsizei n, GLfloat points);
void Fogf(GLenum pname, GLfloat param);
void Fogfv(GLenum pname, GLfloat params);
void Fogi(GLenum pname, GLint param);
void Fogiv(GLenum pname, GLint params);
void FogxOES(GLenum pname, GLfixed param);
void FogxvOES(GLenum pname, GLfixed param);
void FragmentColorMaterialSGIX(GLenum face, GLenum mode);
void FragmentLightModelfSGIX(GLenum pname, GLfloat param);
void FragmentLightModelfvSGIX(GLenum pname, GLfloat params);
void FragmentLightModeliSGIX(GLenum pname, GLint param);
void FragmentLightModelivSGIX(GLenum pname, GLint params);
void FragmentLightfSGIX(GLenum light, GLenum pname, GLfloat param);
void FragmentLightfvSGIX(GLenum light, GLenum pname, GLfloat params);
void FragmentLightiSGIX(GLenum light, GLenum pname, GLint param);
void FragmentLightivSGIX(GLenum light, GLenum pname, GLint params);
void FragmentMaterialfSGIX(GLenum face, GLenum pname, GLfloat param);
void FragmentMaterialfvSGIX(GLenum face, GLenum pname, GLfloat params);
void FragmentMaterialiSGIX(GLenum face, GLenum pname, GLint param);
void FragmentMaterialivSGIX(GLenum face, GLenum pname, GLint params);
void FrameTerminatorGREMEDY();
void FrameZoomSGIX(GLint factor);
void FramebufferDrawBufferEXT(GLuint framebuffer, GLenum mode);
void FramebufferDrawBuffersEXT(GLuint framebuffer, GLsizei n, GLenum bufs);
void FramebufferParameteri(GLenum target, GLenum pname, GLint param);
void FramebufferReadBufferEXT(GLuint framebuffer, GLenum mode);
void FramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
void FramebufferRenderbufferEXT(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
void FramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level);
void FramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void FramebufferTexture1DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void FramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void FramebufferTexture2DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void FramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
void FramebufferTexture3DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
void FramebufferTextureARB(GLenum target, GLenum attachment, GLuint texture, GLint level);
void FramebufferTextureEXT(GLenum target, GLenum attachment, GLuint texture, GLint level);
void FramebufferTextureFaceARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
void FramebufferTextureFaceEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);
void FramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
void FramebufferTextureLayerARB(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
void FramebufferTextureLayerEXT(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
void FreeObjectBufferATI(GLuint buffer);
void FrontFace(GLenum mode);
void Frustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
void FrustumfOES(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
void FrustumxOES(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f);
UInt32 GenAsyncMarkersSGIX(GLsizei range);
void GenBuffers(GLsizei n, GLuint buffers);
void GenBuffersARB(GLsizei n, GLuint buffers);
void GenFencesAPPLE(GLsizei n, GLuint fences);
void GenFencesNV(GLsizei n, GLuint fences);
UInt32 GenFragmentShadersATI(GLuint range);
void GenFramebuffers(GLsizei n, GLuint framebuffers);
void GenFramebuffersEXT(GLsizei n, GLuint framebuffers);
List GenLists(GLsizei range);
void GenNamesAMD(GLenum identifier, GLuint num, GLuint names);
void GenOcclusionQueriesNV(GLsizei n, GLuint ids);
Path GenPathsNV(GLsizei range);
void GenPerfMonitorsAMD(GLsizei n, GLuint monitors);
void GenProgramPipelines(GLsizei n, GLuint pipelines);
void GenProgramsARB(GLsizei n, GLuint programs);
void GenProgramsNV(GLsizei n, GLuint programs);
void GenQueries(GLsizei n, GLuint ids);
void GenQueriesARB(GLsizei n, GLuint ids);
void GenRenderbuffers(GLsizei n, GLuint renderbuffers);
void GenRenderbuffersEXT(GLsizei n, GLuint renderbuffers);
void GenSamplers(GLsizei count, GLuint samplers);
UInt32 GenSymbolsEXT(GLenum datatype, GLenum storagetype, GLenum range, GLuint components);
void GenTextures(GLsizei n, GLuint textures);
void GenTexturesEXT(GLsizei n, GLuint textures);
void GenTransformFeedbacks(GLsizei n, GLuint ids);
void GenTransformFeedbacksNV(GLsizei n, GLuint ids);
void GenVertexArrays(GLsizei n, GLuint arrays);
void GenVertexArraysAPPLE(GLsizei n, GLuint arrays);
UInt32 GenVertexShadersEXT(GLuint range);
void GenerateMipmap(GLenum target);
void GenerateMipmapEXT(GLenum target);
void GenerateMultiTexMipmapEXT(GLenum texunit, GLenum target);
void GenerateTextureMipmapEXT(GLuint texture, GLenum target);
void GetActiveAtomicCounterBufferiv(GLuint program, GLuint bufferIndex, GLenum pname, GLint params);
void GetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLint size, GLenum type, GLchar name);
void GetActiveAttribARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei length, GLint size, GLenum type, GLcharARB name);
void GetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei length, GLchar name);
void GetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei length, GLchar name);
void GetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint values);
void GetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLint size, GLenum type, GLchar name);
void GetActiveUniformARB(GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei length, GLint size, GLenum type, GLcharARB name);
void GetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei length, GLchar uniformBlockName);
void GetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint params);
void GetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei length, GLchar uniformName);
void GetActiveUniformsiv(GLuint program, GLsizei uniformCount, GLuint uniformIndices, GLenum pname, GLint params);
void GetActiveVaryingNV(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLsizei size, GLenum type, GLchar name);
void GetArrayObjectfvATI(GLenum array, GLenum pname, GLfloat params);
void GetArrayObjectivATI(GLenum array, GLenum pname, GLint params);
void GetAttachedObjectsARB(GLhandleARB containerObj, GLsizei maxCount, GLsizei count, GLhandleARB obj);
void GetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei count, GLuint obj);
Int32 GetAttribLocation(GLuint program, GLchar name);
Int32 GetAttribLocationARB(GLhandleARB programObj, GLcharARB name);
void GetBooleanIndexedvEXT(GLenum target, GLuint index, GLboolean data);
void GetBooleani_v(GLenum target, GLuint index, GLboolean data);
void GetBooleanv(GLenum pname, GLboolean params);
void GetBufferParameteri64v(GLenum target, GLenum pname, GLint64 params);
void GetBufferParameteriv(GLenum target, GLenum pname, GLint params);
void GetBufferParameterivARB(GLenum target, GLenum pname, GLint params);
void GetBufferParameterui64vNV(GLenum target, GLenum pname, GLuint64EXT params);
void GetBufferPointerv(GLenum target, GLenum pname, GLvoid * params);
void GetBufferPointervARB(GLenum target, GLenum pname, GLvoid * params);
void GetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, GLvoid data);
void GetBufferSubDataARB(GLenum target, GLintptrARB offset, GLsizeiptrARB size, GLvoid data);
void GetClipPlane(GLenum plane, GLdouble equation);
void GetClipPlanefOES(GLenum plane, GLfloat equation);
void GetClipPlanexOES(GLenum plane, GLfixed equation);
void GetColorTable(GLenum target, GLenum format, GLenum type, GLvoid table);
void GetColorTableEXT(GLenum target, GLenum format, GLenum type, GLvoid data);
void GetColorTableParameterfv(GLenum target, GLenum pname, GLfloat params);
void GetColorTableParameterfvEXT(GLenum target, GLenum pname, GLfloat params);
void GetColorTableParameterfvSGI(GLenum target, GLenum pname, GLfloat params);
void GetColorTableParameteriv(GLenum target, GLenum pname, GLint params);
void GetColorTableParameterivEXT(GLenum target, GLenum pname, GLint params);
void GetColorTableParameterivSGI(GLenum target, GLenum pname, GLint params);
void GetColorTableSGI(GLenum target, GLenum format, GLenum type, GLvoid table);
void GetCombinerInputParameterfvNV(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat params);
void GetCombinerInputParameterivNV(GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint params);
void GetCombinerOutputParameterfvNV(GLenum stage, GLenum portion, GLenum pname, GLfloat params);
void GetCombinerOutputParameterivNV(GLenum stage, GLenum portion, GLenum pname, GLint params);
void GetCombinerStageParameterfvNV(GLenum stage, GLenum pname, GLfloat params);
void GetCompressedMultiTexImageEXT(GLenum texunit, GLenum target, GLint lod, GLvoid img);
void GetCompressedTexImage(GLenum target, GLint level, GLvoid img);
void GetCompressedTexImageARB(GLenum target, GLint level, GLvoid img);
void GetCompressedTextureImageEXT(GLuint texture, GLenum target, GLint lod, GLvoid img);
void GetConvolutionFilter(GLenum target, GLenum format, GLenum type, GLvoid image);
void GetConvolutionFilterEXT(GLenum target, GLenum format, GLenum type, GLvoid image);
void GetConvolutionParameterfv(GLenum target, GLenum pname, GLfloat params);
void GetConvolutionParameterfvEXT(GLenum target, GLenum pname, GLfloat params);
void GetConvolutionParameteriv(GLenum target, GLenum pname, GLint params);
void GetConvolutionParameterivEXT(GLenum target, GLenum pname, GLint params);
void GetConvolutionParameterxvOES(GLenum target, GLenum pname, GLfixed params);
UInt32 GetDebugMessageLog(GLuint count, GLsizei bufsize, GLenum sources, GLenum types, GLuint ids, GLenum severities, GLsizei lengths, GLchar messageLog);
UInt32 GetDebugMessageLogAMD(GLuint count, GLsizei bufsize, GLenum categories, GLuint severities, GLuint ids, GLsizei lengths, GLchar message);
UInt32 GetDebugMessageLogARB(GLuint count, GLsizei bufsize, GLenum sources, GLenum types, GLuint ids, GLenum severities, GLsizei lengths, GLchar messageLog);
void GetDetailTexFuncSGIS(GLenum target, GLfloat points);
void GetDoubleIndexedvEXT(GLenum target, GLuint index, GLdouble data);
void GetDoublei_v(GLenum target, GLuint index, GLdouble data);
void GetDoublei_vEXT(GLenum target, GLuint index, GLdouble data);
void GetDoublev(GLenum pname, GLdouble params);
ErrorCode GetError();
void GetFenceivNV(GLuint fence, GLenum pname, GLint params);
void GetFinalCombinerInputParameterfvNV(GLenum variable, GLenum pname, GLfloat params);
void GetFinalCombinerInputParameterivNV(GLenum variable, GLenum pname, GLint params);
void GetFixedvOES(GLenum pname, GLfixed params);
void GetFloatIndexedvEXT(GLenum target, GLuint index, GLfloat data);
void GetFloati_v(GLenum target, GLuint index, GLfloat data);
void GetFloati_vEXT(GLenum target, GLuint index, GLfloat data);
void GetFloatv(GLenum pname, GLfloat params);
void GetFogFuncSGIS(GLfloat points);
Int32 GetFragDataIndex(GLuint program, GLchar name);
Int32 GetFragDataLocation(GLuint program, GLchar name);
Int32 GetFragDataLocationEXT(GLuint program, GLchar name);
void GetFragmentLightfvSGIX(GLenum light, GLenum pname, GLfloat params);
void GetFragmentLightivSGIX(GLenum light, GLenum pname, GLint params);
void GetFragmentMaterialfvSGIX(GLenum face, GLenum pname, GLfloat params);
void GetFragmentMaterialivSGIX(GLenum face, GLenum pname, GLint params);
void GetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint params);
void GetFramebufferAttachmentParameterivEXT(GLenum target, GLenum attachment, GLenum pname, GLint params);
void GetFramebufferParameteriv(GLenum target, GLenum pname, GLint params);
void GetFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint params);
GLenum GetGraphicsResetStatusARB();
handleARB GetHandleARB(GLenum pname);
void GetHistogram(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid values);
void GetHistogramEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid values);
void GetHistogramParameterfv(GLenum target, GLenum pname, GLfloat params);
void GetHistogramParameterfvEXT(GLenum target, GLenum pname, GLfloat params);
void GetHistogramParameteriv(GLenum target, GLenum pname, GLint params);
void GetHistogramParameterivEXT(GLenum target, GLenum pname, GLint params);
void GetHistogramParameterxvOES(GLenum target, GLenum pname, GLfixed params);
UInt64 GetImageHandleNV(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
void GetImageTransformParameterfvHP(GLenum target, GLenum pname, GLfloat params);
void GetImageTransformParameterivHP(GLenum target, GLenum pname, GLint params);
void GetInfoLogARB(GLhandleARB obj, GLsizei maxLength, GLsizei length, GLcharARB infoLog);
Int32 GetInstrumentsSGIX();
void GetInteger64i_v(GLenum target, GLuint index, GLint64 data);
void GetInteger64v(GLenum pname, GLint64 params);
void GetIntegerIndexedvEXT(GLenum target, GLuint index, GLint data);
void GetIntegeri_v(GLenum target, GLuint index, GLint data);
void GetIntegerui64i_vNV(GLenum value, GLuint index, GLuint64EXT result);
void GetIntegerui64vNV(GLenum value, GLuint64EXT result);
void GetIntegerv(GLenum pname, GLint params);
void GetInternalformati64v(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 params);
void GetInternalformativ(GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint params);
void GetInvariantBooleanvEXT(GLuint id, GLenum value, GLboolean data);
void GetInvariantFloatvEXT(GLuint id, GLenum value, GLfloat data);
void GetInvariantIntegervEXT(GLuint id, GLenum value, GLint data);
void GetLightfv(GLenum light, GLenum pname, GLfloat params);
void GetLightiv(GLenum light, GLenum pname, GLint params);
void GetLightxOES(GLenum light, GLenum pname, GLfixed params);
void GetListParameterfvSGIX(GLuint list, GLenum pname, GLfloat params);
void GetListParameterivSGIX(GLuint list, GLenum pname, GLint params);
void GetLocalConstantBooleanvEXT(GLuint id, GLenum value, GLboolean data);
void GetLocalConstantFloatvEXT(GLuint id, GLenum value, GLfloat data);
void GetLocalConstantIntegervEXT(GLuint id, GLenum value, GLint data);
void GetMapAttribParameterfvNV(GLenum target, GLuint index, GLenum pname, GLfloat params);
void GetMapAttribParameterivNV(GLenum target, GLuint index, GLenum pname, GLint params);
void GetMapControlPointsNV(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLboolean packed, GLvoid points);
void GetMapParameterfvNV(GLenum target, GLenum pname, GLfloat params);
void GetMapParameterivNV(GLenum target, GLenum pname, GLint params);
void GetMapdv(GLenum target, GLenum query, GLdouble v);
void GetMapfv(GLenum target, GLenum query, GLfloat v);
void GetMapiv(GLenum target, GLenum query, GLint v);
void GetMapxvOES(GLenum target, GLenum query, GLfixed v);
void GetMaterialfv(GLenum face, GLenum pname, GLfloat params);
void GetMaterialiv(GLenum face, GLenum pname, GLint params);
void GetMaterialxOES(GLenum face, GLenum pname, GLfixed param);
void GetMinmax(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid values);
void GetMinmaxEXT(GLenum target, GLboolean reset, GLenum format, GLenum type, GLvoid values);
void GetMinmaxParameterfv(GLenum target, GLenum pname, GLfloat params);
void GetMinmaxParameterfvEXT(GLenum target, GLenum pname, GLfloat params);
void GetMinmaxParameteriv(GLenum target, GLenum pname, GLint params);
void GetMinmaxParameterivEXT(GLenum target, GLenum pname, GLint params);
void GetMultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat params);
void GetMultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint params);
void GetMultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble params);
void GetMultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat params);
void GetMultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint params);
void GetMultiTexImageEXT(GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, GLvoid pixels);
void GetMultiTexLevelParameterfvEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat params);
void GetMultiTexLevelParameterivEXT(GLenum texunit, GLenum target, GLint level, GLenum pname, GLint params);
void GetMultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, GLint params);
void GetMultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, GLuint params);
void GetMultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat params);
void GetMultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint params);
void GetMultisamplefv(GLenum pname, GLuint index, GLfloat val);
void GetMultisamplefvNV(GLenum pname, GLuint index, GLfloat val);
void GetNamedBufferParameterivEXT(GLuint buffer, GLenum pname, GLint params);
void GetNamedBufferParameterui64vNV(GLuint buffer, GLenum pname, GLuint64EXT params);
void GetNamedBufferPointervEXT(GLuint buffer, GLenum pname, GLvoid * params);
void GetNamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid data);
void GetNamedFramebufferAttachmentParameterivEXT(GLuint framebuffer, GLenum attachment, GLenum pname, GLint params);
void GetNamedFramebufferParameterivEXT(GLuint framebuffer, GLenum pname, GLint params);
void GetNamedProgramLocalParameterIivEXT(GLuint program, GLenum target, GLuint index, GLint params);
void GetNamedProgramLocalParameterIuivEXT(GLuint program, GLenum target, GLuint index, GLuint params);
void GetNamedProgramLocalParameterdvEXT(GLuint program, GLenum target, GLuint index, GLdouble params);
void GetNamedProgramLocalParameterfvEXT(GLuint program, GLenum target, GLuint index, GLfloat params);
void GetNamedProgramStringEXT(GLuint program, GLenum target, GLenum pname, GLvoid string);
void GetNamedProgramivEXT(GLuint program, GLenum target, GLenum pname, GLint params);
void GetNamedRenderbufferParameterivEXT(GLuint renderbuffer, GLenum pname, GLint params);
void GetNamedStringARB(GLint namelen, GLchar name, GLsizei bufSize, GLint stringlen, GLchar string);
void GetNamedStringivARB(GLint namelen, GLchar name, GLenum pname, GLint params);
void GetObjectBufferfvATI(GLuint buffer, GLenum pname, GLfloat params);
void GetObjectBufferivATI(GLuint buffer, GLenum pname, GLint params);
void GetObjectLabel(GLenum identifier, GLuint name, GLsizei bufSize, GLsizei length, GLchar label);
void GetObjectParameterfvARB(GLhandleARB obj, GLenum pname, GLfloat params);
void GetObjectParameterivAPPLE(GLenum objectType, GLuint name, GLenum pname, GLint params);
void GetObjectParameterivARB(GLhandleARB obj, GLenum pname, GLint params);
void GetObjectPtrLabel(void * ptr, GLsizei bufSize, GLsizei length, GLchar label);
void GetOcclusionQueryivNV(GLuint id, GLenum pname, GLint params);
void GetOcclusionQueryuivNV(GLuint id, GLenum pname, GLuint params);
void GetPathColorGenfvNV(GLenum color, GLenum pname, GLfloat value);
void GetPathColorGenivNV(GLenum color, GLenum pname, GLint value);
void GetPathCommandsNV(GLuint path, GLubyte commands);
void GetPathCoordsNV(GLuint path, GLfloat coords);
void GetPathDashArrayNV(GLuint path, GLfloat dashArray);
Float32 GetPathLengthNV(GLuint path, GLsizei startSegment, GLsizei numSegments);
void GetPathMetricRangeNV(GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat metrics);
void GetPathMetricsNV(GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLsizei stride, GLfloat metrics);
void GetPathParameterfvNV(GLuint path, GLenum pname, GLfloat value);
void GetPathParameterivNV(GLuint path, GLenum pname, GLint value);
void GetPathSpacingNV(GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat returnedSpacing);
void GetPathTexGenfvNV(GLenum texCoordSet, GLenum pname, GLfloat value);
void GetPathTexGenivNV(GLenum texCoordSet, GLenum pname, GLint value);
void GetPerfMonitorCounterDataAMD(GLuint monitor, GLenum pname, GLsizei dataSize, GLuint data, GLint bytesWritten);
void GetPerfMonitorCounterInfoAMD(GLuint group, GLuint counter, GLenum pname, GLvoid data);
void GetPerfMonitorCounterStringAMD(GLuint group, GLuint counter, GLsizei bufSize, GLsizei length, GLchar counterString);
void GetPerfMonitorCountersAMD(GLuint group, GLint numCounters, GLint maxActiveCounters, GLsizei counterSize, GLuint counters);
void GetPerfMonitorGroupStringAMD(GLuint group, GLsizei bufSize, GLsizei length, GLchar groupString);
void GetPerfMonitorGroupsAMD(GLint numGroups, GLsizei groupsSize, GLuint groups);
void GetPixelMapfv(GLenum map, GLfloat values);
void GetPixelMapuiv(GLenum map, GLuint values);
void GetPixelMapusv(GLenum map, GLushort values);
void GetPixelMapxv(GLenum map, GLint size, GLfixed values);
void GetPixelTexGenParameterfvSGIS(GLenum pname, GLfloat params);
void GetPixelTexGenParameterivSGIS(GLenum pname, GLint params);
void GetPixelTransformParameterfvEXT(GLenum target, GLenum pname, GLfloat params);
void GetPixelTransformParameterivEXT(GLenum target, GLenum pname, GLint params);
void GetPointerIndexedvEXT(GLenum target, GLuint index, GLvoid * data);
void GetPointeri_vEXT(GLenum target, GLuint index, GLvoid * data);
void GetPointerv(GLenum pname, GLvoid * params);
void GetPointervEXT(GLenum pname, GLvoid * params);
void GetPolygonStipple(GLubyte mask);
void GetProgramBinary(GLuint program, GLsizei bufSize, GLsizei length, GLenum binaryFormat, GLvoid binary);
void GetProgramEnvParameterIivNV(GLenum target, GLuint index, GLint params);
void GetProgramEnvParameterIuivNV(GLenum target, GLuint index, GLuint params);
void GetProgramEnvParameterdvARB(GLenum target, GLuint index, GLdouble params);
void GetProgramEnvParameterfvARB(GLenum target, GLuint index, GLfloat params);
void GetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei length, GLchar infoLog);
void GetProgramInterfaceiv(GLuint program, GLenum programInterface, GLenum pname, GLint params);
void GetProgramLocalParameterIivNV(GLenum target, GLuint index, GLint params);
void GetProgramLocalParameterIuivNV(GLenum target, GLuint index, GLuint params);
void GetProgramLocalParameterdvARB(GLenum target, GLuint index, GLdouble params);
void GetProgramLocalParameterfvARB(GLenum target, GLuint index, GLfloat params);
void GetProgramNamedParameterdvNV(GLuint id, GLsizei len, GLubyte name, GLdouble params);
void GetProgramNamedParameterfvNV(GLuint id, GLsizei len, GLubyte name, GLfloat params);
void GetProgramParameterdvNV(GLenum target, GLuint index, GLenum pname, GLdouble params);
void GetProgramParameterfvNV(GLenum target, GLuint index, GLenum pname, GLfloat params);
void GetProgramPipelineInfoLog(GLuint pipeline, GLsizei bufSize, GLsizei length, GLchar infoLog);
void GetProgramPipelineiv(GLuint pipeline, GLenum pname, GLint params);
UInt32 GetProgramResourceIndex(GLuint program, GLenum programInterface, GLchar name);
Int32 GetProgramResourceLocation(GLuint program, GLenum programInterface, GLchar name);
Int32 GetProgramResourceLocationIndex(GLuint program, GLenum programInterface, GLchar name);
void GetProgramResourceName(GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei length, GLchar name);
void GetProgramResourceiv(GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, GLenum props, GLsizei bufSize, GLsizei length, GLint params);
void GetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint values);
void GetProgramStringARB(GLenum target, GLenum pname, GLvoid string);
void GetProgramStringNV(GLuint id, GLenum pname, GLubyte program);
void GetProgramSubroutineParameteruivNV(GLenum target, GLuint index, GLuint param);
void GetProgramiv(GLuint program, GLenum pname, GLint params);
void GetProgramivARB(GLenum target, GLenum pname, GLint params);
void GetProgramivNV(GLuint id, GLenum pname, GLint params);
void GetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint params);
void GetQueryObjecti64v(GLuint id, GLenum pname, GLint64 params);
void GetQueryObjecti64vEXT(GLuint id, GLenum pname, GLint64EXT params);
void GetQueryObjectiv(GLuint id, GLenum pname, GLint params);
void GetQueryObjectivARB(GLuint id, GLenum pname, GLint params);
void GetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 params);
void GetQueryObjectui64vEXT(GLuint id, GLenum pname, GLuint64EXT params);
void GetQueryObjectuiv(GLuint id, GLenum pname, GLuint params);
void GetQueryObjectuivARB(GLuint id, GLenum pname, GLuint params);
void GetQueryiv(GLenum target, GLenum pname, GLint params);
void GetQueryivARB(GLenum target, GLenum pname, GLint params);
void GetRenderbufferParameteriv(GLenum target, GLenum pname, GLint params);
void GetRenderbufferParameterivEXT(GLenum target, GLenum pname, GLint params);
void GetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint params);
void GetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint params);
void GetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat params);
void GetSamplerParameteriv(GLuint sampler, GLenum pname, GLint params);
void GetSeparableFilter(GLenum target, GLenum format, GLenum type, GLvoid row, GLvoid column, GLvoid span);
void GetSeparableFilterEXT(GLenum target, GLenum format, GLenum type, GLvoid row, GLvoid column, GLvoid span);
void GetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei length, GLchar infoLog);
void GetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint range, GLint precision);
void GetShaderSource(GLuint shader, GLsizei bufSize, GLsizei length, GLchar source);
void GetShaderSourceARB(GLhandleARB obj, GLsizei maxLength, GLsizei length, GLcharARB source);
void GetShaderiv(GLuint shader, GLenum pname, GLint params);
void GetSharpenTexFuncSGIS(GLenum target, GLfloat points);
String GetString(GLenum name);
String GetStringi(GLenum name, GLuint index);
UInt32 GetSubroutineIndex(GLuint program, GLenum shadertype, GLchar name);
Int32 GetSubroutineUniformLocation(GLuint program, GLenum shadertype, GLchar name);
void GetSynciv(GLsync sync, GLenum pname, GLsizei bufSize, GLsizei length, GLint values);
void GetTexBumpParameterfvATI(GLenum pname, GLfloat param);
void GetTexBumpParameterivATI(GLenum pname, GLint param);
void GetTexEnvfv(GLenum target, GLenum pname, GLfloat params);
void GetTexEnviv(GLenum target, GLenum pname, GLint params);
void GetTexEnvxvOES(GLenum target, GLenum pname, GLfixed params);
void GetTexFilterFuncSGIS(GLenum target, GLenum filter, GLfloat weights);
void GetTexGendv(GLenum coord, GLenum pname, GLdouble params);
void GetTexGenfv(GLenum coord, GLenum pname, GLfloat params);
void GetTexGeniv(GLenum coord, GLenum pname, GLint params);
void GetTexGenxvOES(GLenum coord, GLenum pname, GLfixed params);
void GetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid pixels);
void GetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat params);
void GetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint params);
void GetTexLevelParameterxvOES(GLenum target, GLint level, GLenum pname, GLfixed params);
void GetTexParameterIiv(GLenum target, GLenum pname, GLint params);
void GetTexParameterIivEXT(GLenum target, GLenum pname, GLint params);
void GetTexParameterIuiv(GLenum target, GLenum pname, GLuint params);
void GetTexParameterIuivEXT(GLenum target, GLenum pname, GLuint params);
void GetTexParameterPointervAPPLE(GLenum target, GLenum pname, GLvoid * params);
void GetTexParameterfv(GLenum target, GLenum pname, GLfloat params);
void GetTexParameteriv(GLenum target, GLenum pname, GLint params);
void GetTexParameterxvOES(GLenum target, GLenum pname, GLfixed params);
UInt64 GetTextureHandleNV(GLuint texture);
void GetTextureImageEXT(GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, GLvoid pixels);
void GetTextureLevelParameterfvEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat params);
void GetTextureLevelParameterivEXT(GLuint texture, GLenum target, GLint level, GLenum pname, GLint params);
void GetTextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, GLint params);
void GetTextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, GLuint params);
void GetTextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat params);
void GetTextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint params);
UInt64 GetTextureSamplerHandleNV(GLuint texture, GLuint sampler);
void GetTrackMatrixivNV(GLenum target, GLuint address, GLenum pname, GLint params);
void GetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLsizei size, GLenum type, GLchar name);
void GetTransformFeedbackVaryingEXT(GLuint program, GLuint index, GLsizei bufSize, GLsizei length, GLsizei size, GLenum type, GLchar name);
void GetTransformFeedbackVaryingNV(GLuint program, GLuint index, GLint location);
UInt32 GetUniformBlockIndex(GLuint program, GLchar uniformBlockName);
Int32 GetUniformBufferSizeEXT(GLuint program, GLint location);
void GetUniformIndices(GLuint program, GLsizei uniformCount, GLchar*const uniformNames, GLuint uniformIndices);
Int32 GetUniformLocation(GLuint program, GLchar name);
Int32 GetUniformLocationARB(GLhandleARB programObj, GLcharARB name);
BufferOffset GetUniformOffsetEXT(GLuint program, GLint location);
void GetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint params);
void GetUniformdv(GLuint program, GLint location, GLdouble params);
void GetUniformfv(GLuint program, GLint location, GLfloat params);
void GetUniformfvARB(GLhandleARB programObj, GLint location, GLfloat params);
void GetUniformi64vNV(GLuint program, GLint location, GLint64EXT params);
void GetUniformiv(GLuint program, GLint location, GLint params);
void GetUniformivARB(GLhandleARB programObj, GLint location, GLint params);
void GetUniformui64vNV(GLuint program, GLint location, GLuint64EXT params);
void GetUniformuiv(GLuint program, GLint location, GLuint params);
void GetUniformuivEXT(GLuint program, GLint location, GLuint params);
void GetVariantArrayObjectfvATI(GLuint id, GLenum pname, GLfloat params);
void GetVariantArrayObjectivATI(GLuint id, GLenum pname, GLint params);
void GetVariantBooleanvEXT(GLuint id, GLenum value, GLboolean data);
void GetVariantFloatvEXT(GLuint id, GLenum value, GLfloat data);
void GetVariantIntegervEXT(GLuint id, GLenum value, GLint data);
void GetVariantPointervEXT(GLuint id, GLenum value, GLvoid * data);
Int32 GetVaryingLocationNV(GLuint program, GLchar name);
void GetVertexArrayIntegeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, GLint param);
void GetVertexArrayIntegervEXT(GLuint vaobj, GLenum pname, GLint param);
void GetVertexArrayPointeri_vEXT(GLuint vaobj, GLuint index, GLenum pname, GLvoid * param);
void GetVertexArrayPointervEXT(GLuint vaobj, GLenum pname, GLvoid * param);
void GetVertexAttribArrayObjectfvATI(GLuint index, GLenum pname, GLfloat params);
void GetVertexAttribArrayObjectivATI(GLuint index, GLenum pname, GLint params);
void GetVertexAttribIiv(GLuint index, GLenum pname, GLint params);
void GetVertexAttribIivEXT(GLuint index, GLenum pname, GLint params);
void GetVertexAttribIuiv(GLuint index, GLenum pname, GLuint params);
void GetVertexAttribIuivEXT(GLuint index, GLenum pname, GLuint params);
void GetVertexAttribLdv(GLuint index, GLenum pname, GLdouble params);
void GetVertexAttribLdvEXT(GLuint index, GLenum pname, GLdouble params);
void GetVertexAttribLi64vNV(GLuint index, GLenum pname, GLint64EXT params);
void GetVertexAttribLui64vNV(GLuint index, GLenum pname, GLuint64EXT params);
void GetVertexAttribPointerv(GLuint index, GLenum pname, GLvoid * pointer);
void GetVertexAttribPointervARB(GLuint index, GLenum pname, GLvoid * pointer);
void GetVertexAttribPointervNV(GLuint index, GLenum pname, GLvoid * pointer);
void GetVertexAttribdv(GLuint index, GLenum pname, GLdouble params);
void GetVertexAttribdvARB(GLuint index, GLenum pname, GLdouble params);
void GetVertexAttribdvNV(GLuint index, GLenum pname, GLdouble params);
void GetVertexAttribfv(GLuint index, GLenum pname, GLfloat params);
void GetVertexAttribfvARB(GLuint index, GLenum pname, GLfloat params);
void GetVertexAttribfvNV(GLuint index, GLenum pname, GLfloat params);
void GetVertexAttribiv(GLuint index, GLenum pname, GLint params);
void GetVertexAttribivARB(GLuint index, GLenum pname, GLint params);
void GetVertexAttribivNV(GLuint index, GLenum pname, GLint params);
void GetVideoCaptureStreamdvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble params);
void GetVideoCaptureStreamfvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat params);
void GetVideoCaptureStreamivNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLint params);
void GetVideoCaptureivNV(GLuint video_capture_slot, GLenum pname, GLint params);
void GetVideoi64vNV(GLuint video_slot, GLenum pname, GLint64EXT params);
void GetVideoivNV(GLuint video_slot, GLenum pname, GLint params);
void GetVideoui64vNV(GLuint video_slot, GLenum pname, GLuint64EXT params);
void GetVideouivNV(GLuint video_slot, GLenum pname, GLuint params);
void GetnColorTableARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, GLvoid table);
void GetnCompressedTexImageARB(GLenum target, GLint lod, GLsizei bufSize, GLvoid img);
void GetnConvolutionFilterARB(GLenum target, GLenum format, GLenum type, GLsizei bufSize, GLvoid image);
void GetnHistogramARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, GLvoid values);
void GetnMapdvARB(GLenum target, GLenum query, GLsizei bufSize, GLdouble v);
void GetnMapfvARB(GLenum target, GLenum query, GLsizei bufSize, GLfloat v);
void GetnMapivARB(GLenum target, GLenum query, GLsizei bufSize, GLint v);
void GetnMinmaxARB(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, GLvoid values);
void GetnPixelMapfvARB(GLenum map, GLsizei bufSize, GLfloat values);
void GetnPixelMapuivARB(GLenum map, GLsizei bufSize, GLuint values);
void GetnPixelMapusvARB(GLenum map, GLsizei bufSize, GLushort values);
void GetnPolygonStippleARB(GLsizei bufSize, GLubyte pattern);
void GetnSeparableFilterARB(GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, GLvoid row, GLsizei columnBufSize, GLvoid column, GLvoid span);
void GetnTexImageARB(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, GLvoid img);
void GetnUniformdvARB(GLuint program, GLint location, GLsizei bufSize, GLdouble params);
void GetnUniformfvARB(GLuint program, GLint location, GLsizei bufSize, GLfloat params);
void GetnUniformivARB(GLuint program, GLint location, GLsizei bufSize, GLint params);
void GetnUniformuivARB(GLuint program, GLint location, GLsizei bufSize, GLuint params);
void GlobalAlphaFactorbSUN(GLbyte factor);
void GlobalAlphaFactordSUN(GLdouble factor);
void GlobalAlphaFactorfSUN(GLfloat factor);
void GlobalAlphaFactoriSUN(GLint factor);
void GlobalAlphaFactorsSUN(GLshort factor);
void GlobalAlphaFactorubSUN(GLubyte factor);
void GlobalAlphaFactoruiSUN(GLuint factor);
void GlobalAlphaFactorusSUN(GLushort factor);
void Hint(GLenum target, GLenum mode);
void HintPGI(GLenum target, GLint mode);
void Histogram(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
void HistogramEXT(GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
void IglooInterfaceSGIX(GLenum pname, GLvoid params);
void ImageTransformParameterfHP(GLenum target, GLenum pname, GLfloat param);
void ImageTransformParameterfvHP(GLenum target, GLenum pname, GLfloat params);
void ImageTransformParameteriHP(GLenum target, GLenum pname, GLint param);
void ImageTransformParameterivHP(GLenum target, GLenum pname, GLint params);
sync ImportSyncEXT(GLenum external_sync_type, GLintptr external_sync, GLbitfield flags);
void IndexFormatNV(GLenum type, GLsizei stride);
void IndexFuncEXT(GLenum func, GLclampf ref);
void IndexMask(GLuint mask);
void IndexMaterialEXT(GLenum face, GLenum mode);
void IndexPointer(GLenum type, GLsizei stride, GLvoid pointer);
void IndexPointerEXT(GLenum type, GLsizei stride, GLsizei count, GLvoid pointer);
void IndexPointerListIBM(GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride);
void Indexd(GLdouble c);
void Indexdv(GLdouble c);
void Indexf(GLfloat c);
void Indexfv(GLfloat c);
void Indexi(GLint c);
void Indexiv(GLint c);
void Indexs(GLshort c);
void Indexsv(GLshort c);
void Indexub(GLubyte c);
void Indexubv(GLubyte c);
void IndexxOES(GLfixed component);
void IndexxvOES(GLfixed component);
void InitNames();
void InsertComponentEXT(GLuint res, GLuint src, GLuint num);
void InstrumentsBufferSGIX(GLsizei size, GLint buffer);
void InterleavedArrays(GLenum format, GLsizei stride, GLvoid pointer);
void InterpolatePathsNV(GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight);
void InvalidateBufferData(GLuint buffer);
void InvalidateBufferSubData(GLuint buffer, GLintptr offset, GLsizeiptr length);
void InvalidateFramebuffer(GLenum target, GLsizei numAttachments, GLenum attachments);
void InvalidateSubFramebuffer(GLenum target, GLsizei numAttachments, GLenum attachments, GLint x, GLint y, GLsizei width, GLsizei height);
void InvalidateTexImage(GLuint texture, GLint level);
void InvalidateTexSubImage(GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
Boolean IsAsyncMarkerSGIX(GLuint marker);
Boolean IsBuffer(GLuint buffer);
Boolean IsBufferARB(GLuint buffer);
Boolean IsBufferResidentNV(GLenum target);
Boolean IsEnabled(GLenum cap);
Boolean IsEnabledIndexedEXT(GLenum target, GLuint index);
Boolean IsEnabledi(GLenum target, GLuint index);
Boolean IsFenceAPPLE(GLuint fence);
Boolean IsFenceNV(GLuint fence);
Boolean IsFramebuffer(GLuint framebuffer);
Boolean IsFramebufferEXT(GLuint framebuffer);
Boolean IsImageHandleResidentNV(GLuint64 handle);
Boolean IsList(GLuint list);
Boolean IsNameAMD(GLenum identifier, GLuint name);
Boolean IsNamedBufferResidentNV(GLuint buffer);
Boolean IsNamedStringARB(GLint namelen, GLchar name);
Boolean IsObjectBufferATI(GLuint buffer);
Boolean IsOcclusionQueryNV(GLuint id);
Boolean IsPathNV(GLuint path);
Boolean IsPointInFillPathNV(GLuint path, GLuint mask, GLfloat x, GLfloat y);
Boolean IsPointInStrokePathNV(GLuint path, GLfloat x, GLfloat y);
Boolean IsProgram(GLuint program);
Boolean IsProgramARB(GLuint program);
Boolean IsProgramNV(GLuint id);
Boolean IsProgramPipeline(GLuint pipeline);
Boolean IsQuery(GLuint id);
Boolean IsQueryARB(GLuint id);
Boolean IsRenderbuffer(GLuint renderbuffer);
Boolean IsRenderbufferEXT(GLuint renderbuffer);
Boolean IsSampler(GLuint sampler);
Boolean IsShader(GLuint shader);
Boolean IsSync(GLsync sync);
Boolean IsTexture(GLuint texture);
Boolean IsTextureEXT(GLuint texture);
Boolean IsTextureHandleResidentNV(GLuint64 handle);
Boolean IsTransformFeedback(GLuint id);
Boolean IsTransformFeedbackNV(GLuint id);
Boolean IsVariantEnabledEXT(GLuint id, GLenum cap);
Boolean IsVertexArray(GLuint array);
Boolean IsVertexArrayAPPLE(GLuint array);
Boolean IsVertexAttribEnabledAPPLE(GLuint index, GLenum pname);
void LightEnviSGIX(GLenum pname, GLint param);
void LightModelf(GLenum pname, GLfloat param);
void LightModelfv(GLenum pname, GLfloat params);
void LightModeli(GLenum pname, GLint param);
void LightModeliv(GLenum pname, GLint params);
void LightModelxOES(GLenum pname, GLfixed param);
void LightModelxvOES(GLenum pname, GLfixed param);
void Lightf(GLenum light, GLenum pname, GLfloat param);
void Lightfv(GLenum light, GLenum pname, GLfloat params);
void Lighti(GLenum light, GLenum pname, GLint param);
void Lightiv(GLenum light, GLenum pname, GLint params);
void LightxOES(GLenum light, GLenum pname, GLfixed param);
void LightxvOES(GLenum light, GLenum pname, GLfixed params);
void LineStipple(GLint factor, GLushort pattern);
void LineWidth(GLfloat width);
void LineWidthxOES(GLfixed width);
void LinkProgram(GLuint program);
void LinkProgramARB(GLhandleARB programObj);
void ListBase(GLuint base);
void ListParameterfSGIX(GLuint list, GLenum pname, GLfloat param);
void ListParameterfvSGIX(GLuint list, GLenum pname, GLfloat params);
void ListParameteriSGIX(GLuint list, GLenum pname, GLint param);
void ListParameterivSGIX(GLuint list, GLenum pname, GLint params);
void LoadIdentity();
void LoadIdentityDeformationMapSGIX(GLbitfield mask);
void LoadMatrixd(GLdouble m);
void LoadMatrixf(GLfloat m);
void LoadMatrixxOES(GLfixed m);
void LoadName(GLuint name);
void LoadProgramNV(GLenum target, GLuint id, GLsizei len, GLubyte program);
void LoadTransposeMatrixd(GLdouble m);
void LoadTransposeMatrixdARB(GLdouble m);
void LoadTransposeMatrixf(GLfloat m);
void LoadTransposeMatrixfARB(GLfloat m);
void LoadTransposeMatrixxOES(GLfixed m);
void LockArraysEXT(GLint first, GLsizei count);
void LogicOp(GLenum opcode);
void MakeBufferNonResidentNV(GLenum target);
void MakeBufferResidentNV(GLenum target, GLenum access);
void MakeImageHandleNonResidentNV(GLuint64 handle);
void MakeImageHandleResidentNV(GLuint64 handle, GLenum access);
void MakeNamedBufferNonResidentNV(GLuint buffer);
void MakeNamedBufferResidentNV(GLuint buffer, GLenum access);
void MakeTextureHandleNonResidentNV(GLuint64 handle);
void MakeTextureHandleResidentNV(GLuint64 handle);
void Map1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, GLdouble points);
void Map1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, GLfloat points);
void Map1xOES(GLenum target, GLfixed u1, GLfixed u2, GLint stride, GLint order, GLfixed points);
void Map2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble points);
void Map2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat points);
void Map2xOES(GLenum target, GLfixed u1, GLfixed u2, GLint ustride, GLint uorder, GLfixed v1, GLfixed v2, GLint vstride, GLint vorder, GLfixed points);
VoidPointer MapBuffer(GLenum target, GLenum access);
VoidPointer MapBufferARB(GLenum target, GLenum access);
VoidPointer MapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
void MapControlPointsNV(GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLint uorder, GLint vorder, GLboolean packed, GLvoid points);
void MapGrid1d(GLint un, GLdouble u1, GLdouble u2);
void MapGrid1f(GLint un, GLfloat u1, GLfloat u2);
void MapGrid1xOES(GLint n, GLfixed u1, GLfixed u2);
void MapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
void MapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
void MapGrid2xOES(GLint n, GLfixed u1, GLfixed u2, GLfixed v1, GLfixed v2);
VoidPointer MapNamedBufferEXT(GLuint buffer, GLenum access);
VoidPointer MapNamedBufferRangeEXT(GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
VoidPointer MapObjectBufferATI(GLuint buffer);
void MapParameterfvNV(GLenum target, GLenum pname, GLfloat params);
void MapParameterivNV(GLenum target, GLenum pname, GLint params);
VoidPointer MapTexture2DINTEL(GLuint texture, GLint level, GLbitfield access, GLint stride, GLenum layout);
void MapVertexAttrib1dAPPLE(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint stride, GLint order, GLdouble points);
void MapVertexAttrib1fAPPLE(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint stride, GLint order, GLfloat points);
void MapVertexAttrib2dAPPLE(GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble points);
void MapVertexAttrib2fAPPLE(GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat points);
void Materialf(GLenum face, GLenum pname, GLfloat param);
void Materialfv(GLenum face, GLenum pname, GLfloat params);
void Materiali(GLenum face, GLenum pname, GLint param);
void Materialiv(GLenum face, GLenum pname, GLint params);
void MaterialxOES(GLenum face, GLenum pname, GLfixed param);
void MaterialxvOES(GLenum face, GLenum pname, GLfixed param);
void MatrixFrustumEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
void MatrixIndexPointerARB(GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void MatrixIndexubvARB(GLint size, GLubyte indices);
void MatrixIndexuivARB(GLint size, GLuint indices);
void MatrixIndexusvARB(GLint size, GLushort indices);
void MatrixLoadIdentityEXT(GLenum mode);
void MatrixLoadTransposedEXT(GLenum mode, GLdouble m);
void MatrixLoadTransposefEXT(GLenum mode, GLfloat m);
void MatrixLoaddEXT(GLenum mode, GLdouble m);
void MatrixLoadfEXT(GLenum mode, GLfloat m);
void MatrixMode(GLenum mode);
void MatrixMultTransposedEXT(GLenum mode, GLdouble m);
void MatrixMultTransposefEXT(GLenum mode, GLfloat m);
void MatrixMultdEXT(GLenum mode, GLdouble m);
void MatrixMultfEXT(GLenum mode, GLfloat m);
void MatrixOrthoEXT(GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
void MatrixPopEXT(GLenum mode);
void MatrixPushEXT(GLenum mode);
void MatrixRotatedEXT(GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
void MatrixRotatefEXT(GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
void MatrixScaledEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
void MatrixScalefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
void MatrixTranslatedEXT(GLenum mode, GLdouble x, GLdouble y, GLdouble z);
void MatrixTranslatefEXT(GLenum mode, GLfloat x, GLfloat y, GLfloat z);
void MemoryBarrier(GLbitfield barriers);
void MemoryBarrierEXT(GLbitfield barriers);
void MinSampleShading(GLfloat value);
void MinSampleShadingARB(GLfloat value);
void Minmax(GLenum target, GLenum internalformat, GLboolean sink);
void MinmaxEXT(GLenum target, GLenum internalformat, GLboolean sink);
void MultMatrixd(GLdouble m);
void MultMatrixf(GLfloat m);
void MultMatrixxOES(GLfixed m);
void MultTransposeMatrixd(GLdouble m);
void MultTransposeMatrixdARB(GLdouble m);
void MultTransposeMatrixf(GLfloat m);
void MultTransposeMatrixfARB(GLfloat m);
void MultTransposeMatrixxOES(GLfixed m);
void MultiDrawArrays(GLenum mode, GLint first, GLsizei count, GLsizei drawcount);
void MultiDrawArraysEXT(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
void MultiDrawArraysIndirect(GLenum mode, void * indirect, GLsizei drawcount, GLsizei stride);
void MultiDrawArraysIndirectAMD(GLenum mode, GLvoid indirect, GLsizei primcount, GLsizei stride);
void MultiDrawElementArrayAPPLE(GLenum mode, GLint first, GLsizei count, GLsizei primcount);
void MultiDrawElements(GLenum mode, GLsizei count, GLenum type, GLvoid*const indices, GLsizei drawcount);
void MultiDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, GLvoid*const indices, GLsizei drawcount, GLint basevertex);
void MultiDrawElementsEXT(GLenum mode, GLsizei count, GLenum type, GLvoid * indices, GLsizei primcount);
void MultiDrawElementsIndirect(GLenum mode, GLenum type, void * indirect, GLsizei drawcount, GLsizei stride);
void MultiDrawElementsIndirectAMD(GLenum mode, GLenum type, GLvoid indirect, GLsizei primcount, GLsizei stride);
void MultiDrawRangeElementArrayAPPLE(GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count, GLsizei primcount);
void MultiModeDrawArraysIBM(GLenum mode, GLint first, GLsizei count, GLsizei primcount, GLint modestride);
void MultiModeDrawElementsIBM(GLenum mode, GLsizei count, GLenum type, GLvoid*const indices, GLsizei primcount, GLint modestride);
void MultiTexBufferEXT(GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
void MultiTexCoord1bOES(GLenum texture, GLbyte s);
void MultiTexCoord1bvOES(GLenum texture, GLbyte coords);
void MultiTexCoord1d(GLenum target, GLdouble s);
void MultiTexCoord1dARB(GLenum target, GLdouble s);
void MultiTexCoord1dv(GLenum target, GLdouble v);
void MultiTexCoord1dvARB(GLenum target, GLdouble v);
void MultiTexCoord1f(GLenum target, GLfloat s);
void MultiTexCoord1fARB(GLenum target, GLfloat s);
void MultiTexCoord1fv(GLenum target, GLfloat v);
void MultiTexCoord1fvARB(GLenum target, GLfloat v);
void MultiTexCoord1hNV(GLenum target, GLhalfNV s);
void MultiTexCoord1hvNV(GLenum target, GLhalfNV v);
void MultiTexCoord1i(GLenum target, GLint s);
void MultiTexCoord1iARB(GLenum target, GLint s);
void MultiTexCoord1iv(GLenum target, GLint v);
void MultiTexCoord1ivARB(GLenum target, GLint v);
void MultiTexCoord1s(GLenum target, GLshort s);
void MultiTexCoord1sARB(GLenum target, GLshort s);
void MultiTexCoord1sv(GLenum target, GLshort v);
void MultiTexCoord1svARB(GLenum target, GLshort v);
void MultiTexCoord1xOES(GLenum texture, GLfixed s);
void MultiTexCoord1xvOES(GLenum texture, GLfixed coords);
void MultiTexCoord2bOES(GLenum texture, GLbyte s, GLbyte t);
void MultiTexCoord2bvOES(GLenum texture, GLbyte coords);
void MultiTexCoord2d(GLenum target, GLdouble s, GLdouble t);
void MultiTexCoord2dARB(GLenum target, GLdouble s, GLdouble t);
void MultiTexCoord2dv(GLenum target, GLdouble v);
void MultiTexCoord2dvARB(GLenum target, GLdouble v);
void MultiTexCoord2f(GLenum target, GLfloat s, GLfloat t);
void MultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t);
void MultiTexCoord2fv(GLenum target, GLfloat v);
void MultiTexCoord2fvARB(GLenum target, GLfloat v);
void MultiTexCoord2hNV(GLenum target, GLhalfNV s, GLhalfNV t);
void MultiTexCoord2hvNV(GLenum target, GLhalfNV v);
void MultiTexCoord2i(GLenum target, GLint s, GLint t);
void MultiTexCoord2iARB(GLenum target, GLint s, GLint t);
void MultiTexCoord2iv(GLenum target, GLint v);
void MultiTexCoord2ivARB(GLenum target, GLint v);
void MultiTexCoord2s(GLenum target, GLshort s, GLshort t);
void MultiTexCoord2sARB(GLenum target, GLshort s, GLshort t);
void MultiTexCoord2sv(GLenum target, GLshort v);
void MultiTexCoord2svARB(GLenum target, GLshort v);
void MultiTexCoord2xOES(GLenum texture, GLfixed s, GLfixed t);
void MultiTexCoord2xvOES(GLenum texture, GLfixed coords);
void MultiTexCoord3bOES(GLenum texture, GLbyte s, GLbyte t, GLbyte r);
void MultiTexCoord3bvOES(GLenum texture, GLbyte coords);
void MultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r);
void MultiTexCoord3dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r);
void MultiTexCoord3dv(GLenum target, GLdouble v);
void MultiTexCoord3dvARB(GLenum target, GLdouble v);
void MultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r);
void MultiTexCoord3fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r);
void MultiTexCoord3fv(GLenum target, GLfloat v);
void MultiTexCoord3fvARB(GLenum target, GLfloat v);
void MultiTexCoord3hNV(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r);
void MultiTexCoord3hvNV(GLenum target, GLhalfNV v);
void MultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r);
void MultiTexCoord3iARB(GLenum target, GLint s, GLint t, GLint r);
void MultiTexCoord3iv(GLenum target, GLint v);
void MultiTexCoord3ivARB(GLenum target, GLint v);
void MultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r);
void MultiTexCoord3sARB(GLenum target, GLshort s, GLshort t, GLshort r);
void MultiTexCoord3sv(GLenum target, GLshort v);
void MultiTexCoord3svARB(GLenum target, GLshort v);
void MultiTexCoord3xOES(GLenum texture, GLfixed s, GLfixed t, GLfixed r);
void MultiTexCoord3xvOES(GLenum texture, GLfixed coords);
void MultiTexCoord4bOES(GLenum texture, GLbyte s, GLbyte t, GLbyte r, GLbyte q);
void MultiTexCoord4bvOES(GLenum texture, GLbyte coords);
void MultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
void MultiTexCoord4dARB(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
void MultiTexCoord4dv(GLenum target, GLdouble v);
void MultiTexCoord4dvARB(GLenum target, GLdouble v);
void MultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void MultiTexCoord4fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void MultiTexCoord4fv(GLenum target, GLfloat v);
void MultiTexCoord4fvARB(GLenum target, GLfloat v);
void MultiTexCoord4hNV(GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
void MultiTexCoord4hvNV(GLenum target, GLhalfNV v);
void MultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q);
void MultiTexCoord4iARB(GLenum target, GLint s, GLint t, GLint r, GLint q);
void MultiTexCoord4iv(GLenum target, GLint v);
void MultiTexCoord4ivARB(GLenum target, GLint v);
void MultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
void MultiTexCoord4sARB(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
void MultiTexCoord4sv(GLenum target, GLshort v);
void MultiTexCoord4svARB(GLenum target, GLshort v);
void MultiTexCoord4xOES(GLenum texture, GLfixed s, GLfixed t, GLfixed r, GLfixed q);
void MultiTexCoord4xvOES(GLenum texture, GLfixed coords);
void MultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords);
void MultiTexCoordP1uiv(GLenum texture, GLenum type, GLuint coords);
void MultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords);
void MultiTexCoordP2uiv(GLenum texture, GLenum type, GLuint coords);
void MultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords);
void MultiTexCoordP3uiv(GLenum texture, GLenum type, GLuint coords);
void MultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords);
void MultiTexCoordP4uiv(GLenum texture, GLenum type, GLuint coords);
void MultiTexCoordPointerEXT(GLenum texunit, GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void MultiTexEnvfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
void MultiTexEnvfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat params);
void MultiTexEnviEXT(GLenum texunit, GLenum target, GLenum pname, GLint param);
void MultiTexEnvivEXT(GLenum texunit, GLenum target, GLenum pname, GLint params);
void MultiTexGendEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
void MultiTexGendvEXT(GLenum texunit, GLenum coord, GLenum pname, GLdouble params);
void MultiTexGenfEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
void MultiTexGenfvEXT(GLenum texunit, GLenum coord, GLenum pname, GLfloat params);
void MultiTexGeniEXT(GLenum texunit, GLenum coord, GLenum pname, GLint param);
void MultiTexGenivEXT(GLenum texunit, GLenum coord, GLenum pname, GLint params);
void MultiTexImage1DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLenum format, GLenum type, GLvoid pixels);
void MultiTexImage2DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, GLvoid pixels);
void MultiTexImage3DEXT(GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid pixels);
void MultiTexParameterIivEXT(GLenum texunit, GLenum target, GLenum pname, GLint params);
void MultiTexParameterIuivEXT(GLenum texunit, GLenum target, GLenum pname, GLuint params);
void MultiTexParameterfEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat param);
void MultiTexParameterfvEXT(GLenum texunit, GLenum target, GLenum pname, GLfloat params);
void MultiTexParameteriEXT(GLenum texunit, GLenum target, GLenum pname, GLint param);
void MultiTexParameterivEXT(GLenum texunit, GLenum target, GLenum pname, GLint params);
void MultiTexRenderbufferEXT(GLenum texunit, GLenum target, GLuint renderbuffer);
void MultiTexSubImage1DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid pixels);
void MultiTexSubImage2DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels);
void MultiTexSubImage3DEXT(GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLvoid pixels);
void NamedBufferDataEXT(GLuint buffer, GLsizeiptr size, GLvoid data, GLenum usage);
void NamedBufferSubDataEXT(GLuint buffer, GLintptr offset, GLsizeiptr size, GLvoid data);
void NamedCopyBufferSubDataEXT(GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
void NamedFramebufferParameteriEXT(GLuint framebuffer, GLenum pname, GLint param);
void NamedFramebufferRenderbufferEXT(GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
void NamedFramebufferTexture1DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void NamedFramebufferTexture2DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
void NamedFramebufferTexture3DEXT(GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
void NamedFramebufferTextureEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
void NamedFramebufferTextureFaceEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
void NamedFramebufferTextureLayerEXT(GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
void NamedProgramLocalParameter4dEXT(GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void NamedProgramLocalParameter4dvEXT(GLuint program, GLenum target, GLuint index, GLdouble params);
void NamedProgramLocalParameter4fEXT(GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void NamedProgramLocalParameter4fvEXT(GLuint program, GLenum target, GLuint index, GLfloat params);
void NamedProgramLocalParameterI4iEXT(GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
void NamedProgramLocalParameterI4ivEXT(GLuint program, GLenum target, GLuint index, GLint params);
void NamedProgramLocalParameterI4uiEXT(GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
void NamedProgramLocalParameterI4uivEXT(GLuint program, GLenum target, GLuint index, GLuint params);
void NamedProgramLocalParameters4fvEXT(GLuint program, GLenum target, GLuint index, GLsizei count, GLfloat params);
void NamedProgramLocalParametersI4ivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, GLint params);
void NamedProgramLocalParametersI4uivEXT(GLuint program, GLenum target, GLuint index, GLsizei count, GLuint params);
void NamedProgramStringEXT(GLuint program, GLenum target, GLenum format, GLsizei len, GLvoid string);
void NamedRenderbufferStorageEXT(GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
void NamedRenderbufferStorageMultisampleCoverageEXT(GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
void NamedRenderbufferStorageMultisampleEXT(GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
void NamedStringARB(GLenum type, GLint namelen, GLchar name, GLint stringlen, GLchar string);
void NewList(GLuint list, GLenum mode);
UInt32 NewObjectBufferATI(GLsizei size, GLvoid pointer, GLenum usage);
void Normal3b(GLbyte nx, GLbyte ny, GLbyte nz);
void Normal3bv(GLbyte v);
void Normal3d(GLdouble nx, GLdouble ny, GLdouble nz);
void Normal3dv(GLdouble v);
void Normal3f(GLfloat nx, GLfloat ny, GLfloat nz);
void Normal3fVertex3fSUN(GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
void Normal3fVertex3fvSUN(GLfloat n, GLfloat v);
void Normal3fv(GLfloat v);
void Normal3hNV(GLhalfNV nx, GLhalfNV ny, GLhalfNV nz);
void Normal3hvNV(GLhalfNV v);
void Normal3i(GLint nx, GLint ny, GLint nz);
void Normal3iv(GLint v);
void Normal3s(GLshort nx, GLshort ny, GLshort nz);
void Normal3sv(GLshort v);
void Normal3xOES(GLfixed nx, GLfixed ny, GLfixed nz);
void Normal3xvOES(GLfixed coords);
void NormalFormatNV(GLenum type, GLsizei stride);
void NormalP3ui(GLenum type, GLuint coords);
void NormalP3uiv(GLenum type, GLuint coords);
void NormalPointer(GLenum type, GLsizei stride, GLvoid pointer);
void NormalPointerEXT(GLenum type, GLsizei stride, GLsizei count, GLvoid pointer);
void NormalPointerListIBM(GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride);
void NormalPointervINTEL(GLenum type, GLvoid * pointer);
void NormalStream3bATI(GLenum stream, GLbyte nx, GLbyte ny, GLbyte nz);
void NormalStream3bvATI(GLenum stream, GLbyte coords);
void NormalStream3dATI(GLenum stream, GLdouble nx, GLdouble ny, GLdouble nz);
void NormalStream3dvATI(GLenum stream, GLdouble coords);
void NormalStream3fATI(GLenum stream, GLfloat nx, GLfloat ny, GLfloat nz);
void NormalStream3fvATI(GLenum stream, GLfloat coords);
void NormalStream3iATI(GLenum stream, GLint nx, GLint ny, GLint nz);
void NormalStream3ivATI(GLenum stream, GLint coords);
void NormalStream3sATI(GLenum stream, GLshort nx, GLshort ny, GLshort nz);
void NormalStream3svATI(GLenum stream, GLshort coords);
void ObjectLabel(GLenum identifier, GLuint name, GLsizei length, GLchar label);
void ObjectPtrLabel(void * ptr, GLsizei length, GLchar label);
GLenum ObjectPurgeableAPPLE(GLenum objectType, GLuint name, GLenum option);
GLenum ObjectUnpurgeableAPPLE(GLenum objectType, GLuint name, GLenum option);
void Ortho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
void OrthofOES(GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
void OrthoxOES(GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f);
void PNTrianglesfATI(GLenum pname, GLfloat param);
void PNTrianglesiATI(GLenum pname, GLint param);
void PassTexCoordATI(GLuint dst, GLuint coord, GLenum swizzle);
void PassThrough(GLfloat token);
void PassThroughxOES(GLfixed token);
void PatchParameterfv(GLenum pname, GLfloat values);
void PatchParameteri(GLenum pname, GLint value);
void PathColorGenNV(GLenum color, GLenum genMode, GLenum colorFormat, GLfloat coeffs);
void PathCommandsNV(GLuint path, GLsizei numCommands, GLubyte commands, GLsizei numCoords, GLenum coordType, GLvoid coords);
void PathCoordsNV(GLuint path, GLsizei numCoords, GLenum coordType, GLvoid coords);
void PathCoverDepthFuncNV(GLenum func);
void PathDashArrayNV(GLuint path, GLsizei dashCount, GLfloat dashArray);
void PathFogGenNV(GLenum genMode);
void PathGlyphRangeNV(GLuint firstPathName, GLenum fontTarget, GLvoid fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
void PathGlyphsNV(GLuint firstPathName, GLenum fontTarget, GLvoid fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, GLvoid charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
void PathParameterfNV(GLuint path, GLenum pname, GLfloat value);
void PathParameterfvNV(GLuint path, GLenum pname, GLfloat value);
void PathParameteriNV(GLuint path, GLenum pname, GLint value);
void PathParameterivNV(GLuint path, GLenum pname, GLint value);
void PathStencilDepthOffsetNV(GLfloat factor, GLfloat units);
void PathStencilFuncNV(GLenum func, GLint ref, GLuint mask);
void PathStringNV(GLuint path, GLenum format, GLsizei length, GLvoid pathString);
void PathSubCommandsNV(GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, GLubyte commands, GLsizei numCoords, GLenum coordType, GLvoid coords);
void PathSubCoordsNV(GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, GLvoid coords);
void PathTexGenNV(GLenum texCoordSet, GLenum genMode, GLint components, GLfloat coeffs);
void PauseTransformFeedback();
void PauseTransformFeedbackNV();
void PixelDataRangeNV(GLenum target, GLsizei length, GLvoid pointer);
void PixelMapfv(GLenum map, GLsizei mapsize, GLfloat values);
void PixelMapuiv(GLenum map, GLsizei mapsize, GLuint values);
void PixelMapusv(GLenum map, GLsizei mapsize, GLushort values);
void PixelMapx(GLenum map, GLint size, GLfixed values);
void PixelStoref(GLenum pname, GLfloat param);
void PixelStorei(GLenum pname, GLint param);
void PixelStorex(GLenum pname, GLfixed param);
void PixelTexGenParameterfSGIS(GLenum pname, GLfloat param);
void PixelTexGenParameterfvSGIS(GLenum pname, GLfloat params);
void PixelTexGenParameteriSGIS(GLenum pname, GLint param);
void PixelTexGenParameterivSGIS(GLenum pname, GLint params);
void PixelTexGenSGIX(GLenum mode);
void PixelTransferf(GLenum pname, GLfloat param);
void PixelTransferi(GLenum pname, GLint param);
void PixelTransferxOES(GLenum pname, GLfixed param);
void PixelTransformParameterfEXT(GLenum target, GLenum pname, GLfloat param);
void PixelTransformParameterfvEXT(GLenum target, GLenum pname, GLfloat params);
void PixelTransformParameteriEXT(GLenum target, GLenum pname, GLint param);
void PixelTransformParameterivEXT(GLenum target, GLenum pname, GLint params);
void PixelZoom(GLfloat xfactor, GLfloat yfactor);
void PixelZoomxOES(GLfixed xfactor, GLfixed yfactor);
Boolean PointAlongPathNV(GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat x, GLfloat y, GLfloat tangentX, GLfloat tangentY);
void PointParameterf(GLenum pname, GLfloat param);
void PointParameterfARB(GLenum pname, GLfloat param);
void PointParameterfEXT(GLenum pname, GLfloat param);
void PointParameterfSGIS(GLenum pname, GLfloat param);
void PointParameterfv(GLenum pname, GLfloat params);
void PointParameterfvARB(GLenum pname, GLfloat params);
void PointParameterfvEXT(GLenum pname, GLfloat params);
void PointParameterfvSGIS(GLenum pname, GLfloat params);
void PointParameteri(GLenum pname, GLint param);
void PointParameteriNV(GLenum pname, GLint param);
void PointParameteriv(GLenum pname, GLint params);
void PointParameterivNV(GLenum pname, GLint params);
void PointParameterxvOES(GLenum pname, GLfixed params);
void PointSize(GLfloat size);
void PointSizexOES(GLfixed size);
Int32 PollAsyncSGIX(GLuint markerp);
Int32 PollInstrumentsSGIX(GLint marker_p);
void PolygonMode(GLenum face, GLenum mode);
void PolygonOffset(GLfloat factor, GLfloat units);
void PolygonOffsetEXT(GLfloat factor, GLfloat bias);
void PolygonOffsetxOES(GLfixed factor, GLfixed units);
void PolygonStipple(GLubyte mask);
void PopAttrib();
void PopClientAttrib();
void PopDebugGroup();
void PopMatrix();
void PopName();
void PresentFrameDualFillNV(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLenum target1, GLuint fill1, GLenum target2, GLuint fill2, GLenum target3, GLuint fill3);
void PresentFrameKeyedNV(GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLuint key0, GLenum target1, GLuint fill1, GLuint key1);
void PrimitiveRestartIndex(GLuint index);
void PrimitiveRestartIndexNV(GLuint index);
void PrimitiveRestartNV();
void PrioritizeTextures(GLsizei n, GLuint textures, GLfloat priorities);
void PrioritizeTexturesEXT(GLsizei n, GLuint textures, GLclampf priorities);
void PrioritizeTexturesxOES(GLsizei n, GLuint textures, GLfixed priorities);
void ProgramBinary(GLuint program, GLenum binaryFormat, GLvoid binary, GLsizei length);
void ProgramBufferParametersIivNV(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, GLint params);
void ProgramBufferParametersIuivNV(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, GLuint params);
void ProgramBufferParametersfvNV(GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, GLfloat params);
void ProgramEnvParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void ProgramEnvParameter4dvARB(GLenum target, GLuint index, GLdouble params);
void ProgramEnvParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void ProgramEnvParameter4fvARB(GLenum target, GLuint index, GLfloat params);
void ProgramEnvParameterI4iNV(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
void ProgramEnvParameterI4ivNV(GLenum target, GLuint index, GLint params);
void ProgramEnvParameterI4uiNV(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
void ProgramEnvParameterI4uivNV(GLenum target, GLuint index, GLuint params);
void ProgramEnvParameters4fvEXT(GLenum target, GLuint index, GLsizei count, GLfloat params);
void ProgramEnvParametersI4ivNV(GLenum target, GLuint index, GLsizei count, GLint params);
void ProgramEnvParametersI4uivNV(GLenum target, GLuint index, GLsizei count, GLuint params);
void ProgramLocalParameter4dARB(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void ProgramLocalParameter4dvARB(GLenum target, GLuint index, GLdouble params);
void ProgramLocalParameter4fARB(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void ProgramLocalParameter4fvARB(GLenum target, GLuint index, GLfloat params);
void ProgramLocalParameterI4iNV(GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
void ProgramLocalParameterI4ivNV(GLenum target, GLuint index, GLint params);
void ProgramLocalParameterI4uiNV(GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
void ProgramLocalParameterI4uivNV(GLenum target, GLuint index, GLuint params);
void ProgramLocalParameters4fvEXT(GLenum target, GLuint index, GLsizei count, GLfloat params);
void ProgramLocalParametersI4ivNV(GLenum target, GLuint index, GLsizei count, GLint params);
void ProgramLocalParametersI4uivNV(GLenum target, GLuint index, GLsizei count, GLuint params);
void ProgramNamedParameter4dNV(GLuint id, GLsizei len, GLubyte name, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void ProgramNamedParameter4dvNV(GLuint id, GLsizei len, GLubyte name, GLdouble v);
void ProgramNamedParameter4fNV(GLuint id, GLsizei len, GLubyte name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void ProgramNamedParameter4fvNV(GLuint id, GLsizei len, GLubyte name, GLfloat v);
void ProgramParameter4dNV(GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void ProgramParameter4dvNV(GLenum target, GLuint index, GLdouble v);
void ProgramParameter4fNV(GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void ProgramParameter4fvNV(GLenum target, GLuint index, GLfloat v);
void ProgramParameteri(GLuint program, GLenum pname, GLint value);
void ProgramParameteriARB(GLuint program, GLenum pname, GLint value);
void ProgramParameteriEXT(GLuint program, GLenum pname, GLint value);
void ProgramParameters4dvNV(GLenum target, GLuint index, GLsizei count, GLdouble v);
void ProgramParameters4fvNV(GLenum target, GLuint index, GLsizei count, GLfloat v);
void ProgramStringARB(GLenum target, GLenum format, GLsizei len, GLvoid string);
void ProgramSubroutineParametersuivNV(GLenum target, GLsizei count, GLuint params);
void ProgramUniform1d(GLuint program, GLint location, GLdouble v0);
void ProgramUniform1dEXT(GLuint program, GLint location, GLdouble x);
void ProgramUniform1dv(GLuint program, GLint location, GLsizei count, GLdouble value);
void ProgramUniform1dvEXT(GLuint program, GLint location, GLsizei count, GLdouble value);
void ProgramUniform1f(GLuint program, GLint location, GLfloat v0);
void ProgramUniform1fEXT(GLuint program, GLint location, GLfloat v0);
void ProgramUniform1fv(GLuint program, GLint location, GLsizei count, GLfloat value);
void ProgramUniform1fvEXT(GLuint program, GLint location, GLsizei count, GLfloat value);
void ProgramUniform1i(GLuint program, GLint location, GLint v0);
void ProgramUniform1i64NV(GLuint program, GLint location, GLint64EXT x);
void ProgramUniform1i64vNV(GLuint program, GLint location, GLsizei count, GLint64EXT value);
void ProgramUniform1iEXT(GLuint program, GLint location, GLint v0);
void ProgramUniform1iv(GLuint program, GLint location, GLsizei count, GLint value);
void ProgramUniform1ivEXT(GLuint program, GLint location, GLsizei count, GLint value);
void ProgramUniform1ui(GLuint program, GLint location, GLuint v0);
void ProgramUniform1ui64NV(GLuint program, GLint location, GLuint64EXT x);
void ProgramUniform1ui64vNV(GLuint program, GLint location, GLsizei count, GLuint64EXT value);
void ProgramUniform1uiEXT(GLuint program, GLint location, GLuint v0);
void ProgramUniform1uiv(GLuint program, GLint location, GLsizei count, GLuint value);
void ProgramUniform1uivEXT(GLuint program, GLint location, GLsizei count, GLuint value);
void ProgramUniform2d(GLuint program, GLint location, GLdouble v0, GLdouble v1);
void ProgramUniform2dEXT(GLuint program, GLint location, GLdouble x, GLdouble y);
void ProgramUniform2dv(GLuint program, GLint location, GLsizei count, GLdouble value);
void ProgramUniform2dvEXT(GLuint program, GLint location, GLsizei count, GLdouble value);
void ProgramUniform2f(GLuint program, GLint location, GLfloat v0, GLfloat v1);
void ProgramUniform2fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1);
void ProgramUniform2fv(GLuint program, GLint location, GLsizei count, GLfloat value);
void ProgramUniform2fvEXT(GLuint program, GLint location, GLsizei count, GLfloat value);
void ProgramUniform2i(GLuint program, GLint location, GLint v0, GLint v1);
void ProgramUniform2i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y);
void ProgramUniform2i64vNV(GLuint program, GLint location, GLsizei count, GLint64EXT value);
void ProgramUniform2iEXT(GLuint program, GLint location, GLint v0, GLint v1);
void ProgramUniform2iv(GLuint program, GLint location, GLsizei count, GLint value);
void ProgramUniform2ivEXT(GLuint program, GLint location, GLsizei count, GLint value);
void ProgramUniform2ui(GLuint program, GLint location, GLuint v0, GLuint v1);
void ProgramUniform2ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y);
void ProgramUniform2ui64vNV(GLuint program, GLint location, GLsizei count, GLuint64EXT value);
void ProgramUniform2uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1);
void ProgramUniform2uiv(GLuint program, GLint location, GLsizei count, GLuint value);
void ProgramUniform2uivEXT(GLuint program, GLint location, GLsizei count, GLuint value);
void ProgramUniform3d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
void ProgramUniform3dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
void ProgramUniform3dv(GLuint program, GLint location, GLsizei count, GLdouble value);
void ProgramUniform3dvEXT(GLuint program, GLint location, GLsizei count, GLdouble value);
void ProgramUniform3f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void ProgramUniform3fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void ProgramUniform3fv(GLuint program, GLint location, GLsizei count, GLfloat value);
void ProgramUniform3fvEXT(GLuint program, GLint location, GLsizei count, GLfloat value);
void ProgramUniform3i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
void ProgramUniform3i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
void ProgramUniform3i64vNV(GLuint program, GLint location, GLsizei count, GLint64EXT value);
void ProgramUniform3iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
void ProgramUniform3iv(GLuint program, GLint location, GLsizei count, GLint value);
void ProgramUniform3ivEXT(GLuint program, GLint location, GLsizei count, GLint value);
void ProgramUniform3ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
void ProgramUniform3ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
void ProgramUniform3ui64vNV(GLuint program, GLint location, GLsizei count, GLuint64EXT value);
void ProgramUniform3uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
void ProgramUniform3uiv(GLuint program, GLint location, GLsizei count, GLuint value);
void ProgramUniform3uivEXT(GLuint program, GLint location, GLsizei count, GLuint value);
void ProgramUniform4d(GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
void ProgramUniform4dEXT(GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void ProgramUniform4dv(GLuint program, GLint location, GLsizei count, GLdouble value);
void ProgramUniform4dvEXT(GLuint program, GLint location, GLsizei count, GLdouble value);
void ProgramUniform4f(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void ProgramUniform4fEXT(GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void ProgramUniform4fv(GLuint program, GLint location, GLsizei count, GLfloat value);
void ProgramUniform4fvEXT(GLuint program, GLint location, GLsizei count, GLfloat value);
void ProgramUniform4i(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void ProgramUniform4i64NV(GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
void ProgramUniform4i64vNV(GLuint program, GLint location, GLsizei count, GLint64EXT value);
void ProgramUniform4iEXT(GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void ProgramUniform4iv(GLuint program, GLint location, GLsizei count, GLint value);
void ProgramUniform4ivEXT(GLuint program, GLint location, GLsizei count, GLint value);
void ProgramUniform4ui(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
void ProgramUniform4ui64NV(GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
void ProgramUniform4ui64vNV(GLuint program, GLint location, GLsizei count, GLuint64EXT value);
void ProgramUniform4uiEXT(GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
void ProgramUniform4uiv(GLuint program, GLint location, GLsizei count, GLuint value);
void ProgramUniform4uivEXT(GLuint program, GLint location, GLsizei count, GLuint value);
void ProgramUniformHandleui64NV(GLuint program, GLint location, GLuint64 value);
void ProgramUniformHandleui64vNV(GLuint program, GLint location, GLsizei count, GLuint64 values);
void ProgramUniformMatrix2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void ProgramUniformMatrix2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void ProgramUniformMatrix2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void ProgramUniformMatrix2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void ProgramUniformMatrix2x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void ProgramUniformMatrix2x3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void ProgramUniformMatrix2x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void ProgramUniformMatrix2x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void ProgramUniformMatrix2x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void ProgramUniformMatrix2x4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void ProgramUniformMatrix2x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void ProgramUniformMatrix2x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void ProgramUniformMatrix3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void ProgramUniformMatrix3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void ProgramUniformMatrix3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void ProgramUniformMatrix3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void ProgramUniformMatrix3x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void ProgramUniformMatrix3x2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void ProgramUniformMatrix3x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void ProgramUniformMatrix3x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void ProgramUniformMatrix3x4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void ProgramUniformMatrix3x4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void ProgramUniformMatrix3x4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void ProgramUniformMatrix3x4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void ProgramUniformMatrix4dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void ProgramUniformMatrix4dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void ProgramUniformMatrix4fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void ProgramUniformMatrix4fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void ProgramUniformMatrix4x2dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void ProgramUniformMatrix4x2dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void ProgramUniformMatrix4x2fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void ProgramUniformMatrix4x2fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void ProgramUniformMatrix4x3dv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void ProgramUniformMatrix4x3dvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void ProgramUniformMatrix4x3fv(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void ProgramUniformMatrix4x3fvEXT(GLuint program, GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void ProgramUniformui64NV(GLuint program, GLint location, GLuint64EXT value);
void ProgramUniformui64vNV(GLuint program, GLint location, GLsizei count, GLuint64EXT value);
void ProgramVertexLimitNV(GLenum target, GLint limit);
void ProvokingVertex(GLenum mode);
void ProvokingVertexEXT(GLenum mode);
void PushAttrib(GLbitfield mask);
void PushClientAttrib(GLbitfield mask);
void PushClientAttribDefaultEXT(GLbitfield mask);
void PushDebugGroup(GLenum source, GLuint id, GLsizei length, GLchar message);
void PushMatrix();
void PushName(GLuint name);
void QueryCounter(GLuint id, GLenum target);
GLbitfield QueryMatrixxOES(GLfixed mantissa, GLint exponent);
void RasterPos2d(GLdouble x, GLdouble y);
void RasterPos2dv(GLdouble v);
void RasterPos2f(GLfloat x, GLfloat y);
void RasterPos2fv(GLfloat v);
void RasterPos2i(GLint x, GLint y);
void RasterPos2iv(GLint v);
void RasterPos2s(GLshort x, GLshort y);
void RasterPos2sv(GLshort v);
void RasterPos2xOES(GLfixed x, GLfixed y);
void RasterPos2xvOES(GLfixed coords);
void RasterPos3d(GLdouble x, GLdouble y, GLdouble z);
void RasterPos3dv(GLdouble v);
void RasterPos3f(GLfloat x, GLfloat y, GLfloat z);
void RasterPos3fv(GLfloat v);
void RasterPos3i(GLint x, GLint y, GLint z);
void RasterPos3iv(GLint v);
void RasterPos3s(GLshort x, GLshort y, GLshort z);
void RasterPos3sv(GLshort v);
void RasterPos3xOES(GLfixed x, GLfixed y, GLfixed z);
void RasterPos3xvOES(GLfixed coords);
void RasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void RasterPos4dv(GLdouble v);
void RasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void RasterPos4fv(GLfloat v);
void RasterPos4i(GLint x, GLint y, GLint z, GLint w);
void RasterPos4iv(GLint v);
void RasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w);
void RasterPos4sv(GLshort v);
void RasterPos4xOES(GLfixed x, GLfixed y, GLfixed z, GLfixed w);
void RasterPos4xvOES(GLfixed coords);
void ReadBuffer(GLenum mode);
void ReadInstrumentsSGIX(GLint marker);
void ReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels);
void ReadnPixelsARB(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, GLvoid data);
void Rectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
void Rectdv(GLdouble v1, GLdouble v2);
void Rectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
void Rectfv(GLfloat v1, GLfloat v2);
void Recti(GLint x1, GLint y1, GLint x2, GLint y2);
void Rectiv(GLint v1, GLint v2);
void Rects(GLshort x1, GLshort y1, GLshort x2, GLshort y2);
void Rectsv(GLshort v1, GLshort v2);
void RectxOES(GLfixed x1, GLfixed y1, GLfixed x2, GLfixed y2);
void RectxvOES(GLfixed v1, GLfixed v2);
void ReferencePlaneSGIX(GLdouble equation);
void ReleaseShaderCompiler();
Int32 RenderMode(GLenum mode);
void RenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
void RenderbufferStorageEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
void RenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
void RenderbufferStorageMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
void RenderbufferStorageMultisampleEXT(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
void ReplacementCodePointerSUN(GLenum type, GLsizei stride, GLvoid * pointer);
void ReplacementCodeubSUN(GLubyte code);
void ReplacementCodeubvSUN(GLubyte code);
void ReplacementCodeuiColor3fVertex3fSUN(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
void ReplacementCodeuiColor3fVertex3fvSUN(GLuint rc, GLfloat c, GLfloat v);
void ReplacementCodeuiColor4fNormal3fVertex3fSUN(GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
void ReplacementCodeuiColor4fNormal3fVertex3fvSUN(GLuint rc, GLfloat c, GLfloat n, GLfloat v);
void ReplacementCodeuiColor4ubVertex3fSUN(GLuint rc, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
void ReplacementCodeuiColor4ubVertex3fvSUN(GLuint rc, GLubyte c, GLfloat v);
void ReplacementCodeuiNormal3fVertex3fSUN(GLuint rc, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
void ReplacementCodeuiNormal3fVertex3fvSUN(GLuint rc, GLfloat n, GLfloat v);
void ReplacementCodeuiSUN(GLuint code);
void ReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
void ReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN(GLuint rc, GLfloat tc, GLfloat c, GLfloat n, GLfloat v);
void ReplacementCodeuiTexCoord2fNormal3fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
void ReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN(GLuint rc, GLfloat tc, GLfloat n, GLfloat v);
void ReplacementCodeuiTexCoord2fVertex3fSUN(GLuint rc, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
void ReplacementCodeuiTexCoord2fVertex3fvSUN(GLuint rc, GLfloat tc, GLfloat v);
void ReplacementCodeuiVertex3fSUN(GLuint rc, GLfloat x, GLfloat y, GLfloat z);
void ReplacementCodeuiVertex3fvSUN(GLuint rc, GLfloat v);
void ReplacementCodeuivSUN(GLuint code);
void ReplacementCodeusSUN(GLushort code);
void ReplacementCodeusvSUN(GLushort code);
void RequestResidentProgramsNV(GLsizei n, GLuint programs);
void ResetHistogram(GLenum target);
void ResetHistogramEXT(GLenum target);
void ResetMinmax(GLenum target);
void ResetMinmaxEXT(GLenum target);
void ResizeBuffersMESA();
void ResumeTransformFeedback();
void ResumeTransformFeedbackNV();
void Rotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
void Rotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
void RotatexOES(GLfixed angle, GLfixed x, GLfixed y, GLfixed z);
void SampleCoverage(GLfloat value, GLboolean invert);
void SampleCoverageARB(GLfloat value, GLboolean invert);
void SampleCoverageOES(GLfixed value, GLboolean invert);
void SampleMapATI(GLuint dst, GLuint interp, GLenum swizzle);
void SampleMaskEXT(GLclampf value, GLboolean invert);
void SampleMaskIndexedNV(GLuint index, GLbitfield mask);
void SampleMaskSGIS(GLclampf value, GLboolean invert);
void SampleMaski(GLuint index, GLbitfield mask);
void SamplePatternEXT(GLenum pattern);
void SamplePatternSGIS(GLenum pattern);
void SamplerParameterIiv(GLuint sampler, GLenum pname, GLint param);
void SamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint param);
void SamplerParameterf(GLuint sampler, GLenum pname, GLfloat param);
void SamplerParameterfv(GLuint sampler, GLenum pname, GLfloat param);
void SamplerParameteri(GLuint sampler, GLenum pname, GLint param);
void SamplerParameteriv(GLuint sampler, GLenum pname, GLint param);
void Scaled(GLdouble x, GLdouble y, GLdouble z);
void Scalef(GLfloat x, GLfloat y, GLfloat z);
void ScalexOES(GLfixed x, GLfixed y, GLfixed z);
void Scissor(GLint x, GLint y, GLsizei width, GLsizei height);
void ScissorArrayv(GLuint first, GLsizei count, GLint v);
void ScissorIndexed(GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
void ScissorIndexedv(GLuint index, GLint v);
void SecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue);
void SecondaryColor3bEXT(GLbyte red, GLbyte green, GLbyte blue);
void SecondaryColor3bv(GLbyte v);
void SecondaryColor3bvEXT(GLbyte v);
void SecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue);
void SecondaryColor3dEXT(GLdouble red, GLdouble green, GLdouble blue);
void SecondaryColor3dv(GLdouble v);
void SecondaryColor3dvEXT(GLdouble v);
void SecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue);
void SecondaryColor3fEXT(GLfloat red, GLfloat green, GLfloat blue);
void SecondaryColor3fv(GLfloat v);
void SecondaryColor3fvEXT(GLfloat v);
void SecondaryColor3hNV(GLhalfNV red, GLhalfNV green, GLhalfNV blue);
void SecondaryColor3hvNV(GLhalfNV v);
void SecondaryColor3i(GLint red, GLint green, GLint blue);
void SecondaryColor3iEXT(GLint red, GLint green, GLint blue);
void SecondaryColor3iv(GLint v);
void SecondaryColor3ivEXT(GLint v);
void SecondaryColor3s(GLshort red, GLshort green, GLshort blue);
void SecondaryColor3sEXT(GLshort red, GLshort green, GLshort blue);
void SecondaryColor3sv(GLshort v);
void SecondaryColor3svEXT(GLshort v);
void SecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue);
void SecondaryColor3ubEXT(GLubyte red, GLubyte green, GLubyte blue);
void SecondaryColor3ubv(GLubyte v);
void SecondaryColor3ubvEXT(GLubyte v);
void SecondaryColor3ui(GLuint red, GLuint green, GLuint blue);
void SecondaryColor3uiEXT(GLuint red, GLuint green, GLuint blue);
void SecondaryColor3uiv(GLuint v);
void SecondaryColor3uivEXT(GLuint v);
void SecondaryColor3us(GLushort red, GLushort green, GLushort blue);
void SecondaryColor3usEXT(GLushort red, GLushort green, GLushort blue);
void SecondaryColor3usv(GLushort v);
void SecondaryColor3usvEXT(GLushort v);
void SecondaryColorFormatNV(GLint size, GLenum type, GLsizei stride);
void SecondaryColorP3ui(GLenum type, GLuint color);
void SecondaryColorP3uiv(GLenum type, GLuint color);
void SecondaryColorPointer(GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void SecondaryColorPointerEXT(GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void SecondaryColorPointerListIBM(GLint size, GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride);
void SelectBuffer(GLsizei size, GLuint buffer);
void SelectPerfMonitorCountersAMD(GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint counterList);
void SeparableFilter2D(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid row, GLvoid column);
void SeparableFilter2DEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid row, GLvoid column);
void SetFenceAPPLE(GLuint fence);
void SetFenceNV(GLuint fence, GLenum condition);
void SetFragmentShaderConstantATI(GLuint dst, GLfloat value);
void SetInvariantEXT(GLuint id, GLenum type, GLvoid addr);
void SetLocalConstantEXT(GLuint id, GLenum type, GLvoid addr);
void SetMultisamplefvAMD(GLenum pname, GLuint index, GLfloat val);
void ShadeModel(GLenum mode);
void ShaderBinary(GLsizei count, GLuint shaders, GLenum binaryformat, GLvoid binary, GLsizei length);
void ShaderOp1EXT(GLenum op, GLuint res, GLuint arg1);
void ShaderOp2EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2);
void ShaderOp3EXT(GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3);
void ShaderSource(GLuint shader, GLsizei count, GLchar*const string, GLint length);
void ShaderSourceARB(GLhandleARB shaderObj, GLsizei count, GLcharARB * string, GLint length);
void ShaderStorageBlockBinding(GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
void SharpenTexFuncSGIS(GLenum target, GLsizei n, GLfloat points);
void SpriteParameterfSGIX(GLenum pname, GLfloat param);
void SpriteParameterfvSGIX(GLenum pname, GLfloat params);
void SpriteParameteriSGIX(GLenum pname, GLint param);
void SpriteParameterivSGIX(GLenum pname, GLint params);
void StartInstrumentsSGIX();
void StencilClearTagEXT(GLsizei stencilTagBits, GLuint stencilClearTag);
void StencilFillPathInstancedNV(GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, GLfloat transformValues);
void StencilFillPathNV(GLuint path, GLenum fillMode, GLuint mask);
void StencilFunc(GLenum func, GLint ref, GLuint mask);
void StencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask);
void StencilFuncSeparateATI(GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);
void StencilMask(GLuint mask);
void StencilMaskSeparate(GLenum face, GLuint mask);
void StencilOp(GLenum fail, GLenum zfail, GLenum zpass);
void StencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
void StencilOpSeparateATI(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
void StencilOpValueAMD(GLenum face, GLuint value);
void StencilStrokePathInstancedNV(GLsizei numPaths, GLenum pathNameType, GLvoid paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, GLfloat transformValues);
void StencilStrokePathNV(GLuint path, GLint reference, GLuint mask);
void StopInstrumentsSGIX(GLint marker);
void StringMarkerGREMEDY(GLsizei len, GLvoid string);
void SwizzleEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
void SyncTextureINTEL(GLuint texture);
void TagSampleBufferSGIX();
void Tangent3bEXT(GLbyte tx, GLbyte ty, GLbyte tz);
void Tangent3bvEXT(GLbyte v);
void Tangent3dEXT(GLdouble tx, GLdouble ty, GLdouble tz);
void Tangent3dvEXT(GLdouble v);
void Tangent3fEXT(GLfloat tx, GLfloat ty, GLfloat tz);
void Tangent3fvEXT(GLfloat v);
void Tangent3iEXT(GLint tx, GLint ty, GLint tz);
void Tangent3ivEXT(GLint v);
void Tangent3sEXT(GLshort tx, GLshort ty, GLshort tz);
void Tangent3svEXT(GLshort v);
void TangentPointerEXT(GLenum type, GLsizei stride, GLvoid pointer);
void TbufferMask3DFX(GLuint mask);
void TessellationFactorAMD(GLfloat factor);
void TessellationModeAMD(GLenum mode);
Boolean TestFenceAPPLE(GLuint fence);
Boolean TestFenceNV(GLuint fence);
Boolean TestObjectAPPLE(GLenum object, GLuint name);
void TexBuffer(GLenum target, GLenum internalformat, GLuint buffer);
void TexBufferARB(GLenum target, GLenum internalformat, GLuint buffer);
void TexBufferEXT(GLenum target, GLenum internalformat, GLuint buffer);
void TexBufferRange(GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
void TexBumpParameterfvATI(GLenum pname, GLfloat param);
void TexBumpParameterivATI(GLenum pname, GLint param);
void TexCoord1bOES(GLbyte s);
void TexCoord1bvOES(GLbyte coords);
void TexCoord1d(GLdouble s);
void TexCoord1dv(GLdouble v);
void TexCoord1f(GLfloat s);
void TexCoord1fv(GLfloat v);
void TexCoord1hNV(GLhalfNV s);
void TexCoord1hvNV(GLhalfNV v);
void TexCoord1i(GLint s);
void TexCoord1iv(GLint v);
void TexCoord1s(GLshort s);
void TexCoord1sv(GLshort v);
void TexCoord1xOES(GLfixed s);
void TexCoord1xvOES(GLfixed coords);
void TexCoord2bOES(GLbyte s, GLbyte t);
void TexCoord2bvOES(GLbyte coords);
void TexCoord2d(GLdouble s, GLdouble t);
void TexCoord2dv(GLdouble v);
void TexCoord2f(GLfloat s, GLfloat t);
void TexCoord2fColor3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
void TexCoord2fColor3fVertex3fvSUN(GLfloat tc, GLfloat c, GLfloat v);
void TexCoord2fColor4fNormal3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
void TexCoord2fColor4fNormal3fVertex3fvSUN(GLfloat tc, GLfloat c, GLfloat n, GLfloat v);
void TexCoord2fColor4ubVertex3fSUN(GLfloat s, GLfloat t, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
void TexCoord2fColor4ubVertex3fvSUN(GLfloat tc, GLubyte c, GLfloat v);
void TexCoord2fNormal3fVertex3fSUN(GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
void TexCoord2fNormal3fVertex3fvSUN(GLfloat tc, GLfloat n, GLfloat v);
void TexCoord2fVertex3fSUN(GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
void TexCoord2fVertex3fvSUN(GLfloat tc, GLfloat v);
void TexCoord2fv(GLfloat v);
void TexCoord2hNV(GLhalfNV s, GLhalfNV t);
void TexCoord2hvNV(GLhalfNV v);
void TexCoord2i(GLint s, GLint t);
void TexCoord2iv(GLint v);
void TexCoord2s(GLshort s, GLshort t);
void TexCoord2sv(GLshort v);
void TexCoord2xOES(GLfixed s, GLfixed t);
void TexCoord2xvOES(GLfixed coords);
void TexCoord3bOES(GLbyte s, GLbyte t, GLbyte r);
void TexCoord3bvOES(GLbyte coords);
void TexCoord3d(GLdouble s, GLdouble t, GLdouble r);
void TexCoord3dv(GLdouble v);
void TexCoord3f(GLfloat s, GLfloat t, GLfloat r);
void TexCoord3fv(GLfloat v);
void TexCoord3hNV(GLhalfNV s, GLhalfNV t, GLhalfNV r);
void TexCoord3hvNV(GLhalfNV v);
void TexCoord3i(GLint s, GLint t, GLint r);
void TexCoord3iv(GLint v);
void TexCoord3s(GLshort s, GLshort t, GLshort r);
void TexCoord3sv(GLshort v);
void TexCoord3xOES(GLfixed s, GLfixed t, GLfixed r);
void TexCoord3xvOES(GLfixed coords);
void TexCoord4bOES(GLbyte s, GLbyte t, GLbyte r, GLbyte q);
void TexCoord4bvOES(GLbyte coords);
void TexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
void TexCoord4dv(GLdouble v);
void TexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void TexCoord4fColor4fNormal3fVertex4fSUN(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void TexCoord4fColor4fNormal3fVertex4fvSUN(GLfloat tc, GLfloat c, GLfloat n, GLfloat v);
void TexCoord4fVertex4fSUN(GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void TexCoord4fVertex4fvSUN(GLfloat tc, GLfloat v);
void TexCoord4fv(GLfloat v);
void TexCoord4hNV(GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
void TexCoord4hvNV(GLhalfNV v);
void TexCoord4i(GLint s, GLint t, GLint r, GLint q);
void TexCoord4iv(GLint v);
void TexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q);
void TexCoord4sv(GLshort v);
void TexCoord4xOES(GLfixed s, GLfixed t, GLfixed r, GLfixed q);
void TexCoord4xvOES(GLfixed coords);
void TexCoordFormatNV(GLint size, GLenum type, GLsizei stride);
void TexCoordP1ui(GLenum type, GLuint coords);
void TexCoordP1uiv(GLenum type, GLuint coords);
void TexCoordP2ui(GLenum type, GLuint coords);
void TexCoordP2uiv(GLenum type, GLuint coords);
void TexCoordP3ui(GLenum type, GLuint coords);
void TexCoordP3uiv(GLenum type, GLuint coords);
void TexCoordP4ui(GLenum type, GLuint coords);
void TexCoordP4uiv(GLenum type, GLuint coords);
void TexCoordPointer(GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void TexCoordPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, GLvoid pointer);
void TexCoordPointerListIBM(GLint size, GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride);
void TexCoordPointervINTEL(GLint size, GLenum type, GLvoid * pointer);
void TexEnvf(GLenum target, GLenum pname, GLfloat param);
void TexEnvfv(GLenum target, GLenum pname, GLfloat params);
void TexEnvi(GLenum target, GLenum pname, GLint param);
void TexEnviv(GLenum target, GLenum pname, GLint params);
void TexEnvxOES(GLenum target, GLenum pname, GLfixed param);
void TexEnvxvOES(GLenum target, GLenum pname, GLfixed params);
void TexFilterFuncSGIS(GLenum target, GLenum filter, GLsizei n, GLfloat weights);
void TexGend(GLenum coord, GLenum pname, GLdouble param);
void TexGendv(GLenum coord, GLenum pname, GLdouble params);
void TexGenf(GLenum coord, GLenum pname, GLfloat param);
void TexGenfv(GLenum coord, GLenum pname, GLfloat params);
void TexGeni(GLenum coord, GLenum pname, GLint param);
void TexGeniv(GLenum coord, GLenum pname, GLint params);
void TexGenxOES(GLenum coord, GLenum pname, GLfixed param);
void TexGenxvOES(GLenum coord, GLenum pname, GLfixed params);
void TexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, GLvoid pixels);
void TexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, GLvoid pixels);
void TexImage2DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
void TexImage2DMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
void TexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid pixels);
void TexImage3DEXT(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid pixels);
void TexImage3DMultisample(GLenum target, GLsizei samples, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
void TexImage3DMultisampleCoverageNV(GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
void TexImage4DSGIS(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLint border, GLenum format, GLenum type, GLvoid pixels);
void TexParameterIiv(GLenum target, GLenum pname, GLint params);
void TexParameterIivEXT(GLenum target, GLenum pname, GLint params);
void TexParameterIuiv(GLenum target, GLenum pname, GLuint params);
void TexParameterIuivEXT(GLenum target, GLenum pname, GLuint params);
void TexParameterf(GLenum target, GLenum pname, GLfloat param);
void TexParameterfv(GLenum target, GLenum pname, GLfloat params);
void TexParameteri(GLenum target, GLenum pname, GLint param);
void TexParameteriv(GLenum target, GLenum pname, GLint params);
void TexParameterxOES(GLenum target, GLenum pname, GLfixed param);
void TexParameterxvOES(GLenum target, GLenum pname, GLfixed params);
void TexRenderbufferNV(GLenum target, GLuint renderbuffer);
void TexStorage1D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
void TexStorage2D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
void TexStorage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
void TexStorage3D(GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
void TexStorage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
void TexStorageSparseAMD(GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags);
void TexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid pixels);
void TexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid pixels);
void TexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels);
void TexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels);
void TexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLvoid pixels);
void TexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLvoid pixels);
void TexSubImage4DSGIS(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint woffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLenum format, GLenum type, GLvoid pixels);
void TextureBarrierNV();
void TextureBufferEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
void TextureBufferRangeEXT(GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
void TextureColorMaskSGIS(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
void TextureImage1DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLenum format, GLenum type, GLvoid pixels);
void TextureImage2DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, GLvoid pixels);
void TextureImage2DMultisampleCoverageNV(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
void TextureImage2DMultisampleNV(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
void TextureImage3DEXT(GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, GLvoid pixels);
void TextureImage3DMultisampleCoverageNV(GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
void TextureImage3DMultisampleNV(GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
void TextureLightEXT(GLenum pname);
void TextureMaterialEXT(GLenum face, GLenum mode);
void TextureNormalEXT(GLenum mode);
void TextureParameterIivEXT(GLuint texture, GLenum target, GLenum pname, GLint params);
void TextureParameterIuivEXT(GLuint texture, GLenum target, GLenum pname, GLuint params);
void TextureParameterfEXT(GLuint texture, GLenum target, GLenum pname, GLfloat param);
void TextureParameterfvEXT(GLuint texture, GLenum target, GLenum pname, GLfloat params);
void TextureParameteriEXT(GLuint texture, GLenum target, GLenum pname, GLint param);
void TextureParameterivEXT(GLuint texture, GLenum target, GLenum pname, GLint params);
void TextureRangeAPPLE(GLenum target, GLsizei length, GLvoid pointer);
void TextureRenderbufferEXT(GLuint texture, GLenum target, GLuint renderbuffer);
void TextureStorage1DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
void TextureStorage2DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
void TextureStorage2DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
void TextureStorage3DEXT(GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
void TextureStorage3DMultisampleEXT(GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
void TextureStorageSparseAMD(GLuint texture, GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags);
void TextureSubImage1DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, GLvoid pixels);
void TextureSubImage2DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid pixels);
void TextureSubImage3DEXT(GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLvoid pixels);
void TextureView(GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
void TrackMatrixNV(GLenum target, GLuint address, GLenum matrix, GLenum transform);
void TransformFeedbackAttribsNV(GLsizei count, GLint attribs, GLenum bufferMode);
void TransformFeedbackStreamAttribsNV(GLsizei count, GLint attribs, GLsizei nbuffers, GLint bufstreams, GLenum bufferMode);
void TransformFeedbackVaryings(GLuint program, GLsizei count, GLchar*const varyings, GLenum bufferMode);
void TransformFeedbackVaryingsEXT(GLuint program, GLsizei count, GLchar * varyings, GLenum bufferMode);
void TransformFeedbackVaryingsNV(GLuint program, GLsizei count, GLint locations, GLenum bufferMode);
void TransformPathNV(GLuint resultPath, GLuint srcPath, GLenum transformType, GLfloat transformValues);
void Translated(GLdouble x, GLdouble y, GLdouble z);
void Translatef(GLfloat x, GLfloat y, GLfloat z);
void TranslatexOES(GLfixed x, GLfixed y, GLfixed z);
void Uniform1d(GLint location, GLdouble x);
void Uniform1dv(GLint location, GLsizei count, GLdouble value);
void Uniform1f(GLint location, GLfloat v0);
void Uniform1fARB(GLint location, GLfloat v0);
void Uniform1fv(GLint location, GLsizei count, GLfloat value);
void Uniform1fvARB(GLint location, GLsizei count, GLfloat value);
void Uniform1i(GLint location, GLint v0);
void Uniform1i64NV(GLint location, GLint64EXT x);
void Uniform1i64vNV(GLint location, GLsizei count, GLint64EXT value);
void Uniform1iARB(GLint location, GLint v0);
void Uniform1iv(GLint location, GLsizei count, GLint value);
void Uniform1ivARB(GLint location, GLsizei count, GLint value);
void Uniform1ui(GLint location, GLuint v0);
void Uniform1ui64NV(GLint location, GLuint64EXT x);
void Uniform1ui64vNV(GLint location, GLsizei count, GLuint64EXT value);
void Uniform1uiEXT(GLint location, GLuint v0);
void Uniform1uiv(GLint location, GLsizei count, GLuint value);
void Uniform1uivEXT(GLint location, GLsizei count, GLuint value);
void Uniform2d(GLint location, GLdouble x, GLdouble y);
void Uniform2dv(GLint location, GLsizei count, GLdouble value);
void Uniform2f(GLint location, GLfloat v0, GLfloat v1);
void Uniform2fARB(GLint location, GLfloat v0, GLfloat v1);
void Uniform2fv(GLint location, GLsizei count, GLfloat value);
void Uniform2fvARB(GLint location, GLsizei count, GLfloat value);
void Uniform2i(GLint location, GLint v0, GLint v1);
void Uniform2i64NV(GLint location, GLint64EXT x, GLint64EXT y);
void Uniform2i64vNV(GLint location, GLsizei count, GLint64EXT value);
void Uniform2iARB(GLint location, GLint v0, GLint v1);
void Uniform2iv(GLint location, GLsizei count, GLint value);
void Uniform2ivARB(GLint location, GLsizei count, GLint value);
void Uniform2ui(GLint location, GLuint v0, GLuint v1);
void Uniform2ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y);
void Uniform2ui64vNV(GLint location, GLsizei count, GLuint64EXT value);
void Uniform2uiEXT(GLint location, GLuint v0, GLuint v1);
void Uniform2uiv(GLint location, GLsizei count, GLuint value);
void Uniform2uivEXT(GLint location, GLsizei count, GLuint value);
void Uniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z);
void Uniform3dv(GLint location, GLsizei count, GLdouble value);
void Uniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void Uniform3fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
void Uniform3fv(GLint location, GLsizei count, GLfloat value);
void Uniform3fvARB(GLint location, GLsizei count, GLfloat value);
void Uniform3i(GLint location, GLint v0, GLint v1, GLint v2);
void Uniform3i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
void Uniform3i64vNV(GLint location, GLsizei count, GLint64EXT value);
void Uniform3iARB(GLint location, GLint v0, GLint v1, GLint v2);
void Uniform3iv(GLint location, GLsizei count, GLint value);
void Uniform3ivARB(GLint location, GLsizei count, GLint value);
void Uniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2);
void Uniform3ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
void Uniform3ui64vNV(GLint location, GLsizei count, GLuint64EXT value);
void Uniform3uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2);
void Uniform3uiv(GLint location, GLsizei count, GLuint value);
void Uniform3uivEXT(GLint location, GLsizei count, GLuint value);
void Uniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void Uniform4dv(GLint location, GLsizei count, GLdouble value);
void Uniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void Uniform4fARB(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
void Uniform4fv(GLint location, GLsizei count, GLfloat value);
void Uniform4fvARB(GLint location, GLsizei count, GLfloat value);
void Uniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void Uniform4i64NV(GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
void Uniform4i64vNV(GLint location, GLsizei count, GLint64EXT value);
void Uniform4iARB(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
void Uniform4iv(GLint location, GLsizei count, GLint value);
void Uniform4ivARB(GLint location, GLsizei count, GLint value);
void Uniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
void Uniform4ui64NV(GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
void Uniform4ui64vNV(GLint location, GLsizei count, GLuint64EXT value);
void Uniform4uiEXT(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
void Uniform4uiv(GLint location, GLsizei count, GLuint value);
void Uniform4uivEXT(GLint location, GLsizei count, GLuint value);
void UniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);
void UniformBufferEXT(GLuint program, GLint location, GLuint buffer);
void UniformHandleui64NV(GLint location, GLuint64 value);
void UniformHandleui64vNV(GLint location, GLsizei count, GLuint64 value);
void UniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void UniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void UniformMatrix2fvARB(GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void UniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void UniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void UniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void UniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void UniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void UniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void UniformMatrix3fvARB(GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void UniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void UniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void UniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void UniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void UniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void UniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void UniformMatrix4fvARB(GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void UniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void UniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void UniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, GLdouble value);
void UniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, GLfloat value);
void UniformSubroutinesuiv(GLenum shadertype, GLsizei count, GLuint indices);
void Uniformui64NV(GLint location, GLuint64EXT value);
void Uniformui64vNV(GLint location, GLsizei count, GLuint64EXT value);
void UnlockArraysEXT();
Boolean UnmapBuffer(GLenum target);
Boolean UnmapBufferARB(GLenum target);
Boolean UnmapNamedBufferEXT(GLuint buffer);
void UnmapObjectBufferATI(GLuint buffer);
void UnmapTexture2DINTEL(GLuint texture, GLint level);
void UpdateObjectBufferATI(GLuint buffer, GLuint offset, GLsizei size, GLvoid pointer, GLenum preserve);
void UseProgram(GLuint program);
void UseProgramObjectARB(GLhandleARB programObj);
void UseProgramStages(GLuint pipeline, GLbitfield stages, GLuint program);
void UseShaderProgramEXT(GLenum type, GLuint program);
void VDPAUFiniNV();
void VDPAUGetSurfaceivNV(GLvdpauSurfaceNV surface, GLenum pname, GLsizei bufSize, GLsizei length, GLint values);
void VDPAUInitNV(GLvoid vdpDevice, GLvoid getProcAddress);
void VDPAUIsSurfaceNV(GLvdpauSurfaceNV surface);
void VDPAUMapSurfacesNV(GLsizei numSurfaces, GLvdpauSurfaceNV surfaces);
vdpauSurfaceNV VDPAURegisterOutputSurfaceNV(GLvoid * vdpSurface, GLenum target, GLsizei numTextureNames, GLuint textureNames);
vdpauSurfaceNV VDPAURegisterVideoSurfaceNV(GLvoid vdpSurface, GLenum target, GLsizei numTextureNames, GLuint textureNames);
void VDPAUSurfaceAccessNV(GLvdpauSurfaceNV surface, GLenum access);
void VDPAUUnmapSurfacesNV(GLsizei numSurface, GLvdpauSurfaceNV surfaces);
void VDPAUUnregisterSurfaceNV(GLvdpauSurfaceNV surface);
void ValidateProgram(GLuint program);
void ValidateProgramARB(GLhandleARB programObj);
void ValidateProgramPipeline(GLuint pipeline);
void VariantArrayObjectATI(GLuint id, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
void VariantPointerEXT(GLuint id, GLenum type, GLuint stride, GLvoid addr);
void VariantbvEXT(GLuint id, GLbyte addr);
void VariantdvEXT(GLuint id, GLdouble addr);
void VariantfvEXT(GLuint id, GLfloat addr);
void VariantivEXT(GLuint id, GLint addr);
void VariantsvEXT(GLuint id, GLshort addr);
void VariantubvEXT(GLuint id, GLubyte addr);
void VariantuivEXT(GLuint id, GLuint addr);
void VariantusvEXT(GLuint id, GLushort addr);
void Vertex2bOES(GLbyte x);
void Vertex2bvOES(GLbyte coords);
void Vertex2d(GLdouble x, GLdouble y);
void Vertex2dv(GLdouble v);
void Vertex2f(GLfloat x, GLfloat y);
void Vertex2fv(GLfloat v);
void Vertex2hNV(GLhalfNV x, GLhalfNV y);
void Vertex2hvNV(GLhalfNV v);
void Vertex2i(GLint x, GLint y);
void Vertex2iv(GLint v);
void Vertex2s(GLshort x, GLshort y);
void Vertex2sv(GLshort v);
void Vertex2xOES(GLfixed x);
void Vertex2xvOES(GLfixed coords);
void Vertex3bOES(GLbyte x, GLbyte y);
void Vertex3bvOES(GLbyte coords);
void Vertex3d(GLdouble x, GLdouble y, GLdouble z);
void Vertex3dv(GLdouble v);
void Vertex3f(GLfloat x, GLfloat y, GLfloat z);
void Vertex3fv(GLfloat v);
void Vertex3hNV(GLhalfNV x, GLhalfNV y, GLhalfNV z);
void Vertex3hvNV(GLhalfNV v);
void Vertex3i(GLint x, GLint y, GLint z);
void Vertex3iv(GLint v);
void Vertex3s(GLshort x, GLshort y, GLshort z);
void Vertex3sv(GLshort v);
void Vertex3xOES(GLfixed x, GLfixed y);
void Vertex3xvOES(GLfixed coords);
void Vertex4bOES(GLbyte x, GLbyte y, GLbyte z);
void Vertex4bvOES(GLbyte coords);
void Vertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void Vertex4dv(GLdouble v);
void Vertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void Vertex4fv(GLfloat v);
void Vertex4hNV(GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
void Vertex4hvNV(GLhalfNV v);
void Vertex4i(GLint x, GLint y, GLint z, GLint w);
void Vertex4iv(GLint v);
void Vertex4s(GLshort x, GLshort y, GLshort z, GLshort w);
void Vertex4sv(GLshort v);
void Vertex4xOES(GLfixed x, GLfixed y, GLfixed z);
void Vertex4xvOES(GLfixed coords);
void VertexArrayBindVertexBufferEXT(GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
void VertexArrayColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
void VertexArrayEdgeFlagOffsetEXT(GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset);
void VertexArrayFogCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
void VertexArrayIndexOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
void VertexArrayMultiTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset);
void VertexArrayNormalOffsetEXT(GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
void VertexArrayParameteriAPPLE(GLenum pname, GLint param);
void VertexArrayRangeAPPLE(GLsizei length, GLvoid pointer);
void VertexArrayRangeNV(GLsizei length, GLvoid pointer);
void VertexArraySecondaryColorOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
void VertexArrayTexCoordOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
void VertexArrayVertexAttribBindingEXT(GLuint vaobj, GLuint attribindex, GLuint bindingindex);
void VertexArrayVertexAttribFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
void VertexArrayVertexAttribIFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
void VertexArrayVertexAttribIOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
void VertexArrayVertexAttribLFormatEXT(GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
void VertexArrayVertexAttribLOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
void VertexArrayVertexAttribOffsetEXT(GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset);
void VertexArrayVertexBindingDivisorEXT(GLuint vaobj, GLuint bindingindex, GLuint divisor);
void VertexArrayVertexOffsetEXT(GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
void VertexAttrib1d(GLuint index, GLdouble x);
void VertexAttrib1dARB(GLuint index, GLdouble x);
void VertexAttrib1dNV(GLuint index, GLdouble x);
void VertexAttrib1dv(GLuint index, GLdouble v);
void VertexAttrib1dvARB(GLuint index, GLdouble v);
void VertexAttrib1dvNV(GLuint index, GLdouble v);
void VertexAttrib1f(GLuint index, GLfloat x);
void VertexAttrib1fARB(GLuint index, GLfloat x);
void VertexAttrib1fNV(GLuint index, GLfloat x);
void VertexAttrib1fv(GLuint index, GLfloat v);
void VertexAttrib1fvARB(GLuint index, GLfloat v);
void VertexAttrib1fvNV(GLuint index, GLfloat v);
void VertexAttrib1hNV(GLuint index, GLhalfNV x);
void VertexAttrib1hvNV(GLuint index, GLhalfNV v);
void VertexAttrib1s(GLuint index, GLshort x);
void VertexAttrib1sARB(GLuint index, GLshort x);
void VertexAttrib1sNV(GLuint index, GLshort x);
void VertexAttrib1sv(GLuint index, GLshort v);
void VertexAttrib1svARB(GLuint index, GLshort v);
void VertexAttrib1svNV(GLuint index, GLshort v);
void VertexAttrib2d(GLuint index, GLdouble x, GLdouble y);
void VertexAttrib2dARB(GLuint index, GLdouble x, GLdouble y);
void VertexAttrib2dNV(GLuint index, GLdouble x, GLdouble y);
void VertexAttrib2dv(GLuint index, GLdouble v);
void VertexAttrib2dvARB(GLuint index, GLdouble v);
void VertexAttrib2dvNV(GLuint index, GLdouble v);
void VertexAttrib2f(GLuint index, GLfloat x, GLfloat y);
void VertexAttrib2fARB(GLuint index, GLfloat x, GLfloat y);
void VertexAttrib2fNV(GLuint index, GLfloat x, GLfloat y);
void VertexAttrib2fv(GLuint index, GLfloat v);
void VertexAttrib2fvARB(GLuint index, GLfloat v);
void VertexAttrib2fvNV(GLuint index, GLfloat v);
void VertexAttrib2hNV(GLuint index, GLhalfNV x, GLhalfNV y);
void VertexAttrib2hvNV(GLuint index, GLhalfNV v);
void VertexAttrib2s(GLuint index, GLshort x, GLshort y);
void VertexAttrib2sARB(GLuint index, GLshort x, GLshort y);
void VertexAttrib2sNV(GLuint index, GLshort x, GLshort y);
void VertexAttrib2sv(GLuint index, GLshort v);
void VertexAttrib2svARB(GLuint index, GLshort v);
void VertexAttrib2svNV(GLuint index, GLshort v);
void VertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z);
void VertexAttrib3dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z);
void VertexAttrib3dNV(GLuint index, GLdouble x, GLdouble y, GLdouble z);
void VertexAttrib3dv(GLuint index, GLdouble v);
void VertexAttrib3dvARB(GLuint index, GLdouble v);
void VertexAttrib3dvNV(GLuint index, GLdouble v);
void VertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z);
void VertexAttrib3fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z);
void VertexAttrib3fNV(GLuint index, GLfloat x, GLfloat y, GLfloat z);
void VertexAttrib3fv(GLuint index, GLfloat v);
void VertexAttrib3fvARB(GLuint index, GLfloat v);
void VertexAttrib3fvNV(GLuint index, GLfloat v);
void VertexAttrib3hNV(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z);
void VertexAttrib3hvNV(GLuint index, GLhalfNV v);
void VertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z);
void VertexAttrib3sARB(GLuint index, GLshort x, GLshort y, GLshort z);
void VertexAttrib3sNV(GLuint index, GLshort x, GLshort y, GLshort z);
void VertexAttrib3sv(GLuint index, GLshort v);
void VertexAttrib3svARB(GLuint index, GLshort v);
void VertexAttrib3svNV(GLuint index, GLshort v);
void VertexAttrib4Nbv(GLuint index, GLbyte v);
void VertexAttrib4NbvARB(GLuint index, GLbyte v);
void VertexAttrib4Niv(GLuint index, GLint v);
void VertexAttrib4NivARB(GLuint index, GLint v);
void VertexAttrib4Nsv(GLuint index, GLshort v);
void VertexAttrib4NsvARB(GLuint index, GLshort v);
void VertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
void VertexAttrib4NubARB(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
void VertexAttrib4Nubv(GLuint index, GLubyte v);
void VertexAttrib4NubvARB(GLuint index, GLubyte v);
void VertexAttrib4Nuiv(GLuint index, GLuint v);
void VertexAttrib4NuivARB(GLuint index, GLuint v);
void VertexAttrib4Nusv(GLuint index, GLushort v);
void VertexAttrib4NusvARB(GLuint index, GLushort v);
void VertexAttrib4bv(GLuint index, GLbyte v);
void VertexAttrib4bvARB(GLuint index, GLbyte v);
void VertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void VertexAttrib4dARB(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void VertexAttrib4dNV(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void VertexAttrib4dv(GLuint index, GLdouble v);
void VertexAttrib4dvARB(GLuint index, GLdouble v);
void VertexAttrib4dvNV(GLuint index, GLdouble v);
void VertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void VertexAttrib4fARB(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void VertexAttrib4fNV(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void VertexAttrib4fv(GLuint index, GLfloat v);
void VertexAttrib4fvARB(GLuint index, GLfloat v);
void VertexAttrib4fvNV(GLuint index, GLfloat v);
void VertexAttrib4hNV(GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
void VertexAttrib4hvNV(GLuint index, GLhalfNV v);
void VertexAttrib4iv(GLuint index, GLint v);
void VertexAttrib4ivARB(GLuint index, GLint v);
void VertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
void VertexAttrib4sARB(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
void VertexAttrib4sNV(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
void VertexAttrib4sv(GLuint index, GLshort v);
void VertexAttrib4svARB(GLuint index, GLshort v);
void VertexAttrib4svNV(GLuint index, GLshort v);
void VertexAttrib4ubNV(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
void VertexAttrib4ubv(GLuint index, GLubyte v);
void VertexAttrib4ubvARB(GLuint index, GLubyte v);
void VertexAttrib4ubvNV(GLuint index, GLubyte v);
void VertexAttrib4uiv(GLuint index, GLuint v);
void VertexAttrib4uivARB(GLuint index, GLuint v);
void VertexAttrib4usv(GLuint index, GLushort v);
void VertexAttrib4usvARB(GLuint index, GLushort v);
void VertexAttribArrayObjectATI(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint buffer, GLuint offset);
void VertexAttribBinding(GLuint attribindex, GLuint bindingindex);
void VertexAttribDivisor(GLuint index, GLuint divisor);
void VertexAttribDivisorARB(GLuint index, GLuint divisor);
void VertexAttribFormat(GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
void VertexAttribFormatNV(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
void VertexAttribI1i(GLuint index, GLint x);
void VertexAttribI1iEXT(GLuint index, GLint x);
void VertexAttribI1iv(GLuint index, GLint v);
void VertexAttribI1ivEXT(GLuint index, GLint v);
void VertexAttribI1ui(GLuint index, GLuint x);
void VertexAttribI1uiEXT(GLuint index, GLuint x);
void VertexAttribI1uiv(GLuint index, GLuint v);
void VertexAttribI1uivEXT(GLuint index, GLuint v);
void VertexAttribI2i(GLuint index, GLint x, GLint y);
void VertexAttribI2iEXT(GLuint index, GLint x, GLint y);
void VertexAttribI2iv(GLuint index, GLint v);
void VertexAttribI2ivEXT(GLuint index, GLint v);
void VertexAttribI2ui(GLuint index, GLuint x, GLuint y);
void VertexAttribI2uiEXT(GLuint index, GLuint x, GLuint y);
void VertexAttribI2uiv(GLuint index, GLuint v);
void VertexAttribI2uivEXT(GLuint index, GLuint v);
void VertexAttribI3i(GLuint index, GLint x, GLint y, GLint z);
void VertexAttribI3iEXT(GLuint index, GLint x, GLint y, GLint z);
void VertexAttribI3iv(GLuint index, GLint v);
void VertexAttribI3ivEXT(GLuint index, GLint v);
void VertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z);
void VertexAttribI3uiEXT(GLuint index, GLuint x, GLuint y, GLuint z);
void VertexAttribI3uiv(GLuint index, GLuint v);
void VertexAttribI3uivEXT(GLuint index, GLuint v);
void VertexAttribI4bv(GLuint index, GLbyte v);
void VertexAttribI4bvEXT(GLuint index, GLbyte v);
void VertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w);
void VertexAttribI4iEXT(GLuint index, GLint x, GLint y, GLint z, GLint w);
void VertexAttribI4iv(GLuint index, GLint v);
void VertexAttribI4ivEXT(GLuint index, GLint v);
void VertexAttribI4sv(GLuint index, GLshort v);
void VertexAttribI4svEXT(GLuint index, GLshort v);
void VertexAttribI4ubv(GLuint index, GLubyte v);
void VertexAttribI4ubvEXT(GLuint index, GLubyte v);
void VertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
void VertexAttribI4uiEXT(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
void VertexAttribI4uiv(GLuint index, GLuint v);
void VertexAttribI4uivEXT(GLuint index, GLuint v);
void VertexAttribI4usv(GLuint index, GLushort v);
void VertexAttribI4usvEXT(GLuint index, GLushort v);
void VertexAttribIFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
void VertexAttribIFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride);
void VertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void VertexAttribIPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void VertexAttribL1d(GLuint index, GLdouble x);
void VertexAttribL1dEXT(GLuint index, GLdouble x);
void VertexAttribL1dv(GLuint index, GLdouble v);
void VertexAttribL1dvEXT(GLuint index, GLdouble v);
void VertexAttribL1i64NV(GLuint index, GLint64EXT x);
void VertexAttribL1i64vNV(GLuint index, GLint64EXT v);
void VertexAttribL1ui64NV(GLuint index, GLuint64EXT x);
void VertexAttribL1ui64vNV(GLuint index, GLuint64EXT v);
void VertexAttribL2d(GLuint index, GLdouble x, GLdouble y);
void VertexAttribL2dEXT(GLuint index, GLdouble x, GLdouble y);
void VertexAttribL2dv(GLuint index, GLdouble v);
void VertexAttribL2dvEXT(GLuint index, GLdouble v);
void VertexAttribL2i64NV(GLuint index, GLint64EXT x, GLint64EXT y);
void VertexAttribL2i64vNV(GLuint index, GLint64EXT v);
void VertexAttribL2ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y);
void VertexAttribL2ui64vNV(GLuint index, GLuint64EXT v);
void VertexAttribL3d(GLuint index, GLdouble x, GLdouble y, GLdouble z);
void VertexAttribL3dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z);
void VertexAttribL3dv(GLuint index, GLdouble v);
void VertexAttribL3dvEXT(GLuint index, GLdouble v);
void VertexAttribL3i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z);
void VertexAttribL3i64vNV(GLuint index, GLint64EXT v);
void VertexAttribL3ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
void VertexAttribL3ui64vNV(GLuint index, GLuint64EXT v);
void VertexAttribL4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void VertexAttribL4dEXT(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void VertexAttribL4dv(GLuint index, GLdouble v);
void VertexAttribL4dvEXT(GLuint index, GLdouble v);
void VertexAttribL4i64NV(GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
void VertexAttribL4i64vNV(GLuint index, GLint64EXT v);
void VertexAttribL4ui64NV(GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
void VertexAttribL4ui64vNV(GLuint index, GLuint64EXT v);
void VertexAttribLFormat(GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
void VertexAttribLFormatNV(GLuint index, GLint size, GLenum type, GLsizei stride);
void VertexAttribLPointer(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void VertexAttribLPointerEXT(GLuint index, GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void VertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void VertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void VertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void VertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void VertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void VertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void VertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void VertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, GLuint value);
void VertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid pointer);
void VertexAttribPointerARB(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid pointer);
void VertexAttribPointerNV(GLuint index, GLint fsize, GLenum type, GLsizei stride, GLvoid pointer);
void VertexAttribs1dvNV(GLuint index, GLsizei count, GLdouble v);
void VertexAttribs1fvNV(GLuint index, GLsizei count, GLfloat v);
void VertexAttribs1hvNV(GLuint index, GLsizei n, GLhalfNV v);
void VertexAttribs1svNV(GLuint index, GLsizei count, GLshort v);
void VertexAttribs2dvNV(GLuint index, GLsizei count, GLdouble v);
void VertexAttribs2fvNV(GLuint index, GLsizei count, GLfloat v);
void VertexAttribs2hvNV(GLuint index, GLsizei n, GLhalfNV v);
void VertexAttribs2svNV(GLuint index, GLsizei count, GLshort v);
void VertexAttribs3dvNV(GLuint index, GLsizei count, GLdouble v);
void VertexAttribs3fvNV(GLuint index, GLsizei count, GLfloat v);
void VertexAttribs3hvNV(GLuint index, GLsizei n, GLhalfNV v);
void VertexAttribs3svNV(GLuint index, GLsizei count, GLshort v);
void VertexAttribs4dvNV(GLuint index, GLsizei count, GLdouble v);
void VertexAttribs4fvNV(GLuint index, GLsizei count, GLfloat v);
void VertexAttribs4hvNV(GLuint index, GLsizei n, GLhalfNV v);
void VertexAttribs4svNV(GLuint index, GLsizei count, GLshort v);
void VertexAttribs4ubvNV(GLuint index, GLsizei count, GLubyte v);
void VertexBindingDivisor(GLuint bindingindex, GLuint divisor);
void VertexBlendARB(GLint count);
void VertexBlendEnvfATI(GLenum pname, GLfloat param);
void VertexBlendEnviATI(GLenum pname, GLint param);
void VertexFormatNV(GLint size, GLenum type, GLsizei stride);
void VertexP2ui(GLenum type, GLuint value);
void VertexP2uiv(GLenum type, GLuint value);
void VertexP3ui(GLenum type, GLuint value);
void VertexP3uiv(GLenum type, GLuint value);
void VertexP4ui(GLenum type, GLuint value);
void VertexP4uiv(GLenum type, GLuint value);
void VertexPointer(GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void VertexPointerEXT(GLint size, GLenum type, GLsizei stride, GLsizei count, GLvoid pointer);
void VertexPointerListIBM(GLint size, GLenum type, GLint stride, GLvoid * pointer, GLint ptrstride);
void VertexPointervINTEL(GLint size, GLenum type, GLvoid * pointer);
void VertexStream1dATI(GLenum stream, GLdouble x);
void VertexStream1dvATI(GLenum stream, GLdouble coords);
void VertexStream1fATI(GLenum stream, GLfloat x);
void VertexStream1fvATI(GLenum stream, GLfloat coords);
void VertexStream1iATI(GLenum stream, GLint x);
void VertexStream1ivATI(GLenum stream, GLint coords);
void VertexStream1sATI(GLenum stream, GLshort x);
void VertexStream1svATI(GLenum stream, GLshort coords);
void VertexStream2dATI(GLenum stream, GLdouble x, GLdouble y);
void VertexStream2dvATI(GLenum stream, GLdouble coords);
void VertexStream2fATI(GLenum stream, GLfloat x, GLfloat y);
void VertexStream2fvATI(GLenum stream, GLfloat coords);
void VertexStream2iATI(GLenum stream, GLint x, GLint y);
void VertexStream2ivATI(GLenum stream, GLint coords);
void VertexStream2sATI(GLenum stream, GLshort x, GLshort y);
void VertexStream2svATI(GLenum stream, GLshort coords);
void VertexStream3dATI(GLenum stream, GLdouble x, GLdouble y, GLdouble z);
void VertexStream3dvATI(GLenum stream, GLdouble coords);
void VertexStream3fATI(GLenum stream, GLfloat x, GLfloat y, GLfloat z);
void VertexStream3fvATI(GLenum stream, GLfloat coords);
void VertexStream3iATI(GLenum stream, GLint x, GLint y, GLint z);
void VertexStream3ivATI(GLenum stream, GLint coords);
void VertexStream3sATI(GLenum stream, GLshort x, GLshort y, GLshort z);
void VertexStream3svATI(GLenum stream, GLshort coords);
void VertexStream4dATI(GLenum stream, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void VertexStream4dvATI(GLenum stream, GLdouble coords);
void VertexStream4fATI(GLenum stream, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void VertexStream4fvATI(GLenum stream, GLfloat coords);
void VertexStream4iATI(GLenum stream, GLint x, GLint y, GLint z, GLint w);
void VertexStream4ivATI(GLenum stream, GLint coords);
void VertexStream4sATI(GLenum stream, GLshort x, GLshort y, GLshort z, GLshort w);
void VertexStream4svATI(GLenum stream, GLshort coords);
void VertexWeightPointerEXT(GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void VertexWeightfEXT(GLfloat weight);
void VertexWeightfvEXT(GLfloat weight);
void VertexWeighthNV(GLhalfNV weight);
void VertexWeighthvNV(GLhalfNV weight);
GLenum VideoCaptureNV(GLuint video_capture_slot, GLuint sequence_num, GLuint64EXT capture_time);
void VideoCaptureStreamParameterdvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble params);
void VideoCaptureStreamParameterfvNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat params);
void VideoCaptureStreamParameterivNV(GLuint video_capture_slot, GLuint stream, GLenum pname, GLint params);
void Viewport(GLint x, GLint y, GLsizei width, GLsizei height);
void ViewportArrayv(GLuint first, GLsizei count, GLfloat v);
void ViewportIndexedf(GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
void ViewportIndexedfv(GLuint index, GLfloat v);
void WaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout);
void WeightPathsNV(GLuint resultPath, GLsizei numPaths, GLuint paths, GLfloat weights);
void WeightPointerARB(GLint size, GLenum type, GLsizei stride, GLvoid pointer);
void WeightbvARB(GLint size, GLbyte weights);
void WeightdvARB(GLint size, GLdouble weights);
void WeightfvARB(GLint size, GLfloat weights);
void WeightivARB(GLint size, GLint weights);
void WeightsvARB(GLint size, GLshort weights);
void WeightubvARB(GLint size, GLubyte weights);
void WeightuivARB(GLint size, GLuint weights);
void WeightusvARB(GLint size, GLushort weights);
void WindowPos2d(GLdouble x, GLdouble y);
void WindowPos2dARB(GLdouble x, GLdouble y);
void WindowPos2dMESA(GLdouble x, GLdouble y);
void WindowPos2dv(GLdouble v);
void WindowPos2dvARB(GLdouble v);
void WindowPos2dvMESA(GLdouble v);
void WindowPos2f(GLfloat x, GLfloat y);
void WindowPos2fARB(GLfloat x, GLfloat y);
void WindowPos2fMESA(GLfloat x, GLfloat y);
void WindowPos2fv(GLfloat v);
void WindowPos2fvARB(GLfloat v);
void WindowPos2fvMESA(GLfloat v);
void WindowPos2i(GLint x, GLint y);
void WindowPos2iARB(GLint x, GLint y);
void WindowPos2iMESA(GLint x, GLint y);
void WindowPos2iv(GLint v);
void WindowPos2ivARB(GLint v);
void WindowPos2ivMESA(GLint v);
void WindowPos2s(GLshort x, GLshort y);
void WindowPos2sARB(GLshort x, GLshort y);
void WindowPos2sMESA(GLshort x, GLshort y);
void WindowPos2sv(GLshort v);
void WindowPos2svARB(GLshort v);
void WindowPos2svMESA(GLshort v);
void WindowPos3d(GLdouble x, GLdouble y, GLdouble z);
void WindowPos3dARB(GLdouble x, GLdouble y, GLdouble z);
void WindowPos3dMESA(GLdouble x, GLdouble y, GLdouble z);
void WindowPos3dv(GLdouble v);
void WindowPos3dvARB(GLdouble v);
void WindowPos3dvMESA(GLdouble v);
void WindowPos3f(GLfloat x, GLfloat y, GLfloat z);
void WindowPos3fARB(GLfloat x, GLfloat y, GLfloat z);
void WindowPos3fMESA(GLfloat x, GLfloat y, GLfloat z);
void WindowPos3fv(GLfloat v);
void WindowPos3fvARB(GLfloat v);
void WindowPos3fvMESA(GLfloat v);
void WindowPos3i(GLint x, GLint y, GLint z);
void WindowPos3iARB(GLint x, GLint y, GLint z);
void WindowPos3iMESA(GLint x, GLint y, GLint z);
void WindowPos3iv(GLint v);
void WindowPos3ivARB(GLint v);
void WindowPos3ivMESA(GLint v);
void WindowPos3s(GLshort x, GLshort y, GLshort z);
void WindowPos3sARB(GLshort x, GLshort y, GLshort z);
void WindowPos3sMESA(GLshort x, GLshort y, GLshort z);
void WindowPos3sv(GLshort v);
void WindowPos3svARB(GLshort v);
void WindowPos3svMESA(GLshort v);
void WindowPos4dMESA(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
void WindowPos4dvMESA(GLdouble v);
void WindowPos4fMESA(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void WindowPos4fvMESA(GLfloat v);
void WindowPos4iMESA(GLint x, GLint y, GLint z, GLint w);
void WindowPos4ivMESA(GLint v);
void WindowPos4sMESA(GLshort x, GLshort y, GLshort z, GLshort w);
void WindowPos4svMESA(GLshort v);
void WriteMaskEXT(GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
Bool AssociateDMPbufferSGIX(Display dpy, GLXPbufferSGIX pbuffer, DMparams params, DMbuffer dmbuffer);
int BindChannelToWindowSGIX(Display display, int screen, int channel, Window window);
int BindHyperpipeSGIX(Display dpy, int hpId);
Bool BindSwapBarrierNV(Display dpy, GLuint group, GLuint barrier);
void BindSwapBarrierSGIX(Display dpy, GLXDrawable drawable, int barrier);
void BindTexImageEXT(Display dpy, GLXDrawable drawable, int buffer, int attrib_list);
int BindVideoCaptureDeviceNV(Display dpy, unsigned int video_capture_slot, GLXVideoCaptureDeviceNV device);
int BindVideoDeviceNV(Display dpy, unsigned int video_slot, unsigned int video_device, int attrib_list);
int BindVideoImageNV(Display dpy, GLXVideoDeviceNV VideoDevice, GLXPbuffer pbuf, int iVideoBuffer);
int ChannelRectSGIX(Display display, int screen, int channel, int x, int y, int w, int h);
int ChannelRectSyncSGIX(Display display, int screen, int channel, GLenum synctype);
GLXFBConfigPointer ChooseFBConfig(Display dpy, int screen, int attrib_list, int nelements);
GLXFBConfigSGIXPointer ChooseFBConfigSGIX(Display dpy, int screen, int attrib_list, int nelements);
void CopyImageSubDataNV(Display dpy, GLXContext srcCtx, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLXContext dstCtx, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
void CopySubBufferMESA(Display dpy, GLXDrawable drawable, int x, int y, int width, int height);
GLXContext CreateContextAttribsARB(Display dpy, GLXFBConfig config, GLXContext share_context, Bool direct, int attrib_list);
GLXContext CreateContextWithConfigSGIX(Display dpy, GLXFBConfigSGIX config, int render_type, GLXContext share_list, Bool direct);
GLXPbufferSGIX CreateGLXPbufferSGIX(Display dpy, GLXFBConfigSGIX config, unsigned int width, unsigned int height, int attrib_list);
GLXPixmap CreateGLXPixmapMESA(Display dpy, XVisualInfo visual, Pixmap pixmap, Colormap cmap);
GLXPixmap CreateGLXPixmapWithConfigSGIX(Display dpy, GLXFBConfigSGIX config, Pixmap pixmap);
GLXVideoSourceSGIX CreateGLXVideoSourceSGIX(Display display, int screen, VLServer server, VLPath path, int nodeClass, VLNode drainNode);
GLXContext CreateNewContext(Display dpy, GLXFBConfig config, int render_type, GLXContext share_list, Bool direct);
GLXPbuffer CreatePbuffer(Display dpy, GLXFBConfig config, int attrib_list);
GLXPixmap CreatePixmap(Display dpy, GLXFBConfig config, Pixmap pixmap, int attrib_list);
GLXWindow CreateWindow(Display dpy, GLXFBConfig config, Window win, int attrib_list);
void CushionSGI(Display dpy, Window window, float cushion);
void DestroyGLXPbufferSGIX(Display dpy, GLXPbufferSGIX pbuf);
void DestroyGLXVideoSourceSGIX(Display dpy, GLXVideoSourceSGIX glxvideosource);
int DestroyHyperpipeConfigSGIX(Display dpy, int hpId);
void DestroyPbuffer(Display dpy, GLXPbuffer pbuf);
void DestroyPixmap(Display dpy, GLXPixmap pixmap);
void DestroyWindow(Display dpy, GLXWindow win);
GLXVideoCaptureDeviceNVPointer EnumerateVideoCaptureDevicesNV(Display dpy, int screen, int nelements);
uintPointer EnumerateVideoDevicesNV(Display dpy, int screen, int nelements);
void FreeContextEXT(Display dpy, GLXContext context);
uint GetAGPOffsetMESA(void pointer);
GLXContextID GetContextIDEXT(const GLXContext context);
DisplayPointer GetCurrentDisplay();
DisplayPointer GetCurrentDisplayEXT();
GLXDrawable GetCurrentReadDrawable();
GLXDrawable GetCurrentReadDrawableSGI();
int GetFBConfigAttrib(Display dpy, GLXFBConfig config, int attribute, int value);
int GetFBConfigAttribSGIX(Display dpy, GLXFBConfigSGIX config, int attribute, int value);
GLXFBConfigSGIX GetFBConfigFromVisualSGIX(Display dpy, XVisualInfo vis);
GLXFBConfigPointer GetFBConfigs(Display dpy, int screen, int nelements);
Bool GetMscRateOML(Display dpy, GLXDrawable drawable, int32_t numerator, int32_t denominator);
FunctionPointer GetProcAddress(GLubyte procName);
FunctionPointer GetProcAddressARB(GLubyte procName);
void GetSelectedEvent(Display dpy, GLXDrawable draw, unsigned long event_mask);
void GetSelectedEventSGIX(Display dpy, GLXDrawable drawable, unsigned long mask);
Bool GetSyncValuesOML(Display dpy, GLXDrawable drawable, int64_t ust, int64_t msc, int64_t sbc);
Status GetTransparentIndexSUN(Display dpy, Window overlay, Window underlay, long pTransparentIndex);
int GetVideoDeviceNV(Display dpy, int screen, int numVideoDevices, GLXVideoDeviceNV pVideoDevice);
int GetVideoInfoNV(Display dpy, int screen, GLXVideoDeviceNV VideoDevice, unsigned long pulCounterOutputPbuffer, unsigned long pulCounterOutputVideo);
int GetVideoSyncSGI(unsigned int count);
XVisualInfoPointer GetVisualFromFBConfig(Display dpy, GLXFBConfig config);
XVisualInfoPointer GetVisualFromFBConfigSGIX(Display dpy, GLXFBConfigSGIX config);
int HyperpipeAttribSGIX(Display dpy, int timeSlice, int attrib, int size, void attribList);
int HyperpipeConfigSGIX(Display dpy, int networkId, int npipes, GLXHyperpipeConfigSGIX cfg, int hpId);
GLXContext ImportContextEXT(Display dpy, GLXContextID contextID);
Bool JoinSwapGroupNV(Display dpy, GLXDrawable drawable, GLuint group);
void JoinSwapGroupSGIX(Display dpy, GLXDrawable drawable, GLXDrawable member);
void LockVideoCaptureDeviceNV(Display dpy, GLXVideoCaptureDeviceNV device);
Bool MakeContextCurrent(Display dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
Bool MakeCurrentReadSGI(Display dpy, GLXDrawable draw, GLXDrawable read, GLXContext ctx);
int QueryChannelDeltasSGIX(Display display, int screen, int channel, int x, int y, int w, int h);
int QueryChannelRectSGIX(Display display, int screen, int channel, int dx, int dy, int dw, int dh);
int QueryContext(Display dpy, GLXContext ctx, int attribute, int value);
int QueryContextInfoEXT(Display dpy, GLXContext context, int attribute, int value);
void QueryDrawable(Display dpy, GLXDrawable draw, int attribute, unsigned int value);
Bool QueryFrameCountNV(Display dpy, int screen, GLuint count);
int QueryGLXPbufferSGIX(Display dpy, GLXPbufferSGIX pbuf, int attribute, unsigned int value);
int QueryHyperpipeAttribSGIX(Display dpy, int timeSlice, int attrib, int size, void returnAttribList);
int QueryHyperpipeBestAttribSGIX(Display dpy, int timeSlice, int attrib, int size, void attribList, void returnAttribList);
GLXHyperpipeConfigSGIXPointer QueryHyperpipeConfigSGIX(Display dpy, int hpId, int npipes);
GLXHyperpipeNetworkSGIXPointer QueryHyperpipeNetworkSGIX(Display dpy, int npipes);
Bool QueryMaxSwapBarriersSGIX(Display dpy, int screen, int max);
Bool QueryMaxSwapGroupsNV(Display dpy, int screen, GLuint maxGroups, GLuint maxBarriers);
Bool QuerySwapGroupNV(Display dpy, GLXDrawable drawable, GLuint group, GLuint barrier);
int QueryVideoCaptureDeviceNV(Display dpy, GLXVideoCaptureDeviceNV device, int attribute, int value);
Bool ReleaseBuffersMESA(Display dpy, GLXDrawable drawable);
void ReleaseTexImageEXT(Display dpy, GLXDrawable drawable, int buffer);
void ReleaseVideoCaptureDeviceNV(Display dpy, GLXVideoCaptureDeviceNV device);
int ReleaseVideoDeviceNV(Display dpy, int screen, GLXVideoDeviceNV VideoDevice);
int ReleaseVideoImageNV(Display dpy, GLXPbuffer pbuf);
Bool ResetFrameCountNV(Display dpy, int screen);
void SelectEvent(Display dpy, GLXDrawable draw, unsigned long event_mask);
void SelectEventSGIX(Display dpy, GLXDrawable drawable, unsigned long mask);
int SendPbufferToVideoNV(Display dpy, GLXPbuffer pbuf, int iBufferType, unsigned long pulCounterPbuffer, GLboolean bBlock);
Bool Set3DfxModeMESA(int mode);
int64_t SwapBuffersMscOML(Display dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder);
void SwapIntervalEXT(Display dpy, GLXDrawable drawable, int interval);
int SwapIntervalSGI(int interval);
Bool WaitForMscOML(Display dpy, GLXDrawable drawable, int64_t target_msc, int64_t divisor, int64_t remainder, int64_t ust, int64_t msc, int64_t sbc);
Bool WaitForSbcOML(Display dpy, GLXDrawable drawable, int64_t target_sbc, int64_t ust, int64_t msc, int64_t sbc);
int WaitVideoSyncSGI(int divisor, int remainder, unsigned int count);



#endif
