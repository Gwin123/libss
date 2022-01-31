#ifndef INC_ARRAY_SET_H

#define INC_ARRAY_SET_H

#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct array {
    int *data;
    size_t size;
    size_t maxCapacity;
} array_;

array_ create_array(size_t size, size_t maxCapacity);

array_ create_array_from_array(const int *array, size_t size);

void printArray(array_ array);

void qsort_(array_ *array, int first, int last);

array_ qsortArray(array_ array);

void appendArray(array_ *array, int value);

array_ add(array_ array1, array_ array2);

int linearSearch(array_ array, int x);

int countIf(array_ array, int (*conditional)(int));

void deleteElementWithSavingOrder(array_ *array, size_t position);

void deleteElementWithoutSavingOrder(array_ *array, size_t position);



#endif