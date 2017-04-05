include_directories(util)

#file(GLOB_RECURSE GL_SOURCES gl/*.c)
SET(GL_SRC
    gl/array.c
    gl/blend.c
    gl/buffers.c
    gl/debug.c
    gl/decompress.c
    gl/directstate.c
    gl/eval.c
    gl/fog.c
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
    gl/queries.c
    gl/raster.c
    gl/render.c
    gl/stack.c
    gl/texgen.c
    gl/texture.c
	gl/wrap/gl.c
	gl/wrap/gles.c
	gl/wrap/glstub.c
	gl/math/eval.c
)

SET(GL_H
    ../version.h
    gl/array.h
    gl/blend.h
    gl/buffers.h
    gl/const.h
    gl/debug.h
    gl/decompress.h
    gl/defines.h
    gl/directstate.h
    gl/fog.h
    gl/eval.h
    gl/framebuffers.h
    gl/gles.h
    gl/gl.h
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
    gl/queries.h
    gl/raster.h
    gl/render.h
    gl/stack.h
    gl/state.h
    gl/stb_dxt_104.h
    gl/texgen.h
    gl/texture.h
    gl/math/eval.h
    gl/wrap/es.h
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

add_library(GL SHARED ${GL_SRC})

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    target_link_libraries(GL X11 m dl)
endif()

if(CMAKE_SHARED_LIBRARY_SUFFIX MATCHES ".so")
    set_target_properties(GL PROPERTIES SUFFIX ".so.1")
endif()
