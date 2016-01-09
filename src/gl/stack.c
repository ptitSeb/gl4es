#include "stack.h"

glstack_t *stack = NULL;
glclientstack_t *clientStack = NULL;

void glshim_glPushAttrib(GLbitfield mask) {
    //printf("glPushAttrib(0x%04X)\n", mask);
    noerrorShim();
    if ((glstate.list.compiling || glstate.gl_batch) && glstate.list.active) {
		NewStage(glstate.list.active, STAGE_PUSH);
		glstate.list.active->pushattribute = mask;
		return;
	}
    if (stack == NULL) {
        stack = (glstack_t *)malloc(STACK_SIZE * sizeof(glstack_t));
        stack->len = 0;
        stack->cap = STACK_SIZE;
    } else if (stack->len == stack->cap) {
        stack->cap += STACK_SIZE;
        stack = (glstack_t *)realloc(stack, stack->cap * sizeof(glstack_t));
    }

    glstack_t *cur = stack + stack->len;
    cur->mask = mask;
    cur->clip_planes_enabled = NULL;
    cur->clip_planes = NULL;
    cur->lights_enabled = NULL;
    cur->lights = NULL;

    // TODO: GL_ACCUM_BUFFER_BIT

    // TODO: will tracking these myself be much faster than glGet?
    if (mask & GL_COLOR_BUFFER_BIT) {
        cur->alpha_test = glshim_glIsEnabled(GL_ALPHA_TEST);
        glshim_glGetIntegerv(GL_ALPHA_TEST_FUNC, &cur->alpha_test_func);
        glshim_glGetFloatv(GL_ALPHA_TEST_REF, &cur->alpha_test_ref);

        cur->blend = glshim_glIsEnabled(GL_BLEND);
        glshim_glGetIntegerv(GL_BLEND_SRC, &cur->blend_src_func);
        glshim_glGetIntegerv(GL_BLEND_DST, &cur->blend_dst_func);

        cur->dither = glshim_glIsEnabled(GL_DITHER);
        cur->color_logic_op = glshim_glIsEnabled(GL_COLOR_LOGIC_OP);
        glshim_glGetIntegerv(GL_LOGIC_OP_MODE, &cur->logic_op);

        glshim_glGetFloatv(GL_COLOR_CLEAR_VALUE, cur->clear_color);
        glshim_glGetFloatv(GL_COLOR_WRITEMASK, cur->color_mask);
    }

    if (mask & GL_CURRENT_BIT) {
        glshim_glGetFloatv(GL_CURRENT_COLOR, cur->color);
        glshim_glGetFloatv(GL_CURRENT_NORMAL, cur->normal);
        glshim_glGetFloatv(GL_CURRENT_TEXTURE_COORDS, cur->tex);
    }

    if (mask & GL_DEPTH_BUFFER_BIT) {
        cur->depth_test = glshim_glIsEnabled(GL_DEPTH_TEST);
        glshim_glGetIntegerv(GL_DEPTH_FUNC, &cur->depth_func);
        glshim_glGetFloatv(GL_DEPTH_CLEAR_VALUE, &cur->clear_depth);
        glshim_glGetIntegerv(GL_DEPTH_WRITEMASK, &cur->depth_mask);
    }

    if (mask & GL_ENABLE_BIT) {
        int i;
        GLint max_clip_planes;

        cur->alpha_test = glshim_glIsEnabled(GL_ALPHA_TEST);
        cur->autonormal = glshim_glIsEnabled(GL_AUTO_NORMAL);
        cur->blend = glshim_glIsEnabled(GL_BLEND);
        
        glshim_glGetIntegerv(GL_MAX_CLIP_PLANES, &max_clip_planes);
        cur->clip_planes_enabled = (GLboolean *)malloc(max_clip_planes * sizeof(GLboolean));
        for (i = 0; i < max_clip_planes; i++) {
            *(cur->clip_planes_enabled + i) = glshim_glIsEnabled(GL_CLIP_PLANE0 + i);
        }

        cur->colormaterial = glshim_glIsEnabled(GL_COLOR_MATERIAL);
        cur->cull_face = glshim_glIsEnabled(GL_CULL_FACE);
        cur->depth_test = glshim_glIsEnabled(GL_DEPTH_TEST);
        cur->dither = glshim_glIsEnabled(GL_DITHER);
        cur->fog = glshim_glIsEnabled(GL_FOG);

        GLint max_lights;
        glshim_glGetIntegerv(GL_MAX_LIGHTS, &max_lights);
        cur->lights_enabled = (GLboolean *)malloc(max_lights * sizeof(GLboolean));
        for (i = 0; i < max_lights; i++) {
            *(cur->lights_enabled + i) = glshim_glIsEnabled(GL_LIGHT0 + i);
        }

        cur->lighting = glshim_glIsEnabled(GL_LIGHTING);
        cur->line_smooth = glshim_glIsEnabled(GL_LINE_SMOOTH);
        cur->line_stipple = glshim_glIsEnabled(GL_LINE_STIPPLE);
        cur->color_logic_op = glshim_glIsEnabled(GL_COLOR_LOGIC_OP);
        //TODO: GL_INDEX_LOGIC_OP
        //TODO: GL_MAP1_x
        //TODO: GL_MAP2_x
        cur->multisample = glshim_glIsEnabled(GL_MULTISAMPLE);
        cur->normalize = glshim_glIsEnabled(GL_NORMALIZE);
        cur->point_smooth = glshim_glIsEnabled(GL_POINT_SMOOTH);
        //TODO: GL_POLYGON_OFFSET_LINE
        cur->polygon_offset_fill = glshim_glIsEnabled(GL_POLYGON_OFFSET_FILL);
        //TODO: GL_POLYGON_OFFSET_POINT
        //TODO: GL_POLYGON_SMOOTH
        //TODO: GL_POLYGON_STIPPLE
        cur->sample_alpha_to_coverage = glshim_glIsEnabled(GL_SAMPLE_ALPHA_TO_COVERAGE);
        cur->sample_alpha_to_one = glshim_glIsEnabled(GL_SAMPLE_ALPHA_TO_ONE);
        cur->sample_coverage = glshim_glIsEnabled(GL_SAMPLE_COVERAGE);
        cur->scissor_test = glshim_glIsEnabled(GL_SCISSOR_TEST);
        cur->stencil_test = glshim_glIsEnabled(GL_STENCIL_TEST);
        int a;
        for (a=0; a<MAX_TEX; a++) {
            cur->texture_1d[a] = glstate.enable.texture_1d[a];
            cur->texture_2d[a] = glstate.enable.texture_2d[a];
            cur->texture_3d[a] = glstate.enable.texture_3d[a];
            cur->texgen_s[a] = glstate.enable.texgen_s[a];
            cur->texgen_r[a] = glstate.enable.texgen_r[a];
            cur->texgen_t[a] = glstate.enable.texgen_t[a];
        }
        
    }

    // TODO: GL_EVAL_BIT

    if (mask & GL_FOG_BIT) {
        cur->fog = glshim_glIsEnabled(GL_FOG);
        glshim_glGetFloatv(GL_FOG_COLOR, cur->fog_color);
        glshim_glGetFloatv(GL_FOG_DENSITY, &cur->fog_density);
        glshim_glGetFloatv(GL_FOG_START, &cur->fog_start);
        glshim_glGetFloatv(GL_FOG_END, &cur->fog_end);
        glshim_glGetIntegerv(GL_FOG_MODE, &cur->fog_mode);
    }

    if (mask & GL_HINT_BIT) {
        glshim_glGetIntegerv(GL_PERSPECTIVE_CORRECTION_HINT, &cur->perspective_hint);
        glshim_glGetIntegerv(GL_POINT_SMOOTH_HINT, &cur->point_smooth_hint);
        glshim_glGetIntegerv(GL_LINE_SMOOTH_HINT, &cur->line_smooth_hint);
        glshim_glGetIntegerv(GL_FOG_HINT, &cur->fog_hint);
        glshim_glGetIntegerv(GL_GENERATE_MIPMAP_HINT, &cur->mipmap_hint);
    }

    if (mask & GL_LIGHTING_BIT) {
        cur->lighting = glshim_glIsEnabled(GL_LIGHTING);
        glshim_glGetIntegerv(GL_LIGHT_MODEL_AMBIENT, cur->light_model_ambient);
        glshim_glGetIntegerv(GL_LIGHT_MODEL_TWO_SIDE, &cur->light_model_two_side);

        int i;
        GLint max_lights;
        glshim_glGetIntegerv(GL_MAX_LIGHTS, &max_lights);
        cur->lights_enabled = (GLboolean *)malloc(max_lights * sizeof(GLboolean));
        cur->lights = (GLfloat *)malloc(max_lights * sizeof(GLfloat));
        for (i = 0; i < max_lights; i++) {
            *(cur->lights_enabled + i) = glshim_glIsEnabled(GL_LIGHT0 + i);
            /* TODO: record all data about the lights
            glGetFloatv(GL_LIGHT0 + i, cur->lights + i);
            */
        }
        glshim_glGetIntegerv(GL_SHADE_MODEL, &cur->shade_model);
    }

    if (mask & GL_LINE_BIT) {
        cur->line_smooth = glshim_glIsEnabled(GL_LINE_SMOOTH);
        // TODO: stipple stuff here
        glshim_glGetFloatv(GL_LINE_WIDTH, &cur->line_width);
    }

	// GL_LIST_BIT
    if (mask & GL_LIST_BIT) {
        cur->list_base = glstate.list.base;
    }

    if (mask & GL_MULTISAMPLE_BIT) {
        cur->multisample = glshim_glIsEnabled(GL_MULTISAMPLE);
        cur->sample_alpha_to_coverage = glshim_glIsEnabled(GL_SAMPLE_ALPHA_TO_COVERAGE);
        cur->sample_alpha_to_one = glshim_glIsEnabled(GL_SAMPLE_ALPHA_TO_ONE);
        cur->sample_coverage = glshim_glIsEnabled(GL_SAMPLE_COVERAGE);
    }

    // GL_PIXEL_MODE_BIT
	if (mask & GL_PIXEL_MODE_BIT) {
		GLenum pixel_name[] = {GL_RED_BIAS, GL_RED_SCALE, GL_GREEN_BIAS, GL_GREEN_SCALE, GL_BLUE_BIAS, GL_BLUE_SCALE, GL_ALPHA_BIAS, GL_ALPHA_SCALE};
		int i;
		for (i=0; i<8; i++) 
			glshim_glGetFloatv(pixel_name[i], &cur->pixel_scale_bias[i]);
        //TODO: GL_DEPTH_BIAS & GL_DEPTH_SCALE (probably difficult)
        //TODO: GL_INDEX_OFFEST & GL_INDEX_SHIFT
        //TODO: GL_MAP_COLOR & GL_MAP_STENCIL (probably difficult too)
		glshim_glGetFloatv(GL_ZOOM_X, &cur->pixel_zoomx);
		glshim_glGetFloatv(GL_ZOOM_Y, &cur->pixel_zoomy);
	}
	
    if (mask & GL_POINT_BIT) {
        cur->point_smooth = glshim_glIsEnabled(GL_POINT_SMOOTH);
        glshim_glGetFloatv(GL_POINT_SIZE, &cur->point_size);
    }

    // TODO: GL_POLYGON_BIT
    // TODO: GL_POLYGON_STIPPLE_BIT

    if (mask & GL_SCISSOR_BIT) {
        cur->scissor_test = glshim_glIsEnabled(GL_SCISSOR_TEST);
        glshim_glGetFloatv(GL_SCISSOR_BOX, cur->scissor_box);
    }

    // TODO: GL_STENCIL_BUFFER_BIT
    if (mask & GL_STENCIL_BUFFER_BIT) {
        cur->stencil_test = glshim_glIsEnabled(GL_STENCIL_TEST);
        glshim_glGetIntegerv(GL_STENCIL_FUNC, &cur->stencil_func);
        glshim_glGetIntegerv(GL_STENCIL_VALUE_MASK, &cur->stencil_mask);
        glshim_glGetIntegerv(GL_STENCIL_REF, &cur->stencil_ref);
        //TODO: glStencilFuncSeperate
        
        //TODO: Stencil value mask
        glshim_glGetIntegerv(GL_STENCIL_FAIL, &cur->stencil_sfail);
        glshim_glGetIntegerv(GL_STENCIL_PASS_DEPTH_FAIL, &cur->stencil_dpfail);
        glshim_glGetIntegerv(GL_STENCIL_PASS_DEPTH_PASS, &cur->stencil_dppass);
        //TODO: glStencilOpSeparate

        glshim_glGetIntegerv(GL_STENCIL_CLEAR_VALUE, &cur->stencil_clearvalue);
        //TODO: Stencil buffer writemask
    }
    // GL_TEXTURE_BIT - TODO: incomplete
    if (mask & GL_TEXTURE_BIT) {
        cur->active=glstate.texture.active;
        int a;
        for (a=0; a<MAX_TEX; a++) {
            cur->texgen_r[a] = glstate.enable.texgen_r[a];
            cur->texgen_s[a] = glstate.enable.texgen_s[a];
            cur->texgen_t[a] = glstate.enable.texgen_t[a];
            cur->texgen[a] = glstate.texgen[a];   // all mode and planes per texture in 1 line
	        cur->texture[a] = (glstate.texture.bound[a])?glstate.texture.bound[a]->texture:0;
        }
        //glActiveTexture(GL_TEXTURE0+cur->active);
    }

    // GL_TRANSFORM_BIT
    if (mask & GL_TRANSFORM_BIT) {
		if (!(mask & GL_ENABLE_BIT)) {
			int i;
			GLint max_clip_planes;
			glshim_glGetIntegerv(GL_MAX_CLIP_PLANES, &max_clip_planes);
			cur->clip_planes_enabled = (GLboolean *)malloc(max_clip_planes * sizeof(GLboolean));
			for (i = 0; i < max_clip_planes; i++) {
				*(cur->clip_planes_enabled + i) = glshim_glIsEnabled(GL_CLIP_PLANE0 + i);
			}
		}
		glshim_glGetIntegerv(GL_MATRIX_MODE, &cur->matrix_mode);
		cur->rescale_normal_flag = glshim_glIsEnabled(GL_RESCALE_NORMAL);
		cur->normalize_flag = glshim_glIsEnabled(GL_NORMALIZE);
	}
    // GL_VIEWPORT_BIT
    if (mask & GL_VIEWPORT_BIT) {
		glshim_glGetIntegerv(GL_VIEWPORT, cur->viewport_size);
		glshim_glGetFloatv(GL_DEPTH_RANGE, cur->depth_range);
	}
		
    stack->len++;
}

