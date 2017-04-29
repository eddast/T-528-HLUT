#include <iostream>
#include "matrix.h"

using namespace matrix;
using namespace std;

int main()
{
    Matrix m(2, 3);

    m(0,0) = 1; m(0,1) = 2; m(0,2) = 3;
    m(1,0) = 4; m(1,1) = 5; m(1,2) = 6;

    cout << "m: " << endl;
    std::cout << m << std::endl;

    Matrix mat1(2, 3, 2);
    cout << "mat1: " << endl;
    std::cout << mat1 << std::endl;

    mat1 = mat1 + 1;
    cout << "mat1 + 1: " << endl;
    std::cout << mat1 << std::endl;

    /// SPYRJA!
    cout << "Initialize mat2" << endl;
    Matrix mat2(2, 3, 1);
    /*cout << "mat2 * 2: " << endl;
    mat2 = mat2 * 2;
    cout << mat2 << endl;

    // m = m.transpose();
    // cout << m << endl;

    cout << "m * 2: " << endl;
    m = m * 2;
    cout << m << endl;

    cout << "Adding m to mat1" << endl;
    cout << "m: " << endl;
    cout << m << endl;
    cout << "mat1: " << endl;
    cout << mat1 << endl;
    m = m - mat1;
    cout << m << endl;
    */
    cout << mat1 << endl;
    return 0;
}
