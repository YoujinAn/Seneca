/***********************************************************************
// OOP244 Workshop 4: Constructors, Destructors, Current Object AT HOME
// Bouquet.cpp

	¢º Name: Youjin An
	¢º Part: at_home
	¢º Date: 2019/10/05

***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <iomanip>

#include "Bouquet.h"
#include "utils.h"

using namespace std;

namespace sdds {

	void Bouquet::flushKeyboard() const {
		char ch;
		do {
			ch = cin.get();
		} while (ch != '\n');
	}

	Bouquet::Bouquet() {
		setEmpty();
	}

	Bouquet::Bouquet(const Flower* bflower, int bflowerCount, const char* bmessage) {

		double price = 0.0;

		if (bflower == nullptr) {
			setEmpty();
		}
		else {
			if (bflowerCount <= MAX_FLOWERS)
				b_flowerCount = bflowerCount;
			else
				b_flowerCount = MAX_FLOWERS;

			b_flowers = new Flower[b_flowerCount];

			for (int i = 0; i < b_flowerCount; i++) {
				b_flowers[i].setName(bflower[i].name(), strlen(bflower[i].name()));
				b_flowers[i].setColour(bflower[i].colour(), strlen(bflower[i].colour()));
				b_flowers[i].setPrice(bflower[i].price());
				price += b_flowers[i].price();
			}

			// Tally the price of all the Flowers into a sum and store that sum in b_price for the price of the Bouquet.
			b_price = price;
			copystr(b_message, bmessage, strlen(bmessage));
			/*
				b_message = new char[strlen(message) + 1];
				strcpy(b_message, message);
			*/

		}
	}

	Bouquet::~Bouquet() {

		if (isEmpty()) {
			cout << "An unknown bouquet has departed..." << endl;
		}
		else {
			cout << "A bouquet has departed with the following flowers..." << endl;
		}

		delete[] b_message;
		delete[] b_flowers;
	}

	const char* Bouquet::message() const {
		return b_message;
	}

	double Bouquet::price() const {
		return b_price;

	}

	bool Bouquet::isEmpty()const {
		if (b_price == 0 && b_message == nullptr && b_flowers == nullptr && b_flowerCount == 0) {
			return true;
		}
		return false;
	}

	void Bouquet::setEmpty() {
		b_price = 0.0;
		b_message = nullptr;
		b_flowers = nullptr;
		b_flowerCount = 0;
	}

	void Bouquet::setMessage(const char* prompt) {
		cout << prompt;
		char message[31] = "";
		read(message, 30, "A bouquets's message (non-empty) is limited to 30 characters... Try again: ");
		copystr(b_message, message, strlen(message));
	}

	void Bouquet::discardBouquet() {
		cout << "Discarding the current bouquet..." << endl;
		delete[] b_message;
		delete[] b_flowers;
		setEmpty();
	}

	void Bouquet::arrangeBouquet() {
		bool Input = false;
		char YorN = 'Y';
		
		cout << "Arranging a new bouquet..." << endl;

		if (!isEmpty()) {

			cout << "This bouquet has an arrangement currently, discard it? (Y/N): ";

			do {
				YorN = cin.get();
				if (YorN == 'Y' || YorN == 'N')
				{
					Input = true;
					flushKeyboard();
				}

			} while (!Input && cout << "The decision is either Y or N... Try again : ");

			if (YorN == 'Y') {
				discardBouquet();

			}
			else if (YorN == 'N') {
				cout << "No new arrangement performed..." << endl;
			}
		}

		if (isEmpty() || YorN == 'Y')
		{
			int Option = 0;
			bool check = false;

			cout << "Enter the number of flowers in this bouquet (Valid: 1-3)... : ";

			do {
				cin >> Option;
				if (Option == 1 || Option == 2 || Option == 3)
				{
					check = true;

				}
			} while (!check && cout << "The valid range is 1-3... Try again: ");

			b_flowerCount = Option;
			b_flowers = new Flower[b_flowerCount];

			for (int i = 0; i < b_flowerCount; i++) {
				flushKeyboard();
				b_flowers[i].setFlower();
				b_price += b_flowers[i].price();

			}

			flushKeyboard();
			cout << "A bouquet has been arranged..." << endl;
			setMessage("Enter a message to send with the bouquet...: ");
		}

	}

	ostream& Bouquet::display() const {

		if (isEmpty()) {
			cout << "This is an empty bouquet..." << endl;
		}

		else {
			cout << "This bouquet worth " << fixed << setprecision(2) << b_price << " has the following flowers..." << endl;
			for (int i = 0; i < b_flowerCount; i++) {
				b_flowers[i].display();
			}
			cout << "with a message of: " << b_message << endl;
		}

		return cout;
	}
}