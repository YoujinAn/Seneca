/***********************************************************************
// OOP244 Workshop 5: Member Operator Overloads IN LAB
//
// File Robot.h

	¢º Name: Youjin An
	¢º Email : auj0827@gmail.com
	¢º Part: in_lab
	¢º Date: 2019/10/10

***********************************************************************/

#ifndef SDDS_ROBOT_H
#define SDDS_ROBOT_H

#include <iostream>
using namespace std;

#include "Parts.h"

namespace sdds {

	const int NICK_MAX_LEN = 10;

	class Robot {
		private:
			char nickname[NICK_MAX_LEN + 1];	// the nickname of the Robot
			int durability;
			Arms arms;

		public:
			Robot();		// Default constructor
			Robot(const char* R_nickname, int R_arms_force, int R_durability);

			ostream& display() const;

			// Operator Overload Members
			operator bool() const;

	}; // class Robot
}

#endif // SDDS_ROBOT_H