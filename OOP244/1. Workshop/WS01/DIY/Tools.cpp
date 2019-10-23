/***********************************************************************
// OOP244 Workshop 1 DIY: Compiling modular source code
// File Tools.cpp

	¢º Name: Youjin An
	¢º Email : yan24@myseneca.ca
	¢º Part: DIY (DO IT YOURSELF)
	¢º Date: 2019/09/15

***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>

#include "Contact.h"
#include "Tools.h"

using namespace std;

namespace sdds {

	bool valid(long long min, long long max, long long val) {
		return min <= val && val <= max;
	}

	long long getLongLong(long long min, long long max, const char* valueName) {
		long long val;
		bool done = false;
		while (!done) {
			cin >> val;
			if (cin.fail()) {
				cin.clear();
				cout << "Bad Number, try again: ";
			}
			else {
				if (!valid(min, max, val)) {
					cout << "Invalid " << valueName << "!" << endl
						<< "The " << valueName << " must be between " << min << " and " << max << ": ";
				}
				else {
					done = true;
				}
			}
			cin.ignore(1000, '\n');
		}
		return val;
	}

	void toLowerCase(char* lowerCase, const char* str) {
		int i;
		for (i = 0; str[i] && i < 30; i++) {
			lowerCase[i] = str[i] | 0x20;
		}
		lowerCase[i] = 0;
	}

	bool yes() {
		char ch;
		ch = cin.get();
		cin.ignore(1000, '\n');
		return ch == 'y' || ch == 'Y';
	}

}