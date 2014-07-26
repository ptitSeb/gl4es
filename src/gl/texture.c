#include "texture.h"
#include "raster.h"
#include "decompress.h"
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include "../glx/streaming.h"
// expand non-power-of-two sizes
// TODO: what does this do to repeating textures?
int npot(int n) {
    if (n == 0) return 0;

    int i = 1;
    while (i < n) i <<= 1;
    return i;
}

// conversions for GL_ARB_texture_rectangle
void tex_coord_rect_arb(GLfloat *tex, GLsizei len,
                        GLsizei width, GLsizei height) {
    if (!tex || !width || !height)
        return;

    for (int i = 0; i < len; i++) {
        tex[0] /= width;
        tex[1] /= height;
        tex += 2;
    }
}

void tex_coord_npot(GLfloat *tex, GLsizei len,
                    GLsizei width, GLsizei height,
                    GLsizei nwidth, GLsizei nheight) {
    if (!tex || !width || !height)
        return;

    GLfloat wratio = (width / (GLfloat)nwidth);
    GLfloat hratio = (height / (GLfloat)nheight);
    for (int i = 0; i < len; i++) {
        tex[0] *= wratio;
        tex[1] *= hratio;
        tex += 2;
    }
}

static void *swizzle_texture(GLsizei width, GLsizei height,
                             GLenum *format, GLenum *type,
                             const GLvoid *data) {
    bool convert = false;
	 switch (*format) {
        case GL_ALPHA:
        case GL_RGB:
        case GL_RGBA:
        case GL_LUMINANCE:
        case GL_LUMINANCE_ALPHA:
            break;
        default:
            convert = true;
            break;
    }
    switch (*type) {
        //case GL_FLOAT:
        case GL_UNSIGNED_BYTE:
        case GL_UNSIGNED_SHORT_5_6_5:
        case GL_UNSIGNED_SHORT_4_4_4_4:
        case GL_UNSIGNED_SHORT_5_5_5_1:
            break;
        case GL_UNSIGNED_INT_8_8_8_8_REV:
            *type = GL_UNSIGNED_BYTE;
            break;
        default:
            convert = true;
            break;
    }
	if (data) {
		if (convert) {
			GLvoid *pixels = (GLvoid *)data;
			if (! pixel_convert(data, &pixels, width, height,
								*format, *type, GL_RGBA, GL_UNSIGNED_BYTE)) {
				printf("libGL swizzle error: (%#4x, %#4x -> GL_RGBA, UNSIGNED_BYTE)\n",
					*format, *type);
				return NULL;
			}
			*type = GL_UNSIGNED_BYTE;
			*format = GL_RGBA;
			GLvoid *pix2 = pixels;
			if (raster_need_transform())
				if (!pixel_transform(data, &pixels, width, height,
								*format, *type, raster_scale, raster_bias)) {
					printf("libGL swizzle/convert error: (%#4x, %#4x -> GL_RGBA, UNSIGNED_BYTE)\n",
						*format, *type);
					pix2 = pixels;
				}
			if (pix2!=pixels && pixels!=data)
				free(pixels);
			return pix2;
		} 
    } else {
		if (convert) {
			*type = GL_UNSIGNED_BYTE;
			*format = GL_RGBA;
		}
	}
    return (void *)data;
}

int automipmap = 0;
int texcopydata = 0;
int tested_env = 0;
int texshrink = 0;
int texdump = 0;
int alphahack = 0;
int texstream = 0;

static int proxy_width = 0;
static int proxy_height = 0;

