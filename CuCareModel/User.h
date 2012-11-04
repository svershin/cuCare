// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// User.h - Declaration of base class User
// Member functions are defined in User.cpp

#ifndef USER_H
#define USER_H

#include <string>
#include "Date.h"
#include "ContactInfo.h"
#include "Address.h"

using namespace std;

class User
{
public:

    // Constructor
    User (string usernameParam,
          string firstNameParam,
          string lastNameParam,
          Date dateOfBirthParam,
          ContactInfo contactParam,
          Address addressParam,
          bool deletedParam);

    // Destructor
    ~User();

    string getUsername();

    string getFirstName();
    void setFirstName(const string value);

    string getLastName();
    void setLastName(const string value);

    Date getDateOfBirth();
    void setDateOfBirth(const Date value);

    ContactInfo getContact();
    void setContact(const ContactInfo value);

    Address getAddress();
    void setAddress(const Address value);

    virtual int getType() = 0;
    void markDeleted();
    bool isDeleted();

protected:
private:
    string username;
    string firstName;
    string lastName;
    Date dateOfBirth;
    ContactInfo contact;
    Address address;
    bool deleted;
};

#endif

// EOF
