// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// Patient.cpp - Implementation of class Patient
// Function and attribute declarations are in Patient.h

#include "Patient.h"
#include "StringProperty.h"
#include "IntProperty.h"

// Constructor
Patient::Patient()
    : patientId (0),
      firstName ("0"),
      lastName ("0"),
      notes ("0"),
      pPhysicianId (0)
{
    getProperties()->push_back(new IntProperty(ID_NAME, this, &ModelObject::getId, &ModelObject::setId));
	getProperties()->push_back(new StringProperty("firstname", this, &ModelObject::getFirstName, &ModelObject::setFirstName));
	getProperties()->push_back(new StringProperty("lastname", this, &ModelObject::getLastName, &ModelObject::setLastName));
	getProperties()->push_back(new StringProperty("country", this, &ModelObject::getCountry, &ModelObject::setCountry));
	getProperties()->push_back(new StringProperty("city", this, &ModelObject::getCity, &ModelObject::setCity));
	getProperties()->push_back(new StringProperty("addresslineone", this, &ModelObject::getLineOne, &ModelObject::setLineOne));
	getProperties()->push_back(new StringProperty("addresslinetwo", this, &ModelObject::getLineTwo, &ModelObject::setLineTwo));
	getProperties()->push_back(new StringProperty("postalcode", this, &ModelObject::getPostalCode, &ModelObject::setPostalCode));
	getProperties()->push_back(new StringProperty("workphone", this, &ModelObject::getWorkPhone, &ModelObject::setWorkPhone));
	getProperties()->push_back(new StringProperty("cellphone", this, &ModelObject::getCellPhone, &ModelObject::setCellPhone));
	getProperties()->push_back(new StringProperty("email", this, &ModelObject::getEmail, &ModelObject::setEmail));
	getProperties()->push_back(new StringProperty("workemail", this, &ModelObject::getWorkEmail, &ModelObject::setWorkEmail));
	getProperties()->push_back(new IntProperty("birthday", this, &ModelObject::getDay, &ModelObject::setDay));
	getProperties()->push_back(new IntProperty("birthmonth", this, &ModelObject::getMonth, &ModelObject::setMonth));
	getProperties()->push_back(new IntProperty("birthyear", this, &ModelObject::getYear, &ModelObject::setYear));
	getProperties()->push_back(new IntProperty("addedday", this, &ModelObject::getDay1, &ModelObject::setDay1));
	getProperties()->push_back(new IntProperty("addedmonth", this, &ModelObject::getMonth1, &ModelObject::setMonth1));
	getProperties()->push_back(new IntProperty("addedyear", this, &ModelObject::getYear1, &ModelObject::setYear1));
	getProperties()->push_back(new StringProperty("healthcardnumber", this, &ModelObject::getHCNumber, &ModelObject::setHCNumber));
	getProperties()->push_back(new IntProperty("healthcardexpiryday", this, &ModelObject::getHCExpiryDay, &ModelObject::setHCExpiryDay));
	getProperties()->push_back(new IntProperty("healthcardexpirymonth", this, &ModelObject::getHCExpiryMonth, &ModelObject::setHCExpiryMonth));
	getProperties()->push_back(new IntProperty("healthcardexpiryyear", this, &ModelObject::getHCExpiryYear, &ModelObject::setHCExpiryYear));
	getProperties()->push_back(new StringProperty("notes", this, &ModelObject::getNotes, &ModelObject::setNotes));
	getProperties()->push_back(new IntProperty("physicianid", this, &ModelObject::getPhysicianId, &ModelObject::setPhysicianId));
}

// Static attribute definition

const string Patient::TABLE_NAME = "PATIENTS";
const string Patient::ID_NAME = "patientid";

// Definition of functions declared as virtual in ModelObject 

string Patient::getTableName() { return Patient::TABLE_NAME; }
string Patient::getIdName() { return ID_NAME; }

ModelObject::ObjectType Patient::getObjectType() { return ModelObject::PATIENT; }

// Class attribute get() & set() methods

int Patient::getId() { return patientId; }
void Patient::setId(const int value) { patientId = value; }

string Patient::getFirstName() { return firstName; }
void Patient::setFirstName(const string value) { firstName = value; }

string Patient::getLastName() { return lastName; }
void Patient::setLastName(const string value) { lastName = value; }

