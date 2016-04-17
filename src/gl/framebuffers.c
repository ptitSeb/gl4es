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

void glshim_glGenFramebuffers(GLsizei n, GLuint *ids) {
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

void glshim_glDeleteFramebuffers(GLsizei n, GLuint *framebuffers) {
    //printf("glDeleteFramebuffers(%i, %p), framebuffers[0]=%u\n", n, framebuffers, framebuffers[0]);
    if (glstate.gl_batch) flush();
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

GLboolean glshim_glIsFramebuffer(GLuint framebuffer) {
    //printf("glIsFramebuffer(%u)\n", framebuffer);
    if (glstate.gl_batch) flush();
    LOAD_GLES_OES(glIsFramebuffer);
    
    errorGL();
    return gles_glIsFramebuffer(framebuffer);
}

GLenum fb_status;

GLenum glshim_glCheckFramebufferStatus(GLenum target) {
    if (glstate.gl_batch) flush();
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

void glshim_glBindFramebuffer(GLenum target, GLuint framebuffer) {
    //printf("glBindFramebuffer(%s, %u), list=%s\n", PrintEnum(target), framebuffer, glstate.list.active?"active":"none");
	//PUSH_IF_COMPILING(glBindFramebuffer);
    if (glstate.gl_batch) flush();
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


void glshim_glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level) {
    static GLuint scrap_tex = 0;
    static int scrap_width = 0;
    static int scrap_height = 0;
    
    if (glstate.gl_batch) flush();
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
        khash_t(tex) *list = glstate.texture.list;
        if (! list) {
            list = glstate.texture.list = kh_init(tex);
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
                gltexture_t *bound = glstate.texture.bound[glstate.texture.active];
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
                gltexture_t *bound = glstate.texture.bound[glstate.texture.active];
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
            glshim_glGenTextures(1, &scrap_tex);
        if ((scrap_width!=twidth) || (scrap_height!=theight)) {
                scrap_width = twidth;
                scrap_height = theight;
                gltexture_t *bound = glstate.texture.bound[glstate.texture.active];
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

void glshim_glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level) {
    glshim_glFramebufferTexture2D(target, attachment, GL_TEXTURE_2D, texture, level);
}
void glshim_glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level, GLint layer) {
    (void)layer;
    glshim_glFramebufferTexture2D(target, attachment, GL_TEXTURE_2D, texture, level);
}

void glshim_glGenRenderbuffers(GLsizei n, GLuint *renderbuffers) {
    LOAD_GLES_OES(glGenRenderbuffers);
    //printf("glGenRenderbuffers(%i, %p)\n", n, renderbuffers);
    
    errorGL();
    gles_glGenRenderbuffers(n, renderbuffers);
}

void glshim_glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
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

    if ((current_fb!=0) && (renderbuffer!=0) && ((attachment==GL_DEPTH_ATTACHMENT) || (attachment==GL_STENCIL_ATTACHMENT))) {
        GLuint tmp;
        gles_glGetFramebufferAttachmentParameteriv(target, attachment, GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME, &tmp);
        if (tmp==renderbuffer) {
            noerrorShim();
            return;
        }
    }

    errorGL();
    gles_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}

void glshim_glDeleteRenderbuffers(GLsizei n, GLuint *renderbuffers) {
    if (glstate.gl_batch) flush();
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

void glshim_glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
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
    else if (internalformat == GL_DEPTH_COMPONENT) {    // Not much is supported on GLES...
        internalformat = GL_DEPTH_COMPONENT16;
    }
    
    gles_glRenderbufferStorage(target, internalformat, width, height);
}

void glshim_glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {    //STUB
    glshim_glRenderbufferStorage(target, internalformat, width, height);
}

void glshim_glBindRenderbuffer(GLenum target, GLuint renderbuffer) {
    if (glstate.gl_batch) flush();
    LOAD_GLES_OES(glBindRenderbuffer);
    //printf("glBindRenderbuffer(%s, %u), binded Fbo=%u\n", PrintEnum(target), renderbuffer, current_fb);
    
    current_rb = renderbuffer;
    
    errorGL();
    gles_glBindRenderbuffer(target, renderbuffer);
}

GLboolean glshim_glIsRenderbuffer(GLuint renderbuffer) {
    //printf("glIsRenderbuffer(%u)\n", renderbuffer);
    if (glstate.gl_batch) flush();
    LOAD_GLES_OES(glIsRenderbuffer);
    
    errorGL();
    return gles_glIsRenderbuffer(renderbuffer);
}

void glshim_glGenerateMipmap(GLenum target) {
    //printf("glGenerateMipmap(0x%04X)\n", target);
    LOAD_GLES_OES(glGenerateMipmap);
    
    errorGL();
    return gles_glGenerateMipmap(target);
}

void glshim_glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params) {
    //printf("glGetFramebufferAttachmentParameteriv(%s, %s, %s, %p)\n", PrintEnum(target), PrintEnum(attachment), PrintEnum(pname), params);
    LOAD_GLES_OES(glGetFramebufferAttachmentParameteriv);
    
    errorGL();
    return gles_glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}

void glshim_glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params) {
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
    if (glstate.texture.active != 0)
        gles_glActiveTexture(GL_TEXTURE0);
    if (glstate.texture.client != 0)
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
    #ifdef USE_DRAWTEX
    {
        LOAD_GLES(glTexParameteriv);
        // setup the texture for glDrawTexiOES
        GLint coords [] = {0, 0, mainfbo_width, mainfbo_height};
        gles_glTexParameteriv( GL_TEXTURE_2D, GL_TEXTURE_CROP_RECT_OES, coords );
    }
    #endif
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
    if (glstate.texture.bound[0]) 
        gles_glBindTexture(GL_TEXTURE_2D, glstate.texture.bound[0]->glname);
    if (glstate.texture.active != 0)
        gles_glActiveTexture(GL_TEXTURE0 + glstate.texture.active);
    if (glstate.texture.client != 0)
        gles_glClientActiveTexture(GL_TEXTURE0 + glstate.texture.client);
    
}

void blitMainFBO() {
    #ifdef USE_DRAWTEX
    LOAD_GLES_OES(glDrawTexi);
    #endif
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
    int old_tex = glstate.texture.active;
    int old_client = glstate.texture.client;
    if (glstate.texture.active != 0)
        glshim_glActiveTexture(GL_TEXTURE0);
    if (glstate.texture.client != 0)
        glshim_glClientActiveTexture(GL_TEXTURE0);
    // bind the FBO texture
    gles_glEnable(GL_TEXTURE_2D);
    gles_glBindTexture(GL_TEXTURE_2D, mainfbo_tex);
    // blit
    GLuint old_vp[4];
    gles_glGetIntegerv(GL_VIEWPORT, old_vp);
    gles_glViewport(0, 0, mainfbo_width, mainfbo_height);
    // Draw the texture
    #ifdef USE_DRAWTEX
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
        
        glshim_glPushAttrib(GL_TEXTURE_BIT | GL_ENABLE_BIT | GL_TRANSFORM_BIT | GL_COLOR_BUFFER_BIT | GL_CURRENT_BIT);

        glshim_glMatrixMode(GL_TEXTURE);
        gles_glPushMatrix();
        glshim_glLoadIdentity();
        glshim_glMatrixMode(GL_PROJECTION);
        gles_glPushMatrix();
        glshim_glLoadIdentity();
        glshim_glMatrixMode(GL_MODELVIEW);
        gles_glPushMatrix();
        glshim_glLoadIdentity();
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

        glshim_glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);

        glshim_glDisable(GL_DEPTH_TEST);
        glshim_glDisable(GL_LIGHTING);
        glshim_glDisable(GL_CULL_FACE);
        glshim_glDisable(GL_ALPHA_TEST);
        glshim_glDisable(GL_BLEND);

//        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
        if(!glstate.clientstate.vertex_array) {
            gles_glEnableClientState(GL_VERTEX_ARRAY);
            glstate.clientstate.vertex_array = 1;
        }
        gles_glVertexPointer(2, GL_FLOAT, 0, vert);
        if(!glstate.clientstate.tex_coord_array[0]) {
            gles_glEnableClientState(GL_TEXTURE_COORD_ARRAY);
            glstate.clientstate.tex_coord_array[0] = 1;
        }
        gles_glTexCoordPointer(2, GL_FLOAT, 0, tex);
        for (int a=1; a <MAX_TEX; a++)
            if(glstate.clientstate.tex_coord_array[a]) {
                glshim_glClientActiveTexture(GL_TEXTURE0 + a);
                gles_glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                glstate.clientstate.tex_coord_array[a] = 0;
            }
        if(glstate.clientstate.color_array) {
            gles_glDisableClientState(GL_COLOR_ARRAY);
            glstate.clientstate.color_array = 0;
        }
        if(glstate.clientstate.normal_array) {
            gles_glDisableClientState(GL_NORMAL_ARRAY);
            glstate.clientstate.normal_array = 0;
        }


        glshim_glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        
        gles_glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
        // All the previous states are Pushed / Poped anyway...
        glshim_glPopClientAttrib();
        glshim_glMatrixMode(GL_MODELVIEW);
        gles_glPopMatrix();
        glshim_glMatrixMode(GL_PROJECTION);
        gles_glPopMatrix();
        glshim_glMatrixMode(GL_TEXTURE);
        gles_glPopMatrix();
        glshim_glPopAttrib();
    }
    #endif
    // put back viewport
    gles_glViewport(old_vp[0], old_vp[1], old_vp[2], old_vp[3]);
    // Put everything back
    if (glstate.texture.bound[0]) 
        gles_glBindTexture(GL_TEXTURE_2D, glstate.texture.bound[0]->glname);
    else
        gles_glBindTexture(GL_TEXTURE_2D, 0);
    if (!glstate.enable.texture_2d[0])
        gles_glDisable(GL_TEXTURE_2D);
    if (old_tex != 0)
        glshim_glActiveTexture(GL_TEXTURE0 + old_tex);
    if (old_client != 0)
        glshim_glClientActiveTexture(GL_TEXTURE0 + old_client);
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

