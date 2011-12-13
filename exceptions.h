#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>

class OutOfBoundsException: public std::exception {
	virtual const char* what() const throw()
	{
		return "Value out of bounds.";
	}
};
class ValueNotFoundException: public std::exception {
	virtual const char* what() const throw()
	{
		return "No such value.";
	}
};

extern OutOfBoundsException err_OutOfBounds;
extern ValueNotFoundException err_NoSuchValue;

#endif