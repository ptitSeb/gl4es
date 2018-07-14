#include "framebuffers.h"
#include "debug.h"
#include "../glx/hardext.h"
#include "init.h"
#if !defined(ANDROID) && !defined(AMIGAOS4)
#include <execinfo.h>
#endif
#include "blit.h"

//#define DEBUG
#ifdef DEBUG
#define DBG(a) a
#else
#define DBG(a)
#endif

//extern void* eglGetProcAddress(const char* name);

int npot(int n);
int wrap_npot(GLenum wrap);

void readfboBegin() {
	if (glstate->fbo.fbo_read == glstate->fbo.fbo_draw)
        return;
    DBG(printf("readfboBegin, fbo status read=%u, draw=%u, main=%u, current=%u\n", glstate->fbo.fbo_read, glstate->fbo.fbo_draw, glstate->fbo.mainfbo_fbo, glstate->fbo.current_fb);)
    LOAD_GLES2_OR_OES(glBindFramebuffer);
	GLuint fbo = glstate->fbo.fbo_read;
	if (!fbo)
		fbo = glstate->fbo.mainfbo_fbo;
	gles_glBindFramebuffer(GL_FRAMEBUFFER, fbo);
}

void readfboEnd() {
	if (glstate->fbo.fbo_read == glstate->fbo.fbo_draw)
        return;
    DBG(printf("readfboEnd, fbo status read=%u, draw=%u, main=%u, current=%u\n", glstate->fbo.fbo_read, glstate->fbo.fbo_draw, glstate->fbo.mainfbo_fbo, glstate->fbo.current_fb);)
    LOAD_GLES2_OR_OES(glBindFramebuffer);
	GLuint fbo = glstate->fbo.current_fb;
	if (!fbo)
		fbo = glstate->fbo.mainfbo_fbo;
	gles_glBindFramebuffer(GL_FRAMEBUFFER, fbo);
}

void attach_fbotexture(GLuint fbo, GLuint texture, int width, int height) {
    DBG(printf("attach_fbotexture(%d, %d)\n", fbo, texture);)
    int idx = -1;
    if(glstate->fbo.mainfbo_fbo && !fbo)
        fbo = glstate->fbo.mainfbo_fbo;
    if(glstate->fbo.tex_fbo) {
        for (int i=0; i<glstate->fbo.nbr_fbot && idx==-1; i++)
            if(glstate->fbo.tex_fbo[i].framebuffer==fbo) 
                idx = i;
    }
    if (idx!=-1) {
        glstate->fbo.tex_fbo[idx].texture = texture;
        glstate->fbo.tex_fbo[idx].width = width;
        glstate->fbo.tex_fbo[idx].height = height;
    } else {
        if(glstate->fbo.nbr_fbot == glstate->fbo.cap_fbot) {
            glstate->fbo.cap_fbot += 16;
            glstate->fbo.tex_fbo = (gltexframebuffer_t*)realloc(glstate->fbo.tex_fbo, glstate->fbo.cap_fbot*sizeof(gltexframebuffer_t));
        }
        idx = glstate->fbo.nbr_fbot++;
        glstate->fbo.tex_fbo[idx].framebuffer = fbo;
        glstate->fbo.tex_fbo[idx].texture = texture;
        glstate->fbo.tex_fbo[idx].width = width;
        glstate->fbo.tex_fbo[idx].height = height;
    }
}

void detach_fbotexture(GLuint fbo) {
    DBG(printf("detach_fbotexture(%d)\n", fbo);)
    int idx = -1;
    if(glstate->fbo.mainfbo_fbo && !fbo)
        fbo = glstate->fbo.mainfbo_fbo;
    if(glstate->fbo.tex_fbo) {
        for (int i=0; i<glstate->fbo.nbr_fbot && idx==-1; i++)
            if(glstate->fbo.tex_fbo[i].framebuffer==fbo) 
                idx = i;
    }
    if(idx==-1)
        return;
    if(idx<glstate->fbo.nbr_fbot)
        memmove(&glstate->fbo.tex_fbo[idx+1], &glstate->fbo.tex_fbo[idx], sizeof(gltexframebuffer_t)*(glstate->fbo.nbr_fbot-(idx+1)));
    
    --glstate->fbo.nbr_fbot;
}

int find_fbotexture(GLuint fbo, GLuint *texture, int *width, int *height) {
    DBG(printf("find_fbotexture(%d)", fbo);)
    int idx = -1;
    if(glstate->fbo.mainfbo_fbo && !fbo)
        fbo = glstate->fbo.mainfbo_fbo;
    if(glstate->fbo.tex_fbo) {
        for (int i=0; i<glstate->fbo.nbr_fbot && idx==-1; i++)
            if(glstate->fbo.tex_fbo[i].framebuffer==fbo) 
                idx = i;
    }
    if(width) *width=(idx==-1)?glstate->fbo.mainfbo_width:glstate->fbo.tex_fbo[idx].width;
    if(height) *height=(idx==-1)?glstate->fbo.mainfbo_height:glstate->fbo.tex_fbo[idx].height;
    if(texture) *texture=(idx==-1)?0:glstate->fbo.tex_fbo[idx].texture;
    
    DBG(printf(" => %d\n", (idx==-1)?0:glstate->fbo.tex_fbo[idx].texture);)

    return (idx==-1)?0:1;
}

void gl4es_glGenFramebuffers(GLsizei n, GLuint *ids) {
    DBG(printf("glGenFramebuffers(%i, %p)\n", n, ids);)
    LOAD_GLES2_OR_OES(glGenFramebuffers);
    GLsizei m = 0;
    while(globals4es.recyclefbo && (glstate->fbo.nbr_fbos>0) && (n-m>0)) {
        DBG(printf("Recycled 1 FBO\n");)
        ids[m++] = glstate->fbo.old_fbos[--glstate->fbo.nbr_fbos];
    }
    noerrorShim();
    if(n-m == 0)
        return;
    errorGL();
    gles_glGenFramebuffers(n-m, ids+m);
}

