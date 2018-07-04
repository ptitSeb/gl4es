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
option(AMIGAOS4 "Set to ON if targeting an AmigaOS4/Warp3D platform (activate NOEGL and NOX11)" ${AMIGAOS4})
option(NOX11 "Set to ON to not use X11 (creation of context has to be done outside gl4es)" ${NOX11})
option(NOEGL "Set to ON to not use EGL (all functions are taken in GLES library)" ${NOEGL})
option(STATICLIB "Set to ON to build a static version of gl4es" ${STATICLIB})

# Raspberry PI
if(BCMHOST)
    include_directories(/opt/vc/include /opt/vc/include/interface/vcos/pthreads /opt/vc/include/interface/vmcs_host/linux)
    link_directories(/opt/vc/lib)
    add_definitions(-DBCMHOST)
endif()

# Pandora
if(PANDORA)
    add_definitions(-DPANDORA)
    add_definitions(-DTEXSTREAM)
    add_definitions(-mcpu=cortex-a8 -mfpu=neon -mfloat-abi=softfp -ftree-vectorize -fsingle-precision-constant -ffast-math)
endif()

# ODROID
if(ODROID)
    add_definitions(-DODROID)
endif()

#PocketCHIP
if(CHIP)
    add_definitions(-DCHIP)
    add_definitions(-mcpu=cortex-a8 -mfpu=neon -mfloat-abi=hard -ftree-vectorize -fsingle-precision-constant -ffast-math)
endif()

# AmigaOS4
if(AMIGAOS4)
    set(CMAKE_C_COMPILER "ppc-amigaos-gcc")
    set(CMAKE_CXX_COMPILER "ppc-amigaos-g++")
    set(CMAKE_LINKER "ppc-amigaos-ld")
    set(CMAKE_AR "ppc-amigaos-ar")
    set(CMAKE_RANLIB "ppc-amigaos-ranlib")
    add_definitions(-DAMIGAOS4)
    set(NOX11 ON)
    set(NOEGL ON)
endif()

#NOX11
if(NOX11)
	add_definitions(-DNOX11)
endif()

#NOEGL
if(NOEGL)
    add_definitions(-DNOEGL)
    add_definitions(-DNOX11)
endif()

#DEFAULT_ES=2
if("${DEFAULT_ES}" STREQUAL "2")
    add_definitions(-DDEFAULT_ES=2)
endif()

link_directories(${CMAKE_BINARY_DIR}/lib)
add_definitions(-g -std=gnu99 -funwind-tables -O3 -fvisibility=hidden)

include_directories(include)
add_subdirectory(src)
