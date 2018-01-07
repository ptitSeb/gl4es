#include "gl.h"
#include "debug.h"
#include "../glx/hardext.h"
#include "init.h"
#include "matrix.h"
#include "fpe.h"

glstate_t *glstate = NULL;

glstate_t *default_glstate = NULL;

void init_matrix(glstate_t* glstate);

void* NewGLState(void* shared_glstate, int es2only) {
    if(shared_glstate) {
        glstate_t* glstate = (glstate_t*)shared_glstate;
        glstate->shared_cnt++;
        return (void*)glstate;
    }
    glstate_t *glstate = (glstate_t*)malloc(sizeof(glstate_t));
	GLfloat white[] = {1.0f, 1.0f, 1.0f, 1.0f};
	memset(glstate, 0, sizeof(glstate_t));
	memcpy(glstate->color, white, sizeof(GLfloat)*4);
	glstate->last_error = GL_NO_ERROR;
    glstate->normal[2] = 1.0f; // default normal is 0/0/1
    glstate->matrix_mode = GL_MODELVIEW;
    
    // add default VBO
    {
        khint_t k;
        int ret;
        khash_t(buff) *list = glstate->buffers = kh_init(buff);
        k = kh_put(buff, list, 0, &ret);
        glbuffer_t *buff = kh_value(list, k) = malloc(sizeof(glbuffer_t));
        buff->buffer = 0;
        buff->type = 0;
        buff->data = NULL;
        buff->usage = GL_STATIC_DRAW;
        buff->size = 0;
        buff->access = GL_READ_WRITE;
        buff->mapped = 0;
        glstate->defaultvbo = buff;
    }
    // add default VAO
    {
        khint_t k;
        int ret;
        khash_t(glvao) *list = glstate->vaos = kh_init(glvao);
        k = kh_put(glvao, list, 0, &ret);
        glvao_t *glvao = kh_value(list, k) = malloc(sizeof(glvao_t));
        // new vao is binded to default vbo
        VaoInit(glvao);
        // just put is number
        glvao->array = 0;
        glstate->defaultvao = glvao;
    }
    // initialize gllists
    {
        khint_t k;
        int ret;
        khash_t(gllisthead) *list = glstate->headlists = kh_init(gllisthead);
		kh_put(gllisthead, list, 1, &ret);
		kh_del(gllisthead, list, 1);
    }
    // Bind defaults...
    glstate->vao = glstate->defaultvao;

    glstate->shared_cnt = 0;

    glstate->gl_batch = globals4es.batch;

    //raster & viewport
    glstate->raster.raster_zoomx=1.0f;
    glstate->raster.raster_zoomy=1.0f;
    glstate->raster.map_i2i_size=1;
    glstate->raster.map_i2r_size=1;
    glstate->raster.map_i2g_size=1;
    glstate->raster.map_i2b_size=1;
    glstate->raster.map_i2a_size=1;
    /*
    glstate->raster.map_s2s_size=1;
    glstate->raster.map_r2r_size=1;
    glstate->raster.map_g2g_size=1;
    glstate->raster.map_b2b_size=1;
    glstate->raster.map_a2a_size=1;
    */

    // pack & unpack alignment
    glstate->texture.pack_align = 4;
    glstate->texture.unpack_align = 4;

    // eval
    glstate->map_grid[0]._2 = 1.0f;
    glstate->map_grid[0].n = 1;
    glstate->map_grid[0].d = 1.0f;
    glstate->map_grid[1]._2 = 1.0f;
    glstate->map_grid[1].n = 1;
    glstate->map_grid[1].d = 1.0f;
    
    // line stipple
    glstate->linestipple.factor = 1;
    glstate->linestipple.pattern = 0xFFFF;
    glstate->linestipple.data = (GLubyte *)malloc(sizeof(GLubyte) * 16);
        memset(glstate->linestipple.data, 0xff, sizeof(GLubyte) * 16);
    glstate->linestipple.texture = 0;    
    
    // fpe
    if(hardext.esversion>1) {
        glstate->fpe_state = (fpe_state_t*)malloc(sizeof(fpe_state_t));
        memset(glstate->fpe_state, 0, sizeof(fpe_state_t));
        glstate->glsl.es2 = es2only;
        fpe_Init(glstate);
    }

    // init the matrix tracking
    init_matrix(glstate);

    // init the light tracking
    glstate->light.ambient[0]=glstate->light.ambient[1]=glstate->light.ambient[2]=0.2f;
    glstate->light.ambient[3]=1.0f;
    glstate->light.lights[0].diffuse[0]=
    glstate->light.lights[0].diffuse[1]=
    glstate->light.lights[0].diffuse[2]=
    glstate->light.lights[0].diffuse[3]=1.0f;
    memcpy(glstate->light.lights[0].specular, glstate->light.lights[0].diffuse, 4*sizeof(GLfloat));
    for (int i=0; i<hardext.maxlights; i++) {
        glstate->light.lights[i].ambient[3] = 1.0f;
        glstate->light.lights[i].position[2] = 1.0f;
        glstate->light.lights[i].spotDirection[2] = -1.0f;
        glstate->light.lights[i].spotCutoff = 180;
        glstate->light.lights[i].constantAttenuation = 1;
    }
    // Materials
    glstate->material.front.ambient[0] = 
    glstate->material.front.ambient[1] =
    glstate->material.front.ambient[2] = 0.2f;
    glstate->material.front.ambient[3] = 1.0f;
    glstate->material.front.diffuse[0] = 
    glstate->material.front.diffuse[1] =
    glstate->material.front.diffuse[2] = 0.8f;
    glstate->material.front.diffuse[3] = 1.0f;
    glstate->material.front.specular[3] = 1.0f;
    glstate->material.front.emission[3] = 1.0f;
    glstate->material.front.colormat = GL_AMBIENT_AND_DIFFUSE;
    memcpy(&glstate->material.back, &glstate->material.front, sizeof(material_t));
    // Fog
    glstate->fog.mode = GL_EXP;
    glstate->fog.density = 1.0f;
    glstate->fog.end = 1.0f;
    glstate->fog.coord_src = GL_FRAGMENT_DEPTH;
    // Alpha Func
    glstate->alphafunc = GL_ALWAYS;
    glstate->alpharef = 0.0f;
    // Blend
    glstate->blendsfactorrgb = GL_ONE;
    glstate->blenddfactorrgb = GL_ZERO;
    glstate->blendsfactoralpha = GL_ONE;
    glstate->blenddfactoralpha = GL_ZERO;
    // Point Sprite
    glstate->pointsprite.size = 1.0f;
    glstate->pointsprite.sizeMax = 32.0f;   // spec indicate 1., but it seems it's set to hardware limit, so puting 32...
    glstate->pointsprite.fadeThresholdSize = 1.0f;
    glstate->pointsprite.distance[0] = 1.0f;
    glstate->pointsprite.coordOrigin = GL_UPPER_LEFT;
    // Color Mask
    for(int i=0; i<4; i++)
        glstate->colormask[i] = 1;
    // Raster
    for(int i=0; i<4; i++)
        glstate->raster.raster_scale[i] = 1.0f;
    // ShadeModel
    glstate->shademodel = GL_SMOOTH;
    // TexEnv
    for (int i=0; i<hardext.maxtex; i++) {
        glstate->texenv[i].env.mode = GL_MODULATE;
        glstate->texenv[i].env.rgb_scale = 1.0f;
        glstate->texenv[i].env.alpha_scale = 1.0f;
        glstate->texenv[i].env.src0_rgb = glstate->texenv[i].env.src0_alpha = GL_TEXTURE;
        glstate->texenv[i].env.src1_rgb = glstate->texenv[i].env.src1_alpha = GL_PREVIOUS;
        glstate->texenv[i].env.src2_rgb = glstate->texenv[i].env.src2_alpha = GL_CONSTANT;
        glstate->texenv[i].env.op0_rgb = glstate->texenv[i].env.op1_rgb = GL_SRC_COLOR;
        glstate->texenv[i].env.op2_rgb = glstate->texenv[i].env.op0_alpha = 
        glstate->texenv[i].env.op1_alpha = glstate->texenv[i].env.op2_alpha = GL_SRC_ALPHA;
    }
    // TexGen
    for (int i=0; i<hardext.maxtex; i++) {
        glstate->texgen[i].S = GL_EYE_LINEAR;
        glstate->texgen[i].T = GL_EYE_LINEAR;
        glstate->texgen[i].R = GL_EYE_LINEAR;
        glstate->texgen[i].Q = GL_EYE_LINEAR;
        glstate->texgen[i].S_E[0] = 1.0;
        glstate->texgen[i].S_O[0] = 1.0;
        glstate->texgen[i].T_E[1] = 1.0;
        glstate->texgen[i].T_O[1] = 1.0;
    }

    // fpe
    if(hardext.esversion>1) {
        glstate->fpe_state = (fpe_state_t*)malloc(sizeof(fpe_state_t));
        memset(glstate->fpe_state, 0, sizeof(fpe_state_t));
        glstate->glsl.es2 = es2only;
        fpe_Init(glstate);
        // some default are not 0...
        for (int i=0; i<hardext.maxtex; i++) {
            //TexEnv Combine that are not 0
            glstate->fpe_state->texsrcrgb[1] |= FPE_SRC_PREVIOUS<<(i*4);
            glstate->fpe_state->texsrcalpha[1] |= FPE_SRC_PREVIOUS<<(i*4);
            glstate->fpe_state->texsrcrgb[2] |= FPE_SRC_CONSTANT<<(i*4);
            glstate->fpe_state->texsrcalpha[2] |= FPE_SRC_CONSTANT<<(i*4);
            glstate->fpe_state->texoprgb[0] |= FPE_OP_SRCCOLOR<<(i*2);
            glstate->fpe_state->texoprgb[1] |= FPE_OP_SRCCOLOR<<(i*2);
        }            
    }

    // GLSL stuff
    {
        khint_t k;
        int ret;
        khash_t(shaderlist) *shaders = glstate->glsl.shaders = kh_init(shaderlist);
		kh_put(shaderlist, shaders, 1, &ret);
		kh_del(shaderlist, shaders, 1);
        khash_t(programlist) *programs = glstate->glsl.programs = kh_init(programlist);
		kh_put(programlist, programs, 1, &ret);
		kh_del(programlist, programs, 1);
    }

    // Grab ViewPort
    LOAD_GLES(glGetIntegerv);
    gles_glGetIntegerv(GL_VIEWPORT, (GLint*)&glstate->raster.viewport);
    // FBO
    glstate->fbo.mainfbo_width = glstate->raster.viewport.width;    //main_fbo get the initial dimension of the framebuffer
    glstate->fbo.mainfbo_height = glstate->raster.viewport.height;
    glstate->fbo.mainfbo_nwidth = (hardext.npot)?glstate->fbo.mainfbo_width:npot(glstate->fbo.mainfbo_width);
    glstate->fbo.mainfbo_nheight = (hardext.npot)?glstate->fbo.mainfbo_height:npot(glstate->fbo.mainfbo_height);
    // Get the per/context hardware values
    gles_glGetIntegerv(GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES, &glstate->readf);
    gles_glGetIntegerv(GL_IMPLEMENTATION_COLOR_READ_TYPE_OES, &glstate->readt);
    //printf("LIBGL: Implementation Read is %s/%s\n", PrintEnum(hardext.readf), PrintEnum(hardext.readt));

    // All done
    return (void*)glstate;
}


