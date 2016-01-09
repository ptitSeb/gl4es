#include "light.h"

#ifndef USE_ES2
void glshim_glLightModelf(GLenum pname, GLfloat param) {
//printf("%sglLightModelf(%04X, %.2f)\n", (state.list.compiling)?"list":"", pname, param);
    if (glstate.list.compiling && glstate.list.active) {
		GLfloat dummy[4];
		dummy[0]=param;
		glshim_glLightModelfv(pname, dummy);
		return;
	}
    LOAD_GLES(glLightModelf);
    switch (pname) {
        case GL_LIGHT_MODEL_AMBIENT:
        case GL_LIGHT_MODEL_TWO_SIDE:
            errorGL();
            gles_glLightModelf(pname, param);
			break;
        default:
            errorShim(GL_INVALID_ENUM);
            //printf("stubbed glLightModelf(%i, %.2f)\n", pname, param);
            break;
    }
}

void glshim_glLightModelfv(GLenum pname, const GLfloat* params) {
//printf("%sglLightModelfv(%04X, [%.2f, %.2f, %.2f, %.2f])\n", (state.list.compiling)?"list":"", pname, params[0], params[1], params[2], params[3]);
    if (glstate.list.compiling && glstate.list.active) {
		NewStage(glstate.list.active, STAGE_LIGHTMODEL);
/*		if (glstate.list.active->lightmodel)
			glstate.list.active = extend_renderlist(glstate.list.active);*/
		glstate.list.active->lightmodelparam = pname;
		glstate.list.active->lightmodel = (GLfloat*)malloc(4*sizeof(GLfloat));
		memcpy(glstate.list.active->lightmodel, params, 4*sizeof(GLfloat));
        noerrorShim();
		return;
	}
    LOAD_GLES(glLightModelfv);
    switch (pname) {
        case GL_LIGHT_MODEL_AMBIENT:
        case GL_LIGHT_MODEL_TWO_SIDE:
            errorGL();
            gles_glLightModelfv(pname, params);
			break;
        default:
            errorShim(GL_INVALID_ENUM);
            //printf("stubbed glLightModelfv(%i, %p [%.2f])\n", pname, params, params[0]);
            break;
    }
}

void glshim_glLightfv(GLenum light, GLenum pname, const GLfloat* params) {
//printf("%sglLightfv(%04X, %04X, [%.2f, %.2f, %.2f, %.2f])\n", (state.list.compiling)?"list":"", light, pname, params[0], params[1], params[2], params[3]);
    if (glstate.list.compiling && glstate.list.active) {
		NewStage(glstate.list.active, STAGE_LIGHT);
		rlLightfv(glstate.list.active, light, pname, params);
        noerrorShim();
		return;
	}
    LOAD_GLES(glLightfv);
    gles_glLightfv(light, pname, params);
    errorGL();
}

void glshim_glLightf(GLenum light, GLenum pname, const GLfloat params) {
	GLfloat dummy[4];
	dummy[0]=params;
	glshim_glLightfv(light, pname, dummy);
    errorGL();
}

void glLightModelf(GLenum pname, GLfloat param) __attribute__((alias("glshim_glLightModelf")));
void glLightModelfv(GLenum pname, const GLfloat* params) __attribute__((alias("glshim_glLightModelfv")));
void glLightfv(GLenum light, GLenum pname, const GLfloat* params) __attribute__((alias("glshim_glLightfv")));
void glLightf(GLenum light, GLenum pname, const GLfloat params) __attribute__((alias("glshim_glLightf")));
#endif
