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
	int _location;
	int _ticketsTotal;
	int _ticketsSold;
	std::string _movieName;
public:
	// constructor
	Screening(int loc, std::string name, int total, int sold);
	// accessor functions
	int getLocation() const;
	int ticketsTotal() const;
	int ticketsSold() const;
	int ticketsAvailable() const;
	std::string movieName() const;
	// modifier functions
	void sellTickets(int amount); // can be negative (returns)
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
Screening *getScreening(int location);
Screening *getScreening(int location, int *id);

#endif