#include "texture.h"
#include "raster.h"
#include "decompress.h"
#include "debug.h"
#include "stb_dxt_104.h"
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include "gles.h"
#include "../glx/streaming.h"
#include "../glx/hardext.h"
#include "init.h"
#include "matrix.h"

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

static int inline nlevel(int size, int level) {
    size>>=level;
    if(!size) size=1;
    return size;
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
    if (!tex || !nwidth || !nheight)
        return;
    GLfloat wratio = (width / (GLfloat)nwidth);
    GLfloat hratio = (height / (GLfloat)nheight);
    for (int i = 0; i < len; i++) {
        tex[0] *= wratio;
        tex[1] *= hratio;
        tex += 4;
    }
}

void tex_coord_matrix(GLfloat *tex, GLsizei len, const GLfloat* mat) {
    if (!tex || !len || !mat)
        return;
    for (int i = 0; i < len; i++) {
        vector_matrix(tex, mat, tex);
        tex += 4;
    }
}

/* Setup the texture coordinates
 * 
 * Have to check is ARB_RECTANGLE is used
 * Apply texture matrix if not identity 
 * Or some NPOT texture used
 */
void tex_setup_texcoord(GLuint len, GLuint itarget) {
    LOAD_GLES(glTexCoordPointer);
    GLuint texunit = glstate->texture.client;
    
    static void * tex[MAX_TEX] = {0};
    static int texlen[MAX_TEX] = {0};
    
    gltexture_t *bound = glstate->texture.bound[texunit][itarget];
    
    // check if some changes are needed
    int changes = 0;
    if ((itarget == ENABLED_TEXTURE_RECTANGLE) 
        || (bound && ((bound->width!=bound->nwidth)||(bound->height!=bound->nheight)
        )) || !(globals4es.texmat || glstate->texture_matrix[texunit]->identity) 
        )
        changes = 1;
    if (changes) {
        // first convert to GLfloat, without normalization
        if(texlen[texunit]<len) {
            if(tex[texunit]) free(tex[texunit]);
            tex[texunit] = malloc(4*sizeof(GLfloat)*len);
            texlen[texunit] = len;
        }
        copy_gl_pointer_tex_noalloc(tex[texunit], &glstate->vao->pointers.tex_coord[texunit], 4, 0, len);
        // Normalize if needed
        if (itarget == ENABLED_TEXTURE_RECTANGLE)
            tex_coord_rect_arb(tex[texunit], len, bound->width, bound->height);
        // Apply transformation matrix if any
        if (!(globals4es.texmat || glstate->texture_matrix[texunit]->identity))
            tex_coord_matrix(tex[texunit], len, getTexMat(texunit));
        // NPOT adjust
        if (bound && ((bound->width!=bound->nwidth) || (bound->height!=bound->nheight)))
            tex_coord_npot(tex[texunit], len, bound->width, bound->height, bound->nwidth, bound->nheight);
        // All done, setup the texcoord array now
        gles_glTexCoordPointer(4, GL_FLOAT, 0, tex[texunit]);
    } else {
        gles_glTexCoordPointer(glstate->vao->pointers.tex_coord[texunit].size, glstate->vao->pointers.tex_coord[texunit].type, glstate->vao->pointers.tex_coord[texunit].stride, glstate->vao->pointers.tex_coord[texunit].pointer);
    }
}

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
        case GL_BGRA:
            *format = GL_BGRA;
            *type = GL_UNSIGNED_BYTE;
            break;
        case GL_DEPTH_COMPONENT:
            *format = GL_DEPTH_COMPONENT;
            *type = GL_UNSIGNED_SHORT;
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
            if(globals4es.nolumalpha)
                convert = true;
            else {
                dest_format = GL_LUMINANCE_ALPHA;
                *format = GL_LUMINANCE_ALPHA;
            }
            break;
        case GL_LUMINANCE_ALPHA:
            if(globals4es.nolumalpha)
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
        case GL_BGRA:
            if(hardext.bgra8888 && ((*type)==GL_UNSIGNED_BYTE)) {
                dest_format = GL_BGRA;
                *format = GL_BGRA;
            } else convert = true;
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
								*format, *type, dest_format, dest_type, 0, glstate->texture.unpack_align)) {
				printf("LIBGL: swizzle error: (%s, %s -> %s, %s)\n",
					PrintEnum(*format), PrintEnum(*type), PrintEnum(dest_format), PrintEnum(dest_type));
				return NULL;
			}
			*type = dest_type;
			*format = dest_format;
            if(dest_format!=internalformat) {
                GLvoid *pix2 = (GLvoid *)pixels;
                internal2format_type(internalformat, &dest_format, &dest_type);
                if (! pixel_convert(pixels, &pix2, width, height,
                                    *format, *type, dest_format, dest_type, 0, glstate->texture.unpack_align)) {
                    printf("LIBGL: swizzle error: (%s, %s -> %s, %s)\n",
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
								*format, *type, glstate->raster.raster_scale, glstate->raster.raster_bias)) {
					printf("LIBGL: swizzle/convert error: (%s, %s -> %s, %s)\n",
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

GLenum swizzle_internalformat(GLenum *internalformat, GLenum format, GLenum type) {
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
            if (globals4es.nolumalpha)
                sret = GL_RGBA;
            else
                sret = GL_LUMINANCE_ALPHA;
            break;
        case GL_RGB5:
            sret = GL_RGB5;
            break;
        case GL_RGB:
             if(globals4es.avoid16bits==0 && format==GL_RGB && type==GL_UNSIGNED_SHORT_5_6_5) {
                sret = ret = GL_RGB5;
                break;
            }
        case GL_RGB8:
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
            if(globals4es.avoid16bits==0 && format==GL_RGBA && type==GL_UNSIGNED_SHORT_5_5_5_1) {
                sret = ret = GL_RGB5_A1;
                break;
            }
            if(globals4es.avoid16bits==0 && format==GL_RGBA && type==GL_UNSIGNED_SHORT_4_4_4_4) {
                sret = ret = GL_RGBA4;
                break;
            }
        case GL_RGBA8:
        case GL_RGBA16:
        case GL_RGBA16F:
        case GL_RGBA32F:
        case GL_RGB10_A2:
        case 4: 
            if(format==GL_BGRA && hardext.bgra8888) {
                ret = GL_BGRA; sret = GL_BGRA; 
            } else {
                ret = GL_RGBA; sret = GL_RGBA; 
            }
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
            if (globals4es.nolumalpha)
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
            if (globals4es.nolumalpha)
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
        case GL_BGRA:
            if(hardext.bgra8888) {
                ret = GL_BGRA;
                sret = GL_BGRA;
            } else {
                ret = GL_RGBA;
                sret = GL_RGBA;
            }
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

static int get_shrinklevel(int width, int height, int level) {
    int shrink = 0;
    int mipwidth = width << level;
    int mipheight = height << level;
    switch(globals4es.texshrink) {
        case 0: // nothing
            break;
        case 1: //everything / 2
            if ((mipwidth > 1) && (mipheight > 1)) {
                shrink = 1;
            }
            break;
        case 2: //only > 512 /2
        case 7: //only > 512 /2 , but not for empty texture
            if (((mipwidth%2==0) && (mipheight%2==0)) && 
                ((mipwidth > 512) && (mipheight > 8)) || ((mipheight > 512) && (mipwidth > 8))) {
                shrink = 1;
            }
            break;
        case 3: //only > 256 /2
            if (((mipwidth%2==0) && (mipheight%2==0)) && 
                ((mipwidth > 256) && (mipheight > 8)) || ((mipheight > 256) && (mipwidth > 8))) {
                shrink = 1;
            }
            break;
        case 4: //only > 256 /2, >=1024 /4
        case 5: //every > 256 is downscaled to 256, but not for empty texture   (as there is no downscale stronger than 4, there are the same)
            if (((mipwidth%4==0) && (mipheight%4==0)) && 
                ((mipwidth > 256) && (mipheight > 8)) || ((mipheight > 256) && (mipwidth > 8))) {
                if ((mipwidth>=1024) || (mipheight>=1024)) {
                    shrink = 2;
                } else {
                    shrink = 1;
                }
            }
            break;
        case 6: //only > 128 /2, >=512 is downscaled to 256, but not for empty texture
            if (((mipwidth%2==0) && (mipheight%2==0)) && 
                ((mipwidth > 128) && (mipheight > 8)) || ((mipheight > 128) && (mipwidth > 8))) {
                if (((mipwidth%2==0) && (mipheight%2==0)) && (mipwidth>=512) || (mipheight>=512)) {
                    while (((mipwidth > 256) && (mipheight > 8)) || ((mipheight > 256) && (mipwidth > 8))) {
                        width /= 2;
                        height /= 2;
                        mipwidth /= 2;
                        mipheight /= 2;
                        shrink+=1;
                    }
                } else {
                    shrink = 1;
                }
            }
            break;
        case 8: //advertise 8192 max texture size, but >2048 are shrinked to 2048
            if ((mipwidth>4096) || (mipheight>4096)) {
                shrink=2;
            } else
            if ((mipwidth>2048) || (mipheight>2048)) {
                shrink=1;
            }
            break;
        case 9: //advertise 8192 max texture size, but >4096 are quadshrinked and >512 are shrinked, but not for empty texture
            if ((mipwidth>4096) || (mipheight>4096)) {
                shrink=2;
            } else
            if ((mipwidth>512) || (mipheight>512)) {
                shrink=1;
            }
            break;
        case 10://advertise 8192 max texture size, but >2048 are quadshrinked and >512 are shrinked, but not for empty texture
            if ((mipwidth>2048) || (mipheight>2048)) {
                shrink=2;
            } else
            if ((mipwidth>512) || (mipheight>512)) {
                shrink=1;
            }
            break;
        }
    return shrink;
} 

static int default_tex_mipmap = 0;

static int proxy_width = 0;
static int proxy_height = 0;
static GLint proxy_intformat = 0;

void gl4es_glTexImage2D(GLenum target, GLint level, GLint internalformat,
                  GLsizei width, GLsizei height, GLint border,
                  GLenum format, GLenum type, const GLvoid *data) {

    //printf("glTexImage2D on target=%s with unpack_row_length(%i), size(%i,%i) and skip(%i,%i), format(internal)=%s(%s), type=%s, data=%08x, level=%i (mipmap_need=%i, mipmap_auto=%i, base_level=%i, max_level=%i) => texture=%u (streamed=%i), glstate->list.compiling=%d\n", PrintEnum(target), glstate->texture.unpack_row_length, width, height, glstate->texture.unpack_skip_pixels, glstate->texture.unpack_skip_rows, PrintEnum(format), PrintEnum(internalformat), PrintEnum(type), data, level, (glstate->texture.bound[glstate->texture.active][what_target(target)])?glstate->texture.bound[glstate->texture.active][what_target(target)]->mipmap_need:0, (glstate->texture.bound[glstate->texture.active][what_target(target)])?glstate->texture.bound[glstate->texture.active][what_target(target)]->mipmap_auto:0, (glstate->texture.bound[glstate->texture.active][what_target(target)])?glstate->texture.bound[glstate->texture.active][what_target(target)]->base_level:0, (glstate->texture.bound[glstate->texture.active][what_target(target)])?glstate->texture.bound[glstate->texture.active][what_target(target)]->max_level:0, (glstate->texture.bound[glstate->texture.active][what_target(target)])?glstate->texture.bound[glstate->texture.active][what_target(target)]->texture:0, (glstate->texture.bound[glstate->texture.active][what_target(target)])?glstate->texture.bound[glstate->texture.active][what_target(target)]->streamed:0, glstate->list.compiling);
    // proxy case

    const GLuint itarget = what_target(target);
    const GLuint rtarget = map_tex_target(target);

    if (rtarget == GL_PROXY_TEXTURE_2D) {
        int max1=hardext.maxsize;
        if (globals4es.texshrink>=8 && max1>8192) max1=8192;
        proxy_width = ((width<<level)>max1)?0:width;
        proxy_height = ((height<<level)>max1)?0:height;
        proxy_intformat = swizzle_internalformat(&internalformat, format, type);
        return;
    }
    GLuint old_glbatch = glstate->gl_batch;
    if (glstate->gl_batch || glstate->list.pending) {
        flush();
        glstate->gl_batch = 0;
    } else {
        PUSH_IF_COMPILING(glTexImage2D);
    }
    
    GLvoid *datab = (GLvoid*)data;
    
	if (glstate->vao->unpack)
		datab += (uintptr_t)glstate->vao->unpack->data;
        
    GLvoid *pixels = (GLvoid *)datab;
    border = 0;	//TODO: something?
    noerrorShim();

    gltexture_t *bound = glstate->texture.bound[glstate->texture.active][itarget];
    if (bound) bound->alpha = pixel_hasalpha(format);
    if (globals4es.automipmap) {
        if (bound && (level>0))
            if ((globals4es.automipmap==1) || (globals4es.automipmap==3) || bound->mipmap_need) {
                glstate->gl_batch = old_glbatch;
                return;			// has been handled by auto_mipmap
            }
            else
                bound->mipmap_need = 1;
     }
     GLenum new_format = swizzle_internalformat(&internalformat, format, type);
     if (bound && (level==0)) {
         bound->orig_internal = internalformat;
         bound->internalformat = new_format;
     }
    // shrink checking
    int mipwidth = width << level;
    int mipheight = height << level;
    int shrink = 0;
    if(bound) {
        bound->shrink = shrink = get_shrinklevel(width, height, level);
    }
    if(width>>shrink==0 && height>>shrink==0) return;   // nothing to do
     if (datab) {

        // implements GL_UNPACK_ROW_LENGTH
        if ((glstate->texture.unpack_row_length && glstate->texture.unpack_row_length != width) || glstate->texture.unpack_skip_pixels || glstate->texture.unpack_skip_rows) {
            int imgWidth, pixelSize;
            pixelSize = pixel_sizeof(format, type);
            imgWidth = ((glstate->texture.unpack_row_length)? glstate->texture.unpack_row_length:width) * pixelSize;
            GLubyte *dst = (GLubyte *)malloc(width * height * pixelSize);
            pixels = (GLvoid *)dst;
            const GLubyte *src = (GLubyte *)datab;
            src += glstate->texture.unpack_skip_pixels * pixelSize + glstate->texture.unpack_skip_rows * imgWidth;
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

        if (bound && bound->shrink!=0) {
            switch(globals4es.texshrink) {
            case 0: // nothing ???
                break;
            case 1: //everything / 2
                if ((mipwidth > 1) && (mipheight > 1)) {
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
            default:
                while(shrink) {
                    if (shrink>1) { // quarterscale
                        GLvoid *out = pixels;
                        pixel_quarterscale(pixels, &out, width, height, format, type);
                        if (out != pixels && pixels!=datab)
                            free(pixels);
                        pixels = out;
                        width = nlevel(width, 2);
                        height = nlevel(height, 2);
                        shrink-=2;
                    } else {    //halfscale
                        GLvoid *out = pixels;
                        pixel_halfscale(pixels, &out, width, height, format, type);
                        if (out != pixels && pixels!=datab)
                            free(pixels);
                        pixels = out;
                        width = nlevel(width, 1);
                        height = nlevel(height, 1);
                        shrink--;
                    }
                }
            }
        }
        
        if (globals4es.texdump) {
            if (bound) {
                pixel_to_ppm(pixels, width, height, format, type, bound->texture, glstate->texture.pack_align);
            }
        }
    } else {
#ifdef TEXSTREAM
	    if (globals4es.texstream && bound && (target==GL_TEXTURE_2D) && (width>=256 && height>=256) && 
		((internalformat==GL_RGB) || (internalformat==3) || (internalformat==GL_RGB8) || (internalformat==GL_BGR) || (internalformat==GL_RGB5)) || (globals4es.texstream==2) ) {
			bound->streamingID = AddStreamed(width, height, bound->texture);
			if (bound->streamingID>-1) {	// success
                bound->shrink = 0;  // no shrink on Stream texture
				bound->streamed = true;
				ApplyFilterID(bound->streamingID, bound->min_filter, bound->mag_filter);
				GLboolean tmp = IS_TEX2D(glstate->enable.texture[glstate->texture.active]);
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
            if (!bound->streamed)
                swizzle_texture(width, height, &format, &type, internalformat, new_format, NULL);	// convert format even if data is NULL
            width = nlevel(width, bound->shrink);
            height = nlevel(height, bound->shrink);
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

    {
        GLsizei nheight = (hardext.npot==2)?height:npot(height), nwidth = (hardext.npot==2)?width:npot(width);
        if(target==GL_TEXTURE_RECTANGLE_ARB && hardext.npot==1) {
            nheight = height;
            nwidth = width;
        }
#ifdef PANDORA
#define NO_1x1
#endif
#ifdef NO_1x1
        #define MIN_SIZE 2
        if(level==0) {
            if(nwidth < MIN_SIZE) nwidth=MIN_SIZE;
            if(nheight < MIN_SIZE) nheight=MIN_SIZE;
        }
        #undef MIN_SIZE
#endif
        if (globals4es.texstream && bound && bound->streamed) {
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
        if ((bound) && (globals4es.automipmap==4) && (nwidth!=nheight))
            bound->mipmap_auto = 0;

        if((bound) && (target==GL_TEXTURE_RECTANGLE_ARB && hardext.npot==1)) {
            gl4es_glTexParameteri(rtarget, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            gl4es_glTexParameteri(rtarget, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        }

        if (!(globals4es.texstream && bound && bound->streamed)) {
            if (bound && (target!=GL_TEXTURE_RECTANGLE_ARB) && ((bound->mipmap_need && (globals4es.automipmap!=3)) || (bound->mipmap_auto)))
                gles_glTexParameteri( rtarget, GL_GENERATE_MIPMAP, GL_TRUE );
            else {
                //if(target!=GL_TEXTURE_RECTANGLE_ARB) gles_glTexParameteri( rtarget, GL_GENERATE_MIPMAP, GL_FALSE );
                if ((bound)  && (itarget!=ENABLED_CUBE_MAP && target!=GL_TEXTURE_RECTANGLE_ARB) && (bound->mipmap_need)) {
                    // remove the need for mipmap...
                    bound->mipmap_need = 0;
                    gl4es_glTexParameteri(rtarget, GL_TEXTURE_MIN_FILTER, bound->min_filter);
                    gl4es_glTexParameteri(rtarget, GL_TEXTURE_MAG_FILTER, bound->mag_filter);
                }
            }
            
            if (height != nheight || width != nwidth) {
                gles_glTexImage2D(rtarget, level, format, nwidth, nheight, border,
                                format, type, NULL);
                if (pixels) gles_glTexSubImage2D(rtarget, level, 0, 0, width, height,
                                        format, type, pixels);
                errorGL();
#ifdef NO_1x1
                if(level==0 && (width==1 || height==1 && pixels)) {
                    // complete the texture, juste in case it use GL_REPEAT
                    // also, don't keep the fact we have resized, the non-adjusted coordinates will work (as the texture is enlarged)
                    if(width==1) {gles_glTexSubImage2D(rtarget, level, 1, 0, width, height, format, type, pixels); nwidth=1;}
                    if(height==1) {gles_glTexSubImage2D(rtarget, level, 0, 1, width, height, format, type, pixels); nheight=1;}
                    if(width==1 && height==1) {   // create a manual mipmap just in case_state
                        gles_glTexSubImage2D(rtarget, level, 1, 1, width, height, format, type, pixels);
                        gles_glTexImage2D(rtarget, 1, format, 1, 1, 0, format, type, pixels);
                    }
                }
#endif
            } else {
                gles_glTexImage2D(rtarget, level, format, width, height, border,
                                format, type, pixels);
                errorGL();
            }
            // check if base_level is set... and calculate lower level mipmap
            if(bound->base_level == level) {
                int leveln = level, nw = width, nh = height, nww=nwidth, nhh=nheight;
                int pot = (nh==nhh && nw==nww);
                void *ndata = pixels;
                while(leveln) {
                    if(pixels) {
                        GLvoid *out = ndata;
                        pixel_doublescale(ndata, &out, nw, nh, format, type);
                        if (out != ndata && ndata!=pixels)
                            free(ndata);
                        ndata = out;
                    }
                    nw <<= 1;
                    nh <<= 1;
                    nww <<= 1;
                    nhh <<= 1;
                    --leveln;
                    gles_glTexImage2D(rtarget, leveln, format, nww, nhh, border,
                                    format, type, (pot)?ndata:NULL);
                    if(!pot && pixels) gles_glTexSubImage2D(rtarget, leveln, 0, 0, nw, nh,
                                        format, type, ndata);
                }
                if (ndata!=pixels)
                    free(ndata);
            }
            // check if max_level is set... and calculate highr level mipmap
            if(bound->max_level == level) {
                int leveln = level, nw = nwidth, nh = nheight, nww=width, nhh=height;
                int pot = (nh==nhh && nw==nww);
                void *ndata = pixels;
                while(nw!=1 && nh!=1) {
                    if(pixels) {
                        GLvoid *out = ndata;
                        pixel_halfscale(ndata, &out, nww, nhh, format, type);
                        if (out != ndata && ndata!=pixels)
                            free(ndata);
                        ndata = out;
                    }
                    nw = nlevel(nw, 1);
                    nh = nlevel(nh, 1);
                    nww = nlevel(nww, 1);
                    nhh = nlevel(nhh, 1);
                    ++leveln;
                    gles_glTexImage2D(rtarget, leveln, format, nw, nh, border,
                                    format, type, (pot)?ndata:NULL);
                    if(!pot && pixels) gles_glTexSubImage2D(rtarget, leveln, 0, 0, nww, nhh,
                                        format, type, ndata);
                }
                if (ndata!=pixels)
                    free(ndata);
            }
        /*if (bound && bound->mipmap_need && !bound->mipmap_auto && (globals4es.automipmap!=3))
            gles_glTexParameteri( rtarget, GL_GENERATE_MIPMAP, GL_FALSE );*/
        } else {
            if (pixels)
                gl4es_glTexSubImage2D(rtarget, level, 0, 0, width, height, format, type, pixels);	// (should never happens) updload the 1st data...
            }
    }
    if ((target==GL_TEXTURE_2D) && globals4es.texcopydata && bound && ((globals4es.texstream && !bound->streamed) || !globals4es.texstream)) {
	    if (bound->data) 
			bound->data=realloc(bound->data, width*height*4);
	    else 
			bound->data = malloc(width*height*4);
	    if (datab) {
		    if (!pixel_convert(pixels, &bound->data, width, height, format, type, GL_RGBA, GL_UNSIGNED_BYTE, 0, glstate->texture.pack_align))
			    printf("LIBGL: Error on pixel_convert when TEXCOPY in glTexImage2D\n");
	    } else {
		//memset(bound->data, 0, width*height*4);
	    }
	}
    if (pixels != datab) {
        free(pixels);
    }
    glstate->gl_batch = old_glbatch;
}

void gl4es_glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset,
                     GLsizei width, GLsizei height, GLenum format, GLenum type,
                     const GLvoid *data) {

    GLuint old_glbatch = glstate->gl_batch;
    if (glstate->gl_batch || glstate->list.pending) {
        flush();
        glstate->gl_batch = 0;
    } else {
        PUSH_IF_COMPILING(glTexSubImage2D);
    }

    GLvoid *datab = (GLvoid*)data;
	if (glstate->vao->unpack)
		datab += (uintptr_t)glstate->vao->unpack->data;
    GLvoid *pixels = (GLvoid*)datab;

    const GLuint itarget = what_target(target);
    const GLuint rtarget = map_tex_target(target);

    LOAD_GLES(glTexSubImage2D);
    LOAD_GLES(glTexParameteri);
    noerrorShim();
    //printf("glTexSubImage2D on target=%s with unpack_row_length(%i), size(%i,%i), pos(%i,%i) and skip={%i,%i}, format=%s, type=%s, level=%i, texture=%u\n", PrintEnum(target), glstate->texture.unpack_row_length, width, height, xoffset, yoffset, glstate->texture.unpack_skip_pixels, glstate->texture.unpack_skip_rows, PrintEnum(format), PrintEnum(type), level, glstate->texture.bound[glstate->texture.active][itarget]->texture);
    if (width==0 || height==0) {
        glstate->gl_batch = old_glbatch;
        return;
    }
    
    gltexture_t *bound = glstate->texture.bound[glstate->texture.active][itarget];
    if (globals4es.automipmap) {
        if (bound && (level>0))
            if ((globals4es.automipmap==1) || (globals4es.automipmap==3) || bound->mipmap_need) {
                glstate->gl_batch = old_glbatch;
                return;			// has been handled by auto_mipmap
            }
            else
                bound->mipmap_need = 1;
    }

    if ((glstate->texture.unpack_row_length && glstate->texture.unpack_row_length != width) || glstate->texture.unpack_skip_pixels || glstate->texture.unpack_skip_rows) {
	    int imgWidth, pixelSize;
	    pixelSize = pixel_sizeof(format, type);
	    imgWidth = ((glstate->texture.unpack_row_length)? glstate->texture.unpack_row_length:width) * pixelSize;
	    GLubyte *dst = (GLubyte *)malloc(width * height * pixelSize);
	    pixels = (GLvoid *)dst;
	    const GLubyte *src = (GLubyte *)datab;
	    src += glstate->texture.unpack_skip_pixels * pixelSize + glstate->texture.unpack_skip_rows * imgWidth;
	    for (int y = 0; y < height; y ++) {
		    memcpy(dst, src, width * pixelSize);
		    src += imgWidth;
		    dst += width * pixelSize;
	    }
    }
    
    // compressed format are not handled here, so mask them....
    GLenum orig_internal = bound->orig_internal;
    GLenum internalformat = bound->internalformat;
    // compressed format are not handled here, so mask them....
    if (is_fake_compressed_rgb(orig_internal)) orig_internal=GL_RGB;
    if (is_fake_compressed_rgba(orig_internal)) orig_internal=GL_RGBA;
    if (is_fake_compressed_rgb(internalformat)) internalformat=GL_RGB;
    if (is_fake_compressed_rgba(internalformat)) internalformat=GL_RGBA;


    GLvoid *old = pixels;
#ifdef TEXSTREAM
    if (bound && globals4es.texstream && (bound->streamed)) {
		// Optimisation, let's do convert directly to the right place...
		GLvoid *tmp = GetStreamingBuffer(bound->streamingID);
		tmp += (yoffset*bound->width+xoffset)*2;
		if (! pixel_convert(old, &tmp, width, height,
						format, type, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, bound->width, glstate->texture.pack_align)) {
			printf("LIBGL: swizzle error: (%#4x, %#4x -> GL_RGB, UNSIGNED_SHORT_5_6_5)\n",
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
        if (!pixel_convert(old, &pixels, width, height, format, type, dest_format, dest_type, 0, glstate->texture.pack_align)) {
            printf("LIBGL: Error in pixel_convert while glTexSubImage2D\n");
        } else {
            format = dest_format;
            type = dest_type;
            if(orig_internal!=internalformat) {
                GLvoid* pix2 = pixels;
                internal2format_type(internalformat, &dest_format, &dest_type);
                if (!pixel_convert(pixels, &pix2, width, height, format, type, dest_format, dest_type, 0, glstate->texture.pack_align)) {
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
            glstate->gl_batch = old_glbatch;
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

    if (globals4es.texdump) {
        if (bound) {
            pixel_to_ppm(pixels, width, height, format, type, bound->texture, glstate->texture.pack_align);
        }
    }

    if (bound && bound->mipmap_need && !bound->mipmap_auto && (globals4es.automipmap!=3) && (!globals4es.texstream || (globals4es.texstream && !bound->streamed)))
        gles_glTexParameteri( rtarget, GL_GENERATE_MIPMAP, GL_TRUE );

    if (bound && globals4es.texstream && bound->streamed) {
/*	// copy the texture to the buffer
	void* tmp = GetStreamingBuffer(bound->streamingID);
	for (int yy=0; yy<height; yy++) {
		memcpy(tmp+((yy+yoffset)*bound->width+xoffset)*2, pixels+(yy*width)*2, width*2);
	}*/
    } else {
        gles_glTexSubImage2D(rtarget, level, xoffset, yoffset,
					 width, height, format, type, pixels);
		errorGL();
        // check if base_level is set... and calculate lower level mipmap
        if(bound->base_level == level) {
            int leveln = level, nw = width, nh = height, xx=xoffset, yy=yoffset;
            void *ndata = pixels;
            while(leveln) {
                if(pixels) {
                    GLvoid *out = ndata;
                    pixel_doublescale(ndata, &out, nw, nh, format, type);
                    if (out != ndata && ndata!=pixels)
                        free(ndata);
                    ndata = out;
                }
                nw <<= 1;
                nh <<= 1;
                xx <<= 1;
                yy <<= 1;
                --leveln;
                gles_glTexSubImage2D(rtarget, leveln, xx, yy, nw, nh,
                                    format, type, ndata);
            }
            if (ndata!=pixels)
                free(ndata);
        }
        // check if max_level is set... and calculate highr level mipmap
        if(bound->max_level == level) {
            int leveln = level, nw = width, nh = height, xx=xoffset, yy=yoffset;
            void *ndata = pixels;
            while(nw!=1 && nh!=1) {
                if(pixels) {
                    GLvoid *out = ndata;
                    pixel_halfscale(ndata, &out, nw, nh, format, type);
                    if (out != ndata && ndata!=pixels)
                        free(ndata);
                    ndata = out;
                }
                nw = nlevel(nw, 1);
                nh = nlevel(nh, 1);
                xx = nlevel(xx, 1);
                yy = nlevel(yy, 1);
                ++leveln;
                gles_glTexSubImage2D(rtarget, leveln, xx, yy, nw, nh,
                                    format, type, ndata);
            }
            if (ndata!=pixels)
                free(ndata);
        }

    }

    /*if (bound && bound->mipmap_need && !bound->mipmap_auto && (globals4es.automipmap!=3) && (!globals4es.texstream || (globals4es.texstream && !bound->streamed)))
        gles_glTexParameteri( rtarget, GL_GENERATE_MIPMAP, GL_FALSE );*/

    if ((target==GL_TEXTURE_2D) && globals4es.texcopydata && bound && ((globals4es.texstream && !bound->streamed) || !globals4es.texstream)) {
    //printf("*texcopy* glTexSubImage2D, xy=%i,%i, size=%i,%i=>%i,%i, format=%s, type=%s, tex=%u\n", xoffset, yoffset, width, height, bound->width, bound->height, PrintEnum(format), PrintEnum(type), bound->glname);
        GLvoid * tmp = bound->data;
        tmp += (yoffset*bound->width + xoffset)*4;
        if (!pixel_convert(pixels, &tmp, width, height, format, type, GL_RGBA, GL_UNSIGNED_BYTE, bound->width, glstate->texture.pack_align))
            printf("LIBGL: Error on pixel_convert while TEXCOPY in glTexSubImage2D\n");
    }

    if (pixels != datab)
        free((GLvoid *)pixels);
    glstate->gl_batch = old_glbatch;
}

// 1d stubs
void gl4es_glTexImage1D(GLenum target, GLint level, GLint internalFormat,
                  GLsizei width, GLint border,
                  GLenum format, GLenum type, const GLvoid *data) {

    // TODO: maybe too naive to force GL_TEXTURE_2D here?
    gl4es_glTexImage2D(GL_TEXTURE_1D, level, internalFormat, width, 1,
                 border, format, type, data);
}
void gl4es_glTexSubImage1D(GLenum target, GLint level, GLint xoffset,
                     GLsizei width, GLenum format, GLenum type,
                     const GLvoid *data) {

    gl4es_glTexSubImage2D(GL_TEXTURE_1D, level, xoffset, 0,
                    width, 1, format, type, data);
}
void gl4es_glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y,
		    GLsizei width, GLint border) {
    gl4es_glCopyTexImage2D(GL_TEXTURE_1D, level, internalformat, x, y, width, 1, border);
		    
}

void gl4es_glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y,
                                GLsizei width) {
    gl4es_glCopyTexSubImage2D(GL_TEXTURE_1D, level, xoffset, 0, x, y, width, 1);
}
                                
void gl4es_glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
                                GLint x, GLint y, GLsizei width, GLsizei height) {
    gl4es_glCopyTexSubImage2D(GL_TEXTURE_3D, level, xoffset, yoffset, x, y, width, height);
}

                                


// 3d stubs
void gl4es_glTexImage3D(GLenum target, GLint level, GLint internalFormat,
                  GLsizei width, GLsizei height, GLsizei depth, GLint border,
                  GLenum format, GLenum type, const GLvoid *data) {

    // TODO: maybe too naive to force GL_TEXTURE_2D here?
    gl4es_glTexImage2D(GL_TEXTURE_3D, level, internalFormat, width, height,
                 border, format, type, data);
}
void gl4es_glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, 
                     GLsizei width, GLsizei height, GLsizei depth, GLenum format,
                     GLenum type, const GLvoid *data) {

    gl4es_glTexSubImage2D(GL_TEXTURE_3D, level, xoffset, yoffset,
                    width, height, format, type, data);
}

void gl4es_glPixelStorei(GLenum pname, GLint param) {
    // TODO: add to glGetIntegerv?
//   if (glstate->gl_batch) flush();

    LOAD_GLES(glPixelStorei);
    noerrorShim();
    switch (pname) {
        case GL_UNPACK_ROW_LENGTH:
            glstate->texture.unpack_row_length = param;
            return;
        case GL_UNPACK_SKIP_PIXELS:
            glstate->texture.unpack_skip_pixels = param;
            return;
        case GL_UNPACK_SKIP_ROWS:
            glstate->texture.unpack_skip_rows = param;
            return;
        case GL_UNPACK_LSB_FIRST:
            glstate->texture.unpack_lsb_first = param;
            return;
        case GL_UNPACK_IMAGE_HEIGHT:
            glstate->texture.unpack_image_height = param;
            return;
        case GL_UNPACK_SWAP_BYTES:
        case GL_PACK_SWAP_BYTES:
            // Fake... TODO?
            //glstate->texture.unpack_lsb_first = param;
            return;
        case GL_PACK_ROW_LENGTH:
            glstate->texture.pack_row_length = param;
            return;
        case GL_PACK_SKIP_PIXELS:
            glstate->texture.pack_skip_pixels = param;
            return;
        case GL_PACK_SKIP_ROWS:
            glstate->texture.pack_skip_rows = param;
            return;
        case GL_PACK_LSB_FIRST:
            glstate->texture.pack_lsb_first = param;
            return;
        case GL_PACK_IMAGE_HEIGHT:
            glstate->texture.pack_image_height = param;
            return;
        case GL_PACK_ALIGNMENT:
            if(glstate->texture.pack_align==param)
                return;
            if (param!=1 && param!=2 && param!=4 && param!=8) {
                errorShim(GL_INVALID_VALUE);
                return;
            }
            glstate->texture.pack_align=param;
            break;
        case GL_UNPACK_ALIGNMENT:
            if(glstate->texture.unpack_align==param)
                return;
            if (param!=1 && param!=2 && param!=4 && param!=8) {
                errorShim(GL_INVALID_VALUE);
                return;
            }
            glstate->texture.unpack_align=param;
            break;
    }
    errorGL();
    gles_glPixelStorei(pname, param);
}

GLboolean gl4es_glIsTexture(GLuint texture) {
	noerrorShim();
	if (!texture) {
		return GL_FALSE;
	}
    int ret;
	khint_t k;
	khash_t(tex) *list = glstate->texture.list;
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

gltexture_t* gl4es_getTexture(GLenum target, GLuint texture) {
    // Get a texture based on glID
    gltexture_t* tex = NULL;
    //if (texture == 0) return tex; // texture 0 is a texture like any other... it is not "unbind" texture in fact!!
    int ret;
    khint_t k;
    khash_t(tex) *list = glstate->texture.list;
    if (! list) {
        list = glstate->texture.list = kh_init(tex);
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
        tex->mipmap_auto = default_tex_mipmap || (globals4es.automipmap==1);
        tex->mipmap_need = (globals4es.automipmap==1)?1:0;
        tex->streamingID = -1;
        tex->base_level = -1;
        tex->max_level = -1;
        tex->streamed = false;
        tex->alpha = true;
        tex->compressed = false;
        tex->min_filter = tex->mag_filter = (globals4es.automipmap==1)?GL_LINEAR_MIPMAP_LINEAR:GL_LINEAR;
        tex->format = GL_RGBA;
        tex->type = GL_UNSIGNED_BYTE;
        tex->shrink = 0;
        tex->data = NULL;
    } else {
        tex = kh_value(list, k);
    }
    return tex;
}
#define batch_activetex (glstate->statebatch.active_tex_changed?(glstate->statebatch.active_tex-GL_TEXTURE0):glstate->texture.active)
void gl4es_glBindTexture(GLenum target, GLuint texture) {
	noerrorShim();
    //printf("glBindTexture(%s, %u), active=%i, client=%i, list.active=%p (compiling=%d, pending=%d)\n", PrintEnum(target), texture, glstate->texture.active, glstate->texture.client, glstate->list.active, glstate->list.compiling, glstate->list.pending);
    if(glstate->list.pending) flush();
    if ((target!=GL_PROXY_TEXTURE_2D) && (glstate->list.active && (glstate->gl_batch && !glstate->list.compiling)))  {
        if ((glstate->statebatch.bound_targ[batch_activetex] == target) && (glstate->statebatch.bound_tex[batch_activetex] == texture))
            return; // nothing to do...
        if (glstate->statebatch.bound_targ[batch_activetex]) {
            flush();
        }
        glstate->statebatch.bound_targ[batch_activetex] = target;
        glstate->statebatch.bound_tex[batch_activetex] = texture;
    }
    if ((target!=GL_PROXY_TEXTURE_2D) && ((glstate->list.compiling || glstate->gl_batch) && glstate->list.active)) {
        // check if already a texture binded, if yes, create a new list
        NewStage(glstate->list.active, STAGE_BINDTEX);
        rlBindTexture(glstate->list.active, target, texture);
    } else {
    	int tex_changed = 1;
		int streamingID = -1;
        gltexture_t *tex = NULL;
        const GLuint itarget = what_target(target);

        tex = gl4es_getTexture(target, texture);
        if (glstate->texture.bound[glstate->texture.active][itarget] == tex)
            tex_changed = 0;
        texture = tex->glname;
        if (globals4es.texstream && tex->streamed)
            streamingID = tex->streamingID;
	
        LOAD_GLES(glDisable);
        LOAD_GLES(glEnable);
tex_changed=1;  // seems buggy, temporary disabling that...

        if (tex_changed) {

			GLuint tmp = glstate->enable.texture[glstate->texture.active];
#ifdef TEXSTREAM
	        if (globals4es.texstream) {  // unbind streaming texture if any...
	            gltexture_t *bound = glstate->texture.bound[glstate->texture.active][itarget];
	            if (bound && bound->streamed) {
	                if (tmp)
                        gles_glDisable(GL_TEXTURE_STREAM_IMG);
	                DeactivateStreaming();
	                if (tmp)
                        gles_glEnable(GL_TEXTURE_2D);
	            }
	        }
#endif

	        const GLuint rtarget = map_tex_target(target);

            glstate->texture.bound[glstate->texture.active][itarget] = tex;

            LOAD_GLES(glBindTexture);
#ifdef TEXSTREAM
            if (globals4es.texstream && (streamingID>-1)) {
                if (IS_TEX2D(tmp))
                    gles_glDisable(GL_TEXTURE_2D);
                ActivateStreaming(streamingID);
                if (IS_TEX2D(tmp))
                    gles_glEnable(GL_TEXTURE_STREAM_IMG);
            } else 
#endif
            {
                gles_glBindTexture(rtarget, texture);
                errorGL();
            }
        }
    }
}
#undef batch_activetex

// TODO: also glTexParameterf(v)?
void gl4es_glTexParameteri(GLenum target, GLenum pname, GLint param) {
    PUSH_IF_COMPILING(glTexParameteri);
    LOAD_GLES(glTexParameteri);
    const GLint itarget = what_target(target);
    const GLuint rtarget = map_tex_target(target);
    gltexture_t *texture = glstate->texture.bound[glstate->texture.active][itarget];
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
		    if ((globals4es.automipmap==3) || ((texture) && (globals4es.automipmap==1) && (texture->mipmap_auto==0)))
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
        case GL_CLAMP_TO_BORDER:
		    param = GL_CLAMP_TO_EDGE;
		    break;
	    }
        if (pname==GL_TEXTURE_WRAP_S) if (texture) texture->wrap_s = param;
		if (pname==GL_TEXTURE_WRAP_T) if (texture) texture->wrap_t = param;
	    break;
	case GL_TEXTURE_WRAP_R:
        // ignore it on GLES...
        break;
	case GL_TEXTURE_MAX_LEVEL:
	    if (texture)
		    texture->max_level = param;
	    return;			// not on GLES
    case GL_TEXTURE_BASE_LEVEL:
	    if (texture)
		    texture->base_level = param;
	    return;			// not on GLES
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
	    //return;         // We control the behavour later
        break;
    }
    gles_glTexParameteri(rtarget, pname, param);
    errorGL();
}

void gl4es_glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
    gl4es_glTexParameteri(target, pname, param);
}

void gl4es_glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    switch (pname) {
	case GL_TEXTURE_MIN_FILTER:
	case GL_TEXTURE_MAG_FILTER:
	case GL_TEXTURE_WRAP_S:
	case GL_TEXTURE_WRAP_T:
	case GL_TEXTURE_WRAP_R:
	case GL_TEXTURE_MAX_LEVEL:
    case GL_TEXTURE_BASE_LEVEL:
	case GL_TEXTURE_MIN_LOD:
	case GL_TEXTURE_MAX_LOD:
	case GL_TEXTURE_LOD_BIAS:
	case GL_GENERATE_MIPMAP:
        gl4es_glTexParameteri(target, pname, params[0]);
        return;
    case GL_TEXTURE_BORDER_COLOR:
        // not supported on GLES,
        noerrorShim();
        return;
    }
    PUSH_IF_COMPILING(glTexParameterfv);
    LOAD_GLES(glTexParameterfv);
    errorGL();
    const GLuint rtarget = map_tex_target(target);
    gles_glTexParameterfv(rtarget, pname, params);

}

void gl4es_glTexParameteriv(GLenum target, GLenum pname, const GLint * params) {
    switch (pname) {
	case GL_TEXTURE_MIN_FILTER:
	case GL_TEXTURE_MAG_FILTER:
	case GL_TEXTURE_WRAP_S:
	case GL_TEXTURE_WRAP_T:
	case GL_TEXTURE_WRAP_R:
	case GL_TEXTURE_MAX_LEVEL:
    case GL_TEXTURE_BASE_LEVEL:
	case GL_TEXTURE_MIN_LOD:
	case GL_TEXTURE_MAX_LOD:
	case GL_TEXTURE_LOD_BIAS:
	case GL_GENERATE_MIPMAP:
        gl4es_glTexParameteri(target, pname, params[0]);
        return;
    case GL_TEXTURE_BORDER_COLOR:
        // not supported on GLES,
        noerrorShim();
        return;
    }
    PUSH_IF_COMPILING(glTexParameteriv);
    LOAD_GLES(glTexParameteriv);
    errorGL();
    const GLuint rtarget = map_tex_target(target);
    gles_glTexParameteriv(rtarget, pname, params);
}

void gl4es_glDeleteTextures(GLsizei n, const GLuint *textures) {
    if (glstate->gl_batch || glstate->list.pending) flush();
	noerrorShim();
    LOAD_GLES(glDeleteTextures);
    khash_t(tex) *list = glstate->texture.list;
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
                    for (int j=0; j<ENABLED_TEXTURE_LAST; j++)
                        if (tex == glstate->texture.bound[a][j])
                            glstate->texture.bound[a][j] = NULL;
                }
				gles_glDeleteTextures(1, &tex->glname);
				errorGL();
#ifdef TEXSTREAM
				if (globals4es.texstream && tex->streamed)
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

void gl4es_glGenTextures(GLsizei n, GLuint * textures) {
    if (n<=0) 
		return;
    if (glstate->gl_batch || glstate->list.pending) flush();
    LOAD_GLES(glGenTextures);
    gles_glGenTextures(n, textures);
    errorGL();
    // now, add all the textures to the list
    int ret;
	khint_t k;
	khash_t(tex) *list = glstate->texture.list;
	if (! list) {
		list = glstate->texture.list = kh_init(tex);
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
            tex->mipmap_auto = default_tex_mipmap || (globals4es.automipmap==1);
            tex->mipmap_need = (globals4es.automipmap==1)?1:0;
			tex->streamingID = -1;
            tex->base_level = -1;
            tex->max_level = -1;
			tex->streamed = false;
            tex->alpha = true;
            tex->compressed = false;
			tex->min_filter = tex->mag_filter = (globals4es.automipmap==1)?GL_LINEAR_MIPMAP_LINEAR:GL_LINEAR;
            tex->format = GL_RGBA;
            tex->type = GL_UNSIGNED_BYTE;
            tex->shrink = 0;
			tex->data = NULL;
		} else {
			tex = kh_value(list, k);
			// in case of no delete here...
			if (tex->glname==0)
				tex->glname = tex->texture;
		}
	}
}

GLboolean gl4es_glAreTexturesResident(GLsizei n, const GLuint *textures, GLboolean *residences) {
	noerrorShim();
    return true;
}

void gl4es_glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params) {
    //printf("glGetTexLevelParameteriv(%s, %d, %s, %p)\n", PrintEnum(target), level, PrintEnum(pname), params);
	// simplification: (mostly) not taking "target" into account here
    if (glstate->gl_batch || glstate->list.pending) flush();
	*params = 0;
	noerrorShim();
    const GLuint itarget = what_target(target);
    const GLuint rtarget = map_tex_target(target);
	gltexture_t* bound = glstate->texture.bound[glstate->texture.active][itarget];
	switch (pname) {
		case GL_TEXTURE_WIDTH:
			if (rtarget==GL_PROXY_TEXTURE_2D)
				(*params) = nlevel(proxy_width,level);
			else {
				(*params) = nlevel((bound)?bound->width:2048,level);
                if(level && (!bound || (bound && !(bound->mipmap_auto || bound->mipmap_need))))
                    (*params) = 0;   // Mipmap level not loaded
            }
			break;
		case GL_TEXTURE_HEIGHT: 
			if (rtarget==GL_PROXY_TEXTURE_2D)
				(*params) = nlevel(proxy_height,level);
			else {
				(*params) = nlevel((bound)?bound->height:2048,level); 
                if(level && (!bound || (bound && !(bound->mipmap_auto || bound->mipmap_need))))
                    (*params) = 0;   // Mipmap level not loaded
            }
			break;
		case GL_TEXTURE_INTERNAL_FORMAT:
            if (rtarget==GL_PROXY_TEXTURE_2D)
				(*params) = proxy_intformat;
			else {
                if (bound && bound->compressed)
                    (*params) = bound->internalformat;
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
                int w = nlevel((bound->width>>level),2); //DXT works on 4x4 blocks...
                int h = nlevel((bound->height>>level),2);
                w<<=2; h<<=2;
                if (bound->orig_internal==GL_COMPRESSED_RGB) //DXT1, 64bits (i.e. size=8) for a 4x4 block
                    (*params) = (w*h)/2;
                else    //DXT5, 64+64 (i.e. size = 16) for a 4x4 block
                    (*params) = w*h;
            } else
			 (*params) = (bound)?(bound->width*bound->height*4):0;
			break;
        case GL_TEXTURE_BORDER:
            (*params) = 0;
            break;
        case GL_TEXTURE_INTENSITY_SIZE:
            if(bound)
                (*params) = 32;  // is it correct ? GLES doesn't store Intensity... Shall I return 0 instead? Or fake it and return 8?
            else
                (*params) = 0;
            break;
        case GL_TEXTURE_LUMINANCE_SIZE:
            if(bound)
                (*params) = (bound->orig_internal==GL_LUMINANCE || bound->orig_internal==GL_LUMINANCE_ALPHA)?8:0;
            else
                (*params) = 0;
            break;
            break;
		default:
			errorShim(GL_INVALID_ENUM);	//Wrong here...
			printf("Stubbed glGetTexLevelParameteriv(%s, %i, %s, %p)\n", PrintEnum(target), level, PrintEnum(pname), params);
	}
}

extern GLuint current_fb;   // from framebuffers.c
// hacky viewport temporary changes
void pushViewport(GLint x, GLint y, GLsizei width, GLsizei height);
void popViewport();


void gl4es_glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid * img) {
//printf("glGetTexImage(%s, %i, %s, %s, %p)\n", PrintEnum(target), level, PrintEnum(format), PrintEnum(type), img);
    GLuint old_glbatch = glstate->gl_batch;
    if (glstate->gl_batch || glstate->list.pending) {
        flush();
        glstate->gl_batch = 0;
    }
    const GLuint itarget = what_target(target);    
	if (glstate->texture.bound[glstate->texture.active][itarget]==NULL)
		return;		// no texture bounded...
	gltexture_t* bound = glstate->texture.bound[glstate->texture.active][itarget];
	int width = bound->width;
	int height = bound->height;
	int nwidth = bound->nwidth;
	int nheight = bound->nheight;
    int shrink = bound->shrink;
	if (level != 0) {
		//printf("STUBBED glGetTexImage with level=%i\n", level);
        void* tmp = malloc(width*height*pixel_sizeof(format, type)); // tmp space...
        void* tmp2;
        gl4es_glGetTexImage(map_tex_target(target), 0, format, type, tmp);
        for (int i=0; i<level; i++) {
            pixel_halfscale(tmp, &tmp2, width, height, format, type);
            free(tmp);
            tmp = tmp2;
            width = nlevel(width, 1);
            height = nlevel(height, 1);
        }
        memcpy(img, tmp, width*height*pixel_sizeof(format, type));
        free(tmp);
        if (old_glbatch)
            glstate->gl_batch=old_glbatch;
        return;
	}
	
	if (target!=GL_TEXTURE_2D) {
        if (old_glbatch)
            glstate->gl_batch=old_glbatch;
		return;
    }

    //printf("glGetTexImage(%s, %i, %s, %s, 0x%p), texture=0x%x, size=%i,%i\n", PrintEnum(target), level, PrintEnum(format), PrintEnum(type), img, bound->glname, width, height);
	
	GLvoid *dst = img;
    if (glstate->vao->pack)
        dst += (uintptr_t)glstate->vao->pack->data;
#ifdef TEXSTREAM
    if (globals4es.texstream && bound->streamed) {
        noerrorShim();
        pixel_convert(GetStreamingBuffer(bound->streamingID), &dst, width, height, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, format, type, 0, glstate->texture.unpack_align);
        readfboEnd();
        if (old_glbatch)
            glstate->gl_batch=old_glbatch;
        return;
    }
#endif
    if (globals4es.texcopydata && bound->data) {
        //printf("texcopydata* glGetTexImage(0x%04X, %d, 0x%04x, 0x%04X, %p)\n", target, level, format, type, img);
        noerrorShim();
        if (!pixel_convert(bound->data, &dst, width, height, GL_RGBA, GL_UNSIGNED_BYTE, format, type, 0, glstate->texture.unpack_align))
            printf("LIBGL: Error on pixel_convert while glGetTexImage\n");
	} else {
		// Setup an FBO the same size of the texture
        GLuint oldBind = bound->glname;
        GLuint old_fbo = current_fb;
        GLuint fbo;
	
        // if the texture is not RGBA or RGB or ALPHA, the "just attach texture to the fbo" trick will not work, and a full Blit has to be done
        if((bound->format==GL_RGBA || bound->format==GL_RGB || bound->format==GL_ALPHA) && (shrink==0)) {
            gl4es_glGenFramebuffers(1, &fbo);
            gl4es_glBindFramebuffer(GL_FRAMEBUFFER_OES, fbo);
            gl4es_glFramebufferTexture2D(GL_FRAMEBUFFER_OES, GL_COLOR_ATTACHMENT0_OES, GL_TEXTURE_2D, oldBind, 0);
            // Read the pixels!
            gl4es_glReadPixels(0, nheight-height, width, height, format, type, img);	// using "full" version with conversion of format/type
            gl4es_glBindFramebuffer(GL_FRAMEBUFFER_OES, old_fbo);
            gl4es_glDeleteFramebuffers(1, &fbo);
            noerrorShim();
        } else {
            gl4es_glGenFramebuffers(1, &fbo);
            gl4es_glBindFramebuffer(GL_FRAMEBUFFER_OES, fbo);
            GLuint temptex;
            gl4es_glGenTextures(1, &temptex);
            gl4es_glBindTexture(GL_TEXTURE_2D, temptex);
            gl4es_glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, nwidth<<shrink, nheight<<shrink, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
            gl4es_glFramebufferTexture2D(GL_FRAMEBUFFER_OES, GL_COLOR_ATTACHMENT0_OES, GL_TEXTURE_2D, temptex, 0);
            gl4es_glBindTexture(GL_TEXTURE_2D, oldBind);
            // blit the texture
            // TODO: create a blitTexture function (to be used in raster too)
            LOAD_GLES(glEnableClientState);
            LOAD_GLES(glDisableClientState);
            LOAD_GLES(glVertexPointer);
            LOAD_GLES(glTexCoordPointer);
            LOAD_GLES(glDrawArrays);
            LOAD_GLES(glBindTexture);
            LOAD_GLES(glActiveTexture);
            LOAD_GLES(glClientActiveTexture);
            gl4es_glPushAttrib(GL_TEXTURE_BIT | GL_ENABLE_BIT | GL_TRANSFORM_BIT | GL_COLOR_BUFFER_BIT | GL_CURRENT_BIT);
            GLfloat old_projection[16], old_modelview[16], old_texture[16];

            gl4es_glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            gl4es_glClear(GL_COLOR_BUFFER_BIT);

            GLuint old_tex = glstate->texture.active;
            if (old_tex!=0) gles_glActiveTexture(GL_TEXTURE0);
            GLuint old_cli = glstate->texture.client;
            if (old_cli!=0) gles_glClientActiveTexture(GL_TEXTURE0);
            gl4es_glGetFloatv(GL_TEXTURE_MATRIX, old_texture);
            gl4es_glGetFloatv(GL_PROJECTION_MATRIX, old_projection);
            gl4es_glGetFloatv(GL_MODELVIEW_MATRIX, old_modelview);
            gl4es_glMatrixMode(GL_TEXTURE);
            gl4es_glLoadIdentity();
            gl4es_glMatrixMode(GL_PROJECTION);
            gl4es_glLoadIdentity();
            gl4es_glMatrixMode(GL_MODELVIEW);
            gl4es_glLoadIdentity();

            pushViewport(0,0,nwidth<<shrink, nheight<<shrink);
            float w2 = 2.0f / nwidth;
            float h2 = 2.0f / nheight;
            float blit_x1=0;
            float blit_x2=width;
            float blit_y1=0;
            float blit_y2=height;
            GLfloat blit_vert[] = {
                blit_x1*w2-1.0f, blit_y1*h2-1.0f,
                blit_x2*w2-1.0f, blit_y1*h2-1.0f,
                blit_x2*w2-1.0f, blit_y2*h2-1.0f,
                blit_x1*w2-1.0f, blit_y2*h2-1.0f
            };
            GLfloat rw = ((GLfloat)width)/nwidth;
            GLfloat rh = ((GLfloat)height)/nheight;
            GLfloat blit_tex[] = {
                0,  0,
                rw, 0,
                rw, rh,
                0,  rh
            };

            gl4es_glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT | GL_CLIENT_PIXEL_STORE_BIT);

            gl4es_glDisable(GL_DEPTH_TEST);
            gl4es_glDisable(GL_LIGHTING);
            gl4es_glDisable(GL_CULL_FACE);
            gl4es_glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

            gl4es_glEnable(GL_TEXTURE_2D);
            gles_glBindTexture(GL_TEXTURE_2D, oldBind);
            gl4es_glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

            if(!glstate->clientstate.vertex_array) 
            {
                gles_glEnableClientState(GL_VERTEX_ARRAY);
                glstate->clientstate.vertex_array = 1;
            }
            gles_glVertexPointer(2, GL_FLOAT, 0, blit_vert);
            if(!glstate->clientstate.tex_coord_array[0]) 
            {
                gles_glEnableClientState(GL_TEXTURE_COORD_ARRAY);
                glstate->clientstate.tex_coord_array[0] = 1;
            }
            gles_glTexCoordPointer(2, GL_FLOAT, 0, blit_tex);
            for (int a=1; a <MAX_TEX; a++)
                if(glstate->clientstate.tex_coord_array[a]) {
                    gles_glClientActiveTexture(GL_TEXTURE0 + a);
                    gles_glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                    glstate->clientstate.tex_coord_array[a] = 0;
                    gles_glClientActiveTexture(GL_TEXTURE0);
                }
            if(glstate->clientstate.color_array) {
                gles_glDisableClientState(GL_COLOR_ARRAY);
                glstate->clientstate.color_array = 0;
            }
            if(glstate->clientstate.normal_array) {
                gles_glDisableClientState(GL_NORMAL_ARRAY);
                glstate->clientstate.normal_array = 0;
            }
            gles_glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
            // All the previous states are Pushed / Poped anyway...
            if (old_tex!=0) gles_glActiveTexture(GL_TEXTURE0+old_tex);
            if (old_cli!=0) gles_glClientActiveTexture(GL_TEXTURE0+old_cli);
            gl4es_glPopClientAttrib();
            gl4es_glMatrixMode(GL_TEXTURE);
            gl4es_glLoadMatrixf(old_texture);
            gl4es_glMatrixMode(GL_MODELVIEW);
            gl4es_glLoadMatrixf(old_modelview);
            gl4es_glMatrixMode(GL_PROJECTION);
            gl4es_glLoadMatrixf(old_projection);
            gl4es_glPopAttrib();
            // Read the pixels!
            gl4es_glReadPixels(0, (nheight-height)<<shrink, width<<shrink, height<<shrink, format, type, img);	// using "full" version with conversion of format/type
            gl4es_glBindFramebuffer(GL_FRAMEBUFFER_OES, old_fbo);
            gl4es_glDeleteFramebuffers(1, &fbo);
            gl4es_glDeleteTextures(1, &temptex);
            popViewport();
            noerrorShim();
        }
	}
    if (old_glbatch)
        glstate->gl_batch=old_glbatch;
}

void gl4es_glActiveTexture( GLenum texture ) {
 if (glstate->list.pending) flush();
 if (glstate->list.active && (glstate->gl_batch && !glstate->list.compiling))  {
    if (glstate->statebatch.active_tex_changed) {
        if(glstate->statebatch.active_tex == texture)
            return; // nothing to do...
        flush();
    }
    glstate->statebatch.active_tex = texture;
    glstate->statebatch.active_tex_changed = 1;
 }
 if (glstate->list.active) {
     NewStage(glstate->list.active, STAGE_ACTIVETEX);
     rlActiveTexture(glstate->list.active, texture);
     return;
 }
 
 if ((texture < GL_TEXTURE0) || (texture >= GL_TEXTURE0+MAX_TEX)) {
    errorShim(GL_INVALID_ENUM);
   return;
 }
 glstate->texture.active = texture - GL_TEXTURE0;
 LOAD_GLES(glActiveTexture);
 gles_glActiveTexture(texture);
 errorGL();
}

void gl4es_glClientActiveTexture( GLenum texture ) {
 if ((texture < GL_TEXTURE0) || (texture >= GL_TEXTURE0+MAX_TEX)) {
	 errorShim(GL_INVALID_ENUM);
   return;
 }
 // try to speed-up things...
 if (glstate->texture.client == (texture - GL_TEXTURE0))
    return;
 if (glstate->gl_batch || glstate->list.pending) flush();
 glstate->texture.client = texture - GL_TEXTURE0;
 LOAD_GLES(glClientActiveTexture);
 gles_glClientActiveTexture(texture);
 errorGL();
}
void gl4es_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * data) {
    //printf("glReadPixels(%i, %i, %i, %i, %s, %s, 0x%p)\n", x, y, width, height, PrintEnum(format), PrintEnum(type), data);
    GLuint old_glbatch = glstate->gl_batch;
    if (glstate->gl_batch || glstate->list.pending) {
        flush();
        glstate->gl_batch = 0;
    }
    if (glstate->list.compiling && glstate->list.active) {
		errorShim(GL_INVALID_OPERATION);
        glstate->gl_batch = old_glbatch;
        return;	// never in list
	}
    LOAD_GLES(glReadPixels);
    errorGL();
    GLvoid* dst = data;
    if (glstate->vao->pack)
		dst += (uintptr_t)glstate->vao->pack->data;
		
	readfboBegin();
    if ((format == GL_RGBA && type == GL_UNSIGNED_BYTE)     // should not use default GL_RGBA on Pandora as it's very slow...
       || (format == hardext.readf && type == hardext.readt)    // use the IMPLEMENTATION_READ too...
       || (format == GL_DEPTH_COMPONENT && type == GL_FLOAT))   // this one will probably fail, as DEPTH is not readable on most GLES hardware 
    {
        // easy passthru
        gles_glReadPixels(x, y, width, height, format, type, dst);
        readfboEnd();
        glstate->gl_batch = old_glbatch;
        return;
    }
    // grab data in GL_RGBA format
    int use_bgra = 0;
    if(hardext.readf==GL_BGRA && hardext.readt==GL_UNSIGNED_BYTE)
        use_bgra = 1;   // if IMPLEMENTATION_READ is BGRA, then use it as it's probably faster then RGBA.
    GLvoid *pixels = malloc(width*height*4);
    gles_glReadPixels(x, y, width, height, use_bgra?GL_BGRA:GL_RGBA, GL_UNSIGNED_BYTE, pixels);
    if (! pixel_convert(pixels, &dst, width, height,
					    use_bgra?GL_BGRA:GL_RGBA, GL_UNSIGNED_BYTE, format, type, 0,glstate->texture.unpack_align)) {
        LOGE("LIBGL: ReadPixels error: (%s, UNSIGNED_BYTE -> %s, %s )\n",
            PrintEnum(use_bgra?GL_BGRA:GL_RGBA), PrintEnum(format), PrintEnum(type));
    }
    free(pixels);
    readfboEnd();
    glstate->gl_batch = old_glbatch;
    return;
}

void gl4es_glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset,
                                GLint x, GLint y, GLsizei width, GLsizei height) {
    //printf("glCopyTexSubImage2D(%s, %i, %i, %i, %i, %i, %i, %i), bounded texture=%u format/type=%s, %s\n", PrintEnum(target), level, xoffset, yoffset, x, y, width, height, (glstate->texture.bound[glstate->texture.active])?glstate->texture.bound[glstate->texture.active]->texture:0, PrintEnum((glstate->texture.bound[glstate->texture.active])?glstate->texture.bound[glstate->texture.active]->format:0), PrintEnum((glstate->texture.bound[glstate->texture.active])?glstate->texture.bound[glstate->texture.active]->type:0));
    // PUSH_IF_COMPILING(glCopyTexSubImage2D);
    GLuint old_glbatch = glstate->gl_batch;
    if (glstate->gl_batch || glstate->list.pending) {
        flush();
        glstate->gl_batch = 0;
    }
 
    LOAD_GLES(glCopyTexSubImage2D);
    errorGL();

    // "Unmap" if buffer mapped...
    glbuffer_t *pack = glstate->vao->pack;
    glbuffer_t *unpack = glstate->vao->unpack;
    glstate->vao->pack = NULL;
    glstate->vao->unpack = NULL;

    const GLuint itarget = what_target(target);
 
    gltexture_t* bound = glstate->texture.bound[glstate->texture.active][itarget];
    if (!bound) {
        errorShim(GL_INVALID_OPERATION);
        glstate->gl_batch = old_glbatch;
        return;
    }
#ifdef TEXSTREAM
    if (bound && bound->streamed) {
        void* buff = GetStreamingBuffer(bound->streamingID);
        if ((bound->width == width) && (bound->height == height) && (xoffset == yoffset == 0)) {
            gl4es_glReadPixels(x, y, width, height, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, buff);
        } else {
            void* tmp = malloc(width*height*2);
            gl4es_glReadPixels(x, y, width, height, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, tmp);
            for (int y=0; y<height; y++) {
                memcpy(buff+((yoffset+y)*bound->width+xoffset)*2, tmp+y*width*2, width*2);
            }
            free(tmp);
        }
    } else 
#endif
    {
        if (globals4es.copytex) {
            gles_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
        } else {
            void* tmp = malloc(width*height*4);
            GLenum format = (bound)?bound->format:GL_RGBA;
            GLenum type = (bound)?bound->type:GL_UNSIGNED_BYTE;
            gl4es_glReadPixels(x, y, width, height, format, type, tmp);
            gl4es_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, tmp);
            free(tmp);
        }
    }
    // "Remap" if buffer mapped...
    glstate->vao->pack = pack;
    glstate->vao->unpack = unpack;
    glstate->gl_batch = old_glbatch;
}


void gl4es_glCopyTexImage2D(GLenum target,  GLint level,  GLenum internalformat,  GLint x,  GLint y,  
								GLsizei width,  GLsizei height,  GLint border) {
     //printf("glCopyTexImage2D(0x%04X, %i, 0x%04X, %i, %i, %i, %i, %i), current_fb=%u\n", target, level, internalformat, x, y, width, height, border, current_fb);
     //PUSH_IF_COMPILING(glCopyTexImage2D);
     GLuint old_glbatch = glstate->gl_batch;
     if (glstate->gl_batch || glstate->list.pending) {
         flush();
         glstate->gl_batch = 0;
     }

     errorGL();

     // "Unmap" if buffer mapped...
     glbuffer_t *pack = glstate->vao->pack;
     glbuffer_t *unpack = glstate->vao->unpack;
     glstate->vao->pack = NULL;
     glstate->vao->unpack = NULL;
    
    if (globals4es.copytex) {
        LOAD_GLES(glCopyTexImage2D);
        gles_glCopyTexImage2D(target, level, GL_RGB, x, y, width, height, border);
    } else {
        void* tmp = malloc(width*height*4);
        gl4es_glReadPixels(x, y, width, height, GL_RGBA, GL_UNSIGNED_BYTE, tmp);
        gl4es_glTexImage2D(target, level, internalformat, width, height, border, GL_RGBA, GL_UNSIGNED_BYTE, tmp);
        free(tmp);
    }
    
     // "Remap" if buffer mapped...
     glstate->vao->pack = pack;
     glstate->vao->unpack = unpack;
     
     glstate->gl_batch = old_glbatch;
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

void gl4es_glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat,
							GLsizei width, GLsizei height, GLint border,
							GLsizei imageSize, const GLvoid *data) 
{
    const GLuint itarget = what_target(target);
    const GLuint rtarget = map_tex_target(target);
    if (target == GL_PROXY_TEXTURE_2D) {
        proxy_width = (width>2048)?0:width;
        proxy_height = (height>2048)?0:height;
        return;
    }
     GLuint old_glbatch = glstate->gl_batch;
     if (glstate->gl_batch || glstate->list.pending) {
         flush();
         glstate->gl_batch = 0;
     }

    gltexture_t* bound = glstate->texture.bound[glstate->texture.active][itarget]; 
    if (bound==NULL) {
		errorShim(GL_INVALID_OPERATION);
	    return;		// no texture bounded...
	}
    //printf("glCompressedTexImage2D on target=%s with size(%i,%i), internalformat=%s, imagesize=%i, upackbuffer=%p data=%p\n", PrintEnum(target), width, height, PrintEnum(internalformat), imageSize, glstate->vao->unpack?glstate->vao->unpack->data:0, data);
    // hack...
    if (internalformat==GL_RGBA8)
        internalformat = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
    // test if internalformat is not a compressed one
    if ((width<=0) || (height<=0)) {
        noerrorShim();
        return; // nothing to do...
    }
    LOAD_GLES(glCompressedTexImage2D);
    errorGL();
    
    glbuffer_t *unpack = glstate->vao->unpack;
    glstate->vao->unpack = NULL;
    GLvoid *datab = (GLvoid*)data;
    if (unpack)
		datab += (uintptr_t)unpack->data;
    
    GLenum format = GL_RGBA;
    GLenum type = GL_UNSIGNED_BYTE;
        
    if (isDXTc(internalformat)) {
		GLvoid *pixels, *half;
        int fact = 0;
        pixels = half = NULL;
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
            // if RGBA / DXT1, then RGB 000 needs to have 0 alpha too
            if(internalformat==GL_COMPRESSED_RGBA_S3TC_DXT1_EXT) {
                GLuint *p = (GLuint*)pixels;
                for(int i=0; i<width*height; i++, p++)
                    if(*p==0xff000000) *p=0;
            }
            // automaticaly reduce the pixel size
            half=pixels;
            bound->alpha = (internalformat==GL_COMPRESSED_RGB_S3TC_DXT1_EXT)?false:true;
            if(globals4es.nodownsampling==1) {  // will be removed soon, avoid16bits is better
                format = GL_RGBA;
                type = GL_UNSIGNED_BYTE;
            } else {
                if(globals4es.avoid16bits) {
                    format = GL_RGBA;
                    type = GL_UNSIGNED_BYTE;
                } else {
                    format = (internalformat==GL_COMPRESSED_RGB_S3TC_DXT1_EXT)?GL_RGB:GL_RGBA;
#ifdef PANDORA
                    type = (internalformat==GL_COMPRESSED_RGB_S3TC_DXT1_EXT)?GL_UNSIGNED_SHORT_5_6_5:(internalformat==GL_COMPRESSED_RGBA_S3TC_DXT1_EXT)?GL_UNSIGNED_SHORT_5_5_5_1:GL_UNSIGNED_SHORT_4_4_4_4;
#else
                    type = (internalformat==GL_COMPRESSED_RGB_S3TC_DXT1_EXT)?GL_UNSIGNED_SHORT_5_6_5:GL_UNSIGNED_SHORT_4_4_4_4;
#endif
                    if (pixel_convert(pixels, &half, width, height, GL_RGBA, GL_UNSIGNED_BYTE, format, type, 0, glstate->texture.pack_align))
                        fact = 0;
                    else {
                        format = GL_RGBA;
                        type = GL_UNSIGNED_BYTE;
                    }
                }
            }
            bound->format = format; //internalformat;
            bound->type = type;
            bound->compressed = true;
            bound->internalformat = internalformat;
        } else {
            fact = 0;
        }
		int oldalign;
		gl4es_glGetIntegerv(GL_UNPACK_ALIGNMENT, &oldalign);
		if (oldalign!=1) 
            gl4es_glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		gl4es_glTexImage2D(rtarget, level, format==GL_RGBA?GL_COMPRESSED_RGBA:GL_COMPRESSED_RGB, nlevel(width,fact), nlevel(height,fact), border, format, type, half);
        // re-update bounded texture info
        bound->compressed = true;
        bound->internalformat = internalformat;
		if (oldalign!=1) 
            gl4es_glPixelStorei(GL_UNPACK_ALIGNMENT, oldalign);
		if (half!=pixels)
			free(half);
		if (pixels!=datab)
			free(pixels);
	} else {
	    bound->alpha = true;
        bound->format = internalformat;
        bound->type = GL_UNSIGNED_BYTE;
        bound->internalformat = internalformat;
        bound->compressed = true;
	    gles_glCompressedTexImage2D(rtarget, level, internalformat, width, height, border, imageSize, datab);
	}
	glstate->vao->unpack = unpack;
    glstate->gl_batch = old_glbatch;
}

void gl4es_glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset,
							   GLsizei width, GLsizei height, GLenum format, 
							   GLsizei imageSize, const GLvoid *data) 
{
    const GLuint itarget = what_target(target);
    const GLuint old_glbatch = glstate->gl_batch;
    if (glstate->gl_batch || glstate->list.pending) {
        flush();
        glstate->gl_batch = 0;
    }
    gltexture_t *bound = glstate->texture.bound[glstate->texture.active][itarget];
	if (bound==NULL) {
		errorShim(GL_INVALID_OPERATION);
        glstate->gl_batch = old_glbatch;
		return;		// no texture bounded...
	}
	if (level != 0) {
		noerrorShim();
		//TODO
		//printf("STUBBED glCompressedTexSubImage2D with level=%i\n", level);
        glstate->gl_batch = old_glbatch;
		return;
	}
    //printf("glCompressedTexSubImage2D with unpack_row_length(%i), size(%i,%i), pos(%i,%i) and skip={%i,%i}, internalformat=%s, imagesize=%i, data=%p\n", glstate->texture.unpack_row_length, width, height, xoffset, yoffset, glstate->texture.unpack_skip_pixels, glstate->texture.unpack_skip_rows, PrintEnum(format), imageSize, data);
    glbuffer_t *unpack = glstate->vao->unpack;
    glstate->vao->unpack = NULL;
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
		#if 0
		pixel_thirdscale(pixels, &half, width, height, GL_RGBA, GL_UNSIGNED_BYTE);
		int oldalign;
		gl4es_glGetIntegerv(GL_UNPACK_ALIGNMENT, &oldalign);
		if (oldalign!=1) gl4es_glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		gl4es_glTexSubImage2D(target, level, xoffset/2, yoffset/2, width/2, height/2, GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4, half);
		if (oldalign!=1) gl4es_glPixelStorei(GL_UNPACK_ALIGNMENT, oldalign);
		#else
        GLenum format = bound->format;
        GLenum type = bound->type;
		pixel_convert(pixels, &half, width, height, GL_RGBA, GL_UNSIGNED_BYTE, format, type, 0, glstate->texture.pack_align);
		gl4es_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, half);
		#endif
		if (half!=pixels)
			free(half);
		if (pixels!=datab)
			free(pixels);
	} else {
		gles_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, datab);
	}
    glstate->gl_batch = old_glbatch;
}

