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
	ticketsTotal = total;
	ticketsSold = sold;
}

void Screening::sellTickets(int amount)
{
	if (amount > 0) // positive
	{
		if (ticketsSold + amount > ticketsTotal)
		{
			throw err_OutOfBounds;
		}
		else
		{
			ticketsSold += amount;
		}
	}
	else if (amount < 0) // negative
	{
		if (ticketsSold + amount < 0)
		{
			throw err_OutOfBounds;
		}
		else
		{
			ticketsSold += amount;
		}
	}
}

int Screening::ticketsAvailable()
{
	return ticketsTotal - ticketsSold;
}