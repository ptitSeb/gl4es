#include "gl.h"
#include <limits.h>

#define constDoubleToFloat(a, size) \
    GLfloat s[size];                \
    int i;                          \
    for (i = 0; i < size; i++) {    \
        s[i] = a[i];                \
    }

// naive wrappers

#ifdef USE_ES2
void glCompileShaderARB(GLuint shader) {
    glCompileShader(shader);
    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE) {
        GLint log_length;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &log_length);
        GLchar *log = malloc(sizeof(GLchar) * log_length);
        glGetShaderInfoLog(shader, log_length, NULL, log);
        printf("Shader compile failed: %s\n", log);
        free(log);
    }
}
GLuint glCreateShaderObjectARB(GLenum shaderType) {
    return glCreateShader(shaderType);
}
void glShaderSourceARB(GLuint shader, GLsizei count, const GLchar **string, const GLint *length) {
    glShaderSource(shader, count, string, length);
}
void glGetObjectParameterivARB(GLuint shader, GLenum pname, GLint *params) {
    glGetShaderiv(shader, pname, params);
}
#endif

void glActiveTextureARB(GLenum texture) {
    glActiveTexture(texture);
}
void glClearDepth(GLdouble depth) {
    glClearDepthf(depth);
}
void glClientActiveTextureARB(GLenum texture) {
#ifndef USE_ES2
    glClientActiveTexture(texture);
#endif
}
void glClipPlane(GLenum plane, const GLdouble *equation) {
    constDoubleToFloat(equation, 4);
    glClipPlanef(plane, s);
}
void glDepthRange(GLdouble nearVal, GLdouble farVal) {
    glDepthRangef(nearVal, farVal);
}
void glFogi(GLenum pname, GLint param) {
    glFogf(pname, param);
}
void glFogiv(GLenum pname, GLint *iparams) {
    switch (pname) {
        case GL_FOG_DENSITY:
        case GL_FOG_START:
        case GL_FOG_END:
        case GL_FOG_INDEX: {
            glFogf(pname, *iparams);
            break;
        }
        case GL_FOG_MODE:
        case GL_FOG_COLOR: {
            GLfloat params[4];
            for (int i = 0; i < 4; i++) {
                params[i] = iparams[i];
            }
            glFogfv(pname, params);
            break;
        }
    }
}
void glGetTexGendv(GLenum coord,GLenum pname,GLdouble *params) {
	GLfloat fparams[4];
	glGetTexGenfv(coord, pname, fparams);
	if (pname==GL_TEXTURE_GEN_MODE) *params=fparams[0];
	else for (int i=0; i<4; i++) params[i]=fparams[i];
}
void glGetTexGeniv(GLenum coord,GLenum pname,GLint *params) {
	GLfloat fparams[4];
	glGetTexGenfv(coord, pname, fparams);
	if (pname==GL_TEXTURE_GEN_MODE) *params=fparams[0];
	else for (int i=0; i<4; i++) params[i]=fparams[i];
}
void glGetMaterialiv(GLenum face, GLenum pname, GLint * params) {
	GLfloat fparams[4];
	glGetMaterialfv(face, pname, fparams);
	if (pname==GL_SHININESS) *params=fparams[0];
	else for (int i=0; i<4; i++) params[i]=fparams[i];
}
void glGetLightiv(GLenum light, GLenum pname, GLint * params) {
	GLfloat fparams[4];
	glGetLightfv(light, pname, fparams);
	int n=4;
	if (pname==GL_SPOT_EXPONENT) n=1;
	if (pname==GL_SPOT_CUTOFF) n=1;
	if (pname==GL_SPOT_EXPONENT) n=1;
	if (pname==GL_SPOT_DIRECTION) n=3;
	else for (int i=0; i<n; i++) params[i]=fparams[i];
}
void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params) {
	GLint iparams;
	glGetTexLevelParameteriv(target, level, pname, &iparams);
	(*params)=iparams;
	return;
}
void glGetClipPlane(GLenum plane, GLdouble *equation) {
	GLfloat fparams[4];
	glGetClipPlanef(plane, fparams);
	for (int i=0; i<4; i++) equation[i]=fparams[i];
}

