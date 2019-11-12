/***********************************************************************
// OOP244 Workshop 7: Dervied Classes & Custom I/O Operators
//
// File Ore.h

	¢º Name: Youjin An
	¢º Email : yan24@myseneca.ca
	¢º Part: at_home
	¢º Date: 2019/Nov/14

***********************************************************************/

#ifndef SDDS_ORE_H
#define SDDS_ORE_H

#include <iostream>
using namespace std;

namespace sdds {

	const double DEFAULT_WEIGHT = 300.50; // to set the default weight of the Ore. 
	const int DEFAULT_PURITY = 20; // to set the default purity
	const int CLASS_LEN = 30; // to set the max length of the classification

	class Ore {
	private:
		double weight;
		int purity;
		char classification[CLASS_LEN]; // 30
	public:
		Ore();
		Ore(double O_weight, int O_purity, const char* O_class = "Unknown");

		bool refine();
		ostream& display(ostream& os) const;
		istream& input(istream& is);
	};
	ostream& operator<<(ostream& os, const Ore& ore);
	istream& operator>>(istream& is, Ore& ore);
}

#endif // SDDS_ORE_H