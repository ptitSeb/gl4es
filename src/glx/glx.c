#include <execinfo.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <unistd.h>

#include "glx.h"
#include <GLES/gl.h>

bool eglInitialized = false;
EGLDisplay eglDisplay;
EGLSurface eglSurface;
EGLConfig eglConfigs[1];

int8_t CheckEGLErrors() {
    EGLenum error;
    char *errortext;

    error = eglGetError();

    if (error != EGL_SUCCESS && error != 0) {
        switch (error) {
            case EGL_NOT_INITIALIZED:     errortext = "EGL_NOT_INITIALIZED"; break;
            case EGL_BAD_ACCESS:          errortext = "EGL_BAD_ACCESS"; break;
            case EGL_BAD_ALLOC:           errortext = "EGL_BAD_ALLOC"; break;
            case EGL_BAD_ATTRIBUTE:       errortext = "EGL_BAD_ATTRIBUTE"; break;
            case EGL_BAD_CONTEXT:         errortext = "EGL_BAD_CONTEXT"; break;
            case EGL_BAD_CONFIG:          errortext = "EGL_BAD_CONFIG"; break;
            case EGL_BAD_CURRENT_SURFACE: errortext = "EGL_BAD_CURRENT_SURFACE"; break;
            case EGL_BAD_DISPLAY:         errortext = "EGL_BAD_DISPLAY"; break;
            case EGL_BAD_SURFACE:         errortext = "EGL_BAD_SURFACE"; break;
            case EGL_BAD_MATCH:           errortext = "EGL_BAD_MATCH"; break;
            case EGL_BAD_PARAMETER:       errortext = "EGL_BAD_PARAMETER"; break;
            case EGL_BAD_NATIVE_PIXMAP:   errortext = "EGL_BAD_NATIVE_PIXMAP"; break;
            case EGL_BAD_NATIVE_WINDOW:   errortext = "EGL_BAD_NATIVE_WINDOW"; break;
            default:                      errortext = "unknown"; break;
        }

        printf("ERROR: EGL Error detected: %s (0x%X)\n", errortext, error);
        return 1;
    }

    return 0;
}

static int get_config_default(int attribute, int *value) {
    switch (attribute) {
        case GLX_USE_GL:
        case GLX_RGBA:
        case GLX_DOUBLEBUFFER:
            *value = 1;
            break;
        case GLX_LEVEL:
        case GLX_STEREO:
            *value = 0;
            break;
        case GLX_AUX_BUFFERS:
            *value = 0;
            break;
        case GLX_RED_SIZE:
            *value = 5;
            break;
        case GLX_GREEN_SIZE:
            *value = 6;
            break;
        case GLX_BLUE_SIZE:
            *value = 5;
            break;
        case GLX_ALPHA_SIZE:
            *value = 8;
            break;
        case GLX_DEPTH_SIZE:
            *value = 16;
            break;
        case GLX_STENCIL_SIZE:
        case GLX_ACCUM_RED_SIZE:
        case GLX_ACCUM_GREEN_SIZE:
        case GLX_ACCUM_BLUE_SIZE:
        case GLX_ACCUM_ALPHA_SIZE:
            *value = 0;
            break;
        case GLX_TRANSPARENT_TYPE:
            *value = GLX_NONE;
            break;
        case GLX_RENDER_TYPE:
            *value = GLX_RGBA_BIT | GLX_COLOR_INDEX_BIT;
            break;
        case GLX_VISUAL_ID:
            *value = 1;
            break;
        case GLX_FBCONFIG_ID:
            *value = 1;
            break;
        case GLX_DRAWABLE_TYPE:
            *value = GLX_WINDOW_BIT;
            break;
        case GLX_BUFFER_SIZE:
             *value = 16;
            break;
        case GLX_X_VISUAL_TYPE:
        case GLX_CONFIG_CAVEAT:
        case GLX_SAMPLE_BUFFERS:
        case GLX_SAMPLES:
            *value = 0;
            break;
        default:
            printf("libGL: unknown attrib %i\n", attribute);
            *value = 0;
            return 1;
    }
    return 0;
}

