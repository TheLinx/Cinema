#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include "io.h"
#include "screening.h"
#include "order.h"
using namespace std; // only in this file... so it's okay, right?

int main()
{
	// variables we use in the entire main function
	char cmd; // we use this in the menu
	bool run = true; // the flag to keep running -- we can't use break to get out of the loop while in a switch-case clause
	srand((unsigned)time(NULL)); rand(); rand(); // seed the random generator so we get somewhat random numbers
	// load saved data
	loadScreenings();
	loadOrders();

	while(run)
	{
		// show the current state of information
		printAllScreenings();
		printAllOrders();
		// show the user's options
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
		fflush(stdin); // just in case something is in the input buffer
		cin >> cmd;
		switch(cmd)
		{
		/*
		case 'option':
			{ variables we use in this function;
			read information
			try {
				do the information modification
			}
			catch (exception &e) {
				something went wrong, tell the user
			}
			}
			break;
		*/
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
				Screening(loc, name, amount, 0);
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
				target->purgeOrders();
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
				Order(name, target_id, amount);
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
			// flip the flag
			run = false;
			break;
		}
	}

	// time to say goodbye
	saveScreenings();
	saveOrders();
	return 0;
}