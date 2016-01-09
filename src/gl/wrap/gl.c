#include "gl.h"
#include "../debug.h"
//#include <limits.h>

#define constDoubleToFloat(a, size) \
    GLfloat s[size];                \
    int i;                          \
    for (i = 0; i < size; i++) {    \
        s[i] = a[i];                \
    }

// naive wrappers

#ifdef USE_ES2
void glshim_glCompileShader(GLuint shader) {
    glshim_glCompileShader(shader);
    GLint status;
    glshim_glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE) {
        GLint log_length;
        glshim_glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &log_length);
        GLchar *log = malloc(sizeof(GLchar) * log_length);
        glshim_glGetShaderInfoLog(shader, log_length, NULL, log);
        printf("Shader compile failed: %s\n", log);
        free(log);
    }
}
GLuint glshim_glCreateShaderObject(GLenum shaderType) {
    return glCreateShader(shaderType);
}
void glshim_glShaderSource(GLuint shader, GLsizei count, const GLchar **string, const GLint *length) {
    glshim_glShaderSource(shader, count, string, length);
}
void glshim_glGetObjectParameteriv(GLuint shader, GLenum pname, GLint *params) {
    glshim_glGetShaderiv(shader, pname, params);
}
#endif

void glshim_glClearDepth(GLdouble depth) {
    glshim_glClearDepthf(depth);
}
void glshim_glClipPlane(GLenum plane, const GLdouble *equation) {
    constDoubleToFloat(equation, 4);
    glshim_glClipPlanef(plane, s);
}
void glshim_glDepthRange(GLdouble nearVal, GLdouble farVal) {
    glshim_glDepthRangef(nearVal, farVal);
}
void glshim_glFogi(GLenum pname, GLint param) {
    glshim_glFogf(pname, param);
}
void glshim_glFogiv(GLenum pname, GLint *iparams) {
    switch (pname) {
        case GL_FOG_DENSITY:
        case GL_FOG_START:
        case GL_FOG_END:
        case GL_FOG_INDEX: {
            glshim_glFogf(pname, *iparams);
            break;
        }
        case GL_FOG_MODE:
        case GL_FOG_COLOR: {
            GLfloat params[4];
            for (int i = 0; i < 4; i++) {
                params[i] = iparams[i];
            }
            glshim_glFogfv(pname, params);
            break;
        }
    }
}
void glshim_glGetTexGendv(GLenum coord,GLenum pname,GLdouble *params) {
	GLfloat fparams[4];
	glshim_glGetTexGenfv(coord, pname, fparams);
	if (pname==GL_TEXTURE_GEN_MODE) *params=fparams[0];
	else for (int i=0; i<4; i++) params[i]=fparams[i];
}
void glshim_glGetTexGeniv(GLenum coord,GLenum pname,GLint *params) {
	GLfloat fparams[4];
	glshim_glGetTexGenfv(coord, pname, fparams);
	if (pname==GL_TEXTURE_GEN_MODE) *params=fparams[0];
	else for (int i=0; i<4; i++) params[i]=fparams[i];
}
void glshim_glGetMaterialiv(GLenum face, GLenum pname, GLint * params) {
	GLfloat fparams[4];
	glshim_glGetMaterialfv(face, pname, fparams);
	if (pname==GL_SHININESS) *params=fparams[0];
	else for (int i=0; i<4; i++) params[i]=fparams[i];
}
void glshim_glGetLightiv(GLenum light, GLenum pname, GLint * params) {
	GLfloat fparams[4];
	glshim_glGetLightfv(light, pname, fparams);
	int n=4;
	if (pname==GL_SPOT_EXPONENT) n=1;
	if (pname==GL_SPOT_CUTOFF) n=1;
	if (pname==GL_SPOT_EXPONENT) n=1;
	if (pname==GL_SPOT_DIRECTION) n=3;
	else for (int i=0; i<n; i++) params[i]=fparams[i];
}
void glshim_glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params) {
	GLint iparams;
	glshim_glGetTexLevelParameteriv(target, level, pname, &iparams);
	(*params)=iparams;
	return;
}
void glshim_glGetClipPlane(GLenum plane, GLdouble *equation) {
	GLfloat fparams[4];
	glshim_glGetClipPlanef(plane, fparams);
	for (int i=0; i<4; i++) equation[i]=fparams[i];
}

void glshim_glFrustum(GLdouble left, GLdouble right, GLdouble bottom,
             GLdouble top, GLdouble near, GLdouble far) {
    glshim_glFrustumf(left, right, bottom, top, near, far);
}
void glshim_glPixelStoref(GLenum pname, GLfloat param) {
    glshim_glPixelStorei(pname, param);
}
void glshim_glLighti(GLenum light, GLenum pname, GLint param) {
    glshim_glLightf(light, pname, param);
}
void glshim_glPixelTransferi(GLenum pname, GLint param) {
	glshim_glPixelTransferf(pname, param);	
}

