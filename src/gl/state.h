#include "gl.h"

#ifndef GL_STATE_H
#define GL_STATE_H

#include "eval.h"
#include "texture.h"
#include "buffers.h"

typedef struct {
    GLboolean line_stipple,
              blend,
              color_sum,
              secondary_array,
              color_array,
              normal_array,
              vertex_array,
              tex_coord_array[MAX_TEX],
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
    GLfloat Sv[4];
    GLfloat Tv[4];
    GLfloat Rv[4];
} texgen_state_t;

typedef struct {
    GLuint unpack_row_length,
           unpack_skip_pixels,
           unpack_skip_rows;
    GLboolean unpack_lsb_first;
    // TODO: use those values
    GLuint pack_row_length,
           pack_skip_pixels,
           pack_skip_rows;
    GLboolean pack_lsb_first;
    // TODO: do we only need to worry about GL_TEXTURE_2D?
    GLboolean rect_arb[MAX_TEX];
    gltexture_t *bound[MAX_TEX];
    khash_t(tex) *list;
    GLuint active;	// active texture
	GLuint client;	// client active texture
} texture_state_t;


typedef struct {
    GLint size;
    GLenum type;
    GLsizei stride;
    glbuffer_t *buffer;
    const GLvoid *pointer;
} pointer_state_t;

typedef struct {
    pointer_state_t vertex, color, normal, tex_coord[MAX_TEX], secondary;
} pointer_states_t;


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
	int count;
    GLuint *buffer;
    GLuint size;	
} selectbuf_t;

typedef struct {
	int		top;
	GLfloat	*stack;
} matrixstack_t;

typedef struct {
    glbuffer_t *vertex;
    glbuffer_t *elements;
    glbuffer_t *pack;
    glbuffer_t *unpack;
    khash_t(buff) *list;
} buffers_t;


typedef struct {
    displaylist_state_t list;
    enable_state_t enable;
    map_state_t *map_grid;
    map_states_t map1, map2;
    pointer_states_t pointers;
    renderlist_t **lists;
    texgen_state_t texgen[MAX_TEX];
    texture_state_t texture;
    GLfloat color[4];
    GLfloat secondary[4];
    GLfloat texcoord[MAX_TEX][2];
    GLfloat normal[3];
    int	render_mode;
    int polygon_mode;
    namestack_t namestack;
    matrixstack_t *modelview_matrix;
    matrixstack_t *projection_matrix;
    matrixstack_t **texture_matrix;
    selectbuf_t selectbuf;
    buffers_t buffers;
    int shim_error;
    GLenum last_error;
    GLuint gl_batch;
    GLint vp[4];
} glstate_t;

#endif
