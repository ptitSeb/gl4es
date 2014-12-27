#include "gl.h"
#include "list.h"

#define alloc_sublist(n, cap) \
    (GLfloat *)malloc(n * sizeof(GLfloat) * cap)

#define realloc_sublist(ref, n, cap) \
    if (ref)                         \
        ref = (GLfloat *)realloc(ref, n * sizeof(GLfloat) * cap)

static GLushort *cached_q2t = NULL;
static unsigned long cached_q2t_len = 0;

renderlist_t *alloc_renderlist() {
    renderlist_t *list = (renderlist_t *)malloc(sizeof(renderlist_t));
    list->len = 0;
    list->ilen = 0;
    list->cap = DEFAULT_RENDER_LIST_CAPACITY;

    list->calls.len = 0;
    list->calls.cap = 0;
    list->calls.calls = NULL;

    list->mode = 0;
    list->mode_init = 0;
    list->vert = NULL;
    list->normal = NULL;
    list->color = NULL;
    list->secondary = NULL;

    list->glcall_list = 0;
    list->raster = NULL;
    
    list->stage = STAGE_NONE;
    
    list->pushattribute = 0;
    list->popattribute = false;
    
    int a;
    for (a=0; a<MAX_TEX; a++)
       list->tex[a] = NULL;
    list->material = NULL;
    list->light = NULL;
    list->texgen = NULL;
    list->lightmodel = NULL;
    list->lightmodelparam = GL_LIGHT_MODEL_AMBIENT;
    list->indices = NULL;
    list->q2t = false;
    list->set_texture = false;
    list->texture = 0;
    list->polygon_mode = 0;
    
    list->prev = NULL;
    list->next = NULL;
    list->open = true;
    return list;
}

renderlist_t *extend_renderlist(renderlist_t *list) {
    renderlist_t *new = alloc_renderlist();
    list->next = new;
    new->prev = list;
    if (list->open)
        end_renderlist(list);
    return new;
}

void free_renderlist(renderlist_t *list) {
	// test if list is NULL
	if (list == NULL)
		return;
    // we want the first list in the chain
    while (list->prev)
        list = list->prev;

    renderlist_t *next;
    do {
        if (list->calls.len > 0) {
            for (int i = 0; i < list->calls.len; i++) {
                free(list->calls.calls[i]);
            }
            free(list->calls.calls);
        }
        if (list->vert) free(list->vert);
        if (list->normal) free(list->normal);
        if (list->color) free(list->color);
        if (list->secondary) free(list->secondary);
        int a;
        for (a=0; a<MAX_TEX; a++)
            if (list->tex[a]) free(list->tex[a]);
        if (list->material) {
            rendermaterial_t *m;
            kh_foreach_value(list->material, m,
                free(m);
            )
            kh_destroy(material, list->material);
        }
        if (list->light) {
            renderlight_t *m;
            kh_foreach_value(list->light, m,
                free(m);
            )
            kh_destroy(light, list->light);
        }
        if (list->texgen) {
            rendertexgen_t *m;
            kh_foreach_value(list->texgen, m,
                free(m);
            )
            kh_destroy(texgen, list->texgen);
        }
        if (list->lightmodel)
			free(list->lightmodel);
			
        if ((list->indices) && (!list->q2t)) 
			free(list->indices);
        
        if (list->raster) {
			if (list->raster->texture)
				glDeleteTextures(1, &list->raster->texture);
			free(list->raster);
		}

        next = list->next;
        free(list);
    } while ((list = next));
}

static inline
void resize_renderlist(renderlist_t *list) {
    if (list->len >= list->cap) {
        list->cap += DEFAULT_RENDER_LIST_CAPACITY;
        realloc_sublist(list->vert, 3, list->cap);
        realloc_sublist(list->normal, 3, list->cap);
        realloc_sublist(list->color, 4, list->cap);
        realloc_sublist(list->secondary, 4, list->cap);
        for (int a=0; a<MAX_TEX; a++)
           realloc_sublist(list->tex[a], 2, list->cap);
    }
}

