cmake_minimum_required(VERSION 3.21)
project(omega LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(omega 
    src/main.cpp 
    # include/placeholder.hpp
)
target_include_directories(omega PRIVATE "include")
target_link_libraries(omega PRIVATE sfml-graphics)