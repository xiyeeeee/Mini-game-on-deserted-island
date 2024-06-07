#pragma once
template<class T>
class DynamicArray
{
private:
    T* fElements; // Pointer to the array of elements
    int fCapacity; // Capacity of the array (maximum number of elements it can hold)
    int fSize;     // Current size of the array (number of elements currently in the array)

public:
    // Overloaded Constructor: Used to initialize a new DynamicArray with a specified capacity
    DynamicArray(int Capacity) : fCapacity(Capacity)
    {
        fElements = new T[fCapacity]; // Allocate memory for the array
        fSize = 0; // Initialize size to zero since the array is initially empty
    }

    // Destructor: Used to release the dynamically allocated memory when the object is destroyed
    ~DynamicArray()
    {
        delete[] fElements; // Deallocate the memory used by the array
    }

    // Get the current size of the array
    int size() const
    {
        return fSize;
    }

    // Add an item to the end of the array
    void add(const T& aItem)
    {
        if (fSize < fCapacity)
        {
            fElements[fSize] = aItem; // Add the item at the end of the array
            fSize++; // Increment the size of the array
        }
    }

    // Remove an item at a specified index from the array
    bool remove(int index)
    {
        if (index < 0 || index >= fSize)
            return false; // Index out of range

        // Shift elements to fill the gap created by removing the item
        for (int i = index; i < fSize - 1; i++)
            fElements[i] = fElements[i + 1];

        fSize--; // Decrease the size of the array
        return true; // Item successfully removed
    }

    // Access an element at a specified index (read-only)
    const T& operator[](int index) const
    {
        if (index < 0 || index >= fSize)
            throw std::out_of_range("out of range"); // Throw an exception for out-of-range access

        return fElements[index]; // Return the value at the specified index
    }

    // Clear all elements in the array by resetting the size to zero
    void delAll()
    {
        fSize = 0;
    }
};
