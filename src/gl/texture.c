#include "texture.h"

// expand non-power-of-two sizes
// TODO: what does this do to repeating textures?
int npot(int n) {
    if (n == 0) return 0;

    int i = 1;
    while (i < n) i <<= 1;
    return i;
}

// conversions for GL_ARB_texture_rectangle
void texture_rect_arb_convert(GLfloat *tex, GLsizei len,
                              GLsizei width, GLsizei height) {
    if (!tex || !width || !height) {
        return;
    }

    for (int i = 0; i < len; i++) {
        tex[0] /= width;
        tex[1] /= height;
        tex += 2;
    }
}

void glTexImage2D(GLenum target, GLint level, GLint internalFormat,
                  GLsizei width, GLsizei height, GLint border,
                  GLenum format, GLenum type, const GLvoid *data) {

    GLtexture *bound = state.texture.bound;
    GLvoid *pixels = NULL;
    if (data) {
        // implements GL_UNPACK_ROW_LENGTH
        if (state.texture.unpack_row_length && state.texture.unpack_row_length != width) {
            int imgWidth, pixelSize;
            pixelSize = gl_sizeof(type);
            imgWidth = state.texture.unpack_row_length * pixelSize;
            GLubyte *dst = (GLubyte *)malloc(width * height * pixelSize);
            pixels = (GLvoid *)dst;
            const GLubyte *src = (GLubyte *)data;
            src += state.texture.unpack_skip_pixels + state.texture.unpack_skip_rows * imgWidth;
            for (int y = 0; y < height; y += 1) {
                memcpy(dst, src, width * pixelSize);
                src += imgWidth;
                dst += width;
            }
        }

        switch (format) {
            case GL_ALPHA:
            case GL_RGB:
            case GL_RGBA:
            case GL_LUMINANCE:
            case GL_LUMINANCE_ALPHA:
                break;
            default: {
                if (! pixel_convert(pixels ? pixels : data, &pixels, width, height,
                                    format, type, GL_RGBA, GL_UNSIGNED_BYTE)) {
                    printf("libGL swizzle error: (%#4x, %#4x -> RGBA, UNSIGNED_BYTE)\n",
                        format, type);
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
                pixels = (GLvoid *)data;
                break;
            case GL_UNSIGNED_INT_8_8_8_8:
                type = GL_UNSIGNED_BYTE;
                break;
            default: {
                if (! pixel_convert(pixels ? pixels : data, &pixels, width, height,
                                    format, type, GL_RGBA, GL_UNSIGNED_BYTE)) {
                    printf("libGL swizzle error: (%#4x, %#4x -> RGBA, UNSIGNED_BYTE)\n",
                        format, type);
                    return;
                }
                type = GL_UNSIGNED_BYTE;
                format = GL_RGBA;
            }
        }

        char *env_shrink = getenv("LIBGL_SHRINK");
        if (env_shrink && strcmp(env_shrink, "1") == 0) {
            if (width > 1 && height > 1) {
                GLvoid *out;
                GLfloat ratio = 0.5;
                pixel_scale(pixels, &out, width, height, ratio, format, type);
                if (pixels != data)
                    free(pixels);
                pixels = out;
                width *= ratio;
                height *= ratio;
            }
        }

        char *env_dump = getenv("LIBGL_TEXDUMP");
        if (env_dump && strcmp(env_dump, "1") == 0) {
            if (bound) {
                pixel_to_ppm(pixels, width, height, format, type, bound->texture);
            }
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
    if (! pixels)
        pixels = (GLvoid *)data;

    switch (target) {
        case GL_PROXY_TEXTURE_1D:
        case GL_PROXY_TEXTURE_2D:
            break;
        default: {
            GLsizei nheight = npot(height), nwidth = npot(width);
            if (bound) {
                bound->width = nwidth;
                bound->height = nheight;
            }
            if (height != nheight || width != nwidth) {
                gles_glTexImage2D(target, level, format, nwidth, nheight, border,
                                  format, type, NULL);
                glTexSubImage2D(target, level, 0, 0, width, height,
                                format, type, pixels);
            } else {
                gles_glTexImage2D(target, level, format, width, height, border,
                                  format, type, pixels);
            }
        }
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

void glBindTexture(GLenum target, GLuint texture) {
    if (texture) {
        int ret;
        khint_t k;
        khash_t(tex) *list = state.texture.list;
        if (! list) {
            list = state.texture.list = kh_init(tex);
            // segfaults if we don't do a single put
            kh_put(tex, list, 1, &ret);
            kh_del(tex, list, 1);
        }

        k = kh_get(tex, list, texture);
        GLtexture *tex = NULL;;
        if (k == kh_end(list)){
            k = kh_put(tex, list, texture, &ret);
            tex = kh_value(list, k) = malloc(sizeof(GLtexture));
            tex->texture = texture;
            tex->target = target;
            tex->width = 0;
            tex->height = 0;
            tex->uploaded = false;
        } else {
            tex = kh_value(list, k);
        }
        state.texture.bound = tex;
    }

    state.texture.rect_arb = (target == GL_TEXTURE_RECTANGLE_ARB);
    target = map_tex_target(target);

    LOAD_GLES(void, glBindTexture, GLenum, GLuint);
    gles_glBindTexture(target, texture);
}

// TODO: also glTexParameterf(v)?
void glTexParameteri(GLenum target, GLenum pname, GLint param) {
    LOAD_GLES(void, glTexParameteri, GLenum, GLenum, GLint);
    target = map_tex_target(target);
    gles_glTexParameteri(target, pname, param);
}

void glDeleteTextures(GLsizei n, const GLuint *textures) {
    khash_t(tex) *list = state.texture.list;
    if (list) {
        khint_t k;
        GLtexture *tex;
        for (int i = 0; i < n; i++) {
            GLuint t = textures[i];
            k = kh_get(tex, list, t);
            if (k != kh_end(list)) {
                tex = kh_value(list, k);
                if (tex == state.texture.bound)
                    state.texture.bound = NULL;
                free(tex);
                kh_del(tex, list, k);
            }
        }
    }
    LOAD_GLES(void, glDeleteTextures, GLsizei, const GLuint *);
    gles_glDeleteTextures(n, textures);
}
