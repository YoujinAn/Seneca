/***********************************************************************
// OOP244 Workshop 1 DIY: Compiling modular source code
// File Contact.h

	¢º Name: Youjin An
	¢º Email : yan24@myseneca.ca
	¢º Part: DIY (DO IT YOURSELF)
	¢º Date: 2019/09/15

***********************************************************************/

#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H

namespace sdds {

	struct Contact {
		char name[31];
		long long phoneNumber;
	};

	void getName(char* name);
	long long getPhoneNumber();
	void getContact(Contact* C);
	void printContact(const Contact* C);
	void getStr(char* str, int len);
	void getName(char* name);
	int compare(const Contact* A, const Contact* B);
	void sort(Contact c[], int n);
	bool nameInContact(const Contact* C, const char* nameSubStr);
	int search(Contact* found, const Contact* C, const char* name, int noOfRecs);
	void printContacts(const Contact* C, int num);

}

#endif