void DeleteGLState(void* oldstate) {
    glstate_t* state = (glstate_t*)state;
    if(!state) return;

    if(state->shared_cnt) {
        --state->shared_cnt;
        return;
    }

    if(glstate == state)
        glstate = NULL;


    #define free_hashmap(T, N, K, F)        \
    {                                       \
        T *m;                               \
        kh_foreach_value(state->N, m,       \
            F(m);                        \
        )                                   \
        kh_destroy(K, state->N);            \
    }
    free_hashmap(glvao_t, vaos, glvao, free);
    free_hashmap(glbuffer_t, buffers, buff, free);
    free_hashmap(glquery_t, queries, queries, free);
    free_hashmap(gltexture_t, texture.list, tex, free);
    free_hashmap(renderlist_t, headlists, gllisthead, free_renderlist);
    #undef free_hashmap
    // free eval maps
    #define freemap(dims, name)                              \
    { map_statef_t *m = (map_statef_t *)state->map##dims.name; \
    if (m) {                                                \
        free((void *)m->points);                            \
        free(m);                                            \
    } }
    freemap(1, vertex3); freemap(1, vertex4); freemap(1, index); freemap(1, color4); freemap(1, normal); 
    freemap(1, texture1); freemap(1, texture2); freemap(1, texture3); freemap(1, texture4);   
    freemap(2, vertex3); freemap(2, vertex4); freemap(2, index); freemap(2, color4); freemap(2, normal); 
    freemap(2, texture1); freemap(2, texture2); freemap(2, texture3); freemap(2, texture4);   
    #undef freemap
    // free active list
    if(state->list.active) free_renderlist(state->list.active);

    // free matrix stack
    #define free_matrix(A)                  \
        if (state->A) {                   \
    	    free(state->A->stack);    \
            free(state->A);               \
        }
	free_matrix(projection_matrix);
	free_matrix(modelview_matrix);
	for (int i=0; i<MAX_TEX; i++)
		free_matrix(texture_matrix[i]);
	free(glstate->texture_matrix);
    #undef free_matrix
    // linestipple
    if(state->linestipple.data)
        free(state->linestipple.data);
    // fbo
    if(state->fbo.tex_fbo)
        free(state->fbo.tex_fbo);
    // raster / bitmap
    if(state->raster.data)
        free(state->raster.data);
    if(state->raster.bitmap)
        free(state->raster.bitmap);
    // TODO: delete the "immediate" stuff and bitmap texture?
    // scratch buffer
    if(state->scratch)
        free(state->scratch);
    // free blit GLES2 stuff
    if(state->blit) {
        //TODO: check if should delete GL object too
        free(state->blit);
    }
    //TODO: free sharderlist and programlist...
    if(state->fpe_cache) {
        fpe_Dispose(state);
    }
    // probably missing some things to free here!

    // all done
    free(state);
    return;
}

void ActivateGLState(void* new_glstate) {
    if(glstate == (glstate_t*)new_glstate) return;  // same state, nothing to do
    if (glstate && glstate->gl_batch) flush();
    glstate = (new_glstate)?(glstate_t*)new_glstate:default_glstate;
    // check if viewport is correct
    if(glstate->raster.viewport.width==0.0f || glstate->raster.viewport.height==0.0f) {
        LOAD_GLES(glGetFloatv);
        gles_glGetFloatv(GL_VIEWPORT, (GLfloat*)&glstate->raster.viewport);
    }
    if (globals4es.batch && glstate->init_batch==0) init_batch();
}

void gl_init() {
    default_glstate = (glstate_t*)NewGLState(NULL, 0);
    ActivateGLState(default_glstate);
}

static void fpe_changeplane(int n, bool enable)
{
    glstate->fpe = NULL;
    if(enable)
        glstate->fpe_state->plane |= 1<<n;
    else
        glstate->fpe_state->plane &= ~(1<<n);
}
static void fpe_changelight(int n, bool enable)
{
    glstate->fpe = NULL;
    if(enable)
        glstate->fpe_state->light |= 1<<n;
    else
        glstate->fpe_state->light &= ~(1<<n);
}
static void fpe_changetex(int n)
{
    if(glstate->fpe_bound_changed < n+1)
        glstate->fpe_bound_changed = n+1;
}
#define generate_changetexgen(C) \
static void fpe_changetexgen_##C(int n, bool enable) \
{ \
    if(enable) \
        glstate->fpe_state->texgen_##C |= 1<<n; \
    else \
        glstate->fpe_state->texgen_##C &= ~(1<<n); \
}
generate_changetexgen(s)
generate_changetexgen(t)
generate_changetexgen(r)
generate_changetexgen(q)
#undef generate_changetexgen

#ifndef GL_TEXTURE_STREAM_IMG  
#define GL_TEXTURE_STREAM_IMG                                   0x8C0D     
#endif

static void proxy_glEnable(GLenum cap, bool enable, void (*next)(GLenum)) {
    #define proxy_GO(constant, name) \
        case constant: if(glstate->enable.name != enable) {glstate->enable.name = enable; next(cap);} break
    #define proxy_GOFPE(constant, name, fct) \
        case constant: if(glstate->enable.name != enable) {glstate->enable.name = enable; if(glstate->fpe_state) { fct; } else next(cap);} break
    #define GO(constant, name) \
        case constant: glstate->enable.name = enable; break;
    #define GOFPE(constant, name, fct) \
        case constant: glstate->enable.name = enable; if(glstate->fpe_state) { fct; } break;
    #define proxy_clientGO(constant, name) \
        case constant: if (glstate->vao->name != enable) {glstate->vao->name = enable; next(cap);} break
    #define clientGO(constant, name) \
        case constant: glstate->vao->name = enable; break;
    #define clientGO_proxyFPE(constant, name) \
        case constant: glstate->vao->name = enable; if(glstate->fpe_state) { next(cap);} break;
    // Alpha Hack
    if (globals4es.alphahack && (cap==GL_ALPHA_TEST) && enable) {
        if (glstate->texture.bound[glstate->texture.active][ENABLED_TEX2D])
            if (!glstate->texture.bound[glstate->texture.active][ENABLED_TEX2D]->alpha)
                enable = false;
    }
	noerrorShim();
#ifdef TEXSTREAM
    if (cap==GL_TEXTURE_STREAM_IMG) {
        if(enable)
            glstate->enable.texture[glstate->texture.active] |= (1<<ENABLED_TEX2D);
        else
            glstate->enable.texture[glstate->texture.active] &= ~(1<<ENABLED_TEX2D);
        if(glstate->fpe_state)
            fpe_changetex(glstate->texture.active);
        else
            next(cap);
        return;
    }
#endif

    switch (cap) {
        GO(GL_AUTO_NORMAL, auto_normal);
        proxy_GOFPE(GL_ALPHA_TEST, alpha_test,glstate->fpe_state->alphatest=enable);
        proxy_GOFPE(GL_FOG, fog, glstate->fpe_state->fog=enable);
        proxy_GO(GL_BLEND, blend);
        proxy_GO(GL_CULL_FACE, cull_face);
        proxy_GO(GL_DEPTH_TEST, depth_test);
        case GL_TEXTURE_2D:
            if(enable)
                glstate->enable.texture[glstate->texture.active] |= (1<<ENABLED_TEX2D);
            else
                glstate->enable.texture[glstate->texture.active] &= ~(1<<ENABLED_TEX2D);
            if(glstate->fpe_state)
                fpe_changetex(glstate->texture.active);
            else
                next(cap);
            break;

        // texgen
        GOFPE(GL_TEXTURE_GEN_S, texgen_s[glstate->texture.active], fpe_changetexgen_s(glstate->texture.active, enable)); //TODO: FPE stuffs
        GOFPE(GL_TEXTURE_GEN_T, texgen_t[glstate->texture.active], fpe_changetexgen_t(glstate->texture.active, enable));
        GOFPE(GL_TEXTURE_GEN_R, texgen_r[glstate->texture.active], fpe_changetexgen_r(glstate->texture.active, enable));
        GOFPE(GL_TEXTURE_GEN_Q, texgen_q[glstate->texture.active], fpe_changetexgen_q(glstate->texture.active, enable));
        GO(GL_LINE_STIPPLE, line_stipple);

        // clip plane
        proxy_GOFPE(GL_CLIP_PLANE0, plane[0], fpe_changeplane(0, enable));
        proxy_GOFPE(GL_CLIP_PLANE1, plane[1], fpe_changeplane(1, enable));
        proxy_GOFPE(GL_CLIP_PLANE2, plane[2], fpe_changeplane(2, enable));
        proxy_GOFPE(GL_CLIP_PLANE3, plane[3], fpe_changeplane(3, enable));
        proxy_GOFPE(GL_CLIP_PLANE4, plane[4], fpe_changeplane(4, enable));
        proxy_GOFPE(GL_CLIP_PLANE5, plane[5], fpe_changeplane(5, enable));

        // lights
        proxy_GOFPE(GL_LIGHT0, light[0], fpe_changelight(0, enable));
        proxy_GOFPE(GL_LIGHT1, light[1], fpe_changelight(1, enable));
        proxy_GOFPE(GL_LIGHT2, light[2], fpe_changelight(2, enable));
        proxy_GOFPE(GL_LIGHT3, light[3], fpe_changelight(3, enable));
        proxy_GOFPE(GL_LIGHT4, light[4], fpe_changelight(4, enable));
        proxy_GOFPE(GL_LIGHT5, light[5], fpe_changelight(5, enable));
        proxy_GOFPE(GL_LIGHT6, light[6], fpe_changelight(6, enable));
        proxy_GOFPE(GL_LIGHT7, light[7], fpe_changelight(7, enable));
        proxy_GOFPE(GL_LIGHTING, lighting, glstate->fpe_state->lighting=enable);
        proxy_GOFPE(GL_NORMALIZE, normalize, glstate->fpe_state->normalize=enable);
        proxy_GOFPE(GL_RESCALE_NORMAL, normal_rescale, glstate->fpe_state->rescaling=enable);
        proxy_GOFPE(GL_COLOR_MATERIAL, color_material, glstate->fpe_state->color_material=enable);

        // point sprite
        proxy_GOFPE(GL_POINT_SPRITE, pointsprite, glstate->fpe_state->pointsprite=enable); // TODO: plugin fpe stuffs

        // Smooth and multisample (todo: do somthing with fpe?)
        proxy_GOFPE(GL_MULTISAMPLE, multisample, );
        proxy_GOFPE(GL_SAMPLE_COVERAGE, sample_coverage, );
        proxy_GOFPE(GL_SAMPLE_ALPHA_TO_COVERAGE, sample_alpha_to_coverage, );
        proxy_GOFPE(GL_SAMPLE_ALPHA_TO_ONE, sample_alpha_to_one, );
        proxy_GOFPE(GL_POINT_SMOOTH, point_smooth, );
        proxy_GOFPE(GL_LINE_SMOOTH, line_smooth, );

        // color logic op
        proxy_GOFPE(GL_COLOR_LOGIC_OP, color_logic_op, );
        
        // Secondary color
        GOFPE(GL_COLOR_SUM, color_sum, glstate->fpe_state->colorsum = enable);
        //cannot use clientGO_proxyFPE here, has the ClientArray are really enabled / disabled elsewhere in fact (inside glDraw or list_draw)
        clientGO(GL_SECONDARY_COLOR_ARRAY, secondary_array);
        clientGO(GL_FOG_COORD_ARRAY, fog_array);
	
        // for glDrawArrays
        clientGO(GL_VERTEX_ARRAY, vertex_array);
        clientGO(GL_NORMAL_ARRAY, normal_array);
        clientGO(GL_COLOR_ARRAY, color_array);
        clientGO(GL_TEXTURE_COORD_ARRAY, tex_coord_array[glstate->texture.client]);

        // map eval
        GO(GL_MAP1_COLOR_4 , map1_color4);
        GO(GL_MAP1_INDEX , map1_index);
        GO(GL_MAP1_NORMAL , map1_normal);
        GO(GL_MAP1_TEXTURE_COORD_1 , map1_texture1);
        GO(GL_MAP1_TEXTURE_COORD_2 , map1_texture2);
        GO(GL_MAP1_TEXTURE_COORD_3 , map1_texture3);
        GO(GL_MAP1_TEXTURE_COORD_4 , map1_texture4);
        GO(GL_MAP1_VERTEX_3 , map1_vertex3);
        GO(GL_MAP1_VERTEX_4 , map1_vertex4);
        GO(GL_MAP2_COLOR_4 , map2_color4);
        GO(GL_MAP2_INDEX , map2_index);
        GO(GL_MAP2_NORMAL , map2_normal);
        GO(GL_MAP2_TEXTURE_COORD_1 , map2_texture1);
        GO(GL_MAP2_TEXTURE_COORD_2 , map2_texture2);
        GO(GL_MAP2_TEXTURE_COORD_3 , map2_texture3);
        GO(GL_MAP2_TEXTURE_COORD_4 , map2_texture4);
        GO(GL_MAP2_VERTEX_3 , map2_vertex3);
        GO(GL_MAP2_VERTEX_4 , map2_vertex4);
        
        // Texture 1D and 3D
        case GL_TEXTURE_1D:
            if(enable)
                glstate->enable.texture[glstate->texture.active] |= (1<<ENABLED_TEX1D);
            else
                glstate->enable.texture[glstate->texture.active] &= ~(1<<ENABLED_TEX1D);
            if(glstate->fpe_state)
                fpe_changetex(glstate->texture.active);
            break;
        case GL_TEXTURE_3D:
            if(enable)
                glstate->enable.texture[glstate->texture.active] |= (1<<ENABLED_TEX3D);
            else
                glstate->enable.texture[glstate->texture.active] &= ~(1<<ENABLED_TEX3D);
            if(glstate->fpe_state)
                fpe_changetex(glstate->texture.active);
            break;
        case GL_TEXTURE_RECTANGLE_ARB:
            if(enable)
                glstate->enable.texture[glstate->texture.active] |= (1<<ENABLED_TEXTURE_RECTANGLE);
            else
                glstate->enable.texture[glstate->texture.active] &= ~(1<<ENABLED_TEXTURE_RECTANGLE);
            if(glstate->fpe_state)
                fpe_changetex(glstate->texture.active);
            break;
        case GL_TEXTURE_CUBE_MAP:
            if(enable)
                glstate->enable.texture[glstate->texture.active] |= (1<<ENABLED_CUBE_MAP);
            else
                glstate->enable.texture[glstate->texture.active] &= ~(1<<ENABLED_CUBE_MAP);
            if(glstate->fpe_state)
                fpe_changetex(glstate->texture.active);
            else
                next(cap);
            break;

        
        default: errorGL(); next(cap); break;
    }
    #undef proxy_GO
    #undef GO
    #undef proxy_clientGO
    #undef clientGO
}

