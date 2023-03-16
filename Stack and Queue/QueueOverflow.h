#pragma once

#include <string>
#include "Queue.h"

template <class T>
class QueueOverflow final : public Queue<T>::QueueException
{
public:
	QueueOverflow(const std::string& message) : Queue<T>::QueueException(" QueueOverflow: " + message + "\n") {}
};