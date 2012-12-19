cmake_minimum_required(VERSION 2.6)

project(glesgl)
add_definitions(-std=c99)
set(CMAKE_OSX_ARCHITECTURES i386 CACHE STRING "do not build for 64-bit" FORCE)

include_directories(include)
link_directories(lib)
add_subdirectory(src)

