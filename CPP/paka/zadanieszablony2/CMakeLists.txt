cmake_minimum_required(VERSION 2.6)
project(vector)
include_directories(include)
add_compile_options(-Wall -g)
set(SOURCES main.cpp)
add_executable(vector ${SOURCES})