cmake_minimum_required(VERSION 3.9)
set (CMAKE_CXX_STANDARD 14)

project(Course2Week1 VERSION 1.0)

add_subdirectory(${CMAKE_SOURCE_DIR}/test)

enable_testing()
add_test(NAME test_bfs COMMAND test_bfs)
add_test(NAME test_connected_comp COMMAND test_connected_comp)
add_test(NAME test_dfs COMMAND test_dfs)
add_test(NAME test_topological COMMAND test_topological)
add_test(NAME test_scc COMMAND test_scc)
