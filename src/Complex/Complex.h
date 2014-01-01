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

    bool operator == (const Complex& right) const;
    bool operator != (const Complex& right) const;
    bool operator >  (const Complex& right) const;
    bool operator >= (const Complex& right) const;
    bool operator <  (const Complex& right) const;
    bool operator <= (const Complex& right) const;

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
    _real(other._real)
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
}


template<typename T>
void Complex<T>::sub(const Complex& right)
{
}


template<typename T>
void Complex<T>::sub(const Complex& right, Complex& out) const
{
}


template<typename T>
void Complex<T>::mul(const Complex& right)
{
}


template<typename T>
void Complex<T>::mul(const Complex& right, Complex& out) const
{
}


template<typename T>
void Complex<T>::div(const Complex& right)
{
}


template<typename T>
void Complex<T>::div(const Complex& right, Complex& out) const
{
}


template<typename T>
T Complex<T>::real() const
{
}


template<typename T>
void Complex<T>::real(T re)
{
}


template<typename T>
T Complex<T>::imag() const
{
}


template<typename T>
void Complex<T>::imag(T im)
{
}


template<typename T>
bool Complex<T>::operator == (const Complex& right) const
{
}


template<typename T>
bool Complex<T>::operator != (const Complex& right) const
{
}


template<typename T>
bool Complex<T>::operator >  (const Complex& right) const
{
}


template<typename T>
bool Complex<T>::operator >= (const Complex& right) const
{
}


template<typename T>
bool Complex<T>::operator <  (const Complex& right) const
{
}


template<typename T>
bool Complex<T>::operator <= (const Complex& right) const
{
}


template<typename T>
Complex<T> Complex<T>::operator + (const Complex& right) const
{
}


template<typename T>
Complex<T>& Complex<T>::operator += (const Complex& right)
{
}


template<typename T>
Complex<T> Complex<T>::operator - (const Complex& right) const
{
}


template<typename T>
Complex<T>& Complex<T>::operator -= (const Complex& right)
{
}


template<typename T>
Complex<T> Complex<T>::operator * (const Complex& right) const
{
}


template<typename T>
Complex<T>& Complex<T>::operator *= (const Complex& right)
{
}


template<typename T>
Complex<T> Complex<T>::operator / (const Complex& right) const
{
}


template<typename T>
Complex<T>& Complex<T>::operator /= (const Complex& right)
{
}


#endif // Complex_INCLUDED
