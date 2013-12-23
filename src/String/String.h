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

	explicit String(const char* s);
		/// creates a String object from user provided
		/// read-only String.

	String(const String& other);
		/// creates a copy of other String.

	String& operator=(const String& rhs);
		/// assignes rhs String to this String.

	virtual ~String();
		/// destroys this String.
	
	String& operator+(const String& right);
		/// concatenates this string and right string and returns
		/// a reference to this string.

	void clear();
		/// empties this String.

	size_t length() const;
		/// returns length of this String.

	bool empty() const;
		/// returns true if String is empty false otherwise.

	void reverse();
		/// reverses this String.

	String& reverse() const;
		/// creates a new String with this String reversed.

	String& clone() const;
		/// creates a new String, exact copy of this String.
		/// same as copy constructor.

	vector<String> split(char c);
		/// splits this String on c and returns a vector of Strings.

	const char * c_str() const;
		/// returns const char pointer to raw String representation
		/// of this String.
		
	void trim(const char * pattern = " ");
        /// trims this String from left and right based on characters
        /// given in pattern, default is whitespace.
	
	String& trim(const char * pattern = " ") const;
        /// trims this String from left and right based on characters
        /// given in pattern, default is whitespace. returns a new
        /// String, this String is not changed.
	
	void ltrim(const char * pattern = " ");
        /// trims this String from left based on characters
        /// given in pattern, default is whitespace.
	
	String& ltrim(const char * pattern = " ") const;
        /// trims this String from left based on characters
        /// given in pattern, default is whitespace. returns a new
        /// String, this String is not changed.

	void rtrim(const char * pattern = " ");
        /// trims this String from right based on characters
        /// given in pattern, default is whitespace.
	
	String& rtrim(const char * pattern = " ") const;
        /// trims this String from right based on characters
        /// given in pattern, default is whitespace. returns a new
        /// String, this String is not changed.
	
	int compare(String& s) const;
        /// case-sensitive compares this String to s
        /// returns: 0 on success, 
        /// 1 if this String is lexicographically greater than s, 
        /// -1 if this String is lexicographically less than s
	
	int icompare(String& s) const;
        /// case-insensitive compares this String to s
        /// returns: 0 on success, 
        /// 1 if this String is lexicographically greater than s, 
        /// -1 if this String is lexicographically less than s
	
	void upper();
        /// converts this String to uppercase.
	
	String& upper() const;
	    /// converts this String to uppercase and return a new
        /// String, this String is not changed.

	void lower();
        /// converts this String to lowercase.
	
	String& lower() const;
	    /// converts this String to lowercase and return a new
        /// String, this String is not changed.

	void append(const String& s);
        /// appends String s at the end of this String

    String& append(const String& s) const;
        /// appends String s at the end of this String
        /// returns a new String, this String is not changed.

private:
    char * _str;
    int _length;
};


String::String()
{
    _str = new char[1];
    _str = "";
    _length = 0;
}


String::String(const char* s)
{
    size_t newlen = strlen(s);
    _str = new char[newlen + 1];
    strcpy_s( _str, newlen, s );
    _str[newlen + 1] = '\0';
    _length = newlen + 1;
}


String::String(const String& other)
{
    size_t newlen = other.length();
    _str = new char[newlen + 1];
    strcpy_s( _str, newlen, other.c_str() );
    _str[newlen + 1] = '\0';
    _length = newlen + 1;
}


String& String::operator=(const String& rhs)
{
    if ( this != &rhs )
    {
        clear();
        size_t newlen = rhs.length();
        _str = new char[newlen + 1];
        strcpy_s( _str, newlen, rhs.c_str() );
        _str[newlen + 1] = '\0';
        _length = newlen + 1;
    }
    return *this;
}


String::~String()
{
    delete [] _str;
    _str = (char*)0;
    _length = 0;
}
	

String& String::operator+(const String& right)
{
    return *this;
}


void String::clear()
{
    delete [] _str;
    _str = (char*)0;
    _length = 0;
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
}


String& String::reverse() const
{
    String reversed;
    return reversed;
}


String& String::clone() const
{
    String cloned;
    return cloned;
}


vector<String> String::split(char c)
{
    vector<String> parts;
    return parts;
}


const char * String::c_str() const
{
    return _str;
}
		

void String::trim(const char * pattern)
{
}


String& String::trim(const char * pattern) const
{
    String trimmed;
    return trimmed;
}


void String::ltrim(const char * pattern)
{
}


String& String::ltrim(const char * pattern) const
{
    String ltrimmed;
    return ltrimmed;
}


void String::rtrim(const char * pattern)
{
}


String& String::rtrim(const char * pattern) const
{
    String rtrimmed;
    return rtrimmed;
}

	
int String::compare(String& s) const
{
    return 0;
}


int String::icompare(String& s) const
{
    return 0;
}


void String::upper()
{
}


String& String::upper() const
{
    String uppercase;
    return uppercase;
}


void String::lower()
{
}


String& String::lower() const
{
    String lowercase;
    return lowercase;
}


void String::append(const String& s)
{
}


String& String::append(const String& s) const
{
    String bigger;
    return bigger;
}


#endif // String_INCLUDED