void gl4es_glGetCompressedTexImage(GLenum target, GLint lod, GLvoid *img) {
    if (glstate->gl_batch || glstate->list.pending) flush();

    const GLuint itarget = what_target(target); 
    gltexture_t* bound = glstate->texture.bound[glstate->texture.active][itarget];
    //printf("glGetCompressedTexImage(%s, %i, %p), bound=%p, bound->orig_internal=%s\n", PrintEnum(target), lod, img, bound, (bound)?PrintEnum(bound->orig_internal):"nil");
    errorShim(GL_INVALID_OPERATION);
    if(!bound)
        return;
    if(bound->orig_internal!=GL_COMPRESSED_RGB && bound->orig_internal!=GL_COMPRESSED_RGBA)
        return;
    int width = nlevel(bound->width,lod);
    int height = nlevel(bound->height,lod);
    int w = nlevel(width,2); w<<=2;
    int h = nlevel(height,2); h<<=2;

    int alpha = (bound->orig_internal==GL_COMPRESSED_RGBA)?1:0;

    glbuffer_t *unpack = glstate->vao->unpack;
    glbuffer_t *pack = glstate->vao->pack;
    glstate->vao->unpack = NULL;
    glstate->vao->pack = NULL;
    GLvoid *datab = (GLvoid*)img;
    if (pack)
        datab += (uintptr_t)pack->data;

    // alloc the memory for source image and grab the file
    GLuint *src = (GLuint*)malloc(width*height*4);
    gl4es_glGetTexImage(target, lod, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*)src);
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

    glstate->vao->unpack = unpack;
    glstate->vao->pack = pack;
    noerrorShim();
    return;
}

