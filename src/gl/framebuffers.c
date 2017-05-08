#include "framebuffers.h"
#include "debug.h"
#include "../glx/hardext.h"
#include "init.h"
#ifndef ANDROID
#include <execinfo.h>
#endif

//#define DEBUG
#ifdef DEBUG
#define DBG(a) a
#else
#define DBG(a)
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

GLuint fbo_read = 0;    // if not 0, that's the READ only Framebuffer attached
GLuint fbo_draw = 0;     // if not 0, that's the DRAW only Framebuffer attached

GLuint *old_fbos = NULL;
int nbr_fbos = 0;
int cap_fbos = 0;

int npot(int n);

void readfboBegin() {
    DBG(printf("readfboBegin, fbo status read=%u, draw=%u, main=%u, current=%u\n", fbo_read, fbo_draw, mainfbo_fbo, current_fb);)
    LOAD_GLES_OES(glBindFramebuffer);
	if (!(fbo_read || fbo_draw))
		return;
	GLuint fbo = fbo_read;
	if (!fbo && mainfbo_fbo)
		fbo = mainfbo_fbo;
	gles_glBindFramebuffer(GL_FRAMEBUFFER, fbo);
}

void readfboEnd() {
    DBG(printf("readfboEnd, fbo status read=%u, draw=%u, main=%u, current=%u\n", fbo_read, fbo_draw, mainfbo_fbo, current_fb);)
    LOAD_GLES_OES(glBindFramebuffer);
	if (!(fbo_read || fbo_draw))
		return;
	GLuint fbo = current_fb;
	if (!fbo && mainfbo_fbo)
		fbo = mainfbo_fbo;
	gles_glBindFramebuffer(GL_FRAMEBUFFER, fbo);
}

void gl4es_glGenFramebuffers(GLsizei n, GLuint *ids) {
    DBG(printf("glGenFramebuffers(%i, %p)\n", n, ids);)
    LOAD_GLES_OES(glGenFramebuffers);
    GLsizei m = 0;
    while(globals4es.recyclefbo && (nbr_fbos>0) && (n-m>0)) {
        DBG(printf("Recycled 1 FBO\n");)
        ids[m++] = old_fbos[--nbr_fbos];
    }
    noerrorShim();
    if(n-m == 0)
        return;
    errorGL();
    gles_glGenFramebuffers(n-m, ids+m);
}