void glTexImage2D(GLenum target, GLint level, GLint internalformat,
                  GLsizei width, GLsizei height, GLint border,
                  GLenum format, GLenum type, const GLvoid *data) {

//printf("glTexImage2D with unpack_row_length(%i), size(%i,%i) and skip(%i,%i), format(internal)=%04x(%04x), type=%04x, data=%08x, level=%i (mipmap_need=%i, mipmap_auto=%i) => texture=%u\n", state.texture.unpack_row_length, width, height, state.texture.unpack_skip_pixels, state.texture.unpack_skip_rows, format, internalformat, type, data, level, state.texture.bound[state.texture.active]->mipmap_need, state.texture.bound[state.texture.active]->mipmap_auto, state.texture.bound[state.texture.active]->texture);
/*    GLint unpack;
    glGetIntegerv(GL_UNPACK_ALIGNMENT, &unpack);*/
    GLvoid *pixels = (GLvoid *)data;
    border = 0;	//TODO: something?
    PUSH_IF_COMPILING(glTexImage2D);
    // proxy case
    if (target == GL_PROXY_TEXTURE_2D) {
	proxy_width = (width>2048)?0:width;
	proxy_height = (height>2048)?0:height;
	return;
    }
    if (!tested_env) {
	char *env_mipmap = getenv("LIBGL_MIPMAP");
	if (env_mipmap && strcmp(env_mipmap, "1") == 0) {
		automipmap = 1;
		printf("LIBGL: AutoMipMap forced\n");
	}
	if (env_mipmap && strcmp(env_mipmap, "2") == 0) {
		automipmap = 2;
		printf("LIBGL: guess AutoMipMap\n");
	}
	if (env_mipmap && strcmp(env_mipmap, "3") == 0) {
		automipmap = 3;
		printf("LIBGL: ignore MipMap\n");
	}
	char *env_texcopy = getenv("LIBGL_TEXCOPY");
	if (env_texcopy && strcmp(env_texcopy, "1") == 0) {
		texcopydata = 1;
		printf("LIBGL: Texture copy enabled\n");
	}
	char *env_shrink = getenv("LIBGL_SHRINK");
	if (env_shrink && strcmp(env_shrink, "1") == 0) {
		texshrink = 1;
		printf("LIBGL: Texture shink, mode 1 selected (everything / 2)\n");
	}
	if (env_shrink && strcmp(env_shrink, "2") == 0) {
		texshrink = 2;
		printf("LIBGL: Texture shink, mode 2 selected (only > 512 /2 )\n");
	}
	if (env_shrink && strcmp(env_shrink, "3") == 0) {
		texshrink = 3;
		printf("LIBGL: Texture shink, mode 3 selected (only > 256 /2 )\n");
	}
	char *env_dump = getenv("LIBGL_TEXDUMP");
	if (env_dump && strcmp(env_dump, "1") == 0) {
		texdump = 1;
		printf("LIBGL: Texture dump enabled\n");
	}
	char *env_alpha = getenv("LIBGL_ALPHAHACK");
	if (env_alpha && strcmp(env_alpha, "1") == 0) {
		alphahack = 1;
		printf("LIBGL: Alpha Hack enabled\n");
	}
	char *env_stream = getenv("LIBGL_STREAM");
	if (env_stream && strcmp(env_stream, "1") == 0) {
		texstream = InitStreamingCache();
		printf("LIBGL: Streaming texture %s\n",(texstream)?"enabled":"not enabled");
		//FreeStreamed(AddStreamed(1024, 512, 0));
	}
	tested_env = true;
    }
    
    gltexture_t *bound = state.texture.bound[state.texture.active];
    if (bound) bound->alpha = pixel_hasalpha(format);
    if (automipmap) {
	if (bound && (level>0))
	    if ((automipmap==1) || (automipmap==3) || bound->mipmap_need)
		return;			// has been handled by auto_mipmap
	    else
		bound->mipmap_need = 1;
     }
     if (data) {

        // implements GL_UNPACK_ROW_LENGTH
        if ((state.texture.unpack_row_length && state.texture.unpack_row_length != width) || state.texture.unpack_skip_pixels || state.texture.unpack_skip_rows) {
            int imgWidth, pixelSize;
            pixelSize = pixel_sizeof(format, type);
            imgWidth = ((state.texture.unpack_row_length)? state.texture.unpack_row_length:width) * pixelSize;
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

        GLvoid *old = pixels;
        pixels = (GLvoid *)swizzle_texture(width, height, &format, &type, old);
        if (old != pixels && old != data) {
            free(old);
        }

        bound->shrink = 0;
        if (texshrink==1) {
            if ((width > 1) && (height > 1)) {
                GLvoid *out = pixels;
                GLfloat ratio = 0.5;
                pixel_scale(pixels, &out, width, height, ratio, format, type);
                if (out != pixels && pixels!=data)
                    free(pixels);
                pixels = out;
                width *= ratio;
                height *= ratio;
                bound->shrink = 1;
            }
        }
        if (texshrink==2 || texshrink==3) {
            if (((width > ((texshrink==2)?512:256)) && (height > 8)) || ((height > ((texshrink==2)?512:256)) && (width > 8))) {
                GLvoid *out = pixels;
                pixel_halfscale(pixels, &out, width, height, format, type);
                if (out != pixels && pixels!=data)
                    free(pixels);
                pixels = out;
                width /= 2;
                height /= 2;
                bound->shrink = 1;
            }
        }

        if (texdump) {
            if (bound) {
                pixel_to_ppm(pixels, width, height, format, type, bound->texture);
            }
        }
    } else {
	    swizzle_texture(width, height, &format, &type, NULL);	// convert format even if data is NULL
	    if (bound) {
		bound->shrink = 0;
		if (texshrink>0)
		    if ((texshrink==1) || 
			((texshrink>1) && 
				((width > ((texshrink==2)?512:256)) && (height > 8)) 
			 || ((height > ((texshrink==2)?512:256)) && (width > 8)))) {
			width /= 2;
			height /= 2;
			bound->shrink = 1;
		    }
	    }
		if (texstream && (target==GL_TEXTURE_2D) && ((internalformat==GL_RGB) || (internalformat==3))) {
			bound->streamingID = AddStreamed(width, height, bound->texture);
			if (bound->streamingID>-1) {	// success
				bound->streamed = true;
				ApplyFilterID(bound->streamingID, bound->min_filter, bound->mag_filter);
				ActivateStreaming(bound->streamingID);	//Activate the newly created texture
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

    LOAD_GLES(glTexImage2D);
    LOAD_GLES(glTexSubImage2D);
    LOAD_GLES(glTexParameteri);

    switch (target) {
        case GL_PROXY_TEXTURE_2D:
            break;
        default: {
            GLsizei nheight = npot(height), nwidth = npot(width);
            if (texstream && bound && bound->streamed) {
				nwidth = width;
				nheight = height;
			}
            if (bound && (level == 0)) {
                bound->width = width;
                bound->height = height;
                bound->nwidth = nwidth;
                bound->nheight = nheight;
            }
			if (!(texstream && bound && bound->streamed)) {
				if (bound && bound->mipmap_need && !bound->mipmap_auto && (automipmap!=3))
					gles_glTexParameteri( target, GL_GENERATE_MIPMAP, GL_TRUE );
				if (height != nheight || width != nwidth) {
					gles_glTexImage2D(target, level, format, nwidth, nheight, border,
									  format, type, NULL);
					gles_glTexSubImage2D(target, level, 0, 0, width, height,
										 format, type, pixels);
				} else {
					gles_glTexImage2D(target, level, format, width, height, border,
									  format, type, pixels);
				}
				if (bound && bound->mipmap_need && !bound->mipmap_auto && (automipmap!=3))
					gles_glTexParameteri( target, GL_GENERATE_MIPMAP, GL_FALSE );
			}
        }
    }
    if (texcopydata && bound && (texstream && !bound->streamed)) {
		if (bound->data) free(bound->data);
		bound->data = malloc(width*height*4);
		if (data)
			pixel_convert(pixels, &bound->data, width, height, format, type, GL_RGBA, GL_UNSIGNED_BYTE);
		else
			memset(bound->data, 0, width*height*4);
	}
    if (pixels != data) {
        free(pixels);
    }
}

void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset,
                     GLsizei width, GLsizei height, GLenum format, GLenum type,
                     const GLvoid *data) {
    const GLvoid *pixels = data;
	PUSH_IF_COMPILING(glTexSubImage2D);

    LOAD_GLES(glTexSubImage2D);
    LOAD_GLES(glTexParameteri);
//printf("glTexSubImage2D with unpack_row_length(%i), size(%i,%i), pos(%i,%i) and skip={%i,%i}, format=%04x, type=%04x, level=%i\n", state.texture.unpack_row_length, width, height, xoffset, yoffset, state.texture.unpack_skip_pixels, state.texture.unpack_skip_rows, format, type, level);
    if (width==0 || height==0)
	return;
    target = map_tex_target(target);
    
    gltexture_t *bound = state.texture.bound[state.texture.active];
    if (automipmap) {
	if (bound && (level>0))
	    if ((automipmap==1) || (automipmap==3) || bound->mipmap_need)
		return;			// has been handled by auto_mipmap
	    else
		bound->mipmap_need = 1;
    }

    if ((state.texture.unpack_row_length && state.texture.unpack_row_length != width) || state.texture.unpack_skip_pixels || state.texture.unpack_skip_rows) {
		int imgWidth, pixelSize;
		pixelSize = pixel_sizeof(format, type);
		imgWidth = ((state.texture.unpack_row_length)? state.texture.unpack_row_length:width) * pixelSize;
		GLubyte *dst = (GLubyte *)malloc(width * height * pixelSize);
		pixels = (GLvoid *)dst;
		const GLubyte *src = (GLubyte *)data;
		src += state.texture.unpack_skip_pixels * pixelSize + state.texture.unpack_skip_rows * imgWidth;
		for (int y = 0; y < height; y += 1) {
			memcpy(dst, src, width * pixelSize);
			src += imgWidth;
			dst += width * pixelSize;
		}
    }

    GLvoid *old = pixels;
	if (bound && texstream && (bound->streamed)) {
		if (! pixel_convert(data, &pixels, width, height,
								format, type, GL_RGB, GL_UNSIGNED_SHORT_5_6_5)) {
			printf("libGL swizzle error: (%#4x, %#4x -> GL_RGBA, UNSIGNED_SHORT_5_6_5)\n",
			format, type);
		}
		format = GL_RGB;
		type = GL_UNSIGNED_SHORT_5_6_5;
    } else pixels = (GLvoid *)swizzle_texture(width, height, &format, &type, old);
    if (old != pixels && old != data)
	free(old);

    if (bound->shrink) {
		// special case for width/height == 1
		if (width==1)
			width+=(xoffset%2);
		if (height==1)
			height+=(yoffset%2);
		if ((width==1) || (height==1)) {
			// nothing to do...
			if (pixels != data)
				free((GLvoid *)pixels);
			return;
		}
		// ok, now standard cases....
		xoffset /= 2;
		yoffset /= 2;
		old = pixels;
		pixel_halfscale(pixels, &old, width, height, format, type);
		if (old != pixels && pixels!=data)
			free(pixels);
		pixels = old;
		width /= 2;
		height /= 2;
    }

    if (texdump) {
		if (bound) {
			pixel_to_ppm(pixels, width, height, format, type, bound->texture);
		}
    }

    if (bound && bound->mipmap_need && !bound->mipmap_auto && (automipmap!=3) && (texstream && !bound->streamed))
	gles_glTexParameteri( target, GL_GENERATE_MIPMAP, GL_TRUE );

	if (bound && texstream && bound->streamed) {
		// copy the texture to the buffer
		void* tmp = GetStreamingBuffer(bound->streamingID);
		for (int yy=0; yy<height; yy++) {
			memcpy(tmp+((yy+yoffset)*bound->width+xoffset)*2, tmp+(yy*width)*2, width*2);
		}
	} else
		gles_glTexSubImage2D(target, level, xoffset, yoffset,
						 width, height, format, type, pixels);

    if (bound && bound->mipmap_need && !bound->mipmap_auto && (automipmap!=3) && (texstream && !bound->streamed))
	gles_glTexParameteri( target, GL_GENERATE_MIPMAP, GL_FALSE );

    if (texcopydata && bound && (texstream && !bound->streamed)) {
		GLvoid * tmp = pixels;
		pixel_convert(pixels, &tmp, width, height, format, type, GL_RGBA, GL_UNSIGNED_BYTE);
		for (int yy=0; yy<height; yy++) {
			memcpy(bound->data+((yy+yoffset)*bound->width+xoffset)*4, tmp+(yy*width)*4, width*4);
		}
		if (tmp!=pixels)
			free(tmp);
	}

    if (pixels != data)
        free((GLvoid *)pixels);
}

// 1d stubs
void glTexImage1D(GLenum target, GLint level, GLint internalFormat,
                  GLsizei width, GLint border,
                  GLenum format, GLenum type, const GLvoid *data) {

    // TODO: maybe too naive to force GL_TEXTURE_2D here?
    glTexImage2D(GL_TEXTURE_2D, level, internalFormat, width, 1,
                 border, format, type, data);
}
void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint yoffset,
                     GLsizei width, GLenum format, GLenum type,
                     const GLvoid *data) {

    glTexSubImage2D(GL_TEXTURE_2D, level, xoffset, yoffset,
                    width, 1, format, type, data);
}
void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y,
		    GLsizei width, GLint border) {
    glCopyTexImage2D(GL_TEXTURE_2D, level, internalformat, x, y, width, 1, border);
		    
}

void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y,
                                GLsizei width) {
    glCopyTexSubImage2D(GL_TEXTURE_2D, level, xoffset, 0, x, y, width, 1);
}
                                


