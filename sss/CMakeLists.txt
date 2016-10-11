cmake_minimum_required(VERSION 3.6)
project(sss)

set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES sss.c sss.h)
add_executable(ssss ${SOURCE_FILES})