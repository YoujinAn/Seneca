/***********************************************************************
// OOP244 Workshop 6: Class with a Resource
//
// File Figurin.cpp

	¢º Name: Youjin An
	¢º Email : yan24@myseneca.ca
	¢º Part: in_lab
	¢º Date: 2019/Nov/06

***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iomanip>

#include "Figurine.h"

namespace sdds {

	Figurine::Figurine() {
		name[0] = '\0';
		pose = nullptr;
		price = 0.0;
	}

	Figurine::Figurine(const char* nick_name, const char* fig_pose, double fig_price) {

		//  the name or the pose is either nullptr or an empty string then set the Figurine to a safe empty state. 
		if (nick_name == nullptr || fig_pose == nullptr) {
			name[0] = '\0';
			pose = nullptr;
			price = 0.0;
		}
		else {
			// name
			if (strlen(nick_name) > MAX_NAME_LEN) {
				strcpy(name, nick_name);
				name [strlen(name) + 1] = '\0';
			}
			else {
				setName(nick_name);
			}

			// pose
			setPose(fig_pose);

			// price
			setPrice(fig_price);
		}
	}

	Figurine::~Figurine() {
		delete[] pose;
		pose = nullptr;
	}

	Figurine::Figurine(const Figurine& copy_fig) : price(copy_fig.price) {
		// name
		strcpy(name, copy_fig.name);

		// pose
		if (copy_fig.pose == nullptr) {
			pose = nullptr;
		}
		else {
			pose = new char[strlen(copy_fig.pose) + 1];
			strcpy(pose, copy_fig.pose);
			pose[strlen(pose) + 1] = '\0';
		}
	}

	void Figurine::setName(const char* set_name) {
		strcpy(name, set_name);
		name[strlen(name) + 1] = '\0';
	}

	void Figurine::setPose(const char* set_pose) {
		pose = new char[strlen(set_pose) + 1];
		strcpy(pose, set_pose);
		pose[strlen(pose)] = '\0';
	}

	void Figurine::setPrice(double set_price) {
		if (set_price < 1) {
			price = DEFAULT_PRICE;
		}
		else {
			price = set_price;
		}
	}

	std::ostream& Figurine::display() const {
		if (name[0] == '\0' || pose == nullptr) {
			cout << "This Figurine has not yet been sculpted" << endl;
		}
		else {
			cout << "Figurine Details" << endl;

			cout << "Name: " << name << endl;
			cout << "Pose: " << pose << endl;
			cout << "Pirce: " << fixed << setprecision(2) << price << endl;
		}

		return cout;
	}

	Figurine::operator bool() const {
		return (name[0] == '\0');
	}
} // sdds
