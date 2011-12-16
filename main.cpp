#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
#include "io.h"
#include "screening.h"
#include "order.h"
using namespace std; // only in this file... so it's okay, right?

int main()
{
	// variables we use in the entire main function
	char cmd; // we use this in the menu
	string input[3];
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
		cmd = cin.peek();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
			cout << "== Which screening? (Location?)" << endl << "> ";
			getline(cin, input[0]);
			cout << "== How many tickets?" << endl << "> ";
			getline(cin, input[1]);
			try {
				Screening *target = getScreening(stoi(input[0]));
				cout << "== Reserving " << input[1] << " tickets for screening of " << target->movieName() << "." << endl;
				target->sellTickets(stoi(input[1]));
			}
			catch (exception &e) {
				cout << "Error: " << e.what() <<
				endl << "No change has been made." << endl;
			}
			break;
		case 'b':
			cout << "== Which screening? (Location?)" << endl << "> ";
			getline(cin, input[0]);
			cout << "== How many tickets?" << endl << "> ";
			getline(cin, input[1]);
			try {
				Screening *target = getScreening(stoi(input[0]));
				cout << "== Returning " << input[1] << " tickets for screening of " << target->movieName() << "." << endl;
				target->sellTickets(-stoi(input[1]));
			}
			catch (exception &e) {
				cout << "Error: " << e.what() <<
				endl << "No change has been made." << endl;
			}
			break;
		case 'c':
			cout << "== Location?" << endl << "> ";
			getline(cin, input[0]);
			cout << "== Movie name?" << endl << "> ";
			getline(cin, input[1]);
			cout << "== Location capacity?" << endl << "> ";
			getline(cin, input[2]);
			try {
				Screening(stoi(input[0]), input[1], stoi(input[2]), 0);
			}
			catch (exception &e) {
				cout << "Error: " << e.what() <<
				endl << "No change has been made." << endl;
			}
			break;
		case 'd':
			cout << "== Which screening? (Location?)" << endl << "> ";
			getline(cin, input[0]);
			try {
				unsigned target_id;
				Screening *target = getScreening(stoi(input[0]), &target_id);
				cout << "== Removing screening of " << target->movieName() << "." << endl;
				target->purgeOrders();
				screenings.erase(screenings.begin() + target_id);
			}
			catch (exception &e) {
				cout << "Error: " << e.what() <<
				endl << "No change has been made." << endl;
			}
			break;
		case 'e':
			cout << "== Which screening? (Location?)" << endl << "> ";
			getline(cin, input[0]);
			cout << "== Under what name?" << endl << "> ";
			getline(cin, input[1]);
			cout << "== How many tickets?" << endl << "> ";
			getline(cin, input[2]);
			try {
				unsigned target_id;
				Screening *target = getScreening(stoi(input[0]), &target_id);
				cout << "== Booking " << input[2] << " tickets for screening of " << target->movieName() << " for " << input[1] << "." << endl;
				Order(input[1], target_id, stoi(input[2]));
			}
			catch (exception &e) {
				cout << "Error: " << e.what() <<
				endl << "No change has been made." << endl;
			}
			break;
		case 'f':
			cout << "== Which order? (Id?)" << endl << "> ";
			getline(cin, input[0]);
			try {
				unsigned id;
				Order *order = getOrder(stoi(input[0]), &id); // check that it exists before we remove it
				cout << "== Removing order with id " << input[0] << "." << endl;
				order->returnTickets();
				orders.erase(orders.begin() + id);
			}
			catch (exception &e) {
				cout << "Error: " << e.what() <<
				endl << "No change has been made." << endl;
			}
			break;
		case 'g':
			cout << "== Which order? (Id?)" << endl << "> ";
			getline(cin, input[0]);
			try {
				unsigned id;
				Order *order = getOrder(stoi(input[0]), &id); // check that it exists before we remove it
				cout << "== Completing order with id " << input[0] << "." << endl;
				orders.erase(orders.begin() + id);
			}
			catch (exception &e) {
				cout << "Error: " << e.what() <<
				endl << "No change has been made." << endl;
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