void glFrustum(GLdouble left, GLdouble right, GLdouble bottom,
             GLdouble top, GLdouble near, GLdouble far) {
    glFrustumf(left, right, bottom, top, near, far);
}
void glPixelStoref(GLenum pname, GLfloat param) {
    glPixelStorei(pname, param);
}
void glLighti(GLenum light, GLenum pname, GLint param) {
    glLightf(light, pname, param);
}
void glPixelTransferi(GLenum pname, GLint param) {
	glPixelTransferf(pname, param);	
}

void glLightiv(GLenum light, GLenum pname, GLint *iparams) {
    switch (pname) {
        case GL_AMBIENT:
        case GL_DIFFUSE:
        case GL_SPECULAR:
        case GL_POSITION: {
            GLfloat params[4];
            for (int i = 0; i < 4; i++) {
                params[i] = iparams[i];
            }
            glLightfv(light, pname, params);
            break;
        }
        case GL_SPOT_DIRECTION: {
            GLfloat params[4];
            for (int i = 0; i < 4; i++) {
                params[i] = iparams[i];
            }
            glLightfv(light, pname, params);
            break;
        }
        case GL_SPOT_EXPONENT:
        case GL_SPOT_CUTOFF:
        case GL_CONSTANT_ATTENUATION:
        case GL_LINEAR_ATTENUATION:
        case GL_QUADRATIC_ATTENUATION: {
            glLightf(light, pname, *iparams);
            break;
        }
    }
}
#ifndef USE_ES2
void glLightModeli(GLenum pname, GLint param) {
    glLightModelf(pname, param);
}
void glLightModeliv(GLenum pname, GLint *iparams) {
    switch (pname) {
        case GL_LIGHT_MODEL_AMBIENT: {
            GLfloat params[4];
            for (int i = 0; i < 4; i++) {
                params[i] = iparams[i];
            }
            glLightModelfv(pname, params);
            break;
        }
        case GL_LIGHT_MODEL_LOCAL_VIEWER:
        case GL_LIGHT_MODEL_TWO_SIDE: {
            glLightModelf(pname, *iparams);
            break;
        }
    }
}
#endif
void glMateriali(GLenum face, GLenum pname, GLint param) {
    glMaterialf(face, pname, param);
}
void glMaterialiv(GLenum face, GLenum pname, GLint *iparams) {
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
            glMaterialfv(face, pname, params);
            break;
        }
		case GL_SHININESS:
		{
            GLfloat params[2];
            for (int i = 0; i < 2; i++) {
                params[i] = iparams[i];
            }
            glMaterialfv(face, pname, params);
            break;
        }
        case GL_AMBIENT_AND_DIFFUSE: {
            glMaterialf(face, pname, *iparams);
            break;
        }
		case GL_COLOR_INDEXES:
		{
            GLfloat params[3];
            for (int i = 0; i < 3; i++) {
                params[i] = iparams[i];
            }
            glMaterialfv(face, pname, params);
            break;
        }
    }
}

/*
void glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) {
    glMultiTexCoord4f(target, s, t, 0.0f, 1.0f);
}
* */
void glMultiTexCoord1f(GLenum target, GLfloat s) {
     glMultiTexCoord2f(target, s, 0);
}
void glMultiTexCoord1fv(GLenum target, GLfloat *t) {
     glMultiTexCoord2f(target, t[0], 0);
}
void glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r) {
     glMultiTexCoord2f(target, s, t);
}
void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
     glMultiTexCoord2f(target, s, t);
}
void glMultiTexCoord2fv(GLenum target, GLfloat *t) {
     glMultiTexCoord2f(target, t[0], t[1]);
}
void glMultiTexCoord3fv(GLenum target, GLfloat *t) {
     glMultiTexCoord2f(target, t[0], t[1]);
}
void glMultiTexCoord4fv(GLenum target, GLfloat *t) {
     glMultiTexCoord2f(target, t[0], t[1]);
}
void glMultiTexCoord1fARB(GLenum target, GLfloat s) {
     glMultiTexCoord2f(target, s, 0);
}
void glMultiTexCoord1fvARB(GLenum target, GLfloat *t) {
     glMultiTexCoord2f(target, t[0], 0);
}
void glMultiTexCoord2fARB(GLenum target, GLfloat s, GLfloat t) {
     glMultiTexCoord2f(target, s, t);
}
void glMultiTexCoord3fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r) {
     glMultiTexCoord2f(target, s, t);
}
void glMultiTexCoord4fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
     glMultiTexCoord2f(target, s, t);
}
void glMultiTexCoord2fvARB(GLenum target, GLfloat *t) {
     glMultiTexCoord2f(target, t[0], t[1]);
}
void glMultiTexCoord3fvARB(GLenum target, GLfloat *t) {
     glMultiTexCoord2f(target, t[0], t[1]);
}
void glMultiTexCoord4fvARB(GLenum target, GLfloat *t) {
     glMultiTexCoord2f(target, t[0], t[1]);
}
/*
void glBlendFuncSeparateEXT (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
	glBlendFuncSeparate (sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
*/
void glOrtho(GLdouble left, GLdouble right, GLdouble bottom,
             GLdouble top, GLdouble near, GLdouble far) {
    glOrthof(left, right, bottom, top, near, far);
}

