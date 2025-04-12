target_sources(long_number
    PRIVATE
        long_number.cpp
    PUBLIC
        long_number.hpp
)

target_include_directories(long_number PUBLIC
    "${PROJECT_SOURCE_DIR}/src"
)