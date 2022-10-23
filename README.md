# Project: Omega

Project: Omega is the codename for my C++ assignment for Saxion. It's a very simple Final Fantasy-esque 
bossfight made using SFML.

## Build Requirements

To build the project yourself, you will need the following tools:

    - CMake
    - Ninja
    - GCC

## Build

Use the following 2 commands to build the project:
```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -G "Ninja"
ninja -C build
```
