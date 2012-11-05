// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin, Mike Yuill
//
// User.h - Declaration of base class User
// Member functions are defined in User.cpp

#include "User.h"


// Constructor
User::User
(	string usernameParam,
    string firstNameParam,
    string lastNameParam,
    Date dateOfBirthParam,
    ContactInfo contactParam,
    Address addressParam,
    bool deletedParam)
    : username (usernameParam),
      firstName (firstNameParam),
      lastName (lastNameParam),
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

Date User::getDateOfBirth() { return dateOfBirth; }
void User::setDateOfBirth(const Date value) { dateOfBirth = value; }

ContactInfo User::getContact() { return contact; }
void User::setContact(const ContactInfo value) { contact = value; }

Address User::getAddress() { return address; }
void User::setAddress(const Address value) { address = value; }

void User::markDeleted() { deleted = true; }
bool User::isDeleted() { return deleted; }


//Special getters and setters for serialization purposes
//
QString User::qGetUsername(){return QString::fromStdString(username);}
void User::qSetUsername(const QString value){username = value.toStdString();}

QString User::qGetFirstName(){return QString::fromStdString(firstName);}
void User::qSetFirstName(const QString value){firstName = value.toStdString();}

QString User::qGetLastName(){return QString::fromStdString(lastName);}
void User::qSetLastName(const QString value){lastName = value.toStdString();}

QVariantMap User::qGetDateOfBirth(){return QJson::QObjectHelper::qobject2qvariant(&dateOfBirth);}
//void User::qSetDateOfBirth(const QVariantMap value);

QVariantMap User::qGetContact(){return QJson::QObjectHelper::qobject2qvariant(&contact);}
//void User::qSetContact(const QVariantMap value);

QVariantMap User::qGetAddress(){return QJson::QObjectHelper::qobject2qvariant(&contact);}
//void User::qSetAddress(const QVariantMap value);

void User::qPutDeleted(const bool value){deleted = value;}
// EOF