void q2t_renderlist(renderlist_t *list) {
    if (!list->len || !list->vert || list->q2t) return;
    // TODO: split to multiple lists if list->len > 65535
    int a = 0, b = 1, c = 2, d = 3;
    int winding[6] = {
        a, b, d,
        b, c, d,
    };
    unsigned long len = list->len * 6 / 4;

    // q2t on glDrawElements?
	GLushort *old_indices = NULL;
	GLushort *indices;
    if (list->indices) 
		old_indices = list->indices;
    //    free(list->indices);
    if ((len > cached_q2t_len) || (old_indices)) {
		if (old_indices) {
			indices = malloc(len * sizeof(GLushort));
		} else {
			if (cached_q2t)
				free(cached_q2t);
			cached_q2t = malloc(len * sizeof(GLushort));
			cached_q2t_len = len;
		}
		int k = 0;
        for (int i = 0; i < list->len; i += 4) {
            for (int j = 0; j < 6; j++) {
				if (old_indices)
					indices[k+j] = old_indices[i + winding[j]];
				else
					cached_q2t[k+j] = i + winding[j];
            }
	    k += 6;
        }
    }

    if (!old_indices) {
//		list->indices = cached_q2t;
	    list->q2t = true;
    } else {
	    free(old_indices);
	    list->indices = indices;
    }

    list->ilen = len;
    return;
}

void end_renderlist(renderlist_t *list) {
    if (! list->open)
        return;

    list->stage = STAGE_LAST;
    list->open = false;
    for (int a=0; a<MAX_TEX; a++) {
	    gltexture_t *bound = state.texture.bound[a];
	    if ((list->tex[a]) && (bound) && ((bound->width != bound->nwidth) || (bound->height != bound->nheight))) {
		    tex_coord_npot(list->tex[a], list->len, bound->width, bound->height, bound->nwidth, bound->nheight);
	    }
	    // GL_ARB_texture_rectangle
	    if ((list->tex[a]) && state.texture.rect_arb[a] && (bound)) {
		    tex_coord_rect_arb(list->tex[a], list->len, bound->width, bound->height);
	    }
    }
    switch (list->mode) {
        case GL_QUADS:
			if (list->len==4) {
				list->mode = GL_TRIANGLE_FAN;
			} else {
				list->mode = GL_TRIANGLES;
				q2t_renderlist(list);
			}
            break;
        case GL_POLYGON:
            list->mode = GL_TRIANGLE_FAN;
            break;
        case GL_QUAD_STRIP:
            list->mode = GL_TRIANGLE_STRIP;
            break;
    }
}

void draw_renderlist(renderlist_t *list) {
    if (!list) return;
    LOAD_GLES(glDrawArrays);
    LOAD_GLES(glDrawElements);
#ifdef USE_ES2
    LOAD_GLES(glVertexAttribPointer);
#else
    LOAD_GLES(glVertexPointer);
    LOAD_GLES(glNormalPointer);
    LOAD_GLES(glColorPointer);
    LOAD_GLES(glTexCoordPointer);
#endif
    glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);

	GLfloat *final_colors;
	int old_tex;
    GLushort *indices;
    
    do {
        // push/pop attributes
        if (list->pushattribute)
            glPushAttrib(list->pushattribute);
        if (list->popattribute)
            glPopAttrib();
        // do call_list
        if (list->glcall_list)
            glCallList(list->glcall_list);
        // optimize zero-length segments out earlier?
        call_list_t *cl = &list->calls;
        if (cl->len > 0) {
            for (int i = 0; i < cl->len; i++) {
                glPackedCall(cl->calls[i]);
            }
        }
        old_tex = state.texture.active;
	    if (list->set_texture) {
		glBindTexture(list->target_texture, list->texture);
        }
        // raster
        if (list->raster) {
	    rasterlist_t * r = list->raster;
	    //glBitmap(r->width, r->height, r->xorig, r->yorig, r->xmove, r->ymove, r->raster);
	    render_raster_list(list->raster);
	}
			

        if (list->material) {
            khash_t(material) *map = list->material;
            rendermaterial_t *m;
            kh_foreach_value(map, m,
                switch (m->pname) {
                    case GL_SHININESS:
                        glMaterialf(GL_FRONT_AND_BACK,  m->pname, m->color[0]);
                        break;
                    default:
                        glMaterialfv(GL_FRONT_AND_BACK, m->pname, m->color);
                }
            )
        }
        if (list->light) {
            khash_t(light) *lig = list->light;
            renderlight_t *m;
            kh_foreach_value(lig, m,
                switch (m->pname) {
                    default:
                        glLightfv(m->which, m->pname, m->color);
                }
            )
        }
        if (list->lightmodel) {
            glLightModelfv(list->lightmodelparam, list->lightmodel);
        }
		
        if (list->texgen) {
            khash_t(texgen) *tgn = list->texgen;
            rendertexgen_t *m;
            kh_foreach_value(tgn, m,
                switch (m->pname) {
                    case GL_TEXTURE_GEN_MODE:
                    glTexGeni(m->coord, m->pname, m->color[0]);
                    break;
                    default:
                    glTexGenfv(m->coord, m->pname, m->color);
                }
            )
        }
        
        if (list->polygon_mode)
            glPolygonMode(GL_FRONT_AND_BACK, list->polygon_mode);

        if (! list->len)
            continue;

#ifdef USE_ES2
        if (list->vert) {
            glEnableVertexAttribArray(0);
            gles_glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, list->vert);
        }
        gles_glDrawArrays(list->mode, 0, list->len);
