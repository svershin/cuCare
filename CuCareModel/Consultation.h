// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// Consultation.h - Declaration of class Consultation
// Member functions are defined in Consultation.cpp

#ifndef CONSULTATION_H
#define CONSULTATION_H

#include <string>
#include <vector>
#include "Date.h"
#include "Time.h"
#include "ModelObject.h"

using namespace std;

class Consultation : public ModelObject
{
public:
	// Constructor
	Consultation ();

	// Declaration of functions declared as virtual in ModelObject 

	string getTableName();
    string getIdName();

	ObjectType getObjectType();

	// Class attribute get() & set() methods

	int getId();
	void setId(const int value);

	string getReason();
	void setReason(const string value);

	string getDiagnosis();
	void setDiagnosis(const string value);

	string getComments();
	void setComments(const string value);

    int getCStatus();
    void setCStatus(const int value);

	Date getDate();
	void setDate(const Date value);

		int getDay();
		void setDay(int value);

		int getMonth();
		void setMonth(int value);

		int getYear();
		void setYear(int value);

	Time getTime();
	void setTime(const Time value);

		int getHour();
		void setHour(int value);

		int getMinute();
		void setMinute(int value);

	int getPhysicianId();
	void setPhysicianId(int value);

	vector<int>* getFollowupIds();
	void addFollowupId(const int value);

    static const string TABLE_NAME;
    static const string ID_NAME;

private:
	int consultId;
    string reason;
	string diagnosis;
	string comments;
	ConsultationStatus status;
	Date date;
	Time time;
	vector<int> followupIds;
	int consultingPhysId;
};

#endif // CONSULTATION_H

// EOF
