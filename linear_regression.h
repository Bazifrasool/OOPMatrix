#include "primitives.h"
#include<iostream>
#ifndef LINEAR_REGRESSION
#define LINEAR_REGRESSION
template <typename T>
class linear_regression
{
private:
    Vector1D<T> weights;
    Vector1D<T> result;
    T bias;

public:
    linear_regression(int weights_dim);
    Vector1D<T> &fit(Matrix<T> &X, Vector1D<T> &y);
    Vector1D<T> &predict(Matrix<T> &X);
};
#endif
