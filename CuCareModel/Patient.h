// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
//
// Patient.h - Declaration of base class Patient
// Member functions are defined in Patient.cpp

#ifndef PATIENT_H
#define PATIENT_H

#include <vector>
#include <string>
#include "ContactInfo.h"
#include "Date.h"
#include "Address.h"
#include "HealthCard.h"
#include "ModelObject.h"

using namespace std;

class Patient : public ModelObject
{
public:
	// Constructor
	Patient ();

	// Declaration of functions declared as virtual in ModelObject 

	string getTableName();

	ObjectType getObjectType();

	// Class attribute get() & set() methods

	int getId();
	void setId(const int value);

	string getFirstName();
	void setFirstName(const string value);

	string getLastName();
	void setLastName(const string value);

	Address getAddress();
	void setAddress(const Address value);

		string getCountry();
		void setCountry(const string value);

		string getCity();
		void setCity(const string value);

		string getLineOne();
		void setLineOne(const string value);

		string getLineTwo();
		void setLineTwo(const string value);

		string getPostalCode();
		void setPostalCode(const string value);

	ContactInfo getContact();
	void setContact(const ContactInfo value);

		string getWorkPhone();
		void setWorkPhone(const string value);

		string getCellPhone();
		void setCellPhone(const string value);

		string getEmail();
		void setEmail(const string value);

		string getWorkEmail();
		void setWorkEmail(const string value);

	Date getDateOfBirth();
	void setDateOfBirth(const Date value);

		int getDay();
		void setDay(const int value);

		int getMonth();
		void setMonth(const int value);

		int getYear();
		void setYear(const int value);

	Date getDateAddedToSystem();
	void setDateAddedToSystem(const Date value);

		int getDay1();
		void setDay1(const int value);

		int getMonth1();
		void setMonth1(const int value);

		int getYear1();
		void setYear1(const int value);

	HealthCard getHealthCard();
	void setHealthCard(const HealthCard value);

		string getHCNumber();
		void setHCNumber(const string value);

		int getHCExpiryDay();
		void setHCExpiryDay(const int value);

		int getHCExpiryMonth();
		void setHCExpiryMonth(const int value);

		int getHCExpiryYear();
		void setHCExpiryYear(const int value);

	string getNotes();
	void setNotes(const string value);

	int getPhysicianId();
	void setPhysicianId(int const value);

	vector<int>* getConsultationIds();
	void addConsultationId(const int value);

    static const string TABLE_NAME;
private:
	int patientId;
	string firstName;
	string lastName;
	Address address;
	ContactInfo contact;
	Date dateOfBirth;
	Date dateAddedToSystem;
	HealthCard healthCard;
	string notes;
	int pPhysicianId;
	vector<int> consultationIds;
};


#endif // PATIENT_H

// EOF
