#pragma once
#include "SinglyLinkedNode.h"
#include "SinglyLinkedNodeIterator.h"
#include "List.h"

template<class T>
class SinglyLinkedList : public List<T>
{
private:
    typedef SinglyLinkedNode<T> Node;

    Node* head;  // Pointer to the first node in the linked list
    int count;   // Count of elements in the linked list

public:
    typedef SinglyLinkedNodeIterator<T> Iterator;

    // Default Constructor
    SinglyLinkedList() : head(&(Node::NIL)), count(0) {}

    // Constructor with a given first node
    SinglyLinkedList(Node* firstNode) : head(firstNode), count(1) {}

    // Destructor
    ~SinglyLinkedList()
    {
        Iterator it = begin();
        while (it != it.end())
        {
            Node* toDelete = it.getCurrent();
            ++it;
            delete toDelete; // Delete each node in the list
        }
    }

    // Check if the linked list is empty
    bool isEmpty() const
    {
        return count == 0;
    }

    // Get the size of the linked list
    int size() const
    {
        return count;
    }

    // Add an element to the front of the linked list
    void push_front(const T& value)
    {
        Node* newNode = new Node(value);
        if (head != &(Node::NIL))
        {
            newNode->setNext(head);
        }
        head = newNode;
        ++count;
    }

    // Add an element to the back of the linked list
    void push_back(const T& value)
    {
        if (count == 0)
        {
            push_front(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* node = head;
        while (node->getNext() != &(Node::NIL))
        {
            node = node->getNext();
        }

        node->setNext(newNode);
        ++count;
    }

    // Remove and retrieve the element from the front of the linked list
    bool pop_front(T& value)
    {
        if (head != &(Node::NIL))
        {
            Node* toDelete = head;
            head = head->getNext();
            value = toDelete->getValue();
            delete toDelete;
            --count;
            return true;
        }
        return false;
    }

    // Remove and retrieve the element from the back of the linked list
    bool pop_back(T& value)
    {
        if (count == 1)
            return pop_front(value);

        if (head != &(Node::NIL))
        {
            Node* parent = head;
            Node* toDelete = head;
            while (toDelete != &(Node::NIL) && toDelete->getNext() != &(Node::NIL))
            {
                parent = toDelete;
                toDelete = toDelete->getNext();
            }

            parent->setNext(&(Node::NIL));
            value = toDelete->getValue();
            delete toDelete;
            --count;
            return true;
        }
        return false;
    }

    // Access an element in the linked list by index
    const T& operator[](int index) const
    {
        if (index < 0 || index >= count)
            throw std::out_of_range("out of range");

        Node* node = head;
        while (node != &(Node::NIL) && index > 0)
        {
            node = node->getNext();
            index--;
        }

        return node->getValue();
    }

    // Insert an element at a specific index in the linked list
    void insert(const T& value, int index)
    {
        if (index < 0 || index > count)
            throw std::out_of_range("out of range");

        if (index == 0)
        {
            push_front(value);
        }
        else if (index == count)
        {
            push_back(value);
        }
        else
        {
            Node* newNode = new Node(value);

            Node* node = head;
            while (node != &(Node::NIL) && index > 1)
            {
                node = node->getNext();
                index--;
            }

            if (node != &(Node::NIL))
            {
                newNode->setNext(node->getNext());
                node->setNext(newNode);
            }
            if (head == &(Node::NIL))
                head = newNode;
            ++count;
        }
    }

    // Remove an element at a specific index and retrieve its value
    bool remove(int index, T& value)
    {
        if (index < 0 || index >= count)
            throw std::out_of_range("out of range");

        if (index == 0)
        {
            return pop_front(value);
        }
        else if (index == count - 1)
        {
            return pop_back(value);
        }
        else
        {
            Node* parent = head;
            Node* toDelete = head;
            while (toDelete != &(Node::NIL) && index > 0)
            {
                parent = toDelete;
                toDelete = toDelete->getNext();
                index--;
            }

            if (toDelete != &(Node::NIL))
            {
                value = toDelete->getValue();
                parent->setNext(toDelete->getNext());
                delete toDelete;
                --count;

                if (count == 0)
                {
                    head = &(Node::NIL);
                }
                return true;
            }
            return false;
        }
    }

    // Get an iterator pointing to the beginning of the linked list
    Iterator begin() const
    {
        return Iterator(head);
    }
};
