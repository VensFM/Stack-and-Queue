#include <iostream>
#include <string>
#include "Stack.h"
#include "StackArray.h"

int main()
{
	try
	{
		StackArray<long> stack;
	}
	catch (Stack<long>::StackException& error)
	{
		std::cerr << error.getMessage();
	}
	return 0;
}