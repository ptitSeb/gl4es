#include "gl.h"

glstate_t state = {.color = {1.0f, 1.0f, 1.0f, 1.0f},
	.render_mode = 0,
	.projection_matrix = NULL,
	.modelview_matrix = NULL,
	.texture_matrix = NULL,
	.namestack = {0, NULL}
	};
	
void* gles = NULL;

// config functions
const GLubyte *glGetString(GLenum name) {
    LOAD_GLES(glGetString);
	if (gles_glGetString(name)==NULL)
		printf("**warning** glGetString(%i) called with bad init\n", name);
    switch (name) {
        case GL_VERSION:
#ifdef USE_ES2
            return (GLubyte *)"4.3 glshim wrapper";
#else
            return (GLubyte *)"1.4 glshim wrapper";
#endif
        case GL_EXTENSIONS:
            return (const GLubyte *)(char *){
#ifndef USE_ES2
//                "GL_ARB_vertex_buffer_object "
                "GL_ARB_vertex_buffer "
                "GL_EXT_vertex_array "
//                "GL_EXT_secondary_color "
                "GL_EXT_texture_env_combine "
                "GL_ARB_multitexture "
                "GL_ARB_texture_env_add "
//                "GL_ARB_texture_cube_map "
                "GL_ARB_texture_border_clamp "
                "GL_ARB_point_parameters "
                "GL_ARB_texture_env_combine "
                "GL_ARB_texture_env_crossbar "
                "GL_ARB_texture_env_dot3 "
                "GL_ARB_texture_mirrored_repeat "
                "GL_EXT_blend_color "
                "GL_SGIS_generate_mipmap "
                "GL_EXT_blend_subtract "
                "GL_EXT_blend_logic_op "
                "GL_EXT_blend_func_separate "
                "GL_EXT_packed_depth_stencil "
                "GL_EXT_draw_range_elements "
                "GL_EXT_bgra "
                "GL_ARB_texture_compression "
                "GL_EXT_texture_compression_s3tc "
//                "GL_EXT_stencil_wrap "
#else
                "GL_ARB_vertex_shader "
                "GL_ARB_fragment_shader "
                "GL_ARB_vertex_buffer_object "
                "GL_EXT_framebuffer_object "
                "GL_EXT_vertex_array "
#endif
            };
		case GL_VENDOR:
			return (GLubyte *)"OpenPandora";
		case GL_RENDERER:
#ifdef USE_ES2
			return (GLubyte *)"GLESv2 wrapper";
#else
			return (GLubyte *)"GLES_CM wrapper";
#endif
        default:
            return gles_glGetString(name);
    }
}

// glGet
extern float zoomx, zoomy;
extern GLfloat raster_scale[4];
extern GLfloat raster_bias[4];

void glGetIntegerv(GLenum pname, GLint *params) {
	GLint dummy;
    LOAD_GLES(glGetIntegerv);
    switch (pname) {
        case GL_MAX_ELEMENTS_INDICES:
            *params = 1024;
            break;
        case GL_MAX_ELEMENTS_VERTICES:
			*params = 4096;
			break;
        case GL_AUX_BUFFERS:
            *params = 0;
            break;
        case GL_UNPACK_ROW_LENGTH:	
			*params = state.texture.unpack_row_length;
			break;
        case GL_UNPACK_SKIP_PIXELS:
			*params = state.texture.unpack_skip_pixels;
			break;
        case GL_UNPACK_SKIP_ROWS:
			*params = state.texture.unpack_skip_rows;
			break;
        case GL_UNPACK_LSB_FIRST:
			*params = state.texture.unpack_lsb_first;
			break;
        case GL_PACK_ROW_LENGTH:	
			*params = state.texture.pack_row_length;
			break;
        case GL_PACK_SKIP_PIXELS:
			*params = state.texture.pack_skip_pixels;
			break;
        case GL_PACK_SKIP_ROWS:
			*params = state.texture.pack_skip_rows;
			break;
        case GL_PACK_LSB_FIRST:
			*params = state.texture.pack_lsb_first;
			break;
		case GL_POINT_SIZE_RANGE:
			gles_glGetIntegerv(GL_POINT_SIZE_MIN, params);
			gles_glGetIntegerv(GL_POINT_SIZE_MAX, params+1);
			break;
		case GL_RENDER_MODE:
			*params = (state.render_mode)?state.render_mode:GL_RENDER;
			break;
		case GL_NAME_STACK_DEPTH:
			*params = state.namestack.top;
			break;
		case GL_MAX_NAME_STACK_DEPTH:
			*params = 1024;
			break;
		case GL_MAX_TEXTURE_IMAGE_UNITS:
			/*gles_glGetIntegerv(GL_MAX_TEXTURE_UNITS, params);*/
			*params = 4;
			break;
		case GL_NUM_COMPRESSED_TEXTURE_FORMATS:
			gles_glGetIntegerv(GL_NUM_COMPRESSED_TEXTURE_FORMATS, params);
			(*params)+=4;	// adding fake DXTc
			break;
		case GL_COMPRESSED_TEXTURE_FORMATS:
			gles_glGetIntegerv(GL_NUM_COMPRESSED_TEXTURE_FORMATS, &dummy);
			// get standard ones
			gles_glGetIntegerv(GL_COMPRESSED_TEXTURE_FORMATS, params);
			// add fake DXTc
			params[dummy++]=COMPRESSED_RGB_S3TC_DXT1_EXT;
			params[dummy++]=COMPRESSED_RGBA_S3TC_DXT1_EXT;
			params[dummy++]=COMPRESSED_RGBA_S3TC_DXT3_EXT;
			params[dummy++]=COMPRESSED_RGBA_S3TC_DXT5_EXT;
			break;
		case GL_MAX_MODELVIEW_STACK_DEPTH:
			*params=MAX_STACK_MODELVIEW;
			break;
		case GL_MAX_PROJECTION_STACK_DEPTH:
			*params=MAX_STACK_PROJECTION;
			break;
		case GL_MAX_TEXTURE_STACK_DEPTH:
			*params=MAX_STACK_TEXTURE;
			break;
		case GL_MODELVIEW_STACK_DEPTH:
			*params=(state.modelview_matrix)?1:(state.modelview_matrix->top+1);
			break;
		case GL_PROJECTION_STACK_DEPTH:
			*params=(state.projection_matrix)?1:(state.projection_matrix->top+1);
			break;
		case GL_TEXTURE_STACK_DEPTH:
			*params=(state.texture_matrix)?1:(state.texture_matrix[state.texture.active]->top+1);
			break;
        default:
            gles_glGetIntegerv(pname, params);
    }
}

