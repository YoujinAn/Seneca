/***********************************************************************
// OOP244 Workshop 5: Member Operator Overloads IN LAB
//
// File Robot.h

	¢º Name: Youjin An
	¢º Email : auj0827@gmail.com
	¢º Part: DIY
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
			Legs legs;

		public:
			Robot();		// Default constructor
			Robot(const char* R_nickname, int R_arms_force, int R_Leg_speed, int R_durability);

			ostream& display() const;

			// Operator Overload Members
			operator bool() const;
			Robot& operator-=(int);

			Arms getArms() const;
			Legs getLegs() const;
	}; // class Robot

	// Global Helper Function (Robot) 
	void box(Robot&, Robot&);
}

#endif // SDDS_ROBOT_H