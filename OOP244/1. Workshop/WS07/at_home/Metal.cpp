/***********************************************************************
// OOP244 Workshop 7: Dervied Classes & Custom I/O Operators
//
// File Metal.cpp

	¢º Name: Youjin An
	¢º Email : yan24@myseneca.ca
	¢º Part: at_home
	¢º Date: 2019/Nov/14

***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iomanip>

#include "Metal.h"

namespace sdds {

	Metal::Metal() {
		name = nullptr;
		mohs = 0.0;
		Ore::Ore();
	}

	Metal::Metal(double M_weight, int M_purity, const char* M_classification, const char* M_name, double M_mohs): Ore(M_weight, M_purity, M_classification) {

		if (M_name == nullptr || strlen(M_name) == 0) {

			Metal();
		}

		else {
			// name
			name = new char[NAME_LEN];
			strcpy(name, M_name);
			name[strlen(name) + 1] = '\0';

			// mohs
			if (M_mohs > 0) {
				mohs = M_mohs;
			}
			else {
				mohs = DEFAULT_MOHS;
			}
		}
	}

	Metal::~Metal() {
		delete[] name;
		name = nullptr;
	}

	void Metal::refine() {
		bool check = false;
		check = Ore::refine();
		// if that operation returned true, increment the Metal¡¯s mohs value by 1
		if(check == true){
			mohs += 1;
		}
	}

	ostream& Metal::display(ostream& os) const {
		// If the Metal is in an empty state
		if (name == nullptr && mohs == 0.0) {
			os << "This metal is imaginary" << endl;
		}
		else {
			cout << "Name: " << name << endl;
			Ore::display(os);
			cout << "Mohs: " << fixed << setprecision(2) << mohs << endl;
		}

		return cout;
	}

	istream& Metal::input(istream& is) {
		// name
		char temp_name_arr[NAME_LEN];

		cout << "Enter a value for this metal's name: ";
		is >> temp_name_arr;

		// if the name already has memory allocated to it, deallocate it.
		delete[] name;
		name = new char[NAME_LEN];
		strcpy(name, temp_name_arr);
		name[strlen(name) + 1] = '\0';

		// mohs
		double temp_mohs = DEFAULT_MOHS;
		bool done = false;

		cout << "Enter a value for this metal's mohs: ";

		cin.ignore(1000, '\n');
		while (!done) {
			is >> temp_mohs;
			if (cin.fail()) {
				cin.clear();
				cout << "Bad Number, try again: ";
			}
			else {
				done = true;
			}
			cin.ignore(1000, '\n');
		}

		if (temp_mohs > 0) {
			mohs = temp_mohs;
		}
		else {
			mohs = DEFAULT_MOHS;
		}
		
		// To accept user input to set the other data members inherited from Ore
		Ore::input(is);

		return is;
	}

	ostream& operator<<(ostream& os, const Metal& met) {
		cout << "Metal" << endl;
		met.display(os);
		return os;
	}

	istream& operator>>(istream& is, Metal& met) {
		met.input(is);
		return is;
	}
}