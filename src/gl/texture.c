#include <texture.h>

GLenum convertPixels(const GLvoid *data, GLvoid **out,
                            GLsizei width, GLsizei height,
                            GLenum format, GLenum type) {
    unsigned int w;
    int m0, m1, m2, m3;
    GLenum newFormat = format;
    switch (format) {
        case GL_BGR:
            w = 3;
            m0 = 2; m1 = 1; m2 = 0;
            newFormat = GL_RGB;
            break;
        case GL_BGRA:
            w = 4;
            m0 = 2; m1 = 1; m2 = 0; m3 = 3;
            newFormat = GL_RGBA;
            break;
        default:
            printf("unsupported pixel format: %i\n", format);
            *out = (GLvoid *)data;
            return format;
    }

#define convert(constant, type)\
    case constant:\
        {\
            int size = width * height * w;\
            type *src = (type *)data;\
            type *dst = (type *)malloc(sizeof(type) * size);\
            for (int i = 0; i < size; i += w) {\
                dst[i]   = src[i+m0];\
                dst[i+1] = src[i+m1];\
                dst[i+2] = src[i+m2];\
                if (width == 4) dst[i+3] = src[i+m3];\
            }\
            *out = (GLvoid *)dst;\
        }\
        break;

    switch (type) {
        convert(GL_UNSIGNED_BYTE, GLubyte);
        convert(GL_FLOAT, GLfloat);
        default:
            printf("unsupported pixel depth: %i\n", type);
            *out = (GLvoid *)data;
            return format;
            break;
    }
#undef convert
    return newFormat;
}

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
    switch (format) {
        case GL_ALPHA:
        case GL_RGB:
        case GL_RGBA:
        case GL_LUMINANCE:
        case GL_LUMINANCE_ALPHA:
            pixels = (GLvoid *)data;
            break;
        default:
            printf("unknown format?\n");
            format = convertPixels(data, &pixels, width, height, format, type);
            break;
    }

    /* TODO:
    GL_INVALID_VALUE is generated if border is not 0.
    GL_INVALID_OPERATION is generated if type is
    GL_UNSIGNED_SHORT_5_6_5 and format is not GL_RGB.
    
    GL_INVALID_OPERATION is generated if type is one of
    GL_UNSIGNED_SHORT_4_4_4_4, or GL_UNSIGNED_SHORT_5_5_5_1
    and format is not GL_RGBA.
    */

    LOAD_REAL(void, glTexImage2D, GLenum, GLint, GLint,
              GLsizei, GLsizei, GLint,
              GLenum, GLenum, const GLvoid*);
    real_glTexImage2D(target, level, format, 2, 2, border,
                      format, type, pixels);

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
