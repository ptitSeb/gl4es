#include "raster.h"

#define slow_raster

rasterpos_t rPos = {0, 0, 0};
viewport_t viewport = {0, 0, 0, 0};
GLubyte *raster = NULL;
GLfloat zoomx=1.0f;
GLfloat zoomy=1.0f;
#ifdef slow_raster
GLuint raster_texture=0;
GLsizei raster_width=0;
GLsizei raster_height=0;
GLint	raster_x1, raster_x2, raster_y1, raster_y2;
#define min(a, b)	((a)<b)?(a):(b)
#define max(a, b)	((a)>(b))?(a):(b)
#endif
GLfloat raster_scale[4] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat raster_bias[4] = {0.0f, 0.0f, 0.0f, 0.0f};

/* raster engine:
    we render pixels to memory somewhere
    until someone else wants to use the framebuffer
    then we throw 'em quickly into a texture, render to the whole screen
    then let the other function do their thing
*/

void glRasterPos3f(GLfloat x, GLfloat y, GLfloat z) {
    rPos.x = x;
    rPos.y = y;
    rPos.z = z;
}

void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
    PUSH_IF_COMPILING(glViewport);
    LOAD_GLES(glViewport);
    if (raster) {
        render_raster();
    }
    gles_glViewport(x, y, width, height);
    viewport.x = x;
    viewport.y = y;
    viewport.width = width;
    viewport.height = height;
}

void glPixelZoom(GLfloat xfactor, GLfloat yfactor) {
	zoomx = xfactor;
	zoomy = yfactor;
//printf("LIBGL: glPixelZoom(%f, %f)\n", xfactor, yfactor);
}

