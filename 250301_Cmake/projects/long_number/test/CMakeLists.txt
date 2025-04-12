set(SOURCES 
    test_long_number.cpp
)

add_executable(test_long_number ${SOURCES})
target_link_libraries(test_long_number
    long_number
    gtest_main
)
add_test(NAME test_long_number COMMAND test_long_number)

add_executable(ibusko_test_long_number ibusko_test_long_number.cpp)
target_link_libraries(ibusko_test_long_number
    long_number
    gtest_main
)
add_test(NAME ibusko_test_long_number COMMAND ibusko_test_long_number)