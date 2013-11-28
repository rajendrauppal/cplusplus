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

using std::cout;
using std::cin;
using std::endl;

#define uint unsigned int
#define cuint const unsigned int

cuint MAX_SIZE = 10;

/*
* Iterative binary search function

* Input: integer array, items, size of the array, size, key to search, key
* Output: returns 0-based index of the integer found, -1 if not found

* Throws InvalidArrayException (defined in BinarySearch.h) in case NULL is passed
* Throws InvalidSizeException (defined in BinarySearch.h) in case size <= 0 OR size > MAX_SIZE
*/
int BinarySearch_Iterative(int * items, cuint size, int key)
{
	if ( !items ) throw InvalidArrayException();
	if ( (size <= 0) || (size > MAX_SIZE) ) throw InvalidSizeException();

	uint start = 0;
	uint end = size - 1;

	while ( start <= end ) {
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

/*
* Recursive binary search function

* Input: integer array, items, start index, end index, key to search, key
* Output: returns 0-based index of the integer found, -1 if not found

* Throws InvalidArrayException (defined in BinarySearch.h) in case NULL is passed
* Throws InvalidSizeException (defined in BinarySearch.h) in case start < 0 OR (end + 1) > MAX_SIZE
*/
int BinarySearch_Recursive(int * items, cuint start, cuint end, int key)
{
	if ( !items ) throw InvalidArrayException();
	if ( (start < 0) || ((end + 1) > MAX_SIZE) ) throw InvalidSizeException();

	if ( start > end ) return -1;

	uint mid = ( start + end ) >> 1;
	int miditem = items[mid];
	if ( key == miditem )
		return mid;
	else if ( key < miditem )
		return BinarySearch_Recursive( items, start, mid - 1, key );
	else
		return BinarySearch_Recursive( items, mid + 1, end, key );
}

void Usage()
{
	cout << "Usage:" << endl;
	cout << "BinarySearch.exe <key>" << endl;
	cout << "Example: BinarySearch.exe" << endl;
}

void PrintArray(int * items, cuint size)
{
	cout << "[ ";
	for (uint i = 0; i < (size - 1); ++i)
		cout << items[i] << ", ";
	cout << items[size - 1] << " ]\n";
}

int compare(const void * first, const void * second)
{
	return ( *(const int*)first - *(const int *)second );
}

void Test_BinarySearch_Iterative(int * items)
{
	// Iterative binary search tests
	for ( uint i = 0; i < MAX_SIZE; ++i ) {
		int key = items[i];
		cout << "Looking for... " << key;
		int found_index = BinarySearch_Iterative( items, MAX_SIZE, key );
		if ( found_index != -1 ) {
			cout << "\tFound " << key << " at index " << found_index << endl;
		} else {
			cout << "\tNot found " << key << endl;
		}
	}
}

void Test_BinarySearch_Recursive(int * items)
{
	// Recursive binary search tests
	for ( uint i = 0; i < MAX_SIZE; ++i ) {
		int key = items[i];
		cout << "Looking for... " << key;
		int found_index = BinarySearch_Recursive( items, 0, MAX_SIZE - 1, key );
		if ( found_index != -1 ) {
			cout << "\tFound " << key << " at index " << found_index << endl;
		} else {
			cout << "\tNot found " << key << endl;
		}
	}
}

int main(int argc, char *argv[])
{
	if ( argc != 1 ) {
		Usage();
		exit(1);
	}

	int * items = new int[MAX_SIZE];
	for ( uint i = 0; i < MAX_SIZE; ++i )
		items[i] = rand() % 100;

	std::qsort(items, MAX_SIZE, sizeof(int), compare);
	PrintArray(items, MAX_SIZE);

	Test_BinarySearch_Iterative(items);
	Test_BinarySearch_Recursive(items);

	delete [] items;

	cout << "Press Enter to continue..." << endl;
	cin.get();
	return 0;
}
