#include <iostream>
#include "screening.h"
using namespace std; // only in this file... so it's okay, right?

int main()
{
	Screening *s;
	s = new Screening(1, 10, 2);

	try {
		s->sellTickets(9);
	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
	}

	cout << "Tickets: " << s->ticketsAvailable() << endl;

	return 0;
}