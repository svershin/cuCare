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
#include <QVariantMap>

using namespace std;


class User : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString username READ qGetUserName WRITE qSetUserName)
    Q_PROPERTY(QString firstName READ qGetFirstName WRITE qSetFirstName)
    Q_PROPERTY(QString lastName READ qGetLastName WRITE qSetLastName)
    Q_PROPERTY(QVariantMap dateOfBirth READ qGetDateOfBirth)
    Q_PROPERTY(QVariantMap contact READ qGetContact)
    Q_PROPERTY(QVariantMap address READ qGetAddress)
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
    QString qGetUserName();
    void qSetUserName(const QString value);

    QString qGetFirstName();
    void qSetFirstName(const QString value);

    QString qGetLastName();
    void qSetLastName(const QString value);

    QVariantMap qGetDateOfBirth();
    //void qSetDateOfBirth(const QVariantMap value);

    QVariantMap qGetContact();
    //void qSetContact(const QVariantMap value);

    QVariantMap qGetAddress();
    //void qSetAddress(const QVariantMap value);

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
