#include <exception>
#include <iostream>
#include <fstream>
#include <string>
#include "io.h"

void loadScreenings(std::vector<Screening> *vec)
{
	int tmpLoc, tmpTot, tmpSold, counter = 1;
	std::string tmpName;
	std::ifstream input("biljett.txt");

	if (!input) // if the file doesn't exist...
		return; // don't fuck up!
	input.seekg(0, std::ios::end);
	if (input.tellg() <= 1) // if the file is empty...
		return; // don't fuck up!
	input.seekg(0, std::ios::beg);
	
	while (true)
	{
		input >> tmpLoc >> tmpName >> tmpTot >> tmpSold;
		vec->push_back(Screening(tmpLoc, tmpName, tmpTot, tmpSold));
		if (input.eof()) // we're at the end of the file, let's quit
			break;
	}

	input.close();
}

void saveScreenings(std::vector<Screening> *vec)
{
	std::ofstream output("biljett.txt");

	for (int i = 0; i < vec->size(); i++)
	{
		if (i > 0)
		{
			output << std::endl;
		}
		output << vec->at(i);
	}

	output.close();
}