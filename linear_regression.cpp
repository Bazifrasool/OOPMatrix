#include "linear_regression.h"
#include "primitives.h"

template <typename T>
linear_regression<T>::linear_regression(int weights_dim)
    : weights(weights_dim),best_weights(weights_dim) {
  this->weights = Vector1D<T>(weights_dim);
  this->bias = 0;
  for (int i = 0; i < weights.size(); i++) {
    weights[i] = 1;
  }
  this->best_weights = Vector1D<T>(weights_dim);
  this->best_bias = 0;
  for (int i = 0; i < best_weights.size(); i++) {
    best_weights[i] = 1;
  }
  this->bestScore = INT32_MAX;
  return;
}
template <typename T> 
Vector1D<T> linear_regression<T>::cost(Vector1D<T> y,Vector1D<T> y_pred) {
  // To be completed
  Vector1D<T> temp = y-y_pred;
  for (int i = 0 ; i < temp.size();i++){
    temp[i]=temp[i]*temp[i];
  }
  return temp;

}
#define LEARNING_RATE 0.001f
template <typename T>
Vector1D<T> &linear_regression<T>::fit(Matrix<T> &X, Vector1D<T> &y,int iterations) {
  for( int x = 0 ; x < iterations ; x++){
  Vector1D<T> predictions = predict(X);
  T best_cost=cost(y,predictions).sum();
  if(best_cost<bestScore){
    this->best_weights = weights;
    this->best_bias = bias;
    bestScore = best_cost;
  }

  // std::cout<<"Start of predictions Vector"<<std::endl;
  // std::cout<<predictions<<std::endl;
  // std::cout<<"Start of old weight Vector"<<std::endl;
  // std::cout<<weights<<std::endl;
  Vector1D<T> difference = predictions-y;
  Matrix<T> Transpose_X =X.transpose();
  T factor =  ((T)LEARNING_RATE / ((T)y.size()));
  weights = weights - (Transpose_X.dot_product(difference)) * factor;
  bias = bias - (difference.sum()* factor);
  std::cout<<"Start of predictions Vector"<<std::endl;
  std::cout<<weights<<std::endl;
  std::cout<<"Start of best Vector"<<std::endl;
  std::cout<<best_weights<<std::endl;
  std::cout<<best_bias<<std::endl;
  }

  return weights;
}
template <typename T> Vector1D<T> linear_regression<T>::predict(Matrix<T>const &X) const {
  // To be completed
  Vector1D<T> result = Vector1D<T>(X.rows);
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