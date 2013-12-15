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
#include <list>


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

    T * Iterator();

    void push_back(T data);

    void push_front(T data);

    T pop_back();

    T pop_front();

    T peek_back() const;

    T peek_front() const;

    size_t length() const;

    List& clone() const;

    void reverse();

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
    Node * _current;
    size_t _length;

    //
    // Private interface
    //
    Node * next();

    void reset();

    Node * begin();

    Node * end();
};


template<typename T>
List<T>::List() : _headnode(new Node()), _length(0), _current(_headnode)
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
    _headnode = new Node();
    _length = 0;
    _current = _headnode;
    Node * iter = other._headnode->_next;
    while ( iter ) {
        this->push_back( iter->_data );
        iter = iter->_next;
    }
}


template<typename T>
List<T>& List<T>::operator = (const List& rhs)
{
    if ( this != &rhs )
    {
        clear();

        Node * iter = rhs.next();
        while ( iter ) {
            this->push_back( iter->_data );
            iter = iter->_next;
        }
    }
    return *this;
}


template<typename T>
T * List<T>::Iterator()
{
    T * pdata = &next()->_data;
    return pdata;
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
        Node * prev = _headnode;
        Node * curr = prev->_next;

        while ( curr->_next ) {
            prev = prev->_next;
            curr = curr->_next;
        }
        T data = curr->_data;
        delete curr;
        curr = (Node*)0;
        prev->_next = (Node*)0;
        _length--;
        return data;
    }
}


template<typename T>
T List<T>::pop_front()
{
    if ( empty() ) {
        throw EmptyListException("list empty");
    }
    else {
        T data = _headnode->_next->_data;
        Node * n = _headnode->_next;
        _headnode->_next = _headnode->_next->_next;
        delete n;
        n = (Node*)0;
        _length--;
        return data;
    }
}


template<typename T>
T List<T>::peek_back() const
{
    if ( empty() ) {
        throw EmptyListException("list empty");
    }
    else {
        Node * current = _headnode;
        while ( current->_next ) {
            current = current->_next;
        }
        return current->_data;
    }
}


template<typename T>
T List<T>::peek_front() const
{
    if ( empty() ) {
        throw EmptyListException("list empty");
    }
    else {
        return _headnode->_next->_data;
    }
}


template<typename T>
size_t List<T>::length() const
{
    return _length;
}


template<typename T>
List<T>& List<T>::clone() const
{
    List<T> cloned;
    Node * current = _headnode->_next;
    while ( current ) {
        cloned.push_back( current->_data );
        current = current->_next;
    }
    return cloned;
}


template<typename T>
void List<T>::reverse()
{
    if ( empty() ) {
        throw EmptyListException("list empty");
    }
    Node * prev = (Node*)0;
    Node * curr = _headnode->_next;

    while ( curr ) {
        Node * next = curr->_next;
        curr->_next = prev;
        prev = curr;
        curr = next;
    }
    _headnode->_next = curr;
}


template<typename T>
List<T>& List<T>::reverse() const
{
    List<T> reversed;
    Node * current = _headnode->_next;
    while ( current ) {
        reversed->push_front( current->_data );
        current = current->_next;
    }
    return reversed;
}


template<typename T>
bool List<T>::empty() const
{
    return (_length == 0);
}


template<typename T>
void List<T>::clear()
{
    while ( !empty() ) {
        pop_front();
    }
}


template<typename T>
bool List<T>::equals(const List& other) const
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


/// Strategy:
/// if newsize > current_size, 
///     create (newsize - current_size) nodes with data as val
/// else if newsize < current_size
///     remove (current_size - newsize) nodes from this list
template<typename T>
void List<T>::resize(size_t newsize, const T val)
{
    if ( empty() ) {
        throw EmptyListException("list empty");
    }

    int diff = newsize - this->length();
    if ( diff > 0 ) 
    {
        while ( diff-- )
            this->push_back( val );
    }
    else if ( diff < 0 ) 
    {
        diff = -diff;
        while ( diff-- )
            this->pop_back();
    }
}


//
// Private interface
//
template<typename T>
typename List<T>::Node * List<T>::begin()
    /// Returns pointer to first node.
{
    return _headnode->_next;
}


template<typename T>
typename List<T>::Node * List<T>::next()
    /// Returns traversal pointer pointing to current node.
{
    _current = _current->_next;
    return _current;
}


template<typename T>
typename List<T>::Node * List<T>::end()
    /// Returns pointer to last node.
{
    Node * curr = _headnode;
    while ( curr->_next ) {
        curr = curr->_next;
    }
    return curr;
}


template<typename T>
void List<T>::reset()
    /// Resets traversal pointer to head node.
{
    _current = _headnode;
}


#endif // List_INCLUDED