void glshim_glPushClientAttrib(GLbitfield mask) {
    noerrorShim();
    if (clientStack == NULL) {
        clientStack = (glclientstack_t *)malloc(STACK_SIZE * sizeof(glclientstack_t));
        clientStack->len = 0;
        clientStack->cap = STACK_SIZE;
    } else if (clientStack->len == clientStack->cap) {
        clientStack->cap += STACK_SIZE;
        clientStack = (glclientstack_t *)realloc(clientStack, clientStack->cap * sizeof(glclientstack_t));
    }

    glclientstack_t *cur = clientStack + clientStack->len;
    cur->mask = mask;

    if (mask & GL_CLIENT_PIXEL_STORE_BIT) {
        glshim_glGetIntegerv(GL_PACK_ALIGNMENT, &cur->pack_align);
        glshim_glGetIntegerv(GL_UNPACK_ALIGNMENT, &cur->unpack_align);
        cur->unpack_row_length = glstate.texture.unpack_row_length;
        cur->unpack_skip_pixels = glstate.texture.unpack_skip_pixels;
        cur->unpack_skip_rows = glstate.texture.unpack_skip_rows;
        cur->pack_row_length = glstate.texture.pack_row_length;
        cur->pack_skip_pixels = glstate.texture.pack_skip_pixels;
        cur->pack_skip_rows = glstate.texture.pack_skip_rows;
    }

    if (mask & GL_CLIENT_VERTEX_ARRAY_BIT) {
        cur->vert_enable = glstate.vao->vertex_array;
        cur->color_enable = glstate.vao->color_array;
        cur->secondary_enable = glstate.vao->secondary_array;
        cur->normal_enable = glstate.vao->normal_array;
        int a;
        for (a=0; a<MAX_TEX; a++) {
           cur->tex_enable[a] = glstate.vao->tex_coord_array[a];
        }
        memcpy(&(cur->pointers), &glstate.vao->pointers, sizeof(pointer_states_t));
        cur->client = glstate.texture.client;
    }

    clientStack->len++;
}

