#include "primitives.h"
#include "linear_regression.h"
#include "rapidcsv.h"
using namespace std;
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
int main()
{
    rapidcsv::Document Xdoc("../Xarr.csv");
    rapidcsv::Document Ydoc("../Yarr.csv");

    Matrix<float> Xn = Matrix<float>(Xdoc.GetRowCount(), Xdoc.GetColumnCount());
    Vector1D<float> y = Vector1D<float>(Ydoc.GetColumn<float>(0));
    for(auto i = 0 ; i < Xdoc.GetRowCount();i++){
        Xn[i] = Xdoc.GetRow<float>(i);
    }

    // cout<<Xn<<endl;
    // cout<<y<<endl;
    linear_regression<float> lr = linear_regression<float>(Xdoc.GetColumnCount());
    cout<<lr.predict(Xn)<<endl;
    lr.fit(Xn,y,4000);


    
    return 0;
}