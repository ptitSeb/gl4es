file(GLOB_RECURSE GL_SOURCES gl/*.c)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    include_directories(glx)
    aux_source_directory(glx GLX_SOURCES)
    list(APPEND GL_SOURCES ${GLX_SOURCES})
else()
    message(STATUS "Not on Linux: building without GLX support.")
endif()

add_library(GL SHARED ${GL_SOURCES})
target_link_libraries(GL EGL)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    target_link_libraries(GL X11)
endif()

aux_source_directory(glu GLU_SOURCES)
add_library(GLU SHARED ${GLU_SOURCES})
target_link_libraries(GLU GLES_CM)

aux_source_directory(preload PRELOAD_SOURCES)
add_library(preload SHARED ${PRELOAD_SOURCES})
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    target_link_libraries(preload X11)
endif()

if(CMAKE_SHARED_LIBRARY_SUFFIX MATCHES ".so")
    set_target_properties(GL PROPERTIES SUFFIX ".so.1")
endif()

aux_source_directory(proxy PROXY_SOURCES)
add_library(proxy SHARED ${PROXY_SOURCES})

aux_source_directory(tests TEST_SOURCES)
add_executable(test ${TEST_SOURCES})
target_link_libraries(test proxy)

