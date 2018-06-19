cmake_minimum_required(VERSION 3.10)
project(dfs1)

set(CMAKE_CXX_STANDARD 14)

add_executable(dfs1 main.cpp ParseGraphFile.cpp ParseGraphFile.hpp structs.h)