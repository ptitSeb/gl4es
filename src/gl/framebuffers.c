#include "framebuffers.h"
#include "debug.h"

#ifndef ANDROID
#include <execinfo.h>
#endif
//extern void* eglGetProcAddress(const char* name);

khash_t(dsr) *depthstencil = NULL;
GLuint current_rb = 0;

GLuint current_fb = 0;

GLuint mainfbo_fbo = 0; // The MainFBO
GLuint mainfbo_tex = 0; // Texture Attachment
GLuint mainfbo_dep = 0; // Depth attachment
GLuint mainfbo_ste = 0; // Stencil attachement
int mainfbo_width = 800;
int mainfbo_height = 480;
int mainfbo_nwidth = 1024;
int mainfbo_nheight = 512;

extern bool g_recyclefbo;

GLuint fbo_read = 0;    // if not 0, that's the READ only Framebuffer attached
GLuint fbo_draw = 0;     // if not 0, that's the DRAW only Framebuffer attached

GLuint *old_fbos = NULL;
int nbr_fbos = 0;
int cap_fbos = 0;

int npot(int n);

void readfboBegin() {
    //printf("readfboBegin, fbo status read=%u, draw=%u, main=%u, current=%u\n", fbo_read, fbo_draw, mainfbo_fbo, current_fb);
    LOAD_GLES_OES(glBindFramebuffer);
	if (!(fbo_read || fbo_draw))
		return;
	GLuint fbo = fbo_read;
	if (!fbo && mainfbo_fbo)
		fbo = mainfbo_fbo;
	gles_glBindFramebuffer(GL_FRAMEBUFFER, fbo);
}

void readfboEnd() {
    //printf("readfboEnd, fbo status read=%u, draw=%u, main=%u, current=%u\n", fbo_read, fbo_draw, mainfbo_fbo, current_fb);
    LOAD_GLES_OES(glBindFramebuffer);
	if (!(fbo_read || fbo_draw))
		return;
	GLuint fbo = current_fb;
	if (!fbo && mainfbo_fbo)
		fbo = mainfbo_fbo;
	gles_glBindFramebuffer(GL_FRAMEBUFFER, fbo);
}

void glGenFramebuffers(GLsizei n, GLuint *ids) {
    LOAD_GLES_OES(glGenFramebuffers);
    //printf("glGenFramebuffers(%i, %p)\n", n, ids);
    GLsizei m = 0;
    while(g_recyclefbo && (nbr_fbos>0) && (n-m>0)) {
        //printf("Recycled 1 FBO\n");
        ids[m++] = old_fbos[--nbr_fbos];
    }
    noerrorShim();
    if(n-m == 0)
        return;
    errorGL();
    gles_glGenFramebuffers(n-m, ids+m);
}

void glDeleteFramebuffers(GLsizei n, GLuint *framebuffers) {
    //printf("glDeleteFramebuffers(%i, %p), framebuffers[0]=%u\n", n, framebuffers, framebuffers[0]);
    if (state.gl_batch) flush();
    if (g_recyclefbo) {
        //printf("Recycling %i FBOs\n", n);
        noerrorShim();
        if(cap_fbos == 0) {
            cap_fbos = 16;
            old_fbos = (GLuint*)malloc(cap_fbos * sizeof(GLuint));
        }
        if (nbr_fbos+n == cap_fbos) {
            cap_fbos += n;
            old_fbos = (GLuint*)realloc(old_fbos, cap_fbos *sizeof(GLuint));
        }
        memcpy(old_fbos+nbr_fbos, framebuffers, n*sizeof(GLuint));
        nbr_fbos += n;
    } else {
        LOAD_GLES_OES(glDeleteFramebuffers);
        errorGL();
        gles_glDeleteFramebuffers(n, framebuffers);
    }
}

GLboolean glIsFramebuffer(GLuint framebuffer) {
    //printf("glIsFramebuffer(%u)\n", framebuffer);
    if (state.gl_batch) flush();
    LOAD_GLES_OES(glIsFramebuffer);
    
    errorGL();
    return gles_glIsFramebuffer(framebuffer);
}

GLenum fb_status;

