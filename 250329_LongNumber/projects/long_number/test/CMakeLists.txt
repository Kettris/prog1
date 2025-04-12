set(SOURCES 
	test_long_number.cpp
)

add_executable(test_long_number ${SOURCES})
target_link_libraries(test_long_number
	gtest_main
	gmock_main
	long_number
)

add_test(test_long_number test_long_number)



//add_executable(test_long_number test_long_number.cpp)
//target_link_libraries(test_long_number long_number gtest gtest_main)
//gtest_discover_tests(test_long_number)
