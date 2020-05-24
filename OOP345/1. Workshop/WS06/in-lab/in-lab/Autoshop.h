// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:05 March, 2020

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <iostream>
#include <vector>

#include "Vehicle.h"

namespace sdds
{
	class Autoshop {
	private:
		// a vector that store all the vehicles available at this autoshop.
		std::vector<Vehicle*> m_vehicles;
	public:
		// adds the vehicle received as parameter into the m_vehicles vector.
		Autoshop& operator +=(Vehicle* theVehicle);

		// iterates over the vehicles stored in m_vehicles and prints them into the parameter
		void display(std::ostream& out) const;
		friend std::ostream& operator<<(std::ostream& os, const Autoshop& obj);
	};
}

#endif
