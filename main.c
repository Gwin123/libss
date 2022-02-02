#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/vector/vector.h"


//int main() {
//    volatile vector a = createVector(SIZE_MAX / 10);
//
//    printf("%llu", SIZE_MAX);
//    return 0;
//}

void test_popBack_emptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert (v.size == 1);
    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);

}

void test_pushBack_notEmptyVector() {
    vector v = createVector(5);
    for (int i = 0; i < v.capacity; i++) {
        pushBack(&v, i);
    }

    assert(v.size == 5);
    popBack(&v);

    assert(v.size == 4);
    assert(v.capacity == 4);
}



int main() {
    test_popBack_emptyVector();
    test_pushBack_notEmptyVector();
}






