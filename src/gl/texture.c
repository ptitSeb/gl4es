#include "texture.h"
#include "raster.h"
#include "decompress.h"
#include "debug.h"
#include "stb_dxt_104.h"
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include "gles.h"
#include "../glx/streaming.h"

#ifndef GL_TEXTURE_STREAM_IMG  
#define GL_TEXTURE_STREAM_IMG                                   0x8C0D     
#endif

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
        
    GLfloat iwidth, iheight;
    iwidth = 1.0f/width;
    iheight = 1.0f/height;

    for (int i = 0; i < len; i++) {
        tex[0] *= iwidth;
        tex[1] *= iheight;
        tex += 4;
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
        tex += 4;
    }
}

/* Setup the texture coordinates
 * 
 * Have to check is ARB_RECTANGLE is used
 * Or some NPOT texture used
 * Or SHRINKED texure used
 */
void tex_setup_texcoord(GLuint texunit, GLuint len) {
    LOAD_GLES(glTexCoordPointer);
    GLuint old = glstate.texture.client;
    
    static void * tex[8] = {0,0,0,0,0,0,0,0};   // hugly but convenient...
    
    if (tex[texunit]) {
        free(tex[texunit]);
        tex[texunit]=NULL;
    }
        
    gltexture_t *bound = glstate.texture.bound[texunit];
    
    // check if some changes are needed
    int changes = 0;
    if ((glstate.texture.rect_arb[texunit]) || 
        (bound && ((bound->width!=bound->nwidth)||(bound->height!=bound->nheight)||
        (bound->shrink && (glstate.vao->pointers.tex_coord[texunit].type!=GL_FLOAT) && (glstate.vao->pointers.tex_coord[texunit].type!=GL_DOUBLE)))))
        changes = 1;
	if (old!=texunit) glshim_glClientActiveTexture(texunit+GL_TEXTURE0);
    if (changes) {
        // first convert to GLfloat, without normalization
        tex[texunit] = copy_gl_pointer_tex(&glstate.vao->pointers.tex_coord[texunit], 4, 0, len, glstate.vao->pointers.tex_coord[texunit].buffer);
        if (!tex[texunit]) {
            printf("LibGL: Error with Texture tranform\n");
            gles_glTexCoordPointer(len, glstate.vao->pointers.tex_coord[texunit].type, glstate.vao->pointers.tex_coord[texunit].stride, glstate.vao->pointers.tex_coord[texunit].pointer);
            if (old!=texunit) glshim_glClientActiveTexture(old+GL_TEXTURE0);
            return;
        }
        // Normalize if needed
        if ((glstate.texture.rect_arb[texunit]) || ((glstate.vao->pointers.tex_coord[texunit].type!=GL_FLOAT) && (glstate.vao->pointers.tex_coord[texunit].type!=GL_DOUBLE)))
            tex_coord_rect_arb(tex[texunit], len, bound->width, bound->height);
        if ((bound->width!=bound->nwidth) || (bound->height!=bound->nheight))
            tex_coord_npot(tex[texunit], len, bound->width, bound->height, bound->nwidth, bound->nheight);
        // All done, setup the texcoord array now
        gles_glTexCoordPointer(4, GL_FLOAT, 0, tex[texunit]);
    } else {
        gles_glTexCoordPointer(glstate.vao->pointers.tex_coord[texunit].size, glstate.vao->pointers.tex_coord[texunit].type, glstate.vao->pointers.tex_coord[texunit].stride, glstate.vao->pointers.tex_coord[texunit].pointer);
    }
	if (old!=texunit) glshim_glClientActiveTexture(old+GL_TEXTURE0);
}

int nolumalpha = 0;

static int is_fake_compressed_rgb(GLenum internalformat)
{
    if(internalformat==GL_COMPRESSED_RGB) return 1;
    if(internalformat==GL_COMPRESSED_RGB_S3TC_DXT1_EXT) return 1;
    return 0;
}
static int is_fake_compressed_rgba(GLenum internalformat)
{
    if(internalformat==GL_COMPRESSED_RGBA) return 1;
    if(internalformat==GL_COMPRESSED_RGBA_S3TC_DXT1_EXT) return 1;
    if(internalformat==GL_COMPRESSED_RGBA_S3TC_DXT3_EXT) return 1;
    if(internalformat==GL_COMPRESSED_RGBA_S3TC_DXT5_EXT) return 1;
    return 0;
}

void internal2format_type(GLenum internalformat, GLenum *format, GLenum *type)
{
    switch(internalformat) {
        case GL_ALPHA:
            *format = GL_ALPHA;
            *type = GL_UNSIGNED_BYTE;
            break;
        case GL_LUMINANCE:
            *format = GL_LUMINANCE;
            *type = GL_UNSIGNED_BYTE;
            break;
        case GL_LUMINANCE_ALPHA:
            *format = GL_LUMINANCE_ALPHA;
            *type = GL_UNSIGNED_BYTE;
            break;
        case GL_RGB5:
            *format = GL_RGB;
            *type = GL_UNSIGNED_SHORT_5_6_5;
            break;
        case GL_RGB:
            *format = GL_RGB;
            *type = GL_UNSIGNED_BYTE;
            break;
        case GL_RGB5_A1:
            *format = GL_RGBA;
            *type = GL_UNSIGNED_SHORT_5_5_5_1;
            break;
        case GL_RGBA4:
            *format = GL_RGBA;
            *type = GL_UNSIGNED_SHORT_4_4_4_4;
            break;
        case GL_RGBA:
            *format = GL_RGBA;
            *type = GL_UNSIGNED_BYTE;
            break;
        default:
            printf("LIBGL: Warning, unknown Internalformat (%s)\n", PrintEnum(internalformat));
            *format = GL_RGBA;
            *type = GL_UNSIGNED_BYTE;
            break;
    }
}

static void *swizzle_texture(GLsizei width, GLsizei height,
                             GLenum *format, GLenum *type,
                             GLenum intermediaryformat, GLenum internalformat,
                             const GLvoid *data) {
    bool convert = false;
    GLenum dest_format = GL_RGBA;
    GLenum dest_type = GL_UNSIGNED_BYTE;
	 switch (*format) {
        case GL_LUMINANCE:
            dest_format = GL_LUMINANCE;
            break;
        case GL_RGB:
            dest_format = GL_RGB;
            break;
        case GL_ALPHA:
            dest_format = GL_ALPHA;
        case GL_RGBA:
            break;
        case GL_LUMINANCE8_ALPHA8:
            if(nolumalpha)
                convert = true;
            else {
                dest_format = GL_LUMINANCE_ALPHA;
                *format = GL_LUMINANCE_ALPHA;
            }
            break;
        case GL_LUMINANCE_ALPHA:
            if(nolumalpha)
                convert = true;
            else
                dest_format = GL_LUMINANCE_ALPHA;
            break;
        // vvvvv all this are internal formats, so it should not happens
        case GL_RGB5:
            dest_format = GL_RGB;
            dest_type = GL_UNSIGNED_SHORT_5_6_5;
            convert = true;
            break;
        case GL_RGB8:
            dest_format = GL_RGB;
            *format = GL_RGB;
            break;
        case GL_RGBA4:
            dest_format = GL_RGBA;
            dest_type = GL_UNSIGNED_SHORT_4_4_4_4;
            *format = GL_RGBA;
            break;
        case GL_RGBA8:
            dest_format = GL_RGBA;
            *format = GL_RGBA;
            break;
        default:
            convert = true;
            break;
    }
    switch (*type) {
        case GL_UNSIGNED_SHORT_4_4_4_4_REV:
            if(dest_format==GL_RGBA)
                dest_type = GL_UNSIGNED_SHORT_4_4_4_4;
            convert = true;
            break;
        case GL_UNSIGNED_SHORT_4_4_4_4:
            if(dest_format==GL_RGBA)
                dest_type = GL_UNSIGNED_SHORT_4_4_4_4;
            else
                convert = true;
            break;
        case GL_UNSIGNED_SHORT_1_5_5_5_REV:
            if(dest_format==GL_RGBA)
                dest_type = GL_UNSIGNED_SHORT_5_5_5_1;
            convert = true;
            break;
        case GL_UNSIGNED_SHORT_5_5_5_1:
            if(dest_format==GL_RGBA)
                dest_type = GL_UNSIGNED_SHORT_5_5_5_1;
            else
                convert = true;
            break;
        case GL_UNSIGNED_SHORT_5_6_5_REV:
            if (dest_format==GL_RGB)
                dest_type = GL_UNSIGNED_SHORT_5_6_5;
            convert = true;
            break;
        case GL_UNSIGNED_SHORT_5_6_5:
            if (dest_format==GL_RGB)
                dest_type = GL_UNSIGNED_SHORT_5_6_5;
            else
                convert = true;
            break;
        case GL_UNSIGNED_BYTE:
            break;
        case GL_UNSIGNED_INT_8_8_8_8_REV:
            *type = GL_UNSIGNED_BYTE;
            break;
        default:
            convert = true;
            break;
    }
    // compressed format are not handled here, so mask them....
    if (is_fake_compressed_rgb(intermediaryformat)) intermediaryformat=GL_RGB;
    if (is_fake_compressed_rgba(intermediaryformat)) intermediaryformat=GL_RGBA;
    if (is_fake_compressed_rgb(internalformat)) internalformat=GL_RGB;
    if (is_fake_compressed_rgba(internalformat)) internalformat=GL_RGBA;
    
    if(*format != intermediaryformat || intermediaryformat!=internalformat) {
        internal2format_type(intermediaryformat, &dest_format, &dest_type);
        convert = true;
    }
	if (data) {
		if (convert) {
			GLvoid *pixels = (GLvoid *)data;
			if (! pixel_convert(data, &pixels, width, height,
								*format, *type, dest_format, dest_type, 0)) {
				printf("libGL swizzle error: (%s, %s -> %s, %s)\n",
					PrintEnum(*format), PrintEnum(*type), PrintEnum(dest_format), PrintEnum(dest_type));
				return NULL;
			}
			*type = dest_type;
			*format = dest_format;
            if(dest_format!=internalformat) {
                GLvoid *pix2 = (GLvoid *)pixels;
                internal2format_type(internalformat, &dest_format, &dest_type);
                if (! pixel_convert(pixels, &pix2, width, height,
                                    *format, *type, dest_format, dest_type, 0)) {
                    printf("libGL swizzle error: (%s, %s -> %s, %s)\n",
                        PrintEnum(dest_format), PrintEnum(dest_type), PrintEnum(internalformat), PrintEnum(dest_type));
                    return NULL;
                }
                if(pix2!=pixels) {
                    if (pixels!=data)
                        free(pixels);
                    pixels = pix2;
                }
                *type = dest_type;
                *format = dest_format;
            }
			GLvoid *pix2 = pixels;
			if (raster_need_transform())
				if (!pixel_transform(data, &pixels, width, height,
								*format, *type, raster_scale, raster_bias)) {
					printf("libGL swizzle/convert error: (%s, %s -> %s, %s)\n",
						PrintEnum(*format), PrintEnum(*type), PrintEnum(dest_format), PrintEnum(dest_type));
					pix2 = pixels;
				}
			if (pix2!=pixels && pixels!=data)
				free(pixels);
			return pix2;
		} 
    } else {
		if (convert) {
            internal2format_type(internalformat, &dest_format, &dest_type); // in case they are differents
			*type = dest_type;
			*format = dest_format;
		}
	}
    return (void *)data;
}

