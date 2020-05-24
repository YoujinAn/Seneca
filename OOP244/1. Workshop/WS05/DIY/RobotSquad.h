/***********************************************************************
// OOP244 Workshop 5: Member Operator Overloads IN LAB
//
// File RobotSquad.h

	¢º Name: Youjin An
	¢º Part: DIY
	¢º Date: 2019/10/15

***********************************************************************/

#ifndef SDDS_ROBOTSQUAD_H
#define SDDS_ROBOTSQUAD_H

#include <iostream>
using namespace std;

#include "Robot.h"

namespace sdds {

	const int MIN_NAME = 10;

	class RobotSquad {
		private:
			char* name;
			Robot* robots;
			int coutOfRobots;

		public:

			RobotSquad(const char* r_name = "No Name");
			~RobotSquad();
			
			const char* getName() const;
			int getCount()const;
			Robot* getRoster() const;

			ostream& display() const;

			RobotSquad& operator +=(Robot&);
			RobotSquad& operator --();
	};
}

#endif // SDDS_ROBOTSQUAD_H
