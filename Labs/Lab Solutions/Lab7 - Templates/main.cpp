#include <iostream>
#include <mystack.h>

using namespace std;

/* Implement the Factorial template-metaprogramming example from the
 * lectures. Notice the compilation messages as you compile. What is going
 * on? What happens if you would omit the specialization part of the
 * template (Factorial<0>)?
 */
template <int N>
struct Factorial {
    enum { value = N * Factorial<N - 1>::value };
};

// computes n! for <n>
template <>
struct Factorial<0> { //<0> is the base case
    enum { value = 1 };
};
const int x = Factorial<5>::value; // == 24
const int y = Factorial<0>::value; // == 1



/* 1. Create a template function middle( … ) that takes three arguments, all of
 * the same type, and returns the element that would be in the middle if the
 * elements	were to be ordered (using the < operator). What is the concept
 * of the template function?
 */
template <class T>
T middle(T x, T y, T z)
{
     if( y < x ){
         if( x < z ){ return x; }
         else if ( z < y ){ return y; }
         else { return z; }
     }
     else{
         if( y < z) { return y; }
         else if( z < x ) { return x; }
         else { return z; }
     }
}




int main()
{
    // Middle function tests:

    /*
    string x1 = "Edda";
    string y1 = "Darri";
    string z1 = "Yngvi";
    cout << "String values: " << x1 << ", " << y1 << ", " << z1 << endl;
    cout << "Middle of string values is: " << middle(x1, y1, z1) << endl << endl;

    int x2 = 353;
    int y2 = 212;
    int z2 = 13;
    cout << "Integer values: " << x2 << ", " << y2 << ", " << z2 << endl;
    cout << "Middle of integer values: " << middle(x2, y2, z2) << endl << endl;

    double x3 = 38.7;
    double y3 = 10.3;
    double z3 = 20.6;
    cout << "Double values: " << x3 << ", " << y3 << ", " << z3 << endl;
    cout << "Middle of double values: " << middle(x3, y3, z3) << endl;
    //*/



    // Stack test from teacher

    /*
    // Testing int as stack template typename
	cout << "Expected:" << endl << "3 2 2 NonEmpty Empty" << endl << "Generated:" << endl;
	MyStack<int> intstack;
	intstack.push(1);
	intstack.push(2);
	intstack.push(3);
	cout << intstack.top() << " ";
	intstack.pop();
	cout << intstack.top() << " " << intstack.size() << " ";
	intstack.pop();
	cout << (intstack.empty()?"Empty":"NonEmpty") << " ";
	intstack.pop();
	cout << (intstack.empty()?"Empty":"NonEmpty") << endl;

	// Testing char as stack template typename
	cout << "Expected:" << endl << "c b 2 NonEmpty Empty" << endl << "Generated:" << endl;
	MyStack<char> charstack;
	charstack.push('a');
	charstack.push('b');
	charstack.push('c');
	cout << charstack.top() << " ";
	charstack.pop();
	cout << charstack.top() << " " << charstack.size() << " ";
	charstack.pop();
	cout << (charstack.empty()?"Empty":"NonEmpty") << " ";
	charstack.pop();
	cout << (charstack.empty()?"Empty":"NonEmpty") << endl;

	// Testing std::string as stack template typename
	cout << "Expected:" << endl << "last middle 2 NonEmpty Empty" << endl << "Generated:" << endl;
	MyStack<string> strstack;
	strstack.push("first");
	strstack.push("middle");
	strstack.push("last");
	cout << strstack.top() << " ";
	strstack.pop();
	cout << strstack.top() << " " << strstack.size() << " ";
	strstack.pop();
	cout << (strstack.empty()?"Empty":"NonEmpty") << " ";
	strstack.pop();
	cout << (strstack.empty()?"Empty":"NonEmpty") << endl;
	//*/

	cout << x << " " << y << endl;
}
