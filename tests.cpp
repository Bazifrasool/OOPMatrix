#include "primitives.h"
#include "linear_regression.h"
#include "rapidcsv.h"
using namespace std;
int main()
{
    // Vector1D<double> y = Vector1D<double>(3);

    // y[0] = 1;
    // y[1] = 2;
    // y[2] = 3;

    // X[0][0] = 1;
    // X[0][1] = 2;
    // X[0][2] = 3;
    // X[1][0] = 4;
    // X[1][1] = 5;
    // X[1][2] = 6;
    // X[2][0] = 7;
    // X[2][1] = 8;
    // X[2][2] = 9;

    // Vector1D<double> result = Vector1D<double>(3);
    // linear_regression<double> lr = linear_regression<double>(3, 3);
    // //test dot product , matrix and vector
    // result = lr.predict(X);
    // std::cout << result << std::endl;
    // std::cout << X << std::endl;
    // y = y+y; // vector addition
    // std::cout << (y) << std::endl;
    
    // rapidcsv::Document doc("../Salary_Data.csv");
    // Vector1D<double> X = doc.GetColumn<double>("YearsExperience");
    // std::cout<<Xn<<std::endl;
    rapidcsv::Document Xdoc("../Xtest.csv");
    rapidcsv::Document Ydoc("../Ytest.csv");

    Matrix<double> Xn = Matrix<double>(Xdoc.GetRowCount(), Xdoc.GetColumnCount());
    Vector1D<double> y = Vector1D<double>(Ydoc.GetColumn<double>(0));
    Vector1D<double> y_prime = Vector1D<double>(Ydoc.GetColumn<double>(0));
    Vector1D<double> y_difference = Vector1D<double>(Ydoc.GetColumn<double>(0));
    // Vector1D<double> weights = Vector1D<double>(6);

    // weights[0] = 1;
    // weights[1] = 1;
    // weights[2] = 1;
    // weights[3] = 1;
    // weights[4] = 1;
    // weights[5] = 1;

    for(auto i = 0 ; i < Xdoc.GetRowCount();i++){
        Xn[i] = Xdoc.GetRow<double>(i);
    }


    cout<<Xn<<endl;
    cout<<y<<endl;
    linear_regression<double> lr = linear_regression<double>(Xdoc.GetColumnCount());
    cout<<lr.predict(Xn)<<endl;
    y_prime=lr.predict(Xn);
    y_difference=(y-y_prime);


    
    return 0;
}