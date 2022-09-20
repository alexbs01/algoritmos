cmake_minimum_required(VERSION 3.23)
project(fibonacci C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(fibonacci
        funcionesFibonacci.c
        funcionesFibonacci.h
        main.c)

target_link_libraries(fibonacci -lm)