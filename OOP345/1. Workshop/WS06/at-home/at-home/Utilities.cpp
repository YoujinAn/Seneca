// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:05 March, 2020

#define _CRT_SECURE_NO_WARNINGS

#include "Utilities.h"

namespace sdds {

	Vehicle* createInstance(std::istream& in) {
		std::string line = "";

		std::getline(in, line, '\n');
		std::stringstream buf(line);

		std::getline(buf, line, ',');
		line.erase(0, line.find_first_not_of(" "));
		line.erase(line.find_last_not_of(" ") + 1);

		if (in.fail() || line.length() != 1)
			return nullptr;
		if (line[0] == 'c' || line[0] == 'C') {
			return new Car(buf);
		}
		else if (line[0] == 'r' || line[0] == 'R') {
			return new Racecar(buf);
		}
		else {
			throw line[0];
		}

	}
}