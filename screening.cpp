#include <exception>
#include <iomanip>
#include "screening.h"

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
			std::cout << amount << ", " << _ticketsSold << std::endl;
			_ticketsSold += amount;
			std::cout << amount << ", " << _ticketsSold << std::endl;
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
	return _location;
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

void Screening::print(std::ostream &os) const
{
	os << _location << "\t" << _ticketsTotal << "\t" << _ticketsSold;
}
void Screening::print(std::ostream &os, bool padding) const
{
	if (!padding)
		return print(os);
	os << std::setw(9) << _location
	   << std::setw(15) << _ticketsTotal
	   << std::setw(14) << _ticketsSold;
}

std::ostream& operator<<(std::ostream &os, const Screening &s)
{
	s.print(os);
	return os;
}

void printAllScreenings(std::vector<Screening> *s)
{
	std::cout << "== Screenings: " << s->size() << std::endl;
	std::cout << std::setw(9) << "Location"
	          << std::setw(15) << "Total tickets" 
	          << std::setw(14) << "Sold tickets"
	<< std::endl;
	for (int i = 0; i < s->size(); i++)
	{
		s->at(i).print(std::cout, true);
		std::cout << std::endl;
	}
}

Screening *getScreening(std::vector<Screening> *s, int location)
{
	int found = -1;
	for (int i = 0; i < s->size(); i++)
	{
		if (s->at(i).getLocation() == location)
		{
			found = i;
			break;
		}
	}
	if (found == -1)
	{
		throw err_NoSuchValue;
	}
	return &s->at(found);
}