#include "texture.h"

#include "../glx/hardext.h"
#include "../glx/streaming.h"
#include "array.h"
#include "blit.h"
#include "decompress.h"
#include "debug.h"
#include "enum_info.h"
#include "fpe.h"
#include "framebuffers.h"
#include "gles.h"
#include "init.h"
#include "loader.h"
#include "matrix.h"
#include "pixel.h"
#include "raster.h"
#include "stb_dxt_104.h"

KHASH_MAP_IMPL_INT(tex, gltexture_t *);

//#define DEBUG
#ifdef DEBUG
#define DBG(a) a
#else
#define DBG(a)
#endif

#ifndef GL_TEXTURE_STREAM_IMG  
#define GL_TEXTURE_STREAM_IMG                                   0x8C0D     
#endif
#ifdef TEXSTREAM
#include <EGL/egl.h>
#include <EGL/eglext.h>
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
    if(size) {
        size>>=level;
        if(!size) size=1;
    }
    return size;
}

// conversions for GL_ARB_texture_rectangle
void tex_coord_rect_arb(GLfloat *tex, int stride, GLsizei len,
                        GLsizei width, GLsizei height) {
    if (!tex || !width || !height)
        return;
        
    GLfloat iwidth, iheight;
    iwidth = 1.0f/width;
    iheight = 1.0f/height;
    if(!stride) stride=4;

    for (int i = 0; i < len; i++) {
        tex[0] *= iwidth;
        tex[1] *= iheight;
        tex += stride;
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
    if (!tex || !len || !mat || hardext.esversion!=1)
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
int inline tex_setup_needchange(GLuint itarget) {
    if(hardext.esversion>1) return 0; // no text ajustement on ES2

    GLuint texunit = glstate->texture.client;
    gltexture_t *bound = glstate->texture.bound[texunit][itarget];
    
    // check if some changes are needed
    if ((itarget == ENABLED_TEXTURE_RECTANGLE) 
        || (hardext.esversion==1 && bound->adjust)
        || (hardext.esversion==1 && !globals4es.texmat && !glstate->texture_matrix[texunit]->identity)
        )
        return 1;
    return 0;
}
void tex_setup_texcoord(GLuint len, int changes, GLuint itarget, pointer_state_t* ptr) {
    LOAD_GLES_FPE(glTexCoordPointer);
    GLuint texunit = glstate->texture.client;
    
    static void * tex[MAX_TEX] = {0};
    static int texlen[MAX_TEX] = {0};
    
    gltexture_t *bound = glstate->texture.bound[texunit][itarget];
    
    if (changes) {
        // first convert to GLfloat, without normalization
        if(texlen[texunit]<len) {
            if(tex[texunit]) free(tex[texunit]);
            tex[texunit] = malloc(4*sizeof(GLfloat)*len);
            texlen[texunit] = len;
        }
        copy_gl_pointer_tex_noalloc(tex[texunit], ptr, 4, 0, len);
        // Normalize if needed
        if (itarget == ENABLED_TEXTURE_RECTANGLE)
            tex_coord_rect_arb(tex[texunit], 4, len, bound->width, bound->height);
        // Apply transformation matrix if any
        if (!(globals4es.texmat || glstate->texture_matrix[texunit]->identity))
            tex_coord_matrix(tex[texunit], len, getTexMat(texunit));
        // NPOT adjust
        if (bound->adjust)
            tex_coord_npot(tex[texunit], len, bound->width, bound->height, bound->nwidth, bound->nheight);
        // All done, setup the texcoord array now
        gles_glTexCoordPointer(4, GL_FLOAT, 0, tex[texunit]);
    } else {
        gles_glTexCoordPointer(ptr->size, ptr->type, ptr->stride, ptr->pointer);
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
        case GL_RED:
            if(!hardext.rgtex) {
                *format = GL_RGB;
                *type = GL_UNSIGNED_BYTE;
            } else {
                *format = GL_RED;
                *type = GL_UNSIGNED_BYTE;
            }
            break;
        case GL_RG:
            if(!hardext.rgtex) {
                *format = GL_RGB;
                *type = GL_UNSIGNED_BYTE;
            } else {
                *format = GL_RG;
                *type = GL_UNSIGNED_BYTE;
            }
            break;
        case GL_COMPRESSED_ALPHA:
        case GL_ALPHA:
            *format = GL_ALPHA;
            *type = GL_UNSIGNED_BYTE;
            break;
        case 1:
        case GL_COMPRESSED_LUMINANCE:
        case GL_LUMINANCE:
            *format = GL_LUMINANCE;
            *type = GL_UNSIGNED_BYTE;
            break;
        case 2:
        case GL_COMPRESSED_LUMINANCE_ALPHA:
        case GL_LUMINANCE8_ALPHA8:
        case GL_LUMINANCE_ALPHA:
            if(globals4es.nolumalpha) {
                *format = GL_RGBA;
                *type = GL_UNSIGNED_BYTE;
            } else {
                *format = GL_LUMINANCE_ALPHA;
                *type = GL_UNSIGNED_BYTE;
            }
            break;
        case GL_RGB5:
        case GL_RGB565:
            *format = GL_RGB;
            *type = GL_UNSIGNED_SHORT_5_6_5;
            break;
        case GL_RGB:
            if(globals4es.avoid24bits)
                *format = GL_RGBA;
            else
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
            if(hardext.bgra8888)
                *format = GL_BGRA;
            else
                *format = GL_RGBA;
            *type = GL_UNSIGNED_BYTE;
            break;
        case GL_DEPTH_COMPONENT:
            *format = GL_DEPTH_COMPONENT;
            *type = GL_UNSIGNED_SHORT;
            break;
        case GL_DEPTH_STENCIL:
        case GL_DEPTH24_STENCIL8:
            *format = GL_DEPTH_STENCIL;
            *type = GL_UNSIGNED_INT_24_8;
            break;
        case GL_RGBA16F:
            *format = GL_RGBA;
            *type = (hardext.halffloattex)?GL_HALF_FLOAT_OES:GL_UNSIGNED_BYTE;
            break;
        case GL_RGBA32F:
            *format = GL_RGBA;
            *type = (hardext.floattex)?GL_FLOAT:GL_UNSIGNED_BYTE;
            break;
        case GL_RGB16F:
            *format = GL_RGB;
            *type = (hardext.halffloattex)?GL_HALF_FLOAT_OES:GL_UNSIGNED_BYTE;
            break;
        case GL_RGB32F:
            *format = GL_RGB;
            *type = (hardext.floattex)?GL_FLOAT:GL_UNSIGNED_BYTE;
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
                             const GLvoid *data, gltexture_t *bound) {
    bool convert = false;
    GLenum dest_format = GL_RGBA;
    GLenum dest_type = GL_UNSIGNED_BYTE;
    // compressed format are not handled here, so mask them....
    if (is_fake_compressed_rgb(intermediaryformat)) intermediaryformat=GL_RGB;
    if (is_fake_compressed_rgba(intermediaryformat)) intermediaryformat=GL_RGBA;
    if (is_fake_compressed_rgb(internalformat)) internalformat=GL_RGB;
    if (is_fake_compressed_rgba(internalformat)) internalformat=GL_RGBA;
    if (intermediaryformat==GL_COMPRESSED_LUMINANCE) intermediaryformat=GL_LUMINANCE;
    if (internalformat==GL_COMPRESSED_LUMINANCE) internalformat=GL_LUMINANCE;

    if(*format != intermediaryformat || intermediaryformat!=internalformat) {
        internal2format_type(intermediaryformat, &dest_format, &dest_type);
        convert = true;
    } else {
        if((*type)==GL_HALF_FLOAT) (*type) = GL_HALF_FLOAT_OES;    //the define is different between GL and GLES...
        switch (*format) {
            case GL_R:
            case GL_RED:
                if(!hardext.rgtex) {
                    dest_format = GL_RGB;
                    convert = true;
                } else
                    dest_format = GL_RED;
                break;
            case GL_RG:
                if(!hardext.rgtex) {
                    dest_format = GL_RGB;
                    convert = true;
                } else
                    dest_format = GL_RG;
                break;
            case GL_COMPRESSED_LUMINANCE:
                *format = GL_LUMINANCE;
            case GL_LUMINANCE:
                dest_format = GL_LUMINANCE;
                break;
            case GL_LUMINANCE16F:
                dest_format = GL_LUMINANCE;
                if(hardext.halffloattex)
                    dest_type = GL_HALF_FLOAT_OES;
                break;
            case GL_LUMINANCE32F:
                dest_format = GL_LUMINANCE;
                if(hardext.floattex)
                    dest_type = GL_FLOAT;
                break;
            case GL_RGB:
                dest_format = GL_RGB;
                break;
            case GL_COMPRESSED_ALPHA:
                *format = GL_ALPHA;
            case GL_ALPHA:
                dest_format = GL_ALPHA;
                break;
            case GL_ALPHA16F:
                dest_format = GL_ALPHA;
                if(hardext.halffloattex)
                    dest_type = GL_HALF_FLOAT_OES;
                break;
            case GL_ALPHA32F:
                dest_format = GL_ALPHA;
                if(hardext.floattex)
                    dest_type = GL_FLOAT;
                break;
            case GL_RGBA:
                break;
            case GL_LUMINANCE8_ALPHA8:
            case GL_COMPRESSED_LUMINANCE_ALPHA:
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
            case GL_LUMINANCE_ALPHA16F:
                if(globals4es.nolumalpha)
                    convert = true;
                else
                    dest_format = GL_LUMINANCE_ALPHA;
                if(hardext.halffloattex)
                    dest_type = GL_HALF_FLOAT_OES;
                break;
            case GL_LUMINANCE_ALPHA32F:
                if(globals4es.nolumalpha)
                    convert = true;
                else
                    dest_format = GL_LUMINANCE_ALPHA;
                if(hardext.floattex)
                    dest_type = GL_FLOAT;
                break;
            // vvvvv all this are internal formats, so it should not happens
            case GL_RGB5:
            case GL_RGB565:
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
                if(hardext.bgra8888 && ((*type)==GL_UNSIGNED_BYTE || (*type)==GL_FLOAT || (*type)==GL_HALF_FLOAT)) {
                    dest_format = GL_BGRA;
                    *format = GL_BGRA;
                } else convert = true;
                break;
            case GL_DEPTH24_STENCIL8:
            case GL_DEPTH_STENCIL:
                if(hardext.depthtex && hardext.depthstencil) {
                    *format = dest_format = GL_DEPTH_STENCIL;
                    dest_type = GL_UNSIGNED_INT_24_8;
                } else convert = true;
                break;
            case GL_DEPTH_COMPONENT:
            case GL_DEPTH_COMPONENT16:
            case GL_DEPTH_COMPONENT32:
                if(hardext.depthtex) {
                    if(dest_type==GL_UNSIGNED_BYTE) {
                        dest_type=(*format==GL_DEPTH_COMPONENT32)?GL_UNSIGNED_INT:GL_UNSIGNED_SHORT;
                        convert = true;
                    }
                    *format = dest_format = GL_DEPTH_COMPONENT;
                } else
                    convert = true;
                break;
            case GL_STENCIL_INDEX8:
                if(hardext.stenciltex)
                    *format = dest_format = GL_STENCIL_INDEX8;
                else
                    convert = true;
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
            case GL_UNSIGNED_INT_8_8_8_8_REV:
                *type = GL_UNSIGNED_BYTE;
                // fall through
            case GL_UNSIGNED_BYTE:
                if(dest_format==GL_RGB && globals4es.avoid24bits) {
                    dest_format = GL_RGBA;
                    convert = true;
                }
                break;
            case GL_UNSIGNED_INT_24_8:
                if(hardext.depthtex && hardext.depthstencil) {
                    dest_type = GL_UNSIGNED_INT_24_8;
                } else {
                    *type = GL_UNSIGNED_BYTE;   // will probably do nothing good!
                    convert = true;
                }
                break;
            case GL_FLOAT:
                if(hardext.floattex)
                    dest_type = GL_FLOAT;
                else
                    convert = true;
                break;
            case GL_HALF_FLOAT:
            case GL_HALF_FLOAT_OES:
                if(hardext.halffloattex)
                    dest_type = GL_HALF_FLOAT_OES;
                else
                    convert = true;
                break;
            default:
                convert = true;
                break;
        }
    }
    if (data) {
        if (convert) {
            GLvoid *pixels = (GLvoid *)data;
            bound->inter_format = dest_format;
            bound->format = dest_format;
            bound->inter_type = dest_type;
            bound->type = dest_type;
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
                bound->format = dest_format;
                bound->type = dest_type;
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
        } else {
            bound->inter_format = dest_format;
            bound->format = dest_format;
            bound->inter_type = dest_type;
            bound->type = dest_type;
        }
    } else {
        bound->inter_format = dest_format;
        bound->inter_type = dest_type;
        if (convert) {
            internal2format_type(internalformat, &dest_format, &dest_type); // in case they are differents
            *type = dest_type;
            *format = dest_format;
        }
        bound->format = dest_format;
        bound->type = dest_type;
    }
    return (void *)data;
}

GLenum swizzle_internalformat(GLenum *internalformat, GLenum format, GLenum type) {
    GLenum ret = *internalformat;
    GLenum sret;
    switch(*internalformat) {
        case GL_RED:
            if(!hardext.rgtex) {
                ret = GL_RGB; sret = GL_RGB;
            } else
                sret = GL_RED;
            break;
        case GL_RG:
            if(!hardext.rgtex) {
                ret = GL_RGB; sret = GL_RGB;
            } else
                sret = GL_RG;
            break;
        case GL_RGB565:
            ret=GL_RGB5;
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
        case GL_ALPHA32F:
        case GL_ALPHA16F:
        case GL_ALPHA8:
        case GL_ALPHA:
            ret = GL_ALPHA; sret = GL_ALPHA;
            break;
        case 1:
        case GL_LUMINANCE32F:
        case GL_LUMINANCE16F:
        case GL_LUMINANCE8:
        case GL_LUMINANCE16:
        case GL_LUMINANCE:
            if(format==GL_RED && hardext.rgtex) {
                ret = GL_RED; sret = GL_RED;    
            } else {
                ret = GL_LUMINANCE; sret = GL_LUMINANCE;
            }
            break;
        case 2: 
        case GL_LUMINANCE4_ALPHA4:
        case GL_LUMINANCE8_ALPHA8:
        case GL_LUMINANCE16_ALPHA16:
        case GL_LUMINANCE_ALPHA32F:
        case GL_LUMINANCE_ALPHA16F:
        case GL_LUMINANCE_ALPHA:
            ret = GL_LUMINANCE_ALPHA;
            if (globals4es.nolumalpha)
                sret = GL_RGBA;
            else
                sret = GL_LUMINANCE_ALPHA;
            break;
        // compressed format...
        case GL_COMPRESSED_ALPHA:
            ret = GL_ALPHA;//GL_COMPRESSED_RGBA;
            sret = GL_ALPHA;
            break;
        case GL_COMPRESSED_LUMINANCE:
            ret = GL_LUMINANCE;//GL_COMPRESSED_RGB;
            sret = GL_LUMINANCE;
            break;
        case GL_COMPRESSED_LUMINANCE_ALPHA:
            if (globals4es.nolumalpha) {
                ret = GL_COMPRESSED_RGBA;
                sret = GL_RGBA;
            } else {
                ret = GL_LUMINANCE_ALPHA;
                sret = GL_LUMINANCE_ALPHA;
            }
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
        case GL_DEPTH_COMPONENT:
            if(hardext.depthtex) {
                sret = ret = GL_DEPTH_COMPONENT;
            } else {
                sret = ret = GL_RGBA;
            }
            break;
        case GL_DEPTH_COMPONENT16:
            if(hardext.depthtex) {
                sret = ret = GL_DEPTH_COMPONENT;
            } else {
                sret = ret = GL_RGBA;
            }
            break;
        case GL_DEPTH_COMPONENT32:
            if(hardext.depthtex) {
                sret = ret = GL_DEPTH_COMPONENT;
            } else {
                sret = ret = GL_RGBA;
            }
            break;
        case GL_DEPTH24_STENCIL8:
            if(hardext.depthtex) {
                sret = ret = GL_DEPTH_STENCIL;
            } else {
                sret = ret = GL_RGBA;
            }
            break;
        case GL_STENCIL_INDEX8:
            if(hardext.stenciltex) {
                sret = ret = GL_STENCIL_INDEX8;
            } else {
                sret = ret = (hardext.rgtex)?GL_RED:GL_LUMINANCE;
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
            if (((mipwidth%4==0) && (mipheight%4==0)) && 
                ((mipwidth > 256) && (mipheight > 8)) || ((mipheight > 256) && (mipwidth > 8))) {
                if ((mipwidth>=1024) || (mipheight>=1024)) {
                    shrink = 2;
                } else {
                    shrink = 1;
                }
            }
            break;
        case 5: //every > 256 is downscaled to 256, but not for empty texture
            if (((mipwidth%4==0) && (mipheight%4==0)) && 
                ((mipwidth > 256) && (mipheight > 8)) || ((mipheight > 256) && (mipwidth > 8))) {
                if ((mipwidth>256) || (mipheight>256)) {
                    while (((mipwidth > 256) && (mipheight > 4)) || ((mipheight > 256) && (mipwidth > 4))) {
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
        case 6: //only > 128 /2, >=512 is downscaled to 256, but not for empty texture
            if (((mipwidth%2==0) && (mipheight%2==0)) && 
                ((mipwidth > 128) && (mipheight > 8)) || ((mipheight > 128) && (mipwidth > 8))) {
                if ((mipwidth>=512) || (mipheight>=512)) {
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
        case 8: //advertise *4 max texture size, but >2048 are shrinked to 2048
            if ((mipwidth>hardext.maxsize*2) || (mipheight>hardext.maxsize*2)) {
                shrink=2;
            } else
            if ((mipwidth>hardext.maxsize) || (mipheight>hardext.maxsize)) {
                shrink=1;
            }
            break;
        case 9: //advertise 8192 max texture size, but >4096 are quadshrinked and >512 are shrinked, but not for empty texture
            if ((mipwidth>hardext.maxsize*2) || (mipheight>hardext.maxsize*2)) {
                shrink=2;
            } else
            if (mipwidth>(hardext.maxsize>>2) || mipheight>(hardext.maxsize>>2)) {
                shrink=1;
            }
            break;
        case 10://advertise 8192 max texture size, but >2048 are quadshrinked and >512 are shrinked, but not for empty texture
            if ((mipwidth>hardext.maxsize) || (mipheight>hardext.maxsize)) {
                shrink=2;
            } else
            if ((mipwidth>(hardext.maxsize>>2)) || (mipheight>(hardext.maxsize>>2))) {
                shrink=1;
            }
            break;
        case 11:// scale down to maxres any dimension > maxres
            if(mipwidth>hardext.maxsize || mipheight>hardext.maxsize)
                shrink=1;
            break;
        }
        
    return shrink;
} 

static int proxy_width = 0;
static int proxy_height = 0;
static GLint proxy_intformat = 0;

int wrap_npot(GLenum wrap) {
    switch(wrap) {
        case 0: return 1;   // default is ok (should not, it's GL_REPEAT)
        case GL_CLAMP:
        case GL_CLAMP_TO_EDGE:
        case GL_CLAMP_TO_BORDER:
            return 1;
    }
    return 0;
}
int minmag_npot(GLenum mag) {
    switch(mag) {
        case 0: return 0;   // default is not good
        case GL_NEAREST:
        case GL_LINEAR:
            return 1;
    }
    return 0;
}

GLenum minmag_forcenpot(GLenum filt) {
    switch(filt) {
        case GL_LINEAR:
        case GL_LINEAR_MIPMAP_NEAREST:
        case GL_LINEAR_MIPMAP_LINEAR:
            return GL_LINEAR;
        /*case 0:
        case GL_NEAREST:
        case GL_NEAREST_MIPMAP_NEATEST:
        case GL_NEAREST_MIPMAP_LINEAR:*/
        default:
            return GL_NEAREST;
    }
}

GLenum minmag_float(GLenum filt) {
    switch(filt) {
        case GL_LINEAR:
            return GL_NEAREST;
        case GL_LINEAR_MIPMAP_NEAREST:
        case GL_LINEAR_MIPMAP_LINEAR:
        case GL_NEAREST_MIPMAP_LINEAR:
            return GL_NEAREST_MIPMAP_NEAREST;
        default:
            return filt;
    }
}

void gl4es_glTexImage2D(GLenum target, GLint level, GLint internalformat,
                  GLsizei width, GLsizei height, GLint border,
                  GLenum format, GLenum type, const GLvoid *data) {
    DBG(printf("glTexImage2D on target=%s with unpack_row_length(%i), size(%i,%i) and skip(%i,%i), format(internal)=%s(%s), type=%s, data=%p, level=%i (mipmap_need=%i, mipmap_auto=%i, base_level=%i, max_level=%i) => texture=%u (streamed=%i), glstate->list.compiling=%d\n", PrintEnum(target), glstate->texture.unpack_row_length, width, height, glstate->texture.unpack_skip_pixels, glstate->texture.unpack_skip_rows, PrintEnum(format), (internalformat==3)?"3":(internalformat==4?"4":PrintEnum(internalformat)), PrintEnum(type), data, level, glstate->texture.bound[glstate->texture.active][what_target(target)]->mipmap_need, glstate->texture.bound[glstate->texture.active][what_target(target)]->mipmap_auto, glstate->texture.bound[glstate->texture.active][what_target(target)]->base_level, glstate->texture.bound[glstate->texture.active][what_target(target)]->max_level, glstate->texture.bound[glstate->texture.active][what_target(target)]->texture, glstate->texture.bound[glstate->texture.active][what_target(target)]->streamed, glstate->list.compiling);)
    // proxy case
    const GLuint itarget = what_target(target);
    const GLuint rtarget = map_tex_target(target);
    LOAD_GLES(glTexImage2D);
    LOAD_GLES(glTexSubImage2D);
    LOAD_GLES(glTexParameteri);

    if(globals4es.force16bits) {
        if(internalformat==GL_RGBA || internalformat==4 || internalformat==GL_RGBA8)
            internalformat = GL_RGBA4;
        else if(internalformat==GL_RGB || internalformat==3 || internalformat==GL_RGB8)
            internalformat = GL_RGB5;
    }

    if (rtarget == GL_PROXY_TEXTURE_2D) {
        int max1=hardext.maxsize;
        proxy_width = ((width<<level)>max1)?0:width;
        proxy_height = ((height<<level)>max1)?0:height;
        proxy_intformat = swizzle_internalformat(&internalformat, format, type);
        return;
    }
    // actualy bound if targetting shared TEX2D
    realize_bound(glstate->texture.active, target);

    if (glstate->list.pending) {
        flush();
    } else {
        PUSH_IF_COMPILING(glTexImage2D);
    }

#ifdef __BIG_ENDIAN__
    if(type==GL_UNSIGNED_INT_8_8_8_8)
#else
    if(type==GL_UNSIGNED_INT_8_8_8_8_REV)
#endif
        type = GL_UNSIGNED_BYTE;

    if(type==GL_HALF_FLOAT)
        type = GL_HALF_FLOAT_OES;

    /*if(format==GL_COMPRESSED_LUMINANCE)
        format = GL_RGB;*/    // Danger from the Deep does that. 
        //That's odd, probably a bug (line 453 of src/texture.cpp, it should be interformat instead of format)

    GLvoid *datab = (GLvoid*)data;
    
    if (glstate->vao->unpack)
        datab += (uintptr_t)glstate->vao->unpack->data;
        
    GLvoid *pixels = (GLvoid *)datab;
    border = 0;	//TODO: something?
    noerrorShim();

    gltexture_t *bound = glstate->texture.bound[glstate->texture.active][itarget];

    //Special case when resizing an attached to FBO texture, taht is attached to depth and/or stencil => resizing is specific then
    if(bound->binded_fbo && (bound->binded_attachment==GL_DEPTH_ATTACHMENT || bound->binded_attachment==GL_STENCIL_ATTACHMENT || bound->binded_attachment==GL_DEPTH_STENCIL_ATTACHMENT))
    {
        // non null data should be handled, but need to convert then...
        if(data!=NULL) 
            printf("LIBGL: Warning, Depth/stencil texture resized and with data\n");
        // get new size...
        GLsizei nheight = (hardext.npot)?height:npot(height);
        GLsizei nwidth = (hardext.npot)?width:npot(width);
        bound->npot = (nheight!=height || nwidth!=width);
        bound->nwidth = nwidth;
        bound->nheight = nheight;
        bound->width = width;
        bound->height = height;
        //resize depth texture of renderbuffer?
        if(bound->binded_attachment==GL_DEPTH_ATTACHMENT || bound->binded_attachment==GL_DEPTH_STENCIL_ATTACHMENT)
        {
            if(bound->renderdepth) {
                gl4es_glBindRenderbuffer(GL_RENDERBUFFER, bound->renderdepth);
                gl4es_glRenderbufferStorage(GL_RENDERBUFFER, (bound->binded_attachment==GL_DEPTH_ATTACHMENT)?GL_DEPTH_COMPONENT16:GL_DEPTH24_STENCIL8, nwidth, nheight);
                gl4es_glBindRenderbuffer(GL_RENDERBUFFER, 0);
            } else {
                gles_glTexImage2D(GL_TEXTURE_2D, 0, bound->format, bound->nwidth, bound->nheight, 0, bound->format, bound->type, NULL);
            }
        }
        if((bound->binded_attachment==GL_STENCIL_ATTACHMENT || bound->binded_attachment==GL_DEPTH_STENCIL_ATTACHMENT) && bound->renderstencil)
        {
            gl4es_glBindRenderbuffer(GL_RENDERBUFFER, bound->renderstencil);
            gl4es_glRenderbufferStorage(GL_RENDERBUFFER, GL_STENCIL_INDEX8, nwidth, nheight);
            gl4es_glBindRenderbuffer(GL_RENDERBUFFER, 0);
        }
        // all done, exit
        errorGL();
        return;
    }


    bound->alpha = pixel_hasalpha(format);
    // fpe internal format tracking
    if(glstate->fpe_state) {
        switch (internalformat) {
            case GL_COMPRESSED_ALPHA:
            case GL_ALPHA4:
            case GL_ALPHA8:
            case GL_ALPHA16:
            case GL_ALPHA16F:
            case GL_ALPHA32F:
            case GL_ALPHA:
                bound->fpe_format = FPE_TEX_ALPHA;
                break;
            case 1:
            case GL_COMPRESSED_LUMINANCE:
            case GL_LUMINANCE4:
            case GL_LUMINANCE8:
            case GL_LUMINANCE16:
            case GL_LUMINANCE16F:
            case GL_LUMINANCE32F:
            case GL_LUMINANCE:
                bound->fpe_format = FPE_TEX_LUM;
                break;
            case 2:
            case GL_COMPRESSED_LUMINANCE_ALPHA:
            case GL_LUMINANCE4_ALPHA4:
            case GL_LUMINANCE8_ALPHA8:
            case GL_LUMINANCE16_ALPHA16:
            case GL_LUMINANCE_ALPHA16F:
            case GL_LUMINANCE_ALPHA32F:
            case GL_LUMINANCE_ALPHA:
                bound->fpe_format = FPE_TEX_LUM_ALPHA;
                break;
            case GL_COMPRESSED_INTENSITY:
            case GL_INTENSITY8:
            case GL_INTENSITY16:
            case GL_INTENSITY16F:
            case GL_INTENSITY32F:
            case GL_INTENSITY:
                bound->fpe_format = FPE_TEX_INTENSITY;
                break;
            case 3:
            case GL_RED:
            case GL_RG:
            case GL_RGB:
            case GL_RGB5:
            case GL_RGB565:
            case GL_RGB8:
            case GL_RGB16:
            case GL_RGB16F:
            case GL_RGB32F:
            case GL_COMPRESSED_RGB_S3TC_DXT1_EXT:
            case GL_COMPRESSED_RGB:
                bound->fpe_format = FPE_TEX_RGB;
                break;
            /*case GL_DEPTH_COMPONENT:
            case GL_DEPTH_COMPONENT16:
            case GL_DEPTH_COMPONENT24:
            case GL_DEPTH_COMPONENT32:
            case GL_DEPTH_STENCIL:
            case GL_DEPTH24_STENCIL8:
                bound->fpe_format = FPE_TEX_COMPONENT;*/
            default:
                bound->fpe_format = FPE_TEX_RGBA;
        }
    }
    if (globals4es.automipmap) {
        if (level>0)
            if ((globals4es.automipmap==1) || (globals4es.automipmap==3) || bound->mipmap_need) {
                return;			// has been handled by auto_mipmap
            }
            else if(globals4es.automipmap==2)
                bound->mipmap_need = 1;
    }
    if(level>0 && (bound->npot && globals4es.forcenpot))
        return;         // no mipmap...
    GLenum new_format = swizzle_internalformat(&internalformat, format, type);
    if (level==0 || !bound->valid) {
        bound->orig_internal = internalformat;
        bound->internalformat = new_format;
    }
    // shrink checking
    int mipwidth = width << level;
    int mipheight = height << level;
    int shrink = 0;
    bound->shrink = shrink = get_shrinklevel(width, height, level);

    if(((width>>shrink)==0) && ((height>>shrink)==0)) return;   // nothing to do
    if (datab) {

        // implements GL_UNPACK_ROW_LENGTH
        if ((glstate->texture.unpack_row_length && glstate->texture.unpack_row_length != width) 
        || glstate->texture.unpack_skip_pixels || glstate->texture.unpack_skip_rows) {
            int imgWidth, pixelSize, dstWidth;
            pixelSize = pixel_sizeof(format, type);
            imgWidth = ((glstate->texture.unpack_row_length)? glstate->texture.unpack_row_length:width) * pixelSize;
            GLubyte *dst = (GLubyte *)malloc(width * height * pixelSize);
            pixels = (GLvoid *)dst;
            dstWidth = width * pixelSize;
            const GLubyte *src = (GLubyte *)datab;
            src += glstate->texture.unpack_skip_pixels * pixelSize + glstate->texture.unpack_skip_rows * imgWidth;
            for (int y = height; y; --y) {
                memcpy(dst, src, dstWidth);
                src += imgWidth;
                dst += dstWidth;
            }
        }

        GLvoid *old = pixels;
        pixels = (GLvoid *)swizzle_texture(width, height, &format, &type, internalformat, new_format, old, bound);
        if (old != pixels && old != datab) {
            free(old);
        }

        if (bound->shrink!=0) {
            switch(globals4es.texshrink) {
            case 0: // nothing ???
                break;
            case 1: //everything / 2
            case 11:
                if ((mipwidth > 1) && (mipheight > 1)) {
                    GLvoid *out = pixels;
                    GLfloat ratiox, ratioy;
                    int newwidth = mipwidth;
                    int newheight = mipheight;
                    if(globals4es.texshrink==11) {
                        if (mipwidth>hardext.maxsize)
                            newwidth = hardext.maxsize;
                        if (mipheight>hardext.maxsize)
                            newheight = hardext.maxsize;
                    } else {
                        newwidth = mipwidth / 2;
                        newheight = mipheight / 2;
                        if(!newwidth) newwidth=1;
                        if(!newheight) newheight=1;
                    }
                    ratiox = newwidth/((float)mipwidth);
                    ratioy = newheight/((float)mipheight);
                    bound->ratiox = ratiox;
                    bound->ratioy = ratioy;
                    bound->useratio = 1;
                    pixel_scale(pixels, &out, width, height, newwidth, newheight, format, type);
                    if (out != pixels && pixels!=datab)
                        free(pixels);
                    pixels = out;
                    width = newwidth;
                    height = newheight;
                    bound->shrink = 1;
                }
                break;
            default:
                bound->ratiox = bound->ratioy = 1.0f;
                while(shrink) {
                    int toshrink = (shrink>1)?2:1;
                    GLvoid *out = pixels;
                    if(toshrink==1) {
                        pixel_halfscale(pixels, &out, width, height, format, type);
                        bound->ratiox *= 0.5f; bound->ratioy *= 0.5f;
                    } else {
                        pixel_quarterscale(pixels, &out, width, height, format, type);
                        bound->ratiox *= 0.25f; bound->ratioy *= 0.25f;
                    }
                    if (out != pixels && pixels!=datab)
                        free(pixels);
                    pixels = out;
                    width = nlevel(width, toshrink);
                    height = nlevel(height, toshrink);
                    shrink-=toshrink;
                }
            }
        }
        
        if (globals4es.texdump) {
            pixel_to_ppm(pixels, width, height, format, type, bound->texture, glstate->texture.pack_align);
        }
    } else {
#ifdef TEXSTREAM
        if (globals4es.texstream && (target==GL_TEXTURE_2D || target==GL_TEXTURE_RECTANGLE_ARB) && (width>=256 && height>=224) && 
        ((internalformat==GL_RGB) || (internalformat==3) || (internalformat==GL_RGB8) || (internalformat==GL_BGR) || (internalformat==GL_RGB5) || (internalformat==GL_RGB565)) || (globals4es.texstream==2) ) {
            bound->streamingID = AddStreamed(width, height, bound->texture);
            if (bound->streamingID>-1) {	// success
                bound->shrink = 0;  // no shrink on Stream texture
                bound->streamed = true;
                ApplyFilterID(bound->streamingID, bound->min_filter, bound->mag_filter);
                GLboolean tmp = IS_ANYTEX(glstate->enable.texture[glstate->texture.active]);
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
                glstate->bound_stream[glstate->texture.active] = 1;
        }
#endif
        if (!bound->streamed)
            swizzle_texture(width, height, &format, &type, internalformat, new_format, NULL, bound);	// convert format even if data is NULL
        if (bound->shrink!=0) {
            switch(globals4es.texshrink) {
            case 1: //everything / 2
            case 11:
                if ((mipwidth > 1) && (mipheight > 1)) {
                    GLfloat ratiox, ratioy;
                    if(globals4es.texshrink==11) {
                        if (mipwidth>hardext.maxsize)
                            ratiox = hardext.maxsize/((float)mipwidth);
                        else
                            ratiox = 1.0f;
                        if (mipheight>hardext.maxsize)
                            ratioy = hardext.maxsize/((float)mipheight);
                        else
                            ratioy = 1.0f;
                    } else 
                        ratiox = ratioy = 0.5;
                    bound->ratiox = ratiox;
                    bound->ratioy = ratioy;
                    bound->useratio = 1;
                    int newwidth = width*bound->ratiox;
                    int newheight = height*bound->ratioy;
                    if(globals4es.texshrink==11 && newwidth>hardext.maxsize) newwidth=hardext.maxsize; // in case of some rounding error
                    if(globals4es.texshrink==11 && newheight>hardext.maxsize) newheight=hardext.maxsize; // in case of some rounding error
                    width = newwidth;
                    height = newheight;
                    bound->shrink = 1;
                }
                break;
            default:
                bound->ratiox = bound->ratioy = 1.0f;
                while(shrink) {
                    int toshrink = (shrink>1)?2:1;
                    if(toshrink==1) {
                        bound->ratiox *= 0.5f; bound->ratioy *= 0.5f;
                    } else {
                        bound->ratiox *= 0.25f; bound->ratioy *= 0.25f;
                    }
                    width = nlevel(width, toshrink);
                    height = nlevel(height, toshrink);
                    shrink-=toshrink;
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

    int limitednpot = 0;
    {
        GLsizei nheight = (hardext.npot==3)?height:npot(height);
        GLsizei nwidth = (hardext.npot==3)?width:npot(width);
        bound->npot = (nheight!=height || nwidth!=width);    // hardware that fully support NPOT doesn't care anyway
        if(bound->npot) {
            if(target==GL_TEXTURE_RECTANGLE_ARB && hardext.npot)
                limitednpot=1;
            else if(hardext.npot==1 && (
                    (bound->base_level<=0 && bound->max_level==0) 
                 || (globals4es.automipmap==3) 
                 || (globals4es.automipmap==4 && width!=height) 
                 || (globals4es.forcenpot==1) ) 
                 && (wrap_npot(bound->wrap_s) && wrap_npot(bound->wrap_t)) )
                 limitednpot=1;
            else if(hardext.esversion>1 && hardext.npot==1 
                && (!bound->mipmap_auto || !minmag_npot(bound->min_filter) || !minmag_npot(bound->mag_filter)) 
                && (wrap_npot(bound->wrap_s) && wrap_npot(bound->wrap_t)) )
                limitednpot=1;
            else if(hardext.esversion>1 && hardext.npot==2
                && (wrap_npot(bound->wrap_s) && wrap_npot(bound->wrap_t)) )
                limitednpot=1;

            if(limitednpot) {
                nwidth = width;
                nheight = height;
            }
        }
#ifdef PANDORA
#define NO_1x1
#endif
#ifdef NO_1x1
        #define MIN_SIZE 2
        if(level==0 && hardext.esversion==1) {
            if(nwidth < MIN_SIZE) nwidth=MIN_SIZE;
            if(nheight < MIN_SIZE) nheight=MIN_SIZE;
        }
        #undef MIN_SIZE
#endif
        if (globals4es.texstream && bound->streamed) {
            nwidth = width;
            nheight = height;
        }

        if(bound->npot) {
            if(limitednpot && rtarget==GL_TEXTURE_2D) {
                gles_glTexParameteri(rtarget, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                gles_glTexParameteri(rtarget, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
                bound->wrap_t = bound->wrap_s = GL_CLAMP_TO_EDGE;
            } else if (!wrap_npot(bound->wrap_s) || !wrap_npot(bound->wrap_t)) {
                // resize to npot boundaries (not ideal if the wrap value is change after upload of the texture)
                nwidth =  npot(width);
                nheight = npot(height);
                float ratiox, ratioy;
                ratiox = ((float)nwidth)/width;
                ratioy = ((float)nheight)/height;

                GLvoid *out = pixels;
                if(pixels)
                    pixel_scale(pixels, &out, width, height, nwidth, nheight, format, type);
                if (out != pixels && pixels!=datab)
                    free(pixels);
                pixels = out;
                width = nwidth;
                height = nheight;
                limitednpot = 0;

                if(level==0) {
                    if(!bound->useratio) {
                        bound->useratio = 1;
                        if(bound->ratiox==0.f) bound->ratiox = bound->ratioy = 1.0f;
                    }
                    bound->ratiox *= ratiox;
                    bound->ratioy *= ratioy;
                    bound->npot = 0;
                    bound->shrink = 1;
                }
            }
        }
        // check min/mag settings for GL_FLOAT type textures (only GL_NEAREST  and GL_NEAREST_MIPMAP_NEAREST is supported)
        if(type==GL_FLOAT || type==GL_HALF_FLOAT_OES) {
            GLenum m = minmag_float(bound->min_filter);
            if(bound->min_filter != m ) {
                bound->min_filter = m;
                gles_glTexParameteri(rtarget, GL_TEXTURE_MIN_FILTER, m);
            }
            m = minmag_float(bound->mag_filter);
            if(bound->mag_filter != m ) {
                bound->mag_filter = m;
                gles_glTexParameteri(rtarget, GL_TEXTURE_MAG_FILTER, m);
            }
            bound->mipmap_auto = 0; // no need to automipmap here
        }
        // check min/mag for NPOT with limited support
        if(limitednpot && hardext.npot<2) {
            GLenum m = minmag_forcenpot(bound->min_filter);
            if (m!=bound->min_filter)
                gles_glTexParameteri(rtarget, GL_TEXTURE_MIN_FILTER, m);
            m = minmag_forcenpot(bound->mag_filter);
            if (m!=bound->mag_filter)
                gles_glTexParameteri(rtarget, GL_TEXTURE_MAG_FILTER, m);
            bound->mipmap_auto = 0; // no need to automipmap here
        }
        if ((globals4es.automipmap==4) && (nwidth!=nheight))
            bound->mipmap_auto = 0;

        if (level == 0) {
            bound->width = width;
            bound->height = height;
            bound->nwidth = nwidth;
            bound->nheight = nheight;
            if(target==GL_TEXTURE_RECTANGLE_ARB && hardext.esversion==2) {
                bound->adjust = 0;  // because this test is used in a lot of places
                bound->adjustxy[0] = 1.0f/width;
                bound->adjustxy[1] = 1.0f/height;
            } else {
                // TEXTURE_RECTANGLE could be mutualize with npot texture probably
                bound->adjust = (width!=nwidth || height!=nheight);
                bound->adjustxy[0] = (float)width / nwidth;
                bound->adjustxy[1] = (float)height / nheight;
            }
            bound->compressed = false;
            bound->valid = 1;
        }

        int callgeneratemipmap = 0;
        if (!(globals4es.texstream && bound->streamed)) {
            if ((target!=GL_TEXTURE_RECTANGLE_ARB) && (globals4es.automipmap!=3) && (bound->mipmap_need || bound->mipmap_auto) && !(bound->npot && hardext.npot<2)) {
                if(hardext.esversion<2)
                    gles_glTexParameteri( rtarget, GL_GENERATE_MIPMAP, GL_TRUE );
                else
                    callgeneratemipmap = 1;
            } else {
                //if(target!=GL_TEXTURE_RECTANGLE_ARB) gles_glTexParameteri( rtarget, GL_GENERATE_MIPMAP, GL_FALSE );
                if ((itarget!=ENABLED_CUBE_MAP && target!=GL_TEXTURE_RECTANGLE_ARB) 
                && (bound->mipmap_need || globals4es.automipmap==3)) {
                    // remove the need for mipmap...
                    bound->mipmap_need = 0;
                    /*gles_glTexParameteri(rtarget, GL_TEXTURE_MIN_FILTER, bound->min_filter);
                    gles_glTexParameteri(rtarget, GL_TEXTURE_MAG_FILTER, bound->mag_filter);*/ // why forcing ?
                }
            }
            
            if (height != nheight || width != nwidth) {
                errorGL();
                gles_glTexImage2D(rtarget, level, format, nwidth, nheight, border,
                                format, type, NULL);
                DBG(CheckGLError(1);)
                if (pixels) {
                    gles_glTexSubImage2D(rtarget, level, 0, 0, width, height,
                                        format, type, pixels);
                                        DBG(CheckGLError(1);)
                }
#ifdef NO_1x1
                if(level==0 && (width==1 && height==1 && pixels)) {
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
                errorGL();
                gles_glTexImage2D(rtarget, level, format, width, height, border,
                                format, type, pixels);
                DBG(CheckGLError(1);)
            }
            // check if base_level is set... and calculate lower level mipmap
            if(bound->base_level == level && !(bound->max_level==level && level==0)) {
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
            if(globals4es.automipmap==5 && !level)
                bound->mipmap_done = 0;
            // check if max_level is set... and calculate higher level mipmap
            if(((bound->max_level == level && (level || bound->mipmap_need)) || (callgeneratemipmap && level==0) || (globals4es.automipmap==5 && level && !bound->mipmap_done)) && !(bound->max_level==bound->base_level && bound->max_level==0)) {
                if(globals4es.automipmap==5 && level==1)
                    bound->mipmap_done = 1;
                int leveln = level, nw = nwidth, nh = nheight, nww=width, nhh=height;
                int pot = (nh==nhh && nw==nww);
                void *ndata = pixels;
                while(nw!=1 || nh!=1) {
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
    if ((target==GL_TEXTURE_2D) && globals4es.texcopydata && ((globals4es.texstream && !bound->streamed) || !globals4es.texstream)) {
        if (bound->data) 
            bound->data=realloc(bound->data, width*height*4);
        else 
            bound->data = malloc(width*height*4);
        if (datab) {
            if (!pixel_convert(pixels, &bound->data, width, height, format, type, GL_RGBA, GL_UNSIGNED_BYTE, 0, glstate->texture.unpack_align))
                printf("LIBGL: Error on pixel_convert when TEXCOPY in glTexImage2D\n");
        } else {
        //memset(bound->data, 0, width*height*4);
        }
    }
    if (pixels != datab) {
        free(pixels);
    }
}

void gl4es_glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset,
                     GLsizei width, GLsizei height, GLenum format, GLenum type,
                     const GLvoid *data) {

    if (glstate->list.pending) {
        flush();
    } else {
        PUSH_IF_COMPILING(glTexSubImage2D);
    }
    realize_bound(glstate->texture.active, target);

#ifdef __BIG_ENDIAN__
    if(type==GL_UNSIGNED_INT_8_8_8_8)
#else
    if(type==GL_UNSIGNED_INT_8_8_8_8_REV)
#endif
        type = GL_UNSIGNED_BYTE;

    
    GLvoid *datab = (GLvoid*)data;
    if (glstate->vao->unpack)
        datab += (uintptr_t)glstate->vao->unpack->data;
    GLvoid *pixels = (GLvoid*)datab;

    const GLuint itarget = what_target(target);
    const GLuint rtarget = map_tex_target(target);

    LOAD_GLES(glTexSubImage2D);
    LOAD_GLES(glTexParameteri);
    noerrorShim();
    DBG(printf("glTexSubImage2D on target=%s with unpack_row_length(%d), size(%d,%d), pos(%d,%d) and skip={%d,%d}, format=%s, type=%s, level=%d(base=%d, max=%d), mipmap={need=%d, auto=%d}, texture=%u\n", PrintEnum(target), glstate->texture.unpack_row_length, width, height, xoffset, yoffset, glstate->texture.unpack_skip_pixels, glstate->texture.unpack_skip_rows, PrintEnum(format), PrintEnum(type), level, glstate->texture.bound[glstate->texture.active][itarget]->base_level, glstate->texture.bound[glstate->texture.active][itarget]->max_level, glstate->texture.bound[glstate->texture.active][itarget]->mipmap_need, glstate->texture.bound[glstate->texture.active][itarget]->mipmap_auto, glstate->texture.bound[glstate->texture.active][itarget]->texture);)
    if (width==0 || height==0) {
        return;
    }
    
    gltexture_t *bound = glstate->texture.bound[glstate->texture.active][itarget];
    if (globals4es.automipmap) {
        if (level>0)
            if ((globals4es.automipmap==1) || (globals4es.automipmap==3) || bound->mipmap_need) {
                return;			// has been handled by auto_mipmap
            }
            else
                bound->mipmap_need = 1;
    }

    if ((glstate->texture.unpack_row_length && glstate->texture.unpack_row_length != width) || glstate->texture.unpack_skip_pixels || glstate->texture.unpack_skip_rows) {
        int imgWidth, pixelSize, dstWidth;
        pixelSize = pixel_sizeof(format, type);
        imgWidth = ((glstate->texture.unpack_row_length)? glstate->texture.unpack_row_length:width) * pixelSize;
        GLubyte *dst = (GLubyte *)malloc(width * height * pixelSize);
        pixels = (GLvoid *)dst;
        dstWidth = width * pixelSize;
        const GLubyte *src = (GLubyte *)datab;
        src += glstate->texture.unpack_skip_pixels * pixelSize + glstate->texture.unpack_skip_rows * imgWidth;
        for (int y = height; y; --y) {
            memcpy(dst, src, dstWidth);
            src += imgWidth;
            dst += dstWidth;
        }
    }
    
    GLvoid *old = pixels;
#ifdef TEXSTREAM
    if (globals4es.texstream && (bound->streamed)) {
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
        if (!pixel_convert(old, &pixels, width, height, format, type, bound->inter_format, bound->inter_type, 0, glstate->texture.unpack_align)) {
            printf("LIBGL: Error in pixel_convert while glTexSubImage2D\n");
        } else {
            format = bound->inter_format;
            type = bound->inter_type;
            if(bound->inter_format!=bound->format || bound->inter_type!=bound->type) {
                GLvoid* pix2 = pixels;
                if (!pixel_convert(pixels, &pix2, width, height, format, type, bound->format, bound->type, 0, glstate->texture.unpack_align)) {
                    printf("LIBGL: Error in pixel_convert while glTexSubImage2D\n");
                }
                if (pixels != pix2 && pixels != old)
                    free(pixels);
                pixels = pix2;
                format = bound->format;
                type = bound->type;
            }
        }
        
    }
    if (old != pixels && old != datab)
        free(old);

    if (bound->shrink || bound->useratio) {
        // special case for width/height == 1
        if (width==1)
            width+=(xoffset%2);
        if (height==1)
            height+=(yoffset%2);
        if ((width==1) || (height==1)) {
            // nothing to do...
            if (pixels != datab)
                free((GLvoid *)pixels);
            return;
        }
        // ok, now standard cases....
        old = pixels;
        if(bound->useratio) {
            xoffset *= bound->ratiox;
            yoffset *= bound->ratioy;
            int newwidth = width * bound->ratiox;
            int newheight = height * bound->ratioy;
            pixel_scale(pixels, &old, width, height, newwidth, newheight, format, type);
            width = newwidth;
            height = newheight;
            if (old != pixels && pixels!=data)
                free(pixels);
            pixels = old;
        } else {
            xoffset /= 2*bound->shrink;
            yoffset /= 2*bound->shrink;
            int shrink = bound->shrink;
            while(shrink) {
                int toshrink = (shrink>1)?2:1;
                GLvoid *out = pixels;
                if(toshrink==1)
                    pixel_halfscale(pixels, &old, width, height, format, type);
                else
                    pixel_quarterscale(pixels, &old, width, height, format, type);
                if (old != pixels && pixels!=data)
                    free(pixels);
                pixels = old;
                width = nlevel(width, toshrink);
                height = nlevel(height, toshrink);
                shrink-=toshrink;
            }
        }
    }

    if (globals4es.texdump) {
        pixel_to_ppm(pixels, width, height, format, type, bound->texture, glstate->texture.pack_align);
    }

    int callgeneratemipmap = 0;
    if (level==0 && bound->mipmap_need && (!bound->mipmap_auto || hardext.esversion>1) && (globals4es.automipmap!=3) && (!globals4es.texstream || (globals4es.texstream && !bound->streamed)))
        if(hardext.esversion<2) {
            // ES2 doesn't have this
        //    gles_glTexParameteri( rtarget, GL_GENERATE_MIPMAP, GL_TRUE ); // not sure the usefullness of this call
        } else {
            callgeneratemipmap = 1;
        }

    if (globals4es.texstream && bound->streamed) {
/*	// copy the texture to the buffer
    void* tmp = GetStreamingBuffer(bound->streamingID);
    for (int yy=0; yy<height; yy++) {
        memcpy(tmp+((yy+yoffset)*bound->width+xoffset)*2, pixels+(yy*width)*2, width*2);
    }*/
    } else {
        errorGL();
        gles_glTexSubImage2D(rtarget, level, xoffset, yoffset,
                     width, height, format, type, pixels);
        DBG(CheckGLError(1);)
        // check if base_level is set... and calculate lower level mipmap
        if(bound->base_level == level && !(bound->max_level==level && level==0)) {
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
        // check if max_level is set... and calculate higher level mipmap
        if(((((bound->max_level == level) && (level || bound->mipmap_need)) && (globals4es.automipmap!=3) && (bound->mipmap_need!=0)) || (callgeneratemipmap && level==0)) && !(bound->max_level==bound->base_level && bound->base_level==0)) {
            int leveln = level, nw = width, nh = height, xx=xoffset, yy=yoffset;
            void *ndata = pixels;
            while(nw!=1 || nh!=1) {
                if(pixels) {
                    GLvoid *out = ndata;
                    pixel_halfscale(ndata, &out, nw, nh, format, type);
                    if (out != ndata && ndata!=pixels)
                        free(ndata);
                    ndata = out;
                }
                nw = nlevel(nw, 1);
                nh = nlevel(nh, 1);
                xx = xx>>1;
                yy = yy>>1;
                ++leveln;
                gles_glTexSubImage2D(rtarget, leveln, xx, yy, nw, nh,
                                    format, type, ndata);
            }
            if (ndata!=pixels)
                free(ndata);
        }
    }

    /*if (bound->mipmap_need && !bound->mipmap_auto && (globals4es.automipmap!=3) && (!globals4es.texstream || (globals4es.texstream && !bound->streamed)))
        gles_glTexParameteri( rtarget, GL_GENERATE_MIPMAP, GL_FALSE );*/

    if ((target==GL_TEXTURE_2D) && globals4es.texcopydata && ((globals4es.texstream && !bound->streamed) || !globals4es.texstream)) {
    //printf("*texcopy* glTexSubImage2D, xy=%i,%i, size=%i,%i=>%i,%i, format=%s, type=%s, tex=%u\n", xoffset, yoffset, width, height, bound->width, bound->height, PrintEnum(format), PrintEnum(type), bound->glname);
        GLvoid * tmp = bound->data;
        tmp += (yoffset*bound->width + xoffset)*4;
        if (!pixel_convert(pixels, &tmp, width, height, format, type, GL_RGBA, GL_UNSIGNED_BYTE, bound->width, glstate->texture.unpack_align))
            printf("LIBGL: Error on pixel_convert while TEXCOPY in glTexSubImage2D\n");
    }

    if (pixels != datab)
        free((GLvoid *)pixels);
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
    DBG(printf("glPixelStorei(%s, %d)\n", PrintEnum(pname), param);)
    // TODO: add to glGetIntegerv?

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
    DBG(printf("glIsTexture(%d):", texture);)
    if(!glstate) {DBG(printf("GL_FALSE\n");) return GL_FALSE;}
    noerrorShim();
    if (!texture) {
        DBG(printf("%s\n", glstate->texture.zero->valid?"GL_TRUE":"GL_FALSE");)
        return glstate->texture.zero->valid;
    }
    int ret;
    khint_t k;
    khash_t(tex) *list = glstate->texture.list;
    if (! list) {
        DBG(printf("GL_FALSE\n");)
        return GL_FALSE;
    }
    k = kh_get(tex, list, texture);
    gltexture_t *tex = NULL;
    if (k == kh_end(list)) {
        DBG(printf("GL_FALSE\n");)
        return GL_FALSE;
    }
    DBG(printf("GL_TRUE\n");)
    return GL_TRUE;
}

gltexture_t* gl4es_getCurrentTexture(GLenum target) {
    GLuint itarget = what_target(target);
    return glstate->texture.bound[glstate->texture.active][itarget];
}
gltexture_t* gl4es_getTexture(GLenum target, GLuint texture) {
    // Get a texture based on glID
    gltexture_t* tex = NULL;
    if (texture == 0) return glstate->texture.zero; // texture 0 is a texture mostly like any other... it is not "unbind" texture in fact, but it's not shared
    int ret;
    khint_t k;
    khash_t(tex) *list = glstate->texture.list;
    k = kh_get(tex, list, texture);
    
    if (k == kh_end(list)){
        LOAD_GLES(glGenTextures);
        k = kh_put(tex, list, texture, &ret);
        tex = kh_value(list, k) = malloc(sizeof(gltexture_t));
        memset(tex, 0, sizeof(gltexture_t));
        tex->texture = texture;
        if (texture)
            gles_glGenTextures(1, &tex->glname);
        else
            tex->glname = 0;    // special case for texture n# 0
        DBG(printf("getTexture(%s, %u), failed, creating texture %u\n", PrintEnum(target), texture, tex->glname);)
        tex->target = target;
        tex->adjustxy[0] = tex->adjustxy[1] = 1.f;
        tex->mipmap_auto = (globals4es.automipmap==1);
        tex->mipmap_need = (globals4es.automipmap==1)?1:0;
        tex->streamingID = -1;
        tex->base_level = -1;
        tex->max_level = -1;
        tex->alpha = true;
        tex->min_filter = GL_NEAREST_MIPMAP_LINEAR; //(globals4es.automipmap==1)?GL_NEAREST_MIPMAP_LINEAR:GL_LINEAR;
        tex->mag_filter = GL_LINEAR;
        tex->wrap_s = tex->wrap_t = (globals4es.defaultwrap?0:GL_REPEAT);
        tex->fpe_format = FPE_TEX_RGBA;
        tex->format = GL_RGBA;
        tex->type = GL_UNSIGNED_BYTE;
        tex->inter_format = GL_RGBA;
        tex->inter_type = GL_UNSIGNED_BYTE;
    } else {
        tex = kh_value(list, k);
    }
    return tex;
}
void gl4es_glBindTexture(GLenum target, GLuint texture) {
    noerrorShim();
    DBG(printf("glBindTexture(%s, %u), active=%i, client=%i, list.active=%p (compiling=%d, pending=%d)\n", PrintEnum(target), texture, glstate->texture.active, glstate->texture.client, glstate->list.active, glstate->list.compiling, glstate->list.pending);)
    if ((target!=GL_PROXY_TEXTURE_2D) && glstate->list.compiling && glstate->list.active && !glstate->list.pending) {
        // check if already a texture binded, if yes, create a new list
        NewStage(glstate->list.active, STAGE_BINDTEX);
        rlBindTexture(glstate->list.active, target, texture);
    } else {
        int tex_changed = 1;
        gltexture_t *tex = NULL;
        const GLuint itarget = what_target(target);

        tex = gl4es_getTexture(target, texture);
        if (glstate->texture.bound[glstate->texture.active][itarget] != tex) {
            if(glstate->list.pending) flush();
            tex_changed = glstate->texture.active+1;
            glstate->texture.bound[glstate->texture.active][itarget] = tex;
        }
        LOAD_GLES(glBindTexture);
        switch(target) {
            // cube map are bounded immediatly, other are defered and will be applied with realize_bound or realize_textures
            case GL_TEXTURE_CUBE_MAP:
            case GL_TEXTURE_CUBE_MAP_POSITIVE_X:
            case GL_TEXTURE_CUBE_MAP_NEGATIVE_X:
            case GL_TEXTURE_CUBE_MAP_POSITIVE_Y:
            case GL_TEXTURE_CUBE_MAP_NEGATIVE_Y:
            case GL_TEXTURE_CUBE_MAP_POSITIVE_Z:
            case GL_TEXTURE_CUBE_MAP_NEGATIVE_Z:
                gles_glBindTexture(target, tex?tex->glname:0);
                break;
            case GL_TEXTURE_1D:
            case GL_TEXTURE_2D:
            case GL_TEXTURE_3D:
            case GL_TEXTURE_RECTANGLE_ARB:
                if (glstate->bound_changed < glstate->texture.active+1)
                    glstate->bound_changed = glstate->texture.active+1;
                if (glstate->fpe_state && glstate->fpe_bound_changed < glstate->texture.active+1)
                    glstate->fpe_bound_changed = glstate->texture.active+1;
                break;
        }
    }
}

// TODO: also glTexParameterf(v)?
void gl4es_glTexParameteri(GLenum target, GLenum pname, GLint param) {
    DBG(printf("glTexParameteri(%s, %s, %d(%s))\n", PrintEnum(target), PrintEnum(pname), param, PrintEnum(param));)
    if(!glstate->list.pending) {
        PUSH_IF_COMPILING(glTexParameteri);
    }
    LOAD_GLES(glTexParameteri);
    noerrorShim();
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
            texture->mipmap_need = true;
            if ((globals4es.automipmap==3) || ((globals4es.automipmap==1) && (texture->mipmap_auto==0)))
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
        }
        if(texture->valid && (texture->type==GL_FLOAT || texture->type==GL_HALF_FLOAT_OES)) {
            // FLOAT textures have limited mipmap support in GLES2
            param = minmag_float(param);
        }
        if(texture->valid && (texture->npot && globals4es.forcenpot)) {
            // need to remove MIPMAP for npot if not supported in hardware
            param = minmag_forcenpot(param);
        }
        if (pname==GL_TEXTURE_MIN_FILTER) { if(texture->min_filter == param) return; texture->min_filter = param; }
        if (pname==GL_TEXTURE_MAG_FILTER) { if(texture->mag_filter == param) return; texture->mag_filter = param; }
        break;
    case GL_TEXTURE_WRAP_S:
    case GL_TEXTURE_WRAP_T:
        switch (param) {
        case GL_CLAMP:
        case GL_CLAMP_TO_BORDER:
            param = GL_CLAMP_TO_EDGE;
            break;
        case GL_REPEAT:
        case GL_MIRRORED_REPEAT_OES:
            if(globals4es.defaultwrap==2 && hardext.npot<3 && !texture->valid)
                param = GL_CLAMP_TO_EDGE;
            else if(hardext.esversion>1 && hardext.npot<3 && texture->valid 
            && texture->npot) {
                // should "upgrade" the texture to POT size...
        //printf("Warning, REPEAT / MIRRORED_REPEAT on NPOT texture\n");
                param = GL_CLAMP_TO_EDGE;   // repeat is not support on NPOT with limited_npot
            }
            break;
        }

        if (pname==GL_TEXTURE_WRAP_S) {if (texture->wrap_s == param) return; texture->wrap_s = param; }
        if (pname==GL_TEXTURE_WRAP_T) {if (texture->wrap_t == param) return; texture->wrap_t = param; }
        break;
    case GL_TEXTURE_WRAP_R:
        // ignore it on GLES...
        return;
    case GL_TEXTURE_COMPARE_MODE:
        texture->compare = param;   // TODO, better traking...
        return;
    case GL_TEXTURE_MAX_LEVEL:
        if (texture)
            texture->max_level = param;
        return;			// not on GLES
    case GL_TEXTURE_BASE_LEVEL:
        texture->base_level = param;
        return;			// not on GLES
    case GL_TEXTURE_MIN_LOD:
    case GL_TEXTURE_MAX_LOD:
    case GL_TEXTURE_LOD_BIAS:
        return;			// not on GLES
    case GL_GENERATE_MIPMAP:
        if(globals4es.automipmap==3)
            return; // no mipmap, so no need to generate any
        if(texture->mipmap_auto == ((param)?1:0))
            return; // same value...
        texture->mipmap_auto = (param)?1:0;
        if(hardext.esversion>1) {
            if(texture->valid) {
                // force regeneration, if posssible
                if(glstate->list.pending) flush();
                realize_bound(glstate->texture.active, target);
                LOAD_GLES2_OR_OES(glGenerateMipmap);
                gl4es_glGenerateMipmap(rtarget);
            }
            return;
        }
        break;  // fallback to calling actual glTexParameteri
    case GL_TEXTURE_MAX_ANISOTROPY:
        if(!hardext.aniso) {
            errorShim(GL_INVALID_ENUM);
            return;
        }
        if(param<0){
            errorShim(GL_INVALID_VALUE);
            return;
        }
        if(param>hardext.aniso) param=hardext.aniso;
        texture->aniso = param;
        break;
    }
    if(glstate->list.pending) flush();
    realize_bound(glstate->texture.active, target);
    gles_glTexParameteri(rtarget, pname, param);
    errorGL();
}

void gl4es_glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
    gl4es_glTexParameteri(target, pname, param);
}

void gl4es_glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    DBG(printf("glTexParameterfv(%s, %s, %p {%f...})\n", PrintEnum(target), PrintEnum(pname), params, params[0]);)
    switch (pname) {
    case GL_TEXTURE_MIN_FILTER:
    case GL_TEXTURE_MAG_FILTER:
    case GL_TEXTURE_WRAP_S:
    case GL_TEXTURE_WRAP_T:
    case GL_TEXTURE_WRAP_R:
    case GL_TEXTURE_COMPARE_MODE:
    case GL_TEXTURE_MAX_LEVEL:
    case GL_TEXTURE_BASE_LEVEL:
    case GL_TEXTURE_MIN_LOD:
    case GL_TEXTURE_MAX_LOD:
    case GL_TEXTURE_LOD_BIAS:
    case GL_GENERATE_MIPMAP:
    case GL_TEXTURE_MAX_ANISOTROPY:
        gl4es_glTexParameteri(target, pname, params[0]);
        return;
    case GL_TEXTURE_BORDER_COLOR:
        // not supported on GLES,
        noerrorShim();
        return;
    }
    PUSH_IF_COMPILING(glTexParameterfv);
    realize_bound(glstate->texture.active, target);
    LOAD_GLES(glTexParameterfv);
    errorGL();
    const GLuint rtarget = map_tex_target(target);
    gles_glTexParameterfv(rtarget, pname, params);

}

void gl4es_glTexParameteriv(GLenum target, GLenum pname, const GLint * params) {
    DBG(printf("glTexParameteriv(%s, %s, %p {%d...})\n", PrintEnum(target), PrintEnum(pname), params, params[0]);)
    switch (pname) {
    case GL_TEXTURE_MIN_FILTER:
    case GL_TEXTURE_MAG_FILTER:
    case GL_TEXTURE_WRAP_S:
    case GL_TEXTURE_WRAP_T:
    case GL_TEXTURE_WRAP_R:
    case GL_TEXTURE_COMPARE_MODE:
    case GL_TEXTURE_MAX_LEVEL:
    case GL_TEXTURE_BASE_LEVEL:
    case GL_TEXTURE_MIN_LOD:
    case GL_TEXTURE_MAX_LOD:
    case GL_TEXTURE_LOD_BIAS:
    case GL_GENERATE_MIPMAP:
    case GL_TEXTURE_MAX_ANISOTROPY:
        gl4es_glTexParameteri(target, pname, params[0]);
        return;
    case GL_TEXTURE_BORDER_COLOR:
        // not supported on GLES,
        noerrorShim();
        return;
    }
    PUSH_IF_COMPILING(glTexParameteriv);
    realize_bound(glstate->texture.active, target);
    LOAD_GLES(glTexParameteriv);
    errorGL();
    const GLuint rtarget = map_tex_target(target);
    gles_glTexParameteriv(rtarget, pname, params);
}

void gl4es_glDeleteTextures(GLsizei n, const GLuint *textures) {
    DBG(printf("glDeleteTextures(%d, %p {%d...})\n", n, textures, n?textures[0]:-1);)
    if(!glstate) return;
    FLUSH_BEGINEND;
    
    noerrorShim();
    LOAD_GLES(glDeleteTextures);
    khash_t(tex) *list = glstate->texture.list;
    if (list) {
        khint_t k;
        gltexture_t *tex;
        for (int i = 0; i < n; i++) {
            GLuint t = textures[i];
            if(!t) continue;    // skip texture 0
            k = kh_get(tex, list, t);
            if (k != kh_end(list)) {
                tex = kh_value(list, k);
                int a;
                for (a=0; a<MAX_TEX; a++) {
                    int found=0;
                    for (int j=0; j<ENABLED_TEXTURE_LAST; j++)
                        if (tex == glstate->texture.bound[a][j]) {
                            glstate->texture.bound[a][j] = glstate->texture.zero;
                            found = 1;
                        }
                    if(glstate->actual_tex2d[a]==tex->glname) {
                        glstate->actual_tex2d[a] = 0;
                        found = 1;
                    }
                    if(found)
                        glstate->bound_changed = a+1;
                }
                gles_glDeleteTextures(1, &tex->glname);
                // check if renderbuffer where associeted
                if(tex->binded_fbo) {
                    if(tex->renderdepth)
                        gl4es_glDeleteRenderbuffers(1, &tex->renderdepth);
                    if(tex->renderstencil)
                        gl4es_glDeleteRenderbuffers(1, &tex->renderstencil);
                }
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
    DBG(printf("glGenTextures(%d, %p)\n", n, textures);)
    if (n<=0) 
        return;
    if (glstate->list.pending) flush();
    LOAD_GLES(glGenTextures);
    gles_glGenTextures(n, textures);
    errorGL();
    // now, add all the textures to the list
    int ret;
    khint_t k;
    khash_t(tex) *list = glstate->texture.list;
    
    for (int i=0; i<n; i++) {
        k = kh_get(tex, list, textures[i]);
        DBG(printf(" -> textures[%d] = %u\n", i, textures[i]);)
        gltexture_t *tex = NULL;
        if (k == kh_end(list)){
            k = kh_put(tex, list, textures[i], &ret);
            tex = kh_value(list, k) = malloc(sizeof(gltexture_t));
            memset(tex, 0, sizeof(gltexture_t));
            tex->texture = textures[i];
            tex->glname = textures[i];
            tex->adjustxy[0] = tex->adjustxy[1] = 1.f;
            tex->mipmap_auto = (globals4es.automipmap==1);
            tex->mipmap_need = (globals4es.automipmap==1)?1:0;
            tex->streamingID = -1;
            tex->base_level = -1;
            tex->max_level = -1;
            tex->alpha = true;
            tex->min_filter = GL_NEAREST_MIPMAP_LINEAR; //(globals4es.automipmap==1)?GL_NEAREST_MIPMAP_LINEAR:GL_LINEAR;
            tex->mag_filter = GL_LINEAR;
            tex->wrap_s = tex->wrap_t = (globals4es.defaultwrap?0:GL_REPEAT);
            tex->fpe_format = FPE_TEX_RGBA;
            tex->format = GL_RGBA;
            tex->type = GL_UNSIGNED_BYTE;
            tex->inter_format = GL_RGBA;
            tex->inter_type = GL_UNSIGNED_BYTE;
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
    DBG(printf("glGetTexLevelParameteriv(%s, %d, %s, %p)\n", PrintEnum(target), level, PrintEnum(pname), params);)
    // simplification: (mostly) not taking "target" into account here
    if (glstate->list.pending) flush();
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
                (*params) = nlevel((bound)?bound->width:hardext.maxsize,level);
                if(level && !(bound->mipmap_auto || bound->mipmap_need))
                    (*params) = 0;   // Mipmap level not loaded
            }
            break;
        case GL_TEXTURE_HEIGHT: 
            if (rtarget==GL_PROXY_TEXTURE_2D)
                (*params) = nlevel(proxy_height,level);
            else {
                (*params) = nlevel((bound)?bound->height:hardext.maxsize,level); 
                if(level && !(bound->mipmap_auto || bound->mipmap_need))
                    (*params) = 0;   // Mipmap level not loaded
            }
            break;
        case GL_TEXTURE_INTERNAL_FORMAT:
            if (rtarget==GL_PROXY_TEXTURE_2D)
                (*params) = proxy_intformat;
            else {
                if (bound->compressed)
                    (*params) = bound->internalformat;
                else {
                    if((bound->orig_internal==GL_COMPRESSED_RGB) || (bound->orig_internal==GL_COMPRESSED_RGBA)) {
                        if(bound->orig_internal==GL_COMPRESSED_RGB)
                            *(params) = GL_COMPRESSED_RGB_S3TC_DXT1_EXT;
                        else
                            *(params) = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
                    } else
                        (*params) = bound->internalformat;
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
            if (bound->compressed)
                (*params) = GL_TRUE;
            else {
                if((bound->orig_internal==GL_COMPRESSED_RGB) || (bound->orig_internal==GL_COMPRESSED_RGBA))
                    (*params) = GL_TRUE;
                else
                    (*params) = GL_FALSE;
            }
            break;
        case GL_TEXTURE_COMPRESSED_IMAGE_SIZE:
            if((bound->orig_internal==GL_COMPRESSED_RGB) || (bound->orig_internal==GL_COMPRESSED_RGBA)) {
                int w = nlevel((bound->width>>level),2); //DXT works on 4x4 blocks...
                int h = nlevel((bound->height>>level),2);
                w<<=2; h<<=2;
                if (bound->orig_internal==GL_COMPRESSED_RGB) //DXT1, 64bits (i.e. size=8) for a 4x4 block
                    (*params) = (w*h)/2;
                else    //DXT5, 64+64 (i.e. size = 16) for a 4x4 block
                    (*params) = w*h;
            } else
             (*params) = bound->width*bound->height*4;
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
            (*params) = (bound->orig_internal==GL_LUMINANCE || bound->orig_internal==GL_LUMINANCE_ALPHA)?8:0;
            break;
        case GL_TEXTURE_MAX_ANISOTROPY:
            if(!hardext.aniso)
                errorShim(GL_INVALID_ENUM);
            else
                (*params) = bound->aniso;
            break;
        case GL_TEXTURE_MAX_LEVEL:
            if(!bound->valid || bound->max_level==-1)
                (*params) = 1000;
            else
                (*params) = bound->max_level;
            break;
        case GL_TEXTURE_WRAP_S:
            if(!bound->valid)
                (*params) = GL_REPEAT;
            else
                (*params) = bound->wrap_s?bound->wrap_s:GL_REPEAT;
            break;
        case GL_TEXTURE_WRAP_T:
            if(!bound->valid)
                (*params) = GL_REPEAT;
            else
                (*params) = bound->wrap_t?bound->wrap_t:GL_REPEAT;
            break;
        case GL_TEXTURE_COMPARE_MODE:
                (*params) = bound->compare;  // GL_NONE is 0x0
            break;
        default:
            errorShim(GL_INVALID_ENUM);	//Wrong here...
            printf("Stubbed glGetTexLevelParameteriv(%s, %i, %s, %p)\n", PrintEnum(target), level, PrintEnum(pname), params);
    }
}

void gl4es_glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid * img) {
    DBG(printf("glGetTexImage(%s, %i, %s, %s, %p)\n", PrintEnum(target), level, PrintEnum(format), PrintEnum(type), img);)
    if (glstate->list.pending) {
        flush();
    }
    const GLuint itarget = what_target(target);    

    realize_bound(glstate->texture.active, target);
       
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
        return;
    }
    
    if (target!=GL_TEXTURE_2D) {
        return;
    }

    DBG(printf("glGetTexImage(%s, %i, %s, %s, 0x%p), texture=0x%x, size=%i,%i\n", PrintEnum(target), level, PrintEnum(format), PrintEnum(type), img, bound->glname, width, height);)
    
    GLvoid *dst = img;
    if (glstate->vao->pack)
        dst += (uintptr_t)glstate->vao->pack->data;
#ifdef TEXSTREAM
    if (globals4es.texstream && bound->streamed) {
        noerrorShim();
        pixel_convert(GetStreamingBuffer(bound->streamingID), &dst, width, height, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, format, type, 0, glstate->texture.unpack_align);
        readfboEnd();
        return;
    }
#endif
    if (globals4es.texcopydata && bound->data) {
        //printf("texcopydata* glGetTexImage(0x%04X, %d, 0x%04x, 0x%04X, %p)\n", target, level, format, type, img);
        noerrorShim();
        if (!pixel_convert(bound->data, &dst, width, height, GL_RGBA, GL_UNSIGNED_BYTE, format, type, 0, glstate->texture.pack_align))
            printf("LIBGL: Error on pixel_convert while glGetTexImage\n");
    } else {
        // Setup an FBO the same size of the texture
        GLuint oldBind = bound->glname;
        GLuint old_fbo = glstate->fbo.current_fb->id;
        GLuint fbo;
    
        // if the texture is not RGBA or RGB or ALPHA, the "just attach texture to the fbo" trick will not work, and a full Blit has to be done
        if((bound->format==GL_RGBA || bound->format==GL_RGB || (bound->format==GL_BGRA && hardext.bgra8888) || bound->format==GL_ALPHA) && (shrink==0)) {
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
            gl4es_glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
            gl4es_glClear(GL_COLOR_BUFFER_BIT);
            gl4es_blitTexture(oldBind, 0.f, 0.f, width, height, nwidth, nheight, 1.0f, 1.0f, nwidth<<shrink, nheight<<shrink, 0, 0, BLIT_OPAQUE);
            // Read the pixels!
            gl4es_glReadPixels(0, (nheight-height)<<shrink, width<<shrink, height<<shrink, format, type, img);	// using "full" version with conversion of format/type
            gl4es_glBindFramebuffer(GL_FRAMEBUFFER_OES, old_fbo);
            gl4es_glDeleteFramebuffers(1, &fbo);
            gl4es_glDeleteTextures(1, &temptex);
            noerrorShim();
        }
    }
}

void gl4es_glActiveTexture( GLenum texture ) {
    DBG(printf("glActiveTexture(%s)\n", PrintEnum(texture));)
    int tmu = texture - GL_TEXTURE0;
    if (glstate->list.pending) {
 /*       if(glstate->texture.active == tmu) {
            noerrorShim();
            return;
        }
        flush();*/
    } else if (glstate->list.active) {
        NewStage(glstate->list.active, STAGE_ACTIVETEX);
        rlActiveTexture(glstate->list.active, texture);
        return;
    }
 
    if ((tmu<0) || (tmu>=hardext.maxtex)) {
        errorShim(GL_INVALID_ENUM);
        return;
    }
    if(glstate->texture.active == tmu) {
        noerrorShim();
        return;
    }
    glstate->texture.active = tmu;
    noerrorShim();
}

void gl4es_glClientActiveTexture( GLenum texture ) {
    DBG(printf("glClientActiveTexture(%s)\n", PrintEnum(texture));)
    int tmu = texture - GL_TEXTURE0;
    if ((tmu<0) || (tmu >= hardext.maxtex)) {
        errorShim(GL_INVALID_ENUM);
    return;
    }
    // try to speed-up things...
    if (glstate->texture.client == tmu)
        return;
    if (glstate->list.pending) flush();
    glstate->texture.client = tmu;
    LOAD_GLES_FPE(glClientActiveTexture);
    gles_glClientActiveTexture(texture);
    errorGL();
}

void gl4es_glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid * data) {
    DBG(printf("glReadPixels(%i, %i, %i, %i, %s, %s, 0x%p)\n", x, y, width, height, PrintEnum(format), PrintEnum(type), data);)
    if (glstate->list.pending) {
        flush();
    }
    if (glstate->list.compiling && glstate->list.active) {
        errorShim(GL_INVALID_OPERATION);
        return;	// never in list
    }
    LOAD_GLES(glReadPixels);
    errorGL();
    GLvoid* dst = data;
    if (glstate->vao->pack)
        dst += (uintptr_t)glstate->vao->pack->data;
        
    readfboBegin();
    if ((format == GL_RGBA && type == GL_UNSIGNED_BYTE)     // should not use default GL_RGBA on Pandora as it's very slow...
       || (format == glstate->readf && type == glstate->readt)    // use the IMPLEMENTATION_READ too...
       || (format == GL_DEPTH_COMPONENT && (type == GL_FLOAT || type==GL_HALF_FLOAT)))   // this one will probably fail, as DEPTH is not readable on most GLES hardware 
    {
        // easy passthru
        gles_glReadPixels(x, y, width, height, format, type, dst);
        readfboEnd();
        return;
    }
    // grab data in GL_RGBA format
    int use_bgra = 0;
    if(glstate->readf==GL_BGRA && glstate->readt==GL_UNSIGNED_BYTE)
        use_bgra = 1;   // if IMPLEMENTATION_READ is BGRA, then use it as it's probably faster then RGBA.
    GLvoid *pixels = malloc(width*height*4);
    gles_glReadPixels(x, y, width, height, use_bgra?GL_BGRA:GL_RGBA, GL_UNSIGNED_BYTE, pixels);
    if (! pixel_convert(pixels, &dst, width, height,
                        use_bgra?GL_BGRA:GL_RGBA, GL_UNSIGNED_BYTE, format, type, 0,glstate->texture.pack_align)) {
        LOGE("LIBGL: ReadPixels error: (%s, UNSIGNED_BYTE -> %s, %s )\n",
            PrintEnum(use_bgra?GL_BGRA:GL_RGBA), PrintEnum(format), PrintEnum(type));
    }
    free(pixels);
    readfboEnd();
    return;
}

void gl4es_glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset,
                                GLint x, GLint y, GLsizei width, GLsizei height) {
    const GLuint itarget = what_target(target);
    // WARNING: It seems glColorMask has an impact on what channel are actualy copied by this. The crude glReadPixel / glTexSubImage cannot emulate that, and proper emulation will take need 2 read pixels.
    //  And using the real glCopyTexSubImage2D needs that the FrameBuffer were data are read is compatible with the Texture it's copied to...
    DBG(printf("glCopyTexSubImage2D(%s, %i, %i, %i, %i, %i, %i, %i), bounded texture=%u format/type=%s, %s\n", PrintEnum(target), level, xoffset, yoffset, x, y, width, height, (glstate->texture.bound[glstate->texture.active][itarget])?glstate->texture.bound[glstate->texture.active][itarget]->texture:0, PrintEnum((glstate->texture.bound[glstate->texture.active][itarget])?glstate->texture.bound[glstate->texture.active][itarget]->format:0), PrintEnum((glstate->texture.bound[glstate->texture.active][itarget])?glstate->texture.bound[glstate->texture.active][itarget]->type:0));)
    // PUSH_IF_COMPILING(glCopyTexSubImage2D);
    if (glstate->list.pending) {
        flush();
    }
 
    LOAD_GLES(glCopyTexSubImage2D);
    errorGL();
    realize_bound(glstate->texture.active, target);
    
    // "Unmap" if buffer mapped...
    glbuffer_t *pack = glstate->vao->pack;
    glbuffer_t *unpack = glstate->vao->unpack;
    glstate->vao->pack = NULL;
    glstate->vao->unpack = NULL;

    readfboBegin(); // multiple readfboBegin() can be chained...

    gltexture_t* bound = glstate->texture.bound[glstate->texture.active][itarget];
#ifdef TEXSTREAM
    if (bound->streamed) {
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
        int copytex = 0;
        if(glstate->fbo.current_fb->read_type==0) {
            LOAD_GLES(glGetIntegerv);
            gles_glGetIntegerv(GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES, &glstate->fbo.current_fb->read_format);
            gles_glGetIntegerv(GL_IMPLEMENTATION_COLOR_READ_TYPE_OES, &glstate->fbo.current_fb->read_type);
        }
        copytex = ((bound->format==GL_RGBA && bound->type==GL_UNSIGNED_BYTE) 
            || (bound->format==glstate->fbo.current_fb->read_format && bound->type==glstate->fbo.current_fb->read_type));
        if (copytex || !glstate->colormask[0] || !glstate->colormask[1] || !glstate->colormask[2] || !glstate->colormask[3]) {
            gles_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
        } else {
            void* tmp = malloc(width*height*4);
            GLenum format = bound->format;
            GLenum type = bound->type;
            gl4es_glReadPixels(x, y, width, height, format, type, tmp);
            gl4es_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, tmp);
            free(tmp);
        }
    }
    readfboEnd();
    // "Remap" if buffer mapped...
    glstate->vao->pack = pack;
    glstate->vao->unpack = unpack;
}


void gl4es_glCopyTexImage2D(GLenum target,  GLint level,  GLenum internalformat,  GLint x,  GLint y,  
                                GLsizei width,  GLsizei height,  GLint border) {
    DBG(printf("glCopyTexImage2D(%s, %i, %s, %i, %i, %i, %i, %i), glstate->fbo.current_fb=%u\n", PrintEnum(target), level, PrintEnum(internalformat), x, y, width, height, border, glstate->fbo.current_fb);)
     //PUSH_IF_COMPILING(glCopyTexImage2D);
    if (glstate->list.pending) {
        flush();
    }
    const GLuint itarget = what_target(target);

    // actualy bound if targetting shared TEX2D
    realize_bound(glstate->texture.active, target);

    errorGL();

    // "Unmap" if buffer mapped...
    glbuffer_t *pack = glstate->vao->pack;
    glbuffer_t *unpack = glstate->vao->unpack;
    glstate->vao->pack = NULL;
    glstate->vao->unpack = NULL;
    
    readfboBegin(); // multiple readfboBegin() can be chained...
    realize_bound(glstate->texture.active, target);
    gltexture_t* bound = glstate->texture.bound[glstate->texture.active][itarget];

    if(glstate->fbo.current_fb->read_type==0) {
        LOAD_GLES(glGetIntegerv);
        gles_glGetIntegerv(GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES, &glstate->fbo.current_fb->read_format);
        gles_glGetIntegerv(GL_IMPLEMENTATION_COLOR_READ_TYPE_OES, &glstate->fbo.current_fb->read_type);
    }
    int copytex = ((bound->format==GL_RGBA && bound->type==GL_UNSIGNED_BYTE) 
        || (bound->format==glstate->fbo.current_fb->read_format && bound->type==glstate->fbo.current_fb->read_type));

    if (copytex) {
        LOAD_GLES(glCopyTexImage2D);
        gles_glCopyTexImage2D(target, level, GL_RGB, x, y, width, height, border);
    } else {
        void* tmp = malloc(width*height*4);
        gl4es_glReadPixels(x, y, width, height, GL_RGBA, GL_UNSIGNED_BYTE, tmp);
        gl4es_glTexImage2D(target, level, internalformat, width, height, border, GL_RGBA, GL_UNSIGNED_BYTE, tmp);
        free(tmp);
    }
    
    readfboEnd();
    // "Remap" if buffer mapped...
    glstate->vao->pack = pack;
    glstate->vao->unpack = unpack;
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
        case GL_RGB565:
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
        proxy_width = (width>hardext.maxsize)?0:width;
        proxy_height = (height>hardext.maxsize)?0:height;
        return;
    }
     if (glstate->list.pending) {
         flush();
     }

    // actualy bound if targetting shared TEX2D
    realize_bound(glstate->texture.active, target);

    gltexture_t* bound = glstate->texture.bound[glstate->texture.active][itarget]; 
    DBG(printf("glCompressedTexImage2D on target=%s with size(%i,%i), internalformat=%s, imagesize=%i, upackbuffer=%p data=%p\n", PrintEnum(target), width, height, PrintEnum(internalformat), imageSize, glstate->vao->unpack?glstate->vao->unpack->data:0, data);)
    // hack...
    if (internalformat==GL_RGBA8)
        internalformat = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
    // test if internalformat is not a compressed one
    if ((width<=0) || (height<=0)) {
        noerrorShim();
        return; // nothing to do...
    }
    
    glbuffer_t *unpack = glstate->vao->unpack;
    glstate->vao->unpack = NULL;
    GLvoid *datab = (GLvoid*)data;
    if (unpack)
        datab += (uintptr_t)unpack->data;
    
    GLenum format = GL_RGBA;
    GLenum type = GL_UNSIGNED_BYTE;
        
    if (isDXTc(internalformat)) {
        GLvoid *pixels, *half;
        pixels = half = NULL;
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
            }
        }
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
            if(!globals4es.nodownsampling && !globals4es.avoid16bits) {
                if (!pixel_convert(pixels, &half, width, height, GL_RGBA, GL_UNSIGNED_BYTE, format, type, 0, glstate->texture.unpack_align)) {
                    format = GL_RGBA;
                    type = GL_UNSIGNED_BYTE;
                }
            }
        }
        int oldalign;
        gl4es_glGetIntegerv(GL_UNPACK_ALIGNMENT, &oldalign);
        if (oldalign!=1) 
            gl4es_glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        gl4es_glTexImage2D(rtarget, level, format==GL_RGBA?GL_COMPRESSED_RGBA:GL_COMPRESSED_RGB, width, height, border, format, type, half);
        // re-update bounded texture info
        bound->alpha = (internalformat==GL_COMPRESSED_RGB_S3TC_DXT1_EXT)?false:true;
        bound->format = format; //internalformat;
        bound->type = type;
        bound->compressed = true;
        bound->internalformat = internalformat;
        bound->valid = 1;
        if (oldalign!=1) 
            gl4es_glPixelStorei(GL_UNPACK_ALIGNMENT, oldalign);
        if (half!=pixels)
            free(half);
        if (pixels!=datab)
            free(pixels);
    } else {
        LOAD_GLES(glCompressedTexImage2D);
        bound->alpha = true;
        bound->format = internalformat;
        bound->type = GL_UNSIGNED_BYTE;
        bound->internalformat = internalformat;
        bound->compressed = true;
        bound->valid = 1;
        realize_bound(glstate->texture.active, target);
        if (glstate->fpe_state && glstate->fpe_bound_changed < glstate->texture.active+1)
            glstate->fpe_bound_changed = glstate->texture.active+1;
        gles_glCompressedTexImage2D(rtarget, level, internalformat, width, height, border, imageSize, datab);
        errorGL();
    }
    glstate->vao->unpack = unpack;
}

void gl4es_glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset,
                               GLsizei width, GLsizei height, GLenum format, 
                               GLsizei imageSize, const GLvoid *data) 
{
    const GLuint itarget = what_target(target);
    if (glstate->list.pending) {
        flush();
    }

    // actualy bound if targetting shared TEX2D
    realize_bound(glstate->texture.active, target);

    gltexture_t *bound = glstate->texture.bound[glstate->texture.active][itarget];
    if (level != 0) {
        noerrorShim();
        //TODO
        //printf("STUBBED glCompressedTexSubImage2D with level=%i\n", level);
        return;
    }
    DBG(printf("glCompressedTexSubImage2D with unpack_row_length(%i), size(%i,%i), pos(%i,%i) and skip={%i,%i}, internalformat=%s, imagesize=%i, data=%p\n", glstate->texture.unpack_row_length, width, height, xoffset, yoffset, glstate->texture.unpack_skip_pixels, glstate->texture.unpack_skip_rows, PrintEnum(format), imageSize, data);)
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
        // if RGBA / DXT1, then RGB 000 needs to have 0 alpha too
        if(format==GL_COMPRESSED_RGBA_S3TC_DXT1_EXT) {
            GLuint *p = (GLuint*)pixels;
            for(int i=0; i<width*height; i++, p++)
                if(*p==0xff000000) *p=0;
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
        pixel_convert(pixels, &half, width, height, GL_RGBA, GL_UNSIGNED_BYTE, format, type, 0, glstate->texture.unpack_align);
        gl4es_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, half);
        #endif
        if (half!=pixels)
            free(half);
        if (pixels!=datab)
            free(pixels);
    } else {
        realize_bound(glstate->texture.active, target);        
        gles_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, datab);
    }
}

void gl4es_glGetCompressedTexImage(GLenum target, GLint lod, GLvoid *img) {
    if (glstate->list.pending) flush();

    const GLuint itarget = what_target(target); 
    gltexture_t* bound = glstate->texture.bound[glstate->texture.active][itarget];
    DBG(printf("glGetCompressedTexImage(%s, %i, %p), bound=%p, bound->orig_internal=%s\n", PrintEnum(target), lod, img, bound, (bound)?PrintEnum(bound->orig_internal):"nil");)
    errorShim(GL_INVALID_OPERATION);
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


// bind the correct texture on Tex2D or TEXCUBE mapper...
void realize_bound(int TMU, GLenum target) {
    LOAD_GLES(glBindTexture);
    gltexture_t *tex = glstate->texture.bound[TMU][what_target(target)];
    GLuint t = tex->glname;
    DBG(printf("realize_bound(%d, %s), glsate->actual_tex2d[%d]=%u / %u\n", TMU, PrintEnum(target), TMU, glstate->actual_tex2d[TMU], t);)
#ifdef TEXSTREAM
    LOAD_GLES(glEnable);
    LOAD_GLES(glDisable);
#endif
    switch (target) {
        case GL_TEXTURE_1D:
        case GL_TEXTURE_2D:
        case GL_TEXTURE_3D:
        case GL_TEXTURE_RECTANGLE_ARB:
#ifdef TEXSTREAM
            if(glstate->bound_stream[TMU]) {
                realize_active();
                gles_glDisable(GL_TEXTURE_STREAM_IMG);
                DeactivateStreaming();
                glstate->bound_stream[TMU] = 0;
            }
            int streamingID = tex->streamingID;
            if (globals4es.texstream && (streamingID>-1)) {
                if(hardext.esversion<2) gles_glDisable(GL_TEXTURE_2D);
                ActivateStreaming(streamingID);
                glstate->bound_stream[TMU] = 1;
                glstate->actual_tex2d[TMU] = t;
                if (hardext.esversion<2)
                    gles_glEnable(GL_TEXTURE_STREAM_IMG);
                if (glstate->bound_changed < TMU+1)
                    glstate->bound_changed = TMU+1;
            } else
#endif
            if(glstate->actual_tex2d[TMU] != t) {
                realize_active();
                gles_glBindTexture(GL_TEXTURE_2D, t);
                glstate->actual_tex2d[TMU] = t;
                if (glstate->bound_changed < TMU+1)
                    glstate->bound_changed = TMU+1;
            }
            break;
    }
    if (glstate->fpe_state && glstate->fpe_bound_changed < TMU+1)
    glstate->fpe_bound_changed = TMU+1;
}

void realize_active() {
    LOAD_GLES(glActiveTexture);
    if(glstate->gleshard->active == glstate->texture.active)
        return;
    glstate->gleshard->active = glstate->texture.active;
    gles_glActiveTexture(GL_TEXTURE0 + glstate->gleshard->active);
}

void realize_textures() {
    LOAD_GLES(glEnable);
    LOAD_GLES(glDisable);
    LOAD_GLES(glBindTexture);
    LOAD_GLES(glActiveTexture);
#ifdef TEXSTREAM
    DBG(printf("realize_textures(), glstate->bound_changed=%d, glstate->enable.texture[0]=%X glsate->actual_tex2d[0]=%u / glstate->bound_stream[0]=%u\n", glstate->bound_changed, glstate->enable.texture[0], glstate->actual_tex2d[0], glstate->bound_stream[0]);)
#else
    DBG(printf("realize_textures(), glstate->bound_changed=%d, glstate->enable.texture[0]=%X glsate->actual_tex2d[0]=%u\n", glstate->bound_changed, glstate->enable.texture[0], glstate->actual_tex2d[0]);)
#endif
    for (int i=0; i<glstate->bound_changed; i++) {
        // get highest priority texture unit
        int tmp = glstate->enable.texture[glstate->texture.active];
        int tgt = ENABLED_TEX2D; // default to TEX2D
        if(IS_TEX3D(tmp))
            tgt = ENABLED_TEX3D;
        else if(IS_TEXTURE_RECTANGLE(tmp))
            tgt = ENABLED_TEXTURE_RECTANGLE;
        else if(IS_TEX2D(tmp))
            tgt = ENABLED_TEX2D;
        else if(IS_TEX1D(tmp))
            tgt = ENABLED_TEX1D;
        else if(IS_CUBE_MAP(tmp))
            continue;   // CUBE MAP are immediatly bound
#ifdef TEXSTREAM
        if(glstate->bound_stream[i]) {
            realize_active();
            if(hardext.esversion<2) gles_glDisable(GL_TEXTURE_STREAM_IMG);
            DeactivateStreaming();
            glstate->bound_stream[i] = 0;
        }
#endif
        gltexture_t *tex = glstate->texture.bound[i][tgt];
        GLuint t = tex->glname;
        if (t!=glstate->actual_tex2d[i]
#ifdef TEXSTREAM
            || (glstate->bound_stream[i] != tex->streamed)
#endif
        ) {
            if(glstate->gleshard->active!=i) {
                glstate->gleshard->active = i;
                gles_glActiveTexture(GL_TEXTURE0+i);
            }
#ifdef TEXSTREAM
            int streamed = tex->streamed;
            int streamingID = tex->streamingID;
            if(glstate->bound_stream[i]) {
                if(hardext.esversion<2) gles_glDisable(GL_TEXTURE_STREAM_IMG);
                DeactivateStreaming();
                if(hardext.esversion<2) gles_glEnable(GL_TEXTURE_2D);
                glstate->bound_stream[i] = 0;
            }
            if (globals4es.texstream && (streamingID>-1)) {
                if (IS_ANYTEX(tmp) && hardext.esversion<2)
                    gles_glDisable(GL_TEXTURE_2D);
                ActivateStreaming(streamingID);
                glstate->bound_stream[i] = 1;
                glstate->actual_tex2d[i] = t;
                if (IS_ANYTEX(tmp))
                    gles_glEnable(GL_TEXTURE_STREAM_IMG);
                continue;
            }
#endif

            // bound...
            gles_glBindTexture(GL_TEXTURE_2D, t);
            glstate->actual_tex2d[i] = t;
        }
    }
    glstate->bound_changed = 0;
}



//Direct wrapper
void glTexImage2D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *data) AliasExport("gl4es_glTexImage2D");
void glTexImage1D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *data) AliasExport("gl4es_glTexImage1D");
void glTexImage3D(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *data) AliasExport("gl4es_glTexImage3D");
void glTexImage3DEXT(GLenum target, GLint level, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const GLvoid *data) AliasExport("gl4es_glTexImage3D");
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
