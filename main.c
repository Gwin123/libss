#include "libs/data_structures/vector/vectorVoid.h"

int main() {
    vectorVoid v = createVectorV(5, sizeof(int));

    reserveV(&v, 100);
    printf("%d %d %d", v.capacity, v.size, v.data);


    return 0;
}
