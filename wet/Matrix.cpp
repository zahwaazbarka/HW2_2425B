#include "Matrix.h"
#include "Utilities.h"
#include <iostream>
#include <cmath>

Matrix::Matrix(const int rows, const int columns, const int value)
    : rows(rows), columns(columns), matrix(nullptr) {
    if (rows < 0 || columns < 0) {
        exitWithError(MatamErrorType::OutOfBounds);
    }

    matrix = new int[rows * columns];
    for (int i = 0; i < rows * columns; i++) {
        matrix[i] = value;
    }
}

Matrix::Matrix()
    : rows(0), columns(0), matrix(new int[0]) {}

Matrix::Matrix(const Matrix &other)
    : rows(other.rows), columns(other.columns), matrix(new int[other.rows * other.columns]) {
    for (int i = 0; i < rows * columns; i++) {
        matrix[i] = other.matrix[i];
    }
}