void glPixelTransferf(GLenum pname, GLfloat param) {
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


void init_raster() {
    if (!viewport.width || !viewport.height) {
        glGetIntegerv(GL_VIEWPORT, (GLint *)&viewport);
    }
#ifdef slow_raster
	if ((raster_texture==0) || ((raster_width!=npot(viewport.width)) || (raster_height!=npot(viewport.height)))) {
		renderlist_t *old_list = state.list.active;
		if (old_list) state.list.active = NULL;		// deactivate list...
		glPushAttrib(GL_TEXTURE_BIT | GL_ENABLE_BIT);
		GLuint old_tex;
		glGetIntegerv(GL_ACTIVE_TEXTURE, &old_tex);
		if (old_tex!=GL_TEXTURE0) glActiveTexture(GL_TEXTURE0);
		if (raster_texture==0) {
			glGenTextures(1, &raster_texture);
		}
		glBindTexture(GL_TEXTURE_2D, raster_texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, npot(viewport.width), npot(viewport.height),
			0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
		raster_width=npot(viewport.width);
		raster_height=npot(viewport.height);
		if (old_tex!=GL_TEXTURE0) glActiveTexture(old_tex);
		glPopAttrib();
		if (old_list) state.list.active = old_list;
	}
#endif
    if (!raster) {
        raster = (GLubyte *)malloc(4 * viewport.width * viewport.height * sizeof(GLubyte));
		memset(raster, 0, 4 * viewport.width * viewport.height * sizeof(GLubyte));
#ifdef slow_raster
		raster_x1 = viewport.width; raster_y1 = viewport.height; raster_x2 = 0; raster_y2 = 0;
#endif
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

int in_viewport(GLint x, GLint y) {
	if ((x<0) || (y<0)) return 0;
	if ((x>=viewport.width) || (y>=viewport.height)) return 0;
	return 1;
}

void glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig,
              GLfloat xmove, GLfloat ymove, const GLubyte *bitmap) {
/*printf("glBitmap, xy={%f, %f}, xyorig={%i, %i}, size={%i, %i}, zoom={%f, %f}, viewport={%i, %i, %i, %i}\n", 	
	rPos.x, rPos.y, xorig, yorig, width, height, zoomx, zoomy, viewport.x, viewport.y, viewport.width, viewport.height);*/
    // TODO: shouldn't be drawn if the raster pos is outside the viewport?
    // TODO: negative width/height mirrors bitmap?
    if ((!width && !height) || (bitmap==0)) {
        rPos.x += xmove;
        rPos.y -= ymove;
        return;
    }
    init_raster();

    const GLubyte *from;
    GLubyte *to;
    int x, y;
	int pixtrans=raster_need_transform();
	
    // copy to pixel data
    // TODO: strip blank lines and mirror vertically?
    for (y = 0; y < height; y++) {
        to = raster + 4 * (GLint)(rPos.x + ((viewport.height-(rPos.y + y)) * viewport.width));
        from = bitmap + (y * 2);
        for (x = 0; x < (width + 7 / 8); x++) {
//            if (rPos.x + x > viewport.width || rPos.y + y > viewport.height)
			if (!in_viewport((GLint)rPos.x+x, (GLint)(viewport.height-(rPos.y+y))))
                continue;
            // TODO: wasteful, unroll this?
            GLubyte b = from[(x / 8)];
            int p = (b & (1 << (7 - (x % 8)))) ? 1 : 0;
            // r, g, b, a
            p = (p ? 255 : 0);
			if (pixtrans) {
				*to++ = raster_transform(p*state.color[0], 0);
				*to++ = raster_transform(p*state.color[1], 1);
				*to++ = raster_transform(p*state.color[2], 2);
				*to++ = raster_transform(p*state.color[3], 3);
			} else {
				*to++ = p*state.color[0];
				*to++ = p*state.color[1];
				*to++ = p*state.color[2];
				*to++ = p*state.color[3];
			}
        }
    }

#ifdef slow_raster
	raster_x1=min(raster_x1, rPos.x);
	raster_y1=min(raster_y1, rPos.y);
	raster_x2=max(raster_x2, rPos.x+viewport.width);
	raster_y2=max(raster_y2, rPos.y+viewport.height);
	// Does Bitmap use default Blender (I think)
	render_raster();
#endif
    rPos.x += xmove;
    rPos.y += ymove;
}

void glDrawPixels(GLsizei width, GLsizei height, GLenum format,
                  GLenum type, const GLvoid *data) {
    GLubyte *pixels, *from, *to;
    GLvoid *dst = NULL;
/*printf("glDrawPixels, xy={%f, %f}, size={%i, %i}, format=%04x, type=%04x, zoom={%f, %f}, viewport={%i, %i, %i, %i}\n", 	
	rPos.x, rPos.y, width, height, format, type, zoomx, zoomy, viewport.x, viewport.y, viewport.width, viewport.height);*/
	// check of unsuported format...
	if ((format == GL_STENCIL_INDEX) || (format == GL_DEPTH_COMPONENT))
		return;

    init_raster();

	GLsizei bmp_width = (state.texture.unpack_row_length)?state.texture.unpack_row_length:width;

    if (! pixel_convert(data, &dst, bmp_width, height,
                        format, type, GL_RGBA, GL_UNSIGNED_BYTE)) {
        return;
    }
					  
    pixels = (GLubyte *)dst;
	GLint vx, vy;
	int pixtrans=raster_need_transform();

	if ((zoomx==1.0f) && (zoomy==1.0f)) {
		for (int y = 0; y < height; y++) {
#ifdef slow_raster
			to = raster + 4 * (GLint)(rPos.x + ((rPos.y + y) * viewport.width));
#else
			to = raster + 4 * (GLint)(rPos.x + ((viewport.height - (rPos.y + y)) * viewport.width));
#endif
			from = pixels + 4 * (state.texture.unpack_skip_pixels + (y + state.texture.unpack_skip_rows) * bmp_width);
			for (int x = 0; x < width; x++) {
#ifdef slow_raster
				if (in_viewport((GLint)rPos.x+x, (GLint)(rPos.y+y))) {
#else
				if (in_viewport((GLint)rPos.x+x, (GLint)(viewport.height - (rPos.y+y)))) {
#endif
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
				} else {
					to+=4;
					from+=4;
				}
			}
		}
	} else {
		for (int y = 0; y < height; y++) {
			from = pixels + 4 * (y * bmp_width);
			for (int x = 0; x < width; x++) {
				to = raster + 4 * (GLint)(rPos.x + x*zoomx + ((rPos.y - y*zoomy) * viewport.width));	//not perfect here !
				*to++ = *from++;
				*to++ = *from++;
				*to++ = *from++;
				*to++ = *from++;
			}
		}
	}
	if (pixels != data)
        free(pixels);
	
#ifdef slow_raster
	raster_x1=min(raster_x1, rPos.x);
	raster_y1=min(raster_y1, rPos.y);
	raster_x2=max(raster_x2, rPos.x+width);
	raster_y2=max(raster_y2, rPos.y+height);
	render_raster();
#endif
}

void render_raster() {
    if (!viewport.width || !viewport.height || !raster)
        return;
#ifdef slow_raster
	if ((raster_x1>raster_x2) || (raster_y1>raster_y2)) {
		return;
	}
#endif
// FIXME
#ifndef USE_ES2
    glPushAttrib(GL_TEXTURE_BIT | GL_ENABLE_BIT | GL_TRANSFORM_BIT);
	GLfloat old_projection[16], old_modelview[16];
    glMatrixMode(GL_PROJECTION);
	glGetFloatv(GL_PROJECTION_MATRIX, old_projection);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
	glGetFloatv(GL_MODELVIEW_MATRIX, old_modelview);
    glLoadIdentity();
#ifdef slow_raster
    float w2 = viewport.width / 2.0f;
    float h2 = viewport.height / 2.0f;
	raster_x1=max(0, raster_x1);
	raster_x2=min(viewport.width, raster_x2);
	raster_y1=max(0, raster_y1);
	raster_y2=min(viewport.height, raster_y2);

    GLfloat vert[] = {
        (raster_x1-w2)/w2, (raster_y1-h2)/h2, 0,
        (raster_x2-w2)/w2, (raster_y1-h2)/h2, 0,
        (raster_x2-w2)/w2, (raster_y2-h2)/h2, 0,
        (raster_x1-w2)/w2, (raster_y2-h2)/h2, 0,
    };
    float sw = 1 / (GLfloat)npot(viewport.width);
    float sh = 1 / (GLfloat)npot(viewport.height);
	float y1 = /*viewport.height-*/raster_y1;
	float y2 = /*viewport.height-*/raster_y2;
    GLfloat tex[] = {
        raster_x1*sw, y1*sh,
        raster_x2*sw, y1*sh,
        raster_x2*sw, y2*sh,
        raster_x1*sw, y2*sh
    };
#else
    GLfloat vert[] = {
        -1, -1, 0,
        1, -1, 0,
        1, 1, 0,
        -1, 1, 0,
    };
    float sw = viewport.width / (GLfloat)npot(viewport.width);
    float sh = viewport.height / (GLfloat)npot(viewport.height);

    GLfloat tex[] = {
        0, sh,
        sw, sh,
        sw, 0,
        0, 0,
    };
#endif

    glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT | GL_CLIENT_PIXEL_STORE_BIT);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_NORMAL_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vert);
    glTexCoordPointer(2, GL_FLOAT, 0, tex);


    glEnable(GL_TEXTURE_2D);
#ifdef slow_raster
    glBindTexture(GL_TEXTURE_2D, raster_texture);
#else
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
#endif

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
#ifndef slow_raster
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, npot(viewport.width), npot(viewport.height),
                 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
#endif
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, viewport.width, viewport.height,
                    GL_RGBA, GL_UNSIGNED_BYTE, raster);

	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	
    LOAD_GLES(glDrawArrays);
    gles_glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
#ifndef slow_raster
    glDeleteTextures(1, &texture);

 //   glDisable(GL_BLEND);
#endif
//    glDisable(GL_TEXTURE_2D);
//    glDisableClientState(GL_VERTEX_ARRAY);
//    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	// All the previous states are Pushed / Poped anyway...
    glPopClientAttrib();
    glMatrixMode(GL_MODELVIEW);
	glLoadMatrixf(old_modelview);
    glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(old_projection);
    glPopAttrib();
#endif
    free(raster);
    raster = NULL;
}
