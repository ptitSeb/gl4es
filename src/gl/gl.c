#include "gl.h"
#include "debug.h"
#include "../glx/hardext.h"
#include "init.h"

glstate_t *glstate = NULL;

glstate_t *default_glstate = NULL;

void init_matrix(glstate_t* glstate);

void* NewGLState(void* shared_glstate) {
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
        memset(glvao, 0, sizeof(glvao_t));
        // just put is number
        glvao->array = 0;
        glstate->defaultvao = glvao;
    }
    // Bind defaults...
    glstate->vao = glstate->defaultvao;

    glstate->shared_cnt = 0;

    glstate->gl_batch = globals4es.batch;

    //raster & viewport
    glstate->raster.raster_zoomx=1.0f;
    glstate->raster.raster_zoomy=1.0f;

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

    for(int i=0; i<4; i++)
        glstate->raster.raster_scale[i] = 1.0f;
    LOAD_GLES(glGetFloatv);
    gles_glGetFloatv(GL_VIEWPORT, (GLfloat*)&glstate->raster.viewport);
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


    #define free_hashmap(T, N, K)           \
    {                                       \
        T *m;                               \
        kh_foreach_value(state->N, m,       \
            free(m);                        \
        )                                   \
        kh_destroy(K, state->N);            \
    }
    free_hashmap(glvao_t, vaos, glvao);
    free_hashmap(glbuffer_t, buffers, buff);
    free_hashmap(glquery_t, queries, queries);
    free_hashmap(gltexture_t, texture.list, tex);
    #undef free_hashmap
    // free eval maps
    #define freemap(dims, name)                              \
    { map_statef_t *m = (map_statef_t *)state->map##dims.name; \
    if (m) {                                                \
        if (m->free)                                        \
            free((void *)m->points);                        \
        free(m);                                            \
    } }
    freemap(1, vertex3); freemap(1, vertex4); freemap(1, index); freemap(1, color4); freemap(1, normal); 
    freemap(1, texture1); freemap(1, texture2); freemap(1, texture3); freemap(1, texture4);   
    freemap(2, vertex3); freemap(2, vertex4); freemap(2, index); freemap(2, color4); freemap(2, normal); 
    freemap(2, texture1); freemap(2, texture2); freemap(2, texture3); freemap(2, texture4);   
    #undef freemap
    // free lists
    if(state->lists) {
        for (int i=0; i<state->list.count; i++)
            free_renderlist(state->lists[i]);
        free(state->lists);
    }
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
    default_glstate = (glstate_t*)NewGLState(NULL);
    ActivateGLState(default_glstate);
}

#ifndef GL_TEXTURE_STREAM_IMG  
#define GL_TEXTURE_STREAM_IMG                                   0x8C0D     
#endif

