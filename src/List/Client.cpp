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
#include "List.h"

using std::cout;
using std::cin;
using std::endl;


void Test_List()
{
    List<int> numbers;
    for ( int i = 0; i < 10; ++i ) {
        numbers.push_back(rand() % 1000);
    }

    numbers.resize( 10, 0 );

    for ( size_t i = 0; i < (numbers.length() - 1); ++i ) {
        int * data = numbers.Iterator();
        cout << *data << " -> ";
    }
    cout << *numbers.Iterator() << " -> [NULL]" << endl;
    cout << "Length: " << numbers.length() << endl;

    List<int> marks;
    for ( int i = 0; i < 10; ++i ) {
        marks.push_back(rand() % 1000);
    }

    for ( size_t i = 0; i < (marks.length() - 1); ++i ) {
        int * data = marks.Iterator();
        cout << *data << " -> ";
    }
    cout << *marks.Iterator() << " -> [NULL]" << endl;
    cout << "Length: " << marks.length() << endl;

    if ( numbers.equals(marks) ) {
        cout << "Equal" << endl;
    }
    else {
        cout << "Not Equal" << endl;
    }

    List<int> series = numbers;
    if ( series.equals(numbers) ) {
        cout << "Equal" << endl;
    }
    else {
        cout << "Not Equal" << endl;
    }

    if ( numbers.equals(series) ) {
        cout << "Equal" << endl;
    }
    else {
        cout << "Not Equal" << endl;
    }
}


int main()
{
    //Test_List();

    // experimenting with std::list
    std::list<int> nums(10, 0);
    std::list<int>::const_iterator start = nums.begin();
    std::list<int>::const_iterator end = nums.end();
    while ( start != end ) {
        cout << *start << ",";
        start++;
    }
    cout << endl;

    cout << "Press any key to continue..." << endl;
    cin.get();
    return 0;
}
