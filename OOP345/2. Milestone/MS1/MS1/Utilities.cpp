// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:14 March, 2020

#define _CRT_SECURE_NO_WARNINGS

#include <string>

#include "Utilities.h"

char Utilities::m_delimiter = '\0';

Utilities::Utilities() {
	m_widthField = 1;
}

void Utilities::setFieldWidth(size_t _m_widthField) {
	m_widthField = _m_widthField;
}

size_t Utilities::getFieldWidth() const {
	return m_widthField;
}

const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {

	std::string tmp = "";
	size_t fieldOfDelimiter = str.find(m_delimiter, next_pos + 1);
	if (fieldOfDelimiter < str.length()) {
		more = true;
	}
	else {
		fieldOfDelimiter = str.length();
		more = false;
	}
	tmp = str.substr(next_pos + 1, fieldOfDelimiter - next_pos - 1);
	next_pos = fieldOfDelimiter;


	if (tmp == "")
		throw "Error - 2 delimiter";
	return tmp;
}

void Utilities::setDelimiter(const char deli) {
	m_delimiter = deli;
}
const char Utilities::getDelimiter() const {
	return m_delimiter;
}