// hmm...
static EGLContext eglContext;
static Display *g_display = NULL;
static GLXContext glxContext = NULL;

#ifndef FBIO_WAITFORVSYNC
#define FBIO_WAITFORVSYNC _IOW('F', 0x20, __u32)
#endif
static bool g_showfps = false;
static bool g_usefb = false;
static bool g_vsync = false;
static bool g_xrefresh = false;
static bool g_stacktrace = false;
static bool g_bcm_active = false;
#ifndef BCMHOST
static bool g_bcmhost = false;
#else
static bool g_bcmhost = true;
#endif

static int fbdev = -1;
static int swap_interval = 1;

static void init_display(Display *display) {
    if (! g_display) {
        g_display = display;//XOpenDisplay(NULL);
    }
    if (g_usefb) {
        eglDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    } else {
		eglDisplay = eglGetDisplay(display);
    }
}

static void init_vsync() {
    fbdev = open("/dev/fb0", O_RDONLY);
    if (fbdev < 0) {
        fprintf(stderr, "Could not open /dev/fb0 for vsync.\n");
    }
}

static void xrefresh() {
    system("xrefresh");
}

static void signal_handler(int sig) {
    if (g_xrefresh)
        xrefresh();

#ifdef BCMHOST
    if (g_bcm_active) {
        g_bcm_active = false;
        bcm_host_deinit();
    }
#endif

    if (g_stacktrace) {
        switch (sig) {
            case SIGBUS:
            case SIGFPE:
            case SIGILL:
            case SIGSEGV: {
                void *array[10];
                size_t size = backtrace(array, 10);
                if (! size) {
                    printf("No stacktrace. Compile with -funwind-tables.\n");
                } else {
                    printf("Stacktrace: %i\n", size);
                    backtrace_symbols_fd(array, size, 2);
                }
                break;
            }
        }
    }
    signal(sig, SIG_DFL);
    raise(sig);
}

static void scan_env() {
    static bool first = true;
    if (! first)
        return;

    first = false;
    printf("libGL: built on %s %s\n", __DATE__, __TIME__);
    #define env(name, global, message)                    \
        char *env_##name = getenv(#name);                 \
        if (env_##name && strcmp(env_##name, "1") == 0) { \
            printf("libGL: " message "\n");               \
            global = true;                                \
        }

    env(LIBGL_XREFRESH, g_xrefresh, "xrefresh will be called on cleanup");
    env(LIBGL_STACKTRACE, g_stacktrace, "stacktrace will be printed on crash");
    if (g_xrefresh || g_stacktrace || g_bcmhost) {
        // TODO: a bit gross. Maybe look at this: http://stackoverflow.com/a/13290134/293352
        signal(SIGBUS, signal_handler);
        signal(SIGFPE, signal_handler);
        signal(SIGILL, signal_handler);
        signal(SIGSEGV, signal_handler);
        if (g_xrefresh || g_bcmhost) {
            signal(SIGINT, signal_handler);
            signal(SIGQUIT, signal_handler);
            signal(SIGTERM, signal_handler);
        }
        if (g_xrefresh)
            atexit(xrefresh);
#ifdef BCMHOST
            atexit(bcm_host_deinit);
#endif
    }
    env(LIBGL_FB, g_usefb, "framebuffer output enabled");
    env(LIBGL_FPS, g_showfps, "fps counter enabled");
    env(LIBGL_VSYNC, g_vsync, "vsync enabled");
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd))!= NULL)
        printf("LIBGL: Current folder is:%s\n", cwd);
    if (g_vsync) {
        init_vsync();
    }
}

