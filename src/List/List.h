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


#include <iostream>
#include <string>


using std::string;


class ListException : public std::exception
{
public:
    virtual string message() = 0;
};


class EmptyListException : public ListException
{
public:
    EmptyListException(string msg) : _msg(msg) {}
    string message() { return _msg; }
private:
    std::string _msg;
};


template<typename T>
class List
{
public:
    List();

    ~List();

    List(const List& other);

    List& operator = (const List& rhs);

    void push_back(T data);

    void push_front(T data);

    T pop_back();

    T pop_front();

    T peek_back() const;

    T peek_front() const;

    size_t length() const;

    List& clone() const;

    List& reverse();

    List& reverse() const;

    bool empty() const;

    void clear();

    bool equals(const List<T>& other) const;

    void resize(size_t newsize, const T val);

private:
    struct Node
    {
    public:
        Node * _next;
        T _data;
        
        Node() : _next((Node*)0) 
        {}
        
        explicit Node(T data) : _data(data), _next((Node*)0) 
        {}
    };

    Node * _headnode;
    size_t _length;
};


template<typename T>
List<T>::List() : _headnode(new Node()), _length(0)
{
}


template<typename T>
List<T>::~List()
{
    clear();
}


template<typename T>
List<T>::List(const List& other)
{
}


template<typename T>
List<T>& List<T>::operator = (const List& rhs)
{
    if ( this != &rhs )
    {
    }
    return *this;
}


template<typename T>
void List<T>::push_back(T data)
{
    if ( empty() ) {
        _headnode->_next = new Node(data);
    }
    else {
        Node * current = _headnode;
        while ( current->_next ) {
            current = current->_next;
        }
        current->_next = new Node(data);
    }
    _length++;
}


template<typename T>
void List<T>::push_front(T data)
{
    Node * newnode = new Node(data);
    if ( !empty() )
        newnode->_next = _headnode->_next;
    _headnode->_next = newnode;
    _length++;
}


template<typename T>
T List<T>::pop_back()
{
    if ( empty() ) {
        throw EmptyListException("list empty");
    }
    else {
        Node * current = _headnode;
        while ( current->_next->_next ) {
            current = current->_next;
        }
        T data = current->_data;
        delete current;
        current = (Node*)0;
        _length--;
        return data;
    }
}


template<typename T>
T List<T>::pop_front()
{
    _length--;
}


template<typename T>
T List<T>::peek_back() const
{
}


template<typename T>
T List<T>::peek_front() const
{
}


template<typename T>
size_t List<T>::length() const
{
    return _length;
}


template<typename T>
List<T>& List<T>::clone() const
{
}


template<typename T>
List<T>& List<T>::reverse()
{
}


template<typename T>
List<T>& List<T>::reverse() const
{
}


template<typename T>
bool List<T>::empty() const
{
    return (_length == 0);
}


template<typename T>
void List<T>::clear()
{
}


template<typename T>
bool List<T>::equals(const List<T>& other) const
{
    if ( other.length() != this->length() )
        return false;

    Node * left = this->_headnode->_next;
    Node * right = other._headnode->_next;
    while ( left ) {
        if ( left->_data != right->_data )
            return false;
        left = left->_next;
        right = right->_next;
    }

    return true;
}


template<typename T>
void List<T>::resize(size_t newsize, const T val)
{
}


#endif // List_INCLUDED
