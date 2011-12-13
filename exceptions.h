#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>

class OutOfBoundsException: public std::exception {
	virtual const char* what() const throw()
	{
		return "Value out of bounds.";
	}
} err_OutOfBounds;
class ValueNotFoundException: public std::exception {
	virtual const char* what() const throw()
	{
		return "No such value.";
	}
} err_NoSuchValue;

#endif