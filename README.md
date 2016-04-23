glshim
====

This is a shim providing OpenGL 1.x functionality to OpenGL ES accelerated cards.

Most function of OpenGL up to 1.5 are supported, with some notable exceptions:
 * Reading of Depth or Stencil buffer will not work
 * GL_FEEDBACK mode is not implemented
 * OcclusionQuery is not implemented
 
Some know limitations:
 * GL_SELECT as some limitation in its implementation (for exemple, current Depth buffer or binded texture are not taken into account)
 * NPOT texture are supported, but not with GL_REPEAT / GL_MIRRORED, only GL_CLAMP will work properly
 * Framebuffer use FRAMEBUFFER_OES extension (that must be present in the GLES 1.1 stack)
 * Multiple Color attachment on Framebuffer are not supported
 * Probably many other things

----

Compiling
----
*for Pandora*

    cmake . -DPANDORA=1; make GL
    
*or for the Raspberry Pi*

    cmake . -DBCMHOST=1; make GL

*or for the ODroid*

    cmake . -DODROID=1; make GL

*or for Android*

    An Android.mk is provided that should compile with an NDK


*or use ccmake*
Alternatively, you can use the curses-bases ccmake to select wich platform to use interactively.
    
----

GLU
----
Standard GLU do works without any issues.

But you can also find a GLES optimized version og GLU there https://github.com/lunixbochs/glues

    git clone git@github.com:lunixbochs/glues.git; git checkout glu; cmake .; make

----

Installation
----

Put lib/libGL.so.1 in your `LD_LIBRARY_PATH`.

----

Usage
----

There are many environnement variable to control glshim behavour. All are numeric, except LIBGL_VERSION that take a string.

##### LIBGL_FB
Controls the Framebuffer output
 * 0 : Default, using standard x11 rendering
 * 1 : Use Framebuffer output (x11 bypassed, only fullscreen)
 * 2 : Use Framebuffer, but also an intermediary FBO

##### LIBGL_XREFRESH
Debug helper in specific cases
 * 0 : Default, nothing special
 * 1 : xrefresh will be called on cleanup

##### LIBGL_STACKTRACE
Automatic Backtrace log
 * 0 : Default, nothing special
 * 1 : stacktrace will be printed on crash

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
 * 8 : advertise a max texture size of 8192, but every texture wich one size > 2048 are shrinked to 2048
 * 9 : advertise a max texture size of 8192, but every texture wich one size > 4096 are / 4 and the one > 512 are / 2, but empty texture are not shrinked
 * 10: advertise a max texture size of 8192, but every texture wich one size > 2048 are / 4 and the one > 512 are / 2, but empty texture are not shrinked
 
##### LIBGL_TEXDUMP
Texture dump
 * 0 : Default, nothing special
 * 1 : Texture dump enabled

##### LIBGL_ALPHAHACK
Experimental: enable Alpha test only when using texture that contains an alpha channel
 * 0 : Default, nothing special
 * 1 : Alpha Hack enabled

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
Experimental: Batch mode (fuse of contigous Display list, to limit Draw calls)
 * 0 : Default, only Draw list created during a glList are fused (i.e. contigous glBegin / glEnd inside a List)
 * 1 : Force a maximum of call to be batched (like if all was inside a big glList)
 * 2 : Disable Batch mode completly, no fuse of draw list
 
##### LIBGL_NOERROR
Hack: glGetError() always return GL_NOERROR
 * 0 : Default, glGetError behave as it should
 * 1 : glGetError never fail.

##### LIBGL_GAMMA
Pandora Hack: Set a Gamma value (in decimal formal, 1.0 means no gamma boost)
 * X.Y : Use X.Y as gamma when creating context (typical value can be 1.6 or 2.0)

