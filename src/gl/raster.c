#include "raster.h"

rasterpos_t rPos = {0, 0, 0};
viewport_t viewport = {0, 0, 0, 0};
GLubyte *raster = NULL;
GLfloat zoomx=1.0f;
GLfloat zoomy=1.0f;
GLuint raster_texture=0;
GLsizei raster_width=0;
GLsizei raster_height=0;

GLint	raster_x1, raster_x2, raster_y1, raster_y2;
#define min(a, b)	((a)<b)?(a):(b)
#define max(a, b)	((a)>(b))?(a):(b)
GLfloat raster_scale[4] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat raster_bias[4] = {0.0f, 0.0f, 0.0f, 0.0f};

extern void matrix_column_row(const GLfloat *a, GLfloat *b);
extern void matrix_vector(const GLfloat *a, const GLfloat *b, GLfloat *c);

void glRasterPos3f(GLfloat x, GLfloat y, GLfloat z) {
    if ((state.list.compiling || state.gl_batch) && state.list.active) {
        NewStage(state.list.active, STAGE_RASTER);
        rlRasterOp(state.list.active, 1, x, y, z);
        noerrorShim();
        return;
    }
	#if 1
	// Transform xyz coordinates with currzent modelview and projection matrix...
	GLfloat glmatrix[16], projection[16], modelview[16];
	GLfloat t[3], transl[3] = {x, y, z};
	glGetFloatv(GL_PROJECTION_MATRIX, glmatrix);
	matrix_column_row(glmatrix, projection);
	glGetFloatv(GL_MODELVIEW_MATRIX, glmatrix);
	matrix_column_row(glmatrix, modelview);
	matrix_vector(modelview, transl, t);
	matrix_vector(projection, t, transl);
	GLfloat w2, h2;
	w2=viewport.width/2.0f;
	h2=viewport.height/2.0f;
	rPos.x = transl[0]*w2+w2;
	rPos.y = transl[1]*h2+h2;
	rPos.z = transl[2];

	#else
    rPos.x = x;
    rPos.y = y;
    rPos.z = z;
    #endif
}

void glWindowPos3f(GLfloat x, GLfloat y, GLfloat z) {
    if ((state.list.compiling || state.gl_batch) && state.list.active) {
        NewStage(state.list.active, STAGE_RASTER);
        rlRasterOp(state.list.active, 2, x, y, z);
        noerrorShim();
        return;
    }
    rPos.x = x;
    rPos.y = y;
    rPos.z = z;	
}

void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
    PUSH_IF_COMPILING(glViewport);
    LOAD_GLES(glViewport);
    gles_glViewport(x, y, width, height);
    viewport.x = x;
    viewport.y = y;
    viewport.width = width;
    viewport.height = height;
}

void glPixelZoom(GLfloat xfactor, GLfloat yfactor) {
    if ((state.list.compiling || state.gl_batch) && state.list.active) {
        NewStage(state.list.active, STAGE_RASTER);
        rlRasterOp(state.list.active, 3, xfactor, yfactor, 0.0f);
        noerrorShim();
        return;
    }
	zoomx = xfactor;
	zoomy = yfactor;
//printf("LIBGL: glPixelZoom(%f, %f)\n", xfactor, yfactor);
}

