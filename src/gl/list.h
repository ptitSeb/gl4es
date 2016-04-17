#include "gl.h"

#ifndef DISPLAY_LIST_H
#define DISPLAY_LIST_H

typedef enum {
	STAGE_NONE = 0,
	STAGE_PUSH,
	STAGE_POP,
	STAGE_CALLLIST,
	STAGE_GLCALL,
	STAGE_FOG,
    STAGE_MATRIX,
    STAGE_ACTIVETEX,
	STAGE_BINDTEX,
	STAGE_RASTER,
	STAGE_MATERIAL,
	STAGE_LIGHT,
	STAGE_LIGHTMODEL,
	STAGE_TEXGEN,
	STAGE_POLYGON,
	STAGE_DRAW,
	STAGE_LAST
} liststage_t;

static int StageExclusive[STAGE_LAST] = {
	0, 	// STAGE_NONE
	1,	// STAGE_PUSH
	1,  // STAGE_POP
	1, 	// STAGE_CALLLIST
	0,  // STAGE_GLCALL
	1, 	// STAGE_FOG
    1,  // STAGE_MATRIX
    1,  // STAGE_ACTIVETEX
	1,  // STAGE_BINDTEX
	1,  // STAGE_RASTER
	0,  // STAGE_MATERIAL
	0,  // STAGE_LIGHT
	1,  // STAGE_LIGTMODEL
	0,  // STAGE_TEXGEN
	1,  // STAGE_POLYGON
	1   // STAGE_DRAW
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
} rasterlist_t;

KHASH_MAP_INIT_INT(material, rendermaterial_t *)
KHASH_MAP_INIT_INT(light, renderlight_t *)
KHASH_MAP_INIT_INT(texgen, rendertexgen_t *)

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
    GLfloat lastSecondaryColors[3];

    call_list_t calls;
    
    GLboolean shared_arrays;
    GLfloat *vert;
    GLfloat *normal;
    GLfloat *color;
    GLfloat *secondary;
    GLfloat *tex[MAX_TEX];
    GLushort *indices;
    unsigned int indice_cap;
	
	GLuint	glcall_list;
	rasterlist_t *raster;
	
	liststage_t	stage;
	
	GLbitfield pushattribute;
	GLboolean  popattribute;
    
    int     raster_op;
    GLfloat raster_xyz[3];
    
    int     matrix_op;
    GLfloat matrix_val[16];
    
    int     fog_op;
    GLfloat fog_val[4];
    
    khash_t(material) *material;
    khash_t(light) *light;
    khash_t(texgen) *texgen;
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

#define DEFAULT_CALL_LIST_CAPACITY 20
#define DEFAULT_RENDER_LIST_CAPACITY 64

#define NewStage(l, s) if (l->stage+StageExclusive[l->stage] > s) {l = extend_renderlist(l);} l->stage = s

renderlist_t* GetFirst(renderlist_t* list);

extern renderlist_t *alloc_renderlist();
extern renderlist_t *extend_renderlist(renderlist_t *list);
extern void free_renderlist(renderlist_t *list);
extern void draw_renderlist(renderlist_t *list);
extern void end_renderlist(renderlist_t *list);

extern void rlActiveTexture(renderlist_t *list, GLenum texture );
extern void rlBindTexture(renderlist_t *list, GLenum target, GLuint texture);
extern void rlColor4f(renderlist_t *list, GLfloat r, GLfloat g, GLfloat b, GLfloat a);
extern void rlMaterialfv(renderlist_t *list, GLenum face, GLenum pname, const GLfloat * params);
extern void rlLightfv(renderlist_t *list, GLenum which, GLenum pname, const GLfloat * params);
extern void rlTexGenfv(renderlist_t *list, GLenum coord, GLenum pname, const GLfloat * params);
extern void rlNormal3f(renderlist_t *list, GLfloat x, GLfloat y, GLfloat z);
extern void rlPushCall(renderlist_t *list, packed_call_t *data);
extern void rlTexCoord4f(renderlist_t *list, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
extern void rlMultiTexCoord4f(renderlist_t *list, GLenum texture, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
extern void rlVertex4f(renderlist_t *list, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
extern void rlSecondary3f(renderlist_t *list, GLfloat r, GLfloat g, GLfloat b);
extern void rlRasterOp(renderlist_t *list, int op, GLfloat x, GLfloat y, GLfloat z);
extern void rlFogOp(renderlist_t *list, int op, const GLfloat* v);
#endif
