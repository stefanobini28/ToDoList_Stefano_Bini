cmake_minimum_required(VERSION 3.17)
project(ExampleTxtToMap___Backup)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib)

set(SOURCE_FILES ToDoItem.h ToDoItem.cpp ToDoList.txt ToDoList.cpp ToDoList.h Date.h Date.cpp)
set(LIBRARIES gtest pthread)
add_library(core ${SOURCE_FILES})

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(ExampleTxtToMap___Backup main.cpp)
target_link_libraries(ExampleTxtToMap___Backup ${CURSES_LIBRARIES})
target_link_libraries(ExampleTxtToMap___Backup gtest)
target_link_libraries(ExampleTxtToMap___Backup core)
