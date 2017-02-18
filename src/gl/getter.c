#include "gl.h"
#include "init.h"
#include "texgen.h"
#include "../glx/hardext.h"
#include "gl4eshint.h"
#include "light.h"

GLenum gl4es_glGetError() {
	LOAD_GLES(glGetError);
    if(globals4es.noerror)
        return GL_NO_ERROR;
	if (glstate->shim_error) {
		GLenum tmp = gles_glGetError(); // to purge GLES error stack
        tmp = glstate->last_error;
		glstate->last_error = GL_NO_ERROR;
		return tmp;
	}
	return gles_glGetError();
}
GLenum glGetError() AliasExport("gl4es_glGetError");

void gl4es_glGetPointerv(GLenum pname, GLvoid* *params) {
    noerrorShim();
    if (glstate->list.active && (glstate->gl_batch && !glstate->list.compiling)) flush();
    switch(pname) {
        case GL_COLOR_ARRAY_POINTER:
            *params = (void*)glstate->vao->pointers.color.pointer;
            break;
        case GL_EDGE_FLAG_ARRAY_POINTER:
            *params = NULL;
            break;
        case GL_FEEDBACK_BUFFER_POINTER:
            *params = NULL;
            break;
        case GL_INDEX_ARRAY_POINTER:
            *params = NULL;
        case GL_NORMAL_ARRAY_POINTER:
            *params = (void*)glstate->vao->pointers.normal.pointer;
            break;
        case GL_TEXTURE_COORD_ARRAY_POINTER:
            *params = (void*)glstate->vao->pointers.tex_coord[glstate->texture.client].pointer;
            break;
        case GL_SELECTION_BUFFER_POINTER:
            *params = glstate->selectbuf.buffer;
            break;
        case GL_VERTEX_ARRAY_POINTER :
            *params = (void*)glstate->vao->pointers.vertex.pointer;
            break;
        default:
            errorShim(GL_INVALID_ENUM);
    }
}
void glGetPointerv(GLenum pname, GLvoid* *params) AliasExport("gl4es_glGetPointerv");

