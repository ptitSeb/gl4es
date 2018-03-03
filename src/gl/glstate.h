#ifndef _GL_STATE_H_
#define _GL_STATE_H_

#include "stack.h"

typedef struct {
    int                 dummy[16];  // dummy zone, test for memory overwriting...
    displaylist_state_t list;
    enable_state_t      enable;
    map_grid_t          map_grid[2];
    map_states_t        map1, map2;
    khash_t(gllisthead) *headlists;
    texgen_state_t      texgen[MAX_TEX];
    texenv_state_t      texenv[MAX_TEX];
    texture_state_t     texture;
    GLfloat             vertex[4];
    GLfloat             color[4];
    GLfloat             secondary[4];
    GLfloat             texcoord[MAX_TEX][4];
    GLfloat             normal[3];
    GLfloat             fogcoord;
    GLboolean           colormask[4];
    int	                render_mode;
    int                 polygon_mode;
    namestack_t         namestack;
    GLfloat             mvp_matrix[16];
    int                 mvp_matrix_dirty;
    GLfloat             inv_mv_matrix[16];
    int                 inv_mv_matrix_dirty;
    GLfloat             normal_matrix[9];
    int                 normal_matrix_dirty;
    matrixstack_t       *modelview_matrix;
    matrixstack_t       *projection_matrix;
    matrixstack_t       **texture_matrix;
    int                 matrix_mode;
    selectbuf_t         selectbuf;
    khash_t(glvao)      *vaos;
    khash_t(buff)       *buffers;
    glvao_t             *vao;
    glbuffer_t          *defaultvbo; 
    glvao_t             *defaultvao;
    int                 shim_error;
    GLenum              last_error;
    GLuint              gl_batch;
    int                 init_batch;
    GLint               vp[4];
    statebatch_t        statebatch;
    clientstate_t       clientstate;
    khash_t(queries)    *queries;
    glstack_t           *stack;
    glclientstack_t     *clientStack;
    raster_state_t      raster;
    GLuint              actual_tex2d[MAX_TEX]; // store the texture actually boundon TEX2D unit, because it's shared...
    int                 bound_changed; // 0 if not changed or max TMU if changed...
    int                 fpe_bound_changed; // same but for fpe
#ifdef TEXSTREAM
    int                 bound_stream[MAX_TEX];
#endif
    int                 emulatedPixmap;
    int                 emulatedWin;
    int                 shared_cnt;
    light_state_t       light;
    fog_t               fog;
    material_state_t    material;
    float               planes[MAX_CLIP_PLANES][4];
    pointsprite_t       pointsprite;
    linestipple_t       linestipple;
    int                 immediateMV;
    GLenum              shademodel;
    GLenum              alphafunc;
    GLfloat             alpharef;
    GLenum              blendsfactorrgb;
    GLenum              blenddfactorrgb;
    GLenum              blendsfactoralpha;
    GLenum              blenddfactoralpha;
    GLenum              logicop;
    glsl_t              glsl;
    fpe_state_t         *fpe_state;
    fpe_fpe_t           *fpe;
    fpestatus_t         fpe_client;
    fpe_cache_t         *fpe_cache;
    gleshard_t          gleshard;
    glesblit_t          *blit;
    fbo_t               fbo;
    int                 filterpostupload;   // does the program seems to set filter after uploading texture?
    int                 scratch_alloc;
    void*               scratch;
    int                 merger_cap;
    GLfloat*            merger_master;
    GLfloat*            merger_secondary;
    GLfloat*            merger_tex[MAX_TEX-2];
    int                 merger_indice_cap;
    GLushort*           merger_indices;
    int                 merger_used;
    GLenum              readf; // implementation Read Format
    GLenum              readt; // implementation Read Type
} glstate_t;


#endif //_GL_STATE_H_