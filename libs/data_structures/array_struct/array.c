#include "array.h"
#include <malloc.h>
#include <locale.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

array_ create_array(size_t size, size_t maxCapacity) {
    return (array_) {
            malloc(maxCapacity * sizeof(int)),
            size,
            maxCapacity
    };
}

array_ create_array_from_array(const int *array, size_t size) {
    array_ newArray = create_array(0, 1);
    for (size_t i = 0; i < size; i++)
        appendArray(&newArray, array[i]);

    return (array_) newArray;
}

void printArray(array_ array) {
    for (size_t i = 0; i < array.size; i++)
        printf("%d ", array.data[i]);
    printf("\n");
}

void qsort_(array_ *array, int first, int last) {
    if (first >= last)
        return;

    int i = first;
    int j = last;
    int middle = array->data[(first + last) / 2];

    while (i < j) {
        while (array->data[i] < middle)
            i++;
        while (array->data[j] > middle)
            j--;
        if (i <= j)
            swap(&array->data[i++], &array->data[j--]);
    }
    qsort_(array, first, j);
    qsort_(array, i, last);

}

array_ qsortArray(array_ array) {
    qsort_(&array, 0, array.size - 1);

    return array;
}

void appendArray(array_ *array, const int value) {
    if (array->size == array->maxCapacity) {
        array->data = realloc(array->data, array->maxCapacity * 2 * sizeof(int));
        array->maxCapacity *= 2;
    }
    array->data[array->size] = value;
    array->size++;
}

array_ add(array_ array1, array_ array2) {
    array_ resultedArray = create_array(0, 1);

    for (size_t i = 0; i < array1.size; i++) {
        appendArray(&resultedArray, array1.data[i]);
    }

    for (size_t i = 0; i < array2.size; i++) {
        appendArray(&resultedArray, array2.data[i]);
    }

    return (array_) resultedArray;
}

int linearSearch(const array_ array, const int x) {
    for (int i = 0; i < array.size; i++) {
        if (array.data[i] == x)
            return i;
    }
    return -1;
}

//возвращает кол-во элементов массива a размера size, удовлетворяющих фун-ции
//предикату conditional
int countIf(const array_ array, int (*conditional)(int)) {
    int count = 0;
    for (size_t i = 0; i < array.size; i++) {
        if (conditional(array.data[i]))
            count++;
    }
    return count;
}

void deleteElementWithSavingOrder(array_ *array, const size_t position) {
    for (size_t i = position + 1; i < array->size; i++)
        array->data[i - 1] = array->data[i];
    array->size -= 1;
}

void deleteElementWithoutSavingOrder(array_ *array, const size_t position) {
    array->data[position] = array->data[array->size - 1];
    array->size -= 1;
}

void insertElement(int *a, size_t *size, const size_t position, const int x)
{
    for (size_t i = *size - 1; i >= position; i++)
        a[i + 1] = a[i];
    a[position] = x;
    *size += 1;
}

