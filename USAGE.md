Usage
----

There are many environnement variable to control gl4es behavour. All are numeric, except LIBGL_VERSION that take a string.
You can also change many of this variable at runtime using the `glHint(...)` function. See [gl4eshint.h](include/gl4eshint.h) for the list of #define to use in this function.

##### LIBGL_FB
Controls the Framebuffer output
 * 0 : Default, using standard x11 rendering
 * 1 : Use Framebuffer output (x11 bypassed, only fullscreen)
 * 2 : Use Framebuffer, but also an intermediary FBO
 * 3 : Use PBuffer, allowing x11 (and windowed) rendering even if driver doesn't support it 

##### LIBGL_ES
Controls tje version of GLES to use
 * 0 : Default, using GLES 1.1 backend (unless built with DEFAULT_ES 2)
 * 1 : Use GLES 1.1 backend
 * 2 : Use GLES 2.0 backend

##### LIBGL_GL
Controls the version of OpenGL exposed
 * 0 : Default, expose OpenGL 1.5 when using GLES1.1 or OpenGL 2.0 when using GLES2.0
 * 15: Expose OpenGL 1.5
 * 20: Expose OpenGL 2.0
 * 21: Expose OpenGL 2.1

##### LIBGL_XREFRESH
Debug helper in specific cases
 * 0 : Default, nothing special
 * 1 : xrefresh will be called on cleanup

##### LIBGL_STACKTRACE
Automatic Backtrace log
 * 0 : Default, nothing special
 * 1 : stacktrace will be printed on crash

##### LIBGL_FPS
Print current FPS to the console
 * 0 : Defaut, don't mesure or printf FPS
 * 1 : Print FPS (on stdout) every second

##### LIBGL_VSYNC
VSync control
 * 0 : Default, nothing special
 * 1 : vsync enabled

