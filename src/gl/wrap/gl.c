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
void gl4es_glCompileShader(GLuint shader) {
    gl4es_glCompileShader(shader);
    GLint status;
    gl4es_glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE) {
        GLint log_length;
        gl4es_glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &log_length);
        GLchar *log = malloc(sizeof(GLchar) * log_length);
        gl4es_glGetShaderInfoLog(shader, log_length, NULL, log);
        printf("Shader compile failed: %s\n", log);
        free(log);
    }
}
GLuint gl4es_glCreateShaderObject(GLenum shaderType) {
    return glCreateShader(shaderType);
}
void gl4es_glShaderSource(GLuint shader, GLsizei count, const GLchar **string, const GLint *length) {
    gl4es_glShaderSource(shader, count, string, length);
}
void gl4es_glGetObjectParameteriv(GLuint shader, GLenum pname, GLint *params) {
    gl4es_glGetShaderiv(shader, pname, params);
}
#endif

void gl4es_glClearDepth(GLdouble depth) {
    gl4es_glClearDepthf(depth);
}
void gl4es_glClipPlane(GLenum plane, const GLdouble *equation) {
    constDoubleToFloat(equation, 4);
    gl4es_glClipPlanef(plane, s);
}
void gl4es_glDepthRange(GLdouble nearVal, GLdouble farVal) {
    gl4es_glDepthRangef(nearVal, farVal);
}
void gl4es_glFogi(GLenum pname, GLint param) {
    gl4es_glFogf(pname, param);
}
void gl4es_glFogiv(GLenum pname, GLint *iparams) {
    switch (pname) {
        case GL_FOG_DENSITY:
        case GL_FOG_START:
        case GL_FOG_END:
        case GL_FOG_MODE:
        case GL_FOG_INDEX: {
            gl4es_glFogf(pname, *iparams);
            break;
        }
        case GL_FOG_COLOR: {
            GLfloat params[4];
            for (int i = 0; i < 4; i++) {
                params[i] = (iparams[i]>>16)*1.0f/32767.f;
            }
            gl4es_glFogfv(pname, params);
            break;
        }
    }
}
void gl4es_glGetTexGendv(GLenum coord,GLenum pname,GLdouble *params) {
	GLfloat fparams[4];
	gl4es_glGetTexGenfv(coord, pname, fparams);
	if (pname==GL_TEXTURE_GEN_MODE) *params=fparams[0];
	else for (int i=0; i<4; i++) params[i]=fparams[i];
}
void gl4es_glGetTexGeniv(GLenum coord,GLenum pname,GLint *params) {
	GLfloat fparams[4];
	gl4es_glGetTexGenfv(coord, pname, fparams);
	if (pname==GL_TEXTURE_GEN_MODE) *params=fparams[0];
	else for (int i=0; i<4; i++) params[i]=fparams[i];
}
void gl4es_glGetMaterialiv(GLenum face, GLenum pname, GLint * params) {
	GLfloat fparams[4];
	gl4es_glGetMaterialfv(face, pname, fparams);
	if (pname==GL_SHININESS) *params=fparams[0];
	else {
        if (pname==GL_COLOR_INDEXES)
            for (int i=0; i<3; i++) params[i]=fparams[i];
        else
            for (int i=0; i<4; i++) params[i]=((int)fparams[i]*32767)<<16;
    }
}
void gl4es_glGetLightiv(GLenum light, GLenum pname, GLint * params) {
	GLfloat fparams[4];
	gl4es_glGetLightfv(light, pname, fparams);
	int n=4;
    switch(pname) {
        case GL_SPOT_EXPONENT:
        case GL_SPOT_CUTOFF:
        case GL_CONSTANT_ATTENUATION:
        case GL_LINEAR_ATTENUATION:
        case GL_QUADRATIC_ATTENUATION:
             n=1;
             break;
	    case GL_SPOT_DIRECTION:
             n=3;
             break;
    }
    if(pname==GL_AMBIENT || pname==GL_DIFFUSE || pname==GL_SPECULAR)
        for (int i=0; i<n; i++) params[i]=((int)fparams[i]*32767)<<16;
    else
	    for (int i=0; i<n; i++) params[i]=fparams[i];
}
void gl4es_glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params) {
	GLint iparams;
	gl4es_glGetTexLevelParameteriv(target, level, pname, &iparams);
	(*params)=iparams;
	return;
}
void gl4es_glGetClipPlane(GLenum plane, GLdouble *equation) {
	GLfloat fparams[4];
	gl4es_glGetClipPlanef(plane, fparams);
	for (int i=0; i<4; i++) equation[i]=fparams[i];
}

void gl4es_glFrustum(GLdouble left, GLdouble right, GLdouble bottom,
             GLdouble top, GLdouble near, GLdouble far) {
    gl4es_glFrustumf(left, right, bottom, top, near, far);
}
void gl4es_glPixelStoref(GLenum pname, GLfloat param) {
    gl4es_glPixelStorei(pname, param);
}
void gl4es_glLighti(GLenum light, GLenum pname, GLint param) {
    gl4es_glLightf(light, pname, param);
}
void gl4es_glPixelTransferi(GLenum pname, GLint param) {
	gl4es_glPixelTransferf(pname, param);	
}

