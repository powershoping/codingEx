
cmake_minimum_required(VERSION 3.16)
project("Heap Version 1.0.0")
set(CMAKE_CXX_STANDARD 11)   

set (CMAKE_CXX_FLAGS "")
#Bring the headers to into the project, i.e *.h *.hpp
include_directories(include)

add_executable(heap.exe ./src/heap.cpp)




