// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:05 March, 2020

#ifndef SDDS_RECECAR_H
#define SDDS_RECECAR_H

#include "Car.h"

namespace sdds {

	class Racecar : public Car {
		// the percentage (stored as a number between 0 an 1) by which this Racecar can boost its top speed.
		double m_booster;

	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		// returns the top speed of the car, including any booster effects.
		double topSpeed() const;

		friend std::ostream& operator<<(std::ostream& os, const Racecar& obj);
	};
}

#endif // SDDS_RECECAR_H