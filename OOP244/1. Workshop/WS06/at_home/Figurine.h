/***********************************************************************
// OOP244 Workshop 6: Class with a Resource
//
// File Figurin.h

	¢º Name: Youjin An
	¢º Email : yan24@myseneca.ca
	¢º Part: at_home
	¢º Date: 2019/Nov/07

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

		bool copy; // to determine whether the current object is a copy or not.
	public:
		// constructor
		Figurine();
		Figurine(const char* nick_name, const char* fig_pose, double fig_price, bool copy_check = false);
		~Figurine();

		// copy constructor
		Figurine(const Figurine& copy_fig);
		Figurine& operator=(const Figurine& copy_fig);

		//get
		const char* getName() const;
		const char* getPose() const;
		double getPrice() const;


		//set
		void setName(const char* set_name);
		void setPose(const char* set_pose);
		void setPrice(double set_price);

		std::ostream& display() const;

		operator bool() const;
		bool isCopy() const;
	};

	bool operator==(const Figurine& copy_fig_1, const Figurine& copy_fig_2);
}

#endif // SDDS_FIGURIN_H