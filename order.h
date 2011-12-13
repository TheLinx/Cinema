#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <string>
#include <vector>

class Order {
private:
	int id;
	std::string name;
public:
	Order(std::string name);
	Order(std::string name, int id);
	int getId() const;
	void print(std::ostream &os) const;
	void print(std::ostream &os, bool pad) const;
	friend std::ostream &operator<<(std::ostream &os, const Order &o);
};

extern std::vector<Order> order;

void printAllOrders();
Order *getOrder(int id);

#endif