// 3d stubs
void glTexImage3D(GLenum target, GLint level, GLint internalFormat,
                  GLsizei width, GLsizei height, GLsizei depth, GLint border,
                  GLenum format, GLenum type, const GLvoid *data) {

    // TODO: maybe too naive to force GL_TEXTURE_2D here?
    glTexImage2D(GL_TEXTURE_2D, level, internalFormat, width, height,
                 border, format, type, data);
}
void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset,
                     GLsizei width, GLsizei height, GLsizei depth, GLenum format,
                     GLenum type, const GLvoid *data) {

    glTexSubImage2D(target, level, xoffset, yoffset,
                    width, height, format, type, data);
}

void glPixelStorei(GLenum pname, GLint param) {
    // TODO: add to glGetIntegerv?
    LOAD_GLES(glPixelStorei);
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
        case GL_UNPACK_LSB_FIRST:
            state.texture.unpack_lsb_first = param;
            break;
        case GL_PACK_ROW_LENGTH:
            state.texture.pack_row_length = param;
            break;
        case GL_PACK_SKIP_PIXELS:
            state.texture.pack_skip_pixels = param;
            break;
        case GL_PACK_SKIP_ROWS:
            state.texture.pack_skip_rows = param;
            break;
        case GL_PACK_LSB_FIRST:
            state.texture.pack_lsb_first = param;
            break;
        default:
            gles_glPixelStorei(pname, param);
            break;
    }
}
GLboolean glIsTexture(	GLuint texture) {
	if (!texture) {
		return GL_FALSE;
	}
    int ret;
	khint_t k;
	khash_t(tex) *list = state.texture.list;
	if (! list) {
		return GL_FALSE;
	}
	k = kh_get(tex, list, texture);
	gltexture_t *tex = NULL;
	if (k == kh_end(list)) {
		return GL_FALSE;
	}
	return GL_TRUE;
}