GLenum glCheckFramebufferStatus(GLenum target) {
    if (state.gl_batch) flush();
//#define BEFORE 1
#ifdef BEFORE
    GLenum result = fb_status;
    noerrorShim();
#else
    LOAD_GLES_OES(glCheckFramebufferStatus);
    
    errorGL();
    GLenum result = gles_glCheckFramebufferStatus(target);
#endif
#undef BEFORE
//printf("glCheckFramebufferStatus(0x%04X)=0x%04X\n", target, result);
    return result;
}

void glBindFramebuffer(GLenum target, GLuint framebuffer) {
    //printf("glBindFramebuffer(%s, %u), list=%s\n", PrintEnum(target), framebuffer, state.list.active?"active":"none");
	//PUSH_IF_COMPILING(glBindFramebuffer);
    if (state.gl_batch) flush();
    LOAD_GLES_OES(glBindFramebuffer);
    LOAD_GLES_OES(glCheckFramebufferStatus);
    LOAD_GLES(glGetError);
        
    if (target == GL_FRAMEBUFFER) {
        if (fbo_read)
            fbo_read = 0;
        if (fbo_draw)
            fbo_draw = 0;
    }
    
    if (target == GL_READ_FRAMEBUFFER) {
		fbo_read = framebuffer;
        noerrorShim();
        fb_status = GL_FRAMEBUFFER_COMPLETE;
		return;	//don't bind for now
	}
        
    if (target == GL_DRAW_FRAMEBUFFER) {
		target = GL_FRAMEBUFFER;
		fbo_draw = framebuffer;
	}
    
    if(target==GL_FRAMEBUFFER && framebuffer!=0) {
        gles_glBindFramebuffer(target, 0);
        gles_glCheckFramebufferStatus(target);
    }
        
    current_fb = framebuffer;

    if (mainfbo_fbo && (framebuffer==0)) 
        framebuffer = mainfbo_fbo;
        
    gles_glBindFramebuffer(target, framebuffer);
    GLenum err=gles_glGetError();
    errorShim(err);
    
    fb_status = gles_glCheckFramebufferStatus(target);
}


