//
// String.h
//
// Definition of the String class.
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


#ifndef String_INCLUDED
#define String_INCLUDED


#include <vector>


using std::vector;


class String
    /// definition of the String class.
    /// gives same functionality as std::String
    /// plus some additional features.
{
public:
    String();
        /// creates an empty String.

    String(const char* s);
        /// creates a String object from user provided
        /// read-only String.

    String(const char * start, const char * end);
        /// creates a String object copying characters
        /// from start to end.

    String(const String& other);
        /// creates a copy of other String.

    String& operator = (const String& rhs);
        /// assignes rhs String to this String.

    virtual ~String();
        /// destroys this String.
	
    bool operator == (const String& right) const;
    bool operator != (const String& right) const;
    bool operator >  (const String& right) const;
    bool operator >= (const String& right) const;
    bool operator <  (const String& right) const;
    bool operator <= (const String& right) const;

    String operator +  (const String& right) const;
    String operator += (const String& right);
    
    void clear();
        /// empties this String.

    size_t length() const;
        /// returns length of this String.

    bool empty() const;
        /// returns true if String is empty false otherwise.

    void reverse();
        /// reverses this String.

    void reverse(String& r) const;
        /// creates a new String with this String reversed.

    String clone() const;
        /// creates a new String, exact copy of this String.
        /// same as copy constructor.

    vector<String> split(char c = ' ') const;
        /// splits this String on c and returns a vector of Strings.
        /// this string is unchanged.

    const char * c_str() const;
        /// returns const char pointer to raw String representation
        /// of this String.
		
    void trim(const char * pattern = " ");
        /// trims this String from left and right based on characters
        /// given in pattern, default is whitespace.
	
    void trim(String& t, const char * pattern = " ") const;
        /// trims this String from left and right based on characters
        /// given in pattern, default is whitespace. returns a new
        /// String t, 'this' String is not changed.
	
    void trimleft(const char * pattern = " ");
        /// trims this String from left based on characters
        /// given in pattern, default is whitespace.
	
    void trimleft(String& t, const char * pattern = " ") const;
        /// trims this String from left based on characters
        /// given in pattern, default is whitespace. returns a new
        /// String, this String is not changed.

    void trimright(const char * pattern = " ");
        /// trims this String from right based on characters
        /// given in pattern, default is whitespace.
	
    void trimright(String& t, const char * pattern = " ") const;
        /// trims this String from right based on characters
        /// given in pattern, default is whitespace. returns a new
        /// String, this String is not changed.
	
    int compare(const String& s) const;
        /// case-sensitive compares this String to s
        /// returns: 0 on success, 
        /// 1 if this String is lexicographically greater than s, 
        /// -1 if this String is lexicographically less than s
	
    int compare_i(const String& s) const;
        /// case-insensitive compares this String to s
        /// returns: 0 on success, 
        /// 1 if this String is lexicographically greater than s, 
        /// -1 if this String is lexicographically less than s
	
    void upper();
        /// converts this String to uppercase.
	
    void upper(String& u) const;
        /// converts this String to uppercase and return a new
        /// String, this String is not changed.

    void lower();
        /// converts this String to lowercase.
	
    void lower(String& l) const;
        /// converts this String to lowercase and return a new
        /// String, this String is not changed.

    void capitalize();
        /// Capitalizes this string.
        /// e.g., input: "this is a string"
        /// output: "This Is A String"

    void capitalize(String& c) const;
        /// Returns a copy of capitalized string.

    void append(const String& s);
        /// appends String s at the end of this String

    void append(const String& s, String& r) const;
        /// appends String s at the end of this String
        /// returns a new String, this String is not changed.

private:
    char * _str;
    size_t _length;

    size_t _size(const char * s) const;
    void _construct(const char * right);
};


String::String()
{
    _str = new char[1];
    _str = "";
    _length = 0;
}


String::String(const char* s)
{
    _construct( s );
}


