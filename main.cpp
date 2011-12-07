#include <iostream>
#include "io.h"
#include "screening.h"
using namespace std; // only in this file... so it's okay, right?

int main()
{
	char cmd;
	bool run = true;
	int loc, amount;
	vector<Screening> screenings;
	loadScreenings(&screenings);

	while(run)
	{
		printAllScreenings(&screenings);
		cout << "== What do you want to do?" << endl;
		cout << " a) Buy tickets" << endl;
		cout << " b) Return tickets" << endl;
		cout << " q) Quit" << endl;
		cout << "> ";
		cin >> cmd;
		switch(cmd)
		{
		case 'a':
			cout << "== Which screening? (Location?)" << endl << "> ";
			cin >> loc;
			cout << "== How many tickets?" << endl << "> ";
			cin >> amount;
			try {
				Screening *target = getScreening(&screenings, loc);
				cout << "== Reserving " << amount << " tickets for screening " << target->getLocation() << "." << endl;
				target->sellTickets(amount);
			}
			catch (exception &e) {
				cout << "Error: " << e.what() <<
				endl << "No change has been made." << endl;
			}
			break;
		case 'b':
			cout << "== Which screening? (Location?)" << endl << "> ";
			cin >> loc;
			cout << "== How many tickets?" << endl << "> ";
			cin >> amount;
			try {
				Screening *target = getScreening(&screenings, loc);
				cout << "== Returning " << amount << " tickets for screening " << target->getLocation() << "." << endl;
				target->sellTickets(-amount);
			}
			catch (exception &e) {
				cout << "Error: " << e.what() <<
				endl << "No change has been made." << endl;
			}
			break;
		case 'q':
			run = false;
			break;
		}
	}

	saveScreenings(&screenings);
	return 0;
}