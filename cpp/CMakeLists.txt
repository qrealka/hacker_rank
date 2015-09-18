cmake_minimum_required(VERSION 3.3)
project(CppDomain)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(CppDomain ${SOURCE_FILES})
add_executable(VectorSort vectorSort.cpp)
add_executable(VectorErase VectorErase.cpp)
add_executable(LowerBound LowerBound.cpp)
add_executable(SetsStl SetsStl.cpp)
add_executable(MapsStl MapsStl.cpp)
add_executable(Inheritance Inheritance.cpp)
add_executable(MultiLevel MultiLevel.cpp)