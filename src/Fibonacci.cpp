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
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::sort;

#include "Exceptions.h"

#define uint unsigned int
#define LONGLONG long long

/*
* Generated Fibonacci series up to n
*/
vector<LONGLONG> FibonacciSeries(int n)
{
	if ( n <= 0 ) throw InvalidInputException();
	
	vector<LONGLONG> result;

	LONGLONG first = 1;
	LONGLONG second = 1;
	while ( n != 0 ) {
		if ( n <= 2 ) {
			for (LONGLONG i = 0; i < n; ++i) {
				result.push_back(1);
			}
			break;
		}
		LONGLONG sum = first + second;
		result.push_back(sum);
		first = second;
		second = sum;
		n--;
	}
	sort(result.begin(), result.end());
	return result;
}

/*
* Finds nth Fibonacci number
* Uses Fibonacci series function
*/
LONGLONG NthFibonacci(int n)
{
	vector<LONGLONG> series = FibonacciSeries(n);
	return series[series.size() - 1];
}

/*
* Determines if a given number is Fibonacci or not
*/
bool IsFibonacci(int n)
{
	return true;
}

int main()
{
	// Tests - generating Fibonacci series up to number n
	int MAX_INT = 46;		// maximum 46 Fibonacci numbers with int
	int MAX_LONGLONG = 92;	// maximum 92 Fibonacci numbers with long long
	try {
		vector<LONGLONG> result = FibonacciSeries(MAX_LONGLONG);
		for ( auto start = result.begin(); start != result.end(); ++start ) {
			cout << *start << endl;
		}
		cout << endl;
	}
	catch (InvalidInputException e) {
		cout << e.message() << endl;
	}

	// Tests - Find Nth Fibonacci number
	for (int i = 1; i <= MAX_LONGLONG; ++i ) {
		LONGLONG nthFibonacci = NthFibonacci(i);
		cout << i << "th Fibonacci number is " << nthFibonacci << endl;
	}

	cout << "Press Enter to continue..." << endl;
	cin.get();
	return 0;
}