// OES wrappers

void glClearDepthfOES(GLfloat depth) {
    glClearDepthf(depth);
}
void glClipPlanefOES(GLenum plane, const GLfloat *equation) {
    glClipPlanef(plane, equation);
}
void glDepthRangefOES(GLclampf near, GLclampf far) {
    glDepthRangef(near, far);
}
void glFrustumfOES(GLfloat left, GLfloat right, GLfloat bottom,
                   GLfloat top, GLfloat near, GLfloat far) {
    glFrustumf(left, right, bottom, top, near, far);
}
void glGetClipPlanefOES(GLenum pname, GLfloat equation[4]) {
    glGetClipPlanef(pname, equation);
}
void glOrthofOES(GLfloat left, GLfloat right, GLfloat bottom,
                 GLfloat top, GLfloat near, GLfloat far) {
    glOrthof(left, right, bottom, top, near, far);
}

// glRect

#define GL_RECT(suffix, type)                                 \
    void glRect##suffix(type x1, type y1, type x2, type y2) { \
        glBegin(GL_POLYGON);                                  \
        glVertex2##suffix(x1, y1);                            \
        glVertex2##suffix(x2, y1);                            \
        glVertex2##suffix(x2, y2);                            \
        glVertex2##suffix(x1, y2);                            \
		glEnd();											  \
    }                                                         \
    void glRect##suffix##v(const type *v) {                   \
        glRect##suffix(v[0], v[1], v[2], v[3]);               \
    }

GL_RECT(d, GLdouble)
GL_RECT(f, GLfloat)
GL_RECT(i, GLint)
GL_RECT(s, GLshort)
#undef GL_RECT

// basic thunking

