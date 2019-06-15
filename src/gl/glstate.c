#include "glstate.h"

#include "../glx/hardext.h"
#include "fpe.h"
#include "framebuffers.h"
#include "gl4es.h"
#include "glstate.h"
#include "init.h"
#include "loader.h"

glstate_t *glstate = NULL;

glstate_t *default_glstate = NULL;

void init_matrix(glstate_t* glstate);

static void free_renderbuffer(glrenderbuffer_t *rend)
{
    LOAD_GLES2_OR_OES(glDeleteRenderbuffers);
    if(!rend)
        return;
    if(rend->secondarybuffer)
        gles_glDeleteRenderbuffers(1, &rend->secondarybuffer);
    if(rend->renderbuffer)
        gles_glDeleteRenderbuffers(1, &rend->renderbuffer);
    // the texture will be free by the free of the texture list, as it's referenced there...
    free(rend);
}

static void free_framebuffer(glframebuffer_t *fb)
{
    LOAD_GLES2_OR_OES(glDeleteFramebuffers);
    if(!fb)
        return;
    if(fb->id)
        gles_glDeleteFramebuffers(1, &fb->id);
    // the texture will be free by the free of the texture list, as it's referenced there...
    free(fb);
}

static void free_texture(gltexture_t *tex)
{
    LOAD_GLES(glDeleteTextures);
    if(!tex)
        return;
    if(tex->glname)
        gles_glDeleteTextures(1, &tex->glname);
    if(tex->data)
        free(tex->data);
    // renderbuffer linked to this texture will be freed by the free_renderbuffer function.
    free(tex);
}

