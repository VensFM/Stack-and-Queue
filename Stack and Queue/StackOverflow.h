#pragma once

#include <exception>
#include <string>

class StackOverflow : public std::exception
{
public:
	StackOverflow(const std::string& message)
	{
		message_ = " StackOverflow: " + message + "\n";
	}
	const char* content() const noexcept
	{
		return message_.c_str();
	}
private:
	std::string message_;
};