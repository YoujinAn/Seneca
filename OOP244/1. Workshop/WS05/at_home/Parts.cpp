/***********************************************************************
// OOP244 Workshop 5: Member Operator Overloads IN LAB
//
// File Parts.cpp

	¢º Name: Youjin An
	¢º Email : auj0827@gmail.com
	¢º Part: at_home
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

	/***********************************************************************
							at_home part (Legs)
	***********************************************************************/

	Legs::Legs() {
		speed = 0;
	}

	Legs::Legs(int L_speed) {
		if (L_speed < 1) {
			speed = MIN_SPEED;
		}
		else {
			speed = L_speed;
		}
	}

	int Legs::getSpeed() const {
		return speed;
	}

	Legs& Legs::operator-=(int Passed_int) {
		speed -= Passed_int;
		if (speed < 1) {
			speed = 0;
		}
		return *this;
	}

	// Global Helper Operators (Arms, Legs)
	bool operator > (const Legs& L1, const Legs& L2) {
		return (L1.getSpeed() > L2.getSpeed());
	}
	bool operator < (const Legs& L1, const Legs& L2) {
		return (L1.getSpeed() < L2.getSpeed());
	}
	bool operator > (const Arms& A1, const Arms& A2) {
		return (A1.getForce() > A2.getForce());
	}
	bool operator < (const Arms& A1, const Arms& A2) {
		return (A1.getForce() < A2.getForce());
	}
}