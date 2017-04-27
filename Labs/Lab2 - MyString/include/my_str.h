#ifndef MY_STR_H
#define MY_STR_H

#include <iostream>

class MyStr {
public:

    // Make sure to implement these methods with a great care.
    MyStr( );  // empty string.
    MyStr( const char *str );
    MyStr( const MyStr& rhs );
    MyStr& operator=( const MyStr& rhs );
    ~MyStr( );

    // Returns the size of the string (number of characters).
    int size() const;

    // Returns the n-th character of the string.
    char at( int n ) const;

    // Makes the string an upper case (implement using toupper(ch) in file <cctype>).
    void to_upper();

    // Append str to the end of the string.
    void append( const MyStr& str);

    // outputs the string;
    friend std::ostream& operator<< ( std::ostream& os, const MyStr& rhs );

private:
    char *str_;
};


#endif //MY_STR_H
