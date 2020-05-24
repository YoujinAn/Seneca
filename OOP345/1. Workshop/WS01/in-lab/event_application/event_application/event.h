// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:16 Jan, 2020
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef SDDS_EVENT_H__
#define SDDS_EVENT_H__

#include <iostream>

// a global variable named g_sysClock that stores only positive integers.
extern unsigned int g_sysClock;

namespace sdds {

	class Event {
		// a C-style null-terminated string of up to 128 characters including the null byte terminator representing the description of the event.
		char null_terminated_[129]; 
		// The time must be an integer between 0 and 86400
		int time;

	public:
		Event();
		std::ostream& display(std::ostream& os = std::cout)const;
		// setDescription() : a modifier that receives as a parameter an array of characters.
		Event& setDescription(const char _desc[]);
	};
}
#endif // SDDS_EVENT_H__