const GLubyte *gl4es_glGetString(GLenum name) {
//    LOAD_GLES(glGetString);
    const GLubyte *str;
    errorShim(GL_NO_ERROR);
	static GLubyte *extensions = NULL;
	if(!extensions) {
		extensions = (GLubyte*)malloc(5000);	// arbitrary size...
		strcpy(extensions,
				"GL_EXT_abgr "
                "GL_EXT_packed_pixels "
                "GL_EXT_compiled_vertex_array "
                "GL_ARB_vertex_buffer_object "
                "GL_ARB_vertex_array_object "
                "GL_ARB_vertex_buffer "
                "GL_EXT_vertex_array "
                "GL_EXT_secondary_color "
                "GL_EXT_texture_env_combine "
                "GL_ARB_multitexture "
                "GL_ARB_texture_env_add "
                "GL_ARB_texture_border_clamp "
                "GL_ARB_point_parameters "
                "GL_EXT_texture_env_add "
                "GL_ARB_texture_env_combine "
                "GL_ARB_texture_env_crossbar "
                "GL_ARB_texture_env_dot3 "
                "GL_ARB_texture_mirrored_repeat "
                "GL_SGIS_generate_mipmap "
                "GL_EXT_packed_depth_stencil "
                "GL_EXT_draw_range_elements "
                "GL_EXT_bgra "
                "GL_ARB_texture_compression "
                "GL_EXT_texture_compression_s3tc "
                "GL_OES_texture_compression_S3TC "
                "GL_EXT_texture_compression_dxt3 "
                "GL_EXT_texture_compression_dxt5 "
                "GL_EXT_texture_compression_dxt1 "
                "GL_ARB_point_parameters "
                "GL_EXT_point_parameters "
                "GL_EXT_stencil_wrap "
                "GL_SGIS_texture_edge_clamp "
                "GL_EXT_texture_edge_clamp "
                "GL_EXT_direct_state_access "
                "GL_EXT_multi_draw_arrays "
                "GL_SUN_multi_draw_arrays "
                "GL_ARB_multisample "
                "GL_EXT_texture_object "
                "GL_EXT_polygon_offset "
                "GL_GL4ES_hint "
                "GL_ARB_texture_rectangle "
//                "GL_EXT_blend_logic_op "
				);
        if(globals4es.vabgra)
            strcat(extensions, "GL_ARB_vertex_array_bgra ");
		if(globals4es.npot>=1)
			strcat(extensions, "GL_APPLE_texture_2D_limited_npot ");
		if(globals4es.npot>=2)
			strcat(extensions, "GL_ARB_texture_non_power_of_two ");
        if(hardext.blendcolor)
            strcat(extensions, "GL_EXT_blend_color ");
        if(hardext.blendminmax)
            strcat(extensions, "GL_EXT_blend_minmax ");
        if(hardext.blendeq)
            strcat(extensions, "GL_EXT_blend_equation_separate ");
        if(hardext.blendfunc)
            strcat(extensions, "GL_EXT_blend_func_separate ");
        if(hardext.blendsub)
            strcat(extensions, "GL_EXT_blend_subtract ");
        if(hardext.fbo)
            strcat(extensions,                 
                "GL_ARB_framebuffer_object "
                "GL_EXT_framebuffer_object "
                "GL_EXT_packed_depth_stencil "
                "GL_ARB_draw_buffers ");
        if(hardext.pointsprite)
            strcat(extensions, "GL_ARB_point_sprite ");
        if(hardext.cubemap)
            strcat(extensions, "GL_ARB_texture_cube_map ");
	}
    switch (name) {
        case GL_VERSION:
            return (GLubyte *)globals4es.version;
        case GL_EXTENSIONS:
            return extensions;
		case GL_VENDOR:
			return (GLubyte *)"ptitSeb";
		case GL_RENDERER:
			return (GLubyte *)"GLES_CM wrapper";
		case GL_SHADING_LANGUAGE_VERSION:
			return (GLubyte *)"";
        default:
			errorShim(GL_INVALID_ENUM);
            return (str)?str:(GLubyte*)"";
    }
}
const GLubyte *glGetString(GLenum name) AliasExport("gl4es_glGetString");

#define TOP(A) (glstate->A->stack+(glstate->A->top*16))

