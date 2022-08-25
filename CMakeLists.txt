cmake_minimum_required(VERSION 3.17)

project(
    scratchpad
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CXX_STANDARD 20)

add_subdirectory(lib)
add_executable(scratchpad)
target_sources(scratchpad PRIVATE main.cpp)
target_link_libraries(scratchpad PRIVATE scratch_lib)
