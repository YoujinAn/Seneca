// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:06 March, 2020

#define _CRT_SECURE_NO_WARNINGS

#include "Racecar.h"

namespace sdds {

	Racecar::Racecar(std::istream& in) :Car::Car(in) {
		char deli;
		in >> deli >> m_booster;
	}

	void Racecar::display(std::ostream& out) const {
		Car::display(out);
		if (m_booster) {
			out << "*";
		}
	}

	double Racecar::topSpeed() const {
		return Car::topSpeed() * (1 + m_booster);
	}

	std::ostream& operator<<(std::ostream& os, const Racecar& obj) {
		obj.display(os);
		return os;
	}
}
