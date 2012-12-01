// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// ContactInfo.h - Declaration of base class ContactInfo
// Member functions are defined in ContactInfo.cpp

#include "ContactInfo.h"

ContactInfo::ContactInfo()
    : workPhone (""),
      cellPhone (""),
      email (""),
      workEmail ("")
{
}

// Constructor
ContactInfo::ContactInfo
(       string workPhoneParam,
    string cellPhoneParam,
    string emailParam,
    string workEmailParam)
    : workPhone (workPhoneParam),
      cellPhone (cellPhoneParam),
      email (emailParam),
      workEmail (workEmailParam)
{
}

// Destructor
ContactInfo::~ContactInfo()
{
}

string ContactInfo::getWorkPhone() { return workPhone; }
void ContactInfo::setWorkPhone(const string value) { workPhone = value; }

string ContactInfo::getCellPhone() { return cellPhone; }
void ContactInfo::setCellPhone(const string value) { cellPhone = value; }

string ContactInfo::getEmail() { return email; }
void ContactInfo::setEmail(const string value) { email = value; }

string ContactInfo::getWorkEmail() { return workEmail; }
void ContactInfo::setWorkEmail(const string value) { workEmail = value; }

// EOF