void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level) {
    static GLuint scrap_tex = 0;
    static int scrap_width = 0;
    static int scrap_height = 0;
    
    if (state.gl_batch) flush();
    LOAD_GLES_OES(glFramebufferTexture2D);
    LOAD_GLES(glTexImage2D);
    LOAD_GLES(glBindTexture);
    //printf("glFramebufferTexture2D(%s, %s, %s, %u, %i)\n", PrintEnum(target), PrintEnum(attachment), PrintEnum(textarget), texture, level);
		
    // Ignore Color attachment 1 .. 9
    if ((attachment>=GL_COLOR_ATTACHMENT0+1) && (attachment<=GL_COLOR_ATTACHMENT0+9)) {
        errorShim(GL_INVALID_ENUM);
        return;
    }
    
    int twidth = 0, theight = 0;
    // find texture and get it's real name
    if (texture) {
        gltexture_t *tex = NULL;
        int ret;
        khint_t k;
        khash_t(tex) *list = state.texture.list;
        if (! list) {
            list = state.texture.list = kh_init(tex);
            // segfaults if we don't do a single put
            kh_put(tex, list, 1, &ret);
            kh_del(tex, list, 1);
        }
        k = kh_get(tex, list, texture);
        
        if (k == kh_end(list)){
            printf("*WARNING* texture for FBO not found, name=%u\n", texture);
        } else {
            tex = kh_value(list, k);
            texture = tex->glname;
            // check if texture is shrinked...
            if (tex->shrink) {
                printf("LIBGL: unshrinking shrinked texture for FBO\n");
                tex->width *= 2*tex->shrink;
                tex->height *= 2*tex->shrink;
                tex->nwidth = npot(tex->width);
                tex->nheight = npot(tex->height);
                tex->shrink = 0;
                gltexture_t *bound = state.texture.bound[state.texture.active];
                GLuint oldtex = (bound)?bound->glname:0;
                if (oldtex!=tex->glname) gles_glBindTexture(GL_TEXTURE_2D, tex->glname);
                gles_glTexImage2D(GL_TEXTURE_2D, 0, tex->format, tex->nwidth, tex->nheight, 0, tex->format, tex->type, NULL);
                if (oldtex!=tex->glname) gles_glBindTexture(GL_TEXTURE_2D, oldtex);
            }
            twidth = tex->nwidth;
            theight = tex->nheight;
 /*           if ((tex->width<32) || (tex->height<32)) {
                printf("LIBGL: enlarging too-small texture for FBO\n");
                tex->nwidth = (tex->nwidth<32)?32:tex->nwidth;
                tex->nheight = (tex->nheight<32)?32:tex->nheight;
                tex->shrink = 0;
                gltexture_t *bound = state.texture.bound[state.texture.active];
                GLuint oldtex = (bound)?bound->glname:0;
                if (oldtex!=tex->glname) gles_glBindTexture(GL_TEXTURE_2D, tex->glname);
                gles_glTexImage2D(GL_TEXTURE_2D, 0, tex->format, tex->nwidth, tex->nheight, 0, tex->format, tex->type, NULL);
                if (oldtex!=tex->glname) gles_glBindTexture(GL_TEXTURE_2D, oldtex);
            }*/
            //printf("found texture, glname=%u, size=%ix%i(%ix%i), format/type=0x%04X/0x%04X\n", texture, tex->width, tex->height, tex->nwidth, tex->nheight, tex->format, tex->type);
        }
    }
    
    twidth = twidth >> level; if(twidth<1) twidth=1;
    theight = theight >> level; if(theight<1) theight=1;
    
	if (level!=0) {
        //bind a scrap texture, we don't want level != 0 binding on GLES
        if(!scrap_tex)
            glGenTextures(1, &scrap_tex);
        if ((scrap_width!=twidth) || (scrap_height!=theight)) {
                scrap_width = twidth;
                scrap_height = theight;
                gltexture_t *bound = state.texture.bound[state.texture.active];
                GLuint oldtex = (bound)?bound->glname:0;
                if (oldtex!=scrap_tex) gles_glBindTexture(GL_TEXTURE_2D, scrap_tex);
                gles_glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, scrap_width, scrap_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
                if (oldtex!=scrap_tex) gles_glBindTexture(GL_TEXTURE_2D, oldtex);
        }
        texture = scrap_tex;
    }

    errorGL();
    gles_glFramebufferTexture2D(target, attachment, textarget, texture, 0);
}

void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level) {
    glFramebufferTexture2D(target, attachment, GL_TEXTURE_2D, texture, level);
}
void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level, GLint layer) {
    (void)layer;
    glFramebufferTexture2D(target, attachment, GL_TEXTURE_2D, texture, level);
}

void glGenRenderbuffers(GLsizei n, GLuint *renderbuffers) {
    LOAD_GLES_OES(glGenRenderbuffers);
    //printf("glGenRenderbuffers(%i, %p)\n", n, renderbuffers);
    
    errorGL();
    gles_glGenRenderbuffers(n, renderbuffers);
}

void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
    LOAD_GLES_OES(glFramebufferRenderbuffer);
    LOAD_GLES_OES(glGetFramebufferAttachmentParameteriv);
    //printf("glFramebufferRenderbuffer(%s, %s, %s, %u)\n", PrintEnum(target), PrintEnum(attachment), PrintEnum(renderbuffertarget), renderbuffer);

    //TODO: handle target=READBUFFER or DRAWBUFFER...
    if (depthstencil && (attachment==GL_STENCIL_ATTACHMENT)) {
		khint_t k = kh_get(dsr, depthstencil, renderbuffer);
		if (k != kh_end(depthstencil)) {
			gldepthstencil_t *dsr = kh_value(depthstencil, k);
            renderbuffer = dsr->stencil;
		}
    }
    
    if ((current_fb!=0) && (renderbuffer==0)) {
        //Hack, avoid unbind a renderbuffer on a framebuffer...
        // TODO, avoid binding an already binded RB
        noerrorShim();
        return;
    }

    errorGL();
    gles_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}

