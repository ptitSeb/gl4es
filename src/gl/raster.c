#include "raster.h"
#include "debug.h"
#include "init.h"

static GLubyte *raster = NULL;
static GLuint raster_texture=0;
static GLsizei raster_width=0;
static GLsizei raster_height=0;
static GLsizei raster_realwidth=0;
static GLsizei raster_realheight=0;

static GLint	raster_x1, raster_x2, raster_y1, raster_y2;
#define min(a, b)	((a)<b)?(a):(b)
#define max(a, b)	((a)>(b))?(a):(b)

void matrix_transpose(const GLfloat *a, GLfloat *b);
void matrix_vector(const GLfloat *a, const GLfloat *b, GLfloat *c);

void gl4es_glRasterPos3f(GLfloat x, GLfloat y, GLfloat z) {
    if (glstate->list.active)
        if (glstate->list.compiling || glstate->gl_batch) {
			NewStage(glstate->list.active, STAGE_RASTER);
			rlRasterOp(glstate->list.active, 1, x, y, z);
			noerrorShim();
			return;
		} else flush();

	// Transform xyz coordinates with current modelview and projection matrix...
	GLfloat glmatrix[16], projection[16], modelview[16];
	GLfloat t[4], transl[4] = {x, y, z, 1.0f};
	gl4es_glGetFloatv(GL_PROJECTION_MATRIX, glmatrix);
	matrix_transpose(glmatrix, projection);
	gl4es_glGetFloatv(GL_MODELVIEW_MATRIX, glmatrix);
	matrix_transpose(glmatrix, modelview);
	matrix_vector(modelview, transl, t);
	matrix_vector(projection, t, transl);
	GLfloat w2, h2;
	w2=glstate->raster.viewport.width/2.0f;
	h2=glstate->raster.viewport.height/2.0f;
	glstate->raster.rPos.x = transl[0]*w2+w2;
	glstate->raster.rPos.y = transl[1]*h2+h2;
	glstate->raster.rPos.z = transl[2];
}

void gl4es_glWindowPos3f(GLfloat x, GLfloat y, GLfloat z) {
    if (glstate->list.active)
        if (glstate->list.compiling || glstate->gl_batch) {
			NewStage(glstate->list.active, STAGE_RASTER);
			rlRasterOp(glstate->list.active, 2, x, y, z);
			noerrorShim();
			return;
		} else flush();

    glstate->raster.rPos.x = x;
    glstate->raster.rPos.y = y;
    glstate->raster.rPos.z = z;	
}

void gl4es_glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
    PUSH_IF_COMPILING(glViewport);
    LOAD_GLES(glViewport);
	if(glstate->raster.viewport.x!=x || glstate->raster.viewport.y!=y || glstate->raster.viewport.width!=width || glstate->raster.viewport.height!=height) {
		gles_glViewport(x, y, width, height);
		glstate->raster.viewport.x = x;
		glstate->raster.viewport.y = y;
		glstate->raster.viewport.width = width;
		glstate->raster.viewport.height = height;
	}
}

// hacky viewport temporary changes
void pushViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
    LOAD_GLES(glViewport);
    gles_glViewport(x, y, width, height);
}
void popViewport() {
    LOAD_GLES(glViewport);
    gles_glViewport(glstate->raster.viewport.x, glstate->raster.viewport.y, glstate->raster.viewport.width, glstate->raster.viewport.height);
}


void gl4es_glPixelZoom(GLfloat xfactor, GLfloat yfactor) {
    if (glstate->list.active)
        if (glstate->list.compiling || glstate->gl_batch) {
			NewStage(glstate->list.active, STAGE_RASTER);
			rlRasterOp(glstate->list.active, 3, xfactor, yfactor, 0.0f);
			noerrorShim();
			return;
		} else flush();

	glstate->raster.raster_zoomx = xfactor;
	glstate->raster.raster_zoomy = yfactor;
//printf("LIBGL: glPixelZoom(%f, %f)\n", xfactor, yfactor);
}