GLenum swizzle_internalformat(GLenum *internalformat) {
    GLenum ret = *internalformat;
    GLenum sret;
    switch(*internalformat) {
        case GL_R:
        case 1: 
            ret = GL_LUMINANCE; sret = GL_LUMINANCE; 
            break;
        case GL_RG:
        case 2: 
            ret = GL_LUMINANCE_ALPHA;
            if (nolumalpha)
                sret = GL_RGBA;
            else
                sret = GL_LUMINANCE_ALPHA;
            break;
        case GL_RGB5:
            sret = GL_RGB5;
            break;
        case GL_RGB8:
        case GL_RGB:
        case GL_BGR:
        case GL_RGB16:
        case GL_RGB16F:
        case GL_RGB32F:
        case 3: 
            ret = GL_RGB; sret = GL_RGB; 
            break;
        case GL_RGBA4:
            sret = GL_RGBA4;
            break;
        case GL_RGB5_A1:
            sret = GL_RGB5_A1;
            break;
        case GL_RGBA:
        case GL_RGBA8:
        case GL_BGRA:
        case GL_RGBA16:
        case GL_RGBA16F:
        case GL_RGBA32F:
        case GL_RGB10_A2:
        case 4: 
            ret = GL_RGBA; sret = GL_RGBA; 
            break;
        case GL_ALPHA8:
        case GL_ALPHA:
            ret = GL_ALPHA; sret = GL_ALPHA;
            break;
        case GL_LUMINANCE8:
        case GL_LUMINANCE16:
        case GL_LUMINANCE:
            ret = GL_LUMINANCE; sret = GL_LUMINANCE;
            break;
        case GL_LUMINANCE4_ALPHA4:
        case GL_LUMINANCE8_ALPHA8:
        case GL_LUMINANCE16_ALPHA16:
        case GL_LUMINANCE_ALPHA:
            ret = GL_LUMINANCE_ALPHA;
            if (nolumalpha)
                sret = GL_RGBA;
            else
                sret = GL_LUMINANCE_ALPHA;
            break;
        // compressed format...
        case GL_COMPRESSED_ALPHA:
            ret = GL_COMPRESSED_RGBA;
            sret = GL_ALPHA;
            break;
        case GL_COMPRESSED_LUMINANCE:
            ret = GL_COMPRESSED_RGB;
            sret = GL_LUMINANCE;
            break;
        case GL_COMPRESSED_LUMINANCE_ALPHA:
            ret = GL_COMPRESSED_RGBA;
            if (nolumalpha)
                sret = GL_RGBA;
            else
                sret = GL_LUMINANCE_ALPHA;
            break;
        case GL_COMPRESSED_RGB:
            sret = GL_RGB;
            break;
        case GL_COMPRESSED_RGBA:
            sret = GL_RGBA;
            break;
        case GL_COMPRESSED_RGB_S3TC_DXT1_EXT:
            ret = GL_COMPRESSED_RGB;
            sret = GL_RGB;
            break;
        case GL_COMPRESSED_RGBA_S3TC_DXT1_EXT:  // not good...
        case GL_COMPRESSED_RGBA_S3TC_DXT3_EXT:  // not good, but there is no DXT3 compressor
        case GL_COMPRESSED_RGBA_S3TC_DXT5_EXT:
            ret = GL_COMPRESSED_RGBA;
            sret = GL_RGBA;
            break;
        default:
            ret = GL_RGBA;
            sret = GL_RGBA;
            break;
        // Default...RGBA / RGBA will be fine....
    }
    *internalformat = ret;
    return sret;
}

int automipmap = 0;
int texcopydata = 0;
int tested_env = 0;
int texshrink = 0;
int texdump = 0;
int alphahack = 0;
int texstream = 0;
int copytex = 0;
static int default_tex_mipmap = 0;

static int proxy_width = 0;
static int proxy_height = 0;
static GLint proxy_intformat = 0;

