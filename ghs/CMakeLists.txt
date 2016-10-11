cmake_minimum_required(VERSION 3.6)
project(ghs)

set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES ghs.c ghs.h)
add_executable(ghs ${SOURCE_FILES})