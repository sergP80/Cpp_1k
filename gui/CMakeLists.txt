project("gui")

#FLTK fetch

FetchContent_Declare(
        fltk
        GIT_REPOSITORY https://github.com/fltk/fltk.git
        GIT_TAG release-1.3.9
)

FetchContent_MakeAvailable(fltk)

list(APPEND FLTK_INCLUDE ${fltk_SOURCE_DIR} ${fltk_BINARY_DIR})

include_directories(${FLTK_INCLUDE})

list(APPEND COMMON_FLTK_DEPS fltk fltk_forms)

add_subdirectory("simple_fltk")