include_directories(gl)
link_directories(lib)

aux_source_directory(gl GL_SOURCES)
add_library(GL SHARED ${GL_SOURCES})
target_link_libraries(GL GLES_CM)
target_link_libraries(GL EGL)
target_link_libraries(GL X11)

aux_source_directory(glu GLU_SOURCES)
add_library(GLU SHARED ${GLU_SOURCES})
target_link_libraries(GLU GLES_CM)

if(CMAKE_SHARED_LIBRARY_SUFFIX MATCHES ".so")
    set_target_properties(GL PROPERTIES SUFFIX ".so.1")
endif()

