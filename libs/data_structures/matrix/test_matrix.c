//
// Created by NTK on 30.03.2023.
//

#include "matrix.h"
#include <assert.h>

void test_getMemMatrix() {
    int n = 3;
    int testMatrix[][2] = {
            {3, 6},
            {4, 2},
            {0, 1}
    };

    for (int i = 0; i < n; ++i) {
        int nRows = testMatrix[i][0];
        int nCols = testMatrix[i][1];
        matrix m = getMemMatrix(nRows, nCols);

        assert(m.nRows == nRows);
        assert(m.nCols == nCols);

        freeMemMatrix(&m);
    }
}

void test_swapRows1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    5, 2, 9,
                    7, 1, 0,
                    22, 3, 11
            },
            3, 3);
    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    7, 1, 0,
                    5, 2, 9,
                    22, 3, 11
            },
            3, 3);
    swapRows(testMatrix, 0, 1);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(&testMatrix);
    freeMemMatrix(&endMatrix);
}

void test_swapRows2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    5, 2, 9,
                    7, 1, 0,
                    22, 3, 11
            },
            3, 3);
    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    5, 2, 9,
                    22, 3, 0,
                    7, 1, 0
            },
            3, 3);

    swapRows(testMatrix, 1, 2);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(&testMatrix);
    freeMemMatrix(&endMatrix);
}

void test_swapRows3() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    5, 2, 9,
                    7, 1, 0,
                    22, 3, 11
            },
            3, 3);
    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    22, 3, 11,
                    7, 1, 0,
                    5, 2, 9,
            },
            3, 3);
    swapRows(testMatrix, 0, 2);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(&testMatrix);
    freeMemMatrix(&endMatrix);
}

void test_swapRows() {
    test_swapRows1();
    test_swapRows2();
    test_swapRows3();
}

void test_swapColumns1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    5, 2, 9,
                    7, 1, 0,
                    22, 3, 11
            },
            3, 3);
    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    9, 2, 5,
                    0, 1, 7,
                    11, 3, 22
            },
            3, 3);
    swapColumns(testMatrix, 0, 2);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(&testMatrix);
    freeMemMatrix(&endMatrix);
}

void test_swapColumns2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    5, 2, 9,
                    7, 1, 0,
                    22, 3, 11
            },
            3, 3);
    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    2, 9, 5,
                    1, 0, 7,
                    22, 11, 3
            },
            3, 3);
    swapColumns(testMatrix, 1, 2);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(&testMatrix);
    freeMemMatrix(&endMatrix);
}

void test_swapColumns3() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    5, 2, 9,
                    7, 1, 0,
                    22, 3, 11
            },
            3, 3);
    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    2, 5, 9,
                    7, 1, 0,
                    3, 22, 11
            },
            3, 3);
    swapColumns(testMatrix, 0, 1);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(&testMatrix);
    freeMemMatrix(&endMatrix);
}

void test_swapColumns() {
    test_swapColumns1();
    test_swapColumns2();
    test_swapColumns3();
}

void test_isSquareMatrix1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    5, 2, 9,
                    7, 1, 0,
                    22, 3, 11
            },
            3, 3);
    assert(isSquareMatrix(testMatrix));

    freeMemMatrix(&testMatrix);
}

void test_isSquareMatrix2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 5, 7,
                    1, 2, 7, 8,
                    7, 0, 1, 3,
                    4, 6, 3, 4
            },
            4, 4);
    assert(isSquareMatrix(testMatrix));

    freeMemMatrix(&testMatrix);

}

void test_isSquareMatrix() {
    test_isSquareMatrix1();
    test_isSquareMatrix2();
}

void test_areTwoMatricesEqual1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    5, 2, 9,
                    7, 1, 0,
                    22, 3, 11
            },
            3, 3);
    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    5, 2, 9,
                    1, 7, 0,
                    22, 3, 11
            },
            3, 3);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(&testMatrix);
    freeMemMatrix(&endMatrix);
}

void test_areTwoMatricesEqual2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    1, 4, 7, 9,
                    2, 4, 6, 4
            },
            2, 4);
    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    1, 4, 7, 9,
                    2, 4, 6, 4
            },
            2, 4);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(&testMatrix);
    freeMemMatrix(&endMatrix);
}

void test_areTwoMatricesEqual() {
    test_areTwoMatricesEqual1();
    test_areTwoMatricesEqual2();
}

void test_isEMatrix() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            },
            3, 3);
    assert(isEMatrix(testMatrix));

    freeMemMatrix(&testMatrix);
}

void test_isSymmetricMatrix1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    4, 1, 3,
                    1, 2, 0,
                    3, 0, 5
            },
            3, 3);

    assert(isSymmetricMatrix(testMatrix));

    freeMemMatrix(&testMatrix);
}

void test_isSymmetricMatrix2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    2
            },
            1, 1);

    assert(isSymmetricMatrix(testMatrix));

    freeMemMatrix(&testMatrix);
}

void test_isSymmetricMatrix3() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    2, 3
            },
            2, 2);

    assert(isSymmetricMatrix(testMatrix));

    freeMemMatrix(&testMatrix);

}

void test_isSymmetricMatrix() {
    test_isSymmetricMatrix1();
    test_isSymmetricMatrix2();
    test_isSymmetricMatrix3();
}

void test_transposeSquareMatrix1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    1, 5, 27,
                    6, 85, 6,
                    8, 6, 8
            },
            3, 3);
    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    1, 6, 8,
                    5, 85, 6,
                    27, 6, 8
            },
            3, 3);
    transposeSquareMatrix(testMatrix);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(&testMatrix);
    freeMemMatrix(&endMatrix);
}

