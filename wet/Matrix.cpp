
#include "Matrix.h"
#include "Utilities.h"
#include <iostream>
#include <cmath>

Matrix::Matrix(const int rows, const int columns,const int value) {
    if (rows < 0 || columns < 0) {
        exit(7);
    }
    else {
        matrix=new int[rows*columns];
        this->columns=columns;
        this->rows=rows;
        for(int i=0;i<rows*columns;i++) {
            matrix[i]=value;
        }
    }
}
Matrix::Matrix() {
    matrix = new int[0];
    columns = 0;
    rows = 0;
}
Matrix::Matrix(const Matrix &matrix) {
    columns = matrix.columns;
    rows = matrix.rows;
    this->matrix = new int[rows*columns];
    for(int i=0;i<rows*columns;i++) {
        this->matrix[i]=matrix.matrix[i];
    }

}
Matrix &Matrix::operator=(const Matrix &matrix) {
    if (this == &matrix) {
        return *this;
    }
    if(matrix.rows * matrix.columns != rows*columns) {
        delete[] this->matrix;
        this->matrix = new int[matrix.rows*matrix.columns];
    }

    this->columns = matrix.columns;
    this->rows = matrix.rows;
    for(int i=0;i<rows*columns;i++) {
        this->matrix[i]=matrix.matrix[i];
    }

    return *this;
}
int& Matrix::operator()(const int i,const int j) {
    if(i < 0 || i >= rows || j < 0 || j >= columns) {
        exit(6);
    }
    return this->matrix[(this->columns * i)+j];
}

std::ostream& operator<<(std::ostream&os,const Matrix& matrix) {
    for(int i=0;i<matrix.rows;i++) {
        for(int j=0;j<matrix.columns;j++) {
            os << "|" << matrix.matrix[i*matrix.columns +j];
        }
        os << "|\n";
    }
    return os;
}

Matrix Matrix::operator+(const Matrix& matrix) {
    if(this->columns != matrix.columns || this->rows != matrix.rows) {
        exit(4);
    }

    Matrix result(matrix.rows,matrix.columns,0);
    for(int i = 0 ;i < rows*columns; i++) {
            result.matrix[i] = this->matrix[i] + matrix.matrix[i];
    }
    return result;
}
Matrix Matrix::operator-(const Matrix& matrix) {
    if(columns != matrix.columns || rows != matrix.rows) {
        exit(3);
    }
    Matrix result(matrix.rows,matrix.columns,0);
    for(int i = 0 ;i < rows*columns; i++) {
        result.matrix[i] = this->matrix[i] - matrix.matrix[i];
    }
    return result;
}
Matrix Matrix::operator*(const Matrix& matrix) {
    if(columns != matrix.rows) {
        exit(2);
    }
    Matrix result(rows,matrix.columns,0);
    for(int i = 0 ;i < rows; i++) {

        for(int j = 0;j < matrix.columns;j++) {
            int sum = 0;
            for(int k = 0;k < columns;k++) {
                sum += this->matrix[i*columns+k] * matrix.matrix[k*matrix.columns+j];
            }
            result.matrix[i*result.columns + j] = sum;

        }
    }
    return result;
}

Matrix Matrix::operator+=(const Matrix& matrix) {
    *this = *this + matrix;
    return *this;
}
Matrix Matrix::operator-=(const Matrix& matrix) {
    *this = *this - matrix;
    return *this;
}
Matrix Matrix::operator*=(const Matrix& matrix) {
    *this = *this * matrix;
    return *this;
}
Matrix Matrix::operator-() {
    Matrix result(rows,columns,0);
    for(int i = 0;i < rows*columns;i++) {
        result.matrix[i]=this->matrix[i] * -1;
    }
    return result;
}


Matrix operator*(const int n,const Matrix& matrix) {
    Matrix result(matrix.rows,matrix.columns,0);
    for(int i = 0;i<matrix.columns * matrix.rows;i++) {
        result.matrix[i] = matrix.matrix[i] *= n;
    }
    return result;
}
Matrix operator*(const Matrix& matrix,const int n) {
    return n * matrix;
}
Matrix operator*=(const Matrix& matrix,const int n) {
    return matrix * n;
}

bool Matrix::operator==(const Matrix &matrix) {
    if(columns != matrix.columns || rows != matrix.rows) {
        return false;
    }
    for(int i = 0 ;i < rows*columns; i++) {
        if(matrix.matrix[i] != this->matrix[i]) {
            return false;
        }
    }
    return true;

}
bool Matrix::operator!=(const Matrix &matrix) {
    return !(*this == matrix);
}

Matrix Matrix::rotateClockwise() {
    Matrix result(columns,rows,0);
    int place = 0;
    for (int j = 0; j < columns; j++) {
        for(int i = rows-1 ;i >= 0;i--) {
            result.matrix[place++] = this->matrix[columns * i + j];
        }
    }
    return result;
}
Matrix Matrix::rotateCounterClockwise() {
    Matrix result(columns,rows,0);
    int place = 0;
    for (int j = columns-1; j >=0; j--) {
        for(int i = 0;i < rows;i++) {
            result.matrix[place++] = this->matrix[columns * i + j];
        }
    }
    return result;
}
Matrix Matrix::transpose() {
    Matrix result(columns,rows,0);
    for(int i = 0;i < rows;i++) {
        for(int j = 0;j < columns;j++) {
            result.matrix[j*rows + i] = this->matrix[i*columns + j];
        }
    }
    return result;
}
double Matrix::CalcFrobeniusNorm(const Matrix& matrix) {
    int sum = 0;
    for(int i = 0;i < matrix.rows;i++) {
        for(int j = 0;j < matrix.columns;j++) {
            sum += (matrix.matrix[i*matrix.columns +j] * matrix.matrix[i*matrix.columns +j]);
        }
    }
    return sqrt(sum);
}
// static int CalcDeterminant(const Matrix& matrix) {
    // return 0;
// }