void gl4es_glDeleteFramebuffers(GLsizei n, GLuint *framebuffers) {
    DBG(printf("glDeleteFramebuffers(%i, %p), framebuffers[0]=%u\n", n, framebuffers, framebuffers[0]);)
    for (int i=0; i<n; i++)
        detach_fbotexture(framebuffers[i]);

    if (globals4es.recyclefbo) {
        DBG(printf("Recycling %i FBOs\n", n);)
        noerrorShim();
        if(glstate->fbo.cap_fbos == 0) {
            glstate->fbo.cap_fbos = 16;
            glstate->fbo.old_fbos = (GLuint*)malloc(glstate->fbo.cap_fbos * sizeof(GLuint));
        }
        if (glstate->fbo.nbr_fbos+n == glstate->fbo.cap_fbos) {
            glstate->fbo.cap_fbos += n;
            glstate->fbo.old_fbos = (GLuint*)realloc(glstate->fbo.old_fbos, glstate->fbo.cap_fbos *sizeof(GLuint));
        }
        memcpy(glstate->fbo.old_fbos+glstate->fbo.nbr_fbos, framebuffers, n*sizeof(GLuint));
        glstate->fbo.nbr_fbos += n;
    } else {
        LOAD_GLES2_OR_OES(glDeleteFramebuffers);
        errorGL();
        gles_glDeleteFramebuffers(n, framebuffers);
    }
}

GLboolean gl4es_glIsFramebuffer(GLuint framebuffer) {
    DBG(printf("glIsFramebuffer(%u)\n", framebuffer);)
    LOAD_GLES2_OR_OES(glIsFramebuffer);
    
    errorGL();
    return gles_glIsFramebuffer(framebuffer);
}

//#define BEFORE 1
GLenum gl4es_glCheckFramebufferStatus(GLenum target) {
#ifdef BEFORE
    GLenum result = glstate->fbo.fb_status;
    noerrorShim();
#else
    LOAD_GLES2_OR_OES(glCheckFramebufferStatus);
    
    errorGL();
    GLenum result = gles_glCheckFramebufferStatus(target);
#endif
DBG(printf("glCheckFramebufferStatus(0x%04X)=0x%04X\n", target, result);)
    return result;
}

void gl4es_glBindFramebuffer(GLenum target, GLuint framebuffer) {
    DBG(printf("glBindFramebuffer(%s, %u), list=%s, glstate->fbo.current_fb=%d (draw=%d, read=%d)\n", PrintEnum(target), framebuffer, glstate->list.active?"active":"none", glstate->fbo.current_fb, glstate->fbo.fbo_draw, glstate->fbo.fbo_read);)
	PUSH_IF_COMPILING(glBindFramebuffer);
    LOAD_GLES2_OR_OES(glBindFramebuffer);
//    LOAD_GLES2_OR_OES(glCheckFramebufferStatus);
    LOAD_GLES(glGetError);
        
    if (target == GL_FRAMEBUFFER) {
        glstate->fbo.fbo_read = framebuffer;
        glstate->fbo.fbo_draw = framebuffer;
    }
    
    if (target == GL_READ_FRAMEBUFFER) {
		glstate->fbo.fbo_read = framebuffer;
        noerrorShim();
        glstate->fbo.fb_status = GL_FRAMEBUFFER_COMPLETE;
		return;	//don't bind for now
	}
        
    if (target == GL_DRAW_FRAMEBUFFER) {
		target = GL_FRAMEBUFFER;
		glstate->fbo.fbo_draw = framebuffer;
	}
    
    if(target==GL_FRAMEBUFFER && framebuffer!=0) {
        gles_glBindFramebuffer(target, 0);
        //gles_glCheckFramebufferStatus(target);
    }
        
    glstate->fbo.current_fb = framebuffer;

    if (framebuffer==0)
        framebuffer = glstate->fbo.mainfbo_fbo;
        
    gles_glBindFramebuffer(target, framebuffer);
    GLenum err=gles_glGetError();
    errorShim(err);
    
//    glstate->fbo.fb_status = (framebuffer==0)?GL_FRAMEBUFFER_COMPLETE:gles_glCheckFramebufferStatus(target);
}
#undef BEFORE

GLenum ReadDraw_Push(GLenum target) {
    if(target==GL_FRAMEBUFFER)
        return GL_FRAMEBUFFER;
    LOAD_GLES2_OR_OES(glBindFramebuffer);
    if(target==GL_DRAW_FRAMEBUFFER) {
        if(glstate->fbo.current_fb!=glstate->fbo.fbo_draw)
            gles_glBindFramebuffer(GL_FRAMEBUFFER, (glstate->fbo.fbo_draw)?glstate->fbo.fbo_draw:glstate->fbo.mainfbo_fbo);
        return GL_FRAMEBUFFER;
    }
    if(target==GL_READ_FRAMEBUFFER) {
        if(glstate->fbo.current_fb!=glstate->fbo.fbo_read)
            gles_glBindFramebuffer(GL_FRAMEBUFFER, (glstate->fbo.fbo_read)?glstate->fbo.fbo_read:glstate->fbo.mainfbo_fbo);
        return GL_FRAMEBUFFER;
    }
    return target;
}
void ReadDraw_Pop(GLenum target) {
    if(target==GL_FRAMEBUFFER)
        return;
    LOAD_GLES2_OR_OES(glBindFramebuffer);
    if(target==GL_DRAW_FRAMEBUFFER && glstate->fbo.current_fb!=glstate->fbo.fbo_draw) {
        gles_glBindFramebuffer(GL_FRAMEBUFFER, (glstate->fbo.current_fb)?glstate->fbo.current_fb:glstate->fbo.mainfbo_fbo);
    }
    if(target==GL_READ_FRAMEBUFFER && glstate->fbo.current_fb!=glstate->fbo.fbo_read) {
        gles_glBindFramebuffer(GL_FRAMEBUFFER, (glstate->fbo.current_fb)?glstate->fbo.current_fb:glstate->fbo.mainfbo_fbo);
    }
}