void* NewGLState(void* shared_glstate, int es2only) {
    glstate_t *glstate = (glstate_t*)calloc(1, sizeof(glstate_t));
    if(shared_glstate) {
        glstate_t* copy_state = (glstate_t*)shared_glstate;
        if(!copy_state->shared_cnt) {
            copy_state->shared_cnt = (int*)malloc(sizeof(int));
            (*copy_state->shared_cnt) = 2;
        } else
            (*copy_state->shared_cnt)++;
        glstate->shared_cnt = copy_state->shared_cnt;
        glstate->headlists = copy_state->headlists;
        glstate->actual_tex2d = copy_state->actual_tex2d;
        glstate->texture.list = copy_state->texture.list;
        glstate->glsl = copy_state->glsl;
        glstate->gleshard = copy_state->gleshard;
        glstate->buffers = copy_state->buffers;
        glstate->queries = copy_state->queries;
        glstate->fpe_cache = copy_state->fpe_cache;
        glstate->fbo.renderbufferlist = copy_state->fbo.renderbufferlist;
        glstate->fbo.default_rb = copy_state->fbo.default_rb;
        glstate->fbo.framebufferlist = copy_state->fbo.framebufferlist;
        glstate->fbo.fbo_0 = copy_state->fbo.fbo_0;
        glstate->fbo.old = copy_state->fbo.old;

        glstate->defaultvbo = copy_state->defaultvbo;
    }
	GLfloat white[] = {1.0f, 1.0f, 1.0f, 1.0f};
	memcpy(glstate->color, white, sizeof(GLfloat)*4);
	glstate->last_error = GL_NO_ERROR;
    glstate->normal[2] = 1.0f; // default normal is 0/0/1
    glstate->matrix_mode = GL_MODELVIEW;
    
    // add default VBO
    if(!shared_glstate) // TODO: check if default VBO is shared?
    {
        khint_t k;
        int ret;
        khash_t(buff) *list = glstate->buffers = kh_init(buff);
        k = kh_put(buff, list, 0, &ret);
        glbuffer_t *buff = kh_value(list, k) = calloc(1, sizeof(glbuffer_t));
        /*buff->buffer = 0;
        buff->type = 0;
        buff->data = NULL;*/
        buff->usage = GL_STATIC_DRAW;
        //buff->size = 0;
        buff->access = GL_READ_WRITE;
        //buff->mapped = 0;
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
    if(!shared_glstate)
    {
        khint_t k;
        int ret;
        khash_t(gllisthead) *list = glstate->headlists = kh_init(gllisthead);
		k = kh_put(gllisthead, list, 1, &ret);
		kh_del(gllisthead, list, k);
    }
    // actual_tex2d
    if(!shared_glstate)
    {
        glstate->actual_tex2d = (GLuint*)calloc(MAX_TEX, sizeof(GLuint));
    }
    // glsl
    if(!shared_glstate)
    {
        glstate->glsl = (glsl_t*)malloc(sizeof(glsl_t));
        memset(glstate->glsl, 0, sizeof(glsl_t));
        glstate->gleshard = (gleshard_s_t*)calloc(1, sizeof(gleshard_s_t));
    }
    // Bind defaults...
    glstate->vao = glstate->defaultvao;

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
        glstate->fpe_state = (fpe_state_t*)calloc(1, sizeof(fpe_state_t));
        glstate->glsl->es2 = es2only;
        fpe_Init(glstate);
    }

    // init the matrix tracking
    init_matrix(glstate);

    // init the textures
    {
        gltexture_t* tex;
        if(!shared_glstate) {
            int ret;
            khint_t k;
            khash_t(tex) *list = glstate->texture.list;
            list = glstate->texture.list = kh_init(tex);
            // segfaults if we don't do a single put
            k = kh_put(tex, list, 1, &ret);
            kh_del(tex, list, k);
        }
        // now add default "0" texture => no, because tex 0 is not shared....
        /*k = kh_put(tex, list, 0, &ret);
        glstate->texture.zero = tex = kh_value(list, k) = malloc(sizeof(gltexture_t));*/
        glstate->texture.zero = tex = calloc(1, sizeof(gltexture_t));
        tex->adjustxy[0] = tex->adjustxy[1] = 1.f;
        tex->mipmap_auto = (globals4es.automipmap==1);
        tex->mipmap_need = (globals4es.automipmap==1)?1:0;
        tex->streamingID = -1;
        tex->base_level = -1;
        tex->max_level = -1;
        tex->alpha = true;
        tex->min_filter = (globals4es.automipmap==1)?GL_LINEAR_MIPMAP_LINEAR:GL_LINEAR;
        tex->mag_filter = GL_LINEAR;
        tex->wrap_s = tex->wrap_t = GL_REPEAT;
        tex->fpe_format = FPE_TEX_RGBA;
        tex->format = GL_RGBA;
        tex->type = GL_UNSIGNED_BYTE;
        tex->inter_format = GL_RGBA;
        tex->inter_type = GL_UNSIGNED_BYTE;
        // now bind that texture on all unit
        for (int itarget=0; itarget<ENABLED_TEXTURE_LAST; ++itarget)
            for (int i=0; i<MAX_TEX; ++i)
                glstate->texture.bound[i][itarget] = tex;
    }


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
    // Depth
    glstate->depth.func = GL_LESS;
    glstate->depth.mask = GL_TRUE;
    glstate->depth.far  = 1.0f;
    glstate->depth.clear= 1.0f;
    // Face
    glstate->face.cull  = GL_BACK;
    glstate->face.front = GL_CCW;
    // Point Sprite
    glstate->pointsprite.size = 1.0f;
    glstate->pointsprite.sizeMax = 32.0f;   // spec indicate 1., but it seems it's set to hardware limit, so puting 32...
    glstate->pointsprite.fadeThresholdSize = 1.0f;
    glstate->pointsprite.distance[0] = 1.0f;
    glstate->pointsprite.coordOrigin = GL_UPPER_LEFT;
    // Stencil
    glstate->stencil.func[0] = glstate->stencil.func[1] = GL_ALWAYS;
    //glstate->stencil.f_ref[0] = glstate->stencil.f_ref[1] = 0;
    glstate->stencil.f_mask[0] = glstate->stencil.f_mask[1] = ~(GLuint)0;
    glstate->stencil.mask[0] = glstate->stencil.mask[1] = ~(GLuint)0;
    glstate->stencil.sfail[0] = glstate->stencil.sfail[1] = GL_KEEP;
    glstate->stencil.dpfail[0] = glstate->stencil.dpfail[1] = GL_KEEP;
    glstate->stencil.dppass[0] = glstate->stencil.dppass[1] = GL_KEEP;
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
        glstate->fpe_state = (fpe_state_t*)calloc(1, sizeof(fpe_state_t));
        glstate->glsl->es2 = es2only;
        if(!shared_glstate)
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
    if(!shared_glstate)
    {
        khint_t k;
        int ret;
        khash_t(shaderlist) *shaders = glstate->glsl->shaders = kh_init(shaderlist);
		k = kh_put(shaderlist, shaders, 1, &ret);
		kh_del(shaderlist, shaders, k);
        khash_t(programlist) *programs = glstate->glsl->programs = kh_init(programlist);
		k = kh_put(programlist, programs, 1, &ret);
		kh_del(programlist, programs, k);
    }

    // Grab ViewPort
    LOAD_GLES(glGetIntegerv);
#ifdef AMIGAOS4
    if(default_glstate) // if default_glstate is null, then there is probably no glcontext...
#endif
    gles_glGetIntegerv(GL_VIEWPORT, (GLint*)&glstate->raster.viewport);
    // FBO
    glstate->fbowidth  = glstate->fbo.mainfbo_width  = glstate->raster.viewport.width;
    glstate->fboheight = glstate->fbo.mainfbo_height = glstate->raster.viewport.height;
    glstate->fbo.mainfbo_nwidth = (hardext.npot)?glstate->fbo.mainfbo_width:npot(glstate->fbo.mainfbo_width);
    glstate->fbo.mainfbo_nheight = (hardext.npot)?glstate->fbo.mainfbo_height:npot(glstate->fbo.mainfbo_height);
    // add default Renderbuffer
    if(!shared_glstate)
    {
        khint_t k;
        int ret;
        khash_t(renderbufferlist_t) *list = glstate->fbo.renderbufferlist = kh_init(renderbufferlist_t);
        k = kh_put(renderbufferlist_t, list, 0, &ret);
        glrenderbuffer_t *rend = kh_value(list, k) = calloc(1, sizeof(glrenderbuffer_t));
        glstate->fbo.default_rb = rend;
    }
    // add default Framebuffer
    if(!shared_glstate)
    {
        khint_t k;
        int ret;
        khash_t(framebufferlist_t) *list = glstate->fbo.framebufferlist = kh_init(framebufferlist_t);
        k = kh_put(framebufferlist_t, list, 0, &ret);
        glframebuffer_t *fb = kh_value(list, k) = calloc(1, sizeof(glframebuffer_t));
        fb->width = glstate->fbo.mainfbo_width;
        fb->height = glstate->fbo.mainfbo_height;
        glstate->fbo.fbo_0 = fb;
        if(globals4es.recyclefbo) {
            glstate->fbo.old = (oldfbos_t*)calloc(1, sizeof(oldfbos_t));
        }
    }
    glstate->fbo.current_fb = glstate->fbo.fbo_0;
    glstate->fbo.current_rb = glstate->fbo.default_rb;
    glstate->fbo.fbo_read = glstate->fbo.fbo_0;
    glstate->fbo.fbo_draw = glstate->fbo.fbo_0;
    // Get the per/context hardware values
    glstate->readf = GL_RGBA;
    glstate->readt = GL_UNSIGNED_BYTE;
#ifdef AMIGAOS4
    if(default_glstate) // if default_glstate is null, then there is probably no glcontext...
    {
#endif
    gles_glGetIntegerv(GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES, &glstate->readf);
    gles_glGetIntegerv(GL_IMPLEMENTATION_COLOR_READ_TYPE_OES, &glstate->readt);
#ifdef AMIGAOS4
    }
#endif
    //printf("LIBGL: Implementation Read is %s/%s\n", PrintEnum(glstate->readf), PrintEnum(glstate->readt));

    // All done
    return (void*)glstate;
}


