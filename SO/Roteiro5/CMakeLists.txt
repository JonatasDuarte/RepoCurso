cmake_minimum_required(VERSION 3.19)
project(Roteiro5 C)

set(CMAKE_C_STANDARD 11)

add_executable(Roteiro5
        main.c)

file(COPY processList.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})