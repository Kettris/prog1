target_sources(QuickSort_sort_lib
	PRIVATE
		quick_sort.cpp
	PUBLIC
		quick_sort.hpp
)

target_include_directories(QuickSort_sort_lib PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)