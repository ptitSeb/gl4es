#include "gleswrap.h"

#ifndef skip_glActiveTexture
WRAP_GLES(void, glActiveTexture, GLenum texture)
    return gles_glActiveTexture(texture);
END_WRAP
#endif

#ifndef skip_glAlphaFunc
WRAP_GLES(void, glAlphaFunc, GLenum func, GLclampf ref)
    return gles_glAlphaFunc(func, ref);
END_WRAP
#endif

#ifndef skip_glAlphaFuncx
WRAP_GLES(void, glAlphaFuncx, GLenum func, GLclampx ref)
    return gles_glAlphaFuncx(func, ref);
END_WRAP
#endif

#ifndef skip_glBindBuffer
WRAP_GLES(void, glBindBuffer, GLenum target, GLuint buffer)
    return gles_glBindBuffer(target, buffer);
END_WRAP
#endif

#ifndef skip_glBindTexture
WRAP_GLES(void, glBindTexture, GLenum target, GLuint texture)
    return gles_glBindTexture(target, texture);
END_WRAP
#endif

#ifndef skip_glBlendFunc
WRAP_GLES(void, glBlendFunc, GLenum sfactor, GLenum dfactor)
    return gles_glBlendFunc(sfactor, dfactor);
END_WRAP
#endif

#ifndef skip_glBufferData
WRAP_GLES(void, glBufferData, GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage)
    return gles_glBufferData(target, size, data, usage);
END_WRAP
#endif

#ifndef skip_glBufferSubData
WRAP_GLES(void, glBufferSubData, GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data)
    return gles_glBufferSubData(target, offset, size, data);
END_WRAP
#endif

#ifndef skip_glClear
WRAP_GLES(void, glClear, GLbitfield mask)
    return gles_glClear(mask);
END_WRAP
#endif

