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
#include "Complex.h"
#include <complex>

using std::cout;
using std::cin;
using std::endl;


#define print(s) cout<<endl<<(s)<<endl


template<typename T>
void printc(const Complex<T>& c)
{
    cout << c.real() << "\t" << c.imag() << endl;
}


void Test_construction()
{
    Complex<float> c1; // default ctor
    printc( c1 );
    
    Complex<float> c2( 3.45f, -6.2f ); // parametrized ctor
    printc( c2 );

    c1 = c2; // assignment operator
    printc( c1 );

    Complex<double> c3(-2.3, 4.5);
    Complex<double> c4(c3); // copy ctor
    printc( c3 );
    printc( c4 );
}


void Test_APIs()
{
    Complex<long double> c1(3.4, -1.2);
    Complex<long double> c2(-1.4, 4.25);

    c1.add( c2 ); // add non-const
    printc( c1 );

    Complex<long double> out;
    c1.add( c2, out ); // add const
    printc( out );

    c1.sub( c2 ); // sub non-const
    printc( c1 );
    c1.sub( c2, out ); // sub const
    printc( out );

    c1.mul( c2 ); // mul non-const
    printc( c1 );
    c1.mul( c2, out ); // mul const
    printc( out );

    c1.div( c2 ); // div non-const
    printc( c1 );
    c1.div( c2, out ); // div const
    printc( out );

    c1.conjugate(); // conjugate non-const
    printc( c1 );
    c1.conjugate( out ); // conjugate const
    printc( out );

    // get, set underlying real/imag values
    long double re = out.real();
    long double im = out.imag();

    out.real( 4.44 );
    out.imag( 5.55 );
    printc( out );
}


void Test_operators()
{
    Complex<float> c1( 2.3f, -3.999f );
    Complex<float> c2( 2.3f, -3.999f );

    cout << (c1 == c2) << endl;
    cout << (c1 != c2) << endl;

    Complex<float> c3 = c1 + c2;
    printc( c3 );
    c3 += c1;
    printc( c3 );

    c3 = c1 - c2;
    printc( c3 );
    c3 -= c1;
    printc( c3 );

    c3 = c1 * c2;
    printc( c3 );
    c3 *= c1;
    printc( c3 );

    c3 = c1 / c2;
    printc( c3 );
    c3 /= c1;
    printc( c3 );
}


int main()
{
    Test_construction();
    
    Test_APIs();

    Test_operators();

    print("Press any key to continue...");
    cin.get();
    return 0;
}


// ~EOF
