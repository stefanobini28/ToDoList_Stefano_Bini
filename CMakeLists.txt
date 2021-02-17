cmake_minimum_required(VERSION 3.17)
project(ExampleTxtToList)

set(CMAKE_CXX_STANDARD 11)

add_executable(ExampleTxtToList main.cpp ToDoItem.h ToDoItem.cpp ToDoList.txt List.cpp List.h Date.h Date.cpp)
