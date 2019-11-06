/***********************************************************************
// OOP244 Workshop 6: Class with a Resource
//
// File Figurin.h

	¢º Name: Youjin An
	¢º Email : yan24@myseneca.ca
	¢º Part: in_lab
	¢º Date: 2019/Nov/06

***********************************************************************/

#ifndef SDDS_FIGURIN_H
#define SDDS_FIGURIN_H

#include <iostream>
using namespace std;

namespace sdds {

	const int MAX_NAME_LEN = 20;		// To set the maximum length of the name of the Figurine. 
	const double DEFAULT_PRICE = 25.25;	// To set the default price of a Figurine if an invalid value is given

	class Figurine {

	private:
		char name[MAX_NAME_LEN + 1]; // Remember to consider the nullbyte.
		char* pose;
		double price;
	public:
		Figurine();
		Figurine(const char* nick_name, const char* fig_pose, double fig_price);
		~Figurine();

		Figurine(const Figurine& copy_fig);

		void setName(const char* set_name);
		void setPose(const char* set_pose);
		void setPrice(double set_price);
		std::ostream& display() const;

		operator bool() const;
	};
}

#endif // SDDS_FIGURIN_H