/*
The MIT License (MIT)

Copyright (c) 2013 Rajendra Kumar Uppal

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
#include "Prime.h"


bool Prime::IsPrime( UInt32 n )
    /// Prime number detection function
    /// Input: a natural number n > 1
    /// Output: true if prime, false otherwise
{
	if ( n <= 1 ) 
        throw InvalidInputException();

    double limit = UInt32( sqrt((double)n) );

    for ( UInt32 i = 2; i <= limit; ++i ) {
        if ( n % i == 0 ) 
            return false;
    }
    return true;
}


Prime::Primes Prime::GetPrimes( UInt32 n )
    /// Find first n prime numbers
    /// Input: a positive integer n > 0
    /// Output: a list of first n prime numbers
{
	if ( n <= 0 ) 
        throw InvalidInputException();
	
	if ( n == 1 ) {
		_primes.push_back(2);
		return _primes;
	}

	UInt32 i = 2;
	while ( n != 0 ) {
		if ( IsPrime(i) ) {
			_primes.push_back(i);
			n--;
		}
		i++;
	}

	return _primes;
}


int main()
    /// Driver program to test Prime class APIs
{
	const Int32 MAX = 1000;

	// Find prime numbers among 2-1000 - tests
	for ( Int32 i = -1; i <= MAX; ++i ) {
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
	const Int32 MAX_SIZE = 7;
	Int32 testlist[MAX_SIZE] = {-1, 0, 1, 5, 10, 15, 20};
	for ( Int32 i = 0; i < MAX_SIZE; ++i ) {
		try {
			vector<Int32> primes = PrimeFirstN(testlist[i]);
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
