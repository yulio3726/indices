cmake_minimum_required(VERSION 3.6)
project(permutations)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall-Werror")

set(SOURCE_FILES permutations.c permutations.h implementaciones.h)
add_executable(permutations ${SOURCE_FILES})