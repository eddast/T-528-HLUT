#include "matrix.h"
using namespace matrix;

// Constructor
Matrix::Matrix(int num_rows, int num_cols, const Element initial) :
    num_rows_(num_rows), num_cols_(num_cols), data_(nullptr)
{
    // Setting the matrix's size
    data_ = new Element[num_rows * num_cols];

    // Filling matrix with elements
    /// TODO : fill matrix with elements
}

// Copy constructor
Matrix::Matrix(const Matrix& m) :
    num_rows_(m.num_rows_), num_cols_(m.num_cols_), data_(nullptr)
{
    // Copying matrix and it's values into new matrix object
    data_ = new Element[m.num_rows_ * m.num_cols_];
    data_ = m.data_;
}

// Assign operator overloading
Matrix& Matrix::operator=(const Matrix& rhs)
{
    // Temp variable created for the matrix (data_) as a precaution.
    // The new operator could throw an exception.
    // Then filling data and assigning it to temp
    if ( this != &rhs ) {
        Element *tmp = new Element[rhs.num_rows_ * rhs.num_cols_];
        /// TODO: Refill data with &rhs elements
        num_rows_ = rhs.num_rows_;
        num_cols_ = rhs.num_cols_;
        delete [] data_;
        data_ = tmp;
    }
    return *this;
}

Matrix::~Matrix()
{
    // Deleting allocated memory
    delete[] data_;
}


// Mathematical operations on a matrix (and a scalar).


Matrix Matrix::transpose()
{
    /// TODO
}

Matrix Matrix::operator+(const Element& elem) const
{
    /// TODO
}

Matrix Matrix::operator*(const Element& elem) const
{
    /// TODO
}

// Mathematical operations on two matrices.
Matrix Matrix::operator+(const Matrix& rhs) const
{
    // Matrices need to be the same size for addition to be legal
    // If matrices are not equal in size, an exception is thrown
    if(num_rows_ != rhs.num_rows_ ||num_cols_ != rhs.num_cols_)
    {
        throw matrix_dimensions_wrong();
    }

    /// TODO
}

Matrix Matrix::operator-(const Matrix& rhs) const
{
    // Matrices need to be the same size for subtraction to be legal
    // If matrices are not equal in size, an exception is thrown
    if(num_rows_ != rhs.num_rows_ ||num_cols_ != rhs.num_cols_)
    {
        throw matrix_dimensions_wrong();
    }

    /// TODO
}

// dot-product
Matrix Matrix::operator*(const Matrix& rhs) const
{
    /// TODO
}

Matrix& Matrix::operator+=(const Matrix& rhs)
{
    /// TODO
}

Matrix& Matrix::operator-=(const Matrix& rhs)
{
    /// TODO
}

// dot-product
Matrix& Matrix::operator*=(const Matrix& rhs)
{
    /// TODO
}

// Check for equality.
bool Matrix::operator==(const Matrix& rhs ) const
{
    /// TODO
}


// Access individual elements

Element& Matrix::operator()(const int& row, const int& col)
{
    // Fetches index of specified row and column
    // Returns value at index
}

const Element& Matrix::operator()(const int& row, const int& col) const
{
    // Fetches index of specified row and column
    // Returns value at index
}


// Accessors for number of rows and columns.

int Matrix::get_num_rows() const
{
    // Returns number of rows
    return num_rows_;
}

int Matrix::get_num_cols() const
{
    // Returns number of columns
    return num_cols_;
}
