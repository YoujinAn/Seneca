// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:25 Jan, 2020

#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include "TimedEvents.h"

namespace sdds {

	TimedEvents::TimedEvents() {
		Record_Nums = 0;
		startClock();
		stopClock();
	}

	void TimedEvents::startClock()
	{
		start_time = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock()
	{
		end_time = std::chrono::steady_clock::now();
	}

	void TimedEvents::recordEvent(const char* msg)
	{
		auto ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
		if (Record_Nums < MAX_RECORDS_LEN)
		{
			this->events[Record_Nums].event_name = msg;
			this->events[Record_Nums].units = "nanoseconds";
			this->events[Record_Nums].duration = ms;
			Record_Nums++;
		}
	}
	
	std::ostream& operator<<(std::ostream& out, const TimedEvents& events)
	{
		out << "--------------------------\n";
		out << "Execution Times:\n";
		out << "--------------------------\n";
		for (int i = 0; i < events.Record_Nums; i++)
			out << std::setw(20) << std::left
			<< events.events[i].event_name << ' ' << std::setw(12) << std::right
			<< events.events[i].duration.count() << ' '
			<< events.events[i].units << '\n';
		out << "--------------------------\n";
		return out;
	}
}