/*
The MIT License (MIT)

Copyright (c) 2013 rajendrauppal

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <iostream>

#include "Factorial.h"

#define ULLONG unsigned long long

using std::cout;
using std::cin;
using std::endl;

/*
* Iterative implementation of factorial finding function
*/
ULLONG Factorial_Iterative(int n)
{
	if ( n < 0 ) throw InvalidInputException();
	if ( n <= 1 ) return 1;
	ULLONG f = 1;
	ULLONG num = n;
	while ( num != 1 ) {
		f *= num;
		num -= 1;
	}
	return f;
}

/*
* Recursive implementation of factorial finding function
*/
ULLONG Factorial_Recursive(int n)
{
	if ( n < 0 ) throw InvalidInputException();
	if ( n <= 1 ) return 1;
	else {
		return n * Factorial_Recursive( n - 1 );
	}
}

int main()
{
	const int SIZE = 20;

	// Iterative factorial function tests
	for ( int i = -1; i <= SIZE; ++i ) {
		try {
			cout << "num = " << i << " " << Factorial_Iterative(i) << endl;
		} 
		catch (InvalidInputException e) {
			cout << e.message() << endl;
		}
	}
	cout << endl;

	// Recursive factorial function tests
	for ( int i = -1; i <= SIZE; ++i ) {
		try {
			cout << "num = " << i << " " << Factorial_Recursive(i) << endl;
		}
		catch (InvalidInputException e) {
			cout << e.message() << endl;
		}
	}

	cout << endl;

	cout << "Press Enter to continue..." << endl;
	cin.get();
	return 0;
}
