//
// Created by NTK on 26.03.2023.
//

#include "sort.h"

void bubbleSort(int *a, size_t size) {
    for (size_t i = 0; i < size - 1; i++)
        for (size_t j = size - 1; j > i; j--)
            if (a[j - 1] > a[j])
                swap(&a[j - 1], &a[j]);
}

long long getBubbleSortNComp(int *a, size_t size) {
    long long nComps = 0;
    for (size_t i = 0; ++nComps && i < size; i++)
        for (size_t j = i; ++nComps && i < size; j++)
            if (++nComps && a[i] > a[j])
                swap(&a[i], &a[j]);

    return nComps;
}

void selectionSort(int *a, const size_t size) {
    for (int i = 0; i < size - 1; i++) {
        int minPos = i;
        for (int j = i + 1; j < size; j++)
            if (a[j] < a[minPos])
                minPos = j;
        swap(&a[i], &a[minPos]);
    }
}

long long getSelectionSortNComp(int *a, size_t size) {
    long long nComps = 0;
    for (int i = 0; ++nComps && i < size; i++) {
        int min = a[i];
        int minIndex = i;
        for (int j = i + 1; ++nComps && j < size; j++)
            if (++nComps && a[j] < min) {
                min = a[j];
                minIndex = j;
            }
        if (++nComps && i != minIndex)
            swap(&a[i], &a[minIndex]);
    }

    return nComps;
}

void insertionSort(int *a, const size_t size) {
    for (int i = 1; i < size; ++i) {
        int t = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
}

long long getInsertionSortNComp(int *a, size_t size) {
    long long nComp = 0;
    for (int i = 1; ++nComp && i < size; ++i) {
        int t = a[i];
        int j = i;
        while (++nComp && j > 0 && a[j - 1] > t) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = t;
    }
    return nComp;
}

void combsort(int *a, const size_t size) {
    size_t step = size;
    int swapped = 1;
    while (step > 1 || swapped) {
        if (step > 1)
            step /= 1.24733;
        swapped = 0;
        for (size_t i = 0, j = i + step; j < size; ++i, ++j)
            if (a[i] > a[j]) {
                swap(&a[i], &a[j]);
                swapped = 1;
            }
    }
}

long long getCombSortNComp(int *a, size_t size) {
    long long nComp = 0;
    size_t step = size;
    int swapped = 1;
    while (step > 1 && ++nComp || swapped) {
        if (step > 1 && ++nComp)
            step /= 1.24733;
        swapped = 0;
        for (size_t i = 0, j = i + step; j < size && ++nComp; ++i, ++j)
            if (a[i] > a[j] && ++nComp) {
                swap(&a[i], &a[j]);
                swapped = 1;
            }
    }
    return nComp;
}

void shellSort(int *a, size_t size) {
    for (int d = size / 2; d > 0; d /= 2)
        for (int i = d; i < size; ++i)
            for (int j = i - d; j >= 0 && a[j] > a[j + d]; j -= d)
                swap(&a[j], &a[j + d]);
}

long long getShellSortNComp(int *a, size_t size) {
    long long nComp = 0;
    for (int d = size / 2; d > 0 && ++nComp; d /= 2)
        for (int i = d; i < size && ++nComp; ++i)
            for (int j = i - d; j >= 0 && a[j] > a[j + d]; j -= d) {
                nComp += 2;
                swap(&a[j], &a[j + d]);
            }

    return nComp;
}

void getPrefixSums(int *a, size_t size) {
    int prev = a[0];
    *a = 0;
    for (int i = 1; i < size; i++) {
        int t = a[i];
        a[i] = prev + a[i - 1];
        prev = t;
    }
}

void radixSort(int *a, size_t size) {
    int *buffer = (int *) calloc(size, sizeof(int));
    int max = 0b11111111;
    int step = 8;

    for (int byte = 0; byte < sizeof(int); byte++) {
        int values[UCHAR_MAX + 1] = {0};

        for (size_t i = 0; i < size; i++) {
            int curByte;
            if (byte + 1 == sizeof(int))
                curByte = ((a[i] >> (byte * step)) + CHAR_MAX + 1) & max;
            else
                curByte = (a[i] >> (byte * step)) & max;

            values[curByte]++;
        }

        getPrefixSums(values, UCHAR_MAX + 1);

        for (size_t i = 0; i < size; i++) {
            int curByte;
            if (byte + 1 == sizeof(int))
                curByte = ((a[i] >> (byte * step)) + CHAR_MAX + 1) & max;
            else
                curByte = (a[i] >> (byte * step)) & max;

            buffer[values[curByte]++] = a[i];
        }
        memcpy(a, buffer, sizeof(int) * size);
    }
    free(buffer);
}

long long getRadixSortNComp(int *a, size_t size) {
    long long nComp = 0;
    int *buffer = (int *) calloc(size, sizeof(int));
    int max = 0b11111111;
    int step = 8;

    for (int byte = 0; byte < sizeof(int) && ++nComp; byte++) {
        int values[UCHAR_MAX + 1] = {0};

        for (size_t i = 0; i < size && ++nComp; i++) {
            int curByte;
            if (byte + 1 == sizeof(int))
                curByte = ((a[i] >> (byte * step)) + CHAR_MAX + 1) & max;
            else
                curByte = (a[i] >> (byte * step)) & max;

            values[curByte]++;
        }

        getPrefixSums(values, UCHAR_MAX + 1);

        for (size_t i = 0; i < size && ++nComp; i++) {
            int curByte;
            if (byte + 1 == sizeof(int))
                curByte = ((a[i] >> (byte * step)) + CHAR_MAX + 1) & max;
            else
                curByte = (a[i] >> (byte * step)) & max;

            buffer[values[curByte]++] = a[i];
        }
        memcpy(a, buffer, sizeof(int) * size);
    }
    free(buffer);

    return nComp;
}