void glGetFloatv(GLenum pname, GLfloat *params) {
    LOAD_GLES(glGetFloatv);
    switch (pname) {
        case GL_MAX_ELEMENTS_INDICES:
            *params = 1024;
            break;
        case GL_MAX_ELEMENTS_VERTICES:
			*params = 4096;
			break;
        case GL_AUX_BUFFERS:
            *params = 0;
            break;
        case GL_UNPACK_ROW_LENGTH:	
			*params = state.texture.unpack_row_length;
			break;
        case GL_UNPACK_SKIP_PIXELS:
			*params = state.texture.unpack_skip_pixels;
			break;
        case GL_UNPACK_SKIP_ROWS:
			*params = state.texture.unpack_skip_rows;
			break;
        case GL_UNPACK_LSB_FIRST:
			*params = state.texture.unpack_lsb_first;
			break;
        case GL_PACK_ROW_LENGTH:	
			*params = state.texture.pack_row_length;
			break;
        case GL_PACK_SKIP_PIXELS:
			*params = state.texture.pack_skip_pixels;
			break;
        case GL_PACK_SKIP_ROWS:
			*params = state.texture.pack_skip_rows;
			break;
        case GL_PACK_LSB_FIRST:
			*params = state.texture.pack_lsb_first;
			break;
        case GL_ZOOM_X:
			*params = zoomx;
			break;
        case GL_ZOOM_Y:
			*params = zoomy;
			break;
        case GL_RED_SCALE:
			*params = raster_scale[0];
			break;
        case GL_RED_BIAS:
			*params = raster_bias[0];
			break;
        case GL_GREEN_SCALE:
        case GL_BLUE_SCALE:
        case GL_ALPHA_SCALE:
			*params = raster_scale[(pname-GL_GREEN_SCALE)/2+1];
			break;
        case GL_GREEN_BIAS:
        case GL_BLUE_BIAS:
        case GL_ALPHA_BIAS:
			*params = raster_bias[(pname-GL_GREEN_BIAS)/2+1];
			break;
		case GL_POINT_SIZE_RANGE:
			gles_glGetFloatv(GL_POINT_SIZE_MIN, params);
			gles_glGetFloatv(GL_POINT_SIZE_MAX, params+1);
			break;
		case GL_RENDER_MODE:
			*params = (state.render_mode)?state.render_mode:GL_RENDER;
			break;
		case GL_NAME_STACK_DEPTH:
			*params = state.namestack.top;
			break;
		case GL_MAX_NAME_STACK_DEPTH:
			*params = 1024;
			break;
		case GL_MAX_MODELVIEW_STACK_DEPTH:
			*params=MAX_STACK_MODELVIEW;
			break;
		case GL_MAX_PROJECTION_STACK_DEPTH:
			*params=MAX_STACK_PROJECTION;
			break;
		case GL_MAX_TEXTURE_STACK_DEPTH:
			*params=MAX_STACK_TEXTURE;
			break;
		case GL_MODELVIEW_STACK_DEPTH:
			*params=(state.modelview_matrix)?1:(state.modelview_matrix->top+1);
			break;
		case GL_PROJECTION_STACK_DEPTH:
			*params=(state.projection_matrix)?1:(state.projection_matrix->top+1);
			break;
		case GL_TEXTURE_STACK_DEPTH:
			*params=(state.texture_matrix)?1:(state.texture_matrix[state.texture.active]->top+1);
			break;
        default:
            gles_glGetFloatv(pname, params);
    }
}

