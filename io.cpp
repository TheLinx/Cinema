#include <exception>
#include <iostream>
#include <fstream>
#include <string>
#include "io.h"
#include "screening.h"
#include "order.h"

void loadScreenings()
{
	int tmpLoc, tmpTot, tmpSold;
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
		screenings.push_back(Screening(tmpLoc, tmpName, tmpTot, tmpSold));
		if (input.eof()) // we're at the end of the file, let's quit
			break;
	}

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
	std::ofstream output("biljett.txt");

	for (unsigned i = 0; i < screenings.size(); i++)
	{
		if (i > 0)
		{
			output << std::endl;
		}
		output << screenings.at(i);
	}

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