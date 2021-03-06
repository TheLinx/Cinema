#include <cstdlib>
#include <iomanip>
#include "order.h"
#include "exceptions.h"

std::vector<Order> orders;

Order::Order(std::string name_in, unsigned screening_id_in, unsigned tickets_in)
{
	name = name_in;
	while (true)
	{
		id = rand(); // a random id. this will be a big number on Linux. not a problem, just annoying.
		try {
			getOrder(id); // is there an order with this id?
		}
		catch (std::exception &e) { // nope!
			break; // so, quit this loop.
		}
	}
	screening_id = screening_id_in;
	screening = &screenings.at(screening_id); // get the Screening reference directly from the vector
	tickets = tickets_in;
	screening->sellTickets(tickets); // reserve the tickets
	orders.push_back(*this);
}
Order::Order(std::string name_in, unsigned screening_id_in, unsigned tickets_in, unsigned id_in) // if we already have an id (loading)
{
	name = name_in;
	screening_id = screening_id_in;
	screening = &screenings.at(screening_id);
	tickets = tickets_in;
	id = id_in;
	// there's no exception here because unless the saved data is wrong (and it shouldn't be unless the user is stupid)
	// then ID won't be occupied.
	orders.push_back(*this);
}

unsigned Order::getId() const
{
	return id;
}

Screening *Order::getScreening() const
{
	return screening;
}

void Order::returnTickets()
{
	screening->sellTickets(-(int)tickets); // nothing weird here
}

// the rest is pretty much identical to screening.cpp, look in that for comments.
void Order::print(std::ostream &os) const
{
	os << id << "\t" << name << "\t" << screening_id << "\t" << tickets << "\t";
}
void Order::print(std::ostream &os, bool padding) const
{
	if (!padding)
		return print(os);
	os << std::setw(10) << id
	   << std::setw(15) << name
	   << std::setw(20) << screening->movieName()
	   << std::setw(9) << tickets;
}

std::ostream& operator<<(std::ostream &os, const Order &o)
{
	o.print(os);
	return os;
}

void printAllOrders()
{
	std::cout << "== Orders: " << orders.size() << std::endl;
	std::cout << std::setw(10) << "ID"
	          << std::setw(15) << "Orderer name"
	          << std::setw(20) << "Screening of"
	          << std::setw(9) << "Tickets"
	<< std::endl;
	for (unsigned i = 0; i < orders.size(); i++)
	{
		orders[i].print(std::cout, true);
		std::cout << std::endl;
	}
}

Order *getOrder(unsigned id, unsigned *vector_id)
{
	int found = -1;
	for (unsigned i = 0; i < orders.size(); i++)
	{
		if (orders[i].getId() == id)
		{
			found = i;
			break;
		}
	}
	if (found == -1)
	{
		throw ValueNotFoundException();
	}
	if (vector_id) *vector_id = found;
	return &orders[found];
}