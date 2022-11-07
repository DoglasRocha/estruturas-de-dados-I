cmake_minimum_required(VERSION 3.23)
project(trabalho_strings)

set(CMAKE_CXX_STANDARD 14)

add_executable(trabalho_strings main.cpp includes/ocorrencia.hpp src/ocorrencias.cpp includes/system.hpp src/system.cpp includes/sorts.hpp src/sorts.cpp)
