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
#include <vector>
#include <algorithm>

using std::sqrt;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::sort;

#include "Exceptions.h"

#define uint unsigned int

/*
* Prime number detection function
* Input: a natural number n > 1
* Output: true if prime, false otherwise
*/
bool Prime(int n)
{
	if ( n <= 1 ) throw InvalidInputException();

	double limit = uint( sqrt((double)n) );
	for ( uint i = 2; i <= limit; ++i ) {
		if ( n % i == 0 ) return false;
	}
	return true;
}

/*
* Find first n prime numbers
* Input: a positive integer n > 0
* Output: a list of first n prime numbers
*/
vector<int> PrimeFirstN(int n)
{
	if ( n <= 0 ) throw InvalidInputException();
	
	vector<int> result;
	if ( n == 1 ) {
		result.push_back(2);
		return result;
	}

	int i = 2;
	while ( n != 0 ) {
		if ( Prime(i) ) {
			result.push_back(i);
			n--;
		}
		i++;
	}

	return result;
}

int main()
{
	const int MAX = 1000;

	// Find prime numbers among 2-1000 - tests
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

	// Finding first n prime numbers - tests
	const int MAX_SIZE = 7;
	int testlist[MAX_SIZE] = {-1, 0, 1, 5, 10, 15, 20};
	for ( int i = 0; i < MAX_SIZE; ++i ) {
		try {
			vector<int> primes = PrimeFirstN(testlist[i]);
			for ( auto start = primes.begin(); start != primes.end(); ++start ) {
				cout << *start << " ";
			}
			cout << endl;
		}
		catch (InvalidInputException e) {
			cout << e.message() << endl;
		}
	}

	cout << "Press Enter to continue..." << endl;
	cin.get();
	return 0;
}
