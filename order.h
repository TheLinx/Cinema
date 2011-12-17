#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <string>
#include <vector>
#include "screening.h"

/*** Order class ***
 * This is one order by a customer. It has a randomly generated ID for the customer's use,
 * the name of the customer, a reference to a Screening, its vector position,
 * and the amount of tickets booked.
 * There are two constructors, one for first time definition which generates an ID,
 * and one for loading where you specify the ID yourself.
 */

class Order {
private:
	// our data
	unsigned id;
	std::string name;
	Screening *screening;
	unsigned screening_id;
	unsigned tickets;
public:
	// constructors
	Order(std::string name, unsigned screening_id, unsigned tickets);
	Order(std::string name, unsigned screening_id, unsigned tickets, unsigned id);
	// accessor function
	unsigned getId() const;
	Screening *getScreening() const;
	// action functions
	void returnTickets();
	void print(std::ostream &os) const;
	void print(std::ostream &os, bool pad) const;
	friend std::ostream &operator<<(std::ostream &os, const Order &o);
};

// needs to be extern or it will be called a multiple definition
extern std::vector<Order> orders;

// non-class functions, but still related to orders
void printAllOrders();
Order *getOrder(unsigned id, unsigned *vector_id = NULL);

#endif