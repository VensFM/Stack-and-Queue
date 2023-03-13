#pragma once

#include <string>

class WrongQueueSize 
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