/***********************************************************************
// IPC144 Milestone 3 Contacts
// File contacts.h

	▶ Name: Youjin An
	▶ Email: auj0827@gmail.com
	▶ Date: 12 July.2019
	▶ Part: Milestone 1.3
	
***********************************************************************/

// Structure type Name declaration
struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration
// Place your code from Milestone #2 here...

struct Address {
	unsigned int streetNumber;
	char street[41];
	unsigned int spartmentNumber;
	char postalCode[8];
	char city[41];
};

// Structure type Numbers declaration
// Place your code from Milestone #2 here...

struct Numbers {
	char cell[11];
	char home[11];
	char business[11];
};

// Structure type Contact declaration
// Place your code here...

struct Contact { // user-defined types
	struct Name name; 
	struct Address address;
	struct Numbers numbers;
};