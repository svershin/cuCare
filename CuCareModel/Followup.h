// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// Followup.h - Declaration of class Followup
// Member functions are defined in Followup.cpp

#ifndef FOLLOWUP_H
#define FOLLOWUP_H

#include "Date.h"
#include "ModelObject.h"

class Followup : public ModelObject
{
public:
	// Constructor
	Followup ();

	// Declaration of functions declared as virtual in ModelObject 

	string getTableName();
    string getIdName();

	// Class attribute get() & set() methods

	int getId();
	void setId(const int value);

    int getFStatus();
    void setFStatus(const int value);

	Date getDateDue();
	void setDateDue(const Date value);

		int getDay();
		void setDay(const int value);

		int getMonth();
		void setMonth(const int value);

		int getYear();
		void setYear(const int value);

	Date getDateReceived();
	void setDateReceived(const Date value);

		int getDay1();
		void setDay1(const int value);

		int getMonth1();
		void setMonth1(const int value);

		int getYear1();
		void setYear1(const int value);

	Date getDateCompleted();
	void setDateCompleted(const Date value);

		int getDay2();
		void setDay2(const int value);

		int getMonth2();
		void setMonth2(const int value);

		int getYear2();
		void setYear2(const int value);

        static const string TABLE_NAME;
        static const string ID_NAME;

private:
	int id;
	FollowupStatus status;
	Date dateDue;
	Date dateReceived;
	Date dateCompleted;
};

#endif // FOLLOWUP_H

// EOF
