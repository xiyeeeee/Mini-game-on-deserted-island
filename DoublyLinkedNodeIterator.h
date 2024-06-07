#pragma once
#include "DoublyLinkedNode.h"
template <class DataType>
class DoublyLinkedNodeIterator
{
private:
    typedef DoublyLinkedNode<DataType> Node;
    Node* current; // Pointer to the current node in the iteration

public:
    // Constructor with a starting node
    DoublyLinkedNodeIterator(Node* start) : current(start) {}

    // New constructor to access the sentinel in the iterator's end() method
    DoublyLinkedNodeIterator(Node& node) : current(&node) {}

    // Pre-increment (++iterator)
    DoublyLinkedNodeIterator& operator++()
    {
        current = current->getNext();
        return *this;
    }

    // Post-increment (iterator++)
    DoublyLinkedNodeIterator& operator++(int)
    {
        DoublyLinkedNodeIterator& temp = *this;
        ++(*this);
        return temp;
    }

    // Pre-decrement (--iterator)
    DoublyLinkedNodeIterator& operator--()
    {
        current = current->getPrevious();
        return *this;
    }

    // Post-decrement (iterator--)
    DoublyLinkedNodeIterator& operator--(int)
    {
        DoublyLinkedNodeIterator& temp = *this;
        --(*this);
        return temp;
    }

    // Equality comparison (iterator == other)
    bool operator==(const DoublyLinkedNodeIterator& other) const
    {
        return current == other.current;
    }

    // Inequality comparison (iterator != other)
    bool operator!=(const DoublyLinkedNodeIterator& other) const
    {
        return current != other.current;
    }

    // Dereference operator (*iterator)
    DataType operator*() const
    {
        return current->getValue();
    }

    // Get the current node
    Node* getCurrent()
    {
        return current;
    }

    // Get an iterator pointing to the beginning
    DoublyLinkedNodeIterator begin()
    {
        return DoublyLinkedNodeIterator(current);
    }

    // Get an iterator pointing to the end (using NIL as the end marker)
    DoublyLinkedNodeIterator end()
    {
        return DoublyLinkedNodeIterator(Node::NIL);
    }
};
