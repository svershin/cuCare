// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// SysAdmin.h - Declaration of base class SysAdmin
// Member functions are defined in SysAdmin.cpp

#ifndef SYSADMIN_H
#define SYSADMIN_H

#include "User.h"

class SysAdmin:User
{
public:

    // Constructor
    SysAdmin (string usernameParam,
              string firstNameParam,
              string lastNameParam,
              string titleParam,
              Date dateOfBirthParam,
              ContactInfo contactParam,
              Address addressParam,
              bool deletedParam);

    // Destructor
    ~SysAdmin();

protected:
private:

};


#endif

// EOF
