
cmake_minimum_required(VERSION 3.16)
project("Binary Tree Version 1.0.0")
set(CMAKE_CXX_STANDARD 17)   

set (CMAKE_CXX_FLAGS "")
#Bring the headers to into the project, i.e *.h *.hpp
include_directories(include ../linkedList/include ../tools)

add_executable(binaryTree.exe ./src/binaryTree.cpp ./src/binaryTreeUtil.cpp ../linkedList/src/linkedListUtil.cpp)




