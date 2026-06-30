cmake_minimum_required(VERSION 3.16)
project(Transformations)

set(CMAKE_CXX_STANDARD 17)

find_package(Python3 COMPONENTS Development REQUIRED)
find_package(pybind11 REQUIRED)

pybind11_add_module(Transformations Transformations.cpp)
target_compile_options(Transformations PRIVATE -march=native)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