void gl4es_glPixelTransferf(GLenum pname, GLfloat param) {
    if (glstate->list.active)
        if (glstate->list.compiling || glstate->gl_batch) {
			NewStage(glstate->list.active, STAGE_RASTER);
			rlRasterOp(glstate->list.active, pname|0x10000, param, 0.0f, 0.0f);
			noerrorShim();
			return;
		} else flush();

//printf("LIBGL: glPixelTransferf(%04x, %f)\n", pname, param);
	switch(pname) {
		case GL_RED_SCALE:
			glstate->raster.raster_scale[0]=param;
			break;
		case GL_RED_BIAS:
			glstate->raster.raster_bias[0]=param;
			break;
		case GL_GREEN_SCALE:
		case GL_BLUE_SCALE:
		case GL_ALPHA_SCALE:
			glstate->raster.raster_scale[(pname-GL_GREEN_SCALE)/2+1]=param;
			break;
		case GL_GREEN_BIAS:
		case GL_BLUE_BIAS:
		case GL_ALPHA_BIAS:
			glstate->raster.raster_bias[(pname-GL_GREEN_BIAS)/2+1]=param;
			break;
		/*default:
			printf("LIBGL: stubbed glPixelTransferf(%04x, %f)\n", pname, param);*/
	// the other...
	}
}


void init_raster(int width, int height) {
	int w, h;
	w=npot(width);
	h=npot(height);
    #ifdef USE_DRAWTEX
    raster_realwidth = width;
    raster_realheight = height;
    #endif
	if (raster) {
		if ((raster_width!=w) || (raster_height!=h)) {
			free(raster);
			raster = NULL;
		} else 
			memset(raster, 0, 4 * raster_width * raster_height * sizeof(GLubyte));
	}
    if (!raster) {
        raster = (GLubyte *)malloc(4 * w * h * sizeof(GLubyte));
		memset(raster, 0, 4 * w * h * sizeof(GLubyte));
		raster_x1 = 0; raster_y1 = 0; raster_x2 = width; raster_y2 = height;
		raster_width = w; raster_height = h;
	}
}

GLubyte raster_transform(GLubyte pix, GLubyte number) {
	GLfloat a = (GLfloat)pix*(1.0f/255.0f);
	a=a*glstate->raster.raster_scale[number]+glstate->raster.raster_bias[number];
	if (a<0.0) a=0.0;
	if (a>1.0) a=1.0;
	return (GLubyte)(a*255.0f);
}
GLfloat FASTMATH raster_transformf(GLfloat pix, GLubyte number) {
	pix=pix*glstate->raster.raster_scale[number]+glstate->raster.raster_bias[number];
	if (pix<0.0) pix=0.0;
	if (pix>1.0) pix=1.0;
	return pix;
}

int raster_need_transform() {
	for (int i=0; i<4; i++) if (glstate->raster.raster_scale[i]!=1.0f) return 1;
	for (int i=0; i<4; i++) if (glstate->raster.raster_bias[i]!=0.0f) return 1;
	return 0;
}

GLuint raster_to_texture()
{
    LOAD_GLES(glGenTextures);
    LOAD_GLES(glBindTexture);
    LOAD_GLES(glTexEnvf);
    LOAD_GLES(glTexImage2D);
    LOAD_GLES(glActiveTexture);
    LOAD_GLES(glTexParameteri);
    LOAD_GLES(glTexParameterf);
    #ifdef USE_DRAWTEX
    LOAD_GLES(glTexParameteriv);
    #endif
    
	renderlist_t *old_list = glstate->list.active;
	if (old_list) glstate->list.active = NULL;		// deactivate list...
	GLboolean compiling = glstate->list.compiling;
    GLuint state_batch = glstate->gl_batch;
	glstate->list.compiling = false;
    glstate->gl_batch = 0;
    gl4es_glPushAttrib(GL_TEXTURE_BIT | GL_ENABLE_BIT );
	GLuint old_tex_unit, old_tex;
	gl4es_glGetIntegerv(GL_ACTIVE_TEXTURE, &old_tex_unit);
	if (old_tex_unit!=GL_TEXTURE0) gl4es_glActiveTexture(GL_TEXTURE0);
	old_tex = 0;
	if (glstate->texture.bound[0][ENABLED_TEX2D])
		old_tex = glstate->texture.bound[0][ENABLED_TEX2D]->texture;
	GLuint raster_texture;
	gl4es_glEnable(GL_TEXTURE_2D);
	gles_glGenTextures(1, &raster_texture);
	gles_glBindTexture(GL_TEXTURE_2D, raster_texture);

    gl4es_glPixelStorei(GL_PACK_ALIGNMENT, 1);
    gl4es_glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    gl4es_glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
    gl4es_glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
    gl4es_glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
    gl4es_glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    gles_glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    gles_glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	gles_glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, raster_width, raster_height,
		0, GL_RGBA, GL_UNSIGNED_BYTE, raster);
    #ifdef USE_DRAWTEX
    // setup the texture for glDrawTexiOES
    GLint coords [] = {0, 0, raster_realwidth, raster_realheight};
    gles_glTexParameteriv( GL_TEXTURE_2D, GL_TEXTURE_CROP_RECT_OES, coords );
    #endif

	gles_glBindTexture(GL_TEXTURE_2D, old_tex);
	if (old_tex_unit!=GL_TEXTURE0) 
		gl4es_glActiveTexture(old_tex_unit);
	gl4es_glPopAttrib();
	if (old_list) glstate->list.active = old_list;
	glstate->list.compiling = compiling;
    glstate->gl_batch = state_batch;
	return raster_texture;
}

