#include "Matrix.h"
#include "Utilities.h"
#include <iostream>
#include <cmath>

// Constructor with dimensions and default value
Matrix::Matrix(int rows, int columns, int value)
    : rows(rows), columns(columns), matrix(nullptr) {
    if (rows < 0 || columns < 0) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    matrix = new int[rows * columns];
    for (int i = 0; i < rows * columns; ++i) {
        matrix[i] = value;
    }
}

// Default constructor
Matrix::Matrix() : rows(0), columns(0), matrix(new int[0]) {}

// Copy constructor
Matrix::Matrix(const Matrix& other)
    : rows(other.rows), columns(other.columns), matrix(new int[other.rows * other.columns]) {
    for (int i = 0; i < rows * columns; ++i) {
        matrix[i] = other.matrix[i];
    }
}

// Destructor
Matrix::~Matrix() {
    delete[] matrix;
}

// Assignment operator
Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;

    if (rows * columns != other.rows * other.columns) {
        delete[] matrix;
        matrix = new int[other.rows * other.columns];
    }

    rows = other.rows;
    columns = other.columns;

    for (int i = 0; i < rows * columns; ++i) {
        matrix[i] = other.matrix[i];
    }

    return *this;
}

// Element access operator
int& Matrix::operator()(int i, int j) {
    if (i < 0 || i >= rows || j < 0 || j >= columns) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return matrix[i * columns + j];
}

// Output operator
std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.columns; ++j) {
            os << "|" << matrix.matrix[i * matrix.columns + j];
        }
        os << "|\n";
    }
    return os;
}

// Arithmetic operators
Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || columns != other.columns) {
        exitWithError(MatamErrorType::UnmatchedSizes);
    }
    Matrix result(rows, columns);
    for (int i = 0; i < rows * columns; ++i) {
        result.matrix[i] = matrix[i] + other.matrix[i];
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || columns != other.columns) {
        exitWithError(MatamErrorType::UnmatchedSizes);
    }
    Matrix result(rows, columns);
    for (int i = 0; i < rows * columns; ++i) {
        result.matrix[i] = matrix[i] - other.matrix[i];
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (columns != other.rows) {
        exitWithError(MatamErrorType::NotSquareMatrix);
    }

    Matrix result(rows, other.columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.columns; ++j) {
            int sum = 0;
            for (int k = 0; k < columns; ++k) {
                sum += matrix[i * columns + k] * other.matrix[k * other.columns + j];
            }
            result.matrix[i * result.columns + j] = sum;
        }
    }
    return result;
}

// Compound assignment operators
Matrix& Matrix::operator+=(const Matrix& other) {
    *this = *this + other;
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    *this = *this - other;
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
    *this = *this * other;
    return *this;
}

// Scalar multiplication assignment operator
Matrix& Matrix::operator*=(int n) {
    for (int i = 0; i < rows * columns; ++i) {
        matrix[i] *= n;
    }
    return *this;
}

// Unary minus
Matrix Matrix::operator-() const {
    Matrix result(rows, columns);
    for (int i = 0; i < rows * columns; ++i) {
        result.matrix[i] = -matrix[i];
    }
    return result;
}

// Scalar multiplication (left and right)
Matrix operator*(int n, const Matrix& matrix) {
    Matrix result(matrix.rows, matrix.columns);
    for (int i = 0; i < matrix.rows * matrix.columns; ++i) {
        result.matrix[i] = matrix.matrix[i] * n;
    }
    return result;
}

Matrix operator*(const Matrix& matrix, int n) {
    return n * matrix;
}

// Logical comparison
bool Matrix::operator==(const Matrix& other) const {
    if (rows != other.rows || columns != other.columns) return false;
    for (int i = 0; i < rows * columns; ++i) {
        if (matrix[i] != other.matrix[i]) return false;
    }
    return true;
}

bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);
}

// Transformations
Matrix Matrix::rotateClockwise() const {
    Matrix result(columns, rows);
    int idx = 0;
    for (int j = 0; j < columns; ++j) {
        for (int i = rows - 1; i >= 0; --i) {
            result.matrix[idx++] = matrix[i * columns + j];
        }
    }
    return result;
}

Matrix Matrix::rotateCounterClockwise() const {
    Matrix result(columns, rows);
    int idx = 0;
    for (int j = columns - 1; j >= 0; --j) {
        for (int i = 0; i < rows; ++i) {
            result.matrix[idx++] = matrix[i * columns + j];
        }
    }
    return result;
}

Matrix Matrix::transpose() const {
    Matrix result(columns, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result.matrix[j * rows + i] = matrix[i * columns + j];
        }
    }
    return result;
}

// Frobenius norm
double Matrix::CalcFrobeniusNorm(const Matrix& matrix) {
    int sum = 0;
    for (int i = 0; i < matrix.rows * matrix.columns; ++i) {
        sum += matrix.matrix[i] * matrix.matrix[i];
    }
    return std::sqrt(sum);
}
