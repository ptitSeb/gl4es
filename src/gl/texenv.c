#include "texenv.h"
#include "debug.h"
#include "../glx/hardext.h"

void gl4es_glTexEnvf(GLenum target, GLenum pname, GLfloat param) {
    LOAD_GLES(glTexEnvf);
    PUSH_IF_COMPILING(glTexEnvf);
    // Handling GL_EXT_DOT3, wrapping to standard dot3 (???)
    if(param==GL_DOT3_RGB_EXT) param=GL_DOT3_RGB;
    if(param==GL_DOT3_RGBA_EXT) param=GL_DOT3_RGBA;
    noerrorShim();
    switch(target) {
        case GL_POINT_SPRITE:
            if(pname==GL_COORD_REPLACE) {
                int p = (param!=0.0f)?1:0;
                if (glstate->texture.pscoordreplace[glstate->texture.active] == p)
                    return;
                glstate->texture.pscoordreplace[glstate->texture.active] = p;
            } else {
                errorShim(GL_INVALID_ENUM);
                return;
            }
            break;
        case GL_TEXTURE_FILTER_CONTROL:
            if(pname==GL_TEXTURE_LOD_BIAS) {
                if(glstate->texenv[glstate->texture.active].filter.lod_bias == param)
                    return;
                glstate->texenv[glstate->texture.active].filter.lod_bias = param;
            } else {
                errorShim(GL_INVALID_ENUM);
                return;
            }
            break;
        case GL_TEXTURE_ENV:
            {
            texenv_t *t = &glstate->texenv[glstate->texture.active].env;
            switch(pname) {
                case GL_TEXTURE_ENV_MODE:
                    if(t->mode == param)
                        return;
                    if (param!=GL_ADD && param!=GL_MODULATE && param!=GL_DECAL && param!=GL_BLEND && param!=GL_REPLACE && param!=GL_COMBINE) {
                        errorShim(GL_INVALID_ENUM);
                        return;
                    }
                    t->mode = param;
                    break;
                case GL_COMBINE_RGB:
                    if(t->combine_rgb == param)
                        return;
                    if (param!=GL_REPLACE && param!=GL_MODULATE && param!=GL_ADD && param!=GL_ADD_SIGNED 
                        && param!=GL_INTERPOLATE && param!=GL_SUBTRACT && param!=GL_DOT3_RGB && param!=GL_DOT3_RGBA) {
                            errorShim(GL_INVALID_ENUM);
                            return;
                        }
                    t->combine_rgb = param;
                    break;
                case GL_COMBINE_ALPHA:
                    if(t->combine_alpha == param)
                        return;
                    if (param!=GL_REPLACE && param!=GL_MODULATE && param!=GL_ADD && param!=GL_ADD_SIGNED 
                        && param!=GL_INTERPOLATE && param!=GL_SUBTRACT) {
                            errorShim(GL_INVALID_ENUM);
                            return;
                        }
                    t->combine_alpha = param;
                    break;
                case GL_SRC0_RGB:
                    if(t->src0_rgb == param)
                        return;
                    if (param!=GL_TEXTURE && !(param>=GL_TEXTURE0 && param<GL_TEXTURE0+hardext.maxtex) 
                        && param!=GL_CONSTANT && param!=GL_PRIMARY_COLOR && param!=GL_PREVIOUS) {
                            errorShim(GL_INVALID_ENUM);
                            return;
                        }
                    t->src0_rgb = param;
                    break;
                case GL_SRC1_RGB:
                    if(t->src1_rgb == param)
                        return;
                    if (param!=GL_TEXTURE && !(param>=GL_TEXTURE0 && param<GL_TEXTURE0+hardext.maxtex) 
                        && param!=GL_CONSTANT && param!=GL_PRIMARY_COLOR && param!=GL_PREVIOUS) {
                            errorShim(GL_INVALID_ENUM);
                            return;
                        }
                    t->src1_rgb = param;
                    break;
                case GL_SRC2_RGB:
                    if(t->src2_rgb == param)
                        return;
                    if (param!=GL_TEXTURE && !(param>=GL_TEXTURE0 && param<GL_TEXTURE0+hardext.maxtex) 
                        && param!=GL_CONSTANT && param!=GL_PRIMARY_COLOR && param!=GL_PREVIOUS) {
                            errorShim(GL_INVALID_ENUM);
                            return;
                        }
                    t->src2_rgb = param;
                    break;
                case GL_SRC0_ALPHA:
                    if(t->src0_alpha == param)
                        return;
                    if (param!=GL_TEXTURE && !(param>=GL_TEXTURE0 && param<GL_TEXTURE0+hardext.maxtex) 
                        && param!=GL_CONSTANT && param!=GL_PRIMARY_COLOR && param!=GL_PREVIOUS) {
                            errorShim(GL_INVALID_ENUM);
                            return;
                        }
                    t->src0_alpha = param;
                    break;
                case GL_SRC1_ALPHA:
                    if(t->src1_alpha == param)
                        return;
                    if (param!=GL_TEXTURE && !(param>=GL_TEXTURE0 && param<GL_TEXTURE0+hardext.maxtex) 
                        && param!=GL_CONSTANT && param!=GL_PRIMARY_COLOR && param!=GL_PREVIOUS) {
                            errorShim(GL_INVALID_ENUM);
                            return;
                        }
                    t->src1_alpha = param;
                    break;
                case GL_SRC2_ALPHA:
                    if(t->src2_alpha == param)
                        return;
                    if (param!=GL_TEXTURE && !(param>=GL_TEXTURE0 && param<GL_TEXTURE0+hardext.maxtex) 
                        && param!=GL_CONSTANT && param!=GL_PRIMARY_COLOR && param!=GL_PREVIOUS) {
                            errorShim(GL_INVALID_ENUM);
                            return;
                        }
                    t->src2_alpha = param;
                    break;
                case GL_RGB_SCALE:
                    if(t->rgb_scale == param)
                        return;
                    if(param!=1.0 && param!=2.0 && param!=4.0) {
                        errorShim(GL_INVALID_VALUE);
                        return;
                    }
                    t->rgb_scale = param;
                    break;
                case GL_ALPHA_SCALE:
                    if(t->alpha_scale == param)
                        return;
                    if(param!=1.0 && param!=2.0 && param!=4.0) {
                        errorShim(GL_INVALID_VALUE);
                        return;
                    }
                    t->alpha_scale = param;
                    break;
                default:
                    errorShim(GL_INVALID_ENUM);
                    return;
            }
            }
            break;
        default:
            errorShim(GL_INVALID_ENUM);
            return;
    }
    errorGL();
    gles_glTexEnvf(target, pname, param);
}

