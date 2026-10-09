#pragma once
#include <stdio.h>
#include <cstdlib>

typedef struct {
    int64_t key;
    int64_t payload;
} Data;

template<typename T>
void print_array(T* array, size_t size, void (*print_fn)(T)) {
    for (size_t i = 0; i < size; i++) {
        print_fn(array[i]);
        printf(" ");
    }
    printf("\n");
}

extern void fn_print_data(Data data);
extern void fn_print_long(long data);