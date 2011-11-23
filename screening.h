#ifndef SCREENING_H
#define SCREENING_H

class Screening {
private:
	int location;
	int ticketsTotal;
	int ticketsSold;
public:
	Screening(int loc, int total, int sold);
	void sellTickets(int amount); // can be negative (returns)
	int ticketsAvailable();
};

#endif