void glshim_glFramebufferTextureLayer(	GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
    glshim_glFramebufferTexture2D(target, attachment, GL_TEXTURE_2D, texture,	level); // Force Texture2D, ignore layer...
}

void glshim_glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
    // TODO!
    // create a temp texture
    // glCopyPixel of read FBO
    // set viewport / matrixs
    // glDraw of write FBO
printf("glBlitFramebuffer(%d, %d, %d, %d,  %d, %d, %d, %d,  0x%04X, 0x%04X)\n",
    srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

// direct wrapper

void glGenFramebuffers(GLsizei n, GLuint *ids) __attribute__((alias ("glshim_glGenFramebuffers")));
void glDeleteFramebuffers(GLsizei n, GLuint *framebuffers) __attribute__((alias ("glshim_glDeleteFramebuffers")));
GLboolean glIsFramebuffer(GLuint framebuffer) __attribute__((alias ("glshim_glIsFramebuffer")));
GLenum glCheckFramebufferStatus(GLenum target) __attribute__((alias ("glshim_glCheckFramebufferStatus")));
void glBindFramebuffer(GLenum target, GLuint framebuffer) __attribute__((alias ("glshim_glBindFramebuffer")));
void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level) __attribute__((alias ("glshim_glFramebufferTexture1D")));
void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level) __attribute__((alias ("glshim_glFramebufferTexture2D")));
void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level, GLint layer) __attribute__((alias ("glshim_glFramebufferTexture3D")));
void glGenRenderbuffers(GLsizei n, GLuint *renderbuffers) __attribute__((alias ("glshim_glGenRenderbuffers")));
void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) __attribute__((alias ("glshim_glFramebufferRenderbuffer")));
void glDeleteRenderbuffers(GLsizei n, GLuint *renderbuffers) __attribute__((alias ("glshim_glDeleteRenderbuffers")));
void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) __attribute__((alias ("glshim_glRenderbufferStorage")));
void glBindRenderbuffer(GLenum target, GLuint renderbuffer) __attribute__((alias ("glshim_glBindRenderbuffer")));
GLboolean glIsRenderbuffer(GLuint renderbuffer) __attribute__((alias ("glshim_glIsRenderbuffer")));
void glGenerateMipmap(GLenum target) __attribute__((alias ("glshim_glGenerateMipmap")));
void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params) __attribute__((alias ("glshim_glGetFramebufferAttachmentParameteriv")));
void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params) __attribute__((alias ("glshim_glGetRenderbufferParameteriv")));
void glFramebufferTextureLayer(	GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) __attribute__((alias ("glshim_glFramebufferTextureLayer")));
void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) __attribute__((alias ("glshim_glBlitFramebuffer")));

