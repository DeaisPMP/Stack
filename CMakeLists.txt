cmake_minimum_required(VERSION 3.10)

project(graph_test)
set(CMAKE_CXX_STANDARD 20)
file(GLOB SOURCES "./*.cpp")
include_directories("./")
add_executable(test_cmk ${SOURCES})