void glDeleteRenderbuffers(GLsizei n, GLuint *renderbuffers) {
    if (state.gl_batch) flush();
    LOAD_GLES_OES(glDeleteRenderbuffers);
    
    // check if we delete a depthstencil
    khint_t k;
    if (depthstencil)
        for (int i=0; i<n; i++) {
            khint_t k;
            gldepthstencil_t *dsr;
            for (int i = 0; i < n; i++) {
                GLuint t = renderbuffers[i];
                k = kh_get(dsr, depthstencil, t);
                if (k != kh_end(depthstencil)) {
                    dsr = kh_value(depthstencil, k);
                    gles_glDeleteRenderbuffers(1, &dsr->stencil);
                    kh_del(dsr, depthstencil, k);
                    free(dsr);
                }
            }
        }

    errorGL();
    gles_glDeleteRenderbuffers(n, renderbuffers);
}

void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
    LOAD_GLES_OES(glRenderbufferStorage);
    LOAD_GLES_OES(glGenRenderbuffers);
    LOAD_GLES_OES(glBindRenderbuffer);
    //printf("glRenderbufferStorage(0x%04X, 0x%04X, %i, %i)\n", target, internalformat, width, height);
    
    errorGL();
    width = npot(width);
    height = npot(height);
    // check if internal format is GL_DEPTH_STENCIL_EXT
    // in that case, create first a STENCIL one then a DEPTH one....
    if ((internalformat == GL_DEPTH_STENCIL) || (internalformat == GL_DEPTH24_STENCIL8)) {
        khint_t k;
        int ret;
        internalformat = GL_DEPTH_COMPONENT24;
        GLuint old_rb = current_rb;
        GLuint stencil;
        if (!depthstencil) {
            depthstencil = kh_init(dsr);
            // segfaults if we don't do a single put
            kh_put(dsr, depthstencil, 1, &ret);
            kh_del(dsr, depthstencil, 1);
        }
        // search for an existing buffer (should not exist!)
        k = kh_get(dsr, depthstencil, current_rb);
        gldepthstencil_t *dsr = NULL;
        if (k == kh_end(depthstencil)){
            k = kh_put(dsr, depthstencil, current_rb, &ret);
            dsr = kh_value(depthstencil, k) = malloc(sizeof(gldepthstencil_t));
            dsr->renderbuffer = current_rb;
        } else {
            dsr = kh_value(depthstencil, k);
        }
        // create a stencil buffer
        gles_glGenRenderbuffers(1, &stencil);
        dsr->stencil = stencil;
        gles_glBindRenderbuffer(GL_RENDERBUFFER, stencil);
        gles_glRenderbufferStorage(target, GL_STENCIL_INDEX8, width, height);
        gles_glBindRenderbuffer(GL_RENDERBUFFER, current_rb);
    }
    
    gles_glRenderbufferStorage(target, internalformat, width, height);
}

void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {    //STUB
    glRenderbufferStorage(target, internalformat, width, height);
}

void glBindRenderbuffer(GLenum target, GLuint renderbuffer) {
    if (state.gl_batch) flush();
    LOAD_GLES_OES(glBindRenderbuffer);
    //printf("glBindRenderbuffer(%s, %u), binded Fbo=%u\n", PrintEnum(target), renderbuffer, current_fb);
    
    current_rb = renderbuffer;
    
    errorGL();
    gles_glBindRenderbuffer(target, renderbuffer);
}

GLboolean glIsRenderbuffer(GLuint renderbuffer) {
    //printf("glIsRenderbuffer(%u)\n", renderbuffer);
    if (state.gl_batch) flush();
    LOAD_GLES_OES(glIsRenderbuffer);
    
    errorGL();
    return gles_glIsRenderbuffer(renderbuffer);
}

void glGenerateMipmap(GLenum target) {
    //printf("glGenerateMipmap(0x%04X)\n", target);
    LOAD_GLES_OES(glGenerateMipmap);
    
    errorGL();
    return gles_glGenerateMipmap(target);
}

void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params) {
    //printf("glGetFramebufferAttachmentParameteriv(%s, %s, %s, %p)\n", PrintEnum(target), PrintEnum(attachment), PrintEnum(pname), params);
    LOAD_GLES_OES(glGetFramebufferAttachmentParameteriv);
    
    errorGL();
    return gles_glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}

void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    //printf("glGetRenderbufferParameteriv(%s, %s, %p)\n", PrintEnum(target), PrintEnum(pname), params);
    LOAD_GLES_OES(glGetRenderbufferParameteriv);
    
    errorGL();
    return gles_glGetRenderbufferParameteriv(target, pname, params);
}