static void proxy_glEnable(GLenum cap, bool enable, void (*next)(GLenum)) {
    #define proxy_enable(constant, name) \
        case constant: glstate->enable.name = enable; next(cap); break
    #define enable(constant, name) \
        case constant: glstate->enable.name = enable; break;
    #define proxy_clientenable(constant, name) \
        case constant: glstate->vao->name = enable; next(cap); break
    #define clientenable(constant, name) \
        case constant: glstate->vao->name = enable; break;

    // TODO: maybe could be weird behavior if someone tried to:
    // 1. enable GL_TEXTURE_1D
    // 2. enable GL_TEXTURE_2D
    // 3. disable GL_TEXTURE_1D
    // 4. render. GL_TEXTURE_2D would be disabled.
    // cap = map_tex_target(cap);
    
    // Alpha Hack
    if (globals4es.alphahack && (cap==GL_ALPHA_TEST) && enable) {
        if (glstate->texture.bound[glstate->texture.active][ENABLED_TEX2D])
            if (!glstate->texture.bound[glstate->texture.active][ENABLED_TEX2D]->alpha)
                enable = false;
    }
	noerrorShim();
#ifdef TEXSTREAM
    if (cap==GL_TEXTURE_STREAM_IMG)
        if(enable)
            glstate->enable.texture[glstate->texture.active] |= (1<<ENABLED_TEX2D);
        else
            glstate->enable.texture[glstate->texture.active] &= ~(1<<ENABLED_TEX2D);
#endif
    switch (cap) {
        enable(GL_AUTO_NORMAL, auto_normal);
        proxy_enable(GL_BLEND, blend);
        case GL_TEXTURE_2D:
            if(enable)
                glstate->enable.texture[glstate->texture.active] |= (1<<ENABLED_TEX2D);
            else
                glstate->enable.texture[glstate->texture.active] &= ~(1<<ENABLED_TEX2D);
            next(cap);
            break;

        enable(GL_TEXTURE_GEN_S, texgen_s[glstate->texture.active]);
        enable(GL_TEXTURE_GEN_T, texgen_t[glstate->texture.active]);
        enable(GL_TEXTURE_GEN_R, texgen_r[glstate->texture.active]);
        enable(GL_TEXTURE_GEN_Q, texgen_q[glstate->texture.active]);
        enable(GL_LINE_STIPPLE, line_stipple);

        // point sprite
        proxy_enable(GL_POINT_SPRITE, pointsprite);
        
        // Secondary color
        enable(GL_COLOR_SUM, color_sum);
        clientenable(GL_SECONDARY_COLOR_ARRAY, secondary_array);
	
        // for glDrawArrays
        clientenable(GL_VERTEX_ARRAY, vertex_array);
        clientenable(GL_NORMAL_ARRAY, normal_array);
        clientenable(GL_COLOR_ARRAY, color_array);
        clientenable(GL_TEXTURE_COORD_ARRAY, tex_coord_array[glstate->texture.client]);
        
        // Texture 1D and 3D
        case GL_TEXTURE_1D:
            if(enable)
                glstate->enable.texture[glstate->texture.active] |= (1<<ENABLED_TEX1D);
            else
                glstate->enable.texture[glstate->texture.active] &= ~(1<<ENABLED_TEX1D);
            break;
        case GL_TEXTURE_3D:
            if(enable)
                glstate->enable.texture[glstate->texture.active] |= (1<<ENABLED_TEX3D);
            else
                glstate->enable.texture[glstate->texture.active] &= ~(1<<ENABLED_TEX3D);
            break;
        case GL_TEXTURE_RECTANGLE_ARB:
            if(enable)
                glstate->enable.texture[glstate->texture.active] |= (1<<ENABLED_TEXTURE_RECTANGLE);
            else
                glstate->enable.texture[glstate->texture.active] &= ~(1<<ENABLED_TEXTURE_RECTANGLE);
            break;
        case GL_TEXTURE_CUBE_MAP:
            if(enable)
                glstate->enable.texture[glstate->texture.active] |= (1<<ENABLED_CUBE_MAP);
            else
                glstate->enable.texture[glstate->texture.active] &= ~(1<<ENABLED_CUBE_MAP);
            next(cap);
            break;

        
        default: errorGL(); next(cap); break;
    }
    #undef proxy_enable
    #undef enable
    #undef proxy_clientenable
    #undef clientenable
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

void gl4es_glEnable(GLenum cap) {
    if (glstate->list.active && (glstate->gl_batch && !glstate->list.compiling))  {
        int which_cap = Cap2BatchState(cap);
        if (which_cap<ENABLED_LAST) {
            if ((glstate->statebatch.enabled[which_cap] == 1))
                return; // nothing to do...
            if (glstate->statebatch.enabled[which_cap])
                flush();
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
#endif
    LOAD_GLES(glEnable);
    proxy_glEnable(cap, true, gles_glEnable);
}
void glEnable(GLenum cap) AliasExport("gl4es_glEnable");

void gl4es_glDisable(GLenum cap) {
    if (glstate->list.active && (glstate->gl_batch && !glstate->list.compiling))  {
        int which_cap = Cap2BatchState(cap);
        if (which_cap<ENABLED_LAST) {
            if ((glstate->statebatch.enabled[which_cap] == 2))
                return; // nothing to do...
            if (glstate->statebatch.enabled[which_cap])
                flush();
            glstate->statebatch.enabled[which_cap] = 2;
        }
    }
	PUSH_IF_COMPILING(glDisable)
        
	if (globals4es.texstream && (cap==GL_TEXTURE_2D)) {
		if (glstate->texture.bound[glstate->texture.active][ENABLED_TEX2D])
			if (glstate->texture.bound[glstate->texture.active][ENABLED_TEX2D]->streamed)
				cap = GL_TEXTURE_STREAM_IMG;
	}

    LOAD_GLES(glDisable);
    proxy_glEnable(cap, false, gles_glDisable);
}
void glDisable(GLenum cap) AliasExport("gl4es_glDisable");

void gl4es_glEnableClientState(GLenum cap) {
    ERROR_IN_BEGIN
    // should flush for now... to be optimized later!
    if (glstate->list.active && !glstate->list.compiling)
        flush();
    LOAD_GLES(glEnableClientState);
    proxy_glEnable(cap, true, gles_glEnableClientState);
}
void glEnableClientState(GLenum cap) AliasExport("gl4es_glEnableClientState");

void gl4es_glDisableClientState(GLenum cap) {
    ERROR_IN_BEGIN
    // should flush for now... to be optimized later!
    if (glstate->list.active && !glstate->list.compiling)
        flush();
    LOAD_GLES(glDisableClientState);
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
        isenabled(GL_LINE_STIPPLE, line_stipple);
        isenabled(GL_TEXTURE_GEN_S, texgen_s[glstate->texture.active]);
        isenabled(GL_TEXTURE_GEN_T, texgen_t[glstate->texture.active]);
        isenabled(GL_TEXTURE_GEN_R, texgen_r[glstate->texture.active]);
        isenabled(GL_TEXTURE_GEN_Q, texgen_q[glstate->texture.active]);
		isenabled(GL_COLOR_SUM, color_sum);
        isenabled(GL_POINT_SPRITE, pointsprite);
		clientisenabled(GL_SECONDARY_COLOR_ARRAY, secondary_array);
        case GL_TEXTURE_1D: return glstate->enable.texture[glstate->texture.active]&(1<<ENABLED_TEX1D);
        case GL_TEXTURE_2D: return glstate->enable.texture[glstate->texture.active]&(1<<ENABLED_TEX2D);
        case GL_TEXTURE_3D: return glstate->enable.texture[glstate->texture.active]&(1<<ENABLED_TEX3D);
        case GL_TEXTURE_CUBE_MAP: return glstate->enable.texture[glstate->texture.active]&(1<<ENABLED_CUBE_MAP);
        clientisenabled(GL_VERTEX_ARRAY, vertex_array);
        clientisenabled(GL_NORMAL_ARRAY, normal_array);
        clientisenabled(GL_COLOR_ARRAY, color_array);
        clientisenabled(GL_TEXTURE_COORD_ARRAY, tex_coord_array[glstate->texture.client]);
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
    return list;
}

static inline bool should_intercept_render(GLenum mode) {
    // check bounded tex that will be used if one need some transformations
    for (int aa=0; aa<hardext.maxtex; aa++) {
        if (glstate->enable.texture[aa]) {
            if ((glstate->enable.texgen_s[aa] || glstate->enable.texgen_t[aa] || glstate->enable.texgen_r[aa] || glstate->enable.texgen_q[aa]))
                return true;
            if ((!glstate->vao->tex_coord_array[aa]) && !(mode==GL_POINT && glstate->texture.pscoordreplace[aa]))
                return true;
            if ((glstate->vao->tex_coord_array[aa]) && (glstate->vao->pointers.tex_coord[aa].size == 1))
                return true;
        }
    }
    if(glstate->polygon_mode == GL_LINE && mode>=GL_TRIANGLES)
        return true;
    if ((glstate->vao->secondary_array) && (glstate->vao->color_array))
        return true;
    if (glstate->vao->color_array && (glstate->vao->pointers.color.size != 4))
        return true;
    return (
        (glstate->vao->vertex_array && ! valid_vertex_type(glstate->vao->pointers.vertex.type)) ||
        (mode == GL_LINES && glstate->enable.line_stipple) ||
        /*(mode == GL_QUADS) ||*/ (glstate->list.active)
    );
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
		LOAD_GLES(glDrawElements);
		LOAD_GLES(glNormalPointer);
		LOAD_GLES(glVertexPointer);
		LOAD_GLES(glColorPointer);
		LOAD_GLES(glTexCoordPointer);
        LOAD_GLES(glEnable);
        LOAD_GLES(glDisable);
        LOAD_GLES(glEnableClientState);
        LOAD_GLES(glDisableClientState);
        LOAD_GLES(glMultiTexCoord4f);
        GLuint len = 0;
        for (int i=0; i<count; i++)
            if (len<sindices[i]) len = sindices[i]; // get the len of the arrays
        len++;  // lenght is max(indices) + 1 !
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
            // secondry color and color sizef != 4 are "intercepted" and draw using a list
            client_state(color_array, GL_COLOR_ARRAY, );
            if (glstate->vao->color_array)
				gles_glColorPointer(glstate->vao->pointers.color.size, glstate->vao->pointers.color.type, glstate->vao->pointers.color.stride, glstate->vao->pointers.color.pointer);
            client_state(normal_array, GL_NORMAL_ARRAY, );
			if (glstate->vao->normal_array)
				gles_glNormalPointer(glstate->vao->pointers.normal.type, glstate->vao->pointers.normal.stride, glstate->vao->pointers.normal.pointer);
            client_state(vertex_array, GL_VERTEX_ARRAY, );
			if (glstate->vao->vertex_array)
				gles_glVertexPointer(glstate->vao->pointers.vertex.size, glstate->vao->pointers.vertex.type, glstate->vao->pointers.vertex.stride, glstate->vao->pointers.vertex.pointer);
			GLuint old_tex = glstate->texture.client;
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
                        tex_setup_texcoord(len, itarget);
                    } else
                        gles_glMultiTexCoord4f(GL_TEXTURE0+aa, glstate->texcoord[aa][0], glstate->texcoord[aa][1], glstate->texcoord[aa][2], glstate->texcoord[aa][3]);
                } else if (glstate->clientstate.tex_coord_array[aa]) {
                    // special case, Tex disable but CoordArray enabled... disabling it temporarly
                    TEXTURE(aa);
                    glstate->clientstate.tex_coord_array[aa] = 0;
                    gles_glDisableClientState(GL_TEXTURE_COORD_ARRAY);
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
	LOAD_GLES(glNormalPointer);
	LOAD_GLES(glVertexPointer);
	LOAD_GLES(glColorPointer);
	LOAD_GLES(glTexCoordPointer);
    LOAD_GLES(glEnable);
    LOAD_GLES(glDisable);
    LOAD_GLES(glEnableClientState);
    LOAD_GLES(glDisableClientState);
    LOAD_GLES(glMultiTexCoord4f);

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
            static GLushort *indices = NULL;
            static int indcnt = 0;
            static int indfirst = 0;
            if((indcnt < count) || (indfirst!=first)) {
                if(indcnt < count) {
                    indcnt = count;
                    if (indices) free(indices);
                    indices = (GLushort*)malloc(sizeof(GLushort)*(indcnt*3/2));
                }
                indfirst = first;
                for (int i=0, j=0; i+3<indcnt; i+=4, j+=6) {
                        indices[j+0] = indfirst + i+0;
                        indices[j+1] = indfirst + i+1;
                        indices[j+2] = indfirst + i+2;

                        indices[j+3] = indfirst + i+0;
                        indices[j+4] = indfirst + i+2;
                        indices[j+5] = indfirst + i+3;
                }
            }
            // take care of vao elements, just in case
            glbuffer_t *old_vao_elements = glstate->vao->elements;
            glstate->vao->elements = NULL;
            gl4es_glDrawElements(GL_TRIANGLES, count*3/2, GL_UNSIGNED_SHORT, indices);
            glstate->vao->elements = old_vao_elements;
            return;
        }

        LOAD_GLES(glDrawArrays);

		GLenum mode_init = mode;
		if (mode == GL_QUAD_STRIP)
			mode = GL_TRIANGLE_STRIP;
		if (mode == GL_POLYGON)
			mode = GL_TRIANGLE_FAN;
			
		if (glstate->render_mode == GL_SELECT) {
			select_glDrawArrays(&glstate->vao->pointers.vertex, mode, first, count);
		} else {
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
			GLuint old_tex = glstate->texture.client;
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

			gles_glDrawArrays(mode, first, count);
			
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
		}
    }
}
#undef client_state
void glDrawArrays(GLenum mode, GLint first, GLsizei count) AliasExport("gl4es_glDrawArrays");

