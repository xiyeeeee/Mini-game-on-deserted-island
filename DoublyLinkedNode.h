#pragma once
template <class DataType>
class DoublyLinkedNode
{
public:
    typedef DoublyLinkedNode<DataType> Node;
    static Node NIL; // Static member representing a null node

private:
    DataType value; // Data stored in the node
    Node* next;     // Pointer to the next node in the list
    Node* previous; // Pointer to the previous node in the list

public:
    // Default constructor
    DoublyLinkedNode()
    {
        value = DataType();
        next = &NIL;
        previous = &NIL;
    }

    // Overloaded constructor with a value parameter
    DoublyLinkedNode(const DataType& aValue)
    {
        value = aValue;
        next = &NIL;
        previous = &NIL;
    }

    // Add a node before the current one (New Node is nearer the Head)
    void prepend(Node* newNode)
    {
        newNode->next = this;

        // Check if there is a previous node
        if (this->previous != &NIL)
        {
            newNode->previous = this->previous;
            this->previous->next = newNode;
        }

        this->previous = newNode;
    }

    // Add a node after the current one (Current Node is nearer the Head)
    void append(Node* newNode)
    {
        newNode->previous = this;

        // Check if there is a next node
        if (this->next != &NIL)
        {
            newNode->next = this->next;
            this->next->previous = newNode;
        }

        this->next = newNode;
    }

    // Delete the current node from the list. Pay attention to the sequence.
    void remove()
    {
        // Update the pointers of the surrounding nodes
        if (this->previous != &NIL)
        {
            this->previous->next = this->next;
        }

        if (this->next != &NIL)
        {
            this->next->previous = this->previous;
        }

        // Delete the current node
        delete this;
    }

    // Get a reference to the value stored in the node
    DataType& getValue()
    {
        return value;
    }

    // Get a pointer to the next node
    Node* getNext() const
    {
        return next;
    }

    // Get a pointer to the previous node
    Node* getPrevious() const
    {
        return previous;
    }
};

// Initialize the static member representing a null node
template <class DataType>
typename DoublyLinkedNode<DataType>::Node DoublyLinkedNode<DataType>::NIL;