#else
        if (list->vert) {
            glEnableClientState(GL_VERTEX_ARRAY);
            gles_glVertexPointer(3, GL_FLOAT, 0, list->vert);
        } else {
            glDisableClientState(GL_VERTEX_ARRAY);
        }

        if (list->normal) {
            glEnableClientState(GL_NORMAL_ARRAY);
            gles_glNormalPointer(GL_FLOAT, 0, list->normal);
        } else {
            glDisableClientState(GL_NORMAL_ARRAY);
        }

        indices = list->indices;
        if (list->q2t && !(state.polygon_mode == GL_LINE))
            indices = cached_q2t;
           
		final_colors = NULL;
        if (list->color) {
            glEnableClientState(GL_COLOR_ARRAY);
            if (state.enable.color_sum && (list->secondary)) {
				final_colors=(GLfloat*)malloc(list->len * 4 * sizeof(GLfloat));
				if (indices) {
					for (int i=0; i<list->ilen; i++)
						for (int j=0; j<4; j++) {
							const int k=indices[i]*4+j;
							final_colors[k]=list->color[k] + list->secondary[k];
						}
				 } else {
					for (int i=0; i<list->len*4; i++)
						final_colors[i]=list->color[i] + list->secondary[i];
				}
				gles_glColorPointer(4, GL_FLOAT, 0, final_colors);
			} else
				gles_glColorPointer(4, GL_FLOAT, 0, list->color);
        } else {
            glDisableClientState(GL_COLOR_ARRAY);
        }
        GLuint texture;
        bool stipple;
        stipple = false;
        if (! list->tex[0]) {
            // TODO: do we need to support GL_LINE_STRIP?
            if (list->mode == GL_LINES && state.enable.line_stipple) {
                stipple = true;
                glPushAttrib(GL_COLOR_BUFFER_BIT | GL_ENABLE_BIT | GL_TEXTURE_BIT);
                glEnable(GL_BLEND);
                glEnable(GL_TEXTURE_2D);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE);
                list->tex[0] = gen_stipple_tex_coords(list->vert, list->len);
            } 
	}
	GLfloat *texgened[MAX_TEX];
	GLint needclean[MAX_TEX];
	for (int a=0; a<MAX_TEX; a++) {
		texgened[a]=NULL;
        needclean[a]=0;
		if ((state.enable.texgen_s[a] || state.enable.texgen_t[a] || state.enable.texgen_r[a])) {
		    gen_tex_coords(list->vert, list->normal, &texgened[a], list->len, &needclean[a], a, (list->ilen<list->len)?indices:NULL, (list->ilen<list->len)?list->ilen:0);
		} else if (state.enable.texture_2d[a] && (list->tex[a]==NULL)) {
		    gen_tex_coords(list->vert, list->normal, &texgened[a], list->len, &needclean[a], a, (list->ilen<list->len)?indices:NULL, (list->ilen<list->len)?list->ilen:0);
		}
    }
	old_tex = state.texture.client;
        for (int a=0; a<MAX_TEX; a++) {
		    if ((list->tex[a] || texgened[a])/* && state.enable.texture_2d[a]*/) {
                glClientActiveTexture(GL_TEXTURE0+a);
                glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		        gles_glTexCoordPointer(2, GL_FLOAT, 0, (texgened[a])?texgened[a]:list->tex[a]);
		    } else {
			if (state.enable.tex_coord_array[a]) {
			    glClientActiveTexture(GL_TEXTURE0+a);
			    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		    } 
//else if (!state.enable.texgen_s[a] && state.enable.texture_2d[a]) printf("LIBGL: texture_2d[%i] without TexCoord, mode=0x%04X (init=0x%04X), listlen=%i\n", a, list->mode, list->mode_init, list->len);
			    
		    }
        }
        if (state.texture.client != old_tex) glClientActiveTexture(GL_TEXTURE0+old_tex);

        GLenum mode;
        mode = list->mode;
        if ((state.polygon_mode == GL_LINE) && (mode>=GL_TRIANGLES))
			mode = GL_LINE_LOOP;
		if ((state.polygon_mode == GL_POINT) && (mode>=GL_TRIANGLES))
			mode = GL_POINTS;

        if (indices) {
            if (state.render_mode == GL_SELECT) {			
                select_glDrawElements(list->mode, list->len, GL_UNSIGNED_SHORT, indices);
            } else {
                if (state.polygon_mode == GL_LINE && list->mode_init>=GL_TRIANGLES) {
                    int n, s;
                    GLushort ind_line[list->ilen*3+1];
                    switch (list->mode_init) {
                        case GL_TRIANGLES:
                            n = 3;
                            s = 3;
                            break;
                        case GL_TRIANGLE_STRIP:
                            n = 3;
                            s = 1;
                            break;
                        case GL_TRIANGLE_FAN:	// wrong here...
                            n = list->ilen;
                            s = list->ilen;
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
                            n = list->ilen;
                            s = list->ilen;
                            break;
                    }
                    int k = 0;
					for (int i=n; i<=list->ilen; i+=s) {
						memcpy(ind_line+k, indices+i-n, sizeof(GLushort)*n);
						k+=n;
					}
					//gles_glDrawElements(mode, n, GL_UNSIGNED_SHORT, indices+i-n);
					gles_glDrawElements(mode, k, GL_UNSIGNED_SHORT, ind_line);
                } else {
                    gles_glDrawElements(mode, list->ilen, GL_UNSIGNED_SHORT, indices);
                }
            }
        } else {
            if (state.render_mode == GL_SELECT) {	
                select_glDrawArrays(list->mode, 0, list->len);
            } else {
                int len = list->len;
                if ((state.polygon_mode == GL_LINE) && (list->mode_init>=GL_TRIANGLES)) {
                    int n, s;
                    if (list->q2t)
                    len = len*4/6;
                    GLushort ind_line[len*3+1];
                    switch (list->mode_init) {
                    case GL_TRIANGLES:
                        n = 3;
                        s = 3;
                        break;
                    case GL_TRIANGLE_STRIP:
                        n = 3;
                        s = 1;
                        break;
                    case GL_TRIANGLE_FAN:	// wrong here...
                        n = len;
                        s = len;
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
                        n = len;
                        s = len;
                        break;
                    }
                    int k=0;
                    for (int i=n; i<=len; i+=s)
						for (int j=0; j<n; j++)
							ind_line[k++]=i-n+j;
                    //gles_glDrawArrays(mode, i-n, n);
					gles_glDrawElements(mode, k, GL_UNSIGNED_SHORT, ind_line);
                } else {
                    gles_glDrawArrays(mode, 0, len);
                }
            }
        }
        for (int a=0; a<MAX_TEX; a++) {
            if (needclean[a])
                gen_tex_clean(needclean[a], a);
			if (texgened[a]) {
				free(texgened[a]);
				texgened[a] = NULL;
			}
		}
		if (final_colors)
			free(final_colors);
        if (stipple) {
            glPopAttrib();
        }
