#include <cstdlib>
#include <iomanip>
#include "order.h"
#include "exceptions.h"

std::vector<Order> orders;

Order::Order(std::string name_in, int screening_id_in, int tickets_in)
{
	name = name_in;
	while (true)
	{
		id = rand();
		try {
			getOrder(id); // is there an order with this id?
		}
		catch (std::exception &e) { // nope!
			break; // so, quit this loop.
		}
	}
	screening_id = screening_id_in;
	screening = getScreening(screening_id);
	tickets = tickets_in;
}
Order::Order(std::string name_in, int screening_id_in, int tickets_in, int id_in) // if we already have an id (loading)
{
	name = name_in;
	screening_id = screening_id_in;
	screening = getScreening(screening_id);
	tickets = tickets_in;
	id = id_in;
}

int Order::getId() const
{
	return id;
}

void Order::print(std::ostream &os) const
{
	os << id << "\t" << name << "\t" << screening_id << "\t" << tickets;
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
		orders.at(i).print(std::cout, true);
		std::cout << std::endl;
	}
}

Order *getOrder(int id)
{
	int asd;
	return getOrder(id, &asd);
}

Order *getOrder(int id, int *vector_id)
{
	int found = -1;
	for (unsigned i = 0; i < orders.size(); i++)
	{
		if (orders.at(i).getId() == id)
		{
			found = i;
			break;
		}
	}
	if (found == -1)
	{
		throw err_NoSuchValue;
	}
	*vector_id = found;
	return &orders.at(found);
}