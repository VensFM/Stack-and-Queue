#pragma once

#include <exception>
#include <string>

class WrongStackSize : public std::exception
{
public:
	WrongStackSize(const std::string& message)
	{
		message_ = " WrongStackSize: " + message + "\n";
	}
	const char* content() const noexcept
	{
		return message_.c_str();
	}
private:
	std::string message_;
};