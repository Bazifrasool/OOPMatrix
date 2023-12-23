#include "primitives.h"
#include <vector>
template <typename T> Vector1D<T>::Vector1D(int cols) {
  for (int i = 0; i < cols; i++) {
    __vector.push_back(0);
  }
}
template <typename T> T Vector1D<T>::sum() {
    T sumVal = 0;
    for(auto i : __vector){
      sumVal+=i;
    }
    return sumVal;
  }
template <typename T> Vector1D<T>::Vector1D(std::vector<T> incomingVector) {
  for (int i = 0; i < incomingVector.size(); i++) {
    __vector.push_back(incomingVector[i]);
  }
}
template <typename T> Vector1D<T> Vector1D<T>::operator+(Vector1D<T> const & obj) {
  Vector1D<T> result = Vector1D<T>(obj.size());
  if (obj.size() != this->size()) {
    return result;
  }
  for (int i = 0; i < obj.size(); i++) {
    result[i] = this->__vector[i] + obj.__vector[i];
  }
  return result;
}
template <typename T> Vector1D<T> Vector1D<T>::operator-(Vector1D<T> const &obj) {
  Vector1D<T> result = Vector1D<T>(obj.size());
  if (obj.size() != size()) {
    return result;
  }
  for (int i = 0; i < obj.size(); i++) {
    result[i] = __vector[i] - obj.__vector[i];
  }
  return result;
}
template <typename T> T &Vector1D<T>::operator[](int const & index) {
  if (index < __vector.size()) {
    return __vector[index];
  }
  return __vector[index];
}
template <typename T> T const & Vector1D<T>::operator[](int const & index) const {
  if (index < __vector.size()) {
    return __vector[index];
  }
  return __vector[index];
}
template <typename T> 
Vector1D<T> Vector1D<T>::operator *(T const& scalar) {
    Vector1D<T> result = Vector1D<T>(this->size());
    for (int i = 0; i < this->size(); i++) {
    result[i] = this->__vector[i]*scalar;
  }
  return result;
}
template <typename T> int Vector1D<T>::size() const { return __vector.size(); }

template <typename T> Matrix<T>::Matrix(int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    Vector1D<T> temp = Vector1D<T>(cols);
    __Matrix.push_back(temp);
  }
  this->rows = rows;
  this->cols = cols;
}
template <typename T> Vector1D<T> &Matrix<T>::operator[](int const & row) {
  if (row < this->rows) {

    return __Matrix[row];
  }
  return __Matrix[0];
}
template <typename T> 
Matrix<T> Matrix<T>::transpose() {
  Matrix<T> TransposedMatrix = Matrix<T>(cols,rows);
  for(int i = 0 ; i <this->rows;i++){
    for(int j = 0 ; j < this->cols; j++){
      TransposedMatrix[j][i] = __Matrix[i][j];
    }
  }
  return TransposedMatrix;
}

template <typename T> Vector1D<T> Matrix<T>::dot_product(Vector1D<T> const &vec) const {
  Vector1D<T> Result = Vector1D<T>(rows);
  if (vec.size() != this->cols) {
    return Result;
  }
  for (int i = 0; i < this->rows; i++) {
    for (int j = 0; j < this->cols; j++) {
      Result[i] = Result[i] + (__Matrix[i][j] * vec[j]);
    }
  }
  return (Result);
}
// prepare compiler for types of template required
template class Matrix<float>;
template class Matrix<double>;
template class Matrix<int>;
template class Vector1D<float>;
template class Vector1D<double>;
template class Vector1D<int>;