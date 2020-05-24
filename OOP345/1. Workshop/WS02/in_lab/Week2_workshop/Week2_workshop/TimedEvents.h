// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:23 Jan, 2020

#ifndef SDDS_TIMEDEVENTS_H__
#define SDDS_TIMEDEVENTS_H__

#include <iostream>
#include <string>
#include <chrono> // the timer for an event

namespace sdds {

	// maximum number of record objects at 7
	const int MAX_RECORDS_LEN = 7;

	// statically allocated array of record objects
	class TimedEvents {

		int Record_Nums; // the number of records currently stored
		std::chrono::steady_clock::time_point start_time; // a modifier that starts the timer for an event
		std::chrono::steady_clock::time_point end_time; // a modifier that stops the timer for an event

		// an array of records of anonymous structure type (the structure has no name)
		struct {
			std::string event_name{};
			std::string units{};
			std::chrono::steady_clock::duration duration{};
		} events[MAX_RECORDS_LEN];

	public:
		TimedEvents();		// Constructor

		void startClock();
		void stopClock();
		void recordEvent(const char*);

		// receives a reference to an `std::ostream` object and a `TimedEvents` object
		friend std::ostream& operator<<(std::ostream& out, const TimedEvents& events);
	};
}
#endif // SDDS_TIMEDEVENTS_H__