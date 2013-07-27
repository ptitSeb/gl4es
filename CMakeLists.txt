cmake_minimum_required(VERSION 2.6)

project(glesgl)

# Raspberry PI
if(BCMHOST)
    include_directories(/opt/vc/include /opt/vc/include/interface/vcos/pthreads /opt/vc/include/interface/vmcs_host/linux)
endif()

link_directories(${CMAKE_BINARY_DIR}/lib)
add_definitions(-g -std=c99 -funwind-tables)

include_directories(include)
add_subdirectory(src)
