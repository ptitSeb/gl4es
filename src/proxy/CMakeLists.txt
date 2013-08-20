aux_source_directory(host HOST_SOURCES)
add_library(glhost SHARED ${HOST_SOURCES})
target_link_libraries(glhost ${GL_LIBRARY})

aux_source_directory(client CLIENT_SOURCES)
add_library(GLc SHARED ${CLIENT_SOURCES})

if(CMAKE_SHARED_LIBRARY_SUFFIX MATCHES ".so")
    set_target_properties(GLc PROPERTIES SUFFIX ".so.1")
endif()
