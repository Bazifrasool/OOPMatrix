#include "linear_regression.h"
#include "primitives.h"

template <typename T>
linear_regression<T>::linear_regression(int weights_dim)
    : weights(weights_dim), result(weights_dim), bias(weights_dim) {
  this->weights = Vector1D<T>(weights_dim);
  this->bias = 0;
  for (int i = 0; i < weights.size(); i++) {
    weights[i] = 1;
  }
  return;
}
template <typename T>
Vector1D<T> &linear_regression<T>::fit(Matrix<T> &X, Vector1D<T> &y) {
  return weights;
}
template <typename T> Vector1D<T> &linear_regression<T>::predict(Matrix<T> &X) {
  // To be completed

  result = X.dot_product(weights);
  for (int i = 0; i < result.size(); i++) {
    result[i] = result[i] + bias;
  }
  return result;
}
// prepare compiler for types of template required
template class linear_regression<float>;
template class linear_regression<double>;
template class linear_regression<int>;