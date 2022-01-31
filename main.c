//#include "libs/data_structures/array_struct/array.h"
#include <stdio.h>
#include <time.h>
#include <windows.h>
//#include "libs/data_structures/List/list.h"
//
//array_ qsort2(array_ array) {
//    if (array.size <= 1)
//        return array;
//
//    int elem = array.data[0];
//
//    array_ left = create_array(0, 1);
//    array_ middle = create_array(0, 1);
//    array_ right = create_array(0, 1);
//
//    for (int i = 0; i < array.size; i++) {
//        int currentElem = array.data[i];
//        if (currentElem < elem)
//            appendArray(&left, currentElem);
//        else if (currentElem == elem)
//            appendArray(&middle, currentElem);
//        else
//            appendArray(&right, currentElem);
//    }
//
//    return add(add(qsort2(left), middle), qsort2(right));
//}

long long fastMultiplicatin(const int x, const int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    else if (n % 2 == 0) {
        long long a = fastMultiplicatin(x, n / 2);
        return a * a;
    } else
        return x * fastMultiplicatin(x, n - 1);
}

long long int power(int a, int n) {
    long long x = a;
    long long res = 1;
    while (n != 0) {
        if (n & 1) // или n % 2
            res *= x;
        n >>= 1; // или n /= 2;
        x = x * x;
    }
    return res;
}

int fast(const int x, const int n) {
    if (n == 0)
        return 1;
    if (n % 2 == 0) {
        int a = fast(x, n / 2);
        return a * a;
    } else
        return x * fast(x, n - 1);
}

typedef struct string {
    char *data;
    int length;
} string;

void printString(string str) {
    for (int i = 0; i < str.length; i++)
        printf("%c", str.data[i]);
}

#include <malloc.h>

string createString(int size) {
    return (string) {
            malloc(size * sizeof(int)),
            size
    };
}

string createStringFromArray(const char *a, size_t size) {
    string result = createString(size);
    for (int i = 0; i < size; i++)
        result.data[i] = a[i];

    return result;
}

void print_bytes(void *data1, void *data2, size_t length) {
    unsigned char *ptr1 = data1;
    unsigned char *ptr2 = data2;

    for (size_t i = 0; i < length; i++) {
        unsigned char tmp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = tmp;

        ptr1++;
        ptr2++;
    }
}



void delete(int *a, const size_t size) {
    int iWrite = 0;
    for (int iRead = 0; iRead < size; iRead++) {
        if (a[iRead] > 0)
            a[iWrite++] = a[iRead];
    }
}

int bin(const int *a, const size_t size, const int x) {
    int leftBound = -1;
    int rightBound = size;
    while (rightBound - leftBound > 1) {
        int middle = leftBound + (rightBound - leftBound) / 2;
        if (a[middle] < x)
            leftBound = middle;
        else
            rightBound = middle;
    }
    return rightBound < size && a[rightBound] == x ? rightBound : -1;
}

#include <stdlib.h>

//int main() {
//    unsigned int x = 4;
//    if (x > -3)
//        printf("1");
//    else if (x < 4)
//        printf("2");
//    else
//        printf("3");
//}

//int main() {
//    float a = 2.55;
//    unsigned char b = a + 2;
//    printf("%zu", b);
//    return 42;
//}

#include <stdio.h>

//void f(long long *x) {
//    printf("%lld", *x);
//}
//
//int main() {
//    char a = 10;
//    char b = 15;
//
//    printf("%d", sizeof('A'));
//
//
//    char x = 5;
//    printf("%d %d", sizeof(x), sizeof(+x));
//}


//int main() {
//    float a = 123456789;
//    float b = 1;
//    float c = a + b;
//    printf("%f %f", a, c);
//    return 0;
//}


//int f() {
//    static int x;
//    if ((x = 5 * ++x) < 10)
//        return 5.47 + x;
//    else
//        return 7 * x;
//}
//
//int main() {
//    int y = 10;
//    int s = 0;
//    for (int y = 0; y < 5; y++)
//        s += y;
//    printf("%d %d", s, y);
//}


// Процедура для преобразования в двоичную кучу поддерева с корневым узлом i, что является
// индексом в arr[]. n - размер кучи
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}


void heapify(int arr[], int n, int i) {
    int largest = i;
// Инициализируем наибольший элемент как корень
    int l = 2 * i + 1; // левый = 2*i + 1
    int r = 2 * i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Если самый большой элемент не корень
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, n, largest);
    }
}