int Cap2BatchState(GLenum cap) {
        switch (cap) {
            case GL_ALPHA_TEST: return ENABLED_ALPHA;
            case GL_BLEND: return ENABLED_BLEND;
            case GL_CULL_FACE: return ENABLED_CULL;
            case GL_DEPTH_TEST: return ENABLED_DEPTH;
            case GL_TEXTURE_2D: return  ENABLED_TEX2D_TEX0
                +(glstate->statebatch.active_tex_changed?glstate->statebatch.active_tex-GL_TEXTURE0:glstate->texture.active); 
        }
        return ENABLED_LAST;
}
int Enabled2BatchState(int cap) {
    switch(cap) {
        case ENABLED_ALPHA: return 2-glstate->enable.alpha_test;
        case ENABLED_BLEND: return 2-glstate->enable.blend;
        case GL_CULL_FACE: return 2-glstate->enable.cull_face;
        case GL_DEPTH_TEST: return 2-glstate->enable.depth_test;
        default:
            return (IS_TEX2D(glstate->enable.texture[cap-ENABLED_TEX2D_TEX0]))?1:2;
    }
}

void gl4es_glEnable(GLenum cap) {
    if (glstate->list.active && (glstate->gl_batch && !glstate->list.compiling))  {
        int which_cap = Cap2BatchState(cap);
        if (which_cap<ENABLED_LAST) {
            if(glstate->statebatch.enabled[which_cap]==0)
                glstate->statebatch.enabled[which_cap] = Enabled2BatchState(which_cap);
            if ((glstate->statebatch.enabled[which_cap] == 1))
                return; // nothing to do...
            flush();
            if (glstate->list.active)   // change value only if still in list
                glstate->statebatch.enabled[which_cap] = 1;
        }
    }
	PUSH_IF_COMPILING(glEnable)
#ifdef TEXSTREAM
	if (globals4es.texstream && (cap==GL_TEXTURE_2D)) {
		if (glstate->texture.bound[glstate->texture.active][ENABLED_TEX2D])
			if (glstate->texture.bound[glstate->texture.active][ENABLED_TEX2D]->streamed)
				cap = GL_TEXTURE_STREAM_IMG;
	}
	if (globals4es.texstream && (cap==GL_TEXTURE_RECTANGLE_ARB)) {
		if (glstate->texture.bound[glstate->texture.active][ENABLED_TEXTURE_RECTANGLE])
			if (glstate->texture.bound[glstate->texture.active][ENABLED_TEXTURE_RECTANGLE]->streamed)
				cap = GL_TEXTURE_STREAM_IMG;
	}
#endif
    LOAD_GLES(glEnable);
    proxy_glEnable(cap, true, gles_glEnable);
}
void glEnable(GLenum cap) AliasExport("gl4es_glEnable");

void gl4es_glDisable(GLenum cap) {
    if (glstate->list.active && (glstate->gl_batch && !glstate->list.compiling))  {
        int which_cap = Cap2BatchState(cap);
        if (which_cap<ENABLED_LAST) {
            if(glstate->statebatch.enabled[which_cap]==0)
                glstate->statebatch.enabled[which_cap] = Enabled2BatchState(which_cap);
            if ((glstate->statebatch.enabled[which_cap] == 2))
                return; // nothing to do...
            flush();
            if (glstate->list.active)   // change value only if still in list
                glstate->statebatch.enabled[which_cap] = 2;
        }
    }
	PUSH_IF_COMPILING(glDisable)
        
#ifdef TEXSTREAM
	if (globals4es.texstream && (cap==GL_TEXTURE_2D)) {
		if (glstate->texture.bound[glstate->texture.active][ENABLED_TEX2D])
			if (glstate->texture.bound[glstate->texture.active][ENABLED_TEX2D]->streamed)
				cap = GL_TEXTURE_STREAM_IMG;
	}
	if (globals4es.texstream && (cap==GL_TEXTURE_RECTANGLE_ARB)) {
		if (glstate->texture.bound[glstate->texture.active][ENABLED_TEXTURE_RECTANGLE])
			if (glstate->texture.bound[glstate->texture.active][ENABLED_TEXTURE_RECTANGLE]->streamed)
				cap = GL_TEXTURE_STREAM_IMG;
	}
#endif
    LOAD_GLES(glDisable);
    proxy_glEnable(cap, false, gles_glDisable);
}
void glDisable(GLenum cap) AliasExport("gl4es_glDisable");

void gl4es_glEnableClientState(GLenum cap) {
    ERROR_IN_BEGIN
    // should flush for now... to be optimized later!
    if (glstate->list.active && !glstate->list.compiling)
        flush();
    LOAD_GLES_FPE(glEnableClientState);
    proxy_glEnable(cap, true, gles_glEnableClientState);
}
void glEnableClientState(GLenum cap) AliasExport("gl4es_glEnableClientState");

void gl4es_glDisableClientState(GLenum cap) {
    ERROR_IN_BEGIN
    // should flush for now... to be optimized later!
    if (glstate->list.active && !glstate->list.compiling)
        flush();
    LOAD_GLES_FPE(glDisableClientState);
    proxy_glEnable(cap, false, gles_glDisableClientState);
}
void glDisableClientState(GLenum cap) AliasExport("gl4es_glDisableClientState");


#define isenabled(what, where) \
    case what: return glstate->enable.where
#define clientisenabled(what, where) \
    case what: return glstate->vao->where
    
GLboolean gl4es_glIsEnabled(GLenum cap) {
    if(glstate->list.begin) {errorShim(GL_INVALID_OPERATION); return GL_FALSE;}
    if(glstate->list.compiling) {errorShim(GL_INVALID_OPERATION); return GL_FALSE;}
    // should flush for now... to be optimized later!
    if (glstate->list.active)
        flush();
    LOAD_GLES(glIsEnabled);
    noerrorShim();
    switch (cap) {
        isenabled(GL_AUTO_NORMAL, auto_normal);
        isenabled(GL_ALPHA_TEST, alpha_test);
        isenabled(GL_FOG, fog);
        isenabled(GL_BLEND, blend);
        isenabled(GL_CULL_FACE, cull_face);
        isenabled(GL_DEPTH_TEST, depth_test);
        isenabled(GL_LINE_STIPPLE, line_stipple);
        isenabled(GL_TEXTURE_GEN_S, texgen_s[glstate->texture.active]);
        isenabled(GL_TEXTURE_GEN_T, texgen_t[glstate->texture.active]);
        isenabled(GL_TEXTURE_GEN_R, texgen_r[glstate->texture.active]);
        isenabled(GL_TEXTURE_GEN_Q, texgen_q[glstate->texture.active]);
        isenabled(GL_COLOR_MATERIAL, color_material);
		isenabled(GL_COLOR_SUM, color_sum);
        isenabled(GL_POINT_SPRITE, pointsprite);
        isenabled(GL_CLIP_PLANE0, plane[0]);
        isenabled(GL_CLIP_PLANE1, plane[1]);
        isenabled(GL_CLIP_PLANE2, plane[2]);
        isenabled(GL_CLIP_PLANE3, plane[3]);
        isenabled(GL_CLIP_PLANE4, plane[4]);
        isenabled(GL_CLIP_PLANE5, plane[5]);
        isenabled(GL_LIGHT0, light[0]);
        isenabled(GL_LIGHT1, light[1]);
        isenabled(GL_LIGHT2, light[2]);
        isenabled(GL_LIGHT3, light[3]);
        isenabled(GL_LIGHT4, light[4]);
        isenabled(GL_LIGHT5, light[5]);
        isenabled(GL_LIGHT6, light[6]);
        isenabled(GL_LIGHT7, light[7]);
        isenabled(GL_LIGHTING, lighting);
        isenabled(GL_MULTISAMPLE, multisample);
        isenabled(GL_SAMPLE_COVERAGE, sample_coverage);
        isenabled(GL_SAMPLE_ALPHA_TO_COVERAGE, sample_alpha_to_coverage);
        isenabled(GL_SAMPLE_ALPHA_TO_ONE, sample_alpha_to_one);
        isenabled(GL_POINT_SMOOTH, point_smooth);
        isenabled(GL_LINE_SMOOTH, line_smooth);
        isenabled(GL_COLOR_LOGIC_OP, color_logic_op);
        clientisenabled(GL_SECONDARY_COLOR_ARRAY, secondary_array);
        clientisenabled(GL_FOG_COORD_ARRAY, fog_array);
        case GL_TEXTURE_1D: return glstate->enable.texture[glstate->texture.active]&(1<<ENABLED_TEX1D);
        case GL_TEXTURE_2D: return glstate->enable.texture[glstate->texture.active]&(1<<ENABLED_TEX2D);
        case GL_TEXTURE_3D: return glstate->enable.texture[glstate->texture.active]&(1<<ENABLED_TEX3D);
        case GL_TEXTURE_CUBE_MAP: return glstate->enable.texture[glstate->texture.active]&(1<<ENABLED_CUBE_MAP);
        clientisenabled(GL_VERTEX_ARRAY, vertex_array);
        clientisenabled(GL_NORMAL_ARRAY, normal_array);
        clientisenabled(GL_COLOR_ARRAY, color_array);
        clientisenabled(GL_TEXTURE_COORD_ARRAY, tex_coord_array[glstate->texture.client]);
        isenabled(GL_NORMALIZE, normalize);
        isenabled(GL_RESCALE_NORMAL, normal_rescale);
        isenabled(GL_MAP1_COLOR_4, map1_color4);
        isenabled(GL_MAP1_INDEX, map1_index);
        isenabled(GL_MAP1_NORMAL, map1_normal);
        isenabled(GL_MAP1_TEXTURE_COORD_1, map1_texture1);
        isenabled(GL_MAP1_TEXTURE_COORD_2, map1_texture2);
        isenabled(GL_MAP1_TEXTURE_COORD_3, map1_texture3);
        isenabled(GL_MAP1_TEXTURE_COORD_4, map1_texture4);
        isenabled(GL_MAP1_VERTEX_3, map1_vertex3);
        isenabled(GL_MAP1_VERTEX_4, map1_vertex4);
        isenabled(GL_MAP2_COLOR_4, map2_color4);
        isenabled(GL_MAP2_INDEX, map2_index);
        isenabled(GL_MAP2_NORMAL, map2_normal);
        isenabled(GL_MAP2_TEXTURE_COORD_1, map2_texture1);
        isenabled(GL_MAP2_TEXTURE_COORD_2, map2_texture2);
        isenabled(GL_MAP2_TEXTURE_COORD_3, map2_texture3);
        isenabled(GL_MAP2_TEXTURE_COORD_4, map2_texture4);
        isenabled(GL_MAP2_VERTEX_3, map2_vertex3);
        isenabled(GL_MAP2_VERTEX_4, map2_vertex4);
        default:
			errorGL();
            return gles_glIsEnabled(cap);
    }
}
#undef isenabled
#undef clientisenabled
GLboolean glIsEnabled(GLenum cap) AliasExport("gl4es_glIsEnabled");

static GLboolean is_cache_compatible(GLsizei count) {
    #define T2(AA, A, B) \
    if(glstate->vao->AA!=glstate->vao->B.enabled) return GL_FALSE; \
    if(glstate->vao->B.enabled && memcmp(&glstate->vao->pointers.A, &glstate->vao->B.state, sizeof(pointer_state_t))) return GL_FALSE;
    #define TEST(A,B) T2(A##_array, A, B)
    #define TESTA(A,B,I) T2(A##_array[i], A[i], B[i])

    if(glstate->vao == glstate->defaultvao) return GL_FALSE;
    if(count > glstate->vao->cache_count) return GL_FALSE;
    TEST(vertex, vert)
    TEST(color, color)
    TEST(secondary, secondary)
    TEST(fog, fog)
    TEST(normal, normal)
    for (int i=0; i<hardext.maxtex; i++) {
        TESTA(tex_coord,tex,i)
    }
    #undef TESTA
    #undef TEST
    #undef T2
    return GL_TRUE;
}

