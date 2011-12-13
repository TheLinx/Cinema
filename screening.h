#ifndef SCREENING_H
#define SCREENING_H
#include <iostream>
#include <string>
#include <vector>

class Screening {
private:
	int _location;
	int _ticketsTotal;
	int _ticketsSold;
	std::string _movieName;
public:
	Screening(int loc, std::string name, int total, int sold);
	void sellTickets(int amount); // can be negative (returns)
	int getLocation() const;
	int ticketsTotal() const;
	int ticketsSold() const;
	int ticketsAvailable() const;
	std::string movieName() const;
	void print(std::ostream &os) const;
	void print(std::ostream &os, bool pad) const;
	friend std::ostream &operator<<(std::ostream &os, const Screening &s);
};

extern std::vector<Screening> screenings;

void printAllScreenings();
Screening *getScreening(int location);
Screening *getScreening(int location, int *id);

#endif