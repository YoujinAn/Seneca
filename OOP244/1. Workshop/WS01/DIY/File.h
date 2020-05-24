/***********************************************************************
// OOP244 Workshop 1 DIY: Compiling modular source code
// File File.h

	¢º Name: Youjin An
	¢º Email : yan24@myseneca.ca
	¢º Part: DIY (DO IT YOURSELF)
	¢º Date: 2019/09/15

***********************************************************************/


#ifndef SDDS_FILE_H
#define SDDS_FILE_H

namespace sdds {

	#define MAX_REC_NO 100

	bool readContact(Contact* C, FILE* fptr);
	void writeContact(FILE* fptr, const Contact* C);
	int readContacts(Contact* contacts, const char* filename);
	void writeContacts(Contact* contacts, int cntno, const char* filename);

}

#endif
