aux_source_directory(host HOST_SOURCES)
add_library(host SHARED ${HOST_SOURCES})
target_link_libraries(host ${GL_LIBRARY} asound)

add_library(host_static STATIC ${HOST_SOURCES})
set_target_properties(host_static PROPERTIES OUTPUT_NAME host)

aux_source_directory(client CLIENT_SOURCES)
add_library(client SHARED ${CLIENT_SOURCES})

set_target_properties(client PROPERTIES
    VERSION "2.0.0"
    SOVERSION "2"
)

if(CMAKE_SHARED_LIBRARY_SUFFIX MATCHES ".so")
    set_target_properties(client PROPERTIES SUFFIX ".so.1")
endif()
