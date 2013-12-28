//
// The MIT License (MIT)
//
// Copyright (c) 2013 Rajendra Kumar Uppal
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//


#include <iostream>
#include "String.h"
//#include <string>


using std::cout;
using std::cin;
using std::endl;


#define print(s) cout<<endl<<(s)<<endl


void Test_construction()
{    
    String s;
    print(s.c_str());

    String scopy("radar");
    print(scopy.c_str());
}


void Test_reverse()
{
    String s = "IP Address: 10.xx.xxx.x";
    s.reverse();
    print(s.c_str());

    String reversed;
    s.reverse(reversed);
    print(reversed.c_str());
}


void Test_clone()
{
    String s = "     This is a large  string \b\t\n to be cloned     .yeah!";
    String name = s.clone();
    print(s.c_str());
    print(name.c_str());
}


void Test_upperlower()
{
    String s("tHis is goNNa be all uPPercase StrinG!");
    s.upper();
    print(s.c_str());

    String s1("tHis is goNNa be all LoWeRcase StrinG!");
    s1.lower();
    print(s1.c_str());
}


void Test_split()
{
    String name = "function=split;mode=test;separator=semi-colon";
    vector<String> parts = name.split(';');
    for ( auto start = parts.begin(); start != parts.end(); ++start )
        print( (*start).c_str() );
}


void Test_trim()
{
    String text = "!@#$%^&*()~~function=trim;mode=test;pattern=!@#$%^&*()~~";
    String pattern = "!@#$%^&*()~";

    // get copy of trimmed string, text is unchanged
    String trimmed;
    text.trim( trimmed, pattern.c_str() );
    print( trimmed.c_str() );

    // trim text in-place
    text.trim( pattern.c_str() );
    print( text.c_str() );
    
    // trim from left, get a copy
    text = "!@#$%^&*()~~function=trim;mode=test;pattern=!@#$%^&*()~~";
    text.trimleft( trimmed, pattern.c_str() );
    print( trimmed.c_str() );

    // trim from right, get a copy
    text = "!@#$%^&*()~~function=trim;mode=test;pattern=!@#$%^&*()~~";
    text.trimright( trimmed, pattern.c_str() );
    print( trimmed.c_str() );

    // trim from left, in-place
    text = "!@#$%^&*()~~function=trim;mode=test;pattern=!@#$%^&*()~~";
    text.trimleft( pattern.c_str() );
    print( text.c_str() );

    // trim from right, in-place
    text = "!@#$%^&*()~~function=trim;mode=test;pattern=!@#$%^&*()~~";
    text.trimright( pattern.c_str() );
    print( text.c_str() );
}


void Test_compare()
{
    String s = "application";
    String t = "Apply";
    int result = s.compare_i( t );
    if ( result == -1 ) 
        print( s.c_str() );
    else if ( result == 1 )
        print( t.c_str() );

    result = s.compare( t );
    if ( result == -1 ) 
        print( s.c_str() );
    else if ( result == 1 )
        print( t.c_str() );
}


void Test_operators()
{
    String s = "C:\\Program Files\\Chrome";
    for ( size_t i = 0; i < s.length(); ++i )
        cout << s[i] << " ";
    cout << endl;
    cout << s.c_str() << endl;
    char c = s[s.length()];
    cout << c << endl;
}


int main()
{
    Test_construction();

    Test_reverse();
    
    Test_clone();
    
    Test_upperlower();
    
    Test_split();

    Test_trim();

    Test_compare();
    
    Test_operators();

    print("Press any key to continue...");
    cin.get();
    return 0;
}
