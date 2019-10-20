/***********************************************************************
// IPC144 Milestone 3 Contacts
// File contactHelpers.c

	▶ Name: Youjin An
	▶ Date: 26 July.2019
	▶ Part: Milestone 2.3

***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:

#include <string.h>

// Include your contactHelpers header file on the next line:

#include "contactHelpers.h"

//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
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
	int option, ask, flag = 0;

	while (flag == 0) {
		option = menu();
		printf("\n");

		switch (option)
		{
		case 0:
			printf("Exit the program? (Y)es/(N)o: ");
			ask = yes();
			if (ask == 1) {
				printf("\nContact Management System: terminated");
				flag = 1;
			}
			printf("\n");

			break;

		case 1:
			printf("<<< Feature 1 is unavailable >>>");
			printf("\n\n");
			pause();
			printf("\n");
			break;

		case 2:
			printf("<<< Feature 2 is unavailable >>>");
			printf("\n\n");
			pause();
			printf("\n");
			break;

		case 3:
			printf("<<< Feature 3 is unavailable >>>");
			printf("\n\n");
			pause();
			printf("\n");
			break;

		case 4:
			printf("<<< Feature 4 is unavailable >>>");
			printf("\n\n");
			pause();
			printf("\n");
			break;

		case 5:
			printf("<<< Feature 5 is unavailable >>>");
			printf("\n\n");
			pause();
			printf("\n");
			break;

		case 6:
			printf("<<< Feature 6 is unavailable >>>");
			printf("\n\n");
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
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
    int needInput = 1;

    while (needInput == 1) {
        scanf("%10s", phoneNum);
        clearKeyboard();

        // (String Length Function: validate entry of 10 characters)
        if (strlen(phoneNum) == 10)
            needInput = 0;
        else
            printf("Enter a 10-digit phone number: ");
    }
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    return -1;
}


// displayContactHeader
// Put empty function definition below:



// displayContactFooter
// Put empty function definition below:



// displayContact:
// Put empty function definition below:



// displayContacts:
// Put empty function definition below:



// searchContacts:
// Put empty function definition below:



// addContact:
// Put empty function definition below:



// updateContact:
// Put empty function definition below:



// deleteContact:
// Put empty function definition below:



// sortContacts:
// Put empty function definition below:
