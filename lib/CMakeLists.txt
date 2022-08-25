cmake_minimum_required(VERSION 3.17)

project(
    scratch_lib
    VERSION 0.1.0
    LANGUAGES CXX
)

add_library(scratch_lib OBJECT)

file(GLOB HEADERS "include")
file(GLOB SOURCES "src/*.cpp")

target_include_directories(
    scratch_lib
    PRIVATE src/hello
    PUBLIC ${HEADERS}
)
target_sources(scratch_lib PRIVATE ${SOURCES})

target_compile_features(scratch_lib PUBLIC cxx_std_20)