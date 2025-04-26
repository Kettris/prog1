cmake_minimum_required(VERSION 3.2...3.27.5)

project(vector_list)

add_library(vector_list STATIC)

target_sources(vector_list
    PRIVATE
        src/vector.cpp
        src/doubly_linked_list.cpp
    PUBLIC
        src/vector.hpp
        src/doubly_linked_list.hpp
)

target_include_directories(vector_list PUBLIC
    "${PROJECT_SOURCE_DIR}/src"
)

enable_testing()