static void proxy_glEnable(GLenum cap, bool enable, void (*next)(GLenum)) {
    #define proxy_enable(constant, name) \
        case constant: state.enable.name = enable; next(cap); break
    #define enable(constant, name) \
        case constant: state.enable.name = enable; break;

    // TODO: maybe could be weird behavior if someone tried to:
    // 1. enable GL_TEXTURE_1D
    // 2. enable GL_TEXTURE_2D
    // 3. disable GL_TEXTURE_1D
    // 4. render. GL_TEXTURE_2D would be disabled.
    cap = map_tex_target(cap);

    switch (cap) {
        proxy_enable(GL_BLEND, blend);
        proxy_enable(GL_TEXTURE_2D, texture_2d[state.texture.active]);
        enable(GL_TEXTURE_GEN_S, texgen_s[state.texture.active]);
        enable(GL_TEXTURE_GEN_T, texgen_t[state.texture.active]);
        enable(GL_TEXTURE_GEN_R, texgen_r[state.texture.active]);
        enable(GL_LINE_STIPPLE, line_stipple);

        // for glDrawArrays
        proxy_enable(GL_VERTEX_ARRAY, vertex_array);
        proxy_enable(GL_NORMAL_ARRAY, normal_array);
        proxy_enable(GL_COLOR_ARRAY, color_array);
        proxy_enable(GL_TEXTURE_COORD_ARRAY, tex_coord_array[state.texture.client]);
        default: next(cap); break;
    }
    #undef proxy_enable
    #undef enable
}

void glEnable(GLenum cap) {
    if (state.list.compiling && state.list.active) {
		NewStage(state.list.active, STAGE_GLCALL);
/*		if ((cap == GL_TEXTURE_2D) || (cap == GL_TEXTURE_GEN_S) || (cap == GL_TEXTURE_GEN_T) || (cap == GL_TEXTURE_GEN_R))
			state.list.active = extend_renderlist(state.list.active);*/
        push_glEnable(cap);
    } else {
        LOAD_GLES(glEnable);
        proxy_glEnable(cap, true, gles_glEnable);
    }

}

void glDisable(GLenum cap) {
    if (state.list.compiling && state.list.active) {
		NewStage(state.list.active, STAGE_GLCALL);
/*		if ((cap == GL_TEXTURE_2D) || (cap == GL_TEXTURE_GEN_S) || (cap == GL_TEXTURE_GEN_T) || (cap == GL_TEXTURE_GEN_R))
			state.list.active = extend_renderlist(state.list.active);*/
        push_glDisable(cap);
    } else {
        LOAD_GLES(glDisable);
        proxy_glEnable(cap, false, gles_glDisable);
    }
}

#ifndef USE_ES2
void glEnableClientState(GLenum cap) {
    LOAD_GLES(glEnableClientState);
    proxy_glEnable(cap, true, gles_glEnableClientState);
}

void glDisableClientState(GLenum cap) {
    LOAD_GLES(glDisableClientState);
    proxy_glEnable(cap, false, gles_glDisableClientState);
}
#endif

GLboolean glIsEnabled(GLenum cap) {
    LOAD_GLES(glIsEnabled);
    switch (cap) {
        case GL_LINE_STIPPLE:
            return state.enable.line_stipple;
        case GL_TEXTURE_GEN_S:
            return state.enable.texgen_s[state.texture.active];
        case GL_TEXTURE_GEN_T:
            return state.enable.texgen_t[state.texture.active];
        case GL_TEXTURE_GEN_R:
            return state.enable.texgen_t[state.texture.active];
		case GL_TEXTURE_COORD_ARRAY:
			return state.enable.tex_coord_array[state.texture.client];
        default:
            return gles_glIsEnabled(cap);
    }
}