void gl4es_glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat,
							GLsizei width, GLint border,
							GLsizei imageSize, const GLvoid *data) {
                                
    gl4es_glCompressedTexImage2D(target, level, internalformat, width, 1, border, imageSize, data);
}

void gl4es_glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat,
							GLsizei width, GLsizei height, GLsizei depth, GLint border,
							GLsizei imageSize, const GLvoid *data) {
                                
    gl4es_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
}

void gl4es_glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset,
							   GLsizei width, GLenum format, 
							   GLsizei imageSize, const GLvoid *data) {

    gl4es_glCompressedTexSubImage2D(target, level, xoffset, 0, width, 1, format, imageSize, data);
}
void gl4es_glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,
							   GLsizei width, GLsizei height, GLsizei depth, GLenum format, 
							   GLsizei imageSize, const GLvoid *data) {

    gl4es_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}


void gl4es_glTexEnvf(GLenum target, GLenum pname, GLfloat param) {
    LOAD_GLES(glTexEnvf);
    PUSH_IF_COMPILING(glTexEnvf);

    if(target==GL_POINT_SPRITE && pname==GL_COORD_REPLACE)
        glstate->texture.pscoordreplace[glstate->texture.active] = (param!=0.0f)?1:0;
    gles_glTexEnvf(target, pname, param);
}
void gl4es_glTexEnvi(GLenum target, GLenum pname, GLint param) {
    LOAD_GLES(glTexEnvi);
    PUSH_IF_COMPILING(glTexEnvi);
    if(target==GL_POINT_SPRITE && pname==GL_COORD_REPLACE)
        glstate->texture.pscoordreplace[glstate->texture.active] = (param!=0)?1:0;
    gles_glTexEnvi(target, pname, param);
}
void gl4es_glTexEnvfv(GLenum target, GLenum pname, const GLfloat *param) {
    if ((glstate->list.compiling || glstate->gl_batch) && glstate->list.active) {
		NewStage(glstate->list.active, STAGE_TEXENV);
		rlTexEnvfv(glstate->list.active, target, pname, param);
        noerrorShim();
		return;
	}
    LOAD_GLES(glTexEnvfv);
    gles_glTexEnvfv(target, pname, param);
}
void gl4es_glTexEnviv(GLenum target, GLenum pname, const GLint *param) {
    if (glstate->list.pending) flush();
    if ((glstate->list.compiling || glstate->gl_batch) && glstate->list.active) {
		NewStage(glstate->list.active, STAGE_TEXENV);
		rlTexEnviv(glstate->list.active, target, pname, param);
        noerrorShim();
		return;
	}
    LOAD_GLES(glTexEnviv);
    gles_glTexEnviv(target, pname, param);
}
void gl4es_glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params) {
    LOAD_GLES(glGetTexEnvfv);
    if (glstate->list.pending) flush();
    if (glstate->list.active && (glstate->gl_batch && !glstate->list.compiling)) flush();
    if(target==GL_POINT_SPRITE && pname==GL_COORD_REPLACE)
        *params = glstate->texture.pscoordreplace[glstate->texture.active];
    else
        gles_glGetTexEnvfv(target, pname, params);

}
void gl4es_glGetTexEnviv(GLenum target, GLenum pname, GLint * params) {
    LOAD_GLES(glGetTexEnviv);
    if (glstate->list.pending) flush();
    if (glstate->list.active && (glstate->gl_batch && !glstate->list.compiling)) flush();
    if(target==GL_POINT_SPRITE && pname==GL_COORD_REPLACE)
        *params = glstate->texture.pscoordreplace[glstate->texture.active];
    else
        gles_glGetTexEnviv(target, pname, params);
}