void gl4es_glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level) {
    DBG(printf("glFramebufferTexture2D(%s, %s, %s, %u, %i) glstate->fbo.current_fb=%d (draw=%d, read=%d)\n", PrintEnum(target), PrintEnum(attachment), PrintEnum(textarget), texture, level, glstate->fbo.current_fb, glstate->fbo.fbo_draw, glstate->fbo.fbo_read);)
    static GLuint scrap_tex = 0;
    static int scrap_width = 0;
    static int scrap_height = 0;
    
    LOAD_GLES2_OR_OES(glFramebufferTexture2D);
    LOAD_GLES(glTexImage2D);
    LOAD_GLES(glBindTexture);
    LOAD_GLES(glActiveTexture);
    LOAD_GLES(glTexParameteri);

    // Ignore Color attachment 1 .. 9
    if ((attachment>=GL_COLOR_ATTACHMENT0+1) && (attachment<=GL_COLOR_ATTACHMENT0+9)) {
        errorShim(GL_INVALID_ENUM);
        return;
    }
    
    int twidth = 0, theight = 0;
    // find texture and get it's real name
    gltexture_t *tex = NULL;
    if (texture) {
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
            if (tex->shrink || tex->useratio || (tex->adjust && hardext.npot==1 && !globals4es.potframebuffer)) {
                LOGD("LIBGL: %s texture for FBO\n",(tex->useratio)?"going back to npot size pot'ed":"unshrinking shrinked");
                if(tex->shrink || tex->useratio) {
                    if(tex->useratio) {
                        tex->width = tex->nwidth/tex->ratiox;
                        tex->height = tex->nheight/tex->ratioy;
                    } else {
                        tex->width *= 1<<tex->shrink;
                        tex->height *= 1<<tex->shrink;
                    }
                }
                tex->nwidth = (hardext.npot>0 || hardext.esversion>1)?tex->width:npot(tex->width);
                tex->nheight = (hardext.npot>0 || hardext.esversion>1)?tex->height:npot(tex->height);
                tex->adjustxy[0] = (float)tex->width / tex->nwidth;
                tex->adjustxy[1] = (float)tex->height / tex->nheight;
                tex->adjust=(tex->width!=tex->nwidth || tex->height!=tex->nheight);
                tex->shrink = 0; tex->useratio = 0;
                int oldactive = glstate->texture.active;
                if(oldactive) gles_glActiveTexture(GL_TEXTURE0);
                gltexture_t *bound = glstate->texture.bound[0/*glstate->texture.active*/][ENABLED_TEX2D];
                GLuint oldtex = bound->glname;
                if(hardext.npot==1 && !(wrap_npot(tex->wrap_s) && wrap_npot(tex->wrap_t))) {
                    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
                    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
                    tex->adjust = 0;
                }
                if (oldtex!=tex->glname) gles_glBindTexture(GL_TEXTURE_2D, tex->glname);
                gles_glTexImage2D(GL_TEXTURE_2D, 0, tex->format, tex->nwidth, tex->nheight, 0, tex->format, tex->type, NULL);
                if (oldtex!=tex->glname) gles_glBindTexture(GL_TEXTURE_2D, oldtex);
                if(oldactive) gles_glActiveTexture(GL_TEXTURE0+oldactive);
            }
            if(globals4es.potframebuffer && (npot(twidth)!=twidth || npot(theight!=theight))) {
                // check if POT size is asked
                LOGD("LIBGL: Resize to POT dimension texture for FBO\n");
                twidth = tex->nwidth = npot(tex->nwidth);
                theight = tex->nheight = npot(tex->nheight);
                tex->adjustxy[0] = (float)tex->width / tex->nwidth;
                tex->adjustxy[1] = (float)tex->height / tex->nheight;
                tex->adjust=(tex->width!=tex->nwidth || tex->height!=tex->nheight);
                int oldactive = glstate->texture.active;
                if(oldactive) gles_glActiveTexture(GL_TEXTURE0);
                gltexture_t *bound = glstate->texture.bound[0/*glstate->texture.active*/][ENABLED_TEX2D];
                GLuint oldtex = bound->glname;
                if (oldtex!=tex->glname) gles_glBindTexture(GL_TEXTURE_2D, tex->glname);
                gles_glTexImage2D(GL_TEXTURE_2D, 0, tex->format, tex->nwidth, tex->nheight, 0, tex->format, tex->type, NULL);
                if (oldtex!=tex->glname) gles_glBindTexture(GL_TEXTURE_2D, oldtex);
                if(oldactive) gles_glActiveTexture(GL_TEXTURE0+oldactive);
            }
            twidth = tex->nwidth;
            theight = tex->nheight;
 /*           if ((tex->width<32) || (tex->height<32)) {
                printf("LIBGL: enlarging too-small texture for FBO\n");
                tex->nwidth = (tex->nwidth<32)?32:tex->nwidth;
                tex->nheight = (tex->nheight<32)?32:tex->nheight;
                tex->shrink = 0;
                gltexture_t *bound = glstate->texture.bound[glstate->texture.active][ENABLED_TEX2D];
                GLuint oldtex = bound->glname;
                if (oldtex!=tex->glname) gles_glBindTexture(GL_TEXTURE_2D, tex->glname);
                gles_glTexImage2D(GL_TEXTURE_2D, 0, tex->format, tex->nwidth, tex->nheight, 0, tex->format, tex->type, NULL);
                if (oldtex!=tex->glname) gles_glBindTexture(GL_TEXTURE_2D, oldtex);
            }*/
            if (attachment == GL_COLOR_ATTACHMENT0)
                attach_fbotexture(glstate->fbo.current_fb, tex->texture, tex->width, tex->height);    // track the attached texture for glBlitFramebuffer
            DBG(printf("found texture, glname=%u, size=%ix%i(%ix%i), format/type=%s/%s\n", texture, tex->width, tex->height, tex->nwidth, tex->nheight, PrintEnum(tex->format), PrintEnum(tex->type));)
        }
    }
    
    GLenum ntarget = ReadDraw_Push(target);

    if(tex) {
        tex->binded_fbo = glstate->fbo.current_fb;
        tex->binded_attachment = attachment;
    }

    if(attachment==GL_DEPTH_ATTACHMENT /*&& hardext.depthtex==0*/) {
        noerrorShim();
        if (level!=0) return;
        if(hardext.depthtex && tex) {
            // depth texture supported!
            //check if texture needs to be re-created ad true depth texture
            if(tex->format!=GL_DEPTH_COMPONENT) {
                tex->format = GL_DEPTH_COMPONENT;
                if(tex->type!=GL_UNSIGNED_INT && tex->type!=GL_UNSIGNED_SHORT && tex->type!=GL_FLOAT) tex->type = GL_UNSIGNED_SHORT;
                tex->fpe_format = FPE_TEX_DEPTH;
                int oldactive = glstate->texture.active;
                if(oldactive) gles_glActiveTexture(GL_TEXTURE0);
                gltexture_t *bound = glstate->texture.bound[0/*glstate->texture.active*/][ENABLED_TEX2D];
                GLuint oldtex = bound->glname;
                if (oldtex!=tex->glname) gles_glBindTexture(GL_TEXTURE_2D, tex->glname);
                gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                gles_glTexImage2D(GL_TEXTURE_2D, 0, tex->format, tex->nwidth, tex->nheight, 0, tex->format, tex->type, NULL);
                if (oldtex!=tex->glname) gles_glBindTexture(GL_TEXTURE_2D, oldtex);
                if(oldactive) gles_glActiveTexture(GL_TEXTURE0+oldactive);
            }
            // bind the depth texture...
            gles_glFramebufferTexture2D(ntarget, attachment, GL_TEXTURE_2D, texture, 0);
        } else {
            // let's create a renderbuffer and attach it instead of the (presumably) depth texture
            gl4es_glGenRenderbuffers(1, &tex->renderdepth);
            gl4es_glBindRenderbuffer(GL_RENDERBUFFER, tex->renderdepth);
            gl4es_glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, twidth, theight);
            gl4es_glBindRenderbuffer(GL_RENDERBUFFER, 0);
            gl4es_glFramebufferRenderbuffer(ntarget, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, tex->renderdepth);
        }
        errorGL();
        ReadDraw_Pop(target);
        return;
    }
    if(attachment==GL_DEPTH_STENCIL_ATTACHMENT /*&& hardext.depthtex==0*/) {
        noerrorShim();
        if (level!=0) return;
        // let's create a renderbuffer and attach it instead of the (presumably) depth texture
        if(hardext.depthstencil && !(hardext.depthtex && tex)) {
            gl4es_glGenRenderbuffers(1, &tex->renderdepth);
            gl4es_glBindRenderbuffer(GL_RENDERBUFFER, tex->renderdepth);
            gl4es_glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, twidth, theight);
            gl4es_glBindRenderbuffer(GL_RENDERBUFFER, 0);
            errorGL();
            gl4es_glFramebufferRenderbuffer(ntarget, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, tex->renderdepth);
            gl4es_glFramebufferRenderbuffer(ntarget, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, tex->renderdepth);
        } else {
            if(hardext.depthtex && tex) {
                // depth texture supported!
                //check if texture needs to be re-created ad true depth texture
                if(tex->format!=GL_DEPTH_COMPONENT) {
                    tex->format = GL_DEPTH_COMPONENT;
                    if(tex->type!=GL_UNSIGNED_INT && tex->type!=GL_UNSIGNED_SHORT && tex->type!=GL_FLOAT) tex->type = GL_UNSIGNED_SHORT;
                    tex->fpe_format = FPE_TEX_DEPTH;
                    int oldactive = glstate->texture.active;
                    if(oldactive) gles_glActiveTexture(GL_TEXTURE0);
                    gltexture_t *bound = glstate->texture.bound[0/*glstate->texture.active*/][ENABLED_TEX2D];
                    GLuint oldtex = bound->glname;
                    if (oldtex!=tex->glname) gles_glBindTexture(GL_TEXTURE_2D, tex->glname);
                    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
                    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
                    gles_glTexImage2D(GL_TEXTURE_2D, 0, tex->format, tex->nwidth, tex->nheight, 0, tex->format, tex->type, NULL);
                    if (oldtex!=tex->glname) gles_glBindTexture(GL_TEXTURE_2D, oldtex);
                    if(oldactive) gles_glActiveTexture(GL_TEXTURE0+oldactive);
                }
                // bind the depth texture...
                gles_glFramebufferTexture2D(ntarget, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, texture, 0);
            } else {
                GLuint render_depth;    // memory leak here...
                gl4es_glGenRenderbuffers(1, &render_depth);
                gl4es_glBindRenderbuffer(GL_RENDERBUFFER, render_depth);
                gl4es_glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, twidth, theight);
                gl4es_glBindRenderbuffer(GL_RENDERBUFFER, 0);
                gl4es_glFramebufferRenderbuffer(ntarget, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, render_depth);
            }
            gl4es_glGenRenderbuffers(1, &tex->renderstencil);
            gl4es_glBindRenderbuffer(GL_RENDERBUFFER, tex->renderstencil);
            gl4es_glRenderbufferStorage(GL_RENDERBUFFER, GL_STENCIL_INDEX8, twidth, theight);
            gl4es_glBindRenderbuffer(GL_RENDERBUFFER, 0);
            errorGL();
            gl4es_glFramebufferRenderbuffer(ntarget, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, tex->renderstencil);

        }
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
                GLuint oldtex = bound->glname;
                if (oldtex!=scrap_tex) gles_glBindTexture(GL_TEXTURE_2D, scrap_tex);
                gles_glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, scrap_width, scrap_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
                if (oldtex!=scrap_tex) gles_glBindTexture(GL_TEXTURE_2D, oldtex);
        }
        texture = scrap_tex;
    }
    
    errorGL();
    GLenum realtarget = GL_TEXTURE_2D;
    if(textarget>=GL_TEXTURE_CUBE_MAP_POSITIVE_X && textarget<GL_TEXTURE_CUBE_MAP_POSITIVE_X+6)
        realtarget = textarget;
    gles_glFramebufferTexture2D(ntarget, attachment, realtarget, texture, 0);
    DBG(CheckGLError(1);)
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
    LOAD_GLES2_OR_OES(glGenRenderbuffers);
    
    errorGL();
    gles_glGenRenderbuffers(n, renderbuffers);
}

