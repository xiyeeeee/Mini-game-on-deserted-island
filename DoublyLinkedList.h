#pragma once
#include "DoublyLinkedNode.h"
#include "DoublyLinkedNodeIterator.h"
#include "List.h"

template<class T>
class DoublyLinkedList : public List<T>
{
private:
    // Node typedef for brevity
    typedef DoublyLinkedNode<T> Node;

    // Pointers to the first and last nodes
    Node* head;
    Node* last;

    // Count of elements in the list
    int count;

public:
    // Iterator typedef for brevity
    typedef DoublyLinkedNodeIterator<T> Iterator;

    // Default constructor initializes the head, last, and count
    DoublyLinkedList() : head(&(Node::NIL)), last(&(Node::NIL)), count(0) {}

    // Constructor with initial nodes for flexibility
    DoublyLinkedList(Node* firstNode, Node* lastNode) : head(firstNode), last(lastNode), count(1) {}

    // Destructor to clean up memory when the list is destroyed
    ~DoublyLinkedList()
    {
        // Iterator to traverse the list
        Iterator it = begin();

        // Loop through the list and delete each node
        while (it != it.end())
        {
            Node* toDelete = it.getCurrent();
            ++it;
            toDelete->remove();
        }
    }

    // Check if the list is empty
    bool isEmpty() const { return count == 0; }

    // Get the size of the list
    int size() const { return count; }

    // Add an element to the front of the list
    void push_front(const T& value)
    {
        Node* newNode = new Node(value);

        // If the list is not empty, update the current head
        if (head != &(Node::NIL))
        {
            head->prepend(newNode);
        }

        // Update head and last pointers
        head = newNode;

        // If the list was initially empty, update the last pointer
        if (last == &(Node::NIL))
            last = newNode;

        // Increment the count
        ++count;
    }

    // Add an element to the back of the list
    void push_back(const T& value)
    {
        Node* newNode = new Node(value);

        // If the list is not empty, update the current last
        if (last != &(Node::NIL))
        {
            last->append(newNode);
        }

        // Update last and head pointers
        last = newNode;

        // If the list was initially empty, update the head pointer
        if (head == &(Node::NIL))
            head = newNode;

        // Increment the count
        ++count;
    }

    // Remove the element from the front of the list and retrieve its value
    bool pop_front(T& value)
    {
        // Check if the list is not empty
        if (head != &(Node::NIL))
        {
            // Get the node to be deleted
            Node* toDelete = head;

            // Update head pointer
            head = head->getNext();

            // Retrieve the value, remove the node, and decrement the count
            value = toDelete->getValue();
            toDelete->remove();
            --count;

            // If the list becomes empty, update the last pointer
            if (head == &(Node::NIL))
                last = head;

            return true;
        }

        // Return false if the list is empty
        return false;
    }

    // Remove the element from the back of the list and retrieve its value
    bool pop_back(T& value)
    {
        // Check if the list is not empty
        if (last != &(Node::NIL))
        {
            // Get the node to be deleted
            Node* toDelete = last;

            // Update last pointer
            last = last->getPrevious();

            // Retrieve the value, remove the node, and decrement the count
            value = toDelete->getValue();
            toDelete->remove();
            --count;

            // If the list becomes empty, update the head pointer
            if (last == &(Node::NIL))
                head = last;

            return true;
        }

        // Return false if the list is empty
        return false;
    }

    // Access an element in the list by index (const version)
    const T& operator[](int index) const
    {
        // Check if the index is out of range
        if (index < 0 || index >= count)
            throw std::out_of_range("out of range");

        // Traverse the list to find the node at the specified index
        Node* node = head;
        while (node != &(Node::NIL) && index > 0)
        {
            node = node->getNext();
            index--;
        }

        // Return the value of the node at the specified index
        return node->getValue();
    }

    // Insert an element at a specified index
    void insert(const T& value, int index)
    {
        // Check if the index is out of range
        if (index < 0 || index > count)
            throw std::out_of_range("out of range");

        // Case: insert at the front
        if (index == 0)
        {
            push_front(value);
        }
        // Case: insert at the back
        else if (index == count)
        {
            push_back(value);
        }
        // Case: insert in the middle
        else
        {
            Node* newNode = new Node(value);

            // Traverse the list to find the node before the specified index
            Node* node = head;
            while (node != &(Node::NIL) && index > 1)
            {
                node = node->getNext();
                index--;
            }

            // Insert the new node after the found node
            if (node != &(Node::NIL))
            {
                node->append(newNode);
            }

            // If the list was initially empty, update head and last pointers
            if (head == &(Node::NIL))
                head = newNode;
            if (last == &(Node::NIL))
                last = newNode;

            // Increment the count
            ++count;
        }
    }

    // Remove an element at a specified index and retrieve its value
    bool remove(int index, T& value)
    {
        // Check if the index is out of range
        if (index < 0 || index >= count)
            throw std::out_of_range("out of range");

        // Case: remove from the front
        if (index == 0)
        {
            return pop_front(value);
        }
        // Case: remove from the back
        else if (index == count - 1)
        {
            return pop_back(value);
        }
        // Case: remove from the middle
        else
        {
            // Traverse the list to find the node at the specified index
            Node* toDelete = head;
            while (toDelete != &(Node::NIL) && index > 0)
            {
                toDelete = toDelete->getNext();
                index--;
            }

            // Remove the node, retrieve its value, and decrement the count
            if (toDelete != &(Node::NIL))
            {
                value = toDelete->getValue();
                toDelete->remove();
                --count;

                // If the list becomes empty, update head and last pointers
                if (count == 0)
                {
                    head = last = &(Node::NIL);
                }

                return true;
            }

            // Return false if the node at the specified index is not found
            return false;
        }
    }

    // Get an iterator pointing to the beginning of the list
    Iterator begin() const
    {
        return Iterator(head);
    }
};

