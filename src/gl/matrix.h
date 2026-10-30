#ifndef _GL4ES_MATRIX_H_
#define _GL4ES_MATRIX_H_

#include "gl4es.h"
#include "gles.h"
#include "glstate.h"
#include "list.h"
#include "matvec.h"

void APIENTRY_GL4ES gl4es_glMatrixMode(GLenum mode);
void APIENTRY_GL4ES gl4es_glPushMatrix(void);
void APIENTRY_GL4ES gl4es_glPopMatrix(void);
void APIENTRY_GL4ES gl4es_glLoadMatrixf(const GLfloat * m);
void APIENTRY_GL4ES gl4es_glMultMatrixf(const GLfloat * m);
void APIENTRY_GL4ES gl4es_glLoadIdentity(void);
void APIENTRY_GL4ES gl4es_glTranslatef(GLfloat x, GLfloat y, GLfloat z);
void APIENTRY_GL4ES gl4es_glScalef(GLfloat x, GLfloat y, GLfloat z);
void APIENTRY_GL4ES gl4es_glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
void APIENTRY_GL4ES gl4es_glOrthof(GLfloat left, GLfloat right, GLfloat bottom, GLfloat top, GLfloat nearVal, GLfloat farVal);
void APIENTRY_GL4ES gl4es_glFrustumf(GLfloat left,	GLfloat right, GLfloat bottom, GLfloat top,	GLfloat nearVal, GLfloat farVal);

static inline GLfloat* getTexMat(int tmu) {
	return glstate->texture_matrix[tmu]->stack+glstate->texture_matrix[tmu]->top*16;
}

static inline GLfloat* getMVMat() {
	return glstate->modelview_matrix->stack+glstate->modelview_matrix->top*16;
}

static inline GLfloat* getInvMVMat() {
	if(glstate->inv_mv_matrix_dirty) {
		matrix_inverse(glstate->modelview_matrix->stack+glstate->modelview_matrix->top*16, glstate->inv_mv_matrix);
		glstate->inv_mv_matrix_dirty = 0;
	}
	return glstate->inv_mv_matrix;
}
static inline GLfloat* getNormalMat() {
	if(glstate->normal_matrix_dirty) {
		matrix_inverse3_transpose(glstate->modelview_matrix->stack+glstate->modelview_matrix->top*16, glstate->normal_matrix);
		glstate->normal_matrix_dirty = 0;
	}
	return glstate->normal_matrix;
}

static inline GLfloat* getPMat() {
	return glstate->projection_matrix->stack+glstate->projection_matrix->top*16;
}

static inline GLfloat* getMVPMat()
{
	if(glstate->mvp_matrix_dirty) {
		matrix_mul(getPMat(), getMVMat(), glstate->mvp_matrix);
		glstate->mvp_matrix_dirty = 0;
	}
	return glstate->mvp_matrix;
}

/* Transient MV/P poke. Never use public glPushMatrix: a full stack
 * would GL_STACK_OVERFLOW and silently skip the draw. Always dirty
 * mvp / inv_mv / normal on poke and restore so a getInvMVMat /
 * getNormalMat during the poke cannot leave a stale-but-clean cache. */
typedef struct {
    GLfloat mv[16];
    GLfloat p[16];
    int mv_identity;
    int p_identity;
} gl4es_mvp_save_t;

void gl4es_mat_mark_dirty(void);
void gl4es_mvp_save(gl4es_mvp_save_t *s);
void gl4es_mvp_restore(const gl4es_mvp_save_t *s);
void gl4es_mvp_load_identity(void);
void gl4es_mvp_poke_proj_zbias(GLfloat d);
GLfloat gl4es_polygon_offset_ndc_d(void);

#endif // _GL4ES_MATRIX_H_
