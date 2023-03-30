//
// Created by NTK on 19.02.2023.
//

#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "matrix.h"
#include "../../algorithms/algorithm.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(nRows * sizeof(int *));

    if (values == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    for (int i = 0; i < nRows; i++) {
        values[i] = (int *) malloc(sizeof(int) * nCols);
        if (values[i] == NULL) {
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    }
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(nMatrices * sizeof(matrix));
    if (ms == NULL) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);

    return ms;
}

void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++)
        free(m->values[i]);
    free(m->values);
    m->values = NULL;
    m->nRows = 0;
    m->nCols = 0;
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(&ms[i]);
    free(ms);
}

void inputMatrix(matrix m) {
    for (int rIndex = 0; rIndex < m.nRows; rIndex++) {
        for (int cIndex = 0; cIndex < m.nCols; cIndex++) {
            scanf("%d", &m.values[rIndex][cIndex]);
        }
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        inputMatrix(ms[i]);
    }
}

void outputMatrix(matrix m) {
    for (int rIndex = 0; rIndex < m.nRows; rIndex++) {
        for (int cIndex = 0; cIndex < m.nCols; cIndex++) {
            printf("%d ", m.values[rIndex][cIndex]);
        }
        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        outputMatrix(ms[i]);
    }
}

void swapRows(matrix m, int i1, int i2) {
    assert(i1 < m.nRows && i2 < m.nRows);

    universalSwap(&m.values[i1], &m.values[i2], sizeof(int *));
}

void swapColumns(matrix m, int j1, int j2) {
    assert(j1 < m.nCols && j2 < m.nCols);

    for (int rIndex = 0; rIndex < m.nRows; rIndex++) {
        universalSwap(&m.values[rIndex][j1], &m.values[rIndex][j2], sizeof(int));
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int *rows = (int *) malloc(sizeof(int) * m.nRows);

    for (int rIndex = 0; rIndex < m.nRows; ++rIndex)
        rows[rIndex] = criteria(m.values[rIndex], m.nCols);

    for (int rIndex = 1; rIndex < m.nRows; ++rIndex) {
        int curIndex = rIndex;
        while (curIndex > 0 && rows[curIndex] < rows[curIndex - 1]) {
            swapRows(m, curIndex, curIndex - 1);
            universalSwap(&rows[curIndex], &rows[curIndex - 1], sizeof(int));
            curIndex--;
        }
    }
}

void insertionSortRowsMatrixByRowCriteriaFloat(matrix m, float (*criteria)(int *, int)) {
    float *rows = (float *) malloc(sizeof(float ) * m.nRows);

    for (int rIndex = 0; rIndex < m.nRows; ++rIndex)
        rows[rIndex] = criteria(m.values[rIndex], m.nCols);

    for (int rIndex = 1; rIndex < m.nRows; ++rIndex) {
        int curIndex = rIndex;
        while (curIndex > 0 && rows[curIndex] < rows[curIndex - 1]) {
            swapRows(m, curIndex, curIndex - 1);
            universalSwap(&rows[curIndex], &rows[curIndex - 1], sizeof(int));
            curIndex--;
        }
    }
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int *cols = (int *) malloc(sizeof(int) * m.nCols);
    int *curCols = malloc(sizeof(int) * m.nRows);

    for (int cIndex = 0; cIndex < m.nCols; ++cIndex) {
        for (int rIndex = 0; rIndex < m.nRows; ++rIndex) {
            curCols[rIndex] = m.values[rIndex][cIndex];
        }
        cols[cIndex] = criteria(curCols, m.nRows);
    }

    for (int cIndex = 1; cIndex < m.nCols; ++cIndex) {
        int curIndex = cIndex;
        while (curIndex > 0 && cols[curIndex] < cols[curIndex - 1]) {
            swapColumns(m, curIndex, curIndex - 1);
            universalSwap(&cols[curIndex], &cols[curIndex - 1], sizeof(int));
            curIndex--;
        }
    }
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool areTwoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;

    for (int rIndex = 0; rIndex < m1.nRows; rIndex++) {
        for (int cIndex = 0; cIndex < m1.nCols; ++cIndex) {
            if (m1.values[rIndex][cIndex] != m2.values[rIndex][cIndex])
                return false;
        }
    }
    return true;
}

bool isEMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;

    for (int rIndex = 0; rIndex < m.nRows; rIndex++) {
        for (int cIndex = 0; cIndex < m.nCols; ++cIndex) {
            if (rIndex == cIndex && m.values[rIndex][cIndex] != 1
                || rIndex != cIndex && m.values[rIndex][cIndex] != 0)
                return false;
        }
    }
    return true;
}

