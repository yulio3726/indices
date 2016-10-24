cmake_minimum_required(VERSION 3.6)
project(miFile)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

set(SOURCE_FILES miFile.c miFile.h funcionesImplementadas.h)
add_executable(miFile ${SOURCE_FILES})