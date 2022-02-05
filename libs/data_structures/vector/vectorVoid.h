//
// Created by DNS on 04.02.2022.
//

#ifndef LAST_VECTORVOID_H
#define LAST_VECTORVOID_H

<<<<<<< HEAD
#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>

=======
>>>>>>> fb5d5aabaaa342ad44fc10e18b177640b6c340b9
typedef struct vectorVoid {
    void *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;
} vectorVoid;

<<<<<<< HEAD
vectorVoid createVectorV(size_t n, size_t baseTypeSize);

void reserveV(vectorVoid *v, size_t newCapacity);

void shrinkToFitV(vectorVoid *v);

void clearV(vectorVoid *v);

void deleteVectorV(vectorVoid *v);

=======
>>>>>>> fb5d5aabaaa342ad44fc10e18b177640b6c340b9
#endif //LAST_VECTORVOID_H