Address Patient::getAddress() { return address; }
void Patient::setAddress(const Address value) { address = value; }

    string  Patient::getCountry() { return address.getCountry(); }
	void  Patient::setCountry(const string value) { address.setCountry(value); }

    string  Patient::getCity() { return address.getCity(); }
	void  Patient::setCity(const string value) { address.setCity(value); }

    string  Patient::getLineOne() { return address.getLineOne(); }
	void  Patient::setLineOne(const string value) { address.setLineOne(value); }

    string  Patient::getLineTwo() { return address.getLineTwo(); }
	void  Patient::setLineTwo(const string value) { address.setLineTwo(value); }

    string  Patient::getPostalCode() { return address.getPostalCode(); }
	void  Patient::setPostalCode(const string value) { address.setPostalCode(value); }

ContactInfo Patient::getContact() { return contact; }
void Patient::setContact(const ContactInfo value) { contact = value; }

    string Patient::getWorkPhone() { return contact.getWorkPhone(); }
	void Patient::setWorkPhone(const string value) { contact.setWorkPhone(value); }

	string Patient::getCellPhone() { return contact.getCellPhone(); }
	void Patient::setCellPhone(const string value) { contact.setCellPhone(value); }

	string Patient::getEmail() { return contact.getEmail(); }
	void Patient::setEmail(const string value) { contact.setEmail(value); }

	string Patient::getWorkEmail() { return contact.getWorkEmail(); }
	void Patient::setWorkEmail(const string value) { contact.setWorkEmail(value); }

Date Patient::getDateOfBirth() { return dateOfBirth; }
void Patient::setDateOfBirth(const Date value) { dateOfBirth = value; }

	int  Patient::getDay() { return dateOfBirth.getDay(); }
	void  Patient::setDay(const int value) { dateOfBirth.setDay(value); }

	int  Patient::getMonth() { return dateOfBirth.getMonth(); }
	void  Patient::setMonth(const int value) { dateOfBirth.setMonth(value); }

	int  Patient::getYear() { return dateOfBirth.getYear(); }
	void  Patient::setYear(const int value) { dateOfBirth.setYear(value); }

Date Patient::getDateAddedToSystem() { return dateAddedToSystem; }
void Patient::setDateAddedToSystem(const Date value) { dateAddedToSystem = value; }

	int  Patient::getDay1() { return dateAddedToSystem.getDay(); }
	void  Patient::setDay1(const int value) { dateAddedToSystem.setDay(value); }

	int  Patient::getMonth1() { return dateAddedToSystem.getMonth(); }
	void  Patient::setMonth1(const int value) { dateAddedToSystem.setMonth(value); }

	int  Patient::getYear1() { return dateAddedToSystem.getYear(); }
	void  Patient::setYear1(const int value) { dateAddedToSystem.setYear(value); }

HealthCard Patient::getHealthCard() { return healthCard; }
void Patient::setHealthCard(const HealthCard value) { healthCard = value; }

	string Patient::getHCNumber() { return healthCard.getNumber(); }
	void Patient::setHCNumber(const string value) { healthCard.setNumber(value); }

	int Patient::getHCExpiryDay() { return healthCard.getExpiryPtr()->getDay(); }
	void Patient::setHCExpiryDay(const int value) { healthCard.getExpiryPtr()->setDay(value); }

	int Patient::getHCExpiryMonth() { return healthCard.getExpiryPtr()->getMonth(); }
	void Patient::setHCExpiryMonth(const int value) { healthCard.getExpiryPtr()->setMonth(value); }

	int Patient::getHCExpiryYear() { return healthCard.getExpiryPtr()->getYear(); }
	void Patient::setHCExpiryYear(const int value) { healthCard.getExpiryPtr()->setYear(value); }

string Patient::getNotes() { return notes; }
void Patient::setNotes(const string value) { notes = value; }

int Patient::getPhysicianId() { return pPhysicianId; }
void Patient::setPhysicianId(const int value) { pPhysicianId = value; }

list<int>* Patient::getConsultationIds() { return &consultationIds; }
void Patient::setConsultationIds(list<int> newConsultationIds) { consultationIds = newConsultationIds; }
void Patient::addConsultationId(const int value) { consultationIds.push_back(value); }

// EOF
