// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:06 Feb, 2020

#define _CRT_SECURE_NO_WARNINGS

#include "ConfirmationSender.h"

namespace sdds {

	ConfirmationSender::ConfirmationSender() {
		resPointer = nullptr;
		numOfConfirm = 0;
	}
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& copy) {
		numOfConfirm = copy.numOfConfirm;
		if (numOfConfirm > 0) {
			resPointer = const_cast<const Reservation**>(new Reservation * [numOfConfirm]); // dynamic allocated with const cast
			for (size_t i = 0; i < numOfConfirm; i++) {
				resPointer[i] = copy.resPointer[i];
			}
		}
		else {
			resPointer = nullptr;
		}
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& move) {
		resPointer = move.resPointer;
		numOfConfirm = move.numOfConfirm;
		move.resPointer = nullptr;
		move.numOfConfirm = 0;
	}
	ConfirmationSender::~ConfirmationSender() {
		delete[] resPointer;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool existed = true;

		for (size_t i = 0; i < numOfConfirm && existed; i++) {
			if (resPointer[i] == &res) { // compare existed array with &res
				existed = false; // operator does nothing
			}
		}

		if (existed) {
			Reservation** tmp = new Reservation * [numOfConfirm + 1]; // dynamic allocate in temporary
			for (size_t i = 0; i < numOfConfirm; i++) {
				tmp[i] = const_cast<Reservation*>(resPointer[i]); // copy the value using const cast
			}
			delete[] resPointer; // deallocate original variable
			resPointer = const_cast<const Reservation**>(tmp);
			resPointer[numOfConfirm++] = &res;
		}


		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		bool existed = true;
		size_t i = 0;
		for (; i < numOfConfirm && existed; i++) { // compare existed array with &res
			if (resPointer[i] == &res) {
				existed = false;
			}
		}

		if (!existed) { // if value is in the original array
			Reservation** tmp = new Reservation * [numOfConfirm--];
			if (i > 0) {
				for (size_t j = 0; j < i; j++) { //copy the value before the existed value
					tmp[j] = const_cast<Reservation*>(resPointer[j]);
				}
			}
			for (size_t j = i; j < numOfConfirm; j++) { // copy after existed value
				tmp[j] = const_cast<Reservation*>(resPointer[j + 1]);
			}
			delete[] resPointer;
			resPointer = const_cast<const Reservation**>(tmp);
		}
		return *this;
	}

	ostream& operator<<(ostream& os, const ConfirmationSender& con) {
		os << "--------------------------" << std::endl;
		os << "Confirmations to Send" << std::endl;
		os << "--------------------------" << std::endl;
		if (con.numOfConfirm == 0) {
			os << "The object is empty!" << std::endl;
		}
		else {
			for (size_t i = 0; i < con.numOfConfirm; i++) {
				os << *con.resPointer[i];
			}
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}