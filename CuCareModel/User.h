// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// User.h - Declaration of class User
// Member functions are defined in User.cpp

#ifndef USER_H
#define USER_H

#include <string>
#include "Date.h"
#include "ContactInfo.h"
#include "Address.h"
#include "ModelObject.h"

using namespace std;

class User : public ModelObject
{
public:
	User();

	// Declaration of functions declared as virtual in ModelObject 

	string getTableName();
    string getIdName();

    ModelObject::ObjectType getObjectType() = 0;

	// Class attribute get() & set() methods

	int getId();
	void setId(const int value);

    string getUsername();
    void setUsername(const string value);

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

        static const string TABLE_NAME;
        static const string ID_NAME;

private:
	int userId;
	string username;
	string firstName;
	string lastName;
	Address address;
	ContactInfo contact;
	Date dateOfBirth;
};

#endif // USER_H
