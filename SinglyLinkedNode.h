#pragma once
template<class DataType>
class SinglyLinkedNode
{
public:
    // Define Node type for simplicity
    typedef SinglyLinkedNode<DataType> Node;

    // Static instance representing the end of the linked list
    static Node NIL;

private:
    DataType value;  // Data stored in the node
    Node* next;      // Pointer to the next node in the linked list

public:
    // Default constructor
    SinglyLinkedNode()
    {
        value = DataType();  // Default value for DataType
        next = &NIL;         // Initialize next to the NIL instance
    }

    // Constructor with a given value
    SinglyLinkedNode(const DataType& aValue)
    {
        value = aValue;
        next = &NIL;
    }

    // Get the value stored in the node
    DataType& getValue()
    {
        return value;
    }

    // Set the next node in the linked list
    void setNext(Node* node)
    {
        next = node;
    }

    // Get a pointer to the next node in the linked list
    Node* getNext() const
    {
        return next;
    }
};

// Initialize the static NIL instance for the SinglyLinkedNode template
template<class DataType>
SinglyLinkedNode<DataType> SinglyLinkedNode<DataType>::NIL;

