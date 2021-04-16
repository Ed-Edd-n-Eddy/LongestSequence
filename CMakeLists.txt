cmake_minimum_required(VERSION 3.5.1)

## defines project's name and version
project(LongestSequence VERSION 1.0.0)

## set the C standard to 11
set(CMAKE_C_STANDARD 11)

## calls the child CMakeLists file from lib folder
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib)