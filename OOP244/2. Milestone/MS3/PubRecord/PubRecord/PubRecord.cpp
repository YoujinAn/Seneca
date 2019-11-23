/***********************************************************************
// OOP244 Project Milestone 3: THE PUBRECORD ABSRACT CLASS
//
// File PubRecord.cpp

	¢º Name: Youjin An
	¢º Email : yan24@myseneca.ca
	¢º Part: MS03
	¢º Date: 23 Nov 2019

***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#include <cstring>

#include "PubRecord.h"

namespace sdds {

	// Protected Functions
	const char* PubRecord::name()const {
		return pub_name;
	}

	void PubRecord::name(const char* p_name) {
		if (p_name == nullptr) {
			pub_name = nullptr;
		}
		else {
			pub_name = new char[strlen(p_name) + 1];
			strcpy(pub_name, p_name);
		}
	}

	// Public Functions
	PubRecord::PubRecord() {
		pub_name = nullptr;
		shelf_num = 0;
		typeOfmedia = 0;
	}

	PubRecord::~PubRecord() {
		delete[] pub_name;
	}

	// copy constructor
	PubRecord::PubRecord(const PubRecord& p_name) {
		name(p_name.pub_name);
		shelf_num = p_name.shelfNo();
		mediaType(p_name.mediaType());
	}

	PubRecord& PubRecord::operator=(const PubRecord& p_name) {
		name(p_name.pub_name);
		shelf_num = p_name.shelfNo();
		mediaType(p_name.mediaType());
		return *this;
	}

	// Shelf number
	void PubRecord::readShelfNo() {
		int num;
		bool valid = false;
		while (!valid) {
			cin >> num;
			if (num > 99 && num < 1000) {
				shelf_num = num;
				valid = true;
			}
			else {
				valid = false;
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Invalid Shelf Number, Enter again: ";
			}
		}
	}

	int PubRecord::shelfNo()const {
		return shelf_num;
	}

	// Media Type
	void PubRecord::mediaType(int p_typeOfmedia) {
		if (p_typeOfmedia == SDDS_CONSOLE) {
			typeOfmedia = SDDS_CONSOLE;
		}
		else if (p_typeOfmedia == SDDS_FILE) {
			typeOfmedia = SDDS_FILE;
		}
	}

	int PubRecord::mediaType()const {
		return typeOfmedia;
	}

	// Virtual Function
	char PubRecord::recID()const {
		return 'c';
	}

	// Overloaded Operators
	bool PubRecord::operator==(char rec_id)const {
		return recID() == rec_id;
	}
	bool PubRecord::operator==(const char* p_name)const {
		return strstr(pub_name, p_name) != nullptr;
	}
	PubRecord::operator bool()const {
		return pub_name != nullptr;
	}
}