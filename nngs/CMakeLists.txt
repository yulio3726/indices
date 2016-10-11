cmake_minimum_required(VERSION 3.6)
project(nngs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")

set(SOURCE_FILES nngs.c nngs.h)
add_executable(swe ${SOURCE_FILES})