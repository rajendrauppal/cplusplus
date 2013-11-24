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

using std::cout;
using std::cin;
using std::endl;
using std::sqrt;
using std::pow;

struct Roots
{
	double alpha;
	double beta;
};

/*
* Solves a quadratic equation of the form
* (a * x ^ 2 + b * x + c) = 0
* alpha = -b + sqrt(b ^ 2 - 4 * a * c) / 2 * a
* beta = -b - sqrt(b ^ 2 - 4 * a * c) / 2 * a
*/
Roots Quadratic(double a, double b, double c)
{
	Roots roots;
	double d = sqrt(pow(b, 2) - 4 * a * c);
	roots.alpha = ( -b + d ) / ( 2 * a );
	roots.beta = ( -b - d ) / ( 2 * a );
	return roots;
}

int main()
{
	// Tests - Solving quadratic equations
	Roots roots = Quadratic(3, 2, -1);	// 3x^2 + 2*x - 1 = 0
	cout << "3x^2 + 2*x - 1 = 0" << endl;
	cout << "alpha = " << roots.alpha << " beta = " << roots.beta << endl;

	roots = Quadratic(1, 2, 1);	// x^2 + 2*x + 1 = 0
	cout << "x^2 + 2*x + 1 = 0" << endl;
	cout << "alpha = " << roots.alpha << " beta = " << roots.beta << endl;

	cout << "Press Enter to continue..." << endl;
	cin.get();
	return 0;
}
