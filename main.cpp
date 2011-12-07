#include <iostream>
#include "io.h"
#include "screening.h"
using namespace std; // only in this file... so it's okay, right?

int main()
{
	char cmd;
	bool run = true;
	vector<Screening> screenings;
	loadScreenings(&screenings);

	while(run)
	{
		printAllScreenings(&screenings);
		cout << "== What do you want to do?" << endl;
		cout << " a) Buy a ticket" << endl;
		cout << " q) Quit" << endl;
		cout << "> ";
		cin >> cmd;
		switch(cmd)
		{
		case 'a':
			int loc, amount;
			cout << "== Which screening? (Location?)" << endl << "> ";
			cin >> loc;
			cout << "== How many tickets?" << endl << "> ";
			cin >> amount;
			try {
				Screening *target = getScreening(&screenings, loc);
				cout << "== Reserving " << amount << " tickets for screening " << target << "." << endl;
				target->sellTickets(amount);
			}
			catch (exception &e) {
				cout << "Error: " << e.what() << endl;
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