#ifndef USE_ES2
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

#undef clone_gl_pointer
#endif
void glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) AliasExport("gl4es_glVertexPointer");
void glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) AliasExport("gl4es_glColorPointer");
void glNormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer) AliasExport("gl4es_glNormalPointer");
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) AliasExport("gl4es_glTexCoordPointer");
void glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer) AliasExport("gl4es_glSecondaryColorPointer");

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
    for (int a=0; a<MAX_TEX; a++)
		if (glstate->enable.texture[a] && ((glstate->list.active->tex[a]==0) && !(glstate->enable.texgen_s[a] || glstate->texture.pscoordreplace[a])))
			rlMultiTexCoord4f(glstate->list.active, GL_TEXTURE0+a, glstate->texcoord[a][0], glstate->texcoord[a][1], glstate->texcoord[a][2], glstate->texcoord[a][3]);
    // render if we're not in a display list
    if (!(glstate->list.compiling || glstate->gl_batch) && (!(globals4es.mergelist) || (glstate->polygon_mode==GL_LINE))) {
        renderlist_t *mylist = glstate->list.active;
        glstate->list.active = NULL;
        mylist = end_renderlist(mylist);
        draw_renderlist(mylist);
        free_renderlist(mylist);
    } else {
        if(!(glstate->list.compiling || glstate->gl_batch)) {
            glstate->list.pending = 1;
            NewStage(glstate->list.active, STAGE_POSTDRAW);
        }
        else glstate->list.active = extend_renderlist(glstate->list.active);
    }
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
#ifndef USE_ES2
    else {
        LOAD_GLES(glNormal3f);
        gles_glNormal3f(nx, ny, nz);
        errorGL();
    }