void gl4es_glDeleteFramebuffers(GLsizei n, GLuint *framebuffers) {
    DBG(printf("glDeleteFramebuffers(%i, %p), framebuffers[0]=%u\n", n, framebuffers, framebuffers[0]);)
    if (glstate->gl_batch) flush();
    if (globals4es.recyclefbo) {
        DBG(printf("Recycling %i FBOs\n", n);)
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

GLboolean gl4es_glIsFramebuffer(GLuint framebuffer) {
    DBG(printf("glIsFramebuffer(%u)\n", framebuffer);)
    if (glstate->gl_batch) flush();
    LOAD_GLES_OES(glIsFramebuffer);
    
    errorGL();
    return gles_glIsFramebuffer(framebuffer);
}

GLenum fb_status;

GLenum gl4es_glCheckFramebufferStatus(GLenum target) {
    if (glstate->gl_batch) flush();
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
DBG(printf("glCheckFramebufferStatus(0x%04X)=0x%04X\n", target, result);)
    return result;
}

void gl4es_glBindFramebuffer(GLenum target, GLuint framebuffer) {
    DBG(printf("glBindFramebuffer(%s, %u), list=%s, current_fb=%d (draw=%d, read=%d)\n", PrintEnum(target), framebuffer, glstate->list.active?"active":"none", current_fb, fbo_draw, fbo_read);)
    if (glstate->gl_batch) flush();
	PUSH_IF_COMPILING(glBindFramebuffer);
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

GLenum ReadDraw_Push(GLenum target) {
    if(target==GL_FRAMEBUFFER)
        return GL_FRAMEBUFFER;
    LOAD_GLES_OES(glBindFramebuffer);
    if(target==GL_DRAW_FRAMEBUFFER) {
        if(current_fb!=fbo_draw)
            gles_glBindFramebuffer(GL_FRAMEBUFFER, fbo_draw);
        return GL_FRAMEBUFFER;
    }
    if(target==GL_READ_FRAMEBUFFER) {
        if(current_fb!=fbo_read)
            gles_glBindFramebuffer(GL_FRAMEBUFFER, fbo_read);
        return GL_FRAMEBUFFER;
    }
    return target;
}
void ReadDraw_Pop(GLenum target) {
    if(target==GL_FRAMEBUFFER)
        return;
    LOAD_GLES_OES(glBindFramebuffer);
    if(target==GL_DRAW_FRAMEBUFFER && current_fb!=fbo_draw) {
        gles_glBindFramebuffer(GL_FRAMEBUFFER, (mainfbo_fbo && (current_fb==0))?mainfbo_fbo:current_fb);
    }
    if(target==GL_READ_FRAMEBUFFER && current_fb!=fbo_read) {
        gles_glBindFramebuffer(GL_FRAMEBUFFER, (mainfbo_fbo && (current_fb==0))?mainfbo_fbo:current_fb);
    }
}

void gl4es_glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level) {
    DBG(printf("glFramebufferTexture2D(%s, %s, %s, %u, %i) current_fb=%d (draw=%d, read=%d)\n", PrintEnum(target), PrintEnum(attachment), PrintEnum(textarget), texture, level, current_fb, fbo_draw, fbo_read);)
    static GLuint scrap_tex = 0;
    static int scrap_width = 0;
    static int scrap_height = 0;
    
    if (glstate->gl_batch) flush();
    LOAD_GLES_OES(glFramebufferTexture2D);
    LOAD_GLES(glTexImage2D);
    LOAD_GLES(glBindTexture);
		
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
        khash_t(tex) *list = glstate->texture.list;
        if (! list) {
            list = glstate->texture.list = kh_init(tex);
            // segfaults if we don't do a single put
            kh_put(tex, list, 1, &ret);
            kh_del(tex, list, 1);
        }
        k = kh_get(tex, list, texture);
        
        if (k == kh_end(list)){
            LOGE("LIBGL: texture for FBO not found, name=%u\n", texture);
        } else {
            tex = kh_value(list, k);
            texture = tex->glname;
            // check if texture is shrinked...
            if (tex->shrink) {
                LOGD("LIBGL: unshrinking shrinked texture for FBO\n");
                tex->width *= 2*tex->shrink;
                tex->height *= 2*tex->shrink;
                tex->nwidth = hardext.npot==2?tex->width:npot(tex->width);
                tex->nheight = hardext.npot==2?tex->height:npot(tex->height);
                tex->shrink = 0;
                gltexture_t *bound = glstate->texture.bound[glstate->texture.active][ENABLED_TEX2D];
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
                gltexture_t *bound = glstate->texture.bound[glstate->texture.active][ENABLED_TEX2D];
                GLuint oldtex = (bound)?bound->glname:0;
                if (oldtex!=tex->glname) gles_glBindTexture(GL_TEXTURE_2D, tex->glname);
                gles_glTexImage2D(GL_TEXTURE_2D, 0, tex->format, tex->nwidth, tex->nheight, 0, tex->format, tex->type, NULL);
                if (oldtex!=tex->glname) gles_glBindTexture(GL_TEXTURE_2D, oldtex);
            }*/
            DBG(printf("found texture, glname=%u, size=%ix%i(%ix%i), format/type=0x%04X/0x%04X\n", texture, tex->width, tex->height, tex->nwidth, tex->nheight, tex->format, tex->type);)
        }
    }
    
    GLenum ntarget = ReadDraw_Push(target);

    if(attachment==GL_DEPTH_ATTACHMENT /*&& hardext.depthtex==0*/) {
        noerrorShim();
        if (level!=0) return;
        // let's create a renderbuffer and attach it instead of the (presumably) depth texture
        GLuint render_depth;    // memory leak here...
        gl4es_glGenRenderbuffers(1, &render_depth);
        gl4es_glBindRenderbuffer(GL_RENDERBUFFER, render_depth);
        gl4es_glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, twidth, theight);
        gl4es_glBindRenderbuffer(GL_RENDERBUFFER, 0);
        errorGL();
        gl4es_glFramebufferRenderbuffer(ntarget, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, render_depth);
        ReadDraw_Pop(target);
        return;
    }

    twidth = twidth >> level; if(twidth<1) twidth=1;
    theight = theight >> level; if(theight<1) theight=1;
    
	if (level!=0) {
        //bind a scrap texture, we don't want level != 0 binding on GLES
        if(!scrap_tex)
            gl4es_glGenTextures(1, &scrap_tex);
        if ((scrap_width!=twidth) || (scrap_height!=theight)) {
                scrap_width = twidth;
                scrap_height = theight;
                gltexture_t *bound = glstate->texture.bound[glstate->texture.active][ENABLED_TEX2D];
                GLuint oldtex = (bound)?bound->glname:0;
                if (oldtex!=scrap_tex) gles_glBindTexture(GL_TEXTURE_2D, scrap_tex);
                gles_glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, scrap_width, scrap_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
                if (oldtex!=scrap_tex) gles_glBindTexture(GL_TEXTURE_2D, oldtex);
        }
        texture = scrap_tex;
    }
    
    errorGL();
    gles_glFramebufferTexture2D(ntarget, attachment, textarget, texture, 0);
    ReadDraw_Pop(target);
}

