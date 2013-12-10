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
#include <vector>
#include <algorithm>
#include <math.h>


using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::sort;
using std::sqrt;
using std::pow;


#include "Exceptions.h"
#include "Fibonacci.h"


Fibonacci::Fibonacci()
{
	_series.clear();
}


Fibonacci::~Fibonacci()
{
}


vector<UInt64> Fibonacci::GenerateSeries( Int32 n )
	/// Generates Fibonacci series up to n
{
	if ( n <= 0 ) 
		throw InvalidInputExceptionFibonacci();

	UInt64 first = 1;
	UInt64 second = 1;
	while ( n != 0 ) {
		if ( n <= 2 ) {
			for (UInt64 i = 0; i < n; ++i) {
				_series.push_back(1);
			}
			break;
		}
		UInt64 sum = first + second;
		_series.push_back(sum);
		first = second;
		second = sum;
		n--;
	}
	sort(_series.begin(), _series.end());
	return _series;
}


UInt64 Fibonacci::NthFibonacci( Int32 n )
	/// Finds nth Fibonacci number
	/// Uses Fibonacci series function
{
	_series = GenerateSeries(n);
	return _series[_series.size() - 1];
}


bool Fibonacci::IsFibonacci(double n)
    /// Determines if a given number is Fibonacci or not.
    /// Test: A positive number n is Fibonacci iff (5*n^2 + 4) or (5*n^2 - 4).
{
	if ( n <= 0 ) 
        throw InvalidInputExceptionFibonacci();

	double criteria[2] = {5 * pow(n, 2) + 4, 5 * pow(n, 2) - 4};	
	for ( int i = 0; i < 2; ++i ) {
		if ( criteria[i] > 0 ) {
			double root = sqrt(criteria[i]);
			double diff = root - int(root);
			if ( diff == 0.0 ) return true;
		}
	}
	return false;
}


TestFibonacci::TestFibonacci() 
    : _max_int(46), // maximum 46 Fibonacci numbers with int
    _max_long(92) // maximum 92 Fibonacci numbers with long long
{
}


TestFibonacci::~TestFibonacci()
{
}


void TestFibonacci::Test_FibonacciSeries()
    /// Tests - generating Fibonacci series up to number n
{
	try {
		vector<UInt64> result = _fib.GenerateSeries(_max_long);
		for ( auto start = result.begin(); start != result.end(); ++start ) {
			cout << *start << endl;
		}
		cout << endl;
	}
	catch (InvalidInputExceptionFibonacci e) {
		cout << e.message() << endl;
	}
}


void TestFibonacci::Test_NthFibonacci()
    /// Tests - Find Nth Fibonacci number
{
	for (Int32 i = 1; i <= _max_long; ++i ) {
		UInt64 nthFibonacci = _fib.NthFibonacci(i);
		cout << i << "th Fibonacci number is " << nthFibonacci << endl;
	}
}


void TestFibonacci::Test_IsFibonacci()
    /// Tests - Is given number Fibonacci?
{
	for ( Int32 i = 1; i <= _fib.NthFibonacci(10); ++i ) {
		if ( _fib.IsFibonacci(i) )
			cout << i << "th number is Fibonacci!" << endl;
		else
			cout << i << "th number is not Fibonacci!" << endl;
	}
}


int main()
{
    TestFibonacci test;

	test.Test_FibonacciSeries();
	test.Test_NthFibonacci();
	test.Test_IsFibonacci();

	cout << "Press Enter to continue..." << endl;
	cin.get();
	return 0;
}