void gl4es_glLightiv(GLenum light, GLenum pname, GLint *iparams) {
    GLfloat params[4];
    switch (pname) {
        case GL_AMBIENT:
        case GL_DIFFUSE:
        case GL_SPECULAR:
            for (int i = 0; i < 4; i++) {
                params[i] = (iparams[i]>>16)*(1.0f/32767.f);
            }
            gl4es_glLightfv(light, pname, params);
            break;
        case GL_POSITION:
            for (int i = 0; i < 4; i++) {
                params[i] = iparams[i];
            }
            gl4es_glLightfv(light, pname, params);
            break;
        case GL_SPOT_DIRECTION:
            for (int i = 0; i < 4; i++) {
                params[i] = iparams[i];
            }
            gl4es_glLightfv(light, pname, params);
            break;
        case GL_SPOT_EXPONENT:
        case GL_SPOT_CUTOFF:
        case GL_CONSTANT_ATTENUATION:
        case GL_LINEAR_ATTENUATION:
        case GL_QUADRATIC_ATTENUATION: {
            gl4es_glLightf(light, pname, *iparams);
            break;
        }
    }
}
#ifndef USE_ES2
void gl4es_glLightModeli(GLenum pname, GLint param) {
    gl4es_glLightModelf(pname, param);
}
void gl4es_glLightModeliv(GLenum pname, GLint *iparams) {
    switch (pname) {
        case GL_LIGHT_MODEL_AMBIENT: {
            GLfloat params[4];
            for (int i = 0; i < 4; i++) {
                params[i] = (iparams[i]>>16)*1.f/32767.f;
            }
            gl4es_glLightModelfv(pname, params);
            break;
        }
        case GL_LIGHT_MODEL_LOCAL_VIEWER:
        case GL_LIGHT_MODEL_TWO_SIDE: {
            gl4es_glLightModelf(pname, *iparams);
            break;
        }
    }
}
#endif
void gl4es_glMateriali(GLenum face, GLenum pname, GLint param) {
    gl4es_glMaterialf(face, pname, param);
}
void gl4es_glMaterialiv(GLenum face, GLenum pname, GLint *iparams) {
printf("glMaterialiv(%04X, %04X, [%i,...]\n", face, pname, iparams[0]);
    switch (pname) {
        case GL_AMBIENT: 
		case GL_DIFFUSE:
		case GL_SPECULAR:
		case GL_EMISSION:
        case GL_AMBIENT_AND_DIFFUSE:
		{
            GLfloat params[4];
            for (int i = 0; i < 4; i++) {
                params[i] = (iparams[i]>>16)*1.f/32767.f;
            }
            gl4es_glMaterialfv(face, pname, params);
            break;
        }
		case GL_SHININESS:
		{
            gl4es_glMaterialf(face, pname, *iparams);
            break;
        }
		case GL_COLOR_INDEXES:
		{
            GLfloat params[3];
            for (int i = 0; i < 3; i++) {
                params[i] = iparams[i];
            }
            gl4es_glMaterialfv(face, pname, params);
            break;
        }
    }
}

/*
void glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) {
    glMultiTexCoord4f(target, s, t, 0.0f, 1.0f);
}
* */
void gl4es_glMultiTexCoord1f(GLenum target, GLfloat s) {
     gl4es_glMultiTexCoord4f(target, s, 0, 0, 1);
}
void gl4es_glMultiTexCoord1fv(GLenum target, GLfloat *t) {
     gl4es_glMultiTexCoord4f(target, t[0], 0, 0, 1);
}
void gl4es_glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) {
     gl4es_glMultiTexCoord4f(target, s, t, 0, 1);
}
void gl4es_glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r) {
     gl4es_glMultiTexCoord4f(target, s, t, r, 1);
}
/*void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
     glMultiTexCoord2f(target, s, t);
}*/
void gl4es_glMultiTexCoord2fv(GLenum target, GLfloat *t) {
     gl4es_glMultiTexCoord4f(target, t[0], t[1], 0, 1);
}
void gl4es_glMultiTexCoord3fv(GLenum target, GLfloat *t) {
     gl4es_glMultiTexCoord4f(target, t[0], t[1], t[2], 1);
}
void gl4es_glMultiTexCoord4fv(GLenum target, GLfloat *t) {
     gl4es_glMultiTexCoord4f(target, t[0], t[1], t[2], t[3]);
}
/*
void glBlendFuncSeparateEXT (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
	glBlendFuncSeparate (sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
*/
void gl4es_glOrtho(GLdouble left, GLdouble right, GLdouble bottom,
             GLdouble top, GLdouble near, GLdouble far) {
    gl4es_glOrthof(left, right, bottom, top, near, far);
}

// OES wrappers

void glClearDepthfOES(GLfloat depth) {
    gl4es_glClearDepthf(depth);
}
void glClipPlanefOES(GLenum plane, const GLfloat *equation) {
    gl4es_glClipPlanef(plane, equation);
}
void glDepthRangefOES(GLclampf near, GLclampf far) {
    gl4es_glDepthRangef(near, far);
}
void glFrustumfOES(GLfloat left, GLfloat right, GLfloat bottom,
                   GLfloat top, GLfloat near, GLfloat far) {
    gl4es_glFrustumf(left, right, bottom, top, near, far);
}
void glGetClipPlanefOES(GLenum pname, GLfloat equation[4]) {
    gl4es_glGetClipPlanef(pname, equation);
}
void glOrthofOES(GLfloat left, GLfloat right, GLfloat bottom,
                 GLfloat top, GLfloat near, GLfloat far) {
    gl4es_glOrthof(left, right, bottom, top, near, far);
}

// glRect

