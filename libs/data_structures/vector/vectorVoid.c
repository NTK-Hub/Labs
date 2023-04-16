//
// Created by NTK on 19.02.2023.
//

#include "vectorVoid.h"

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    int *memory = malloc(baseTypeSize * n);
    if (memory == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    } else
        return (vectorVoid) {memory, 0, n, baseTypeSize};
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    v->data = (int *) realloc(v->data, v->baseTypeSize * newCapacity);

    if (newCapacity < v->size)
        v->size = newCapacity;

    v->capacity = newCapacity;

    if (newCapacity == 0)
        return;

    if (v->data == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    }
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
}

bool isEmptyV(vectorVoid *v) {
    return v->size == 0;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v, size_t index, void *destination) {
    char *source = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    char *destination = (char *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void popBackV(vectorVoid *v) {
    if (isEmptyV(v)) {
        fprintf(stderr, "is empty");
        exit(1);
    } else
        v->size--;
}

void pushBackV(vectorVoid *v, void *source) {
    if (isFullV(v) && isEmptyV(v))
        reserveV(v, 1);
    else if (isFullV(v))
        reserveV(v, 2 * v->capacity);

    setVectorValueV(v, v->size, source);
    v->size++;
}