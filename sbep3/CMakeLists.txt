cmake_minimum_required(VERSION 3.6)
project(sbep3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall-Werror")

set(SOURCE_FILES sbep3.c sbep3.h implementaciones.h)
add_executable(sbep3 ${SOURCE_FILES})