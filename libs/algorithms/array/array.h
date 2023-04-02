//
// Created by NTK on 19.02.2023.
//

#ifndef LABS_ARRAY_H
#define LABS_ARRAY_H

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

//
int compare_ints(const void *a, const void *b);

//
int cmp_long_long(const void *pa, const void *pb);

//
int countNUnique(long long *a, int n);

//сортировка вставкой
void insertionSort(int *a, const size_t size);

//ввод массива data размера n
void inputArray_(int *a, size_t n);

// вывод массива data размера n
void outputArray_(const int *a, size_t n);

// возвращает значение первого вхождения элемента x
// в массиве a размера n при его наличии, иначе - n
size_t linearSearch_(const int *a, const size_t n, int x);

// возвращает позицию вхождения элемента x
// в отсортированном массиве a размера n при его наличии, иначе -1
size_t binarySearch(const int *a, size_t n, int x);

// возвращает позицию первого элемента равного или большего x
// в отсортированном массиве a размера n
// при отсутствии такого элемента возвращает n
size_t binarySearchMoreOrEqual_(const int *a, const size_t n, int x);

// вставка элемента со значением value
// в массив data размера n на позицию pos
void insert_(int *a, size_t *n, size_t pos, int value);

// добавление элемента value в конец массива data размера n
void append_(int *a, size_t *n, int value);

// удаление из массива data размера n элемента на позиции pos
// с сохранением порядка оставшихся элементов
void deleteByPosSaveOrder_(int *a, size_t *n, size_t pos);

// удаление из массива data размера n элемента на позиции pos
// без сохранения порядка оставшихся элементов
// размер массива data уменьшается на единицу
void deleteByPosUnsaveOrder_(int *a, size_t *n, size_t pos);

// возвращает позицию последнего элемента меньшего или равного x
// (вернёт -1, если все числа больше x)
int binarySearchLessOrEqual(const int *a, size_t n, int x);

// возвращает значение ’истина’ если все элементы
// массива data размера n соответствует функции-предикату predicate
// иначе - ’ложь’
int all_(const int *a, size_t n, int (*predicate )(int));

// возвращает значение ’истина’ если хотя бы один элемент
// массива data размера n соответствует функции-предикату predicate
// иначе - ’ложь’
int any_(const int *a, size_t n, int (*predicate )(int));

// применяет функцию predicate ко всем элементам массива source
// размера n и сохраняет результат в массиве dest размера n
void forEach_(const int *source, int *dest, size_t n, const int (*
predicate )(int));

// возвращает количество элементов массива data размера n
// удовлетворяющих функции-предикату predicate
int countIf_(const int *a, size_t n, int (*predicate )(int));

// удаляет из массива data размера n все элементы, удовлетворяющие
// функции-предикату deletePredicate, записывает в n новый размер
// массива
void deleteIf_(int *a, size_t *n, int (*deletePredicate )(int));

//возвращает индекс i элемента со значением x с начала массива а размера n, если элемент найден, иначе: -1
int getPositionithGivenValue(const int *a, const size_t n, const int x);

//возвращает индекс i первого отрицательного элемента массива а размера n, если элемент найден, иначе: -1
int findFirsNegativeIndex(const int *a, const size_t n);

//возвращает индекс i элемента с начала массива а размера n (по функции-предикату) f, если элемент найден, иначе: -1
int findIndexIf(const int *a, const size_t n, int (*f)(int));

//возвращает индекс i последнего чётного элемента массива a размера  n если элемент найден, иначе: -1
int findLastEvenIndex(const int *a, const size_t n);


//возвращает индекс i элемента с конца массива а размера n (по функции-предикату) f, если элемент найден, иначе: -1
int findIndexLastIf(const int *a, const size_t n, int (*f)(int));

//возвращает количество отрицательных элементов в массиве a размера n
int getNegativeCount(const int *a, const size_t n);

//возвращает количество элементов массива a размера n, удовлетворяющих функции f
int getCountIf(const int *a, const size_t n, int (*f)(int));

//обменивает значения по адресам переменных a и b
void swap(int *a, int *b);

//изменяет порядок элементов массива a размера n на обратный
void reverseArray(int *a, size_t n);

//возвращает "истина", если последовательность является паминдромом, иначе "ложь"
int isPalindrom(const int *a, const size_t n);

//сортировка выбором массива a размераом n
void sortChoice(int *a, size_t n);

//удаляет из массива a размера n все нечётные элементы
void removeAllOddElements(int *a, size_t *n);

//вставляет элемент x  в позицию pos массива a размера n с сохранением относительного порядка других элементов
void insertAnElement(int *a, size_t *n, size_t pos, int x);


//удаляет элемент x на позиции pos из массива a размером n с сохранением относительного порядка других элементов
void deleteByPosSaveOrder(int *a, size_t *n, const size_t pos);

//удаляет элемент x на позиции pos из массива a размером n без сохранения порядка элементов
void deleteByPosUnsaveOrder(int *a, size_t *n, size_t pos);

//применяет функцию f к элементам массива a размера size
void forEach(int *a, const size_t size, void (*f)(int *));

//возвращает значение "истина", если хотя бы один из элементов массива a размера size удовлетворяет условию функции-предикату f, иначе - "ложь"
int any(const int *a, const size_t size, int (*f)(int));

//возвращает значение "истина", если все элементы массива a размера size удовлетворяют условию функции-предикату f, иначе - "ложь"
int all(const int *a, const size_t size, int (*f)(int));

//разделяет элементы массива a размера sizeA на элементы, удовлетворяющие функции-предикату f, сохраняя в массиве b размера sizeB, иначе - в массиве c размера sizeC
void arraySplit(const int *a, size_t sizeA, int *b, size_t *sizeB, int *c, size_t *sizeC, int (*pred )(int));

size_t linearSearchFirstMaxIndex(const int *a, const size_t n);

int linearSearchMax(const int *a, const size_t n);

size_t linearSearchLastMinIndex(const int *a, const size_t n);

int linearSearchMin(const int *a, const size_t n);

long long getSum(const int *a, const size_t n);

bool isUniqueArray(const int *a, const size_t n);

float getDistance(int *a, int n);

bool isNonDescendingSorted(int *a, int n);

int countValues(const int *a, int n, int value);

int maximum(int a, int b);

bool isOrdered(int *a, size_t n);

#endif //LABS_ARRAY_H
