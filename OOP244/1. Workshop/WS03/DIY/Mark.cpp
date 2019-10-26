/***********************************************************************
// OOP244 Workshop 3: Member functions and privacy
// File Mark.cpp

	¢º Name: Youjin An
	¢º Part: DIY
	¢º Date: 2019/09/28

	¢º 'Mark' module:
		The Mark class can hold a mark value and an ¡°out of¡± value and then
		display the mark in following formats: As is, Raw and Percentage

***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

#include "Mark.h"

namespace sdds {

	void Mark::flushKeyboard()const {
		char get_char = '\0';
		while (get_char != '\n') {
			get_char = cin.get();
		} // while
	}

	void Mark::set(int diaplayMode) {
		m_displayMode = diaplayMode;
	}

	void Mark::set(double mark, int outOf) {
		m_mark = mark;
		m_outOf = outOf;
	}

	void Mark::setEmpty() {
		m_displayMode = DSP_UNDEFINED;
		m_mark = -1;
		m_outOf = 100;
		m_name[0] = '\0';
	}

	bool Mark::isEmpty()const {
		/*
		if (m_displayMode == DSP_UNDEFINED && m_mark == -1 && m_outof == 100) {
			return true;
		}
		*/
		if (m_mark == -1) {
			return true;
		}

		return false;
	}

	int Mark::percent()const {
		double result;
		result = (m_mark / m_outOf) * 100 + 0.5;
		return (int)result;
	}

	double Mark::rawValue()const {
		double cal;
		return cal = (m_mark / m_outOf);
	}

	bool Mark::read(const char* prompt) {

		bool check = true;

		cout << prompt;
		cin >> m_mark;
		cin.ignore();
		cin >> m_outOf;

		if (cin.fail()) {
			cin.clear();
			setEmpty();
			check = false;
		}

		flushKeyboard();

		return check;
	}

	std::ostream& Mark::display(int width) const {
		if (!(m_name[0] == '\0')) {
			cout.fill('.');
			cout.width(width);
			cout.setf(ios::left);
			cout << m_name;
		}

		if (isEmpty()) {
			cout << "Empty Mark object!";
		}
		else {
			if (m_displayMode == DSP_RAW) {
				cout.setf(ios::fixed);
				cout.precision(2);
				cout << rawValue();
			}
			else if (m_displayMode == DSP_PERCENT) {
				cout << "%" << percent();
			}
			else if (m_displayMode == DSP_ASIS) {
				cout.setf(ios::fixed);
				cout.precision(1);
				cout << m_mark << "/" << m_outOf;
			}
			else if (m_displayMode == DSP_UNDEFINED) {
				cout << "Display mode not set!";
			}
			else if (m_displayMode == DSP_LETTER) {
				prnLetter();
			}
			else if (m_displayMode == DSP_GPA) {
				cout.setf(ios::fixed);
				cout.precision(1); // ONE digits after the decimal point
				cout << GPA();
			}
			else
				cout << "Invalid Mark Display setting!";
		} // else if
		return cout;
	}

	/***********************************************************************
									in_home
	***********************************************************************/

	void Mark::prnLetter()const {
		int Per = percent();

		if (!isEmpty()) {
			if (0 <= Per && Per < 50) {
				cout << "F";
			}
			else if (50 <= Per && Per < 55) {
				cout << "D";
			}
			else if (55 <= Per && Per < 60) {
				cout << "D+";
			}
			else if (60 <= Per && Per < 65) {
				cout << "C";
			}
			else if (65 <= Per && Per < 70) {
				cout << "C+";
			}
			else if (70 <= Per && Per < 75) {
				cout << "B";
			}
			else if (75 <= Per && Per < 80) {
				cout << "B+";
			}
			else if (80 <= Per && Per < 90) {
				cout << "A";
			}
			else if (90 <= Per && Per <= 100) {
				cout << "A+";
			}
			else
				cout << "?";
		}
	}

	void Mark::set(const char* name) {
		strcpy(m_name, name);
	}

	void Mark::set(const char* name, double rawMark, int outof) {
		set(name);
		set(rawMark, outof);
	}

	bool Mark::readName(const char* prompt, int maxLen) {
		bool check = true;

		cout << prompt;
		cin.getline(m_name, maxLen + 1);

		if (cin.fail()) {
			cin.clear();
			flushKeyboard();
			m_name[0] = '\0';
			check = false;
		}

		return check;
	}

	void Mark::changeOutOf(int value) {
		double cal = m_mark * (double)value / m_outOf;

		m_outOf = value;

		if (cal < 1) {
			// If the value is less than 1, set the mark to a safe empty state.
			setEmpty();
		}
	}

	double Mark::GPA()const {
		double raw = rawValue();
		return raw * 4;
	}

	double Mark::letterBasedGPA()const {
		double GPA = percent();
		double re_GPA = 0.0;

		if (0 <= GPA && GPA < 50) {
			return re_GPA = 0.0;
		}
		else if (50 <= GPA && GPA < 55) {
			return re_GPA = 1.0;
		}
		else if (55 <= GPA && GPA < 60) {
			return re_GPA = 1.5;
		}
		else if (60 <= GPA && GPA < 65) {
			return re_GPA = 2.0;
		}
		else if (65 <= GPA && GPA < 70) {
			return re_GPA = 2.5;
		}
		else if (70 <= GPA && GPA < 75) {
			return re_GPA = 3.0;
		}
		else if (75 <= GPA && GPA < 80) {
			return re_GPA = 3.5;
		}
		else if (80 <= GPA && GPA < 90) {
			return re_GPA = 4.0;
		}
		else if (90 <= GPA && GPA <= 100) {
			return re_GPA = 4.0;
		}
		return re_GPA;
	}

}