void glshim_glLightiv(GLenum light, GLenum pname, GLint *iparams) {
    switch (pname) {
        case GL_AMBIENT:
        case GL_DIFFUSE:
        case GL_SPECULAR:
        case GL_POSITION: {
            GLfloat params[4];
            for (int i = 0; i < 4; i++) {
                params[i] = iparams[i];
            }
            glshim_glLightfv(light, pname, params);
            break;
        }
        case GL_SPOT_DIRECTION: {
            GLfloat params[4];
            for (int i = 0; i < 4; i++) {
                params[i] = iparams[i];
            }
            glshim_glLightfv(light, pname, params);
            break;
        }
        case GL_SPOT_EXPONENT:
        case GL_SPOT_CUTOFF:
        case GL_CONSTANT_ATTENUATION:
        case GL_LINEAR_ATTENUATION:
        case GL_QUADRATIC_ATTENUATION: {
            glshim_glLightf(light, pname, *iparams);
            break;
        }
    }
}
#ifndef USE_ES2
void glshim_glLightModeli(GLenum pname, GLint param) {
    glshim_glLightModelf(pname, param);
}
void glshim_glLightModeliv(GLenum pname, GLint *iparams) {
    switch (pname) {
        case GL_LIGHT_MODEL_AMBIENT: {
            GLfloat params[4];
            for (int i = 0; i < 4; i++) {
                params[i] = iparams[i];
            }
            glshim_glLightModelfv(pname, params);
            break;
        }
        case GL_LIGHT_MODEL_LOCAL_VIEWER:
        case GL_LIGHT_MODEL_TWO_SIDE: {
            glshim_glLightModelf(pname, *iparams);
            break;
        }
    }
}
#endif
void glshim_glMateriali(GLenum face, GLenum pname, GLint param) {
    glshim_glMaterialf(face, pname, param);
}
void glshim_glMaterialiv(GLenum face, GLenum pname, GLint *iparams) {
printf("glMaterialiv(%04X, %04X, [%i,...]\n", face, pname, iparams[0]);
    switch (pname) {
        case GL_AMBIENT: 
		case GL_DIFFUSE:
		case GL_SPECULAR:
		case GL_EMISSION:
		{
            GLfloat params[4];
            for (int i = 0; i < 4; i++) {
                params[i] = iparams[i];	// should divide by MAX_INT
            }
            glshim_glMaterialfv(face, pname, params);
            break;
        }
		case GL_SHININESS:
		{
            GLfloat params[2];
            for (int i = 0; i < 2; i++) {
                params[i] = iparams[i];
            }
            glshim_glMaterialfv(face, pname, params);
            break;
        }
        case GL_AMBIENT_AND_DIFFUSE: {
            glshim_glMaterialf(face, pname, *iparams);
            break;
        }
		case GL_COLOR_INDEXES:
		{
            GLfloat params[3];
            for (int i = 0; i < 3; i++) {
                params[i] = iparams[i];
            }
            glshim_glMaterialfv(face, pname, params);
            break;
        }
    }
}

/*
void glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) {
    glMultiTexCoord4f(target, s, t, 0.0f, 1.0f);
}
* */
void glshim_glMultiTexCoord1f(GLenum target, GLfloat s) {
     glshim_glMultiTexCoord4f(target, s, 0, 0, 1);
}
void glshim_glMultiTexCoord1fv(GLenum target, GLfloat *t) {
     glshim_glMultiTexCoord4f(target, t[0], 0, 0, 1);
}
void glshim_glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) {
     glshim_glMultiTexCoord4f(target, s, t, 0, 1);
}
void glshim_glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r) {
     glshim_glMultiTexCoord4f(target, s, t, r, 1);
}
/*void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
     glMultiTexCoord2f(target, s, t);
}*/
void glshim_glMultiTexCoord2fv(GLenum target, GLfloat *t) {
     glshim_glMultiTexCoord4f(target, t[0], t[1], 0, 1);
}
void glshim_glMultiTexCoord3fv(GLenum target, GLfloat *t) {
     glshim_glMultiTexCoord4f(target, t[0], t[1], t[2], 1);
}
void glshim_glMultiTexCoord4fv(GLenum target, GLfloat *t) {
     glshim_glMultiTexCoord4f(target, t[0], t[1], t[2], t[3]);
}
/*
void glBlendFuncSeparateEXT (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
	glBlendFuncSeparate (sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
*/
void glshim_glOrtho(GLdouble left, GLdouble right, GLdouble bottom,
             GLdouble top, GLdouble near, GLdouble far) {
    glshim_glOrthof(left, right, bottom, top, near, far);
}

// OES wrappers

void glClearDepthfOES(GLfloat depth) {
    glshim_glClearDepthf(depth);
}
void glClipPlanefOES(GLenum plane, const GLfloat *equation) {
    glshim_glClipPlanef(plane, equation);
}
void glDepthRangefOES(GLclampf near, GLclampf far) {
    glshim_glDepthRangef(near, far);
}
void glFrustumfOES(GLfloat left, GLfloat right, GLfloat bottom,
                   GLfloat top, GLfloat near, GLfloat far) {
    glshim_glFrustumf(left, right, bottom, top, near, far);
}
void glGetClipPlanefOES(GLenum pname, GLfloat equation[4]) {
    glshim_glGetClipPlanef(pname, equation);
}
void glOrthofOES(GLfloat left, GLfloat right, GLfloat bottom,
                 GLfloat top, GLfloat near, GLfloat far) {
    glshim_glOrthof(left, right, bottom, top, near, far);
}

// glRect

#define GL_RECT(suffix, type)                                 \
    void glshim_glRect##suffix(type x1, type y1, type x2, type y2) { \
        glshim_glBegin(GL_POLYGON);                                  \
        glshim_glVertex2##suffix(x1, y1);                            \
        glshim_glVertex2##suffix(x2, y1);                            \
        glshim_glVertex2##suffix(x2, y2);                            \
        glshim_glVertex2##suffix(x1, y2);                            \
		glshim_glEnd();											  \
    }                                                         \
    void glshim_glRect##suffix##v(const type *v) {                   \
        glshim_glRect##suffix(v[0], v[1], v[2], v[3]);               \
    }

GL_RECT(d, GLdouble)
GL_RECT(f, GLfloat)
GL_RECT(i, GLint)
GL_RECT(s, GLshort)
#undef GL_RECT

// basic thunking

