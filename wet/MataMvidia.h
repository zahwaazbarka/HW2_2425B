

#include <iostream>
#include "Matrix.h"
#include "Utilities.h"


class MataMvidia {
private:
    std::string movieName;
    std::string movieAuthorName;
    Matrix* frames;
    int frameCount;


public:
    MataMvidia(std::string movie,std::string author,Matrix* frames,int framesCount);
    MataMvidia(const MataMvidia& movie);

    MataMvidia& operator=(const MataMvidia& movie);

    Matrix& operator[](int n);

    MataMvidia& operator+=(const MataMvidia& movie);
    MataMvidia& operator+=(const Matrix& movie);
    MataMvidia operator+(const MataMvidia& movie);

    friend std::ostream &operator<<(std::ostream &os, const MataMvidia& movie);

    ~MataMvidia(){delete [] frames;}

};
