set(wxBUILD_SHARED ON)

message(STATUS "Fetching wxWidgets...")

FetchContent_Declare(
        wxWidgets
        GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
        GIT_SHALLOW ON
        GIT_TAG        v3.2.5
)
FetchContent_MakeAvailable(wxWidgets)

set(wxWidgets_INCLUDE ${wxWidgets_SOURCE_DIR}/include)
set(wxWidgets_USE_LIBS core base net stc)
#
#find_package(wxWidgets REQUIRED COMPONENTS ${wxWidgets_USE_LIBS})

add_subdirectory("wx-widgets")
