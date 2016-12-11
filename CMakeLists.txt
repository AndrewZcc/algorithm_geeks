cmake_minimum_required(VERSION 3.5)
project(algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp search/binary_search.h sort/insertion_sort.h sort/insertion_sort.h util/util.h sort/selection_sort.h sort/bubble_sort.h sort/merge_sort.h sort/heap_sort.h sort/quick_sort.h)
add_executable(algorithm ${SOURCE_FILES})