#define GL_RECT(suffix, type)                                 \
    void gl4es_glRect##suffix(type x1, type y1, type x2, type y2) { \
        gl4es_glBegin(GL_POLYGON);                                  \
        gl4es_glVertex2##suffix(x1, y1);                            \
        gl4es_glVertex2##suffix(x2, y1);                            \
        gl4es_glVertex2##suffix(x2, y2);                            \
        gl4es_glVertex2##suffix(x1, y2);                            \
		gl4es_glEnd();											  \
    }                                                         \
    void gl4es_glRect##suffix##v(const type *v) {                   \
        gl4es_glRect##suffix(v[0], v[1], v[2], v[3]);               \
    }

GL_RECT(d, GLdouble)
GL_RECT(f, GLfloat)
GL_RECT(i, GLint)
GL_RECT(s, GLshort)
#undef GL_RECT

// basic thunking

#define THUNK(suffix, type, max)                            \
/* colors */                                                \
void gl4es_glColor3##suffix(type r, type g, type b) {             \
    gl4es_glColor4f(r/max, g/max, b/max, 1.0f);                   \
}                                                           \
void gl4es_glColor4##suffix(type r, type g, type b, type a) {     \
    gl4es_glColor4f(r/max, g/max, b/max, a/max);                  \
}                                                           \
void gl4es_glColor3##suffix##v(const type *v) {                   \
    gl4es_glColor4f(v[0]/max, v[1]/max, v[2]/max, 1.0f);          \
}                                                           \
void gl4es_glColor4##suffix##v(const type *v) {                   \
    gl4es_glColor4f(v[0]/max, v[1]/max, v[2]/max, v[3]/max);      \
}                                                           \
void gl4es_glSecondaryColor3##suffix(type r, type g, type b) {    \
    gl4es_glSecondaryColor3f(r/max, g/max, b/max);                \
}                                                           \
void gl4es_glSecondaryColor3##suffix##v(const type *v) {          \
    gl4es_glSecondaryColor3f(v[0]/max, v[1]/max, v[2]/max);       \
}                                                           \
/* index */                                                 \
void gl4es_glIndex##suffix(type c) {                              \
    gl4es_glIndexf(c);                                            \
}                                                           \
void gl4es_glIndex##suffix##v(const type *c) {                    \
    gl4es_glIndexf(c[0]);                                         \
}                                                           \
/* normal */                                                \
void gl4es_glNormal3##suffix(type x, type y, type z) {            \
    gl4es_glNormal3f(x, y, z);                                    \
}                                                           \
void gl4es_glNormal3##suffix##v(const type *v) {                  \
    gl4es_glNormal3f(v[0], v[1], v[2]);                           \
}                                                           \
/* raster */                                                \
void gl4es_glRasterPos2##suffix(type x, type y) {                 \
    gl4es_glRasterPos3f(x, y, 0);                                 \
}                                                           \
void gl4es_glRasterPos2##suffix##v(type *v) {                     \
    gl4es_glRasterPos3f(v[0], v[1], 0);                           \
}                                                           \
void gl4es_glRasterPos3##suffix(type x, type y, type z) {         \
    gl4es_glRasterPos3f(x, y, z);                                 \
}                                                           \
void gl4es_glRasterPos3##suffix##v(type *v) {                     \
    gl4es_glRasterPos3f(v[0], v[1], v[2]);                        \
}                                                           \
void gl4es_glRasterPos4##suffix(type x, type y, type z, type w) { \
    gl4es_glRasterPos4f(x, y, z, w);                              \
}                                                           \
void gl4es_glRasterPos4##suffix##v(type *v) {                     \
    gl4es_glRasterPos4f(v[0], v[1], v[2], v[3]);                  \
}                                                           \
void gl4es_glWindowPos2##suffix(type x, type y) {                 \
    gl4es_glWindowPos3f(x, y, 0);                                 \
}                                                           \
void gl4es_glWindowPos2##suffix##v(type *v) {                     \
    gl4es_glWindowPos3f(v[0], v[1], 0);                           \
}                                                           \
void gl4es_glWindowPos3##suffix(type x, type y, type z) {         \
    gl4es_glWindowPos3f(x, y, z);                                 \
}                                                           \
void gl4es_glWindowPos3##suffix##v(type *v) {                     \
    gl4es_glWindowPos3f(v[0], v[1], v[2]);                        \
}                                                           \
/* vertex */                                                \
void gl4es_glVertex2##suffix(type x, type y) {                    \
    gl4es_glVertex4f(x, y, 0, 1);                                 \
}                                                           \
void gl4es_glVertex2##suffix##v(type *v) {                        \
    gl4es_glVertex4f(v[0], v[1], 0 ,1);                           \
}                                                           \
void gl4es_glVertex3##suffix(type x, type y, type z) {            \
    gl4es_glVertex4f(x, y, z, 1);                                 \
}                                                           \
void gl4es_glVertex3##suffix##v(type *v) {                        \
    gl4es_glVertex4f(v[0], v[1], v[2], 1);                        \
}                                                           \
void gl4es_glVertex4##suffix(type r, type g, type b, type w) {    \
    gl4es_glVertex4f(r, g, b, w);                                 \
}                                                           \
void gl4es_glVertex4##suffix##v(type *v) {                        \
    gl4es_glVertex4f(v[0], v[1], v[2], v[3]);                     \
}                                                           \
/* texture */                                               \
void gl4es_glTexCoord1##suffix(type s) {                          \
    gl4es_glTexCoord4f(s, 0, 0, 1);                               \
}                                                           \
void gl4es_glTexCoord1##suffix##v(type *t) {                      \
    gl4es_glTexCoord4f(t[0], 0, 0, 1);                            \
}                                                           \
void gl4es_glTexCoord2##suffix(type s, type t) {                  \
    gl4es_glTexCoord4f(s, t, 0, 1);                               \
}                                                           \
void gl4es_glTexCoord2##suffix##v(type *t) {                      \
    gl4es_glTexCoord4f(t[0], t[1], 0, 1);                         \
}                                                           \
void gl4es_glTexCoord3##suffix(type s, type t, type r) {          \
    gl4es_glTexCoord4f(s, t, r, 1);                               \
}                                                           \
void gl4es_glTexCoord3##suffix##v(type *t) {                      \
    gl4es_glTexCoord4f(t[0], t[1], t[2], 1);                      \
}                                                           \
void gl4es_glTexCoord4##suffix(type s, type t, type r, type q) {  \
    gl4es_glTexCoord4f(s, t, r, q);                               \
}                                                           \
void gl4es_glTexCoord4##suffix##v(type *t) {                      \
    gl4es_glTexCoord4f(t[0], t[1], t[2], t[3]);                    \
}															\
/* multi-texture */                                         \
void gl4es_glMultiTexCoord1##suffix(GLenum target, type s) {      \
    gl4es_glMultiTexCoord4f(target, s, 0, 0, 1);                        \
}                                                           \
void gl4es_glMultiTexCoord1##suffix##v(GLenum target, type *t) {  \
    gl4es_glMultiTexCoord4f(target, t[0], 0, 0, 1);                    \
}                                                           \
void gl4es_glMultiTexCoord2##suffix(GLenum target, type s, type t) {           \
    gl4es_glMultiTexCoord4f(target, s, t, 0, 1);                               \
}                                                                        \
void gl4es_glMultiTexCoord2##suffix##v(GLenum target, type *t) {               \
    gl4es_glMultiTexCoord4f(target, t[0], t[1], 0, 1);                         \
}                                                                        \
void gl4es_glMultiTexCoord3##suffix(GLenum target, type s, type t, type r) {   \
    gl4es_glMultiTexCoord4f(target, s, t, r, 1);                               \
}                                                                        \
void gl4es_glMultiTexCoord3##suffix##v(GLenum target, type *t) {               \
    gl4es_glMultiTexCoord4f(target, t[0], t[1], t[2], 1);                      \
}                                                                        \
void gl4es_glMultiTexCoord4##suffix(GLenum target, type s, type t, type r, type q) {  \
    gl4es_glMultiTexCoord4f(target, s, t, r, q);                               \
}                                                                        \
void gl4es_glMultiTexCoord4##suffix##v(GLenum target, type *t) {               \
    gl4es_glMultiTexCoord4f(target, t[0], t[1], t[2], t[3]);                   \
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
void gl4es_glGet##suffix##v(GLenum pname, type *params) {      \
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
    gl4es_glGetFloatv(pname, p);		                         \
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
void gl4es_glColor3f(GLfloat r, GLfloat g, GLfloat b) {
    gl4es_glColor4f(r, g, b, 1.0f);
}
void gl4es_glColor3fv(GLfloat *c) {
    gl4es_glColor4f(c[0], c[1], c[2], 1.0f);
}
void gl4es_glColor4fv(GLfloat *c) {
    gl4es_glColor4f(c[0], c[1], c[2], c[3]);
}
void gl4es_glIndexfv(const GLfloat *c) {
    gl4es_glIndexf(*c);
}
void gl4es_glSecondaryColor3fv(const GLfloat *v) {
    gl4es_glSecondaryColor3f(v[0], v[1], v[2]);
}

