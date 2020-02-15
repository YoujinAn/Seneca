// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:13 Feb, 2020

#define _CRT_SECURE_NO_WARNINGS

#include "Movie.h"

namespace sdds {

	Movie::Movie() {
		m_title = "";
		yearOfpub = 0;
		description = "";
	}

	const string& Movie::title() const {
		return m_title;
	}

	Movie::Movie(const string& strMovie) {
        auto title_field = strMovie.find(',');
        auto year_field = strMovie.find(',', title_field + 1);
        auto desc_field = strMovie.find('.', year_field + 1);

        // Movie title
        m_title = strMovie.substr(0, title_field);
        m_title.erase(0, m_title.find_first_not_of(" "));
        m_title.erase(m_title.find_last_not_of(" ") + 1);

        // // year
        yearOfpub = stoi(strMovie.substr(title_field + 1, year_field - title_field - 1));
        
        // description
        description = strMovie.substr(year_field + 1, desc_field - year_field + 1);
        description.erase(0, description.find_first_not_of(" "));
	}

    ostream& operator<<(ostream& os, const Movie& _Movie) {
		// TITLE | YEAR | DESCRIPTION
        os << setw(40) << setfill(' ') << _Movie.m_title << " | ";
        os << setw(4) << setfill(' ') << _Movie.yearOfpub << " | ";
        os << setw(22) << setfill(' ') << _Movie.description;
        os << '\n';
        return os;
    }
}