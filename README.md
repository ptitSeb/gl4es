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
 * Internaly, Texture coordinates are 2D, Vertex are 3D only (no real support for W for vertex, or 3D texture / cubemaps)
 * Probably many other things

----

Compiling
----
*for Pandora*

    cmake . ; make GL
    
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
