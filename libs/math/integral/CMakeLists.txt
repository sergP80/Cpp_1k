﻿project("integral")

file(GLOB_RECURSE SRC LIST_DIRECTORIES true *.cpp *.cxx)

include_directories(include)

add_library(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} ${COMMON_LIB_DEPS})

target_include_directories(
        ${PROJECT_NAME}
        PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)