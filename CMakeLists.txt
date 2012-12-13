cmake_minimum_required(VERSION 2.6)
project(glesgl)
add_definitions(-std=c99 -arch i386)
include_directories(src include)
add_library(GL SHARED src/glesgl.c)

