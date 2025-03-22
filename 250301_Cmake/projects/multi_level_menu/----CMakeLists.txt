project(multi_level_menu)
add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/includes
)

add_library(menu_lib STATIC
    includes/menu_functions.cpp
    includes/menu_items.cpp
)

target_link_libraries(${PROJECT_NAME} menu_lib)