static renderlist_t *arrays_to_renderlist(renderlist_t *list, GLenum mode,
                                        GLsizei skip, GLsizei count) {
    if (! list)
        list = alloc_renderlist();
//if (glstate->list.compiling) LOGD("arrary_to_renderlist while compiling list, skip=%d, count=%d\n", skip, count);
    list->mode = mode;
    list->mode_init = mode;
    list->len = count-skip;
    list->cap = count-skip;

    // check cache if any
    if(glstate->vao->shared_arrays)  {
        if (!is_cache_compatible(count))
            VaoSharedClear(glstate->vao);
    }
    
    if(glstate->vao->shared_arrays) {
        #define OP(A, N) (A)?A+skip*N:NULL
        list->vert = OP(glstate->vao->vert.ptr,4);
        list->color = OP(glstate->vao->color.ptr,4);
        list->secondary = OP(glstate->vao->secondary.ptr,4);
        list->fogcoord = OP(glstate->vao->fog.ptr, 1);
        list->normal = OP(glstate->vao->normal.ptr,3);
        for (int i=0; i<hardext.maxtex; i++) 
            list->tex[i] = OP(glstate->vao->tex[i].ptr,4);
        #undef OP
        
        list->shared_arrays = glstate->vao->shared_arrays;
        (*glstate->vao->shared_arrays)++;
    } else {
        if(!globals4es.novaocache && glstate->vao != glstate->defaultvao) {
            // prepare a vao cache object
            list->shared_arrays = glstate->vao->shared_arrays = (int*)malloc(sizeof(int));
            *glstate->vao->shared_arrays = 1;
            #define G2(AA, A, B) \
            glstate->vao->B.enabled = glstate->vao->AA; \
            if (glstate->vao->B.enabled) memcpy(&glstate->vao->B.state, &glstate->vao->pointers.A, sizeof(pointer_state_t));
            #define GO(A,B) G2(A##_array, A, B)
            #define GOA(A,B,I) G2(A##_array[i], A[i], B[i])
            GO(vertex, vert)
            GO(color, color)
            GO(secondary, secondary)
            GO(fog, fog)
            GO(normal, normal)
            for (int i=0; i<hardext.maxtex; i++) {
                GOA(tex_coord,tex,i)
            }
            glstate->vao->cache_count = count;
            #undef GOA
            #undef GO
            #undef G2
        }
        if (glstate->vao->vertex_array) {
            if(glstate->vao->shared_arrays) {
                glstate->vao->vert.ptr = copy_gl_pointer_tex(&glstate->vao->pointers.vertex, 4, 0, count);
                list->vert = glstate->vao->vert.ptr + 4*skip;
            } else
                list->vert = copy_gl_pointer_tex(&glstate->vao->pointers.vertex, 4, skip, count);
        }
        if (glstate->vao->color_array) {
            if(glstate->vao->shared_arrays) {
                if(glstate->vao->pointers.color.size==GL_BGRA)
                    glstate->vao->color.ptr = copy_gl_pointer_color_bgra(&glstate->vao->pointers.color, 4, 0, count);
                else
                    glstate->vao->color.ptr = copy_gl_pointer_color(&glstate->vao->pointers.color, 4, 0, count);
                list->color = glstate->vao->color.ptr + 4*skip;
            } else {
                if(glstate->vao->pointers.color.size==GL_BGRA)
                    list->color = copy_gl_pointer_color_bgra(&glstate->vao->pointers.color, 4, skip, count);
                else
                    list->color = copy_gl_pointer_color(&glstate->vao->pointers.color, 4, skip, count);
            }
        }
        if (glstate->vao->secondary_array/* && glstate->enable.color_array*/) {
            if(glstate->vao->shared_arrays) {
                if(glstate->vao->pointers.secondary.size==GL_BGRA)
                    glstate->vao->secondary.ptr = copy_gl_pointer_color_bgra(&glstate->vao->pointers.secondary, 4, 0, count);
                else
                    glstate->vao->secondary.ptr = copy_gl_pointer(&glstate->vao->pointers.secondary, 4, 0, count);		// alpha chanel is always 0 for secondary...
                    list->secondary = glstate->vao->secondary.ptr + 4*skip;
            } else {
                if(glstate->vao->pointers.secondary.size==GL_BGRA)
                    list->secondary = copy_gl_pointer_color_bgra(&glstate->vao->pointers.secondary, 4, skip, count);
                else
                    list->secondary = copy_gl_pointer(&glstate->vao->pointers.secondary, 4, skip, count);		// alpha chanel is always 0 for secondary...
            }
        }
        if (glstate->vao->normal_array) {
            if(glstate->vao->shared_arrays) {
                glstate->vao->normal.ptr = copy_gl_pointer_raw(&glstate->vao->pointers.normal, 3, 0, count);
                list->normal = glstate->vao->normal.ptr + 3*skip;
            } else
                list->normal = copy_gl_pointer_raw(&glstate->vao->pointers.normal, 3, skip, count);
        }
        if (glstate->vao->fog_array) {
            if(glstate->vao->shared_arrays) {
                glstate->vao->fog.ptr = copy_gl_pointer_raw(&glstate->vao->pointers.fog, 1, 0, count);
                list->fogcoord = glstate->vao->fog.ptr + 1*skip;
            } else
                list->fogcoord = copy_gl_pointer_raw(&glstate->vao->pointers.fog, 1, skip, count);
        }
        for (int i=0; i<hardext.maxtex; i++) {
            if (glstate->vao->tex_coord_array[i]) {
                if(glstate->vao->shared_arrays) {
                    glstate->vao->tex[i].ptr = copy_gl_pointer_tex(&glstate->vao->pointers.tex_coord[i], 4, 0, count);
                    list->tex[i] = glstate->vao->tex[i].ptr + 4*skip;
                } else
                    list->tex[i] = copy_gl_pointer_tex(&glstate->vao->pointers.tex_coord[i], 4, skip, count);
            }
        }
    }
    for (int i=0; i<hardext.maxtex; i++)
        if(list->tex[i] && list->maxtex < i+1) list->maxtex = i+1;
    return list;
}

static inline bool should_intercept_render(GLenum mode) {
    // check bounded tex that will be used if one need some transformations
    for (int aa=0; aa<hardext.maxtex; aa++) {
        if (glstate->enable.texture[aa]) {
            if ((hardext.esversion==1) && ((glstate->enable.texgen_s[aa] || glstate->enable.texgen_t[aa] || glstate->enable.texgen_r[aa] || glstate->enable.texgen_q[aa])))
                return true;
            if ((!glstate->vao->tex_coord_array[aa]) && !(mode==GL_POINT && glstate->texture.pscoordreplace[aa]))
                return true;
            if ((glstate->vao->tex_coord_array[aa]) && (glstate->vao->pointers.tex_coord[aa].size == 1))
                return true;
        }
    }
    if(glstate->polygon_mode == GL_LINE && mode>=GL_TRIANGLES)
        return true;
    if ((hardext.esversion==1) && ((glstate->vao->secondary_array) && (glstate->vao->color_array)))
        return true;
    if ((hardext.esversion==1) && (glstate->vao->color_array && (glstate->vao->pointers.color.size != 4)))
        return true;
    return (
        (glstate->vao->vertex_array && ! valid_vertex_type(glstate->vao->pointers.vertex.type)) ||
        (mode == GL_LINES && glstate->enable.line_stipple) ||
        /*(mode == GL_QUADS) ||*/ (glstate->list.active)
    );
}

GLuint len_indices(GLushort *sindices, GLsizei count) {
    GLuint len = 0;
    for (int i=0; i<count; i++)
        if (len<sindices[i]) len = sindices[i]; // get the len of the arrays
    return len+1;  // lenght is max(indices) + 1 !
}

void gl4es_glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices) {
    //printf("glDrawElements(%s, %d, %s, %p), vtx=%p map=%p\n", PrintEnum(mode), count, PrintEnum(type), indices, (glstate->vao->vertex)?glstate->vao->vertex->data:NULL, (glstate->vao->elements)?glstate->vao->elements->data:NULL);
    // TODO: split for count > 65535?
    // special check for QUADS and TRIANGLES that need multiple of 4 or 3 vertex...
    if(glstate->list.active && !glstate->list.compiling && glstate->gl_batch) 
        flush();
    if (mode == GL_QUADS) while(count%4) count--;
    else if (mode == GL_TRIANGLES) while(count%3) count--;
    
    if (count<0) {
		errorShim(GL_INVALID_VALUE);
		return;
	}
    if (count==0) {
        noerrorShim();
        return;
    }

	noerrorShim();
    GLushort *sindices;
    bool need_free = (type!=GL_UNSIGNED_SHORT);
    if(need_free)
        sindices = copy_gl_array((glstate->vao->elements)?glstate->vao->elements->data + (uintptr_t)indices:indices,
            type, 1, 0, GL_UNSIGNED_SHORT, 1, 0, count);
    else
        sindices = (glstate->vao->elements)?(glstate->vao->elements->data + (uintptr_t)indices):(GLvoid*)indices;
    bool compiling = (glstate->list.active);

    if (compiling) {
        renderlist_t *list = NULL;
        GLsizei min, max;

		NewStage(glstate->list.active, STAGE_DRAW);
        list = glstate->list.active;

        if(need_free) {
            normalize_indices(sindices, &max, &min, count);
            list = arrays_to_renderlist(list, mode, min, max + 1);
            list->indices = sindices;
        } else {
            getminmax_indices(sindices, &max, &min, count);
            list = arrays_to_renderlist(list, mode, min, max + 1);
            list->indices = copy_gl_array(sindices, type, 1, 0, GL_UNSIGNED_SHORT, 1, 0, count);
            if(min) normalize_indices(list->indices, &max, &min, count);
        }
        list->ilen = count;
        list->indice_cap = count;
        //end_renderlist(list);
        
        glstate->list.active = extend_renderlist(list);
        return;
     }

     if (should_intercept_render(mode) || (mode==GL_QUADS)) {
        renderlist_t *list = NULL;
        GLsizei min, max;

        if(need_free) {
            normalize_indices(sindices, &max, &min, count);
            list = arrays_to_renderlist(list, mode, min, max + 1);
            list->indices = sindices;
        } else {
            getminmax_indices(sindices, &max, &min, count);
            list = arrays_to_renderlist(list, mode, min, max + 1);
            list->indices = copy_gl_array(sindices, type, 1, 0, GL_UNSIGNED_SHORT, 1, 0, count);
            if(min) normalize_indices(list->indices, &max, &min, count);
        }
        list->ilen = count;
        list->indice_cap = count;
        list = end_renderlist(list);
        draw_renderlist(list);
        free_renderlist(list);
        
        return;
     } else {
        if (glstate->raster.bm_drawing)
            bitmap_flush();

		LOAD_GLES_FPE(glDrawElements);
		LOAD_GLES_FPE(glNormalPointer);
		LOAD_GLES_FPE(glVertexPointer);
		LOAD_GLES_FPE(glColorPointer);
		LOAD_GLES_FPE(glTexCoordPointer);
        LOAD_GLES_FPE(glEnable);
        LOAD_GLES_FPE(glDisable);
        LOAD_GLES_FPE(glEnableClientState);
        LOAD_GLES_FPE(glDisableClientState);
        LOAD_GLES_FPE(glMultiTexCoord4f);
        GLuint len = 0;
#define client_state(A, B, C) \
            if(glstate->vao->A != glstate->clientstate.A) {           \
                C                                              \
                if((glstate->clientstate.A = glstate->vao->A)==true)  \
                    gles_glEnableClientState(B);                \
                else                                            \
                    gles_glDisableClientState(B);               \
            }


		GLenum mode_init = mode;
		/*if (glstate->polygon_mode == GL_LINE && mode>=GL_TRIANGLES)
			mode = GL_LINE_LOOP;*/
		if (glstate->polygon_mode == GL_POINT && mode>=GL_TRIANGLES)
			mode = GL_POINTS;

		if (mode == GL_QUAD_STRIP)
			mode = GL_TRIANGLE_STRIP;
		if (mode == GL_POLYGON)
			mode = GL_TRIANGLE_FAN;
		if (glstate->render_mode == GL_SELECT) {
			select_glDrawElements(&glstate->vao->pointers.vertex, mode, count, GL_UNSIGNED_SHORT, sindices);
		} else {
            GLuint old_tex = glstate->texture.client;
            
            realize_textures();

            // secondry color and color sizef != 4 are "intercepted" and draw using a list, unless usin ES>1.1
            client_state(color_array, GL_COLOR_ARRAY, );
            if (glstate->vao->color_array)
                gles_glColorPointer(glstate->vao->pointers.color.size, glstate->vao->pointers.color.type, glstate->vao->pointers.color.stride, glstate->vao->pointers.color.pointer);
            if(hardext.esversion>1) {
                client_state(secondary_array, GL_SECONDARY_COLOR_ARRAY, );
                if (glstate->vao->secondary_array)
                    fpe_glSecondaryColorPointer(glstate->vao->pointers.secondary.size, glstate->vao->pointers.secondary.type, glstate->vao->pointers.secondary.stride, glstate->vao->pointers.secondary.pointer);
            }
            client_state(normal_array, GL_NORMAL_ARRAY, );
            if (glstate->vao->normal_array)
                gles_glNormalPointer(glstate->vao->pointers.normal.type, glstate->vao->pointers.normal.stride, glstate->vao->pointers.normal.pointer);
            client_state(vertex_array, GL_VERTEX_ARRAY, );
            if (glstate->vao->vertex_array)
                gles_glVertexPointer(glstate->vao->pointers.vertex.size, glstate->vao->pointers.vertex.type, glstate->vao->pointers.vertex.stride, glstate->vao->pointers.vertex.pointer);
            #define TEXTURE(A) gl4es_glClientActiveTexture(A+GL_TEXTURE0);
            for (int aa=0; aa<hardext.maxtex; aa++) {
                client_state(tex_coord_array[aa], GL_TEXTURE_COORD_ARRAY, TEXTURE(aa););
                // get 1st enabled target
                const GLint itarget = get_target(glstate->enable.texture[aa]);
                if (itarget>=0) {
                    if (!IS_TEX2D(glstate->enable.texture[aa]) && (IS_ANYTEX(glstate->enable.texture[aa]))) {
                        TEXTURE(aa);
                        gles_glEnable(GL_TEXTURE_2D);
                    }
                    if (glstate->vao->tex_coord_array[aa]) {
                        TEXTURE(aa);
                        if(!len) len = len_indices(sindices, count);
                        tex_setup_texcoord(len, itarget);
                    } else
                        gles_glMultiTexCoord4f(GL_TEXTURE0+aa, glstate->texcoord[aa][0], glstate->texcoord[aa][1], glstate->texcoord[aa][2], glstate->texcoord[aa][3]);
                } else if (glstate->clientstate.tex_coord_array[aa] && hardext.esversion!=1) {
                    // special case on GL2, Tex disable but CoordArray enabled...
                    TEXTURE(aa);
                    if(!len) len = len_indices(sindices, count);
                    tex_setup_texcoord(len, ENABLED_TEX2D);
                }
            }
            if (glstate->texture.client!=old_tex)
                TEXTURE(old_tex);

            // POLYGON mode as LINE is "intercepted" and drawn using list
			gles_glDrawElements(mode, count, GL_UNSIGNED_SHORT, sindices);

            for (int aa=0; aa<hardext.maxtex; aa++) {
                if (!IS_TEX2D(glstate->enable.texture[aa]) && (IS_ANYTEX(glstate->enable.texture[aa]))) {
                    TEXTURE(aa);
                    gles_glDisable(GL_TEXTURE_2D);
                }
            }
            if (glstate->texture.client!=old_tex)
                TEXTURE(old_tex);
            #undef TEXTURE
		}
        if(need_free)
            free(sindices);
    }
}
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices) AliasExport("gl4es_glDrawElements");