// EXT direct wrapper
void glGenFramebuffersEXT(GLsizei n, GLuint *ids) __attribute__((alias ("glshim_glGenFramebuffers")));
void glDeleteFramebuffersEXT(GLsizei n, GLuint *framebuffers) __attribute__((alias ("glshim_glDeleteFramebuffers")));
GLboolean glIsFramebufferEXT(GLuint framebuffer) __attribute__((alias ("glshim_glIsFramebuffer")));
GLenum glCheckFramebufferStatusEXT(GLenum target) __attribute__((alias ("glshim_glCheckFramebufferStatus")));
void glBindFramebufferEXT(GLenum target, GLuint framebuffer) __attribute__((alias ("glshim_glBindFramebuffer")));
void glFramebufferTexture1DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level) __attribute__((alias ("glshim_glFramebufferTexture1D")));
void glFramebufferTexture2DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level) __attribute__((alias ("glshim_glFramebufferTexture2D")));
void glFramebufferTexture3DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level, GLint layer) __attribute__((alias ("glshim_glFramebufferTexture3D")));
void glGenRenderbuffersEXT(GLsizei n, GLuint *renderbuffers) __attribute__((alias ("glshim_glGenRenderbuffers")));
void glFramebufferRenderbufferEXT(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) __attribute__((alias ("glshim_glFramebufferRenderbuffer")));
void glDeleteRenderbuffersEXT(GLsizei n, GLuint *renderbuffers) __attribute__((alias ("glshim_glDeleteRenderbuffers")));
void glRenderbufferStorageEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) __attribute__((alias ("glshim_glRenderbufferStorage")));
void glBindRenderbufferEXT(GLenum target, GLuint renderbuffer) __attribute__((alias ("glshim_glBindRenderbuffer")));
GLboolean glIsRenderbufferEXT(GLuint renderbuffer) __attribute__((alias ("glshim_glIsRenderbuffer")));
void glGenerateMipmapEXT(GLenum target) __attribute__((alias ("glshim_glGenerateMipmap")));
void glGetFramebufferAttachmentParameterivEXT(GLenum target, GLenum attachment, GLenum pname, GLint *params) __attribute__((alias ("glshim_glGetFramebufferAttachmentParameteriv")));
void glGetRenderbufferParameterivEXT(GLenum target, GLenum pname, GLint * params) __attribute__((alias ("glshim_glGetRenderbufferParameteriv")));
void glFramebufferTextureLayerEXT(	GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) __attribute__((alias ("glshim_glFramebufferTextureLayer")));
void glBlitFramebufferEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) __attribute__((alias ("glshim_glBlitFramebuffer")));