// raster
void gl4es_glRasterPos2f(GLfloat x, GLfloat y) {
    gl4es_glRasterPos3f(x, y, 0.0f);
}
void gl4es_glRasterPos2fv(const GLfloat *v) {
    gl4es_glRasterPos3f(v[0], v[1], 0.0f);
}
void gl4es_glRasterPos3fv(const GLfloat *v) {
    gl4es_glRasterPos3f(v[0], v[1], v[2]);
}
void gl4es_glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    gl4es_glRasterPos3f(x/w, y/w, z/w);
}
void gl4es_glRasterPos4fv(const GLfloat *v) {
    gl4es_glRasterPos4f(v[0], v[1], v[2], v[3]);
}
void gl4es_glWindowPos2f(GLfloat x, GLfloat y) {
    gl4es_glWindowPos3f(x, y, 0.0f);
}
void gl4es_glWindowPos2fv(const GLfloat *v) {
    gl4es_glWindowPos3f(v[0], v[1], 0.0f);
}
void gl4es_glWindowPos3fv(const GLfloat *v) {
    gl4es_glWindowPos3f(v[0], v[1], v[2]);
}

// eval
void gl4es_glEvalCoord1d(GLdouble u) {
    gl4es_glEvalCoord1f(u);
}

void gl4es_glEvalCoord2d(GLdouble u, GLdouble v) {
    gl4es_glEvalCoord2f(u, v);
}

void gl4es_glEvalCoord1fv(GLfloat *v) {
    gl4es_glEvalCoord1f(v[0]);
}

void gl4es_glEvalCoord1dv(GLdouble *v) {
    gl4es_glEvalCoord1d(v[0]);
}

void gl4es_glEvalCoord2fv(GLfloat *v) {
    gl4es_glEvalCoord2f(v[0], v[1]);
}

