

#include <iostream>


#include "Exceptions.h"


using std::cout;
using std::cin;
using std::endl;


#define uint unsigned int
#define cuint const unsigned int


cuint MAX_SIZE = 10;


int BinarySearch_Iterative(int * items, cuint size, int key)
	/// Iterative binary search function
	/// Input: integer array, items, size of the array, size, key to search, key
	/// Output: returns 0-based index of the integer found, -1 if not found
	/// Throws InvalidArrayException (defined in BinarySearch.h) in case NULL is passed
	/// Throws InvalidSizeException (defined in BinarySearch.h) in case size <= 0 OR size > MAX_SIZE
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


int BinarySearch_Recursive(int * items, cuint start, cuint end, int key)
	/// Recursive binary search function
	/// Input: integer array, items, start index, end index, key to search, key
	/// Output: returns 0-based index of the integer found, -1 if not found
	/// Throws InvalidArrayException (defined in BinarySearch.h) in case NULL is passed
	/// Throws InvalidSizeException (defined in BinarySearch.h) in case start < 0 OR (end + 1) > MAX_SIZE
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


void PrintArray(int * items, cuint size)
	/// Displays the array items of size to the console.
{
	cout << "[ ";
	for (uint i = 0; i < (size - 1); ++i)
		cout << items[i] << ", ";
	cout << items[size - 1] << " ]\n";
}


int compare(const void * first, const void * second)
	/// compare predicate to qsort function.
{
	return ( *(const int*)first - *(const int *)second );
}


void Test_BinarySearch_Iterative(int * items)
	/// Iterative binary search tests
{
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
	/// Recursive binary search tests
{
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