#define THUNK(suffix, type, max)                            \
/* colors */                                                \
void glColor3##suffix(type r, type g, type b) {             \
    glColor4f(r/max, g/max, b/max, 1.0f);                   \
}                                                           \
void glColor4##suffix(type r, type g, type b, type a) {     \
    glColor4f(r/max, g/max, b/max, a/max);                  \
}                                                           \
void glColor3##suffix##v(const type *v) {                   \
    glColor4f(v[0]/max, v[1]/max, v[2]/max, 1.0f);          \
}                                                           \
void glColor4##suffix##v(const type *v) {                   \
    glColor4f(v[0]/max, v[1]/max, v[2]/max, v[3]/max);      \
}                                                           \
void glSecondaryColor3##suffix(type r, type g, type b) {    \
    glSecondaryColor3f(r/max, g/max, b/max);                \
}                                                           \
void glSecondaryColor3##suffix##v(const type *v) {          \
    glSecondaryColor3f(v[0]/max, v[1]/max, v[2]/max);       \
}                                                           \
/* index */                                                 \
void glIndex##suffix(type c) {                              \
    glIndexf(c);                                            \
}                                                           \
void glIndex##suffix##v(const type *c) {                    \
    glIndexf(c[0]);                                         \
}                                                           \
/* normal */                                                \
void glNormal3##suffix(type x, type y, type z) {            \
    glNormal3f(x, y, z);                                    \
}                                                           \
void glNormal3##suffix##v(const type *v) {                  \
    glNormal3f(v[0], v[1], v[2]);                           \
}                                                           \
/* raster */                                                \
void glRasterPos2##suffix(type x, type y) {                 \
    glRasterPos3f(x, y, 0);                                 \
}                                                           \
void glRasterPos2##suffix##v(type *v) {                     \
    glRasterPos3f(v[0], v[1], 0);                           \
}                                                           \
void glRasterPos3##suffix(type x, type y, type z) {         \
    glRasterPos3f(x, y, z);                                 \
}                                                           \
void glRasterPos3##suffix##v(type *v) {                     \
    glRasterPos3f(v[0], v[1], v[2]);                        \
}                                                           \
void glRasterPos4##suffix(type x, type y, type z, type w) { \
    glRasterPos4f(x, y, z, w);                              \
}                                                           \
void glRasterPos4##suffix##v(type *v) {                     \
    glRasterPos4f(v[0], v[1], v[2], v[3]);                  \
}                                                           \
void glWindowPos2##suffix(type x, type y) {                 \
    glWindowPos3f(x, y, 0);                                 \
}                                                           \
void glWindowPos2##suffix##v(type *v) {                     \
    glWindowPos3f(v[0], v[1], 0);                           \
}                                                           \
void glWindowPos3##suffix(type x, type y, type z) {         \
    glWindowPos3f(x, y, z);                                 \
}                                                           \
void glWindowPos3##suffix##v(type *v) {                     \
    glWindowPos3f(v[0], v[1], v[2]);                        \
}                                                           \
/* vertex */                                                \
void glVertex2##suffix(type x, type y) {                    \
    glVertex2f(x, y);                                       \
}                                                           \
void glVertex2##suffix##v(type *v) {                        \
    glVertex2f(v[0], v[1]);                                 \
}                                                           \
void glVertex3##suffix(type x, type y, type z) {            \
    glVertex3f(x, y, z);                                    \
}                                                           \
void glVertex3##suffix##v(type *v) {                        \
    glVertex3f(v[0], v[1], v[2]);                           \
}                                                           \
void glVertex4##suffix(type r, type g, type b, type w) {    \
    glVertex4f(r, g, b, w);                                 \
}                                                           \
void glVertex4##suffix##v(type *v) {                        \
    glVertex4f(v[0], v[1], v[2], v[3]);                     \
}                                                           \
/* texture */                                               \
void glTexCoord1##suffix(type s) {                          \
    glTexCoord2f(s, 0);                                     \
}                                                           \
void glTexCoord1##suffix##v(type *t) {                      \
    glTexCoord2f(t[0], 0);                                  \
}                                                           \
void glTexCoord2##suffix(type s, type t) {                  \
    glTexCoord2f(s, t);                                     \
}                                                           \
void glTexCoord2##suffix##v(type *t) {                      \
    glTexCoord2f(t[0], t[1]);                               \
}                                                           \
void glTexCoord3##suffix(type s, type t, type r) {          \
    glTexCoord2f(s, t);                                     \
}                                                           \
void glTexCoord3##suffix##v(type *t) {                      \
    glTexCoord2f(t[0], t[1]);                               \
}                                                           \
void glTexCoord4##suffix(type s, type t, type r, type q) {  \
    glTexCoord2f(s, t);                                     \
}                                                           \
void glTexCoord4##suffix##v(type *t) {                      \
    glTexCoord2f(t[0], t[1]);                               \
}															\
/* multi-texture */                                         \
void glMultiTexCoord1##suffix(GLenum target, type s) {      \
    glMultiTexCoord2f(target, s, 0);                        \
}                                                           \
void glMultiTexCoord1##suffix##v(GLenum target, type *t) {  \
    glMultiTexCoord2f(target, t[0], 0);                    \
}                                                           \
void glMultiTexCoord2##suffix(GLenum target, type s, type t) {           \
    glMultiTexCoord2f(target, s, t);                                     \
}                                                                        \
void glMultiTexCoord2##suffix##v(GLenum target, type *t) {               \
    glMultiTexCoord2f(target, t[0], t[1]);                               \
}                                                                        \
void glMultiTexCoord3##suffix(GLenum target, type s, type t, type r) {   \
    glMultiTexCoord2f(target, s, t);                                     \
}                                                                        \
void glMultiTexCoord3##suffix##v(GLenum target, type *t) {               \
    glMultiTexCoord2f(target, t[0], t[1]);                               \
}                                                                        \
void glMultiTexCoord4##suffix(GLenum target, type s, type t, type r, type q) {  \
    glMultiTexCoord2f(target, s, t);                                     \
}                                                                        \
void glMultiTexCoord4##suffix##v(GLenum target, type *t) {               \
    glMultiTexCoord2f(target, t[0], t[1]);                               \
}                                                                        \
/* multi-texture ARB */                                                  \
void glMultiTexCoord1##suffix##ARB(GLenum target, type s) {              \
    glMultiTexCoord2f(target, s, 0);                                     \
}                                                                        \
void glMultiTexCoord1##suffix##vARB(GLenum target, type *t) {            \
    glMultiTexCoord2f(target, t[0], 0);                                  \
}                                                                        \
void glMultiTexCoord2##suffix##ARB(GLenum target, type s, type t) {      \
    glMultiTexCoord2f(target, s, t);                                     \
}                                                                        \
void glMultiTexCoord2##suffix##vARB(GLenum target, type *t) {            \
    glMultiTexCoord2f(target, t[0], t[1]);                               \
}                                                                        \
void glMultiTexCoord3##suffix##ARB(GLenum target, type s, type t, type r) {   \
    glMultiTexCoord2f(target, s, t);                                     \
}                                                                        \
void glMultiTexCoord3##suffix##vARB(GLenum target, type *t) {            \
    glMultiTexCoord2f(target, t[0], t[1]);                               \
}                                                                        \
void glMultiTexCoord4##suffix##ARB(GLenum target, type s, type t, type r, type q) {  \
    glMultiTexCoord2f(target, s, t);                                     \
}                                                                        \
void glMultiTexCoord4##suffix##vARB(GLenum target, type *t) {            \
    glMultiTexCoord2f(target, t[0], t[1]);                               \
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
void glGet##suffix##v(GLenum pname, type *params) {      \
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
    glGetFloatv(pname, p);		                         \
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
void glColor3f(GLfloat r, GLfloat g, GLfloat b) {
    glColor4f(r, g, b, 1.0f);
}
void glColor3fv(GLfloat *c) {
    glColor4f(c[0], c[1], c[2], 1.0f);
}
void glColor4fv(GLfloat *c) {
    glColor4f(c[0], c[1], c[2], c[3]);
}
void glIndexfv(const GLfloat *c) {
    glIndexf(*c);
}
void glSecondaryColor3fv(const GLfloat *v) {
    glSecondaryColor3f(v[0], v[1], v[2]);
}

