cmake_minimum_required(VERSION 3.24.1)

project(stacklist)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(DOWNLOAD_EXTRACT_TIMESTAMP 1)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(GLOB SOURCES "./*.cpp")
include_directories("./")
enable_testing()
add_executable(test_cmk ${SOURCES})
target_link_libraries(test_cmk GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_cmk)