##### LIBGL_RECYCLEFBO
Recycling FBO special case (don't delete a created FBO, but recycle it if needed)
 * 0 : Default, nothing special
 * 1 : Recycling of FBO enabled

##### LIBGL_MIPMAP
Handling of Manual and Automatic MIPMAP
 * 0 : Default, nothing special
 * 1 : AutoMipMap forced
 * 2 : guess AutoMipMap (based on manual mipmaping on textures)
 * 3 : ignore MipMap (mipmap creation / use entirely disabled)
 * 4 : ignore AutoMipMap on non-squared textures

##### LIBGL_FORCENPOT
Forcing NPOT (Non-Power of Two) Texture size.
 * 0 : Default, nothing special
 * 1 : If hardware only support Limited NPOT, then disabling MIPMAP (i.e. LIBGL_MIPMAP=3), so all texture can be NPOT.
       If Hardware support full NPOT, do nothing special. Usefull for GLES2 backend where limited NPOT is always supported.
 
##### LIBGL_TEXCOPY
Make a local copy of every texture for easy glGetTexImage2D
 * 0 : Default, nothing special
 * 1 : Texture copy enabled

##### LIBGL_SHRINK
Texture shrinking control
 * 0 : Default, nothing special
 * 1 : everything / 2 (using original algorithm for size reduction, all other shink mode use a refined algorithm)
 * 2 : only textures wich one size > 512 are / 2
 * 3 : only textures wich one size > 256 are / 2
 * 4 : only textures wich one size > 256 are / 2, and the one > 1024 are / 4
 * 5 : only textures wich one size > 256 are resized to 256 (if possible, because only /2 and /4 exists), but empty texture are not shrinked
 * 6 : only textures wich one size > 128 are / 2, thoses >= 512 are resized to 256 (if possible, because only /2 and /4 exists), but empty texture are not shrinked
 * 7 : only textures wich one size > 512 are / 2, but empty texture are not shrinked
 * 8 : advertise a max texture size *4, but every texture wich one size > 2048 are shrinked to 2048
 * 9 : advertise a max texture size *4, but every texture wich one size > 4096 are / 4 and the one > 512 are / 2, but empty texture are not shrinked
 * 10: advertise a max texture size *4, but every texture wich one size > 2048 are / 4 and the one > 512 are / 2, but empty texture are not shrinked
 
##### LIBGL_TEXDUMP
Texture dump
 * 0 : Default, nothing special
 * 1 : Texture dump enabled

##### LIBGL_ALPHAHACK
Experimental: enable Alpha test only when using texture that contains an alpha channel
 * 0 : Default, nothing special
 * 1 : Alpha Hack enabled

##### LIBGL_NODOWNSAMPLING
Texture downsampling control (deprecated, use LIBGL_AVOID16BITS instead)
 * 0 : Default, DXTc texture are downsampled to 16bits
 * 1 : DXTc texture are left as 32bits RGBA

##### LIBGL_STREAM
PANDORA only: enable Texture Streaming (works only on RGB textures)
 * 0 : Default, nothing special
 * 1 : Enabled on empty RGB textures
 * 2 : Enabled on all RGB textures

##### LIBGL_COPY
Control the glCopyTex(Sub)Image2D hack (they are buggy on pandora and don't work most of the time)
 * 0 : Don't use native glCopyTex(Sub)Image2D, but a workaround function using FBO
 * 1 : No glCopyTexImage2D / glCopyTexSubImage2D hack, use native ones

##### LIBGL_NOLUMALPHA
Control the availability of the LUMUNANCE_ALPHA format (can be buggy on Pandora model CC)
 * 0 : Default,GL_LUMINANCE_ALPHA is available and used if needed
 * 1 : GL_LUMINANCE_ALPHA hardware support disabled (a GL_RGBA texture will be used instead)

##### LIBGL_BLENDHACK
Experimental: Change Blend GL_SRC_ALPHA, GL_ONE to GL_ONE, GL_ONE
 * 0 : Default, nothing special
 * 1 : Change Blend GL_SRC_ALPHA, GL_ONE to GL_ONE, GL_ONE (can be usefull for Xash3D engine)

##### LIBGL_BLENDCOLOR
Hack: Export a (faked) glBlendColor
 * 0 : Default, don't expose gBlendColor
 * 1 : Exposed the function (if no hadware support, faked function willbe used)

##### LIBGL_VERSION
Hack: Control the glGetString version. Overide version string (should be in the form of "1.x")

##### LIBGL_BATCH
This has been removed with v1.0.5. `LIBGL_BEGINEND` is a better alternative. 
Also use `LIBGL_BEGINEND=0` to acheive the same result as `LIBGL_BATCH=2` (i.e. no merging of renderlist at all).
The Hint are still i place, but will always return 0 if queried, and do nothing if set.

##### LIBGL_NOERROR
Hack: glGetError() always return GL_NOERROR
 * 0 : Default, glGetError behave as it should
 * 1 : glGetError never fail.

##### LIBGL_GAMMA
Pandora Hack: Set a Gamma value (in decimal formal, 1.0 means no gamma boost)
 * X.Y : Use X.Y as gamma when creating context (typical value can be 1.6 or 2.0)

##### LIBGL_SRGB
ODROID Hack: Enable sRGB Surface (so Gamma corrected), if Hardware support it
 * 0 : Default, don't try to use sRGB surface
 * 1 : Enable sRGB Surface (but support will be tested first, must have EGL_KHR_gl_colorspace extension)

##### LIBGL_FASTMATH
Hack: Activate some Fast Math in processor/coprocessor
 * 0 : Default, nothing special
 * 1 : On OpenPandora and CHIP, activate "RunFast" on Cortex-A8 (mode default NaN, flush-to-zero)
     : Not implemented on other platforms (will do nothing)

##### LIBGL_SILENTSTUB
Debug: Hide or Show the Sub / Not found message
 * 0 : Default, the messages are shown
 * 1 : Silent, don't print the STUB or glXGetProcAddress glXXXXX not found message

##### LIBGL_NOBANNER
Show/Hide initial text
 * 0 : Default, print starting message
 * 1 : Silent: no LIBGL message at start (combile with LIBGL_SILENTSTUB for more silence)

##### LIBGL_NPOT
Expose NPOT (Non Power of Two) Support
 * 0 : Default, expose the extension that are availble by the GLES backend
 * 1 : Expose limited NPOT extension
 * 2 : Expose GL_ARB_texture_non_power_of_two extension

##### LIBGL_GLQUERIES
Expose glQueries functions
 * 0 : Don't expose the function (fake one will be used if called)
 * 1 : Default, expose fake functions (always answer 0)

##### LIBGL_NOTEXMAT
Handling of Texture Matrix
 * 0 : Default, perform handling internaly (better handling of NPOT texture on all hardware)
 * 1 : Let the driver handle texmat (can be faster in some cases, but NPOT texture may be broken)

##### LIBGL_NOTEST
Initial Hardware test
 * 0 : Default, perform intial hardware testing (using a PBuffer)
 * 1 : Do not perform test (no extensions tested or used)

##### LIBGL_NOVAOCACHE
VAO Caching
 * 0 : Default, try to cache vao to avoid memcpy in render list
 * 1 : Don't cache VAO

##### LIBGL_VABGRA
Vertex Array BGRA extension
 * 0 : Default, GL_ARB_vertex_array_bgra not exposed (still emulated)
 * 1 : Extension exposed may be faster in some cases (Arx Libertatis mainly)

##### LIBGL_BEGINEND
Merge of subsequent glBegin/glEnd blocks (will be non-effective if BATCH mode is used)
 * 0 : Don't try to merge
 * 1 : Try to merge, even if there is a glColor / glNormal in between (default)
 * 2 : Try hard to merge, even if there is a glColor / glNormal or Matrix operations in between

##### LIBGL_AVOID16BITS
Try to avoid 16bits textures
 * 0 : Default, use 16bits texture if it can avoid a convertion or for DXTc textures
 * 1 : Use 32bits texture unless specifically requested (using internalformat)

##### LIBGL_AVOID24BITS
Try to avoid 24bits textures (i.e. GL_RGB)
 * 0 : Default, use 24bits texture when it's possible
 * 1 : Force 32bits textures when GL_RGB is asked (as internal or not). Not recommanded, as it may brake some blend functions (especialy on GLES 1.1 backend). Does not impact GL_UNSIGNED_SHORT_5_6_5 and friends.

##### LIBGL_POTFRAMEBUFFER
Use only Power Of Two dimension for Framebuffer
 * 0 : Default, use NPOT dimension if supported
 * 1 : Force Framebuffer to be created with POT dimension (not advised on GLES2 backend)

##### LIBGL_NOBGRA
Ignore BGRA Texture hardware extension
 * 0 : Default, use BGRA extension if possible
 * 1 : Ignore BGRA extension, even if supported by GLES hardware

##### LIBGL_ES
Choose GLES hardware backend. WIP, don't use for now
 * 0 : Default, auto choose (GLES 1.1 for now on all platforms)
 * 1 : Use GLES 1.1 backend (so no shaders)
 * 2 : Use GLES 2.0 backend (shaders, but Fixed Pipeline function not implemented for now)

##### LIBGL_GL
Choose OpenGL version target for emulation
 * 0 : Default, auto choose (1.5 for now)
 * 15: Target OpenGL 1.5
 * 20: Target OpenGL 2.0 (with GLSL 1.10)
 * 21: Target OpenGL 2.1 (with GLSL 1.20)

##### LIBGL_NOHIGHP
Usage of highp precision in fragment shader (ES2 backend only)
 * 0 : Default, use highp if available
 * 1 : Disable usage of highp in Fragment shaders

##### LIBGL_COMMENTS
Comments in shaders are kept (also for generated shaders by fpe_shaders)
 * 0 : Default, no comments in shaders sent to GLES Hardware
 * 1 : Comments are left in Shaders sent to GLES Hardware

##### LIBGL_FBOMAKECURRENT
Workaround for FBO and glXMakeCurrent (force unbind/bind FBO when changing context)
* 0 : Disabled (Default on mast configuration)
* 1 : Enabled (Default if Vendor is ARM or if using LIBGL_FB 1 and 2)
