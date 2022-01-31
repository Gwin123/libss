#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/vector/vector.h"


int main() {
    volatile vector a = createVector(SIZE_MAX / 10);

    printf("%llu", SIZE_MAX);
    return 0;
}







