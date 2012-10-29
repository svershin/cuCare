// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// User.h - Declaration of base class User
// Member functions are defined in User.cpp

#include "User.h"

// Constructor
User::User
(	string usernameParam,
    string firstNameParam,
    string lastNameParam,
    string titleParam,
    Date dateOfBirthParam,
    ContactInfo contactParam,
    Address addressParam,
    bool deletedParam)
    : username (usernameParam),
      firstName (firstNameParam),
      lastName (lastNameParam),
      title (titleParam),
      dateOfBirth (dateOfBirthParam),
      contact (contactParam),
      address (addressParam),
      deleted (deletedParam)
{
}

// Destructor
User::~User()
{
}

string User::getUsername() { return username; }

string User::getFirstName() { return firstName; }
void User::setFirstName(const string value) { firstName = value; }

string User::getLastName() { return lastName; }
void User::setLastName(const string value) { lastName = value; }

string User::getTitle() { return title; }
void User::setTitle(const string value) { title = value; }

Date User::getDateOfBirth() { return dateOfBirth; }
void User::setDateOfBirth(const Date value) { dateOfBirth = value; }

ContactInfo User::getContact() { return contact; }
void User::setContact(const ContactInfo value) { contact = value; }

Address User::getAddress() { return address; }
void User::setAddress(const Address value) { address = value; }

void User::markDeleted() { deleted = true; }
// EOF
