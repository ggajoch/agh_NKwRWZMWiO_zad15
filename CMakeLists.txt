cmake_minimum_required(VERSION 3.1)
project(dfs1)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(dfs1 main.cpp parse_task_file.cpp parse_task_file.hpp argument_parser.cpp argument_parser.hpp structs.h)
