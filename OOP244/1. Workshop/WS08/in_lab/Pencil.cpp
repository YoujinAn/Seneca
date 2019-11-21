/***********************************************************************
// OOP244 Workshop 8: Virtual Functions
//
// File Pencil.cpp

	¢º Name: Youjin An
	¢º Email : yan24@myseneca.ca
	¢º Part: in_lab
	¢º Date: 21 Nov 2019

***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "Pencil.h"

namespace sdds {

	Pencil::Pencil() {
		HB_scale[0] = '\0';
		graphite = 0;
	}

	Pencil::Pencil(const char* HB_scale_pencil, int graphite_pencil) {

		// HB_scale
		int HB_len = strlen(HB_scale_pencil);
		if (HB_scale_pencil == nullptr || HB_len == 0) {
			HB_scale[0] = '\0';
			graphite = 0;
		}
		else {
			strncpy(HB_scale, HB_scale_pencil, HB_MAX + 1);
			HB_scale[HB_MAX] = '\0';
			graphite = graphite_pencil;
		}

		// graphite
		if (graphite_pencil < 0 || graphite_pencil > 100) {
			graphite = GRAPHITE_MAX; // 100
		}
		else {
			graphite = graphite_pencil;
		}
	}

	Pencil::~Pencil() {	}

	void Pencil::write(const char* text) {

		if (graphite == 0) {
			cout << "We can't write without graphite!" << endl;
		}
		else if (graphite > 0) {
			cout << "Writing out the following: " << text << " with a Pencil!" << endl;

			int spaces = 0;
			int text_len = strlen(text);
			for (int i = 0; i < text_len; i++) {
				if (text[i] == ' ') {
					spaces++;
				}
			}
			// Reduce the amount of graphite by the number of spaces found in the text times 5
			graphite -= (spaces * 5);

			// less than zero set it to zero instead
			if (graphite < 0) {
				graphite = 0;
			}
		}
	}

	void Pencil::refill(int refill_graphite) {
		graphite += refill_graphite;
		if (graphite > GRAPHITE_MAX) {
			graphite = GRAPHITE_MAX;
		}
		cout << "Refilling the pencil with graphite" << endl;
	}

	bool Pencil::filled() const {
		return graphite > 0;
	}

	ostream& Pencil::display(ostream& os) const {
		if (HB_scale[0] != '\0') {
			os << "Pencil Details" << endl;
			os << "HB Value: " << HB_scale << endl;
			os << "Graphite Remaining: " << graphite << endl;
		}
		else {
			os << "This is an empty Pencil" << endl;
		}
		return os;
	}

} // sdds
