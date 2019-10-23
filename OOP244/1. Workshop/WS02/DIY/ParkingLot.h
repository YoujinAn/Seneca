/***********************************************************************
// OOP244 Workshop 2: Dynamic Memory

// File	ParkingLot.h

	¢º Name: Youjin An
	¢º Part: DIY (DO IT YOURSELF)
	¢º Date: 2019/09/24

***********************************************************************/

#ifndef SDDS_PARKINGLOT_H_
#define SDDS_PARKINGLOT_H_

#include "ParkingSpot.h"

namespace sdds {

	struct ParkingLot {

		int PL_NumOfSpots; // holding the number of ParkingSpots
		ParkingSpot* PL_ArrOfPS; // hold an array of ParkingSpots
	};

	void setEmpty(ParkingLot&);
	bool isEmpty(const ParkingLot&);
	void openParking(ParkingLot&, int noOfSpots);
	int parkCar(ParkingLot&);
	bool returnCar(ParkingLot&, int spotNo);
	void closeParking(ParkingLot&);

}
#endif // SDDS_PARKINGLOT_H_
