#include <iostream>
#include "matrix.h"

using namespace matrix;
using namespace std;

int main()
{
    cout << "m initialized " << endl;
    Matrix m(2, 3);
    cout << "m assigned values " << endl;
    m(0,0) = 1; m(0,1) = 2; m(0,2) = 3;
    m(1,0) = 4; m(1,1) = 5; m(1,2) = 6;
    cout << "m:" << endl;
    cout << m << endl;

    Matrix m1(2, 4, 3);
    Matrix m2(2, 3, 1);
    cout << "m1:" << endl;
    cout << m1 << endl;
    cout << "m2:" << endl;
    cout << m2 << endl;

    m = m + m2;
    cout << "m = m + m2" << endl;
    cout << m << endl;

    cout << "m = m + 2" << endl;
    m = m + 2;
    cout << "m:" << endl;
    cout << m << endl;

    cout << "Calling m.transpose()" << endl;
    m = m.transpose();
    cout << "m:" << endl;
    cout << m << endl;


    return 0;
}
