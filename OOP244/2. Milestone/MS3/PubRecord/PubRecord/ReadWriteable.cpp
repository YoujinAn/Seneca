/***********************************************************************
// OOP244 Project Milestone 3: THE PUBRECORD ABSRACT CLASS
//
// File ReadWriteable.cpp

	¢º Name: Youjin An
	¢º Email : yan24@myseneca.ca
	¢º Part: MS03
	¢º Date: 23 Nov 2019

***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#include "ReadWriteable.h"

namespace sdds {

	istream& operator>>(istream& is, ReadWriteable& readwriteable) {
		return readwriteable.read(is);
	}

	ostream& operator<<(ostream& os, const ReadWriteable& readwriteable) {
		return readwriteable.write(os);
	}
}