static renderlist_t *arrays_to_renderlist(renderlist_t *list, GLenum mode,
                                        GLsizei skip, GLsizei count) {
    if (! list)
        list = alloc_renderlist();
//if (state.list.compiling) printf("arrary_to_renderlist while compiling list\n");
    list->mode = mode;
    list->mode_init = mode;
    list->len = count-skip;
    list->cap = count-skip;
    
	if (state.enable.vertex_array) {
		list->vert = copy_gl_pointer(&state.pointers.vertex, 3, skip, count);
	}
	if (state.enable.color_array) {
		list->color = copy_gl_pointer(&state.pointers.color, 4, skip, count);
	}
	if (state.enable.normal_array) {
		list->normal = copy_gl_pointer(&state.pointers.normal, 3, skip, count);
	}
	for (int i=0; i<MAX_TEX; i++) {
		if (state.enable.tex_coord_array[i]) {
		list->tex[i] = copy_gl_pointer(&state.pointers.tex_coord[i], 2, skip, count);
		}
	}
	
    end_renderlist(list);
    return list;
}

static inline bool should_intercept_render(GLenum mode) {
    return (
        (state.enable.vertex_array && ! valid_vertex_type(state.pointers.vertex.type)) ||
        (state.enable.texture_2d[0] && (state.enable.texgen_s[0] || state.enable.texgen_t[0] || state.enable.texgen_r[0])) ||
        (state.enable.texture_2d[1] && (state.enable.texgen_s[1] || state.enable.texgen_t[1] || state.enable.texgen_r[1])) ||
        (state.enable.texture_2d[2] && (state.enable.texgen_s[2] || state.enable.texgen_t[2] || state.enable.texgen_r[2])) ||
        (state.enable.texture_2d[3] && (state.enable.texgen_s[3] || state.enable.texgen_t[3] || state.enable.texgen_r[3])) ||
        (mode == GL_LINES && state.enable.line_stipple) ||
        (mode == GL_QUADS) || (state.list.active && state.list.compiling)
    );
}

void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *uindices) {
    // TODO: split for count > 65535?
    GLushort *indices = copy_gl_array(uindices, type, 1, 0, GL_UNSIGNED_SHORT, 1, 0, count);
    // TODO: do this in a more direct fashion.
    if (should_intercept_render(mode)) {
        glBegin(mode);
        for (int i = 0; i < count; i++) {
            glArrayElement(indices[i]);
        }
        glEnd();
        free(indices);
        return;
    }
    bool compiling = (state.list.active && state.list.compiling);
    if (compiling) {
        renderlist_t *list = NULL;
        GLsizei min, max;

		NewStage(state.list.active, STAGE_DRAW);
        list = state.list.active;/* = extend_renderlist(state.list.active);*/

        normalize_indices(indices, &max, &min, count);
        list = arrays_to_renderlist(list, mode, min, max + 1 +min);
        end_renderlist(list);
        //state.list.active = extend_renderlist(state.list.active);
    } else {
		LOAD_GLES(glDrawElements);
		GLenum mode_init = mode;
		if (state.polygon_mode == GL_LINE && mode>=GL_TRIANGLES)
			mode = GL_LINE_LOOP;
		if (state.polygon_mode == GL_POINT && mode>=GL_TRIANGLES)
			mode = GL_POINTS;

		if (mode == GL_QUAD_STRIP)
			mode = GL_TRIANGLE_STRIP;
		if (mode == GL_POLYGON)
			mode = GL_TRIANGLE_FAN;
		if (state.render_mode == GL_SELECT) {
			select_glDrawElements(mode, count, GL_UNSIGNED_SHORT, indices);
		} else {
			if (state.polygon_mode == GL_LINE && mode_init>=GL_TRIANGLES) {
				int n, s;
				switch (mode_init) {
					case GL_TRIANGLES:
						n = 3;
						s = 3;
						break;
					case GL_TRIANGLE_STRIP:
						n = 3;
						s = 1;
						break;
					case GL_TRIANGLE_FAN:	// wrong here...
						n = count;
						s = count;
						break;
					case GL_QUADS:
						n = 4;
						s = 4;
						break;
					case GL_QUAD_STRIP:
						n = 4;
						s = 1;
						break;
					default:		// Polygon and other?
						n = count;
						s = count;
						break;
				}
				for (int i=n; i<count; i+=s)
					gles_glDrawElements(mode, n, GL_UNSIGNED_SHORT, indices+i-n);
			} else
				gles_glDrawElements(mode, count, GL_UNSIGNED_SHORT, indices);
		}
        free(indices);
    }
}

