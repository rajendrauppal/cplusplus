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

#include "Exceptions.h"
#include "GcdLcm.h"

using std::cout;
using std::cin;
using std::endl;

/* pseudocode: Credit: en.wikipedia.org/wiki/Euclidean_algorithm
function gcd(a, b)
	while b != 0
		t = b
		b = a % b
		a = t
	return a
*/
int GcdLcm::GCD_Euclidean_Iterative(int m, int n)
{
	if ( (m < 0) || (n < 0) ) throw InvalidInputException();
	if ( !m && !n ) throw InvalidInputException();
	if ( m && !n ) return m;
	if ( !m && n ) return n;	

	while ( n ) {
		int temp = n;
		n = m % n;
		m = temp;
	}

	return m;
}

/* pseudocode: Credit: en.wikipedia.org/wiki/Euclidean_algorithm
function gcd(a, b)
	while b != 0
		t = b
		b = a % b
		a = t
	return a
*/
int GcdLcm::GCD_Euclidean_Recursive(int m, int n)
{
	if ( (m < 0) || (n < 0) ) throw InvalidInputException();
	if ( !m && !n ) throw InvalidInputException();
	if ( m && !n ) return m;
	if ( !m && n ) return n;	

	return GCD_Euclidean_Recursive(n, m % n);
}

/* pseudocode: Credit: en.wikipedia.org/wiki/Euclidean_algorithm
function gcd(a, b)
	while a != b
		if a > b
			a = a - b
		else
			b = b - a
	return a
*/
int GcdLcm::GCD_AlternateEuclidean_Iterative(int m, int n)
{
	if ( (m < 0) || (n < 0) ) throw InvalidInputException();
	if ( !m && !n ) throw InvalidInputException();
	if ( m && !n ) return m;
	if ( !m && n ) return n;	

	while ( m != n ) {
		if ( m > n )
			m = m - n;
		else
			n = n - m;
	}

	return m;
}

/* pseudocode: Credit: en.wikipedia.org/wiki/Euclidean_algorithm
function gcd(a, b)
	while a != b
		if a > b
			a = a - b
		else
			b = b - a
	return a
*/
int GcdLcm::GCD_AlternateEuclidean_Recursive(int m, int n)
{
	if ( (m < 0) || (n < 0) ) throw InvalidInputException();
	if ( !m && !n ) throw InvalidInputException();
	if ( m && !n ) return m;
	if ( !m && n ) return n;	

	if ( m == n ) return m;
	if ( m > n )
		return GCD_AlternateEuclidean_Recursive(m - n, n);
	else
		return GCD_AlternateEuclidean_Recursive(m, n - m);
}

/* Binary GCD algorithm - Iterative implementation
(Credit: en.wikipedia.org/wiki/Binary_GCD_algorithm)
-----------------------------------------------
m       n       gcd
-----------------------------------------------
even    even    2 * gcd( m/2, n/2 )
even    odd     gcd( m/2, n )
odd     even    gcd( m, n/2 )
odd     odd     m >= n then gcd( (m - n)/2, n )
                m < n  then gcd( (n - m)/2, m )
-----------------------------------------------
*/
int GcdLcm::GCD_Binary_Iterative(int m, int n)
{
	if ( (m < 0) || (n < 0) ) throw InvalidInputException();
	if ( !m && !n ) throw InvalidInputException();
	if ( m && !n ) return m;
	if ( !m && n ) return n;
	
	int shift = 0;
	while ( (~m & 1) && (~n & 1) ) { // while m and n both are even
		m >>= 1;
		n >>= 1;
		shift++;
	}

	while (n) {

		while ( ~m & 1 ) // while m is even
			m >>= 1;

		while ( ~n & 1 ) // while n is even
			n >>= 1;

		if ( m > n ) 
			std::swap(m, n);

		n = n - m;
	}

	return m << shift;
}

/* Binary GCD algorithm - Recursive implementation
(Credit: en.wikipedia.org/wiki/Binary_GCD_algorithm)
-----------------------------------------------
m       n       gcd
-----------------------------------------------
even    even    2 * gcd( m/2, n/2 )
even    odd     gcd( m/2, n )
odd     even    gcd( m, n/2 )
odd     odd     m >= n then gcd( (m - n)/2, n )
                m < n  then gcd( (n - m)/2, m )
-----------------------------------------------
*/
int GcdLcm::GCD_Binary_Recursive(int m, int n)
{
	if ( (m < 0) || (n < 0) ) throw InvalidInputException();
	if ( !m && !n ) throw InvalidInputException();
	if ( m && !n ) return m;
	if ( !m && n ) return n;
	if ( m == n ) return m;

	bool m_even = ~m & 1;
	bool n_even = ~n & 1;
	
	if ( m_even && n_even ) 
		return GCD_Binary_Recursive( m >> 1, n >> 1 ) << 1;

	if ( m_even && !n_even ) 
		return GCD_Binary_Recursive( m >> 1, n );

	if ( !m_even && n_even ) 
		return GCD_Binary_Recursive( m, n >> 1 );

	if ( m >= n ) 
		return GCD_Binary_Recursive( (m - n) >> 1, n );
	else 
		return GCD_Binary_Recursive( (n - m) >> 1, m );
}

/* Credit: en.wikipedia.org/wiki/Least_common_multiple
LCM(a, b) = |a . b| / GCD(a, b)
*/
int GcdLcm::LCM_UsingGCD(int m, int n)
{
	if ( (m < 0) || (n < 0) ) throw InvalidInputException();
	if ( !m && !n ) return 0;
	if ( m && !n ) return 0;
	if ( !m && n ) return 0;
	if ( m == n ) return m;

	return (m * n) / GCD_Euclidean_Iterative(m, n);
}

/* Credit: en.wikipedia.org/wiki/Least_common_multiple
LCM(a, b) = |a . b| / GCD(a, b)
*/
int GcdLcm::GCD_UsingLCM(int m, int n)
{
	if ( (m < 0) || (n < 0) ) throw InvalidInputException();
	if ( !m && !n ) throw InvalidInputException();
	if ( m && !n ) return m;
	if ( !m && n ) return n;
	if ( m == n ) return m;

	int lcm = LCM_UsingGCD(m, n);
	if ( !lcm )
		throw ZeroLCMException();
	else
		return (m * n) / lcm;
}


int main()
{
	GcdLcm gcdlcm;
	int nums[13][2] = {{0,1}, {1,0}, {0,0}, {1,1}, {-1,1}, {1,-1}, {-1,-1}, {1,1}, {2,3}, {10,10}, {121,11}, {24,60}, {36253652,183728732}};
	for ( size_t i = 0; i < 13; ++i ) {
		try 
		{
			int m = nums[i][0];
			int n = nums[i][1];

			cout << gcdlcm.GCD_Euclidean_Iterative(m, n) << endl;
			cout << gcdlcm.GCD_Euclidean_Recursive(m, n) << endl;

			cout << gcdlcm.GCD_AlternateEuclidean_Iterative(m, n) << endl;
			cout << gcdlcm.GCD_AlternateEuclidean_Recursive(m, n) << endl;

			cout << gcdlcm.GCD_Binary_Recursive(m, n) << endl;
			cout << gcdlcm.GCD_Binary_Iterative(m, n) << endl;

			cout << gcdlcm.GCD_UsingLCM(m, n) << endl;			
			cout << gcdlcm.LCM_UsingGCD(m, n) << endl;
		} 
		catch (CPPExceptions& e) 
		{
			cout << e.message() << endl;
		}
	}

	cout << "Press Enter to continue..." << endl;
	cin.get();
	return 0;
}