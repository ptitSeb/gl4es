#include "light.h"

void glLightModelf(GLenum pname, GLfloat param) {
    LOAD_GLES(glLightModelf);
    switch (pname) {
        case GL_LIGHT_MODEL_AMBIENT:
        case GL_LIGHT_MODEL_TWO_SIDE:
            gles_glLightModelf(pname, param);
        default:
            printf("stubbed glLightModelf(%i, %.2f)\n", pname, param);
            break;
    }
}
