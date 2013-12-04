/*

Exceptions.h

$Id: ~/git/C++/src/Exceptions.h $

Definition of the Exceptions class. Common exceptions class to be used by
all other individual modules.

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

#ifndef Exceptions_INCLUDED
#define Exceptions_INCLUDED

#include <string>

using std::string;

class CPPExceptions
{
public:
	virtual string message() { return ""; }
};

class InvalidInputException : public CPPExceptions
{
public:
	virtual string message() { return "Undefined"; }
};

class InvalidArrayException : public CPPExceptions
{
public:
	virtual string message() { return "Invalid Array!"; }
};

class InvalidSizeException : public CPPExceptions
{
public:
	virtual string message() { return "Invalid Size!"; }
};

class InvalidInputExceptionFibonacci : public CPPExceptions
{
public:
	virtual string message() { return "Factorial of negative number is undefined!"; }
};

class ZeroLCMException : public CPPExceptions
{
public:
	virtual string message() { return "LCM was zero!"; }
};

#endif // Exceptions_INCLUDED
