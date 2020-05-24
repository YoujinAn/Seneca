// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:19 Jan, 2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>

#include "event.h"

namespace sdds {

	Event::Event() {
		null_terminated_ = nullptr;
		time = 0;
	}

	Event::~Event() {
		if (null_terminated_ == nullptr) {
			delete[] null_terminated_;
		}
	}

	std::ostream& Event::display(std::ostream& os)const {
		static int counter = 0;
		os << std::setw(3) << ++counter << ". ";
		if (null_terminated_ != nullptr)
			os << std::setfill('0') << std::setw(2) << time / 3600 << ':' << std::setw(2) << time / 60 % 60 << ':' << std::setw(2) << time % 60 << std::setfill(' ') << " -> " << null_terminated_ << std::endl;
		else
			os << "[ No Event ]" << std::endl;

		return os;
	}

	Event& Event::setDescription(const char* _desc) {
		if (_desc != nullptr) {
			if (null_terminated_ != nullptr)
			{
				null_terminated_ = nullptr;
			}
			null_terminated_ = new char[strlen(_desc) + 1];
			strcpy(null_terminated_, _desc);
			time = g_sysClock;
		}
		else {
			null_terminated_ = nullptr;
			time = 0;
		}
		return *this;
	}

}