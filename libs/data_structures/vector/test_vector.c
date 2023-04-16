//
// Created by NTK on 19.02.2023.
//

#include <assert.h>
#include "vector.h"
#include "test_vector.h"

void test_createVector() {
    vector v = createVector(7);

    assert(v.size == 0);
    assert(v.capacity == 7);

    deleteVector(&v);
}

void test_createZeroVector() {
    vector v = createVector(0);

    assert(v.size == 0);
    assert(v.capacity == 0);

    deleteVector(&v);
}

void test_reserve1() {
    vector v = createVector(7);
    v.size = 5;
    reserve(&v, 6);

    assert(v.size == 5);
    assert(v.capacity == 6);

    deleteVector(&v);
}

void test_reserve2() {
    vector v = createVector(7);
    v.size = 5;
    reserve(&v, 4);

    assert(v.size == 4);
    assert(v.capacity == 4);

    deleteVector(&v);
}

void test_reserve() {
    test_reserve1();
    test_reserve2();
}

void test_shrinkToFit() {
    vector v = createVector(4);
    v.size = 2;
    shrinkToFit(&v);

    assert(v.size == v.capacity);

    deleteVector(&v);
}

void test_isEmpty() {
    vector v = createVector(4);

    assert(isEmpty(&v));

    deleteVector(&v);
}

void test_isFull() {
    vector v = createVector(4);
    v.size = 4;

    assert(isFull(&v));

    deleteVector(&v);
}

void test_getVectorValue1() {
    vector v = createVector(4);
    v.data[2] = 45;

    assert(getVectorValue(&v, 2) == v.data[2]);

    deleteVector(&v);
}

void test_getVectorValue2() {
    vector v = createVector(10);
    v.data[10] = 12;

    assert(getVectorValue(&v, 10) == v.data[10]);

    deleteVector(&v);
}

void test_getVectorValue3() {
    vector v = createVector(5);
    *v.data = 1;

    assert(getVectorValue(&v, 0) == *v.data);

    deleteVector(&v);
}

void test_getVectorValue() {
    test_getVectorValue1();
    test_getVectorValue2();
    test_getVectorValue3();
}

void test_pushBack_emptyVector() {
    vector v = createVector(10);
    pushBack(&v, 15);

    assert(*v.data == 15);
    assert(v.size == 1);
    assert(v.capacity == 10);

    deleteVector(&v);
}

void test_pushBack_fullVector() {
    vector v = createVector(4);
    v.size = 4;
    pushBack(&v, 1);

    assert(v.data[4] == 1);
    assert(v.size == 5);
    assert(v.capacity == 8);

    deleteVector(&v);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert (v.size == 1);
    popBack(&v);

    assert (v.size == 0);
//    printf("%zu", v.capacity);
    assert (v.capacity == 1);

    deleteVector(&v);
}

void test_atVector_notEmptyVector() {
    vector v = createVector(5);
    v.size = 3;

    assert(atVector(&v, 2) == &v.data[2]);

    deleteVector(&v);
}

void test_atVector_requestToLastElement1() {
    vector v = createVector(5);

    assert(atVector(&v, 5) == &v.data[5]);

    deleteVector(&v);
}

void test_atVector_requestToLastElement2() {
    vector v = createVector(5);

    assert(atVector(&v, 0) == v.data);

    deleteVector(&v);
}

void test_atVector_requestToLastElement() {
    test_atVector_requestToLastElement1();
    test_atVector_requestToLastElement2();
}

void test_back_oneElementInVector() {
    vector v = createVector(1);
    v.size = 1;

    assert(back(&v) == v.data);

    deleteVector(&v);
}

void test_front_oneElementInVector() {
    vector v = createVector(1);

    assert(front(&v) == v.data);

    deleteVector(&v);
}

void test_back() {
    vector v = createVector(7);
    v.size = 6;

    assert(back(&v) == &v.data[5]);

    deleteVector(&v);
}

void test_front() {
    vector v = createVector(6);

    v.size = 5;

    assert(front(&v) == v.data);

    deleteVector(&v);
}

void testVector() {
    test_createVector();
    test_createZeroVector();
    test_reserve();
    test_shrinkToFit();
    test_isEmpty();
    test_isFull();
    test_getVectorValue();
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
    test_back();
    test_front();
}