GLXContext glXCreateContext(Display *display,
                            XVisualInfo *visual,
                            GLXContext shareList,
                            Bool isDirect) {
    EGLint configAttribs[] = {
#ifdef PANDORA
        EGL_RED_SIZE, 5,
        EGL_GREEN_SIZE, 6,
        EGL_BLUE_SIZE, 5,
#endif
        EGL_DEPTH_SIZE, 16,
#ifdef USE_ES2
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
#else
        EGL_BUFFER_SIZE, 16,
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES_BIT,
#endif
        EGL_NONE
    };

#ifdef USE_ES2
    EGLint attrib_list[] = {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE
    };
#else
    EGLint *attrib_list = NULL;
#endif

    scan_env();

#ifdef BCMHOST
    if (! g_bcm_active) {
        g_bcm_active = true;
        bcm_host_init();
    }
#endif

    GLXContext fake = malloc(sizeof(struct __GLXContextRec));
	memset(fake, 0, sizeof(struct __GLXContextRec));
	if (!g_usefb)
		eglMakeCurrent(eglDisplay, NULL, NULL, EGL_NO_CONTEXT);	// just in case some context is already attached. *TODO: track that?
	else {
		if (eglDisplay != NULL) {
			eglMakeCurrent(eglDisplay, NULL, NULL, EGL_NO_CONTEXT);
			if (eglContext != NULL) {
				eglDestroyContext(eglDisplay, eglContext);
				eglContext = NULL;
			}
			if (eglSurface != NULL) {
				eglDestroySurface(eglDisplay, eglSurface);
				eglSurface = NULL;
			}
		}
	}
    // make an egl context here...
    EGLBoolean result;
    if (eglDisplay == NULL || eglDisplay == EGL_NO_DISPLAY) {
        init_display(display);
        if (eglDisplay == EGL_NO_DISPLAY) {
            printf("Unable to create EGL display.\n");
            return fake;
        }
    }

    // first time?
    if (eglInitialized == false) {
        eglBindAPI(EGL_OPENGL_ES_API);
        result = eglInitialize(eglDisplay, NULL, NULL);
        if (result != EGL_TRUE) {
            printf("Unable to initialize EGL display.\n");
            return fake;
        }
        eglInitialized = true;
    }

    int configsFound;
	if (!g_usefb)
		result = eglChooseConfig(eglDisplay, configAttribs, fake->eglConfigs, 1, &configsFound);
	else
		result = eglChooseConfig(eglDisplay, configAttribs, eglConfigs, 1, &configsFound);

    CheckEGLErrors();
    if (result != EGL_TRUE || configsFound == 0) {
        printf("No EGL configs found.\n");
        return fake;
    }
	if (!g_usefb)
		fake->eglContext = eglCreateContext(eglDisplay, fake->eglConfigs[0], EGL_NO_CONTEXT, attrib_list);
	else
		eglContext = eglCreateContext(eglDisplay, eglConfigs[0], EGL_NO_CONTEXT, attrib_list);

    CheckEGLErrors();

    // need to return a glx context pointing at it
    fake->display = (g_usefb)?g_display:display;
    fake->direct = true;
    fake->xid = 1;
	//*TODO* put eglContext inside GLXcontext, to handle multiple Glxcontext
    return fake;
}

GLXContext glXCreateContextAttribsARB(Display *display, void *config,
                                      GLXContext share_context, Bool direct,
                                      const int *attrib_list) {
    return glXCreateContext(display, NULL, NULL, direct);
}

void glXDestroyContext(Display *display, GLXContext ctx) {
    if ((!g_usefb && ctx->eglContext) || (g_usefb && eglContext)) {
		EGLBoolean result = eglDestroyContext(eglDisplay, (g_usefb)?eglContext:ctx->eglContext);
        if (!g_usefb && ctx->eglSurface != NULL) {
            eglDestroySurface(eglDisplay, ctx->eglSurface);
			eglSurface = ctx->eglSurface = NULL;
        }
        if (g_usefb && eglSurface != NULL) {
            eglDestroySurface(eglDisplay, eglSurface);
        }
        if (result != EGL_TRUE) {
            printf("Failed to destroy EGL context.\n");
        }
        /*if (fbdev >= 0) {
            close(fbdev);
            fbdev = -1;
        }*/
    }
    return;
}

Display *glXGetCurrentDisplay() {
	if (!g_usefb)
		return XOpenDisplay(NULL);
	else
		if (g_display && eglContext) {
			return g_display;
		}
    return NULL;
}

