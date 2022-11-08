cmake_minimum_required(VERSION 3.23)
project(trabalho_strings)

set(CMAKE_CXX_STANDARD 14)

file (GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(trabalho_strings main.cpp ${SOURCES})
