cmake_minimum_required(VERSION 3.2...3.27.5)

project(250301_Cmake)

enable_testing()

add_subdirectory(lib/googletest)
add_subdirectory(Quick_Sort_test)
add_subdirectory(multi_level_menu)
add_subdirectory(long_number)
add_subdirectory(vector_list)

set(CMAKE_SUPPRESS_REGENERATION TRUE)