XVisualInfo *glXChooseVisual(Display *display,
                             int screen,
                             int *attributes) {

    // apparently can't trust the Display I'm passed?
/*
    if (g_display == NULL) {
        g_display = XOpenDisplay(NULL);
    }
*/
    int default_depth = XDefaultDepth(display, screen);
    if (default_depth != 16 && default_depth != 24)
        printf("libGL: unusual desktop color depth %d\n", default_depth);

    XVisualInfo *visual = (XVisualInfo *)malloc(sizeof(XVisualInfo));
    if (!XMatchVisualInfo(display, screen, default_depth, TrueColor, visual)) {
        printf("libGL: XMatchVisualInfo failed in glXChooseVisual\n");
        return NULL;
    }

    return visual;
}

/*
EGL_BAD_MATCH is generated if draw or read are not compatible with context
or if context is set to EGL_NO_CONTEXT and draw or read are not set to
EGL_NO_SURFACE, or if draw or read are set to EGL_NO_SURFACE and context is
not set to EGL_NO_CONTEXT.
*/

Bool glXMakeCurrent(Display *display,
                    GLXDrawable drawable,
                    GLXContext context) {
    if (eglDisplay != NULL) {
        eglMakeCurrent(eglDisplay, NULL, NULL, EGL_NO_CONTEXT);
		if (g_usefb)
			if (eglSurface != NULL) {
				eglDestroySurface(eglDisplay, eglSurface);
			}
    }
    glxContext = context;
    // call with NULL to just destroy old stuff.
    if (! context) {
        return true;
    }
    if (eglDisplay == NULL) {
        init_display(display);
    }

    if (g_usefb)
        drawable = 0;
	if (!g_usefb) {
		// need current surface for eglSwapBuffer
		if (context->eglSurface)
			eglSurface = context->eglSurface;		// reused previously created Surface
		else
			eglSurface = context->eglSurface = eglCreateWindowSurface(eglDisplay, context->eglConfigs[0], drawable, NULL);
	} else
		eglSurface = eglCreateWindowSurface(eglDisplay, eglConfigs[0], drawable, NULL);
    CheckEGLErrors();
    
    glxContext->drawable = drawable;

    EGLBoolean result = eglMakeCurrent(eglDisplay, (g_usefb)?eglSurface:context->eglSurface, (g_usefb)?eglSurface:context->eglSurface, (g_usefb)?eglContext:context->eglContext);
    CheckEGLErrors();
    if (result) {
        return true;
    }
    return false;
}

Bool glXMakeContextCurrent(Display *display, int drawable,
                           int readable, GLXContext context) {
    return glXMakeCurrent(display, drawable, context);
}

void glXSwapBuffers(Display *display,
                    int drawable) {
    static int frames = 0;

    if (g_vsync && fbdev >= 0) {
        // TODO: can I just return if I don't meet vsync over multiple frames?
        // this will just block otherwise.
        int arg = 0;
        for (int i = 0; i < swap_interval; i++) {
            ioctl(fbdev, FBIO_WAITFORVSYNC, &arg);
        }
    }
    eglSwapBuffers(eglDisplay, eglSurface);
    CheckEGLErrors();

    if (g_showfps) {
        // framerate counter
        static float avg, fps = 0;
        static int frame1, last_frame, frame, now, current_frames;
        struct timeval out;
        gettimeofday(&out, NULL);
        now = out.tv_sec;
        frame++;
        current_frames++;

        if (frame == 1) {
            frame1 = now;
        } else if (frame1 < now) {
            if (last_frame < now) {
                float change = current_frames / (float)(now - last_frame);
                float weight = 0.7;
                if (! fps) {
                    fps = change;
                } else {
                    fps = (1 - weight) * fps + weight * change;
                }
                current_frames = 0;

                avg = frame / (float)(now - frame1);
                printf("libGL fps: %.2f, avg: %.2f\n", fps, avg);
            }
        }
        last_frame = now;
    }
}

int glXGetConfig(Display *display,
                 XVisualInfo *visual,
                 int attribute,
                 int *value) {
    return get_config_default(attribute, value);
}

