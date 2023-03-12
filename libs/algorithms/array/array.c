//
// Created by NTK on 19.02.2023.
//

#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "array.h"

#define NOT_FOUND -1


void inputArray_(int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void outputArray_(const int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void append_(int *const a, size_t *const n, const int value) {
    a[*n] = value;
    (*n)++;
}

void insert_(int *const a, size_t *const n, const size_t pos,
             const int value) {
    assert (pos < *n);
    if (*n != 0) {
        size_t lowBound = (pos == 0) ? SIZE_MAX : pos;
        (*n)++;
        for (size_t i = *n; i != lowBound; i--)
            a[i] = a[i - 1];
        a[pos] = value;
    } else {
        (*n)++;
        a[pos] = value;
    }
}

void deleteByPosSaveOrder_(int *a, size_t *n, const size_t pos) {
    for (size_t i = pos; i < *n - 1; i++)
        a[i] = a[i + 1];
    (*n)--;
}

void deleteByPosUnsaveOrder_(int *a, size_t *n, size_t pos) {
    a[pos] = a[*n - 1];
    (*n)--;
}

size_t linearSearch(const int *a, const size_t n, int x) {
    for (size_t i = 0; i < n; i++)
        if (a[i] == x)
            return i;
    return n;
}

int any_(const int *a, size_t n, int (*predicate )(int)) {
    for (size_t i = 0; i < n; i++)
        if (predicate(a[i]))
            return 1;
    return 0;
}

int all_(const int *a, size_t n, int (*predicate )(int)) {
    for (size_t i = 0; i < n; i++)
        if (!predicate(a[i]))
            return 0;
    return 1;
}

int countIf_(const int *const a, const size_t n, int (*predicate )(int)) {
    int count = 0;
    for (size_t i = 0; i < n; i++)
        count += predicate(a[i]);
    return count;
}

void deleteIf_(int *const a, size_t *const n, int (*deletePredicate )(int)) {
    size_t iRead = 0;
    while (iRead < *n && !deletePredicate(a[iRead]))
        iRead++;
    size_t iWrite = iRead;
    while (iRead < *n) {
        if (!deletePredicate(a[iRead])) {
            a[iWrite] = a[iRead];
            iWrite++;
        }
        iRead++;
    }
    *n = iWrite;
}

void forEach(const int *source, int *dest, const size_t n, const int (*predicate )(int)) {
    for (size_t i = 0; i < n; i++)
        dest[i] = predicate(source[i]);
}

size_t binarySearch_(const int *a, size_t n, int x) {
    size_t left = 0;
    size_t right = n - 1;
    while (left <= right) {
        size_t middle = left + (right - left) / 2;
        if (a[middle] < x)
            left = middle + 1;
        else if (a[middle] > x)
            right = middle - 1;
        else
            return middle;
    }
    return SIZE_MAX;
}

size_t binarySearchMoreOrEqual_(const int *a, size_t n, int x) {
    if (a[0] >= x)
        return 0;
    size_t left = 0;
    size_t right = n;
    while (right - left > 1) {
        size_t middle = left + (right - left) / 2;
        if (a[middle] < x)
            left = middle;
        else
            right = middle;
    }
    return right;
}

unordered_array_set unordered_array_set_create(size_t capacity) {
    return (unordered_array_set) {
            malloc(sizeof(int) * capacity), 0, capacity
    };
}

unordered_array_set unordered_array_set_create_from_array(const int *a, size_t size) {
    unordered_array_set set = unordered_array_set_create(size);
    for (size_t i = 0; i < size; i++)
        unordered_array_set_insert(&set, a[i]);
    unordered_array_set_shrinkToFit(&set);
    return set;
}

static void unordered_array_set_shrinkToFit(unordered_array_set *a) {
    if (a->size != a->capacity) {
        a->data = (int *) realloc(a->data, sizeof(int) * a->size);
        a->capacity = a->size;
    }
}

int compare_ints(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

int unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2) {
    if (set1.size != set2.size)
        return 0;
    qsort(set1.data, set1.size, sizeof(int), compare_ints);
    qsort(set2.data, set2.size, sizeof(int), compare_ints);
    return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0;
}

int unordered_array_set_in(unordered_array_set *set, int value) {
    return linearSearch(set->data, set->size, value);
}

void unordered_array_set_isAbleAppend(unordered_array_set *set) {
    assert (set->size < set->capacity);
}

void unordered_array_set_insert(unordered_array_set *set, int value) {
    if (unordered_array_set_in(set, value) == set->size) {
        unordered_array_set_isAbleAppend(set);
        append_(set->data, &set->size, value);
    }
}

bool isUnique(const int *const a, int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] == a[j])
                return false;
    return true;
}



void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void selectionSortDecr(int *const a, int n) {
    for (int i = 0; i < n; i++) {
        int indexOfMax = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[indexOfMax])
                indexOfMax = j;
        }
        if (indexOfMax != i)
            swap(&a[indexOfMax], &a[i]);
    }
}

