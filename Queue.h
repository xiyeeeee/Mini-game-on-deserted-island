#pragma once
#include "List.h"
template<class T>
class Queue
{
private:
    List<T>* fElements; // Pointer to a List object to store the elements of the queue
    T value;            // Temporary variable to store the value when dequeuing

public:
    // Default Constructor
    Queue()
    {
        fElements = new DoublyLinkedList<T>(); // Create a new DoublyLinkedList to store elements
    }

    // Destructor
    ~Queue()
    {
        delete fElements; // Delete the dynamically allocated list when the queue is destroyed
    }

    // Check if the queue is empty
    bool isEmpty() const
    {
        return fElements->isEmpty(); // Delegates to the isEmpty function of the underlying list
    }

    // Get the size of the queue
    int size() const
    {
        return fElements->size(); // Delegates to the size function of the underlying list
    }

    // Add an item to the back of the queue (enqueue)
    void enqueue(const T& aItem)
    {
        fElements->push_back(aItem); // Adds an item to the end of the underlying list
    }

    // Remove and return the item from the front of the queue (dequeue)
    const T& dequeue()
    {
        fElements->pop_front(value); // Removes and retrieves the item from the front of the list
        return value;                 // Returns the dequeued value
    }
};