const char *glXQueryExtensionsString(Display *display, int screen) {
    const char *extensions = {
        "GLX_ARB_create_context "
        "GLX_ARB_create_context_profile "
        "GLX_EXT_create_context_es2_profile "
    };
    return extensions;
}

const char *glXQueryServerString(Display *display, int screen, int name) {
    return "";
}

Bool glXQueryExtension(Display *display, int *errorBase, int *eventBase) {
    if (errorBase)
        *errorBase = 0;

    if (eventBase)
        *eventBase = 0;

    return true;
}

Bool glXQueryVersion(Display *display, int *major, int *minor) {
    // TODO: figure out which version we want to pretend to implement
    *major = 1;
    *minor = 4;
    return true;
}

const char *glXGetClientString(Display *display, int name) {
    // TODO: return actual data here
    switch (name) {
        case GLX_VENDOR: return "OpenPandora";
        case GLX_VERSION: return "1.4 OpenPandora";
        case GLX_EXTENSIONS: break;
    }
    return "";
}

int glXQueryContext( Display *dpy, GLXContext ctx, int attribute, int *value ){
	*value=0;
	if (ctx) switch (attribute) {
		case GLX_FBCONFIG_ID: *value=ctx->xid; break;
		case GLX_RENDER_TYPE: *value=GLX_RGBA_TYPE; break;
		case GLX_SCREEN: break;			// screen n# is always 0
	}
    return 0;
}


void glXQueryDrawable( Display *dpy, int draw, int attribute,
                       unsigned int *value ) {
	*value=0;
}

// stubs for glfw (GLX 1.3)
GLXContext glXGetCurrentContext() {
    // hack to make some games start
    if (g_usefb)
		return glxContext ? glxContext : (void *)1;
	else
		return glxContext;
}

GLXFBConfig *glXChooseFBConfig(Display *display, int screen,
                       const int *attrib_list, int *count) {
    *count = 1;
    GLXFBConfig *configs = malloc(sizeof(GLXFBConfig) * *count);
    return configs;
}

GLXFBConfig *glXGetFBConfigs(Display *display, int screen, int *count) {
    *count = 1;
    GLXFBConfig *configs = malloc(sizeof(GLXFBConfig) * *count);
    return configs;
}

int glXGetFBConfigAttrib(Display *display, GLXFBConfig config, int attribute, int *value) {
    return get_config_default(attribute, value);
}

XVisualInfo *glXGetVisualFromFBConfig(Display *display, GLXFBConfig config) {
    /*if (g_display == NULL) {
        g_display = XOpenDisplay(NULL);
    }*/
    XVisualInfo *visual = (XVisualInfo *)malloc(sizeof(XVisualInfo));
    XMatchVisualInfo(display, 0, 16, TrueColor, visual);
    return visual;
}

GLXContext glXCreateNewContext(Display *display, GLXFBConfig config,
                               int render_type, GLXContext share_list,
                               Bool is_direct) {
    return glXCreateContext(display, 0, share_list, is_direct);
}

void glXSwapIntervalMESA(int interval) {
    printf("glXSwapInterval(%i)\n", interval);
    if (! g_vsync)
        printf("Enable LIBGL_VSYNC=1 if you want to use vsync.\n");
    swap_interval = interval;
}

void glXSwapIntervalSGI(int interval) {
    glXSwapIntervalMESA(interval);
}

void glXSwapIntervalEXT(Display *display, int drawable, int interval) {
    glXSwapIntervalMESA(interval);
}

// misc stubs
void glXCopyContext(Display *display, GLXContext src, GLXContext dst, GLuint mask) {
	// mask is ignored for now, but should include glPushAttrib / glPopAttrib
	memcpy(dst, src, sizeof(struct __GLXContextRec));
}
void glXCreateGLXPixmap(Display *display, XVisualInfo * visual, Pixmap pixmap) {} // should return GLXPixmap
void glXDestroyGLXPixmap(Display *display, void *pixmap) {} // really wants a GLXpixmap
void glXCreateWindow(Display *display, GLXFBConfig config, Window win, int *attrib_list) {} // should return GLXWindow
void glXDestroyWindow(Display *display, void *win) {} // really wants a GLXWindow
GLXDrawable glXGetCurrentDrawable() {if (glxContext) return glxContext->drawable; else return 0;} // this should actually return GLXDrawable.
Bool glXIsDirect(Display * display, GLXContext ctx) {
    return true;
}
/*
 * Generate OpenGL-compatible bitmap.
 * From Mesa-9.0.1
 */
