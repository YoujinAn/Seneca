// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:14 March, 2020

// Station class encapsulates the information about a given station on the assembly line that fills customer orders.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <iostream>
#include <string>
#include <iomanip>

#include "Utilities.h"

class Station {
private:
	unsigned int s_id;
	std::string s_name;
	std::string s_description;
	unsigned int s_serialNumber;
	unsigned int s_quantity;

	Utilities util;
	static size_t s_widthField;
	size_t s_quantity_count = 0;

public:
	static size_t id_generator;

	Station(const std::string str);

	const std::string& getItemName() const;
	const unsigned int getNextSerialNumber();
	const unsigned int getQuantity();
	void updateQuantity();
	void display(std::ostream& os, bool full) const;
};
#endif // SDDS_STATION_H