void gl4es_glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level) {
    gl4es_glFramebufferTexture2D(target, attachment, GL_TEXTURE_2D, texture, level);
}
void gl4es_glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level, GLint layer) {
    (void)layer;
    gl4es_glFramebufferTexture2D(target, attachment, GL_TEXTURE_2D, texture, level);
}

void gl4es_glGenRenderbuffers(GLsizei n, GLuint *renderbuffers) {
    DBG(printf("glGenRenderbuffers(%i, %p)\n", n, renderbuffers);)
    LOAD_GLES_OES(glGenRenderbuffers);
    
    errorGL();
    gles_glGenRenderbuffers(n, renderbuffers);
}

void gl4es_glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
    DBG(printf("glFramebufferRenderbuffer(%s, %s, %s, %u)\n", PrintEnum(target), PrintEnum(attachment), PrintEnum(renderbuffertarget), renderbuffer);)
    LOAD_GLES_OES(glFramebufferRenderbuffer);
    LOAD_GLES_OES(glGetFramebufferAttachmentParameteriv);

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
    
    GLenum ntarget = ReadDraw_Push(target);

    if ((current_fb!=0) && (renderbuffer!=0) && ((attachment==GL_DEPTH_ATTACHMENT) || (attachment==GL_STENCIL_ATTACHMENT))) {
        GLuint tmp;
        gles_glGetFramebufferAttachmentParameteriv(ntarget, attachment, GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME, &tmp);
        if (tmp==renderbuffer) {
            noerrorShim();
            ReadDraw_Pop(target);
            return;
        }
    }

    errorGL();
    gles_glFramebufferRenderbuffer(ntarget, attachment, renderbuffertarget, renderbuffer);
    ReadDraw_Pop(target);
}

