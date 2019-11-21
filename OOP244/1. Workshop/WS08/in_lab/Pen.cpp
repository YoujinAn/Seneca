/***********************************************************************
// OOP244 Workshop 8: Virtual Functions
//
// File Pen.cpp

	¢º Name: Youjin An
	¢º Email : yan24@myseneca.ca
	¢º Part: in_lab
	¢º Date: 21 Nov 2019

***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include "Pen.h"

namespace sdds {

	Pen::Pen() {
		style = nullptr;
		ink = 0;
	}

	Pen::Pen(const char* style_pen, int ink_pen) {
		// style
		if (style_pen == nullptr || strlen(style_pen) == 0) {
			style = nullptr;
			ink = 0;
		}
		else {
			style = new char[strlen(style_pen) + 1];
			strncpy(style, style_pen, strlen(style_pen) + 1);
			style[strlen(style_pen)] = '\0';
		}

		// ink
		if (ink_pen < 1 || ink_pen > 50) {
			ink = INK_MAX;
		}
		else {
			ink = ink_pen;
		}
	}

	Pen::~Pen() {
		delete[] style;
	}

	void Pen::write(const char* text) {

		if (ink == 0) {
			cout << "We can't write without ink!" << endl;
		}
		else if (ink > 0) {
			cout << "Writing out the following: " << text << " with a Pen!" << endl;

			int non_spaces = 0;
			for (int i = 0; i < strlen(text); i++) {
				if (text[i] != ' ') {
					non_spaces++;
				}
			}
			// Reduce the amount of ink  by the number of non-spaces found in the text times 2
			ink -= (non_spaces * 2);

			// less than zero set it to zero instead
			if (ink < 0) {
				ink = 0;
			}
		}
	}

	void Pen::refill(int ink_pen) {
		ink += ink_pen;
		if (ink > INK_MAX) {
			ink = INK_MAX;
		}
		cout << "Refilling the pen with ink" << endl;
	}

	bool Pen::filled() const {
		return ink > 0;
	}

	ostream& Pen::display(ostream& os) const {
		if (style == nullptr) {
			os << "This is an empty Pen" << endl;
		}
		else {
			os << "Pen Details" << endl;
			os << "Style: " << style << endl;
			os << "Ink Remaining: " << ink << endl;
		}
		return os;
	}

} // sdds