#define THUNK(suffix, type, max)                            \
/* colors */                                                \
void glshim_glColor3##suffix(type r, type g, type b) {             \
    glshim_glColor4f(r/max, g/max, b/max, 1.0f);                   \
}                                                           \
void glshim_glColor4##suffix(type r, type g, type b, type a) {     \
    glshim_glColor4f(r/max, g/max, b/max, a/max);                  \
}                                                           \
void glshim_glColor3##suffix##v(const type *v) {                   \
    glshim_glColor4f(v[0]/max, v[1]/max, v[2]/max, 1.0f);          \
}                                                           \
void glshim_glColor4##suffix##v(const type *v) {                   \
    glshim_glColor4f(v[0]/max, v[1]/max, v[2]/max, v[3]/max);      \
}                                                           \
void glshim_glSecondaryColor3##suffix(type r, type g, type b) {    \
    glshim_glSecondaryColor3f(r/max, g/max, b/max);                \
}                                                           \
void glshim_glSecondaryColor3##suffix##v(const type *v) {          \
    glshim_glSecondaryColor3f(v[0]/max, v[1]/max, v[2]/max);       \
}                                                           \
/* index */                                                 \
void glshim_glIndex##suffix(type c) {                              \
    glshim_glIndexf(c);                                            \
}                                                           \
void glshim_glIndex##suffix##v(const type *c) {                    \
    glshim_glIndexf(c[0]);                                         \
}                                                           \
/* normal */                                                \
void glshim_glNormal3##suffix(type x, type y, type z) {            \
    glshim_glNormal3f(x, y, z);                                    \
}                                                           \
void glshim_glNormal3##suffix##v(const type *v) {                  \
    glshim_glNormal3f(v[0], v[1], v[2]);                           \
}                                                           \
/* raster */                                                \
void glshim_glRasterPos2##suffix(type x, type y) {                 \
    glshim_glRasterPos3f(x, y, 0);                                 \
}                                                           \
void glshim_glRasterPos2##suffix##v(type *v) {                     \
    glshim_glRasterPos3f(v[0], v[1], 0);                           \
}                                                           \
void glshim_glRasterPos3##suffix(type x, type y, type z) {         \
    glshim_glRasterPos3f(x, y, z);                                 \
}                                                           \
void glshim_glRasterPos3##suffix##v(type *v) {                     \
    glshim_glRasterPos3f(v[0], v[1], v[2]);                        \
}                                                           \
void glshim_glRasterPos4##suffix(type x, type y, type z, type w) { \
    glshim_glRasterPos4f(x, y, z, w);                              \
}                                                           \
void glshim_glRasterPos4##suffix##v(type *v) {                     \
    glshim_glRasterPos4f(v[0], v[1], v[2], v[3]);                  \
}                                                           \
void glshim_glWindowPos2##suffix(type x, type y) {                 \
    glshim_glWindowPos3f(x, y, 0);                                 \
}                                                           \
void glshim_glWindowPos2##suffix##v(type *v) {                     \
    glshim_glWindowPos3f(v[0], v[1], 0);                           \
}                                                           \
void glshim_glWindowPos3##suffix(type x, type y, type z) {         \
    glshim_glWindowPos3f(x, y, z);                                 \
}                                                           \
void glshim_glWindowPos3##suffix##v(type *v) {                     \
    glshim_glWindowPos3f(v[0], v[1], v[2]);                        \
}                                                           \
/* vertex */                                                \
void glshim_glVertex2##suffix(type x, type y) {                    \
    glshim_glVertex4f(x, y, 0, 1);                                 \
}                                                           \
void glshim_glVertex2##suffix##v(type *v) {                        \
    glshim_glVertex4f(v[0], v[1], 0 ,1);                           \
}                                                           \
void glshim_glVertex3##suffix(type x, type y, type z) {            \
    glshim_glVertex4f(x, y, z, 1);                                 \
}                                                           \
void glshim_glVertex3##suffix##v(type *v) {                        \
    glshim_glVertex4f(v[0], v[1], v[2], 1);                        \
}                                                           \
void glshim_glVertex4##suffix(type r, type g, type b, type w) {    \
    glshim_glVertex4f(r, g, b, w);                                 \
}                                                           \
void glshim_glVertex4##suffix##v(type *v) {                        \
    glshim_glVertex4f(v[0], v[1], v[2], v[3]);                     \
}                                                           \
/* texture */                                               \
void glshim_glTexCoord1##suffix(type s) {                          \
    glshim_glTexCoord4f(s, 0, 0, 1);                               \
}                                                           \
void glshim_glTexCoord1##suffix##v(type *t) {                      \
    glshim_glTexCoord4f(t[0], 0, 0, 1);                            \
}                                                           \
void glshim_glTexCoord2##suffix(type s, type t) {                  \
    glshim_glTexCoord4f(s, t, 0, 1);                               \
}                                                           \
void glshim_glTexCoord2##suffix##v(type *t) {                      \
    glshim_glTexCoord4f(t[0], t[1], 0, 1);                         \
}                                                           \
void glshim_glTexCoord3##suffix(type s, type t, type r) {          \
    glshim_glTexCoord4f(s, t, r, 1);                               \
}                                                           \
void glshim_glTexCoord3##suffix##v(type *t) {                      \
    glshim_glTexCoord4f(t[0], t[1], t[2], 1);                      \
}                                                           \
void glshim_glTexCoord4##suffix(type s, type t, type r, type q) {  \
    glshim_glTexCoord4f(s, t, r, q);                               \
}                                                           \
void glshim_glTexCoord4##suffix##v(type *t) {                      \
    glshim_glTexCoord4f(t[0], t[1], t[2], t[3]);                    \
}															\
/* multi-texture */                                         \
void glshim_glMultiTexCoord1##suffix(GLenum target, type s) {      \
    glshim_glMultiTexCoord4f(target, s, 0, 0, 1);                        \
}                                                           \
void glshim_glMultiTexCoord1##suffix##v(GLenum target, type *t) {  \
    glshim_glMultiTexCoord4f(target, t[0], 0, 0, 1);                    \
}                                                           \
void glshim_glMultiTexCoord2##suffix(GLenum target, type s, type t) {           \
    glshim_glMultiTexCoord4f(target, s, t, 0, 1);                               \
}                                                                        \
void glshim_glMultiTexCoord2##suffix##v(GLenum target, type *t) {               \
    glshim_glMultiTexCoord4f(target, t[0], t[1], 0, 1);                         \
}                                                                        \
void glshim_glMultiTexCoord3##suffix(GLenum target, type s, type t, type r) {   \
    glshim_glMultiTexCoord4f(target, s, t, r, 1);                               \
}                                                                        \
void glshim_glMultiTexCoord3##suffix##v(GLenum target, type *t) {               \
    glshim_glMultiTexCoord4f(target, t[0], t[1], t[2], 1);                      \
}                                                                        \
void glshim_glMultiTexCoord4##suffix(GLenum target, type s, type t, type r, type q) {  \
    glshim_glMultiTexCoord4f(target, s, t, r, q);                               \
}                                                                        \
void glshim_glMultiTexCoord4##suffix##v(GLenum target, type *t) {               \
    glshim_glMultiTexCoord4f(target, t[0], t[1], t[2], t[3]);                   \
}


