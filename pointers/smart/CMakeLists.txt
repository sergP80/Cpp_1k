project("smart-pointers-demo")

file(GLOB SRC src/*.cpp src/*.cxx)

file(GLOB TEST_SRC test/*.cpp test/*.cxx)

include_directories(include ${GTEST_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} ${COMMON_DEPS})

set(TEST_PROJECT_NAME ${PROJECT_NAME}_test)
add_executable(${TEST_PROJECT_NAME} ${TEST_SRC})
target_link_libraries(${TEST_PROJECT_NAME} ${COMMON_DEPS} ${GTEST_COMMON_DEPS})
add_test(NAME ${TEST_PROJECT_NAME} COMMAND ${TEST_PROJECT_NAME})