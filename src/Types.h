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


#ifndef Types_INCLUDED
#define Types_INCLUDED


#if defined(_MSC_VER) 
	//
	// Windows/Visual C++
	//
	typedef signed char             Int8;
	typedef unsigned char           UInt8;
	typedef signed short            Int16;
	typedef unsigned short          UInt16;
	typedef signed int              Int32;
	typedef unsigned int            UInt32;
	typedef signed __int64          Int64;
	typedef unsigned __int64        UInt64;
	#if defined(_WIN64)
		typedef signed __int64      IntPtr;
		typedef unsigned __int64    UIntPtr;
	#else
		typedef signed long         IntPtr;
		typedef unsigned long       UIntPtr;
	#endif
#elif defined(__GNUC__) || defined(__clang__)
	//
	// Unix/GCC/Clang
	//
	typedef signed char             Int8;
	typedef unsigned char           UInt8;
	typedef signed short            Int16;
	typedef unsigned short          UInt16;
	typedef signed int              Int32;
	typedef unsigned int            UInt32;
	typedef signed long             IntPtr;
	typedef unsigned long           UIntPtr;
	#if defined(__LP64__)
		typedef signed long         Int64;
		typedef unsigned long       UInt64;
	#else
		typedef signed long long    Int64;
		typedef unsigned long long  UInt64;
	#endif
#endif


#endif // Types_INCLUDED