void glshim_glTexImage2D(GLenum target, GLint level, GLint internalformat,
                  GLsizei width, GLsizei height, GLint border,
                  GLenum format, GLenum type, const GLvoid *data) {

    //printf("glTexImage2D on target=%s with unpack_row_length(%i), size(%i,%i) and skip(%i,%i), format(internal)=%s(%s), type=%s, data=%08x, level=%i (mipmap_need=%i, mipmap_auto=%i) => texture=%u (streamed=%i), glstate.list.compiling=%d\n", PrintEnum(target), glstate.texture.unpack_row_length, width, height, glstate.texture.unpack_skip_pixels, glstate.texture.unpack_skip_rows, PrintEnum(format), PrintEnum(internalformat), PrintEnum(type), data, level, (glstate.texture.bound[glstate.texture.active])?glstate.texture.bound[glstate.texture.active]->mipmap_need:0, (glstate.texture.bound[glstate.texture.active])?glstate.texture.bound[glstate.texture.active]->mipmap_auto:0, (glstate.texture.bound[glstate.texture.active])?glstate.texture.bound[glstate.texture.active]->texture:0, (glstate.texture.bound[glstate.texture.active])?glstate.texture.bound[glstate.texture.active]->streamed:0, glstate.list.compiling);
    // proxy case
    if (target == GL_PROXY_TEXTURE_2D) {
        proxy_width = ((width<<level)>(texshrink>=8)?8192:2048)?0:width;
        proxy_height = ((height<<level)>(texshrink>=8)?8192:2048)?0:height;
        proxy_intformat = swizzle_internalformat(&internalformat);
        return;
    }
    //PUSH_IF_COMPILING(glTexImage2D);
    GLuint old_glbatch = glstate.gl_batch;
    if (glstate.gl_batch) {
        flush();
        glstate.gl_batch = 0;
    }

    GLvoid *datab = (GLvoid*)data;
    
	if (glstate.vao->unpack)
		datab += (uintptr_t)glstate.vao->pack->data;
        
    GLvoid *pixels = (GLvoid *)datab;
    border = 0;	//TODO: something?
    noerrorShim();

    gltexture_t *bound = glstate.texture.bound[glstate.texture.active];
    if (bound) bound->alpha = pixel_hasalpha(format);
    if (automipmap) {
        if (bound && (level>0))
            if ((automipmap==1) || (automipmap==3) || bound->mipmap_need) {
                glstate.gl_batch = old_glbatch;
                return;			// has been handled by auto_mipmap
            }
            else
                bound->mipmap_need = 1;
     }
     GLenum new_format = swizzle_internalformat(&internalformat);
     if (bound && (level==0)) {
         bound->orig_internal = internalformat;
         bound->internalformat = new_format;
     }
     if (datab) {

        // implements GL_UNPACK_ROW_LENGTH
        if ((glstate.texture.unpack_row_length && glstate.texture.unpack_row_length != width) || glstate.texture.unpack_skip_pixels || glstate.texture.unpack_skip_rows) {
            int imgWidth, pixelSize;
            pixelSize = pixel_sizeof(format, type);
            imgWidth = ((glstate.texture.unpack_row_length)? glstate.texture.unpack_row_length:width) * pixelSize;
            GLubyte *dst = (GLubyte *)malloc(width * height * pixelSize);
            pixels = (GLvoid *)dst;
            const GLubyte *src = (GLubyte *)datab;
            src += glstate.texture.unpack_skip_pixels * pixelSize + glstate.texture.unpack_skip_rows * imgWidth;
            for (int y = 0; y < height; y += 1) {
                memcpy(dst, src, width * pixelSize);
                src += imgWidth;
                dst += width;
            }
        }

        GLvoid *old = pixels;
        pixels = (GLvoid *)swizzle_texture(width, height, &format, &type, internalformat, new_format, old);
        if (old != pixels && old != datab) {
            free(old);
        }

        if (bound) {
        bound->shrink = 0;
        switch(texshrink) {
            case 0: // nothing
                break;
            case 1: //everything / 2
                if ((width > 1) && (height > 1)) {
                    GLvoid *out = pixels;
                    GLfloat ratio = 0.5;
                    pixel_scale(pixels, &out, width, height, ratio, format, type);
                    if (out != pixels && pixels!=datab)
                        free(pixels);
                    pixels = out;
                    width *= ratio;
                    height *= ratio;
                    bound->shrink = 1;
                }
                break;
            case 2: //only > 512 /2
            case 7: //only > 512 /2 , but not for empty texture
                if (((width%2==0) && (height%2==0)) && 
                    ((width > 512) && (height > 8)) || ((height > 512) && (width > 8))) {
                    GLvoid *out = pixels;
                    pixel_halfscale(pixels, &out, width, height, format, type);
                    if (out != pixels && pixels!=datab)
                        free(pixels);
                    pixels = out;
                    width /= 2;
                    height /= 2;
                    bound->shrink = 1;
                }
                break;
            case 3: //only > 256 /2
                if (((width%2==0) && (height%2==0)) && 
                    ((width > 256) && (height > 8)) || ((height > 256) && (width > 8))) {
                    GLvoid *out = pixels;
                    pixel_halfscale(pixels, &out, width, height, format, type);
                    if (out != pixels && pixels!=datab)
                        free(pixels);
                    pixels = out;
                    width /= 2;
                    height /= 2;
                    bound->shrink = 1;
                }
                break;
            case 4: //only > 256 /2, >=1024 /4
            case 5: //every > 256 is downscaled to 256, but not for empty texture   (as there is no downscale stronger than 4, there are the same)
                if (((width%4==0) && (height%4==0)) && 
                    ((width > 256) && (height > 8)) || ((height > 256) && (width > 8))) {
                    if ((width>=1024) || (height>=1024)) {
                        GLvoid *out = pixels;
                        pixel_quarterscale(pixels, &out, width, height, format, type);
                        if (out != pixels && pixels!=datab)
                            free(pixels);
                        pixels = out;
                        width /= 4;
                        height /= 4;
                        bound->shrink = 2;
                    } else {
                        GLvoid *out = pixels;
                        pixel_halfscale(pixels, &out, width, height, format, type);
                        if (out != pixels && pixels!=datab)
                            free(pixels);
                        pixels = out;
                        width /= 2;
                        height /= 2;
                        bound->shrink = 1;
                    }
                }
                break;
            /*case 5: //every > 256 is downscaled to 256, but not for empty texture
                while (((width%2==0) && (height%2==0)) && 
                    ((width > 256) && (height > 8)) || ((height > 256) && (width > 8))) {
                    GLvoid *out = pixels;
                    pixel_halfscale(pixels, &out, width, height, format, type);
                    if (out != pixels && pixels!=datab)
                        free(pixels);
                    pixels = out;
                    width /= 2;
                    height /= 2;
                    bound->shrink+=1;
                }
                break;*/
            case 6: //only > 128 /2, >=512 is downscaled to 256, but not for empty texture
                if (((width%2==0) && (height%2==0)) && 
                    ((width > 128) && (height > 8)) || ((height > 128) && (width > 8))) {
                    if (((width%2==0) && (height%2==0)) && (width>=512) || (height>=512)) {
                        while (((width > 256) && (height > 8)) || ((height > 256) && (width > 8))) {
                            GLvoid *out = pixels;
                            pixel_halfscale(pixels, &out, width, height, format, type);
                            if (out != pixels && pixels!=datab)
                                free(pixels);
                            pixels = out;
                            width /= 2;
                            height /= 2;
                            bound->shrink=1;
                        }
                    } else {
                        GLvoid *out = pixels;
                        pixel_halfscale(pixels, &out, width, height, format, type);
                        if (out != pixels && pixels!=datab)
                            free(pixels);
                        pixels = out;
                        width /= 2;
                        height /= 2;
                        bound->shrink = 1;
                    }
                }
                break;
            case 8: //advertise 8192 max texture size, but >2048 are shrinked to 2048
                if ((width>4096) || (height>4096)) {
                    GLvoid *out = pixels;
                    pixel_quarterscale(pixels, &out, width, height, format, type);
                    if (out != pixels && pixels!=datab)
                        free(pixels);
                    pixels = out;
                    width /= 4;
                    height /= 4;
                    bound->shrink=2;
                } else
                if ((width>2048) || (height>2048)) {
                    GLvoid *out = pixels;
                    pixel_halfscale(pixels, &out, width, height, format, type);
                    if (out != pixels && pixels!=datab)
                        free(pixels);
                    pixels = out;
                    width /= 2;
                    height /= 2;
                    bound->shrink=1;
                }
                break;
            case 9: //advertise 8192 max texture size, but >4096 are quadshrinked and >512 are shrinked, but not for empty texture
                if ((width>4096) || (height>4096)) {
                    GLvoid *out = pixels;
                    pixel_quarterscale(pixels, &out, width, height, format, type);
                    if (out != pixels && pixels!=datab)
                        free(pixels);
                    pixels = out;
                    width /= 4;
                    height /= 4;
                    bound->shrink=2;
                } else
                if ((width>512) || (height>512)) {
                    GLvoid *out = pixels;
                    pixel_halfscale(pixels, &out, width, height, format, type);
                    if (out != pixels && pixels!=datab)
                        free(pixels);
                    pixels = out;
                    width /= 2;
                    height /= 2;
                    bound->shrink=1;
                }
                break;
            case 10://advertise 8192 max texture size, but >2048 are quadshrinked and >512 are shrinked, but not for empty texture
                if ((width>2048) || (height>2048)) {
                    GLvoid *out = pixels;
                    pixel_quarterscale(pixels, &out, width, height, format, type);
                    if (out != pixels && pixels!=datab)
                        free(pixels);
                    pixels = out;
                    width /= 4;
                    height /= 4;
                    bound->shrink=2;
                } else
                if ((width>512) || (height>512)) {
                    GLvoid *out = pixels;
                    pixel_halfscale(pixels, &out, width, height, format, type);
                    if (out != pixels && pixels!=datab)
                        free(pixels);
                    pixels = out;
                    width /= 2;
                    height /= 2;
                    bound->shrink=1;
                }
                break;
            }
        }
        
        if (texdump) {
            if (bound) {
                pixel_to_ppm(pixels, width, height, format, type, bound->texture);
            }
        }
    } else {
#ifdef TEXSTREAM
	    if (texstream && bound && (target==GL_TEXTURE_2D) && (width>=256 && height>=256) && 
		((internalformat==GL_RGB) || (internalformat==3) || (internalformat==GL_RGB8) || (internalformat==GL_BGR) || (internalformat==GL_RGB5)) || (texstream==2) ) {
			bound->streamingID = AddStreamed(width, height, bound->texture);
			if (bound->streamingID>-1) {	// success
				bound->streamed = true;
				ApplyFilterID(bound->streamingID, bound->min_filter, bound->mag_filter);
				GLboolean tmp = glstate.enable.texture_2d[glstate.texture.active];
				LOAD_GLES(glDisable);
				LOAD_GLES(glEnable);
				if (tmp)
				    gles_glDisable(GL_TEXTURE_2D);
				ActivateStreaming(bound->streamingID);	//Activate the newly created texture
				format = GL_RGB;
				type = GL_UNSIGNED_SHORT_5_6_5;
				if (tmp)
				    gles_glEnable(GL_TEXTURE_STREAM_IMG);
				}
	    }
#endif
	    if (bound) {
            bound->shrink = 0;
            if (!bound->streamed)
                swizzle_texture(width, height, &format, &type, internalformat, new_format, NULL);	// convert format even if data is NULL
            if ((texshrink>0) && !bound->streamed) {
                switch(texshrink) {
                    case 1: //everything / 2
                            width /= 2;
                            height /= 2;
                            bound->shrink = 1;
                            break;
                    case 2: //only > 512 /2
                        if((width>512) || (height>512)) {
                            width /= 2;
                            height /= 2;
                            bound->shrink = 1;
                        }
                        break;
                    case 3: //only > 256 /2
                        if((width>256) || (height>256)) {
                            width /= 2;
                            height /= 2;
                            bound->shrink = 1;
                        }
                        break;
                    case 4: //only > 256 /2, >=1024 /4
                        if((width>1024) || (height>1024)) {
                            width /= 4;
                            height /= 4;
                            bound->shrink = 2;
                        } else if((width>256) || (height>256)) {
                            width /= 2;
                            height /= 2;
                            bound->shrink = 1;
                        }
                        break;
                    case 5: //every > 256 is downscaled to 256, but not for empty texture
                        break;
                    case 6: //only > 128 /2, >=512 is downscaled to 256 ), but not for empty texture
                        break;
                    case 7: //only > 512 /2, but not for empty texture
                        break;
                    case 8: //advertise 8192 max texture size, but >2048 are shrinked to 2048
                    case 9: //advertise 8192 max texture size, but >4096 are quadshrinked and >512 are shrinked, but not for empty texture (but >2048 are not supported anyway)
                    case 10://advertise 8192 max texture size, but >2048 are quadshrinked and >512 are shrinked, but not for empty texture (but >2048 are not supported anyway)
                        if((width>4096) || (height>4096)) {
                            width /= 4;
                            height /= 4;
                            bound->shrink = 2;
                        } else if((width>2048) || (height>2048)) {
                            width /= 2;
                            height /= 2;
                            bound->shrink = 1;
                        }                    
                        break;
                }
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
                bound->format = format;
                bound->type = type;
                bound->compressed = false;
            }
            if ((bound) && (automipmap==4) && (nwidth!=nheight))
                bound->mipmap_auto = 0;
                
            if (!(texstream && bound && bound->streamed)) {
                if (bound && ((bound->mipmap_need && (automipmap!=3)) || (bound->mipmap_auto)))
                    gles_glTexParameteri( target, GL_GENERATE_MIPMAP, GL_TRUE );
                else {
                    gles_glTexParameteri( target, GL_GENERATE_MIPMAP, GL_FALSE );
                    if ((bound) && (bound->mipmap_need)) {
                        // remove the need for mipmap...
                        bound->mipmap_need = 0;
                        glshim_glTexParameteri(target, GL_TEXTURE_MIN_FILTER, bound->min_filter);
                        glshim_glTexParameteri(target, GL_TEXTURE_MAG_FILTER, bound->mag_filter);
                    }
                }
                
                if (height != nheight || width != nwidth) {
                    gles_glTexImage2D(target, level, format, nwidth, nheight, border,
                                    format, type, NULL);
                    if (pixels) gles_glTexSubImage2D(target, level, 0, 0, width, height,
                                         format, type, pixels);
                    errorGL();
                } else {
                    gles_glTexImage2D(target, level, format, width, height, border,
                                    format, type, pixels);
                    errorGL();
                }
                /*if (bound && bound->mipmap_need && !bound->mipmap_auto && (automipmap!=3))
                    gles_glTexParameteri( target, GL_GENERATE_MIPMAP, GL_FALSE );*/
            } else {
                if (pixels)
                    glshim_glTexSubImage2D(target, level, 0, 0, width, height, format, type, pixels);	// (should never happens) updload the 1st data...
                }
        }
    }
    if ((target==GL_TEXTURE_2D) && texcopydata && bound && ((texstream && !bound->streamed) || !texstream)) {
	    if (bound->data) 
			bound->data=realloc(bound->data, width*height*4);
	    else 
			bound->data = malloc(width*height*4);
	    if (datab) {
		    if (!pixel_convert(pixels, &bound->data, width, height, format, type, GL_RGBA, GL_UNSIGNED_BYTE, 0))
			    printf("LIBGL: Error on pixel_convert when TEXCOPY in glTexImage2D\n");
	    } else {
		//memset(bound->data, 0, width*height*4);
	    }
	}
    if (pixels != datab) {
        free(pixels);
    }
    glstate.gl_batch = old_glbatch;
}

