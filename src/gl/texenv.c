#include "texenv.h"
#include "debug.h"
#include "../glx/hardext.h"

void gl4es_glTexEnvf(GLenum target, GLenum pname, GLfloat param) {
    LOAD_GLES2(glTexEnvf);
    if (!glstate->list.pending) {
        PUSH_IF_COMPILING(glTexEnvf);
    }
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
                if (glstate->list.pending) flush();
                glstate->texture.pscoordreplace[glstate->texture.active] = p;
                if (glstate->fpe_state)
                    glstate->fpe_state->pointsprite_coord = p;
            } else {
                errorShim(GL_INVALID_ENUM);
                return;
            }
            break;
        case GL_TEXTURE_FILTER_CONTROL:
            if(pname==GL_TEXTURE_LOD_BIAS) {
                if(glstate->texenv[glstate->texture.active].filter.lod_bias == param)
                    return;
                if (glstate->list.pending) flush();
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
                    if (glstate->list.pending) flush();
                    t->mode = param;
                    if(glstate->fpe_state) {
                        int state = FPE_MODULATE;
                        switch(t->mode) {
                            case GL_ADD: state=FPE_ADD; break;
                            case GL_DECAL: state=FPE_DECAL; break;
                            case GL_BLEND: state=FPE_BLEND; break;
                            case GL_REPLACE: state=FPE_REPLACE; break;
                            case GL_COMBINE: state=FPE_COMBINE; break;
                        }
                        glstate->fpe_state->texenv &= ~ (7<<(glstate->texture.active*3));
                        glstate->fpe_state->texenv |= state<<(glstate->texture.active*3);
                    }
                    break;
                case GL_COMBINE_RGB:
                    if(t->combine_rgb == param)
                        return;
                    if (param!=GL_REPLACE && param!=GL_MODULATE && param!=GL_ADD && param!=GL_ADD_SIGNED 
                        && param!=GL_INTERPOLATE && param!=GL_SUBTRACT && param!=GL_DOT3_RGB && param!=GL_DOT3_RGBA) {
                            errorShim(GL_INVALID_ENUM);
                            return;
                        }
                    if (glstate->list.pending) flush();
                    t->combine_rgb = param;
                    if(glstate->fpe_state) {
                        int state = FPE_CR_REPLACE;
                        switch(t->combine_rgb) {
                            case GL_MODULATE: state=FPE_CR_MODULATE; break;
                            case GL_ADD: state=FPE_CR_ADD; break;
                            case GL_ADD_SIGNED: state=FPE_CR_ADD_SIGNED; break;
                            case GL_INTERPOLATE: state=FPE_CR_INTERPOLATE; break;
                            case GL_SUBTRACT: state=FPE_CR_SUBTRACT; break;
                            case GL_DOT3_RGB: state=FPE_CR_DOT3_RGB; break;
                            case GL_DOT3_RGBA: state=FPE_CR_DOT3_RGBA; break;
                        }
                        glstate->fpe_state->texcombine[glstate->texture.active] &= ~ 0xf;
                        glstate->fpe_state->texcombine[glstate->texture.active] |= state;
                    }
                    break;
                case GL_COMBINE_ALPHA:
                    if(t->combine_alpha == param)
                        return;
                    if (param!=GL_REPLACE && param!=GL_MODULATE && param!=GL_ADD && param!=GL_ADD_SIGNED 
                        && param!=GL_INTERPOLATE && param!=GL_SUBTRACT) {
                            errorShim(GL_INVALID_ENUM);
                            return;
                        }
                    if (glstate->list.pending) flush();
                    t->combine_alpha = param;
                    if(glstate->fpe_state) {
                        int state = FPE_CR_REPLACE;
                        switch(t->combine_alpha) {
                            case GL_MODULATE: state=FPE_CR_MODULATE; break;
                            case GL_ADD: state=FPE_CR_ADD; break;
                            case GL_ADD_SIGNED: state=FPE_CR_ADD_SIGNED; break;
                            case GL_INTERPOLATE: state=FPE_CR_INTERPOLATE; break;
                            case GL_SUBTRACT: state=FPE_CR_SUBTRACT; break;
                        }
                        glstate->fpe_state->texcombine[glstate->texture.active] &= ~ 0xf0;
                        glstate->fpe_state->texcombine[glstate->texture.active] |= state<<4;
                    }
                    break;
                case GL_SRC0_RGB:
                    if(t->src0_rgb == param)
                        return;
                    if (param!=GL_TEXTURE && !(param>=GL_TEXTURE0 && param<GL_TEXTURE0+hardext.maxtex) 
                        && param!=GL_CONSTANT && param!=GL_PRIMARY_COLOR && param!=GL_PREVIOUS) {
                            errorShim(GL_INVALID_ENUM);
                            return;
                        }
                    if (glstate->list.pending) flush();
                    t->src0_rgb = param;
                    if(glstate->fpe_state) {
                        int state = FPE_SRC_TEXTURE;
                        if(t->src0_rgb>=GL_TEXTURE0 && t->src0_rgb<=GL_TEXTURE8) {
                            state = FPE_SRC_TEXTURE0 + (t->src0_rgb-GL_TEXTURE0);
                        } else
                            switch(t->src0_rgb) {
                                case GL_CONSTANT: state=FPE_SRC_CONSTANT; break;
                                case GL_PRIMARY_COLOR: state=FPE_SRC_PRIMARY_COLOR; break;
                                case GL_PREVIOUS: state=FPE_SRC_PREVIOUS; break;
                            }
                        glstate->fpe_state->texsrcrgb[0] &= ~ (0xf<<(glstate->texture.active*4));
                        glstate->fpe_state->texsrcrgb[0] |= state<<(glstate->texture.active*4);
                    }
                    break;
                case GL_SRC1_RGB:
                    if(t->src1_rgb == param)
                        return;
                    if (param!=GL_TEXTURE && !(param>=GL_TEXTURE0 && param<GL_TEXTURE0+hardext.maxtex) 
                        && param!=GL_CONSTANT && param!=GL_PRIMARY_COLOR && param!=GL_PREVIOUS) {
                            errorShim(GL_INVALID_ENUM);
                            return;
                        }
                    if (glstate->list.pending) flush();
                    t->src1_rgb = param;
                    if(glstate->fpe_state) {
                        int state = FPE_SRC_TEXTURE;
                        if(t->src1_rgb>=GL_TEXTURE0 && t->src1_rgb<=GL_TEXTURE8) {
                            state = FPE_SRC_TEXTURE0 + (t->src1_rgb-GL_TEXTURE0);
                        } else
                            switch(t->src1_rgb) {
                                case GL_CONSTANT: state=FPE_SRC_CONSTANT; break;
                                case GL_PRIMARY_COLOR: state=FPE_SRC_PRIMARY_COLOR; break;
                                case GL_PREVIOUS: state=FPE_SRC_PREVIOUS; break;
                            }
                        glstate->fpe_state->texsrcrgb[1] &= ~ (0xf<<(glstate->texture.active*4));
                        glstate->fpe_state->texsrcrgb[1] |= state<<(glstate->texture.active*4);
                    }
                    break;
                case GL_SRC2_RGB:
                    if(t->src2_rgb == param)
                        return;
                    if (param!=GL_TEXTURE && !(param>=GL_TEXTURE0 && param<GL_TEXTURE0+hardext.maxtex) 
                        && param!=GL_CONSTANT && param!=GL_PRIMARY_COLOR && param!=GL_PREVIOUS) {
                            errorShim(GL_INVALID_ENUM);
                            return;
                        }
                    if (glstate->list.pending) flush();
                    t->src2_rgb = param;
                    if(glstate->fpe_state) {
                        int state = FPE_SRC_TEXTURE;
                        if(t->src2_rgb>=GL_TEXTURE0 && t->src2_rgb<=GL_TEXTURE8) {
                            state = FPE_SRC_TEXTURE0 + (t->src2_rgb-GL_TEXTURE0);
                        } else
                            switch(t->src2_rgb) {
                                case GL_CONSTANT: state=FPE_SRC_CONSTANT; break;
                                case GL_PRIMARY_COLOR: state=FPE_SRC_PRIMARY_COLOR; break;
                                case GL_PREVIOUS: state=FPE_SRC_PREVIOUS; break;
                            }
                        glstate->fpe_state->texsrcrgb[2] &= ~ (0xf<<(glstate->texture.active*4));
                        glstate->fpe_state->texsrcrgb[2] |= state<<(glstate->texture.active*4);
                    }
                    break;
                case GL_SRC0_ALPHA:
                    if(t->src0_alpha == param)
                        return;
                    if (param!=GL_TEXTURE && !(param>=GL_TEXTURE0 && param<GL_TEXTURE0+hardext.maxtex) 
                        && param!=GL_CONSTANT && param!=GL_PRIMARY_COLOR && param!=GL_PREVIOUS) {
                            errorShim(GL_INVALID_ENUM);
                            return;
                        }
                    if (glstate->list.pending) flush();
                    t->src0_alpha = param;
                    if(glstate->fpe_state) {
                        int state = FPE_SRC_TEXTURE;
                        if(t->src0_alpha>=GL_TEXTURE0 && t->src0_alpha<=GL_TEXTURE8) {
                            state = FPE_SRC_TEXTURE0 + (t->src0_alpha-GL_TEXTURE0);
                        } else
                            switch(t->src0_alpha) {
                                case GL_CONSTANT: state=FPE_SRC_CONSTANT; break;
                                case GL_PRIMARY_COLOR: state=FPE_SRC_PRIMARY_COLOR; break;
                                case GL_PREVIOUS: state=FPE_SRC_PREVIOUS; break;
                            }
                        glstate->fpe_state->texsrcalpha[0] &= ~ (0xf<<(glstate->texture.active*4));
                        glstate->fpe_state->texsrcalpha[0] |= state<<(glstate->texture.active*4);
                    }
                    break;
                case GL_SRC1_ALPHA:
                    if(t->src1_alpha == param)
                        return;
                    if (param!=GL_TEXTURE && !(param>=GL_TEXTURE0 && param<GL_TEXTURE0+hardext.maxtex) 
                        && param!=GL_CONSTANT && param!=GL_PRIMARY_COLOR && param!=GL_PREVIOUS) {
                            errorShim(GL_INVALID_ENUM);
                            return;
                        }
                    if (glstate->list.pending) flush();
                    t->src1_alpha = param;
                    if(glstate->fpe_state) {
                        int state = FPE_SRC_TEXTURE;
                        if(t->src1_alpha>=GL_TEXTURE0 && t->src1_alpha<=GL_TEXTURE8) {
                            state = FPE_SRC_TEXTURE0 + (t->src1_alpha-GL_TEXTURE0);
                        } else
                            switch(t->src1_alpha) {
                                case GL_CONSTANT: state=FPE_SRC_CONSTANT; break;
                                case GL_PRIMARY_COLOR: state=FPE_SRC_PRIMARY_COLOR; break;
                                case GL_PREVIOUS: state=FPE_SRC_PREVIOUS; break;
                            }
                        glstate->fpe_state->texsrcalpha[1] &= ~ (0xf<<(glstate->texture.active*4));
                        glstate->fpe_state->texsrcalpha[1] |= state<<(glstate->texture.active*4);
                    }
                    break;
                case GL_SRC2_ALPHA:
                    if(t->src2_alpha == param)
                        return;
                    if (param!=GL_TEXTURE && !(param>=GL_TEXTURE0 && param<GL_TEXTURE0+hardext.maxtex) 
                        && param!=GL_CONSTANT && param!=GL_PRIMARY_COLOR && param!=GL_PREVIOUS) {
                            errorShim(GL_INVALID_ENUM);
                            return;
                        }
                    if (glstate->list.pending) flush();
                    t->src2_alpha = param;
                    if(glstate->fpe_state) {
                        int state = FPE_SRC_TEXTURE;
                        if(t->src2_alpha>=GL_TEXTURE0 && t->src2_alpha<=GL_TEXTURE8) {
                            state = FPE_SRC_TEXTURE0 + (t->src2_alpha-GL_TEXTURE0);
                        } else
                            switch(t->src2_alpha) {
                                case GL_CONSTANT: state=FPE_SRC_CONSTANT; break;
                                case GL_PRIMARY_COLOR: state=FPE_SRC_PRIMARY_COLOR; break;
                                case GL_PREVIOUS: state=FPE_SRC_PREVIOUS; break;
                            }
                        glstate->fpe_state->texsrcalpha[2] &= ~ (0xf<<(glstate->texture.active*4));
                        glstate->fpe_state->texsrcalpha[2] |= state<<(glstate->texture.active*4);
                    }
                    break;
                case GL_OPERAND0_RGB:
                    if(t->op0_rgb == param)
                        return;
                    if (param!=GL_SRC_COLOR && param!=GL_ONE_MINUS_SRC_COLOR
                         && param!=GL_SRC_ALPHA && param!=GL_ONE_MINUS_SRC_ALPHA) {
                            errorShim(GL_INVALID_ENUM);
                            return;
                        }
                    if (glstate->list.pending) flush();
                    t->op0_rgb = param;
                    if(glstate->fpe_state) {
                        int state = FPE_OP_ALPHA;
                        switch(t->op0_rgb) {
                            case GL_SRC_COLOR: state=FPE_OP_SRCCOLOR; break;
                            case GL_ONE_MINUS_SRC_COLOR: state=FPE_OP_MINUSCOLOR; break;
                            case GL_ONE_MINUS_SRC_ALPHA: state=FPE_OP_MINUSALPHA; break;
                        }
                        glstate->fpe_state->texoprgb[0] &= ~ (0x3<<(glstate->texture.active*2));
                        glstate->fpe_state->texoprgb[0] |= state<<(glstate->texture.active*2);
                    }
                    break;
                case GL_OPERAND1_RGB:
                    if(t->op1_rgb == param)
                        return;
                    if (param!=GL_SRC_COLOR && param!=GL_ONE_MINUS_SRC_COLOR
                         && param!=GL_SRC_ALPHA && param!=GL_ONE_MINUS_SRC_ALPHA) {
                            errorShim(GL_INVALID_ENUM);
                            return;
                        }
                    if (glstate->list.pending) flush();
                    t->op1_rgb = param;
                    if(glstate->fpe_state) {
                        int state = FPE_OP_ALPHA;
                        switch(t->op1_rgb) {
                            case GL_SRC_COLOR: state=FPE_OP_SRCCOLOR; break;
                            case GL_ONE_MINUS_SRC_COLOR: state=FPE_OP_MINUSCOLOR; break;
                            case GL_ONE_MINUS_SRC_ALPHA: state=FPE_OP_MINUSALPHA; break;
                        }
                        glstate->fpe_state->texoprgb[1] &= ~ (0x3<<(glstate->texture.active*2));
                        glstate->fpe_state->texoprgb[1] |= state<<(glstate->texture.active*2);
                    }
                    break;
                case GL_OPERAND2_RGB:
                    if(t->op2_rgb == param)
                        return;
                    if (param!=GL_SRC_COLOR && param!=GL_ONE_MINUS_SRC_COLOR
                         && param!=GL_SRC_ALPHA && param!=GL_ONE_MINUS_SRC_ALPHA) {
                            errorShim(GL_INVALID_ENUM);
                            return;
                        }
                    if (glstate->list.pending) flush();
                    t->op2_rgb = param;
                    if(glstate->fpe_state) {
                        int state = FPE_OP_ALPHA;
                        switch(t->op2_rgb) {
                            case GL_SRC_COLOR: state=FPE_OP_SRCCOLOR; break;
                            case GL_ONE_MINUS_SRC_COLOR: state=FPE_OP_MINUSCOLOR; break;
                            case GL_ONE_MINUS_SRC_ALPHA: state=FPE_OP_MINUSALPHA; break;
                        }
                        glstate->fpe_state->texoprgb[2] &= ~ (0x3<<(glstate->texture.active*2));
                        glstate->fpe_state->texoprgb[2] |= state<<(glstate->texture.active*2);
                    }
                    break;
                case GL_OPERAND0_ALPHA:
                    if(t->op0_alpha == param)
                        return;
                    if (param!=GL_SRC_ALPHA && param!=GL_ONE_MINUS_SRC_ALPHA) {
                            errorShim(GL_INVALID_ENUM);
                            return;
                        }
                    if (glstate->list.pending) flush();
                    t->op0_alpha = param;
                    if(glstate->fpe_state) {
                        int state = FPE_OP_ALPHA;
                        if(t->op0_alpha==GL_ONE_MINUS_SRC_ALPHA) state=FPE_OP_MINUSALPHA;

                        glstate->fpe_state->texopalpha[0] &= ~ (0x1<<glstate->texture.active);
                        glstate->fpe_state->texopalpha[0] |= state<<glstate->texture.active;
                    }
                    break;
                case GL_OPERAND1_ALPHA:
                    if(t->op1_alpha == param)
                        return;
                    if (param!=GL_SRC_ALPHA && param!=GL_ONE_MINUS_SRC_ALPHA) {
                            errorShim(GL_INVALID_ENUM);
                            return;
                        }
                    if (glstate->list.pending) flush();
                    t->op1_alpha = param;
                    if(glstate->fpe_state) {
                        int state = FPE_OP_ALPHA;
                        if(t->op1_alpha==GL_ONE_MINUS_SRC_ALPHA) state=FPE_OP_MINUSALPHA;

                        glstate->fpe_state->texopalpha[1] &= ~ (0x1<<glstate->texture.active);
                        glstate->fpe_state->texopalpha[1] |= state<<glstate->texture.active;
                    }
                    break;
                case GL_OPERAND2_ALPHA:
                    if(t->op2_alpha == param)
                        return;
                    if (param!=GL_SRC_ALPHA && param!=GL_ONE_MINUS_SRC_ALPHA) {
                            errorShim(GL_INVALID_ENUM);
                            return;
                        }
                    if (glstate->list.pending) flush();
                    t->op2_alpha = param;
                    if(glstate->fpe_state) {
                        int state = FPE_OP_ALPHA;
                        if(t->op2_alpha==GL_ONE_MINUS_SRC_ALPHA) state=FPE_OP_MINUSALPHA;

                        glstate->fpe_state->texopalpha[2] &= ~ (0x1<<glstate->texture.active);
                        glstate->fpe_state->texopalpha[2] |= state<<glstate->texture.active;
                    }
                    break;
                case GL_RGB_SCALE:
                    if(t->rgb_scale == param)
                        return;
                    if(param!=1.0 && param!=2.0 && param!=4.0) {
                        errorShim(GL_INVALID_VALUE);
                        return;
                    }
                    if (glstate->list.pending) flush();
                    t->rgb_scale = param;
                    if(glstate->fpe_state) {
                        if(param==1.0f)
                            glstate->fpe_state->texrgbscale &= ~(1<<glstate->texture.active);
                        else
                        glstate->fpe_state->texrgbscale |= 1<<glstate->texture.active;
                    }
                    break;
                case GL_ALPHA_SCALE:
                    if(t->alpha_scale == param)
                        return;
                    if(param!=1.0 && param!=2.0 && param!=4.0) {
                        errorShim(GL_INVALID_VALUE);
                        return;
                    }
                    if (glstate->list.pending) flush();
                    t->alpha_scale = param;
                    if(glstate->fpe_state) {
                        if(param==1.0f)
                            glstate->fpe_state->texalphascale &= ~(1<<glstate->texture.active);
                        else
                        glstate->fpe_state->texalphascale |= 1<<glstate->texture.active;
                    }
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
    if(hardext.esversion==1)
        gles_glTexEnvf(target, pname, param);
}