void gl4es_glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
    DBG(printf("glFramebufferRenderbuffer(%s, %s, %s, %u)\n", PrintEnum(target), PrintEnum(attachment), PrintEnum(renderbuffertarget), renderbuffer);)
    LOAD_GLES2_OR_OES(glFramebufferRenderbuffer);
    LOAD_GLES2_OR_OES(glGetFramebufferAttachmentParameteriv);
    LOAD_GLES(glGetError);

    if (attachment == GL_COLOR_ATTACHMENT0 && globals4es.fboforcetex) {
        // drop the renderbuffer attachement and create a texture instead...
        int oldactive = glstate->texture.active;
        if(oldactive) gl4es_glActiveTexture(GL_TEXTURE0);
        gltexture_t *bound = glstate->texture.bound[0][ENABLED_TEX2D];
        GLuint oldtex = bound->glname;
        // get size of renderbuffer
        LOAD_GLES2_OR_OES(glGetRenderbufferParameteriv);
        GLint width, height;
        GLenum format;
        GLuint oldrender = glstate->fbo.current_rb;
        if(oldrender != renderbuffer) gl4es_glBindRenderbuffer(GL_RENDERBUFFER, renderbuffer);
        // TODO: keep track of Renderbuffer parameter, to avoid querying geometry
        gles_glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH, &width);
        gles_glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &height);
        gles_glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_INTERNAL_FORMAT, &format);
        if(oldrender != renderbuffer) gl4es_glBindRenderbuffer(GL_RENDERBUFFER, oldrender);
        // TODO: keep track of that texture, for delete when the Renderbuffer is deleted
        // create a texture
        GLuint newtex;
        gl4es_glGenTextures(1, &newtex);
        gl4es_glBindTexture(GL_TEXTURE_2D, newtex);
        gl4es_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        gl4es_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        gl4es_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        gl4es_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        gl4es_glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
        gl4es_glBindTexture(GL_TEXTURE_2D, oldtex);
        gl4es_glFramebufferTexture2D(target, attachment, GL_TEXTURE_2D, newtex, 0);
        // end of cleanup
        if(oldactive) gl4es_glActiveTexture(GL_TEXTURE0+oldactive);
        return;
    }

    if (attachment == GL_DEPTH_STENCIL_ATTACHMENT) {
        // doesn't seems to be supported "as-is" on GLES
        gl4es_glFramebufferRenderbuffer(target, GL_DEPTH_ATTACHMENT, renderbuffertarget, renderbuffer);
        gl4es_glFramebufferRenderbuffer(target, GL_STENCIL_ATTACHMENT, renderbuffertarget, renderbuffer);
        return;
    }
    
    //TODO: handle target=READBUFFER or DRAWBUFFER...
    if (glstate->fbo.depthstencil && (attachment==GL_STENCIL_ATTACHMENT)) {
		khint_t k = kh_get(dsr, glstate->fbo.depthstencil, renderbuffer);
		if (k != kh_end(glstate->fbo.depthstencil)) {
			gldepthstencil_t *dsr = kh_value(glstate->fbo.depthstencil, k);
            renderbuffer = dsr->stencil;
		}
    }

    if ((glstate->fbo.current_fb!=0) && (renderbuffer==0)) {
        //Hack, avoid unbind a renderbuffer on a framebuffer...
        // TODO, avoid binding an already binded RB
        noerrorShim();
        return;
    }
    
    GLenum ntarget = ReadDraw_Push(target);

    if ((glstate->fbo.current_fb!=0) && (renderbuffer!=0) && ((attachment==GL_DEPTH_ATTACHMENT) || (attachment==GL_STENCIL_ATTACHMENT))) {
        GLuint tmp;
        gles_glGetFramebufferAttachmentParameteriv(ntarget, attachment, GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE, &tmp);
        if(tmp==GL_RENDERBUFFER) {
            gles_glGetFramebufferAttachmentParameteriv(ntarget, attachment, GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME, &tmp);
            GLenum err = gles_glGetError();
            if (tmp==renderbuffer && err!=GL_NO_ERROR) {
                noerrorShim();
                ReadDraw_Pop(target);
                return;
            }
        }
    }

    if(attachment == GL_COLOR_ATTACHMENT0) {
        detach_fbotexture(glstate->fbo.current_fb); // remove texture attachement if there was one
    }

    errorGL();
    gles_glFramebufferRenderbuffer(ntarget, attachment, renderbuffertarget, renderbuffer);
    DBG(CheckGLError(1);)
    ReadDraw_Pop(target);
}

