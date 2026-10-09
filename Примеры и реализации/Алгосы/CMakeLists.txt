cmake_minimum_required(VERSION 3.24)
SET(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(MergeSort LANGUAGES CXX)
project(QuickSort LANGUAGES CXX)
project(CountingSort LANGUAGES CXX)
project(BubbleSort LANGUAGES CXX)
project(SelectionSort LANGUAGES CXX)

add_executable(MergeSort
    algosiki.cpp

    merge_sort.cpp
)

add_executable(QuickSort
    algosiki.cpp

    quick_sort.cpp
)

add_executable(CountingSort
    algosiki.cpp

    counting_sort.cpp
)

add_executable(BubbleSort
    algosiki.cpp

    bubble_sort.cpp
)

add_executable(SelectionSort
    algosiki.cpp

    insertion_sort.cpp
)