//
// Created by DNS on 04.02.2022.
//

#ifndef LAST_VECTORVOID_H
#define LAST_VECTORVOID_H

typedef struct vectorVoid {
    void *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;
} vectorVoid;

#endif //LAST_VECTORVOID_H
