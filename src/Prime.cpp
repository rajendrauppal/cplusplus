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
#include <math.h>

using std::sqrt;
using std::cout;
using std::cin;
using std::endl;

#include "Prime.h"

#define uint unsigned int

bool Prime(int n)
{
	if ( n <= 1 ) throw InvalidInputException();

	double limit = uint( sqrt((double)n) );
	for ( uint i = 2; i <= limit; ++i ) {
		if ( n % i == 0 ) return false;
	}
	return true;
}

int main()
{
	const int MAX = 1000;

	// Find prime numbers among 2-1000
	for ( int i = -1; i <= MAX; ++i ) {
		try {
			if ( Prime(i) ) {
				cout << i << endl;
			}
		}
		catch (InvalidInputException e) {
			cout << e.message() << endl;
		}
	}

	cout << "Press Enter to continue..." << endl;
	cin.get();
	return 0;
}