THUNK(b, GLbyte, (float)CHAR_MAX)
THUNK(d, GLdouble, 1.0f)
THUNK(i, GLint, (float)INT_MAX)
THUNK(s, GLshort, (float)SHRT_MAX)
THUNK(ub, GLubyte, (float)UCHAR_MAX)
THUNK(ui, GLuint, (float)UINT_MAX)
THUNK(us, GLushort, (float)USHRT_MAX)

#undef THUNK

// glGet

#define THUNK(suffix, type)                              \
void glshim_glGet##suffix##v(GLenum pname, type *params) {      \
    int i, n = 1;                                        \
    switch (pname) {                                     \
        /* two values */                                 \
        case GL_ALIASED_POINT_SIZE_RANGE:                \
        case GL_ALIASED_LINE_WIDTH_RANGE:                \
        case GL_MAX_VIEWPORT_DIMS:                       \
            n = 2;                                       \
            break;                                       \
        /* three values */                               \
        case GL_CURRENT_NORMAL:                          \
        case GL_POINT_DISTANCE_ATTENUATION:              \
            n = 3;                                       \
            break;                                       \
        /* four values */                                \
        case GL_COLOR_CLEAR_VALUE:                       \
        case GL_COLOR_WRITEMASK:                         \
        case GL_CURRENT_COLOR:                           \
        case GL_CURRENT_TEXTURE_COORDS:                  \
        case GL_DEPTH_RANGE:                             \
        case GL_FOG_COLOR:                               \
        case GL_LIGHT_MODEL_AMBIENT:                     \
        case GL_SCISSOR_BOX:                             \
        case GL_SMOOTH_LINE_WIDTH_RANGE:                 \
        case GL_SMOOTH_POINT_SIZE_RANGE:                 \
        case GL_VIEWPORT:                                \
            n = 4;                                       \
            break;                                       \
        /* GL_NUM_COMPRESSED_TEXTURE_FORMATS values */   \
        case GL_COMPRESSED_TEXTURE_FORMATS:              \
            n = GL_NUM_COMPRESSED_TEXTURE_FORMATS;       \
            break;                                       \
        /* sixteen values */                             \
        case GL_MODELVIEW_MATRIX:                        \
        case GL_PROJECTION_MATRIX:                       \
        case GL_TEXTURE_MATRIX:                          \
            n = 16;                                      \
            break;                                       \
    }                                                    \
    GLfloat *p = (GLfloat *)malloc(sizeof(GLfloat) * n); \
    glshim_glGetFloatv(pname, p);		                         \
    for (i = 0; i < n; i++) {                            \
        params[i] = (type)p[i];                          \
    }                                                    \
    free(p);                                             \
}

THUNK(Double, GLdouble)
//THUNK(Integer, GLint)
//THUNK(Float, GLfloat)

#undef THUNK

// manually defined float wrappers, because we don't autowrap float functions

// color
void glshim_glColor3f(GLfloat r, GLfloat g, GLfloat b) {
    glshim_glColor4f(r, g, b, 1.0f);
}
void glshim_glColor3fv(GLfloat *c) {
    glshim_glColor4f(c[0], c[1], c[2], 1.0f);
}
void glshim_glColor4fv(GLfloat *c) {
    glshim_glColor4f(c[0], c[1], c[2], c[3]);
}
void glshim_glIndexfv(const GLfloat *c) {
    glshim_glIndexf(*c);
}
void glshim_glSecondaryColor3fv(const GLfloat *v) {
    glshim_glSecondaryColor3f(v[0], v[1], v[2]);
}

// raster
void glshim_glRasterPos2f(GLfloat x, GLfloat y) {
    glshim_glRasterPos3f(x, y, 0.0f);
}
void glshim_glRasterPos2fv(const GLfloat *v) {
    glshim_glRasterPos3f(v[0], v[1], 0.0f);
}
void glshim_glRasterPos3fv(const GLfloat *v) {
    glshim_glRasterPos3f(v[0], v[1], v[2]);
}
void glshim_glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    glshim_glRasterPos3f(x/w, y/w, z/w);
}
void glshim_glRasterPos4fv(const GLfloat *v) {
    glshim_glRasterPos4f(v[0], v[1], v[2], v[3]);
}
void glshim_glWindowPos2f(GLfloat x, GLfloat y) {
    glshim_glWindowPos3f(x, y, 0.0f);
}
void glshim_glWindowPos2fv(const GLfloat *v) {
    glshim_glWindowPos3f(v[0], v[1], 0.0f);
}
void glshim_glWindowPos3fv(const GLfloat *v) {
    glshim_glWindowPos3f(v[0], v[1], v[2]);
}

// eval
void glshim_glEvalCoord1d(GLdouble u) {
    glshim_glEvalCoord1f(u);
}

void glshim_glEvalCoord2d(GLdouble u, GLdouble v) {
    glshim_glEvalCoord2f(u, v);
}

void glshim_glEvalCoord1fv(GLfloat *v) {
    glshim_glEvalCoord1f(v[0]);
}

void glshim_glEvalCoord1dv(GLdouble *v) {
    glshim_glEvalCoord1d(v[0]);
}

void glshim_glEvalCoord2fv(GLfloat *v) {
    glshim_glEvalCoord2f(v[0], v[1]);
}