int getIndexOfFirstMax(const int *const a, int n) {
    assert(n > 0); // программа выдаст ошибку, если пользователь
// передаст неположительное значение n;
// требует подключения assert.h
    int indexOfFirstMax = 0;
    for (int i = 1; i < n; i++)
        if (a[i] > a[indexOfFirstMax]) // особое внимание на знак
// операции сравнения
// для поиска первого потребуется >
// для поиска последнего - >=
            indexOfFirstMax = i;
    return indexOfFirstMax;
}

int getIndexOfLastMin(const int *const a, int n) {
    assert(n > 0);
    int indexOfLastMin = 0;
    for (int i = 1; i < n; i++)
        if (a[i] <= a[indexOfLastMin])
            indexOfLastMin = i;
    return indexOfLastMin;
}

void selectionSort(int *const a, int n) {
    for (int i = 0; i < n; i++) {
        int indexOfMin = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[indexOfMin])
                indexOfMin = j;
        }
        if (indexOfMin != i)
            swap(&a[indexOfMin], &a[i]);
    }
}

void selectionSortInterval(int *a, int start, int end) {
    assert(start <= end);
    selectionSort(a + start, end - start);
}

bool isNonDecreasing(const int *const a, int n) {
    for (int i = 1; i < n; i++)
        if (a[i - 1] > a[i])
            return false;
    return true;
}

bool isNonIncreasing(const int *const a, int n) {
    for (int i = 1; i < n; i++)
        if (a[i - 1] < a[i])
            return false;
    return true;
}

bool isSorted(const int *const a, int n) {
    return isNonDecreasing(a, n) || isNonIncreasing(a, n);
}

double getGeometricMeanOfPositiveElements(const int *const a, int n) {
    assert(n > 0);
    double prodOfPositives = 1;
    int nPositives = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            nPositives++;
            prodOfPositives *= a[i];
        }
    }
    return nPositives ? pow(prodOfPositives, 1. / nPositives) : 0;
}

void combine(int *a, int n, int *b, int m, int *c, int *cSize) {
// обезопасим себя, вдруг пользователь передаст несортированные массивы
// тут два варианта: или отсортируем сами, или выставим assert;
// я остановился на первом
    if (isNonIncreasing(a, n))
        selectionSortDecr(a, n);
    if (isNonIncreasing(b, m))
        selectionSortDecr(b, m);
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < n) {
        if (j == m || a[i] > b[j])
            c[k++] = a[i++];
        else if (a[i] == b[j])
            i++;
        else
            j++;
    }
    *cSize = k;
}

int getIndexOfFirstNonNegative(const int *const a, int n) {
    for (int i = 0; i < n; i++)
        if (a[i] >= 0)
            return i;
    return NOT_FOUND;
}

void reverseArray(int *const a, int n) {
    for (int i = 0, j = n - 1; i < j; i++, j--)
        swap(&a[i], &a[j]);
}

void getNearestElements(const int *const a, int n, int x,
                        int *lowerBound, int *upperBound) {
    *lowerBound = INT_MIN;
    *upperBound = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            *lowerBound = x;
            *upperBound = x;
            return;
        } else if (*lowerBound < a[i] && a[i] < x)
            *lowerBound = a[i];
        else if (x < a[i] && a[i] < *upperBound)
            *upperBound = a[i];
    }
}

void arrayToSet(int *source, int size, int *destination, int *sizeB) {
    if (source != destination)
        memcpy(destination, source, sizeof(int) * size);
// выполним сортировку массива, если он неотсортирован;
// пусть он будет отсортирован по неубыванию
    if (isNonIncreasing(destination, size))
        reverseArray(destination, size);
    else if (!isNonDecreasing(destination, size))
        selectionSort(destination, size);
    int j = 1;
    for (int i = 1; i < size; i++) {
        if (destination[i] != destination[i - 1])
            destination[j++] = destination[i];
    }
    *sizeB = j;
}

// Возвращает значение "истина", если вещественные числа
// a и b можно считать равными на основании абсолютной погрешности
bool isEqual(double a, double b) {
    return fabs(a - b) < 0.0000001;
}

bool isGeometricProgression(int *a, int n) {
    if (linearSearch(a, n, 0) != NOT_FOUND)
        return false;
    double q = a[1] / a[0];
    if (isEqual(fabs(q), 1))
        return false;
    for (int i = 2; i < n; i++)
        if (!isEqual((double) a[i] / a[i - 1], q))
            return false;
    return true;
}

int getSumOfEvenDigitsOfPositiveNumber(int x) {
    if (x < 0)
        return 0;
    int s = 0;
    while (x != 0) {
        if (x % 2 == 0)
            s += x % 10;
        x /= 10;
    }
    return s;
}

long long getSum(const int * const a, int n) {
    long long s = 0;
    for (int i = 0; i < n; i++)
        s += a[i];
    return s;
}

