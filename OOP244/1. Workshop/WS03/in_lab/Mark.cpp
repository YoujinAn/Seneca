/***********************************************************************
// OOP244 Workshop 3: Member functions and privacy
// File Mark.cpp

	¢º Name: Youjin An
	¢º Part: in_lab
	¢º Date: 2019/09/26

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
	}

	bool Mark::isEmpty()const {
		if (m_displayMode == DSP_UNDEFINED && m_mark == -1 && m_outOf == 100) {
			return true;
		}
		return false;
	}

	int Mark::percent()const {
		double result;
		result = (m_mark / m_outOf) * 100 + 0.5;
		return (int) result;
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

	std::ostream& Mark::display() const {
		if (isEmpty()) {
			cout << "Empty Mark object!";
		}
		else {
			if (m_displayMode == DSP_RAW) {
				cout << rawValue();
			}
			else if (m_displayMode == DSP_PERCENT) {
				cout << "%" << percent();
			}
			else if (m_displayMode == DSP_ASIS) {
				cout << m_mark << "/" << m_outOf;
			}
			else if (m_displayMode == DSP_UNDEFINED) {
				cout << "Display mode not set!";
			}
			else
				cout << "Invalid Mark Display setting!";
		} // else if
		return cout;
	}
}