void glBindTexture(GLenum target, GLuint texture) {
    if (state.list.compiling && state.list.active) {
		// check if already a texture binded, if yes, create a new list
		NewStage(state.list.active, STAGE_BINDTEX);
/*		if (state.list.active->set_texture)
			state.list.active = extend_renderlist(state.list.active);*/
        rlBindTexture(state.list.active, texture);
    } else {
        if (texstream) {  // unbind streaming texture if any...
            gltexture_t *bound = state.texture.bound[state.texture.active];
            if (bound && bound->streamed)
                DeactivateStreaming();
        }
		int streamingID = -1;
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
            gltexture_t *tex = NULL;
            
            if (k == kh_end(list)){
				LOAD_GLES(glGenTextures);
                k = kh_put(tex, list, texture, &ret);
                tex = kh_value(list, k) = malloc(sizeof(gltexture_t));
                tex->texture = texture;
                gles_glGenTextures(1, &tex->glname);
                tex->target = target;
                tex->width = 0;
                tex->height = 0;
                tex->uploaded = false;
                tex->mipmap_auto = 0;
                tex->mipmap_need = 0;
				tex->alpha = true;
				tex->streamed = false;
				tex->streamingID = -1;
				tex->min_filter = tex->mag_filter = GL_LINEAR;
                tex->data = NULL;
            } else {
                tex = kh_value(list, k);
            }
            state.texture.bound[state.texture.active] = tex;
            texture = tex->glname;
			if (texstream && tex->streamed)
				streamingID = tex->streamingID;
        } else {
            state.texture.bound[state.texture.active] = NULL;
        }

        state.texture.rect_arb[state.texture.active] = (target == GL_TEXTURE_RECTANGLE_ARB);
        target = map_tex_target(target);

        LOAD_GLES(glBindTexture);
		if (texstream && (streamingID>-1))
			ActivateStreaming(streamingID);
		else
			gles_glBindTexture(target, texture);
    }
}

// TODO: also glTexParameterf(v)?
void glTexParameteri(GLenum target, GLenum pname, GLint param) {
    PUSH_IF_COMPILING(glTexParameteri);
    LOAD_GLES(glTexParameteri);
    target = map_tex_target(target);
    gltexture_t *texture = state.texture.bound[state.texture.active];
    switch (pname) {
	case GL_TEXTURE_MIN_FILTER:
	case GL_TEXTURE_MAG_FILTER:
	    switch (param) {
		case GL_NEAREST_MIPMAP_NEAREST:
		case GL_NEAREST_MIPMAP_LINEAR:
		case GL_LINEAR_MIPMAP_NEAREST:
		case GL_LINEAR_MIPMAP_LINEAR:
		    if (texture)
			texture->mipmap_need = true;
		    if (automipmap==3)
			switch (param) {
			    case GL_NEAREST_MIPMAP_NEAREST:
			    case GL_NEAREST_MIPMAP_LINEAR:
				param = GL_NEAREST;
				break;
			    case GL_LINEAR_MIPMAP_NEAREST:
			    case GL_LINEAR_MIPMAP_LINEAR:
				param = GL_LINEAR;
				break;
			}
			if (pname==GL_TEXTURE_MIN_FILTER) texture->min_filter = param;
			if (pname==GL_TEXTURE_MAG_FILTER) texture->mag_filter = param;
		    break;
	    }
	case GL_TEXTURE_WRAP_S:
	case GL_TEXTURE_WRAP_T:
	    switch (param) {
		case GL_CLAMP:
		    param = GL_CLAMP_TO_EDGE;
		    break;
	    }
	    break;
	case GL_TEXTURE_MAX_LEVEL:
	    if (texture)
		texture->mipmap_auto = (param)?1:0;
	    return;			// not on GLES
	case GL_TEXTURE_MIN_LOD:
	case GL_TEXTURE_MAX_LOD:
	case GL_TEXTURE_LOD_BIAS:
	    return;			// not on GLES
	case GL_GENERATE_MIPMAP:
	    if (texture)
		texture->mipmap_auto = (param)?1:0;
	    break;
    }
    gles_glTexParameteri(target, pname, param);
}

void glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
    glTexParameteri(target, pname, param);
}

void glDeleteTextures(GLsizei n, const GLuint *textures) {
    LOAD_GLES(glDeleteTextures);
    khash_t(tex) *list = state.texture.list;
    if (list) {
        khint_t k;
        gltexture_t *tex;
        for (int i = 0; i < n; i++) {
            GLuint t = textures[i];
            k = kh_get(tex, list, t);
            if (k != kh_end(list)) {
                tex = kh_value(list, k);
                int a;
                for (a=0; a<MAX_TEX; a++) {
                    if (tex == state.texture.bound[a])
                        state.texture.bound[a] = NULL;
                }
				gles_glDeleteTextures(1, &tex->glname);
				if (texstream && tex->streamed)
					FreeStreamed(tex->streamingID);
                free(tex);
                kh_del(tex, list, k);
            }
        }
    }
}

void glGenTextures(GLsizei n, GLuint * textures) {
    if (n<=0) 
		return;
    LOAD_GLES(glGenTextures);
    gles_glGenTextures(n, textures);
    // now, add all the textures to the list
    int ret;
	khint_t k;
	khash_t(tex) *list = state.texture.list;
	if (! list) {
		list = state.texture.list = kh_init(tex);
		// segfaults if we don't do a single put
		kh_put(tex, list, 1, &ret);
		kh_del(tex, list, 1);
	}
	
	for (int i=0; i<n; i++) {
		k = kh_get(tex, list, textures[i]);
		gltexture_t *tex = NULL;;
		if (k == kh_end(list)){
			k = kh_put(tex, list, textures[i], &ret);
			tex = kh_value(list, k) = malloc(sizeof(gltexture_t));
			tex->texture = textures[i];
			tex->glname = textures[i];
			tex->width = 0;
			tex->height = 0;
			tex->uploaded = false;
			tex->mipmap_auto = 0;
			tex->mipmap_need = 0;
			tex->streamingID = -1;
			tex->streamed = false;
			tex->min_filter = tex->mag_filter = GL_NEAREST;
			tex->data = NULL;
		} else {
			tex = kh_value(list, k);
		}
	}
}

GLboolean glAreTexturesResident(GLsizei n, const GLuint *textures, GLboolean *residences) {
    return true;
}

void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params) {
	// simplification: not taking "target" into account here
	*params = 0;
	gltexture_t* bound = state.texture.bound[state.texture.active];
	switch (pname) {
		case GL_TEXTURE_WIDTH:
			if (target==GL_PROXY_TEXTURE_2D)
				(*params) = proxy_width>>level;
			else
				(*params) = ((bound)?bound->width:2048)>>level; 
			break;
		case GL_TEXTURE_HEIGHT: 
			if (target==GL_PROXY_TEXTURE_2D)
				(*params) = proxy_height>>level;
			else
				(*params) = ((bound)?bound->height:2048)>>level; 
			break;
		case GL_TEXTURE_INTERNAL_FORMAT:
			(*params) = GL_RGBA;
			break;
		case GL_TEXTURE_DEPTH:
			(*params) = 0;
			break;
		case GL_TEXTURE_RED_TYPE:
		case GL_TEXTURE_GREEN_TYPE:
		case GL_TEXTURE_BLUE_TYPE:
		case GL_TEXTURE_ALPHA_TYPE:
		case GL_TEXTURE_DEPTH_TYPE:
			(*params) = GL_FLOAT;
			break;
		case GL_TEXTURE_RED_SIZE:
		case GL_TEXTURE_GREEN_SIZE:
		case GL_TEXTURE_BLUE_SIZE:
		case GL_TEXTURE_ALPHA_SIZE:
			(*params) = 8;
			break;
		case GL_TEXTURE_DEPTH_SIZE:
			(*params) = 0;
			break;
		case GL_TEXTURE_COMPRESSED:
			(*params) = GL_FALSE;
			break;
		case GL_TEXTURE_COMPRESSED_IMAGE_SIZE:
			(*params) = (bound)?(bound->width*bound->height*4):0;
			break;
		default:
			printf("Stubbed glGetTexLevelParameteriv(%04x, %i, %04x, %p)\n", target, level, pname, params);
	}
}

