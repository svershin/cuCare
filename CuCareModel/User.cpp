// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
//
// User.cpp - Implementation of class User
// Function and attribute declarations are in User.h

#include "User.h"
#include "StringProperty.h"
#include "IntProperty.h"

// Constructor
User::User() {
	getProperties()->push_back(new IntProperty("userId", this, &ModelObject::getId, &ModelObject::setId));
	getProperties()->push_back(new StringProperty("username", this, &ModelObject::getUsername, &ModelObject::setUsername));
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
}

// Static attribute definition

const string User::TABLE_NAME = "USERS";

// Definition of functions declared as virtual in ModelObject 

string User::getTableName() { return TABLE_NAME; }

// Class attribute get() & set() methods

int User::getId() { return userId; }
void User::setId(const int value) { userId = value; }

string User::getUsername() { return username; }
void User::setUsername(const string value) { username = value; }

string User::getFirstName() { return firstName; }
void User::setFirstName(const string value) { firstName = value; }

string User::getLastName() { return lastName; }
void User::setLastName(const string value) { lastName = value; }

Address User::getAddress() { return address; }
void User::setAddress(const Address value) { address = value; }

    string  User::getCountry() { return address.getCountry(); }
	void  User::setCountry(const string value) { address.setCountry(value); }

    string  User::getCity() { return address.getCity(); }
	void  User::setCity(const string value) { address.setCity(value); }

    string  User::getLineOne() { return address.getLineOne(); }
	void  User::setLineOne(const string value) { address.setLineOne(value); }

    string  User::getLineTwo() { return address.getLineTwo(); }
	void  User::setLineTwo(const string value) { address.setLineTwo(value); }

    string  User::getPostalCode() { return address.getPostalCode(); }
	void  User::setPostalCode(const string value) { address.setPostalCode(value); }

ContactInfo User::getContact() { return contact; }
void User::setContact(const ContactInfo value) { contact = value; }

    string User::getWorkPhone() { return contact.getWorkPhone(); }
	void User::setWorkPhone(const string value) { contact.setWorkPhone(value); }

	string User::getCellPhone() { return contact.getCellPhone(); }
	void User::setCellPhone(const string value) { contact.setCellPhone(value); }

	string User::getEmail() { return contact.getEmail(); }
	void User::setEmail(const string value) { contact.setEmail(value); }

	string User::getWorkEmail() { return contact.getWorkEmail(); }
	void User::setWorkEmail(const string value) { contact.setWorkEmail(value); }

Date User::getDateOfBirth() { return dateOfBirth; }
void User::setDateOfBirth(const Date value) { dateOfBirth = value; }

	int  User::getDay() { return dateOfBirth.getDay(); }
	void  User::setDay(const int value) { dateOfBirth.setDay(value); }

	int  User::getMonth() { return dateOfBirth.getMonth(); }
	void  User::setMonth(const int value) { dateOfBirth.setMonth(value); }

	int  User::getYear() { return dateOfBirth.getYear(); }
	void  User::setYear(const int value) { dateOfBirth.setYear(value); }

// EOF
