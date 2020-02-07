// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:06 Feb, 2020

#ifndef SDDS_CONFIRMATIONSENDER_H__
#define SDDS_CONFIRMATIONSENDER_H__

#include <iostream>

#include "Reservation.h"

namespace sdds {

	class ConfirmationSender {
		const Reservation** resPointer;
		size_t numOfConfirm;
	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& copy);
		ConfirmationSender(ConfirmationSender&& move);
		~ConfirmationSender();

		ConfirmationSender& operator+=(const Reservation& res); // add the parameter to the array
		ConfirmationSender& operator-=(const Reservation& res); // remove the parameter from the array
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& con);
	};
}

#endif // SDDS_CONFIRMATIONSENDER_H__