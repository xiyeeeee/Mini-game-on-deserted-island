#pragma once
template<class T>
//Interface containing pure virtual methods
class List
{
	//template design pattern
public:
	List() {}
	virtual ~List() {}
	virtual bool isEmpty() const = 0;
	virtual int size() const = 0;
	virtual void push_front(const T& value) = 0;
	virtual void push_back(const T& value) = 0;
	virtual bool pop_front(T& value) = 0;
	virtual bool pop_back(T& value) = 0;
	virtual const T& operator[](int index) const = 0;
	virtual void insert(const T& value, int index) = 0;
	virtual bool remove(int index, T& value) = 0;
};

