// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:18 March, 2020

// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t j = 0; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					Product* ptr = new Product(desc[i].desc, price[j].price);
					ptr->validate();
					priceList += ptr;

					delete ptr;
					ptr = nullptr;
				}
			}
		}

		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers
		for (size_t i = 0; i < desc.size(); i++)
		{
			for (size_t n = 0; n < price.size(); n++)
			{
				if (desc[i].code == price[n].code)
				{
					std::unique_ptr<Product> ptr(new Product(desc[i].desc, price[n].price));
					ptr->validate();
					priceList += ptr;
				}
			}
		}

		return priceList;
	}
}