#include <iostream>
#include <ctime>
#include <cstdlib>
#include "io.h"
#include "screening.h"
#include "order.h"
using namespace std; // only in this file... so it's okay, right?

int main()
{
	char cmd;
	bool run = true;
	srand((unsigned)time(NULL));
	loadScreenings();
	loadOrders();

	while(run)
	{
		printAllScreenings();
		printAllOrders();
		cout << "== What do you want to do?" << endl;
		cout << " a) Buy tickets" << endl;
		cout << " b) Return tickets" << endl;
		cout << " c) Add a screening" << endl;
		cout << " d) Remove a screening" << endl;
		cout << " e) Add an order" << endl;
		cout << " f) Cancel an order" << endl;
		cout << " g) Remove an order" << endl;
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
		case 'e':
			{ int loc, amount; string name;
			cout << "== Which screening? (Location?)" << endl << "> ";
			cin >> loc;
			cout << "== How many tickets?" << endl << "> ";
			cin >> amount;
			cout << "== Under what name?" << endl << "> ";
			cin >> name;
			try {
				int target_id;
				Screening *target = getScreening(loc, &target_id);
				cout << "== Booking " << amount << " tickets for screening of " << target->movieName() << " for " << name << "." << endl;
				orders.push_back(Order(name, target_id, amount));
			}
			catch (exception &e) {
				cout << "Error: " << e.what() <<
				endl << "No change has been made." << endl;
			}
			}
			break;
		case 'f':
			{ int id;
			cout << "== Which order? (Id?)" << endl << "> ";
			cin >> id;
			try {
				Order *order = getOrder(id); // check that it exists before we remove it
				cout << "== Removing order with id " << id << "." << endl;
				order->returnTickets();
				orders.erase(orders.begin() + id);
			}
			catch (exception &e) {
				cout << "Error: " << e.what() <<
				endl << "No change has been made." << endl;
			}
			}
			break;
		case 'g':
			{ int id;
			cout << "== Which order? (Id?)" << endl << "> ";
			cin >> id;
			try {
				getOrder(id); // check that it exists before we remove it
				cout << "== Completing order with id " << id << "." << endl;
				orders.erase(orders.begin() + id);
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
	saveOrders();
	return 0;
}