cmake_minimum_required(VERSION 3.6)
project(how_to C)

set(CMAKE_C_STANDARD 99)

include_directories(.)

add_executable(how_to
        open_read_file.c
        structs.h)
