// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:05 Feb, 2020

#ifndef SDDS_RESERVATION_H__
#define SDDS_RESERVATION_H__

#include <iostream>
#include <string>
using namespace std;

namespace sdds {

	class Reservation {
        string res_id;      // an array of characters
        string res_name;    // the name on the reservation
        string res_email;
        size_t res_numppl;     // the number of people in the party
        int party_day;         // (between 1 and 31)
        int pary_hour;         // (between 1 and 24)
    public:
        Reservation();         // a default constructor
        Reservation(const std::string& res);      //  receives the reservation as a string
        
        // Friend Helper
        friend ostream& operator<<(ostream& os, const Reservation& res);
	};
}

#endif // SDDS_RESERVATION_H__