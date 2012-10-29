// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// SysAdmin.h - Declaration of base class SysAdmin
// Member functions are defined in SysAdmin.cpp

#include "SysAdmin.h"

// Constructor
SysAdmin::SysAdmin
(	string usernameParam,
    string firstNameParam,
    string lastNameParam,
    string titleParam,
    Date dateOfBirthParam,
    ContactInfo contactParam,
    Address addressParam,
    bool deletedParam)
    : User (usernameParam,
            firstNameParam,
            lastNameParam,
            titleParam,
            dateOfBirthParam,
            contactParam,
            addressParam,
            deletedParam)
{
}

// Destructor
SysAdmin::~SysAdmin()
{
}

// EOF