void glDrawArrays(GLenum mode, GLint first, GLsizei count) {
    renderlist_t *list, *active = state.list.active;
    if (active && state.list.compiling) {
		NewStage(state.list.active, STAGE_DRAW);
        list = state.list.active;/* = extend_renderlist(active);*/
        arrays_to_renderlist(list, mode, first, count+first);
        return;
    }

    if (state.polygon_mode == GL_LINE && mode>=GL_TRIANGLES)
		mode = GL_LINE_LOOP;
    if (state.polygon_mode == GL_POINT && mode>=GL_TRIANGLES)
		mode = GL_POINTS;

    if (should_intercept_render(mode)) {
        list = arrays_to_renderlist(NULL, mode, first, count+first);
        end_renderlist(list);
        draw_renderlist(list);
        free_renderlist(list);
    } else {
        // TODO: some draw states require us to use the full pipeline here
        // like texgen, stipple, npot
        LOAD_GLES(glDrawArrays);

		GLenum mode_init = mode;
		if (mode == GL_QUAD_STRIP)
			mode = GL_TRIANGLE_STRIP;
		if (mode == GL_POLYGON)
			mode = GL_TRIANGLE_FAN;

		if (state.render_mode == GL_SELECT) {
			select_glDrawArrays(mode, first, count);
		} else {
			if (state.polygon_mode == GL_LINE && mode_init>=GL_TRIANGLES) {
				int n, s;
				switch (mode_init) {
					case GL_TRIANGLES:
						n = 3;
						s = 3;
						break;
					case GL_TRIANGLE_STRIP:
						n = 3;
						s = 1;
						break;
					case GL_TRIANGLE_FAN:	// wrong here...
						n = count;
						s = count;
						break;
					case GL_QUADS:
						n = 4;
						s = 4;
						break;
					case GL_QUAD_STRIP:
						n = 4;
						s = 1;
						break;
					default:		// Polygon and other?
						n = count;
						s = count;
						break;
				}
				for (int i=n; i<count; i+=s)
					gles_glDrawArrays(mode, i-n, n);
			} else
				gles_glDrawArrays(mode, first, count);
		}
    }
}

#ifndef USE_ES2
#define clone_gl_pointer(t, s)\
    t.size = s; t.type = type; t.stride = stride; t.pointer = pointer;
void glVertexPointer(GLint size, GLenum type,
                     GLsizei stride, const GLvoid *pointer) {
    LOAD_GLES(glVertexPointer);
	clone_gl_pointer(state.pointers.vertex, size);
    glGetError();
    gles_glVertexPointer(size, type, stride, pointer);
}
void glColorPointer(GLint size, GLenum type,
                     GLsizei stride, const GLvoid *pointer) {
    LOAD_GLES(glColorPointer);
    clone_gl_pointer(state.pointers.color, size);
    gles_glColorPointer(size, type, stride, pointer);
}
void glNormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer) {
    LOAD_GLES(glNormalPointer);
    clone_gl_pointer(state.pointers.normal, 3);
    gles_glNormalPointer(type, stride, pointer);
}
void glTexCoordPointer(GLint size, GLenum type,
                     GLsizei stride, const GLvoid *pointer) {
    LOAD_GLES(glTexCoordPointer);
    clone_gl_pointer(state.pointers.tex_coord[state.texture.client], size);
    gles_glTexCoordPointer(size, type, stride, pointer);
}
#undef clone_gl_pointer
#endif

void glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid *pointer) {
    uintptr_t ptr = (uintptr_t)pointer;
    // element lengths
    GLsizei tex=0, color=0, normal=0, vert=0;
    // element formats
    GLenum tf, cf, nf, vf;
    tf = cf = nf = vf = GL_FLOAT;

    switch (format) {
        GL_V2F: vert = 2; break;
        GL_V3F: vert = 3; break;
        GL_C4UB_V2F:
            color = 4; cf = GL_UNSIGNED_BYTE;
            vert = 2;
            break;
        GL_C4UB_V3F:
            color = 4; cf = GL_UNSIGNED_BYTE;
            vert = 3;
            break;
        GL_C3F_V3F:
            color = 3;
            vert = 4;
            break;
        GL_N3F_V3F:
            normal = 3;
            vert = 3;
            break;
        GL_C4F_N3F_V3F:
            color = 4;
            normal = 3;
            vert = 3;
            break;
        GL_T2F_V3F:
            tex = 2;
            vert = 3;
            break;
        GL_T4F_V4F:
            tex = 4;
            vert = 4;
            break;
        GL_T2F_C4UB_V3F:
            tex = 2;
            color = 4; cf = GL_UNSIGNED_BYTE;
            vert = 3;
            break;
        GL_T2F_C3F_V3F:
            tex = 2;
            color = 3;
            vert = 3;
            break;
        GL_T2F_N3F_V3F:
            tex = 2;
            normal = 3;
            vert = 3;
            break;
        GL_T2F_C4F_N3F_V3F:
            tex = 2;
            color = 4;
            normal = 3;
            vert = 3;
            break;
        GL_T4F_C4F_N3F_V4F:
            tex = 4;
            color = 4;
            normal = 3;
            vert = 4;
            break;
    }
    if (! stride)
        stride = tex * gl_sizeof(tf) +
                 color * gl_sizeof(cf) +
                 normal * gl_sizeof(nf) +
                 vert * gl_sizeof(vf);
    if (tex) {
        glTexCoordPointer(tex, tf, stride, (GLvoid *)ptr);
        ptr += tex * gl_sizeof(tf);
    }
    if (color) {
        glColorPointer(color, cf, stride, (GLvoid *)ptr);
        ptr += color * gl_sizeof(cf);
    }
    if (normal) {
        glNormalPointer(nf, stride, (GLvoid *)ptr);
        ptr += normal * gl_sizeof(nf);
    }
    if (vert)
        glVertexPointer(vert, vf, stride, (GLvoid *)ptr);
}