void glshim_glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset,
                     GLsizei width, GLsizei height, GLenum format, GLenum type,
                     const GLvoid *data) {

	//PUSH_IF_COMPILING(glTexSubImage2D);
    GLuint old_glbatch = glstate.gl_batch;
    if (glstate.gl_batch) {
        flush();
        glstate.gl_batch = 0;
    }

    GLvoid *datab = (GLvoid*)data;
	if (glstate.vao->unpack)
		datab += (uintptr_t)glstate.vao->pack->data;
    GLvoid *pixels = (GLvoid*)datab;

    LOAD_GLES(glTexSubImage2D);
    LOAD_GLES(glTexParameteri);
    noerrorShim();
    //printf("glTexSubImage2D on target=%s with unpack_row_length(%i), size(%i,%i), pos(%i,%i) and skip={%i,%i}, format=%s, type=%s, level=%i, texture=%u\n", PrintEnum(target), glstate.texture.unpack_row_length, width, height, xoffset, yoffset, glstate.texture.unpack_skip_pixels, glstate.texture.unpack_skip_rows, PrintEnum(format), PrintEnum(type), level, glstate.texture.bound[glstate.texture.active]->texture);
    if (width==0 || height==0) {
        glstate.gl_batch = old_glbatch;
        return;
    }
    target = map_tex_target(target);
    
    gltexture_t *bound = glstate.texture.bound[glstate.texture.active];
    if (automipmap) {
        if (bound && (level>0))
            if ((automipmap==1) || (automipmap==3) || bound->mipmap_need) {
                glstate.gl_batch = old_glbatch;
                return;			// has been handled by auto_mipmap
            }
            else
                bound->mipmap_need = 1;
    }

    if ((glstate.texture.unpack_row_length && glstate.texture.unpack_row_length != width) || glstate.texture.unpack_skip_pixels || glstate.texture.unpack_skip_rows) {
	    int imgWidth, pixelSize;
	    pixelSize = pixel_sizeof(format, type);
	    imgWidth = ((glstate.texture.unpack_row_length)? glstate.texture.unpack_row_length:width) * pixelSize;
	    GLubyte *dst = (GLubyte *)malloc(width * height * pixelSize);
	    pixels = (GLvoid *)dst;
	    const GLubyte *src = (GLubyte *)datab;
	    src += glstate.texture.unpack_skip_pixels * pixelSize + glstate.texture.unpack_skip_rows * imgWidth;
	    for (int y = 0; y < height; y ++) {
		    memcpy(dst, src, width * pixelSize);
		    src += imgWidth;
		    dst += width * pixelSize;
	    }
    }
    
    // compressed format are not handled here, so mask them....
    GLenum orig_internal = bound->orig_internal;
    GLenum internalformat = bound->internalformat;
    if (orig_internal==GL_COMPRESSED_RGB) orig_internal=GL_RGB;
    if (orig_internal==GL_COMPRESSED_RGBA) orig_internal=GL_RGBA;
    if (internalformat==GL_COMPRESSED_RGB) internalformat=GL_RGB;
    if (internalformat==GL_COMPRESSED_RGBA) internalformat=GL_RGBA;


    GLvoid *old = pixels;
#ifdef TEXSTREAM
    if (bound && texstream && (bound->streamed)) {
		// Optimisation, let's do convert directly to the right place...
		GLvoid *tmp = GetStreamingBuffer(bound->streamingID);
		tmp += (yoffset*bound->width+xoffset)*2;
		if (! pixel_convert(old, &tmp, width, height,
						format, type, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, bound->width)) {
			printf("libGL swizzle error: (%#4x, %#4x -> GL_RGB, UNSIGNED_SHORT_5_6_5)\n",
						format, type);
		}
		format = GL_RGB;
		type = GL_UNSIGNED_SHORT_5_6_5;
    } else  
#endif
    {
        //pixels = (GLvoid *)swizzle_texture(width, height, &format, &type, old);
        GLenum dest_format, dest_type;
        internal2format_type(orig_internal, &dest_format, &dest_type);
        if (!pixel_convert(old, &pixels, width, height, format, type, dest_format, dest_type, 0)) {
            printf("LIBGL: Error in pixel_convert while glTexSubImage2D\n");
        } else {
            format = dest_format;
            type = dest_type;
            if(orig_internal!=internalformat) {
                GLvoid* pix2 = pixels;
                internal2format_type(internalformat, &dest_format, &dest_type);
                if (!pixel_convert(pixels, &pix2, width, height, format, type, dest_format, dest_type, 0)) {
                    printf("LIBGL: Error in pixel_convert while glTexSubImage2D\n");
                }
                if (pixels != pix2 && pixels != old)
                    free(pixels);
                pixels = pix2;
                format = dest_format;
                type = dest_type;
            }
        }
        
    }
    if (old != pixels && old != datab)
        free(old);

    if (bound->shrink) {
        // special case for width/height == 1
        if (width==1)
            width+=(xoffset%2);
        if (height==1)
            height+=(yoffset%2);
        if ((width==1) || (height==1)) {
            // nothing to do...
            if (pixels != datab)
                free((GLvoid *)pixels);
            glstate.gl_batch = old_glbatch;
            return;
        }
        // ok, now standard cases....
        xoffset /= 2*bound->shrink;
        yoffset /= 2*bound->shrink;
        old = pixels;
        if (bound->shrink==1)
            pixel_halfscale(pixels, &old, width, height, format, type);
        else
            pixel_quarterscale(pixels, &old, width, height, format, type);
        if (old != pixels && pixels!=data)
            free(pixels);
        pixels = old;
        width /= 2*bound->shrink;
        height /= 2*bound->shrink;
    }

    if (texdump) {
        if (bound) {
            pixel_to_ppm(pixels, width, height, format, type, bound->texture);
        }
    }

    if (bound && bound->mipmap_need && !bound->mipmap_auto && (automipmap!=3) && (!texstream || (texstream && !bound->streamed)))
        gles_glTexParameteri( target, GL_GENERATE_MIPMAP, GL_TRUE );

    if (bound && texstream && bound->streamed) {
/*	// copy the texture to the buffer
	void* tmp = GetStreamingBuffer(bound->streamingID);
	for (int yy=0; yy<height; yy++) {
		memcpy(tmp+((yy+yoffset)*bound->width+xoffset)*2, pixels+(yy*width)*2, width*2);
	}*/
    } else {
        gles_glTexSubImage2D(target, level, xoffset, yoffset,
					 width, height, format, type, pixels);
		errorGL();
    }

    if (bound && bound->mipmap_need && !bound->mipmap_auto && (automipmap!=3) && (!texstream || (texstream && !bound->streamed)))
        gles_glTexParameteri( target, GL_GENERATE_MIPMAP, GL_FALSE );

    if ((target==GL_TEXTURE_2D) && texcopydata && bound && ((texstream && !bound->streamed) || !texstream)) {
    //printf("*texcopy* glTexSubImage2D, xy=%i,%i, size=%i,%i=>%i,%i, format=%s, type=%s, tex=%u\n", xoffset, yoffset, width, height, bound->width, bound->height, PrintEnum(format), PrintEnum(type), bound->glname);
        GLvoid * tmp = bound->data;
        tmp += (yoffset*bound->width + xoffset)*4;
        if (!pixel_convert(pixels, &tmp, width, height, format, type, GL_RGBA, GL_UNSIGNED_BYTE, bound->width))
            printf("LIBGL: Error on pixel_convert while TEXCOPY in glTexSubImage2D\n");
    }

    if (pixels != datab)
        free((GLvoid *)pixels);
    glstate.gl_batch = old_glbatch;
}

// 1d stubs
void glshim_glTexImage1D(GLenum target, GLint level, GLint internalFormat,
                  GLsizei width, GLint border,
                  GLenum format, GLenum type, const GLvoid *data) {

    // TODO: maybe too naive to force GL_TEXTURE_2D here?
    glshim_glTexImage2D(GL_TEXTURE_2D, level, internalFormat, width, 1,
                 border, format, type, data);
}
void glshim_glTexSubImage1D(GLenum target, GLint level, GLint xoffset,
                     GLsizei width, GLenum format, GLenum type,
                     const GLvoid *data) {

    glshim_glTexSubImage2D(GL_TEXTURE_2D, level, xoffset, 0,
                    width, 1, format, type, data);
}
void glshim_glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y,
		    GLsizei width, GLint border) {
    glshim_glCopyTexImage2D(GL_TEXTURE_2D, level, internalformat, x, y, width, 1, border);
		    
}

void glshim_glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y,
                                GLsizei width) {
    glshim_glCopyTexSubImage2D(GL_TEXTURE_2D, level, xoffset, 0, x, y, width, 1);
}
                                
void glshim_glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
                                GLint x, GLint y, GLsizei width, GLsizei height) {
    glshim_glCopyTexSubImage2D(GL_TEXTURE_2D, level, xoffset, yoffset, x, y, width, height);
}

                                


// 3d stubs
void glshim_glTexImage3D(GLenum target, GLint level, GLint internalFormat,
                  GLsizei width, GLsizei height, GLsizei depth, GLint border,
                  GLenum format, GLenum type, const GLvoid *data) {

    // TODO: maybe too naive to force GL_TEXTURE_2D here?
    glshim_glTexImage2D(GL_TEXTURE_2D, level, internalFormat, width, height,
                 border, format, type, data);
}
void glshim_glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, 
                     GLsizei width, GLsizei height, GLsizei depth, GLenum format,
                     GLenum type, const GLvoid *data) {

    glshim_glTexSubImage2D(target, level, xoffset, yoffset,
                    width, height, format, type, data);
}

