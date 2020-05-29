#pragma once
// #include <exception>
#include "StackException.h"
template <typename T>
class Stack
{
private:
	static const int defaultSize = 10;
	static const int maxSize = 1000;
	int _size;
	int _top;
	T* stackPtr;
public:
	explicit Stack(int s = defaultSize);
	~Stack() {
		delete[] stackPtr;
	}
	T& push(const T&);
	T& pop();
	bool isEmpty() const { return _top < 0; }
	bool isFull() const { return _top >= _size - 1; }
	T& top() const { return stackPtr[_top]; }
	int size() const { return _size; }
};

template<typename T>
inline Stack<T>::Stack(int s)
{
	if (s > maxSize || s < 1)
		throw out_of_range("Stack size out of range");
	else
	{
		_size = s;
		_top = -1;
		stackPtr = new T[_size];
	}

}

template<typename T>
inline T& Stack<T>::push(const T& item)
{
	if (isFull())
		throw StackException("Stack is full");
	else {
		return stackPtr[++_top] = item;
	}
}

template<typename T>
inline T& Stack<T>::pop()
{
	if (isEmpty())
		throw StackException("Stack is empty");
	else
		return stackPtr[_top--];
}


