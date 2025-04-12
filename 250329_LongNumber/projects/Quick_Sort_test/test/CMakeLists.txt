set(SOURCES 
	test_QuickSort.cpp
)

add_executable(test_QuickSort ${SOURCES})
target_link_libraries(test_QuickSort
	gtest_main
	gmock_main
	QuickSort_sort_lib
)

add_test(test_QuickSort test_QuickSort)