void glshim_glEvalCoord2dv(GLdouble *v) {
    glshim_glEvalCoord2d(v[0], v[1]);
}

void glshim_glMapGrid1d(GLint un, GLdouble u1, GLdouble u2) {
    glshim_glMapGrid1f(un, u1, u2);
}

void glshim_glMapGrid2d(GLint un, GLdouble u1, GLdouble u2,
                 GLint vn, GLdouble v1, GLdouble v2) {
    glshim_glMapGrid2f(un, u1, u2, vn, v1, v2);
}

// matrix
void glshim_glLoadMatrixd(const GLdouble *m) {
    constDoubleToFloat(m, 16);
    glshim_glLoadMatrixf(s);
}
void glshim_glMultMatrixd(const GLdouble *m) {
    constDoubleToFloat(m, 16);
    glshim_glMultMatrixf(s);
}

// normal
void glshim_glNormal3fv(GLfloat *v) {
    glshim_glNormal3f(v[0], v[1], v[2]);
}

// textures
void glshim_glTexCoord1f(GLfloat s) {
    glshim_glTexCoord4f(s, 0, 0, 1);
}
void glshim_glTexCoord1fv(GLfloat *t) {
    glshim_glTexCoord4f(t[0], 0, 0, 1);
}
void glshim_glTexCoord2f(GLfloat s, GLfloat t) {
    glshim_glTexCoord4f(s, t, 0, 1);
}
void glshim_glTexCoord2fv(GLfloat *t) {
    glshim_glTexCoord4f(t[0], t[1], 0, 1);
}
void glshim_glTexCoord3f(GLfloat s, GLfloat t, GLfloat r) {
    glshim_glTexCoord4f(s, t, r, 1);
}
void glshim_glTexCoord3fv(GLfloat *t) {
    glshim_glTexCoord4f(t[0], t[1], t[2], 1);
}
/*void glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    glTexCoord2f(s, t);
}*/
void glshim_glTexCoord4fv(GLfloat *t) {
    glshim_glTexCoord4f(t[0], t[1], t[2], t[3]);
}

// texgen
void glshim_glTexGend(GLenum coord, GLenum pname, GLdouble param) {
    glshim_glTexGenf(coord, pname, param);
}
void glshim_glTexGenf(GLenum coord, GLenum pname, GLfloat param) {
    GLfloat params[4] = {0,0,0,0};
    params[0] = param;
    glshim_glTexGenfv(coord, pname, params);
}
void glshim_glTexGendv(GLenum coord, GLenum pname, const GLdouble *params) {
    GLfloat tmp[4];
    tmp[0]=params[0];
    if ((pname==GL_OBJECT_PLANE) || (pname==GL_EYE_PLANE))
		for (int i=1; i<4; i++)
			tmp[i]=params[i];
    glshim_glTexGenfv(coord, pname, tmp);
}
void glshim_glTexGeniv(GLenum coord, GLenum pname, const GLint *params) {
    GLfloat tmp[4];
    tmp[0]=params[0];
    if ((pname==GL_OBJECT_PLANE) || (pname==GL_EYE_PLANE))
		for (int i=1; i<4; i++)
			tmp[i]=params[i];
    glshim_glTexGenfv(coord, pname, tmp);
}

// transforms
void glshim_glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
    glshim_glRotatef(angle, x, y, z);
}
void glshim_glScaled(GLdouble x, GLdouble y, GLdouble z) {
    glshim_glScalef(x, y, z);
}
void glshim_glTranslated(GLdouble x, GLdouble y, GLdouble z) {
    glshim_glTranslatef(x, y, z);
}

// vertex
void glshim_glVertex2f(GLfloat x, GLfloat y) {
    glshim_glVertex4f(x, y, 0, 1);
}
void glshim_glVertex2fv(GLfloat *v) {
    glshim_glVertex4f(v[0], v[1], 0, 1);
}
void glshim_glVertex3fv(GLfloat *v) {
    glshim_glVertex4f(v[0], v[1], v[2], 1);
}
void glshim_glVertex3f(GLfloat r, GLfloat g, GLfloat b) {
    glshim_glVertex4f(r, g, b, 1);
}
void glshim_glVertex4fv(GLfloat *v) {
    glshim_glVertex4f(v[0], v[1], v[2], v[3]);
}

void glshim_glDrawRangeElements(GLenum mode,GLuint start,GLuint end,GLsizei count,GLenum type,const void *indices) {
//printf("glDrawRangeElements(%s, %i, %i, %i, %s, @%p), inlist=%i\n", PrintEnum(mode), start, end, count, PrintEnum(type), indices, (state.list.active)?1:0);
    #if 1
    glshim_glDrawElements(mode, count, type, indices);
    #else
	GLushort *newinds = (GLushort*)malloc(sizeof(GLushort)*count);
	int newcount=0;
    glbuffer_t *elements = state.vao->elements;
    state.vao->elements = NULL;
    
	uintptr_t ptr = (uintptr_t)indices;
    if (elements)
        ptr+=(uintptr_t)elements->data;
    
	for (int i=0; i<count; i++) {
		GL_TYPE_SWITCH(indice, ptr, type,
		if ((indice[i]>=start) && (indice[i]<=end))
			newinds[newcount++]=indice[i];
		, );
	}
	glshim_glDrawElements(mode, newcount, GL_UNSIGNED_SHORT, newinds);
	free(newinds);
    
    state.vao->elements = elements;
    #endif
}

void glshim_glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) {
	// ignore buf is better than nothing...
	// TODO: handle buf
	glshim_glBlendEquationSeparate(modeRGB, modeAlpha);
}

void glshim_glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
	// ignore buf is better than nothing..
	// TODO: handle buf
	glshim_glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
}
#undef constDoubleToFloat