void gl4es_glEvalCoord2dv(GLdouble *v) {
    gl4es_glEvalCoord2d(v[0], v[1]);
}

void gl4es_glMapGrid1d(GLint un, GLdouble u1, GLdouble u2) {
    gl4es_glMapGrid1f(un, u1, u2);
}

void gl4es_glMapGrid2d(GLint un, GLdouble u1, GLdouble u2,
                 GLint vn, GLdouble v1, GLdouble v2) {
    gl4es_glMapGrid2f(un, u1, u2, vn, v1, v2);
}

// matrix
void gl4es_glLoadMatrixd(const GLdouble *m) {
    constDoubleToFloat(m, 16);
    gl4es_glLoadMatrixf(s);
}
void gl4es_glMultMatrixd(const GLdouble *m) {
    constDoubleToFloat(m, 16);
    gl4es_glMultMatrixf(s);
}

// normal
void gl4es_glNormal3fv(GLfloat *v) {
    gl4es_glNormal3f(v[0], v[1], v[2]);
}

// textures
void gl4es_glTexCoord1f(GLfloat s) {
    gl4es_glTexCoord4f(s, 0, 0, 1);
}
void gl4es_glTexCoord1fv(GLfloat *t) {
    gl4es_glTexCoord4f(t[0], 0, 0, 1);
}
void gl4es_glTexCoord2f(GLfloat s, GLfloat t) {
    gl4es_glTexCoord4f(s, t, 0, 1);
}
void gl4es_glTexCoord2fv(GLfloat *t) {
    gl4es_glTexCoord4f(t[0], t[1], 0, 1);
}
void gl4es_glTexCoord3f(GLfloat s, GLfloat t, GLfloat r) {
    gl4es_glTexCoord4f(s, t, r, 1);
}
void gl4es_glTexCoord3fv(GLfloat *t) {
    gl4es_glTexCoord4f(t[0], t[1], t[2], 1);
}
/*void glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    glTexCoord2f(s, t);
}*/
void gl4es_glTexCoord4fv(GLfloat *t) {
    gl4es_glTexCoord4f(t[0], t[1], t[2], t[3]);
}

// texgen
void gl4es_glTexGend(GLenum coord, GLenum pname, GLdouble param) {
    gl4es_glTexGenf(coord, pname, param);
}
void gl4es_glTexGenf(GLenum coord, GLenum pname, GLfloat param) {
    GLfloat params[4] = {0,0,0,0};
    params[0] = param;
    gl4es_glTexGenfv(coord, pname, params);
}
void gl4es_glTexGendv(GLenum coord, GLenum pname, const GLdouble *params) {
    GLfloat tmp[4];
    tmp[0]=params[0];
    if ((pname==GL_OBJECT_PLANE) || (pname==GL_EYE_PLANE))
		for (int i=1; i<4; i++)
			tmp[i]=params[i];
    gl4es_glTexGenfv(coord, pname, tmp);
}
void gl4es_glTexGeniv(GLenum coord, GLenum pname, const GLint *params) {
    GLfloat tmp[4];
    tmp[0]=params[0];
    if ((pname==GL_OBJECT_PLANE) || (pname==GL_EYE_PLANE))
		for (int i=1; i<4; i++)
			tmp[i]=params[i];
    gl4es_glTexGenfv(coord, pname, tmp);
}

// transforms
void gl4es_glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
    gl4es_glRotatef(angle, x, y, z);
}
void gl4es_glScaled(GLdouble x, GLdouble y, GLdouble z) {
    gl4es_glScalef(x, y, z);
}
void gl4es_glTranslated(GLdouble x, GLdouble y, GLdouble z) {
    gl4es_glTranslatef(x, y, z);
}

// vertex
void gl4es_glVertex2f(GLfloat x, GLfloat y) {
    gl4es_glVertex4f(x, y, 0, 1);
}
void gl4es_glVertex2fv(GLfloat *v) {
    gl4es_glVertex4f(v[0], v[1], 0, 1);
}
void gl4es_glVertex3fv(GLfloat *v) {
    gl4es_glVertex4f(v[0], v[1], v[2], 1);
}
void gl4es_glVertex3f(GLfloat r, GLfloat g, GLfloat b) {
    gl4es_glVertex4f(r, g, b, 1);
}
void gl4es_glVertex4fv(GLfloat *v) {
    gl4es_glVertex4f(v[0], v[1], v[2], v[3]);
}

void gl4es_glDrawRangeElements(GLenum mode,GLuint start,GLuint end,GLsizei count,GLenum type,const void *indices) {
//printf("glDrawRangeElements(%s, %i, %i, %i, %s, @%p), inlist=%i\n", PrintEnum(mode), start, end, count, PrintEnum(type), indices, (state.list.active)?1:0);
    #if 1
    gl4es_glDrawElements(mode, count, type, indices);
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
	gl4es_glDrawElements(mode, newcount, GL_UNSIGNED_SHORT, newinds);
	free(newinds);
    
    state.vao->elements = elements;
    #endif
}

void gl4es_glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) {
	// ignore buf is better than nothing...
	// TODO: handle buf
	gl4es_glBlendEquationSeparate(modeRGB, modeAlpha);
}

void gl4es_glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
	// ignore buf is better than nothing..
	// TODO: handle buf
	gl4es_glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
}
#undef constDoubleToFloat

