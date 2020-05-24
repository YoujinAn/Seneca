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
			name[0] = '\0';
			pose = nullptr;
			price = 0.0;

		if (nick_name != nullptr && fig_pose != nullptr) {
			// name
			if (strlen(nick_name) > MAX_NAME_LEN) {
				setName(nick_name);
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

	Figurine::Figurine(const Figurine& copy_fig) {
		// name
		strcpy(name, copy_fig.name);

		// pose
		if (copy_fig.pose == nullptr) {
			pose = nullptr;
		}
		else {
			// pose = nullptr. Before it is deleted in the setPose
			pose = nullptr;

			setPose(copy_fig.pose);
		}

		// price
		price = copy_fig.price;
	}

	void Figurine::setName(const char* set_name) {
		strncpy(name, set_name, MAX_NAME_LEN);
		name[strlen(name) + 1] = '\0';
	}

	void Figurine::setPose(const char* set_pose) {
		// **if there is some data, they should be deleted 
		// (FigurineTester.cpp Line 65,73)
		delete[] pose; 

		pose = new char[strlen(set_pose) + 1];
		strcpy(pose, set_pose);
		pose[strlen(pose)] = '\0';
	}

	void Figurine::setPrice(double set_price) {
		if (set_price < 1.0) {
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
			cout << "Price: " << fixed << setprecision(2) << price << endl;
		}

		return cout;
	}

	Figurine::operator bool() const {
		return (name[0] == '\0');
	}
} // sdds
