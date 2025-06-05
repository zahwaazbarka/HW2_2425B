#pragma once
#include <iostream>

class Matrix {
private:
    int rows;
    int columns; // the width
    int* matrix;

public:
    // Constructors and Destructor
    Matrix(int rows, int columns, int value = 0);
    Matrix();
    Matrix(const Matrix& matrix);
    ~Matrix();

    // Assignment and element access
    Matrix& operator=(const Matrix& matrix);
    int& operator()(int i, int j);

    // Output operator
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

    // Arithmetic operators (Matrix-Matrix)
    Matrix operator+(const Matrix& matrix) const;
    Matrix operator-(const Matrix& matrix) const;
    Matrix operator*(const Matrix& matrix) const;

    Matrix& operator+=(const Matrix& matrix);
    Matrix& operator-=(const Matrix& matrix);
    Matrix& operator*=(const Matrix& matrix);

    Matrix operator-() const;

    // Arithmetic operators (Matrix-Scalar)
    friend Matrix operator*(int n, const Matrix& matrix);
    friend Matrix operator*(const Matrix& matrix, int n);

    // Logical operators
    bool operator==(const Matrix& matrix) const;
    bool operator!=(const Matrix& matrix) const;

    // Transformations
    Matrix rotateClockwise() const;
    Matrix rotateCounterClockwise() const;
    Matrix transpose() const;

    // Norm
    static double CalcFrobeniusNorm(const Matrix& matrix);
};
