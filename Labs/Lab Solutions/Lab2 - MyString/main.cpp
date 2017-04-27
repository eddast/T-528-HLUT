#include <iostream>
#include "my_str.h"

using namespace std;

int main()
{
    MyStr str("hello");
    MyStr str2(" world");


    cout << "At place 0: " << str.at(0) << endl;
    cout << "At place 1: " << str.at(1) << endl;
    cout << "At place 2: " << str.at(2) << endl;
    cout << "At place 3: " << str.at(3) << endl;
    cout << "At place 4: " << str.at(4) << endl;


    cout << "My string str: " << str << " is " << str.size() << " characters long" << endl;
    cout << "My string str2: " << str2 << " is " << str2.size() << " characters long" << endl;


    cout << "Appending str: " << str << " to str2: " << str2 << endl;
    str.append(str2);
    cout << "Str is now: " << str << endl;


    cout << "Now making str uppercase: " << endl;
    str.to_upper();
    cout << str << endl;


    cout << "Current size of str is " << str.size() << endl;

    cout << "Initiazing empty string: " << endl;
    MyStr emptystr;
    cout << "String: " << emptystr << endl;
    cout << "Size of emptystr is: " << emptystr.size() << endl;



}
