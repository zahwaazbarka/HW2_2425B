#include "MataMvidia.h"
#include "Utilities.h"
#include <iostream>

MataMvidia::MataMvidia(std::string movie, std::string author, Matrix* frames, int framesCount) {
    this->movieName = movie;
    this->movieAuthorName = author;
    this->frameCount = framesCount;
    this->frames = new Matrix[frameCount];
    for (int i = 0; i < frameCount; i++) {
        this->frames[i] = frames[i];
    }
}

MataMvidia &MataMvidia::operator=(const MataMvidia &movie) {
    if (this == &movie) {
        return *this;
    }
    delete[] this->frames;
    this->movieName = movie.movieName;
    this->movieAuthorName = movie.movieAuthorName;
    this->frameCount = movie.frameCount;
    this->frames = new Matrix[frameCount];
    for (int i = 0; i < frameCount; i++) {
        this->frames[i] = movie.frames[i];
    }
    return *this;
}

MataMvidia::MataMvidia(const MataMvidia& movie) {
    this->movieName = movie.movieName;
    this->movieAuthorName = movie.movieAuthorName;
    this->frameCount = movie.frameCount;
    this->frames = new Matrix[frameCount];
    for (int i = 0; i < frameCount; i++) {
        this->frames[i] = movie.frames[i];
    }
}

std::ostream& operator<<(std::ostream& os, const MataMvidia& MataMvidia) {
    os << "Movie Name: " << MataMvidia.movieName << "\n"
       << "Author: " << MataMvidia.movieAuthorName << "\n";
    for (int i = 0; i < MataMvidia.frameCount; i++) {
        os << "\nFrame " << i << ":\n" << MataMvidia.frames[i];
    }
    os << "\n-----End of Movie-----\n";
    return os;
}

Matrix& MataMvidia::operator[](int n) {
    if (n < 0 || n >= frameCount) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return this->frames[n];
}

MataMvidia& MataMvidia::operator+=(const MataMvidia& movie) {
    Matrix* newFrames = new Matrix[this->frameCount + movie.frameCount];
    for (int i = 0; i < this->frameCount; i++) {
        newFrames[i] = this->frames[i];
    }
    for (int i = this->frameCount; i < movie.frameCount + this->frameCount; i++) {
        newFrames[i] = movie.frames[i - this->frameCount];
    }
    delete[] this->frames;
    this->frames = newFrames;
    this->frameCount += movie.frameCount;
    return *this;
}

MataMvidia& MataMvidia::operator+=(const Matrix& matrix) {
    Matrix* newFrames = new Matrix[this->frameCount + 1];
    for (int i = 0; i < this->frameCount; i++) {
        newFrames[i] = this->frames[i];
    }
    newFrames[this->frameCount] = matrix;
    delete[] this->frames;
    this->frames = newFrames;
    this->frameCount += 1;
    return *this;
}

MataMvidia MataMvidia::operator+(const MataMvidia& movie) {
    MataMvidia newMovie(*this);
    newMovie += movie;
    return newMovie;
}
