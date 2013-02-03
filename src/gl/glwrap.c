#include <gl.h>

// naive wrappers

void glActiveTextureARB(GLenum texture) {
    glActiveTexture(texture);
}

void glClearDepth(GLdouble depth) {
    glClearDepthf(depth);
}

void glDepthRange(GLdouble nearVal, GLdouble farVal) {
    glDepthRangef(nearVal, farVal);
}

void glFogi(GLenum pname, GLint param) {
    glFogf(pname, param);
}

void glFrustum(GLdouble left, GLdouble right, GLdouble bottom,
             GLdouble top, GLdouble near, GLdouble far) {
    glFrustumf(left, right, bottom, top, near, far);
}

void glMateriali(GLenum face, GLenum pname, GLint param) {
    glMaterialf(face, pname, param);
}

void glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat r, GLfloat q, GLfloat t) {
    glMultiTexCoord4f(target, s, t, 0.0f, 0.0f);
}

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

void glGetClipPlanefOES(GLenum plane, const GLfloat *equation) {
    glGetClipPlanef(plane, (GLfloat *)equation);
}

void glOrthofOES(GLfloat left, GLfloat right, GLfloat bottom,
                 GLfloat top, GLfloat near, GLfloat far) {
    glOrthof(left, right, bottom, top, near, far);
}

// glRect

#define GL_RECT(suffix, type)\
    void glRect##suffix(type x1, type y1, type x2, type y2) {\
        glBegin(GL_POLYGON);\
        glVertex2##suffix(x1, y1);\
        glVertex2##suffix(x2, y1);\
        glVertex2##suffix(x2, y2);\
        glVertex2##suffix(x1, y2);\
    }

GL_RECT(f, GLfloat)
GL_RECT(i, GLint)

// basic thunking

#define THUNK(suffix, type)\
/* colors */\
void glColor3##suffix(type r, type g, type b) {\
    glColor4f(r, g, b, 1.0f);\
}\
void glColor4##suffix(type r, type g, type b, type a) {\
    glColor4f(r, g, b, a);\
}\
void glColor3##suffix##v(const type *v) {\
    glColor4f(v[0], v[1], v[2], 1.0f);\
}\
void glColor4##suffix##v(const type *v) {\
    glColor4f(v[0], v[1], v[2], v[3]);\
}\
void glSecondaryColor3##suffix(type r, type g, type b) {\
    glSecondaryColor3f(r, g, b);\
}\
void glSecondaryColor3##suffix##v(const type *v) {\
    glSecondaryColor3f(v[0], v[1], v[2]);\
}\
/* index */\
void glIndex##suffix(type c) {\
    glIndexf(c);\
}\
void glIndex##suffix##v(const type *c) {\
    glIndexf(c[0]);\
}\
/* normal */\
void glNormal3##suffix(type x, type y, type z) {\
    glNormal3f(x, y, z);\
}\
void glNormal3##suffix##v(const type *v) {\
    glNormal3f(v[0], v[1], v[2]);\
}\
/* raster */\
void glRasterPos2##suffix(type x, type y) {\
    glRasterPos3f(x, y, 0);\
}\
void glRasterPos2##suffix##v(type *v) {\
    glRasterPos3f(v[0], v[1], 0);\
}\
void glRasterPos3##suffix(type x, type y, type z) {\
    glRasterPos3f(x, y, z);\
}\
void glRasterPos3##suffix##v(type *v) {\
    glRasterPos3f(v[0], v[1], v[2]);\
}\
/* vertex */\
void glVertex2##suffix(type x, type y) {\
    glVertex2f(x, y);\
}\
void glVertex2##suffix##v(type *v) {\
    glVertex2f(v[0], v[1]);\
}\
void glVertex3##suffix(type x, type y, type z) {\
    glVertex3f(x, y, z);\
}\
void glVertex3##suffix##v(type *v) {\
    glVertex3f(v[0], v[1], v[2]);\
}\
void glVertex4##suffix(type r, type g, type b, type w) {\
    glVertex3f(r/w, g/w, b/w);\
}\
void glVertex4##suffix##v(type *v) {\
    glVertex3f(v[0]/v[3], v[1]/v[3], v[2]/v[3]);\
}

THUNK(b, GLbyte)
THUNK(d, GLdouble)
THUNK(i, GLint)
THUNK(s, GLshort)
THUNK(ub, GLubyte)
THUNK(ui, GLuint)
THUNK(us, GLushort)

#undef THUNK

// glGet

#define THUNK(suffix, type)\
void glGet##suffix##v(GLenum pname, type *params) {\
    int i, n = 1;\
    switch (pname) {\
        /* two values */\
        case GL_ALIASED_POINT_SIZE_RANGE:\
        case GL_ALIASED_LINE_WIDTH_RANGE:\
        case GL_MAX_VIEWPORT_DIMS:\
            n = 2;\
            break;\
        /* three values */\
        case GL_CURRENT_NORMAL:\
        case GL_POINT_DISTANCE_ATTENUATION:\
            n = 3;\
            break;\
        /* four values */\
        case GL_COLOR_CLEAR_VALUE:\
        case GL_COLOR_WRITEMASK:\
        case GL_CURRENT_COLOR:\
        case GL_CURRENT_TEXTURE_COORDS:\
        case GL_DEPTH_RANGE:\
        case GL_FOG_COLOR:\
        case GL_LIGHT_MODEL_AMBIENT:\
        case GL_SCISSOR_BOX:\
        case GL_SMOOTH_LINE_WIDTH_RANGE:\
        case GL_SMOOTH_POINT_SIZE_RANGE:\
        case GL_VIEWPORT:\
            n = 4;\
            break;\
        /* GL_NUM_COMPRESSED_TEXTURE_FORMATS values */\
        case GL_COMPRESSED_TEXTURE_FORMATS:\
            n = GL_NUM_COMPRESSED_TEXTURE_FORMATS;\
            break;\
        /* sixteen values */\
        case GL_MODELVIEW_MATRIX:\
        case GL_PROJECTION_MATRIX:\
        case GL_TEXTURE_MATRIX:\
            n = 16;\
            break;\
    }\
    GLfloat *p = (GLfloat *)malloc(sizeof(GLfloat) * n);\
    glGetFloatv(pname, p);\
    for (i = 0; i < n; i++) {\
        params[i] = (type)p[i];\
    }\
    free(p);\
}

THUNK(Double, GLdouble)
// THUNK(Integer, GLint)

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

// matrix
#define constDoubleToFloat(a, size)\
    GLfloat s[size];\
    int i;\
    for (i = 0; i < size; i++) {\
        s[i] = a[i];\
    }

void glLoadMatrixd(const GLdouble *m) {
    constDoubleToFloat(m, 16);
    glLoadMatrixf(s);
}

void glMultMatrixd(const GLdouble *m) {
    constDoubleToFloat(m, 16);
    glMultMatrixf(s);
}

void glClipPlane(GLenum plane, const GLdouble *equation) {
    constDoubleToFloat(equation, 4);
    glClipPlanef(plane, s);
}

#undef constDoubleToFLoat

// normal
void glNormal3fv(GLfloat *v) {
    glNormal3f(v[0], v[1], v[2]);
}

// textures
void glTexCoord2d(GLdouble s, GLdouble t) {
    glTexCoord2f(s, t);
}

void glTexCoord2fv(GLfloat *t) {
    glTexCoord2f(t[0], t[1]);
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
