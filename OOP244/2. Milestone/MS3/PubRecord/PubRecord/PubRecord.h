/***********************************************************************
// OOP244 Project Milestone 3: THE PUBRECORD ABSRACT CLASS
//
// File PubRecord.h

	¢º Name: Youjin An
	¢º Email : yan24@myseneca.ca
	¢º Part: MS03
	¢º Date: 23 Nov 2019

***********************************************************************/

#ifndef SDDS_PUBRECORD_H__
#define SDDS_PUBRECORD_H__

#include "ReadWriteable.h"
#include "Date.h"

namespace sdds {

	const int SDDS_CONSOLE = 0;
	const int SDDS_FILE = 1;

	class PubRecord :public ReadWriteable {
	private:
		char* pub_name;		// to hold the name of the publication
		int shelf_num;		// to hold the shelf number
		int typeOfmedia;	// to hold the type of the media
	protected:
		const char* name()const;
		void name(const char* p_name);
	public:
		PubRecord();
		~PubRecord();

		// copy constructor
		PubRecord(const PubRecord& p_name);
		PubRecord& operator=(const PubRecord& p_name);

		// Two functions called mediaType to set and return the type of the media
		void mediaType(int p_typeOfmedia);
		int mediaType()const;

		void readShelfNo();
		int shelfNo()const;

		// returns a characterand does not change the class
		virtual char recID()const;

		// overloaded operators
		bool operator==(char rec_id)const;
		bool operator==(const char* p_name)const;
		operator bool()const;
	};

}
#endif // !SDDS_PUBRECORD_H__
