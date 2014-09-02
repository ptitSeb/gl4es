#include "framebuffers.h"

khash_t(dsr) *depthstencil = NULL;
GLuint current_rb = 0;

GLuint current_fb = 0;

GLuint mainfbo_fbo = 0; // The MainFBO
GLuint mainfbo_tex = 0; // Texture Attachment
GLuint mainfbo_dep = 0; // Depth attachment
GLuint mainfbo_ste = 0; // Stencil attachement
int mainfbo_width = 800;
int mainfbo_height = 480;

extern void* eglGetProcAddress(const char*);
int npot(int n);

void glGenFramebuffers(GLsizei n, GLuint *ids) {
    LOAD_GLES_OES(glGenFramebuffers);
    
    errorGL();
    gles_glGenFramebuffers(n, ids);
}

void glDeleteFramebuffers(GLsizei n, GLuint *framebuffers) {
    LOAD_GLES_OES(glDeleteFramebuffers);
    
    errorGL();
    gles_glDeleteFramebuffers(n, framebuffers);
}

GLboolean glIsFramebuffer(GLuint framebuffer) {
    LOAD_GLES_OES(glIsFramebuffer);
    
    errorGL();
    return gles_glIsFramebuffer(framebuffer);
}

GLenum glCheckFramebufferStatus(GLenum target) {
    LOAD_GLES_OES(glCheckFramebufferStatus);
    
    errorGL();
    GLenum result = gles_glCheckFramebufferStatus(target);
    return result;
}

void glBindFramebuffer(GLenum target, GLuint framebuffer) {
    LOAD_GLES_OES(glBindFramebuffer);
    
    errorGL();
    gles_glBindFramebuffer(target, framebuffer);
}

void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture,	GLint level) {
    LOAD_GLES_OES(glFramebufferTexture2D);
    
    errorGL();
    gles_glFramebufferTexture2D(target, attachment, textarget, texture, level);
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
    
    errorGL();
    gles_glGenRenderbuffers(n, renderbuffers);
}

void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
    LOAD_GLES_OES(glFramebufferRenderbuffer);
    
    if (depthstencil && (attachment==GL_STENCIL_ATTACHMENT)) {
		khint_t k = kh_get(dsr, depthstencil, renderbuffer);
		if (k != kh_end(depthstencil)) {
			gldepthstencil_t *dsr = kh_value(depthstencil, k);
            renderbuffer = dsr->stencil;
		}
    }
    
    errorGL();
    gles_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}

void glDeleteRenderbuffers(GLsizei n, GLuint *renderbuffers) {
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
    LOAD_GLES_OES(glBindRenderbuffer);
    
    current_rb = renderbuffer;
    
    errorGL();
    gles_glBindRenderbuffer(target, renderbuffer);
}

GLboolean glIsRenderbuffer(GLuint renderbuffer) {
    LOAD_GLES_OES(glIsRenderbuffer);
    
    errorGL();
    return gles_glIsRenderbuffer(renderbuffer);
}

void glGenerateMipmap(GLenum target) {
    LOAD_GLES_OES(glGenerateMipmap);
    
    errorGL();
    return gles_glGenerateMipmap(target);
}

void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params) {
    LOAD_GLES_OES(glGetFramebufferAttachmentParameteriv);
    
    errorGL();
    return gles_glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}

void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    LOAD_GLES_OES(glGetRenderbufferParameteriv);
    
    errorGL();
    return gles_glGetRenderbufferParameteriv(target, pname, params);
}
/*
void createMainFBO(int width, int height) {
    LOAD_GLES_OES(glGenFramebuffers);
    LOAD_GLES_OES(glBindFramebuffer);
    LOAD_GLES_OES(glFramebufferTexture2D);
    LOAD_GLES_OES(glCheckFramebufferStatus);
    LOAD_GLES_OES(glRenderbufferStorage);
    LOAD_GLES_OES(glGenRenderbuffers);
    LOAD_GLES_OES(glBindRenderbuffer);
    LOAD_GLES(glTexImage2D);
    LOAD_GLES(glGenTextures);
    LOAD_GLES(glBindTexture);
    LOAD_GLES(glActiveTexture);
    LOAD_GLES(glClientActiveTexture);

    // If there is already a Framebuffer created, let's delete it....
    deleteMainFBO();
    
    // switch to texture unit 0 if needed
    if (state.texture.active != 0)
        gles_glActiveTexture(GL_TEXTURE0);
    if (state.texture.client != 0)
        gles_glClientActiveTexture(GL_TEXTURE0);
    
    // create a fbo
    gles_glGenFramebuffers(1, &mainfbo_fbo);
    gles_glBindFramebuffers(GL_FRAMEBUFFER, mainfbo_fbo);
    
	gles_glGenRenderbuffers(1, &mainfbo_dep);
	gles_glGenRenderbuffers(1, &mainfbo_ste);
    gles_glBindRenderbuffer(GL_RENDERBUFFER, &mainfbo_ste);
    gles_glRenderbufferStorage(GL_RENDERBUFFER_EXT, GL_STENCIL_INDEX8, width, height);
    gles_glBindRenderbuffer(GL_RENDERBUFFER, &mainfbo_dep);
    gles_glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT24, width, height);
    gles_glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, mainfbo_ste);
    gles_glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, mainfbo_dep);
    
	gles_glGenTextures(1, &mainfbo_tex);
    gles_glBindTexture(GL_TEXTURE_2D, mainfbo_tex);
//    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    gles_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    gles_glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height,
					0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	gles_glBindTexture(GL_TEXTURE_2D, 0);
    gles_glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, mainfbo_tex, 0);

	GLenum status = gles_glCheckFramebufferStatusEXT(GL_FRAMEBUFFER);

	gles_glBindRenderbuffer(GL_RENDERBUFFER, 0);
	gles_glBindFramebuffer(GL_FRAMEBUFFER, 0);

    // Put everything back, and active the MainFBO
    gles_glBindFramebuffer(GL_FRAMEBUFFER, (current_fb)?current_fb:mainfbo_fbo);
    if (state.texture.bound[0]) 
        gles_glBindTexture(GL_TEXTURE_2D, state.texture.bound[0]->glname);
    else
        gles_glBindTexture(GL_TEXTURE_2D, 0);
    if (state.texture.active != 0)
        gles_glActiveTexture(GL_TEXTURE0 + state.texture.active);
    if (state.texture.client != 0)
        gles_glClientActiveTexture(GL_TEXTURE0 + state.texture.client);
    
    if (status != GL_FRAMEBUFFER_COMPLETE) {
        printf("LIBGL: Error while creating main fbo (0x%04X)\n", status);
        deleteMainFBO();
    }
}

void blitMainFBO() {
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
*/
