#include <iomanip>
#include "screening.h"
#include "order.h"
#include "exceptions.h"

std::vector<Screening> screenings;

Screening::Screening(unsigned location, std::string movieName, unsigned ticketsTotal, unsigned ticketsSold)
{
	// check that the location isn't occupied, and throw a tantrum if it is
	try {
		getScreening(location); // get a screening in this location
	}
	catch (std::exception &e) { // we had an error. this is actually good.
		goto skipthrow; // yeah, goto is ugly. however, I don't know another way to do this.
	}
	throw KeyOccupiedException(); // this will be skipped by the goto if we had an error
	skipthrow: 
	loc = location;
	movn = movieName;
	tickt = ticketsTotal;
	ticks = ticketsSold;
	screenings.push_back(*this); // add ourselves to the list of screenings
}

void Screening::sellTickets(int amount)
{
	if (amount > 0) // positive
	{
		if (ticks + amount > tickt) // if we actually can't sell that many tickets
		{
			throw OutOfBoundsException(); // throw an exception
		}
		else // everything checks out
		{
			ticks += amount; // modify our private member
		}
	}
	else if (amount < 0) // negative
	{
		if (ticks + amount < 0) // again, if we can't return that many tickets
		{
			throw OutOfBoundsException(); // throw an exception
		}
		else // everything checks out
		{
			ticks += amount; // modify our private member
		}
	}
}

// accessor functions -- comments not needed

unsigned Screening::location() const
{
	return loc;
}

unsigned Screening::ticketsAvailable() const
{
	return tickt - ticks;
}

unsigned Screening::ticketsSold() const
{
	return ticks;
}

unsigned Screening::ticketsTotal() const
{
	return tickt;
}

std::string Screening::movieName() const
{
	return movn;
}

// all the printing stuff
void Screening::print(std::ostream &os) const
{ // this is the function for printing to the save file
	os << loc << "\t" << movn << "\t" << tickt << "\t" << ticks;
}
void Screening::print(std::ostream &os, bool padding) const
{ // this is the function for printing to the humans -- padding and pretty stuff
	if (!padding)
		return print(os);
	os << std::setw(9) << loc
	   << std::setw(20) << movn
	   << std::setw(15) << tickt
	   << std::setw(14) << ticks;
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
		if (orders[i].getScreening() == this) // if the orders screening is this screening
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
		screenings[i].print(std::cout, true); // call the pretty print function
		std::cout << std::endl;
	}
}

// go through the screenings vector to find the screening in a specified location.
// also pass the vector id of it as a reference upstream
Screening *getScreening(unsigned location, unsigned *id)
{
	int found = -1; // vector can't have an item here -- safe for instances where there is no screening at specified location
	for (unsigned i = 0; i < screenings.size(); i++)
	{ // loop through the screenings vector
		if (screenings[i].location() == location) // stuff checks out!
		{
			found = i;
			break; // no need to continue the loop - let's quit out
		}
	}
	if (found == -1) // if the found variable hasn't changed
	{
		throw ValueNotFoundException(); // it's exception o'clock
	}
	if (id) *id = found; // pass id of screening upstream
	return &screenings[found]; // and return a reference
}