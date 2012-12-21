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

void glVertex2f(GLfloat x, GLfloat y) {
    glVertex3f(x, y, 0);
}

void glVertex2i(GLint x, GLint y) {
    glVertex3f(x, y, 0);
}

void glColor3f(GLfloat r, GLfloat g, GLfloat b) {
    glColor4f(r, g, b, 1.0f);
}
