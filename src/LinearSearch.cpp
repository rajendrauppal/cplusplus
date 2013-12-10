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
#include "Types.h"


using std::cout;
using std::cin;
using std::endl;


const Int32 MAX_SIZE = 100;


bool LinearSearch(Int32 * items, Int32 size, Int32 key)
{
	if ( !items ) throw InvalidArrayException();
	if ( (size < 0) || (size > MAX_SIZE) ) throw InvalidSizeException();

	bool result = false;
	for ( Int32 i = 0; i < size; ++i ) {
		if ( key == items[i] ) result = true;
	}
	return result;
}


void PrintArray(Int32 * items, Int32 size)
{
	cout << "[ ";
	for ( Int32 i = 0; i < size-1; ++i ) {
		cout << items[i] << ", ";
	}
	cout << items[size-1] << " ]" << endl;
}


void Test_LinearSearch()
    /// Tests - LinearSearch
{
	Int32 * items = new Int32[MAX_SIZE];
	for ( Int32 i = 0; i < MAX_SIZE; ++i ) {
		items[i] = rand() % 100;
	}
	PrintArray(items, MAX_SIZE);

	for ( Int32 i = 0; i < MAX_SIZE; ++i ) {
		if ( LinearSearch(items, MAX_SIZE, i) )
			cout << i << " found!" << endl;
		else
			cout << i << " not found!" << endl;
	}
	delete [] items;
}


Int32 main()
    /// Driver program to test LinearSearch API
{
	Test_LinearSearch();

	cout << "Press Enter to continue..." << endl;
	cin.get();
	return 0;
}