void gl4es_glDrawArrays(GLenum mode, GLint first, GLsizei count) {
    if(glstate->list.active && !glstate->list.compiling && glstate->gl_batch) 
        flush();
    // special check for QUADS and TRIANGLES that need multiple of 4 or 3 vertex...
    if (mode == GL_QUADS) while(count%4) count--;
    else if (mode == GL_TRIANGLES) while(count%3) count--;

	if (count<0) {
		errorShim(GL_INVALID_VALUE);
		return;
	}
    if (count==0) {
        noerrorShim();
        return;
    }

    if (glstate->raster.bm_drawing)
        bitmap_flush();

    // special case for (very) large GL_QUADS array
    if ((mode==GL_QUADS) && (count>4*8000)) {
        // split the array in manageable slice
        int cnt = 4*8000;
        for (int i=0; i<count; i+=4*8000) {
            if (i+cnt>count) cnt = count-i;
            gl4es_glDrawArrays(mode, i, cnt);
        }
        return;
    }
	noerrorShim();
	LOAD_GLES_FPE(glNormalPointer);
	LOAD_GLES_FPE(glVertexPointer);
	LOAD_GLES_FPE(glColorPointer);
	LOAD_GLES_FPE(glTexCoordPointer);
    LOAD_GLES_FPE(glEnable);
    LOAD_GLES_FPE(glDisable);
    LOAD_GLES_FPE(glEnableClientState);
    LOAD_GLES_FPE(glDisableClientState);
    LOAD_GLES_FPE(glMultiTexCoord4f);

    if (glstate->list.active) {
        NewStage(glstate->list.active, STAGE_DRAW);
        glstate->list.active = arrays_to_renderlist(glstate->list.active, mode, first, count+first);
        glstate->list.active = extend_renderlist(glstate->list.active);
        return;
    }

    /*if (glstate->polygon_mode == GL_LINE && mode>=GL_TRIANGLES)
		mode = GL_LINE_LOOP;*/
    if (glstate->polygon_mode == GL_POINT && mode>=GL_TRIANGLES)
		mode = GL_POINTS;

    if (should_intercept_render(mode)) {
        renderlist_t *list;
        list = arrays_to_renderlist(NULL, mode, first, count+first);
        list = end_renderlist(list);
        draw_renderlist(list);
        free_renderlist(list);
    } else {
        if (mode==GL_QUADS) {
            // TODO: move those static in glstate
            static GLushort *indices = NULL;
            static int indcnt = 0;
            static int indfirst = 0;
            int realfirst = ((first%4)==0)?0:first;
            int realcount = count + (first-realfirst);
            if((indcnt < realcount) || (indfirst!=realfirst)) {
                if(indcnt < realcount) {
                    indcnt = realcount;
                    if (indices) free(indices);
                    indices = (GLushort*)malloc(sizeof(GLushort)*(indcnt*3/2));
                }
                indfirst = realfirst;
                GLushort *p = indices;
                for (int i=0, j=indfirst; i+3<indcnt; i+=4, j+=4) {
                        *(p++) = j + 0;
                        *(p++) = j + 1;
                        *(p++) = j + 2;

                        *(p++) = j + 0;
                        *(p++) = j + 2;
                        *(p++) = j + 3;
                }
            }
            // take care of vao elements, just in case
            glbuffer_t *old_vao_elements = glstate->vao->elements;
            glstate->vao->elements = NULL;
            gl4es_glDrawElements(GL_TRIANGLES, count*3/2, GL_UNSIGNED_SHORT, indices+(first-indfirst)*3/2);
            glstate->vao->elements = old_vao_elements;
            return;
        }

        LOAD_GLES_FPE(glDrawArrays);

		GLenum mode_init = mode;
		if (mode == GL_QUAD_STRIP)
			mode = GL_TRIANGLE_STRIP;
		if (mode == GL_POLYGON)
			mode = GL_TRIANGLE_FAN;
			
		if (glstate->render_mode == GL_SELECT) {
			select_glDrawArrays(&glstate->vao->pointers.vertex, mode, first, count);
		} else {
            realize_textures();
            
            GLuint old_tex = glstate->texture.client;

            // setup the Array Pointers
            client_state(color_array, GL_COLOR_ARRAY, );    
            if (glstate->vao->color_array)
                gles_glColorPointer(glstate->vao->pointers.color.size, glstate->vao->pointers.color.type, glstate->vao->pointers.color.stride, glstate->vao->pointers.color.pointer);
            if(hardext.esversion>1) {
                client_state(secondary_array, GL_SECONDARY_COLOR_ARRAY, );
                if (glstate->vao->secondary_array)
                    fpe_glSecondaryColorPointer(glstate->vao->pointers.secondary.size, glstate->vao->pointers.secondary.type, glstate->vao->pointers.secondary.stride, glstate->vao->pointers.secondary.pointer);
            }
            client_state(normal_array, GL_NORMAL_ARRAY, );
            if (glstate->vao->normal_array)
                gles_glNormalPointer(glstate->vao->pointers.normal.type, glstate->vao->pointers.normal.stride, glstate->vao->pointers.normal.pointer);
            client_state(vertex_array, GL_VERTEX_ARRAY, );
            if (glstate->vao->vertex_array)
                gles_glVertexPointer(glstate->vao->pointers.vertex.size, glstate->vao->pointers.vertex.type, glstate->vao->pointers.vertex.stride, glstate->vao->pointers.vertex.pointer);
            #define TEXTURE(A) gl4es_glClientActiveTexture(A+GL_TEXTURE0);
            for (int aa=0; aa<hardext.maxtex; aa++) {
                client_state(tex_coord_array[aa], GL_TEXTURE_COORD_ARRAY, TEXTURE(aa););
                // get 1st enabled target
                const GLint itarget = get_target(glstate->enable.texture[aa]);
                if(itarget>=0) {
                    if (!IS_TEX2D(glstate->enable.texture[aa]) && (IS_ANYTEX(glstate->enable.texture[aa]))) {
                        TEXTURE(aa);
                        gles_glEnable(GL_TEXTURE_2D);
                    }
                    if (glstate->vao->tex_coord_array[aa]) {
                        TEXTURE(aa);
                        tex_setup_texcoord(count+first, itarget);
                    } else
                        gles_glMultiTexCoord4f(GL_TEXTURE0+aa, glstate->texcoord[aa][0], glstate->texcoord[aa][1], glstate->texcoord[aa][2], glstate->texcoord[aa][3]);
                }  else if (glstate->clientstate.tex_coord_array[aa] && hardext.esversion!=1) {
                    // special case on GL2, Tex disable but CoordArray enabled...
                    TEXTURE(aa);
                    tex_setup_texcoord(count+first, ENABLED_TEX2D);
                }
            }
            if (glstate->texture.client!=old_tex)
                TEXTURE(old_tex);

			gles_glDrawArrays(mode, first, count);
			
            for (int aa=0; aa<hardext.maxtex; aa++) {
                const GLint itarget = get_target(glstate->enable.texture[aa]);
                if (!IS_TEX2D(glstate->enable.texture[aa]) && (IS_ANYTEX(glstate->enable.texture[aa]))) {
                    TEXTURE(aa);
                    gles_glDisable(GL_TEXTURE_2D);
                }
            }
            if (glstate->texture.client!=old_tex)
                TEXTURE(old_tex);
            #undef TEXTURE
		}
    }
}
void glDrawArrays(GLenum mode, GLint first, GLsizei count) AliasExport("gl4es_glDrawArrays");

