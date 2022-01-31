#ifndef INC_ARRAY_H
#define INC_ARRAY_H

#include <stddef.h>
#include <stdbool.h>

// ввод массива data размера n
void inputArray_(int *a, size_t n);

// вывод массива data размера n
void outputArray_(const int *a, size_t n);

void append_(int *array, size_t *size, int value);

void deleteIf(int *a, size_t *size, int (*conditional)(int));

bool isEqual(int a, int b);

// возвращает позицию вхождения элемента x
// в отсортированном массиве stops размера n при его наличии, иначе - n
size_t binarySearch_(const int *a, size_t n, int x);

int compare_ints(const void *a, const void *b);

void copyArray(int *b, const int *a, size_t size);

int binarySearchLessOrEqual(const int *a, int n, int x);

void insert_(int *a, size_t *n, size_t pos, int value);

void insertElement_(int *a, size_t *size, size_t position, int x);

void deleteByPosUnsaveOrder_(int *a, size_t *n, size_t pos);

void deleteByPosSaveOrder_(int *a, size_t *n, const size_t pos);

# endif