#define maybe_free(x) \
    if (x) free(x)

#define enable_disable(pname, enabled) \
    if (enabled) glshim_glEnable(pname);      \
    else glshim_glDisable(pname)

#define v2(c) c[0], c[1]
#define v3(c) v2(c), c[2]
#define v4(c) v3(c), c[3]

void glshim_glPopAttrib() {
//printf("glPopAttrib()\n");
    noerrorShim();
    if ((glstate.list.compiling || glstate.gl_batch) && glstate.list.active) {
		NewStage(glstate.list.active, STAGE_POP);
		glstate.list.active->popattribute = true;
		return;
	}
    if (stack == NULL || stack->len == 0) {
        errorShim(GL_STACK_UNDERFLOW);
        return;
    }

    glstack_t *cur = stack + stack->len-1;

    if (cur->mask & GL_COLOR_BUFFER_BIT) {
        enable_disable(GL_ALPHA_TEST, cur->alpha_test);
        glshim_glAlphaFunc(cur->alpha_test_func, cur->alpha_test_ref);

        enable_disable(GL_BLEND, cur->blend);
        glshim_glBlendFunc(cur->blend_src_func, cur->blend_dst_func);

        enable_disable(GL_DITHER, cur->dither);
        enable_disable(GL_COLOR_LOGIC_OP, cur->color_logic_op);
        glshim_glLogicOp(cur->logic_op);

        GLfloat *c;
        glshim_glClearColor(v4(cur->clear_color));
        glshim_glColorMask(v4(cur->color_mask));
    }

    if (cur->mask & GL_CURRENT_BIT) {
        glshim_glColor4f(v4(cur->color));
        glshim_glNormal3f(v3(cur->normal));
        glshim_glTexCoord4f(v4(cur->tex));
    }

    if (cur->mask & GL_DEPTH_BUFFER_BIT) {
        enable_disable(GL_DEPTH_TEST, cur->depth_test);
        glshim_glDepthFunc(cur->depth_func);
        glshim_glClearDepth(cur->clear_depth);
        glshim_glDepthMask(cur->depth_mask);
    }

    if (cur->mask & GL_ENABLE_BIT) {
        int i;

        enable_disable(GL_ALPHA_TEST, cur->alpha_test);
        enable_disable(GL_AUTO_NORMAL, cur->autonormal);
        enable_disable(GL_BLEND, cur->blend);

        GLint max_clip_planes;
        glshim_glGetIntegerv(GL_MAX_CLIP_PLANES, &max_clip_planes);
        for (i = 0; i < max_clip_planes; i++) {
            enable_disable(GL_CLIP_PLANE0 + i, *(cur->clip_planes_enabled + i));
        }

        enable_disable(GL_COLOR_MATERIAL, cur->colormaterial);
        enable_disable(GL_CULL_FACE, cur->cull_face);
        enable_disable(GL_DEPTH_TEST, cur->depth_test);
        enable_disable(GL_DITHER, cur->dither);
        enable_disable(GL_FOG, cur->fog);

        GLint max_lights;
        glshim_glGetIntegerv(GL_MAX_LIGHTS, &max_lights);
        for (i = 0; i < max_lights; i++) {
            enable_disable(GL_LIGHT0 + i, *(cur->lights_enabled + i));
        }

        enable_disable(GL_LIGHTING, cur->lighting);
        enable_disable(GL_LINE_SMOOTH, cur->line_smooth);
        enable_disable(GL_LINE_STIPPLE, cur->line_stipple);
        enable_disable(GL_COLOR_LOGIC_OP, cur->color_logic_op);
        //TODO: GL_INDEX_LOGIC_OP
        //TODO: GL_MAP1_x
        //TODO: GL_MAP2_x
        enable_disable(GL_MULTISAMPLE, cur->multisample);
        enable_disable(GL_NORMALIZE, cur->normalize);
        enable_disable(GL_POINT_SMOOTH, cur->point_smooth);
        //TODO: GL_POLYGON_OFFSET_LINE
        enable_disable(GL_POLYGON_OFFSET_FILL, cur->polygon_offset_fill);
        //TODO: GL_POLYGON_OFFSET_POINT
        //TODO: GL_POLYGON_SMOOTH
        //TODO: GL_POLYGON_STIPPLE
        enable_disable(GL_SAMPLE_ALPHA_TO_COVERAGE, cur->sample_alpha_to_coverage);
        enable_disable(GL_SAMPLE_ALPHA_TO_ONE, cur->sample_alpha_to_one);
        enable_disable(GL_SAMPLE_COVERAGE, cur->sample_coverage);
        enable_disable(GL_SCISSOR_TEST, cur->scissor_test);
        enable_disable(GL_STENCIL_TEST, cur->stencil_test);
        int a;
        int old_tex = glstate.texture.active;
        for (a=0; a<MAX_TEX; a++) {
			if (glstate.enable.texture_1d[a] != cur->texture_1d[a]) {
				glshim_glActiveTexture(GL_TEXTURE0+a);
				enable_disable(GL_TEXTURE_1D, cur->texture_1d[a]);
			}
			if (glstate.enable.texture_2d[a] != cur->texture_2d[a]) {
				glshim_glActiveTexture(GL_TEXTURE0+a);
				enable_disable(GL_TEXTURE_2D, cur->texture_2d[a]);
			}
			if (glstate.enable.texture_3d[a] != cur->texture_3d[a]) {
				glshim_glActiveTexture(GL_TEXTURE0+a);
				enable_disable(GL_TEXTURE_3D, cur->texture_3d[a]);
			}
            glstate.enable.texgen_r[a] = cur->texgen_r[a];
            glstate.enable.texgen_s[a] = cur->texgen_s[a];
            glstate.enable.texgen_t[a] = cur->texgen_t[a];
         }
         if (glstate.texture.active != old_tex) glshim_glActiveTexture(GL_TEXTURE0+old_tex);
    }

    if (cur->mask & GL_FOG_BIT) {
        enable_disable(GL_FOG, cur->fog);
        glshim_glFogfv(GL_FOG_COLOR, cur->fog_color);
        glshim_glFogf(GL_FOG_DENSITY, cur->fog_density);
        glshim_glFogf(GL_FOG_START, cur->fog_start);
        glshim_glFogf(GL_FOG_END, cur->fog_end);
        glshim_glFogf(GL_FOG_MODE, cur->fog_mode);
    }

    if (cur->mask & GL_HINT_BIT) {
        enable_disable(GL_PERSPECTIVE_CORRECTION_HINT, cur->perspective_hint);
        enable_disable(GL_POINT_SMOOTH_HINT, cur->point_smooth_hint);
        enable_disable(GL_LINE_SMOOTH_HINT, cur->line_smooth_hint);
        enable_disable(GL_FOG_HINT, cur->fog_hint);
        enable_disable(GL_GENERATE_MIPMAP_HINT, cur->mipmap_hint);
    }
	// GL_LIST_BIT
    if (cur->mask & GL_LIST_BIT) {
        glshim_glListBase(cur->list_base);
    }

    if (cur->mask & GL_LINE_BIT) {
        enable_disable(GL_LINE_SMOOTH, cur->line_smooth);
        // TODO: stipple stuff here
        glshim_glLineWidth(cur->line_width);
    }

    if (cur->mask & GL_MULTISAMPLE_BIT) {
        enable_disable(GL_MULTISAMPLE, cur->multisample);
        enable_disable(GL_SAMPLE_ALPHA_TO_COVERAGE, cur->sample_alpha_to_coverage);
        enable_disable(GL_SAMPLE_ALPHA_TO_ONE, cur->sample_alpha_to_one);
        enable_disable(GL_SAMPLE_COVERAGE, cur->sample_coverage);
    }

    if (cur->mask & GL_POINT_BIT) {
        enable_disable(GL_POINT_SMOOTH, cur->point_smooth);
        glshim_glPointSize(cur->point_size);
    }

    if (cur->mask & GL_SCISSOR_BIT) {
        enable_disable(GL_SCISSOR_TEST, cur->scissor_test);
        glshim_glScissor(v4(cur->scissor_box));
    }

    if (cur->mask & GL_STENCIL_BUFFER_BIT) {
        enable_disable(GL_STENCIL_TEST, cur->stencil_test);
        glshim_glStencilFunc(cur->stencil_func, cur->stencil_ref, cur->stencil_mask);
        //TODO: Stencil value mask
        glshim_glStencilOp(cur->stencil_sfail, cur->stencil_dpfail, cur->stencil_dppass);
        glshim_glClearStencil(cur->stencil_clearvalue);
        //TODO: Stencil buffer writemask
    }

    if (cur->mask & GL_TEXTURE_BIT) {
        int a;
        //TODO: Enable bit for the 4 texture coordinates
        for (a=0; a<MAX_TEX; a++) {
            glstate.enable.texgen_r[a] = cur->texgen_r[a];
            glstate.enable.texgen_s[a] = cur->texgen_s[a];
            glstate.enable.texgen_t[a] = cur->texgen_t[a];
            glstate.texgen[a] = cur->texgen[a];   // all mode and planes per texture in 1 line
			if ((cur->texture[a]==0 && glstate.texture.bound[a] != 0) || (cur->texture[a]!=0 && glstate.texture.bound[a]==0)) {
			   glshim_glActiveTexture(GL_TEXTURE0+a);
			   glshim_glBindTexture(GL_TEXTURE_2D, cur->texture[a]);
			}
        }
        if (glstate.texture.active!= cur->active) glshim_glActiveTexture(GL_TEXTURE0+cur->active);
    }
    
	if (cur->mask & GL_PIXEL_MODE_BIT) {
		GLenum pixel_name[] = {GL_RED_BIAS, GL_RED_SCALE, GL_GREEN_BIAS, GL_GREEN_SCALE, GL_BLUE_BIAS, GL_BLUE_SCALE, GL_ALPHA_BIAS, GL_ALPHA_SCALE};
		int i;
		for (i=0; i<8; i++) 
			glshim_glPixelTransferf(pixel_name[i], cur->pixel_scale_bias[i]);
        //TODO: GL_DEPTH_BIAS & GL_DEPTH_SCALE (probably difficult)
        //TODO: GL_INDEX_OFFEST & GL_INDEX_SHIFT
        //TODO: GL_MAP_COLOR & GL_MAP_STENCIL (probably difficult too)
		glshim_glPixelZoom(cur->pixel_zoomx, cur->pixel_zoomy);
	}

	if (cur->mask & GL_TRANSFORM_BIT) {
		if (!(cur->mask & GL_ENABLE_BIT)) {
			int i;
			GLint max_clip_planes;
			glshim_glGetIntegerv(GL_MAX_CLIP_PLANES, &max_clip_planes);
			for (i = 0; i < max_clip_planes; i++) {
				enable_disable(GL_CLIP_PLANE0 + i, *(cur->clip_planes_enabled + i));
			}
		}
		glshim_glMatrixMode(cur->matrix_mode);
		enable_disable(GL_NORMALIZE, cur->normalize_flag);		
		enable_disable(GL_RESCALE_NORMAL, cur->rescale_normal_flag);		
	}

    if (cur->mask & GL_VIEWPORT_BIT) {
		glshim_glViewport(cur->viewport_size[0], cur->viewport_size[1], cur->viewport_size[2], cur->viewport_size[3]);
		glshim_glDepthRangef(cur->depth_range[0], cur->depth_range[1]);
	}
	
    maybe_free(cur->clip_planes_enabled);
    maybe_free(cur->clip_planes);
    maybe_free(cur->lights_enabled);
    maybe_free(cur->lights);
    stack->len--;
}

