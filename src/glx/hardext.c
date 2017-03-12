#include "../gl/gl.h"
#include "hardext.h"
#include "../gl/init.h"

static int tested = 0;

hardext_t hardext;

#define SHUT(a) if(!globals4es.nobanner) a

void GetHardwareExtensions(int notest)
{
    // used EGL & GLES functions
    LOAD_EGL(eglBindAPI);
    LOAD_EGL(eglInitialize);
    LOAD_EGL(eglGetDisplay);
    LOAD_EGL(eglCreatePbufferSurface);
    LOAD_EGL(eglDestroySurface);
    LOAD_EGL(eglDestroyContext);
    LOAD_EGL(eglMakeCurrent);
    LOAD_EGL(eglChooseConfig);
    LOAD_EGL(eglCreateContext);
    LOAD_EGL(eglQueryString);
    LOAD_GLES(glGetString);
    LOAD_GLES(glGetIntegerv);

    EGLDisplay eglDisplay;
    EGLSurface eglSurface;
    EGLContext eglContext;

    if(tested) return;
    // put some default values
    memset(&hardext, 0, sizeof(hardext));
    hardext.maxtex = 1;
    hardext.maxsize = 2048;
    hardext.readf = GL_RGBA;
    hardext.readt = GL_UNSIGNED_BYTE;

    if(notest) {
        SHUT(LOGD("LIBGL: Hardware test disabled, nothing activated...\n"));
    }

    // Create a PBuffer first...
    EGLint egl_context_attrib[] = {
    #ifdef USE_ES2
        EGL_CONTEXT_CLIENT_VERSION, 2,
    #endif
        EGL_NONE
    };

    //let's create a PBuffer attributes
    EGLint egl_attribs[10];	// should be enough
    int i = 0;
    egl_attribs[i++] = EGL_WIDTH;
    egl_attribs[i++] = 32;
    egl_attribs[i++] = EGL_HEIGHT;
    egl_attribs[i++] = 32;
    egl_attribs[i++] = EGL_NONE;

    EGLint configAttribs[] = {
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_ALPHA_SIZE, 8,
        EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES_BIT,
        EGL_NONE
    };

    int configsFound;
    static EGLConfig pbufConfigs[1];
    
    eglDisplay = egl_eglGetDisplay(EGL_DEFAULT_DISPLAY);

    egl_eglBindAPI(EGL_OPENGL_ES_API);
    if (egl_eglInitialize(eglDisplay, NULL, NULL) != EGL_TRUE) {
        LOGE("LIBGL: Error while gathering supported extension (Init issue), default to none\n");
        return;
    }

    egl_eglChooseConfig(eglDisplay, configAttribs, pbufConfigs, 1, &configsFound);
    if(!configsFound) {
        SHUT(LOGE("LIBGL: Error while gathering supported extension (Config issue), default to none\n"));
        return;
    }
    eglContext = egl_eglCreateContext(eglDisplay, pbufConfigs[0], EGL_NO_CONTEXT, egl_context_attrib);
    if(!eglContext) {
        SHUT(LOGE("LIBGL: Error while gathering supported extension (Context issue), default to none\n"));
        return;
    }
    eglSurface = egl_eglCreatePbufferSurface(eglDisplay, pbufConfigs[0], egl_attribs);
    if(!eglSurface) {
        SHUT(LOGE("LIBGL: Error while gathering supported extension (Surface issue), default to none\n"));
        egl_eglDestroyContext(eglDisplay, eglContext);
        return;
    }
    egl_eglMakeCurrent(eglDisplay, eglSurface, eglSurface, eglContext);

    // Now get extensions
    const char* Exts = gles_glGetString(GL_EXTENSIONS);
    // Parse them!
    #define S(A, B, C) if(strstr(Exts, A)) { hardext.B = 1; SHUT(LOGD("LIBGL: Extension %s detected%s",A, C?" and used\n":"\n")); } 
    if(strstr(Exts, "GL_APPLE_texture_2D_limited_npot")) hardext.npot = 1;
    if(strstr(Exts, "GL_ARB_texture_non_power_of_two ")) hardext.npot = 2;
    if(hardext.npot>0) {
        SHUT(LOGD("LIBGL: Hardware %s NPOT detected and used\n", hardext.npot==2?"Full":"Limited"));
    }
    S("GL_OES_blend_subtract", blendsub, 1);
    S("GL_OES_blend_func_separate", blendfunc, 1);
    S("GL_OES_blend_equation_separate", blendeq, 1);
    S("GL_EXT_blend_minmax", blendminmax, 1);
    S("GL_EXT_blend_color", blendcolor, 1);
    if(hardext.blendcolor==0) {
        // try by just loading the function
        LOAD_GLES_OR_OES(glBlendColor);
        if(gles_glBlendColor != NULL) {
            hardext.blendcolor = 1;
	    SHUT(LOGD("LIBGL: Extension glBlendColor found and used\n"));
	}
    }
    S("GL_OES_point_sprite", pointsprite, 1); 
    S("GL_OES_point_size_array", pointsize, 0);
    S("GL_OES_element_index_uint", elementuint, 0);
    S("GL_OES_framebuffer_object", fbo, 1);
    S("GL_OES_packed_depth_stencil", depthstencil, 1);
    S("GL_OES_depth24", depth24, 1);
    S("GL_OES_rgb8_rgba8", rgba8, 1);
    S("GL_EXT_multi_draw_arrays", multidraw, 1);
    S("GL_EXT_texture_format_BGRA8888", bgra8888, 1);
    S("GL_OES_depth_texture", depthtex, 1);
    S("GL_OES_texture_cube_map", cubemap, 1);

    // Now get some max stuffs
    gles_glGetIntegerv(GL_MAX_TEXTURE_SIZE, &hardext.maxsize);
    SHUT(LOGD("LIBGL: Max texture size: %d\n", hardext.maxsize));
    gles_glGetIntegerv(GL_MAX_TEXTURE_UNITS, &hardext.maxtex);
    gles_glGetIntegerv(GL_MAX_LIGHTS, &hardext.maxlights);
    if(hardext.maxtex>MAX_TEX) hardext.maxtex=MAX_TEX;      // caping, as there are some fixed-sized array...
    if(hardext.maxlights>MAX_LIGHT) hardext.maxlights=MAX_LIGHT;                // caping lights too
    SHUT(LOGD("LIBGL: Texture Units: %d, Max lights: %d\n", hardext.maxtex, hardext.maxlights));
#ifndef PANDORA
// The IMPLEMENTATION_COLOR_READ is pretty buggy on the Pandora, so disabling it (it's just use to blit PBuffer to Drawable in glx.c)
    gles_glGetIntegerv(GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES, &hardext.readf);
    gles_glGetIntegerv(GL_IMPLEMENTATION_COLOR_READ_TYPE_OES, &hardext.readt);
    SHUT(LOGD("LIBGL: Implementation Read is %s/%s\n", PrintEnum(hardext.readf), PrintEnum(hardext.readt)));
#endif

    if(strstr(egl_eglQueryString(eglDisplay, EGL_EXTENSIONS), "EGL_KHR_gl_colorspace")) {
        SHUT(LOGD("LIBGL: sRGB surface supported\n"));
        hardext.srgb = 1;
    }

    // End, cleanup
    egl_eglMakeCurrent(eglDisplay, 0, 0, EGL_NO_CONTEXT);
    egl_eglDestroySurface(eglDisplay, eglSurface);
    egl_eglDestroyContext(eglDisplay, eglContext);
}
