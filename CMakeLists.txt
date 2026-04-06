# Versión mínima de CMake necesaria
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(newproject)

# C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Decirle a CMake qué archivo compilar
add_executable(mi_programa main.cpp)

# Enlazar Raylib y las dependencias necesarias
target_link_libraries(mi_programa PRIVATE 
    raylib 
    GL 
    m 
    pthread 
    dl 
    rt 
    X11
)