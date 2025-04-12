target_sources(LongNumber_lib
	PRIVATE
		long_number.cpp
	PUBLIC
		long_number.hpp
)

target_include_directories(long_number_lib PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)