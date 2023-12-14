#include "primitives.h"
#include "linear_regression.h"

template <typename T>
linear_regression<T>::linear_regression(int weights_dim, int result_dim) : weights(weights_dim), result(result_dim)
{
    this->weights = Vector1D<T>(weights_dim);
    this->bias = 10;
    this->weights[0] = 1;
    this->weights[1] = 2;
    this->weights[2] = 3;

    return;
}
template <typename T>
Vector1D<T> & linear_regression<T>::fit(Matrix<T> &X, Vector1D<T> &y)
{
    return weights;
}
template <typename T>
Vector1D<T> & linear_regression<T>::predict(Matrix<T> &X)
{
    // To be completed
    result = X.dot_product(weights);
    for (int i = 0; i < result.size(); i++)
    {
        result[i] = result[i] + bias;
    }
    return result;
}
// prepare compiler for types of template required
template class linear_regression<float>;
template class linear_regression<double>;
template class linear_regression<int>;