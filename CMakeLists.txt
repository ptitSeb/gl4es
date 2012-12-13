cmake_minimum_required(VERSION 2.6)

project(glesgl)
add_definitions(-std=c99)
set(CMAKE_OSX_ARCHITECTURES i386 CACHE STRING "do not build for 64-bit" FORCE)

include_directories(src include)
link_directories(lib)

add_library(GL SHARED src/glesgl.c)
target_link_libraries(GL GLES_CM)

