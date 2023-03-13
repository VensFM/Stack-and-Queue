#pragma once

#include <exception>
#include <string>

class StackUnderflow : public std::exception
{
public:
	StackUnderflow(const std::string& message)
	{
		message_ = " StackUnderflow: " + message + "\n";
	}
	const char* content() const noexcept
	{
		return message_.c_str();
	}
private:
	std::string message_;
};