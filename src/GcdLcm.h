
/*

GcdLcm.h

$Id: ~/git/C++/src/GcdLcm.h $

Definition of the GcdLcm class.

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

#ifndef GcdLcm_INCLUDED
#define GcdLcm_INCLUDED

class GcdLcm
	/// GCD/LCM combined class responsible for calculating GCD/LCM of 
	/// n >= 2 positive integers.
	///
	/// Several algorithms of finding GCD are implemented in this class.
	///
	/// Iterative and Recursive versions are also implemented of each algorithm.
{
public:
	int GCD_Euclidean_Iterative(int m, int n);
		/// Basic Euclidean algorithm defined as:
		/// pseudocode: Credit: en.wikipedia.org/wiki/Euclidean_algorithm
		/// function gcd(a, b)
		/// while b != 0
		///		t = b
		///		b = a % b
		///		a = t
		/// return a
		///
		/// throws InvalidInputException (defined in Exceptions.h)
		/// if ( a < 0 or b < 0 ) or ( a == 0 and b == 0 )

	int GCD_Euclidean_Recursive(int m, int n);
		/// pseudocode: Credit: en.wikipedia.org/wiki/Euclidean_algorithm
		/// function gcd(a, b)
		///		if ( a and not b ) return a
		///		if ( not a and b ) return b
		///		return gcd(b, a % b)
		///
		/// throws InvalidInputException (defined in Exceptions.h)
		/// if ( a < 0 or b < 0 ) or ( a == 0 and b == 0 )

	int GCD_AlternateEuclidean_Iterative(int m, int n);
		/// pseudocode: Credit: en.wikipedia.org/wiki/Euclidean_algorithm
		/// function gcd(a, b)
		/// while a != b
		///		if a > b
		///			a = a - b
		///		else
		///			b = b - a
		///	return a

	int GCD_AlternateEuclidean_Recursive(int m, int n);
		/// pseudocode: Credit: en.wikipedia.org/wiki/Euclidean_algorithm
		/// function gcd(a, b)
		/// 	if ( m == n ) return m;
		///		if ( m > n )
		///			return gcd(m - n, n);
		///		else
		///			return gcd(m, n - m);

	int GCD_Binary_Iterative(int m, int n);
		/// Binary GCD algorithm - Iterative implementation
		/// (Credit: en.wikipedia.org/wiki/Binary_GCD_algorithm)
		/// -----------------------------------------------
		/// m       n       gcd
		/// -----------------------------------------------
		/// even    even    2 * gcd( m/2, n/2 )
		/// even    odd     gcd( m/2, n )
		/// odd     even    gcd( m, n/2 )
		/// odd     odd     m >= n then gcd( (m - n)/2, n )
		///                 m < n  then gcd( (n - m)/2, m )
		/// -----------------------------------------------

	int GCD_Binary_Recursive(int m, int n);
		/// Core algorithm:
		/// function gcd(a, b):
		///		if ( a_even && b_even ) 
		/// 		return gcd( a >> 1, b >> 1 ) << 1;
		///		if ( b_even && !b_even ) 
		/// 		return gcd( a >> 1, b );
		///		if ( !a_even && b_even ) 
		/// 		return gcd( a, b >> 1 );
		///		if ( a >= b ) 
		/// 		return gcd( (a - b) >> 1, b );
		///		else 
		/// 		return gcd( (b - a) >> 1, a );

	int LCM_UsingGCD(int m, int n);
		/// Credit: en.wikipedia.org/wiki/Least_common_multiple
		/// LCM(a, b) = |a . b| / GCD(a, b)

	int GCD_UsingLCM(int m, int n);
		/// Credit: en.wikipedia.org/wiki/Least_common_multiple
		/// GCD(a, b) = |a . b| / LCM(a, b)
};

#endif // GcdLcm_INCLUDED
