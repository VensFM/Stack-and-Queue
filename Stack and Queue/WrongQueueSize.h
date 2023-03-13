#pragma once

#include <exception>
#include <string>

class WrongQueueSize : public std::exception
{
public:
	WrongQueueSize(const std::string& message)
	{
		message_ = " WrongQueueSize: " + message + "\n";
	}
	const char* content() const noexcept
	{
		return message_.c_str();
	}
private:
	std::string message_;
};