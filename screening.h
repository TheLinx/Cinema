#ifndef SCREENING_H
#define SCREENING_H
#include <iostream>
#include <vector>

class Screening {
private:
	int _location;
	int _ticketsTotal;
	int _ticketsSold;
public:
	Screening(int loc, int total, int sold);
	void sellTickets(int amount); // can be negative (returns)
	int getLocation();
	int ticketsTotal();
	int ticketsSold();
	int ticketsAvailable();
	void print(std::ostream &os) const;
	void print(std::ostream &os, bool pad) const;
	friend std::ostream &operator<<(std::ostream &os, const Screening &s);
};

void printAllScreenings(std::vector<Screening> *s);
Screening *getScreening(std::vector<Screening> *s, int location);

#endif