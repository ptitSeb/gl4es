cmake_minimum_required(VERSION 2.6)

project(glesgl)
link_directories(${CMAKE_BINARY_DIR}/lib)
add_definitions(-g -std=c99 -funwind-tables)
set(CMAKE_OSX_ARCHITECTURES i386 CACHE STRING "do not build for 64-bit" FORCE)

include_directories(include)
add_subdirectory(src)

