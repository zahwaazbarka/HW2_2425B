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
    ~Matrix() { delete[] matrix; }

    // Assignment and element access
    Matrix& operator=(const Matrix& matrix);
    int& operator()(int i, int j);

    // Output operator
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

    // Arithmetic operators (Matrix-Matrix) - return by value, const versions
    Matrix operator+(const Matrix& matrix) const;
    Matrix operator-(const Matrix& matrix) const;
    Matrix operator*(const Matrix& matrix) const;

    // Compound assignment operators - return by reference
    Matrix& operator+=(const Matrix& matrix);
    Matrix& operator-=(const Matrix& matrix);
    Matrix& operator*=(const Matrix& matrix);

    // Unary minus - const version
    Matrix operator-() const;

    // Arithmetic operators (Matrix-Scalar)
    friend Matrix operator*(int n, const Matrix& matrix);
    friend Matrix operator*(const Matrix& matrix, int n);
    Matrix& operator*=(int n);  // This should be a member function, not friend

    // Logical operators - const versions
    bool operator==(const Matrix& matrix) const;
    bool operator!=(const Matrix& matrix) const;

    // Transformations - const versions
    Matrix rotateClockwise() const;
    Matrix rotateCounterClockwise() const;
    Matrix transpose() const;

    // Norm
    static double CalcFrobeniusNorm(const Matrix& matrix);
};
