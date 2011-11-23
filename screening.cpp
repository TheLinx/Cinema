#include <exception>
#include "screening.h"

class OutOfBoundsException: public std::exception {
	virtual const char* what() const throw()
	{
		return "Value out of bounds.";
	}
} err_OutOfBounds;

Screening::Screening(int loc, int total, int sold)
{
	location = loc;
	_ticketsTotal = total;
	_ticketsSold = sold;
}

void Screening::sellTickets(int amount)
{
	if (amount > 0) // positive
	{
		if (_ticketsSold + amount > _ticketsTotal)
		{
			throw err_OutOfBounds;
		}
		else
		{
			_ticketsSold += amount;
		}
	}
	else if (amount < 0) // negative
	{
		if (_ticketsSold + amount < 0)
		{
			throw err_OutOfBounds;
		}
		else
		{
			_ticketsSold += amount;
		}
	}
}

int Screening::getLocation()
{
	return location;
}

int Screening::ticketsAvailable()
{
	return _ticketsTotal - _ticketsSold;
}

int Screening::ticketsSold()
{
	return _ticketsSold;
}

int Screening::ticketsTotal()
{
	return _ticketsTotal;
}