void gl4es_glDeleteRenderbuffers(GLsizei n, GLuint *renderbuffers) {
    DBG(printf("glDeleteRenderbuffer(%d, %p)\n", n, renderbuffers);)
    LOAD_GLES2_OR_OES(glDeleteRenderbuffers);
    
    // check if we delete a depthstencil
    khint_t k;
    if (glstate->fbo.depthstencil)
        for (int i=0; i<n; i++) {
            khint_t k;
            gldepthstencil_t *dsr;
            for (int i = 0; i < n; i++) {
                GLuint t = renderbuffers[i];
                k = kh_get(dsr, glstate->fbo.depthstencil, t);
                if (k != kh_end(glstate->fbo.depthstencil)) {
                    dsr = kh_value(glstate->fbo.depthstencil, k);
                    gles_glDeleteRenderbuffers(1, &dsr->stencil);
                    kh_del(dsr, glstate->fbo.depthstencil, k);
                    free(dsr);
                }
            }
        }

    errorGL();
    gles_glDeleteRenderbuffers(n, renderbuffers);
}

void gl4es_glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
    DBG(printf("glRenderbufferStorage(%s, %s, %i, %i)\n", PrintEnum(target), PrintEnum(internalformat), width, height);)
    LOAD_GLES2_OR_OES(glRenderbufferStorage);
    LOAD_GLES2_OR_OES(glGenRenderbuffers);
    LOAD_GLES2_OR_OES(glBindRenderbuffer);
    
    errorGL();
    width = (hardext.npot>0 && !globals4es.potframebuffer)?width:npot(width);
    height = (hardext.npot>0 && !globals4es.potframebuffer)?height:npot(height);
    // check if internal format is GL_DEPTH_STENCIL_EXT
    if (internalformat == GL_DEPTH_STENCIL)
        internalformat = GL_DEPTH24_STENCIL8;
    // in that case, create first a STENCIL one then a DEPTH one....
    if ((internalformat == GL_DEPTH24_STENCIL8) && (hardext.depthstencil==0)) {
        khint_t k;
        int ret;
        internalformat = (hardext.depth24)?GL_DEPTH_COMPONENT24:GL_DEPTH_COMPONENT16;
        GLuint old_rb = glstate->fbo.current_rb;
        GLuint stencil;
        if (!glstate->fbo.depthstencil) {
            glstate->fbo.depthstencil = kh_init(dsr);
            // segfaults if we don't do a single put
            kh_put(dsr, glstate->fbo.depthstencil, 1, &ret);
            kh_del(dsr, glstate->fbo.depthstencil, 1);
        }
        // search for an existing buffer (should not exist!)
        k = kh_get(dsr, glstate->fbo.depthstencil, glstate->fbo.current_rb);
        gldepthstencil_t *dsr = NULL;
        if (k == kh_end(glstate->fbo.depthstencil)){
            k = kh_put(dsr, glstate->fbo.depthstencil, glstate->fbo.current_rb, &ret);
            dsr = kh_value(glstate->fbo.depthstencil, k) = malloc(sizeof(gldepthstencil_t));
            dsr->renderbuffer = glstate->fbo.current_rb;
        } else {
            dsr = kh_value(glstate->fbo.depthstencil, k);
        }
        // create a stencil buffer
        gles_glGenRenderbuffers(1, &stencil);
        dsr->stencil = stencil;
        gles_glBindRenderbuffer(GL_RENDERBUFFER, stencil);
        gles_glRenderbufferStorage(target, GL_STENCIL_INDEX8, width, height);
        gles_glBindRenderbuffer(GL_RENDERBUFFER, glstate->fbo.current_rb);
    }
    else if (internalformat == GL_DEPTH_COMPONENT || internalformat == GL_DEPTH_COMPONENT32)    // Not much is supported on GLES...
        internalformat = GL_DEPTH_COMPONENT16;
    else if (internalformat == GL_RGB8 && hardext.rgba8==0)
        internalformat = GL_RGB565_OES;
    else if (internalformat == GL_RGBA8 && hardext.rgba8==0)
        internalformat = GL_RGBA4_OES;

    gles_glRenderbufferStorage(target, internalformat, width, height);
    DBG(CheckGLError(1);)
}