#ifndef skip_glClearColor
WRAP_GLES(void, glClearColor, GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
    return gles_glClearColor(red, green, blue, alpha);
END_WRAP
#endif

#ifndef skip_glClearColorx
WRAP_GLES(void, glClearColorx, GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha)
    return gles_glClearColorx(red, green, blue, alpha);
END_WRAP
#endif

#ifndef skip_glClearDepthf
WRAP_GLES(void, glClearDepthf, GLclampf depth)
    return gles_glClearDepthf(depth);
END_WRAP
#endif

#ifndef skip_glClearDepthx
WRAP_GLES(void, glClearDepthx, GLclampx depth)
    return gles_glClearDepthx(depth);
END_WRAP
#endif

#ifndef skip_glClearStencil
WRAP_GLES(void, glClearStencil, GLint s)
    return gles_glClearStencil(s);
END_WRAP
#endif

#ifndef skip_glClientActiveTexture
WRAP_GLES(void, glClientActiveTexture, GLenum texture)
    return gles_glClientActiveTexture(texture);
END_WRAP
#endif

#ifndef skip_glClipPlanef
WRAP_GLES(void, glClipPlanef, GLenum plane, const GLfloat * equation)
    return gles_glClipPlanef(plane, equation);
END_WRAP
#endif

#ifndef skip_glClipPlanex
WRAP_GLES(void, glClipPlanex, GLenum plane, const GLfixed * equation)
    return gles_glClipPlanex(plane, equation);
END_WRAP
#endif

#ifndef skip_glColor4f
WRAP_GLES(void, glColor4f, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
    return gles_glColor4f(red, green, blue, alpha);
END_WRAP
#endif

#ifndef skip_glColor4ub
WRAP_GLES(void, glColor4ub, GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha)
    return gles_glColor4ub(red, green, blue, alpha);
END_WRAP
#endif

#ifndef skip_glColor4x
WRAP_GLES(void, glColor4x, GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha)
    return gles_glColor4x(red, green, blue, alpha);
END_WRAP
#endif

#ifndef skip_glColorMask
WRAP_GLES(void, glColorMask, GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
    return gles_glColorMask(red, green, blue, alpha);
END_WRAP
#endif

#ifndef skip_glColorPointer
WRAP_GLES(void, glColorPointer, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer)
    return gles_glColorPointer(size, type, stride, pointer);
END_WRAP
#endif

#ifndef skip_glCompressedTexImage2D
WRAP_GLES(void, glCompressedTexImage2D, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data)
    return gles_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
END_WRAP
#endif

#ifndef skip_glCompressedTexSubImage2D
WRAP_GLES(void, glCompressedTexSubImage2D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data)
    return gles_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
END_WRAP
#endif

#ifndef skip_glCopyTexImage2D
WRAP_GLES(void, glCopyTexImage2D, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
    return gles_glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
END_WRAP
#endif

#ifndef skip_glCopyTexSubImage2D
WRAP_GLES(void, glCopyTexSubImage2D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
    return gles_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
END_WRAP
#endif

#ifndef skip_glCullFace
WRAP_GLES(void, glCullFace, GLenum mode)
    return gles_glCullFace(mode);
END_WRAP
#endif

#ifndef skip_glDeleteBuffers
WRAP_GLES(void, glDeleteBuffers, GLsizei n, const GLuint * buffers)
    return gles_glDeleteBuffers(n, buffers);
END_WRAP
#endif

#ifndef skip_glDeleteTextures
WRAP_GLES(void, glDeleteTextures, GLsizei n, const GLuint * textures)
    return gles_glDeleteTextures(n, textures);
END_WRAP
#endif

#ifndef skip_glDepthFunc
WRAP_GLES(void, glDepthFunc, GLenum func)
    return gles_glDepthFunc(func);
END_WRAP
#endif

#ifndef skip_glDepthMask
WRAP_GLES(void, glDepthMask, GLboolean flag)
    return gles_glDepthMask(flag);
END_WRAP
#endif

#ifndef skip_glDepthRangef
WRAP_GLES(void, glDepthRangef, GLclampf near, GLclampf far)
    return gles_glDepthRangef(near, far);
END_WRAP
#endif

#ifndef skip_glDepthRangex
WRAP_GLES(void, glDepthRangex, GLclampx near, GLclampx far)
    return gles_glDepthRangex(near, far);
END_WRAP
#endif

#ifndef skip_glDisable
WRAP_GLES(void, glDisable, GLenum cap)
    return gles_glDisable(cap);
END_WRAP
#endif

#ifndef skip_glDisableClientState
WRAP_GLES(void, glDisableClientState, GLenum array)
    return gles_glDisableClientState(array);
END_WRAP
#endif

#ifndef skip_glDrawArrays
WRAP_GLES(void, glDrawArrays, GLenum mode, GLint first, GLsizei count)
    return gles_glDrawArrays(mode, first, count);
END_WRAP
#endif

#ifndef skip_glDrawElements
WRAP_GLES(void, glDrawElements, GLenum mode, GLsizei count, GLenum type, const GLvoid * indices)
    return gles_glDrawElements(mode, count, type, indices);
END_WRAP
#endif

#ifndef skip_glEnable
WRAP_GLES(void, glEnable, GLenum cap)
    return gles_glEnable(cap);
END_WRAP
#endif

#ifndef skip_glEnableClientState
WRAP_GLES(void, glEnableClientState, GLenum array)
    return gles_glEnableClientState(array);
END_WRAP
#endif

#ifndef skip_glFinish
WRAP_GLES(void, glFinish)
    return gles_glFinish();
END_WRAP
#endif

#ifndef skip_glFlush
WRAP_GLES(void, glFlush)
    return gles_glFlush();
END_WRAP
#endif

#ifndef skip_glFogf
WRAP_GLES(void, glFogf, GLenum pname, GLfloat param)
    return gles_glFogf(pname, param);
END_WRAP
#endif

#ifndef skip_glFogfv
WRAP_GLES(void, glFogfv, GLenum pname, const GLfloat * params)
    return gles_glFogfv(pname, params);
END_WRAP
#endif

#ifndef skip_glFogx
WRAP_GLES(void, glFogx, GLenum pname, GLfixed param)
    return gles_glFogx(pname, param);
END_WRAP
#endif

#ifndef skip_glFogxv
WRAP_GLES(void, glFogxv, GLenum pname, const GLfixed * params)
    return gles_glFogxv(pname, params);
END_WRAP
#endif

#ifndef skip_glFrontFace
WRAP_GLES(void, glFrontFace, GLenum mode)
    return gles_glFrontFace(mode);
END_WRAP
#endif

#ifndef skip_glFrustumf
WRAP_GLES(void, glFrustumf, GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far)
    return gles_glFrustumf(left, right, bottom, top, near, far);
END_WRAP
#endif

#ifndef skip_glFrustumx
WRAP_GLES(void, glFrustumx, GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far)
    return gles_glFrustumx(left, right, bottom, top, near, far);
END_WRAP
#endif

#ifndef skip_glGenBuffers
WRAP_GLES(void, glGenBuffers, GLsizei n, GLuint * buffers)
    return gles_glGenBuffers(n, buffers);
END_WRAP
#endif

#ifndef skip_glGenTextures
WRAP_GLES(void, glGenTextures, GLsizei n, GLuint * textures)
    return gles_glGenTextures(n, textures);
END_WRAP
#endif

#ifndef skip_glGetBooleanv
WRAP_GLES(void, glGetBooleanv, GLenum pname, GLboolean * params)
    return gles_glGetBooleanv(pname, params);
END_WRAP
#endif

#ifndef skip_glGetBufferParameteriv
WRAP_GLES(void, glGetBufferParameteriv, GLenum target, GLenum pname, GLint * params)
    return gles_glGetBufferParameteriv(target, pname, params);
END_WRAP
#endif

#ifndef skip_glGetClipPlanef
WRAP_GLES(void, glGetClipPlanef, GLenum plane, GLfloat * equation)
    return gles_glGetClipPlanef(plane, equation);
END_WRAP
#endif

#ifndef skip_glGetClipPlanex
WRAP_GLES(void, glGetClipPlanex, GLenum plane, GLfixed * equation)
    return gles_glGetClipPlanex(plane, equation);
END_WRAP
#endif

#ifndef skip_glGetError
WRAP_GLES(GLenum, glGetError)
    return gles_glGetError();
END_WRAP
#endif

#ifndef skip_glGetFixedv
WRAP_GLES(void, glGetFixedv, GLenum pname, GLfixed * params)
    return gles_glGetFixedv(pname, params);
END_WRAP
#endif

#ifndef skip_glGetFloatv
WRAP_GLES(void, glGetFloatv, GLenum pname, GLfloat * params)
    return gles_glGetFloatv(pname, params);
END_WRAP
#endif

#ifndef skip_glGetIntegerv
WRAP_GLES(void, glGetIntegerv, GLenum pname, GLint * params)
    return gles_glGetIntegerv(pname, params);
END_WRAP
#endif

#ifndef skip_glGetLightfv
WRAP_GLES(void, glGetLightfv, GLenum light, GLenum pname, GLfloat * params)
    return gles_glGetLightfv(light, pname, params);
END_WRAP
#endif

#ifndef skip_glGetLightxv
WRAP_GLES(void, glGetLightxv, GLenum light, GLenum pname, GLfixed * params)
    return gles_glGetLightxv(light, pname, params);
END_WRAP
#endif

#ifndef skip_glGetMaterialfv
WRAP_GLES(void, glGetMaterialfv, GLenum face, GLenum pname, GLfloat * params)
    return gles_glGetMaterialfv(face, pname, params);
END_WRAP
#endif

#ifndef skip_glGetMaterialxv
WRAP_GLES(void, glGetMaterialxv, GLenum face, GLenum pname, GLfixed * params)
    return gles_glGetMaterialxv(face, pname, params);
END_WRAP
#endif

#ifndef skip_glGetPointerv
WRAP_GLES(void, glGetPointerv, GLenum pname, GLvoid ** params)
    return gles_glGetPointerv(pname, params);
END_WRAP
#endif

#ifndef skip_glGetString
WRAP_GLES(const GLubyte *, glGetString, GLenum name)
    return gles_glGetString(name);
END_WRAP
#endif

#ifndef skip_glGetTexEnvfv
WRAP_GLES(void, glGetTexEnvfv, GLenum target, GLenum pname, GLfloat * params)
    return gles_glGetTexEnvfv(target, pname, params);
END_WRAP
#endif

#ifndef skip_glGetTexEnviv
WRAP_GLES(void, glGetTexEnviv, GLenum target, GLenum pname, GLint * params)
    return gles_glGetTexEnviv(target, pname, params);
END_WRAP
#endif

#ifndef skip_glGetTexEnvxv
WRAP_GLES(void, glGetTexEnvxv, GLenum target, GLenum pname, GLfixed * params)
    return gles_glGetTexEnvxv(target, pname, params);
END_WRAP
#endif

#ifndef skip_glGetTexParameterfv
WRAP_GLES(void, glGetTexParameterfv, GLenum target, GLenum pname, GLfloat * params)
    return gles_glGetTexParameterfv(target, pname, params);
END_WRAP
#endif

#ifndef skip_glGetTexParameteriv
WRAP_GLES(void, glGetTexParameteriv, GLenum target, GLenum pname, GLint * params)
    return gles_glGetTexParameteriv(target, pname, params);
END_WRAP
#endif

#ifndef skip_glGetTexParameterxv
WRAP_GLES(void, glGetTexParameterxv, GLenum target, GLenum pname, GLfixed * params)
    return gles_glGetTexParameterxv(target, pname, params);
END_WRAP
#endif

#ifndef skip_glHint
WRAP_GLES(void, glHint, GLenum target, GLenum mode)
    return gles_glHint(target, mode);
END_WRAP
#endif

#ifndef skip_glIsBuffer
WRAP_GLES(GLboolean, glIsBuffer, GLuint buffer)
    return gles_glIsBuffer(buffer);
END_WRAP
#endif

#ifndef skip_glIsEnabled
WRAP_GLES(GLboolean, glIsEnabled, GLenum cap)
    return gles_glIsEnabled(cap);
END_WRAP
#endif

#ifndef skip_glIsTexture
WRAP_GLES(GLboolean, glIsTexture, GLuint texture)
    return gles_glIsTexture(texture);
END_WRAP
#endif

#ifndef skip_glLightModelf
WRAP_GLES(void, glLightModelf, GLenum pname, GLfloat param)
    return gles_glLightModelf(pname, param);
END_WRAP
#endif

#ifndef skip_glLightModelfv
WRAP_GLES(void, glLightModelfv, GLenum pname, const GLfloat * params)
    return gles_glLightModelfv(pname, params);
END_WRAP
#endif

#ifndef skip_glLightModelx
WRAP_GLES(void, glLightModelx, GLenum pname, GLfixed param)
    return gles_glLightModelx(pname, param);
END_WRAP
#endif

#ifndef skip_glLightModelxv
WRAP_GLES(void, glLightModelxv, GLenum pname, const GLfixed * params)
    return gles_glLightModelxv(pname, params);
END_WRAP
#endif

#ifndef skip_glLightf
WRAP_GLES(void, glLightf, GLenum light, GLenum pname, GLfloat param)
    return gles_glLightf(light, pname, param);
END_WRAP
#endif

#ifndef skip_glLightfv
WRAP_GLES(void, glLightfv, GLenum light, GLenum pname, const GLfloat * params)
    return gles_glLightfv(light, pname, params);
END_WRAP
#endif

#ifndef skip_glLightx
WRAP_GLES(void, glLightx, GLenum light, GLenum pname, GLfixed param)
    return gles_glLightx(light, pname, param);
END_WRAP
#endif

#ifndef skip_glLightxv
WRAP_GLES(void, glLightxv, GLenum light, GLenum pname, const GLfixed * params)
    return gles_glLightxv(light, pname, params);
END_WRAP
#endif

#ifndef skip_glLineWidth
WRAP_GLES(void, glLineWidth, GLfloat width)
    return gles_glLineWidth(width);
END_WRAP
#endif

#ifndef skip_glLineWidthx
WRAP_GLES(void, glLineWidthx, GLfixed width)
    return gles_glLineWidthx(width);
END_WRAP
#endif

#ifndef skip_glLoadIdentity
WRAP_GLES(void, glLoadIdentity)
    return gles_glLoadIdentity();
END_WRAP
#endif

#ifndef skip_glLoadMatrixf
WRAP_GLES(void, glLoadMatrixf, const GLfloat * m)
    return gles_glLoadMatrixf(m);
END_WRAP
#endif

#ifndef skip_glLoadMatrixx
WRAP_GLES(void, glLoadMatrixx, const GLfixed * m)
    return gles_glLoadMatrixx(m);
END_WRAP
#endif

#ifndef skip_glLogicOp
WRAP_GLES(void, glLogicOp, GLenum opcode)
    return gles_glLogicOp(opcode);
END_WRAP
#endif

#ifndef skip_glMaterialf
WRAP_GLES(void, glMaterialf, GLenum face, GLenum pname, GLfloat param)
    return gles_glMaterialf(face, pname, param);
END_WRAP
#endif

#ifndef skip_glMaterialfv
WRAP_GLES(void, glMaterialfv, GLenum face, GLenum pname, const GLfloat * params)
    return gles_glMaterialfv(face, pname, params);
END_WRAP
#endif

#ifndef skip_glMaterialx
WRAP_GLES(void, glMaterialx, GLenum face, GLenum pname, GLfixed param)
    return gles_glMaterialx(face, pname, param);
END_WRAP
#endif

#ifndef skip_glMaterialxv
WRAP_GLES(void, glMaterialxv, GLenum face, GLenum pname, const GLfixed * params)
    return gles_glMaterialxv(face, pname, params);
END_WRAP
#endif

#ifndef skip_glMatrixMode
WRAP_GLES(void, glMatrixMode, GLenum mode)
    return gles_glMatrixMode(mode);
END_WRAP
#endif

#ifndef skip_glMultMatrixf
WRAP_GLES(void, glMultMatrixf, const GLfloat * m)
    return gles_glMultMatrixf(m);
END_WRAP
#endif

#ifndef skip_glMultMatrixx
WRAP_GLES(void, glMultMatrixx, const GLfixed * m)
    return gles_glMultMatrixx(m);
END_WRAP
#endif

#ifndef skip_glMultiTexCoord4f
WRAP_GLES(void, glMultiTexCoord4f, GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q)
    return gles_glMultiTexCoord4f(target, s, t, r, q);
END_WRAP
#endif

#ifndef skip_glMultiTexCoord4x
WRAP_GLES(void, glMultiTexCoord4x, GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q)
    return gles_glMultiTexCoord4x(target, s, t, r, q);
END_WRAP
#endif

#ifndef skip_glNormal3f
WRAP_GLES(void, glNormal3f, GLfloat nx, GLfloat ny, GLfloat nz)
    return gles_glNormal3f(nx, ny, nz);
END_WRAP
#endif

#ifndef skip_glNormal3x
WRAP_GLES(void, glNormal3x, GLfixed nx, GLfixed ny, GLfixed nz)
    return gles_glNormal3x(nx, ny, nz);
END_WRAP
#endif

#ifndef skip_glNormalPointer
WRAP_GLES(void, glNormalPointer, GLenum type, GLsizei stride, const GLvoid * pointer)
    return gles_glNormalPointer(type, stride, pointer);
END_WRAP
#endif

#ifndef skip_glOrthof
WRAP_GLES(void, glOrthof, GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far)
    return gles_glOrthof(left, right, bottom, top, near, far);
END_WRAP
#endif

#ifndef skip_glOrthox
WRAP_GLES(void, glOrthox, GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far)
    return gles_glOrthox(left, right, bottom, top, near, far);
END_WRAP
#endif

#ifndef skip_glPixelStorei
WRAP_GLES(void, glPixelStorei, GLenum pname, GLint param)
    return gles_glPixelStorei(pname, param);
END_WRAP
#endif

#ifndef skip_glPointParameterf
WRAP_GLES(void, glPointParameterf, GLenum pname, GLfloat param)
    return gles_glPointParameterf(pname, param);
END_WRAP
#endif

#ifndef skip_glPointParameterfv
WRAP_GLES(void, glPointParameterfv, GLenum pname, const GLfloat * params)
    return gles_glPointParameterfv(pname, params);
END_WRAP
#endif

#ifndef skip_glPointParameterx
WRAP_GLES(void, glPointParameterx, GLenum pname, GLfixed param)
    return gles_glPointParameterx(pname, param);
END_WRAP
#endif

#ifndef skip_glPointParameterxv
WRAP_GLES(void, glPointParameterxv, GLenum pname, const GLfixed * params)
    return gles_glPointParameterxv(pname, params);
END_WRAP
#endif

#ifndef skip_glPointSize
WRAP_GLES(void, glPointSize, GLfloat size)
    return gles_glPointSize(size);
END_WRAP
#endif

#ifndef skip_glPointSizePointerOES
WRAP_GLES(void, glPointSizePointerOES, GLenum type, GLsizei stride, const GLvoid * pointer)
    return gles_glPointSizePointerOES(type, stride, pointer);
END_WRAP
#endif

#ifndef skip_glPointSizex
WRAP_GLES(void, glPointSizex, GLfixed size)
    return gles_glPointSizex(size);
END_WRAP
#endif

#ifndef skip_glPolygonOffset
WRAP_GLES(void, glPolygonOffset, GLfloat factor, GLfloat units)
    return gles_glPolygonOffset(factor, units);
END_WRAP
#endif

#ifndef skip_glPolygonOffsetx
WRAP_GLES(void, glPolygonOffsetx, GLfixed factor, GLfixed units)
    return gles_glPolygonOffsetx(factor, units);
END_WRAP
#endif

#ifndef skip_glPopMatrix
WRAP_GLES(void, glPopMatrix)
    return gles_glPopMatrix();
END_WRAP
#endif

#ifndef skip_glPushMatrix
WRAP_GLES(void, glPushMatrix)
    return gles_glPushMatrix();
END_WRAP
#endif

#ifndef skip_glReadPixels
WRAP_GLES(void, glReadPixels, GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels)
    return gles_glReadPixels(x, y, width, height, format, type, pixels);
END_WRAP
#endif

#ifndef skip_glRotatef
WRAP_GLES(void, glRotatef, GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
    return gles_glRotatef(angle, x, y, z);
END_WRAP
#endif

#ifndef skip_glRotatex
WRAP_GLES(void, glRotatex, GLfixed angle, GLfixed x, GLfixed y, GLfixed z)
    return gles_glRotatex(angle, x, y, z);
END_WRAP
#endif

#ifndef skip_glSampleCoverage
WRAP_GLES(void, glSampleCoverage, GLclampf value, GLboolean invert)
    return gles_glSampleCoverage(value, invert);
END_WRAP
#endif

#ifndef skip_glSampleCoveragex
WRAP_GLES(void, glSampleCoveragex, GLclampx value, GLboolean invert)
    return gles_glSampleCoveragex(value, invert);
END_WRAP
#endif

#ifndef skip_glScalef
WRAP_GLES(void, glScalef, GLfloat x, GLfloat y, GLfloat z)
    return gles_glScalef(x, y, z);
END_WRAP
#endif

#ifndef skip_glScalex
WRAP_GLES(void, glScalex, GLfixed x, GLfixed y, GLfixed z)
    return gles_glScalex(x, y, z);
END_WRAP
#endif

#ifndef skip_glScissor
WRAP_GLES(void, glScissor, GLint x, GLint y, GLsizei width, GLsizei height)
    return gles_glScissor(x, y, width, height);
END_WRAP
#endif

#ifndef skip_glShadeModel
WRAP_GLES(void, glShadeModel, GLenum mode)
    return gles_glShadeModel(mode);
END_WRAP
#endif

#ifndef skip_glStencilFunc
WRAP_GLES(void, glStencilFunc, GLenum func, GLint ref, GLuint mask)
    return gles_glStencilFunc(func, ref, mask);
END_WRAP
#endif

#ifndef skip_glStencilMask
WRAP_GLES(void, glStencilMask, GLuint mask)
    return gles_glStencilMask(mask);
END_WRAP
#endif

#ifndef skip_glStencilOp
WRAP_GLES(void, glStencilOp, GLenum fail, GLenum zfail, GLenum zpass)
    return gles_glStencilOp(fail, zfail, zpass);
END_WRAP
#endif

#ifndef skip_glTexCoordPointer
WRAP_GLES(void, glTexCoordPointer, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer)
    return gles_glTexCoordPointer(size, type, stride, pointer);
END_WRAP
#endif

#ifndef skip_glTexEnvf
WRAP_GLES(void, glTexEnvf, GLenum target, GLenum pname, GLfloat param)
    return gles_glTexEnvf(target, pname, param);
END_WRAP
#endif

#ifndef skip_glTexEnvfv
WRAP_GLES(void, glTexEnvfv, GLenum target, GLenum pname, const GLfloat * params)
    return gles_glTexEnvfv(target, pname, params);
END_WRAP
#endif

#ifndef skip_glTexEnvi
WRAP_GLES(void, glTexEnvi, GLenum target, GLenum pname, GLint param)
    return gles_glTexEnvi(target, pname, param);
END_WRAP
#endif

#ifndef skip_glTexEnviv
WRAP_GLES(void, glTexEnviv, GLenum target, GLenum pname, const GLint * params)
    return gles_glTexEnviv(target, pname, params);
END_WRAP
#endif

#ifndef skip_glTexEnvx
WRAP_GLES(void, glTexEnvx, GLenum target, GLenum pname, GLfixed param)
    return gles_glTexEnvx(target, pname, param);
END_WRAP
#endif

#ifndef skip_glTexEnvxv
WRAP_GLES(void, glTexEnvxv, GLenum target, GLenum pname, const GLfixed * params)
    return gles_glTexEnvxv(target, pname, params);
END_WRAP
#endif

#ifndef skip_glTexImage2D
WRAP_GLES(void, glTexImage2D, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels)
    return gles_glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
END_WRAP
#endif

#ifndef skip_glTexParameterf
WRAP_GLES(void, glTexParameterf, GLenum target, GLenum pname, GLfloat param)
    return gles_glTexParameterf(target, pname, param);
END_WRAP
#endif

#ifndef skip_glTexParameterfv
WRAP_GLES(void, glTexParameterfv, GLenum target, GLenum pname, const GLfloat * params)
    return gles_glTexParameterfv(target, pname, params);
END_WRAP
#endif

#ifndef skip_glTexParameteri
WRAP_GLES(void, glTexParameteri, GLenum target, GLenum pname, GLint param)
    return gles_glTexParameteri(target, pname, param);
END_WRAP
#endif

#ifndef skip_glTexParameteriv
WRAP_GLES(void, glTexParameteriv, GLenum target, GLenum pname, const GLint * params)
    return gles_glTexParameteriv(target, pname, params);
END_WRAP
#endif

#ifndef skip_glTexParameterx
WRAP_GLES(void, glTexParameterx, GLenum target, GLenum pname, GLfixed param)
    return gles_glTexParameterx(target, pname, param);
END_WRAP
#endif

#ifndef skip_glTexParameterxv
WRAP_GLES(void, glTexParameterxv, GLenum target, GLenum pname, const GLfixed * params)
    return gles_glTexParameterxv(target, pname, params);
END_WRAP
#endif

#ifndef skip_glTexSubImage2D
WRAP_GLES(void, glTexSubImage2D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels)
    return gles_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
END_WRAP
#endif

#ifndef skip_glTranslatef
WRAP_GLES(void, glTranslatef, GLfloat x, GLfloat y, GLfloat z)
    return gles_glTranslatef(x, y, z);
END_WRAP
#endif

#ifndef skip_glTranslatex
WRAP_GLES(void, glTranslatex, GLfixed x, GLfixed y, GLfixed z)
    return gles_glTranslatex(x, y, z);
END_WRAP
#endif

#ifndef skip_glVertexPointer
WRAP_GLES(void, glVertexPointer, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer)
    return gles_glVertexPointer(size, type, stride, pointer);
END_WRAP
#endif

#ifndef skip_glViewport
WRAP_GLES(void, glViewport, GLint x, GLint y, GLsizei width, GLsizei height)
    return gles_glViewport(x, y, width, height);
END_WRAP
#endif
