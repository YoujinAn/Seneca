/***********************************************************************
// OOP244 MILESTONE 1: Date Class & MenuItem Class & Menu Class
//
// File Menu.h

	¢º Name: Youjin An
	¢º Email : yan24@myseneca.ca
	¢º Part: MS01
	¢º Date: 17 Nov 2019

// Menu Class: A class that has several MenuItems to be displayed
				so the user can select one of them for an action to be executed in the program

***********************************************************************/

#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__

#include <iostream>

namespace sdds {

	const unsigned int MAX_MENU_ITEMS = 20;
	const unsigned int MAX_TITLE_LEN = 30;

	class MenuItem {
		// This class should be fully private
	private:
		friend class Menu; // MenuItem class only accessible by the Menu class

		// To hold only one C style string of characters for the description in the menu item.
		char* menu_item_description;

		MenuItem();
		MenuItem(const char*);
		~MenuItem();

		// A MenuItem object can not be copied from or assigned to another MenuItem object
		MenuItem(const MenuItem& copy_menu_item) = delete;
		void operator=(const MenuItem& copy_menu_item) = delete;

		operator bool()const;
		operator const char* ();

		std::ostream& display(std::ostream& os = std::cout); // Display the description of the MenuItem 
	};

	class Menu {
		// This class has minimum of three member variables.
	private:
		char* menu_title;
		MenuItem* menu_items[MAX_MENU_ITEMS];
		int menuItems_of_num;

	public:
		Menu();
		Menu(const char* m_title);
		~Menu();

		// A Menu Object can not be copied or assigned to another Menu Object.
		Menu(const Menu& copy_menu) = delete;
		void operator=(const Menu& copy_menu) = delete;

		std::ostream& display_title(std::ostream& os = std::cout)const;
		std::ostream& display(std::ostream& os = std::cout)const;

		// Operator overloads
		Menu& operator<<(const char* menu_item_des);

		unsigned int getSelection();
		int operator~();

		operator int()const;
		operator unsigned int()const;

		operator bool()const;

		const char* operator[](int index)const;
	};
	// Helper operator overloads
	std::ostream& operator<<(std::ostream& os, Menu& menu);
}
#endif // SDDS_MENU_H__