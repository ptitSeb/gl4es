#include <glesgl.h>
// naive wrappers

void glClearDepth(GLclampf depth) {
    glClearDepthf(depth);
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
