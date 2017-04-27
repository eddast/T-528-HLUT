#include "my_str.h"
#include <cstring>
#include <ctype.h>

using namespace std;

// Initializes empty string.
MyStr::MyStr( ) : str_(nullptr)
{
    // Empty array still has room for the null-terminating sign at place 1
    str_ = new char[1];
    str_[0] = '\0';
}

MyStr::MyStr( const char *str ) : str_(nullptr)
{
    // Initialize new array of length of string
    // Copy contents of str into str_ (the member variable)
    // (From teacher's notes)
    str_ = new char[strlen(str)+1];
    strcpy(str_,str);
}

// Copy constructor
MyStr::MyStr( const MyStr& rhs ) : str_(nullptr)
{
    // Initilize new string, copy contents
    // of our string into new string
    // (From teacher's notes)
    str_ = new char[strlen(rhs.str_)+1];
    strcpy( str_, rhs.str_ );
}

// Overloading the assignment operator
// Need to think carefully about allocating/deallocating
MyStr& MyStr::operator=( const MyStr& rhs ) {
    // (From teacher's notes)
    // If arrays are not the same
    // actions are made
    if ( this != &rhs ) {
        // new array initiated with string size
        // and str_ array redefined as the new array
        char *tmp = new char[rhs.size()+1];
        strcpy( tmp, rhs.str_ );
        delete [] str_;
        str_ = tmp;
    }
    return *this;
}

// Deletes our pointer array, releasing the memory of our pointer
MyStr::~MyStr( )
{
    delete[] str_;
}

// Returns the size of the string (number of characters).
int MyStr::size() const
{
    // Omit the null-terminating character
    // Making number of characters in string size of array -1
    return strlen(str_) - 1;
}

// Returns the n-th character of the string.
char MyStr::at( int n ) const
{
    // returns the n-th element of array
    return str_[n];
}

// Makes the string an upper case (implement using toupper(ch) in file <cctype>).
void MyStr::to_upper()
{
    // Iterates through string, putting
    // each character to upper case character
    for(int i = 0; i <= size(); i++)
    {
        str_[i] = toupper(str_[i]);
    }
}

// Append str to the end of the string.
void MyStr::append( const MyStr& str)
{
    // Initiating array of new size which is size of old string
    // Combined with size of new string plus null-terminating char
    int new_size = (size())+(str.size())+1;
    char *tmp = new char[new_size];

    // Filling first part of tmp with old str (str_)
    int i = 0;
    for(; i <= size(); i++)
    {
        tmp[i] = str_[i];
    }

    // Filling second part of tmp with new str (str)
    for(int j = 0; j <= str.size(); j++)
    {
        tmp[i] = str.at(j);
        i++;
    }

    // Now deleting str_ and redefining it as tmp
    // Now has double capacity and new str appended to it
    delete[] str_;
    str_ = tmp;
}

// Outputs the string
ostream& operator <<( std::ostream& os, const MyStr& rhs )
{
    // Loops through, outputting array contents element by element
    for(int i = 0; i <= rhs.size(); i++)
    {
        os << rhs.str_[i];
    }
    return os;
}
