cmake_minimum_required(VERSION 3.12)

project(boost-static LANGUAGES CXX)

set(Boost_VERBOSE ON)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS regex)

# --- flags ---
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

add_compile_options(
    -Wall
    -Wextra
    -Werror
    -Wno-error=deprecated-declarations
    -Wno-error=unused-parameter
)

include(CTest)
add_subdirectory(src)
