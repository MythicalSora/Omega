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
    src/gameObject.cpp
    src/scene.cpp
    src/sceneHandler.cpp
    src/spriteObject.cpp
    # include/placeholder.hpp
)
target_include_directories(omega PRIVATE "include")
target_include_directories(omega PRIVATE "assets")
target_link_libraries(omega PRIVATE sfml-graphics)

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET omega POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:omega> $<TARGET_FILE_DIR:omega> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS omega)