//Direct wrapper
#ifdef USE_ES2
void glCompileShader(GLuint shader) __attribute__((alias("glshim_glCompileShader")));
GLuint glCreateShaderObject(GLenum shaderType) __attribute__((alias("glshim_glCreateShaderObject")));
void glGetObjectParameteriv(GLuint shader, GLenum pname, GLint *params) __attribute__((alias("glshim_glGetObjectParameteriv")));
void glShaderSource(GLuint shader, GLsizei count, const GLchar **string, const GLint *length) __attribute__((alias("glshim_glShaderSource")));

void glCompileShaderARB(GLuint shader) __attribute__((alias("glshim_glCompileShader")));
GLuint glCreateShaderObjectARB(GLenum shaderType) __attribute__((alias("glshim_glCreateShaderObject")));
void glGetObjectParameterivARB(GLuint shader, GLenum pname, GLint *params) __attribute__((alias("glshim_glGetObjectParameteriv")));
void glShaderSourceARB(GLuint shader, GLsizei count, const GLchar **string, const GLint *length) __attribute__((alias("glshim_glShaderSource")));
#endif

void glClearDepth(GLdouble depth) __attribute__((alias("glshim_glClearDepth")));
void glClipPlane(GLenum plane, const GLdouble *equation) __attribute__((alias("glshim_glClipPlane")));
void glDepthRange(GLdouble nearVal, GLdouble farVal) __attribute__((alias("glshim_glDepthRange")));
void glFogi(GLenum pname, GLint param) __attribute__((alias("glshim_glFogi")));
void glFogiv(GLenum pname, GLint *params) __attribute__((alias("glshim_glFogiv")));
void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far) __attribute__((alias("glshim_glFrustum")));
void glGetDoublev(GLenum pname, GLdouble *params) __attribute__((alias("glshim_glGetDoublev")));
void glLighti(GLenum light, GLenum pname, GLint param) __attribute__((alias("glshim_glLighti")));
void glLightiv(GLenum light, GLenum pname, GLint *iparams) __attribute__((alias("glshim_glLightiv")));
void glLightModeli(GLenum pname, GLint param) __attribute__((alias("glshim_glLightModeli")));
void glLightModeliv(GLenum pname, GLint *iparams) __attribute__((alias("glshim_glLightModeliv")));
void glMateriali(GLenum face, GLenum pname, GLint param) __attribute__((alias("glshim_glMateriali")));
void glMaterialiv(GLenum face, GLenum pname, GLint *param) __attribute__((alias("glshim_glMaterialiv")));
void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far) __attribute__((alias("glshim_glOrtho")));
void glGetMaterialiv(GLenum face, GLenum pname, GLint * params) __attribute__((alias("glshim_glGetMaterialiv")));
void glGetLightiv(GLenum light, GLenum pname, GLint * params) __attribute__((alias("glshim_glGetLightiv")));
void glGetClipPlane(GLenum plane, GLdouble *equation) __attribute__((alias("glshim_glGetClipPlane")));
void glDrawRangeElements(GLenum mode,GLuint start,GLuint end,GLsizei count,GLenum type,const void *indices) __attribute__((alias("glshim_glDrawRangeElements")));
void glColor3f(GLfloat r, GLfloat g, GLfloat b) __attribute__((alias("glshim_glColor3f")));
void glColor3fv(GLfloat *c) __attribute__((alias("glshim_glColor3fv")));
void glColor4fv(GLfloat *c) __attribute__((alias("glshim_glColor4fv")));
void glIndexfv(const GLfloat *c) __attribute__((alias("glshim_glIndexfv")));
void glSecondaryColor3fv(const GLfloat *v) __attribute__((alias("glshim_glSecondaryColor3fv")));
void glRasterPos2f(GLfloat x, GLfloat y) __attribute__((alias("glshim_glRasterPos2f")));
void glRasterPos2fv(const GLfloat *v) __attribute__((alias("glshim_glRasterPos2fv")));
void glRasterPos3fv(const GLfloat *v) __attribute__((alias("glshim_glRasterPos3fv")));
void glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) __attribute__((alias("glshim_glRasterPos4f")));
void glRasterPos4fv(const GLfloat *v) __attribute__((alias("glshim_glRasterPos4fv")));
void glWindowPos2f(GLfloat x, GLfloat y) __attribute__((alias("glshim_glWindowPos2f")));
void glWindowPos2fv(const GLfloat *v) __attribute__((alias("glshim_glWindowPos2fv")));
void glWindowPos3fv(const GLfloat *v) __attribute__((alias("glshim_glWindowPos3fv")));
void glPixelStoref(GLenum pname, GLfloat param) __attribute__((alias("glshim_glPixelStoref")));
void glGetTexGendv(GLenum coord,GLenum pname,GLdouble *params) __attribute__((alias("glshim_glGetTexGendv")));
void glGetTexGeniv(GLenum coord,GLenum pname,GLint *params) __attribute__((alias("glshim_glGetTexGeniv")));
void glPixelTransferi(GLenum pname, GLint param) __attribute__((alias("glshim_glPixelTransferi")));
void glEvalCoord1d(GLdouble u) __attribute__((alias("glshim_glEvalCoord1d")));
void glEvalCoord1dv(GLdouble *v) __attribute__((alias("glshim_glEvalCoord1dv")));
void glEvalCoord1fv(GLfloat *v) __attribute__((alias("glshim_glEvalCoord1fv")));
void glEvalCoord2d(GLdouble u, GLdouble v) __attribute__((alias("glshim_glEvalCoord2d")));
void glEvalCoord2dv(GLdouble *v) __attribute__((alias("glshim_glEvalCoord2dv")));
void glEvalCoord2fv(GLfloat *v) __attribute__((alias("glshim_glEvalCoord2fv")));
void glMapGrid1d(GLint un, GLdouble u1, GLdouble u2) __attribute__((alias("glshim_glMapGrid1d")));
void glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2) __attribute__((alias("glshim_glMapGrid2d")));
void glLoadMatrixd(const GLdouble *m) __attribute__((alias("glshim_glLoadMatrixd")));
void glMultMatrixd(const GLdouble *m) __attribute__((alias("glshim_glMultMatrixd")));
void glNormal3fv(GLfloat *v) __attribute__((alias("glshim_glNormal3fv")));

