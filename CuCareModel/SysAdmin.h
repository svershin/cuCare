// COMP 3004 FALL 2012
// Assignment 4: cuCare Prototype #2
// Team: The Four Puppeteers
//
// SysAdmin.h - Declaration of base class SysAdmin
// Member functions are defined in SysAdmin.cpp

#ifndef SYSADMIN_H
#define SYSADMIN_H

#include "User.h"

class SysAdmin:public User
{
public:
    // Declaration of functions declared as virtual in ModelObject 

    ObjectType getObjectType();
};

#endif // SYSADMIN_H

// EOF
