#include "gl.h"

#ifndef GL_STATE_H
#define GL_STATE_H

#include "eval.h"
#include "texture.h"
#include "buffers.h"
#include "queries.h"
#include "light.h"

typedef struct _glstack_t glstack_t;
typedef struct _glclientstack_t glclientstack_t;

typedef struct {
    GLboolean line_stipple,
              auto_normal,
              blend,
              color_sum,
              pointsprite,
              texgen_s[MAX_TEX],
              texgen_t[MAX_TEX],
              texgen_r[MAX_TEX],
              texgen_q[MAX_TEX];
    GLuint    texture[MAX_TEX]; // flag
} enable_state_t;

typedef struct {
    GLenum S;
    GLenum T;
    GLenum R;
    GLenum Q;
    GLfloat S_E[4]; // Eye Plane
    GLfloat T_E[4];
    GLfloat R_E[4];
    GLfloat Q_E[4];
    GLfloat S_O[4]; // Object Plane
    GLfloat T_O[4];
    GLfloat R_O[4];
    GLfloat Q_O[4];
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
    gltexture_t *bound[MAX_TEX][ENABLED_TEXTURE_LAST];
    GLboolean pscoordreplace[MAX_TEX];
    khash_t(tex) *list;
    GLuint active;	// active texture
	GLuint client;	// client active texture
} texture_state_t;

typedef struct {
    renderlist_t *active;
    GLboolean compiling;
    GLboolean pending;
    GLboolean begin;
    GLboolean locked;
    GLuint base;
    GLuint name;
    GLenum mode;

    GLuint count;
    GLuint cap;
} displaylist_state_t;

typedef struct {
    rasterpos_t rPos;
    viewport_t viewport;
    GLfloat raster_scale[4];
    GLfloat raster_bias[4];
    GLfloat raster_zoomx;
    GLfloat raster_zoomy;
} raster_state_t;


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
    GLfloat zminoverall;
    GLfloat zmaxoverall;
    GLuint  overflow;
    GLuint  pos;
    GLboolean  hit;
} selectbuf_t;

typedef struct {
	int		top;
    int     identity;
	GLfloat	*stack;
} matrixstack_t;

typedef enum {
    ENABLED_ALPHA,
    ENABLED_BLEND,
    ENABLED_CULL,
    ENABLED_DEPTH,
    ENABLED_TEX2D_TEX0,
    ENABLED_TEX2D_TEX1,
    ENABLED_TEX2D_TEX2,
    ENABLED_TEX2D_TEX3,
    ENABLED_TEX2D_TEX4,
    ENABLED_TEX2D_TEX5,
    ENABLED_TEX2D_TEX6,
    ENABLED_TEX2D_TEX7,
    ENABLED_LAST
} statbatch_enabled_t;

typedef struct {
    int    active_tex_changed;
    GLenum active_tex;  // current active texture
    GLenum bound_targ[MAX_TEX];
    GLenum bound_tex[MAX_TEX];
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
    int matrix_mode;
    selectbuf_t selectbuf;
    khash_t(glvao) *vaos;
    khash_t(buff) *buffers;
    glvao_t *vao;
    glbuffer_t *defaultvbo; 
    glvao_t *defaultvao;
    int shim_error;
    GLenum last_error;
    GLuint gl_batch;
    int init_batch;
    GLint vp[4];
    statebatch_t statebatch;
    clientstate_t clientstate;
    khash_t(queries) *queries;
    glstack_t *stack;
    glclientstack_t *clientStack;
    raster_state_t raster;
    int emulatedPixmap;
    int emulatedWin;
    int shared_cnt;
    light_state_t light;
    material_state_t material;
} glstate_t;

#endif