void createMainFBO(int width, int height) {
    LOAD_GLES_OES(glGenFramebuffers);
    LOAD_GLES_OES(glBindFramebuffer);
    LOAD_GLES_OES(glFramebufferTexture2D);
    LOAD_GLES_OES(glCheckFramebufferStatus);
    LOAD_GLES_OES(glFramebufferRenderbuffer);
    LOAD_GLES_OES(glRenderbufferStorage);
    LOAD_GLES_OES(glGenRenderbuffers);
    LOAD_GLES_OES(glBindRenderbuffer);
    LOAD_GLES(glTexImage2D);
    LOAD_GLES(glGenTextures);
    LOAD_GLES(glBindTexture);
    LOAD_GLES(glActiveTexture);
    LOAD_GLES(glTexParameteri);
    LOAD_GLES(glClientActiveTexture);
    LOAD_GLES(glClear);

    // If there is already a Framebuffer created, let's delete it.... unless it's already the right size!
    if (mainfbo_fbo) {
        if (width==mainfbo_width && height==mainfbo_height)
            return;
        deleteMainFBO();
    }
    // switch to texture unit 0 if needed
    if (state.texture.active != 0)
        gles_glActiveTexture(GL_TEXTURE0);
    if (state.texture.client != 0)
        gles_glClientActiveTexture(GL_TEXTURE0);
        
    mainfbo_width = width;
    mainfbo_height = height;
    mainfbo_nwidth = width = npot(width);
    mainfbo_nheight = height = npot(height);

    // create the texture
	gles_glGenTextures(1, &mainfbo_tex);
    gles_glBindTexture(GL_TEXTURE_2D, mainfbo_tex);
    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    gles_glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
					0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	gles_glBindTexture(GL_TEXTURE_2D, 0);
    // create the render buffers
	gles_glGenRenderbuffers(1, &mainfbo_dep);
	gles_glGenRenderbuffers(1, &mainfbo_ste);
    gles_glBindRenderbuffer(GL_RENDERBUFFER, mainfbo_ste);
    gles_glRenderbufferStorage(GL_RENDERBUFFER, GL_STENCIL_INDEX8, width, height);
    gles_glBindRenderbuffer(GL_RENDERBUFFER, mainfbo_dep);
    gles_glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, width, height);
    gles_glBindRenderbuffer(GL_RENDERBUFFER, 0);
    // create a fbo
    gles_glGenFramebuffers(1, &mainfbo_fbo);
    gles_glBindFramebuffer(GL_FRAMEBUFFER, mainfbo_fbo);
    
    gles_glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, mainfbo_ste);
    gles_glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, mainfbo_dep);
    
    gles_glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, mainfbo_tex, 0);

	GLenum status = gles_glCheckFramebufferStatus(GL_FRAMEBUFFER);

	gles_glBindFramebuffer(GL_FRAMEBUFFER, 0);

    // Final check, and bind the fbo for future use
    if (status != GL_FRAMEBUFFER_COMPLETE) {
        printf("LIBGL: Error while creating main fbo (0x%04X)\n", status);
        deleteMainFBO();
        gles_glBindFramebuffer(GL_FRAMEBUFFER, current_fb);
        gles_glBindFramebuffer(GL_RENDERBUFFER, current_rb);
    } else {
        gles_glBindFramebuffer(GL_FRAMEBUFFER, (current_fb)?current_fb:mainfbo_fbo);
        if (current_rb)
            gles_glBindRenderbuffer(GL_RENDERBUFFER, current_rb);
        // clear color, depth and stencil...
        if (current_fb==0)
            gles_glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    }
    // Put everything back, and active the MainFBO
    if (state.texture.bound[0]) 
        gles_glBindTexture(GL_TEXTURE_2D, state.texture.bound[0]->glname);
    if (state.texture.active != 0)
        gles_glActiveTexture(GL_TEXTURE0 + state.texture.active);
    if (state.texture.client != 0)
        gles_glClientActiveTexture(GL_TEXTURE0 + state.texture.client);
    
}

