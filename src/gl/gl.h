#include <dlfcn.h>
//#include <GLES/gl.h>
#include "gles.h"
#include <EGL/egl.h>
#ifdef TEXSTREAM
#include <EGL/eglext.h>
#endif
#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "khash.h"

#ifdef __ARM_NEON__
#include <arm_neon.h>
#endif

#ifndef AliasExport
#define AliasExport(name)   __attribute__((alias(name))) __attribute__((visibility("default")))
#endif

#ifndef FASTMATH
#ifdef __GNUC__
 #ifdef __arm__
  #ifdef __ARM_PCS_VFP
   //#warning Arm Hardfloat detected
   #define FASTMATH
  #else
   #if defined(__ARM_FP) && defined(PANDORA)
    //#warning Arm SoftFP detected
    #define FASTMATH __attribute__((pcs("aapcs-vfp")))
   #else
	//#warning Arm no FP detected
	#define FASTMATH
   #endif
  #endif
 #else
  #define FASTMATH
 #endif
#else
 #define FASTMATH
#endif
#endif

#ifndef GL_H
#define GL_H

#include "../config.h"
#include "wrap/es.h"
#include "const.h"

//Typedef for egl to be abble to call LOAD_EGL...

typedef EGLBoolean (*eglBindAPI_PTR)(EGLenum api);
typedef EGLBoolean (*eglBindTexImage_PTR)(EGLDisplay dpy, EGLSurface surface, EGLint buffer);
typedef EGLBoolean (*eglChooseConfig_PTR)(EGLDisplay dpy, const EGLint * attrib_list, EGLConfig * configs, EGLint config_size, EGLint * num_config);
typedef EGLBoolean (*eglCopyBuffers_PTR)(EGLDisplay dpy, EGLSurface surface, EGLNativePixmapType target);
typedef EGLContext (*eglCreateContext_PTR)(EGLDisplay dpy, EGLConfig config, EGLContext share_context, const EGLint * attrib_list);
typedef EGLSurface (*eglCreatePbufferFromClientBuffer_PTR)(EGLDisplay dpy, EGLenum buftype, EGLClientBuffer buffer, EGLConfig config, const EGLint * attrib_list);
typedef EGLSurface (*eglCreatePbufferSurface_PTR)(EGLDisplay dpy, EGLConfig config, const EGLint * attrib_list);
typedef EGLSurface (*eglCreatePixmapSurface_PTR)(EGLDisplay dpy, EGLConfig config, EGLNativePixmapType pixmap, const EGLint * attrib_list);
typedef EGLSurface (*eglCreateWindowSurface_PTR)(EGLDisplay dpy, EGLConfig config, EGLNativeWindowType win, const EGLint * attrib_list);
typedef EGLBoolean (*eglDestroyContext_PTR)(EGLDisplay dpy, EGLContext ctx);
typedef EGLBoolean (*eglDestroySurface_PTR)(EGLDisplay dpy, EGLSurface surface);
typedef EGLBoolean (*eglGetConfigAttrib_PTR)(EGLDisplay dpy, EGLConfig config, EGLint attribute, EGLint * value);
typedef EGLBoolean (*eglGetConfigs_PTR)(EGLDisplay dpy, EGLConfig * configs, EGLint config_size, EGLint * num_config);
typedef EGLContext (*eglGetCurrentContext_PTR)();
typedef EGLDisplay (*eglGetCurrentDisplay_PTR)();
typedef EGLSurface (*eglGetCurrentSurface_PTR)(EGLint readdraw);
typedef EGLDisplay (*eglGetDisplay_PTR)(EGLNativeDisplayType display_id);
typedef EGLint (*eglGetError_PTR)();
typedef __eglMustCastToProperFunctionPointerType (*eglGetProcAddress_PTR)(const char * procname);
typedef EGLBoolean (*eglInitialize_PTR)(EGLDisplay dpy, EGLint * major, EGLint * minor);
typedef EGLBoolean (*eglMakeCurrent_PTR)(EGLDisplay dpy, EGLSurface draw, EGLSurface read, EGLContext ctx);
typedef EGLenum (*eglQueryAPI_PTR)();
typedef EGLBoolean (*eglQueryContext_PTR)(EGLDisplay dpy, EGLContext ctx, EGLint attribute, EGLint * value);
typedef const char * (*eglQueryString_PTR)(EGLDisplay dpy, EGLint name);
typedef EGLBoolean (*eglQuerySurface_PTR)(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint * value);
typedef EGLBoolean (*eglReleaseTexImage_PTR)(EGLDisplay dpy, EGLSurface surface, EGLint buffer);
typedef EGLBoolean (*eglReleaseThread_PTR)();
typedef EGLBoolean (*eglSurfaceAttrib_PTR)(EGLDisplay dpy, EGLSurface surface, EGLint attribute, EGLint value);
typedef EGLBoolean (*eglSwapBuffers_PTR)(EGLDisplay dpy, EGLSurface surface);
typedef EGLBoolean (*eglSwapBuffersWithDamageEXT_PTR)(EGLDisplay dpy, EGLSurface surface, EGLint * rects, EGLint n_rects);
typedef EGLBoolean (*eglSwapInterval_PTR)(EGLDisplay dpy, EGLint interval);
typedef EGLBoolean (*eglTerminate_PTR)(EGLDisplay dpy);
typedef EGLBoolean (*eglUnlockSurfaceKHR_PTR)(EGLDisplay display, EGLSurface surface);
typedef EGLBoolean (*eglWaitClient_PTR)();
typedef EGLBoolean (*eglWaitGL_PTR)();
typedef EGLBoolean (*eglWaitNative_PTR)(EGLint engine);
#ifdef TEXSTREAM
typedef EGLSurface (*eglCreatePixmapSurfaceHI_PTR)(EGLDisplay dpy, EGLConfig config, struct EGLClientPixmapHI * pixmap);
typedef EGLBoolean (*eglDestroyImageKHR_PTR)(EGLDisplay dpy, EGLImageKHR image);
typedef EGLBoolean (*eglDestroyStreamKHR_PTR)(EGLDisplay dpy, EGLStreamKHR stream);
typedef EGLImageKHR (*eglCreateImageKHR_PTR)(EGLDisplay dpy, EGLContext ctx, EGLenum target, EGLClientBuffer buffer, const EGLint * attrib_list);
typedef EGLStreamKHR (*eglCreateStreamFromFileDescriptorKHR_PTR)(EGLDisplay dpy, EGLNativeFileDescriptorKHR file_descriptor);
typedef EGLStreamKHR (*eglCreateStreamKHR_PTR)(EGLDisplay dpy, const EGLint * attrib_list);
typedef EGLSyncKHR (*eglCreateSyncKHR_PTR)(EGLDisplay dpy, EGLenum type, const EGLint * attrib_list);
typedef EGLBoolean (*eglDestroySyncKHR_PTR)(EGLDisplay dpy, EGLSyncKHR sync);
typedef EGLBoolean (*eglSignalSyncKHR_PTR)(EGLDisplay dpy, EGLSyncKHR sync, EGLenum mode);
typedef EGLBoolean (*eglGetSyncAttribKHR_PTR)(EGLDisplay dpy, EGLSyncKHR sync, EGLint attribute, EGLint * value);
typedef EGLBoolean (*eglStreamAttribKHR_PTR)(EGLDisplay dpy, EGLStreamKHR stream, EGLenum attribute, EGLint value);
typedef EGLBoolean (*eglStreamConsumerAcquireKHR_PTR)(EGLDisplay dpy, EGLStreamKHR stream);
typedef EGLBoolean (*eglStreamConsumerGLTextureExternalKHR_PTR)(EGLDisplay dpy, EGLStreamKHR stream);
typedef EGLBoolean (*eglStreamConsumerReleaseKHR_PTR)(EGLDisplay dpy, EGLStreamKHR stream);
typedef EGLBoolean (*eglLockSurfaceKHR_PTR)(EGLDisplay display, EGLSurface surface, const EGLint * attrib_list);
typedef EGLNativeFileDescriptorKHR (*eglGetStreamFileDescriptorKHR_PTR)(EGLDisplay dpy, EGLStreamKHR stream);
typedef EGLBoolean (*eglQueryStreamKHR_PTR)(EGLDisplay dpy, EGLStreamKHR stream, EGLenum attribute, EGLint * value);
typedef EGLBoolean (*eglQueryStreamTimeKHR_PTR)(EGLDisplay dpy, EGLStreamKHR stream, EGLenum attribute, EGLTimeKHR * value);
typedef EGLint (*eglWaitSyncKHR_PTR)(EGLDisplay dpy, EGLSyncKHR sync, EGLint flags);
typedef EGLSurface (*eglCreateStreamProducerSurfaceKHR_PTR)(EGLDisplay dpy, EGLConfig config, EGLStreamKHR stream, const EGLint * attrib_list);
#endif

