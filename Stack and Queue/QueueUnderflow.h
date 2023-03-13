#pragma once

#include <exception>
#include <string>

class QueueUnderflow : public std::exception
{
public:
	QueueUnderflow(const std::string& message)
	{
		message_ = " QueueUnderflow: " + message + "\n";
	}
	const char* content() const noexcept
	{
		return message_.c_str();
	}
private:
	std::string message_;
};