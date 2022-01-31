//
// Created by DNS on 14.12.2021.
//

#include <stdio.h>
#include <assert.h>
#include "array.h"

void inputArray_(int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void outputArray_(const int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void append_(int *array, size_t *size, const int value) {
    *size += 1;
    array[*size - 1] = value;
}

void deleteIf(int *a, size_t *size, int (*conditional)(int)) {
    int iWrite = 0;
    for (size_t iRead = 0; iRead < *size; iRead++)
        if (!conditional(a[iRead]))
            a[iWrite++] = a[iRead];
    *size = iWrite;
}

bool isEqual(const int a, const int b) {
    return a == b;
}


size_t binarySearch_(const int *a, size_t n, int x) {
    int left = -1;
    int right = n;
    while (right - left > 1) {
        int middle = (left + right) / 2;
        if (a[middle] <= x)
            left = middle;
        else
            right = middle;
    }
    return a[left] == x ? left : n;
}

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;

    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}

void copyArray(int *b, const int *a, size_t size) {
    for (size_t i = 0; i < size; i++)
        b[i] = a[i];
}

// возвращает позицию последнего элемента меньшего или равного x
// (вернёт -1, если все числа больше x)
int binarySearchLessOrEqual(const int *a, const int n, const int x) {
    int left = -1;
    int right = n;
    while (right - left > 1) {
        int middle = (left + right) / 2;
        if (a[middle] <= x)
            left = middle;
        else
            right = middle;
    }
    return left;
}

void insert_(int *const a, size_t *const n, const size_t pos, const int value) {
    assert (pos <= *n);
    if (*n == pos) {
        append_(a, n, value);
        return;
    }
    (*n)++;
    for (size_t i = *n; i != pos; i--)
        a[i] = a[i - 1];
    a[pos] = value;
}

void deleteByPosUnsaveOrder_(int *a, size_t *n, size_t pos) {
    a[pos] = a[*n - 1];
    *n -= 1;
}

void insertElement_(int *a, size_t *size, const size_t position, const int x) {
    assert(position <= *size);
    if (*size == position) {
        append_(a, size, x);
        return;
    }

    for (size_t i = *size - 1; i >= position; i--)
        a[i + 1] = a[i];
    a[position] = x;
    *size += 1;
}

void deleteByPosSaveOrder_(int *a, size_t *n, const size_t pos) {
    for (size_t i = pos; i < *n - 1; i++)
        a[i] = a[i + 1];
    *n -= 1;
}
