cmake_minimum_required(VERSION "3.19.2")

project("senmath")

project("senmathtests")
add_executable("senmathtests" ${CMAKE_CURRENT_SOURCE_DIR}/tests.cpp)
target_link_libraries("senmathtests" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../out/libsenmath.a)
target_include_directories("senmathtests" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../headers)
