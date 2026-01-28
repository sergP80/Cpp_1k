project("simple-compute")

file(GLOB SRC src/*.cpp src/*.cxx)

include_directories(include)

add_executable(${PROJECT_NAME} ${SRC}
        include/calculator.hpp
        src/calculator.cpp)

target_link_libraries(${PROJECT_NAME} ${COMMON_DEPS})