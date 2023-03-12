//
// Created by NTK on 19.02.2023.
//

#ifndef LABS_MATRIX_H

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;
typedef struct position {
    int rowIndex;
    int colIndex;
} position;

matrix getMemMatrix(int nRows, int nCols); // размещает в динамической памяти матрицу размером nRows на nCols. Возвращает матрицу.

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols); // размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols. Возвращает указатель на нулевую матрицу.

void freeMemMatrix(matrix *m); // освобождает память, выделенную под хранение матрицы m.

void freeMemMatrices(matrix *ms, int nMatrices); // освобождает память, выделенную под хранение массива ms из nMatrices матриц.

void inputMatrix(matrix *m); // ввод матрицы m.

void inputMatrices(matrix *ms, int nMatrices); // ввод массива из nMatrices матриц, хранящейся по адресу ms

void outputMatrix(matrix m); //  вывод матрицы m.

void outputMatrices(matrix *ms, int nMatrices); // вывод массива из nMatrices матриц, хранящейся по адресу ms.

void swapRows(matrix m, int i1, int i2); // обмен строк с порядковыми номерами i1 и i2 в матрице m. Помните, что для этого достаточно обменять указатели соответствующих строк:

#define LABS_MATRIX_H

#endif //LABS_MATRIX_H
