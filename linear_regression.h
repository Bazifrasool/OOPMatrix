#include "primitives.h"
#include <iostream>
#ifndef LINEAR_REGRESSION
#define LINEAR_REGRESSION
template <typename T> class linear_regression {
private:
  Vector1D<T> weights;
  T bias;
  Vector1D<T> best_weights;
  T best_bias;
  T bestScore;

public:
  linear_regression(int weights_dim);
  Vector1D<T> &fit(Matrix<T> &X, Vector1D<T> &y,int iterations);
  Vector1D<T> predict(Matrix<T>const &X) const;
  Vector1D<T> cost(Vector1D<T> y,Vector1D<T> y_pred);
};
#endif
