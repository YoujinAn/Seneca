// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:12 Feb, 2020

#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

namespace sdds {

	class Book {

        string author;
        string b_title;
        string countryOfpub;
        size_t yearOfpub;
        double b_price;
        string description; // the summary of the book

    public:
        Book(); // a default constructor

        const string& title() const; // a query that returns the title of the book
        const string& country() const; // a query that returns the publication country
        const size_t& year() const; // a query that returns the publication year
        double& price(); // a function that returns the price by reference, allowing you to update the price
        Book(const string& strBook); //  A constructor that receives the book as a string

        // Friend Helper
        friend ostream& operator<<(ostream& os, const Book& _Book);
	};
}
#endif // SDDS_BOOK_H__