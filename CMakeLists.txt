cmake_minimum_required(VERSION 3.10)

project(Reasons VERSION 0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

target_include_directories(reasons PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_executable(reasons
    src/main.cpp
    src/repl.cpp
)
