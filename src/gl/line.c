#include <line.h>

GLuint genStippleTex(GLint factor, GLint pattern, GLfloat *pixels,
                     GLfloat *vert, GLfloat **tex, int length) {
    pixels = (GLfloat *)malloc(sizeof(GLfloat) * 16);
    // generate our texture
    for (int i = 0; i < 16; i++) {
        pixels[i] = (stipplePattern >> i) & 1 ? 255 : 0;
    }

    // generate our texture coords
    *tex = (GLfloat *)malloc(length * 2 * sizeof(GLfloat));
    GLfloat *texPos = *tex;
    GLfloat *vertPos = vert;

    GLfloat x1, x2, y1, y2;
    GLfloat len;
    for (int i = 0; i < length / 2; i++) {
        x1 = *vertPos++;
        y1 = *vertPos++;
        vertPos++; // z
        x2 = *vertPos++;
        y2 = *vertPos++;
        vertPos++;

        len = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)) / stippleFactor;

        *texPos++ = 0;
        *texPos++ = 0;
        *texPos++ = len;
        *texPos++ = 0;
    }

    // TODO: this really shouldn't go here, and should be restored after render
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);

    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA,
        16, 1, 0, GL_ALPHA, GL_UNSIGNED_BYTE, pixels);

    return texture;
}
