cmake_minimum_required(VERSION "3.19.2")
project("senmath")

add_library("senmath" ${CMAKE_CURRENT_SOURCE_DIR}/src/Angle.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Vec2.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Vec3.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Mat2.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/Mat3.cpp)
target_include_directories("senmath" PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)