// rect
#define GL_RECT(suffix, type)                                \
    void glRect##suffix(type x1, type y1, type x2, type y2) __attribute__((alias("glshim_glRect" #suffix))); \
    void glRect##suffix##v(const type *v)__attribute__((alias("glshim_glRect" #suffix "v")));

GL_RECT(d, GLdouble)
GL_RECT(f, GLfloat)
GL_RECT(i, GLint)
GL_RECT(s, GLshort)
#undef GL_RECT

void glTexCoord1f(GLfloat s) __attribute__((alias("glshim_glTexCoord1f")));
void glTexCoord1fv(GLfloat *t) __attribute__((alias("glshim_glTexCoord1fv")));
void glTexCoord2f(GLfloat s, GLfloat t) __attribute__((alias("glshim_glTexCoord2f")));
void glTexCoord2fv(GLfloat *t) __attribute__((alias("glshim_glTexCoord2fv")));
void glTexCoord3f(GLfloat s, GLfloat t, GLfloat r) __attribute__((alias("glshim_glTexCoord3f")));
void glTexCoord3fv(GLfloat *t) __attribute__((alias("glshim_glTexCoord3fv")));
void glTexCoord4fv(GLfloat *t) __attribute__((alias("glshim_glTexCoord4fv")));
void glMultiTexCoord1f(GLenum target, GLfloat s) __attribute__((alias("glshim_glMultiTexCoord1f")));
void glMultiTexCoord1fv(GLenum target, GLfloat *t) __attribute__((alias("glshim_glMultiTexCoord1fv")));
void glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) __attribute__((alias("glshim_glMultiTexCoord2f")));
void glMultiTexCoord2fv(GLenum target, GLfloat *t) __attribute__((alias("glshim_glMultiTexCoord2fv")));
void glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r) __attribute__((alias("glshim_glMultiTexCoord3f")));
void glMultiTexCoord3fv(GLenum target, GLfloat *t) __attribute__((alias("glshim_glMultiTexCoord3fv")));
void glMultiTexCoord4fv(GLenum target, GLfloat *t) __attribute__((alias("glshim_glMultiTexCoord4fv")));
void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params) __attribute__((alias("glshim_glGetTexLevelParameterfv")));
void glTexGend(GLenum coord, GLenum pname, GLdouble param) __attribute__((alias("glshim_glTexGend")));
void glTexGenf(GLenum coord, GLenum pname, GLfloat param) __attribute__((alias("glshim_glTexGenf")));
void glTexGendv(GLenum coord, GLenum pname, const GLdouble *params) __attribute__((alias("glshim_glTexGendv")));
void glTexGeniv(GLenum coord, GLenum pname, const GLint *params) __attribute__((alias("glshim_glTexGeniv")));
void glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) __attribute__((alias("glshim_glRotated")));
void glScaled(GLdouble x, GLdouble y, GLdouble z) __attribute__((alias("glshim_glScaled")));
void glTranslated(GLdouble x, GLdouble y, GLdouble z) __attribute__((alias("glshim_glTranslated")));
void glVertex2f(GLfloat x, GLfloat y) __attribute__((alias("glshim_glVertex2f")));
void glVertex2fv(GLfloat *v) __attribute__((alias("glshim_glVertex2fv")));
void glVertex3f(GLfloat r, GLfloat g, GLfloat b) __attribute__((alias("glshim_glVertex3f")));
void glVertex3fv(GLfloat *v) __attribute__((alias("glshim_glVertex3fv")));
void glVertex4fv(GLfloat *v) __attribute__((alias("glshim_glVertex4fv")));

// basic thunking

