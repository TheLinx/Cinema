#include <iostream>
#include "io.h"
#include "screening.h"
using namespace std; // only in this file... so it's okay, right?

int main()
{
	vector<Screening> screenings;
	loadScreenings(&screenings);

	cout << "Amount of screenings: " << screenings.size() << endl;

	for (int i = 0; i < screenings.size(); i++)
	{
		cout << screenings[i].ticketsAvailable() << endl;
	}

	saveScreenings(&screenings);
	return 0;
}