#endif
    glstate->normal[0] = nx; glstate->normal[1] = ny; glstate->normal[2] = nz;
}
void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) AliasExport("gl4es_glNormal3f");

void gl4es_glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    if (glstate->list.active) {
        rlVertex4f(glstate->list.active, x, y, z, w);
        noerrorShim();
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
                PUSH_IF_COMPILING(glColor4f);
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
    }
#ifndef USE_ES2
    else {
        LOAD_GLES(glColor4f);
        gles_glColor4f(red, green, blue, alpha);
        errorGL();
    }
#endif
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
        else
            rlMultiTexCoord4f(glstate->list.active, GL_TEXTURE0, s, t, r, q);
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
        else
            rlMultiTexCoord4f(glstate->list.active, target, s, t, r, q);
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
    if (glIsList(list))
        return glstate->lists[list - 1];

    return NULL;
}

GLuint gl4es_glGenLists(GLsizei range) {
	if (range<0) {
		errorShim(GL_INVALID_VALUE);
		return 0;
	}
	noerrorShim();
    int start = glstate->list.count;
    if (glstate->lists == NULL) {
        glstate->list.cap += range + 100;
        glstate->lists = malloc(glstate->list.cap * sizeof(uintptr_t));
    } else if (glstate->list.count + range > glstate->list.cap) {
        glstate->list.cap += range + 100;
        glstate->lists = realloc(glstate->lists, glstate->list.cap * sizeof(uintptr_t));
    }
    glstate->list.count += range;

    for (int i = 0; i < range; i++) {
        glstate->lists[start+i] = NULL;
    }
    return start + 1;
}
GLuint glGenLists(GLsizei range) AliasExport("gl4es_glGenLists");