void gl4es_glDeleteRenderbuffers(GLsizei n, GLuint *renderbuffers) {
    DBG(printf("glDeleteRenderbuffer(%d, %p)\n", n, renderbuffers);)
    if (glstate->gl_batch) flush();
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

void gl4es_glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
    DBG(printf("glRenderbufferStorage(%s, %s, %i, %i)\n", PrintEnum(target), PrintEnum(internalformat), width, height);)
    LOAD_GLES_OES(glRenderbufferStorage);
    LOAD_GLES_OES(glGenRenderbuffers);
    LOAD_GLES_OES(glBindRenderbuffer);
    
    errorGL();
    width = hardext.npot==2?width:npot(width);
    height = hardext.npot==2?height:npot(height);
    // check if internal format is GL_DEPTH_STENCIL_EXT
    if (internalformat == GL_DEPTH_STENCIL)
        internalformat = GL_DEPTH24_STENCIL8;
    // in that case, create first a STENCIL one then a DEPTH one....
    if ((internalformat == GL_DEPTH24_STENCIL8) && (hardext.depthstencil==0)) {
        khint_t k;
        int ret;
        internalformat = (hardext.depth24)?GL_DEPTH_COMPONENT24:GL_DEPTH_COMPONENT16;
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
    else if (internalformat == GL_DEPTH_COMPONENT)    // Not much is supported on GLES...
        internalformat = GL_DEPTH_COMPONENT16;
    else if (internalformat == GL_RGB8 && hardext.rgba8==0)
        internalformat = GL_RGB565_OES;
    else if (internalformat == GL_RGBA8 && hardext.rgba8==0)
        internalformat = GL_RGBA4_OES;

    gles_glRenderbufferStorage(target, internalformat, width, height);
}

void gl4es_glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {    //STUB
    gl4es_glRenderbufferStorage(target, internalformat, width, height);
}

void gl4es_glBindRenderbuffer(GLenum target, GLuint renderbuffer) {
    DBG(printf("glBindRenderbuffer(%s, %u), binded Fbo=%u\n", PrintEnum(target), renderbuffer, current_fb);)
    if (glstate->gl_batch) flush();
    LOAD_GLES_OES(glBindRenderbuffer);
    
    current_rb = renderbuffer;
    
    errorGL();
    gles_glBindRenderbuffer(target, renderbuffer);
}

GLboolean gl4es_glIsRenderbuffer(GLuint renderbuffer) {
    DBG(printf("glIsRenderbuffer(%u)\n", renderbuffer);)
    if (glstate->gl_batch) flush();
    LOAD_GLES_OES(glIsRenderbuffer);
    
    errorGL();
    return gles_glIsRenderbuffer(renderbuffer);
}

void gl4es_glGenerateMipmap(GLenum target) {
    DBG(printf("glGenerateMipmap(%s)\n", PrintEnum(target));)
    LOAD_GLES_OES(glGenerateMipmap);
    
    errorGL();
    if(globals4es.automipmap != 3)
        gles_glGenerateMipmap(target);
}

void gl4es_glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params) {
    DBG(printf("glGetFramebufferAttachmentParameteriv(%s, %s, %s, %p)\n", PrintEnum(target), PrintEnum(attachment), PrintEnum(pname), params);)
    LOAD_GLES_OES(glGetFramebufferAttachmentParameteriv);
    
    GLenum ntarget = ReadDraw_Push(target);
    // hack to return DEPTH size
    if(ntarget==GL_FRAMEBUFFER && attachment==GL_DEPTH_ATTACHMENT && pname==GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE && hardext.depthtex==0) {
        noerrorShim();
        gl4es_glGetFramebufferAttachmentParameteriv(ntarget, attachment, GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME, params);
        if (params)
            *params = 16;   //Depth buffer is 16 on GLES. No check for 24 bits here...
        ReadDraw_Pop(target);
        return;
    }
    
    errorGL();
    gles_glGetFramebufferAttachmentParameteriv(ntarget, attachment, pname, params);
    ReadDraw_Pop(target);
}

void gl4es_glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    DBG(printf("glGetRenderbufferParameteriv(%s, %s, %p)\n", PrintEnum(target), PrintEnum(pname), params);)
    LOAD_GLES_OES(glGetRenderbufferParameteriv);
    
    errorGL();
    gles_glGetRenderbufferParameteriv(target, pname, params);
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
    if (glstate->texture.active != 0)
        gles_glActiveTexture(GL_TEXTURE0);
    if (glstate->texture.client != 0)
        gles_glClientActiveTexture(GL_TEXTURE0);
        
    mainfbo_width = width;
    mainfbo_height = height;
    mainfbo_nwidth = width = hardext.npot==2?width:npot(width);
    mainfbo_nheight = height = hardext.npot==2?width:npot(height);

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
    if (glstate->texture.bound[0][ENABLED_TEX2D]) 
        gles_glBindTexture(GL_TEXTURE_2D, glstate->texture.bound[0][ENABLED_TEX2D]->glname);
    if (glstate->texture.active != 0)
        gles_glActiveTexture(GL_TEXTURE0 + glstate->texture.active);
    if (glstate->texture.client != 0)
        gles_glClientActiveTexture(GL_TEXTURE0 + glstate->texture.client);
    
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
    int old_tex = glstate->texture.active;
    int old_client = glstate->texture.client;
    if (glstate->texture.active != 0)
        gl4es_glActiveTexture(GL_TEXTURE0);
    if (glstate->texture.client != 0)
        gl4es_glClientActiveTexture(GL_TEXTURE0);
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
        
        gl4es_glPushAttrib(GL_TEXTURE_BIT | GL_ENABLE_BIT | GL_TRANSFORM_BIT | GL_COLOR_BUFFER_BIT | GL_CURRENT_BIT);

        gl4es_glMatrixMode(GL_TEXTURE);
        gl4es_glPushMatrix();
        gl4es_glLoadIdentity();
        gl4es_glMatrixMode(GL_PROJECTION);
        gl4es_glPushMatrix();
        gl4es_glLoadIdentity();
        gl4es_glMatrixMode(GL_MODELVIEW);
        gl4es_glPushMatrix();
        gl4es_glLoadIdentity();
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

        gl4es_glPushClientAttrib(GL_CLIENT_VERTEX_ARRAY_BIT);

        gl4es_glDisable(GL_DEPTH_TEST);
        gl4es_glDisable(GL_LIGHTING);
        gl4es_glDisable(GL_CULL_FACE);
        gl4es_glDisable(GL_ALPHA_TEST);
        gl4es_glDisable(GL_BLEND);