void glshim_glPixelStorei(GLenum pname, GLint param) {
    // TODO: add to glGetIntegerv?
//   if (glstate.gl_batch) flush();

    LOAD_GLES(glPixelStorei);
    noerrorShim();
    switch (pname) {
        case GL_UNPACK_ROW_LENGTH:
            glstate.texture.unpack_row_length = param;
            break;
        case GL_UNPACK_SKIP_PIXELS:
            glstate.texture.unpack_skip_pixels = param;
            break;
        case GL_UNPACK_SKIP_ROWS:
            glstate.texture.unpack_skip_rows = param;
            break;
        case GL_UNPACK_LSB_FIRST:
            glstate.texture.unpack_lsb_first = param;
            break;
        case GL_UNPACK_IMAGE_HEIGHT:
            glstate.texture.unpack_image_height = param;
            break;
        case GL_UNPACK_SWAP_BYTES:
        case GL_PACK_SWAP_BYTES:
            // Fake... TODO?
            //glstate.texture.unpack_lsb_first = param;
            break;
        case GL_PACK_ROW_LENGTH:
            glstate.texture.pack_row_length = param;
            break;
        case GL_PACK_SKIP_PIXELS:
            glstate.texture.pack_skip_pixels = param;
            break;
        case GL_PACK_SKIP_ROWS:
            glstate.texture.pack_skip_rows = param;
            break;
        case GL_PACK_LSB_FIRST:
            glstate.texture.pack_lsb_first = param;
            break;
        case GL_PACK_IMAGE_HEIGHT:
            glstate.texture.pack_image_height = param;
            break;
        default:
			errorGL();
            gles_glPixelStorei(pname, param);
            break;
    }
}
GLboolean glshim_glIsTexture(	GLuint texture) {
	noerrorShim();
	if (!texture) {
		return GL_FALSE;
	}
    int ret;
	khint_t k;
	khash_t(tex) *list = glstate.texture.list;
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

gltexture_t* glshim_getTexture(GLenum target, GLuint texture) {
    // Get a texture based on glID
    gltexture_t* tex = NULL;
    if (texture == 0) return tex;
    int ret;
    khint_t k;
    khash_t(tex) *list = glstate.texture.list;
    if (! list) {
        list = glstate.texture.list = kh_init(tex);
        // segfaults if we don't do a single put
        kh_put(tex, list, 1, &ret);
        kh_del(tex, list, 1);
    }
    k = kh_get(tex, list, texture);
    
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
        tex->mipmap_auto = default_tex_mipmap || (automipmap==1);
        tex->mipmap_need = (automipmap==1)?1:0;
        tex->alpha = true;
        tex->streamed = false;
        tex->streamingID = -1;
        tex->min_filter = tex->mag_filter = (automipmap==1)?GL_LINEAR_MIPMAP_LINEAR:GL_LINEAR;
        tex->format = GL_RGBA;
        tex->type = GL_UNSIGNED_BYTE;
        tex->orig_internal = GL_RGBA;
        tex->internalformat = GL_RGBA;
        tex->data = NULL;
    } else {
        tex = kh_value(list, k);
    }
    return tex;
}

void glshim_glBindTexture(GLenum target, GLuint texture) {
	noerrorShim();
    if ((target!=GL_PROXY_TEXTURE_2D) && (glstate.list.active && (glstate.gl_batch && !glstate.list.compiling)))  {
        if ((glstate.statebatch.bound_targ == target) && (glstate.statebatch.bound_tex == texture))
            return; // nothing to do...
        if (!glstate.statebatch.bound_targ) {
            glstate.statebatch.bound_targ = target;
            glstate.statebatch.bound_tex = texture;
        } else {
            flush();
        }
    }
    if ((target!=GL_PROXY_TEXTURE_2D) && ((glstate.list.compiling || glstate.gl_batch) && glstate.list.active)) {
        // check if already a texture binded, if yes, create a new list
        NewStage(glstate.list.active, STAGE_BINDTEX);
        rlBindTexture(glstate.list.active, target, texture);
    } else {
    	int tex_changed = 1;
		int streamingID = -1;
        gltexture_t *tex = NULL;
        //printf("glBindTexture(0x%04X, %u), active=%i, client=%i\n", target, texture, glstate.texture.active, glstate.texture.client);
        if (texture) {
            tex = glshim_getTexture(target, texture);
            if (glstate.texture.bound[glstate.texture.active] == tex)
            	tex_changed = 0;
            texture = tex->glname;
			if (texstream && tex->streamed)
				streamingID = tex->streamingID;
        } else {
            if (glstate.texture.bound[glstate.texture.active] == NULL)
            	tex_changed = 0;
        }
	
        LOAD_GLES(glDisable);
        LOAD_GLES(glEnable);
tex_changed=1;  // seems buggy, temporary disabling that...

        if (tex_changed) {

			GLboolean tmp = glstate.enable.texture_2d[glstate.texture.active];
#ifdef TEXSTREAM
	        if (texstream) {  // unbind streaming texture if any...
	            gltexture_t *bound = glstate.texture.bound[glstate.texture.active];
	            if (bound && bound->streamed) {
	                if (tmp)
                        gles_glDisable(GL_TEXTURE_STREAM_IMG);
	                DeactivateStreaming();
	                if (tmp)
                        gles_glEnable(GL_TEXTURE_2D);
	            }
	        }
#endif

	        glstate.texture.rect_arb[glstate.texture.active] = (target == GL_TEXTURE_RECTANGLE_ARB);
	        target = map_tex_target(target);

            glstate.texture.bound[glstate.texture.active] = tex;

            LOAD_GLES(glBindTexture);
#ifdef TEXSTREAM
            if (texstream && (streamingID>-1)) {
                if (tmp)
                    gles_glDisable(GL_TEXTURE_2D);
                ActivateStreaming(streamingID);
                if (tmp)
                    gles_glEnable(GL_TEXTURE_STREAM_IMG);
            } else 
#endif
            {
                gles_glBindTexture(target, texture);
                errorGL();
            }
        }
    }
}

// TODO: also glTexParameterf(v)?
void glshim_glTexParameteri(GLenum target, GLenum pname, GLint param) {
    PUSH_IF_COMPILING(glTexParameteri);
    LOAD_GLES(glTexParameteri);
    target = map_tex_target(target);
    gltexture_t *texture = glstate.texture.bound[glstate.texture.active];
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
		    if ((automipmap==3) || ((texture) && (automipmap==1) && (texture->mipmap_auto==0)))
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
			if (pname==GL_TEXTURE_MIN_FILTER) if (texture) texture->min_filter = param;
			if (pname==GL_TEXTURE_MAG_FILTER) if (texture) texture->mag_filter = param;
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
    case GL_TEXTURE_BASE_LEVEL:
	case GL_TEXTURE_MIN_LOD:
	case GL_TEXTURE_MAX_LOD:
	case GL_TEXTURE_LOD_BIAS:
	    return;			// not on GLES
	case GL_GENERATE_MIPMAP:
	    if (texture) {
            texture->mipmap_auto = (param)?1:0;
            if (texture->glname == 0)
                default_tex_mipmap = texture->mipmap_auto;
        } else
            default_tex_mipmap = (param)?1:0;       // default?
	    return;         // We control the behavour later
    }
    gles_glTexParameteri(target, pname, param);
    errorGL();
}

void glshim_glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
    glshim_glTexParameteri(target, pname, param);
}

void glshim_glDeleteTextures(GLsizei n, const GLuint *textures) {
    if (glstate.gl_batch) flush();
	noerrorShim();
    LOAD_GLES(glDeleteTextures);
    khash_t(tex) *list = glstate.texture.list;
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
                    if (tex == glstate.texture.bound[a])
                        glstate.texture.bound[a] = NULL;
                }
				gles_glDeleteTextures(1, &tex->glname);
				errorGL();
#ifdef TEXSTREAM
				if (texstream && tex->streamed)
					FreeStreamed(tex->streamingID);
#endif
				#if 1
                kh_del(tex, list, k);
                if (tex->data) free(tex->data);
                free(tex);
                #else
                tex->glname = tex->texture;
                tex->streamed = false;
                tex->streamingID = -1;
                if (tex->data) free(tex->data);
                tex->data = NULL;
                #endif
            }
        }
    }
}

void glshim_glGenTextures(GLsizei n, GLuint * textures) {
    if (n<=0) 
		return;
    if (glstate.gl_batch) flush();
    LOAD_GLES(glGenTextures);
    gles_glGenTextures(n, textures);
    errorGL();
    // now, add all the textures to the list
    int ret;
	khint_t k;
	khash_t(tex) *list = glstate.texture.list;
	if (! list) {
		list = glstate.texture.list = kh_init(tex);
		// segfaults if we don't do a single put
		kh_put(tex, list, 1, &ret);
		kh_del(tex, list, 1);
	}
	
	for (int i=0; i<n; i++) {
		k = kh_get(tex, list, textures[i]);
		gltexture_t *tex = NULL;
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
            tex->alpha = true;
            tex->compressed = false;
			tex->min_filter = tex->mag_filter = GL_NEAREST;
            tex->format = GL_RGBA;
            tex->type = GL_UNSIGNED_BYTE;
			tex->data = NULL;
		} else {
			tex = kh_value(list, k);
			// in case of no delete here...
			if (tex->glname==0)
				tex->glname = tex->texture;
		}
	}
}

GLboolean glshim_glAreTexturesResident(GLsizei n, const GLuint *textures, GLboolean *residences) {
	noerrorShim();
    return true;
}

