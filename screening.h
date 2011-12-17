#ifndef SCREENING_H
#define SCREENING_H
#include <iostream>
#include <string>
#include <vector>

/*** Screening class ***
 * This is one screening of a movie. It has a location, ticket amounts and name of movie.
 * Two screenings may not be in the same location.
 * You can modify the amount of sold tickets by using the sellTickets function - this is foolproofed with exceptions.
 * All screenings are stored (automatically) in the externed screenings vector.
 */

class Screening {
private:
	// our data
	unsigned loc;     // Location
	unsigned tickt;   // Total tickets
	unsigned ticks;   // Sold tickets
	std::string movn; // Movie name
public:
	// constructor
	Screening(unsigned location, std::string movieName, unsigned ticketsTotal, unsigned ticketsSold);
	// accessor functions
	unsigned location() const;
	unsigned ticketsTotal() const;
	unsigned ticketsSold() const;
	unsigned ticketsAvailable() const;
	std::string movieName() const;
	// modifier functions
	void sellTickets(int amount); // can be negative (for returns/refunds)
	// action functions
	void print(std::ostream &os) const;
	void print(std::ostream &os, bool pad) const;
	friend std::ostream &operator<<(std::ostream &os, const Screening &s);
	void purgeOrders();
};

// needs to be extern or it will be called a multiple definition
extern std::vector<Screening> screenings;

// non-class functions, but still related to screenings
void printAllScreenings();
Screening *getScreening(unsigned location, unsigned *id = NULL);

#endif