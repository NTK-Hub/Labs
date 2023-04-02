//
// Created by NTK on 19.02.2023.
//

#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include "array.h"
#include <stdbool.h>
#include <math.h>

int compare_ints(const void *a, const void *b) {
    int arg1 = *(const int *) a;
    int arg2 = *(const int *) b;
    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;
    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}

int countNUnique(long long *a, int n) {
    qsort(a, n, sizeof(long long), cmp_long_long);

    int count = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1])
            count++;
    }
    return count;
}

//void insertionSort(int *a, const size_t size) {
//    for (size_t i = 1; i < size; i++) {
//
//        int t = a[i];
//        int j = i;
//        while (j > 0 && a[j - 1] > t) {
//            a[j] = a[j - 1];
//            j--;
//        }
//        a[j] = t;
//    }
//}

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
    assert (pos <= *n);
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
    for (size_t i = pos + 1; i < *n; i++)
        a[i - 1] = a[i];
    (*n)--;
}

void deleteByPosUnsaveOrder_(int *a, size_t *n, size_t pos) {
    a[pos] = a[*n - 1];
    (*n)--;
}

size_t linearSearch_(const int *a, const size_t n, int x) {
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

void deleteIf_(int *const a, size_t *const n, int (*deletePredicate )(
        int)) {
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

void forEach_(const int *source, int *dest, const size_t n, const int (*
predicate )(int)) {
    for (size_t i = 0; i < n; i++)
        dest[i] = predicate(source[i]);
}

int binarySearchLessOrEqual(const int *a, size_t n, int x) {
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


size_t binarySearch(const int *a, size_t n, const int x) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (a[middle] < x) // если ’истина’, искомый элемент лежит правее
            left = middle + 1;
        else if (a[middle] > x) // если ’истина’, искомый элемент лежит левее
            right = middle - 1;
        else
            return middle;
    }
    return n;
}

size_t binarySearchMoreOrEqual_(const int *a, size_t n, int x) {
    if (a[0] >= x)
        return 0;
    int left = 0;
    int right = n;
    while (right - left > 1) {
        size_t middle = left + (right - left) / 2;
        if (a[middle] < x)
            left = middle;
        else
            right = middle;
    }
    return right;
}

int getPositionithGivenValue(const int *a, const size_t n, const int x) {
    int i = 0;
    while (i < n && a[i] != x)
        i++;

    return i == n ? -1 : i;
}

int findFirsNegativeIndex(const int *a, const size_t n) {
    int i = 0;
    while (i < n && a[i] >= 0)
        i++;
    return i == n ? -1 : i;
}

int findIndexIf(const int *a, const size_t n, int (*f)(int)) {
    for (size_t i = 0; i < n; i++)
        if (f(a[i]))
            return i;
    return -1;
}

int findLastEvenIndex(const int *a, const size_t n) {
    for (size_t i = n - 1; i <= 0; i--)
        return a[i] % 2 == 0 ? i : -1;
}

int findIndexLastIf(const int *a, const size_t n, int (*f)(int)) {
    for (size_t i = n - 1; i <= 0; i--)
        if (f(a[i]))
            return i;
    return -1;
}

int getNegativeCount(const int *a, const size_t n) {
    int count = 0;

    for (size_t i = 0; i < n; i++)
        count += a[i] < 0;

    return count;
}

int getCountIf(const int *a, const size_t n, int (*f)(int)) {
    int count = 0;

    for (size_t i = 0; i < n; i++)
        count += f(a[i]);

    return count;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void reverseArray(int *a, size_t n) {
    size_t halfSize = n / 2;

    for (size_t i = 0; i < halfSize; ++i)
        swap(&a[i], &a[n - i - 1]);
}

int isPalindrom(const int *a, const size_t n) {
    size_t halfSize = n / 2;
    for (size_t i = 0; i < halfSize; i++)
        if (a[i] != a[n - i - 1])
            return 0;
    return 1;
}

void sortChoice(int *a, size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        size_t minIndex = i;
        for (size_t j = i; j < n; j++)
            if (a[i] < a[minIndex])
                minIndex = j;
        swap(&a[i], &a[minIndex]);
    }
}

void removeAllOddElements(int *a, size_t *n) {
    size_t iRead = 0;
    while (iRead < *n && a[iRead] % 2 == 0)
        iRead++;
    size_t iWrite = iRead;
    while (iRead < *n) {
        if (a[iRead] % 2 == 0) {
            a[iWrite] = a[iRead];
            iWrite++;
        }
        iRead++;
    }
    *n = iWrite;
}

void insertAnElement(int *a, size_t *n, size_t pos, int x) {
    for (int i = *n - 1; i >= pos; i--) {
        a[i + 1] = a[i];
    }
    a[pos] = x;
    (*n)++;
}

void deleteByPosSaveOrder(int *a, size_t *n, const size_t pos) {
    size_t lastElementPos = *n - 1;
    for (size_t i = pos; i < lastElementPos; i++)
        a[i] = a[i + 1];
    *n = lastElementPos;
}

void deleteByPosUnsaveOrder(int *a, size_t *n, size_t pos) {
    a[pos] = a[*n - 1];
    (*n)--;
}

void forEach(int *a, const size_t size, void (*f)(int *)) {
    for (size_t i = 0; i < size; i++)
        f(&a[i]);
}

int any(const int *a, const size_t size, int (*f)(int)) {
    for (size_t i = 0; i < size; i++)
        if (f(a[i]))
            return 1;
    return 0;
}

int all(const int *a, const size_t size, int (*f)(int)) {
    for (size_t i = 0; i < size; i++)
        if (!f(a[i]))
            return 0;
    return 1;
}

void arraySplit(const int *a, size_t sizeA, int *b, size_t *sizeB, int *c, size_t *sizeC, int (*pred)(int)) {
    *sizeB = 0;
    *sizeC = 0;
    for (size_t i = 0; i < sizeA; i++) {
        if (pred(a[i])) {
            b[*sizeB] = a[i];
            (*sizeB)++;
        } else {
            c[*sizeC] = a[i];
            (*sizeC)++;
        }
    }
}

size_t linearSearchFirstMaxIndex(const int *a, const size_t n) {
    size_t maxIndex = 0;
    for (size_t i = 1; i < n; ++i) {
        if (a[i] > a[maxIndex])
            maxIndex = i;
    }

    return maxIndex;
}

int linearSearchMax(const int *a, const size_t n) {
    size_t index = linearSearchFirstMaxIndex(a, n);
    return a[index];
}

size_t linearSearchLastMinIndex(const int *a, const size_t n) {
    size_t minIndex = 0;
    for (size_t i = 1; i < n; ++i) {
        if (a[i] <= a[minIndex])
            minIndex = i;
    }

    return minIndex;
}

int linearSearchMin(const int *a, const size_t n) {
    size_t index = linearSearchLastMinIndex(a, n);
    return a[index];
}

bool isUniqueArray(const int *a, const size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = i + 1; j < n; ++j) {
            if (a[i] == a[j])
                return false;
        }
    }
    return true;
}

long long getSum(const int *a, const size_t n) {
    int sum = 0;
    for (size_t i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

float getDistance(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i] * a[i];

    return sqrt(sum);
}

bool isNonDescendingSorted(int *a, int n) {
    for (int i = 1; i < n; i++)
        if (a[i] < a[i - 1])
            return false;
    return true;
}

int countValues(const int *a, int n, int value) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == value)
            count++;
    }
    return count;
}

int maximum(int a, int b) {
    return a > b ? a : b;
}

bool isOrdered(int *a, size_t n) {
    for (size_t i = 1; i < n; ++i) {
        if (a[i - 1] > a[i])
            return false;
        return true;
    }
}