// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:05 March, 2020

#define _CRT_SECURE_NO_WARNINGS

#include "Utilities.h"

namespace sdds {

	Vehicle* createInstance(std::istream& in) {
		std::stringstream buf;
		std::string line;
		std::getline(in, line);

		buf << line;
		char tag = '\0';
		buf >> tag;

		if (tag == 'c' || tag == 'C') {
			return new Car(buf);
		}
		else {
			return nullptr;
		}
	}
}