#endif
    } while ((list = list->next));
    glPopClientAttrib();
}

// gl function wrappers

void rlVertex3f(renderlist_t *list, GLfloat x, GLfloat y, GLfloat z) {
    if (list->vert == NULL) {
        list->vert = alloc_sublist(3, list->cap);
    } else {
        resize_renderlist(list);
    }

    if (list->normal) {
        GLfloat *normal = list->normal + (list->len * 3);
        memcpy(normal, list->lastNormal, sizeof(GLfloat) * 3);
    }

    if (list->color) {
        GLfloat *color = list->color + (list->len * 4);
        memcpy(color, state.color, sizeof(GLfloat) * 4);
    }

    if (list->secondary) {
        GLfloat *secondary = list->secondary + (list->len * 4);
        memcpy(secondary, state.secondary, sizeof(GLfloat) * 4);
    }

    for (int a=0; a<MAX_TEX; a++) {
		if (list->tex[a]) {
			GLfloat *tex = list->tex[a] + (list->len * 2);
			memcpy(tex, state.texcoord[a], sizeof(GLfloat) * 2);
		}
    }

    GLfloat *vert = list->vert + (list->len++ * 3);
    vert[0] = x; vert[1] = y; vert[2] = z;
}

void rlNormal3f(renderlist_t *list, GLfloat x, GLfloat y, GLfloat z) {
    if (list->normal == NULL) {
        list->normal = alloc_sublist(3, list->cap);
        // catch up
        int i;
        if (list->len) for (i = 0; i < list->len-1; i++) {
            GLfloat *normal = (list->normal + (i * 3));
            memcpy(normal, list->lastNormal, sizeof(GLfloat) * 3);
        }
    } else {
        resize_renderlist(list);
    }
    
    GLfloat *normal = list->lastNormal;
    normal[0] = x; normal[1] = y; normal[2] = z;
}

