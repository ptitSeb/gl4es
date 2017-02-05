#include "light.h"
#include "../glx/hardext.h"
#include "matrix.h"
#include "matvec.h"

#ifndef USE_ES2
void gl4es_glLightModelf(GLenum pname, GLfloat param) {
//printf("%sglLightModelf(%04X, %.2f)\n", (state.list.compiling)?"list":"", pname, param);
    if (glstate->list.compiling && glstate->list.active) {
		GLfloat dummy[4];
		dummy[0]=param;
		gl4es_glLightModelfv(pname, dummy);
		return;
	}
    switch (pname) {
        case GL_LIGHT_MODEL_TWO_SIDE:
            errorGL();
            glstate->light.two_side = param;
			break;
        case GL_LIGHT_MODEL_AMBIENT:
        default:
            errorShim(GL_INVALID_ENUM);
            return;
    }
    LOAD_GLES(glLightModelf);
    gles_glLightModelf(pname, param);
}

void gl4es_glLightModelfv(GLenum pname, const GLfloat* params) {
//printf("%sglLightModelfv(%04X, [%.2f, %.2f, %.2f, %.2f])\n", (state.list.compiling)?"list":"", pname, params[0], params[1], params[2], params[3]);
    if (glstate->list.compiling && glstate->list.active) {
		NewStage(glstate->list.active, STAGE_LIGHTMODEL);
/*		if (glstate->list.active->lightmodel)
			glstate->list.active = extend_renderlist(glstate->list.active);*/
		glstate->list.active->lightmodelparam = pname;
		glstate->list.active->lightmodel = (GLfloat*)malloc(4*sizeof(GLfloat));
		memcpy(glstate->list.active->lightmodel, params, 4*sizeof(GLfloat));
        noerrorShim();
		return;
	}
    switch (pname) {
        case GL_LIGHT_MODEL_AMBIENT:
            if(memcmp(glstate->light.ambient, params, 4*sizeof(GLfloat))==0) {
                noerrorShim();
                return;
            }
            errorGL();
            memcpy(glstate->light.ambient, params, 4*sizeof(GLfloat));
            break;
        case GL_LIGHT_MODEL_TWO_SIDE:
            if(glstate->light.two_side == params[0]) {
                noerrorShim();
                return;
            }
            errorGL();
            glstate->light.two_side = params[0];
			break;
        default:
            errorShim(GL_INVALID_ENUM);
            return;
    }
    LOAD_GLES(glLightModelfv);
    gles_glLightModelfv(pname, params);
}

void gl4es_glLightfv(GLenum light, GLenum pname, const GLfloat* params) {
//printf("%sglLightfv(%04X, %04X, %p=[%.2f, %.2f, %.2f, %.2f])\n", (glstate->list.compiling)?"list":"", light, pname, params, (params)?params[0]:0.0f, (params)?params[1]:0.0f, (params)?params[2]:0.0f, (params)?params[3]:0.0f);
    if(light<0 || light>=hardext.maxlights) {
        errorShim(GL_INVALID_ENUM);
        return;
    }
    if (glstate->list.compiling && glstate->list.active) {
		NewStage(glstate->list.active, STAGE_LIGHT);
		rlLightfv(glstate->list.active, light, pname, params);
        noerrorShim();
		return;
	}
    GLfloat tmp[4];
    noerrorShim();
    switch(pname) {
        case GL_AMBIENT:
            if(memcmp(glstate->light.lights[light].ambient, params, 4*sizeof(GLfloat))==0)
                return;
            memcpy(glstate->light.lights[light].ambient, params, 4*sizeof(GLfloat));
            break;
        case GL_DIFFUSE:
            if(memcmp(glstate->light.lights[light].diffuse, params, 4*sizeof(GLfloat)))
                return;
            memcpy(glstate->light.lights[light].diffuse, params, 4*sizeof(GLfloat));
            break;
        case GL_SPECULAR:
            if(memcmp(glstate->light.lights[light].specular, params, 4*sizeof(GLfloat)))
                return;
            memcpy(glstate->light.lights[light].specular, params, 4*sizeof(GLfloat));
            break;
        case GL_POSITION:
            vector_matrix(params, getMVMat(), tmp);
            if(memcmp(glstate->light.lights[light].position, tmp, 4*sizeof(GLfloat)))
                return;
            memcpy(glstate->light.lights[light].position, tmp, 4*sizeof(GLfloat));
            break;
        case GL_SPOT_DIRECTION:
            memcpy(tmp, params, 3*sizeof(GLfloat));
            tmp[3] = 0.0f;
            vector_matrix(tmp, getMVMat(), tmp);
            if(memcmp(glstate->light.lights[light].spotDirection, tmp, 4*sizeof(GLfloat)))
                return;
            memcpy(glstate->light.lights[light].spotDirection, tmp, 4*sizeof(GLfloat));
            break;
        case GL_SPOT_EXPONENT:
            if(params[0]<0 || params[0]>128) {
                errorShim(GL_INVALID_VALUE);
                return;
            }
            if(glstate->light.lights[light].spotExponent == params[0])
                return;
            glstate->light.lights[light].spotExponent = params[0];
            break;
        case GL_SPOT_CUTOFF:
            if(params[0]<0 || (params[0]>90 && params[0]!=180)) {
                errorShim(GL_INVALID_VALUE);
                return;
            }
            if(glstate->light.lights[light].spotCutoff == params[0])
                return;
            glstate->light.lights[light].spotCutoff = params[0];
            break;
        case GL_CONSTANT_ATTENUATION:
            if(params[0]<0) {
                errorShim(GL_INVALID_VALUE);
                return;
            }
            if(glstate->light.lights[light].constantAttenuation == params[0])
                return;
            glstate->light.lights[light].constantAttenuation = params[0];
            break;
        case GL_LINEAR_ATTENUATION:
            if(params[0]<0) {
                errorShim(GL_INVALID_VALUE);
                return;
            }
            if(glstate->light.lights[light].linearAttenuation == params[0])
                return;
            glstate->light.lights[light].linearAttenuation = params[0];
            break;
        case GL_QUADRATIC_ATTENUATION:
            if(params[0]<0) {
                errorShim(GL_INVALID_VALUE);
                return;
            }
            if(glstate->light.lights[light].quadraticAttenuation == params[0])
                return;
            glstate->light.lights[light].quadraticAttenuation = params[0];
            break;
    }
    LOAD_GLES(glLightfv);
    gles_glLightfv(light, pname, params);
    errorGL();
}

