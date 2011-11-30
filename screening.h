#include <iostream>

#ifndef SCREENING_H
#define SCREENING_H

class Screening {
private:
	int _location;
	int _ticketsTotal;
	int _ticketsSold;
public:
	Screening(int loc, int total, int sold);
	void sellTickets(int amount); // can be negative (returns)
	int getLocation() const;
	int ticketsTotal() const;
	int ticketsSold() const;
	int ticketsAvailable() const;
	void print(std::ostream &os) const;
	friend std::ostream &operator<<(std::ostream &os, const Screening &s);
};

#endif