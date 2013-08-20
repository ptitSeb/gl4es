aux_source_directory(host HOST_SOURCES)
add_library(glhost SHARED ${HOST_SOURCES})
target_link_libraries(glhost ${GL_LIBRARY} dl)

add_library(glhost_static STATIC ${HOST_SOURCES})
set_target_properties(glhost_static PROPERTIES OUTPUT_NAME glhost)

aux_source_directory(client CLIENT_SOURCES)
add_library(GLc SHARED ${CLIENT_SOURCES})

if(CMAKE_SHARED_LIBRARY_SUFFIX MATCHES ".so")
    set_target_properties(GLc PROPERTIES SUFFIX ".so.1")
endif()
