cmake_minimum_required(VERSION 3.3)
project(Algo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Algo ${SOURCE_FILES})
add_executable(PlusMinus PlusMinus.cpp)
add_executable(FunnyStrings FunnyStrings.cpp)
add_executable(BiggerGreater BiggerGreater.cpp)
add_executable(SortIntro SortIntro.cpp)
add_executable(InsertionOne InsertionOne.cpp)
add_executable(InsertionTwo InsertionTwo.cpp)