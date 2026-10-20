cmake_minimum_required(VERSION 3.24)
SET(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Sorts LANGUAGES CXX)

add_executable(MergeSort
    algosiki.cpp

    Sorts/merge_sort.cpp
)

add_executable(QuickSort
    algosiki.cpp

    Sorts/quick_sort.cpp
)

add_executable(CountingSort
    algosiki.cpp

    Sorts/counting_sort.cpp
)

add_executable(BubbleSort
    algosiki.cpp

    Sorts/bubble_sort.cpp
)

add_executable(SelectionSort
    algosiki.cpp

    Sorts/insertion_sort.cpp
)

project(Heap LANGUAGES CXX)

add_executable(Heapsort
    algosiki.cpp

    Heap/heapsort_tests.cpp
)