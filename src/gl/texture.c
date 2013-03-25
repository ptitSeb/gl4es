#include "texture.h"

// expand non-power-of-two sizes
// TODO: what does this do to repeating textures?
int npot(int n) {
    if (n == 0) return 0;

    int i = 1;
    while (i < n) i <<= 1;
    return i;
}

void glTexImage2D(GLenum target, GLint level, GLint internalFormat,
                  GLsizei width, GLsizei height, GLint border,
                  GLenum format, GLenum type, const GLvoid *data) {

    GLvoid *pixels;
    // implements GL_UNPACK_ROW_LENGTH
    if (state.texture.unpack_row_length && state.texture.unpack_row_length != width) {
        int imgWidth, pixelSize;
        pixelSize = gl_sizeof(type);
        imgWidth = state.texture.unpack_row_length * pixelSize;
        GLubyte *dst = malloc(imgWidth * height);
        const GLubyte *src = data;
        src += state.texture.unpack_skip_pixels + state.texture.unpack_skip_rows * imgWidth;
        for (int y = state.texture.unpack_skip_rows; y < height; y += 1) {
            memcpy(dst+imgWidth, src, width * pixelSize);
            src += imgWidth;
        }
        pixels = (GLvoid *)dst;
    }

    // TODO: put in a util module
    static int endian = 0;
    if (!endian) {
        uint16_t i = 1;
        if (*(char *)&i) {
            endian = 1;
        } else {
            endian = 2;
        }
    }

    switch (format) {
        case GL_ALPHA:
        case GL_RGB:
        case GL_RGBA:
        case GL_LUMINANCE:
        case GL_LUMINANCE_ALPHA:
            pixels = (GLvoid *)data;
            break;
        default: {
            const GLvoid *src = pixels ? pixels : data;
            if (! pixel_convert(src, &pixels, width, height,
                                format, type, GL_RGBA, GL_UNSIGNED_BYTE)) {
                return;
            }
            break;
        }
    }
    switch (type) {
        case GL_FLOAT:
        case GL_UNSIGNED_BYTE:
        case GL_UNSIGNED_SHORT_5_6_5:
        case GL_UNSIGNED_SHORT_4_4_4_4:
        case GL_UNSIGNED_SHORT_5_5_5_1:
            break;
        case GL_UNSIGNED_INT_8_8_8_8:
            type = GL_UNSIGNED_BYTE;
            break;
        default: {
            const GLvoid *src = pixels ? pixels : data;
            if (! pixel_convert(src, &pixels, width, height,
                                format, type, GL_RGBA, GL_UNSIGNED_BYTE)) {
                return;
            }
            type = GL_UNSIGNED_BYTE;
            format = GL_RGBA;
        }
    }

    /* TODO:
    GL_INVALID_VALUE is generated if border is not 0.
    GL_INVALID_OPERATION is generated if type is
    GL_UNSIGNED_SHORT_5_6_5 and format is not GL_RGB.
    
    GL_INVALID_OPERATION is generated if type is one of
    GL_UNSIGNED_SHORT_4_4_4_4, or GL_UNSIGNED_SHORT_5_5_5_1
    and format is not GL_RGBA.
    */

    LOAD_GLES(void, glTexImage2D, GLenum, GLint, GLint,
              GLsizei, GLsizei, GLint,
              GLenum, GLenum, const GLvoid*);
    switch (target) {
        case GL_PROXY_TEXTURE_1D:
        case GL_PROXY_TEXTURE_2D:
            break;
        default:
            gles_glTexImage2D(target, level, format, width, height, border,
                              format, type, pixels);
    }

    if (pixels != data) {
        free((GLvoid *)pixels);
    }
}

void glTexImage1D(GLenum target, GLint level, GLint internalFormat,
                  GLsizei width, GLint border,
                  GLenum format, GLenum type, const GLvoid *data) {

    // TODO: maybe too naive to force GL_TEXTURE_2D here?
    glTexImage2D(GL_TEXTURE_2D, level, internalFormat, width, 1,
                 border, format, type, data);
}

void glPixelStorei(GLenum pname, GLint param) {
    // TODO: add to glGetIntegerv?
    LOAD_GLES(void, glPixelStorei, GLenum, GLint);
    switch (pname) {
        case GL_UNPACK_ROW_LENGTH:
            state.texture.unpack_row_length = param;
            break;
        case GL_UNPACK_SKIP_PIXELS:
            state.texture.unpack_skip_pixels = param;
            break;
        case GL_UNPACK_SKIP_ROWS:
            state.texture.unpack_skip_rows = param;
            break;
        default:
            gles_glPixelStorei(pname, param);
            break;
    }
}
