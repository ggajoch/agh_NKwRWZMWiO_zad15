cmake_minimum_required(VERSION 3.1)
project(dfs1)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(dfs1 main.cpp ParseGraphFile.cpp ParseGraphFile.hpp structs.h)
