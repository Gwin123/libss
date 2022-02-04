//
// Created by DNS on 03.02.2022.
//

#include "vectorVoid.h"
#include <malloc.h>

void memoryAllocateError(const void *data) {
    if (data == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
}

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    void *data;
    if (n) {
        data = malloc(n * sizeof(baseTypeSize));
        memoryAllocateError(data);
    } else
        data = NULL;

    return (vectorVoid) {data, 0, n, baseTypeSize};
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity) {
        v->data = realloc(v->data, newCapacity * sizeof(v->baseTypeSize));
        memoryAllocateError(v->data);
    } else
        v->data = NULL;

    v->capacity = newCapacity;
    if (v->size > newCapacity)
        v->size = newCapacity;
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
    clearV(v);
    v->capacity = 1;
}
