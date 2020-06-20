include_directories(util)

#file(GLOB_RECURSE GL_SOURCES gl/*.c)
SET(GL_SRC
    gl/arbconverter.c
	gl/arbgenerator.c
	gl/arbhelper.c
	gl/arbparser.c
    gl/array.c
    gl/blit.c
    gl/blend.c
    gl/buffers.c
    gl/build_info.c
    gl/debug.c
    gl/decompress.c
    gl/depth.c
    gl/directstate.c
    gl/drawing.c
    gl/enable.c
    gl/envvars.c
    gl/eval.c
    gl/face.c
    gl/fog.c
    gl/fpe.c
    gl/fpe_cache.c
    gl/fpe_shader.c
    gl/framebuffers.c
    gl/gl_lookup.c
    gl/getter.c
    gl/gl4es.c
    gl/glstate.c
    gl/hint.c
    gl/init.c
    gl/light.c
    gl/line.c
    gl/list.c
    gl/listdraw.c
    gl/listrl.c
    gl/loader.c
    gl/logs.c
    gl/matrix.c
    gl/matvec.c
    gl/oldprogram.c
    gl/pixel.c
    gl/planes.c
    gl/pointsprite.c
    gl/preproc.c
    gl/program.c
    gl/queries.c
    gl/raster.c
    gl/render.c
    gl/shader.c
    gl/shaderconv.c
    gl/shader_hacks.c
    gl/stack.c
    gl/stencil.c
    gl/string_utils.c
    gl/stubs.c
    gl/texenv.c
    gl/texgen.c
    gl/texture.c
    gl/texture_compressed.c
    gl/texture_params.c
    gl/texture_read.c
    gl/texture_3d.c
    gl/uniform.c
    gl/vertexattrib.c
	gl/wrap/gl4eswraps.c
	gl/wrap/gles.c
	gl/wrap/glstub.c
	gl/math/matheval.c
)

SET(GL_H
    ../version.h
    gl/arbconverter.h
	gl/arbgenerator.h
	gl/arbhelper.h
	gl/arbparser.h
    gl/array.h
    gl/blend.h
    gl/blit.h
    gl/buffers.h
	gl/build_info.h
    gl/const.h
    gl/debug.h
    gl/decompress.h
    gl/defines.h
    gl/depth.h
    gl/directstate.h
    gl/envvars.h
    gl/eval.h
    gl/face.h
    gl/fog.h
    gl/fpe.h
    gl/fpe_shader.h
    gl/framebuffers.h
    gl/gl_lookup.h
    gl/gles.h
    gl/gl4es.h
    gl/glstate.h
    gl/hint.h
    gl/init.h
    gl/light.h
    gl/line.h
    gl/list.h
    gl/loader.h
    gl/logs.h
    gl/matrix.h
    gl/matvec.h
    gl/oldprogram.h
    gl/pixel.h
    gl/planes.h
    gl/pointsprite.h
    gl/preproc.h
    gl/program.h
    gl/queries.h
    gl/raster.h
    gl/render.h
    gl/shader.h
    gl/shaderconv.h
    gl/shader_hacks.h
    gl/stack.h
    gl/state.h
    gl/stencil.h
    gl/stb_dxt_104.h
    gl/string_utils.h
    gl/texenv.h
    gl/texgen.h
    gl/uniform.h
    gl/texture.h
    gl/vertexattrib.h
    gl/math/eval.h
    gl/wrap/gl4es.h
    gl/wrap/gles.h
    gl/wrap/stub.h
)

set_source_files_properties(gl/build_info.c PROPERTIES OBJECT_OUTPUTS "dummy.c")

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux" AND NOT NO_LOADER)
    include_directories(glx)
#    aux_source_directory(glx GLX_SOURCES)
#    list(APPEND GL_SOURCES ${GLX_SOURCES})
    list(APPEND GL_SRC
        glx/hardext.c
        glx/gbm.c
	    glx/glx.c
	    glx/lookup.c
        glx/rpi.c
	    glx/streaming.c
        glx/utils.c
    )
    list(APPEND GL_H
        glx/glx_gbm.h
        glx/gbmfunc.h
        glx/drmfunc.h
        glx/glx.h
        glx/hardext.h
        glx/rpi.h
        glx/streaming.h
        glx/utils.h
    )
else()
    include_directories(glx)
    list(APPEND GL_SRC
        glx/hardext.c
    )
    message(STATUS "Not on Linux: building without GLX support.")
endif()

if(AMIGAOS4)
    include_directories(agl)
    list(APPEND GL_SRC
        glx/gbm.c
        glx/glx.c
        agl/lookup.c
        agl/amigaos.c
        agl/agl.c
    )
    list(APPEND GL_H
        glx/hardext.h
        glx/glx.h
        agl/amigaos.h
        agl/agl.h
    )
endif()

if(STATICLIB)
add_library(GL STATIC ${GL_SRC})
else()
    add_library(GL SHARED ${GL_SRC})
    
    if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
        if(NOX11)
            if(AMIGAOS4)
                target_link_libraries(GL m)
            else()
                target_link_libraries(GL m dl)
            endif()
        else()
            target_link_libraries(GL X11 m dl)
        endif()
    endif()
    if(USE_CLOCK)
        target_link_libraries(GL rt)
    endif()
    
    if(CMAKE_SHARED_LIBRARY_SUFFIX MATCHES ".so")
        set_target_properties(GL PROPERTIES SUFFIX ".so.1")
    endif()
    install(TARGETS GL
    LIBRARY
      DESTINATION "/usr/lib/gl4es/"
    )
  install(FILES "../include/gl4esinit.h" "../include/gl4eshint.h"
    DESTINATION "/usr/include/gl4es/"
    )
  endif()