// glGet
void gl4es_glGetIntegerv(GLenum pname, GLint *params) {
    if (params==NULL) {
        errorShim(GL_INVALID_OPERATION);
        return;
    }
    GLint dummy;
    LOAD_GLES(glGetIntegerv);
    if (glstate->list.active && (glstate->gl_batch && !glstate->list.compiling)) flush();
    noerrorShim();
    switch (pname) {
        case GL_MAJOR_VERSION:
            *params = 1;
            break;
        case GL_MINOR_VERSION:
            *params = 5;
            break;
        case GL_MAX_ELEMENTS_INDICES:
            *params = 1024;
            break;
        case GL_MAX_ELEMENTS_VERTICES:
			*params = 4096;
			break;
        case GL_AUX_BUFFERS:
            *params = 0;
            break;
        case GL_MAX_DRAW_BUFFERS_ARB:   // fake...
            *params = 1;
            break;
        case GL_UNPACK_ROW_LENGTH:	
			*params = glstate->texture.unpack_row_length;
			break;
        case GL_UNPACK_SKIP_PIXELS:
			*params = glstate->texture.unpack_skip_pixels;
			break;
        case GL_UNPACK_SKIP_ROWS:
			*params = glstate->texture.unpack_skip_rows;
			break;
        case GL_UNPACK_LSB_FIRST:
			*params = glstate->texture.unpack_lsb_first;
			break;
        case GL_UNPACK_IMAGE_HEIGHT:
            *params = glstate->texture.unpack_image_height;
            break;
        case GL_PACK_ROW_LENGTH:	
			*params = glstate->texture.pack_row_length;
			break;
        case GL_PACK_SKIP_PIXELS:
			*params = glstate->texture.pack_skip_pixels;
			break;
        case GL_PACK_SKIP_ROWS:
			*params = glstate->texture.pack_skip_rows;
			break;
        case GL_PACK_LSB_FIRST:
			*params = glstate->texture.pack_lsb_first;
			break;
        case GL_PACK_IMAGE_HEIGHT:
            *params = glstate->texture.pack_image_height;
            break;
        case GL_UNPACK_SWAP_BYTES:
        case GL_PACK_SWAP_BYTES:
            //Fake, *TODO* ?
			*params = 0;
			break;
        case GL_ZOOM_X:
	        *params = glstate->raster.raster_zoomx;
	        break;
        case GL_ZOOM_Y:
            *params = glstate->raster.raster_zoomy;
            break;
        case GL_RED_SCALE:
            *params = glstate->raster.raster_scale[0];
            break;
        case GL_RED_BIAS:
            *params = glstate->raster.raster_bias[0];
            break;
        case GL_GREEN_SCALE:
        case GL_BLUE_SCALE:
        case GL_ALPHA_SCALE:
            *params = glstate->raster.raster_scale[(pname-GL_GREEN_SCALE)/2+1];
	    break;
        case GL_GREEN_BIAS:
        case GL_BLUE_BIAS:
        case GL_ALPHA_BIAS:
    	    *params = glstate->raster.raster_bias[(pname-GL_GREEN_BIAS)/2+1];
	    break;
	case GL_POINT_SIZE_RANGE:
        gles_glGetIntegerv(GL_POINT_SIZE_MIN, params);
        gles_glGetIntegerv(GL_POINT_SIZE_MAX, params+1);
        break;
	case GL_RENDER_MODE:
        *params = (glstate->render_mode)?glstate->render_mode:GL_RENDER;
        break;
	case GL_NAME_STACK_DEPTH:
        *params = glstate->namestack.top;
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
        params[dummy++]=GL_COMPRESSED_RGB_S3TC_DXT1_EXT;
        params[dummy++]=GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
        params[dummy++]=GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
        params[dummy++]=GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
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
        *params=(glstate->modelview_matrix)?(glstate->modelview_matrix->top+1):1;
        break;
	case GL_PROJECTION_STACK_DEPTH:
        *params=(glstate->projection_matrix)?(glstate->projection_matrix->top+1):1;
        break;
	case GL_TEXTURE_STACK_DEPTH:
        *params=(glstate->texture_matrix)?(glstate->texture_matrix[glstate->texture.active]->top+1):1;
        break;
	case GL_MAX_LIST_NESTING:
        *params=64;	// fake, no limit in fact
        break;
	case  GL_ARRAY_BUFFER_BINDING:
        *params=(glstate->vao->vertex)?glstate->vao->vertex->buffer:0;
        break;
	case  GL_ELEMENT_ARRAY_BUFFER_BINDING:
        *params=(glstate->vao->elements)?glstate->vao->elements->buffer:0;
        break;
	case  GL_PIXEL_PACK_BUFFER_BINDING:
        *params=(glstate->vao->pack)?glstate->vao->pack->buffer:0;
        break;
	case  GL_PIXEL_UNPACK_BUFFER_BINDING:
        *params=(glstate->vao->unpack)?glstate->vao->unpack->buffer:0;
        break;
    case GL_MATRIX_MODE:
        *params=glstate->matrix_mode;
        break;
    case GL_LIGHT_MODEL_TWO_SIDE:
        *params=glstate->light.two_side;
        break;
    case GL_LIGHT_MODEL_AMBIENT:
        for (dummy=0; dummy<4; dummy++)
                params[dummy]=glstate->light.ambient[dummy];
        break;
    case GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB:
        *params=hardext.maxsize;
        break;
    case GL_SHRINK_HINT_GL4ES:
        *params=globals4es.texshrink;
        break;
    case GL_ALPHAHACK_HINT_GL4ES: 
        *params=globals4es.alphahack;
        break;
    case GL_RECYCLEFBO_HINT_GL4ES: 
        *params=globals4es.recyclefbo;
        break;
    case GL_MIPMAP_HINT_GL4ES: 
        *params=globals4es.automipmap;
        break;
    case GL_TEXDUMP_HINT_GL4ES: 
        *params=globals4es.texdump;
        break;
    case GL_COPY_HINT_GL4ES: 
        *params=globals4es.copytex;
        break;
    case GL_NOLUMAPHA_HINT_GL4ES: 
        *params=globals4es.nolumalpha;
        break;
    case GL_BLENDHACK_HINT_GL4ES: 
        *params=globals4es.blendhack;
        break;
    case GL_BATCH_HINT_GL4ES: 
        *params=globals4es.batch;
        break;
    case GL_NOERROR_HINT_GL4ES: 
        *params=globals4es.noerror;
        break;
    default:
        errorGL();
        gles_glGetIntegerv(pname, params);
    }
}
void glGetIntegerv(GLenum pname, GLint *params) AliasExport("gl4es_glGetIntegerv");

