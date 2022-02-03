//
// Created by DNS on 31.01.2022.
//
#include "vector.h"
#include <malloc.h>

void memoryAllocateError(const int* data) {
    if (data == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
}

vector createVector(size_t n) {
    int *data;
    if (n) {
        data = (int *) malloc(n * sizeof(int));
        memoryAllocateError(data);
    } else
        data = NULL;

    return (vector) {data, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity) {
        v->data = (int *) realloc(v->data, newCapacity * sizeof(int));
        memoryAllocateError(v->data);
    }
    else
        v->data = NULL;

    v->capacity = newCapacity;
    if (v->size > newCapacity)
        v->size = newCapacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    clear(v);
    v->capacity = 0;
}