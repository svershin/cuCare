// COMP 3004 FALL 2012
// Assignment 2: cuCare Prototype
// Team: The Four Puppeteers
// Contributing Editors: Sergey Vershinin
//
// Physician.h - Declaration of base class Physician
// Member functions are defined in Physician.cpp

#ifndef PHYSICIAN_H
#define PHYSICIAN_H

#include "User.h"

class Physician:public User
{
public:

    // Constructor
    Physician (int idParam,
               string usernameParam,
               string firstNameParam,
               string lastNameParam,
               string titleParam,
               Date dateOfBirthParam,
               ContactInfo contactParam,
               Address addressParam,
               bool deletedParam);

    // Destructor
    ~Physician();

    int getId();

protected:
private:
    int id;
};


#endif

// EOF