void test_transposeSquareMatrix2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3, 0,
                    4, -6
            },
            2, 2);
    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    3, 4,
                    0, -6
            },
            2, 2);
    transposeSquareMatrix(testMatrix);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(&testMatrix);
    freeMemMatrix(&endMatrix);
}

void test_transposeSquareMatrix3() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3, 6, -9,
                    -4, 0, 6,
                    22, 5, 44
            },
            3, 3);
    matrix endMatrix = createMatrixFromArray(
            (int[]) {
                    3, -4, 22,
                    6, 0, 5,
                    -9, 6, 44
            },
            3, 3);
    transposeSquareMatrix(testMatrix);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(&testMatrix);
    freeMemMatrix(&endMatrix);
}

void test_transposeSquareMatrix() {
    test_transposeSquareMatrix1();
    test_transposeSquareMatrix2();
    test_transposeSquareMatrix3();
}

void test_transposeMatrix1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {1, 2, 3,
                       5, 0, 6
            },
            2, 3);
    matrix endMatrix = createMatrixFromArray(
            (int[]) {1, 5,
                       2, 3,
                       4, 7
                       },
            3, 2);
    transposeMatrix(&testMatrix);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(&testMatrix);
    freeMemMatrix(&endMatrix);
}

void test_transposeMatrix2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {3, 2, 3,
                     5, 0, 6
            },
            2, 3);
    matrix endMatrix = createMatrixFromArray(
            (int[]) {3, 5,
                     2, 3,
                     4, 7
            },
            3, 2);
    transposeMatrix(&testMatrix);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(&testMatrix);
    freeMemMatrix(&endMatrix);
}

void test_transposeMatrix3() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {1, 2, 3,
                     55, 0, 6
            },
            2, 3);
    matrix endMatrix = createMatrixFromArray(
            (int[]) {1, 55,
                     2, 3,
                     4, 7
            },
            3, 2);
    transposeMatrix(&testMatrix);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(&testMatrix);
    freeMemMatrix(&endMatrix);
}

void test_transposeMatrix(){
    test_transposeMatrix1();
    test_transposeMatrix2();
    test_transposeMatrix3();
}

void test_getMinValuePos1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3, 6, -9,
                    -4, 0, 6,
                    22, 5, 44
            },
            3, 3);
    position pos = getMinValuePos(testMatrix);
    position minVauePos = {0, 2};

    assert(pos.rowIndex == minVauePos.rowIndex && pos.colIndex == minVauePos.colIndex);

    freeMemMatrix(&testMatrix);
}

void test_getMinValuePos2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3, 6, 0,
                    -4, -9, 6,
                    22, 5, 44
            },
            3, 3);
    position pos = getMinValuePos(testMatrix);
    position minVauePos = {1, 1};

    assert(pos.rowIndex == minVauePos.rowIndex && pos.colIndex == minVauePos.colIndex);

    freeMemMatrix(&testMatrix);
}

void test_getMinValuePos3() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3, 6, 0,
                    -4, 9, 6,
                    22, 5, 44
            },
            3, 3);
    position pos = getMinValuePos(testMatrix);
    position minVauePos = {2, 2};

    assert(pos.rowIndex == minVauePos.rowIndex && pos.colIndex == minVauePos.colIndex);

    freeMemMatrix(&testMatrix);
}

void test_getMinValuePos4() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3, 6, 0,
                    -4, 9, 6,
                    22, 5, -44
            },
            3, 3);
    position pos = getMinValuePos(testMatrix);
    position minVauePos = {2, 0};

    assert(pos.rowIndex == minVauePos.rowIndex && pos.colIndex == minVauePos.colIndex);

    freeMemMatrix(&testMatrix);
}

void test_getMinValuePos() {
    test_getMinValuePos1();
    test_getMinValuePos2();
    test_getMinValuePos3();
    test_getMinValuePos4();
}

void test_getMaxValuePos1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3, 6, 0,
                    -4, 9, 6,
                    -22, 5, 44
            },
            3, 3);
    position pos = getMaxValuePos(testMatrix);
    position maxVauePos = {2, 2};

    assert(pos.rowIndex == maxVauePos.rowIndex && pos.colIndex == maxVauePos.colIndex);

    freeMemMatrix(&testMatrix);
}

void test_getMaxValuePos2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3, 6, 0,
                    -4, 999, 6,
                    22, 5, 44
            },
            3, 3);
    position pos = getMaxValuePos(testMatrix);
    position maxVauePos = {0, 1};

    assert(pos.rowIndex == maxVauePos.rowIndex && pos.colIndex == maxVauePos.colIndex);

    freeMemMatrix(&testMatrix);
}

void test_getMaxValuePos3() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3, 6, 0,
                    -4, 9, 6,
                    -22, 5, -44
            },
            3, 3);
    position pos = getMaxValuePos(testMatrix);
    position maxVauePos = {2, 0};

    assert(pos.rowIndex == maxVauePos.rowIndex && pos.colIndex == maxVauePos.colIndex);

    freeMemMatrix(&testMatrix);
}

void test_getMaxValuePos4() {
    matrix testMatrix = createMatrixFromArray(
            (int[]) {
                    3, 6, 0,
                    -4, -9, 6,
                    222, 55, 44
            },
            3, 3);
    position pos = getMaxValuePos(testMatrix);
    position maxVauePos = {1, 2};

    assert(pos.rowIndex == maxVauePos.rowIndex && pos.colIndex == maxVauePos.colIndex);

    freeMemMatrix(&testMatrix);
}

void test_getMaxValuePos() {
    test_getMaxValuePos1();
    test_getMaxValuePos2();
    test_getMaxValuePos3();
    test_getMaxValuePos4();
}

void test_matrix() {
    test_getMemMatrix();
    test_swapRows();
    test_swapColumns();
    test_isSquareMatrix();
    test_areTwoMatricesEqual();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_transposeMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
}