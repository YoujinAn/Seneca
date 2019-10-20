/* -------------------------------
Name: Youjin An
Student number: 140413188
Email: yan24@myseneca.ca
Section: SII
Date: July 26, 2019
----------------------------------
Assignment: 2
Milestone:  4
---------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+

#include "contacts.h"
#include "contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

void String_input(char* arr, int size)
{
	char c;
	int cnt = 0;

	do {
		c = getchar();
		if (c != '\n')
		{
			arr[cnt] = c;
			cnt++;
		}
	} while (c != '\n' && cnt < size-1);

	if (c != '\n')
		clearKeyboard();

	arr[cnt + 1] = '\0';
}

// getName:
void getName(struct Name *name) {

	int option = 0;

	printf("Please enter the contact's first name: ");
	scanf(" %30[^\n]", name->firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	option = yes();
	if (option == 1) {
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]", name->middleInitial);
		clearKeyboard();
		//String_input(name->middleInitial, sizeof(name->middleInitial));
		//fgets(name->middleInitial, sizeof(name->middleInitial), stdin);
	}

	printf("Please enter the contact's last name: ");
	scanf(" %35[^\n]", name->lastName);
}

// getAddress:
void getAddress(struct Address *address) {

	int option = 0;

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

	int option = 0;

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

