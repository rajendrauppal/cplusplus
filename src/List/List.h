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


#ifndef List_INCLUDED
#define List_INCLUDED


#include "../Types.h"
#include <list>

template<typename T>
class List
{
public:
    List();

    ~List();

    List(const List& other);

    List& operator = (const List& rhs);

    void push(T data);

    T pop();

    T peek() const;

    Int32 length() const;

    List& clone() const;

    List& reverse();

    bool empty() const;

    void clear();

    bool equals(const List& other) const;

    void resize(Int32 newsize, const T val);

private:
    class Node
    {
        Node * _next;
        T _data;
    };

    Node _node;
};


template<typename T>
List<T>::List()
{
}


template<typename T>
List<T>::~List()
{
}


#endif // List_INCLUDED
