/***********************************************************************
// OOP244 Workshop 7: Dervied Classes & Custom I/O Operators
//
// File Metal.h

	¢º Name: Youjin An
	¢º Email : yan24@myseneca.ca
	¢º Part: at_home
	¢º Date: 2019/Nov/14

***********************************************************************/

#ifndef SDDS_METAL_H
#define SDDS_METAL_H

#include "Ore.h"

namespace sdds {

	const double DEFAULT_MOHS = 2.5; // to set the default mohs of a Metal
	const int NAME_LEN = 10; // to determine the max length of the name for a metal

	class Metal : public Ore {
	private:
		char* name; // the name of the Metal.
		double mohs; // the mohs of the Metal
	public:
		Metal();
		Metal(double M_weight, int M_purity, const char* M_classification, const char* M_name, double M_mohs);
		~Metal();

		void refine();
		ostream& display(ostream& os) const;
		istream& input(istream& is);
	};
	ostream& operator<<(ostream& os, const Metal& met);
	istream& operator>>(istream& is, Metal& met);
}

#endif // SDDS_METAL_H

