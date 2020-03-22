// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:22 March, 2020

#include <vector>
#include <iomanip>

#include "CustomerOrder.h"

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder() {
	m_name = "";
	m_product = "";
	m_cntItem = 1;
	m_lstItem = nullptr;
}

CustomerOrder::CustomerOrder(const std::string& str) {

	size_t tmp_pos = -1;
	bool check = false;
	std::vector<Item*> tmpVec;

	m_name = util.extractToken(str, tmp_pos, check);
	m_product = util.extractToken(str, tmp_pos, check);

	while (check) {
		tmpVec.push_back(new Item(util.extractToken(str, tmp_pos, check)));
	}
	m_cntItem = static_cast<unsigned int>(tmpVec.size());
	m_lstItem = new Item * [m_cntItem];
	for (size_t i = 0; i < m_cntItem; i++) {
		m_lstItem[i] = std::move(tmpVec[i]);
	}
}

CustomerOrder::~CustomerOrder() {
	for (size_t i = 0u; i < m_cntItem; i++) delete m_lstItem[i];
	delete[] m_lstItem;
	m_lstItem = nullptr;
}

// move constructor
CustomerOrder::CustomerOrder(CustomerOrder&& move) noexcept {
	*this = std::move(move);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& move) noexcept {
	if (this != &move) {
		m_name = move.m_name;
		m_product = move.m_product;
		m_cntItem = move.m_cntItem;
		m_lstItem = move.m_lstItem;
		m_widthField = move.m_widthField;

		move.m_name = "";
		move.m_product = "";
		move.m_cntItem = 0;
		move.m_lstItem = nullptr;
		move.m_widthField = 0;
	}

	return *this;
}


bool CustomerOrder::isOrderFilled() const {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_isFilled == false)
			return false;
	}
	return true;
}

bool CustomerOrder::isItemFilled(const std::string& itemName) const {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == itemName) {
			if (!m_lstItem[i]->m_isFilled) {
				return false;
			}
		}
	}
	return true;
}

void CustomerOrder::fillItem(Station& station, std::ostream& os) {
	m_widthField = util.getFieldWidth();

	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == station.getItemName()) {
			m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
			m_lstItem[i]->m_isFilled = true;

			os << "    ";
			os << (m_lstItem[i]->m_isFilled ? "Filled" : "Unfilled") << " ";
			os << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;

		}
	}
}

void CustomerOrder::display(std::ostream& os) const {
	os << m_name << " - " << m_product << std::endl;

	for (size_t i = 0; i < m_cntItem; i++) {
		os << std::setw(6) << std::setfill('0') << "[" << m_lstItem[i]->m_serialNumber << "] ";
		os << std::setw(16) << std::setfill(' ') << m_lstItem[i]->m_itemName << " - ";
		os << (isItemFilled(m_lstItem[i]->m_itemName) ? "Filled" : "MISSING") << std::endl;
	}
}