void gl4es_glTexEnvi(GLenum target, GLenum pname, GLint param) {
    gl4es_glTexEnvf(target, pname, param);
}

void gl4es_glTexEnvfv(GLenum target, GLenum pname, const GLfloat *param) {
    if ((glstate->list.compiling || glstate->gl_batch) && glstate->list.active) {
		NewStage(glstate->list.active, STAGE_TEXENV);
		rlTexEnvfv(glstate->list.active, target, pname, param);
        noerrorShim();
		return;
	}
    if(target==GL_TEXTURE_ENV && pname==GL_TEXTURE_ENV_COLOR) {
        texenv_t *t = &glstate->texenv[glstate->texture.active].env;
        if(memcmp(t->color, param, 4*sizeof(GLfloat))==0) {
            noerrorShim();
            return;
        }
        memcpy(t->color, param, 4*sizeof(GLfloat));
        errorGL();
        LOAD_GLES(glTexEnvfv);
        gles_glTexEnvfv(target, pname, param);
    } else
        gl4es_glTexEnvf(target, pname, *param);
}
void gl4es_glTexEnviv(GLenum target, GLenum pname, const GLint *param) {
    if (glstate->list.pending) flush();
    if ((glstate->list.compiling || glstate->gl_batch) && glstate->list.active) {
		NewStage(glstate->list.active, STAGE_TEXENV);
		rlTexEnviv(glstate->list.active, target, pname, param);
        noerrorShim();
		return;
	}
    if(target==GL_TEXTURE_ENV && pname==GL_TEXTURE_ENV_COLOR) {
        GLfloat p[4];
        p[0] = param[0]; p[1] = param[1]; p[2] = param[2]; p[3] = param[3];
        gl4es_glTexEnvfv(target, pname, p);
    } else
        gl4es_glTexEnvf(target, pname, *param);
}
void gl4es_glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params) {
    if (glstate->list.pending) flush();
    if (glstate->list.active && (glstate->gl_batch && !glstate->list.compiling)) flush();
    noerrorShim();
    switch(target) {
        case GL_POINT_SPRITE:
            if(pname == GL_COORD_REPLACE) {
                *params = glstate->texture.pscoordreplace[glstate->texture.active];
                return;
            }
            break;
        case GL_TEXTURE_FILTER_CONTROL:
            if(pname == GL_TEXTURE_LOD_BIAS) {
                *params = glstate->texenv[glstate->texture.active].filter.lod_bias;
                return;
            }
            break;
        case GL_TEXTURE_ENV:
        {
            texenv_t *t = &glstate->texenv[glstate->texture.active].env;
            switch(pname) {
                case GL_TEXTURE_ENV_MODE:
                    *params = t->mode;
                    return;
                case GL_TEXTURE_ENV_COLOR:
                    memcpy(params, t->color, 4*sizeof(GLfloat));
                    return;
                case GL_COMBINE_RGB:
                    *params = t->combine_rgb;
                    return;
                case GL_COMBINE_ALPHA:
                    *params = t->combine_alpha;
                    return;
                case GL_SRC0_RGB:
                    *params = t->src0_rgb;
                    return;
                case GL_SRC1_RGB:
                    *params = t->src1_rgb;
                    return;
                case GL_SRC2_RGB:
                    *params = t->src2_rgb;
                    return;
                case GL_SRC0_ALPHA:
                    *params = t->src0_alpha;
                    return;
                case GL_SRC1_ALPHA:
                    *params = t->src1_alpha;
                    return;
                case GL_SRC2_ALPHA:
                    *params = t->src2_alpha;
                    return;
                case GL_RGB_SCALE:
                    *params = t->rgb_scale;
                    return;
                case GL_ALPHA_SCALE:
                    *params = t->alpha_scale;
                    return;
            }
        }
    }
    errorShim(GL_INVALID_ENUM);
    return;
}
void gl4es_glGetTexEnviv(GLenum target, GLenum pname, GLint * params) {
    LOAD_GLES(glGetTexEnviv);
    if (glstate->list.pending) flush();
    if (glstate->list.active && (glstate->gl_batch && !glstate->list.compiling)) flush();
    noerrorShim();
    switch(target) {
        case GL_POINT_SPRITE:
            if(pname == GL_COORD_REPLACE) {
                *params = glstate->texture.pscoordreplace[glstate->texture.active];
                return;
            }
            break;
        case GL_TEXTURE_FILTER_CONTROL:
            if(pname == GL_TEXTURE_LOD_BIAS) {
                *params = glstate->texenv[glstate->texture.active].filter.lod_bias;
                return;
            }
            break;
        case GL_TEXTURE_ENV:
        {
            texenv_t *t = &glstate->texenv[glstate->texture.active].env;
            switch(pname) {
                case GL_TEXTURE_ENV_MODE:
                    *params = t->mode;
                    return;
                case GL_TEXTURE_ENV_COLOR:
                    memcpy(params, t->color, 4*sizeof(GLfloat));
                    return;
                case GL_COMBINE_RGB:
                    *params = t->combine_rgb;
                    return;
                case GL_COMBINE_ALPHA:
                    *params = t->combine_alpha;
                    return;
                case GL_SRC0_RGB:
                    *params = t->src0_rgb;
                    return;
                case GL_SRC1_RGB:
                    *params = t->src1_rgb;
                    return;
                case GL_SRC2_RGB:
                    *params = t->src2_rgb;
                    return;
                case GL_SRC0_ALPHA:
                    *params = t->src0_alpha;
                    return;
                case GL_SRC1_ALPHA:
                    *params = t->src1_alpha;
                    return;
                case GL_SRC2_ALPHA:
                    *params = t->src2_alpha;
                    return;
                case GL_RGB_SCALE:
                    *params = t->rgb_scale;
                    return;
                case GL_ALPHA_SCALE:
                    *params = t->alpha_scale;
                    return;
            }
        }
    }
    errorShim(GL_INVALID_ENUM);
    return;
}


void glTexEnvf(GLenum target, GLenum pname, GLfloat param) AliasExport("gl4es_glTexEnvf");
void glTexEnvi(GLenum target, GLenum pname, GLint param) AliasExport("gl4es_glTexEnvi");
void glTexEnvfv(GLenum target, GLenum pname, const GLfloat *param) AliasExport("gl4es_glTexEnvfv");
void glTexEnviv(GLenum target, GLenum pname, const GLint *param) AliasExport("gl4es_glTexEnviv");
void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params) AliasExport("gl4es_glGetTexEnvfv");
void glGetTexEnviv(GLenum target, GLenum pname, GLint * params) AliasExport("gl4es_glGetTexEnviv");
