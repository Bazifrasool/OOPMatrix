#include <iostream>
#include <vector>

template <typename T>
class Vector1D
{
private:
    /* data */
    std::vector<T> __vector;

public:
    Vector1D(int cols)
    {
        for (int i = 0; i < cols; i++)
        {
            __vector.push_back(0);
        }
    }
    Vector1D<T> operator+(Vector1D<T> &obj)
    {
        Vector1D<T> result = Vector1D<T>(obj.size());
        if (obj.size() != this->size())
        {
            return result;
        }
        for (int i = 0; i < obj.size(); i++)
        {
            result[i] = this->__vector[i] + obj.__vector[i];
        }
        return result;
    }
    T &operator[](int index)
    {
        if (index < __vector.size())
            return __vector[index];
        else
        {
            return __vector[index];
        }
    }
    int size()
    {
        return __vector.size();
    }

    friend std::ostream &operator<<(std::ostream &out, Vector1D<T> &data)
    {
        out << "| ";
        for (int i = 0; i < data.size(); i++)
        {
            out << data[i] << " | ";
        }
        out << std::endl;
        return out;
    }
};

template <typename T>
class Matrix
{
private:
    std::vector<Vector1D<T>> __Matrix;

public:
    int rows;
    int cols;
    Matrix(int rows, int cols)
    {
        for (int i = 0; i < rows; i++)
        {
            Vector1D<T> temp = Vector1D<T>(cols);
            __Matrix.push_back(temp);
        }
        this->rows = rows;
        this->cols = cols;
    }
    Vector1D<T> &operator[](int row)
    {
        if (row < this->rows)
        {

            return __Matrix[row];
        }
        else
        {
            return __Matrix[0];
        }
    }

    Vector1D<T> &dot_product(Vector1D<T> vec)
    {
        Vector1D<T> *Result = new Vector1D<T>(rows);
        if (vec.size() != this->cols)
        {
            return *Result;
        }
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                (*Result)[i] = (*Result)[i] + (__Matrix[i][j] * vec[j]);
            }
        }
        return *Result;
    }

    friend std::ostream &operator<<(std::ostream &out, Matrix<T> &data)
    {
        for (int i = 0; i < data.rows; i++)
        {
            out << data[i] << std::endl;
        }
        return out;
    }
};
template <typename T>
class linear_regression
{
private:
    Vector1D<T> weights;
    Vector1D<T> result;
    T bias;

public:
    linear_regression(int weights_dim, int result_dim) : weights(weights_dim), result(result_dim)
    {
        this->weights = Vector1D<T>(weights_dim);
        this->bias = 10;
        this->weights[0] = 1;
        this->weights[1] = 2;
        this->weights[2] = 3;

        return;
    }
    Vector1D<T> &fit(Matrix<T> &X, Vector1D<T> &y)
    {
        return weights;
    }
    Vector1D<T> &predict(Matrix<T> &X)
    {
        // To be completed
        result = X.dot_product(weights);
        for (int i = 0; i < result.size(); i++)
        {
            result[i] = result[i] + bias;
        }
        return result;
    }
};

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