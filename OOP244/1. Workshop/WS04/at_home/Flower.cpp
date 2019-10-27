/***********************************************************************
// OOP244 Workshop 4: read functions for foolproof integer and C string
//                    data entry
// Flower.cpp

	¢º Name: Youjin An
	¢º Email : auj0827@gmail.com
	¢º Part: at_home
	¢º Date: 2019/10/05

***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "Flower.h"
#include "utils.h"

using namespace std;

namespace sdds {

	Flower::Flower() {
		setEmpty();
	}

	Flower::Flower(const char* fname, const char* fcolour, double fprice) {

		if ((fname != nullptr && fname[0] != '\0') && (fcolour != nullptr && fcolour[0] != '\0') && fprice > 0) {

			f_name = new char[strlen(fname) + 1];
			strcpy(f_name, fname);

			f_colour = new char[strlen(fcolour) + 1];
			strcpy(f_colour, fcolour);

			f_price = fprice;
		}
		else
			setEmpty();
	}

	Flower::~Flower() {
		if (isEmpty()) {
			cout << "An unknown flower has departed..." << endl;
		}
		else
			cout << colour() << " " << name() << " has departed..." << endl;

		delete[] f_name;
		delete[] f_colour;
	}

	const char* Flower::name() const {
		return f_name;
	}

	const char* Flower::colour() const {
		return f_colour;
	}

	double Flower::price() const {
		return f_price;
	}

	bool Flower::isEmpty()const {
		bool check = false;
		if (f_name == nullptr && f_colour == nullptr && f_price == 0.0) {
			check = true;
			return check;
		}
		else
			return check;
	}

	void Flower::setEmpty() {
		f_name = nullptr;
		f_colour = nullptr;
		f_price = 0.0;
	}

	void Flower::setName(const char* prompt) {
		char getName[NAME_MAX_LEN + 1] = "";

		cout << prompt;
		read(getName, NAME_MAX_LEN, "A flower's name is limited to 25 characters... Try again: ");

		f_name = new char[strlen(getName) + 1];
		strcpy(f_name, getName);
	}

	void Flower::setColour(const char* prompt) {
		char getColur[COL_MAX_LEN + 1] = "";

		cout << prompt;
		read(getColur, COL_MAX_LEN, "A flower's colour is limited to 15 characters... Try again: ");

		f_colour = new char[strlen(getColur) + 1];
		strcpy(f_colour, getColur);
	}

	void Flower::setPrice(const char* prompt) {
		cout << prompt;
		double price;
		do {
			cin >> price;
			if (price <= 0) {
				cout << "A flower's price is a non-negative number... Try again: ";
			}
		} while (price <= 0);
		f_price = price;
	}

	void Flower::setFlower() {
		cout << "Beginning the birth of a new flower..." << endl;

		setName("Enter the flower's name... : ");
		setColour("Enter the flower's colour... : ");
		setPrice("Enter the flower's price... : ");

		cout << "The flower's current details..." << endl;

		display();
	}

	std::ostream& Flower::display() const {
		if (isEmpty()) {
			cout << "This is an empty flower..." << endl;
		}
		else {
			cout << "Flower: " << f_colour << f_name << " Price: " << f_price << endl;
		}
		return cout;
	}

	void Flower::setName(const char* name, int len) {
		f_name = new char[len + 1];
		strcpy(f_name, name);
	}

	void Flower::setColour(const char* colour, int len) {
		f_colour = new char[len + 1];
		strcpy(f_colour, colour);
	}

	void Flower::setPrice(double price) {
		if (price < 0) {
			f_price = 1;
		}
		else
			f_price = price;
	}
}