void blitMainFBO() {
    LOAD_GLES_OES(glDrawTexi);
    LOAD_GLES(glBindTexture);
    LOAD_GLES(glActiveTexture);
    LOAD_GLES(glClientActiveTexture);
    LOAD_GLES(glViewport);
    LOAD_GLES(glEnable);
    LOAD_GLES(glDisable);
    LOAD_GLES(glGetIntegerv);
    
    if (mainfbo_fbo==0)
        return;
    
    // switch to texture unit 0 if needed
    int old_tex = state.texture.active;
    int old_client = state.texture.client;
    if (state.texture.active != 0)
        glActiveTexture(GL_TEXTURE0);
    if (state.texture.client != 0)
        glClientActiveTexture(GL_TEXTURE0);
    // bind the FBO texture
    gles_glEnable(GL_TEXTURE_2D);
    gles_glBindTexture(GL_TEXTURE_2D, mainfbo_tex);
    // blit
    GLuint old_vp[4];
    gles_glGetIntegerv(GL_VIEWPORT, old_vp);
    gles_glViewport(0, 0, mainfbo_width, mainfbo_height);
    // Draw the texture
    #if 0
    gles_glDrawTexi(0, 0, 0, mainfbo_width, mainfbo_height);
    #else
    {
        LOAD_GLES(glEnableClientState);
        LOAD_GLES(glDisableClientState);
        LOAD_GLES(glBindTexture);
        LOAD_GLES(glVertexPointer);
        LOAD_GLES(glTexCoordPointer);
        LOAD_GLES(glDrawArrays);
        LOAD_GLES(glOrthof);
        LOAD_GLES(glPushMatrix);
        LOAD_GLES(glPopMatrix);
        
        glPushAttrib(GL_TEXTURE_BIT | GL_ENABLE_BIT | GL_TRANSFORM_BIT | GL_COLOR_BUFFER_BIT | GL_CURRENT_BIT);

        glMatrixMode(GL_TEXTURE);
        gles_glPushMatrix();
        glLoadIdentity();
        glMatrixMode(GL_PROJECTION);
        gles_glPushMatrix();
        glLoadIdentity();
        glMatrixMode(GL_MODELVIEW);
        gles_glPushMatrix();
        glLoadIdentity();
        GLfloat vert[] = {
            -1, -1,
            +1, -1,
            +1, +1,
            -1, +1,
        };
        float sw = (float)mainfbo_width / (float)mainfbo_nwidth;
        float sh = (float)mainfbo_height / (float)mainfbo_nheight;
        GLfloat tex[] = {
            0, 0,
            sw, 0,
            sw, sh,
            0, sh
        };

        glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);

        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);
        glDisable(GL_CULL_FACE);
        glDisable(GL_ALPHA_TEST);
        glDisable(GL_BLEND);

//        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glDisableClientState(GL_COLOR_ARRAY);
        glDisableClientState(GL_NORMAL_ARRAY);
        gles_glVertexPointer(2, GL_FLOAT, 0, vert);
        gles_glTexCoordPointer(2, GL_FLOAT, 0, tex);


        glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        
        gles_glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
        // All the previous states are Pushed / Poped anyway...
        glPopClientAttrib();
        glMatrixMode(GL_MODELVIEW);
        gles_glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        gles_glPopMatrix();
        glMatrixMode(GL_TEXTURE);
        gles_glPopMatrix();
        glPopAttrib();
    }
    #endif
    // put back viewport
    gles_glViewport(old_vp[0], old_vp[1], old_vp[2], old_vp[3]);
    // Put everything back
    if (state.texture.bound[0]) 
        gles_glBindTexture(GL_TEXTURE_2D, state.texture.bound[0]->glname);
    else
        gles_glBindTexture(GL_TEXTURE_2D, 0);
    if (!state.enable.texture_2d[0])
        gles_glDisable(GL_TEXTURE_2D);
    if (old_tex != 0)
        glActiveTexture(GL_TEXTURE0 + old_tex);
    if (old_client != 0)
        glClientActiveTexture(GL_TEXTURE0 + old_client);
}

