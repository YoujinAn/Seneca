/***********************************************************************
// OOP244 Workshop 2: Dynamic Memory

// File	ParkingSpot.cpp

	¢º Name: Youjin An
	¢º Part: DIY (DO IT YOURSELF)
	¢º Date: 2019/09/24

	¢º 'ParkingSpot' module:
		Create a structure called ParkingSpot with two member variables:
		1. A C-style string to hold an 8 letter license plate of a car.
		2. A character pointer to dynamically hold make and model of a car.

***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

#include "ParkingSpot.h"
#include "utils.h"

namespace sdds {

	void setEmpty(ParkingSpot& PS) {
		PS.PS_license[0] = '\0';
		PS.PS_modelOfcar = nullptr;
	}

	bool isEmpty(const ParkingSpot& PS) {
		bool check = false;
		if (PS.PS_modelOfcar == nullptr) {
			check = true;
			return check;
		}
		return check;
	}

	void freeSpot(ParkingSpot& PS) {
		delete[] PS.PS_modelOfcar;
		setEmpty(PS);
	}

	void print(const ParkingSpot& PS) {
		cout << PS.PS_modelOfcar << ", plate number: " << PS.PS_license << endl;
	}

	void parkCar(ParkingSpot& PS) {
		char temp_PS_modelOfcar[61] = "";

		cout << "Make and Model: ";
		read(temp_PS_modelOfcar, 61, "Too long, Make and model must be shorter than 60 characters\nRedo Entry: ");

		PS.PS_modelOfcar = new char[ strlen(temp_PS_modelOfcar) + 1 ];
		strcpy(PS.PS_modelOfcar, temp_PS_modelOfcar);

		cout << "License Plate: ";
		read(PS.PS_license, 9, "Too long, License Plate must be shorter than 8 characters\nRedo Entry: ");
	}

}
