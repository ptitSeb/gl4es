GL4ES - OpenGL for GLES Hardware
====

Many OpenGL software already works with GL4ES.

![foobillards++](refs/foobillardplus.0000014748.png)

Complex OpenGL 1.5 games, like Foobillard++, that uses cascaded display list, line stipple, TexGen, works fine. Here running on the OpenPandora. It will work with both GLES1.1 and GLES2.0 backend. Most OpenGL 1.x games will runs. 


[![Play on Youtube](https://img.youtube.com/vi/75FYb60L7zw/0.jpg)](https://www.youtube.com/watch?v=75FYb60L7zw)

The limit is an hardware one: GLES1.1 and GLES2.0 hardware do not allow reading Depth buffer, so some games that use it (like AssultCube) for game play wont run. Some FPS are using it just for cosmetics (Lens flare), the they still run fine without, Like Serious Sam (both First and Second Encouter), here on the OpenPandora again.


[![Play on Youtube](https://img.youtube.com/vi/kJPb2jYiBoM/0.jpg)](https://www.youtube.com/watch?v=kJPb2jYiBoM)

More complex program, like Blender, can also run.


![MineCraft](media/minecraft.png)

But also Minecraft, here on an ODroid in this old video.


![OpenRA](refs/openra.0000031249.png)

On the OpenGL 2.0, side using GLES2.0 backend, OpenRA can run on the Pandora.


And OpenGL 2.x opens a lot of dors. Many commercial games run just fine on gl4es.

[![Play on Youtube](https://img.youtube.com/vi/VUoeHWuwlMU/0.jpg)](https://www.youtube.com/watch?v=VUoeHWuwlMU)

Here some FNA games, running on an ODroid XU4 (using method described [there](https://magazine.odroid.com/article/playing-modern-fna-games-on-the-odroid-platform/)). That video show just a few, and even more can be make to run.



[![Play on Youtube](https://img.youtube.com/vi/B4YN37z3-ws/0.jpg)](https://www.youtube.com/watch?v=B4YN37z3-ws)

And with [Box86](https://github.com/ptitSeb/box86), even more commercial games can run, like here NeverWinter Night on an ODroid XU4
