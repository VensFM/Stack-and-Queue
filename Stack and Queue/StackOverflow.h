#pragma once

#include <string>
#include "Stack.h"

template <class T>
class StackOverflow final : public Stack<T>::StackException
{
public:
	StackOverflow(const std::string& message) : Stack<T>::StackException(" StackOverflow: " + message + "\n") {}
};