String::String(const char * start, const char * end)
{
    size_t newlen = 1;
    const char * temp = start;
    while ( temp != end ) {
        temp++;
        newlen++;
    }
    _str = new char[newlen];
    temp = start;
    size_t i = 0;
    while ( temp != end ) {
        _str[i++] = *temp++;
    }
    _str[i] = '\0';
    _length = newlen - 1;
}


String::String(const String& other)
{
    _construct( other.c_str() );
}


String& String::operator = (const String& rhs)
{
    if ( this != &rhs )
    {
        clear();
        _construct( rhs.c_str() );
    }
    return *this;
}


String::~String()
{
    clear();
}
	

bool String::operator == (const String& right) const
{
    return ( compare(right) == 0 );
}


bool String::operator != (const String& right) const
{
    return ( compare(right) == 0 );
}


bool String::operator >  (const String& right) const
{
    return ( compare(right) == 1 );
}


bool String::operator >= (const String& right) const
{
    return ( compare(right) >= 0 );
}


bool String::operator <  (const String& right) const
{
    return ( compare(right) == -1 );
}


bool String::operator <= (const String& right) const
{
    return ( compare(right) <= 0 );
}


String String::operator + (const String& right) const
{
    return *this;
}


String String::operator += (const String& right)
{
    return *this;
}


void String::clear()
{
    if ( length() ) {
        delete [] _str;
        _str = 0;
        _length = 0;
    }
}


size_t String::length() const
{
    return _length;
}


bool String::empty() const
{
    return (_length == 0);
}


void String::reverse()
{
    size_t start = 0, end = length() - 1;
    while ( start < end ) {
        std::swap( _str[start], _str[end] );
        start++;
        end--;
    }
}


void String::reverse(String& r) const
{
    r = *this;
    r.reverse();
}


String String::clone() const
{
    return String(*this);
}


vector<String> String::split(char c) const
{
    vector<String> parts;

    size_t len = length();
    const char * start = &_str[0];
    const char * end = &_str[len];
    const char * part_end = start;

    while ( start != end ) {
        while ( (part_end != end) && (*part_end != c) ) {
            part_end++;
        }
        String part( start, part_end );
        parts.push_back( part );
        start = part_end++;
    }

    return parts;
}


const char * String::c_str() const
{
    return _str;
}
		

void String::trim(const char * pattern)
{
}


void String::trim(String& t, const char * pattern) const
{
}


void String::trimleft(const char * pattern)
{
}


void String::trimleft(String& t, const char * pattern) const
{
}


void String::trimright(const char * pattern)
{
}


void String::trimright(String& t, const char * pattern) const
{
}

	
int String::compare(const String& s) const
{
    return 0;
}


int String::compare_i(const String& s) const
{
    return 0;
}


void String::upper()
{
    char * temp = _str;
    while ( *temp ) {
        if (*temp >= 'a' && *temp <= 'z')
            *temp -= 32;
        temp++;
    }
}


void String::upper(String& u) const
{
    u = *this;
    u.upper();
}


void String::lower()
{
    char * temp = _str;
    while ( *temp ) {
        if (*temp >= 'A' && *temp <= 'Z')
            *temp += 32;
        temp++;
    }
}


void String::lower(String& l) const
{
    l = *this;
    l.lower();
}


void String::capitalize()
{
    if ( empty() )
        return;
}


void String::capitalize(String& c) const
{
}


void String::append(const String& s)
{
    *this += s;
}


void String::append(const String& s, String& r) const
{
    r = *this + s;
}


//
// Private methods
//
size_t String::_size(const char * s) const
{
    if ( !s ) return 0;
    size_t length = 0;
    while ( *s++ )
        length++;
    return length;
}


void String::_construct(const char * right)
{
    size_t newlen = _size( right ) + 1;
    _str = new char[newlen];
    strcpy_s( _str, newlen, right );
    _length = newlen - 1;
}


#endif // String_INCLUDED
