#pragma once
#include "Queue.h"
#include "QueueOverflow.h"
#include "QueueUnderflow.h"
#include "WrongQueueSize.h"

template <typename T>
class QueueArray final : public Queue<T> 
{
public:
	QueueArray(size_t size = 100);   
	QueueArray(const QueueArray<T>& src) = delete;
	QueueArray(QueueArray<T>&& src);  
	QueueArray<T>& operator=(const QueueArray<T>& src) = delete;
	QueueArray<T>& operator=(QueueArray<T>&& src);
	~QueueArray() override;

	void enQueue(const T& e) override;
	T deQueue() override;
	bool isEmpty() const override;
	void print() const;

private:
	T* array_;
	size_t head_ = 0;
	size_t tail_ = 0;
	size_t size_;
	void swap(QueueArray<T>& src);
};

template<typename T>
QueueArray<T>::QueueArray(size_t size) : size_(size + 1), head_(0), tail_(0)
{
	if (size_ < 1)
	{
		throw WrongQueueSize<T>("stack size too small.");
	}
	try
	{
		array_ = new T[size_];
	}
	catch (...)
	{
		throw WrongQueueSize<T>("stack size too big.");
	}
}

template<typename T>
QueueArray<T>::QueueArray(QueueArray<T>&& src)
{
	this->swap(src);
}

template<typename T>
QueueArray<T>& QueueArray<T>::operator=(QueueArray<T>&& src)
{
	this->swap(src);
	delete[] src.array_;
	src.size_ = 0;
	src.head_ = 0;
	src.tail_ = 0;
	return this;
}

template<typename T>
QueueArray<T>::~QueueArray()
{
	delete[] array_;
}

template<typename T>
void QueueArray<T>::enQueue(const T& e)
{
	if (head_ == tail_ + 1 || (tail_ == size_ - 1  && head_ == 0))
	{
		throw QueueOverflow<T>("no space for new element.");
	}
	array_[tail_] = e;
	if (tail_ == size_ - 1)
	{
		tail_ = 0;
	}
	else
	{
		++tail_;
	}
}

template<typename T>
T QueueArray<T>::deQueue()
{
	if (isEmpty())
	{
		throw QueueUnderflow<T>("queue is empty.");
	}
	T out = array_[head_];
	if (head_ == size_ - 1)
	{
		head_ = 0;
	}
	else
	{
		head_++;
	}
	return out;
}

template<typename T>
bool QueueArray<T>::isEmpty() const
{
	return head_ == tail_;
}

template<typename T>
void QueueArray<T>::print() const
{
	int temp = head_;
	while (temp != tail_ || (temp == size_ - 1 && tail_ == 0))
	{
		std::cout << array_[temp] << " ";
		if (temp == size_ - 1)
		{
			temp = 0;
		}
		else
		{
			temp++;
		}
	}
}

template<typename T>
void QueueArray<T>::swap(QueueArray<T>& src)
{
	std::swap(array_, src.array_);
	std::swap(head_, src.head_);
	std::swap(tail_, src.tail_);
	std::swap(size_, src.size_);
}