//Direct wrapper
#ifdef USE_ES2
void glCompileShader(GLuint shader) AliasExport("gl4es_glCompileShader");
GLuint glCreateShaderObject(GLenum shaderType) AliasExport("gl4es_glCreateShaderObject");
void glGetObjectParameteriv(GLuint shader, GLenum pname, GLint *params) AliasExport("gl4es_glGetObjectParameteriv");
void glShaderSource(GLuint shader, GLsizei count, const GLchar **string, const GLint *length) AliasExport("gl4es_glShaderSource");

void glCompileShaderARB(GLuint shader) AliasExport("gl4es_glCompileShader");
GLuint glCreateShaderObjectARB(GLenum shaderType) AliasExport("gl4es_glCreateShaderObject");
void glGetObjectParameterivARB(GLuint shader, GLenum pname, GLint *params) AliasExport("gl4es_glGetObjectParameteriv");
void glShaderSourceARB(GLuint shader, GLsizei count, const GLchar **string, const GLint *length) AliasExport("gl4es_glShaderSource");
#endif

void glClearDepth(GLdouble depth) AliasExport("gl4es_glClearDepth");
void glClipPlane(GLenum plane, const GLdouble *equation) AliasExport("gl4es_glClipPlane");
void glDepthRange(GLdouble nearVal, GLdouble farVal) AliasExport("gl4es_glDepthRange");
void glFogi(GLenum pname, GLint param) AliasExport("gl4es_glFogi");
void glFogiv(GLenum pname, GLint *params) AliasExport("gl4es_glFogiv");
void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far) AliasExport("gl4es_glFrustum");
void glGetDoublev(GLenum pname, GLdouble *params) AliasExport("gl4es_glGetDoublev");
void glLighti(GLenum light, GLenum pname, GLint param) AliasExport("gl4es_glLighti");
void glLightiv(GLenum light, GLenum pname, GLint *iparams) AliasExport("gl4es_glLightiv");
void glLightModeli(GLenum pname, GLint param) AliasExport("gl4es_glLightModeli");
void glLightModeliv(GLenum pname, GLint *iparams) AliasExport("gl4es_glLightModeliv");
void glMateriali(GLenum face, GLenum pname, GLint param) AliasExport("gl4es_glMateriali");
void glMaterialiv(GLenum face, GLenum pname, GLint *param) AliasExport("gl4es_glMaterialiv");
void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far) AliasExport("gl4es_glOrtho");
void glGetMaterialiv(GLenum face, GLenum pname, GLint * params) AliasExport("gl4es_glGetMaterialiv");
void glGetLightiv(GLenum light, GLenum pname, GLint * params) AliasExport("gl4es_glGetLightiv");
void glGetClipPlane(GLenum plane, GLdouble *equation) AliasExport("gl4es_glGetClipPlane");
void glDrawRangeElements(GLenum mode,GLuint start,GLuint end,GLsizei count,GLenum type,const void *indices) AliasExport("gl4es_glDrawRangeElements");
void glColor3f(GLfloat r, GLfloat g, GLfloat b) AliasExport("gl4es_glColor3f");
void glColor3fv(GLfloat *c) AliasExport("gl4es_glColor3fv");
void glColor4fv(GLfloat *c) AliasExport("gl4es_glColor4fv");
void glIndexfv(const GLfloat *c) AliasExport("gl4es_glIndexfv");
void glSecondaryColor3fv(const GLfloat *v) AliasExport("gl4es_glSecondaryColor3fv");
void glRasterPos2f(GLfloat x, GLfloat y) AliasExport("gl4es_glRasterPos2f");
void glRasterPos2fv(const GLfloat *v) AliasExport("gl4es_glRasterPos2fv");
void glRasterPos3fv(const GLfloat *v) AliasExport("gl4es_glRasterPos3fv");
void glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) AliasExport("gl4es_glRasterPos4f");
void glRasterPos4fv(const GLfloat *v) AliasExport("gl4es_glRasterPos4fv");
void glWindowPos2f(GLfloat x, GLfloat y) AliasExport("gl4es_glWindowPos2f");
void glWindowPos2fv(const GLfloat *v) AliasExport("gl4es_glWindowPos2fv");
void glWindowPos3fv(const GLfloat *v) AliasExport("gl4es_glWindowPos3fv");
void glPixelStoref(GLenum pname, GLfloat param) AliasExport("gl4es_glPixelStoref");
void glGetTexGendv(GLenum coord,GLenum pname,GLdouble *params) AliasExport("gl4es_glGetTexGendv");
void glGetTexGeniv(GLenum coord,GLenum pname,GLint *params) AliasExport("gl4es_glGetTexGeniv");
void glPixelTransferi(GLenum pname, GLint param) AliasExport("gl4es_glPixelTransferi");
void glEvalCoord1d(GLdouble u) AliasExport("gl4es_glEvalCoord1d");
void glEvalCoord1dv(GLdouble *v) AliasExport("gl4es_glEvalCoord1dv");
void glEvalCoord1fv(GLfloat *v) AliasExport("gl4es_glEvalCoord1fv");
void glEvalCoord2d(GLdouble u, GLdouble v) AliasExport("gl4es_glEvalCoord2d");
void glEvalCoord2dv(GLdouble *v) AliasExport("gl4es_glEvalCoord2dv");
void glEvalCoord2fv(GLfloat *v) AliasExport("gl4es_glEvalCoord2fv");
void glMapGrid1d(GLint un, GLdouble u1, GLdouble u2) AliasExport("gl4es_glMapGrid1d");
void glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2) AliasExport("gl4es_glMapGrid2d");
void glLoadMatrixd(const GLdouble *m) AliasExport("gl4es_glLoadMatrixd");
void glMultMatrixd(const GLdouble *m) AliasExport("gl4es_glMultMatrixd");
void glNormal3fv(GLfloat *v) AliasExport("gl4es_glNormal3fv");

