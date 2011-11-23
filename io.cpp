#include <exception>
#include <iostream>
#include <fstream>
#include "io.h"

void loadScreenings(std::vector<Screening> *vec)
{
	int tmpLoc, tmpTot, tmpSold, counter = 1;
	std::ifstream input("biljett.txt");

	while (true)
	{
		input >> tmpLoc >> tmpTot >> tmpSold;
		vec->push_back(Screening(tmpLoc, tmpTot, tmpSold));
		if (input.eof()) // we're at the end of the file, let's quit
			break;
	}
}

void saveScreenings(std::vector<Screening> *vec)
{
	
}