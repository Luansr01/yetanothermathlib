cmake_minimum_required(VERSION "3.19.2")
project("mathlib")

include_directories("include")

add_executable("mathlib" "tests.cpp")

target_include_directories("mathlib" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include}")

set(CMAKE_CXX_FLAGS "${CXXFLAGS}")