void gl4es_glGetFloatv(GLenum pname, GLfloat *params) {
    LOAD_GLES(glGetFloatv);
    if (glstate->list.active && (glstate->gl_batch && !glstate->list.compiling)) flush();
    noerrorShim();
    switch (pname) {
        case GL_MAJOR_VERSION:
            *params = 1;
            break;
        case GL_MINOR_VERSION:
            *params = 5;
            break;
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
            *params = glstate->texture.unpack_row_length;
            break;
        case GL_UNPACK_SKIP_PIXELS:
            *params = glstate->texture.unpack_skip_pixels;
            break;
        case GL_UNPACK_SKIP_ROWS:
            *params = glstate->texture.unpack_skip_rows;
            break;
        case GL_UNPACK_LSB_FIRST:
            *params = glstate->texture.unpack_lsb_first;
            break;
        case GL_PACK_ROW_LENGTH:	
            *params = glstate->texture.pack_row_length;
            break;
        case GL_PACK_SKIP_PIXELS:
            *params = glstate->texture.pack_skip_pixels;
            break;
        case GL_PACK_SKIP_ROWS:
            *params = glstate->texture.pack_skip_rows;
            break;
        case GL_PACK_LSB_FIRST:
            *params = glstate->texture.pack_lsb_first;
            break;
        case GL_ZOOM_X:
            *params = glstate->raster.raster_zoomx;
            break;
        case GL_ZOOM_Y:
            *params = glstate->raster.raster_zoomy;
            break;
        case GL_RED_SCALE:
            *params = glstate->raster.raster_scale[0];
            break;
        case GL_RED_BIAS:
            *params = glstate->raster.raster_bias[0];
            break;
        case GL_GREEN_SCALE:
        case GL_BLUE_SCALE:
        case GL_ALPHA_SCALE:
            *params = glstate->raster.raster_scale[(pname-GL_GREEN_SCALE)/2+1];
            break;
        case GL_GREEN_BIAS:
        case GL_BLUE_BIAS:
        case GL_ALPHA_BIAS:
            *params = glstate->raster.raster_bias[(pname-GL_GREEN_BIAS)/2+1];
            break;
        case GL_POINT_SIZE_RANGE:
            gles_glGetFloatv(GL_POINT_SIZE_MIN, params);
            gles_glGetFloatv(GL_POINT_SIZE_MAX, params+1);
            break;
        case GL_RENDER_MODE:
            *params = (glstate->render_mode)?glstate->render_mode:GL_RENDER;
            break;
        case GL_NAME_STACK_DEPTH:
            *params = glstate->namestack.top;
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
            *params=(glstate->modelview_matrix)?(glstate->modelview_matrix->top+1):1;
            break;
        case GL_PROJECTION_STACK_DEPTH:
            *params=(glstate->projection_matrix)?(glstate->projection_matrix->top+1):1;
            break;
        case GL_TEXTURE_STACK_DEPTH:
            *params=(glstate->texture_matrix)?(glstate->texture_matrix[glstate->texture.active]->top+1):1;
            break;
        case GL_MAX_LIST_NESTING:
            *params=64;	// fake, no limit in fact
            break;
        case  GL_ARRAY_BUFFER_BINDING:
            *params=(glstate->vao->vertex)?glstate->vao->vertex->buffer:0;
            break;
        case  GL_ELEMENT_ARRAY_BUFFER_BINDING:
            *params=(glstate->vao->elements)?glstate->vao->elements->buffer:0;
            break;
        case  GL_PIXEL_PACK_BUFFER_BINDING:
            *params=(glstate->vao->pack)?glstate->vao->pack->buffer:0;
            break;
        case  GL_PIXEL_UNPACK_BUFFER_BINDING:
            *params=(glstate->vao->unpack)?glstate->vao->unpack->buffer:0;
            break;
        case GL_TRANSPOSE_PROJECTION_MATRIX:
            matrix_transpose(TOP(projection_matrix), params);
            break;
        case GL_TRANSPOSE_MODELVIEW_MATRIX:
            matrix_transpose(TOP(modelview_matrix), params);
            break;
        case GL_TRANSPOSE_TEXTURE_MATRIX:
            matrix_transpose(TOP(texture_matrix[glstate->texture.active]), params);
            break;
        case GL_MATRIX_MODE:
            *params=glstate->matrix_mode;
            break;
        case GL_PROJECTION_MATRIX:
            memcpy(params, TOP(projection_matrix), 16*sizeof(GLfloat));
            break;
        case GL_MODELVIEW_MATRIX:
            memcpy(params, TOP(modelview_matrix), 16*sizeof(GLfloat));
            break;
        case GL_TEXTURE_MATRIX:
            memcpy(params, TOP(texture_matrix[glstate->texture.active]), 16*sizeof(GLfloat));
            break;
        case GL_LIGHT_MODEL_TWO_SIDE:
            *params=glstate->light.two_side;
            break;
        case GL_LIGHT_MODEL_AMBIENT:
            memcpy(params, glstate->light.ambient, 4*sizeof(GLfloat));
            break;
        case GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB:
            *params=hardext.maxsize;
            break;
        case GL_SHRINK_HINT_GL4ES:
            *params=globals4es.texshrink;
            break;
        case GL_ALPHAHACK_HINT_GL4ES: 
            *params=globals4es.alphahack;
            break;
        case GL_RECYCLEFBO_HINT_GL4ES: 
            *params=globals4es.recyclefbo;
            break;
        case GL_MIPMAP_HINT_GL4ES: 
            *params=globals4es.automipmap;
            break;
        case GL_TEXDUMP_HINT_GL4ES: 
            *params=globals4es.texdump;
            break;
        case GL_COPY_HINT_GL4ES: 
            *params=globals4es.copytex;
            break;
        case GL_NOLUMAPHA_HINT_GL4ES: 
            *params=globals4es.nolumalpha;
            break;
        case GL_BLENDHACK_HINT_GL4ES: 
            *params=globals4es.blendhack;
            break;
        case GL_BATCH_HINT_GL4ES: 
            *params=globals4es.batch;
            break;
        case GL_NOERROR_HINT_GL4ES: 
            *params=globals4es.noerror;
            break;
        case GL_NODOWNSAMPLING_HINT_GL4ES:
            *params=globals4es.nodownsampling;
            break;
        default:
            errorGL();
            gles_glGetFloatv(pname, params);
    }
}
void glGetFloatv(GLenum pname, GLfloat *params) AliasExport("gl4es_glGetFloatv");