void glPixelTransferf(GLenum pname, GLfloat param) {
    if ((state.list.compiling || state.gl_batch) && state.list.active) {
        NewStage(state.list.active, STAGE_RASTER);
        rlRasterOp(state.list.active, pname|0x10000, param, 0.0f, 0.0f);
        noerrorShim();
        return;
    }
//printf("LIBGL: glPixelTransferf(%04x, %f)\n", pname, param);
	switch(pname) {
		case GL_RED_SCALE:
			raster_scale[0]=param;
			break;
		case GL_RED_BIAS:
			raster_bias[0]=param;
			break;
		case GL_GREEN_SCALE:
		case GL_BLUE_SCALE:
		case GL_ALPHA_SCALE:
			raster_scale[(pname-GL_GREEN_SCALE)/2+1]=param;
			break;
		case GL_GREEN_BIAS:
		case GL_BLUE_BIAS:
		case GL_ALPHA_BIAS:
			raster_bias[(pname-GL_GREEN_BIAS)/2+1]=param;
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
	a=a*raster_scale[number]+raster_bias[number];
	if (a<0.0) a=0.0;
	if (a>1.0) a=1.0;
	return (GLubyte)(a*255.0f);
}
GLfloat raster_transformf(GLfloat pix, GLubyte number) {
	pix=pix*raster_scale[number]+raster_bias[number];
	if (pix<0.0) pix=0.0;
	if (pix>1.0) pix=1.0;
	return pix;
}

int raster_need_transform() {
	for (int i=0; i<4; i++) if (raster_scale[i]!=1.0f) return 1;
	for (int i=0; i<4; i++) if (raster_bias[i]!=0.0f) return 1;
	return 0;
}

GLuint raster_to_texture()
{
    LOAD_GLES(glGenTextures);
    LOAD_GLES(glBindTexture);
    LOAD_GLES(glTexEnvf);
    LOAD_GLES(glTexImage2D);
    LOAD_GLES(glActiveTexture);
    
	renderlist_t *old_list = state.list.active;
	if (old_list) state.list.active = NULL;		// deactivate list...
	GLboolean compiling = state.list.compiling;
    GLuint state_batch = state.gl_batch;
	state.list.compiling = false;
    state.gl_batch = 0;
    glPushAttrib(GL_TEXTURE_BIT | GL_ENABLE_BIT );
	GLuint old_tex_unit, old_tex;
	glGetIntegerv(GL_ACTIVE_TEXTURE, &old_tex_unit);
	if (old_tex_unit!=GL_TEXTURE0) glActiveTexture(GL_TEXTURE0);
	old_tex = 0;
	if (state.texture.bound[0])
		old_tex = state.texture.bound[0]->texture;
	GLuint raster_texture;
	glEnable(GL_TEXTURE_2D);
	gles_glGenTextures(1, &raster_texture);
	gles_glBindTexture(GL_TEXTURE_2D, raster_texture);

    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
    glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
    glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	gles_glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, raster_width, raster_height,
		0, GL_RGBA, GL_UNSIGNED_BYTE, raster);

	gles_glBindTexture(GL_TEXTURE_2D, old_tex);
	if (old_tex_unit!=GL_TEXTURE0) 
		glActiveTexture(old_tex_unit);
	glPopAttrib();
	if (old_list) state.list.active = old_list;
	state.list.compiling = compiling;
    state.gl_batch = state_batch;
	return raster_texture;
}

void glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig,
              GLfloat xmove, GLfloat ymove, const GLubyte *bitmap) {
/*printf("glBitmap, xy={%f, %f}, xyorig={%f, %f}, size={%u, %u}, zoom={%f, %f}, viewport={%i, %i, %i, %i}\n", 	
	rPos.x, rPos.y, xorig, yorig, width, height, zoomx, zoomy, viewport.x, viewport.y, viewport.width, viewport.height);*/
    // TODO: shouldn't be drawn if the raster pos is outside the viewport?
    // TODO: negative width/height mirrors bitmap?
    noerrorShim();
    if ((!width && !height) || (bitmap==0)) {
		if (state.list.compiling || state.gl_batch) {
			if (state.list.active->raster)
				state.list.active = extend_renderlist(state.list.active);		// already a raster in the list, create a new one
			rasterlist_t *r = state.list.active->raster = (rasterlist_t*)malloc(sizeof(rasterlist_t));
			r->texture = 0;
			r->xorig = 0;
			r->yorig = 0;
			r->zoomx = 1.0f;
			r->zoomy = 1.0f;
			r->xmove = xmove;
			r->ymove = ymove;
			
		} else {
			rPos.x += xmove;
			rPos.y += ymove;
		}
        return;
    }

    init_raster(width, height);
    const GLubyte *from;
    GLubyte *to;
    int x, y;
	int pixtrans=raster_need_transform();
	
    // copy to pixel data
    for (y = 0; y < height; y++) {
        to = raster + 4 * (GLint)(y * raster_width);
        from = bitmap + (y * ((width+7)/8));
        for (x = 0; x < width; x++) {
            // TODO: wasteful, unroll this?
            GLubyte b = from[(x / 8)];
            int p = (b & (1 << (7 - (x % 8)))) ? 255 : 0;
            // r, g, b, a
            //p = (p ? 255 : 0);
			if (pixtrans) {
				*to++ = raster_transform(p, 0);
				*to++ = raster_transform(p, 1);
				*to++ = raster_transform(p, 2);
				*to++ = raster_transform(p, 3);
			} else {
				*to++ = p;
				*to++ = p;
				*to++ = p;
				*to++ = p;
			}
        }
    }

    rasterlist_t rast;
    rasterlist_t *r;
	if (state.list.compiling || state.gl_batch) {
		NewStage(state.list.active, STAGE_RASTER);
/*		if (state.list.active->raster)
			state.list.active = extend_renderlist(state.list.active);*/		// already a raster in the list, create a new one
		r = state.list.active->raster = (rasterlist_t*)malloc(sizeof(rasterlist_t));
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
	r->zoomx = zoomx;
	r->zoomy = zoomy;
    LOAD_GLES(glDeleteTextures);
	if (!(state.list.compiling || state.gl_batch)) {
		render_raster_list(r);
		gles_glDeleteTextures(1, &r->texture);
		r->texture = 0;
	}
}

void glDrawPixels(GLsizei width, GLsizei height, GLenum format,
                  GLenum type, const GLvoid *data) {
    GLubyte *pixels, *from, *to;
    GLvoid *dst = NULL;
    noerrorShim();
/*printf("glDrawPixels, xy={%f, %f}, size={%i, %i}, format=%04x, type=%04x, zoom={%f, %f}, viewport={%i, %i, %i, %i}\n", 	
	rPos.x, rPos.y, width, height, format, type, zoomx, (zoominversey)?-zoomy:zoomy, viewport.x, viewport.y, viewport.width, viewport.height);*/
	// check of unsuported format...
	if ((format == GL_STENCIL_INDEX) || (format == GL_DEPTH_COMPONENT)) {
        errorShim(GL_INVALID_ENUM);
		return;
    }

    init_raster(width, height);

	GLsizei bmp_width = (state.texture.unpack_row_length)?state.texture.unpack_row_length:width;

    if (! pixel_convert(data, &dst, bmp_width, height,
                        format, type, GL_RGBA, GL_UNSIGNED_BYTE, 0)) {
        return;
    }
					  
    pixels = (GLubyte *)dst;
	GLint vx, vy;
	int pixtrans=raster_need_transform();

	for (int y = 0; y < height; y++) {
		to = raster + 4 * (GLint)(y * raster_width);
		from = pixels + 4 * (state.texture.unpack_skip_pixels + (y + state.texture.unpack_skip_rows) * bmp_width);
		for (int x = 0; x < width; x++) {
			if (pixtrans) {
				*to++ = raster_transform(*from++, 0);
				*to++ = raster_transform(*from++, 1);
				*to++ = raster_transform(*from++, 2);
				*to++ = raster_transform(*from++, 3);
			} else {
				*to++ = *from++;
				*to++ = *from++;
				*to++ = *from++;
				*to++ = *from++;
			}
		}
	}
	if (pixels != data)
        free(pixels);
	
    rasterlist_t rast;
    rasterlist_t *r;
	if (state.list.compiling || gl_batch) {
		NewStage(state.list.active, STAGE_RASTER);
/*		if (state.list.active->raster)
			state.list.active = extend_renderlist(state.list.active);*/		// already a raster in the list, create a new one
		rasterlist_t *r = state.list.active->raster = (rasterlist_t*)malloc(sizeof(rasterlist_t));
	} else {
		r = &rast;
	}
	r->texture = raster_to_texture(width, height);
	r->xmove = 0;
	r->ymove = 0;
	r->xorig = 0;
	r->yorig = 0;
	r->width = width;
	r->height = height;
	r->bitmap = false;
	r->zoomx = zoomx;
	r->zoomy = zoomy;
    LOAD_GLES(glDeleteTextures);
	if (!(state.list.compiling || state.gl_batch)) {
		render_raster_list(r);
		gles_glDeleteTextures(1, &r->texture);
		r->texture = 0;
	}
}

void render_raster_list(rasterlist_t* rast) {
//printf("render_raster_list, rast->width=%i, rast->height=%i, rPos.x=%f, rPos.y=%f, raster->texture=%u\n", rast->width, rast->height, rPos.x, rPos.y, rast->texture);
    LOAD_GLES(glEnableClientState);
    LOAD_GLES(glDisableClientState);
    LOAD_GLES(glBindTexture);
    LOAD_GLES(glVertexPointer);
    LOAD_GLES(glTexCoordPointer);
	LOAD_GLES(glDrawArrays);
    
	if (rast->texture) {
		glPushAttrib(GL_TEXTURE_BIT | GL_ENABLE_BIT | GL_TRANSFORM_BIT | GL_COLOR_BUFFER_BIT | GL_CURRENT_BIT);
		GLfloat old_projection[16], old_modelview[16], old_texture[16];

		GLuint old_tex = state.texture.active;
		if (old_tex!=0) glActiveTexture(GL_TEXTURE0);
		GLuint old_cli = state.texture.client;
		if (old_cli!=0) glClientActiveTexture(GL_TEXTURE0);
		glMatrixMode(GL_TEXTURE);
		glGetFloatv(GL_TEXTURE_MATRIX, old_texture);
		glLoadIdentity();
		glMatrixMode(GL_PROJECTION);
		glGetFloatv(GL_PROJECTION_MATRIX, old_projection);
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);
		glGetFloatv(GL_MODELVIEW_MATRIX, old_modelview);
		glLoadIdentity();
		float w2 = viewport.width / 2.0f;
		float h2 = viewport.height / 2.0f;
		float raster_x1=rPos.x-rast->xorig;
		float raster_x2=rPos.x-rast->xorig + rast->width * rast->zoomx ;
		float raster_y1=rPos.y-rast->yorig;
		float raster_y2=rPos.y-rast->yorig + rast->height * rast->zoomy ;
		GLfloat vert[] = {
			(raster_x1-w2)/w2, (raster_y1-h2)/h2, 0,
			(raster_x2-w2)/w2, (raster_y1-h2)/h2, 0,
			(raster_x2-w2)/w2, (raster_y2-h2)/h2, 0,
			(raster_x1-w2)/w2, (raster_y2-h2)/h2, 0,
		};
		float sw = rast->width / (GLfloat)npot(rast->width);
		float sh = rast->height / (GLfloat)npot(rast->height);
		GLfloat tex[] = {
			0, 0,
			sw, 0,
			sw, sh,
			0, sh
		};

		glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT | GL_CLIENT_PIXEL_STORE_BIT);

		glDisable(GL_DEPTH_TEST);
		glDisable(GL_LIGHTING);
		glDisable(GL_CULL_FACE);
		if (rast->bitmap) {
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.0f);
		} else {
			glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		}

		glEnable(GL_TEXTURE_2D);
		gles_glBindTexture(GL_TEXTURE_2D, rast->texture);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

		gles_glEnableClientState(GL_VERTEX_ARRAY);
		gles_glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		gles_glDisableClientState(GL_COLOR_ARRAY);
		gles_glDisableClientState(GL_NORMAL_ARRAY);
		gles_glVertexPointer(3, GL_FLOAT, 0, vert);
		gles_glTexCoordPointer(2, GL_FLOAT, 0, tex);


		//glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		
		gles_glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
		// All the previous states are Pushed / Poped anyway...
		if (old_tex!=0) glActiveTexture(GL_TEXTURE0+old_tex);
		if (old_cli!=0) glClientActiveTexture(GL_TEXTURE0+old_cli);
		glPopClientAttrib();
		glMatrixMode(GL_TEXTURE);
		glLoadMatrixf(old_texture);
		glMatrixMode(GL_MODELVIEW);
		glLoadMatrixf(old_modelview);
		glMatrixMode(GL_PROJECTION);
		glLoadMatrixf(old_projection);
		glPopAttrib();
	}
	rPos.x += rast->xmove;
	rPos.y += rast->ymove;
}
