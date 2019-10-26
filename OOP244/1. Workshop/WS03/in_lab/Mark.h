/***********************************************************************
// OOP244 Workshop 3: Member functions and privacy
// File Mark.h

	¢º Name: Youjin An
	¢º Part: in_lab
	¢º Date: 2019/09/26

***********************************************************************/

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_

#include <iostream>

namespace sdds {

	const int DSP_RAW = 1;
	const int DSP_PERCENT = 2;
	const int DSP_ASIS = 3;
	const int DSP_UNDEFINED = -1;

	class Mark {
	private:
		int m_displayMode;
		double m_mark;
		int m_outOf;

		void flushKeyboard()const;

	public:
		void set(int diaplayMode);
		void set(double mark, int m_outOf = 1);
		void setEmpty();
		bool isEmpty()const;
		int percent()const;
		double rawValue()const;
		bool read(const char* prompt);
		std::ostream& display() const;
	};
}

#endif // SDDS_MARK_H_