//Direct wrapper
void glTexImage2D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *data) AliasExport("gl4es_glTexImage2D");
void glTexImage1D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *data) AliasExport("gl4es_glTexImage1D");
void glTexImage3D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *data) AliasExport("gl4es_glTexImage3D");
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *data) AliasExport("gl4es_glTexSubImage2D");
void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *data) AliasExport("gl4es_glTexSubImage1D");
void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,  GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *data) AliasExport("gl4es_glTexSubImage3D");
void glBindTexture(GLenum target, GLuint texture) AliasExport("gl4es_glBindTexture");
void glGenTextures(GLsizei n, GLuint * textures) AliasExport("gl4es_glGenTextures");
void glDeleteTextures(GLsizei n, const GLuint * textures) AliasExport("gl4es_glDeleteTextures");
void glTexParameteri(GLenum target, GLenum pname, GLint param) AliasExport("gl4es_glTexParameteri");
void glTexParameterf(GLenum target, GLenum pname, GLfloat param) AliasExport("gl4es_glTexParameterf");
void glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params) AliasExport("gl4es_glTexParameterfv");
void glTexParameteriv(GLenum target, GLenum pname, const GLint * params) AliasExport("gl4es_glTexParameteriv");
GLboolean glAreTexturesResident(GLsizei n, const GLuint *textures, GLboolean *residences) AliasExport("gl4es_glAreTexturesResident");
void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params) AliasExport("gl4es_glGetTexLevelParameteriv");
void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid * img) AliasExport("gl4es_glGetTexImage");
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * data) AliasExport("gl4es_glReadPixels");
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexImage2D");
void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexImage1D");
void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexImage3D");
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexSubImage2D");
void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexSubImage1D");
void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexSubImage3D");
void glGetCompressedTexImage(GLenum target, GLint lod, GLvoid *img) AliasExport("gl4es_glGetCompressedTexImage");
void glCopyTexImage1D(GLenum target,  GLint level,  GLenum internalformat,  GLint x,  GLint y, GLsizei width,  GLint border) AliasExport("gl4es_glCopyTexImage1D");
void glCopyTexImage2D(GLenum target,  GLint level,  GLenum internalformat,  GLint x,  GLint y, GLsizei width,  GLsizei height,  GLint border) AliasExport("gl4es_glCopyTexImage2D");
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) AliasExport("gl4es_glCopyTexSubImage2D");
void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) AliasExport("gl4es_glCopyTexSubImage1D");
void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) AliasExport("gl4es_glCopyTexSubImage3D");
void glActiveTexture( GLenum texture ) AliasExport("gl4es_glActiveTexture");
void glClientActiveTexture( GLenum texture ) AliasExport("gl4es_glClientActiveTexture");
GLboolean glIsTexture( GLuint texture ) AliasExport("gl4es_glIsTexture");
void glPixelStorei(GLenum pname, GLint param) AliasExport("gl4es_glPixelStorei");
void glTexEnvf(GLenum target, GLenum pname, GLfloat param) AliasExport("gl4es_glTexEnvf");
void glTexEnvi(GLenum target, GLenum pname, GLint param) AliasExport("gl4es_glTexEnvi");
void glTexEnvfv(GLenum target, GLenum pname, const GLfloat *param) AliasExport("gl4es_glTexEnvfv");
void glTexEnviv(GLenum target, GLenum pname, const GLint *param) AliasExport("gl4es_glTexEnviv");
void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params) AliasExport("gl4es_glGetTexEnvfv");
void glGetTexEnviv(GLenum target, GLenum pname, GLint * params) AliasExport("gl4es_glGetTexEnviv");