#include "loader.h"
packed_call_t* glCopyPackedCall(const packed_call_t *packed);

#define checkError(code)                          \
    {int error; while ((error = glGetError())) {} \
    code                                          \
    if ((error = glGetError()))                   \
        printf(#code " -> %i\n", error);}

#define printError(file, line)              \
    {int error; if ((error = glGetError())) \
        printf(file ":%i -> %i\n", line, error);}

#define GL_TYPE_CASE(name, var, magic, type, code) \
    case magic: {                                  \
        type *name = (type *)var;                  \
        code                                       \
        break;                                     \
    }

#define GL_TYPE_CASE2(name, var, magic, type, code2, code) \
    case magic: {                                  \
        code2 {                                    \
          type *name = (type *)var;                \
          code                                     \
        }                                          \
        break;                                     \
    }

#define GL_TYPE_CASE_MAX(name, var, magic, type, code, max) \
    case magic: {                                  \
	    type *name = (type *)var;                  \
		type maxv = max;						   \
	    code                                       \
	    break;                                     \
    }
	
#define GL_TYPE_SWITCH(name, var, type, code, extra)               \
    switch (type) {                                                \
        GL_TYPE_CASE(name, var, GL_DOUBLE, GLdouble, code)         \
        GL_TYPE_CASE(name, var, GL_FLOAT, GLfloat, code)           \
        GL_TYPE_CASE(name, var, GL_INT, GLint, code)               \
        GL_TYPE_CASE(name, var, GL_SHORT, GLshort, code)           \
        GL_TYPE_CASE(name, var, GL_BYTE, GLbyte, code)   \
        GL_TYPE_CASE(name, var, GL_UNSIGNED_BYTE, GLubyte, code)   \
        GL_TYPE_CASE(name, var, GL_UNSIGNED_INT, GLuint, code)     \
        GL_TYPE_CASE(name, var, GL_UNSIGNED_SHORT, GLushort, code) \
        extra                                                      \
    }

#define GL_TYPE_SWITCH2(name, var, type, code2, code, extra)       \
    switch (type) {                                                \
        GL_TYPE_CASE2(name, var, GL_DOUBLE, GLdouble, code2, code) \
        GL_TYPE_CASE2(name, var, GL_FLOAT, GLfloat, code2, code)   \
        GL_TYPE_CASE2(name, var, GL_INT, GLint, code2, code)       \
        GL_TYPE_CASE2(name, var, GL_SHORT, GLshort, code2, code)   \
        GL_TYPE_CASE2(name, var, GL_BYTE, GLbyte, code2, code)     \
        GL_TYPE_CASE2(name, var, GL_UNSIGNED_BYTE, GLubyte, code2, code)   \
        GL_TYPE_CASE2(name, var, GL_UNSIGNED_INT, GLuint, code2, code)     \
        GL_TYPE_CASE2(name, var, GL_UNSIGNED_SHORT, GLushort, code2, code) \
        extra                                                      \
    }

#define GL_TYPE_SWITCH_MAX(name, var, type, code, extra)               \
    switch (type) {                                                \
	    GL_TYPE_CASE_MAX(name, var, GL_DOUBLE, GLdouble, code, 1.0d)         \
	    GL_TYPE_CASE_MAX(name, var, GL_FLOAT, GLfloat, code, 1.0f)           \
	    GL_TYPE_CASE_MAX(name, var, GL_INT, GLint, code, 2147483647l)               \
	    GL_TYPE_CASE_MAX(name, var, GL_SHORT, GLshort, code, 32767)           \
	    GL_TYPE_CASE_MAX(name, var, GL_BYTE, GLbyte, code, 255)   \
	    GL_TYPE_CASE_MAX(name, var, GL_UNSIGNED_BYTE, GLubyte, code, 127)   \
	    GL_TYPE_CASE_MAX(name, var, GL_UNSIGNED_INT, GLuint, code, 4294967295l)     \
	    GL_TYPE_CASE_MAX(name, var, GL_UNSIGNED_SHORT, GLushort, code, 65535) \
		extra                                                      \
    }
	
#define PUSH_IF_COMPILING_EXT(nam, ...)             \
    if ((glstate.list.compiling || glstate.gl_batch) && glstate.list.active) { \
		NewStage(glstate.list.active, STAGE_GLCALL);   \
        push_##nam(__VA_ARGS__);                    \
        noerrorShim();								\
        return (nam##_RETURN)0;                     \
    }

//printf("list:%i, " #nam "\n", state.list.name);
// cannot include "debug.h" as it include "gl.h"...
const char* PrintEnum(GLenum what);

#define PUSH_IF_COMPILING(name) PUSH_IF_COMPILING_EXT(name, name##_ARG_NAMES)

static const GLsizei gl_sizeof(GLenum type) {
    // types
    switch (type) {
        case GL_DOUBLE:
            return 8;
        case GL_FLOAT:
        case GL_INT:
        case GL_UNSIGNED_INT:
        case GL_UNSIGNED_INT_10_10_10_2:
        case GL_UNSIGNED_INT_2_10_10_10_REV:
        case GL_UNSIGNED_INT_8_8_8_8:
        case GL_UNSIGNED_INT_8_8_8_8_REV:
        case GL_4_BYTES:
            return 4;
        case GL_3_BYTES:
            return 3;
        case GL_LUMINANCE_ALPHA:
        case GL_SHORT:
        case GL_UNSIGNED_SHORT:
        case GL_UNSIGNED_SHORT_1_5_5_5_REV:
        case GL_UNSIGNED_SHORT_4_4_4_4:
        case GL_UNSIGNED_SHORT_4_4_4_4_REV:
        case GL_UNSIGNED_SHORT_5_5_5_1:
        case GL_UNSIGNED_SHORT_5_6_5:
        case GL_UNSIGNED_SHORT_5_6_5_REV:
        case GL_2_BYTES:
            return 2;
		case GL_ALPHA:
        case GL_LUMINANCE:
        case GL_BYTE:
        case GL_UNSIGNED_BYTE:
        case GL_UNSIGNED_BYTE_2_3_3_REV:
        case GL_UNSIGNED_BYTE_3_3_2:
            return 1;
    }
    // formats
    printf("libGL: Unsupported pixel data type: %s\n", PrintEnum(type));
    return 0;
}

static const GLuint gl_max_value(GLenum type) {
    switch (type) {
        // float/double only make sense on tex/color
        // be careful about using this
        case GL_DOUBLE:
        case GL_FLOAT:
            return 1;
        case GL_BYTE:           return 127;
        case GL_UNSIGNED_BYTE:  return 255;
        case GL_SHORT:          return 32767;
        case GL_UNSIGNED_SHORT: return 65535;
        case GL_INT:            return 2147483647;
        case GL_UNSIGNED_INT:   return 4294967295;
    }
    printf("libGL: unknown gl max value type: %s\n", PrintEnum(type));
    return 0;
}

static const GLboolean is_type_packed(GLenum type) {
    switch (type) {
        case GL_4_BYTES:
        case GL_3_BYTES:
        case GL_2_BYTES:
        case GL_UNSIGNED_BYTE_2_3_3_REV:
        case GL_UNSIGNED_BYTE_3_3_2:
        case GL_UNSIGNED_INT_10_10_10_2:
        case GL_UNSIGNED_INT_2_10_10_10_REV:
        case GL_UNSIGNED_INT_8_8_8_8:
        case GL_UNSIGNED_INT_8_8_8_8_REV:
        case GL_UNSIGNED_SHORT_1_5_5_5_REV:
        case GL_UNSIGNED_SHORT_4_4_4_4:
        case GL_UNSIGNED_SHORT_4_4_4_4_REV:
        case GL_UNSIGNED_SHORT_5_5_5_1:
        case GL_UNSIGNED_SHORT_5_6_5:
        case GL_UNSIGNED_SHORT_5_6_5_REV:
            return true;
    }
    return false;
}

static const GLsizei pixel_sizeof(GLenum format, GLenum type) {
    GLsizei width = 0;
    switch (format) {
        case GL_RED:
		case GL_ALPHA:
		case GL_LUMINANCE:
            width = 1;
            break;
        case GL_RG:
		case GL_LUMINANCE_ALPHA:
            width = 2;
            break;
        case GL_RGB:
        case GL_BGR:
        case GL_RGB8:
            width = 3;
            break;
        case GL_RGBA:
        case GL_BGRA:
        case GL_RGBA8:
            width = 4;
            break;
        default:
            printf("libGL: unsupported pixel format %s\n", PrintEnum(format));
            return 0;
    }

    if (is_type_packed(type))
        width = 1;

    return width * gl_sizeof(type);
}

static const GLboolean pixel_hasalpha(GLenum format) {
    switch (format) {
	case GL_ALPHA:
    case GL_LUMINANCE_ALPHA:
    case GL_RGBA:
    case GL_BGRA:
    case GL_RGBA8:
	    return true;
	case GL_RED:
	case GL_LUMINANCE:
    case GL_RG:
    case GL_RGB:
    case GL_BGR:
    case GL_RGB8:
	    return false;
        default:
            return true;
    }
}

static inline const GLboolean valid_vertex_type(GLenum type) {
    switch (type) {
        case GL_BYTE:
        case GL_FIXED:
        case GL_FLOAT:
        case GL_SHORT:
            return true;
        default:
            return false;
    }
}

#include "wrap/stub.h"
#include "wrap/gl.h"
#include "eval.h"
#include "light.h"
#include "line.h"
#include "list.h"
#include "pixel.h"
#include "raster.h"
#include "stack.h"
#include "texgen.h"
#include "texture.h"
#include "array.h"
#include "framebuffers.h"

const GLubyte *glshim_glGetString(GLenum name);
void glshim_glGetIntegerv(GLenum pname, GLint *params);
void glshim_glGetFloatv(GLenum pname, GLfloat *params);
void glshim_glEnable(GLenum cap);
void glshim_glDisable(GLenum cap);
void glshim_glEnableClientState(GLenum cap);
void glshim_glDisableClientState(GLenum cap);
GLboolean glshim_glIsEnabled(GLenum cap);
void glshim_glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
void glshim_glDrawArrays(GLenum mode, GLint first, GLsizei count);
void glshim_glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid *pointer);
void glshim_glBegin(GLenum mode);
void glshim_glEnd();
void glshim_glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz);
void glshim_glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glshim_glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
void glshim_glSecondaryColor3f(GLfloat r, GLfloat g, GLfloat b);
void glshim_glMaterialfv(GLenum face, GLenum pname, const GLfloat *params);
void glshim_glMaterialf(GLenum face, GLenum pname, const GLfloat param);
void glshim_glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void glshim_glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
void glshim_glArrayElement(GLint i);
void glshim_glLockArrays(GLint first, GLsizei count);
void glshim_glUnlockArrays();
GLuint glshim_glGenLists(GLsizei range);
void glshim_glNewList(GLuint list, GLenum mode);
void glshim_glEndList();
void glshim_glCallList(GLuint list);
void glshim_glCallLists(GLsizei n, GLenum type, const GLvoid *lists);
void glshim_glDeleteLists(GLuint list, GLsizei range);
void glshim_glListBase(GLuint base);
GLboolean glshim_glIsList(GLuint list);
void glshim_glPolygonMode(GLenum face, GLenum mode);
void glshim_glPushMatrix();
void glshim_glPopMatrix();
GLenum glshim_glGetError();

void glshim_glPointParameteri(GLenum pname, GLint param);
void glshim_glPointParameteriv(GLenum pname, const GLint * params);


void glshim_glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void glshim_glIndexPointer(GLenum type, GLsizei stride, const GLvoid * pointer);
void glshim_glEdgeFlagPointer(GLsizei stride, const GLvoid * pointer);
void glshim_glGetPointerv(GLenum pname, GLvoid* *params);
void glshim_glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
void glshim_glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
void glshim_glBlendEquationSeparate(GLenum modeRGB, GLenum modeA);
void glshim_glBlendFunc(GLenum sfactor, GLenum dfactor);
void glshim_glFlush();
void glshim_glFinish();
void glshim_glLoadMatrixf(const GLfloat * m);
void glshim_glMultMatrixf(const GLfloat * m);
void glshim_glFogfv(GLenum pname, const GLfloat* params);

void glshim_glStencilMaskSeparate(GLenum face, GLuint mask);

void glshim_glMultiDrawArrays(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
void glshim_glMultiDrawElements( GLenum mode, GLsizei *count, GLenum type, const void * const *indices, GLsizei primcount);


void flush();
void init_batch();

#include "state.h"
extern glstate_t glstate;

GLuint gl_batch; // 0 = off, 1 = on

static inline void errorGL() {	// next glGetError will be from GL 
	glstate.shim_error = 0;
}
static inline void errorShim(GLenum error) {	// next glGetError will be "error" from glShim
	glstate.shim_error = 1;
	glstate.last_error = error;
}
static inline void noerrorShim() {
	errorShim(GL_NO_ERROR);
}

#include "defines.h"

#include "render.h"

#endif