bool isSymmetricMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;

    for (int rIndex = 0; rIndex < m.nRows; rIndex++) {
        for (int cIndex = 0; cIndex < m.nCols; cIndex++) {
            int rowsIndex = cIndex;
            int colsIndex = rIndex;

            if (m.values[rIndex][cIndex] != m.values[rowsIndex][colsIndex])
                return false;
        }
    }
    return true;
}

void transposeSquareMatrix(matrix m) {
    assert(isSquareMatrix(m));

    for (int rIndex = 0; rIndex < m.nRows; ++rIndex) {
        for (int cIndex = 0; cIndex < rIndex; ++cIndex) {
            if (rIndex != cIndex)
                universalSwap(&m.values[rIndex][cIndex], &m.values[cIndex][rIndex], sizeof(int));
        }
    }
}

void transposeMatrix(matrix *m) {
    matrix newMatrix = getMemMatrix(m->nCols, m->nRows);

    for (int i = 0; i < m->nRows; i++)
        for (int j = 0; j < m->nCols; j++)
            newMatrix.values[j][i] = m->values[i][j];

    freeMemMatrix(m);
    *m = newMatrix;
}

position getMinValuePos(matrix m) {
    position minValuePos = {0, 0};

    for (int rIndex = 0; rIndex < m.nRows; rIndex++) {
        for (int cIndex = 0; cIndex < m.nCols; cIndex++) {
            position currentPos = {rIndex, cIndex};
            if (m.values[currentPos.rowIndex][currentPos.colIndex] <
                m.values[minValuePos.rowIndex][minValuePos.colIndex])
                minValuePos = currentPos;
        }
    }
    return minValuePos;
}

position getMaxValuePos(matrix m) {
    position maxValuePos = {0, 0};

    for (int rIndex = 0; rIndex < m.nRows; rIndex++) {
        for (int cIndex = 0; cIndex < m.nCols; cIndex++) {
            position currentPos = {rIndex, cIndex};
            if (m.values[currentPos.rowIndex][currentPos.colIndex] >
                m.values[maxValuePos.rowIndex][maxValuePos.colIndex])
                maxValuePos = currentPos;
        }
    }
    return maxValuePos;
}

matrix createMatrixFromArray(const int *a, int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int rIndex = 0; rIndex < nRows; rIndex++)
        for (int cIndex = 0; cIndex < nCols; cIndex++)
            m.values[rIndex][cIndex] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values, int nMatrices, int nRows, int nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int rIndex = 0; rIndex < nRows; rIndex++)
            for (int cIndex = 0; cIndex < nCols; cIndex++)
                ms[k].values[rIndex][cIndex] = values[l++];

    return ms;
}

matrix mulMatrices(matrix m1, matrix m2) {
    matrix mulMatrix = getMemMatrix(m1.nRows, m2.nCols);

    for (int i = 0; i < m1.nRows; ++i) {
        for (int j = 0; j < m2.nCols; ++j) {
            mulMatrix.values[i][j] = 0;
            for (int k = 0; k < m1.nCols; ++k) {
                mulMatrix.values[i][j] += m1.values[i][k] * m2.values[k][j];
            }
        }
    }
    return mulMatrix;
}