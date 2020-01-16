// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:16 Jan, 2020
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
        null_terminated_[0] = '\0';
        time = 0;
    }

    std::ostream& Event::display(std::ostream& os)const {
        static int counter = 0;
        os << std::setw(3) << ++counter << ". ";
        if (null_terminated_[0] != '\0')
            os << std::setfill('0') << std::setw(2) << time / 3600 << ':' << std::setw(2) << time / 60 % 60 << ':' << std::setw(2) << time % 60 << std::setfill(' ') << " -> " << null_terminated_ << std::endl;
        else
            os << "[ No Event ]" << std::endl;

        return os;
    }

    Event& Event::setDescription(const char _desc[]) {
        if (_desc && _desc[0] != '\0') {
            time = g_sysClock;
            strncpy(null_terminated_, _desc, 128);
            null_terminated_[128] = '\0';
        }
        else {
            null_terminated_[0] = '\0';
        }
        return *this;
    }

}