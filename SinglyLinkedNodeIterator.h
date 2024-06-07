#pragma once
#include "SinglyLinkedNode.h"  

template<class DataType>
class SinglyLinkedNodeIterator
{
private:
    // Define Node type for simplicity
    typedef SinglyLinkedNode<DataType> Node;

    Node* current;  // Pointer to the current node in the iterator

public:
    // Constructor with a starting node
    SinglyLinkedNodeIterator(Node* start) : current(start) {}

    // Constructor to access the sentinel in the iterator's end() method
    SinglyLinkedNodeIterator(Node& node) : current(&node) {}

    // Pre-increment: move to the next node
    SinglyLinkedNodeIterator& operator++()
    {
        current = current->getNext();
        return *this;
    }

    // Post-increment: return the iterator and then move to the next node
    SinglyLinkedNodeIterator& operator++(int)
    {
        SinglyLinkedNodeIterator& temp = *this;
        ++(*this);
        return temp;
    }

    // Equality comparison: check if two iterators are pointing to the same node
    bool operator==(const SinglyLinkedNodeIterator& other) const
    {
        return current == other.current;
    }

    // Inequality comparison: check if two iterators are not pointing to the same node
    bool operator!=(const SinglyLinkedNodeIterator& other) const
    {
        return current != other.current;
    }

    // Dereference operator: get the value of the current node
    DataType operator*() const
    {
        return current->getValue();
    }

    // Get the pointer to the current node
    Node* getCurrent()
    {
        return current;
    }

    // Begin method: return a new iterator starting from the current node
    SinglyLinkedNodeIterator begin()
    {
        return SinglyLinkedNodeIterator(current);
    }

    // End method: return an iterator pointing to the end marker (NIL)
    SinglyLinkedNodeIterator end()
    {
        return SinglyLinkedNodeIterator(Node::NIL);  // Using NIL as the end marker
    }
};