// immediate mode functions
void glBegin(GLenum mode) {
    if (! state.list.active) {
        state.list.active = alloc_renderlist();
    }/* else*/ {
		// create a new list, as we are already inside one
		NewStage(state.list.active, STAGE_DRAW);
//		state.list.active = extend_renderlist(state.list.active);
	}
    state.list.active->mode = mode;
    state.list.active->mode_init = mode;
}

void glEnd() {
    if (! state.list.active) return;
    // render if we're not in a display list
    if (! state.list.compiling) {
		renderlist_t *mylist = state.list.active;
        state.list.active = NULL;
        end_renderlist(mylist);
        draw_renderlist(mylist);
        free_renderlist(mylist);
    } else {
        state.list.active = extend_renderlist(state.list.active);
    }
}

void glNormal3f(GLfloat x, GLfloat y, GLfloat z) {
    if (state.list.active) {
        rlNormal3f(state.list.active, x, y, z);
    }
#ifndef USE_ES2
    else {
        LOAD_GLES(glNormal3f);
        gles_glNormal3f(x, y, z);
    }
#endif
}

void glVertex3f(GLfloat x, GLfloat y, GLfloat z) {
    if (state.list.active) {
        rlVertex3f(state.list.active, x, y, z);
    }
}

void glColor4f(GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    if (state.list.active) {
        rlColor4f(state.list.active, r, g, b, a);
    }
#ifndef USE_ES2
    else {
        LOAD_GLES(glColor4f);
        gles_glColor4f(r, g, b, a);
        state.color[0] = r; state.color[1] = g;
        state.color[2] = b; state.color[3] = a;
    }
#endif
}

#ifndef USE_ES2
void glMaterialfv(GLenum face, GLenum pname, const GLfloat *params) {
    LOAD_GLES(glMaterialfv);
    if (state.list.compiling && state.list.active) {
		NewStage(state.list.active, STAGE_MATERIAL);
        rlMaterialfv(state.list.active, face, pname, params);
    } else {
	    if (face!=GL_FRONT_AND_BACK) {
		    face=GL_FRONT_AND_BACK;
		}
        gles_glMaterialfv(face, pname, params);
    }
}
void glMaterialf(GLenum face, GLenum pname, const GLfloat param) {
    LOAD_GLES(glMaterialf);
    if (state.list.compiling && state.list.active) {
		GLfloat params[4];
		memset(params, 0, 4*sizeof(GLfloat));
		params[0] = param;
		NewStage(state.list.active, STAGE_MATERIAL);
        rlMaterialfv(state.list.active, face, pname, params);
    } else {
	    if (face!=GL_FRONT_AND_BACK) {
		    face=GL_FRONT_AND_BACK;
		}
        gles_glMaterialf(face, pname, param);
    }
}
#endif

void glTexCoord2f(GLfloat s, GLfloat t) {
    if (state.list.active) {
        rlTexCoord2f(state.list.active, s, t);
    }
}

void glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) {
    if (state.list.active) {
        rlMultiTexCoord2f(state.list.active, target, s, t);
    }
}
void glArrayElement(GLint i) {
    GLfloat *v;
    pointer_state_t *p;
    p = &state.pointers.color;
    if (state.enable.color_array && p->pointer) {
        v = gl_pointer_index(p, i);
        GLfloat scale = gl_max_value(p->type);
        // color[3] defaults to 1.0f
        if (p->size < 4)
            v[3] = 1.0f;

        // scale color coordinates to a 0 - 1.0 range
        for (int i = 0; i < p->size; i++) {
            v[i] /= scale;
        }
        glColor4fv(v);
    }
    p = &state.pointers.normal;
    if (state.enable.normal_array && p->pointer) {
        v = gl_pointer_index(p, i);
        glNormal3fv(v);
    }
    p = &state.pointers.tex_coord[0];
    if (/*state.enable.texture_2d[0] &&*/ state.enable.tex_coord_array[0] && p->pointer) {
        v = gl_pointer_index(p, i);
        glTexCoord2fv(v);
    }
    int a;
    for (a=1; a<MAX_TEX; a++) {
	    p = &state.pointers.tex_coord[a];
	    if (/*state.enable.texture_2d[a] &&*/ state.enable.tex_coord_array[a] && p->pointer) {
			v = gl_pointer_index(p, i);
			glMultiTexCoord2fv(GL_TEXTURE0+a, v);
	    }
    }
    p = &state.pointers.vertex;
    if (state.enable.vertex_array && p->pointer) {
        v = gl_pointer_index(p, i);
        if (p->size == 4) {
            glVertex4fv(v);
        } else {
            glVertex3fv(v);
        }
    }
}