// rect
#define GL_RECT(suffix, type)                                \
    void glRect##suffix(type x1, type y1, type x2, type y2) AliasExport("gl4es_glRect" #suffix); \
    void glRect##suffix##v(const type *v)AliasExport("gl4es_glRect" #suffix "v");

GL_RECT(d, GLdouble)
GL_RECT(f, GLfloat)
GL_RECT(i, GLint)
GL_RECT(s, GLshort)
#undef GL_RECT

void glTexCoord1f(GLfloat s) AliasExport("gl4es_glTexCoord1f");
void glTexCoord1fv(GLfloat *t) AliasExport("gl4es_glTexCoord1fv");
void glTexCoord2f(GLfloat s, GLfloat t) AliasExport("gl4es_glTexCoord2f");
void glTexCoord2fv(GLfloat *t) AliasExport("gl4es_glTexCoord2fv");
void glTexCoord3f(GLfloat s, GLfloat t, GLfloat r) AliasExport("gl4es_glTexCoord3f");
void glTexCoord3fv(GLfloat *t) AliasExport("gl4es_glTexCoord3fv");
void glTexCoord4fv(GLfloat *t) AliasExport("gl4es_glTexCoord4fv");
void glMultiTexCoord1f(GLenum target, GLfloat s) AliasExport("gl4es_glMultiTexCoord1f");
void glMultiTexCoord1fv(GLenum target, GLfloat *t) AliasExport("gl4es_glMultiTexCoord1fv");
void glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) AliasExport("gl4es_glMultiTexCoord2f");
void glMultiTexCoord2fv(GLenum target, GLfloat *t) AliasExport("gl4es_glMultiTexCoord2fv");
void glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r) AliasExport("gl4es_glMultiTexCoord3f");
void glMultiTexCoord3fv(GLenum target, GLfloat *t) AliasExport("gl4es_glMultiTexCoord3fv");
void glMultiTexCoord4fv(GLenum target, GLfloat *t) AliasExport("gl4es_glMultiTexCoord4fv");
void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params) AliasExport("gl4es_glGetTexLevelParameterfv");
void glTexGend(GLenum coord, GLenum pname, GLdouble param) AliasExport("gl4es_glTexGend");
void glTexGenf(GLenum coord, GLenum pname, GLfloat param) AliasExport("gl4es_glTexGenf");
void glTexGendv(GLenum coord, GLenum pname, const GLdouble *params) AliasExport("gl4es_glTexGendv");
void glTexGeniv(GLenum coord, GLenum pname, const GLint *params) AliasExport("gl4es_glTexGeniv");
void glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) AliasExport("gl4es_glRotated");
void glScaled(GLdouble x, GLdouble y, GLdouble z) AliasExport("gl4es_glScaled");
void glTranslated(GLdouble x, GLdouble y, GLdouble z) AliasExport("gl4es_glTranslated");
void glVertex2f(GLfloat x, GLfloat y) AliasExport("gl4es_glVertex2f");
void glVertex2fv(GLfloat *v) AliasExport("gl4es_glVertex2fv");
void glVertex3f(GLfloat r, GLfloat g, GLfloat b) AliasExport("gl4es_glVertex3f");
void glVertex3fv(GLfloat *v) AliasExport("gl4es_glVertex3fv");
void glVertex4fv(GLfloat *v) AliasExport("gl4es_glVertex4fv");

// basic thunking