void glshim_glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params) {
    //printf("glGetTexLevelParameteriv(%s, %d, %s, %p)\n", PrintEnum(target), level, PrintEnum(pname), params);
	// simplification: (mostly) not taking "target" into account here
    if (glstate.gl_batch) flush();
	*params = 0;
	noerrorShim();
	gltexture_t* bound = glstate.texture.bound[glstate.texture.active];
	switch (pname) {
		case GL_TEXTURE_WIDTH:
			if (target==GL_PROXY_TEXTURE_2D)
				(*params) = proxy_width>>level;
			else
				(*params) = ((bound)?bound->width:2048)>>level;
            if(bound && ((bound->orig_internal==GL_COMPRESSED_RGB) || (bound->orig_internal==GL_COMPRESSED_RGBA))) {
                if (*params<4)      // minimum size of a compressed block is 4
                    *params = 0;
            } else {
                if (*params<=0)     // 1 is the minimum, not 0
                    *params = 1;
            }
			break;
		case GL_TEXTURE_HEIGHT: 
			if (target==GL_PROXY_TEXTURE_2D)
				(*params) = proxy_height>>level;
			else
				(*params) = ((bound)?bound->height:2048)>>level; 
            if(bound && ((bound->orig_internal==GL_COMPRESSED_RGB) || (bound->orig_internal==GL_COMPRESSED_RGBA))) {
                if (*params<4)      // minimum size of a compressed block is 4
                    *params = 0;
            } else {
                if (*params<=0)      // 1 is the minimum, not 0, but only on uncompressed textures
                    *params = 1;
            }
			break;
		case GL_TEXTURE_INTERNAL_FORMAT:
            if (target==GL_PROXY_TEXTURE_2D)
				(*params) = proxy_intformat;
			else {
                if (bound && bound->compressed)
                    (*params) = bound->format;
                else {
                    if(bound && ((bound->orig_internal==GL_COMPRESSED_RGB) || (bound->orig_internal==GL_COMPRESSED_RGBA))) {
                        if(bound->orig_internal==GL_COMPRESSED_RGB)
                            *(params) = GL_COMPRESSED_RGB_S3TC_DXT1_EXT;
                        else
                            *(params) = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
                    } else
                        (*params) = GL_RGBA;
                }
            }
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
            if (bound && bound->compressed)
                (*params) = GL_TRUE;
            else {
                if(bound && ((bound->orig_internal==GL_COMPRESSED_RGB) || (bound->orig_internal==GL_COMPRESSED_RGBA)))
                    (*params) = GL_TRUE;
                else
                    (*params) = GL_FALSE;
            }
			break;
		case GL_TEXTURE_COMPRESSED_IMAGE_SIZE:
            if(bound && ((bound->orig_internal==GL_COMPRESSED_RGB) || (bound->orig_internal==GL_COMPRESSED_RGBA))) {
                int w = bound->width>>level;
                int h = bound->height>>level;
                w = ((w>>2)+1) << 2; h = ((h>>2)+1) << 2;   //DXT works on 4x4 blocks...
                if (bound->orig_internal==GL_COMPRESSED_RGB) //DXT1, 64bits (i.e. size=8) for a 4x4 block
                    (*params) = (w*h)/2;
                else    //DXT5, 64+64 (i.e. size = 16) for a 4x4 block
                    (*params) = w*h;
            } else
			 (*params) = (bound)?(bound->width*bound->height*4):0;
			break;
		default:
			errorShim(GL_INVALID_ENUM);	//Wrong here...
			printf("Stubbed glGetTexLevelParameteriv(%04x, %i, %04x, %p)\n", target, level, pname, params);
	}
}

extern GLuint current_fb;   // from framebuffers.c

void glshim_glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid * img) {
    if (glstate.gl_batch) flush();
	if (glstate.texture.bound[glstate.texture.active]==NULL)
		return;		// no texture bounded...
	gltexture_t* bound = glstate.texture.bound[glstate.texture.active];
	int width = bound->width;
	int height = bound->height;
	if (level != 0) {
		//printf("STUBBED glGetTexImage with level=%i\n", level);
        void* tmp = malloc(width*height*pixel_sizeof(format, type)); // tmp space...
        void* tmp2;
        glshim_glGetTexImage(target, 0, format, type, tmp);
        for (int i=0; i<level; i++) {
            pixel_halfscale(tmp, &tmp2, width, height, format, type);
            free(tmp);
            tmp = tmp2;
            if(width>1) width>>=1;
            if(height>1) height>>=1;
        }
        memcpy(img, tmp, width*height*pixel_sizeof(format, type));
        free(tmp);
        return;
	}
	
	if (target!=GL_TEXTURE_2D)
		return;

    //printf("glGetTexImage(0x%04X, %i, 0x%04X, 0x%04X, 0x%p), texture=%u, size=%i,%i\n", target, level, format, type, img, bound->glname, width, height);
	
	GLvoid *dst = img;
    if (glstate.vao->pack)
        dst += (uintptr_t)glstate.vao->pack->data;
#ifdef TEXSTREAM
    if (texstream && bound->streamed) {
        noerrorShim();
        pixel_convert(GetStreamingBuffer(bound->streamingID), &dst, width, height, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, format, type, 0);
        readfboEnd();
        return;
    }
#endif
    if (texcopydata && bound->data) {
        printf("texcopydata* glGetTexImage(0x%04X, %d, 0x%04x, 0x%04X, %p)\n", target, level, format, type, img);
        noerrorShim();
        if (!pixel_convert(bound->data, &dst, width, height, GL_RGBA, GL_UNSIGNED_BYTE, format, type, 0))
            printf("LIBGL: Error on pixel_convert while glGetTexImage\n");
	} else {
		// Setup an FBO the same size of the texture
        GLuint oldBind = bound->glname;
        GLuint old_fbo = current_fb;
        GLuint fbo;
	
		glshim_glGenFramebuffers(1, &fbo);
		glshim_glBindFramebuffer(GL_FRAMEBUFFER_OES, fbo);
		glshim_glFramebufferTexture2D(GL_FRAMEBUFFER_OES, GL_COLOR_ATTACHMENT0_OES, GL_TEXTURE_2D, oldBind, 0);
		// Read the pixels!
		glshim_glReadPixels(0, 0, width, height, format, type, img);	// using "full" version with conversion of format/type
		glshim_glBindFramebuffer(GL_FRAMEBUFFER_OES, old_fbo);
        glshim_glDeleteFramebuffers(1, &fbo);
        noerrorShim();
	}
}

void glshim_glActiveTexture( GLenum texture ) {
 if (glstate.list.active && (glstate.gl_batch && !glstate.list.compiling))  {
    if (glstate.statebatch.active_tex_changed) {
        if(glstate.statebatch.active_tex == texture)
            return; // nothing to do...
        flush();
    }
    glstate.statebatch.active_tex = texture;
    glstate.statebatch.active_tex_changed = 1;
 }
 if (glstate.list.active) {
     NewStage(glstate.list.active, STAGE_ACTIVETEX);
     rlActiveTexture(glstate.list.active, texture);
     return;
 }
 
 if ((texture < GL_TEXTURE0) || (texture >= GL_TEXTURE0+MAX_TEX)) {
    errorShim(GL_INVALID_ENUM);
   return;
 }
 glstate.texture.active = texture - GL_TEXTURE0;
 LOAD_GLES(glActiveTexture);
 gles_glActiveTexture(texture);
 errorGL();
}

void glshim_glClientActiveTexture( GLenum texture ) {
 if ((texture < GL_TEXTURE0) || (texture >= GL_TEXTURE0+MAX_TEX)) {
	 errorShim(GL_INVALID_ENUM);
   return;
 }
 // try to speed-up things...
 if (glstate.texture.client == (texture - GL_TEXTURE0))
    return;
 if (glstate.gl_batch) flush();
 glstate.texture.client = texture - GL_TEXTURE0;
 LOAD_GLES(glClientActiveTexture);
 gles_glClientActiveTexture(texture);
 errorGL();
}

void glshim_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * data) {
    //printf("glReadPixels(%i, %i, %i, %i, 0x%04X, 0x%04X, 0x%p)\n", x, y, width, height, format, type, data);
    GLuint old_glbatch = glstate.gl_batch;
    if (glstate.gl_batch) {
        flush();
        glstate.gl_batch = 0;
    }
    if (glstate.list.compiling && glstate.list.active) {
		errorShim(GL_INVALID_OPERATION);
        glstate.gl_batch = old_glbatch;
        return;	// never in list
	}
    LOAD_GLES(glReadPixels);
    errorGL();
    GLvoid* dst = data;
    if (glstate.vao->pack)
		dst += (uintptr_t)glstate.vao->pack->data;
		
	readfboBegin();
    if (format == GL_RGBA && format == GL_UNSIGNED_BYTE) {
        // easy passthru
        gles_glReadPixels(x, y, width, height, GL_RGBA, GL_UNSIGNED_BYTE, dst);
        readfboEnd();
        glstate.gl_batch = old_glbatch;
        return;
    }
    // grab data in GL_RGBA format
    GLvoid *pixels = malloc(width*height*4);
    gles_glReadPixels(x, y, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
    if (! pixel_convert(pixels, &dst, width, height,
					    GL_RGBA, GL_UNSIGNED_BYTE, format, type, 0)) {
        printf("libGL ReadPixels error: (GL_RGBA, UNSIGNED_BYTE -> %#4x, %#4x )\n",
            format, type);
    }
    free(pixels);
    readfboEnd();
    glstate.gl_batch = old_glbatch;
    return;
}

void glshim_glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset,
                                GLint x, GLint y, GLsizei width, GLsizei height) {
    //printf("glCopyTexSubImage2D(%s, %i, %i, %i, %i, %i, %i, %i), bounded texture=%u format/type=%s, %s\n", PrintEnum(target), level, xoffset, yoffset, x, y, width, height, (glstate.texture.bound[glstate.texture.active])?glstate.texture.bound[glstate.texture.active]->texture:0, PrintEnum((glstate.texture.bound[glstate.texture.active])?glstate.texture.bound[glstate.texture.active]->format:0), PrintEnum((glstate.texture.bound[glstate.texture.active])?glstate.texture.bound[glstate.texture.active]->type:0));
    // PUSH_IF_COMPILING(glCopyTexSubImage2D);
    GLuint old_glbatch = glstate.gl_batch;
    if (glstate.gl_batch) {
        flush();
        glstate.gl_batch = 0;
    }
 
    LOAD_GLES(glCopyTexSubImage2D);
    errorGL();

    // "Unmap" if buffer mapped...
    glbuffer_t *pack = glstate.vao->pack;
    glbuffer_t *unpack = glstate.vao->unpack;
    glstate.vao->pack = NULL;
    glstate.vao->unpack = NULL;
 
    gltexture_t* bound = glstate.texture.bound[glstate.texture.active];
    if (!bound) {
        errorShim(GL_INVALID_OPERATION);
        glstate.gl_batch = old_glbatch;
        return;
    }
#ifdef TEXSTREAM
    if (bound && bound->streamed) {
        void* buff = GetStreamingBuffer(bound->streamingID);
        if ((bound->width == width) && (bound->height == height) && (xoffset == yoffset == 0)) {
            glshim_glReadPixels(x, y, width, height, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, buff);
        } else {
            void* tmp = malloc(width*height*2);
            glshim_glReadPixels(x, y, width, height, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, tmp);
            for (int y=0; y<height; y++) {
                memcpy(buff+((yoffset+y)*bound->width+xoffset)*2, tmp+y*width*2, width*2);
            }
            free(tmp);
        }
    } else 
#endif
    {
        if (copytex) {
            gles_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
        } else {
            void* tmp = malloc(width*height*4);
            GLenum format = (bound)?bound->format:GL_RGBA;
            GLenum type = (bound)?bound->type:GL_UNSIGNED_BYTE;
            glshim_glReadPixels(x, y, width, height, format, type, tmp);
            glshim_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, tmp);
            free(tmp);
        }
    }
    // "Remap" if buffer mapped...
    glstate.vao->pack = pack;
    glstate.vao->unpack = unpack;
    glstate.gl_batch = old_glbatch;
}


