// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin, Mike Yuill
//
// User.h - Declaration of base class User
// Member functions are defined in User.cpp

#ifndef USER_H
#define USER_H

#include <string>
#include "Date.h"
#include "ContactInfo.h"
#include "Address.h"
#include <QVariantMap>
#include "../CuCareCommunications/qjson/src/qobjecthelper.h"
#include "modelobject.h"

using namespace std;


class User : public ModelObject
{
    Q_OBJECT

    Q_PROPERTY(QString username READ qGetUsername WRITE qSetUsername)
    Q_PROPERTY(QString firstName READ qGetFirstName WRITE qSetFirstName)
    Q_PROPERTY(QString lastName READ qGetLastName WRITE qSetLastName)
    Q_PROPERTY(QVariantMap dateOfBirth READ qGetDateOfBirth WRITE qSetDateOfBirth)
    Q_PROPERTY(QVariantMap contact READ qGetContact WRITE qSetContact)
    Q_PROPERTY(QVariantMap address READ qGetAddress WRITE qSetAddress)
    Q_PROPERTY(bool deleted READ isDeleted WRITE qPutDeleted)


public:

    // Constructor
    User (string usernameParam,
          string firstNameParam,
          string lastNameParam,
          Date dateOfBirthParam,
          ContactInfo contactParam,
          Address addressParam,
          bool deletedParam);

    User();

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


    //Special getters and setters for serialization purposes
    QString qGetUsername();
    void qSetUsername(const QString value);

    QString qGetFirstName();
    void qSetFirstName(const QString value);

    QString qGetLastName();
    void qSetLastName(const QString value);

    QVariantMap qGetDateOfBirth();
    void qSetDateOfBirth(const QVariantMap value);

    QVariantMap qGetContact();
    void qSetContact(const QVariantMap value);

    QVariantMap qGetAddress();
    void qSetAddress(const QVariantMap value);

    void qPutDeleted(const bool value);

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