void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid * img) {
//printf("glGetTexImage(0x%04X, %i, 0x%04X, 0x%04X, 0x%p)\n", target, level, format, type, img);
	if (state.texture.bound[state.texture.active]==NULL)
		return;		// no texture bounded...
	if (level != 0) {
		//TODO
		printf("STUBBED glGetTexImage with level=%i\n", level);
		return;
	}

	gltexture_t* bound = state.texture.bound[state.texture.active];
	int width = bound->width;
	int height = bound->height;
	
	if (texstream && bound->streamed) {
		pixel_convert(GetStreamingBuffer(bound->streamingID), &img, bound->width, bound->height, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, format, type);
		return;
	}
	
	if (texcopydata && bound->data) {
		pixel_convert(bound->data, &img, bound->width, bound->height, GL_RGBA, GL_UNSIGNED_BYTE, format, type);
	} else {
		// Setup an FBO the same size of the texture
		#define getOES(name, proto)	proto name = (proto)eglGetProcAddress(#name); if (name==NULL) printf("Warning! %s is NULL\n", #name)
		#define USEFBO
		#ifdef USEFBO
		// first, get all FBO functions...
		getOES(glIsRenderbufferOES, PFNGLISRENDERBUFFEROESPROC);
		getOES(glBindRenderbufferOES, PFNGLBINDRENDERBUFFEROESPROC);
		getOES(glDeleteRenderbuffersOES, PFNGLDELETERENDERBUFFERSOESPROC);
		getOES(glGenRenderbuffersOES, PFNGLGENRENDERBUFFERSOESPROC);
		getOES(glRenderbufferStorageOES, PFNGLRENDERBUFFERSTORAGEOESPROC);
		getOES(glGetRenderbufferParameterivOES, PFNGLGETRENDERBUFFERPARAMETERIVOESPROC);
		getOES(glIsFramebufferOES, PFNGLISFRAMEBUFFEROESPROC);
		getOES(glBindFramebufferOES, PFNGLBINDFRAMEBUFFEROESPROC);
		getOES(glDeleteFramebuffersOES, PFNGLDELETEFRAMEBUFFERSOESPROC);
		getOES(glGenFramebuffersOES, PFNGLGENFRAMEBUFFERSOESPROC);
		getOES(glCheckFramebufferStatusOES, PFNGLCHECKFRAMEBUFFERSTATUSOESPROC);
		getOES(glFramebufferRenderbufferOES, PFNGLFRAMEBUFFERRENDERBUFFEROESPROC);
		getOES(glFramebufferTexture2DOES, PFNGLFRAMEBUFFERTEXTURE2DOESPROC);
		getOES(glGetFramebufferAttachmentParameterivOES, PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVOESPROC);
		getOES(glGenerateMipmapOES, PFNGLGENERATEMIPMAPOESPROC);
		// and the DrawTex can be usefull too
		getOES(glDrawTexiOES, PFNGLDRAWTEXIOESPROC);
		
		// Now create the FBO
		GLint oldBind = bound->texture;
		GLuint fbo;
		#define USE_TEXTURE 1
		#ifdef  USE_TEXTURE
		void *temp = malloc(width * height * 4);
		memset(temp, 0, width * height * 4);
		GLuint temp_tex;
		glGenTextures(1, &temp_tex);
		glBindTexture(GL_TEXTURE_2D, temp_tex);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,
			GL_RGBA, GL_UNSIGNED_BYTE, temp);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
		glGenFramebuffersOES(1, &fbo);
		glBindFramebufferOES(GL_FRAMEBUFFER_OES, fbo);
		glFramebufferTexture2DOES(GL_FRAMEBUFFER_OES, GL_COLOR_ATTACHMENT0_OES, GL_TEXTURE_2D, temp_tex, 0);
		glClear(GL_COLOR_BUFFER_BIT);
		#else
		glGenFramebuffersOES(1, &fbo);
		glBindFramebufferOES(GL_FRAMEBUFFER_OES, fbo);
		
		GLuint rbo, depthRenderbuffer;
		glGenRenderbuffersOES(1, &rbo);
		glBindRenderbufferOES(GL_RENDERBUFFER_OES, rbo);
		glRenderbufferStorageOES(GL_RENDERBUFFER_OES, GL_RGBA8_OES, width, height);
		glFramebufferRenderbufferOES(GL_FRAMEBUFFER_OES, GL_COLOR_ATTACHMENT0_OES, GL_RENDERBUFFER_OES, rbo);

		glGenRenderbuffersOES(1, &depthRenderbuffer);
		glBindRenderbufferOES(GL_RENDERBUFFER_OES, depthRenderbuffer);
		glRenderbufferStorageOES(GL_RENDERBUFFER_OES, GL_DEPTH_COMPONENT16_OES, width, height);
		glFramebufferRenderbufferOES(GL_FRAMEBUFFER_OES, GL_DEPTH_ATTACHMENT_OES, GL_RENDERBUFFER_OES, depthRenderbuffer);
		#endif
/*
		GLenum status = glCheckFramebufferStatusOES(GL_FRAMEBUFFER_OES);
		if (status != GL_FRAMEBUFFER_COMPLETE_OES) {
			printf("glGetTexImage, incomplete FBO (%04x)", status);
		} 
*/
		glBindFramebufferOES(GL_FRAMEBUFFER_OES, 0);
		// Now, draw the texture inside FBO
		glPushAttrib(GL_CURRENT_BIT|GL_ENABLE_BIT|GL_VIEWPORT_BIT|GL_COLOR_BUFFER_BIT);
		glBindFramebufferOES(GL_FRAMEBUFFER_OES, fbo);
		glViewport(0, 0, width, height);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);	//*SEB TODO: Save Color before
		glDrawTexiOES(0, 0, 0, width, height);
		glEnable(GL_BLEND);
		glEnable(GL_ALPHA);
		// Read the pixels!
		glReadPixels(0, 0, width, height, format, type, img);	// using "full" version with conversion of format/type
		glPopAttrib();
		#ifdef USE_TEXTURE
		glBindFramebufferOES(GL_FRAMEBUFFER_OES, 0);
		glDeleteTextures(1, &temp_tex);
		free(temp);
		#else
		// Unmount FBO
		glBindRenderbufferOES(GL_RENDERBUFFER_OES, 0);
		glBindFramebufferOES(GL_FRAMEBUFFER_OES, 0);
		//glBindTexture(GL_TEXTURE_2D, oldBind);
		glDeleteRenderbuffersOES(1, &rbo);
		glDeleteRenderbuffersOES(1, &depthRenderbuffer);
		glDeleteFramebuffersOES(1, &fbo);
		#endif
		#else
		// the DrawTex can be usefull too
		getOES(glDrawTexiOES, PFNGLDRAWTEXIOESPROC);
		const EGLint attribListPbuffer[] =
		{
			EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
			EGL_RED_SIZE, 8,
			EGL_GREEN_SIZE, 8,
			EGL_BLUE_SIZE, 8,
			EGL_ALPHA_SIZE, 8,
			EGL_DEPTH_SIZE, 16,
			EGL_STENCIL_SIZE, 0,
			EGL_NONE
		};
		const EGLint srfPbufferAttr[] =
		{
			EGL_WIDTH, width,
			EGL_HEIGHT, height,
			EGL_COLORSPACE, GL_RGBA,
			EGL_TEXTURE_FORMAT, EGL_TEXTURE_RGBA,
			EGL_TEXTURE_TARGET, EGL_TEXTURE_2D,
			EGL_LARGEST_PBUFFER, EGL_TRUE,
			EGL_NONE
		};
		#endif
		#undef USEFBO
		#undef getOES
	}
}