// TODO: between a lock and unlock, I can assume the array pointers are unchanged
// so I can build a renderlist_t on the first call and hold onto it
// maybe I need a way to call a renderlist_t with (first, count)
void glLockArraysEXT(GLint first, GLsizei count) {
    state.list.locked = true;
}

void glUnlockArraysEXT() {
    state.list.locked = false;
}

// display lists

static renderlist_t *glGetList(GLuint list) {
    if (glIsList(list))
        return state.lists[list - 1];

    return NULL;
}

GLuint glGenLists(GLsizei range) {
    int start = state.list.count;
    if (state.lists == NULL) {
        state.list.cap += range + 100;
        state.lists = malloc(state.list.cap * sizeof(uintptr_t));
    } else if (state.list.count + range > state.list.cap) {
        state.list.cap += range + 100;
        state.lists = realloc(state.lists, state.list.cap * sizeof(uintptr_t));
    }
    state.list.count += range;

    for (int i = 0; i < range; i++) {
        state.lists[start+i] = NULL;
    }
    return start + 1;
}

void glNewList(GLuint list, GLenum mode) {
    if (! glIsList(list))
        return;
    state.list.name = list;
    state.list.mode = mode;
    // TODO: if state.list.active is already defined, we probably need to clean up here
    state.list.active = state.list.first = alloc_renderlist();
    state.list.compiling = true;
}

void glEndList() {
    GLuint list = state.list.name;
    if (state.list.compiling) {
		// Free the previous list if it exist...
		free_renderlist(state.lists[list - 1]);
        state.lists[list - 1] = state.list.first;
        state.list.compiling = false;
		end_renderlist(state.list.active);
        state.list.active = NULL;
        if (state.list.mode == GL_COMPILE_AND_EXECUTE) {
            glCallList(list);
        }
    }
}

void glCallList(GLuint list) {
    if (state.list.compiling && state.list.active) {
		NewStage(state.list.active, STAGE_CALLLIST);
		/*state.list.active = extend_renderlist(state.list.active);*/
		state.list.active->glcall_list = list;
		return;
	}
    // TODO: the output of this call can be compiled into another display list
    renderlist_t *l = glGetList(list);
    if (l)
        draw_renderlist(l);
}

void glPushCall(void *call) {
    if (state.list.compiling && state.list.active) {
		NewStage(state.list.active, STAGE_GLCALL);
        rlPushCall(state.list.active, call);
    }
}

