aux_source_directory(. CLIENT_SOURCES)
add_library(client SHARED ${CLIENT_SOURCES})

set_target_properties(client PROPERTIES
    VERSION "2.0.0"
    SOVERSION "2"
)
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-version-script=Versions")

if(CMAKE_SHARED_LIBRARY_SUFFIX MATCHES ".so")
    set_target_properties(client PROPERTIES SUFFIX ".so.1")
endif()
