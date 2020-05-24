/***********************************************************************
// OOP244 MILESTONE 1: Date Class & MenuItem Class & Menu Class
//
// File Menu.cpp

	¢º Name: Youjin An
	¢º Email : yan24@myseneca.ca
	¢º Part: MS01
	¢º Date: 17 Nov 2019

// Menu Class: A class that has several MenuItems to be displayed
				so the user can select one of them for an action to be executed in the program

***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <cstring>

using namespace std;

#include "Utils.h"
#include "Menu.h"

namespace sdds {

	/*--------------------------------------------------
	/						MenuItem
	----------------------------------------------------*/

	MenuItem::MenuItem() {
		menu_item_description = nullptr;
	}

	MenuItem::MenuItem(const char* menu_item_des) {
		menu_item_description = new char[strlen(menu_item_des) + 1];
		strcpy(menu_item_description, menu_item_des);
		// menu_item_description[strlen(menu_item_des) + 1] = '\0';
	}

	MenuItem::~MenuItem() {
		delete[] menu_item_description;
		menu_item_description = nullptr;
	}

	MenuItem::operator bool()const {
		// It should return false if it is empty.
		if (menu_item_description == nullptr)
			return false;
		else
			return true;
	}

	MenuItem::operator const char* () {
		return menu_item_description;
	}

	std::ostream& MenuItem::display(std::ostream& os) {
		os << menu_item_description;
		return os;
	}

	/*--------------------------------------------------
	/						Menu
	----------------------------------------------------*/

	Menu::Menu() {
		menu_title = nullptr;

		// menu_items
		menu_items[0] = nullptr;
		for (unsigned int i = 0; i < MAX_MENU_ITEMS; ++i) {
			menu_items[i] = nullptr;
		}

		menuItems_of_num = 0;
	}

	Menu::Menu(const char* m_title) {

		// menu_title
		menu_title = new char[strlen(m_title) + 1];
		strcpy(menu_title, m_title);
		// menu_title[strlen(m_title) + 1] = '\0';

		// menu_items
		menu_items[0] = nullptr;
		for (unsigned int i = 0; i < MAX_MENU_ITEMS; ++i) {
			menu_items[i] = nullptr;
		}

		// menuItems_of_num
		menuItems_of_num = 0;
	}

	Menu::~Menu() {
		// menu_title
		delete[] menu_title;
		menu_title = nullptr;

		// menu_items
		for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++) {
			delete menu_items[i];
			menu_items[i] = nullptr;
		}
	}

	ostream& Menu::display_title(ostream& os)const {
		if (menu_title != nullptr) {
			os << menu_title;
		}
		return os;
	}

	ostream& Menu::display(ostream& os)const {
		int i = 0;

		if (menu_title != nullptr) {
			display_title(os) << ':' << endl;
		}

		while (menu_items[i] != nullptr) {
			os << " " << i + 1 << "- " << (const char*)*menu_items[i] << endl;
			++i;
		}
		os << " 0- Exit" << endl << "> ";

		return os;
	}

	// Operator overloads
	Menu& Menu::operator<<(const char* menu_item_des) {
		if ((unsigned int)menuItems_of_num < MAX_MENU_ITEMS) {
			menu_items[menuItems_of_num] = new MenuItem(menu_item_des);
			++menuItems_of_num;
		}
		return *this;
	}

	unsigned int Menu::getSelection() {
		int selection = -1;
		bool check = false;
		display();
		do {
			cin >> selection;
			// between 0 and the number of the menu items
			if (cin.fail() || selection < 0 || selection > menuItems_of_num) {
				cin.clear();
				cin.ignore(1000, '\n');
				check = true;
				cout << "Invalid Selection, try again: ";
			}
			else {
				check = false;
				cin.ignore(1000, '\n');
			}
		} while (check);

		return selection;
	}

	int Menu::operator~() {
		return getSelection();
	}

	// Casting the Menu to an integer or an unsigned integer should return 
	// the number of MenuItems allocated in the MenuItem array of pointers. 
	Menu::operator int()const {
		return menuItems_of_num;
	}

	Menu::operator unsigned int()const {
		return (unsigned int)menuItems_of_num;
	}

	Menu::operator bool()const {
		if (int(*this) > 0) {
			return true;
		}
		else { return false; }
	}

	const char* Menu::operator[](int index)const {
		if (index >= 0 && menu_items[index] != nullptr)
			return (const char*)*menu_items[(index + 1) % menuItems_of_num == 0 ? menuItems_of_num - 1 : (index + 1) % menuItems_of_num - 1];
		else
			return nullptr;
	}

	ostream& operator<<(ostream& os, Menu& menu) {
		menu.display_title(os);
		return os;
	}

}