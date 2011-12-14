#include <exception>
#include <iostream>
#include <fstream>
#include <string>
#include "io.h"
#include "screening.h"
#include "order.h"

void loadScreenings()
{
	// define the variables we need when reading from the input file
	int tmpLoc, tmpTot, tmpSold;
	std::string tmpName;
	// open the file
	std::ifstream input("biljett.txt");

	if (!input) // if the file doesn't exist...
		return; // don't fuck up!
	input.seekg(0, std::ios::end);
	if (input.tellg() <= 1) // if the file is empty...
		return; // don't fuck up!
	input.seekg(0, std::ios::beg);
	
	while (!input.eof()) // loop until we're at the end of the file
	{
		input >> tmpLoc >> tmpName >> tmpTot >> tmpSold; // read info
		screenings.push_back(Screening(tmpLoc, tmpName, tmpTot, tmpSold)); // add a new Screening object to the screenings vector
	}

	// close the file
	input.close();
}

void loadOrders()
{
	int tmpId, tmpScrId, tmpAmount;
	std::string tmpName;
	std::ifstream input("order.txt");

	if(!input)
		return;
	input.seekg(0, std::ios::end);
	if (input.tellg() <= 1)
		return;
	input.seekg(0, std::ios::beg);

	while (true)
	{
		input >> tmpId >> tmpName >> tmpScrId >> tmpAmount;
		orders.push_back(Order(tmpName, tmpScrId, tmpAmount, tmpId));
		if (input.eof())
			break;
	}
}

void saveScreenings()
{
	// open the file again
	std::ofstream output("biljett.txt");

	for (unsigned i = 0; i < screenings.size(); i++)
	{ // for every member of the vector
		if (i > 0)
		{ // if we've already printed something
			output << std::endl; // print a new-line first
		}
		output << screenings.at(i); // now, print the screening, using the cout << thing
	}

	// and close the file
	output.close();
}

void saveOrders()
{
	std::ofstream output("order.txt");

	for (unsigned i = 0; i < orders.size(); i++)
	{
		if (i > 0)
		{
			output << std::endl;
		}
		output << orders.at(i);
	}

	output.close();
}