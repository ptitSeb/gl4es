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
    LOAD_GLES(glLightModelf);
    switch (pname) {
        case GL_LIGHT_MODEL_TWO_SIDE:
            errorGL();
            glstate->light.two_side = param;
            gles_glLightModelf(pname, param);
			break;
        case GL_LIGHT_MODEL_AMBIENT:
        default:
            errorShim(GL_INVALID_ENUM);
            //printf("stubbed glLightModelf(%i, %.2f)\n", pname, param);
            break;
    }
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
    LOAD_GLES(glLightModelfv);
    LOAD_GLES(glLightModelf);
    switch (pname) {
        case GL_LIGHT_MODEL_AMBIENT:
            if(memcmp(glstate->light.ambient, params, 4*sizeof(GLfloat))==0) {
                noerrorShim();
                return;
            }
            errorGL();
            memcpy(glstate->light.ambient, params, 4*sizeof(GLfloat));
            gles_glLightModelfv(pname, params);
            break;
        case GL_LIGHT_MODEL_TWO_SIDE:
            if(glstate->light.two_side == params[0]) {
                noerrorShim();
                return;
            }
            errorGL();
            glstate->light.two_side = params[0];
            gles_glLightModelf(pname, params[0]);
			break;
        default:
            errorShim(GL_INVALID_ENUM);
            //printf("stubbed glLightModelfv(%i, %p [%.2f])\n", pname, params, params[0]);
            break;
    }
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

void glLightModelf(GLenum pname, GLfloat param) AliasExport("gl4es_glLightModelf");
void glLightModelfv(GLenum pname, const GLfloat* params) AliasExport("gl4es_glLightModelfv");
void glLightfv(GLenum light, GLenum pname, const GLfloat* params) AliasExport("gl4es_glLightfv");
void glLightf(GLenum light, GLenum pname, const GLfloat params) AliasExport("gl4es_glLightf");
#endif