void rlColor4f(renderlist_t *list, GLfloat r, GLfloat g, GLfloat b, GLfloat a) {
    if (list->color == NULL) {
        list->color = alloc_sublist(4, list->cap);
        // catch up
        int i;
        if (list->len) for (i = 0; i < list->len-1; i++) {
            GLfloat *color = (list->color + (i * 4));
            memcpy(color, state.color, sizeof(GLfloat) * 4);
        } else {
            GLfloat *color = list->color;
	    color[0] = r; color[1] = g; color[2] = b; color[3] = a;
	}
    } else {
        resize_renderlist(list);
    }

    GLfloat *color = state.color;
    color[0] = r; color[1] = g; color[2] = b; color[3] = a;
}

void rlSecondary3f(renderlist_t *list, GLfloat r, GLfloat g, GLfloat b) {
    if (list->secondary == NULL) {
        list->secondary = alloc_sublist(4, list->cap);
        // catch up
        int i;
        if (list->len) for (i = 0; i < list->len-1; i++) {
            GLfloat *secondary = (list->secondary + (i * 4));
            memcpy(secondary, state.secondary, sizeof(GLfloat) * 4);
        }
    } else {
        resize_renderlist(list);
    }

    GLfloat *color = state.secondary;
    color[0] = r; color[1] = g; color[2] = b; color[3] = 0.0f;
}

void rlMaterialfv(renderlist_t *list, GLenum face, GLenum pname, const GLfloat * params) {
    rendermaterial_t *m;
    khash_t(material) *map;
    khint_t k;
    int ret;
    if (! list->material) {
        list->material = map = kh_init(material);
        // segfaults if we don't do a single put
        kh_put(material, map, 1, &ret);
        kh_del(material, map, 1);
    } else {
        map = list->material;
    }

    // TODO: currently puts all faces in the same map
    k = kh_get(material, map, pname);
    if (k == kh_end(map)) {
        k = kh_put(material, map, pname, &ret);
        m = kh_value(map, k) = malloc(sizeof(rendermaterial_t));
    } else {
        m = kh_value(map, k);
    }

    m->face = face;
    m->pname = pname;
    m->color[0] = params[0];
    m->color[1] = params[1];
    m->color[2] = params[2];
    m->color[3] = params[3];
}

