#include <iostream>
#include <stdexcept>
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

    cout << "Fetching m(0,0) element" << endl;
    cout << "m(0,0): " << m(0,0) << endl;
    cout << "Fetching m(0,1) element" << endl;
    cout << "m(0,1): " << m(0,1) << endl;
    cout << "Fetching m(0,2) element" << endl;
    cout << "m(0,2): " << m(0,2) << endl;
    cout << "Fetching m(1,0) element" << endl;
    cout << "m(1,0): " << m(1,0) << endl;
    cout << "Fetching m(1,1) element" << endl;
    cout << "m(1,1): " << m(1,1) << endl;
    cout << "Fetching m(1,2) element" << endl;
    cout << "m(1,2): " << m(1,2) << endl;
    cout << "Fetching m(1,3) element" << endl;
    cout << "m(1,3): ";

    try
    {
        cout << m(1,3) << endl;
    }
    catch(std::out_of_range outofrange)
    {
        cout << "Failed: " << outofrange.what() << endl;
    }
    try
    {
        cout << "Fetching m(2,0) element" << endl;
        cout << "m(2,0): " << m(2,0) << endl;
    }
    catch(std::out_of_range outofrange)
    {
        cout << "Failed: " << outofrange.what() << endl;
    }
    try
    {
        cout << "Fetching m(1,4) element" << endl;
        cout << "m(1,4): " << m(1,4) << endl;
    }
    catch(std::out_of_range outofrange)
    {
        cout << "Failed: " << outofrange.what() << endl;
    }
    try
    {
        cout << "Fetching m(3,0) element" << endl;
        cout << "m(3,0): " << m(3,0) << endl;
    }
    catch(std::out_of_range outofrange)
    {
        cout << "Failed: " << outofrange.what() << endl;
    }

    Matrix mm(2, 3, 2);
    Matrix m1(3, 3, 3);
    Matrix m2(3, 3, 1);
    cout << "m1:" << endl;
    cout << m1 << endl;
    cout << "m2:" << endl;
    cout << m2 << endl;

    cout << "m = m + 2" << endl;
    m = m + 2;
    cout << "m:" << endl;
    cout << m << endl;

    cout << "m = m + 2" << endl;
    m = m + 2;
    cout << "m:" << endl;
    cout << m << endl;

    cout << "m = 2 + m" << endl;
    m = 2 + m;
    cout << "m:" << endl;
    cout << m << endl;


    cout << "m = m - mm" << endl;
    m = m - mm;
    cout << "m:" << endl;
    cout << m << endl;

    cout << "Calling m.transpose()" << endl;
    m = m.transpose();
    cout << "m:" << endl;
    cout << m << endl;

    cout << "Calling m += m" << endl;
    m += m;
    cout << "m:" << endl;
    cout << m << endl;

    cout << "Calling m += m" << endl;
    m += m;
    cout << "m:" << endl;
    cout << m << endl;

    cout << "Calling m += m2" << endl;
    try
    {
        m += m2;
        cout << "m:" << endl;
        cout << m << endl;
    }
    catch(matrix_dimensions_wrong e)
    {
        cout << "Failed: matrices not compatible for operation" << endl;
    }

    Matrix mat(3, 2, 2);
    cout << "mat:" << endl;
    cout << mat << endl;

    cout << "Calling m -= mat" << endl;
    m -= mat;
    cout << "m:" << endl;
    cout << m << endl;

    cout << "Calling m -= m2" << endl;
    try
    {
        m -= m2;
        cout << "m:" << endl;
        cout << m << endl;
    }
    catch(matrix_dimensions_wrong e)
    {
        cout << "Failed: matrices not compatible for operation" << endl;
    }

    cout << "Fetching m(2,1), the element in row three, column one" << endl;
    cout << "m(2,1): " << m(2,1) << endl;

    cout << "Fetching m(3,6) element" << endl;
    cout << "m(3,6): ";
    try
    {
        cout << m(3,1) << endl;
    }
    catch(std::out_of_range outofrange)
    {
        cout << "Failed: " << outofrange.what() << endl;
    }
    cout << "m's number of rows: " << m.get_num_rows() << endl;
    cout << "m's number of columns: " << m.get_num_cols() << endl;

    cout << "m1 *= m2" << endl;
    m1 *= m2;
    cout << "m1:" << endl;
    cout << m1 << endl;

    Matrix test_mult3(9,7,2);
    Matrix test_mult4(7,9,2);
    cout << "test_mult3 *= test_mult4" << endl;
    test_mult3 *= test_mult4;
    cout << "test_mult3:" << endl;
    cout << test_mult3 << endl;

    Matrix n(2,3,1);
    cout << "m:" << endl;
    cout << m << endl;
    cout << "n:" << endl;
    cout << n << endl;
    cout << "Test m *= n" << endl;
    m *= n;
    cout << "m:" << endl;
    cout << m << endl;

    return 0;
}