static void
fill_bitmap(Display * dpy, Window win, GC gc,
            unsigned int width, unsigned int height,
            int x0, int y0, unsigned int c, GLubyte * bitmap)
{
   XImage *image;
   unsigned int x, y;
   Pixmap pixmap;
   XChar2b char2b;

   pixmap = XCreatePixmap(dpy, win, 8 * width, height, 1);
   XSetForeground(dpy, gc, 0);
   XFillRectangle(dpy, pixmap, gc, 0, 0, 8 * width, height);
   XSetForeground(dpy, gc, 1);

   char2b.byte1 = (c >> 8) & 0xff;
   char2b.byte2 = (c & 0xff);

   XDrawString16(dpy, pixmap, gc, x0, y0, &char2b, 1);

   image = XGetImage(dpy, pixmap, 0, 0, 8 * width, height, 1, XYPixmap);
   if (image) {
      /* Fill the bitmap (X11 and OpenGL are upside down wrt each other).  */
      for (y = 0; y < height; y++)
         for (x = 0; x < 8 * width; x++)
            if (XGetPixel(image, x, y))
               bitmap[width * (height - y - 1) + x / 8] |=
                  (1 << (7 - (x % 8)));
      XDestroyImage(image);
   }

   XFreePixmap(dpy, pixmap);
}
/*
 * determine if a given glyph is valid and return the
 * corresponding XCharStruct.
 * From MesaGL-9.0.1
 */
static XCharStruct *
isvalid(XFontStruct * fs, int which)
{
   unsigned int rows, pages;
   int byte1 = 0, byte2 = 0;
   int i, valid = 1;

   rows = fs->max_byte1 - fs->min_byte1 + 1;
   pages = fs->max_char_or_byte2 - fs->min_char_or_byte2 + 1;

   if (rows == 1) {
      /* "linear" fonts */
      if ((fs->min_char_or_byte2 > which) || (fs->max_char_or_byte2 < which))
         valid = 0;
   }
   else {
      /* "matrix" fonts */
      byte2 = which & 0xff;
      byte1 = which >> 8;
      if ((fs->min_char_or_byte2 > byte2) ||
          (fs->max_char_or_byte2 < byte2) ||
          (fs->min_byte1 > byte1) || (fs->max_byte1 < byte1))
         valid = 0;
   }

   if (valid) {
      if (fs->per_char) {
         if (rows == 1) {
            /* "linear" fonts */
            return (fs->per_char + (which - fs->min_char_or_byte2));
         }
         else {
            /* "matrix" fonts */
            i = ((byte1 - fs->min_byte1) * pages) +
               (byte2 - fs->min_char_or_byte2);
            return (fs->per_char + i);
         }
      }
      else {
         return (&fs->min_bounds);
      }
   }
   return (NULL);
}

