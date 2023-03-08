
cmake_minimum_required(VERSION 3.16)
project("Binary Search Tree Version 1.0.0")
set(CMAKE_CXX_STANDARD 17)   

set (CMAKE_CXX_FLAGS "")
#Bring the headers to into the project, i.e *.h *.hpp
include_directories(include)

add_executable(linkedList.exe ./src/linkedList.cpp ./src/linkedListUtil.cpp)




