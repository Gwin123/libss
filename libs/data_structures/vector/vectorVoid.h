//
// Created by DNS on 03.02.2022.
//

#ifndef LAST_VECTORVOID_H
#define LAST_VECTORVOID_H

#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct vectorVoid {
    void *data; // указатель на нулевой элемент вектор
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
    size_t baseTypeSize; // размер базового типа
} vectorVoid;



#endif //LAST_VECTORVOID_H
