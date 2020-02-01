cmake_minimum_required(VERSION 3.9)
set (CMAKE_CXX_STANDARD 14)

project(Course2Week3 VERSION 1.0)

add_subdirectory(${CMAKE_SOURCE_DIR}/test)

enable_testing()
add_test(NAME test_heap COMMAND test_heap)
add_test(NAME test_tree COMMAND test_tree)