//        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    
        if(!glstate->clientstate.vertex_array) {
            gles_glEnableClientState(GL_VERTEX_ARRAY);
            glstate->clientstate.vertex_array = 1;
        }
        gles_glVertexPointer(2, GL_FLOAT, 0, vert);
        if(!glstate->clientstate.tex_coord_array[0]) {
            gles_glEnableClientState(GL_TEXTURE_COORD_ARRAY);
            glstate->clientstate.tex_coord_array[0] = 1;
        }
        gles_glTexCoordPointer(2, GL_FLOAT, 0, tex);
        for (int a=1; a <MAX_TEX; a++)
            if(glstate->clientstate.tex_coord_array[a]) {
                gl4es_glClientActiveTexture(GL_TEXTURE0 + a);
                gles_glDisableClientState(GL_TEXTURE_COORD_ARRAY);
                glstate->clientstate.tex_coord_array[a] = 0;
            }
        if(glstate->clientstate.color_array) {
            gles_glDisableClientState(GL_COLOR_ARRAY);
            glstate->clientstate.color_array = 0;
        }
        if(glstate->clientstate.normal_array) {
            gles_glDisableClientState(GL_NORMAL_ARRAY);
            glstate->clientstate.normal_array = 0;
        }


        gl4es_glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
        
        gles_glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
        // All the previous states are Pushed / Poped anyway...
        gl4es_glPopClientAttrib();
        gl4es_glMatrixMode(GL_MODELVIEW);
        gl4es_glPopMatrix();
        gl4es_glMatrixMode(GL_PROJECTION);
        gl4es_glPopMatrix();
        gl4es_glMatrixMode(GL_TEXTURE);
        gl4es_glPopMatrix();
        gl4es_glPopAttrib();
    }
    #endif
    // put back viewport
    gles_glViewport(old_vp[0], old_vp[1], old_vp[2], old_vp[3]);
    // Put everything back
    if (glstate->texture.bound[0][ENABLED_TEX2D]) 
        gles_glBindTexture(GL_TEXTURE_2D, glstate->texture.bound[0][ENABLED_TEX2D]->glname);
    else
        gles_glBindTexture(GL_TEXTURE_2D, 0);
    if (!IS_TEX2D(glstate->enable.texture[0]))
        gles_glDisable(GL_TEXTURE_2D);
    if (old_tex != 0)
        gl4es_glActiveTexture(GL_TEXTURE0 + old_tex);
    if (old_client != 0)
        gl4es_glClientActiveTexture(GL_TEXTURE0 + old_client);
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

void gl4es_glFramebufferTextureLayer(	GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
    gl4es_glFramebufferTexture2D(target, attachment, GL_TEXTURE_2D, texture,	level); // Force Texture2D, ignore layer...
}

void gl4es_glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
    // TODO!
    // create a temp texture
    // glCopyPixel of read FBO
    // set viewport / matrixs
    // glDraw of write FBO
DBG(printf("glBlitFramebuffer(%d, %d, %d, %d,  %d, %d, %d, %d,  0x%04X, 0x%04X)\n",
    srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);)
}

// direct wrapper

