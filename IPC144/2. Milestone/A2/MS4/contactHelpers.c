/***********************************************************************
// IPC144 Milestone 4 Contacts
// File contactHelpers.c

	▶ Name: Youjin An
	▶ Date: 26 July.2019
	▶ Part: Milestone 2.4

***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:

#include <string.h>

// -------------------------------
// Include your contactHelpers header file on the next line:

#include "contactHelpers.h"

// -------------------------------
// define MAXCONTACTS for sizing contacts array (5):

#define MAXCONTACTS 5

//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard:
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void) {
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt:
int getInt(void) {
	int Value;
	char NL = 'x';
	scanf("%d%c", &Value, &NL);

	while (NL != '\n')
	{
		clearKeyboard();
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		scanf("%d%c", &Value, &NL);
	}

	return Value;
}

// getIntInRange:
int getIntInRange(int min, int max) {
	int Value;
	Value = getInt();

	while (Value < min || Value > max) {
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		Value = getInt();
	}

	return Value;
}

// yes:
int yes(void) {
	char single_char;
	char NL = 'x';
	scanf(" %c%c", &single_char, &NL);

	while (((single_char != 'y') || (single_char != 'Y') || (single_char != 'n') || (single_char != 'N')) && (NL != '\n')) {
		if (NL != '\n') {
			clearKeyboard();
		}
		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		scanf(" %c%c", &single_char, &NL);
	}

	return (single_char == 'y' || single_char == 'Y');
}

// menu:
int menu(void) {
	int option = 0;

	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");

	printf("Select an option:> ");
	option = getIntInRange(0, 6);

	return option;
}

// contactManagerSystem:
void contactManagerSystem(void) {

	struct Contact basic_contact[MAXCONTACTS] = {
		{ { "Rick",{ '\0' }, "Grimes" }, { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
		{ "4161112222", "4162223333", "4163334444" } },
		{ { "Maggie", "R.", "Greene" }, { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
		{ "9051112222", "9052223333", "9053334444" } },
		{ { "Morgan", "A.", "Jones" }, 	{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
		{ "7051112222", "7052223333", "7053334444" } },
		{ { "Sasha",{ '\0' }, "Williams" }, { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
		{ "9052223333", "9052223333", "9054445555" } },
	};

	int option, ask, flag = 0;

	while (flag == 0) {
		option = menu();
		printf("\n");

		switch (option)
		{
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			ask = yes();
			printf("\n");

			if (ask == 1) {
				printf("Contact Management System: terminated\n");
				flag = 1;
			}

			break;

		case 1:
			displayContacts(basic_contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 2:
			addContact(basic_contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 3:
			updateContact(basic_contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 4:
			deleteContact(basic_contact, MAXCONTACTS);
			printf("\n");
			pause();
			printf("\n");
			break;

		case 5:
			searchContacts(basic_contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 6:
			sortContacts(basic_contact, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		}
	}
}

// getStreetNumber
int getStreetNumber(void) {
	int Value;
	Value = getInt();

	while (Value < 0) {
		printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
		Value = getInt();
	}

	return Value;
}

// getApartmentNumber
int getApartmentNumber(void) {
	int Value;
	Value = getInt();

	while (Value < 0) {
		printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
		Value = getInt();
	}

	return Value;
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

void getTenDigitPhone(char phoneNum[])
{
	int i, needInput = 1;
	int len;

	while (needInput == 1) {
		scanf("%10s", phoneNum);
		clearKeyboard();

		len = strlen(phoneNum);

		// (String Length Function: validate entry of 10 characters)
		if (len == 10) {
			needInput = 0;
			// Modify this function to ensure all values entered are numerical digits
			for (i = 0; i < len; i++) {
				if ('9' < phoneNum[i] || phoneNum[i] < '0') { // ASCII 
					printf("Enter a 10-digit phone number: ");
					needInput = 1;
					break;
				}
			}
		}
		else
			printf("Enter a 10-digit phone number: ");
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i;
	for (i = 0; i < size; i++) {
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0) {
			return i;
		}
	}

	return -1;
}

// displayContactHeader
void displayContactHeader(void) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int count) {
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", count);
}

// displayContact:
void displayContact(const struct Contact* contact) {
	// contact full name
	printf(" %s", contact->name.firstName);
	if (strlen(contact->name.middleInitial) != 0) {
		printf(" %s", contact->name.middleInitial);
	}
	printf(" %s\n", contact->name.lastName);

	// contact numbers
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);

	//contact adress
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
	if (contact->address.apartmentNumber > 0) {
		printf("Apt# %d, ", contact->address.apartmentNumber);
	}

	printf("%s, %s\n", contact->address.city, contact->address.postalCode); // city and postal code
}

// displayContacts:
void displayContacts(const struct Contact contacts[], int size) {
	int i, count = 0;

	displayContactHeader(); // start

	for (i = 0; i < size; i++) {
		if (strlen(contacts[i].numbers.cell) != 0) {
			displayContact(&contacts[i]);
			count++;
		}
	}

	displayContactFooter(count); // end
}

// searchContacts:
void searchContacts(const struct Contact contacts[], int size) {

	char cell_number[11];
	int find_contact_index;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cell_number);
	// Search the contact array to find a contact with the cell phone number previously entered
	find_contact_index = findContactIndex(contacts, size, cell_number);

	if (find_contact_index == -1) {
		printf("*** Contact NOT FOUND ***\n");
		printf("\n");
	}
	// If the contact is found, display the details
	else {
		printf("\n");
		displayContact(&contacts[find_contact_index]);
		printf("\n");
	}
}

// addContact:
void addContact(struct Contact contacts[], int size) {
	int i;

	for (i = 0; i < size; i++) {
		if (strlen(contacts[i].numbers.cell) == 0) {
			break;
		}
	}

	// If there are no available slots, the contact listing is full
	if (i == size) {
		printf("*** ERROR: The contact list is full! ***\n");
		printf("\n");
	}
	else {
		getContact(&contacts[i]);
		// After adding the new contact, display the following message
		printf("--- New contact added! ---\n");
		printf("\n");
	}
}

// updateContact:
void updateContact(struct Contact contacts[], int size) {

	char cell_number[11];
	int find_contact_index, option;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cell_number);
	// Search the contact array to find a contact with the cell phone number previously entered
	find_contact_index = findContactIndex(contacts, size, cell_number);

	// If the contact could NOT be located, display the following message
	if (find_contact_index == -1) {
		printf("*** Contact NOT FOUND ***\n\n");
	}
	else {
		printf("\nContact found:\n");

		// Then display the details for the contact.
		displayContact(&contacts[find_contact_index]);
		printf("\n");

		printf("Do you want to update the name? (y or n): ");
		option = yes();
		if (option == 1) {
			getName(&contacts[find_contact_index].name);
		}

		printf("Do you want to update the address? (y or n): ");
		option = yes();
		if (option == 1) {
			getAddress(&contacts[find_contact_index].address);
		}

		printf("Do you want to update the numbers? (y or n): ");
		option = yes();
		if (option == 1) {
			getNumbers(&contacts[find_contact_index].numbers);
		}

		printf("--- Contact Updated! ---\n\n");
	}
}

// deleteContact:
void deleteContact(struct Contact contacts[], int size) {
	char cell_number[11];
	int find_contact_index, option;

	printf("Enter the cell number for the contact: ");
	getTenDigitPhone(cell_number);
	find_contact_index = findContactIndex(contacts, size, cell_number);

	if (find_contact_index == -1) {
		printf("*** Contact NOT FOUND ***\n");
	}

	else {
		printf("\nContact found:\n");
		displayContact(&contacts[find_contact_index]);
		printf("\n");

		printf("CONFIRM: Delete this contact? (y or n): ");
		option = yes();

		if (option == 1) {
			contacts[find_contact_index].numbers.business[0] = '\0';
			contacts[find_contact_index].numbers.cell[0] = '\0';
			contacts[find_contact_index].numbers.home[0] = '\0';
			printf("--- Contact deleted! ---\n");
		}
	}
}

// sortContacts:
void sortContacts(struct Contact contacts[], int size) {
	int i, j;
	struct Contact temp;

	for (i = 0; i < size - 1; i++) {
		for (j = i + 1; j < size; j++) {
			if (strlen(contacts[i].numbers.cell) != 0 && strlen(contacts[j].numbers.cell) != 0) {
				if (strcmp(contacts[i].numbers.cell, contacts[j].numbers.cell) > 0) {
					temp = contacts[i];
					contacts[i] = contacts[j];
					contacts[j] = temp;
				}
			}
		}
	}

	printf("--- Contacts sorted! ---\n");
	printf("\n");
}