#define THUNK(suffix, type)                                \
void glColor3##suffix##v(const type *v)                 __attribute__((alias("glshim_glColor3"#suffix "v"))); \
void glColor3##suffix(type r, type g, type b)           __attribute__((alias("glshim_glColor3"#suffix))); \
void glColor4##suffix##v(const type *v)                 __attribute__((alias("glshim_glColor4"#suffix "v"))); \
void glColor4##suffix(type r, type g, type b, type a)   __attribute__((alias("glshim_glColor4"#suffix))); \
void glSecondaryColor3##suffix##v(const type *v)        __attribute__((alias("glshim_glSecondaryColor3"#suffix "v"))); \
void glSecondaryColor3##suffix(type r, type g, type b)  __attribute__((alias("glshim_glSecondaryColor3"#suffix))); \
void glIndex##suffix##v(const type *c)                  __attribute__((alias("glshim_glIndex"#suffix"v"))); \
void glIndex##suffix(type c)                            __attribute__((alias("glshim_glIndex"#suffix))); \
void glNormal3##suffix##v(const type *v)                __attribute__((alias("glshim_glNormal3"#suffix"v"))); \
void glNormal3##suffix(type x, type y, type z)          __attribute__((alias("glshim_glNormal3"#suffix))); \
void glRasterPos2##suffix##v(type *v)                   __attribute__((alias("glshim_glRasterPos2"#suffix"v"))); \
void glRasterPos2##suffix(type x, type y)               __attribute__((alias("glshim_glRasterPos2"#suffix))); \
void glRasterPos3##suffix##v(type *v)                   __attribute__((alias("glshim_glRasterPos3"#suffix"v"))); \
void glRasterPos3##suffix(type x, type y, type z)       __attribute__((alias("glshim_glRasterPos3"#suffix))); \
void glRasterPos4##suffix##v(type *v)                   __attribute__((alias("glshim_glRasterPos4"#suffix"v"))); \
void glRasterPos4##suffix(type x, type y, type z, type w)__attribute__((alias("glshim_glRasterPos4"#suffix))); \
void glWindowPos2##suffix##v(type *v)                   __attribute__((alias("glshim_glWindowPos2"#suffix"v"))); \
void glWindowPos2##suffix(type x, type y)               __attribute__((alias("glshim_glWindowPos2"#suffix))); \
void glWindowPos3##suffix##v(type *v)                   __attribute__((alias("glshim_glWindowPos3"#suffix"v"))); \
void glWindowPos3##suffix(type x, type y, type z)       __attribute__((alias("glshim_glWindowPos3"#suffix))); \
void glVertex2##suffix##v(type *v)                      __attribute__((alias("glshim_glVertex2"#suffix"v"))); \
void glVertex2##suffix(type x, type y)                  __attribute__((alias("glshim_glVertex2"#suffix))); \
void glVertex3##suffix##v(type *v)                      __attribute__((alias("glshim_glVertex3"#suffix"v"))); \
void glVertex3##suffix(type x, type y, type z)          __attribute__((alias("glshim_glVertex3"#suffix))); \
void glVertex4##suffix(type x, type y, type z, type w)  __attribute__((alias("glshim_glVertex4"#suffix))); \
void glVertex4##suffix##v(type *v)                      __attribute__((alias("glshim_glVertex4"#suffix"v"))); \
void glTexCoord1##suffix(type s)                        __attribute__((alias("glshim_glTexCoord1"#suffix))); \
void glTexCoord1##suffix##v(type *t)                    __attribute__((alias("glshim_glTexCoord1"#suffix"v"))); \
void glTexCoord2##suffix(type s, type t)                __attribute__((alias("glshim_glTexCoord2"#suffix))); \
void glTexCoord2##suffix##v(type *t)                    __attribute__((alias("glshim_glTexCoord2"#suffix"v"))); \
void glTexCoord3##suffix(type s, type t, type r)        __attribute__((alias("glshim_glTexCoord3"#suffix))); \
void glTexCoord3##suffix##v(type *t)                    __attribute__((alias("glshim_glTexCoord3"#suffix"v"))); \
void glTexCoord4##suffix(type s, type t, type r, type q)__attribute__((alias("glshim_glTexCoord4"#suffix))); \
void glTexCoord4##suffix##v(type *t)                    __attribute__((alias("glshim_glTexCoord4"#suffix"v"))); \
void glMultiTexCoord1##suffix(GLenum target, type s)    __attribute__((alias("glshim_glMultiTexCoord1"#suffix))); \
void glMultiTexCoord1##suffix##v(GLenum target, type *t)__attribute__((alias("glshim_glMultiTexCoord1"#suffix"v"))); \
void glMultiTexCoord2##suffix(GLenum target, type s, type t)        __attribute__((alias("glshim_glMultiTexCoord2"#suffix))); \
void glMultiTexCoord2##suffix##v(GLenum target, type *t)            __attribute__((alias("glshim_glMultiTexCoord2"#suffix"v"))); \
void glMultiTexCoord3##suffix(GLenum target, type s, type t, type r)__attribute__((alias("glshim_glMultiTexCoord3"#suffix))); \
void glMultiTexCoord3##suffix##v(GLenum target, type *t)            __attribute__((alias("glshim_glMultiTexCoord3"#suffix"v"))); \
void glMultiTexCoord4##suffix(GLenum target, type s, type t, type r, type q) __attribute__((alias("glshim_glMultiTexCoord4"#suffix))); \
void glMultiTexCoord4##suffix##v(GLenum target, type *t)            __attribute__((alias("glshim_glMultiTexCoord4"#suffix"v"))); \
void glMultiTexCoord1##suffix##ARB(GLenum target, type s)           __attribute__((alias("glshim_glMultiTexCoord1"#suffix))); \
void glMultiTexCoord1##suffix##vARB(GLenum target, type *t)         __attribute__((alias("glshim_glMultiTexCoord1"#suffix"v"))); \
void glMultiTexCoord2##suffix##ARB(GLenum target, type s, type t)   __attribute__((alias("glshim_glMultiTexCoord2"#suffix))); \
void glMultiTexCoord2##suffix##vARB(GLenum target, type *t)         __attribute__((alias("glshim_glMultiTexCoord2"#suffix"v"))); \
void glMultiTexCoord3##suffix##ARB(GLenum target, type s, type t, type r)  __attribute__((alias("glshim_glMultiTexCoord3"#suffix))); \
void glMultiTexCoord3##suffix##vARB(GLenum target, type *t)         __attribute__((alias("glshim_glMultiTexCoord3"#suffix"v"))); \
void glMultiTexCoord4##suffix##ARB(GLenum target, type s, type t, type r, type q) __attribute__((alias("glshim_glMultiTexCoord4"#suffix))); \
void glMultiTexCoord4##suffix##vARB(GLenum target, type *t)__attribute__((alias("glshim_glMultiTexCoord4"#suffix"v")));

THUNK(b, GLbyte)
THUNK(d, GLdouble)
THUNK(i, GLint)
THUNK(s, GLshort)
THUNK(ub, GLubyte)
THUNK(ui, GLuint)
THUNK(us, GLushort)
#undef THUNK

#define THUNK(suffix, type) \
    extern void glGet##suffix##v(GLenum pname, type *params);

THUNK(Double, GLdouble)
THUNK(Integer, GLint)
THUNK(Float, GLfloat)
#undef THUNK

void glMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t) __attribute__((alias("glshim_glMultiTexCoord2f")));
void glMultiTexCoord3fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r) __attribute__((alias("glshim_glMultiTexCoord3f")));
void glMultiTexCoord2fvARB(GLenum target, GLfloat *t) __attribute__((alias("glshim_glMultiTexCoord2fv")));
void glMultiTexCoord3fvARB(GLenum target, GLfloat *t) __attribute__((alias("glshim_glMultiTexCoord3fv")));
void glMultiTexCoord4fvARB(GLenum target, GLfloat *t) __attribute__((alias("glshim_glMultiTexCoord4fv")));
void glDrawRangeElementsEXT(GLenum mode,GLuint start,GLuint end,GLsizei count,GLenum type,const void *indices) __attribute__((alias("glshim_glDrawRangeElements")));
