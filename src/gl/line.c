#include "line.h"

GLint stippleFactor = 1;
GLushort stipplePattern = 0xFFFF;
GLubyte *stippleData = NULL;
GLuint stippleTexture = 0;

void glshim_glLineStipple(GLuint factor, GLushort pattern) {
    stippleFactor = factor;
    stipplePattern = pattern;
    if (stippleData != NULL) {
        free(stippleData);
    }
    stippleData = (GLubyte *)malloc(sizeof(GLubyte) * 16);
    for (int i = 0; i < 16; i++) {
        stippleData[i] = (stipplePattern >> i) & 1 ? 255 : 0;
    }

    glshim_glPushAttrib(GL_TEXTURE_BIT);
    if (! stippleTexture)
        glshim_glGenTextures(1, &stippleTexture);

    glshim_glBindTexture(GL_TEXTURE_2D, stippleTexture);
    glshim_glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glshim_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glshim_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glshim_glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA,
        16, 1, 0, GL_ALPHA, GL_UNSIGNED_BYTE, stippleData);
    glshim_glPopAttrib();
    noerrorShim();
}
void glLineStipple(GLuint factor, GLushort pattern) __attribute__((alias("glshim_glLineStipple")));

void bind_stipple_tex() {
    glshim_glBindTexture(GL_TEXTURE_2D, stippleTexture);
}

GLfloat *gen_stipple_tex_coords(GLfloat *vert, int length) {
    // generate our texture coords
    GLfloat *tex = (GLfloat *)malloc(length * 4 * sizeof(GLfloat));
    GLfloat *texPos = tex;
    GLfloat *vertPos = vert;

    GLfloat x1, x2, y1, y2;
    GLfloat len;
    for (int i = 0; i < length / 2; i++) {
        x1 = *vertPos++;
        y1 = *vertPos++;
        vertPos++; // z
        vertPos++; // w
        x2 = *vertPos++;
        y2 = *vertPos++;
        vertPos++;
        vertPos++;

        len = sqrtf(powf(x2-x1, 2) + powf(y2-y1, 2)) / stippleFactor * 16;

        *texPos++ = 0;
        *texPos++ = 0;
        *texPos++ = 0;
        *texPos++ = 1;
        *texPos++ = len;
        *texPos++ = 0;
        *texPos++ = 0;
        *texPos++ = 1;
    }
    return tex;
}