void DeleteGLState(void* oldstate) {
    glstate_t* state = (glstate_t*)oldstate;
    if(!state) return;

    if(state->shared_cnt) {
        if(!--(*state->shared_cnt)) {
            free(state->shared_cnt);
            state->shared_cnt = 0;
        }
    }
    if(globals4es.noclean)
        return;
        
    if(glstate == state)
        glstate = NULL;

    if(!state->shared_cnt)
        free(state->actual_tex2d);
    
    #define free_hashmap(T, N, K, F)        \
    if(state->N)                            \
    {                                       \
        T *m;                               \
        kh_foreach_value(state->N, m,       \
            F(m);                        \
        )                                   \
        kh_destroy(K, state->N);            \
    }
    free_hashmap(glvao_t, vaos, glvao, free);
    if(!state->shared_cnt) {
        free_hashmap(glquery_t, queries, queries, free);
        free_hashmap(glbuffer_t, buffers, buff, free);
        free_hashmap(gltexture_t, texture.list, tex, free_texture);
        free_hashmap(renderlist_t, headlists, gllisthead, free_renderlist);
        free_hashmap(glrenderbuffer_t, fbo.renderbufferlist, renderbufferlist_t, free_renderbuffer);
        free_hashmap(glframebuffer_t, fbo.framebufferlist, framebufferlist_t, free_framebuffer);
    }
    #undef free_hashmap
    // free texture zero as it's not in the list anymore
    free(state->texture.zero);
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
    if(!state->shared_cnt && state->list.active) free_renderlist(state->list.active);

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
	free(state->texture_matrix);
    #undef free_matrix
    // linestipple
    if(state->linestipple.data)
        free(state->linestipple.data);
    // raster / bitmap
    if(state->raster.data)
        free(state->raster.data);
    if(state->raster.bitmap)
        free(state->raster.bitmap);
    // TODO: delete the "immediate" stuff and bitmap texture?
    // scratch buffer
    if(state->scratch)
        free(state->scratch);
    // merger buffers
    if(state->merger_master)
        free(state->merger_master);
    if(state->merger_secondary)
        free(state->merger_secondary);
    for(int a=0; a<MAX_TEX-2; ++a)
        if(state->merger_tex[a])
            free(state->merger_tex[a]);
    // mainfbo
    if(!state->shared_cnt) {
        if(state->fbo.mainfbo_fbo)
            deleteMainFBO(state);
    }
    // oldfbos
    if(!state->shared_cnt && state->fbo.old) {
        LOAD_GLES2_OR_OES(glDeleteFramebuffers);
        gles_glDeleteFramebuffers(state->fbo.old->nbr, state->fbo.old->fbos);
        free(state->fbo.old->fbos);
        free(state->fbo.old);
    }
    // free blit GLES2 stuff
    if(state->blit) {
        //TODO: check if should delete GL object too
        free(state->blit);
    }
    if(!state->shared_cnt) {
        free(state->glsl);
        free(state->gleshard);
        if(state->fpe_cache) {
            fpe_Dispose(state);
        }
    }
    //TODO: free sharderlist and programlist...

    // probably missing some things to free here!

    // all done
    free(state);
    return;
}

void ActivateGLState(void* new_glstate) {
    glstate_t *newstate = (new_glstate)?(glstate_t*)new_glstate:default_glstate;
    if(glstate == newstate) return;  // same state, nothing to do
    // check if viewport is correct
#ifdef AMIGAOS4
    if(glstate || newstate!=default_glstate) // avoid getting gles info with no context
#endif
    if(new_glstate && (newstate->raster.viewport.width==0.0f || newstate->raster.viewport.height==0.0f)) {
        LOAD_GLES(glGetFloatv);
        gles_glGetFloatv(GL_VIEWPORT, (GLfloat*)&newstate->raster.viewport);
    }
    glstate = newstate;
}

void gl_init() {
    default_glstate = (glstate_t*)NewGLState(NULL, 0);
    ActivateGLState(default_glstate);
}

