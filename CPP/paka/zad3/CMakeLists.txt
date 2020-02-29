cmake_minimum_required(VERSION 2.6)

project(bib)

include_directories(include)

add_compile_options(-Wall -g)

set(SOURCES Main.cpp Catalog.cpp Book.cpp Page.cpp)

add_executable(bib ${SOURCES})