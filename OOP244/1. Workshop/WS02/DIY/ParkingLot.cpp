/***********************************************************************
// OOP244 Workshop 2: Dynamic Memory

// File	ParkingLot.cpp

	¢º Name: Youjin An
	¢º Part: DIY (DO IT YOURSELF)
	¢º Date: 2019/09/24

	¢º 'ParkingLot' module:
		Create a structure called ParkingLot with two member variables:
		1. An integer holding the number of ParkingSpots in the ParkingLot.
		2. A ParkingSpot pointer to dynamically hold an array of ParkingSpots

***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

#include "ParkingLot.h"
#include "utils.h"

namespace sdds {

	void setEmpty(ParkingLot& PL) {
		PL.PL_NumOfSpots = 0;
		PL.PL_ArrOfPS = nullptr;
	}

	bool isEmpty(const ParkingLot& PL) {
		bool check = false;
		if (PL.PL_ArrOfPS == nullptr) {
			check = true;
			return check;
		}
		return check;
	}


	void openParking(ParkingLot& PL, int noOfSpots) {
		PL.PL_ArrOfPS = new ParkingSpot[noOfSpots];
		PL.PL_NumOfSpots = noOfSpots;

		for (int i = 0; i < PL.PL_NumOfSpots; i++) {
			setEmpty(PL.PL_ArrOfPS[i]);
		}
	}

	int parkCar(ParkingLot& PL) {
		for (int i = 0; i < PL.PL_NumOfSpots; i++) {
			if (isEmpty(PL.PL_ArrOfPS[i]) == true) {
				parkCar(PL.PL_ArrOfPS[i]);
				return i;
			}
		}
		return -1;
	}

	bool returnCar(ParkingLot& PL, int spotNo) {

		if ((PL.PL_NumOfSpots >= 0 && spotNo <= PL.PL_NumOfSpots) && isEmpty(PL.PL_ArrOfPS[spotNo]) == false) {
			cout << "Returning ";
			print(PL.PL_ArrOfPS[spotNo]);
			freeSpot(PL.PL_ArrOfPS[spotNo]);
			return true;
		}
		return false;
	}

	void closeParking(ParkingLot& PL) {
		for (int i = 0; i < PL.PL_NumOfSpots; i++) {
			if (!isEmpty(PL.PL_ArrOfPS[i])) {
				returnCar(PL, i);
			}
		}

		delete[] PL.PL_ArrOfPS;
		isEmpty(PL);
	}
}