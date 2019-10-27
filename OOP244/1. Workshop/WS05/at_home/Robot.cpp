/***********************************************************************
// OOP244 Workshop 5: Member Operator Overloads IN LAB
//
// File Robot.cpp

	¢º Name: Youjin An
	¢º Email : auj0827@gmail.com
	¢º Part: at_home
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

	Robot::Robot(const char* R_nickname, int R_arms_force, int R_Leg_speed, int R_durability) {
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

			// speed
			legs = R_Leg_speed;
		}
	}

	ostream& Robot::display() const {
		if (nickname[0] != '\0' && durability != 0) {
			cout << "***Robot Summary***" << endl;
			cout << "Nickname: " << nickname << endl;
			cout << "Arm Power: " << arms.getForce() << endl;
			cout << "Durability: " << durability << endl;
			cout << "Legs: " << legs.getSpeed() << endl;
		}
		else
			cout << "This Robot isn't operational" << endl;

		return cout;
	}

	// Operator Overload Members
	Robot::operator bool() const {
		return (durability == 0 || nickname == nullptr);
	}

	/***********************************************************************
							at_home part (Legs)
	***********************************************************************/

	Arms Robot::getArms() const {
		return arms;
	}

	Legs Robot::getLegs() const {
		return legs;
	}

	Robot& Robot::operator-=(int Passed_int) {
		durability -= Passed_int;
		if (durability < 1) {
			durability = 0;
		}
		return *this;
	}

	// Global Helper Function (Robot) 
	void box(Robot& r1, Robot& r2) {

		cout << "Attempting to begin a Robot boxing match" << endl;

		if (r1 || r2) {	//check empty state
			cout << "At least one of the Robots isn't operational. No bout will be had." << endl;
		}
		else {
			cout << "Both participants are operational... beginning the bout" << endl;

			while (!r1 && !r2) {	// begins the main combat loop
				//first faster
				if (r1.getLegs().getSpeed() > r2.getLegs().getSpeed()) {
					r2 -= r1.getArms().getForce();
					if (!r2) {
						r1 -= r2.getArms().getForce();
					}
				}
				// seconde faster
				else { 
					r1 -= r2.getArms().getForce();
					if (!r1) {
						r2 -= r1.getArms().getForce();
					}
				}
			}

			cout << "The bout has concluded... the winner is: " << endl;
			// Win r1
			if (!r1) {
				r1.display();
			}
			// Win r2
			else if (!r2) {
				r2.display();
			}
			else {
				cout << "No bout will begin" << endl;
			}
		}


	}
}