void gl4es_glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig,
              GLfloat xmove, GLfloat ymove, const GLubyte *bitmap) {
/*printf("glBitmap, xy={%f, %f}, xyorig={%f, %f}, size={%u, %u}, zoom={%f, %f}, viewport={%i, %i, %i, %i}\n", 	
	glstate->raster.rPos.x, glstate->raster.rPos.y, xorig, yorig, width, height, glstate->raster.raster_zoomx, glstate->raster.raster_zoomy, glstate->raster.viewport.x, glstate->raster.viewport.y, glstate->raster.viewport.width, glstate->raster.viewport.height);*/
    // TODO: shouldn't be drawn if the raster pos is outside the viewport?
    // TODO: negative width/height mirrors bitmap?
    noerrorShim();
    if ((!width && !height) || (bitmap==0)) {
		if (glstate->list.active) {
			if (glstate->list.active->raster)
				glstate->list.active = extend_renderlist(glstate->list.active);		// already a raster in the list, create a new one
			rasterlist_t *r = glstate->list.active->raster = (rasterlist_t*)malloc(sizeof(rasterlist_t));
            r->shared = (int*)malloc(sizeof(int)); 
            *r->shared = 0;
			r->texture = 0;
			r->xorig = 0;
			r->yorig = 0;
			r->zoomx = 1.0f;
			r->zoomy = 1.0f;
			r->xmove = xmove;
			r->ymove = ymove;
			
		} else {
			glstate->raster.rPos.x += xmove;
			glstate->raster.rPos.y += ymove;
		}
        return;
    }

    init_raster(width, height);
    const GLubyte *from;
    GLubyte *to;
    int x, y;
	int pixtrans=raster_need_transform();
	
    // copy to pixel data
	if (pixtrans) {
        for (y = 0; y < height; y++) {
            to = raster + 4 * (GLint)(y * raster_width);
            from = bitmap + (y * ((width+7)/8));
            for (x = 0; x < width; x++) {
                GLubyte b = from[(x / 8)];
                int p = (b & (1 << (7 - (x % 8)))) ? 255 : 0;
                // r, g, b, a
				*to++ = raster_transform(p, 0);
				*to++ = raster_transform(p, 1);
				*to++ = raster_transform(p, 2);
				*to++ = raster_transform(p, 3);
			}
        }
	} else {
        for (y = 0; y < height; y++) {
            to = raster + 4 * (GLint)(y * raster_width);
            from = bitmap + (y * ((width+7)/8));
            for (x = 0; x < width; x++) {
                GLubyte b = from[(x / 8)];
                int p = (b & (1 << (7 - (x % 8)))) ? 255 : 0;
				*to++ = p;
				*to++ = p;
				*to++ = p;
				*to++ = p;
			}
        }
    }

    rasterlist_t rast;
    rasterlist_t *r;
	if (glstate->list.active) {
		NewStage(glstate->list.active, STAGE_RASTER);
		r = glstate->list.active->raster = (rasterlist_t*)malloc(sizeof(rasterlist_t));
        r->shared = (int*)malloc(sizeof(int));
        *r->shared = 0;
	} else {
		r = &rast;
	}
	r->texture = raster_to_texture();
	r->xmove = xmove;
	r->ymove = ymove;
	r->xorig = xorig;
	r->yorig = yorig;
	r->width = width;
	r->height = height;
	r->bitmap = true;
	r->zoomx = glstate->raster.raster_zoomx;
	r->zoomy = glstate->raster.raster_zoomy;
    LOAD_GLES(glDeleteTextures);
	if (!(glstate->list.active)) {
		render_raster_list(r);
		gles_glDeleteTextures(1, &r->texture);
		r->texture = 0;
	}
}