void glshim_glCopyTexImage2D(GLenum target,  GLint level,  GLenum internalformat,  GLint x,  GLint y,  
								GLsizei width,  GLsizei height,  GLint border) {
     //printf("glCopyTexImage2D(0x%04X, %i, 0x%04X, %i, %i, %i, %i, %i), current_fb=%u\n", target, level, internalformat, x, y, width, height, border, current_fb);
     //PUSH_IF_COMPILING(glCopyTexImage2D);
     GLuint old_glbatch = glstate.gl_batch;
     if (glstate.gl_batch) {
         flush();
         glstate.gl_batch = 0;
     }

     errorGL();

     // "Unmap" if buffer mapped...
     glbuffer_t *pack = glstate.vao->pack;
     glbuffer_t *unpack = glstate.vao->unpack;
     glstate.vao->pack = NULL;
     glstate.vao->unpack = NULL;
    
    if (copytex) {
        LOAD_GLES(glCopyTexImage2D);
        gles_glCopyTexImage2D(target, level, GL_RGB, x, y, width, height, border);
    } else {
        void* tmp = malloc(width*height*4);
        glshim_glReadPixels(x, y, width, height, GL_RGBA, GL_UNSIGNED_BYTE, tmp);
        glshim_glTexImage2D(target, level, internalformat, width, height, border, GL_RGBA, GL_UNSIGNED_BYTE, tmp);
        free(tmp);
    }
    
     // "Remap" if buffer mapped...
     glstate.vao->pack = pack;
     glstate.vao->unpack = unpack;
     
     glstate.gl_batch = old_glbatch;
}



GLboolean isDXTc(GLenum format) {
	switch (format) {
		case GL_COMPRESSED_RGB_S3TC_DXT1_EXT:
		case GL_COMPRESSED_RGBA_S3TC_DXT1_EXT:
		case GL_COMPRESSED_RGBA_S3TC_DXT3_EXT:
		case GL_COMPRESSED_RGBA_S3TC_DXT5_EXT:
			return true;
	}
	return false;
}

GLboolean isNotCompressed(GLenum format) {
    switch(format) {
        case GL_RGBA:
        case GL_RGB:
        case GL_RGBA8:
        case GL_RGB8:
        case GL_RGB5:
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
		return (GLvoid*)data;
	}
	// alloc memory
	GLvoid *pixels = malloc(((width+3)&~3)*((height+3)&~3)*pixelsize);
	// uncompress loop
	int blocksize;
	switch (format) {
		case GL_COMPRESSED_RGB_S3TC_DXT1_EXT:
		case GL_COMPRESSED_RGBA_S3TC_DXT1_EXT:
			blocksize = 8;
			break;
		case GL_COMPRESSED_RGBA_S3TC_DXT3_EXT:
		case GL_COMPRESSED_RGBA_S3TC_DXT5_EXT:
			blocksize = 16;
			break;
	}
	uintptr_t src = (uintptr_t) data;
	for (int y=0; y<height; y+=4) {
		for (int x=0; x<width; x+=4) {
			switch(format) {
				case GL_COMPRESSED_RGB_S3TC_DXT1_EXT:
				case GL_COMPRESSED_RGBA_S3TC_DXT1_EXT:
					DecompressBlockDXT1(x, y, width, (uint8_t*)src, pixels);
					break;
				case GL_COMPRESSED_RGBA_S3TC_DXT3_EXT:
					DecompressBlockDXT3(x, y, width, (uint8_t*)src, pixels);
					break;
				case GL_COMPRESSED_RGBA_S3TC_DXT5_EXT:
					DecompressBlockDXT5(x, y, width, (uint8_t*)src, pixels);
					break;
			}
			src+=blocksize;
		}
	}
	return pixels;
}

void glshim_glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat,
							GLsizei width, GLsizei height, GLint border,
							GLsizei imageSize, const GLvoid *data) 
{
    if (target == GL_PROXY_TEXTURE_2D) {
        proxy_width = (width>2048)?0:width;
        proxy_height = (height>2048)?0:height;
        return;
    }
     GLuint old_glbatch = glstate.gl_batch;
     if (glstate.gl_batch) {
         flush();
         glstate.gl_batch = 0;
     }

    if (glstate.texture.bound[glstate.texture.active]==NULL) {
		errorShim(GL_INVALID_OPERATION);
	    return;		// no texture bounded...
	}
    //printf("glCompressedTexImage2D on target=%s with size(%i,%i), internalformat=%s, imagesize=%i, upackbuffer=%p\n", PrintEnum(target), width, height, PrintEnum(internalformat), imageSize, glstate.vao->unpack?glstate.vao->unpack->data:0);
    // hack...
    if (internalformat==GL_RGBA8)
        internalformat = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
    // test if internalformat is not a compressed one
    if (level != 0) {
		noerrorShim();
	    //TODO
	    //printf("STUBBED glCompressedTexImage2D with level=%i\n", level);
	    //return;
    }
    if ((width<=0) || (height<=0)) {
        noerrorShim();
        return; // nothing to do...
    }
    LOAD_GLES(glCompressedTexImage2D);
    errorGL();
    
    glbuffer_t *unpack = glstate.vao->unpack;
    glstate.vao->unpack = NULL;
    GLvoid *datab = (GLvoid*)data;
    if (unpack)
		datab += (uintptr_t)unpack->data;
    
    GLenum format = GL_RGBA;
    GLenum type = GL_UNSIGNED_BYTE;
        
    if (isDXTc(internalformat)) {
		GLvoid *pixels, *half;
        int fact = 0;
        if (datab) {
            if (width<4 || height<4) {	// can happens :(
                GLvoid *tmp;
                GLsizei nw=width;
                GLsizei nh=height;
                if (nw<4) nw = 4;
                if (nh<4) nh = 4;
                tmp = uncompressDXTc(nw, nh, internalformat, imageSize, datab);
                pixels = malloc(4*width*height);
                // crop
                for (int y=0; y<height; y++)
                    memcpy(pixels+y*width*4, tmp+y*nw*4, width*4);
                free(tmp);
            } else {
                pixels = uncompressDXTc(width, height, internalformat, imageSize, datab);
            }
            // automaticaly reduce the pixel size
            half=pixels;
            glstate.texture.bound[glstate.texture.active]->alpha = (internalformat==GL_COMPRESSED_RGB_S3TC_DXT1_EXT)?false:true;
            format = (internalformat==GL_COMPRESSED_RGB_S3TC_DXT1_EXT)?GL_RGB:GL_RGBA;
            glstate.texture.bound[glstate.texture.active]->format = format; //internalformat;
            type = (internalformat==GL_COMPRESSED_RGB_S3TC_DXT1_EXT)?GL_UNSIGNED_SHORT_5_6_5:GL_UNSIGNED_SHORT_4_4_4_4;
            glstate.texture.bound[glstate.texture.active]->type = type;
            glstate.texture.bound[glstate.texture.active]->compressed = true;
            if (pixel_convert(pixels, &half, width, height, GL_RGBA, GL_UNSIGNED_BYTE, format, type, 0))
                fact = 0;
//            if (pixel_thirdscale(pixels, &half, width, height, GL_RGBA, GL_UNSIGNED_BYTE)) 
//                fact = 1;
            else
                glstate.texture.bound[glstate.texture.active]->type = GL_UNSIGNED_BYTE;
        } else {
            half = NULL;
            fact = 1;
        }
		int oldalign;
		glshim_glGetIntegerv(GL_UNPACK_ALIGNMENT, &oldalign);
		if (oldalign!=1) 
            glshim_glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glshim_glTexImage2D(target, level, GL_RGBA, width>>fact, height>>fact, border, format, type, half);
		if (oldalign!=1) 
            glshim_glPixelStorei(GL_UNPACK_ALIGNMENT, oldalign);
		if (half!=pixels)
			free(half);
		if (pixels!=datab)
			free(pixels);
	} else {
	    glstate.texture.bound[glstate.texture.active]->alpha = true;
        glstate.texture.bound[glstate.texture.active]->format = internalformat;
        glstate.texture.bound[glstate.texture.active]->type = GL_UNSIGNED_BYTE;
        glstate.texture.bound[glstate.texture.active]->compressed = true;
	    gles_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, datab);
	}
	glstate.vao->unpack = unpack;
    glstate.gl_batch = old_glbatch;
}