void glXUseXFont(Font font, int first, int count, int listBase) {
	/* Mostly from MesaGL-9.0.1 
	 * 
	 */
	// First get current Display and Window
	XFontStruct *fs;
	unsigned int max_width, max_height, max_bm_width, max_bm_height;
    Pixmap pixmap;
    XGCValues values;
    GC gc;
    int i;
    unsigned long valuemask;
	GLubyte *bm;
	Display *dpy = glxContext->display;
	Window win = glxContext->drawable;		//TODO, check that drawable is a window and not a pixmap ?
	// Grab font params
	fs = XQueryFont(dpy, font);
    if (!fs) {
      printf("LIBGL: error, no font set before call to glXUseFont\n");
      return;
    }
	max_width = fs->max_bounds.rbearing - fs->min_bounds.lbearing;
    max_height = fs->max_bounds.ascent + fs->max_bounds.descent;
    max_bm_width = (max_width + 7) / 8;
    max_bm_height = max_height;

    bm = (GLubyte *)malloc((max_bm_width * max_bm_height) * sizeof(GLubyte));
    if (!bm) {
       XFreeFontInfo(NULL, fs, 1);
       return;
    }
    // Save GL texture parameters
    GLint swapbytes, lsbfirst, rowlength;
    GLint skiprows, skippixels, alignment;
    glGetIntegerv(GL_UNPACK_SWAP_BYTES, &swapbytes);
    glGetIntegerv(GL_UNPACK_LSB_FIRST, &lsbfirst);
    glGetIntegerv(GL_UNPACK_ROW_LENGTH, &rowlength);
    glGetIntegerv(GL_UNPACK_SKIP_ROWS, &skiprows);
    glGetIntegerv(GL_UNPACK_SKIP_PIXELS, &skippixels);
    glGetIntegerv(GL_UNPACK_ALIGNMENT, &alignment);
	// Set Safe Texture params
	glPixelStorei(GL_UNPACK_SWAP_BYTES, GL_FALSE);
    glPixelStorei(GL_UNPACK_LSB_FIRST, GL_FALSE);
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
    glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);
    glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	// Create GC and Pixmap
	pixmap = XCreatePixmap(dpy, win, 10, 10, 1);
    values.foreground = BlackPixel(dpy, DefaultScreen(dpy));
    values.background = WhitePixel(dpy, DefaultScreen(dpy));
    values.font = fs->fid;
    valuemask = GCForeground | GCBackground | GCFont;
    gc = XCreateGC(dpy, pixmap, valuemask, &values);
    XFreePixmap(dpy, pixmap);
	// Loop each chars
    for (i = 0; i < count; i++) {
       unsigned int width, height, bm_width, bm_height;
       GLfloat x0, y0, dx, dy;
       XCharStruct *ch;
       int x, y;
       unsigned int c = first + i;
       int list = listBase + i;
       int valid;

       /* check on index validity and get the bounds */
       ch = isvalid(fs, c);
       if (!ch) {
          ch = &fs->max_bounds;
          valid = 0;
       }
       else {
          valid = 1;
       }
      /* glBitmap()' parameters:
          straight from the glXUseXFont(3) manpage.  */
       width = ch->rbearing - ch->lbearing;
       height = ch->ascent + ch->descent;
       x0 = -ch->lbearing;
       y0 = ch->descent - 1;
       dx = ch->width;
       dy = 0;
       /* X11's starting point.  */
       x = -ch->lbearing;
       y = ch->ascent;
       /* Round the width to a multiple of eight.  We will use this also
         for the pixmap for capturing the X11 font.  This is slightly
         inefficient, but it makes the OpenGL part real easy.  */
       bm_width = (width + 7) / 8;
       bm_height = height;
       glNewList(list, GL_COMPILE);
       if (valid && (bm_width > 0) && (bm_height > 0)) {

          memset(bm, '\0', bm_width * bm_height);
          fill_bitmap(dpy, win, gc, bm_width, bm_height, x, y, c, bm);

          glBitmap(width, height, x0, y0, dx, dy, bm);
       }
       else {
          glBitmap(0, 0, 0.0, 0.0, dx, dy, NULL);
       }
       glEndList();
    }

	// Free GC & Pixmap
    free(bm);
    XFreeFontInfo(NULL, fs, 1);
    XFreeGC(dpy, gc);

    // Restore saved packing modes.
    glPixelStorei(GL_UNPACK_SWAP_BYTES, swapbytes);
    glPixelStorei(GL_UNPACK_LSB_FIRST, lsbfirst);
    glPixelStorei(GL_UNPACK_ROW_LENGTH, rowlength);
    glPixelStorei(GL_UNPACK_SKIP_ROWS, skiprows);
    glPixelStorei(GL_UNPACK_SKIP_PIXELS, skippixels);
    glPixelStorei(GL_UNPACK_ALIGNMENT, alignment);
	// All done
}
void glXWaitGL() {}
void glXWaitX() {}
void glXReleaseBuffersMESA() {}
