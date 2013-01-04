#include "gleswrap.h"

#ifndef skip_glFlush
WRAP_GLES(void, glFlush)
    return glFlush();
END_WRAP
#endif

#ifndef skip_glClearColor
WRAP_GLES(void, glClearColor, GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
    return glClearColor(red, green, blue, alpha);
END_WRAP
#endif

#ifndef skip_glHint
WRAP_GLES(void, glHint, GLenum target, GLenum mode)
    return glHint(target, mode);
END_WRAP
#endif

#ifndef skip_glColor4ub
WRAP_GLES(void, glColor4ub, GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha)
    return glColor4ub(red, green, blue, alpha);
END_WRAP
#endif

#ifndef skip_glGetString
WRAP_GLES(const GLubyte *, glGetString, GLenum name)
    return glGetString(name);
END_WRAP
#endif

#ifndef skip_glLightx
WRAP_GLES(void, glLightx, GLenum light, GLenum pname, GLfixed param)
    return glLightx(light, pname, param);
END_WRAP
#endif

#ifndef skip_glGetTexParameterxv
WRAP_GLES(void, glGetTexParameterxv, GLenum target, GLenum pname, GLfixed * params)
    return glGetTexParameterxv(target, pname, params);
END_WRAP
#endif

#ifndef skip_glScalef
WRAP_GLES(void, glScalef, GLfloat x, GLfloat y, GLfloat z)
    return glScalef(x, y, z);
END_WRAP
#endif

#ifndef skip_glClearColorx
WRAP_GLES(void, glClearColorx, GLclampx red, GLclampx green, GLclampx blue, GLclampx alpha)
    return glClearColorx(red, green, blue, alpha);
END_WRAP
#endif

#ifndef skip_glLineWidth
WRAP_GLES(void, glLineWidth, GLfloat width)
    return glLineWidth(width);
END_WRAP
#endif

#ifndef skip_glScalex
WRAP_GLES(void, glScalex, GLfixed x, GLfixed y, GLfixed z)
    return glScalex(x, y, z);
END_WRAP
#endif

#ifndef skip_glLightf
WRAP_GLES(void, glLightf, GLenum light, GLenum pname, GLfloat param)
    return glLightf(light, pname, param);
END_WRAP
#endif

#ifndef skip_glDeleteTextures
WRAP_GLES(void, glDeleteTextures, GLsizei n, const GLuint * textures)
    return glDeleteTextures(n, textures);
END_WRAP
#endif

#ifndef skip_glClearDepthx
WRAP_GLES(void, glClearDepthx, GLclampx depth)
    return glClearDepthx(depth);
END_WRAP
#endif

#ifndef skip_glDepthRangef
WRAP_GLES(void, glDepthRangef, GLclampf near, GLclampf far)
    return glDepthRangef(near, far);
END_WRAP
#endif

#ifndef skip_glGetTexParameteriv
WRAP_GLES(void, glGetTexParameteriv, GLenum target, GLenum pname, GLint * params)
    return glGetTexParameteriv(target, pname, params);
END_WRAP
#endif

#ifndef skip_glClearStencil
WRAP_GLES(void, glClearStencil, GLint s)
    return glClearStencil(s);
END_WRAP
#endif

#ifndef skip_glSampleCoverage
WRAP_GLES(void, glSampleCoverage, GLclampf value, GLboolean invert)
    return glSampleCoverage(value, invert);
END_WRAP
#endif

#ifndef skip_glGenTextures
WRAP_GLES(void, glGenTextures, GLsizei n, GLuint * textures)
    return glGenTextures(n, textures);
END_WRAP
#endif

#ifndef skip_glDepthFunc
WRAP_GLES(void, glDepthFunc, GLenum func)
    return glDepthFunc(func);
END_WRAP
#endif

#ifndef skip_glCompressedTexSubImage2D
WRAP_GLES(void, glCompressedTexSubImage2D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid * data)
    return glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
END_WRAP
#endif

#ifndef skip_glMultiTexCoord4f
WRAP_GLES(void, glMultiTexCoord4f, GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q)
    return glMultiTexCoord4f(target, s, t, r, q);
END_WRAP
#endif

#ifndef skip_glGetTexParameterfv
WRAP_GLES(void, glGetTexParameterfv, GLenum target, GLenum pname, GLfloat * params)
    return glGetTexParameterfv(target, pname, params);
END_WRAP
#endif

#ifndef skip_glIsBuffer
WRAP_GLES(GLboolean, glIsBuffer, GLuint buffer)
    return glIsBuffer(buffer);
END_WRAP
#endif

#ifndef skip_glIsTexture
WRAP_GLES(GLboolean, glIsTexture, GLuint texture)
    return glIsTexture(texture);
END_WRAP
#endif

#ifndef skip_glCopyTexSubImage2D
WRAP_GLES(void, glCopyTexSubImage2D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
    return glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
END_WRAP
#endif

#ifndef skip_glCompressedTexImage2D
WRAP_GLES(void, glCompressedTexImage2D, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid * data)
    return glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
END_WRAP
#endif

#ifndef skip_glPointSizePointerOES
WRAP_GLES(void, glPointSizePointerOES, GLenum type, GLsizei stride, const GLvoid * pointer)
    return glPointSizePointerOES(type, stride, pointer);
END_WRAP
#endif

#ifndef skip_glDisable
WRAP_GLES(void, glDisable, GLenum cap)
    return glDisable(cap);
END_WRAP
#endif

#ifndef skip_glLogicOp
WRAP_GLES(void, glLogicOp, GLenum opcode)
    return glLogicOp(opcode);
END_WRAP
#endif

#ifndef skip_glColorMask
WRAP_GLES(void, glColorMask, GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
    return glColorMask(red, green, blue, alpha);
END_WRAP
#endif

#ifndef skip_glBindTexture
WRAP_GLES(void, glBindTexture, GLenum target, GLuint texture)
    return glBindTexture(target, texture);
END_WRAP
#endif

#ifndef skip_glMultiTexCoord4x
WRAP_GLES(void, glMultiTexCoord4x, GLenum target, GLfixed s, GLfixed t, GLfixed r, GLfixed q)
    return glMultiTexCoord4x(target, s, t, r, q);
END_WRAP
#endif

#ifndef skip_glGetTexEnvfv
WRAP_GLES(void, glGetTexEnvfv, GLenum target, GLenum pname, GLfloat * params)
    return glGetTexEnvfv(target, pname, params);
END_WRAP
#endif

#ifndef skip_glLineWidthx
WRAP_GLES(void, glLineWidthx, GLfixed width)
    return glLineWidthx(width);
END_WRAP
#endif

#ifndef skip_glCullFace
WRAP_GLES(void, glCullFace, GLenum mode)
    return glCullFace(mode);
END_WRAP
#endif

#ifndef skip_glGetLightfv
WRAP_GLES(void, glGetLightfv, GLenum light, GLenum pname, GLfloat * params)
    return glGetLightfv(light, pname, params);
END_WRAP
#endif

#ifndef skip_glColor4x
WRAP_GLES(void, glColor4x, GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha)
    return glColor4x(red, green, blue, alpha);
END_WRAP
#endif

#ifndef skip_glPointSize
WRAP_GLES(void, glPointSize, GLfloat size)
    return glPointSize(size);
END_WRAP
#endif

#ifndef skip_glDrawArrays
WRAP_GLES(void, glDrawArrays, GLenum mode, GLint first, GLsizei count)
    return glDrawArrays(mode, first, count);
END_WRAP
#endif

#ifndef skip_glViewport
WRAP_GLES(void, glViewport, GLint x, GLint y, GLsizei width, GLsizei height)
    return glViewport(x, y, width, height);
END_WRAP
#endif

#ifndef skip_glLoadIdentity
WRAP_GLES(void, glLoadIdentity)
    return glLoadIdentity();
END_WRAP
#endif

#ifndef skip_glTexEnvf
WRAP_GLES(void, glTexEnvf, GLenum target, GLenum pname, GLfloat param)
    return glTexEnvf(target, pname, param);
END_WRAP
#endif

#ifndef skip_glGetFixedv
WRAP_GLES(void, glGetFixedv, GLenum pname, GLfixed * params)
    return glGetFixedv(pname, params);
END_WRAP
#endif

#ifndef skip_glCopyTexImage2D
WRAP_GLES(void, glCopyTexImage2D, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
    return glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
END_WRAP
#endif

#ifndef skip_glEnableClientState
WRAP_GLES(void, glEnableClientState, GLenum array)
    return glEnableClientState(array);
END_WRAP
#endif

#ifndef skip_glGetBufferParameteriv
WRAP_GLES(void, glGetBufferParameteriv, GLenum target, GLenum pname, GLint * params)
    return glGetBufferParameteriv(target, pname, params);
END_WRAP
#endif

#ifndef skip_glDrawElements
WRAP_GLES(void, glDrawElements, GLenum mode, GLsizei count, GLenum type, const GLvoid * indices)
    return glDrawElements(mode, count, type, indices);
END_WRAP
#endif

#ifndef skip_glTexEnvi
WRAP_GLES(void, glTexEnvi, GLenum target, GLenum pname, GLint param)
    return glTexEnvi(target, pname, param);
END_WRAP
#endif

#ifndef skip_glClientActiveTexture
WRAP_GLES(void, glClientActiveTexture, GLenum texture)
    return glClientActiveTexture(texture);
END_WRAP
#endif

#ifndef skip_glBufferSubData
WRAP_GLES(void, glBufferSubData, GLenum target, GLintptr offset, GLsizeiptr size, const GLvoid * data)
    return glBufferSubData(target, offset, size, data);
END_WRAP
#endif

#ifndef skip_glMatrixMode
WRAP_GLES(void, glMatrixMode, GLenum mode)
    return glMatrixMode(mode);
END_WRAP
#endif

#ifndef skip_glSampleCoveragex
WRAP_GLES(void, glSampleCoveragex, GLclampx value, GLboolean invert)
    return glSampleCoveragex(value, invert);
END_WRAP
#endif

#ifndef skip_glGetLightxv
WRAP_GLES(void, glGetLightxv, GLenum light, GLenum pname, GLfixed * params)
    return glGetLightxv(light, pname, params);
END_WRAP
#endif

#ifndef skip_glNormalPointer
WRAP_GLES(void, glNormalPointer, GLenum type, GLsizei stride, const GLvoid * pointer)
    return glNormalPointer(type, stride, pointer);
END_WRAP
#endif

#ifndef skip_glGetMaterialxv
WRAP_GLES(void, glGetMaterialxv, GLenum face, GLenum pname, GLfixed * params)
    return glGetMaterialxv(face, pname, params);
END_WRAP
#endif

#ifndef skip_glPopMatrix
WRAP_GLES(void, glPopMatrix)
    return glPopMatrix();
END_WRAP
#endif

#ifndef skip_glFogx
WRAP_GLES(void, glFogx, GLenum pname, GLfixed param)
    return glFogx(pname, param);
END_WRAP
#endif

#ifndef skip_glPointSizex
WRAP_GLES(void, glPointSizex, GLfixed size)
    return glPointSizex(size);
END_WRAP
#endif

#ifndef skip_glClipPlanef
WRAP_GLES(void, glClipPlanef, GLenum plane, const GLfloat * equation)
    return glClipPlanef(plane, equation);
END_WRAP
#endif

#ifndef skip_glPointParameterf
WRAP_GLES(void, glPointParameterf, GLenum pname, GLfloat param)
    return glPointParameterf(pname, param);
END_WRAP
#endif

#ifndef skip_glPointParameterx
WRAP_GLES(void, glPointParameterx, GLenum pname, GLfixed param)
    return glPointParameterx(pname, param);
END_WRAP
#endif

#ifndef skip_glMaterialf
WRAP_GLES(void, glMaterialf, GLenum face, GLenum pname, GLfloat param)
    return glMaterialf(face, pname, param);
END_WRAP
#endif

#ifndef skip_glVertexPointer
WRAP_GLES(void, glVertexPointer, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer)
    return glVertexPointer(size, type, stride, pointer);
END_WRAP
#endif

#ifndef skip_glFogf
WRAP_GLES(void, glFogf, GLenum pname, GLfloat param)
    return glFogf(pname, param);
END_WRAP
#endif

#ifndef skip_glLightModelf
WRAP_GLES(void, glLightModelf, GLenum pname, GLfloat param)
    return glLightModelf(pname, param);
END_WRAP
#endif

#ifndef skip_glTexSubImage2D
WRAP_GLES(void, glTexSubImage2D, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid * pixels)
    return glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
END_WRAP
#endif

#ifndef skip_glRotatex
WRAP_GLES(void, glRotatex, GLfixed angle, GLfixed x, GLfixed y, GLfixed z)
    return glRotatex(angle, x, y, z);
END_WRAP
#endif

#ifndef skip_glClear
WRAP_GLES(void, glClear, GLbitfield mask)
    return glClear(mask);
END_WRAP
#endif

#ifndef skip_glActiveTexture
WRAP_GLES(void, glActiveTexture, GLenum texture)
    return glActiveTexture(texture);
END_WRAP
#endif

#ifndef skip_glTexEnvx
WRAP_GLES(void, glTexEnvx, GLenum target, GLenum pname, GLfixed param)
    return glTexEnvx(target, pname, param);
END_WRAP
#endif

#ifndef skip_glBindBuffer
WRAP_GLES(void, glBindBuffer, GLenum target, GLuint buffer)
    return glBindBuffer(target, buffer);
END_WRAP
#endif

#ifndef skip_glRotatef
WRAP_GLES(void, glRotatef, GLfloat angle, GLfloat x, GLfloat y, GLfloat z)
    return glRotatef(angle, x, y, z);
END_WRAP
#endif

#ifndef skip_glStencilOp
WRAP_GLES(void, glStencilOp, GLenum fail, GLenum zfail, GLenum zpass)
    return glStencilOp(fail, zfail, zpass);
END_WRAP
#endif

#ifndef skip_glReadPixels
WRAP_GLES(void, glReadPixels, GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * pixels)
    return glReadPixels(x, y, width, height, format, type, pixels);
END_WRAP
#endif

#ifndef skip_glLightModelx
WRAP_GLES(void, glLightModelx, GLenum pname, GLfixed param)
    return glLightModelx(pname, param);
END_WRAP
#endif

#ifndef skip_glGetTexEnvxv
WRAP_GLES(void, glGetTexEnvxv, GLenum target, GLenum pname, GLfixed * params)
    return glGetTexEnvxv(target, pname, params);
END_WRAP
#endif

#ifndef skip_glTranslatef
WRAP_GLES(void, glTranslatef, GLfloat x, GLfloat y, GLfloat z)
    return glTranslatef(x, y, z);
END_WRAP
#endif

#ifndef skip_glLoadMatrixx
WRAP_GLES(void, glLoadMatrixx, const GLfixed * m)
    return glLoadMatrixx(m);
END_WRAP
#endif

#ifndef skip_glBufferData
WRAP_GLES(void, glBufferData, GLenum target, GLsizeiptr size, const GLvoid * data, GLenum usage)
    return glBufferData(target, size, data, usage);
END_WRAP
#endif

#ifndef skip_glIsEnabled
WRAP_GLES(GLboolean, glIsEnabled, GLenum cap)
    return glIsEnabled(cap);
END_WRAP
#endif

#ifndef skip_glDisableClientState
WRAP_GLES(void, glDisableClientState, GLenum array)
    return glDisableClientState(array);
END_WRAP
#endif

#ifndef skip_glGetError
WRAP_GLES(GLenum, glGetError)
    return glGetError();
END_WRAP
#endif

#ifndef skip_glGetTexEnviv
WRAP_GLES(void, glGetTexEnviv, GLenum target, GLenum pname, GLint * params)
    return glGetTexEnviv(target, pname, params);
END_WRAP
#endif

#ifndef skip_glGetFloatv
WRAP_GLES(void, glGetFloatv, GLenum pname, GLfloat * params)
    return glGetFloatv(pname, params);
END_WRAP
#endif

#ifndef skip_glGetMaterialfv
WRAP_GLES(void, glGetMaterialfv, GLenum face, GLenum pname, GLfloat * params)
    return glGetMaterialfv(face, pname, params);
END_WRAP
#endif

#ifndef skip_glAlphaFunc
WRAP_GLES(void, glAlphaFunc, GLenum func, GLclampf ref)
    return glAlphaFunc(func, ref);
END_WRAP
#endif

#ifndef skip_glTranslatex
WRAP_GLES(void, glTranslatex, GLfixed x, GLfixed y, GLfixed z)
    return glTranslatex(x, y, z);
END_WRAP
#endif

#ifndef skip_glGetClipPlanex
WRAP_GLES(void, glGetClipPlanex, GLenum plane, GLfixed * equation)
    return glGetClipPlanex(plane, equation);
END_WRAP
#endif

#ifndef skip_glMaterialx
WRAP_GLES(void, glMaterialx, GLenum face, GLenum pname, GLfixed param)
    return glMaterialx(face, pname, param);
END_WRAP
#endif

#ifndef skip_glStencilFunc
WRAP_GLES(void, glStencilFunc, GLenum func, GLint ref, GLuint mask)
    return glStencilFunc(func, ref, mask);
END_WRAP
#endif

#ifndef skip_glGetIntegerv
WRAP_GLES(void, glGetIntegerv, GLenum pname, GLint * params)
    return glGetIntegerv(pname, params);
END_WRAP
#endif

#ifndef skip_glGetClipPlanef
WRAP_GLES(void, glGetClipPlanef, GLenum plane, GLfloat * equation)
    return glGetClipPlanef(plane, equation);
END_WRAP
#endif

#ifndef skip_glTexCoordPointer
WRAP_GLES(void, glTexCoordPointer, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer)
    return glTexCoordPointer(size, type, stride, pointer);
END_WRAP
#endif

#ifndef skip_glFrontFace
WRAP_GLES(void, glFrontFace, GLenum mode)
    return glFrontFace(mode);
END_WRAP
#endif

#ifndef skip_glLoadMatrixf
WRAP_GLES(void, glLoadMatrixf, const GLfloat * m)
    return glLoadMatrixf(m);
END_WRAP
#endif

#ifndef skip_glTexImage2D
WRAP_GLES(void, glTexImage2D, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid * pixels)
    return glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
END_WRAP
#endif

#ifndef skip_glFrustumx
WRAP_GLES(void, glFrustumx, GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far)
    return glFrustumx(left, right, bottom, top, near, far);
END_WRAP
#endif

#ifndef skip_glStencilMask
WRAP_GLES(void, glStencilMask, GLuint mask)
    return glStencilMask(mask);
END_WRAP
#endif

#ifndef skip_glOrthox
WRAP_GLES(void, glOrthox, GLfixed left, GLfixed right, GLfixed bottom, GLfixed top, GLfixed near, GLfixed far)
    return glOrthox(left, right, bottom, top, near, far);
END_WRAP
#endif

#ifndef skip_glMultMatrixf
WRAP_GLES(void, glMultMatrixf, const GLfloat * m)
    return glMultMatrixf(m);
END_WRAP
#endif

#ifndef skip_glMultMatrixx
WRAP_GLES(void, glMultMatrixx, const GLfixed * m)
    return glMultMatrixx(m);
END_WRAP
#endif

#ifndef skip_glClipPlanex
WRAP_GLES(void, glClipPlanex, GLenum plane, const GLfixed * equation)
    return glClipPlanex(plane, equation);
END_WRAP
#endif

#ifndef skip_glShadeModel
WRAP_GLES(void, glShadeModel, GLenum mode)
    return glShadeModel(mode);
END_WRAP
#endif

#ifndef skip_glOrthof
WRAP_GLES(void, glOrthof, GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far)
    return glOrthof(left, right, bottom, top, near, far);
END_WRAP
#endif

#ifndef skip_glFrustumf
WRAP_GLES(void, glFrustumf, GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat near, GLfloat far)
    return glFrustumf(left, right, bottom, top, near, far);
END_WRAP
#endif

#ifndef skip_glEnable
WRAP_GLES(void, glEnable, GLenum cap)
    return glEnable(cap);
END_WRAP
#endif

#ifndef skip_glNormal3x
WRAP_GLES(void, glNormal3x, GLfixed nx, GLfixed ny, GLfixed nz)
    return glNormal3x(nx, ny, nz);
END_WRAP
#endif

#ifndef skip_glGenBuffers
WRAP_GLES(void, glGenBuffers, GLsizei n, GLuint * buffers)
    return glGenBuffers(n, buffers);
END_WRAP
#endif

#ifndef skip_glFinish
WRAP_GLES(void, glFinish)
    return glFinish();
END_WRAP
#endif

#ifndef skip_glNormal3f
WRAP_GLES(void, glNormal3f, GLfloat nx, GLfloat ny, GLfloat nz)
    return glNormal3f(nx, ny, nz);
END_WRAP
#endif

#ifndef skip_glBlendFunc
WRAP_GLES(void, glBlendFunc, GLenum sfactor, GLenum dfactor)
    return glBlendFunc(sfactor, dfactor);
END_WRAP
#endif

#ifndef skip_glAlphaFuncx
WRAP_GLES(void, glAlphaFuncx, GLenum func, GLclampx ref)
    return glAlphaFuncx(func, ref);
END_WRAP
#endif

#ifndef skip_glDepthRangex
WRAP_GLES(void, glDepthRangex, GLclampx near, GLclampx far)
    return glDepthRangex(near, far);
END_WRAP
#endif

#ifndef skip_glGetPointerv
WRAP_GLES(void, glGetPointerv, GLenum pname, GLvoid ** params)
    return glGetPointerv(pname, params);
END_WRAP
#endif

#ifndef skip_glDepthMask
WRAP_GLES(void, glDepthMask, GLboolean flag)
    return glDepthMask(flag);
END_WRAP
#endif

#ifndef skip_glColor4f
WRAP_GLES(void, glColor4f, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
    return glColor4f(red, green, blue, alpha);
END_WRAP
#endif

#ifndef skip_glPolygonOffsetx
WRAP_GLES(void, glPolygonOffsetx, GLfixed factor, GLfixed units)
    return glPolygonOffsetx(factor, units);
END_WRAP
#endif

#ifndef skip_glTexParameterf
WRAP_GLES(void, glTexParameterf, GLenum target, GLenum pname, GLfloat param)
    return glTexParameterf(target, pname, param);
END_WRAP
#endif

#ifndef skip_glColorPointer
WRAP_GLES(void, glColorPointer, GLint size, GLenum type, GLsizei stride, const GLvoid * pointer)
    return glColorPointer(size, type, stride, pointer);
END_WRAP
#endif

#ifndef skip_glTexParameteri
WRAP_GLES(void, glTexParameteri, GLenum target, GLenum pname, GLint param)
    return glTexParameteri(target, pname, param);
END_WRAP
#endif

#ifndef skip_glPushMatrix
WRAP_GLES(void, glPushMatrix)
    return glPushMatrix();
END_WRAP
#endif

#ifndef skip_glClearDepthf
WRAP_GLES(void, glClearDepthf, GLclampf depth)
    return glClearDepthf(depth);
END_WRAP
#endif

#ifndef skip_glDeleteBuffers
WRAP_GLES(void, glDeleteBuffers, GLsizei n, const GLuint * buffers)
    return glDeleteBuffers(n, buffers);
END_WRAP
#endif

#ifndef skip_glScissor
WRAP_GLES(void, glScissor, GLint x, GLint y, GLsizei width, GLsizei height)
    return glScissor(x, y, width, height);
END_WRAP
#endif

#ifndef skip_glGetBooleanv
WRAP_GLES(void, glGetBooleanv, GLenum pname, GLboolean * params)
    return glGetBooleanv(pname, params);
END_WRAP
#endif

#ifndef skip_glPixelStorei
WRAP_GLES(void, glPixelStorei, GLenum pname, GLint param)
    return glPixelStorei(pname, param);
END_WRAP
#endif

#ifndef skip_glTexParameterx
WRAP_GLES(void, glTexParameterx, GLenum target, GLenum pname, GLfixed param)
    return glTexParameterx(target, pname, param);
END_WRAP
#endif

#ifndef skip_glPolygonOffset
WRAP_GLES(void, glPolygonOffset, GLfloat factor, GLfloat units)
    return glPolygonOffset(factor, units);
END_WRAP
#endif


