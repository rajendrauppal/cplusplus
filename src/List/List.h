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
    ListException(string msg) : _msg(msg) {}
    string message() const { return _msg; }
private:
    std::string _msg;
};


template<typename T>
class List
{
public:
    /// Constructors
    List();
    List(int count, const T& value);
    List(const List& other);
    List& operator = (const List& rhs);
    ~List();

    /// Modifiers
    void assign(int count, const T& value);
    void push_back(T data);
    void push_front(T data);
    T pop_back();
    T pop_front();
    void clear();
    void resize(int newsize, const T& val);
    void insert(const T& key, const T& val);
    void insert(int n, const T& key, const T& val);
    void swap(List& other);

    /// Element access
    T peek_back() const;
    T peek_front() const;
    T at(size_t index) const;
    T operator [] (size_t pos) const;

    /// Capacity/Queries
    size_t length() const;
    bool empty() const;
    bool operator == (const List& other) const;
    bool operator != (const List& other) const;
    bool equals(const List& other) const;
    template<typename Condition> 
    bool find(const T& key, Condition c) const;

    /// Operations
    List<T>& reverse();
        /// reverse this list and returns a reference to it.

    void splice(const T& key, List& other);
        /// split the list at position where key is found
        /// and insert items from the other list.
        /// other list is destroyed.

    void remove(const T& val);
        /// Removes from this list all the elements 
        /// that compare equal to val.
    
    template<typename Condition> 
    void remove_if(Condition c);
        /// Removes from this list all the elements 
        /// for which Condition c returns true.

    void unique();
        /// Removes duplicate elements from this list
        /// based on equality (==) condition by default.

    template<typename Condition>
    void unique(Condition c);
        /// Takes as argument a specific comparison function 
        /// that determine the "uniqueness" of an element.
    
    void merge(List& other);
    
    template<typename Condition>
    void merge(List& other, Condition c);

    void sort();

    template<typename Condition>
    void sort(Condition c);

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

    bool _issorted();

    void _unique_sorted();
    
    void _unique_unsorted();
    
    template<typename Condition>
    void _unique_sorted(Condition c);
    
    template<typename Condition>
    void _unique_unsorted(Condition c);

    typename Node * _min(Node * node);

    template<typename Condition>
    typename Node * _min(Node * node, Condition c);
 };


// Constructors
template<typename T>
List<T>::List(): _headnode(new Node()), _length(0)
{
}


template<typename T>
List<T>::List(int count, const T& value): _headnode(new Node()), _length(0)
{
    resize( count, value );
}


template<typename T>
List<T>::List(const List& other)
{
    _headnode = new Node();
    _length = 0;
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
        int end = rhs.length() - 1;
        for ( int i = (rhs.length() - 1); i >= 0 ; i-- )
            this->push_front( rhs[i] );
    }
    return *this;
}


template<typename T>
List<T>::~List()
{
    clear();
}


