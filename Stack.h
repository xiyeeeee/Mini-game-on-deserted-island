#pragma once
#include "List.h"              
#include "DoublyLinkedList.h"  
template<class T>
class Stack
{
private:
    List<T>* fElements;  // Pointer to the list of elements

public:
    // Constructor: create a stack with a doubly linked list
    Stack()
    {
        fElements = new DoublyLinkedList<T>();
    }

    // Destructor: release the memory allocated for the list
    ~Stack()
    {
        delete fElements;
    }

    // Check if the stack is empty
    bool isEmpty() const
    {
        return fElements->isEmpty();
    }

    // Get the number of elements in the stack
    int size() const
    {
        return fElements->size();
    }

    // Push an item onto the top of the stack
    void push(const T& aItem)
    {
        fElements->push_front(aItem);
    }

    // Pop an item from the top of the stack
    // Returns true if the pop operation is successful, false otherwise
    bool pop(T& aItem)
    {
        return fElements->pop_front(aItem);
    }

    // Get the item at the top of the stack without removing it
    const T& top()
    {
        return (*fElements)[0];
    }
};
