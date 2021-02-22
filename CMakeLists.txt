cmake_minimum_required(VERSION 3.17)
project(ExampleTxtToMap)

set(CMAKE_CXX_STANDARD 14)

add_executable(ExampleTxtToMap main.cpp ToDoItem.h ToDoItem.cpp ToDoList.txt Map.cpp Map.h Date.h Date.cpp)
