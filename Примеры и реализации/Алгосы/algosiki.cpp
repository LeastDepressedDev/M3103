#include "algosiki.h"
#include <stdio.h>

void fn_print_data(Data data) {
    printf("(%ld %ld)", data.key, data.payload);
}

void fn_print_long(long data) {
    printf("%ld", data);
}