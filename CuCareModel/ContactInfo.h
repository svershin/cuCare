// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin, Mike Yuill
//
// ContactInfo.h - Declaration of base class ContactInfo
// Member functions are defined in ContactInfo.cpp

#ifndef CONTACTINFO_H
#define CONTACTINFO_H

#include <string>
#include <QString>

using namespace std;

class ContactInfo : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString workPhone READ qGetWorkPhone WRITE qSetWorkPhone)
    Q_PROPERTY(QString cellPhone READ qGetCellPhone WRITE qSetCellPhone)
    Q_PROPERTY(QString email READ qGetEmail WRITE qSetEmail)
    Q_PROPERTY(QString workEmail READ qGetWorkEmail WRITE qSetEmail)

public:

    // Constructor
    ContactInfo (string workPhoneParam,
                 string cellPhoneParam,
                 string emailParam,
                 string workEmailParam);

    //Blank constructor
    ContactInfo();

    //Copy Constructor
    ContactInfo(const ContactInfo& origin);

    //Assignment operator
    ContactInfo& operator=(const ContactInfo& origin);

    // Destructor
    ~ContactInfo();

    string getWorkPhone();
    void setWorkPhone(const string value);

    string getCellPhone();
    void setCellPhone(const string value);

    string getEmail();
    void setEmail(const string value);

    string getWorkEmail();
    void setWorkEmail(const string value);


    //Special getters and setters for serialization purposes
    QString qGetWorkPhone();
    void qSetWorkPhone(const QString value);

    QString qGetCellPhone();
    void qSetCellPhone(const QString value);

    QString qGetEmail();
    void qSetEmail(const QString value);

    QString qGetWorkEmail();
    void qSetWorkEmail(const QString value);


protected:
private:
    string workPhone;
    string cellPhone;
    string email;
    string workEmail;
};


#endif

// EOF
