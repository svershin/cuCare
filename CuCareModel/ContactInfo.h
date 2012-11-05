// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
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

    string workPhone;
    string cellPhone;
    string email;
    string workEmail;

public:

    // Constructor
    ContactInfo (string workPhoneParam,
                 string cellPhoneParam,
                 string emailParam,
                 string workEmailParam);

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

protected:
private:
    string workPhone;
    string cellPhone;
    string email;
    string workEmail;
};


#endif

// EOF
