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
	_location = loc;
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

int Screening::getLocation() const
{
	return _location;
}

int Screening::ticketsAvailable() const
{
	return _ticketsTotal - _ticketsSold;
}

int Screening::ticketsSold() const
{
	return _ticketsSold;
}

int Screening::ticketsTotal() const
{
	return _ticketsTotal;
}

void Screening::print(std::ostream &os) const
{
	os << _location << "\t" << _ticketsTotal << "\t" << _ticketsSold;
}

std::ostream& operator<<(std::ostream &os, const Screening &s)
{
	s.print(os);
	return os;
}

void printAllScreenings(std::vector<Screening> *s)
{
	std::cout << "Screenings: " << s->size() << std::endl;
	for (int i = 0; i < s->size(); i++)
	{
		std::cout << s->at(i) << std::endl;
	}
}