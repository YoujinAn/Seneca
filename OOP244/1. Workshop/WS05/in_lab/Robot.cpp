/***********************************************************************
// OOP244 Workshop 5: Member Operator Overloads IN LAB
//
// File Robot.cpp

	¢º Name: Youjin An
	¢º Email : auj0827@gmail.com
	¢º Part: in_lab
	¢º Date: 2019/10/10

***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include "Robot.h"

namespace sdds {
	// Default constructor
	Robot::Robot() {
		nickname[0] = '\0';
		durability = 0;
		arms = 0;
	}

	Robot::Robot(const char* R_nickname, int R_arms_force, int R_durability) {
		if (R_nickname == nullptr || nickname[0] == '\0') {
			Robot();	// setting to safe empty space
		}
		else {
			// R_nickname
			if (strlen(R_nickname) > NICK_MAX_LEN) {
				strcpy(nickname, R_nickname);
				nickname[NICK_MAX_LEN] = '\0';
			}
			else {
				strcpy(nickname, R_nickname);
			}

			// R_durability
			if (R_durability < 1) {
				durability = 100;
			}
			else durability = R_durability;

			// force
			arms = R_arms_force;
		}
	}

	ostream& Robot::display() const {
		if (nickname[0] != '\0' && durability != 0) {
			cout << "***Robot Summary***" << endl;
			cout << "Nickname: " << nickname << endl;
			cout << "Arm Power: " << arms.getForce() << endl;
			cout << "Durability: " << durability << endl;
		}
		else
			cout << "This Robot isn't operational" << endl;

		return cout;
	}

	// Operator Overload Members
	Robot::operator bool() const {
		return (durability == 0 || nickname == nullptr);
	}

}