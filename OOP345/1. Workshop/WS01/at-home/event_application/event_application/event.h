// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:19 Jan, 2020
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
		// a C-style nullterminated string of any length.
		char* null_terminated_;
		// The time must be an integer between 0 and 86400
		int time;

	public:
		Event();
		// Make sure your program doesn't have memory leaks.
		~Event();

		std::ostream& display(std::ostream& os = std::cout)const;
		// setDescription() : a modifier that receives as a parameter an array of characters.
		Event& setDescription(const char* _desc);
	};
}
#endif // SDDS_EVENT_H__