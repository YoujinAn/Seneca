/***********************************************************************
// OOP244 Workshop 5: Member Operator Overloads IN LAB
//
// File RobotSquad.cpp

	¢º Name: Youjin An
	¢º Part: DIY
	¢º Date: 2019/10/15

***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "RobotSquad.h"

using namespace std;

namespace sdds {

	RobotSquad::RobotSquad(const char* r_name) {
		name = new char[MIN_NAME + 1];
		strcpy(name, r_name);
		name[MIN_NAME] = '\0';

		robots = nullptr;
		coutOfRobots = 0;
	}

	RobotSquad::~RobotSquad() {
		delete[] name;
		delete[] robots;
	}

	const char* RobotSquad::getName() const
	{
		return name;
	}

	int RobotSquad::getCount() const
	{
		return coutOfRobots;
	}

	Robot* RobotSquad::getRoster()const
	{
		return this->robots;
	}

	ostream& RobotSquad::display() const
	{
		if (coutOfRobots == 0)  // Empty Squad
		{
			cout << "Squad **" << name << "** has no members" << endl;
		}
		else
		{
			cout << "***Squad Summary***" << endl;
			cout << "Name: " << name << endl;
			cout << "Roster Count: " << coutOfRobots << endl;
			cout << "Roster:" << endl;
			for (int i = 0; i < coutOfRobots; i++) {
				robots[i].display();
			}
		}
		return cout;
	}

	RobotSquad& RobotSquad::operator +=(Robot& robot)
	{
		Robot* temp = new Robot[coutOfRobots + 1];

		for (int i = 0; i < coutOfRobots; i++) {
			temp[i] = robots[i];					// Copy current array to array temp
		}

		coutOfRobots++;
		delete[] robots;							// Delete current array
		robots = temp;								// Save the pointer to temp array to the current array pointer
		robots[coutOfRobots - 1] = robot;			// Add a new robot to the end of current array

		return *this;
	}

	RobotSquad& RobotSquad::operator--()
	{
		if (robots == nullptr) {
			cout << "This squad **" << name << "** has no members or is uninitialized. Can't do --." << endl;
		}
		else {
			if (coutOfRobots == 0) {
				robots = nullptr;  // set Roster to a safe empty state
			}
			else {
				Robot* temp = new Robot[coutOfRobots - 1];
				for (int i = 0; i < coutOfRobots - 1; i++)
				{
					temp[i] = robots[i];
				}
				delete[] robots;
				robots = temp;
				coutOfRobots--;
			}
		}
		return *this;
	}
}
