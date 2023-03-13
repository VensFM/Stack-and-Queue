#pragma once
#include "Stack.h"
#include "StackOverflow.h"
#include "StackUnderflow.h"
#include "WrongStackSize.h"

template <class T>
class StackArray final : public Stack<T>
{
public:
	StackArray(size_t size = 100); 
	StackArray(const StackArray<T>& src) = delete;
	StackArray(StackArray<T>&& src);
	StackArray& operator=(const StackArray<T>& src) = delete;
	StackArray& operator=(StackArray<T>&& src);
	~StackArray()override; 

	void push(const T& e)override;
	T pop()override;
	const T& top()override;
	bool isEmpty()override;
private:
	T* array_; 
	size_t top_; 
	size_t size_; 
	void swap(StackArray<T>& src);
};



template<class T>
StackArray<T>::StackArray(size_t size) : size_(size), top_(0)
{
	if (size_ < 1)
	{
		throw WrongStackSize<T>("stack size too small.");
	}
	try
	{
		array_ = new T[size_ + 1];
	}
	catch (...) 
	{
		throw WrongStackSize<T>("stack size too big.");
	}
}

template<class T>
StackArray<T>::StackArray(StackArray<T>&& src)
{
	this->swap(src);
}

template<class T>
StackArray<T>& StackArray<T>::operator=(StackArray<T>&& src)
{
	this->swap(src);
	delete[] src.array_;
	src.size_ = 0;
	src.top_ = 0;
	return this;
}

template<class T>
inline StackArray<T>::~StackArray()
{
	delete[] array_;
}

template<class T>
void StackArray<T>::push(const T& e)
{
	if (top_ == size_) 
	{
		throw StackOverflow<T>("no space for new element.");
	}
	array_[++top_] = e;
}

template<class T>
T StackArray<T>::pop()
{
	if (isEmpty()) 
	{ 
		throw StackUnderflow<T>("stack is empty.");
	}
	return array_[top_--];
}

template<class T>
const T& StackArray<T>::top()
{
	return array_[top_];
}

template<class T>
bool StackArray<T>::isEmpty()
{
	return top_ == 0;
}

template <class T>
void StackArray<T> ::swap(StackArray<T>& src)
{
	std::swap(array_, src.array_); 
	std::swap(top_, src.top_);
	std::swap(size_, src.size_);
}