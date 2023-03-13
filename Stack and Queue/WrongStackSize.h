#pragma once

#include <string>
#include "Stack.h"

template <class T>
class WrongStackSize final : public Stack<T>::StackException
{
public:
	WrongStackSize(const std::string& message) : Stack<T>::StackException(" WrongStackSize: " + message + "\n") {}
};