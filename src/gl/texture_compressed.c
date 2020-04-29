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

//#define DEBUG
#ifdef DEBUG
#define DBG(a) a
#else
#define DBG(a)
#endif

static int inline nlevel(int size, int level) {
    if(size) {
        size>>=level;
        if(!size) size=1;
    }
    return size;
}

GLboolean isDXTc(GLenum format) {
    switch (format) {
        case GL_COMPRESSED_RGB_S3TC_DXT1_EXT:
        case GL_COMPRESSED_RGBA_S3TC_DXT1_EXT:
        case GL_COMPRESSED_RGBA_S3TC_DXT3_EXT:
        case GL_COMPRESSED_RGBA_S3TC_DXT5_EXT:
        case GL_COMPRESSED_SRGB_S3TC_DXT1_EXT:
        case GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT:
        case GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT:
        case GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT:
            return true;
    }
    return false;
}

GLboolean isDXTcSRGB(GLenum format) {
    switch (format) {
        case GL_COMPRESSED_SRGB_S3TC_DXT1_EXT:
        case GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT:
        case GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT:
        case GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT:
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

GLvoid *uncompressDXTc(GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, int transparent0, int* simpleAlpha, int* complexAlpha, const GLvoid *data) {
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
        case GL_COMPRESSED_SRGB_S3TC_DXT1_EXT:
        case GL_COMPRESSED_RGBA_S3TC_DXT1_EXT:
        case GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT:
            blocksize = 8;
            break;
        case GL_COMPRESSED_RGBA_S3TC_DXT3_EXT:
        case GL_COMPRESSED_RGBA_S3TC_DXT5_EXT:
        case GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT:
        case GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT:
            blocksize = 16;
            break;
    }
    uintptr_t src = (uintptr_t) data;
    for (int y=0; y<height; y+=4) {
        for (int x=0; x<width; x+=4) {
            switch(format) {
                case GL_COMPRESSED_RGB_S3TC_DXT1_EXT:
                case GL_COMPRESSED_RGBA_S3TC_DXT1_EXT:
                case GL_COMPRESSED_SRGB_S3TC_DXT1_EXT:
                case GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT:
                    DecompressBlockDXT1(x, y, width, (uint8_t*)src, transparent0, simpleAlpha, complexAlpha, pixels);
                    break;
                case GL_COMPRESSED_RGBA_S3TC_DXT3_EXT:
                case GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT:
                    DecompressBlockDXT3(x, y, width, (uint8_t*)src, transparent0, simpleAlpha, complexAlpha, pixels);
                    break;
                case GL_COMPRESSED_RGBA_S3TC_DXT5_EXT:
                case GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT:
                    DecompressBlockDXT5(x, y, width, (uint8_t*)src, transparent0, simpleAlpha, complexAlpha, pixels);
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
        glstate->proxy_width = (width>hardext.maxsize)?0:width;
        glstate->proxy_height = (height>hardext.maxsize)?0:height;
        return;
    }
    FLUSH_BEGINEND;

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
        bound->alpha = (internalformat==GL_COMPRESSED_RGB_S3TC_DXT1_EXT || internalformat==GL_COMPRESSED_SRGB_S3TC_DXT1_EXT)?false:true;
        if(globals4es.nodownsampling==1) {  // will be removed soon, avoid16bits is better
            format = GL_RGBA;
            type = GL_UNSIGNED_BYTE;
        } else {
            if(globals4es.avoid16bits) {
                format = GL_RGBA;
                type = GL_UNSIGNED_BYTE;
            } else {
                format = (internalformat==GL_COMPRESSED_RGB_S3TC_DXT1_EXT || internalformat==GL_COMPRESSED_SRGB_S3TC_DXT1_EXT)?GL_RGB:GL_RGBA;
                #ifdef PANDORA
                type = (internalformat==GL_COMPRESSED_RGB_S3TC_DXT1_EXT || internalformat==GL_COMPRESSED_SRGB_S3TC_DXT1_EXT)?GL_UNSIGNED_SHORT_5_6_5:((internalformat==GL_COMPRESSED_RGBA_S3TC_DXT1_EXT)?GL_UNSIGNED_SHORT_5_5_5_1:GL_UNSIGNED_SHORT_4_4_4_4);
                #else
                type = (internalformat==GL_COMPRESSED_RGB_S3TC_DXT1_EXT || internalformat==GL_COMPRESSED_SRGB_S3TC_DXT1_EXT)?GL_UNSIGNED_SHORT_5_6_5:GL_UNSIGNED_SHORT_4_4_4_4;
                #endif
            }
        }
        int srgb = isDXTcSRGB(internalformat);
        int simpleAlpha = 0;
        int complexAlpha = 0;
        int transparent0 = (internalformat==GL_COMPRESSED_RGBA_S3TC_DXT1_EXT || internalformat==GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT)?1:0;
        if (datab) {
            if (width<4 || height<4) {	// can happens :(
                GLvoid *tmp;
                GLsizei nw=width;
                GLsizei nh=height;
                if (nw<4) nw = 4;
                if (nh<4) nh = 4;
                tmp = uncompressDXTc(nw, nh, internalformat, imageSize, transparent0, &simpleAlpha, &complexAlpha, datab);
                pixels = malloc(4*width*height);
                // crop
                for (int y=0; y<height; y++)
                    memcpy(pixels+y*width*4, tmp+y*nw*4, width*4);
                free(tmp);
            } else {
                pixels = uncompressDXTc(width, height, internalformat, imageSize, transparent0, &simpleAlpha, &complexAlpha, datab);
            }
            if(srgb)
                pixel_srgb_inplace(pixels, width, height);
            // automaticaly reduce the pixel size
            half=pixels;
            if(!globals4es.nodownsampling && !globals4es.avoid16bits) {
                if(type!=GL_UNSIGNED_BYTE) {
                    // packed, recheck status of alpha & complex alpha...
                    if(simpleAlpha && !complexAlpha) {
                        format = GL_RGBA;
                        type = GL_UNSIGNED_SHORT_5_5_5_1;
                    } else if(complexAlpha) {
                        format = GL_RGBA;
                        type = GL_UNSIGNED_SHORT_4_4_4_4;
                    } else {
                        format = GL_RGB;
                        type = GL_UNSIGNED_SHORT_5_6_5;
                    }
                }
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
        gl4es_glTexImage2D(rtarget, level, (simpleAlpha||complexAlpha)?GL_COMPRESSED_RGBA:GL_COMPRESSED_RGB, width, height, border, format, type, half);
        // re-update bounded texture info
        bound->alpha = (simpleAlpha||complexAlpha)?1:0;
        bound->format = format;
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
    FLUSH_BEGINEND;

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
    int simpleAlpha = 0;
    int complexAlpha = 0;
    int transparent0 = (format==GL_COMPRESSED_RGBA_S3TC_DXT1_EXT || format==GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT)?1:0;
    if (isDXTc(format)) {
        int srgb = isDXTcSRGB(format);
        GLvoid *pixels;
        if (width<4 || height<4) {	// can happens :(
            GLvoid *tmp;
            GLsizei nw=width;
            GLsizei nh=height;
            if (nw<4) nw = 4;
            if (nh<4) nh = 4;
            tmp = uncompressDXTc(nw, nh, format, imageSize, transparent0, &simpleAlpha, &complexAlpha, datab);
            pixels = malloc(4*width*height);
            // crop
            for (int y=0; y<height; y++)
                memcpy(pixels+y*width*4, tmp+y*nw*4, width*4);
            free(tmp);
        } else {
            pixels = uncompressDXTc(width, height, format, imageSize, transparent0, &simpleAlpha, &complexAlpha, datab);
        }
        if(srgb)
            pixel_srgb_inplace(pixels, width, height);
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
        gles_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, datab);
    }
}

void gl4es_glGetCompressedTexImage(GLenum target, GLint lod, GLvoid *img) {
    //FLUSH_BEGINEND;   //no need on get

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
    int dxt1 = (bound->wanted_internal==GL_COMPRESSED_RGBA_S3TC_DXT1_EXT || bound->wanted_internal==GL_COMPRESSED_RGB_S3TC_DXT1_EXT)?1:0;   // Add SRGB variant?

    int ralpha = (alpha && !dxt1)?1:0;

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
                if(alpha && dxt1) {
                    // change transparent to RGB = 0
                    for (int i=0; i<16; ++i)
                        if(tmp[i]&0xff000000!=0xff000000)
                            tmp[i] = 0;
                }
            }
            stb_compress_dxt_block((unsigned char*)datab, (const unsigned char*)tmp, ralpha, STB_DXT_NORMAL);
            datab+=8*(ralpha+1);
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

//Direct wrapper
void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexImage2D");
void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexImage1D");
void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexImage3D");
void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexSubImage2D");
void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexSubImage1D");
void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexSubImage3D");
void glGetCompressedTexImage(GLenum target, GLint lod, GLvoid *img) AliasExport("gl4es_glGetCompressedTexImage");

//EXT mapper
void glCompressedTexImage2DEXT(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexImage2D");
void glCompressedTexImage1DEXT(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexImage1D");
void glCompressedTexImage3DEXT(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexImage3D");
void glCompressedTexSubImage2DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexSubImage2D");
void glCompressedTexSubImage1DEXT(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexSubImage1D");
void glCompressedTexSubImage3DEXT(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexSubImage3D");
void glGetCompressedTexImageEXT(GLenum target, GLint lod, GLvoid *img) AliasExport("gl4es_glGetCompressedTexImage");

//ARB mapper
void glCompressedTexImage2DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexImage2D");
void glCompressedTexImage1DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexImage1D");
void glCompressedTexImage3DARB(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexImage3D");
void glCompressedTexSubImage2DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexSubImage2D");
void glCompressedTexSubImage1DARB(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexSubImage1D");
void glCompressedTexSubImage3DARB(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const GLvoid *data) AliasExport("gl4es_glCompressedTexSubImage3D");
void glGetCompressedTexImageARB(GLenum target, GLint lod, GLvoid *img) AliasExport("gl4es_glGetCompressedTexImage");

