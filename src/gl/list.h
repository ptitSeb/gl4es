#include "gl.h"

#ifndef DISPLAY_LIST_H
#define DISPLAY_LIST_H

typedef enum {
	STAGE_NONE = 0,
	STAGE_PUSH,
	STAGE_POP,
	STAGE_GLCALL,
    STAGE_RENDER,
	STAGE_FOG,
    STAGE_POINTPARAM,
    STAGE_MATRIX,
    STAGE_ACTIVETEX,
	STAGE_BINDTEX,
	STAGE_RASTER,
	STAGE_MATERIAL,
    STAGE_COLOR_MATERIAL,
	STAGE_LIGHT,
	STAGE_LIGHTMODEL,
    STAGE_LINESTIPPLE,
	STAGE_TEXENV,
	STAGE_TEXGEN,
	STAGE_POLYGON,
	STAGE_DRAW,
    STAGE_POSTDRAW,
	STAGE_LAST
} liststage_t;

static int StageExclusive[] = {
	0, 	// STAGE_NONE
	1,	// STAGE_PUSH
	1,  // STAGE_POP
	0,  // STAGE_GLCALL
    1,  // STAGE_RENDER
	1, 	// STAGE_FOG
	1, 	// STAGE_POINTPARAM
    1,  // STAGE_MATRIX
    1,  // STAGE_ACTIVETEX
	1,  // STAGE_BINDTEX
	1,  // STAGE_RASTER
	0,  // STAGE_MATERIAL
    1,  // STAGE_COLOR_MATERIAL
	0,  // STAGE_LIGHT
	1,  // STAGE_LIGTMODEL
    1,  // STAGE_LINESTIPPLE
	0,  // STAGE_TEXENV
	0,  // STAGE_TEXGEN
	1,  // STAGE_POLYGON
	1,  // STAGE_DRAW
    1,  // STAGE_POSTDRAW   (used for "pending", i.e. post glEnd(), in case a similar glBegin occurs)
    0   // STAGE_LAST
};

typedef struct {
    int face;
    int pname;
    GLfloat color[4];
    int count;
} rendermaterial_t;

typedef struct {
    int which;
    int pname;
    GLfloat color[4];
    int count;
} renderlight_t;

typedef struct {
    int coord;
    int pname;
    GLfloat color[4];
    int count;
} rendertexgen_t;

typedef struct {
    int target;
    int pname;
    GLfloat params[4];
    int count;
} rendertexenv_t;

typedef struct {
	GLfloat	xmove;
	GLfloat ymove;
	GLsizei width;
	GLsizei height;
	GLfloat xorig;
	GLfloat yorig;
	GLfloat zoomx;
	GLfloat zoomy;
	GLboolean bitmap;
	GLuint	texture;
    int     *shared;
} rasterlist_t;

KHASH_MAP_INIT_INT(material, rendermaterial_t *)
KHASH_MAP_INIT_INT(light, renderlight_t *)
KHASH_MAP_INIT_INT(texgen, rendertexgen_t *)
KHASH_MAP_INIT_INT(texenv, rendertexenv_t *)

typedef struct _call_list_t {
    unsigned long len;
    unsigned long cap;
    packed_call_t **calls;
} call_list_t;