void gl4es_glDrawPixels(GLsizei width, GLsizei height, GLenum format,
                  GLenum type, const GLvoid *data) {
    GLubyte *pixels, *from, *to;
    GLvoid *dst = NULL;
    LOAD_GLES(glDeleteTextures);

    noerrorShim();
    
/*printf("glDrawPixels, xy={%f, %f}, size={%i, %i}, format=%s, type=%s, zoom={%f, %f}, viewport={%i, %i, %i, %i}\n", 	
	glstate->raster.rPos.x, glstate->raster.rPos.y, width, height, PrintEnum(format), PrintEnum(type), glstate->raster.raster_zoomx, glstate->raster.raster_zoomy, glstate->raster.viewport.x, glstate->raster.viewport.y, glstate->raster.viewport.width, glstate->raster.viewport.height);*/
	// check of unsuported format...
	if ((format == GL_STENCIL_INDEX) || (format == GL_DEPTH_COMPONENT)) {
        errorShim(GL_INVALID_ENUM);
		return;
    }

    init_raster(width, height);

	GLsizei bmp_width = (glstate->texture.unpack_row_length)?glstate->texture.unpack_row_length:width;

    if (! pixel_convert(data, &dst, bmp_width, height,
                        format, type, GL_RGBA, GL_UNSIGNED_BYTE, 0, 1)) {	// pack_align is forced to 1 when drawing
        return;
    }
					  
    pixels = (GLubyte *)dst;
	GLint vx, vy;
	int pixtrans=raster_need_transform();

    if (pixtrans) {
        for (int y = 0; y < height; y++) {
            to = raster + 4 * (GLint)(y * raster_width);
            from = pixels + 4 * (glstate->texture.unpack_skip_pixels + (y + glstate->texture.unpack_skip_rows) * bmp_width);
            for (int x = 0; x < width; x++) {
				*to++ = raster_transform(*from++, 0);
				*to++ = raster_transform(*from++, 1);
				*to++ = raster_transform(*from++, 2);
				*to++ = raster_transform(*from++, 3);
            }
        }
	} else {
        for (int y = 0; y < height; y++) {
            to = raster + 4 * (GLint)(y * raster_width);
            from = pixels + 4 * (glstate->texture.unpack_skip_pixels + (y + glstate->texture.unpack_skip_rows) * bmp_width);
            for (int x = 0; x < width; x++) {
				*to++ = *from++;
				*to++ = *from++;
				*to++ = *from++;
				*to++ = *from++;
			}
		}
	}
	if (pixels != data)
        free(pixels);
	
    static rasterlist_t rast = {.texture=0, .shared=NULL};
    rasterlist_t *r;
	if (glstate->list.active) {
		NewStage(glstate->list.active, STAGE_RASTER);
		rasterlist_t *r = glstate->list.active->raster = (rasterlist_t*)malloc(sizeof(rasterlist_t));
        r->shared = (int*)malloc(sizeof(int));
        *r->shared = 0;
	} else {
		r = &rast;
        if(r->texture)
            gles_glDeleteTextures(1, &r->texture);
	}
	r->texture = raster_to_texture(width, height);
	r->xmove = 0;
	r->ymove = 0;
	r->xorig = 0;
	r->yorig = 0;
	r->width = width;
	r->height = height;
	r->bitmap = false;
	r->zoomx = glstate->raster.raster_zoomx;
	r->zoomy = glstate->raster.raster_zoomy;
	if (!(glstate->list.active)) {
		render_raster_list(r);
/*		gles_glDeleteTextures(1, &r->texture);
		r->texture = 0;*/
	}
}

