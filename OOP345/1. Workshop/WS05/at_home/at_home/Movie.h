// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:13 Feb, 2020

#ifndef SDDS_MOVIE_H__
#define SDDS_MOVIE_H__

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

namespace sdds {

	class Movie {

        string m_title;
        size_t yearOfpub;
        string description;

    public:
        Movie();    // a default constructor
        
        const string& title() const;    // a query that returns the title of the movie
        
        Movie(const string& strMovie);  // A constructor that receives the movie as a string

        //Template function
        template <typename T>
        void fixSpelling(T spellChecker){
            spellChecker(m_title);
            spellChecker(description);
        }

        // Friend Helper
        friend ostream& operator<<(ostream& os, const Movie& _Movie);
	};
}
#endif // SDDS_MOVIE_H__