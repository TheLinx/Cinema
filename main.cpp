#include <iostream>
#include "io.h"
#include "screening.h"
using namespace std; // only in this file... so it's okay, right?

int main()
{
	vector<Screening> screenings;
	loadScreenings(&screenings);

	printAllScreenings(&screenings);

	saveScreenings(&screenings);
	return 0;
}