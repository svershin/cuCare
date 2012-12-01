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

using namespace std;

class ContactInfo
{
public:

    // Constructor
    ContactInfo ();

    ContactInfo(string workPhoneParam,
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
