// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:06 Feb, 2020

#ifndef SDDS_RESTAURANT_H__
#define SDDS_RESTAURANT_H__

#include <iostream>

#include "Reservation.h"

namespace sdds {

	class Restaurant {
		Reservation* res;
		size_t numOfres;

	public:
		Restaurant();
		Restaurant(Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& res_copy);	// should store copies of all reservations
		Restaurant(Restaurant&& move);
		~Restaurant();

		size_t size() const;	// return how many reservations are in the system
		friend std::ostream& operator<<(std::ostream& os, const Restaurant& res);
	};
}

#endif // SDDS_RESTAURANT_H__