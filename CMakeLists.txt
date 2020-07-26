cmake_minimum_required(VERSION 3.10)
project(Algorithms-and-Data-Structures)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

add_subdirectory(data_structures)
