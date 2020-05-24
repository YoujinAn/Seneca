// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:05 March, 2020

#define _CRT_SECURE_NO_WARNINGS

#include "Autoshop.h"

namespace sdds {

	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(std::ostream& out) const {
		out << "--------------------------------" << std::endl;
		out << "| Cars in the autoshop!        |" << std::endl;
		out << "--------------------------------" << std::endl;
		
		/*
		for (auto elem : this->m_vehicles) {
			elem->display(out);
			out << std::endl;
		}
		*/
		
		for (auto i = m_vehicles.begin(); i != m_vehicles.end(); i++)
		{
			(*i)->display(out);
			out << std::endl;
		}
			
		out << "--------------------------------" << std::endl;
	}
	
	std::ostream& operator<<(std::ostream& os, const Autoshop& obj) {
		obj.display(os);
		return os;
	}
	
}