void rlLightfv(renderlist_t *list, GLenum which, GLenum pname, const GLfloat * params) {
    renderlight_t *m;
    khash_t(light) *map;
    khint_t k;
    int ret;
    if (! list->light) {
        list->light = map = kh_init(light);
        // segfaults if we don't do a single put
        kh_put(light, map, 1, &ret);
        kh_del(light, map, 1);
    } else {
        map = list->light;
    }

	int key = pname | ((which-GL_LIGHT0)<<16);
    k = kh_get(light, map, key);
    if (k == kh_end(map)) {
        k = kh_put(light, map, key, &ret);
        m = kh_value(map, k) = malloc(sizeof(renderlight_t));
    } else {
        m = kh_value(map, k);
    }

    m->which = which;
    m->pname = pname;
    m->color[0] = params[0];
    m->color[1] = params[1];
    m->color[2] = params[2];
    m->color[3] = params[3];
}

void rlTexGenfv(renderlist_t *list, GLenum coord, GLenum pname, const GLfloat * params) {
    rendertexgen_t *m;
    khash_t(texgen) *map;
    khint_t k;
    int ret;
    if (! list->texgen) {
        list->texgen = map = kh_init(texgen);
        // segfaults if we don't do a single put
        kh_put(texgen, map, 1, &ret);
        kh_del(texgen, map, 1);
    } else {
        map = list->texgen;
    }

	int key = pname | ((coord-GL_S)<<16);
    k = kh_get(texgen, map, key);
    if (k == kh_end(map)) {
        k = kh_put(texgen, map, key, &ret);
        m = kh_value(map, k) = malloc(sizeof(rendertexgen_t));
    } else {
        m = kh_value(map, k);
    }

    m->coord = coord;
    m->pname = pname;
    m->color[0] = params[0];
    m->color[1] = params[1];
    m->color[2] = params[2];
    m->color[3] = params[3];
}

void rlTexCoord2f(renderlist_t *list, GLfloat s, GLfloat t) {
    if (list->tex[0] == NULL) {
        list->tex[0] = alloc_sublist(2, list->cap);
        // catch up
        GLfloat *tex = list->tex[0];
        if (list->len) for (int i = 0; i < list->len-1; i++) {
            memcpy(tex, state.texcoord[0], sizeof(GLfloat) * 2);
            tex += 2;
        }
    } else {
        resize_renderlist(list);
    }
    GLfloat *tex = state.texcoord[0];
    tex[0] = s; tex[1] = t;
}

void rlMultiTexCoord2f(renderlist_t *list, GLenum target, GLfloat s, GLfloat t) {
    if (list->tex[target-GL_TEXTURE0] == NULL) {
        list->tex[target-GL_TEXTURE0] = alloc_sublist(2, list->cap);
        // catch up
        GLfloat *tex = list->tex[target-GL_TEXTURE0];
        if (list->len) for (int i = 0; i < list->len-1; i++) {
            memcpy(tex, state.texcoord[target-GL_TEXTURE0], sizeof(GLfloat) * 2);
            tex += 2;
        }
    } else {
        resize_renderlist(list);
    }
    GLfloat *tex = state.texcoord[target-GL_TEXTURE0];
    tex[0] = s; tex[1] = t;
}

void rlBindTexture(renderlist_t *list, GLenum target, GLuint texture) {
    list->texture = texture;
    list->target_texture = target;
    list->set_texture = true;
}

void rlPushCall(renderlist_t *list, packed_call_t *data) {
    call_list_t *cl = &list->calls;
    if (!cl->calls) {
        cl->cap = DEFAULT_CALL_LIST_CAPACITY;
        cl->calls = malloc(DEFAULT_CALL_LIST_CAPACITY * sizeof(uintptr_t));
    } else if (list->calls.len == list->calls.cap) {
        cl->cap += DEFAULT_CALL_LIST_CAPACITY;
        cl->calls = realloc(cl->calls, cl->cap * sizeof(uintptr_t));
    }
    cl->calls[cl->len++] = data;
}
#undef alloc_sublist
#undef realloc_sublist
