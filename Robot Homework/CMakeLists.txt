cmake_minimum_required(VERSION 4.1)
project(rover C)

set(CMAKE_C_STANDARD 11)

add_executable(rover main.c
        rover.c
        rover.h)
