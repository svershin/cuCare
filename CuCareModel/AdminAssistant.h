// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// AdminAssistant.h - Declaration of base class AdminAssistant
// Member functions are defined in AdminAssistant.cpp

#ifndef ADMINASSISTANT_H
#define ADMINASSISTANT_H

#include "User.h"

class AdminAssistant:public User
{
public:

    // Constructor
    AdminAssistant (string usernameParam,
                    string firstNameParam,
                    string lastNameParam,
                    Date dateOfBirthParam,
                    ContactInfo contactParam,
                    Address addressParam,
                    bool deletedParam);

    // Destructor
    ~AdminAssistant();

    int getType() { return 3; }

protected:
private:
};


#endif

// EOF
