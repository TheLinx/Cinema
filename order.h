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
	int id;
	std::string name;
	Screening *screening;
	int screening_id;
	int tickets;
public:
	// constructors
	Order(std::string name, int screening_id, int tickets);
	Order(std::string name, int screening_id, int tickets, int id);
	// accessor function
	int getId() const;
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
Order *getOrder(int id);
Order *getOrder(int id, int *vector_id);

#endif