#include <texture.h>

GLuint tUnpackRowLength = 0;
GLuint tUnpackSkipPixels = 0;
GLuint tUnpackSkipRows = 0;

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
            printf("Unsupported pixel conversion format: %i\n", format);
            *out = (GLvoid *)data;
            return 0;
    }

#define convert(constant, type)                              \
    case constant:                                           \
        {                                                    \
            int size = width * height * w;                   \
            type *src = (type *)data;                        \
            type *dst = (type *)malloc(sizeof(type) * size); \
            for (int i = 0; i < size; i += w) {              \
                dst[i]   = src[i+m0];                        \
                dst[i+1] = src[i+m1];                        \
                dst[i+2] = src[i+m2];                        \
                if (width == 4) dst[i+3] = src[i+m3];        \
            }                                                \
            *out = (GLvoid *)dst;                            \
        }                                                    \
        break;

    switch (type) {
        convert(GL_UNSIGNED_BYTE, GLubyte);
        convert(GL_FLOAT, GLfloat);
        default:
            printf("Unsupported pixel packing(2): %i\n", type);
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
    // implements GL_UNPACK_ROW_LENGTH
    if (tUnpackRowLength && tUnpackRowLength != width) {
        int imgWidth, pixelSize;
        pixelSize = gl_sizeof(type);
        imgWidth = tUnpackRowLength * pixelSize;
        GLubyte *dst = malloc(imgWidth * height);
        const GLubyte *src = data;
        src += tUnpackSkipPixels + tUnpackSkipRows * imgWidth;
        for (int y = tUnpackSkipRows; y < height; y += 1) {
            memcpy(dst+imgWidth, src, width * pixelSize);
            src += imgWidth;
        }
        pixels = (GLvoid *)dst;
    }

    switch (type) {
        case GL_UNSIGNED_BYTE:
        case GL_UNSIGNED_SHORT_5_6_5:
        case GL_UNSIGNED_SHORT_4_4_4_4:
        case GL_UNSIGNED_SHORT_5_5_5_1:
            break;
        default:
            printf("Unsupported pixel type: %i\n", type);
            return;
    }
    switch (format) {
        case GL_ALPHA:
        case GL_RGB:
        case GL_RGBA:
        case GL_LUMINANCE:
        case GL_LUMINANCE_ALPHA:
            pixels = (GLvoid *)data;
            break;
        default:
            printf("Unsupported pixel format? %i\n", format);
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

    LOAD_GLES(void, glTexImage2D, GLenum, GLint, GLint,
              GLsizei, GLsizei, GLint,
              GLenum, GLenum, const GLvoid*);
    gles_glTexImage2D(target, level, format, width, height, border,
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

void glPixelStorei(GLenum pname, GLint param) {
    LOAD_GLES(void, glPixelStorei, GLenum, GLint);
    switch (pname) {
        case GL_UNPACK_ROW_LENGTH:
            tUnpackRowLength = param;
            break;
        case GL_UNPACK_SKIP_PIXELS:
            tUnpackSkipPixels = param;
            break;
        case GL_UNPACK_SKIP_ROWS:
            tUnpackSkipRows = param;
            break;
        default:
            gles_glPixelStorei(pname, param);
            break;
    }
}
