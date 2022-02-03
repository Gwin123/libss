#include "libs/data_structures/vector/vector.h"

void test_pushBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 5);

    assert(v.size == 1);
    assert(v.capacity == 1);
    assert(v.data[0] == 5);

    deleteVector(&v);
}

void test_pushBack_fullVector() {
    vector v = createVector(5);
    for (int i = 0; i < v.capacity; i++) {
        pushBack(&v, i);
    }

    assert(v.size == 5);
    pushBack(&v, 5);

    assert(v.data[v.size - 1] == 5);
    assert(v.size == 6);
    assert(v.capacity == 10);

    deleteVector(&v);
}

void test_pushBack() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);

    deleteVector(&v);
}

void test_popBack() {
    test_popBack_notEmptyVector();
}

void test_getVectorValue_lastElement() {
    vector v = createVector(5);
    for (int i = 0; i < v.capacity; i++) {
        pushBack(&v, i);
    }

    assert(getVectorValue(&v, v.size - 1) == 4);

    deleteVector(&v);
}

void test_getVectorValue() {
    test_getVectorValue_lastElement();
}

void test_isEmpty_emptyVector() {
    vector v = createVector(0);

    assert(isEmpty(&v));

    deleteVector(&v);
}

void test_isEmpty_notEmptyVector() {
    vector v = createVector(0);

    pushBack(&v, 5);

    assert(!isEmpty(&v));

    deleteVector(&v);
}

void test_isFull_emptyVector() {
    vector v = createVector(0);

    assert(isFull(&v));

    deleteVector(&v);
}

void test_isFull_notEmptyNotFullVector() {
    vector v = createVector(5);

    pushBack(&v, 5);

    assert(!isFull(&v));

    deleteVector(&v);
}

void test_isFull_FullVector() {
    vector v = createVector(3);

    pushBack(&v, 5);
    pushBack(&v, 5);
    pushBack(&v, 5);

    assert(isFull(&v));

    deleteVector(&v);
}

void test_isEmpty() {
    test_isEmpty_emptyVector();
    test_isEmpty_notEmptyVector();
}

void test_isFull() {
    test_isFull_emptyVector();
    test_isFull_notEmptyNotFullVector();
    test_isFull_FullVector();
}

void test_atVector_notEmptyVector() {
    vector v = createVector(5);
    for (int i = 1; i <= v.capacity; i++)
        pushBack(&v, i);

    int* index = atVector(&v, 2);
    assert(*index == 3);

}

void test_atVector_requestToLastElement() {
    vector v = createVector(5);
    for (int i = 0; i < v.capacity; i++)
        pushBack(&v, i);

    int* index = atVector(&v, 4);
    assert(*index == 4);
}

void test_atVector() {
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
}

void test_back_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 5);

    int *pBack = back(&v);
    assert(*pBack == 5);
}

void test_back_fullVector() {
    vector v = createVector(5);
    for (int i = 0; i < v.capacity; i++)
        pushBack(&v, i);

    int* pBack = back(&v);
    assert(*pBack == 4);
}

void test_back() {
    test_back_oneElementInVector();
    test_back_fullVector();
}

void test_front_fullVector() {
    vector v = createVector(5);
    for (int i = 0; i < v.capacity; i++)
        pushBack(&v, i);

    int* pFront = front(&v);
    assert(*pFront == 0);
}

void test_front_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 5);

    int *pFront = front(&v);
    assert(*pFront == 5);
}

void test_front() {
    test_front_fullVector();
    test_front_oneElementInVector();
}

void test() {
    test_pushBack();
    test_popBack();
    test_getVectorValue();
    test_isEmpty();
    test_isFull();
    test_front();
    test_back();
    test_atVector();
}

int main() {
    test();
}
