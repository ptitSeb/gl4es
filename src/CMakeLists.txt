include_directories(util)

#file(GLOB_RECURSE GL_SOURCES gl/*.c)
SET(GL_SRC
    gl/array.c
    gl/blit.c
    gl/blend.c
    gl/buffers.c
    gl/debug.c
    gl/decompress.c
    gl/directstate.c
    gl/eval.c
    gl/fog.c
    gl/fpe.c
    gl/fpe_shader.c
    gl/framebuffers.c
    gl/getter.c
    gl/gl.c
    gl/hint.c
    gl/init.c
    gl/light.c
    gl/line.c
    gl/list.c
    gl/loader.c
    gl/matrix.c
    gl/matvec.c
    gl/pixel.c
    gl/planes.c
    gl/pointsprite.c
    gl/program.c
    gl/queries.c
    gl/raster.c
    gl/render.c
    gl/shader.c
    gl/shaderconv.c
    gl/stack.c
    gl/string_utils.c
    gl/texenv.c
    gl/texgen.c
    gl/texture.c
    gl/uniform.c
    gl/vertexattrib.c
	gl/wrap/gl.c
	gl/wrap/gles.c
	gl/wrap/glstub.c
	gl/math/eval.c
)

SET(GL_H
    ../version.h
    gl/array.h
    gl/blend.h
    gl/blit.h
    gl/buffers.h
    gl/const.h
    gl/debug.h
    gl/decompress.h
    gl/defines.h
    gl/directstate.h
    gl/eval.h
    gl/fog.h
    gl/fpe.h
    gl/fpe_shader.h
    gl/framebuffers.h
    gl/gles.h
    gl/gl.h
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
    gl/pixel.h
    gl/planes.h
    gl/pointsprite.h
    gl/program.h
    gl/queries.h
    gl/raster.h
    gl/render.h
    gl/shader.h
    gl/shaderconv.h
    gl/stack.h
    gl/state.h
    gl/stb_dxt_104.h
    gl/string_utils.h
    gl/texenv.h
    gl/texgen.h
    gl/uniform.h
    gl/texture.h
    gl/vertexattrib.h
    gl/math/eval.h
    gl/wrap/gles.h
    gl/wrap/gl.h
    gl/wrap/stub.h
)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    include_directories(glx)
#    aux_source_directory(glx GLX_SOURCES)
#    list(APPEND GL_SOURCES ${GLX_SOURCES})
    list(APPEND GL_SRC
	    glx/hardext.c
	    glx/glx.c
	    glx/lookup.c
        glx/rpi.c
	    glx/streaming.c
        glx/utils.c
    )
    list(APPEND GL_H
        glx/glx.h
        glx/hardext.h
        glx/rpi.h
        glx/streaming.h
        glx/utils.h
    )
else()
    message(STATUS "Not on Linux: building without GLX support.")
endif()

if(AMIGAOS4)
    include_directories(agl)
    list(APPEND GL_SRC
        agl/amigaos.c
        agl/agl.c
    )
    list(APPEND GL_H
        agl/amigaos.h
        agl/agl.h
    )
endif()

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

if(CMAKE_SHARED_LIBRARY_SUFFIX MATCHES ".so")
    set_target_properties(GL PROPERTIES SUFFIX ".so.1")
endif()