// Modifiers
template<typename T>
void List<T>::assign(int count, const T& value)
{
    resize( count, value );
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
        throw ListException("list empty");
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
        throw ListException("list empty");
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
void List<T>::clear()
{
    while ( !empty() ) {
        pop_front();
    }
}


/// Strategy:
/// if newsize > current_size, 
///     create (newsize - current_size) nodes with data as val
/// else if newsize < current_size
///     remove (current_size - newsize) nodes from this list
template<typename T>
void List<T>::resize(int newsize, const T& val)
{
    if ( newsize < 0 )
        throw ListException("Invalid size requested");

    if ( 0 == newsize ) {
        clear();
        return;
    }

    int diff = newsize - this->length();
    if ( diff > 0 ) {
        while ( diff-- )
            this->push_back( val );
    }
    else {
        diff = -diff;
        while ( diff-- )
            this->pop_back();
    }
}


template<typename T>
void List<T>::insert(const T& key, const T& val)
    /// inserts val into list just before key.
    /// throws exception if list is empty or if key not found.
{
    if ( empty() )
        throw ListException("list empty");

    Node * prev = _headnode;
    Node * curr = _headnode->_next;

    while ( curr && (curr->_data != key) ) {
        prev = prev->_next;
        curr = curr->_next;
    }

    if ( !curr ) // key not found
        throw ListException("key not found");

    // key found at curr
    Node * n = new Node(val);
    prev->_next = n;
    n->_next = curr;
    _length++;
}


template<typename T>
void List<T>::insert(int n, const T& key, const T& val)
    /// inserts val n ( >= 1 ) times into list just before key.
    /// throws exception if list is empty or if key not found.
{
    if ( n <= 0 )
        return;

    if ( n == 1 ) {
        insert( key, val );
        return;
    }

    if ( empty() )
        throw ListException("list empty");

    Node * prev = _headnode;
    Node * curr = _headnode->_next;

    while ( curr && (curr->_data != key) ) {
        prev = prev->_next;
        curr = curr->_next;
    }

    if ( !curr ) // key not found
        throw ListException("key not found");

    // key found at curr
    Node * node = (Node*)0;
    while ( n-- ) {
        node = new Node(val);
        prev->_next = node;
        prev = prev->_next;
        _length++;
    }
    prev->_next = curr;
}


template<typename T>
void List<T>::swap(List& other)
{
    std::swap( this->_headnode, other._headnode );
    std::swap( this->_length, other._length );
}


// Element access
template<typename T>
T List<T>::peek_back() const
{
    if ( empty() )
        throw ListException("list empty");

    Node * current = _headnode;
    while ( current->_next )
        current = current->_next;

    return current->_data;
}


template<typename T>
T List<T>::peek_front() const
{
    if ( empty() )
        throw ListException("list empty");
    
    return _headnode->_next->_data;
}


template<typename T>
T List<T>::at(size_t index) const
{
    if ( empty() ) {
        throw ListException("list empty");
    }

    if ( index >= this->length() ) {
        throw ListException("out of bound access");
    }

    size_t count = 0;
    Node * curr = _headnode->_next;
    while ( count != index ) {
        curr = curr->_next;
        count++;
    }
    return curr->_data;
}


template<typename T>
T List<T>::operator [] (size_t pos) const
{
    return at(pos);
}


// Capacity/Queries
template<typename T>
size_t List<T>::length() const
{
    return _length;
}


template<typename T>
bool List<T>::empty() const
{
    return (_length == 0);
}


template<typename T>
bool List<T>::operator == (const List& other) const
{
    return this->equals(other);
}


template<typename T>
bool List<T>::operator != (const List& other) const
{
    return (!(*this == other));
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


template<typename T>
template<class Condition>
bool List<T>::find(const T& key, Condition c) const
{
    if ( empty() )
        return false;

    Node * curr = _headnode->_next;
    while ( curr ) {
        if ( c(key, curr->_data) )
            return true;
        curr = curr->_next;
    }
    return false;
}


// Operations
template<typename T>
List<T>& List<T>::reverse()
{
    if ( empty() )
        throw ListException("list empty");

    Node * prev = (Node*)0;
    Node * curr = _headnode->_next;

    while ( curr ) {
        Node * next = curr->_next;
        curr->_next = prev;
        prev = curr;
        curr = next;
    }
    _headnode->_next = prev;

    return *this;
}


template<typename T>
void List<T>::splice(const T& key, List& other)
{
    /// split the list at position where key is found
    /// and insert items from the other list.
    /// other list is destroyed.
    if ( empty() )
        throw ListException("list empty");

    Node * prev = _headnode;
    Node * curr = _headnode->_next;

    while ( curr && (curr->_data != key) ) {
        prev = prev->_next;
        curr = curr->_next;
    }

    if ( !curr ) // key not found
        throw ListException("key not found");

    // key found at curr, split here and 
    // insert elements from other list
    while ( !other.empty() ) {
        T val = other.pop_front();
        Node * n = new Node(val);
        prev->_next = n;
        prev = prev->_next;
        _length++;
    }
    prev->_next = curr;
}


template<typename T>
void List<T>::remove(const T& val)
    /// removes all elements equal to val from the list.
    /// traverse from first to last node
    /// if val is found, remove that node, go to next node
    /// if val not found, go to next node
{
    if ( empty() ) 
        return;

    Node * prev = _headnode;
    Node * curr = _headnode->_next;

    while ( curr ) {
        if ( curr->_data == val ) {
            Node * erase = curr;
            prev->_next = curr->_next;
            curr = prev->_next;

            delete erase;
            erase = (Node*)0;
            --_length;
        }
        else {
            prev = prev->_next;
            curr = curr->_next;
        }
    }
}


template<typename T>
template<typename Condition>
void List<T>::remove_if(Condition c)
    /// removes all elements meeting the condition c.
    /// traverse from first to last node
    /// if val is found, remove that node, go to next node
    /// if val not found, go to next node
{
    if ( empty() )
        return;

    Node * prev = _headnode;
    Node * curr = _headnode->_next;

    while ( curr ) {
        if ( c( curr->_data ) ) {
            Node * erase = curr;
            prev->_next = curr->_next;
            curr = prev->_next;

            delete erase;
            erase = (Node*)0;
            --_length;
        }
        else {
            prev = prev->_next;
            curr = curr->_next;
        }
    }
}


template<typename T>
void List<T>::unique()
    /// remove duplicate elements from the list, based on equality.
{
    // list is empty or contains one element
    // not worth removing duplicates!
    if ( 1 >= length() )
        return;

    if ( _issorted() )
        _unique_sorted();
    else
        _unique_unsorted();
}


template<typename T>
template<typename Condition>
void List<T>::unique(Condition c)
    /// remove duplicate elements from the list, based on condition c.
{
    // list is empty or contains one element
    // not worth removing duplicates!
    if ( 1 >= length() )
        return;

    if ( _issorted() )
        _unique_sorted(c);
    else
        _unique_unsorted(c);
}


template<typename T>
void List<T>::merge(List& other)
    /// merges two sorted lists.
    /// if lists aren't sorted, behaviour is undefined.
    /// puts all elements of other list into this list
    /// in sorted order, other list is destroyed.
{
    if ( this->empty() || other.empty() )
        return;
    if ( this != &other ) {
        while( !other.empty() ) {
            this->push_front( other.pop_front() );
        }
        this->sort();
    }
}


template<typename T>
template<typename Condition>
void List<T>::merge(List& other, Condition c)
{
    if ( this->empty() || other.empty() )
        return;
    if ( this != &other ) {
        while( !other.empty() ) {
            this->push_front( other.pop_front() );
        }
        this->sort(c);
    }
}


template<typename T>
void List<T>::sort()
{
    if ( 1 >= length() )
        return;
    if ( !_issorted() ) {
        Node * curr = _headnode->_next;
        while ( curr ) {
            Node * minnode = _min( curr );
            std::swap( curr->_data, minnode->_data );
            curr = curr->_next;
        }
    }
}


template<typename T>
template<typename Condition>
void List<T>::sort(Condition c)
{
    if ( 1 >= length() )
        return;
    if ( !_issorted() ) {
        Node * curr = _headnode->_next;
        while ( curr ) {
            Node * minnode = _min( curr, c );
            std::swap( curr->_data, minnode->_data );
            curr = curr->_next;
        }
    }
}


//
// Private methods
//
template<typename T>
bool List<T>::_issorted()
{
    if ( 1 >= length() )
        return true;

    Node * prev = _headnode->_next;
    Node * curr = prev->_next;

    while ( curr ) {
        if ( prev->_data > curr->_data )
            return false;
        prev = prev->_next;
        curr = curr->_next;
    }

    return true;
}


template<typename T>
void List<T>::_unique_sorted()
{
    // sorted list, run O(n) algorithm
    Node * prev = _headnode;
    Node * curr = _headnode->_next;

    while ( curr ) {
        if ( curr->_data == prev->_data ) {
            Node * erase = curr;
            prev->_next = curr->_next;
            curr = prev->_next;

            delete erase;
            erase = (Node*)0;
            --_length;
        }
        else {
            prev = prev->_next;
            curr = curr->_next;
        }
    }
}

    
template<typename T>
void List<T>::_unique_unsorted()
{
    // unsorted list, run O(n^2) algorithm
    Node * first = _headnode->_next;
    Node * prev = first;
    Node * curr = prev->_next;

    while (first->_next) {
        while ( curr ) {
            if ( curr->_data == first->_data ) {
                Node * erase = curr;
                prev->_next = curr->_next;
                curr = prev->_next;

                delete erase;
                erase = (Node*)0;
                --_length;
            }
            else {
                prev = prev->_next;
                curr = curr->_next;
            }
        }
        if ( first->_next ) {
            prev = first->_next;
            curr = prev->_next;
            first = prev;
        }
    }
}

    
template<typename T>
template<typename Condition>
void List<T>::_unique_sorted(Condition c)
{
    // sorted list, run O(n) algorithm
    Node * prev = _headnode;
    Node * curr = _headnode->_next;

    while ( curr ) {
        if ( c(curr->_data, prev->_data) ) {
            Node * erase = curr;
            prev->_next = curr->_next;
            curr = prev->_next;

            delete erase;
            erase = (Node*)0;
            --_length;
        }
        else {
            prev = prev->_next;
            curr = curr->_next;
        }
    }
}


template<typename T>    
template<typename Condition>
void List<T>::_unique_unsorted(Condition c)
{
    // unsorted list, run O(n^2) algorithm
    Node * first = _headnode->_next;
    Node * prev = first;
    Node * curr = prev->_next;

    while (first->_next) {
        while ( curr ) {
            if ( c( curr->_data, first->_data ) ) {
                Node * erase = curr;
                prev->_next = curr->_next;
                curr = prev->_next;

                delete erase;
                erase = (Node*)0;
                --_length;
            }
            else {
                prev = prev->_next;
                curr = curr->_next;
            }
        }
        if ( first->_next ) {
            prev = first->_next;
            curr = prev->_next;
            first = prev;
        }
    }
}


template<typename T>
typename List<T>::Node * List<T>::_min(Node * node)
{
    Node * minnode = (Node*)0;
    if ( node ) {
        minnode = node;
        Node * curr = node->_next;
        while ( curr ) {
            if ( curr->_data < minnode->_data )
                minnode = curr;
            curr = curr->_next;
        }
    }
    return minnode;
}


template<typename T>
template<typename Condition>
typename List<T>::Node * List<T>::_min(Node * node, Condition c)
{
    Node * minnode = (Node*)0;
    if ( node ) {
        minnode = node;
        Node * curr = node->_next;
        while ( curr ) {
            if ( c( curr->_data, minnode->_data ) )
                minnode = curr;
            curr = curr->_next;
        }
    }
    return minnode;
}


#endif // List_INCLUDED
