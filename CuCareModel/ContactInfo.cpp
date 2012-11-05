// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin, Mike Yuill
//
// ContactInfo.h - Declaration of base class ContactInfo
// Member functions are defined in ContactInfo.cpp

#include "ContactInfo.h"

// Constructor
ContactInfo::ContactInfo
(	string workPhoneParam,
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


// Special getters and setters for serialization purposes
//
QString ContactInfo::qGetWorkPhone(){return QString::fromStdString(workPhone);}
void ContactInfo::qSetWorkPhone(const QString value){workPhone = value.toStdString();}

QString ContactInfo::qGetCellPhone(){return QString::fromStdString(cellPhone);}
void ContactInfo::qSetCellPhone(const QString value){cellPhone = value.toStdString();}

QString ContactInfo::qGetEmail(){return QString::fromStdString(email);}
void ContactInfo::qSetEmail(const QString value){email = value.toStdString();}

QString ContactInfo::qGetWorkEmail(){return QString::fromStdString(workEmail);}
void ContactInfo::qSetWorkEmail(const QString value){workEmail = value.toStdString();}

// EOF
