#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

namespace matrix {

    typedef int Element;

    class matrix_dimensions_wrong: public std::exception {
        virtual const char* what() const throw() {
           return "Wrong matrix dimensions for operation";
        }
    };

    class Matrix {
    public:

        Matrix(int num_rows, int num_cols, const Element initial = Element());
        Matrix(const Matrix& m);
        Matrix& operator=(const Matrix& rhs);
        virtual ~Matrix();

       // Mathematical operations on a matrix (and a scalar).
        Matrix transpose();
        Matrix operator+(const Element& elem) const;
        Matrix operator*(const Element& elem) const;

        // Mathematical operations on two matrices.
        Matrix operator+(const Matrix& rhs) const;
        Matrix operator-(const Matrix& rhs) const;
        Matrix operator*(const Matrix& rhs) const;  // dot-product

        Matrix& operator+=(const Matrix& rhs);
        Matrix& operator-=(const Matrix& rhs);
        Matrix& operator*=(const Matrix& rhs);  // dot-product

        // Check for equality.
        bool operator==(const Matrix& rhs ) const;

        // Access individual elements
        Element& operator()(const int& row, const int& col);
        const Element& operator()(const int& row, const int& col) const;

        // Accessors for number of rows and columns.
        int get_num_rows() const;
        int get_num_cols() const;

        // Input / Output
        friend std::istream& operator >> ( std::istream& is, Matrix& rhs );
        friend std::ostream& operator << ( std::ostream& os, const Matrix& rhs );

    private:

        int index(int row, int col ) const {
            return row * num_cols_ + col;
        }

        int num_rows_;
        int num_cols_;
        Element* data_;  // implement 2D using 1D array and above index function
    };

    inline std::istream& operator >> ( std::istream& is, Matrix& rhs )
    {
        for ( int row = 0; row < rhs.get_num_rows(); ++row ) {
            for ( int col = 0; col < rhs.get_num_cols(); ++col ) {
                Element elem;
                is >> elem;
                rhs(row,col) = elem;
            }
        }
        return is;
    }

    inline std::ostream& operator << ( std::ostream& os, const Matrix& rhs )
    {
        for ( int row = 0; row < rhs.get_num_rows(); ++row ) {
            for ( int col = 0; col < rhs.get_num_cols(); ++col ) {
                os << ' ' << rhs(row,col);
            }
            os << '\n';
        }
        return os;
    }

    inline Matrix operator+(const Element& elem, const Matrix& rhs)
    {
        return rhs + elem;
    }

    inline Matrix operator*(const Element& elem, const Matrix& rhs)
    {
        return rhs * elem;
    }
}

#endif //MATRIX_H