void gl4es_glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {    //STUB
    gl4es_glRenderbufferStorage(target, internalformat, width, height);
}

void gl4es_glBindRenderbuffer(GLenum target, GLuint renderbuffer) {
    DBG(printf("glBindRenderbuffer(%s, %u), binded Fbo=%u\n", PrintEnum(target), renderbuffer, glstate->fbo.current_fb);)
    LOAD_GLES2_OR_OES(glBindRenderbuffer);
    
    glstate->fbo.current_rb = renderbuffer;
    
    errorGL();
    gles_glBindRenderbuffer(target, renderbuffer);
}

GLboolean gl4es_glIsRenderbuffer(GLuint renderbuffer) {
    DBG(printf("glIsRenderbuffer(%u)\n", renderbuffer);)
    LOAD_GLES2_OR_OES(glIsRenderbuffer);
    
    errorGL();
    return gles_glIsRenderbuffer(renderbuffer);
}

void gl4es_glGenerateMipmap(GLenum target) {
    DBG(printf("glGenerateMipmap(%s)\n", PrintEnum(target));)
    LOAD_GLES2_OR_OES(glGenerateMipmap);
    
    if(globals4es.forcenpot && hardext.npot==1) {
        gltexture_t *bound = gl4es_getCurrentTexture(target);
        if(bound->npot) {
            noerrorShim();
            return; // no need to generate mipmap, mipmap is disabled here
        }
    }

    errorGL();
    if(globals4es.automipmap != 3)
        gles_glGenerateMipmap(target);
}

