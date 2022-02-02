#include "libs/data_structures/vector/vector.h"

void test_popBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert (v.size == 1);
    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);

    deleteVector(&v);
}

void test_pushBack_notEmptyVector() {
    vector v = createVector(5);
    for (int i = 0; i < v.capacity; i++) {
        pushBack(&v, i);
    }

    assert(v.size == 5);
    popBack(&v);

    assert(v.size == 4);
    assert(v.capacity == 5);

    deleteVector(&v);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(5);
    for (int i = 1; i <= v.capacity; i++)
        pushBack(&v, i);

    int *index = atVector(&v, 2);
    assert(*index == 3);

    deleteVector(&v);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(5);
    for (int i = 0; i < v.capacity; i++)
        pushBack(&v, i);

    int *index = atVector(&v, 4);
    assert(*index == 4);

    deleteVector(&v);
}

void test_back_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 5);

    int *pBack = back(&v);
    assert(*pBack == 5);

    deleteVector(&v);
}

void test_back_fullVector() {
    vector v = createVector(5);
    for (int i = 0; i < v.capacity; i++)
        pushBack(&v, i);

    int *pBack = back(&v);
    assert(*pBack == 4);

    deleteVector(&v);
}

void test_front_fullVector() {
    vector v = createVector(5);
    for (int i = 0; i < v.capacity; i++)
        pushBack(&v, i);

    int *pFront = front(&v);
    assert(*pFront == 0);

    deleteVector(&v);
}

void test_front_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 5);

    int *pFront = front(&v);
    assert(*pFront == 5);

    deleteVector(&v);
}

int main() {
    test_popBack_emptyVector();
    test_pushBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_back_fullVector();
    test_front_oneElementInVector();
    test_front_fullVector();
}






