include_directories(gl)
aux_source_directory(gl GL_SOURCES)

IF(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    include_directories(glx)
    aux_source_directory(glx GLX_SOURCES)
    list(APPEND GL_SOURCES ${GLX_SOURCES})
else()
    message(STATUS "Not on Linux: building without GLX support.")
endif()

add_library(GL SHARED ${GL_SOURCES})
target_link_libraries(GL GLES_CM)
target_link_libraries(GL EGL)

if(HAVE_X11)
    target_link_libraries(GL X11)
endif()

aux_source_directory(glu GLU_SOURCES)
add_library(GLU SHARED ${GLU_SOURCES})
target_link_libraries(GLU GLES_CM)

aux_source_directory(preload PRELOAD_SOURCES)
add_library(preload SHARED ${PRELOAD_SOURCES})

if(CMAKE_SHARED_LIBRARY_SUFFIX MATCHES ".so")
    set_target_properties(GL PROPERTIES SUFFIX ".so.1")
endif()