void gl4es_glTexEnvi(GLenum target, GLenum pname, GLint param) {
    gl4es_glTexEnvf(target, pname, param);
}

void gl4es_glTexEnvfv(GLenum target, GLenum pname, const GLfloat *param) {
    if ((glstate->list.compiling) && glstate->list.active) {
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
        if (glstate->list.pending) flush();
        memcpy(t->color, param, 4*sizeof(GLfloat));
        errorGL();
        LOAD_GLES2(glTexEnvfv);
        if(gles_glTexEnvfv)
            gles_glTexEnvfv(target, pname, param);
    } else
        gl4es_glTexEnvf(target, pname, *param);
}
void gl4es_glTexEnviv(GLenum target, GLenum pname, const GLint *param) {
    if ((glstate->list.compiling) && glstate->list.active) {
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
    //if (glstate->list.pending) flush();
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
                case GL_OPERAND0_RGB:
                    *params = t->op0_rgb;
                    break;
                case GL_OPERAND1_RGB:
                    *params = t->op1_rgb;
                    break;
                case GL_OPERAND2_RGB:
                    *params = t->op2_rgb;
                    break;
                case GL_OPERAND0_ALPHA:
                    *params = t->op0_alpha;
                    break;
                case GL_OPERAND1_ALPHA:
                    *params = t->op1_alpha;
                    break;
                case GL_OPERAND2_ALPHA:
                    *params = t->op2_alpha;
                    break;
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
 //   LOAD_GLES(glGetTexEnviv);
    //if (glstate->list.pending) flush();
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
                case GL_OPERAND0_RGB:
                    *params = t->op0_rgb;
                    break;
                case GL_OPERAND1_RGB:
                    *params = t->op1_rgb;
                    break;
                case GL_OPERAND2_RGB:
                    *params = t->op2_rgb;
                    break;
                case GL_OPERAND0_ALPHA:
                    *params = t->op0_alpha;
                    break;
                case GL_OPERAND1_ALPHA:
                    *params = t->op1_alpha;
                    break;
                case GL_OPERAND2_ALPHA:
                    *params = t->op2_alpha;
                    break;
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