void glshim_glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset,
							   GLsizei width, GLsizei height, GLenum format, 
							   GLsizei imageSize, const GLvoid *data) 
{
     GLuint old_glbatch = glstate.gl_batch;
     if (glstate.gl_batch) {
         flush();
         glstate.gl_batch = 0;
     }

	if (glstate.texture.bound[glstate.texture.active]==NULL) {
		errorShim(GL_INVALID_OPERATION);
        glstate.gl_batch = old_glbatch;
		return;		// no texture bounded...
	}
	if (level != 0) {
		noerrorShim();
		//TODO
		//printf("STUBBED glCompressedTexSubImage2D with level=%i\n", level);
        glstate.gl_batch = old_glbatch;
		return;
	}
    //printf("glCompressedTexSubImage2D with unpack_row_length(%i), size(%i,%i), pos(%i,%i) and skip={%i,%i}, internalformat=%s, imagesize=%i\n", glstate.texture.unpack_row_length, width, height, xoffset, yoffset, glstate.texture.unpack_skip_pixels, glstate.texture.unpack_skip_rows, PrintEnum(format), imageSize);
    glbuffer_t *unpack = glstate.vao->unpack;
    glstate.vao->unpack = NULL;
    GLvoid *datab = (GLvoid*)data;
    if (unpack)
		datab += (uintptr_t)unpack->data;
    LOAD_GLES(glCompressedTexSubImage2D);
    errorGL();
    if (isDXTc(format)) {
		GLvoid *pixels;
		if (width<4 || height<4) {	// can happens :(
			GLvoid *tmp;
			GLsizei nw=width;
			GLsizei nh=height;
			if (nw<4) nw = 4;
			if (nh<4) nh = 4;
			tmp = uncompressDXTc(nw, nh, format, imageSize, datab);
			pixels = malloc(4*width*height);
			// crop
			for (int y=0; y<height; y++)
				memcpy(pixels+y*width*4, tmp+y*nw*4, width*4);
			free(tmp);
		} else {
			pixels = uncompressDXTc(width, height, format, imageSize, datab);
		}
		GLvoid *half=pixels;
		#if 1
		pixel_thirdscale(pixels, &half, width, height, GL_RGBA, GL_UNSIGNED_BYTE);
		int oldalign;
		glshim_glGetIntegerv(GL_UNPACK_ALIGNMENT, &oldalign);
		if (oldalign!=1) glshim_glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glshim_glTexSubImage2D(target, level, xoffset/2, yoffset/2, width/2, height/2, GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4, half);
		if (oldalign!=1) glshim_glPixelStorei(GL_UNPACK_ALIGNMENT, oldalign);
		#else
		pixel_halfscale(pixels, &half, width, height, GL_RGBA, GL_UNSIGNED_BYTE);
		glTexSubImage2D(target, level, xoffset/2, yoffset/2, width/2, height/2, GL_RGBA, GL_UNSIGNED_BYTE, half);
		#endif
		if (half!=pixels)
			free(half);
		if (pixels!=datab)
			free(pixels);
	} else {
		gles_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, datab);
	}
    glstate.gl_batch = old_glbatch;
}

void glshim_glGetCompressedTexImage(GLenum target, GLint lod, GLvoid *img) {
    if (glstate.gl_batch) flush();

    gltexture_t* bound = glstate.texture.bound[glstate.texture.active];
    //printf("glGetCompressedTexImage(%s, %i, %p), bound=%p, bound->orig_internal=%s\n", PrintEnum(target), lod, img, bound, (bound)?PrintEnum(bound->orig_internal):"nil");
    errorShim(GL_INVALID_OPERATION);
    if(!bound)
        return;
    if(bound->orig_internal!=GL_COMPRESSED_RGB && bound->orig_internal!=GL_COMPRESSED_RGBA)
        return;
    int width = bound->width>>lod;
    int height = bound->height>>lod;
    int w = ((width>>2)+1)<<2;
    int h = ((height>>2)+1)<<2;

    int alpha = (bound->orig_internal==GL_COMPRESSED_RGBA)?1:0;

    glbuffer_t *unpack = glstate.vao->unpack;
    glbuffer_t *pack = glstate.vao->pack;
    glstate.vao->unpack = NULL;
    glstate.vao->pack = NULL;
    GLvoid *datab = (GLvoid*)img;
    if (pack)
        datab += (uintptr_t)pack->data;

    // alloc the memory for source image and grab the file
    GLuint *src = (GLuint*)malloc(width*height*4);
    glshim_glGetTexImage(target, lod, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*)src);
    GLuint tmp[4*4]; //this is the 4x4 block
    for (int y = 0; y < h; y+=4)
        for (int x = 0; x < w; x+=4) {
            GLuint col = 0;
            for (int i=0; i<16; i++) {
                if(x+(i%4)<width && y+(i/4)<height)
                    col = src[x+(i%4)+(y+(i/4))*width];
                tmp[i] = col;
            }
            stb_compress_dxt_block((unsigned char*)datab, (const unsigned char*)tmp, alpha, STB_DXT_NORMAL);
            datab+=8*(alpha+1);
    }

    free(src);

    glstate.vao->unpack = unpack;
    glstate.vao->pack = pack;
    noerrorShim();
    return;
}

void glshim_glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat,
							GLsizei width, GLint border,
							GLsizei imageSize, const GLvoid *data) {
                                
    glshim_glCompressedTexImage2D(target, level, internalformat, width, 1, border, imageSize, data);
}

void glshim_glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat,
							GLsizei width, GLsizei height, GLsizei depth, GLint border,
							GLsizei imageSize, const GLvoid *data) {
                                
    glshim_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
}

void glshim_glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset,
							   GLsizei width, GLenum format, 
							   GLsizei imageSize, const GLvoid *data) {

    glshim_glCompressedTexSubImage2D(target, level, xoffset, 0, width, 1, format, imageSize, data);
}
void glshim_glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
							   GLsizei width, GLsizei height, GLsizei depth, GLenum format, 
							   GLsizei imageSize, const GLvoid *data) {

    glshim_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}


//Direct wrapper
void glTexImage2D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *data) __attribute__((alias("glshim_glTexImage2D")));
void glTexImage1D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *data) __attribute__((alias("glshim_glTexImage1D")));
void glTexImage3D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *data) __attribute__((alias("glshim_glTexImage3D")));
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *data) __attribute__((alias("glshim_glTexSubImage2D")));
void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *data) __attribute__((alias("glshim_glTexSubImage1D")));
void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,  GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *data) __attribute__((alias("glshim_glTexSubImage3D")));
void glBindTexture(GLenum target, GLuint texture) __attribute__((alias("glshim_glBindTexture")));
void glGenTextures(GLsizei n, GLuint * textures) __attribute__((alias("glshim_glGenTextures")));
void glDeleteTextures(GLsizei n, const GLuint * textures) __attribute__((alias("glshim_glDeleteTextures")));
void glTexParameteri(GLenum target, GLenum pname, GLint param) __attribute__((alias("glshim_glTexParameteri")));
void glTexParameterf(GLenum target, GLenum pname, GLfloat param) __attribute__((alias("glshim_glTexParameterf")));
GLboolean glAreTexturesResident(GLsizei n, const GLuint *textures, GLboolean *residences) __attribute__((alias("glshim_glAreTexturesResident")));
void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params) __attribute__((alias("glshim_glGetTexLevelParameteriv")));
void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid * img) __attribute__((alias("glshim_glGetTexImage")));
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * data) __attribute__((alias("glshim_glReadPixels")));
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedTexImage2D")));
void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedTexImage1D")));
void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedTexImage3D")));
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedTexSubImage2D")));
void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedTexSubImage1D")));
void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedTexSubImage3D")));
void glGetCompressedTexImage(GLenum target, GLint lod, GLvoid *img) __attribute__((alias("glshim_glGetCompressedTexImage")));
void glCopyTexImage1D(GLenum target,  GLint level,  GLenum internalformat,  GLint x,  GLint y, GLsizei width,  GLint border) __attribute__((alias("glshim_glCopyTexImage1D")));
void glCopyTexImage2D(GLenum target,  GLint level,  GLenum internalformat,  GLint x,  GLint y, GLsizei width,  GLsizei height,  GLint border) __attribute__((alias("glshim_glCopyTexImage2D")));
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) __attribute__((alias("glshim_glCopyTexSubImage2D")));
void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) __attribute__((alias("glshim_glCopyTexSubImage1D")));
void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) __attribute__((alias("glshim_glCopyTexSubImage3D")));
void glActiveTexture( GLenum texture ) __attribute__((alias("glshim_glActiveTexture")));
void glClientActiveTexture( GLenum texture ) __attribute__((alias("glshim_glClientActiveTexture")));
GLboolean glIsTexture( GLuint texture ) __attribute__((alias("glshim_glIsTexture")));
void glPixelStorei(GLenum pname, GLint param) __attribute__((alias("glshim_glPixelStorei")));
//EXT mapper
void glTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,  GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *data) __attribute__((alias("glshim_glTexSubImage3D")));
void glCompressedTexImage2DEXT(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedTexImage2D")));
void glCompressedTexImage1DEXT(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedTexImage1D")));
void glCompressedTexImage3DEXT(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedTexImage3D")));
void glCompressedTexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedTexSubImage2D")));
void glCompressedTexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedTexSubImage1D")));
void glCompressedTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedTexSubImage3D")));
void glGetCompressedTexImageEXT(GLenum target, GLint lod, GLvoid *img) __attribute__((alias("glshim_glGetCompressedTexImage")));
void glCopyTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) __attribute__((alias("glshim_glCopyTexSubImage3D")));

//ARB mapper
void glActiveTextureARB(GLenum texture) __attribute__((alias("glshim_glActiveTexture")));
void glClientActiveTextureARB(GLenum texture) __attribute__((alias("glshim_glClientActiveTexture")));
void glTexSubImage3DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,  GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *data) __attribute__((alias("glshim_glTexSubImage3D")));
void glCompressedTexImage2DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedTexImage2D")));
void glCompressedTexImage1DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedTexImage1D")));
void glCompressedTexImage3DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedTexImage3D")));
void glCompressedTexSubImage2DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedTexSubImage2D")));
void glCompressedTexSubImage1DARB(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedTexSubImage1D")));
void glCompressedTexSubImage3DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data) __attribute__((alias("glshim_glCompressedTexSubImage3D")));
void glGetCompressedTexImageARB(GLenum target, GLint lod, GLvoid *img) __attribute__((alias("glshim_glGetCompressedTexImage")));
void glCopyTexSubImage3DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) __attribute__((alias("glshim_glCopyTexSubImage3D")));