//EXT mapper
void glTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,  GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *data) AliasExport("gl4es_glTexSubImage3D");
void glCompressedTexImage2DEXT(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexImage2D");
void glCompressedTexImage1DEXT(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexImage1D");
void glCompressedTexImage3DEXT(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexImage3D");
void glCompressedTexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexSubImage2D");
void glCompressedTexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexSubImage1D");
void glCompressedTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexSubImage3D");
void glGetCompressedTexImageEXT(GLenum target, GLint lod, GLvoid *img) AliasExport("gl4es_glGetCompressedTexImage");
void glCopyTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) AliasExport("gl4es_glCopyTexSubImage3D");

//ARB mapper
void glActiveTextureARB(GLenum texture) AliasExport("gl4es_glActiveTexture");
void glClientActiveTextureARB(GLenum texture) AliasExport("gl4es_glClientActiveTexture");
void glTexSubImage3DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset,  GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const GLvoid *data) AliasExport("gl4es_glTexSubImage3D");
void glCompressedTexImage2DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexImage2D");
void glCompressedTexImage1DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexImage1D");
void glCompressedTexImage3DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexImage3D");
void glCompressedTexSubImage2DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexSubImage2D");
void glCompressedTexSubImage1DARB(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexSubImage1D");
void glCompressedTexSubImage3DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexSubImage3D");
void glGetCompressedTexImageARB(GLenum target, GLint lod, GLvoid *img) AliasExport("gl4es_glGetCompressedTexImage");
void glCopyTexSubImage3DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) AliasExport("gl4es_glCopyTexSubImage3D");