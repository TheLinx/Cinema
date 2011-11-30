#include <iostream>
#include "io.h"
#include "screening.h"
using namespace std; // only in this file... so it's okay, right?

int main()
{
	bool run = true;
	vector<Screening> screenings;
	loadScreenings(&screenings);

	while(run)
	{
		printAllScreenings(&screenings);
		cout << "== What do you want to do?" << endl;
		run = false;
	}

	saveScreenings(&screenings);
	return 0;
}