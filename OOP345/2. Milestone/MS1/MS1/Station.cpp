// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:14 March, 2020

#define _CRT_SECURE_NO_WARNINGS

#include "Station.h"

size_t Station::id_generator = 1;
size_t Station::s_widthField = 1;

Station::Station(const std::string str) {
	
	try {
		size_t tmp_pos = -1;
		bool check = true;
		s_name = util.extractToken(str, tmp_pos, check);
		s_serialNumber = std::stoi(util.extractToken(str, tmp_pos, check));
		s_quantity = std::stoi(util.extractToken(str, tmp_pos, check));
		s_description = util.extractToken(str, tmp_pos, check);

		this->s_quantity_count = id_generator++;

		if (util.getFieldWidth() < s_name.size()) {
			util.setFieldWidth(s_name.size());
		}

		if (s_widthField < s_name.length())
		{
			s_widthField = s_name.length();
		}
	}
	catch (const char* msg) {//get error message using exception
		std::cout << msg;
		exit(1);
	}
}

const std::string& Station::getItemName() const {
	return s_name;
}

const unsigned int Station::getNextSerialNumber() {
	return s_serialNumber++;
}

const unsigned int Station::getQuantity() {
	return s_quantity;
}

void Station::updateQuantity() {
	s_quantity -= 1;
}

void Station::display(std::ostream& os, bool full) const
{
	if (full == false)
	{
		os << "[" << std::setfill('0') << std::setw(3) << std::right << s_quantity_count << "] Item: ";
		os << std::setfill(' ') << std::setw(s_widthField) << std::left << s_name
			<< " [" << std::setfill('0') << std::setw(6) << std::right << s_serialNumber << "]";
	}
	else {
		os << "[" << std::setfill('0') << std::setw(3) << std::right << s_quantity_count << "] Item: ";
		os << std::setfill(' ') << std::setw(s_widthField) << std::left << s_name
			<< " [" << std::setfill('0') << std::setw(6) << std::right << s_serialNumber << "]"
			<< std::setfill(' ') << " Quantity: " << std::setw(s_widthField) << std::left << s_quantity
			<< " Description: " << s_description;
	}
	os << std::endl;
}