void gl4es_glNewList(GLuint list, GLenum mode) {
	errorShim(GL_INVALID_VALUE);
	if (list==0)
		return;
    if (! glIsList(list))
        return;
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
    if (glstate->list.compiling) {
	// Free the previous list if it exist...
        free_renderlist(glstate->lists[list - 1]);
        glstate->lists[list - 1] = GetFirst(glstate->list.active);
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
    renderlist_t *l = gl4es_glGetList(list);
    if (l) {
        free_renderlist(l);
        glstate->lists[list-1] = NULL;
    }

    // lists just grow upwards, maybe use a better storage mechanism?
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
    if (list - 1 < glstate->list.count) {
        return true;
    }
    return false;
}
GLboolean glIsList(GLuint list) AliasExport("gl4es_glIsList");

void gl4es_glPolygonMode(GLenum face, GLenum mode) {
    ERROR_IN_BEGIN
	noerrorShim();
	if (face != GL_FRONT_AND_BACK)
		errorShim(GL_INVALID_ENUM);
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

void gl4es_glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) {
    PUSH_IF_COMPILING(glBlendColor);
    LOAD_GLES_OES(glBlendColor);
	if  (gles_glBlendColor)
		gles_glBlendColor(red, green, blue, alpha);
	else {
        static int test = 1;
        if (test) {
            LOGD("stub glBlendColor(%f, %f, %f, %f)\n", red, green, blue, alpha);
            test = 0;
        }
    }
}
void glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) AliasExport("gl4es_glBlendColor");
void glBlendColorEXT(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) AliasExport("gl4es_glBlendColor");
void glBlendColorARB(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha) AliasExport("gl4es_glBlendColor");