// Основная функция, выполняющая пирамидальную сортировку
void heapSort(int arr[], int n) {
    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--) {
        // Перемещаем текущий корень в конец
        swap(&arr[0], &arr[i]);

        // вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

/* Вспомогательная функция для вывода на экран массива размера n*/


//// Управляющая программа
//int main() {
//    int arr[] = {12, 11, 13, 5, 6, 7};
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    heapSort(arr, n);












    //
    //void inputArray(int *a, int size) {
    //    for (int i = 0; i < size; i++)
    //        scanf("%d", (a + i));
    //}
    //
    //void printArray(int *a, int n) {
    //    for (int i = 0; i < n; ++i)
    //        printf("%d ", a[i]);
    //    printf("\n");
    //}
    //
    //void merge(int *res, int *left, int left_size, int *right, int right_size) {
    //    int l_i = 0;
    //    int r_i = 0;
    //    int b_i = 0;
    //    while (l_i < left_size && r_i < right_size) {
    //        if (left[l_i] < right[r_i]) {
    //            res[b_i] = left[l_i];
    //            l_i++;
    //            b_i++;
    //        } else {
    //            res[b_i] = right[r_i];
    //            r_i++;
    //            b_i++;
    //        }
    //    }
    //
    //    while (l_i < left_size) {
    //        res[b_i++] = left[l_i++];
    //    }
    //
    //    while (r_i < right_size) {
    //        res[b_i++] = right[r_i++];
    //    }
    //}
    //
    //void merge_sort(int *a, const int size) {
    //    if (size <= 1)
    //        return;
    //
    //    int middle = size / 2;
    //
    //    int *left = a;
    //    int left_size = middle;
    //
    //    int *right = a + middle;
    //    int right_size = size - middle;
    //
    //    merge_sort(left, left_size);
    //    merge_sort(right, right_size);
    //
    //    int *buffer = (int *) malloc(sizeof(int) * size);
    //
    //    merge(buffer, left, left_size, right, right_size);
    //
    //    for (int i = 0; i < size; i++)
    //        a[i] = buffer[i];
    //
    //    free(buffer);
    //
    //}
    //
    //
    //int main() {
    //    int size;
    //    scanf("%d", &size);
    //
    //    int *arr = (int *) malloc(sizeof(int) * size);
    //
    //    inputArray(arr, size);
    //    merge_sort(arr, size);
    //    printArray(arr, size);
    //
    //}
    //



#define BITS 8

int absFast(const int x) {
    int mask = x >> (sizeof(int) * BITS - 1);

    return (x + mask) ^ mask;
}

int minFast(const int x, const int y) {
    return y ^ ((x ^ y) & -(x < y));
}

int maxFast(const int x, const int y) {
    return x ^ ((x ^ y) & -(x < y));
}

int isDegreeOf2(const int x) {
    return x && !(x & (x - 1));
}




// корень степени n через бинарный
//1 2 3 4 5
//6 7 8 9 10
//11 12 13 14 15
//16 17 18 19 20
//21 22 23 24 25
//26 27 28 29 30

#include <math.h>







double absf(const double x) {
    return x > 0 ? x : -x;
}

typedef struct fraction {
    int num;
    int denumerator;
} fraction;

//возвращает НОД для a и b
int gcd(int a, int b) {
    while (a != 0 && b != 0)
        if (abs(a) > b)
            a = abs(a) % b;
        else
            b %= abs(a);
    return abs(a) + b;
}

// сокращает дробь f
void simpleFraction(fraction *f) {
    int gcdValue = gcd(f->num, f->denumerator);
    f->num /= gcdValue;
    f->denumerator /= gcdValue;
}








double sqrtPos(const double x) {
    double l = 0;
    double r = x;
    double m = (l + r) / 2;
    while (absf(m * m - x) > 0.000001) {
        if (m * m > x)
            r = m;
        else
            l = m;

        m = (l + r) / 2;
    }
    return m;
}

double fastPow(double x, int n) {
    double res = 1;
    while (n != 0) {
        if (n & 1)
            res *= x;
        n >>= 1;
        x *= x;
    }
    return res;
}

#include <assert.h>

double root(const double x, const int n) {
    assert(!(x < 0 && n % 2 != 0));
    assert(n != 0);

    double absX = absf(x);
    double l = 0;
    double r = absX;
    double m = (l + r) / 2;
    double currentResult = fastPow(m, n);
    while (absf(currentResult - absX) > 0.000001) {
        if (currentResult > absX)
            r = m;
        else
            l = m;

        m = (l + r) / 2;
        currentResult = fastPow(m, n);
    }

    return x > 0 ? m : -m;
}

int main() {
    printf("%lf", root(12245.0, 16));
    printf("%d", 123);
}










