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

#define LLONG long long

using std::cout;
using std::cin;
using std::endl;

/*
* Iterative implementation of factorial finding function
*/
LLONG Factorial_Iterative(LLONG n)
{
	if ( n < 0 ) throw InvalidInputException();
	if ( n <= 1 ) return 1;
	LLONG f = 1;
	while ( n != 1 ) {
		f *= n;
		n -= 1;
	}
	return f;
}

/*
* Recursive implementation of factorial finding function
*/
LLONG Factorial_Recursive(LLONG n)
{
	if ( n < 0 ) throw InvalidInputException();
	if ( n <= 1 ) return 1;
	else {
		return n * Factorial_Recursive( n - 1 );
	}
}

int main()
{
	int numbers[6] = {-1, 0, 5, 10, 47, 50};
	// Iterative factorial function tests
	for ( unsigned int i = 0; i < 6; ++i ) {
		try {
			cout << Factorial_Iterative(numbers[i]) << endl;
		} 
		catch (InvalidInputException e) {
			cout << e.message() << endl;
		}
	}
	cout << endl;

	// Recursive factorial function tests
	for ( unsigned int i = 0; i < 6; ++i ) {
		try {
			cout << Factorial_Recursive(numbers[i]) << endl;
		}
		catch (InvalidInputException e) {
			cout << e.message() << endl;
		}
	}
	cout << endl;

	cout << "Please press Enter to continue..." << endl;
	cin.get();
	return 0;
}
