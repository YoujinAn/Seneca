// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:06 March, 2020

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <iostream>
#include <string>

#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle {
	private:
		std::string c_tag;
		std::string c_maker;
		std::string c_condition; // a car can be new, used, or broken in need of repairs.
		double top_speed;

	public:
		Car();
		Car(std::istream&); // a custom constructor that receives an object of type
		
		// a query that returns new, used or broken, representing the condition of the car
		std::string maker() const;
		std::string condition() const;
		double topSpeed() const;
		// a query that inserts in the first parameter the content of the car object
		void display(std::ostream& out) const;

		friend std::ostream& operator<<(std::ostream& os, const Car& obj);
	};
}

#endif // SDDS_CAR_H
