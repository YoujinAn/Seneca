/***********************************************************************
// OOP244 Workshop 1 DIY: Compiling modular source code
// File Contact.cpp

	¢º Name: Youjin An
	¢º Email : yan24@myseneca.ca
	¢º Part: DIY (DO IT YOURSELF)
	¢º Date: 2019/09/15

***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>

#include "Contact.h"
#include "Tools.h"

using namespace std;

namespace sdds {

	void getName(char* name) {
		getStr(name, 30);
	}
	
	long long getPhoneNumber() {
		return getLongLong(1000000000LL, 9999999999LL, "Phone Number");
	}

	void getContact(Contact* C) {
		cout << "Name: ";
		getName(C->name);
		cout << "Phone Number: ";
		C->phoneNumber = getPhoneNumber();
	}

	void printContact(const Contact* C) {
		cout << setw(35) << setfill('.') << setiosflags(ios::left) << C->name << C->phoneNumber << endl;
	}

	void getStr(char* str, int len) {
		cin.getline(str, len, '\n');
	}

	int compare(const Contact* A, const Contact* B) {
		return strcmp(A->name, B->name);
	}

	void sort(Contact c[], int n) {
		Contact temp;
		for (int i = n - 1; i > 0; i--) {
			for (int j = 0; j < i; j++) {
				if (compare(&c[j], &c[j + 1]) > 0) {
					temp = c[j];
					c[j] = c[j + 1];
					c[j + 1] = temp;
				}
			}
		}
	}

	bool nameInContact(const Contact* C, const char* nameSubStr) {
		char name[31];
		char subName[31];
		toLowerCase(name, C->name);
		toLowerCase(subName, nameSubStr);
		return strstr(name, subName) != nullptr;
	}

	int search(Contact* found, const Contact* C, const char* name, int noOfRecs) {
		int i;
		int noOfMatches = 0;
		for (i = 0; i < noOfRecs; i++) {
			if (nameInContact(&C[i], name)) {
				found[noOfMatches] = C[i];
				noOfMatches++;
			}
		}
		return noOfMatches;
	}

	void printContacts(const Contact* C, int num) {
		for (int i = 0; i < num; i++) {
			printContact(&C[i]);
		}
	}

}