typedef struct _renderlist_t {
    unsigned long len;
    unsigned long ilen;
    unsigned long cap;
    GLenum mode;
    GLenum mode_init;		// initial requested mode
    GLfloat lastNormal[3];
    GLfloat lastColors[4];
    GLfloat lastSecondaryColors[4];

    int lastColorsSet;

    int*        shared_calls;
    call_list_t calls;
    
    int *shared_arrays;
    GLfloat *vert;
    GLfloat *normal;
    GLfloat *color;
    GLfloat *secondary;
    GLfloat *tex[MAX_TEX];
    int *shared_indices;
    GLushort *indices;
    unsigned int indice_cap;
	
	rasterlist_t *raster;
	
	liststage_t	stage;
	
	GLbitfield pushattribute;
	GLboolean  popattribute;
    
    int     render_op;
    GLuint  render_arg;

    int     raster_op;
    GLfloat raster_xyz[3];
    
    int     matrix_op;
    GLfloat matrix_val[16];
    
    int     fog_op;
    GLfloat fog_val[4];

    int     pointparam_op;
    GLfloat pointparam_val[4];

    int     linestipple_op;
    GLuint  linestipple_factor, linestipple_pattern;

    int     post_color;
    GLfloat post_colors[4];
    int     post_normal;
    GLfloat post_normals[3];
    
    khash_t(material) *material;
    GLenum  colormat_face;
    GLenum  colormat_mode;
    khash_t(light) *light;
    khash_t(texgen) *texgen;
    khash_t(texenv) *texenv;
    GLfloat	*lightmodel;
    GLenum	lightmodelparam;
    GLenum	polygon_mode;
    GLboolean set_tmu;      // TRUE is glActiveTexture called
    int tmu;             // the current TMU...
    GLuint texture;				
    GLenum target_texture;      
    GLboolean  set_texture;
    struct _renderlist_t *prev;
    struct _renderlist_t *next;
    GLboolean open;
} renderlist_t;

KHASH_MAP_INIT_INT(gllisthead, renderlist_t*)

#define DEFAULT_CALL_LIST_CAPACITY 20
#define DEFAULT_RENDER_LIST_CAPACITY 64

renderlist_t* recycle_renderlist(renderlist_t* list);
#define NewDrawStage(l, m) if(globals4es.mergelist \
            && ((l->prev && isempty_renderlist(l) && l->prev->open && l->prev->mode==mode && l->prev->mode_init==mode)  \
            || (l->stage==STAGE_POSTDRAW && l->open && l->mode==mode && l->mode_init==mode))  && \
            mode!=GL_POLYGON && mode!=GL_LINE_STRIP && mode!=GL_LINE_LOOP && \
            mode!=GL_TRIANGLE_FAN && mode!=GL_TRIANGLE_STRIP && mode!=GL_QUAD_STRIP) \
                l=recycle_renderlist(l); else NewStage(l, STAGE_DRAW)
#define NewStage(l, s) if (l->stage+StageExclusive[l->stage] > s) {l = extend_renderlist(l);} l->stage = s

renderlist_t* GetFirst(renderlist_t* list);

renderlist_t *alloc_renderlist();
renderlist_t *extend_renderlist(renderlist_t *list);
void free_renderlist(renderlist_t *list);
void draw_renderlist(renderlist_t *list);
renderlist_t* end_renderlist(renderlist_t *list);
bool isempty_renderlist(renderlist_t *list);

void rlActiveTexture(renderlist_t *list, GLenum texture );
void rlBindTexture(renderlist_t *list, GLenum target, GLuint texture);
void rlColor4f(renderlist_t *list, GLfloat r, GLfloat g, GLfloat b, GLfloat a) FASTMATH;
void rlMaterialfv(renderlist_t *list, GLenum face, GLenum pname, const GLfloat * params);
void rlLightfv(renderlist_t *list, GLenum which, GLenum pname, const GLfloat * params);
void rlTexGenfv(renderlist_t *list, GLenum coord, GLenum pname, const GLfloat * params);
void rlTexEnvfv(renderlist_t *list, GLenum target, GLenum pname, const GLfloat * params);
void rlTexEnviv(renderlist_t *list, GLenum target, GLenum pname, const GLint * params);
void rlNormal3f(renderlist_t *list, GLfloat x, GLfloat y, GLfloat z) FASTMATH;
void rlPushCall(renderlist_t *list, packed_call_t *data);
void rlMultiTexCoord4f(renderlist_t *list, GLenum texture, GLfloat s, GLfloat t, GLfloat r, GLfloat q) FASTMATH;
void rlVertex4f(renderlist_t *list, GLfloat x, GLfloat y, GLfloat z, GLfloat w) FASTMATH;
void rlSecondary3f(renderlist_t *list, GLfloat r, GLfloat g, GLfloat b) FASTMATH;
void rlRasterOp(renderlist_t *list, int op, GLfloat x, GLfloat y, GLfloat z) FASTMATH;
void rlFogOp(renderlist_t *list, int op, const GLfloat* v);
void rlPointParamOp(renderlist_t *list, int op, const GLfloat* v);
#endif