void glActiveTexture( GLenum texture ) {
/* NewStage(state.list.active, STAGE_BINDTEX);
 if (state.list.compiling && state.list.active)
	state.list.active = extend_renderlist(state.list.active);*/
 PUSH_IF_COMPILING(glActiveTexture);
 
 if ((texture < GL_TEXTURE0) || (texture >= GL_TEXTURE0+MAX_TEX))
   return;
 state.texture.active = texture - GL_TEXTURE0;
 LOAD_GLES(glActiveTexture);
 gles_glActiveTexture(texture);
}

void glClientActiveTexture( GLenum texture ) {
 if ((texture < GL_TEXTURE0) || (texture >= GL_TEXTURE0+MAX_TEX))
   return;
 state.texture.client = texture - GL_TEXTURE0;
 LOAD_GLES(glClientActiveTexture);
 gles_glClientActiveTexture(texture);
}

void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * data) {
//printf("glReadPixels(%i, %i, %i, %i, 0x%04X, 0x%04X, 0x%p)\n", x, y, width, height, format, type, data);
    if (state.list.compiling && state.list.active)
	return;	// never in list
    LOAD_GLES(glReadPixels);
    if (format == GL_RGBA && format == GL_UNSIGNED_BYTE) {
	// easy passthru
	gles_glReadPixels(x, y, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);
	return;
    }
    // grab data in GL_RGBA format
    GLvoid *pixels = malloc(width*height*4);
    gles_glReadPixels(x, y, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
    if (! pixel_convert(pixels, &data, width, height,
					    GL_RGBA, GL_UNSIGNED_BYTE, format, type)) {
	printf("libGL ReadPixels error: (GL_RGBA, UNSIGNED_BYTE -> %#4x, %#4x )\n",
		format, type);
    }
    free(pixels);
    return;
}

void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset,
                                GLint x, GLint y, GLsizei width, GLsizei height) {
//printf("glCopyTexSubImage2D(%i, %i, %i, %i, %i, %i, %i, %i)\n", target, level, xoffset, yoffset, x, y, width, height);
 PUSH_IF_COMPILING(glCopyTexSubImage2D);
 
 LOAD_GLES(glCopyTexSubImage2D);
 
 gltexture_t* bound = state.texture.bound[state.texture.active];
 if (bound && bound->streamed) {
    void* buff = GetStreamingBuffer(bound->streamingID);
    if ((bound->width == width) && (bound->height == height) && (xoffset == yoffset == 0)) {
        glReadPixels(x, y, width, height, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, buff);
    } else {
        void* tmp = malloc(width*height*2);
        glReadPixels(x, y, width, height, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, tmp);
        for (int y=0; y<height; y++) {
            memcpy(buff+((yoffset+y)*bound->width+xoffset)*2, tmp+y*width*2, width*2);
        }
        free(tmp);
    }
 } else
    gles_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}

GLboolean isDXTc(GLenum format) {
	switch (format) {
		case COMPRESSED_RGB_S3TC_DXT1_EXT:
		case COMPRESSED_RGBA_S3TC_DXT1_EXT:
		case COMPRESSED_RGBA_S3TC_DXT3_EXT:
		case COMPRESSED_RGBA_S3TC_DXT5_EXT:
			return true;
	}
	return false;
}

GLvoid *uncompressDXTc(GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data) {
	// uncompress a DXTc image
	// get pixel size of uncompressed image => fixed RGBA
	int pixelsize = 4;
/*	if (format==COMPRESSED_RGB_S3TC_DXT1_EXT)
		pixelsize = 3;*/
	// check with the size of the input data stream if the stream is in fact uncompressed
	if (imageSize == width*height*pixelsize || data==NULL) {
		// uncompressed stream
		return data;
	}
	// alloc memory
	GLvoid *pixels = malloc(width*height*pixelsize);
	// uncompress loop
	int blocksize;
	switch (format) {
		case COMPRESSED_RGB_S3TC_DXT1_EXT:
		case COMPRESSED_RGBA_S3TC_DXT1_EXT:
			blocksize = 8;
			break;
		case COMPRESSED_RGBA_S3TC_DXT3_EXT:
		case COMPRESSED_RGBA_S3TC_DXT5_EXT:
			blocksize = 16;
			break;
	}
	uintptr_t src = (uintptr_t) data;
	for (int y=0; y<height; y+=4) {
		for (int x=0; x<width; x+=4) {
			switch(format) {
				case COMPRESSED_RGB_S3TC_DXT1_EXT:
				case COMPRESSED_RGBA_S3TC_DXT1_EXT:
					DecompressBlockDXT1(x, y, width, (uint8_t*)src, pixels);
					break;
				case COMPRESSED_RGBA_S3TC_DXT3_EXT:
					DecompressBlockDXT3(x, y, width, (uint8_t*)src, pixels);
					break;
				case COMPRESSED_RGBA_S3TC_DXT5_EXT:
					DecompressBlockDXT5(x, y, width, (uint8_t*)src, pixels);
					break;
			}
			src+=blocksize;
		}
	}
	return pixels;
}