void gl4es_glGetLightfv(GLenum light, GLenum pname, GLfloat * params) {
    const int nl = light-GL_LIGHT0;
    if(nl<0 || nl>=hardext.maxlights) {
        errorShim(GL_INVALID_ENUM);
        return;
    }
    switch(pname) {
        case GL_AMBIENT:
            memcpy(params, glstate->light.lights[nl].ambient, 4*sizeof(GLfloat));
            break;
        case GL_DIFFUSE:
            memcpy(params, glstate->light.lights[nl].diffuse, 4*sizeof(GLfloat));
            break;
        case GL_SPECULAR:
            memcpy(params, glstate->light.lights[nl].specular, 4*sizeof(GLfloat));
            break;
        case GL_POSITION:
            memcpy(params, glstate->light.lights[nl].position, 4*sizeof(GLfloat));
            break;
        case GL_SPOT_DIRECTION:
            memcpy(params, glstate->light.lights[nl].spotDirection, 3*sizeof(GLfloat));
            break;
        case GL_SPOT_EXPONENT:
            params[0] = glstate->light.lights[nl].spotExponent;
            break;
        case GL_SPOT_CUTOFF:
            params[0] = glstate->light.lights[nl].spotCutoff;
            break;
        case GL_CONSTANT_ATTENUATION:
            params[0] = glstate->light.lights[nl].constantAttenuation;
            break;
        case GL_LINEAR_ATTENUATION:
            params[0] = glstate->light.lights[nl].linearAttenuation;
            break;
        case GL_QUADRATIC_ATTENUATION:
            params[0] = glstate->light.lights[nl].quadraticAttenuation;
            break;
        default:
            errorShim(GL_INVALID_ENUM);
            return;
    }
    noerrorShim();
}
void glGetLightfv(GLenum pname, GLfloat *params) AliasExport("gl4es_glGetLightfv");

