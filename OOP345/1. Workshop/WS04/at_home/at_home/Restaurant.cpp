// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:06 Feb, 2020

#define _CRT_SECURE_NO_WARNINGS

#include "Restaurant.h"

namespace sdds {

	Restaurant::Restaurant() {
		res = nullptr;
		numOfres = 0;
	}

	Restaurant::Restaurant(Reservation* reservations[], size_t cnt) {
		numOfres = cnt;
		res = new Reservation[numOfres]; //dynamic allocated array for saving reservaton
		for (size_t i = 0; i < numOfres; i++) {
			res[i] = *reservations[i];
		}
	}

	Restaurant::Restaurant(const Restaurant& res_copy) {
		if (this != &res_copy) {
			numOfres = res_copy.numOfres;
			if (res_copy.res != nullptr) {
				res = new Reservation[numOfres];
				for (size_t i = 0; i < numOfres; i++) {
					res[i] = res_copy.res[i];
				}
			}
			else {
				res = nullptr;
			}
		}
	}

	Restaurant::Restaurant(Restaurant&& move) {
		numOfres = move.numOfres;
		move.numOfres = 0;
		res = move.res;
		move.res = nullptr;
	}

	Restaurant::~Restaurant() { // destructor
		delete[] res;
	}
	size_t Restaurant::size() const {
		return numOfres; // return size of reservation
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& res) {
		os << "--------------------------" << std::endl
			<< "Fancy Restaurant" << std::endl
			<< "--------------------------" << std::endl;
		if (res.numOfres == 0) {
			os << "The object is empty!" << std::endl;
		}
		else {
			for (size_t i = 0; i < res.numOfres; i++) {
				os << res.res[i];
			}
		}
		os << "--------------------------" << std::endl;

		return os;
	}
}