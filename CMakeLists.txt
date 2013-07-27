cmake_minimum_required(VERSION 2.6)

project(glesgl)
link_directories(${CMAKE_BINARY_DIR}/lib)
add_definitions(-g -std=c99 -funwind-tables)

include_directories(include)
add_subdirectory(src)