void gl4es_glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)
{
    PUSH_IF_COMPILING(glBlendFuncSeparate);
    LOAD_GLES_OES(glBlendFuncSeparate);
#ifdef ODROID
    if(gles_glBlendFuncSeparate)
#endif
    gles_glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}
void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) AliasExport("gl4es_glBlendFuncSeparate");
void glBlendFuncSeparateEXT (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) AliasExport("gl4es_glBlendFuncSeparate");

void gl4es_glBlendEquationSeparate(GLenum modeRGB, GLenum modeA) {
    PUSH_IF_COMPILING(glBlendEquationSeparate);
    LOAD_GLES_OES(glBlendEquationSeparate);
#ifdef ODROID
    if(gles_glBlendEquationSeparate)
#endif
    gles_glBlendEquationSeparate(modeRGB, modeA);
}
void glBlendEquationSeparate(GLenum modeRGB, GLenum modeA) AliasExport("gl4es_glBlendEquationSeparate");
void glBlendEquationSeparateEXT(GLenum modeRGB, GLenum modeA) AliasExport("gl4es_glBlendEquationSeparate");

void gl4es_glBlendFunc(GLenum sfactor, GLenum dfactor) {
    if (glstate->list.active)
        if (!glstate->list.compiling && glstate->gl_batch) {
            if ((glstate->statebatch.blendfunc_s == sfactor) && (glstate->statebatch.blendfunc_d == dfactor))
                return; // nothing to do...
            if (!glstate->statebatch.blendfunc_s) {
                glstate->statebatch.blendfunc_s = sfactor;
                glstate->statebatch.blendfunc_d = dfactor;
            }
        } 

    PUSH_IF_COMPILING(glBlendFunc)
    LOAD_GLES(glBlendFunc);
    LOAD_GLES_OES(glBlendFuncSeparate);
    errorGL();
    // There are some limitations in GLES1.1 Blend functions
    switch(sfactor) {
        case GL_SRC_COLOR:
            if (gles_glBlendFuncSeparate) {
                gles_glBlendFuncSeparate(sfactor, dfactor, sfactor, dfactor);
                return;
            }
            sfactor = GL_ONE;   // approx...
            break;
        case GL_ONE_MINUS_SRC_COLOR:
            if (gles_glBlendFuncSeparate) {
                gles_glBlendFuncSeparate(sfactor, dfactor, sfactor, dfactor);
                return;
            }
            sfactor = GL_ONE;  // not sure it make sense...
            break;
        // here, we need support for glBlendColor...
        case GL_CONSTANT_COLOR:
        case GL_CONSTANT_ALPHA:
            sfactor = GL_ONE;
            break;
        case GL_ONE_MINUS_CONSTANT_COLOR:
        case GL_ONE_MINUS_CONSTANT_ALPHA:
            sfactor = GL_ZERO;
            break;
        default:
            break;
    }
    
    switch(dfactor) {
        case GL_DST_COLOR:
            sfactor = GL_ONE;   // approx...
            break;
        case GL_ONE_MINUS_DST_COLOR:
            sfactor = GL_ZERO;  // not sure it make sense...
            break;
        // here, we need support for glBlendColor...
        case GL_CONSTANT_COLOR:
        case GL_CONSTANT_ALPHA:
            sfactor = GL_ONE;
            break;
        case GL_ONE_MINUS_CONSTANT_COLOR:
        case GL_ONE_MINUS_CONSTANT_ALPHA:
            sfactor = GL_ZERO;
            break;
        default:
            break;
    }
    
    if ((globals4es.blendhack) && (sfactor==GL_SRC_ALPHA) && (dfactor==GL_ONE)) {
        // special case, as seen in Xash3D, but it breaks torus_trooper, so behind a parameter
        sfactor = GL_ONE;
    }

#ifdef ODROID
    if(gles_glBlendFunc)
#endif
    gles_glBlendFunc(sfactor, dfactor);
}
void glBlendFunc(GLenum sfactor, GLenum dfactor) AliasExport("gl4es_glBlendFunc");


