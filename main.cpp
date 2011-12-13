#include <iostream>
#include <ctime>
#include <cstdlib>
#include "io.h"
#include "screening.h"
using namespace std; // only in this file... so it's okay, right?

int main()
{
	char cmd;
	bool run = true;
	srand((unsigned)time(NULL));
	loadScreenings();

	while(run)
	{
		printAllScreenings();
		cout << "== What do you want to do?" << endl;
		cout << " a) Buy tickets" << endl;
		cout << " b) Return tickets" << endl;
		cout << " c) Add a screening" << endl;
		cout << " d) Remove a screening" << endl;
		cout << " q) Quit" << endl;
		cout << "> ";
		cin >> cmd;
		switch(cmd)
		{
		case 'a':
			{ int loc, amount;
			cout << "== Which screening? (Location?)" << endl << "> ";
			cin >> loc;
			cout << "== How many tickets?" << endl << "> ";
			cin >> amount;
			try {
				Screening *target = getScreening(loc);
				cout << "== Reserving " << amount << " tickets for screening of " << target->movieName() << "." << endl;
				target->sellTickets(amount);
			}
			catch (exception &e) {
				cout << "Error: " << e.what() <<
				endl << "No change has been made." << endl;
			}
			}
			break;
		case 'b':
			{ int loc, amount;
			cout << "== Which screening? (Location?)" << endl << "> ";
			cin >> loc;
			cout << "== How many tickets?" << endl << "> ";
			cin >> amount;
			try {
				Screening *target = getScreening(loc);
				cout << "== Returning " << amount << " tickets for screening of " << target->movieName() << "." << endl;
				target->sellTickets(-amount);
			}
			catch (exception &e) {
				cout << "Error: " << e.what() <<
				endl << "No change has been made." << endl;
			}
			}
			break;
		case 'c':
			{ int loc, amount; string name;
			cout << "== Location?" << endl << "> ";
			cin >> loc;
			cout << "== Movie name?" << endl << "> ";
			cin >> name;
			cout << "== Location capacity?" << endl << "> ";
			cin >> amount;
			try {
				screenings.push_back(Screening(loc, name, amount, 0));
			}
			catch (exception &e) {
				cout << "Error: " << e.what() <<
				endl << "No change has been made." << endl;
			}
			}
			break;
		case 'd':
			{ int loc;
			cout << "== Which screening? (Location?)" << endl << "> ";
			cin >> loc;
			try {
				int target_id;
				Screening *target = getScreening(loc, &target_id);
				cout << "== Removing screening of " << target->movieName() << "." << endl;
				screenings.erase(screenings.begin() + target_id);
			}
			catch (exception &e) {
				cout << "Error: " << e.what() <<
				endl << "No change has been made." << endl;
			}
			}
			break;
		case 'q':
			run = false;
			break;
		}
	}

	saveScreenings();
	return 0;
}