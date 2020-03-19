// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:18 March, 2020

// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include "List.h"
#include "Element.h"

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price);
}

#endif