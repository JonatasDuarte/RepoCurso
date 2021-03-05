cmake_minimum_required(VERSION 3.17)
project(prod_cons C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")

add_executable(prod_cons main.c)