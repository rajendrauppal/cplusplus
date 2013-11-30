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

int GcdLcm::GCD_Euclidean_Recursive(int m, int n)
{
	if ( (m < 0) || (n < 0) ) throw InvalidInputException();
	if ( !m && !n ) throw InvalidInputException();
	if ( m && !n ) return m;
	if ( !m && n ) return n;	

	return GCD_Euclidean_Recursive(n, m % n);
}

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

int GcdLcm::GCD_Binary_Iterative(int m, int n)
{
	return 0;
}

/* Binary GCD algorithm (Credit: en.wikipedia.org/wiki/Binary_GCD_algorithm)
-----------------------------------------------
m		n		gcd
-----------------------------------------------
even	even	2 * gcd( m/2, n/2 )
even	odd     gcd( m/2, n )
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

int GcdLcm::LCM_Iterative(int m, int n)
{
	return 0;
}

int GcdLcm::LCM_Recursive(int m, int n)
{
	return 0;
}

int GcdLcm::GCD_UsingLCM(int m, int n)
{
	return 0;
}


int main()
{
	GcdLcm gcdlcm;
	int nums[13][2] = {{0,1}, {1,0}, {0,0}, {1,1}, {-1,1}, {1,-1}, {-1,-1}, {1,1}, {2,3}, {10,10}, {121,11}, {24,60}, {36253652,183728732}};
	for ( size_t i = 0; i < 13; ++i ) {
		try 
		{
			cout << gcdlcm.GCD_Euclidean_Iterative(nums[i][0], nums[i][1]) << endl;
			cout << gcdlcm.GCD_Euclidean_Recursive(nums[i][0], nums[i][1]) << endl;

			cout << gcdlcm.GCD_AlternateEuclidean_Iterative(nums[i][0], nums[i][1]) << endl;
			cout << gcdlcm.GCD_AlternateEuclidean_Recursive(nums[i][0], nums[i][1]) << endl;

			cout << gcdlcm.GCD_Binary_Recursive(nums[i][0], nums[i][1]) << endl;
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