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


#include "Factorial.h"
#include "Exceptions.h"


using std::cout;
using std::cin;
using std::endl;


typedef UInt64 (Factorial::*FactorialFunction)( Int32 n );


Factorial::Factorial() : _fact(1)
{
}


Factorial::~Factorial()
{
}


UInt64 Factorial::Iterative(Int32 n)
	/// Iterative implementation of factorial finding function
	/// Definition: 
	/// f(n) = undefined,  if n < 0
	/// f(n) = 1,          if n = 0, 1
	/// f(n) = n * f(n-1), if n > 1
{
	if ( n < 0 ) 
		throw InvalidInputException();
	if ( n <= 1 ) 
		return 1;
	UInt64 num = n;
	while ( num != 1 ) {
		_fact *= num;
		num -= 1;
	}
	return _fact;
}


UInt64 Factorial::Recursive(Int32 n)
	/// Recursive implementation of factorial finding function
	/// Definition: 
	/// f(n) = undefined,  if n < 0
	/// f(n) = 1,          if n = 0, 1
	/// f(n) = n * f(n-1), if n > 1
{
	if ( n < 0 ) 
		throw InvalidInputException();
	if ( n <= 1 ) 
		return 1;
	else
		return n * Recursive( n - 1 );
}


void Test_Factorial(FactorialFunction pFactfn, const Int32& size)
{
	for ( Int32 i = -1; i <= size; ++i ) {
		try {
			Factorial f;
			cout << "num = " << i << " " << (f.*pFactfn)(i) << endl;
		} 
		catch (InvalidInputException e) {
			cout << e.message() << endl;
		}
	}
	cout << endl;
}


int main()
{
	const Int32 SIZE = 20;

	// Iterative factorial function tests
	Test_Factorial(&Factorial::Iterative, SIZE);

	// Recursive factorial function tests
	Test_Factorial(&Factorial::Recursive, SIZE);

	cout << "Press Enter to continue..." << endl;
	cin.get();
	return 0;
}