#define THUNK(suffix, type)                                \
void glColor3##suffix##v(const type *v)                 AliasExport("gl4es_glColor3"#suffix "v"); \
void glColor3##suffix(type r, type g, type b)           AliasExport("gl4es_glColor3"#suffix); \
void glColor4##suffix##v(const type *v)                 AliasExport("gl4es_glColor4"#suffix "v"); \
void glColor4##suffix(type r, type g, type b, type a)   AliasExport("gl4es_glColor4"#suffix); \
void glSecondaryColor3##suffix##v(const type *v)        AliasExport("gl4es_glSecondaryColor3"#suffix "v"); \
void glSecondaryColor3##suffix(type r, type g, type b)  AliasExport("gl4es_glSecondaryColor3"#suffix); \
void glIndex##suffix##v(const type *c)                  AliasExport("gl4es_glIndex"#suffix"v"); \
void glIndex##suffix(type c)                            AliasExport("gl4es_glIndex"#suffix); \
void glNormal3##suffix##v(const type *v)                AliasExport("gl4es_glNormal3"#suffix"v"); \
void glNormal3##suffix(type x, type y, type z)          AliasExport("gl4es_glNormal3"#suffix); \
void glRasterPos2##suffix##v(type *v)                   AliasExport("gl4es_glRasterPos2"#suffix"v"); \
void glRasterPos2##suffix(type x, type y)               AliasExport("gl4es_glRasterPos2"#suffix); \
void glRasterPos3##suffix##v(type *v)                   AliasExport("gl4es_glRasterPos3"#suffix"v"); \
void glRasterPos3##suffix(type x, type y, type z)       AliasExport("gl4es_glRasterPos3"#suffix); \
void glRasterPos4##suffix##v(type *v)                   AliasExport("gl4es_glRasterPos4"#suffix"v"); \
void glRasterPos4##suffix(type x, type y, type z, type w)AliasExport("gl4es_glRasterPos4"#suffix); \
void glWindowPos2##suffix##v(type *v)                   AliasExport("gl4es_glWindowPos2"#suffix"v"); \
void glWindowPos2##suffix(type x, type y)               AliasExport("gl4es_glWindowPos2"#suffix); \
void glWindowPos3##suffix##v(type *v)                   AliasExport("gl4es_glWindowPos3"#suffix"v"); \
void glWindowPos3##suffix(type x, type y, type z)       AliasExport("gl4es_glWindowPos3"#suffix); \
void glVertex2##suffix##v(type *v)                      AliasExport("gl4es_glVertex2"#suffix"v"); \
void glVertex2##suffix(type x, type y)                  AliasExport("gl4es_glVertex2"#suffix); \
void glVertex3##suffix##v(type *v)                      AliasExport("gl4es_glVertex3"#suffix"v"); \
void glVertex3##suffix(type x, type y, type z)          AliasExport("gl4es_glVertex3"#suffix); \
void glVertex4##suffix(type x, type y, type z, type w)  AliasExport("gl4es_glVertex4"#suffix); \
void glVertex4##suffix##v(type *v)                      AliasExport("gl4es_glVertex4"#suffix"v"); \
void glTexCoord1##suffix(type s)                        AliasExport("gl4es_glTexCoord1"#suffix); \
void glTexCoord1##suffix##v(type *t)                    AliasExport("gl4es_glTexCoord1"#suffix"v"); \
void glTexCoord2##suffix(type s, type t)                AliasExport("gl4es_glTexCoord2"#suffix); \
void glTexCoord2##suffix##v(type *t)                    AliasExport("gl4es_glTexCoord2"#suffix"v"); \
void glTexCoord3##suffix(type s, type t, type r)        AliasExport("gl4es_glTexCoord3"#suffix); \
void glTexCoord3##suffix##v(type *t)                    AliasExport("gl4es_glTexCoord3"#suffix"v"); \
void glTexCoord4##suffix(type s, type t, type r, type q)AliasExport("gl4es_glTexCoord4"#suffix); \
void glTexCoord4##suffix##v(type *t)                    AliasExport("gl4es_glTexCoord4"#suffix"v"); \
void glMultiTexCoord1##suffix(GLenum target, type s)    AliasExport("gl4es_glMultiTexCoord1"#suffix); \
void glMultiTexCoord1##suffix##v(GLenum target, type *t)AliasExport("gl4es_glMultiTexCoord1"#suffix"v"); \
void glMultiTexCoord2##suffix(GLenum target, type s, type t)        AliasExport("gl4es_glMultiTexCoord2"#suffix); \
void glMultiTexCoord2##suffix##v(GLenum target, type *t)            AliasExport("gl4es_glMultiTexCoord2"#suffix"v"); \
void glMultiTexCoord3##suffix(GLenum target, type s, type t, type r)AliasExport("gl4es_glMultiTexCoord3"#suffix); \
void glMultiTexCoord3##suffix##v(GLenum target, type *t)            AliasExport("gl4es_glMultiTexCoord3"#suffix"v"); \
void glMultiTexCoord4##suffix(GLenum target, type s, type t, type r, type q) AliasExport("gl4es_glMultiTexCoord4"#suffix); \
void glMultiTexCoord4##suffix##v(GLenum target, type *t)            AliasExport("gl4es_glMultiTexCoord4"#suffix"v"); \
void glMultiTexCoord1##suffix##ARB(GLenum target, type s)           AliasExport("gl4es_glMultiTexCoord1"#suffix); \
void glMultiTexCoord1##suffix##vARB(GLenum target, type *t)         AliasExport("gl4es_glMultiTexCoord1"#suffix"v"); \
void glMultiTexCoord2##suffix##ARB(GLenum target, type s, type t)   AliasExport("gl4es_glMultiTexCoord2"#suffix); \
void glMultiTexCoord2##suffix##vARB(GLenum target, type *t)         AliasExport("gl4es_glMultiTexCoord2"#suffix"v"); \
void glMultiTexCoord3##suffix##ARB(GLenum target, type s, type t, type r)  AliasExport("gl4es_glMultiTexCoord3"#suffix); \
void glMultiTexCoord3##suffix##vARB(GLenum target, type *t)         AliasExport("gl4es_glMultiTexCoord3"#suffix"v"); \
void glMultiTexCoord4##suffix##ARB(GLenum target, type s, type t, type r, type q) AliasExport("gl4es_glMultiTexCoord4"#suffix); \
void glMultiTexCoord4##suffix##vARB(GLenum target, type *t)AliasExport("gl4es_glMultiTexCoord4"#suffix"v");

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

void glMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t) AliasExport("gl4es_glMultiTexCoord2f");
void glMultiTexCoord3fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r) AliasExport("gl4es_glMultiTexCoord3f");
void glMultiTexCoord2fvARB(GLenum target, GLfloat *t) AliasExport("gl4es_glMultiTexCoord2fv");
void glMultiTexCoord3fvARB(GLenum target, GLfloat *t) AliasExport("gl4es_glMultiTexCoord3fv");
void glMultiTexCoord4fvARB(GLenum target, GLfloat *t) AliasExport("gl4es_glMultiTexCoord4fv");
void glDrawRangeElementsEXT(GLenum mode,GLuint start,GLuint end,GLsizei count,GLenum type,const void *indices) AliasExport("gl4es_glDrawRangeElements");
