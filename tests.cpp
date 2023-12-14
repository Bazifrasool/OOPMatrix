#include "primitives.h"
#include "linear_regression.h"
int main()
{
    Matrix<float> X = Matrix<float>(3, 3);
    Vector1D<float> y = Vector1D<float>(3);

    y[0] = 1;
    y[1] = 2;
    y[2] = 3;

    X[0][0] = 1;
    X[0][1] = 2;
    X[0][2] = 3;
    X[1][0] = 4;
    X[1][1] = 5;
    X[1][2] = 6;
    X[2][0] = 7;
    X[2][1] = 8;
    X[2][2] = 9;

    Vector1D<float> result = Vector1D<float>(3);
    linear_regression<float> lr = linear_regression<float>(3, 3);
    //test dot product , matrix and vector
    result = lr.predict(X);
    std::cout << result << std::endl;
    std::cout << X << std::endl;
    y = y+y; // vector addition
    std::cout << (y) << std::endl;
    
    return 0;
}