void gl4es_glStencilMaskSeparate(GLenum face, GLuint mask) {
    // fake function..., call it only for front or front_and_back, just ignore back (crappy, I know)
    if ((face==GL_FRONT) || (face==GL_FRONT_AND_BACK))
        gl4es_glStencilMask(mask);
}
void glStencilMaskSeparate(GLenum face, GLuint mask) AliasExport("gl4es_glStencilMaskSeparate");


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

void gl4es_glFogfv(GLenum pname, const GLfloat* params) {

    if (glstate->list.active)
        if (glstate->list.compiling || glstate->gl_batch) {
                NewStage(glstate->list.active, STAGE_FOG);
                rlFogOp(glstate->list.active, pname, params);
                return;
            }
        else flush();

    LOAD_GLES(glFogfv);
    gles_glFogfv(pname, params);
}
void glFogfv(GLenum pname, const GLfloat* params) AliasExport("gl4es_glFogfv");

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

void gl4es_glPointParameteri(GLenum pname, GLint param)
{
    gl4es_glPointParameterf(pname, param);
}
void glPointParameteri(GLenum pname, GLint param) AliasExport("gl4es_glPointParameteri");

void gl4es_glPointParameteriv(GLenum pname, const GLint * params)
{
    GLfloat tmp[3];
    int v=(pname==GL_POINT_DISTANCE_ATTENUATION)?3:1;
    for (int i=0; i<v; i++) tmp[i] = params[i];
    gl4es_glPointParameterfv(pname, tmp);
}
void glPointParameteriv(GLenum pname, const GLint * params) AliasExport("gl4es_glPointParameteriv");

