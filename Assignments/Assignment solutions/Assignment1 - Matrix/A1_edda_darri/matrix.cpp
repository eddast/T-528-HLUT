#include "matrix.h"
using namespace matrix;

// Constructor
Matrix::Matrix(int num_rows, int num_cols, const Element initial) :
    num_rows_(num_rows), num_cols_(num_cols), data_(nullptr)
{
    // Setting the matrix's size
    data_ = new Element[num_rows * num_cols];

    // Filling matrix with elements
    for(int i = 0; i < (num_rows * num_cols); i++)
    {
        data_[i] = initial;
    }
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
        tmp = rhs.data_;
        num_rows_ = rhs.num_rows_;
        num_cols_ = rhs.num_cols_;
        delete [] data_;
        data_ = tmp;
    }
    // Returns current matrix as the assignment
    return *this;
}

Matrix::~Matrix()
{
    // Deleting allocated memory
    delete [] data_;
}


// Mathematical operations on a matrix (and a scalar).


// Transposing matrix:
// Switching columns and rows and their values
Matrix Matrix::transpose()
{
    Matrix result(num_cols_, num_rows_);
    std::cout << "result matrix: " << std::endl;
    std::cout << result << std::endl;
    for(int row = 0; row < num_rows_; row++)
    {
        for(int col = 0; col < num_cols_; col++)
        {
            int idx_data = index(row, col);
            int idx_result = index(col, row);

            std::cout << "Pushing " << data_[idx_data] << " into index: " << idx_result << " in result matrix" << std::endl;
            result.data_[idx_result] = data_[idx_data];
        }
    }

    return result;
}

Matrix Matrix::operator+(const Element& elem) const
{
    // Creating a result matrix, then filling it with
    // Previous elements plus constant
    // Then result matrix is returned
    Matrix result(num_rows_, num_cols_);
    for(int i = 0; i < (num_rows_ * num_cols_) ; i++)
    {
        result.data_[i] = data_[i] + elem;
    }

    return result;
}

// Creating a result matrix, then filling it with
// Previous elements times constant
// Then result matrix is returned
Matrix Matrix::operator*(const Element& elem) const
{
    Matrix result(num_rows_, num_cols_);
    for(int i = 0; i < (num_rows_ * num_cols_) ; i++)
    {
        result.data_[i] = data_[i] * elem;
    }

    return result;
}

// Mathematical operations on two matrices.
Matrix Matrix::operator+(const Matrix& rhs) const
{
    // Matrices need to be the same size for addition to be legal
    // If matrices are not equal in size, an exception is thrown
    if(num_rows_ != rhs.num_rows_ || num_cols_ != rhs.num_cols_)
    {
        throw matrix_dimensions_wrong();
    }

    // Creating result matrix, filling it with results
    Matrix result(num_rows_, num_cols_);
    for(int i = 0; i < (num_rows_ * num_cols_); i++)
    {
        result.data_[i] = data_[i] + rhs.data_[i];
    }

    return result;
}

Matrix Matrix::operator-(const Matrix& rhs) const
{
    // Matrices need to be the same size for subtraction to be legal
    // If matrices are not equal in size, an exception is thrown
    if(num_rows_ != rhs.num_rows_ ||num_cols_ != rhs.num_cols_)
    {
        throw matrix_dimensions_wrong();
    }

    // Creating result matrix, filling it with results
    Matrix result(num_rows_, num_cols_);
    for(int i = 0; i < (num_rows_ * num_cols_); i++)
    {
        result.data_[i] = data_[i] - rhs.data_[i];
    }

    return result;
}

// dot-product
Matrix Matrix::operator*(const Matrix& rhs) const
{
    /// TODO
    Matrix result(num_rows_, num_cols_);
    return result;
}

Matrix& Matrix::operator+=(const Matrix& rhs)
{
    /// TODO
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& rhs)
{
    /// TODO
    return *this;
}

// dot-product
Matrix& Matrix::operator*=(const Matrix& rhs)
{
    /// TODO
    return *this;
}

// Check for equality.
bool Matrix::operator==(const Matrix& rhs ) const
{
    // Matrices need to be the same size to be equal
    if((num_rows_ * num_cols_) != (rhs.num_rows_ * rhs.num_cols_))
    {
        return false;
    }
    else
    {
        // Checking if each element is the same
        // Returning false if any element is not equal
        for(int i = 0; i < (num_rows_ * num_cols_) ; i++)
        {
            if(data_[i] != rhs.data_[i])
            {
                return false;
            }
        }
        return true;
    }
}


// Access individual elements

Element& Matrix::operator()(const int& row, const int& col)
{
    // Fetches index of specified row and column
    // Returns value at index
    int idx = index(row, col);

    return data_[idx];
}

const Element& Matrix::operator()(const int& row, const int& col) const
{
    // Fetches index of specified row and column
    // Returns value at index
    int idx = index(row, col);

    return data_[idx];
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