// raster
void glRasterPos2f(GLfloat x, GLfloat y) {
    glRasterPos3f(x, y, 0.0f);
}
void glRasterPos2fv(const GLfloat *v) {
    glRasterPos3f(v[0], v[1], 0.0f);
}
void glRasterPos3fv(const GLfloat *v) {
    glRasterPos3f(v[0], v[1], v[2]);
}
void glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    glRasterPos3f(x/w, y/w, z/w);
}
void glRasterPos4fv(const GLfloat *v) {
    glRasterPos4f(v[0], v[1], v[2], v[3]);
}
void glWindowPos2f(GLfloat x, GLfloat y) {
    glWindowPos3f(x, y, 0.0f);
}
void glWindowPos2fv(const GLfloat *v) {
    glWindowPos3f(v[0], v[1], 0.0f);
}
void glWindowPos3fv(const GLfloat *v) {
    glWindowPos3f(v[0], v[1], v[2]);
}

// eval
void glEvalCoord1d(GLdouble u) {
    glEvalCoord1f(u);
}

void glEvalCoord2d(GLdouble u, GLdouble v) {
    glEvalCoord2f(u, v);
}

void glEvalCoord1fv(GLfloat *v) {
    glEvalCoord1f(v[0]);
}

void glEvalCoord1dv(GLdouble *v) {
    glEvalCoord1d(v[0]);
}

void glEvalCoord2fv(GLfloat *v) {
    glEvalCoord2f(v[0], v[1]);
}

void glEvalCoord2dv(GLdouble *v) {
    glEvalCoord2d(v[0], v[1]);
}

void glMapGrid1d(GLint un, GLdouble u1, GLdouble u2) {
    glMapGrid1f(un, u1, u2);
}

void glMapGrid2d(GLint un, GLdouble u1, GLdouble u2,
                 GLint vn, GLdouble v1, GLdouble v2) {
    glMapGrid2f(un, u1, u2, vn, v1, v2);
}

// matrix
void glLoadMatrixd(const GLdouble *m) {
    constDoubleToFloat(m, 16);
    glLoadMatrixf(s);
}
void glMultMatrixd(const GLdouble *m) {
    constDoubleToFloat(m, 16);
    glMultMatrixf(s);
}

