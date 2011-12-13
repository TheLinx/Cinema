#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <string>
#include <vector>
#include "screening.h"

class Order {
private:
	int id;
	std::string name;
	Screening *screening;
	int screening_id;
	int tickets;
public:
	Order(std::string name, int screening_id, int tickets);
	Order(std::string name, int screening_id, int tickets, int id);
	int getId() const;
	void print(std::ostream &os) const;
	void print(std::ostream &os, bool pad) const;
	friend std::ostream &operator<<(std::ostream &os, const Order &o);
};

extern std::vector<Order> orders;

void printAllOrders();
Order *getOrder(int id);
Order *getOrder(int id, int *vector_id);

#endif