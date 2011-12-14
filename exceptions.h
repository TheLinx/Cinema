#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <exception>

/*** Exceptions ***
 * These are the exceptions we use in the Screening and Order classes.
 * We need to use extern for the instances, or we get multiple definition errors.
 */

class OutOfBoundsException: public std::exception { // err_OutOfBounds
	virtual const char* what() const throw()
	{
		return "Value out of bounds.";
	}
};
class ValueNotFoundException: public std::exception { // err_NoSuchValue
	virtual const char* what() const throw()
	{
		return "No such value.";
	}
};
class KeyOccupiedException: public std::exception { // err_KeyOccupied
	virtual const char* what() const throw()
	{
		return "Primary key value occupied.";
	}
};

extern OutOfBoundsException err_OutOfBounds;
extern ValueNotFoundException err_NoSuchValue;
extern KeyOccupiedException err_KeyOccupied;

#endif