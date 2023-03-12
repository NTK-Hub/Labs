//
// Created by NTK on 19.02.2023.
//

#ifndef LABS_ARRAY_H
#define LABS_ARRAY_H

#include <stddef.h>
#include <stdbool.h>

// ввод массива data размера n
void inputArray_(int *a, size_t n);

// вывод массива data размера n
void outputArray_(const int *a, size_t n);

// возвращает значение первого вхождения элемента x
// в массиве a размера n при его наличии, иначе - n
size_t linearSearch(const int *a, const size_t n, int x);

// возвращает позицию вхождения элемента x
// в отсортированном массиве a размера n при его наличии, иначе - SIZE_MAX
size_t binarySearch_(const int *a, const size_t n, int x);

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

// возвращает значение ’истина’ если все элементы
// массива data размера n соответствует функции-предикату predicate
// иначе - ’ложь’
int all_(const int *a, size_t n, int (*predicate )(int));

// возвращает значение ’истина’ если хотя бы один элемент
// массива data размера n соответствует функции-предикату predicate
// иначе - ’ложь’
int any_(const int *a, size_t n, int (*predicate )(int));

// применяет функцию func ко всем элементам массива source
// размера n и сохраняет результат в массиве dest размера n
void forEach(const int *source, int *dest, size_t n, const int (*func)(int));

// возвращает количество элементов массива data размера n
// удовлетворяющих функции-предикату predicate
int countIf_(const int *a, size_t n, int (*predicate )(int));

// удаляет из массива data размера n все элементы, удовлетворяющие
// функции-предикату deletePredicate, записывает в n новый размер
// массива
void deleteIf_(int *a, size_t *n, int (*deletePredicate )(int));

//Объявление типа множество:
typedef struct unordered_array_set {
    int *data; // элементы множества
    size_t size; // количество элементов в множестве
    size_t capacity; // максимальное количество элементов в множестве
} unordered_array_set;

//Для создания множества будем пользоваться двумя функциями. Первая возвращает множество, заданного размера:
unordered_array_set unordered_array_set_create(size_t capacity);

//Вторая функция создаёт множество из элементов одномерного массива a размера size:
unordered_array_set unordered_array_set_create_from_array(const int *a, size_t size);

static void unordered_array_set_shrinkToFit(unordered_array_set *a);

//comp - указатель на функцию-компаратор, которая возвращает отрицательное
//целое значение, если первый аргумент меньше второго аргумента, положительное значение,
//если первый аргумент больше второго и ноль, если аргументыравны.
int compare_ints(const void* a, const void* b);

int unordered_array_set_isEqual(unordered_array_set set1, unordered_array_set set2);

int unordered_array_set_in(unordered_array_set *set, int value);

void unordered_array_set_isAbleAppend(unordered_array_set *set);

void unordered_array_set_insert(unordered_array_set *set, int value);

// Возвращает значение "истина", если массив a размера n
// не содержит повторяющихся элементов
bool isUnique(const int *const a, int n);

// Обмен переменных по адресам a и b
void swap(int *a, int *b);

// Сортировка элементов массива a размера n по невозрастанию
void selectionSortDecr(int *const a, int n);

// возвращает индекс первого максимального элемента в массиве a размера n
int getIndexOfFirstMax(const int *const a, int n);

// возвращает индекс последнего минимального элемента в массиве a размера n
int getIndexOfLastMin(const int *const a, int n);

// Сортировка элементов массива a размера n по неубыванию
void selectionSort(int *const a, int n);

// Сортировка элементов массива a по неубыванию, начиная с позиции start
// включительно, заканчивая позицией end (невключительно).
void selectionSortInterval(int *a, int start, int end);

// Возвращает значение "истина" если массив a размера n
// упорядочен по неубыванию, "ложь" - в противном случае.
bool isNonDecreasing(const int *const a, int n);

// Возвращает значение "истина" если массив a размера n
// упорядочен по невозрастанию, "ложь" - в противном случае.
bool isNonIncreasing(const int *const a, int n);

// Возвращает значение "истина" если массив a размера n
// упорядочен по невозрастанию или неубыванию или все элементы равны,
// "ложь" - в противном случае.
bool isSorted(const int *const a, int n);

// Возвращает среднее геометрическое положительных элементов
// массива a размера n. Если положительные элементы отсутствуют,
// возвращает 0
double getGeometricMeanOfPositiveElements(const int * const a, int n);

// В силу того, что нам нужно куда-то записать размер получившегося массива,
// в функцию передаётся адрес переменной, в которую нужно записать
// ответ (параметр int *cSize)
// Записывает по адресу c все элементы массива a размера n
// которых нет в массиве b размера m в порядке невозрастания.
// Записывает по адресу cSize количество элементов в массиве с
void combine(int *a, int n, int *b, int m, int *c, int *cSize);

// Возвращает позицию первого вхождения неотрицательного элемента
// в массив a размера n, если такой элемент есть.
// В противном случае возвращает -1.
int getIndexOfFirstNonNegative(const int * const a, int n);

// Изменяет порядок следования элементов в массиве a
// размера n на обратный.
void reverseArray(int * const a, int n);

// Записывает в lowerBound и upperBound элементы последовательности,
// ближайшие к x снизу и сверху, если элемента со значением x нет в массиве.
// Если ближайших элементов нет, записывает значения
// INT_MIN и INT_MAX соответственно
// В противном случае записывает значения x по адресам lowerBound и upperBound.
void getNearestElements(const int * const a, int n, int x, int *lowerBound, int *upperBound);

// Записывает по адресу destination отсортированные элементы из массива
// source размера size, где каждое значение взято один раз.
// Записывает по адресу sizeB количество элементов в массиве destination
void arrayToSet(int *source, int size, int *destination, int *sizeB);

// Возвращает значение "истина", если вещественные числа
// a и b можно считать равными на основании абсолютной погрешности
bool isEqual(double a, double b);

// Возвращает значение "истина", если элементы массива a
// размера n составляют геометрическую прогрессию,
// в противном случае -- "ложь"
bool isGeometricProgression(int *a, int n);

// Возвращает сумму четных цифр числа x
// Если число отрицательное, возвращает значение 0
int getSumOfEvenDigitsOfPositiveNumber(int x);

// Возвращает сумму элементов массива a размера n
long long getSum(const int * const a, int n);





#endif //LABS_ARRAY_H
