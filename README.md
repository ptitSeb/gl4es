gl4es
====

![gl4es build status](https://api.travis-ci.org/ptitSeb/gl4es.png "gl4es build status")

This is a library providing OpenGL 1.x functionality for OpenGL ES 1.1 accelerated hardware.
A new GLES2.0 backend also provide some OpenGL 2.x support (and also support OpenGL 1.5 function, sometimes better then when using GLES 1.1 backend)
GL4ES is known to work on many platform: OpenPandora, ODroid, RaspberryPI (2 and 3 at least), PocketCHIP, (otherfruit)PI, Android, x86 and x86_64 Linux (using mesa-egl). There is also some WIP support for AmigaOS4, using experimental GLES2 driver for Warp3D.

This is a fork a glshim (https://github.com/lunixbochs/glshim). Go check this lib if you need things like RemoteGL or TinyGLES (for 100% software rendering).

The focus is on compatibility and speed with a wide selection of game and software.

It has been tested successfully of a large selection of games and software, including: Minecraft, OpenMW, SeriousSam (both First and Second Encounters), RVGL (ReVolt GL), TSMC (The Secret Maryo Chronicles), TORCS, SpeedDreams, GL-117, Foobillard(plus), Blender 2.68 to name just a few.

Most function of OpenGL up to 1.5 are supported, with some notable exceptions:
 * Reading of Depth or Stencil buffer will not work
 * GL_FEEDBACK mode is not implemented
 
Some know limitations:
 * GL_SELECT as some limitation in its implementation (for exemple, current Depth buffer or binded texture are not taken into account)
 * NPOT texture are supported, but not with GL_REPEAT / GL_MIRRORED, only GL_CLAMP will work properly (unless the GLES Hardware support NPOT)
 * Framebuffer use FRAMEBUFFER_OES extension (that must be present in the GLES 1.1 stack)
 * Multiple Color attachment on Framebuffer are not supported
 * OcclusionQuery is implemented, but with a 0 bits precision
 * Probably many other things

Status of the GLES2 backend
 * This backend is at its early stage of development, but is now usable
 * The FPE (Fixed Pipeline Emulator) has most OpenGL 1.5 drawing call implemented
 * The Shader Conversion is really crude, so only simple shaders will work (especialy, the implicit conversion float <-> int is not handled)
 * Lighting support double-side and color separation using GLES2
 * FogCoord are supported, along with secondary color
 * An ES2 context should be usable (usefull for SDL2)
 * A few OpenGL 2.x games have been tested. To name a few: OpenRA, GZDoom, Danger from the Deep, SuperTuxKart 0.8.1, Hammerwatch, OpenMW...
 * glxgears works, but FlatShade is not implemented (and will probably never be), so it's slightly different then using GLES1.1 or actuel GL hardware
 * GL_TEXTURE_1D, GL_TEXTURE_3D and GL_TEXTURE_RECTANGLE_ARB are not yet supported in shaders (they are supported in fixed pipeline functions), and texture 3D are just 2D for now.
 * Program that link only a GL_FRAGMENT or GL_VERTEX shader are not supported yet.

----

Compiling
----
How to compile and per-platform specific comment can be found [here](COMPILE.md)

----

GLU
----

Standard GLU do works without any issues. You can find a version [here](https://github.com/ptitSeb/GLU) if you need one.

----

Installation
----

Put lib/libGL.so.1 in your `LD_LIBRARY_PATH`.
Beware that GL4ES is meant to replace any libGL you can have on your system (like Mesa for example)

----

Usage
----

There are many environnement variable to control gl4es behavour, also usable at runtime using `glHint(...)`.

See [here](USAGE.md) for all variables and what they do.

----

Version history
----

The change log is [here](CHANGELOG.md)
