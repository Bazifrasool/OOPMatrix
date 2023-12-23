#include <iostream>
#include <vector>
#ifndef PRIMITIVES
#define PRIMITIVES
template <typename T> class Vector1D {
private:
  /* data */
  std::vector<T> __vector;

public:
  Vector1D(int cols);
  Vector1D(std::vector<T>);
  T sum();
  Vector1D<T> operator+(Vector1D<T> const& obj);
  Vector1D<T> operator-(Vector1D<T> const& obj);
  Vector1D<T> operator*(T const& scalar);
  T &operator[](int const & index);
  T const &operator[](int const & index) const ;
  int size() const;
  friend std::ostream &operator<<(std::ostream &out, Vector1D<T> &data) {

    out << "| ";
    for (int i = 0; i < data.size(); i++) {
      out << data[i] << " | ";
    }
    out << std::endl;
    return out;
  }
};

template <typename T> class Matrix {
private:
  std::vector<Vector1D<T>> __Matrix;

public:
  int rows;
  int cols;
  Matrix(int rows, int cols);
  Vector1D<T> &operator[](int const & row);
  Matrix<T> transpose();
  Vector1D<T> dot_product(Vector1D<T> const &vec);

  friend std::ostream &operator<<(std::ostream &out, Matrix<T> &data) {
    out << "---------------------------------"
        << "\n";
    for (int i = 0; i < data.rows; i++) {
      out << data[i] << std::endl;
    }
    out << "---------------------------------"
        << "\n";
    return out;
  }
};
#endif