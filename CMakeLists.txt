cmake_minimum_required(VERSION 3.15)

project(
    c99 VERSION 1.0
    DESCRIPTION "Portable data structures and algorithms for C99."
    LANGUAGES C
)

add_executable(
        c99

        array/binary_search.c
        array/lis.c

        tree/prefix_tree.c

        graph/disjoint_set.c

        main.cpp
)
