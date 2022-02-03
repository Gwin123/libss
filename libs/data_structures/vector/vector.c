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

bool isEmpty(vector *v) {
    return !v->size;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i];
}

void pushBack(vector *v, int x) {
    if (v->capacity == 0)
        reserve(v, 1);
    else if (isFull(v))
        reserve(v, v->capacity * 2);

    v->data[v->size] = x;
    v->size++;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "vector is empty");
        exit(1);
    }
    v->size--;
}

int* atVector(vector *v, size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[%u] is not exists", index);
        exit(1);
    }

    return v->data + index;
}

int* back(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "Vector is empty");
        exit(1);
    }

    return v->data + v->size - 1;
}

int* front(vector *v) {
    if (v->size == 0) {
        fprintf(stderr, "Vector is empty");
        exit(1);
    }

    return v->data;
}