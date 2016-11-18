cmake_minimum_required(VERSION 2.6)

project(glshim)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

option(PANDORA "Set to ON if targeting an OpenPandora device" ${PANDORA})
option(BCMHOST "Set to ON if targeting an RPi(2) device" ${BCMHOST})
option(ODROID "Set to ON if targeting an ODroid device" ${ODROID})
option(CHIP "Set to ON if targeting an C.H.I.P. device" ${CHIP})

option(USE_DRAWTEX "Set to ON to use the glDrawTexiOES extension" ${USE_DRAWTEX})

# Raspberry PI
if(BCMHOST)
    include_directories(/opt/vc/include /opt/vc/include/interface/vcos/pthreads /opt/vc/include/interface/vmcs_host/linux)
    link_directories(/opt/vc/lib)
    add_definitions(-DBCMHOST)
endif()

if(PANDORA)
    add_definitions(-DPANDORA)
    add_definitions(-DTEXSTREAM)
    add_definitions(-mcpu=cortex-a8 -mfpu=neon -mfloat-abi=softfp -ftree-vectorize -fsingle-precision-constant -ffast-math)
endif()

if(ODROID)
    add_definitions(-DODROID)
endif()

if(CHIP)
    add_definitions(-DCHIP)
    add_definitions(-mcpu=cortex-a8 -mfpu=neon -mfloat-abi=hard -ftree-vectorize -fsingle-precision-constant -ffast-math)
endif()

if(USE_DRAWTEX)
    add_definitions(-DUSE_DRAWTEX)
endif()

link_directories(${CMAKE_BINARY_DIR}/lib)
add_definitions(-g -std=gnu99 -funwind-tables -O3 -fvisibility=hidden)

include_directories(include)
add_subdirectory(src)