//#define ACTIVE_MULTIDRAW
void gl4es_glMultiDrawArrays(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount)
{
    #ifdef ACTIVE_MULTIDRAW
    LOAD_GLES_EXT(glMultiDrawArrays);
    if(glstate->list.pending) flush();
    if((!gles_glMultiDrawArrays) || should_intercept_render(mode) || (mode==GL_QUADS) || (glstate->list.active && (glstate->list.compiling || glstate->gl_batch)) 
        || (glstate->render_mode == GL_SELECT) || ((glstate->polygon_mode == GL_LINE) || (glstate->polygon_mode == GL_POINT)) )
    #endif
    {
        // GL_QUADS special case can probably by improved
        // divide the call
        // TODO optimize with forcing Batch mode
        for (int i=0; i<primcount; i++)
            gl4es_glDrawArrays(mode, first[i], count[i]);
    }
    #ifdef ACTIVE_MULTIDRAW
    else
    {
        if(mode==GL_QUAD_STRIP) mode=GL_TRIANGLE_STRIP;
        else if(mode==GL_POLYGON) mode=GL_TRIANGLE_FAN;

        if (glstate->raster.bm_drawing)
            bitmap_flush();

        LOAD_GLES_FPE(glNormalPointer);
        LOAD_GLES_FPE(glVertexPointer);
        LOAD_GLES_FPE(glColorPointer);
        LOAD_GLES_FPE(glTexCoordPointer);
        LOAD_GLES_FPE(glEnable);
        LOAD_GLES_FPE(glDisable);
        LOAD_GLES_FPE(glEnableClientState);
        LOAD_GLES_FPE(glDisableClientState);
        LOAD_GLES_FPE(glMultiTexCoord4f);

        GLuint old_tex = glstate->texture.client;

        realize_textures();
        
        // setup the Array Pointers
        client_state(color_array, GL_COLOR_ARRAY, );    
        if (glstate->vao->color_array)
            gles_glColorPointer(glstate->vao->pointers.color.size, glstate->vao->pointers.color.type, glstate->vao->pointers.color.stride, glstate->vao->pointers.color.pointer);
        client_state(normal_array, GL_NORMAL_ARRAY, );
        if (glstate->vao->normal_array)
            gles_glNormalPointer(glstate->vao->pointers.normal.type, glstate->vao->pointers.normal.stride, glstate->vao->pointers.normal.pointer);
        client_state(vertex_array, GL_VERTEX_ARRAY, );
        if (glstate->vao->vertex_array)
            gles_glVertexPointer(glstate->vao->pointers.vertex.size, glstate->vao->pointers.vertex.type, glstate->vao->pointers.vertex.stride, glstate->vao->pointers.vertex.pointer);
        #define TEXTURE(A) gl4es_glClientActiveTexture(A+GL_TEXTURE0);
        for (int aa=0; aa<hardext.maxtex; aa++) {
            client_state(tex_coord_array[aa], GL_TEXTURE_COORD_ARRAY, TEXTURE(aa););
            // get 1st enabled target
            const GLint itarget = get_target(glstate->enable.texture[aa]);
            if(itarget>=0) {
                if (itarget==ENABLED_TEX1D || itarget==ENABLED_TEX3D || itarget==ENABLED_TEXTURE_RECTANGLE) {
                    TEXTURE(aa);
                    gles_glEnable(GL_TEXTURE_2D);
                }
                if (glstate->vao->tex_coord_array[aa]) {
                    TEXTURE(aa);
                    tex_setup_texcoord(count+first, itarget);
                } else
                    gles_glMultiTexCoord4f(GL_TEXTURE0+aa, glstate->texcoord[aa][0], glstate->texcoord[aa][1], glstate->texcoord[aa][2], glstate->texcoord[aa][3]);
            }  else if (glstate->clientstate.tex_coord_array[aa]) {
                // special case, Tex disable but CoordArray enabled... disabling it temporarly
                TEXTURE(aa);
                glstate->clientstate.tex_coord_array[aa] = 0;
                gles_glDisableClientState(GL_TEXTURE_COORD_ARRAY);
            }
        }
        if (glstate->texture.client!=old_tex)
            TEXTURE(old_tex);
        
        if(hardext.esversion!=1) realize_glenv();
        gles_glMultiDrawArrays(mode, first, count, primcount);

        for (int aa=0; aa<hardext.maxtex; aa++) {
            const GLint itarget = get_target(glstate->enable.texture[aa]);
            if (itarget==ENABLED_TEX1D || itarget==ENABLED_TEX3D || itarget==ENABLED_TEXTURE_RECTANGLE) {
                TEXTURE(aa);
                gles_glDisable(GL_TEXTURE_2D);
            }
        }
        if (glstate->texture.client!=old_tex)
            TEXTURE(old_tex);
        #undef TEXTURE

        errorGL();
    }
    #endif
}
void glMultiDrawArrays(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount) AliasExport("gl4es_glMultiDrawArrays");

void gl4es_glMultiDrawElements( GLenum mode, GLsizei *count, GLenum type, const void * const *indices, GLsizei primcount)
{
    #ifdef ACTIVE_MULTIDRAW
    LOAD_GLES_EXT(glMultiDrawElements);
    if(glstate->list.pending) flush();
    if((!gles_glMultiDrawElements) || should_intercept_render(mode) || (mode==GL_QUADS) || (glstate->list.active && (glstate->list.compiling || glstate->gl_batch)) 
        || (glstate->render_mode == GL_SELECT) || ((glstate->polygon_mode == GL_LINE) || (glstate->polygon_mode == GL_POINT)) || (type != GL_UNSIGNED_SHORT) )
    #endif
    {
        // divide the call
        // TODO optimize with forcing Batch mode
        for (int i=0; i<primcount; i++)
            gl4es_glDrawElements(mode, count[i], type, indices[i]);
    }
    #ifdef ACTIVE_MULTIDRAW
    else
    {
        if(mode==GL_QUAD_STRIP) mode=GL_TRIANGLE_STRIP;
        else if(mode==GL_POLYGON) mode=GL_TRIANGLE_FAN;

        if (glstate->raster.bm_drawing)
            bitmap_flush();

        LOAD_GLES_FPE(glNormalPointer);
        LOAD_GLES_FPE(glVertexPointer);
        LOAD_GLES_FPE(glColorPointer);
        LOAD_GLES_FPE(glTexCoordPointer);
        LOAD_GLES_FPE(glEnable);
        LOAD_GLES_FPE(glDisable);
        LOAD_GLES_FPE(glEnableClientState);
        LOAD_GLES_FPE(glDisableClientState);
        LOAD_GLES_FPE(glMultiTexCoord4f);

        GLuint old_tex = glstate->texture.client;

        realize_textures();
        
        // setup the Array Pointers
        client_state(color_array, GL_COLOR_ARRAY, );    
        if (glstate->vao->color_array)
            gles_glColorPointer(glstate->vao->pointers.color.size, glstate->vao->pointers.color.type, glstate->vao->pointers.color.stride, glstate->vao->pointers.color.pointer);
        client_state(normal_array, GL_NORMAL_ARRAY, );
        if (glstate->vao->normal_array)
            gles_glNormalPointer(glstate->vao->pointers.normal.type, glstate->vao->pointers.normal.stride, glstate->vao->pointers.normal.pointer);
        client_state(vertex_array, GL_VERTEX_ARRAY, );
        if (glstate->vao->vertex_array)
            gles_glVertexPointer(glstate->vao->pointers.vertex.size, glstate->vao->pointers.vertex.type, glstate->vao->pointers.vertex.stride, glstate->vao->pointers.vertex.pointer);
        #define TEXTURE(A) gl4es_glClientActiveTexture(A+GL_TEXTURE0);
        for (int aa=0; aa<hardext.maxtex; aa++) {
            client_state(tex_coord_array[aa], GL_TEXTURE_COORD_ARRAY, TEXTURE(aa););
            // get 1st enabled target
            const GLint itarget = get_target(glstate->enable.texture[aa]);
            if(itarget>=0) {
                if (itarget==ENABLED_TEX1D || itarget==ENABLED_TEX3D || itarget==ENABLED_TEXTURE_RECTANGLE) {
                    TEXTURE(aa);
                    gles_glEnable(GL_TEXTURE_2D);
                }
                if (glstate->vao->tex_coord_array[aa]) {
                    TEXTURE(aa);
                    tex_setup_texcoord(count+first, itarget);
                } else
                    gles_glMultiTexCoord4f(GL_TEXTURE0+aa, glstate->texcoord[aa][0], glstate->texcoord[aa][1], glstate->texcoord[aa][2], glstate->texcoord[aa][3]);
            }  else if (glstate->clientstate.tex_coord_array[aa]) {
                // special case, Tex disable but CoordArray enabled... disabling it temporarly
                TEXTURE(aa);
                glstate->clientstate.tex_coord_array[aa] = 0;
                gles_glDisableClientState(GL_TEXTURE_COORD_ARRAY);
            }
        }
        if (glstate->texture.client!=old_tex)
            TEXTURE(old_tex);
        
        if(hardext.esversion!=1) realize_glenv();
        gles_glMultiDrawElements(mode, count, type, indices, primcount);

        for (int aa=0; aa<hardext.maxtex; aa++) {
            const GLint itarget = get_target(glstate->enable.texture[aa]);
            if (itarget==ENABLED_TEX1D || itarget==ENABLED_TEX3D || itarget==ENABLED_TEXTURE_RECTANGLE) {
                TEXTURE(aa);
                gles_glDisable(GL_TEXTURE_2D);
            }
        }
        if (glstate->texture.client!=old_tex)
            TEXTURE(old_tex);
        #undef TEXTURE

        errorGL();
    }
    #endif
}
void glMultiDrawElements( GLenum mode, GLsizei *count, GLenum type, const void * const *indices, GLsizei primcount) AliasExport("gl4es_glMultiDrawElements");

#undef client_state
#define clone_gl_pointer(t, s)\
    t.size = s; t.type = type; t.stride = stride; t.pointer = pointer + (uintptr_t)((glstate->vao->vertex)?glstate->vao->vertex->data:0)
void gl4es_glVertexPointer(GLint size, GLenum type,
                     GLsizei stride, const GLvoid *pointer) {
    if(size<1 || size>4) {
        errorShim(GL_INVALID_VALUE);
		return;
    }
    noerrorShim();
    clone_gl_pointer(glstate->vao->pointers.vertex, size);
}
void gl4es_glColorPointer(GLint size, GLenum type,
                     GLsizei stride, const GLvoid *pointer) {
	if (!((size>0 && size<=4) || (size==GL_BGRA && type==GL_UNSIGNED_BYTE))) {
        errorShim(GL_INVALID_VALUE);
		return;
    }
    noerrorShim();
    clone_gl_pointer(glstate->vao->pointers.color, size);
}
void gl4es_glNormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer) {
    noerrorShim();
    clone_gl_pointer(glstate->vao->pointers.normal, 3);
}
void gl4es_glTexCoordPointer(GLint size, GLenum type,
                     GLsizei stride, const GLvoid *pointer) {
    if(size<1 || size>4) {
        errorShim(GL_INVALID_VALUE);
		return;
    }
    noerrorShim();
    clone_gl_pointer(glstate->vao->pointers.tex_coord[glstate->texture.client], size);
}
void gl4es_glSecondaryColorPointer(GLint size, GLenum type, 
					GLsizei stride, const GLvoid *pointer) {
	if (!(size==3 || (size==GL_BGRA && type==GL_UNSIGNED_BYTE))) {
        errorShim(GL_INVALID_VALUE);
		return;		// Size must be 3...
    }
    clone_gl_pointer(glstate->vao->pointers.secondary, size);
    noerrorShim();
}
void gl4es_glFogCoordPointer(GLenum type, GLsizei stride, const GLvoid *pointer) {
    clone_gl_pointer(glstate->vao->pointers.fog, 1);
    noerrorShim();
}

#undef clone_gl_pointer

void glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) AliasExport("gl4es_glVertexPointer");
void glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) AliasExport("gl4es_glColorPointer");
void glNormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer) AliasExport("gl4es_glNormalPointer");
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) AliasExport("gl4es_glTexCoordPointer");
void glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) AliasExport("gl4es_glSecondaryColorPointer");
void glFogCoordPointer(GLenum type, GLsizei stride, const GLvoid *pointer) AliasExport("gl4es_glFogCoordPointer");

void gl4es_glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid *pointer) {
    uintptr_t ptr = (uintptr_t)pointer;
    // element lengths
    GLsizei tex=0, color=0, normal=0, vert=0;
    // element formats
    GLenum tf, cf, nf, vf;
    tf = cf = nf = vf = GL_FLOAT;
    noerrorShim();
    switch (format) {
        case GL_V2F: vert = 2; break;
        case GL_V3F: vert = 3; break;
        case GL_C4UB_V2F:
            color = 4; cf = GL_UNSIGNED_BYTE;
            vert = 2;
            break;
        case GL_C4UB_V3F:
            color = 4; cf = GL_UNSIGNED_BYTE;
            vert = 3;
            break;
        case GL_C3F_V3F:
            color = 3;
            vert = 4;
            break;
        case GL_N3F_V3F:
            normal = 3;
            vert = 3;
            break;
        case GL_C4F_N3F_V3F:
            color = 4;
            normal = 3;
            vert = 3;
            break;
        case GL_T2F_V3F:
            tex = 2;
            vert = 3;
            break;
        case GL_T4F_V4F:
            tex = 4;
            vert = 4;
            break;
        case GL_T2F_C4UB_V3F:
            tex = 2;
            color = 4; cf = GL_UNSIGNED_BYTE;
            vert = 3;
            break;
        case GL_T2F_C3F_V3F:
            tex = 2;
            color = 3;
            vert = 3;
            break;
        case GL_T2F_N3F_V3F:
            tex = 2;
            normal = 3;
            vert = 3;
            break;
        case GL_T2F_C4F_N3F_V3F:
            tex = 2;
            color = 4;
            normal = 3;
            vert = 3;
            break;
        case GL_T4F_C4F_N3F_V4F:
            tex = 4;
            color = 4;
            normal = 3;
            vert = 4;
            break;
        default:
            errorShim(GL_INVALID_ENUM);
            return;
    }
    if (!stride)
        stride = tex * gl_sizeof(tf) +
                 color * gl_sizeof(cf) +
                 normal * gl_sizeof(nf) +
                 vert * gl_sizeof(vf);
    if (tex) {
		gl4es_glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        gl4es_glTexCoordPointer(tex, tf, stride, (GLvoid *)ptr);
        ptr += tex * gl_sizeof(tf);
    }
    if (color) {
		gl4es_glEnableClientState(GL_COLOR_ARRAY);
        gl4es_glColorPointer(color, cf, stride, (GLvoid *)ptr);
        ptr += color * gl_sizeof(cf);
    }
    if (normal) {
		gl4es_glEnableClientState(GL_NORMAL_ARRAY);
        gl4es_glNormalPointer(nf, stride, (GLvoid *)ptr);
        ptr += normal * gl_sizeof(nf);
    }
    if (vert) {
		gl4es_glEnableClientState(GL_VERTEX_ARRAY);
        gl4es_glVertexPointer(vert, vf, stride, (GLvoid *)ptr);
    }
}
void glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid *pointer) AliasExport("gl4es_glInterleavedArrays");

