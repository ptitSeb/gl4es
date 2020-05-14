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
void tex_setup_texcoord(GLuint len, int changes, GLuint itarget, vertexattrib_t* ptr) {
    LOAD_GLES_FPE(glTexCoordPointer);
    GLuint texunit = glstate->texture.client;
    
    gltexture_t *bound = glstate->texture.bound[texunit][itarget];
    
    if (changes) {
        // first convert to GLfloat, without normalization
        if(glstate->helper_texlen[texunit]<len) {
            if(glstate->helper_tex[texunit]) free(glstate->helper_tex[texunit]);
            glstate->helper_tex[texunit] = malloc(4*sizeof(GLfloat)*len);
            glstate->helper_texlen[texunit] = len;
        }
        copy_gl_pointer_tex_noalloc(glstate->helper_tex[texunit], ptr, 4, 0, len);
        // Normalize if needed
        if (itarget == ENABLED_TEXTURE_RECTANGLE)
            tex_coord_rect_arb(glstate->helper_tex[texunit], 4, len, bound->width, bound->height);
        // Apply transformation matrix if any
        if (!(globals4es.texmat || glstate->texture_matrix[texunit]->identity))
            tex_coord_matrix(glstate->helper_tex[texunit], len, getTexMat(texunit));
        // NPOT adjust
        if (bound->adjust)
            tex_coord_npot(glstate->helper_tex[texunit], len, bound->width, bound->height, bound->nwidth, bound->nheight);
        // All done, setup the texcoord array now
        gles_glTexCoordPointer(4, GL_FLOAT, 0, glstate->helper_tex[texunit]);
    } else {
        gles_glTexCoordPointer(ptr->size, ptr->type, ptr->stride, ptr->pointer);
    }
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
        if (glstate->texture.bound[glstate->texture.active][itarget] == tex)
            return;
        
        FLUSH_BEGINEND;
        tex_changed = glstate->texture.active+1;
        glstate->texture.bound[glstate->texture.active][itarget] = tex;

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
        if (pname==GL_TEXTURE_MIN_FILTER) { texture->wanted_min = param; }
        if (pname==GL_TEXTURE_MAG_FILTER) { texture->wanted_mag = param; }
        switch (param) {
        case GL_NEAREST_MIPMAP_NEAREST:
        case GL_NEAREST_MIPMAP_LINEAR:
        case GL_LINEAR_MIPMAP_NEAREST:
        case GL_LINEAR_MIPMAP_LINEAR:
            texture->mipmap_need = true;
            if ((globals4es.automipmap==3) || ((globals4es.automipmap==1) && (texture->mipmap_auto==0)) || (texture->compressed && (texture->mipmap_auto==0)))
            switch (param) {
                case GL_NEAREST_MIPMAP_NEAREST:
                case GL_NEAREST_MIPMAP_LINEAR:
                    texture->mipmap_need = false;
                    param = GL_NEAREST;
                    break;
                case GL_LINEAR_MIPMAP_NEAREST:
                case GL_LINEAR_MIPMAP_LINEAR:
                    texture->mipmap_need = false;
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
        if(hardext.esversion>1 && param) {
            if(texture->valid) {
                // force regeneration, if possible
                FLUSH_BEGINEND;
                realize_bound(glstate->texture.active, target);
                LOAD_GLES2_OR_OES(glGenerateMipmap);
                gl4es_glGenerateMipmap(rtarget);
                if(texture->wanted_min != texture->min_filter)
                    gl4es_glTexParameteri(target, GL_TEXTURE_MIN_FILTER, texture->wanted_min);
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
    FLUSH_BEGINEND;
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
    FLUSH_BEGINEND;
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
            tex->wanted_min = tex->min_filter = GL_NEAREST_MIPMAP_LINEAR; //(globals4es.automipmap==1)?GL_NEAREST_MIPMAP_LINEAR:GL_LINEAR;
            tex->wanted_mag = tex->mag_filter = GL_LINEAR;
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
    FLUSH_BEGINEND;
    *params = 0;
    noerrorShim();
    const GLuint itarget = what_target(target);
    const GLuint rtarget = map_tex_target(target);
    gltexture_t* bound = glstate->texture.bound[glstate->texture.active][itarget];
    switch (pname) {
        case GL_TEXTURE_WIDTH:
            if (rtarget==GL_PROXY_TEXTURE_2D)
                (*params) = nlevel(glstate->proxy_width,level);
            else {
                (*params) = nlevel((bound)?bound->width:hardext.maxsize,level);
                if(level && !(bound->mipmap_auto || bound->mipmap_need))
                    (*params) = 0;   // Mipmap level not loaded
            }
            break;
        case GL_TEXTURE_HEIGHT: 
            if (rtarget==GL_PROXY_TEXTURE_2D)
                (*params) = nlevel(glstate->proxy_height,level);
            else {
                (*params) = nlevel((bound)?bound->height:hardext.maxsize,level); 
                if(level && !(bound->mipmap_auto || bound->mipmap_need))
                    (*params) = 0;   // Mipmap level not loaded
            }
            break;
        case GL_TEXTURE_INTERNAL_FORMAT:
            if (rtarget==GL_PROXY_TEXTURE_2D)
                (*params) = glstate->proxy_intformat;
            else {
                if (bound->compressed)
                    (*params) = bound->internalformat;
                else {
                    if(bound->wanted_internal==GL_COMPRESSED_RGBA_S3TC_DXT1_EXT)
                        *params = bound->wanted_internal;
                    else
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
                if (bound->orig_internal==GL_COMPRESSED_RGB || bound->wanted_internal==GL_COMPRESSED_RGBA_S3TC_DXT1_EXT) //DXT1, 64bits (i.e. size=8) for a 4x4 block
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
        case GL_TEXTURE_MIN_FILTER:
            *params = bound->wanted_min;
            break;
        case GL_TEXTURE_MAG_FILTER:
            *params = bound->wanted_mag;
            break;
        case GL_TEXTURE_COMPARE_MODE:
                (*params) = bound->compare;  // GL_NONE is 0x0
            break;
        default:
            errorShim(GL_INVALID_ENUM);	//Wrong here...
            printf("Stubbed glGetTexLevelParameteriv(%s, %i, %s, %p)\n", PrintEnum(target), level, PrintEnum(pname), params);
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
        gl4es_flush();*/
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
    FLUSH_BEGINEND;
    glstate->texture.client = tmu;
    LOAD_GLES_FPE(glClientActiveTexture);
    gles_glClientActiveTexture(texture);
    errorGL();
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

// bind the correct texture on Tex2D or TEXCUBE mapper...
void realize_bound(int TMU, GLenum target) {
    realize_active();
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

void realize_textures(int drawing) {
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
            // check, if drawing, if mipmap needs some special care...
            if(drawing && tex->mipmap_need && !tex->mipmap_done) {
                LOAD_GLES2_OR_OES(glGenerateMipmap);
                gles_glGenerateMipmap(GL_TEXTURE_2D);
                tex->mipmap_done = 1;
                tex->mipmap_auto = 1;
            }
        }
    }
    glstate->bound_changed = 0;
}

//Direct wrapper
void glBindTexture(GLenum target, GLuint texture) AliasExport("gl4es_glBindTexture");
void glGenTextures(GLsizei n, GLuint * textures) AliasExport("gl4es_glGenTextures");
void glDeleteTextures(GLsizei n, const GLuint * textures) AliasExport("gl4es_glDeleteTextures");
void glTexParameteri(GLenum target, GLenum pname, GLint param) AliasExport("gl4es_glTexParameteri");
void glTexParameterf(GLenum target, GLenum pname, GLfloat param) AliasExport("gl4es_glTexParameterf");
void glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params) AliasExport("gl4es_glTexParameterfv");
void glTexParameteriv(GLenum target, GLenum pname, const GLint * params) AliasExport("gl4es_glTexParameteriv");
void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params) AliasExport("gl4es_glGetTexLevelParameteriv");
GLboolean glAreTexturesResident(GLsizei n, const GLuint *textures, GLboolean *residences) AliasExport("gl4es_glAreTexturesResident");
void glActiveTexture( GLenum texture ) AliasExport("gl4es_glActiveTexture");
void glClientActiveTexture( GLenum texture ) AliasExport("gl4es_glClientActiveTexture");
void glPixelStorei(GLenum pname, GLint param) AliasExport("gl4es_glPixelStorei");

//ARB mapper
void glActiveTextureARB(GLenum texture) AliasExport("gl4es_glActiveTexture");
void glClientActiveTextureARB(GLenum texture) AliasExport("gl4es_glClientActiveTexture");
