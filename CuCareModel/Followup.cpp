// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// Followup.cpp - Implementation of class Followup
// Function and attribute declarations are in Followup.h

#include "Followup.h"
#include "IntProperty.h"

// Constructor
Followup::Followup () {
    getProperties()->push_back(new IntProperty(ID_NAME, this, &ModelObject::getId, &ModelObject::setId));
    getProperties()->push_back(new IntProperty("dueday", this, &ModelObject::getDay, &ModelObject::setDay));
    getProperties()->push_back(new IntProperty("duemonth", this, &ModelObject::getMonth, &ModelObject::setMonth));
    getProperties()->push_back(new IntProperty("dueyear", this, &ModelObject::getYear, &ModelObject::setYear));
    getProperties()->push_back(new IntProperty("receivedday", this, &ModelObject::getDay1, &ModelObject::setDay1));
    getProperties()->push_back(new IntProperty("receivedmonth", this, &ModelObject::getMonth1, &ModelObject::setMonth1));
    getProperties()->push_back(new IntProperty("receivedyear", this, &ModelObject::getYear1, &ModelObject::setYear1));
    getProperties()->push_back(new IntProperty("completedday", this, &ModelObject::getDay2, &ModelObject::setDay2));
    getProperties()->push_back(new IntProperty("completedmonth", this, &ModelObject::getMonth2, &ModelObject::setMonth2));
    getProperties()->push_back(new IntProperty("completedyear", this, &ModelObject::getYear2, &ModelObject::setYear2));
    getProperties()->push_back(new IntProperty("status", this, &ModelObject::getFStatus, &ModelObject::setFStatus));
}

// Static attribute definition

const string Followup::TABLE_NAME = "FOLLOWUPS";
const string Followup::ID_NAME = "followupid";

// Definition of functions declared as virtual in ModelObject

string Followup::getTableName() { return TABLE_NAME; }
string Followup::getIdName() { return ID_NAME; }

// Class attribute get() & set() methods

int Followup::getId() { return id; }
void Followup::setId(const int value) { id = value; }

int Followup::getFStatus() { return (int)status; }
void Followup::setFStatus(const int value) { status = (FollowupStatus)value; }

Date Followup::getDateDue() { return dateDue; }
void Followup::setDateDue(const Date value) { dateDue = value; }

	int Followup::getDay() { return dateDue.getDay(); }
	void Followup::setDay(const int value) { dateDue.setDay(value); }

	int Followup::getMonth() { return dateDue.getMonth(); }
	void Followup::setMonth(const int value) { dateDue.setMonth(value); }

	int Followup::getYear() { return dateDue.getYear(); }
	void Followup::setYear(const int value) { dateDue.setYear(value); }

Date Followup::getDateReceived() { return dateReceived; }
void Followup::setDateReceived(const Date value) { dateReceived = value; }

	int Followup::getDay1() { return dateReceived.getDay(); }
	void Followup::setDay1(const int value) { dateReceived.setDay(value); }

	int Followup::getMonth1() { return dateReceived.getMonth(); }
	void Followup::setMonth1(const int value) { dateReceived.setMonth(value); }

	int Followup::getYear1() { return dateReceived.getYear(); }
	void Followup::setYear1(const int value) { dateReceived.setYear(value); }

Date Followup::getDateCompleted() { return dateCompleted; }
void Followup::setDateCompleted(const Date value) { dateCompleted = value; }

	int Followup::getDay2() { return dateCompleted.getDay(); }
	void Followup::setDay2(const int value) { dateCompleted.setDay(value); }

	int Followup::getMonth2() { return dateCompleted.getMonth(); }
	void Followup::setMonth2(const int value) { dateCompleted.setMonth(value); }

	int Followup::getYear2() { return dateCompleted.getYear(); }
	void Followup::setYear2(const int value) { dateCompleted.setYear(value); }

// EOF