// immediate mode functions
void gl4es_glBegin(GLenum mode) {
    glstate->list.begin = 1;
    glstate->list.pending = 0;
    if (!glstate->list.active)
        glstate->list.active = alloc_renderlist();
    // small optim... continue a render command if possible
    NewDrawStage(glstate->list.active, mode);
    glstate->list.active->mode = mode;
    glstate->list.active->mode_init = mode;
    noerrorShim();	// TODO, check Enum validity
}
void glBegin(GLenum mode) AliasExport("gl4es_glBegin");

void gl4es_glEnd() {
    if (!glstate->list.active) return;
    glstate->list.begin = 0;
    // check if TEXTUREx is activate and no TexCoord (or texgen), in that case, create a dummy one base on glstate->..
    for (int a=0; a<hardext.maxtex; a++)
		if ((hardext.esversion==1) && glstate->enable.texture[a] && ((glstate->list.active->tex[a]==0) && !(glstate->enable.texgen_s[a] || glstate->texture.pscoordreplace[a])))
			rlMultiTexCoord4f(glstate->list.active, GL_TEXTURE0+a, glstate->texcoord[a][0], glstate->texcoord[a][1], glstate->texcoord[a][2], glstate->texcoord[a][3]);
    // end immediateMV if needed
    if(glstate->immediateMV)
        gl4es_immediateMVEnd(glstate->list.active);
    // render if we're not in a display list
    int withColor = 0;
    if(glstate->list.compiling || glstate->gl_batch) {
        glstate->list.active = extend_renderlist(glstate->list.active);
    } else {
        if (!globals4es.beginend /*|| (glstate->polygon_mode==GL_LINE)*/) {
            renderlist_t *mylist = glstate->list.active;
            withColor = (mylist->color!=NULL);
            glstate->list.active = NULL;
            mylist = end_renderlist(mylist);
            draw_renderlist(mylist);
            free_renderlist(mylist);
        } else {
            withColor = (glstate->list.active->color!=NULL);
            glstate->list.pending = 1;
            NewStage(glstate->list.active, STAGE_POSTDRAW);
        }
    }
    if(withColor)
        gl4es_glColor4f(glstate->color[0], glstate->color[1], glstate->color[2], glstate->color[3]);
    noerrorShim();
}
void glEnd() AliasExport("gl4es_glEnd");

void gl4es_glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {
    if (glstate->list.active) {
        if (glstate->list.active->stage != STAGE_DRAW) {
            if ((glstate->list.compiling || glstate->gl_batch) && glstate->list.active) {
                glstate->list.active->lastNormal[0] = nx; glstate->list.active->lastNormal[1] = ny; glstate->list.active->lastNormal[2] = nz;
            } else if (glstate->list.pending && glstate->list.active->stage==STAGE_POSTDRAW) {
                glstate->list.active->post_normals[0] = nx; glstate->list.active->post_normals[1] = ny;
                glstate->list.active->post_normals[2] = nz;
                glstate->list.active->post_normal = 1;
                return;                
            }

            PUSH_IF_COMPILING(glNormal3f);
        } else {
            rlNormal3f(glstate->list.active, nx, ny, nz);
            glstate->list.active->lastNormal[0] = nx; glstate->list.active->lastNormal[1] = ny; glstate->list.active->lastNormal[2] = nz;
            noerrorShim();
        }
    }
    else {
        LOAD_GLES_FPE(glNormal3f);
        errorGL();
        gles_glNormal3f(nx, ny, nz);
    }
    glstate->normal[0] = nx; glstate->normal[1] = ny; glstate->normal[2] = nz;
}
void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) AliasExport("gl4es_glNormal3f");

void gl4es_glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    if (glstate->list.active) {
        rlVertex4f(glstate->list.active, x, y, z, w);
        noerrorShim();
    } else {
        glstate->vertex[0]=x; glstate->vertex[1]=y; glstate->vertex[2]=z; glstate->vertex[3]=w;
    }
}
void glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) AliasExport("gl4es_glVertex4f");

void gl4es_glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    if (glstate->list.active) {
        if (glstate->list.active->stage != STAGE_DRAW) {
            if (glstate->list.compiling || glstate->gl_batch || glstate->list.active->stage<STAGE_DRAW) {
                glstate->list.active->lastColors[0] = red; glstate->list.active->lastColors[1] = green;
                glstate->list.active->lastColors[2] = blue; glstate->list.active->lastColors[3] = alpha;
                glstate->list.active->lastColorsSet = 1;
            }
            else if (glstate->list.pending && glstate->list.active->stage==STAGE_POSTDRAW) {
                glstate->list.active->post_colors[0] = red; glstate->list.active->post_colors[1] = green;
                glstate->list.active->post_colors[2] = blue; glstate->list.active->post_colors[3] = alpha;
                glstate->list.active->post_color = 1;
                return;
            }
            PUSH_IF_COMPILING(glColor4f);
        } else {
            rlColor4f(glstate->list.active, red, green, blue, alpha);
            noerrorShim();
        }
    } else {
        LOAD_GLES_FPE(glColor4f);
        errorGL();
        gles_glColor4f(red, green, blue, alpha);
    }
    // change the state last thing
    glstate->color[0] = red; glstate->color[1] = green;
    glstate->color[2] = blue; glstate->color[3] = alpha;
}
void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) AliasExport("gl4es_glColor4f");

void gl4es_glSecondaryColor3f(GLfloat r, GLfloat g, GLfloat b) {
    if (glstate->list.active) {
        if(glstate->list.pending)
            flush();
        else
        {
            rlSecondary3f(glstate->list.active, r, g, b);
            glstate->list.active->lastSecondaryColors[0] = r; glstate->list.active->lastSecondaryColors[1] = g;
            glstate->list.active->lastSecondaryColors[2] = b;
        }
        noerrorShim();
    } else {
        noerrorShim();
    }
    // change the state last thing
    glstate->secondary[0] = r; glstate->secondary[1] = g;
    glstate->secondary[2] = b;
}
void glSecondaryColor3f(GLfloat r, GLfloat g, GLfloat b) AliasExport("gl4es_glSecondaryColor3f");


void gl4es_glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    if (glstate->list.active) {
        if(glstate->list.pending)
            flush();
        else {
            // test if called between glBegin / glEnd but Texture is not active. In that case, ignore the call
            if(hardext.esversion==1 || (glstate->list.begin && (glstate->list.compiling || glstate->enable.texture[0])))
                rlMultiTexCoord4f(glstate->list.active, GL_TEXTURE0, s, t, r, q);
        }
    }
    noerrorShim();
    glstate->texcoord[0][0] = s; glstate->texcoord[0][1] = t;
    glstate->texcoord[0][2] = r; glstate->texcoord[0][3] = q;
}
void glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q) AliasExport("gl4es_glTexCoord4f");

void gl4es_glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
	// TODO, error if target is unsuported texture....
    if (glstate->list.active) {
        if(glstate->list.pending)
            flush();
        else {
            // test if called between glBegin / glEnd but Texture is not active. In that case, ignore the call
            if(hardext.esversion==1 || (glstate->list.begin && (glstate->list.compiling || glstate->enable.texture[target-GL_TEXTURE0])))
                rlMultiTexCoord4f(glstate->list.active, target, s, t, r, q);
        }
    }
    noerrorShim();
    glstate->texcoord[target-GL_TEXTURE0][0] = s; glstate->texcoord[target-GL_TEXTURE0][1] = t;
    glstate->texcoord[target-GL_TEXTURE0][2] = r; glstate->texcoord[target-GL_TEXTURE0][3] = q;
}
void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) AliasExport("gl4es_glMultiTexCoord4f");
void glMultiTexCoord4fARB(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) AliasExport("gl4es_glMultiTexCoord4f");

void gl4es_glArrayElement(GLint i) {
    GLfloat *v;
    pointer_state_t *p;
    p = &glstate->vao->pointers.color;
    if (glstate->vao->color_array) {
        v = gl_pointer_index(p, i);
        GLfloat scale = 1.0f/gl_max_value(p->type);
        // color[3] defaults to 1.0f
        if (p->size < 4)
            v[3] = 1.0f;

        // scale color coordinates to a 0 - 1.0 range
        for (int i = 0; i < p->size; i++) {
            v[i] *= scale;
        }
        gl4es_glColor4fv(v);
    }
    p = &glstate->vao->pointers.secondary;
    if (glstate->vao->secondary_array) {
        v = gl_pointer_index(p, i);
        GLfloat scale = 1.0f/gl_max_value(p->type);

        // scale color coordinates to a 0 - 1.0 range
        for (int i = 0; i < p->size; i++) {
            v[i] *= scale;
        }
        gl4es_glSecondaryColor3fv(v);
    }
    p = &glstate->vao->pointers.normal;
    if (glstate->vao->normal_array) {
        v = gl_pointer_index(p, i);
        gl4es_glNormal3fv(v);
    }
    p = &glstate->vao->pointers.tex_coord[0];
    if (glstate->vao->tex_coord_array[0]) {
        v = gl_pointer_index(p, i);
        if (p->size<4)
            gl4es_glTexCoord2fv(v);
        else
            gl4es_glTexCoord4fv(v);
    }
    int a;
    for (a=1; a<MAX_TEX; a++) {
	    p = &glstate->vao->pointers.tex_coord[a];
	    if (glstate->vao->tex_coord_array[a]) {
			v = gl_pointer_index(p, i);
            if (p->size<4)
                gl4es_glMultiTexCoord2fv(GL_TEXTURE0+a, v);
            else
                gl4es_glMultiTexCoord4fv(GL_TEXTURE0+a, v);
	    }
    }
    p = &glstate->vao->pointers.vertex;
    if (glstate->vao->vertex_array) {
        v = gl_pointer_index(p, i);
        if (p->size == 4) {
            gl4es_glVertex4fv(v);
        } else if (p->size == 3) {
            gl4es_glVertex3fv(v);
        } else {
            gl4es_glVertex2fv(v);
        }
    }
}
void glArrayElement(GLint i) AliasExport("gl4es_glArrayElement");

// TODO: between a lock and unlock, I can assume the array pointers are unchanged
// so I can build a renderlist_t on the first call and hold onto it
// maybe I need a way to call a renderlist_t with (first, count)
void gl4es_glLockArrays(GLint first, GLsizei count) {
    glstate->list.locked = true;
    noerrorShim();
}
void glLockArraysEXT(GLint first, GLsizei count) AliasExport("gl4es_glLockArrays");
void gl4es_glUnlockArrays() {
    glstate->list.locked = false;
    noerrorShim();
}
void glUnlockArraysEXT() AliasExport("gl4es_glUnlockArrays");
// display lists

static renderlist_t *gl4es_glGetList(GLuint list) {
    khint_t k;
    int ret;
    khash_t(gllisthead) *lists = glstate->headlists;
    k = kh_get(gllisthead, lists, list);
    if (k != kh_end(lists))
        return kh_value(lists, k);
    return NULL;
}

GLuint gl4es_glGenLists(GLsizei range) {
	if (range<0) {
		errorShim(GL_INVALID_VALUE);
		return 0;
	}
	noerrorShim();
   	khint_t k;
   	int ret;
	khash_t(gllisthead) *lists = glstate->headlists;
    int start = glstate->list.count;
    glstate->list.count += range;

    for (int i = 0; i < range; i++) {
        k = kh_get(gllisthead, lists, start+i);
        if (k == kh_end(lists)){
            k = kh_put(gllisthead, lists, start+i, &ret);
            kh_value(lists, k) = NULL;  // create an empty gllist
        }
    }
    return start + 1;
}
GLuint glGenLists(GLsizei range) AliasExport("gl4es_glGenLists");


void gl4es_glNewList(GLuint list, GLenum mode) {
	errorShim(GL_INVALID_VALUE);
	if (list==0)
		return;
    {
        khint_t k;
        int ret;
        khash_t(gllisthead) *lists = glstate->headlists;
        k = kh_get(gllisthead, lists, list);
        if (k == kh_end(lists)){
            k = kh_put(gllisthead, lists, list, &ret);
            kh_value(lists, k) = NULL;
        }
    }
    noerrorShim();
    if (glstate->gl_batch) {
        glstate->gl_batch = 0;
        flush();
    }
    glstate->list.name = list;
    glstate->list.mode = mode;
    // TODO: if glstate->list.active is already defined, we probably need to clean up here
    glstate->list.active = alloc_renderlist();
    glstate->list.compiling = true;
}
void glNewList(GLuint list, GLenum mode) AliasExport("gl4es_glNewList");

