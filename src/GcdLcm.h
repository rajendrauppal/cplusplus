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

/*
 * GCD/LCM combined class responsible for calculating GCD/LCM of n >= 2 positive integers.
 * Several algorithms of finding GCD are implemented in this class.
 * Iterative and Recursive versions are also implemented of each algorithm.
 */
class GcdLcm
{
public:
	int GCD_Euclidean_Iterative(int m, int n);

	int GCD_Euclidean_Recursive(int m, int n);

	int GCD_AlternateEuclidean_Iterative(int m, int n);

	int GCD_AlternateEuclidean_Recursive(int m, int n);

	int GCD_Binary_Iterative(int m, int n);

	int GCD_Binary_Recursive(int m, int n);

	int LCM_Iterative(int m, int n);

	int LCM_Recursive(int m, int n);

	int GCD_UsingLCM(int m, int n);
};