#pragma once

#include <exception>
#include <string>

class QueueOverflow : public std::exception
{
public:
	QueueOverflow(const std::string& message)
	{
		message_ = " QueueOverflow: " + message + "\n";
	}
	const char* content() const noexcept
	{
		return message_.c_str();
	}
private:
	std::string message_;
};