void gl4es_glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params) {
    DBG(printf("glGetFramebufferAttachmentParameteriv(%s, %s, %s, %p)\n", PrintEnum(target), PrintEnum(attachment), PrintEnum(pname), params);)
    LOAD_GLES2_OR_OES(glGetFramebufferAttachmentParameteriv);
    
    GLenum ntarget = ReadDraw_Push(target);
    // hack to return DEPTH size
    if(ntarget==GL_FRAMEBUFFER && attachment==GL_DEPTH_ATTACHMENT && pname==GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE && hardext.depthtex==0) {
        errorGL();
        gles_glGetFramebufferAttachmentParameteriv(ntarget, attachment, GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME, params);
        //TODO: Check all this?!
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
    LOAD_GLES2_OR_OES(glGetRenderbufferParameteriv);
    
    errorGL();
    gles_glGetRenderbufferParameteriv(target, pname, params);
}

void createMainFBO(int width, int height) {
    LOAD_GLES2_OR_OES(glGenFramebuffers);
    LOAD_GLES2_OR_OES(glBindFramebuffer);
    LOAD_GLES2_OR_OES(glFramebufferTexture2D);
    LOAD_GLES2_OR_OES(glCheckFramebufferStatus);
    LOAD_GLES2_OR_OES(glFramebufferRenderbuffer);
    LOAD_GLES2_OR_OES(glRenderbufferStorage);
    LOAD_GLES2_OR_OES(glGenRenderbuffers);
    LOAD_GLES2_OR_OES(glBindRenderbuffer);
    LOAD_GLES(glTexImage2D);
    LOAD_GLES(glGenTextures);
    LOAD_GLES(glBindTexture);
    LOAD_GLES(glActiveTexture);
    LOAD_GLES(glTexParameteri);
    LOAD_GLES2(glClientActiveTexture);
    LOAD_GLES(glClear);

    // If there is already a Framebuffer created, let's delete it.... unless it's already the right size!
    if (glstate->fbo.mainfbo_fbo) {
        if (width==glstate->fbo.mainfbo_width && height==glstate->fbo.mainfbo_height)
            return;
        deleteMainFBO();
    }
    DBG(printf("LIBGL: Create FBO of %ix%i 32bits\n", width, height);)
    // switch to texture unit 0 if needed
    if (glstate->texture.active != 0)
        gles_glActiveTexture(GL_TEXTURE0);
    if (glstate->texture.client != 0 && gles_glClientActiveTexture)
        gles_glClientActiveTexture(GL_TEXTURE0);
        
    glstate->fbo.mainfbo_width = width;
    glstate->fbo.mainfbo_height = height;
    glstate->fbo.mainfbo_nwidth = width = hardext.npot>0?width:npot(width);
    glstate->fbo.mainfbo_nheight = height = hardext.npot>0?height:npot(height);

    // create the texture
	gles_glGenTextures(1, &glstate->fbo.mainfbo_tex);
    gles_glBindTexture(GL_TEXTURE_2D, glstate->fbo.mainfbo_tex);
    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    gles_glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
					0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
	gles_glBindTexture(GL_TEXTURE_2D, 0);
    // create the render buffers
	gles_glGenRenderbuffers(1, &glstate->fbo.mainfbo_dep);
	gles_glGenRenderbuffers(1, &glstate->fbo.mainfbo_ste);
    gles_glBindRenderbuffer(GL_RENDERBUFFER, glstate->fbo.mainfbo_ste);
    gles_glRenderbufferStorage(GL_RENDERBUFFER, GL_STENCIL_INDEX8, width, height);
    gles_glBindRenderbuffer(GL_RENDERBUFFER, glstate->fbo.mainfbo_dep);
    gles_glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, width, height);
    gles_glBindRenderbuffer(GL_RENDERBUFFER, 0);
    // create a fbo
    gles_glGenFramebuffers(1, &glstate->fbo.mainfbo_fbo);
    gles_glBindFramebuffer(GL_FRAMEBUFFER, glstate->fbo.mainfbo_fbo);
    
    gles_glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, glstate->fbo.mainfbo_ste);
    gles_glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, glstate->fbo.mainfbo_dep);
    
    gles_glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, glstate->fbo.mainfbo_tex, 0);
    attach_fbotexture(glstate->fbo.mainfbo_fbo, glstate->fbo.mainfbo_tex, glstate->fbo.mainfbo_width, glstate->fbo.mainfbo_height);

	GLenum status = gles_glCheckFramebufferStatus(GL_FRAMEBUFFER);

	gles_glBindFramebuffer(GL_FRAMEBUFFER, 0);

    // Final check, and bind the fbo for future use
    if (status != GL_FRAMEBUFFER_COMPLETE) {
        printf("LIBGL: Error while creating main fbo (0x%04X)\n", status);
        deleteMainFBO();
        gles_glBindFramebuffer(GL_FRAMEBUFFER, glstate->fbo.current_fb);
        gles_glBindFramebuffer(GL_RENDERBUFFER, glstate->fbo.current_rb);
    } else {
        gles_glBindFramebuffer(GL_FRAMEBUFFER, (glstate->fbo.current_fb)?glstate->fbo.current_fb:glstate->fbo.mainfbo_fbo);
        if (glstate->fbo.current_rb)
            gles_glBindRenderbuffer(GL_RENDERBUFFER, glstate->fbo.current_rb);
        // clear color, depth and stencil...
        if (glstate->fbo.current_fb==0)
            gles_glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    }
    // Put everything back, and active the MainFBO
    gles_glBindTexture(GL_TEXTURE_2D, glstate->texture.bound[0][ENABLED_TEX2D]->glname);
    if (glstate->texture.active != 0)
        gles_glActiveTexture(GL_TEXTURE0 + glstate->texture.active);
    if (glstate->texture.client != 0 && gles_glClientActiveTexture)
        gles_glClientActiveTexture(GL_TEXTURE0 + glstate->texture.client);
    
}

void blitMainFBO(int x, int y, int width, int height) {
    if (glstate->fbo.mainfbo_fbo==0)
        return;

    // blit the texture
    if(!width && !height) {
        gl4es_glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        gl4es_glClear(GL_COLOR_BUFFER_BIT);
    }

    GLint vp[4];
    memcpy(vp, &glstate->raster.viewport, sizeof(vp));
    gl4es_glViewport(0, 0, glstate->fbo.mainfbo_width, glstate->fbo.mainfbo_height);
    float rx, ry;
    if(!width && !height) {
        width = glstate->fbo.mainfbo_width;
        height = glstate->fbo.mainfbo_height;
        rx = ry = 1.0f;
    } else {
        //y = glstate->fbo.mainfbo_height - (y+height);
        y = -y;
        rx = (float)width/glstate->fbo.mainfbo_width;
        ry = (float)height/glstate->fbo.mainfbo_height;
    }
    gl4es_blitTexture(glstate->fbo.mainfbo_tex, 0.f, 0.f,
        glstate->fbo.mainfbo_width, glstate->fbo.mainfbo_height, 
        glstate->fbo.mainfbo_nwidth, glstate->fbo.mainfbo_nheight, 
        rx, ry,
        0, 0, x, y, BLIT_OPAQUE);
    gl4es_glViewport(vp[0], vp[1], vp[2], vp[3]);
}

void bindMainFBO() {
    LOAD_GLES2_OR_OES(glBindFramebuffer);
    LOAD_GLES2_OR_OES(glCheckFramebufferStatus);
    if (!glstate->fbo.mainfbo_fbo)
        return;
    if (glstate->fbo.current_fb==0) {
        gles_glBindFramebuffer(GL_FRAMEBUFFER, glstate->fbo.mainfbo_fbo);
        gles_glCheckFramebufferStatus(GL_FRAMEBUFFER);
    }
}

void unbindMainFBO() {
    LOAD_GLES2_OR_OES(glBindFramebuffer);
    if (!glstate->fbo.mainfbo_fbo)
        return;
    if (glstate->fbo.current_fb==0) {
        GLuint pixel;
        gles_glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }
}

