cmake_minimum_required(VERSION 3.3)
project(CppDomain)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(CppDomain ${SOURCE_FILES})
add_executable(VectorSort vectorSort.cpp)
add_executable(VectorErase VectorErase.cpp)