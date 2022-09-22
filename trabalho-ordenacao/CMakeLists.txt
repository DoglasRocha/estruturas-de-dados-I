cmake_minimum_required(VERSION 3.23)
project(trabalho_ordenacao)

set(CMAKE_CXX_STANDARD 14)
include_directories(${PROJECT_SOURCE_DIR}/includes)
include_directories(${PROJECT_SOURCE_DIR}/common/includes)
include_directories(${PROJECT_SOURCE_DIR}/sequencial-list/includes)

file(GLOB SRC "${PROJECT_SOURCE_DIR}/src/*.cpp")
file(GLOB COMMON_SRC "${PROJECT_SOURCE_DIR}/common/src/*.cpp")

add_executable(trabalho_ordenacao main.cpp ${SRC} ${COMMON_SRC})
