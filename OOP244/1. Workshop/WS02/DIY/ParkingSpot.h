/***********************************************************************
// OOP244 Workshop 2: Dynamic Memory

// File	ParkingSpot.h

	¢º Name: Youjin An
	¢º Part: DIY (DO IT YOURSELF)
	¢º Date: 2019/09/24

***********************************************************************/

#ifndef SDDS_PARKINGSPORT_H_
#define SDDS_PARKINGSPORT_H_

namespace sdds {

	struct ParkingSpot {

		char PS_license [9]; // A C-style string to hold an 8 letter license plate of a car.
		char* PS_modelOfcar; // hold make and model of a car
	};

	void setEmpty(ParkingSpot&);
	bool isEmpty(const ParkingSpot&);
	void freeSpot(ParkingSpot&);
	void print(const ParkingSpot&);
	void parkCar(ParkingSpot&);
}

#endif // SDDS_PARKINGSPORT_H_
