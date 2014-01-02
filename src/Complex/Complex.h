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


#ifndef Complex_INCLUDED
#define Complex_INCLUDED


#include <cmath>


template<typename T>
class Complex
{
public:
    Complex();
    Complex(T real, T imag);
    ~Complex();

    Complex(const Complex& other);
    Complex& operator = (const Complex& rhs);

    void add(const Complex& right);
    void add(const Complex& right, Complex& out) const;

    void sub(const Complex& right);
    void sub(const Complex& right, Complex& out) const;

    void mul(const Complex& right);
    void mul(const Complex& right, Complex& out) const;

    void div(const Complex& right);
    void div(const Complex& right, Complex& out) const;

    T real() const;
    void real(T re);

    T imag() const;
    void imag(T im);

    void conjugate();
    void conjugate(Complex& out) const;

    void reciprocal();
    void reciprocal(Complex& out) const;

    T modulus() const;

    bool operator == (const Complex& right) const;
    bool operator != (const Complex& right) const;

    Complex operator + (const Complex& right) const;
    Complex& operator += (const Complex& right);

    Complex operator - (const Complex& right) const;
    Complex& operator -= (const Complex& right);

    Complex operator * (const Complex& right) const;
    Complex& operator *= (const Complex& right);

    Complex operator / (const Complex& right) const;
    Complex& operator /= (const Complex& right);

private:
    T _real;
    T _imag;
};


template<typename T>
Complex<T>::Complex():
    _real(0),
    _imag(0)
{
}


template<typename T>
Complex<T>::Complex(T real, T imag):
    _real(real),
    _imag(imag)
{
}


template<typename T>
Complex<T>::~Complex()
{
}


template<typename T>
Complex<T>::Complex(const Complex& other):
    _real(other._real),
    _imag(other._imag)
{
}


template<typename T>
Complex<T>& Complex<T>::operator = (const Complex& rhs)
{
    if ( this != &rhs ) {
        _real = rhs._real;
        _imag = rhs._imag;
    }
    return *this;
}


template<typename T>
void Complex<T>::add(const Complex& right)
{
    _real += right._real;
    _imag += right._imag;
}


template<typename T>
void Complex<T>::add(const Complex& right, Complex& out) const
{
    out._real = this->_real + right._real;
    out._imag = this->_imag + right._imag;
}


template<typename T>
void Complex<T>::sub(const Complex& right)
{
    _real -= right._real;
    _imag -= right._imag;
}


template<typename T>
void Complex<T>::sub(const Complex& right, Complex& out) const
{
    out._real = this->_real - right._real;
    out._imag = this->_imag - right._imag;
}


template<typename T>
void Complex<T>::mul(const Complex& right)
{
    _real = _real * right._real + _imag * right._imag;
    _imag = _real * right._imag + _imag * right._real;
}


template<typename T>
void Complex<T>::mul(const Complex& right, Complex& out) const
{
    out.real( _real * right._real + _imag * right._imag );
    out.imag( _real * right._imag + _imag * right._real );
}


template<typename T>
void Complex<T>::div(const Complex& right)
{
    T numerator_real = ( _real * right._real - _imag * right._imag );
    T numerator_imag = ( _imag * right._real - _real * right._imag );
    T denominator = ( right._real * right._real + right._imag * right._imag );

    real( numerator_real / (T)denominator );
    imag( numerator_imag / (T)denominator );
}


template<typename T>
void Complex<T>::div(const Complex& right, Complex& out) const
{
    T numerator_real = ( _real * right._real - _imag * right._imag );
    T numerator_imag = ( _imag * right._real - _real * right._imag );
    T denominator = ( right._real * right._real + right._imag * right._imag );

    out.real( numerator_real / (T)denominator );
    out.imag( numerator_imag / (T)denominator );
}


template<typename T>
T Complex<T>::real() const
{
    return _real;
}


template<typename T>
void Complex<T>::real(T re)
{
    _real = re;
}


template<typename T>
T Complex<T>::imag() const
{
    return _imag;
}


template<typename T>
void Complex<T>::imag(T im)
{
    _imag = im;
}


template<typename T>
void Complex<T>::conjugate()
{
    _imag = -_imag;
}


template<typename T>
void Complex<T>::conjugate(Complex& out) const
{
    out._imag = -out._imag;
}


template<typename T>
void Complex<T>::reciprocal()
{
    Complex<T> c;
    conjugate( c );
    T denominator = ( _real * _real + _imag * _imag );
    _real = c.real() / (T)denominator;
    _imag = c.imag() / (T)denominator;
}


template<typename T>
void Complex<T>::reciprocal(Complex& out) const
{
    out = *this;
    out.reciprocal();
}


template<typename T>
T Complex<T>::modulus() const
{
    return ( std::sqrt( _real * _real + _imag * _imag ) );
}


template<typename T>
bool Complex<T>::operator == (const Complex& right) const
{
    return ( (_real == right._real) && (_imag == right._imag) );
}


template<typename T>
bool Complex<T>::operator != (const Complex& right) const
{
    return ( !(*this == right) );
}


template<typename T>
Complex<T> Complex<T>::operator + (const Complex& right) const
{
    Complex<T> result;
    add( right, result );
    return result;
}


template<typename T>
Complex<T>& Complex<T>::operator += (const Complex& right)
{
    add( right );
    return *this;
}


template<typename T>
Complex<T> Complex<T>::operator - (const Complex& right) const
{
    Complex<T> result;
    sub( right, result );
    return result;
}


template<typename T>
Complex<T>& Complex<T>::operator -= (const Complex& right)
{
    sub( right );
    return *this;
}


template<typename T>
Complex<T> Complex<T>::operator * (const Complex& right) const
{
    Complex<T> result;
    mul( right, result );
    return result;
}


template<typename T>
Complex<T>& Complex<T>::operator *= (const Complex& right)
{
    mul( right );
    return *this;
}


template<typename T>
Complex<T> Complex<T>::operator / (const Complex& right) const
{
    Complex<T> result;
    div( right, result );
    return result;
}


template<typename T>
Complex<T>& Complex<T>::operator /= (const Complex& right)
{
    div( right );
    return *this;
}


#endif // Complex_INCLUDED
