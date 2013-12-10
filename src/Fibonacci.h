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


#ifndef Fibonacci_INCLUDED
#define Fibonacci_INCLUDED


#include <vector>


#include "Types.h"


using std::vector;


class Fibonacci
{
public:
	Fibonacci();

	~Fibonacci();

	vector<UInt64> GenerateSeries(Int32 n);

	UInt64 NthFibonacci( Int32 n );

    bool IsFibonacci( double n );

private:
	vector<UInt64> _series;
};


class TestFibonacci
{
public:
    TestFibonacci();

    ~TestFibonacci();

    void Test_FibonacciSeries();

    void Test_NthFibonacci();

    void Test_IsFibonacci();

private:
    Fibonacci       _fib;
    const UInt32    _max_int;
    const UInt32    _max_long;
};


#endif // Fibonacci_INCLUDED
