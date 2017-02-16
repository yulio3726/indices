cmake_minimum_required(VERSION 3.6)
project(sbep2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall-Werror")

set(SOURCE_FILES sbep2.c sbep2.h implementaciones.h)
add_executable(sbep2 ${SOURCE_FILES})