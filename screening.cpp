#include <iomanip>
#include "screening.h"
#include "exceptions.h"

std::vector<Screening> screenings;

Screening::Screening(int loc, std::string name, int total, int sold)
{
	_location = loc;
	_movieName = name;
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

std::string Screening::movieName() const
{
	return _movieName;
}

void Screening::print(std::ostream &os) const
{
	os << _location << "\t" << _movieName << "\t" << _ticketsTotal << "\t" << _ticketsSold;
}
void Screening::print(std::ostream &os, bool padding) const
{
	if (!padding)
		return print(os);
	os << std::setw(9) << _location
	   << std::setw(20) << _movieName
	   << std::setw(15) << _ticketsTotal
	   << std::setw(14) << _ticketsSold;
}

std::ostream& operator<<(std::ostream &os, const Screening &s)
{
	s.print(os);
	return os;
}

void printAllScreenings()
{
	std::cout << "== Screenings: " << screenings.size() << std::endl;
	std::cout << std::setw(9) << "Location"
	          << std::setw(20) << "Movie name"
	          << std::setw(15) << "Total tickets" 
	          << std::setw(14) << "Sold tickets"
	<< std::endl;
	for (int i = 0; i < screenings.size(); i++)
	{
		screenings.at(i).print(std::cout, true);
		std::cout << std::endl;
	}
}

Screening *getScreening(int location)
{
	int asd;
	return getScreening(location, &asd);
}

Screening *getScreening(int location, int *id)
{
	int found = -1;
	for (int i = 0; i < screenings.size(); i++)
	{
		if (screenings.at(i).getLocation() == location)
		{
			found = i;
			break;
		}
	}
	if (found == -1)
	{
		throw err_NoSuchValue;
	}
	*id = found;
	return &screenings.at(found);
}