void gl4es_glPointParameterf(GLenum pname, GLfloat param) {
    PUSH_IF_COMPILING(glPointParameterf);
    LOAD_GLES(glPointParameterf);
    gles_glPointParameterf(pname, param);
}void glPointParameterf(GLenum pname, GLfloat param) AliasExport("gl4es_glPointParameterf");

void gl4es_glPointParameterfv(GLenum pname, const GLfloat * params)
{
    if (glstate->list.active)
        if (glstate->list.compiling || glstate->gl_batch) {
            if (pname == GL_POINT_DISTANCE_ATTENUATION) {
                NewStage(glstate->list.active, STAGE_POINTPARAM);
                rlPointParamOp(glstate->list.active, 1, params);
                return;
            } else {
                gl4es_glPointParameterf(pname, params[0]);
                return;
            }
        } else flush();

    LOAD_GLES(glPointParameterfv);

    gles_glPointParameterfv(pname, params);
}
void glPointParameterfv(GLenum pname, const GLfloat * params) AliasExport("gl4es_glPointParameterfv");



void gl4es_glMultiDrawArrays(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount)
{
    LOAD_GLES_EXT(glMultiDrawArrays);
    if(glstate->list.pending) flush();
    if((!gles_glMultiDrawArrays) || should_intercept_render(mode) || (mode==GL_QUADS) || (glstate->list.active && (glstate->list.compiling || glstate->gl_batch)) 
        || (glstate->render_mode == GL_SELECT) || ((glstate->polygon_mode == GL_LINE) || (glstate->polygon_mode == GL_POINT)) )
    {
        // GL_QUADS special case can probably by improved
        // divide the call
        // TODO optimize with forcing Batch mode
        for (int i=0; i<primcount; i++)
            gl4es_glDrawArrays(mode, first[i], count[i]);
    }
    else
    {
        if(mode==GL_QUAD_STRIP) mode=GL_TRIANGLE_STRIP;
        else if(mode==GL_POLYGON) mode=GL_TRIANGLE_FAN;
        gles_glMultiDrawArrays(mode, first, count, primcount);
        errorGL();
    }
}
void glMultiDrawArrays(GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount) AliasExport("gl4es_glMultiDrawArrays");

void gl4es_glMultiDrawElements( GLenum mode, GLsizei *count, GLenum type, const void * const *indices, GLsizei primcount)
{
    LOAD_GLES_EXT(glMultiDrawElements);
    if(glstate->list.pending) flush();
    if((!gles_glMultiDrawElements) || should_intercept_render(mode) || (mode==GL_QUADS) || (glstate->list.active && (glstate->list.compiling || glstate->gl_batch)) 
        || (glstate->render_mode == GL_SELECT) || ((glstate->polygon_mode == GL_LINE) || (glstate->polygon_mode == GL_POINT)) || (type != GL_UNSIGNED_SHORT) )
    {
        // divide the call
        // TODO optimize with forcing Batch mode
        for (int i=0; i<primcount; i++)
            gl4es_glDrawElements(mode, count[i], type, indices[i]);
    }
    else
    {
        if(mode==GL_QUAD_STRIP) mode=GL_TRIANGLE_STRIP;
        else if(mode==GL_POLYGON) mode=GL_TRIANGLE_FAN;
        gles_glMultiDrawElements(mode, count, type, indices, primcount);
        errorGL();
    }
}
void glMultiDrawElements( GLenum mode, GLsizei *count, GLenum type, const void * const *indices, GLsizei primcount) AliasExport("gl4es_glMultiDrawElements");
