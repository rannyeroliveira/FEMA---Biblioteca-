cmake_minimum_required(VERSION 3.30)
project(FEMA___Biblioteca_)


set(CMAKE_CXX_STANDARD 14)

add_executable(FEMA___Biblioteca_
    BIBLIOTECA.cpp)

add_executable(AutorService service/AutorService.h)