void bindMainFBO() {
    LOAD_GLES_OES(glBindFramebuffer);
    LOAD_GLES_OES(glCheckFramebufferStatus);
    if (!mainfbo_fbo)
        return;
    if (current_fb==0) {
        gles_glBindFramebuffer(GL_FRAMEBUFFER, mainfbo_fbo);
        gles_glCheckFramebufferStatus(GL_FRAMEBUFFER);
    }
}

void unbindMainFBO() {
    LOAD_GLES_OES(glBindFramebuffer);
    if (!mainfbo_fbo)
        return;
    if (current_fb==0) {
        GLuint pixel;
        gles_glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }
}

void deleteMainFBO() {
    LOAD_GLES_OES(glDeleteFramebuffers);
    LOAD_GLES_OES(glDeleteRenderbuffers);
    LOAD_GLES(glDeleteTextures);

    if (mainfbo_dep) {
        gles_glDeleteRenderbuffers(1, &mainfbo_dep);
        mainfbo_dep = 0;
    }
    if (mainfbo_ste) {
        gles_glDeleteRenderbuffers(1, &mainfbo_ste);
        mainfbo_ste = 0;
    }
    if (mainfbo_tex) {
        gles_glDeleteTextures(1, &mainfbo_tex);
        mainfbo_tex = 0;
    }
    if (mainfbo_fbo) {
        gles_glDeleteFramebuffers(1, &mainfbo_fbo);
        mainfbo_fbo = 0;
    }
    
    // all done...
}

void glFramebufferTextureLayer(	GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
    glFramebufferTexture2D(target, attachment, GL_TEXTURE_2D, texture,	level); // Force Texture2D, ignore layer...
}

void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
    // TODO!
    // create a temp texture
    // glCopyPixel of read FBO
    // set viewport / matrixs
    // glDraw of write FBO
printf("glBlitFramebuffer(%d, %d, %d, %d,  %d, %d, %d, %d,  0x%04X, 0x%04X)\n",
    srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}


// EXT direct wrapper
void glGenFramebuffersEXT(GLsizei n, GLuint *ids) {
    glGenFramebuffers(n, ids);
}
void glDeleteFramebuffersEXT(GLsizei n, GLuint *framebuffers) {
    glDeleteFramebuffers(n, framebuffers);
}
GLboolean glIsFramebufferEXT(GLuint framebuffer) {
    return glIsFramebuffer(framebuffer);
}
GLenum glCheckFramebufferStatusEXT(GLenum target) {
    return glCheckFramebufferStatus(target);
}
void glBindFramebufferEXT(GLenum target, GLuint framebuffer) {
    glBindFramebuffer(target, framebuffer);
}
void glFramebufferTexture1DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level) {
    glFramebufferTexture1D(target, attachment, textarget, texture, level);
}
void glFramebufferTexture2DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level) {
    glFramebufferTexture2D(target, attachment, textarget, texture, level);
}
void glFramebufferTexture3DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level, GLint layer) {
    glFramebufferTexture3D(target, attachment, textarget, texture, level, layer);
}
void glGenRenderbuffersEXT(GLsizei n, GLuint *renderbuffers) {
    glGenRenderbuffers(n, renderbuffers);
}
void glFramebufferRenderbufferEXT(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
    glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}
void glDeleteRenderbuffersEXT(GLsizei n, GLuint *renderbuffers) {
    glDeleteRenderbuffers(n, renderbuffers);
}
void glRenderbufferStorageEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
    glRenderbufferStorage(target, internalformat, width, height);
}
void glBindRenderbufferEXT(GLenum target, GLuint renderbuffer) {
    glBindRenderbuffer(target, renderbuffer);
}
GLboolean glIsRenderbufferEXT(GLuint renderbuffer) {
    return glIsRenderbuffer(renderbuffer);
}
void glGenerateMipmapEXT(GLenum target) {
    glGenerateMipmap(target);
}
void glGetFramebufferAttachmentParameterivEXT(GLenum target, GLenum attachment, GLenum pname, GLint *params) {
    glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}
void glGetRenderbufferParameterivEXT(GLenum target, GLenum pname, GLint * params) {
    glGetRenderbufferParameteriv(target, pname, params);
}

void glFramebufferTextureLayerEXT(	GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
    glFramebufferTextureLayer(target, attachment, texture, level, layer);
}

void glBlitFramebufferEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
    glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}