void glCallLists(GLsizei n, GLenum type, const GLvoid *lists) {
    #define call(name, type) \
        case name: glCallList(((type *)lists)[i] + state.list.base); break

    // seriously wtf
    #define call_bytes(name, stride)                             \
        case name:                                               \
            l = (GLubyte *)lists;                                \
            list = 0;                                            \
            for (j = 0; j < stride; j++) {                       \
                list += *(l + (i * stride + j)) << (stride - j); \
            }                                                    \
            glCallList(list + state.list.base);                  \
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

void glDeleteList(GLuint list) {
    renderlist_t *l = glGetList(list);
    if (l) {
        free_renderlist(l);
        state.lists[list-1] = NULL;
    }

    // lists just grow upwards, maybe use a better storage mechanism?
}

void glDeleteLists(GLuint list, GLsizei range) {
    for (int i = 0; i < range; i++) {
        glDeleteList(list+i);
    }
}

void glListBase(GLuint base) {
    state.list.base = base;
}

GLboolean glIsList(GLuint list) {
    if (list - 1 < state.list.count) {
        return true;
    }
    return false;
}

void glPolygonMode(GLenum face, GLenum mode) {
	if (face == GL_BACK)
		return;		//TODO, handle face enum for polygon mode != GL_FILL
	if (state.list.compiling && state.list.active) {
		NewStage(state.list.active, STAGE_POLYGON);
/*		if (state.list.active->polygon_mode)
			state.list.active = extend_renderlist(state.list.active);*/
		state.list.active->polygon_mode = mode;
		return;
	}
	switch(mode) {
		case GL_LINE:
		case GL_POINT:
			state.polygon_mode = mode;
			break;
		default:
			state.polygon_mode = 0;
	}
}

void alloc_matrix(matrixstack_t **matrixstack, int depth) {
	*matrixstack = (matrixstack_t*)malloc(sizeof(matrixstack_t));
	(*matrixstack)->top = 0;
	(*matrixstack)->stack = (GLfloat*)malloc(sizeof(GLfloat)*depth*16);
}

void glPushMatrix() {
	PUSH_IF_COMPILING(glPushMatrix);
	LOAD_GLES(glPushMatrix);
	// Alloc matrix stacks if needed
	if (!state.projection_matrix)
		alloc_matrix(&state.projection_matrix, MAX_STACK_PROJECTION);
	if (!state.modelview_matrix)
		alloc_matrix(&state.modelview_matrix, MAX_STACK_MODELVIEW);
	if (!state.texture_matrix) {
		state.texture_matrix = (matrixstack_t**)malloc(sizeof(matrixstack_t*)*MAX_TEX);
		for (int i=0; i<MAX_TEX; i++)
			alloc_matrix(&state.texture_matrix[i], MAX_STACK_TEXTURE);
	}
	// get matrix mode
	GLint matrix_mode;
	glGetIntegerv(GL_MATRIX_MODE, &matrix_mode);
	// go...
	switch(matrix_mode) {
		case GL_PROJECTION:
			if (state.projection_matrix->top<MAX_STACK_PROJECTION) {
				glGetFloatv(GL_PROJECTION_MATRIX, state.projection_matrix->stack+16*state.projection_matrix->top++);
			}	// else generate GL_ERROR_STACK_OVERFLOW...
			break;
		case GL_MODELVIEW:
			if (state.modelview_matrix->top<MAX_STACK_MODELVIEW) {
				glGetFloatv(GL_MODELVIEW_MATRIX, state.modelview_matrix->stack+16*state.modelview_matrix->top++);
			}	// else generate GL_ERROR_STACK_OVERFLOW...
			break;
		case GL_TEXTURE:
			if (state.texture_matrix[state.texture.active]->top<MAX_STACK_PROJECTION) {
				glGetFloatv(GL_TEXTURE_MATRIX, state.texture_matrix[state.texture.active]->stack+16*state.texture_matrix[state.texture.active]->top++);
			}	// else generate GL_ERROR_STACK_OVERFLOW...
			break;
			
		default:
			//Warning?
			printf("LIBGL: PushMatrix with Unrecognise matrix mode (0x%04X)\n", matrix_mode);
			gles_glPushMatrix();
	}
}

void glPopMatrix() {
	PUSH_IF_COMPILING(glPopMatrix);
	LOAD_GLES(glPopMatrix);
	// Alloc matrix stacks if needed
	if (!state.projection_matrix)
		alloc_matrix(&state.projection_matrix, MAX_STACK_PROJECTION);
	if (!state.modelview_matrix)
		alloc_matrix(&state.modelview_matrix, MAX_STACK_MODELVIEW);
	if (!state.texture_matrix) {
		state.texture_matrix = (matrixstack_t**)malloc(sizeof(matrixstack_t*)*MAX_TEX);
		for (int i=0; i<MAX_TEX; i++)
			alloc_matrix(&state.texture_matrix[i], MAX_STACK_TEXTURE);
	}
	// get matrix mode
	GLint matrix_mode;
	glGetIntegerv(GL_MATRIX_MODE, &matrix_mode);
	// go...
	switch(matrix_mode) {
		case GL_PROJECTION:
			if (state.projection_matrix->top) {
				glLoadMatrixf(state.projection_matrix->stack+16*--state.projection_matrix->top);
			}	// else generate GL_ERROR_STACK_UNDERFLOW...
			break;
		case GL_MODELVIEW:
			if (state.modelview_matrix->top) {
				glLoadMatrixf(state.modelview_matrix->stack+16*--state.modelview_matrix->top);
			}	// else generate GL_ERROR_STACK_UNDERFLOW...
			break;
		case GL_TEXTURE:
			if (state.texture_matrix[state.texture.active]->top) {
				glLoadMatrixf(state.texture_matrix[state.texture.active]->stack+16*--state.texture_matrix[state.texture.active]->top);
			}	// else generate GL_ERROR_STACK_UNDERFLOW...
			break;
			
		default:
			//Warning?
			printf("LIBGL: PopMatrix withUnrecognise matrix mode (0x%04X)\n", matrix_mode);
			gles_glPopMatrix();
	}
}
