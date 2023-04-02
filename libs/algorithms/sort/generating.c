//
// Created by NTK on 26.03.2023.
//

#include "generating.h"

void generateRandomArray(int *a, size_t size) {
    srand(time(0));

    for (int i = 0; i < size; ++i)
        a[i] = INT_MIN / 2 + rand();
}

void generateOrderedArray(int *a, size_t size) {
    for (int i = 0; i < size; ++i)
        a[i] = i;
}

void generateOrderedBackwards(int *a, size_t size) {
    for (int i = size; i > 0; --i)
        a[i] = size - i;
}