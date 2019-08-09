cmake_minimum_required(VERSION 3.14)
project(rando)

set(CMAKE_CXX_STANDARD 11)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif (NOT CMAKE_BUILD_TYPE)

set(TARGET_NAME random_string)
add_executable(${TARGET_NAME} random_string.cpp)
target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -pedantic)
