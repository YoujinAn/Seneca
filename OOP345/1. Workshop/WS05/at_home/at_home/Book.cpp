// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:13 Feb, 2020

#define _CRT_SECURE_NO_WARNINGS

#include "Book.h"

namespace sdds {

	Book::Book() {
		author = "";
		b_title = "";
		countryOfpub = "";
		yearOfpub = 0;
		b_price = 0.0;
		description = "";
	}

	const string& Book::title() const {
		return b_title;
	}

	const string& Book::country() const {
		return countryOfpub;
	}

	const size_t& Book::year() const {
		return yearOfpub;
	}

	double& Book::price() {
		return b_price;
	}

	Book::Book(const string& strBook) {
		auto author_field = strBook.find(',');
		auto title_field = strBook.find(',', author_field + 1);
		auto country_field = strBook.find(',', title_field + 1);
		auto price_field = strBook.find(',', country_field + 1);
		auto years_field = strBook.find(',', price_field + 1);
		auto desc_field = strBook.length();

		// author
		author = strBook.substr(0, author_field);
		author.erase(0, author.find_first_not_of(" "));
		author.erase(author.find_last_not_of(" ") + 1);

		// title
		b_title = strBook.substr(author_field + 1, title_field - author_field - 1);
		b_title.erase(0, b_title.find_first_not_of(" "));
		b_title.erase(b_title.find_last_not_of(" ") + 1);

		// countryOfpub
		countryOfpub = strBook.substr(title_field + 1, country_field - title_field - 1);
		countryOfpub.erase(0, countryOfpub.find_first_not_of(" "));
		countryOfpub.erase(countryOfpub.find_last_not_of(" ") + 1);

		// year
		yearOfpub = stoi(strBook.substr(price_field + 1, years_field - price_field - 1));

		// price
		b_price = stod(strBook.substr(country_field + 1, price_field - country_field - 1));

		// description
		description = strBook.substr(years_field + 1, desc_field - years_field - 1);
		description.erase(0, description.find_first_not_of(" "));
	}

	ostream& operator<<(ostream& os, const Book& _Book) {
		// AUTHOR,TITLE,COUNTRY,PRICE,YEAR,DESCRIPTION
		os << setw(20) << setfill(' ') << _Book.author << " | ";
		os << setw(22) << setfill(' ') << _Book.b_title << " | ";
		os << setw(5) << setfill(' ') << _Book.countryOfpub << " | ";
		os << setw(4) << setfill(' ') << _Book.yearOfpub << " | ";
		os << setw(6) << setfill(' ') << fixed << setprecision(2) << _Book.b_price << " | ";
		os << setw(22) << setfill(' ') << _Book.description;
		os << '\n';
		return os;
	}
}