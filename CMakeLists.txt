﻿# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Cpp_1k")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../dist/lib/${CMAKE_SYSTEM_NAME}/${CMAKE_SYSTEM_PROCESSOR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../dist/lib/${CMAKE_SYSTEM_NAME}/${CMAKE_SYSTEM_PROCESSOR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../dist/bin/${CMAKE_SYSTEM_NAME}/${CMAKE_SYSTEM_PROCESSOR}")

if (CMAKE_COMPILER_IS_GNUCXX)
 add_definitions (-Wall -pedantic)
endif()

if(MSVC)
 add_definitions (/W4)
endif()

# Include sub-projects.
add_subdirectory ("libs")
add_subdirectory ("integral_app")
add_subdirectory ("book_phone")
add_subdirectory ("decanat")