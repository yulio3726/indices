cmake_minimum_required(VERSION 3.5)
project(rbbf1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(SOURCE_FILES rbbf1.c rbbf1.h)
add_executable(rbbf1 ${SOURCE_FILES})