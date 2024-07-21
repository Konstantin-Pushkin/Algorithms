cmake_minimum_required(VERSION 3.8)

project(Algorithms)

set(CMAKE_CXX_STANDARD 23)

# Search
add_executable(BinarySearch Search/BinarySearch.cpp)
add_executable(LinearSearch Search/LinearSearch.cpp)
add_executable(InterpolationSearch Search/InterpolationSearch.cpp)
add_executable(BlockInterpolationSearch Search/BlockInterpolationSearch.cpp)

# Sorting
add_executable(BubbleSort Sorting/BubbleSort.cpp)
add_executable(QuickSort Sorting/QuickSort.cpp)
add_executable(QuickSort_2 Sorting/QuickSort_2.cpp)
add_executable(ShellSort Sorting/ShellSort.cpp)
add_executable(InsertSort Sorting/InsertSort.cpp)
add_executable(MergeSort Sorting/MergeSort.cpp)

# Graph
add_executable(BFS Graph/BFS.cpp)
add_executable(BFS_2 Graph/BFS_2.cpp)
add_executable(DFS Graph/DFS.cpp)
add_executable(DFS_2 Graph/DFS_2.cpp)
add_executable(Dijkstra Graph/Dijkstra'_algorithm.cpp)

# Dynamic programming
add_executable(Fibonacci Dynamic_programming/Fibonacci.cpp)