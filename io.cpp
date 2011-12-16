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
	std::string tmpData[4];
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
		// read info
		getline(input, tmpData[0], '\t'); // location
		getline(input, tmpData[1], '\t'); // movie name
		getline(input, tmpData[2], '\t'); // total tickets
		getline(input, tmpData[3], '\n'); // sold tickets
		Screening(stoi(tmpData[0]), tmpData[1], stoi(tmpData[2]), stoi(tmpData[3])); // create a new Screening object
	}

	// close the file
	input.close();
}

void loadOrders()
{
	std::string tmpData[4];
	std::ifstream input("order.txt");

	if(!input)
		return;
	input.seekg(0, std::ios::end);
	if (input.tellg() <= 1)
		return;
	input.seekg(0, std::ios::beg);

	while (!input.eof())
	{
		getline(input, tmpData[0], '\t'); // ID
		getline(input, tmpData[1], '\t'); // customer name
		getline(input, tmpData[2], '\t'); // screening id
		getline(input, tmpData[3], '\n'); // amount of tickets
		Order(tmpData[1], stoi(tmpData[2]), stoi(tmpData[3]), stoi(tmpData[0]));
	}

	input.close();
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
		output << screenings[i]; // now, print the screening, using the cout << thing
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
		output << orders[i];
	}

	output.close();
}