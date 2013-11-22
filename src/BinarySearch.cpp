
/*
* AUTHOR : Rajendra Kumar Uppal
* DATE : 11/22/2013
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int BinarySearch()
{
	return 0;
}

void usage()
{
	cout << "Usage:" << endl;
	cout << "BinarySearch.exe <Array> <SearchItem>" << endl;
}

int main(int argc, char *argv[])
{
	if ( argc != 2 ) {
		usage();
		exit(1);
	}
	return 0;
}