void gl4es_glLightf(GLenum light, GLenum pname, const GLfloat params) {
	GLfloat dummy[4];
	dummy[0]=params;
	gl4es_glLightfv(light, pname, dummy);
    errorGL();
}

void gl4es_glMaterialfv(GLenum face, GLenum pname, const GLfloat *params) {
    if ((glstate->list.compiling || glstate->gl_batch) && glstate->list.active) {
		//TODO: Materialfv can be done per vertex, how to handle that ?!
		//NewStage(glstate->list.active, STAGE_MATERIAL);
        rlMaterialfv(glstate->list.active, face, pname, params);
        noerrorShim();
    } else {
        if(face!=GL_FRONT_AND_BACK && face!=GL_FRONT && face!=GL_BACK) {
            errorShim(GL_INVALID_ENUM);
            return;
        }
        switch(pname) {
            case GL_AMBIENT:
                if(face==GL_FRONT_AND_BACK || face==GL_FRONT)
                    memcpy(glstate->material.front.ambient, params, 4*sizeof(GLfloat));
                if(face==GL_FRONT_AND_BACK || face==GL_BACK)
                    memcpy(glstate->material.back.ambient, params, 4*sizeof(GLfloat));
                break;
            case GL_DIFFUSE:
                if(face==GL_FRONT_AND_BACK || face==GL_FRONT)
                    memcpy(glstate->material.front.diffuse, params, 4*sizeof(GLfloat));
                if(face==GL_FRONT_AND_BACK || face==GL_BACK)
                    memcpy(glstate->material.back.diffuse, params, 4*sizeof(GLfloat));
                break;
            case GL_SPECULAR:
                if(face==GL_FRONT_AND_BACK || face==GL_FRONT)
                    memcpy(glstate->material.front.specular, params, 4*sizeof(GLfloat));
                if(face==GL_FRONT_AND_BACK || face==GL_BACK)
                    memcpy(glstate->material.back.specular, params, 4*sizeof(GLfloat));
                break;
            case GL_EMISSION:
                if(face==GL_FRONT_AND_BACK || face==GL_FRONT)
                    memcpy(glstate->material.front.emission, params, 4*sizeof(GLfloat));
                if(face==GL_FRONT_AND_BACK || face==GL_BACK)
                    memcpy(glstate->material.back.emission, params, 4*sizeof(GLfloat));
                break;
            case GL_AMBIENT_AND_DIFFUSE:
                if(face==GL_FRONT_AND_BACK || face==GL_FRONT) {
                    memcpy(glstate->material.front.ambient, params, 4*sizeof(GLfloat));
                    memcpy(glstate->material.front.diffuse, params, 4*sizeof(GLfloat));
                }
                if(face==GL_FRONT_AND_BACK || face==GL_BACK) {
                    memcpy(glstate->material.back.ambient, params, 4*sizeof(GLfloat));
                    memcpy(glstate->material.back.diffuse, params, 4*sizeof(GLfloat));
                }
                break;
            case GL_SHININESS:
                if(face==GL_FRONT_AND_BACK || face==GL_FRONT)
                    glstate->material.front.shininess = *params;
                if(face==GL_FRONT_AND_BACK || face==GL_BACK)
                    glstate->material.back.shininess = *params;
                break;
            case GL_COLOR_INDEXES:
                if(face==GL_FRONT_AND_BACK || face==GL_FRONT) {
                    glstate->material.front.indexes[0] = params[0];
                    glstate->material.front.indexes[1] = params[1];
                    glstate->material.front.indexes[2] = params[2];
                }
                if(face==GL_FRONT_AND_BACK || face==GL_BACK) {
                    glstate->material.back.indexes[0] = params[0];
                    glstate->material.back.indexes[1] = params[1];
                    glstate->material.back.indexes[2] = params[2];
                }
                break;
                
        }

	    if (face!=GL_FRONT_AND_BACK) {
		    face=GL_FRONT_AND_BACK;
		}
        LOAD_GLES(glMaterialfv);
        gles_glMaterialfv(face, pname, params);
        errorGL();
    }
}

