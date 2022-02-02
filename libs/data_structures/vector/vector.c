//
// Created by DNS on 31.01.2022.
//
#include "vector.h"
#include <malloc.h>

vector createVector(size_t n) {
    int *data;
    if (n) {
        data = (int *) malloc(n * sizeof(int));
        if (data == NULL) {
            fprintf(stderr, "bad alloc ");
            exit(1);
        }
    } else
        data = NULL;

    return (vector) {data, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    if (!newCapacity) {
        free(v->data);
        v->data = NULL;
        return;
    }

    v->data = (int *) realloc(v->data, newCapacity * sizeof(int));
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }

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
    clear(v);
    v->capacity = 1;
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
    (v->size)++;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "vector is empty");
        exit(1);
    }

    v->size--;
    shrinkToFit(v);
}









//
//void appendArray(vector *array, const int value) {
//    if (array->size == array->capacity) {
//        array->data = realloc(array->data, array->capacity * 2 * sizeof(int));
//        array->capacity *= 2;
//    }
//    array->data[array->size] = value;
//    array->size++;
//}
//
//
//vector create_array_from_array(const int *array, size_t size) {
//    vector newArray = create_array(0, 1);
//    for (size_t i = 0; i < size; i++)
//        appendArray(&newArray, array[i]);
//
//    return (vector) newArray;
//}
//
//void printArray(vector array) {
//    for (size_t i = 0; i < array.size; i++)
//        printf("%d ", array.data[i]);
//    printf("\n");
//}
//
//void qsort_(vector *array, int first, int last) {
//    if (first >= last)
//        return;
//
//    int i = first;
//    int j = last;
//    int middle = array->data[(first + last) / 2];
//
//    while (i < j) {
//        while (array->data[i] < middle)
//            i++;
//        while (array->data[j] > middle)
//            j--;
//        if (i <= j)
//            swap(&array->data[i++], &array->data[j--]);
//    }
//    qsort_(array, first, j);
//    qsort_(array, i, last);
//
//}
//
//vector qsortArray(vector array) {
//    qsort_(&array, 0, array.size - 1);
//
//    return array;
//}
//
//
//vector add(vector array1, vector array2) {
//    vector resultedArray = create_array(0, 1);
//
//    for (size_t i = 0; i < array1.size; i++) {
//        appendArray(&resultedArray, array1.data[i]);
//    }
//
//    for (size_t i = 0; i < array2.size; i++) {
//        appendArray(&resultedArray, array2.data[i]);
//    }
//
//    return (vector) resultedArray;
//}
//
//int linearSearch(const vector array, const int x) {
//    for (int i = 0; i < array.size; i++) {
//        if (array.data[i] == x)
//            return i;
//    }
//    return -1;
//}
//
////возвращает кол-во элементов массива a размера size, удовлетворяющих фун-ции
////предикату conditional
//int countIf(const vector array, int (*conditional)(int)) {
//    int count = 0;
//    for (size_t i = 0; i < array.size; i++) {
//        if (conditional(array.data[i]))
//            count++;
//    }
//    return count;
//}
//
//void deleteElementWithSavingOrder(vector *array, const size_t position) {
//    for (size_t i = position + 1; i < array->size; i++)
//        array->data[i - 1] = array->data[i];
//    array->size -= 1;
//}
//
//void deleteElementWithoutSavingOrder(vector *array, const size_t position) {
//    array->data[position] = array->data[array->size - 1];
//    array->size -= 1;
//}
//
//void insertElement(int *a, size_t *size, const size_t position, const int x) {
//    for (size_t i = *size - 1; i >= position; i++)
//        a[i + 1] = a[i];
//    a[position] = x;
//    *size += 1;
//}
//