void glGenFramebuffers(GLsizei n, GLuint *ids) AliasExport("gl4es_glGenFramebuffers");
void glDeleteFramebuffers(GLsizei n, GLuint *framebuffers) AliasExport("gl4es_glDeleteFramebuffers");
GLboolean glIsFramebuffer(GLuint framebuffer) AliasExport("gl4es_glIsFramebuffer");
GLenum glCheckFramebufferStatus(GLenum target) AliasExport("gl4es_glCheckFramebufferStatus");
void glBindFramebuffer(GLenum target, GLuint framebuffer) AliasExport("gl4es_glBindFramebuffer");
void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level) AliasExport("gl4es_glFramebufferTexture1D");
void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level) AliasExport("gl4es_glFramebufferTexture2D");
void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level, GLint layer) AliasExport("gl4es_glFramebufferTexture3D");
void glGenRenderbuffers(GLsizei n, GLuint *renderbuffers) AliasExport("gl4es_glGenRenderbuffers");
void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) AliasExport("gl4es_glFramebufferRenderbuffer");
void glDeleteRenderbuffers(GLsizei n, GLuint *renderbuffers) AliasExport("gl4es_glDeleteRenderbuffers");
void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) AliasExport("gl4es_glRenderbufferStorage");
void glBindRenderbuffer(GLenum target, GLuint renderbuffer) AliasExport("gl4es_glBindRenderbuffer");
GLboolean glIsRenderbuffer(GLuint renderbuffer) AliasExport("gl4es_glIsRenderbuffer");
void glGenerateMipmap(GLenum target) AliasExport("gl4es_glGenerateMipmap");
void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params) AliasExport("gl4es_glGetFramebufferAttachmentParameteriv");
void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params) AliasExport("gl4es_glGetRenderbufferParameteriv");
void glFramebufferTextureLayer(	GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) AliasExport("gl4es_glFramebufferTextureLayer");
void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) AliasExport("gl4es_glBlitFramebuffer");

// EXT direct wrapper
void glGenFramebuffersEXT(GLsizei n, GLuint *ids) AliasExport("gl4es_glGenFramebuffers");
void glDeleteFramebuffersEXT(GLsizei n, GLuint *framebuffers) AliasExport("gl4es_glDeleteFramebuffers");
GLboolean glIsFramebufferEXT(GLuint framebuffer) AliasExport("gl4es_glIsFramebuffer");
GLenum glCheckFramebufferStatusEXT(GLenum target) AliasExport("gl4es_glCheckFramebufferStatus");
void glBindFramebufferEXT(GLenum target, GLuint framebuffer) AliasExport("gl4es_glBindFramebuffer");
void glFramebufferTexture1DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level) AliasExport("gl4es_glFramebufferTexture1D");
void glFramebufferTexture2DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level) AliasExport("gl4es_glFramebufferTexture2D");
void glFramebufferTexture3DEXT(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level, GLint layer) AliasExport("gl4es_glFramebufferTexture3D");
void glGenRenderbuffersEXT(GLsizei n, GLuint *renderbuffers) AliasExport("gl4es_glGenRenderbuffers");
void glFramebufferRenderbufferEXT(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) AliasExport("gl4es_glFramebufferRenderbuffer");
void glDeleteRenderbuffersEXT(GLsizei n, GLuint *renderbuffers) AliasExport("gl4es_glDeleteRenderbuffers");
void glRenderbufferStorageEXT(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) AliasExport("gl4es_glRenderbufferStorage");
void glBindRenderbufferEXT(GLenum target, GLuint renderbuffer) AliasExport("gl4es_glBindRenderbuffer");
GLboolean glIsRenderbufferEXT(GLuint renderbuffer) AliasExport("gl4es_glIsRenderbuffer");
void glGenerateMipmapEXT(GLenum target) AliasExport("gl4es_glGenerateMipmap");
void glGetFramebufferAttachmentParameterivEXT(GLenum target, GLenum attachment, GLenum pname, GLint *params) AliasExport("gl4es_glGetFramebufferAttachmentParameteriv");
void glGetRenderbufferParameterivEXT(GLenum target, GLenum pname, GLint * params) AliasExport("gl4es_glGetRenderbufferParameteriv");
void glFramebufferTextureLayerEXT(	GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) AliasExport("gl4es_glFramebufferTextureLayer");
void glBlitFramebufferEXT(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) AliasExport("gl4es_glBlitFramebuffer");