void render_raster_list(rasterlist_t* rast) {
//printf("render_raster_list, rast->x/y=%f/%f rast->width/height=%i/%i, rPos.x/y/z=%f/%f/%f, rast->zoomxy=%f/%f raster->texture=%u\n", rast->xorig, rast->yorig, rast->width, rast->height, glstate->raster.rPos.x, glstate->raster.rPos.y, glstate->raster.rPos.z, rast->zoomx, rast->zoomy, rast->texture);
    #ifdef USE_DRAWTEX
    LOAD_GLES_OES(glDrawTexf);
    LOAD_GLES(glEnable);
    LOAD_GLES(glDisable);
    #else
    LOAD_GLES(glEnableClientState);
    LOAD_GLES(glDisableClientState);
    LOAD_GLES(glVertexPointer);
    LOAD_GLES(glTexCoordPointer);
	LOAD_GLES(glDrawArrays);
    #endif
    LOAD_GLES(glBindTexture);
    LOAD_GLES(glActiveTexture);
    LOAD_GLES(glClientActiveTexture);
    
	if (rast->texture) {
		GLuint old_tex = glstate->texture.active;
		if (old_tex!=0) gles_glActiveTexture(GL_TEXTURE0);
		GLuint old_cli = glstate->texture.client;
		if (old_cli!=0) gles_glClientActiveTexture(GL_TEXTURE0);
        #ifdef USE_DRAWTEX
        gl4es_glPushAttrib(GL_ENABLE_BIT | GL_COLOR_BUFFER_BIT | GL_CURRENT_BIT);
        
        gltexture_t *old_bind = glstate->texture.bound[0][ENABLED_TEX2D];
        gl4es_glEnable(GL_TEXTURE_2D);
		gles_glBindTexture(GL_TEXTURE_2D, rast->texture);

		if (rast->bitmap) {
			gl4es_glEnable(GL_ALPHA_TEST);
			gl4es_glAlphaFunc(GL_GREATER, 0.0f);
		} else {
			gl4es_glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		}
        
        gles_glDrawTexf(glstate->raster.rPos.x-rast->xorig, glstate->raster.rPos.y-rast->yorig, glstate->raster.rPos.z, rast->width * rast->zoomx, rast->height * rast->zoomy);
        if (!IS_TEX2D(glstate->enable.texture[0])) gl4es_glDisable(GL_TEXTURE_2D);
		if (old_tex!=0) gles_glActiveTexture(GL_TEXTURE0+old_tex);
		if (old_cli!=0) gles_glClientActiveTexture(GL_TEXTURE0+old_cli);
        if (old_bind == NULL) 
            gles_glBindTexture(GL_TEXTURE_2D, 0);
        else
            gles_glBindTexture(GL_TEXTURE_2D, old_bind->glname);
        #else
		gl4es_glPushAttrib(GL_TEXTURE_BIT | GL_ENABLE_BIT | GL_TRANSFORM_BIT | GL_COLOR_BUFFER_BIT | GL_CURRENT_BIT);
		GLfloat old_projection[16], old_modelview[16], old_texture[16];

		gl4es_glGetFloatv(GL_TEXTURE_MATRIX, old_texture);
		gl4es_glGetFloatv(GL_PROJECTION_MATRIX, old_projection);
		gl4es_glGetFloatv(GL_MODELVIEW_MATRIX, old_modelview);
		gl4es_glMatrixMode(GL_TEXTURE);
		gl4es_glLoadIdentity();
		gl4es_glMatrixMode(GL_PROJECTION);
		gl4es_glLoadIdentity();
		gl4es_glMatrixMode(GL_MODELVIEW);
		gl4es_glLoadIdentity();
		float w2 = 2.0f / glstate->raster.viewport.width;
		float h2 = 2.0f / glstate->raster.viewport.height;
		float raster_x1=glstate->raster.rPos.x-rast->xorig;
		float raster_x2=glstate->raster.rPos.x-rast->xorig + rast->width * rast->zoomx ;
		float raster_y1=glstate->raster.rPos.y-rast->yorig;
		float raster_y2=glstate->raster.rPos.y-rast->yorig + rast->height * rast->zoomy ;
		GLfloat rast_vert[] = {
			raster_x1*w2-1.0f, raster_y1*h2-1.0f,
			raster_x2*w2-1.0f, raster_y1*h2-1.0f,
			raster_x2*w2-1.0f, raster_y2*h2-1.0f,
			raster_x1*w2-1.0f, raster_y2*h2-1.0f
		};
		float sw = rast->width / (GLfloat)npot(rast->width);
		float sh = rast->height / (GLfloat)npot(rast->height);
		GLfloat rast_tex[] = {
			0, 0,
			sw, 0,
			sw, sh,
			0, sh
		};

		gl4es_glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT | GL_CLIENT_PIXEL_STORE_BIT);

		gl4es_glDisable(GL_DEPTH_TEST);
		gl4es_glDisable(GL_LIGHTING);
		gl4es_glDisable(GL_CULL_FACE);
		if (rast->bitmap) {
			gl4es_glEnable(GL_ALPHA_TEST);
			gl4es_glAlphaFunc(GL_GREATER, 0.0f);
		} else {
			gl4es_glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		}

		gl4es_glEnable(GL_TEXTURE_2D);
		gles_glBindTexture(GL_TEXTURE_2D, rast->texture);
		gl4es_glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

        if(!glstate->clientstate.vertex_array) 
        {
            gles_glEnableClientState(GL_VERTEX_ARRAY);
            glstate->clientstate.vertex_array = 1;
        }
		gles_glVertexPointer(2, GL_FLOAT, 0, rast_vert);
        if(!glstate->clientstate.tex_coord_array[0]) 
        {
            gles_glEnableClientState(GL_TEXTURE_COORD_ARRAY);
            glstate->clientstate.tex_coord_array[0] = 1;
        }
		gles_glTexCoordPointer(2, GL_FLOAT, 0, rast_tex);
        for (int a=1; a <MAX_TEX; a++)
            if(glstate->clientstate.tex_coord_array[a]) {
                gles_glClientActiveTexture(GL_TEXTURE0 + a);
                gles_glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                glstate->clientstate.tex_coord_array[a] = 0;
                gles_glClientActiveTexture(GL_TEXTURE0);
            }
        if(glstate->clientstate.color_array) {
            gles_glDisableClientState(GL_COLOR_ARRAY);
            glstate->clientstate.color_array = 0;
        }
        if(glstate->clientstate.normal_array) {
            gles_glDisableClientState(GL_NORMAL_ARRAY);
            glstate->clientstate.normal_array = 0;
        }


		//glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		
		gles_glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
		// All the previous states are Pushed / Poped anyway...
		if (old_tex!=0) gles_glActiveTexture(GL_TEXTURE0+old_tex);
		if (old_cli!=0) gles_glClientActiveTexture(GL_TEXTURE0+old_cli);
		gl4es_glPopClientAttrib();
		gl4es_glMatrixMode(GL_TEXTURE);
		gl4es_glLoadMatrixf(old_texture);
		gl4es_glMatrixMode(GL_MODELVIEW);
		gl4es_glLoadMatrixf(old_modelview);
		gl4es_glMatrixMode(GL_PROJECTION);
		gl4es_glLoadMatrixf(old_projection);
        #endif
		gl4es_glPopAttrib();
	}
	glstate->raster.rPos.x += rast->xmove;
	glstate->raster.rPos.y += rast->ymove;
}

//Direct wrapper
void glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap) AliasExport("gl4es_glBitmap");
void glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *data) AliasExport("gl4es_glDrawPixels");
void glRasterPos3f(GLfloat x, GLfloat y, GLfloat z) AliasExport("gl4es_glRasterPos3f");
void glWindowPos3f(GLfloat x, GLfloat y, GLfloat z) AliasExport("gl4es_glWindowPos3f");
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) AliasExport("gl4es_glViewport");
void glPixelZoom(GLfloat xfactor, GLfloat yfactor) AliasExport("gl4es_glPixelZoom");
void glPixelTransferf(GLenum pname, GLfloat param) AliasExport("gl4es_glPixelTransferf");
