#include <gl.h>
// naive wrappers

void glActiveTextureARB(GLenum texture) {
    glActiveTexture(texture);
}

void glClearDepth(double depth) {
    glClearDepthf(depth);
}

void glOrtho(double left, double right, double bottom,
             double top, double near, double far) {
    glOrthof(left, right, bottom, top, near, far);
}

void glFrustum(double left, double right, double bottom,
             double top, double near, double far) {
    glFrustumf(left, right, bottom, top, near, far);
}

void glFogi(GLenum pname, GLint param) {
    glFogf(pname, param);
}

// basic thunking

#define THUNK(suffix, type)\
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
void glVertex2##suffix(type x, type y) {\
    glVertex2f(x, y);\
}\
void glVertex3##suffix(type x, type y, type z) {\
    glVertex3f(x, y, z);\
}

// TODO: we don't handle glVertex4f anywhere

THUNK(b, GLbyte);
THUNK(s, GLshort);
THUNK(i, GLint);
THUNK(d, GLdouble);
THUNK(ub, GLubyte);
THUNK(us, GLushort);
THUNK(ui, GLuint);

void glVertex2f(GLfloat x, GLfloat y) {
    glVertex3f(x, y, 0);
}

void glColor3f(GLfloat r, GLfloat g, GLfloat b) {
    glColor4f(r, g, b, 1.0f);
}

#undef THUNK

void glTranslated(GLdouble x, GLdouble y, GLdouble z) {
    glTranslatef(x, y, z);
}

void glTexCoord2d(GLdouble s, GLdouble t) {
    glTexCoord2f(s, t);
}

void glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz) {
    // TODO: needs to be added to glDrawArrays too
    glNormal3f(nx, ny, nz);
}

void glGetDoublev(GLenum pname, GLdouble *params) {
    int i, n = 1;
    switch (pname) {
        // two values
        case GL_ALIASED_POINT_SIZE_RANGE:
        case GL_ALIASED_LINE_WIDTH_RANGE:
        case GL_MAX_VIEWPORT_DIMS:
            n = 2;
            break;
        // three values:
        case GL_CURRENT_NORMAL:
        case GL_POINT_DISTANCE_ATTENUATION:
            n = 3;
            break;
        // four values
        case GL_COLOR_CLEAR_VALUE:
        case GL_COLOR_WRITEMASK:
        case GL_CURRENT_COLOR:
        case GL_CURRENT_TEXTURE_COORDS:
        case GL_DEPTH_RANGE:
        case GL_FOG_COLOR:
        case GL_LIGHT_MODEL_AMBIENT:
        case GL_SCISSOR_BOX:
        case GL_SMOOTH_LINE_WIDTH_RANGE:
        case GL_SMOOTH_POINT_SIZE_RANGE:
        case GL_VIEWPORT:
            n = 4;
            break;
        // GL_NUM_COMPRESSED_TEXTURE_FORMATS values
        case GL_COMPRESSED_TEXTURE_FORMATS:
            n = GL_NUM_COMPRESSED_TEXTURE_FORMATS;
            break;
        // sixteen values
        case GL_MODELVIEW_MATRIX:
        case GL_PROJECTION_MATRIX:
        case GL_TEXTURE_MATRIX:
            n = 16;
            break;
    }
    GLfloat *p = (GLfloat *)malloc(sizeof(GLfloat) * n);
    glGetFloatv(pname, p);
    for (i = 0; i < n; i++) {
        *params++ = (GLdouble)*p++;
    }
}