void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat,
							GLsizei width, GLsizei height, GLint border,
							GLsizei imageSize, const GLvoid *data) 
{
    if (target == GL_PROXY_TEXTURE_2D) {
	proxy_width = (width>2048)?0:width;
	proxy_height = (height>2048)?0:height;
	return;
    }
    if (state.texture.bound[state.texture.active]==NULL)
	    return;		// no texture bounded...
    if (level != 0) {
	    //TODO
	    //printf("STUBBED glCompressedTexImage2D with level=%i\n", level);
	    return;
    }
//printf("glCompressedTexImage2D with size(%i,%i), internalformat=%04x, imagesize=%i\n", width, height, internalformat, imageSize);
    LOAD_GLES(glCompressedTexImage2D);
    if (isDXTc(internalformat)) {
		GLvoid *pixels;
		if (width<4 || height<4) {	// can happens :(
			GLvoid *tmp;
			GLsizei nw=width;
			GLsizei nh=height;
			if (nw<4) nw = 4;
			if (nh<4) nh = 4;
			tmp = uncompressDXTc(nw, nh, internalformat, imageSize, data);
			pixels = malloc(4*width*height);
			// crop
			for (int y=0; y<height; y++)
				memcpy(pixels+y*width*4, tmp+y*nw*4, width*4);
			free(tmp);
		} else {
			pixels = uncompressDXTc(width, height, internalformat, imageSize, data);
		}
		// automaticaly reduce the pixel size
		GLvoid *half=pixels;
		state.texture.bound[state.texture.active]->alpha = (internalformat==COMPRESSED_RGB_S3TC_DXT1_EXT)?false:true;
		int fact = 0;
		#if 1
		if (pixel_thirdscale(pixels, &half, width, height, GL_RGBA, GL_UNSIGNED_BYTE)) fact = 1;
		int oldalign;
		glGetIntegerv(GL_UNPACK_ALIGNMENT, &oldalign);
		if (oldalign!=1) glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexImage2D(target, level, GL_RGBA, width>>fact, height>>fact, border, GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4, half);
		if (oldalign!=1) glPixelStorei(GL_UNPACK_ALIGNMENT, oldalign);
		#else
		if (pixel_halfscale(pixels, &half, width, height, GL_RGBA, GL_UNSIGNED_BYTE)) fact = 1;
		glTexImage2D(target, level, GL_RGBA, width>>fact, height>>fact, border, GL_RGBA, GL_UNSIGNED_BYTE, half);
		#endif
		if (half!=pixels)
			free(half);
		if (pixels!=data)
			free(pixels);
	} else {
	    state.texture.bound[state.texture.active]->alpha = true;
	    gles_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
	}
}

void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset,
							   GLsizei width, GLsizei height, GLenum format, 
							   GLsizei imageSize, const GLvoid *data) 
{
	if (state.texture.bound[state.texture.active]==NULL)
		return;		// no texture bounded...
	if (level != 0) {
		//TODO
		//printf("STUBBED glCompressedTexSubImage2D with level=%i\n", level);
		return;
	}
//printf("glCompressedTexSubImage2D with unpack_row_length(%i), size(%i,%i), pos(%i,%i) and skip={%i,%i}, internalformat=%04x, imagesize=%i\n", state.texture.unpack_row_length, width, height, xoffset, yoffset, state.texture.unpack_skip_pixels, state.texture.unpack_skip_rows, format, imageSize);
    LOAD_GLES(glCompressedTexSubImage2D);
    if (isDXTc(format)) {
		GLvoid *pixels;
		if (width<4 || height<4) {	// can happens :(
			GLvoid *tmp;
			GLsizei nw=width;
			GLsizei nh=height;
			if (nw<4) nw = 4;
			if (nh<4) nh = 4;
			tmp = uncompressDXTc(nw, nh, format, imageSize, data);
			pixels = malloc(4*width*height);
			// crop
			for (int y=0; y<height; y++)
				memcpy(pixels+y*width*4, tmp+y*nw*4, width*4);
			free(tmp);
		} else {
			pixels = uncompressDXTc(width, height, format, imageSize, data);
		}
		GLvoid *half=pixels;
		#if 1
		pixel_thirdscale(pixels, &half, width, height, GL_RGBA, GL_UNSIGNED_BYTE);
		int oldalign;
		glGetIntegerv(GL_UNPACK_ALIGNMENT, &oldalign);
		if (oldalign!=1) glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glTexSubImage2D(target, level, xoffset/2, yoffset/2, width/2, height/2, GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4, half);
		if (oldalign!=1) glPixelStorei(GL_UNPACK_ALIGNMENT, oldalign);
		#else
		pixel_halfscale(pixels, &half, width, height, GL_RGBA, GL_UNSIGNED_BYTE);
		glTexSubImage2D(target, level, xoffset/2, yoffset/2, width/2, height/2, GL_RGBA, GL_UNSIGNED_BYTE, half);
		#endif
		if (half!=pixels)
			free(half);
		if (pixels!=data)
			free(pixels);
	} else {
		gles_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
	}
								   
}
