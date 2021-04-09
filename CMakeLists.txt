cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 14)

project(Google_tests)

include_directories(${GTEST_INCLUDE_DIRS})
find_package(GTest REQUIRED)


set(CMAKE_CXX_FLAGS -pthread)
set(CMAKE_INCLUDE_PATH /usr/local/include)
set(SOURCE_FILES RunAllTests.cpp test1.cpp)
add_executable(Google_Tests ${SOURCE_FILES})
target_link_libraries(Google_Tests gtest gtest_main)
target_link_libraries(Google_Tests ${GTEST_BOTH_LIBRARIES} core)
