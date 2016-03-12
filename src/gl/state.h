#include "gl.h"

#ifndef GL_STATE_H
#define GL_STATE_H

#include "eval.h"
#include "texture.h"
#include "buffers.h"

typedef struct {
    GLboolean line_stipple,
              auto_normal,
              blend,
              color_sum,
              texgen_s[MAX_TEX],
              texgen_t[MAX_TEX],
              texgen_r[MAX_TEX],
              texture_2d[MAX_TEX],
              texture_3d[MAX_TEX],
              texture_1d[MAX_TEX];
} enable_state_t;


typedef struct {
    GLenum S;
    GLenum T;
    GLenum R;
    GLfloat S_E[4]; // Eye Plane
    GLfloat T_E[4];
    GLfloat R_E[4];
    GLfloat S_O[4]; // Object Plane
    GLfloat T_O[4];
    GLfloat R_O[4];
} texgen_state_t;

typedef struct {
    GLuint unpack_row_length,
           unpack_skip_pixels,
           unpack_skip_rows,
           unpack_image_height;
    GLboolean unpack_lsb_first;
    // TODO: use those values
    GLuint pack_row_length,
           pack_skip_pixels,
           pack_skip_rows,
           pack_image_height;
    GLboolean pack_lsb_first;
    // TODO: do we only need to worry about GL_TEXTURE_2D?
    GLboolean rect_arb[MAX_TEX];
    gltexture_t *bound[MAX_TEX];
    khash_t(tex) *list;
    GLuint active;	// active texture
	GLuint client;	// client active texture
} texture_state_t;

typedef struct {
    renderlist_t *active;
    GLboolean compiling;
    GLboolean locked;
    GLuint base;
    GLuint name;
    GLenum mode;

    GLuint count;
    GLuint cap;
} displaylist_state_t;


typedef struct {
    map_state_t *vertex3,
                *vertex4,
                *index,
                *color4,
                *normal,
                *texture1,
                *texture2,
                *texture3,
                *texture4;
} map_states_t;

typedef struct {
	int		top;
	GLuint	*names;
} namestack_t;

typedef struct {
	GLuint  count;
    GLuint *buffer;
    GLuint  size;
    GLfloat zmin;
    GLfloat zmax;
    GLuint  overflow;
    GLuint  pos;
    GLboolean  hit;
} selectbuf_t;

typedef struct {
	int		top;
	GLfloat	*stack;
} matrixstack_t;

typedef enum {
    ENABLED_ALPHA,
    ENABLED_BLEND,
    ENABLED_CULL,
    ENABLED_DEPTH,
    ENABLED_TEX2D,
    ENABLED_LAST
} statbatch_enabled_t;

typedef struct {
    int    active_tex_changed;
    GLenum active_tex;  // only 1 active texture for now
    GLenum bound_targ;
    GLenum bound_tex;
    int enabled[ENABLED_LAST];    // the enabled are: 0=not set, 1=enabled, 2=disabled
    GLenum blendfunc_s;
    GLenum blendfunc_d;
} statebatch_t;

typedef struct {
    GLboolean   vertex_array,
                color_array,
                normal_array,
                tex_coord_array[MAX_TEX];
} clientstate_t;

typedef struct {
    int dummy[16];  // dummy zone, test for memory overwriting...
    displaylist_state_t list;
    enable_state_t enable;
    map_state_t *map_grid;
    map_states_t map1, map2;
    renderlist_t **lists;
    texgen_state_t texgen[MAX_TEX];
    texture_state_t texture;
    GLfloat color[4];
    GLfloat secondary[4];
    GLfloat texcoord[MAX_TEX][4];
    GLfloat normal[3];
    int	render_mode;
    int polygon_mode;
    namestack_t namestack;
    matrixstack_t *modelview_matrix;
    matrixstack_t *projection_matrix;
    matrixstack_t **texture_matrix;
    selectbuf_t selectbuf;
    khash_t(glvao) *vaos;
    khash_t(buff) *buffers;
    glvao_t *vao;
    glbuffer_t *defaultvbo; 
    glvao_t *defaultvao;
    int shim_error;
    GLenum last_error;
    GLuint gl_batch;
    GLint vp[4];
    statebatch_t statebatch;
    clientstate_t clientstate;
} glstate_t;

#endif
