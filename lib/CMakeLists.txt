cmake_minimum_required(VERSION 3.5.1)

## set var for build directory
set(BLD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)

## set var for the include directory
set(INCL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

## set var for the source directory
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

## check if the builld tool matches the needed and set warning levels for compilation
if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall
                        -Wextra
                        -Werror
                        -Wundef
                        -Wuninitialized
                        -Wshadow
                        -Wpointer-arith
                        -Wcast-align
                        -Wcast-qual
                        -Wunused-parameter
                        -Wlogical-op
                        -Wdouble-promotion
                        -Wduplicated-cond
                        -Wduplicated-branches
                        -Wnull-dereference)
endif()

## create the libarary with the project name and defines to be .so
add_library(${PROJECT_NAME}

            SHARED

            ${INCL_DIR}/traverser.h
            ${INCL_DIR}/pointsStack.h

            ${SRC_DIR}/traverser.c
            ${SRC_DIR}/pointsStack.c)

## message when launchin cmake to display info about the project
message(STATUS "Library: ${PROJECT_NAME} v${PROJECT_VERSION}")