void gl4es_glMaterialf(GLenum face, GLenum pname, const GLfloat param) {
    if ((glstate->list.compiling || glstate->gl_batch) && glstate->list.active) {
		GLfloat params[4];
		memset(params, 0, 4*sizeof(GLfloat));
		params[0] = param;
		NewStage(glstate->list.active, STAGE_MATERIAL);
        rlMaterialfv(glstate->list.active, face, pname, params);
        noerrorShim();
    } else {
        if(face!=GL_FRONT_AND_BACK && face!=GL_FRONT && face!=GL_BACK) {
            errorShim(GL_INVALID_ENUM);
            return;
        }
        if(pname!=GL_SHININESS) {
            errorShim(GL_INVALID_ENUM);
            return;
        }
        if(face==GL_FRONT_AND_BACK || face==GL_FRONT)
            glstate->material.front.shininess = param;
        if(face==GL_FRONT_AND_BACK || face==GL_BACK)
            glstate->material.back.shininess = param;

        LOAD_GLES(glMaterialf);
	    if (face!=GL_FRONT_AND_BACK) {
		    face=GL_FRONT_AND_BACK;
		}
        gles_glMaterialf(face, pname, param);
        errorGL();
    }
}

void gl4es_glColorMaterial(GLenum face, GLenum mode) {
    if ((glstate->list.compiling || glstate->gl_batch) && glstate->list.active) {
		NewStage(glstate->list.active, STAGE_COLOR_MATERIAL);
        glstate->list.active->colormat_face = face;
        glstate->list.active->colormat_mode = mode;
        noerrorShim();
    } else {
        if(face!=GL_FRONT_AND_BACK && face!=GL_FRONT && face!=GL_BACK) {
            errorShim(GL_INVALID_ENUM);
            return;
        }
        if(mode!=GL_EMISSION && mode!=GL_AMBIENT && mode!=GL_DIFFUSE && mode!=GL_SPECULAR && mode!=GL_AMBIENT_AND_DIFFUSE) {
            errorShim(GL_INVALID_ENUM);
            return;
        }
        if(face==GL_FRONT_AND_BACK || face==GL_FRONT)
            glstate->material.front.colormat = mode;
        if(face==GL_FRONT_AND_BACK || face==GL_BACK)
            glstate->material.back.colormat = mode;
        noerrorShim();
    }
}

void glLightModelf(GLenum pname, GLfloat param) AliasExport("gl4es_glLightModelf");
void glLightModelfv(GLenum pname, const GLfloat* params) AliasExport("gl4es_glLightModelfv");
void glLightfv(GLenum light, GLenum pname, const GLfloat* params) AliasExport("gl4es_glLightfv");
void glLightf(GLenum light, GLenum pname, const GLfloat params) AliasExport("gl4es_glLightf");
void glMaterialfv(GLenum face, GLenum pname, const GLfloat *params) AliasExport("gl4es_glMaterialfv");
void glMaterialf(GLenum face, GLenum pname, const GLfloat param) AliasExport("gl4es_glMaterialf");
void glColorMaterial(GLenum face, GLenum mode) AliasExport("gl4es_glColorMaterial");
#endif
