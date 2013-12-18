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
#include <list>
#include <algorithm>


using std::cout;
using std::cin;
using std::endl;


template<typename T>
void PrintList(List<T>& list)
{
    int i;
    int len = list.length();
    for ( i = 0; i < (len - 1); ++i ) { // test length()
        //cout << list.at(i) << " -> "; // test at()
        cout << list[i] << " -> "; // test operator[]
    }
    cout << list.at(i) << " -> [NULL]" << endl;
    cout << "Length = " << list.length() << endl << endl;
}


void Test_List()
{
    try {
        List<int> numbers; // test default ctor
        size_t i;
        for ( i = 0; i < 10; ++i ) {
            //numbers.push_back(rand() % 1000); // test push_back()
            numbers.push_front(rand() % 1000); // test push_front()
        }
        PrintList(numbers); // test length(), at(), operator[]

        List<int> reversed = numbers.reverse(); // test reverse() non-const
        PrintList(numbers);
        
        if ( reversed.reverse().reverse().equals(numbers) ) // test method chaining
            cout << "reverse worked fine" << endl;

        //numbers.resize(-1, 0); // test resize non-const
        //PrintList(numbers);

        //numbers.resize(0, 0);
        //PrintList(numbers);

        //numbers.resize(4, 0);
        //PrintList(numbers);

        //numbers.resize(15, 0);
        //PrintList(numbers);

        cout << numbers.peek_back() << endl; // test peek_back()
        cout << numbers.peek_front() << endl; // test peek_front()

        /*for ( i = 0; i < 10; ++i ) {
            cout << numbers.pop_back() << "::"; // test pop_back()
            cout << numbers.pop_front() << "::"; // test pop_front()
        }*/
        //PrintList(numbers); // test length(), at(), operator[]

        //cout << numbers.peek_back() << endl; // test peek_back()
        //cout << numbers.peek_front() << endl; // test peek_front()

        /*List<int> series = numbers; // test copy ctor
        if ( series.equals(numbers) ) // test equals()
            cout << "Equal" << endl;
        if ( series == numbers ) // test operator==
            cout << "Equal" << endl;
        if ( series != numbers ) // test operator!=
            cout << "Not Equal" << endl;
        else
            cout << "Equal" << endl;

        List<int> cloned;
        cloned = series; // test operator=
        PrintList( cloned );*/

        // test resize to make larger with 0 values
        List<string> names;
        cout << "start pushing..." << endl;
        for ( int i = 0; i < 50; ++i ) {
            names.push_front("push_front() is way faster than push_back()!");
        }
        //names.reverse();
        cout << "done pushing..." << endl;
        PrintList( names );

        // test parametrized constructor
        List<float> temperatures(100, 37.5f);
        PrintList( temperatures );

        // test assign function ( same as parameterized constructor )
        List<bool> status;
        status.assign( names.length(), true );
        PrintList( status );
    }
    catch ( ListException& e ) {
        cout << e.message() << endl;
    }
}


void Test_swap()
{
    List<int> first;
    List<int> second(4, 200);
    first.swap( second );
    PrintList( first );
    PrintList( second );
}


void Test_splice()
{
    List<int> first(3, 100);
    List<int> second(4, 200);
    first.splice( 100, second );
    PrintList( first );
    PrintList( second );
}


bool cond(char * first, char * second) 
{
    return !_strcmpi(first, second);
}


int main()
{
    Test_splice();
    cin.get();

    Test_swap();
    cin.get();

    Test_List();
    
    char * tokens[5] = {"comment","keyword","identifier","user-type","method"};
    List<char*> someids;
    for ( int i = 0; i < 5; ++i )
        someids.push_front( tokens[i] );

    for ( int i = 0; i < 5; ++i )
        cout << someids.find( tokens[i], cond ) << endl; // test find function

    cout << someids.find("Identifier", cond) << endl;

    /// test insert(key, val) function
    List<int> token_ids;
    for ( int i = 0; i < 5; ++i ) {
        token_ids.push_front( i + 1 );
    }
    PrintList( token_ids );

    token_ids.insert(1, 1, 555);
    PrintList( token_ids );

    token_ids.insert(0, 555);
    PrintList( token_ids );

    token_ids.insert(41, 555);
    PrintList( token_ids );

    token_ids.insert(444, 555);
    PrintList( token_ids );
    
    cout << "Press any key to continue..." << endl;
    cin.get();
    return 0;
}
