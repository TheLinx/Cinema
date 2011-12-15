#include <iomanip>
#include "screening.h"
#include "order.h"
#include "exceptions.h"

std::vector<Screening> screenings;

Screening::Screening(int loc, std::string name, int total, int sold)
{
	// check that the location isn't occupied, and throw a tantrum if it is
	try {
		getScreening(loc); // get a screening in this location
	}
	catch (std::exception &e) { // we had an error. this is actually good.
		goto skipthrow; // yeah, goto is ugly. however, I don't know another way to do this.
	}
	throw err_KeyOccupied; // this will be skipped by the goto if we had an error
	skipthrow: 
	_location = loc;
	_movieName = name;
	_ticketsTotal = total;
	_ticketsSold = sold;
	screenings.push_back(*this); // add ourselves to the list of screenings
}

void Screening::sellTickets(int amount)
{
	if (amount > 0) // positive
	{
		if (_ticketsSold + amount > _ticketsTotal) // if we actually can't sell that many tickets
		{
			throw err_OutOfBounds; // throw an exception
		}
		else // everything checks out
		{
			_ticketsSold += amount; // modify our private member
		}
	}
	else if (amount < 0) // negative
	{
		if (_ticketsSold + amount < 0) // again, if we can't return that many tickets
		{
			throw err_OutOfBounds; // throw an exception
		}
		else // everything checks out
		{
			_ticketsSold += amount; // modify our private member
		}
	}
}

// accessor functions -- comments not needed

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

// all the printing stuff
void Screening::print(std::ostream &os) const
{ // this is the function for printing to the save file
	os << _location << "\t" << _movieName << "\t" << _ticketsTotal << "\t" << _ticketsSold;
}
void Screening::print(std::ostream &os, bool padding) const
{ // this is the function for printing to the humans -- padding and pretty stuff
	if (!padding)
		return print(os);
	os << std::setw(9) << _location
	   << std::setw(20) << _movieName
	   << std::setw(15) << _ticketsTotal
	   << std::setw(14) << _ticketsSold;
}

std::ostream& operator<<(std::ostream &os, const Screening &s)
{ // cout << thing handler
	s.print(os);
	return os;
}

// remove Orders that link to this Screening
// we need to do this before we remove a Screening
void Screening::purgeOrders()
{
	for (unsigned i = 0; i < orders.size();) // we can't move to the next item if we've removed one, so we'll i++ manually
	{
		if (orders.at(i).getScreening() == this) // if the orders screening is this screening
			orders.erase(orders.begin() + i); // remove the order from the vector
		else // if not
			i++; // move on to the next order
	}
}

// print a pretty list of the screenings vector
void printAllScreenings()
{
	std::cout << "== Screenings: " << screenings.size() << std::endl;
	std::cout << std::setw(9) << "Location"
	          << std::setw(20) << "Movie name"
	          << std::setw(15) << "Total tickets" 
	          << std::setw(14) << "Sold tickets"
	<< std::endl;
	for (unsigned i = 0; i < screenings.size(); i++)
	{ // for evert screening in the screenings vector
		screenings.at(i).print(std::cout, true); // call the pretty print function
		std::cout << std::endl;
	}
}

// go through the screenings vector to find the screening in a specified location.
// also pass the vector id of it as a reference upstream
Screening *getScreening(int location, int *id)
{
	int found = -1; // vector can't have an item here -- safe for instances where there is no screening at specified location
	for (unsigned i = 0; i < screenings.size(); i++)
	{ // loop through the screenings vector
		if (screenings.at(i).getLocation() == location) // stuff checks out!
		{
			found = i;
			break; // no need to continue the loop - let's quit out
		}
	}
	if (found == -1) // if the found variable hasn't changed
	{
		throw err_NoSuchValue; // it's exception o'clock
	}
	*id = found; // pass id of screening upstream
	return &screenings.at(found); // and return a reference
}

// if we don't actually need the vector id
Screening *getScreening(int location)
{
	int asd; // there's probably a way to do this without even creating a temp variable, but this is probably
	return getScreening(location, &asd); // optimized out by the compiler anyway
}