aux_source_directory(host HOST_SOURCES)
add_library(host SHARED ${HOST_SOURCES})
target_link_libraries(host ${GL_LIBRARY} asound)

add_library(host_static STATIC ${HOST_SOURCES})
set_target_properties(host_static PROPERTIES OUTPUT_NAME host)

add_subdirectory(client)
