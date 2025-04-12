add_library(includes
  menu.hpp
  menu_functions.cpp
  menu_functions.hpp
  menu_items.cpp
  menu_items.hpp
)

target_include_directories(includes
  PUBLIC
  "${CMAKE_CURRENT_SOURCE_DIR}"
)