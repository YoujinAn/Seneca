/***********************************************************************
// OOP244 Workshop 5: Member Operator Overloads IN LAB
//
// File Parts.cpp

	¢º Name: Youjin An
	¢º Email : auj0827@gmail.com
	¢º Part: in_lab
	¢º Date: 2019/10/10

***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include "Parts.h"

namespace sdds {

	// Default constructor
	Arms::Arms() {
		force = 0;
	}

	// 1 Argument Constructor
	Arms::Arms(int A_force) {
		if (A_force < 1) {
			force = MIN_FORCE;
		}
		else {
			force = A_force;
		}
	}

	int Arms::getForce() const {
		return force;
	}

	// Operator Overload Members
	Arms& Arms::operator++() {
		force += 10;
		return *this;
	}

	Arms Arms::operator++(int) {
		Arms Arms_postFix = *this;
		force += 10;
		return Arms_postFix;
	}

	Arms& Arms::operator+=(int Passed_int) {
		force += Passed_int;

		if (force < 1) {
			force = 0;
		}

		return *this;
	}

}