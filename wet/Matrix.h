#pragma once
#include <iostream>

class Matrix {
private:
    int rows;
    int columns; //the width
    int* matrix;

public:
    Matrix(int rows,int columns,int value = 0);
    Matrix();
    Matrix(const Matrix& matrix);
    Matrix& operator=(const Matrix& matrix);
    int& operator()( int i, int j);
    friend std::ostream& operator<<(std::ostream& os,const Matrix& matrix);

    Matrix operator+(const Matrix& matrix);
    Matrix operator-(const Matrix& matrix);
    Matrix operator*(const Matrix& matrix);

    Matrix operator+=(const Matrix& matrix);
    Matrix operator-=(const Matrix& matrix);
    Matrix operator*=(const Matrix& matrix);
    Matrix operator-();

    friend Matrix operator*(const int n,const Matrix& matrix);
    friend Matrix operator*(const Matrix& matrix,const int n);
    friend Matrix operator*=(const Matrix& matrix,const int n);

    bool operator==(const Matrix& matrix);
    bool operator!=(const Matrix& matrix);

    Matrix rotateClockwise();
    Matrix rotateCounterClockwise();
    Matrix transpose();
    static double CalcFrobeniusNorm(const Matrix& matrix);
    //static int CalcDeterminant(const Matrix& matrix);

    ~Matrix(){delete [] matrix;}

};
