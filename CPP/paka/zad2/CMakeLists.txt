
cmake_minimum_required(VERSION 2.6)
project(rtv)
include_directories(include)
add_compile_options(-Wall -g)
set(SOURCES Main.cpp Rzutnik.cpp Telewizor.cpp)
add_executable(rtv ${SOURCES})
