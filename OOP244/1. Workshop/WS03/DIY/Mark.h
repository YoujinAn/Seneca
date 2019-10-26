/***********************************************************************
// OOP244 Workshop 3: Member functions and privacy
// File Mark.h

	¢º Name: Youjin An
	¢º Part: DIY
	¢º Date: 2019/09/28

***********************************************************************/

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_

#include <iostream>

namespace sdds {

	const int DSP_RAW = 1;
	const int DSP_PERCENT = 2;
	const int DSP_ASIS = 3;
	const int DSP_UNDEFINED = -1;

	const int DSP_GPA = 4;
	const int DSP_LETTER = 5;

	class Mark {
	private:
		int m_displayMode;
		double m_mark;
		int m_outOf;

		char m_name[51]; // the name or the title of the mark.

		void flushKeyboard()const;
		void prnLetter()const;

	public:
		void set(int diaplayMode);
		void set(double mark, int m_outOf = 1);
		void setEmpty();
		bool isEmpty()const;
		int percent()const;
		double rawValue()const;
		bool read(const char* prompt);
		std::ostream& display(int width = 55)const;

		void set(const char* name);
		void set(const char* name, double rawMark, int outof = 1);
		bool readName(const char* prompt, int maxLen = 50);
		void changeOutOf(int value);
		double GPA()const;
		double letterBasedGPA()const;
	};
}
#endif // SDDS_MARK_H_
