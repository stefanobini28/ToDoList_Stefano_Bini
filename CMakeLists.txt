cmake_minimum_required(VERSION 3.17)
project(ExampleTxtToList)

set(CMAKE_CXX_STANDARD 11)

add_executable(ExampleTxtToList main.cpp List.h List.cpp ToDoList.txt)