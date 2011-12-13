#include <cstdlib>
#include <iomanip>
#include "order.h"
#include "exceptions.h"

std::vector<Order> orders;

Order::Order(std::string name_in)
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
}
Order::Order(std::string name_in, int id_in) // if we already have an id (loading)
{
	name = name_in;
	id = id_in;
}

int Order::getId() const
{
	return id;
}

void Order::print(std::ostream &os) const
{
	os << id << "\t" << name;
}
void Order::print(std::ostream &os, bool padding) const
{
	if (!padding)
		return print(os);
	os << std::setw(6) << id
	   << std::setw(15) << name;
}

std::ostream& operator<<(std::ostream &os, const Order &o)
{
	o.print(os);
	return os;
}

void printAllOrders()
{
	std::cout << "== Orders: " << orders.size() << std::endl;
	std::cout << std::setw(6) << "ID"
	          << std::setw(15) << "Orderer name"
	<< std::endl;
	for (int i = 0; i < orders.size(); i++)
	{
		orders.at(i).print(std::cout, true);
		std::cout << std::endl;
	}
}

Order *getOrder(int id)
{
	int found = -1;
	for (int i = 0; i < orders.size(); i++)
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
	return &orders.at(found);
}