void deleteMainFBO() {
    LOAD_GLES2_OR_OES(glDeleteFramebuffers);
    LOAD_GLES2_OR_OES(glDeleteRenderbuffers);
    LOAD_GLES(glDeleteTextures);

    detach_fbotexture(glstate->fbo.mainfbo_fbo);
    if (glstate->fbo.mainfbo_dep) {
        gles_glDeleteRenderbuffers(1, &glstate->fbo.mainfbo_dep);
        glstate->fbo.mainfbo_dep = 0;
    }
    if (glstate->fbo.mainfbo_ste) {
        gles_glDeleteRenderbuffers(1, &glstate->fbo.mainfbo_ste);
        glstate->fbo.mainfbo_ste = 0;
    }
    if (glstate->fbo.mainfbo_tex) {
        gles_glDeleteTextures(1, &glstate->fbo.mainfbo_tex);
        glstate->fbo.mainfbo_tex = 0;
    }
    if (glstate->fbo.mainfbo_fbo) {
        gles_glDeleteFramebuffers(1, &glstate->fbo.mainfbo_fbo);
        glstate->fbo.mainfbo_fbo = 0;
    }
    
    // all done...
}

void gl4es_glFramebufferTextureLayer(	GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
    gl4es_glFramebufferTexture2D(target, attachment, GL_TEXTURE_2D, texture,	level); // Force Texture2D, ignore layer...
}

void gl4es_getMainFBSize(GLint* width, GLint* height);

void gl4es_glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
    // mask will be ignored
    // filter will be taken only for ReadFBO has no Texture attached (so readpixel is used)
    DBG(printf("glBlitFramebuffer(%d, %d, %d, %d,  %d, %d, %d, %d,  0x%04X, %s) fbo_read=%d, fbo_draw=%d\n",
        srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, PrintEnum(filter), glstate->fbo.fbo_read, glstate->fbo.fbo_draw);)

    if((mask&GL_COLOR_BUFFER_BIT)==0)
        return; // cannot copy DEPTH or STENCIL data on GLES, only COLOR_BUFFER...

    if(glstate->fbo.fbo_read == glstate->fbo.fbo_draw && srcX0==dstX0 && srcX1==dstX1 && srcY0==dstY0 && srcY1==dstY1)
        return; // no need to try copying on itself
    
    if(dstX1==dstX0 || dstY1==dstY0)
        return; // nothing to draw
    if(srcX1==srcX0 || srcY1==srcY0)
        return; // nothing to draw

    GLuint texture = 0;
    find_fbotexture(glstate->fbo.fbo_read, &texture, NULL, NULL);
    int created = (texture==0 || (glstate->fbo.fbo_read==glstate->fbo.fbo_draw));
    int oldtex = glstate->texture.active;
    if (oldtex)
        gl4es_glActiveTexture(GL_TEXTURE0);
    float nwidth, nheight;
    if (created) {
        gltexture_t *old = glstate->texture.bound[ENABLED_TEX2D][glstate->texture.active];
        gl4es_glGenTextures(1, &texture);
        gl4es_glBindTexture(GL_TEXTURE_2D, texture);
        gl4es_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        gl4es_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        gl4es_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, (filter==GL_LINEAR)?GL_LINEAR:GL_NEAREST);
        gl4es_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, (filter==GL_LINEAR)?GL_LINEAR:GL_NEAREST);
        gl4es_glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, srcX0, srcY0, srcX1-srcX0, srcY1-srcY0, 0);
        srcX1-=srcX0; srcX0=0.f;
        srcY1-=srcY0; srcY0=0.f;
        gl4es_glBindTexture(GL_TEXTURE_2D, old->texture);
    }
    if(texture==glstate->fbo.mainfbo_tex) {
        nwidth = glstate->fbo.mainfbo_nwidth;
        nheight = glstate->fbo.mainfbo_nheight;
    } else {
        gltexture_t *tex = gl4es_getTexture(GL_TEXTURE_2D, texture);
        if(tex) {
            nwidth = tex->nwidth;
            nheight = tex->nheight;
        } else {
            // not good if here!
            nwidth = srcX1;
            nheight = srcY1;
        }
    }
    float srcW = srcX1-srcX0;
    float srcH = srcY1-srcY0;
    float zoomx = ((float)(dstX1-dstX0))/srcW;
    float zoomy = ((float)(dstY1-dstY0))/srcH;
    // get the width / height of write FBO
    int fbowidth, fboheight;
    if(glstate->fbo.fbo_draw==glstate->fbo.mainfbo_fbo) {
        fbowidth = glstate->fbo.mainfbo_width;
        fboheight = glstate->fbo.mainfbo_height;
        if(glstate->fbo.mainfbo_width!=dstX1 || glstate->fbo.mainfbo_height!=dstY1) {
            gl4es_getMainFBSize(&glstate->fbo.mainfbo_width, &glstate->fbo.mainfbo_height);
        }
    } else {
        if (!find_fbotexture(glstate->fbo.fbo_draw, NULL, &fbowidth, &fboheight)) {
            // not found, get width/height from Hardware
            GLuint renderbuff;
            gl4es_glGetFramebufferAttachmentParameteriv(GL_DRAW_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME, &renderbuff);
            GLuint old = glstate->fbo.current_rb;
            gl4es_glBindRenderbuffer(GL_RENDERBUFFER, renderbuff);
            gl4es_glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH, &fbowidth);
            gl4es_glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &fboheight);
            gl4es_glBindRenderbuffer(GL_RENDERBUFFER, old);
            // save value, to not query it each time
            attach_fbotexture(glstate->fbo.fbo_draw, 0, fbowidth, fboheight);
        }
    }
    GLint vp[4];
    memcpy(vp, &glstate->raster.viewport, sizeof(vp));
    gl4es_glViewport(0, 0, fbowidth, fboheight);
    gl4es_blitTexture(texture, srcX0, srcY0, srcW, srcH, nwidth, nheight, zoomx, zoomy, 0, 0, dstX0, dstY0, BLIT_OPAQUE);
    gl4es_glViewport(vp[0], vp[1], vp[2], vp[3]);
    if(created) {
        gl4es_glDeleteTextures(1, &texture);
    }
    if(oldtex)
        gl4es_glActiveTexture(GL_TEXTURE0+oldtex);

}

GLuint gl4es_getCurrentFBO() {
  return glstate->fbo.current_fb;
}

void gl4es_setCurrentFBO() {
  LOAD_GLES2_OR_OES(glBindFramebuffer);
  gles_glBindFramebuffer(GL_FRAMEBUFFER, (glstate->fbo.current_fb)?glstate->fbo.current_fb:glstate->fbo.mainfbo_fbo);
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
