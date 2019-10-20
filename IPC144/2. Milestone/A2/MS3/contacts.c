/***********************************************************************
// IPC144 Milestone 3 Contacts
// File contacts.c

	▶ Name: Youjin An
	▶ Date: 26 July.2019
	▶ Part: Milestone 2.3

***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+

#include "contacts.h"
#include "contactHelpers.h"


// +---------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2   |
// |        function definitions below...              |
// |                                                   |
// | *** See hint regarding the getNumbers function    |
// +---------------------------------------------------+


// getName:
void getName(struct Name *name) {

	char option = '\0'; // NULL

	printf("Please enter the contact's first name: ");
	scanf(" %[^\n]", name->firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	option = yes();
	if (option == 1) {
		printf("Please enter the contact's middle initial(s): ");
		fgets(name->middleInitial, sizeof(name->middleInitial), stdin);
		clearKeyboard();
	}

	printf("Please enter the contact's last name: ");
	scanf(" %[^\n]", name->lastName);
}

// getAddress:
void getAddress(struct Address *address) {

	char option = '\0'; // NULL

	printf("Please enter the contact's street number: ");
	address->streetNumber = getStreetNumber();

	printf("Please enter the contact's street name: ");
	scanf(" %[^\n]", address->street);

	printf("Do you want to enter an apartment number? (y or n): ");
	option = yes();
	if (option == 1)
	{
		printf("Please enter the contact's apartment number: ");
		address->apartmentNumber = getApartmentNumber();
	}

	printf("Please enter the contact's postal code: ");
	fgets(address->postalCode, sizeof(address->postalCode), stdin);
	clearKeyboard();

	printf("Please enter the contact's city: ");
	scanf(" %[^\n]", address->city);
}

// getNumbers:
// HINT:  Update this function to use the new helper 
//        function "getTenDigitPhone" where applicable
void getNumbers(struct Numbers *numbers) {

	char option = '\0'; // NULL

	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);

	printf("Do you want to enter a home phone number? (y or n): ");
	option = yes();
	if (option == 1)
	{
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	option = yes();
	if (option == 1)
	{
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
	}
};

// getContact
void getContact(struct Contact *contact) {
	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);
}
