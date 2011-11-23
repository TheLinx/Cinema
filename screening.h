#ifndef SCREENING_H
#define SCREENING_H

class Screening {
private:
	int location;
	int _ticketsTotal;
	int _ticketsSold;
public:
	Screening(int loc, int total, int sold);
	void sellTickets(int amount); // can be negative (returns)
	int getLocation();
	int ticketsTotal();
	int ticketsSold();
	int ticketsAvailable();
};

#endif