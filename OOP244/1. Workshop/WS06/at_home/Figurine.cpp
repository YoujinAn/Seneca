/***********************************************************************
// OOP244 Workshop 6: Class with a Resource
//
// File Figurin.cpp

	¢º Name: Youjin An
	¢º Email : yan24@myseneca.ca
	¢º Part: at_home
	¢º Date: 2019/Nov/07

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
		copy = false;
	}

	Figurine::Figurine(const char* nick_name, const char* fig_pose, double fig_price, bool copy_check) {

		//  the name or the pose is either nullptr or an empty string then set the Figurine to a safe empty state. 
		name[0] = '\0';
		pose = nullptr;
		price = 0.0;
		copy = false;

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
		// shallow capy non dynamic variables
		// name 
		strcpy(name, copy_fig.name);

		// price
		price = copy_fig.price;

		// deallocate previous allocated memory
		// pose
		if (copy_fig.pose == nullptr) {
			pose = nullptr;
		}
		else {
			// pose = nullptr. Before it is deleted in the setPose
			pose = nullptr;

			setPose(copy_fig.pose);
		}

		// copy
		copy = true;
	}

	Figurine& Figurine::operator=(const Figurine& copy_fig) {
		// check for self assignment
		if (this != &copy_fig) {
			// to deallocate any old memory that was allocated to our dynamic resources.
			delete[] pose;

			// shallow capy non dynamic variables
			// name 
			strcpy(name, copy_fig.name);

			// price
			price = copy_fig.price;

			// deallocate previous allocated memory
			if (copy_fig.pose == nullptr) {
				pose = nullptr;
			}
			else {
				// pose = nullptr. Before it is deleted in the setPose
				pose = nullptr;

				setPose(copy_fig.pose);
			}

			// copy
			copy = true;

		} // if (this != &copy_fig)
		return *this;
	}

	//get
	const char* Figurine::getName() const {
		return name;
	}
	const char* Figurine::getPose() const {
		return pose;
	}
	double Figurine::getPrice() const {
		return price;
	}

	// set
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
			// If the object is empty and a copy
			if (copy == true) {
				cout << "This is a replica of emptiness" << endl;
			}
		}
		else {
			cout << "Figurine Details" << endl;

			cout << "Name: " << name << endl;
			cout << "Pose: " << pose << endl;
			cout << "Price: " << fixed << setprecision(2) << price << endl;
			// If the Figurine isn¡¯t empty but is a copy
			if (copy == true) {
				cout << "This is a replica" << endl;
			}
		}

		return cout;
	}

	Figurine::operator bool() const {
		return (name[0] == '\0');
	}

	bool Figurine::isCopy() const {
		return (copy == true);
	}

	bool operator==(const Figurine& copy_fig_1, const Figurine& copy_fig_2) {
		bool check = false;

		// 1. The name, pose and price are the same between the two
		if ((copy_fig_1.getName() == copy_fig_2.getName()) &&
			(copy_fig_1.getPose() == copy_fig_2.getPose()) &&
			(copy_fig_1.getPrice() == copy_fig_2.getPrice())  ) {
			// 2. Neither Figurine is a copy of the other.
			if ((copy_fig_1.isCopy() == false) && (copy_fig_2.isCopy() == false)) {
				check = true;
			}
		}
		return check;
	}

} // sdds
