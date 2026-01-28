project("wx-widget-app")

file(GLOB SRC src/*.cpp src/*.cxx)

include_directories(${wxWidgets_INCLUDE} include)

add_executable(${PROJECT_NAME} ${SRC})

target_include_directories(${PROJECT_NAME} PRIVATE ${wxWidgets_INCLUDE})
target_link_libraries(${PROJECT_NAME} ${COMMON_DEPS} ${wxWidgets_USE_LIBS})