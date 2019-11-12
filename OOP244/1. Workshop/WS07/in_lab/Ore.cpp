/***********************************************************************
// OOP244 Workshop 7: Dervied Classes & Custom I/O Operators
//
// File Ore.cpp

	¢º Name: Youjin An
	¢º Email : yan24@myseneca.ca
	¢º Part: in_lab
	¢º Date: 2019/Nov/14

***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iomanip>

#include "Ore.h"

namespace sdds {

	Ore::Ore() {
		weight = 0.0;
		purity = 0;
		classification[0] = '\0';
	}

	Ore::Ore(double O_weight, int O_purity, const char* O_class) {
		// weight
		if (O_weight < 1) {
			weight = DEFAULT_WEIGHT;
		}
		else {
			weight = O_weight;
		}

		// purity
		if (O_purity < 1 || 100 < O_purity) {
			purity = DEFAULT_PURITY;
		}
		else {
			purity = O_purity;
		}

		// classification
		strncpy(classification, O_class, CLASS_LEN);
		classification[strlen(classification) + 1] = '\0';
	}

	bool Ore::refine() {
		// If an Ore is already at 100 purity
		if (purity >= 100) {
			cout << "Can no longer be refined" << endl;
			return false;
		}
		
		weight -= 20;
		purity += 10;

		// The purity of an Ore cannot exceed 100
		if (purity > 100) {
			purity = 100;
		}

		return true;
	}

	ostream& Ore::display(ostream& os) const {
		// If the Ore is in an empty state
		if (weight == 0.0 && purity == 0) {
			os << "This ore is imaginary" << endl;
		}
		else {
			os << "Weight: " << fixed << setprecision(2) << weight << endl;
			os << "Purity: " << purity << endl;
			os << "Classification: " << classification << endl;
		}
		
		return cout;
	}

	istream& Ore::input(istream& is) {
		// weight
		double temp_weight = 0.0;
		cout << "Enter a value for this ore's weight: ";
		is >> temp_weight;

		// purity
		int temp_purity = 0;
		cout << "Enter a value for this ore's purity: ";
		is >> temp_purity;

		// classification
		char temp_classification[CLASS_LEN]; // 30
		cout << "Enter a classification for the ore (MAX 30 chars): ";

		bool done = false;
		cin.ignore(1000, '\n');
		while (!done) {
			is >> temp_classification;
			if (cin.fail()) {
				cin.clear();
				cout << "Bad Number, try again: ";
			}
			else {
				done = true;
			}
			cin.ignore(1000, '\n');
		}

		Ore temp(temp_weight, temp_purity, temp_classification);
		if (temp.weight != 0) {
			*this = temp;
		}
		else
			*this = Ore();

		return is;
	}

	ostream& operator<<(ostream& os, const Ore& ore){
		cout << "Ore" << endl;
		ore.display(os);
		return os;
	}

	istream& operator>>(istream& os, Ore& ore) {
		ore.input(os);
		return os;
	}
}