// normal
void glNormal3fv(GLfloat *v) {
    glNormal3f(v[0], v[1], v[2]);
}

// textures
void glTexCoord1f(GLfloat s) {
    glTexCoord2f(s, 0);
}
void glTexCoord1fv(GLfloat *t) {
    glTexCoord2f(t[0], 0);
}
void glTexCoord2fv(GLfloat *t) {
    glTexCoord2f(t[0], t[1]);
}
void glTexCoord3f(GLfloat s, GLfloat t, GLfloat r) {
    glTexCoord2f(s, t);
}
void glTexCoord3fv(GLfloat *t) {
    glTexCoord2f(t[0], t[1]);
}
void glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    glTexCoord2f(s, t);
}
void glTexCoord4fv(GLfloat *t) {
    glTexCoord2f(t[0], t[1]);
}

// texgen
void glTexGend(GLenum coord, GLenum pname, GLdouble param) {
    glTexGenf(coord, pname, param);
}
void glTexGenf(GLenum coord, GLenum pname, GLfloat param) {
    GLfloat params[4] = {0,0,0,0};
    params[0] = param;
    glTexGenfv(coord, pname, params);
}
void glTexGendv(GLenum coord, GLenum pname, const GLdouble *params) {
    GLfloat tmp[4];
    tmp[0]=params[0];
    if ((pname==GL_OBJECT_PLANE) || (pname==GL_EYE_PLANE))
		for (int i=1; i<4; i++)
			tmp[i]=params[i];
    glTexGenfv(coord, pname, tmp);
}
void glTexGeniv(GLenum coord, GLenum pname, const GLint *params) {
    GLfloat tmp[4];
    tmp[0]=params[0];
    if ((pname==GL_OBJECT_PLANE) || (pname==GL_EYE_PLANE))
		for (int i=1; i<4; i++)
			tmp[i]=params[i];
    glTexGenfv(coord, pname, tmp);
}

// transforms
void glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
    glRotatef(angle, x, y, z);
}
void glScaled(GLdouble x, GLdouble y, GLdouble z) {
    glScalef(x, y, z);
}
void glTranslated(GLdouble x, GLdouble y, GLdouble z) {
    glTranslatef(x, y, z);
}

// vertex
void glVertex2f(GLfloat x, GLfloat y) {
    glVertex3f(x, y, 0);
}
void glVertex2fv(GLfloat *v) {
    glVertex3f(v[0], v[1], 0);
}
void glVertex3fv(GLfloat *v) {
    glVertex3f(v[0], v[1], v[2]);
}
void glVertex4f(GLfloat r, GLfloat g, GLfloat b, GLfloat w) {
    glVertex3f(r/w, g/w, b/w);
}
void glVertex4fv(GLfloat *v) {
    glVertex3f(v[0]/v[3], v[1]/v[3], v[2]/v[3]);
}

void glDrawRangeElements(GLenum mode,GLuint start,GLuint end,GLsizei count,GLenum type,const void *indices) {
//printf("glDrawRangeElements(0x%04X, %i, %i, %i, 0x%04X, @%p), inlist=%i\n", mode, start, end, count, type, indices, (state.list.active)?1:0);
	GLushort *newinds = (GLushort*)malloc(sizeof(GLushort)*count);
	int newcount=0;
    glbuffer_t *elements = state.buffers.elements;
    state.buffers.elements = NULL;
    
	uintptr_t ptr = (uintptr_t)indices;
    if (elements)
        ptr+=(uintptr_t)elements->data;
    
	for (int i=0; i<count; i++) {
		GL_TYPE_SWITCH(indice, ptr, type,
		if ((indice[i]>=start) && (indice[i]<=end))
			newinds[newcount++]=indice[i];
		, );
	}
	glDrawElements(mode, newcount, GL_UNSIGNED_SHORT, newinds);
	free(newinds);
    
    state.buffers.elements = elements;
}

void glDrawRangeElementsEXT(GLenum mode,GLuint start,GLuint end,GLsizei count,GLenum type,const void *indices) {
    glDrawRangeElements(mode, start, end, count, type, indices);
}
void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) {
	// ignore buf is better than nothing...
	// TODO: handle buf
	glBlendEquationSeparate(modeRGB, modeAlpha);
}

void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
	// ignore buf is better than nothing..
	// TODO: handle buf
	glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
}
#undef constDoubleToFloat
