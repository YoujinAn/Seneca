// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:22 March, 2020

#ifndef CUSTOMERORDER
#define CUSTOMERORDER

#include <iostream>
#include <string>

#include "Station.h"
#include "Utilities.h"

struct Item
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_isFilled = false;

	Item(const std::string& src) : m_itemName(src) {};
};

class CustomerOrder {
private:
	std::string m_name;			// the name of the customer 
	std::string m_product;		// the name of the product being assembled
	unsigned int m_cntItem;		// a count of the number of items for the customer's order
	Item** m_lstItem;			// a dynamically allocated array of pointers
	static size_t m_widthField;	// the maximum width of a field, used for display purposes

	Utilities util;

public:
	CustomerOrder();								// default constructor
	CustomerOrder(const std::string& str);			// custom constructor
	~CustomerOrder();								// destructor

	// copy operations
	CustomerOrder(CustomerOrder& copy) { throw "ERROR:  Copy is not allows"; };				
	CustomerOrder& operator=(CustomerOrder& copy) = delete;

	// move constructor
	CustomerOrder(CustomerOrder&& move) noexcept;
	CustomerOrder& operator=(CustomerOrder&& move) noexcept;

	bool isOrderFilled() const;
	bool isItemFilled(const std::string& itemName) const;
	void fillItem(Station& station, std::ostream& os);
	void display(std::ostream& os) const;
};

#endif // CUSTOMERORDER