void gl4es_glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params) {
    if(face!=GL_FRONT && face!=GL_BACK) {
        errorShim(GL_INVALID_ENUM);
        return;
    }
    switch(pname) {
        case GL_AMBIENT:
            if(face==GL_FRONT)
                memcpy(params, glstate->material.front.ambient, 4*sizeof(GLfloat));
            if(face==GL_BACK)
                memcpy(params, glstate->material.back.ambient, 4*sizeof(GLfloat));
            break;
        case GL_DIFFUSE:
            if(face==GL_FRONT)
                memcpy(params, glstate->material.front.diffuse, 4*sizeof(GLfloat));
            if(face==GL_BACK)
                memcpy(params, glstate->material.back.diffuse, 4*sizeof(GLfloat));
            break;
        case GL_SPECULAR:
            if(face==GL_FRONT)
                memcpy(params, glstate->material.front.specular, 4*sizeof(GLfloat));
            if(face==GL_BACK)
                memcpy(params, glstate->material.back.specular, 4*sizeof(GLfloat));
            break;
        case GL_EMISSION:
            if(face==GL_FRONT)
                memcpy(params, glstate->material.front.emission, 4*sizeof(GLfloat));
            if(face==GL_BACK)
                memcpy(params, glstate->material.back.emission, 4*sizeof(GLfloat));
            break;
        case GL_SHININESS:
            if(face==GL_FRONT)
                *params = glstate->material.front.shininess;
            if(face==GL_BACK)
                *params = glstate->material.back.shininess;
            break;
        case GL_COLOR_INDEXES:
            if(face==GL_FRONT) {
                params[0] = glstate->material.front.indexes[0];
                params[1] = glstate->material.front.indexes[1];
                params[2] = glstate->material.front.indexes[2];
            }
            if(face==GL_BACK) {
                params[0] = glstate->material.back.indexes[0];
                params[1] = glstate->material.back.indexes[1];
                params[2] = glstate->material.back.indexes[2];
            }
        default:
            errorShim(GL_INVALID_ENUM);
            return;
    }
    noerrorShim();
}
void glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params) AliasExport("gl4es_glGetMaterialfv");