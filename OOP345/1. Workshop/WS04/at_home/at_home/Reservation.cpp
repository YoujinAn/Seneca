// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:06 Feb, 2020

#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <iostream>
#include <algorithm>

#include "Reservation.h"

namespace sdds {

    // default constructor
    Reservation::Reservation() {
        res_id = "";
        res_name = "";
        res_email = "";
        res_numppl = 0;
        party_day = 0;
        pary_hour = 0;
    }

    Reservation::Reservation(const string& res) {
        // get string
        auto id_fieldEnd = res.find(':') + 1; // value is 9
        auto name_fieldEnd = res.find(','); // value is 18
        auto email_fieldEnd = res.find(',', name_fieldEnd + 1); // value is 37
        auto num_fieldEnd = res.find(',', email_fieldEnd + 1); // value is 50
        auto day_fieldEnd = res.find(',', num_fieldEnd + 1); // values is 55
        auto time_fieldEnd = res.length(); // end of line

        res_id = res.substr(0, id_fieldEnd); // get string from id_field
        res_id.erase(remove(res_id.begin(), res_id.end(), ' '), res_id.end()); // remove the ' '
        
        res_name = res.substr(id_fieldEnd, name_fieldEnd - id_fieldEnd); // get string between res_id and res_name field
        res_name.erase(remove(res_name.begin(), res_name.end(), ' '), res_name.end()); //remove the ' '
        
        res_email = res.substr(name_fieldEnd + 1, email_fieldEnd - name_fieldEnd - 1); // get string betwwen res_name and res_email field
        res_email.erase(remove(res_email.begin(), res_email.end(), ' '), res_email.end()); // remove the ' '
        res_email.append(">"); // append the > for print out
        
        res_numppl = stoi(res.substr(email_fieldEnd + 1, num_fieldEnd - email_fieldEnd - 1)); // get interger of people number number using stoi
        party_day = stoi(res.substr(num_fieldEnd + 1, day_fieldEnd - num_fieldEnd - 1)); // get interger of day number number using stoi
        pary_hour = stoi(res.substr(day_fieldEnd + 1, time_fieldEnd - day_fieldEnd - 1)); // get interger of hour(time) number number using stoi
    }

    ostream& operator<<(ostream& os, const Reservation& res) {
        // insert the content of a reservation object
        string time;
        if (res.pary_hour >= 6 && res.pary_hour <= 9)
            time = "Breakfast on day";
        else if (res.pary_hour >= 11 && res.pary_hour <= 15)
            time = "Lunch on day";
        else if (res.pary_hour >= 17 && res.pary_hour <= 21)
            time = "Dinner on day";
        else
            time = "Drinks on day";

        // Print -> ID:NAME,EMAIL,PARTY SIZE,DAY,HOUR
        // ex) Reservation RES-001:       John  <john@email.com>        Drinks on day 3 @ 5:00 for 2 people.
        os << "Reservation " << res.res_id << setw(11) << right << res.res_name << "  <" << setw(23) << left << res.res_email << time << " " << res.party_day << " @ " << res.pary_hour << ":00 for " << res.res_numppl << " people." << endl;
        return os;
    }
}