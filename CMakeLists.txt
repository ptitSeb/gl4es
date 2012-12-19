cmake_minimum_required(VERSION 2.6)

project(glesgl)
add_definitions(-std=c99)
set(CMAKE_OSX_ARCHITECTURES i386 CACHE STRING "do not build for 64-bit" FORCE)

include_directories(src include)
link_directories(lib)

AUX_SOURCE_DIRECTORY(src GL_SOURCES)

add_library(GL SHARED ${GL_SOURCES})
target_link_libraries(GL GLES_CM)
target_link_libraries(GL EGL)
target_link_libraries(GL X11)

