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
#include <time.h>
#include "BinarySearch.h"

using std::cout;
using std::cin;
using std::endl;

#define uint unsigned int
#define cuint const unsigned int

cuint MAX_SIZE = 10;

int BinarySearch(int * items, cuint size, int key)
{
	if ( !items ) throw InvalidArrayException();
	if ( (size <= 0) && (size > MAX_SIZE) ) throw InvalidSizeException();

	uint start = 0;
	uint end = size - 1;

	while ( start < end ) {
		uint mid = ( start + end ) >> 1;
		int miditem = items[mid];
		if ( key == miditem ) {
			return mid;
		} else if ( key < miditem ) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	return -1;
}

void Usage()
{
	cout << "Usage:" << endl;
	cout << "BinarySearch.exe <key>" << endl;
	cout << "Example: BinarySearch.exe 5" << endl;
}

void PrintArray(int * items, cuint size)
{
	cout << "[ ";
	for (int i = 0; i < (size - 1); ++i)
		cout << items[i] << ", ";
	cout << items[size - 1] << " ]\n";
}

int main(int argc, char *argv[])
{
	if ( argc != 2 ) {
		Usage();
		exit(1);
	}

	int * items = new int[MAX_SIZE];
	for ( uint i = 0; i < MAX_SIZE; ++i )
		items[i] = rand() % 100;

	PrintArray(items, MAX_SIZE);

	int key = atoi(argv[1]);
	cout << "Looking for... " << key << endl;
	int found_index = BinarySearch( items, MAX_SIZE, key );
	if ( found_index != -1 ) {
		cout << "Found " << key << " at index " << found_index << endl;
	} else {
		cout << "Not found " << key << endl;
	}

	return 0;
}
