/***********************************************************************
// OOP244 Workshop 1 DIY: Compiling modular source code
// File File.cpp

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
#include "File.h"

using namespace std;

namespace sdds {

	bool readContact(Contact* C, FILE* fptr) {
		return fscanf(fptr, "%[^,],%lld", C->name, &C->phoneNumber) == 2;
	}

	void writeContact(FILE* fptr, const Contact* C) {
		fprintf(fptr, "%s,%lld", C->name, C->phoneNumber);
	}

	int readContacts(Contact* contacts, const char* filename) {
		FILE* fptr = fopen(filename, "r");
		Contact C;
		int num;
		for (num = 0; fptr && num < MAX_REC_NO && readContact(&C, fptr); num++) {
			contacts[num] = C;
		}
		return num;
	}

	void writeContacts(Contact* contacts, int cntno, const char* filename) {
		FILE* fptr = fopen(filename, "w");
		int num;
		for (num = 0; num < cntno; num++) {
			writeContact(fptr, &contacts[num]);
		}
		fclose(fptr);
	}

}