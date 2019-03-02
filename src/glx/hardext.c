#include "hardext.h"

#include "../gl/debug.h"
#include "../gl/gl4es.h"
#include "../gl/init.h"
#include "../gl/logs.h"
#include "../gl/loader.h"
#ifndef ANDROID
#include "rpi.h"
#endif
#include "glx_gbm.h"

#ifndef EGL_PLATFORM_GBM_KHR
#define EGL_PLATFORM_GBM_KHR                     0x31D7
#endif

static int tested = 0;

hardext_t hardext;

#define SHUT(a) if(!globals4es.nobanner) a

#if defined(NOX11) && defined(NOEGL)
__attribute__((visibility("default")))
#endif
void GetHardwareExtensions(int notest)
{
    if(tested) return;
    // put some default values
    memset(&hardext, 0, sizeof(hardext));
    hardext.maxtex = 2;
    hardext.maxsize = 2048;
    hardext.maxlights = 8;
    hardext.maxplanes = 6;

    hardext.esversion = globals4es.es;
    if(notest) 
    {
#ifndef AMIGAOS4
        SHUT(LOGD("LIBGL: Hardware test disabled, nothing activated...\n"));
#endif
        if(hardext.esversion==2) {
            hardext.maxteximage = 4;
            hardext.maxvarying = 8;
            hardext.maxtex = 4;
            hardext.maxvattrib = 8;
            hardext.npot = 1;
            hardext.fbo = 1; 
            hardext.pointsprite = 1;
            hardext.pointsize = 1;
            hardext.cubemap = 1;
        }
        return;
    }
#if defined(BCMHOST) && !defined(ANDROID)
    rpi_init();
#endif
#ifdef NOEGL
    SHUT(LOGD("LIBGL: Hardware test on current Context...\n"));
#else
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
    LOAD_EGL(eglTerminate);

    EGLDisplay eglDisplay;
    EGLSurface eglSurface;
    EGLContext eglContext;

    SHUT(LOGD("LIBGL: Using GLES %s backend\n", (hardext.esversion==1)?"1.1":"2.0"));

    // Create a PBuffer first...
    EGLint egl_context_attrib_es2[] = {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE
    };

    EGLint egl_context_attrib[] = {
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
#ifdef PANDORA
    // on the Pandora, there don't seem to exist a 8888 PBuffer config for GLES2.
        EGL_RED_SIZE, (hardext.esversion==1)?8:5,
        EGL_GREEN_SIZE, (hardext.esversion==1)?8:6,
        EGL_BLUE_SIZE, (hardext.esversion==1)?8:5,
        EGL_ALPHA_SIZE, (hardext.esversion==1)?8:0,
#else
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_ALPHA_SIZE, 8,
#endif
        EGL_SURFACE_TYPE, EGL_PBUFFER_BIT,
        EGL_RENDERABLE_TYPE, (hardext.esversion==1)?EGL_OPENGL_ES_BIT:EGL_OPENGL_ES2_BIT,
        EGL_NONE
    };

    int configsFound;
    static EGLConfig pbufConfigs[1];

#ifndef NO_GBM
    if(strstr(egl_eglQueryString(EGL_NO_DISPLAY, EGL_EXTENSIONS), "EGL_KHR_platform_gbm")) {
        SHUT(LOGD("LIBGL: GBM Surfaces supported%s\n", globals4es.usegbm?" and used":""));
        hardext.gbm = 1;
    }
#endif
    eglDisplay = egl_eglGetDisplay(EGL_DEFAULT_DISPLAY);

    egl_eglBindAPI(EGL_OPENGL_ES_API);
    if (egl_eglInitialize(eglDisplay, NULL, NULL) != EGL_TRUE) {
        LOGE("LIBGL: Error while gathering supported extension (eglInitialize: %s), default to none\n", PrintEGLError(0));
        egl_eglTerminate(eglDisplay);
        return;
    }

    egl_eglChooseConfig(eglDisplay, configAttribs, pbufConfigs, 1, &configsFound);
#ifndef PANDORA
    if(!configsFound) {
        // try without alpha channel
        configAttribs[4*2-1] = 0;
        egl_eglChooseConfig(eglDisplay, configAttribs, pbufConfigs, 1, &configsFound);
        if(configsFound) {
            SHUT(LOGD("LIBGL: No alpha channel in PBuffer context, disabling EGL Alpha channel...\n"));
            hardext.eglnoalpha = 1;
        }
    }
#endif
    if(!configsFound) {
        SHUT(LOGE("LIBGL: Error while gathering supported extension (eglChooseConfig: %s), default to none\n", PrintEGLError(0)));
        egl_eglTerminate(eglDisplay);
        return;
    }
    eglContext = egl_eglCreateContext(eglDisplay, pbufConfigs[0], EGL_NO_CONTEXT, (hardext.esversion==1)?egl_context_attrib:egl_context_attrib_es2);
    if(!eglContext) {
        SHUT(LOGE("LIBGL: Error while gathering supported extension (eglCreateContext: %s), default to none\n", PrintEGLError(0)));
        return;
    }
    eglSurface = egl_eglCreatePbufferSurface(eglDisplay, pbufConfigs[0], egl_attribs);
    if(!eglSurface) {
        SHUT(LOGE("LIBGL: Error while gathering supported extension (eglCreatePBufferSurface: %s), default to none\n", PrintEGLError(0)));
        egl_eglDestroyContext(eglDisplay, eglContext);
        egl_eglTerminate(eglDisplay);
        return;
    }
    egl_eglMakeCurrent(eglDisplay, eglSurface, eglSurface, eglContext);
#endif
    tested = 1;
    LOAD_GLES(glGetString);
    LOAD_GLES(glGetIntegerv);
    LOAD_GLES(glGetError);
    // Now get extensions
    const char* Exts = gles_glGetString(GL_EXTENSIONS);
    // Parse them!
    #define S(A, B, C) if(strstr(Exts, A)) { hardext.B = 1; SHUT(LOGD("LIBGL: Extension %s detected%s",A, C?" and used\n":"\n")); } 
    if(hardext.esversion>1) hardext.npot = 1;
    if(strstr(Exts, "GL_APPLE_texture_2D_limited_npot")) hardext.npot = 1;
    if(strstr(Exts, "GL_IMG_texture_npot")) hardext.npot = 1; // it should enable mipmap (so hardext.npot=2), but mipmap (so level > 0) needs to be POT-sized?!!
    if(strstr(Exts, "GL_ARB_texture_non_power_of_two") || strstr(Exts, "GL_OES_texture_npot")) hardext.npot = 3;
    if(hardext.npot>0) {
        SHUT(LOGD("LIBGL: Hardware %s NPOT detected and used\n", hardext.npot==3?"Full":(hardext.npot==2?"Limited+Mipmap":"Limited")));
    }
    S("GL_EXT_blend_minmax", blendminmax, 1);
    /*if(hardext.blendcolor==0) {
        // try by just loading the function
        LOAD_GLES_OR_OES(glBlendColor);
        if(gles_glBlendColor != NULL) {
            hardext.blendcolor = 1;
	        SHUT(LOGD("LIBGL: Extension glBlendColor found and used\n"));
	    }
    }*/ // I don't think this is correct
    if(hardext.esversion<2) {
        S("GL_OES_framebuffer_object", fbo, 1);
        S("GL_OES_point_sprite", pointsprite, 1); 
        S("GL_OES_point_size_array", pointsize, 0);
        S("GL_OES_texture_cube_map", cubemap, 1);
        S("GL_EXT_blend_color", blendcolor, 1);
        S("GL_OES_blend_subtract", blendsub, 1);
        S("GL_OES_blend_func_separate", blendfunc, 1);
        S("GL_OES_blend_equation_separate", blendeq, 1);
        S("GL_OES_texture_mirrored_repeat", mirrored, 1);  
    } else {
        hardext.fbo = 1; 
        SHUT(LOGD("LIBGL: FBO are in core, and so used\n"));
        hardext.pointsprite = 1;
        SHUT(LOGD("LIBGL: PointSprite are in core, and so used\n"));
        hardext.pointsize = 1;
        SHUT(LOGD("LIBGL: CubeMap are in core, and so used\n"));
        hardext.cubemap = 1;
        SHUT(LOGD("LIBGL: BlendColor is in core, and so used\n"));
        hardext.blendcolor = 1;
        SHUT(LOGD("LIBGL: Blend Substract is in core, and so used\n"));
        hardext.blendsub = 1;
        SHUT(LOGD("LIBGL: Blend Function and Equation Separation is in core, and so used\n"));
        hardext.blendfunc = 1;
        hardext.blendeq = 1;
        SHUT(LOGD("LIBGL: Texture Mirrored Repeat is in core, and so used\n"));
        hardext.mirrored = 1;
    }
    S("GL_OES_mapbuffer", mapbuffer, 0);
    S("GL_OES_element_index_uint", elementuint, 1);
    S("GL_OES_packed_depth_stencil", depthstencil, 1);
    S("GL_OES_depth24", depth24, 1);
    S("GL_OES_rgb8_rgba8", rgba8, 1);
    S("GL_EXT_multi_draw_arrays", multidraw, 0);
    if(!globals4es.nobgra) {
        S("GL_EXT_texture_format_BGRA8888", bgra8888, 1);
    }
    if(!globals4es.nodepthtex) {
        S("GL_OES_depth_texture", depthtex, 1);
        S("GL_OES_texture_stencil8", stenciltex, 1);
    }
    S("GL_OES_draw_texture", drawtex, 1);
    S("GL_EXT_texture_rg", rgtex, 1);
    if(globals4es.floattex) {
        S("GL_OES_texture_float", floattex, 1);
        S("GL_OES_texture_half_float", halffloattex, 1);
        S("GL_EXT_color_buffer_float", floatfbo, 1);
        S("GL_EXT_color_buffer_half_float", halffloatfbo, 1);
    }

    if (hardext.esversion>1) {
        if(!globals4es.nohighp) {
            S("GL_OES_fragment_precision_high", highp, 1);
            if(!hardext.highp) {
                // check if highp is supported anyway
                LOAD_GLES2(glGetShaderPrecisionFormat);
                if(gles_glGetShaderPrecisionFormat) {
                    GLint range[2] = {0};
                    GLint precision=0;
                    gles_glGetShaderPrecisionFormat(GL_FRAGMENT_SHADER, GL_HIGH_FLOAT, range, &precision);
                    if(!(range[0]==0 && range[1]==0 && precision==0)) {
                        hardext.highp = 2;  // no need to declare #entension here
                        SHUT(LOGD("LIBGL: high precision float in fragment shader available and used\n"));
                    }
                }
            }
        }
        S("GL_EXT_frag_depth", fragdepth, 1);
        gles_glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &hardext.maxvattrib);
        SHUT(LOGD("LIBGL: Max vertex attrib: %d\n", hardext.maxvattrib));
        S("GL_OES_standard_derivatives", derivatives, 1);
    }
    // Now get some max stuffs
    gles_glGetIntegerv(GL_MAX_TEXTURE_SIZE, &hardext.maxsize);
    SHUT(LOGD("LIBGL: Max texture size: %d\n", hardext.maxsize));
    gles_glGetIntegerv((hardext.esversion==1)?GL_MAX_TEXTURE_UNITS:GL_MAX_TEXTURE_IMAGE_UNITS, &hardext.maxtex);
    if (hardext.esversion==1) {
        gles_glGetIntegerv(GL_MAX_LIGHTS, &hardext.maxlights);
        gles_glGetIntegerv(GL_MAX_CLIP_PLANES, &hardext.maxplanes);
        hardext.maxteximage=hardext.maxtex;
    } else {
        // simulated stuff using the FPE
        hardext.maxlights = 8;
        hardext.maxplanes = 6;
        gles_glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &hardext.maxteximage);
        gles_glGetIntegerv(GL_MAX_VARYING_VECTORS, &hardext.maxvarying);
        SHUT(LOGD("LIBGL: Max Varying Vector: %d\n", hardext.maxvarying));
        if(hardext.maxvattrib<16 && hardext.maxtex>4)
            hardext.maxtex = 4; // with less then 16 vertexattrib, more then 4 textures seems unreasonnable
    }
    if(hardext.maxtex>MAX_TEX) hardext.maxtex=MAX_TEX;      // caping, as there are some fixed-sized array...
    if(hardext.maxteximage>MAX_TEX) hardext.maxteximage=MAX_TEX;
    if(hardext.maxlights>MAX_LIGHT) hardext.maxlights=MAX_LIGHT;                // caping lights too
    if(hardext.maxplanes>MAX_CLIP_PLANES) hardext.maxplanes=MAX_CLIP_PLANES;    // caping planes, even 6 should be the max supported anyway
    SHUT(LOGD("LIBGL: Texture Units: %d(%d), Max lights: %d, Max planes: %d\n", hardext.maxtex, hardext.maxteximage, hardext.maxlights, hardext.maxplanes));
    S("GL_EXT_texture_filter_anisotropic", aniso, 1);
    if(hardext.aniso) {
        gles_glGetIntegerv(GL_MAX_TEXTURE_MAX_ANISOTROPY, &hardext.aniso);
        if(gles_glGetError()!=GL_NO_ERROR)
            hardext.aniso = 0;
        if(hardext.aniso)
            SHUT(LOGD("LIBGL: Max Anisotropic filtering: %d\n", hardext.aniso));
    }
    // get GLES driver signatures...
    const char* vendor = gles_glGetString(GL_VENDOR);
    SHUT(LOGD("LIBGL: Hardware vendor is %s\n", vendor));
    if(strstr(vendor, "ARM"))
        hardext.vendor = VEND_ARM;
    else if(strstr(vendor, "Imagination Technologies"))
        hardext.vendor = VEND_IMGTEC;

#ifndef NOEGL
    if(strstr(egl_eglQueryString(eglDisplay, EGL_EXTENSIONS), "EGL_KHR_gl_colorspace")) {
        SHUT(LOGD("LIBGL: sRGB surface supported\n"));
        hardext.srgb = 1;
    }

    // End, cleanup
    egl_eglMakeCurrent(eglDisplay, 0, 0, EGL_NO_CONTEXT);
    egl_eglDestroySurface(eglDisplay, eglSurface);
    egl_eglDestroyContext(eglDisplay, eglContext);

    egl_eglTerminate(eglDisplay);
#endif
}