#undef enable_disable
#define enable_disable(pname, enabled)             \
    if (enabled) glshim_glEnableClientState(pname);       \
    else glshim_glDisableClientState(pname)

void glshim_glPopClientAttrib() {
    noerrorShim();
	//LOAD_GLES(glVertexPointer);
	//LOAD_GLES(glColorPointer);
	//LOAD_GLES(glNormalPointer);
	//LOAD_GLES(glTexCoordPointer);

    if (clientStack == NULL || clientStack->len == 0) {
        errorShim(GL_STACK_UNDERFLOW);
        return;
    }

    glclientstack_t *cur = clientStack + clientStack->len-1;
    if (cur->mask & GL_CLIENT_PIXEL_STORE_BIT) {
        glshim_glPixelStorei(GL_PACK_ALIGNMENT, cur->pack_align);
        glshim_glPixelStorei(GL_UNPACK_ALIGNMENT, cur->unpack_align);
        glshim_glPixelStorei(GL_UNPACK_ROW_LENGTH, cur->unpack_row_length);
        glshim_glPixelStorei(GL_UNPACK_SKIP_PIXELS, cur->unpack_skip_pixels);
        glshim_glPixelStorei(GL_UNPACK_SKIP_ROWS, cur->unpack_skip_rows);
        glshim_glPixelStorei(GL_PACK_ROW_LENGTH, cur->pack_row_length);
        glshim_glPixelStorei(GL_PACK_SKIP_PIXELS, cur->pack_skip_pixels);
        glshim_glPixelStorei(GL_PACK_SKIP_ROWS, cur->pack_skip_rows);
    }

    if (cur->mask & GL_CLIENT_VERTEX_ARRAY_BIT) {
		if (glstate.vao->vertex_array != cur->vert_enable)
			enable_disable(GL_VERTEX_ARRAY, cur->vert_enable);
		if (glstate.vao->normal_array != cur->normal_enable)
			enable_disable(GL_NORMAL_ARRAY, cur->normal_enable);
		if (glstate.vao->color_array != cur->color_enable)
			enable_disable(GL_COLOR_ARRAY, cur->color_enable);
		if (glstate.vao->secondary_array != cur->secondary_enable)
			enable_disable(GL_SECONDARY_COLOR_ARRAY, cur->secondary_enable);
        for (int a=0; a<MAX_TEX; a++) {
		   if (glstate.vao->tex_coord_array[a] != cur->tex_enable[a]) {
			   glshim_glClientActiveTexture(GL_TEXTURE0+a);
			   enable_disable(GL_TEXTURE_COORD_ARRAY, cur->tex_enable[a]);
		   }
        }

        memcpy(&glstate.vao->pointers, &(cur->pointers), sizeof(pointer_states_t));
		if (glstate.texture.client != cur->client) glshim_glClientActiveTexture(GL_TEXTURE0+cur->client);
    }

    clientStack->len--;
}

#undef maybe_free
#undef enable_disable
#undef v2
#undef v3
#undef v4

//Direct wrapper
void glPushClientAttrib(GLbitfield mask) __attribute__((alias("glshim_glPushClientAttrib")));
void glPopClientAttrib() __attribute__((alias("glshim_glPopClientAttrib")));
void glPushAttrib(GLbitfield mask) __attribute__((alias("glshim_glPushAttrib")));
void glPopAttrib() __attribute__((alias("glshim_glPopAttrib")));