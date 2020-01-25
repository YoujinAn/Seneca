// Name: Youjin An
// Seneca Student ID:140413188
// Seneca email:yan24@myseneca.ca
// Date of completion:25 Jan, 2020

#define _CRT_SECURE_NO_WARNINGS

#include "RecordSet.h"

using namespace std;

namespace sdds {

	RecordSet::RecordSet() {
		records = nullptr;
		Record_num = 0;
	}

	RecordSet::RecordSet(const char* file_name) {
		string str;
		string str1;
		ifstream f_obj;
		size_t i = 0;
		Record_num = 0;
		f_obj.open(file_name);
		if (f_obj.is_open()) {
			while (getline(f_obj, str, ' ')) {
				Record_num++;
			}

		}
		f_obj.close();
		records = new string[Record_num];
		f_obj.open(file_name);
		while (getline(f_obj, str1, ' ')) {
			records[i] = str1;
			i++;
		}
	}

	RecordSet::RecordSet(const RecordSet& _RecordSet) {
		records = nullptr;
		*this = _RecordSet;
	}

	RecordSet& RecordSet::operator=(const RecordSet& _RecordSet) {

		if (this != &_RecordSet) {
			Record_num = _RecordSet.Record_num;
			delete[] records;
			if (_RecordSet.records != nullptr)
			{
				records = new string[_RecordSet.Record_num];
				for (unsigned int i = 0; i < _RecordSet.Record_num; i++) {
					records[i] = _RecordSet.records[i];
				}
			}
			else {
				records = nullptr;
			}
		}

		return *this;
	}
	
	RecordSet::~RecordSet() {
		delete[] records;
	}

	size_t RecordSet::size() const {
		return Record_num;
	}

	string RecordSet::getRecord(size_t _records) {
		string temp = "";

		if (_records >= 0 && _records < Record_num) {
			temp = records[_records];
		}
		else {
			temp = "";
		}

		return temp;
	}

	RecordSet::RecordSet(RecordSet&& src)
	{
		*this = std::move(src);
	}

	RecordSet& RecordSet::operator=(RecordSet&& src)
	{
		if (this != &src)
		{
			delete[] records;
			records = new string[src.Record_num + 1];
			for (size_t i = 0; i < src.Record_num; i++) {
				records[i] = src.records[i];
			}
			Record_num = src.Record_num;
			src.records = nullptr;
			src.Record_num = 0;

		}
		return *this;
	}

}