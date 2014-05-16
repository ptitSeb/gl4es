#include "light.h"

#ifndef USE_ES2
void glLightModelf(GLenum pname, GLfloat param) {
    LOAD_GLES(glLightModelf);
    switch (pname) {
        case GL_LIGHT_MODEL_AMBIENT:
        case GL_LIGHT_MODEL_TWO_SIDE:
            gles_glLightModelf(pname, param);
			break;
        default:
            //printf("stubbed glLightModelf(%i, %.2f)\n", pname, param);
            break;
    }
}

void glLightModelfv(GLenum pname, const GLfloat* params) {
    if (state.list.active) {
		NewStage(state.list.active, STAGE_LIGHTMODEL);
/*		if (state.list.active->lightmodel)
			state.list.active = extend_renderlist(state.list.active);*/
		state.list.active->lightmodelparam = pname;
		state.list.active->lightmodel = (GLfloat*)malloc(4*sizeof(GLfloat));
		memcpy(state.list.active->lightmodel, params, 4*sizeof(GLfloat));
		return;
	}
    LOAD_GLES(glLightModelfv);
    switch (pname) {
        case GL_LIGHT_MODEL_AMBIENT:
        case GL_LIGHT_MODEL_TWO_SIDE:
            gles_glLightModelfv(pname, params);
			break;
        default:
            //printf("stubbed glLightModelfv(%i, %p)\n", pname, params);
            break;
    }
}

void glLightfv(GLenum light, GLenum pname, const GLfloat* params) {
    if (state.list.active) {
		NewStage(state.list.active, STAGE_LIGHT);
		rlLightfv(state.list.active, light, pname, params);
		return;
	}
    LOAD_GLES(glLightfv);
    gles_glLightfv(light, pname, params);
}
#endif