void gl4es_glEndList() {
	noerrorShim();
    GLuint list = glstate->list.name;
    khash_t(gllisthead) *lists = glstate->headlists;
    khint_t k;
    {
        int ret;
        k = kh_get(gllisthead, lists, list);
        if (k == kh_end(lists)){
            k = kh_put(gllisthead, lists, list, &ret);
            kh_value(lists, k) = NULL;
        }
    }
    if (glstate->list.compiling) {
	// Free the previous list if it exist...
        free_renderlist(kh_value(lists, k));
        kh_value(lists, k) = GetFirst(glstate->list.active);
        glstate->list.compiling = false;
        end_renderlist(glstate->list.active);
        glstate->list.active = NULL;
        if (globals4es.batch==1) {
            init_batch();
        } 
        if (glstate->list.mode == GL_COMPILE_AND_EXECUTE) {
            glCallList(list);
        }
    }
}
void glEndList() AliasExport("gl4es_glEndList");

renderlist_t* append_calllist(renderlist_t *list, renderlist_t *a);
void gl4es_glCallList(GLuint list) {
	noerrorShim();
    if (glstate->list.active) {
        glstate->list.active = append_calllist(glstate->list.active, gl4es_glGetList(list));
		return;
	}
    // TODO: the output of this call can be compiled into another display list
    renderlist_t *l = gl4es_glGetList(list);
    if (l)
        draw_renderlist(l);
}
void glCallList(GLuint list) AliasExport("gl4es_glCallList");

void glPushCall(void *call) {
    if (glstate->list.active) {
		NewStage(glstate->list.active, STAGE_GLCALL);
        rlPushCall(glstate->list.active, call);
    }
}

void gl4es_glCallLists(GLsizei n, GLenum type, const GLvoid *lists) {
    #define call(name, type) \
        case name: glCallList(((type *)lists)[i] + glstate->list.base); break

    // seriously wtf
    #define call_bytes(name, stride)                             \
        case name:                                               \
            l = (GLubyte *)lists;                                \
            list = 0;                                            \
            for (j = 0; j < stride; j++) {                       \
                list += *(l + (i * stride + j)) << (stride - j); \
            }                                                    \
            gl4es_glCallList(list + glstate->list.base);                  \
            break

    unsigned int i, j;
    GLuint list;
    GLubyte *l;
    for (i = 0; i < n; i++) {
        switch (type) {
            call(GL_BYTE, GLbyte);
            call(GL_UNSIGNED_BYTE, GLubyte);
            call(GL_SHORT, GLshort);
            call(GL_UNSIGNED_SHORT, GLushort);
            call(GL_INT, GLint);
            call(GL_UNSIGNED_INT, GLuint);
            call(GL_FLOAT, GLfloat);
            call_bytes(GL_2_BYTES, 2);
            call_bytes(GL_3_BYTES, 3);
            call_bytes(GL_4_BYTES, 4);
        }
    }
    #undef call
    #undef call_bytes
}
void glCallLists(GLsizei n, GLenum type, const GLvoid *lists) AliasExport("gl4es_glCallLists");

void gl4es_glDeleteList(GLuint list) {
    if(glstate->gl_batch) {
        flush();
    }
    renderlist_t *gllist = NULL;
    {
        khint_t k;
        int ret;
        khash_t(gllisthead) *lists = glstate->headlists;
        k = kh_get(gllisthead, lists, list);
        renderlist_t *gllist = NULL;
        if (k != kh_end(lists)){
            gllist = kh_value(lists, k);
            free_renderlist(gllist);
            kh_del(gllisthead, lists, k);
        }
    }
}

void gl4es_glDeleteLists(GLuint list, GLsizei range) {
	noerrorShim();
    for (int i = 0; i < range; i++) {
        gl4es_glDeleteList(list+i);
    }
}
void glDeleteLists(GLuint list, GLsizei range) AliasExport("gl4es_glDeleteLists");

void gl4es_glListBase(GLuint base) {
	noerrorShim();
    glstate->list.base = base;
}
void glListBase(GLuint base) AliasExport("gl4es_glListBase");

GLboolean gl4es_glIsList(GLuint list) {
	noerrorShim();
    khint_t k;
    int ret;
    khash_t(gllisthead) *lists = glstate->headlists;
    k = kh_get(gllisthead, lists, list);
    if (k != kh_end(lists))
        return true;
    return false;
}
GLboolean glIsList(GLuint list) AliasExport("gl4es_glIsList");

void gl4es_glPolygonMode(GLenum face, GLenum mode) {
    ERROR_IN_BEGIN
	noerrorShim();
	if (face == GL_FRONT)
		face = GL_FRONT_AND_BACK;   //TODO, better handle all this
	if (face == GL_BACK)
		return;		//TODO, handle face enum for polygon mode != GL_FILL
    if (glstate->list.active)
        if (glstate->list.compiling || glstate->gl_batch) {
            NewStage(glstate->list.active, STAGE_POLYGON);
            glstate->list.active->polygon_mode = mode;
            return;
        }
        else flush();
	switch(mode) {
		case GL_LINE:
		case GL_POINT:
			glstate->polygon_mode = mode;
			break;
		case GL_FILL:
			glstate->polygon_mode = 0;
			break;
		default:
			glstate->polygon_mode = 0;
	}
}
void glPolygonMode(GLenum face, GLenum mode) AliasExport("gl4es_glPolygonMode");


void gl4es_glStencilMaskSeparate(GLenum face, GLuint mask) {
    LOAD_GLES2(glStencilMaskSeparate);
    errorGL();
    if(gles_glStencilMaskSeparate) {
        gles_glStencilMaskSeparate(face, mask);
    } else {
        // fake function..., call it only for front or front_and_back, just ignore back (crappy, I know)
        if ((face==GL_FRONT) || (face==GL_FRONT_AND_BACK))
            gl4es_glStencilMask(mask);
        else
            noerrorShim();
    }
}
void glStencilMaskSeparate(GLenum face, GLuint mask) AliasExport("gl4es_glStencilMaskSeparate");

void gl4es_glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) {
    LOAD_GLES2(glStencilFuncSeparate);
    errorGL();
    if(gles_glStencilFuncSeparate) {
        gles_glStencilFuncSeparate(face, func, ref, mask);
    } else {
        // fake function..., call it only for front or front_and_back, just ignore back (crappy, I know)
        if ((face==GL_FRONT) || (face==GL_FRONT_AND_BACK))
            gl4es_glStencilFunc(func, ref, mask);
        else
            noerrorShim();
    }
}
void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) AliasExport("gl4es_glStencilFuncSeparate");

void gl4es_glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) {
    LOAD_GLES2(glStencilOpSeparate);
    errorGL();
    if(gles_glStencilOpSeparate) {
        gles_glStencilOpSeparate(face, sfail, dpfail, dppass);
    } else {
        //fake, again
        if ((face==GL_FRONT) || (face==GL_FRONT_AND_BACK))
            gl4es_glStencilOp(sfail, dpfail, dppass);
        else
            noerrorShim();
    }
}
void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) AliasExport("gl4es_glStencilOpSeparate");


void init_statebatch() {
    memset(&glstate->statebatch, 0, sizeof(statebatch_t));
}

void flush() {
    // flush internal list
    renderlist_t *mylist = glstate->list.active;
    if (mylist) {
        GLuint old = glstate->gl_batch;
        glstate->list.active = NULL;
        glstate->list.pending = 0;
        glstate->gl_batch = 0;
        mylist = end_renderlist(mylist);
        draw_renderlist(mylist);
        free_renderlist(mylist);
        glstate->gl_batch = old;
    }
    if(glstate->immediateMV)
        gl4es_immediateMVEnd(glstate->list.active);
    init_statebatch();
    glstate->list.active = (glstate->gl_batch)?alloc_renderlist():NULL;
}

void init_batch() {
    glstate->list.active = alloc_renderlist();
    init_statebatch();
    glstate->gl_batch = 1;
    glstate->init_batch = 1;
}
#ifndef ANDROID
extern void BlitEmulatedPixmap();
#endif
void gl4es_glFlush() {
	LOAD_GLES(glFlush);
    
    if (glstate->gl_batch || glstate->list.pending) flush();
    PUSH_IF_COMPILING(glFlush);
    
    gles_glFlush();
    errorGL();

#ifndef ANDROID
    if(glstate->emulatedPixmap && !glstate->emulatedWin)
        BlitEmulatedPixmap();
#endif
}
void glFlush() AliasExport("gl4es_glFlush");

void gl4es_glFinish() {
	LOAD_GLES(glFinish);
    
    if (glstate->gl_batch || glstate->list.pending) flush();
    PUSH_IF_COMPILING(glFinish);
    
    gles_glFinish();
    errorGL();
}
void glFinish() AliasExport("gl4es_glFinish");

void gl4es_glIndexPointer(GLenum type, GLsizei stride, const GLvoid * pointer) {
    static bool warning = false;
    if(!warning) {
        LOGD("Warning, stubbed glIndexPointer\n");
        warning = true;
    }
}
void glIndexPointer(GLenum type, GLsizei stride, const GLvoid * pointer) AliasExport("gl4es_glIndexPointer");

void gl4es_glEdgeFlagPointer(GLsizei stride, const GLvoid * pointer) {
    static bool warning = false;
    if(!warning) {
        LOGD("Warning, stubbed glEdgeFlagPointer\n");
        warning = true;
    }
}
void glEdgeFlagPointer(GLsizei stride, const GLvoid * pointer) AliasExport("gl4es_glEdgeFlagPointer");



void gl4es_glShadeModel(GLenum mode) {
    if(mode!=GL_SMOOTH && mode!=GL_FLAT) {
        errorShim(GL_INVALID_ENUM);
        return;
    }
    PUSH_IF_COMPILING(glShadeModel);
    noerrorShim();
    if(mode==glstate->shademodel)
        return;
    glstate->shademodel = mode;
    LOAD_GLES2(glShadeModel);
    if(gles_glShadeModel) {
        errorGL();
        gles_glShadeModel(mode);
    }
}
void glShadeModel(GLenum mode) AliasExport("gl4es_glShadeModel");

void gl4es_glAlphaFunc(GLenum func, GLclampf ref) {
    PUSH_IF_COMPILING(glAlphaFunc);
    noerrorShim();
    if(ref<0.0f) ref = 0.0f;
    if(ref>1.0f) ref = 1.0f;
    if(glstate->alphafunc==func && glstate->alpharef==ref)
        return;
    if(func!=GL_NEVER && func!=GL_LESS && func!=GL_EQUAL
        && func!=GL_LEQUAL && func!=GL_GREATER && func!=GL_NOTEQUAL
        && func!=GL_ALWAYS && func!=GL_GEQUAL) {
            errorShim(GL_INVALID_ENUM);
            return;
    }
    glstate->alphafunc = func;
    glstate->alpharef = ref;
    LOAD_GLES_FPE(glAlphaFunc);
    if(gles_glAlphaFunc) {
        errorGL();
        gles_glAlphaFunc(func, ref);
    }
}
void glAlphaFunc(GLenum func, GLclampf ref) AliasExport("gl4es_glAlphaFunc");

void gl4es_glLogicOp(GLenum opcode) {
    PUSH_IF_COMPILING(glLogicOp);
    noerrorShim();
    if(glstate->logicop==opcode)
        return;
    // TODO: test if opcode is valid
    glstate->logicop = opcode;
    LOAD_GLES2(glLogicOp);
    if(gles_glLogicOp) {
        errorGL();
        gles_glLogicOp(opcode);
    }
}
void glLogicOp(GLenum opcode) AliasExport("gl4es_glLogicOp");

void gl4es_glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
    PUSH_IF_COMPILING(glColorMask);
    if(glstate->colormask[0]==red && glstate->colormask[1]==green && glstate->colormask[2]==blue && glstate->colormask[3]==alpha) {
        noerrorShim();
        return;
    }
    glstate->colormask[0]=red;
    glstate->colormask[1]=green;
    glstate->colormask[2]=blue;
    glstate->colormask[3]=alpha;
    LOAD_GLES(glColorMask);
    gles_glColorMask(red, green, blue, alpha);
}
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) AliasExport("gl4es_glColorMask");

void gl4es_scratch(int alloc) {
    if(glstate->scratch_alloc<alloc) {
        if(glstate->scratch)
            free(glstate->scratch);
        glstate->scratch = malloc(alloc);
        glstate->scratch_alloc = alloc;
    }
}
